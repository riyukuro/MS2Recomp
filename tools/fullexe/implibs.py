#!/usr/bin/env python3
"""One .def (and with --lib its import .lib, lib /def under wine) per DLL of the exe's import directory (exact DLL names,
the exe's import set); mfc140 (by ordinal) is left to the real mfc140.lib. Data imports (mangled @@3/@@2 storage) get
DATA. Beyond the exe's own imports:
  libcef.dll    the full export table of the shipped x64 libcef.dll (CEF 3.3396): the C API functions the wrapper's
                cef_* calls name (views, server, translator_test, waitable_event, xml/zip readers ...) that the exe's
                IAT lacks because the code calling them is not linked there; /opt:ref keeps unused ones out
  EXTRA         single functions the linked objs call and the exe never imported
    implibs.py [--lib] [--imports FILE] [--write-imports FILE]
  --imports        read the (dll, symbol) set from FILE (data/fullexe/imports.tsv) instead of the exe and libcef.dll: names
                   only, the same .def files
  --write-imports  write that set (from the exe, libcef.dll and EXTRA) to FILE and exit"""
import collections, os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT as R, OUT as F, TREE as T, EXE, tagged, wine  # noqa: E402
import bytematch as bm
import ms2paths  # noqa: E402
import pefile  # noqa: E402
OUT = os.path.join(F, "implib")
os.makedirs(OUT, exist_ok=True)
EXTRA = {"D3DX9_42.dll": ("D3DXGetShaderConstantTable",), "D3DCompiler_42.dll": ("D3DGetInputSignatureBlob",),
         # Crypto++ socketft/wait/winpipes, efd Thread_Win32, the CEF lock, the IME caret, tooltip/loading-dialog shell
         # helpers: code the exe dead-stripped or inlined differently, so its IAT lacks them
         "KERNEL32.dll": ("CancelIo", "CreateThread", "GetOverlappedResult", "PulseEvent", "TryEnterCriticalSection",
                          "VirtualQuery"),
         "USER32.dll": ("GetCaretPos",), "SHLWAPI.dll": ("SHCreateMemStream", "StrCmpCA", "StrCmpCW"),
         "OLEAUT32.dll": ("SysAllocStringLen",), "DSOUND.dll": ("DirectSoundCreate8",),  # the exe imports it as #11
         "WS2_32.dll": ("WSAGetOverlappedResult", "WSARecv", "WSASend", "WSASetLastError", "getservbyname", "select",
                        "shutdown")}
CEF = os.path.join(os.path.dirname(EXE), "libcef.dll")


def arg(name):
    return sys.argv[sys.argv.index(name) + 1] if name in sys.argv else None


per = collections.defaultdict(set)
if arg("--imports"):
    for l in open(arg("--imports")):
        if l.strip() and l[0] != "#":
            dll, s = l.rstrip("\n").split("\t")[:2]
            per[dll].add((s, None))
for slot, v in (() if arg("--imports") else bm.Exe(bm.EXE).iat.items()):
    dll, s = v.split("!", 1)
    if dll.lower() == "mfc140.dll":
        continue
    if s.startswith("#"):
        per[dll].add(("@" + s[1:], None))
    else:
        per[dll].add((s, None))
for dll, names in (() if arg("--imports") else EXTRA.items()):
    k = next((d for d in per if d.lower() == dll.lower()), dll)
    per[k] |= {(n, None) for n in names}
if not arg("--imports") and os.path.exists(CEF):
    k = next((d for d in per if d.lower() == "libcef.dll"), "libcef.dll")
    pe = pefile.PE(CEF, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_EXPORT"]])
    per[k] |= {(e.name.decode(), None) for e in pe.DIRECTORY_ENTRY_EXPORT.symbols if e.name}
if arg("--write-imports"):
    with open(arg("--write-imports"), "w", newline="\n") as f:
        f.write("# dll\tsymbol (@n = by ordinal): the import libs' names, from the exe's import directory, the shipped"
                " libcef.dll's\n# export table and implibs.py's EXTRA (tools/fullexe/implibs.py --write-imports)\n")
        for dll, syms in sorted(per.items()):
            for s, _ in sorted(syms):
                f.write("%s\t%s\n" % (dll, s))
    sys.exit(0)
env = dict(os.environ, WINEPREFIX=ms2paths.WINEPREFIX, WINEDEBUG="-all")
for dll, syms in sorted(per.items()):
    base = os.path.splitext(dll)[0]
    with open(os.path.join(OUT, base + ".def"), "w") as f:
        f.write(f"LIBRARY \"{dll}\"\nEXPORTS\n")
        for s, _ in sorted(syms):
            if s.startswith("@"):
                f.write(f"  ord{s[1:]} {s} NONAME\n")
            else:
                data = " DATA" if re.search(r"@@[23]", s) else ""
                f.write(f"  {s}{data}\n")
    print(base)
    if "--lib" in sys.argv:
        d = os.path.join(OUT, base + ".def")
        subprocess.run([os.path.join(ms2paths.THIRD_PARTY, "msvc", "bin", "x64", "lib"), "/nologo", "/machine:x64",
                        "/def:" + wine(d), "/out:" + wine(d[:-4] + ".lib")], env=env, cwd=R, check=True,
                       stdout=subprocess.DEVNULL)
