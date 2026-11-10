// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A profiling/interval logger: an object holding a lock,
// a label + message string, first/last millisecond ticks and a hit counter, whose log() refreshes the message from a
// printf-style format (times the interval between hits), appends a "[label_count:delta last/first]" diagnostic line
// to the log singleton, and notifies an optional callback.
// MS2-UNIT: unit_1402e12c0
// MS2-RANGE: 0x1402e12c0-0x1402e1b80 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <stdarg.h>
#include <string>

unsigned long GetTickCountMs2();   // C3: was FUN_140869420
class CLogString* GetLogString();   // C3: was FUN_140166440


// The interval logger.
class Unk_PerfLogCallback { public: virtual void vfunc_0(); };
class Unk_PerfLog {
public:
    CLockCriticalSection m_lock;   // +0x00
    CString m_strLabel;      // +0x30
    CString m_strMessage;    // +0x38
    unsigned m_nLastTick;    // +0x40
    unsigned m_nFirstTick;   // +0x44
    unsigned m_nCount;       // +0x48
    Unk_PerfLogCallback* m_pCallback;   // +0x50

    void LogInterval(const char* pszFormat, ...);
    unsigned GetFirstTick();
    CString FUN_1402e14e0();
    unsigned GetElapsedSeconds();
    void SetCallback(void* pCallback);
};
MS2_CHECK_OFFSET(Unk_PerfLog, m_strLabel, 0x30);
MS2_CHECK_OFFSET(Unk_PerfLog, m_strMessage, 0x38);
MS2_CHECK_OFFSET(Unk_PerfLog, m_nLastTick, 0x40);
MS2_CHECK_OFFSET(Unk_PerfLog, m_nFirstTick, 0x44);
MS2_CHECK_OFFSET(Unk_PerfLog, m_nCount, 0x48);
MS2_CHECK_OFFSET(Unk_PerfLog, m_pCallback, 0x50);

// The two tick deltas are unsigned long arguments: their fmt instances live in this range, ArgType<unsigned long> 0x1402e15d0,
// make_type<unsigned long> 0x1402e1a00, the wchar_t MakeValue(unsigned long) 0x1402e1a20 and the char MakeValue::type(unsigned long)
// 0x1402e1a50 (make_type always uses the char MakeValue). The Value entries are the wide instances, as this is a wide format call.

// @0x1402e1600 (the unit's five-argument log call: an FMT_VARIADIC wrapper over CLogString::LogInfo).
template <class A, class B, class C, class D, class E>
inline void Unk_PerfLogInfo(CLogString* log, unsigned __int64 a, unsigned __int64 c, int category, const wchar_t* format,
    const A& v0, const B& v1, const C& v2, const D& v3, const E& v4)
{
    const fmt::internal::ArgArray<5>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v0),
        fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v1), fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v2),
        fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v3), fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(v4)};
    log->LogInfo(a, c, category, format, fmt::ArgList(fmt::internal::make_type(v0, v1, v2, v3, v4), args));
}

// @0x1402e12c0
void Unk_PerfLog::LogInterval(const char* pszFormat, ...)
{
    bool bEmpty = m_strMessage.IsEmpty();
    unsigned nNow = GetTickCountMs2();
    if (m_nFirstTick == 0)
        m_nFirstTick = nNow;
    unsigned long nDeltaLast = nNow - m_nLastTick;
    unsigned long nDeltaFirst = nNow - m_nFirstTick;
    if (!bEmpty) {
        m_nCount++;
        Unk_PerfLogInfo(GetLogString(), 0, 0, 1, L"[{0}_{1}:{2} {3}/{4}]",
                        m_strLabel, m_nCount, m_strMessage, nDeltaLast, nDeltaFirst);
    }
    m_nLastTick = nNow;

    if (Unk_LockGuard guard = m_lock) {
    } else {
        va_list args;
        va_start(args, pszFormat);
        m_strMessage.FormatV(pszFormat, args);
        va_end(args);
    }

    if (m_pCallback != 0)
        m_pCallback->vfunc_0();
}

// @0x1402e14c0
unsigned Unk_PerfLog::GetFirstTick()
{
    return m_nFirstTick;
}

// @0x1402e14e0
CString Unk_PerfLog::FUN_1402e14e0()
{
    if (Unk_LockGuard guard = m_lock) {
     __assume(0);
 } else {
        return m_strMessage;
    }
}

// @0x1402e1570
unsigned Unk_PerfLog::GetElapsedSeconds()
{
    if (m_nLastTick < m_nFirstTick)
        return 0;
    return (unsigned)(int)(m_nLastTick - m_nFirstTick) / 1000;
}

// @0x1402e15b0
void Unk_PerfLog::SetCallback(void* pCallback)
{
    m_pCallback = (Unk_PerfLogCallback*)pCallback;
}

// @0x1402e1a60 - the CRT's bounds-checked memmove_s (UCRT static-inline copy, unreferenced in this TU).
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
