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
- For the units that declare `// MS2-TOOLSET:`, the old compilers the exe's prebuilt libraries were built with. Each
  goes into a gitignored `third_party/` dir and is checked against its manifest (`--check`).
  - vc9: cl 15.00.30729 for the CRI Movie decoder (`tools/fetch-vc9.sh`, from the WDK 7.1 ISO).
  - vc11: cl 17.00.61030 for the Scaleform Video add-on (`tools/fetch-vs2012.sh`, from Microsoft's VS2012.4.iso and
    VS2012_WDX_ENU.iso; `--download` fetches both). It installs the VS2012 Update 4 compiler and VC headers and the
    Windows SDK 8.0 headers.
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

## Resources

By default the `rsrc` stage builds `shim/exe.res` straight from your exe's `.rsrc` tree (`tools/fullexe/rsrc.py`).
`tools/extract_resources.py` turns the same resources into an ordinary resource script for a plain Visual Studio build:

```
python tools/extract_resources.py [MapleStory2.exe]     # -> resources/MapleStory2.rc + one file per resource
python tools/extract_resources.py --compile             # rc.exe (14.16 toolchain) -> resources/MapleStory2.res
```

It checks the exe first (the `tools/check_exe.py` hash and TimeDateStamp 0x62568C46). Icons become real `.ico` files
(`2000 ICON "...ico"`) and bitmaps real `.bmp` files. Dialogs (DIALOGEX), menus and VERSIONINFO are decompiled to `.rc`
text. String tables, HTML, DLGINIT, AFX_DIALOG_LAYOUT and the manifest (`1 24`) are raw includes. Every entry keeps its
LANGUAGE. Compiled with rc.exe, the result has the same entries (type, name, language, data bytes) as `rsrc.py`'s
exe.res: `python tools/extract_resources.py --compare a.res b.res` checks this. To link that .res instead of reading the
exe, pass `-DMS2_RESOURCES_RES=<path>/MapleStory2.res`.

`resources/` holds Nexon's data. It is gitignored, and the publish script refuses any resource file.

## Committed lists instead of exe reads

These options are off by default. Each one replaces an exe read with a committed list of names or addresses (no exe
bytes), and gives the same stage output:

- `-DMS2_IMPORTS_FROM_LIST=ON`: the `implibs` stage builds the import libs from `data/fullexe/imports.tsv` (the exe's
  import names, the shipped `libcef.dll` export names and the extra imports), so it needs neither the exe nor
  `libcef.dll`. `tools/fullexe/implibs.py --write-imports <file>` regenerates the list.
- `-DMS2_CRTINIT_FROM_LIST=ON`: the `crtinit` stage reads the exe's static-initializer table (the `.CRT$XC*`/`.CRT$XI*`
  pointers, in order) from `data/fullexe/crtinit-exe.tsv`; `initorder` then gives the same `--before` list.
  `tools/fullexe/crtinit.py --write-exe-table <file>` regenerates it.

## How much glue is left

`tools/fullexe/gluecount.py` appends a dated row to `progress/glue-metrics.tsv` (alias pairs, ABI adapters, trap
stubs, duplicate symbols, unresolved symbols before the shim, `/FORCE` flags, boot patch files, signature clashes).

## Plain link (prototype)

`cmake/fullexe-plain/` links the exe once and runs no Python at build time. It writes the import-lib `.def` files from
`data/fullexe/imports.tsv`, assembles the CryptoPP MASM objs and compiles `shim_runtime.cpp` itself. Everything else
comes from glue files: the obj list in link order, the `/alternatename` lines and the `/ORDER` list.
`tools/fullexe/plainglue.py write <dir>` writes them from a finished `cmake/fullexe` build. The objs come from that
build's compile cache (`MS2_PLAIN_OBJ_ROOT`), so the compile is not covered yet. The one remaining data stub is
extracted once from your exe with `plainglue.py stubs <exe> <dir>/stubs.tsv <obj>`:

```
cmake -S cmake/fullexe-plain -B build/fullexe-plain -G Ninja -DMS2_PLAIN_GLUE=<dir> -DMS2_PLAIN_OBJ_ROOT=build/progress-<tag> \
      -DMS2_PLAIN_STUBS_OBJ=<obj> -DMS2_RESOURCES_RES=<res> && cmake --build build/fullexe-plain
```

The result is `build/fullexe-plain/out/fullexe-plain.exe`. With `-DMS2_PLAIN_NAME=fullexe3` and the same objs and glue,
it is byte-identical to `link2`'s `fullexe3.exe` except for the link timestamp. The exe's export directory records
the output name, so the default name shifts some `.rdata` bytes.
