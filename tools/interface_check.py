#!/usr/bin/env python3
"""Exact-interface rule for done-functional units (docs/RECOVERY.md "Exact interface", fx12 2026-10-20).

Function BODIES may stay functional, but what a unit exports to other units must be byte-exact. A non-exact function of
the unit is part of its SHARED INTERFACE when
  ext     another unit's committed .obj has its mangled name as an undefined external (it calls/binds it), or
  class   it is a ctor/dtor/operator=/??_G/??_E or a virtual of a class defined in a shared header (placeholder/,
          commonfiles/, or any header another unit includes), or
  comdat  it is a selectany COMDAT (template instantiation / inline) that other units' objs also emit.
Such a function must be byte-exact, or carry a written reason: an `// MS2-FUNCTIONAL: <reason>` comment at the function
(within 4 lines above its `// @0xVA` tag up to its opening brace, or on/after the line of its `// MS2-PIN`), an explicit
`// MS2-FUNCTIONAL <mangled-or-0xVA>: <reason>` line anywhere in the unit's .cpp/own headers, or a row in
progress/interface-allow.tsv (unit<TAB>mangled-or-0xVA<TAB>reason).
Codegen-only diffs are ignored (reported as info): same callee multiset (direct calls/tail jumps/IAT calls, resolved to
exe VAs through symbols.tsv) and the same unwind frame (allocation + saved registers) as the exe function.

    .venv/bin/python tools/interface_check.py [--results build/progress-AGENT/results.json] [--all] [-v] UNIT-SUBSTR...
    .venv/bin/python tools/interface_check.py --measure UNIT-SUBSTR...      (committed merge state, one line per unit)

Without --results it reads build/progress-$MS2_AGENT/results.json (fresh after unit-check / progress.py --agent), else
the merge tree's results. Dependents come from the merge tree's objs (work/merge-wt/build/progress/obj = the committed
state; falls back to build/progress/obj). Exit 1 when a violation is found, unless MS2_INTERFACE_WARN=1.
progress.py --functional --check calls check_unit() for units that are not yet done/done-functional in queue.tsv
(already-done units only get the list as a warning; their violators are in work/coord/fixups-pending.md).
"""
import argparse
import collections
import json
import os
import pickle
import re
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ms2paths  # noqa: E402

ROOT = ms2paths.ROOT
GAME = os.path.join(ROOT, "src", "ms2")
MERGE_TREE = os.path.join(ROOT, "work", "merge-wt")
ALLOW = os.path.join(ROOT, "progress", "interface-allow.tsv")
INDEX = os.path.join(ROOT, "build", "interface-index.pkl")
SHARED_DIRS = ("placeholder/", "commonfiles/")
SPECIAL = ("??0", "??1", "??4", "??_G", "??_E")
WEAK_REASON = re.compile(r"^\W*(?:todo|wip|tbd|functional|not\s+(?:byte[- ]?)?exact(?:\s+yet)?)\W*$", re.I)


def corpus_dir():
    for d in (os.path.join(MERGE_TREE, "build", "progress"), os.path.join(ROOT, "build", "progress")):
        if os.path.isdir(os.path.join(d, "obj")):
            return d
    return None


# ----------------------------------------------------------------------------------------------------------------
# corpus index: per committed unit obj, undefined externals and selectany code COMDATs; per header, including units

