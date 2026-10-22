// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). commonfiles\timer.cpp: Timer (millisecond poll timer on the
// service manager's clock 0xe001001b) and TimeRange (start/end CMsTime pair).
// MS2-UNIT: ?\timer.cpp
// MS2-RANGE: 0x1408686b0-0x1408691c0 .text$mn
// MS2-PIN: ??_GTimer@@UEAAPEAXI@Z 0x140868c90
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\timer.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include "timer.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include <efd/ServiceManager.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit callees.
efd::ServiceManager* FUN_1413f9850();                                       // the game's service manager
int FUN_140873600(Unk_140165cf0* pNode, const char* pszName, CMsTime& out);  // TinyXML time attribute

// @0x1408690a0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x1408686b0
Timer::Timer()
{
    m_nPeriod = 0;
    m_nPauseTime = 0;
    m_fLastRatio = 0.0f;
    m_pClock = 0;
}

// @0x140868720
Timer::~Timer()
{
}

// @0x140868750
void Timer::FUN_140868750(unsigned int ms)
{
    m_nPeriod = ms;
    m_nPauseTime = 0;
    m_fLastRatio = 0.0f;
    m_nStart = (int)FUN_1408688e0();
    m_nEnd = m_nStart + ms;
}

// @0x1408687c0
void Timer::FUN_1408687c0()
{
    FUN_140868750(0x3fffffff);
}

// @0x1408687f0
void Timer::FUN_1408687f0()
{
    m_nPeriod = 0;
    m_fLastRatio = 0.0f;
}

// @0x140868820
void Timer::FUN_140868820()
{
    m_nStart = (int)FUN_1408688e0() - m_nPeriod;
}

// @0x140868850
void Timer::FUN_140868850()
{
    m_nPauseTime = (int)FUN_1408688e0();
}

// @0x140868880
void Timer::FUN_140868880()
{
    int d = (int)FUN_1408688e0() - m_nPauseTime;
    m_nStart += d;
    m_nEnd += d;
    m_nPauseTime = 0;
}

// @0x1408688e0
__int64 Timer::FUN_1408688e0()
{
    if (m_pClock == 0)
        m_pClock = FUN_1413f9850()->GetClock(0xe001001b);
    return (__int64)(m_pClock->GetCurrentTime() * 1000.0);
}

// @0x140868940
float Timer::FUN_140868940()
{
    if (FUN_140868c00() != 0)
        return 1.0f;
    return (float)FUN_140868a70() / (float)FUN_140868af0();
}

// @0x1408689a0
float Timer::FUN_1408689a0()
{
    float r;
    if (FUN_140868c00() != 0)
        return 1.0f;
    r = (float)FUN_140868a70() / (float)FUN_140868af0();
    r = r + r * 2.0f;
    if (1.0f < r)
        r = 1.0f;
    return r;
}

// @0x140868a50
int Timer::GetStart() const
{
    return m_nStart;
}

// @0x140868a70
int Timer::FUN_140868a70()
{
    if (m_nPeriod == 0)
        return 0;
    return (int)FUN_1408688e0() - m_nStart;
}

// @0x140868ab0
int Timer::FUN_140868ab0()
{
    if (m_nPeriod == 0)
        return 0;
    return m_nEnd - (int)FUN_1408688e0();
}

// @0x140868af0
int Timer::FUN_140868af0() const
{
    if (m_nPeriod == 0)
        return 1;
    return m_nPeriod;
}

// @0x140868b20
float Timer::FUN_140868b20()
{
    float cur = FUN_140868940();
    float d = cur - m_fLastRatio;
    m_fLastRatio += d;
    return d;
}

// @0x140868b80
int Timer::FUN_140868b80() const
{
    if (m_nPeriod == 0)
        return 0;
    return 1;
}

// @0x140868ba0
int Timer::FUN_140868ba0()
{
    if (m_nPeriod == 0)
        return false;
    return FUN_140868a70() < FUN_140868af0();
}

// @0x140868c00
int Timer::FUN_140868c00()
{
    if (m_nPeriod == 0)
        return false;
    return FUN_140868a70() >= FUN_140868af0();
}

// @0x140868c60
int Timer::HasPauseTime() const
{
    return m_nPauseTime != 0;
}

// @0x140868cd0
TimeRange::TimeRange()
{
}

// @0x140868d10
TimeRange::TimeRange(const CMsTime& start, const CMsTime& end)
    : m_start(start), m_end(end)
{
}

// @0x140868d60
void TimeRange::FUN_140868d60(Unk_140165cf0* pNode)
{
    FUN_140873600(pNode, "startTime", m_start);
    FUN_140873600(pNode, "endTime", m_end);
}

// @0x140868db0
void TimeRange::FUN_140868db0(COutputStream& out) const
{
    if (m_start.Get() == 0 || m_end.Get() == 0)
    {
        out.WriteUInt8(0);
    }
    else
    {
        out.WriteUInt8(1);
        out.WriteInt64(m_start.Get());
        out.WriteInt64(m_end.Get());
    }
}

// @0x140868e70
void TimeRange::FUN_140868e70(CInPacket& in)
{
    int present = in.ReadUInt8();
    if (present == 1)
    {
        m_start = in.ReadInt64();
        m_end = in.ReadInt64();
    }
}

// @0x140868f20
CMsTime& TimeRange::FUN_140868f20()
{
    return m_start;
}

// @0x140868f40
CMsTime& TimeRange::FUN_140868f40()
{
    return m_end;
}

// @0x140868f60
bool TimeRange::FUN_140868f60(const CMsTime& t) const
{
    if (m_start.Get() <= t.Get())
    {
        if (t.Get() < m_end.Get())
            return true;
    }
    return false;
}

// @0x140868fd0
bool TimeRange::FUN_140868fd0(const CMsTime& t, ATL::CTimeSpan before, ATL::CTimeSpan after) const
{
    if ((m_start + before) <= t)
    {
        if (t < (m_end + after))
            return true;
    }
    return false;
}

// @0x140869060
bool TimeRange::FUN_140869060() const
{
    if (m_start.Get() > m_end.Get())
        return false;
    return true;
}
