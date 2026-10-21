// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The code half of the translation unit whose dynamic
// initializers are unit_140105110 (Scaleform identity matrices, the Winsock start-up object, the UI string constants,
// the ATL static initializers and the Gamebryo library SDM objects / key loaders): the game's Gamebryo bootstrap TU,
// CU name unknown. Its own code is EE_USE_DEFAULT_ALLOCATOR (efd::CreateGlobalMemoryAllocator) and a file-static
// crash dumper (an unhandled-exception filter writing "<exe>.<date>.<time>.dmp" with MiniDumpWriteDump); everything else
// in the range is header code this TU emitted first: the efd StandardAllocator (SmallObjectAllocator<ExternalMemAllocator>)
// it instantiates, Scaleform's SysAllocMalloc singleton / GFx::System, the ATL module objects and trace categories, and
// the efd::SmartPointer / vector-deleting-destructor COMDATs of the Gamebryo headers.
// MS2-UNIT: unit_141803210
// MS2-RANGE: 0x141803210-0x141808730 .text$mn
// MS2-RANGE: 0x1401073f0-0x140107420 .text$di
// MS2-RANGE: 0x142cb9920-0x142cb9940 .text$yd
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0ExternalMemAllocator@efd@@QEAA@XZ 0x141803900 ; prop
// MS2-PIN: ??0IAllocator@efd@@QEAA@XZ 0x1418039c0 ; prop
// MS2-PIN: ??1?$CSimpleArray@GV?$CSimpleArrayEqualHelper@G@ATL@@@ATL@@QEAA@XZ 0x141803c20 ; unique
// MS2-PIN: ??1CAtlWinModule@ATL@@QEAA@XZ 0x141804160 ; unique
// MS2-PIN: ??1CComCriticalSection@ATL@@QEAA@XZ 0x141804190 ; prop
// MS2-PIN: ??1_ATL_COM_MODULE70@ATL@@QEAA@XZ 0x141804450 ; unique
// MS2-PIN: ??1_ATL_WIN_MODULE70@ATL@@QEAA@XZ 0x141804470 ; unique
// MS2-PIN: ?AtlWinModuleTerm@ATL@@YAJPEAU_ATL_WIN_MODULE70@1@PEAUHINSTANCE__@@@Z 0x141806dd0 ; unique
// MS2-PIN: ?CreateMemoryLogHandler@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAXXZ 0x141806f90 ; unique
// MS2-PIN: ?CreateMemoryLogHandler@ExternalMemAllocator@efd@@UEAAXXZ 0x141806fa0 ; unique
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x1418071a0 ; unique
// MS2-PIN: ?GetRTTI@NiShadowCubeMap@@UEBAPEBVNiRTTI@@XZ 0x1418071b0 ; unique
// MS2-PIN: ?GetRTTI@NiShadowMap@@UEBAPEBVNiRTTI@@XZ 0x1418071c0 ; unique
// MS2-PIN: ?GetSize@?$CSimpleArray@GV?$CSimpleArrayEqualHelper@G@ATL@@@ATL@@QEBAHXZ 0x1418071d0 ; unique
// MS2-PIN: ?GetSizeFromAddress@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@AEAA_KPEAX@Z 0x1418071e0 ; unique
// MS2-PIN: ?Initialize@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAXXZ 0x1418075f0 ; unique
// MS2-PIN: ?PerThreadInit@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAXXZ 0x141807630 ; unique
// MS2-PIN: ?PerThreadInit@IAllocator@efd@@UEAAXXZ 0x141807640 ; unique
// MS2-PIN: ?PerThreadShutdown@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAXXZ 0x141807650 ; unique
// MS2-PIN: ?PerThreadShutdown@IAllocator@efd@@UEAAXXZ 0x141807660 ; unique
// MS2-PIN: ?RemoveAll@?$CSimpleArray@GV?$CSimpleArrayEqualHelper@G@ATL@@@ATL@@QEAAXXZ 0x141807b40 ; unique
// MS2-PIN: ?SetMarker@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAA_NPEBD00@Z 0x141807e50 ; unique
// MS2-PIN: ?SetMarker@ExternalMemAllocator@efd@@UEAA_NPEBD00@Z 0x141807ea0 ; unique
// MS2-PIN: ?SetSizeToAddress@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@AEAAXPEAX_K@Z 0x141807ec0 ; unique
// MS2-PIN: ?Shutdown@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAXXZ 0x141808010 ; unique
// MS2-PIN: ?Shutdown@ExternalMemAllocator@efd@@UEAAXXZ 0x141808040 ; unique
// MS2-PIN: ?Term@CAtlWinModule@ATL@@QEAAXXZ 0x141808110 ; unique
// MS2-PIN: ?TrackAllocate@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAA_NQEBX_KVMemHint@2@W4MemEventType@2@PEBDH4@Z 0x141808160 ; unique
// MS2-PIN: ?TrackAllocate@ExternalMemAllocator@efd@@UEAA_NQEBX_KVMemHint@2@W4MemEventType@2@PEBDH4@Z 0x1418081e0 ; unique
// MS2-PIN: ?TrackDeallocate@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAA_NQEBXW4MemEventType@2@@Z 0x141808200 ; unique
// MS2-PIN: ?TrackDeallocate@ExternalMemAllocator@efd@@UEAA_NQEBXW4MemEventType@2@@Z 0x141808250 ; unique
// MS2-PIN: ?VerifyAddress@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAA_NPEBX@Z 0x1418084e0 ; unique
// MS2-PIN: ?VerifyAddress@ExternalMemAllocator@efd@@UEAA_NPEBX@Z 0x141808520 ; unique
// MS2-PINS-END tplpin
#define MS2_NO_ENGINE_STATIC_INIT
#ifndef MS2_HOOK_DLL
// This TU saw the Scaleform headers without SF_BUILD_STATICLIB: SF_EXPORT is __declspec(dllexport), so it emits (and the exe
// exports, ordinals 1-20) the inline SF_EXPORT members and default-constructor closures it reached first. The hook DLL keeps
// the static-library form.
#undef SF_BUILD_STATICLIB
#endif
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <winsock2.h>
#include <dbghelp.h>
#include "GFxConfig.h"
#include "Kernel/SF_System.h"
#include "Kernel/SF_Threads.h"
#include "GFx/GFx_Loader.h"
#include "Kernel/HeapPT/HeapPT_SysAllocMalloc.h"
#include "Kernel/HeapPT/HeapPT_SysAllocWinAPI.h"
#include "Render/Render_Matrix2x4.h"
#include "Render/Render_Matrix3x4.h"
#include "Render/Render_Matrix4x4.h"
#include <atlimage.h>