def _obj_symbols(path):
    d = open(path, "rb").read()
    if d[:4] == b"\0\0\xff\xff":
        nsec, = struct.unpack_from("<I", d, 44)
        symoff, nsyms = struct.unpack_from("<II", d, 48)
        sechdr, recsz, sfmt = 56, 20, "<i"
    else:
        nsec, = struct.unpack_from("<H", d, 2)
        symoff, nsyms = struct.unpack_from("<II", d, 8)
        sechdr, recsz, sfmt = 20 + struct.unpack_from("<H", d, 16)[0], 18, "<h"
    chars = [struct.unpack_from("<I", d, sechdr + 40 * i + 36)[0] for i in range(nsec)]
    sel = {}
    stroff = symoff + nsyms * recsz
    undef, comdat = set(), set()
    i = 0
    pending = []
    while i < nsyms:
        o = symoff + i * recsz
        nm = d[o:o + 8]
        value, = struct.unpack_from("<I", d, o + 8)
        secnum, = struct.unpack_from(sfmt, d, o + 12)
        sclass, naux = d[o + recsz - 2], d[o + recsz - 1]
        if sclass == 3 and naux and value == 0 and 0 < secnum <= nsec:
            num, s = struct.unpack_from("<HB", d, o + recsz + 12)
            if sfmt == "<i":
                num |= struct.unpack_from("<H", d, o + recsz + 16)[0] << 16
            sel.setdefault(secnum, (s, num))
        if sclass == 2:
            if nm[:4] == b"\0\0\0\0":
                so = stroff + struct.unpack_from("<I", nm, 4)[0]
                nm = d[so:d.index(b"\0", so)]
            else:
                nm = nm.rstrip(b"\0")
            name = nm.decode("latin1")
            if secnum == 0 and value == 0:
                undef.add(name)
            elif 0 < secnum <= nsec and chars[secnum - 1] & 0x20 and chars[secnum - 1] & 0x1000:
                pending.append((name, secnum))
        i += 1 + naux
    for name, sn in pending:
        s, num = sel.get(sn, (0, 0))
        for _ in range(8):
            if s != 5 or not num:
                break
            s, num = sel.get(num, (0, 0))
        if s != 1:                       # not NODUPLICATES: inline / template copy
            comdat.add(name)
    return undef, comdat


def load_index(cdir):
    try:
        idx = pickle.load(open(INDEX, "rb"))
    except Exception:
        idx = {}
    if idx.get("_dir") != cdir:
        idx = {"_dir": cdir}
    objdir = os.path.join(cdir, "obj")
    seen = set()
    changed = False
    for d, _, files in os.walk(objdir):
        for f in files:
            if not f.endswith(".obj"):
                continue
            p = os.path.join(d, f)
            rel = os.path.relpath(p, objdir)[:-4] + ".cpp"
            seen.add(rel)
            st = os.stat(p)
            key = (st.st_mtime, st.st_size)
            e = idx.get(rel)
            if e and e["key"] == key:
                continue
            try:
                undef, comdat = _obj_symbols(p)
            except Exception:
                continue
            hdrs = []
            try:
                hdrs = [os.path.relpath(h, GAME) for h in json.load(open(p[:-4] + ".deps")).get("deps", [])
                        if h.startswith(GAME + os.sep)]
            except Exception:
                pass
            idx[rel] = dict(key=key, undef=undef, comdat=comdat, hdrs=hdrs)
            changed = True
    for rel in [k for k in idx if k != "_dir" and k not in seen]:
        del idx[rel]
        changed = True
    if changed:
        os.makedirs(os.path.dirname(INDEX), exist_ok=True)
        tmp = INDEX + f".tmp{os.getpid()}"
        pickle.dump(idx, open(tmp, "wb"))
        os.replace(tmp, INDEX)
    undef_by, comdat_by, hdr_users = collections.defaultdict(set), collections.defaultdict(set), collections.defaultdict(set)
    for rel, e in idx.items():
        if rel == "_dir":
            continue
        for n in e["undef"]:
            undef_by[n].add(rel)
        for n in e["comdat"]:
            comdat_by[n].add(rel)
        for h in e["hdrs"]:
            hdr_users[h].add(rel)
    return undef_by, comdat_by, hdr_users


_CLASSDEF = None


