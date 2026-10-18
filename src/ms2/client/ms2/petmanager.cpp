// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPetManager (the pet packet handler: summon / recall /
// name / level / exp / flags of the player's pet) and CPetInventory (the pet's own bag: Unk_Inventory's shape with one
// slot array, packet 0x79 for take out / put in / move / summon), plus the std::map<int, unsigned> (pet counts) and
// Delegate<bool(int,const CMsgBoxData&)> glue they instantiate.
// MS2-UNIT: ?\petmanager.cpp
// MS2-RANGE: 0x140c86860-0x140c8ef00 .text$mn
// MS2-RANGE: 0x1400cf250-0x1400cf2b0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strGemUpgradeSound@@YAXXZ 0x1400cf250 ; probe
// MS2-PIN: ??__Es_strPetSummonSound@@YAXXZ 0x1400cf280 ; probe
// MS2-PIN: ??$?0VCPetInventory@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVCPetInventory@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140c8b780 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCPetInventory@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c8e9c0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCPetInventory@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140c8ed60 ; unique
// MS2-PIN: ??$Call@VCPetInventory@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVCPetInventory@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVCPetInventory@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140c8eda0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCPetInventory@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c8edd0 ; unique
// MS2-PINS-END tplpin
// File name assumed (the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\petmanager.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uihudentity.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cpet.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The sound ids of the pet: the summon effect sound and the level up sound (initialized before everything else).
static CString s_strPetSummonSound = "02100199";
static CString s_strGemUpgradeSound = "System_Gemstone_Upgrade_01";

// ---- unit-local views of exe objects and unrecovered callees --------------------------------------------------------
class Unk_PmGameMenu { public: void FUN_141938270(int bUp, int nA, int nB); };
Unk_PmGameMenu* FUN_140938b90(int nId);
class Unk_PmInventoryDialog { public: void FUN_14199a3f0(__int64 nItemUid); };
Unk_PmInventoryDialog* FUN_1405344f0(int nId);
class Unk_PmPetDialog { public: void FUN_140e74640(int nPage); };
Unk_PmPetDialog* FUN_140b99ba0(int nId);

