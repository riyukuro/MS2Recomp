// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The start-up step profiler's construction pair (ctor/dtor)
// plus the string-formatting wrappers that sit in front of it: the variadic wide wrapper, its va_list core and the
// va_list narrow (bounded) core, all three going through the CRT's __stdio_common_* entry points with the process's
// global printf options. The profiler class (Unk_StepProfiler) is declared in ms2.h; only its ctor/dtor are defined here.
// MS2-UNIT: unit_1402e1070
// MS2-RANGE: 0x1402e1070-0x1402e12c0 .text$mn
// Unk_StepProfiler adds no virtuals of its own, so its vftable is ICF-folded onto CLockCriticalSection's (the exe's ctor
// stores 0x142ce6750 only), leaving no distinct RTTI vftable in the exe for the obj-emitted ??_7 to pair with.
// MS2-PIN: ??_7Unk_StepProfiler@@6B@ 0x142ce6750
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/ms2.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <stdarg.h>

// The process-wide printf options the CRT entry points take (first qword of the object the getter returns).
unsigned long long* FUN_1402c3760();

// @0x1402e1150 - the va_list wide formatter (vswprintf core)
int FUN_1402e1150(wchar_t* pBuffer, size_t nBufferCount, const wchar_t* pszFormat, _locale_t pLocale, va_list args)
{
    int nCount = __stdio_common_vswprintf(*FUN_1402c3760(), pBuffer, nBufferCount, pszFormat, pLocale, args);
    int nResult;
    if (nCount < 0)
        nResult = -1;
    else
        nResult = nCount;
    return nResult;
}

// @0x1402e1070 - the variadic wide formatter: builds the va_list and defers to FUN_1402e1150
int FUN_1402e1070(wchar_t* pBuffer, size_t nBufferCount, const wchar_t* pszFormat, _locale_t pLocale, ...)
{
    va_list args;
    va_start(args, pLocale);
    int nCount = FUN_1402e1150(pBuffer, nBufferCount, pszFormat, pLocale, args);
    va_end(args);
    return nCount;
}

// @0x1402e10d0 - the va_list narrow, bounded formatter (vsnprintf_s core)
int FUN_1402e10d0(char* pBuffer, size_t nBufferCount, size_t nMaxCount, const char* pszFormat,
                  _locale_t pLocale, va_list args)
{
    int nCount = __stdio_common_vsnprintf_s(*FUN_1402c3760(), pBuffer, nBufferCount, nMaxCount,
                                            pszFormat, pLocale, args);
    int nResult;
    if (nCount < 0)
        nResult = -1;
    else
        nResult = nCount;
    return nResult;
}

// @0x1402e11c0
Unk_StepProfiler::Unk_StepProfiler(CString strName)
    : m_strName(strName), m_strStep(), m_uiStepStart(0), m_uiStart(0), m_nStep(0), m_pListener(0)
{
}

// @0x1402e1260
Unk_StepProfiler::~Unk_StepProfiler()
{
    m_pListener = 0;
}
