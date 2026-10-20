"""'Left behind' leaderboard from Home Assistant history: the biggest residues after litter box visits.

Reads each base's residue and visit weight history, assigns every visit to the cat with the nearest current
reference weight (like the visit automation), keeps residues between residue_min_g and residue_max_g and prints
the top entries and each cat's best. With --write it seeds the leaderboard helpers that setup_ha.py created
(input_text.litter_box_left_behind_top and input_number.<cat>_best_left_behind; a best is only ever raised),
merging with what is already there. The automation keeps them up to date afterwards.

Usage:  uvx python left_behind.py [days] [--write]   (default 30 days)
"""
import datetime as dt
import sys
import urllib.parse

from hacommon import load_config, rest, find_bases

LEADERBOARD = "input_text.litter_box_left_behind_top"

args = [a for a in sys.argv[1:] if not a.startswith("--")]
write = "--write" in sys.argv
days = float(args[0]) if args else 30
cfg = load_config()
now = dt.datetime.now(dt.timezone.utc)
start = now - dt.timedelta(days=days)


def num(s):
    try:
        return float(s)
    except (TypeError, ValueError):
        return None


def hist(ents):
    q = (f"/api/history/period/{urllib.parse.quote(start.isoformat())}?end_time={urllib.parse.quote(now.isoformat())}"
         f"&filter_entity_id={','.join(ents)}&no_attributes")
    res = {}
    for series in rest(cfg, "GET", q) or []:
        if series:
            res[series[0]["entity_id"]] = [(dt.datetime.fromisoformat(p["last_changed"]), p["state"]) for p in series]
    return res


states = {s["entity_id"]: s["state"] for s in rest(cfg, "GET", "/api/states")}
bases = find_bases(cfg, states)
refs = {c["name"]: num(states.get(f"input_number.{c['slug']}_reference_weight")) or c["weight"] for c in cfg["cats"]}

entries = []  # (grams, cat, local time, base)
for b in bases:
    e = b["entities"]
    if "last_visit_residue" not in e:
        continue
    h = hist([e["last_visit_residue"], e["last_visit_weight"]])
    weights = [(t, num(s)) for t, s in h.get(e["last_visit_weight"], []) if num(s) is not None]
    prev = None
    for t, s in h.get(e["last_visit_residue"], []):
        p, prev = prev, s
        # Same rule as the automation: a new value, not a sensor coming back after an HA restart / Wi-Fi drop.
        if p in (None, "unavailable", "") or num(s) is None:
            continue
        g = round(num(s) * 1000)
        if not cfg["residue_min_g"] <= g <= cfg["residue_max_g"]:
            continue
        w = next((v for tw, v in reversed(weights) if tw <= t), None)
        if w is None:
            continue
        cat, ref = min(refs.items(), key=lambda kv: abs(w - kv[1]))
        if abs(w - ref) > cfg["match_kg"]:
            cat = "Unknown"
        entries.append((g, cat, t.astimezone(), b["name"]))

entries.sort(key=lambda x: -x[0])
print(f"Left behind, last {days:g} days: {len(entries)} plausible residues "
      f"({cfg['residue_min_g']}-{cfg['residue_max_g']} g)")
for i, (g, cat, t, base) in enumerate(entries[:cfg["leaderboard_size"]], 1):
    print(f"  {i:2}. {cat:10} {g:4} g  {t:%Y-%m-%d %H:%M}  {base}")
best = {c["name"]: max((g for g, cat, _, _ in entries if cat == c["name"]), default=0) for c in cfg["cats"]}
print("Personal bests: " + ", ".join(f"{n} {g} g" for n, g in best.items()))

if write:
    current = [x for x in (states.get(LEADERBOARD) or "").split(";") if x.count("|") == 2]
    merged = {x: int(x.split("|")[1]) for x in current}
    merged.update({f"{cat}|{g}|{t:%y%m%d%H%M}": g for g, cat, t, _ in entries})
    out = ""
    for item in sorted(merged, key=lambda x: -merged[x])[:cfg["leaderboard_size"]]:
        cand = f"{out};{item}" if out else item
        if len(cand) <= 255:
            out = cand
    rest(cfg, "POST", "/api/services/input_text/set_value", {"entity_id": LEADERBOARD, "value": out})
    print(f"  set    {LEADERBOARD}")
    for c in cfg["cats"]:
        ent = f"input_number.{c['slug']}_best_left_behind"
        if best[c["name"]] > (num(states.get(ent)) or 0):
            rest(cfg, "POST", "/api/services/input_number/set_value", {"entity_id": ent, "value": best[c["name"]]})
            print(f"  set    {ent} = {best[c['name']]} g")
