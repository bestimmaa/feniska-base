"""Set cats' reference weights in Home Assistant.

Usage:  uvx python set_weights.py "Cat A=3.2" "Cat B=4.5"   (names as in cats.local.toml)
"""
import sys

from hacommon import load_config, rest, slug

cfg = load_config()
for arg in sys.argv[1:]:
    name, kg = arg.rsplit("=", 1)
    entity = f"input_number.{slug(name)}_reference_weight"
    rest(cfg, "POST", "/api/services/input_number/set_value", {"entity_id": entity, "value": float(kg)})
    print(entity, "=", rest(cfg, "GET", f"/api/states/{entity}")["state"])
