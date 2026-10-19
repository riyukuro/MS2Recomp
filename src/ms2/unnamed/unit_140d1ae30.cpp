// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: the item "use function" dispatch of the
// client. An item's <function name=...> selects one of the handlers registered by name in s_itemUseFuncs (0x143ac1a20);
// UseItem checks the item can be used now (cooldown, level, job, gender, VIP, binding), asks for a bind confirmation and
// runs the handler, which usually opens a dialog or a confirm box and finally sends the use request through the
// inventory. Handler names are the registration keys; the other function names are invented.
// MS2-UNIT: unit_140d1ae30
// MS2-RANGE: 0x1400d1f70-0x1400d2300 .text$di
// MS2-RANGE: 0x140d1ae30-0x140d2a7e0 .text$mn
// MS2-RANGE: 0x142ca49f0-0x142ca4bc0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <algorithm>
#include <map>
#include <vector>

#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/uiitemmultiopenboxdialog.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cshutdownevent.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cequipmentslotlayerinfo.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/client/ms2/cubespawnobject.h"
#include "ms2/client/ms2/uiitembillboarddialog.h"
#include "ms2/client/ms2/uiitemblueprintcreatedialog.h"
#include "ms2/client/ms2/uiugccubebilldialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

class Unk_ItemEquipData : public CItemData {};              // CItem::FUN_140527840's record (as commonfiles\item.cpp)
class Unk_ItemOwnerRef : public CItemTransfer {};           // CItem::FUN_140527930's transfer state

typedef Delegate<bool(int, const CMsgBoxData&)> Unk_IuBoxCallback;

// The handler of an item function: the item (by value, the handler destroys it) and the local player.
typedef int (*Unk_ItemUseFunc)(MS2Ptr<CItem> spItem, PC* pPlayer);

class Unk_RideeFieldObj;
class Unk_IuWorld
{
public:
    MyPC* FUN_141bd0cc0();                                  // the local player
    MS2Ptr<Unk_RideeFieldObj> FUN_141bc4f10(Unk_Entity* pEntity);   // the field object of an entity
    int FUN_141bd3060();                                    // the current field (map) id
};
Unk_IuWorld* FUN_1403ed2d0();
CUIService* FUN_1403ed2b0();

extern Unk_Inventory DAT_143ab2a90;                         // the player's inventory

// Notices and message boxes (unit_140d73aa0).
void FUN_140d73aa0(CStringW strText, int nType, void* pListener, CStringW strTag);
void FUN_140d73bc0(int nStringId, int nType, void* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* pListener, CStringW strTag);
void FUN_1412751f0(const CStringW& strText, int nA, int nB);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_1412752d0(const CStringW& strText, int n);

// String table texts.
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14028de60(int nStringId);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_140938ae0(CStringW strKey, const int& nArg);
CStringW FUN_1409e8970(CStringW strKey, const int& nA, const int& nB);
CStringW FUN_1409e8ca0(CStringW strKey, const int& n1, const int& n2, const int& n3, const int& n4, const int& n5);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
int FUN_14028cb70(const CStringW& strText, ATL::CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nExpected);
bool FUN_1407183f0(const CStringW& str);
int FUN_1407181a0(const CStringW& str);

// Item helpers.
bool FUN_1406343b0(MS2Ptr<CItem> spItem, const __int64* pCharacterId);   // the item is bound to another character
MS2Ptr<CItemData> FUN_14053f870(int nItemId);              // the item table record

// Time helpers.
__int64 FUN_140869440();                                    // the server time
int FUN_14086bcf0(__int64 nLastTime, int nDays);           // nDays passed since nLastTime (the "do not ask again" check)
void FUN_14086a7e0(CMsTime& time, int nDays);              // time += nDays
CStringW FUN_14086aec0(ATL::CTimeSpan span, int nDays, int nHours, int nMinutes, int nSeconds);
int FUN_14028e280(CMsTime& timeOut, const CStringA& strFormat, const CStringA& strText);

// The "blocked contents" flags of the client config.
class Unk_IuFlagSet { public: int FUN_1402c4c90(int nFlag); };
struct Unk_IuConfig
{
    void* m_p00;
    Unk_IuFlagSet m_flags;                                  // +0x08
};
Unk_IuConfig* FUN_14025e7b0();

// The drop table: the reward entries of a box.
class Unk_IuDropEntry
{
public:
    virtual int vfunc_0();                                  // 0 the item id
    virtual int vfunc_1();
    virtual unsigned vfunc_2();                             // 2 the count
    char m_pad_08[0x18];
    int m_nItemId;                                          // +0x20
    unsigned m_nCount;                                      // +0x28
};
class Unk_IuDropIter
{
public:
    Unk_IuDropEntry& FUN_1409ee3c0() const;                 // operator*
    Unk_IuDropIter& FUN_1409ee540();                        // operator++
    void* m_p;
};
bool operator!=(const Unk_IuDropIter& a, const Unk_IuDropIter& b);
class Unk_IuDropList
{
public:
    Unk_IuDropList();                                       // 0x1405a1910
    ~Unk_IuDropList();                                      // 0x1405a1a40
    Unk_IuDropIter FUN_1409efbb0();                         // begin
    Unk_IuDropIter FUN_1409eff60();                         // end
    void* m_begin;
    void* m_end;
    void* m_cap;
};
class Unk_IuDropParams
{
public:
    Unk_IuDropParams();                                     // 0x1402e9180
    int m_n0;
    int m_nLevel;                                           // +4
    int m_nJob;                                             // +8
    int m_pad[8];
};
class Unk_IuDropTable { public: void FUN_1402eaf10(int nBoxId, Unk_IuDropParams& params, Unk_IuDropList& out, int n); };
Unk_IuDropTable* FUN_1405a1fd0();
int FUN_1403bafd0(int nItemId);                             // the inventory tab of an item id
bool FUN_141900510(int nTab, __int64* pnAmount, __int64* pnCap);   // a currency-like tab and its amount/cap
class Unk_IuStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_IuStrings* FUN_1401a9d70();

