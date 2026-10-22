// packet.h - inline parts of COutPacket (header-defined in the original; emitted as COMDATs in the first unit that
// needs them: commonfiles\clientreconnectionstructs.cpp). Include only from clientreconnectionstructs.cpp / packet.cpp.
// Helper names (FUN_xxx) are invented; the bodies are proven from the exe. The free helpers keep the names/signatures
// that commonfiles/stream.cpp already declares for them.
#pragma once
#include <string.h>
#include "ms2/placeholder/coutpacket.h"

CStringW FUN_14016a730(const char*, int);

// Encoded size of a value (the argument is only used for strings).
inline int FUN_14020abc0(const unsigned char&) { return 1; }                          // @0x14020abc0
inline int FUN_14020abd0(const short&) { return 2; }                                  // @0x14020abd0
inline int FUN_14020abe0(const int&) { return 4; }                                    // @0x14020abe0
inline int FUN_14020abf0(const __int64&) { return 8; }                                // @0x14020abf0
inline __int64 FUN_14020ac00(const CString& s) { return (__int64)s.GetLength() + 2; }              // @0x14020ac00
inline __int64 FUN_14020ac20(const CStringW& s) { return (__int64)s.GetLength() * 2 + 2; }         // @0x14020ac20
// Store a value at dst and return its size.
inline int FUN_14020ac40(unsigned char v, unsigned char* dst) { *dst = v; return FUN_14020abc0(v); }        // @0x14020ac40
inline int FUN_14020ace0(short v, unsigned char* dst) { *(short*)dst = v; return FUN_14020abd0(v); }        // @0x14020ace0
inline int FUN_14020ad80(int v, unsigned char* dst) { *(int*)dst = v; return FUN_14020abe0(v); }            // @0x14020ad80
inline int FUN_14020ae20(__int64 v, unsigned char* dst) { *(__int64*)dst = v; return FUN_14020abf0(v); }    // @0x14020ae20
inline int FUN_14020aec0(const void* data, unsigned count, unsigned char* dst) { memcpy(dst, data, count); return count; }  // @0x14020aec0
inline int FUN_14020b020(const CString& s, unsigned char* dst)                                              // @0x14020b020
{ *(unsigned short*)dst = (unsigned short)s.GetLength(); memcpy(dst + 2, (const char*)s, (size_t)s.GetLength()); return FUN_14020ac00(s); }
inline int FUN_14020b170(const CStringW& s, unsigned char* dst)                                             // @0x14020b170
{ *(unsigned short*)dst = (unsigned short)s.GetLength(); memcpy(dst + 2, (const wchar_t*)s, (size_t)s.GetLength() * 2); return FUN_14020ac20(s); }
inline int FUN_14020b410(float v, unsigned char* dst) { *(float*)dst = v; int n = (int)(__int64)v; return FUN_14020abe0(n); }  // @0x14020b410
// Writes the three floats of a point through the virtual float encoder (slot 5).
inline void FUN_14020af60(COutPacket* out, const Unk_StreamPoint* p)                                        // @0x14020af60
{ out->WriteFloat(p->x); out->WriteFloat(p->y); out->WriteFloat(p->z); }

#define MS2_PKT_FILE L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\packet.h"
// @0x14020b630
inline void COutPacket::FUN_14020b630(unsigned n)
{
    unsigned neededBufferSize = m_nLength + n;
    (void)((neededBufferSize <= 0xffffffffu) || (_wassert(L"neededBufferSize <= MAX_LEN_PACKET", MS2_PKT_FILE, 0x340), 0));
    if (neededBufferSize > m_aBuffer.GetCount()) {
        size_t newSize = m_aBuffer.GetCount();
        do { newSize <<= 1; } while (neededBufferSize > newSize);
        m_aBuffer.SetCount(newSize, -1);
    }
}
#define MS2_PKT_PUT(Size, Put, value) \
    do { FUN_14020b630(Size(value)); m_nLength += Put(value, (unsigned char*)&m_aBuffer[0] + m_nLength); } while (0)

