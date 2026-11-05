// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemRemakeScrollTable: the item option remake scroll table
// (Table/itemRemakeScroll.xml) and its CItemRemakeScrollData rows, the item option remake helpers (lock items, sales,
// option texts; itemremakeoption.h) and the encoders/decoders of the remake packet records (citemremakeoptionpacket.h).
// File name assumed (the exe has no assert path for it); method names are invented.
// MS2-UNIT: ?\itemremakescrolldata.cpp
// MS2-RANGE: 0x1400ba7d0-0x1400ba890 .text$di
// MS2-RANGE: 0x140615410-0x14061ce90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAIAEAH$0A@@?$pair@HH@std@@QEAA@AEAIAEAH@Z 0x140619850 ; unique
// MS2-PIN: ??$_Emplace_back@U?$pair@HH@std@@@?$_Uninitialized_backout_al@PEAU?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX$$QEAU?$pair@HH@1@@Z 0x14061a0f0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAX$$QEAU?$pair@HH@1@@Z 0x14061a150 ; unique
// MS2-PIN: ??$_Emplace_reallocate@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAPEAU?$pair@HH@1@QEAU21@$$QEAU21@@Z 0x14061a210 ; unique
// MS2-PIN: ??$_Ptr_move_cat@U?$pair@HH@std@@U12@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAU?$pair@HH@0@0@Z 0x14061a450 ; unique
// MS2-PIN: ??$_Uninitialized_move@PEAU?$pair@HH@std@@PEAU12@V?$allocator@U?$pair@HH@std@@@2@@std@@YAPEAU?$pair@HH@0@QEAU10@0PEAU10@AEAV?$allocator@U?$pair@HH@std@@@0@@Z 0x14061a480 ; unique
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAU?$pair@HH@std@@PEAU12@V?$allocator@U?$pair@HH@std@@@2@@std@@YAPEAU?$pair@HH@0@PEAU10@QEAU10@1AEAV?$allocator@U?$pair@HH@std@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x14061a550 ; unique
// MS2-PIN: ??$construct@U?$pair@HH@std@@U12@@?$_Default_allocator_traits@V?$allocator@U?$pair@HH@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@HH@std@@@1@QEAU?$pair@HH@1@$$QEAU31@@Z 0x14061a5e0 ; unique
// MS2-PIN: ??$emplace_back@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX$$QEAU?$pair@HH@1@@Z 0x14061a630 ; unique
// MS2-PIN: ??$forward@U?$pair@HH@std@@@std@@YA$$QEAU?$pair@HH@0@AEAU10@@Z 0x14061a6b0 ; prop
// MS2-PIN: ??$move@AEAU?$pair@HH@std@@@std@@YA$$QEAU?$pair@HH@0@AEAU10@@Z 0x14061a6c0 ; prop
// MS2-PIN: ??A?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAAEAU?$pair@HH@1@_K@Z 0x14061ad10 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCItemOption@@@@QEBAPEAVCItemOption@@XZ 0x14061ad40 ; unique
// MS2-PIN: ?_Change_array@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXQEAU?$pair@HH@2@_K1@Z 0x14061c8e0 ; unique
// MS2-PIN: ?_Has_unused_capacity@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEBA_NXZ 0x14061c9f0 ; unique
// MS2-PIN: ?_Orphan_range@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEBAXPEAU?$pair@HH@2@0@Z 0x14061ca40 ; unique
// MS2-PIN: ?_Reallocate_exactly@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAX_K@Z 0x14061ca50 ; unique
// MS2-PIN: ?_Umove@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAPEAU?$pair@HH@2@PEAU32@00@Z 0x14061cc10 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXPEAU?$pair@HH@2@00U?$integral_constant@_N$00@2@@Z 0x14061cc50 ; prop
// MS2-PIN: ?_Umove_if_noexcept@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAXPEAU?$pair@HH@2@00@Z 0x14061cc90 ; unique
// MS2-PIN: ?push_back@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX$$QEAU?$pair@HH@2@@Z 0x14061ccf0 ; unique
// MS2-PIN: ?reserve@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX_K@Z 0x14061cd20 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CItemRemakeScrollTable@@6B?$TSingleton@VCItemRemakeScrollTable@@@@@ 0x142d69f90
// MS2-PIN: ??_7CItemRemakeScrollTable@@6B?$CValidData@VCItemRemakeScrollTable@@@@@ 0x142d69fb0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemremakescrolldata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <typeinfo>
#include <utility>
#include <vector>
#include "ms2/ms2format.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/itemoption.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/citemoptiontable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citemremakescrolldata.h"
#include "ms2/placeholder/citemremakescrolltable.h"
#include "ms2/placeholder/citemremakeoptionpacket.h"
#include "ms2/placeholder/itemremakeoption.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
class Unk_1401b4ec0 { public: Unk_1401b4ec0(CLockCriticalSection&, int); ~Unk_1401b4ec0(); private: void* m_p; };  // C3: the scoped lock (0x1401b4ec0 / 0x1401b5120, matched in commonfiles/banktable.cpp)
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

