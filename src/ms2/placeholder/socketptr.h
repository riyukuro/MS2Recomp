// Intrusive CPtred smart pointer used by the socket layer (Unk_SocketPtr<T>), moved out of client\ms2\gamesocket.h so
// that commonfiles\packet.cpp (CPacketBuffer's parent pointer and the buffer lists) can use it. Names invented.
#pragma once
#include <cstddef>
#include "ms2/placeholder/cptred.h"
class CInPacket;
#include "ms2/placeholder/tptreddummy.h"
void FUN_14015b020(CPtred*); int FUN_140159bc0(CPtred*); void FUN_140159ba0(CPtred*);
CPtred* FUN_1401ba820(CPtred*);
// MS2-FUNCTIONAL: equivalent intrusive ownership; explicit casts and allocation temporaries differ.
template<class T> struct Unk_SocketRef {
    static __forceinline CPtred* Base(T* p) { return p; }
    static T* New(void*) { return new T; }
    static T* Create(void* p) { return static_cast<T*>(FUN_1401ba820(New(p))); }
};
// MS2-FUNCTIONAL: null-preserving conversion between the wrapper and its packet subobject.
template<> struct Unk_SocketRef<CInPacket> {
    static CPtred* Base(CInPacket* p);
    static TPtredDummy<CInPacket>* New(void*);
    static CInPacket* Value(TPtredDummy<CInPacket>* p);
    static CInPacket* Create(void* p);
};
struct Unk_SocketNew { explicit Unk_SocketNew(int) {} };
// MS2-FUNCTIONAL: nullptr overloads and typed reference helpers preserve ownership with different temporaries.
template<class T> class Unk_SocketPtr {
public:
    Unk_SocketPtr():p(0) {}
    Unk_SocketPtr(int):p(0) {}   // w30: the exe's TPtr(int) ctor (stores null; 0x1401b7a70)
    Unk_SocketPtr(const Unk_SocketNew&):p(0) { ResetNew(); }
    Unk_SocketPtr(std::nullptr_t):p(0) {}
    Unk_SocketPtr(T* v):p(v) { AddRef(); }
    Unk_SocketPtr(const Unk_SocketPtr& v):p(v.p) { AddRef(); }
    Unk_SocketPtr(Unk_SocketPtr&& v):p(v.p) { v.p=0; }
    ~Unk_SocketPtr() { Release(); }
    Unk_SocketPtr& operator=(const Unk_SocketPtr& v) { v.AddRef(); Release(); p=v.p; return *this; }
    Unk_SocketPtr& operator=(T* v) { Unk_SocketPtr tmp(v); T* old=p; p=tmp.p; tmp.p=old; return *this; }
    Unk_SocketPtr& operator=(std::nullptr_t) { Release(); return *this; }
    Unk_SocketPtr& operator=(int) { Release(); return *this; }
    Unk_SocketPtr& operator=(const Unk_SocketNew&) { ResetNew(); return *this; }
    operator T*() const { return p; }   // w117: the exe's pair== calls it (0x140789570 for Rider)
    T* get() const { return p; } T* operator->() const { return p; } T& operator*() const { return *p; }
    bool operator==(T* v) const { return p==v; }
private:
    static void Reference(CPtred* v) { FUN_14015b020(v); }
    void AddRef() const { if(p) AddRefImpl((void*)0); }
    // T derives from CPtred at offset 0: the exe passes p straight on (implicit upcast). Boxed payloads (Unk_SocketRef<T>
    // specialized) go through Base: MS2_SOCKETPTR_BOXED(T) after the specialization.
    void AddRefImpl(void*) const { Reference(p); }
    void Release() { if(p) { ReleaseImpl((void*)0); p=0; } }
    void ReleaseImpl(void*) { if(FUN_140159bc0(p)==0) { Reference(p); FUN_140159ba0(p); } }
    void ResetNew() { Release(); p=Unk_SocketRef<T>::Create((void*)0); }
    void* pad; T* p;
};
// The AddRefImpl/ReleaseImpl of a payload boxed behind its CPtred (Unk_SocketRef<T> specialized): one Base call each.
#define MS2_SOCKETPTR_BOXED(...)                                                                                        \
    template<> inline void Unk_SocketPtr<__VA_ARGS__>::AddRefImpl(void*) const                                          \
    { Reference(Unk_SocketRef<__VA_ARGS__>::Base(p)); }                                                                 \
    template<> inline void Unk_SocketPtr<__VA_ARGS__>::ReleaseImpl(void*)                                               \
    { CPtred* base=Unk_SocketRef<__VA_ARGS__>::Base(p); if(FUN_140159bc0(base)==0) { Reference(base); FUN_140159ba0(base); } }
MS2_SOCKETPTR_BOXED(CInPacket)
