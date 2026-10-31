// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_1408e2330: out-of-line wrappers
// of the shared "boxed pointer" family (see unit_1403f37d0.cpp), three bodies repeated per wrapped type:
//   * guarded release `if (p->m_pValue != 0) <C>(p, 0);`
//   * `FUN_14015b020(p);` - the family's shared out-of-line helper
//   * `<B>(p->m_pValue);` - unwrap the box at +8 and hand the pointer on
// All names invented from shape; only the family helper and the few unwrap targets are outside this unit.
// MS2-UNIT: unit_1408e2330
// MS2-RANGE: 0x1408e2330-0x1408e2810 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

struct Unk_BoxedPointer {
    void* m_pUnused;            // +0x00
    void* m_pValue;             // +0x08 the boxed pointer the wrappers test and unwrap
};

void FUN_1408e2330(Unk_BoxedPointer* p);
void FUN_1408e2360(Unk_BoxedPointer* p);
void FUN_1408e2390(Unk_BoxedPointer* p);
void FUN_1408e23c0(Unk_BoxedPointer* p);
void FUN_1408e23f0(Unk_BoxedPointer* p);
void FUN_1408e2420(Unk_BoxedPointer* p);
void FUN_1408e2450(Unk_BoxedPointer* p);
void FUN_1408e2480(Unk_BoxedPointer* p);
void FUN_1408e24b0(Unk_BoxedPointer* p);
void FUN_1408e24e0(Unk_BoxedPointer* p);
void FUN_1408e2510(void* p);
void FUN_1408e2530(void* p);
void FUN_1408e2550(void* p);
void FUN_1408e2570(void* p);
void FUN_1408e2590(void* p);
void FUN_1408e25b0(void* p);
void FUN_1408e25d0(void* p);
void FUN_1408e25f0(void* p);
void FUN_1408e2610(void* p);
void FUN_1408e2630(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2660(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2690(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e26c0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e26f0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2720(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2750(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2780(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e27b0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e27e0(Unk_BoxedPointer* p, void* pUnused);
class CPtred   // C3: member view for the former free stand-ins
{
public:
    static void AddRefPtred(class CPtred*);
};
void FUN_14041d1b0(void* p);   // outside this unit

// ---------------------------------------------------------------------------
// the 29 entries, in address order
// ---------------------------------------------------------------------------

// @0x1408e2330
void FUN_1408e2330(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e2630(p, 0);
}

// @0x1408e2360
void FUN_1408e2360(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e2660(p, 0);
}

// @0x1408e2390
void FUN_1408e2390(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e2690(p, 0);
}

// @0x1408e23c0
void FUN_1408e23c0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e26c0(p, 0);
}

// @0x1408e23f0
void FUN_1408e23f0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e26f0(p, 0);
}

// @0x1408e2420
void FUN_1408e2420(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e2720(p, 0);
}

// @0x1408e2450
void FUN_1408e2450(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e2750(p, 0);
}

// @0x1408e2480
void FUN_1408e2480(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e2780(p, 0);
}

// @0x1408e24b0
void FUN_1408e24b0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e27b0(p, 0);
}

// @0x1408e24e0
void FUN_1408e24e0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1408e27e0(p, 0);
}

// @0x1408e2510
void FUN_1408e2510(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e2530
void FUN_1408e2530(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e2550
void FUN_1408e2550(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e2570
void FUN_1408e2570(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e2590
void FUN_1408e2590(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e25b0
void FUN_1408e25b0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e25d0
void FUN_1408e25d0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e25f0
void FUN_1408e25f0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e2610
void FUN_1408e2610(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1408e2630
void FUN_1408e2630(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e2510(p->m_pValue);
}

// @0x1408e2660
void FUN_1408e2660(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e2530(p->m_pValue);
}

// @0x1408e2690
void FUN_1408e2690(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e2550(p->m_pValue);
}

// @0x1408e26c0
void FUN_1408e26c0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e2570(p->m_pValue);
}

// @0x1408e26f0
void FUN_1408e26f0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e2590(p->m_pValue);
}

// @0x1408e2720
void FUN_1408e2720(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14041d1b0(p->m_pValue);
}

// @0x1408e2750
void FUN_1408e2750(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e25b0(p->m_pValue);
}

// @0x1408e2780
void FUN_1408e2780(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e25d0(p->m_pValue);
}

// @0x1408e27b0
void FUN_1408e27b0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e25f0(p->m_pValue);
}

// @0x1408e27e0
void FUN_1408e27e0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1408e2610(p->m_pValue);
}

