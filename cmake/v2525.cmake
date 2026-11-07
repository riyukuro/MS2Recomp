# Configure-time setup of <engine dir>/gamebryo-v2525, the include/overlay tree of the v2525-recipe engine objs.
# The tree is rebuilt from the pristine stock Gamebryo Source with engine-patches-v2525/ (BUILDING.md, "Engine trees").
# Inputs: MS2_ROOT, V2525_DIR (<engine dir>/gamebryo-v2525), V2525_SDK (the pristine <third_party>/gamebryo/APPDIR/Source,
# never patched in place), V2525_PY (a python3, or empty).
# The tree exists (a maintainer checkout tracks it): nothing to do. It is missing: apply the patches with V2525_PY, or stop
# with the command to run. A stamp records the manifest it came from; a pull that changes the patches asks for a re-apply.
set(_v_patches "${MS2_ROOT}/engine-patches-v2525")
set(_v_stamp "${V2525_DIR}/.engine-patches-v2525.sha256")
set(_v_cmd "python tools/apply_engine_patches.py engine-patches-v2525 \"${V2525_SDK}\" \"${V2525_DIR}\"")
if(EXISTS "${_v_patches}/manifest.tsv")
  file(SHA256 "${_v_patches}/manifest.tsv" _v_sha)
  if(EXISTS "${_v_stamp}")
    file(READ "${_v_stamp}" _v_old)
    string(STRIP "${_v_old}" _v_old)
    if(NOT _v_old STREQUAL _v_sha)
      message(FATAL_ERROR "${V2525_DIR} was made from an older engine-patches-v2525/: delete that directory and configure "
                          "again (it is rebuilt from ${V2525_SDK})")
    endif()
  elseif(NOT EXISTS "${V2525_DIR}/SDK_FILES.tsv")
    if(NOT IS_DIRECTORY "${V2525_SDK}")
      message(FATAL_ERROR "no pristine Gamebryo Source at ${V2525_SDK}: the v2525 engine objs are built from the stock "
                          "3.2.0.661 Source there (unpatched; see BUILDING.md)")
    endif()
    if(NOT V2525_PY)
      message(FATAL_ERROR "${V2525_DIR} is missing and no Python was found to make it. Run, in ${MS2_ROOT}:\n  ${_v_cmd}")
    endif()
    message(STATUS "gamebryo-v2525: applying engine-patches-v2525 to ${V2525_SDK} -> ${V2525_DIR}")
    execute_process(COMMAND "${V2525_PY}" -I "${MS2_ROOT}/tools/apply_engine_patches.py" "${_v_patches}" "${V2525_SDK}"
                            "${V2525_DIR}" RESULT_VARIABLE _v_rc OUTPUT_VARIABLE _v_out ERROR_VARIABLE _v_out)
    if(NOT _v_rc EQUAL 0)
      message(FATAL_ERROR "engine-patches-v2525 did not apply (the Source at ${V2525_SDK} must be the stock, unpatched "
                          "tree; engine-patches/ goes into the gamebryo/ copy only):\n${_v_out}")
    endif()
    file(WRITE "${_v_stamp}" "${_v_sha}\n")
  endif()
elseif(NOT EXISTS "${V2525_DIR}/SDK_FILES.tsv")
  message(FATAL_ERROR "${V2525_DIR} is missing and this checkout has no engine-patches-v2525/")
endif()
