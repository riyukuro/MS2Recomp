# Cross-compile Windows x64 on Linux with clang-cl + lld-link against the MSVC 14.16 (VS2017 15.9)
# headers/libs installed by msvc-wine in third_party/msvc. ABI-compatible with the original MapleStory2.exe
# (MSVC 14.16, dynamic CRT, MBCS mfc140.dll). For byte-matching later, use cl.exe via third_party/msvc/bin/x64.
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR AMD64)

get_filename_component(MS2_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
set(MSVC_ROOT "${MS2_ROOT}/third_party/msvc")
set(MSVC_VC "${MSVC_ROOT}/VC/Tools/MSVC/14.16.27023")
set(WINSDK "${MSVC_ROOT}/Windows Kits/10")
set(WINSDK_VER 10.0.19041.0)

set(CMAKE_C_COMPILER clang-cl)
set(CMAKE_CXX_COMPILER clang-cl)
set(CMAKE_LINKER lld-link)
set(CMAKE_AR llvm-lib)
set(CMAKE_RC_COMPILER llvm-rc)
set(CMAKE_MT llvm-mt)
set(CMAKE_C_COMPILER_TARGET x86_64-pc-windows-msvc)
set(CMAKE_CXX_COMPILER_TARGET x86_64-pc-windows-msvc)

# Native Windows host: clang-cl reads the INCLUDE/LIB of the vcvars environment (v141 + SDK 10.0.19041), so the msvc-wine
# directories below are only added on other hosts.
if(CMAKE_HOST_WIN32)
    set(_flags "-fms-compatibility-version=19.16 --target=x86_64-pc-windows-msvc -D_HAS_AUTO_PTR_ETC=1")
    set(CMAKE_C_FLAGS_INIT "${_flags}")
    set(CMAKE_CXX_FLAGS_INIT "${_flags}")
    set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreadedDLL)
    return()
endif()

set(_inc
    "${MSVC_VC}/include" "${MSVC_VC}/atlmfc/include"
    "${WINSDK}/Include/${WINSDK_VER}/ucrt" "${WINSDK}/Include/${WINSDK_VER}/um"
    "${WINSDK}/Include/${WINSDK_VER}/shared" "${WINSDK}/Include/${WINSDK_VER}/winrt")
set(_flags "-fms-compatibility-version=19.16 --target=x86_64-pc-windows-msvc -D_HAS_AUTO_PTR_ETC=1")
foreach(d ${_inc})
    string(APPEND _flags " /imsvc \"${d}\"")
endforeach()
set(CMAKE_C_FLAGS_INIT "${_flags}")
set(CMAKE_CXX_FLAGS_INIT "${_flags}")
set(CMAKE_RC_FLAGS_INIT "/I \"${MSVC_VC}/atlmfc/include\" /I \"${WINSDK}/Include/${WINSDK_VER}/um\" /I \"${WINSDK}/Include/${WINSDK_VER}/shared\"")

set(_libs "/LIBPATH:\"${MSVC_VC}/lib/x64\" /LIBPATH:\"${MSVC_VC}/atlmfc/lib/x64\" /LIBPATH:\"${WINSDK}/Lib/${WINSDK_VER}/ucrt/x64\" /LIBPATH:\"${WINSDK}/Lib/${WINSDK_VER}/um/x64\"")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${_libs}")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "${_libs}")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "${_libs}")

set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreadedDLL)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
