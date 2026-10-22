// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Packet stream operators, CInPacket, COutPacket send path,
// CPacketBuffer, and the std::map / CAtlList instantiations of the networking layer.
// MS2-UNIT: commonfiles\packet.cpp
// MS2-RANGE: 0x14070f700-0x140716a40 .text$mn
// MS2-RANGE: 0x1400bbe60-0x1400bc1a0 .text$di
// MS2-PIN: ??C?$Unk_SocketPtr@VCPacketBuffer@@@@QEBAPEAVCPacketBuffer@@XZ 0x140713520
// MS2-PIN: ??D?$Unk_SocketPtr@VCPacketBuffer@@@@QEBAAEAVCPacketBuffer@@XZ 0x140713540
// MS2-PIN: ?get@?$Unk_SocketPtr@VCPacketBuffer@@@@QEBAPEAVCPacketBuffer@@XZ 0x140713570
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@I@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBU?$pair@HH@std@@I@1@XZ 0x140713580
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@I@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBU?$pair@HH@std@@I@1@XZ 0x1407135a0
// MS2-PIN: ??$?0V?$tuple@AEBU?$pair@HH@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@HH@std@@I@std@@QEAA@AEAV?$tuple@AEBU?$pair@HH@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140711050
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@I@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@I@std@@@std@@@std@@@0@AEAV10@@Z 0x140712d70
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VCPacketBuffer@@@@AEBAXPEAX@Z 0x140715470
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VCPacketBuffer@@@@AEAAXPEAX@Z 0x140716120
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\packet.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include "packet.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cpacketbuffer.h"
#include "ms2/placeholder/exception.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/buffercryptmanager.h"
#include "ms2/placeholder/cbuffercryptmanager.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- externals (bound by VA) ----------------------------------------------------------------------------------------
#include "ms2/client/ms2/networkservice.h"
unsigned FUN_140869420();                                       // millisecond clock
CString FUN_14016a600(const wchar_t*, int);                     // wide -> CString
int FUN_1401cde60(CBufferCryptManager*, unsigned char* data, int length, int connectionState, unsigned* key);   // decrypt
int FUN_1401cddd0(CBufferCryptManager*, unsigned char* data, int length, int connectionState, unsigned* key);   // encrypt
unsigned __int64 FUN_140282020(const Unk_OSNumber&);
// The byte vectors streamed by the operators below are CAtlArray<char> (a distinct instantiation from CInPacket::m_data's
// CAtlArray<unsigned char>: operator[] 0x1406c35b0 vs 0x140203bf0, both byte-identical).
int FUN_1406c3660(const ATL::CAtlArray<char>&);                       // element count
const unsigned char* FUN_1406c3630(const ATL::CAtlArray<char>&);      // data pointer (null when empty)
extern CBufferCryptManager* DAT_143aac528;
CBufferCryptManager* GetBufferCryptManager();
CNetworkService* FUN_140714f90();
CPacketBuffer* FUN_1407138b0(unsigned, const Unk_SocketNew&);

// _wassert with the original text/line where the source spelling differs from the printed text.
#define MS2_PK_ASSERT(line, text, expr) (void)((!!(expr)) || (_wassert(L##text, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))

// Serializable item of the stream operators (slot 0 writes, slot 1 reads); name invented.
class Unk_PktSerializable {
public:
    virtual void vfunc_0(COutputStream&) = 0;
    virtual void vfunc_1(CInputStream&) = 0;
};
// (a user template; its COMDAT sorts after std::forward<..>, exe 0x140712d80)
template<class T> T pkmin(T a, T b) { T r; if (a < b) r = a; else r = b; return r; }

// ---- byte-vector helpers ----------------------------------------------------------------------------------------------
// @0x140715250
void FUN_140715250(ATL::CAtlArray<char>& array, __int64 count) { array.SetCount(count, -1); }
// @0x140714db0
unsigned char* FUN_140714db0(ATL::CAtlArray<char>& array) { if (array.IsEmpty()) return 0; return (unsigned char*)&array[0]; }
// @0x140714fc0
unsigned __int64 FUN_140714fc0(const Unk_OSId& id) { return id.value; }

