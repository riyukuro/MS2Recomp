// astooltip_local.h - unit-local declarations shared by the parts of astooltip.cpp (Unk_ helper types, free-function
// prototypes of this unit's own functions called across parts, and prototypes of exe callees not in a shared header).
// Each part appends ONLY inside its own section. The part that DEFINES a function owns its signature.
#pragma once

#include <cmath>
template <class A> CStringW FormatStringId(int nStringId, const A& a);     // the exe instances (item.cpp and others)
template <class A, class B> CStringW FormatStringId(int nStringId, const A& a, const B& b);
// The exe imports floor from the UCRT: its <cmath> floor<int> (0x1409ecf20) calls through the IAT.
extern "C" double (__cdecl* __imp_floor)(double);
template <> inline double floor<int, void>(int n) { return __imp_floor((double)n); }


// ---- part 1 (0x1409c5210-0x1409cc800) ----
#include "ms2/ms2format.h"
#include "ms2/commonfiles/itemenchantinfo.h"     // MS2Ptr<BaseOption>
#include "ms2/commonfiles/citemoptiontable.h"    // CItemOptionTable (the recovered form; NOT placeholder/citemoptiontable.h)
class Unk_140166430* GetItemOptionTable();                // TSingleton<CItemOptionTable>::GetInstance (exe copy)
CStringW GetOptionKindLabel(int nKind, CItem* pItem);  // part 5: the option kind title (pet kinds use their own text)
bool FormatRandomOptionValue(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, MS2Ptr<BaseOption> spOption, const CStringW& strValue);
#include "ms2/commonfiles/itemdroptable.h"       // ItemDropResult (ASObj::FUN_1409c5bd0)
CStringW GetItemDisplayName(unsigned nItemId);              // the item name (itemugcmesh.cpp)
CStringW FUN_1409eb450(int n);                    // part 6: CStringW(int)
bool FUN_1403ba4c0(const int& nItemId);           // the item id is a currency (gameentitycommon.cpp)
#include "ms2/commonfiles/maid.h"
#include "ms2/commonfiles/maidgradejockpottable.h"     // CMaidRecipeTable
#include "ms2/placeholder/cusermaidmanager.h"
#include "ms2/placeholder/cmanufacturemanager.h"
CStringW FUN_140763e10(int nPrice);               // the price text (questmasktable.cpp)
CStringW FUN_1412e1e50(CTimeSpan span, int a, int b);   // a duration text (uimaidrecipelistdialog.cpp)

#include "ms2/commonfiles/item.h"               // CItemUgc (the UGC info behind CItem::FUN_1405278d0)
#include "ms2/placeholder/cugcmanager.h"
CString GetDownloadFilePath(int nType, CString strPath);   // a UGC resource url (ugcimagepath.cpp)
// The config singleton DAT_143aac5c0 (cachedata.cpp GetCommonResource): the movie shown for a UGC item without a look.
struct Unk_TooltipConfigPaths
{
    char m_pad[0xc8];
    CString m_strUgcMovie;                        // +0xc8
};
class Unk_SingletonObj* GetCommonResource();
bool FormatRandomSpecialOptionValue(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, MS2Ptr<BaseOption> spOption, const CStringW& strValue);
#include "ms2/commonfiles/featuremanager.h"
class Unk_140166410* FUN_140166410();                 // TSingleton<CFeatureManager>::GetInstance (exe copy; also part 2)
CStringW FUN_1409e5320(const int& nSeason);       // part 5: the season text (also part 3)
CStringW FUN_14016a730(const char* sz, int nCodePage);   // 0x14016a730 widen (as commonfiles/packet.h)
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/ugcmapsetiteminfo.h"
#include "ms2/placeholder/cstringtable.h"
#include <list>
#include <algorithm>
#include "ms2/placeholder/setitemtable.h"
#include "ms2/commonfiles/setitemoptionpart.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/client/ms2/equipment.h"
class PCBase;
class WorldService;



