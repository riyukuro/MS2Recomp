// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: the item "use function" dispatch of the
// client. An item's <function name=...> selects one of the handlers registered by name in s_itemUseFuncs (0x143ac1a20);
// UseItem checks the item can be used now (cooldown, level, job, gender, VIP, binding), asks for a bind confirmation and
// runs the handler, which usually opens a dialog or a confirm box and finally sends the use request through the
// inventory. Handler names are the registration keys; the other function names are invented.
// MS2-UNIT: unit_140d1ae30
// MS2-RANGE: 0x1400d1f70-0x1400d2300 .text$di
// MS2-RANGE: 0x140d1ae30-0x140d2a7e0 .text$mn
// MS2-RANGE: 0x142ca49f0-0x142ca4bc0 .text$yd
// MS2-PIN: memcpy_s 0x140d2a6c0
// MS2-PIN: ??$GetItemUseDialog@VUIInteriorBuildDialog@@@@YAPEAVUIInteriorBuildDialog@@H@Z 0x140d27120
// MS2-PIN: ??$GetItemUseDialog@VUIItemBillBoardDialog@@@@YAPEAVUIItemBillBoardDialog@@H@Z 0x140d271c0
// MS2-PIN: ??$GetItemUseDialog@VUIItemBlueprintCreateDialog@@@@YAPEAVUIItemBlueprintCreateDialog@@H@Z 0x140d27260
// MS2-PIN: ??$GetItemUseDialog@VUIItemExtractionScrollDialog@@@@YAPEAVUIItemExtractionScrollDialog@@H@Z 0x140d27300
// MS2-PIN: ??$GetItemUseDialog@VUIItemGachaBoxDialog@@@@YAPEAVUIItemGachaBoxDialog@@H@Z 0x140d273a0
// MS2-PIN: ??$GetItemUseDialog@VUIItemLulluBoxDialog@@@@YAPEAVUIItemLulluBoxDialog@@H@Z 0x140d27440
// MS2-PIN: ??$GetItemUseDialog@VUIItemMergeRevertDialog@@@@YAPEAVUIItemMergeRevertDialog@@H@Z 0x140d274e0
// MS2-PIN: ??$GetItemUseDialog@VUIItemMultiOpenBoxDialog@@@@YAPEAVUIItemMultiOpenBoxDialog@@H@Z 0x140d27580
// MS2-PIN: ??$GetItemUseDialog@VUIItemPetBoxDialog@@@@YAPEAVUIItemPetBoxDialog@@H@Z 0x140d27620
// MS2-PIN: ??$GetItemUseDialog@VUIItemPetTrainingDialog@@@@YAPEAVUIItemPetTrainingDialog@@H@Z 0x140d276c0
// MS2-PIN: ??$GetItemUseDialog@VUIPetExtractionScrollDialog@@@@YAPEAVUIPetExtractionScrollDialog@@H@Z 0x140d27760
// MS2-PIN: ??$GetItemUseDialog@VUISelectItemBoxDialog@@@@YAPEAVUISelectItemBoxDialog@@H@Z 0x140d27800
// MS2-PIN: ??$GetItemUseDialog@VUIUGCCubeBillDialog@@@@YAPEAVUIUGCCubeBillDialog@@H@Z 0x140d278a0
#define MS2_THIS_FILE ""
// The exe's memcpy_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memcpy)
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
#include "ms2/placeholder/ccashcallmanager.h"
#include "ms2/placeholder/fishingmanager.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/uiinteriorbuilddialog.h"
#include "ms2/client/ms2/uiitemexchangescrolldialog.h"
#include "ms2/client/ms2/uiitemextractionscrolldialog.h"
#include "ms2/client/ms2/uiitemlulluboxdialog.h"
#include "ms2/client/ms2/uiitemmergerevertdialog.h"
#include "ms2/client/ms2/uiavatarbase.h"               // UIAvatarPet (uiitempetboxdialog.h inline ctor)
#include "ms2/client/ms2/uiitempetboxdialog.h"
#include "ms2/client/ms2/uiitempettrainingdialog.h"
#include "ms2/client/ms2/uiselectitemboxdialog.h"
#include "ms2/client/ms2/uiwebbrowser.h"
#include "ms2/client/ms2/costumemanager.h"           // fittingdollpc.h inline FUN_1409763e0 copies MS2Ptr<CostumeManager>
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/client/ms2/stateplayinstrumentdata.h"
#include "ms2/client/ms2/portal.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/client/ms2/dungeonrecordcli.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/uiitemgachaboxdialog.h"
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
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                  // the current field's data
    void FUN_141bc2c90(NiPoint3 kPos, ATL::CAtlArray<void*>& arrOut);   // the portals containing a position
    void FUN_141bc2980(std::vector<int>& vOut);             // the portal ids of the field
    MS2Ptr<CPortal> FUN_141bc2800(int nId);                 // a portal by id
    int FUN_141bdb660(int nKind);                           // the field forbids the play kind
    bool FUN_141bcada0(__int64 nCharacterId);               // the player is registered for the instrument play
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
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nStringId);
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

// The drop table: the reward entries of a box (commonfiles/itemdroptable.h).
ItemDropTable* FUN_1405a1fd0();
int FUN_1403bafd0(int nItemId);                             // the inventory tab of an item id
bool FUN_141900510(int nTab, __int64* pnAmount, __int64* pnCap);   // a currency-like tab and its amount/cap
class Unk_IuStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_IuStrings* FUN_1401a9d70();