#ifndef NOMINMAX
#define NOMINMAX
#endif
#undef min
#undef max
#include <NiMain.h>
#include <efdPhysX/PhysXSDKManager.h>
#include <NSFParserLib.h>
#include <NiAnimation.h>
#include <NiBinaryShaderLib.h>
#include <NiCollision.h>
#include <NiDX9RendererSetup.h>
#include <NiStreamProcessor.h>
#include <NiParticle.h>
#include <NiPhysX.h>
#include <NiTerrainLib.h>
#include <NiInput.h>
#include <efd/DefaultInitializeMemoryManager.h>

#pragma comment(lib, "dbghelp.lib")     // MiniDumpWriteDump
#pragma function(strlen)                // the exe calls the CRT strlen (0x14280f01e) here

// ---- Scaleform matrix members this TU instantiated (exported, see SF_EXPORT above; the Identity statics are in
// unit_140105110) ----

template Scaleform::Render::Matrix2x4<float>::Matrix2x4();
template Scaleform::Render::Matrix3x4<float>::Matrix3x4();
template Scaleform::Render::Matrix4x4<float>::Matrix4x4();
template float Scaleform::Render::Matrix2x4<float>::GetXScale() const;
template float Scaleform::Render::Matrix2x4<float>::GetYScale() const;