// ---- stream operators -------------------------------------------------------------------------------------------------
// @0x14070f700
CInputStream& FUN_14070f700(CInputStream& in, ATL::CAtlArray<char>& value)
{
    int count = in.ReadInt32();
    FUN_140715250(value, count);
    in.ReadBytes(FUN_140714db0(value), count);
    return in;
}
// @0x14070f770
CInputStream& FUN_14070f770(CInputStream& in, Unk_PktSerializable& item) { item.vfunc_1(in); return in; }
// @0x14070f7b0
CInputStream& FUN_14070f7b0(CInputStream& in, CByteBuffer& value)
{
    int count = in.ReadInt32();
    value.FUN_140715230(count);
    in.ReadBytes(value.FUN_140204eb0(), count);
    return in;
}
// @0x14070f820
COutputStream& FUN_14070f820(COutputStream& out, bool value) { out.WriteBool(value); return out; }
// @0x14070f860
COutputStream& FUN_14070f860(COutputStream& out, unsigned char value) { out.WriteUInt8(value); return out; }
// @0x14070f8a0
COutputStream& FUN_14070f8a0(COutputStream& out, short value) { out.WriteInt16(value); return out; }
// @0x14070f8e0
COutputStream& FUN_14070f8e0(COutputStream& out, unsigned short value) { out.WriteInt16(value); return out; }
// @0x14070f920
COutputStream& FUN_14070f920(COutputStream& out, int value) { out.WriteInt32(value); return out; }
// @0x14070f960
COutputStream& FUN_14070f960(COutputStream& out, long value) { out.WriteInt32(value); return out; }
// @0x14070f9a0
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned int value) { out.WriteInt32(value); return out; }
// @0x14070f9e0
COutputStream& FUN_14070f9e0(COutputStream& out, __int64 value) { out.WriteInt64(value); return out; }
// @0x14070fa20
COutputStream& FUN_14070fa20(COutputStream& out, unsigned __int64 value) { out.WriteInt64(value); return out; }
// @0x14070fa60
COutputStream& FUN_14070fa60(COutputStream& out, float value) { out.WriteFloat(value); return out; }
// @0x14070faa0
COutputStream& FUN_14070faa0(COutputStream& out, const CString& value) { out.WriteString(value); return out; }
// @0x14070fae0
COutputStream& FUN_14070fae0(COutputStream& out, const CStringW& value) { out.WriteUnicodeString(value); return out; }
// @0x14070fb20
COutputStream& FUN_14070fb20(COutputStream& out, const Unk_OSId& value) { out.WriteInt64(FUN_140714fc0(value)); return out; }
// @0x14070fb70
COutputStream& FUN_14070fb70(COutputStream& out, const Unk_OSNumber& value) { out.WriteInt64(FUN_140282020(value)); return out; }
// @0x14070fbc0
COutputStream& FUN_14070fbc0(COutputStream& out, const ATL::CAtlArray<char>& value)
{
    out.WriteInt32(FUN_1406c3660(value));
    out.WriteBytes(FUN_1406c3630(value), FUN_1406c3660(value));
    return out;
}
// @0x14070fc40
COutputStream& FUN_14070fc40(COutputStream& out, const Unk_PktSerializable& item) { const_cast<Unk_PktSerializable&>(item).vfunc_0(out); return out; }
// @0x14070fc80
COutputStream& FUN_14070fc80(COutputStream& out, CByteBuffer& value)
{
    out.WriteInt32(value.GetLength());
    out.WriteBytes(value.FUN_140204eb0(), value.GetLength());
    return out;
}

