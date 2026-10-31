// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A two-function construction pair: the pooled-object factory
// (allocator New + in-place pool constructor) and the initializer that base-initializes the object and stores the fresh
// instance in its +0x8 member. The object's class and the allocator live in other units; only the pointer views used here
// are recovered. File and function names are invented.
// MS2-UNIT: unit_14112fe10
// MS2-RANGE: 0x14112fe10-0x14112fe60 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The pooled allocator New and the pool-constructor helper of the type built here (both live in other units).
void* FUN_1410dc3b0(void* pTag);
class CPtred* FUN_1401ba820(class CPtred*);   // C3: was FUN_1401ba820
void  FUN_141149360(void* pThis);   // the object's base initializer

// The object's pointer member at +0x8.
struct Unk_Obj8 {
    char  m_pad_00[0x8];
    void* m_pField8;   // +0x8
};
MS2_CHECK_OFFSET(Unk_Obj8, m_pField8, 0x8);

// @0x14112fe40
void* FUN_14112fe40(void*)
{
    return ((void*)FUN_1401ba820((class CPtred*)(FUN_1410dc3b0(0))));
}

// @0x14112fe10
void FUN_14112fe10(Unk_Obj8* pThis)
{
    FUN_141149360(pThis);
    pThis->m_pField8 = FUN_14112fe40(0);
}
