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

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

bool FUN_14028f650(Unk_140165cf0* pElem);                   // the node is a usable element
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_CommonLog { public: void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg); };
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& rValue);   // index or -1

// CItem's records: the item data (CItem::FUN_140527840) and the enchant / option status (CItem::FUN_1405278a0).
class Unk_ItemEquipData : public CItemData {};
class Unk_ItemEnchantData : public CItemStatus {};

CItemOptionTable* FUN_140166430();                          // TSingleton<CItemOptionTable>::GetInstance
CFeatureManager* FUN_140166410();                           // TSingleton<CFeatureManager>::GetInstance
CGameRule* FUN_1401c0d90();                                 // TSingleton<CGameRule>::GetInstance
CStringTable* GetStringTable();                              // TSingleton<CStringTable>::GetInstance
Unk_IngTable* FUN_140281980();
unsigned FUN_1405575b0(Unk_IngTable*, int);                 // the lock item of an item
const CString& FUN_14082efb0(int nStat);                    // the xml name of a stat
const CString& FUN_14081d380(int nSpecial);                 // the xml name of a special stat
int FUN_14082ee80(const CStringA& strName);                 // stat name -> id (-1 when none)
int FUN_14081d260(const CStringA& strName);                 // special option name -> id (0 when none)
bool FUN_14082f250(int nStat);                              // the stat value is a percent
bool FUN_14081dcd0(int nSaType);                            // the SA value is a percent
CStringW FUN_140631600(int nStat, BaseOption* pBase);       // the text of a stat option
CStringW FUN_140631830(int nStat, int nValue, Unk_ItemEquipData* pData);    // the text of a special stat option
CStringW GetStringCommon(int nStringId);                      // a common string by id
CStringW GetStringCommonByKey(const CStringW& str);                // a string table text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a1);    // a formatted string table text
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // formats one text argument
CStringW FUN_14183e9c0(CStringW strName, int nRank);        // the item name coloured by rank
int FUN_14053feb0(int nItemId);                             // the default rank of an item
unsigned FUN_140482050(unsigned nAmount, unsigned nScale);  // scaled amount
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* pszDelim);
int FUN_1406198a0(int nValue, float fRate);

// The option list of the remake records (Unk_RemakeOptionList50) is a vector of (option index, value) pairs.
typedef std::vector<std::pair<int, int> > Unk_RemakeOptionPairs;
#ifdef __clang__
// clang emits an unavailable MFC CopyChars import for operator+ (hook DLL); call the exe's copy of
// operator+(const CStringW&, const wchar_t*) (the COMDAT this unit emits at 0x14061ad70).
CStringW FUN_14061ad70(const CStringW& str, const wchar_t* psz);
#endif

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
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 1;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("remakeScroll"); pNode != 0;
         pNode = pNode->FUN_140168650("remakeScroll"))
    {
        if (!FUN_14028f650(pNode))
            continue;
        int nId = 0;
        FUN_1408731e0(pNode, "id", nId);
        if (nId == 0)
            continue;
        CItemRemakeScrollDataPtr spData(new CItemRemakeScrollData);
        if (spData == 0)
            continue;
        FUN_1408731a0(pNode, "minLv", spData->m_nLevelMin);
        FUN_1408731a0(pNode, "maxLv", spData->m_nLevelMax);
        XmlTokenList(pNode, "rank", spData->m_arrRanks);
        XmlTokenList(pNode, "slot", spData->m_arrSlots);
        FUN_1408731e0(pNode, "onlyPet", spData->m_nPetKind);
        XmlTokenList(pNode, "item", spData->m_arrItemTypes);
        XmlValue(pNode, "representOpValue", spData->m_nLockOption);
        XmlValue(pNode, "addOpKind", spData->m_nOptionKind);
        XmlValue(pNode, "addOpValue", spData->m_nOptionValue);
        Unk_CriticalSectionLock lock(m_lock, 1);
        m_map.SetAt(nId, spData);
    }
    SetInit(true);
    return 1;
}

// @0x140615b70
int CItemRemakeScrollTable::Reload()
{
    int nRet = 0;
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_map.RemoveAll();
    nRet = Load();
    return nRet;
}

