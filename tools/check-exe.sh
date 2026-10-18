#!/bin/sh
# Verify that you have the exact MapleStory2.exe the project is matched against (see tools/check_exe.py). Linux entry point.
#
#   tools/check-exe.sh [path/to/MapleStory2.exe]
R=$(cd "$(dirname "$0")/.." && pwd)
PY="$R/.venv/bin/python"; [ -x "$PY" ] || PY=python3
exec "$PY" "$R/tools/check_exe.py" "$@"
