#!/usr/bin/env python3
"""/ALTERNATENAME:<unresolved>=<defined> for every unresolved external whose exe VA (symbol row, or the FUN_/DAT_ VA in
its name) some obj defines under another mangling -> alias.rsp. A definition's VA: the gates' pairings
(build/progress*/results.json "pairs": obj symbol -> exe VA; the gb gates' pairs/xpairs via plan.py's gbpairs.tsv), else
its symbol row, else the VA in its name. alias-manual.tsv names the definition of VAs none of these give. Of the
definitions at a VA the alias takes the first that does not itself reference the unresolved name or another unresolved
name of that VA (the relocations of its own COMDAT section): one that does is a wrapper the gate paired with the VA of the
function it calls (e.g. `Name() { FUN_<va>(this); }`), and aliasing to it would make it call itself, directly or through
another wrapper's overload of the same FUN_ (0x140a52ef0: Unk_AvEffectRequest's ctor calls FUN_140a52ef0(void*), aliased
to Unk_WsC_SpawnCfg's ctor, which calls FUN_140a52ef0(Unk_WsC_SpawnCfg*), aliased back: a stack overflow on the first
UI sound after login). With no other definition the name is left
unresolved (a trap stub). A pair where one side is a non-static member and the other a free/static function, both
returning a class by value, gets no alias (the hidden return pointer and `this` would swap registers) but a line in
abithunks.tsv, from which shim.py emits an adapter. So does a scalar-returning free declaration of a free definition
returning cri_any (CRI vendor shim; returned through a hidden pointer): a "shift" line.
FULLEXE_FRESH set (plan.py links master's objs): the symbol tables and results.json pairings of the main tree (ROOT)
come first, the tree's fill in names only it has.
Reproducible: the same inputs (symbol tables, results.json, gbpairs/defsyms/unresolved, alias-manual.tsv) give the same
bytes (no hash or set order reaches the output; `--check` runs it twice and compares). FULLEXE_OBJ_CACHES pins the
results.json read to those caches; FULLEXE_ALIAS_CURRENT=1 drops entries whose obj no longer matches the sources."""
import collections, glob, json, os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(1, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
from common import SYMBOL_TABLES, ROOT as R, OUT as F, TREE as T, tagged, udt_return_abi, cri_any_shift  # noqa: E402
TABLES = [R, T] if os.environ.get("FULLEXE_FRESH") and os.path.realpath(R) != os.path.realpath(T) else [T]
sym2va = {}
for fn in [f"{d}/progress/{t}" for d in TABLES for t in SYMBOL_TABLES]:
    for l in open(fn, encoding="latin1"):
        p = l.rstrip("\n").split("\t")
        if l[0] != "#" and len(p) > 1:
            try: sym2va.setdefault(p[0], int(p[1], 16))
            except ValueError: pass
PH = re.compile(r"(?:FUN|LAB|DAT|PTR)_(14[0-9a-f]{7})")
SCOPE = re.compile(r"\?(?:\d|[A-P]+@)\?\?$")
def name_va(s):
    """the FUN_/DAT_ VA a name is named for: the first such identifier that is not only the enclosing function scope of
    a local (`?1??FUN_<va>@@...@`: a function-local static, or a local struct in a template argument). The Any(Buf*)
    ctor ??$?0UBuf@?1??FUN_140051d90@@YAIPEA_J@Z@@Any@@... is not 0x140051d90: aliasing the function's other manglings
    to it made the CRI demux threads run a trivial ctor and crash (fb4890a24)"""
    m = next((m for m in PH.finditer(s) if not SCOPE.search(s, 0, m.start())), None)
    return int(m.group(1), 16) if m else None
def va_of(s):
    if s in sym2va: return sym2va[s]
    return name_va(s)
# every paired VA of a symbol: a COMDAT (std/ATL template) the gates pin to several exe copies is the definition of each.
# A functional body (ok false) counts too when the source itself names the VA (how "tag" = `// @0x`, "pin" = MS2-PIN):
# without a symbols row its name has no other VA, so callers of the exe VA would stay trap stubs. Exact pairs come first.
paired = collections.defaultdict(list)
loose = collections.defaultdict(list)
# FULLEXE_ALIAS_CURRENT=1 (default unset: every entry, as before): a results.json entry counts only while its obj is the
# one it describes and current for the unit's source and headers (mtimes, headers under the tree and outside its work/).
# Every agent's cache is read, and one a gate has not re-run since a pin or declaration changed still pairs the old
# symbol with the VA (FUN_141bfad40 -> the GameObject AddTail after the pins rotated), outvoting the current pairing.
# An entry that describes the very obj the link takes (order.tsv, same mtime) counts whatever its sources did since:
# its pairs are those of the code being linked (TAG 17: a header commit between plan.py and alias.py made 21 planned
# objs' entries stale and 40 of their definitions lost their VA -> trap stubs).
CURRENT = os.environ.get("FULLEXE_ALIAS_CURRENT", "") not in ("", "0")
dropped_stale = collections.Counter()
PLANNED = set()
if CURRENT and os.path.exists(os.path.join(F, "order.tsv")):
    PLANNED = {os.path.realpath(p[3] if os.path.isabs(p[3]) else os.path.join(R, p[3]))
               for l in open(os.path.join(F, "order.tsv")) if l[0] != "#" and len(p := l.rstrip("\n").split("\t")) > 3}


def entry_current(rj, unit, r):
    tree, cache = os.path.dirname(os.path.dirname(os.path.dirname(rj))), os.path.dirname(rj)
    o = os.path.join(cache, "obj", unit[:-4] + ".obj")
    try:
        t = os.path.getmtime(o)
        deps = json.load(open(o[:-4] + ".deps")).get("deps", [])
    except (OSError, ValueError):
        return False
    if (r.get("key") or [None])[0] != t:
        return False
    if os.path.realpath(o) in PLANNED:
        return True
    if any(not f.startswith(tree + os.sep) or f.startswith(os.path.join(tree, "work") + os.sep) for f in deps):
        return False
    return all(os.path.exists(f) and os.path.getmtime(f) <= t for f in [os.path.join(tree, "src", "ms2", unit)] + deps)


# FULLEXE_OBJ_CACHES (plan.py's pin; cmake/fullexe sets it): only those caches' results.json, not every agent's under build/
RESULTS = ([os.path.join(os.path.abspath(c), "results.json") for c in os.environ["FULLEXE_OBJ_CACHES"].split(":") if c]
           if os.environ.get("FULLEXE_OBJ_CACHES") else
           [rj for d in TABLES for rj in sorted(glob.glob(f"{d}/build/progress*/results.json"))])
# cur: the pairings of current entries only (fresh evidence for aliascheck.py, which audits the picks below)
cur = collections.defaultdict(set)
for rj in [rj for rj in RESULTS if os.path.exists(rj)]:
    for unit, r in json.load(open(rj)).items():
        is_cur = entry_current(rj, unit, r)
        if CURRENT and not is_cur:
            dropped_stale[os.path.basename(os.path.dirname(rj))] += 1
            continue
        for sym, pr in ((r.get("res") or {}).get("pairs") or {}).items():
            if not pr.get("va"): continue
            if is_cur and (pr.get("ok") or pr.get("how") in ("tag", "pin")): cur[sym].add(pr["va"])
            if pr.get("ok"):
                if pr["va"] not in paired[sym]: paired[sym].append(pr["va"])
            elif pr.get("how") in ("tag", "pin") and pr["va"] not in loose[sym]: loose[sym].append(pr["va"])
if os.path.exists(f"{F}/gbpairs.tsv"):
    for l in open(f"{F}/gbpairs.tsv", encoding="latin1"):
        sym, va = l.rstrip("\n").split("\t")
        if int(va, 16) not in paired[sym]: paired[sym].append(int(va, 16))
va2def, def_obj, all_obj = {}, {}, {}
for l in open(f"{F}/defsyms.tsv", encoding="latin1"):
    s, o = l.rstrip("\n").split("\t")[:2]
    all_obj.setdefault(s, o)
    if s.startswith(("$", ".", "??_C@", "__real@", "__xmm@")): continue
    if s in def_obj: continue
    vas = paired.get(s) or ([va_of(s)] if va_of(s) is not None else [])
    vas = vas + [v for v in loose.get(s, ()) if v not in vas]
    for va in vas:
        va2def.setdefault(va, []).append(s)
    if vas: def_obj[s] = o
# a definition named for another VA (FUN_<va>) goes after the others at the VA: a pairing against another function's VA
# (a stale results.json: build/progress-coord paired UICastingBar::FUN_1418e1390 with the ctor's 0x1418e0f10, so `new
# UICastingBar` ran "stop casting" on raw heap, boot 13s) is only taken when nothing else claims the VA. Only the name's
# VA counts: re-ordering by symbol rows as well moved ~250 ICF-folded Scaleform targets (boot 21a)
for va, ds in va2def.items():
    ds.sort(key=lambda d: (m := PH.search(d)) is not None and int(m.group(1), 16) != va)
def obj_path(o):
    """defsyms.tsv's obj column: a <OUT>/obj snapshot name, asm/<obj>, or a path relative to the repo root"""
    for d in (os.path.join(F, "obj"), F, R):
        if os.path.exists(os.path.join(d, o)): return os.path.join(d, o)
undef_memo = {}
def refs(obj):
    """{defined external: the symbol names its own section's relocations reference} (objs are /Gy: a COMDAT section
    per function, so this is what that one function calls or addresses)"""
    if obj not in undef_memo:
        out = {}
        path = obj_path(obj)
        if path and os.path.exists(path):
            with open(path, "rb") as f:
                b = f.read()
            s1, s2 = struct.unpack_from("<HH", b, 0)
            if s1 == 0 and s2 == 0xFFFF:
                nsec, symoff, nsym = struct.unpack_from("<III", b, 44); sz, fmt, sec0 = 20, "<i", 56
            else:
                nsec, = struct.unpack_from("<H", b, 2); symoff, nsym, opt = struct.unpack_from("<IIH", b, 8)
                sz, fmt, sec0 = 18, "<h", 20 + opt
            strs = symoff + nsym * sz

            def name(o):
                if b[o:o + 4] == b"\0\0\0\0":
                    so = strs + struct.unpack_from("<I", b, o + 4)[0]
                    return b[so:b.index(b"\0", so)].decode("latin1")
                return b[o:o + 8].rstrip(b"\0").decode("latin1")
            defs = {}
            i = 0
            while i < nsym:
                o = symoff + i * sz
                sec, = struct.unpack_from(fmt, b, o + 12)
                if sec > 0 and b[o + sz - 2] == 2:
                    defs[name(o)] = sec
                i += 1 + b[o + sz - 1]
            sec_refs = {}
            for sec in set(defs.values()):
                h = sec0 + (sec - 1) * 40
                rp, = struct.unpack_from("<I", b, h + 24)
                nr, = struct.unpack_from("<H", b, h + 32)
                if struct.unpack_from("<I", b, h + 36)[0] & 0x01000000:      # IMAGE_SCN_LNK_NRELOC_OVFL
                    nr = struct.unpack_from("<I", b, rp)[0]
                sec_refs[sec] = {name(symoff + struct.unpack_from("<I", b, rp + 10 * k + 4)[0] * sz)
                                 for k in range(nr)}
            out = {d: sec_refs[sec] for d, sec in defs.items()}
        undef_memo[obj] = out
    return undef_memo[obj]
for l in open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "alias-manual.tsv"), encoding="latin1"):
    p = l.rstrip("\n").split("\t")
    if l[0] != "#" and len(p) > 1:
        va2def[int(p[0], 16)] = [p[1]]