// @0x140615bf0
CItemRemakeScrollDataPtr CItemRemakeScrollTable::GetData(int nId)
{
    CheckInit();
    CItemRemakeScrollDataPtr spData(0);
    Unk_CriticalSectionLock lock(m_lock, 1);
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
// MS2-FUNCTIONAL: stack slot order of the iterator/temporaries differs
void FUN_140615ca0(MS2Ptr<CItem> item, int nGroup, ATL::CAtlArray<MS2Ptr<CItemRemakeOptionUtil::TStatInfo> >& out)
{
    MS2Ptr<CItemOption> spOption(item->FUN_1405278a0()->m_spOption);
    if (spOption.get() != 0)
    {
        Unk_EnchantMap& stats = spOption->FUN_1405cb8a0(nGroup);
        if (!stats.IsEmpty())
        {
            POSITION pos = stats.GetStartPosition();
            while (pos != 0)
            {
                int nStat = stats.GetKeyAt(pos);
                Unk_EnchantPtr<BaseOption> spBase(stats.GetValueAt(pos));
                if (!(spBase == 0))
                {
                    std::pair<int, int> range =
                        FUN_140166430()->FUN_1405f64e0(item->FUN_1405276c0(), item->FUN_140526bd0(), nStat);
                    if (range.second == spBase->GetValue())
                    {
                        MS2Ptr<CItemRemakeOptionUtil::TStatInfo> spInfo(new CItemRemakeOptionUtil::TStatInfo);
                        spInfo->m_nKind = 0;
                        spInfo->m_nValue = spBase->GetValue();
                        spInfo->m_nId = nStat;
                        out.Add(spInfo);
                    }
                }
                stats.GetNext(pos);
            }
        }
        Unk_SocketSpecialMap& specials = spOption->FUN_1405cb8d0(nGroup);
        if (!specials.IsEmpty())
        {
            POSITION pos = specials.GetStartPosition();
            while (pos != 0)
            {
                int nSpecial = specials.GetKeyAt(pos);
                Unk_EnchantPtr<BaseOption> spBase(specials.GetValueAt(pos));
                if (!(spBase == 0))
                {
                    std::pair<int, int> range =
                        FUN_140166430()->FUN_1405f6650(item->FUN_1405276c0(), item->FUN_140526bd0(), nSpecial);
                    if (range.second == spBase->GetValue())
                    {
                        MS2Ptr<CItemRemakeOptionUtil::TStatInfo> spInfo(new CItemRemakeOptionUtil::TStatInfo);
                        spInfo->m_nKind = 1;
                        spInfo->m_nValue = spBase->GetValue();
                        spInfo->m_nId = nSpecial;
                        out.Add(spInfo);
                    }
                }
                specials.GetNext(pos);
            }
        }
    }
}

// Whether a remake scroll can be used on an item: 0 = yes, else the error (1 no item / not a pet, 2 no data, 3 the
// options do not allow it, 4 slot, 5 rank, 6 level, 7 remake disabled, 8 item, 10 no scroll, 11 no option value).
// @0x140616170
// MS2-FUNCTIONAL: local slot layout and the error-code return temporaries differ
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
        if (Unk_ArrayFind<unsigned>(spScroll->m_arrItemTypes, spData->FUN_14053c510()) == -1)
            return 8;
    }
    else if (spScroll->m_nPetKind == 0)
    {
        if (Unk_ArrayFind<unsigned>(spScroll->m_arrSlots, spData->FUN_14053c620()) == -1)
            return 4;
    }
    else if (!spData->FUN_14053cc40())
        return 1;
    if (Unk_ArrayFind<unsigned>(spScroll->m_arrRanks, item->FUN_140526bd0()) == -1)
        return 5;
    int nLevel = spData->limit.levelLimit;
    if (nLevel < spScroll->m_nLevelMin || spScroll->m_nLevelMax < nLevel)
        return 6;
    if (spScroll->m_nOptionValue == 0)
        return 0xb;
    bool bExclusive = spData->FUN_14053d600();
    MS2Ptr<ItemOptionRandom> spRandom = FUN_140166430()->FUN_1405f6010(spData->FUN_14053eff0(item->FUN_140526bd0()));
    Unk_SocketSpecialMap& specials = spOption->FUN_1405cb8d0(2);
    Unk_EnchantMap& stats = spOption->FUN_1405cb8a0(2);
    if (specials.IsEmpty() && stats.IsEmpty())
        return 3;
    unsigned nExclusive = 0;
    POSITION pos = stats.GetStartPosition();
    while (pos != 0)
    {
        int nStat = stats.GetKeyAt(pos);
        if (!spRandom->FUN_1405d74d0(nStat))
            return 3;
        if (bExclusive)
        {
            CString strName(FUN_14082efb0(nStat));
            bool bFound = FUN_140166430()->FUN_1405f6e40(strName).get() != 0;
            if (bFound)
                nExclusive++;
        }
        stats.GetNext(pos);
    }
    pos = specials.GetStartPosition();
    while (pos != 0)
    {
        int nSpecial = specials.GetKeyAt(pos);
        if (!spRandom->FUN_1405d7550(nSpecial))
            return 3;
        if (bExclusive)
        {
            CString strName(FUN_14081d380(nSpecial));
            bool bFound = FUN_140166430()->FUN_1405f6e40(strName).get() != 0;
            if (bFound)
                nExclusive++;
        }
        specials.GetNext(pos);
    }
    if (nExclusive < 2)
        return 0;
    return 3;
}

