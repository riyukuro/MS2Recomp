#!/bin/bash
# Install cl 15.00.30729.207 (VS2008 SP1, x64 target) and the WDK 7.1 CRT/API headers into third_party/msvc9 for the
# units that declare `// MS2-TOOLSET: vc9` (tools/msvc9/cl runs it). Nothing of it goes into git (third_party/ is ignored).
#
#   tools/fetch-vc9.sh <path to GRMWDK_EN_7600_1.ISO>    from your own copy of the WDK 7.1.0 ISO
#   tools/fetch-vc9.sh --download                         fetch it from Microsoft's download centre first (620 MB)
#   tools/fetch-vc9.sh --check                            only verify an existing install
#
# The ISO is checked against its SHA-256 before anything is extracted, the install against tools/msvc9/manifest.tsv
# (tools/msvc9/check.py: SHA-256 of every binary, digests of the two header trees, the cl banner).
# Needs bsdtar, cabextract and wine (msiexec /a unpacks headers.msi; the prefix is third_party/msvc9/prefix).
set -euo pipefail
R=$(cd "$(dirname "$0")/.." && pwd)
TP=${MS2_THIRD_PARTY:-$R/third_party}
V=$TP/msvc9
PY=$R/.venv/bin/python; [ -x "$PY" ] || PY=python3
ISO_SHA=5edc723b50ea28a070cad361dd0927df402b7a861a036bbcf11d27ebba77657d
ISO_URL=https://download.microsoft.com/download/4/A/2/4A25C7D5-EFBE-4182-B6A9-AE6850409A78/GRMWDK_EN_7600_1.ISO
WDKVER=7600.16385.win7_wdk.100208-1538
# buildtools_x86fre_cab001.cab holds three cl sets (x86, x86->amd64, x86->ia64) as _<name>_<5-digit index>; the amd64
# target set (bin/x86/amd64 in the WDK) is indices 44-61
AMD64_FIRST=44 AMD64_LAST=61

case "${1:-}" in
    --check) exec "$PY" "$R/tools/msvc9/check.py" ;;
    --download)
        mkdir -p "$TP/downloads"
        ISO=$TP/downloads/GRMWDK_EN_7600_1.ISO
        [ -f "$ISO" ] || { curl -fL --retry 3 -o "$ISO.part" "$ISO_URL" && mv "$ISO.part" "$ISO"; } ;;
    ""|-h|--help) sed -n '2,11p' "$0" | sed 's/^# \{0,1\}//'; exit 2 ;;
    *) ISO=$1 ;;
esac
for t in bsdtar cabextract wine; do
    command -v $t >/dev/null || { echo "fetch-vc9: $t not found" >&2; exit 2; }
done
echo "fetch-vc9: checking $ISO"
got=$(sha256sum "$ISO" | cut -d' ' -f1)
[ "$got" = "$ISO_SHA" ] || { echo "fetch-vc9: $ISO: sha256 $got, want $ISO_SHA (GRMWDK_EN_7600_1.ISO, WDK 7.1.0)" >&2; exit 1; }

mkdir -p "$TP"
T=$(mktemp -d "$TP/.msvc9-fetch.XXXXXX")
trap 'rm -rf "$T"' EXIT
mkdir -p "$T/iso" "$T/cab" "$T/new/bin/1033" "$T/new/include"
bsdtar -xf "$ISO" -C "$T/iso" WDK/buildtools_x86fre_cab001.cab WDK/headers.msi WDK/headers_cab001.cab
cabextract -q -d "$T/cab" "$T/iso/WDK/buildtools_x86fre_cab001.cab"
for f in "$T"/cab/_*_[0-9][0-9][0-9][0-9][0-9]; do
    b=${f##*/}
    n=$((10#${b##*_}))
    [ $n -ge $AMD64_FIRST ] && [ $n -le $AMD64_LAST ] || continue
    nm=${b#_}; nm=${nm%_*}
    cp "$f" "$T/new/bin/$nm"
done
for f in clui.dll cvtresui.dll linkui.dll; do cp "$T/new/bin/$f" "$T/new/bin/1033/"; done

# headers.msi: an administrative install unpacks the tree without registering anything
export WINEPREFIX=$V.prefix-fetch WINEDEBUG=-all DISPLAY= WAYLAND_DISPLAY=
winp() { local p="z:$1"; echo "${p//\//\\}"; }
echo "fetch-vc9: unpacking headers.msi (wine msiexec /a)"
timeout 1200 wine msiexec /a "$(winp "$T/iso/WDK/headers.msi")" /qn TARGETDIR="$(winp "$T/hdr")" >/dev/null 2>&1 || true
wineserver -k 2>/dev/null || true
rm -rf "$WINEPREFIX"
H=$T/hdr/WinDDK/$WDKVER/inc
[ -d "$H/crt" ] && [ -d "$H/api" ] || { echo "fetch-vc9: msiexec did not produce $H/{crt,api}" >&2; exit 1; }
mv "$H/crt" "$H/api" "$T/new/include/"

rm -rf "$V.old"
[ -d "$V" ] && mv "$V" "$V.old"
mv "$T/new" "$V"
rm -rf "$V.old"
"$PY" "$R/tools/msvc9/check.py"
