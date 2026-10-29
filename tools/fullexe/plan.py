#!/usr/bin/env python3
"""Full-exe link plan: pick one obj per credited unit of a merge tree (game units by MS2-UNIT, engine/library TUs by
gb results), order by the lowest exe VA they own (matched/functional status rows, else their declared range), write
order.tsv (va, kind, unit, obj) + objs.rsp (link response file).
Closure: engine/library objs with no address (no pairs: CEF wrapper, pcre/Lua tables, D3DX11Effects, CryptoPP tables)
and gb objs no results row names join, after everything else, while they define an external the planned objs still
reference (repeated to a fixed point). Also writes gbpairs.tsv (obj symbol -> exe VA of the gb pairings, for
alias.py).
FULLEXE_FRESH=data|all (default unset: the tree's objs only, as before): game units under src/ms2/data/ (data) or every
game unit (all) take the master's source (ROOT/src/ms2, units the tree lacks included, units master deleted dropped) and
the newest obj among ROOT/build/progress*/obj that is current for it (progress.py's rule: the master source and every
.deps entry no newer than the obj; deps only under ROOT, outside work/), when it is newer than the tree's obj. A unit
only master has and no build is current for takes its newest stale obj, and so does a tree unit whose newest stale
master obj is newer than the tree's obj; a tree unit master renamed (same MS2-UNIT in
another file) that no build has compiled under the new name keeps the tree's obj. A tree
like work/merge-wt then links master's current data units without a merge. Caveat: the agents' caches build the main
tree's working copy, so an uncommitted edit there can reach the link."""
import collections, glob, json, os, pickle, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT as R, OUT as F, TREE as T, GB_OVERLAY, coff_externals, tagged, status_tsv  # noqa: E402
import ms2paths  # noqa: E402  (on the path through common)
OUT = F
C = os.path.join(T, "build", "progress")

rows = collections.defaultdict(list)       # unit -> [(va, state)]
for l in open(status_tsv()):
    if l[0] == "#":
        continue
    p = l.rstrip("\n").split("\t")
    rows[p[2]].append((int(p[0], 16), p[3]))

def low(u, fallback=None):
    v = [va for va, st in rows.get(u, ()) if st != "stub"]
    if v:
        return min(v)
    v = [va for va, st in rows.get(u, ())]
    return min(v) if v else fallback

plan, skipped = [], collections.Counter()
rebuild = []                                # units linked from a stale obj or left out for a missing one (rebuild<TAG>.txt)
NM_ZONE = (0x14156a020, 0x14160a7f0)              # the Nexon Messenger SDK units (unit_14160a7f0 is game code, kept)
GAME = os.path.join(T, "src", "ms2")
MASTER = os.path.join(R, "src", "ms2")
FRESH = os.environ.get("FULLEXE_FRESH", "")
if FRESH not in ("", "data", "all"):
    sys.exit(f"FULLEXE_FRESH={FRESH}: expected data or all")
# FULLEXE_OBJ_CACHES (':'-separated progress cache dirs) pins the obj search to those caches: a reproducible build (cmake/fullexe)
MASTER_OBJ = ([os.path.join(os.path.abspath(d), "obj") for d in os.environ["FULLEXE_OBJ_CACHES"].split(":") if d]
              if os.environ.get("FULLEXE_OBJ_CACHES") else sorted(glob.glob(os.path.join(R, "build", "progress*", "obj")))) if FRESH else []


def tracked(root):
    """the src/ms2 sources git tracks in the checkout at root (relative to src/ms2), or None outside git: another agent's
    untracked WIP file (a split in progress, say) would add a second definition of its symbols; the files of a submodule
    (the mirror's src/ms2/scaleform) count as tracked"""
    r = subprocess.run(["git", "-C", root, "ls-files", "-z", "--recurse-submodules", "--", "src/ms2"], capture_output=True, text=True)
    return {os.path.relpath(f, "src/ms2").replace("/", os.sep) for f in r.stdout.split("\0") if f} if r.returncode == 0 else None


GAME_GIT, MASTER_GIT = tracked(T), tracked(R) if FRESH else None


