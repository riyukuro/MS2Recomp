#!/usr/bin/env python3
"""Engine stage of tools/progress.py: compile the Gamebryo TUs of engine/units-gb.json, pair every function of their
objs with an exe VA and byte-match it (tools/bytematch.py), credit engine functions in status.tsv.

    .venv/bin/python tools/gbprogress.py [-j 8] [--cache DIR] [filter...]    # standalone: compile + match, print summary

Pairing (per obj function, funclets skipped): the mangled name through progress/symbols{,-engine,-manual}.tsv, else (or
when that pair does not match) the unique exe function of the same length whose bytes equal the obj's with relocations
masked. Functions with several identical exe copies and no name pair are then paired (2026-10-20, gb5) through an
exact caller's relocation target or a referenced vftable's slot of the same name (kept only if exact), else
(assign_copies, over all objs) one to one with the free copies nearest the obj's own functions (kept only if exact).
Credit (per exe VA, outside the game unit ranges of work/map/units.tsv and not claimed by a game unit row):
  matched     some obj's function is byte-identical (incl. unwind/EH data);
  functional  paired by name or a unique masked hit, but no obj matches exactly;
  stub        an uncredited function between two credited functions of the same unit (the TU's own range; runs of
              more than STUB_GAP functions are not counted).
Unit names: gb:<Lib>/<TU> (one name for both recipes of a TU; an exact v2525 obj wins the attribution over stock).
VA windows (engine/unit-windows.tsv, 2026-10-20 lb2): a unit-name prefix pairs only inside (include) or outside
(exclude) VA ranges (pairing, not just credit: name, search and callee pairs), for a library the exe links twice
(Gamebryo's LNUM Lua gb:Lua/ and the stock Lua 5.1.4 gb:Lua2/, mostly byte-identical); part of the match cache key.
Cache: <cache>/gb/obj/<recipe>/... (incremental: obj mtime vs source + /showIncludes deps), <cache>/gb/results.json
(per-obj match results keyed by obj mtime/size).
"""
import argparse
import bisect
import collections
import contextlib
import hashlib
import io
import json
import os
import re
import struct
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from multiprocessing import Pool

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import bytematch as bm  # noqa: E402
import ms2paths  # noqa: E402
import gbtree  # noqa: E402

CL = ms2paths.find_cl()
UNITS_TSV = ms2paths.UNITS_TSV
FUNCS = ms2paths.FUNCTIONS_TSV
GB_BAND = (0x141bf0000, 0x142303c10)        # main Gamebryo band (report only)
GB_TAIL = (0x1427b6c90, 0x1428d6000)        # Gamebryo tail: renderer / shader libs (report only)
STUB_GAP = 48                                # longest run of uncredited functions counted as one TU's stubs
KEY = "gb2"                                  # gb2: .deps now case-repaired (Wine lowercases dirs); bump to recompile everything
MATCH_KEY = "rtti-pin1"                         # bump to re-match every obj (pairing logic changed)
if bm.CHAIN:
    MATCH_KEY += "-chain"
LEAF_SMALL, LEAF_NEAR = 16, 0x10000             # assign_copies: small leaf copies only this near the obj's own functions
STATIC_NEAR = 0x10000                           # match_obj: a COMDAT caller's static callee only this near the obj's own code
RELOK_KEY = "relok9:"                         # assign_copies: relocation-consistency cache version
COPY_ROUNDS = 8                              # assign_copies: offers of an unpaired copy to the next claimant
LIB_RECIPE = "/obj/lib-"                         # obj path part of the library units' recipes (lib-cef, ...)
NO_CALLEE = bool(os.environ.get("MS2_GB_NO_CALLEE"))     # old pairing (no callee pass), for before/after comparisons
if NO_CALLEE:
    MATCH_KEY = "nocallee"


def _safe(name):
    return re.sub(r"[^A-Za-z0-9_.-]+", "__", name)


def obj_path(cache, u):
    return os.path.join(cache, "gb", "obj", u["recipe"], _safe(u["name"]) + ".obj")


def _key(u):
    ts = u.get("toolset", ms2paths.DEFAULT_TOOLSET)       # default toolset keeps the old key (no rebuild)
    return KEY + (" toolset=" + ts if ts != ms2paths.DEFAULT_TOOLSET else "") + " " + " ".join(u["args"])


def needs_compile(cache, u):
    o = obj_path(cache, u)
    d = o[:-4] + ".deps"
    if not os.path.exists(o) or not os.path.exists(d):
        return True
    try:
        meta = json.load(open(d))
    except Exception:
        return True
    if meta.get("key") != _key(u):
        return True
    t = os.path.getmtime(o)
    for f in [u["source"]] + meta.get("deps", []):
        if not os.path.exists(f) or os.path.getmtime(f) > t:
            return True
    return False


_CASE_DIRS = {}


def _case_fix(p):
    """Wine prints /showIncludes directories lowercased: resolve each component case-insensitively (None if absent)."""
    cur = "/"
    for part in p.strip("/").split("/"):
        nxt = os.path.join(cur, part)
        if not os.path.exists(nxt):
            if cur not in _CASE_DIRS:
                try:
                    _CASE_DIRS[cur] = {n.lower(): n for n in os.listdir(cur)}
                except OSError:
                    _CASE_DIRS[cur] = {}
            hit = _CASE_DIRS[cur].get(part.lower())
            if hit is None:
                return None
            nxt = os.path.join(cur, hit)
        cur = nxt
    return cur


def _real(p):
    p = ms2paths.host_path(p)
    if not os.path.exists(p):
        p = _case_fix(p) if os.path.isabs(p) else None
    return os.path.realpath(p) if p else None


def compile_unit(args):
    cache, u = args
    o = obj_path(cache, u)
    os.makedirs(os.path.dirname(o), exist_ok=True)
    env = ms2paths.toolchain_env()
    cl = ms2paths.find_cl_toolset(u.get("toolset"))
    cmd = ms2paths.cl_cmdline([cl, "/nologo", "/c"] + u["args"] + ["/showIncludes", "/Fo" + o, u["source"]])
    t0 = time.time()
    r = subprocess.run(cmd, cwd=u["cwd"], capture_output=True, text=True, env=env, encoding="latin1")
    deps, errs = set(), []
    for line in (r.stdout + r.stderr).splitlines():
        if line.startswith("Note: including file:"):
            f = _real(line.split(":", 2)[2])
            if f and f.startswith(ROOT):       # the repo's engine sources (MSVC / SDK headers do not change)
                deps.add(f)
        elif " error " in line or "fatal error" in line:
            errs.append(line.strip())
    ok = r.returncode == 0 and os.path.exists(o)
    if ok:
        json.dump({"key": _key(u), "deps": sorted(deps)}, open(o[:-4] + ".deps", "w"))
    elif os.path.exists(o):
        os.remove(o)
    return ok, errs[:3], time.time() - t0


# ---------------------------------------------------------------------------------------------------------------
# matching (worker processes)

G = {}


WINDOWS_TSV = os.path.join(ROOT, "engine", "unit-windows.tsv")


def load_windows():
    """[(unit prefix, include|exclude, lo, hi)] from engine/unit-windows.tsv"""
    out = []
    if os.path.exists(WINDOWS_TSV):
        for ln in open(WINDOWS_TSV):
            c = ln.split("#")[0].split()
            if len(c) >= 4:
                out.append((c[0], c[1], int(c[2], 16), int(c[3], 16)))
    return out


def unit_window(unit, windows):
    """(include ranges or None, exclude ranges) of a unit name"""
    rg = lambda kind: [(lo, hi) for p, k, lo, hi in windows if k == kind and unit.startswith(p)]
    return (rg("include") or None, rg("exclude"))


def _allowed(va):
    inc, exc = G.get("win") or (None, [])
    return va is None or ((inc is None or any(lo <= va < hi for lo, hi in inc)) and
                          not any(lo <= va < hi for lo, hi in exc))


def _is_text(va):
    exe = G["exe"]
    return any(sec.Name.rstrip(b"\0") == b".text" and sec.VirtualAddress <= va - exe.base < sec.VirtualAddress
               + sec.Misc_VirtualSize for sec in exe.pe.sections)


def _init():
    exe = bm.Exe(bm.EXE)
    names, dnames = {}, {}
    # symbols-engine-manual first (gb15): an engine function whose mangled name the game also defines (the game's own
    # TinyXML has a global ?TiXmlFOpen too) is pinned to the engine copy by a row there; no other row overlaps.
    for f in ("symbols-engine-manual.tsv", "symbols-manual.tsv", "symbols.tsv", "symbols-engine.tsv"):
        p = os.path.join(ROOT, "progress", f)
        if not os.path.exists(p):
            continue
        for ln in open(p):
            c = ln.rstrip("\n").split("\t")
            if ln[0] != "#" and len(c) > 1 and (len(c) < 3 or c[2] == "func"):
                names.setdefault(c[0], int(c[1], 16))
            elif ln[0] != "#" and len(c) > 2 and c[0].startswith("??_7"):
                dnames.setdefault(c[0], int(c[1], 16))
    bm.SYMBOLS.clear()
    bm.SYMBOLS.update(names)      # relocation targets resolve through the same tables
    bylen = collections.defaultdict(list)
    for rva, (end, _) in exe.rf.items():
        if bm.CHAIN and rva in exe._chained:
            continue
        bylen[exe.chain_end(rva) - rva].append(rva)
    # leaf functions (no stack frame, no calls) have no .pdata entry: their length comes from the function map
    leaf = set()
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if p[0] and not p[0].startswith("#"):
            rva = int(p[0], 16) - exe.base
            if rva not in exe.rf and int(p[1]) > 0:
                bylen[int(p[1])].append(rva)
                leaf.add(rva)
    game = game_ranges()
    G.update(exe=exe, names=names, dnames=dnames, bylen=bylen, leaf=leaf, game=game, game_lo=[a for a, _ in game],
             named_vas=set(names.values()))


def owned_game_units():
    """start VAs of the work/map/units.tsv rows owned by a library doc (see game_ranges)"""
    return {int(v, 16) for d in gbtree.lib_docs() for v in d.get("owned_game_units", ())}