bool FUN_14028f650(struct Unk_XmlElement*);   // C3: was FUN_14028f650
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& rValue);   // index or -1

// CItem's records: the item data (CItem::FUN_140527840) and the enchant / option status (CItem::FUN_1405278a0).
class Unk_ItemEquipData : public CItemData {};
class Unk_ItemEnchantData : public CItemStatus {};

class Unk_140166430* FUN_140166430();   // C3: was FUN_140166430
void* FUN_1401c0d90();   // C3: was FUN_1401c0d90
const CString& GetStatName(unsigned nStat);                 // the xml name of a stat
const CString& FUN_14081d380(int nSpecial);                 // the xml name of a special stat
int FindStatByName(const CStringA& strName);                // stat name -> id (-1 when none)
unsigned FUN_14081d260(const CStringA& strName);            // special option name -> id (0 when none; C3: the exe returns unsigned)
bool IsStatKindTwo(int nStat);                              // the stat value is a percent
bool FUN_14081dcd0(int nSaType);                            // the SA value is a percent
CStringW FUN_140631600(int nStat, BaseOption* pBase);       // the text of a stat option
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData);    // the text of a special stat option
CStringW GetStringCommon(int nStringId);                      // a common string by id
CStringW GetStringCommonByKey(const CStringW& str);                // a string table text
CStringW FUN_14183e9c0(CStringW strName, int nRank);        // the item name coloured by rank
int FUN_14053feb0(int nItemId);                             // the default rank of an item
unsigned FUN_140482050(unsigned nAmount, unsigned nScale);  // scaled amount
void FUN_14025a680(CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* pszDelim);
int FUN_1406198a0(int nValue, float fRate);

// The option list of the remake records (Unk_RemakeOptionList50) is a vector of (option index, value) pairs.
typedef std::vector<std::pair<int, int> > Unk_RemakeOptionPairs;

// The market sort-key names of an included header (names invented).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CItemRemakeScrollTable::s_bInit;
#endif

// ---- CItemRemakeScrollData ----

// @0x140615410
CItemRemakeScrollData::CItemRemakeScrollData()
    : m_nLevelMin(0), m_nLevelMax(0), m_nPetKind(0), m_nLockOption(RemakeScrollOpValueNone),
      m_nOptionKind(RemakeScrollOpKindNone), m_nOptionValue(RemakeScrollOpValueNone)
{
}

// @0x1406154d0
CItemRemakeScrollData::~CItemRemakeScrollData()
{
    m_arrSlots.RemoveAll();
    m_arrRanks.RemoveAll();
    m_arrItemTypes.RemoveAll();
}

// ---- CItemRemakeScrollTable ----

// @0x140615570
CItemRemakeScrollTable::CItemRemakeScrollTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140615640
CItemRemakeScrollTable::~CItemRemakeScrollTable()
{
    m_map.RemoveAll();
}

// @0x140615700
int CItemRemakeScrollTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "itemRemakeScroll.xml");
    FUN_1401d1160(strPath);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 1;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("remakeScroll")); pNode != 0;
         pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("remakeScroll")))
    {
        if (!FUN_14028f650((struct Unk_XmlElement*)(pNode)))
            continue;
        int nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<int&>(nId));
        if (nId == 0)
            continue;
        CItemRemakeScrollDataPtr spData(new CItemRemakeScrollData);
        if (spData == 0)
            continue;
        XmlGetAttr((class TiXmlElement*)(pNode), "minLv", reinterpret_cast<unsigned short&>(spData->m_nLevelMin));
        XmlGetAttr((class TiXmlElement*)(pNode), "maxLv", reinterpret_cast<unsigned short&>(spData->m_nLevelMax));
        XmlTokenList(pNode, "rank", spData->m_arrRanks);
        XmlTokenList(pNode, "slot", spData->m_arrSlots);
        XmlGetAttr((class TiXmlElement*)(pNode), "onlyPet", reinterpret_cast<int&>(spData->m_nPetKind));
        XmlTokenList(pNode, "item", spData->m_arrItemTypes);
        XmlValue(pNode, "representOpValue", spData->m_nLockOption);
        XmlValue(pNode, "addOpKind", spData->m_nOptionKind);
        XmlValue(pNode, "addOpValue", spData->m_nOptionValue);
        Unk_1401b4ec0 lock(m_lock, 1);
        m_map.SetAt(nId, spData);
    }
    SetInit(true);
    return 1;
}