// ---- smart-pointer array deleters (efd::SmartPointer<T> destructor + vector deleting destructor COMDATs) ----
// The headers above emit most of the TU's SmartPointer array deleters. The rest are byte-identical for every T and
// have no callers left in the exe (their users were folded into other TUs' copies). These are the remaining
// NiTObjectArray<...Ptr> element types of the included headers; which T the exe used is not recoverable.
template void NiTNewInterface<NiPhysXPropPtr>::Deallocate(NiPhysXPropPtr* pArray);
template void NiTNewInterface<NiMaterialNodePtr>::Deallocate(NiMaterialNodePtr* pArray);
template void NiTNewInterface<NiMaterialResourcePtr>::Deallocate(NiMaterialResourcePtr* pArray);
template void NiTNewInterface<NiCodeBlockPtr>::Deallocate(NiCodeBlockPtr* pArray);
template void NiTNewInterface<NiShaderDescPtr>::Deallocate(NiShaderDescPtr* pArray);

// ---- ATL module atom array (_ATL_WIN_MODULE70::m_rgWindowClassAtoms) ----
// corecrt's memmove_s is `static __inline`, so every TU that calls it keeps a private copy; this TU's (0x141808610) is
// reached from CSimpleArray<ATOM>::RemoveAt -> ATL::Checked::memmove_s, whose COMDATs the linker took from another TU.
template BOOL ATL::CSimpleArray<ATOM>::RemoveAt(int nIndex);

// ---- the default Gamebryo allocator (0x141803210 CreateGlobalMemoryAllocator) ----

EE_USE_DEFAULT_ALLOCATOR

// ---- Winsock start-up object (the static is unit_140105110's s_wsaStartup) ----

struct Unk_WsaStartup
{
    int m_nResult;
    Unk_WsaStartup();
    ~Unk_WsaStartup();
};

// 0x141803bb0
Unk_WsaStartup::Unk_WsaStartup()
{
    m_nResult = 0;
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 0), &wsaData) == 0 && LOBYTE(wsaData.wVersion);
}

// 0x1418044a0
Unk_WsaStartup::~Unk_WsaStartup()
{
    for (int i = 0; m_nResult && i < 50; i++)
        Sleep(100);
    WSACleanup();
}

// ---- small handle types whose out-of-line constructors live in this TU (statics in unit_140107420 / unit_140135c50) ----

class Unk_BuddyHandleBase { public: Unk_BuddyHandleBase(void* h); void* handle; };    // ctor 0x1401cd130 (buddy.cpp)
class Unk_1418036e0 : public Unk_BuddyHandleBase { public: Unk_1418036e0(void* h); };
class Unk_1418036b0 { public: Unk_1418036b0(); private: void* m_p; int m_n; };

// 0x1418036b0
Unk_1418036b0::Unk_1418036b0()
{
    m_p = 0;
    m_n = 0;
}

// 0x1418036e0
Unk_1418036e0::Unk_1418036e0(void* h) : Unk_BuddyHandleBase(h)
{
}

// ---- crash dumper ----

// The unhandled-exception filter object (0x143aedbd0, 0x190 bytes): writes "<module path>.<yyyymmdd>.<hhmmss>.dmp" next
// to the exe, then chains to the previous filter. The callbacks at +0x148 and the flag at +0x140 are never set in this
// build (no other code references the object).
class Unk_CrashDumper
{
public:
    typedef void (*Callback)(int nPhase, const char* pszDumpPath);

    Unk_CrashDumper();
    ~Unk_CrashDumper();
    LONG Write(EXCEPTION_POINTERS* pException);
    static LONG WINAPI Filter(EXCEPTION_POINTERS* pException);

private:
    CRITICAL_SECTION m_cs;                          // +0x0
    volatile DWORD m_nBusy;                         // +0x28 (winnt.h's out-of-line InterlockedExchange overload)
    char m_szDumpPath[MAX_PATH];                    // +0x2c
    LPTOP_LEVEL_EXCEPTION_FILTER m_pPrevFilter;     // +0x130
    HANDLE m_hFile;                                 // +0x138
    int m_bHandled;                                 // +0x140 EXCEPTION_EXECUTE_HANDLER instead of the previous filter's
    Callback m_pfnCallback;                         // +0x148 0 before / 1 after the dump
    void* m_150;                                    // +0x150 (+0x150..+0x188 cleared by the ctor, otherwise unused)
    void* m_158;
    void* m_160;
    void* m_168;
    void* m_170;
    void* m_178;
    void* m_180;
    void* m_188;
};

