#!/usr/bin/env python3
"""Verify that the MSVC toolchain on this host is the one the byte-matches were made with, before you spend time on a unit.

    python tools/check_toolchain.py            check against tools/toolchain-manifest.tsv (exit 1 on any difference)
    python tools/check_toolchain.py --record   rewrite the manifest from this host's install (maintainer only)
    python tools/check_toolchain.py --quick    skip the whole-tree digests (compiler binaries, key headers, versions only)

Checked: cl.exe / link.exe version banners, SHA-256 of cl.exe, c1.dll, c1xx.dll, c2.dll, link.exe, key MFC/ATL/CRT/SDK headers and
mfc140.lib, and an order-independent digest of the complete VC include, ATLMFC include and Windows SDK ucrt/um/shared trees (so
one patched header anywhere is caught). Also reports whether the other tools (cmake, ninja, clang-cl, llvm-nm, llvm-undname,
Python modules) are on PATH. Linux: reads third_party/msvc (msvc-wine). Windows: the VS2017 v141 install found through vswhere /
vcvarsall (see tools/ms2paths.py; MS2_VCVARS, MS2_CL override). tools/check-toolchain.sh is a thin wrapper.
"""
import hashlib
import os
import re
import shutil
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ms2paths  # noqa: E402

ROOT = ms2paths.ROOT
MANIFEST = os.path.join(ROOT, "tools", "toolchain-manifest.tsv")
BIN = "bin/Hostx64/x64"
VC_FILES = [BIN + "/" + n for n in ("cl.exe", "c1.dll", "c1xx.dll", "c2.dll", "link.exe", "lib.exe", "mspdb140.dll",
                                    "mspdbcore.dll", "msobj140.dll")] + [
    "atlmfc/lib/x64/mfc140.lib", "atlmfc/lib/x64/atls.lib", "lib/x64/msvcrt.lib", "lib/x64/libcmt.lib",
    "include/yvals.h", "include/xmemory0", "include/xstring", "include/xutility", "include/vector", "include/string",
    "include/type_traits", "include/vcruntime.h", "include/eh.h", "include/new", "include/intrin.h",
    "atlmfc/include/afx.h", "atlmfc/include/afxwin.h", "atlmfc/include/afxcmn.h", "atlmfc/include/afxcoll.h",
    "atlmfc/include/atlbase.h", "atlmfc/include/atlcom.h", "atlmfc/include/atlstr.h", "atlmfc/include/atlsimpstr.h",
    "atlmfc/include/atlcore.h", "atlmfc/include/cstringt.h", "atlmfc/include/afxstr.h"]
SDK_FILES = ["ucrt/stdio.h", "ucrt/corecrt.h", "ucrt/corecrt_wstdio.h", "ucrt/stdlib.h", "um/windows.h", "um/winbase.h",
             "um/winuser.h", "um/d3d11.h", "um/winnt.h", "shared/d3d9.h", "shared/windef.h"]
VC_TREES = ["include", "atlmfc/include"]
SDK_TREES = ["ucrt", "um", "shared"]
TOOLS = ["cmake", "ninja", "clang-cl", "llvm-nm", "llvm-undname"]


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for blk in iter(lambda: f.read(1 << 20), b""):
            h.update(blk)
    return h.hexdigest()


def ci_path(base, rel):
    """base/rel with every component matched case-insensitively (the SDK headers are mixed case on disk; Windows does not care,
    Linux does). Returns the joined path unchanged when a component is missing."""
    cur = base
    for part in rel.split("/"):
        try:
            names = os.listdir(cur)
        except OSError:
            return os.path.join(base, rel)
        hit = part if part in names else next((n for n in sorted(names) if n.lower() == part.lower()), part)
        cur = os.path.join(cur, hit)
    return cur


def tree_digest(top):
    """(file count, digest) over lowercased relative paths + file hashes, symlinks (msvc-wine's case aliases) ignored."""
    rows = set()
    for d, dirs, files in os.walk(top):
        dirs[:] = [x for x in dirs if not os.path.islink(os.path.join(d, x))]
        for f in files:
            p = os.path.join(d, f)
            if not os.path.islink(p):
                rows.add((os.path.relpath(p, top).replace("\\", "/").lower(), sha256(p)))
    rows = sorted(rows)
    h = hashlib.sha256()
    for r in rows:
        h.update(("%s %s\n" % r).encode())
    return len(rows), h.hexdigest()


def banner(exe, env):
    """version banner of cl / link (they print it on stderr when run without arguments)"""
    try:
        r = subprocess.run([exe], capture_output=True, text=True, env=env, encoding="latin1", timeout=120)
    except (OSError, subprocess.SubprocessError) as ex:
        return "unavailable: %s" % ex
    m = re.search(r"Version ([0-9.]+)", r.stdout + r.stderr)
    return m.group(1) if m else "unknown"