// @0x140615b70
int CItemRemakeScrollTable::Reload()
{
    int nRet = 0;
    Unk_1401b4ec0 lock(m_lock, 1);
    m_map.RemoveAll();
    nRet = Load();
    return nRet;
}

// @0x140615bf0
CItemRemakeScrollDataPtr CItemRemakeScrollTable::GetData(int nId)
{
    CheckInit();
    CItemRemakeScrollDataPtr spData(0);
    Unk_1401b4ec0 lock(m_lock, 1);
    m_map.Lookup(nId, spData);
    return spData;
}

// @0x14061b280
void CItemRemakeScrollTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemRemakeScrollTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14061c620
void CItemRemakeScrollTable::SetInit(bool b)
{
    s_bInit = b;
}

// ---- the option remake helpers ----

// The options of nGroup whose value is the top of their range.
// @0x140615ca0
void FUN_140615ca0(MS2Ptr<CItem> item, int nGroup, ATL::CAtlArray<MS2Ptr<CItemRemakeOptionUtil::TStatInfo> >& out)
{
    MS2Ptr<CItemOption> spOption(item->FUN_1405278a0()->m_spOption);
    if (spOption.get() != 0)
    {
        Unk_EnchantMap& stats = spOption->GetStatMap(nGroup);
        if (!stats.IsEmpty())
        {
            for (POSITION pos = stats.GetStartPosition(); pos != 0; stats.GetNext(pos))
            {
                int nStat = stats.GetKeyAt(pos);
                Unk_EnchantPtr<BaseOption> spBase(stats.GetValueAt(pos));
                if (spBase == 0)
                    continue;
                std::pair<int, int> range =
                    ((class CItemOptionTable*)FUN_140166430())->GetRandomOptionRange(item->FUN_1405276c0(), item->GetRarity(), nStat);
                if (range.second == spBase->GetValue())
                {
                    MS2Ptr<CItemRemakeOptionUtil::TStatInfo> spInfo(new CItemRemakeOptionUtil::TStatInfo);
                    spInfo->m_nKind = 0;
                    spInfo->m_nValue = spBase->GetValue();
                    spInfo->m_nId = nStat;
                    out.Add(spInfo);
                }
            }
        }
        Unk_SocketSpecialMap& specials = spOption->GetSpecialMap(nGroup);
        if (!specials.IsEmpty())
        {
            for (POSITION pos = specials.GetStartPosition(); pos != 0; specials.GetNext(pos))
            {
                int nSpecial = specials.GetKeyAt(pos);
                Unk_EnchantPtr<BaseOption> spBase(specials.GetValueAt(pos));
                if (spBase == 0)
                    continue;
                std::pair<int, int> range =
                    ((class CItemOptionTable*)FUN_140166430())->GetRandomSpecialOptionRange(item->FUN_1405276c0(), item->GetRarity(), nSpecial);
                if (range.second == spBase->GetValue())
                {
                    MS2Ptr<CItemRemakeOptionUtil::TStatInfo> spInfo(new CItemRemakeOptionUtil::TStatInfo);
                    spInfo->m_nKind = 1;
                    spInfo->m_nValue = spBase->GetValue();
                    spInfo->m_nId = nSpecial;
                    out.Add(spInfo);
                }
            }
        }
    }
}