// ---- CInPacket --------------------------------------------------------------------------------------------------------
// @0x14070fd00
CInPacket::CInPacket(CInPacket& iPacket)
{
    MS2_ASSERT_AT(0xdc, iPacket.m_nState == RS_COMPLETED);
    m_flags = iPacket.m_flags;
    m_nState = RS_COMPLETED;
    m_data.SetCount(iPacket.m_length, -1);
    memcpy(&m_data[0], &iPacket.m_data[0], iPacket.m_length);
    m_length = iPacket.m_length;
    m_opcode = iPacket.m_opcode;
    m_40 = iPacket.m_40;
    m_packetLength = iPacket.m_packetLength;
    m_offset = iPacket.m_offset;
    iPacket.FUN_140713940();
}
// @0x14070fe80
int CInPacket::FUN_14070fe80() { FUN_140715280(6); return (unsigned short)FUN_1407140a0(); }
// MS2-FUNCTIONAL: bool temp slot differs
// @0x14070feb0
bool CInPacket::ReadBool() { return ReadUInt8() != 0; }
// MS2-FUNCTIONAL: receive state machine: local layout / temp order differs
// @0x14070ff00
int CInPacket::FUN_14070ff00(Unk_SocketPtr<CPacketBuffer>* buffer, int* stateBefore, int hasSequence)
{
    if (stateBefore != NULL) *stateBefore = m_nState;
    char* data = (*buffer).get()->FUN_140713530();
    int remaining = (**buffer).GetSize();
    if (m_nState == RS_HEADER) {
        unsigned headerLen = 6;
        if (hasSequence != 0) headerLen = 10;
        MS2_PK_ASSERT(0x105, "headerLen > m_uLength", headerLen > (unsigned)m_length);
        unsigned count = pkmin<unsigned>(remaining, headerLen - m_length);
        FUN_140715120(data, count);
        if (headerLen <= (unsigned)m_length) {
            m_nState = RS_DATA;
            m_opcode = ReadInt16();
            m_packetLength = ReadInt32();
            if (hasSequence != 0) {
                m_40 = ReadInt32();
                m_length -= 4;
                m_offset -= 4;
            }
        }
        remaining -= count;
        if (remaining == 0) {
            *buffer = 0;
            return m_nState;
        }
        data += count;
    }
    MS2_PK_ASSERT(0x11c, "m_nState == RS_DATA", m_nState == RS_DATA);
    int count = pkmin<unsigned>(remaining, (m_packetLength + 6) - m_length);
    FUN_140715120(data, count);
    if (m_packetLength + 6U <= (unsigned)m_length) m_nState = RS_COMPLETED;
    remaining -= count;
    CPacketBuffer* rest;
    if (remaining == 0) {
        rest = 0;
    } else {
        Unk_SocketNew unused(0);
        int offset = (**buffer).GetSize();
        offset -= remaining;
        rest = (**buffer).FUN_140715390(offset, remaining, unused);
    }
    *buffer = rest;
    return m_nState;
}
// @0x140710280
void CInPacket::FUN_140710280(int connectionState, unsigned* key)
{
    FUN_1401cde60(GetBufferCryptManager(), &m_data[0] + m_offset, m_length - m_offset, connectionState, key);
}
// @0x140710300
CString CInPacket::FUN_140710300() const
{
    CString result;
    const unsigned char* data = &m_data[0];
    for (unsigned i = 0; i < m_length; ++i) {
        CString piece;
        piece.Format("%02x ", data[i]);
        result += piece;
    }
    return result;
}
// MS2-FUNCTIONAL: temp order differs
// @0x1407103f0
void FUN_1407103f0(CInPacket* packet)
{
    Unk_CompressedStream stream(true, 0x28);
    CByteBuffer& decoded = stream.Decode(*static_cast<CInputStream*>(packet));
    unsigned length = decoded.GetLength();
    packet->m_data.SetCount(length + 8, -1);
    memcpy(&packet->m_data[0] + 8, decoded.FUN_140204eb0(), length);
    packet->m_length = length + 8;
    packet->m_offset = 8;
}

// ---- COutPacket -------------------------------------------------------------------------------------------------------
// Rate limit of the packets sent through FUN_1407105c0: (type, key) -> earliest tick of the next send.
std::map<std::pair<int, int>, unsigned> g_packetThrottle;     // 0x143ab0ab0

