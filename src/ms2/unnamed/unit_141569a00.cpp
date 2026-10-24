// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Windows SDK's strsafe.h worker functions
// (static __inline) that a TU of the game instantiated: StringLengthWorkerA, StringExValidateSrcA,
// StringValidateDestA, StringValidateDestAndLengthA, StringExValidateDestA, StringCopyWorkerA, StringVPrintfWorkerA,
// StringExHandleFillBehindNullA, StringExHandleOtherFlagsA. Taking their addresses in a selectany table emits each one.
// MS2-UNIT: unit_141569a00
// MS2-RANGE: 0x141569a00-0x14156a020 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#pragma warning(disable : 4995)
// This TU's own copy of the CRT's _vsnprintf (0x14160bd30, outside every unit) is what StringVPrintfWorkerA calls; the
// symbol table binds the name _vsnprintf to the other copy (unit_1402c3760, 0x1402c37e0), so call the copy by address.
int __cdecl FUN_14160bd30(char* pDest, size_t nBufferCount, const char* pszFormat, va_list args);
#define _vsnprintf FUN_14160bd30
#include <strsafe.h>
#undef _vsnprintf

// @0x141569a00
// @0x141569ab0
// @0x141569b40
// @0x141569b90
// @0x141569c00
// @0x141569c80
// @0x141569d70
// @0x141569e70
// @0x141569ed0
__declspec(selectany) extern const void* const ms2_strsafeWorkers[] = {
    (const void*)&StringLengthWorkerA,
    (const void*)&StringExValidateSrcA,
    (const void*)&StringValidateDestA,
    (const void*)&StringValidateDestAndLengthA,
    (const void*)&StringExValidateDestA,
    (const void*)&StringCopyWorkerA,
    (const void*)&StringVPrintfWorkerA,
    (const void*)&StringExHandleFillBehindNullA,
    (const void*)&StringExHandleOtherFlagsA,
};

// These two strsafe workers are also referenced by the NM string helper in unit_1415fb880. The SDK copies above
// provide their canonical implementation; these exported FUN_ aliases preserve the recovered EXE call names.
// MS2-FUNCTIONAL: validates a nonzero destination size against the maximum allowed size from the recovered worker.
int __cdecl FUN_141569b40(char* pDest, unsigned long long cchDest, unsigned long long cchMax)
{
    if (cchDest == 0 || cchMax < cchDest)
        return static_cast<int>(0x80070057u);
    return 0;
}

// MS2-FUNCTIONAL: copies up to count bytes, null terminates, and reports the recovered STRSAFE_E_INSUFFICIENT_BUFFER result.
int __cdecl FUN_141569c80(char* pDest, unsigned long long cchDest, unsigned long long* pCopied,
                          const char* pSrc, unsigned long long count)
{
    unsigned long long copied = 0;
    while (cchDest != 0 && count != 0 && *pSrc != '\0') {
        *pDest++ = *pSrc++;
        --cchDest;
        --count;
        ++copied;
    }

    int result = 0;
    if (cchDest == 0) {
        --pDest;
        --copied;
        result = static_cast<int>(0x8007007au);
    }
    *pDest = '\0';
    if (pCopied != nullptr)
        *pCopied = copied;
    return result;
}
