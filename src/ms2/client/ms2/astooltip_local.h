// astooltip_local.h - unit-local declarations shared by the parts of astooltip.cpp (Unk_ helper types, free-function
// prototypes of this unit's own functions called across parts, and prototypes of exe callees not in a shared header).
// Each part appends ONLY inside its own section. The part that DEFINES a function owns its signature.
#pragma once

// ---- part 1 (0x1409c5210-0x1409cc800) ----
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 1
#include "ms2/ms2format.h"
#include "ms2/commonfiles/itemenchantinfo.h"     // Unk_EnchantPtr<BaseOption>
#include "ms2/commonfiles/citemoptiontable.h"    // CItemOptionTable (the recovered form; NOT placeholder/citemoptiontable.h)
CItemOptionTable* FUN_140166430();                // TSingleton<CItemOptionTable>::GetInstance (exe copy)
CStringW FUN_1409e6010(int nKind, CItem* pItem);  // part 5: the option kind title (pet kinds use their own text)
bool FUN_1409c5210(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, Unk_EnchantPtr<BaseOption> spOption, const CStringW& strValue);
#include "ms2/commonfiles/itemdroptable.h"       // ItemDropResult (ASObj::FUN_1409c5bd0)
CStringW FUN_141425950(int nItemId);              // the item name (itemugcmesh.cpp)
CStringW FUN_1409eb450(int n);                    // part 6: CStringW(int)
bool FUN_1403ba4c0(const int& nItemId);           // the item id is a currency (gameentitycommon.cpp)
#include "ms2/commonfiles/maid.h"
#include "ms2/commonfiles/maidgradejockpottable.h"     // CMaidRecipeTable
#include "ms2/placeholder/cusermaidmanager.h"
#include "ms2/placeholder/cmanufacturemanager.h"
CStringW FUN_140763e10(int nPrice);               // the price text (questmasktable.cpp)
CStringW FUN_1412e1e50(CTimeSpan span, int a, int b);   // a duration text (uimaidrecipelistdialog.cpp)
CStringW FUN_140632a60(int nStringId, const CStringW& a, const CStringW& b);   // FormatStringId<CStringW, CStringW>
#include "ms2/commonfiles/item.h"               // CItemUgc (the UGC info behind CItem::FUN_1405278d0)
#include "ms2/placeholder/cugcmanager.h"
CUgcManager* FUN_14052d220();                     // TSingleton<CUgcManager>::GetInstance (exe copy)
CString FUN_1410280d0(int nType, CString strPath);   // a UGC resource url (ugcimagepath.cpp)
// The config singleton DAT_143aac5c0 (cachedata.cpp FUN_1401d31f0): the movie shown for a UGC item without a look.
struct Unk_TooltipConfigPaths
{
    char m_pad[0xc8];
    CString m_strUgcMovie;                        // +0xc8
};
Unk_TooltipConfigPaths* FUN_1401d31f0();
bool FUN_1409c56f0(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, Unk_EnchantPtr<BaseOption> spOption, const CStringW& strValue);
#include "ms2/commonfiles/featuremanager.h"
CFeatureManager* FUN_140166410();                 // TSingleton<CFeatureManager>::GetInstance (exe copy; also part 2)
CStringW FUN_1409e5320(const int& nSeason);       // part 5: the season text (also part 3)
CStringW FUN_14016a730(const char* sz, int nCodePage);   // 0x14016a730 widen (as commonfiles/packet.h)
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/ugcmapsetiteminfo.h"
#include "ms2/placeholder/cstringtable.h"
CItemDataTable* FUN_140281980_p1();               // 0x140281980 TSingleton<CItemDataTable>::GetInstance (exe copy)
CStringTable* FUN_1401a9d70_p1();                 // 0x1401a9d70 the string table
#include <list>
#include <algorithm>
#include "ms2/placeholder/setitemtable.h"
#include "ms2/commonfiles/setitemoptionpart.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/client/ms2/equipment.h"
class PCBase;
class WorldService;
WorldService* FUN_1403ed2d0_p1();                 // 0x1403ed2d0 WorldService::GetInstance (exe copy)
PCBase* FUN_141bd1290(WorldService* pWorld, int nId);   // the player of an object id (worldservice_1.cpp)
CEquipment* FUN_1416561a0_p1(PCBase* pPc);        // 0x1416561a0 the player's equipment
int FUN_141658e60_p1(PCBase* pPc);                // 0x141658e60 the player's gender
CStringW FUN_1406319f0(int nId, unsigned short nLevel);   // the additional-effect text (itemsocketsystemutil.cpp)
CStringW FUN_140631600(int nStat, BaseOption* pOption);   // a set stat option text (itemsocketsystemutil.cpp)
CStringW FUN_140631830(int nSpecial, int nValue, CItemData* pData);   // a set special option text (itemsocketsystemutil.cpp)
extern const int DAT_142dbac18[4];                // the item model classes that make a set piece gender-bound (1, 2, 3, 18)
#include "ms2/placeholder/citemmergeoptiontable.h"
class Unk_ItemEnchantData;
CStringW FUN_1409e0900(int n);                    // part 5: an int option value text
CStringW FUN_1409e0a90(float fRate);              // part 5: a rate option value text
bool FUN_14082f1d0(int nStat);                    // the stat is shown as an integer (stat.cpp)
bool FUN_14081dc50(int nSpecial);                 // the special stat is shown as an integer (specialability.cpp)
CStringW FUN_14082f000(int nStat);                // GetStatCommonText (stat.cpp)
CStringW FUN_140630e10(int nSpecial);             // the special stat name (itemsocketsystemutil.cpp)
void FUN_14083d2b0(CStringW& str);                // trims the trailing line break (unit_14083bab0.cpp)
#endif
#if defined(MS2_AT_SOLO) && MS2_AT_SOLO == 1
class Unk_ItemEquipData : public CItemData {};    // solo build only: part 5 defines it otherwise
struct Unk_EquipItemData : public CItemData {};   // solo build only: CEquipItem::FUN_1411dc7f0's record (defined by another part)
#endif
// ---- end part 1 ----

