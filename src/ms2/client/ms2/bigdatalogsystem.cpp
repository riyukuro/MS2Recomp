// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBigDataLogSystem: see bigdatalogsystem.h. w276.
// Calculate / the iteration idioms follow the third-party v2525 snapshot (work/xr2), checked against the decompile.
// MS2-UNIT: client\ms2\bigdatalogsystem.cpp
// MS2-RANGE: 0x140a1f250-0x140a20460 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\bigdatalogsystem.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <cmath>
#include <mmsystem.h>
#include "bigdatalogsystem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#pragma comment(lib, "winmm.lib")

// cl's `for each` (the exe's iteration shape); clang-cl (the hook DLL build) has no such statement: a range-for there.
#ifdef __clang__
#define BD_FOR_EACH(decl, container) for (decl : container)
#else
#define BD_FOR_EACH(decl, container) for each (decl in container)
#endif

// ---- exe callees ----
class Unk_BdFrame { public: float FUN_141473210(); };                   // the frame timer: frame rate
class Unk_BdMemory { public: unsigned __int64 FUN_14161bdc0(); };       // the memory monitor: bytes in use
class Unk_BdNetwork { public: unsigned FUN_141538f60(); };              // the network service: latency
unsigned FUN_140869420();                                               // millisecond clock
Unk_BdFrame* FUN_14086d260();
Unk_BdMemory* FUN_1409f7c90();
Unk_BdNetwork* FUN_140714f90();
float FUN_14096b1c0(float f);                                           // sqrtf
void FUN_140710590(COutPacket& packet);                                 // send the packet

// @0x140a1f250
void CBigDataLogSystem::CSampleList::Clear()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_values.clear();
    }
}
MS2_REPLACE_METHOD(0x140A1F250, CBigDataLogSystem::CSampleList, Clear, 86, 0x8F3BB139);

// @0x140a1f2b0
void CBigDataLogSystem::CSampleList::Add(float fValue)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_values.push_back(fValue);
    }
}
MS2_REPLACE_METHOD(0x140A1F2B0, CBigDataLogSystem::CSampleList, Add, 97, 0x1DA89906);

// @0x140a1f320
// MS2-FUNCTIONAL: the exe's for-each temporaries and iterator copies differ (35 bytes)
bool CBigDataLogSystem::CSampleList::Calculate(float* pAverage, float* pMin, float* pMax, int* pCount, float* pDeviation)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (m_values.empty())
        {
            *pMax = 0.0f;
            *pMin = 0.0f;
            *pAverage = 0.0f;
            *pCount = 0;
            *pDeviation = 0.0f;
            return false;
        }
        __int64 nTotal = 0;
        *pCount = (int)m_values.size();
        *pMin = m_values[0];
        *pMax = m_values[0];
        BD_FOR_EACH(__int64 nValue, m_values)
        {
            nTotal += nValue;
            if ((float)nValue < *pMin)
                *pMin = (float)nValue;
            if ((float)nValue > *pMax)
                *pMax = (float)nValue;
        }
        *pAverage = (float)nTotal / (float)*pCount;
        float fVariance = 0.0f;
        BD_FOR_EACH(const __int64& nValue, m_values)
            fVariance += ((float)nValue - *pAverage) * ((float)nValue - *pAverage);
        *pDeviation = FUN_14096b1c0(fVariance);
        m_values.clear();
    }
    return true;
}
MS2_REPLACE_METHOD(0x140A1F320, CBigDataLogSystem::CSampleList, Calculate, 872, 0xAF3A3CE2);

// @0x140a1f690
CBigDataLogSystem::CBigDataLogSystem()
{
    m_dwLastSendTick = 0;
    m_bEnable = false;
}

// @0x140a1f720
CBigDataLogSystem::~CBigDataLogSystem()
{
}