// The quest scroll: the quest client manager.
class Unk_IuQuest : public CPtred {};                       // CQuest (Unk_PayloadPtr<CQuest> in the exe: get 0x140747690, dtor 0x140747580)
class Unk_IuQuestList
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual MS2Ptr<Unk_IuQuest> vfunc_3(int nQuestId);      // 3 the quest
    int FUN_140745590(int nQuestId);                        // completed
    int FUN_140745630(int nQuestId);                        // accepted
    int FUN_140745820(int nQuestId, int n);                 // the quest may start
};
class Unk_IuQuestMgr
{
public:
    virtual void vfunc_0();
    virtual int vfunc_1(int nQuestId, int n);               // 1 the quest can be accepted
    void* m_p08;
    Unk_IuQuestList m_list;                                 // +0x10
};
Unk_IuQuestMgr* FUN_140764020();
Unk_IuQuestMgr* FUN_141523ba0(PC* pPlayer);                 // the player's quests (MyPC)
CStringW FUN_1416e4df0(int nQuestId);                       // the quest name

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

// The scroll / box dialogs and services the handlers open.
class UIPetExtractionScrollDialog : public UIDialog
{
public:
    void FUN_140e72860(__int64 nScrollUid);                 // remember the scroll and open
};
UIItemExchangeScrollDialog* FUN_140b6ce30(int nId);         // the dialog getter of another unit (same template body)
UIWebBrowser* FUN_140c43790(int nId);                       // the dialog getter of another unit (same template body)
CFeatureManager* FUN_140166410();
CFishingManager* FUN_140953f20();
CGuildManager* FUN_1403ed290();
WeddingManager* FUN_1409eed90();
bool FUN_141b89990(WeddingManager* pWedding);              // married
bool FUN_141b899d0(WeddingManager* pWedding);              // ApplyPartner: the partner is online (returns AL; weddingmanager.cpp declares it void)
CBlockManager* FUN_140a6a830();
void FUN_140a30ad0(const BlockPtr& spBlock, int nAction, unsigned __int64 n);   // the blocked action notice
CStringA FUN_14016a600(const wchar_t* psz, unsigned nCodePage);                // wide to multibyte
int FUN_1405267d0(CItem* pItem, int nGender);                     // CItem member: the item may be worn by the gender (the exe tests the int result)
void FUN_1418fe1c0(const CStringA& strUrl);                 // open the url in the external browser
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);   // equals
CStringW FUN_1409eec40(int nStringId);                      // a string table text (the item string table)
CStringW FUN_14062b4f0(CStringW strKey, const int& nArg);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, void* pListener, CStringW strTag);
int FUN_1401e0800(unsigned short nLevel);                   // the ability reset is open at that level
bool FUN_14152e7f0(PC* pPlayer);                            // the gender can't change (MyPC)

// The box / potion handlers.
int FUN_141658e60(PC* pPlayer);                             // the gender
int FUN_141276180(const CString& strChannel, const CString& strArg);   // the notice log
CStringW FUN_1409e8820(CStringW strKey, const int& nArg);
DungeonRoomTable* FUN_14031c2a0();
CMyCharacter* FUN_140931510();
unsigned FUN_140869420();                                   // the raw timer (ms)
int FUN_14086be10(int nSeconds);                            // seconds to ms
extern int DAT_143ab2914;                                   // the GM level

// OpenMassive.
size_t FUN_140966da0(const ATL::CAtlArray<void*>& arr);     // GetCount (the CAtlArray<MS2Ptr<T>> COMDAT)
bool FUN_140930b10();                                       // the player has a state that blocks it
bool FUN_140930b70();                                       // the player is idle
extern int DAT_143ab287c;                                   // the wedding progress state
int FUN_14166c930(PC* pPlayer);                             // the actor state kind
class Unk_IuScene;
Unk_IuScene* FUN_1408e57f0();
int FUN_1422b9e00(Unk_IuScene* pScene);                     // the scene state id
unsigned FUN_14086bd90(unsigned nMs);                       // ms to seconds
CStringW FUN_141b708a0(unsigned nSeconds, int n);           // a duration text

// OpenInstrument.
int FUN_14166cc80(PC* pPlayer);                             // the move state
void* FUN_14165f100(PC* pPlayer);                           // the ridden object
__int64 FUN_141656a80(PC* pPlayer);                         // the character id
class Unk_IuMusicPlayer { public: bool FUN_140d09d90(int n); };   // pre-listening a score
Unk_IuMusicPlayer* FUN_140c8dac0();
struct Unk_InventoryUsePacket                               // inventory.cpp's use-item packet (0x19)
{
    Unk_InventoryUsePacket();
    ~Unk_InventoryUsePacket();
    void FUN_1401fbc40(COutPacket& packet);
    __int64 id;
    CStringW argument;
};

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

// The UCRT's `static __inline memcpy_s` of this TU (kept alive by the pointer below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;

// ---- dynamic initializers (.text$di) ----