def fresh_scope(rel):
    return FRESH == "all" or (FRESH == "data" and rel.startswith("data" + os.sep))


# a dep must be under the checkout, or under the engine / third_party dirs it points elsewhere (a BYO SDK, ms2paths)
DEP_ROOTS = tuple([R + os.sep] + [d + os.sep for d in (os.path.abspath(ms2paths.ENGINE_DIR), os.path.abspath(ms2paths.THIRD_PARTY))
                                  if not (d + os.sep).startswith(R + os.sep)])


def fresh_obj(rel, stale_ok=False):
    """the newest master build obj of game source rel that progress.py would not rebuild (stale_ok: any), or None"""
    src, best = os.path.join(MASTER, rel), None
    for od in MASTER_OBJ:
        o = os.path.join(od, rel[:-4] + ".obj")
        try:
            t = os.path.getmtime(o)
            deps = json.load(open(o[:-4] + ".deps")).get("deps", [])
        except (OSError, ValueError):
            continue
        if any(not f.startswith(DEP_ROOTS) or f.startswith(os.path.join(R, "work") + os.sep) for f in deps):
            continue           # built from another worktree's sources
        if not stale_ok and any(not os.path.exists(f) or os.path.getmtime(f) > t for f in [src] + deps):
            continue           # stale for the master source
        if best is None or t > best[0]:
            best = (t, o)
    return best[1] if best else None


sources = []                                # (path of the unit's source, rel, obj or None)
for d, _, fs in os.walk(GAME):
    for f in fs:
        if f.endswith(".cpp"):
            p = os.path.join(d, f)
            rel = os.path.relpath(p, GAME)
            if GAME_GIT is not None and rel not in GAME_GIT:
                skipped["untracked source"] += 1; continue
            sources.append((p, rel, os.path.join(C, "obj", rel[:-4] + ".obj")))
if FRESH:
    have = {rel for _, rel, _ in sources}
    for d, _, fs in os.walk(MASTER):
        for f in fs:
            rel = os.path.relpath(os.path.join(d, f), MASTER)
            if f.endswith(".cpp") and rel not in have and fresh_scope(rel):
                if MASTER_GIT is not None and rel not in MASTER_GIT:
                    skipped["fresh: untracked master source"] += 1; continue
                sources.append((None, rel, None))
    def unit_name(path):
        for line in open(path, encoding="latin1"):
            m = re.match(r"\s*//\s*MS2-UNIT:\s*(\S+)", line)
            if m:
                return m.group(1)
    out, gone, unbuilt = [], [], set()
    for p, rel, obj in sources:
        if not fresh_scope(rel):
            out.append((p, rel, obj)); continue
        if not os.path.exists(os.path.join(MASTER, rel)) or (MASTER_GIT is not None and rel not in MASTER_GIT):
            gone.append((p, rel, obj)); continue
        mo = fresh_obj(rel)
        if mo and (obj is None or not os.path.exists(obj) or os.path.getmtime(mo) > os.path.getmtime(obj)):
            skipped["fresh: master obj"] += 1
            out.append((os.path.join(MASTER, rel), rel, mo))
        elif p is None and fresh_obj(rel, True):
            # a unit only master has whose source changed since its last build (an uncommitted edit): its older obj
            skipped["fresh: master-only unit, stale master obj"] += 1
            rebuild.append(rel)
            out.append((os.path.join(MASTER, rel), rel, fresh_obj(rel, True)))
        elif (so := fresh_obj(rel, True)) and obj and os.path.exists(obj) and \
                os.path.getmtime(so) > os.path.getmtime(obj):
            # no build is current (e.g. a header another agent is editing), but one is newer than the tree's obj
            skipped["fresh: stale master obj, newer than the tree's"] += 1
            rebuild.append(rel)
            out.append((os.path.join(MASTER, rel), rel, so))
        elif p is None:
            skipped["fresh: no current master obj"] += 1
            unbuilt.add(unit_name(os.path.join(MASTER, rel)))
        else:
            out.append((p, rel, obj))
    # a unit master renamed (same MS2-UNIT, another file) that no build has compiled under its new name yet keeps the
    # tree's obj; one master deleted outright is dropped
    for p, rel, obj in gone:
        if unit_name(p) in unbuilt - {None}:
            skipped["fresh: renamed in master, not built yet: tree obj"] += 1
            out.append((p, rel, obj))
        else:
            skipped["fresh: deleted in master"] += 1
    sources = out