def class_headers():
    """simple class name -> [header rel to src/ms2] that define it (`class|struct X ... {`)"""
    global _CLASSDEF
    if _CLASSDEF is None:
        _CLASSDEF = collections.defaultdict(list)
        rx = re.compile(r"^\s*(?:template\s*<[^>]*>\s*)?(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?(\w+)\s*(?:final\s*)?(?::[^;{]*)?\{",
                        re.M)
        for d, _, files in os.walk(GAME):
            for f in files:
                if f.endswith((".h", ".hpp", ".inl")):
                    p = os.path.join(d, f)
                    for m in rx.finditer(open(p, encoding="latin1").read()):
                        _CLASSDEF[m.group(1)].append(os.path.relpath(p, GAME))
    return _CLASSDEF


def demangle_all(names):
    names = list(names)
    if not names:
        return {}
    try:
        out = subprocess.run(["llvm-undname"], input="\n".join(names) + "\n", capture_output=True, text=True).stdout
    except OSError:
        return {n: n for n in names}
    res, cur = {}, None
    lines = [l for l in out.splitlines()]
    # llvm-undname echoes each input line, then the demangled form, then a blank line
    i = 0
    for n in names:
        while i < len(lines) and lines[i].strip() != n:
            i += 1
        res[n] = lines[i + 1].strip() if i + 1 < len(lines) else n
        i += 2
    return res


def class_of(dem):
    """'public: virtual void __cdecl ns::C<int>::F(int)' -> ('ns::C<int>', 'C', virtual?)"""
    s = re.sub(r"^(?:public|protected|private): ", "", dem)
    virt = s.startswith("virtual ")
    head = s.split("(")[0]
    head = head.split(" __cdecl ")[-1]
    depth, cut = 0, -1
    for k, ch in enumerate(head):
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        elif ch == ":" and depth == 0 and head[k:k + 2] == "::":
            cut = k
    if cut < 0:
        return None, None, virt
    cls = head[:cut]
    simple = re.sub(r"<.*$", "", cls.split("::")[-1] if "<" not in cls else cls[:cls.index("<")].split("::")[-1])
    return cls, simple, virt


# ----------------------------------------------------------------------------------------------------------------
# reasons

def own_headers(path):
    d = os.path.dirname(path)
    stem = os.path.splitext(os.path.basename(path))[0]
    out = []
    for m in re.finditer(r'^\s*#\s*include\s+"([^"/]+\.h)"', open(path, encoding="latin1").read(), re.M):
        q = os.path.join(d, m.group(1))
        if os.path.exists(q) and os.path.splitext(m.group(1))[0].split("_")[0] == stem.split("_")[0]:
            out.append(q)
    return out


def reasons(path, unit_name):
    """{va(int) or mangled name: reason} from the unit's sources and progress/interface-allow.tsv"""
    out = {}
    for f in [path] + own_headers(path):
        lines = open(f, encoding="latin1").read().split("\n")
        for i, l in enumerate(lines):
            m = re.match(r"\s*//\s*MS2-FUNCTIONAL\s+(0x[0-9a-fA-F]+|\?\S+)\s*:\s*(.*)", l)
            if m:
                k = m.group(1)
                out[int(k, 16) if k.startswith("0x") else k] = m.group(2).strip() or "(no text)"
                continue
            m = re.match(r"\s*//\s*@0x([0-9a-fA-F]+)\s*$", l)
            if m:
                va = int(m.group(1), 16)
                rng = []
                for j in range(i - 1, max(-1, i - 5), -1):     # comment block right above the tag
                    if not lines[j].strip().startswith("//"):
                        break
                    rng.append(j)
                for j in range(i + 1, min(len(lines), i + 16)):  # up to the body's opening brace
                    rng.append(j)
                    if "{" in lines[j] or lines[j].rstrip().endswith(";"):
                        break
                for j in sorted(rng):
                    r = re.search(r"//\s*MS2-FUNCTIONAL\b:?\s*(.*)", lines[j])
                    if r:
                        out.setdefault(va, r.group(1).strip() or "(no text)")
                        break
            m = re.match(r"\s*//\s*MS2-PIN:\s*(\S+)\s+0x[0-9a-fA-F]+(.*)", l)
            if m:
                for t in (m.group(2), lines[i + 1] if i + 1 < len(lines) else ""):
                    r = re.search(r"MS2-FUNCTIONAL\b:?\s*(.*)", t)
                    if r:
                        out.setdefault(m.group(1), r.group(1).strip() or "(no text)")
                        break
    if os.path.exists(ALLOW):
        for l in open(ALLOW, encoding="utf-8"):
            p = l.rstrip("\n").split("\t")
            if l.startswith("#") or len(p) < 3 or p[0] != unit_name:
                continue
            out[int(p[1], 16) if p[1].startswith("0x") else p[1]] = "allowlist: " + p[2]
    return out


