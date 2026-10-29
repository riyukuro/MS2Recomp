#!/usr/bin/env python3
"""Units the compile stage left without an obj -> <OUT>/compilecheck.txt, one summary line on stdout. The full exe links
without such a unit and everything it defines becomes a trap stub, so a header change that breaks a dependent unit
silently turns its functions into traps (TextClipboard login trap, c365bd099: 15 sfr units dropped). Reads the
compile-failed.tsv tools/progress.py writes into each FULLEXE_OBJ_CACHES dir (default: build/progress-<MS2_AGENT>).
Engine objs: with FULLEXE_ENGINE_REFRESH unset (MS2_ENGINE_REFRESH=0) plan.py takes the FULLEXE_GB_OVERLAY cache as is, so
an engine TU that no longer compiles (or was never compiled there, e.g. MS2_ENGINE_CACHE_TAG) would link its old obj or
none. Then every engine obj of data/engine/units-gb.json is checked here against its last real build (tools/gbfresh.py
status: compile key, sources, headers, engine-patches) and a missing or stale one is a row like a compile failure
(kind engine-missing / engine-stale). With FULLEXE_ENGINE_REFRESH=1|check plan.py rebuilds or stops on those itself.
FULLEXE_STRICT_COMPILE=1: exit 1 on a unit that tools/fullexe/compile-allow.tsv ("<unit>\t<reason>") does not list
(bisecting against an old engine cache on purpose: MS2_STRICT_COMPILE= reports only)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, OUT, GB_OVERLAY  # noqa: E402

caches = [c for c in os.environ.get("FULLEXE_OBJ_CACHES", "").split(":") if c] or \
    [os.path.join(ROOT, "build", "progress-" + os.environ.get("MS2_AGENT", "fullexe"))]
ALLOW = os.path.join(os.path.dirname(os.path.abspath(__file__)), "compile-allow.tsv")
# this many failures is a broken toolchain (stale wineserver, wine upgrade), not a code change
TOOLCHAIN = 200

rows, missing = [], []
for c in caches:
    f = os.path.join(c, "compile-failed.tsv")
    if not os.path.exists(f):
        missing.append(c)
        continue
    for l in open(f):
        if l.strip() and not l.startswith("#"):
            kind, unit = l.rstrip("\n").split("\t", 1)
            rows.append((kind, unit))
# the engine objs plan.py will take unchecked (see above)
eng_note = ""
if GB_OVERLAY and not os.environ.get("FULLEXE_ENGINE_REFRESH"):
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import gbfresh  # noqa: E402
    gcache = os.path.dirname(GB_OVERLAY[0])
    n0, units = len(rows), gbfresh.units_of()
    failed = {u for _, u in rows}                    # the compile stage's own engine failures, listed once
    for u in units:
        st, why = gbfresh.status(gcache, u)
        if st in ("missing", "stale") and u["name"] not in failed:
            rows.append(("engine-" + st, u["name"] + (f" ({why})" if why else "")))
    eng_note = (f"; engine stage not refreshed (FULLEXE_ENGINE_REFRESH unset): {len(rows) - n0} of {len(units)} "
                f"engine obj(s) in {gcache} missing or stale")
allowed = {l.split("\t", 1)[0].strip() for l in open(ALLOW) if l.strip() and not l.startswith("#")} \
    if os.path.exists(ALLOW) else set()
new = [(k, u) for k, u in rows if u.split(" (", 1)[0] not in allowed]
os.makedirs(OUT, exist_ok=True)
with open(os.path.join(OUT, "compilecheck.txt"), "w") as fo:
    for c in missing:
        fo.write(f"no compile-failed.tsv in {c}\n")
    for k, u in rows:
        fo.write(f"{k}\t{u}\t{'allowed' if u.split(' (', 1)[0] in allowed else 'FAILED'}\n")
why = " (toolchain/wine broken? a stale wineserver fails every cl at once; not a code change)" if len(new) >= TOOLCHAIN else ""
if sum(1 for k, _ in new if k == "engine-stale") >= TOOLCHAIN:
    why = " (engine cache built with other flags or sources: rebuild it with MS2_ENGINE_REFRESH=1)"
print(f"compilecheck: {len(rows)} unit(s) without an obj, {len(rows) - len(new)} allowed, {len(new)} not in "
      f"{os.path.basename(ALLOW)}{why}" + (f"; no compile-failed.tsv in {', '.join(missing)}" if missing else "") + eng_note)
for k, u in new[:40]:
    print(f"compilecheck: COMPILE FAILED {k} {u} (its functions would be trap stubs in the full exe)")
if len(new) > 40:
    print(f"compilecheck: ... {len(new) - 40} more in {os.path.join(OUT, 'compilecheck.txt')}")
if (new or missing) and os.environ.get("FULLEXE_STRICT_COMPILE"):
    sys.exit(1)
