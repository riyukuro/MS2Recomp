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
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// Unrecovered helpers (the xml loader helpers the other table units use).
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view

class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString GetXmlPath(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
template <class C> void XmlSplit(const CString&, C&, const char*);         // split into unsigneds
template <class C> int XmlTokenList(TiXmlElement*, const char*, C&);                // list attribute
// C3: FUN_140178570 is XmlTokenList<ATL::CAtlArray<int> >

MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// The sort-name tables of two ugc market lists (the same seven names, one copy per original translation unit).
static CStringA s_sortNamesA[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CStringA s_sortNamesB[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_pointer(0);                                              // @0x1400bb160 (data 0x143ab02a0)

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
    CString strPath = GetXmlPath("Table", "masteryUGCHousing.xml");
    TiXmlDocument doc;
    if (!GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false))
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    TiXmlElement* pMastery = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("masteryUGCHousing"));
    if (pMastery == 0)
        return false;
    for (TiXmlElement* pRow = ((class TiXmlElement*)((class Unk_XmlNode*)(pMastery))->FirstChild("v")); pRow != 0; pRow = ((class TiXmlElement*)((class Unk_XmlNode*)(pRow))->NextSibling("v")))
    {
        MS2Ptr<MasteryInteriorInfo> spInfo(new MasteryInteriorInfo);
        XmlGetAttr((class TiXmlElement*)(pRow), "value", spInfo->m_nValue);
        XmlGetAttr((class TiXmlElement*)(pRow), "grade", spInfo->m_nGrade);
        ATL::CAtlArray<unsigned> ids;
        ATL::CAtlArray<int> ranks;
        ATL::CAtlArray<int> counts;
        XmlTokenList(pRow, "rewardJobItemID", ids);
        XmlTokenList(pRow, "rewardJobItemRank", ranks);
        XmlTokenList(pRow, "rewardJobItemCount", counts);
        if (ids.GetCount() != ranks.GetCount())
            return false;
        if (ranks.GetCount() != counts.GetCount())
            return false;
        for (size_t i = 0; i < ids.GetCount(); ++i)
        {
            MS2Ptr<ItemEntity> spItem(new ItemEntity);
            spItem->m_itemId = ids[i];
            reinterpret_cast<ItemEntity*>(spItem.get())->SetRank(ranks[i]);
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
    CString strPath = GetXmlPath("Table", "ugcHousingExtendHeight.xml");
    TiXmlDocument doc;
    if (!GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false))
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (TiXmlElement* pRow = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v")); pRow != 0; pRow = ((class TiXmlElement*)((class Unk_XmlNode*)(pRow))->NextSibling("v")))
    {
        MS2Ptr<ExtendHeightInfo> spInfo(new ExtendHeightInfo);
        XmlGetAttr((class TiXmlElement*)(pRow), "height", spInfo->m_nHeight);
        XmlGetAttr((class TiXmlElement*)(pRow), "price", spInfo->m_nPrice);
        if (spInfo->m_nHeight >= m_nMaxHeight)
            m_nMaxHeight = spInfo->m_nHeight;
        m_mapHeight.SetAt(spInfo->m_nHeight, spInfo);
    }
    return true;
}

// @0x1406626f0
bool CMasteryInteriorTable::LoadArea()
{
    CString strPath = GetXmlPath("Table", "ugcHousingExtendArea.xml");
    TiXmlDocument doc;
    if (!GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false))
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (TiXmlElement* pRow = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v")); pRow != 0; pRow = ((class TiXmlElement*)((class Unk_XmlNode*)(pRow))->NextSibling("v")))
    {
        MS2Ptr<ExtendAreaInfo> spInfo(new ExtendAreaInfo);
        XmlGetAttr((class TiXmlElement*)(pRow), "area", spInfo->m_nArea);
        XmlGetAttr((class TiXmlElement*)(pRow), "price", spInfo->m_nPrice);
        CStringA strValue = Unk_ReadString((class Unk_XmlNode*)(pRow), "value", CStringA(""));
        ATL::CAtlArray<unsigned> sizes;
        XmlSplit(strValue, sizes, ",");
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
    CString strPath = GetXmlPath("Table", "ugcHousingPointReward.xml");
    TiXmlDocument doc;
    if (!GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false))
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (TiXmlElement* pRow = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v")); pRow != 0; pRow = ((class TiXmlElement*)((class Unk_XmlNode*)(pRow))->NextSibling("v")))
    {
        MS2Ptr<InteriorPointReward> spInfo(new InteriorPointReward);
        XmlGetAttr((class TiXmlElement*)(pRow), "housingPoint", spInfo->m_nPoint);
        XmlGetAttr((class TiXmlElement*)(pRow), "individualDropBoxId", spInfo->m_nDropBox);
        spInfo->m_strIcon = Unk_ReadString((class Unk_XmlNode*)(pRow), "icon", CStringA(""));
        spInfo->m_strKey = Unk_ReadString((class Unk_XmlNode*)(pRow), "stringKey", CStringA(""));
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
                if (spData.IsNull())
                    continue;
                if (!spData->limit.IsJobRecommended(nJob))
                    continue;
                rItems.Add(spItem);
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
