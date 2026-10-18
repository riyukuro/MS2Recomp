#!/bin/sh
# Verify the MSVC toolchain against tools/toolchain-manifest.tsv (see tools/check_toolchain.py). Linux entry point.
R=$(cd "$(dirname "$0")/.." && pwd)
PY="$R/.venv/bin/python"; [ -x "$PY" ] || PY=python3
exec "$PY" "$R/tools/check_toolchain.py" "$@"