for p, rel, obj in sources:
    name, rng, place = None, [], None
    for line in open(p, encoding="latin1"):
        if "MS2-" not in line:
            continue
        m = re.match(r"\s*//\s*MS2-UNIT:\s*(\S+)", line)
        if m:
            name = m.group(1)
        m = re.match(r"\s*//\s*MS2-RANGE:\s*0x([0-9a-fA-F]+)", line)
        if m:
            rng.append(int(m.group(1), 16))
        m = re.match(r"\s*//\s*MS2-NO-EXE:\s*0x([0-9a-fA-F]+)", line)
        if m:
            place = int(m.group(1), 16)
    if not name:
        continue
    if not os.path.exists(obj):
        skipped["game obj missing"] += 1
        rebuild.append(rel)
        continue
    va = place if place is not None else low(name, min(rng) if rng else None)
    # Nexon Messenger is not part of the rebuild (user 2026-10-24): the zone's units stay out of the link and
    # unnamed/nm_stubs.cpp (MS2-NO-EXE, placed at the zone start) stands in for the symbols the game references
    if place is None and va is not None and NM_ZONE[0] <= va < NM_ZONE[1]:
        skipped["NM zone: not in the rebuild (nm_stubs)"] += 1
        continue
    if va is None:
        skipped["game no address"] += 1
        continue
    kind = "scaleform" if rel.startswith("scaleform/") else "game"
    plan.append((va, kind, name, obj))

GB_DIRS = GB_OVERLAY + [os.path.join(C, "gb")]          # first wins
res = {}
for d in reversed(GB_DIRS):
    rj = os.path.join(d, "results.json")
    if os.path.exists(rj):
        res.update(json.load(open(rj)))
with open(os.path.join(OUT, "gbpairs.tsv"), "w") as f:
    for k, c in res.items():
        for pr in c.get("pairs", []) + (c.get("xpairs") or []):
            if pr[1]:
                f.write(f"{pr[0]}\t{pr[1]:x}\n")


# FULLEXE_ENGINE_REFRESH=1|check (default unset: the objs as they are, as before): every engine/lib obj some results row
# names is checked by content (tools/gbfresh.py: sources, headers, engine-patches/*.ed, manifest.tsv, units-gb.json
# entry) in the first FULLEXE_GB_OVERLAY cache. 1 recompiles a stale or absent one there (so no obj comes from the
# tree's cache, a work/ path), check stops with the list. FULLEXE_ENGINE_STRICT=1 also rebuilds objs without a stamp.
ENGINE_REFRESH = os.environ.get("FULLEXE_ENGINE_REFRESH", "")
if ENGINE_REFRESH:
    if ENGINE_REFRESH not in ("1", "check"):
        sys.exit(f"FULLEXE_ENGINE_REFRESH={ENGINE_REFRESH}: expected 1 or check")
    if not GB_OVERLAY:
        sys.exit("FULLEXE_ENGINE_REFRESH needs FULLEXE_GB_OVERLAY=<cache>/gb (a gate output dir under build/): the engine objs "
                 "are rebuilt there, not taken from the merge tree's cache")
    sys.path.insert(0, os.path.join(R, "tools"))
    import gbfresh  # noqa: E402
    wanted = {tuple(k.split(":", 1)) for k in res}
    left = gbfresh.refresh(os.path.dirname(GB_OVERLAY[0]), gbfresh.units_of(), ENGINE_REFRESH == "1",
                           bool(os.environ.get("FULLEXE_ENGINE_STRICT")), False, int(os.environ.get("FULLEXE_JOBS", "8")),
                           log=lambda m: print(m, file=sys.stderr), only=wanted, missing=True)
    if left:
        sys.exit(f"{len(left)} engine obj(s) stale or failed to build (FULLEXE_ENGINE_REFRESH={ENGINE_REFRESH}): "
                 + ", ".join(u["name"] for u in left[:5]))