def game_ranges():
    """sorted [(lo, hi)] of the game units (work/map/units.tsv), minus the rows a library doc owns: "owned_game_units"
    in engine/units-lib-*.json lists unit-map rows (start VA, hex) whose range is a vendored library compiled by the
    engine stage (fmt 0.12.0, 2026-10-20 tc1: the game map's source-less ?\\fmt.cpp row)."""
    owned = owned_game_units()
    game = []
    for line in open(UNITS_TSV):
        p = line.rstrip("\n").split("\t")
        if not p[0].startswith("#") and len(p) > 1 and int(p[0], 16) not in owned:
            game.append((int(p[0], 16), int(p[1], 16)))
    game.sort()
    return game


def _in_game(va):
    import bisect
    i = bisect.bisect_right(G["game_lo"], va) - 1
    return i >= 0 and va < G["game"][i][1]


def _search(obj, si):
    exe = G["exe"]
    data, fields, unw = obj.function(si)
    keep = bytearray(b"\x01") * len(data)
    for off, ln, *_ in fields:
        for k in range(off, min(off + ln, len(data))):
            keep[k] = 0
    idx = [k for k in range(len(data)) if keep[k]]
    want = bytes(data[k] for k in idx)
    hits = []
    leaf = G["leaf"]
    for rva in G["bylen"].get(len(data), []):
        if (rva in leaf) != (unw is None):      # a leaf (no .pdata) only pairs with a leaf, and vice versa
            continue
        img = exe.img[rva:rva + len(data)]
        if bytes(img[k] for k in idx) == want:
            hits.append(rva + exe.base)
    return hits


def _match(obj, n, va):
    with contextlib.redirect_stdout(io.StringIO()):
        try:
            return bool(bm.match_one(obj, n, va, G["exe"], verbose=False, check_unwind=True, quiet=True))
        except Exception:
            return False


def _comdat_any(obj, n):
    return obj.sec(obj.syms[obj.by_name[n]][2]).get("comdat", (0,))[0] == 2


def _hints(obj, n, shints):
    """the exe targets of the last match of n; the static callees of a COMDAT-any caller go to shints instead: the
    linker may have kept another TU's copy of the caller, which calls that TU's statics (LuaTraits<T>::ToLuaObject ->
    _SWIG_Lua_AddMetatable), so they count only near the obj's own code (_static_hints)"""
    t = dict(bm.LAST_TARGETS)
    if not _comdat_any(obj, n):
        return t
    for k in [k for k in t if k in obj.by_name and obj.syms[obj.by_name[k]][4] == 3]:
        shints.setdefault(k, t.pop(k))
    return t


def _static_hints(obj, out, shints, callees):
    """shints whose exe VA lies within STATIC_NEAR of the obj's own (non-COMDAT-any) exact functions (if it has none:
    any of its exact functions) -> callees"""
    own = sorted(va for n, va, ok, _ in out if ok and not _comdat_any(obj, n)) or sorted(va for _, va, ok, _ in out if ok)
    if not own:
        return
    for k, v in shints.items():
        if k not in callees:
            i = bisect.bisect_left(own, v)
            if min(abs(v - own[j]) for j in (i - 1, i) if 0 <= j < len(own)) <= STATIC_NEAR:
                callees[k] = v


def match_obj(path):
    """([(symbol, va, ok, how)] for the obj's functions that pair with an exe VA, [[symbol, [exe copies]]] of the
    unpaired functions whose bytes several exe functions have, exe VAs of the obj's exact non-template functions)"""
    out = []
    try:
        obj = bm.Obj(path)
    except Exception:
        return out, [], []
    callees, pending = {}, []    # name -> exe VA called/referenced by this obj's exact functions; unpaired functions
    copies = {}                  # unpaired name -> the exe functions whose bytes equal it (relocations masked), if several
    weak = {}                    # name -> its non-exact table-name pair, kept if nothing better turns up
    shints = {}                  # static name -> exe VA called by an exact COMDAT-any function (see _hints)
    rtti = {}                    # the obj's ms_RTTI anchors (see _rtti_clash), found on first use
    for si in obj.func_symbols():
        n = obj.syms[si][0]
        if n.startswith(bm.FUNCLET_PREFIXES):
            continue
        va = G["names"].get(n)
        if not _allowed(va):
            va = None
        ok = False
        how = "name"
        hits = ()
        if va is not None:
            ok = _match(obj, n, va)
            if ok and _rtti_clash(obj, n, va, rtti):
                va, ok = None, False      # a table name on another class's copy (the TUs' twins): search instead
            if ok:
                callees.update(_hints(obj, n, shints))
        if not ok:
            hits = [h for h in _search(obj, si) if _allowed(h)]
            if len(hits) > 1:
                eng = tuple(h for h in hits if not _in_game(h))      # game-unit copies are never engine credit
                if eng:
                    copies[n] = eng
            if len(hits) == 1 and hits[0] != va:
                ok2 = _match(obj, n, hits[0])
                if ok2:
                    callees.update(_hints(obj, n, shints))
                if ok2 or va is None:
                    va, how, ok = hits[0], "search", ok2
            elif len(hits) == 1:
                how = "name"
        if va is None:
            pending.append(n)
            continue
        if not ok and n in copies:       # its table name points at another (game) copy: may still pair below
            weak[n] = (n, va, ok, how)
            pending.append(n)
            continue
        out.append((n, va, ok, how))
    # callee pass: a function with no table name and several byte-identical exe copies (template instantiations for
    # types of the same size, e.g. map<utf8string,__int64> / map<utf8string,unsigned __int64>) is paired with the exe
    # function an exact caller of this obj references under its name, if it then matches exactly; repeated until no
    # new exact match appears
    # vftable pass: a vftable referenced by an exact function (or named in the tables) pairs its slots' functions
    # (destructors, virtuals nobody calls directly) with the exe vftable's slots
    exe = G["exe"]
    vfts = {obj.syms[i][0]: i for i in obj.syms if obj.syms[i][0].startswith("??_7") and obj.syms[i][2] > 0}
    tried = set()
    while (pending or vfts) and not NO_CALLEE:
        grew = False
        _static_hints(obj, out, shints, callees)
        for n in list(vfts):
            va = callees.get(n) or G["dnames"].get(n)
            if va is not None and (_allowed(va) or not _is_text(va)):   # windows are code ranges, vftables are .rdata
                for tn, tgt in _vft_slots(obj, vfts.pop(n), va):
                    callees.setdefault(tn, tgt)
                grew = True
        nxt = []
        for n in pending:
            va = callees.get(n)
            if va is None or not _allowed(va) or (va - exe.base not in exe.rf and va - exe.base not in G["leaf"]) \
                    or (n, va) in tried:
                nxt.append(n)
                continue
            tried.add((n, va))
            if _match(obj, n, va):          # exact only: the caller itself may be a byte-identical look-alike of
                if n in copies and (va in G["named_vas"] or va in {v for _, v, ok, _ in out if ok}):
                    weak[n] = (n, va, True, "callee")   # another type, so its reloc targets are only a hint: a VA
                    nxt.append(n)       # the tables or another name of this obj hold leaves a name with several
                    continue            # copies to assign_copies
                callees.update(_hints(obj, n, shints))
                out.append((n, va, True, "callee"))
            else:                           # a wrong hint: still unpaired (a copy candidate below)
                nxt.append(n)
        if len(nxt) == len(pending) and not grew:
            break
        pending = nxt
    # library objs (engine/units-lib-*.json, compiled from the vendor's own sources inside an include window): a hint
    # that stays non-exact (the vendor built them with another MSVC: EH states, inlining) still names the function at
    # that VA, so it pairs as functional rather than leaving the function a stub
    if LIB_RECIPE in path and not NO_CALLEE:
        used = {va for _, va, _, _ in out}
        for n in [n for n in pending if n not in copies and n not in weak]:
            va = callees.get(n)
            if va is not None and va not in used and _allowed(va) and G["win"] and G["win"][0] \
                    and (va - exe.base in exe.rf or va - exe.base in G["leaf"]):
                out.append((n, va, False, "hint"))
                used.add(va)
                pending.remove(n)
    # the remaining unpaired functions with several byte-identical exe copies are paired by assign_copies (all objs)
    out += [weak[n] for n in pending if n in weak]
    cands = [[n, list(copies[n])] for n in pending if n in copies]
    own = sorted({va for n, va, ok, _ in out if ok and obj.sec(obj.syms[obj.by_name[n]][2]).get("comdat", (0,))[0] != 2})
    return out, cands, own


def _vft_slots(obj, si, va):
    """[(slot symbol, exe target)] of the obj's vftable si placed at exe va (nothing if its unrelocated bytes differ)"""
    exe = G["exe"]
    _, value, secnum = obj.syms[si][:3]
    sec = obj.sec(secnum)
    nxt = [v for (_, v, sn, _, _) in obj.syms.values() if sn == secnum and v > value]
    end = min(nxt) if nxt else sec["size"]
    data = sec["data"][value:end]
    try:
        xb = exe.read(va, len(data))
    except Exception:
        return []
    if len(xb) < len(data):
        return []
    mask = bytearray(len(data))
    out = []
    for r, rsi, ty in sec["relocs"]:
        if not value <= r < end:
            continue
        off = r - value
        for k in range(off, min(off + bm.RELOC_LEN.get(ty, 4), len(data))):
            mask[k] = 1
        if ty == bm.REL_ADDR64 and off + 8 <= len(data):
            out.append((obj.syms[rsi][0], struct.unpack_from("<Q", xb, off)[0] - struct.unpack_from("<q", data, off)[0]))
    if any(not mask[k] and data[k] != xb[k] for k in range(len(data))):
        return []
    return out


def _match_job(job):
    path, win = job
    G["win"] = win
    return path, match_obj(path)