// ---- part 2 (0x1409cc800-0x1409d3010) ----
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 2
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
#include "ms2/placeholder/cubeiteminfo.h"                // CUgcItemLook (the placeholder form other parts use; not commonfiles/ugcdef.h)
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/client/ms2/skilldatatablecli.h"       // SkillDataTableCli (commonfiles form, as part 4)
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/cpetdatatable.h"
class PCBase;
class Unk_ItemOwnerRef : public CItemTransfer {};                     // CItem::FUN_140527930's record (the item's CItemTransfer)
CPetDataTable* FUN_14052d210();                                       // TSingleton<CPetDataTable>::GetInstance (exe copy)
CStringW FUN_14016a730(const char* sz, int nCodePage);                // a multi-byte text as a wide string (achievedata.cpp)
CFeatureManager* FUN_140166410();                                     // TSingleton<CFeatureManager>::GetInstance (exe copy)
CReservedWordTable* FUN_1403b4750();                                  // 0x1403b4750 the reserved word table
CItemSocketTable* FUN_14052d200();                                    // TSingleton<CItemSocketTable>::GetInstance (exe copy)
CItemDataTable* FUN_140281980_p2();                                   // 0x140281980 TSingleton<CItemDataTable>::GetInstance (exe copy)
CGameRule* FUN_1401c0d90();                                           // TSingleton<CGameRule>::GetInstance (exe copy)
SkillDataTableCli* FUN_1401958b0();                                   // TSingleton<SkillDataTableCli>::GetInstance (exe copy)
MyPC* FUN_1409613d0(PCBase* p);                                       // efd::DynamicCast<MyPC>(PCBase*)
bool FUN_140633a20(MS2Ptr<CItem> spItem);                             // the item can be traded (itemsocketsystemutil.cpp)
CStringW FUN_1418fec00(int nMoneyType, __int64 nAmount, bool bIcon);  // a money text (uicommon.cpp)
CStringW FUN_14062ae60(int nGemId);                                   // the gemstone option text (itemsocketsystemutil.cpp)
CStringW FUN_14062b310(MS2Ptr<TSocketGemStoneInfo> spGem);            // the gemstone state text (itemsocketsystemutil.cpp)
CStringW FUN_140627390(unsigned nGemId);                              // the gemstone name (itemsocketsystemutil.cpp)
CStringW FUN_1406319f0(int nId, unsigned short nLevel);               // the additional-effect text (itemsocketsystemutil.cpp)
CStringW FUN_140630e10(int nSpecial);                                 // the special stat name (itemsocketsystemutil.cpp)
CStringW FUN_14082f000(int nStat);                                    // GetStatCommonText (stat.cpp)
bool FUN_14082f250(int nStat);                                        // the stat is shown as a rate (stat.cpp)
bool FUN_14081dcd0(int nSpecial);                                     // the special stat is shown as a rate (specialability.cpp)
CStringW FUN_1408116a0(int nStringId, const int& n);                  // FormatStringId<int>
CStringW FUN_14086cfc0(int nStringId, const long& n);                 // FormatStringId<long>
CStringW FUN_14086d060(int nStringId, const __int64& n);              // FormatStringId<__int64>
CStringW FUN_1409e6120(CItem* pItem, int nTradeable, int nPersonal, int nBindable, int nBindOnGet, const CStringW& strSeparator, int nCount, CStringW strBindName, int nRemainOnly);   // part 5: the item limit text
// identical redeclarations of other parts' prototypes (solo builds)
CStringTable* FUN_1401a9d70_p3();                                     // 0x1401a9d70 the string table (part 3)
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);        // FormatStringId<CStringW> (part 5)
CStringW FUN_1409e0900(int n);                                        // part 5
CStringW FUN_1409e0b40(int nTenths);                                  // part 5
int FUN_1409e6c80(CItem* pItem);                                      // part 5
#include "ms2/commonfiles/item.h"                                     // CItemStatus / CItemUgc
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/client/ms2/achievemanager.h"
#include <set>
class Unk_ItemEnchantData;                                            // CItem::FUN_1405278a0's record (part 3 owns the type)
CItemEnchantInfo* FUN_140630d60_p2(Unk_ItemEnchantData* pStatus);     // 0x140630d60 CItemStatus::FUN_140630d60 (the enchant record; this in rcx)
void* FUN_1403ed2d0_p2();                                             // 0x1403ed2d0 the world service
PCBase* FUN_141bd0cc0_p2(void* pWorld);                               // 0x141bd0cc0 the local player
CAchieveManager* FUN_1406c7600();                                     // TSingleton<CAchieveManager>::GetInstance (exe copy)
int FUN_140936640(CAchieveManager* pManager, int nId, int nGrade);    // 0x140936640 CAchieveManager: the trophy grade is reached
CStringW FUN_14093bd40(int nId, int nGrade, CStringW strDefault);     // the trophy requirement text (achievemanager.cpp)
bool FUN_140930c50();                                                 // the housing state is local (unit_14092f420.cpp)
unsigned FUN_141901d20(int nItemId, __int64 nUid, __int64 nUgcUid);   // uicommon.cpp
unsigned FUN_141901f70(int nItemId, __int64 nUid, __int64 nUgcUid);   // uicommon.cpp
int FUN_1407077c0(int nId);                                           // objectdata.cpp: state change permission
int FUN_140707710(int nId);                                           // objectdata.cpp: trigger control enabled
CStringW FUN_1416e4df0(int nBookId);                                  // the book description
extern unsigned short DAT_143ab291c;                                  // the housing level limit (offline)
extern unsigned short DAT_143ab2940;                                  // the housing level limit
extern unsigned short DAT_143ab2964;                                  // billboard: the required level
extern unsigned DAT_143ab2970;                                        // billboard: the required adventure level
// The (trophy id, grade) key of the achieved-trophy set DAT_143ab32d8 (as scenestategame.cpp / mypc.cpp).
struct Unk_SSGHouseKey
{
    Unk_SSGHouseKey() { m_nA = 0; m_nB = 0; }   // 0x1409ed810 (inline COMDAT of this unit)
    unsigned int m_nA;
    unsigned int m_nB;
};
inline bool operator<(const Unk_SSGHouseKey& a, const Unk_SSGHouseKey& b)
{
    if (a.m_nA != b.m_nA)
        return a.m_nA < b.m_nA;
    return a.m_nB < b.m_nB;
}
extern std::set<Unk_SSGHouseKey> DAT_143ab32d8;
#endif
#if defined(MS2_AT_SOLO) && MS2_AT_SOLO == 2
class Unk_ItemEquipData : public CItemData {};    // solo build only: part 5 defines it otherwise
#endif
// ---- end part 2 ----

