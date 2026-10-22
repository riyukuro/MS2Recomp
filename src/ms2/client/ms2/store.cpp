// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CStore: the client's account / bank item container, its
// packet requests and the server packet handlers. Class and member names are invented (assert text and packet shapes).
// MS2-UNIT: client\ms2\store.cpp
// MS2-RANGE: 0x140de11a0-0x140de4d10 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\store.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/store.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/commonfiles/banktable.h"
#include "ms2/client/ms2/triggeractioncli.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- external surfaces (names invented; every callee is bound by its exe address) ---------------------------------
class UIStoreDialog : public UIDialog {};                        // RTTI name; only the dynamic_cast target is used
class Unk_SSGDlg4e47 : public UIStoreDialog {};                  // GetDialog<T> result type of FUN_140de48d0
struct Unk_StoreUIMgr
{
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
    void FUN_141adc530(int nId);
    void FUN_141add1f0();
};
Unk_StoreUIMgr* FUN_1403ed2b0();
void FUN_141b109a0(Unk_SSGDlg4e47* pDlg);
struct Unk_StoreInv
{
    MS2Ptr<CItem> FUN_140a5d680(__int64 nId);
    int FUN_140a661e0(CItem* pItem);
};
struct Unk_StoreEvents                                           // the item event hub (FUN_140a6a840), slots 8..12
{
    virtual void vfunc_0() = 0; virtual void vfunc_1() = 0; virtual void vfunc_2() = 0; virtual void vfunc_3() = 0;
    virtual void vfunc_4() = 0; virtual void vfunc_5() = 0; virtual void vfunc_6() = 0; virtual void vfunc_7() = 0;
    virtual void vfunc_8(CItem* pItem) = 0;                      // item added
    virtual void vfunc_9(CItem* pItem) = 0;                      // item removed
    virtual void vfunc_10(CItem* pItem) = 0;                     // item count changed
    virtual void vfunc_11() = 0;                                 // list loaded
    virtual void vfunc_12() = 0;                                 // store ready
};
Unk_StoreEvents* FUN_140a6a840();
struct Unk_GuildConstInt { char m_b[0x58]; };
struct Unk_AuConfig                                              // the account config; only four int constants are read
{
    char m_pad[0x44a8];
    Unk_GuildConstInt m_44a8, m_4500, m_4558, m_45b0;
};
MS2_CHECK_SIZE(Unk_AuConfig, 0x4608);
Unk_AuConfig* FUN_1401d3200();
int* FUN_1402056b0(Unk_GuildConstInt* p);
int FUN_1408b6200(int nType);
struct Unk_StoreStatusMgr { void FUN_141b0ce20(int, int); };
Unk_StoreStatusMgr* FUN_140aa6d40();
unsigned char FUN_140361ab0(void* pMap, int nKey, int* pValue);
struct Unk_SsMap;
void FUN_14016a050(Unk_SsMap* pMap, int nKey, int nValue);
CItemData* FUN_140527840(CItem* pItem);
int FUN_14052a7e0(MS2Ptr<CItem> a, MS2Ptr<CItem> b);
void FUN_140710590(COutPacket& packet);
void FUN_1401fba60(unsigned char* pReq, COutputStream& rStream);
void FUN_1401fbaf0(unsigned char* pReq, COutputStream& rStream);
void FUN_1401fba60(unsigned char* pReq, COutputStream& rStream);
struct Unk_KhCamera;
Unk_KhCamera* FUN_140c8dac0();
__int64 FUN_140c8dab0(Unk_KhCamera* p);
struct Unk_SSG535320 { __int64 FUN_140c8b2e0(); };
Unk_SSG535320* FUN_140535320();
CStringW GetStringCommonByKey(const CStringW& rKey);
void FUN_1412751f0(const CStringW& rText, int nA, int nB);
void FUN_141275260(int nId, int nA, int nB);
void FUN_140d73bc0(int nId, int nA, IMessageListener* pListener, CStringW strExtra);
void FUN_140d73aa0(CStringW strText, int nA, int nB, CStringW strExtra);
CStringW FUN_1408116a0(int nId, const int& rArg);
CStringW FUN_1409e97f0(int nId, const int& rArg);
CStringW FUN_140763e10(int nValue);
template <class T> void Unk_AkoMessage(int nId, int nA, int nB, const T& rArg);
void FUN_140961010(int nId, int nA, int nB, const CStringW& rArg);
CEffectService* FUN_1403ed280();
void FUN_140720e50(void* pDest, void* pSrc, unsigned __int64 nCount);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
void* FUN_1401b59c0();
Unk_SSGDlg4e47* FUN_140de48d0(int nId);
extern char DAT_143ab2a90;
extern char DAT_143ab2d80;
extern __int64 DAT_143ab2828;
extern int DAT_143ab2864;
extern __int64 DAT_143ab28f8;
// /Ob0: the exe reads these globals inline, so they are macros
#define Unk_Inventory() (reinterpret_cast<Unk_StoreInv*>(&DAT_143ab2a90))
#define Unk_StoreInstance() (reinterpret_cast<CStore*>(&DAT_143ab2d80))