def gbobj(recipe, name):
    """a gb unit's obj: the overlay's build when it has one (the tree may hold a newer build of older source), else
    the newest among the other dirs"""
    os_ = [os.path.join(d, "obj", recipe, re.sub(r"[^A-Za-z0-9_.-]+", "__", name) + ".obj") for d in GB_DIRS]
    os_ = [o for o in os_ if os.path.exists(o)]
    if os_ and any(os_[0].startswith(d + os.sep) for d in GB_OVERLAY):
        return os_[0]
    return max(os_, key=os.path.getmtime) if os_ else None


byunit = collections.defaultdict(list)
for k, c in res.items():
    byunit[c["unit"].lower()].append((sum(1 for pr in c.get("pairs", ()) if pr[2]) + len(c.get("pairs", ())), k, c))
units_lc = {u.lower(): u for u in rows if u.startswith("gb:")}
known, noaddr = set(), []
for ul, cands in byunit.items():
    cands.sort(key=lambda t: (-t[0], t[1]))
    _, k, c = cands[0]
    skipped["engine twin dropped"] += len(cands) - 1
    for _, kk, _ in cands:
        rc, nm = kk.split(":", 1)
        known.add((rc, re.sub(r"[^A-Za-z0-9_.-]+", "__", nm) + ".obj"))
    recipe, name = k.split(":", 1)
    obj = gbobj(recipe, name)
    if not obj:
        skipped["engine obj missing"] += 1
        continue
    u = units_lc.get(ul, c["unit"])
    va = low(u)
    if va is None:
        prs = [pr[1] for pr in c.get("pairs", ()) + c.get("xpairs", [])]
        va = min(prs) if prs else None
    kind = "lib" if recipe.startswith("lib-") else "engine"
    if va is None:
        noaddr.append((kind, u, obj))
        continue
    plan.append((va, kind, u, obj))
# gb objs no results row names (a recipe unit not gated yet): closure candidates too
for d in GB_DIRS:
    od = os.path.join(d, "obj")
    for recipe in sorted(os.listdir(od)) if os.path.isdir(od) else ():
        for fn in sorted(os.listdir(os.path.join(od, recipe))):
            o = os.path.join(od, recipe, fn)
            if fn.endswith(".obj") and (recipe, fn) not in known:
                known.add((recipe, fn))
                noaddr.append(("lib" if recipe.startswith("lib-") else "engine", f"gb:{recipe}/{fn[:-4]}", o))

plan.sort()

# --- closure over the no-address objs
cache_p = os.path.join(OUT, "coffsyms.pkl")
cache = pickle.load(open(cache_p, "rb")) if os.path.exists(cache_p) else {}
def ext(o):
    st = os.stat(o)
    key = (st.st_mtime_ns, st.st_size)
    if cache.get(o, (None,))[0] != key:
        cache[o] = (key, coff_externals(o))
    return cache[o][1]
defined, needed = set(), set()
for _, _, _, o in plan:
    d, u = ext(o)
    defined |= d; needed |= u
cands = [(kind, u, o, *ext(o)) for kind, u, o in noaddr]
NOVA = 0xFFFFFFFFFF
added = True
while added:
    added = False
    want = needed - defined
    for c in cands:
        if c[2] is not None and c[3] & want:
            plan.append((NOVA, c[0] + "-closure", c[1], c[2]))
            defined |= c[3]; needed |= c[4]
            c_obj = c[2]
            cands = [x for x in cands if x[2] != c_obj]
            added = True
            break
skipped["engine no address"] = len(cands)
pickle.dump(cache, open(cache_p, "wb"))

with open(os.path.join(OUT, "order.tsv"), "w") as f:
    f.write("#va\tkind\tunit\tobj\n")
    for va, kind, u, obj in plan:
        f.write(f"{va:x}\t{kind}\t{u}\t{obj}\n")
# progress.py filters for the units whose obj is stale or missing: build them and plan again for a current link
open(tagged("rebuild.txt"), "w").write("".join(r.replace(os.sep, "/") + "\n" for r in sorted(set(rebuild))))
print(len(plan), collections.Counter(k for _, k, _, _ in plan), dict(skipped))