// Whether a remake scroll can be used on an item: 0 = yes, else the error (1 no item / not a pet, 2 no data, 3 the
// options do not allow it, 4 slot, 5 rank, 6 level, 7 remake disabled, 8 item, 10 no scroll, 11 no option value).
// @0x140616170
int FUN_140616170(MS2Ptr<CItem> item, MS2Ptr<CItemRemakeScrollData> spScroll)
{
    if (item == 0)
        return 1;
    if (spScroll == 0)
        return 10;
    MS2Ptr<CItemData> spData(item->FUN_140527840());
    if (spData == 0)
        return 2;
    if (spData->property.remakeDisable)
        return 7;
    MS2Ptr<CItemOption> spOption(item->FUN_1405278a0()->m_spOption);
    if (spOption == 0)
        return 3;
    if (!spScroll->m_arrItemTypes.IsEmpty())
    {
        if (Unk_ArrayFind<unsigned>(spScroll->m_arrItemTypes, spData->GetItemId()) == -1)
            return 8;
    }
    else if (spScroll->m_nPetKind != 0)
    {
        if (!spData->IsPetItem())
            return 1;
    }
    else
    {
        if (Unk_ArrayFind<unsigned>(spScroll->m_arrSlots, spData->GetEquipSubtype()) == -1)
            return 4;
    }
    if (Unk_ArrayFind<unsigned>(spScroll->m_arrRanks, item->GetRarity()) == -1)
        return 5;
    int nLevel = spData->limit.levelLimit;
    if (nLevel < spScroll->m_nLevelMin || nLevel > spScroll->m_nLevelMax)
        return 6;
    if (spScroll->m_nOptionValue == 0)
        return 0xb;
    int bExclusive = spData->FUN_14053d600();
    {
        MS2Ptr<ItemOptionRandom> spRandom = ((class CItemOptionTable*)FUN_140166430())->GetRandom(spData->FUN_14053eff0(item->GetRarity()));
        Unk_SocketSpecialMap& specials = spOption->GetSpecialMap(2);
        Unk_EnchantMap& stats = spOption->GetStatMap(2);
        if (specials.IsEmpty() && stats.IsEmpty())
            return 3;
        unsigned nExclusive = 0;
        for (POSITION pos = stats.GetStartPosition(); pos != 0; stats.GetNext(pos))
        {
            int nStat = stats.GetKeyAt(pos);
            if (!spRandom->HasStat(nStat))
                return 3;
            if (bExclusive)
            {
                CString strName(GetStatName(nStat));
                bool bFound = ((class CItemOptionTable*)FUN_140166430())->FindOptionNameList(strName).get() != 0;
                if (bFound)
                    nExclusive++;
            }
        }
        for (POSITION pos = specials.GetStartPosition(); pos != 0; specials.GetNext(pos))
        {
            int nSpecial = specials.GetKeyAt(pos);
            if (!spRandom->HasSpecialStat(nSpecial))
                return 3;
            if (bExclusive)
            {
                CString strName(FUN_14081d380(nSpecial));
                bool bFound = ((class CItemOptionTable*)FUN_140166430())->FindOptionNameList(strName).get() != 0;
                if (bFound)
                    nExclusive++;
            }
        }
        if (nExclusive > 1)
            return 3;
    }
    return 0;
}

// The remake sale of an item: 0 none, 1 the game rule's, 2 a bigger one (nRate).
// @0x140616b60
int FUN_140616b60(MS2Ptr<CItemData> data, unsigned* pDiscount, unsigned nRate)
{
    unsigned nSale = ((class CGameRule*)FUN_1401c0d90())->FUN_140478cd0(data);
    unsigned nDiscount = nSale > nRate ? nSale : nRate;
    *pDiscount = nDiscount;
    int nRet = 0;
    if (nDiscount > 0)
    {
        if (nDiscount == nSale)
            nRet = 1;
        else
            nRet = 2;
    }
    return nRet;
}

// The pet remake sale (same as FUN_140616b60).
// @0x140616c50
int FUN_140616c50(MS2Ptr<CItemData> data, unsigned* pDiscount, unsigned nRate)
{
    unsigned nSale = ((class CGameRule*)FUN_1401c0d90())->FUN_140478cd0(data);
    unsigned nDiscount = nSale > nRate ? nSale : nRate;
    *pDiscount = nDiscount;
    int nRet = 0;
    if (nDiscount > 0)
    {
        if (nDiscount == nSale)
            nRet = 1;
        else
            nRet = 2;
    }
    return nRet;
}

// The discounted ingredient count (the discount is capped by IngredientFeeReduceLimit; at least 1).
// @0x140616d40
int FUN_140616d40(int nCount, unsigned nDiscount)
{
    nDiscount = nDiscount < (unsigned)FUN_1406198a0(10000, FUN_1401d3200()->IngredientFeeReduceLimit)
        ? nDiscount : FUN_1406198a0(10000, FUN_1401d3200()->IngredientFeeReduceLimit);
    unsigned nRet = FUN_140482050(nCount, nDiscount);
    return nRet < 1 ? 1 : nRet;
}