// @0x1400d1f70
static ATL::CAtlMap<CStringW, Unk_ItemUseFunc, ATL::CStringElementTraits<CStringW> > s_itemUseFuncs;
// @0x1400d1fc0
static std::map<unsigned, DWORD> s_itemUseMap;   // item id -> last use tick (the exe type is map<unsigned,unsigned>; stand-in: worldservice.cpp claims the pair ctor names)
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
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
        FUN_140d73aa0(GetStringCommonByKey(L"s_item_err_puton_vip"), 0, 0, L"");
        return false;
    }
    if (spItem->FUN_140525e00() != 0 && !pPlayer->vfunc_146())
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_item_err_puton_wedding"), 0, 0, L"");
        return false;
    }
    if (!spItem->FUN_140526810((unsigned short)pPlayer->vfunc_78()))
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_err_not_enough_level"), 1, 1);
        return false;
    }
    if (!spItem->FUN_140526790(pPlayer->FUN_141654700()))
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_item_err_disable_job"), 0, 0, L"");
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
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d1c550
int UseItemCheckCapacity(CItem* pItem, CStringW& strTab, __int64* pnOver)
{
    std::vector<ItemDropResult> drops;
    ItemDropContext context;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        context.m_gender = pPlayer->FUN_141658e60();
        context.m_job = pPlayer->FUN_141654700();
    }
    Unk_ItemEquipData* pRecord = pItem->FUN_140527840();
    if (pRecord->function.parameter.FUN_1408d2380() != 0)
    {
        int nBoxId = 0;
        if (pRecord->function.name == L"OpenItemBox")
            nBoxId = pRecord->function.arg0;
        else if (pRecord->function.name == L"OpenItemBoxWithKey")
            nBoxId = pRecord->function.parameter.FUN_1408d1fd0(5, 0);
        FUN_1405a1fd0()->GetBoxItems(nBoxId, context, drops, false);
    }
    for (std::vector<ItemDropResult>::iterator it = drops.begin(); it != drops.end(); ++it)
    {
        ItemDropResult& entry = *it;
        MS2Ptr<CItemData> spData = FUN_14053f870(entry.m_itemId);
        if (spData == 0)
            continue;
        int nItemId = entry.vfunc_o18_0();
        unsigned nCount = entry.vfunc_o18_2();
        int nTab = FUN_1403bafd0(nItemId);
        if (nTab == 0x11)
            continue;
        __int64 nAmount = 0;
        __int64 nCap = 0;
        if (!FUN_141900510(nTab, &nAmount, &nCap))
            continue;
        if (nTab == 0x10)
            continue;
        nCount = (std::max)(nCount, entry.m_maxCount);
        __int64 nTotal = nCount + nAmount;
        if (nCap < nTotal)
        {
            *pnOver = nTotal - nCap;
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
    __int64 nItemUid = box.FUN_141a02f10(0, 0);
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
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
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
        strMsg = GetStringCommonByKey(strKey);
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
        spBox->FUN_141a024e0(GetStringCommon(0x29e), 0);
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
            spBox->FUN_141a024e0(GetStringCommon(0x29e), 0);
            FUN_140d73c60(spBox);
        }
        return;
    }
    OpenItemBoxContents(pItem, L"");
}

// Send the open request; boxes that allow it ask for the count to open at once.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
            spBox->SetTitle(GetStringCommonByKey(L"s_msg_item_open_item_box_multiopen_title"));
            spBox->FUN_141a01690(GetStringCommonByKey(L"s_msg_item_open_item_box_multiopen_ok"), GetStringCommonByKey(L"s_word_cancel"), L"");
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
    if (nButton != 0)
        return true;
    if (IsBoxNotAgainChecked(box))
    {
        TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n10Time = FUN_140869440();
        TSingleton<CGameOption>::GetInstance()->FUN_141243540();
    }
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(box.FUN_141a02c20());
    if (spItem.get() != 0)
        OpenItemBoxSingle(spItem.get());
    return true;
}

// @0x140d1db60
bool OnOpenItemBoxCapacity(int nButton, const CMsgBoxData& box)
{
    if (nButton != 0)
        return true;
    if (IsBoxNotAgainChecked(box))
    {
        TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n18Time = FUN_140869440();
        TSingleton<CGameOption>::GetInstance()->FUN_141243540();
    }
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(box.FUN_141a02c20());
    if (spItem.get() != 0)
        OpenItemBoxContents(spItem.get(), L"");
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
    if (nCount > *TSingleton<Client::Constants>::GetInstance()->ItemBoxMultiOpenLimitCount.Get())
        nCount = *TSingleton<Client::Constants>::GetInstance()->ItemBoxMultiOpenLimitCount.Get();
    if (nCount > 1)
    {
        UIItemMultiOpenBoxDialog* pDialog = GetItemUseDialog<UIItemMultiOpenBoxDialog>(0x4f88);
        if (pDialog != 0 && pDialog->FUN_141924630() == 0)
            pDialog->FUN_140c3f9d0(spItem->FUN_1405276c0(), spItem->FUN_140526bd0(), strArgs, nCount);
    }
    else
    {
        DAT_143ab2a90.FUN_140a63880(spItem.get(), strArgs);
    }
    return true;
}

// @0x140d1df70
int RecallParty(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    return 1;
}

// The codi (outfit) tab item: activate the tab or extend its period.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
        FUN_140d73aa0(GetStringCommonByKey(L"s_msg_item_active_codi_tab_already_limitless"), 0, 0, L"");
        return 1;
    }
    if (nState == 1)
    {
        if (bLimitless)
        {
            strMsg = GetStringCommonByKey(L"s_msg_item_active_codi_tab_already_period_use_limitless");
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
        strMsg = GetStringCommonByKey(L"s_msg_item_active_codi_tab_limitless");
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
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, GetStringCommonByKey(L"s_msg_item_change_beauty"), 0, s_strUseFunctionItem);
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
    int nReactorId = spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(0, 0);
    if (!FUN_140b7a330(pPlayer, nReactorId))
        return 0;
    static_cast<MyPC*>(pPlayer)->FUN_14152e0c0();
    return DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
}

