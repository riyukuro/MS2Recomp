// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A pointer-dereference accessor and its wrapper: the accessor
// loads the qword stored at the address it is given, the wrapper forwards its argument to it.
// MS2-UNIT: unit_1403e8e30
// MS2-RANGE: 0x1403e8e30-0x1403e8e60 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_1403e8e30.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1403e8e30
void* FUN_1403e8e30(void** p)
{
    return *p;
}

// @0x1403e8e40
void FUN_1403e8e40(void** p)
{
    FUN_1403e8e30(p);
}