// @0x140710500
COutPacket::COutPacket(int nType, int nUnk)
{
    m_aBuffer.SetCount(0x100, -1);
    FUN_140710740(nType, nUnk, true);
}
// @0x140710590
void FUN_140710590(COutPacket& packet)
{
    if (FUN_140714f90() != 0) FUN_140714f90()->FUN_14153a020(packet);
}
// MS2-FUNCTIONAL: temp order differs
// @0x1407105c0
bool FUN_1407105c0(COutPacket* packet, int key, int delay)
{
    if (packet->m_aBuffer.GetCount() < 2) return false;
    unsigned now = FUN_140869420();
    int type = *(unsigned short*)&packet->m_aBuffer[0];
    std::pair<int, int> id(type, key);
    std::map<std::pair<int, int>, unsigned>::iterator it = g_packetThrottle.find(id);
    if (it != g_packetThrottle.end() && now < it->second) return false;
    unsigned next = now + delay;
    g_packetThrottle[id] = next;
    FUN_140710590(*packet);
    return true;
}
// @0x1407106d0
void FUN_1407106d0(int type, int key)
{
    std::pair<int, int> id(type, key);
    g_packetThrottle.erase(id);
}
// @0x140710710
void COutPacket::WriteBool(bool value) { WriteUInt8(value); }
// @0x140710740
void COutPacket::FUN_140710740(int nType, int nUnk, int bEncodeType)
{
    m_nFlag = nUnk;
    m_nLength = 0;
    m_n14 = 0;
    if (nType != 0x7fffffff && bEncodeType) {
        MS2_ASSERT_AT(0x161, nType < 65535);
        WriteInt16((short)nType);
    }
    m_nSequence = 0;
}
MS2_REPLACE_METHOD(0x140710740, COutPacket, FUN_140710740, 152, 0x978D8940);
// @0x1407107e0
void FUN_1407107e0(COutPacket* packet, int type, int unk, const void* data, int count)
{
    packet->m_aBuffer.RemoveAll();
    packet->m_aBuffer.SetCount(0x100, -1);
    packet->FUN_140710740(type, unk, true);
    packet->WriteBytes(data, count);
}
MS2_REPLACE(0x1407107E0, FUN_1407107e0, 124, 0x76F804E3);
// MS2-FUNCTIONAL: send path: local layout / temp order differs
// @0x140710870
void FUN_140710870(COutPacket* packet, ATL::CAtlList<Unk_SocketPtr<CPacketBuffer> >* list, unsigned sequence, unsigned* key, int hasSequence)
{
    int total = packet->m_nLength + 6;
    if (hasSequence != 0) total = packet->m_nLength + 10;
    const Unk_PodArray<char>& constBuffer = packet->m_aBuffer;
    const unsigned char* source = (const unsigned char*)&constBuffer[0];
    unsigned chunk = pkmin<unsigned>(total, 0x5b4);
    Unk_SocketPtr<CPacketBuffer> buffer(FUN_1407138b0(chunk, Unk_SocketNew(0)));
    if (packet->FUN_14020bc40() != 0) (*buffer).FUN_140715360(buffer.operator->());
    unsigned short* header = (unsigned short*)buffer.get()->FUN_140713530();
    unsigned char* end = (unsigned char*)header + chunk;
    unsigned type;
    if (key == NULL) type = sequence & 0xffff;
    else type = sequence & 0xffff ^ *key >> 16;
    *header = (unsigned short)type;
    *(unsigned*)(header + 1) = packet->m_nLength;
    unsigned* cursor = (unsigned*)(header + 3);
    if (hasSequence != 0) {
        *cursor = sequence;
        cursor = (unsigned*)(header + 5);
    }
    memcpy(cursor, source, end - (unsigned char*)cursor);
    source += end - (unsigned char*)cursor;
    list->AddTail(buffer);
    while ((total -= chunk) != 0) {
        chunk = pkmin<unsigned>(total, 0x5b4);
        buffer = FUN_1407138b0(chunk, Unk_SocketNew(0));
        if (packet->FUN_14020bc40() != 0) (*buffer).FUN_140715360(buffer.operator->());
        unsigned char* part = (unsigned char*)buffer.get()->FUN_140713530();
        end = part + chunk;
        memcpy(part, source, end - part);
        source += end - part;
        list->AddTail(buffer);
    }
}
// MS2-FUNCTIONAL: temp order differs
// @0x140710b90
COutPacket* FUN_140710b90(COutPacket* packet, int state, unsigned* key)
{
    if (packet->m_n14 != state) {
        if (packet->m_n14 == 0 || packet->m_n14 == state) {
            FUN_1401cddd0(GetBufferCryptManager(), (unsigned char*)&packet->m_aBuffer[0], packet->m_nLength, state, key);
            packet->m_n14 = state;
        } else {
            MS2_ASSERT_AT(0x1a5, FALSE);
            packet = 0;
        }
    }
    return packet;
}
// @0x140710c50
CString COutPacket::FUN_140710c50() const
{
    CString result;
    const unsigned char* data = (const unsigned char*)&m_aBuffer[0];
    for (unsigned i = 0; i < m_nLength; ++i) {
        CString piece;
        piece.Format("%02x ", data[i]);
        result += piece;
    }
    return result;
}
// @0x140710d40
void FUN_140710d40(COutPacket* packet, bool useCompression, unsigned threshold)
{
    Unk_CompressedStream stream(useCompression, threshold);
    CByteBuffer& raw = stream.FUN_140714de0();
    MS2_PK_ASSERT(0x1c1, "m_uOffset > PROTOCOL_LENGTH", packet->m_nLength > 2);
    raw.WriteBytes(&packet->m_aBuffer[0] + 2, packet->m_nLength - 2);
    packet->m_nLength = 2;
    stream.Encode(*packet);
}

