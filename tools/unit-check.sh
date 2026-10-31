#!/bin/sh
# Per-unit done check for one agent (docs/RECOVERY.md sections 10 and 12). Safe to run while other agents run theirs.
#
#   MS2_AGENT=<name> tools/unit-check.sh [--functional] [--no-clang] [--no-dll] [-v] <unit-substr> [<unit-substr> ...]
#
# Thin wrapper: the implementation is tools/unit_check.py (also the entry point on native Windows; see its docstring for the
# steps - progress.py --check, the cl 19.16 / clang-cl DLL link checks, then the fullexe precheck (relink of the last
# published latest build with the unit's obj; MS2_FULLEXE_PRECHECK=0 skips it) - and what --functional changes).
R=$(cd "$(dirname "$0")/.." && pwd)
PY="$R/.venv/bin/python"; [ -x "$PY" ] || PY=python3
exec "$PY" "$R/tools/unit_check.py" "$@"
