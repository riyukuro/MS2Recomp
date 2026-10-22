// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). InvenSlot and InventorySlotBag: the item slots of the
// inventory window. See invenslot.h. Member and local names are invented from the use.
// The range holds two original TUs (two copies of the header statics in .text$di; InvenSlot's COMDATs sit before the
// InventorySlotBag code); both are written here, the second copy of the header statics by hand.
// MS2-UNIT: ?\invenslot.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1414043e0-0x14140ff10 .text$mn
// MS2-RANGE: 0x1400f5230-0x1400f5950 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__E?ms_ClassInfo@InvenSlot@@2VClassInfo@efd@@B@@YAXXZ 0x1400f5230 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VUIShopDialog@@@@QEBAPEAVUIShopDialog@@XZ 0x14140e920 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUIShopDialog@@@@QEBAPEAVUIShopDialog@@XZ 0x14140e940 ; unique
// MS2-PIN: ??_EInvenSlot@@WJA@EAAPEAXI@Z 0x14140e950 ; prop
// MS2-PIN: ?GetClassDesc@InvenSlot@@UEBAPEBVClassInfo@efd@@XZ 0x14140e9c0 ; prop
// MS2-PIN: ?IsEmpty@?$CAtlList@HV?$CElementTraits@H@ATL@@@ATL@@QEBA_NXZ 0x14140ea60 ; unique
// MS2-PIN: ?SetupClassInfo@InvenSlot@@SAXPEAVClassInfo@efd@@_K@Z 0x14140ea90 ; unique
// MS2-PIN: ??_EInventorySlotBag@@WJA@EAAPEAXI@Z 0x14140fcfc ; unique
// MS2-PIN: ?GetClassDesc@InventorySlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x14140fd70 ; unique
// MS2-PIN: ?TypeCast@InventorySlotBag@@UEBA_NIPEAPEAX@Z 0x14140fde0 ; unique
// MS2-PIN: ?TypeCast@InventorySlotBag@@UEBA_NIPEAPEBX@Z 0x14140fe30 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7InvenSlot@@6BBindData@NotifyContext@@@ 0x142f0eb08 ; hand: primary vftable
// MS2-PIN: ??_7InvenSlot@@6B@ 0x142f0ebf8 ; hand
// MS2-PIN: ?TypeCast@InvenSlot@@UEBA_NIPEAPEAX@Z 0x14140eaf0
// MS2-PIN: ?TypeCast@InvenSlot@@UEBA_NIPEAPEBX@Z 0x14140eb40
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\invenslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "invenslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/client/ms2/store.h"
#include "ms2/client/ms2/storeslot.h"
#include "ms2/client/ms2/equipslot.h"
#include "ms2/client/ms2/trademanagerex.h"
#include "ms2/client/ms2/gemslot.h"
#include "ms2/client/ms2/fittingdollslot.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/itembreakslot.h"
#include "ms2/client/ms2/itemlockslot.h"
#include "ms2/client/ms2/itemscrollslot.h"
#include "ms2/client/ms2/petslot.h"
#include "ms2/client/ms2/tabcontentspetinfo.h"
#include <NxPhysics.h>
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/client/ms2/uitradedialogex.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/commonfiles/itemexchangescrolltable.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/cequipmentslotlayerinfo.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/placeholder/uidialogeventdispatcher.h"
#include "ms2/client/ms2/uiplayinstrumentdialog.h"
#include "ms2/client/ms2/uiitemmergerevertdialog.h"
#include "ms2/client/ms2/uiitemextractionscrolldialog.h"
#include "ms2/client/ms2/uiblackmarketdialog.h"
#include "hook/ms2hook.h"
#include <utility>
#include <efd/IBase.h>
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_ItemEquipData : public CItemData { };          // CItem::FUN_140527840's record
class Unk_ItemOwnerRef : public CItemTransfer { };       // CItem::FUN_140527930 (the binding holder)

extern Unk_Inventory DAT_143ab2a90;                       // the player's inventory
extern __int64 DAT_143ab2828;                             // the own character id
extern __int64 DAT_143af25f0;                             // the fitting doll object id

class Unk_IsNetObject;
class Unk_IsWorld
{
public:
    MyPC* FUN_141bd0cc0();                                // the local player
    Unk_IsNetObject* FUN_141bd1530(__int64 nId);          // a field object by id
};
Unk_IsWorld* FUN_1403ed2d0();
CEffectService* FUN_1403ed280();                          // the sound service
CUIService* FUN_1403ed2b0();                              // the UI service
FittingDollPC* FUN_140884db0(Unk_IsNetObject* pObject);   // the object as a fitting doll (class 0x6200046)
void FUN_14121b840(int nResult);                          // the notice of a doll item result (fittingdollslot#1)
int FUN_141420a70(CItem* pItem, FittingDollPC* pDoll);   // the equip slot the item goes to on the avatar

// The skill book of the local player (JobSystemCli, FUN_1416546d0) and the skill table.
class Unk_IsSkillBook
{
public:
    virtual void vfunc_0();
    virtual MS2Ptr<SkillLevelData> vfunc_1(unsigned nSkillId);    // 1 the learned level of a skill
};
Unk_IsSkillBook* FUN_1416546d0(MyPC* pPc);
MS2Ptr<SkillData> FUN_140639210(unsigned nSkillId);      // JobSystem::GetSkillData

// The inventory window (UI class 0x4e2d).
class UIInventoryDialog : public UIDialog
{
public:
    CStringW FUN_14199abe0();                             // the search text
    static eUIClassID GetUIClassID() { return (eUIClassID)0x4e2d; }   // 0x14140ea50 (COMDAT)
    void FUN_14199bc00();                                 // refresh
    bool FUN_14199b4e0(int nResult, const CMsgBoxData& box);   // the destroy box answer
};
UIInventoryDialog* FUN_1405344f0(int nId);
void FUN_140c3fe30(UIInventoryDialog* pDialog, int n);

// The quest event dispatcher (FUN_140bfc4b0) the slot registers with.
class Unk_IsQuestEvents
{
public:
    void FUN_141aa87c0(UIQuestEventListener*);
    void FUN_141aa8850(UIQuestEventListener*);
};
Unk_IsQuestEvents* FUN_140bfc4b0();
// The item / UGC event hubs the bag registers with.
struct Unk_IsItemEvents;
Unk_IsItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_IsItemEvents*, UIItemEventListener*);
void FUN_1419caeb0(Unk_IsItemEvents*, UIItemEventListener*);
class Unk_IsUgcEvents
{
public:
    void FUN_141b38be0(UIUGCEventListener*);
    void FUN_141b38c70(UIUGCEventListener*);
};
Unk_IsUgcEvents* FUN_140bc09f0();

// The store table as the exe binds it (only functional in store.cpp, so called by address).
class Unk_IsStoreView
{
public:
    MS2Ptr<CItem> FUN_140de1490(__int64 nId);             // CStore::Find
    int FUN_140de21a0(MS2Ptr<CItem> spItem, int nCount);  // CStore::AvailableSlot
    int FUN_140de2490(int nType);                         // CStore::Allowed
};
#define IS_STORE_VIEW (*reinterpret_cast<Unk_IsStoreView*>(&DAT_143ab2d80))

// The item break manager (FUN_1409c4b20).
class Unk_IsBreakMgr
{
public:
    int FUN_140531270(MS2Ptr<CItem> spItem);              // the item can be broken
    int FUN_140532ab0();                                  // the break window is open
    int FUN_140532de0(MS2Ptr<CItem> spItem, int nSlot);   // add the item
    int FUN_140533340(MS2Ptr<CItem> spItem);              // replace the item
};
Unk_IsBreakMgr* FUN_1409c4b20();

// The item lock manager (FUN_140535310).
class Unk_IsLockMgr
{
public:
    int FUN_140612d60();                                  // the lock window is open
    int FUN_140612e90(MS2Ptr<CItem> spItem);              // put the item into a lock slot
    int FUN_1406130e0(__int64 nItemUid);
    int FUN_140613160(CItem* pItem);                      // the item may be used (not locked)
};
Unk_IsLockMgr* FUN_140535310();
CPetManager* FUN_140535320();

// The feature switches (FUN_140166410).
class Unk_IsFeatures
{
public:
    bool FUN_14036d570(int nFeature);
};
Unk_IsFeatures* FUN_140166410();

// The key state.
class Unk_IsKeys
{
public:
    bool FUN_14116d950(int nKey, bool b, int c);
    bool FUN_14116dcb0(int nAction, int a, int b);        // an action key is bound
};
Unk_IsKeys* FUN_14025e7c0();

// The key bindings (FUN_1409331f0).
class Unk_IsKeyMap
{
public:
    CStringW FUN_14142d760(int nAction, int n);           // the key text of an action
    int FUN_140a700b0();
};
Unk_IsKeyMap* FUN_1409331f0();

// The gamepad HUD.
class Unk_IsPadHud
{
public:
    void FUN_1422cee50(int n);
};
class Unk_IsPadHudPtr
{
public:
    ~Unk_IsPadHudPtr();                                   // 0x140a58400
    void* FUN_140a58470() const;                          // non-null test
    Unk_IsPadHud* FUN_140a584a0() const;                  // operator->
    void* m_p0;
    void* m_p8;
};
class Unk_IsUiScale
{
public:
    Unk_IsPadHudPtr FUN_1422b0370(int nDialogId);
};
Unk_IsUiScale* FUN_14025e7a0();

// The names of the inventory tabs / item kinds.
class Unk_IsTabNames
{
public:
    CStringW FUN_141813300(int nTab);
    CStringW FUN_141811980(int nKind, int nId);
};
Unk_IsTabNames* FUN_1401a9d70();

// The item rules (quest items, ...).
class Unk_IsItemRules
{
public:
    int FUN_1416ce170(MS2Ptr<CItem> spItem);              // 0: normal, 1: quest item, 2: hidden
    void FUN_1416ce860(MS2Ptr<CItem> spItem, ATL::CAtlArray<int>& quests);
};
Unk_IsItemRules* FUN_140764020();
CStringW FUN_1416e5210(int nQuestId, CStringW strFormat);

// Strings and notices.
CStringW GetStringCommonByKey(const CStringW& strKey);           // string table text by key
CStringW GetStringCommon(int nStringId);                    // string table text by id
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_140298ea0(CStringW strKey);
void FUN_141275260(int nStringId, int nA, int nB);        // notice by string id
void FUN_1412751f0(const CStringW& strText, int nA, int nB);
void FUN_140961010(int nId, int nA, int nB, const CStringW& rArg);
void FUN_141276180(const CString& strA, const CString& strB);
void FUN_140d73bc0(int nId, int nType, void* p, CStringW strTag);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nId, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spData);
unsigned FUN_1412773a0(unsigned nMax);
CString FUN_140719530(unsigned __int64 v);                // "%I64u"
CString FUN_140719210(long v);                            // "%ld"
void FUN_140165270(ATL::CAtlArray<CString>* pArr, const CString& str);   // append a string to the slot's data array
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);       // the value is an object
void FUN_140614800(Scaleform::GFx::Value v);
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);                 // item link / popup for the item
CStringW FUN_1413fa9b0(const CStringW& str);
bool FUN_14025cd60(const CStringW& a, const CStringW& b);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
void FUN_140710590(COutPacket& packet);                   // send the packet

// The GFx value wrapper used for the cooldown calls (AScript-like, 0x48 bytes).
class Unk_IsScript
{
public:
    Unk_IsScript(const Scaleform::GFx::Value& v, int nMovie);   // 0x1422ba780
    ~Unk_IsScript();
    Scaleform::GFx::Value FUN_140e5bf20(const char* szMethod, float a1, float a2);
    Scaleform::GFx::Value FUN_1422bb330(const char* szMethod);
    Scaleform::GFx::Value FUN_140bfe360(const char* szMethod, bool b);
private:
    void* m_pad[9];
};
MS2_CHECK_SIZE(Unk_IsScript, 0x48);