def _greedy(todo, xok, match=None):
    """one-to-one pairing of each group's names with its exact copies (maximum matching): [(name, va)]. xok caches
    match results ("name@va" -> bool); without `match` an uncached trial returns None (a worker must run it)"""
    out = []
    for ns, copies in todo:
        for n in ns:
            for v in copies:
                t = f"{n}@{v:x}"
                if t not in xok:
                    if match is None:
                        return None
                    xok[t] = match(n, v)
        # maximum matching (augmenting paths, names and copies in the given order): a name whose callees are not in
        # the tables matches every copy, and first-fit let it take the one copy a callee-pinned name could use
        adj = {n: [v for v in copies if xok[f"{n}@{v:x}"]] for n in ns}
        mate = {}

        def augment(n, seen):
            for v in adj[n]:
                if v not in seen:
                    seen.add(v)
                    if v not in mate or augment(mate[v], seen):
                        mate[v] = n
                        return True
            return False
        for n in ns:
            augment(n, set())
        got = {n: v for v, n in mate.items()}
        out += [(n, got[n]) for n in ns if n in got]
    return out


def _verify_job(job):
    path, todo, xok = job
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, xok
    _greedy(todo, xok, lambda n, v: _match(obj, n, v))
    return path, xok


def _code_match(obj, n, va):
    """code bytes match (relocations resolved consistently) whatever the unwind/EH data: its targets are reliable"""
    with contextlib.redirect_stdout(io.StringIO()):
        try:
            return bool(bm.match_one(obj, n, va, G["exe"], verbose=False, check_unwind=False, quiet=True))
        except Exception:
            return False


def _libhint_job(job):
    """library obj: the exe targets (vftables -> their slots, direct callees) of its functions whose code matches
    (exact pairs, the copy pairs assign_copies found, then the hints themselves, to a fixpoint; plus `ext`, the other
    library objs' hints) name its functions that stay unpaired: (path, [(name, va)] credited functional, {name: va}
    every target found)"""
    path, pairs, win, ext = job
    G["win"] = win
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, [], {}
    exe = G["exe"]
    funcs = [obj.syms[si][0] for si in obj.func_symbols() if not obj.syms[si][0].startswith(bm.FUNCLET_PREFIXES)]
    paired = {n for n, _, _ in pairs}
    callees = {}
    todo = [(n, va) for n, va, _ in pairs]
    vfts = {obj.syms[i][0]: i for i in obj.syms if obj.syms[i][0].startswith("??_7") and obj.syms[i][2] > 0}
    out = []
    used = {va for _, va, _ in pairs}
    while True:
        for n, va in todo:
            if _code_match(obj, n, va):
                for k, v in bm.LAST_TARGETS.items():
                    callees.setdefault(k, v)
        for k, v in ext.items():
            callees.setdefault(k, v)
        for vn in list(vfts):
            va = callees.get(vn)
            if va is not None and not _is_text(va):
                for tn, tgt in _vft_slots(obj, vfts.pop(vn), va):
                    callees.setdefault(tn, tgt)
        todo = []
        for n in funcs:
            va = callees.get(n)
            if n in paired or va is None or va in used or not _allowed(va):
                continue
            if va - exe.base in exe.rf or va - exe.base in G["leaf"]:
                out.append((n, va))
                todo.append((n, va))
                paired.add(n)
                used.add(va)
        if not todo:
            break
    return path, out, {k: v for k, v in callees.items() if _allowed(v) or not _is_text(v)}


def lib_hints(res, paths, windows, j, log=print):
    """res[key]["hpairs"] of the library units (recipe lib-*): see _libhint_job (two rounds: the second one seeded
    with every obj's targets); a VA some obj pairs exactly or another hint already names is skipped"""
    keys = [k for k, c in res.items() if c["recipe"].startswith("lib-") and k in paths]
    jobs, byp = [], {}
    for k in keys:
        c = res[k]
        win = unit_window(c["unit"], windows)
        if not win[0]:
            continue
        jobs.append((paths[k], [(n, va, ok) for n, va, ok, _ in c["pairs"] + c.get("xpairs", [])], win))
        byp[paths[k]] = k
    if not jobs:
        return
    taken = {va for c in res.values() for _, va, ok, _ in c["pairs"] + c.get("xpairs", []) if ok}
    got, ext = {}, {}
    with Pool(max(1, j), initializer=_init) as p:
        for rnd in range(2):
            for path, hp, tg in p.imap_unordered(_libhint_job, [jb + (ext if rnd else {},) for jb in jobs]):
                got[byp[path]] = hp
                if not rnd:
                    for k, v in tg.items():
                        ext.setdefault(k, v)
    n = 0
    for k in sorted(got):
        res[k]["hpairs"] = []
        for nm, va in got[k]:
            if va not in taken:
                taken.add(va)
                res[k]["hpairs"].append([nm, va, False, "libhint"])
                n += 1
    log(f"engine: library hint pairs {n}")


def _small_leaf():
    """exe VAs of the leaf functions (no .pdata) shorter than LEAF_SMALL bytes"""
    exe = bm.Exe(bm.EXE)
    out = set()
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if p[0] and not p[0].startswith("#") and int(p[1]) < LEAF_SMALL and int(p[0], 16) - exe.base not in exe.rf:
            out.add(int(p[0], 16))
    return out


def _reloc_targets(obj, data, fields, nodup=False):
    """[(field offset, extra, addend, key)] of the function's REL32 relocations; key names the target within the obj
    (nodup: also code in /Gy COMDATs of selection NODUPLICATES, the TU's own non-inline functions)"""
    out = []
    for f in fields:
        tsi = f[5]
        if tsi is not None and bm.REL_REL32 <= f[3] <= bm.REL_REL32 + 5:
            t = obj.syms[tsi]
            if t[2] <= 0 or obj.sec(t[2])["chars"] & 0x20 and \
                    obj.sec(t[2]).get("comdat", (0,))[0] not in ((0, 1) if nodup else (0,)):
                continue        # an inline callee has several identical copies in the exe: says nothing of the TU
            out.append((f[0], f[3] - bm.REL_REL32, struct.unpack_from("<i", data, f[0])[0], (t[0], t[2], t[1])))
    return out


def _rtti_clash(obj, n, va, memo):
    """the function at `va` loads an ms_RTTI other than the one _exe_anchors finds for the obj: it is another TU's
    copy (NiDX9/NiD3D10/D3D11PersistentSrcTextureRendererData::GetViewerStrings are byte-identical twins)"""
    data, fields, _ = obj.function(obj.by_name[n])
    tg = [r for r in _reloc_targets(obj, data, fields) if r[3][0].startswith("?ms_RTTI@")]
    if not tg:
        return False
    if "anchors" not in memo:
        def resolve(m, v):
            d, fl, _ = obj.function(obj.by_name[m])
            for fo, extra, add, key in _reloc_targets(obj, d, fl):
                yield key, v + fo + 4 + extra + struct.unpack_from("<i", G["exe"].img, v - G["exe"].base + fo)[0] - add
        memo["anchors"] = {k: v for k, v in _exe_anchors(obj, resolve).items() if k[0].startswith("?ms_RTTI@")}
    an, rva = memo["anchors"], va - G["exe"].base
    return any(key in an and an[key] != va + fo + 4 + extra + struct.unpack_from("<i", G["exe"].img, rva + fo)[0] - add
               for fo, extra, add, key in tg)


def _exe_anchors(obj, resolve):
    """{relocation key: exe VA} found from the exe alone, not from any pairing: string literals whose text occurs
    once in .rdata; the class's ms_RTTI, from the copy of its dynamic initializer that loads the class-name string;
    and its vftable, the .rdata slot holding GetRTTI (`lea rax, [ms_RTTI]; ret`) less the slot's offset"""
    exe = G["exe"]
    if "getrtti" not in G:
        secs = {}
        for sec in exe.pe.sections:                 # the first of a name (the exe has a second, tiny .text)
            secs.setdefault(sec.Name.rstrip(b"\0"), (sec.VirtualAddress, sec.Misc_VirtualSize))
        tva, tsz = secs[b".text"]
        get = collections.defaultdict(list)
        for m in re.finditer(rb"\x48\x8d\x05(....)\xc3", exe.img[tva:tva + tsz], re.S):
            f = exe.base + tva + m.start()
            get[f + 7 + struct.unpack("<i", m.group(1))[0]].append(f)
        G["getrtti"], G["secs"] = get, secs
    get, (rva0, rsz) = G["getrtti"], G["secs"][b".rdata"]

    def find_all(pat, align=1):
        out, i = [], exe.img.find(pat, rva0, rva0 + rsz)
        while i >= 0 and len(out) < 3:
            if i % align == 0:
                out.append(exe.base + i)
            i = exe.img.find(pat, i + 1, rva0 + rsz)
        return out
    out = {}
    for t in obj.syms.values():
        if t[0].startswith("??_C@") and t[2] > 0 and t[1] == 0 and t[3] == 0:
            data = obj.sec(t[2])["data"]
            if len(data) >= 6 and data.endswith(b"\0"):
                # not the tail of a longer string; the linker may put a non-text constant (a float) right before it
                hits = [h for h in find_all(data) if not 0x20 <= exe.img[h - exe.base - 1] < 0x7f]
                if len(hits) == 1:
                    out[(t[0], t[2], t[1])] = hits[0]
    rtti = {}
    for n in obj.by_name:
        m = re.fullmatch(r"\?\?__E\?ms_RTTI@(\w+)@@2VNiRTTI@@B@@YAXXZ", n)
        if not m:
            continue
        data, fields, _ = obj.function(obj.by_name[n])
        pat = bytearray(data)
        for f in fields:
            pat[f[0]:f[0] + f[1]] = b"\0" * f[1]
        pk = ("thunk", bytes(pat), tuple((f[0], f[1]) for f in fields))
        if pk not in G:               # the initializers are tail-jump leaves the function map may not list: scan .text
            rx, o = b"", 0
            for f in sorted(fields):
                rx += re.escape(data[o:f[0]]) + b".{%d}" % f[1]
                o = f[0] + f[1]
            rx += re.escape(data[o:])
            tva, tsz = G["secs"][b".text"]
            G[pk] = [exe.base + tva + m.start() for m in re.finditer(rx, exe.img[tva:tva + tsz], re.S)]
        good = []
        for v in G[pk]:
            at = dict(resolve(n, v))
            if any(k in out for k in at) and all(out[k] == at[k] for k in at if k in out):
                good.append(at)
        if len(good) == 1:
            for k, tv in good[0].items():
                if k[0] == f"?ms_RTTI@{m.group(1)}@@2VNiRTTI@@B":
                    out[k] = rtti[m.group(1)] = tv
    for t in obj.syms.values():
        m = re.fullmatch(r"\?\?_7(\w+)@@6B@", t[0])
        if not m or t[2] <= 0 or m.group(1) not in rtti or len(get.get(rtti[m.group(1)], ())) != 1:
            continue
        for off, si, ty in obj.sec(t[2])["relocs"]:
            if obj.syms[si][0] == f"?GetRTTI@{m.group(1)}@@UEBAPEBVNiRTTI@@XZ":
                slots = find_all(struct.pack("<Q", get[rtti[m.group(1)]][0]), 8)
                if len(slots) == 1:
                    out[(t[0], t[2], t[1])] = slots[0] - (off - t[1])
                break
    return out


