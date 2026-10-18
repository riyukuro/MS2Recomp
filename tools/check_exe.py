#!/usr/bin/env python3
"""Verify that you have the exact MapleStory2.exe the project is matched against (KMS2_DEV x64 build, 66,052,624 bytes).

    python tools/check_exe.py [path/to/MapleStory2.exe]          (tools/check-exe.sh is a thin wrapper on Linux)

Default path: $MS2_EXE, else "Game Versions/KMS2_DEV/x64/MapleStory2.exe" inside the checkout. The exe is not
distributed with this repository; every byte-match gate compares against it. Exit 0 = the hash matches.
"""
import hashlib
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WANT = "1a3009453a6e7bc6c93c87c1dac139b440df74419c8320262721399f2f91d660"


def main(argv):
    exe = argv[1] if len(argv) > 1 and argv[1] else (os.environ.get("MS2_EXE") or
                                                      os.path.join(ROOT, "Game Versions", "KMS2_DEV", "x64", "MapleStory2.exe"))
    if not os.path.isfile(exe):
        print("check-exe: not found: %s" % exe, file=sys.stderr)
        print("  Put your KMS2_DEV x64 MapleStory2.exe at: Game Versions/KMS2_DEV/x64/MapleStory2.exe (inside the checkout),", file=sys.stderr)
        print("  or point MS2_EXE at it. Expected SHA-256 %s" % WANT, file=sys.stderr)
        return 2
    h = hashlib.sha256()
    with open(exe, "rb") as f:
        for blk in iter(lambda: f.read(1 << 20), b""):
            h.update(blk)
    got = h.hexdigest()
    if got == WANT:
        print("check-exe: OK (%s)" % exe)
        return 0
    print("check-exe: MISMATCH for %s" % exe, file=sys.stderr)
    print("  got  %s" % got, file=sys.stderr)
    print("  want %s" % WANT, file=sys.stderr)
    print("  This is a different build; the gates will not match. You need the KMS2_DEV x64 exe.", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
