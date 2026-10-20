// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMasteryInteriorTable: the ugc housing mastery / extend
// height / extend area / point reward tables (Table/masteryUGCHousing.xml, ugcHousingExtendHeight.xml,
// ugcHousingExtendArea.xml, ugcHousingPointReward.xml) and their lookups, plus the CRBMap<.., MS2Ptr<..>> template glue.
// MS2-UNIT: ?\masteryinteriortable.cpp
// MS2-RANGE: 0x1400bafe0-0x1400bb180 .text$di
// MS2-RANGE: 0x140661c00-0x1406694a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_sortNamesA@@YAXXZ 0x1400bafe0 ; probe
// MS2-PIN: ??__Es_sortNamesB@@YAXXZ 0x1400bb0a0 ; probe
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@_J@ATL@@SA_NAEB_J0@Z 0x140665160 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@_J@ATL@@SAHAEB_J0@Z 0x1406651c0 ; unique
// MS2-PIN: ?Find@?$CRBTree@_JV?$MS2Ptr@UInteriorPointReward@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@UInteriorPointReward@@@@@3@@ATL@@IEBAPEAVCNode@12@_J@Z 0x1406654e0 ; unique
// MS2-PIN: ?GetKeyAt@?$CRBTree@HV?$MS2Ptr@UExtendAreaInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UExtendAreaInfo@@@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x1406658c0 ; unique
// MS2-PIN: ?GetKeyAt@?$CRBTree@HV?$MS2Ptr@UExtendHeightInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UExtendHeightInfo@@@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x140665920 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@HV?$MS2Ptr@UExtendAreaInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UExtendAreaInfo@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@UExtendAreaInfo@@@@PEAU__POSITION@@@Z 0x140665aa0 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@HV?$MS2Ptr@UExtendHeightInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UExtendHeightInfo@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@UExtendHeightInfo@@@@PEAU__POSITION@@@Z 0x140665b00 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@HV?$MS2Ptr@UExtendAreaInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UExtendAreaInfo@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x140668b10 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@HV?$MS2Ptr@UExtendHeightInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UExtendHeightInfo@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x140668b80 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@HV?$MS2Ptr@UMasteryInteriorInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UMasteryInteriorInfo@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x140668bf0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\masteryinteriortable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "masteryinteriortable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_140873220(Unk_140165cf0*, const char*, unsigned&);
void FUN_1408732e0(Unk_140165cf0*, const char*, __int64&);
CStringA FUN_14015f710(Unk_140165cf0*, const char*, CStringA strDefault);
void FUN_140177e10(CStringA& str, ATL::CAtlArray<unsigned>& rOut, const char* pszSep);         // split into unsigneds
void FUN_140178670(Unk_140165cf0*, const char*, ATL::CAtlArray<unsigned>& rOut);                // list attribute
void FUN_140178570(Unk_140165cf0*, const char*, ATL::CAtlArray<int>& rOut);                     // list attribute
bool FUN_14026b1c0(ItemEntity*, int);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// The sort-name tables of two ugc market lists (the same seven names, one copy per original translation unit).
static CStringA s_sortNamesA[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CStringA s_sortNamesB[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };   // zero-initialised pointer holder (0x1401cd100)
static Unk_1401cd100 s_pointer(NULL);                                         // 0x143ab02a0

// @0x140661c00
CMasteryInteriorTable::CMasteryInteriorTable()
{
    m_nMaxGrade = 1;
    m_mapMastery.RemoveAll();
    m_nMaxHeight = 1;
    m_mapHeight.RemoveAll();
    m_nMaxArea = 1;
    m_mapArea.RemoveAll();
    m_mapReward.RemoveAll();
}

// @0x140661d00
CMasteryInteriorTable::~CMasteryInteriorTable()
{
}

// @0x1406645a0
ExtendAreaInfo::ExtendAreaInfo() : m_nArea(0), m_nPrice(0), m_nWidth(0), m_nLength(0)
{
}

// @0x140664600
ExtendHeightInfo::ExtendHeightInfo() : m_nHeight(0), m_nPrice(0)
{
}

// @0x140664650
InteriorPointReward::InteriorPointReward() : m_nPoint(0), m_nDropBox(0)
{
    m_strIcon.Empty();
    m_strKey.Empty();
}

// @0x1406646e0
MasteryInteriorInfo::MasteryInteriorInfo() : m_nGrade(0), m_nValue(0)
{
}

// @0x140661d80
bool CMasteryInteriorTable::Load()
{
    if (!LoadMastery())
        return false;
    if (!LoadHeight())
        return false;
    if (!LoadArea())
        return false;
    if (!LoadRewards())
        return false;
    return true;
}

// @0x140661df0
bool CMasteryInteriorTable::LoadMastery()
{
    CString strPath = FUN_14071a5b0("Table", "masteryUGCHousing.xml");
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return false;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    Unk_140165cf0* pMastery = pRoot->FUN_140165cf0("masteryUGCHousing");
    if (pMastery == 0)
        return false;
    for (Unk_140165cf0* pRow = pMastery->FUN_140165cf0("v"); pRow != 0; pRow = pRow->FUN_140168650("v"))
    {
        MS2Ptr<MasteryInteriorInfo> spInfo(new MasteryInteriorInfo);
        FUN_140873220(pRow, "value", spInfo->m_nValue);
        FUN_1408731e0(pRow, "grade", spInfo->m_nGrade);
        ATL::CAtlArray<unsigned> ids;
        ATL::CAtlArray<int> ranks;
        ATL::CAtlArray<int> counts;
        FUN_140178670(pRow, "rewardJobItemID", ids);
        FUN_140178570(pRow, "rewardJobItemRank", ranks);
        FUN_140178570(pRow, "rewardJobItemCount", counts);
        if (ids.GetCount() != ranks.GetCount())
            return false;
        if (ranks.GetCount() != counts.GetCount())
            return false;
        for (size_t i = 0; i < ids.GetCount(); ++i)
        {
            MS2Ptr<ItemEntity> spItem(new ItemEntity);
            spItem->m_itemId = ids[i];
            FUN_14026b1c0(spItem.get(), ranks[i]);
            spItem->m_count = counts[i];
            spInfo->m_items.Add(spItem);
        }
        if (spInfo->m_nGrade >= m_nMaxGrade)
            m_nMaxGrade = spInfo->m_nGrade;
        m_mapMastery.SetAt(spInfo->m_nGrade, spInfo);
    }
    return true;
}

// @0x140662430
bool CMasteryInteriorTable::LoadHeight()
{
    CString strPath = FUN_14071a5b0("Table", "ugcHousingExtendHeight.xml");
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return false;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pRow = pRoot->FUN_140165cf0("v"); pRow != 0; pRow = pRow->FUN_140168650("v"))
    {
        MS2Ptr<ExtendHeightInfo> spInfo(new ExtendHeightInfo);
        FUN_1408731e0(pRow, "height", spInfo->m_nHeight);
        FUN_1408732e0(pRow, "price", spInfo->m_nPrice);
        if (spInfo->m_nHeight >= m_nMaxHeight)
            m_nMaxHeight = spInfo->m_nHeight;
        m_mapHeight.SetAt(spInfo->m_nHeight, spInfo);
    }
    return true;
}

