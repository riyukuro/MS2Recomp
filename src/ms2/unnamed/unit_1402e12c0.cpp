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
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <stdarg.h>
#include <string>

typedef __int64 i64;
typedef unsigned __int64 u64;

unsigned FUN_140869420();   // client millisecond clock
void* FUN_140166440();      // the CLogString singleton


// fmt slot helpers (16-byte argument record + 8-byte bound slot)
struct Unk_LogArg { i64 m_w0, m_w1; };
MS2_CHECK_SIZE(Unk_LogArg, 0x10);
Unk_LogArg FUN_140163740(const CString& str);      // boxes a string argument
Unk_LogArg FUN_140163790(int nValue);              // boxes an int argument
u64* FUN_140163e80(u64* pSlot);                    // empty argument slot
u64* FUN_1401cee00(u64* pSlot, const void* pValue); // slot bound to a string
u64* FUN_14015e5d0(u64* pSlot, const void* pValue); // slot bound to an int
u64 FUN_14016d660(u64 a, u64 b, u64 c, u64 d);      // joins four slots
u64 FUN_140163e50(void* pOut, u64 kJoined, Unk_LogArg* pFirst);
void FUN_140653690(i64 pLog, i64 a, i64 c, int nCategory, const wchar_t* pszFormat, u64 kArgs);

// The interval logger.
class Unk_PerfLogCallback { public: virtual void vfunc_0(); };
class Unk_PerfLog {
public:
    CLockCriticalSection m_lock;   // +0x00
    CString m_strLabel;      // +0x30
    CString m_strMessage;    // +0x38
    unsigned m_nLastTick;    // +0x40
    unsigned m_nFirstTick;   // +0x44
    int m_nCount;            // +0x48
    Unk_PerfLogCallback* m_pCallback;   // +0x50

    void FUN_1402e12c0(const char* pszFormat, ...);
    unsigned FUN_1402e14c0();
    CString FUN_1402e14e0();
    unsigned FUN_1402e1570();
    void FUN_1402e15b0(void* pCallback);
};
MS2_CHECK_OFFSET(Unk_PerfLog, m_strLabel, 0x30);
MS2_CHECK_OFFSET(Unk_PerfLog, m_strMessage, 0x38);
MS2_CHECK_OFFSET(Unk_PerfLog, m_nLastTick, 0x40);
MS2_CHECK_OFFSET(Unk_PerfLog, m_nFirstTick, 0x44);
MS2_CHECK_OFFSET(Unk_PerfLog, m_nCount, 0x48);
MS2_CHECK_OFFSET(Unk_PerfLog, m_pCallback, 0x50);

u64 FUN_1402e1a50(int nValue);

// fmt::internal::MakeValue<unsigned long> boxed-argument ctor (the 8-byte branch is unreachable on LLP64).
struct Unk_LogArgValue : Unk_LogArg {
    Unk_LogArgValue(unsigned nValue);
};
MS2_CHECK_SIZE(Unk_LogArgValue, 0x10);

// @0x1402e1a20
Unk_LogArgValue::Unk_LogArgValue(unsigned nValue)
{
    if (sizeof(long) == sizeof(int))
        *(int*)&m_w0 = nValue;
    else
        m_w0 = (unsigned long long)nValue;
}

// @0x1402e1a00
u64 FUN_1402e1a00(const int* pValue)
{
    return FUN_1402e1a50(*pValue);
}

// @0x1402e1a50
u64 FUN_1402e1a50(int)
{
    return 2;
}

// @0x1402e15d0 - slot bound to an int argument
u64* FUN_1402e15d0(u64* pSlot, const int* pValue)
{
    *pSlot = FUN_1402e1a00(pValue);
    return pSlot;
}