// The quest scroll: the quest client manager.
class Unk_IuQuestList { public: int FUN_140745630(int nQuestId); };
class Unk_IuQuestMgr
{
public:
    virtual void vfunc_0();
    virtual int vfunc_1(int nQuestId, int n);               // 1 the quest can be accepted
    void* m_p08;
    Unk_IuQuestList m_list;                                 // +0x10
};
Unk_IuQuestMgr* FUN_140764020();

// ItemChangeBeauty: the field object the player stands on (ridee.cpp's view of the same COMDATs).
class Unk_IuBody;
Unk_IuBody* FUN_14166d220(PCBase* pActor);
class Unk_IuHitReport                                       // GameObjectControllerHitReport (its header pulls PhysX)
{
public:
    Unk_Entity* FUN_140cfaff0() const;                      // GetEntity
};
Unk_IuHitReport* FUN_141240f20(Unk_IuBody* pBody);
class Unk_RideeFieldObj : public CPtred
{
public:
    bool FUN_140ae0700();                                   // the object blocks the beauty change
};
int FUN_14166ce30(PC* pActor);                              // dead
int FUN_1416595d0(PC* pActor);
int FUN_141659690(PC* pActor);

// CreateReactor / FestivalEvent / BlueprintImport.
bool FUN_140b7a330(PC* pPlayer, int nReactorId);           // a reactor of that id can be placed here
class Unk_PbEventMgr { public: bool FUN_140cead80(CStringW strEvent); };   // the game event is running
Unk_PbEventMgr* FUN_14015a050();
void FUN_1404288d0(Unk_GameEventLockedValue<0x78>* pFestival, ATL::CAtlArray<MS2Ptr<FestivalContext> >& arrOut);   // CGameEventValueFestival::GetAll
int FUN_1406321d0(Unk_ItemUgcInfo* pUgc);                   // CItemUgc: the blueprint has no image yet
void FUN_141405440(MS2Ptr<CItem> spItem);                   // import the blueprint
class UIInventoryDialog : public UIDialog
{
public:
    bool FUN_14199ac30(int nButton, const CMsgBoxData& box);   // the couple effect receiver box result
};
UIInventoryDialog* FUN_1405344f0(int nId);                  // Unk_BreakDialog<UIInventoryDialog> (itembreakmanager.cpp)

// ---- the box helpers ----

void OpenItemBox(CItem* pItem, int nCount);
void OpenItemBoxSingle(CItem* pItem);
void OpenItemBoxContents(CItem* pItem, CStringW strArgs);
bool OnOpenItemBoxConfirm(int nButton, const CMsgBoxData& box);
bool OnOpenItemBoxCapacity(int nButton, const CMsgBoxData& box);
bool OnOpenItemBoxMulti(int nButton, const CMsgBoxData& box);
int UseItemCheckCapacity(CItem* pItem, CStringW& strTab, __int64* pnOver);

// The open dialog of a UI class id as T (13 instantiations at 0x140d27120..0x140d278a0).
template <class T> T* GetItemUseDialog(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0((eUIClassID)nId);
        if (spObject.get() != 0)
            return dynamic_cast<T*>(spObject.operator->());
    }
    return 0;
}

// ---- dynamic initializers (.text$di) ----

// @0x1400d1f70
static ATL::CAtlMap<CStringW, Unk_ItemUseFunc, ATL::CStringElementTraits<CStringW> > s_itemUseFuncs;
// @0x1400d1fc0
static std::map<unsigned, unsigned> s_itemUseMap;
// @0x1400d1ff0
static CStringW s_strChangeCharName(L"changeCharName");
// @0x1400d2020
static CStringW s_strChangeGuildName(L"changeGuildName");
// @0x1400d2050
static CStringW s_strOpenMassive(L"openMassive");
// @0x1400d2080
static CStringW s_strUseFunctionItem(L"use_function_item");
// @0x1400d20b0
static CStringW s_strUseBindFuncItem(L"useBindFuncItem");
// @0x1400d20e0
static CString s_sortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400d21a0
static CString s_strSkill = "skill";
// @0x1400d21d0
static CString s_strStun = "stun";
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
// @0x1400d2200
static Unk_1401cd100 s_pointer(NULL);
// @0x1400d2220
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
// @0x1400d2270
static UICommon::CMyPCKeyInputController s_keyInput;
// @0x1400d22a0
static CString s_warningGender = "system_notice_error_warningGender";
// @0x1400d22d0
static CString s_warningNotThisPlace = "system_notice_error_warningNotThisPlace";

// ---- the handlers ----