// ---- CStore -----------------------------------------------------------------------------------------------------
// @0x140de11a0
int CStore::Add(CItem* pItem)
{
    if (Unk_LockGuard guard = m_lock) {
    } else {
        if (m_items.Lookup(pItem->FUN_140526a50())) {
            return 0x11;
        }
        int nSlot = pItem->FUN_140526b50();
        if ((int)m_slots.GetCount() <= nSlot) {
            return 0xd;
        }
        if (nSlot == -1) {
            nSlot = EmptySlot();
            if (nSlot == -1) {
                return 0xd;
            }
            pItem->FUN_140526b70(nSlot);
        } else if (m_slots[nSlot].get() != 0) {
            return 0x11;
        }
        pItem->FUN_140526a30(1);
        m_items.SetAt(pItem->FUN_140526a50(), MS2Ptr<CItem>(pItem));
        m_slots[nSlot].AssignRaw(pItem);
    }
    return 0;
}

// @0x140de1380
void CStore::Remove(__int64 nId)
{
    MS2Ptr<CItem> pItem;
    if (Unk_LockGuard guard = m_lock) {
    } else if (m_items.Lookup(nId, pItem)) {
        m_items.RemoveKey(nId);
        if (pItem.get() != 0) {
            m_slots[((CItem*)pItem)->FUN_140526b50()] = 0;
            ((CItem*)pItem)->FUN_140526a30(0);
        }
    }
}

// @0x140de1490
MS2Ptr<CItem> CStore::Find(__int64 nId)
{
    MS2Ptr<CItem> pItem;
    {
        if (Unk_LockGuard guard = m_lock) {
        } else {
            m_items.Lookup(nId, pItem);
        }
    }
    return pItem;
}

// @0x140de1540
MS2Ptr<CItem> CStore::FindType(int nType)
{
    {
        if (Unk_LockGuard guard = m_lock) {
        } else {
            for (POSITION pos = m_items.GetHeadPosition(); pos; m_items.GetNext(pos)) {
                MS2Ptr<CItem> pItem(m_items.GetValueAt(pos));
                if (((CItem*)pItem)->FUN_1405276c0() == nType) {
                    return pItem;
                }
            }
        }
    }
    return MS2Ptr<CItem>(0);
}

// @0x140de1680
MS2Ptr<CItem> CStore::FindTypeCount(int nType, unsigned nCount)
{
    {
        if (Unk_LockGuard guard = m_lock) {
        } else {
            for (POSITION pos = m_items.GetHeadPosition(); pos; m_items.GetNext(pos)) {
                MS2Ptr<CItem> pItem(m_items.GetValueAt(pos));
                if (((CItem*)pItem)->FUN_1405276c0() == nType) {
                    if (nCount <= (unsigned)((CItem*)pItem)->FUN_140526c50()) {
                        return pItem;
                    }
                }
            }
        }
    }
    return MS2Ptr<CItem>(0);
}

