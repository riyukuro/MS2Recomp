// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_14045b2c0: out-of-line wrappers
// of the shared "boxed pointer" family (see unit_1403f37d0.cpp), three bodies repeated per wrapped type:
//   * guarded release `if (p->m_pValue != 0) <C>(p, 0);`
//   * `FUN_14015b020(p);` - the family's shared out-of-line helper
//   * `<B>(p->m_pValue);` - unwrap the box at +8 and hand the pointer on
// All names invented from shape; only the family helper and the few unwrap targets are outside this unit.
// MS2-UNIT: unit_14045b2c0
// MS2-RANGE: 0x14045b2c0-0x14045b6e0 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

struct Unk_BoxedPointer {
    void* m_pUnused;            // +0x00
    void* m_pValue;             // +0x08 the boxed pointer the wrappers test and unwrap
};

void FUN_14045b2c0(Unk_BoxedPointer* p);
// (0x14045b2f0 is Unk_FieldPtr<ATL::CAtlList<UINT> >::AddRef, explicitly instantiated below)
void FUN_14045b320(Unk_BoxedPointer* p);
void FUN_14045b350(Unk_BoxedPointer* p);
void FUN_14045b380(Unk_BoxedPointer* p);
void FUN_14045b3b0(Unk_BoxedPointer* p);
void FUN_14045b3e0(Unk_BoxedPointer* p);
void FUN_14045b410(Unk_BoxedPointer* p);
void FUN_14045b440(void* p);
// (0x14045b460 is Unk_FieldPtr<ATL::CAtlList<UINT> >::Ref, emitted by that instantiation)
void FUN_14045b480(void* p);
void FUN_14045b4a0(void* p);
void FUN_14045b4c0(void* p);
void FUN_14045b4e0(void* p);
void FUN_14045b500(void* p);
void FUN_14045b520(void* p);
void FUN_14045b540(void* p);
void FUN_14045b560(Unk_BoxedPointer* p, void* pUnused);
// (0x14045b590 is Unk_FieldPtr<ATL::CAtlList<UINT> >::AddRefImpl, emitted by that instantiation)
void FUN_14045b5c0(Unk_BoxedPointer* p, void* pUnused);
void FUN_14045b5f0(Unk_BoxedPointer* p, void* pUnused);
void FUN_14045b620(Unk_BoxedPointer* p, void* pUnused);
void FUN_14045b650(Unk_BoxedPointer* p, void* pUnused);
void FUN_14045b680(Unk_BoxedPointer* p, void* pUnused);
void FUN_14045b6b0(Unk_BoxedPointer* p, void* pUnused);
#include <atlcoll.h>
#include "ms2/commonfiles/fieldmetatable.h"   // Unk_FieldPtr<T> (and the real CPtred)
// (0x14044cfb0 is Unk_FieldPtr<ATL::CAtlList<UINT> >::Owner, pinned in unit_14044a880)




// ---------------------------------------------------------------------------
// the 25 entries, in address order
// ---------------------------------------------------------------------------

// @0x14045b2c0
void FUN_14045b2c0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14045b560(p, 0);
}

// 0x14045b2f0 / 0x14045b590 / 0x14045b460: the real private Unk_FieldPtr<ATL::CAtlList<UINT> >::AddRef -> AddRefImpl -> Ref(Owner(m_p))
template void Unk_FieldPtr<ATL::CAtlList<UINT> >::AddRef() const;





// @0x14045b320
void FUN_14045b320(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14045b5c0(p, 0);
}

// @0x14045b350
void FUN_14045b350(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14045b5f0(p, 0);
}

// @0x14045b380
void FUN_14045b380(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14045b620(p, 0);
}

// @0x14045b3b0
void FUN_14045b3b0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14045b650(p, 0);
}

// @0x14045b3e0
void FUN_14045b3e0(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14045b680(p, 0);
}

// @0x14045b410
void FUN_14045b410(Unk_BoxedPointer* p)
{
    if (p->m_pValue != 0)
        FUN_14045b6b0(p, 0);
}

// @0x14045b440
void FUN_14045b440(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}







// @0x14045b480
void FUN_14045b480(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14045b4a0
void FUN_14045b4a0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14045b4c0
void FUN_14045b4c0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14045b4e0
void FUN_14045b4e0(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14045b500
void FUN_14045b500(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14045b520
void FUN_14045b520(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14045b540
void FUN_14045b540(void* p)
{
    CPtred::AddRefPtred((class CPtred*)(p));
}

// @0x14045b560
void FUN_14045b560(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14045b440(p->m_pValue);
}




// @0x14045b5c0
void FUN_14045b5c0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14045b4a0(p->m_pValue);
}

// @0x14045b5f0
void FUN_14045b5f0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14045b4c0(p->m_pValue);
}

// @0x14045b620
void FUN_14045b620(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14045b4e0(p->m_pValue);
}

// @0x14045b650
void FUN_14045b650(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14045b500(p->m_pValue);
}

// @0x14045b680
void FUN_14045b680(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14045b520(p->m_pValue);
}

// @0x14045b6b0
void FUN_14045b6b0(Unk_BoxedPointer* p, void* pUnused)
{
    FUN_14045b540(p->m_pValue);
}

// MS2-PIN: ?AddRef@?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@AEBAXXZ 0x14045b2f0
// MS2-PIN: ?AddRefImpl@?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@AEBAXPEAX@Z 0x14045b590
// MS2-PIN: ?Ref@?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@CAXPEAVCPtred@@@Z 0x14045b460
