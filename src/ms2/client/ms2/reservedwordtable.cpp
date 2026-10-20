// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CReservedWordTable: the "$word$" markers of game texts
// ($MyPCName$, $item:1000$, $npcName:11000001$, $male:..,female:..$, "[y" colour tags ...) and the formatter functions
// behind them. The formatters read many unrecovered singletons (player, world, string tables, feature switches), which
// are declared here as unit-local Unk_Rw* types.
// MS2-UNIT: client\ms2\reservedwordtable.cpp
// MS2-RANGE: 0x1416fa4b0-0x141701380 .text$mn
// MS2-RANGE: 0x1400ff140-0x1400ff2b0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FUN_141700510@Unk_RwOwnerRec@@QEAA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@XZ 0x141700510 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\reservedwordtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cscripttable.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/luautil.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef ATL::CAtlArray<CStringW> CStrArray;

// ---------------------------------------------------------------------------------------------------------------
// Unrecovered helpers (externs bound by VA).
// ---------------------------------------------------------------------------------------------------------------
void FUN_14025a680(const CStringW& str, CStrArray& rOut, const wchar_t* pszSep);    // splits into parts
void FUN_14083d2b0(CStringW& str);                                                  // strips the markup of a word
int FUN_1413faab0(wchar_t ch);                                                      // 1: the word ends in a final consonant
int FUN_1413fab50(wchar_t ch);                                                      // the same for the second josa pair
int FUN_140718200(const CStringW& str);                                             // the number of an argument
int FUN_1407181a0(const CStringW& str);
unsigned __int64 FUN_140718370(const CStringW& str);
CStringW FUN_14016a730(const char* psz, int nCodePage);                             // utf-8 to wide
CStringW FUN_1416e4df0(int nQuestId);                                               // the name of a quest
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1401aa6a0(int nId);                                                    // an npc name by id
CStringW FUN_141700820(int nId);                                                    // 0x141700820
CStringW FUN_1416ff950(int nId);                                                    // 0x1416ff950
int FUN_141658e60(PC* pPc);                                                         // the gender of the player
CString FUN_140740ef0(const char* pszFormat, const CString& strKind, const int& nId);                                              // a text of the common string table

// The local player / world.
class Unk_RwMapInfo { public: void* m_p0; void* m_p1; };
MS2_CHECK_SIZE(Unk_RwMapInfo, 0x10);
class Unk_RwWorld
{
public:
    PC* FUN_141bd0cc0();                                    // the local player
    Unk_RwMapInfo FUN_141bd30a0();                          // the map info of the player
};
Unk_RwWorld* FUN_1403ed2d0();
char FUN_1408851f0(Unk_RwMapInfo* pInfo);                   // the map is a town / safe map
void FUN_1408850f0(Unk_RwMapInfo* pInfo);
void* FUN_140885340(Unk_RwMapInfo* pInfo);
int FUN_1403754f0(void* pCode);
__int64 FUN_141670a00(PC* pPc, int nStat);                  // PCBase stat
class Unk_RwTaxi { public: int FUN_140675730(unsigned short nLevel, int nPvp, int nMapKind); };
Unk_RwTaxi* FUN_1401c0db0();

// Locale switch of the name tables ("npcNamePlural" differs by locale).
class Unk_RwLocale { public: };
Unk_RwLocale* FUN_1409a8b10();
int* FUN_140cfd280(Unk_RwLocale* pLocale);

// A map name with its world map entry.
class Unk_RwMapTable { public: };
Unk_RwMapTable* FUN_140cb17d0();
int FUN_141b98380(Unk_RwMapTable* pTable, int nMapId);

class Unk_RwUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_RwUIManager* FUN_1403ed2b0();
UIRouletteDialog* FUN_1416ffcb0(int nId);
class CScriptTable;
CScriptTable* FUN_141371b30();

// The view / dictionary (maview) switches.
struct Unk_RwView { char m_pad[0x8b]; char m_bMaview; };
struct Unk_RwViewRef { void* m_p0; void* m_p1; };
void FUN_1406cd330(Unk_RwViewRef* pRef);
__int64 FUN_140729ad0(Unk_RwViewRef* pRef);
Unk_RwView* FUN_14035eb90(Unk_RwViewRef* pRef);
void FUN_14035e5b0(Unk_RwViewRef* pRef);

// An item reference (smart pointer to the item data).
struct Unk_RwItemRef { void* m_p0; void* m_p1; };
struct Unk_RwItemData { char m_pad[0x79]; char m_bDictionary; };
void FUN_14053f870(Unk_RwItemRef* pRef, int nItemId);
char FUN_1402ffd90(Unk_RwItemRef* pRef);                    // the reference is empty
Unk_RwItemData* FUN_1401b52a0(Unk_RwItemRef* pRef);
int FUN_14053c5c0(Unk_RwItemData* pData);                   // the item slot kind
void FUN_1401b50d0(Unk_RwItemRef* pRef);

