#!/usr/bin/env python3
"""Content-hash freshness of the Gamebryo engine objs (tools/fullexe links them), rebuilt from committed inputs.

    python3 tools/gbfresh.py CACHE [--rebuild] [--adopt] [-j N] [FILTER...]

CACHE is a progress cache dir (build/progress-<agent>); its gb/obj/<recipe>/<unit>.obj are checked. An obj is stale when
the sha256 over everything it was compiled from differs from its <obj>.stamp sidecar:
  - the compile key (flags, toolset) and the units-gb.json entry (data/engine/units-*.json) of the unit;
  - the content of the source and of every header in its .deps (gbprogress writes them), each with the
    engine-patches/<path>.ed and engine-patches/manifest.tsv row of an engine/gamebryo file (the patch inputs of a
    BYO-SDK build, tools/apply_engine_patches.py).
mtimes are not used: a copied snapshot obj gets a fresh mtime and hides an obj built from older sources (sfr39:
PropService and EntityActorData lacked the scene-name decorator). An obj without a stamp is judged by gbprogress's
mtime rule plus, per dep with an engine-patches/manifest.tsv row, "its content is that row's result" (a manifest commit
only invalidates the objs whose own patched files changed); --adopt stamps those that pass, --strict (or
--rebuild --strict) treats every unstamped obj as stale.
Without --rebuild the stale ones are listed (exit 1); with it they are recompiled (gbprogress.compile_unit) and stamped."""
import argparse
import hashlib
import json
import os
import pickle
import sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gbprogress  # noqa: E402
import gbtree  # noqa: E402

ROOT = gbtree.ROOT
PATCHES = os.path.join(ROOT, "engine-patches")
MANIFEST = os.path.join(PATCHES, "manifest.tsv")
ENGINE = gbtree.ENGINE
_hash_cache = {}


def _sha(path):
    """sha256 of a file, memoised on (path, mtime, size) in this process"""
    st = os.stat(path)
    k = (path, st.st_mtime_ns, st.st_size)
    if k not in _hash_cache:
        _hash_cache[k] = hashlib.sha256(open(path, "rb").read()).hexdigest()
    return _hash_cache[k]


_manifest = {}


def manifest_row(rel):
    if not _manifest and os.path.exists(MANIFEST):
        for l in open(MANIFEST, encoding="latin1"):
            p = l.rstrip("\n").split("\t")
            if len(p) >= 4 and p[0] != "path":
                _manifest[p[0]] = "\t".join(p[1:4])
    return _manifest.get(rel, "")


def patch_inputs(f):
    """[patch file path or None, manifest row] of an engine/gamebryo file"""
    if not f.startswith(ENGINE + os.sep):
        return None, ""
    rel = os.path.relpath(f, ENGINE).replace(os.sep, "/")
    ed = os.path.join(PATCHES, rel + ".ed")
    return (ed if os.path.exists(ed) else None), manifest_row(rel)


def stamp_files(u, deps):
    return [u["source"]] + [d for d in deps if os.path.exists(d)]


def stamp_of(u, deps):
    h = hashlib.sha256()
    h.update(gbprogress._key(u).encode())
    h.update(json.dumps({k: u[k] for k in ("recipe", "name", "unit", "args", "cwd") if k in u}, sort_keys=True).encode())
    for f in sorted(set(stamp_files(u, deps))):
        ed, row = patch_inputs(f)
        h.update(("\0%s\0%s\0%s\0%s" % (os.path.relpath(f, ROOT), _sha(f), _sha(ed) if ed else "-", row)).encode())
    return h.hexdigest()


def _meta(o):
    try:
        return json.load(open(o[:-4] + ".deps"))
    except Exception:
        return None


