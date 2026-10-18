"""Where the gate tools find the files that are not in the repository. Every default is the in-tree location used by
the maintainer's checkout; an external checkout points the environment variables at its own copies:

  MS2_EXE          the original x64 MapleStory2.exe (KMS2_DEV build; tools/check-exe.sh verifies it)
  MS2_MAP_DIR      functions.tsv, units.tsv (exe-derived function/unit map; default work/map, else the published data/map)
  MS2_CLASSES_DIR  rtti_classes.tsv, rtti_vftables.tsv (tools/rtti_scan.py <exe> <dir>)
  MS2_THIRD_PARTY  MSVC 14.16 + Windows SDK (msvc-wine layout: bin/x64/cl, VC/, Windows Kits/), dxsdk/, physx*/
  MS2_ENGINE_DIR   Gamebryo 3.2.0.661 + engine patches (the directory that holds gamebryo/; stock source + engine-patches/, see CONTRIBUTING.md)
  MS2_WINEPREFIX   Wine prefix for the MSVC toolchain (MS2_MSVC_WINEPREFIX also accepted)
  MS2_SCALEFORM_SDK  Scaleform GFx 4.1.x SDK headers (the Scaleform/ directory)
"""
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def _env(name, default):
    return os.environ.get(name) or default


EXE = _env("MS2_EXE", os.path.join(ROOT, "Game Versions", "KMS2_DEV", "x64", "MapleStory2.exe"))
# work/map is the maintainer's live copy; data/map is the published snapshot (tools/publish-github.sh syncs it)
_WORK_MAP = os.path.join(ROOT, "work", "map")
MAP_DIR = _env("MS2_MAP_DIR", _WORK_MAP if os.path.exists(os.path.join(_WORK_MAP, "functions.tsv")) else os.path.join(ROOT, "data", "map"))
CLASSES_DIR = _env("MS2_CLASSES_DIR", os.path.join(ROOT, "work", "classes"))
THIRD_PARTY = _env("MS2_THIRD_PARTY", os.path.join(ROOT, "third_party"))
ENGINE_DIR = _env("MS2_ENGINE_DIR", os.path.join(ROOT, "engine"))
WINEPREFIX = _env("MS2_WINEPREFIX", _env("MS2_MSVC_WINEPREFIX", os.path.join(ROOT, "work", "wineprefix-msvc")))
SCALEFORM_SDK = os.path.join(ROOT, "work", "scaleform", "4.1.19", "Scaleform")   # MS2_SCALEFORM_SDK read by progress.py
FUNCTIONS_TSV = os.path.join(MAP_DIR, "functions.tsv")
UNITS_TSV = os.path.join(MAP_DIR, "units.tsv")
RTTI_CLASSES = os.path.join(CLASSES_DIR, "rtti_classes.tsv")
RTTI_VFTABLES = os.path.join(CLASSES_DIR, "rtti_vftables.tsv")
CL = os.path.join(THIRD_PARTY, "msvc", "bin", "x64", "cl")
