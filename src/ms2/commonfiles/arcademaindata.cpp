// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CArcadeDataTable: the arcade games (Table/arcadeGame.xml),
// their rewards per round (Table/Server/arcadeReward.xml) and the record holders (Table/arcadeGameRecord.xml).
// MS2-UNIT: ?\arcademaindata.cpp
// MS2-RANGE: 0x1401a2e40-0x1401adea0 .text$mn
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2SvrPtr@VCArcadeMainData@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$MS2SvrPtr@VCArcadeMainData@@@@@3@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x1401a9dd0
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@@4@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x1401a9ec0
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$vector@V?$MS2SvrPtr@VCArcadeRewardData@@@@V?$allocator@V?$MS2SvrPtr@VCArcadeRewardData@@@@@std@@@std@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$vector@V?$MS2SvrPtr@VCArcadeRewardData@@@@V?$allocator@V?$MS2SvrPtr@VCArcadeRewardData@@@@@std@@@std@@@4@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x1401a9fb0
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$vector@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@@std@@@4@@ATL@@QEBAPEBVCPair@12@AEBH@Z 0x1401aa620
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$vector@V?$MS2SvrPtr@VCArcadeRewardData@@@@V?$allocator@V?$MS2SvrPtr@VCArcadeRewardData@@@@@std@@@std@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$vector@V?$MS2SvrPtr@VCArcadeRewardData@@@@V?$allocator@V?$MS2SvrPtr@VCArcadeRewardData@@@@@std@@@std@@@4@@ATL@@QEBAPEBVCPair@12@AEBH@Z 0x1401aa660
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x1401a96b0
// MS2-PIN: ?Hash@?$CDefaultHashTraits@H@ATL@@SAKAEBH@Z 0x1401aa180
// The exe's MainPtr copies AddRef and moves steal (construct<MainPtr&> calls the copy ctor, construct<MainPtr&&> and the
// sort helpers' std::move the steal ctor); ms2svrptr.h steals on T& instead: same net refcounts, pinned by name, functional.
// MS2-PIN: ??$construct@V?$MS2SvrPtr@VCArcadeMainData@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2SvrPtr@VCArcadeMainData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2SvrPtr@VCArcadeMainData@@@@@1@QEAV?$MS2SvrPtr@VCArcadeMainData@@@@AEAV3@@Z 0x1401a7e90
// MS2-PIN: ??$construct@V?$MS2SvrPtr@VCArcadeMainData@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$MS2SvrPtr@VCArcadeMainData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2SvrPtr@VCArcadeMainData@@@@@1@QEAV?$MS2SvrPtr@VCArcadeMainData@@@@$$QEAV3@@Z 0x1401a7f30
// MS2-PIN: ??$_Insertion_sort_unchecked@PEAV?$MS2SvrPtr@VCArcadeMainData@@@@UUnk_ArcadeMainLess@@@std@@YAPEAV?$MS2SvrPtr@VCArcadeMainData@@@@PEAV1@QEAV1@UUnk_ArcadeMainLess@@@Z 0x1401a5790
// MS2-PIN: ??$_Make_heap_unchecked@PEAV?$MS2SvrPtr@VCArcadeMainData@@@@UUnk_ArcadeMainLess@@@std@@YAXPEAV?$MS2SvrPtr@VCArcadeMainData@@@@0UUnk_ArcadeMainLess@@@Z 0x1401a59b0
// MS2-PIN: ??$_Pop_heap_unchecked@PEAV?$MS2SvrPtr@VCArcadeMainData@@@@UUnk_ArcadeMainLess@@@std@@YAXPEAV?$MS2SvrPtr@VCArcadeMainData@@@@0UUnk_ArcadeMainLess@@@Z 0x1401a69d0
// MS2-PIN: ??$swap@V?$MS2SvrPtr@VCArcadeMainData@@@@X@std@@YAXAEAV?$MS2SvrPtr@VCArcadeMainData@@@@0@Z 0x1401a8540
// MS2-FUNCTIONAL ??$swap@V?$MS2SvrPtr@VCArcadeMainData@@@@X@std@@YAXAEAV?$MS2SvrPtr@VCArcadeMainData@@@@0@Z: T tmp(std::move(a)) calls the exe move ctor 0x1401a85d0; the placeholder has none, so it binds the const& copy (same ms2svrptr.h retype)
// MS2-FUNCTIONAL ??$construct@V?$MS2SvrPtr@VCArcadeMainData@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2SvrPtr@VCArcadeMainData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2SvrPtr@VCArcadeMainData@@@@@1@QEAV?$MS2SvrPtr@VCArcadeMainData@@@@AEAV3@@Z: the exe MS2SvrPtr has no non-const-lvalue steal ctor: construct<T&> calls the const& copy (0x1401a8600), the placeholder (ms2svrptr.h) binds its steal ctor (0x1401a85d0); retyping the steal as a move ctor touches 30 units
// MS2-FUNCTIONAL ??$construct@V?$MS2SvrPtr@VCArcadeMainData@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$MS2SvrPtr@VCArcadeMainData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2SvrPtr@VCArcadeMainData@@@@@1@QEAV?$MS2SvrPtr@VCArcadeMainData@@@@$$QEAV3@@Z: the exe steal ctor 0x1401a85d0 is MS2SvrPtr's move ctor (construct<T&&> calls it), the placeholder has none so the rvalue binds the const& copy (0x1401a8600); same ms2svrptr.h retype
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\arcademaindata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/carcadedatatable.h"
#include <algorithm>
#include <functional>
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (same ones continentregiontable.cpp uses).
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14016a5c0(const char* psz, int n);
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
bool FUN_14028f710(Unk_140165cf0* pElem);                               // the element is usable

