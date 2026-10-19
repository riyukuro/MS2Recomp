// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemDefaultData: the default items of the character
// creation (Table/defaultItems.xml): per job code and gender the items per slot, the preselected ones and the base items;
// see itemdefaultdata.h. File name assumed (the exe has no assert path for it); method names are invented.
// MS2-UNIT: ?\itemdefaultdata.cpp
// MS2-RANGE: 0x1400b9b40-0x1400b9dd0 .text$di
// MS2-RANGE: 0x140583fa0-0x14058c160 .text$mn
// MS2-RANGE: 0x142c9af10-0x142c9afc0 .text$yd
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@UDefaultItemData@@@@V?$CElementTraits@V?$MS2Ptr@UDefaultItemData@@@@@ATL@@@ATL@@@@6B@ 0x142d5fd18
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@UDefaultItemData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UDefaultItemData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140588680
// MS2-PIN: ??$format_arg@_WW4Unk_ItemDefaultKind@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_ItemDefaultKind@@@Z 0x1405864d0
//
// The TU also owns ms_aMaps' initializer 0x1400b9b00 / atexit 0x142c9aee0 (in ?\itemdatatable.cpp's ranges, which defines
// the same object as g_itemDefaultSlotMaps): its array ctor closure 0x140587540 is in this range, so ms_aMaps is defined here.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemdefaultdata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#define MS2_TPTRVALUE_ASSIGN_VIA_TEMP
#include <stdlib.h>
#include <typeinfo>
#include "itemdefaultdata.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/placeholder/tcreatecharinfo.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
unsigned int FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned int nDefault);
int ReadSlotAttr(Unk_140165cf0* pElem, const char* pszName, int* pnOut);  // banktable.cpp: slot name attribute
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                             // the item data of an id

// The default items per job (job code 0 = every job).
#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's maps and flag (symbols-manual.tsv)
ATL::CAtlMap<Unk_ItemDefaultKind, int> CItemDefaultData::ms_aMaps[2];
ATL::CAtlMap<int, MS2Ptr<CItemDefaultData::TDefaultItems> > CItemDefaultData::ms_mapJobItems;
bool CItemDefaultData::s_bInit;
#endif

// The market sort-key names of three included headers (names invented).
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// The equipment slots of the table (0x142d5f5f0).
static const Unk_ItemDefaultKind s_aSlots[18] = {
    (Unk_ItemDefaultKind)1, (Unk_ItemDefaultKind)2, (Unk_ItemDefaultKind)3, (Unk_ItemDefaultKind)4,
    (Unk_ItemDefaultKind)5, (Unk_ItemDefaultKind)6, (Unk_ItemDefaultKind)7, (Unk_ItemDefaultKind)8,
    (Unk_ItemDefaultKind)9, (Unk_ItemDefaultKind)10, (Unk_ItemDefaultKind)11, (Unk_ItemDefaultKind)12,
    (Unk_ItemDefaultKind)13, (Unk_ItemDefaultKind)14, (Unk_ItemDefaultKind)15, (Unk_ItemDefaultKind)16,
    (Unk_ItemDefaultKind)17, (Unk_ItemDefaultKind)18,
};