// @0x1406626f0
bool CMasteryInteriorTable::LoadArea()
{
    CString strPath = FUN_14071a5b0("Table", "ugcHousingExtendArea.xml");
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return false;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pRow = pRoot->FUN_140165cf0("v"); pRow != 0; pRow = pRow->FUN_140168650("v"))
    {
        MS2Ptr<ExtendAreaInfo> spInfo(new ExtendAreaInfo);
        FUN_1408731e0(pRow, "area", spInfo->m_nArea);
        FUN_1408732e0(pRow, "price", spInfo->m_nPrice);
        CStringA strValue = FUN_14015f710(pRow, "value", CStringA(""));
        ATL::CAtlArray<unsigned> sizes;
        FUN_140177e10(strValue, sizes, "x");
        if (sizes.GetCount() != 2)
        {
            spInfo->m_nWidth = 0;
            spInfo->m_nLength = 0;
        }
        else
        {
            spInfo->m_nWidth = sizes[0];
            spInfo->m_nLength = sizes[1];
        }
        if (spInfo->m_nArea >= m_nMaxArea)
            m_nMaxArea = spInfo->m_nArea;
        m_mapArea.SetAt(spInfo->m_nArea, spInfo);
    }
    return true;
}

// @0x140662ae0
bool CMasteryInteriorTable::LoadRewards()
{
    CString strPath = FUN_14071a5b0("Table", "ugcHousingPointReward.xml");
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return false;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pRow = pRoot->FUN_140165cf0("v"); pRow != 0; pRow = pRow->FUN_140168650("v"))
    {
        MS2Ptr<InteriorPointReward> spInfo(new InteriorPointReward);
        FUN_1408732e0(pRow, "housingPoint", spInfo->m_nPoint);
        FUN_140873220(pRow, "individualDropBoxId", spInfo->m_nDropBox);
        spInfo->m_strIcon = FUN_14015f710(pRow, "icon", CStringA(""));
        spInfo->m_strKey = FUN_14015f710(pRow, "stringKey", CStringA(""));
        m_mapReward.SetAt(spInfo->m_nPoint, spInfo);
    }
    return true;
}