int OpenItemBox(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenItemBoxWithKey(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenDungeonItemBox(MS2Ptr<CItem> spItem, PC* pPlayer);
int CallAirTaxi(MS2Ptr<CItem> spItem, PC* pPlayer);
int CallMedic(MS2Ptr<CItem> spItem, PC* pPlayer);
int CallBlackMarket(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenBank(MS2Ptr<CItem> spItem, PC* pPlayer);
int LevelPotion(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenInstrument(MS2Ptr<CItem> spItem, PC* pPlayer);
int ExpandInven(MS2Ptr<CItem> spItem, PC* pPlayer);
int ChangeCharName(MS2Ptr<CItem> spItem, PC* pPlayer);
int ChangeGuildName(MS2Ptr<CItem> spItem, PC* pPlayer);
int ChangeGender(MS2Ptr<CItem> spItem, PC* pPlayer);
int ResetAbilityCoolTime(MS2Ptr<CItem> spItem, PC* pPlayer);
int RecallGuild(MS2Ptr<CItem> spItem, PC* pPlayer);
int RecallWedding(MS2Ptr<CItem> spItem, PC* pPlayer);
int RecallParty(MS2Ptr<CItem> spItem, PC* pPlayer);
int EnchantScroll(MS2Ptr<CItem> spItem, PC* pPlayer);
int FishingRod(MS2Ptr<CItem> spItem, PC* pPlayer);
int UGCMapPackage(MS2Ptr<CItem> spItem, PC* pPlayer);
int SelectItemBox(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenItemBoxLullu(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenPetBox(MS2Ptr<CItem> spItem, PC* pPlayer);
int ItemRemakeScroll(MS2Ptr<CItem> spItem, PC* pPlayer);
int ItemRePackingScroll(MS2Ptr<CItem> spItem, PC* pPlayer);
int PetTraining(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenWebPage(MS2Ptr<CItem> spItem, PC* pPlayer);
int ItemSocketScroll(MS2Ptr<CItem> spItem, PC* pPlayer);
int ItemExchangeScroll(MS2Ptr<CItem> spItem, PC* pPlayer);
int ItemExtraction(MS2Ptr<CItem> spItem, PC* pPlayer);
int PetExtraction(MS2Ptr<CItem> spItem, PC* pPlayer);
int QuestScroll(MS2Ptr<CItem> spItem, PC* pPlayer);
int ItemMergeRevert(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenMassive(MS2Ptr<CItem> spItem, PC* pPlayer);
int ItemActiveCodiTab(MS2Ptr<CItem> spItem, PC* pPlayer);
int ItemChangeBeauty(MS2Ptr<CItem> spItem, PC* pPlayer);
int InstallBillBoard(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenCoupleEffectBox(MS2Ptr<CItem> spItem, PC* pPlayer);
int SuperWorldChat(MS2Ptr<CItem> spItem, PC* pPlayer);
int CreateReactor(MS2Ptr<CItem> spItem, PC* pPlayer);
int FestivalEvent(MS2Ptr<CItem> spItem, PC* pPlayer);
int BlueprintImport(MS2Ptr<CItem> spItem, PC* pPlayer);
int ChatEmoticonAdd(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenItemBoxLimitedQuantity(MS2Ptr<CItem> spItem, PC* pPlayer);
int OpenGachaBox(MS2Ptr<CItem> spItem, PC* pPlayer);
int QuestStart(MS2Ptr<CItem> spItem, PC* pPlayer);

// @0x140d1ae30
void RegisterItemUseFuncs()
{
    s_itemUseFuncs.SetAt(L"OpenItemBox", OpenItemBox);
    s_itemUseFuncs.SetAt(L"OpenItemBoxWithKey", OpenItemBoxWithKey);
    s_itemUseFuncs.SetAt(L"OpenDungeonItemBox", OpenDungeonItemBox);
    s_itemUseFuncs.SetAt(L"CallAirTaxi", CallAirTaxi);
    s_itemUseFuncs.SetAt(L"CallMedic", CallMedic);
    s_itemUseFuncs.SetAt(L"CallBlackMarket", CallBlackMarket);
    s_itemUseFuncs.SetAt(L"OpenBank", OpenBank);
    s_itemUseFuncs.SetAt(L"LevelPotion", LevelPotion);
    s_itemUseFuncs.SetAt(L"OpenInstrument", OpenInstrument);
    s_itemUseFuncs.SetAt(L"ExpandInven", ExpandInven);
    s_itemUseFuncs.SetAt(L"ChangeCharName", ChangeCharName);
    s_itemUseFuncs.SetAt(L"ChangeGuildName", ChangeGuildName);
    s_itemUseFuncs.SetAt(L"ChangeGender", ChangeGender);
    s_itemUseFuncs.SetAt(L"ResetAbilityCoolTime", ResetAbilityCoolTime);
    s_itemUseFuncs.SetAt(L"RecallGuild", RecallGuild);
    s_itemUseFuncs.SetAt(L"RecallWedding", RecallWedding);
    s_itemUseFuncs.SetAt(L"RecallParty", RecallParty);
    s_itemUseFuncs.SetAt(L"EnchantScroll", EnchantScroll);
    s_itemUseFuncs.SetAt(L"FishingRod", FishingRod);
    s_itemUseFuncs.SetAt(L"UGCMapPackage", UGCMapPackage);
    s_itemUseFuncs.SetAt(L"SelectItemBox", SelectItemBox);
    s_itemUseFuncs.SetAt(L"OpenItemBoxLullu", OpenItemBoxLullu);
    s_itemUseFuncs.SetAt(L"OpenItemBoxLulluSimple", OpenItemBoxLullu);
    s_itemUseFuncs.SetAt(L"OpenPetBox", OpenPetBox);
    s_itemUseFuncs.SetAt(L"ItemRemakeScroll", ItemRemakeScroll);
    s_itemUseFuncs.SetAt(L"ItemRePackingScroll", ItemRePackingScroll);
    s_itemUseFuncs.SetAt(L"PetTraining", PetTraining);
    s_itemUseFuncs.SetAt(L"OpenWebPage", OpenWebPage);
    s_itemUseFuncs.SetAt(L"ItemSocketScroll", ItemSocketScroll);
    s_itemUseFuncs.SetAt(L"ItemExchangeScroll", ItemExchangeScroll);
    s_itemUseFuncs.SetAt(L"ItemExtraction", ItemExtraction);
    s_itemUseFuncs.SetAt(L"PetExtraction", PetExtraction);
    s_itemUseFuncs.SetAt(L"QuestScroll", QuestScroll);
    s_itemUseFuncs.SetAt(L"ItemMergeRevert", ItemMergeRevert);
    s_itemUseFuncs.SetAt(L"OpenMassive", OpenMassive);
    s_itemUseFuncs.SetAt(L"ItemActiveCodiTab", ItemActiveCodiTab);
    s_itemUseFuncs.SetAt(L"ItemChangeBeauty", ItemChangeBeauty);
    s_itemUseFuncs.SetAt(L"InstallBillBoard", InstallBillBoard);
    s_itemUseFuncs.SetAt(L"OpenCoupleEffectBox", OpenCoupleEffectBox);
    s_itemUseFuncs.SetAt(L"SuperWorldChat", SuperWorldChat);
    s_itemUseFuncs.SetAt(L"WeddingChat", SuperWorldChat);
    s_itemUseFuncs.SetAt(L"TreasureMap", RecallParty);
    s_itemUseFuncs.SetAt(L"CreateReactor", CreateReactor);
    s_itemUseFuncs.SetAt(L"FestivalEvent", FestivalEvent);
    s_itemUseFuncs.SetAt(L"BlueprintImport", BlueprintImport);
    s_itemUseFuncs.SetAt(L"ChatEmoticonAdd", ChatEmoticonAdd);
    s_itemUseFuncs.SetAt(L"OpenItemBoxLimitedQuantity", OpenItemBoxLimitedQuantity);
    s_itemUseFuncs.SetAt(L"OpenGachaBox", OpenGachaBox);
    s_itemUseFuncs.SetAt(L"QuestStart", QuestStart);
}

// Can the local player use the item now (cooldown, item lock, PC bang / VIP / wedding items, level, job, gender,
// character binding)? Shows the reason when not.
// @0x140d1b610
bool CanUseItem(MS2Ptr<CItem> spItem)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (pPlayer->FUN_141523bc0()->FUN_141765fe0(spItem->FUN_140527840()->FUN_14053dc20(), 0) != 0.0f)
    {
        FUN_140d73bc0(0x55, 0, 0, L"");
        return false;
    }
    if (!spItem->FUN_140528980())
    {
        if (spItem->FUN_140528930())
            FUN_140d73bc0(0xe1, 0, 0, L"");
        else
            FUN_140d73bc0(0xea, 0, 0, L"");
        return false;
    }
    if (spItem->FUN_140525ca0() != 0 && pPlayer->FUN_141658f30() == 0)
    {
        FUN_140d73bc0(0xe2, 0, 0, L"");
        return false;
    }
    if (spItem->FUN_140525db0() != 0 && pPlayer->FUN_141662de0() == 0)
    {
        FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_puton_vip"), 0, 0, L"");
        return false;
    }
    if (spItem->FUN_140525e00() != 0 && !pPlayer->vfunc_146())
    {
        FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_puton_wedding"), 0, 0, L"");
        return false;
    }
    if (!spItem->FUN_140526810((unsigned short)pPlayer->vfunc_78()))
    {
        FUN_1412751f0(FUN_14028b8e0(L"s_err_not_enough_level"), 1, 1);
        return false;
    }
    if (!spItem->FUN_140526790(pPlayer->FUN_141654700()))
    {
        FUN_140d73aa0(FUN_14028b8e0(L"s_item_err_disable_job"), 0, 0, L"");
        return false;
    }
    if (!spItem->FUN_1405267d0(pPlayer->FUN_141658e60()))
    {
        FUN_140d73bc0(0x2d, 0, 0, L"");
        return false;
    }
    __int64 nCharacterId = pPlayer->FUN_141656a80();
    if (!FUN_1406343b0(spItem, &nCharacterId))
    {
        FUN_140d73bc0(0xfe, 0, 0, L"");
        return false;
    }
    return true;
}

// Use an item: checks, the bind-on-use confirmation (unless bConfirmed), then the item function's handler; an item
// without a registered handler is sent to the server as is.
// @0x140d1bd60
int UseItem(MS2Ptr<CItem> spItem, int bConfirmed)
{
    if (!CanUseItem(spItem))
        return 0;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (spItem->FUN_140527840() == 0)
        return 0;
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownFunctionItem()->FUN_1407d0dc0(spItem->FUN_140527840()->FUN_14053c510()) == true)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    if (DAT_143ab2a90.FUN_140a661e0(spItem.get()) == 0)
        return 0;
    if (bConfirmed == 0 && spItem->FUN_140527930()->FUN_140635100() != 0 && spItem->FUN_140527930()->FUN_140635120() == 0)
    {
        CStringW strMsg = FUN_1405c2690(L"s_msg_transfer_bind_when_use", pPlayer->vfunc_77());
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, strMsg, 0, s_strUseBindFuncItem);
        if (spBox.get())
        {
            spBox->FUN_141a01600(spItem->FUN_140526a50());
            spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
            spBox->FUN_141a01700(0x477, 0x478, 0);
            FUN_140d73c60(spBox);
            return 1;
        }
    }
    if (s_itemUseFuncs.GetCount() == 0)
        RegisterItemUseFuncs();
    CStringW strFunction = spItem->FUN_140527840()->function.name;
    Unk_ItemUseFunc pfnUse = 0;
    if (!s_itemUseFuncs.Lookup(strFunction, pfnUse))
    {
        DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
        return 1;
    }
    return pfnUse(spItem, pPlayer);
}

// Use an item of an inventory slot once its cooldown is over.
class Unk_IuSlot { public: float FUN_141409060(); };        // the cooldown left of the slot item's skill
// @0x140d1c3a0
int UseSlotItem(Unk_IuSlot* pSlot, MS2Ptr<CItem> spItem)
{
    if (pSlot->FUN_141409060() > 0.0f)
    {
        FUN_140d73bc0(0x55, 0, 0, L"");
        return 0;
    }
    return UseItem(spItem, 0);
}

// The "do not ask again" check box of a confirm box ("<button>,<checked>" in the box text).
// @0x140d1c470
bool IsBoxNotAgainChecked(const CMsgBoxData& box)
{
    ATL::CAtlArray<CStringW> arrFields;
    if (FUN_14028cb70(box.FUN_141a02d50(), arrFields, L",", 2) == 0)
        return false;
    return FUN_1407183f0(arrFields[1]);
}

// Would opening the box overflow a currency-like inventory tab? Returns the tab name and the overflow.
// @0x140d1c550
int UseItemCheckCapacity(CItem* pItem, CStringW& strTab, __int64* pnOver)
{
    Unk_IuDropList drops;
    Unk_IuDropParams params;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        params.m_nJob = pPlayer->FUN_141658e60();
        params.m_nLevel = pPlayer->FUN_141654700();
    }
    Unk_ItemEquipData* pRecord = pItem->FUN_140527840();
    if (pRecord->function.parameter.FUN_1408d2380() != 0)
    {
        int nBoxId = 0;
        if (pRecord->function.name == L"OpenItemBox")
            nBoxId = pRecord->function.arg0;
        else if (pRecord->function.name == L"OpenItemBoxWithKey")
            nBoxId = pRecord->function.parameter.FUN_1408d1fd0(5, 0);
        FUN_1405a1fd0()->FUN_1402eaf10(nBoxId, params, drops, 0);
    }
    for (Unk_IuDropIter it = drops.FUN_1409efbb0(); it != drops.FUN_1409eff60(); it.FUN_1409ee540())
    {
        Unk_IuDropEntry& entry = it.FUN_1409ee3c0();
        MS2Ptr<CItemData> spData = FUN_14053f870(entry.m_nItemId);
        if (spData == 0)
            continue;
        int nItemId = entry.vfunc_0();
        unsigned nCount = entry.vfunc_2();
        int nTab = FUN_1403bafd0(nItemId);
        if (nTab == 0x11)
            continue;
        __int64 nAmount = 0;
        __int64 nCap = 0;
        if (!FUN_141900510(nTab, &nAmount, &nCap))
            continue;
        if (nTab == 0x10)
            continue;
        nCount = (std::max)(nCount, entry.m_nCount);
        if (nCap < (__int64)(nCount + nAmount))
        {
            *pnOver = (nCount + nAmount) - nCap;
            strTab = FUN_1401a9d70()->FUN_141811980(1, nItemId);
            return 1;
        }
    }
    return 0;
}

// The quest scroll confirm box: accept the scroll's quests (when none is in progress and all can be accepted).
// @0x140d1c8e0
bool OnQuestScrollConfirm(int nButton, const CMsgBoxData& box)
{
    if (nButton != 0)
        return true;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(box.FUN_141a02f10(0, 0));
    if (spItem.IsNull())
        return true;
    std::vector<int> quests = spItem->FUN_140527840()->function.xml.FUN_1409e8620(L"questID", std::vector<int>());
    for (size_t i = 0; i < quests.size(); i++)
    {
        if (FUN_140764020()->m_list.FUN_140745630(quests[i]) != 0)
        {
            FUN_140d73bc0(0x5f3, 0, 0, L"");
            return true;
        }
        if (FUN_140764020()->vfunc_1(quests[i], 0) == 0)
        {
            FUN_140d73bc0(0x5f4, 0, 0, L"");
            return true;
        }
    }
    DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
    return true;
}

// Open a box item: confirm first unless the player chose "do not ask again" in the last 7 days.
// @0x140d1cbd0
void OpenItemBox(CItem* pItem, int nCount)
{
    if (FUN_14086bcf0(TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n10Time, 7) == 0)
    {
        OpenItemBoxSingle(pItem);
        return;
    }
    CStringW strMsg;
    if (nCount < 2)
    {
        CStringW strKey = pItem->FUN_140527840()->function.xml.FUN_14042cad0(L"notifyBox", L"s_msg_item_open_item_box");
        strMsg = FUN_14028b8e0(strKey);
    }
    else
    {
        int nHave = DAT_143ab2a90.FUN_140a5f180(pItem->FUN_1405276c0(), 0);
        strMsg = FUN_1409e8970(L"s_msg_item_open_item_box_multi", nHave, nCount);
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, strMsg, 0, L"");
    if (spBox.get())
    {
        spBox->FUN_141a027c0(Unk_IuBoxCallback(OnOpenItemBoxConfirm));
        spBox->FUN_141a01600(pItem->FUN_140526a50());
        spBox->FUN_141a01ee0(MS2Ptr<CItem>(pItem), pItem->FUN_140527b10(), 1, 0, -1, -1, 1);
        spBox->FUN_141a01800(1);
        spBox->FUN_141a024e0(FUN_14028de60(0x29e), 0);
        FUN_140d73c60(spBox);
    }
}

// Open one box: warn first when a currency tab would overflow (unless "do not ask again" in the last 7 days).
// @0x140d1d060
void OpenItemBoxSingle(CItem* pItem)
{
    __int64 nOver = 0;
    CStringW strTab;
    if (UseItemCheckCapacity(pItem, strTab, &nOver) != 0
        && FUN_14086bcf0(TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n18Time, 7) != 0)
    {
        CStringW strMsg = FUN_14052bd00(0x2a7, strTab);
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, strMsg, 0, L"");
        if (spBox.get())
        {
            spBox->FUN_141a027c0(Unk_IuBoxCallback(OnOpenItemBoxCapacity));
            spBox->FUN_141a01600(pItem->FUN_140526a50());
            spBox->FUN_141a01ee0(MS2Ptr<CItem>(pItem), pItem->FUN_140527b10(), 1, 0, -1, -1, 1);
            spBox->FUN_141a01800(2);
            spBox->FUN_141a024e0(FUN_14028de60(0x29e), 0);
            FUN_140d73c60(spBox);
        }
        return;
    }
    OpenItemBoxContents(pItem, L"");
}

// Send the open request; boxes that allow it ask for the count to open at once.
// @0x140d1d3f0
void OpenItemBoxContents(CItem* pItem, CStringW strArgs)
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x6e) != 0)
    {
        DAT_143ab2a90.FUN_140a63880(pItem, strArgs);
        return;
    }
    int nMultiOpen = pItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(4, 1);
    int bSingle = pItem->FUN_140529640();
    int nCount = DAT_143ab2a90.FUN_140a5f410(MS2Ptr<CItem>(pItem));
    if (nCount < 0)
        nCount = 0;
    if (*TSingleton<Client::Constants>::GetInstance()->ItemBoxMultiOpenLimitCount.Get() < nCount)
        nCount = *TSingleton<Client::Constants>::GetInstance()->ItemBoxMultiOpenLimitCount.Get();
    if (bSingle != 0)
        nCount = 1;
    if (nMultiOpen == 1 && nCount > 1)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x29, FUN_140298ea0(L"s_msg_item_open_item_box_multiopen_msg"), 0, L"");
        if (spBox.get())
        {
            MS2Ptr<CMsgBoxDataItem> spEntry(new CMsgBoxDataItem);
            int nRarity = pItem->FUN_140526bd0();
            spEntry->FUN_141a06630(pItem->FUN_140527b10(), true, nRarity);
            spEntry->m_nUnitCount = 1;
            spEntry->m_nCount = nCount;
            spEntry->m_nMax = nCount;
            spEntry->m_spItem.AssignRaw(pItem);
            spBox->FUN_141a01e60(spEntry);
            spBox->FUN_141a015d0(FUN_14028b8e0(L"s_msg_item_open_item_box_multiopen_title"));
            spBox->FUN_141a01690(FUN_14028b8e0(L"s_msg_item_open_item_box_multiopen_ok"), FUN_14028b8e0(L"s_word_cancel"), L"");
            spBox->FUN_140b76940(strArgs);
            spBox->FUN_141a027c0(Unk_IuBoxCallback(OnOpenItemBoxMulti));
            spBox->FUN_141a024a0(0);
            spBox->FUN_141a01600(pItem->FUN_140526a50());
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        DAT_143ab2a90.FUN_140a63880(pItem, strArgs);
    }
}

// @0x140d1da90
bool OnOpenItemBoxConfirm(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        if (IsBoxNotAgainChecked(box))
        {
            TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n10Time = FUN_140869440();
            TSingleton<CGameOption>::GetInstance()->FUN_141243540();
        }
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(box.FUN_141a02c20());
        if (spItem.get() != 0)
            OpenItemBoxSingle(spItem.get());
    }
    return true;
}