// The remake sale of an item: 0 none, 1 the game rule's, 2 a bigger one (nRate).
// @0x140616b60
int FUN_140616b60(MS2Ptr<CItemData> data, unsigned* pDiscount, unsigned nRate)
{
    unsigned nSale = FUN_1401c0d90()->FUN_140478cd0(data);
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
    unsigned nSale = FUN_1401c0d90()->FUN_140478cd0(data);
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
    else if (spData->FUN_14053cc40())
        nId = 0x68;
    return nId;
}

// The lock item's level.
// @0x140616f10
unsigned FUN_140616f10(MS2Ptr<CItem> item)
{
    if (item == 0 || !FUN_140166410()->FUN_14036d570(0xa5))
        return 0;
    if (item->FUN_140525640() != 0)
        return 0;
    return item->FUN_140526bd0();
}

// Whether the options of an item may be locked (per item kind feature).
// @0x140616fd0
bool FUN_140616fd0(MS2Ptr<CItem> item)
{
    if (item == 0 || item->FUN_140527840() == 0)
        return false;
    MS2Ptr<CItemData> spData(item->FUN_140527840());
    if (spData->FUN_14053d600())
        return FUN_140166410()->FUN_14036d570(0x8a);
    else if (spData->FUN_14053d2f0())
        return FUN_140166410()->FUN_14036d570(0x89);
    else if (spData->FUN_14053d5c0())
        return FUN_140166410()->FUN_14036d570(0x8b);
    else if (spData->FUN_14053cc40())
        return FUN_140166410()->FUN_14036d570(0x9b);
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
    out.vfunc_o10_4(m_18);
    out.vfunc_o10_4(m_20);
}

// @0x140617280
void RemakeOptionBase::vfunc_2(CInPacket& in)
{
    m_18 = in.vfunc_o8_4();
    m_20 = in.vfunc_o8_4();
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
    out.vfunc_o10_1((unsigned char)nCount);
    if (0 < nCount)
    {
        for (int i = 0; i < nCount; i++)
        {
            std::pair<int, int>& option = reinterpret_cast<Unk_RemakeOptionPairs&>(m_options)[i];
            out.vfunc_o10_1((unsigned char)option.first);
            out.vfunc_o10_2((short)option.second);
        }
    }
}

// @0x140617450
void RemakeOption::vfunc_2(CInPacket& in)
{
    RemakeOptionBase::vfunc_2(in);
    int nCount = in.vfunc_o8_1();
    if (nCount > 0)
    {
        reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).reserve(nCount);
        for (int i = 0; i < nCount; i++)
        {
            unsigned nIndex = in.vfunc_o8_1();
            int nValue = (unsigned short)in.vfunc_o8_2();
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
    out.vfunc_o10_1((unsigned char)m_kind);
    out.vfunc_o10_3(m_value);
}

// @0x140617610
void RemakeOptionDebug::vfunc_2(CInPacket& in)
{
    RemakeOption::vfunc_2(in);
    m_kind = in.vfunc_o8_1();
    m_value = in.vfunc_o8_3();
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
    out.vfunc_o10_4(m_uid);
}

// @0x140617720
void ApplyOptionBase::vfunc_2(CInPacket& in)
{
    m_uid = in.vfunc_o8_4();
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
    out.vfunc_o10_4(m_uid);
    out.vfunc_o10_3(m_count);
}

// @0x140617820
void ForceFillIngredient::vfunc_2(CInPacket& in)
{
    m_uid = in.vfunc_o8_4();
    m_count = in.vfunc_o8_3();
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
    out.vfunc_o10_4(m_scrollUid);
    out.vfunc_o10_4(m_itemUid);
    out.vfunc_o10_4(m_ingredientUid);
    out.vfunc_o10_0(m_bLocked);
    int nCount = (int)reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).size();
    out.vfunc_o10_1((unsigned char)nCount);
    if (0 < nCount)
    {
        for (int i = 0; i < nCount; i++)
        {
            std::pair<int, int>& option = reinterpret_cast<Unk_RemakeOptionPairs&>(m_options)[i];
            out.vfunc_o10_1((unsigned char)option.first);
            out.vfunc_o10_2((short)option.second);
        }
    }
}

