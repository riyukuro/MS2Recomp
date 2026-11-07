// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two stream cryptor wrapper functions.
// MS2-UNIT: unit_1415ef0e0
// MS2-RANGE: 0x1415ef0e0-0x1415ef130 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

extern void FUN_1415eb720(void*);
extern void FUN_1415eb7b0(void*);
extern void FUN_1415ef0e0(void*);

// the member at offset 0 that the wrapper hands on
struct Unk_CryptorMemberView { char m; };
// @0x1415ef0e0
void FUN_1415ef0e0(void* p)
{
    FUN_1415eb720(&static_cast<Unk_CryptorMemberView*>(p)->m);
}

// @0x1415ef100
void FUN_1415ef100(void* p)
{
    FUN_1415eb7b0(static_cast<char*>(p) + 0x18);
    FUN_1415ef0e0(static_cast<char*>(p) + 8);
}
