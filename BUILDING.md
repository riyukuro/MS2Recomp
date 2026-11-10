# Building MapleStory2.exe

The build compiles every object from this checkout and links a replacement `MapleStory2.exe`. You supply the SDKs
yourself (below). The build never reads the original exe. No SDK, object file or generated import library is ever part
of the repository.

Windows, Visual Studio 2022: File > Open > Folder, pick the checkout. VS selects the `windows` preset. Then Build >
Build All. Or, in a developer prompt for the 14.16 toolset (see [Windows](#windows)):

```
cmake --preset windows
cmake --build --preset windows
```

Linux, MSVC 14.16 under Wine:

```
cmake --preset linux
cmake --build --preset linux
```

The `linux` preset's condition is "the host is not Windows", so cmake offers it on every other host as well; Linux is
the only one described here.

The result is `build/<preset>/out/MapleStory2.exe`, a copy of `fullexe-plain.exe` (its `.map` is beside it). A clean
build has about 3,700 steps; the 2026-11-10 one took about 12 minutes at `-j12` on Linux. Header dependencies are not
tracked: after a header edit, rebuild from clean.

The build uses only this checkout:

- the compile commands come from the glue in `data/fullexe/plain`, made again from the checkout at configure (see
  [Glue derived at configure](#glue-derived-at-configure));
- the `/ORDER` list is unpacked from the committed `order.tar.xz`;
- the resources come from the stand-in `cmake/fullexe-plain/standin/standin.rc` (see [Resources](#resources));
- the import libs are written from `data/fullexe/imports.tsv`;
- `tools/fullexe/shim_runtime.cpp` is compiled with only what the exe needs to run: the entry point and a trap for any
  function no object defines, which writes the name to `fullexe-trap.log` beside the exe and exits;
- the game units (the sources under `src/ms2`) are compiled with `/DMS2_STANDALONE`, so the `MS2_REPLACE*` lines
  that register each function with the maintainers' hook DLL expand to nothing and the exe holds no registration
  (see `MS2_PLAIN_STANDALONE` under [Options](#options)).

The exe-reading build that the maintainers check against the original exe is described under
[Maintainer builds](#maintainer-builds-with-the-original-exe). You do not need it.

## Prerequisites

- **Windows**: Visual Studio 2022 (Community is enough), see [Windows](#windows) for the components. CMake and Ninja
  come with it, and Python 3 (python.org; needed to make the engine trees and to derive the glue at configure).
- **Linux**: Wine, CMake 3.21 or newer (the version `CMakePresets.json` asks for), Ninja, and MSVC 14.16 with the
  Windows SDK 10.0.19041 installed with
  [msvc-wine](https://github.com/mstorsjo/msvc-wine) into `third_party/msvc/`. The compilers run in the Wine prefix
  named by the `MS2_WINEPREFIX` environment variable (default `<checkout>/work/wineprefix-msvc`).
- MSVC 14.16 cl/link and the Windows SDK 10.0.19041 (`tools/toolchain-manifest.tsv` pins them,
  `tools/check_toolchain.py --quick` verifies them).
- For the units that declare `// MS2-TOOLSET:`, the old compilers the exe's prebuilt libraries were built with. Each
  goes into a gitignored `third_party/` dir and is checked against its manifest (`--check`). On Linux they are
  required. On Windows each one is optional: without it, the 14.16 `cl` builds those objects (see [Windows](#windows)).
  - vc9: cl 15.00.30729 for the CRI Movie decoder (`tools/fetch-vc9.sh`, from the WDK 7.1 ISO).
  - vc11: cl 17.00.61030 for the Scaleform Video add-on (`tools/fetch-vs2012.sh`, from Microsoft's VS2012.4.iso and
    VS2012_WDX_ENU.iso; `--download` fetches both). It installs the VS2012 Update 4 compiler and VC headers and the
    Windows SDK 8.0 headers.
  - 1414, 1415: the MSVC 14.14 and 14.15 toolsets for some engine libraries, in `third_party/msvc147/` and
    `third_party/msvc148/`.
- Python 3 with the packages of `requirements.txt` makes the glue from the checkout at configure. The default is
  `<checkout>/.venv`; override it with `-DMS2_PLAIN_PYTHON=<python>`. Without it, configure warns and links the
  committed glue. That works only for the commit the glue was made from, such as the published tip.
- The Scaleform submodule: `git submodule update --init` (`src/ms2/scaleform` is a submodule, and a few hundred objects
  compile from it).
- About 20 GB of free disk for the build tree (a clean build measured 16 GB), not counting your SDK trees, and 16 GB
  of RAM.

## Your SDKs

Two CMake cache variables name the SDK directories. Left empty, they default to `third_party/` and `engine/` in the
checkout.

| Variable | Contents |
| --- | --- |
| `MS2_MSVC_ROOT` | a directory in the `third_party/` layout: `msvc/` (MSVC 14.16 + Windows SDK, msvc-wine; Linux only), the old compilers above, `gamebryo/APPDIR/Source` (the stock Gamebryo 3.2.0.661 Source, unpatched), `gamebryo/APPDIR/Build/GameFramework/Win32/VC90` (the same SDK's generated `*_LuaWrap_Release.cpp` files under `egfLua/Release` and `ecrPhysXLua/Release`; 12 objects compile from them), `dxsdk/DXSDK` (DirectX SDK June 2010), `physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win` (PhysX 2.8.4 SDK), and under `src/` the statically linked library sources `cryptopp562`, `jpeg-6b`, `libpng-1.6.17`, `lua-5.1.4`, `expat-2.0.1`, `zlib-1.2.3`, `pcre-8.21`, `pathengine-sigmaco` (PathEngine evaluation sources) and the CEF 3.3396 binary distribution (`cef_binary_3.3396.1786.gd3e36d0_windows64_minimal`), plus `fmod44464/` and `razer/` (headers) |
| `MS2_PLAIN_ENGINE` | the directory that holds `gamebryo/`: Gamebryo LightSpeed 3.2.0.661 after `tools/apply-engine-patches.sh engine-patches <dir>/gamebryo`, `fmt-ms2/`: `format.cc` and `format.h` of upstream cppformat (fmt) commit 5ca3d00e2 (BSD 2-clause) after `tools/apply-engine-patches.sh fmt-patches <dir>/fmt-ms2`, and `gamebryo-v2525/`, made from the pristine Source by `engine-patches-v2525/` (configure does this; see "Engine trees" below) |

The library sources are the upstream releases, unmodified, and none of them is redistributed here. `pcre-8.21` is upstream PCRE 8.21 (BSD) prepared the way its `NON-UNIX-USE` describes for a build without `configure`: `cp pcre.h.generic pcre.h` and `cp pcre_chartables.c.dist pcre_chartables.c`; the build settings are `-D` defines in `data/engine/units-lib-pcre.json`, so no `config.h` is needed.

Example: `cmake --preset linux -DMS2_MSVC_ROOT=<dir> -DMS2_PLAIN_ENGINE=<dir>`. In Visual Studio, put such overrides in
a `CMakeUserPresets.json` preset that inherits `windows`.

When the SDKs live outside the checkout, `third_party/` at the checkout's top level must still lead to them (a symlink
or a junction to `MS2_MSVC_ROOT`): some sources reach SDK headers through relative symlinks (`src/ms2/cef/include` ->
`../../../third_party/src/cef_binary_...`).

### Engine trees

The build uses two trees made from one stock Gamebryo 3.2.0.661 tree, and the order matters:

1. `gamebryo-v2525/` is made from the pristine `APPDIR/Source` with `engine-patches-v2525/`:
   `tools/apply-engine-patches.sh engine-patches-v2525 <third_party>/gamebryo/APPDIR/Source <engine dir>/gamebryo-v2525`
   (Windows: `python tools\apply_engine_patches.py ...` with the same arguments). It writes only to the third argument.
   Configure runs this step itself (`cmake/v2525.cmake`) when `gamebryo-v2525/` is missing and Python is found, and stops
   if `engine-patches-v2525/` changed since (delete `gamebryo-v2525/` and configure again).
2. `engine-patches/` is applied to a separate copy of `APPDIR/Source`, `<engine dir>/gamebryo/`.

The SDK copy under `<third_party>/gamebryo/` must stay unpatched: the build also compiles about 4,000 of its files as
they are, and step 1 checks every stock hash and refuses on a patched tree. Never apply `engine-patches/` to it in place.

Game sources name these SDKs by include path only (`<cryptopp562/...>`, `<pathengine-sigmaco/...>`, `<zlib-1.2.3/...>`,
`<fmod44464/...>`, `<razer/...>`; the include roots are `MS2_THIRD_PARTY_INCLUDE_DIRS` in `cmake/ms2-engine-flags.cmake`),
so the roots may live anywhere.

## Options

- `MS2_RESOURCES_RES=<file>`: link this `.res` instead of the stand-in (see [Resources](#resources)).
- `MS2_SHIM_DIAGNOSTICS=ON`: also build the shim's diagnostics into the exe. These are a vectored crash logger with a
  stack-overflow reporter and a `/GS` failure hook, a wrapper of `SetUnhandledExceptionFilter`, a hang sampler, and
  boot milestones (`AfxWinMain`, the first window, the message loop, `LoadLibrary`). All of them write to
  `fullexe-trap.log`. They change nothing the client does. The maintainers' test builds have them on.
- `MS2_PLAIN_STANDALONE=OFF`: compile the game units without `/DMS2_STANDALONE` and link with `/opt:ref`, as the
  maintainer build does. The default, ON, leaves the hook registrations out: without it every `MS2_REPLACE*` line adds
  a record, a thunk and an initializer that calls the shim's no-op `Register` (17,724 registrations). A registration
  is also the only reference to a function whose callers are not written yet, so ON links with `/opt:noref` to keep
  those functions; `/opt:noref` also keeps every other unreferenced function. Measured on 2026-11-09, ON against OFF:
  the exe is 55.7 MB against 51.8 MB (`.text` 38.9 against 33.9 MB, `.data` 1.4 against 2.7 MB), it places 221,275
  of the original's functions against 195,981, and it has 36,432 static initializers against 71,873 (36,431 since
  2026-11-10, when a constant member pointer of ours lost its initializer). Four of those initializers are not in the
  OFF exe, because `/opt:ref` drops them as unreferenced: the ATL objects `_AtlComModule`, `_AtlWinModule`,
  `InitializeCAtlStringMgr` and `InitializeCImage`. The original exe runs these four once each as well, later in its
  table. Both exes reach the field the same way. Setting the option ON when configuring
  `cmake/fullexe-plain` directly has the same effect; there the default is OFF.
- `MS2_PLAIN_DERIVE=AUTO|ON|OFF`: make the glue at configure (see below). `AUTO`, the default, falls back to the
  committed glue without a usable Python; `ON` stops instead; `OFF` always links the committed glue.
- `MS2_PLAIN_ORDER=OFF`: let the linker lay functions out in its own order instead of the original's.
- `MS2_PLAIN_NAME=<name>`: the linked exe's name (default `fullexe-plain`). The exe's export directory records it.
- `MS2_CL_1414`, `MS2_CL_1415`, `MS2_CL_vc9`, `MS2_CL_vc9c`, `MS2_CL_vc9v`, `MS2_CL_vc11` (Windows): the old compilers,
  see [Windows](#windows).

## Resources

By default the link takes the stand-in `cmake/fullexe-plain/standin/standin.rc`, which rc compiles to
`<build>/standin.res`. The stand-in is written for this repo and holds nothing of the exe's:

- its own icon 2000 (`standin.ico`, drawn by `mkicon.py` there);
- manifest 1 (Common Controls 6, asInvoker, DPI aware);
- plain English dialogs with the control IDs the client binds: 3000 (out of memory: buttons 8 and 10, SysLink 1034,
  text 1035), 3001 (error: button 11, text 1036), 148 and 150 (a WebBrowser control, 1236 and 1237);
- a VERSIONINFO reading "MS2Recomp stand-in".

It lacks the exe's dev dialogs, menus, bitmaps and strings, and its dialogs look different.

If you own the original exe, `tools/extract_resources.py` turns its resources into an ordinary resource script:

```
python tools/extract_resources.py [MapleStory2.exe]     # -> resources/MapleStory2.rc + one file per resource
python tools/extract_resources.py --compile             # rc.exe (14.16 toolchain) -> resources/MapleStory2.res
```

It checks the exe first (the `tools/check_exe.py` hash and TimeDateStamp 0x62568C46). Icons become real `.ico` files
(`2000 ICON "...ico"`) and bitmaps real `.bmp` files. Dialogs (DIALOGEX), menus and VERSIONINFO are decompiled to `.rc`
text. String tables, HTML, DLGINIT, AFX_DIALOG_LAYOUT and the manifest (`1 24`) are raw includes. Every entry keeps its
LANGUAGE. Compiled with rc.exe, the result has the same entries (type, name, language, data bytes) as `rsrc.py`'s
exe.res: `python tools/extract_resources.py --compare a.res b.res` checks this. Pass it with
`-DMS2_RESOURCES_RES=<path>/MapleStory2.res`.

`resources/` holds Nexon's data. It is gitignored, and the publish script refuses any resource file.

## Windows

Tested on Windows 10 with VS 2022 Community from the VS GUI's Open Folder: on 11-03 it built all 3731 steps of that
day's glue with every `MS2_CL_<tool>` on the 14.16 fallback, and the exe logged in on a local server and entered a
field. On 11-09, from the command line (an elevated ssh session, the 14.16 developer prompt, a source export of
that day's tree with no git, no exe anywhere, every `MS2_CL_<tool>` on the fallback) and following the steps below:
configure derived the glue (3674 objs, the committed `compile.tsv` but for `\` in paths), and a clean
`cmake --build --preset windows` ran 3734 steps with none failed in 14.6 min on 8 cores. In that build no game unit got
`/DMS2_STANDALONE` (a Windows path-form bug, fixed since); the rebuild with the fix recompiled the 1983 game units
(9.4 min, none failed). The exe (55.6 MB) started under WARP and reached the login screen.

- Install VS 2022 with the "Desktop development with C++" workload and these individual components: MSVC v141 VS 2017
  C++ x64/x86 build tools (14.16), C++ ATL for v141, C++ MFC for v141, C++ CMake tools for Windows, and the Windows 10
  SDK (10.0.19041). Install Python 3 from python.org as well (3.12 was tested; tick "Add python.exe to PATH"): the
  engine trees are made with it (steps below), and configure derives the glue with `<checkout>\.venv`. No Wine is
  needed. Without a `.venv`, configure links the committed glue instead of deriving it, which works only for the commit
  that glue was made from.
- Outside the VS GUI, use a developer prompt for the 14.16 toolset: `"C:\Program Files\Microsoft Visual
  Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" -vcvars_ver=14.16`. A plain VS 2022 prompt gives cl 14.4x,
  which is not the build's compiler. Check with `cl` (it prints 19.16). The GUI selects the v141 toolset from the
  preset by itself.
- `MS2_CL_1414`, `MS2_CL_1415`, `MS2_CL_vc9`, `MS2_CL_vc9c`, `MS2_CL_vc9v` and `MS2_CL_vc11` may name those compilers'
  `cl.exe` (or a `.cmd` wrapper that sets that compiler's own `INCLUDE`/`LIB`). Each one left unset gives a CMake
  warning and the 14.16 `cl` builds those rows instead; the exe then works but is not byte-identical. CMake adds the
  `/I<checkout>\src` (and for `vc9v` the `/FI tools\msvc9v\compat.h`) that the Linux wrappers add, and builds the
  fallback `vc*` rows `/MD /Zp8`. `/MD`: their flag sets name no CRT, and cl 19.16's default `/MT` would pull
  `libcpmt.lib` into the link (LNK2038/LNK2005). `/Zp8` (the cl rows' layout option): at the default `/Zp16` cl 19.16
  rounds a derived class past a base with an `align(16)` member where VC9 fills the base's tail padding, so
  `sfr_video_02` would stop at its `ShapeDataFloatMP size` static_assert (0xa0, the exe's 0x90). With both, every
  `vc*` row compiles under the fallback with its static_asserts intact, and an all-fallback build links and runs.
- Command lines reach 9.6 KB, over cmd.exe's limit, so on Windows each flag set goes into a response file
  (`<build>/out/cl/<id>.rsp`).
- `tree.tsv` symlinks need Developer Mode or an elevated prompt; without it CMake copies the target instead. CMake
  writes the link targets with backslashes (a Windows symlink whose target has `/` does not resolve).
- Flag-set arguments containing `$(` (unexpanded `$(GB_SDK)` include dirs that name no dir) are dropped, since Ninja and
  MSBuild would both read them as variables.
- Code-page warnings (C4819, C4828: the sources hold cp949 text) are harmless.

Steps:

1. Clone the repo and fetch the Scaleform submodule: `git clone <url> <checkout>`, then `git submodule update --init`
   in `<checkout>`. For a byte-identical exe, clone to the reference checkout path (see
   [What matches](#what-matches); a `subst Z:` drive works).
2. Put the SDK tree at `<checkout>\third_party` (or a junction to it; see [Your SDKs](#your-sdks) for its layout),
   with the stock Gamebryo Source unpatched at `third_party\gamebryo\APPDIR\Source`.
3. Make the venv, in `<checkout>`: `python -m venv .venv`, then `.venv\Scripts\python -m pip install -r
   requirements.txt`.
4. Make the engine trees under `<checkout>\engine` (see "Engine trees"). `gamebryo-v2525` is made by configure (step
   6). The patched Gamebryo copy and fmt, in `<checkout>`:
   ```
   robocopy third_party\gamebryo\APPDIR\Source engine\gamebryo /E
   python tools\apply_engine_patches.py engine-patches engine\gamebryo
   mkdir engine\fmt-ms2
   copy <fmt checkout at 5ca3d00e2>\format.cc engine\fmt-ms2
   copy <fmt checkout at 5ca3d00e2>\format.h engine\fmt-ms2
   python tools\apply_engine_patches.py fmt-patches engine\fmt-ms2
   ```
   (robocopy exits 1 when it copied files; that is success.) Each `apply_engine_patches.py` run checks the hashes
   of what it wrote.
5. `src\ms2\cef\include` and `src\ms2\cef\libcef_dll` are git symlinks. Without symlink support git checks each
   out as a small text file, and the CEF units then fail to find their headers (`lib_cef_tail` stops at
   `libcef_dll/ctocpp/callback_ctocpp.h`). Replace both with junctions, in `src\ms2\cef`:
   ```
   del include
   mklink /J include ..\..\..\third_party\src\cef_binary_3.3396.1786.gd3e36d0_windows64_minimal\include
   del libcef_dll
   mklink /J libcef_dll ..\..\..\third_party\src\cef_binary_3.3396.1786.gd3e36d0_windows64_minimal\libcef_dll
   ```
6. In the VS GUI: File > Open > Folder, pick `<checkout>`. VS selects the `windows` preset and configures with the
   14.16 `cl` and its own Ninja. Then Build > Build All. The exe is `<checkout>\build\windows\out\MapleStory2.exe`.
   Or, in the 14.16 developer prompt, `cmake --preset windows` then `cmake --build --preset windows` in `<checkout>`.
   Other SDK locations: `-DMS2_MSVC_ROOT=<dir> -DMS2_PLAIN_ENGINE=<dir>`, with forward slashes.

On a Windows 10 install without recent updates, VS 2022 may fail to start ("Could not start Visual Studio",
`ControllerConnectionException`). Its .NET runtime stops with "Your Windows doesn't fully support CET". Install the
Windows updates, or turn off the shadow-stack mitigation for the ServiceHub exes in an elevated PowerShell:
`gci "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\ServiceHub" -r -fi *.exe |
% { Set-ProcessMitigation -Name $_.Name -Disable UserShadowStack }`.

## How the build works

`cmake/fullexe-plain/` (the directory the root presets build) links the exe once and runs no Python at build time. At
configure it writes the import-lib `.def` files from `data/fullexe/imports.tsv`. It also writes one custom command per
object, from the glue's compile list. At build time it compiles the objects, assembles the CryptoPP MASM objs and
compiles `shim_runtime.cpp`. Then one closed link takes the objects in the glue's order (`objs.txt`), the
`/alternatename` lines (`alias.rsp`) and the `/ORDER` list. `order.txt` (32 MB) is committed as `order.tar.xz`
(1.7 MB) and unpacked into `<build>/glue/` at configure; `MS2_PLAIN_ORDER` is on when either file exists.

The glue files in `data/fullexe/plain/` come from the newest maintainer build that linked and passed its smoke test.
Each publish refreshes them. `stubs.tsv` lists the data stubs that build needed (names and addresses only). Every
global has a definition now, so it lists none, and the link takes no stub obj. A data stub that comes back in the
exe's `.bss` makes an obj of zero fill only (no exe bytes), committed as `data/fullexe/plain/stubs.obj`, the default of
`MS2_PLAIN_STUBS_OBJ`.

### Glue derived at configure

When the glue dir has `link.tsv`, configure makes the glue from the checkout itself (`MS2_PLAIN_DERIVE`: `AUTO`, the
default, `ON` or `OFF`). It runs `tools/fullexe/plainglue.py derive <build>/glue-derived --base <glue dir>` with
`MS2_PLAIN_PYTHON` (default `<root>/.venv`; it needs the packages of `requirements.txt`) and links that
glue. Without a usable Python, `AUTO` warns and links the committed glue; `ON` stops. derive reads no exe and no obj
cache:

- `link.tsv`, the link plan, as `plan.py` makes it: one obj per git-tracked `src/ms2` source with `MS2-UNIT`, placed at
  the `NO-EXE` place, else the lowest `progress/status.tsv` VA, else the lowest `MS2-RANGE` (units in the NM zone
  0x14156a020-0x14160a7f0 are left out); one obj per engine and library unit of `data/engine/units-gb.json` and
  `units-lib-*.json` (one entry per unit spelling, at the unit's lowest `status.tsv` VA); then the closure objs;
- `before.tsv`: `initorder.py`'s `--before` rules from the exe's static-initializer table
  (`data/fullexe/crtinit-exe.tsv`, each entry's unit from `status.tsv`, else from the `data/map/units.tsv` ranges);
- `objs.txt`: `link.tsv` sorted as `plan.py` sorts and moved by the `before.tsv` rules as `link.py --before` moves them;
- `compile.tsv`, `flags.tsv`, `tree.tsv`: as `plainglue.py compile` writes them (from `progress.py` and `gbtree.py`),
  without the `.deps` check;
- `order.txt`: `order.py`'s list from `data/map/functions.tsv` and the symbol tables, not filtered to the names the objs
  define, so the link adds `/ignore:4037`; with `MS2_PLAIN_STANDALONE` the `ms2::hook::detail` helper names are
  left out (`derive --standalone`), since that exe holds no hook code;
- `stubs.obj`: zero fill from `stubs.tsv`, none when it lists no stub; `alias.rsp` and `stubs.tsv` are copied.

`linkfacts.tsv` is the only glue input taken from an exe-reading build (no exe bytes: names, VAs and paths). It holds
what the repository does not record:

- `pick`: an engine unit with two `units-gb.json` entries linked from the one that is not the default (the lowest
  `recipe:name`); the build chose it from the gate's pair counts, which are not committed;
- `va`: an engine or library unit with no `status.tsv` row, placed at the VA of its gate pairs (shared COMDATs that
  only the gate pairs with that unit);
- `closure`: an obj no unit names whose symbols the link needs; finding it takes the objs' COFF symbol tables;
- `noinit`: a unit the exe's static-initializer table names that has no initializer of ours (its init comes from
  another obj in the link, such as `atlbase.obj`), so it gets no `before.tsv` rule; that takes the linked objs.

A new game unit needs no refresh, in the maintainer tree or in the published repo: it derives at the next configure,
placed by its `MS2-NO-EXE` line, else its `status.tsv` rows, else its `MS2-RANGE`. A source added, renamed or removed
at a later commit is picked up by the next build, which re-runs configure (an edit to an existing source's `MS2-UNIT`
or `MS2-RANGE` line needs a re-configure by hand).

A new engine or library unit (a new `units-gb.json` or `units-lib-*.json` entry) is different:

- In the maintainer tree it is linked once `progress/status.tsv` has a row for it, or with a hand-added `va` row in
  `linkfacts.tsv`. With neither, derive leaves it out without a message: configure passes, and the link fails only
  if something refers to a symbol that unit alone defines.
- `progress/status.tsv` is not in the published repo. There, and with `--committed-tables`, derive reads the
  committed `link.tsv` and `before.tsv` and takes the engine and library objs from `link.tsv` alone. A new engine or
  library unit is left out, again without a message, until a glue refresh (or a hand-added `link.tsv` row) names it.
  A `linkfacts.tsv` row has no effect there.

A new closure obj or a new twin pick also needs a refresh (or a hand-added `linkfacts.tsv` row). Checked on
2026-11-10 in a scratch checkout with one new game source and one new `units-gb.json` entry, by running derive and
the `linux` preset's configure; nothing was compiled or linked. Checked on the 2026-11-08 glue:
derive gave the committed glue's `link.tsv`, `before.tsv`, `objs.txt`, `compile.tsv`, `flags.tsv`, `tree.tsv` and
`stubs.obj` byte for byte, and its `order.txt` filtered to the reference names was the reference `order.txt`.

So with Python, a commit after the last glue refresh builds too, unless it adds an engine or library unit whose
symbols the link needs (see above). With the committed glue alone (no Python, or `-DMS2_PLAIN_DERIVE=OFF`), only the
commit the glue was made from builds: a renamed, added or removed unit breaks the compile or the link (LNK1120).
`data/fullexe/plain/commit` records the maintainer's build id only.

### Compile list

`compile.tsv`, `flags.tsv` and `tree.tsv` give the cl command of every obj in `objs.txt`:

- `compile.tsv`: obj, tool, working dir, source, flag set. The tool is `cl` (14.16) or the unit's `MS2-TOOLSET`
  (`vc9`, `vc9c`, `vc9v`, `vc11`, `1414`, `1415`). Game units carry their `MS2-FLAGS` profile; engine and library units
  their `data/engine` flags.
- `flags.tsv`: one row per distinct flag set (no `/Fo`, no `/showIncludes`).
- `tree.tsv`: the generated include dirs those commands name (`build/gb-tree` and the DirectX overlays), as symlinks or
  one-line files.

Paths are written as `${TP}`, `${ENGINE}`, `${GEN}` and `${ROOT}`. The build fills them from `MS2_MSVC_ROOT`,
`MS2_PLAIN_ENGINE`, `MS2_PLAIN_GEN` and `MS2_PLAIN_CHECKOUT`, recreates `tree.tsv` under `MS2_PLAIN_GEN`, and makes one
custom command per obj into `<build>/cache`. MS2_PCH=1 builds are not supported.

### What matches

Compiled from the same checkout and SDKs, every obj's code, data, relocations and symbols are identical to those of
the maintainer build's compile cache (checked on 83 objs: 50 game, 10 vc9, 3 vc11, 10 engine, 10 Scaleform). Only the
`/Z7` debug sections differ, and only in recorded paths: the obj's own `/Fo` path, the `${GEN}` dir and the command
line (no `/showIncludes`). The link uses `/debug:none`, so those sections do not reach the exe. The checkout path does
reach the exe, though: `__FILE__` strings (asserts, `MS2Ptr` and engine logging; about 110, or about 17.7k with
`-DMS2_PLAIN_STANDALONE=OFF`, where each registration stores one) hold the source path as
spelled on the compiler command line, and the anonymous-namespace names (`?A0x<hash>`) hash it, which also moves
`/ORDER` matches. A build from another path gave an exe 37,888 bytes larger. Byte identity needs the same checkout
path, with `MS2_MSVC_ROOT` and `MS2_PLAIN_ENGINE` spelled as in the reference build, the exe's own `.res` (the
stand-in changes `.rsrc`), `-DMS2_PLAIN_STANDALONE=OFF`, `-DMS2_SHIM_DIAGNOSTICS=ON` and
`-DMS2_PLAIN_NAME=fullexe3`. For this project's reference
builds the path is the maintainer's build checkout as the exe's `__FILE__` strings spell it (a `z:` path under Wine;
the link's `/out` paths use a second spelling of the same dir through a symlink), with its `third_party` and `engine`
under it. Any other path builds a working exe that differs in its `__FILE__` strings and layout.

A full build on Linux (the 10-31 glue: 3637 steps, about 85 minutes at `-j16`) of a clean worktree with that build's
glue and `-DMS2_PLAIN_NAME=fullexe3` gave an exe identical to `link2`'s `fullexe3.exe` except for 4 bytes, the link
timestamps in the COFF header and the debug directory. The objs are not byte-identical files. That would need the same
`/Fo` dir, the same `${GEN}` dir and `/showIncludes`.

A second full build (the 11-03 glue, the same checkout path, no exe anywhere: the committed `stubs.obj` default, `order.txt`
unpacked from `order.tar.xz`, a supplied `.res`) gave the same symbol set and section list as the reference
`fullexe3.exe` but was 512 bytes larger (`.text$mn` +0xd0, `.xdata` -0x20). Of its 3390 objs that could be compared
(283 reference objs had been rebuilt since), 3329 were identical outside the debug and `.chks64` sections. The 61 that
differed were all engine objs (`ecrD3D11Renderer`, `NiMain` textures, `NiMesh`, `AttachNifData`, `LuaWrap`,
`ActorModel`, `egmAnimationBindings`). The reference cache had built them on 10-27, before 153 `engine-patches` files
changed; the fresh build applied the patches at that commit. So the size difference comes from a stale reference cache,
not from reading the exe. Relinking the reference objs with the committed `stubs.obj` and the unpacked order list gave
the reference exe except for the 4 timestamp bytes.

## Maintainer builds (with the original exe)

These builds read the original x64 `MapleStory2.exe` (KMS2_DEV build): `-DMS2_EXE=<file>` or the `MS2_EXE`
environment variable, else `Game Versions/KMS2_DEV/x64/MapleStory2.exe` in the checkout (verified by
`tools/check_exe.py`). They check the recompiled code against it, and they make the glue the build above links. To
build the game you need neither.

### Exe-reading build

```
cmake --preset fullexe && cmake --build build/fullexe
```

`cmake/fullexe` (root option `MS2_EXE_BUILD=ON`, which the `fullexe` preset sets) builds from the same checkout and
SDKs and checks every obj against the exe. The result is `build/fullexe/out/MapleStory2.exe`, a copy of `fullexe3.exe`
next to it (link log and map there too). Rebuilding after an edit recompiles only the changed translation units; the
link reads every object where the compile cache keeps it (a response file), so no copy of the objects is made. The
shim it builds (`tools/fullexe/shim.py`) always has the diagnostics of `MS2_SHIM_DIAGNOSTICS`. A build dir this
configure made stays an exe-reading build when CMake re-runs in it.

Besides the prerequisites above it needs:

- the original exe (above);
- for every SDK root its own cache variable, checked at configure against `cmake/sdk-manifest.txt` (file names and
  SHA-256 values only; a missing or different file stops the configure with the variable name): `MS2_GAMEBRYO_ROOT`
  (the engine dir, default `engine/`), `MS2_MSVC_ROOT` (default `third_party/`), and `MS2_DXSDK_ROOT`,
  `MS2_PHYSX_ROOT`, `MS2_CEF_ROOT`, `MS2_PATHENGINE_ROOT`, which must sit at their places under `MS2_MSVC_ROOT` as in
  the table above. Example: `cmake --preset fullexe -DMS2_GAMEBRYO_ROOT=<dir> -DMS2_MSVC_ROOT=<dir>`;
- Python 3 with the packages of `tools/` (`.venv/bin/python` by default, `-DMS2_PYTHON=...`) and LLVM binutils
  (`llvm-nm`, `llvm-undname`);
- one free heavy slot (`tools/heavy_lock.py`): the link and the compile stage take it. The slots are files in
  `work/locks/`; a second checkout on the same machine shares them with `MS2_LOCK_DIR=<first checkout>/work/locks`;
- about 60 GB of free disk.

`cmake/fullexe` cannot run without the exe: `rtti_scan`, `progress` (byte matching), `pinreport`, `implibs --lib`,
`datapair`, `shim`, `rsrc` and `crtinit` all open it, and `alias` then finds no pairs.

#### Stages

Each is a CMake target that runs the matching `tools/fullexe` script unchanged, in this order: `compile` (incremental
per-unit cache), `plan`, `implibs`, `asm`, `link0` (open link), `defsyms`, `analyze0`, `alias` and `order` (generated
glue), `link1`, `analyze1`, `shim` and `rsrc` (generated stubs, ABI adapters, resources), `crtinit`, `initorder`, and
`link2` (the closed link). `cmake --build build/fullexe --target <stage>` runs the chain up to that stage. By default
the `rsrc` stage builds `shim/exe.res` straight from the exe's `.rsrc` tree (`tools/fullexe/rsrc.py`);
`-DMS2_RESOURCES_RES=<res>` links a `.res` instead.

#### Committed lists instead of exe reads

These options are off by default. Each one replaces an exe read with a committed list of names or addresses (no exe
bytes), and gives the same stage output:

- `-DMS2_IMPORTS_FROM_LIST=ON`: the `implibs` stage builds the import libs from `data/fullexe/imports.tsv` (the exe's
  import names, the shipped `libcef.dll` export names and the extra imports), so it needs neither the exe nor
  `libcef.dll`. `tools/fullexe/implibs.py --write-imports <file>` regenerates the list.
- `-DMS2_CRTINIT_FROM_LIST=ON`: the `crtinit` stage reads the exe's static-initializer table (the `.CRT$XC*`/`.CRT$XI*`
  pointers, in order) from `data/fullexe/crtinit-exe.tsv`; `initorder` then gives the same `--before` list.
  `tools/fullexe/crtinit.py --write-exe-table <file>` regenerates it.

#### How much glue is left

`tools/fullexe/gluecount.py` appends a dated row to `progress/glue-metrics.tsv` (alias pairs, ABI adapters, trap
stubs, duplicate symbols, unresolved symbols before the shim, `/FORCE` flags, boot patch files, signature clashes).
Both are maintainer files and are not in the published repo.

### Plain link over an obj cache

`cmake/fullexe-plain` can also link the objs an exe-reading build compiled instead of compiling them
(`MS2_PLAIN_COMPILE=OFF`, `MS2_PLAIN_OBJ_ROOT` = that build's compile cache):

```
cmake -S cmake/fullexe-plain -B build/fullexe-plain -G Ninja -DMS2_PLAIN_OBJ_ROOT=build/progress-<tag> \
      [-DMS2_RESOURCES_RES=<res>] && cmake --build build/fullexe-plain
```

The result is `build/fullexe-plain/out/MapleStory2.exe`. With `-DMS2_PLAIN_NAME=fullexe3`, a build's glue
(`plainglue.py write <dir>` on a finished `cmake/fullexe` build, `-DMS2_PLAIN_GLUE=<dir>`), its objs and
`-DMS2_SHIM_DIAGNOSTICS=ON`, the result is byte-identical to `link2`'s `fullexe3.exe` except for the link timestamp.
The exe's export directory records the output name, so the default name shifts some `.rdata` bytes.

`plainglue.py stubs <exe> data/fullexe/plain/stubs.tsv <obj>` writes `stubs.obj` from the exe and reports whether it
holds exe bytes (an empty `stubs.tsv` writes none).

### Refreshing the glue

This needs an exe-reading `cmake/fullexe` build. `glue-refresh.sh`, `latest.sh`, the `work/` dirs and
`publish-github.sh` named here are maintainer files and are not in the published repo. After each applied merge, once
that commit's fullexe-latest build has linked and passed, run these against that build, with `FULLEXE_DIR` and
`--cache` pointing at it:

1. `tools/fullexe/plainglue.py write data/fullexe/plain`
2. `plainglue.py compile data/fullexe/plain` (in that build's checkout and environment)
3. `plainglue.py pack data/fullexe/plain`
4. `plainglue.py facts data/fullexe/plain --tree <that build's checkout>` (in that checkout)

Then delete `order.txt` and commit `objs.txt`, `alias.rsp`, `stubs.tsv`, `order.tar.xz`, `compile.tsv`, `flags.tsv`,
`tree.tsv`, `link.tsv`, `before.tsv` and `linkfacts.tsv` together (step 1 writes `link.tsv` and `before.tsv`;
`plainglue.py tables <dir>` writes only them). Step 2 writes the compile list as the finished build ran it and checks
each command against the flags key its `.deps` recorded. Step 4 writes `linkfacts.tsv`, the few link-plan facts derive
cannot compute (above), and checks that derive's rules plus those facts give the build's `link.tsv` back; it exits 3
when they do not. Rerun `plainglue.py stubs` and commit `stubs.obj` only when `stubs.tsv` changes and the tool still
reports zero fill; when `stubs.tsv` lists no stub, delete `stubs.obj` instead.

`tools/fullexe/glue-refresh.sh [--commit]` runs those steps in one command, from the latest published
`fullexe-latest` build. It takes the glue dir that `latest.sh` publishes only on a smoke PASS. If that dir holds no
glue for the published commit (a `latest.sh --loop` started before 10-30 keeps none), the script runs step 1 itself on
the build's `out` dir, after checking that `out/fullexe3.exe` is the published exe. It writes a `commit` file naming
the build's commit. Run it while that build's checkout (the `latest.sh` checkout, or `--wt <dir>`) is still at that
commit; the script stops once the checkout has moved on. It also stops when `stubs.tsv` changed. It does not open the
original exe.

Each published merge carries fresh glue: after the merge's `apply.sh` and before `tools/publish-github.sh`, run
`MS2_AGENT=<name> tools/fullexe/glue-refresh.sh --commit` (`MS2_AGENT` is any short name of your own: the tools keep
their private cache under `build/progress-<name>/`). It commits the glue for the newest smoke-passed
`fullexe-latest` build, which can be older than the merge. The published tip must be that build's own sources, so
`glue-refresh.sh --side <branch> [--overlay <path>]...` makes a side commit: parent the build's commit, tree that commit
with the refreshed glue (plus any `--overlay` path, such as this file, as master has it). `PUBLISH_REV=<branch>
tools/publish-github.sh` then publishes that commit instead of master. When the script stops because the build's checkout
has moved past the published build, refresh after the next smoke PASS. When it stops because `stubs.tsv` changed, run
`plainglue.py stubs` against an exe first (above).

### Hook DLL

The per-unit gates link the recompiled units into a proxy `dinput8.dll` (`src/hook`) that redirects functions of the
original exe to them and runs the differential tests. See [`README.md`](README.md#hook-dll-development) and
`CONTRIBUTING.md`.
