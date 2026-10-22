// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Client reconnection structs and the outgoing-packet buffer
// (resend/capture bookkeeping). Class names are RTTI names; field and method names are invented unless said otherwise.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/stream.h"

class CGameSocket;

// TPtredDummy<T>: CPtred followed by the owned value (the smart pointer below points at the value).
#include "ms2/placeholder/tptreddummy.h"
void FUN_14015b020(CPtred*);
int FUN_140159bc0(CPtred*);
void FUN_140159ba0(CPtred*);
CPtred* FUN_1401ba820(CPtred*);

// Argument of the smart pointer's creating constructor (0x1401b7b90 builds it; same shape as Unk_PopupNewTag).
struct Unk_PktNewTag { explicit Unk_PktNewTag(int); };

// Intrusive smart pointer to the value of a TPtredDummy<T> (name invented; same shape as Unk_PopupPtr of
// client\ms2\uicommunitypopup.h, plus operator*).
template<class T> class Unk_PktPtr {
public:
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
    static void Ref(CPtred* p) { FUN_14015b020(p); }
    static T* Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
    void AddRefImpl(void*) const { Ref(Owner(m_p)); }
    void ReleaseImpl(void*) {
        CPtred* owner = Owner(m_p);
        if (FUN_140159bc0(owner) == 0) { Ref(owner); FUN_140159ba0(owner); }
    }
    void* m_00;
    T* m_p;
};

class SocketReconnectionInfo : public CPtred {
public:
    SocketReconnectionInfo();                                   // 0x140208340
    // @0x14020a6e0
    // ~SocketReconnectionInfo() is the implicit destructor at 0x14020a6e0
    int m_18, m_1c, m_20, m_24;
};
MS2_CHECK_SIZE(SocketReconnectionInfo, 0x28);

class ReconnectionOptions : public CPtred {
public:
    struct Values { int v[11]; };
    ReconnectionOptions();                                      // 0x1402083b0
    ReconnectionOptions(const ReconnectionOptions& other);      // 0x140208400
    // @0x14020a6c0
    // ~ReconnectionOptions() is the implicit destructor at 0x14020a6c0
    ReconnectionOptions& FUN_140208460(const ReconnectionOptions& other);   // operator=
    void FUN_1402084a0(COutputStream& out) const;               // 11 x Encode4
    void FUN_140208500(CInputStream& in);                       // 11 x Decode4
    Values m_values;
};
MS2_CHECK_SIZE(ReconnectionOptions, 0x48);

class ReconnectionContext : public CPtred {
public:
    ReconnectionContext();                                      // 0x140208560
    // @0x14020a660
    // ~ReconnectionContext() is the implicit destructor at 0x14020a660
    void FUN_1402085c0();                                       // Reset
    void FUN_140208610(COutputStream& out) const;
    void FUN_140208680(CInputStream& in);
    int m_18;
    CString m_20;
    int m_28;
};
MS2_CHECK_SIZE(ReconnectionContext, 0x30);

class ReconnectionContextCli : public CPtred {
public:
    ReconnectionContextCli();                                   // 0x140208720
    // @0x14020a690
    // ~ReconnectionContextCli() is the implicit destructor at 0x14020a690
    void FUN_140208780();                                       // Reset
    int m_18, m_1c, m_20, m_24;
    bool m_28;
    int m_2c;
    bool m_30;
    int m_34, m_38;
    CString m_40;
    int m_48, m_4c;
};
MS2_CHECK_SIZE(ReconnectionContextCli, 0x50);

typedef Unk_PktPtr<COutPacket> COutPacketPtr;

// Keeps the captured/pending/loopback outgoing packets of a game socket so they can be resent after a reconnect.
class COutPacketBuffer : public CPtred {
public:
    COutPacketBuffer();                                         // 0x140208830
    virtual ~COutPacketBuffer();                                // 0x1402088e0
    void FUN_140208960(CGameSocket* pSocket, COutPacket& packet);           // flush pending, then send packet
    void RetransmitClientPackets(CGameSocket* pSocket, unsigned lastSequence);
    void FUN_140208d40();                                       // Clear
    void ShrinkCapturedPackets();
    void FUN_140209050(unsigned ackSequence);                   // drop acknowledged packets
    void PushPendingPacket(COutPacket& packet);
    void SetLimit(unsigned limit);
    unsigned FUN_140209360();                                   // sequence of the oldest captured packet
    int GetSequence();                                        // current sequence
    void FUN_140209450(int enabled);
    int GetCaptureEnabled();
    void FUN_1402094b0(int value);
    void FUN_140209510(COutPacket& packet, bool bControl);      // Capture
    bool FUN_140209640(int type, bool bControl);                // IsControlPacket
    COutPacketPtr FUN_14020aaa0(COutPacket& packet);            // Clone (inline COMDAT)

    volatile int m_resending;                    // +0x18
    int m_value;                        // +0x1c
    volatile int m_captureEnabled;               // +0x20
    unsigned m_limit;                   // +0x24
    volatile unsigned m_capturedSize;            // +0x28
    unsigned m_sequence;                // +0x2c
    volatile int m_pendingSize;                  // +0x30
    volatile int m_loopbackSize;                 // +0x34
    CLockCriticalSection m_lock;        // +0x38
    ATL::CAtlList<COutPacketPtr> m_captured;    // +0x68
    ATL::CAtlList<COutPacketPtr> m_pending;     // +0x98
    ATL::CAtlList<COutPacketPtr> m_loopback;    // +0xc8
};
MS2_CHECK_SIZE(COutPacketBuffer, 0xf8);