def locations():
    env = ms2paths.toolchain_env()
    vc = ms2paths.msvc_tools_dir(env)
    sdk = ms2paths.winsdk_include(env)
    return env, vc, sdk


def measure(vc, sdk, env, quick):
    """-> {key tuple: value} for this host"""
    out = {}
    cl = os.path.join(vc, BIN, "cl.exe") if os.path.exists(os.path.join(vc, BIN, "cl.exe")) else ms2paths.find_cl(env)
    link = os.path.join(vc, BIN, "link.exe")
    out[("version", "cl")] = banner(ms2paths.find_cl(env), env)
    out[("version", "link")] = banner(link if os.name == "nt" else os.path.join(ms2paths.THIRD_PARTY, "msvc", "bin", "x64", "link"),
                                      env)
    for rel in VC_FILES:
        p = ci_path(vc, rel)
        out[("file", "vc", rel)] = sha256(p) if os.path.isfile(p) else "MISSING"
    for rel in SDK_FILES:
        p = ci_path(sdk, rel)
        out[("file", "sdk", rel)] = sha256(p) if os.path.isfile(p) else "MISSING"
    if not quick:
        for root, base, trees in (("vc", vc, VC_TREES), ("sdk", sdk, SDK_TREES)):
            for t in trees:
                p = os.path.join(base, t)
                n, d = tree_digest(p) if os.path.isdir(p) else (0, "MISSING")
                out[("tree", root, t)] = "%d %s" % (n, d)
    return out


def read_manifest():
    want = {}
    with open(MANIFEST) as f:
        for line in f:
            if line.startswith("#") or not line.strip():
                continue
            p = line.rstrip("\n").split("\t")
            want[tuple(p[:-1])] = p[-1]
    return want


def write_manifest(got):
    with open(MANIFEST, "w") as f:
        f.write("# MSVC toolchain the byte-matches were made with (tools/check_toolchain.py --record; cl 19.16.27054, VS2017 15.9 v141,\n"
                "# Windows SDK 10.0.19041.0; tree rows count each lowercase path once). Columns: kind, root (vc = VC/Tools/MSVC/14.16.27023, sdk = Windows Kits/10/Include/10.0.19041.0),\n"
                "# relative path, value. tree rows: '<file count> <sha256 of the sorted lowercase-path+hash list>', symlinks ignored.\n")
        for k in sorted(got):
            f.write("\t".join(k) + "\t" + got[k] + "\n")


def compare(want, got):
    bad = []
    for k in sorted(want):
        g = got.get(k)
        if g is None:
            continue    # quick mode skips the tree rows
        if g != want[k]:
            bad.append("%s: got %s, want %s" % (" ".join(k), g, want[k]))
    return bad


def other_tools():
    notes = []
    path = os.pathsep.join([os.path.join(ROOT, ".venv", "bin"), os.path.join(ROOT, ".venv", "Scripts"), os.environ.get("PATH", "")])
    for t in TOOLS:
        if not shutil.which(t, path=path):
            notes.append("%s not found on PATH" % t)
    for m in ("capstone", "pefile"):
        try:
            __import__(m)
        except ImportError:
            notes.append("python module %s missing (pip install -r requirements.txt)" % m)
    return notes


def main(argv):
    quick, record = "--quick" in argv, "--record" in argv
    env, vc, sdk = locations()
    print("check-toolchain: VC  %s\ncheck-toolchain: SDK %s" % (vc, sdk))
    if not vc or not os.path.isdir(vc):
        print("check-toolchain: MSVC 14.16 toolset not found (see CONTRIBUTING.md, Windows)", file=sys.stderr)
        return 2
    if not os.path.isdir(sdk):
        print("check-toolchain: Windows SDK include dir not found: %s" % sdk, file=sys.stderr)
        return 2
    got = measure(vc, sdk, env, quick and not record)
    if record:
        write_manifest(got)
        print("check-toolchain: recorded %d rows in %s" % (len(got), MANIFEST))
        return 0
    bad = compare(read_manifest(), got)
    for n in other_tools():
        print("check-toolchain: warning: " + n)
    if bad:
        print("check-toolchain: MISMATCH (%d differences); byte-matches will not be reliable with this toolchain" % len(bad),
              file=sys.stderr)
        for b in bad[:40]:
            print("  " + b, file=sys.stderr)
        if len(bad) > 40:
            print("  ... %d more" % (len(bad) - 40), file=sys.stderr)
        print("  You need VS2017 15.9 (cl 19.16.27054) with the 14.16.27023 toolset + MFC/ATL MBCS and Windows 10 SDK 10.0.19041.",
              file=sys.stderr)
        return 1
    print("check-toolchain: OK (cl %s, link %s%s)" % (got[("version", "cl")], got[("version", "link")],
                                                      ", quick: header trees not digested" if quick else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