// The lock item id of an item (0 = no lock possible).
// @0x140616dd0
int FUN_140616dd0(MS2Ptr<CItem> item)
{
    int nId = 0;
    if (item == 0 || item->FUN_140527840() == 0)
        return nId;
    MS2Ptr<CItemData> spData(item->FUN_140527840());
    if (spData->FUN_14053d600())
        nId = 0x66;
    else if (spData->FUN_14053d2f0())
        nId = 0x65;
    else if (spData->FUN_14053d5c0())
        nId = 0x67;
    else if (spData->IsPetItem())
        nId = 0x68;
    return nId;
}

// The lock item's level.
// @0x140616f10
unsigned FUN_140616f10(MS2Ptr<CItem> item)
{
    if (item == 0 || !TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xa5))
        return 0;
    if (item->IsPetItem() != 0)
        return 0;
    return item->GetRarity();
}

// Whether the options of an item may be locked (per item kind feature).
// @0x140616fd0
bool FUN_140616fd0(MS2Ptr<CItem> item)
{
    if (item == 0 || item->FUN_140527840() == 0)
        return false;
    MS2Ptr<CItemData> spData(item->FUN_140527840());
    if (spData->FUN_14053d600())
        return TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x8a);
    else if (spData->FUN_14053d2f0())
        return TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x89);
    else if (spData->FUN_14053d5c0())
        return TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x8b);
    else if (spData->IsPetItem())
        return TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x9b);
    return false;
}

// ---- CCItemRemakeOptionPacket ----

namespace CCItemRemakeOptionPacket {

// @0x1406171b0
RemakeOptionBase::RemakeOptionBase()
    : m_18(0), m_20(0)
{
}

// @0x140617200
RemakeOptionBase::~RemakeOptionBase()
{
}

// @0x140617230
void RemakeOptionBase::vfunc_1(COutputStream& out)
{
    out.WriteInt64(m_18);
    out.WriteInt64(m_20);
}

// @0x140617280
void RemakeOptionBase::vfunc_2(CInPacket& in)
{
    m_18 = in.ReadInt64();
    m_20 = in.ReadInt64();
}

// @0x1406172f0
// MS2-FUNCTIONAL: the exe's Unk_RemakeOptionList50 ctor is noexcept (no EH state); the shared struct here declares it without throw()
RemakeOption::RemakeOption()
{
}

// @0x140617340
RemakeOption::~RemakeOption()
{
}

// @0x140617380
void RemakeOption::vfunc_1(COutputStream& out)
{
    RemakeOptionBase::vfunc_1(out);
    int nCount = (int)reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).size();
    out.WriteUInt8((unsigned char)nCount);
    if (0 < nCount)
    {
        for (int i = 0; i < nCount; i++)
        {
            std::pair<int, int>& option = reinterpret_cast<Unk_RemakeOptionPairs&>(m_options)[i];
            out.WriteUInt8((unsigned char)option.first);
            out.WriteInt16((short)option.second);
        }
    }
}

// @0x140617450
void RemakeOption::vfunc_2(CInPacket& in)
{
    RemakeOptionBase::vfunc_2(in);
    int nCount = in.ReadUInt8();
    if (nCount > 0)
    {
        reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).reserve(nCount);
        for (int i = 0; i < nCount; i++)
        {
            unsigned nIndex = in.ReadUInt8();
            int nValue = (unsigned short)in.ReadInt16();
            reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).push_back(std::pair<int, int>(nIndex, nValue));
        }
    }
}

// @0x140617560
RemakeOptionDebug::RemakeOptionDebug()
    : m_kind(0), m_value(0)
{
}

// @0x1406175b0
void RemakeOptionDebug::vfunc_1(COutputStream& out)
{
    RemakeOption::vfunc_1(out);
    out.WriteUInt8((unsigned char)m_kind);
    out.WriteInt32(m_value);
}

// @0x140617610
void RemakeOptionDebug::vfunc_2(CInPacket& in)
{
    RemakeOption::vfunc_2(in);
    m_kind = in.ReadUInt8();
    m_value = in.ReadInt32();
}

// @0x140617690
ApplyOptionBase::ApplyOptionBase()
    : m_uid(0)
{
}

