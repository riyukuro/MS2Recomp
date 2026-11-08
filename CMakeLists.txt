# Entry point for `cmake --preset fullexe` (see BUILDING.md); the build itself is cmake/fullexe.
cmake_minimum_required(VERSION 3.20)
project(ms2 NONE)

# Optional, off by default: the 32-bit PathEngine .tok builder (tools/tok/README.md). Needs your own PathEngine SDK
# headers (MS2_PATHENGINE_SDK); with the option off nothing PathEngine is looked for.
option(MS2_BUILD_TOK_TOOL "Also build tools/tok/builder (32-bit .tok builder; needs MS2_PATHENGINE_SDK)" OFF)
if(MS2_BUILD_TOK_TOOL)
    include(tools/tok/builder/tok-tool.cmake)
endif()

add_subdirectory(cmake/fullexe)
