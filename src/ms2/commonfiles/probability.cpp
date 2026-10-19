// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The probability disclosure log: Probability::LogContext
// collects one TrialResult per random pick (the weight and total weight it was rolled with, as a percentage text)
// for item option random / fusion, special hair, gacha and socket rolls. Logging is compiled out: IsLogEnabled()
// returns false, so every Append function bails out right after its function-local static name.
// Name assumed (the exe has no __FILE__ for this unit); the class names are RTTI.
// MS2-UNIT: ?\probability.cpp
// MS2-RANGE: 0x14073b630-0x140743430 .text$mn
// MS2-RANGE: 0x142c9bba0-0x142c9bcc0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\probability.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/probability.h"
#include "ms2/commonfiles/itemoptiondata.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CFeatureManager* FUN_140166410();
void* FUN_140166440();                                                          // the log
void FUN_140353fc0(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const int& arg);
CString FUN_140188f50(const char* psz, int nCodePage);                         // CString from a C string

namespace Probability
{
typedef LogContext::TrialResult TrialResult;

bool IsLogEnabled();
CString StatName(ItemOptionValueRandom* pValue);
CString GetProbabilityText(int nWeight, int nTotal, double dScale);
CString PercentText(double d);
}

using namespace Probability;

// @0x14073b630
LogContext::LogContext()
{
    Clear();
}

// @0x14073b6a0
LogContext::LogContext(const LogContext& o)
{
    Copy(o);
}

// @0x14073b720
LogContext::LogContext(LogContext&& o)
{
    m_strName = std::move(o.m_strName);
    m_vTrials = std::move(o.m_vTrials);
}

// @0x14073b7d0
LogContext& LogContext::operator=(const LogContext& o)
{
    if (this != &o)
    {
        Clear();
        Copy(o);
    }
    return *this;
}

// @0x14073b820
void LogContext::Clear()
{
    m_strName.Empty();
    m_vTrials.clear();
}

// @0x14073b860
void LogContext::Copy(const LogContext& o)
{
    m_strName = o.m_strName;
    m_vTrials = o.m_vTrials;
}

// @0x14073b8b0
CString& LogContext::GetName()
{
    return m_strName;
}

// @0x14073b8d0
void LogContext::SetName(CString str)
{
    m_strName = std::move(str);
}

// @0x14073b920
std::vector<MS2Ptr<TrialResult> >& LogContext::GetTrials()
{
    return m_vTrials;
}

// @0x14073b940
void LogContext::AddTrial(MS2Ptr<TrialResult> spTrial)
{
    m_vTrials.emplace_back(spTrial);
}

// @0x14073b990
void LogContext::AddTrials(const std::vector<MS2Ptr<TrialResult> >& v)
{
    m_vTrials.insert(m_vTrials.end(), v.begin(), v.end());
}

// @0x14073e680
bool Probability::IsLogEnabled()
{
    bool bEnabled = false;
    return bEnabled;
}

// @0x14073e6a0
bool FUN_14073e6a0()
{
    if (IsLogEnabled() == true)
        return FUN_140166410()->FUN_14036d570(0x115);
    return false;
}

// @0x14073e6e0
bool FUN_14073e6e0()
{
    if (IsLogEnabled() == true)
        return FUN_140166410()->FUN_14036d570(0x114);
    return false;
}

// @0x14073e720
bool FUN_14073e720()
{
    return FUN_140166410()->FUN_14036d570(0x116);
}