def _relok_job(job):
    """{"name@va": 1 | 0 | -1}: the copy's relocations resolve to the exe VAs the obj's exact pairs give the same
    targets (1), none of its targets is known (0), or one resolves elsewhere (-1: another TU's copy)"""
    k, path, exact, todo = job
    exe = G["exe"]
    out = {}
    try:
        obj = bm.Obj(path)
    except Exception:
        return k, out

    def resolve(n, va):
        data, fields, _ = obj.function(obj.by_name[n])
        rva = va - exe.base
        for fo, extra, add, key in _reloc_targets(obj, data, fields):
            yield key, va + fo + 4 + extra + struct.unpack_from("<i", exe.img, rva + fo)[0] - add
    # anchors: only the obj's own (non pick-any COMDAT) exact pairs; a COMDAT's exact pair may itself be a sibling
    # instantiation's byte-identical copy. A target the anchors disagree on is dropped.
    seen = collections.defaultdict(set)
    for n, va in exact:
        if n in obj.by_name and obj.sec(obj.syms[obj.by_name[n]][2]).get("comdat", (0,))[0] != 2:
            for key, t in resolve(n, va):
                seen[key].add(t)
    known = {key: next(iter(ts)) for key, ts in seen.items() if len(ts) == 1}
    strong = _exe_anchors(obj, resolve)      # the class's own RTTI static / vftable: certain, and they tell its TU
    known.update(strong)
    for n, hits in todo:
        if n not in obj.by_name:
            continue
        at = {v: dict(resolve(n, v)) for v in hits}
        # only a target the copies disagree on tells them apart (one all of them share, e.g. a merged string, does not)
        disc = {key for key in known if len({m.get(key) for m in at.values()}) > 1}
        for v, m in at.items():
            # a vote: an anchor may itself be a same-named sibling TU's copy (the material node libraries' static
            # CreateFragmentN), so one stray target does not rule a copy out; only agreement on a TU-private target
            # (static, own function) confirms it, a shared COMDAT one (vftable, string) can only tell against it
            ks = disc & m.keys()
            bad = sum(known[key] != m[key] for key in ks)
            good = len(ks) - bad
            r = -1 if bad > good else 0
            if good > bad and any(known[key] == m[key] and (key in strong or obj.sec(key[1]).get("comdat", (0,))[0] == 0)
                                  for key in ks):
                r = 1
            out[f"{n}@{v:x}"] = r
    return k, out


def assign_copies(res, cgroups, paths, j, log=print):
    """Pair the objs' unpaired functions that have several byte-identical exe copies (template instantiations of
    same-size types, e.g. map<utf8string,int> / map<utf8string,unsigned int>, kept apart by the linker): every copy no
    obj pairs exactly goes to the claiming obj whose own (non-COMDAT-any) exact functions lie nearest (the TU whose
    instantiation the linker placed there), then each obj pairs its functions one to one with its copies (greedy: the
    first copy that matches exactly; a callee named in the tables tells same-byte copies apart). Writes
    res[key]["xpairs"] (match results cached per obj result in res[key]["xok"])."""
    claimed = {va for c in res.values() for _, va, ok, _ in c["pairs"] if ok}
    small_leaf = _small_leaf()
    groups = collections.defaultdict(list)
    for k, c in res.items():
        for n, gid in c.get("cands", ()):
            if gid in cgroups:
                groups[(k, tuple(cgroups[gid]))].append(n)

    # relocation consistency (gb12): the obj's exact pairs give exe VAs for its relocation targets (vftable, RTTI,
    # strings, statics); a copy whose relocations resolve elsewhere is another TU's (sibling classes' CreateObject /
    # ??_G / CreateClone are byte-identical but for those), one that resolves the same is the obj's own
    rjobs = []
    for k, c in res.items():
        todo = sorted((n, tuple(cgroups[gid])) for n, gid in c.get("cands", ()) if gid in cgroups)
        if not todo or k not in paths:
            continue
        exact = sorted((n, va) for n, va, ok, _ in c["pairs"] if ok)
        rk = RELOK_KEY + hashlib.sha1(repr((exact, todo)).encode()).hexdigest()[:16]
        if c.get("relok", {}).get("key") != rk:
            rjobs.append((rk, (k, paths[k], exact, todo)))
    if rjobs:
        log(f"engine: copy relocation targets of {len(rjobs)} obj(s) ...")
        rks = {jb[0]: rk for rk, jb in rjobs}
        with Pool(max(1, j), initializer=_init) as p:
            for k, out in p.imap_unordered(_relok_job, [jb for _, jb in rjobs], chunksize=4):
                res[k]["relok"] = {"key": rks[k], "ok": out}
    rel = {k: c.get("relok", {}).get("ok", {}) for k, c in res.items()}

    def xview(k):
        # exact copy matches, less those another TU's relocation targets rule out
        r = rel.get(k, {})
        return {t: b and r.get(t, 0) >= 0 for t, b in res[k].get("xok", {}).items()}

    def dist(k, v):
        # an exact copy pair of an earlier round anchors the obj too (an obj whose only own code was a copy, e.g. a
        # NiPSys* modifier's CreateObject, then pulls its ??_G / ctor copies next to it)
        own = list(res[k].get("own") or ()) + [a for _, a in xpairs.get(k, ())]
        if own:
            return min(abs(v - a) for a in own)
        ex = [va for _, va, ok, _ in res[k]["pairs"] if ok]
        return (min(abs(v - a) for a in ex) if ex else 1 << 40) + (1 << 32)
    xpairs = collections.defaultdict(list)
    refused = set()       # (va, key): the obj had the copy and none of its names matched it exactly
    for _ in range(COPY_ROUNDS):    # a copy its nearest obj cannot pair goes to the next nearest claimant
        done = {(k, n) for k in xpairs for n, _ in xpairs[k]}
        owner = {}
        for (k, hits), ns in groups.items():
            for v in hits:
                if v in claimed or (v, k) in refused:
                    continue
                rv = [rel.get(k, {}).get(f"{n}@{v:x}", 0) for n in ns]
                if rv and min(rv) == -1 and max(rv) == -1:
                    continue                              # every name of the group resolves to other targets there
                d = dist(k, v)
                if v in small_leaf and d > LEAF_NEAR:     # a few-byte leaf body (ret, return a constant) says
                    continue                              # nothing about its TU: only near the obj's own code
                if max(rv, default=0) == 1:
                    d -= 1 << 50                          # its relocations confirm the obj: before any distance
                if v not in owner or (d, k) < owner[v]:
                    owner[v] = (d, k)
        todo = collections.defaultdict(list)
        for (k, hits), ns in groups.items():
            mine = sorted((v for v in hits if v in owner and owner[v][1] == k), key=lambda v: (owner[v][0], v))  # nearest first
            left = [n for n in ns if (k, n) not in done]
            if mine and left:
                todo[k].append((left, mine))
        if not todo:
            break
        jobs = [(paths[k], prs, res[k].get("xok", {}), k) for k, prs in todo.items()
                if k in paths and _greedy(prs, xview(k)) is None]
        if jobs:
            log(f"engine: pairing byte-identical copies in {len(jobs)} obj(s) ...")
            byp = {p: k for p, _, _, k in jobs}
            with Pool(max(1, j), initializer=_init) as p:
                for path, xok in p.imap_unordered(_verify_job, [(p_, t, x) for p_, t, x, _ in jobs]):
                    res[byp[path]]["xok"] = xok
        grew, r0 = False, len(refused)
        for k, prs in todo.items():
            got = _greedy(prs, xview(k)) or ()
            xpairs[k] += got
            claimed |= {v for _, v in got}
            grew |= bool(got)
            refused |= {(v, k) for _, mine in prs for v in mine if v not in claimed}
        if not grew and len(refused) == r0:
            break
    for k, c in res.items():
        c["xpairs"] = [[n, v, True, "copy"] for n, v in xpairs.get(k, ())]


# ---------------------------------------------------------------------------------------------------------------

# ---------------------------------------------------------------------------------------------------------------
# block pass (2026-10-22 gb12): a TU's dynamic initializers (.text$di) and atexit destructors (.text$yd) are one
# section per function; the linker lays an obj's sections of one name out contiguously, in the obj's section order, at
# the section alignment. Header statics (NiXKeyregisterloaderreturn, efd kCAT_* FixedStrings, NiFloodgateSDM) give
# every includer the same byte-identical functions (hundreds of copies), which assign_copies cannot place (its
# distance is to the obj's .text code, far away). Here each obj's whole block is placed: an exe base where every
# function's masked bytes match; relocations into the obj's own (non-COMDAT) data sections that agree on one base per
# section are counted as a score (the exe TU's data layout may differ a little), used only to rank placements.
BLOCK_SECS = (".text$di", ".text$yd")
BLOCK_KEY = "blk7"


