// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A small TU between enchantscrollslot and fishingmanager (the
// v2525 TU map gives [0x140cd7ce0, 0x140cd7e40)): two world-service helpers (the current field data, the name of the
// current map in string table 3) and the out-of-line ctor of the fishing line object (Unk_FishLine, the 0xa8-byte member
// of CFishingGuideObject at +0xda8; its dtor 0x140cd7e40 opens fishingmanager.cpp). Function names unknown.
// MS2-UNIT: unit_140cd7ce0
// MS2-RANGE: 0x140cd7ce0-0x140cd7e40 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/client/ms2/cubecraft_1.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140cd7ce0
MS2Ptr<CFieldDataCli> FUN_140cd7ce0()
{
    return WorldService::GetInstance()->FUN_141bd30a0();
}
MS2_REPLACE(0x140CD7CE0, FUN_140cd7ce0, 56, 0x82029F8F);

// @0x140cd7d20
CStringW FUN_140cd7d20()
{
    return TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, WorldService::GetInstance()->FUN_141bd3060());
}
MS2_REPLACE(0x140CD7D20, FUN_140cd7d20, 86, 0x9225298E);

// The fishing line's ctor (Unk_FishLine of cubecraft_1.h).
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// @0x140cd7d80
Unk_FishLine::Unk_FishLine()
{
    m_pGuide = 0;
    m_nKind = 0;
    m_kTarget = efd::Point3::ZERO;
    m_kLanding = efd::Point3::ZERO;
    m_nEffect = 0;
}
