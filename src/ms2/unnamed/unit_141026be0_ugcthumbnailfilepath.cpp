// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UGC thumbnail directory and thumbnail file path.
// MS2-UNIT: unit_141026be0
// MS2-RANGE: 0x141026be0-0x141026d10 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

CStringW FUN_14016a730(const char* psz, int n);

// @0x141026be0
CStringW FUN_141026be0()
{
    CStringW strPath = FUN_14016a730("./Custom/Thumbnail", 0);
    return CStringW(strPath);
}

// @0x141026c50
CStringW FUN_141026c50(const CStringW& strTitle)
{
    CStringW strPath;
    strPath.Format(L"%s/%s.png", (LPCWSTR)FUN_141026be0(), (LPCWSTR)strTitle);
    return CStringW(strPath);
}
