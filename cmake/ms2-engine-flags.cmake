# Gamebryo (engine/gamebryo) include environment for the recovered game code (src/ms2). Included by src/ms2/CMakeLists.txt;
# tools/progress.py parses MS2_ENGINE_INCLUDE_DIRS / MS2_ENGINE_DEFINITIONS from this file (keep the "..." one-per-line
# format), so there is one source of truth. Pass 1: layouts must match the exe, so the engine is seen exactly as the engine
# libs were built for it (NOTES.md "Gamebryo x64 build"; engine/gamebryo/CMakeLists.txt, vcproj "Release" configuration):
#   EE_USE_NATIVE_STL          MSVC STL instead of STLport (the exe only has MSVC STL containers)
#   EE_EFD_CONFIG_RELEASE, EE_CONFIG_RELEASE, NIRELEASE   shipping configuration (release layouts validated against the exe)
#   EE_EFD_NO_IMPORT           the engine is statically linked into the exe: *_ENTRY export macros expand to nothing
#   EE_PLATFORM_WIN32, WIN32, STRICT
# NOT defined on purpose: NDEBUG (the game code keeps live asserts), NOMINMAX/WINVER (the MFC game code needs the
# defaults), _WINDLL/NI*_IMPORT (would turn the *_ENTRY macros into dllimport).
# The directory list is GB_SDK_INCLUDE_DIRS of engine/gamebryo/CMakeLists.txt (the flattened sdk/Win32/Include) plus TinyXML,
# relative to engine/gamebryo. Verified layouts: work/eng1_probe, NOTES.md "Engine headers in the game build".
set(MS2_ENGINE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../engine/gamebryo")
set(MS2_ENGINE_DEFINITIONS
    "EE_USE_NATIVE_STL"
    "EE_EFD_CONFIG_RELEASE"
    "EE_CONFIG_RELEASE"
    "NIRELEASE"
    "EE_EFD_NO_IMPORT"
    "EE_PLATFORM_WIN32"
    "WIN32"
    "STRICT"
    "EE_USE_PER_THREAD_ALLOCATOR_POOLS=0"
)
set(MS2_ENGINE_INCLUDE_DIRS
    "Foundation"
    "GameFramework"
    "CoreRuntime/EngineLibs/NiSystem/Win32"
    "CoreRuntime/EngineLibs/NiSystem"
    "CoreRuntime/EngineLibs/NiMain/Win32"
    "CoreRuntime/EngineLibs/NiMain"
    "CoreRuntime/EngineLibs/NiMain/StandardMaterialNodeLibrary"
    "CoreRuntime/EngineLibs/NiFloodgate/Win32"
    "CoreRuntime/EngineLibs/NiFloodgate"
    "CoreRuntime/EngineLibs/NiFloodgate/Kernels/NiNopKernel"
    "CoreRuntime/EngineLibs/NiMesh/Win32"
    "CoreRuntime/EngineLibs/NiMesh"
    "CoreRuntime/EngineLibs/NiMesh/Kernels/NiMorphingKernel"
    "CoreRuntime/EngineLibs/NiMesh/Kernels/NiSkinningKernelP"
    "CoreRuntime/EngineLibs/NiMesh/Kernels/NiSkinningKernelPN16"
    "CoreRuntime/EngineLibs/NiMesh/Kernels/NiSkinningKernelPN32"
    "CoreRuntime/EngineLibs/NiMesh/Kernels/NiSkinningKernelPNBT16"
    "CoreRuntime/EngineLibs/NiMesh/Kernels/NiSkinningKernelPNBT32"
    "CoreRuntime/EngineLibs/NiMesh/Kernels/NiInstanceCullingKernel"
    "CoreRuntime/EngineLibs/NiMesh/Kernels/NiCalculateBoneMatricesKernel"
    "CoreRuntime/EngineLibs/NiAnimation/Win32"
    "CoreRuntime/EngineLibs/NiAnimation"
    "CoreRuntime/EngineLibs/NiParticle/Win32"
    "CoreRuntime/EngineLibs/NiParticle"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSAlignedQuadGeneratorKernelFF"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSAlignedQuadGeneratorKernelFV"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSAlignedQuadGeneratorKernelVF"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSAlignedQuadGeneratorKernelVV"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSAlignedQuadTextureKernel"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSFacingQuadGeneratorKernel"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSSimulatorGeneralKernel"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSSimulatorForcesKernel"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSSimulatorCollidersKernel"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSSimulatorFinalKernel"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSSimulatorMeshAlignKernelFF"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSSimulatorMeshAlignKernelFV"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSSimulatorMeshAlignKernelVF"
    "CoreRuntime/EngineLibs/NiParticle/Kernels/NiPSSimulatorMeshAlignKernelVV"
    "CoreRuntime/EngineLibs/NiCollision/Win32"
    "CoreRuntime/EngineLibs/NiCollision"
    "CoreRuntime/EngineLibs/NiTerrain/Win32"
    "CoreRuntime/EngineLibs/NiTerrain"
    "CoreRuntime/EngineLibs/NiDX9Renderer/Win32"
    "CoreRuntime/EngineLibs/NiDX9Renderer"
    "CoreRuntime/EngineLibs/NiD3D10Renderer/Win32"
    "CoreRuntime/EngineLibs/NiD3D10Renderer"
    "CoreRuntime/EngineLibs/ecrD3D11Renderer/Win32"
    "CoreRuntime/EngineLibs/ecrD3D11Renderer"
    "CoreRuntime/EngineLibs"
    "CoreRuntime/ShaderLibs/NiBinaryShaderLib/Win32"
    "CoreRuntime/ShaderLibs/NiBinaryShaderLib"
    "CoreRuntime/ShaderLibs/NiD3DXEffectShaderLib/Win32"
    "CoreRuntime/ShaderLibs/NiD3DXEffectShaderLib"
    "CoreRuntime/ShaderLibs/NSBShaderLib/Win32"
    "CoreRuntime/ShaderLibs/NSBShaderLib"
    "CoreRuntime/ShaderLibs/NSFParserLib/Win32"
    "CoreRuntime/ShaderLibs/NSFParserLib"
    "CoreRuntime/UtilityLibs/NiInput/Win32"
    "CoreRuntime/UtilityLibs/NiInput"
    "CoreRuntime/UtilityLibs/NiVisualTracker/Win32"
    "CoreRuntime/UtilityLibs/NiVisualTracker"
    "CoreRuntime/UtilityLibs/NiDX9RendererSetup/Win32"
    "CoreRuntime/UtilityLibs/NiDX9RendererSetup"
    "CoreRuntime/PhysXLibs/NiPhysX/Win32"
    "CoreRuntime/PhysXLibs/NiPhysX"
    "CoreRuntime/PhysXLibs/NiPhysXParticle/Win32"
    "CoreRuntime/PhysXLibs/NiPhysXParticle"
    "CoreRuntime/PhysXLibs/NiPhysXParticle/Kernels/NiPhysXPSSimulatorInitialKernel"
    "CoreRuntime/PhysXLibs/NiPhysXParticle/Kernels/NiPhysXPSSimulatorFinalKernel"
    "CoreRuntime/UtilityLibs/NiSettingsDialog"
    "3rdParty/TinyXML"
    # PhysX 2.8.4 headers (the exe was built against 2.8.4; MS2_PHYSX_VERSION=283 swaps them for 2.8.3 below; tools/progress.py
    # reads the literal 2.8.4 paths, or 2.8.3 with MS2_PHYSX=283 in the environment).
    # MS2: src/ms2/physx2846 shadows NxScene.h/NxPhysics.h (the shipped 2.8.4.6 PhysXCore has one NxScene virtual more, see
    # there); it reaches the stock headers as <Physics/include/...> through the SDKs dir. Keep both before Physics/include.
    "../../src/ms2/physx2846"
    "../../third_party/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/SDKs"
    "../../third_party/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/SDKs/Foundation/include"
    "../../third_party/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/SDKs/Physics/include"
    # MS2: NiPhysXMeshDesc.h includes NxCooking.h (EntityWorldManager's real PropService header).
    "../../third_party/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/SDKs/Cooking/include"
    "../../third_party/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/SDKs/PhysXLoader/include"
)

# Fall back to the PhysX 2.8.3 SDK headers: -DMS2_PHYSX_VERSION=283 (default 284, what the exe was compiled against).
# The MS2_PHYSX=283 environment variable sets the default (tools/progress.py honours the same variable).
if("$ENV{MS2_PHYSX}" STREQUAL "283")
    set(_ms2_physx_default "283")
else()
    set(_ms2_physx_default "284")
endif()
set(MS2_PHYSX_VERSION "${_ms2_physx_default}" CACHE STRING "PhysX SDK headers for the game build: 284 or 283")
if(MS2_PHYSX_VERSION STREQUAL "283")
    list(TRANSFORM MS2_ENGINE_INCLUDE_DIRS REPLACE "physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/"
         "physx283/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.3/")
endif()

# DirectX SDK (June 2010) headers the Windows SDK lacks (d3dx9*.h, ...), through a symlink overlay so that the Windows SDK's
# d3d9/d3d11/dxgi headers still win (the same trick as engine/gamebryo/CMakeLists.txt). tools/progress.py builds the same
# overlay in build/ms2-engine-dxsdk (keep both in sync). COPY_ON_ERROR: native Windows without symlink privilege copies.
set(MS2_DXSDK_DIR "${CMAKE_CURRENT_LIST_DIR}/../third_party/dxsdk/DXSDK" CACHE PATH "DirectX SDK (June 2010) root")
set(MS2_WINSDK_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/../third_party/msvc/Windows Kits/10/Include/10.0.19041.0" CACHE PATH
    "Windows SDK include root (decides which DXSDK headers are shadowed)")
set(MS2_ENGINE_OVERLAY "${CMAKE_BINARY_DIR}/ms2-engine-dxsdk")
set(MS2_ENGINE_OVERLAY_PREFERRED "${CMAKE_BINARY_DIR}/ms2-engine-dxsdk-preferred")
file(MAKE_DIRECTORY "${MS2_ENGINE_OVERLAY}" "${MS2_ENGINE_OVERLAY_PREFERRED}")
file(GLOB _ms2_winsdk "${MS2_WINSDK_INCLUDE}/um/*" "${MS2_WINSDK_INCLUDE}/shared/*")
set(_ms2_winsdk_lc)
foreach(h ${_ms2_winsdk})
    get_filename_component(n "${h}" NAME)
    string(TOLOWER "${n}" n)
    list(APPEND _ms2_winsdk_lc "${n}")
endforeach()
file(GLOB _ms2_dxh RELATIVE "${MS2_DXSDK_DIR}/Include" "${MS2_DXSDK_DIR}/Include/*")
foreach(h ${_ms2_dxh})
    string(TOLOWER "${h}" hl)
    if(hl IN_LIST _ms2_winsdk_lc)
        continue()
    endif()
    foreach(n "${h}" "${hl}")
        if(NOT EXISTS "${MS2_ENGINE_OVERLAY}/${n}")
            file(CREATE_LINK "${MS2_DXSDK_DIR}/Include/${h}" "${MS2_ENGINE_OVERLAY}/${n}" COPY_ON_ERROR SYMBOLIC)
        endif()
    endforeach()
endforeach()
foreach(n XInput.h xinput.h)
    if(NOT EXISTS "${MS2_ENGINE_OVERLAY_PREFERRED}/${n}")
        file(CREATE_LINK "${MS2_DXSDK_DIR}/Include/XInput.h" "${MS2_ENGINE_OVERLAY_PREFERRED}/${n}" COPY_ON_ERROR SYMBOLIC)
    endif()
endforeach()

# Apply to `target` (the ms2game OBJECT library).
function(ms2_engine_flags target)
    set(_dirs)
    foreach(d ${MS2_ENGINE_INCLUDE_DIRS})
        # collapse ".." textually: ninja lowercases /showIncludes paths containing it, so deps never match on Linux
        get_filename_component(_d "${MS2_ENGINE_ROOT}/${d}" ABSOLUTE)
        list(APPEND _dirs "${_d}")
    endforeach()
    target_include_directories(${target} BEFORE PRIVATE "${MS2_ENGINE_OVERLAY_PREFERRED}")
    target_include_directories(${target} PRIVATE ${_dirs})
    target_include_directories(${target} AFTER PRIVATE "${MS2_ENGINE_OVERLAY}")
    target_compile_definitions(${target} PRIVATE ${MS2_ENGINE_DEFINITIONS})
    # Hook DLL only (not progress.py): it runs inside the exe, which already ran the engine's header-inline static
    # initialisers (SDM objects, key-loader registration); a second run would double-register. See the // MS2: guards.
    target_compile_definitions(${target} PRIVATE MS2_NO_ENGINE_STATIC_INIT)
    # clang-cl compiles as C++17 where the STL enforces matching allocator value types; the engine's CustomAllocator uses
    # the mapped pair type for multimaps (the cl 19.16 /std:c++14 build does not check).
    target_compile_definitions(${target} PRIVATE _ENFORCE_MATCHING_ALLOCATORS=0)
endfunction()