// The client string tables (singleton at 0x143aac298): FUN_141811980(table, id) is the string of id in table.
class Unk_1401a9d70 { public: CStringW FUN_141811980(int nTable, int nId); };
extern Unk_1401a9d70* DAT_143aac298;
// @0x1401a9d70
inline Unk_1401a9d70* GetStringTable() { return DAT_143aac298; }

// @0x1401aa6a0
// The npc's display name: "<title> <name>", or the name alone when the npc has no title (string tables 0x13 and 2).
inline CStringW FUN_1401aa6a0(int nNpcId)
{
    CStringW strTitle = GetStringTable()->FUN_141811980(0x13, nNpcId);
    CStringW strName = GetStringTable()->FUN_141811980(2, nNpcId);
    if (strTitle.GetLength() == 0)
        return strName;
    CStringW str;
    str.Format(L"%s %s", (const wchar_t*)strTitle, (const wchar_t*)strName);
    return str;
}

// The order of GetMainDataList: by sortingOrder, then by id.
struct Unk_ArcadeMainLess
{
    // @0x1401a9310
    bool operator()(const CArcadeDataTable::MainPtr& a, const CArcadeDataTable::MainPtr& b) const
    {
        if (a->m_nSortingOrder == b->m_nSortingOrder)
            return a->m_nId < b->m_nId;
        return a->m_nSortingOrder < b->m_nSortingOrder;
    }
};

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CArcadeDataTable::s_bInit;
#endif

// @0x1401a2e40
bool CArcadeDataTable::Load()
{
    if (!LoadMain())
        return false;
    if (!LoadRecord())
        return false;
    SetInit(true);
    return true;
}

// @0x1401a2e90
bool CArcadeDataTable::LoadMain()
{
    CString strPath = FUN_14071a5b0("Table", "arcadeGame.xml");
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("arcadeGame"); pNode != 0; pNode = pNode->FUN_140168650("arcadeGame"))
    {
        MainPtr pData(new CArcadeMainData);
        int nId = 0;
        FUN_1408731e0(pNode, "id", nId);
        pData->m_nId = nId;
        FUN_1408731e0(pNode, "sortingOrder", pData->m_nSortingOrder);
        FUN_140873420(pNode, "arcadeBanner", pData->m_strArcadeBanner);
        FUN_140873220(pNode, "targetField", pData->m_nTargetField);
        FUN_1408730a0(pNode, "isEventArcade", pData->m_bIsEventArcade);
        m_mapMain.SetAt(pData->m_nId, pData);
    }
    return true;
}