// @0x140d1db60
bool OnOpenItemBoxCapacity(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        if (IsBoxNotAgainChecked(box))
        {
            TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n18Time = FUN_140869440();
            TSingleton<CGameOption>::GetInstance()->FUN_141243540();
        }
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(box.FUN_141a02c20());
        if (spItem.get() != 0)
            OpenItemBoxContents(spItem.get(), L"");
    }
    return true;
}

// The multi-open count box: open that many boxes (through the multi open dialog for more than one).
// @0x140d1dc60
bool OnOpenItemBoxMulti(int nButton, const CMsgBoxData& box)
{
    if (nButton != 0)
        return true;
    __int64 nItemUid = box.FUN_141a02c20();
    CStringW strArgs = box.FUN_141a02fd0(0, CStringW());
    ATL::CAtlArray<CStringW> arrFields;
    if (FUN_14028cb70(box.FUN_141a02d50(), arrFields, L",", 2) == 0)
        return true;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
    if (spItem.IsNull())
        return true;
    int nCount = FUN_1407181a0(arrFields[1]);
    if (nCount < 0)
        nCount = 0;
    if (*TSingleton<Client::Constants>::GetInstance()->ItemBoxMultiOpenLimitCount.Get() < nCount)
        nCount = *TSingleton<Client::Constants>::GetInstance()->ItemBoxMultiOpenLimitCount.Get();
    if (nCount < 2)
    {
        DAT_143ab2a90.FUN_140a63880(spItem.get(), strArgs);
    }
    else
    {
        UIItemMultiOpenBoxDialog* pDialog = GetItemUseDialog<UIItemMultiOpenBoxDialog>(0x4f88);
        if (pDialog != 0 && pDialog->FUN_141924630() == 0)
            pDialog->FUN_140c3f9d0(spItem->FUN_1405276c0(), spItem->FUN_140526bd0(), strArgs, nCount);
    }
    return true;
}

