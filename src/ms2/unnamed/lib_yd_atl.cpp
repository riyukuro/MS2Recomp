// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the ATL module atexit destructors that the
// lib_di_atl initializers register. Two linked objects each carry the selectany _AtlComModule / _AtlWinModule
// pair, so each destructor appears twice.
// MS2-UNIT: lib_yd_atl
// MS2-RANGE: 0x142cc99b4-0x142cc9a88 .text$yd
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

namespace
{
// ~CAtlComModule (atlbase.h) with Term() kept out of line, as the exe inlines it into the atexit thunk.
struct AtlComModuleDtor : ATL::_ATL_COM_MODULE
{
    __forceinline ~AtlComModuleDtor()
    {
        reinterpret_cast<ATL::CAtlComModule*>(this)->Term();
    }
};

// ~CAtlWinModule (atlbase.h): Term() inlined to AtlWinModuleTerm, then the members' destructors.
struct AtlWinModuleDtor : ATL::_ATL_WIN_MODULE
{
    __forceinline ~AtlWinModuleDtor()
    {
        ATL::AtlWinModuleTerm(this, ATL::_AtlBaseModule.GetModuleInstance());
    }
};
}

// ~CAtlComModule: Term() under an EH frame.
// @0x142cc99b4
void FUN_142cc99b4()
{
    reinterpret_cast<AtlComModuleDtor&>(ATL::_AtlComModule).~AtlComModuleDtor();
}

// ~CAtlWinModule: AtlWinModuleTerm with the base module's instance, then the window-class atom array's RemoveAll.
// @0x142cc99d4
#pragma optimize("s", on)                                       // cl builds ??__F atexit thunks for size: `and [m], 0` stores
void FUN_142cc99d4()
{
    reinterpret_cast<AtlWinModuleDtor&>(ATL::_AtlWinModule).~AtlWinModuleDtor();
}
#pragma optimize("", on)

// The second object's copies.
// @0x142cc9a18
void FUN_142cc9a18()
{
    reinterpret_cast<AtlComModuleDtor&>(ATL::_AtlComModule).~AtlComModuleDtor();
}

// @0x142cc9a38
#pragma optimize("s", on)
void FUN_142cc9a38()
{
    reinterpret_cast<AtlWinModuleDtor&>(ATL::_AtlWinModule).~AtlWinModuleDtor();
}
#pragma optimize("", on)

// ~CAtlBaseModule on the exe's _AtlBaseModule; FUN_14014d1ac registers it.
// @0x142cc9a7c
void DestroyAtlBaseModule()
{
    ATL::_AtlBaseModule.~CAtlBaseModule();
}
