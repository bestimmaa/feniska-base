"""Set up cat identification and a 'Cats' dashboard in Home Assistant for one or more Feniska bases running ESPHome.

Creates (via the HA API, no YAML files needed):
  - per cat: input_number <cat>_reference_weight, input_number <cat>_last_weight,
    counter <cat>_visits_today, template sensor <cat>_weight (long-term statistics)
  - counter unknown_litter_visits_today, input_select litter_box_last_cat
  - automation "Litter box - identify cat and count visit" (nearest reference weight wins,
    references learn slowly from confident matches) and a midnight counter reset
  - a storage-mode dashboard with tiles, last visit, weight trend, visit history and base controls

Idempotent: existing helpers and sensors are kept (reference weights are not touched),
automations and the dashboard are overwritten.

Usage:  uvx --with websockets python setup_ha.py [config.toml]   (default: cats.local.toml)
"""
import asyncio
import json
import sys

import websockets

from hacommon import load_config, rest, find_bases


class WS:
    def __init__(self, ws):
        self.ws, self.n = ws, 0

    async def call(self, **msg):
        self.n += 1
        await self.ws.send(json.dumps({"id": self.n, **msg}))
        while True:
            r = json.loads(await self.ws.recv())
            if r.get("id") == self.n:
                if not r.get("success", True):
                    raise RuntimeError(f"{msg['type']}: {r.get('error')}")
                return r.get("result")


def states(cfg):
    return {s["entity_id"]: s for s in rest(cfg, "GET", "/api/states")}


async def ensure_helper(ws, kind, existing, entity_id, **params):
    if entity_id in existing:
        print(f"  keep   {entity_id}")
        return False
    await ws.call(type=f"{kind}/create", **params)
    print(f"  create {entity_id}")
    return True


def ensure_template_sensor(cfg, existing, entity_id, name, state):
    if entity_id in existing:
        print(f"  keep   {entity_id}")
        return
    flow = rest(cfg, "POST", "/api/config/config_entries/flow", {"handler": "template", "show_advanced_options": False})
    flow = rest(cfg, "POST", f"/api/config/config_entries/flow/{flow['flow_id']}", {"next_step_id": "sensor"})
    rest(cfg, "POST", f"/api/config/config_entries/flow/{flow['flow_id']}", {
        "name": name, "state": state, "unit_of_measurement": "kg",
        "device_class": "weight", "state_class": "measurement"})
    print(f"  create {entity_id}")


def visit_automation(cfg, bases):
    cats_jinja = "[" + ", ".join(
        f"['{c['name']}', 'input_number.{c['slug']}_reference_weight']" for c in cfg["cats"]) + "]"
    # One trigger per base; the visit weight (and box name) come from whichever base fired.
    weight_of = "{" + ", ".join(
        f"'{b['entities']['visits_since_boot']}': '{b['entities']['last_visit_weight']}'" for b in bases) + "}"
    box_of = "{" + ", ".join(
        f"'{b['entities']['visits_since_boot']}': '{b['name']}'" for b in bases) + "}"
    cat_tpl = (
        "{% set ns = namespace(best='Unknown', d=999) %}"
        "{% for n, e in " + cats_jinja + " %}"
        "{% set d = (w - states(e) | float(0)) | abs %}"
        "{% if d < ns.d %}{% set ns.d = d %}{% set ns.best = n %}{% endif %}"
        "{% endfor %}"
        "{{ ns.best if ns.d <= " + str(cfg["match_kg"]) + " else 'Unknown' }}")
    rate = cfg["learn_rate"]
    per_cat = []
    for c in cfg["cats"]:
        ref = f"input_number.{c['slug']}_reference_weight"
        per_cat.append({
            "conditions": [{"condition": "template", "value_template": "{{ cat == '" + c["name"] + "' }}"}],
            "sequence": [
                {"action": "input_number.set_value", "target": {"entity_id": f"input_number.{c['slug']}_last_weight"},
                 "data": {"value": "{{ w | round(2) }}"}},
                {"action": "counter.increment", "target": {"entity_id": f"counter.{c['slug']}_visits_today"}},
                {"if": [{"condition": "template",
                         "value_template": "{{ (w - states('" + ref + "') | float(0)) | abs < " + str(cfg["learn_kg"]) + " }}"}],
                 "then": [{"action": "input_number.set_value", "target": {"entity_id": ref},
                           "data": {"value": "{{ (" + str(1 - rate) + " * states('" + ref + "') | float(0) + "
                                             + str(rate) + " * w) | round(2) }}"}}]},
            ]})
    return {
        "alias": "Litter box - identify cat and count visit",
        "description": "Assigns each Feniska litter box visit to the cat with the nearest reference weight; "
                       "reference weights learn slowly from confident matches.",
        "mode": "queued",
        "triggers": [{"trigger": "state", "entity_id": [b["entities"]["visits_since_boot"] for b in bases]}],
        # Only a rising visit counter is a visit. A counter reappearing after an HA restart or a Wi-Fi drop
        # (unavailable -> 2) must not count. After a base reboot the counter has no value ('unknown') until
        # the first visit, so unknown -> 1 is a real visit.
        "conditions": [{"condition": "template",
                        "value_template": "{{ trigger.from_state is not none "
                                          "and trigger.from_state.state not in ['unavailable', ''] "
                                          "and trigger.to_state.state | int(0) > trigger.from_state.state | int(0) }}"}],
        "actions": [
            {"variables": {"w": "{{ states(" + weight_of + "[trigger.entity_id]) | float(0) }}",
                           "box": "{{ " + box_of + "[trigger.entity_id] }}"}},
            {"variables": {"cat": cat_tpl}},
            {"action": "input_select.select_option", "target": {"entity_id": "input_select.litter_box_last_cat"},
             "data": {"option": "{{ cat }}"}},
            *([{"action": "input_select.select_option", "target": {"entity_id": "input_select.litter_box_last_box"},
                "data": {"option": "{{ box }}"}}] if len(bases) > 1 else []),
            {"choose": per_cat,
             "default": [{"action": "counter.increment", "target": {"entity_id": "counter.unknown_litter_visits_today"}}]},
        ],
    }


