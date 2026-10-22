// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): PCInfo, the pc record (stats, worn items, guild) of another
// player's character, and the TU's memmove_s copy.
// MS2-UNIT: ?\pcinfo.cpp
// MS2-RANGE: 0x140db9e30-0x140dbad20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pcinfo.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/placeholder/pcinfo.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

int FUN_14082f1a0(int nType);                               // stat kind: 0 = 32-bit value

// @0x140db9e30
PCInfo::PCInfo()
    : m_18(1), m_1c(1), m_20(10), m_28(0), m_30(0), m_38(0), m_60(0),
      m_3c0(0), m_3c4(3), m_3c8(0), m_3cc(0), m_3d0(0), m_3d4(0), m_3d8(0), m_3dc(0),
      m_3e0(""), m_3e8(L""), m_3f0(L""), m_3f8(L""), m_400(L""), m_408(L""),
      m_508(false), m_510(0), m_520(0), m_530(0), m_nGuildRank(0), m_nGuildId(0), m_nGuildEmblem(0)
{
    memset(m_aStats0, 0, sizeof(m_aStats0));
    memset(m_aStats1, 0, sizeof(m_aStats1));
    memset(m_aStats2, 0, sizeof(m_aStats2));
}

// @0x140dba1c0
int PCInfo::FUN_140dba1c0()
{
    return m_3c0;
}

// @0x140dba1e0
int PCInfo::FUN_140dba1e0()
{
    return m_3c0;
}

// @0x140dba200
int PCInfo::FUN_140dba200()
{
    return m_3c0;
}

// @0x140dba220
int PCInfo::FUN_140dba220()
{
    return m_3c0;
}

// @0x140dba240
int PCInfo::FUN_140dba240()
{
    return m_3c0;
}

// @0x140dba260
int PCInfo::FUN_140dba260()
{
    return m_3c0;
}

// @0x140dba280
void PCInfo::FUN_140dba280(CInPacket* pPacket)
{
    unsigned char nCount = pPacket->ReadUInt8();
    if (nCount == 0x23)
    {
        for (int nType = 0; nType < 0x23; nType++)
        {
            for (int i = 0; i < 3; i++)
            {
                __int64 nValue = 0;
                if (FUN_14082f1a0(nType))
                    nValue = pPacket->ReadInt64();
                else
                    nValue = (unsigned)pPacket->ReadInt32();
                if (i == 1)
                    m_aStats1[nType] = nValue;
                else if (i == 2)
                    m_aStats2[nType] = nValue;
                else if (i == 0)
                    m_aStats0[nType] = nValue;
            }
        }
    }
    else
    {
        for (int n = 0; n < nCount; n++)
        {
            int nType = pPacket->ReadUInt8();
            for (int i = 0; i < 3; i++)
            {
                __int64 nValue = 0;
                if (FUN_14082f1a0(nType))
                    nValue = pPacket->ReadInt64();
                else
                    nValue = (unsigned)pPacket->ReadInt32();
                if (i == 1)
                    m_aStats1[nType] = nValue;
                else if (i == 2)
                    m_aStats2[nType] = nValue;
                else if (i == 0)
                    m_aStats0[nType] = nValue;
            }
        }
    }
}

// @0x140dba560
MS2Ptr<CItem> PCInfo::FUN_140dba560(int nGemType)
{
    if (m_aItems.IsEmpty())
        return MS2Ptr<CItem>(0);
    size_t nCount = m_aItems.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CItem> spItem = m_aItems.GetAt(i);
        if (spItem == 0 || ((CItem*)spItem)->FUN_140527900() == 0)
            continue;
        int nType = ((CItem*)spItem)->FUN_140527900()->vfunc_1();
        if (nType == nGemType)
            return spItem;
    }
    return MS2Ptr<CItem>(0);
}

// @0x140dba700
MS2Ptr<CItem> PCInfo::FUN_140dba700(Unk_InventoryEquipSlot nSlot)
{
    MS2Ptr<CItem> spItem(0);
    m_mapEquip0.Lookup(nSlot, spItem);
    return spItem;
}

// @0x140dba790
MS2Ptr<CItem> PCInfo::FUN_140dba790(Unk_InventoryEquipSlot nSlot)
{
    MS2Ptr<CItem> spItem(0);
    m_mapEquip1.Lookup(nSlot, spItem);
    return spItem;
}

// @0x140dba820
MS2Ptr<CItem> PCInfo::FUN_140dba820(Unk_InventoryEquipSlot nSlot)
{
    MS2Ptr<CItem> spItem(0);
    m_mapEquip2.Lookup(nSlot, spItem);
    return spItem;
}

// @0x140dba8b0
MS2Ptr<CItem> PCInfo::FUN_140dba8b0(int nKind, Unk_InventoryEquipSlot nSlot)
{
    if (nKind == 0)
        return FUN_140dba700(nSlot);
    else if (nKind == 1)
        return FUN_140dba790(nSlot);
    else if (nKind == 2)
        return FUN_140dba820(nSlot);
    return MS2Ptr<CItem>(0);
}

// @0x140dba990
void PCInfo::FUN_140dba990(ATL::CAtlArray<MS2Ptr<CItem> >& aItems)
{
    for (POSITION pos = m_mapEquip0.GetStartPosition(); pos; m_mapEquip0.GetNext(pos))
        aItems.Add(m_mapEquip0.GetValueAt(pos));
}

// @0x140dbaa10
int PCInfo::FUN_140dbaa10()
{
    MS2Ptr<CItem> spItem = FUN_140dba700((Unk_InventoryEquipSlot)5);
    if (spItem == 0)
        return 0;
    return ((CItem*)spItem)->FUN_140526bd0();
}

// @0x140dbac00
MS2_EMIT_CRT_MEMMOVE_S();
