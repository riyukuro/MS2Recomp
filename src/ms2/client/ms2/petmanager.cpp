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
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uipetsystemdialog.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/client/ms2/uiotherpetsystemdialog.h"
class NoticeMessage   // C3: unit-local view (ctor 0x140a52ef0, dtor 0x1405a89e0, 0x70 bytes)
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void SetActor(int nActor);   // 0x140a53190
    void* m_storage[14];
};
#include "ms2/placeholder/clockcriticalsection.h"   // Unk_CriticalSectionLock (was a local lock view)

// The sound ids of the pet: the summon effect sound and the level up sound (initialized before everything else).
static CString s_strPetSummonSound = "02100199";
static CString s_strGemUpgradeSound = "System_Gemstone_Upgrade_01";

// ---- unit-local views of exe objects and unrecovered callees --------------------------------------------------------
class UIGameMenuDialog   // C3: member view (real class not in this TU)
{
public:
    void InitPetInfo(int, int, int);
};
class Unk_PmGameMenu { public:  };
class UIGameMenuDialog* FindGameMenuDialog(int);   // C3: was FindGameMenuDialog
class UIInventoryDialog   // C3: member view (real class not in this TU)
{
public:
    void RefreshItemSlot(__int64);
};
class Unk_PmInventoryDialog { public:  };
template<class T> T* Unk_BreakDialog(int);   // C3: was Unk_PmInventoryDialog* FUN_1405344f0 (calls cast back)
template <class T> T* Unk_PetGetDialog(int nId);   // C3: was FUN_140b99ba0

// The local player or another player object (a PC). FUN_141663400 clears / sets the worn pet item, FUN_141663450 reads it.
class Unk_PCBaseComp_a78 : public CPtred {};
class CSkillRecord : public CPtred {};
struct Unk_InventorySkillRequest
{
    Unk_InventorySkillRequest(int, unsigned short);                // 0x141763fa0
    int skill;
    unsigned short level;
    unsigned __int64 tick;
    unsigned serial, unknown14;
    struct Point { Point(); float x, y, z; } origin, direction;
    unsigned unknown30, unknown34;
    bool remap, suppressDispatch, itemUse;
    __int64 item;
};
MS2_CHECK_SIZE(Unk_InventorySkillRequest, 0x48);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, remap, 0x38);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, itemUse, 0x3a);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, item, 0x40);
class Unk_PmSkills : public CSkillSystem { };
class MyPC   // C3: member view (real class not in this TU)
{
public:
    CSkillSystem* GetSkillSystem();
};
class Unk_PmPlayer : public PC
{
public:
};
class Unk_PmWorld
{
public:
};
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
struct Unk_PmConfig { char m_pad_0[0x328]; CString m_strLevelUpEffect; };      // +0x328 the pet level up effect
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource
#include "ms2/client/ms2/equipment.h"   // CEquipment (was a local member view)
//
//
//
//
class Unk_BreakSelected* GetPetManager();   // C3: was GetPetManager
void ReadPetFlags(unsigned char*, void*);   // C3: was ReadPetFlags

// items
int FUN_14053dc60(CItemData*);
MS2Ptr<CItemData> FUN_14053f870(int);
extern Unk_Inventory g_143ab2a90;                           // the player's inventory

// messages
CStringW GetStringCommonByKey(const CStringW&);
void FUN_141275260(int, int, int);
int PlaySystemSound(const CString&, const CString&);
void FUN_1412751b0(const CStringW&, int);
void ShowMessageBox(CStringW, int, void*, CStringW);
void FUN_140d73bc0(int, int, void*, CStringW);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, void* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
int FUN_1412773a0(int);   // C3: was FUN_1412773a0

// The record behind DAT_143abf720 (its +0x28 is the uid of the item that cannot be taken out of the bag).
struct Unk_PmFixedItem { __int64 m_pad_0[5]; __int64 m_nUid; };
class CInstrumentManager;
// @0x140c8dab0
__int64 FUN_140c8dab0(Unk_PmFixedItem* pRec)
{
    return pRec->m_nUid;
}
// @0x140c8dac0
Unk_PmFixedItem* GetInstrumentManager()
{
    return reinterpret_cast<Unk_PmFixedItem*>(TSingleton<CInstrumentManager>::s_instance);
}

