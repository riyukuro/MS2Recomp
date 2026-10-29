"""Data units for tools/progress.py: globals the exe keeps outside every code unit (DAT_143..., g_*, class statics
of no recovered class), defined in a unit whose `// MS2-RANGE`s lie in .data/.rdata instead of .text.

A data unit has no functions, so progress.py checks its globals instead. Every external data symbol the obj defines
(string literals, __real constants, RTTI and other compiler data excluded) must
  - have a row in the symbol table (progress/symbols.tsv; hand-written ones go to progress/symbols-manual.tsv),
  - lie in one of the unit's MS2-RANGEs,
  - fit before the next exe address the symbol table knows (its size runs to the obj's next symbol, less what
    can be that symbol's alignment padding; it must not overlap a neighbouring global),
  - hold the exe's initializer: bytematch.match_data (unrelocated bytes equal, ADDR64 slots resolved against the
    exe) up to the next known exe address, a trailing zero run within the padding window left out; a .bss global
    is all zero like the exe's.
    A slot initialized with a string literal must point at the same bytes in the exe, and there at a string-pool
    literal (bytematch.string_pool_literal): the exe's pointer may land inside a data object or blob whose bytes
    merely start like a short string ("!", "1", "").
Several units declare one exe global with different types (`?DAT_143ab2820@@3HA` int, `?DAT_143ab2820@@3_JA`
__int64): the unit defines one of them and maps the others with `#pragma comment(linker, "/alternatename:A=B")`;
every such A must be bound to the same exe address as the B the obj defines.

In the hook DLL every one of these names is bound to the exe's own global (symbols table -> ms2sym.obj), so the
definitions and their pragmas sit inside `#ifndef MS2_HOOK_DLL` (docs/RECOVERY.md section 9).
"""
import ast
import bisect
import contextlib
import io
import os
import re
import struct

import bytematch as bm

SKIP_PREFIXES = ("??_C@", "__real@", "__xmm@", "__mask@", "__ymm@", "$", ".", "??_R", "__security_", "_tls_",
                 "__imp_", "_fltused")


def _exec_sections(exe):
    out = []
    for s in exe.pe.sections:
        if s.Characteristics & 0x20000000:               # IMAGE_SCN_MEM_EXECUTE
            lo = exe.base + s.VirtualAddress
            out.append((lo, lo + s.Misc_VirtualSize))
    return out


def is_data_unit(u, exe):
    """True when the unit owns at least one range and none of its ranges lies in an executable section."""
    ex = _exec_sections(exe)
    return bool(u.ranges) and not any(a < hi and lo < b for lo, hi in u.ranges for a, b in ex)


def _alternatenames(obj):
    out = []
    for s in obj.sections:
        if s["name"] != ".drectve":
            continue
        text = s["data"].decode("latin1")
        for m in re.finditer(r'/alternatename:("?)([^=\s"]+)=([^\s"]+)\1', text, re.I):
            out.append((m.group(2), m.group(3)))
    return out


def _table():
    """The loaded symbol table plus progress/symbols-manual.tsv (a report-mode gate loads only the committed
    progress/symbols.tsv, which picks the hand-written rows up at the next merge; the hook DLL link reads both)."""
    tab = dict(bm.SYMBOLS)
    p = os.path.join(bm.ROOT, "progress", "symbols-manual.tsv")
    if os.path.exists(p):
        for line in open(p):
            if line.startswith("#") or not line.strip():
                continue
            q = line.rstrip("\n").split("\t")
            tab.setdefault(q[0], int(q[1], 16))
    return tab


