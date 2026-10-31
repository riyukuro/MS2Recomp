// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The two append operators of the cube-map service's UTF-8 string
// (efd::utf8string, 0x20 bytes, recovered by the cubemapinformationservice units as Unk_CMISStr) and the C-string form that
// forwards to the first. The string type and both real appenders live in other units.
// MS2-UNIT: unit_14112cd60
// MS2-RANGE: 0x14112cd60-0x14112cdec .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

struct Unk_CMISStr;                                          // efd::utf8string (0x20)
struct Unk_CMISStrView { Unk_CMISStr* m_first; };            // the string's first member, its internal string

void FUN_14114d9b0(Unk_CMISStr* pStr, const char* pSz);      // operator+= (const char*)
Unk_CMISStr* FUN_1409a1570(Unk_CMISStr* pStr, Unk_CMISStr* pAdd);   // operator+= (const string&)

// @0x14112cd60
void FUN_14112cd60(Unk_CMISStr* pStr, const char* pSz)
{
    FUN_14114d9b0(pStr, pSz);
}

// @0x14112cd90
// MS2-FUNCTIONAL: same calls; the exe routes the second argument through rax (mov rax,[home2]; mov rcx,[home1]; mov
// rdx,rax) where cl loads it straight into rdx. No source form found for that hop (probed plain/const/restrict/volatile
// pointer and reference params, by-value 8- and 16-byte classes, comma and named-local spellings).
Unk_CMISStr* FUN_14112cd90(Unk_CMISStr* pStr, Unk_CMISStr* pAdd)
{
    FUN_1409a1570(pStr, pAdd);
    return pStr;
}

// @0x14112cdc0
Unk_CMISStr* FUN_14112cdc0(Unk_CMISStr* pStr, const char* pSz)
{
    FUN_14112cd60(reinterpret_cast<Unk_CMISStr*>(&reinterpret_cast<Unk_CMISStrView*>(pStr)->m_first), pSz);
    return pStr;
}
