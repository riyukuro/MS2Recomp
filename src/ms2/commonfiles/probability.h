// probability.h - Probability::LogContext (RTTI .?AVLogContext@Probability@@) and its nested TrialResult (RTTI
// .?AVTrialResult@LogContext@Probability@@): the probability disclosure log of one random roll (item option
// random / fusion, special hair, gacha, socket). NOT an original header; recovered from ?\probability.cpp
// (0x14073b630-0x140743430): operator new(0x38) / new(0x48) in the logging functions, the implicit TrialResult ctor
// 0x140743110 (NSDMI zeroing) and the LogContext ctors 0x14073b630..0x14073b720. Member names invented.
#pragma once

#include <vector>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/ms2layout.h"

namespace Probability
{
class LogContext : public CPtred
{
public:
    // One logged trial: the log keys, the result text and the weight / total weight it was rolled with.
    class TrialResult : public CPtred
    {
    public:
        CString m_strKey;                       // +0x18 "<name>_<code>_..."
        CString m_strVersionKey;                // +0x20 "<name>_v<ver>_<code>_..."
        CString m_strResult;                    // +0x28 the picked stat / item
        CString m_strProbability;               // +0x30 the percentage text ("0.0" for none)
        int m_nWeight = 0;                      // +0x38
        int m_nTotalWeight = 0;                 // +0x3c
        unsigned char m_nTrial = 0;             // +0x40 1-based trial number
        unsigned char m_nLockCount = 0;         // +0x41 locked option count
        int m_n44 = 0;                          // +0x44 never set
    };

    LogContext();                               // 0x14073b630
    LogContext(const LogContext& o);            // 0x14073b6a0
    LogContext(LogContext&& o);                 // 0x14073b720
    LogContext& operator=(const LogContext& o); // 0x14073b7d0
    void Clear();                               // 0x14073b820
    void Copy(const LogContext& o);             // 0x14073b860
    CString& GetName();                         // 0x14073b8b0
    void SetName(CString str);                  // 0x14073b8d0
    std::vector<MS2Ptr<TrialResult> >& GetTrials();             // 0x14073b920
    void AddTrial(MS2Ptr<TrialResult> spTrial);                 // 0x14073b940
    void AddTrials(const std::vector<MS2Ptr<TrialResult> >& v); // 0x14073b990

    CString m_strName;                          // +0x18 the log name ("ItemOptionRandom_Option", ...)
    std::vector<MS2Ptr<TrialResult> > m_vTrials;    // +0x20
};
}
MS2_CHECK_SIZE(Probability::LogContext::TrialResult, 0x48);
MS2_CHECK_OFFSET(Probability::LogContext::TrialResult, m_nWeight, 0x38);
MS2_CHECK_OFFSET(Probability::LogContext::TrialResult, m_n44, 0x44);
MS2_CHECK_SIZE(Probability::LogContext, 0x38);
MS2_CHECK_OFFSET(Probability::LogContext, m_vTrials, 0x20);