// ---- part 3 (0x1409d3010-0x1409d9f30) ----
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 3
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
class Unk_ItemPlusInfo { public: int FUN_1408bbc50(); };    // CItemStatus::FUN_140630d90's record (UnlimitedEnchantInfo)
class Unk_ItemEnchantData { public: Unk_ItemPlusInfo* FUN_140630d90(); };   // CItem::FUN_1405278a0's record (CItemStatus)
CStringTable* FUN_1401a9d70_p3();                           // 0x1401a9d70 the string table (astooltip.cpp declares the Unk_CommandStrings form)
CReservedWordTable* FUN_1403b4750();                        // 0x1403b4750 the reserved word table
ItemGachaBoxTable* FUN_14052d230();                         // 0x14052d230 TSingleton<ItemGachaBoxTable>::GetInstance
int FUN_1409e6fc0(int nKind);                               // part 5: the item kind shown by the tooltip
CStringW FUN_1409e5320(const int& nSeason);                 // part 5: the season text
CStringW FUN_14016a730(const char* sz, int nCodePage);              // 0x14016a730 widen (as commonfiles/packet.h)
#include "ms2/placeholder/citemextradata.h"
#include "ms2/commonfiles/itemdata.h"                       // ItemColorEx
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/itemdatatable.h"
CFeatureManager* FUN_140166410_p3();                        // 0x140166410 TSingleton<CFeatureManager>::GetInstance (exe copy)
CItemDataTable* FUN_140281980_p3();                         // 0x140281980 TSingleton<CItemDataTable>::GetInstance (exe copy)
bool FUN_140f33250(ASObj& obj, MS2Ptr<ItemColorEx> spColor, MS2Ptr<CItemData> spData, bool bAlt);   // the colour of an item (unit_140f32290.cpp)
#endif
#include "ms2/ms2format.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/exptable.h"
#include "ms2/commonfiles/commonstruct_wa.h"                // CIngredientContainer
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/commonfiles/itemsocket.h"
class PCBase;
CExpTable* FUN_1404a1bb0_p3();                              // 0x1404a1bb0 TSingleton<CExpTable>::GetInstance (exe copy)
ItemDropTable* FUN_1405a1fd0_p3();                          // 0x1405a1fd0 TSingleton<ItemDropTable>::GetInstance (exe copy)
void* FUN_1403ed2d0_p3();                                   // 0x1403ed2d0 the world service
PCBase* FUN_141bd0cc0_p3(void* pWorld);                     // 0x141bd0cc0 the local player
int FUN_141654700_p3(PCBase* pPc);                          // 0x141654700 the job
int FUN_141658e60_p3(PCBase* pPc);                          // 0x141658e60 the gender
bool FUN_1406a6030(MS2Ptr<CItemData> spData);               // the item data may be registered at the merat market (meratmarketbasketinfo.cpp)
// The owner ids of the merat market checks (0x20 bytes; uimeratmarketregisterdialog.cpp's Unk_MrdOwner).
struct Unk_TooltipItemOwner
{
    void FUN_1409aff60();
    __int64 m_nAccount;
    unsigned m_nType;
    void* m_pCharacter;                                     // the own character id (stored as a pointer-size value)
    __int64 m_n18;
};
MS2_CHECK_SIZE(Unk_TooltipItemOwner, 0x20);
bool FUN_1406a5a50(MS2Ptr<CItem> spItem, const Unk_TooltipItemOwner* pOwner);   // the item may be registered (meratmarketbasketinfo.cpp)
extern __int64 DAT_143ab2820;                               // the own account id
extern unsigned DAT_143ab2830;
extern __int64 DAT_143ab2838;
extern int DAT_143ab2834;
// CItemBreakIngredientTable (commonfiles/item.h, which this unit cannot include: CUgcItemLook clash with ugcdef.h)
struct Unk_TooltipBreakTable
{
    MS2SvrPtr<CIngredientContainer> FUN_14052e730(int nBoxId);                       // GetGachaBox
    MS2SvrPtr<CIngredientContainer> FUN_14052e810(int nItemId, int nGrade, int nEnchant);   // GetIngredients
};
Unk_TooltipBreakTable* FUN_140535300_p3();                  // 0x140535300 the break ingredient table
class Unk_TooltipBreakManager { public: int FUN_140531270(MS2Ptr<CItem> spItem); };   // CItemBreakManager: the item can be broken
Unk_TooltipBreakManager* FUN_1409c4b20_p3();                // 0x1409c4b20 the break manager
// The callers here test CItemData::FUN_14053d740 (enableRegisterMeratMarket) as an int (no movzx): the exe's caller-side
// prototype returns BOOL.
struct Unk_ItemDataMeratView : CItemData { int FUN_14053d740(); };
#if defined(MS2_AT_SOLO) && MS2_AT_SOLO == 3
class Unk_ItemEquipData : public CItemData {};                       // solo build only: part 5 defines it otherwise
#endif
// ---- end part 3 ----

