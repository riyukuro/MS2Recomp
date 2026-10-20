// ms2svrptr.h - PLACEHOLDER for the exe's 16-byte intrusive smart pointer with an auto_ptr-style steal constructor
// (RTTI-less template; its COMDATs sort between CValidData and TSingleton in the units that use it). NOT an original
// header. Same layout and bodies as MS2Ptr<T> (ascript.h), but a non-const copy constructor moves: a function that
// returns its local through `return p;` picks it. Used by serverlisttable.cpp and continentregiontable.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// Argument of the creating constructor (0x1401b7b90 builds it; same shape as Unk_JobNewTag).
struct MS2SvrNewTag { explicit MS2SvrNewTag(int); };
CPtred* FUN_1401ba820(CPtred* p);       // marks a freshly allocated object (sets the count to 1)

template <class T>
class MS2SvrPtr
{
public:
    MS2SvrPtr(const MS2SvrNewTag&) { m_p = 0; Make(); }   // fresh object (itemgachaboxtable.cpp)
    MS2SvrPtr() { m_p = 0; }
    MS2SvrPtr(int) { m_p = 0; }
    MS2SvrPtr(decltype(nullptr)) { m_p = 0; }   // null literal (itemgachaboxtable.cpp: the exe's copy takes a 64-bit argument)
    MS2SvrPtr(T* p) { m_p = p; AddRef(); }
    MS2SvrPtr(const MS2SvrPtr& o) { m_p = o.m_p; AddRef(); }
    MS2SvrPtr(MS2SvrPtr& o) { m_p = o.m_p; o.m_p = 0; }   // auto_ptr-style steal (non-const lvalue); PortalRandomTargetData specializes it to copy+AddRef (portaltable.h)
    ~MS2SvrPtr() { Release(); }
    MS2SvrPtr& operator=(const MS2SvrPtr& o)
    {
        o.AddRef();
        Release();
        m_p = o.m_p;
        return *this;
    }
    MS2SvrPtr& operator=(T* p)              // assign from a raw pointer: build a temporary, swap (ugcmapsetiteminfo.cpp)
    {
        MS2SvrPtr tmp(p);
        T* old = m_p;
        m_p = tmp.m_p;
        tmp.m_p = old;
        return *this;
    }
    operator T*() const { return m_p; }
    T* operator->() const { return m_p; }
    T& operator*() const { return *m_p; }   // 0x1406f24c0 for T = CNpcShopBuyPeriod (npcshopdata.cpp)
    T* get() const { return m_p; }
    bool operator==(T* o) const { return m_p == o; }
    bool operator!() const { return m_p == 0; }   // portaltable.cpp: `if (!p)` is an out-of-line no-arg COMDAT
#ifdef MS2_SVRPTR_ASSIGN_INT
    // `p = 0` of units that call the exe's operator=(int) COMDAT (Release; return *this; e.g. 0x140f567a0 for
    // T = CIngredientContainer, uiitemexchangescrolldialog.cpp). Opt-in per unit: the other units keep operator=(T*).
    MS2SvrPtr& operator=(int) { Release(); return *this; }
#endif
private:
    void Make() { Release(); m_p = Create(0); }
    static T* Allocate(void*) { return new T; }
    static T* Create(void*) { return static_cast<T*>(FUN_1401ba820(Allocate(0))); }
    void AddRef() const { if (m_p) AddRefImpl(0); }
    void AddRefImpl(void*) const { Reference(m_p); }
    static void Reference(T* p) { CPtred::AddRefPtred(p); }
    void Release()
    {
        if (m_p)
        {
            ReleaseImpl(0);
            m_p = 0;
        }
    }
    void ReleaseImpl(void*)
    {
        if (CPtred::ReleasePtred(m_p) == 0)
        {
            Reference(m_p);
            CPtred::DeletePtred(m_p);
        }
    }

    void* m_unk_00;
    T* m_p;                             // +0x08
};
MS2_CHECK_SIZE(MS2SvrPtr<CPtred>, 0x10);
