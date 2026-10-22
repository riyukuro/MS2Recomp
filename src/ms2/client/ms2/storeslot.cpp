// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StoreSlot and StoreSlotBag: the slots of the npc shop window.
// See storeslot.h. Member and local names are invented from the use.
// MS2-UNIT: client\ms2\storeslot.cpp
// MS2-RANGE: 0x141808730-0x14180bc30 .text$mn
// MS2-RANGE: 0x14010cbd0-0x14010cf80 .text$di
// MS2-PIN: ??_7StoreSlot@@6BBindData@NotifyContext@@@ 0x142f7e458 ; hand: primary vftable
// MS2-PIN: ?TypeCast@StoreSlot@@UEBA_NIPEAPEAX@Z 0x14180b0d0 ; hand
// MS2-PIN: ?TypeCast@StoreSlot@@UEBA_NIPEAPEBX@Z 0x14180b120 ; hand
// MS2-PIN: ?TypeCast@StoreSlotBag@@UEBA_NIPEAPEAX@Z 0x14180ba70 ; hand
// MS2-PIN: ?TypeCast@StoreSlotBag@@UEBA_NIPEAPEBX@Z 0x14180bac0 ; hand
// MS2-PIN: ?GetClassDesc@StoreSlot@@UEBAPEBVClassInfo@efd@@XZ 0x14180b060 ; hand
// MS2-PIN: ?GetClassDesc@StoreSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x14180ba00 ; hand
// MS2-PIN: ??_7StoreSlot@@6B@ 0x142f7e548 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\storeslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "storeslot.h"
#include "store.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/itemutiltransfer.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_ItemEquipData : public CItemData { };          // CItem::FUN_140527840's record

// The store table as the exe binds it (these two methods are only functional in store.cpp, so call them by address).
class Unk_SsStoreView
{
public:
    int FUN_140de21a0(MS2Ptr<CItem> spItem, int nCount);   // CStore::AvailableSlot
    int FUN_140de2490(int nType);                           // CStore::Allowed
};
#define SS_STORE_VIEW (*reinterpret_cast<Unk_SsStoreView*>(&DAT_143ab2d80))

extern Unk_Inventory DAT_143ab2a90;                       // the player's inventory
extern __int64 DAT_143ab2828;

// The local player.
class Unk_SsPlayer
{
public:
    __int64 FUN_141656a80();                              // the character id
    int FUN_14166ce30();                                  // nonzero: the player is dead
};
class Unk_SsWorld
{
public:
    Unk_SsPlayer* FUN_141bd0cc0();                        // the local player
};
Unk_SsWorld* FUN_1403ed2d0();
CEffectService* FUN_1403ed280();                          // the sound service

// A dialog of the GetDialog<T> registry (the inventory 0x4e2d, the store 0x4e47).
class Unk_SsDialog : public UIDialog
{
public:
    CStringW FUN_141b10b50();                             // the search text of the store dialog
};
Unk_SsDialog* FUN_1405344f0(int nId);
Unk_SsDialog* FUN_140de48d0(int nId);
void FUN_141b10eb0(Unk_SsDialog* pDlg);                   // refresh the store dialog (icon search)

// The quest event dispatcher (FUN_140bfc4b0) the slot registers with.
class Unk_SsQuestEvents
{
public:
    void FUN_141aa87c0(UIQuestEventListener*);
    void FUN_141aa8850(UIQuestEventListener*);
};
Unk_SsQuestEvents* FUN_140bfc4b0();
// The item event hub (FUN_140a6a840) the bag registers with.
struct Unk_SsItemEvents;
Unk_SsItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_SsItemEvents*, UIItemEventListener*);
void FUN_1419caeb0(Unk_SsItemEvents*, UIItemEventListener*);

// The singleton that decides whether an item may be sold into the store.
class Unk_SsItemRules
{
public:
    int FUN_1416ce170(MS2Ptr<CItem> spItem);
};
Unk_SsItemRules* FUN_140764020();

// The input state (modifier keys).
class Unk_SsKeys
{
public:
    bool FUN_14116d950(int nKey, bool b, int c);
};
Unk_SsKeys* FUN_14025e7c0();

// The names of the inventory tabs.
class Unk_SsTabNames
{
public:
    CStringW FUN_141813300(int nTab);
};
Unk_SsTabNames* FUN_1401a9d70();

