# Real MSVC 14.16 (cl 19.16.27054, VS2017 15.9 / v141 toolset) on a native Windows host. Same compiler as
# toolchain-msvc1416-wine.cmake, without Wine: cl/link/lib/rc/mt come from PATH, which tools/ms2paths.py (toolchain_env)
# fills from vcvarsall.bat x64 -vcvars_ver=14.16. Run cmake from such an environment (tools/unit_check.py does this).
# MS2_CL (full path to cl.exe) overrides the PATH lookup.
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR AMD64)
if(DEFINED ENV{MS2_CL})
    file(TO_CMAKE_PATH "$ENV{MS2_CL}" _ms2_cl)
    set(CMAKE_C_COMPILER "${_ms2_cl}")
    set(CMAKE_CXX_COMPILER "${_ms2_cl}")
else()
    set(CMAKE_C_COMPILER cl)
    set(CMAKE_CXX_COMPILER cl)
endif()
set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreadedDLL)