// @0x140de17e0
int CStore::HasCount(int nType, int nCount)
{
    int nHave = CountType(nType);
    return nHave >= nCount;
}

// @0x140de1830
int CStore::CountType(int nType)
{
    int nTotal = 0;
    if (Unk_LockGuard guard = m_lock) {
    } else {
        int nLength = (int)m_slots.GetCount();
        for (int i = 0; i < nLength; i++) {
            MS2Ptr<CItem> pItem(m_slots[i]);
            if (pItem.get() != 0) {
                if (((CItem*)pItem)->FUN_1405276c0() == nType) {
                    nTotal += ((CItem*)pItem)->FUN_140526c50();
                }
            }
        }
    }
    return nTotal;
}

// @0x140de1950
int CStore::FreeTypeCount(int nType)
{
    int nFree = 0;
    if (Unk_LockGuard guard = m_lock) {
    } else {
        int nLength = (int)m_slots.GetCount();
        for (int i = 0; i < nLength; i++) {
            MS2Ptr<CItem> pItem(m_slots[i]);
            if (pItem.get() != 0) {
                if (((CItem*)pItem)->FUN_1405276c0() == nType) {
                    ((CItem*)pItem)->FUN_1405281e0();
                    ((CItem*)pItem)->FUN_140526c50();
                    int nLimit = ((CItem*)pItem)->FUN_1405281e0();
                    int nHeld = ((CItem*)pItem)->FUN_140526c50();
                    nFree += nLimit - nHeld;
                }
            }
        }
    }
    return nFree;
}

// @0x140de1af0
MS2Ptr<CItem> CStore::Slot(int nSlot)
{
    MS2Ptr<CItem> pItem(0);
    int nCount = (int)m_slots.GetCount();
    if (nSlot < 0 || nSlot >= nCount)
        return MS2Ptr<CItem>(0);
    {
        if (Unk_LockGuard guard = m_lock) {
        } else {
            pItem = m_slots[nSlot];
        }
    }
    return pItem;
}

// @0x140de1c00
int CStore::Count()
{
    return (int)m_items.GetCount();
}

// @0x140de1c30
int CStore::Capacity()
{
    return m_capacity;
}

// @0x140de1c50
int CStore::Swap(int nA, int nB)
{
    if (Unk_LockGuard guard = m_lock) {
    } else {
        MS2Ptr<CItem> pFirst = Slot(nA);
        if (pFirst.get() != 0) {
            Remove(((CItem*)pFirst)->FUN_140526a50());
            ((CItem*)pFirst)->FUN_140526b70(nB);
        }
        MS2Ptr<CItem> pSecond = Slot(nB);
        if (pSecond.get() != 0) {
            Remove(((CItem*)pSecond)->FUN_140526a50());
            ((CItem*)pSecond)->FUN_140526b70(nA);
        }
        if (pFirst.get() != 0) {
            Add(pFirst.get());
        }
        if (pSecond.get() != 0) {
            Add(pSecond.get());
        }
    }
    return 1;
}

// @0x140de1dd0
int CStore::Move(int nSlot, MS2Ptr<CItem> pItem)
{
    if (pItem == 0) {
        return 0;
    } else if (nSlot < 0 || (int)m_slots.GetCount() <= nSlot) {
        return 0;
    } else if (((CItem*)pItem)->FUN_140526b50() == nSlot) {
        return 1;
    } else {
        if (Unk_LockGuard guard = m_lock) {
        } else {
            MS2Ptr<CItem> pOld(m_slots[nSlot]);
            if (pOld.get() != 0) {
                return 0;
            }
            m_slots[nSlot] = pItem;
            ((CItem*)pItem)->FUN_140526b70(nSlot);
            ((CItem*)pItem)->FUN_140526a30(1);
        }
        return 1;
    }
}

