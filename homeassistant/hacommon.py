"""Shared helpers for the Home Assistant scripts: config loading, REST calls, base entity discovery."""
import json
import pathlib
import re
import tomllib
import urllib.request

HERE = pathlib.Path(__file__).parent

# Entities the ESPHome config creates, keyed by entity-id suffix -> domain.
BASE_ENTITIES = {
    "visits_since_boot": "sensor",
    "last_visit_weight": "sensor",
    "last_visit_peak": "sensor",
    "last_visit_duration": "sensor",
    "last_visit_residue": "sensor",
    "last_visit_time": "sensor",
    "weight_live": "sensor",
    "uptime": "sensor",
    "wifi_signal": "sensor",
    "tare": "button",
    "display_backlight": "light",
}


def load_config(path=None):
    path = pathlib.Path(path) if path else HERE / "cats.local.toml"
    if not path.exists():
        raise SystemExit(f"{path} not found - copy cats.example.toml to cats.local.toml and adjust it")
    cfg = tomllib.loads(path.read_text())
    cfg.setdefault("match_kg", 1.5)
    cfg.setdefault("learn_kg", 0.5)
    cfg.setdefault("learn_rate", 0.2)
    cfg.setdefault("dashboard_url", "dashboard-cats")
    cfg.setdefault("dashboard_title", "Cats")
    cfg["ha_url"] = cfg["ha_url"].rstrip("/")
    cfg["token"] = pathlib.Path(cfg["token_file"]).expanduser().read_text().strip()
    for cat in cfg["cats"]:
        cat["slug"] = slug(cat["name"])
    return cfg


def slug(name):
    return re.sub(r"[^a-z0-9]+", "_", name.lower()).strip("_")


def rest(cfg, method, path, body=None):
    req = urllib.request.Request(
        cfg["ha_url"] + path, method=method,
        data=json.dumps(body).encode() if body is not None else None,
        headers={"Authorization": f"Bearer {cfg['token']}", "Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=20) as r:
        return json.loads(r.read() or b"null")


def find_bases(cfg, entity_ids):
    """Find all Feniska bases in HA. Returns [{"name": device name, "entities": {suffix: entity_id}}], sorted by name.

    HA prefixes entity ids with device and sometimes area names (e.g. sensor.living_room_feniska_base_uptime),
    and other devices use the same suffixes (e.g. a router's ..._uptime). So: find each base by its
    visit counter, ask HA for all entities of that device, and match suffixes only within those.

    Optional config: base_devices = ["Name", ...] limits the bases to these device names (exact, case-insensitive);
    the older base_device = "part of a name" still works and keeps the bases whose visit counter contains it."""
    anchors = sorted(e for e in entity_ids if e.startswith("sensor.") and e.endswith("_visits_since_boot"))
    if cfg.get("base_device"):
        anchors = [e for e in anchors if slug(cfg["base_device"]) in e]
    if not anchors:
        raise SystemExit("No Feniska base found in HA (no sensor.*_visits_since_boot) - is the base adopted?")
    tpl = "[" + ",".join(
        "{'anchor': '" + a + "', 'name': device_attr(device_id('" + a + "'), 'name_by_user') or "
        "device_attr(device_id('" + a + "'), 'name'), 'entities': device_entities(device_id('" + a + "'))}"
        for a in anchors) + "]"
    devices = json.loads(rest_text(cfg, "/api/template", {"template": "{{ " + tpl + " | tojson }}"}))
    if cfg.get("base_devices"):
        wanted = {n.lower() for n in cfg["base_devices"]}
        devices = [d for d in devices if (d["name"] or "").lower() in wanted]
        if not devices:
            raise SystemExit(f"None of base_devices {cfg['base_devices']} found in HA")
    bases = []
    for d in devices:
        found = {}
        for suffix, domain in BASE_ENTITIES.items():
            hits = [e for e in d["entities"] if e.startswith(domain + ".") and e.endswith("_" + suffix)]
            if hits:
                found[suffix] = sorted(hits)[0]
        if "last_visit_weight" not in found:
            raise SystemExit(f"Base '{d['name']}' has no last_visit_weight sensor - flash the current ESPHome config")
        bases.append({"name": d["name"] or d["anchor"], "entities": found})
    return sorted(bases, key=lambda b: b["name"])


def rest_text(cfg, path, body):
    req = urllib.request.Request(
        cfg["ha_url"] + path, method="POST", data=json.dumps(body).encode(),
        headers={"Authorization": f"Bearer {cfg['token']}", "Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=20) as r:
        return r.read().decode()
