#!/bin/sh
# Wrapper for Ghidra (official 12.1.4 release unpacked in third_party/ghidra_12.1.4_PUBLIC, symlinked at third_party/ghidra).
#   tools/ghidra.sh gui        -> GUI (opens a window; agents must not use this)
#   tools/ghidra.sh            -> prints this usage
#   tools/ghidra.sh analyze    -> headless import + full analysis of the KMS2_DEV x64 dump into ghidra/MS2.gpr
#   tools/ghidra.sh headless … -> raw analyzeHeadless with project args prefilled (-process MapleStory2.exe -noanalysis ...)
ROOT=$(cd "$(dirname "$0")/.." && pwd)
GHIDRA="$ROOT/third_party/ghidra"
EXE="$ROOT/Game Versions/KMS2_DEV/x64/MapleStory2.exe"
export GHIDRA_HEADLESS_MAXMEM=${GHIDRA_HEADLESS_MAXMEM:-12G}
export XDG_CONFIG_HOME="$ROOT/work/ghidra_settings" XDG_CACHE_HOME="$ROOT/work/ghidra_cache"
mkdir -p "$ROOT/ghidra" "$XDG_CONFIG_HOME" "$XDG_CACHE_HOME"

case "$1" in
analyze)
    exec "$GHIDRA/support/analyzeHeadless" "$ROOT/ghidra" MS2 \
        -import "$EXE" -overwrite \
        -scriptPath "$ROOT/tools/ghidra_scripts" \
        -postScript ExportFunctions.java "$ROOT/work/functions.tsv" \
        -analysisTimeoutPerFile 86400 \
        -log "$ROOT/ghidra/analyze.log" -scriptlog "$ROOT/ghidra/script.log"
    ;;
headless)
    shift
    exec "$GHIDRA/support/analyzeHeadless" "$ROOT/ghidra" MS2 -scriptPath "$ROOT/tools/ghidra_scripts" "$@"
    ;;
gui)
    exec "$GHIDRA/ghidraRun"
    ;;
*)
    sed -n '2,6p' "$0" >&2
    exit 2
    ;;
esac