# ----------------------------------------------------------------------------------------------------------------
# codegen-only classification

_BM = {}


def _bm(exe=None):
    if not _BM:
        import bytematch as bm
        _BM["bm"] = bm
        _BM["exe"] = exe or bm.Exe(bm.EXE)
        sym = {}
        for line in open(bm.SYMBOLS_TSV, encoding="latin1"):
            p = line.rstrip("\n").split("\t")
            if len(p) >= 2 and not line.startswith("#"):
                try:
                    sym[p[0]] = int(p[1], 16)
                except ValueError:
                    pass
        _BM["sym"] = sym
        _BM["inv_imp"] = {}
    return _BM


FRAME_LOOSE = not os.environ.get("MS2_INTERFACE_FRAME_STRICT")   # locals-size-only frame diffs count as codegen
FUN_RE = re.compile(r"FUN_([0-9a-fA-F]{9})(?![0-9a-zA-Z])")


def _unwind_shape(buf, off):
    b0, _, ncodes, fr = struct.unpack_from("<BBBB", buf, off)
    codes = buf[off + 4:off + 4 + 2 * ncodes]
    shape, k = [b0 >> 3 & 3, fr], 0
    nslots = {0: 1, 2: 1, 3: 1, 4: 2, 5: 3, 8: 2, 9: 3, 10: 1}
    while k < ncodes:
        op, info = codes[2 * k + 1] & 15, codes[2 * k + 1] >> 4
        n = (2 if info == 0 else 3) if op == 1 else nslots.get(op, 1)
        shape.append((op, info, bytes(codes[2 * k + 2:2 * (k + n)])))
        k += n
    return shape