static Unk_CrashDumper s_crashDumper;

// 0x141803710
Unk_CrashDumper::Unk_CrashDumper()
{
    InitializeCriticalSection(&m_cs);
    m_nBusy = 0;
    m_hFile = 0;
    m_pfnCallback = 0;
    m_150 = 0;
    m_158 = 0;
    m_160 = 0;
    m_168 = 0;
    m_170 = 0;
    m_178 = 0;
    m_180 = 0;
    m_188 = 0;
    m_pPrevFilter = SetUnhandledExceptionFilter(Filter);
    GetModuleFileNameA(0, m_szDumpPath, MAX_PATH);
    SYSTEMTIME st;
    GetLocalTime(&st);
    wsprintfA(m_szDumpPath + strlen(m_szDumpPath), ".%d%02d%02d.%02d%02d%02d.dmp", st.wYear, st.wMonth, st.wDay,
        st.wHour, st.wMinute, st.wSecond);
}

// 0x1418041d0
Unk_CrashDumper::~Unk_CrashDumper()
{
    SetUnhandledExceptionFilter(m_pPrevFilter);
    DeleteCriticalSection(&m_cs);
}

// 0x141807670
LONG WINAPI Unk_CrashDumper::Filter(EXCEPTION_POINTERS* pException)
{
    return s_crashDumper.Write(pException);
}

