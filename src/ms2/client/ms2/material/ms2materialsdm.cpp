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

// MS2: no MS2MaterialSDM object is defined in this TU. The exe's initializer at 0x140106fb0 calls this constructor and is
// the MS2MaterialSDMObject in unit_140105110; 0x14014d250 is another out-of-line initializer.
