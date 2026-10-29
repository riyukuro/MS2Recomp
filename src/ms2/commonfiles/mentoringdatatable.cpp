// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MentoringDataTable: Table/MentoringConfig.xml (the mentoring
// attendance reward coins, the daily coin caps for mentor and mentee, the icon flag).
// MS2-UNIT: ?\mentoringdatatable.cpp
// MS2-RANGE: 0x14069bcb0-0x14069c3e0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\mentoringdatatable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/mentoringdatatable.h"
#include <algorithm>
#include <iterator>
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);              // FirstChildElement
    Unk_140165cf0* FUN_14086e8d0(const char* pszName);              // first child element (by name)
    Unk_140165cf0* FUN_14086e7e0(const char* pszName);              // next sibling element (by name)
};
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, int& rOut);
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned int& rOut);
int FUN_1408730a0(Unk_140165cf0* pElem, const char* pszName, bool& rOut);
short FUN_140315da0(const short& nValue, short nMin, short nMax);      // clamp

static int LoadRewardCoins(Unk_140165cf0* pParent, const char* pszName, std::vector<unsigned int>* pOut);

// @0x14069bcb0
MentoringDataTable::MentoringDataTable()
    : m_nMentorRewardCoin(0)
{
    m_nMaxMentorDailyRewardCoin = 0;
    m_nMaxMenteeDailyRewardCoin = 0;
    m_bShowIcon = true;
}

// @0x14069bd20
MentoringDataTable::~MentoringDataTable()
{
}

// @0x14069bd60
bool MentoringDataTable::Init()
{
    if (!Load())
        return false;
    return true;
}

// @0x14069bd90
bool MentoringDataTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "MentoringConfig.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return false;
    Unk_140165cf0* pConfig = pRoot->FUN_140165cf0("MentoringConfig");
    if (pConfig != 0)
        LoadConfig(pConfig);
    return true;
}

// @0x14069bf00
void MentoringDataTable::LoadConfig(Unk_140165cf0* pConfig)
{
    Unk_140165cf0* pAttend = pConfig->FUN_140165cf0("AttendReward");
    if (pAttend != 0)
        LoadRewardCoins(pAttend, "RewardCoin", &m_attendRewardCoins);
    FUN_140873220(pConfig, "maxMentorDailyRewardCoin", m_nMaxMentorDailyRewardCoin);
    FUN_140873220(pConfig, "maxMenteeDailyRewardCoin", m_nMaxMenteeDailyRewardCoin);
    FUN_1408730a0(pConfig, "isShowIcon", m_bShowIcon);
    Unk_140165cf0* pMentor = pConfig->FUN_140165cf0("MentorReward");
    if (pMentor != 0)
        FUN_140873220(pMentor, "coin", m_nMentorRewardCoin);
}

// @0x14069bff0
unsigned int MentoringDataTable::GetAttendRewardCoin(short nDay)
{
    if (m_attendRewardCoins.empty())
        return 0;
    short nIndex = FUN_140315da0(nDay, 0, (short)(m_attendRewardCoins.size() - 1));
    return m_attendRewardCoins[nIndex];
}

// Appends src to the end of out (0x140323a40, the dungeonroom helper).
template <class C> void AppendTo(const C& src, C& out)
{
    std::copy(src.begin(), src.end(), std::back_inserter(out));
}

// @0x14069c070
void MentoringDataTable::GetAttendRewardCoins(std::vector<unsigned int>& rOut)
{
    AppendTo(m_attendRewardCoins, rOut);
}

// @0x14069c0a0
unsigned int MentoringDataTable::GetRewardableCoin(unsigned int nCoin, unsigned int nTodayCoin, bool bMentee)
{
    unsigned int nMax;
    if (bMentee)
        nMax = m_nMaxMenteeDailyRewardCoin;
    else
        nMax = m_nMaxMentorDailyRewardCoin;
    unsigned int nLimit = nMax;
    if (nTodayCoin >= nLimit)
        return 0;
    unsigned int nRest = nLimit - nTodayCoin;
    return (std::min)(nCoin, nRest);
}

// @0x14069c120
unsigned int MentoringDataTable::GetMaxMenteeDailyRewardCoin()
{
    return m_nMaxMenteeDailyRewardCoin;
}

// @0x14069c140
unsigned int MentoringDataTable::GetMaxMentorDailyRewardCoin()
{
    return m_nMaxMentorDailyRewardCoin;
}

// @0x14069c150
static int LoadRewardCoins(Unk_140165cf0* pParent, const char* pszName, std::vector<unsigned int>* pOut)
{
    int nCount = 0;
    for (Unk_140165cf0* pChild = pParent->FUN_14086e8d0(pszName); pChild != 0; pChild = pChild->FUN_14086e7e0(pszName))
    {
        unsigned int nCoin;
        FUN_140873220(pChild, "v", nCoin);
        pOut->push_back(nCoin);
        nCount++;
    }
    return nCount > 0 ? 0 : 1;
}

MS2_EMIT_CRT_MEMMOVE_S();
