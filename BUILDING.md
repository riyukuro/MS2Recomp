# Building the full executable

One command builds `fullexe<N>.exe` from this checkout plus SDKs you supply yourself. No SDK, object file or generated
import library is ever part of the repository.

```
cmake --preset fullexe && cmake --build build/fullexe
```

The result is `build/fullexe/out/fullexe3.exe` (link log and map next to it). Rebuilding after an edit recompiles only
the changed translation units; the link reads every object where the compile cache keeps it (a response file), so no
copy of the objects is made.

## Prerequisites

- Linux with Wine, or Windows with the VS2017 v141 toolset; the MSVC 14.16 cl/link and the Windows SDK 10.0.19041
  (`tools/toolchain-manifest.tsv` pins them, `tools/check_toolchain.py --quick` verifies them).
- CMake 3.25 or newer, Ninja, Python 3 with the packages of `tools/` (the default is `.venv/bin/python`; override with
  `-DMS2_PYTHON=...`), LLVM binutils (`llvm-nm`, `llvm-undname`).
- The original x64 `MapleStory2.exe` (KMS2_DEV build): `-DMS2_EXE=<file>` or the `MS2_EXE` environment variable, else `Game Versions/KMS2_DEV/x64/MapleStory2.exe` in the checkout (verified by `tools/check_exe.py`).
- One free heavy slot (`tools/heavy_lock.py`): the link and the compile stage take it. The slots are files in `work/locks/`;
  a second checkout on the same machine shares them with `MS2_LOCK_DIR=<first checkout>/work/locks`.
- About 60 GB of free disk and 16 GB of RAM for a clean build.

## Your SDKs

Each root is a CMake cache variable. Left empty, it defaults to the in-tree location that `CONTRIBUTING.md` describes.
At configure time every root is checked against `cmake/sdk-manifest.txt`, which lists file names and SHA-256 values only;
a missing or different file stops the configure with the variable name.

| Variable | Contents |
| --- | --- |
| `MS2_GAMEBRYO_ROOT` | the directory that holds `gamebryo/`: Gamebryo LightSpeed 3.2.0.661 after `tools/apply-engine-patches.sh engine-patches <dir>/gamebryo`, and `fmt-ms2/`: `format.cc` and `format.h` of upstream cppformat (fmt) commit 5ca3d00e2 (BSD 2-clause) after `tools/apply-engine-patches.sh fmt-patches <dir>/fmt-ms2` (default `engine/`) |
| `MS2_DXSDK_ROOT` | DirectX SDK June 2010; must be `dxsdk/DXSDK` under the `MS2_MSVC_ROOT` directory (see below) |
| `MS2_PHYSX_ROOT` | PhysX 2.8.4 SDK; must be `physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win` under `MS2_MSVC_ROOT` |
| `MS2_CEF_ROOT` | CEF 3.3396 binary distribution (`cef_binary_3.3396.1786.gd3e36d0_windows64_minimal`); must be under `src/` of `MS2_MSVC_ROOT` |
| `MS2_PATHENGINE_ROOT` | PathEngine evaluation sources; must be `src/pathengine-sigmaco` under `MS2_MSVC_ROOT` (game sources include them as `<pathengine-sigmaco/...>`, see below) |
| `MS2_MSVC_ROOT` | a directory in the `third_party/` layout that the tools read (`MS2_THIRD_PARTY`): `msvc/` (MSVC 14.16 + Windows SDK, msvc-wine), `dxsdk/`, `physx284/`, and under `src/` the statically linked library sources `cryptopp562`, `jpeg-6b`, `libpng-1.6.17`, `lua-5.1.4`, `expat-2.0.1`, `zlib-1.2.3`, `pcre-8.21`, `pathengine-sigmaco` and the CEF distribution, plus `fmod44464/` and `razer/` (headers); default `third_party/` |

The library sources are the upstream releases, unmodified, and none of them is redistributed here. `pcre-8.21` is upstream PCRE 8.21 (BSD) prepared the way its `NON-UNIX-USE` describes for a build without `configure`: `cp pcre.h.generic pcre.h` and `cp pcre_chartables.c.dist pcre_chartables.c`; the build settings are `-D` defines in `data/engine/units-lib-pcre.json`, so no `config.h` is needed.

Example: `cmake --preset fullexe -DMS2_GAMEBRYO_ROOT=<dir> -DMS2_MSVC_ROOT=<dir>`.

Game sources name these SDKs by include path only (`<cryptopp562/...>`, `<pathengine-sigmaco/...>`, `<zlib-1.2.3/...>`,
`<fmod44464/...>`, `<razer/...>`; the include roots are `MS2_THIRD_PARTY_INCLUDE_DIRS` in `cmake/ms2-engine-flags.cmake`),
so the roots may live anywhere.

## Stages

Each is a CMake target that runs the matching `tools/fullexe` script unchanged, in this order: `compile` (incremental
per-unit cache), `plan`, `implibs`, `asm`, `link0` (open link), `defsyms`, `analyze0`, `alias` and `order` (generated
glue), `link1`, `analyze1`, `shim` and `rsrc` (generated stubs, ABI adapters, resources), `crtinit`, `initorder`, and
`link2` (the closed link). `cmake --build build/fullexe --target <stage>` runs the chain up to that stage.

## How much glue is left

`tools/fullexe/gluecount.py` appends a dated row to `progress/glue-metrics.tsv` (alias pairs, ABI adapters, trap
stubs, duplicate symbols, unresolved symbols before the shim, `/FORCE` flags, boot patch files, signature clashes).