def reset_automation(cfg):
    counters = [f"counter.{c['slug']}_visits_today" for c in cfg["cats"]] + ["counter.unknown_litter_visits_today"]
    return {
        "alias": "Litter box - reset daily visit counters", "description": "", "mode": "single",
        "triggers": [{"trigger": "time", "at": "00:00:00"}], "conditions": [],
        "actions": [{"action": "counter.reset", "target": {"entity_id": counters}}],
    }


def dashboard(cfg, bases):
    cats = cfg["cats"]
    multi = len(bases) > 1

    def row(base, suffix, name):
        return [{"entity": base["entities"][suffix], "name": name}] if suffix in base["entities"] else []

    def last_visit_rows(base):
        return [*row(base, "last_visit_time", "Time"), *row(base, "last_visit_weight", "Weight"),
                *row(base, "last_visit_duration", "Duration"), *row(base, "last_visit_residue", "Left behind")]

    def base_rows(base):
        return [*row(base, "tare", "Tare (litter box on, no cat)"), *row(base, "weight_live", "Live weight"),
                *row(base, "uptime", "Base uptime"), *row(base, "wifi_signal", "Wi-Fi"),
                *row(base, "display_backlight", "Display backlight")]

    tiles = ([{"type": "tile", "entity": f"sensor.{c['slug']}_weight", "name": c["name"], "icon": "mdi:cat"} for c in cats]
             + [{"type": "tile", "entity": f"counter.{c['slug']}_visits_today", "name": f"{c['name']} visits today",
                 "icon": "mdi:emoticon-poop"} for c in cats])
    last_visit = {"type": "entities", "title": "Last visit", "entities": [
        {"entity": "input_select.litter_box_last_cat", "name": "Cat"},
        *([{"entity": "input_select.litter_box_last_box", "name": "Litter box"}] if multi else last_visit_rows(bases[0])),
        {"entity": "counter.unknown_litter_visits_today", "name": "Unknown visits today"},
    ]}
    per_base_visits = [{"type": "entities", "title": f"{b['name']}: last visit", "entities": last_visit_rows(b)}
                       for b in bases] if multi else []
    live = [{"entity": b["entities"]["weight_live"], "name": b["name"] if multi else "Live weight"}
            for b in bases if "weight_live" in b["entities"]]
    refs = [{"entity": f"input_number.{c['slug']}_reference_weight", "name": f"{c['name']} reference"} for c in cats]
    controls = ([{"type": "entities", "title": "Calibration & base", "entities": refs + base_rows(bases[0])}] if not multi
                else [{"type": "entities", "title": "Calibration", "entities": refs}]
                + [{"type": "entities", "title": f"{b['name']}: base", "entities": base_rows(b)} for b in bases])
    return {"title": cfg["dashboard_title"], "views": [{
        "title": cfg["dashboard_title"], "path": "cats", "icon": "mdi:cat",
        "cards": [
            {"type": "grid", "columns": min(len(cats), 3) if len(cats) > 1 else 2, "square": False, "cards": tiles},
            last_visit,
            *per_base_visits,
            {"type": "statistics-graph", "title": "Weight trend", "chart_type": "line", "period": "day",
             "days_to_show": 30, "stat_types": ["mean"],
             "entities": [{"entity": f"sensor.{c['slug']}_weight", "name": c["name"]} for c in cats]},
            {"type": "history-graph", "title": "Visits (daily counters)", "hours_to_show": 168,
             "entities": [{"entity": f"counter.{c['slug']}_visits_today", "name": c["name"]} for c in cats]
                         + [{"entity": "counter.unknown_litter_visits_today", "name": "Unknown"}]},
            *([{"type": "history-graph", "title": "Litter box weight (24 h)", "hours_to_show": 24,
                "entities": live}] if live else []),
            {"type": "logbook", "title": "Visit log", "hours_to_show": 48,
             "target": {"entity_id": ["input_select.litter_box_last_cat"]
                                     + (["input_select.litter_box_last_box"] if multi else [])}},
            *controls,
        ]}]}


