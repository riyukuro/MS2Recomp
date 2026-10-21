// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Stopwatches, server clock and calendar helpers.
// MS2-UNIT: commonfiles\timeutil.cpp
// MS2-RANGE: 0x1408691c0-0x14086d350 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\timeutil.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "timeutil.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <atlcoll.h>
#include <algorithm>
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Logger singleton: Log(category, level, format, args...) forwards to 0x1406530d0 with a packed fmt::ArgList.
class Unk_TimeLogger {
public:
    void Log(int category, int level, const wchar_t* format, const fmt::ArgList& args);   // 0x1406530d0
#define MS2_LOG_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline void Log(int category, int level, const wchar_t* format, FMT_GEN(n, FMT_MAKE_ARG)) \
    { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, FMT_MAKE_REF_wchar_t)}; \
        Log(category, level, format, fmt::ArgList(fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
    MS2_LOG_WRAP(2)
    MS2_LOG_WRAP(3)
};
Unk_TimeLogger* FUN_140166440();

// Unrecovered helpers.
// CAtlArray<CString> stand-in: the exe instantiates its own copies of this array's ctor/dtor/GetCount/operator[]
// (0x140163230 / 0x1401641d0 / 0x1401662c0 / 0x140164930), distinct from the CAtlArray<CString> COMDATs of other units.
class Unk_TimeStrList {
public:
    Unk_TimeStrList(); ~Unk_TimeStrList();
    size_t FUN_1401662c0() const;
    CString& FUN_140164930(size_t index);
    void* m_data; size_t m_count; size_t m_alloc; int m_pad_18;
};
MS2_CHECK_SIZE(Unk_TimeStrList,0x20);
void FUN_14015f050(CString& text, Unk_TimeStrList& out, const char* delimiter);
void FUN_140177de0(CString& text, ATL::CAtlArray<int>& out, const char* delimiter);
void FUN_1401d9a30(const CStringW& text, ATL::CAtlArray<int>& out, const wchar_t* delimiter);
CStringW FormatStringId(int id, const fmt::ArgList& args);   // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

// Statics (0x143ab1f40..0x143ab1fa8).
__int64 g_timeOffset;
int g_timeHistoryCount;
__int64 g_timeHistory[10];
DWORD g_tickBase;
Unk_ServerClock* Unk_ServerClock::s_instance;

static const int kDaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};   // 0x142d9b8f8

// @0x1408691c0
__time64_t TimeFromTm(tm* time) { return _mktime64(time); }
MS2_REPLACE(0x1408691C0, TimeFromTm, 25, 0x12A8ED52);
// @0x140869200
__int64 GetPastRecordedTime(int back) {
    if(back > 10) { MS2_ASSERT_AT(28, FALSE); back = 10; }
    if(g_timeHistoryCount < back) return 0;
    int slot = (g_timeHistoryCount - back) % 10;
    return g_timeHistory[slot];
}
// @0x140869280
void SyncServerTime(__int64 serverTime) {
    __time64_t now;
    _time64(&now);
    g_timeOffset = serverTime - now;
    RecordLocalTime();
}
// @0x1408692c0
void SetServerTimeOffset(__int64 offset) { g_timeOffset = offset; RecordLocalTime(); }
// @0x1408692f0
void AddServerTimeOffset(__int64 delta) { g_timeOffset = g_timeOffset + delta; RecordLocalTime(); }
// @0x140869330
void RecordLocalTime() {
    __time64_t now;
    _time64(&now);
    int slot = g_timeHistoryCount % 10;
    g_timeHistoryCount = g_timeHistoryCount + 1;
    g_timeHistory[slot] = now;
}
// @0x140869390
void ResetTickBase() { g_tickBase = timeGetTime(); }
// @0x1408693b0
int GetTicksSinceBase() { return TickDifference(timeGetTime(), g_tickBase) + 1; }
// @0x1408693e0
DWORD GetTickCountMs() { return timeGetTime(); }
// @0x140869400
int TickDifference(int a, int b) { return a - b; }
// @0x140869420
DWORD GetTickCountMs2() { return GetTickCountMs(); }
// @0x140869440
__int64 GetServerTime() {
    if(Unk_ServerClock::GetInstance() == 0) return 0;
    else return Unk_ServerClock::GetInstance()->FUN_141473640();
}
// @0x140869470
int DaysToSeconds(int days) { return days * 86400; }
// @0x140869490
int HoursToSeconds(int hours) { return hours * 3600; }
// @0x1408694b0
int MinutesToSeconds(int minutes) { return minutes * 60; }
// @0x1408694c0
int GetServerDayOfWeek() { CMsTime now(GetServerTime()); return now.GetDayOfWeek(); }

