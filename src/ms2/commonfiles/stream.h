#define STREAM_ASSERT(line,expr) (void)((!!(expr)) || (_wassert(_CRT_WIDE(#expr),L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stream.h",line),0))
// CByteBuffer and stream base names recovered from RTTI; helper names inferred.
#pragma once
#include <atlcoll.h>
#include <string>
#include "ms2/ms2recover.h"
#include "ms2/placeholder/nipoint3.h"   // Unk_StreamPoint
class CIOBuffer {
public:
    virtual unsigned vfunc_0() = 0;
    virtual short vfunc_1() = 0;
    // Bounds-checked decoders shared by CByteBuffer and CInPacket (defined in commonfiles\packet.cpp, inline in the
    // exe's packet.h): store the value read from `data` (`size` bytes remain) and return the bytes consumed; they throw
    // Exception(0x26) with a "[type=..][offset=..][hint=..]" text when too little remains.
    void FUN_140714df0(CString& text,CString hint);
    int FUN_140713970(unsigned char&,const unsigned char*,unsigned);
    int FUN_140713ae0(short&,const unsigned char*,unsigned);
    int FUN_140713c50(int&,const unsigned char*,unsigned);
    int FUN_140713db0(__int64&,const unsigned char*,unsigned);
    int FUN_140714ab0(float&,const unsigned char*,unsigned);
    int FUN_140714210(CString&,const unsigned char*,unsigned);
    int FUN_1407145e0(CStringW&,const unsigned char*,unsigned);
    int FUN_140713f20(void*,int,const unsigned char*,unsigned);
};
class CInputStream { public:
    virtual bool vfunc_o8_0() = 0;
    virtual unsigned char vfunc_o8_1() = 0;
    virtual short vfunc_o8_2() = 0;
    virtual int vfunc_o8_3() = 0;
    virtual __int64 vfunc_o8_4() = 0;
    virtual float vfunc_o8_5() = 0;
    virtual CString vfunc_o8_6() = 0;
    virtual CString vfunc_o8_7() = 0;
    virtual CStringW vfunc_o8_8() = 0;
    virtual void vfunc_o8_9(void* data,int count) = 0;
    virtual Unk_StreamPoint vfunc_o8_10() = 0;
    virtual Unk_StreamPoint vfunc_o8_11() = 0;
    virtual float vfunc_o8_12() = 0;
    virtual float vfunc_o8_13() = 0;
    virtual float vfunc_o8_14(int scale) = 0;
    virtual float vfunc_o8_15() = 0;
    virtual float vfunc_o8_16(int scale) = 0;
};
class COutputStream { public:
    virtual void vfunc_o10_0(bool value) = 0;
    virtual void vfunc_o10_1(unsigned char value) = 0;
    virtual void vfunc_o10_2(short value) = 0;
    virtual void vfunc_o10_3(int value) = 0;
    virtual void vfunc_o10_4(__int64 value) = 0;
    virtual void vfunc_o10_5(float value) = 0;
    virtual void vfunc_o10_6(const CString& value) = 0;
    virtual void vfunc_o10_7(const CString& value) = 0;
    virtual void vfunc_o10_8(const CStringW& value) = 0;
    virtual void vfunc_o10_9(const void* data,int count) = 0;
    virtual void vfunc_o10_10(const Unk_StreamPoint& value) = 0;
    virtual void vfunc_o10_11(const Unk_StreamPoint& value) = 0;
    virtual void vfunc_o10_12(float value) = 0;
    virtual void vfunc_o10_13(float value) = 0;
    virtual void vfunc_o10_14(float value, int scale) = 0;
    virtual void vfunc_o10_15(float value) = 0;
    virtual void vfunc_o10_16(float value, int scale) = 0;
};
class CByteBuffer : public CIOBuffer, public CInputStream, public COutputStream { public:
    CByteBuffer();
    ~CByteBuffer();
    unsigned vfunc_0() override;
    short vfunc_1() override;
    virtual void vfunc_2(int n,unsigned uOffset);
    bool vfunc_o8_0() override;
    unsigned char vfunc_o8_1() override;
    short vfunc_o8_2() override;
    int vfunc_o8_3() override;
    __int64 vfunc_o8_4() override;
    float vfunc_o8_5() override;
    CString vfunc_o8_6() override;
    CString vfunc_o8_7() override;
    CStringW vfunc_o8_8() override;
    void vfunc_o8_9(void* data,int count) override;
    Unk_StreamPoint vfunc_o8_10() override;
    Unk_StreamPoint vfunc_o8_11() override;
    float vfunc_o8_12() override;
    float vfunc_o8_13() override;
    float vfunc_o8_14(int scale) override;
    float vfunc_o8_15() override;
    float vfunc_o8_16(int scale) override;
    void vfunc_o10_0(bool value) override;
    void vfunc_o10_1(unsigned char value) override;
    void vfunc_o10_2(short value) override;
    void vfunc_o10_3(int value) override;
    void vfunc_o10_4(__int64 value) override;
    void vfunc_o10_5(float value) override;
    void vfunc_o10_6(const CString& value) override;
    void vfunc_o10_7(const CString& value) override;
    void vfunc_o10_8(const CStringW& value) override;
    void vfunc_o10_9(const void* data,int count) override;
    void vfunc_o10_10(const Unk_StreamPoint& value) override;
    void vfunc_o10_11(const Unk_StreamPoint& value) override;
    void vfunc_o10_12(float value) override;
    void vfunc_o10_13(float value) override;
    void vfunc_o10_14(float value, int scale) override;
    void vfunc_o10_15(float value) override;
    void vfunc_o10_16(float value, int scale) override;
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