// @0x140a1f780
void CBigDataLogSystem::Reset()
{
    for (int i = 0; i < SAMPLE_MAX; i = i + 1)
    {
        CSampleList* pList = &m_samples[i];
        pList->Clear();
    }
    m_dwLastSendTick = FUN_140869420();
}
MS2_REPLACE_METHOD(0x140A1F780, CBigDataLogSystem, Reset, 93, 0x1A0C692B);

// @0x140a1f7f0
void CBigDataLogSystem::SetEnable(bool bEnable)
{
    m_bEnable = bEnable;
    Reset();
}
MS2_REPLACE_METHOD(0x140A1F7F0, CBigDataLogSystem, SetEnable, 44, 0xA9B79C68);

// @0x140a1f830
void CBigDataLogSystem::AddSample(int nType, __int64 nValue)
{
    if (nType < 0 || nType >= SAMPLE_MAX)
        return;
    if (!m_bEnable)
        return;
    m_samples[nType].Add((float)nValue);
}
MS2_REPLACE_METHOD(0x140A1F830, CBigDataLogSystem, AddSample, 94, 0x7A9D9A53);

// @0x140a1f8a0
void CBigDataLogSystem::Update()
{
    unsigned nTick = FUN_140869420();
    if (nTick > m_dwLastSendTick + 300000)
        SendStatistics();
    float fFrameRate = FUN_14086d260()->FUN_141473210();
    AddSample(SAMPLE_FPS, (__int64)fFrameRate);
    unsigned __int64 nMemory = FUN_1409f7c90()->FUN_14161bdc0();
    AddSample(SAMPLE_MEMORY, (__int64)(float)nMemory);
    unsigned nLatency = FUN_140714f90()->FUN_141538f60();
    AddSample(SAMPLE_LATENCY, nLatency);
}
MS2_REPLACE_METHOD(0x140A1F8A0, CBigDataLogSystem, Update, 199, 0x15B837EF);

// @0x140a1f970
void CBigDataLogSystem::SendLog(const CString& strKey, const CString& strValue)
{
    COutPacket packet(static_cast<int>(SendOp::LogSend), 0);
    packet.vfunc_o10_1(0);
    packet.vfunc_o10_1(0);
    packet.vfunc_o10_6(strKey);
    packet.vfunc_o10_6(strValue);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140A1F970, CBigDataLogSystem, SendLog, 130, 0x1648C8A5);

// @0x140a1fa00
// MS2-FUNCTIONAL: the name string scope / temporaries differ (7 bytes)
void CBigDataLogSystem::SendStatistics()
{
    COutPacket packet(static_cast<int>(SendOp::LogSend), 0);
    packet.vfunc_o10_1(0);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_1(3);
    for (int i = 0; i < SAMPLE_MAX; i = i + 1)
    {
        float fMax;
        float fMin;
        int nCount;
        float fDeviation;
        float fAverage;
        CSampleList* pList = &m_samples[i];
        pList->Calculate(&fAverage, &fMin, &fMax, &nCount, &fDeviation);
        {
            const char* pszName = GetSampleName(i);
            CString strName(pszName);
            packet.vfunc_o10_7(strName);
        }
        packet.vfunc_o10_5(fAverage);
        packet.vfunc_o10_5(fDeviation);
        packet.vfunc_o10_3(nCount);
        packet.vfunc_o10_5(fMin);
        packet.vfunc_o10_5(fMax);
    }
    FUN_140710590(packet);
    m_dwLastSendTick = timeGetTime();
}
MS2_REPLACE_METHOD(0x140A1FA00, CBigDataLogSystem, SendStatistics, 364, 0xAEA94F79);

// @0x140a1fb80
const char* CBigDataLogSystem::GetSampleName(int nType)
{
    switch (nType)
    {
    case 0:
        return "fps";
    case 1:
        return "mem";
    case 2:
        return "lat";
    default:
        MS2_ASSERT_AT(0x9e, FALSE);
        return "";
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