def codegen_only(obj, name, va, local):
    """(True, why) when the obj function and the exe function at va have the same callees and the same frame"""
    B = _bm()
    bm, exe = B["bm"], B["exe"]
    si = obj.by_name.get(name)
    if si is None or obj.syms[si][2] <= 0:
        return False, "not in obj"
    data, fields, unw = obj.function(si)
    rva = va - exe.base
    size = bm._fn_size(exe, va)
    if not size:
        return False, "no exe size"
    end = rva + size
    xunw = exe.rf[rva][1] if rva in exe.rf else None
    # frame (a leaf without .pdata on both sides has none)
    if (unw is None) != (xunw is None):
        return False, "frame differs (leaf vs non-leaf)"
    frame_note = ""
    if unw is not None:
        try:
            os_, xs = _unwind_shape(obj.sec(unw[0])["data"], unw[1]), _unwind_shape(exe.img, xunw)
        except (struct.error, IndexError):
            return False, "unwind unreadable"
        if os_ != xs:
            # same saved registers / frame register, only the local area size differs: temporaries (codegen)
            regs = lambda sh: [c for c in sh[2:] if c[0] not in (1, 2)] + sh[:2]
            if not FRAME_LOOSE or regs(os_) != regs(xs):
                return False, "frame differs"
            frame_note = ", locals size differs"
    # callees
    oc, unres = [], 0
    for off, ln, tname, ty, inner, tsi in fields:
        if ty != 4:
            continue
        if off >= 1 and data[off - 1] in (0xE8, 0xE9):
            m = FUN_RE.search(tname)
            v = int(m.group(1), 16) if m else local.get(tname, B["sym"].get(tname))
            if v is None:
                unres += 1
            else:
                oc.append(v)
        elif off >= 2 and data[off - 2:off] == b"\xff\x15":
            oc.append("imp:" + tname[6:] if tname.startswith("__imp_") else tname)
    xc = []
    md = bm.capstone.Cs(bm.capstone.CS_ARCH_X86, bm.capstone.CS_MODE_64)
    for ins in md.disasm(bytes(exe.img[rva:end]), va):
        if ins.mnemonic in ("call", "jmp"):
            op = ins.op_str
            if re.fullmatch(r"0x[0-9a-f]+", op):
                t = int(op, 16)
                if not va <= t < exe.base + end:
                    xc.append(t)
            elif ins.mnemonic == "call" and op.startswith("qword ptr [rip"):
                m = re.search(r"rip ([+-]) 0x([0-9a-f]+)", op)
                if m:
                    a = ins.address + ins.size + (int(m.group(2), 16) * (1 if m.group(1) == "+" else -1))
                    xc.append("imp:" + exe.imp.get(a, hex(a)))
    if len(oc) + unres != len(xc):
        return False, f"callee count {len(oc) + unres} vs exe {len(xc)}"
    left = collections.Counter(oc) - collections.Counter(xc)
    extra = list((collections.Counter(xc) - collections.Counter(oc)).elements())
    for v in list(left.elements()):         # a byte-identical copy at another VA (ICF look-alike) is the same callee
        if not isinstance(v, int):
            continue
        hit = next((x for x in extra if isinstance(x, int) and bm.same_code(exe, v, x)), None)
        if hit is not None:
            extra.remove(hit)
            left[v] -= 1
    left = +left
    if left:
        if all(isinstance(x, str) for x in left):
            # IAT names: compare by count only (ordinal-imported names may print differently)
            if sum(1 for x in xc if isinstance(x, str)) == sum(1 for x in oc if isinstance(x, str)) and \
                    not (collections.Counter(x for x in oc if not isinstance(x, str)) -
                         collections.Counter(x for x in xc if not isinstance(x, str))):
                return True, "same callees + frame" + frame_note
        return False, "callees differ: " + ", ".join(hex(x) if isinstance(x, int) else x for x in list(left)[:3])
    return True, "same callees + frame" + frame_note + (f" ({unres} unresolved)" if unres else "")


# ----------------------------------------------------------------------------------------------------------------