// Slots of other units.
InvenSlot* FUN_140a50b50(DragSlot* pSlot);                // the inventory slot behind a drag source
EquipSlot* FUN_14120d560(NotifyContext::BindData* p);
PetSlot* FUN_140dbc0d0(DragSlot* p);
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

// The use-item paths (vfunc_13).
int FUN_141659690(MyPC* pPC);                             // the player is in the cube craft mode
class Unk_PCCubeCraft
{
public:
    void FUN_1410aad50();                                 // confirm: build / move / rotate
};
class UIUGCItemEditDialog : public UIDialog
{
public:
    void SetEditItem(MS2Ptr<CItem> spItem);             // put the UGC item into the editor
};
UIUGCItemEditDialog* FUN_140eeff60(int nId);
class Unk_IsInstrumentMgr
{
public:
    bool FUN_140d09d90(int nMode);                        // a pre-listening is running
    __int64 FUN_140c8dab0();                              // the uid of the score being played
};
Unk_IsInstrumentMgr* FUN_140c8dac0();                     // TSingleton<CInstrumentManager>::GetInstance
class Unk_IsInstrumentDialog
{
public:
    void FUN_140fef7b0(MS2Ptr<CItem> spItem);             // play the instrument
    void FUN_140fef8f0(MS2Ptr<CItem> spItem);             // play the score
};
Unk_IsInstrumentDialog* FUN_140d0c0e0(int nId);
class Unk_IsAccountFlagSet
{
public:
    int FUN_1402c4c90(int nFlag);
};
struct Unk_IsAccountFlags
{
    void* m_0;
    Unk_IsAccountFlagSet m_flags;                         // +0x08
};
Unk_IsAccountFlags* FUN_14025e7b0();
CBlockManager* FUN_140a6a830();
void FUN_140a30ad0(const BlockPtr& rec, int action, unsigned __int64 cb);   // the blocked-action notice
void FUN_140a2ff20(const BlockPtr& rec, int action, unsigned __int64 cb);   // the blocked-action notice (drop)

// Helpers defined further down in this unit.
static int FUN_14140dea0(CItem* pItem, MyPC* pPC);

// The right click paths (vfunc_14).
class Unk_IsJobSkills
{
public:
    MS2Ptr<SkillData> FUN_1407ee1d0(int nSkillId);        // the skill record
};
Unk_IsJobSkills* FUN_1401958b0();
int FUN_141769320(MS2Ptr<CItemData> spData);              // the skill of an emotion / skill book item
void FUN_14092fac0(int nSkillId, int nItemId, __int64 nItemUid, int nPage);   // register a shortcut
void* FUN_140938c30(int nId);                             // the profile dialog (0x2711)
bool FUN_141271960(MS2Ptr<CItem> spItem, int nSlot, int nFlag);   // put the gem item on (packet 0x47)
void FUN_140c887b0(MS2Ptr<CItem> spItem, int nSlot);      // put the item into the pet inventory (count box when stacked)
UIPlayInstrumentDialog* FUN_140d0c040(int nId);
UIItemMergeRevertDialog* FUN_140d274e0(int nId);
UIItemExtractionScrollDialog* FUN_140d27300(int nId);
UIBlackMarketDialog* FUN_140a22f10(int nId);
static int FUN_14140d3e0(MS2Ptr<CItem> spItem, int bHint);
static void FUN_14140c4d0(__int64 nUid, int nItemId, int nCount, int nMax);

// The drop paths (vfunc_18).
class Unk_IsInventoryView
{
public:
    int FUN_140a65b70();                                  // the open tab of the inventory window (-1: closed)
};
#define IS_INVENTORY_VIEW (*reinterpret_cast<Unk_IsInventoryView*>(&DAT_143ab2a90))
bool FUN_141271f90(MS2Ptr<CItem> spItem);                 // take the gem item off (packet 0x47)
void FUN_140c88c30(MS2Ptr<CItem> spItem, int nSlot);      // take the item out of the pet inventory
bool FUN_140633fb0(MS2Ptr<CItem> spItem, int* pReason);   // may the item go to the black market

// The destroy paths (vfunc_26).
int FUN_14138c900(void* pBuffs, int nKind);               // a buff of the kind is on
void* FUN_1409331e0();                                    // the player's buff table
__int64 FUN_1410947c0(void* pObject);                     // the item uid of a ride
bool FUN_140633700(MS2Ptr<CItem> spItem);                 // the item is destroyed without a box
void FUN_1409e4950(MS2Ptr<CItem> spItem, CStringW& strOut, bool* pHas);   // the warning prefix of the item
CPhysXHelper* FUN_1409f7ca0();                            // the physics scene
extern Unk_StreamPoint DAT_143a08cf8;                     // NiPoint3::UNIT_Z
static CStringW FUN_14140c2b0(MS2Ptr<CItem> spItem);

// The tooltip paths (vfunc_0).
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);   // str == sz
CItemExchangeScrollTable* FUN_140f56960();
class Unk_IsEquipView : public MyPC
{
public:
    MS2Ptr<CEquipItem> FUN_141655e10(int nSlot);          // the worn item of a slot
    int FUN_141658f30();                                  // the account is premium (PC room)
    int FUN_141662de0();                                  // the VIP state
};

// The trade / sell paths.
bool FUN_140633e40(MS2Ptr<CItem> spItem, int* pReason);   // may the item be traded
void FUN_141425fc0(__int64 nUid, unsigned int nCount, CItem* pItem);   // sell the item to the npc shop
static void FUN_14140d200(__int64 nUid, int nCount, int nMax);
static void FUN_14140cb90(__int64 nUid, int nItemId, int nCount, int nMax, int nPrice, CStringW strName);
class Unk_IsDropper
{
public:
    void FUN_141538930(__int64 nUid, int nCount);         // drop the item (packet)
};
Unk_IsDropper* FUN_140714f90();
void FUN_1419f8920(MS2Ptr<CItem> spItem, int nCount);     // sell without a box
static int FUN_14140d350(CItem* pItem);

// The right click mode (FUN_14140d3e0).
extern ATL::CAtlList<int> DAT_143af2258;                  // the ids of the open dialogs, the latest first
bool FUN_140633a20(MS2Ptr<CItem> spItem);                 // may be traded
bool FUN_140633840(MS2Ptr<CItem> spItem);                 // may be sold
bool FUN_140633b80(MS2Ptr<CItem> spItem);                 // may be registered on the black market
int FUN_141a5c7a0(void* pDialog);                         // the profile dialog shows the own character

// The put-on checks (FUN_14140dea0) and the shop (FUN_14140e3f0).
class Unk_IsItemRequire : public CItem
{
public:
    int FUN_140526810(int nLevel);                        // the level is enough
    int FUN_140526790(int nJob);                          // the job may wear it
    int FUN_1405267d0(int nGender);                       // the gender may wear it
};
bool FUN_1406343b0(MS2Ptr<CItem> spItem, const __int64* pCharacterId);   // the binding allows the character
class UIShopDialog : public UIDialog
{
public:
    bool FUN_141afb780(MS2Ptr<CItem> spItem);             // the shop buys the item
};
UIShopDialog* FUN_140534780(int nId);
static int FUN_14140e3f0(MS2Ptr<CItem> spItem);
static __int64 FUN_14140fa00(int nIndex, int nTab);

// The open dialogs of a UI class (COMDATs 0x14140e770 / 0x14140e820).
template <class T> inline T* Unk_InvGetDialog()
{
    CUIService* pService = FUN_1403ed2b0();
    if (pService == 0)
        return 0;
    MS2Ptr<UIObject> obj = pService->FUN_141adcea0(T::GetUIClassID());
    if (!obj)
        return 0;
    return dynamic_cast<T*>(obj.operator->());
}
template <class T> inline T* Unk_InvGetDialogById(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> obj = FUN_1403ed2b0()->FUN_141adcea0((eUIClassID)nId);
        if (obj.get())
            return dynamic_cast<T*>(obj.operator->());
    }
    return 0;
}

// @0x14140ea30 (COMDAT)
inline CTradeManagerEx* TSingleton<CTradeManagerEx>::GetInstance()
{
    return s_instance;
}

EE_IMPLEMENT_CONCRETE_CLASS_INFO(InvenSlot);

static CString s_strOnCooldownEnd = "onCooldownEnd";
static CString s_strOnCooldownStart = "onCooldownStart";
static CString s_strUpdateIconSearchOn = "updateIconSearchOn";
static CStringW s_strDestroyItem = L"destroy_item";
static CStringW s_strDrop = L"drop";
static CStringW s_strLearnEmotion = L"learn_emotion";
static CStringW s_strSell = L"sell";
static CStringW s_strSwapStoreIn = L"swapstorein-";
static CStringW s_strSwapStoreOut = L"swapstoreout-";
static CStringW s_strTradeIn = L"tradein";
static CStringW s_strUseStoreIn = L"usestorein";
static CStringW s_strUseStoreOut = L"usestoreout";
static CString s_strPremiumSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
static CString s_strSystemNoticeErrorWarningBag = "system_notice_error_warningBag";
static CString s_strChangeDagger = "Change_Dagger";

EE_IMPLEMENT_CONCRETE_CLASS_INFO(InventorySlotBag);

// The second copy of the header statics (the InventorySlotBag TU).
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

static int FUN_141404c70(unsigned __int64 nKey);

// ---- free helpers ----

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x1414043e0
// Ask for the count to move into the storage (bTake == 0) or out of it.
void FUN_1414043e0(__int64 nUid, int nCount, int nMax, int bTake, int nSlot)
{
    int nId;
    const CStringW* pTag;
    if (bTake == 0)
    {
        nId = 0x2ab;
        pTag = &s_strUseStoreIn;
    }
    else
    {
        nId = 0x2ac;
        pTag = &s_strUseStoreOut;
    }
    CStringW strTag = *pTag;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(5, nId, 0, strTag);
    if (spBox.get() != 0)
    {
        CStringW strCount;
        strCount.Format(L"%d", nCount);
        spBox->FUN_141a01620(nSlot);
        spBox->FUN_141a01600(nUid);
        spBox->FUN_141a01d30(1, strCount, FUN_1412773a0(nMax), 0, 0);
        FUN_140d73c60(spBox);
    }
}
MS2_REPLACE(0x1414043E0, FUN_1414043e0, 478, 0x65FB6048);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x1414045d0
// The same for the swap storage.
void FUN_1414045d0(__int64 nUid, int nCount, int nMax, int bTake, int nSlot)
{
    int nId;
    const CStringW* pTag;
    if (bTake == 0)
    {
        nId = 0x2ab;
        pTag = &s_strSwapStoreIn;
    }
    else
    {
        nId = 0x2ac;
        pTag = &s_strSwapStoreOut;
    }
    CStringW strTag = *pTag;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(5, nId, 0, strTag);
    if (spBox.get() != 0)
    {
        CStringW strCount;
        strCount.Format(L"%d", nCount);
        spBox->FUN_141a01620(nSlot);
        spBox->FUN_141a01600(nUid);
        spBox->FUN_141a01d30(1, strCount, FUN_1412773a0(nMax), 0, 0);
        FUN_140d73c60(spBox);
    }
}
MS2_REPLACE(0x1414045D0, FUN_1414045d0, 478, 0xED9C79B9);

// @0x1414047c0
// Play the item sound of an item record.
void FUN_1414047c0(MS2Ptr<CItemData> spData)
{
    if (spData.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), spData->FUN_14053eca0(), CString(""), 0, 0,
            1.0f, 0);
}
MS2_REPLACE(0x1414047C0, FUN_1414047c0, 288, 0x8BC70F5B);

// @0x1414048f0
void FUN_1414048f0(int nItemId)
{
    FUN_1414047c0(FUN_14053f870(nItemId));
}
MS2_REPLACE(0x1414048F0, FUN_1414048f0, 52, 0xB9C08CBF);