// @0x140d1df70
int RecallParty(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    return 1;
}

// The codi (outfit) tab item: activate the tab or extend its period.
// @0x140d1dfa0
int ItemActiveCodiTab(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (spItem == 0)
        return 0;
    if (spItem->FUN_140527840() == 0 || pPlayer == 0)
        return 0;
    int nDays = spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(0, 0);
    MS2Ptr<CEquipmentSlotLayerInfo> spTitle = pPlayer->FUN_1416561a0()->GetTitle();
    if (spTitle == 0)
        return 0;
    unsigned nState = spTitle->FUN_1411df830();
    if (nState == 0)
        return 0;
    CStringW strMsg;
    bool bLimitless = nDays == 0;
    if (nState == 2)
    {
        FUN_140d73aa0(FUN_14028b8e0(L"s_msg_item_active_codi_tab_already_limitless"), 0, 0, L"");
        return 1;
    }
    if (nState == 1)
    {
        if (bLimitless)
        {
            strMsg = FUN_14028b8e0(L"s_msg_item_active_codi_tab_already_period_use_limitless");
        }
        else
        {
            CMsTime end(spTitle->m_end);
            FUN_14086a7e0(end, nDays);
            CMsTime newEnd(end);
            CMsTime start(spTitle->m_start);
            ATL::CTimeSpan span(newEnd.Get() - start.Get());
            unsigned nSpan = (unsigned)span.GetDays();
            unsigned nMax = spTitle->FUN_1411df8e0();
            if (nMax < nSpan || (nSpan == nMax && span.GetSeconds() > 0))
            {
                FUN_140d73aa0(FUN_140938ae0(L"s_msg_item_active_codi_tab_max", (int)nMax), 0, 0, L"");
                return 1;
            }
            strMsg = FUN_140938ae0(L"s_msg_item_active_codi_tab_add_period", nDays);
        }
    }
    else if (bLimitless)
    {
        strMsg = FUN_14028b8e0(L"s_msg_item_active_codi_tab_limitless");
    }
    else
    {
        strMsg = FUN_140938ae0(L"s_msg_item_active_codi_tab_period", nDays);
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, strMsg, 0, s_strUseFunctionItem);
    if (spBox.get() != 0)
    {
        spBox->FUN_141a01600(spItem->FUN_140526a50());
        spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
        spBox->FUN_141a024a0(0);
        spBox->FUN_141a01700(0x477, 0x478, 0);
        FUN_140d73c60(spBox);
        return 1;
    }
    return 1;
}