// ---- CPacketBuffer / socket pointer helpers ---------------------------------------------------------------------------------
// @0x1407130d0
CPacketBuffer::CPacketBuffer(int size, char* data, CPacketBuffer* parent) { FUN_140715000(size, data, parent); }
// @0x1407132c0
CPacketBuffer::~CPacketBuffer()
{
    if (m_parent == 0) {
        char* data = m_data;
        delete[] data;
    }
}
// @0x140713530
char* CPacketBuffer::FUN_140713530() { return m_data; }
// @0x140714fa0
int CPacketBuffer::GetSize() const { return m_size; }
// @0x140715000
CPacketBuffer* CPacketBuffer::FUN_140715000(int size, char* data, CPacketBuffer* parent)
{
    m_size = size;
    m_data = data;
    m_parent = parent;
    return this;
}
// @0x140715360
void CPacketBuffer::FUN_140715360(void* value) { *FUN_140715db0() = value; }
// @0x140715390
CPacketBuffer* CPacketBuffer::FUN_140715390(unsigned offset, int size, const Unk_SocketNew&)
{
    CPacketBuffer* slice = new CPacketBuffer(size, m_data + offset, this);
    return slice;
}
// @0x140715db0
void** CPacketBuffer::FUN_140715db0() { return reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x10); }
// @0x1407138b0
CPacketBuffer* FUN_1407138b0(unsigned size, const Unk_SocketNew&)
{
    char* data = new char[size];
    CPacketBuffer* buffer = new CPacketBuffer(size, data, 0);
    return buffer;
}
// @0x140714f80
CBufferCryptManager* GetBufferCryptManager() { return DAT_143aac528; }
// @0x140714f90
CNetworkService* FUN_140714f90() { return TSingleton<CNetworkService>::s_instance; }

// ---- Unk_CompressedStream constructor (inline in the exe) ---------------------------------------------------------------
inline Unk_CompressedStream::Unk_CompressedStream(bool useCompression, unsigned threshold)
{
    m_threshold = threshold;
    m_useCompression = useCompression;
}
// @0x140714de0
CByteBuffer& Unk_CompressedStream::FUN_140714de0() { return m_raw; }
// @0x140715230
void CByteBuffer::FUN_140715230(int count) { FUN_140204670(count); }

// ---- CIOBuffer bounds-checked decoders ------------------------------------------------------------------------------------
#define MS2_PK_DECODE_FAIL(hint, code) \
    { CString text; FormatDecodeError(text, CString(hint)); throw Exception(text, code); }
// @0x140714df0
void CIOBuffer::FormatDecodeError(CString& text, CString hint)
{
    text.Format("[type=%u][offset=%u][hint=%s]", (unsigned short)GetType(), GetOffset(), (const char*)hint);
}
// @0x140713970
int CIOBuffer::Decode1(unsigned char& value, const unsigned char* data, unsigned size)
{
    if (size < sizeof(unsigned char)) MS2_PK_DECODE_FAIL("Decode1", 0x26);
    value = *data;
    return 1;
}
// @0x140713ae0
int CIOBuffer::Decode2(short& value, const unsigned char* data, unsigned size)
{
    if (size < sizeof(short)) MS2_PK_DECODE_FAIL("Decode2", 0x26);
    value = *(const short*)data;
    return 2;
}
// @0x140713c50
int CIOBuffer::Decode4(int& value, const unsigned char* data, unsigned size)
{
    if (size < sizeof(int)) MS2_PK_DECODE_FAIL("Decode4", 0x26);
    value = *(const int*)data;
    return 4;
}
// @0x140713db0
int CIOBuffer::Decode8(__int64& value, const unsigned char* data, unsigned size)
{
    if (size < sizeof(__int64)) MS2_PK_DECODE_FAIL("Decode8", 0x26);
    value = *(const __int64*)data;
    return 8;
}
// @0x140713f20
int CIOBuffer::DecodeBuffer(void* dest, int count, const unsigned char* data, unsigned size)
{
    if (size < (unsigned)count) MS2_PK_DECODE_FAIL("DecodeBuffer", 0x26);
    memcpy(dest, data, (unsigned)count);
    return count;
}
// @0x140714ab0
int CIOBuffer::Decodef(float& value, const unsigned char* data, unsigned size)
{
    if (size < sizeof(float)) MS2_PK_DECODE_FAIL("Decodef", 0x26);
    value = *(const float*)data;
    return 4;
}
// MS2-FUNCTIONAL: throw path: 0x10 more stack than the exe
// @0x140714210
int CIOBuffer::DecodeStrA(CString& value, const unsigned char* data, unsigned size)
{
    if (size < 2) MS2_PK_DECODE_FAIL("DecodeStrA", 0x26);
    unsigned short length = *(const unsigned short*)data;
    if (size < length + 2u) MS2_PK_DECODE_FAIL("DecodeStrA", 0x26);
    value = CString((const char*)(data + 2), length);
    if (length != 0 && CString::StringLength(value.GetBuffer()) != length) MS2_PK_DECODE_FAIL("DecodeStrA", 0x18);
    return length + 2;
}
// MS2-FUNCTIONAL: throw path: 0x10 more stack than the exe
// @0x1407145e0
int CIOBuffer::DecodeStr(CStringW& value, const unsigned char* data, unsigned size)
{
    if (size < 2) MS2_PK_DECODE_FAIL("DecodeStr", 0x26);
    unsigned short length = *(const unsigned short*)data;
    if (size < length * 2u + 2) MS2_PK_DECODE_FAIL("DecodeStr", 0x26);
    value = CStringW((const wchar_t*)(data + 2), length);
    if (length != 0 && CStringW::StringLength(value.GetBuffer()) != length) MS2_PK_DECODE_FAIL("DecodeStr", 0x18);
    return length * 2 + 2;
}