// @0x14020a630
inline COutPacket::~COutPacket() {}
// @0x14020aa30
inline void COutPacket::FUN_14020aa30(const COutPacket& src, int offset)
{
    WriteBytes(src.m_aBuffer.GetData() + offset, src.FUN_14020b9f0() - offset);
}
// @0x14020ac70
inline void COutPacket::WriteUInt8(unsigned char value) { FUN_14020b630(FUN_14020abc0(value)); m_nLength += FUN_14020ac40(value, (unsigned char*)&m_aBuffer[0] + m_nLength); }
// @0x14020ad10
inline void COutPacket::WriteInt16(short value) { FUN_14020b630(FUN_14020abd0(value)); m_nLength += FUN_14020ace0(value, (unsigned char*)&m_aBuffer[0] + m_nLength); }
// @0x14020adb0
inline void COutPacket::WriteInt32(int value) { FUN_14020b630(FUN_14020abe0(value)); m_nLength += FUN_14020ad80(value, (unsigned char*)&m_aBuffer[0] + m_nLength); }
// @0x14020ae50
inline void COutPacket::WriteInt64(__int64 value) { FUN_14020b630(FUN_14020abf0(value)); m_nLength += FUN_14020ae20(value, (unsigned char*)&m_aBuffer[0] + m_nLength); }
// @0x14020aef0
inline void COutPacket::WriteBytes(const void* data, int count) { FUN_14020b630(count); m_nLength += FUN_14020aec0(data, count, (unsigned char*)&m_aBuffer[0] + m_nLength); }
// @0x14020afc0
inline void COutPacket::WriteUnicodeStringA(const CString& value) { CStringW text = FUN_14016a730(value, 0); WriteUnicodeString(text); }
// @0x14020b090
inline void COutPacket::WriteString(const CString& value)
{
    CString text = value;
    if (text.GetLength() > 0xffff) text = text.Left(0xffff);
    FUN_14020b630(FUN_14020ac00(text));
    m_nLength += FUN_14020b020(text, (unsigned char*)&m_aBuffer[0] + m_nLength);
}
// @0x14020b1e0
inline void COutPacket::WriteUnicodeString(const CStringW& value)
{
    CStringW text = value;
    if (text.GetLength() > 0xffff) text = text.Left(0xffff);
    FUN_14020b630(FUN_14020ac20(text));
    m_nLength += FUN_14020b170(text, (unsigned char*)&m_aBuffer[0] + m_nLength);
}
// @0x14020b2c0
inline void COutPacket::WriteVector3(const Unk_StreamPoint& value) { FUN_14020af60(this, &value); }
// @0x14020b2f0
inline void COutPacket::WriteVector3Short(const Unk_StreamPoint& value)
{
    float x = value.x;
    if (x < 0.0f) x -= 0.001f; else x += 0.001f;
    float y = value.y;
    if (y < 0.0f) y -= 0.001f; else y += 0.001f;
    WriteInt16((unsigned short)(int)x);
    WriteInt16((unsigned short)(int)y);
    WriteInt16((unsigned short)(int)(value.z + 0.001f));
}
// @0x14020b450
inline void COutPacket::WriteFloat(float value)
{
    int n = (int)(__int64)value;
    FUN_14020b630(FUN_14020abe0(n));
    m_nLength += FUN_14020b410(value, (unsigned char*)&m_aBuffer[0] + m_nLength);
}
// @0x14020b4d0
inline void COutPacket::WriteShortX100(float value) { short n = (short)(value / 100.0f); WriteInt16(n); }
// @0x14020b510
inline void COutPacket::WriteShortX10(float value) { short n = (short)(value / 10.0f); WriteInt16(n); }
// @0x14020b550
inline void COutPacket::WriteShortScaled(float value, int scale) { short n = (short)(value / (float)scale); WriteInt16(n); }
// @0x14020b5a0
inline void COutPacket::WriteShortDiv10(float value) { short n = (short)(value * 10.0f); WriteInt16(n); }
// @0x14020b5e0
inline void COutPacket::WriteShortDivScaled(float value, int scale) { short n = (short)(value * (float)scale); WriteInt16(n); }