// The festival item: only in its fields and while its game event (and festival kind) runs.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
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
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d203f0
int OpenCoupleEffectBox(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIInventoryDialog* pDialog = FUN_1405344f0(0x4e2d);
    if (pDialog != 0)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, GetStringCommonByKey(L"s_coupleeffect_recevie_name"), 0, L"");
        if (spBox.get() != 0)
        {
            CStringW strEmpty(L"");
            spBox->FUN_141a01d30(2, strEmpty, 0xc, 0, 0);
            spBox->FUN_1405340b0(spItem->FUN_140526a50());
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

// @0x140d21480
int ItemMergeRevert(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIItemMergeRevertDialog* pDialog = GetItemUseDialog<UIItemMergeRevertDialog>(0x4f3d);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630() != 0)
            return 1;
        pDialog->FUN_140e4c7a0(spItem.get());
        pDialog->FUN_141924680();
    }
    return 1;
}

// The quest scroll: warn first when the item says so, else accept its quests.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d21520
int QuestScroll(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    CStringW strWarn = spItem->FUN_140527840()->function.xml.FUN_14042cad0(L"warnMsg", L"");
    if (strWarn.GetLength() == 0)
    {
        std::vector<int> quests = spItem->FUN_140527840()->function.xml.FUN_1409e8620(L"questID", std::vector<int>());
        for (size_t i = 0; i < quests.size(); ++i)
        {
            if (FUN_140764020()->m_list.FUN_140745630(quests[i]) != 0)
            {
                FUN_140d73bc0(0x5f3, 0, 0, L"");
                return 0;
            }
            if (FUN_140764020()->vfunc_1(quests[i], 0) == 0)
            {
                FUN_140d73bc0(0x5f4, 0, 0, L"");
                return 0;
            }
        }
        return DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommonByKey(strWarn), 0, L"");
    if (spBox.get() != 0)
    {
        spBox->FUN_1405340b0(spItem->FUN_140526a50());
        spBox->FUN_141a027c0(Unk_IuBoxCallback(OnQuestScrollConfirm));
        FUN_140d73c60(spBox);
    }
    return 1;
}

// @0x140d21a10
int PetExtraction(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_140166410()->FUN_14036d570(0x6c))
    {
        UIPetExtractionScrollDialog* pDialog = GetItemUseDialog<UIPetExtractionScrollDialog>(0x4f4a);
        if (pDialog != 0)
        {
            if (pDialog->FUN_141924630() != 0)
                return 1;
            pDialog->FUN_140e72860(spItem->FUN_140526a50());
            pDialog->FUN_141924680();
        }
    }
    return 1;
}

// @0x140d21ad0
int ItemExtraction(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_140166410()->FUN_14036d570(0x8f))
    {
        UIItemExtractionScrollDialog* pDialog = GetItemUseDialog<UIItemExtractionScrollDialog>(0x4f49);
        if (pDialog != 0)
        {
            if (pDialog->FUN_141924630() != 0)
                return 1;
            pDialog->FUN_140e4b2c0(spItem->FUN_140526a50());
            pDialog->FUN_141924680();
        }
    }
    return 1;
}

// @0x140d21b90
int ItemExchangeScroll(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIItemExchangeScrollDialog* pDialog = FUN_140b6ce30(0x4f14);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630() != 0)
            return 1;
        pDialog->FUN_140f51490(spItem.get());
        pDialog->FUN_141924680();
    }
    return 1;
}

// @0x140d21c30
int ItemSocketScroll(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4f10))
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_itemsocket_scroll_already_open"), 0, 0, L"");
        return 0;
    }
    DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
    return 1;
}

// The web page item: the in-game browser ("maview") or the external one.
// @0x140d21d70
int OpenWebPage(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    CStringA strUrl = FUN_14016a600(spItem->FUN_140527840()->function.parameter.FUN_1408d21c0(0, L""), 0);
    CStringW strKind = spItem->FUN_140527840()->function.parameter.FUN_1408d21c0(1, L"");
    if (FUN_1403b3c40(strKind, L"maview"))
    {
        UIWebBrowser* pBrowser = FUN_140c43790(0x4e6a);
        if (pBrowser == 0)
            return 1;
        pBrowser->FUN_14135ec00(strUrl, true);
    }
    else
    {
        FUN_1418fe1c0(strUrl);
    }
    return 1;
}

// @0x140d21f50
int PetTraining(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4f12) != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_pet_training_dialog_already_open"), 0, 0, L"");
        return 0;
    }
    UIItemPetTrainingDialog* pDialog = GetItemUseDialog<UIItemPetTrainingDialog>(0x4f12);
    if (pDialog != 0)
    {
        pDialog->SetOwner(spItem->FUN_140526a50());
        pDialog->FUN_141924680();
    }
    return 1;
}

// @0x140d22090
int ItemRePackingScroll(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4f11) != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_item_repacking_scroll_already_open"), 0, 0, L"");
        return 0;
    }
    return DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
}

// @0x140d221c0
int ItemRemakeScroll(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4f09) != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_itemremake_scroll_already_open"), 0, 0, L"");
        return 0;
    }
    return DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
}

// @0x140d222f0
int OpenPetBox(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIItemPetBoxDialog* pDialog = GetItemUseDialog<UIItemPetBoxDialog>(0x4f2c);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630() != 0)
            return 1;
        pDialog->SetBoxItemId(spItem->FUN_1405276c0());
        pDialog->FUN_141924680();
    }
    return 1;
}

