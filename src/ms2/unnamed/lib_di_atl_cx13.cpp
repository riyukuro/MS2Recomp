// Executable-derived ATL module initialization recovery.
// MS2-UNIT: lib_di_atl
// MS2-RANGE: 0x140122840-0x1401228f3 .text$di
// MS2-RANGE: 0x140122900-0x140122993 .text$di
// MS2-RANGE: 0x140122ee0-0x140122f93 .text$di
// MS2-RANGE: 0x140122fa0-0x140123033 .text$di
// MS2-RANGE: 0x14012d520-0x14012d5d6 .text$di
// MS2-RANGE: 0x14012d5e0-0x14012d676 .text$di
// MS2-RANGE: 0x14014d124-0x14014d144 .text$di
// MS2-RANGE: 0x14014d144-0x14014d164 .text$di
// MS2-RANGE: 0x14014d16c-0x14014d18c .text$di
// MS2-RANGE: 0x14014d18c-0x14014d1ac .text$di
// MS2-RANGE: 0x14014d1ac-0x14014d1cc .text$di
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <new>

extern "C" IMAGE_DOS_HEADER __ImageBase;
extern void FUN_142cc4300();
extern void FUN_142cc4390();
extern void FUN_142cc4590();
extern void FUN_142cc4620();
extern void FUN_142cc5d00();
extern void FUN_142cc5d90();
extern void FUN_142cc99b4();
extern void FUN_142cc99d4();
extern void FUN_142cc9a18();
extern void FUN_142cc9a38();

namespace
{
// CComCriticalSection::Init; the copies differ in whether _AtlInitializeCriticalSectionEx took the Vista path.
template <bool UseInitializeEx>
__forceinline HRESULT AtlCsInit(LPCRITICAL_SECTION cs) throw()
{
    HRESULT hRes = S_OK;
    if (!(UseInitializeEx ? InitializeCriticalSectionEx(cs, 0, 0) : InitializeCriticalSectionAndSpinCount(cs, 0)))
        hRes = HRESULT_FROM_WIN32(GetLastError());
    return hRes;
}

// CAtlComModule's inline constructor (atlbase.h) over its critical-section variant.
template <bool UseInitializeEx>
struct AtlComModuleCtor : ATL::_ATL_COM_MODULE
{
    __forceinline AtlComModuleCtor() throw()
    {
        cbSize = 0;
        m_hInstTypeLib = reinterpret_cast<HINSTANCE>(&__ImageBase);
        m_ppAutoObjMapFirst = &ATL::__pobjMapEntryFirst + 1;
        m_ppAutoObjMapLast = &ATL::__pobjMapEntryLast;
        if (FAILED(AtlCsInit<UseInitializeEx>(&m_csObjMap.m_sec)))
        {
            ATL::CAtlBaseModule::m_bInitFailed = true;
            return;
        }
        cbSize = sizeof(ATL::_ATL_COM_MODULE);
    }
};

// CAtlWinModule's inline constructor with AtlWinModuleInit inlined.
template <bool UseInitializeEx>
struct AtlWinModuleCtor : ATL::_ATL_WIN_MODULE
{
    __forceinline AtlWinModuleCtor() throw()
    {
        cbSize = sizeof(ATL::_ATL_WIN_MODULE);
        m_pCreateWndList = NULL;
        HRESULT hr = AtlCsInit<UseInitializeEx>(&m_csWindowCreate.m_sec);
        if (FAILED(hr))
        {
            ATL::CAtlBaseModule::m_bInitFailed = true;
            cbSize = 0;
            return;
        }
    }
};

template <bool UseInitializeEx>
__forceinline void InitComModule(void (*terminate)())
{
    new (&ATL::_AtlComModule) AtlComModuleCtor<UseInitializeEx>();
    std::atexit(terminate);
}

template <bool UseInitializeEx>
__forceinline void InitWinModule(void (*terminate)())
{
    new (&ATL::_AtlWinModule) AtlWinModuleCtor<UseInitializeEx>();
    std::atexit(terminate);
}
}

// Three linked ATL copies initialize the same selectany COM-module object.
// clears the stored module fields, initializes its critical section, records failure and registers its matching exit routine.
// @0x140122840
void FUN_140122840()
{
    InitComModule<false>(FUN_142cc4300);
}

// initializes the selectany Windows-module object and registers its matching exit routine.
// @0x140122900
void FUN_140122900()
{
    InitWinModule<false>(FUN_142cc4390);
}

// duplicate ATL COM-module initialization emitted by another linked object.
// @0x140122ee0
void FUN_140122ee0()
{
    InitComModule<false>(FUN_142cc4590);
}

// duplicate ATL Windows-module initialization emitted by another linked object.
// @0x140122fa0
void FUN_140122fa0()
{
    InitWinModule<false>(FUN_142cc4620);
}

// initializes the selectany COM-module object with InitializeCriticalSectionEx.
// @0x14012d520
void FUN_14012d520()
{
    InitComModule<true>(FUN_142cc5d00);
}

// initializes the selectany Windows-module object with InitializeCriticalSectionEx.
// @0x14012d5e0
void FUN_14012d5e0()
{
    InitWinModule<true>(FUN_142cc5d90);
}

// calls ATL's CAtlComModule constructor on the executable global and installs its matching atexit cleanup.
// @0x14014d124
void FUN_14014d124()
{
    ATL::_AtlComModule.CAtlComModule::CAtlComModule();
    std::atexit(FUN_142cc99b4);
}

// calls ATL's CAtlWinModule constructor on the executable global and installs its matching atexit cleanup.
// @0x14014d144
void FUN_14014d144()
{
    ATL::_AtlWinModule.CAtlWinModule::CAtlWinModule();
    std::atexit(FUN_142cc99d4);
}

// duplicate CAtlComModule constructor initializer from another linked object.
// @0x14014d16c
void FUN_14014d16c()
{
    ATL::_AtlComModule.CAtlComModule::CAtlComModule();
    std::atexit(FUN_142cc9a18);
}

// duplicate CAtlWinModule constructor initializer from another linked object.
// @0x14014d18c
void FUN_14014d18c()
{
    ATL::_AtlWinModule.CAtlWinModule::CAtlWinModule();
    std::atexit(FUN_142cc9a38);
}

// calls ATL's CAtlBaseModule constructor on the executable global and registers its shutdown callback.
// @0x14014d1ac
void FUN_14014d1ac()
{
    new (&ATL::_AtlBaseModule) ATL::CAtlBaseModule();
    std::atexit([] { ATL::_AtlBaseModule.~CAtlBaseModule(); });
}