// @0x140662ea0
void CMasteryInteriorTable::AddMastery(__int64& nCurrent, unsigned short& nGrade, __int64 nAmount)
{
    if (nGrade >= m_nMaxGrade)
        return;
    for (int i = nGrade + 1; i <= m_nMaxGrade; ++i)
    {
        MS2Ptr<MasteryInteriorInfo> spInfo(0);
        if (!m_mapMastery.Lookup(i, spInfo))
            return;
        __int64 nSum = nCurrent + nAmount;
        if (nSum >= spInfo->m_nValue)
        {
            nCurrent = 0;
            nGrade = nGrade + 1;
            nAmount = nSum - spInfo->m_nValue;
        }
        else
        {
            nCurrent = nSum;
            nAmount = 0;
        }
        if (nAmount <= 0)
            return;
        if (nGrade >= m_nMaxGrade)
            return;
    }
}

// @0x140663010
// MS2-FUNCTIONAL: cleanup/branch layout of the item loop differs (exe duplicates the release paths)
void CMasteryInteriorTable::GetInteriorItems(int nLevel, int nJob, ATL::CAtlArray<MS2Ptr<ItemEntity> >& rItems)
{
    if (nLevel > m_nMaxGrade)
        return;
    MS2Ptr<MasteryInteriorInfo> spInfo(0);
    if (m_mapMastery.Lookup(nLevel, spInfo))
    {
        for (size_t i = 0; i < spInfo->m_items.GetCount(); ++i)
        {
            MS2Ptr<ItemEntity> spItem = spInfo->m_items[i];
            if (spItem->m_itemId != 0)
            {
                MS2Ptr<CItemData> spData = FUN_14053f870(spItem->m_itemId);
                if (!spData.IsNull())
                {
                    if (spData->limit.FUN_140545da0(nJob))
                        rItems.Add(spItem);
                }
            }
        }
    }
}

// @0x1406631b0
unsigned CMasteryInteriorTable::GetMasteryValue(int nGrade)
{
    if (nGrade > m_nMaxGrade)
        return 0;
    MS2Ptr<MasteryInteriorInfo> spInfo(0);
    if (m_mapMastery.Lookup(nGrade, spInfo))
        return spInfo->m_nValue;
    return 0;
}

// @0x140663250
__int64 CMasteryInteriorTable::GetMasteryTotal(unsigned short nGrade, __int64 nCurrent)
{
    int nTotal = 0;
    for (int i = 1; i <= nGrade; ++i)
        nTotal += GetMasteryValue(i);
    return nTotal + nCurrent;
}

// @0x1406632c0
bool CMasteryInteriorTable::FindNextHeight(unsigned char nHeight, unsigned char& rNext, __int64& rPrice)
{
    if (nHeight >= m_nMaxHeight)
        return false;
    for (int i = nHeight + 1; i <= m_nMaxHeight; ++i)
    {
        MS2Ptr<ExtendHeightInfo> spInfo(0);
        if (m_mapHeight.Lookup(i, spInfo))
        {
            rNext = (unsigned char)i;
            rPrice = spInfo->m_nPrice;
            return true;
        }
    }
    return false;
}

// @0x1406633a0
bool CMasteryInteriorTable::FindNextArea(unsigned char nArea, unsigned char& rNext, __int64& rPrice, int& rWidth, int& rLength)
{
    if (nArea >= m_nMaxArea)
        return false;
    for (int i = nArea + 1; i <= m_nMaxArea; ++i)
    {
        MS2Ptr<ExtendAreaInfo> spInfo(0);
        if (m_mapArea.Lookup(i, spInfo))
        {
            rNext = (unsigned char)i;
            rPrice = spInfo->m_nPrice;
            rWidth = spInfo->m_nWidth;
            rLength = spInfo->m_nLength;
            return true;
        }
    }
    return false;
}

// @0x1406634b0
unsigned CMasteryInteriorTable::GetDropBox(__int64 nPoints)
{
    __int64 nBest = 0;
    for (POSITION pos = m_mapReward.GetHeadPosition(); pos; m_mapReward.GetNext(pos))
    {
        __int64 nKey = m_mapReward.GetKeyAt(pos);
        if (nKey <= nPoints && nKey > nBest)
            nBest = nKey;
    }
    if (nBest != 0)
    {
        MS2Ptr<InteriorPointReward> spInfo(0);
        if (m_mapReward.Lookup(nBest, spInfo))
            return spInfo->m_nDropBox;
    }
    return 0;
}