// ---- CPetInventory ----------------------------------------------------------------------------------------------
// @0x140c86860
CPetInventory::CPetInventory() : m_items(10)
{
    ResetSlots();
}
// @0x140c8d680
CPetInventory::~CPetInventory()
{
}
// @0x140c868d0
void CPetInventory::ResetSlots()
{
    if (reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance()) == 0)
        return;
    unsigned nSlots = 0;
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pPlayer != 0)
    {
        void* pPet = pPlayer->FUN_141676a10();
        if (pPet != 0)
        {
            MS2Ptr<CPetData> spRow = static_cast<CPet*>(pPet)->GetRow();
            if (spRow.get() != 0)
                nSlots = spRow->m_nSlotNum;
        }
    }
    Unk_CriticalSectionLock guard(m_lock, 1);
    m_items.RemoveAll();
    m_slots.RemoveAll();
    m_slots.SetCount(nSlots, -1);
    m_n80 = 0;
}
// @0x140c869e0
int CPetInventory::AddItem(CItem* pItem)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    if (m_items.Lookup(pItem->GetItemUid()) != 0)
        return 0x11;
    int nSlot = pItem->GetSlot();
    if (nSlot != -1)
    {
        int nCount = (int)m_slots.GetCount();
        if (nSlot < 0 || nSlot >= nCount)
            return 0x1d;
        if (m_slots[nSlot].get() != 0)
            return 0x11;
    }
    else
    {
        int nEmpty = FindEmptySlot();
        if (nEmpty == -1)
            return 0xd;
        nSlot = nEmpty;
        pItem->SetSlot(nSlot);
    }
    {
        ItemPtr spItem(pItem);
        m_items.SetAt(pItem->GetItemUid(), spItem);
    }
    m_slots[nSlot].AssignRaw(pItem);
    return 0;
}
// @0x140c86bb0
void CPetInventory::RemoveItem(unsigned __int64 nUid)
{
    ItemPtr spItem;
    Unk_CriticalSectionLock guard(m_lock, 1);
    if (m_items.Lookup(nUid, spItem))
    {
        m_items.RemoveKey(nUid);
        if (spItem.get() != 0)
        {
            int nSlot = spItem->GetSlot();
            m_slots[nSlot] = 0;
        }
    }
}
// @0x140c86c90
CPetInventory::ItemPtr CPetInventory::GetItemBySlot(int nSlot)
{
    ItemPtr spItem(0);
    int nCount = (int)m_slots.GetCount();
    if (nSlot < 0 || nSlot >= nCount)
        return ItemPtr(0);
    {
        Unk_CriticalSectionLock guard(m_lock, 1);
        spItem = m_slots[nSlot];
    }
    return spItem;
}
// @0x140c86d90
CPetInventory::ItemPtr CPetInventory::FindUsableItemById(int nItemId)
{
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pPlayer == 0)
        return ItemPtr(0);
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (POSITION pos = m_items.GetHeadPosition(); pos != 0; m_items.GetNext(pos))
    {
        ItemPtr spItem = m_items.GetValueAt(pos);
        if (pPlayer->CanUseItem(spItem.get()) == 0)
            continue;
        if (spItem->GetItemId() == nItemId)
            return spItem;
    }
    return ItemPtr(0);
}
// @0x140c86f20
size_t CPetInventory::CollectItemsById(int nItemId, ATL::CAtlList<ItemPtr>& result, int nMode)
{
    {
        Unk_CriticalSectionLock guard(m_lock, 1);
        for (unsigned i = 0; i < m_slots.GetCount(); ++i)
        {
            ItemPtr spItem = m_slots[i];
            if (spItem.get() != 0 && spItem->GetItemId() == nItemId)
            {
                if (nMode == 2)
                    result.AddTail(spItem);
                else if (spItem->GetCount() < spItem->GetSlotMax())
                    result.AddTail(spItem);
            }
        }
    }
    if (result.GetCount() > 1)
    {
        int nCount = (int)result.GetCount();
        int nLast = nCount - 1;
        int nFirst = 0;
        int nSecond = 0;
        for (int i = 0; i < nCount; ++i)
        {
            for (int j = 0; j < nLast; ++j)
            {
                nFirst = result.GetAt(result.FindIndex(j))->GetCount();
                nSecond = result.GetAt(result.FindIndex(j + 1))->GetCount();
                if (nMode == 2)
                {
                    if (nFirst > nSecond)
                        result.SwapElements(result.FindIndex(j), result.FindIndex(j + 1));
                }
                else if (nMode == 1)
                {
                    if (nFirst < nSecond)
                        result.SwapElements(result.FindIndex(j), result.FindIndex(j + 1));
                }
            }
        }
    }
    return result.GetCount();
}
// @0x140c87250
CPetInventory::ItemPtr CPetInventory::GetItemByUid(unsigned __int64 nUid)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    ItemPtr spItem;
    m_items.Lookup(nUid, spItem);
    return spItem;
}
// @0x140c87300
CPetInventory::ItemPtr CPetInventory::FindItemByDataId(int nItemId, int bAnyUsability)
{
    if (nItemId == 0)
        return ItemPtr(0);
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pPlayer == 0)
        return ItemPtr(0);
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (POSITION pos = m_items.GetHeadPosition(); pos != 0; m_items.GetNext(pos))
    {
        ItemPtr spItem = m_items.GetValueAt(pos);
        if (!spItem)
            continue;
        if (bAnyUsability == 0 && pPlayer->CanUseItem(spItem.get()) == 0)
            continue;
        if (((class CItemData*)(class CItemData*)(reinterpret_cast<CItemData*>(spItem->GetData())))->GetSkillId() == nItemId)
            return spItem;
    }
    return ItemPtr(0);
}
// @0x140c874f0
int CPetInventory::GetUsedSlotCount()
{
    int nUsed = 0;
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (unsigned i = 0; i < m_slots.GetCount(); ++i)
    {
        ItemPtr spItem = m_slots[i];
        if (spItem == 0)
            continue;
        ++nUsed;
    }
    return nUsed;
}
// @0x140c875e0
int CPetInventory::GetSlotCount()
{
    return (int)m_slots.GetCount();
}
// @0x140c87610
int CPetInventory::HasEmptySlot()
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    unsigned nCount = (unsigned)m_slots.GetCount();
    int nHalf = nCount >> 1;
    int nLast = nCount - 1;
    for (int i = 0; i < nHalf; ++i)
    {
        ItemPtr spItem = m_slots[nLast - i];
        if (spItem == 0)
            return 1;
        spItem = m_slots[i];
        if (spItem == 0)
            return 1;
    }
    return 0;
}
// @0x140c87780
int CPetInventory::HasEnoughItems(int nItemId, int nCount)
{
    int nHave = GetItemCount(nItemId, 0);
    return nHave >= nCount;
}
// @0x140c877e0
int CPetInventory::FUN_140c877e0(int nItemId, int nRarity, int nCount)
{
    int nHave = GetItemCount(nItemId, nRarity);
    return nHave >= nCount;
}
// @0x140c87840
int CPetInventory::GetItemCount(int nItemId, int nRarity)
{
    if (nItemId == 0)
        return 0;
    int nTotal = 0;
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pPlayer == 0)
        return 0;
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (unsigned i = 0; i < m_slots.GetCount(); ++i)
    {
        ItemPtr spItem = m_slots[i];
        if (spItem == 0)
            continue;
        if (pPlayer->CanUseItem(spItem.get()) == 0)
            continue;
        if (spItem->GetItemId() != nItemId)
            continue;
        if (nRarity != 0 && spItem->GetRarity() != nRarity)
            continue;
        nTotal += spItem->GetCount();
    }
    return nTotal;
}
// @0x140c87a00
int CPetInventory::GetStackRoom(int nItemId)
{
    int nRoom = 0;
    Unk_CriticalSectionLock guard(m_lock, 1);
    int nCount = (int)m_slots.GetCount();
    for (int i = 0; i < nCount; ++i)
    {
        ItemPtr spItem = m_slots[i];
        if (static_cast<bool>(spItem.get()) && spItem->GetItemId() == nItemId)
            nRoom += spItem->GetSlotMax() - spItem->GetCount() < 0 ? 0 : spItem->GetSlotMax() - spItem->GetCount();
    }
    return nRoom;
}
// @0x140c87b90
unsigned CPetInventory::FindEmptySlot()
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (unsigned i = 0; i < m_slots.GetCount(); ++i)
    {
        ItemPtr spItem = m_slots[i];
        if (spItem == 0)
            return i;
    }
    return 0xffffffff;
}
// @0x140c87c80
int CPetInventory::FindSlotForItem(ItemPtr spItem, int nNeed)
{
    if ((spItem.get() ? true : false) && spItem->GetSlotMax() > 1)
    {
        int nStock = GetStackRoom(spItem->GetItemId());
        if (nStock < nNeed)
            return -1;
        int nCount = (int)m_slots.GetCount();
        for (int i = 0; i < nCount; ++i)
        {
            ItemPtr spSlot = m_slots[i];
            if ((spSlot.get() ? true : false) && spSlot->GetItemId() == spItem->GetItemId())
            {
                int nRoom = (spSlot->GetSlotMax() - spSlot->GetCount() < 0) ? 0 : spSlot->GetSlotMax() - spSlot->GetCount();
                if (0 < nRoom)
                    return spSlot->GetSlot();
            }
        }
    }
    return FindEmptySlot();
}
// @0x140c87ef0
void CPetInventory::GetAllItems(ATL::CAtlArray<ItemPtr>& result)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (POSITION pos = m_items.GetHeadPosition(); pos != 0; m_items.GetNext(pos))
    {
        ItemPtr spItem = m_items.GetValueAt(pos);
        result.Add(spItem);
    }
}
// @0x140c87fb0
bool CPetInventory::UseItemById(int nItemId)
{
    ItemPtr spItem = FindUsableItemById(nItemId);
    if (spItem == 0)
        return false;
    return UseItemSkill(spItem);
}
// @0x140c88050
bool CPetInventory::UseItemByDataId(int nItemId)
{
    ItemPtr spItem = FindItemByDataId(nItemId, 0);
    if (spItem == 0)
        return false;
    return UseItemSkill(spItem);
}
// @0x140c88100
void CPetInventory::SendRequestPetInventoryMode7()
{
    COutPacket packet(static_cast<int>(SendOp::RequestPetInventory), 0);
    packet.Encode1(7);
    FUN_140710590(packet);
}
// @0x140c88160
void CPetInventory::SendRequestPetInventoryMode3(__int64 nUid, int nSlot)
{
    if (((class CPetManager*)GetPetManager())->GetSummonUid() == nUid)
        return;
    COutPacket packet(static_cast<int>(SendOp::RequestPetInventory), 0);
    packet.Encode1(3);
    packet.Encode8(nUid);
    packet.Encode2(nSlot);
    FUN_140710590(packet);
}
// @0x140c88200
void CPetInventory::SendRequestPetInventoryMode0(__int64 nUid, int nSlot, int nCount)
{
    if (nCount < 1)
        return;
    if (((class CPetManager*)GetPetManager())->GetSummonUid() == nUid)
        return;
    ItemPtr spItem = g_143ab2a90.FindItemByUid(nUid);
    if (spItem == 0)
        return;
    if (spItem->IsPetItem() != 0)
    {
        FUN_140d73bc0(0xc16, 0, 0, L"");
        return;
    }
    if (((class CItemData*)(class CItemData*)(reinterpret_cast<CItemData*>(spItem->GetData())))->IsScoreItem())
    {
        if (FUN_140c8dab0(GetInstrumentManager()) == spItem->GetItemUid())
        {
            ShowMessageBox(GetStringCommonByKey(L"s_item_err_binditem_by_playing_score"), 0, 0, CStringW(L""));
            return;
        }
    }
    if (nSlot == -1)
    {
        nSlot = FindSlotForItem(spItem, nCount);
        if (nSlot == -1)
        {
            FUN_141275260(0xf2, 1, 1);
            return;
        }
    }
    ItemPtr spPet = g_143ab2a90.FindItemByUid(((class CPetManager*)GetPetManager())->GetSummonUid());
    if (spPet == 0)
        return;
    if (spPet->IsExpired())
        return;
    COutPacket packet(static_cast<int>(SendOp::RequestPetInventory), 0);
    packet.Encode1(0);
    packet.Encode8(nUid);
    packet.Encode2((short)nSlot);
    packet.Encode4(nCount);
    FUN_140710590(packet);
}
// @0x140c88590
void CPetInventory::SendRequestPetInventoryMode1(__int64 nUid, int nSlot, int nCount)
{
    if (nCount < 1)
        return;
    if (((class CPetManager*)GetPetManager())->GetSummonUid() == nUid)
        return;
    COutPacket packet(static_cast<int>(SendOp::RequestPetInventory), 0);
    packet.Encode1(1);
    packet.Encode8(nUid);
    packet.Encode2(nSlot);
    packet.Encode4(nCount);
    FUN_140710590(packet);
}
// @0x140c88650
bool CPetInventory::OnMoveToPetCountResult(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        int nCount = _wtoi(box.FUN_141a02d50().Trim(L','));
        SendRequestPetInventoryMode0(box.FUN_141a02c20(), box.GetInventorySlot(), nCount);
    }
    return true;
}
// @0x140c88700
bool CPetInventory::OnMoveFromPetCountResult(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        int nCount = _wtoi(box.FUN_141a02d50().Trim(L','));
        SendRequestPetInventoryMode1(box.FUN_141a02c20(), box.GetInventorySlot(), nCount);
    }
    return true;
}
// @0x140c887b0
void CPetInventory::MoveItemToPetInventory(ItemPtr spItem, int nSlot)
{
    if (spItem == 0)
        return;
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pPlayer == 0)
        return;
    if (spItem->IsPetItem() != 0)
    {
        FUN_140d73bc0(0xc16, 0, 0, CStringW(L""));
        return;
    }
    if (g_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
        return;
    ItemPtr spPet = g_143ab2a90.FindItemByUid(pPlayer->FUN_1416769f0());
    if ((spPet.get() ? true : false) && spPet->IsExpired())
    {
        FUN_140d73bc0(0xc15, 0, 0, CStringW(L""));
        return;
    }
    if (!spItem->FUN_140526850())
    {
        ((class CPetManager*)GetPetManager())->GetInventory()->SendRequestPetInventoryMode0(spItem->GetItemUid(), nSlot, spItem->GetCount());
    }
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(5, 0xc0f, 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            CStringW strCount = StringFormat<unsigned>(L"{0}", spItem->GetCount());
            spBox->SetInventorySlot(nSlot);
            spBox->SetItemUid(spItem->GetItemUid());
            spBox->SetInput(1, strCount, FUN_1412773a0(spItem->GetSlotMax()), 0, 0);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(((class CPetManager*)GetPetManager())->GetInventory(), &CPetInventory::OnMoveToPetCountResult));
            FUN_140d73c60(spBox);
        }
    }
}
// @0x140c88c30
void CPetInventory::MoveItemFromPetInventory(ItemPtr spItem, int nSlot)
{
    if (spItem == 0)
        return;
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pPlayer == 0)
        return;
    if (g_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
        return;
    if (!spItem->FUN_140526850())
    {
        ((class CPetManager*)GetPetManager())->GetInventory()->SendRequestPetInventoryMode1(spItem->GetItemUid(), nSlot, spItem->GetCount());
    }
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(5, 0xc10, 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            CStringW strCount = StringFormat<unsigned>(L"{0}", spItem->GetCount());
            spBox->SetInventorySlot(nSlot);
            spBox->SetItemUid(spItem->GetItemUid());
            spBox->SetInput(1, strCount, FUN_1412773a0(spItem->GetSlotMax()), 0, 0);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(((class CPetManager*)GetPetManager())->GetInventory(), &CPetInventory::OnMoveFromPetCountResult));
            FUN_140d73c60(spBox);
        }
    }
}
// @0x140c88f70
bool CPetInventory::UseItemSkill(ItemPtr spItem)
{
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pPlayer == 0)
        return false;
    if (((class CGuideManager*)FUN_1409331e0())->IsRestricted(8) != 0)
    {
        FUN_141275260(0x888, 1, 1);
        return false;
    }
    if (!((class CItemData*)(class CItemData*)(reinterpret_cast<CItemData*>(spItem->GetData())))->FUN_14053d270())
        return false;
    MS2Ptr<SkillLevelData> spLevel = reinterpret_cast<SkillDataTable*>(TSingleton<SkillDataTableCli>::GetInstance())->GetSkillLevelData(((class CItemData*)(class CItemData*)(reinterpret_cast<CItemData*>(spItem->GetData())))->GetSkillId(), 1);
    if (spLevel == 0)
        return false;
    Unk_InventorySkillRequest request(((class CItemData*)(class CItemData*)(reinterpret_cast<CItemData*>(spItem->GetData())))->GetSkillId(), 1);
    request.remap = spLevel->HasSequenceName();
    request.itemUse = true;
    request.item = spItem->GetItemUid();
    MS2Ptr<CSkillRecord> spRecord = ((Unk_PmSkills*)((MyPC*)(Unk_PmPlayer*)(pPlayer))->GetSkillSystem())->CreateSkillRecord(request);
    if (spRecord == 0)
        return false;
    return pPlayer->vfunc_102(spRecord);
}