// ---- part 4 (0x1409d9f30-0x1409e0450) ----
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 4
#include "ms2/commonfiles/itemdatatable.h"          // CItemDataTable::GetMusicScore
#include "ms2/commonfiles/timeutil.h"               // MsToSeconds
#include "ms2/commonfiles/masterytable.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/skilldatatablecli.h"       // SkillDataTableCli / SkillData / SkillLevelData (commonfiles form)
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/commonfiles/chatemoticontable.h"
void FUN_1402929a0(const CStringW& str, std::vector<unsigned>& rOut, const wchar_t* pszSep);   // split into ids (commonutil.cpp)
CStringW FUN_14028b8e0(const CStringW& str);                         // a string table text (commonutil.cpp)
int FUN_14028e280(CMsTime& kOut, const CString& strFormat, const CString& strText);   // parses a date text (commonutil.cpp)
class MyPC;
extern Unk_Inventory DAT_143ab2a90;                                   // the inventory
CStringW FUN_141b708a0(unsigned nSeconds, bool bShowSeconds);         // a duration text (util.cpp)
bool FUN_141b48950(MS2Ptr<CItem> spItem);                             // the item has a preview model (uishopdialog.cpp)
bool FUN_141b488c0(MS2Ptr<CItemData> spData);                         // the item data may be previewed
// The job system of a player (JobSystemCli; jobsystem.h is not included: it pulls placeholder/skilldata.h, which clashes
// with the commonfiles SkillData of skilldatatablecli.h). Only the proven slots.
#include "ms2/commonfiles/jobtable.h"                 // JobData / JobSkillData
#include "ms2/placeholder/cquestmanagercommon.h"
// A learnt skill of the job system (JobSkill, guess/jobsystem.h; that header is not included here, see below).
class Unk_TooltipJobSkillP4 : public CPtred
{
public:
    unsigned FUN_140637cc0();                                         // JobSkill::GetID
    unsigned m_nId;                                                   // +0x18
    unsigned short m_nLevel;                                          // +0x1c
    unsigned char m_1e;
    bool m_bLearnt;                                                   // +0x1f
};
MS2_CHECK_OFFSET(Unk_TooltipJobSkillP4, m_bLearnt, 0x1f);
// CSkillPointSimulator (skillpointsimulator.h pulls jobsystem.h) / UISkillBookTreeDialog: only the called members.
class Unk_TooltipSkillSim : public CPtred
{
public:
    MS2Ptr<Unk_TooltipJobSkillP4> FUN_140abc980(unsigned nSkillId);   // CSkillPointSimulator::GetEditSkill
};
struct Unk_TooltipSkillTreeDialog
{
    MS2Ptr<Unk_TooltipSkillSim> FUN_140ec8ad0();                      // UISkillBookTreeDialog::GetSimulator
};
class UIDialog;
UIDialog* FUN_1409eb120(int nDialogId);                               // part 6: a dialog by id
// The skill tier option manager behind PC::FUN_1409eee00 (fittingdollpc.h forward-declares it for the user unit).
class Unk_PCSkillTree : public CPtred
{
public:
    unsigned short FUN_14080baf0(unsigned nSkillId);                  // CSkillTierOptionManager::GetSkillLevel
};
// The local player's quest state (MyPC::FUN_141523ba0 result; the CQuestManagerCommon sits at +0x10).
struct Unk_TooltipQuestHolder
{
    unsigned char m_00[0x10];
    CQuestManagerCommon m_quests;                                     // +0x10
};
struct Unk_TooltipQuestOwner
{
    Unk_TooltipQuestHolder* FUN_141523ba0();                          // MyPC: the quest state
};
void* FUN_1403ed2d0_p4();                                             // 0x1403ed2d0 the world service
Unk_TooltipQuestOwner* FUN_141bd0cc0_p4(void* pWorld);                // 0x141bd0cc0 the local player (MyPC*)
CStringW FUN_1416e4df0(int nBookId);                                  // the quest/book name (as part 1)
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/commonfiles/commonstruct_wa.h"                 // ItemDropItemLife
#include <algorithm>
int FUN_141658e60_p4(PCBase* pPc);                                    // 0x141658e60 the gender of a player
ItemDropTable* FUN_1405a1fd0_p4();                                    // 0x1405a1fd0 TSingleton<ItemDropTable>::GetInstance
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);                    // the item data of an id (as astooltip.cpp)
bool FUN_14052a3f0(int bFollowEndDate, __int64 nExpiry, int nType, int nLifeType, int nItemType);   // a drop expires (item.cpp)
CStringW FUN_14183e9c0(CStringW strText, int nRank);                  // colours a text by rank (texttohtml.cpp)
bool FUN_1409e7930(ItemDropResult& lhs, ItemDropResult& rhs);         // part 5: the display order
bool FUN_1409e7a40(ItemDropResult& lhs, ItemDropResult& rhs);         // part 5: the pick order
struct Unk_TooltipJobSystem
{
    virtual ~Unk_TooltipJobSystem();                                  // MS2: slot 0
    virtual MS2Ptr<SkillLevelData> vfunc_1(unsigned nSkillId);        // MS2: slot 1
    virtual bool vfunc_2(unsigned nSkillId);                          // MS2: slot 2 learnt (or granted by a temporary source)
    MS2Ptr<JobData> FUN_140639bb0();                                  // JobSystem::GetJobData
    MS2Ptr<Unk_TooltipJobSkillP4> FUN_1406394d0(unsigned nSkillId);   // JobSystem::FindSkill
};
Unk_TooltipJobSystem* FUN_1416546d0(MyPC* pPC);                       // the job system of a player (JobSystemCli*)
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
struct Unk_TooltipOwnerPC
{
    MS2Ptr<CEquipItem> FUN_141655c90(int nSlot);                      // member: rcx = owner, rdx = result, r8d = slot
};
int FUN_141654700(PCBase* pPc);                                       // the job of a player
int FUN_141662de0(PCBase* pPc);                                       // the VIP grade of a player
CStringW FUN_1409404f0(__int64 nValue);                               // a number with separators (achievemanager.cpp)
CStringW FUN_141277910(MS2Ptr<CItemData> spData);                     // the item name text (unit_141274d10.cpp)
CStringW FUN_1406285d0(unsigned nMask);                               // the gemstone upgrade text (itemsocketsystemutil.cpp)
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);        // FormatStringId<CStringW> (item.cpp)
// part 5 helpers (signatures from the call sites in this part)
CStringW FUN_1409e3050(const CStringW& strPrefix, int nScope, int nReset);
void FUN_1409e68a0(int nJob, ATL::CAtlArray<unsigned>& jobs, int& nAllowed, CStringW& strOut);   // the job limit text
void FUN_1409e6aa0(int nJob, ATL::CAtlArray<unsigned>& jobs, CStringW& strOut);                  // the disabled job text
void FUN_1409e6d00(int nRight, int nLeft, ATL::CAtlArray<Unk_SkillWeapon>& weapons, int& nAllowed, CStringW& strOut);   // the required weapons
CStringW FUN_1408116a0(int nStringId, const int& n);                  // FormatStringId<int>
#include "ms2/commonfiles/featuremanager.h"
CFeatureManager* FUN_140166410_p5();                                  // 0x140166410 TSingleton<CFeatureManager>::GetInstance (exe copy)
CStringW FUN_1409e6120(CItem* pItem, int nTradeable, int nPersonal, int nBindable, int nBindOnGet, const CStringW& strSeparator, int nCount, CStringW strBindName, int nRemainOnly);   // the item limit text
void FUN_1409e6d00(int nRight, int nLeft, ATL::CAtlArray<Unk_SkillWeapon>& weapons, int& nAllowed, CStringW& strOut);   // the required weapons
#endif
// interface_check reads reasons from the unit .cpp and its own headers, not from the .inl files:
// MS2-FUNCTIONAL 0x1409db930: the exe keeps the null test of the side tooltip in a bool temp (no source form found)
#if defined(MS2_AT_SOLO) && MS2_AT_SOLO == 4
class Unk_ItemEquipData : public CItemData {};                       // solo build only: part 5 defines it otherwise
class Unk_ItemOwnerRef : public CItemTransfer {};                     // solo build only: part 2 defines it otherwise
#endif
// ---- end part 4 ----

