// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_1408e2810: the tail of the "boxed
// pointer" wrapper family of unit_1408e2330 (shape: TPtr<T> release glue, one set per wrapped type):
//   * `if (p->m_pValue != 0) { <Release>(p, 0); p->m_pValue = 0; }` - drop the boxed reference
//   * `<Release>`: the intrusive ref-count release of the pointee (FUN_140159bc0 == 0 -> destroy, then FUN_140159ba0)
//   * a CRT memcpy_s copy (checked copy, errno + invalid-parameter handler)
// All names invented from shape.
// MS2-UNIT: unit_1408e2810
// MS2-RANGE: 0x1408e2810-0x1408e2ed0 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

struct Unk_BoxedPointer {
    void* m_pUnused;            // +0x00
    void* m_pValue;             // +0x08 the boxed pointer
};

int FUN_140159bc0(void* p);     // outside this unit: release the reference, 0 = last one
void FUN_140159ba0(void* p);    // outside this unit: free the pointee after its destroy

void FUN_1408e2a90(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2ae0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2b30(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2b80(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2bd0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2c20(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2c70(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2cc0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2d10(Unk_BoxedPointer* p, void* pUnused);
void FUN_1408e2d60(Unk_BoxedPointer* p, void* pUnused);
void FUN_14041d1b0(void* p);   // outside this unit
void FUN_1408e2510(void* p);   // outside this unit
void FUN_1408e2530(void* p);   // outside this unit
void FUN_1408e2550(void* p);   // outside this unit
void FUN_1408e2570(void* p);   // outside this unit
void FUN_1408e2590(void* p);   // outside this unit
void FUN_1408e25b0(void* p);   // outside this unit
void FUN_1408e25d0(void* p);   // outside this unit
void FUN_1408e25f0(void* p);   // outside this unit
void FUN_1408e2610(void* p);   // outside this unit

// @0x1408e2810
void FUN_1408e2810(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2a90(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e2850
void FUN_1408e2850(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2ae0(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e2890
void FUN_1408e2890(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2b30(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e28d0
void FUN_1408e28d0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2b80(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e2910
void FUN_1408e2910(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2bd0(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e2950
void FUN_1408e2950(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2c20(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e2990
void FUN_1408e2990(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2c70(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e29d0
void FUN_1408e29d0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2cc0(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e2a10
void FUN_1408e2a10(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2d10(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e2a50
void FUN_1408e2a50(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0) {
        FUN_1408e2d60(p, 0);
        p->m_pValue = 0;
    }
}

// @0x1408e2a90
void FUN_1408e2a90(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e2510(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2ae0
void FUN_1408e2ae0(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e2530(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2b30
void FUN_1408e2b30(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e2550(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2b80
void FUN_1408e2b80(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e2570(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2bd0
void FUN_1408e2bd0(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e2590(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2c20
void FUN_1408e2c20(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_14041d1b0(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2c70
void FUN_1408e2c70(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e25b0(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2cc0
void FUN_1408e2cc0(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e25d0(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2d10
void FUN_1408e2d10(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e25f0(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2d60
void FUN_1408e2d60(Unk_BoxedPointer* p, void* pUnused)
{
    void* pValue = p->m_pValue;
    if (FUN_140159bc0(pValue) == 0) {
        FUN_1408e2610(pValue);
        FUN_140159ba0(pValue);
    }
}

// @0x1408e2db0
// The UCRT's memcpy_s (checked copy), as an ordinary function.
#pragma function(memcpy)
int FUN_1408e2db0(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
#pragma intrinsic(memcpy)