// @0x141404930
void FUN_141404930(__int64 nUid)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
    if (spItem.get() != 0)
        FUN_1414047c0(MS2Ptr<CItemData>(spItem->FUN_140527840()));
}
MS2_REPLACE(0x141404930, FUN_141404930, 128, 0xBA442799);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x1414049c0
// Append the cooldown key (group, skill) of a skill that shows its cooldown.
void FUN_1414049c0(ATL::CAtlArray<CString>* pArr, int nSkillId)
{
    if (nSkillId == 0)
        return;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    FUN_1416546d0(pPc);
    MS2Ptr<SkillData> spSkill(std::move(FUN_140639210(nSkillId)));
    if (!spSkill)
        return;
    MS2Ptr<SkillLevelData> spLevel(0);
    if (pPc->FUN_1416764d0() == 0)
        spLevel = FUN_1416546d0(pPc)->vfunc_1(nSkillId);
    else
        spLevel = spSkill->FUN_1407e90a0(1);
    if (!spLevel)
        return;
    if (spSkill->m_condition.m_nUseCoolDownShowUI != 0)
    {
        FUN_140165270(pArr, FUN_140719210(spSkill->m_nCooldownGroupID));
        FUN_140165270(pArr, FUN_140719210(nSkillId));
    }
}
MS2_REPLACE(0x1414049C0, FUN_1414049c0, 670, 0x0CFBAC74);

// @0x141404c70
static int FUN_141404c70(unsigned __int64 nKey)
{
    return (int)(nKey >> 32);
}
MS2_REPLACE(0x141404C70, FUN_141404c70, 15, 0x5CE537A7);

// @0x141404c90
// The cooldown left of a skill of the local player.
float FUN_141404c90(int nSkillId)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    return pPc->FUN_141523bc0()->FUN_141765fe0(nSkillId, 1);
}
MS2_REPLACE(0x141404C90, FUN_141404c90, 72, 0x788CDE18);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x141404ce0
// A cooldown started: start the slot's cooldown animation when the key is the skill's.
bool FUN_141404ce0(int nSkillId, unsigned __int64 nKey, Scaleform::GFx::Value* pValue)
{
    if (nSkillId == 0)
        return false;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    FUN_1416546d0(pPc);
    MS2Ptr<SkillData> spSkill(std::move(FUN_140639210(nSkillId)));
    if (!spSkill)
        return false;
    MS2Ptr<SkillLevelData> spLevel(0);
    if (pPc->FUN_1416764d0() == 0)
        spLevel = FUN_1416546d0(pPc)->vfunc_1(nSkillId);
    else
        spLevel = spSkill->FUN_1407e90a0(1);
    if (!spLevel)
        return false;
    if (spSkill->m_condition.m_nUseCoolDownShowUI == 0)
        return false;
    int nGroup = FUN_141404c70(nKey);
    if (nGroup == 0 || nGroup != (int)spSkill->GetCooldownGroupId())
    {
        if (nKey == 0 || nKey != spSkill->GetCooldownKey())
            return false;
    }
    if (FUN_1409b4d40(*pValue))
    {
        float fRemain = 0;
        float fTotal = 0;
        int nByItem = 0;
        pPc->FUN_141523bc0()->FUN_141766230(nSkillId, &fRemain, &fTotal, &nByItem, 1);
        if (0.0f < fRemain)
        {
            Unk_IsScript script(*pValue, 2);
            float fCool;
            if (nByItem == 0)
                fCool = spLevel->FUN_140804660();
            else
                fCool = fTotal;
            FUN_140614800(script.FUN_140e5bf20(s_strOnCooldownStart, fRemain, fCool));
            return true;
        }
    }
    return false;
}
MS2_REPLACE(0x141404CE0, FUN_141404ce0, 982, 0x8E91ECC5);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x1414050c0
// A cooldown ended: stop the slot's cooldown animation.
bool FUN_1414050c0(int nSkillId, unsigned __int64 nKey, Scaleform::GFx::Value* pValue)
{
    if (nSkillId == 0)
        return false;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    FUN_1416546d0(pPc);
    MS2Ptr<SkillData> spSkill(std::move(FUN_140639210(nSkillId)));
    if (!spSkill)
        return false;
    MS2Ptr<SkillLevelData> spLevel(0);
    if (pPc->FUN_1416764d0() == 0)
        spLevel = FUN_1416546d0(pPc)->vfunc_1(nSkillId);
    else
        spLevel = spSkill->FUN_1407e90a0(1);
    if (!spLevel)
        return false;
    if (FUN_140166410()->FUN_14036d570(0xca) == false && spSkill->m_condition.m_nUseCoolDownShowUI == 0)
        return false;
    int nGroup = FUN_141404c70(nKey);
    if (nGroup == 0 || nGroup != (int)spSkill->GetCooldownGroupId())
    {
        if (nKey == 0 || nKey != spSkill->GetCooldownKey())
            return false;
    }
    if (FUN_1409b4d40(*pValue))
    {
        float fRemain = pPc->FUN_141523bc0()->FUN_141765fe0(nSkillId, 1);
        if (fRemain <= 0.0f)
        {
            Unk_IsScript script(*pValue, 2);
            FUN_140614800(script.FUN_1422bb330(s_strOnCooldownEnd));
            return true;
        }
    }
    return false;
}
MS2_REPLACE(0x1414050C0, FUN_1414050c0, 880, 0x0E177859);

// @0x141405440
// Ask whether to destroy the item (the inventory window answers the box).
void FUN_141405440(MS2Ptr<CItem> spItem)
{
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(10, 0xcd2, 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        UIInventoryDialog* pDlg = FUN_1405344f0(0x4e2d);
        if (pDlg != 0 && pDlg->FUN_141924630() != 0)
        {
            CStringW strDefault(L"");
            spBox->FUN_1405340b0(spItem->FUN_140526a50());
            spBox->FUN_140b76940(spItem->FUN_140528010());
            spBox->FUN_141a01d30(2, strDefault, 0xc, 0, 0);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(pDlg, &UIInventoryDialog::FUN_14199b4e0));
            FUN_140d73c60(spBox);
        }
    }
}
MS2_REPLACE(0x141405440, FUN_141405440, 610, 0xC0834321);

// @0x1414056b0
// How the item is put on by right click: 0 not equipment, 1 the normal tab, 2 the codi tab.
int FUN_1414056b0(MS2Ptr<CItem> spItem)
{
    int nResult = 0;
    if (spItem->FUN_1405258b0() != 0)
    {
        if (FUN_140166410()->FUN_14036d570(0x8e))
        {
            if (FUN_14025e7c0()->FUN_14116dcb0(0x4940d, 0, 0))
                nResult = 1;
            else
                nResult = 2;
        }
        else
        {
            nResult = 1;
        }
    }
    return nResult;
}
MS2_REPLACE(0x1414056B0, FUN_1414056b0, 159, 0xE760F091);

// ---- InvenSlot ----

// @0x141405760
InvenSlot::InvenSlot(const CString& strName, int nIndex, __int64 nItemUid)
    : MS2DragSlot(strName, nIndex)
{
    m_nItemUid = nItemUid;
    SetEnabled(true);
    FUN_140bfc4b0()->FUN_141aa87c0(this);
}

// @0x141405840
InvenSlot::~InvenSlot()
{
    FUN_140bfc4b0()->FUN_141aa8850(this);
}

// @0x1414058f0
int InvenSlot::FUN_1414058f0()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(GetItemUid());
    if (spItem.get() != 0)
        return spItem->FUN_140527840()->FUN_14053dc20();
    return 0;
}
MS2_REPLACE_METHOD(0x1414058F0, InvenSlot, FUN_1414058f0, 137, 0x89645CA2);

// @0x141405980
int InvenSlot::FUN_141405980()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(GetItemUid());
    if (spItem.get() != 0)
        return spItem->FUN_1405276c0();
    return 0;
}
MS2_REPLACE_METHOD(0x141405980, InvenSlot, FUN_141405980, 129, 0x5B13475B);

// @0x141405a10
__int64 InvenSlot::GetItemUid()
{
    return m_nItemUid;
}
MS2_REPLACE_METHOD(0x141405A10, InvenSlot, GetItemUid, 18, 0xB95413A9);

// @0x141405a30
void InvenSlot::SetItemUid(__int64 nItemUid)
{
    m_nItemUid = nItemUid;
}
MS2_REPLACE_METHOD(0x141405A30, InvenSlot, SetItemUid, 28, 0x932389C7);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x141405a60
bool InvenSlot::FUN_141405a60(CItem* pItem, int nSlot)
{
    bool bResult;
    if (pItem == 0)
    {
        bResult = false;
    }
    else if (pItem->FUN_140527840()->FUN_14053cbc0() == false)
    {
        bResult = false;
    }
    else if (pItem->FUN_140528930())
    {
        bResult = false;
    }
    else if (pItem->FUN_140526c30() == 0)
    {
        bResult = false;
    }
    else
    {
        FittingDollPC* pDoll = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(DAT_143af25f0));
        if (pDoll == 0)
        {
            bResult = false;
        }
        else
        {
            if (nSlot != 0 && pItem->FUN_140527840()->FUN_14053eba0()->FUN_14054b450(nSlot) == false)
            {
                FUN_14121b840(0x10);
                return false;
            }
            int nPos = nSlot;
            if (nSlot == 0)
                nPos = FUN_141420a70(pItem, pDoll);
            unsigned char nType = (unsigned char)nPos;
            if (pItem->FUN_140527840()->FUN_14053d460())
                nType = 5;
            else if (pItem->FUN_140527840()->FUN_14053d2b0())
                nType = 8;
            int nError = pDoll->FUN_14121c910(pItem);
            if (nError == 0)
            {
                COutPacket packet(0x42, 0);
                packet.vfunc_o10_1(2);
                packet.vfunc_o10_4((__int64)pDoll->FUN_14121c6c0());
                packet.vfunc_o10_4(pItem->FUN_140526a50());
                packet.vfunc_o10_1(nType);
                FUN_140710590(packet);
            }
            else
            {
                FUN_14121b840(nError);
            }
            bResult = nError == 0;
        }
    }
    return bResult;
}
MS2_REPLACE_METHOD(0x141405A60, InvenSlot, FUN_141405a60, 573, 0xE7C18AAB);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x141405cb0
void InvenSlot::vfunc_6(void* p)
{
    ATL::CAtlArray<CString>* pArr = static_cast<ATL::CAtlArray<CString>*>(p);
    FUN_140165270(pArr, FUN_140719530(m_nItemUid));
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem == 0)
        return;
    int nItemId = spItem->FUN_1405276c0();
    if (spItem->FUN_140527840()->FUN_14053c5c0() == 2 || spItem->FUN_140527840()->FUN_14053c5c0() == 0x18)
        FUN_140165270(pArr, FUN_140719210(nItemId));
    FUN_1414049c0(pArr, spItem->FUN_140527840()->FUN_14053dc20());
}
MS2_REPLACE_METHOD(0x141405CB0, InvenSlot, vfunc_6, 360, 0xF25982D8);

// @0x141405e20
void InvenSlot::vfunc_o178_2(void* p)
{
    FUN_14140c100();
}
MS2_REPLACE_METHOD_VIA(0x141405E20, InvenSlot, UIQuestEventListener, vfunc_o178_2, 38, 0xAAB65F18);

// @0x141405e50
void InvenSlot::vfunc_o178_1(void* p)
{
    FUN_14140c100();
}
MS2_REPLACE_METHOD_VIA(0x141405E50, InvenSlot, UIQuestEventListener, vfunc_o178_1, 38, 0x0C295B48);

// @0x141405e80
void InvenSlot::vfunc_o178_5(void* p)
{
    FUN_14140c100();
}
MS2_REPLACE_METHOD_VIA(0x141405E80, InvenSlot, UIQuestEventListener, vfunc_o178_5, 38, 0xDC8E7F78);

