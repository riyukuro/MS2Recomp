# Contributing

The work here is recovering the MapleStory2 client function by function. A unit is one original compilation unit,
written as `src/ms2/<path>.cpp`, and it is done when the gates below pass. Batches of units are handed out as GitHub
issues labelled `unit-batch`.

## What you need to supply

None of this is in the repository.

| What | Where it goes |
|---|---|
| The KMS2_DEV x64 `MapleStory2.exe` | `Game Versions/KMS2_DEV/x64/MapleStory2.exe`, or set `MS2_EXE`. Run `tools/check-exe.sh` (Windows: `python tools\check_exe.py`): it must print `OK` (SHA-256 check) |
| MSVC 14.16 (VS2017 15.9, cl 19.16.27054), MFC/ATL MBCS, Windows 10 SDK 10.0.19041 | `third_party/msvc/`, installed with [msvc-wine](https://github.com/mstorsjo/msvc-wine) (`vsdownload.py --manifest` for 15.9, then `install.sh`). `tools/msvc/*` wrap it under Wine. On Windows the real VS2017 v141 install is used instead, see [Windows](#windows-native-no-wsl-no-wine). `tools/check-toolchain.sh` (Windows: `python tools\check_toolchain.py`) compares your install with ours before you start |
| Stock Gamebryo 3.2.0.661 (LightSpeed) source, patched with `engine-patches/` (see below) | `engine/gamebryo/` |
| DirectX SDK June 2010, PhysX 2.8.4 | `third_party/dxsdk/`, `third_party/physx284/` |
| Scaleform GFx 4.1.x SDK headers (the game uses 4.1.18; 4.1.19 headers also work) | `work/scaleform/4.1.19/Scaleform`, or set `MS2_SCALEFORM_SDK`. Optional: without it the placeholder types are used |
| Exe-derived maps: `rtti_classes.tsv`, `rtti_vftables.tsv` | `work/classes/`, regenerated from the exe by `tools/regen-map.sh rtti` (byte-identical; Windows: `python tools\rtti_scan.py "<exe>" work\classes`) |
| `functions.tsv`, `units.tsv` (curated Ghidra map) | shipped in this repository as `data/map/`; the tools use `work/map/` if present, else `data/map/` (or set `MS2_MAP_DIR`). `tools/regen-map.sh ghidra` gives an approximation only |

### Engine patches

`engine-patches/` holds our changes to Gamebryo as ed-style scripts, one `<path>.ed` per file, containing only our
inserted text (never the stock lines), plus `manifest.tsv` with the SHA-256 of every stock and patched file. You supply
the stock Gamebryo 3.2.0.661 tree and apply the patches:

```
tools/apply-engine-patches.sh engine-patches /path/to/stock/gamebryo   # verify stock hashes, patch, verify results
```

On Windows run the Python script directly: `python tools\apply_engine_patches.py engine-patches C:\path\to\stock\gamebryo`. Do not let Git convert line
endings: the repository's `.gitattributes` turns conversion off (`* -text`), so the `.ed` line numbers and the SHA-256 checks
stay valid even with `core.autocrlf=true`.

Copy or move the patched tree to `engine/gamebryo/` (or set `MS2_ENGINE_DIR`). The script refuses and writes nothing if
a stock file hash, an added file or a result hash does not match. 199 files are patched and 41 added (CMake files and
the Nexon-specific `NiFOV*` / `NiStudioShaderContext` classes). Likewise provide Scaleform 4.1.x as in the table.
`tools/engine-patches.py` regenerates the patches (maintainer only; needs the private stock-import history).

Everything is looked up relative to the checkout. To keep a file elsewhere, set the matching variable instead:
`MS2_EXE`, `MS2_MAP_DIR`, `MS2_CLASSES_DIR`, `MS2_THIRD_PARTY`, `MS2_ENGINE_DIR`, `MS2_WINEPREFIX`,
`MS2_SCALEFORM_SDK` (see `tools/ms2paths.py`).

Host: Linux with Wine, CMake 3.20+, Ninja, clang-cl and LLVM tools (`llvm-undname`, `llvm-nm`) on PATH, Python 3 with
`pip install -r requirements.txt`. Put a virtualenv at `.venv/` (the scripts use `.venv/bin/python`). Or native Windows,
next section.

## Windows (native, no WSL, no Wine)

The gates run the same compiler as on Linux, the real `cl.exe`/`link.exe` of Visual Studio 2017 15.9. Nothing in the gate path
needs bash or Wine (`tools/unit-check.sh`, `check-exe.sh`, `check-toolchain.sh` are thin wrappers over `tools/unit_check.py`,
`check_exe.py`, `check_toolchain.py`).

**1. Install**

| What | How |
|---|---|
| Visual Studio 2017 Build Tools **15.9** (cl 19.16.27054, toolset `14.16.27023`) | `vs_buildtools.exe` of the 15.9 channel (https://aka.ms/vs/15/release/vs_buildtools.exe) with the components `Microsoft.VisualStudio.Component.VC.Tools.x86.x64` (MSVC v141 x64/x86 build tools) and `Microsoft.VisualStudio.Component.VC.ATLMFC` (C++ ATL and MFC, includes the MBCS libraries: `mfc140.lib`, not `mfc140u.lib`). Command line: `vs_buildtools.exe --quiet --wait --norestart --nocache --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 --add Microsoft.VisualStudio.Component.VC.ATLMFC` |
| Windows 10 SDK **10.0.19041.0** | VS component `Microsoft.VisualStudio.Component.Windows10SDK.19041` (VS 2019/2022 installer) or the standalone "Windows 10 SDK (10.0.19041.0)" installer; any other SDK version changes headers and is caught by `check_toolchain.py` |
| Alternative: v141 inside VS 2019/2022 | components `Microsoft.VisualStudio.Component.VC.v141.x86.x64`, `Microsoft.VisualStudio.Component.VC.v141.ATL`, `Microsoft.VisualStudio.Component.VC.v141.MFC`. Allowed only if `check_toolchain.py` prints OK: that toolset has been patched separately by Microsoft |
| Git, Python 3.10+, CMake 3.20+, Ninja, LLVM (clang-cl, lld-link, `llvm-nm`, `llvm-undname`) | `winget install Git.Git Python.Python.3.12 Kitware.CMake Ninja-build.Ninja LLVM.LLVM`; all on `PATH` |
| DirectX SDK (June 2010), PhysX 2.8.4 | install them anywhere and link the folders to where the tools look: `mklink /J third_party\dxsdk\DXSDK "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)"`, and `third_party\physx284\PFiles\NVIDIA Corporation\NVIDIA PhysX SDK\v2.8.4_win` to the extracted PhysX 2.8.4 SDK (create the parent folders first) |

**2. Checkout and Python**

    git config core.longpaths true
    git config core.autocrlf false
    python -m venv .venv
    .venv\Scripts\pip install -r requirements.txt

Use `.venv\Scripts\python` for every `python` below (the tools themselves also fall back to the interpreter running them).
Symbolic links are optional: the DirectX header overlay is copied if Windows refuses `mklink` without Developer Mode.

**3. Point the tools at the toolchain.** Nothing to do if Visual Studio is in a default location or known to `vswhere`:
`tools/ms2paths.py` finds the install that has the `14.16.*` toolset, runs `vcvarsall.bat x64 -vcvars_ver=14.16 10.0.19041.0`
once per process and gives `cl`, `link`, `cmake`, `ninja` and `clang-cl` that environment. You can instead start from a
"x64 Native Tools Command Prompt for VS 2017" (then `INCLUDE`/`LIB` are already set and are used as they are). Overrides:

| Variable | Meaning |
|---|---|
| `MS2_VCVARS` | full path of `vcvarsall.bat` |
| `MS2_CL` | full path of the 14.16 `cl.exe` |
| `MS2_VCVARS_VER`, `MS2_WINSDK_VER` | default `14.16` and `10.0.19041.0` |
| `MS2_THIRD_PARTY`, `MS2_EXE`, `MS2_MAP_DIR`, ... | as in the table above (a Windows path is fine) |

`python tools\ms2paths.py show` prints what was found; `python tools\ms2paths.py run cmake ...` and `... shell` run a command or a
shell in the toolchain environment.

**4. Check, then work**

    python tools\check_exe.py                  # OK = right MapleStory2.exe
    python tools\check_toolchain.py            # OK = same compiler binaries and headers as the maintainer; run it before byte-matching
    set MS2_AGENT=yourname                      # PowerShell: $env:MS2_AGENT = "yourname"
    python tools\progress.py --agent yourname --force --functional --check <unit-substring>
    python tools\unit_check.py --functional <unit-substring>

`check_toolchain.py` compares SHA-256 of `cl.exe`, `c1.dll`, `c1xx.dll`, `c2.dll`, `link.exe`, key MFC/ATL/CRT/SDK headers and a
digest of the complete header trees with `tools/toolchain-manifest.tsv`. A mismatch means byte-matching results will not agree
with ours: fix the install first. Native Windows is newer than the Linux/Wine path: if a gate behaves differently from this
document, open an issue with the output of `python tools\ms2paths.py show`.

Not supported on Windows: the full shared builds and merge scripts (`tools/merge.sh`, `regen-map.sh`, the Gamebryo engine stage of
`progress.py` without a unit filter, which needs symlinks) and the runtime/client scripts. Those are maintainer-only.

## Claiming a batch

1. Open an issue labelled `unit-batch` and comment that you take it. Do not start units from a batch someone else holds.
2. Tick nothing yourself; the maintainer ticks a unit when its PR has been applied.
3. If you cannot finish a unit, say which one and why (for example "needs a shared type X") in the issue.

## Working on a unit

A unit's source starts with a header block:

```
// MS2-UNIT: <unit name from the issue>
// MS2-RANGE: 0x14190eac0-0x141910480 .text$mn
// MS2-RANGE: 0x140111d60-0x140111ef1 .text$di
```

Use the ranges from the issue. Every function in them is compiled by the same toolchain and compared byte by byte to
the exe. Write typed, behaviour-equivalent C++ (no Ghidra names such as `param_1` or `plVar1`, no raw offset
arithmetic where a member would do). Where exact bytes will not come out, mark the function
`// MS2-FUNCTIONAL: <reason>` after at most two attempts.

Set `export MS2_AGENT=<yourname>` (Windows: `set MS2_AGENT=<yourname>`) first in every shell that runs the tools. It selects a private cache under
`build/progress-<yourname>/`, so the tools never write the shared `progress/` files.

## The gates

Iterate with:

    python tools/progress.py --agent <yourname> --force --functional --check <unit-substring>

It must print `CHECK OK`. Before you open a PR, run once:

    tools/unit-check.sh --functional <unit-substring>      (Windows: python tools\unit_check.py --functional <unit-substring>)

It must print `functional gate: OK` and `DLL link: OK`. The functional gate means:

- every function in the unit's ranges is either byte-identical (`matched`) or implemented in source (`functional`), no
  `stub`;
- every vftable of the unit's classes is paired with the exe and matches slot by slot;
- the unit raises no symbol conflict with the committed tables;
- both hook DLLs (cl 19.16 and clang-cl) link.

Template glue (STL/ATL instantiations) is paired with `tools/tplpin.py <unit-substring>`.

## Pull requests

- One PR per unit or per batch, changing `src/` only.
- Do not edit `progress/`, `assets/` or anything under `tools/`, `cmake/`. If you need a new symbol-table row, list it in
  the PR description.
- PRs are not merged on GitHub: the mirror is regenerated from the maintainer's repository. The maintainer applies the
  PR locally after re-running the gates and credits you in the commit.
- State in the PR which units it covers and the output of both gates (exact/functional counts).
- Do not add anything derived from the exe other than the recovered source: no disassembly dumps, no byte listings,
  no decompiler output.