// @0x1408694f0
CStopWatch::CStopWatch() {
    m_start = GetTickCountMs2();
    m_logOnExit = 0;
}
// @0x140869550
CStopWatch::CStopWatch(const char* format, ...) {
    va_list args;
    va_start(args, format);
    m_name.FormatV(format, args);
    va_end(args);
    m_start = GetTickCountMs2();
    m_logOnExit = 1;
}
// @0x1408695f0
CStopWatch::~CStopWatch() {
    if(m_logOnExit != 0) {
        const char* name = m_name;
        DWORD elapsed = GetTickCountMs2() - m_start;
        FUN_140166440()->Log(12, 19, L"{0} {1}", elapsed, name);
    }
}
// @0x1408696a0
void CStopWatch::vfunc_1(const char* format, ...) {
    CString message;
    va_list args;
    va_start(args, format);
    message.FormatV(format, args);
    va_end(args);
    const char* text = message;
    const char* name = m_name;
    DWORD elapsed = GetTickCountMs2() - m_start;
    FUN_140166440()->Log(12, 19, L"{0} {1} {2}", elapsed, name, text);
}
// @0x140869790
unsigned CStopWatch::GetElapsedSeconds() { return (unsigned)(GetTickCountMs2() - m_start) / 1000; }
// @0x1408697c0
int CStopWatch::GetElapsedMs() { return GetTickCountMs2() - m_start; }

// @0x1408697f0
CStopWatchEx::CStopWatchEx() { m_callback = 0; }
// @0x140869860
CStopWatchEx::~CStopWatchEx() { m_callback = 0; }
// @0x1408698c0
void CStopWatchEx::vfunc_1(const char* format, ...) {
    if(Unk_LockGuard guard = m_lock) { __assume(0); } else {
        va_list args;
        va_start(args, format);
        m_message.FormatV(format, args);
        va_end(args);
    }
    DWORD elapsed = GetTickCountMs2() - m_start;
    FUN_140166440()->Log(12, 19, L"{0} {1} {2}", elapsed, m_name, m_message);
    if(m_callback != 0) m_callback->Invoke();
}
// @0x140869a00
CString CStopWatchEx::GetMessageText() {
    { if(Unk_LockGuard guard = m_lock) { __assume(0); } else { return m_message; } }
}
// @0x140869a90
int CStopWatchEx::GetStartTick() { return m_start; }
// @0x140869ab0
void CStopWatchEx::SetCallback(Unk_StopWatchCallback* callback) { m_callback = callback; }

