// pcinfo.h - PLACEHOLDER for PCInfo (RTTI .?AVPCInfo@@, 0x558 bytes, vftable 0x142e370d8: 1 slot). NOT an original header.
// Bodies in client/ms2/pcinfo.cpp (?\pcinfo.cpp). A pc record (another player's character as the server describes it):
// MyPC::vfunc_125, AvatarPC and UIAvatarPC take it (mypc.cpp / avatarpc.cpp / uiavatarbase.cpp still use their local
// Unk_PCArg125 stand-ins for it). Field names are invented from use.
#pragma once

#include <map>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/additionalactionadditional.h"    // SAType

class CItem;
class CInPacket;

class PCInfo : public CPtred
{
public:
    PCInfo();                                               // 0x140db9e30
    // ~PCInfo: implicit (0x140dbaa90, ??_G 0x140dbabc0): the exe dtor does not re-store the vftable
    int FUN_140dba1c0();                                    // m_3c0 (six identical getters)
    int FUN_140dba1e0();
    int FUN_140dba200();
    int FUN_140dba220();
    int FUN_140dba240();
    int FUN_140dba260();
    void FUN_140dba280(CInPacket* pPacket);                 // reads the stat table (0x23 stats x 3 kinds)
    MS2Ptr<CItem> FUN_140dba560(int nGemType);              // the first item of m_aItems whose gem has the type
    MS2Ptr<CItem> FUN_140dba700(Unk_InventoryEquipSlot nSlot);  // the item worn in a slot (m_mapEquip0)
    MS2Ptr<CItem> FUN_140dba790(Unk_InventoryEquipSlot nSlot);  // (m_mapEquip1)
    MS2Ptr<CItem> FUN_140dba820(Unk_InventoryEquipSlot nSlot);  // (m_mapEquip2)
    MS2Ptr<CItem> FUN_140dba8b0(int nKind, Unk_InventoryEquipSlot nSlot);    // one of the above by kind
    void FUN_140dba990(ATL::CAtlArray<MS2Ptr<CItem> >& aItems);  // appends every item of m_mapEquip0
    int FUN_140dbaa10();                                    // FUN_140526bd0 of the item in slot 5

    unsigned short m_18;                                    // +0x18 (1) level (UIPCInfoDialog::vfunc_95 zero-extends it)
    int m_1c;                                               // +0x1c (1)
    int m_20;                                               // +0x20 (10)
    __int64 m_28;                                           // +0x28
    __int64 m_30;                                           // +0x30 pc id
    int m_38;                                               // +0x38
    ATL::CAtlArray<unsigned int> m_aIds;                    // +0x40
    int m_60;                                               // +0x60
    __int64 m_aStats0[0x23];                                // +0x68 stat values, kind 0
    __int64 m_aStats1[0x23];                                // +0x180 kind 1
    __int64 m_aStats2[0x23];                                // +0x298 kind 2
    std::map<SAType, int> m_3b0;                            // +0x3b0
    int m_3c0;                                              // +0x3c0
    int m_3c4;                                              // +0x3c4 (3)
    int m_3c8;                                              // +0x3c8
    int m_3cc;                                              // +0x3cc
    int m_3d0;                                              // +0x3d0
    int m_3d4;                                              // +0x3d4
    int m_3d8;                                              // +0x3d8
    int m_3dc;                                              // +0x3dc
    CStringA m_3e0;                                         // +0x3e0
    CStringW m_3e8;                                         // +0x3e8
    CStringW m_3f0;                                         // +0x3f0
    CStringW m_3f8;                                         // +0x3f8
    CStringW m_400;                                         // +0x400
    CStringW m_408;                                         // +0x408
    ATL::CAtlArray<MS2Ptr<CItem> > m_aItems;                // +0x410
    ATL::CAtlMap<Unk_InventoryEquipSlot, MS2Ptr<CItem> > m_mapEquip0;   // +0x430
    ATL::CAtlMap<Unk_InventoryEquipSlot, MS2Ptr<CItem> > m_mapEquip1;   // +0x478
    ATL::CAtlMap<Unk_InventoryEquipSlot, MS2Ptr<CItem> > m_mapEquip2;   // +0x4c0
    bool m_508;                                             // +0x508
    CMsTime m_510;                                          // +0x510
    CMsTime m_520;                                          // +0x520
    int m_530;                                              // +0x530
    int m_nGuildRank;                                       // +0x534
    CStringW m_strGuildName;                                // +0x538
    CStringW m_strGuildEmblemPath;                          // +0x540
    __int64 m_nGuildId;                                     // +0x548
    __int64 m_nGuildEmblem;                                 // +0x550
};
MS2_CHECK_OFFSET(PCInfo, m_3b0, 0x3b0);
MS2_CHECK_OFFSET(PCInfo, m_3e0, 0x3e0);
MS2_CHECK_OFFSET(PCInfo, m_aItems, 0x410);
MS2_CHECK_OFFSET(PCInfo, m_mapEquip0, 0x430);
MS2_CHECK_OFFSET(PCInfo, m_508, 0x508);
MS2_CHECK_OFFSET(PCInfo, m_510, 0x510);
MS2_CHECK_OFFSET(PCInfo, m_530, 0x530);
MS2_CHECK_SIZE(PCInfo, 0x558);