def _block_layout(obj, secname):
    """[(symbol, offset, data, fields, leaf, alignment)] of the obj's functions in sections named secname, in link
    order"""
    secs = [(i + 1, s) for i, s in enumerate(obj.sections) if s["name"] == secname and s["chars"] & 0x20]
    fsyms = {}
    for si in obj.func_symbols():
        n, v, sn = obj.syms[si][0], obj.syms[si][1], obj.syms[si][2]
        if not n.startswith(bm.FUNCLET_PREFIXES):
            fsyms.setdefault(sn, []).append((v, si))
    out, off = [], 0
    for sn, s in secs:
        al = 1 << (((s["chars"] >> 20) & 0xF) - 1) if (s["chars"] >> 20) & 0xF else 16
        off = (off + al - 1) & -al
        for v, si in sorted(fsyms.get(sn, ())):
            data, fields, unw = obj.function(si)
            out.append((obj.syms[si][0], off + v, bytes(data), fields, unw is None, al))
        off += s["size"]
    return out


def _block_cands(obj, lay):
    """[(base, score, bad, shifts)] where the block lay fits the exe; score = own-data relocations agreeing on a base
    per section, bad = functions (at most 1/8) whose bytes differ, shifts = [[index, delta]] of the functions placed
    off their obj offset (after a function whose exe size differs)"""
    exe = G["exe"]
    if not lay:
        return []
    pats = []
    for n, off, data, fields, leaf, al in lay:
        m = bytearray(b"\xff") * len(data)
        loc = []
        for f in fields:
            for k in range(f[0], min(f[0] + f[1], len(data))):
                m[k] = 0
            tsi = f[5]
            if tsi is not None and bm.REL_REL32 <= f[3] <= bm.REL_REL32 + 5:
                t = obj.syms[tsi]
                if t[2] > 0 and not obj.sec(t[2])["chars"] & 0x20 and obj.sec(t[2]).get("comdat", (0,))[0] == 0:
                    loc.append((f[0], f[3] - bm.REL_REL32, struct.unpack_from("<i", data, f[0])[0] + 0, t[2], t[1]))
        mi = int.from_bytes(bytes(m), "little")
        pats.append((len(data), mi, int.from_bytes(data, "little") & mi, loc, al))
    # seed: the non-leaf function with the fewest (but some) masked hits
    best = None
    for i, (n, off, data, fields, leaf, al) in enumerate(lay):
        if leaf:
            continue
        hits = _search(obj, obj.by_name[n])
        if hits and (best is None or len(hits) < len(best[1])):
            best = (i, hits)
        if 0 < len(hits) <= 2:
            break
    if best is None:
        return []
    starts = G.get("starts")
    if starts is None:
        starts = G["starts"] = sorted(exe.rf)

    def fits(i, va):
        """None: the exe function at va is ours; else the size of the (different) exe function there, or -1"""
        ln, mi, want, loc, al = pats[i]
        rva = va - exe.base
        if not _allowed(va) or _in_game(va):
            return -1
        if (rva not in exe.rf or exe.chain_end(rva) - rva == ln) and \
                int.from_bytes(bytes(exe.img[rva:rva + ln]), "little") & mi == want:
            return None
        # a function the exe builds differently (MS2 change, other inlining): tolerated where the exe has a
        # function of its own (with unwind data, so its size is known)
        return exe.chain_end(rva) - rva if rva in exe.rf else -1
    # no tolerance: blocks are mostly identical header thunks, so a block with one differing function fits at many
    # wrong places (tried 1/8 in gb12: NiBezPosKey's thunks landed on NiAlphaController's block)
    out, lim = [], 0
    for h in best[1]:
        si = best[0]
        pos, bad = {si: h}, 0
        # walk forward: each function follows the previous one's exe size at its own section alignment
        for i in range(si, len(pats)):
            if i > si:
                pos[i] = (end + pats[i][4] - 1) & -pats[i][4]
            r = fits(i, pos[i])
            if r == -1:
                bad = len(pats)
                break
            if r is not None:
                bad += 1
            end = pos[i] + (pats[i][0] if r is None else r)
            if bad > lim:
                break
        # walk back: the previous function ends right below (our size if it matches there, else the exe function
        # that starts before)
        for i in range(si - 1, -1, -1):
            if bad > lim:
                break
            nxt = pos[i + 1]
            a = pats[i][4]
            guess = (nxt - pats[i][0]) & -a
            if fits(i, guess) is None and ((guess + pats[i][0] + pats[i + 1][4] - 1) & -pats[i + 1][4]) == nxt:
                pos[i] = guess
                continue
            j = bisect.bisect_left(starts, nxt - exe.base) - 1
            if j < 0:
                bad = len(pats)
                break
            pos[i] = starts[j] + exe.base
            r = fits(i, pos[i])
            if r is None or r == -1 or ((pos[i] + r + pats[i + 1][4] - 1) & -pats[i + 1][4]) != nxt:
                bad = len(pats)
                break
            bad += 1
        if bad > lim:
            continue
        bases = collections.defaultdict(collections.Counter)
        for i, va in pos.items():
            rva = va - exe.base
            if fits(i, va) is None:
                for fo, extra, add, sn, sv in pats[i][3]:
                    disp = struct.unpack_from("<i", exe.img, rva + fo)[0]
                    bases[sn][va + fo + 4 + extra + disp - add - sv] += 1
        base = pos[0] - lay[0][1]
        shifts = [[i, va - base - lay[i][1]] for i, va in sorted(pos.items()) if va != base + lay[i][1]]
        # score: relocations into the obj's own data that agree with one base per section (the exe TU's data layout
        # may differ a little, so this only ranks placements)
        out.append((base, sum(c.most_common(1)[0][1] for c in bases.values()), bad, shifts))
    return out


def _block_job(job):
    path, win = job
    G["win"] = win
    out = {}
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, out
    for sec in BLOCK_SECS:
        lay = _block_layout(obj, sec)
        if lay:
            out[sec] = {"lay": [[n, off, len(d)] for n, off, d, _, _, _ in lay],
                        "cands": [list(c) for c in _block_cands(obj, lay)]}
    return path, out


def assign_blocks(res, paths, windows, j, log=print):
    """place every obj's .text$di / .text$yd block (see BLOCK_SECS); writes res[key]["bpairs"]"""
    jobs = []
    for k, c in res.items():
        if c.get("blk", {}).get("key") != c["key"] + [BLOCK_KEY] and k in paths:
            jobs.append((paths[k], unit_window(c["unit"], windows), k))
    if jobs:
        log(f"engine: block layouts of {len(jobs)} obj(s) ...")
        byp = {p: k for p, _, k in jobs}
        with Pool(max(1, j), initializer=_init) as p:
            for path, out in p.imap_unordered(_block_job, [(p_, w) for p_, w, _ in jobs], chunksize=4):
                res[byp[path]]["blk"] = {"key": res[byp[path]]["key"] + [BLOCK_KEY], "secs": out}
    # exe VAs paired exactly by a name / unique search / callee hint / copy: another TU's function, never inside a
    # block. A copy pair of a block function is not: assign_copies places those by distance to the obj's .text and
    # never checks the data they initialise, so the block placement decides them (see the end).
    blkfn = {k: {n for s in c.get("blk", {}).get("secs", {}).values() for n, _, _ in s["lay"]} for k, c in res.items()}
    fixed, ex = {}, {}
    for k, c in res.items():
        for n, va, ok, how in c["pairs"] + c.get("hpairs", []) + [x for x in c.get("xpairs", []) if x[0] not in blkfn[k]]:
            if ok:
                fixed.setdefault(va, set()).add((k, n))
                ex[(k, n)] = va
    taken = []          # sorted [(lo, hi, unit)] of placed blocks
    bp = collections.defaultdict(list)
    for sec in BLOCK_SECS:
        todo = []
        for k, c in res.items():
            s = c.get("blk", {}).get("secs", {}).get(sec)
            if not s or not s["cands"]:
                continue
            lay = s["lay"]
            # the obj's own exact pairs inside the block are anchors: a placement must keep every one of them
            anchors = [(i, ex[(k, n)]) for i, (n, off, _) in enumerate(lay) if (k, n) in ex]
            good = []
            for b, score, bad, shifts in s["cands"]:
                sh = dict(shifts)
                pos = [b + off + sh.get(i, 0) for i, (n, off, _) in enumerate(lay)]
                if any(pos[i] != va for i, va in anchors):
                    continue
                if any(v in fixed and (k, n) not in fixed[v] for (n, _, _), v in zip(lay, pos)):
                    continue
                good.append(((bad, -score), pos))
            if good:
                best = min(good)[0]
                todo.append((k, lay, sorted(g[1] for g in good if g[0] == best)))
        # fewest (best-ranked) placements first, larger blocks first; a placement never overlaps an earlier one, but
        # the stock and v2525 objs of one unit share theirs
        todo.sort(key=lambda t: (len(t[2]), -(t[1][-1][1] + t[1][-1][2]), t[0]))
        for k, lay, good in todo:
            u = res[k]["unit"]
            for pos in good:
                lo, hi = pos[0], pos[-1] + lay[-1][2]
                i = bisect.bisect_right(taken, (lo, 1 << 62)) - 1
                if i >= 0 and taken[i][:3] == (lo, hi, u):
                    pass
                elif (i >= 0 and taken[i][1] > lo) or (i + 1 < len(taken) and taken[i + 1][0] < hi):
                    continue
                else:
                    bisect.insort(taken, (lo, hi, u))
                bp[k] += [(n, v) for (n, _, _), v in zip(lay, pos)]
                break
    # verify exactly (unwind included); a placed function that differs stays a functional pair
    vjobs = [(paths[k], [([n], [v]) for n, v in prs], res[k].get("bok", {})) for k, prs in bp.items()]
    vjobs = [jb for jb in vjobs if _greedy(jb[1], jb[2]) is None]
    if vjobs:
        byp = {paths[k]: k for k in bp}
        with Pool(max(1, j), initializer=_init) as p:
            for path, xok in p.imap_unordered(_verify_job, vjobs):
                res[byp[path]]["bok"] = xok
    n_ok = 0
    for k, c in res.items():
        xok = c.get("bok", {})
        c["bpairs"] = [[n, v, bool(xok.get(f"{n}@{v:x}")), "block"] for n, v in bp.get(k, ())]
        n_ok += sum(1 for p in c["bpairs"] if p[2])
    # an exact block pair supersedes copy pairs of the same function or exe VA
    bva = {p[1] for c in res.values() for p in c["bpairs"] if p[2]}
    for k, c in res.items():
        bn = {p[0] for p in c["bpairs"] if p[2]}
        if "xpairs" in c:
            c["xpairs"] = [x for x in c["xpairs"] if x[0] not in bn and x[1] not in bva]
    log(f"engine: block pairs {sum(len(v) for v in bp.values())} ({n_ok} exact) in {len(bp)} obj(s)")


