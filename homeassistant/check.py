"""Health and plausibility check for the Feniska bases and the cat identification in Home Assistant.

Reports per base (firmware, uptime/reboots, availability, current empty weight, visits of the last N hours with
weight, duration and the cat they best match) and per cat (reference, visits, weight spread), then lists
anything that looks wrong under ISSUES. Read-only: it changes nothing in HA.

Usage:  uvx python check.py [hours]   (default 24)
"""
import datetime as dt
import statistics
import sys
import urllib.parse

from hacommon import load_config, rest, rest_text, find_bases

cfg = load_config()
hours = float(sys.argv[1]) if len(sys.argv) > 1 else 24
now = dt.datetime.now(dt.timezone.utc)
start = now - dt.timedelta(hours=hours)
out = sys.stdout.write
issues = []


def P(t):
    return dt.datetime.fromisoformat(t.replace("Z", "+00:00"))


def num(s):
    try:
        return float(s)
    except (TypeError, ValueError):
        return None


def hist(ents, t0=start, t1=now):
    q = (f"/api/history/period/{urllib.parse.quote(t0.isoformat())}?end_time={urllib.parse.quote(t1.isoformat())}"
         f"&filter_entity_id={','.join(ents)}&no_attributes")
    res = {}
    for series in rest(cfg, "GET", q) or []:
        if series:
            res[series[0]["entity_id"]] = [(P(p["last_changed"]), p["state"]) for p in series]
    return res


def at(series, t, slack=5):
    v = None
    for ts, s in series or []:
        if ts <= t + dt.timedelta(seconds=slack):
            v = s
    return v


states = {s["entity_id"]: s for s in rest(cfg, "GET", "/api/states")}
st = lambda e: states.get(e, {}).get("state")
bases = find_bases(cfg, states)
cats = cfg["cats"]
refs = {c["name"]: num(st(f"input_number.{c['slug']}_reference_weight")) for c in cats}
min_visit = cfg.get("visit_min_kg", 1.0)

out(f"Feniska check {now.astimezone():%Y-%m-%d %H:%M} - last {hours:g} h - {len(bases)} base(s)\n")
for a in ("automation.litter_box_identify_cat_and_count_visit", "automation.litter_box_reset_daily_visit_counters"):
    if st(a) != "on":
        issues.append(f"{a} is {st(a)}")

per_cat = {c["name"]: [] for c in cats}
unknown = []
for b in bases:
    e = b["entities"]
    anchor = e["visits_since_boot"]
    fw = rest_text(cfg, "/api/template", {"template": "{{ device_attr(device_id('" + anchor + "'), 'sw_version') }}"})
    up = num(st(e.get("uptime")))
    live = num(st(e.get("weight_live")))
    out(f"\n== {b['name']}  firmware {fw}  uptime {up and round(up / 3600, 1)} h  live now {live} kg\n")
    for k, ent in e.items():
        if st(ent) in ("unavailable", None):
            issues.append(f"{b['name']}: {ent} is {st(ent)}")
    if up is not None and up < hours * 3600:
        issues.append(f"{b['name']}: rebooted {up / 3600:.1f} h ago (each boot re-tares; check nothing was on it)")
    if live is not None and abs(live) > 0.15:
        issues.append(f"{b['name']}: empty reading is {live:+.2f} kg now (zero drift, litter added/removed, "
                      f"or a cat is in the box right now)")

    keys = ["visits_since_boot", "last_visit_weight", "last_visit_peak", "last_visit_duration", "last_visit_residue"]
    h = hist([e[k] for k in keys if k in e] + ([e["weight_live"]] if "weight_live" in e else []))
    lw = [(t, num(v)) for t, v in h.get(e.get("weight_live"), []) if num(v) is not None]
    calm = [v for t, v in lw if abs(v) < min_visit]
    if calm:
        lo, hi = min(calm), max(calm)
        out(f"   live weight outside visits: {lo:+.3f} .. {hi:+.3f} kg\n")
    prev = None
    for ts, s in h.get(anchor, []):
        n, p = num(s), prev
        prev = s
        if p in (None, "unavailable", "") or n is None or n <= (num(p) or 0):
            continue
        w = num(at(h.get(e["last_visit_weight"]), ts))
        pk = num(at(h.get(e.get("last_visit_peak")), ts))
        du = num(at(h.get(e.get("last_visit_duration")), ts))
        rs = num(at(h.get(e.get("last_visit_residue")), ts + dt.timedelta(seconds=60), slack=0))
        name, ref = min(refs.items(), key=lambda kv: abs((w or 0) - (kv[1] or 0)))
        off = abs((w or 0) - (ref or 0))
        cat = name if off <= cfg["match_kg"] else "Unknown"
        out(f"   {ts.astimezone():%m-%d %H:%M}  {w if w is None else round(w, 2):>5} kg  peak {pk if pk is None else round(pk, 2)}"
            f"  {du if du is None else int(du)} s  residue {rs if rs is None else round(rs, 2)}  -> {cat}"
            f" (nearest {name} {ref}, off {off:.2f})\n")
        (per_cat[cat] if cat != "Unknown" else unknown).append((ts, b["name"], w))
        if du is not None and du > 600:
            issues.append(f"{b['name']}: {du / 60:.0f} min visit at {ts.astimezone():%H:%M} (something left on the box?)")
        if pk is not None and w is not None and pk - w > 2.0:
            issues.append(f"{b['name']}: peak {pk:.2f} vs median {w:.2f} kg at {ts.astimezone():%H:%M} (two cats, or a jump)")
        if rs is not None and (rs < -0.3 or rs > 0.6):
            issues.append(f"{b['name']}: residue {rs:+.2f} kg after the {ts.astimezone():%H:%M} visit (litter kicked out, or cleaning)")

out("\n== Cats\n")
for c in cats:
    v = per_cat[c["name"]]
    ws = [w for _, _, w in v if w is not None]
    spread = f", median {statistics.median(ws):.2f}, range {min(ws):.2f}-{max(ws):.2f} kg" if ws else ""
    out(f"   {c['name']:10} reference {refs[c['name']]} kg (configured start {c['weight']})  "
        f"visits {len(v)} ({', '.join(sorted({bn for _, bn, _ in v})) or '-'}){spread}  "
        f"today's counter {st('counter.' + c['slug'] + '_visits_today')}\n")
    if not v:
        issues.append(f"{c['name']}: no identified visit in the last {hours:g} h")
    if refs[c["name"]] is not None and abs(refs[c["name"]] - c["weight"]) > 0.5:
        issues.append(f"{c['name']}: reference drifted to {refs[c['name']]} kg (configured {c['weight']})")
    if len(ws) >= 3 and max(ws) - min(ws) > 1.0:
        issues.append(f"{c['name']}: visit weights vary {min(ws):.2f}-{max(ws):.2f} kg (misassigned visits?)")
out(f"   Unknown    visits {len(unknown)}" + (": " + ", ".join(f"{t.astimezone():%H:%M} {bn} {w and round(w, 2)} kg"
                                                              for t, bn, w in unknown) if unknown else "") + "\n")
if len(unknown) >= 3:
    issues.append(f"{len(unknown)} unknown visits in {hours:g} h")

out("\nISSUES:\n" + ("".join(f"  - {i}\n" for i in issues) if issues else "  none\n"))