// The account state (a flag at +0xa9c).
struct Unk_SsAccount
{
    unsigned char prefix[0xa9c];
    bool flag;
    bool FUN_140a6a0d0();
};
MS2_CHECK_SIZE(Unk_SsAccount, 0xa9d);
Unk_SsAccount* FUN_1401c0d90();

// The character map iterator (the constructor makes it come back through a hidden pointer).
struct Unk_SsCharIter { Unk_SsCharIter(); void* node; };
MS2_CHECK_SIZE(Unk_SsCharIter, 8);
class Unk_InventoryCharacters
{
public:
    Unk_SsCharIter FUN_140341f40();                       // end
    Unk_SsCharIter FUN_1404c0270(const __int64& id);      // find
};
extern Unk_InventoryCharacters DAT_143ab2a30;
bool FUN_1403344a0(const Unk_SsCharIter&, const Unk_SsCharIter&);
bool FUN_140334210(const Unk_SsCharIter&, const Unk_SsCharIter&);

bool FUN_1406344b0(MS2Ptr<CItem> spItem, const __int64* pCharacter, ItemUtilTransfer::TOutBindingParam* pOut);

void* FUN_1409331e0();                                    // the game state manager
int FUN_14138c900(void* pMgr, int n);
CStringW GetStringCommon(int nStringId);                    // a string table text
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
void FUN_141275260(int nStringId, int nA, int nB);        // notice by string id
void FUN_140961010(int nId, int nA, int nB, const CStringW& rArg);
void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spData);
void FUN_141a026f0(CMsgBoxData* pBox, int n);
void FUN_141276180(const CString& strA, const CString& strB);
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);                 // item link / popup for the item
void* FUN_140a50b50(DragSlot* pSlot);                     // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                   // its item uid
void FUN_140710590(COutPacket& packet);                   // send the packet
CString FUN_140719530(unsigned __int64 v);                // "%I64u"
CString FUN_140719210(long v);                            // "%ld"
void FUN_140165270(void* pArr, const CString& str);       // append a string to the slot's data array
void FUN_1414049c0(void* pArr, int nType);
void FUN_141404ce0(int nType, void* pArr, Scaleform::GFx::Value* pValue);
void FUN_1414050c0(int nType, void* pArr, Scaleform::GFx::Value* pValue);
void FUN_1414043e0(__int64 nUid, int nCount, int nItemId, int bTake, int nSlot);   // request: buy
void FUN_1414045d0(__int64 nUid, int nCount, int nItemId, int bTake, int nSlot);   // request: sell
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);
CStringW FUN_1413fa9b0(const CStringW& kIn);
bool FUN_14025cd60(const CStringW&, const CStringW&);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
StoreSlot* FUN_14140e6d0(DragSlot* p);                    // the store slot behind a drag source (null: not one)
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(StoreSlot);

static CString s_strUpdateIconSearchOn = "updateIconSearchOn";
static CStringW s_strDestroyStoreItem = L"destroy_store_item";

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

static CString s_strSystemNoticeErrorWarningBag = "system_notice_error_warningBag";

EE_IMPLEMENT_CONCRETE_CLASS_INFO(StoreSlotBag);

// The second copy of the header statics (a second header of the unit defines the same ones).
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

StoreSlot* FUN_14140e6d0(DragSlot* p);
StoreSlotBag* FUN_14180b940(NotifyContext::BindData* p);
unsigned __int64 FUN_14180b810(int nIndex);

// @0x141808730
StoreSlot::StoreSlot(const CString& strName, int nIndex, unsigned __int64 nStoreItemId)
    : MS2DragSlot(strName, nIndex), m_nStoreItemId(nStoreItemId)
{
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    SetEnabled(true);
}

// @0x141808810
StoreSlot::~StoreSlot()
{
    FUN_140bfc4b0()->FUN_141aa8850(this);
}

// @0x1418088c0
void StoreSlot::SetStoreItemId(unsigned __int64 nItemId)
{
    m_nStoreItemId = nItemId;
}

// @0x1418088f0
unsigned __int64 StoreSlot::GetStoreItemId()
{
    return m_nStoreItemId;
}

// @0x141808910
int StoreSlot::FUN_141808910()
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(GetStoreItemId());
    if (spItem.get() == 0)
        return 0;
    return spItem->FUN_140527840()->FUN_14053dc20();
}