// ---- CPetManager ------------------------------------------------------------------------------------------------
// @0x140c89200
Unk_PetManagerEmpty::Unk_PetManagerEmpty()
{
}
// @0x140c89220
int CPetManager::UseItemById(int nItemId)
{
    if (((class CPetManager*)GetPetManager())->GetInventory()->UseItemById(nItemId))
        return 1;
    return g_143ab2a90.FUN_140a63000(nItemId);
}
// @0x140c89270
int CPetManager::FUN_140c89270(int nItemId)
{
    if (((class CPetManager*)GetPetManager())->GetInventory()->UseItemByDataId(nItemId))
        return 1;
    return g_143ab2a90.FUN_140a63360(nItemId);
}
// @0x140c892c0
MS2Ptr<CItem> CPetManager::FindItemById(int nItemId)
{
    MS2Ptr<CItem> spItem = ((class CPetManager*)GetPetManager())->GetInventory()->FindUsableItemById(nItemId);
    if (spItem.get() != 0)
        return spItem;
    return g_143ab2a90.FUN_140a5e2e0(nItemId);
}
// @0x140c89380
MS2Ptr<CItem> CPetManager::FindItemByUid(unsigned __int64 nUid)
{
    MS2Ptr<CItem> spItem = ((class CPetManager*)GetPetManager())->GetInventory()->GetItemByUid(nUid);
    if (spItem.get() != 0)
        return spItem;
    return g_143ab2a90.FindItemByUid(nUid);
}
// @0x140c89440
int CPetManager::CountItems(int nItemId, int nRarity)
{
    int nPet = ((class CPetManager*)GetPetManager())->GetInventory()->GetItemCount(nItemId, nRarity);
    int nBag = g_143ab2a90.FUN_140a5f180(nItemId, nRarity);
    return nPet + nBag;
}
// @0x140c894b0
CPetManager::CPetManager()
    : m_8(0), m_nSummonUid(0)
{
    m_nAuto = 1;
}
// @0x140c89570
CPetManager::~CPetManager()
{
}
// @0x140c895e0
void CPetManager::OnResponsePet(CInPacket& in)
{
    int nMode = in.ReadUInt8();
    switch (nMode)
    {
    case 7: OnPetCountList(in); break;
    case 8: OnPetCountUpdate(in); break;
    case 9: OnPetInfo(in); break;
    case 0: OnPetSummoned(in); break;
    case 1: OnPetUnsummoned(in); break;
    case 2: OnPetSummonSound(in); break;
    case 4: OnPetRenamed(in); break;
    case 5: OnPetOptionsUpdate(in); break;
    case 6: OnPetFlagsUpdate(in); break;
    case 10: FUN_140c8a4b0(in); break;
    case 0x12: FUN_140c8a640(in); break;
    case 0x11: OnPetItemDataUpdate(in); break;
    case 0xb: OnPetLevelUp(in); break;
    case 0xc: FUN_140c8ab80(in); break;
    case 0x10: OnOtherPetInfo(in); break;
    case 0x13: OnPetError(in); break;
    case 0x15: FUN_140c8afa0(in); break;
    case 0xf: OnPetAutoChanged(in); break;
    case 0x14: OnPetTrapSkillConsumed(in); break;
    }
}
// @0x140c89810
void CPetManager::OnPetCountList(CInPacket& in)
{
    ClearCounts();
    int nCount = in.ReadInt32();
    for (int i = 0; i < nCount; ++i)
    {
        unsigned long nKey = in.ReadInt32();
        int nValue = (unsigned short)in.ReadInt16();
        m_counts[nKey] = nValue;
    }
}
// @0x140c898f0
void CPetManager::OnPetCountUpdate(CInPacket& in)
{
    unsigned long nKey = in.ReadInt32();
    long nValue = (unsigned short)in.ReadInt16();
    m_counts[nKey] = nValue;
}
// @0x140c89980
void CPetManager::OnPetInfo(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
    {
        ((class CPetManager*)GetPetManager())->GetInventory()->ResetSlots();
        m_info.FUN_1401ffd00(&in);
        if (m_info.identity.name.IsEmpty())
        {
            MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(GetSummonUid());
            if (spItem == 0)
                return;
            m_info.identity.name = spItem->FUN_140527b10();
        }
        UIPetSystemDialog* pDialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
        if (pDialog != 0)
            pDialog->FUN_140e74640(1);
    }
}
// @0x140c89b20
void CPetManager::OnPetSummoned(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    int nValue = in.ReadInt32();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    pPlayer->ReadPetItem(in);
    pPlayer->FUN_141676a50(pPlayer->FUN_1416769f0(), nValue);
    ((class CEquipment*)(struct Unk_PCEquipSet*)(pPlayer->GetEquipment()))->FUN_1411e7660();
    if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
    {
        ((class CPetManager*)GetPetManager())->SetSummonUid(pPlayer->FUN_1416769f0());
        Unk_PmInventoryDialog* pInventory = reinterpret_cast<Unk_PmInventoryDialog*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
        if (pInventory != 0)
            ((UIInventoryDialog*)(Unk_PmInventoryDialog*)(pInventory))->RefreshItemSlot(pPlayer->FUN_1416769f0());
        Unk_PmGameMenu* pMenu = ((class Unk_PmGameMenu*)FindGameMenuDialog(0x4e28));
        if (pMenu != 0)
        {
            MS2Ptr<CPetData> spRow = ((class CPetManager*)GetPetManager())->GetSummonedPetRow();
            if (spRow.get() != 0)
                ((UIGameMenuDialog*)(Unk_PmGameMenu*)(pMenu))->InitPetInfo(1, spRow->m_nType == 1, m_nAuto);
        }
    }
}
// @0x140c89d00
void CPetManager::OnPetUnsummoned(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    __int64 nUid = in.ReadInt64();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    pPlayer->FUN_141676ab0(nUid);
    pPlayer->SetPetItem(MS2Ptr<CItem>(0));
    ((class CEquipment*)(struct Unk_PCEquipSet*)(pPlayer->GetEquipment()))->FUN_1411e7660();
    if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
    {
        ((class CPetManager*)GetPetManager())->SetSummonUid(0);
        Unk_PmInventoryDialog* pInventory = reinterpret_cast<Unk_PmInventoryDialog*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
        if (pInventory != 0)
            ((UIInventoryDialog*)(Unk_PmInventoryDialog*)(pInventory))->RefreshItemSlot(nUid);
        Unk_PmGameMenu* pMenu = ((class Unk_PmGameMenu*)FindGameMenuDialog(0x4e28));
        if (pMenu != 0)
            ((UIGameMenuDialog*)(Unk_PmGameMenu*)(pMenu))->InitPetInfo(0, 0, 0);
        UIPetSystemDialog* pDialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
        if (pDialog != 0)
            pDialog->FUN_140e74640(2);
        FUN_141275260(0xc0c, 1, 1);
    }
}
extern const efd::Matrix3 DAT_143a09600;                // efd::Matrix3::IDENTITY