// @0x1406176c0
ApplyOptionBase::~ApplyOptionBase()
{
}

// @0x1406176e0
void ApplyOptionBase::vfunc_1(COutputStream& out)
{
    out.WriteInt64(m_uid);
}

// @0x140617720
void ApplyOptionBase::vfunc_2(CInPacket& in)
{
    m_uid = in.ReadInt64();
}

// @0x140617770
ForceFillIngredient::ForceFillIngredient()
    : m_uid(0), m_count(0)
{
}

// @0x1406177b0
ForceFillIngredient::~ForceFillIngredient()
{
}

// @0x1406177d0
void ForceFillIngredient::vfunc_1(COutputStream& out)
{
    out.WriteInt64(m_uid);
    out.WriteInt32(m_count);
}

// @0x140617820
void ForceFillIngredient::vfunc_2(CInPacket& in)
{
    m_uid = in.ReadInt64();
    m_count = in.ReadInt32();
}

// @0x140617890
ApplyOptionClient::ApplyOptionClient()
    : m_item(0)
{
}

// @0x1406178e0
ApplyOptionClient::~ApplyOptionClient()
{
    m_item = 0;
}

// @0x140617940
void ApplyOptionClient::vfunc_1(COutputStream& out)
{
    ApplyOptionBase::vfunc_1(out);
}

// @0x140617970
void ApplyOptionClient::vfunc_2(CInPacket& in)
{
    ApplyOptionBase::vfunc_2(in);
    if (m_item.get() != 0)
        m_item->FUN_140524eb0(in);
}

}

// ---- CCItemRemakeOptionScrollPacket ----

namespace CCItemRemakeOptionScrollPacket {

// @0x1406179e0
RemakeOption::RemakeOption()
    : m_scrollUid(0), m_itemUid(0), m_ingredientUid(0), m_bLocked(false)
{
}

// @0x140617a50
RemakeOption::~RemakeOption()
{
}

// @0x140617a90
void RemakeOption::vfunc_1(COutputStream& out)
{
    out.WriteInt64(m_scrollUid);
    out.WriteInt64(m_itemUid);
    out.WriteInt64(m_ingredientUid);
    out.WriteBool(m_bLocked);
    int nCount = (int)reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).size();
    out.WriteUInt8((unsigned char)nCount);
    if (0 < nCount)
    {
        for (int i = 0; i < nCount; i++)
        {
            std::pair<int, int>& option = reinterpret_cast<Unk_RemakeOptionPairs&>(m_options)[i];
            out.WriteUInt8((unsigned char)option.first);
            out.WriteInt16((short)option.second);
        }
    }
}

// @0x140617bb0
void RemakeOption::vfunc_2(CInPacket& in)
{
    m_scrollUid = in.ReadInt64();
    m_itemUid = in.ReadInt64();
    m_ingredientUid = in.ReadInt64();
    m_bLocked = in.ReadBool();
    int nCount = in.ReadUInt8();
    if (nCount > 0)
    {
        reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).reserve(nCount);
        for (int i = 0; i < nCount; i++)
        {
            unsigned nIndex = in.ReadUInt8();
            int nValue = (unsigned short)in.ReadInt16();
            reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).push_back(std::pair<int, int>(nIndex, nValue));
        }
    }
}

}

// ---- Unk_RemakeStat and the option texts ----

// @0x140617da0
Unk_RemakeStat::Unk_RemakeStat()
    : m_nMode(5), m_bFinal(false)
{
}

// @0x140617de0
Unk_RemakeStat::Unk_RemakeStat(unsigned nMode, MS2Ptr<CItem> item, bool bFinal)
    : m_nMode(nMode), m_item(item), m_bFinal(bFinal)
{
}

// The option text under a string table key.
// @0x140617e50
CStringW FUN_140617e50(const CStringW& strKey, Unk_RemakeStat& stat, unsigned* pCount)
{
    CStringW strNames = FUN_140617ef0(stat, pCount);
    return FUN_14028dfa0<CStringW>(strKey, strNames);
}