def status(cache, u, strict=False):
    """(state, why): state is fresh / stale / unstamped (fresh by mtime only) / missing"""
    o = gbprogress.obj_path(cache, u)
    if not os.path.exists(o):
        return "missing", ""
    meta = _meta(o)
    if meta is None or meta.get("key") != gbprogress._key(u):
        return "stale", "compile key changed or no .deps"
    sp = o[:-4] + ".stamp"
    want = stamp_of(u, meta.get("deps", []))
    if os.path.exists(sp):
        return ("fresh", "") if open(sp).read().strip() == want else ("stale", "sources/patches/manifest changed")
    if gbprogress.needs_compile(cache, u):
        return "stale", "older than a source or header"
    # per file, not the manifest's mtime (any manifest commit made every unstamped obj of an overlay stale: 1314 for
    # the NiTerrainLib.h row alone): the obj is not older than a dep (above), so it was compiled from each dep's current
    # content; that content must be the result its own manifest row names. A .ed without a row goes by mtime as before.
    t = os.path.getmtime(o)
    for f in stamp_files(u, meta.get("deps", [])):
        ed, row = patch_inputs(f)
        if row:
            if _sha(f) != row.split("\t")[1]:
                return "stale", os.path.relpath(f, ROOT) + " differs from its engine-patches/manifest.tsv result"
        elif ed and os.path.getmtime(ed) > t:
            return "stale", "older than " + os.path.relpath(ed, ROOT)
    return ("stale", "unstamped (--strict)") if strict else ("unstamped", "")


def write_stamp(cache, u):
    o = gbprogress.obj_path(cache, u)
    meta = _meta(o)
    if meta is not None:
        open(o[:-4] + ".stamp", "w").write(stamp_of(u, meta.get("deps", [])) + "\n")


def units_of(filters=()):
    tree, _ = gbtree.assemble()
    us = [u for u in gbtree.load_units(tree) if u["source"]]
    return [u for u in us if not filters or any(f in u["name"] or f in u["unit"] for f in filters)]


def refresh(cache, units, rebuild=True, strict=False, adopt=False, j=8, log=print, only=None, missing=False):
    """Check (and with rebuild recompile) the objs of units that exist in cache (with `missing`, compile absent ones too);
    `only`: (recipe, name) pairs to limit to.
    Returns the units still stale."""
    cache = os.path.abspath(cache)
    stale, n_unst = [], 0
    for u in units:
        if only is not None and (u["recipe"], u["name"]) not in only:
            continue
        st, why = status(cache, u, strict)
        if st == "stale":
            stale.append((u, why))
        elif st == "unstamped":
            n_unst += 1
            if adopt:
                write_stamp(cache, u)
        elif st == "missing" and missing:
            stale.append((u, "no obj in this cache"))
    if n_unst and not adopt:
        log(f"gbfresh: {n_unst} obj(s) without a stamp, judged by mtime (run with --adopt to stamp them)")
    if not stale:
        return []
    for u, why in stale[:20]:
        log(f"gbfresh: stale {u['recipe']} {u['name']}: {why}")
    if len(stale) > 20:
        log(f"gbfresh: ... {len(stale) - 20} more")
    if not rebuild:
        return [u for u, _ in stale]
    log(f"gbfresh: recompiling {len(stale)} engine TU(s) into {cache}")
    bad = []
    with ThreadPoolExecutor(max_workers=max(1, j)) as ex:
        for (u, _), (ok, errs, dt) in zip(stale, ex.map(gbprogress.compile_unit, [(cache, u) for u, _ in stale])):
            if ok:
                write_stamp(cache, u)
            else:
                bad.append(u)
                log(f"gbfresh: FAIL {u['recipe']} {u['name']}" + "".join("\n    " + e[:300] for e in errs))
    return bad


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cache")
    ap.add_argument("--rebuild", action="store_true")
    ap.add_argument("--adopt", action="store_true")
    ap.add_argument("--strict", action="store_true")
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("filters", nargs="*")
    a = ap.parse_args()
    left = refresh(a.cache, units_of(a.filters), a.rebuild, a.strict, a.adopt, a.j)
    print("gbfresh:", "all current" if not left else f"{len(left)} stale/failed")
    sys.exit(1 if left else 0)


if __name__ == "__main__":
    main()
