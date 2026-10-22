// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Client reconnection structs and COutPacketBuffer; also the
// first instantiation of COutPacket's inline members (commonfiles/packet.h).
// MS2-UNIT: commonfiles\clientreconnectionstructs.cpp
// MS2-RANGE: 0x140208340-0x14020c3a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\clientreconnectionstructs.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "clientreconnectionstructs.h"
#include "packet.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void FUN_141267410(CGameSocket* pSocket, COutPacket& packet);     // CGameSocket::Send (client\ms2\gamesocket.cpp)

// Logger singleton: Log*(account, character, category, format, args...) forwards to CLogString::FUN_140653550 / 690.
class Unk_CrsLog : public CLogString {
public:
#define MS2_CRS_LOG_WRAP(n, Name, Target) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline void Name(unsigned __int64 a, unsigned __int64 b, int category, const wchar_t* format, FMT_GEN(n, FMT_MAKE_ARG)) \
    { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, FMT_MAKE_REF_wchar_t)}; \
        Target(a, b, category, format, fmt::ArgList(fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
    MS2_CRS_LOG_WRAP(3, Log, FUN_140653550)
    MS2_CRS_LOG_WRAP(4, Log, FUN_140653550)
    MS2_CRS_LOG_WRAP(4, LogB, FUN_140653690)
};
Unk_CrsLog* FUN_140166440();

// @0x140208340
SocketReconnectionInfo::SocketReconnectionInfo() { m_18 = 0; m_1c = 0; m_20 = 0; m_24 = 0; }
// @0x1402083b0
ReconnectionOptions::ReconnectionOptions() { memset(&m_values, 0, sizeof(m_values)); }
// @0x140208400
ReconnectionOptions::ReconnectionOptions(const ReconnectionOptions& other) : CPtred() { m_values = other.m_values; }
// @0x140208460
ReconnectionOptions& ReconnectionOptions::FUN_140208460(const ReconnectionOptions& other) { m_values = other.m_values; return *this; }
// @0x1402084a0
void ReconnectionOptions::FUN_1402084a0(COutputStream& out) const { for (int i = 0; i < 11; ++i) out.WriteInt32(m_values.v[i]); }
// @0x140208500
void ReconnectionOptions::FUN_140208500(CInputStream& in) { for (int i = 0; i < 11; ++i) m_values.v[i] = in.ReadInt32(); }
// @0x140208560
ReconnectionContext::ReconnectionContext() { FUN_1402085c0(); }
// @0x1402085c0
void ReconnectionContext::FUN_1402085c0() { m_18 = 0; m_20 = ""; m_28 = 0; }
// @0x140208610
void ReconnectionContext::FUN_140208610(COutputStream& out) const { out.WriteInt32(m_18); out.WriteString(m_20); out.WriteInt32(m_28); }
// @0x140208680
void ReconnectionContext::FUN_140208680(CInputStream& in) { m_18 = in.ReadInt32(); m_20 = in.ReadString(); m_28 = in.ReadInt32(); }
// @0x140208720
ReconnectionContextCli::ReconnectionContextCli() { FUN_140208780(); }
// @0x140208780
void ReconnectionContextCli::FUN_140208780()
{
    m_18 = 0; m_1c = 0; m_20 = 0; m_24 = 0; m_28 = false; m_2c = 0; m_34 = 0; m_38 = 0;
    m_40 = "";
    m_48 = 0; m_30 = false; m_4c = 0;
}
// @0x140208830
COutPacketBuffer::COutPacketBuffer() : m_captured(10), m_pending(10), m_loopback(10) { FUN_140208d40(); }
// @0x1402088e0
COutPacketBuffer::~COutPacketBuffer() {}
// @0x140208960
void COutPacketBuffer::FUN_140208960(CGameSocket* pSocket, COutPacket& packet)
{
    MS2_ASSERT_AT(0x10a, pSocket != NULL);
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else {
        for (POSITION pos = m_pending.GetHeadPosition(); pos != NULL; m_pending.GetNext(pos)) {
            COutPacketPtr& pending = m_pending.GetAt(pos);
            FUN_140209510(*pending, false);
            FUN_141267410(pSocket, *pending);
        }
        m_pending.RemoveAll();
        if (packet.FUN_14020bc40() == 0) FUN_140209510(packet, false);
        FUN_141267410(pSocket, packet);
    }
}
// @0x140208ab0
void COutPacketBuffer::RetransmitClientPackets(CGameSocket* pSocket, unsigned lastSequence)
{
    MS2_ASSERT_AT(0x122, pSocket != NULL);
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else {
        m_resending = 1;
        unsigned newSequence = lastSequence;
        COutPacket ack(static_cast<int>(SendOp::ReconnectUnk), 0);
        ack.WriteInt32(lastSequence);
        FUN_141267410(pSocket, ack);
        for (POSITION pos = m_captured.GetHeadPosition(); pos != NULL; m_captured.GetNext(pos)) {
            COutPacketPtr& captured = m_captured.GetAt(pos);
            if (captured->FUN_14020ba00() <= lastSequence) continue;
            ++newSequence;
            FUN_140166440()->Log(0, 0, 0x85, L"{0}. type={1} seqOld={2}, seqNew={3}", L"COutPacketBuffer::RetransmitClientPackets",
                                 captured->FUN_14020ba20(), captured->FUN_14020ba00(), newSequence);
            captured->FUN_14020c070(newSequence);
            FUN_141267410(pSocket, *captured);
        }
        COutPacket done(static_cast<int>(SendOp::FinalizeReconnect), 0);
        done.WriteInt32(m_sequence);
        FUN_141267410(pSocket, done);
        m_resending = 0;
    }
}
// @0x140208d40
void COutPacketBuffer::FUN_140208d40()
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else {
        m_resending = 0; m_value = 0; m_captureEnabled = 0; m_limit = 0; m_capturedSize = 0;
        m_pendingSize = 0; m_loopbackSize = 0; m_sequence = 0;
        m_captured.RemoveAll();
        m_pending.RemoveAll();
        m_loopback.RemoveAll();
    }
}
// @0x140208e30
void COutPacketBuffer::ShrinkCapturedPackets()
{
    if (m_captureEnabled == 0) {
        if (m_capturedSize != 0) {
            if (Unk_LockGuard guard = m_lock) { __assume(0); } else { m_captured.RemoveAll(); m_capturedSize = 0; }
        }
    } else {
        unsigned limit = m_limit;
        unsigned shrink = limit / 2;
        if (m_capturedSize < limit) return;
        if (Unk_LockGuard guard = m_lock) { __assume(0); } else {
            FUN_140166440()->LogB(0, 0, 0x85, L"{0}. currSize={1} limit={2} shrink={3}", L"COutPacketBuffer::ShrinkCapturedPackets",
                                  m_capturedSize, limit, shrink);
            while (m_capturedSize > shrink && !m_captured.IsEmpty()) {
                COutPacketPtr packet = m_captured.RemoveHead();
                MS2_ASSERT_AT(0x177, packet.get() != NULL);
                m_capturedSize -= packet->FUN_14020b9f0();
            }
        }
    }
}
// @0x140209050
void COutPacketBuffer::FUN_140209050(unsigned ackSequence)
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else {
        while (!m_captured.IsEmpty()) {
            POSITION posHead = m_captured.GetHeadPosition();
            POSITION pos = posHead;
            m_captured.GetNext(pos);
            COutPacketPtr& head = m_captured.GetAt(posHead);
            if (head->FUN_14020ba00() > ackSequence) break;
            if (pos == NULL) break;
            COutPacketPtr& next = m_captured.GetAt(pos);
            if (next->FUN_14020ba00() > ackSequence) break;
            m_capturedSize -= head->FUN_14020b9f0();
            m_captured.RemoveHeadNoReturn();
        }
    }
}
// @0x1402091b0
void COutPacketBuffer::PushPendingPacket(COutPacket& packet)
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else {
        COutPacketPtr copy = FUN_14020aaa0(packet);
        if (packet.FUN_14020bc40() != 0) {
            m_loopbackSize += copy->FUN_14020b9f0();
            m_loopback.AddTail(copy);
            FUN_140166440()->Log(0, 0, 0x85, L"{0}[line={1}] m_pendingLoopbackPackets(type={2})", L"COutPacketBuffer::PushPendingPacket",
                                 MS2_LINE(0x219), packet.FUN_14020ba20());
        } else {
            m_pendingSize += copy->FUN_14020b9f0();
            m_pending.AddTail(copy);
        }
    }
}
// @0x140209340
void COutPacketBuffer::SetLimit(unsigned limit) { m_limit = limit; }
// @0x140209360
unsigned COutPacketBuffer::FUN_140209360()
{
    if (m_capturedSize == 0) return 0;
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else {
        if (m_captured.IsEmpty()) return 0;
        return m_captured.GetHead()->FUN_14020ba00();
    }
}
// @0x140209430
int COutPacketBuffer::GetSequence() { return m_sequence; }
// @0x140209450
void COutPacketBuffer::FUN_140209450(int enabled)
{
    m_captureEnabled = enabled;
    if (enabled == 0) ShrinkCapturedPackets();
}
// @0x140209490
int COutPacketBuffer::GetCaptureEnabled() { return m_captureEnabled; }
// @0x1402094b0
void COutPacketBuffer::FUN_1402094b0(int value)
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else m_value = value;
}
// @0x140209510
void COutPacketBuffer::FUN_140209510(COutPacket& packet, bool bControl)
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else if (m_resending == 0) {
        ++m_sequence;
        packet.FUN_14020c070(m_sequence);
        if (m_captureEnabled != 0) {
            if (!FUN_140209640(packet.FUN_14020ba20(), bControl)) {
                COutPacketPtr copy = FUN_14020aaa0(packet);
                m_capturedSize += copy->FUN_14020b9f0();
                m_captured.AddTail(copy);
            }
        }
    }
}
// @0x140209640
bool COutPacketBuffer::FUN_140209640(int type, bool bControl)
{
    if (bControl == 1) {
        switch (type) { case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: return true; }
    } else {
        switch (type) { case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: return true; }
    }
    return false;
}