# ---------------------------------------------------------------------------------------------------------------
# sub-block pass (2026-10-22 gb13): most exe TUs carry a different header-static set than the stock objs (only 16 of
# the 48 TUs with animation-key loaders have a NiBoolKey thunk; the NiFloodgate/NiCollision/NiParticle SDM objects
# come and go; the NiPhysX classes' blocks hold only their ms_RTTI initializer), so assign_blocks' whole-layout fit
# finds no base. Here a block is laid out from an anchor (a block function whose exe VA is certain: an exact
# non-copy pair, or a thunk whose relocation resolves to a string / ms_RTTI _exe_anchors finds in the exe alone) by an
# order-preserving walk: the exe function right after (before) a placed one is the obj's next (previous) block
# function that matches it exactly (bytes, unwind, every relocation to a named symbol); obj functions the exe TU does
# not have are skipped. Byte-identical thunks of one shape (atexit registrations, kCAT copies) are thus paired k-th to
# k-th in link order. Only the TU-private statics they write go unchecked (the exe TU's data layout differs with its
# header set). A run that reaches a VA another TU pairs exactly is dropped whole (it walked past its TU).
SUB_KEY = "sub6"
SUB_PAD = 64            # most int3 padding between two functions of a block


def _sub_job(job):
    path, win, todo, own = job
    G["win"] = win
    exe = G["exe"]
    out = {}
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, out
    img, base = exe.img, exe.base

    def resolve(n, va):
        data, fields, _ = obj.function(obj.by_name[n])
        rva = va - base
        for fo, extra, add, key in _reloc_targets(obj, data, fields, True):
            yield key, va + fo + 4 + extra + struct.unpack_from("<i", img, rva + fo)[0] - add
    strong = None
    for sec, anchors in todo.items():
        lay = _block_layout(obj, sec)
        if not lay:
            continue
        pats = []
        for n, off, data, fields, leaf, al in lay:
            m = bytearray(b"\xff") * len(data)
            for f in fields:
                m[f[0]:f[0] + f[1]] = b"\0" * min(f[1], max(0, len(data) - f[0]))
            mi = int.from_bytes(bytes(m), "little")
            pats.append((len(data), mi, int.from_bytes(data, "little") & mi, al))
        memo = {}

        def fit(i, va):
            if (i, va) in memo:
                return memo[(i, va)]
            ln, mi, want, al = pats[i]
            rva = va - base
            ok = (va & (al - 1)) == 0 and _allowed(va) and not _in_game(va) and 0 < rva < len(img) - ln and \
                (rva not in exe.rf or exe.chain_end(rva) - rva == ln) and \
                int.from_bytes(bytes(img[rva:rva + ln]), "little") & mi == want and _match(obj, lay[i][0], va)
            memo[(i, va)] = ok
            return ok
        idx = {n: i for i, (n, *_) in enumerate(lay)}
        anc = {idx[n]: va for n, va in anchors.items() if n in idx}
        # anchors from the exe alone: a block function referencing a target _exe_anchors pins (class-name string,
        # ms_RTTI), found once in .text with those targets
        if strong is None:
            strong = _exe_anchors(obj, resolve)
            # (2026-10-22 gb15) and the obj's own non-COMDAT functions the unit pairs exactly outside its blocks: a
            # message-handler registration (EE_HANDLER's HandlerObjectN) loads its TU's handler method
            for si in obj.func_symbols():
                t = obj.syms[si]
                if t[0] in own and t[2] > 0 and obj.sec(t[2]).get("comdat", (0,))[0] in (0, 1):
                    strong.setdefault((t[0], t[2], t[1]), own[t[0]])
            # (2026-10-22 gb15, sub6) and the TU's own statics those exact functions address: an atexit destructor
            # of a static smart pointer (`??__F?ms_sp...`) is one of hundreds of identical release thunks, told apart
            # only by the static it releases. A key two exact functions resolve differently is dropped.
            dk = {}
            for n, va in own.items():
                if n in obj.by_name:
                    for key, tva in resolve(n, va):
                        if not obj.sec(key[1])["chars"] & 0x20:
                            dk.setdefault(key, set()).add(tva)
            for key, vs in dk.items():
                if len(vs) == 1:
                    strong.setdefault(key, vs.pop())
        for i, (n, off, data, fields, leaf, al) in enumerate(lay):
            if i in anc:
                continue
            keys = {r[3] for r in _reloc_targets(obj, data, fields, True)} & strong.keys()
            if not keys:
                continue
            pk = ("subthunk", bytes(data), tuple((f[0], f[1]) for f in fields))
            if pk not in G:
                rx, o = b"", 0
                for f in sorted(fields):
                    rx += re.escape(data[o:f[0]]) + b".{%d}" % f[1]
                    o = f[0] + f[1]
                rx += re.escape(data[o:])
                tva, tsz = G["secs"][b".text"]
                G[pk] = [base + tva + m.start() for m in re.finditer(rx, img[tva:tva + tsz], re.S)]
            good = [v for v in G[pk] if all(dict(resolve(n, v)).get(k) == strong[k] for k in keys)]
            if len(good) == 1 and fit(i, good[0]):
                anc[i] = good[0]
        runs = []
        for i0, va0 in sorted(anc.items()):
            if not fit(i0, va0) and anchors.get(lay[i0][0]) != va0:
                continue
            run = {i0: va0}
            i, va = i0, va0
            while True:                                   # forward: the next exe function is a later obj function
                nxt = va + pats[i][0]
                while nxt - (va + pats[i][0]) < SUB_PAD and img[nxt - base] == 0xCC:
                    nxt += 1
                j = next((j for j in range(i + 1, len(lay)) if fit(j, nxt)), None)
                if j is None:
                    break
                run[j] = nxt
                i, va = j, nxt
            i, va = i0, va0
            while True:                                   # backward: the exe function ending below is an earlier one
                e = va
                while va - e < SUB_PAD and img[e - 1 - base] == 0xCC:
                    e -= 1
                j = next((j for j in range(i - 1, -1, -1) if fit(j, e - pats[j][0])), None)
                if j is None:
                    break
                run[j] = e - pats[j][0]
                i, va = j, e - pats[j][0]
            runs.append(run)
        got, bad = {}, False
        for run in runs:
            for i, va in run.items():
                if got.setdefault(i, va) != va:
                    bad = True        # two anchors place one function differently: no placement
        vas = list(got.values())
        if not bad and got and len(set(vas)) == len(vas):
            out[sec] = [[lay[i][0], va] for i, va in sorted(got.items())]
    return path, out


def assign_subblocks(res, paths, windows, j, log=print):
    """place the blocks assign_blocks could not (see SUB_KEY); adds exact [name, va, True, "subblock"] to bpairs"""
    fixed = {}           # exe VA -> units that pair it exactly (not by a copy guess)
    for k, c in res.items():
        for n, va, ok, how in c["pairs"] + c.get("hpairs", []) + c.get("bpairs", []):
            if ok:
                fixed.setdefault(va, set()).add(c["unit"].lower())
    jobs = []
    for k, c in res.items():
        secs = c.get("blk", {}).get("secs", {})
        bn = {p[0] for p in c.get("bpairs", []) if p[2]}
        ex = {n: va for n, va, ok, _ in c["pairs"] + c.get("hpairs", []) + c.get("bpairs", []) if ok}
        todo = {}
        for sec, s in secs.items():
            names = [n for n, _, _ in s["lay"]]
            if names and not any(n in bn for n in names):
                todo[sec] = {n: ex[n] for n in names if n in ex}
        if not todo or k not in paths:
            continue
        blkn = {n for s in secs.values() for n, _, _ in s["lay"]}
        own = {n: va for n, va in ex.items() if n not in blkn}
        sk = c["key"] + [SUB_KEY, hashlib.sha1(json.dumps([todo, own], sort_keys=True).encode()).hexdigest()[:16]]
        if c.get("sblk", {}).get("key") != sk:
            jobs.append((paths[k], unit_window(c["unit"], windows), todo, k, sk, own))
    if jobs:
        log(f"engine: sub-block layouts of {len(jobs)} obj(s) ...")
        byp = {p: (k, sk) for p, _, _, k, sk, _ in jobs}
        with Pool(max(1, j), initializer=_init) as p:
            for path, out in p.imap_unordered(_sub_job, [(p_, w, t, o) for p_, w, t, _, _, o in jobs], chunksize=2):
                k, sk = byp[path]
                res[k]["sblk"] = {"key": sk, "secs": out}
    claims = collections.defaultdict(set)
    runs = []
    for k, c in sorted(res.items()):
        for sec, prs in c.get("sblk", {}).get("secs", {}).items():
            u = c["unit"].lower()
            if any(va in fixed and u not in fixed[va] for _, va in prs):
                continue                                  # walked into another TU's block
            runs.append((k, prs))
            for _, va in prs:
                claims[va].add(u)
    n_ok = 0
    new = collections.defaultdict(list)
    for k, prs in runs:
        own = {p[0] for p in res[k].get("bpairs", []) if p[2]}
        for n, va in prs:
            if len(claims[va]) == 1 and n not in own and va not in fixed:
                new[k].append([n, va, True, "subblock"])
                n_ok += 1
    sva = {p[1] for prs in new.values() for p in prs}
    for k, c in res.items():
        c["bpairs"] = c.get("bpairs", []) + new.get(k, [])
        sn = {p[0] for p in new.get(k, ())}
        if "xpairs" in c:
            c["xpairs"] = [x for x in c["xpairs"] if x[0] not in sn and x[1] not in sva]
    log(f"engine: sub-block pairs {n_ok} in {len(new)} obj(s) ({len(runs)} runs)")


