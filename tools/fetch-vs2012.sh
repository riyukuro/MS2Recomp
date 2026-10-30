#!/bin/bash
# Install cl 17.00.61030 (VS2012 Update 4, x86-hosted x64 target), the VS2012 VC headers and the Windows 8.0 SDK headers
# into third_party/msvc11 for the units that declare `// MS2-TOOLSET: vc11` (tools/msvc11/cl runs it). Nothing of it
# goes into git (third_party/ is ignored).
#
#   tools/fetch-vs2012.sh <VS2012.4.iso> <VS2012_WDX_ENU.iso>   from your own copies of the two ISOs
#   tools/fetch-vs2012.sh --download                            fetch both from Microsoft's download centre first (3.1 GB)
#   tools/fetch-vs2012.sh --check                               only verify an existing install
#
# VS2012.4.iso (the Update 4 full ISO) has the compiler and the VC headers; the Windows SDK 8.0 headers come from the
# VS2012 Express for Windows Desktop ISO. Both ISOs are checked against their SHA-256 before anything is extracted, the
# install against tools/msvc11/manifest.tsv (tools/msvc11/check.py: SHA-256 of every binary, header tree digests, banner).
# Needs bsdtar, cabextract and wine (msiexec /a unpacks the header msis; cl uses wine's builtin msvcr110/msvcp110).
set -euo pipefail
R=$(cd "$(dirname "$0")/.." && pwd)
TP=${MS2_THIRD_PARTY:-$R/third_party}
V=$TP/msvc11
PY=$R/.venv/bin/python; [ -x "$PY" ] || PY=python3
U4_SHA=c462118eabcc242a50f1215587cb1c79505159af79fc50c24d8be1d25203cd87
U4_URL=https://download.microsoft.com/download/D/4/8/D48D1AC2-A297-4C9E-A9D0-A218E6609F06/VSU4/VS2012.4.iso
WDX_SHA=d38e57b269aed44a41ce2b74b78dad3b92d2bc553fc4b71180080a8936ce2ffb
WDX_URL=https://download.microsoft.com/download/1/F/5/1F519CC5-0B90-4EA3-8159-33BFB97EF4D9/VS2012_WDX_ENU.iso

