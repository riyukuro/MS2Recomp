// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_140b5faf0: out-of-line wrappers
// of the shared "boxed pointer" family (see unit_1403f37d0.cpp), three bodies repeated per wrapped type:
//   * guarded release `if (p->m_pValue != 0) <C>(p, 0);`
//   * `FUN_14015b020(p);` - the family's shared out-of-line helper
//   * `<B>(p->m_pValue);` - unwrap the box at +8 and hand the pointer on
// All names invented from shape; only the family helper and the few unwrap targets are outside this unit.
// MS2-UNIT: unit_140b5faf0
// MS2-RANGE: 0x140b5faf0-0x140b602f0 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

struct Unk_BoxedPointer {
    void* m_pUnused;            // +0x00
    void* m_pValue;             // +0x08 the boxed pointer the wrappers test and unwrap
};

void FUN_140b5faf0(Unk_BoxedPointer* p);
void FUN_140b5fb20(Unk_BoxedPointer* p);
void FUN_140b5fb50(Unk_BoxedPointer* p);
void FUN_140b5fb80(Unk_BoxedPointer* p);
void FUN_140b5fbb0(Unk_BoxedPointer* p);
void FUN_140b5fbe0(Unk_BoxedPointer* p);
void FUN_140b5fc10(Unk_BoxedPointer* p);
void FUN_140b5fc40(Unk_BoxedPointer* p);
void FUN_140b5fc70(Unk_BoxedPointer* p);
void FUN_140b5fca0(Unk_BoxedPointer* p);
void FUN_140b5fcd0(Unk_BoxedPointer* p);
void FUN_140b5fd00(Unk_BoxedPointer* p);
void FUN_140b5fd30(Unk_BoxedPointer* p);
void FUN_140b5fd60(Unk_BoxedPointer* p);
void FUN_140b5fd90(Unk_BoxedPointer* p);
void FUN_140b5fdc0(Unk_BoxedPointer* p);
void FUN_140b5fdf0(void* p);
void FUN_140b5fe10(void* p);
void FUN_140b5fe30(void* p);
void FUN_140b5fe50(void* p);
void FUN_140b5fe70(void* p);
void FUN_140b5fe90(void* p);
void FUN_140b5feb0(void* p);
void FUN_140b5fed0(void* p);
void FUN_140b5fef0(void* p);
void FUN_140b5ff10(void* p);
void FUN_140b5ff30(void* p);
void FUN_140b5ff50(void* p);
void FUN_140b5ff70(void* p);
void FUN_140b5ff90(void* p);
void FUN_140b5ffb0(void* p);
void FUN_140b5ffd0(void* p);
void FUN_140b5fff0(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60020(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60050(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60080(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b600b0(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b600e0(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60110(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60140(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60170(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b601a0(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b601d0(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60200(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60230(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60260(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b60290(Unk_BoxedPointer* p, void* pUnused);
void FUN_140b602c0(Unk_BoxedPointer* p, void* pUnused);
void FUN_14015b020(void* p);   // outside this unit

// ---------------------------------------------------------------------------
// the 48 entries, in address order
// ---------------------------------------------------------------------------

// @0x140b5faf0
void FUN_140b5faf0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b5fff0(p, 0);
}

// @0x140b5fb20
void FUN_140b5fb20(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60020(p, 0);
}

// @0x140b5fb50
void FUN_140b5fb50(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60050(p, 0);
}

// @0x140b5fb80
void FUN_140b5fb80(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60080(p, 0);
}

// @0x140b5fbb0
void FUN_140b5fbb0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b600b0(p, 0);
}

// @0x140b5fbe0
void FUN_140b5fbe0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b600e0(p, 0);
}

// @0x140b5fc10
void FUN_140b5fc10(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60110(p, 0);
}

// @0x140b5fc40
void FUN_140b5fc40(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60140(p, 0);
}

// @0x140b5fc70
void FUN_140b5fc70(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60170(p, 0);
}

// @0x140b5fca0
void FUN_140b5fca0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b601a0(p, 0);
}

// @0x140b5fcd0
void FUN_140b5fcd0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b601d0(p, 0);
}

// @0x140b5fd00
void FUN_140b5fd00(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60200(p, 0);
}

// @0x140b5fd30
void FUN_140b5fd30(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60230(p, 0);
}

// @0x140b5fd60
void FUN_140b5fd60(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60260(p, 0);
}

// @0x140b5fd90
void FUN_140b5fd90(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b60290(p, 0);
}

// @0x140b5fdc0
void FUN_140b5fdc0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_140b602c0(p, 0);
}

// @0x140b5fdf0
void FUN_140b5fdf0(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5fe10
void FUN_140b5fe10(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5fe30
void FUN_140b5fe30(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5fe50
void FUN_140b5fe50(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5fe70
void FUN_140b5fe70(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5fe90
void FUN_140b5fe90(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5feb0
void FUN_140b5feb0(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5fed0
void FUN_140b5fed0(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5fef0
void FUN_140b5fef0(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5ff10
void FUN_140b5ff10(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5ff30
void FUN_140b5ff30(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5ff50
void FUN_140b5ff50(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5ff70
void FUN_140b5ff70(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5ff90
void FUN_140b5ff90(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5ffb0
void FUN_140b5ffb0(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5ffd0
void FUN_140b5ffd0(void* p)
{
    FUN_14015b020(p);
}

// @0x140b5fff0
void FUN_140b5fff0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5fdf0(p->m_pValue);
}

// @0x140b60020
void FUN_140b60020(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5fe10(p->m_pValue);
}

// @0x140b60050
void FUN_140b60050(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5fe30(p->m_pValue);
}

// @0x140b60080
void FUN_140b60080(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5fe50(p->m_pValue);
}

// @0x140b600b0
void FUN_140b600b0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5fe70(p->m_pValue);
}

// @0x140b600e0
void FUN_140b600e0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5fe90(p->m_pValue);
}

// @0x140b60110
void FUN_140b60110(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5feb0(p->m_pValue);
}

// @0x140b60140
void FUN_140b60140(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5fed0(p->m_pValue);
}

// @0x140b60170
void FUN_140b60170(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5fef0(p->m_pValue);
}

// @0x140b601a0
void FUN_140b601a0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5ff10(p->m_pValue);
}

// @0x140b601d0
void FUN_140b601d0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5ff30(p->m_pValue);
}

// @0x140b60200
void FUN_140b60200(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5ff50(p->m_pValue);
}

// @0x140b60230
void FUN_140b60230(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5ff70(p->m_pValue);
}

// @0x140b60260
void FUN_140b60260(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5ff90(p->m_pValue);
}

// @0x140b60290
void FUN_140b60290(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5ffb0(p->m_pValue);
}

// @0x140b602c0
void FUN_140b602c0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_140b5ffd0(p->m_pValue);
}