// The option text of an item: one row per option (best values marked; with bFinal the stat range too).
// @0x140617ef0
CStringW FUN_140617ef0(Unk_RemakeStat& stat, unsigned* pCount)
{
    if (stat.m_item == 0)
        return CStringW(L"");
    MS2Ptr<CItem> item(stat.m_item);
    MS2Ptr<CItemOption> spOption(item->FUN_1405278a0()->m_spOption);
    if (spOption == 0)
        return CStringW(L"");
    int nGroup = stat.m_nMode;
    Unk_EnchantMap& stats = spOption->GetStatMap(nGroup);
    Unk_SocketSpecialMap& specials = spOption->GetSpecialMap(nGroup);
    const CStringW& strBest = GetStringCommon(0x48d);
    const CStringW& strRowBest = GetStringCommonByKey(L"s_tooltip_itemoption_stat_row_best");
    const CStringW& strRow = GetStringCommonByKey(L"s_tooltip_itemoption_stat_row");
    bool bFinal = stat.m_bFinal;
    const CStringW& strRange = bFinal ? GetStringCommonByKey(L"s_itemremake_option_with_range") : CStringW(L"");
    const CStringW& strRangeR = bFinal ? GetStringCommonByKey(L"s_itemremake_option_with_range_r") : CStringW(L"");
    bool bBest = false;
    Unk_OptionTextMap names(10);
    if (item->IsPetItem() != 0 && nGroup == 2)
        spOption->FUN_1405cb900(nGroup, names);
    else
    {
        int nRow = 0;
        for (POSITION pos = stats.GetStartPosition(); pos != 0; stats.GetNext(pos))
        {
            int nStat = stats.GetKeyAt(pos);
            names.SetAt(nRow++, GetStatName(nStat));
        }
        for (POSITION pos = specials.GetStartPosition(); pos != 0; specials.GetNext(pos))
        {
            int nSpecial = specials.GetKeyAt(pos);
            names.SetAt(nRow++, FUN_14081d380(nSpecial));
        }
    }
    int nNames = names.GetCount();
    (void)nNames;
    unsigned nCount = 0;
    CStringW strText;
    for (POSITION pos = names.GetHeadPosition(); pos != 0; names.GetNext(pos))
    {
        int nStat = FindStatByName(names.GetValueAt(pos));
        if (nStat != -1)
        {
            Unk_EnchantMap::CPair* pPair = stats.Lookup(nStat);
            if (pPair == 0)
                continue;
            Unk_EnchantPtr<BaseOption> spBase(pPair->m_value);
            if (!spBase)
                continue;
            CStringW strName = FUN_140631600(nStat, spBase.get());
            std::pair<int, int> range =
                ((class CItemOptionTable*)FUN_140166430())->GetRandomOptionRange(item->FUN_1405276c0(), item->GetRarity(), nStat);
            bBest = range.second == spBase->GetValue();
            if (bBest)
                strName = StringFormat<CStringW>(strBest, strName);
            CStringW strValue;
            if (!strRange.IsEmpty())
            {
                if (IsStatKindTwo(nStat))
                {
                    float fMin = (float)range.first / 10.0;
                    float fMax = (float)range.second / 10.0;
                    strValue = StringFormat(strRangeR, strName, fMin, fMax);
                }
                else
                    strValue = StringFormat(strRange, strName, range.first, range.second);
            }
            else
                strValue = strName;
            if (bBest == true || ((class CItemOptionTable*)FUN_140166430())->IsHighRollValue(item, nStat, nGroup, spBase->GetValue()))
                strText.Append(StringFormat<CStringW>(strRowBest, strValue));
            else
                strText.Append(StringFormat<CStringW>(strRow, strValue));
            nCount++;
            continue;
        }
        Unk_SocketSpecialStat nSpecial = (Unk_SocketSpecialStat)FUN_14081d260(names.GetValueAt(pos));
        if (nSpecial != 0)
        {
            Unk_SocketSpecialMap::CPair* pPair = specials.Lookup(nSpecial);
            if (pPair == 0)
                continue;
            Unk_EnchantPtr<BaseOption> spBase(pPair->m_value);
            if (!spBase)
                continue;
            CStringW strName = FUN_140631830(nSpecial, spBase->GetValue(), item->FUN_140527840());
            std::pair<int, int> range =
                ((class CItemOptionTable*)FUN_140166430())->GetRandomSpecialOptionRange(item->FUN_1405276c0(), item->GetRarity(), nSpecial);
            bBest = range.second == spBase->GetValue();
            if (bBest)
                strName = StringFormat<CStringW>(strBest, strName);
            CStringW strValue;
            if (!strRange.IsEmpty())
            {
                if (FUN_14081dcd0(nSpecial))
                {
                    float fMin = (float)range.first / 10.0;
                    float fMax = (float)range.second / 10.0;
                    strValue = StringFormat(strRangeR, strName, fMin, fMax);
                }
                else
                    strValue = StringFormat(strRange, strName, range.first, range.second);
            }
            else
                strValue = strName;
            if (bBest == true || ((class CItemOptionTable*)FUN_140166430())->IsHighRollSpecialValue(item, nSpecial, nGroup, spBase->GetValue()))
                strText.Append(StringFormat<CStringW>(strRowBest, strValue));
            else
                strText.Append(StringFormat<CStringW>(strRow, strValue));
            nCount++;
            continue;
        }
    }
    if (pCount != 0)
        *pCount = nCount;
    return strText;
}

