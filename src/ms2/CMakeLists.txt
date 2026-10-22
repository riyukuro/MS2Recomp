# Recovered game code (src/ms2/**.cpp) as an OBJECT library: every object is linked into the hook DLL (no static
# library, which would drop objects whose only content is MS2_REPLACE registrations).
# Under cl 19.16 it is compiled with Nexon's game-code flags (cmake/ms2-game-flags.cmake) so the functions can
# byte-match the exe; this directory's per-config flags are cleared so no /O2 /Ob1 /DNDEBUG of the build type leak in.
# clang-cl keeps the normal project flags (it can never byte-match).
include("${CMAKE_CURRENT_LIST_DIR}/../../cmake/ms2-game-flags.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../../cmake/ms2-scaleform-sdk.cmake")    # optional Scaleform SDK headers (MS2_SCALEFORM_SDK)
include("${CMAKE_CURRENT_LIST_DIR}/../../cmake/ms2-engine-flags.cmake")     # Gamebryo include dirs + defines (docs/RECOVERY.md section 3)
include("${CMAKE_CURRENT_LIST_DIR}/../../cmake/ms2-unit-profiles.cmake")    # `// MS2-FLAGS: <profile>` per-unit flags (Scaleform)

if(MSVC AND NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    foreach(cfg DEBUG RELEASE RELWITHDEBINFO MINSIZEREL)
        set(CMAKE_CXX_FLAGS_${cfg} "/Zi")
    endforeach()
endif()

# Game code sees Nexon's preprocessor environment, not the hook project's (no WIN32_LEAN_AND_MEAN / NOMINMAX:
# MFC and the original headers need the full windows.h and the min/max macros; no /utf-8: literals stay bytes).
set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "" COMPILE_OPTIONS "")
add_compile_options(/W3 /EHsc)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wno-microsoft-cast -Wno-unused-command-line-argument -Wno-invalid-offsetof
                        -Wno-unused-private-field -Wno-inconsistent-missing-override)
endif()

# src/ms2/scaleform is a git submodule in the published mirror (GFx418-Recomp)
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/scaleform/include")
    message(FATAL_ERROR "src/ms2/scaleform is empty: run `git submodule update --init` (or clone with --recurse-submodules)")
endif()

file(GLOB_RECURSE MS2_GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
ms2_filter_sources(MS2_GAME_SOURCES)     # MS2_GAME_FILTER (per-agent link check, src/CMakeLists.txt)
if(NOT MS2_GAME_SOURCES)
    message(FATAL_ERROR "MS2_GAME_FILTER '${MS2_GAME_FILTER}' matches no game source")
endif()
ms2_unit_profiles(MS2_GAME_SOURCES)      # per-source overrides after the game flags (cmake/ms2-unit-profiles.cmake)
add_library(ms2game OBJECT ${MS2_GAME_SOURCES})
target_include_directories(ms2game PRIVATE "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/hook")
ms2_engine_flags(ms2game)
ms2_scaleform_flags(ms2game)
ms2_game_flags(ms2game)