// The local player or another player object (a PC). FUN_141663400 clears / sets the worn pet item, FUN_141663450 reads it.
class Unk_PmSkillLevel : public CPtred {};
class Unk_PCBaseComp_a78 : public CPtred {};
class CSkillRecord : public CPtred {};
class Unk_PmSkillTable { public: MS2Ptr<Unk_PmSkillLevel> FUN_1407ee2f0(int, unsigned short); };
Unk_PmSkillTable* FUN_1401958b0();
bool FUN_140804450(Unk_PmSkillLevel*);
struct Unk_InventorySkillRequest
{
    Unk_InventorySkillRequest(int, unsigned short);                // 0x141763fa0
    int skill;
    unsigned short level;
    unsigned __int64 tick;
    unsigned serial, unknown14;
    float origin[3], direction[3];
    unsigned unknown30, unknown34;
    bool remap, suppressDispatch, itemUse;
    __int64 item;
};
MS2_CHECK_SIZE(Unk_InventorySkillRequest, 0x48);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, remap, 0x38);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, itemUse, 0x3a);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, item, 0x40);
class Unk_PmSkills { public: MS2Ptr<CSkillRecord> FUN_141765570(Unk_InventorySkillRequest&); };
class Unk_PmPlayer : public PC
{
public:
    void FUN_141663400(MS2Ptr<CItem> spItem);
    MS2Ptr<CItem> FUN_141663450();
    Unk_PmSkills* FUN_141523bc0();
};
class Unk_PmWorld
{
public:
    Unk_PmPlayer* FUN_141bd0cc0();                          // the local player
    Unk_PmPlayer* FUN_141bd1290(int nObjectId);
    int FUN_141bd1a10(void* pObject);                       // the entity kind of an object
};
Unk_PmWorld* FUN_1403ed2d0();
class Unk_PmGuide { public: int FUN_14138c900(int nKind); };
Unk_PmGuide* FUN_1409331e0();
class Unk_PmUI { public: void FUN_141add1f0(); };
Unk_PmUI* FUN_1403ed2b0();
class Unk_PmNames { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_PmNames* FUN_1401a9d70();
class Unk_PmPetRowTable : public CPtred { public: MS2Ptr<Unk_PetRow> FUN_1407290f0(int nPetId); };
Unk_PmPetRowTable* FUN_14052d210();
struct Unk_PmConfig { char m_pad_0[0x328]; CString m_strLevelUpEffect; };      // +0x328 the pet level up effect
Unk_PmConfig* FUN_1401d31f0();
CEffectService* FUN_1403ed280();
void FUN_1411e7660(Unk_PCEquipSet* pEquip);
CPetManager* FUN_140535320();                               // CPetManager::GetInstance (0x140535320)
void FUN_1401ff930(Unk_PetFlags* pFlags, CInPacket* pIn);

// items
CItemData* FUN_140527840(CItem*);
int FUN_14053dc20(CItemData*);
int FUN_14053dc60(CItemData*);
bool FUN_14053cd10(CItemData*);
bool FUN_14053d270(CItemData*);
bool FUN_140534e50(MS2Ptr<CItem>&);
MS2Ptr<CItemData> FUN_14053f870(int);
void FUN_140e6d4a0(int nObjectId, MS2Ptr<CItem> spItem);    // the pet item arrived
extern Unk_Inventory DAT_143ab2a90;                         // the player's inventory

// messages
CStringW FUN_14028b8e0(const CStringW&);
void FUN_141275260(int, int, int);
void FUN_141276180(const CString&, const CString&);
void FUN_1412751b0(const CStringW&, int);
void FUN_140d73aa0(CStringW, int, int, CStringW);
void FUN_140d73bc0(int, int, int, CStringW);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, IMessageListener* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
CStringW FUN_1405c2690(CStringW, const CStringW&);
unsigned FUN_1412773a0(unsigned nMax);

// The record behind DAT_143abf720 (its +0x28 is the uid of the item that cannot be taken out of the bag).
struct Unk_PmFixedItem { __int64 m_pad_0[5]; __int64 m_nUid; };
extern Unk_PmFixedItem* DAT_143abf720;
// @0x140c8dab0
__int64 FUN_140c8dab0(Unk_PmFixedItem* pRec)
{
    return pRec->m_nUid;
}
// @0x140c8dac0
Unk_PmFixedItem* FUN_140c8dac0()
{
    return DAT_143abf720;
}

// ---- CPetInventory ----------------------------------------------------------------------------------------------
// @0x140c86860
CPetInventory::CPetInventory() : m_items(10)
{
    FUN_140c868d0();
}
// @0x140c8d680
CPetInventory::~CPetInventory()
{
}
// @0x140c868d0
void CPetInventory::FUN_140c868d0()
{
    if (FUN_1403ed2d0() != 0)
    {
        int nSlots = 0;
        Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
        {
            void* pPet = pPlayer->FUN_141676a10();
            if (pPet != 0)
            {
                MS2Ptr<Unk_PetRow> spRow = static_cast<CPet*>(pPet)->FUN_140b102b0();
                if (spRow.get() != 0)
                    nSlots = spRow->m_nSlots;
            }
        }
        Unk_CriticalSectionLock guard(m_lock, 1);
        m_items.RemoveAll();
        m_slots.RemoveAll();
        m_slots.SetCount(nSlots, -1);
        m_n80 = 0;
    }
}
// @0x140c869e0
int CPetInventory::FUN_140c869e0(CItem* pItem)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    if (m_items.Lookup(pItem->FUN_140526a50()) != 0)
        return 0x11;
    int nSlot = pItem->FUN_140526b50();
    if (nSlot == -1)
    {
        nSlot = FUN_140c87b90();
        if (nSlot == -1)
            return 0xd;
        pItem->FUN_140526b70(nSlot);
    }
    else
    {
        int nCount = (int)m_slots.GetCount();
        if (nSlot < 0 || nCount <= nSlot)
            return 0x1d;
        if (m_slots[nSlot].get() != 0)
            return 0x11;
    }
    m_items.SetAt(pItem->FUN_140526a50(), ItemPtr(pItem));
    m_slots[nSlot].AssignRaw(pItem);
    return 0;
}
// @0x140c86bb0
void CPetInventory::FUN_140c86bb0(unsigned __int64 nUid)
{
    ItemPtr spItem;
    Unk_CriticalSectionLock guard(m_lock, 1);
    if (m_items.Lookup(nUid, spItem))
    {
        m_items.RemoveKey(nUid);
        if (spItem.get() != 0)
        {
            int nSlot = spItem->FUN_140526b50();
            m_slots[nSlot] = 0;
        }
    }
}
// @0x140c86c90
CPetInventory::ItemPtr CPetInventory::FUN_140c86c90(int nSlot)
{
    ItemPtr spItem(0);
    int nCount = (int)m_slots.GetCount();
    if (nSlot < 0 || nCount <= nSlot)
        return ItemPtr(0);
    Unk_CriticalSectionLock guard(m_lock, 1);
    spItem = m_slots[nSlot];
    return spItem;
}
// @0x140c86d90
CPetInventory::ItemPtr CPetInventory::FUN_140c86d90(int nItemId)
{
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return ItemPtr(0);
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (POSITION pos = m_items.GetHeadPosition(); pos != 0; m_items.GetNext(pos))
    {
        ItemPtr spItem = m_items.GetValueAt(pos);
        if (pPlayer->FUN_141662eb0(spItem.get()) == 0)
            continue;
        if (spItem->FUN_1405276c0() == nItemId)
            return spItem;
    }
    return ItemPtr(0);
}
// MS2-FUNCTIONAL: typed list / array accessors; the bubble sort keeps the exe's repeated passes.
// @0x140c86f20
void CPetInventory::FUN_140c86f20(int nItemId, ATL::CAtlList<ItemPtr>& result, int nMode)
{
    {
        Unk_CriticalSectionLock guard(m_lock, 1);
        for (unsigned i = 0; i < m_slots.GetCount(); ++i)
        {
            ItemPtr spItem = m_slots[i];
            if (spItem.get() == 0 || spItem->FUN_1405276c0() != nItemId)
                continue;
            if (nMode == 2)
                result.AddTail(spItem);
            else if (spItem->FUN_140526c50() < spItem->FUN_1405281e0())
                result.AddTail(spItem);
        }
    }
    if (result.GetCount() > 1)
    {
        int nCount = (int)result.GetCount();
        for (int i = 0; i < nCount; ++i)
        {
            for (int j = 0; j < nCount - 1; ++j)
            {
                int nFirst = result.GetAt(result.FindIndex(j))->FUN_140526c50();
                int nSecond = result.GetAt(result.FindIndex(j + 1))->FUN_140526c50();
                if ((nMode == 2 && nSecond < nFirst) || (nMode == 1 && nFirst < nSecond))
                    result.SwapElements(result.FindIndex(j), result.FindIndex(j + 1));
            }
        }
    }
}
// @0x140c87250
CPetInventory::ItemPtr CPetInventory::FUN_140c87250(unsigned __int64 nUid)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    ItemPtr spItem;
    m_items.Lookup(nUid, spItem);
    return spItem;
}
// @0x140c87300
CPetInventory::ItemPtr CPetInventory::FUN_140c87300(int nItemId, int bAnyUsability)
{
    if (nItemId == 0)
        return ItemPtr(0);
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return ItemPtr(0);
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (POSITION pos = m_items.GetHeadPosition(); pos != 0; m_items.GetNext(pos))
    {
        ItemPtr spItem = m_items.GetValueAt(pos);
        if (FUN_140534e50(spItem) != 0)
            continue;
        if (bAnyUsability == 0 && pPlayer->FUN_141662eb0(spItem.get()) == 0)
            continue;
        if (FUN_14053dc20(FUN_140527840(spItem.get())) == nItemId)
            return spItem;
    }
    return ItemPtr(0);
}
// @0x140c874f0
int CPetInventory::FUN_140c874f0()
{
    int nFree = 0;
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (unsigned i = 0; i < m_slots.GetCount(); ++i)
    {
        ItemPtr spItem = m_slots[i];
        if (spItem.get() == 0)
            ++nFree;
    }
    return nFree;
}
// @0x140c875e0
int CPetInventory::FUN_140c875e0()
{
    return (int)m_slots.GetCount();
}
// @0x140c87610
int CPetInventory::FUN_140c87610()
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    unsigned nCount = (unsigned)m_slots.GetCount();
    for (int i = 0; i < (int)(nCount >> 1); ++i)
    {
        ItemPtr spItem = m_slots[(int)((nCount - 1) - i)];
        if (spItem.get() == 0)
            return 1;
        spItem = m_slots[i];
        if (spItem.get() == 0)
            return 1;
    }
    return 0;
}
// @0x140c87780
bool CPetInventory::FUN_140c87780(int nItemId, int nCount)
{
    return nCount <= FUN_140c87840(nItemId, 0);
}
// @0x140c877e0
bool CPetInventory::FUN_140c877e0(int nItemId, int nRarity, int nCount)
{
    return nCount <= FUN_140c87840(nItemId, nRarity);
}
// @0x140c87840
int CPetInventory::FUN_140c87840(int nItemId, int nRarity)
{
    int nTotal = 0;
    if (nItemId == 0)
        return 0;
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (unsigned i = 0; i < m_slots.GetCount(); ++i)
    {
        ItemPtr spItem = m_slots[i];
        if (spItem.get() == 0)
            continue;
        if (pPlayer->FUN_141662eb0(spItem.get()) == 0)
            continue;
        if (spItem->FUN_1405276c0() != nItemId)
            continue;
        if (nRarity != 0 && spItem->FUN_140526bd0() != nRarity)
            continue;
        nTotal += spItem->FUN_140526c50();
    }
    return nTotal;
}
// @0x140c87a00
int CPetInventory::FUN_140c87a00(int nItemId)
{
    int nRoom = 0;
    Unk_CriticalSectionLock guard(m_lock, 1);
    int nCount = (int)m_slots.GetCount();
    for (int i = 0; i < nCount; ++i)
    {
        ItemPtr spItem = m_slots[i];
        if (spItem.get() != 0 && spItem->FUN_1405276c0() == nItemId)
            nRoom += (int)spItem->FUN_1405281e0() - spItem->FUN_140526c50();
    }
    return nRoom;
}
// @0x140c87b90
unsigned CPetInventory::FUN_140c87b90()
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (unsigned i = 0; i < m_slots.GetCount(); ++i)
    {
        ItemPtr spItem = m_slots[i];
        if (spItem.get() == 0)
            return i;
    }
    return 0xffffffff;
}
// @0x140c87c80
int CPetInventory::FUN_140c87c80(ItemPtr spItem, int nNeed)
{
    if (spItem.get() != 0 && spItem->FUN_1405281e0() > 1)
    {
        if (FUN_140c87a00(spItem->FUN_1405276c0()) < nNeed)
            return -1;
        int nCount = (int)m_slots.GetCount();
        for (int i = 0; i < nCount; ++i)
        {
            ItemPtr spSlot = m_slots[i];
            if (spSlot.get() != 0 && spSlot->FUN_1405276c0() == spItem->FUN_1405276c0())
            {
                int nRoom = (int)spSlot->FUN_1405281e0() - spSlot->FUN_140526c50();
                if (0 < nRoom)
                    return spSlot->FUN_140526b50();
            }
        }
    }
    return FUN_140c87b90();
}
// @0x140c87ef0
void CPetInventory::FUN_140c87ef0(ATL::CAtlArray<ItemPtr>& result)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (POSITION pos = m_items.GetHeadPosition(); pos != 0; m_items.GetNext(pos))
    {
        ItemPtr spItem = m_items.GetValueAt(pos);
        result.Add(spItem);
    }
}
// @0x140c87fb0
bool CPetInventory::FUN_140c87fb0(int nItemId)
{
    ItemPtr spItem = FUN_140c86d90(nItemId);
    if (spItem.get() == 0)
        return false;
    return FUN_140c88f70(spItem);
}
// @0x140c88050
bool CPetInventory::FUN_140c88050(int nItemId)
{
    ItemPtr spItem = FUN_140c87300(nItemId, 0);
    if (spItem.get() == 0)
        return false;
    return FUN_140c88f70(spItem);
}
// @0x140c88100
void CPetInventory::FUN_140c88100()
{
    COutPacket packet(0x79, 0);
    packet.Encode1(7);
    FUN_140710590(packet);
}
// @0x140c88160
void CPetInventory::FUN_140c88160(__int64 nUid, short nSlot)
{
    if (FUN_140535320()->FUN_140c8b2e0() != nUid)
    {
        COutPacket packet(0x79, 0);
        packet.Encode1(3);
        packet.Encode8(nUid);
        packet.Encode2(nSlot);
        FUN_140710590(packet);
    }
}
// @0x140c88200
void CPetInventory::FUN_140c88200(__int64 nUid, int nSlot, int nCount)
{
    if (0 < nCount)
    {
        if (FUN_140535320()->FUN_140c8b2e0() != nUid)
        {
            ItemPtr spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
            if (spItem.get() != 0)
            {
                if (spItem->FUN_140525640() == 0)
                {
                    if (FUN_14053cd10(FUN_140527840(spItem.get())))
                    {
                        if (FUN_140c8dab0(FUN_140c8dac0()) == spItem->FUN_140526a50())
                        {
                            FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_binditem_by_playing_score"), 0, 0, CStringW(L""));
                            return;
                        }
                    }
                    int nTarget = nSlot;
                    if (nSlot == -1)
                    {
                        nTarget = FUN_140c87c80(spItem, nCount);
                        if (nTarget == -1)
                        {
                            FUN_141275260(0xf2, 1, 1);
                            return;
                        }
                    }
                    ItemPtr spPet = DAT_143ab2a90.FUN_140a5d680(FUN_140535320()->FUN_140c8b2e0());
                    if (spPet.get() != 0 && !spPet->FUN_140528930())
                    {
                        COutPacket packet(0x79, 0);
                        packet.Encode1(0);
                        packet.Encode8(nUid);
                        packet.Encode2((short)nTarget);
                        packet.Encode4(nCount);
                        FUN_140710590(packet);
                    }
                }
                else
                    FUN_140d73bc0(0xc16, 0, 0, CStringW(L""));
            }
        }
    }
}
// @0x140c88590
void CPetInventory::FUN_140c88590(__int64 nUid, short nSlot, int nCount)
{
    if (0 < nCount)
    {
        if (FUN_140535320()->FUN_140c8b2e0() != nUid)
        {
            COutPacket packet(0x79, 0);
            packet.Encode1(1);
            packet.Encode8(nUid);
            packet.Encode2(nSlot);
            packet.Encode4(nCount);
            FUN_140710590(packet);
        }
    }
}
// @0x140c88650
bool CPetInventory::FUN_140c88650(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        int nCount = _wtoi(box.FUN_141a02d50().Trim(L','));
        FUN_140c88200(box.FUN_141a02c20(), box.FUN_141a02c80(), nCount);
    }
    return true;
}
// @0x140c88700
bool CPetInventory::FUN_140c88700(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        int nCount = _wtoi(box.FUN_141a02d50().Trim(L','));
        FUN_140c88590(box.FUN_141a02c20(), (short)box.FUN_141a02c80(), nCount);
    }
    return true;
}
// MS2-FUNCTIONAL: message box temporaries; same calls and arguments.
// @0x140c887b0
void CPetInventory::FUN_140c887b0(ItemPtr spItem, int nSlot)
{
    if (spItem.get() == 0)
        return;
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (spItem->FUN_140525640() != 0)
    {
        FUN_140d73bc0(0xc16, 0, 0, CStringW(L""));
        return;
    }
    if (DAT_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
        return;
    ItemPtr spPet = DAT_143ab2a90.FUN_140a5d680(pPlayer->FUN_1416769f0());
    if (spPet.get() != 0 && spPet->FUN_140528930())
    {
        FUN_140d73bc0(0xc15, 0, 0, CStringW(L""));
        return;
    }
    if (!spItem->FUN_140526850())
    {
        FUN_140535320()->FUN_140c8b410()->FUN_140c88200(spItem->FUN_140526a50(), nSlot, spItem->FUN_140526c50());
        return;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(5, 0xc0f, 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        CStringW strCount = StringFormat(L"{0}", spItem->FUN_140526c50());
        spBox->FUN_141a01620(nSlot);
        spBox->FUN_141a01600(spItem->FUN_140526a50());
        spBox->FUN_141a01d30(1, strCount, FUN_1412773a0(spItem->FUN_1405281e0()), 0, 0);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(FUN_140535320()->FUN_140c8b410(), &CPetInventory::FUN_140c88650));
        FUN_140d73c60(spBox);
    }
}
// MS2-FUNCTIONAL: message box temporaries; same calls and arguments.
// @0x140c88c30
void CPetInventory::FUN_140c88c30(ItemPtr spItem, int nSlot)
{
    if (spItem.get() == 0)
        return;
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (DAT_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
        return;
    if (!spItem->FUN_140526850())
    {
        FUN_140535320()->FUN_140c8b410()->FUN_140c88590(spItem->FUN_140526a50(), (short)nSlot, spItem->FUN_140526c50());
        return;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(5, 0xc10, 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        CStringW strCount = StringFormat(L"{0}", spItem->FUN_140526c50());
        spBox->FUN_141a01620(nSlot);
        spBox->FUN_141a01600(spItem->FUN_140526a50());
        spBox->FUN_141a01d30(1, strCount, FUN_1412773a0(spItem->FUN_1405281e0()), 0, 0);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(FUN_140535320()->FUN_140c8b410(), &CPetInventory::FUN_140c88700));
        FUN_140d73c60(spBox);
    }
}
// MS2-FUNCTIONAL: typed skill request; equivalent early returns (same shape as Unk_Inventory::FUN_140a63000).
// @0x140c88f70
bool CPetInventory::FUN_140c88f70(ItemPtr spItem)
{
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (FUN_1409331e0()->FUN_14138c900(8) != 0)
    {
        FUN_141275260(0x888, 1, 1);
        return false;
    }
    if (!FUN_14053d270(FUN_140527840(spItem.get())))
        return false;
    int nSkill = FUN_14053dc20(FUN_140527840(spItem.get()));
    MS2Ptr<Unk_PmSkillLevel> spLevel = FUN_1401958b0()->FUN_1407ee2f0(nSkill, 1);
    if (spLevel.get() != 0)
        return false;
    Unk_InventorySkillRequest request(nSkill, 1);
    request.remap = FUN_140804450(spLevel.get());
    request.itemUse = true;
    request.item = spItem->FUN_140526a50();
    MS2Ptr<CSkillRecord> spRecord = pPlayer->FUN_141523bc0()->FUN_141765570(request);
    if (spRecord.get() == 0)
        return false;
    return pPlayer->vfunc_102(spRecord);
}

// ---- CPetManager ------------------------------------------------------------------------------------------------
// @0x140c89200
Unk_PetManagerEmpty* Unk_PetManagerEmpty::FUN_140c89200()
{
    return this;
}
// @0x140c89220
int CPetManager::FUN_140c89220(int nItemId)
{
    if (FUN_140535320()->FUN_140c8b410()->FUN_140c87fb0(nItemId))
        return 1;
    return DAT_143ab2a90.FUN_140a63000(nItemId);
}
// @0x140c89270
int CPetManager::FUN_140c89270(int nItemId)
{
    if (FUN_140535320()->FUN_140c8b410()->FUN_140c88050(nItemId))
        return 1;
    return DAT_143ab2a90.FUN_140a63360(nItemId);
}
// @0x140c892c0
MS2Ptr<CItem> CPetManager::FUN_140c892c0(int nItemId)
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c86d90(nItemId);
    if (spItem.get() == 0)
        return DAT_143ab2a90.FUN_140a5e2e0(nItemId);
    return spItem;
}
// @0x140c89380
MS2Ptr<CItem> CPetManager::FUN_140c89380(unsigned __int64 nUid)
{
    MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(nUid);
    if (spItem.get() == 0)
        return DAT_143ab2a90.FUN_140a5d680(nUid);
    return spItem;
}
// @0x140c89440
int CPetManager::FUN_140c89440(int nItemId, int nRarity)
{
    int nPet = FUN_140535320()->FUN_140c8b410()->FUN_140c87840(nItemId, nRarity);
    int nBag = DAT_143ab2a90.FUN_140a5f180(nItemId, nRarity);
    return nPet + nBag;
}
// @0x140c894b0
CPetManager::CPetManager()
{
    m_8 = 0;
    m_nSummonUid = 0;
    m_a0.FUN_140c89200();
    m_nAuto = 1;
}
// @0x140c89570
CPetManager::~CPetManager()
{
}
// @0x140c895e0
void CPetManager::FUN_140c895e0(CInPacket& in)
{
    switch (in.vfunc_o8_1())
    {
    case 0: FUN_140c89b20(in); break;
    case 1: FUN_140c89d00(in); break;
    case 2: FUN_140c89ea0(in); break;
    case 4: FUN_140c8a140(in); break;
    case 5: FUN_140c8a420(in); break;
    case 6: FUN_140c8a390(in); break;
    case 7: FUN_140c89810(in); break;
    case 8: FUN_140c898f0(in); break;
    case 9: FUN_140c89980(in); break;
    case 10: FUN_140c8a4b0(in); break;
    case 0xb: FUN_140c8a940(in); break;
    case 0xc: FUN_140c8ab80(in); break;
    case 0xf: FUN_140c8b070(in); break;
    case 0x10: FUN_140c8ac50(in); break;
    case 0x11: FUN_140c8a7a0(in); break;
    case 0x12: FUN_140c8a640(in); break;
    case 0x13: FUN_140c8ae50(in); break;
    case 0x14: FUN_140c8b0c0(in); break;
    case 0x15: FUN_140c8afa0(in); break;
    }
}
// @0x140c89810
void CPetManager::FUN_140c89810(CInPacket& in)
{
    FUN_140c8b1f0();
    int nCount = in.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        unsigned long nKey = in.vfunc_o8_3();
        int nValue = (unsigned short)in.vfunc_o8_2();
        m_counts[nKey] = nValue;
    }
}
// @0x140c898f0
void CPetManager::FUN_140c898f0(CInPacket& in)
{
    unsigned long nKey = in.vfunc_o8_3();
    long nValue = (unsigned short)in.vfunc_o8_2();
    m_counts[nKey] = nValue;
}
// @0x140c89980
void CPetManager::FUN_140c89980(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
        {
            FUN_140535320()->FUN_140c8b410()->FUN_140c868d0();
            m_info.FUN_1401ffd00(&in);
            if (m_info.identity.name.IsEmpty())
            {
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_140c8b2e0());
                if (spItem.get() == 0)
                    return;
                m_info.identity.name = spItem->FUN_140527b10();
            }
            Unk_PmPetDialog* pDialog = FUN_140b99ba0(0x4f38);
            if (pDialog != 0)
                pDialog->FUN_140e74640(1);
        }
    }
}
// @0x140c89b20
void CPetManager::FUN_140c89b20(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    int nValue = in.vfunc_o8_3();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        pPlayer->FUN_141663150(in);
        pPlayer->FUN_141676a50(pPlayer->FUN_1416769f0(), nValue);
        FUN_1411e7660(pPlayer->FUN_1416561a0());
        if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
        {
            FUN_140535320()->FUN_140c8b300(pPlayer->FUN_1416769f0());
            Unk_PmInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
            if (pInventory != 0)
                pInventory->FUN_14199a3f0(pPlayer->FUN_1416769f0());
            Unk_PmGameMenu* pMenu = FUN_140938b90(0x4e28);
            if (pMenu != 0)
            {
                MS2Ptr<Unk_PetRow> spRow = FUN_140535320()->FUN_140c8b470();
                if (spRow.get() != 0)
                    pMenu->FUN_141938270(1, spRow->m_nF18 == 1, m_nAuto);
            }
        }
    }
}
// @0x140c89d00
void CPetManager::FUN_140c89d00(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    __int64 nUid = in.vfunc_o8_4();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        pPlayer->FUN_141676ab0(nUid);
        pPlayer->FUN_141663400(MS2Ptr<CItem>(0));
        FUN_1411e7660(pPlayer->FUN_1416561a0());
        if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
        {
            FUN_140535320()->FUN_140c8b300(0);
            Unk_PmInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
            if (pInventory != 0)
                pInventory->FUN_14199a3f0(nUid);
            Unk_PmGameMenu* pMenu = FUN_140938b90(0x4e28);
            if (pMenu != 0)
                pMenu->FUN_141938270(0, 0, 0);
            Unk_PmPetDialog* pDialog = FUN_140b99ba0(0x4f38);
            if (pDialog != 0)
                pDialog->FUN_140e74640(2);
            FUN_141275260(0xc0c, 1, 1);
        }
    }
}
// @0x140c89ea0
void CPetManager::FUN_140c89ea0(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    CPet* pPet = static_cast<CPet*>(FUN_140c8b5c0(nObjectId));
    if (pPet != 0)
    {
        Unk_PmPlayer* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
        PCBase* pOwner = pPet->FUN_140b10320();
        if (pLocal != 0 && pLocal == pOwner && pPet->vfunc_127() != 0)
        {
            PCBase* pOwner2 = pPet->FUN_140b10320();
            if (pOwner2 != 0)
            {
                NiTransform xf;
                xf.MakeIdentity();
                xf.m_Translate = pOwner2->vfunc_18();
                FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/system"), s_strPetSummonSound, CString(""), 1, &xf, 1.0f, 0);
            }
        }
    }
}
// @0x140c8a140
void CPetManager::FUN_140c8a140(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    Unk_PetIdentity identity;
    identity.FUN_1401fef40(&in);
    CPet* pPet = static_cast<CPet*>(FUN_140c8b5c0(nObjectId));
    if (pPet != 0)
    {
        pPet->vfunc_76(identity.name);
        MS2Ptr<Unk_PCBaseComp_a78> spHud = pPet->vfunc_82();
        if (spHud.get() != 0)
            ((UIHudEntity::Entity*)(void*)spHud.operator->())->FUN_140f48d80();
    }
    Unk_PmPlayer* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal != 0)
    {
        if (FUN_1403ed2d0()->FUN_141bd0cc0()->FUN_14123c580() == nObjectId)
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_140535320()->FUN_140c8b2e0());
            if (spItem.get() == 0)
                return;
            m_info.identity.FUN_1401ff0f0(identity);
            spItem->FUN_140528b00(m_info.identity.name);
            FUN_140535320()->FUN_140c8b450()->identity.extra = identity.extra;
            Unk_PmPetDialog* pDialog = FUN_140b99ba0(0x4f38);
            if (pDialog != 0)
                pDialog->FUN_140e74640(0xd);
        }
    }
}
// @0x140c8a390
void CPetManager::FUN_140c8a390(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
            FUN_1401ff930(&m_info.flags, &in);
    }
}
// @0x140c8a420
void CPetManager::FUN_140c8a420(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
            m_info.options.FUN_1401ff4d0(&in);
    }
}
// @0x140c8a4b0
void CPetManager::FUN_140c8a4b0(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    __int64 nValue = in.vfunc_o8_4();
    __int64 nUid = in.vfunc_o8_4();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
            if (spItem.get() != 0)
            {
                spItem->FUN_140528b60(nValue);
                if (pPlayer->FUN_1416769f0() == nUid)
                    m_info.identity.id = nValue;
                Unk_PmPetDialog* pDialog = FUN_140b99ba0(0x4f38);
                if (pDialog != 0)
                    pDialog->FUN_140e74640(6);
            }
        }
    }
}
// @0x140c8a640
void CPetManager::FUN_140c8a640(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    int nLevel = in.vfunc_o8_3();
    __int64 nUid = in.vfunc_o8_4();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
            if (spItem.get() != 0)
            {
                spItem->FUN_140528bb0(nLevel);
                Unk_PmPetDialog* pDialog = FUN_140b99ba0(0x4f38);
                if (pDialog != 0)
                    pDialog->FUN_140e74640(8);
            }
        }
    }
}
// @0x140c8a7a0
void CPetManager::FUN_140c8a7a0(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    __int64 nUid = in.vfunc_o8_4();
    unsigned char nFlag = in.vfunc_o8_1();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem.get() != 0)
        {
            spItem->FUN_140526bf0(nFlag);
            spItem->FUN_140524eb0(in);
            if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
            {
                Unk_PmPetDialog* pDialog = FUN_140b99ba0(0x4f38);
                if (pDialog != 0)
                    pDialog->FUN_140e74640(7);
            }
        }
    }
}
// @0x140c8a940
void CPetManager::FUN_140c8a940(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    unsigned short nLevel = (unsigned short)in.vfunc_o8_2();
    __int64 nUid = in.vfunc_o8_4();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0)
    {
        if (pPlayer->FUN_1416769f0() == nUid)
        {
            CPet* pPet = static_cast<CPet*>(FUN_140c8b5c0(nObjectId));
            if (pPet != 0)
            {
                Unk_EffectTarget kTarget;
                kTarget.m_strName = FUN_1401d31f0()->m_strLevelUpEffect;
                kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(pPet);
                kTarget.FUN_140a53190(pPet->FUN_14123c580());
                FUN_1403ed280()->FUN_1411a4a00(kTarget);
            }
        }
        if (pPlayer == FUN_1403ed2d0()->FUN_141bd0cc0())
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
            if (spItem.get() != 0)
            {
                spItem->FUN_140528bf0(nLevel);
                if (pPlayer->FUN_1416769f0() == nUid)
                    m_info.identity.level = (short)nLevel;
                Unk_PmPetDialog* pDialog = FUN_140b99ba0(0x4f38);
                if (pDialog != 0)
                    pDialog->FUN_140e74640(9);
            }
        }
    }
}
// @0x140c8ab80
void CPetManager::FUN_140c8ab80(CInPacket& in)
{
    int nExp = in.vfunc_o8_3();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        pPlayer->FUN_141663a70(nExp);
        Unk_PmPetDialog* pDialog = FUN_140b99ba0(0x4f38);
        if (pDialog != 0)
            pDialog->FUN_140e74640(0xc);
        FUN_141276180(s_strGemUpgradeSound, CString(""));
    }
}
// @0x140c8ac50
void CPetManager::FUN_140c8ac50(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    int nId = in.vfunc_o8_3();
    __int64 nUid = in.vfunc_o8_4();
    int nRarity = in.vfunc_o8_3();
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_140523c40(nId, nRarity, 0))
    {
        spItem->FUN_140526b30(nObjectId);
        spItem->FUN_140526a70(nUid);
        spItem->FUN_140524eb0(in);
        FUN_140e6d4a0(nObjectId, spItem);
    }
}
// @0x140c8ae50
void CPetManager::FUN_140c8ae50(CInPacket& in)
{
    switch (in.vfunc_o8_3())
    {
    case 0x1b: FUN_141275260(0x34, 1, 1); break;
    case 0x1c: FUN_1403ed2b0()->FUN_141add1f0(); break;
    default: FUN_141275260(0x979, 1, 1); break;
    case 0x1e: FUN_141275260(0xf2, 1, 1); break;
    case 0x20: FUN_140d73bc0(0xc24, 0, 0, CStringW(L"")); break;
    case 0x21: FUN_141275260(0xc21, 1, 1); break;
    case 0x27: break;
    }
}
// @0x140c8afa0
void CPetManager::FUN_140c8afa0(CInPacket& in)
{
    int nObjectId = in.vfunc_o8_3();
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer != 0 && pPlayer->FUN_1416769d0() != 0)
    {
        if (pPlayer->FUN_141663450().get() != 0)
            pPlayer->FUN_141663150(in);
    }
}
// @0x140c8b070
void CPetManager::FUN_140c8b070(CInPacket& in)
{
    m_nAuto = in.vfunc_o8_1();
}
// @0x140c8b0c0
void CPetManager::FUN_140c8b0c0(CInPacket& in)
{
    int nSkillId = in.vfunc_o8_3();
    MS2Ptr<CItemData> spData = FUN_14053f870(nSkillId);
    if (spData.get() != 0)
    {
        CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nSkillId);
        CStringW strText = FUN_1405c2690(CStringW(L"s_skill_consume_by_pet_trap"), strName);
        FUN_1412751b0(strText, 0x14);
    }
}
// @0x140c8b1f0
void CPetManager::FUN_140c8b1f0()
{
    m_counts.clear();
}
// @0x140c8b220
int CPetManager::FUN_140c8b220(int nKey)
{
    if (m_counts.find((unsigned long)nKey) == m_counts.end())
        return 0;
    return m_counts[(unsigned long)nKey];
}
// @0x140c8b2b0
bool CPetManager::FUN_140c8b2b0()
{
    return FUN_140c8b2e0() != 0;
}
// @0x140c8b2e0
__int64 CPetManager::FUN_140c8b2e0()
{
    return m_nSummonUid;
}
// @0x140c8b300
void CPetManager::FUN_140c8b300(__int64 nUid)
{
    m_nSummonUid = nUid;
}
// @0x140c8b320
int CPetManager::FUN_140c8b320()
{
    return m_nAuto;
}
// @0x140c8b340
int CPetManager::FUN_140c8b340()
{
    m_nAuto = (m_nAuto == 0);
    COutPacket packet(0x78, 0);
    packet.Encode1(0xf);
    packet.vfunc_o10_0(m_nAuto == 1);
    FUN_140710590(packet);
    return m_nAuto;
}
// @0x140c8b410
CPetInventory* CPetManager::FUN_140c8b410()
{
    return &m_inv;
}
// @0x140c8b430
Unk_PetManagerEmpty* CPetManager::FUN_140c8b430()
{
    return &m_a0;
}
// @0x140c8b450
CCPetInfoPacket::Info* CPetManager::FUN_140c8b450()
{
    return &m_info;
}
// @0x140c8b470
MS2Ptr<Unk_PetRow> CPetManager::FUN_140c8b470()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_140c8b2e0());
    if (spItem.get() == 0)
        return MS2Ptr<Unk_PetRow>(0);
    MS2Ptr<CItemData> spData(FUN_140527840(spItem.get()));
    if (spData.get() == 0)
        return MS2Ptr<Unk_PetRow>(0);
    return FUN_14052d210()->FUN_1407290f0(FUN_14053dc60(spData.get()));
}
// @0x140c8b5c0
void* CPetManager::FUN_140c8b5c0(int nObjectId)
{
    Unk_PmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pPlayer == 0)
        return 0;
    return pPlayer->FUN_141676a10();
}

MS2_EMIT_CRT_MEMMOVE_S();