// @0x1406635c0
MS2Ptr<MasteryInteriorInfo> CMasteryInteriorTable::GetMastery(unsigned short nGrade)
{
    MS2Ptr<MasteryInteriorInfo> spInfo(0);
    m_mapMastery.Lookup(nGrade, spInfo);
    return spInfo;
}

// @0x140663640
MS2Ptr<InteriorPointReward> CMasteryInteriorTable::GetPointReward(__int64 nPoints)
{
    __int64 nBest = 0;
    for (POSITION pos = m_mapReward.GetHeadPosition(); pos; m_mapReward.GetNext(pos))
    {
        __int64 nKey = m_mapReward.GetKeyAt(pos);
        if (nKey <= nPoints && nKey > nBest)
            nBest = nKey;
    }
    if (nBest != 0)
    {
        MS2Ptr<InteriorPointReward> spInfo(0);
        if (m_mapReward.Lookup(nBest, spInfo))
            return spInfo;
    }
    return MS2Ptr<InteriorPointReward>(0);
}

// @0x140663790
MS2Ptr<ExtendAreaInfo> CMasteryInteriorTable::GetArea(int nArea)
{
    MS2Ptr<ExtendAreaInfo> spInfo(0);
    m_mapArea.Lookup(nArea, spInfo);
    return spInfo;
}

// @0x140663820
MS2Ptr<ExtendAreaInfo> CMasteryInteriorTable::GetPreviousArea(int nArea)
{
    MS2Ptr<ExtendAreaInfo> spResult(0);
    for (POSITION pos = m_mapArea.GetHeadPosition(); pos; m_mapArea.GetNext(pos))
    {
        int nKey = m_mapArea.GetKeyAt(pos);
        MS2Ptr<ExtendAreaInfo> spInfo = m_mapArea.GetValueAt(pos);
        if (spInfo == 0)
            continue;
        if (nKey < nArea)
        {
            spResult = spInfo;
            continue;
        }
        break;
    }
    return spResult;
}

// @0x140663970
MS2Ptr<ExtendAreaInfo> CMasteryInteriorTable::GetNextArea(int nArea)
{
    for (POSITION pos = m_mapArea.GetHeadPosition(); pos; m_mapArea.GetNext(pos))
    {
        int nKey = m_mapArea.GetKeyAt(pos);
        MS2Ptr<ExtendAreaInfo> spInfo = m_mapArea.GetValueAt(pos);
        if (spInfo == 0)
            continue;
        if (nKey > nArea)
            return spInfo;
    }
    return MS2Ptr<ExtendAreaInfo>(0);
}

// @0x140663ab0
MS2Ptr<ExtendHeightInfo> CMasteryInteriorTable::GetHeight(int nHeight)
{
    MS2Ptr<ExtendHeightInfo> spInfo(0);
    m_mapHeight.Lookup(nHeight, spInfo);
    return spInfo;
}

// @0x140663b30
MS2Ptr<ExtendHeightInfo> CMasteryInteriorTable::GetPreviousHeight(int nHeight)
{
    MS2Ptr<ExtendHeightInfo> spResult(0);
    for (POSITION pos = m_mapHeight.GetHeadPosition(); pos; m_mapHeight.GetNext(pos))
    {
        int nKey = m_mapHeight.GetKeyAt(pos);
        MS2Ptr<ExtendHeightInfo> spInfo = m_mapHeight.GetValueAt(pos);
        if (spInfo == 0)
            continue;
        if (nKey < nHeight)
        {
            spResult = spInfo;
            continue;
        }
        break;
    }
    return spResult;
}

// @0x140663c80
MS2Ptr<ExtendHeightInfo> CMasteryInteriorTable::GetNextHeight(int nHeight)
{
    for (POSITION pos = m_mapHeight.GetHeadPosition(); pos; m_mapHeight.GetNext(pos))
    {
        int nKey = m_mapHeight.GetKeyAt(pos);
        MS2Ptr<ExtendHeightInfo> spInfo = m_mapHeight.GetValueAt(pos);
        if (spInfo == 0)
            continue;
        if (nKey > nHeight)
            return spInfo;
    }
    return MS2Ptr<ExtendHeightInfo>(0);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9b520-0x142c9b580 .text$yd
