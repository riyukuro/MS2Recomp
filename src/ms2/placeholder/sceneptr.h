// Placeholder (not an original header): the scene child-list smart pointer, shared by the UISceneEntity views of
// uiscenegame.h and uiscenelobbyselect.h. Name invented (RTTI TPtr<T>).
#pragma once

#include "ms2/placeholder/cptred.h"

// The 16-byte intrusive smart pointer (pointee at +8) of a scene in the child list (ctor 0x141ac79a0, copy 0x141ac7960,
// dtor 0x141ac7a00).
template<class T> class Unk_ScenePtr {
public:
    Unk_ScenePtr() : p(0) {}
    Unk_ScenePtr(T* value) : p(value) { AddRef(); }
    Unk_ScenePtr(const Unk_ScenePtr& o) : p(o.p) { AddRef(); }
    ~Unk_ScenePtr() { Release(); }
    Unk_ScenePtr& operator=(const Unk_ScenePtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
    T* get() const { return p; }
    T* operator->() const { return p; }
private:
    void AddRef() const { if(p) AddRefImpl(0); }
    static void AddRefObject(T* value) { CPtred::AddRefPtred(reinterpret_cast<CPtred*>(value)); }
    void AddRefImpl(void*) const { AddRefObject(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(CPtred::ReleasePtred(reinterpret_cast<CPtred*>(p))==0) { AddRefObject(p); CPtred::DeletePtred(reinterpret_cast<CPtred*>(p)); } }
    void* pad_00; T* p;
};