# ---------------------------------------------------------------------------------------------------------------
# header-static equivalence rule (2026-10-22 gb15). NiAnimationKeyMacros.h's NiRegisterAnimationStream(Key) defines a
# namespace-scope `static int Keyregisterloaderreturn = Key::RegisterLoader();` in every TU that includes a key header:
# each includer emits a 20-byte .text$di initializer (sub rsp,28 / call Key::RegisterLoader / mov [rip+int],eax / add
# rsp,28 / ret) writing a TU-private int nothing reads. The exe has 980 of them in 48 TUs, interleaved with other
# libraries' initializers by LTCG, so which TU emitted a given copy is not provable (the sub-block walk mostly guesses
# k-th to k-th). The copies are interchangeable: a copy no unit pairs is credited to the header pseudo-unit
# HSTATIC_UNIT when (all of) its bytes and unwind data match an obj's ??__E<Key>registerloaderreturn@@YAXXZ exactly
# (bytematch, relocations masked), its call resolves to the exe VA a unit pairs exactly with <Key>::RegisterLoader,
# and its store target is a .bss int that no other rip-relative operand in .text references. Nothing else qualifies.
HSTATIC_UNIT = "gb:NiAnimation/NiAnimationKeyMacros"
HSTATIC_RES = "header:NiAnimationKeyMacros"
HSTATIC_RE = re.compile(r"^\?\?__E(\w+)registerloaderreturn@@YAXXZ$")
HSTATIC_SHAPE = (bytes.fromhex("4883ec28e8"), bytes.fromhex("8905"), bytes.fromhex("4883c428c3"))