// 0x141808270
LONG Unk_CrashDumper::Write(EXCEPTION_POINTERS* pException)
{
    while (InterlockedExchange(&m_nBusy, 1))
        Sleep(100);
    if (m_pfnCallback)
        m_pfnCallback(0, m_szDumpPath);
    EnterCriticalSection(&m_cs);
    m_hFile = CreateFileA(m_szDumpPath, GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_FLAG_WRITE_THROUGH, 0);
    if (m_hFile != INVALID_HANDLE_VALUE)
    {
        MINIDUMP_EXCEPTION_INFORMATION info;
        info.ThreadId = GetCurrentThreadId();
        info.ExceptionPointers = pException;
        info.ClientPointers = FALSE;
        MINIDUMP_TYPE eType = MiniDumpNormal;
        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), m_hFile, eType, pException ? &info : 0, 0, 0);
        CloseHandle(m_hFile);
    }
    m_hFile = 0;
    if (m_pfnCallback)
        m_pfnCallback(1, m_szDumpPath);
    LeaveCriticalSection(&m_cs);
    m_nBusy = 0;
    do
        Sleep(1000);
    while (m_nBusy);
    LONG nResult = 0;
    if (m_pPrevFilter)
        nResult = m_pPrevFilter(pException);
    return m_bHandled ? 1 : nResult;
}
// MS2-PIN: ?CreateGlobalMemoryAllocator@efd@@YAPEAVIAllocator@1@XZ 0x141803210
// MS2-PIN: ??0Unk_WsaStartup@@QEAA@XZ 0x141803bb0
// MS2-PIN: ??0Unk_CrashDumper@@QEAA@XZ 0x141803710
// MS2-PIN: ??1Unk_CrashDumper@@QEAA@XZ 0x1418041d0
// MS2-PIN: ?Filter@Unk_CrashDumper@@SAJPEAU_EXCEPTION_POINTERS@@@Z 0x141807670
// MS2-PIN: ?Write@Unk_CrashDumper@@QEAAJPEAU_EXCEPTION_POINTERS@@@Z 0x141808270
// MS2-PIN: ??__Es_crashDumper@@YAXXZ 0x1401073f0
// MS2-PIN: ??__Fs_crashDumper@@YAXXZ 0x142cb9920
// MS2-FUNCTIONAL: efd::SmallObjectAllocator / ExternalMemAllocator below are MS2-modified in the exe (object size 0x7020,
// a lock-add counter at +0x7018, Allocate throws bad_alloc on null); the stock Gamebryo headers are compiled, so the
// SmallObjectAllocator ctor/??_G/Allocate/Deallocate/Reallocate and CreateDefaultGlobalMemoryAllocator are functional.
// ??_FThread: Scaleform 4.1.18 defaults the thread stack to 0x100000, the 4.1.19 headers to 0x20000.
// MS2-PIN: ??0?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@QEAA@_K@Z 0x141803420
// MS2-PIN: ??0CComCriticalSection@ATL@@QEAA@XZ 0x141803660
// MS2-FUNCTIONAL ??0CComCriticalSection@ATL@@QEAA@XZ: the exe's copy zeroes m_sec through a memset call; the stock ATL ctor inlines it (rep stosb), same effect
// MS2-PIN: ??_G?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAPEAXI@Z 0x1418067f0
// MS2-PIN: ?Allocate@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAPEAXAEA_K0VMemHint@2@W4MemEventType@2@PEBDH3@Z 0x141806b60
// MS2-PIN: ?Allocate@ExternalMemAllocator@efd@@UEAAPEAXAEA_K0VMemHint@2@W4MemEventType@2@PEBDH3@Z 0x141806d10
// MS2-PIN: ?CreateDefaultGlobalMemoryAllocator@efd@@YAPEAVIAllocator@1@_N@Z 0x141806f20
// MS2-PIN: ?Deallocate@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAXPEAXW4MemEventType@2@_K@Z 0x141807000
// MS2-PIN: ?Reallocate@?$SmallObjectAllocator@VExternalMemAllocator@efd@@@efd@@UEAAPEAXPEAXAEA_K1VMemHint@2@W4MemEventType@2@_KPEBDH5@Z 0x141807730
// MS2-PIN: ?Reallocate@ExternalMemAllocator@efd@@UEAAPEAXPEAXAEA_K1VMemHint@2@W4MemEventType@2@_KPEBDH5@Z 0x141807ad0
// MS2-PIN: ??1?$SmartPointer@VNiTextKeyMatch@@@efd@@QEAA@XZ 0x141803f80
// MS2-PIN: ??1InterpItem@NiGeomMorpherController@@QEAA@XZ 0x141804240
// MS2-PIN: ??1TextKeyCallbackData@NiControllerSequence@@QEAA@XZ 0x141804410
// MS2-PIN: ??_EInterpItem@NiGeomMorpherController@@QEAAPEAXI@Z 0x1418060a0
// MS2-PIN: ??_ETextKeyCallbackData@NiControllerSequence@@QEAAPEAXI@Z 0x1418064a0
// MS2-PIN: ?Free@SysAllocMalloc@Scaleform@@UEAAXPEAX_K1@Z 0x141807170
// MS2-PIN: ?GetXScale@?$Matrix2x4@M@Render@Scaleform@@QEBAMXZ 0x141807330
// MS2-PIN: ?GetYScale@?$Matrix2x4@M@Render@Scaleform@@QEBAMXZ 0x1418073e0
// MS2-PIN: ?Init@CComCriticalSection@ATL@@QEAAJXZ 0x141807490
// MS2-PIN: ?Initialize@ExternalMemAllocator@efd@@UEAAXXZ 0x141807620
// MS2-PIN: ?Init@System@GFx@Scaleform@@SAXPEAVSysAllocBase@3@@Z 0x1418074e0
// MS2-PIN: ?Realloc@SysAllocMalloc@Scaleform@@UEAAPEAXPEAX_K11@Z 0x141807690
// MS2-PIN: ??1Unk_WsaStartup@@QEAA@XZ 0x1418044a0
// MS2-PIN: ??0Unk_1418036b0@@QEAA@XZ 0x1418036b0
// MS2-PIN: ??0Unk_1418036e0@@QEAA@PEAX@Z 0x1418036e0
// MS2-PIN: ??_FThread@Scaleform@@QEAAXXZ 0x1418067c0
// MS2-PIN: ?_sqrt@?$Matrix2x4@M@Render@Scaleform@@CAMM@Z 0x141808560
// MS2-PIN: memmove_s 0x141808610
// MS2-PIN: ??1?$SmartPointer@VNiSPWorkflow@@@efd@@QEAA@XZ 0x141803f20
// MS2-PIN: ??_E?$SmartPointer@VNiSPWorkflow@@@efd@@QEAAPEAXI@Z 0x141805540
// MS2-PIN: ?DecRefCount@NiSPWorkflow@@QEAAXXZ 0x141807120