FN = re.compile(r"\??(?:FUN|LAB)_(14[0-9a-f]{7})(?:@|$)")
def fn_va(r):
    """the VA of a function name: its symbols row, or its own identifier FUN_<va> (not the scope of a function-local
    static such as ?s_character@?1??FUN_140931510@@..., which the function's own section references)"""
    if r in sym2va: return sym2va[r]
    m = FN.match(r)
    return int(m.group(1), 16) if m else None
unresolved = {l.rstrip("\n").split("\t")[0] for l in open(tagged("unresolved.txt"), encoding="latin1")}
def wraps(d, s, va):
    """d's own section references s, or another unresolved function name of the same VA (aliased at this VA as well, so
    two such wrappers would call each other; a defined callee sharing the VA, XmlSplitImpl or CWnd::Default, is not)"""
    return d in def_obj and any(r == s or (r in unresolved and fn_va(r) == va) for r in refs(def_obj[d]).get(d, ()))
n = wrappers = folded = 0
pairs = []
_fold = {}
def fold_va(va):
    """the VA of a byte-identical exe copy (bytematch.same_code) of the function at va that some definition is paired
    with, else None: the exe holds several copies of a COMDAT body (std/ATL template, MS2Ptr<T>::operator=) and a gate
    pairs the definition with one of them while the game code names another (FUN_141120750 vs the copy at 141120610)"""
    if not _fold:
        import bytematch as bm
        exe = _fold["exe"] = bm.Exe(bm.EXE)
        _fold["bm"] = bm
        idx = _fold["idx"] = collections.defaultdict(list)
        for v in sorted(va2def):
            sz = bm._fn_size(exe, v)
            if sz and sz <= 0x400: idx[(sz, exe.read(v, 8))].append(v)
    exe, bm = _fold["exe"], _fold["bm"]
    sz = bm._fn_size(exe, va)
    if not sz or sz > 0x400: return None
    return next((v for v in _fold["idx"].get((sz, exe.read(va, 8)), ()) if bm.same_code(exe, va, v)), None)