// @0x140869ad0
Unk_TimeRange::Unk_TimeRange() { startHour = 0; startMinute = 0; endHour = 0; endMinute = 0; }
// @0x140869b60
int Unk_TimeRange::Parse(CString text) {
    Unk_TimeStrList halves;
    FUN_14015f050(text, halves, "-");
    if(halves.FUN_1401662c0() != 2) return 0;
    ATL::CAtlArray<int> start;
    ATL::CAtlArray<int> end;
    FUN_140177de0(halves.FUN_140164930(0), start, ":");
    FUN_140177de0(halves.FUN_140164930(1), end, ":");
    if(start.GetCount() != 2 || end.GetCount() != 2) return 0;
    startHour = start[0];
    startMinute = start[1];
    endHour = end[0];
    endMinute = end[1];
    return 1;
}
// @0x140869d50
int Unk_TimeRange::IsSet() {
    int result;
    if(startHour == 0 && startMinute == 0 && endHour == 0 && endMinute == 0) result = 0;
    else result = 1;
    return result;
}
// @0x140869db0
int Unk_TimeRange::ContainsServerNow() { return Contains(GetServerTime()); }
// @0x140869de0
int Unk_TimeRange::Contains(__int64 time) {
    CMsTime now(time);
    CMsTime zero(0);
    if(now != zero) {
        CMsTime start(now.GetYear(), now.GetMonth(), now.GetDay(), startHour, startMinute, 0);
        CMsTime end(now.GetYear(), now.GetMonth(), now.GetDay(), endHour, endMinute, 0);
        if(startHour > endHour) end += ATL::CTimeSpan(1, 0, 0, 0);
        if(now < start) {
            start -= ATL::CTimeSpan(1, 0, 0, 0);
            end -= ATL::CTimeSpan(1, 0, 0, 0);
        }
        if(start <= now && now < end) return 1;
    }
    return 0;
}
// @0x14086a000
int Unk_TimeRange::IsValid() {
    if(startHour > 23) return 0;
    if(endHour > 23) return 0;
    if(startMinute > 59) return 0;
    if(endMinute > 59) return 0;
    return 1;
}
// @0x14086a050
CStringW Unk_TimeRange::ToString() { return StringFormat(L"{0}:{1} ~ {2}:{3}", startHour, startMinute, endHour, endMinute); }

// @0x14086a0c0
Unk_DayTime::Unk_DayTime() { m_seconds = 0; }
// @0x14086a0e0
Unk_DayTime::Unk_DayTime(int hour, int minute, int second) { m_seconds = 0; Set(hour, minute, second); }
// @0x14086a130
Unk_DayTime::Unk_DayTime(const CMsTime& time) { m_seconds = 0; Set(time.GetHour(), time.GetMinute(), time.GetSecond()); }
// @0x14086a1a0
Unk_DayTime::Unk_DayTime(__int64 time) {
    m_seconds = 0;
    CMsTime value(time);
    Set(value.GetHour(), value.GetMinute(), value.GetSecond());
}
// @0x14086a220
Unk_DayTime::Unk_DayTime(const CStringW& text) { m_seconds = 0; Parse(text); }
// @0x14086a260
bool Unk_DayTime::Set(int hour, int minute, int second) {
    if(hour < 0 || hour >= 24) { MS2_ASSERT_AT(407, FALSE); return false; }
    if(minute < 0 || minute >= 60) { MS2_ASSERT_AT(412, FALSE); return false; }
    if(second < 0 || second >= 60) { MS2_ASSERT_AT(417, FALSE); return false; }
    m_seconds = (hour * 3600) + (second + minute * 60);
    return true;
}
// @0x14086a350
bool Unk_DayTime::Parse(const CStringW& text) {
    ATL::CAtlArray<int> parts;
    FUN_1401d9a30(text, parts, L":");
    if(parts.IsEmpty()) return false;
    int hour = parts.GetCount() >= 1 ? parts[0] : 0;
    int minute = parts.GetCount() >= 2 ? parts[1] : 0;
    int second = parts.GetCount() >= 3 ? parts[2] : 0;
    return Set(hour, minute, second);
}
// @0x14086a490
unsigned Unk_DayTime::GetHour() { return m_seconds / 3600; }
// @0x14086a4b0
unsigned Unk_DayTime::GetMinute() { return (m_seconds % 3600) / 60; }
// @0x14086a4e0
unsigned Unk_DayTime::GetSecond() { return m_seconds % 60; }
// @0x14086a500
void Unk_DayTime::SetSeconds(unsigned seconds) { m_seconds = seconds; }
// @0x14086a520
unsigned Unk_DayTime::GetSeconds() { return m_seconds; }