// @0x140d22390
int OpenItemBoxLullu(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIItemLulluBoxDialog* pDialog = GetItemUseDialog<UIItemLulluBoxDialog>(0x4f2b);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630() != 0)
            return 1;
        pDialog->SetBoxItemId(spItem->FUN_1405276c0());
        pDialog->FUN_141924680();
    }
    return 1;
}

// @0x140d22430
int SelectItemBox(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UISelectItemBoxDialog* pDialog = GetItemUseDialog<UISelectItemBoxDialog>(0x4eff);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630() != 0)
            return 1;
        pDialog->SetItemUid(spItem->FUN_140526a50());
        pDialog->FUN_141924680();
    }
    return 1;
}

// @0x140d224d0
int UGCMapPackage(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIInteriorBuildDialog* pDialog = GetItemUseDialog<UIInteriorBuildDialog>(0x4ee8);
    if (pDialog != 0)
        pDialog->FUN_140f4b4c0(spItem->FUN_140526a50());
    return 1;
}

// @0x140d22540
int FishingRod(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_140166410()->FUN_14036d570(0xb))
        FUN_140953f20()->FUN_140cdadb0(spItem);
    return 1;
}

// @0x140d225d0
int EnchantScroll(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4ee0) != 0)
    {
        FUN_140d73bc0(0xb68, 0, 0, L"");
        return 0;
    }
    return DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
}

// The guild recall: call the other guild members.
// @0x140d226b0
int RecallGuild(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x1a) != 0)
    {
        FUN_140d73bc0(0x2f7, 0, 0, L"");
        return 0;
    }
    if (FUN_1403ed290()->FUN_1413b6160() == 0)
    {
        FUN_140d73bc0(0xb5a, 0, 0, L"");
        return 0;
    }
    ATL::CAtlMap<__int64, __int64> mapMembers;
    int nTotal = FUN_1403ed290()->FUN_1404d3400(&mapMembers);
    int nCount = nTotal - 1;
    if (nCount <= 0)
    {
        FUN_140d73bc0(0xb5c, 0, 0, L"");
        return 0;
    }
    return TSingleton<CCashCallManager>::GetInstance()->FUN_140b04430(spItem->FUN_140526a50(), nCount);
}

// The wedding recall: call the partner.
// @0x140d228e0
int RecallWedding(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x1a) != 0)
    {
        FUN_140d73bc0(0x2f7, 0, 0, L"");
        return 0;
    }
    if (!FUN_141b89990(FUN_1409eed90()))
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_err_cash_recall_not_marriage"), 0, 0, L"");
        return 0;
    }
    if (!FUN_141b899d0(FUN_1409eed90()))
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_err_cash_recall_not_marriage"), 0, 0, L"");
        return 0;
    }
    return TSingleton<CCashCallManager>::GetInstance()->FUN_140b04430(spItem->FUN_140526a50(), 1);
}

// @0x140d22b50
int ResetAbilityCoolTime(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_1401e0800((unsigned short)pPlayer->vfunc_78()) == 0)
    {
        FUN_140d73bc0(0xc63, 0, 0, L"");
        return 0;
    }
    if (FUN_140764020()->m_list.FUN_140745590(*TSingleton<Client::Constants>::GetInstance()->CharacterAbilityOpenQuestID.Get()) == 0)
    {
        FUN_140d73bc0(0xc63, 0, 0, L"");
        return 0;
    }
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(1, 0xc62, 0, s_strUseFunctionItem);
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01600(spItem->FUN_140526a50());
            spBox->FUN_141a024a0(0);
            spBox->FUN_141a01700(0x477, 0x478, 0);
            FUN_140d73c60(spBox);
            return 1;
        }
    }
    return 0;
}

// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d22dd0
int ChangeGender(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_140166410()->FUN_14036d570(0x104))
    {
        if (FUN_1409eed90() == 0)
        {
            FUN_140d73aa0(FUN_1409eec40(0x2f5), 0, 0, L"");
            return 1;
        }
        int nState = FUN_1409eed90()->FUN_140d295d0()->m_nState;
        bool bFree = nState == 0 || nState == 5;
        if (!bFree)
        {
            FUN_140d73aa0(GetStringCommonByKey(L"s_change_gender_err_wedding"), 0, 0, L"");
            return 1;
        }
    }
    if (FUN_14152e7f0(pPlayer))
    {
        FUN_140d73aa0(FUN_1409eec40(0x2f3), 0, 0, L"");
        return 1;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, FUN_14052bd00(0x2f2, pPlayer->vfunc_77()), 0, s_strUseFunctionItem);
    if (spBox.get() == 0)
        return 0;
    spBox->FUN_141a01600(spItem->FUN_140526a50());
    spBox->FUN_141a024a0(0);
    spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
    spBox->FUN_141a01700(0x477, 0x478, 0);
    FUN_140d73c60(spBox);
    return 1;
}

// @0x140d233d0
int ChangeGuildName(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_1403ed290()->FUN_1404d01b0(pPlayer->vfunc_77()) == 0)
    {
        FUN_1412751f0(GetStringCommon(0x416), 1, 1);
        return 0;
    }
    int nMax = *TSingleton<Client::Constants>::GetInstance()->GuildNameLengthMax.Get();
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, FUN_14062b4f0(L"s_guild_ui_change_name", nMax), 0, s_strChangeGuildName);
        if (spBox.get() != 0)
        {
            CStringW strEmpty(L"");
            spBox->FUN_141a01600(spItem->FUN_140526a50());
            spBox->FUN_141a01d30(0, strEmpty, nMax, 0, 0);
            FUN_140d73c60(spBox);
        }
    }
    return 0;
}