for l in open(tagged("unresolved.txt"), encoding="latin1"):
    s = l.rstrip("\n").split("\t")[0]
    va = va_of(s)
    if va is not None and va not in va2def and name_va(s) == va:
        fv = fold_va(va)
        if fv is not None:
            va, folded = fv, folded + 1
    if va in va2def and s not in va2def[va]:
        # the first definition at the VA that does not itself call s (or another name of the VA)
        d = next((d for d in va2def[va] if not wraps(d, s, va)), None)
        if d is None:
            wrappers += 1
            continue
        pairs.append((s, d))
# aliascheck.py: a pick only stale caches support (no source pin, symbol row, alias-manual row, own FUN_ name, current
# gate pairing or exe-byte match with agreeing callees) while another definition at the VA has fresh evidence is
# replaced by the first such definition (FULLEXE_ALIAS_STRICT=0: only reported). Every non-ok row -> aliascheck<TAG>.tsv.
# FUN_141c18890 took Unk_WsTargetF7's RemoveKey from build/progress-cx13 & co. for days: same bytes as m_1a8's
# RemoveKey<Unk_WsObjectEntry>, but its node dtor released the entity id as a CPtred (HUD portrait AV).
import aliascheck  # noqa: E402
STRICT = os.environ.get("FULLEXE_ALIAS_STRICT", "1") != "0"
claims, manual = aliascheck.fresh_claims(cur)
def_objp = {d_: aliascheck.obj_path(o_) for d_, o_ in all_obj.items()}
rows = aliascheck.check([f'"/alternatename:{s_}={d_}"' for s_, d_ in pairs], sym2va, claims, manual, set(all_obj), def_objp)
fixed = {}
for kind, s_, d_, va, cl in rows:
    if kind == "cacheonly" or not STRICT:
        continue
    alts = [d2 for d2 in va2def.get(va, ()) if d2 != d_ and d2 != s_ and va in claims and d2 in claims[va]
            and not wraps(d2, s_, va)]
    # a freshly claimed definition whose own bytes (and callees) match the exe goes first
    alts.sort(key=lambda d2: not (def_objp.get(d2) and aliascheck.bytes_evidence(def_objp[d2], d2, va, claims, def_objp)
                                  == (True, [])))
    alt = alts[0] if alts else None
    if alt is None and manual.get(va) in def_obj:
        alt = manual[va]
    if alt is not None:
        fixed[s_] = alt
