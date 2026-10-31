// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Four pooled-object construction pairs: for each of four
// pointer-wrapped types, the factory (allocator New + in-place constructor, sharing the runtime's refcount-1 helper) and
// the initializer that releases the object's previous +0x8 instance and stores the fresh one. The owned types, their
// allocators and the per-type release helpers live in other units; only the pointer view used here is recovered.
// File and function names are invented.
// MS2-UNIT: unit_141bb1490
// MS2-RANGE: 0x141bb1490-0x141bb15d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The runtime's refcount-1 helper, the four types' pooled allocator+constructor and their release helpers (other units).
class CPtred* FUN_1401ba820(class CPtred*);   // C3: was FUN_1401ba820
void* FUN_141b9d8e0(void* pTag);
void* FUN_141b9d950(void* pTag);
void* FUN_141b9d9c0(void* pTag);
void* FUN_141b9da20(void* pTag);
void  FUN_141b6c060(void* pThis);
void  FUN_141b6c0a0(void* pThis);
void  FUN_141b6c0e0(void* pThis);
void  FUN_140cb18e0(void* pThis);

// The four factories below (defined after the initializers, in exe order).
void* FUN_141bb1550(void*);
void* FUN_141bb1570(void*);
void* FUN_141bb1590(void*);
void* FUN_141bb15b0(void*);

// The owner's pointer member at +0x8 (the four owners share this view).
struct Unk_141bb1490_Obj8 {
    char  m_pad_00[0x8];
    void* m_pField8;   // +0x8
};
MS2_CHECK_OFFSET(Unk_141bb1490_Obj8, m_pField8, 0x8);

// @0x141bb1490
void FUN_141bb1490(Unk_141bb1490_Obj8* pThis)
{
    FUN_141b6c060(pThis);
    pThis->m_pField8 = FUN_141bb1550(0);
}

// @0x141bb14c0
void FUN_141bb14c0(Unk_141bb1490_Obj8* pThis)
{
    FUN_141b6c0a0(pThis);
    pThis->m_pField8 = FUN_141bb1570(0);
}

// @0x141bb14f0
void FUN_141bb14f0(Unk_141bb1490_Obj8* pThis)
{
    FUN_141b6c0e0(pThis);
    pThis->m_pField8 = FUN_141bb1590(0);
}

// @0x141bb1520
void FUN_141bb1520(Unk_141bb1490_Obj8* pThis)
{
    FUN_140cb18e0(pThis);
    pThis->m_pField8 = FUN_141bb15b0(0);
}

// @0x141bb1550
void* FUN_141bb1550(void*)
{
    return ((void*)FUN_1401ba820((class CPtred*)(FUN_141b9d8e0(0))));
}

// @0x141bb1570
void* FUN_141bb1570(void*)
{
    return ((void*)FUN_1401ba820((class CPtred*)(FUN_141b9d950(0))));
}

// @0x141bb1590
void* FUN_141bb1590(void*)
{
    return ((void*)FUN_1401ba820((class CPtred*)(FUN_141b9d9c0(0))));
}

// @0x141bb15b0
void* FUN_141bb15b0(void*)
{
    return ((void*)FUN_1401ba820((class CPtred*)(FUN_141b9da20(0))));
}
