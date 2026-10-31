// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_1403f37d0: 134 out-of-line
// wrappers of one "boxed pointer" family, three bodies repeated:
//   * A (44x): `if (p->m_pValue != 0) <C>(p, 0);` - the guarded release of the boxed pointer at +8, with the
//     false/null second argument the exe passes in edx/rdx (which is why every C entry homes rdx too);
//   * C (44x): `<B>(p->m_pValue);` - unwrap the box and hand the pointer on;
//   * B (45x): `<the shared helper>` - forward the wrapper's own pointer to the family's out-of-line helper.
// Each A pairs with the C that follows it and each C with a B, type for type. All names invented from shape; the
// single callee outside this unit is FUN_14015b020.
// MS2-UNIT: unit_1403f37d0
// MS2-RANGE: 0x1403f37d0-0x1403f4e10 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

// ---- unit-local view of the box the family wraps ----
struct Unk_BoxedPointer {
    void* m_pUnused;            // +0x00
    void* m_pValue;             // +0x08 the boxed pointer the wrappers test and unwrap
};

// ---- prototypes ----

void FUN_1403f37d0(Unk_BoxedPointer* p);
void FUN_1403f3800(Unk_BoxedPointer* p);
void FUN_1403f3830(Unk_BoxedPointer* p);
void FUN_1403f3860(Unk_BoxedPointer* p);
void FUN_1403f3890(Unk_BoxedPointer* p);
void FUN_1403f38c0(Unk_BoxedPointer* p);
void FUN_1403f38f0(Unk_BoxedPointer* p);
void FUN_1403f3920(Unk_BoxedPointer* p);
void FUN_1403f3950(Unk_BoxedPointer* p);
void FUN_1403f3980(Unk_BoxedPointer* p);
void FUN_1403f39b0(Unk_BoxedPointer* p);
void FUN_1403f39e0(Unk_BoxedPointer* p);
void FUN_1403f3a10(Unk_BoxedPointer* p);
void FUN_1403f3a40(Unk_BoxedPointer* p);
void FUN_1403f3a70(Unk_BoxedPointer* p);
void FUN_1403f3aa0(Unk_BoxedPointer* p);
void FUN_1403f3ad0(Unk_BoxedPointer* p);
void FUN_1403f3b00(Unk_BoxedPointer* p);
void FUN_1403f3b30(Unk_BoxedPointer* p);
void FUN_1403f3b60(Unk_BoxedPointer* p);
void FUN_1403f3b90(Unk_BoxedPointer* p);
void FUN_1403f3bc0(Unk_BoxedPointer* p);
void FUN_1403f3bf0(Unk_BoxedPointer* p);
void FUN_1403f3c20(Unk_BoxedPointer* p);
void FUN_1403f3c50(Unk_BoxedPointer* p);
void FUN_1403f3c80(Unk_BoxedPointer* p);
void FUN_1403f3cb0(Unk_BoxedPointer* p);
void FUN_1403f3ce0(Unk_BoxedPointer* p);
void FUN_1403f3d10(Unk_BoxedPointer* p);
void FUN_1403f3d40(Unk_BoxedPointer* p);
void FUN_1403f3d70(Unk_BoxedPointer* p);
void FUN_1403f3da0(Unk_BoxedPointer* p);
void FUN_1403f3dd0(Unk_BoxedPointer* p);
void FUN_1403f3e00(Unk_BoxedPointer* p);
void FUN_1403f3e30(Unk_BoxedPointer* p);
void FUN_1403f3e60(Unk_BoxedPointer* p);
void FUN_1403f3e90(Unk_BoxedPointer* p);
void FUN_1403f3ec0(Unk_BoxedPointer* p);
void FUN_1403f3ef0(Unk_BoxedPointer* p);
void FUN_1403f3f20(Unk_BoxedPointer* p);
void FUN_1403f3f50(Unk_BoxedPointer* p);
void FUN_1403f3f80(Unk_BoxedPointer* p);
void FUN_1403f3fb0(Unk_BoxedPointer* p);
void FUN_1403f3fe0(Unk_BoxedPointer* p);
void FUN_1403f4010(void* p);
void FUN_1403f4030(void* p);
void FUN_1403f4050(void* p);
void FUN_1403f4070(void* p);
void FUN_1403f4090(void* p);
void FUN_1403f40b0(void* p);
void FUN_1403f40d0(void* p);
void FUN_1403f40f0(void* p);
void FUN_1403f4110(void* p);
void FUN_1403f4130(void* p);
void FUN_1403f4150(void* p);
void FUN_1403f4170(void* p);
void FUN_1403f4190(void* p);
void FUN_1403f41b0(void* p);
void FUN_1403f41d0(void* p);
void FUN_1403f41f0(void* p);
void FUN_1403f4210(void* p);
void FUN_1403f4230(void* p);
void FUN_1403f4250(void* p);
void FUN_1403f4270(void* p);
void FUN_1403f4290(void* p);
void FUN_1403f42b0(void* p);
void FUN_1403f42d0(void* p);
void FUN_1403f42f0(void* p);
void FUN_1403f4310(void* p);
void FUN_1403f4330(void* p);
void FUN_1403f4350(void* p);
void FUN_1403f4370(void* p);
void FUN_1403f4390(void* p);
void FUN_1403f43b0(void* p);
void FUN_1403f43d0(void* p);
void FUN_1403f43f0(void* p);
void FUN_1403f4410(void* p);
void FUN_1403f4430(void* p);
void FUN_1403f4450(void* p);
void FUN_1403f4470(void* p);
void FUN_1403f4490(void* p);
void FUN_1403f44b0(void* p);
void FUN_1403f44d0(void* p);
void FUN_1403f44f0(void* p);
void FUN_1403f4510(void* p);
void FUN_1403f4530(void* p);
void FUN_1403f4550(void* p);
void FUN_1403f4570(void* p);
void FUN_1403f4590(void* p);
void FUN_1403f45b0(void* p);
void FUN_1403f45d0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4600(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4630(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4660(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4690(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f46c0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f46f0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4720(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4750(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4780(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f47b0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f47e0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4810(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4840(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4870(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f48a0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f48d0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4900(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4930(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4960(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4990(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f49c0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f49f0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4a20(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4a50(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4a80(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4ab0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4ae0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4b10(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4b40(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4b70(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4ba0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4bd0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4c00(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4c30(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4c60(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4c90(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4cc0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4cf0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4d20(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4d50(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4d80(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4db0(Unk_BoxedPointer* p, void* pUnused);
void FUN_1403f4de0(Unk_BoxedPointer* p, void* pUnused);
class CPtred   // C3: member view for the former free stand-ins
{
public:
    static void AddRefPtred(class CPtred*);
};

// ---------------------------------------------------------------------------
// the 134 entries, in address order
// ---------------------------------------------------------------------------

// @0x1403f37d0
void FUN_1403f37d0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f45d0(p, 0);
}

// @0x1403f3800
void FUN_1403f3800(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4600(p, 0);
}

// @0x1403f3830
void FUN_1403f3830(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4630(p, 0);
}

// @0x1403f3860
void FUN_1403f3860(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4660(p, 0);
}

// @0x1403f3890
void FUN_1403f3890(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4690(p, 0);
}

// @0x1403f38c0
void FUN_1403f38c0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f46c0(p, 0);
}

// @0x1403f38f0
void FUN_1403f38f0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f46f0(p, 0);
}

// @0x1403f3920
void FUN_1403f3920(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4720(p, 0);
}

// @0x1403f3950
void FUN_1403f3950(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4750(p, 0);
}

// @0x1403f3980
void FUN_1403f3980(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4780(p, 0);
}

// @0x1403f39b0
void FUN_1403f39b0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f47b0(p, 0);
}

// @0x1403f39e0
void FUN_1403f39e0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f47e0(p, 0);
}

// @0x1403f3a10
void FUN_1403f3a10(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4810(p, 0);
}

// @0x1403f3a40
void FUN_1403f3a40(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4840(p, 0);
}

// @0x1403f3a70
void FUN_1403f3a70(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4870(p, 0);
}

// @0x1403f3aa0
void FUN_1403f3aa0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f48a0(p, 0);
}

// @0x1403f3ad0
void FUN_1403f3ad0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f48d0(p, 0);
}

// @0x1403f3b00
void FUN_1403f3b00(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4900(p, 0);
}

// @0x1403f3b30
void FUN_1403f3b30(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4930(p, 0);
}

// @0x1403f3b60
void FUN_1403f3b60(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4960(p, 0);
}

// @0x1403f3b90
void FUN_1403f3b90(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4990(p, 0);
}

// @0x1403f3bc0
void FUN_1403f3bc0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f49c0(p, 0);
}

// @0x1403f3bf0
void FUN_1403f3bf0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f49f0(p, 0);
}

// @0x1403f3c20
void FUN_1403f3c20(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4a20(p, 0);
}

// @0x1403f3c50
void FUN_1403f3c50(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4a50(p, 0);
}

// @0x1403f3c80
void FUN_1403f3c80(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4a80(p, 0);
}

// @0x1403f3cb0
void FUN_1403f3cb0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4ab0(p, 0);
}

// @0x1403f3ce0
void FUN_1403f3ce0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4ae0(p, 0);
}

// @0x1403f3d10
void FUN_1403f3d10(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4b10(p, 0);
}

// @0x1403f3d40
void FUN_1403f3d40(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4b40(p, 0);
}

// @0x1403f3d70
void FUN_1403f3d70(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4b70(p, 0);
}

// @0x1403f3da0
void FUN_1403f3da0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4ba0(p, 0);
}

// @0x1403f3dd0
void FUN_1403f3dd0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4bd0(p, 0);
}

// @0x1403f3e00
void FUN_1403f3e00(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4c00(p, 0);
}

// @0x1403f3e30
void FUN_1403f3e30(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4c30(p, 0);
}

// @0x1403f3e60
void FUN_1403f3e60(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4c60(p, 0);
}

// @0x1403f3e90
void FUN_1403f3e90(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4c90(p, 0);
}

// @0x1403f3ec0
void FUN_1403f3ec0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4cc0(p, 0);
}

// @0x1403f3ef0
void FUN_1403f3ef0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4cf0(p, 0);
}

// @0x1403f3f20
void FUN_1403f3f20(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4d20(p, 0);
}

// @0x1403f3f50
void FUN_1403f3f50(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4d50(p, 0);
}

// @0x1403f3f80
void FUN_1403f3f80(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4d80(p, 0);
}

// @0x1403f3fb0
void FUN_1403f3fb0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4db0(p, 0);
}

// @0x1403f3fe0
void FUN_1403f3fe0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_1403f4de0(p, 0);
}

// @0x1403f4010
void FUN_1403f4010(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4030
void FUN_1403f4030(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4050
void FUN_1403f4050(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4070
void FUN_1403f4070(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4090
void FUN_1403f4090(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f40b0
void FUN_1403f40b0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f40d0
void FUN_1403f40d0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f40f0
void FUN_1403f40f0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4110
void FUN_1403f4110(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4130
void FUN_1403f4130(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4150
void FUN_1403f4150(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4170
void FUN_1403f4170(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4190
void FUN_1403f4190(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f41b0
void FUN_1403f41b0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f41d0
void FUN_1403f41d0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f41f0
void FUN_1403f41f0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4210
void FUN_1403f4210(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4230
void FUN_1403f4230(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4250
void FUN_1403f4250(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4270
void FUN_1403f4270(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4290
void FUN_1403f4290(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f42b0
void FUN_1403f42b0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f42d0
void FUN_1403f42d0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f42f0
void FUN_1403f42f0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4310
void FUN_1403f4310(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4330
void FUN_1403f4330(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4350
void FUN_1403f4350(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4370
void FUN_1403f4370(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4390
void FUN_1403f4390(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f43b0
void FUN_1403f43b0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f43d0
void FUN_1403f43d0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f43f0
void FUN_1403f43f0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4410
void FUN_1403f4410(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4430
void FUN_1403f4430(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4450
void FUN_1403f4450(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4470
void FUN_1403f4470(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4490
void FUN_1403f4490(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f44b0
void FUN_1403f44b0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f44d0
void FUN_1403f44d0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f44f0
void FUN_1403f44f0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4510
void FUN_1403f4510(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4530
void FUN_1403f4530(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4550
void FUN_1403f4550(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4570
void FUN_1403f4570(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f4590
void FUN_1403f4590(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f45b0
void FUN_1403f45b0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x1403f45d0
void FUN_1403f45d0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4010(p->m_pValue);
}

// @0x1403f4600
void FUN_1403f4600(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4030(p->m_pValue);
}

// @0x1403f4630
void FUN_1403f4630(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4050(p->m_pValue);
}

// @0x1403f4660
void FUN_1403f4660(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4070(p->m_pValue);
}

// @0x1403f4690
void FUN_1403f4690(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4090(p->m_pValue);
}

// @0x1403f46c0
void FUN_1403f46c0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f40b0(p->m_pValue);
}

// @0x1403f46f0
void FUN_1403f46f0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f40d0(p->m_pValue);
}

// @0x1403f4720
void FUN_1403f4720(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f40f0(p->m_pValue);
}

// @0x1403f4750
void FUN_1403f4750(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4110(p->m_pValue);
}

// @0x1403f4780
void FUN_1403f4780(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4130(p->m_pValue);
}

// @0x1403f47b0
void FUN_1403f47b0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4150(p->m_pValue);
}

// @0x1403f47e0
void FUN_1403f47e0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4170(p->m_pValue);
}

// @0x1403f4810
void FUN_1403f4810(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4190(p->m_pValue);
}

// @0x1403f4840
void FUN_1403f4840(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f41b0(p->m_pValue);
}

// @0x1403f4870
void FUN_1403f4870(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f41d0(p->m_pValue);
}

// @0x1403f48a0
void FUN_1403f48a0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f41f0(p->m_pValue);
}

// @0x1403f48d0
void FUN_1403f48d0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4210(p->m_pValue);
}

// @0x1403f4900
void FUN_1403f4900(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4230(p->m_pValue);
}

// @0x1403f4930
void FUN_1403f4930(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4250(p->m_pValue);
}

// @0x1403f4960
void FUN_1403f4960(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4270(p->m_pValue);
}

// @0x1403f4990
void FUN_1403f4990(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4290(p->m_pValue);
}

// @0x1403f49c0
void FUN_1403f49c0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f42b0(p->m_pValue);
}

// @0x1403f49f0
void FUN_1403f49f0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f42d0(p->m_pValue);
}

// @0x1403f4a20
void FUN_1403f4a20(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f42f0(p->m_pValue);
}

// @0x1403f4a50
void FUN_1403f4a50(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4310(p->m_pValue);
}

// @0x1403f4a80
void FUN_1403f4a80(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4330(p->m_pValue);
}

// @0x1403f4ab0
void FUN_1403f4ab0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4350(p->m_pValue);
}

// @0x1403f4ae0
void FUN_1403f4ae0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4370(p->m_pValue);
}

// @0x1403f4b10
void FUN_1403f4b10(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4390(p->m_pValue);
}

// @0x1403f4b40
void FUN_1403f4b40(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f43b0(p->m_pValue);
}

// @0x1403f4b70
void FUN_1403f4b70(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f43d0(p->m_pValue);
}

// @0x1403f4ba0
void FUN_1403f4ba0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f43f0(p->m_pValue);
}

// @0x1403f4bd0
void FUN_1403f4bd0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4410(p->m_pValue);
}

// @0x1403f4c00
void FUN_1403f4c00(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4430(p->m_pValue);
}

// @0x1403f4c30
void FUN_1403f4c30(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4450(p->m_pValue);
}

// @0x1403f4c60
void FUN_1403f4c60(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4470(p->m_pValue);
}

// @0x1403f4c90
void FUN_1403f4c90(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f44b0(p->m_pValue);
}

// @0x1403f4cc0
void FUN_1403f4cc0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f44d0(p->m_pValue);
}

// @0x1403f4cf0
void FUN_1403f4cf0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f44f0(p->m_pValue);
}

// @0x1403f4d20
void FUN_1403f4d20(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4510(p->m_pValue);
}

// @0x1403f4d50
void FUN_1403f4d50(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4530(p->m_pValue);
}

// @0x1403f4d80
void FUN_1403f4d80(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4550(p->m_pValue);
}

// @0x1403f4db0
void FUN_1403f4db0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4570(p->m_pValue);
}

// @0x1403f4de0
void FUN_1403f4de0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_1403f4590(p->m_pValue);
}