// The beauty change item: only while the player stands normally, outside a beauty-blocking field object.
// @0x140d1e8d0
int ItemChangeBeauty(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (spItem == 0)
        return 0;
    if (spItem->FUN_140527840() == 0 || pPlayer == 0)
        return 0;
    if (spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(0, 0) == 0)
        return 0;
    if (pPlayer->FUN_14123c260() <= 0.9f || pPlayer->FUN_14123c260() >= 1.1f)
    {
        FUN_1412752d0(L"s_msg_item_err_change_beauty_invalid_state", 1);
        return 0;
    }
    if (FUN_14166ce30(pPlayer) != 0 || pPlayer->vfunc_65() != 0 || FUN_1416595d0(pPlayer) != 0 || FUN_141659690(pPlayer) != 0)
    {
        FUN_1412752d0(L"s_msg_item_err_change_beauty_invalid_state", 1);
        return 0;
    }
    Unk_EntRef spEntity(FUN_141240f20(FUN_14166d220(pPlayer))->FUN_140cfaff0());
    if (spEntity != 0)
    {
        MS2Ptr<Unk_RideeFieldObj> spObj = FUN_1403ed2d0()->FUN_141bc4f10(spEntity.FUN_1408a9090());
        if (spObj.get() != 0 && spObj->FUN_140ae0700())
        {
            FUN_1412752d0(L"s_msg_item_err_change_beauty_invalid_state", 1);
            return 0;
        }
    }
    if (static_cast<MyPC*>(pPlayer)->FUN_141527160(0x25) == 0)
    {
        FUN_1412752d0(L"s_msg_item_err_change_beauty_invalid_state", 1);
        return 0;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, FUN_14028b8e0(L"s_msg_item_change_beauty"), 0, s_strUseFunctionItem);
    if (spBox.get() != 0)
    {
        spBox->FUN_141a01600(spItem->FUN_140526a50());
        spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
        spBox->FUN_141a024a0(0);
        spBox->FUN_141a01700(0x477, 0x478, 0);
        FUN_140d73c60(spBox);
        return 1;
    }
    return 0;
}