// The random option picks of one reroll: each picked value is popped from a copy of the picker so the next trial is
// logged with the remaining total weight; the armor / special option probability is scaled by its rate.
// @0x14073e750
bool AppendItemOptionRandomOptionLog(unsigned nProbVer, int nCode, const Unk_ItemOptionValuePicker& picker,
                                     const std::vector<ItemOptionValueRandom*>& vPicked,
                                     const std::vector<MS2Ptr<ItemOptionValueRandom> >& vLocked,
                                     std::pair<ItemOptionValueRandom*, double>* pArmor,
                                     std::pair<ItemOptionValueRandom*, double>* pSpecial, Unk_ProbabilityLog* pLogs)
{
    static CString s_strName("ItemOptionRandom_Option");
    if (!IsLogEnabled())
        return false;
    if (nProbVer == 0)
        return false;
    CString strVer = Unk_SocketFormat("v{0}", nProbVer);
    if (vPicked.empty() == true)
        return false;
    if (!picker.IsValid())
        return false;
    MS2Ptr<LogContext> spContext(new LogContext());
    unsigned char nLocked = (vLocked.empty() == true) ? 0 : 1;
    Unk_ItemOptionValuePicker kPicker(picker);
    for (int i = 0; i < (int)vPicked.size(); i++)
    {
        unsigned nTotal = kPicker.GetTotal();
        ItemOptionValueRandom* pValue = vPicked[i];
        Unk_ItemOptionValuePicker::Entry kEntry;
        if (!kPicker.PopFirstItemData(pValue, kEntry))
        {
            FUN_140353fc0(FUN_140166440(), 1, 0x13b, L"AppendLogContext, PopFirstItemData is null, pickedVec index: {0}", i);
            continue;
        }
        unsigned nWeight = kEntry.weight;
        double dScale = 1.0;
        if (pValue == pArmor->first)
            dScale = pArmor->second;
        else if (pValue == pSpecial->first)
            dScale = pSpecial->second;
        CString strProbability = GetProbabilityText(nWeight, nTotal, dScale);
        CString strKey = Unk_SocketFormat("{0}_{1}_tlc_{2}_tpc_{3}", s_strName, nCode, nLocked, i + 1);
        CString strVersionKey = Unk_SocketFormat("{0}_{1}_{2}_tlc_{3}_tpc_{4}", s_strName, strVer, nCode, nLocked, i + 1);
        MS2Ptr<TrialResult> spTrial(new TrialResult());
        spTrial->m_strKey = strKey;
        spTrial->m_strVersionKey = strVersionKey;
        spTrial->m_strResult = StatName(kEntry.value);
        spTrial->m_strProbability = strProbability;
        spTrial->m_nWeight = nWeight;
        spTrial->m_nTotalWeight = nTotal;
        spTrial->m_nTrial = (unsigned char)i + 1;
        spTrial->m_nLockCount = (unsigned char)vLocked.size();
        spContext->AddTrial(spTrial);
    }
    spContext->SetName(s_strName);
    pLogs->emplace_back(spContext);
    return true;
}

// @0x14073ede0
bool AppendItemOptionRandomStatLog(unsigned nProbVer, unsigned nStatId, int nValue, Unk_ProbabilityLog* pLogs)
{
    static CString s_strName("ItemOptionRandom_Stat");
    if (!IsLogEnabled())
        return false;
    if (nProbVer == 0)
        return false;
    MS2Ptr<LogContext> spContext(new LogContext());
    CString strVer = Unk_SocketFormat("v{0}", nProbVer);
    CString strKey = Unk_SocketFormat("{0}_s_{1}", s_strName, nStatId);
    CString strVersionKey = Unk_SocketFormat("{0}_{1}_s_{2}", s_strName, strVer, nStatId);
    CString strValue = Unk_SocketFormat("{0}", nValue);
    MS2Ptr<TrialResult> spTrial(new TrialResult());
    spTrial->m_strKey = strKey;
    spTrial->m_strVersionKey = strVersionKey;
    spTrial->m_strResult = strValue;
    spContext->SetName(s_strName);
    spContext->AddTrial(spTrial);
    pLogs->emplace_back(spContext);
    return true;
}

