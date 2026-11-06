// tptr.h - PLACEHOLDER for TPtr<T> (real name from RTTI template arguments, e.g. TPtr<struct TMarketBillDataParam>).
// NOT an original header. An 8-byte intrusive pointer: ~TPtr() is `if (m_p) m_p->vfunc_2()` (release through the
// pointee's slot 2), e.g. 0x140a5a8c0. Passed by value in virtual slots (the callee destroys it). Declarations only,
// except TPtr(T*): inline, so callers emit their own COMDAT (the exe ICF-folds it with CComPtrBase<T>::CComPtrBase(T*)).
#pragma once

#include "ms2/ms2layout.h"

// The intrusive pointee as TPtr sees it: AddRef is vftable slot 1, Release slot 2.
struct Unk_TPtrPointee
{
    virtual void vfunc_0();
    virtual void AddRef();
    virtual void Release();
};

template <class T>
class TPtr
{
public:
    TPtr(const TPtr& o);
    // 0x140aac040 for T = PC (scenestategame OnAddUser): the CComPtrBase(T*) shape, folded with it in the exe
    TPtr(T* p) throw()
    {
        m_p = p;
        if (m_p != 0)
            ((Unk_TPtrPointee*)m_p)->AddRef();
    }
    TPtr& operator=(T* p);              // 0x141746d10 for T = PC (inline COMDAT, defined by scenestategame.cpp)
    ~TPtr();
    T* get() const;
    T* operator->() const;
    bool operator==(T* p) const;        // 0x140c206b0 for T = PCBase (inline COMDAT, uihideandseekresultdialog.cpp)

private:
    T* m_p;                             // +0x00
};