// @0x141405eb0
int InvenSlot::vfunc_11()
{
    if (FUN_1409b4d40(m_value18))
        m_value18.Invoke((const char*)s_strOnCooldownEnd, 0);
    m_nItemUid = 0;
    return DragSlot::vfunc_11();
}
MS2_REPLACE_METHOD(0x141405EB0, InvenSlot, vfunc_11, 97, 0x8C911851);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x141405f20
int InvenSlot::vfunc_13()
{
    int nResult;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
    {
        nResult = 0;
    }
    else
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(GetItemUid());
        if (!(spItem == 0))
        {
            if (FUN_141659690(pPC) == 0)
            {
                if (spItem->FUN_140525f10() == 1 && spItem->FUN_140525f60() == 0)
                {
                    if (spItem->FUN_140525fc0() == 0)
                    {
                        MS2Ptr<UIUGCItemEditDialog> spEdit(FUN_140eeff60(0x4e69));
                        if (spEdit)
                        {
                            UIUGCItemEditDialog* pEdit = spEdit.get();
                            if (pEdit->vfunc_55() == 1)
                            {
                                spEdit.get()->SetEditItem(spItem);
                                FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4e69);
                            }
                        }
                    }
                    else
                    {
                        FUN_141405440(spItem);
                    }
                    return 1;
                }
                if (spItem->FUN_140525680() == false)
                {
                    if (spItem->FUN_140527840()->FUN_14053cd90() == true)
                    {
                        if (DAT_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
                            return 0;
                        if (FUN_14140dea0(spItem.get(), pPC) != 0)
                            return FUN_140d1c3a0(spItem);
                    }
                    else
                    {
                        if (spItem->FUN_140527840()->FUN_14053ddb0() != 0)
                        {
                            if (FUN_14140dea0(spItem.get(), pPC) == 0)
                                return 0;
                            if (FUN_1403ed2b0()->FUN_141adc7f0((eUIClassID)0x4e3b) == 0)
                                return 0;
                            FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4e3b);
                            COutPacket packet(0x65, 0);
                            packet.vfunc_o10_1(10);
                            packet.vfunc_o10_1(1);
                            packet.vfunc_o10_3(spItem->FUN_1405276c0());
                            FUN_140710590(packet);
                            return 1;
                        }
                        if (spItem->FUN_140525640() == 0)
                        {
                            if (spItem->FUN_140527840()->FUN_14053ce40() == false)
                            {
                                if (spItem->FUN_140527840()->FUN_14053cbc0() == false)
                                {
                                    if (spItem->FUN_140527840()->FUN_14053c8b0())
                                    {
                                        if (FUN_14140dea0(spItem.get(), pPC) != 0)
                                            DAT_143ab2a90.FUN_140a635f0(spItem.get());
                                    }
                                }
                                else if (FUN_1403ed2b0()->FUN_141adc940((eUIClassID)0x4e3b) == 0)
                                {
                                    int nSlot = FUN_1414056b0(spItem);
                                    DAT_143ab2a90.FUN_140a621c0(GetItemUid(), 0, nSlot);
                                }
                            }
                            else if (FUN_14140dea0(spItem.get(), pPC) != 0)
                            {
                                int nSkillId = spItem->FUN_140527840()->FUN_14053dc20();
                                CStringW strText = FUN_14052bd00(0x85a, FUN_1401a9d70()->FUN_141811980(4, nSkillId));
                                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strText, 0, s_strLearnEmotion);
                                if (spBox.get() != 0)
                                {
                                    spBox->FUN_141a01600(m_nItemUid);
                                    FUN_140d73c60(spBox);
                                }
                            }
                        }
                        else
                        {
                            pPC->FUN_14152aa90(spItem, 0);
                        }
                    }
                }
                else
                {
                    if (FUN_140166410()->FUN_14036d570(10) == false)
                        return 0;
                    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(5) != 0)
                    {
                        FUN_141275260(0x2f7, 1, 1);
                        return 0;
                    }
                    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4eec) != 0)
                    {
                        CStringW strKey(L"s_play_instrument_cant_while_play_instrument");
                        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
                        return 0;
                    }
                    if (FUN_140c8dac0()->FUN_140d09d90(1))
                    {
                        CStringW strKey(L"s_play_instrument_cant_while_pre_listening");
                        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
                        return 0;
                    }
                    BlockPtr spBlocked = FUN_140a6a830()->FindBlockedAction(0x10);
                    if (spBlocked.get() != 0)
                    {
                        FUN_140a30ad0(spBlocked, 0x10, 0);
                        return 0;
                    }
                    if (spItem->FUN_140525730() == false)
                    {
                        Unk_IsInstrumentDialog* pDialog;
                        if (spItem->FUN_140525790() && (pDialog = FUN_140d0c0e0(0x4eed)) != 0)
                            pDialog->FUN_140fef8f0(spItem);
                    }
                    else
                    {
                        FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4eed);
                        Unk_IsInstrumentDialog* pDialog = FUN_140d0c0e0(0x4eed);
                        if (pDialog != 0)
                            pDialog->FUN_140fef7b0(spItem);
                    }
                }
                nResult = 1;
            }
            else
            {
                Unk_PCCubeCraft* pCraft = pPC->FUN_141530290();
                if (pCraft != 0)
                    pCraft->FUN_1410aad50();
                nResult = 1;
            }
        }
        else
        {
            nResult = 0;
        }
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x141405F20, InvenSlot, vfunc_13, 2856, 0x77317826);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x141406a60
int InvenSlot::vfunc_14()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(GetItemUid());
    if (!spItem)
        return 0;
    UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
    if (pInventory != 0)
    {
        spItem->FUN_1405268d0(0);
        pInventory->FUN_14199bc00();
    }
    switch (FUN_14140d3e0(spItem, 0))
    {
    case 1:
        return FUN_14140b6d0(spItem);
    case 2:
        if (FUN_14140be60(spItem) != 0)
        {
            Unk_IsPadHudPtr spHud = FUN_14025e7a0()->FUN_1422b0370(6);
            if (spHud.FUN_140a58470() != 0)
                spHud.FUN_140a584a0()->FUN_1422cee50(0);
        }
        break;
    case 3:
    {
        bool bAll;
        if (FUN_14025e7c0()->FUN_14116d950(0x2a, false, 0) || FUN_14025e7c0()->FUN_14116d950(0x36, false, 0))
            bAll = true;
        else
            bAll = false;
        int nCount = bAll ? spItem->FUN_140526c50() : 1;
        int nSlot = IS_STORE_VIEW.FUN_140de21a0(spItem, nCount);
        if (nSlot == -1)
        {
            FUN_141275260(0xf2, 1, 1);
            return 0;
        }
        if (IS_STORE_VIEW.FUN_140de2490(spItem->FUN_1405276c0()) == 0)
        {
            FUN_141275260(0xf1, 1, 0);
            return 0;
        }
        if (spItem->FUN_140526850() == false || bAll)
        {
            MS2Ptr<CItemData> spData((CItemData*)spItem->FUN_140527840());
            FUN_140de2dc0(&MS2_STORE_TABLE, spItem->FUN_140526a50(), nSlot, spItem->FUN_140526c50(), spData);
        }
        else
        {
            FUN_1414043e0(spItem->FUN_140526a50(), spItem->FUN_140526c50(), spItem->FUN_1405281e0(), 0, m_nIndex);
        }
        break;
    }
    case 4:
    {
        MS2Ptr<CItem> spCur = DAT_143ab2a90.FUN_140a5d680(GetItemUid());
        if (spCur.get() != 0)
            FUN_141405a60(spCur.get(), 0);
        break;
    }
    case 5:
    {
        int bCodi = 0;
        if (spItem->FUN_1405258b0() != 0)
            bCodi = 1;
        DAT_143ab2a90.FUN_140a621c0(GetItemUid(), 0, bCodi);
        break;
    }
    case 6:
    {
        int nSlot = FUN_1414056b0(spItem);
        DAT_143ab2a90.FUN_140a621c0(GetItemUid(), 0, nSlot);
        break;
    }
    case 7:
        if (spItem->FUN_140527840()->FUN_14053e460())
        {
            __int64 nUid = 0;
            int nSkillId = FUN_141769320(MS2Ptr<CItemData>((CItemData*)spItem->FUN_140527840()));
            if (spItem->FUN_140527840()->FUN_14053cc80() && spItem->FUN_140525f10() != 0)
            {
                if (spItem->FUN_140525f60() == 0)
                {
                    FUN_140d73bc0(0x2e8, 0, 0, CStringW(L""));
                    return 0;
                }
                nUid = spItem->FUN_140526a50();
            }
            bool bShortcut = false;
            MS2Ptr<SkillData> spSkill = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
            if (spSkill.get() != 0)
                bShortcut = spSkill->FUN_1407e9ea0();
            if (spItem->FUN_140527840()->FUN_14053d270() == false || bShortcut)
                nUid = spItem->FUN_140526a50();
            else
                nUid = 0;
            int nPage = FUN_1409331f0()->FUN_140a700b0();
            FUN_14092fac0(nSkillId, spItem->FUN_1405276c0(), nUid, nPage);
        }
        break;
    case 8:
    case 9:
        if (FUN_1409c4b20()->FUN_140532ab0() != 0)
            FUN_1409c4b20()->FUN_140532de0(spItem, -1);
        break;
    case 10:
        if (FUN_140535310()->FUN_140612d60() != 0)
            FUN_140535310()->FUN_140612e90(spItem);
        break;
    case 11:
    {
        UIBlackMarketDialog* pMarket;
        if (FUN_141409150(spItem) != 0 && (pMarket = FUN_140a22f10(0x4e97)) != 0)
            pMarket->FUN_1418d0fc0(this, (CItem*)spItem);
        break;
    }
    case 12:
        if (FUN_140938c30(0x2711) != 0)
            FUN_141271960(spItem, -1, 0);
        break;
    case 13:
    {
        UIPlayInstrumentDialog* pPlay = FUN_140d0c040(0x4eec);
        if (pPlay != 0)
        {
            CStringW strError;
            if (spItem->FUN_140527840()->FUN_14053cd10() == false)
                strError = GetStringCommonByKey(CStringW(L"s_item_err_cannot_play_instrument"));
            else if (spItem->FUN_140525730() == false)
            {
                if (spItem->FUN_140527340() < 1)
                    strError = GetStringCommonByKey(CStringW(L"s_item_err_cannot_play_none_count"));
                else if (pPlay->FUN_14100c8f0() == false)
                    strError = GetStringCommonByKey(CStringW(L"s_item_err_cannot_play_now"));
                else if (spItem->FUN_140528980() == false)
                    strError = GetStringCommonByKey(CStringW(L"s_item_err_cannot_invaild_item"));
            }
            else
                strError = GetStringCommonByKey(CStringW(L"s_item_err_cannot_play_instrument_empty_custom"));
            if (strError.IsEmpty())
                pPlay->FUN_14100c910(spItem);
            else
                FUN_1412751f0(strError, 1, 1);
        }
        break;
    }
    case 14:
    {
        unsigned nFree = FUN_140535320()->FUN_140c8b410()->FUN_140c87b90();
        if (nFree == -1 && spItem->FUN_1405281e0() < 2)
        {
            FUN_141275260(0xf2, 1, 1);
            return 0;
        }
        FUN_140c887b0(spItem, 0);
        break;
    }
    case 15:
        FUN_141405440(spItem);
        break;
    case 16:
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC == 0)
            return 0;
        if (spItem->FUN_140525640() != 0)
            pPC->FUN_14152aa90(spItem, 0);
        break;
    }
    case 17:
    {
        UIItemMergeRevertDialog* pRevert = FUN_140d274e0(0x4f3d);
        if (pRevert != 0)
        {
            int nError = pRevert->FUN_140e4d330(spItem.get());
            if (nError == 0)
                pRevert->FUN_140e4c7d0(spItem.get());
            else
                pRevert->FUN_140e4d010(nError);
        }
        break;
    }
    case 18:
    {
        UIItemExtractionScrollDialog* pScroll;
        if (FUN_140166410()->FUN_14036d570(0x8f) && (pScroll = FUN_140d27300(0x4f49)) != 0)
            pScroll->FUN_140e4a920(m_nItemUid);
        break;
    }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141406A60, InvenSlot, vfunc_14, 3942, 0x65D9E63E);

