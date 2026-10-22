// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The ranking client data: CRankUgcMarketBuy, the arena grade
// table (pvpRankingDuelMode.xml) and the CRankViewer singleton with the CAtlArray glue over its lists.
// MS2-UNIT: ?\rankugcmarketbuy.cpp
// MS2-RANGE: 0x140768690-0x14076a1e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GCRankUgcMarketBuy@@UEAAPEAXI@Z 0x140768a80 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7CRankingArenaDataTable@@6B?$TSingleton@VCRankingArenaDataTable@@@@@ 0x142d87d80
// MS2-PIN: ??_7CRankingArenaDataTable@@6B?$CValidData@VCRankingArenaDataTable@@@@@ 0x142d87d90
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\rankugcmarketbuy.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <errno.h>
#include <string.h>
#include <typeinfo>

#include "rankugcmarketbuy.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"

// The table file loader helpers.
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
CString FUN_14016a5c0(const char* psz, int n);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CRankingArenaDataTable::s_bInit;
#endif

// ---- CRankUgcMarketBuy ----

// @0x140768690
CRankUgcMarketBuy::CRankUgcMarketBuy()
{
    Reset();
}

// @0x140768700
CRankUgcMarketBuy::~CRankUgcMarketBuy()
{
    Reset();
}

// @0x140768770
void CRankUgcMarketBuy::Reset()
{
    m_nId = 0;
    m_strName = L"";
    m_strText = "";
    m_nFlag = 0;
    m_nValue = 0;
    m_nCount = 0;
}

// @0x1407687f0
void CRankUgcMarketBuy::Write(COutputStream& out)
{
    out.WriteInt64(m_nId);
    out.WriteUnicodeString(m_strName);
    out.WriteUnicodeStringA(m_strText);
    out.WriteUInt8((unsigned char)m_nFlag);
    out.WriteInt64(m_nValue);
    out.WriteInt32(m_nCount);
}

// @0x1407688c0
void CRankUgcMarketBuy::Read(CInPacket& packet)
{
    m_nId = packet.ReadInt64();
    m_strName = packet.ReadUnicodeString();
    m_strText = packet.ReadUnicodeStringA();
    m_nFlag = packet.ReadUInt8();
    m_nValue = packet.ReadInt64();
    m_nCount = packet.ReadInt32();
}

// ---- RankingArenaData ----

// @0x140768ac0
RankingArenaData::RankingArenaData()
    : m_nGrade(0), m_nGradeRating(0), m_nWinnerReward(0), m_nLoserReward(0), m_nWeeklyRewardMax(0), m_nWinnerRating(0),
      m_nLoserRating(0)
{
}

// @0x140768b50
RankingArenaData::~RankingArenaData()
{
}

// @0x140769130
RankingArenaData& RankingArenaData::operator=(const RankingArenaData& o)
{
    CPtred::operator=(o);
    m_nGrade = o.m_nGrade;
    m_nGradeRating = o.m_nGradeRating;
    m_nWinnerReward = o.m_nWinnerReward;
    m_nLoserReward = o.m_nLoserReward;
    m_nWeeklyRewardMax = o.m_nWeeklyRewardMax;
    m_nWinnerRating = o.m_nWinnerRating;
    m_nLoserRating = o.m_nLoserRating;
    return *this;
}

// ---- CRankingArenaDataTable ----

// @0x140768b80
CRankingArenaDataTable::CRankingArenaDataTable()
{
}

// @0x140768c10
CRankingArenaDataTable::~CRankingArenaDataTable()
{
}

// @0x140768c90
bool CRankingArenaDataTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "pvpRankingDuelMode.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return false;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("gradeInfo"); pNode != 0; pNode = pNode->FUN_140168650("gradeInfo"))
    {
        RankingArenaData kData;
        FUN_1408731e0(pNode, "grade", kData.m_nGrade);
        if (kData.m_nGrade == 0)
            continue;
        if (kData.m_nGrade >= 8)
            continue;
        FUN_1408731e0(pNode, "gradeRating", kData.m_nGradeRating);
        FUN_1408731e0(pNode, "winnerReward", kData.m_nWinnerReward);
        FUN_1408731e0(pNode, "loserReward", kData.m_nLoserReward);
        FUN_1408731e0(pNode, "weeklyRewardMax", kData.m_nWeeklyRewardMax);
        FUN_1408731e0(pNode, "winnerRating", kData.m_nWinnerRating);
        FUN_1408731e0(pNode, "loserRating", kData.m_nLoserRating);
        m_aGrades[kData.m_nGrade] = kData;
    }
    for (int i = 1; i < 8; i++)
    {
        if (m_aGrades[i].m_nGrade == 0)
            return false;
    }
    SetInit(true);
    return true;
}

// @0x140768fb0
RankingArenaData* CRankingArenaDataTable::GetGrade(int nGrade)
{
    CheckInit();
    if (nGrade >= 8)
        return &m_aGrades[1];
    return &m_aGrades[nGrade];
}

// @0x140769000
// MS2-FUNCTIONAL: loop exit jump layout differs
RankingArenaData* CRankingArenaDataTable::GetGradeOfRating(int nRating)
{
    CheckInit();
    int nFound = 8;
    for (int i = 1; i < 8; i++)
    {
        if (m_aGrades[i].m_nGradeRating > nRating)
        {
            nFound = i;
            break;
        }
    }
    if (nFound == 1)
        return &m_aGrades[1];
    return &m_aGrades[nFound - 1];
}

// @0x1407692e0
void CRankingArenaDataTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CRankingArenaDataTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// the UCRT memmove_s this TU's CString code inlines
// @0x1407693a0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- CRankViewer ----

// @0x1407694c0
CRankViewer::CRankViewer()
{
}

// @0x140769530
CRankViewer::~CRankViewer()
{
    m_aKind0.RemoveAll();
    m_aKind1.RemoveAll();
}

// @0x1407695c0
void CRankViewer::ReadList(CInPacket& packet)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        int nKind = packet.ReadUInt8();
        ATL::CAtlArray<MS2Ptr<CRankUgcMarketBuy> >* pList = 0;
        if (nKind == 0)
            pList = &m_aKind0;
        else if (nKind == 1)
            pList = &m_aKind1;
        if (pList == 0)
            return;
        pList->RemoveAll();
        int nCount = packet.ReadInt32();
        for (int i = 0; i < nCount; i++)
        {
            MS2Ptr<CRankUgcMarketBuy> spEntry(new CRankUgcMarketBuy);
            spEntry->Read(packet);
            pList->Add(spEntry);
        }
    }
}

// @0x140769800
ATL::CAtlArray<MS2Ptr<CRankUgcMarketBuy> >* CRankViewer::GetKind0List()
{
    return &m_aKind0;
}

// @0x140769820
ATL::CAtlArray<MS2Ptr<CRankUgcMarketBuy> >* CRankViewer::GetKind1List()
{
    return &m_aKind1;
}

// @0x140769780
void CRankViewer::OnPacket(CInPacket& packet)
{
    int nKind = packet.ReadUInt8();
    if (nKind == 0)
    {
        ReadList(packet);
        ReadList(packet);
    }
}