// @0x1418089a0
void StoreSlot::vfunc_6(void* p)
{
    FUN_140165270(p, FUN_140719530(m_nStoreItemId));
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(m_nStoreItemId);
    if (spItem.IsNull())
        return;
    int nType = spItem->FUN_1405276c0();
    if (spItem->FUN_140527840()->FUN_14053c5c0() == 2 || spItem->FUN_140527840()->FUN_14053c5c0() == 0x18)
        FUN_140165270(p, FUN_140719210(nType));
    FUN_1414049c0(p, FUN_141808910());
}

// @0x141808b10
int StoreSlot::FUN_141808b10(CStringW strSearch)
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(m_nStoreItemId);
    if (spItem.IsNull())
        return -1;
    if (FUN_1409b4d40(m_value18))
    {
        CStringW strName = spItem->FUN_140527b10();
        CStringW strLower = FUN_1413fa9b0(strName);
        bool bFound = false;
        if (strSearch.GetLength() > 0)
        {
            strSearch.MakeLower();
            strLower.MakeLower();
            bFound = FUN_14025cd60(strLower, strSearch);
        }
        AScript script(m_value18, 2);
        script.Invoke(s_strUpdateIconSearchOn, bFound);
        if (bFound)
            return m_nIndex;
    }
    return -1;
}

// @0x141808d30
int StoreSlot::vfunc_11()
{
    m_nStoreItemId = 0;
    return DragSlot::vfunc_11();
}

// @0x141808d60
int StoreSlot::vfunc_13()
{
    return vfunc_14();
}

// @0x141808d90
int StoreSlot::vfunc_14()
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(GetStoreItemId());
    if (spItem.IsNull())
        return 0;
    if (vfunc_26(spItem) == 1)
        return 1;
    if (DAT_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
        return 0;
    if (spItem->FUN_14052a580((void*)DAT_143ab2828) != 1)
    {
        FUN_140d73bc0(0xff, 0, 0, CStringW(L""));
        return 0;
    }
    Unk_SsDialog* pDlg = FUN_1405344f0(0x4e2d);
    if (pDlg != 0 && pDlg->vfunc_55() == 0)
    {
        int nTab = DAT_143ab2a90.FUN_140a617f0(spItem);
        bool bAll;
        if (FUN_14025e7c0()->FUN_14116d950(0x2a, false, 0) || FUN_14025e7c0()->FUN_14116d950(0x36, false, 0))
            bAll = true;
        else
            bAll = false;
        int nCount = bAll ? spItem->FUN_140526c50() : 1;
        int nSlot = DAT_143ab2a90.FUN_140a612b0(nTab, spItem, nCount);
        if (nSlot == -1)
        {
            FUN_140961010(0x44, 1, 1, FUN_1401a9d70()->FUN_141813300(nTab));
            FUN_141276180(s_strSystemNoticeErrorWarningBag, CString(""));
            return 0;
        }
        if (spItem->FUN_140526850() == false || bAll)
        {
            MS2Ptr<CItemData> spData((CItemData*)spItem->FUN_140527840());
            FUN_140de31f0(&MS2_STORE_TABLE, spItem->FUN_140526a50(), nSlot, spItem->FUN_140526c50(), spData);
        }
        else
        {
            FUN_1414043e0(spItem->FUN_140526a50(), spItem->FUN_140526c50(), spItem->FUN_1405281e0(), 1, m_nIndex);
        }
    }
    return 1;
}

// @0x141809280
int StoreSlot::vfunc_15()
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(GetStoreItemId());
    if (spItem.get() != 0)
        FUN_140d2cfc0(spItem);
    return DragSlot::vfunc_15();
}

// @0x141809310
int StoreSlot::vfunc_17()
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(GetStoreItemId());
    int nResult = vfunc_26(spItem);
    if (nResult == 0)
    {
        if (spItem->FUN_14052a580((void*)DAT_143ab2828) != 1)
        {
            FUN_140d73bc0(0xff, 0, 0, CStringW(L""));
            return 0;
        }
        vfunc_12();
    }
    else if (nResult == 1)
    {
        vfunc_12();
    }
    return 1;
}

