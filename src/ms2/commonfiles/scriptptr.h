// scriptptr.h - the handles of the talk script contents and the choice row, split out of scriptcontent.h and talkscript.h
// so the read-only view src/ms2/placeholder/cinematiccontent.h can share them. Header name assumed.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// The 16-byte intrusive smart pointer (pointee at +8) of the content classes.
template<class T> class Unk_ScriptPtr {
public:
    Unk_ScriptPtr() : p(0) {}
    Unk_ScriptPtr(int) : p(0) {}
    Unk_ScriptPtr(T* value) : p(value) { AddRef(); }
    Unk_ScriptPtr(const Unk_ScriptPtr& o) : p(o.p) { AddRef(); }
    Unk_ScriptPtr(Unk_ScriptPtr&& o) : p(o.p) { o.p = 0; }    // `return local;` moves (0x140859b90 for CTalkScript)
    ~Unk_ScriptPtr() { Release(); }
    Unk_ScriptPtr& operator=(int) { Release(); return *this; }
    Unk_ScriptPtr& operator=(T* value) { Unk_ScriptPtr temp(value); T* old=p; p=temp.p; temp.p=old; return *this; }
    Unk_ScriptPtr& operator=(const Unk_ScriptPtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
    bool operator==(T* o) const { return p == o; }
    T* get() const { return p; }
    T* operator->() const { return p; }
    bool IsNull() const { return p == 0; }                  // 0x14085a420 for CTalkScript
private:
    void AddRef() const { if(p) AddRefImpl(0); }
    static void AddRefObject(T* value) { CPtred::AddRefPtred(reinterpret_cast<CPtred*>(value)); }
    void AddRefImpl(void*) const { AddRefObject(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(CPtred::ReleasePtred(reinterpret_cast<CPtred*>(p))==0) { AddRefObject(p); CPtred::DeletePtred(reinterpret_cast<CPtred*>(p)); } }
    void* pad_00; T* p;
};

// One choice of a talk page (0x18): the shown text and the two jump targets.
struct Unk_ScriptChoice {
    CStringW m_text;                        // +0x00 "text"
    CStringA m_goto;                        // +0x08 "goto"
    CStringA m_gotoFail;                    // +0x10 "gotoFail"
};
MS2_CHECK_SIZE(Unk_ScriptChoice, 0x18);

// A second instance of the content pointer (own AddRef/AddRefImpl COMDATs in the exe, 0x14085f0f0).
template<class T> class Unk_TalkContentPtr {
public:
    Unk_TalkContentPtr() : p(0) {}
    Unk_TalkContentPtr(int) : p(0) {}
    Unk_TalkContentPtr(T* value) : p(value) { AddRef(); }
    Unk_TalkContentPtr(const Unk_TalkContentPtr& o) : p(o.p) { AddRef(); }
    ~Unk_TalkContentPtr() { Release(); }
    Unk_TalkContentPtr& operator=(int) { Release(); return *this; }
    Unk_TalkContentPtr& operator=(T* value) { Unk_TalkContentPtr temp(value); T* old=p; p=temp.p; temp.p=old; return *this; }
    Unk_TalkContentPtr& operator=(const Unk_TalkContentPtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
    bool operator==(T* o) const { return p == o; }
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
