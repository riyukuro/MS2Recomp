// dungeonrewardcoupon.h - DungeonRewardCoupon, one entry of Table/DungeonRewardCoupon.xml (the extra reward ticket of
// a dungeon room). Owning unit: commonfiles\dungeonrewardcoupon.cpp (0x14031c510-0x14031c970; the unit name is assumed
// from the class name). Field names from the xml attributes; method names invented.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class TiXmlElement;     // game TinyXML element

// RTTI DungeonRewardCoupon, 0x50 bytes.
class DungeonRewardCoupon : public CPtred
{
public:
    DungeonRewardCoupon();                          // 0x14031c510
    // implicit dtor 0x14031c7e0
    int GetId();                                    // 0x14031c590
    void Load(TiXmlElement* pElem);                // 0x14031c5b0

    int m_id;                                       // +0x18
    unsigned m_ticketTag;                           // +0x1c
    int m_baseItemID;                               // +0x20
    int m_maxExtraCount;                            // +0x24
    ATL::CAtlArray<unsigned> m_baseRate;            // +0x28 ticket count per extra reward
    bool m_canBuyInMeratMarket;                     // +0x48
};
MS2_CHECK_SIZE(DungeonRewardCoupon, 0x50);
MS2_CHECK_OFFSET(DungeonRewardCoupon, m_baseRate, 0x28);