// @0x141407a20
int InvenSlot::vfunc_15()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem.get() != 0)
        FUN_140d2cfc0(spItem);
    return DragSlot::vfunc_15();
}
MS2_REPLACE_METHOD(0x141407A20, InvenSlot, vfunc_15, 136, 0xAA066DF1);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x141407ab0
int InvenSlot::vfunc_17()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    int nResult = vfunc_26(spItem);
    if (nResult == 0)
    {
        vfunc_12();
    }
    else if (nResult == 1)
    {
        vfunc_12();
        BlockPtr spBlocked = FUN_140a6a830()->FindBlockedAction(0x14);
        if (spBlocked.get() != 0)
        {
            FUN_140a2ff20(spBlocked, 0x14, 0);
            return 1;
        }
        FUN_14140c4d0(m_nItemUid, spItem->FUN_1405276c0(), spItem->FUN_140526c50(), spItem->FUN_1405281e0());
    }
    else if (nResult == 2)
    {
        vfunc_12();
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141407AB0, InvenSlot, vfunc_17, 456, 0xEAFF2A56);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x141407c80
int InvenSlot::vfunc_18(void* p)
{
    DragSlot* pDrag = static_cast<DragSlot*>(p);
    InvenSlot* pInven = FUN_140a50b50(pDrag);
    if (pInven != 0)
    {
        COutPacket packet(0x17, 0);
        packet.vfunc_o10_1(3);
        packet.vfunc_o10_4(pInven->GetItemUid());
        packet.vfunc_o10_2((short)m_nIndex);
        FUN_140710590(packet);
        FUN_141404930(pInven->GetItemUid());
        return pInven->vfunc_10();
    }
    EquipSlot* pEquip = FUN_14120d560(pDrag);
    if (pEquip != 0)
    {
        MS2Ptr<CItem> spWorn = pEquip->vfunc_25();
        MS2Ptr<CItem> spMine = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
        if (spWorn.get() != 0)
        {
            if (spMine.get() != 0
                && spMine->FUN_140527840()->FUN_14053eba0()->FUN_14054b450(spWorn->FUN_140527a20()))
            {
                DAT_143ab2a90.FUN_140a62270(spMine.get(), spWorn->FUN_140527a20(), pEquip->GetKind(), 0);
            }
            else if (IS_INVENTORY_VIEW.FUN_140a65b70() == DAT_143ab2a90.FUN_140a617f0(spWorn))
            {
                DAT_143ab2a90.FUN_140a62920(spWorn->FUN_140526a50());
            }
        }
    }
    else if (StoreSlot* pStore = efd::DynamicCast<StoreSlot>(pDrag))
    {
        MS2Ptr<CItem> spItem = IS_STORE_VIEW.FUN_140de1490(pStore->GetStoreItemId());
        if (spItem == 0)
            return pDrag->vfunc_10();
        if (pStore->vfunc_26(spItem) == 1)
            return 1;
        int nTab = DAT_143ab2a90.FUN_140a617f0(spItem);
        int nSlot = DAT_143ab2a90.FUN_140a612b0(nTab, spItem, spItem->FUN_140526c50());
        if (nSlot == -1)
        {
            FUN_140961010(0x44, 1, 1, FUN_1401a9d70()->FUN_141813300(nTab));
            FUN_141276180(s_strSystemNoticeErrorWarningBag, CString(""));
            return pDrag->vfunc_10();
        }
        if (DAT_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
            return 0;
        if (spItem->FUN_14052a580((void*)DAT_143ab2828) != 1)
        {
            FUN_140d73bc0(0xff, 0, 0, CStringW(L""));
            return 0;
        }
        if (spItem->FUN_140526850() == false)
        {
            FUN_140de31f0(&MS2_STORE_TABLE, spItem->FUN_140526a50(), m_nIndex, spItem->FUN_140526c50(),
                MS2Ptr<CItemData>(0));
        }
        else
        {
            FUN_1414045d0(spItem->FUN_140526a50(), spItem->FUN_140526c50(), spItem->FUN_1405281e0(), 1, m_nIndex);
        }
        FUN_141404930(pStore->GetStoreItemId());
    }
    else if (TradeSlot* pTrade = efd::DynamicCast<TradeSlot>(pDrag))
    {
        FUN_1414048f0(pTrade->FUN_14185e530());
        pTrade->FUN_14185e5d0();
    }
    else if (GemSlot* pGem = efd::DynamicCast<GemSlot>(pDrag))
    {
        MS2Ptr<CItem> spGem = pGem->vfunc_25();
        MS2Ptr<CItem> spMine = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
        if (spGem.get() != 0)
        {
            if (spMine.get() != 0 && spMine->FUN_140525a30() != 0)
            {
                int nKind = spMine->FUN_140527840()->FUN_14053e900();
                if (nKind == spGem->FUN_140527840()->FUN_14053e900())
                {
                    if (pGem->GetGemType() == nKind)
                        FUN_141271960(spMine, spGem->FUN_140526b50(), 0);
                }
                else
                {
                    FUN_141271f90(spGem);
                }
            }
            else
            {
                FUN_141271f90(spGem);
            }
        }
        return pGem->vfunc_10();
    }
    else if (FittingDollSlot* pDoll = efd::DynamicCast<FittingDollSlot>(pDrag))
    {
        pDoll->FUN_14121ddc0();
    }
    else if (ItemBreakSlot* pBreak = efd::DynamicCast<ItemBreakSlot>(pDrag))
    {
        MS2Ptr<CItem> spOld = pBreak->vfunc_25();
        MS2Ptr<CItem> spMine = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
        if (FUN_1409c4b20()->FUN_140531270(spOld) != 0)
        {
            if (FUN_1409c4b20()->FUN_140531270(spMine) == 0)
                FUN_1409c4b20()->FUN_140533340(spOld);
            else
                FUN_1409c4b20()->FUN_140532de0(spMine, spOld->FUN_140526b50());
        }
    }
    else if (ItemLockSlot* pLock = efd::DynamicCast<ItemLockSlot>(pDrag))
    {
        MS2Ptr<CItem> spOld = pLock->vfunc_25();
        MS2Ptr<CItem> spMine = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
        if (spOld.get() != 0 && spOld->FUN_140528cc0())
        {
            if (spMine.get() != 0 && spMine->FUN_140528cc0())
                FUN_140535310()->FUN_140612e90(spMine);
            else
                FUN_140535310()->FUN_1406130e0(spOld->FUN_140526a50());
        }
    }
    else if (PetSlot* pPet = FUN_140dbc0d0(pDrag))
    {
        __int64 nUid = pPet->GetPetItemUid();
        MS2Ptr<CItem> spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(nUid);
        if (spItem.get() != 0)
        {
            FUN_140c88c30(spItem, m_nIndex);
            FUN_141404930(nUid);
        }
    }
    else if (TabContentsPetInfo::EquipSlot* pPetEquip = efd::DynamicCast<TabContentsPetInfo::EquipSlot>(pDrag))
    {
        if (IS_INVENTORY_VIEW.FUN_140a65b70() == DAT_143ab2a90.FUN_140a617f0(pPetEquip->vfunc_25()))
        {
            MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPC != 0)
                pPC->SendRequestPet(pPetEquip->FUN_140cbcb00());
            return 1;
        }
    }
    else if (ItemScrollSlot* pScroll = efd::DynamicCast<ItemScrollSlot>(pDrag))
    {
        pScroll->vfunc_17();
        return 1;
    }
    return pDrag->vfunc_10();
}
MS2_REPLACE_METHOD(0x141407C80, InvenSlot, vfunc_18, 4021, 0xF695C1A1);

// @0x141408c50
MS2Ptr<CItem> InvenSlot::vfunc_25()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(GetItemUid());
    return spItem;
}
MS2_REPLACE_METHOD(0x141408C50, InvenSlot, vfunc_25, 108, 0xBDCB37C8);

// @0x141408cd0
int InvenSlot::vfunc_20()
{
    DragSlot::vfunc_20();
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem.get() != 0)
    {
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            spItem->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
        if (spItem->FUN_1405268f0() != 0)
            spItem->FUN_1405268d0(0);
        UIDialogEventDispatcher::GetInstance()->vfunc_3(this);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141408CD0, InvenSlot, vfunc_20, 444, 0x148FB318);

// @0x141408ea0
int InvenSlot::vfunc_21()
{
    DragSlot::vfunc_21();
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem.get() != 0)
    {
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            spItem->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
        UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
        if (pInventory != 0)
            pInventory->FUN_14199bc00();
    }
    UIDialogEventDispatcher::GetInstance()->vfunc_4(this);
    return 1;
}
MS2_REPLACE_METHOD(0x141408EA0, InvenSlot, vfunc_21, 441, 0x8B133860);

// @0x141409060
float InvenSlot::FUN_141409060()
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return pPC->FUN_141523bc0()->FUN_141765fe0(FUN_1414058f0(), 0);
}
MS2_REPLACE_METHOD(0x141409060, InvenSlot, FUN_141409060, 86, 0x7F94C302);