CStringW FUN_1406319f0(int nId, unsigned short nLevel);   // the additional-effect text (itemsocketsystemutil.cpp)
CStringW FUN_140631600(int nStat, BaseOption* pOption);   // a set stat option text (itemsocketsystemutil.cpp)
CStringW FUN_140631830(int nSpecial, int nValue, CItemData* pData);   // a set special option text (itemsocketsystemutil.cpp)
extern const int DAT_142dbac18[4];                // the item model classes that make a set piece gender-bound (1, 2, 3, 18)
#include "ms2/placeholder/citemmergeoptiontable.h"
// C3: Unk_ItemEnchantData = CItemStatus (CItem::m_spStatus +0xf8)
CStringW FormatInt(int n);                    // part 5: an int option value text
CStringW FormatRatePercent(float fRate);              // part 5: a rate option value text
bool IsStatKindOne(int nStat);                    // the stat is shown as an integer (stat.cpp)
bool FUN_14081dc50(int nSpecial);                 // the special stat is shown as an integer (specialability.cpp)
CStringW GetStatCommonText(unsigned nStat);                // GetStatCommonText (stat.cpp)
CStringW FUN_140630e10(int nSpecial);             // the special stat name (itemsocketsystemutil.cpp)
void FUN_14083d2b0(CStringW& str);                // trims the trailing line break (unit_14083bab0.cpp)
#include "ms2/placeholder/wcformat.h"
#include "ms2/commonfiles/itemoption.h"
#include "ms2/commonfiles/itemsocketsystemutil.h"
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/client/ms2/skilldatatablecli.h"
void* GetItemSocketTable();                // TSingleton<CItemSocketTable>::GetInstance (exe copy; as part 2)
#include <cmath>
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cpetdatatable.h"
#include "ms2/placeholder/unlimitedenchantinfo.h"
#include "ms2/commonfiles/exptable.h"
#include "ms2/commonfiles/itemenchantlimittable.h"
void* GetExpTable();                    // 0x1404a1bb0 TSingleton<CExpTable>::GetInstance (exe copy)
int FindStatByName(const CStringA& strName);       // stat name -> id (-1 when none; stat.cpp)
unsigned FUN_14081d260(const CStringA& strName);       // special option name -> id (0 when none; specialability.cpp)
const CString& GetStatName(unsigned nStat);          // the xml name of a stat (stat.cpp)
const CString& FUN_14081d380(int nSpecial);       // the xml name of a special stat (specialability.cpp)
int FUN_1406198a0(int nValue, float fRate);       // itemremakescrolldata.cpp
__int64 FUN_140632990(__int64 nValue, float fRate);   // itemsocketsystemutil.cpp
CStringW FUN_140631720(int nStat, int nValue, bool bPercent);   // a stat value text (itemsocketsystemutil.cpp)
CStringW GetEnchantStatText(int nStat, MS2Ptr<BaseOption> spBase, CItemStatus* pStatus);   // an enchant stat row (itemsocketsystemutil.cpp)
int FUN_14072fd00(int nUnused);                   // the pet option count (unit_14072f7f0.cpp)
CStringW GetStringCommonByKey(const CStringW& strKey);   // the string-table text of a key (commonutil.cpp)
CStringW FUN_1409404f0(__int64 nValue);           // a number with separators (achievemanager.cpp)
// ---- end part 1 ----

// ---- part 2 (0x1409cc800-0x1409d3010) ----
#include "ms2/ms2format.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/citemmergeoptiontable.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/commonfiles/itemsocketsystemutil.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/ugcdef.h"                       // CUgcItemLook (as parts 4/5; not placeholder/cubeiteminfo.h)
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/client/ms2/skilldatatablecli.h"       // SkillDataTableCli (commonfiles form, as part 4)
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/cpetdatatable.h"
class PCBase;
class Unk_ItemOwnerRef : public CItemTransfer {};                     // CItem::FUN_140527930's record (the item's CItemTransfer)
CStringW FUN_14016a730(const char* sz, int nCodePage);                // a multi-byte text as a wide string (achievedata.cpp)
class Unk_140166410* FUN_140166410();                                     // TSingleton<CFeatureManager>::GetInstance (exe copy)
CReservedWordTable* FUN_1403b4750();                                  // 0x1403b4750 the reserved word table
void* GetItemSocketTable();                                    // TSingleton<CItemSocketTable>::GetInstance (exe copy)
void* GetGameRule();                                           // TSingleton<CGameRule>::GetInstance (exe copy)
class Unk_AkoMyPC;
template <> Unk_AkoMyPC* efd::DynamicCast<Unk_AkoMyPC, PCBase>(PCBase* Source);
bool CanTradeItem(MS2Ptr<CItem> spItem);                             // the item can be traded (itemsocketsystemutil.cpp)
CStringW FUN_1418fec00(int nMoneyType, __int64 nAmount, bool bIcon);  // a money text (uicommon.cpp)
CStringW GetGemstoneOptionText(int nGemId);                                   // the gemstone option text (itemsocketsystemutil.cpp)
CStringW FUN_14062b310(MS2Ptr<TSocketGemStoneInfo> spGem);            // the gemstone state text (itemsocketsystemutil.cpp)
CStringW FUN_140627390(unsigned nGemId);                              // the gemstone name (itemsocketsystemutil.cpp)
CStringW FUN_1406319f0(int nId, unsigned short nLevel);               // the additional-effect text (itemsocketsystemutil.cpp)
CStringW FUN_140630e10(int nSpecial);                                 // the special stat name (itemsocketsystemutil.cpp)
CStringW GetStatCommonText(unsigned nStat);                                    // GetStatCommonText (stat.cpp)
bool IsStatKindTwo(int nStat);                                        // the stat is shown as a rate (stat.cpp)
bool FUN_14081dcd0(int nSpecial);                                     // the special stat is shown as a rate (specialability.cpp)