// A maid (housing) entry.
struct Unk_RwOwnerRef { void* m_p0; void* m_p1; };
struct Unk_RwOwnerRec
{
    char m_pad_0[0x34];
    int m_nId;                                              // +0x34
    char m_pad_38[0x88 - 0x38];
    __int64 m_nEnd;                                         // +0x88
    char m_pad_90[0xe8 - 0x90];
    CStringW m_strName;                                     // +0xe8
    CStringW FUN_141700510() { return m_strName; }          // 0x141700510
};
void FUN_141093800(void* pMaid, Unk_RwOwnerRef* pRef);
__int64 FUN_1409ee260(Unk_RwOwnerRef* pRef);
Unk_RwOwnerRec* FUN_14067e8c0(Unk_RwOwnerRef* pRef);
void FUN_14067e620(Unk_RwOwnerRef* pRef);
int FUN_14067db20(Unk_RwOwnerRec* pRec);
CStringW FUN_141093310(void* pMaid);                        // the maid name
struct Unk_RwUserRef { void* m_p0; void* m_p1; };
class Unk_RwUserDb { public: };
Unk_RwUserDb* FUN_1409eed10();
void FUN_14067f780(Unk_RwUserDb* pDb, Unk_RwUserRef* pRef, int nId);
__int64 FUN_14109a370(Unk_RwUserRef* pRef);
struct Unk_RwUser { char m_pad[0x60]; CStringW m_strName; };
Unk_RwUser* FUN_1406810d0(Unk_RwUserRef* pRef);
void FUN_140680b50(Unk_RwUserRef* pRef);
struct Unk_RwMaidRef { void* m_p0; void* m_p1; };
class Unk_RwMaidDb { public: };
Unk_RwMaidDb* FUN_1409eed20();
void FUN_14067f180(Unk_RwMaidDb* pDb, Unk_RwMaidRef* pRef, int nId);
__int64 FUN_140df5ae0(Unk_RwMaidRef* pRef);
struct Unk_RwMaid { char m_pad[0x10]; int m_nSalary; };
Unk_RwMaid* FUN_1406810e0(Unk_RwMaidRef* pRef);
int FUN_1409eee80(Unk_RwMaid* pMaid);
void FUN_140680b80(Unk_RwMaidRef* pRef);
CStringW FUN_140763e10(int nMoney);                         // a money text
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1408116a0(int nStringId, const int& nArg);
__int64 FUN_140869440();
__int64* FUN_1402e4970(__int64* pBase, __int64* pKey);
struct Unk_RwConfig { char m_pad[0x50d0]; int m_nValue; };
Unk_RwConfig* FUN_1401d3200();
int* FUN_1402056b0(int* pValue);
void FUN_1406c47a0(ATL::CTime* pTime, __int64 nTime);
CStringW FUN_1409e90c0(int nStringId, const int& nA, const int& nB, const int& nC, const int& nD, const int& nE);

// ---------------------------------------------------------------------------------------------------------------
// Statics (.text$di)
// ---------------------------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static CString s_aStrNames[7] = {CString("None"), CString("Buy"), CString("Like"), CString("PriceLow"),
                                 CString("PriceHigh"), CString("Create"), CString("EnumEnd")};   // 0x143ae6970 @0x1400ff140
static CString s_strSkill("skill");                                                   // 0x143ae6968 @0x1400ff200
static CString s_strStun("stun");                                                     // 0x143ae6960 @0x1400ff230
static ATL::CAtlMap<unsigned int, CString> s_mapUnknown;                              // 0x143ae69b0 @0x1400ff260
#endif