// @0x1414090c0
int InvenSlot::FUN_1414090c0()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(GetItemUid());
    if (!spItem)
        return 0;
    return FUN_141409150(spItem);
}
MS2_REPLACE_METHOD(0x1414090C0, InvenSlot, FUN_1414090c0, 136, 0x7DD6C7D5);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x141409150
int InvenSlot::FUN_141409150(CItem* pItem)
{
    if (FUN_140535310() != 0 && FUN_140535310()->FUN_140613160(pItem) == 0)
        return 0;
    int nReason = 0;
    if (FUN_140633fb0(MS2Ptr<CItem>(pItem), &nReason) == false)
    {
        CStringW strError;
        if (nReason == 2)
            strError = GetStringCommonByKey(CStringW(L"s_blackmarket_error_disable_registitem_by_gemstone"));
        else
            strError = GetStringCommon(0x92c);
        FUN_1412751f0(strError, 1, 1);
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141409150, InvenSlot, FUN_141409150, 355, 0x4C7BF1AE);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x1414092c0
int InvenSlot::vfunc_26(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return 0;
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    if (spData == 0)
        return 0;
    if (FUN_14138c900(FUN_1409331e0(), 6) != 0)
    {
        FUN_141275260(0x88a, 1, 1);
        return 0;
    }
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (pPC->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0x42, 0, 0, CStringW(L""));
        return 0;
    }
    void* pRide = pPC->FUN_141676a10();
    if (pRide != 0 && FUN_1410947c0(pRide) == spItem->FUN_140526a50())
    {
        FUN_140d73bc0(0x71, 0, 0, CStringW(L""));
        return 0;
    }
    if (pPC->FUN_141676b00(spItem->FUN_140526a50()) != 0)
    {
        FUN_140d73bc0(0x71, 0, 0, CStringW(L""));
        return 0;
    }
    if (FUN_140535310() != 0 && FUN_140535310()->FUN_140613160(spItem.get()) == 0)
        return 0;
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622750() == 0)
    {
        CStringW strKey(L"s_itembreak_usedgemstone_item");
        FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        return 0;
    }
    if (spItem->FUN_140525640() != 0 && FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4f38) != 0)
    {
        CStringW strKey(L"s_err_cannot_destroy_petsystem_opendialog");
        FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        return 0;
    }
    if (spData->FUN_14053c6f0() == 0xd8 && FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4f38) != 0)
    {
        CStringW strKey(L"s_err_cannot_destroy_petsystem_opendialog");
        FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        return 0;
    }
    if (spItem->FUN_140527840()->FUN_14053cd10() && FUN_140c8dac0()->FUN_140c8dab0() == spItem->FUN_140526a50())
    {
        CStringW strKey(L"s_play_instrument_cant_destory_score");
        FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        return 0;
    }
    if (FUN_140633700(spItem) == false)
    {
        CStringW strError;
        if (FUN_140764020()->FUN_1416ce170(spItem) == 0)
        {
            if (spItem->FUN_140527930()->FUN_140635120() == 0)
            {
                MS2Ptr<TSocketGemStoneInfo> spGem = spItem->FUN_1405279c0()->FUN_140620c40();
                if (spGem.get() == 0)
                {
                    if (DAT_143ab2a90.FUN_140a65770(spItem.get()) == 7)
                    {
                        strError = GetStringCommonByKey(CStringW(L"s_item_err_cannot_vip_drop"));
                        FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4f1b);
                    }
                    else
                    {
                        int nItemId = spItem->FUN_1405276c0();
                        strError = FUN_14052bd00(0xd8, FUN_1401a9d70()->FUN_141811980(1, nItemId));
                    }
                }
                else
                {
                    CStringW strOwner = spGem->FUN_1406201d0();
                    if (!strOwner.IsEmpty())
                        strError = FUN_1405c2690(CStringW(L"s_item_err_cannot_drop_if_binding_in_socket"), strOwner);
                }
            }
            else
            {
                CStringW strOwner;
                spItem->FUN_140527930()->FUN_140635350(pPC, &strOwner);
                strError = FUN_14052bd00(0xd9, strOwner);
            }
        }
        else
        {
            strError = FUN_1405c2690(CStringW(L"s_item_err_questitem_destroy"), FUN_14140c2b0(spItem));
        }
        if (strError.GetLength() != 0)
        {
            CStringW strText;
            CStringW strPrefix;
            bool bPrefix = false;
            FUN_1409e4950(spItem, strPrefix, &bPrefix);
            if (bPrefix == true && strPrefix.GetLength() > 0)
            {
                strText += strPrefix;
                strText += L"\n";
            }
            strText += strError;
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, strText, 0, s_strDestroyItem);
            if (spBox.get() != 0)
            {
                spBox->FUN_141a01600(m_nItemUid);
                spBox->FUN_141a024a0(0);
                spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, spItem->FUN_140526c50(), -1, -1, 1);
                spBox->FUN_141a01700(0x475, 0x476, 0);
                FUN_140d73c60(spBox);
                return 0;
            }
        }
    }
    NxGroupsMask kMask;
    kMask.bits0 = 0xffffffff;
    kMask.bits3 = 0;
    kMask.bits2 = 0;
    kMask.bits1 = 0;
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = pPC->FUN_1416767d0();
    kInfo.m_dir = DAT_143a08cf8.FUN_1409f7960();
    kInfo.m_maxDist = 0.0f;
    kInfo.m_groups = 0x389;
    if (FUN_1409f7ca0()->CastRay(&kInfo, &kMask) == false)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1414092C0, InvenSlot, vfunc_26, 4553, 0x6E22C975);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140a490 (ITooltip::vfunc_0)
int InvenSlot::vfunc_0(void* p)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (!spItem)
        return 0;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    int nMode = FUN_14140d3e0(spItem, 1);
    if (nMode == 2)
    {
        Unk_IsPadHudPtr spHud = FUN_14025e7a0()->FUN_1422b0370(6);
        if (spHud.FUN_140a58470() != 0)
            spHud.FUN_140a584a0()->FUN_1422cee50(8);
    }
    if (FUN_1403b3c40(spItem->FUN_140527840()->function.name, L"ItemExchangeScroll"))
    {
        MS2Ptr<CExchangeItemInfo> spInfo = FUN_140f56960()->GetData(spItem->FUN_1405276c0());
        if (spInfo.get() != 0)
        {
            MS2Ptr<CItem> spResult(new CItem);
            if (spResult.get() != 0)
            {
                if (spResult->FUN_14052b130(spInfo->m_exchange.m_nId, spInfo->m_exchange.m_nRank, 0) == 0)
                    return 0;
                ASTooltip tip(pPC, 0x800, 2);
                if (tip.FUN_1409e13f0(spResult.get(), spItem.get(), 0x800, 0x80) != 0)
                {
                    {
                        CStringW strEmpty(L"");
                        tip.FUN_1409c6a20(strEmpty, GetStringCommon(0x75a));
                    }
                    {
                        CStringW strEmpty(L"");
                        CStringW strKey(L"s_word_compose_result");
                        tip.FUN_1409c7060(GetStringCommonByKey(strKey), strEmpty);
                    }
                    *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
                    return 1;
                }
            }
        }
        return 0;
    }
    MS2Ptr<CItem> spWorn(FUN_14140c030(spItem));
    if (spWorn.get() != 0 && spWorn->FUN_140526a50() == spItem->FUN_140526a50())
        return 0;
    ASTooltip tip(pPC, 0x80, 2);
    if (tip.FUN_1409e13a0(spWorn.get(), spItem.get()) == 0)
        return 0;
    CStringW strHint = vfunc_22();
    if (strHint.GetLength() == 0)
    {
        CStringW strEmpty1(L"");
        CStringW strEmpty2(L"");
        tip.FUN_1409c6a20(strEmpty2, strEmpty1);
    }
    else
    {
        CStringW strEmpty(L"");
        tip.FUN_1409c6a20(strEmpty, strHint);
    }
    if (nMode == 2)
        tip.FUN_1409c0e60("customizeColor", L"");
    if (FUN_1403ed2b0()->FUN_141adcb40() != 0 && spItem->FUN_140527840()->FUN_14053d510())
    {
        MS2Ptr<CEquipItem> spEquip = static_cast<Unk_IsEquipView*>(pPC)->FUN_141655e10(4);
        bool bDagger = spEquip.get() != 0 && spEquip->GetItem() == spWorn.get();
        if (bDagger)
            FUN_141276180(s_strChangeDagger, CString(""));
    }
    if (IsEnabled() == true)
        tip.FUN_1409db930(MS2Ptr<CItem>(0), spItem);
    *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x14140A490, InvenSlot, ITooltip, vfunc_0, 2550, 0x2972CB7F);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140ae90
int InvenSlot::vfunc_8(void* p)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (!spItem)
        return 0;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(spItem.get(), pPC, 0x1c01f) == 0)
        return 0;
    slot.FUN_1407cbbe0(s_strUpdateIconSearchOn, FUN_14140c180(spItem));
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}
MS2_REPLACE_METHOD(0x14140AE90, InvenSlot, vfunc_8, 406, 0x667BD262);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140b030
CStringW InvenSlot::vfunc_22()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (!spItem)
        return CStringW(L"");
    switch (FUN_14140d3e0(spItem, 1))
    {
    case 1:
        return GetStringCommon(0x74f);
    case 2:
        return GetStringCommon(0x755);
    case 3:
        return GetStringCommon(0x753);
    case 4:
        return GetStringCommon(0x75b);
    case 5:
        return GetStringCommonByKey(CStringW(L"s_msg_rclick_puton_equip_to_skintab"));
    case 6:
        if (FUN_140166410()->FUN_14036d570(0x8e) && spItem->FUN_1405258b0() != 0)
        {
            CStringW strText = GetStringCommonByKey(CStringW(L"s_msg_rclick_puton_equip_to_coditab"));
            CStringW strKey = FUN_1409331f0()->FUN_14142d760(0x4940d, 0);
            if (!strKey.IsEmpty())
            {
                strText += L"\n";
                strText += FUN_1405c2690(CStringW(L"s_msg_rclick_puton_equip_to_skintab_with_key"), strKey);
            }
            return strText;
        }
        return GetStringCommon(0x751);
    case 7:
        return GetStringCommon(0x75a);
    case 8:
    case 9:
        return GetStringCommon(0x75f);
    case 10:
        return GetStringCommon(0x75f);
    case 11:
        return GetStringCommon(0x760);
    case 13:
        return GetStringCommon(0x761);
    case 17:
        return GetStringCommonByKey(CStringW(L"s_msg_rclick_item_merge_revert"));
    case 18:
        return GetStringCommonByKey(CStringW(L"s_msg_rclick_item_extraction"));
    default:
        return CStringW(L"");
    }
}
MS2_REPLACE_METHOD(0x14140B030, InvenSlot, vfunc_22, 1446, 0x2DF2A92D);

// @0x14140b630
void InvenSlot::vfunc_23(void* p)
{
    FUN_141404ce0(FUN_1414058f0(), (unsigned __int64)p, &m_value18);
}
MS2_REPLACE_METHOD(0x14140B630, InvenSlot, vfunc_23, 63, 0x3AD216A1);

// @0x14140b680
void InvenSlot::vfunc_24(void* p)
{
    FUN_1414050c0(FUN_1414058f0(), (unsigned __int64)p, &m_value18);
}
MS2_REPLACE_METHOD(0x14140B680, InvenSlot, vfunc_24, 63, 0x5BBBA7AD);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140b6d0
int InvenSlot::FUN_14140b6d0(MS2Ptr<CItem> spItem)
{
    if (!spItem)
        return 0;
    if (spItem->FUN_140527930() == 0)
        return 0;
    if (FUN_140535310() != 0 && FUN_140535310()->FUN_140613160(spItem.get()) == 0)
        return 0;
    int nReason = 0;
    if (FUN_140633e40(spItem, &nReason) == false)
    {
        CStringW strError;
        if (nReason == 2)
            strError = GetStringCommonByKey(CStringW(L"s_trade_tradelimit_by_gemstone"));
        else
            strError = GetStringCommon(0x83f);
        FUN_1412751f0(strError, 1, 1);
        return 0;
    }
    if (spItem->FUN_140527840()->FUN_14053cd10() && FUN_140c8dac0()->FUN_140c8dab0() == spItem->FUN_140526a50())
    {
        CStringW strKey(L"s_trade_tradelimit_playing_score");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        return 0;
    }
    UITradeDialogEx* pTrade = Unk_InvGetDialogById<UITradeDialogEx>(0x4e83);
    if (pTrade != 0)
    {
        int nSlot = 0;
        if (pTrade->FUN_141b283f0(&nSlot) == 0)
        {
            FUN_140d73aa0(GetStringCommon(0x82f), 0, 0, CStringW(L""));
            return 0;
        }
        bool bAll;
        if (FUN_14025e7c0()->FUN_14116d950(0x2a, false, 0) || FUN_14025e7c0()->FUN_14116d950(0x36, false, 0))
            bAll = true;
        else
            bAll = false;
        if (spItem->FUN_140526850() == false || bAll)
        {
            int nCount = spItem->FUN_140526c50();
            CTradeManagerEx::GetInstance()->SendTradeMode8(spItem->FUN_140526a50(), nCount, nSlot);
            FUN_141404930(spItem->FUN_140526a50());
        }
        else
        {
            FUN_14140d200(spItem->FUN_140526a50(), spItem->FUN_140526c50(), spItem->FUN_1405281e0());
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14140B6D0, InvenSlot, FUN_14140b6d0, 1397, 0xA82B334A);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140bc50
int InvenSlot::FUN_14140bc50(CStringW strSearch)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem == 0)
        return -1;
    CStringW strName = spItem->FUN_140527b10();
    CStringW strLower = FUN_1413fa9b0(strName);
    bool bFound = false;
    if (strSearch.GetLength() > 0)
    {
        strSearch.MakeLower();
        strLower.MakeLower();
        bFound = FUN_14025cd60(strLower, strSearch);
    }
    if (FUN_1409b4d40(m_value18))
    {
        Unk_IsScript script(m_value18, 2);
        FUN_140614800(script.FUN_140bfe360(s_strUpdateIconSearchOn, bFound));
    }
    if (bFound == false)
        return -1;
    return m_nIndex;
}
MS2_REPLACE_METHOD(0x14140BC50, InvenSlot, FUN_14140bc50, 507, 0x1568B068);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140be60
int InvenSlot::FUN_14140be60(CItem* pItem)
{
    if (FUN_14140e3f0(MS2Ptr<CItem>(pItem)) == 0)
        return 0;
    bool bAll;
    if (FUN_14025e7c0()->FUN_14116d950(0x2a, false, 0) || FUN_14025e7c0()->FUN_14116d950(0x36, false, 0))
        bAll = true;
    else
        bAll = false;
    if (!bAll && pItem->FUN_140525c60() == 0)
    {
        FUN_14140cb90(GetItemUid(), FUN_141405980(), pItem->FUN_140526c50(), pItem->FUN_140526c50(),
            pItem->FUN_140527670(), pItem->FUN_140527b10());
        return 1;
    }
    FUN_141425fc0(pItem->FUN_140526a50(), pItem->FUN_140526c50(), pItem);
    return 1;
}
MS2_REPLACE_METHOD(0x14140BE60, InvenSlot, FUN_14140be60, 447, 0xAE0AD242);

