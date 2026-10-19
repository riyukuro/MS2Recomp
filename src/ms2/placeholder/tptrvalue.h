// tptrvalue.h - PLACEHOLDER for TPtrValue<T> (RTTI-less; the smart pointer to the value inside a TPtredDummy<T> box).
// NOT an original header. 16 bytes: +0x00 unknown, +0x08 pointer to the value (the CPtred header sits 0x18 bytes
// before the value). Copying a non-const source steals the reference (the exe's `FUN_14066ceb0`); a const copy adds
// one. Same shape as the copy in gamerankingcli.h (that header keeps its own definition; do not include both).
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/tptreddummy.h"

CPtred* FUN_1401ba820(CPtred*);            // sets the count of a fresh box to 1

// The new-object tag of the value pointer (0x1401b7b90, returns its this, no code). The name is the one the symbol
// table knows (first used by gamerankingcli.h).
struct Unk_GrNewTag
{
    explicit Unk_GrNewTag(int);
};

template <class T>
class TPtrValue
{
public:
    TPtrValue() { m_p = 0; }
    TPtrValue(int) { m_p = 0; }
    TPtrValue(const Unk_GrNewTag&) { m_p = 0; Make(); }
#ifdef MS2_TPTRVALUE_MOVE
    // maidgradejockpottable.cpp: the exe's std glue copies lvalues with the add-ref ctor and moves with the stealing one
    TPtrValue(TPtrValue&& o) { m_p = o.m_p; o.m_p = 0; }
#else
    TPtrValue(TPtrValue& o) { m_p = o.m_p; o.m_p = 0; }
#endif
    TPtrValue(const TPtrValue& o) { m_p = o.m_p; AddRef(); }
    ~TPtrValue() { Release(); }
    TPtrValue& operator=(const TPtrValue& o) { o.AddRef(); Release(); m_p = o.m_p; return *this; }
#ifndef MS2_TPTRVALUE_ASSIGN_VIA_TEMP
    TPtrValue& operator=(const Unk_GrNewTag&) { Make(); return *this; }
#endif
    // MS2_TPTRVALUE_ASSIGN_VIA_TEMP (opt-in per unit; itemdefaultdata.cpp): `p = Unk_GrNewTag(0)` converts through the tag
    // ctor into a temporary and assigns it (ctor 0x140586ba0 + operator= 0x140587320), with no Make() call.
    TPtrValue& operator=(int) { Release(); return *this; }   // `m_ptr = 0` (0x140517ee0 for CWinHttpClient, imagehttpclient.cpp)
    T* operator->() const { return m_p; }
    T& operator*() const { return *m_p; }       // 0x140689c10 for T = CAtlArray<double> (maidgradejockpottable.cpp)
    T* get() const { return m_p; }      // `if (spList)` (0x140d37f30 for the item loader's lists)
#ifdef MS2_TPTRVALUE_ASSIGN_VIA_TEMP
    // itemdefaultdata.cpp: `spList ? spList->GetCount() : 0` and `if (spList && ...)` (the bool byte) convert through this
    // getter (0x140587460 for T = CAtlArray<TPtr<DefaultItemData>>).
    operator T*() const { return m_p; }
#endif
    bool operator!() const { return m_p == 0; }
    bool operator==(T* p) const { return m_p == p; }

private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    void AddRefImpl(void*) const { Reference(Owner(m_p)); }
    static void Reference(TPtredDummy<T>* p) { CPtred::AddRefPtred(p); }
    void Make() { Release(); m_p = Create(0); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    void ReleaseImpl(void*)
    {
        TPtredDummy<T>* owner = Owner(m_p);
        if (CPtred::ReleasePtred(owner) == 0) {
            Reference(owner);
            CPtred::DeletePtred(owner);
        }
    }
    static TPtredDummy<T>* Allocate(void*) { return new TPtredDummy<T>(); }
    static T* Value(TPtredDummy<T>* p) { return p == 0 ? 0 : &p->value; }
    static TPtredDummy<T>* Owner(T* p) { return p == 0 ? 0 : CONTAINING_RECORD(p, TPtredDummy<T>, value); }
    static T* Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }

    void* m_00;
    T* m_p;
};
