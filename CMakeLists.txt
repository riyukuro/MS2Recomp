# Entry point for the root presets (see BUILDING.md).
#   default: the no-exe build (cmake/fullexe-plain): every obj compiled from the sources and the committed glue in
#            data/fullexe/plain, linked into MapleStory2.exe. It never reads the original exe.
#   MS2_EXE_BUILD=ON (preset "fullexe", maintainers): the exe-reading build (cmake/fullexe), which also checks the objs
#            against the original exe (MS2_EXE).
cmake_minimum_required(VERSION 3.20)
project(ms2 NONE)

# A build dir that an exe-reading configure made (it has MS2_CACHE_TAG) stays one when cmake re-runs there by itself;
# every other new build dir gets the no-exe build.
if(DEFINED CACHE{MS2_CACHE_TAG})
    set(_ms2_exe_default ON)
else()
    set(_ms2_exe_default OFF)
endif()
option(MS2_EXE_BUILD "maintainer build: read and check against the original exe (cmake/fullexe) instead of the no-exe build" ${_ms2_exe_default})

# Optional, off by default: the 32-bit PathEngine .tok builder (tools/tok/README.md). Needs your own PathEngine SDK
# headers (MS2_PATHENGINE_SDK); with the option off nothing PathEngine is looked for.
option(MS2_BUILD_TOK_TOOL "Also build tools/tok/builder (32-bit .tok builder; needs MS2_PATHENGINE_SDK)" OFF)
if(MS2_BUILD_TOK_TOOL)
    include(tools/tok/builder/tok-tool.cmake)
endif()
# Optional, off by default: the MS2.Tok Gamebryo Toolbench plugin (tools/tok/plugin; no PathEngine code, needs your own
# Toolbench assemblies in MS2_TOOLBENCH_DIR and the .NET SDK).
option(MS2_TOK_TOOLBENCH_PLUGIN "Also build the MS2.Tok Toolbench plugin (tools/tok/plugin)" OFF)
if(MS2_TOK_TOOLBENCH_PLUGIN)
    include(tools/tok/plugin/tok-plugin.cmake)
endif()

if(MS2_EXE_BUILD)
    add_subdirectory(cmake/fullexe)
else()
    # compile the objs here (no obj cache from an exe-reading build to read them from)
    set(MS2_PLAIN_COMPILE ON CACHE BOOL "compile the objs here from the committed glue (plainglue.py compile)")
    # no hook registrations in the exe: the game units get /DMS2_STANDALONE and the link /opt:noref
    set(MS2_PLAIN_STANDALONE ON CACHE BOOL "compile the game units with /DMS2_STANDALONE (no hook registrations in the exe)")
    add_subdirectory(cmake/fullexe-plain)
endif()