pairs = [(s_, fixed.get(s_, d_)) for s_, d_ in pairs]
with open(tagged("aliascheck.tsv"), "w") as ck:
    for kind, s_, d_, va, cl in sorted(rows, key=lambda r: (r[0], r[3], r[1])):
        ck.write(f"{kind}\t{va:x}\t{s_}\t{d_}\t{fixed.get(s_, '')}\t"
                 + "; ".join(f"{k} [{','.join(sorted(v))}]" for k, v in sorted(cl.items())) + "\n")
bad = [r for r in rows if r[0] != "cacheonly"]
if bad:
    print(f"aliascheck: {len(bad)} pick(s) without fresh evidence where another definition has it; {len(fixed)} replaced"
          f"{'' if STRICT else ' (FULLEXE_ALIAS_STRICT=0: none)'}; {sum(1 for r in bad if r[1] not in fixed)} kept -> "
          f"{tagged('aliascheck.tsv')}")
    for kind, s_, d_, va, cl in bad:
        print(f"  {kind} 0x{va:x} {s_} = {d_}" + (f"  -> {fixed[s_]}" if s_ in fixed else "  (kept)"))
# a free declaration of a member returning a class by value (or the reverse) passes the hidden return pointer and
# `this` in swapped registers: no alias, abithunks.tsv instead (shim.py: xchg rcx,rdx; jmp <definition>)
abi = udt_return_abi({x for p in pairs for x in p})
shift = cri_any_shift(pairs)
with open(tagged("alias.rsp"), "w") as out, open(tagged("abithunks.tsv"), "w") as th:
    for s, d in pairs:
        if s in abi and d in abi and abi[s] != abi[d]:
            th.write(f"{s}\t{d}\n")
            continue
        if (s, d) in shift:
            th.write(f"{s}\t{d}\tshift\n")
            continue
        out.write(f'"/alternatename:{s}={d}"\n'); n += 1
if dropped_stale:
    print("FULLEXE_ALIAS_CURRENT: skipped stale results.json entries:", ", ".join(f"{k} {v}" for k, v in sorted(dropped_stale.items())))
print(n, "aliases;", folded, "through a byte-identical exe copy;", wrappers, "dropped (every definition at the VA calls the unresolved name or another name of the VA: a "
      "wrapper the gate paired with its callee's VA);", sum(1 for s, d in pairs if s in abi and d in abi and
      abi[s] != abi[d]), "abi thunks (member vs free declaration returning a class: abithunks.tsv);", len(shift),
      "cri_any shift thunks")
if "--check" in sys.argv:
    # determinism check: a second run of this script on the same inputs must write the same bytes
    import subprocess
    outs = [tagged("alias.rsp"), tagged("abithunks.tsv")]
    first = [open(f, "rb").read() for f in outs]
    subprocess.run([sys.executable, "-P", os.path.abspath(__file__)], check=True, stdout=subprocess.DEVNULL)
    for f, b in zip(outs, first):
        if open(f, "rb").read() != b:
            sys.exit(f"--check: {os.path.basename(f)} differs between two runs on the same inputs")
    print("--check: alias.rsp and abithunks.tsv are byte-identical across two runs")
