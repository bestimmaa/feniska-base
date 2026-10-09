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


def find_base_entities(cfg, entity_ids):
    """Map BASE_ENTITIES suffixes to the base's real entity ids.

    HA prefixes entity ids with device and sometimes area names (e.g. sensor.living_room_feniska_base_uptime),
    and other devices use the same suffixes (e.g. a router's ..._uptime). So: find the base by its
    visit counter, ask HA for all entities of that device, and match suffixes only within those."""
    hint = slug(cfg["base_device"]) if cfg.get("base_device") else ""
    anchors = sorted(e for e in entity_ids if e.startswith("sensor.") and e.endswith("_visits_since_boot") and hint in e)
    if not anchors:
        raise SystemExit("No Feniska base found in HA (no sensor.*_visits_since_boot) - is the base adopted?")
    if len(anchors) > 1:
        raise SystemExit(f"Several bases found: {anchors} - set base_device in the config")
    device_entities = json.loads(rest_text(cfg, "/api/template", {
        "template": "{{ device_entities(device_id('" + anchors[0] + "')) | tojson }}"}))
    found = {}
    for suffix, domain in BASE_ENTITIES.items():
        hits = [e for e in device_entities if e.startswith(domain + ".") and e.endswith("_" + suffix)]
        if hits:
            found[suffix] = sorted(hits)[0]
    if "last_visit_weight" not in found:
        raise SystemExit("Base found, but it has no last_visit_weight sensor - flash the current ESPHome config")
    return found


def rest_text(cfg, path, body):
    req = urllib.request.Request(
        cfg["ha_url"] + path, method="POST", data=json.dumps(body).encode(),
        headers={"Authorization": f"Bearer {cfg['token']}", "Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=20) as r:
        return r.read().decode()
