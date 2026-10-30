// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMsTime out-of-line members (atltime.h-style time class with
// a server time zone). Queue name unit_1406c47a0; the CU is presumably commonfiles\mstime.cpp (the header is
// commonfiles\mstime.h per its assert string; the member order matches the declaration order). Its first two members
// (0x1406c4730 default ctor, 0x1406c4760 copy ctor) sit just below units.tsv's guessed boundary, so the range starts there.
// Layout evidence: src/ms2/placeholder/mstime.h.
// MS2-UNIT: unit_1406c47a0
// MS2-RANGE: 0x1406c4730-0x1406c53d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\mstime.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atltime.h>
#include <time.h>
#include "ms2/placeholder/mstime.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The zone statics are written by the exe (SetTimeZone from CNetworkService); the hook DLL binds them to the exe's
// copies (symbols-manual) instead of defining its own.
#ifndef MS2_HOOK_DLL
bool CMsTime::s_bTimeZoneSet;
int CMsTime::s_nZoneSeconds;
int CMsTime::s_nDstHours;
#endif

// @0x1406c4730
CMsTime::CMsTime()
{
    Init(0, false);
}

// @0x1406c4760
CMsTime::CMsTime(const CMsTime& other)
{
    Init(other.m_time, other.IsLocal());
}

// @0x1406c47a0
CMsTime::CMsTime(__time64_t t)
{
    Init(t, false);
}

// @0x1406c47d0
CMsTime::CMsTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec)
{
    if (nYear >= 1900 && nMonth >= 1 && nMonth <= 12 && nDay >= 1 && nDay <= 31 && nHour >= 0 && nHour <= 23 &&
        nMin >= 0 && nMin <= 59 && nSec >= 0 && nSec <= 59) {
        struct tm atm;
        atm.tm_sec = nSec;
        atm.tm_min = nMin;
        atm.tm_hour = nHour;
        atm.tm_mday = nDay;
        atm.tm_mon = nMonth - 1;
        atm.tm_year = nYear - 1900;
        atm.tm_isdst = 0;
        __time64_t t = MakeTime(&atm);
        Init(t, true);
    } else {
        Init(0, true);
    }
}

// @0x1406c4930
CMsTime& CMsTime::operator=(const CMsTime& other) throw()
{
    Init(other.m_time, other.IsLocal());
    return *this;
}

// @0x1406c4970
CMsTime& CMsTime::operator=(__time64_t t)
{
    Init(t, false);
    return *this;
}

// @0x1406c49a0
CMsTime& CMsTime::operator+=(ATL::CTimeSpan span)
{
    m_time += span.GetTimeSpan();
    return *this;
}
MS2_REPLACE_METHOD(0x1406C49A0, CMsTime, operator+=, 50, 0x500213F8);

// @0x1406c49e0
CMsTime& CMsTime::operator-=(ATL::CTimeSpan span)
{
    m_time -= span.GetTimeSpan();
    return *this;
}
MS2_REPLACE_METHOD(0x1406C49E0, CMsTime, operator-=, 56, 0x1BDF3309);

// @0x1406c4a20
ATL::CTimeSpan CMsTime::operator-(const CMsTime& time) const
{
    return ATL::CTimeSpan(Get() - time.Get());
}

// @0x1406c4a80
CMsTime CMsTime::operator-(ATL::CTimeSpan span) const
{
    return CMsTime(Get() - span.GetTimeSpan());
}

// @0x1406c4ae0
CMsTime CMsTime::operator+(ATL::CTimeSpan span) const
{
    return CMsTime(Get() + span.GetTimeSpan());
}
MS2_REPLACE_METHOD(0x1406C4AE0, CMsTime, operator+, 78, 0x65BACAFC);

// @0x1406c4b40
bool CMsTime::operator==(const CMsTime& time) const
{
    return GetTime() == time.GetTime();
}
MS2_REPLACE_METHOD(0x1406C4B40, CMsTime, operator==, 77, 0x94596DFA);

// @0x1406c4ba0
bool CMsTime::operator!=(const CMsTime& time) const
{
    return GetTime() != time.GetTime();
}
MS2_REPLACE_METHOD(0x1406C4BA0, CMsTime, operator!=, 77, 0x49856085);

// @0x1406c4c00
bool CMsTime::operator<(const CMsTime& time) const
{
    return GetTime() < time.GetTime();
}
MS2_REPLACE_METHOD(0x1406C4C00, CMsTime, operator<, 77, 0x8D68E044);

// @0x1406c4c60
bool CMsTime::operator>(const CMsTime& time) const
{
    return GetTime() > time.GetTime();
}
MS2_REPLACE_METHOD(0x1406C4C60, CMsTime, operator>, 77, 0xF48B429D);

