// coutpacket.h - COutPacket (RTTI .?AVCOutPacket@@, base COutputStream, vftable 0x142cf27e8, 17 slots).
// Not an original header (packet.cpp defines the class in the exe); declaration proven from the exe.
// Slot list = COutputStream's 17 encoders (commonfiles/stream.h vfunc_o10_N); there is NO virtual destructor
// (slot 0 is the bool encoder 0x140710710, which calls slot 1). Non-virtual ~COutPacket at 0x14020a630.
// Layout: vftable +0, int +8 (=0), int +0xc (=0), int +0x10 (ctor arg 2), uint +0x14 (write offset),
// CAtlArray<void*>(?) at +0x18 (reserved 0x100 bytes by the ctor 0x140710500, which takes (type, int)).
// Slots: 0 bool 0x140710710, 1 u8 0x14020ac70, 2 i16 0x14020ad10, 3 i32 0x14020adb0, 4 i64 0x14020ae50,
// 5 float(as int) 0x14020b450, 6 CString->wide 0x14020afc0, 7 CString 0x14020b090, 8 CStringW 0x14020b1e0,
// 9 raw bytes 0x14020aef0, 10 point 0x14020b2c0, 11 point 0x14020b2f0, 12..16 scaled floats 0x14020b510..b5e0.
// Encode1/2/4/8 are the old names of slots 1..4; they are forced-inline wrappers that call the slot directly
// (the exe calls the slot functions directly on local packets).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/podarray.h"
#include "ms2/commonfiles/opcodes.h"

class COutPacket : public COutputStream
{
public:
    COutPacket(int nType = 0x7fffffff, int nUnk = 0);       // 0x140710500 (packet.cpp)
    ~COutPacket();                                          // 0x14020a630, inline in the exe (commonfiles/packet.h)
    void WriteBool(bool value) override;
    void WriteUInt8(unsigned char value) override;
    void WriteInt16(short value) override;
    void WriteInt32(int value) override;
    void WriteInt64(__int64 value) override;
    void WriteFloat(float value) override;
    void WriteUnicodeStringA(const CString& value) override;
    void WriteString(const CString& value) override;
    void WriteUnicodeString(const CStringW& value) override;
    void WriteBytes(const void* data, int count) override;
    void WriteVector3(const Unk_StreamPoint& value) override;
    void WriteVector3Short(const Unk_StreamPoint& value) override;
    void WriteShortX10(float value) override;
    void WriteShortX100(float value) override;
    void WriteShortScaled(float value, int scale) override;
    void WriteShortDiv10(float value) override;
    void WriteShortDivScaled(float value, int scale) override;

    __forceinline void Encode1(unsigned char n) { COutPacket::WriteUInt8(n); }
    __forceinline void Encode2(short n)         { COutPacket::WriteInt16(n); }
    __forceinline void Encode4(int n)           { COutPacket::WriteInt32(n); }
    __forceinline void Encode8(__int64 n)       { COutPacket::WriteInt64(n); }
    __forceinline void FUN_14020ae50(__int64 n) { COutPacket::WriteInt64(n); }

    // 0x140710740: sets the flag/length/cursor fields; when bEncodeType and nType != 0x7fffffff writes the u16 type.
    void FUN_140710740(int nType, int nUnk, int bEncodeType);
    CString FUN_140710c50() const;   // hex dump "%02x " of the buffer, @0x140710c50
    // 0x14020b630: grows the buffer (doubling) so that `n` more bytes fit after m_nLength (inline in commonfiles/packet.h).
    void FUN_14020b630(unsigned n);
    // 0x14020aa30: appends src's payload (from `offset`) through the virtual raw-bytes encoder (slot 9).
    void FUN_14020aa30(const COutPacket& src, int offset);
    // Inline accessors of the exe (COMDATs in clientreconnectionstructs.cpp's range; names invented).
    int  FUN_14020b9f0() const { return (int)m_nLength; }                          // @0x14020b9f0
    unsigned FUN_14020ba00() const { return m_nSequence; }                        // @0x14020ba00
    int  FUN_14020ba10() const { return m_n14; }                              // @0x14020ba10
    unsigned short FUN_14020ba20() const { return *(unsigned short*)&m_aBuffer[0]; }   // @0x14020ba20 (packet type)
    int  FUN_14020bc40() const { return m_nFlag; }                            // @0x14020bc40
    void FUN_14020c070(int n) { m_nSequence = n; }                            // @0x14020c070
    void FUN_14020c090(int n) { m_n14 = n; }                                  // @0x14020c090

    // Public so that unit-local code (packet.cpp, clientreconnectionstructs.cpp) can reach them; layout from the exe.
    unsigned m_nSequence;               // +0x08
    unsigned m_nLength;                 // +0x0c write cursor / payload length
    int m_nFlag;                        // +0x10 (ctor argument 2)
    int m_n14;                          // +0x14
    Unk_PodArray<char> m_aBuffer;       // +0x18 (data, count, alloc, grow)
};
MS2_CHECK_SIZE(COutPacket, 0x38);

// Sends `packet` through the client socket (0x140710590: gets the socket singleton 0x140714f90, null-checked).
void FUN_140710590(COutPacket& packet);