// @0x14020aaa0
COutPacketPtr COutPacketBuffer::FUN_14020aaa0(COutPacket& packet)
{
    COutPacketPtr copy(Unk_PktNewTag(0));
    copy->FUN_140710740(packet.FUN_14020ba20(), packet.FUN_14020bc40(), false);
    copy->FUN_14020c070(packet.FUN_14020ba00());
    copy->FUN_14020c090(packet.FUN_14020ba10());
    copy->FUN_14020aa30(packet, 0);
    return copy;
}

// Hooks (client replaces the exe bodies with these).
MS2_REPLACE_METHOD(0x140208460, ReconnectionOptions, FUN_140208460, 45, 0x017AEA6A);
MS2_REPLACE_METHOD(0x1402084A0, ReconnectionOptions, FUN_1402084a0, 88, 0xA22007A0);
MS2_REPLACE_METHOD(0x140208500, ReconnectionOptions, FUN_140208500, 78, 0xDC37A21F);
MS2_REPLACE_METHOD(0x1402085C0, ReconnectionContext, FUN_1402085c0, 63, 0xAD914FF8);
MS2_REPLACE_METHOD(0x140208610, ReconnectionContext, FUN_140208610, 105, 0x82442E16);
MS2_REPLACE_METHOD(0x140208680, ReconnectionContext, FUN_140208680, 147, 0x83A5348B);
MS2_REPLACE_METHOD(0x140208780, ReconnectionContextCli, FUN_140208780, 165, 0x6B519DF5);
MS2_REPLACE_METHOD(0x140208960, COutPacketBuffer, FUN_140208960, 326, 0xF5D9EE98);
MS2_REPLACE_METHOD(0x140208AB0, COutPacketBuffer, RetransmitClientPackets, 641, 0xB1AE3AD4);
MS2_REPLACE_METHOD(0x140208D40, COutPacketBuffer, FUN_140208d40, 227, 0xA4669931);
MS2_REPLACE_METHOD(0x140208E30, COutPacketBuffer, ShrinkCapturedPackets, 535, 0xC7874AD2);
MS2_REPLACE_METHOD(0x140209050, COutPacketBuffer, FUN_140209050, 337, 0x7D8B5E33);
MS2_REPLACE_METHOD(0x1402091B0, COutPacketBuffer, PushPendingPacket, 381, 0xC82B70A7);
MS2_REPLACE_METHOD(0x140209340, COutPacketBuffer, SetLimit, 22, 0x5ED7A56F);
MS2_REPLACE_METHOD(0x140209430, COutPacketBuffer, GetSequence, 14, 0x6A78E4AB);
MS2_REPLACE_METHOD(0x140209450, COutPacketBuffer, FUN_140209450, 47, 0x92F6C3F9);
MS2_REPLACE_METHOD(0x140209490, COutPacketBuffer, GetCaptureEnabled, 14, 0xA25B27BF);
MS2_REPLACE_METHOD(0x1402094B0, COutPacketBuffer, FUN_1402094b0, 88, 0x0208595C);
MS2_REPLACE_METHOD(0x140209510, COutPacketBuffer, FUN_140209510, 284, 0xEA511BF5);
MS2_REPLACE_METHOD(0x140209640, COutPacketBuffer, FUN_140209640, 90, 0x6996CB7F);

MS2_EMIT_CRT_MEMMOVE_S();
