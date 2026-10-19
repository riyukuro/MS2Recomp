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
