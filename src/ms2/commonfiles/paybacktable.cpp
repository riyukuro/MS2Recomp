// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PaybackTable, the merat payback share per adventure level
// (Table/PaybackTable.xml) with the payback period queries, plus the template glue of its std::vector<LevelEntry> and
// std::sort. Names are invented from use.
// MS2-UNIT: ?\paybacktable.cpp
// MS2-RANGE: 0x14071af20-0x14071e2f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1PaybackTable@@UEAA@XZ 0x14071d5a0
// MS2-PIN: ??_GPaybackTable@@UEAAPEAXI@Z 0x14071d790
// MS2-PIN: ??_7PaybackTable@@6B?$TSingleton@VPaybackTable@@@@@ 0x142d820f0
// MS2-PIN: ??_7PaybackTable@@6B?$CValidData@VPaybackTable@@@@@ 0x142d82100
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/paybacktable.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include <algorithm>
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"

extern "C" double (__cdecl* __imp_floor)(double);            // the exe imports floor from the UCRT

class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pNode);                   // the element is enabled for this build
unsigned FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned nDefault);
__int64 GetServerTime();                                    // the server clock
__int64 MakeTime(int year, int month, int day, int hour, int minute, int second);
__int64 GetNextMonthStart(__int64 nTime);                   // midnight of the day
__int64 FUN_14086ba60(const __int64& nTime, int nDays);
int IsMonthChanged(__int64 nTime);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool PaybackTable::s_bInit;
#endif

static bool FUN_14071bc90(const PaybackTable::LevelEntry& lhs, const PaybackTable::LevelEntry& rhs);

// @0x14071af20
PaybackTable::LevelEntry::LevelEntry()
    : m_nLevel(0), m_nWeight(0)
{
}

// @0x14071af50
PaybackTable::PaybackTable()
    : m_nStart(0), m_nEnd(0), m_nTotalWeight(0), m_bLocale(false)
{
}

// @0x14071aff0
bool PaybackTable::Load()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x109))
    {
        SetInit(true);
        return true;
    }
    CString strPath = FUN_14071a5b0("Table", "PaybackTable.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    m_nTotalWeight = 0;
    m_levels.clear();
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("payback"); pNode != 0; pNode = pNode->FUN_140168650("payback"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        LevelEntry entry;
        entry.m_nLevel = FUN_140197390(pNode, "adventure_level", 0);
        entry.m_nWeight = FUN_140197390(pNode, "payback_percent", 0);
        if (entry.m_nLevel != 0)
        {
            m_levels.push_back(entry);
            m_nTotalWeight += entry.m_nWeight;
        }
    }
    std::sort(m_levels.begin(), m_levels.end(), FUN_14071bc90);
    m_nStart = 0;
    if (*FUN_1401d3200()->PaybackStartDate.Get() != 0)
    {
        int nYear = (int)((double)*FUN_1401d3200()->PaybackStartDate.Get() / 10000.0);
        int nMonth = *FUN_1401d3200()->PaybackStartDate.Get() / 100 % 100;
        int nDay = *FUN_1401d3200()->PaybackStartDate.Get() % 100;
        m_nStart = MakeTime(nYear, nMonth, nDay, 0, 0, 0);
    }
    m_nEnd = 0;
    if (*FUN_1401d3200()->PaybackEndDate.Get() != 0)
    {
        int nYear = (int)((double)*FUN_1401d3200()->PaybackEndDate.Get() / 10000.0);
        int nMonth = *FUN_1401d3200()->PaybackEndDate.Get() / 100 % 100;
        int nDay = *FUN_1401d3200()->PaybackEndDate.Get() % 100;
        m_nEnd = MakeTime(nYear, nMonth, nDay, 23, 59, 59);
    }
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d650())
    {
        if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036e510())
            m_bLocale = true;
    }
    SetInit(true);
    return true;
}

// @0x14071b4c0
std::vector<PaybackTable::LevelEntry>& PaybackTable::GetLevels(unsigned __int64 nContext)
{
    return m_levels;
}

// @0x14071b4e0
float PaybackTable::GetLevelPercent(const LevelEntry* pEntry, unsigned __int64 nContext)
{
    return (float)(pEntry->m_nWeight * 100) / (float)GetInstance()->GetTotalWeight(nContext);
}

// @0x14071b540
float PaybackTable::GetPercentUpTo(unsigned nLevel, unsigned __int64 nContext)
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x109))
        return 0.0f;
    float fPercent = 0.0f;
    const std::vector<LevelEntry>& levels = GetLevels(nContext);
    for (std::vector<LevelEntry>::const_iterator it = levels.begin(); it != levels.end(); it++)
    {
        if (it->m_nLevel > nLevel)
            break;
        fPercent += GetLevelPercent(&*it, nContext);
    }
    return fPercent;
}

