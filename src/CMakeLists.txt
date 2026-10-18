# Recompiled MapleStory2 code + hook DLL (proxy dinput8.dll loaded by the original KMS2_DEV x64 MapleStory2.exe).
#   clang-cl:  cmake -G Ninja -S src -B build/hook-clang -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-clangcl-x64.cmake
#   cl 19.16:  cmake -G Ninja -S src -B build/hook-msvc  -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-msvc1416-wine.cmake
# See NOTES.md "Recompiled source layout & hook DLL".
cmake_minimum_required(VERSION 3.20)
if(NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif()
project(ms2recomp C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(MS2HOOK_WITH_GAME "Link the recovered game code (src/ms2) and its difftests into the hook DLL" ON)
option(MS2HOOK_WITH_COMPAT "Link the client compatibility fixes (src/hook/compat, not game code; NOTES \"Field-entry crash\")" ON)
# Per-agent link check (tools/unit-check.sh, docs/RECOVERY.md section 12): build only the game sources (and difftests)
# whose path contains one of these substrings, and link against another symbol table (the agent's
# build/progress-<agent>/symbols.tsv = committed progress/symbols.tsv + the agent's own harvest). Empty = everything.
set(MS2_GAME_FILTER "" CACHE STRING "Only game sources/difftests whose path contains one of these substrings (;-list)")
option(MS2_SYMOBJ_PRUNE "ms2sym.obj holds only the symbols the game objects reference (faster per-unit link checks)" OFF)
set(MS2_SYMBOL_TSV "" CACHE FILEPATH "Symbol table for ms2sym.obj instead of progress/symbols.tsv")

add_compile_definitions(WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS)
add_compile_options(/W3 /EHsc /utf-8)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wno-microsoft-cast -Wno-unused-command-line-argument)
endif()

# Recovered game code: OBJECT library `ms2game` (src/ms2/CMakeLists.txt), compiled with Nexon's game-code flags under
# cl 19.16 (cmake/ms2-game-flags.cmake; NOTES "Game-code compiler flags (byte-matching)") and linked object by object
# into the DLL (never via a static library: the linker would drop objects whose only content is MS2_REPLACE
# registrations, since nothing references them).
file(GLOB_RECURSE MS2_DIFFTEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/hook/difftest/*.cpp")
# Keep only the entries of list `var` whose path contains one of MS2_GAME_FILTER's substrings.
function(ms2_filter_sources var)
    if(MS2_GAME_FILTER)
        set(kept "")
        foreach(f IN LISTS ${var})
            foreach(sub IN LISTS MS2_GAME_FILTER)
                string(FIND "${f}" "${sub}" pos)
                if(NOT pos EQUAL -1)
                    list(APPEND kept "${f}")
                    break()
                endif()
            endforeach()
        endforeach()
        set(${var} "${kept}" PARENT_SCOPE)
    endif()
endfunction()
ms2_filter_sources(MS2_DIFFTEST_SOURCES)
file(GLOB_RECURSE MS2_COMPAT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/hook/compat/*.cpp")

add_library(detours STATIC hook/detours/detours.cpp hook/detours/disasm.cpp hook/detours/modules.cpp)
target_compile_definitions(detours PRIVATE DETOURS_X64 DETOURS_64BIT)
target_compile_options(detours PRIVATE /W0)

add_library(dinput8 SHARED
    hook/dinput8_proxy.cpp
    hook/hook_runtime.cpp
    hook/difftest.cpp)
if(MS2HOOK_WITH_GAME)
    add_subdirectory(ms2)
    target_sources(dinput8 PRIVATE $<TARGET_OBJECTS:ms2game> ${MS2_DIFFTEST_SOURCES})
    # Unrecovered exe functions/globals by their real names (docs/RECOVERY.md "Calling unrecovered code"):
    # tools/ms2symobj.py turns progress/symbols.tsv (+ symbols-manual.tsv) into thunks / absolute symbols that are
    # used only when no recovered definition exists (/alternatename). Needs the fixed DLL base below.
    get_filename_component(MS2_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)
    if(EXISTS "${MS2_ROOT}/.venv/bin/python")
        set(MS2_PYTHON "${MS2_ROOT}/.venv/bin/python")
    elseif(EXISTS "${MS2_ROOT}/.venv/Scripts/python.exe")
        set(MS2_PYTHON "${MS2_ROOT}/.venv/Scripts/python.exe")
    else()
        find_package(Python3 REQUIRED COMPONENTS Interpreter)
        set(MS2_PYTHON "${Python3_EXECUTABLE}")
    endif()
    # Lowest priority first (later tables override earlier ones): FID-matched engine/third-party names, then symbols.tsv.
    set(MS2_SYMBOL_TABLES "")
    if(EXISTS "${MS2_ROOT}/progress/symbols-engine.tsv")
        list(APPEND MS2_SYMBOL_TABLES "${MS2_ROOT}/progress/symbols-engine.tsv")
    endif()
    if(MS2_SYMBOL_TSV)
        list(APPEND MS2_SYMBOL_TABLES "${MS2_SYMBOL_TSV}")
    else()
        list(APPEND MS2_SYMBOL_TABLES "${MS2_ROOT}/progress/symbols.tsv")
    endif()
    if(EXISTS "${MS2_ROOT}/progress/symbols-manual.tsv")
        list(APPEND MS2_SYMBOL_TABLES "${MS2_ROOT}/progress/symbols-manual.tsv")
    endif()
    set(MS2_SYMOBJ_PRUNE_ARG "")
    if(MS2_SYMOBJ_PRUNE)
        set(MS2_SYMOBJ_PRUNE_ARG --prune)
    endif()
    set(MS2_SYMOBJ "${CMAKE_CURRENT_BINARY_DIR}/ms2sym.obj")
    add_custom_command(OUTPUT "${MS2_SYMOBJ}"
        COMMAND "${MS2_PYTHON}" "${MS2_ROOT}/tools/ms2symobj.py" -o "${MS2_SYMOBJ}" ${MS2_SYMBOL_TABLES} --rebind --rebind-log "${CMAKE_CURRENT_BINARY_DIR}/rebound.txt" ${MS2_SYMOBJ_PRUNE_ARG} --objs $<TARGET_OBJECTS:ms2game>
        DEPENDS "${MS2_ROOT}/tools/ms2symobj.py" ${MS2_SYMBOL_TABLES} $<TARGET_OBJECTS:ms2game>
        COMMAND_EXPAND_LISTS
        COMMENT "Generating ms2sym.obj (exe symbol map)")
    set_source_files_properties("${MS2_SYMOBJ}" PROPERTIES EXTERNAL_OBJECT TRUE GENERATED TRUE)
    target_sources(dinput8 PRIVATE "${MS2_SYMOBJ}")
    add_custom_command(TARGET dinput8 POST_BUILD
        COMMAND "${MS2_PYTHON}" "${MS2_ROOT}/tools/ms2symobj.py" --check "$<TARGET_FILE:dinput8>" ${MS2_SYMBOL_TABLES})
endif()
if(MS2HOOK_WITH_COMPAT)
    target_sources(dinput8 PRIVATE ${MS2_COMPAT_SOURCES})
endif()
target_include_directories(dinput8 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/hook")
target_link_libraries(dinput8 PRIVATE detours)
set_target_properties(dinput8 PROPERTIES OUTPUT_NAME dinput8 PREFIX "")
# Fixed base 0x100000000, below the (non-relocatable) exe at 0x140000000: keeps every exe address within REL32 range
# of the DLL's code, which the absolute data symbols of ms2sym.obj rely on. A fixed DLL cannot be relocated: if the
# range is taken the DLL (and with it the process) fails to load instead of misbehaving.
target_link_options(dinput8 PRIVATE /DEBUG /OPT:REF /OPT:ICF /BASE:0x100000000 /DYNAMICBASE:NO /FIXED)
# NiRendererSettings.h pulls NiD3D10Headers.h, whose #pragma comment(lib) asks for the June 2010 DX SDK import libs.
# Mixed-case symlinks, since lld-link on Linux is case-sensitive and the pragma asks for D3DX9.lib / D3DX10.lib.
set(MS2_DXLIB_DIR "${CMAKE_BINARY_DIR}/dxsdk-lib")
file(MAKE_DIRECTORY "${MS2_DXLIB_DIR}")
foreach(_n D3DX9 D3DX10)
    string(TOLOWER "${_n}" _l)
    file(CREATE_LINK "${MS2_ROOT}/third_party/dxsdk/DXSDK/Lib/x64/${_l}.lib" "${MS2_DXLIB_DIR}/${_n}.lib" COPY_ON_ERROR SYMBOLIC)
endforeach()
target_link_options(dinput8 PRIVATE "/LIBPATH:${MS2_DXLIB_DIR}")