// The unit's two-argument log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T, class U>
inline void Unk_ItemDefaultLog(CLogString* log, int level, int category, const wchar_t* format, const T& first,
                               const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// @0x140583fa0
void CItemDefaultData::Load()
{
    if (!ms_mapJobItems.IsEmpty())
        return;
    CString strPath;
    strPath = FUN_14071a5b0("Table", "defaultItems.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0) {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    MS2Ptr<TDefaultItems> spCommon(new TDefaultItems(0));
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key")) {
        if (!FUN_14028f710(pKey))
            continue;
        int nJobCode = 0;
        FUN_140873890(pKey, "jobCode", nJobCode);
        MS2Ptr<TDefaultItems> spItems(0);
        if (nJobCode == 0) {
            spItems = spCommon;
            ms_mapJobItems.SetAt(nJobCode, spItems);
        } else if (!ms_mapJobItems.Lookup(nJobCode, spItems)) {
            spItems.AssignRaw(new TDefaultItems(nJobCode));
            ms_mapJobItems.SetAt(nJobCode, spItems);
        }
        for (Unk_140165cf0* pSlot = pKey->FUN_140165cf0("slot"); pSlot != 0; pSlot = pSlot->FUN_140168650("slot")) {
            Unk_ItemDefaultKind eSlot = (Unk_ItemDefaultKind)0;
            ReadSlotAttr(pSlot, "name", (int*)&eSlot);
            for (Unk_140165cf0* pItem = pSlot->FUN_140165cf0("item"); pItem != 0; pItem = pItem->FUN_140168650("item")) {
                if (!FUN_14028f710(pItem))
                    continue;
                bool bVisible = false;
                FUN_1408736d0(pItem, "visible", bVisible);
                bool bBase = false;
                FUN_1408736d0(pItem, "base", bBase);
                int nSaleTag = 0;
                FUN_1408731e0(pItem, "saleTag", nSaleTag);
                bool bSelect = false;
                FUN_1408736d0(pItem, "select", bSelect);
                if (!bVisible && !bBase)
                    continue;
                int nItemId = FUN_140197390(pItem, "id", 0);
                MS2Ptr<CItemData> spItemData = FUN_14053f870(nItemId);
                if (!spItemData)
                    continue;
                if (!bBase) {
                    Unk_ItemDefaultKind eItemSlot = (Unk_ItemDefaultKind)spItemData->FUN_14053eba0()->FUN_14054b400();
                    if (eItemSlot != eSlot) {
                        Unk_ItemDefaultLog(FUN_140166440(), 1, 0x13, L"<{0}> \xc640 <{1}>\xac00 \xac19\xc9c0 \xc54a\xc2b5\xb2c8\xb2e4.", eItemSlot, eSlot);
                        continue;
                    }
                }
                int nGender = spItemData->limit.genderLimit;
                MS2Ptr<DefaultItemData> spDefault(new DefaultItemData(nItemId, nSaleTag));
                if (spDefault.get() != 0)
                    spDefault->m_bSelect = bSelect;
                if (bBase) {
                    if (nGender == 2) {
                        ms_aMaps[0].SetAt(eSlot, nItemId);
                        ms_aMaps[1].SetAt(eSlot, nItemId);
                    } else {
                        ms_aMaps[nGender].SetAt(eSlot, nItemId);
                    }
                    if (bVisible || spItemData->FUN_14053cf40())
                        spItems->Add(nGender, eSlot, spDefault);
                } else {
                    spItems->Add(nGender, eSlot, spDefault);
                }
            }
        }
    }
    SetInit(true);
}

// @0x140584790
int CItemDefaultData::IsDefaultItem(int nJobCode, int nGender, int nItemId)
{
    CheckInit();
    if (nJobCode == 0)
        return 0;
    if (FUN_140583f70(nGender) == 0)
        return 0;
    MS2Ptr<TDefaultItems> spCommon(0);
    if (ms_mapJobItems.Lookup(0, spCommon) && spCommon->HasItem(nGender, nItemId))
        return 1;
    MS2Ptr<TDefaultItems> spJob(0);
    if (ms_mapJobItems.Lookup(nJobCode, spJob) && spJob->HasItem(nGender, nItemId))
        return 1;
    return 0;
}
MS2_REPLACE(0x140584790, CItemDefaultData::IsDefaultItem, 313, 0x81410066);

// @0x1405848d0
int CItemDefaultData::GetItems(int nJobCode, int nGender, Unk_DefaultItemArray& aItems)
{
    CheckInit();
    if (nJobCode == 0)
        return 0;
    if (FUN_140583f70(nGender) == 0)
        return 0;
    MS2Ptr<TDefaultItems> spCommon;
    if (ms_mapJobItems.Lookup(0, spCommon))
        spCommon->GetItems(nGender, aItems);
    MS2Ptr<TDefaultItems> spJob;
    if (ms_mapJobItems.Lookup(nJobCode, spJob))
        spJob->GetItems(nGender, aItems);
    return 1;
}
MS2_REPLACE(0x1405848D0, CItemDefaultData::GetItems, 233, 0x44BBC771);

// @0x1405849c0
int CItemDefaultData::GetSlotItems(int nJobCode, int nGender, Unk_ItemDefaultKind eSlot, Unk_DefaultItemArray& aItems)
{
    CheckInit();
    if (nJobCode == 0)
        return 0;
    if (FUN_140583f70(nGender) == 0)
        return 0;
    MS2Ptr<TDefaultItems> spCommon(0);
    if (ms_mapJobItems.Lookup(0, spCommon))
        spCommon->GetSlotItems(nGender, eSlot, aItems);
    MS2Ptr<TDefaultItems> spJob(0);
    if (ms_mapJobItems.Lookup(nJobCode, spJob))
        spJob->GetSlotItems(nGender, eSlot, aItems);
    return 1;
}
MS2_REPLACE(0x1405849C0, CItemDefaultData::GetSlotItems, 252, 0x6E09E5B8);

// @0x140584ad0
void CItemDefaultData::GetRandomItems(int nJobCode, int nGender, ATL::CAtlArray<unsigned>& aItemIds)
{
    CheckInit();
    aItemIds.RemoveAll();
    if (FUN_140583f70(nGender) == 0)
        return;
    if (nJobCode == 0)
        return;
    MS2Ptr<TDefaultItems> spCommon(0);
    MS2Ptr<TDefaultItems> spJob(0);
    ms_mapJobItems.Lookup(0, spCommon);
    ms_mapJobItems.Lookup(nJobCode, spJob);
    if (!spCommon && !spJob)
        return;
    ATL::CAtlMap<Unk_ItemDefaultKind, TPtrValue<Unk_DefaultItemArray> >* pCommon = spCommon ? &spCommon->m_mapSlotItems[nGender] : 0;
    ATL::CAtlMap<Unk_ItemDefaultKind, TPtrValue<Unk_DefaultItemArray> >* pJob = spJob ? &spJob->m_mapSlotItems[nGender] : 0;
    for (int i = 0; i < 18; i++) {
        Unk_ItemDefaultKind eSlot = s_aSlots[i];
        TPtrValue<Unk_DefaultItemArray> spCommonList(0);
        TPtrValue<Unk_DefaultItemArray> spJobList(0);
        if (pCommon != 0)
            pCommon->Lookup(eSlot, spCommonList);
        if (pJob != 0)
            pJob->Lookup(eSlot, spJobList);
        if (!spCommonList && !spJobList)
            continue;
        int nCount = spCommonList ? spCommonList->GetCount() : 0;
        nCount += spJobList ? spJobList->GetCount() : 0;
        if (nCount == 0)
            continue;
        size_t nIndex = rand() % nCount;
        if (spCommonList && nIndex < spCommonList->GetCount()) {
            MS2Ptr<DefaultItemData> spItem = spCommonList->GetAt(nIndex);
            if (spItem.get() != 0) {
                aItemIds.Add(spItem->m_nItemId);
                continue;
            }
        }
        if (spCommonList)
            nIndex -= spCommonList->GetCount();
        if (spJobList && nIndex < spJobList->GetCount()) {
            MS2Ptr<DefaultItemData> spItem = spJobList->GetAt(nIndex);
            if (spItem.get() != 0) {
                aItemIds.Add(spItem->m_nItemId);
                continue;
            }
        }
    }
}
MS2_REPLACE(0x140584AD0, CItemDefaultData::GetRandomItems, 1301, 0xCC35D3F1);

// @0x140584ff0
void CItemDefaultData::GetCreateItems(TCreateCharInfo* pInfo, ATL::CAtlArray<unsigned>& aItemIds)
{
    CheckInit();
    aItemIds.RemoveAll();
    int nGender = pInfo->m_nGender;
    int nJobCode = pInfo->m_nJobCode;
    if (FUN_140583f70(nGender) == 0)
        return;
    if (nJobCode == 0)
        return;
    MS2Ptr<TDefaultItems> spCommon(0);
    MS2Ptr<TDefaultItems> spJob(0);
    ms_mapJobItems.Lookup(0, spCommon);
    ms_mapJobItems.Lookup(nJobCode, spJob);
    if (spCommon == 0 && spJob == 0)
        return;
    ATL::CAtlMap<Unk_ItemDefaultKind, TPtrValue<Unk_DefaultItemArray> >* pCommon = spCommon ? &spCommon->m_mapSlotItems[nGender] : 0;
    ATL::CAtlMap<Unk_ItemDefaultKind, TPtrValue<Unk_DefaultItemArray> >* pJob = spJob ? &spJob->m_mapSlotItems[nGender] : 0;
    bool bSelected = pInfo->m_b58;
    unsigned nSlot8Item = 0;
    unsigned nSlot9Item = 0;
    for (int i = 0; i < 18; i++) {
        Unk_ItemDefaultKind eSlot = s_aSlots[i];
        TPtrValue<Unk_DefaultItemArray> spCommonList(0);
        TPtrValue<Unk_DefaultItemArray> spJobList(0);
        if (pCommon != 0)
            pCommon->Lookup(eSlot, spCommonList);
        if (pJob != 0)
            pJob->Lookup(eSlot, spJobList);
        if (!spCommonList && !spJobList)
            continue;
        int nCount = spCommonList ? spCommonList->GetCount() : 0;
        nCount += spJobList ? spJobList->GetCount() : 0;
        if (nCount == 0)
            continue;
        MS2Ptr<DefaultItemData> spItem(0);
        if (bSelected) {
            if (spCommon)
                spItem = spCommon->GetSelected(nGender, eSlot);
            if (spJob)
                spItem = spJob->GetSelected(nGender, eSlot);
        }
        if (spItem == 0) {
            size_t nIndex = rand() % nCount;
            if (spCommonList && nIndex < spCommonList->GetCount()) {
                MS2Ptr<DefaultItemData> spRandom = spCommonList->GetAt(nIndex);
                if (spRandom.get() != 0)
                    spItem = spRandom;
            }
            if (spItem == 0) {
                if (spCommonList)
                    nIndex -= spCommonList->GetCount();
                if (spJobList && nIndex < spJobList->GetCount()) {
                    MS2Ptr<DefaultItemData> spRandom = spJobList->GetAt(nIndex);
                    if (spRandom.get() != 0)
                        spItem = spRandom;
                }
            }
        }
        if (spItem.get() != 0) {
            int nItemId = spItem->m_nItemId;
            if (eSlot == kItemDefaultKind8)
                nSlot8Item = nItemId;
            else if (eSlot == kItemDefaultKind9)
                nSlot9Item = nItemId;
            else
                aItemIds.Add(spItem->m_nItemId);
        }
    }
    CItemData* pSlot8Data = FUN_14053f870(nSlot8Item);
    if (pSlot8Data->FUN_14053d2b0()) {
        aItemIds.Add(nSlot8Item);
    } else {
        if (nSlot8Item > 0)
            aItemIds.Add(nSlot8Item);
        if (nSlot9Item > 0 && nSlot9Item != nSlot8Item)
            aItemIds.Add(nSlot9Item);
    }
}
MS2_REPLACE(0x140584FF0, CItemDefaultData::GetCreateItems, 1847, 0x4093CB4C);

// @0x140585730
CItemDefaultData::TDefaultItems::TDefaultItems(int nJobCode) : m_nJobCode(nJobCode)
{
    Init();
}

// @0x140585820
void CItemDefaultData::TDefaultItems::Clear()
{
    for (int i = 0; i < 2; i++) {
        m_mapSlotItems[i].RemoveAll();
        m_mapSelected[i].RemoveAll();
        m_mapItems[i].RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x140585820, CItemDefaultData::TDefaultItems, Clear, 130, 0x120DA11C);

// @0x1405858b0
void CItemDefaultData::TDefaultItems::Init()
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 18; j++) {
            TPtrValue<Unk_DefaultItemArray> spList(Unk_GrNewTag(0));
            m_mapSlotItems[i].SetAt(s_aSlots[j], spList);
        }
    }
}

