#!/bin/sh
# Run ninja on a cl 19.16 build dir with the project Wine prefix (needed for dirs configured before tools/msvc/ existed,
# e.g. build/gamebryo-msvc; otherwise Wine falls back to ~/.wine).
R=$(cd "$(dirname "$0")/.." && pwd)
export WINEPREFIX="${MS2_WINEPREFIX:-${MS2_MSVC_WINEPREFIX:-$R/work/wineprefix-msvc}}" WINEDEBUG="${WINEDEBUG:--all}" PATH="$R/.venv/bin:$PATH"
exec ninja "$@"