// @0x1406c4cc0
bool CMsTime::operator<=(const CMsTime& time) const
{
    return GetTime() <= time.GetTime();
}
MS2_REPLACE_METHOD(0x1406C4CC0, CMsTime, operator<=, 77, 0x5F795A94);

// @0x1406c4d20
bool CMsTime::operator>=(const CMsTime& time) const
{
    return GetTime() >= time.GetTime();
}
MS2_REPLACE_METHOD(0x1406C4D20, CMsTime, operator>=, 77, 0x80431B9B);

// @0x1406c4d80
bool CMsTime::IsNull() const
{
    return GetTime() == 0;
}
MS2_REPLACE_METHOD(0x1406C4D80, CMsTime, IsNull, 52, 0xED6051DA);

// @0x1406c4dc0
int CMsTime::GetYear() const
{
    struct tm ttm;
    struct tm* ptm;

    ptm = GetLocalTm(&ttm);
    return ptm ? (ptm->tm_year) + 1900 : 0;
}
MS2_REPLACE_METHOD(0x1406C4DC0, CMsTime, GetYear, 101, 0x2FC4AD02);

// @0x1406c4e30
int CMsTime::GetMonth() const
{
    struct tm ttm;
    struct tm* ptm;

    ptm = GetLocalTm(&ttm);
    return ptm ? ptm->tm_mon + 1 : 0;
}
MS2_REPLACE_METHOD(0x1406C4E30, CMsTime, GetMonth, 98, 0xB5B453D1);

// @0x1406c4ea0
int CMsTime::GetDay() const
{
    struct tm ttm;
    struct tm* ptm;

    ptm = GetLocalTm(&ttm);
    return ptm ? ptm->tm_mday : 0;
}
MS2_REPLACE_METHOD(0x1406C4EA0, CMsTime, GetDay, 96, 0x50B67F0A);

// @0x1406c4f10
int CMsTime::GetHour() const
{
    struct tm ttm;
    struct tm* ptm;

    ptm = GetLocalTm(&ttm);
    return ptm ? ptm->tm_hour : -1;
}
MS2_REPLACE_METHOD(0x1406C4F10, CMsTime, GetHour, 96, 0x56C7268B);

// @0x1406c4f80
int CMsTime::GetMinute() const
{
    struct tm ttm;
    struct tm* ptm;

    ptm = GetLocalTm(&ttm);
    return ptm ? ptm->tm_min : -1;
}
MS2_REPLACE_METHOD(0x1406C4F80, CMsTime, GetMinute, 96, 0xEF387B6F);

// @0x1406c4ff0
int CMsTime::GetSecond() const
{
    struct tm ttm;
    struct tm* ptm;

    ptm = GetLocalTm(&ttm);
    return ptm ? ptm->tm_sec : -1;
}
MS2_REPLACE_METHOD(0x1406C4FF0, CMsTime, GetSecond, 95, 0x1861CBA2);

// @0x1406c5060
int CMsTime::GetDayOfWeek() const
{
    struct tm ttm;
    struct tm* ptm;

    ptm = GetLocalTm(&ttm);
    return ptm ? ptm->tm_wday + 1 : 0;
}
MS2_REPLACE_METHOD(0x1406C5060, CMsTime, GetDayOfWeek, 98, 0x5A938D13);

// @0x1406c50d0
struct tm* CMsTime::GetLocalTm(struct tm* ptm) const
{
    ATLENSURE(ptm != NULL);

    if (ptm != NULL) {
        struct tm ptmTemp;
        __time64_t t = Get() - CalcZoneOffset();
        errno_t err = _gmtime64_s(&ptmTemp, &t);

        if (err != 0) {
            return NULL;
        }

        *ptm = ptmTemp;
        return ptm;
    }

    return NULL;
}
MS2_REPLACE_METHOD(0x1406C50D0, CMsTime, GetLocalTm, 241, 0x62892560);

// @0x1406c51d0
__time64_t CMsTime::MakeTime(struct tm* ptm)
{
    return _mkgmtime64(ptm);
}
MS2_REPLACE_METHOD(0x1406C51D0, CMsTime, MakeTime, 30, 0x0B53230C);

// @0x1406c5200
bool CMsTime::IsTimeZoneSet()
{
    return s_bTimeZoneSet;
}

// @0x1406c5210
void CMsTime::SetTimeZone(int zoneSeconds, int dstHours)
{
    s_bTimeZoneSet = true;
    s_nZoneSeconds = zoneSeconds;
    s_nDstHours = dstHours;
}
MS2_REPLACE(0x1406C5210, CMsTime::SetTimeZone, 36, 0x74F0792D);

MS2_EMIT_CRT_MEMMOVE_S();