// Two logs: the fused option, then the stat it rolled.
// @0x14073f150
bool AppendItemFusionLog(unsigned nProbVer, int nCode, int nOption, CString strOption, int nOptionTotal,
                         int nOptionWeight, int nStat, int nStatTotal, int nStatWeight, Unk_ProbabilityLog* pLogs)
{
    if (!IsLogEnabled())
        return false;
    if (nProbVer == 0)
        return false;
    CString strVer = Unk_SocketFormat("v{0}", nProbVer);
    {
        static CString s_strName("ItemFusion_Option");
        CString strKey = Unk_SocketFormat("{0}_{1}", s_strName, nCode);
        CString strVersionKey = Unk_SocketFormat("{0}_{1}_{2}_p_{3}", s_strName, strVer, nCode, nOption);
        CString strProbability = GetProbabilityText(nOptionWeight, nOptionTotal, 1.0);
        MS2Ptr<LogContext> spContext(new LogContext());
        MS2Ptr<TrialResult> spTrial(new TrialResult());
        spTrial->m_strKey = strKey;
        spTrial->m_strVersionKey = strVersionKey;
        spTrial->m_strResult = std::move(strOption);
        spTrial->m_strProbability = strProbability;
        spTrial->m_nWeight = nOptionWeight;
        spTrial->m_nTotalWeight = nOptionTotal;
        spTrial->m_nTrial = 1;
        spTrial->m_nLockCount = 0;
        spContext->AddTrial(spTrial);
        spContext->SetName(s_strName);
        pLogs->emplace_back(spContext);
    }
    {
        static CString s_strName("ItemFusion_Stat");
        CString strKey = Unk_SocketFormat("{0}_{1}", s_strName, nCode);
        CString strVersionKey = Unk_SocketFormat("{0}_{1}_{2}_p_{3}_o_{4}", s_strName, strVer, nCode, nOption, strOption);
        CString strProbability = GetProbabilityText(nStatWeight, nStatTotal, 1.0);
        CString strValue = Unk_SocketFormat("{0}", nStat);
        MS2Ptr<LogContext> spContext(new LogContext());
        MS2Ptr<TrialResult> spTrial(new TrialResult());
        spTrial->m_strKey = strKey;
        spTrial->m_strVersionKey = strVersionKey;
        spTrial->m_strResult = strValue;
        spTrial->m_strProbability = strProbability;
        spTrial->m_nWeight = nStatWeight;
        spTrial->m_nTotalWeight = nStatTotal;
        spTrial->m_nTrial = 1;
        spTrial->m_nLockCount = 0;
        spContext->AddTrial(spTrial);
        spContext->SetName(s_strName);
        pLogs->emplace_back(spContext);
    }
    return true;
}

// The context is the caller's (a fresh one: an already named context is not logged into).
// @0x14073f980
bool AppendSpecialHairLog(unsigned nProbVer, int nResult, int nGroup, const CString& strType, int nWeight, int nTotal,
                          MS2Ptr<LogContext> spContext)
{
    static CString s_strName("SpecialHair");
    if (!IsLogEnabled())
        return false;
    if (spContext == 0)
        return false;
    if (nProbVer == 0)
        return false;
    CString strVer = Unk_SocketFormat("v{0}", nProbVer);
    if (!spContext->GetName().IsEmpty())
        return false;
    CString strKey = Unk_SocketFormat("{0}_{1}", s_strName, strType);
    CString strVersionKey = Unk_SocketFormat("{0}_{1}_{2}_g_{3}", s_strName, strType, strVer, nGroup);
    CString strProbability = GetProbabilityText(nWeight, nTotal, 1.0);
    CString strValue = Unk_SocketFormat("{0}", nResult);
    MS2Ptr<TrialResult> spTrial(new TrialResult());
    spTrial->m_strKey = strKey;
    spTrial->m_strVersionKey = strVersionKey;
    spTrial->m_strResult = strValue;
    spTrial->m_strProbability = strProbability;
    spTrial->m_nWeight = nWeight;
    spTrial->m_nTotalWeight = nTotal;
    spTrial->m_nTrial = 1;
    spTrial->m_nLockCount = 0;
    spContext->AddTrial(spTrial);
    spContext->SetName(s_strName);
    return true;
}

// @0x14073fdc0
bool AppendGachaLog(unsigned nProbVer, int nGroup, int nGachaId, int nDrawGroup, int nDrawGroupId, int nResult,
                    int nWeight, int nTotal, MS2Ptr<LogContext> spContext)
{
    static CString s_strName("Gacha");
    if (!IsLogEnabled())
        return false;
    if (spContext == 0)
        return false;
    if (nProbVer == 0)
        return false;
    CString strVer = Unk_SocketFormat("v{0}", nProbVer);
    if (!spContext->GetName().IsEmpty())
        return false;
    CString strKey = Unk_SocketFormat("{0}_{1}", s_strName, nGachaId);
    CString strVersionKey = Unk_SocketFormat("{0}_{1}_{2}_{3}_dg_{4}_g_{5}", s_strName, strVer, nGachaId, nDrawGroup,
                                             nDrawGroupId, nGroup);
    CString strProbability = GetProbabilityText(nWeight, nTotal, 1.0);
    CString strValue = Unk_SocketFormat("{0}", nResult);
    MS2Ptr<TrialResult> spTrial(new TrialResult());
    spTrial->m_strKey = strKey;
    spTrial->m_strVersionKey = strVersionKey;
    spTrial->m_strResult = strValue;
    spTrial->m_strProbability = strProbability;
    spTrial->m_nWeight = nWeight;
    spTrial->m_nTotalWeight = nTotal;
    spTrial->m_nTrial = 1;
    spTrial->m_nLockCount = 0;
    spContext->AddTrial(spTrial);
    spContext->SetName(s_strName);
    return true;
}

