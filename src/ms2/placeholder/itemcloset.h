// itemcloset.h - PLACEHOLDER for ItemCloset::SlotInfo (RTTI .?AUSlotInfo@ItemCloset@@, 0x30 bytes, base CPtred, vftable
// 0x142d8c5b0) and ItemCloset::TabInfo (RTTI .?AUTabInfo@ItemCloset@@, 0x50 bytes, base CPtred, vftable 0x142df50e8).
// NOT an original header. Serializers (unit_1407a4f20) write/read the closet tab packet: a tab = three ints, its name and a
// list of slots. TabInfo's ctor (0x140be3220) and dtor (0x140be36e0) live in the closet UI unit and are only declared.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/stream.h"

class CInPacket;
namespace ItemCloset {
struct SlotInfo : public CPtred {
    SlotInfo();                                   // 0x1407aaf00
    // ~SlotInfo() is implicit (0x1407ab010: no vptr reset)
    void FUN_1407a8390(COutputStream& out) const; // item id, three ints
    void FUN_1407a8410(CInPacket& in);
    __int64 m_itemId;                             // +0x18
    int m_20;                                     // +0x20 item id
    unsigned int m_24;                            // +0x24 equip slot (zero-extended into FUN_140be4750)
    int m_28;                                     // +0x28 rarity
};
struct TabInfo : public CPtred {
    TabInfo();                                    // 0x140be3220
    // ~TabInfo() is implicit (0x140be36e0: no vptr reset)
    void FUN_1407a84e0(COutputStream& out) const;
    void FUN_1407a8600(CInPacket& in);
    int m_18, m_1c, m_20;                         // +0x18
    ATL::CAtlArray<MS2Ptr<SlotInfo> > m_slots;    // +0x28
    CStringW m_name;                              // +0x48
};
} // namespace ItemCloset
MS2_CHECK_SIZE(ItemCloset::SlotInfo, 0x30);
MS2_CHECK_SIZE(ItemCloset::TabInfo, 0x50);
MS2_CHECK_OFFSET(ItemCloset::TabInfo, m_slots, 0x28);
MS2_CHECK_OFFSET(ItemCloset::TabInfo, m_name, 0x48);