// ---- CInPacket accessors and decoders ----------------------------------------------------------------------------------------
// @0x140713940
void CInPacket::FUN_140713940() { m_nState = RS_HEADER; m_length = 0; m_offset = 0; }
// @0x140714fb0
unsigned CInPacket::GetOffset() { return m_offset; }
// @0x140714fd0
short CInPacket::GetType() {
    return *(const short*)(&m_data[0] + 6);
}
// @0x140713a60
unsigned char CInPacket::ReadUInt8()
{
    unsigned char value;
    m_offset += Decode1(value, &m_data[0] + m_offset, m_length - m_offset);
    return value;
}
// @0x140713bd0
short CInPacket::ReadInt16()
{
    short value;
    m_offset += Decode2(value, &m_data[0] + m_offset, m_length - m_offset);
    return value;
}
// @0x140713d40
int CInPacket::ReadInt32()
{
    int value;
    m_offset += Decode4(value, &m_data[0] + m_offset, m_length - m_offset);
    return value;
}
// @0x140713ea0
__int64 CInPacket::ReadInt64()
{
    __int64 value;
    m_offset += Decode8(value, &m_data[0] + m_offset, m_length - m_offset);
    return value;
}
// @0x140714020
void CInPacket::ReadBytes(void* data, int count)
{
    m_offset += DecodeBuffer(data, count, &m_data[0] + m_offset, m_length - m_offset);
}
// @0x1407140a0
short CInPacket::FUN_1407140a0() { return ReadInt16(); }
// @0x1407140d0
Unk_StreamPoint CInPacket::FUN_1407140d0()
{
    Unk_StreamPoint point;
    point.x = ReadFloat();
    point.y = ReadFloat();
    point.z = ReadFloat();
    return point;
}
// @0x140714190
CString CInPacket::ReadUnicodeStringA()
{
    CStringW text = ReadUnicodeString();
    return FUN_14016a600(text, 0);
}
// @0x140714520
CString CInPacket::ReadString()
{
    CString value;
    m_offset += DecodeStrA(value, &m_data[0] + m_offset, m_length - m_offset);
    return value;
}
// @0x140714900
CStringW CInPacket::ReadUnicodeString()
{
    CStringW value;
    m_offset += DecodeStr(value, &m_data[0] + m_offset, m_length - m_offset);
    return value;
}
// @0x1407149c0
Unk_StreamPoint CInPacket::ReadVector3() { return FUN_1407140d0(); }
// @0x1407149f0
Unk_StreamPoint CInPacket::ReadVector3Short()
{
    Unk_StreamPoint point;
    point.x = (float)ReadInt16();
    point.y = (float)ReadInt16();
    point.z = (float)ReadInt16();
    return point;
}
// @0x140714ba0
float CInPacket::ReadFloat()
{
    float value;
    m_offset += Decodef(value, &m_data[0] + m_offset, m_length - m_offset);
    return value;
}
// @0x140714c20
float CInPacket::ReadShortX100() { float r = (float)ReadInt16() * 100.0f; return r; }
// @0x140714c70
float CInPacket::ReadShortX10() { float r = (float)ReadInt16() * 10.0f; return r; }
// @0x140714cc0
float CInPacket::ReadShortScaled(int scale) { float r = (float)ReadInt16() * (float)scale; return r; }
// @0x140714d10
float CInPacket::ReadShortDiv10() { float r = (float)ReadInt16() / 10.0f; return r; }
// @0x140714d60
float CInPacket::ReadShortDivScaled(int scale) { float r = (float)ReadInt16() / (float)scale; return r; }
// MS2-FUNCTIONAL: append: temp order differs
// @0x140715120
void CInPacket::FUN_140715120(const char* data, unsigned count)
{
    if (m_data.GetCount() < m_length + count) {
        size_t newSize = m_data.GetCount();
        do { newSize <<= 1; } while (newSize < m_length + count);
        m_data.SetCount(newSize, -1);
    }
    memcpy(&m_data[0] + m_length, data, count);
    m_length += count;
}
// @0x140715280
void CInPacket::FUN_140715280(unsigned offset)
{
    if (offset <= (unsigned)m_length) { m_offset = offset; return; }
    MS2_PK_DECODE_FAIL("SetOffset", 0x26);
}

