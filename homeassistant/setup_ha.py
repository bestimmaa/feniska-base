"""Set up cat identification and a 'Cats' dashboard in Home Assistant for a Feniska base running ESPHome.

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

from hacommon import load_config, rest, find_base_entities


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


def visit_automation(cfg, base):
    cats_jinja = "[" + ", ".join(
        f"['{c['name']}', 'input_number.{c['slug']}_reference_weight']" for c in cfg["cats"]) + "]"
    cat_tpl = (
        "{% set w = states('" + base["last_visit_weight"] + "') | float(0) %}"
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
        "triggers": [{"trigger": "state", "entity_id": base["visits_since_boot"]}],
        "conditions": [{"condition": "template",
                        "value_template": "{{ trigger.to_state.state not in ['unknown', 'unavailable', ''] }}"}],
        "actions": [
            {"variables": {"w": "{{ states('" + base["last_visit_weight"] + "') | float(0) }}", "cat": cat_tpl}},
            {"action": "input_select.select_option", "target": {"entity_id": "input_select.litter_box_last_cat"},
             "data": {"option": "{{ cat }}"}},
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


def dashboard(cfg, base):
    cats = cfg["cats"]

    def row(suffix, name):
        return [{"entity": base[suffix], "name": name}] if suffix in base else []

    tiles = ([{"type": "tile", "entity": f"sensor.{c['slug']}_weight", "name": c["name"], "icon": "mdi:cat"} for c in cats]
             + [{"type": "tile", "entity": f"counter.{c['slug']}_visits_today", "name": f"{c['name']} visits today",
                 "icon": "mdi:emoticon-poop"} for c in cats])
    return {"title": cfg["dashboard_title"], "views": [{
        "title": cfg["dashboard_title"], "path": "cats", "icon": "mdi:cat",
        "cards": [
            {"type": "grid", "columns": min(len(cats), 3) if len(cats) > 1 else 2, "square": False, "cards": tiles},
            {"type": "entities", "title": "Last visit", "entities": [
                {"entity": "input_select.litter_box_last_cat", "name": "Cat"},
                *row("last_visit_time", "Time"), *row("last_visit_weight", "Weight"),
                *row("last_visit_duration", "Duration"), *row("last_visit_residue", "Left behind"),
                {"entity": "counter.unknown_litter_visits_today", "name": "Unknown visits today"},
            ]},
            {"type": "statistics-graph", "title": "Weight trend", "chart_type": "line", "period": "day",
             "days_to_show": 30, "stat_types": ["mean"],
             "entities": [{"entity": f"sensor.{c['slug']}_weight", "name": c["name"]} for c in cats]},
            {"type": "history-graph", "title": "Visits (daily counters)", "hours_to_show": 168,
             "entities": [{"entity": f"counter.{c['slug']}_visits_today", "name": c["name"]} for c in cats]
                         + [{"entity": "counter.unknown_litter_visits_today", "name": "Unknown"}]},
            *([{"type": "history-graph", "title": "Litter box weight (24 h)", "hours_to_show": 24,
                "entities": [{"entity": base["weight_live"], "name": "Live weight"}]}] if "weight_live" in base else []),
            {"type": "logbook", "title": "Visit log", "hours_to_show": 48,
             "target": {"entity_id": ["input_select.litter_box_last_cat"]}},
            {"type": "entities", "title": "Calibration & base", "entities": [
                *[{"entity": f"input_number.{c['slug']}_reference_weight", "name": f"{c['name']} reference"} for c in cats],
                *row("tare", "Tare (litter box on, no cat)"), *row("weight_live", "Live weight"),
                *row("uptime", "Base uptime"), *row("wifi_signal", "Wi-Fi"),
                *row("display_backlight", "Display backlight"),
            ]},
        ]}]}


async def main():
    cfg = load_config(sys.argv[1] if len(sys.argv) > 1 else None)
    existing = states(cfg)
    base = find_base_entities(cfg, existing)
    print("Base entities:")
    for k, v in base.items():
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
        options = [c["name"] for c in cfg["cats"]] + ["Unknown"]
        if not await ensure_helper(ws, "input_select", existing, "input_select.litter_box_last_cat",
                                   name="Litter box last cat", options=options, icon="mdi:cat"):
            for item in await ws.call(type="input_select/list"):
                if item.get("name") == "Litter box last cat" and item.get("options") != options:
                    await ws.call(type="input_select/update", input_select_id=item["id"],
                                  name=item["name"], options=options, icon="mdi:cat")
                    print("  update input_select.litter_box_last_cat options")

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
        for aid, auto in (("feniska_cat_visit", visit_automation(cfg, base)),
                          ("feniska_cat_visits_reset", reset_automation(cfg))):
            rest(cfg, "POST", f"/api/config/automation/config/{aid}", auto)
            print(f"  saved  {aid}")

        print("Dashboard:")
        url = cfg["dashboard_url"]
        if not any(d.get("url_path") == url for d in await ws.call(type="lovelace/dashboards/list")):
            await ws.call(type="lovelace/dashboards/create", url_path=url, title=cfg["dashboard_title"],
                          icon="mdi:cat", mode="storage", show_in_sidebar=True, require_admin=False)
            print(f"  create {url}")
        await ws.call(type="lovelace/config/save", url_path=url, config=dashboard(cfg, base))
        print(f"  saved  {url}")

    final = states(cfg)
    print("Check:")
    check = [f"input_number.{c['slug']}_reference_weight" for c in cfg["cats"]] + \
            [f"sensor.{c['slug']}_weight" for c in cfg["cats"]] + \
            ["input_select.litter_box_last_cat", "automation.litter_box_identify_cat_and_count_visit",
             "automation.litter_box_reset_daily_visit_counters"]
    for e in check:
        print(f"  {e:55} {final.get(e, {}).get('state', 'MISSING')}")


asyncio.run(main())
