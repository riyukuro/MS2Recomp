// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The static CRT's narrow sprintf core: the process printf-options
// getter, the __stdio_common_vsprintf_s wrapper the rest of the exe formats through (FUN_1402e10d0/FUN_1402e1150 call the
// same options word) and the CRT's _vsnprintf, which forwards to that wrapper with the "C" locale. This is library code the
// exe linked in, not game source: the names below are the recovered identities, not original source names.
// MS2-UNIT: unit_1402c3760
// MS2-RANGE: 0x1402c3760-0x1402c3840 .text$mn
#define MS2_THIS_FILE ""
// The real build's ucrt headers did not have the _CRT_STDIO_INLINE bodies (the exe calls this _vsnprintf out of line from
// six sites), so this TU asks for the declaration-only form of stdio.h to be able to define it.
#define _NO_CRT_STDIO_INLINE 1
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <stdarg.h>

// The process-wide printf options word every __stdio_common_* entry point takes as its first argument.
extern unsigned long long DAT_143aad0e8;

// @0x1402c3760 - &printfOptions
unsigned long long* FUN_1402c3760()
{
    return &DAT_143aad0e8;
}

// @0x1402c3770 - the va_list narrow formatter (vsprintf_s core)
int FUN_1402c3770(char* pBuffer, size_t nBufferCount, const char* pszFormat, _locale_t pLocale, va_list args)
{
    int nCount = __stdio_common_vsprintf_s(*FUN_1402c3760(), pBuffer, nBufferCount, pszFormat, pLocale, args);
    int nResult;
    if (nCount < 0)
        nResult = -1;
    else
        nResult = nCount;
    return nResult;
}

// @0x1402c37e0 - the CRT's _vsnprintf (the wrapper with the NULL locale)
// Defined inline (a COMDAT) because other units of the game, which keep the SDK's inline stdio bodies, instantiate their own
// copy of this symbol; a selectany address table keeps this unit's copy emitted.
inline int __cdecl _vsnprintf(char* pDest, size_t nBufferCount, const char* pszFormat, va_list args)
{
    return FUN_1402c3770(pDest, nBufferCount, pszFormat, 0, args);
}
__declspec(selectany) extern const void* const ms2_vsnprintfAnchor[] = { (const void*)&_vsnprintf };