// @0x14071b630
__int64 PaybackTable::GetMeratUpTo(unsigned nLevel, __int64 nAmount, unsigned __int64 nContext)
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x109))
        return 0;
    __int64 nMerat = 0;
    const std::vector<LevelEntry>& levels = GetLevels(nContext);
    for (std::vector<LevelEntry>::const_iterator it = levels.begin(); it != levels.end(); it++)
    {
        const LevelEntry* pEntry = &*it;
        if (pEntry->m_nLevel > nLevel)
            continue;
        nMerat += GetLevelMerat(pEntry, nAmount, nContext);
    }
    return nMerat;
}

// @0x14071b730
__int64 PaybackTable::GetMeratTotal(__int64 nAmount, unsigned __int64 nContext)
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x109))
        return 0;
    const std::vector<LevelEntry>& levels = GetLevels(nContext);
    if (levels.empty())
        return 0;
    return GetMeratUpTo(levels.back().m_nLevel, nAmount, nContext);
}

// @0x14071b7c0
bool PaybackTable::InPeriod(__int64 nTime)
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x109))
        return false;
    if (m_nStart == 0)
        return false;
    if (m_nEnd == 0)
        return false;
    bool bIn = m_nStart <= nTime && nTime < m_nEnd;
    return bIn;
}

// @0x14071b860
bool PaybackTable::IsPaybackDay(__int64 nTime)
{
    __int64 nNow = GetServerTime();
    if (!InMonthPeriod(nNow))
        return false;
    if (nTime == 0)
        return true;
    return IsMonthChanged(nTime) ? true : false;
}

// @0x14071b8d0
bool PaybackTable::InMonthPeriod(__int64 nTime)
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x109))
        return false;
    if (m_nStart == 0)
        return false;
    if (m_nEnd == 0)
        return false;
    CMsTime start(GetNextMonthStart(m_nStart));
    __int64 nEndDay = GetNextMonthStart(m_nEnd);
    CMsTime end(FUN_14086ba60(nEndDay, 0));
    bool bIn = start.Get() <= nTime && nTime < end.Get();
    return bIn;
}

// @0x14071b9c0
bool PaybackTable::IsResetWindow()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x109))
        return false;
    CMsTime now(GetServerTime());
    if (now.GetDay() != 1)
        return false;
    if (now.GetHour() != 0)
        return false;
    if (now.GetMinute() * 60 + now.GetSecond() > *FUN_1401d3200()->PaybackRewardMinutes.Get() * 60)
        return false;
    if (IsPaybackDay(now.Get()))
        return false;
    return true;
}

// @0x14071baa0
__int64 PaybackTable::GetStartTime()
{
    return m_nStart;
}

// @0x14071bac0
unsigned PaybackTable::GetTotalWeight(unsigned __int64 nContext)
{
    return m_nTotalWeight;
}

// @0x14071bae0
__int64 PaybackTable::GetLevelMerat(const LevelEntry* pEntry, __int64 nAmount, unsigned __int64 nContext)
{
    const std::vector<LevelEntry>& levels = GetLevels(nContext);
    if (levels.back().m_nLevel == pEntry->m_nLevel)
    {
        __int64 nMerat = nAmount;
        for (std::vector<LevelEntry>::const_iterator it = levels.begin(); it != levels.end(); it++)
        {
            if (levels.back().m_nLevel == it->m_nLevel)
                continue;
            nMerat -= GetWeightedMerat(&*it, nAmount, nContext);
        }
        return nMerat;
    }
    return GetWeightedMerat(pEntry, nAmount, nContext);
}

// @0x14071bc00
bool PaybackTable::IsLocaleEnabled()
{
    return m_bLocale;
}

// @0x14071bc20
__int64 PaybackTable::GetWeightedMerat(const LevelEntry* pEntry, __int64 nAmount, unsigned __int64 nContext)
{
    return (__int64)__imp_floor((double)(__int64)(nAmount * pEntry->m_nWeight) / (double)GetTotalWeight(nContext));
}

// @0x14071bc90
static bool FUN_14071bc90(const PaybackTable::LevelEntry& lhs, const PaybackTable::LevelEntry& rhs)
{
    return lhs.m_nLevel < rhs.m_nLevel;
}

// @0x14071e1d0
MS2_EMIT_CRT_MEMMOVE_S();
