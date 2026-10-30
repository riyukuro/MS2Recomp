#!/usr/bin/env python3
"""Verify the VC11 install (third_party/msvc11, tools/fetch-vs2012.sh) against tools/msvc11/manifest.tsv, check_toolchain style.

    python tools/msvc11/check.py            exit 1 on any difference
    python tools/msvc11/check.py --record   rewrite the manifest from this host's install (maintainer only)

Checked: SHA-256 of every file under bin/, an order-independent digest of include/vc (VS2012 Update 4 VC/include) and
include/sdk/{um,shared} (Windows SDK 8.0), and the cl banner (17.00.61030) through tools/msvc11/cl.
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import ms2paths  # noqa: E402
from check_toolchain import sha256, tree_digest, banner  # noqa: E402

MANIFEST = os.path.join(ms2paths.ROOT, "tools", "msvc11", "manifest.tsv")
VC11 = os.path.join(ms2paths.THIRD_PARTY, "msvc11")
TREES = ["include/vc", "include/sdk/um", "include/sdk/shared"]


def measure():
    out = {}
    b = os.path.join(VC11, "bin")
    for d, _, files in os.walk(b):
        for f in files:
            p = os.path.join(d, f)
            out[("file", os.path.relpath(p, VC11).replace("\\", "/"))] = sha256(p)
    for t in TREES:
        p = os.path.join(VC11, t)
        n, dg = tree_digest(p) if os.path.isdir(p) else (0, "MISSING")
        out[("tree", t)] = "%d %s" % (n, dg)
    out[("version", "cl")] = banner(ms2paths.find_cl_toolset("vc11"), dict(os.environ))
    return out


def main(argv):
    got = measure()
    if "--record" in argv:
        with open(MANIFEST, "w") as f:
            f.write("# VC11 toolchain for `// MS2-TOOLSET: vc11` units (tools/msvc11/check.py --record; cl 17.00.61030 x64 from\n"
                    "# VS2012.4.iso, VC/include from its vc_librarycore86, Windows SDK 8.0 um + shared from VS2012_WDX_ENU.iso).\n"
                    "# Columns: kind, path under third_party/msvc11, value. tree rows: '<file count> <sha256 of the sorted\n"
                    "# lowercase-path+hash list>'.\n")
            for k in sorted(got):
                f.write("\t".join(k) + "\t" + got[k] + "\n")
        print("wrote %s (%d rows)" % (MANIFEST, len(got)))
        return 0
    want = {}
    for line in open(MANIFEST):
        if line.startswith("#") or not line.strip():
            continue
        p = line.rstrip("\n").split("\t")
        want[tuple(p[:-1])] = p[-1]
    bad = ["%s: got %s, want %s" % (" ".join(k), got.get(k, "MISSING"), v) for k, v in sorted(want.items())
           if got.get(k, "MISSING") != v]
    bad += ["%s: not in the manifest" % " ".join(k) for k in sorted(set(got) - set(want))]
    for b in bad:
        print("DIFF " + b)
    print("vc11 toolchain: %s (%d rows, %s)" % ("OK" if not bad else "%d difference(s)" % len(bad), len(want), VC11))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
