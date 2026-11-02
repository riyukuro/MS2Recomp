// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTrafficOptimizer: per-map packet traffic limits.
// MS2-UNIT: commonfiles\trafficoptimizer.cpp
// MS2-RANGE: 0x14087d240-0x14087e8c0 .text$mn
// MS2-PIN: ?CompareElements@Unk_TOTraits@@SA_NAEBI0@Z 0x14087d940
// MS2-PIN: ?GetNode@?$CAtlMap@IIUUnk_TOTraits@@V?$CElementTraits@I@ATL@@@ATL@@AEBAPEAVCNode@12@AEBIAEAI1AEAPEAV312@@Z 0x14087dba0
// MS2-PIN: ?Hash@Unk_TOTraits@@SAKAEBI@Z 0x14087dc90
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\trafficoptimizer.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "trafficoptimizer.h"
#include "ms2/client/ms2/worldservice.h"  // C3: WorldService::FUN_141bd3060
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/fielddata.h"
#include "hook/ms2hook.h"
#include <algorithm>

class PCBase   // C3: member view for 0x14166c930
{
public:
    int GetCurStateId();                                    // 0x14166c930 current state id
};

const unsigned CTrafficOptimizer::MIN_TRAFFIC = 100;

static bool FUN_14087ddc0(Unk_TOList* list, unsigned id);

// @0x14087d240
CTrafficOptimizer::CTrafficOptimizer() : m_map(17, .75f, .25f, 2.25f, 10) {}

// @0x14087d2b0
CTrafficOptimizer::~CTrafficOptimizer() {}

// @0x14087d2f0
unsigned CTrafficOptimizer::FUN_14087d2f0(Unk_TOEntity* entity) {
    if (FUN_14087ddc0(entity ? entity->vfunc_6() : 0, 0x6200003)) {
        return FUN_14087d410(entity);
    } else if (FUN_14087ddc0(entity ? entity->vfunc_6() : 0, 0x6200045)) {
        return FUN_14087d540(entity);
    } else if (FUN_14087ddc0(entity ? entity->vfunc_6() : 0, 0x6200065)) {
        return FUN_14087d500(entity);
    }
    return 100;
}
MS2_REPLACE_METHOD(0x14087D2F0, CTrafficOptimizer, FUN_14087d2f0, 264, 0x01DE5B8F);

// @0x14087d410
unsigned CTrafficOptimizer::FUN_14087d410(Unk_TOEntity* entity) {
    if (!entity) {
        return 100;
    }
    unsigned traffic = 0;
    if (FUN_14087d630((unsigned)WorldService::GetInstance()->FUN_141bd3060()) != 0) {
        traffic += GetTraffic(3);
    } else {
        traffic += GetTraffic(4);
    }
    if (reinterpret_cast<PCBase*>(entity)->GetCurStateId() == 1) {
        traffic += GetTraffic(5);
    } else {
        traffic += GetTraffic(6);
    }
    return (std::max)(MIN_TRAFFIC, traffic);
}
MS2_REPLACE_METHOD(0x14087D410, CTrafficOptimizer, FUN_14087d410, 220, 0x1D790835);

// @0x14087d500
unsigned CTrafficOptimizer::FUN_14087d500(Unk_TOEntity*) {
    unsigned traffic = GetTraffic(0);
    return (std::max)(MIN_TRAFFIC, traffic);
}
MS2_REPLACE_METHOD(0x14087D500, CTrafficOptimizer, FUN_14087d500, 54, 0x149E8801);

// @0x14087d540
unsigned CTrafficOptimizer::FUN_14087d540(Unk_TOEntity* entity) {
    unsigned traffic = 0;
    if (reinterpret_cast<PCBase*>(entity)->GetCurStateId() == 1) {
        traffic = GetTraffic(1);
    } else {
        traffic = GetTraffic(2);
    }
    return (std::max)(MIN_TRAFFIC, traffic);
}
MS2_REPLACE_METHOD(0x14087D540, CTrafficOptimizer, FUN_14087d540, 101, 0xB400A261);

// @0x14087d5b0
void CTrafficOptimizer::SetTraffic(unsigned key, unsigned value) {
    m_map.SetAt(key, value);
}
MS2_REPLACE_METHOD(0x14087D5B0, CTrafficOptimizer, SetTraffic, 50, 0xA097ADE7);

// @0x14087d5f0
unsigned CTrafficOptimizer::GetTraffic(unsigned key) {
    unsigned value = 0;
    m_map.Lookup(key, value);
    return value;
}
MS2_REPLACE_METHOD(0x14087D5F0, CTrafficOptimizer, GetTraffic, 57, 0xDAAB5227);

// @0x14087d630
int CTrafficOptimizer::FUN_14087d630(unsigned id) {
    Unk_TOField* field = FUN_140374140(id).operator->();
    if (field == 0) {
        return 0;
    }
    if (reinterpret_cast<CFieldData*>(field)->FUN_140375270()) {
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14087D630, CTrafficOptimizer, FUN_14087d630, 119, 0x6AF1FF99);

// @0x14087ddc0
static bool FUN_14087ddc0(Unk_TOList* list, unsigned id) {
    if (list == 0) {
        return false;
    }
    for (unsigned i = 0; i < list->count; ++i) {
        if (list->records[i].id == id) {
            return true;
        }
    }
    return false;
}
