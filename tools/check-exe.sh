#!/bin/bash
# Verify that you have the exact MapleStory2.exe the project is matched against (KMS2_DEV x64 build, 66,052,624 bytes).
#
#   tools/check-exe.sh [path/to/MapleStory2.exe]
#
# Default path: $MS2_EXE, else "Game Versions/KMS2_DEV/x64/MapleStory2.exe" inside the checkout. The exe is not
# distributed with this repository; every byte-match gate compares against it. Exit 0 = the hash matches.
set -u
R=$(cd "$(dirname "$0")/.." && pwd)
WANT=1a3009453a6e7bc6c93c87c1dac139b440df74419c8320262721399f2f91d660
EXE=${1:-${MS2_EXE:-$R/Game Versions/KMS2_DEV/x64/MapleStory2.exe}}
if [ ! -f "$EXE" ]; then
    echo "check-exe: not found: $EXE" >&2
    echo "  Put your KMS2_DEV x64 MapleStory2.exe at: Game Versions/KMS2_DEV/x64/MapleStory2.exe (inside the checkout)," >&2
    echo "  or point MS2_EXE at it. Expected SHA-256 $WANT" >&2
    exit 2
fi
GOT=$(sha256sum "$EXE" | cut -d' ' -f1)
if [ "$GOT" = "$WANT" ]; then echo "check-exe: OK ($EXE)"; exit 0; fi
echo "check-exe: MISMATCH for $EXE" >&2
echo "  got  $GOT" >&2
echo "  want $WANT" >&2
echo "  This is a different build; the gates will not match. You need the KMS2_DEV x64 exe." >&2
exit 1