// @0x140de1fd0
void CStore::Append(ATL::CAtlArray<MS2Ptr<CItem> >& rItems)
{
    if (Unk_LockGuard guard = m_lock) {
    } else {
        for (POSITION pos = m_items.GetHeadPosition(); pos; m_items.GetNext(pos)) {
            MS2Ptr<CItem> pItem(m_items.GetValueAt(pos));
            rItems.Add(pItem);
        }
    }
}

// @0x140de20a0
int CStore::EmptySlot()
{
    {
        if (Unk_LockGuard guard = m_lock) {
        } else {
            int nLength = (int)m_slots.GetCount();
            for (int i = 0; i < nLength; i++) {
                MS2Ptr<CItem> pItem(m_slots[i]);
                if (pItem == 0) {
                    return i;
                }
            }
        }
    }
    return -1;
}

// @0x140de21a0
int CStore::AvailableSlot(MS2Ptr<CItem> pItem, int nCount)
{
    if (pItem.get() != 0) {
        if (((CItem*)pItem)->FUN_1405281e0() > 1) {
            int nFree = FreeTypeCount(((CItem*)pItem)->FUN_1405276c0());
            if (nCount <= nFree) {
                return 0;
            }
        }
    }
    return EmptySlot();
}

// @0x140de2270
int CStore::NeedsSort()
{
    MS2Ptr<CItem> pFirst(0);
    MS2Ptr<CItem> pSecond(0);
    if (Unk_LockGuard guard = m_lock) {
    } else {
        if (CanMerge() != 0) {
            return 1;
        }
        int nCount = (int)m_slots.GetCount();
        for (int i = 1; i < nCount; i++) {
            pFirst = m_slots[i - 1];
            pSecond = m_slots[i];
            if (FUN_14052a7e0(pFirst, pSecond) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

// @0x140de2490
int CStore::Allowed(int nType)
{
    if (m_type == 0) {
        return 1;
    }
    MS2Ptr<CItemData> pData = FUN_14053f870(m_type);
    if (pData.get() != 0) {
        MS2Ptr<CBankData> pBank = static_cast<CBankTable*>(FUN_1401b59c0())->GetBankData(pData->FUN_14053dce0());
        if (pBank.get() != 0) {
            return pBank->IsStorable(nType);
        }
    }
    return 0;
}

// @0x140de2580
int CStore::CanMerge()
{
    MS2Ptr<CItem> pItem(0);
    MS2Ptr<CItemData> pData(0);
    ATL::CAtlMap<unsigned short, int> seen;
    int nCount = (int)m_slots.GetCount();
    for (int i = 0; i < nCount; i++) {
        pItem = m_slots[i];
        if (!(pItem == 0)) {
            pData.AssignRaw(FUN_140527840(pItem));
            if (!(pData == 0)) {
                if (pData->FUN_14053c7c0()) {
                    unsigned nMax = pData->property.slotMax;
                    if ((unsigned)((CItem*)pItem)->FUN_140526c50() < nMax) {
                        int nOther;
                        if (FUN_140361ab0(&seen, ((CItem*)pItem)->FUN_1405276c0(), &nOther)) {
                            return 1;
                        }
                        FUN_14016a050(reinterpret_cast<Unk_SsMap*>(&seen), ((CItem*)pItem)->FUN_1405276c0(), i);
                    }
                }
            }
        }
    }
    return 0;
}

// @0x140de27c0
__int64 CStore::Id()
{
    return m_id;
}

// @0x140de27e0
void CStore::SetId(__int64 nId, int nType)
{
    m_id = nId;
    m_type = nType;
    m_capacity = m_id != 0 ? FUN_1408b6200(nType) : 0x24;
    Clear();
}

// @0x140de2860
int CStore::Ready()
{
    return m_ready;
}

// @0x140de2880
void CStore::SetReady(int nReady)
{
    m_ready = nReady;
}

// @0x140de28a0
void CStore::Extend(int nExtended)
{
    if (m_id != 0) {
        return;
    }
    m_extended = nExtended;
    m_capacity = m_extended + 0x24;
    if ((int)m_slots.GetCount() < m_capacity) {
        size_t nOld = m_slots.GetCount();
        MS2Ptr<CItem> pNull(0);
        m_slots.InsertAt(nOld, pNull, m_capacity - nOld);
    }
}

// @0x140de2970
int CStore::WithinCapacity()
{
    return m_capacity >= CurrentCapacity();
}

// @0x140de29b0
int CStore::CurrentCapacity()
{
    return m_id != 0 ? Capacity() : *FUN_1402056b0(&FUN_1401d3200()->m_44a8) + 0x24;
}

// @0x140de2a00
void CStore::Reset()
{
    ResetId(0, 0);
}

// @0x140de2a30
void CStore::ResetId(__int64 nId, int nType)
{
    Clear();
    SetReady(0);
    SetId(nId, nType);
}

// @0x140de2a80
__int64 CStore::Value4558()
{
    return *FUN_1402056b0(&FUN_1401d3200()->m_4558);
}

// @0x140de2ab0
__int64 CStore::Value45b0()
{
    return *FUN_1402056b0(&FUN_1401d3200()->m_45b0);
}

// @0x140de2ae0
__int64 CStore::Value4500()
{
    return *FUN_1402056b0(&FUN_1401d3200()->m_4500);
}

// @0x140de2b10
void CStore::SetReceived(int nReceived)
{
    m_received = nReceived;
}

// @0x140de2b30
int CStore::Received()
{
    return m_received;
}

// @0x140de2b50
void CStore::RequestLoad()
{
    LoadRequest request;
    request.m_id = Id();
    COutPacket packet(static_cast<int>(SendOp::RequestItemStorage), 0);
    packet.vfunc_o10_1(0xc);
    FUN_1401fba60(reinterpret_cast<unsigned char*>(&request), packet);
    FUN_140710590(packet);
}

// @0x140de2bd0
void CStore::RequestClose()
{
    COutPacket packet(static_cast<int>(SendOp::RequestItemStorage), 0);
    packet.vfunc_o10_1(8);
    packet.vfunc_o10_4(Id());
    FUN_140710590(packet);
}

// @0x140de2c40
void CStore::RequestAction(int nAction, __int64 nId)
{
    COutPacket packet(static_cast<int>(SendOp::RequestItemStorage), 0);
    packet.vfunc_o10_1(3);
    packet.vfunc_o10_4(Id());
    packet.vfunc_o10_1(nAction);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// @0x140de2ce0
void CStore::RequestExtend()
{
    __int64 nId = Id();
    if (nId == 0) {
        COutPacket packet(static_cast<int>(SendOp::RequestItemStorage), 0);
        packet.vfunc_o10_1(6);
        packet.vfunc_o10_4(nId);
        FUN_140710590(packet);
    }
}

// @0x140de2d60
void CStore::RequestSort()
{
    COutPacket packet(static_cast<int>(SendOp::RequestItemStorage), 0);
    packet.vfunc_o10_1(0xf);
    FUN_140710590(packet);
}

// The client asks the server to move `nCount` of the inventory item `nId` into store slot `nSlot` (packet 0), unless the
// item is bound to the played score / the summoned pet or the inventory refuses it. Names invented.
// @0x140de2dc0
void FUN_140de2dc0(void*, __int64 nId, int nSlot, int nCount, MS2Ptr<CItemData> pSound)
{
    MS2Ptr<CItem> pItem = Unk_Inventory()->FUN_140a5d680(nId);
    if (!pItem) {
        return;
    }
    if (FUN_140527840(pItem)->FUN_14053cd10()) {
        if (FUN_140c8dab0(FUN_140c8dac0()) == ((CItem*)pItem)->FUN_140526a50()) {
            FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_item_err_binditem_by_playing_score")), 1, 1);
            return;
        }
    }
    if (((CItem*)pItem)->FUN_140525640() != 0) {
        if (FUN_140535320()->FUN_140c8b2e0() == nId) {
            FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_item_err_binditem_by_summon_pet")), 1, 1);
            return;
        }
    }
    if (Unk_Inventory()->FUN_140a661e0(pItem.get()) == 0) {
        return;
    }
    CStore::MoveRequest request;
    request.m_id = Unk_StoreInstance()->Id();
    request.m_item = nId;
    request.m_slot = nSlot;
    request.m_count = nCount;
    COutPacket packet(static_cast<int>(SendOp::RequestItemStorage), 0);
    packet.vfunc_o10_1(0);
    FUN_1401fbaf0(reinterpret_cast<unsigned char*>(&request), packet);
    FUN_140710590(packet);
    if (pSound.get() != 0) {
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), pSound->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    }
}

// The client asks the server to add `nCount` of the store item `nId` to the inventory slot `nSlot` (packet 1).
// @0x140de31f0
void FUN_140de31f0(CStore* pStore, __int64 nId, int nSlot, int nCount, MS2Ptr<CItemData> pSound)
{
    {
        MS2Ptr<CItem> pItem = Unk_StoreInstance()->Find(nId);
        if (pItem.get() != 0) {
            if (Unk_Inventory()->FUN_140a661e0(pItem.get()) == 0) {
                return;
            }
            if (((CItem*)pItem)->FUN_14052a580((void*)DAT_143ab2828) != 1) {
                return;
            }
        }
    }
    COutPacket packet(static_cast<int>(SendOp::RequestItemStorage), 0);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_4(pStore->Id());
    packet.vfunc_o10_4(nId);
    packet.vfunc_o10_2(nSlot);
    packet.vfunc_o10_3(nCount);
    FUN_140710590(packet);
    if (pSound.get() != 0) {
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), pSound->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    }
}

// @0x140de3480
void CStore::Dispatch(CInPacket* pPacket)
{
    int nType = pPacket->vfunc_o8_1();
    if (nType == 0xb) {
        OnClear(pPacket);
    } else if (nType == 4) {
        OnBegin(pPacket);
    } else if (nType == 5) {
        OnItems(pPacket);
    } else if (nType == 0) {
        OnAdd(pPacket);
    } else if (nType == 1) {
        OnRemove(pPacket);
    } else if (nType == 9) {
        OnCount(pPacket);
    } else if (nType == 3) {
        OnCurrency(pPacket);
    } else if (nType == 0xd) {
        OnExtend(pPacket);
    } else if (nType == 7) {
        OnClose(pPacket);
    } else if (nType == 2) {
        OnSwap(pPacket);
    } else if (nType == 8) {
        OnList(pPacket);
    } else if (nType == 0xe) {
        OnReset(pPacket);
    } else if (nType == 0x10) {
        OnError(pPacket);
    }
}

// @0x140de3610
void CStore::OnClear(CInPacket*)
{
    Clear();
}

// @0x140de3640
void CStore::OnBegin(CInPacket* pPacket)
{
    __int64 nId = pPacket->vfunc_o8_4();
    if (Id() != nId) {
        MS2_ASSERT_AT(0x2dd, 0);
        return;
    }
    if (nId == 0) {
        FUN_1403ed2b0()->FUN_141adc530(0x4e47);
    }
    int nCount = (unsigned short)pPacket->vfunc_o8_2();
    SetReceived(nCount);
    if (nCount == 0) {
        SetReady(1);
        FUN_140a6a840()->vfunc_12();
    }
}

// @0x140de3740
void CStore::OnItems(CInPacket* pPacket)
{
    __int64 nId = pPacket->vfunc_o8_4();
    if (Id() != nId) {
        MS2_ASSERT_AT(0x2f7, 0);
        return;
    }
    int nCount = (unsigned short)pPacket->vfunc_o8_2();
    for (int i = 0; i < nCount; i++) {
        ReadItem(pPacket);
    }
    if (Count() == Received()) {
        SetReady(1);
        SetReceived(0);
        FUN_140a6a840()->vfunc_12();
    }
}

// @0x140de3870
void CStore::OnAdd(CInPacket* pPacket)
{
    __int64 nId = pPacket->vfunc_o8_4();
    if (Id() != nId) {
        MS2_ASSERT_AT(0x30f, 0);
        return;
    }
    ReadItem(pPacket);
    SetReady(1);
}

// @0x140de3910
void CStore::OnRemove(CInPacket* pPacket)
{
    __int64 nId = pPacket->vfunc_o8_4();
    if (Id() != nId) {
        MS2_ASSERT_AT(0x31d, 0);
        return;
    }
    __int64 nItemId = pPacket->vfunc_o8_4();
    MS2Ptr<CItem> pItem = Find(nItemId);
    if (!pItem) {
        return;
    }
    Remove(nItemId);
    FUN_140a6a840()->vfunc_9(pItem.get());
}

// @0x140de3a50
void CStore::OnCount(CInPacket* pPacket)
{
    __int64 nId = pPacket->vfunc_o8_4();
    if (Id() != nId) {
        MS2_ASSERT_AT(0x331, 0);
        return;
    }
    __int64 nItemId = pPacket->vfunc_o8_4();
    int nCount = pPacket->vfunc_o8_3();
    MS2Ptr<CItem> pItem = Find(nItemId);
    if (!pItem) {
        return;
    }
    ((CItem*)pItem)->FUN_140526c70(nCount);
    FUN_140a6a840()->vfunc_10(pItem.get());
}

// @0x140de3bc0
void CStore::OnCurrency(CInPacket* pPacket)
{
    if (Id() != 0) {
        MS2_ASSERT_AT(0x346, 0);
        return;
    }
    __int64 nCurrency = pPacket->vfunc_o8_4();
    DAT_143ab28f8 = nCurrency;
    FUN_140aa6d40()->FUN_141b0ce20(10, 0);
}

// @0x140de3c60
void CStore::OnExtend(CInPacket* pPacket)
{
    if (Id() != 0) {
        MS2_ASSERT_AT(0x356, 0);
        return;
    }
    int nExtended = pPacket->vfunc_o8_3();
    Extend(nExtended);
}

// @0x140de3ce0
void CStore::OnClose(CInPacket*)
{
    Unk_SSGDlg4e47* pDlg = FUN_140de48d0(0x4e47);
    if (pDlg != 0) {
        if (pDlg->vfunc_55() == 0) {
            FUN_141b109a0(pDlg);
        }
    }
}

// @0x140de3d40
void CStore::OnSwap(CInPacket* pPacket)
{
    __int64 nId = pPacket->vfunc_o8_4();
    if (Id() != nId) {
        MS2_ASSERT_AT(0x36b, 0);
        return;
    }
    MS2Ptr<CItem> items[2] = { MS2Ptr<CItem>(0), MS2Ptr<CItem>(0) };
    for (int i = 0; i < 2; i++) {
        __int64 nItemId = pPacket->vfunc_o8_4();
        short nSlot = pPacket->vfunc_o8_2();
        if (nItemId == 0) {
            continue;
        }
        items[i] = Find(nItemId);
        if (!items[i]) {
            continue;
        }
        Remove(nItemId);
        ((CItem*)items[i])->FUN_140526b70((int)nSlot);
    }
    for (unsigned i = 0; i < 2; i++) {
        if (items[i].get() != 0) {
            Add(items[i].get());
        }
    }
    for (unsigned i = 0; i < 2; i++) {
        if (items[i].get() != 0) {
            FUN_140a6a840()->vfunc_10(items[i].get());
        }
    }
}

// @0x140de4030
void CStore::OnList(CInPacket* pPacket)
{
    __int64 nId = pPacket->vfunc_o8_4();
    if (Id() != nId) {
        MS2_ASSERT_AT(0x395, 0);
        return;
    }
    int nCount = (unsigned short)pPacket->vfunc_o8_2();
    for (int i = 0; i < nCount; i++) {
        int nType = pPacket->vfunc_o8_3();
        __int64 nUid = pPacket->vfunc_o8_4();
        short nSlot = pPacket->vfunc_o8_2();
        int nAmount = pPacket->vfunc_o8_3();
        MS2Ptr<CItem> pItem(new CItem());
        if (((CItem*)pItem)->FUN_140523c40(nType, nAmount, 0)) {
            ((CItem*)pItem)->FUN_140526b30(DAT_143ab2864);
            ((CItem*)pItem)->FUN_140526a70(nUid);
            int nIndex = (int)nSlot;
            ((CItem*)pItem)->FUN_140526b70(nIndex);
            ((CItem*)pItem)->FUN_140524eb0(*pPacket);
            Add(pItem.get());
        }
    }
    FUN_140a6a840()->vfunc_11();
}

// @0x140de4320
void CStore::OnReset(CInPacket*)
{
    Reset();
    FUN_1403ed2b0()->FUN_141adc530(0x4e47);
}

// @0x140de4360
void CStore::OnError(CInPacket* pPacket)
{
    int nError = pPacket->vfunc_o8_3();
    switch (nError) {
    case 10:
        FUN_140d73bc0(0xeb, 0, 0, CStringW(L""));
        break;
    default:
        FUN_1412751f0(FUN_1408116a0(0x2af, nError), 1, 1);
        break;
    case 0xc:
        FUN_141275260(0xf1, 1, 0);
        break;
    case 0xd:
        FUN_141275260(0xf2, 1, 1);
        break;
    case 0xe: {
        int nCapacity = Unk_StoreInstance()->CurrentCapacity();
        CStringW strText = FUN_1409e97f0(0x2b0, nCapacity);
        FUN_140d73aa0(CStringW(strText), 0, 0, CStringW(L""));
        break;
    }
    case 0xf:
        FUN_1403ed2b0()->FUN_141add1f0();
        break;
    case 0x10:
        FUN_141275260(0xfb, 1, 1);
        break;
    case 0x11:
        FUN_141275260(0xfc, 1, 1);
        break;
    case 0x12:
        FUN_141275260(0x2b1, 1, 1);
        break;
    case 0x13:
        FUN_141275260(0x2b2, 1, 1);
        break;
    case 0x14:
        FUN_140961010(0x2b3, 1, 1, FUN_140763e10(2000000000));
        break;
    case 0x15:
        FUN_141275260(0xa5e, 1, 1);
        break;
    case 0x16:
        FUN_141275260(0xff, 1, 1);
        break;
    }
}

// @0x140de4690
void CStore::ReadItem(CInPacket* pPacket)
{
    int nType = pPacket->vfunc_o8_3();
    __int64 nUid = pPacket->vfunc_o8_4();
    short nSlot = pPacket->vfunc_o8_2();
    int nAmount = pPacket->vfunc_o8_3();
    MS2Ptr<CItem> pItem(new CItem());
    if (((CItem*)pItem)->FUN_140523c40(nType, nAmount, 0)) {
        ((CItem*)pItem)->FUN_140526b30(DAT_143ab2864);
        ((CItem*)pItem)->FUN_140526a70(nUid);
        int nIndex = (int)nSlot;
        ((CItem*)pItem)->FUN_140526b70(nIndex);
        ((CItem*)pItem)->FUN_140524eb0(*pPacket);
        Add(pItem.get());
        FUN_140a6a840()->vfunc_8(pItem.get());
    }
}

// @0x140de48d0
Unk_SSGDlg4e47* FUN_140de48d0(int nId)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get()) {
            return static_cast<Unk_SSGDlg4e47*>(dynamic_cast<UIStoreDialog*>(p.operator->()));
        }
    }
    return 0;
}

// @0x140de4970
CStore::MoveRequest::MoveRequest()
{
    m_id = 0;
    m_item = 0;
    m_slot = 0;
    m_count = 0;
}

// @0x140de49b0
CStore::LoadRequest::LoadRequest()
{
    m_id = 0;
}

// @0x140de4cb0
TriggerActionCli* FUN_140de4cb0()
{
    return new TriggerActionCli();
}