// @0x141809460
int StoreSlot::vfunc_18(void* p)
{
    DragSlot* pDrag = static_cast<DragSlot*>(p);
    void* pItemSlot = FUN_140a50b50(pDrag);
    if (pItemSlot == 0)
    {
        StoreSlot* pFrom = FUN_14140e6d0(pDrag);
        if (pFrom != 0)
        {
            if (pFrom->GetIndex() == m_nIndex)
                return pDrag->vfunc_10();
            COutPacket packet(static_cast<int>(SendOp::RequestItemStorage), 0);
            packet.WriteUInt8(2);
            packet.WriteInt64(MS2_STORE_TABLE.Id());
            packet.WriteInt64(pFrom->GetStoreItemId());
            packet.WriteInt16((short)m_nIndex);
            FUN_140710590(packet);
            MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(pFrom->GetStoreItemId());
            if (spItem.get() != 0 && spItem.get() != 0)
            {
                if (spItem->FUN_140527840() != 0)
                    FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
                        spItem->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
            }
            return pFrom->vfunc_11();
        }
    }
    else
    {
        MS2Ptr<CItem> spStoreItem = MS2_STORE_TABLE.Slot(m_nIndex);
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pItemSlot));
        if (spItem == 0)
            return pDrag->vfunc_10();
        int nSlot = m_nIndex;
        if (spStoreItem.get() != 0)
        {
            int nAvail = 0;
            nSlot = 0;
            if (spItem->FUN_1405281e0() == 1)
            {
                nAvail = SS_STORE_VIEW.FUN_140de21a0(spItem, spItem->FUN_140526c50());
                if (nAvail == -1)
                {
                    FUN_141275260(0xf2, 1, 1);
                    return pDrag->vfunc_10();
                }
            }
        }
        if (SS_STORE_VIEW.FUN_140de2490(spItem->FUN_1405276c0()) == 0)
        {
            FUN_141275260(0xf1, 1, 0);
            return pDrag->vfunc_10();
        }
        if (DAT_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
            return pDrag->vfunc_10();
        if (spItem->FUN_140526850() == false)
        {
            FUN_140de2dc0(&MS2_STORE_TABLE, spItem->FUN_140526a50(), nSlot, spItem->FUN_140526c50(),
                MS2Ptr<CItemData>(0));
        }
        else
        {
            FUN_1414045d0(spItem->FUN_140526a50(), spItem->FUN_140526c50(), spItem->FUN_1405281e0(), 0, m_nIndex);
        }
    }
    return pDrag->vfunc_10();
}

// @0x141809b20
MS2Ptr<CItem> StoreSlot::vfunc_25()
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(GetStoreItemId());
    return spItem;
}

