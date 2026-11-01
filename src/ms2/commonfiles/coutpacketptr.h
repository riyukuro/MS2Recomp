// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The intrusive smart pointer of the outgoing packets,
// split out of clientreconnectionstructs.h so headers can use COutPacketPtr without COutPacketBuffer.
#pragma once
#include <stddef.h>
#include "ms2/placeholder/cptred.h"

class COutPacket;


// TPtredDummy<T>: CPtred followed by the owned value (the smart pointer below points at the value).
#include "ms2/placeholder/tptreddummy.h"
CPtred* FUN_1401ba820(CPtred*);

// Argument of the smart pointer's creating constructor (0x1401b7b90 builds it; same shape as Unk_PopupNewTag).
struct Unk_PktNewTag { explicit Unk_PktNewTag(int); };

// Intrusive smart pointer to the value of a TPtredDummy<T> (name invented; same shape as Unk_PopupPtr of
// client\ms2\uicommunitypopup.h, plus operator*).
template<class T> class Unk_PktPtr {
public:
    Unk_PktPtr(int) : m_p(0) {}
    Unk_PktPtr(Unk_PktPtr&& p) : m_p(p.m_p) { p.m_p = 0; }
    Unk_PktPtr(const Unk_PktPtr& p) : m_p(p.m_p) { AddRef(); }
    Unk_PktPtr(const Unk_PktNewTag&) : m_p(0) { Make(); }
    ~Unk_PktPtr() { Release(); }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
    T& operator*() const { return *m_p; }
private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    void Make() { Release(); m_p = Create(0); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    static TPtredDummy<T>* Allocate(void*) { return new TPtredDummy<T>(); }
    static T* Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
    static TPtredDummy<T>* Owner(T* p) { return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value)); }
    static void Ref(CPtred* p) { CPtred::AddRefPtred(p); }
    static T* Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
    void AddRefImpl(void*) const { Ref(Owner(m_p)); }
    void ReleaseImpl(void*) {
        CPtred* owner = Owner(m_p);
        if (CPtred::ReleasePtred(owner) == 0) { Ref(owner); CPtred::DeletePtred(owner); }
    }
    void* m_00;
    T* m_p;
};

typedef Unk_PktPtr<COutPacket> COutPacketPtr;