case "${1:-}" in
    --check) exec "$PY" "$R/tools/msvc11/check.py" ;;
    --download)
        mkdir -p "$TP/downloads"
        U4=$TP/downloads/VS2012.4.iso WDX=$TP/downloads/VS2012_WDX_ENU.iso
        [ -f "$U4" ] || { curl -fL --retry 3 -o "$U4.part" "$U4_URL" && mv "$U4.part" "$U4"; }
        [ -f "$WDX" ] || { curl -fL --retry 3 -o "$WDX.part" "$WDX_URL" && mv "$WDX.part" "$WDX"; } ;;
    ""|-h|--help) sed -n '2,13p' "$0" | sed 's/^# \{0,1\}//'; exit 2 ;;
    *) [ $# -eq 2 ] || { echo "fetch-vs2012: need both ISOs (VS2012.4.iso VS2012_WDX_ENU.iso)" >&2; exit 2; }
       U4=$1 WDX=$2 ;;
esac
for t in bsdtar cabextract wine; do
    command -v $t >/dev/null || { echo "fetch-vs2012: $t not found" >&2; exit 2; }
done
echo "fetch-vs2012: checking $U4 and $WDX"
got=$(sha256sum "$U4" | cut -d' ' -f1)
[ "$got" = "$U4_SHA" ] || { echo "fetch-vs2012: $U4: sha256 $got, want $U4_SHA (VS2012.4.iso, Update 4)" >&2; exit 1; }
got=$(sha256sum "$WDX" | cut -d' ' -f1)
[ "$got" = "$WDX_SHA" ] || { echo "fetch-vs2012: $WDX: sha256 $got, want $WDX_SHA (VS2012_WDX_ENU.iso)" >&2; exit 1; }

mkdir -p "$TP"
T=$(mktemp -d "$TP/.msvc11-fetch.XXXXXX")
trap 'rm -rf "$T"' EXIT
mkdir -p "$T/iso" "$T/wdx" "$T/cc" "$T/res" "$T/new/bin/1033" "$T/new/include/vc" "$T/new/include/sdk"
# vc_compilercore86 = the x86-hosted compilers (vc_compilercore without 86 is the ARM set); the cab's file names are the
# msi's WinC_compiler_<host>_<target>_<name>_F keys
bsdtar -xf "$U4" -C "$T/iso" packages/vc_compilercore86 packages/vc_compilercore86res/enu packages/vc_librarycore86
cabextract -q -d "$T/cc" "$T/iso/packages/vc_compilercore86/vc_CompilerCore86.cab"
cabextract -q -d "$T/res" "$T/iso/packages/vc_compilercore86res/enu/vc_CompilerCore86Res.cab"
for f in cl.exe c1.dll c1xx.dll c2.dll; do cp "$T/cc/WinC_compiler_x86_amd64_${f}_F" "$T/new/bin/$f"; done
for f in mspdb110.dll mspdbcore.dll mspdbsrv.exe; do cp "$T/cc/WinC_compiler_project_x86_${f}_F" "$T/new/bin/$f"; done
cp "$T/cc/WinC_compiler_x86_msobj110.dll_F" "$T/new/bin/msobj110.dll"
cp "$T/res/WinC_compiler_core_x86_amd64_clui.dll_F_enu" "$T/new/bin/1033/clui.dll"

# the header msis: an administrative install unpacks the tree without registering anything
bsdtar -xf "$WDX" -C "$T/wdx" packages/Windows_SDK
export WINEPREFIX=$V.prefix-fetch WINEDEBUG=-all DISPLAY= WAYLAND_DISPLAY=
winp() { local p="z:$1"; echo "${p//\//\\}"; }
echo "fetch-vs2012: unpacking vc_librarycore86.msi and the two Windows SDK 8.0 header msis (wine msiexec /a)"
timeout 1200 wine msiexec /a "$(winp "$T/iso/packages/vc_librarycore86/vc_librarycore86.msi")" /qn TARGETDIR="$(winp "$T/vc")" >/dev/null 2>&1 || true
S=$T/wdx/packages/Windows_SDK
timeout 1200 wine msiexec /a "$(winp "$S/Windows Software Development Kit-x86_en-us.msi")" /qn TARGETDIR="$(winp "$T/sdk1")" >/dev/null 2>&1 || true
timeout 1200 wine msiexec /a "$(winp "$S/Windows Software Development Kit for Metro style Apps-x86_en-us.msi")" /qn TARGETDIR="$(winp "$T/sdk2")" >/dev/null 2>&1 || true
wineserver -k 2>/dev/null || true
rm -rf "$WINEPREFIX"
H=$T/vc/Program\ Files/Microsoft\ Visual\ Studio\ 11.0/VC/include
[ -f "$H/stdio.h" ] || { echo "fetch-vs2012: msiexec did not produce VC/include" >&2; exit 1; }
cp -r "$H/." "$T/new/include/vc/"
# the SDK splits its headers over the two msis (windows.h is in the Metro one); the two sets do not overlap
for s in sdk1 sdk2; do
    K=$T/$s/Windows\ Kits/8.0/Include
    [ -d "$K/um" ] && [ -d "$K/shared" ] || { echo "fetch-vs2012: msiexec did not produce $s Include/{um,shared}" >&2; exit 1; }
    mkdir -p "$T/new/include/sdk/um" "$T/new/include/sdk/shared"
    cp -rn "$K/um/." "$T/new/include/sdk/um/"
    cp -rn "$K/shared/." "$T/new/include/sdk/shared/"
done
[ -f "$T/new/include/sdk/um/Windows.h" ] || { echo "fetch-vs2012: no Windows.h in the SDK headers" >&2; exit 1; }

rm -rf "$V.old"
[ -d "$V" ] && mv "$V" "$V.old"
mv "$T/new" "$V"
rm -rf "$V.old"
"$PY" "$R/tools/msvc11/check.py"
