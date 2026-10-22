#define STREAM_ASSERT(line,expr) (void)((!!(expr)) || (_wassert(_CRT_WIDE(#expr),L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stream.h",line),0))
// CByteBuffer and stream base names recovered from RTTI; helper names inferred.
#pragma once
#include <atlcoll.h>
#include <string>
#include "ms2/ms2recover.h"
#include "ms2/placeholder/nipoint3.h"   // Vector3
class CIOBuffer {
public:
    virtual unsigned GetOffset() = 0;
    virtual short GetType() = 0;
    // Bounds-checked decoders shared by CByteBuffer and CInPacket (defined in commonfiles\packet.cpp, inline in the
    // exe's packet.h): store the value read from `data` (`size` bytes remain) and return the bytes consumed; they throw
    // Exception(0x26) with a "[type=..][offset=..][hint=..]" text when too little remains.
    void FormatDecodeError(CString& text,CString hint);
    int Decode1(unsigned char&,const unsigned char*,unsigned);
    int Decode2(short&,const unsigned char*,unsigned);
    int Decode4(int&,const unsigned char*,unsigned);
    int Decode8(__int64&,const unsigned char*,unsigned);
    int Decodef(float&,const unsigned char*,unsigned);
    int DecodeStrA(CString&,const unsigned char*,unsigned);
    int DecodeStr(CStringW&,const unsigned char*,unsigned);
    int DecodeBuffer(void*,int,const unsigned char*,unsigned);
};
class CInputStream { public:
    virtual bool ReadBool() = 0;
    virtual unsigned char ReadUInt8() = 0;
    virtual short ReadInt16() = 0;
    virtual int ReadInt32() = 0;
    virtual __int64 ReadInt64() = 0;
    virtual float ReadFloat() = 0;
    virtual CString ReadUnicodeStringA() = 0;
    virtual CString ReadString() = 0;
    virtual CStringW ReadUnicodeString() = 0;
    virtual void ReadBytes(void* data,int count) = 0;
    virtual Vector3 ReadVector3() = 0;
    virtual Vector3 ReadVector3Short() = 0;
    virtual float ReadShortX10() = 0;
    virtual float ReadShortX100() = 0;
    virtual float ReadShortScaled(int scale) = 0;
    virtual float ReadShortDiv10() = 0;
    virtual float ReadShortDivScaled(int scale) = 0;
};
class COutputStream { public:
    virtual void WriteBool(bool value) = 0;
    virtual void WriteUInt8(unsigned char value) = 0;
    virtual void WriteInt16(short value) = 0;
    virtual void WriteInt32(int value) = 0;
    virtual void WriteInt64(__int64 value) = 0;
    virtual void WriteFloat(float value) = 0;
    virtual void WriteUnicodeStringA(const CString& value) = 0;
    virtual void WriteString(const CString& value) = 0;
    virtual void WriteUnicodeString(const CStringW& value) = 0;
    virtual void WriteBytes(const void* data,int count) = 0;
    virtual void WriteVector3(const Vector3& value) = 0;
    virtual void WriteVector3Short(const Vector3& value) = 0;
    virtual void WriteShortX10(float value) = 0;
    virtual void WriteShortX100(float value) = 0;
    virtual void WriteShortScaled(float value, int scale) = 0;
    virtual void WriteShortDiv10(float value) = 0;
    virtual void WriteShortDivScaled(float value, int scale) = 0;
};
class CByteBuffer : public CIOBuffer, public CInputStream, public COutputStream { public:
    CByteBuffer();
    ~CByteBuffer();
    unsigned GetOffset() override;
    short GetType() override;
    virtual void vfunc_2(int n,unsigned uOffset);
    bool ReadBool() override;
    unsigned char ReadUInt8() override;
    short ReadInt16() override;
    int ReadInt32() override;
    __int64 ReadInt64() override;
    float ReadFloat() override;
    CString ReadUnicodeStringA() override;
    CString ReadString() override;
    CStringW ReadUnicodeString() override;
    void ReadBytes(void* data,int count) override;
    Vector3 ReadVector3() override;
    Vector3 ReadVector3Short() override;
    float ReadShortX10() override;
    float ReadShortX100() override;
    float ReadShortScaled(int scale) override;
    float ReadShortDiv10() override;
    float ReadShortDivScaled(int scale) override;
    void WriteBool(bool value) override;
    void WriteUInt8(unsigned char value) override;
    void WriteInt16(short value) override;
    void WriteInt32(int value) override;
    void WriteInt64(__int64 value) override;
    void WriteFloat(float value) override;
    void WriteUnicodeStringA(const CString& value) override;
    void WriteString(const CString& value) override;
    void WriteUnicodeString(const CStringW& value) override;
    void WriteBytes(const void* data,int count) override;
    void WriteVector3(const Vector3& value) override;
    void WriteVector3Short(const Vector3& value) override;
    void WriteShortX10(float value) override;
    void WriteShortX100(float value) override;
    void WriteShortScaled(float value, int scale) override;
    void WriteShortDiv10(float value) override;
    void WriteShortDivScaled(float value, int scale) override;
    std::string ToHex() const;
    void FromHex(const std::string&);
    bool Compress(CByteBuffer&) const;
    bool Uncompress(CByteBuffer&) const;
    void WriteBuffer(CByteBuffer&);
    void ReadBuffer(CByteBuffer&);
    void SetLength(int);
    static bool TestCompression();
    void FUN_140204670(int);
    void FUN_140715230(int);
    void FUN_140720e90(unsigned);
    void FUN_140518490();
    unsigned GetLength() const;
    unsigned char* FUN_140204eb0();
    const unsigned char* FUN_14067c4c0() const;
    CByteBuffer& FUN_140714de0();
    void FUN_140720c30(CByteBuffer&);
    unsigned char& operator[](size_t index) { STREAM_ASSERT(669,index < m_uLength);return m_aByteBuff[index]; }
    const unsigned char& operator[](size_t index) const { STREAM_ASSERT(670,index < m_uLength);return m_aByteBuff[index]; }
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<unsigned char> m_aByteBuff;
    unsigned m_uOffset;
    unsigned m_uLength;
};
MS2_CHECK_SIZE(CByteBuffer,0x40);
MS2_CHECK_OFFSET(CByteBuffer,m_aByteBuff,0x18);
MS2_CHECK_OFFSET(CByteBuffer,m_uOffset,0x38);
MS2_CHECK_OFFSET(CByteBuffer,m_uLength,0x3c);
class Unk_CompressedStream {
public:
    Unk_CompressedStream() = default;
    inline Unk_CompressedStream(bool useCompression,unsigned threshold);   // @0x140713140 (inline in the exe)
    void Encode(COutputStream&);
    CByteBuffer& Decode(CInputStream&);
    void EncodeReady(COutputStream&);
    CByteBuffer& FUN_140714de0();
    CByteBuffer& Compressed() { return m_compressed; }
    void SetThreshold(unsigned n) { m_threshold=n; }
    void SetCompressed(bool b) { m_useCompression=b; }
private:
    MS2_LAYOUT_FRIEND;
public:
    CByteBuffer m_raw;
private:
    CByteBuffer m_compressed;
    unsigned m_threshold;
    bool m_useCompression;
};
MS2_CHECK_SIZE(Unk_CompressedStream,0x88);
MS2_CHECK_OFFSET(Unk_CompressedStream,m_threshold,0x80);
MS2_CHECK_OFFSET(Unk_CompressedStream,m_useCompression,0x84);
class Unk_StreamWrapper {
public:
    void Encode(COutputStream&,bool);
    void Decode(CInputStream&);
    bool Update(bool,unsigned);
    void Configure(bool,unsigned);
    void EncodeReady(COutputStream& s) { m_stream.EncodeReady(s); }
    CByteBuffer& Raw() { return m_stream.FUN_140714de0(); }
    CByteBuffer& Read(CInputStream& s) { return m_stream.Decode(s); }
    void Prepare(COutputStream& s) { m_stream.Encode(s); }
    void SetDirty(bool b) { m_dirty=b; }
private:
    MS2_LAYOUT_FRIEND;
    void* m_pad00; void* m_pad08; void* m_pad10;
    Unk_CompressedStream m_stream;
    bool m_dirty;
};
MS2_CHECK_OFFSET(Unk_StreamWrapper,m_stream,0x18);
MS2_CHECK_OFFSET(Unk_StreamWrapper,m_dirty,0xa0);
