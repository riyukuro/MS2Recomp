// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Windows SDK strsafe.h workers (StringCchCopyExA, StringCbCopyExA,
// StringCchPrintfA, StringCchCatA, StringCchCopyA, taken by address like unit_141569a00) plus 21 std::vector<T>::_Buy
// instances over element types the exe does not name (stand-ins of the exact element size).
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_1415fbae0
// MS2-RANGE: 0x1415fbae0-0x1415fd530 .text$mn
// MS2-PIN: ?StringCchPrintfA@@YAJPEAD_KPEBDZZ 0x1415fbd50
#define MS2_THIS_FILE ""
#define _ALLOW_KEYWORD_MACROS 1
#define private public
#include <vector>
#undef private
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#pragma warning(disable : 4995)
// The CRT's _vsnprintf copy StringVPrintfWorkerA calls (see unit_141569a00).
int __cdecl FUN_14160bd30(char* pDest, size_t nBufferCount, const char* pszFormat, va_list args);
#define _vsnprintf FUN_14160bd30
#include <strsafe.h>
#undef _vsnprintf

template <int Tag, int N> struct Unk_VecElem { unsigned __int64 q[N / 8]; };
// @0x1415fbae0
// @0x1415fbd50 MS2-FUNCTIONAL: the SDK header spills an extra copy of the format pointer; the exe is the older va_start form
// @0x1415fbdf0
// @0x1415fbe70
// @0x1415fbef0
__declspec(selectany) extern const void* const ms2_strsafeCallers[] = {
    (const void*)&StringCbCopyExA,
    (const void*)&StringCchPrintfA,
    (const void*)&StringCchCatA,
    (const void*)&StringCchCopyA,
    (const void*)&StringCchCopyExA,
};

// @0x1415fc140
HRESULT Unk_CopyNullOnFail(char* dest, unsigned cch, const char* src)
{
    return StringCbCopyExA(dest, cch, src, NULL, NULL, 0x100);
}

// @0x1415fc180
__declspec(selectany) extern bool (std::vector<Unk_VecElem<0, 16> >::* const Unk_Buy_1415fc180)(size_t) = &std::vector<Unk_VecElem<0, 16> >::_Buy;
// @0x1415fc270
__declspec(selectany) extern bool (std::vector<Unk_VecElem<1, 24> >::* const Unk_Buy_1415fc270)(size_t) = &std::vector<Unk_VecElem<1, 24> >::_Buy;
// @0x1415fc360
__declspec(selectany) extern bool (std::vector<Unk_VecElem<2, 88> >::* const Unk_Buy_1415fc360)(size_t) = &std::vector<Unk_VecElem<2, 88> >::_Buy;
// @0x1415fc450
__declspec(selectany) extern bool (std::vector<Unk_VecElem<3, 48> >::* const Unk_Buy_1415fc450)(size_t) = &std::vector<Unk_VecElem<3, 48> >::_Buy;
// @0x1415fc540
__declspec(selectany) extern bool (std::vector<Unk_VecElem<4, 152> >::* const Unk_Buy_1415fc540)(size_t) = &std::vector<Unk_VecElem<4, 152> >::_Buy;
// @0x1415fc630
__declspec(selectany) extern bool (std::vector<Unk_VecElem<5, 544> >::* const Unk_Buy_1415fc630)(size_t) = &std::vector<Unk_VecElem<5, 544> >::_Buy;
// @0x1415fc720
__declspec(selectany) extern bool (std::vector<Unk_VecElem<6, 296> >::* const Unk_Buy_1415fc720)(size_t) = &std::vector<Unk_VecElem<6, 296> >::_Buy;
// @0x1415fc810
__declspec(selectany) extern bool (std::vector<Unk_VecElem<7, 280> >::* const Unk_Buy_1415fc810)(size_t) = &std::vector<Unk_VecElem<7, 280> >::_Buy;
// @0x1415fc900
__declspec(selectany) extern bool (std::vector<Unk_VecElem<8, 1408> >::* const Unk_Buy_1415fc900)(size_t) = &std::vector<Unk_VecElem<8, 1408> >::_Buy;
// @0x1415fc9f0
__declspec(selectany) extern bool (std::vector<Unk_VecElem<9, 24> >::* const Unk_Buy_1415fc9f0)(size_t) = &std::vector<Unk_VecElem<9, 24> >::_Buy;
// @0x1415fcae0
__declspec(selectany) extern bool (std::vector<Unk_VecElem<10, 5288> >::* const Unk_Buy_1415fcae0)(size_t) = &std::vector<Unk_VecElem<10, 5288> >::_Buy;
// @0x1415fcbd0
__declspec(selectany) extern bool (std::vector<Unk_VecElem<11, 24> >::* const Unk_Buy_1415fcbd0)(size_t) = &std::vector<Unk_VecElem<11, 24> >::_Buy;
// @0x1415fccc0
__declspec(selectany) extern bool (std::vector<Unk_VecElem<12, 400> >::* const Unk_Buy_1415fccc0)(size_t) = &std::vector<Unk_VecElem<12, 400> >::_Buy;
// @0x1415fcdb0
__declspec(selectany) extern bool (std::vector<Unk_VecElem<13, 184> >::* const Unk_Buy_1415fcdb0)(size_t) = &std::vector<Unk_VecElem<13, 184> >::_Buy;
// @0x1415fcea0
__declspec(selectany) extern bool (std::vector<Unk_VecElem<14, 88> >::* const Unk_Buy_1415fcea0)(size_t) = &std::vector<Unk_VecElem<14, 88> >::_Buy;
// @0x1415fcf90
__declspec(selectany) extern bool (std::vector<Unk_VecElem<15, 2792> >::* const Unk_Buy_1415fcf90)(size_t) = &std::vector<Unk_VecElem<15, 2792> >::_Buy;
// @0x1415fd080
__declspec(selectany) extern bool (std::vector<Unk_VecElem<16, 3784> >::* const Unk_Buy_1415fd080)(size_t) = &std::vector<Unk_VecElem<16, 3784> >::_Buy;
// @0x1415fd170
__declspec(selectany) extern bool (std::vector<Unk_VecElem<17, 200> >::* const Unk_Buy_1415fd170)(size_t) = &std::vector<Unk_VecElem<17, 200> >::_Buy;
// @0x1415fd260
__declspec(selectany) extern bool (std::vector<Unk_VecElem<18, 248> >::* const Unk_Buy_1415fd260)(size_t) = &std::vector<Unk_VecElem<18, 248> >::_Buy;
// @0x1415fd350
__declspec(selectany) extern bool (std::vector<Unk_VecElem<19, 1168> >::* const Unk_Buy_1415fd350)(size_t) = &std::vector<Unk_VecElem<19, 1168> >::_Buy;
// @0x1415fd440
__declspec(selectany) extern bool (std::vector<Unk_VecElem<20, 32> >::* const Unk_Buy_1415fd440)(size_t) = &std::vector<Unk_VecElem<20, 32> >::_Buy;