CStringW FUN_1409e6120(CItem* pItem, int nTradeable, int nPersonal, int nBindable, int nBindOnGet, const CStringW& strSeparator, int nCount, CStringW strBindName, int nRemainOnly);   // part 5: the item limit text
// identical redeclarations of other parts' prototypes (solo builds)

CStringW FormatInt(int n);                                        // part 5
CStringW FormatTenthsPercent(int nTenths);                                  // part 5
int FUN_1409e6c80(CItem* pItem);                                      // part 5
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/client/ms2/achievemanager.h"
#include <set>
// C3: Unk_ItemEnchantData = CItemStatus (CItem::m_spStatus +0xf8)



class Unk_NametagTrophy* GetAchieveManager();                                     // TSingleton<CAchieveManager>::GetInstance (exe copy)

CStringW GetRequireAchieveText(int nId, int nGrade, CStringW strDefault);     // the trophy requirement text (achievemanager.cpp)
unsigned char FUN_140930c50();                                                 // the housing state is local (unit_14092f420.cpp)
int FUN_141901d20(int nItemId, __int64 nUid, __int64 nUgcUid);   // uicommon.cpp
int FUN_141901f70(int nItemId, __int64 nUid, __int64 nUgcUid);   // uicommon.cpp
int HasStateChangePermission(int nId);                                           // objectdata.cpp: state change permission
int IsTriggerControlEnabled(int nId);                                           // objectdata.cpp: trigger control enabled
CStringW GetQuestName(int nBookId);                                  // the book description
extern unsigned short DAT_143ab291c;                                  // the housing level limit (offline)
extern unsigned short DAT_143ab2940;                                  // the housing level limit
extern unsigned short DAT_143ab2964;                                  // billboard: the required level
extern unsigned DAT_143ab2970;                                        // billboard: the required adventure level
// The (trophy id, grade) key of the achieved-trophy set DAT_143ab32d8 is itemdatatable.h's Unk_TrophyKey (was the
// unit-local Unk_SSGHouseKey, same 8-byte layout and ordering).
inline Unk_TrophyKey::Unk_TrophyKey() { m_nId = 0; m_nLevel = 0; }   // 0x1409ed810 (inline COMDAT of this unit)
//
//
//
//
//
//
//
//
//
//
extern std::set<Unk_TrophyKey> DAT_143ab32d8;   // userproxy.cpp
// ---- end part 2 ----