// @0x1402e1600
// MS2-FUNCTIONAL: fmt argument-packing template glue; the exe's argument slot temporaries are laid out differently.
void FUN_1402e1600(i64 pLog, i64 a, i64 c, int nCategory, const wchar_t* pszFormat,
                   const CString* pStr0, const int* pInt1, const CString* pStr2,
                   const int* pInt3, const int* pInt4)
{
    Unk_LogArg kArg0 = FUN_140163740(*pStr0);
    Unk_LogArg kArg1 = FUN_140163790(*pInt1);
    Unk_LogArg kArg2 = FUN_140163740(*pStr2);
    Unk_LogArgValue kArg3(*pInt3);
    Unk_LogArgValue kArg4(*pInt4);
    (void)kArg1; (void)kArg2; (void)kArg3; (void)kArg4;

    u64 aSlot[5];
    u64 aInit[10];
    u64* pInit0 = FUN_140163e80(&aInit[0]);
    u64* pInit1 = FUN_140163e80(&aInit[1]);
    u64* pInit2 = FUN_140163e80(&aInit[2]);
    u64* pInit3 = FUN_140163e80(&aInit[3]);
    u64* pInit4 = FUN_140163e80(&aInit[4]);
    u64* pInit5 = FUN_140163e80(&aInit[5]);
    u64* pInit6 = FUN_140163e80(&aInit[6]);
    u64* pInit7 = FUN_140163e80(&aInit[7]);
    u64* pInit8 = FUN_140163e80(&aInit[8]);
    u64* pInit9 = FUN_140163e80(&aInit[9]);
    u64* pBound4 = FUN_1402e15d0(&aSlot[4], pInt4);
    u64* pBound3 = FUN_1402e15d0(&aSlot[3], pInt3);
    u64* pBound2 = FUN_1401cee00(&aSlot[2], pStr2);
    u64* pBound1 = FUN_14015e5d0(&aSlot[1], pInt1);
    u64* pBound0 = FUN_1401cee00(&aSlot[0], pStr0);
    (void)pBound4; (void)pBound0;

    u64 q0 = *pInit0, q1 = *pInit1, q2 = *pInit2, q3 = *pInit3, q4 = *pInit4;
    u64 q5 = *pInit5, q6 = *pInit6, q7 = *pInit7, q8 = *pInit8, q9 = *pInit9;
    (void)q0; (void)q1; (void)q2; (void)q3; (void)q4;
    (void)q5; (void)q6; (void)q7; (void)q8; (void)q9;

    u64 kJoined = FUN_14016d660(*pBound0, *pBound1, *pBound2, *pBound3);
    char aOut[24];
    u64 kArgs = FUN_140163e50(aOut, kJoined, &kArg0);
    FUN_140653690(pLog, a, c, nCategory, pszFormat, kArgs);
}

// @0x1402e12c0
void Unk_PerfLog::FUN_1402e12c0(const char* pszFormat, ...)
{
    bool bHasMessage = !m_strMessage.IsEmpty();
    unsigned nNow = FUN_140869420();
    if (m_nFirstTick == 0)
        m_nFirstTick = nNow;
    int nDeltaLast = (int)(nNow - m_nLastTick);
    int nDeltaFirst = (int)(nNow - m_nFirstTick);
    if (bHasMessage) {
        m_nCount++;
        void* pLog = FUN_140166440();
        FUN_1402e1600((i64)pLog, 0, 0, 1, L"[{0}_{1}:{2} {3}/{4}]",
                      &m_strLabel, &m_nCount, &m_strMessage, &nDeltaLast, &nDeltaFirst);
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
unsigned Unk_PerfLog::FUN_1402e14c0()
{
    return m_nFirstTick;
}

// @0x1402e14e0
CString Unk_PerfLog::FUN_1402e14e0()
{
    if (Unk_LockGuard guard = m_lock) {
    } else {
        return m_strMessage;
    }
}

// @0x1402e1570
unsigned Unk_PerfLog::FUN_1402e1570()
{
    if (m_nLastTick < m_nFirstTick)
        return 0;
    return (unsigned)(int)(m_nLastTick - m_nFirstTick) / 1000;
}

// @0x1402e15b0
void Unk_PerfLog::FUN_1402e15b0(void* pCallback)
{
    m_pCallback = (Unk_PerfLogCallback*)pCallback;
}

// @0x1402e1a60 - the CRT's bounds-checked memmove_s (UCRT static-inline copy, unreferenced in this TU).
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
