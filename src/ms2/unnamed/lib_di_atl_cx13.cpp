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
extern void FUN_141803560(void* self);
extern void FUN_141803610(void* self);
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
template <typename T>
T* AtlExeAddress(std::uintptr_t address)
{
    return reinterpret_cast<T*>(address);
}

void InitComModule(bool useInitializeEx, void (*terminate)())
{
    auto* const com = reinterpret_cast<std::uint8_t*>(&ATL::_AtlComModule);
    auto* const initFailed = reinterpret_cast<std::uint8_t*>(&ATL::CAtlBaseModule::m_bInitFailed);
    *reinterpret_cast<std::uint64_t*>(com + 0x20) = 0;
    *reinterpret_cast<std::uint64_t*>(com + 0x28) = 0;
    *reinterpret_cast<std::uint64_t*>(com + 0x30) = 0;
    *reinterpret_cast<std::uint64_t*>(com + 0x38) = 0;
    *reinterpret_cast<std::uint64_t*>(com + 0x40) = 0;
    *reinterpret_cast<std::uint64_t*>(com) = 0;
    *reinterpret_cast<std::uintptr_t*>(com + 8) = reinterpret_cast<std::uintptr_t>(&__ImageBase);
    *reinterpret_cast<std::uintptr_t*>(com + 0x10) = reinterpret_cast<std::uintptr_t>(&ATL::__pobjMapEntryLast);
    *reinterpret_cast<std::uintptr_t*>(com + 0x18) = reinterpret_cast<std::uintptr_t>(&ATL::__pobjMapEntryLast);

    const BOOL initialized = useInitializeEx
        ? InitializeCriticalSectionEx(reinterpret_cast<LPCRITICAL_SECTION>(com + 0x20), 0, 0)
        : InitializeCriticalSectionAndSpinCount(reinterpret_cast<LPCRITICAL_SECTION>(com + 0x20), 0);
    if (!initialized)
    {
        const DWORD error = GetLastError();
        if (error != 0)
        {
            *initFailed = 1;
            std::atexit(terminate);
            return;
        }
    }
    *reinterpret_cast<std::uint64_t*>(com) = 0x48;
    std::atexit(terminate);
}

void InitWinModule(bool useInitializeEx, void (*terminate)())
{
    auto* const win = reinterpret_cast<std::uint8_t*>(&ATL::_AtlWinModule);
    auto* const initFailed = reinterpret_cast<std::uint8_t*>(&ATL::CAtlBaseModule::m_bInitFailed);
    *reinterpret_cast<std::uint64_t*>(win) = 0x48;
    for (unsigned offset = 8; offset <= 0x40; offset += 8)
        *reinterpret_cast<std::uint64_t*>(win + offset) = 0;

    const BOOL initialized = useInitializeEx
        ? InitializeCriticalSectionEx(reinterpret_cast<LPCRITICAL_SECTION>(win + 8), 0, 0)
        : InitializeCriticalSectionAndSpinCount(reinterpret_cast<LPCRITICAL_SECTION>(win + 8), 0);
    if (!initialized && GetLastError() != 0)
    {
        *initFailed = 1;
        *reinterpret_cast<std::uint64_t*>(win) = 0;
    }
    std::atexit(terminate);
}
}

// Three linked ATL copies initialize the same selectany COM-module object.
// MS2-FUNCTIONAL: clears the stored module fields, initializes its critical section, records failure and registers its matching exit routine.
// @0x140122840
void FUN_140122840()
{
    InitComModule(false, FUN_142cc4300);
}

// MS2-FUNCTIONAL: initializes the selectany Windows-module object and registers its matching exit routine.
// @0x140122900
void FUN_140122900()
{
    InitWinModule(false, FUN_142cc4390);
}

// MS2-FUNCTIONAL: duplicate ATL COM-module initialization emitted by another linked object.
// @0x140122ee0
void FUN_140122ee0()
{
    InitComModule(false, FUN_142cc4590);
}

// MS2-FUNCTIONAL: duplicate ATL Windows-module initialization emitted by another linked object.
// @0x140122fa0
void FUN_140122fa0()
{
    InitWinModule(false, FUN_142cc4620);
}

// MS2-FUNCTIONAL: initializes the selectany COM-module object with InitializeCriticalSectionEx.
// @0x14012d520
void FUN_14012d520()
{
    InitComModule(true, FUN_142cc5d00);
}

// MS2-FUNCTIONAL: initializes the selectany Windows-module object with InitializeCriticalSectionEx.
// @0x14012d5e0
void FUN_14012d5e0()
{
    InitWinModule(true, FUN_142cc5d90);
}

// MS2-FUNCTIONAL: calls ATL's CAtlComModule constructor on the executable global and installs its matching atexit cleanup.
// @0x14014d124
void FUN_14014d124()
{
    FUN_141803560(&ATL::_AtlComModule);
    std::atexit(FUN_142cc99b4);
}

// MS2-FUNCTIONAL: calls ATL's CAtlWinModule constructor on the executable global and installs its matching atexit cleanup.
// @0x14014d144
void FUN_14014d144()
{
    FUN_141803610(&ATL::_AtlWinModule);
    std::atexit(FUN_142cc99d4);
}

// MS2-FUNCTIONAL: duplicate CAtlComModule constructor initializer from another linked object.
// @0x14014d16c
void FUN_14014d16c()
{
    FUN_141803560(&ATL::_AtlComModule);
    std::atexit(FUN_142cc9a18);
}

// MS2-FUNCTIONAL: duplicate CAtlWinModule constructor initializer from another linked object.
// @0x14014d18c
void FUN_14014d18c()
{
    FUN_141803610(&ATL::_AtlWinModule);
    std::atexit(FUN_142cc9a38);
}

// MS2-FUNCTIONAL: calls ATL's CAtlBaseModule constructor on the executable global and registers its shutdown callback.
// @0x14014d1ac
void FUN_14014d1ac()
{
    new (&ATL::_AtlBaseModule) ATL::CAtlBaseModule();
    std::atexit([] { ATL::_AtlBaseModule.~CAtlBaseModule(); });
}