def check_unit(rel, unit_name, res, obj_path, cache=None, exe=None):
    """[(row dict)] for the unit's non-exact functions on its shared interface. row: name, va, olen, xlen, kinds,
    deps, reason (None = missing), cg (codegen-only verdict text or None), violation (bool)"""
    cache = cache if cache is not None else {}
    if "idx" not in cache:
        cd = corpus_dir()
        cache["idx"] = load_index(cd) if cd else ({}, {}, {})
    undef_by, comdat_by, hdr_users = cache["idx"]
    # auto-guess pairs are byte-identical look-alikes (only the owner of a folded copy is a guess): not a diff
    bad = {n: p for n, p in (res.get("pairs") or {}).items() if not p.get("ok") and p.get("how") != "auto-guess"}
    if not bad:
        return []
    path = os.path.join(GAME, rel)
    own_h = {os.path.relpath(h, GAME) for h in own_headers(path)}
    dem = demangle_all(n for n in bad if n.startswith(SPECIAL) or re.search(r"@@[UME]E", n) or n.startswith("?"))
    chdr = class_headers()
    rows = []
    for name, p in sorted(bad.items(), key=lambda kv: kv[1]["va"]):
        kinds, deps = [], set()
        u = {x for x in undef_by.get(name, ()) if x != rel}
        if u:
            kinds.append("ext")
            deps |= u
        c = {x for x in comdat_by.get(name, ()) if x != rel}
        if c:
            kinds.append("comdat")
            deps |= c
        d = dem.get(name, "")
        if d:
            cls, simple, virt = class_of(d)
            special = name.startswith(SPECIAL) or "operator=" in d
            if cls and (special or virt):
                for h in chdr.get(simple, ()):
                    users = {x for x in hdr_users.get(h, ()) if x != rel}
                    if h.startswith(SHARED_DIRS) or users or h not in own_h and not h.startswith(
                            os.path.splitext(rel)[0].split("_")[0]):
                        kinds.append("class")
                        deps |= users
                        break
        if not kinds:
            continue
        rows.append(dict(name=name, va=p["va"], kinds=kinds, deps=sorted(deps), report=p.get("report", "")))
    if not rows:
        return []
    rs = reasons(path, unit_name)
    obj = None
    try:
        B = _bm(exe)
        obj = B["bm"].Obj(obj_path) if obj_path and os.path.exists(obj_path) else None
    except Exception:
        obj = None
    local = dict(res.get("harvest") or {})
    local.update({n: p["va"] for n, p in (res.get("pairs") or {}).items()})
    for r in rows:
        r["reason"] = rs.get(r["va"]) or rs.get(r["name"])
        r["weak"] = bool(r["reason"]) and bool(WEAK_REASON.match(r["reason"]))
        olen = xlen = None
        if obj:
            si = obj.by_name.get(r["name"])
            if si is not None and obj.syms[si][2] > 0:
                olen = len(obj.function(si)[0])
            xlen = _BM["bm"]._fn_size(_BM["exe"], r["va"])
        r["olen"], r["xlen"] = olen, xlen
        r["cg"] = None
        if obj:
            try:
                ok, why = codegen_only(obj, r["name"], r["va"], local)
            except Exception as ex:          # never let the classifier break a gate
                ok, why = False, f"classifier error {ex.__class__.__name__}"
            r["cg"] = why
            r["cg_ok"] = ok
        else:
            r["cg_ok"] = False
        r["violation"] = not r["reason"] and not r["cg_ok"]
    return rows


def fmt_row(r, nd=4):
    deps = ", ".join(os.path.splitext(x)[0] for x in r["deps"][:nd]) + (f" +{len(r['deps']) - nd}" if len(r["deps"]) > nd else "")
    st = ("reason: " + r["reason"][:60]) if r["reason"] else ("codegen-only" if r["cg_ok"] else "NO REASON")
    return (f"{r['name']}  @0x{r['va']:x}  obj/exe {r['olen']}/{r['xlen']}  [{'+'.join(r['kinds'])}]  "
            f"{st}  ({r['cg']})  deps: {deps or '-'}")


def done_units():
    q = os.path.join(ROOT, "progress", "queue.tsv")
    out = {}
    for l in open(q, encoding="utf-8"):
        p = l.rstrip("\n").split("\t")
        if len(p) >= 5 and not l.startswith("#"):
            out[p[0]] = p[4]
    return out


