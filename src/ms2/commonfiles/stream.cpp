// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: commonfiles\stream.cpp
// MS2-PIN: ?EncodeReady@Unk_StreamWrapper@@QEAAXAEAVCOutputStream@@@Z 0x14083b990
// MS2-PIN: ?Prepare@Unk_StreamWrapper@@QEAAXAEAVCOutputStream@@@Z 0x14083ba20
// MS2-PIN: ?Compressed@Unk_CompressedStream@@QEAAAEAVCByteBuffer@@XZ 0x14083b9c0
// MS2-RANGE: 0x140838d50-0x14083bab0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stream.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "stream.h"
#include "ms2/ms2format.h"
#include "hook/ms2hook.h"
extern "C" int compress(unsigned char*,unsigned long*,const unsigned char*,unsigned long);
extern "C" int uncompress(unsigned char*,unsigned long*,const unsigned char*,unsigned long);
CStringW FUN_14016a730(const char*,int);
CString FUN_1401d4330(const wchar_t*,int);
int FUN_14020abc0(const unsigned char&);
int FUN_14020ac40(unsigned char,unsigned char*);
int FUN_14020abd0(const short&);
int FUN_14020ace0(short,unsigned char*);
int FUN_14020abe0(const int&);
int FUN_14020ad80(int,unsigned char*);
int FUN_14020abf0(const __int64&);
int FUN_14020ae20(__int64,unsigned char*);
int FUN_14020ac00(const CString&);
int FUN_14020b020(const CString&,unsigned char*);
int FUN_14020ac20(const CStringW&);
int FUN_14020b170(const CStringW&,unsigned char*);
int FUN_14020b410(float,unsigned char*);
int FUN_14020aec0(const void*,int,unsigned char*);
struct Unk_StreamTest { unsigned char byte; int number; CStringW text; };
// @0x140838d50
std::string CByteBuffer::ToHex() const {
    std::string result; result.reserve(m_uLength<<1);
    for(unsigned i=0;i<m_uLength;++i) result+=StringFormat("{0:02X}",m_aByteBuff[i]);
    return result;
}
MS2_REPLACE_METHOD(0x140838D50, CByteBuffer, ToHex, 282, 0x77B3A344);
// @0x140838e70
void CByteBuffer::FromHex(const std::string& hex) {
    unsigned char digits[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    FUN_140518490(); size_t length=hex.length();
    if(length%2!=0) {MS2_ASSERT_AT(65,FALSE);return;}
    {
        for(size_t i=0;i<length;i+=2) {
            unsigned char a=hex[i]; unsigned char b=hex[i+1];
            unsigned char byte=(unsigned char)(digits[a]<<4)|digits[b]; WriteUInt8(byte);
        }
        return FUN_140720e90(0);
    }

}
MS2_REPLACE_METHOD(0x140838E70, CByteBuffer, FromHex, 2202, 0xE897382F);
// @0x140839710
bool CByteBuffer::Compress(CByteBuffer& dest) const {
    unsigned length=GetLength(); unsigned result=0;
    if(length==0) return false;
    unsigned long len=length+13+length/100;
    if(len>=0x80000000u) return false;
    dest.FUN_140715230(len+4);
    MS2_ASSERT_AT(342,dest.GetLength() >= len + 4);
    if(compress(dest.FUN_140204eb0()+4,&len,FUN_14067c4c0(),length)==0) {
        dest.SetLength(len+4);result=len+4;
        dest[0]=(length&0xff000000)>>24;dest[1]=(length&0xff0000)>>16;dest[2]=(length&0xff00)>>8;dest[3]=length&0xff;
    } else dest.FUN_140715230(0);
    return result>0;
}
MS2_REPLACE_METHOD(0x140839710, CByteBuffer, Compress, 444, 0x44DF5BC1);
// @0x1408398e0
bool CByteBuffer::Uncompress(CByteBuffer& dest) const {
    unsigned length=GetLength(); unsigned result=0;
    const CByteBuffer& source=*this;
    if(length<=4) return false;
    unsigned n=(source[0]<<24)|(source[1]<<16)|(source[2]<<8)|source[3];
    unsigned long len=n>1?n:1;
    if(len>=0x80000000u) return false;
    dest.FUN_140715230(len);
    MS2_ASSERT_AT(385,dest.GetLength() >= len);
    unsigned long original=len;
    if(uncompress(dest.FUN_140204eb0(),&len,FUN_14067c4c0()+4,length-4)==0) {
        if(len!=original && len>=0x80000000u) return false;
        dest.SetLength(len);result=len;
    } else dest.FUN_140715230(0);
    return result>0;
}
MS2_REPLACE_METHOD(0x1408398E0, CByteBuffer, Uncompress, 461, 0x5CF06288);
// @0x140839ac0
void CByteBuffer::WriteBuffer(CByteBuffer& data) { WriteInt32(data.GetLength());WriteBytes(data.FUN_140204eb0(),data.GetLength()); }
MS2_REPLACE_METHOD(0x140839AC0, CByteBuffer, WriteBuffer, 125, 0xBA8A965F);
// @0x140839b50
void CByteBuffer::ReadBuffer(CByteBuffer& data) { unsigned count=ReadInt32();data.FUN_140204670(count);ReadBytes(data.FUN_140204eb0(),count); }
MS2_REPLACE_METHOD(0x140839B50, CByteBuffer, ReadBuffer, 120, 0xF6A84ABE);
// @0x140839bd0
void CByteBuffer::WriteBool(bool value) { WriteUInt8(value?1:0); }
MS2_REPLACE_METHOD_VIA(0x140839BD0, CByteBuffer, COutputStream, WriteBool, 79, 0x8B4AC83C);
// @0x140839c30
void CByteBuffer::WriteUInt8(unsigned char value) { FUN_140204670(FUN_14020abc0(value));m_uOffset+=FUN_14020ac40(value,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x140839C30, CByteBuffer, COutputStream, WriteUInt8, 103, 0x2FD21646);
// @0x140839ca0
void CByteBuffer::WriteInt16(short value) { FUN_140204670(FUN_14020abd0(value));m_uOffset+=FUN_14020ace0(value,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x140839CA0, CByteBuffer, COutputStream, WriteInt16, 104, 0x67347359);
// @0x140839d10
void CByteBuffer::WriteInt32(int value) { FUN_140204670(FUN_14020abe0(value));m_uOffset+=FUN_14020ad80(value,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x140839D10, CByteBuffer, COutputStream, WriteInt32, 102, 0x5F2254FE);
// @0x140839d80
void CByteBuffer::WriteInt64(__int64 value) { FUN_140204670(FUN_14020abf0(value));m_uOffset+=FUN_14020ae20(value,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x140839D80, CByteBuffer, COutputStream, WriteInt64, 104, 0xF4C239B8);
// @0x140839df0
void CByteBuffer::WriteFloat(float value) { FUN_140204670(FUN_14020abe0((int)(unsigned)value));m_uOffset+=FUN_14020b410(value,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x140839DF0, CByteBuffer, COutputStream, WriteFloat, 117, 0x1ADB8C62);
// @0x140839e70
void CByteBuffer::WriteUnicodeStringA(const CString& value) { CStringW text=FUN_14016a730(value,0);if(text.GetLength()>65535)text=text.Left(65535); FUN_140204670(FUN_14020ac20(text));m_uOffset+=FUN_14020b170(text,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x140839E70, CByteBuffer, COutputStream, WriteUnicodeStringA, 235, 0x03341E78);
// @0x140839f70
void CByteBuffer::WriteString(const CString& value) { CString text=value;if(text.GetLength()>65535)text=text.Left(65535); FUN_140204670(FUN_14020ac00(text));m_uOffset+=FUN_14020b020(text,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x140839F70, CByteBuffer, COutputStream, WriteString, 224, 0x15C4855C);
// @0x14083a060
void CByteBuffer::WriteUnicodeString(const CStringW& value) { CStringW text=value;if(text.GetLength()>65535)text=text.Left(65535); FUN_140204670(FUN_14020ac20(text));m_uOffset+=FUN_14020b170(text,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x14083A060, CByteBuffer, COutputStream, WriteUnicodeString, 224, 0x84884C79);
// @0x14083a150
void CByteBuffer::WriteBytes(const void* data,int count) { FUN_140204670(count);m_uOffset+=FUN_14020aec0(data,count,&m_aByteBuff[0]+m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x14083A150, CByteBuffer, COutputStream, WriteBytes, 108, 0xAF97CEE0);
// @0x14083a1d0
void CByteBuffer::WriteVector3(const Unk_StreamPoint& value) { WriteFloat(value.x);WriteFloat(value.y);WriteFloat(value.z); }
MS2_REPLACE_METHOD_VIA(0x14083A1D0, CByteBuffer, COutputStream, WriteVector3, 135, 0x188D4181);
// @0x14083a260
void CByteBuffer::WriteVector3Short(const Unk_StreamPoint& value) { WriteInt16((short)value.x);WriteInt16((short)value.y);WriteInt16((short)(value.z+0.0001f)); }
MS2_REPLACE_METHOD_VIA(0x14083A260, CByteBuffer, COutputStream, WriteVector3Short, 147, 0x0CFE1934);
// @0x14083a300
void CByteBuffer::vfunc_2(int n,unsigned uOffset) { MS2_ASSERT_AT(200,m_aByteBuff.GetCount() >= uOffset + FUN_14020abe0(n));FUN_14020ad80(n,&m_aByteBuff[0]+uOffset); }
MS2_REPLACE_METHOD(0x14083A300, CByteBuffer, vfunc_2, 141, 0xC46FB140);
// @0x14083a3a0
void CByteBuffer::WriteShortX10(float value) { short n=(short)(value/10.f);WriteInt16(n); }
MS2_REPLACE_METHOD_VIA(0x14083A3A0, CByteBuffer, COutputStream, WriteShortX10, 77, 0x51B630F9);
// @0x14083a400
void CByteBuffer::WriteShortX100(float value) { short n=(short)(value/100.f);WriteInt16(n); }
MS2_REPLACE_METHOD_VIA(0x14083A400, CByteBuffer, COutputStream, WriteShortX100, 77, 0xB6420C1F);
// @0x14083a460
void CByteBuffer::WriteShortScaled(float value,int scale) { short n=(short)(value/(float)scale);WriteInt16(n); }
MS2_REPLACE_METHOD_VIA(0x14083A460, CByteBuffer, COutputStream, WriteShortScaled, 87, 0xD72B1FBA);
// @0x14083a4c0
void CByteBuffer::WriteShortDiv10(float value) { short n=(short)(value*10.f);WriteInt16(n); }
MS2_REPLACE_METHOD_VIA(0x14083A4C0, CByteBuffer, COutputStream, WriteShortDiv10, 77, 0xBB7021DD);
// @0x14083a520
void CByteBuffer::WriteShortDivScaled(float value,int scale) { short n=(short)(value*(float)scale);WriteInt16(n); }
MS2_REPLACE_METHOD_VIA(0x14083A520, CByteBuffer, COutputStream, WriteShortDivScaled, 87, 0x9BA54DAB);
// @0x14083a580
bool CByteBuffer::ReadBool() { return ReadUInt8()?true:false; }
MS2_REPLACE_METHOD_VIA(0x14083A580, CByteBuffer, CInputStream, ReadBool, 67, 0xE061F660);
// @0x14083a5d0
unsigned char CByteBuffer::ReadUInt8() { unsigned char value;m_uOffset+=FUN_140713970(value,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset);return value; }
MS2_REPLACE_METHOD_VIA(0x14083A5D0, CByteBuffer, CInputStream, ReadUInt8, 113, 0x561BE4EF);
// @0x14083a650
short CByteBuffer::ReadInt16() { short value;m_uOffset+=FUN_140713ae0(value,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset);return value; }
MS2_REPLACE_METHOD_VIA(0x14083A650, CByteBuffer, CInputStream, ReadInt16, 113, 0xA5C7A791);
// @0x14083a6d0
int CByteBuffer::ReadInt32() { int value;m_uOffset+=FUN_140713c50(value,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset);return value; }
MS2_REPLACE_METHOD_VIA(0x14083A6D0, CByteBuffer, CInputStream, ReadInt32, 112, 0x9F2B20EC);
// @0x14083a750
__int64 CByteBuffer::ReadInt64() { __int64 value;m_uOffset+=FUN_140713db0(value,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset);return value; }
MS2_REPLACE_METHOD_VIA(0x14083A750, CByteBuffer, CInputStream, ReadInt64, 113, 0x014FB177);
// @0x14083a7d0
float CByteBuffer::ReadFloat() { float value;m_uOffset+=FUN_140714ab0(value,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset);return value; }
MS2_REPLACE_METHOD_VIA(0x14083A7D0, CByteBuffer, CInputStream, ReadFloat, 114, 0x77CCFCAF);
// @0x14083a850
CString CByteBuffer::ReadUnicodeStringA() { CStringW value;m_uOffset+=FUN_1407145e0(value,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset);return FUN_1401d4330(value,0); }
MS2_REPLACE_METHOD_VIA(0x14083A850, CByteBuffer, CInputStream, ReadUnicodeStringA, 196, 0x89F4B84D);
// @0x14083a920
CString CByteBuffer::ReadString() { CString value;m_uOffset+=FUN_140714210(value,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset);return value; }
MS2_REPLACE_METHOD_VIA(0x14083A920, CByteBuffer, CInputStream, ReadString, 185, 0x269EF53D);
// @0x14083a9e0
CStringW CByteBuffer::ReadUnicodeString() { CStringW value;m_uOffset+=FUN_1407145e0(value,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset);return value; }
MS2_REPLACE_METHOD_VIA(0x14083A9E0, CByteBuffer, CInputStream, ReadUnicodeString, 185, 0x4D56ACDF);
// @0x14083aaa0
void CByteBuffer::ReadBytes(void* data,int count) { m_uOffset+=FUN_140713f20(data,count,&m_aByteBuff[0]+m_uOffset,m_uLength-m_uOffset); }
MS2_REPLACE_METHOD_VIA(0x14083AAA0, CByteBuffer, CInputStream, ReadBytes, 124, 0xA2775042);
// @0x14083ab30
Unk_StreamPoint CByteBuffer::ReadVector3() { Unk_StreamPoint value;value.x=ReadFloat();value.y=ReadFloat();value.z=ReadFloat();return value; }
MS2_REPLACE_METHOD_VIA(0x14083AB30, CByteBuffer, CInputStream, ReadVector3, 163, 0x8FBF854D);
// @0x14083abe0
Unk_StreamPoint CByteBuffer::ReadVector3Short() { Unk_StreamPoint value;value.x=(float)ReadInt16();value.y=(float)ReadInt16();value.z=(float)ReadInt16();return value; }
MS2_REPLACE_METHOD_VIA(0x14083ABE0, CByteBuffer, CInputStream, ReadVector3Short, 178, 0x1B7A6561);
// @0x14083aca0
float CByteBuffer::ReadShortX10() { float value=(float)ReadInt16()*10.f;return value; }
MS2_REPLACE_METHOD_VIA(0x14083ACA0, CByteBuffer, CInputStream, ReadShortX10, 68, 0x78C99F0E);
// @0x14083acf0
float CByteBuffer::ReadShortX100() { float value=(float)ReadInt16()*100.f;return value; }
MS2_REPLACE_METHOD_VIA(0x14083ACF0, CByteBuffer, CInputStream, ReadShortX100, 68, 0x3B21EC5B);
// @0x14083ad40
float CByteBuffer::ReadShortScaled(int scale) { float value=(float)ReadInt16()*(float)scale;return value; }
MS2_REPLACE_METHOD_VIA(0x14083AD40, CByteBuffer, CInputStream, ReadShortScaled, 74, 0x3B9319CB);
// @0x14083ad90
float CByteBuffer::ReadShortDiv10() { float value=(float)ReadInt16()/10.f;return value; }
MS2_REPLACE_METHOD_VIA(0x14083AD90, CByteBuffer, CInputStream, ReadShortDiv10, 68, 0x6A4A3418);
// @0x14083ade0
float CByteBuffer::ReadShortDivScaled(int scale) { float value=(float)ReadInt16()/(float)scale;return value; }
MS2_REPLACE_METHOD_VIA(0x14083ADE0, CByteBuffer, CInputStream, ReadShortDivScaled, 74, 0xBC626986);
// @0x14083ae30
void CByteBuffer::SetLength(int length) {
    if(length<=0) {m_aByteBuff.RemoveAll();m_uOffset=0;m_uLength=0;}
    else {if(length>(int)m_uLength)m_aByteBuff.SetCount(length);
        if((int)m_aByteBuff.GetCount()>=length)m_uLength=length;
        m_uOffset=m_uOffset<m_uLength?m_uOffset:m_uLength;
    }
}
MS2_REPLACE_METHOD(0x14083AE30, CByteBuffer, SetLength, 204, 0xF918E4A9);
// @0x14083af10
bool CByteBuffer::TestCompression() {
    bool ok=false;
    CByteBuffer source,packed,unpacked;
    Unk_StreamTest original={100,1000,L"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
    source.WriteUInt8(original.byte);source.WriteInt32(original.number);source.WriteUnicodeString(original.text);
    ok=source.Compress(packed);if(!ok){MS2_ASSERT_AT(512,0);return false;}
    ok=packed.Uncompress(unpacked);if(!ok){MS2_ASSERT_AT(519,0);return false;}
    Unk_StreamTest copy;
    copy.byte=unpacked.ReadUInt8();copy.number=unpacked.ReadInt32();copy.text=unpacked.ReadUnicodeString();
    ok=original.byte==copy.byte && original.number==copy.number && original.text==copy.text;
    if(!ok){MS2_ASSERT_AT(534,0);return false;}
    int len=source.GetLength();int len2=unpacked.GetLength();
    ok=len==len2;
    if(!ok){MS2_ASSERT_AT(548,0);return false;}
    return true;
}
MS2_REPLACE(0x14083AF10, CByteBuffer::TestCompression, 976, 0xE3CCF212);
// @0x14083b2f0
void Unk_CompressedStream::Encode(COutputStream& out) {
    CByteBuffer* data=0;
    if(m_raw.GetLength()<m_threshold)m_useCompression=false;
    if(m_useCompression){m_raw.Compress(m_compressed);data=&Compressed();} else {m_raw.FUN_140720e90(0);m_raw.FUN_140720c30(m_compressed);data=&FUN_140714de0();}
    out.WriteBool(m_useCompression);out.WriteInt32(data->GetLength());out.WriteBytes(data->FUN_140204eb0(),data->GetLength());
}
MS2_REPLACE_METHOD(0x14083B2F0, Unk_CompressedStream, Encode, 298, 0x2C116931);
// @0x14083b420
CByteBuffer& Unk_CompressedStream::Decode(CInputStream& in) {
    m_useCompression=in.ReadBool();unsigned count=in.ReadInt32();
    m_raw.FUN_140204670(count);in.ReadBytes(m_raw.FUN_140204eb0(),count);
    if(m_useCompression){bool ok=m_raw.Uncompress(m_compressed);MS2_ASSERT_AT(593,ok);}
    else {m_raw.FUN_140720c30(m_compressed);m_compressed.FUN_140720e90(0);}
    return m_compressed;
}
MS2_REPLACE_METHOD(0x14083B420, Unk_CompressedStream, Decode, 260, 0xE4D13373);
// @0x14083b530
void Unk_CompressedStream::EncodeReady(COutputStream& out) {
    CByteBuffer* data=0; if(m_useCompression)data=&Compressed();else data=&FUN_140714de0();
    out.WriteBool(m_useCompression);out.WriteInt32(data->GetLength());out.WriteBytes(data->FUN_140204eb0(),data->GetLength());
}
MS2_REPLACE_METHOD(0x14083B530, Unk_CompressedStream, EncodeReady, 201, 0xD0C38066);
// @0x14083b600
void Unk_StreamWrapper::Encode(COutputStream& out,bool raw) {
    if(raw){CByteBuffer& data=Raw();out.WriteBytes(data.FUN_140204eb0(),data.GetLength());}
    else {if(m_dirty){Prepare(out);SetDirty(false);}else EncodeReady(out);}
}
MS2_REPLACE_METHOD(0x14083B600, Unk_StreamWrapper, Encode, 170, 0xACEB3D74);
// @0x14083b6b0
void Unk_StreamWrapper::Decode(CInputStream& in) { Read(in); }
MS2_REPLACE_METHOD(0x14083B6B0, Unk_StreamWrapper, Decode, 34, 0xDD506B28);
// @0x14083b6e0
bool Unk_StreamWrapper::Update(bool compression,unsigned threshold) { Configure(compression,threshold);return m_dirty; }
MS2_REPLACE_METHOD(0x14083B6E0, Unk_StreamWrapper, Update, 55, 0x3D3AF75D);
// @0x14083b720
void Unk_StreamWrapper::Configure(bool compression,unsigned threshold) { if(!m_dirty && !compression)m_dirty=true;if(m_dirty){m_stream.SetCompressed(compression);m_stream.SetThreshold(threshold);} }
MS2_REPLACE_METHOD(0x14083B720, Unk_StreamWrapper, Configure, 119, 0xED0AE760);