// ---- part 3 (0x1409d3010-0x1409d9f30) ----
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/placeholder/unlimitedenchantinfo.h"
class Unk_ItemPlusInfo : public UnlimitedEnchantInfo {};    // CItemStatus::FUN_140630d90's record
#include "ms2/commonfiles/itemenchantinfo.h"              // CItemEnchantInfo
#include "ms2/commonfiles/itemoption.h"
// C3: Unk_ItemEnchantData = CItemStatus (CItem::m_spStatus +0xf8)
CReservedWordTable* FUN_1403b4750();                        // 0x1403b4750 the reserved word table
// (C3: FUN_14052d230 = TSingleton<ItemGachaBoxTable>::GetInstance, itemgachaboxtable.h)
int FUN_1409e6fc0(int nKind);                               // part 5: the item kind shown by the tooltip
CStringW FUN_1409e5320(const int& nSeason);                 // part 5: the season text
CStringW FUN_14016a730(const char* sz, int nCodePage);              // 0x14016a730 widen (as commonfiles/packet.h)
#include "ms2/placeholder/citemextradata.h"
#include "ms2/commonfiles/itemdata.h"                       // ItemColorEx
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/itemdatatable.h"
class Unk_140166410* FUN_140166410();                        // 0x140166410 TSingleton<CFeatureManager>::GetInstance (exe copy)
bool FUN_140f33250(ASObj& obj, MS2Ptr<ItemColorEx> spColor, MS2Ptr<CItemData> spData, bool bAlt);   // the colour of an item (unit_140f32290.cpp)
#include "ms2/ms2format.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/exptable.h"
#include "ms2/commonfiles/commonstruct_wa.h"                // CIngredientContainer
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/commonfiles/itemsocket.h"
class PCBase;
void* GetExpTable();                              // 0x1404a1bb0 TSingleton<CExpTable>::GetInstance (exe copy)




bool FUN_1406a6030(MS2Ptr<CItemData> spData);               // the item data may be registered at the merat market (meratmarketbasketinfo.cpp)
// The owner ids of the merat market checks (0x20 bytes; uimeratmarketregisterdialog.cpp's Unk_MrdOwner).
struct Unk_BillOwner
{
    Unk_BillOwner();
    __int64 m_nAccount;
    unsigned m_nType;
    void* m_pCharacter;                                     // the own character id (stored as a pointer-size value)
    __int64 m_n18;
};
MS2_CHECK_SIZE(Unk_BillOwner, 0x20);
struct Unk_MeratItemOwner;
bool FUN_1406a5a50(MS2Ptr<CItem> spItem, const Unk_MeratItemOwner* pOwner);   // the item may be registered (meratmarketbasketinfo.cpp)
extern __int64 DAT_143ab2820;                               // the own account id
extern unsigned DAT_143ab2830;
extern __int64 DAT_143ab2838;
extern int DAT_143ab2834;
// CItemBreakIngredientTable (commonfiles/item.h, which this unit cannot include: CUgcItemLook clash with ugcdef.h)
struct Unk_TooltipBreakTable
{
};
class Unk_BreakRecipes* GetItemBreakIngredientTable();                  // 0x140535300 the break ingredient table
#include "ms2/commonfiles/itembreakmanager.h"
class Unk_SlotBreakManager* GetItemBreakManager();                // 0x1409c4b20 the break manager
// The callers here test CItemData::IsMeratMarketRegisterable (0x14053d740, enableRegisterMeratMarket) as an int (no movzx):
// it returns BOOL (int).
struct Unk_ItemDataMeratView;   // its FUN_14053d740 was CItemData::IsMeratMarketRegisterable
#include "ms2/commonfiles/itemgemstonedata.h"
CItemGemStoneUpgradeTable* GetItemGemStoneUpgradeTable();              // 0x14062c280 TSingleton<CItemGemStoneUpgradeTable>::GetInstance (exe copy)
bool FUN_140627020(MS2Ptr<CItemGemStoneData> spRow);        // the gemstone is at its last level (itemsocketsystemutil.cpp)
#include "ms2/commonfiles/itemextractiontable.h"
void* GetItemExtractionTable();                   // 0x14052d1f0 TSingleton<CItemExtractionTable>::GetInstance (exe copy)
bool FUN_140634230(MS2Ptr<CItem> spItem);                   // the item is excluded from repacking (itemsocketsystemutil.cpp)

CStringW GetStringCommonByKey(const CStringW& strKey);             // the string-table text of a key (commonutil.cpp)
#include "ms2/client/ms2/questmanager_2.h"
void* FUN_140764020();                          // 0x140764020 TSingleton<CQuestManager>::GetInstance (exe copy)
CStringW GetQuestNameWithLevel(int nQuestId, CStringW strKey); // the quest name formatted with a string-table key (by value)
// the UI string service (0x14025e7a0): "$"-prefixed keys translated by FUN_1422b0570
class Unk_TooltipUiStrings;   // C3: the GFxManager singleton (astooltip.cpp casts it to its GFxManager view)
class Unk_AltStringMgr* GetGFxManager();
bool IsStatKindTwo(int nStat);                              // the stat is shown as a rate (stat.cpp)
bool FUN_14081dcd0(int nSpecial);                           // the special stat is shown as a rate (specialability.cpp)
CStringW GetStatCommonText(unsigned nStat);                          // GetStatCommonText (stat.cpp)
CStringW FUN_140630e10(int nSpecial);                       // the special stat name (itemsocketsystemutil.cpp)
CStringW FormatInt(int n);                              // part 5: an int option value text
CStringW FormatRatePercent(float fRate);                        // part 5: a rate option value text
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/client/ms2/achievemanager.h"
class Unk_NametagTrophy* GetAchieveManager();                                     // TSingleton<CAchieveManager>::GetInstance (exe copy)