// The text of the locked options (the rows of the option text at the given indices).
// @0x140619070
CStringW FUN_140619070(Unk_RemakeStat& stat, const ATL::CAtlArray<int>& aLocked)
{
    unsigned nCount = 0;
    CStringW strOptions = FUN_140617ef0(stat, &nCount);
    ATL::CAtlArray<CStringW> rows;
    FUN_14025a680(strOptions, rows, L"\n");
    CStringW strText;
    for (size_t i = 0; i < aLocked.GetCount(); i++)
    {
        int nIndex = aLocked[i];
        strText += rows[nIndex] + L"\n";
    }
    return strText;
}

// The number of options of an item.
// @0x1406191e0
unsigned FUN_1406191e0(unsigned nMode, MS2Ptr<CItem> item)
{
    unsigned nCount = 0;
    Unk_RemakeStat stat(nMode, item, true);
    FUN_140617ef0(stat, &nCount);
    return nCount;
}

// The nOption-th option of the stat as a lock record: nIndex 0 = stat, 1 = special; nValue its id.
// @0x140619290
bool Unk_RemakeStat::FUN_140619290(int nOption, int& nIndex, int& nValue)
{
    if (m_item == 0)
        return false;
    MS2Ptr<CItem> item(m_item);
    MS2Ptr<CItemOption> spOption(item->FUN_1405278a0()->m_spOption);
    if (spOption == 0)
        return false;
    if (nOption < 0)
        return false;
    int nGroup = m_nMode;
    Unk_EnchantMap& stats = spOption->GetStatMap(nGroup);
    Unk_SocketSpecialMap& specials = spOption->GetSpecialMap(nGroup);
    Unk_OptionTextMap names(10);
    if (item->IsPetItem() != 0 && nGroup == 2)
        spOption->FUN_1405cb900(nGroup, names);
    else
    {
        int nRow = 0;
        for (POSITION pos = stats.GetStartPosition(); pos != 0; stats.GetNext(pos))
        {
            int nStat = stats.GetKeyAt(pos);
            names.SetAt(nRow++, GetStatName(nStat));
        }
        for (POSITION pos = specials.GetStartPosition(); pos != 0; specials.GetNext(pos))
        {
            int nSpecial = specials.GetKeyAt(pos);
            names.SetAt(nRow++, FUN_14081d380(nSpecial));
        }
    }
    if (names.IsEmpty())
        return false;
    CString strName;
    int i = 0;
    for (POSITION pos = names.GetHeadPosition(); pos != 0; names.GetNext(pos))
    {
        if (i == nOption)
        {
            strName = names.GetValueAt(pos);
            break;
        }
        i++;
    }
    if (strName.IsEmpty())
        return false;
    int nStat = FindStatByName(strName);
    if (nStat != -1)
    {
        nIndex = 0;
        nValue = nStat;
        return true;
    }
    int nSpecial = FUN_14081d260(strName);
    if (nSpecial != 0)
    {
        nIndex = 1;
        nValue = nSpecial;
        return true;
    }
    return false;
}

// The lock item's name (coloured by its rank; nLevel 0: the item's default rank).
// @0x140619760
CStringW FUN_140619760(int nItemId, unsigned nLevel)
{
    int nRank;
    if (nItemId == 0)
        return CStringW(L"");
    unsigned nLockId = TSingleton<CItemDataTable>::GetInstance()->GetTagItemId((ItemTagKey)nItemId);
    nRank = nLevel;
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xa5))
        nRank = nLevel;
    if (nRank == 0)
        nRank = FUN_14053feb0(nLockId);
    return FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nLockId), nRank);
}

// @0x1406198a0
int FUN_1406198a0(int nValue, float fRate)
{
    return (int)(nValue * (double)fRate + 1e-06);
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9b280-0x142c9b2b0 .text$yd