def _hstatic_job(job):
    tmpl, loaders, taken = job
    exe = G["exe"]
    head, mid, tail = HSTATIC_SHAPE
    cand = {}           # exe VA -> (key, store target)
    for rva in G["bylen"].get(20, ()):
        va = rva + exe.base
        b = bytes(exe.img[rva:rva + 20])
        if va in taken or b[:5] != head or b[9:11] != mid or b[15:] != tail or _in_game(va):
            continue
        key = loaders.get(va + 9 + struct.unpack_from("<i", b, 5)[0])
        if key in tmpl:
            cand[va] = (key, va + 15 + struct.unpack_from("<i", b, 11)[0])
    # the store target: in .bss (past the raw data of its section) and referenced by one rip-relative disp32 in .text
    bss = [(exe.base + s.VirtualAddress + s.SizeOfRawData, exe.base + s.VirtualAddress + s.Misc_VirtualSize)
           for s in exe.pe.sections if s.Misc_VirtualSize > s.SizeOfRawData]
    tg = {t for _, t in cand.values() if any(lo <= t < hi for lo, hi in bss)}
    refs, at = collections.Counter(), {}
    if tg:
        lo_t, hi_t = min(tg), max(tg)
        for s in exe.pe.sections:
            if s.Name.rstrip(b"\0") != b".text":
                continue
            buf = bytes(exe.img[s.VirtualAddress:s.VirtualAddress + s.Misc_VirtualSize])
            for k in range(4):
                base = exe.base + s.VirtualAddress + k + 4
                for i, (dv,) in enumerate(struct.iter_unpack("<i", buf[k:k + (len(buf) - k) // 4 * 4])):
                    t = base + 4 * i + dv
                    if lo_t <= t <= hi_t and t in tg:
                        refs[t] += 1
                        at.setdefault(t, []).append(base + 4 * i - 4)
    # a disp32 hit outside the thunk counts only if it is the operand of a decoded rip-relative instruction of the
    # function containing it (most are byte coincidences)
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = True
    fstarts = G.get("fstarts")
    if fstarts is None:
        fstarts = G["fstarts"] = sorted((int(p[0], 16), int(p[1])) for p in
                                        (ln.split("\t") for ln in open(FUNCS)) if p[0] and p[0][0] != "#")
    for va, (key, t) in cand.items():
        if refs[t] <= 1:
            continue
        real = 0
        for q in at[t]:
            if va <= q < va + 20:
                real += 1
                continue
            i = bisect.bisect_right(fstarts, (q, 1 << 62)) - 1
            f0, fz = fstarts[i] if i >= 0 else (0, 0)
            if f0 <= q < f0 + fz:
                for ins in md.disasm(bytes(exe.img[f0 - exe.base:f0 - exe.base + fz]), f0):
                    if ins.address < q < ins.address + ins.size:
                        real += "rip" in ins.op_str and ins.address + ins.disp_offset == q
                        break
            else:
                real += 1           # outside the function map: undecidable, keep it as a reference
        refs[t] = real
    objs, out = {}, []
    for va, (key, t) in sorted(cand.items()):
        if t not in tg or refs[t] != 1:
            continue
        path, n = tmpl[key]
        if path not in objs:
            objs[path] = bm.Obj(path)
        obj = objs[path]
        if _match(obj, n, va) and sorted(bm.LAST_TARGETS.values()) == sorted([loaders_va(loaders, key), t]):
            out.append([n, va, True, "hstatic"])
    return out


def loaders_va(loaders, key):
    return next(v for v, k in loaders.items() if k == key)


def header_statics(res, paths, log=print):
    """credit the unclaimed exe copies of the NiAnimation key loader initializers (see HSTATIC_UNIT)"""
    res.pop(HSTATIC_RES, None)
    loaders, tmpl, taken = {}, {}, set()
    for k, c in sorted(res.items()):
        allp = c["pairs"] + c.get("xpairs", []) + c.get("hpairs", []) + c.get("bpairs", [])
        for n, va, ok, how in allp:
            if ok:
                taken.add(va)
                m = re.match(r"^\?RegisterLoader@(\w+)@@SAHXZ$", n)
                if m:
                    loaders[va] = m.group(1)
        for n, _, _ in c.get("blk", {}).get("secs", {}).get(".text$di", {}).get("lay", ()):
            m = HSTATIC_RE.match(n)
            if m and k in paths:
                tmpl.setdefault(m.group(1), (paths[k], n))
    if len(set(loaders.values())) != len(loaders):      # a key class whose loader two exe VAs claim: no rule
        dup = {v for v in loaders.values() if list(loaders.values()).count(v) > 1}
        loaders = {va: key for va, key in loaders.items() if key not in dup}
    with Pool(1, initializer=_init) as p:
        out = p.apply(_hstatic_job, ((tmpl, loaders, taken),))
    if out:
        res[HSTATIC_RES] = {"key": [], "unit": HSTATIC_UNIT, "recipe": "stock", "pairs": out, "xpairs": [], "cands": [], "own": []}
    log(f"engine: header-static copies {len(out)} ({len(loaders)} key loaders, {len(tmpl)} templates)")


def run(cache, j=8, filters=(), log=print):
    """Compile + match every engine unit (those whose name contains one of `filters`); returns (results, failed)."""
    t0 = time.time()
    cache = os.path.abspath(cache)     # v2525 units compile with the tree as cwd
    tree, _ = gbtree.assemble()
    units = gbtree.load_units(tree)
    if filters:
        units = [u for u in units if any(f in u["name"] or f in u["unit"] for f in filters)]
    units = [u for u in units if u["source"]]
    todo = [u for u in units if needs_compile(cache, u)]
    failed = set()
    if todo:
        log(f"engine: compiling {len(todo)} of {len(units)} Gamebryo TU(s) ...")
        with ThreadPoolExecutor(max_workers=max(1, j)) as ex:
            for u, (ok, errs, dt) in zip(todo, ex.map(compile_unit, [(cache, u) for u in todo])):
                if not ok:
                    failed.add(u["name"])
                    log(f"  FAIL {u['recipe']} {u['name']} ({dt:.1f}s)" + "".join("\n      " + e[:300] for e in errs))
    t1 = time.time()
    rpath = os.path.join(cache, "gb", "results.json")
    res = json.load(open(rpath)) if os.path.exists(rpath) else {}
    gpath = os.path.join(cache, "gb", "copygroups.json")      # copy group id -> exe VAs (see assign_copies)
    groups = json.load(open(gpath)) if os.path.exists(gpath) else {}
    jobs = []
    windows = load_windows()
    for u in units:
        o = obj_path(cache, u)
        if u["name"] in failed or not os.path.exists(o):
            res.pop(u["recipe"] + ":" + u["name"], None)
            continue
        key = [os.path.getmtime(o), os.path.getsize(o), MATCH_KEY]
        if LIB_RECIPE in o:
            key.append("lib-hint2")
        win = unit_window(u["unit"], windows)
        if win != (None, []):
            key.append(json.dumps(win))
        if os.environ.get("MS2_MERGE_INCR"):      # tools/merge.sh: also keyed by the symbol tables the match read
            import mergekey
            key.append(mergekey.engine_stamp())
        c = res.get(u["recipe"] + ":" + u["name"])
        if not c or c.get("key") != key:
            jobs.append((u, o, key, win))
    if jobs:
        log(f"engine: matching {len(jobs)} obj(s) ...")
        byobj = {o: (u, key) for u, o, key, _ in jobs}
        with Pool(max(1, j), initializer=_init) as p:
            for o, (rows, cands, own) in p.imap_unordered(_match_job, [(o, w) for _, o, _, w in jobs], chunksize=2):
                u, key = byobj[o]
                gc = []
                for n, hits in cands:                  # copy groups are shared by many objs: stored once
                    gid = hashlib.sha1(" ".join("%x" % h for h in hits).encode()).hexdigest()[:16]
                    groups.setdefault(gid, hits)
                    gc.append([n, gid])
                res[u["recipe"] + ":" + u["name"]] = {"key": key, "unit": u["unit"], "recipe": u["recipe"],
                                                       "pairs": [list(r) for r in rows], "cands": gc, "own": own}
    live = {u["recipe"] + ":" + u["name"] for u in gbtree.load_units(tree)}
    res = {k: v for k, v in res.items() if k in live}
    if not NO_CALLEE:
        t2 = time.time()
        allu = gbtree.load_units(tree)
        assign_copies(res, groups, {u["recipe"] + ":" + u["name"]: obj_path(cache, u) for u in allu}, j, log)
        lib_hints(res, {u["recipe"] + ":" + u["name"]: obj_path(cache, u) for u in allu}, windows, j, log)
        assign_blocks(res, {u["recipe"] + ":" + u["name"]: obj_path(cache, u) for u in allu}, windows, j, log)
        assign_subblocks(res, {u["recipe"] + ":" + u["name"]: obj_path(cache, u) for u in allu}, windows, j, log)
        header_statics(res, {u["recipe"] + ":" + u["name"]: obj_path(cache, u) for u in allu}, log)
        used = {g for c in res.values() for _, g in c.get("cands", ())}
        groups = {g: h for g, h in groups.items() if g in used}
        json.dump(groups, open(gpath + ".tmp", "w"))
        os.replace(gpath + ".tmp", gpath)
        log(f"engine: copy pairs {sum(len(c['xpairs']) for c in res.values())} ({time.time() - t2:.0f}s)")
    os.makedirs(os.path.dirname(rpath), exist_ok=True)
    json.dump(res, open(rpath + ".tmp", "w"))
    os.replace(rpath + ".tmp", rpath)
    log(f"engine: compile {t1 - t0:.0f}s, match {time.time() - t1:.0f}s, {len(failed)} TU(s) failed")
    return res, failed


def load_results(cache):
    rpath = os.path.join(cache, "gb", "results.json")
    return json.load(open(rpath)) if os.path.exists(rpath) else {}


def credit(res, game_rows):
    """status rows for engine functions: [(va, symbol, unit, state, size)]; game_rows: VAs already claimed by game units"""
    starts, info = [], {}
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if not p[0] or p[0].startswith("#"):
            continue
        va = int(p[0], 16)
        info[va] = (int(p[1]), p[3] if len(p) > 3 else "")
        starts.append(va)
    starts.sort()
    game = game_ranges()
    import bisect
    gs = [a for a, _ in game]

    def in_game(va):
        i = bisect.bisect_right(gs, va) - 1
        return i >= 0 and va < game[i][1]
    best = {}      # va -> (rank, symbol, unit)   rank: 3 exact v2525, 2 exact stock, 1 paired
    named = set()  # (unit, va) paired through a name table
    # a stock TU and its v2525 twin are one TU whose unit names differ in case (SchedulerLua / schedulerlua): credit
    # them under the stock name, else a stub gap between their functions is never filled
    canon = {}
    for c in sorted(res.values(), key=lambda c: c["recipe"] != "stock"):
        canon.setdefault(c["unit"].lower(), c["unit"])
    for k, c in sorted(res.items()):
        c = dict(c, unit=canon[c["unit"].lower()])
        better = {x[0] for x in c.get("xpairs", []) + c.get("bpairs", []) if x[2]}
        for sym, va, ok, how in c["pairs"] + c.get("xpairs", []) + c.get("hpairs", []) + c.get("bpairs", []):
            if not ok and sym in better:      # a non-exact table-name pair superseded by an exact copy pair
                continue
            if how == "name":
                named.add((c["unit"], va))
            if va not in info or va in game_rows or in_game(va):
                continue
            rank = (3 if c["recipe"] == "v2525" else 2) if ok else 1
            if va not in best or rank > best[va][0]:
                best[va] = (rank, sym, c["unit"])
    rows = {va: (sym, unit, "matched" if r >= 2 else "functional") for va, (r, sym, unit) in best.items()}
    # stubs: uncredited functions between two credited functions of the same unit. A credited function shorter than
    # LEAF_SMALL (ret, return a constant, an empty virtual: the linker folds such bodies across TUs) is no evidence of
    # where its TU lies: it neither bounds nor interrupts a run
    # (the header pseudo-unit's copies lie in many TUs' blocks: they bound no stub run either)
    cred = sorted(v for v in rows if info[v][0] >= LEAF_SMALL and rows[v][1] != HSTATIC_UNIT)
    for a, b in zip(cred, cred[1:]):
        if rows[a][1] != rows[b][1]:
            continue
        i = bisect.bisect_right(starts, a)
        gap = []
        while i < len(starts) and starts[i] < b:
            v = starts[i]
            if v in game_rows or in_game(v):
                gap = None
                break
            i += 1
            if v in rows:
                continue
            gap.append(v)
            if len(gap) > STUB_GAP:      # a COMDAT placed elsewhere, not the TU's own range
                gap = None
                break
        for v in gap or ():
            rows[v] = (None, rows[a][1], "stub")
    _drop_foreign_stubs(rows, starts, named)
    return [(va, sym if sym else info[va][1], unit, st, info[va][0]) for va, (sym, unit, st) in sorted(rows.items())]


FOREIGN_FAR = 0x40000


def _drop_foreign_stubs(rows, starts, named):
    """A TU's code is contiguous: a unit's credited functions linked by stub runs form components. A minor component
    (fewer credited functions than the unit's largest) far from the largest one and without a name-table pair is a
    run of byte-identical copies in another library or TU (a second Lua build, template COMDATs a game TU placed),
    so the functions between them are not this unit's stubs."""
    pos = {v: i for i, v in enumerate(starts)}
    cred = {}
    for va, (sym, unit, st) in rows.items():
        if st != "stub":
            cred.setdefault(unit, []).append(va)
    for unit, cv in cred.items():
        cv.sort()
        comps = [[cv[0]]]
        for a, b in zip(cv, cv[1:]):
            between = starts[pos[a] + 1:pos[b]] if a in pos and b in pos else [None]
            if between and all(v in rows and rows[v][1] == unit and rows[v][2] == "stub" for v in between):
                comps[-1] += between + [b]
            elif not between:
                comps[-1].append(b)
            else:
                comps.append([b])
        if len(comps) < 2:
            continue
        size = [sum(1 for v in c if rows[v][2] != "stub") for c in comps]
        big = max(size)
        lo = min(c[0] for c, n in zip(comps, size) if n == big)
        hi = max(c[-1] for c, n in zip(comps, size) if n == big)
        for c, n in zip(comps, size):
            if n == big or (c[0] < hi + FOREIGN_FAR and c[-1] > lo - FOREIGN_FAR):
                continue
            # a name-table pair only anchors the run when it is exact: a functional one is a game /Od copy of an
            # inline the engine TU emitted optimised (NiPlane::SetConstant 0x141c1bb10 for NiHalfSpaceBV)
            if any((unit, v) in named and rows[v][2] == "matched" for v in c):
                continue
            for v in c:
                if rows[v][2] == "stub":
                    del rows[v]


def summary(rows):
    """per-lib lines + totals (engine block of summary.txt)"""
    per = collections.defaultdict(lambda: collections.Counter())
    for va, sym, unit, st, size in rows:
        lib = unit[3:].split("/")[0]
        per[lib][st] += 1
        per[lib][st + "_b"] += size
        per[lib]["n"] += 1
        per[lib]["b"] += size
    out = [f"{'engine lib':<45} {'funcs':>6} {'match':>6} {'func.':>6} {'stub':>5} {'bytes':>8} {'matched':>8}  "
           f"{'exact':>6} {'impl.':>6}"]
    tot = collections.Counter()
    for lib in sorted(per, key=lambda k: -per[k]["matched"]):
        c = per[lib]
        tot.update(c)
        out.append(f"{'gb:' + lib:<45} {c['n']:6} {c['matched']:6} {c['functional']:6} {c['stub']:5} {c['b']:8} "
                   f"{c['matched_b']:8}  {100.0 * c['matched_b'] / max(1, c['b']):5.1f}% "
                   f"{100.0 * (c['matched_b'] + c['functional_b']) / max(1, c['b']):5.1f}%")
    out.append(f"{'engine total (' + str(len(per)) + ' libs)':<45} {tot['n']:6} {tot['matched']:6} {tot['functional']:6} "
               f"{tot['stub']:5} {tot['b']:8} {tot['matched_b']:8}")
    starts = {}
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if p[0] and not p[0].startswith("#"):
            starts[int(p[0], 16)] = int(p[1])
    st = {va: s for va, _, _, s, _ in rows}
    for nm, (lo, hi) in (("Gamebryo band", GB_BAND), ("Gamebryo tail", GB_TAIL)):
        vs = [v for v in starts if lo <= v < hi]
        m = sum(1 for v in vs if st.get(v) == "matched")
        f = sum(1 for v in vs if st.get(v) == "functional")
        b = sum(starts[v] for v in vs)
        bm_ = sum(starts[v] for v in vs if st.get(v) == "matched")
        out.append(f"{nm} 0x{lo:x}-0x{hi:x}: {len(vs)} functions; matched {m} ({100.0 * m / max(1, len(vs)):.2f}%), "
                   f"{100.0 * bm_ / max(1, b):.2f}% of bytes; implemented {m + f} ({100.0 * (m + f) / max(1, len(vs)):.2f}%)")
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("filters", nargs="*")
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--cache", default=os.path.join(ROOT, "build", "progress-" + (os.environ.get("MS2_AGENT") or "report")))
    ap.add_argument("--rows", help="write the status rows here (tsv)")
    a = ap.parse_args()
    import heavy_lock
    a.j = heavy_lock.clamp_jobs(a.j)
    with heavy_lock.heavy():     # no-op when a parent (progress.py, merge) already holds a slot
        res, failed = run(a.cache, a.j, a.filters)
    rows = credit(res, set())
    if a.rows:
        with open(a.rows, "w") as fo:
            fo.write("#va\tname\tunit\tstate\tsize\n")
            for va, nm, un, st, sz in rows:
                fo.write(f"{va:x}\t{nm}\t{un}\t{st}\t{sz}\n")
    print("\n".join(summary(rows)))


if __name__ == "__main__":
    main()