async def main():
    cfg = load_config(sys.argv[1] if len(sys.argv) > 1 else None)
    existing = states(cfg)
    bases = find_bases(cfg, existing)
    for b in bases:
        print(f"Base '{b['name']}':")
        for k, v in b["entities"].items():
            print(f"  {k:20} {v}")

    host = cfg["ha_url"].split("://", 1)[1]
    scheme = "wss" if cfg["ha_url"].startswith("https") else "ws"
    async with websockets.connect(f"{scheme}://{host}/api/websocket", max_size=None) as raw:
        await raw.recv()
        await raw.send(json.dumps({"type": "auth", "access_token": cfg["token"]}))
        if json.loads(await raw.recv()).get("type") != "auth_ok":
            raise SystemExit("HA authentication failed - check the token file")
        ws = WS(raw)

        print("Helpers:")
        new_refs = []
        for c in cfg["cats"]:
            if await ensure_helper(ws, "input_number", existing, f"input_number.{c['slug']}_reference_weight",
                                   name=f"{c['name']} reference weight", min=1, max=15, step=0.05,
                                   mode="box", unit_of_measurement="kg", icon="mdi:cat"):
                new_refs.append(c)
            await ensure_helper(ws, "input_number", existing, f"input_number.{c['slug']}_last_weight",
                                name=f"{c['name']} last weight", min=0, max=15, step=0.01,
                                mode="box", unit_of_measurement="kg", icon="mdi:cat")
            await ensure_helper(ws, "counter", existing, f"counter.{c['slug']}_visits_today",
                                name=f"{c['name']} visits today", icon="mdi:emoticon-poop", step=1, initial=0)
        await ensure_helper(ws, "counter", existing, "counter.unknown_litter_visits_today",
                            name="Unknown litter visits today", icon="mdi:help-circle", step=1, initial=0)
        selects = [("input_select.litter_box_last_cat", "Litter box last cat",
                    [c["name"] for c in cfg["cats"]] + ["Unknown"], "mdi:cat")]
        if len(bases) > 1:
            selects.append(("input_select.litter_box_last_box", "Litter box last box",
                            [b["name"] for b in bases], "mdi:package-variant"))
        for entity_id, name, options, icon in selects:
            if not await ensure_helper(ws, "input_select", existing, entity_id, name=name, options=options, icon=icon):
                for item in await ws.call(type="input_select/list"):
                    if item.get("name") == name and item.get("options") != options:
                        await ws.call(type="input_select/update", input_select_id=item["id"],
                                      name=name, options=options, icon=icon)
                        print(f"  update {entity_id} options")

        await asyncio.sleep(2)
        for c in new_refs:
            rest(cfg, "POST", "/api/services/input_number/set_value",
                 {"entity_id": f"input_number.{c['slug']}_reference_weight", "value": c["weight"]})
            print(f"  set    input_number.{c['slug']}_reference_weight = {c['weight']} kg")

        print("Template sensors (long-term weight statistics):")
        existing = states(cfg)
        for c in cfg["cats"]:
            ensure_template_sensor(cfg, existing, f"sensor.{c['slug']}_weight", f"{c['name']} weight",
                                   "{% set v = states('input_number." + c["slug"] + "_last_weight') | float(0) %}"
                                   "{{ v if v > 0 else none }}")

        print("Automations:")
        for aid, auto in (("feniska_cat_visit", visit_automation(cfg, bases)),
                          ("feniska_cat_visits_reset", reset_automation(cfg))):
            rest(cfg, "POST", f"/api/config/automation/config/{aid}", auto)
            print(f"  saved  {aid}")

        print("Dashboard:")
        url = cfg["dashboard_url"]
        if not any(d.get("url_path") == url for d in await ws.call(type="lovelace/dashboards/list")):
            await ws.call(type="lovelace/dashboards/create", url_path=url, title=cfg["dashboard_title"],
                          icon="mdi:cat", mode="storage", show_in_sidebar=True, require_admin=False)
            print(f"  create {url}")
        await ws.call(type="lovelace/config/save", url_path=url, config=dashboard(cfg, bases))
        print(f"  saved  {url}")

    final = states(cfg)
    print("Check:")
    check = [f"input_number.{c['slug']}_reference_weight" for c in cfg["cats"]] + \
            [f"sensor.{c['slug']}_weight" for c in cfg["cats"]] + \
            ["input_select.litter_box_last_cat", "automation.litter_box_identify_cat_and_count_visit",
             "automation.litter_box_reset_daily_visit_counters"] + \
            (["input_select.litter_box_last_box"] if len(bases) > 1 else [])
    for e in check:
        print(f"  {e:55} {final.get(e, {}).get('state', 'MISSING')}")


asyncio.run(main())
