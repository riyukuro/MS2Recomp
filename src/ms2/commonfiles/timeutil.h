// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). commonfiles\timeutil.cpp: stopwatches, server clock and calendar helpers.
// Class names CStopWatch / CStopWatchEx come from RTTI; every other name is invented (Unk_*, descriptive free functions).
#pragma once
#include <afx.h>
#include <atltime.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/os.h"

// Server clock object read by GetServerTime (0x141473640 returns now - m_base + m_offset): CMainSystem
// (placeholder/cmainsystem.h), viewed through these calls. Its singleton slot 0x143ab1fa8 is the one
// TSingleton<CMainSystem>::s_instance every CMainSystem user shares (a static of its own would be a second copy).
class CMainSystem;
class Unk_ServerClock {
public:
    __int64 FUN_141473640();
    __int64 FUN_1414732f0(int nMode);                               // 0x1414732f0 the clock in ms (mode: the actor's time mode)
    static Unk_ServerClock* GetInstance()                          // 0x14086d260
    { return reinterpret_cast<Unk_ServerClock*>(TSingleton<CMainSystem>::s_instance); }
};

// Callback object stored in CStopWatchEx (slot 0 is called after every message).
class Unk_StopWatchCallback { public: virtual void Invoke(); };

class CStopWatch {
public:
    CStopWatch();
    CStopWatch(const char* format, ...);
    virtual ~CStopWatch();
    virtual void vfunc_1(const char* format, ...);
    unsigned GetElapsedSeconds();
    int GetElapsedMs();
protected:
    MS2_LAYOUT_FRIEND;
    int m_start;
    CString m_name;
    int m_logOnExit;
};
MS2_CHECK_SIZE(CStopWatch,0x20);
MS2_CHECK_OFFSET(CStopWatch,m_start,8);
MS2_CHECK_OFFSET(CStopWatch,m_name,0x10);
MS2_CHECK_OFFSET(CStopWatch,m_logOnExit,0x18);

class CStopWatchEx : public CStopWatch {
public:
    CStopWatchEx();
    virtual ~CStopWatchEx();
    virtual void vfunc_1(const char* format, ...);
    CString GetMessageText();
    int GetStartTick();
    void SetCallback(Unk_StopWatchCallback* callback);
private:
    MS2_LAYOUT_FRIEND;
    CString m_message;
    CLockCriticalSection m_lock;
    Unk_StopWatchCallback* m_callback;
};
MS2_CHECK_SIZE(CStopWatchEx,0x60);
MS2_CHECK_OFFSET(CStopWatchEx,m_message,0x20);
MS2_CHECK_OFFSET(CStopWatchEx,m_lock,0x28);
MS2_CHECK_OFFSET(CStopWatchEx,m_callback,0x58);

// "HH:MM-HH:MM" window of the day (four ints: start hour, start minute, end hour, end minute).
struct Unk_TimeRange {
    Unk_TimeRange();
    int Parse(CString text);
    int IsSet();
    int ContainsServerNow();
    int Contains(__int64 time);
    int IsValid();
    CStringW ToString();
    int startHour, startMinute, endHour, endMinute;
};
MS2_CHECK_SIZE(Unk_TimeRange,16);

// Seconds since midnight (4 bytes).
struct Unk_DayTime {
    Unk_DayTime();
    Unk_DayTime(int hour,int minute,int second);
    Unk_DayTime(const CMsTime& time);   // sb2: CMsTime (calls 0x1406c4f10..), not ATL::CTime
    Unk_DayTime(__int64 time);
    Unk_DayTime(const CStringW& text);
    bool Set(int hour,int minute,int second);
    bool Parse(const CStringW& text);
    unsigned GetHour();
    unsigned GetMinute();
    unsigned GetSecond();
    void SetSeconds(unsigned seconds);
    unsigned GetSeconds();
    bool operator<(const Unk_DayTime& other) const;     // 0x14086a540
    bool operator>(const Unk_DayTime& other) const;     // 0x14086a580
    bool operator<=(const Unk_DayTime& other) const;    // 0x14086a5c0
    bool operator>=(const Unk_DayTime& other) const;    // 0x14086a600
    bool operator==(const Unk_DayTime& other) const;    // 0x14086a640
    bool operator!=(const Unk_DayTime& other) const;    // 0x14086a680
    unsigned m_seconds;
};
MS2_CHECK_SIZE(Unk_DayTime,4);

// Free functions (names invented).
__time64_t TimeFromTm(tm* time);
__int64 GetPastRecordedTime(int back);
void SyncServerTime(__int64 serverTime);
void SetServerTimeOffset(__int64 offset);
void AddServerTimeOffset(__int64 delta);
void RecordLocalTime();
void ResetTickBase();
int GetTicksSinceBase();
DWORD GetTickCountMs();
int TickDifference(int a, int b);
DWORD GetTickCountMs2();
__int64 GetServerTime();
int DaysToSeconds(int days);
int HoursToSeconds(int hours);
int MinutesToSeconds(int minutes);
int GetServerDayOfWeek();

// Calendar helpers on CMsTime / raw __time64_t values (names invented).
void TruncateToDay(CMsTime& time);
void TruncateToHour(CMsTime& time);
void AddDays(CMsTime& time, long days);
void AddHours(CMsTime& time, int hours);
void AddMinutes(CMsTime& time, int minutes);
void AddSeconds(CMsTime& time, int seconds);
CMsTime AddByUnit(int unit, const CMsTime& time, long amount);
__time64_t GetWeekdayStart(CMsTime& time, int weekday);
__int64 PositiveDifference(__int64 from, __int64 to);
bool IsEarlierDay(CMsTime& a, CMsTime& b, int baseHour);
bool IsEarlierHourlessDay(CMsTime& a, CMsTime& b);
bool IsFutureTime(__int64 time);
int IsNotRecentDayChange(__int64 time);
int IsMonthChanged(__int64 time);
CStringW FormatTimeSpan(ATL::CTimeSpan span, bool days, bool hours, bool minutes, bool seconds);
__time64_t NextWeekdayStart(int weekday, __int64 time);
__time64_t MakeTime(int year, int month, int day, int hour, int minute, int second);
__time64_t GetNextDayStart(__int64 time);
__time64_t GetNextMonthStart(__int64 time);
unsigned char IsLeapYear(int year);
int GetDaysInMonth(int year, int month);
int GetWeekOfMonth(int year, int month, int day);
__int64 GetWeekOfYear(int year, int month, int day);
__time64_t GetFirstSundayOnOrAfter(int year, int month, int day);
int GetLeapDaysBefore(CMsTime& time);
__int64 GetDaysBetween(__int64 a, __int64 b);
int GetDayNumber(__int64 time);
int GetDayNumberDifference(__int64 a, __int64 b);
__time64_t GetNthWeekStart(__int64* time, unsigned n);
__time64_t GetNthMonthStart(__int64* time, unsigned n);
CString FormatCompileDate(CString text);
int IsOlderThanDays(__int64 time, int days);
__int64 GetDaysBetweenDays(CMsTime& from, CMsTime& to);
unsigned MsToSeconds(unsigned ms);
unsigned MsToMinutes(unsigned ms);
int SecondsToMs(int seconds);
__int64 FloatSecondsToMs(float seconds);
__int64 DoubleSecondsToMs(double seconds);
unsigned SecondsToDays(int seconds);
__int64 DaysToSeconds64(int days);