// @0x1401a31a0
bool CArcadeDataTable::LoadReward()
{
    CString strPath = FUN_14071a5b0("Table/Server", "arcadeReward.xml");
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("arcadeGame"); pNode != 0; pNode = pNode->FUN_140168650("arcadeGame"))
    {
        int nArcadeId = 0;
        FUN_1408731e0(pNode, "arcadeId", nArcadeId);
        int nId = nArcadeId;
        std::vector<RewardPtr> aReward;
        aReward.resize(MAX_ROUND);
        aReward[0] = new CArcadeRewardData;
        for (Unk_140165cf0* pReward = pNode->FUN_140165cf0("reward"); pReward != 0; pReward = pReward->FUN_140168650("reward"))
        {
            if (!FUN_14028f710(pReward))
                continue;
            RewardPtr pData(new CArcadeRewardData);
            pData->m_nArcadeId = nId;
            FUN_1408731e0(pReward, "round", pData->m_nRound);
            FUN_140873360(pReward, "expRate", pData->m_fExpRate);
            FUN_1408732e0(pReward, "meso", pData->m_nMeso);
            if (pData->m_nRound < MAX_ROUND)
                aReward[pData->m_nRound] = pData;
        }
        m_mapReward.SetAt(nId, aReward);
    }
    return true;
}

// @0x1401a35d0
bool CArcadeDataTable::LoadRecord()
{
    CString strPath = FUN_14071a5b0("Table", "arcadeGameRecord.xml");
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("arcadeGame"); pNode != 0; pNode = pNode->FUN_140168650("arcadeGame"))
    {
        int nArcadeId = 0;
        FUN_1408731e0(pNode, "id", nArcadeId);
        int nId = nArcadeId;
        std::vector<Unk_ArcadeRecord> aRecord;
        aRecord.reserve(10);
        for (Unk_140165cf0* pRank = pNode->FUN_140165cf0("rank"); pRank != 0; pRank = pRank->FUN_140168650("rank"))
        {
            Unk_ArcadeRecord record;
            unsigned nNpcId = 0;
            FUN_140873220(pRank, "npcID", nNpcId);
            FUN_1408731e0(pRank, "score", record.first);
            record.second = FUN_1401aa6a0(nNpcId);
            aRecord.push_back(record);
        }
        std::sort(aRecord.begin(), aRecord.end(), std::greater<Unk_ArcadeRecord>());
        m_mapRecord.SetAt(nId, aRecord);
    }
    return true;
}

// @0x1401a3940
CArcadeDataTable::MainPtr CArcadeDataTable::GetMainData(int nId)
{
    CheckInit();
    MainPtr p(0);
    if (!m_mapMain.Lookup(nId, p))
        return MainPtr(0);
    return p;
}

// @0x1401a3a00
void CArcadeDataTable::GetMainDataList(std::vector<MainPtr>& out)
{
    CheckInit();
    out.clear();
    out.reserve(m_mapMain.GetCount());
    POSITION pos = m_mapMain.GetStartPosition();
    while (pos != 0)
    {
        out.push_back(m_mapMain.GetValueAt(pos));
        m_mapMain.GetNext(pos);
    }
    std::sort(out.begin(), out.end(), Unk_ArcadeMainLess());
}

// @0x1401a3ae0
void CArcadeDataTable::GetRecords(int nId, std::vector<Unk_ArcadeRecord>& out) const
{
    CheckInit();
    const RecordMap::CPair* pPair = m_mapRecord.Lookup(nId);
    if (pPair != 0)
        out = pPair->m_value;
}

// @0x1401a3b40
CArcadeDataTable::RewardPtr CArcadeDataTable::GetReward(int nId, int nRound) const
{
    CheckInit();
    const RewardMap::CPair* pPair = m_mapReward.Lookup(nId);
    if (pPair == 0)
        return RewardPtr(0);
    if ((int)pPair->m_value.size() < nRound)
        return RewardPtr(0);
    return pPair->m_value[nRound];
}

// @0x1401a8b20
CArcadeMainData::CArcadeMainData()
{
    m_nId = 0;
    m_nSortingOrder = 0;
    m_nTargetField = 0;
    m_bIsEventArcade = false;
}

// @0x1401a8f10
CArcadeMainData::~CArcadeMainData()
{
}

// @0x1401a8b90
CArcadeRewardData::CArcadeRewardData()
{
    m_nArcadeId = 0;
    m_nRound = 0;
    m_fExpRate = 0;
    m_nMeso = 0;
}

// @0x1401a8f40
CArcadeRewardData::~CArcadeRewardData()
{
}

// @0x1401a9600
void CArcadeDataTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CArcadeDataTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1401abe90
void CArcadeDataTable::SetInit(bool b)
{
    s_bInit = b;
}
