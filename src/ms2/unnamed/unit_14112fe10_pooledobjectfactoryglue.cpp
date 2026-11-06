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

#include "ms2/client/ms2/cubemapinformationservice_tail.h"   // SalesInfo, MS2SvrPtr<SalesInfo>
// C3: FUN_1410dc3b0 is MS2SvrPtr<SalesInfo>::Allocate (unit_1410dbc10); FUN_1401ba820 marks the fresh object.
//
// C3: FUN_141149360 (the "base initializer") is MS2SvrPtr<SalesInfo>::Release.

// The object's pointer member at +0x8.
struct Unk_Obj8 {
    char  m_pad_00[0x8];
    void* m_pField8;   // +0x8
};
MS2_CHECK_OFFSET(Unk_Obj8, m_pField8, 0x8);

// @0x14112fe40
template SalesInfo* MS2SvrPtr<SalesInfo>::Create(void*);   // C3: was FUN_14112fe40
//
//
//

// @0x14112fe10
template void MS2SvrPtr<SalesInfo>::Make();   // C3: was FUN_14112fe10 (Release 0x141149360, then m_p = Create(0))
//
//
//
//