// ---- file statics (.text$di) ---------------------------------------------------------------------------------------------
static CString s_listNames0[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // 0x143ab0b20
static CString s_listNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};                      // 0x143ab0ae0
static CString s_listNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};                      // 0x143ab0b60
static CString s_listNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};                      // 0x143ab0ba0

// The UCRT header-inline memcpy_s (corecrt_memcpy_s.h) closes the obj's COMDAT tail; the exe calls memset/memcpy here.
#pragma function(memcpy, memset)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x1407168f0
errno_t FUN_1407168f0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize) {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9bac0-0x142c9bba0 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x140715250, FUN_140715250, 40, 0xC6E9AB8A);
MS2_REPLACE(0x140714db0, FUN_140714db0, 47, 0x2C61C6EC);
MS2_REPLACE(0x140714fc0, FUN_140714fc0, 14, 0x82C92E11);
MS2_REPLACE(0x14070f700, FUN_14070f700, 106, 0x2863236A);
MS2_REPLACE(0x14070f770, FUN_14070f770, 45, 0x16C8AB58);
MS2_REPLACE(0x14070f7b0, FUN_14070f7b0, 102, 0x8ED70AC6);
MS2_REPLACE(0x14070f820, FUN_14070f820, 43, 0x5126B57B);
MS2_REPLACE(0x14070f860, FUN_14070f860, 44, 0xDC797D93);
MS2_REPLACE(0x14070f8a0, FUN_14070f8a0, 45, 0x5DEC3F43);
MS2_REPLACE(0x14070f8e0, FUN_14070f8e0, 45, 0x5DEC3F43);
MS2_REPLACE(0x14070f920, FUN_14070f920, 43, 0x31C95D8E);
MS2_REPLACE(0x14070f960, FUN_14070f960, 43, 0x31C95D8E);
MS2_REPLACE(0x14070f9a0, FUN_14070f9a0, 43, 0x31C95D8E);
MS2_REPLACE(0x14070f9e0, FUN_14070f9e0, 45, 0x3A4C0818);
MS2_REPLACE(0x14070fa20, FUN_14070fa20, 45, 0x3A4C0818);
MS2_REPLACE(0x14070fa60, FUN_14070fa60, 47, 0xAB7F6DD9);
MS2_REPLACE(0x14070faa0, FUN_14070faa0, 45, 0x9D1840A0);
MS2_REPLACE(0x14070fae0, FUN_14070fae0, 45, 0xAA3A77F8);
MS2_REPLACE(0x14070fb20, FUN_14070fb20, 63, 0x146858C6);
MS2_REPLACE(0x14070fb70, FUN_14070fb70, 63, 0x808A85EC);
MS2_REPLACE(0x14070fbc0, FUN_14070fbc0, 122, 0x62046D9B);
MS2_REPLACE(0x14070fc40, FUN_14070fc40, 44, 0x85434CD2);
MS2_REPLACE(0x14070fc80, FUN_14070fc80, 122, 0x93D8A2F2);
MS2_REPLACE_METHOD(0x14070fe80, CInPacket, FUN_14070fe80, 42, 0xF20168B1);
MS2_REPLACE_METHOD_VIA(0x14070feb0, CInPacket, CInputStream, ReadBool, 67, 0xE061F660);
MS2_REPLACE_METHOD(0x14070ff00, CInPacket, FUN_14070ff00, 889, 0xCC51CDC9);
MS2_REPLACE_METHOD(0x140710280, CInPacket, FUN_140710280, 120, 0xA9790E51);
MS2_REPLACE(0x1407103f0, FUN_1407103f0, 262, 0x9CDB8DAB);
MS2_REPLACE(0x140710590, FUN_140710590, 42, 0x7966F887);
MS2_REPLACE(0x1407105c0, FUN_1407105c0, 259, 0x35988C99);
MS2_REPLACE(0x1407106d0, FUN_1407106d0, 54, 0xD8D41D66);
MS2_REPLACE_METHOD(0x140710710, COutPacket, WriteBool, 39, 0x553FDBF2);
MS2_REPLACE(0x140710870, FUN_140710870, 790, 0xF5FD8FA4);
MS2_REPLACE(0x140710b90, FUN_140710b90, 181, 0xA1C676CB);
MS2_REPLACE(0x140710d40, FUN_140710d40, 246, 0x9461C257);
MS2_REPLACE_METHOD(0x140713530, CPacketBuffer, FUN_140713530, 15, 0xCBEE5D21);
MS2_REPLACE_METHOD(0x140714fa0, CPacketBuffer, GetSize, 14, 0x72E52537);
MS2_REPLACE_METHOD(0x140715000, CPacketBuffer, FUN_140715000, 81, 0x3433AD85);
MS2_REPLACE_METHOD(0x140715360, CPacketBuffer, FUN_140715360, 37, 0xC8F82C49);
MS2_REPLACE_METHOD(0x140715db0, CPacketBuffer, FUN_140715db0, 15, 0x770B1889);
MS2_REPLACE(0x140714f80, GetBufferCryptManager, 8, 0xF2EA183E);
MS2_REPLACE(0x140714f90, FUN_140714f90, 8, 0x0D8AB200);
MS2_REPLACE_METHOD(0x140714de0, Unk_CompressedStream, FUN_140714de0, 11, 0x3BE09B6E);
MS2_REPLACE_METHOD(0x140715230, CByteBuffer, FUN_140715230, 32, 0xD1D53A76);
MS2_REPLACE_METHOD(0x140713970, CIOBuffer, Decode1, 218, 0xC179EE8E);
MS2_REPLACE_METHOD(0x140713ae0, CIOBuffer, Decode2, 219, 0xA9CED8D6);
MS2_REPLACE_METHOD(0x140713c50, CIOBuffer, Decode4, 217, 0xDB975035);
MS2_REPLACE_METHOD(0x140713db0, CIOBuffer, Decode8, 219, 0x722AB4A9);
MS2_REPLACE_METHOD(0x140713f20, CIOBuffer, DecodeBuffer, 233, 0x7D7D786A);
MS2_REPLACE_METHOD(0x140714ab0, CIOBuffer, Decodef, 221, 0xA8F68AC2);
MS2_REPLACE_METHOD(0x140714210, CIOBuffer, DecodeStrA, 745, 0x6A5F9DFD);
MS2_REPLACE_METHOD(0x1407145e0, CIOBuffer, DecodeStr, 747, 0x9D146BE9);
MS2_REPLACE_METHOD(0x140713940, CInPacket, FUN_140713940, 42, 0x52DF3817);
MS2_REPLACE_METHOD(0x140714fb0, CInPacket, GetOffset, 14, 0x921EE467);
MS2_REPLACE_METHOD(0x140714fd0, CInPacket, GetType, 37, 0x9128F8DB);
MS2_REPLACE_METHOD_VIA(0x140713a60, CInPacket, CInputStream, ReadUInt8, 113, 0xFD8B0C01);
MS2_REPLACE_METHOD_VIA(0x140713bd0, CInPacket, CInputStream, ReadInt16, 113, 0xD23ADBAD);
MS2_REPLACE_METHOD_VIA(0x140713d40, CInPacket, CInputStream, ReadInt32, 112, 0x198BE64D);
MS2_REPLACE_METHOD_VIA(0x140713ea0, CInPacket, CInputStream, ReadInt64, 113, 0x442FCC14);
MS2_REPLACE_METHOD_VIA(0x140714020, CInPacket, CInputStream, ReadBytes, 124, 0x5813BF1A);
MS2_REPLACE_METHOD(0x1407140a0, CInPacket, FUN_1407140a0, 48, 0x4632FC2C);
MS2_REPLACE_METHOD_VIA(0x140714ba0, CInPacket, CInputStream, ReadFloat, 114, 0x361FC030);
MS2_REPLACE_METHOD_VIA(0x140714c20, CInPacket, CInputStream, ReadShortX100, 68, 0xCDD292EB);
MS2_REPLACE_METHOD_VIA(0x140714c70, CInPacket, CInputStream, ReadShortX10, 68, 0xBDCB66C8);
MS2_REPLACE_METHOD_VIA(0x140714cc0, CInPacket, CInputStream, ReadShortScaled, 74, 0x3B9319CB);
MS2_REPLACE_METHOD_VIA(0x140714d10, CInPacket, CInputStream, ReadShortDiv10, 68, 0xB7280D8D);
MS2_REPLACE_METHOD_VIA(0x140714d60, CInPacket, CInputStream, ReadShortDivScaled, 74, 0xBC626986);
MS2_REPLACE_METHOD(0x140715120, CInPacket, FUN_140715120, 229, 0x44DDABF1);
MS2_REPLACE_METHOD(0x140715280, CInPacket, FUN_140715280, 207, 0x044530BA);