// @0x140585970
void CItemDefaultData::TDefaultItems::AddItem(int nGender, MS2Ptr<DefaultItemData> spItem)
{
    if (FUN_140583f70(nGender) == 0)
        return;
    m_mapItems[nGender].SetAt(spItem->m_nItemId, spItem);
}

// @0x1405859f0
void CItemDefaultData::TDefaultItems::AddSlotItem(int nGender, Unk_ItemDefaultKind eSlot, MS2Ptr<DefaultItemData> spItem)
{
    if (FUN_140583f70(nGender) == 0)
        return;
    ATL::CAtlMap<Unk_ItemDefaultKind, TPtrValue<Unk_DefaultItemArray> >* pSlotItems = &m_mapSlotItems[nGender];
    ATL::CAtlMap<Unk_ItemDefaultKind, MS2Ptr<DefaultItemData> >* pSelected = &m_mapSelected[nGender];
    TPtrValue<Unk_DefaultItemArray> spList(0);
    if (!pSlotItems->Lookup(eSlot, spList)) {
        spList = Unk_GrNewTag(0);
        pSlotItems->SetAt(eSlot, spList);
    }
    spList->Add(spItem);
    if (spItem && spItem->m_bSelect)
        pSelected->SetAt(eSlot, spItem);
    MS2Ptr<CItemData> spItemData = FUN_14053f870(spItem->m_nItemId);
    if (eSlot == kItemDefaultKind8 && spItemData && spItemData->FUN_14053d2b0())
        AddSlotItem(nGender, kItemDefaultKind9, spItem);
}