def check(u, obj, exe):
    """{name: {"va", "size", "ok", "report"}} for the unit's data globals and alternatename aliases."""
    out = {}
    tab = _table()
    known = sorted(set(tab.values()))
    for si, (name, value, secnum, typ, sclass) in sorted(obj.syms.items()):
        if secnum <= 0 or sclass != 2 or obj.is_code(si) or name.startswith(SKIP_PREFIXES):
            continue
        sec = obj.sec(secnum)
        if sec["name"].startswith((".debug", ".drectve", ".pdata", ".xdata")) or sec["chars"] & 0xA00:
            continue                                     # LNK_INFO / LNK_REMOVE
        va = tab.get(name)
        if va is None:
            out[name] = {"va": None, "size": None, "ok": False,
                         "report": "no symbol row (add it to progress/symbols-manual.tsv)"}
            continue
        nxt = [v for (n, v, sn, t, c) in obj.syms.values() if sn == secnum and v > value]
        size = (min(nxt) if nxt else sec["size"]) - value
        bad = []
        if not u.in_range(va):
            bad.append(f"0x{va:x} is outside the unit's MS2-RANGEs")
        i = bisect.bisect_right(known, va)
        # the obj gives no symbol sizes: `size` runs to the next symbol of the section, which the compiler orders as
        # it likes and aligns, so up to (alignment of that next symbol - 1) bytes of it can be padding
        pad = 0
        if nxt:
            nv = min(nxt)
            pad = min(16, nv & -nv if nv else 16) - 1
        if i < len(known) and va + size - pad > known[i]:
            bad.append(f"{size} bytes overlap the next known exe global at 0x{known[i]:x} "
                       f"({known[i] - va} bytes free)")
        # the padding is zero in the obj, while the exe holds its neighbour's bytes there (a `char` the compiler
        # follows with an 8-aligned global): a trailing run of zero bytes within the padding window is not compared
        limit = known[i] - va if i < len(known) else None
        if pad and not sec["chars"] & 0x80:              # not IMAGE_SCN_CNT_UNINITIALIZED_DATA
            body = sec["data"][value:value + size]
            z = 0
            while z < min(pad, len(body) - 1) and body[len(body) - 1 - z] == 0:
                z += 1
            limit = size - z if limit is None else min(limit, size - z)
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            ok = bm.match_data(obj, si, va, exe, False, quiet=True, limit=limit, strings=True)
        if not ok:
            bad.append("initializer differs: " + " ".join(l.strip() for l in buf.getvalue().splitlines()[1:])[:300])
        out[name] = {"va": va, "size": size, "ok": not bad, "report": "; ".join(bad)}
    for alias, target in _alternatenames(obj):
        va, tva = tab.get(alias), tab.get(target)
        bad = []
        if target not in out and (tva is None or tva != va):
            # an alias may also name a known exe global another TU defines (a pointer slot's target)
            bad.append(f"alternatename target {target} is neither a data global of this unit nor a known exe "
                       f"global at the alias's address")
        if va is None:
            bad.append("no symbol row (add it to progress/symbols-manual.tsv)")
        elif va != tva:
            bad.append(f"alias of {target} at 0x{tva:x}, but the symbol table binds it to 0x{va:x}"
                       if tva is not None else f"alias of {target}, which has no symbol row")
        out[alias] = {"va": va, "size": 0, "ok": not bad, "alias": target, "report": "; ".join(bad)}
    return out


# --- report mode: initialized globals of code units (python tools/datacheck.py ...) ---------------------------------
# A code unit's data is never compared with the exe: progress.py runs check() only for data units (is_data_unit), and
# a code unit's pairs are its functions. Its tables, default-value blobs and string-pointer arrays get an exe address
# only as relocation targets of matched functions (results.json "harvest") or from the symbol table, and bytematch
# masks those reloc fields, so `static const float k[] = {...}` with a wrong value still leaves every function matched.

NM_ZONE = (0x14156a020, 0x14160a7f0)
CHECKED = []          # (unit obj path, name) of every global code_unit_globals compared
PAIR_UNREF = []       # --pair: (unit, name) of non-COMDAT globals no paired function references
PAIR_CONFLICT = []    # --pair: (unit, name, [exe vas]) whose references disagree


def code_unit_globals(obj, vas, known, exe):
    """[(name, va, size, report)] for every initialized (.data/.rdata) global of obj that vas binds to an exe address
    and whose bytes or pointer slots differ from the exe's (bytematch.match_data with strings=True, sized as check())."""
    out = []
    for si, (name, value, secnum, typ, sclass) in sorted(obj.syms.items()):
        if secnum <= 0 or sclass not in (2, 3) or obj.is_code(si) or name.startswith(SKIP_PREFIXES + ("??_7", "??_8")):
            continue
        sec = obj.sec(secnum)
        if not sec["name"].startswith((".data", ".rdata")) or sec["chars"] & 0xA80:   # LNK_INFO/REMOVE, .bss
            continue
        va = vas.get(name)
        if va is None:
            continue
        nxt = [v for (n, v, sn, t, c) in obj.syms.values() if sn == secnum and v > value]
        size = (min(nxt) if nxt else sec["size"]) - value
        i = bisect.bisect_right(known, va)
        limit = known[i] - va if i < len(known) else None
        if nxt:
            nv = min(nxt)
            pad = min(16, nv & -nv if nv else 16) - 1
            body = sec["data"][value:value + size]
            z = 0
            while z < min(pad, len(body) - 1) and body[len(body) - 1 - z] == 0:
                z += 1
            limit = size - z if limit is None else min(limit, size - z)
        buf = io.StringIO()
        CHECKED.append(name)
        with contextlib.redirect_stdout(buf):
            ok = bm.match_data(obj, si, va, exe, False, quiet=True, limit=limit, strings=True)
        if not ok:
            rep = " ".join(l.strip() for l in buf.getvalue().splitlines()[1:])
            why = ulp_only(obj, secnum, value, limit if limit is not None else size, va, exe) \
                if re.fullmatch(r"MISMATCH \d+ unrelocated byte\(s\) differ", rep) else ""
            out.append((name, va, size, rep, why))
    return out