// @0x14140c030
CItem* InvenSlot::FUN_14140c030(MS2Ptr<CItem> spItem)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return pPC->FUN_14152e2f0(spItem).get();
}
MS2_REPLACE_METHOD(0x14140C030, InvenSlot, FUN_14140c030, 201, 0x6ED00564);

// @0x14140c100
void InvenSlot::FUN_14140c100()
{
    if (FUN_140764020()->FUN_1416ce170(vfunc_25()) != 2)
        vfunc_10();
}
MS2_REPLACE_METHOD(0x14140C100, InvenSlot, FUN_14140c100, 112, 0xA309D40E);

// @0x14140c180
bool InvenSlot::FUN_14140c180(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return false;
    bool bResult = false;
    UIInventoryDialog* pDlg = Unk_InvGetDialog<UIInventoryDialog>();
    if (pDlg != 0)
    {
        if (pDlg->vfunc_55() == 0)
        {
            CStringW strQuery = pDlg->FUN_14199abe0();
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
MS2_REPLACE_METHOD(0x14140C180, InvenSlot, FUN_14140c180, 297, 0x5F3CA500);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140c2b0
// The names of the quests that use the item, one per line.
static CStringW FUN_14140c2b0(MS2Ptr<CItem> spItem)
{
    ATL::CAtlArray<int> arrQuests;
    FUN_140764020()->FUN_1416ce860(spItem, arrQuests);
    if (arrQuests.GetCount() == 0)
        return CStringW(L"");
    CStringW strNames;
    for (size_t i = 0; i < arrQuests.GetCount(); i++)
    {
        if (!strNames.IsEmpty())
            strNames += L"\n";
        strNames += FUN_1416e5210(arrQuests[i], CStringW(L"s_msg_tooltip_quest_name"));
    }
    return strNames;
}
MS2_REPLACE(0x14140C2B0, FUN_14140c2b0, 526, 0x185916FD);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140c4d0
// Drop the item: at once for one non-quest item, else ask (with a count for stacks).
static void FUN_14140c4d0(__int64 nUid, int nItemId, int nCount, int nMax)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
    int nQuest = FUN_140764020()->FUN_1416ce170(spItem);
    if (nCount < 2 && nQuest == 0)
    {
        FUN_140714f90()->FUN_141538930(nUid, nCount);
        return;
    }
    CStringW strText;
    int nType;
    if (nCount < 2)
    {
        nType = 0x11;
        strText = FUN_1405c2690(CStringW(L"s_msg_quest_item_drop"), FUN_14140c2b0(spItem));
    }
    else
    {
        nType = 0xd;
        strText = nQuest == 0 ? FUN_140298ea0(CStringW(L"s_msg_item_drop"))
                              : FUN_1405c2690(CStringW(L"s_msg_quest_item_drop_stack"), FUN_14140c2b0(spItem));
    }
    MS2Ptr<CItem> spCur = DAT_143ab2a90.FUN_140a5d680(nUid);
    if (!spCur)
        return;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(nType, strText, 0, s_strDrop);
    if (spBox.get() != 0)
    {
        CStringW strCount;
        strCount.Format(L"%d", nCount);
        spBox->FUN_141a01600(nUid);
        spBox->FUN_141a01d30(1, strCount, FUN_1412773a0(nMax), 0, 0);
        spBox->FUN_141a01ee0(spCur, spCur->FUN_140527b10(), 1, 0, -1, -1, 1);
        spBox->FUN_141a01700(0x477, 0x478, 0);
        FUN_140d73c60(spBox);
    }
}
MS2_REPLACE(0x14140C4D0, FUN_14140c4d0, 1719, 0x28342F3F);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140cb90
// Sell the item to the npc shop: at once for one non-quest item, else ask.
static void FUN_14140cb90(__int64 nUid, int nItemId, int nCount, int nMax, int nPrice, CStringW strName)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
    int nQuest = FUN_140764020()->FUN_1416ce170(spItem);
    if (nMax < 2 && nQuest == 0)
    {
        FUN_1419f8920(DAT_143ab2a90.FUN_140a5d680(nUid), nCount);
        return;
    }
    CStringW strText;
    int nType;
    if (nMax < 2)
    {
        nType = 0x11;
        strText = FUN_1405c2690(CStringW(L"s_msg_quest_item_sell"), FUN_14140c2b0(spItem));
    }
    else
    {
        nType = 0x12;
        strText = nQuest == 0 ? GetStringCommonByKey(CStringW(L"s_msg_item_sell"))
                              : FUN_1405c2690(CStringW(L"s_msg_quest_item_sell_stack"), FUN_14140c2b0(spItem));
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(nType, strText, 0, s_strSell);
    if (spBox.get() != 0)
    {
        MS2Ptr<CItem> spCur = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spCur.get() != 0)
        {
            spBox->FUN_141a01600(nUid);
            spBox->SetTitle(GetStringCommon(0x460));
            spBox->FUN_141a01700(0x47e, 0x476, 0);
            spBox->FUN_141a01ee0(spCur, strName, 1, nCount, nMax, nPrice, 1);
            FUN_140d73c60(spBox);
        }
    }
}
MS2_REPLACE(0x14140CB90, FUN_14140cb90, 1637, 0xE0599DE8);

// @0x14140d200
// Ask the count of a stack to put into the trade window.
static void FUN_14140d200(__int64 nUid, int nCount, int nMax)
{
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(5, 0x842, 0, s_strTradeIn);
    if (spBox.get() != 0)
    {
        CStringW strCount;
        strCount.Format(L"%d", nCount);
        spBox->FUN_141a01600(nUid);
        spBox->FUN_141a01d30(1, strCount, FUN_1412773a0(nMax), 0, 0);
        FUN_140d73c60(spBox);
    }
}
MS2_REPLACE(0x14140D200, FUN_14140d200, 322, 0xD776043D);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140d350
// The item may be put on the fitting doll.
static int FUN_14140d350(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    if (pItem->FUN_140527840()->FUN_14053cbc0() == false)
        return 0;
    FittingDollPC* pDoll = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(DAT_143af25f0));
    if (pDoll == 0)
        return 0;
    if (pDoll->FUN_14121c910(pItem) == 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x14140D350, FUN_14140d350, 128, 0x40533BAE);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140d3e0
// The right click action for the item by the latest open dialog (1 trade, 2 sell, 3 store, 4 fitting doll, 5 codi,
// 6 equip, 7 shortcut, 8 break, 10 lock, 11 black market, 12 gem, 13 instrument, 14 pet inventory, 15 destroy,
// 16 summon, 17 merge revert, 18 extraction; 0 none). bHint: only the modes that show a hint.
static int FUN_14140d3e0(MS2Ptr<CItem> spItem, int bHint)
{
    if (!spItem)
        return 0;
    int nDialog = !DAT_143af2258.IsEmpty() ? DAT_143af2258.GetHead() : 0;
    if (nDialog == 0x4e83)
    {
        if (FUN_140633a20(spItem) == false)
            return bHint ? 0 : 1;
        return 1;
    }
    else if (nDialog == 0x4e3b)
    {
        if (FUN_140633840(spItem) == false)
            return bHint ? 0 : 2;
        return 2;
    }
    else if (nDialog == 0x4e47 || nDialog == 0x4e78)
    {
        if (IS_STORE_VIEW.FUN_140de2490(spItem->FUN_1405276c0()) == 0)
            return bHint ? 0 : 3;
        return 3;
    }
    else if (nDialog == 0x4e77)
    {
        if (FUN_14140d350(spItem.get()) == 0)
            return bHint ? 0 : 4;
        return 4;
    }
    else if (nDialog == 0x4e8d || nDialog == 0x4e8e)
    {
        if (FUN_1409c4b20()->FUN_140531270(spItem) == 0)
            return bHint ? 0 : 8;
        return 8;
    }
    else if (nDialog == 0x4f08)
    {
        if (spItem->FUN_140528cc0() == false)
            return bHint ? 0 : 10;
        return 10;
    }
    else if (nDialog == 0x4f49)
    {
        return 18;
    }
    else if (nDialog == 0x4e97)
    {
        UIBlackMarketDialog* pMarket;
        if (FUN_140633b80(spItem) == false || (pMarket = FUN_140a22f10(0x4e97)) == 0 || pMarket->FUN_1418d0be0() == false)
            return bHint ? 0 : 11;
        return 11;
    }
    else if (nDialog == 0x4eec)
    {
        if (spItem->FUN_140527840()->FUN_14053cd10() && spItem->FUN_140525730() == false)
            return 13;
        return bHint ? 0 : 13;
    }
    else
    {
        if (nDialog == 0x4f38)
        {
            if (spItem->FUN_140525640() != 0)
                return 16;
            if (FUN_140535320()->FUN_140c8b410()->FUN_140c875e0() > 0)
                return 14;
        }
        else if (nDialog == 0x4f3d)
        {
            if (bHint == 0)
                return 17;
            UIItemMergeRevertDialog* pRevert = FUN_140d274e0(0x4f3d);
            if (pRevert != 0 && pRevert->FUN_140e4d330(spItem.get()) == 0)
                return 17;
        }
        else if (nDialog == 0x2711)
        {
            void* pProfile;
            if (FUN_140166410()->FUN_14036d570(0x8e) && spItem->FUN_140527840()->FUN_14053cbc0()
                && spItem->FUN_1405258b0() != 0 && (pProfile = FUN_140938c30(0x2711)) != 0
                && FUN_141a5c7a0(pProfile) == 1)
                return 5;
        }
        if (spItem.get() != 0)
        {
            if (spItem->FUN_140525fc0() != 0)
                return 15;
            if (spItem->FUN_140527840()->FUN_14053cbc0())
                return 6;
            if (spItem->FUN_140527840()->FUN_14053e460())
                return 7;
            if (spItem->FUN_140525a30() != 0)
                return 12;
        }
        return 0;
    }
}
MS2_REPLACE(0x14140D3E0, FUN_14140d3e0, 2320, 0x7B8340F6);

// @0x14140dd30
// The text of a put-on error kind.
static CStringW FUN_14140dd30(int nUnused, int nKind)
{
    switch (nKind)
    {
    case 0:
        return CStringW(L"");
    case 1:
        return GetStringCommon(0xbf0);
    case 2:
        return GetStringCommon(0xbf1);
    case 4:
        return GetStringCommon(0xbf2);
    case 5:
        return GetStringCommon(0xbf2);
    case 6:
        return GetStringCommon(0xbf2);
    default:
        return CStringW(L"");
    }
}
MS2_REPLACE(0x14140DD30, FUN_14140dd30, 318, 0x900560A2);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140dea0
// The player may put the item on (notices why not).
static int FUN_14140dea0(CItem* pItem, MyPC* pPC)
{
    if (pItem->FUN_140528980() == false)
    {
        if (pItem->FUN_140528930())
            FUN_140d73bc0(0xe1, 0, 0, CStringW(L""));
        return 0;
    }
    Unk_IsEquipView* pView = static_cast<Unk_IsEquipView*>(pPC);
    if (pItem->FUN_140525ca0() != 0 && pView->FUN_141658f30() == 0)
    {
        FUN_140d73bc0(0xe2, 0, 0, CStringW(L""));
        return 0;
    }
    if (pItem->FUN_140525db0() != 0 && pView->FUN_141662de0() == 0)
    {
        CStringW strKey(L"s_item_err_puton_vip");
        FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        return 0;
    }
    if (pItem->FUN_140525e00() != 0 && pPC->vfunc_146() == false)
    {
        CStringW strKey(L"s_item_err_puton_wedding");
        FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        return 0;
    }
    Unk_IsItemRequire* pRequire = static_cast<Unk_IsItemRequire*>(pItem);
    if (pRequire->FUN_140526810(pPC->vfunc_78()) == 0)
    {
        CStringW strKey(L"s_err_not_enough_level");
        FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        return 0;
    }
    if (pRequire->FUN_140526790(pPC->FUN_141654700()) == 0)
    {
        CStringW strKey(L"s_item_err_disable_job");
        FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        return 0;
    }
    __int64 nCharacterId = pPC->FUN_141656a80();
    if (FUN_1406343b0(MS2Ptr<CItem>(pItem), &nCharacterId) == false)
    {
        FUN_140d73bc0(0xfe, 0, 0, CStringW(L""));
        return 0;
    }
    if (pRequire->FUN_1405267d0(pPC->FUN_141658e60()) == 0)
    {
        FUN_140d73bc0(0x2d, 0, 0, CStringW(L""));
        return 0;
    }
    return 1;
}
MS2_REPLACE(0x14140DEA0, FUN_14140dea0, 1340, 0x1497075E);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140e3f0
// The open npc shop buys the item.
static int FUN_14140e3f0(MS2Ptr<CItem> spItem)
{
    MS2Ptr<UIShopDialog> spShop(FUN_140534780(0x4e3b));
    if (spShop.get() != 0)
    {
        if (spShop->FUN_141afb780(spItem) == false)
            return 0;
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x14140E3F0, FUN_14140e3f0, 251, 0x18B38322);

// ---- InventorySlotBag ----

// @0x14140eca0
// Create the slot bag of an inventory tab with nCount slots and register it under its name.
InventorySlotBag* FUN_14140eca0(const CString& strName, int nTab, int nCount)
{
    InventorySlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) InventorySlotBag(strName, nTab);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
    return pBag;
}
MS2_REPLACE(0x14140ECA0, FUN_14140eca0, 186, 0x331442C2);

// @0x14140ed60
// Destroy the slot bag registered under the name.
void FUN_14140ed60(const CString& strName)
{
    InventorySlotBag* pBag = efd::DynamicCast<InventorySlotBag>(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}
MS2_REPLACE(0x14140ED60, FUN_14140ed60, 65, 0xE9E644AD);

// @0x14140edb0
InventorySlotBag::InventorySlotBag(const CString& strName, int nTab)
    : DragSlotBag(strName), m_nTab(nTab), m_nPendingSlot(-1)
{
    FUN_1419cae20(FUN_140a6a840(), this);
    FUN_140bc09f0()->FUN_141b38be0(this);
}

// @0x14140eee0
InventorySlotBag::~InventorySlotBag()
{
    FUN_1419caeb0(FUN_140a6a840(), this);
    FUN_140bc09f0()->FUN_141b38c70(this);
}

// @0x14140efe0
int InventorySlotBag::vfunc_il1()
{
    UIInventoryDialog* pDlg = FUN_1405344f0(0x4e2d);
    if (pDlg == 0 || pDlg->vfunc_55() != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x14140EFE0, InventorySlotBag, UIItemEventListener, vfunc_il1, 69, 0x148E9A68);

// @0x14140f030
void InventorySlotBag::vfunc_ugc_2(void* p, CString str)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680((__int64)p);
    if (spItem == 0)
        return;
    if (FUN_14140f990(spItem.get()) == 0)
        return;
    InvenSlot* pSlot = FUN_140a50b50(FUN_1422cd070(spItem->FUN_140526b50()));
    if (pSlot != 0)
        pSlot->vfunc_10();
}
MS2_REPLACE_METHOD_VIA(0x14140F030, InventorySlotBag, UIUGCEventListener, vfunc_ugc_2, 257, 0x632E673D);

// @0x14140f140
void InventorySlotBag::vfunc_2(void* p)
{
    UIInventoryDialog* pDlg = FUN_1405344f0(0x4e2d);
    if (pDlg != 0)
        FUN_140c3fe30(pDlg, 2);
    if (FUN_14140f990(static_cast<CItem*>(p)) != 0)
    {
        InvenSlot* pSlot = FUN_140a50b50(FUN_1422cd070(static_cast<CItem*>(p)->FUN_140526b50()));
        if (pSlot != 0)
        {
            pSlot->SetItemUid(static_cast<CItem*>(p)->FUN_140526a50());
            pSlot->vfunc_10();
        }
    }
}
MS2_REPLACE_METHOD_VIA(0x14140F140, InventorySlotBag, UIItemEventListener, vfunc_2, 174, 0xFF0188B3);

// @0x14140f200
void InventorySlotBag::vfunc_3(void* p, bool b)
{
    UIInventoryDialog* pDlg = FUN_1405344f0(0x4e2d);
    if (pDlg != 0)
        FUN_140c3fe30(pDlg, 2);
    if (FUN_14140f990(static_cast<CItem*>(p)) != 0)
    {
        DragSlot* pSlot = FUN_1422cd070(static_cast<CItem*>(p)->FUN_140526b50());
        if (pSlot != 0)
            pSlot->vfunc_11();
    }
}
MS2_REPLACE_METHOD_VIA(0x14140F200, InventorySlotBag, UIItemEventListener, vfunc_3, 148, 0x287E73BB);

// @0x14140f2a0
void InventorySlotBag::vfunc_4(void* p, int n)
{
    if (FUN_14140f990(static_cast<CItem*>(p)) != 0)
    {
        InvenSlot* pSlot = FUN_140a50b50(FUN_1422cd070(static_cast<CItem*>(p)->FUN_140526b50()));
        if (pSlot != 0)
        {
            pSlot->SetItemUid(static_cast<CItem*>(p)->FUN_140526a50());
            pSlot->vfunc_10();
        }
    }
}
MS2_REPLACE_METHOD_VIA(0x14140F2A0, InventorySlotBag, UIItemEventListener, vfunc_4, 141, 0xA6F6D9DF);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140f340
void InventorySlotBag::vfunc_5(void* p, int n)
{
    UIInventoryDialog* pDlg = FUN_1405344f0(0x4e2d);
    if (pDlg != 0)
        FUN_140c3fe30(pDlg, 1);
    if (FUN_14140f990(static_cast<CItem*>(p)) != 0)
    {
        InvenSlot* pSlot = FUN_140a50b50(FUN_1422cd070(static_cast<CItem*>(p)->FUN_140526b50()));
        if (pSlot != 0)
        {
            MS2Ptr<CItem> spCur = DAT_143ab2a90.FUN_140a5d680(static_cast<CItem*>(p)->FUN_140526a50());
            if (!(spCur == 0) && spCur->FUN_140526b50() == static_cast<CItem*>(p)->FUN_140526b50())
            {
                pSlot->SetItemUid(static_cast<CItem*>(p)->FUN_140526a50());
                pSlot->vfunc_10();
            }
        }
    }
}
MS2_REPLACE_METHOD_VIA(0x14140F340, InventorySlotBag, UIItemEventListener, vfunc_5, 309, 0x12B1DA22);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140f480
void InventorySlotBag::vfunc_21(void* p)
{
    if (FUN_14140f990(static_cast<CItem*>(p)) != 0 && m_nPendingSlot > -1)
    {
        InvenSlot* pSlot = FUN_140a50b50(FUN_1422cd070(m_nPendingSlot));
        if (pSlot != 0)
            pSlot->vfunc_10();
        m_nPendingSlot = -1;
    }
}
MS2_REPLACE_METHOD_VIA(0x14140F480, InventorySlotBag, UIItemEventListener, vfunc_21, 138, 0x690F69C0);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140f510
void InventorySlotBag::vfunc_22(void* p)
{
    if (FUN_14140f990(static_cast<CItem*>(p)) != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(static_cast<CItem*>(p)->FUN_140526a50());
        if (!spItem)
            return;
        m_nPendingSlot = spItem->FUN_140526b50();
    }
}
MS2_REPLACE_METHOD_VIA(0x14140F510, InventorySlotBag, UIItemEventListener, vfunc_22, 154, 0xA639BE3E);

// @0x14140f5b0
void InventorySlotBag::FUN_14140f5b0(CItem* pItem)
{
    if (FUN_14140f990(pItem) == 0)
        return;
    InvenSlot* pSlot = FUN_140a50b50(FUN_1422cd070(pItem->FUN_140526b50()));
    if (pSlot != 0)
        pSlot->vfunc_10();
}
MS2_REPLACE_METHOD(0x14140F5B0, InventorySlotBag, FUN_14140f5b0, 99, 0x1FDD6D27);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140f620
int InventorySlotBag::FUN_14140f620(CStringW strSearch)
{
    int nResult = -1;
    for (std::pair<const int, CString> entry : m_slots)
    {
        InvenSlot* pSlot = FUN_140a50b50(FUN_1422cd0f0(entry.second));
        if (pSlot != 0)
        {
            int nIndex = pSlot->FUN_14140bc50(strSearch);
            if (nIndex != -1)
            {
                if (nResult != -1 && nResult < nIndex)
                    nIndex = nResult;
                nResult = nIndex;
            }
        }
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x14140F620, InventorySlotBag, FUN_14140f620, 363, 0x78F08648);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140f7a0
ASDataProvider InventorySlotBag::FUN_14140f7a0()
{
    ASDataProvider arrNames(2);
    for (std::pair<const int, CString> entry : m_slots)
    {
        arrNames.FUN_1422bbf70(entry.second);
    }
    return ASDataProvider(arrNames);
}
MS2_REPLACE_METHOD(0x14140F7A0, InventorySlotBag, FUN_14140f7a0, 247, 0x17AB954B);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140f8a0
DragSlot* InventorySlotBag::vfunc_16(int nIndex)
{
    CString strName = static_cast<DragSlotBag*>(this)->vfunc_15(nIndex);
    __int64 nUid = FUN_14140fa00(nIndex, m_nTab);
    InvenSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) InvenSlot(strName, nIndex, nUid);
    return pSlot;
}
MS2_REPLACE_METHOD(0x14140F8A0, InventorySlotBag, vfunc_16, 221, 0x9FBDFB00);

// @0x14140f990
int InventorySlotBag::FUN_14140f990(CItem* pItem)
{
    return m_nTab == DAT_143ab2a90.FUN_140a617f0(MS2Ptr<CItem>(pItem));
}
MS2_REPLACE_METHOD(0x14140F990, InventorySlotBag, FUN_14140f990, 101, 0xBAE87DBE);

// MS2-FUNCTIONAL: equivalent control flow; branch order / temporaries differ (not tuned)
// @0x14140fa00
// The uid of the item at the slot index of an inventory tab (0: empty).
static __int64 FUN_14140fa00(int nIndex, int nTab)
{
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    DAT_143ab2a90.FUN_140a60880(nTab, items);
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
MS2_REPLACE(0x14140FA00, FUN_14140fa00, 303, 0x1FA59440);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb1740-0x142cb1ab0 .text$yd
