// CMsTime: the game's time class from commonfiles\mstime.h (class name invented; the header name comes from the
// assert __FILE__ L"e:\build\kr\22_04\ms2code\commonfiles\mstime.h" at 0x142d15980, used by Get() at line 125).
// A copy of ATL::CTime's source with a server time-zone flag, NOT derived from ATL::CTime (sb2, exe evidence):
//   - every ctor/assignment (0x1406c4730 / 4760 / 47a0 / 47d0 / 4930 / 4970) ends in Init 0x1406c5270, which stores
//     [this+0]=__time64_t and [this+8]=bool; none calls an ATL::CTime base ctor;
//   - GetYear..GetSecond / GetDayOfWeek (0x1406c4dc0..0x1406c5060) are atltime.h's bodies, but their GetLocalTm
//     (0x1406c50d0) runs _gmtime64_s on Get() - zone offset, and the 6-int ctor (0x1406c47d0) uses _mkgmtime64
//     (0x1406c51d0) and sets the flag; the comparisons (0x1406c4b40..0x1406c4d80) compare GetTime() 0x140282070;
//   - 16 bytes: m_time +0, m_bLocal +8 (Init, IsLocal 0x1406c52a0, GetTime).
// Out-of-line members live in commonfiles\mstime.cpp (exe 0x1406c4730-0x1406c53d0, our unit_1406c47a0 at
// src/ms2/commonfiles/mstime.cpp). Init/IsLocal are header inlines (COMDATs at the tail of that range); Get, GetTime and
// CalcZoneOffset are header inlines first instantiated by commonfiles\commonstruct.cpp (0x140281f20..0x1402820b6).
// The zone statics are 0x143ab05a8 (bool set), 0x143ab05ac (zone seconds), 0x143ab05b0 (DST hours), written by
// SetTimeZone 0x1406c5210. Member names other than the atltime.h ones are invented.
#pragma once
#include <afx.h>
#include <atltime.h>
#include "ms2/ms2layout.h"

// <assert.h> declares _wassert only without NDEBUG (same declaration as ms2recover.h).
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);
#define MS2_MSTIME_ASSERT(line, expr) \
    (void)((!!(expr)) || (_wassert(_CRT_WIDE(#expr), L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\mstime.h", line), 0))

class CMsTime {
public:
    CMsTime();                                                     // 0x1406c4730 (guilddef)
    CMsTime& operator=(const CMsTime&) throw();                     // 0x1406c4930 (nothrow: no EH state at its callers)
    CMsTime& operator=(__time64_t);                                 // 0x1406c4970
    CMsTime(__time64_t t);                                          // 0x1406c47a0
    CMsTime(int year,int month,int day,int hour,int minute,int second); // 0x1406c47d0
    CMsTime(const CMsTime&);                                        // 0x1406c4760
    CMsTime& operator+=(ATL::CTimeSpan span);                       // 0x1406c49a0
    CMsTime& operator-=(ATL::CTimeSpan span);                       // 0x1406c49e0
    ATL::CTimeSpan operator-(const CMsTime&) const;                 // 0x1406c4a20
    CMsTime operator-(ATL::CTimeSpan span) const;                   // 0x1406c4a80
    CMsTime operator+(ATL::CTimeSpan span) const;                   // 0x1406c4ae0
    bool operator==(const CMsTime&) const;                          // 0x1406c4b40
    bool operator!=(const CMsTime&) const;                          // 0x1406c4ba0
    bool operator<(const CMsTime&) const;                           // 0x1406c4c00
    bool operator>(const CMsTime&) const;                           // 0x1406c4c60
    bool operator<=(const CMsTime&) const;                          // 0x1406c4cc0
    bool operator>=(const CMsTime&) const;                          // 0x1406c4d20
    bool IsNull() const;                                            // 0x1406c4d80 (GetTime() == 0)
    int GetYear() const;                                            // 0x1406c4dc0
    int GetMonth() const;                                           // 0x1406c4e30
    int GetDay() const;                                             // 0x1406c4ea0
    int GetHour() const;                                            // 0x1406c4f10
    int GetMinute() const;                                          // 0x1406c4f80
    int GetSecond() const;                                          // 0x1406c4ff0
    int GetDayOfWeek() const;                                       // 0x1406c5060
    struct tm* GetLocalTm(struct tm* ptm) const;                    // 0x1406c50d0
    __time64_t MakeTime(struct tm* ptm);                            // 0x1406c51d0 (_mkgmtime64)
    static bool IsTimeZoneSet();                                    // 0x1406c5200
    static void SetTimeZone(int zoneSeconds, int dstHours);         // 0x1406c5210

    // @0x1406c5270
    void Init(__time64_t t, bool bLocal) { m_time = t; m_bLocal = bLocal; }
    // @0x1406c52a0
    bool IsLocal() const { return m_bLocal; }
    // @0x140281f20
    __time64_t CalcZoneOffset() const { return s_nZoneSeconds - s_nDstHours * 60 * 60; }
    // @0x140282020
    __time64_t Get() const {
        if (m_time != 0 && !s_bTimeZoneSet) {
            MS2_MSTIME_ASSERT(125, FALSE);
        }
        return GetTime();
    }
    // @0x140282070
    __time64_t GetTime() const {
        if (m_time == 0) return 0;
        if (m_bLocal == true) return CalcZoneOffset() + m_time;
        return m_time;
    }

    __time64_t m_time;   // +0x00
    bool m_bLocal;       // +0x08

    static bool s_bTimeZoneSet;    // 0x143ab05a8
    static int s_nZoneSeconds;     // 0x143ab05ac
    static int s_nDstHours;        // 0x143ab05b0
};
MS2_CHECK_SIZE(CMsTime,16);
MS2_CHECK_OFFSET(CMsTime, m_bLocal, 8);
