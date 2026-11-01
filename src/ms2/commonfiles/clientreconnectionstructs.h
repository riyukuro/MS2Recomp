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
#include "ms2/commonfiles/coutpacketptr.h"

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

// Keeps the captured/pending/loopback outgoing packets of a game socket so they can be resent after a reconnect.
class COutPacketBuffer : public CPtred {
public:
    COutPacketBuffer();                                         // 0x140208830
    virtual ~COutPacketBuffer();                                // 0x1402088e0
    void FUN_140208960(CGameSocket* pSocket, COutPacket& packet);           // flush pending, then send packet
    void RetransmitClientPackets(CGameSocket* pSocket, unsigned lastSequence);
    void Reset();                                       // Clear
    void ShrinkCapturedPackets();
    void DiscardAcked(unsigned ackSequence);                   // drop acknowledged packets
    void PushPendingPacket(COutPacket& packet);
    void SetLimit(unsigned limit);
    unsigned FUN_140209360();                                   // sequence of the oldest captured packet
    int GetSequence();                                        // current sequence
    void SetCaptureEnabled(int enabled);
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
