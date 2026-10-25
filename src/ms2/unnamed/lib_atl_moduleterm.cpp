// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the out-of-line ATL module destructors that the
// lib_di_atl selectany initializers hand over as their exit routines. Three linked objects each carry the
// _AtlComModule / _AtlWinModule pair, so each destructor appears three times (the atexit thunks are lib_yd_atl).
// MS2-UNIT: lib_atl_moduleterm
// MS2-RANGE: 0x142cc4300-0x142cc4470 .text$mn
// MS2-RANGE: 0x142cc4590-0x142cc4700 .text$mn
// MS2-RANGE: 0x142cc5d00-0x142cc5e70 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

// ~CAtlComModule: Term() releases the cached class factories (DecodePointer'd), deletes the object-map lock and
// clears cbSize.
// MS2-FUNCTIONAL: calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc4300
void FUN_142cc4300()
{
    ATL::_AtlComModule.~CAtlComModule();
}

// ~CAtlWinModule: AtlWinModuleTerm with the base module's instance (unregisters the window classes), then the
// atom array's destructor.
// MS2-FUNCTIONAL: calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc4390
void FUN_142cc4390()
{
    ATL::_AtlWinModule.~CAtlWinModule();
}

// The second object's copies.
// MS2-FUNCTIONAL: calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc4590
void FUN_142cc4590()
{
    ATL::_AtlComModule.~CAtlComModule();
}

// MS2-FUNCTIONAL: calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc4620
void FUN_142cc4620()
{
    ATL::_AtlWinModule.~CAtlWinModule();
}

// The third object's copies.
// MS2-FUNCTIONAL: calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc5d00
void FUN_142cc5d00()
{
    ATL::_AtlComModule.~CAtlComModule();
}

// MS2-FUNCTIONAL: calls the ATL 14.16 destructor out of line; the exe inlines it
// @0x142cc5d90
void FUN_142cc5d90()
{
    ATL::_AtlWinModule.~CAtlWinModule();
}