// Only the checks were kept: nothing is logged.
// @0x140740230
bool AppendItemSocketLog(unsigned nProbVer, bool bUnlock, int nSocket, int nResult, MS2Ptr<LogContext> spContext)
{
    static CString s_strName("ItemSocket");
    if (!IsLogEnabled())
        return false;
    if (spContext == 0)
        return false;
    if (nProbVer == 0)
        return false;
    CString strVer = Unk_SocketFormat("v{0}", nProbVer);
    if (!spContext->GetName().IsEmpty())
        return false;
    return true;
}

// @0x1407403b0
CString Ordinal(unsigned n)
{
    if (n == 0)
        return "";
    else if (n == 1)
        return "1st";
    else if (n == 2)
        return "2nd";
    else if (n == 3)
        return "3rd";
    return Unk_SocketFormat("{0}th", n);
}

// @0x1407404c0
CString Probability::StatName(ItemOptionValueRandom* pValue)
{
    return FUN_140188f50(pValue->FUN_1405d26c0().GetString(), 0);
}

// @0x140740540
CString Probability::GetProbabilityText(int nWeight, int nTotal, double dScale)
{
    static CString s_strZero("0.0");
    if (nTotal == 0 || nWeight == 0)
        return s_strZero;
    double d = (double)nWeight / (double)nTotal * dScale;
    return PercentText(d);
}

// @0x140740650
CString Probability::PercentText(double d)
{
    static CString s_strZero("0.0");
    if (d == 0.0)
        return s_strZero;
    double dPercent = d * 100.0;
    return Unk_SocketFormat("{0:.4f}", dPercent);
}

// Unk_ItemOptionPicker members used by the log (itemoptiondata.h).
template <class T>
unsigned Unk_ItemOptionPicker<T>::GetTotal()
{
    return m_total;
}

template <class T>
bool Unk_ItemOptionPicker<T>::PopFirstItemData(T value, Entry& out)
{
    for (typename std::map<unsigned, Entry>::iterator it = m_entries.begin(); it != m_entries.end(); ++it)
    {
        Entry* pEntry = &it->second;
        if (pEntry->value == value)
        {
            out = *pEntry;
            m_total -= pEntry->weight;
            m_entries.erase(it);
            return true;
        }
    }
    return false;
}

MS2_REPLACE_METHOD(0x14073B7D0, LogContext, operator=, 61, 0x4AC9A0B8);
MS2_REPLACE_METHOD(0x14073B820, LogContext, Clear, 49, 0x903081BD);
MS2_REPLACE_METHOD(0x14073B860, LogContext, Copy, 72, 0x0640366B);
MS2_REPLACE_METHOD(0x14073B8B0, LogContext, GetName, 15, 0x271C8F51);
MS2_REPLACE_METHOD(0x14073B8D0, LogContext, SetName, 68, 0xBB9312C2);
MS2_REPLACE_METHOD(0x14073B920, LogContext, GetTrials, 15, 0x5731F599);
MS2_REPLACE_METHOD(0x14073B940, LogContext, AddTrial, 61, 0x73B30BFC);
MS2_REPLACE_METHOD(0x14073B990, LogContext, AddTrials, 124, 0xDEC349D1);
MS2_REPLACE(0x14073E680, Probability::IsLogEnabled, 17, 0x2562E347);
MS2_REPLACE(0x14073E6A0, FUN_14073e6a0, 44, 0x88E08F2C);
MS2_REPLACE(0x14073E6E0, FUN_14073e6e0, 44, 0x98CC32EB);
MS2_REPLACE(0x14073E720, FUN_14073e720, 27, 0x9BB14BB9);
MS2_REPLACE(0x1407403B0, Ordinal, 242, 0x032CF23D);
MS2_REPLACE(0x1407404C0, Probability::StatName, 120, 0x7FF1EECC);
