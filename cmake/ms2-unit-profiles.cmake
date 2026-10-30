# Per-unit compiler flag profiles for recovered code that is not /Od game code (docs/RECOVERY.md section 2 "Flag profiles").
# A src/ms2 unit selects one with a line `// MS2-FLAGS: <profile>` (by convention in the header block). The profile's
# options are APPENDED after the game flags (cmake/ms2-game-flags.cmake), so for cl they override /Od /Ob0 /GR /EHsc
# /fp:fast; tools/progress.py (tools/ms2flags.py) parses these lists and builds the same command line.
# A profile is orthogonal to the MSVC toolset (14.14/14.15/14.16, tc1): a unit's toolset choice and its profile compose.
#
#   scaleform   Scaleform GFx 4.1.18 recovered from the exe (src/ms2/scaleform, sfr lane): SDK property sheets
#               GFx_Config_Release + GFx_Lib (work/lb5/gen_gfx.py): /Ox /Ob2 /Ot /GF /Gy /GR- /Zp8 /MD, no EH
#               (/EHs-c- cancels the directory's /EHsc), /fp:precise, SF_BUILD_SHIPPING + NDEBUG,
#               GFX_USE_VIDEO (the exe links GFx video: Video state 0x1e, the CRI decoder).
#   gamebryo    MS2 code built inside the game's Gamebryo-flagged projects (the MS2 material classes and node library at
#               0x14274d700-0x142778550, gb14): the engine's release switches (data/engine/units-gb.json flags 0) /O2 /GR-;
#               /EHsc /fp:fast /GS /Gy are the game's already.

set(MS2_PROFILE_scaleform_OPTIONS
    "/Ox"
    "/Ob2"
    "/Ot"
    "/GF"
    "/Gy"
    "/GR-"
    "/Zp8"
    "/EHs-c-"
    "/fp:precise"
)
set(MS2_PROFILE_scaleform_DEFINITIONS
    "NDEBUG"
    "SF_BUILD_SHIPPING"
    "_CRT_SECURE_NO_WARNINGS"
    "GFX_USE_VIDEO"
)
set(MS2_PROFILE_gamebryo_OPTIONS
    "/O2"
    "/Ob2"
    "/GR-"
)
set(MS2_PROFILE_gamebryo_DEFINITIONS
)
set(MS2_UNIT_PROFILES scaleform gamebryo)

# Toolsets a src/ms2 unit can select with `// MS2-TOOLSET: <toolset>` (default: the project's cl 19.16 and the game flags).
#   vc9   cl 15.00.30729 (VS2008 SP1 x64; tools/msvc9/cl, installed by tools/fetch-vc9.sh) for code the exe links from a
#         prebuilt VS2008 library (the CRI Movie decoder, sfr_cri_*). The unit gets these options INSTEAD of the game flags
#         (no PCH, no game include dirs, /GS default); its MS2-FLAGS profile adds only its definitions. The source must
#         be C++03 (tools/msvc9/include only stands in for the C++ headers the WDK lacks). cmake builds such a unit with
#         a custom command and links the obj into the hook DLL directly (src/ms2/CMakeLists.txt); clang-cl compiles it
#         like any other unit. /Ob1: the library's functions came from separate objs, so one never inlines another;
#         mark the unit's own source-only helpers `inline`.
#   vc11  cl 17.00.61030 (VS2012 Update 4 x64; tools/msvc11/cl, installed by tools/fetch-vs2012.sh) for the Scaleform
#         Video add-on, which the exe links prebuilt (Rich prodid 0xce: sfr_video_*, the CRI glue in sfr_cri_01/02).
#         Same rules as vc9, but C++11 as far as VS2012 goes (no alias `using`, no explicit conversion operators,
#         no variadic templates) and with the VS2012 VC headers. /O2 /GR- and no EH, like the SF profile. The
#         functions the exe inlines need `inline`. The _ALLOW_* defines drop yvals.h's detect_mismatch records
#         (_MSC_VER 1700, MT_StaticRelease), which the 19.16 /MD link rejects, and _USE_ANSI_CPP (its include
#         guard; it undefines _CRT_NOPRAGMA_LIBS) skips use_ansi.h's /DEFAULTLIB:libcpmt, the static VS2012 C++
#         runtime; codegen is unchanged.
# MS2_UNIT_TOOLSET / MS2_UNIT_SOURCE (environment for tools/progress.py, cmake cache for the DLL build; both
# "<unit stem>=<value>,...") select a toolset, or compile a scratch copy, without a source edit (experiments only).
set(MS2_TOOLSET_vc9_OPTIONS
    "/O2"
    "/Ob1"
    "/Gy"
    "/GF"
    "/Zl"
    "/Z7"
    "/EHsc"
    "/bigobj"
    "/TP"
)
set(MS2_TOOLSET_vc11_OPTIONS
    "/O2"
    "/Gy"
    "/GF"
    "/Zl"
    "/Z7"
    "/GR-"
    "/EHs-c-"
    "/bigobj"
    "/TP"
    "/D_ALLOW_MSC_VER_MISMATCH"
    "/D_ALLOW_RUNTIME_LIBRARY_MISMATCH"
    "/D_USE_ANSI_CPP"
)
set(MS2_UNIT_TOOLSETS vc9 vc11)