// ---------------------------------------------------------------------------------------------------------------
// The formatters registered by the ctor (defined below).
// ---------------------------------------------------------------------------------------------------------------
static void Rw_MyPCHp(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_MyPCName(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_MyPCLevel(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Npc(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcTitle(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcName(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcPlural(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcNamePlural(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcFunction(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Item(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_ItemPlural(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Map(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Key(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_PenaltyPrice(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Skill(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Ppr(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Pp2(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Achieve(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Script(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_DungeonTitle(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Quest(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_RouletteTotal(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_RouletteCurrent(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_RoulettePrev(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Gender(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_PetCollectGroup(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_MasteryRecipe(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_MasteryRecipePlural(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Job(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcNameBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcPluralBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_NpcNamePluralBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_ItemBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_MapBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_DungeonTitleBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_QuestBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_PetCollectGroupBold(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_Maview(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_ExternalWeb(CStringW& strOut, CStringW strArg, CStringW& strWhole);
static void Rw_GenderOf(CStringW& strToken, PC* pPc);
static void Rw_NpcLink(unsigned int nId, CStringW strText, CStringW& strOut);
static void Rw_GenderId(CStringW& strToken, int nGender);

// ---------------------------------------------------------------------------------------------------------------
// CReservedWordTable
// ---------------------------------------------------------------------------------------------------------------

// @0x1416fa4b0
CReservedWordTable::CReservedWordTable()
{
    m_mapValue.SetAt(L"$MyPCHp", Rw_MyPCHp);
    m_mapValue.SetAt(L"$MyPCName", Rw_MyPCName);
    m_mapValue.SetAt(L"$MyPCLevel", Rw_MyPCLevel);
    m_mapValue.SetAt(L"$paneltyPrice", Rw_PenaltyPrice);
    m_mapValue.SetAt(L"$ppr", Rw_Ppr);
    m_mapValue.SetAt(L"$pp", Rw_Ppr);
    m_mapValue.SetAt(L"$pp2", Rw_Pp2);
    m_mapValue.SetAt(L"$rouletteTotal", Rw_RouletteTotal);
    m_mapValue.SetAt(L"$rouletteCurrent", Rw_RouletteCurrent);
    m_mapValue.SetAt(L"$roulettePrev", Rw_RoulettePrev);
    m_mapValue.SetAt(L"$male", Rw_Gender);
    m_mapValue.SetAt(L"$female", Rw_Gender);
    m_mapValue.SetAt(L"$key", Rw_Key);

    m_mapObject.SetAt(L"$item", Rw_Item);
    m_mapObject.SetAt(L"$itemPlural", Rw_ItemPlural);
    m_mapObject.SetAt(L"$map", Rw_Map);
    m_mapObject.SetAt(L"$skill", Rw_Skill);
    m_mapObject.SetAt(L"$npc", Rw_Npc);
    m_mapObject.SetAt(L"$npcTitle", Rw_NpcTitle);
    m_mapObject.SetAt(L"$npcName", Rw_NpcName);
    m_mapObject.SetAt(L"$npcPlural", Rw_NpcPlural);
    m_mapObject.SetAt(L"$npcNamePlural", Rw_NpcNamePlural);
    m_mapObject.SetAt(L"$npcFunction", Rw_NpcFunction);
    m_mapObject.SetAt(L"$pp", Rw_Ppr);
    m_mapObject.SetAt(L"$pp2", Rw_Pp2);
    m_mapObject.SetAt(L"$achieve", Rw_Achieve);
    m_mapObject.SetAt(L"$script", Rw_Script);
    m_mapObject.SetAt(L"$dungeonTitle", Rw_DungeonTitle);
    m_mapObject.SetAt(L"$maview", Rw_Maview);
    m_mapObject.SetAt(L"$externalWeb", Rw_ExternalWeb);
    m_mapObject.SetAt(L"$quest", Rw_Quest);
    m_mapObject.SetAt(L"$petCollectGroup", Rw_PetCollectGroup);
    m_mapObject.SetAt(L"$masteryRecipe", Rw_MasteryRecipe);
    m_mapObject.SetAt(L"$masteryRecipePlural", Rw_MasteryRecipePlural);
    m_mapObject.SetAt(L"$job", Rw_Job);

    POSITION pos = m_mapObject.GetStartPosition();
    while (pos != 0)
    {
        CStringW strKey = m_mapObject.GetKeyAt(pos);
        FnWord pfnWord = m_mapObject.GetValueAt(pos);
        m_mapBold.SetAt(strKey, pfnWord);
        m_mapObject.GetNext(pos);
    }
    m_mapBold.SetAt(L"$item", Rw_ItemBold);
    m_mapBold.SetAt(L"$map", Rw_MapBold);
    m_mapBold.SetAt(L"$npc", Rw_NpcBold);
    m_mapBold.SetAt(L"$npcName", Rw_NpcNameBold);
    m_mapBold.SetAt(L"$npcPlural", Rw_NpcPluralBold);
    m_mapBold.SetAt(L"$npcNamePlural", Rw_NpcNamePluralBold);
    m_mapBold.SetAt(L"$dungeonTitle", Rw_DungeonTitleBold);
    m_mapBold.SetAt(L"$quest", Rw_QuestBold);
    m_mapBold.SetAt(L"$petCollectGroup", Rw_PetCollectGroupBold);

    m_mapColor.SetAt(L"[y", CStringW(L"<font color=\"#ffd200\">"));
    m_mapColor.SetAt(L"[b", CStringW(L"<font color=\"#00a2ed\">"));
    m_mapColor.SetAt(L"[g", CStringW(L"<font color=\"#909090\">"));

    m_mapPlain.SetAt(L"$item", Rw_Item);
    m_mapPlain.SetAt(L"$map", Rw_Map);
    m_mapPlain.SetAt(L"$skill", Rw_Skill);
    m_mapPlain.SetAt(L"$npc", Rw_Npc);
    m_mapPlain.SetAt(L"$npcName", Rw_NpcName);
    m_mapPlain.SetAt(L"$achieve", Rw_Achieve);
    m_mapPlain.SetAt(L"$dungeonTitle", Rw_DungeonTitle);
    m_mapPlain.SetAt(L"itemPlural", Rw_ItemPlural);
    m_mapPlain.SetAt(L"$npcPlural", Rw_NpcPlural);
    m_mapPlain.SetAt(L"$npcNamePlural", Rw_NpcNamePlural);
}

// @0x1416fb270
CReservedWordTable::~CReservedWordTable()
{
}

// @0x1416fb300
void CReservedWordTable::FUN_1416fb300(CStringW& str)
{
    FUN_1416fb380(str);
    FUN_1416fb340(str);
}
MS2_REPLACE_METHOD(0x1416FB300, CReservedWordTable, FUN_1416fb300, 49, 0x892501A7);

// @0x1416fb340
void CReservedWordTable::FUN_1416fb340(CStringW& str)
{
    FUN_1416fc320(str, m_mapValue);
}
MS2_REPLACE_METHOD(0x1416FB340, CReservedWordTable, FUN_1416fb340, 46, 0xFE89D269);

// @0x1416fb380
void CReservedWordTable::FUN_1416fb380(CStringW& str)
{
    FUN_1416fc320(str, m_mapObject);
}
MS2_REPLACE_METHOD(0x1416FB380, CReservedWordTable, FUN_1416fb380, 46, 0xF2AE5A81);

// @0x1416fb3c0
int CReservedWordTable::FUN_1416fb3c0(CStringW& str)
{
    FUN_1416fc540(str, m_mapColor);
    return 1;
}
MS2_REPLACE_METHOD(0x1416FB3C0, CReservedWordTable, FUN_1416fb3c0, 53, 0xA68264A1);

// @0x1416fb400
void CReservedWordTable::FUN_1416fb400(CStringW& str, void* pMaid)
{
    if (pMaid == 0)
        return;
    int nPassed = 0;
    CStringW strEnd(L"");
    CStringW strExtend(L"");
    Unk_RwOwnerRef kOwner;
    FUN_141093800(pMaid, &kOwner);
    if (FUN_1409ee260(&kOwner) == 0)
        str.Replace(L"$OwnerName$", FUN_14028de60(0x787));
    else
    {
        if (!FUN_14067e8c0(&kOwner)->FUN_141700510().IsEmpty())
            str.Replace(L"$OwnerName$", FUN_14067e8c0(&kOwner)->FUN_141700510());
        else
        {
            Unk_RwOwnerRec* pRec = FUN_14067e8c0(&kOwner);
            Unk_RwUserRef kUser;
            FUN_14067f780(FUN_1409eed10(), &kUser, pRec->m_nId);
            if (FUN_14109a370(&kUser) == 0)
                str.Replace(L"$OwnerName$", FUN_14028de60(0x787));
            else
                str.Replace(L"$OwnerName$", FUN_1406810d0(&kUser)->m_strName);
            FUN_140680b50(&kUser);
        }
        Unk_RwOwnerRec* pRec2 = FUN_14067e8c0(&kOwner);
        Unk_RwMaidRef kMaid;
        FUN_14067f180(FUN_1409eed20(), &kMaid, pRec2->m_nId);
        if (FUN_140df5ae0(&kMaid) != 0)
        {
            if (FUN_1409eee80(FUN_1406810e0(&kMaid)) == 0)
                str.Replace(L"$MaidSalary$", FUN_14052bd00(0x7a7, FUN_140763e10(FUN_1406810e0(&kMaid)->m_nSalary)));
            else
                str.Replace(L"$MaidSalary$", FUN_14052bd00(0x7a6, FUN_140763e10(FUN_1406810e0(&kMaid)->m_nSalary)));
        }
        nPassed = FUN_14067db20(FUN_14067e8c0(&kOwner));
        __int64 nKey = FUN_140869440();
        __int64 nBase = *FUN_1402e4970(&FUN_14067e8c0(&kOwner)->m_nEnd, &nKey);
        __int64 nExtend = nBase + *FUN_1402056b0(&FUN_1401d3200()->m_nValue) * 0x15180;
        ATL::CTime kEnd;
        ATL::CTime kExtendTime;
        FUN_1406c47a0(&kEnd, FUN_14067e8c0(&kOwner)->m_nEnd);
        FUN_1406c47a0(&kExtendTime, nExtend);
        int nMinute = kEnd.GetMinute();
        int nHour = kEnd.GetHour();
        int nDay = kEnd.GetDay();
        int nMonth = kEnd.GetMonth();
        int nYear = kEnd.GetYear();
        strEnd = FUN_1409e90c0(0x798, nYear, nMonth, nDay, nHour, nMinute);
        nMinute = kExtendTime.GetMinute();
        nHour = kExtendTime.GetHour();
        nDay = kExtendTime.GetDay();
        nMonth = kExtendTime.GetMonth();
        nYear = kExtendTime.GetYear();
        strExtend = FUN_1409e90c0(0x799, nYear, nMonth, nDay, nHour, nMinute);
        FUN_140680b80(&kMaid);
    }
    FUN_14067e620(&kOwner);
    str.Replace(L"$MaidName$", FUN_141093310(pMaid));
    str.Replace(L"$MaidEndDate$", strEnd);
    str.Replace(L"$MaidExtendDate$", strExtend);
    CStringW strPassed = FUN_1408116a0(0x7a5, nPassed);
    FUN_1416fc710(strPassed, nPassed);
    str.Replace(L"$MaidPassedDay$", strPassed);
}

// @0x1416fbc20
void CReservedWordTable::FUN_1416fbc20(CStringW& str, PC* pPc)
{
    int nPos = 0;
    int nEnd;
    while ((nPos = str.Find(L"$", nPos)) != -1)
    {
        nEnd = str.Find(L"$", nPos + 1);
        if (nEnd == -1)
            break;
        CStringW strToken = str.Mid(nPos, nEnd - nPos + 1);
        CStringW strKey = FUN_1416fc180(CStringW(strToken));
        if (strKey.Compare(L"$male") != 0 && strKey.Compare(L"$female") != 0)
            nPos = nEnd + 1;
        else
        {
            Rw_GenderOf(strToken, pPc);
            str.Delete(nPos, nEnd - nPos + 1);
            str.Insert(nPos, strToken);
        }
    }
}

// @0x1416fbda0
void CReservedWordTable::FUN_1416fbda0(CStringW& str, int nGender)
{
    int nPos = 0;
    int nEnd;
    while ((nPos = str.Find(L"$", nPos)) != -1)
    {
        nEnd = str.Find(L"$", nPos + 1);
        if (nEnd == -1)
            break;
        CStringW strToken = str.Mid(nPos, nEnd - nPos + 1);
        CStringW strKey = FUN_1416fc180(CStringW(strToken));
        if (strKey.Compare(L"$male") != 0 && strKey.Compare(L"$female") != 0)
            nPos = nEnd + 1;
        else
        {
            Rw_GenderId(strToken, nGender);
            str.Delete(nPos, nEnd - nPos + 1);
            str.Insert(nPos, strToken);
        }
    }
}

// @0x1416fbf20
void CReservedWordTable::FUN_1416fbf20(CStringW& str)
{
    FUN_1416fc320(str, m_mapBold);
}
MS2_REPLACE_METHOD(0x1416FBF20, CReservedWordTable, FUN_1416fbf20, 48, 0x967B40A5);

// @0x1416fbf60
void CReservedWordTable::FUN_1416fbf60(CStringW& str, unsigned short nLevel)
{
    str.Replace(L"$level$", StringFormat(L"{0}", nLevel));
}
MS2_REPLACE_METHOD(0x1416FBF60, CReservedWordTable, FUN_1416fbf60, 115, 0x395CBD8F);

// @0x1416fbfe0
CStringW CReservedWordTable::FUN_1416fbfe0(unsigned int nMapId, CStringW strColor)
{
    CStringW strRet;
    if (FUN_141b98380(FUN_140cb17d0(), nMapId) == 0)
        strRet = CStringTable::GetInstance()->FUN_141811980(3, nMapId);
    else
        strRet = StringFormat(L"<u><a href='event:worldmap,{0}'><FONT color='{2}'>{1}</FONT></a></u>",
                              StringFormat(L"{0}", nMapId), CStringTable::GetInstance()->FUN_141811980(3, nMapId), strColor);
    return strRet;
}

// @0x1416fc180
CStringW CReservedWordTable::FUN_1416fc180(CStringW str)
{
    int nColon = 0;
    nColon = str.Find(L":", 0);
    if (nColon != -1)
        return str.Mid(0, nColon);
    return str.Mid(0, str.GetLength() - 1);
}
MS2_REPLACE_METHOD(0x1416FC180, CReservedWordTable, FUN_1416fc180, 196, 0x5B883C35);

// @0x1416fc250
CStringW CReservedWordTable::FUN_1416fc250(CStringW str)
{
    int nColon = 0;
    nColon = str.Find(L":", 0);
    if (nColon != -1)
        return str.Mid(nColon + 1, str.GetLength() - nColon - 2);
    return CStringW(L"");
}
MS2_REPLACE_METHOD(0x1416FC250, CReservedWordTable, FUN_1416fc250, 201, 0x1AF7243D);

// @0x1416fc320
void CReservedWordTable::FUN_1416fc320(CStringW& str, WordMap& map)
{
    int nPos = 0;
    int nEnd;
    while ((nPos = str.Find(L"$", nPos)) != -1)
    {
        nEnd = str.Find(L"$", nPos + 1);
        if (nEnd == -1)
            break;
        CStringW strToken = str.Mid(nPos, nEnd - nPos + 1);
        FnWord pfnWord = 0;
        bool bFound = map.Lookup(FUN_1416fc180(CStringW(strToken)), pfnWord);
        if (bFound)
        {
            pfnWord(strToken, FUN_1416fc250(CStringW(strToken)), str);
            str.Delete(nPos, nEnd - nPos + 1);
            str.Insert(nPos, strToken);
        }
        else
            nPos = nEnd + 1;
    }
}

// @0x1416fc540
void CReservedWordTable::FUN_1416fc540(CStringW& str, TextMap& map)
{
    int nStart = 0;
    int nEnd;
    while ((nStart = str.Find(L"[", nStart)) != -1)
    {
        nEnd = str.Find(L"]", nStart + 1);
        if (nEnd == -1)
            break;
        CStringW strRest = str.Mid(nStart, nEnd - nStart + 1);
        CStringW strValue;
        CStringW strKey = FUN_1416fc180(CStringW(strRest));
        if (!map.Lookup(strKey, strValue))
            nStart = nEnd + 1;
        else
        {
            str.Delete(nEnd, 1);
            str.Insert(nEnd, L"</font>");
            int nLen = strKey.GetLength();
            str.Delete(nStart, nLen + 1);
            str.Insert(nStart, strValue);
        }
    }
}

// @0x1416fc6f0
void CReservedWordTable::FUN_1416fc6f0()
{
}

// @0x1416fc710
void CReservedWordTable::FUN_1416fc710(CStringW& str, int nCount)
{
    int nFirst = str.Find(L"$", 0);
    int nSecond = str.Find(L"$", nFirst + 1);
    if (nFirst != -1 && nSecond != -1)
    {
        CStringW strToken = str.Mid(nFirst, nSecond - nFirst + 1);
        if (!strToken.IsEmpty())
        {
            CStringW strBody(strToken);
            strBody.Trim(L"$");
            CStrArray aItems;
            FUN_14025a680(strBody, aItems, L",");
            CStringW strPick(L"");
            for (size_t i = 0; i < aItems.GetCount(); i++)
            {
                CStrArray aParts;
                FUN_14025a680(aItems[i], aParts, L":");
                if (aParts.GetCount() == 2)
                {
                    if (aParts[0].CompareNoCase(L"singular") == 0)
                    {
                        if (nCount == 1)
                            strPick = aParts[1];
                    }
                    else if (aParts[0].CompareNoCase(L"plural") == 0 && nCount > 1)
                        strPick = aParts[1];
                }
            }
            if (!strPick.IsEmpty())
                str.Replace(strToken, strPick);
        }
    }
}

// ---------------------------------------------------------------------------------------------------------------
// The word formatters. (out, argument, whole text); the argument is passed by value and destroyed by the callee.
// ---------------------------------------------------------------------------------------------------------------

// @0x1416fc9c0
static void Rw_MyPCHp(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
    {
        strOut = L"";
        return;
    }
    strOut.Format(L"%d", FUN_141670a00(pPc, 4));
}

// @0x1416fca60
static void Rw_MyPCName(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
    {
        strOut = L"";
        return;
    }
    strOut = pPc->vfunc_77();
}

// @0x1416fcb10
static void Rw_MyPCLevel(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
    {
        strOut = L"";
        return;
    }
    unsigned short nLevel = (unsigned short)pPc->vfunc_78();
    strOut.Format(L"%d", nLevel);
}


// @0x1416fcbb0
static void Rw_Npc(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut = FUN_1401aa6a0(_wtoi(strArg));
}

// @0x1416fcc30
static void Rw_NpcTitle(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut = CStringTable::GetInstance()->FUN_141811980(0x13, _wtoi(strArg));
}

// @0x1416fccd0
static void Rw_NpcName(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut = CStringTable::GetInstance()->FUN_141811980(2, _wtoi(strArg));
}

// @0x1416fcd70
static void Rw_NpcPlural(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    int nLocale = *FUN_140cfd280(FUN_1409a8b10());
    if (nLocale < 0 || (nLocale > 1 && nLocale != 3))
        strOut = FUN_141700820(_wtoi(strArg));
    else
        strOut = FUN_1401aa6a0(_wtoi(strArg));
}

// @0x1416fce70
static void Rw_NpcNamePlural(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    int nLocale = *FUN_140cfd280(FUN_1409a8b10());
    if (nLocale < 0 || (nLocale > 1 && nLocale != 3))
        strOut = CStringTable::GetInstance()->FUN_141811980(0x3d, _wtoi(strArg));
    else
        strOut = CStringTable::GetInstance()->FUN_141811980(2, _wtoi(strArg));
}

// @0x1416fcfb0
static void Rw_NpcFunction(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut = CStringTable::GetInstance()->FUN_141811980(10, _wtoi(strArg));
}

// @0x1416fd050
static void Rw_Item(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut = CStringTable::GetInstance()->FUN_141811980(1, _wtoi(strArg));
}

// @0x1416fd0f0
static void Rw_ItemPlural(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    int nLocale = *FUN_140cfd280(FUN_1409a8b10());
    if (nLocale < 0 || (nLocale > 1 && nLocale != 3))
        strOut = CStringTable::GetInstance()->FUN_141811980(0x3e, _wtoi(strArg));
    else
        strOut = CStringTable::GetInstance()->FUN_141811980(1, _wtoi(strArg));
}

// @0x1416fd230
static void Rw_Map(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut = CStringTable::GetInstance()->FUN_141811980(3, _wtoi(strArg));
}

// @0x1416fd2d0
static void Rw_Key(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut = CStringTable::GetInstance()->FUN_1418125b0(_wtoi(strArg));
}

// @0x1416fd360
static void Rw_PenaltyPrice(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        strOut = L"";
    else
    {
        Unk_RwMapInfo kMap = FUN_1403ed2d0()->FUN_141bd30a0();
        char cTown = FUN_1408851f0(&kMap);
        FUN_1408850f0(&kMap);
        if (cTown == 0)
        {
            Unk_RwMapInfo kMap2 = FUN_1403ed2d0()->FUN_141bd30a0();
            int nMapKind = FUN_1403754f0(FUN_140885340(&kMap2));
            int nPvp = pPc->FUN_141661aa0();
            unsigned short nLevel = (unsigned short)pPc->vfunc_78();
            unsigned int nPrice = FUN_1401c0db0()->FUN_140675730(nLevel, nPvp, nMapKind);
            FUN_1408850f0(&kMap2);
            strOut.Format(L"%d", nPrice);
        }
        else
            strOut = L"";
    }
}

// @0x1416fd510
static void Rw_Skill(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut = CStringTable::GetInstance()->FUN_141811980(4, _wtoi(strArg));
}

// "$ppr" / "$pp2": the josa pair ("eun, neun") chosen by the last character of the word before the marker.
// @0x1416fd5b0
static void Rw_Ppr(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    CStrArray aWords;
    FUN_14025a680(strWhole, aWords, L"$ ");
    strOut.Replace(L"$", L"");
    for (size_t i = 0; i < aWords.GetCount(); i++)
    {
        if (strOut.Compare(aWords[i]) == 0 && i != 0)
        {
            CStringW strPrev(aWords[i - 1]);
            FUN_14083d2b0(strPrev);
            strPrev.Remove(L']');
            strPrev.Remove(L')');
            CStringW strWord(strPrev);
            if (strWord.GetLength() > 0)
            {
                CStrArray aForms;
                FUN_14025a680(strArg, aForms, L", ");
                if (aForms.GetCount() != 2)
                    return;
                wchar_t chLast = strWord.GetAt(strWord.GetLength() - 1);
                int nFinal = FUN_1413faab0(chLast);
                CStringW* pForm;
                if (nFinal == 1)
                    pForm = &aForms[1];
                else
                    pForm = &aForms[0];
                strOut = *pForm;
                return;
            }
        }
    }
}

// @0x1416fd860
static void Rw_Pp2(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    CStrArray aWords;
    FUN_14025a680(strWhole, aWords, L"$ ");
    strOut.Replace(L"$", L"");
    for (size_t i = 0; i < aWords.GetCount(); i++)
    {
        if (strOut.Compare(aWords[i]) == 0 && i != 0)
        {
            CStringW strPrev(aWords[i - 1]);
            FUN_14083d2b0(strPrev);
            strPrev.Remove(L']');
            strPrev.Remove(L')');
            CStringW strWord(strPrev);
            if (strWord.GetLength() > 0)
            {
                CStrArray aForms;
                FUN_14025a680(strArg, aForms, L", ");
                if (aForms.GetCount() != 2)
                    return;
                wchar_t chLast = strWord.GetAt(strWord.GetLength() - 1);
                int nFinal = FUN_1413fab50(chLast);
                CStringW* pForm;
                if (nFinal == 1)
                    pForm = &aForms[1];
                else
                    pForm = &aForms[0];
                strOut = *pForm;
                return;
            }
        }
    }
}

// @0x1416fdb10
static void Rw_Achieve(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    int nId = _wtoi(strArg);
    if (nId == 0)
        return;
    strOut = CStringTable::GetInstance()->FUN_141811980(0x18, nId);
}

// @0x1416fdbd0
static void Rw_Script(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    unsigned __int64 nId = FUN_140718370(strArg);
    if (nId == 0)
        return;
    strOut = FUN_141371b30()->GetScript(nId);
}

// @0x1416fdc80
static void Rw_DungeonTitle(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    int nId = FUN_140718200(strArg);
    if (nId == 0)
        return;
    strOut = FUN_1416ff950(nId);
}

// @0x1416fdd20
static void Rw_Quest(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    int nId = FUN_140718200(strArg);
    if (nId == 0)
        return;
    strOut = FUN_1416e4df0(nId);
}

// @0x1416fddc0
static void Rw_RouletteTotal(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    UIRouletteDialog* pDlg = FUN_1416ffcb0(0x4e6d);
    if (pDlg != 0)
    {
        int nCount = pDlg->FUN_141ac5a00();
        strOut = StringFormat(L"{0}", nCount);
    }
}

// @0x1416fde70
static void Rw_RouletteCurrent(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    UIRouletteDialog* pDlg = FUN_1416ffcb0(0x4e6d);
    if (pDlg != 0)
    {
        int nIndex = pDlg->FUN_141ac59e0();
        nIndex = nIndex + 1;
        strOut = StringFormat(L"{0}", nIndex);
    }
}

// @0x1416fdf20
static void Rw_RoulettePrev(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    UIRouletteDialog* pDlg = FUN_1416ffcb0(0x4e6d);
    if (pDlg != 0)
    {
        int nIndex = pDlg->FUN_141ac59e0();
        strOut = StringFormat(L"{0}", nIndex);
    }
}

// "$male:..,female:..$": the form of the local player's gender.
// @0x1416fdfd0
static void Rw_Gender(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        strOut = L"";
    else
    {
        strOut.Replace(L"$", L"");
        CStrArray aItems;
        FUN_14025a680(strOut, aItems, L",");
        CStringW strPick(L"");
        for (size_t i = 0; i < aItems.GetCount(); i++)
        {
            CStrArray aParts;
            FUN_14025a680(aItems[i], aParts, L":");
            if (aParts.GetCount() == 2)
            {
                if (aParts[0].CompareNoCase(L"male") == 0)
                {
                    if (FUN_141658e60(pPc) == 0)
                        strPick = aParts[1];
                }
                else if (aParts[0].CompareNoCase(L"female") == 0 && FUN_141658e60(pPc) == 1)
                    strPick = aParts[1];
            }
        }
        strOut = strPick;
    }
}

// @0x1416fe1f0
static void Rw_PetCollectGroup(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    int nId = FUN_1407181a0(strArg);
    strOut = CStringTable::GetInstance()->FUN_141811980(0x41, nId);
}

// @0x1416fe280
static void Rw_MasteryRecipe(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    int nId = FUN_1407181a0(strArg);
    strOut = CStringTable::GetInstance()->FUN_141811980(0x2f, nId);
}

// @0x1416fe310
static void Rw_MasteryRecipePlural(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    int nId = FUN_1407181a0(strArg);
    strOut = CStringTable::GetInstance()->FUN_141811980(0x4e, nId);
}

// @0x1416fe3a0
static void Rw_Job(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    int nId = FUN_1407181a0(strArg);
    strOut = CStringTable::GetInstance()->FUN_141811980(6, nId);
}

// The gender form of a marker by the gender of pPc (null: the local player).
// @0x1416fe430
static void Rw_GenderOf(CStringW& strToken, PC* pPc)
{
    int nGender;
    if (pPc == 0)
    {
        PC* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pLocal == 0)
        {
            strToken = L"";
            return;
        }
        nGender = FUN_141658e60(pLocal);
    }
    else
        nGender = FUN_141658e60(pPc);
    strToken.Replace(L"$", L"");
    CStrArray aItems;
    FUN_14025a680(strToken, aItems, L",");
    CStringW strPick(L"");
    for (size_t i = 0; i < aItems.GetCount(); i++)
    {
        CStrArray aParts;
        FUN_14025a680(aItems[i], aParts, L":");
        if (aParts.GetCount() == 2)
        {
            if (aParts[0].CompareNoCase(L"male") == 0)
            {
                if (nGender == 0)
                    strPick = aParts[1];
            }
            else if (aParts[0].CompareNoCase(L"female") == 0 && nGender == 1)
                strPick = aParts[1];
        }
    }
    strToken = strPick;
}

// @0x1416fe660
static void Rw_GenderId(CStringW& strToken, int nGender)
{
    PC* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal == 0)
        strToken = L"";
    else
    {
        strToken.Replace(L"$", L"");
        CStrArray aItems;
        FUN_14025a680(strToken, aItems, L",");
        CStringW strPick(L"");
        for (size_t i = 0; i < aItems.GetCount(); i++)
        {
            CStrArray aParts;
            FUN_14025a680(aItems[i], aParts, L":");
            if (aParts.GetCount() == 2)
            {
                if (aParts[0].CompareNoCase(L"male") == 0)
                {
                    if (nGender == 0)
                        strPick = aParts[1];
                }
                else if (aParts[0].CompareNoCase(L"female") == 0 && nGender == 1)
                    strPick = aParts[1];
            }
        }
        strToken = strPick;
    }
}

// The encyclopedia link of a monster / npc: the dictionary page when the feature is on, else the web page.
// @0x1416fe850
static void Rw_NpcLink(unsigned int nId, CStringW strText, CStringW& strOut)
{
    strOut.Empty();
    Unk_RwViewRef kView;
    FUN_1406cd330(&kView);
    if (FUN_140729ad0(&kView) == 0 || FUN_14035eb90(&kView)->m_bMaview == 0)
        strOut = strText;
    else
    {
        const char* pszKind;
        if (nId / 10000000 == 1)
            pszKind = "NpcView";
        else
            pszKind = "MonsterView";
        const char* pszKindArg = pszKind;
        CString strUrl = Unk_SocketFormat("maview:/Encyclopedia/{0}?c={1:08d}", pszKindArg, nId);
        if (CFeatureManager::GetInstance()->FUN_14036d570(0x2f) == 1)
            strOut = StringFormat(L"<u><a href='event:npcdictionary,{0}'><FONT color='#5c2b00'>{1}</FONT></a></u>", nId, strText);
        else
            strOut = StringFormat(L"<a href='event:webPage,{0}'><FONT color='#5c2b00'><u>{1}</u></FONT></a>",
                                  FUN_14016a730((const char*)strUrl, 0), strText);
    }
    FUN_14035e5b0(&kView);
}

// @0x1416fea90
static void Rw_NpcBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    CStringW strName;
    Rw_Npc(strName, CStringW(strArg), strWhole);
    Rw_NpcLink(FUN_140718200(strArg), strName, strOut);
}

// @0x1416feb30
static void Rw_NpcNameBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    CStringW strName;
    Rw_NpcName(strName, CStringW(strArg), strWhole);
    Rw_NpcLink(FUN_140718200(strArg), strName, strOut);
}

// @0x1416febd0
static void Rw_NpcPluralBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    CStringW strName;
    Rw_NpcPlural(strName, CStringW(strArg), strWhole);
    Rw_NpcLink(FUN_140718200(strArg), strName, strOut);
}

// @0x1416fec70
static void Rw_NpcNamePluralBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    CStringW strName;
    Rw_NpcNamePlural(strName, CStringW(strArg), strWhole);
    Rw_NpcLink(FUN_140718200(strArg), strName, strOut);
}

// @0x1416fed10
static void Rw_ItemBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    int nItemId = _wtoi(strArg);
    if (nItemId != 0)
    {
        Unk_RwItemRef kItem;
        FUN_14053f870(&kItem, nItemId);
        if (FUN_1402ffd90(&kItem) == 0)
        {
            if (FUN_1401b52a0(&kItem)->m_bDictionary == 0)
                strOut = CStringTable::GetInstance()->FUN_141811980(1, nItemId);
            else
            {
                CString strView;
                int nKind = FUN_14053c5c0(FUN_1401b52a0(&kItem));
                if (nKind == 1)
                    strView = "ItemEquipView";
                else if (nKind == 6)
                    strView = "ItemInstallView";
                else if (nKind == 9)
                    strView = "ItemRideView";
                else
                    strView = "ItemEtcView";
                CStringW strName = CStringTable::GetInstance()->FUN_141811980(1, nItemId);
                CString strUrl = StringFormat("maview:/Encyclopedia/{0}?c={1:08d}", strView, nItemId);
                if (CFeatureManager::GetInstance()->FUN_14036d570(0x2f) == 1)
                    strOut = StringFormat(L"<u><a href='event:itemdictionary,{0}'><FONT color='#5c2b00'>{1}</FONT></a></u>", (unsigned int)nItemId, strName);
                else
                    strOut = StringFormat(L"<a href='event:webPage,{0}'><u><FONT color='#5c2b00'>{1}</FONT></u></a>",
                                          FUN_14016a730((const char*)strUrl, 0), strName);
            }
        }
        FUN_1401b50d0(&kItem);
    }
}

// @0x1416ff030
static void Rw_MapBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    int nMapId = _wtoi(strArg);
    if (nMapId != 0)
    {
        if (FUN_141b98380(FUN_140cb17d0(), nMapId) == 0)
            strOut = CStringTable::GetInstance()->FUN_141811980(3, nMapId);
        else
        {
            CStringW strName = CStringTable::GetInstance()->FUN_141811980(3, nMapId);
            strOut = StringFormat(L"<u><a href='event:worldmap,{0}'><FONT color='#5c2b00'>{1}</FONT></a></u>",
                                  StringFormat(L"{0}", (unsigned int)nMapId), strName);
        }
    }
}

// @0x1416ff1b0
static void Rw_DungeonTitleBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    int nId = FUN_140718200(strArg);
    if (nId == 0)
        return;
    strOut = StringFormat(L"<u><a href='event:dungeon,{0}'><FONT color='#5c2b00'>{1}</FONT></a></u>", (unsigned int)nId, FUN_1416ff950(nId));
}

// @0x1416ff280
static void Rw_QuestBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    int nId = FUN_140718200(strArg);
    if (nId == 0)
        return;
    strOut = StringFormat(L"<u><a href='event:quest,{0}'><FONT color='#5c2b00'>{1}</FONT></a></u>", (unsigned int)nId, FUN_1416e4df0(nId));
}

// @0x1416ff350
static void Rw_PetCollectGroupBold(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    int nId = FUN_1407181a0(strArg);
    strOut = StringFormat(L"<u><a href='event:petCollectGroup,{0}'><FONT color='#5c2b00'>{1}</FONT></a></u>", nId,
                          CStringTable::GetInstance()->FUN_141811980(0x41, nId));
}

// "text|url|color": splits the arguments of a web link.
// @0x1416ff890
static bool Rw_SplitLink(const CStrArray& aParts, CStringW& strText, CStringW& strUrl, CStringW& strColor)
{
    size_t nCount = aParts.GetCount();
    if (nCount < 2)
        return false;
    strText = aParts[0];
    strText.Trim();
    strUrl = aParts[1];
    strUrl.Trim();
    if (nCount > 2)
    {
        strColor = aParts[2];
        strColor.Trim();
    }
    return true;
}

// @0x1416ff420
static void Rw_Maview(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    CStrArray aParts;
    FUN_14025a680(strArg, aParts, L",");
    CStringW strText, strUrl, strColor;
    if (Rw_SplitLink(aParts, strText, strUrl, strColor))
    {
        if (strUrl.Replace(L"http://maview.nexon.com/", L"maview:/") == 0)
            strUrl.Replace(L"maview.nexon.com/", L"maview:/");
        CStringW strFormat(L"<a href ='event:webPage,{0}'><u>{1}</u></a></font>");
        strOut = StringFormat((const wchar_t*)strFormat, strUrl, strText);
        if (!strColor.IsEmpty())
        {
            CStringW strColored(L"<font color='#{0}'>{1}</font>");
            strOut = StringFormat((const wchar_t*)strColored, strColor, strOut);
        }
    }
}

// @0x1416ff670
static void Rw_ExternalWeb(CStringW& strOut, CStringW strArg, CStringW& strWhole)
{
    strOut.Empty();
    CStrArray aParts;
    FUN_14025a680(strArg, aParts, L",");
    CStringW strText, strUrl, strColor;
    if (Rw_SplitLink(aParts, strText, strUrl, strColor))
    {
        CStringW strFormat(L"<a href ='event:externalWeb,{0}'><u>{1}</u></a></font>");
        strOut = StringFormat((const wchar_t*)strFormat, strUrl, strText);
        if (!strColor.IsEmpty())
        {
            CStringW strColored(L"<font color='#{0}'>{1}</font>");
            strOut = StringFormat((const wchar_t*)strColored, strColor, strOut);
        }
    }
}

// @0x141700820
CStringW FUN_141700820(int nId)
{
    CStringW strFirst = CStringTable::GetInstance()->FUN_141811980(0x13, nId);
    CStringW strSecond = CStringTable::GetInstance()->FUN_141811980(0x3d, nId);
    if (strFirst.GetLength() == 0)
        return strSecond;
    CStringW strRet;
    strRet.Format(L"%s %s", (const wchar_t*)strFirst, (const wchar_t*)strSecond);
    return strRet;
}

// @0x1416ff950
CStringW FUN_1416ff950(int nId)
{
    return CStringTable::GetInstance()->FUN_141811980(0x14, nId);
}

// @0x1416ffcb0
UIRouletteDialog* FUN_1416ffcb0(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> spDialog = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (spDialog.get())
            return dynamic_cast<UIRouletteDialog*>((UIObject*)spDialog);
    }
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb5d30-0x142cb5dc0 .text$yd