CStringW GetRequireAchieveText(int nId, int nGrade, CStringW strDefault);     // the trophy requirement text (achievemanager.cpp)
int HasStateChangePermission(int nId);                                           // objectdata.cpp: state change permission
int IsTriggerControlEnabled(int nId);                                           // objectdata.cpp: trigger control enabled

extern unsigned short DAT_143ab291c;                                  // the housing level limit (offline)
#include "ms2/commonfiles/maid.h"
CStringW FUN_140763e10(int nPrice);                                   // the price text (questmasktable.cpp)
#include "ms2/placeholder/termtagmanagercli.h"


#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/citemremakescrolltable.h"
// The coupon items of a beauty shop (npcshopdata.cpp): a CAtlArray boxed behind its CPtred (TPtredDummy).
typedef ATL::CAtlArray<MS2Ptr<CItemData> > Unk_TooltipBeautyItems;
template<> struct Unk_SocketRef<Unk_TooltipBeautyItems> {
    static CPtred* Base(Unk_TooltipBeautyItems* p)
    {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_TooltipBeautyItems>, value);
        return result;
    }
};
MS2_SOCKETPTR_BOXED(Unk_TooltipBeautyItems)
Unk_SocketPtr<Unk_TooltipBeautyItems> FUN_1406e5af0(unsigned nShopId);    // the coupon items of a beauty shop (npcshopdata.cpp)
// C3: ItemFunctionArgs (citemdata.h) replaces the local member view
// CItemData::FUN_14053c940 / FUN_14053d660 return an int at the call sites (citemdata.h declares them bool).
struct Unk_ItemDataIntView : CItemData { int FUN_14053c940(int nGender); int FUN_14053d660(); };
int FUN_14053feb0(int nItemId);                                       // the default rank of an item (itemdata.cpp)
void FUN_14183eba0(unsigned nItemId, CStringW& strIcon, unsigned long& nSize, unsigned long& nColor1, unsigned long& nColor2);   // the super chat item look (texttohtml.cpp)
extern unsigned long s_color6;                                   // texttohtml.cpp s_colors: the super chat colour
extern unsigned long s_color18;                                   // texttohtml.cpp s_colors: the super chat second colour
extern CStringW DAT_143aef3b8;                                        // texttohtml.cpp: the default super chat icon
#include "ms2/commonfiles/itemenchantlimittable.h"
#include "ms2/commonfiles/itemenchanttransformtable.h"
// ---- end part 3 ----

// ---- part 4 (0x1409d9f30-0x1409e0450) ----
#include "ms2/commonfiles/itemdatatable.h"          // CItemDataTable::GetMusicScore
#include "ms2/commonfiles/timeutil.h"               // MsToSeconds
#include "ms2/commonfiles/masterytable.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/skilldatatablecli.h"       // SkillDataTableCli / SkillData / SkillLevelData (commonfiles form)
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/commonfiles/chatemoticontable.h"
void FUN_1402929a0(const CStringW& str, std::vector<int>& rOut, const wchar_t* pszSep);   // split into ids (commonutil.cpp)
CStringW GetStringCommonByKey(const CStringW& str);                         // a string table text (commonutil.cpp)
int FUN_14028e280(CMsTime& kOut, const CString& strFormat, const CString& strText);   // parses a date text (commonutil.cpp)
class MyPC;
extern Unk_Inventory g_143ab2a90;                                   // the inventory
CStringW FUN_141b708a0(unsigned nSeconds, bool bShowSeconds);         // a duration text (util.cpp)
bool FUN_141b48950(MS2Ptr<CItem> spItem);                             // the item has a preview model (uishopdialog.cpp)
bool IsPreviewable(MS2Ptr<CItemData> spData);                         // the item data may be previewed
#include "ms2/commonfiles/jobtable.h"                 // JobData / JobSkillData
#include "ms2/placeholder/fittingdollpc.h"                // PC::FUN_1409eee00
#include "ms2/client/ms2/uiskillbookautodistributedialog.h"
UISkillBookTreeDialog* FUN_1409eb120(int nId);                        // the skill book tree dialog if it is open
// The skill tier option manager behind PC::FUN_1409eee00 (fittingdollpc.h forward-declares it for the user unit).
#include "ms2/client/ms2/skilltieroptionmanager.h"
class Unk_PCSkillTree : public CSkillTierOptionManager { };
// The local player's quest state (MyPC::FUN_141523ba0 result; the CQuestManagerCommon sits at +0x10).
#include "ms2/placeholder/cquestmanagercommon.h"
struct Unk_TooltipQuestState {};                                       // the CQuestManagerCommon (abstract here)
struct Unk_TooltipQuestHolder
{
    unsigned char m_00[0x10];
    Unk_TooltipQuestState m_quests;                                   // +0x10
};


