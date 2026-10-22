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
#               0x14274d700-0x142778550, gb14): the engine's release switches (engine/units-gb.json flags 0) /O2 /GR-;
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
