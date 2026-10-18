#!/bin/sh
# usage: tools/apply-engine-patches.sh <engine-patches-dir> <stock-gamebryo-tree>
# Verifies stock hashes, applies the ed-style patches, verifies result hashes; refuses on any mismatch.
exec python3 -I "$(dirname "$0")/apply_engine_patches.py" "$@"
