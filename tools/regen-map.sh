#!/bin/bash
# Regenerate the exe-derived data files the gates read (nothing derived from the exe is published in this repository).
#
#   tools/regen-map.sh rtti [OUTDIR]     RTTI classes + vftables from the exe alone. Deterministic: the output is byte-identical
#                                        to the maintainer's files. Default OUTDIR = $MS2_CLASSES_DIR or work/classes.
#   tools/regen-map.sh ghidra            functions.tsv / calls / strrefs / vtables via Ghidra headless (needs Ghidra 11.x
#                                        at third_party/ghidra). NOT byte-identical to the maintainer's map (see below).
#
# What the gates need: rtti_classes.tsv + rtti_vftables.tsv (vftable pairing), work/map/functions.tsv (function starts and
# sizes, used to pair and size-check every compiled function) and work/map/units.tsv (unit ranges, only for totals and
# tplpin). The maintainer's functions.tsv/units.tsv come from a curated Ghidra project (FID library matching, manual
# function creation, unit segmentation by tools/unit_map.py); that project is not reproducible by a script. Ask the
# maintainer for the two files if the Ghidra output differs from what a unit's MS2-RANGE lines expect.
set -eu
R=$(cd "$(dirname "$0")/.." && pwd)
PY="$R/.venv/bin/python"; [ -x "$PY" ] || PY=python3
"$R/tools/check-exe.sh" >/dev/null
EXE=${MS2_EXE:-$R/Game Versions/KMS2_DEV/x64/MapleStory2.exe}
case "${1:-}" in
rtti)
    OUT=${2:-${MS2_CLASSES_DIR:-$R/work/classes}}
    mkdir -p "$OUT"
    "$PY" "$R/tools/rtti_scan.py" "$EXE" "$OUT"
    ;;
ghidra)
    MAP=${MS2_MAP_DIR:-$R/work/map}
    mkdir -p "$MAP"
    "$R/tools/ghidra.sh" analyze
    "$R/tools/ghidra.sh" headless -process MapleStory2.exe -noanalysis -postScript ExportMap.java "$MAP"
    echo "regen-map: wrote $MAP/{functions,calls,strrefs,vtables}.tsv (units.tsv: tools/unit_map.py, needs the same inputs)"
    ;;
*) sed -n '2,15p' "$0"; exit 2 ;;
esac