// @0x140d1ef50
int CreateReactor(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (!FUN_140b7a330(pPlayer, spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(0, 0)))
        return 0;
    static_cast<MyPC*>(pPlayer)->FUN_14152e0c0();
    return DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
}

// The festival item: only in its fields and while its game event (and festival kind) runs.
// @0x140d1f030
int FestivalEvent(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    int nFieldId = FUN_1403ed2d0()->FUN_141bd3060();
    std::vector<int> vFields = spItem->FUN_140527840()->function.xml.FUN_1409e8620(L"fieldID", std::vector<int>());
    bool bValid = false;
    for (size_t i = 0; i < vFields.size(); ++i)
    {
        if (vFields[i] == 0 || vFields[i] == nFieldId)
        {
            bValid = true;
            break;
        }
    }
    if (!bValid)
    {
        FUN_140d73aa0(FUN_140298ea0(L"s_item_invalid_function_item_this_field"), 0, 0, L"");
        return 0;
    }
    CStringW strEvent = spItem->FUN_140527840()->function.xml.FUN_14042cad0(L"gameEvent", L"");
    if (!FUN_14015a050()->FUN_140cead80(strEvent))
    {
        FUN_140d73aa0(FUN_140298ea0(L"s_item_invalid_function_item_event_not_start"), 0, 0, L"");
        return 0;
    }
    int nDefault = 0;
    int nUseType = spItem->FUN_140527840()->function.xml.GetInt(L"itemUseType", nDefault);
    ATL::CAtlArray<MS2Ptr<FestivalContext> > arrFestivals;
    FUN_1404288d0(TSingleton<CGameEventValueManager>::GetInstance()->GetFestival(), arrFestivals);
    bValid = false;
    for (size_t i = 0; i < arrFestivals.GetCount(); ++i)
    {
        if (arrFestivals[i].get() != 0)
        {
            if (nUseType == 0 || arrFestivals[i]->m_1c == nUseType)
            {
                bValid = true;
                break;
            }
        }
    }
    if (bValid)
    {
        DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
        return 1;
    }
    FUN_140d73aa0(FUN_140298ea0(L"s_item_invalid_function_not_use_item"), 0, 0, L"");
    return 0;
}

