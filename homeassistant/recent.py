"""Show recent litter box activity from Home Assistant (live-weight spikes and the last visit, per base).

Usage:  uvx python recent.py [minutes]   (default 30)
"""
import datetime as dt
import sys
import urllib.parse

from hacommon import load_config, rest, find_bases

cfg = load_config()
minutes = int(sys.argv[1]) if len(sys.argv) > 1 else 30
states = {s["entity_id"]: s["state"] for s in rest(cfg, "GET", "/api/states")}
bases = find_bases(cfg, states)

for b in bases:
    base = b["entities"]
    print(f"== {b['name']}")
    if "weight_live" in base:
        start = (dt.datetime.now(dt.timezone.utc) - dt.timedelta(minutes=minutes)).isoformat()
        hist = rest(cfg, "GET", f"/api/history/period/{urllib.parse.quote(start)}"
                                f"?filter_entity_id={base['weight_live']}&minimal_response&no_attributes")
        vals = [(p.get("last_changed") or p.get("lu"), float(p["state"])) for p in (hist[0] if hist else [])
                if p["state"] not in ("unknown", "unavailable")]
        print(f"Live weight, last {minutes} min: {len(vals)} points")
        if vals:
            t, peak = max(vals, key=lambda x: x[1])
            print(f"  peak {peak:.3f} kg at {t}")
            for t, v in vals:
                if v > 0.3:
                    print(f"    {t}  {v:.3f} kg")
    print("Last visit:")
    for key in ("last_visit_time", "last_visit_weight", "last_visit_duration", "last_visit_residue", "visits_since_boot"):
        if key in base:
            print(f"  {key:20} {states[base[key]]}")

print("== Cats")
print(f"  {'last cat':20} {states.get('input_select.litter_box_last_cat', 'n/a')}")
if len(bases) > 1:
    print(f"  {'last box':20} {states.get('input_select.litter_box_last_box', 'n/a')}")
for c in cfg["cats"]:
    print(f"  {c['name']:20} weight {states.get('sensor.' + c['slug'] + '_weight', 'n/a')}, "
          f"reference {states.get('input_number.' + c['slug'] + '_reference_weight', 'n/a')}, "
          f"visits today {states.get('counter.' + c['slug'] + '_visits_today', 'n/a')}")