# Apply the profiles to the sources of `srcvar` that declare one. Options only under real MSVC (clang-cl never
# byte-matches and keeps the project's codegen); definitions for both compilers so the code is the same.
function(ms2_unit_profiles srcvar)
    foreach(f IN LISTS ${srcvar})
        file(STRINGS "${f}" hdr LIMIT_COUNT 1 REGEX "^[ \t]*//[ \t]*MS2-FLAGS:")
        if(NOT hdr)
            continue()
        endif()
        string(REGEX REPLACE ".*MS2-FLAGS:[ \t]*([A-Za-z0-9_]+).*" "\\1" prof "${hdr}")
        if(NOT prof IN_LIST MS2_UNIT_PROFILES)
            message(FATAL_ERROR "${f}: unknown MS2-FLAGS profile '${prof}' (known: ${MS2_UNIT_PROFILES})")
        endif()
        set_property(SOURCE "${f}" APPEND PROPERTY COMPILE_DEFINITIONS ${MS2_PROFILE_${prof}_DEFINITIONS})
        if(MSVC AND NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            set_property(SOURCE "${f}" APPEND PROPERTY COMPILE_OPTIONS ${MS2_PROFILE_${prof}_OPTIONS})
        endif()
    endforeach()
endfunction()

set(MS2_UNIT_TOOLSET "" CACHE STRING "Experiment override of `// MS2-TOOLSET:` (<unit stem>=<toolset|default>,...)")
set(MS2_UNIT_SOURCE "" CACHE STRING "Experiment: compile a scratch copy for a toolset unit (<unit stem>=<file>,...)")

# value of the "<unit>=<value>,..." list `spec` for the unit `stem` (path under src/ms2 without .cpp) or its file name
function(ms2_unit_override spec stem out)
    get_filename_component(base "${stem}" NAME)
    set(val "")
    string(REPLACE "," ";" items "${spec}")
    foreach(it IN LISTS items)
        string(FIND "${it}" "=" eq)
        if(eq LESS 1)
            continue()
        endif()
        string(SUBSTRING "${it}" 0 ${eq} k)
        math(EXPR v0 "${eq} + 1")
        string(SUBSTRING "${it}" ${v0} -1 v)
        string(STRIP "${k}" k)
        if(k STREQUAL stem OR k STREQUAL base)
            string(STRIP "${v}" val)
            break()
        endif()
    endforeach()
    set(${out} "${val}" PARENT_SCOPE)
endfunction()

# Take the sources of `srcvar` that select another toolset out of the list (real MSVC only) and build each with a custom
# command (tools/msvc9/compile.py: the toolset's cl and options, the profile's definitions, a depfile); the objects are
# returned in `objvar` for the hook DLL (src/CMakeLists.txt links them, feeds them to ms2symobj and adds the VS2008 CRT's
# legacy_stdio_definitions). MS2_UNIT_SOURCE applies to these objects only: clang-cl compiles the committed source.
function(ms2_unit_toolsets srcvar objvar)
    get_filename_component(root "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/.." ABSOLUTE)
    set(kept "")
    set(objs "")
    foreach(f IN LISTS ${srcvar})
        file(RELATIVE_PATH rel "${CMAKE_CURRENT_SOURCE_DIR}" "${f}")
        string(REGEX REPLACE "\\.cpp$" "" stem "${rel}")
        ms2_unit_override("${MS2_UNIT_TOOLSET}" "${stem}" ts)
        if(NOT ts)
            file(STRINGS "${f}" hdr LIMIT_COUNT 1 REGEX "^[ \t]*//[ \t]*MS2-TOOLSET:")
            if(hdr)
                string(REGEX REPLACE ".*MS2-TOOLSET:[ \t]*([A-Za-z0-9_]+).*" "\\1" ts "${hdr}")
            endif()
        endif()
        if(ts STREQUAL "default" OR ts STREQUAL "1416")
            set(ts "")
        endif()
        if(ts AND NOT ts IN_LIST MS2_UNIT_TOOLSETS)
            message(FATAL_ERROR "${f}: unknown MS2-TOOLSET '${ts}' (known: ${MS2_UNIT_TOOLSETS})")
        endif()
        if(NOT ts OR NOT MSVC OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            list(APPEND kept "${f}")
            continue()
        endif()
        ms2_unit_override("${MS2_UNIT_SOURCE}" "${stem}" src)
        if(src)
            message(WARNING "MS2_UNIT_SOURCE: ${stem} is built from ${src} (experiment override)")
        else()
            set(src "${f}")
        endif()
        # these objects are for the hook DLL only (tools/progress.py builds the fullexe's), so like ms2_game_flags
        set(defs "/DMS2_HOOK_DLL")
        file(STRINGS "${src}" phdr LIMIT_COUNT 1 REGEX "^[ \t]*//[ \t]*MS2-FLAGS:")
        if(phdr)
            string(REGEX REPLACE ".*MS2-FLAGS:[ \t]*([A-Za-z0-9_]+).*" "\\1" prof "${phdr}")
            foreach(d IN LISTS MS2_PROFILE_${prof}_DEFINITIONS)
                list(APPEND defs "/D${d}")
            endforeach()
        endif()
        set(obj "${CMAKE_CURRENT_BINARY_DIR}/toolset-${ts}/${stem}.obj")
        get_filename_component(odir "${obj}" DIRECTORY)
        file(MAKE_DIRECTORY "${odir}")
        add_custom_command(OUTPUT "${obj}"
            COMMAND "${root}/tools/msvc9/compile.py" "${obj}.d" "${root}/tools/ms${ts}/cl" /c ${MS2_TOOLSET_${ts}_OPTIONS} ${defs}
                    "/Fo${obj}" "${src}"
            DEPENDS "${src}" "${root}/cmake/ms2-unit-profiles.cmake" "${root}/tools/ms${ts}/cl"
            DEPFILE "${obj}.d"
            COMMENT "Building ${ts} object ${stem}.obj"
            VERBATIM)
        list(APPEND objs "${obj}")
    endforeach()
    set(${srcvar} "${kept}" PARENT_SCOPE)
    set(${objvar} "${objs}" PARENT_SCOPE)
endfunction()