def ulp_only(obj, secnum, value, size, va, exe):
    """'ulp' when every differing unrelocated byte lies in an aligned dword whose two values, read as float, are at
    most 4 ulp apart (the litcheck rule for 0.785398185 vs 0.785398006 spellings)."""
    sec = obj.sec(secnum)
    ours = sec["data"][value:value + size]
    size = len(ours)
    xb = exe.read(va, size)
    relocated = set()
    for rva, _, ty in sec["relocs"]:
        relocated.update(range(rva - value, rva - value + bm.RELOC_LEN.get(ty, 4)))
    words = {k - (va + k) % 4 for k in range(size) if k not in relocated and ours[k] != xb[k]}
    for w in words:
        if w < 0 or w + 4 > size:
            return ""
        a, b = (int.from_bytes(x[w:w + 4], "little", signed=True) for x in (ours, xb))
        if abs(a - b) > 4 or not (a >> 23) & 0xff:      # a float with an exponent, not a small int
            return ""
    return "ulp"


_NAMED_VA = re.compile(r"\?(?:DAT|s|g)_(14[0-9a-f]{7})(?![0-9a-f])")


def _exe_section(exe, va):
    rva = va - exe.base
    for sh in exe.pe.sections:
        if sh.VirtualAddress <= rva < sh.VirtualAddress + max(sh.Misc_VirtualSize, sh.SizeOfRawData):
            return sh.Name.rstrip(b"\0").decode("latin1")
    return ""


def pair_through_code(obj, pairs, exe, wanted):
    """{name: {exe va}} for the globals in wanted, read off the exe side of every paired function that references
    them: the exe function holds its reference at the same reloc offset. A byte-matched pair (ok) is read as is; a
    mismatched one only where the 3 bytes in front of the field (REX/opcode/ModRM) are the same in both, so the
    instruction at that offset is the same one. REL32_k targets lose their addend like bytematch's harvest."""
    found = {}
    for fname, p in pairs.items():
        si = obj.by_name.get(fname)
        if si is None or obj.syms[si][2] <= 0 or not obj.is_code(si):
            continue
        try:
            data, fields, _ = obj.function(si)
        except Exception:                               # noqa: BLE001
            continue
        hit = [f for f in fields if f[2] in wanted]
        if not hit:
            continue
        xb = exe.read(p["va"], len(data))
        for off, ln, tname, ty, inner, rsi in hit:
            if not p.get("ok") and (off < 3 or data[off - 3:off] != xb[off - 3:off]):
                continue
            if bm.REL_REL32 <= ty <= bm.REL_REL32 + 5 and off + 4 <= len(data):
                add = struct.unpack_from("<i", data, off)[0]
                tgt = p["va"] + off + 4 + (ty - bm.REL_REL32) + struct.unpack_from("<i", xb, off)[0] - add
            elif ty == bm.REL_ADDR64 and off + 8 <= len(data):
                tgt = struct.unpack_from("<Q", xb, off)[0] - struct.unpack_from("<q", data, off)[0]
            else:
                continue
            found.setdefault(tname, set()).add(tgt)
    return found


_POOLED = re.compile(r"\[\+0x[0-9a-f]+\] string literal (b'.*?'|b\".*?\"): the exe slot points at (0x[0-9a-f]+) [0-9a-f]+, not a string-pool literal")


_DYNINIT = re.compile(r"\[\+0x[0-9a-f]+\] \?\?_7\S+ is paired with 0x[0-9a-f]+, exe slot holds 0x0\b")


def benign(rep, exe):
    """'dynamic-init' when every mismatch is a vftable slot the exe image leaves 0 (a guarded local static the exe
    constructs on first use); 'pooled-literal' when every mismatch is a string slot whose exe target holds the same text inside a merged
    string blob (the linker pooled the literal with a longer neighbour, so it is not at a ??_C@ boundary)."""
    dyn = _DYNINIT.findall(rep)
    if dyn and len(dyn) == rep.count("[+0x") and "differ" not in rep:
        return "dynamic-init"       # the exe constructs the object at run time (its image slot is 0); ours is constant-initialized
    hits = list(_POOLED.finditer(rep))
    if not hits or len(hits) != rep.count("[+0x") or "differ" in rep:
        return ""
    for m in hits:
        lit = ast.literal_eval(m.group(1))
        if exe.read(int(m.group(2), 16), len(lit)) != lit:
            return ""
    return "pooled-literal"