// @0x141809ba0
int StoreSlot::vfunc_20()
{
    DragSlot::vfunc_20();
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(m_nStoreItemId);
    if (spItem.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            spItem->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    return 1;
}

// @0x141809d10
int StoreSlot::vfunc_21()
{
    DragSlot::vfunc_21();
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(m_nStoreItemId);
    if (spItem.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            spItem->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    return vfunc_10();
}

// MS2-FUNCTIONAL: the frame layout of the many temporaries differs
// @0x141809ea0
int StoreSlot::vfunc_26(MS2Ptr<CItem> spItem)
{
    if (spItem.IsNull())
        return 0;
    if (FUN_14138c900(FUN_1409331e0(), 6) != 0)
    {
        FUN_141275260(0x88a, 1, 1);
        return 0;
    }
    Unk_SsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (pPlayer->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0x42, 0, 0, CStringW(L""));
        return 0;
    }
    if (spItem->FUN_140527930() == 0)
        return 0;

    CStringW strMsg;
    ItemUtilTransfer::TOutBindingParam param;
    __int64 nCharacter = pPlayer->FUN_141656a80();
    if (!FUN_1406344b0(spItem, &nCharacter, &param))
    {
        CStringW strName(param.name);
        bool bAllow;
        if (FUN_1401c0d90()->FUN_140a6a0d0() && spItem->FUN_1405258b0() != 0)
            bAllow = true;
        else
            bAllow = false;
        bool bGem = spItem->FUN_1405279c0()->FUN_1406210e0();
        if (bAllow && bGem)
        {
            FUN_140d73bc0(0xed, 0, 0, CStringW(L""));
            return 1;
        }
        if (!bAllow)
        {
            __int64 nOwner = param.characterId;
            if (nOwner == 0)
            {
                MS2_ASSERT_AT(0xf8, FALSE);
                return 1;
            }
            int nKind = param.kind;
            Unk_SsCharIter end = DAT_143ab2a30.FUN_140341f40();
            Unk_SsCharIter found = DAT_143ab2a30.FUN_1404c0270(nOwner);
            if (FUN_1403344a0(found, end))
            {
                if (nKind == 1)
                    FUN_140d73bc0(0xfc, 0, 0, CStringW(L""));
                else if (nKind == 2)
                    FUN_140d73aa0(GetStringCommon(0xdc), 0, 0, CStringW(L""));
                return 1;
            }
            if (nKind == 1)
                strMsg = FUN_14052bd00(0xda, strName);
            else if (nKind == 2)
                strMsg = FUN_14052bd00(0xdd, strName);
        }
    }
    __int64 nPrice = spItem->FUN_14052a480();
    if (strMsg.IsEmpty() && nPrice != 0 && nPrice != DAT_143ab2828)
    {
        Unk_SsCharIter end = DAT_143ab2a30.FUN_140341f40();
        Unk_SsCharIter found = DAT_143ab2a30.FUN_1404c0270(nPrice);
        if (FUN_140334210(found, end))
            strMsg = FUN_1405c2690(CStringW(L"s_item_err_cannot_drop_if_moveDisable"), spItem->FUN_14052a4f0());
    }
    if (!strMsg.IsEmpty())
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, CStringW(strMsg), 0, CStringW(s_strDestroyStoreItem));
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01600(m_nStoreItemId);
            spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, spItem->FUN_140526c50(), -1, -1, 1);
            spBox->FUN_141a01800(1);
            FUN_141a026f0(spBox.get(), 1);
            spBox->FUN_141a024e0(GetStringCommon(0x9d1), 0);
            FUN_140d73c60(spBox);
            return 1;
        }
    }
    return 0;
}

// @0x14180a970 (ITooltip::vfunc_0)
int StoreSlot::vfunc_0(void* p)
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(m_nStoreItemId);
    if (spItem.IsNull())
        return 0;
    ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x80, 2);
    if (tip.FUN_1409e0d40(spItem.get()) == 0)
        return 0;
    tip.FUN_1409c69b0(GetStringCommon(0x754));
    if (IsEnabled() == true)
        tip.FUN_1409db7b0(spItem);
    *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
    return 1;
}

// @0x14180ab10
int StoreSlot::vfunc_8(void* p)
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(m_nStoreItemId);
    if (spItem.IsNull())
        return 0;
    ASSlot slot(2);
    Unk_SsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (slot.FUN_1409c3860(spItem.get(), pPlayer, 0x1c01f) == 0)
        return 0;
    slot.FUN_1407cbbe0(s_strUpdateIconSearchOn, FUN_14180aea0());
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}

// @0x14180ac70
CStringW StoreSlot::vfunc_22()
{
    return GetStringCommon(0x754);
}

// @0x14180acb0
void StoreSlot::vfunc_23(void* p)
{
    FUN_141404ce0(FUN_141808910(), p, &m_value18);
}

// @0x14180ad00
void StoreSlot::vfunc_24(void* p)
{
    int nType = FUN_141808910();
    if (nType != 0)
        FUN_1414050c0(nType, p, &m_value18);
}

// @0x14180ad50
void StoreSlot::vfunc_o178_2(void*)
{
    FUN_14180ade0();
}

// @0x14180ad80
void StoreSlot::vfunc_o178_1(void*)
{
    FUN_14180ade0();
}

// @0x14180adb0
void StoreSlot::vfunc_o178_5(void*)
{
    FUN_14180ade0();
}

// @0x14180ade0
void StoreSlot::FUN_14180ade0()
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(GetStoreItemId());
    if (spItem.IsNull())
        return;
    if (FUN_140764020()->FUN_1416ce170(spItem) != 0)
        vfunc_10();
}