// ---- part 5 (0x1409e0450-0x1409e7dc0) ----
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 5
#include "ms2/ms2format.h"
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);        // FormatStringId<CStringW> (item.cpp)
CStringW GetStatValueText(unsigned nId);                              // 0x14082f090 the format of a stat value (stat.cpp)
CStringW FUN_1409e0900(int n);
CStringW FUN_1409e0970(int nStat, int n);
CStringW FUN_1409e0a10(const CStringW& strFormat, int n);
CStringW FUN_1409e0a90(float fRate);
CStringW FUN_1409e0b40(int nTenths);
CStringW FUN_1409e0bf0(int nStat, int nTenths);
CStringW FUN_1409e0cb0(const CStringW& strFormat, float fRate);
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/commonfiles/chatemoticontable.h"
void FUN_1402929a0(const CStringW& str, std::vector<unsigned>& rOut, const wchar_t* pszSep);   // split into ids (commonutil.cpp)
CStringW FUN_14028b8e0(const CStringW& str);                         // a string table text (commonutil.cpp)
int FUN_14028e280(CMsTime& kOut, const CString& strFormat, const CString& strText);   // parses a date text (commonutil.cpp)
#include "ms2/placeholder/wcformat.h"
class Unk_ItemEquipData : public CItemData {};                       // CItem::FUN_140527840's record (as commonfiles\item.cpp)
CUIService* FUN_1403ed2b0();                                          // CUIService::GetInstance (exe copy)
int FUN_1409e6c80(CItem* pItem);
CStringW FUN_1409e7880();
#include "ms2/commonfiles/itemdroptable.h"
CStringW FUN_1407196b0(unsigned n);                                   // number -> text (unit_1407186f0.cpp)
CStringW FUN_1409e3050(const CStringW& strPrefix, int nScope, int nReset);
bool FUN_1409e7930(ItemDropResult& lhs, ItemDropResult& rhs);
bool FUN_1409e7a40(ItemDropResult& lhs, ItemDropResult& rhs);
extern int g_nDebugUI;                                                // 0x143ae0fc0 (uiobject.cpp): debug UI information on
int FUN_1409e1b80(ASTooltip* pTooltip, int nSkillId, int bFromDialog);
// JobSkill / JobSystem::FindSkill (jobsystem.h clashes with skilldatatablecli.h here, see part 4).
class Unk_TooltipJobSkill : public CPtred { public: unsigned m_nId; unsigned short m_nLevel; };   // JobSkill +0x18 / +0x1c
struct Unk_TooltipJobSystemP5
{
    MS2Ptr<Unk_TooltipJobSkill> FUN_1406394d0(unsigned nSkillId);     // JobSystem::FindSkill
};
class MyPC;
Unk_TooltipJobSystemP5* FUN_1416546d0_p5(MyPC* pPC);                  // 0x1416546d0 the job system of a player (JobSystemCli*)
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/commonfiles/timeutil.h"
SkillDataTableCli* FUN_1401958b0_p5();                                // 0x1401958b0 TSingleton<SkillDataTableCli>::GetInstance (exe copy)
CStringTable* FUN_1401a9d70_p5();                                     // 0x1401a9d70 the string table
ItemGachaBoxTable* FUN_14052d230_p5();                                // 0x14052d230 TSingleton<ItemGachaBoxTable>::GetInstance
void* FUN_1403ed2d0_p5();                                             // 0x1403ed2d0 the world service
PCBase* FUN_141bd0cc0_p5(void* pWorld);                               // 0x141bd0cc0 the local player
#include "ms2/client/ms2/achievemanager.h"
CAchieveManager* FUN_1406c7600();                                     // TSingleton<CAchieveManager>::GetInstance (exe copy)
CStringW FUN_14093b970(int nId);                                      // achievement title (achievemanager.cpp)
CStringW FUN_14093c8d0(int nId, int nGrade, int bRaw);                // achievement description
CStringW FUN_14093ce70(int nId, int nGrade);                          // achievement reward text
CStringW FUN_14093e330(CAchieve* pAchieve, int nKey);                 // achievement completion date
CString FUN_140159490(CAchieveData* pData);                           // achievement icon path (achievecondition.cpp, static there)
float FUN_14028d280(unsigned nTicks);                                 // milliseconds -> seconds (commonutil.cpp)
#include "ms2/commonfiles/itemgift.h"                                 // ItemAble
void FUN_1409e2ed0(Scaleform::GFx::Value* pOut, ItemAble& item);
#include "ms2/commonfiles/meratmarketbasketinfo.h"                   // CMeratMarketPremiumProduct
#include "ms2/commonfiles/jobtable.h"
JobTable* FUN_1401d7a50_p5();                                         // 0x1401d7a50 TSingleton<JobTable>::GetInstance (exe copy)
bool FUN_1402226b0(int nJob);                                         // the job code is valid
void FUN_1409e68a0(int nJob, ATL::CAtlArray<unsigned>& jobs, int& nAllowed, CStringW& strOut);   // the job limit text
void FUN_1409e6aa0(int nJob, ATL::CAtlArray<unsigned>& jobs, CStringW& strOut);                  // the disabled job text
#endif
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
CStringW BlockFormat(int, const fmt::ArgList&);
FMT_VARIADIC_W(CStringW, BlockFormat, int)
const int& FUN_1409e8500(const CAtlArray<int>& arr, int nIndex, const int& nDefault);   // arr[nIndex], nDefault when out of range
// ---- end part 6 ----

