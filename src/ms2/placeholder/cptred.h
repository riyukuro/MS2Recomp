// cptred.h - CPtred (RTTI .?AVCPtred@@, vftable 0x142ce54a0, 1 slot), the intrusively reference-counted base of
// ~2,244 game classes. NOT an original header (name assumed); recovered from the first .text$mn obj
// (?\achievecondition.cpp, 0x1401580a0-0x14015b490), which instantiated all of CPtred's inline functions.
//
// Layout (0x18): vftable, the reference count at +0x08 (LONG, interlocked), a pointer at +0x10 (zeroed by the ctor,
// not touched by any CPtred code; unknown).
// Ctor 0x140159740 and dtor 0x140159840 are defined (out of line) in src/ms2/commonfiles/achievecondition.cpp so
// that units deriving from CPtred do not emit CPtred's vftable / deleting dtor COMDATs of their own.
//
// Reference counting. The smart pointer (MS2Ptr<T>, ascript.h; real name probably TPtr<T>) calls three
// non-template helpers on its pointee. Their names are invented; done units declare the same functions as
// `void FUN_14015b020(CPtred*)`, `int FUN_140159bc0(CPtred*)`, `void FUN_140159ba0(CPtred*)` (same ABI, same VAs):
//   AddRefPtred(p)   0x14015b020: InterlockedIncrement(&p->m_nRef)
//   ReleasePtred(p)  0x140159bc0 -> 0x14015b1d0 -> 0x14015b1f0: InterlockedDecrement, returns the new count
//   DeletePtred(p)   0x140159ba0 -> 0x14015b0a0 -> 0x14015b0c0: `delete p` (virtual deleting dtor)
// The pointer's per-T ReleaseImpl is `if (ReleasePtred(m_p) == 0) { Reference(m_p); DeletePtred(m_p); }`.
#pragma once

#include <intrin.h>

#include "ms2/ms2layout.h"

class CPtred
{
public:
    CPtred();                           // 0x140159740
    // Copying a value creates fresh reference bookkeeping, as proved by the copy ctor body.
    // @0x1401d27b0
    CPtred(const CPtred&) : m_nRef(0), m_pad_10(0) {}
    // Assigning a value keeps this object's own reference bookkeeping (the implicit operator= copied the count).
    // @0x1404efd80
    CPtred& operator=(const CPtred&) { return *this; }
    virtual ~CPtred();                  // slot 0 (??_G 0x140159b30), dtor 0x140159840
    friend CPtred* InitRefCount(CPtred*);   // w30: sets the count to 1 (fieldbanner unit, 0x1401ba820)

    // Interlocked helpers on the count (ATL CComMultiThreadModel::Increment/Decrement shape).
    // @0x14015a340
    static long InterlockedInc(long* p) { return _InterlockedIncrement(p); }
    // @0x140159d50
    static long InterlockedDec(long* p) { return _InterlockedDecrement(p); }

    // @0x14015b020
    static void AddRefPtred(CPtred* p) { InterlockedInc(&p->m_nRef); }
    // @0x140159bc0
    static int ReleasePtred(CPtred* p) { return p->ReleaseRef(); }
    // @0x140159ba0
    static void DeletePtred(CPtred* p) { DeletePtredImpl(p); }

    // @0x14015b1d0
    int ReleaseRef() { return DecRef(); }
    // @0x14015b1f0
    int DecRef() { return InterlockedDec(&m_nRef); }
    // @0x14015b0a0
    static void DeletePtredImpl(CPtred* p) { DeleteObject(p); }
    // @0x14015b0c0
    static void DeleteObject(CPtred* p) { delete p; }

private:
    MS2_LAYOUT_FRIEND;
    long m_nRef;                        // +0x08 reference count
    void* m_pad_10;                     // +0x10 unknown (zeroed by the ctor)
};
MS2_CHECK_SIZE(CPtred, 0x18);
MS2_CHECK_OFFSET(CPtred, m_nRef, 0x08);