CStringW GetQuestName(int nBookId);                                  // the quest/book name (as part 1)
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/commonfiles/commonstruct_wa.h"                 // ItemDropItemLife
#include <algorithm>

MS2Ptr<CItemData> FUN_14053f870(int nItemId);                    // the item data of an id (as astooltip.cpp)
bool IsExpiring(int bFollowEndDate, __int64 nExpiry, int nType, int nLifeType, int nItemType);   // a drop expires (item.cpp)
CStringW FUN_14183e9c0(CStringW strText, int nRank);                  // colours a text by rank (texttohtml.cpp)
bool FUN_1409e7930(ItemDropResult& lhs, ItemDropResult& rhs);         // part 5: the display order
bool FUN_1409e7a40(ItemDropResult& lhs, ItemDropResult& rhs);         // part 5: the pick order

MS2Ptr<AScript> FUN_1409e7dc0(int nMovieId, const Scaleform::GFx::Value& v);   // part 6: wrap a child AS object
CStringW FUN_1409e7880();                                             // part 5: the enablePreview text
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"           // CMeratMarketProduct
#include "ms2/commonfiles/itemgemstonedata.h"               // CItemGemStoneUpgradeTable
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/equipitem.h"
struct Unk_EquipItemData : public CItemData {};                       // CEquipItem::FUN_1411dc7f0's record (as customize.cpp)
// The owner player of the tooltip (ASTooltip::m_40): its equipped item of a slot (5 right hand, 4 left hand).






CStringW FUN_1409404f0(__int64 nValue);                               // a number with separators (achievemanager.cpp)
CStringW FUN_141277910(MS2Ptr<CItemData> spData);                     // the item name text (unit_141274d10.cpp)
CStringW FUN_1406285d0(unsigned nMask);                               // the gemstone upgrade text (itemsocketsystemutil.cpp)

// part 5 helpers (signatures from the call sites in this part)
CStringW FUN_1409e3050(const CStringW& strPrefix, int nScope, int nReset);
void FUN_1409e68a0(int nJob, ATL::CAtlArray<unsigned>& jobs, int& nAllowed, CStringW& strOut);   // the job limit text
void FUN_1409e6aa0(int nJob, ATL::CAtlArray<unsigned>& jobs, CStringW& strOut);                  // the disabled job text
void FUN_1409e6d00(int nRight, int nLeft, ATL::CAtlArray<Unk_SkillWeapon>& weapons, int& nAllowed, CStringW& strOut);   // the required weapons
// interface_check reads reasons from the unit .cpp and its own headers, not from the .inl files:
// MS2-FUNCTIONAL 0x1409db930: the exe keeps the null test of the side tooltip in a bool temp (no source form found)
// ---- end part 4 ----

// ---- part 5 (0x1409e0450-0x1409e7dc0) ----
#include "ms2/ms2format.h"