// @0x140d236a0
int ChangeCharName(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    {
        BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(10);
        if (spBlock.get() != 0)
        {
            FUN_140a30ad0(spBlock, 10, 0);
            return 1;
        }
    }
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(10, 1, 0, s_strChangeCharName);
        if (spBox.get() != 0)
        {
            CStringW strEmpty(L"");
            spBox->FUN_141a01600(spItem->FUN_140526a50());
            spBox->FUN_141a01d30(2, strEmpty, 0xc, 0, 0);
            FUN_140d73c60(spBox);
        }
    }
    return 1;
}

// The inventory expansion item: name the tab it expands.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d23870
int ExpandInven(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    CStringW strMsg = FUN_1409eec40(0x29c);
    CStringW strTab;
    if (!DAT_143ab2a90.FUN_140a5ce30(strTab))
    {
        FUN_140d73bc0(0x2a3, 0, 0, L"");
        return 0;
    }
    if (strTab.GetLength() != 0 && spItem->FUN_140527840()->function.parameter.FUN_1408d2380() == 1)
        strMsg = FUN_14052bd00(0x2a6, strTab);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, strMsg, 0, s_strUseFunctionItem);
    if (spBox.get() == 0)
        return 0;
    spBox->FUN_141a01600(spItem->FUN_140526a50());
    spBox->FUN_141a024a0(0);
    spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
    spBox->FUN_141a01700(0x477, 0x478, 0);
    FUN_140d73c60(spBox);
    return 1;
}

// @0x140d24cc0
int OpenBank(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    TSingleton<CCashCallManager>::GetInstance()->FUN_140b03d70(spItem->FUN_140526a50());
    return 1;
}

// @0x140d24d30
int CallBlackMarket(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    TSingleton<CCashCallManager>::GetInstance()->FUN_140b03980(spItem->FUN_140526a50());
    return 1;
}

// @0x140d24da0
int CallMedic(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    TSingleton<CCashCallManager>::GetInstance()->FUN_140b03590(spItem->FUN_140526a50());
    return 1;
}

// @0x140d24e10
int CallAirTaxi(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_1403ed2b0()->FUN_141adc940((eUIClassID)0x4e42) != 0)
        FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4e42);
    return 1;
}

// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d24900
int LevelPotion(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return 0;
    if (spField->HasTutorialType())
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_tutorial_levelup_item_not_use"), 1, 1);
        return 0;
    }
    int nDefault = 0;
    int nTarget = spItem->FUN_140527840()->function.xml.GetInt(L"targetLevel", nDefault);
    if (nTarget == 0)
        return 0;
    unsigned short nLevel = (unsigned short)nTarget;
    if ((int)(unsigned short)pPlayer->vfunc_78() >= (int)nLevel)
    {
        FUN_140d73aa0(FUN_1409e8820(L"s_err_cannot_already_target_level_potion", nTarget), 0, 0, L"");
        return 0;
    }
    if (FUN_14166ce30(pPlayer) != 0)
    {
        FUN_140d73bc0(0x54, 0, 0, L"");
        return 0;
    }
    return DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
}

// The dungeon reward box: only while the dungeon's reward count isn't used up.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d24e70
int OpenDungeonItemBox(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    int nDungeon = spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(0, 0);
    int nIndex = spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(1, 0);
    DungeonRoomPtr spRoom = FUN_14031c2a0()->GetRoom(nDungeon, nIndex);
    if (spRoom == 0)
        return 0;
    unsigned nRoomId = spRoom->GetRewardRoomID();
    DungeonRecordCliPtr spRecord = FUN_140931510()->GetRecord()->GetRecord(nRoomId);
    int nNow = spRecord->GetBonusRewardCountNow();
    int nMax = spRecord->GetMaxCount();
    if (nNow >= nMax)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_msg_dungeon_item_open_dungeon_count"), 0, 0, L"");
        return 0;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, GetStringCommonByKey(L"s_msg_item_open_dungeon_item_box"), 0, s_strUseFunctionItem);
    if (spBox.get() == 0)
        return 0;
    spBox->FUN_141a01600(spItem->FUN_140526a50());
    spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
    spBox->FUN_141a01700(0x477, 0x478, 0);
    FUN_140d73c60(spBox);
    return 1;
}

// The box opened with keys: needs the key count and the right gender.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d25430
int OpenItemBoxWithKey(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    int nKeyId = spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(0, 0);
    int nNeed = spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(1, 0);
    int nHave = DAT_143ab2a90.FUN_140a5f180(nKeyId, 0);
    if (nHave < nNeed)
    {
        FUN_140d73aa0(FUN_14028dfa0(L"s_msg_item_open_item_box_with_key_no_key_count", FUN_1401a9d70()->FUN_141811980(1, nKeyId), nHave, nNeed), 0, 0, L"");
        return 1;
    }
    if (::FUN_1405267d0(spItem.operator->(), FUN_141658e60(pPlayer)) == 0)
    {
        FUN_141276180(s_warningGender, "");
        FUN_140d73bc0(0x2d, 0, 0, L"");
        return 1;
    }
    CStringW strMsg = FUN_1405c2690(L"s_msg_item_open_item_box_with_key", FUN_1401a9d70()->FUN_141811980(1, nKeyId));
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, strMsg, 0, s_strUseFunctionItem);
    if (spBox.get() == 0)
        return 0;
    spBox->FUN_141a01600(spItem->FUN_140526a50());
    spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
    spBox->FUN_141a01700(0x477, 0x478, 0);
    FUN_140d73c60(spBox);
    return 1;
}