// The blueprint item: create its image first, else confirm and import it.
// @0x140d1f6d0
int BlueprintImport(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (spItem == 0)
        return 0;
    Unk_ItemUgcInfo* pUgc = spItem->FUN_1405278d0();
    if (pUgc == 0)
        return 0;
    if (pUgc->m_nUgcUid == 0)
    {
        if (FUN_1406321d0(pUgc) == 0)
        {
            UIItemBlueprintCreateDialog* pDialog = GetItemUseDialog<UIItemBlueprintCreateDialog>(0x4f7b);
            if (pDialog != 0 && pDialog->vfunc_55() != 0)
                pDialog->FUN_140c36fe0(spItem->FUN_140526a50());
        }
        else
        {
            FUN_141405440(spItem);
        }
    }
    else
    {
        UIUGCCubeBillDialog* pDialog = GetItemUseDialog<UIUGCCubeBillDialog>(0x4f29);
        if (pDialog != 0)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, FUN_1405c2690(L"s_msg_item_open_blueprint", spItem->FUN_140527b10()), 0, s_strUseFunctionItem);
            if (spBox.get() != 0)
            {
                spBox->FUN_141a01600(spItem->FUN_140526a50());
                spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
                spBox->FUN_141a024a0(0);
                spBox->FUN_141a01700(0x477, 0x478, 0);
                spBox->FUN_141a027c0(Unk_IuBoxCallback(pDialog, &UIUGCCubeBillDialog::FUN_140ee8000));
                FUN_140d73c60(spBox);
            }
        }
    }
    return 1;
}

// The chat emoticon item: describe its period and confirm.
// @0x140d1fba0
int ChatEmoticonAdd(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    CStringW strMsg = FUN_1405c2690(L"s_msg_chat_emoticon_item_use_description", spItem->FUN_140527b10());
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    if (!spData)
        return 0;
    CXmlData* pXml = &spData->function.xml;
    if (pXml->FUN_14092c5f0(L"endDate"))
    {
        CString strDate = pXml->FUN_1409e8560(L"endDate", "");
        CMsTime end;
        if (FUN_14028e280(end, "%04d-%02d-%02d-%02d-%02d-%02d", strDate) == 0)
            return 0;
        strMsg += FUN_1409e8ca0(L"s_msg_chat_emoticon_item_use_description_enddate", end.GetYear(), end.GetMonth(), end.GetDay(), end.GetHour(), end.GetMinute());
    }
    else if (pXml->FUN_14092c5f0(L"durationSec"))
    {
        __int64 nDefault = 0;
        ATL::CTimeSpan span(pXml->FUN_1409e86e0(L"durationSec", nDefault));
        strMsg += FUN_1405c2690(L"s_msg_chat_emoticon_item_use_description_duration", FUN_14086aec0(span, 1, 1, 1, 1));
    }
    strMsg += FUN_140298ea0(L"s_msg_chat_emoticon_item_use_description_warning");
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, strMsg, 0, s_strUseFunctionItem);
    if (spBox.get() == 0)
        return 1;
    spBox->FUN_141a01600(spItem->FUN_140526a50());
    spBox->FUN_141a020b0(spItem->FUN_1405276c0(), spItem->FUN_140526bd0(), 0);
    spBox->FUN_141a01700(0x477, 0x478, 0);
    FUN_140d73c60(spBox);
    return 1;
}

// The super world chat (and wedding chat) item: ask the server to open the chat.
// @0x140d20350
int SuperWorldChat(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    int nItemId = spItem->FUN_1405276c0();
    COutPacket packet(0xa7, 0);
    packet.vfunc_o10_1(0);
    packet.vfunc_o10_3(nItemId);
    FUN_140710590(packet);
    return 1;
}

// The couple effect box: ask for the receiver's name.
// @0x140d203f0
int OpenCoupleEffectBox(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIInventoryDialog* pDialog = FUN_1405344f0(0x4e2d);
    if (pDialog != 0)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, FUN_14028b8e0(L"s_coupleeffect_recevie_name"), 0, L"");
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01d30(2, L"", 0xc, 0, 0);
            spBox->FUN_141a01600(spItem->FUN_140526a50());
            spBox->FUN_141a027c0(Unk_IuBoxCallback(pDialog, &UIInventoryDialog::FUN_14199ac30));
            FUN_140d73c60(spBox);
        }
    }
    return 1;
}

// @0x140d20690
int InstallBillBoard(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIItemBillBoardDialog* pDialog = GetItemUseDialog<UIItemBillBoardDialog>(0x4f4f);
    if (pDialog != 0 && pDialog->FUN_140c323f0() == true)
        pDialog->FUN_140c32360(spItem->FUN_140526a50());
    return 1;
}