def main():
    import argparse
    import json
    import sys
    ap = argparse.ArgumentParser(description="Report initialized globals of code units whose bytes differ from the "
                                             "exe's (report only; progress.py counts are not touched).")
    ap.add_argument("filters", nargs="*", help="unit substrings")
    agent = os.environ.get("MS2_AGENT")
    ap.add_argument("--dir", default=os.path.join("build", f"progress-{agent}" if agent else "progress"))
    ap.add_argument("--results", help="results.json to read (default DIR/results.json)")
    ap.add_argument("--out", help="write the TSV here (default stdout)")
    ap.add_argument("--pair", action="store_true", help="also pair globals with no exe VA through the paired functions "
                    "that reference them, and check pointer slots against the unit's pairs")
    a = ap.parse_args()
    res = json.load(open(a.results or os.path.join(a.dir, "results.json")))
    exe = bm.Exe(bm.EXE)
    bm.load_symbols()
    tab = _table()
    harvest = {}
    for ent in res.values():
        for k, v in ((ent.get("res") or {}).get("harvest") or {}).items():
            harvest.setdefault(k, v)
    known = sorted(set(tab.values()) | set(harvest.values()))
    rows, nunit, nglob = [], 0, 0
    pstat = {"by-name": 0, "paired": 0, "conflict": 0, "noref-comdat": 0, "noref": 0, "data-section": 0}
    for rel, ent in sorted(res.items()):
        if a.filters and not any(f in rel for f in a.filters):
            continue
        r = ent.get("res")
        if ent.get("failed") or not r or r.get("data") is not None:
            continue                                     # data units: progress.py checks them already
        path = os.path.join(a.dir, "obj", rel[:-4] + ".obj")
        if not os.path.exists(path):
            continue
        vas = dict(tab)
        vas.update(r.get("harvest") or {})                # the unit's own references win (file statics)
        vas = {k: v for k, v in vas.items() if not NM_ZONE[0] <= v < NM_ZONE[1]}
        obj = bm.Obj(path)
        bm.HARVEST.clear()
        bm.LOCAL_KNOWN.clear()
        nunit += 1
        ukn = known
        if a.pair:
            unbound = {}
            for si, (name, value, secnum, typ, sclass) in obj.syms.items():
                if secnum <= 0 or sclass not in (2, 3) or obj.is_code(si) or name in vas \
                        or name.startswith(SKIP_PREFIXES + ("??_7", "??_8")):
                    continue
                sec = obj.sec(secnum)
                if sec["name"].startswith((".data", ".rdata")) and not sec["chars"] & 0xA80:
                    unbound[name] = bool(sec["chars"] & 0x1000)
            found = pair_through_code(obj, r.get("pairs") or {}, exe, unbound)
            for name, comdat in unbound.items():
                tg = found.get(name)
                m = _NAMED_VA.match(name)
                if not tg and m and not comdat:
                    tg = {int(m.group(1), 16)}          # unreferenced, but the name gives its exe address
                    pstat["by-name"] += 1
                if not tg:
                    pstat["noref-comdat" if comdat else "noref"] += 1
                    if not comdat and len(PAIR_UNREF) < 100000:
                        PAIR_UNREF.append((rel, name))
                elif len(tg) > 1:
                    pstat["conflict"] += 1
                    PAIR_CONFLICT.append((rel, name, sorted(tg)))
                else:
                    t = next(iter(tg))
                    if NM_ZONE[0] <= t < NM_ZONE[1] or _exe_section(exe, t) not in (".data", ".rdata"):
                        pstat["data-section"] += 1      # a target outside the exe's data: not this global's home
                        continue
                    vas[name] = t
                    pstat["paired"] += 1
            ukn = sorted(set(known) | set(vas.values()))
            bm.LOCAL_KNOWN.update(vas)                  # pointer slots must land on the unit's paired targets
        try:
            hits = code_unit_globals(obj, vas, ukn, exe)
        except Exception as e:                           # noqa: BLE001
            print(f"datacheck: {rel}: {e}", file=sys.stderr)
            continue
        for name, va, size, rep, why in hits:
            nglob += 1
            rows.append(f"{va:x}\t{rel}\t{name}\t{size}\t{rep[:400]}\t{why or benign(rep, exe)}")
    fo = open(a.out, "w") if a.out else sys.stdout
    print("#va\tunit\tsymbol\tsize\treport\tbenign", file=fo)
    for row in rows:
        print(row, file=fo)
    if a.pair:
        print("datacheck --pair: " + ", ".join(f"{k} {v}" for k, v in pstat.items()), file=sys.stderr)
        for u, n, t in PAIR_CONFLICT:
            print(f"datacheck: conflict {u} {n} " + " ".join(f"0x{x:x}" for x in t), file=sys.stderr)
    print(f"datacheck: {nunit} code units, {len(CHECKED)} initialized globals bound to the exe checked, {nglob} of them differ from the exe", file=sys.stderr)


if __name__ == "__main__":
    main()
