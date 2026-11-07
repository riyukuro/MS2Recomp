// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two nested stream cryptor wrapper functions.
// MS2-UNIT: unit_1415fb820
// MS2-RANGE: 0x1415fb820-0x1415fb880 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

extern void FUN_1415ef190(void*, void*);

// the nested cryptor at offset 0, which the wrapper hands on
struct Unk_NestedCryptorView { char m; };
// @0x1415fb820
void FUN_1415fb820(void* p, void* q)
{
    FUN_1415ef190(&static_cast<Unk_NestedCryptorView*>(p)->m, q);
}

// @0x1415fb850
void FUN_1415fb850(void* p, void* q)
{
    FUN_1415fb820(static_cast<char*>(p) + 8, q);
}