CStringW GetStatValueText(unsigned nId);                              // 0x14082f090 the format of a stat value (stat.cpp)
CStringW FormatInt(int n);
CStringW FUN_1409e0970(int nStat, int n);
CStringW FUN_1409e0a10(const CStringW& strFormat, int n);
CStringW FormatRatePercent(float fRate);
CStringW FormatTenthsPercent(int nTenths);
CStringW FUN_1409e0bf0(int nStat, int nTenths);
CStringW FUN_1409e0cb0(const CStringW& strFormat, float fRate);
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/commonfiles/chatemoticontable.h"
void FUN_1402929a0(const CStringW& str, std::vector<int>& rOut, const wchar_t* pszSep);   // split into ids (commonutil.cpp)
CStringW GetStringCommonByKey(const CStringW& str);                         // a string table text (commonutil.cpp)
int FUN_14028e280(CMsTime& kOut, const CString& strFormat, const CString& strText);   // parses a date text (commonutil.cpp)
#include "ms2/placeholder/wcformat.h"
class Unk_ItemEquipData : public CItemData {};                       // CItem::FUN_140527840's record (as commonfiles\item.cpp)
CUIService* FUN_1403ed2b0();                                          // CUIService::GetInstance (exe copy)
int FUN_1409e6c80(CItem* pItem);
CStringW FUN_1409e7880();
#include "ms2/commonfiles/itemdroptable.h"
CStringW FUN_1407196b0(long n);                                   // number -> text (unit_1407186f0.cpp)
CStringW FUN_1409e3050(const CStringW& strPrefix, int nScope, int nReset);
bool FUN_1409e7930(ItemDropResult& lhs, ItemDropResult& rhs);
bool FUN_1409e7a40(ItemDropResult& lhs, ItemDropResult& rhs);
extern int g_nDebugUI;                                                // 0x143ae0fc0 (uiobject.cpp): debug UI information on
int FUN_1409e1b80(ASTooltip* pTooltip, int nSkillId, int bFromDialog);
class MyPC;

#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/commonfiles/timeutil.h"
// (C3: FUN_14052d230 = TSingleton<ItemGachaBoxTable>::GetInstance, itemgachaboxtable.h)


#include "ms2/client/ms2/achievemanager.h"
class Unk_NametagTrophy* GetAchieveManager();                                     // TSingleton<CAchieveManager>::GetInstance (exe copy)
CStringW FUN_14093b970(int nId);                                      // achievement title (achievemanager.cpp)
CStringW FUN_14093c8d0(int nId, int nGrade, int bRaw);                // achievement description
CStringW FUN_14093ce70(int nId, int nGrade);                          // achievement reward text
CStringW GetRecordedDateText(CAchieve* pAchieve, int nKey);                 // achievement completion date
CString GetAchieveName(CAchieveData* pData);                           // achievement icon path (achievecondition.cpp, static there)
float FUN_14028d280(unsigned nTicks);                                 // milliseconds -> seconds (commonutil.cpp)
#include "ms2/commonfiles/itemgift.h"                                 // ItemAble
void FUN_1409e2ed0(Scaleform::GFx::Value* pOut, ItemAble& item);
#include "ms2/commonfiles/meratmarketbasketinfo.h"                   // CMeratMarketPremiumProduct
#include "ms2/commonfiles/jobtable.h"
bool FUN_1402226b0(int nJob);                                         // the job code is valid
void FUN_1409e68a0(int nJob, ATL::CAtlArray<unsigned>& jobs, int& nAllowed, CStringW& strOut);   // the job limit text
void FUN_1409e6aa0(int nJob, ATL::CAtlArray<unsigned>& jobs, CStringW& strOut);                  // the disabled job text
#include "ms2/commonfiles/featuremanager.h"
// The no-argument BlockFormat (0x1409eec40, COMDAT in the template range): FMT_VARIADIC_W has no 0-arg form. w534: move to the shared section.
#include "ms2/placeholder/blockformat.h"
inline CStringW BlockFormat(int nStringId) { return FUN_14028dee0(nStringId, fmt::ArgList()); }

CStringW GetRequireAchieveText(int nId, int nGrade, CStringW strDefault);     // the trophy requirement text (achievemanager.cpp)
const int& GetAtOrDefault(const CAtlArray<int>& arr, int nIndex, const int& nDefault);   // part 6: arr[nIndex], nDefault when out of range
bool FUN_1409e7080(const ATL::CAtlArray<unsigned long>& ids, const ATL::CAtlArray<int>& grades, CStringW& strOut);   // the unmet trophy requirements
class Unk_140166410* FUN_140166410();                                  // 0x140166410 TSingleton<CFeatureManager>::GetInstance (exe copy)
#include "ms2/commonfiles/commonstruct_wa.h"                 // Unk_IngVec (FUN_1409e7460)
int FUN_14053feb0(int nItemId);                                       // the default rank of an item (itemdata.cpp)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                    // the item data of an id