// @0x140d259d0
int OpenItemBox(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (::FUN_1405267d0(spItem.operator->(), FUN_141658e60(pPlayer)) == 0)
    {
        FUN_141276180(s_warningGender, "");
        FUN_140d73bc0(0x2d, 0, 0, L"");
        return 1;
    }
    int nCount = 1;
    if (spItem->FUN_140527840()->function.parameter.FUN_1408d2380() > 4)
        nCount = spItem->FUN_140527840()->function.parameter.FUN_1408d1fd0(4, 1);
    int nHave = DAT_143ab2a90.FUN_140a5f180(spItem->FUN_1405276c0(), 0);
    if (nCount > nHave)
    {
        FUN_140d73aa0(FUN_1409e8970(L"s_msg_item_open_item_box_multi_no_having_count", nHave, nCount), 0, 0, L"");
        return 1;
    }
    OpenItemBox(spItem.get(), nCount);
    return 1;
}

// The limited quantity box: a per-item cooldown between uses (GMs skip it).
// @0x140d25c50
int OpenItemBoxLimitedQuantity(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    CXmlData* pXml = &spItem->FUN_140527840()->function.xml;
    int nCooldown = 0;
    if (!pXml->FUN_14092c5c0())
    {
        int nDefault = 0;
        nCooldown = pXml->GetInt(L"cooldownTime", nDefault);
    }
    if (nCooldown > 0 && DAT_143ab2914 < 0x32)
    {
        unsigned nNow = FUN_140869420();
        unsigned nLast = s_itemUseMap[spItem->FUN_1405276c0()];
        if (nNow - nLast < (unsigned)FUN_14086be10(nCooldown))
            return 0;
        s_itemUseMap[spItem->FUN_1405276c0()] = nNow;
    }
    DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
    return 1;
}

// @0x140d25e10
int OpenGachaBox(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    UIItemGachaBoxDialog* pDialog = GetItemUseDialog<UIItemGachaBoxDialog>(0x4f8b);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630() != 0)
            return 1;
        pDialog->FUN_140c41c30(spItem->FUN_1405276c0());
        pDialog->FUN_141924680();
    }
    return 1;
}

// The quest start item: level, start and repeat checks, then confirm.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d25eb0
int QuestStart(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    if (spData == 0)
        return 0;
    if (!spData->FUN_14053cd90())
        return 0;
    unsigned nQuestId = spData->function.parameter.FUN_1408d1f60(0, 0);
    unsigned nLevel = spData->function.parameter.FUN_1408d1f60(1, 0);
    if (nLevel == 0)
        nLevel = 10;
    if ((unsigned)pPlayer->vfunc_78() < nLevel)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_quest_start_err_level"), 0, 0, L"");
        return 0;
    }
    if (FUN_141523ba0(pPlayer)->m_list.FUN_140745820(nQuestId, 0) == 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_quest_start_err_invalid"), 0, 0, L"");
        return 0;
    }
    MS2Ptr<Unk_IuQuest> spQuest = (&FUN_141523ba0(pPlayer)->m_list)->vfunc_3(nQuestId);
    if (spQuest.get() != 0 && FUN_141523ba0(pPlayer)->vfunc_1(nQuestId, 0) == 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_quest_start_err_completed"), 0, 0, L"");
        return 0;
    }
    CStringW strTitle = GetStringCommonByKey(L"s_quest_start_title");
    CStringW strMsg = FUN_1405c2690(L"s_quest_start_msg", FUN_1416e4df0(nQuestId));
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(2, strMsg, 0, s_strUseFunctionItem);
    if (spBox.get() == 0)
        return DAT_143ab2a90.FUN_140a63880(spItem.get(), L"");
    spBox->SetTitle(strTitle);
    spBox->FUN_141a01600(spItem->FUN_140526a50());
    spBox->FUN_141a024a0(0);
    spBox->FUN_141a01700(0x477, 0x478, 0);
    FUN_140d73c60(spBox);
    return 1;
}

// ---- inline members of other classes instantiated here ----

// @0x140d29440
MS2Ptr<CEquipmentSlotLayerInfo> Unk_PCEquipSet::GetTitle()
{
    return m_spTitle;
}

// @0x140d295d0
WeddingProxy* WeddingManager::FUN_140d295d0()
{
    return &m_proxy;
}

