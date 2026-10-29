#!/usr/bin/env python3
"""Measure the full-exe link: unresolved externals (by subsystem), duplicate symbols, section sizes vs the exe, placement
drift of functions with a known exe VA (symbols tables) between fullexe.map and the exe."""
import bisect, collections, os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import SYMBOL_TABLES, ROOT as R, OUT as F, TREE as T, tagged, status_tsv  # noqa: E402
log = open(tagged("link.log"), encoding="latin1").read().splitlines()

# --- symbol -> exe va
sym2va = {}
for fn in SYMBOL_TABLES:
    for l in open(os.path.join(T, "progress", fn), encoding="latin1"):
        p = l.rstrip("\n").split("\t")
        if l[0] != "#" and len(p) > 1:
            try:
                sym2va.setdefault(p[0], int(p[1], 16))
            except ValueError:
                pass
# --- exe va -> owner (units.tsv cpp / status unit)
units = []
for l in open(os.path.join(R, "data/map/units.tsv")):
    p = l.rstrip("\n").split("\t")
    if l[0] != "#" and len(p) > 2:
        units.append((int(p[0], 16), int(p[1], 16), p[2]))
units.sort()
ustarts = [u[0] for u in units]
status = {}
for l in open(status_tsv()):
    p = l.split("\t")
    if l[0] != "#":
        status[int(p[0], 16)] = (p[2], p[3])

def where(va):
    if va in status:
        u, st = status[va]
        if u.startswith("gb:"):
            return "engine:" + u[3:].split("/")[0], st
        return ("scaleform" if u.startswith("sfr_") else "game"), st
    i = bisect.bisect_right(ustarts, va) - 1
    if i >= 0 and va < units[i][1]:
        return ("scaleform" if units[i][2].startswith("sfr_") else "game"), "no row"
    return "outside units", "no row"

CRT = re.compile(r"^(__|_?_?(std|security|GSHandler|C_specific|CxxFrame|CxxThrow|RTC|chkstk|purecall|guard|tls|dyn_tls|"
                 r"scrt|acrt|vcrt|crt|imp_)|_?(mem|str|wcs|mbs|_?(s)?printf|sprintf|_?v?s?n?w?printf|atexit|onexit|malloc|"
                 r"free|calloc|realloc|_aligned|abort|exit|terminate|_?initterm|_?purecall|_?fltused|_?ftol|_?Init_thread))")

def demangle(names):
    out = {}
    names = list(names)
    for i in range(0, len(names), 5000):
        chunk = names[i:i + 5000]
        r = subprocess.run(["llvm-undname"], input="\n".join(chunk), capture_output=True, text=True)
        lines = [l for l in r.stdout.splitlines() if l.strip()]
        # llvm-undname echoes "<mangled>\n<demangled>\n\n" per input
        j = 0
        for n in chunk:
            if j + 1 < len(lines) and lines[j] == n:
                out[n] = lines[j + 1]; j += 2
            else:
                out[n] = n
    return out

def subsystem(sym, dem):
    va = sym2va.get(sym)
    if va is not None:
        w, st = where(va)
        return "exe-addr " + w + " [" + st + "]"
    d = dem
    if sym.startswith("__imp_"):
        return "__imp_ (dllimport) " + subsystem(sym[6:], dem.replace("__imp_", "", 1))[0:0] + ("mfc" if "Afx" in d or "CWnd" in d or "CString" in d else "other")
    keys = [("Gamebryo", r"\b(Ni[A-Z]\w*|efd::|ecr::|egf::|egmToolServices|ecrInput|efdNet|emi::|NiD3D|NSB|NSF)"),
            ("Scaleform", r"Scaleform::"), ("NexonMessenger", r"\bNM\w*|CNM\w*|NMCO|Nmco"),
            ("CEF", r"\bcef_|Cef[A-Z]|CefRefPtr"), ("FMOD", r"FMOD"), ("PhysX", r"\bNx[A-Z]|PhysX"),
            ("MFC/ATL", r"\bC[A-Z]\w+::|\bAfx|ATL::"), ("std", r"\bstd::"), ("CryptoPP", r"CryptoPP"),
            ("Lua", r"\blua[L_]?\w*"), ("DirectX", r"\bD3DX|\bD3D|IDirect|DXGI"), ("zlib", r"\b(deflate|inflate|crc32|adler32)"),
            ("Win32 C", r"^[A-Z][A-Za-z0-9]+[AW]?$")]
    for k, pat in keys:
        if re.search(pat, d):
            return "no-addr " + k
    if CRT.search(sym):
        return "no-addr CRT/compiler"
    return "no-addr other"

unres = collections.defaultdict(set)     # symbol -> referencing objs
dups = collections.defaultdict(set)
SYM = r'(?:"[^"]*" \((\S+)\)|(\S+))'
for l in log:
    m = re.search(r"^(\S+?) : (?:error|warning) LNK20(?:01|19): unresolved external symbol " + SYM, l)
    if m:
        unres[m.group(2) or m.group(3)].add(m.group(1)); continue
    m = re.search(r"^(\S+?) : (?:error|warning) LNK(?:2005|4006): " + SYM + r" already defined in (\S+?);?(?: |$)", l)
    if m:
        dups[m.group(2) or m.group(3)].update((m.group(1), m.group(4)))
dem = demangle(set(unres) | set(dups))
cat = collections.Counter(); catrefs = collections.Counter(); ex = collections.defaultdict(list)
for s, objs in unres.items():
    c = subsystem(s, dem.get(s, s))
    cat[c] += 1; catrefs[c] += len(objs)
    if len(ex[c]) < 6:
        ex[c].append(dem.get(s, s)[:110])
out = [f"# unresolved: {len(unres)} symbols"]
for c, n in cat.most_common():
    out.append(f"{n:7} {catrefs[c]:8} refs  {c}")
    for e in ex[c]:
        out.append(f"           e.g. {e}")
dcat = collections.Counter(); dex = collections.defaultdict(list)
for s, objs in dups.items():
    kinds = tuple(sorted({("engine" if "/gb/" in o or "stock__" in o or "gamebryo__" in o else "obj") for o in objs}))
    c = subsystem(s, dem.get(s, s))
    dcat[c] += 1
    if len(dex[c]) < 4:
        dex[c].append(dem.get(s, s)[:110] + "  <" + " | ".join(sorted(os.path.basename(o) for o in objs))[:160] + ">")
out.append(f"# duplicate (LNK2005): {len(dups)} symbols")
for c, n in dcat.most_common():
    out.append(f"{n:7}  {c}")
    for e in dex[c]:
        out.append(f"           e.g. {e}")
other = collections.Counter(re.search(r"(LNK\d+)", l).group(1) for l in log if re.search(r"LNK\d+", l))
out.append("# diagnostics by code: " + ", ".join(f"{k} {v}" for k, v in other.most_common()))
open(tagged("unresolved.txt"), "w").write("\n".join(f"{s}\t{dem.get(s, s)}\t{len(o)}" for s, o in sorted(unres.items())) + "\n")
open(tagged("duplicates.txt"), "w").write("\n".join(f"{s}\t{dem.get(s, s)}\t{' '.join(sorted(o))}" for s, o in sorted(dups.items())) + "\n")
print("\n".join(out))