bool IsExpiring(int bFollowEndDate, __int64 nExpiry, int nType, int nLifeType, int nItemType);   // a drop expires (item.cpp)
#include "ms2/commonfiles/itemenchantinfo.h"     // MS2Ptr<BaseOption> (FUN_1409e4950)
#include "ms2/commonfiles/citemoptiontable.h"    // CItemOptionTable
#include "ms2/commonfiles/itemoption.h"
#include "ms2/commonfiles/item.h"               // CItemStatus
class Unk_140166430* GetItemOptionTable();                // TSingleton<CItemOptionTable>::GetInstance (exe copy)
bool FormatRandomOptionValue(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, MS2Ptr<BaseOption> spOption, const CStringW& strValue);   // part 1
bool FormatRandomSpecialOptionValue(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, MS2Ptr<BaseOption> spOption, const CStringW& strValue);   // part 1
CStringW FUN_140631600(int nStat, BaseOption* pOption);   // a set stat option text (itemsocketsystemutil.cpp)
CStringW FUN_140631830(int nSpecial, int nValue, CItemData* pData);   // a set special option text (itemsocketsystemutil.cpp)
int FindStatByName(const CStringA& strName);       // stat name -> id (-1 when none; stat.cpp)
unsigned FUN_14081d260(const CStringA& strName);       // special option name -> id (0 when none; specialability.cpp)
const CString& GetStatName(unsigned nStat);          // the xml name of a stat (stat.cpp)
const CString& FUN_14081d380(int nSpecial);       // the xml name of a special stat (specialability.cpp)
void FUN_1409e4950(MS2Ptr<CItem> spItem, CStringW& strOut, bool* pBest);   // the random option rows of an item (by value: the callee destroys spItem)
// MS2-FUNCTIONAL 0x1409e4950: /Od temporaries and frame differ (the .inl marker is not read by interface_check); same calls and control flow
#include <cmath>
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cpetdatatable.h"
int FUN_1406198a0(int nValue, float fRate);       // itemremakescrolldata.cpp
__int64 FUN_140632990(__int64 nValue, float fRate);   // itemsocketsystemutil.cpp
CStringW FUN_140631720(int nStat, int nValue, bool bPercent);   // a stat value text (itemsocketsystemutil.cpp)
CStringW GetOptionKindLabel(int nKind, CItem* pItem);  // the option kind title (pet kinds use their own text)
CStringW FUN_1409e34e0(MS2Ptr<CItem> spItem);     // the option text of an item (as tabcontentspetinfo.cpp; the callee destroys spItem)
// MS2-FUNCTIONAL 0x1409e34e0: /Od temporaries differ (written after part 1's FUN_1409c9170 loop); same behaviour
CStringW FUN_1409e6120(CItem* pItem, int nTradeable, int nPersonal, int nBindable, int nBindOnGet, const CStringW& strSeparator, int nCount, CStringW strBindName, int nRemainOnly);   // the item limit text
void FUN_1409e6d00(int nRight, int nLeft, ATL::CAtlArray<Unk_SkillWeapon>& weapons, int& nAllowed, CStringW& strOut);   // the required weapons
// ---- end part 5 ----

// ---- part 6 (0x1409e7dc0-0x1409eb4c0) ----
// Shared by all parts (w534). The fmt wrappers below are COMDATs whose first instantiation is in this unit
// (0x1409e7e70-0x1409eadb0): call them naturally with the exact argument types and they pair by themselves.
//   StringFormat(L"...", a, b...)        ms2format.h  (narrow/wide literal format -> CString/CStringW)
//   FUN_14028dfa0(CStringW key, a, ...)  wcformat.h   (string-table key text formatted with the args)
//   BlockFormat(int stringId, a, ...)    below        (string-id text formatted with the args; 0x14028dee0)
// Never declare FUN_1409e7e70..FUN_1409eadb0 as externs.
#include "ms2/ms2format.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/cxmldata.h"
const int& GetAtOrDefault(const CAtlArray<int>& arr, int nIndex, const int& nDefault);   // arr[nIndex], nDefault when out of range
// ---- end part 6 ----