// @0x140c89ea0
void CPetManager::OnPetSummonSound(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    CPet* pPet = static_cast<CPet*>(GetPlayerPet(nObjectId));
    if (pPet == 0)
        return;
    Unk_PmPlayer* pLocal = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    PCBase* pOwner = pPet->GetOwnerPC();
    if (pLocal != 0 && pLocal == pOwner && pPet->vfunc_127() != 0)
    {
        PCBase* pOwner2 = pPet->GetOwnerPC();
        if (pOwner2 != 0)
        {
            NiTransform xf;
            xf.m_fScale = 1.0f;
            xf.m_Translate = static_cast<const efd::Point3&>(pOwner2->vfunc_18());
            xf.m_Rotate = DAT_143a09600;
            TSingleton<CEffectService>::GetInstance()->FUN_1411a5110(CString("ms2sound/sound/system"), s_strPetSummonSound, CString(""), 1, &xf, 1.0f, 0);
        }
    }
}
// @0x140c8a140
void CPetManager::OnPetRenamed(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    Unk_PetIdentity identity;
    identity.Read(&in);
    CPet* pPet = static_cast<CPet*>(GetPlayerPet(nObjectId));
    if (pPet != 0)
    {
        pPet->vfunc_76(identity.name);
        MS2Ptr<Unk_PCBaseComp_a78> spHud = pPet->vfunc_82();
        if (spHud.get() != 0)
            ((UIHudEntity::Entity*)(void*)spHud.operator->())->FUN_140f48d80();
    }
    if (((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()) != 0 && ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer())->GetObjectId() == nObjectId)
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(((class CPetManager*)GetPetManager())->GetSummonUid());
        if (spItem == 0)
            return;
        m_info.identity.CopyFrom(identity);
        spItem->FUN_140528b00(m_info.identity.name);
        ((class CPetManager*)GetPetManager())->GetInfo()->identity.extra = identity.extra;
        UIPetSystemDialog* pDialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
        if (pDialog != 0)
            pDialog->FUN_140e74640(0xd);
    }
}
// @0x140c8a390
void CPetManager::OnPetFlagsUpdate(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
        ReadPetFlags((unsigned char*)(&m_info.flags), (void*)(&in));
}
// @0x140c8a420
void CPetManager::OnPetOptionsUpdate(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
        m_info.options.Read(&in);
}
// @0x140c8a4b0
void CPetManager::FUN_140c8a4b0(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    __int64 nValue = in.ReadInt64();
    __int64 nUid = in.ReadInt64();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nUid);
        if (spItem == 0)
            return;
        spItem->SetPetExp(nValue);
        if (pPlayer->FUN_1416769f0() == nUid)
            m_info.identity.id = nValue;
        UIPetSystemDialog* pDialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
        if (pDialog != 0)
            pDialog->FUN_140e74640(6);
    }
}
// @0x140c8a640
void CPetManager::FUN_140c8a640(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    int nLevel = in.ReadInt32();
    __int64 nUid = in.ReadInt64();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nUid);
        if (spItem == 0)
            return;
        spItem->FUN_140528bb0(nLevel);
        UIPetSystemDialog* pDialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
        if (pDialog != 0)
            pDialog->FUN_140e74640(8);
    }
}
// @0x140c8a7a0
void CPetManager::OnPetItemDataUpdate(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    __int64 nUid = in.ReadInt64();
    int nFlag = in.ReadUInt8();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nUid);
    if (spItem == 0)
        return;
    spItem->FUN_140526bf0(nFlag);
    spItem->ReadFromStream(in);
    if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
    {
        UIPetSystemDialog* pDialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
        if (pDialog != 0)
            pDialog->FUN_140e74640(7);
    }
}
// @0x140c8a940
void CPetManager::OnPetLevelUp(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    short nLevel = (short)in.ReadInt32();
    __int64 nUid = in.ReadInt64();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    {
        if (pPlayer->FUN_1416769f0() == nUid)
        {
            CPet* pPet = static_cast<CPet*>(GetPlayerPet(nObjectId));
            if (pPet != 0)
            {
                NoticeMessage kTarget;   // C3: was Unk_EffectTarget
                ((Unk_EffectTarget&)(kTarget)).m_strName = ((struct Unk_PmConfig*)GetCommonResource())->m_strLevelUpEffect;
                ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->GetObjectKind(reinterpret_cast<class Unk_WsC_GameObj*>(pPet));
                ((NoticeMessage&)(kTarget)).SetActor(pPet->GetObjectId());
                TSingleton<CEffectService>::GetInstance()->InsertEffect(((Unk_EffectTarget&)(kTarget)));
            }
        }
        if (pPlayer == ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer()))
        {
            MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nUid);
            if (spItem == 0)
                return;
            spItem->SetPetLevel(nLevel);
            if (pPlayer->FUN_1416769f0() == nUid)
                m_info.identity.level = nLevel;
            UIPetSystemDialog* pDialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
            if (pDialog != 0)
                pDialog->FUN_140e74640(9);
        }
    }
}
// @0x140c8ab80
void CPetManager::FUN_140c8ab80(CInPacket& in)
{
    int nExp = in.ReadInt32();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pPlayer == 0)
        return;
    pPlayer->FUN_141663a70(nExp);
    UIPetSystemDialog* pDialog = Unk_PetGetDialog<UIPetSystemDialog>(0x4f38);
    if (pDialog != 0)
        pDialog->FUN_140e74640(0xc);
    PlaySystemSound(s_strGemUpgradeSound, "");
}
// @0x140c8ac50
void CPetManager::OnOtherPetInfo(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    int nId = in.ReadInt32();
    __int64 nUid = in.ReadInt64();
    int nRarity = in.ReadInt32();
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_140523c40(nId, nRarity, 0))
    {
        spItem->SetObjectId(nObjectId);
        spItem->SetItemUid(nUid);
        spItem->ReadFromStream(in);
        UIOtherPetSystemDialog::ShowPet(nObjectId, spItem);
    }
}
// @0x140c8ae50
void CPetManager::OnPetError(CInPacket& in)
{
    int nError = in.ReadInt32();
    switch (nError)
    {
    case 0x1b: FUN_141275260(0x34, 1, 1); break;
    case 0x1c: TSingleton<CUIService>::GetInstance()->FUN_141add1f0(); break;
    case 0x20: FUN_140d73bc0(0xc24, 0, 0, CStringW(L"")); break;
    case 0x1e: FUN_141275260(0xf2, 1, 1); break;
    case 0x27: break;
    case 0x21: FUN_141275260(0xc21, 1, 1); break;
    default: FUN_141275260(0x979, 1, 1); break;
    }
}
// @0x140c8afa0
void CPetManager::FUN_140c8afa0(CInPacket& in)
{
    int nObjectId = in.ReadInt32();
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return;
    if (pPlayer->FUN_1416769d0() == 0)
        return;
    if (pPlayer->GetPetItem() == 0)
        return;
    pPlayer->ReadPetItem(in);
}
// @0x140c8b070
void CPetManager::OnPetAutoChanged(CInPacket& in)
{
    m_nAuto = in.ReadBool();
}
// @0x140c8b0c0
void CPetManager::OnPetTrapSkillConsumed(CInPacket& in)
{
    int nSkillId = in.ReadInt32();
    MS2Ptr<CItemData> spData = FUN_14053f870(nSkillId);
    if (spData == 0)
        return;
    FUN_1412751b0(FUN_14028dfa0<CStringW>(L"s_skill_consume_by_pet_trap", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nSkillId)), 0x14);
}
// @0x140c8b1f0
void CPetManager::ClearCounts()
{
    m_counts.clear();
}
// @0x140c8b220
int CPetManager::GetCountByKey(int nKey)
{
    if (m_counts.find(reinterpret_cast<unsigned long&>(nKey)) == m_counts.end())
        return 0;
    return m_counts[reinterpret_cast<unsigned long&>(nKey)];
}
// @0x140c8b2b0
int CPetManager::HasSummonedPet()
{
    if ((unsigned __int64)GetSummonUid() > 0)
        return 1;
    return 0;
}
// @0x140c8b2e0
__int64 CPetManager::GetSummonUid()
{
    return m_nSummonUid;
}
// @0x140c8b300
void CPetManager::SetSummonUid(__int64 nUid)
{
    m_nSummonUid = nUid;
}
// @0x140c8b320
int CPetManager::GetAuto()
{
    return m_nAuto;
}
// @0x140c8b340
int CPetManager::SendRequestPet()
{
    m_nAuto = (m_nAuto == 0);
    COutPacket packet(static_cast<int>(SendOp::RequestPet), 0);
    packet.Encode1(0xf);
    packet.WriteBool(m_nAuto == 1);
    FUN_140710590(packet);
    return m_nAuto;
}
// @0x140c8b410
CPetInventory* CPetManager::GetInventory()
{
    return &m_inv;
}
// @0x140c8b430
Unk_PetManagerEmpty* CPetManager::FUN_140c8b430()
{
    return &m_a0;
}
// @0x140c8b450
CCPetInfoPacket::Info* CPetManager::GetInfo()
{
    return &m_info;
}
// @0x140c8b470
MS2Ptr<CPetData> CPetManager::GetSummonedPetRow()
{
    MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(GetSummonUid());
    if (spItem == 0)
        return MS2Ptr<CPetData>(0);
    MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(spItem->GetData()));
    if (spData == 0)
        return MS2Ptr<CPetData>(0);
    return TSingleton<CPetDataTable>::GetInstance()->Find(spData->GetPetId());
}
// @0x140c8b5c0
void* CPetManager::GetPlayerPet(int nObjectId)
{
    Unk_PmPlayer* pPlayer = ((Unk_PmPlayer*)((WorldService*)(Unk_PmWorld*)(reinterpret_cast<Unk_PmWorld*>(WorldService::GetInstance())))->FindPCById(nObjectId));
    if (pPlayer == 0)
        return 0;
    void* pPet = pPlayer->FUN_141676a10();
    if (pPet == 0)
        return 0;
    return pPet;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca38f0-0x142ca3930 .text$yd