// @0x14180aea0
bool StoreSlot::FUN_14180aea0()
{
    MS2Ptr<CItem> spItem = MS2_STORE_TABLE.Find(m_nStoreItemId);
    if (spItem == 0)
        return false;
    bool bResult = false;
    Unk_SsDialog* pDlg = FUN_140de48d0(0x4e47);
    if (pDlg != 0)
    {
        if (pDlg->vfunc_55() == 0)
        {
            CStringW strQuery = pDlg->FUN_141b10b50();
            if (strQuery.GetLength() > 0)
            {
                CStringW strName = spItem->FUN_140527b10();
                CStringW strLower = FUN_1413fa9b0(strName);
                strQuery.MakeLower();
                strLower.MakeLower();
                bResult = FUN_14025cd60(strLower, strQuery);
            }
        }
    }
    return bResult;
}

// @0x14180b170
void FUN_14180b170(const CString& strName, int nStoreId, int nCount)
{
    StoreSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) StoreSlotBag(strName, nStoreId);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x14180b230
void FUN_14180b230(const CString& strName)
{
    StoreSlotBag* pBag = FUN_14180b940(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x14180b280
StoreSlotBag::StoreSlotBag(const CString& strName, int nStoreId)
    : DragSlotBag(strName), m_nStoreId(nStoreId)
{
    FUN_1419cae20(FUN_140a6a840(), this);
}

// @0x14180b340
StoreSlotBag::~StoreSlotBag()
{
    FUN_1419caeb0(FUN_140a6a840(), this);
}

// @0x14180b3e0
int StoreSlotBag::FUN_14180b3e0(CStringW strSearch)
{
    int nResult = -1;
    for (std::pair<const int, CString> entry : m_slots)
    {
        StoreSlot* pSlot = FUN_14140e6d0(FUN_1422cd0f0(entry.second));
        if (pSlot != 0)
        {
            int nIndex = pSlot->FUN_141808b10(strSearch);
            if (nIndex == -1)
                continue;
            if (nResult == -1)
                nResult = nIndex;
            else
                nResult = nResult < nIndex ? nResult : nIndex;
        }
    }
    return nResult;
}

// @0x14180b560
void StoreSlotBag::vfunc_9(void* p)
{
    CItem* pItem = static_cast<CItem*>(p);
    StoreSlot* pSlot = FUN_14140e6d0(FUN_1422cd070(pItem->FUN_140526b50()));
    if (pSlot != 0)
    {
        pSlot->SetStoreItemId(pItem->FUN_140526a50());
        pSlot->vfunc_10();
    }
}

// @0x14180b5e0
void StoreSlotBag::vfunc_10(void* p)
{
    CItem* pItem = static_cast<CItem*>(p);
    DragSlot* pSlot = FUN_1422cd070(pItem->FUN_140526b50());
    if (pSlot != 0)
        pSlot->vfunc_11();
}

// @0x14180b640
void StoreSlotBag::vfunc_il11(void* p)
{
    CItem* pItem = static_cast<CItem*>(p);
    StoreSlot* pSlot = FUN_14140e6d0(FUN_1422cd070(pItem->FUN_140526b50()));
    if (pSlot != 0)
    {
        pSlot->SetStoreItemId(pItem->FUN_140526a50());
        pSlot->vfunc_10();
    }
}

// @0x14180b6c0
void StoreSlotBag::vfunc_12()
{
    Unk_SsDialog* pDlg = FUN_140de48d0(0x4e47);
    if (pDlg != 0)
    {
        if (pDlg->vfunc_55() == 0)
            FUN_141b10eb0(pDlg);
    }
}

// @0x14180b710
DragSlot* StoreSlotBag::vfunc_16(int nIndex)
{
    CString strName = DragSlotBag::vfunc_15(nIndex);
    unsigned __int64 nId = FUN_14180b810(nIndex);
    StoreSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) StoreSlot(strName, nIndex, nId);
    return pSlot;
}

// @0x14180b7f0
int FUN_14180b7f0()
{
    return 1;
}

// @0x14180b810
unsigned __int64 FUN_14180b810(int nIndex)
{
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    MS2_STORE_TABLE.Append(items);
    for (unsigned i = 0; i < items.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = items[i];
        if (spItem.get() != 0)
        {
            if (spItem->FUN_140526b50() == nIndex)
                return spItem->FUN_140526a50();
        }
    }
    return 0;
}

// @0x14180b940
StoreSlotBag* FUN_14180b940(NotifyContext::BindData* p)
{
    StoreSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200032, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142cbb550-0x142cbb6d0 .text$yd
