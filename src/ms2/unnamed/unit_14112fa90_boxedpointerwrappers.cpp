// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_14112fa90: out-of-line wrappers
// of the shared "boxed pointer" family (see unit_1403f37d0.cpp), three bodies repeated per wrapped type:
//   * guarded release `if (p->m_pValue != 0) <C>(p, 0);`
//   * `FUN_14015b020(p);` - the family's shared out-of-line helper
//   * `<B>(p->m_pValue);` - unwrap the box at +8 and hand the pointer on
// All names invented from shape; only the family helper and the few unwrap targets are outside this unit.
// MS2-UNIT: unit_14112fa90
// MS2-RANGE: 0x14112fa90-0x14112fe10 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

struct Unk_BoxedPointer {
    void* m_pUnused;            // +0x00
    void* m_pValue;             // +0x08 the boxed pointer the wrappers test and unwrap
};

void FUN_14112fa90(Unk_BoxedPointer* p);
void FUN_14112fac0(Unk_BoxedPointer* p);
void FUN_14112faf0(Unk_BoxedPointer* p);
void FUN_14112fb20(Unk_BoxedPointer* p);
void FUN_14112fb50(Unk_BoxedPointer* p);
void FUN_14112fb80(Unk_BoxedPointer* p);
void FUN_14112fbb0(Unk_BoxedPointer* p);
void FUN_14112fbe0(void* p);
void FUN_14112fc00(void* p);
void FUN_14112fc20(void* p);
void FUN_14112fc40(void* p);
void FUN_14112fc60(void* p);
void FUN_14112fc80(void* p);
void FUN_14112fca0(void* p);
void FUN_14112fcc0(Unk_BoxedPointer* p, void* pUnused);
void FUN_14112fcf0(Unk_BoxedPointer* p, void* pUnused);
void FUN_14112fd20(Unk_BoxedPointer* p, void* pUnused);
void FUN_14112fd50(Unk_BoxedPointer* p, void* pUnused);
void FUN_14112fd80(Unk_BoxedPointer* p, void* pUnused);
void FUN_14112fdb0(Unk_BoxedPointer* p, void* pUnused);
void FUN_14112fde0(Unk_BoxedPointer* p, void* pUnused);
class CPtred   // C3: member view for the former free stand-ins
{
public:
    static void AddRefPtred(class CPtred*);
};
void FUN_1408b7780(void* p);   // outside this unit

// ---------------------------------------------------------------------------
// the 21 entries, in address order
// ---------------------------------------------------------------------------

// @0x14112fa90
void FUN_14112fa90(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14112fcc0(p, 0);
}

// @0x14112fac0
void FUN_14112fac0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14112fcf0(p, 0);
}

// @0x14112faf0
void FUN_14112faf0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14112fd20(p, 0);
}

// @0x14112fb20
void FUN_14112fb20(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14112fd50(p, 0);
}

// @0x14112fb50
void FUN_14112fb50(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14112fd80(p, 0);
}

// @0x14112fb80
void FUN_14112fb80(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14112fdb0(p, 0);
}

// @0x14112fbb0
void FUN_14112fbb0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14112fde0(p, 0);
}

// @0x14112fbe0
void FUN_14112fbe0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14112fc00
void FUN_14112fc00(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14112fc20
void FUN_14112fc20(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14112fc40
void FUN_14112fc40(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14112fc60
void FUN_14112fc60(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14112fc80
void FUN_14112fc80(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14112fca0
void FUN_14112fca0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14112fcc0
void FUN_14112fcc0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14112fbe0(p->m_pValue);
}

// @0x14112fcf0
void FUN_14112fcf0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14112fc00(p->m_pValue);
}

// @0x14112fd20
void FUN_14112fd20(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14112fc20(p->m_pValue);
}

// @0x14112fd50
void FUN_14112fd50(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14112fc40(p->m_pValue);
}

// @0x14112fd80
void FUN_14112fd80(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408b7780(p->m_pValue);
}

// @0x14112fdb0
void FUN_14112fdb0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14112fc60(p->m_pValue);
}

// @0x14112fde0
void FUN_14112fde0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14112fc80(p->m_pValue);
}