// @0x14086a540
bool Unk_DayTime::operator<(const Unk_DayTime& other) const { return m_seconds < other.m_seconds; }
// @0x14086a580
bool Unk_DayTime::operator>(const Unk_DayTime& other) const { return m_seconds > other.m_seconds; }
// @0x14086a5c0
bool Unk_DayTime::operator<=(const Unk_DayTime& other) const { return m_seconds <= other.m_seconds; }
// @0x14086a600
bool Unk_DayTime::operator>=(const Unk_DayTime& other) const { return m_seconds >= other.m_seconds; }
// @0x14086a640
bool Unk_DayTime::operator==(const Unk_DayTime& other) const { return m_seconds == other.m_seconds; }
// @0x14086a680
bool Unk_DayTime::operator!=(const Unk_DayTime& other) const { return m_seconds != other.m_seconds; }

// @0x14086a6c0
void TruncateToDay(CMsTime& time) {
    if(time.Get() == 0) return;
    time -= ATL::CTimeSpan(0, time.GetHour(), time.GetMinute(), time.GetSecond());
}
// @0x14086a740
void TruncateToHour(CMsTime& time) {
    if(time.Get() == 0) return;
    time -= ATL::CTimeSpan(0, 0, time.GetMinute(), time.GetSecond());
}
// @0x14086a7e0
void AddDays(CMsTime& time, long days) { time += ATL::CTimeSpan(days, 0, 0, 0); }
// @0x14086a830
void AddHours(CMsTime& time, int hours) { time += ATL::CTimeSpan(0, hours, 0, 0); }
// @0x14086a880
void AddMinutes(CMsTime& time, int minutes) { time += ATL::CTimeSpan(0, 0, minutes, 0); }
// @0x14086a8d0
void AddSeconds(CMsTime& time, int seconds) { time += ATL::CTimeSpan(0, 0, 0, seconds); }
// @0x14086a910
CMsTime AddByUnit(int unit, const CMsTime& time, long amount) {
    switch(unit) {
    case 0: return time + ATL::CTimeSpan(amount, 0, 0, 0);
    case 1: return time + ATL::CTimeSpan(0, amount, 0, 0);
    case 2: return time + ATL::CTimeSpan(0, 0, amount, 0);
    case 3: return time + ATL::CTimeSpan(0, 0, 0, amount);
    default: MS2_ASSERT_AT(557, FALSE); return time;
    }
}
// @0x14086aa90
__time64_t GetWeekdayStart(CMsTime& time, int weekday) {
    int dayOfWeek = time.GetDayOfWeek();
    if(dayOfWeek == 0 || weekday == 0) return 0;
    CMsTime copy(time);
    int current = dayOfWeek - 1;
    int target = weekday - 1;
    if(current >= target) target = target + 7;
    AddDays(copy, target - current);
    TruncateToDay(copy);
    return copy.Get();
}
// @0x14086ab30
__int64 PositiveDifference(__int64 from, __int64 to) {
    if(to < from) return 0;
    return to - from;
}
// @0x14086ab70
bool IsEarlierDay(CMsTime& a, CMsTime& b, int baseHour) {
    MS2_ASSERT_AT(589, baseHour >= 0 && baseHour < 24);
    if(a > b) return false;
    if(baseHour != 0) { AddHours(a, -baseHour); AddHours(b, -baseHour); }
    TruncateToDay(a);
    TruncateToDay(b);
    return a < b;
}
// @0x14086ac20
bool IsEarlierHourlessDay(CMsTime& a, CMsTime& b) {
    if(a > b) return false;
    TruncateToHour(a);
    TruncateToHour(b);
    return a < b;
}
// @0x14086ac80
bool IsFutureTime(__int64 time) {
    __int64 now = GetServerTime();
    __int64 diff = time - now;
    ATL::CTimeSpan span(diff);
    if(span.GetTotalSeconds() <= 0) return false;
    return true;
}
// @0x14086ace0
int IsNotRecentDayChange(__int64 time) {
    if(time != 0) {
        __int64 now = GetServerTime();
        __int64 diff = now - time;
        if(diff <= 0) return 0;
        if(diff <= 86400) {
            CMsTime a(time);
            CMsTime b(now);
            int dayA = a.GetYear() * 10000 + a.GetMonth() * 100 + a.GetDay();
            int dayB = b.GetYear() * 10000 + b.GetMonth() * 100 + b.GetDay();
            if(dayA == 0 || dayB == 0) return 0;
            if(dayA == dayB) return 0;
        }
    }
    return 1;
}
// @0x14086ae10
int IsMonthChanged(__int64 time) {
    CMsTime a(time);
    CMsTime b(GetServerTime());
    int monthA = a.GetYear() * 100 + a.GetMonth();
    int monthB = b.GetYear() * 100 + b.GetMonth();
    if(monthA == 0 || monthB == 0) return 0;
    if(monthA == monthB) return 0;
    return 1;
}
// @0x14086aec0
CStringW FormatTimeSpan(ATL::CTimeSpan span, bool days, bool hours, bool minutes, bool seconds) {
    CStringW result;
    if(days) {
        if(span.GetDays() > 0) {
            __int64 value = span.GetDays();
            result = FormatStringId(2426, value);
        }
    }
    if(hours) {
        if(span.GetHours() > 0) {
            if(!result.IsEmpty()) result += L" ";
            long value = span.GetHours();
            result += FormatStringId(2429, value);
        }
    }
    if(minutes) {
        if(span.GetMinutes() > 0) {
            if(!result.IsEmpty()) result += L" ";
            long value = span.GetMinutes();
            result += FormatStringId(2428, value);
        }
    }
    if(seconds) {
        if(span.GetSeconds() > 0) {
            if(!result.IsEmpty()) result += L" ";
            long value = span.GetSeconds();
            result += FormatStringId(2427, value);
        }
    }
    return result;
}
// @0x14086b190
__time64_t NextWeekdayStart(int weekday, __int64 time) {
    CMsTime t(time);
    CMsTime start(t.GetYear(), t.GetMonth(), t.GetDay(), 0, 0, 0);
    int dayOfWeek = start.GetDayOfWeek();
    long delta = 0;
    if(dayOfWeek < weekday) delta = weekday - dayOfWeek;
    else delta = 7 - (dayOfWeek - weekday);
    start += ATL::CTimeSpan(delta, 0, 0, 0);
    return start.Get();
}
// @0x14086b2a0
__time64_t MakeTime(int year, int month, int day, int hour, int minute, int second) {
    tm t;
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = minute;
    t.tm_sec = second;
    return TimeFromTm(&t);
}
// @0x14086b330
__time64_t GetNextDayStart(__int64 time) {
    CMsTime t(time);
    TruncateToDay(t);
    AddDays(t, 1);
    return t.Get();
}
// @0x14086b380
__time64_t GetNextMonthStart(__int64 time) {
    CMsTime t(time);
    int year = t.GetYear();
    int month = t.GetMonth();
    month = month + 1;
    if(month > 12) { month = month - 12; year = year + 1; }
    CMsTime start(year, month, 1, 0, 0, 0);
    return start.Get();
}
// @0x14086b430
unsigned char IsLeapYear(int year) {
    int result;
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) result = 1;
    else result = 0;
    return result;
}
// @0x14086b490
int GetDaysInMonth(int year, int month) {
    int days = 30;
    if(month == 4 || month == 6 || month == 9 || month == 11) days = 30;
    else if(month == 2) { if(IsLeapYear(year)) days = 29; else days = 28; }
    else days = 31;
    return days;
}
// @0x14086b510
int GetWeekOfMonth(int year, int month, int day) {
    CMsTime first(year, month, 1, 0, 0, 0);
    int dayOfWeek = first.GetDayOfWeek();
    return (day - 2 + dayOfWeek) / 7 + 1;
}
// @0x14086b590
__int64 GetWeekOfYear(int year, int month, int day) {
    CMsTime first(year, 1, 1, 0, 0, 0);
    CMsTime date(year, month, day, 0, 0, 0);
    ATL::CTimeSpan span = date - first;
    int offset = 0;
    int dayOfWeek = first.GetDayOfWeek();
    switch(dayOfWeek) {
    case 1: offset = 5; break;
    default: offset = dayOfWeek - 3; break;
    }
    return (span.GetDays() + 1 + offset) / 7 + 1;
}
// @0x14086b6a0
__time64_t GetFirstSundayOnOrAfter(int year, int month, int day) {
    CMsTime t(year, month, day, 0, 0, 0);
    int dayOfWeek = t.GetDayOfWeek();
    if(dayOfWeek != 1) { int days = 8 - dayOfWeek; t += ATL::CTimeSpan(days, 0, 0, 0); }
    return t.Get();
}
// @0x14086b750
int GetLeapDaysBefore(CMsTime& time) {
    int year = time.GetYear();
    if(time.GetMonth() <= 2) year = year - 1;
    return year / 4 - year / 100 + year / 400;
}
// @0x14086b7d0
__int64 GetDaysBetween(__int64 a, __int64 b) {
    if(a > b) std::swap(a, b);
    CMsTime from(a);
    CMsTime to(b);
    ATL::CTimeSpan span = to - from;
    return span.GetDays();
}
// @0x14086b840
int GetDayNumber(__int64 time) {
    CMsTime t(time);
    int days = t.GetYear() * 365 + t.GetDay();
    int month = t.GetMonth();
    for(int i = 0; i < month - 1; i++) days = days + kDaysInMonth[i];
    days = days + GetLeapDaysBefore(t);
    return days;
}
// @0x14086b900
int GetDayNumberDifference(__int64 a, __int64 b) {
    int first = GetDayNumber(a);
    int second = GetDayNumber(b);
    return second - first;
}
// @0x14086b950
__time64_t GetNthWeekStart(__int64* time, unsigned n) {
    CMsTime t(*time);
    __int64 sunday = GetFirstSundayOnOrAfter(t.GetYear(), t.GetMonth(), t.GetDay());
    sunday = sunday - 1;
    CMsTime start(sunday);
    start += ATL::CTimeSpan(1, 0, 0, 0);
    if(n > 1) { long weeks = (n - 1) * 7; start += ATL::CTimeSpan(weeks, 0, 0, 0); }
    return start.Get();
}
// @0x14086ba60
__time64_t GetNthMonthStart(__int64* time, unsigned n) {
    __int64 result = GetNextMonthStart(*time);
    if(n > 1) { for(unsigned i = 1; i < n; i++) result = GetNextMonthStart(result); }
    result = result - 1;
    CMsTime t(result);
    return t.Get();
}
// @0x14086baf0
CString FormatCompileDate(CString text) {
    CString monthNames("JanFebMarAprMayJunJulAugSepOctNovDec");
    int pos = 0;
    CString parts[3];
    for(int i = 0; i < 3; i++) parts[i] = text.Tokenize(" ", pos);
    int month = monthNames.Find(parts[0], 0) / 3 + 1;
    int day = atoi(parts[1]);
    int year = atoi(parts[2]);
    return StringFormat("{0}{1:02d}{2:02d}", year, month, day);
}
// @0x14086bcf0
int IsOlderThanDays(__int64 time, int days) {
    __int64 now = GetServerTime();
    if(time + days * 86400 < now) return 1;
    return 0;
}
// @0x14086bd40
__int64 GetDaysBetweenDays(CMsTime& from, CMsTime& to) {
    TruncateToDay(to);
    TruncateToDay(from);
    ATL::CTimeSpan span = to - from;
    return span.GetDays();
}
// @0x14086bd90
unsigned MsToSeconds(unsigned ms) { return ms / 1000; }
// @0x14086bdb0
unsigned MsToMinutes(unsigned ms) { return ms / 60000; }
// @0x14086be10
int SecondsToMs(int seconds) { return seconds * 1000; }
// @0x14086be30
__int64 FloatSecondsToMs(float seconds) { return (__int64)(seconds * 1000.0f); }
// @0x14086be50
__int64 DoubleSecondsToMs(double seconds) { return (__int64)(seconds * 1000.0); }
// @0x14086be70
unsigned SecondsToDays(int seconds) { return seconds / 86400; }
// @0x14086be90
__int64 DaysToSeconds64(int days) { return (__int64)days * 60 * 60 * 24; }