// @0x140617bb0
void RemakeOption::vfunc_2(CInPacket& in)
{
    m_scrollUid = in.vfunc_o8_4();
    m_itemUid = in.vfunc_o8_4();
    m_ingredientUid = in.vfunc_o8_4();
    m_bLocked = in.vfunc_o8_0();
    int nCount = in.vfunc_o8_1();
    if (nCount > 0)
    {
        reinterpret_cast<Unk_RemakeOptionPairs&>(m_options).reserve(nCount);
        for (int i = 0; i < nCount; i++)
        {
            unsigned nIndex = in.vfunc_o8_1();
            int nValue = (unsigned short)in.vfunc_o8_2();
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
    return FUN_1405c2690(strKey, strNames);
}

// The option text of an item: one row per option (best values marked; with bFinal the stat range too).
// @0x140617ef0
// MS2-FUNCTIONAL: temporary/local slot layout of the long text builder differs
CStringW FUN_140617ef0(Unk_RemakeStat& stat, unsigned* pCount)
{
    if (stat.m_item == 0)
        return CStringW(L"");
    MS2Ptr<CItem> item(stat.m_item);
    MS2Ptr<CItemOption> spOption(item->FUN_1405278a0()->m_spOption);
    if (spOption == 0)
        return CStringW(L"");
    int nGroup = stat.m_nMode;
    Unk_EnchantMap& stats = spOption->FUN_1405cb8a0(nGroup);
    Unk_SocketSpecialMap& specials = spOption->FUN_1405cb8d0(nGroup);
    CStringW strBest = GetStringCommon(0x48d);
    CStringW strRowBest = GetStringCommonByKey(CStringW(L"s_tooltip_itemoption_stat_row_best"));
    CStringW strRow = GetStringCommonByKey(CStringW(L"s_tooltip_itemoption_stat_row"));
    CStringW strRange = stat.m_bFinal ? GetStringCommonByKey(CStringW(L"s_itemremake_option_with_range")) : CStringW(L"");
    CStringW strRangeR = stat.m_bFinal ? GetStringCommonByKey(CStringW(L"s_itemremake_option_with_range_r")) : CStringW(L"");
    Unk_OptionTextMap names(10);
    if (item->FUN_140525640() == 0 || nGroup != 2)
    {
        int nRow = 0;
        POSITION pos = stats.GetStartPosition();
        while (pos != 0)
        {
            int nStat = stats.GetKeyAt(pos);
            names.SetAt(nRow, FUN_14082efb0(nStat));
            nRow++;
            stats.GetNext(pos);
        }
        pos = specials.GetStartPosition();
        while (pos != 0)
        {
            int nSpecial = specials.GetKeyAt(pos);
            names.SetAt(nRow, FUN_14081d380(nSpecial));
            nRow++;
            specials.GetNext(pos);
        }
    }
    else
        spOption->FUN_1405cb900(nGroup, names);
    size_t nNames = names.GetCount();
    (void)nNames;
    unsigned nCount = 0;
    CStringW strText;
    POSITION pos = names.GetHeadPosition();
    while (pos != 0)
    {
        int nStat = FUN_14082ee80(names.GetValueAt(pos));
        if (nStat == -1)
        {
            int nSpecial = FUN_14081d260(names.GetValueAt(pos));
            Unk_SocketSpecialMap::CPair* pPair;
            if (nSpecial != 0 && (pPair = specials.Lookup((Unk_SocketSpecialStat)nSpecial)) != 0)
            {
                Unk_EnchantPtr<BaseOption> spBase(pPair->m_value);
                if (!(spBase == 0))
                {
                    CStringW strName = FUN_140631830(nSpecial, spBase->GetValue(), item->FUN_140527840());
                    std::pair<int, int> range =
                        FUN_140166430()->FUN_1405f6650(item->FUN_1405276c0(), item->FUN_140526bd0(), nSpecial);
                    bool bBest = range.second == spBase->GetValue();
                    if (bBest)
                        strName = FUN_1401e8510(strBest, strName);
                    CStringW strValue;
                    if (strRange.IsEmpty())
                        strValue = strName;
                    else if (!FUN_14081dcd0(nSpecial))
                        strValue = StringFormat(strRange, strName, range.first, range.second);
                    else
                    {
                        float fMin = (float)range.first / 10.0f;
                        float fMax = (float)range.second / 10.0f;
                        strValue = StringFormat(strRangeR, strName, fMin, fMax);
                    }
                    if (bBest || FUN_140166430()->FUN_1405f6a90(item, nSpecial, nGroup, spBase->GetValue()))
                        strText.Append(FUN_1401e8510(strRowBest, strValue));
                    else
                        strText.Append(FUN_1401e8510(strRow, strValue));
                    nCount++;
                }
            }
        }
        else
        {
            Unk_EnchantMap::CPair* pPair = stats.Lookup(nStat);
            if (pPair != 0)
            {
                Unk_EnchantPtr<BaseOption> spBase(pPair->m_value);
                if (!(spBase == 0))
                {
                    CStringW strName = FUN_140631600(nStat, spBase.get());
                    std::pair<int, int> range =
                        FUN_140166430()->FUN_1405f64e0(item->FUN_1405276c0(), item->FUN_140526bd0(), nStat);
                    bool bBest = range.second == spBase->GetValue();
                    if (bBest)
                        strName = FUN_1401e8510(strBest, strName);
                    CStringW strValue;
                    if (strRange.IsEmpty())
                        strValue = strName;
                    else if (!FUN_14082f250(nStat))
                        strValue = StringFormat(strRange, strName, range.first, range.second);
                    else
                    {
                        float fMin = (float)range.first / 10.0f;
                        float fMax = (float)range.second / 10.0f;
                        strValue = StringFormat(strRangeR, strName, fMin, fMax);
                    }
                    if (bBest || FUN_140166430()->FUN_1405f67e0(item, nStat, nGroup, spBase->GetValue()))
                        strText.Append(FUN_1401e8510(strRowBest, strValue));
                    else
                        strText.Append(FUN_1401e8510(strRow, strValue));
                    nCount++;
                }
            }
        }
        names.GetNext(pos);
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
#ifdef __clang__
        strText += FUN_14061ad70(rows[nIndex], L"\n");
#else
        strText += rows[nIndex] + L"\n";
#endif
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
// MS2-FUNCTIONAL: local slot layout (the name map and string temporaries) differs
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
    Unk_EnchantMap& stats = spOption->FUN_1405cb8a0(nGroup);
    Unk_SocketSpecialMap& specials = spOption->FUN_1405cb8d0(nGroup);
    Unk_OptionTextMap names(10);
    if (item->FUN_140525640() == 0 || nGroup != 2)
    {
        int nRow = 0;
        POSITION pos = stats.GetStartPosition();
        while (pos != 0)
        {
            int nStat = stats.GetKeyAt(pos);
            names.SetAt(nRow, FUN_14082efb0(nStat));
            nRow++;
            stats.GetNext(pos);
        }
        pos = specials.GetStartPosition();
        while (pos != 0)
        {
            int nSpecial = specials.GetKeyAt(pos);
            names.SetAt(nRow, FUN_14081d380(nSpecial));
            nRow++;
            specials.GetNext(pos);
        }
    }
    else
        spOption->FUN_1405cb900(nGroup, names);
    if (names.IsEmpty())
        return false;
    CString strName;
    int i = 0;
    POSITION pos = names.GetHeadPosition();
    while (pos != 0)
    {
        if (i == nOption)
        {
            strName = names.GetValueAt(pos);
            break;
        }
        i++;
        names.GetNext(pos);
    }
    if (strName.IsEmpty())
        return false;
    int nStat = FUN_14082ee80(strName);
    if (nStat == -1)
    {
        int nSpecial = FUN_14081d260(strName);
        if (nSpecial == 0)
            return false;
        nIndex = 1;
        nValue = nSpecial;
        return true;
    }
    nIndex = 0;
    nValue = nStat;
    return true;
}

// The lock item's name (coloured by its rank; nLevel 0: the item's default rank).
// @0x140619760
CStringW FUN_140619760(int nItemId, unsigned nLevel)
{
    int nRank;
    if (nItemId == 0)
        return CStringW(L"");
    unsigned nLockId = FUN_1405575b0(FUN_140281980(), nItemId);
    nRank = nLevel;
    if (FUN_140166410()->FUN_14036d570(0xa5))
        nRank = nLevel;
    if (nRank == 0)
        nRank = FUN_14053feb0(nLockId);
    return FUN_14183e9c0(GetStringTable()->FUN_141811980(1, nLockId), nRank);
}

// @0x1406198a0
int FUN_1406198a0(int nValue, float fRate)
{
    return (int)(nValue * (double)fRate + 1e-06);
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9b280-0x142c9b2b0 .text$yd