def queue_state(name, states):
    """queue.tsv state of an MS2-UNIT name (queue rows may name a unit `?\\file.cpp` while the source says `dir\\file.cpp`)"""
    if name in states:
        return states[name]
    base, _, suf = name.replace("/", "\\").rpartition("\\")
    return states.get("?\\" + suf)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("filters", nargs="*")
    ap.add_argument("--results", help="progress results.json (default: build/progress-$MS2_AGENT, else the merge tree)")
    ap.add_argument("--measure", action="store_true", help="one summary line per unit (committed merge state)")
    ap.add_argument("--unit", action="append", default=[], help="exact MS2-UNIT name (repeatable); refuses a stale "
                    "result (source or own header newer than the cached obj)")
    ap.add_argument("--state", help="only units in this queue.tsv state (e.g. done-functional)")
    ap.add_argument("-v", "--verbose", action="store_true", help="also list codegen-only / reasoned items")
    a = ap.parse_args()
    import progress
    agent = os.environ.get("MS2_AGENT")
    rdir = None
    if a.results:
        rdir = os.path.dirname(os.path.abspath(a.results))
    elif agent and not a.measure and os.path.exists(os.path.join(ROOT, "build", f"progress-{agent}", "results.json")):
        rdir = os.path.join(ROOT, "build", f"progress-{agent}")
    else:
        rdir = corpus_dir()
    results = json.load(open(os.path.join(rdir, "results.json")))
    states = done_units()
    units = [u for u in progress.find_units(a.filters)] if a.filters or not a.unit else []
    if a.unit:
        allu = progress.find_units([])
        for n in a.unit:
            hit = [u for u in allu if u.name == n] or (
                [u for u in allu if u.name.replace("/", "\\").endswith("\\" + n[2:])] if n.startswith("?\\") else [])
            if len(hit) != 1:
                sys.exit(f"interface: {len(hit)} sources have MS2-UNIT {n}")
            o = os.path.join(rdir, "obj", hit[0].rel[:-4] + ".obj")
            srcs = [hit[0].path] + own_headers(hit[0].path)
            if not os.path.exists(o) or max(os.path.getmtime(x) for x in srcs) > os.path.getmtime(o):
                sys.exit(f"interface: {os.path.relpath(rdir, ROOT)} has no fresh result for {n}: run "
                         f"tools/unit-check.sh --functional on it first")
            units += hit
    if a.state:
        units = [u for u in units if queue_state(u.name, states) == a.state]
    cache, nviol, summary = {}, 0, collections.Counter()
    for u in units:
        res = (results.get(u.rel) or {}).get("res")
        if not res:
            if a.filters:
                print(f"{u.name}: no results in {os.path.relpath(rdir, ROOT)} (run unit-check / progress.py first)")
            continue
        rows = check_unit(u.rel, u.name, res, os.path.join(rdir, "obj", u.rel[:-4] + ".obj"), cache)
        v = [r for r in rows if r["violation"]]
        nviol += len(v)
        nfun = sum(1 for p in res["pairs"].values() if not p["ok"] and p.get("how") != "auto-guess")
        summary["units"] += 1
        summary["fail"] += bool(v)
        summary["shared"] += len(rows)
        summary["viol"] += len(v)
        summary["cg"] += sum(1 for r in rows if r["cg_ok"] and not r["reason"])
        summary["reason"] += sum(1 for r in rows if r["reason"])
        summary["weak"] += sum(1 for r in rows if r["reason"] and r["weak"])
        for r in v:
            for k in r["kinds"]:
                summary["k_" + k] += 1
        if a.measure:
            print(f"{u.name} [{queue_state(u.name, states) or '?'}]: {nfun} non-exact, {len(rows)} shared, "
                  f"{sum(1 for r in rows if r['cg_ok'] and not r['reason'])} codegen-only, "
                  f"{sum(1 for r in rows if r['reason'])} reasoned, {len(v)} VIOLATIONS")
        if not a.measure and (v or a.verbose and rows):
            print(f"{u.name} [{queue_state(u.name, states) or '?'}]: {len(v)} interface violation(s)")
        for r in rows:
            if r["violation"] or a.verbose:
                print(("  INTERFACE " if r["violation"] else "  ok ") + fmt_row(r))
    print(f"interface: {summary['units']} units, {summary['fail']} failing; shared non-exact {summary['shared']} "
          f"(codegen-only {summary['cg']}, reasoned {summary['reason']} [weak {summary['weak']}], violations "
          f"{summary['viol']}: ext {summary['k_ext']} class {summary['k_class']} comdat {summary['k_comdat']})")
    if nviol and not os.environ.get("MS2_INTERFACE_WARN"):
        sys.exit(1)


if __name__ == "__main__":
    main()
