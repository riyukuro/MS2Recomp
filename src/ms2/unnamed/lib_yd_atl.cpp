// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the ATL module atexit destructors that the
// lib_di_atl initializers register. Two linked objects each carry the selectany _AtlComModule / _AtlWinModule
// pair, so each destructor appears twice.
// MS2-UNIT: lib_yd_atl
// MS2-RANGE: 0x142cc99b4-0x142cc9a7c .text$yd
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

// ~CAtlComModule: Term() under an EH frame.
// MS2-FUNCTIONAL: tail-calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc99b4
void FUN_142cc99b4()
{
    ATL::_AtlComModule.~CAtlComModule();
}

// ~CAtlWinModule: AtlWinModuleTerm with the base module's instance, then the window-class atom array's RemoveAll.
// MS2-FUNCTIONAL: tail-calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc99d4
void FUN_142cc99d4()
{
    ATL::_AtlWinModule.~CAtlWinModule();
}

// The second object's copies.
// MS2-FUNCTIONAL: tail-calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc9a18
void FUN_142cc9a18()
{
    ATL::_AtlComModule.~CAtlComModule();
}

// MS2-FUNCTIONAL: tail-calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc9a38
void FUN_142cc9a38()
{
    ATL::_AtlWinModule.~CAtlWinModule();
}
