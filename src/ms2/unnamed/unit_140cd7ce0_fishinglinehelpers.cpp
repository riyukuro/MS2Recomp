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
MS2Ptr<Unk_WsPtred298> FUN_140cd7ce0()
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

// The fishing line's ctor. Unk_FishLine (cubecraft_1.h) only proves the owner pointer and the size, so the ctor is written
// on a same-layout view: two timers (the line's flight / reel phases), the start and end points, a counter.
struct Unk_FishLineInit
{
    Unk_FishLineInit();
    void* m_pOwner;             // +0x00 (set by the guide object)
    __int64 m_08;               // +0x08
    int m_10;                   // +0x10
    Timer m_timer18;            // +0x18
    efd::Point3 m_vStart;       // +0x50
    efd::Point3 m_vEnd;         // +0x5c
    int m_68;                   // +0x68
    Timer m_timer70;            // +0x70
};
MS2_CHECK_OFFSET(Unk_FishLineInit, m_timer18, 0x18);
MS2_CHECK_OFFSET(Unk_FishLineInit, m_vStart, 0x50);
MS2_CHECK_OFFSET(Unk_FishLineInit, m_timer70, 0x70);
MS2_CHECK_SIZE(Unk_FishLineInit, sizeof(Unk_FishLine));

// @0x140cd7d80
Unk_FishLineInit::Unk_FishLineInit()
{
    m_08 = 0;
    m_10 = 0;
    m_vStart = efd::Point3::ZERO;
    m_vEnd = efd::Point3::ZERO;
    m_68 = 0;
}