// @0x140585c40
void CItemDefaultData::TDefaultItems::Add(int nGender, Unk_ItemDefaultKind eSlot, MS2Ptr<DefaultItemData> spItem)
{
    if (nGender == 2) {
        AddItem(0, spItem);
        AddItem(1, spItem);
        AddSlotItem(0, eSlot, spItem);
        AddSlotItem(1, eSlot, spItem);
    } else {
        if (FUN_140583f70(nGender) == 0)
            return;
        AddItem(nGender, spItem);
        AddSlotItem(nGender, eSlot, spItem);
    }
}

// @0x140585e30
int CItemDefaultData::TDefaultItems::HasItem(int nGender, int nItemId)
{
    if (FUN_140583f70(nGender) == 0)
        return 0;
    MS2Ptr<DefaultItemData> spItem;
    if (m_mapItems[nGender].Lookup(nItemId, spItem))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140585E30, CItemDefaultData::TDefaultItems, HasItem, 152, 0xEF7301D8);

// @0x140585ed0
int CItemDefaultData::TDefaultItems::GetItems(int nGender, Unk_DefaultItemArray& aItems)
{
    if (FUN_140583f70(nGender) == 0)
        return 0;
    ATL::CAtlMap<int, MS2Ptr<DefaultItemData> >* pItems = &m_mapItems[nGender];
    for (POSITION pos = pItems->GetStartPosition(); pos != 0; pItems->GetNext(pos)) {
        MS2Ptr<DefaultItemData> spItem = pItems->GetValueAt(pos);
        aItems.Add(spItem);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140585ED0, CItemDefaultData::TDefaultItems, GetItems, 181, 0x58FABA1B);

// @0x140585f90
int CItemDefaultData::TDefaultItems::GetSlotItems(int nGender, Unk_ItemDefaultKind eSlot, Unk_DefaultItemArray& aItems)
{
    if (FUN_140583f70(nGender) == 0)
        return 0;
    ATL::CAtlMap<Unk_ItemDefaultKind, TPtrValue<Unk_DefaultItemArray> >* pSlotItems = &m_mapSlotItems[nGender];
    TPtrValue<Unk_DefaultItemArray> spList(0);
    if (pSlotItems->Lookup(eSlot, spList))
        aItems.Append(*spList);
    return 1;
}
MS2_REPLACE_METHOD(0x140585F90, CItemDefaultData::TDefaultItems, GetSlotItems, 166, 0x071E7AE9);

// @0x140586040
MS2Ptr<DefaultItemData> CItemDefaultData::TDefaultItems::GetSelected(int nGender, Unk_ItemDefaultKind eSlot)
{
    if (FUN_140583f70(nGender) == 0)
        return MS2Ptr<DefaultItemData>(0);
    ATL::CAtlMap<Unk_ItemDefaultKind, MS2Ptr<DefaultItemData> >* pSelected = &m_mapSelected[nGender];
    MS2Ptr<DefaultItemData> spItem(0);
    pSelected->Lookup(eSlot, spItem);
    return spItem;
}
MS2_REPLACE_METHOD(0x140586040, CItemDefaultData::TDefaultItems, GetSelected, 187, 0x6812BCEF);