// The massive event portal item: open a portal (wedding party or event field) where none is.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d20710
int OpenMassive(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x3b) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    ATL::CAtlArray<void*> arrPortals;
    FUN_1403ed2d0()->FUN_141bc2c90(pPlayer->vfunc_18(), arrPortals);
    if (FUN_140966da0(arrPortals) != 0)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_msg_item_open_massive_error_another_portal"), 1, 1);
        return 0;
    }
    int nTipped = 0;
    std::vector<int> vIds;
    FUN_1403ed2d0()->FUN_141bc2980(vIds);
    for (size_t i = 0; i < vIds.size(); ++i)
    {
        MS2Ptr<CPortal> spPortal = FUN_1403ed2d0()->FUN_141bc2800(vIds[i]);
        if (spPortal == 0)
            continue;
        if (spPortal->m_strTip.GetLength() > 0)
            ++nTipped;
    }
    if (nTipped >= 10)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_msg_item_open_massive_error_too_many_portal"), 1, 1);
        return 0;
    }
    if (FUN_1403ed2d0()->FUN_141bd30a0() == 0)
        return 0;
    if (FUN_140930b10())
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_msg_item_open_massive_cant_open"), 1, 1);
        return 0;
    }
    if (FUN_1403ed2d0()->FUN_141bd30a0()->m_nMassiveEventField == 1)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_msg_item_open_massive_cant_open"), 1, 1);
        return 0;
    }
    bool bDefault = false;
    bool bWedding = spItem->FUN_140527840()->function.xml.FUN_1409e8780(L"weddingParty", bDefault);
    if (!bWedding)
    {
        if (!FUN_140930b70())
        {
            FUN_1412751f0(GetStringCommonByKey(L"s_msg_item_open_massive_cant_open"), 1, 1);
            return 0;
        }
    }
    else if (DAT_143ab287c != 0xf)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_msg_item_open_massive_cant_open"), 1, 1);
        return 0;
    }
    if (FUN_14166c930(pPlayer) != 1 || FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_msg_item_open_massive_invalid_state"), 1, 1);
        return 0;
    }
    const wchar_t* pszKey = bWedding ? L"s_msg_item_open_massive_open_wedding" : L"s_msg_item_open_massive_open";
    int nFieldDefault = 0;
    int nFieldId = spItem->FUN_140527840()->function.xml.GetInt(L"fieldID", nFieldDefault);
    unsigned long nTickDefault = 60000;
    unsigned long nDuration = spItem->FUN_140527840()->function.xml.GetULong(L"portalDurationTick", nTickDefault);
    int nMaxDefault = 1;
    int nMaxCount = spItem->FUN_140527840()->function.xml.GetInt(L"maxCount", nMaxDefault);
    CStringW strDuration = FUN_141b708a0(FUN_14086bd90(nDuration), 0);
    CStringW strMsg = FUN_14028dfa0(CStringW(pszKey), FUN_1401a9d70()->FUN_141811980(3, nFieldId), nMaxCount, strDuration);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(5, strMsg, 0, s_strOpenMassive);
    if (spBox.get() != 0)
    {
        spBox->FUN_141a01600(spItem->FUN_140526a50());
        spBox->FUN_141a01d30(5, L"", 6, 0, 0);
        FUN_140d73c60(spBox);
    }
    return 1;
}

// The instrument item: play it where the field and the player's state allow.
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries, branch layout or callee typing differ from the exe
// @0x140d23c50
int OpenInstrument(MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (!FUN_140166410()->FUN_14036d570(10))
        return 0;
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(5) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    if (pPlayer == 0)
        return 0;
    if (FUN_14166ce30(pPlayer) != 0 || FUN_14166c930(pPlayer) != 1)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_play_instrument_invalid_state"), 1, 1);
        return 0;
    }
    bool bMovable = false;
    if (FUN_14166cc80(pPlayer) == 1)
        bMovable = true;
    else if (FUN_14166cc80(pPlayer) > 1 && FUN_14166cc80(pPlayer) < 6)
        bMovable = true;
    if (!bMovable || FUN_14165f100(pPlayer) != 0)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_play_instrument_invalid_state"), 1, 1);
        return 0;
    }
    Unk_EntRef spEntity(FUN_141240f20(FUN_14166d220(pPlayer))->FUN_140cfaff0());
    if (spEntity != 0)
    {
        MS2Ptr<Unk_RideeFieldObj> spObj = FUN_1403ed2d0()->FUN_141bc4f10(spEntity.FUN_1408a9090());
        if (spObj.get() != 0 && spObj->FUN_140ae0700())
        {
            FUN_1412751f0(GetStringCommonByKey(L"s_play_instrument_invalid_position"), 1, 1);
            return 0;
        }
    }
    BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0xf);
    if (spBlock.get() != 0)
    {
        FUN_140a30ad0(spBlock, 0xf, 0);
        return 0;
    }
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return 0;
    if ((spField->m_nLimitContent & 8) != 0)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_play_instrument_invalid_map"), 1, 1);
        return 0;
    }
    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4eed) != 0)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_play_instrument_cant_while_write_music"), 1, 1);
        return 0;
    }
    if (FUN_140c8dac0()->FUN_140d09d90(0))
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_play_instrument_cant_while_pre_listening"), 1, 1);
        return 0;
    }
    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4eec) != 0)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_play_instrument_invalid_state"), 1, 1);
        return 0;
    }
    if (FUN_1403ed2d0()->FUN_141bdb660(3) != 0)
    {
        FUN_1412751f0(FUN_1409eec40(0x62), 1, 1);
        FUN_141276180(s_warningNotThisPlace, "");
        return 0;
    }
    if (!FUN_1403ed2d0()->FUN_141bcada0(FUN_141656a80(pPlayer)))
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_play_instrument_cant_doesnt_register"), 1, 1);
        return 0;
    }
    __int64 nItemUid = spItem->FUN_140526a50();
    StatePlayInstrumentData* pData = new StatePlayInstrumentData(MS2Ptr<CItemData>(spItem->FUN_140527840()), nItemUid);
    pPlayer->vfunc_59(0x2f, pData, 0x7d, 0);
    Unk_InventoryUsePacket use;
    use.id = nItemUid;
    COutPacket packet(0x19, 0);
    use.FUN_1401fbc40(packet);
    FUN_140710590(packet);
    return 1;
}
