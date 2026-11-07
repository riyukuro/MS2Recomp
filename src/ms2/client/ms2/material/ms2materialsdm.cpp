// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2Material StaticDataManager registration (see
// ms2materialsdm.h). No __FILE__ strings; file name guessed from the Gamebryo <lib>SDM.cpp convention.
// MS2-UNIT: ?\ms2materialsdm.cpp
// MS2-RANGE: 0x142756a00-0x142756aa0 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <efd/StaticDataManager.h>
#include "ms2/client/ms2/material/ms2materialsdm.h"
#include "ms2/client/ms2/material/ms2materiallibrary.h"

// @0x142756a00
EE_IMPLEMENT_SDM_CONSTRUCTOR(MS2Material, "NiMesh NiFloodgate NiMain");

// @0x142756a60
void MS2MaterialSDM::Init()
{
    EE_IMPLEMENT_SDM_INIT_CHECK();
    MS2MaterialLibrary::InitFromSDM();
}

// @0x142756a80
void MS2MaterialSDM::Shutdown()
{
    EE_IMPLEMENT_SDM_SHUTDOWN_CHECK();
    MS2MaterialLibrary::_SDMShutdown();
}

// The TU's own MS2MaterialSDMObject (the header-static pattern of Gamebryo's <lib>SDM.cpp): its initializer leads this
// TU's .text$di run, after softparticlesmaterial.cpp's, and calls the constructor out of line. unit_140105110 holds a
// second copy at 0x140106fb0. The exe already ran it, so only the byte-match build defines it.
// MS2-RANGE: 0x14014d250-0x14014d260 .text$di
#ifndef MS2_HOOK_DLL
#pragma inline_depth(0)  // the exe jumps to the constructor; cl 19.16 would inline it
// @0x14014d250
static MS2MaterialSDM MS2MaterialSDMObject;
#endif
