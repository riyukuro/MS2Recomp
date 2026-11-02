// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: commonfiles\packetlogger.cpp
// MS2-PIN: ?Find@?$CRBTree@HV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@H@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@IEBAPEAVCNode@12@H@Z 0x140717af0
// MS2-PIN: ?GetLength@Unk_LogInPacket@@QEBAHXZ 0x140717cb0
// MS2-PIN: ?GetSequence@Unk_LogInPacket@@QEBAHXZ 0x140717cc0
// MS2-RANGE: 0x140716a40-0x1407186f0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\packetlogger.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "packetlogger.h"
#include <shlwapi.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/xmlattr.h"
class Unk_1401b4ec0 { public: Unk_1401b4ec0(CLockCriticalSection&,int); ~Unk_1401b4ec0(); private: void* p; };
CStringW FUN_14016a730(const char*,int);
CString FUN_14016a600(const wchar_t*,int);
unsigned __int64 FUN_1403d7cb0(const CStringW&);
// @0x140716a40
CPacketLogger::CPacketLogger() : m_client(false),m_enabled(false),m_sendRate(0),m_sendBytes(0),m_receiveRate(0),m_receiveBytes(0) { m_lastReceive=0;m_lastSend=0; }
// @0x140716b60
CPacketLogger::~CPacketLogger() { Close(); }
// @0x140716bf0
bool CPacketLogger::Configure(bool enabled,bool client,bool open) { m_enabled=enabled;m_client=client;if(open)Open();return 1; }
MS2_REPLACE_METHOD(0x140716BF0, CPacketLogger, Configure, 75, 0x7A2643E9);
// @0x140716c50
void CPacketLogger::LogSend(int opcode,const Unk_LogOutPacket& packet) {
    if(!m_enabled)return;
    {
        if(m_receiveBytes<0x100000)m_receiveBytes+=reinterpret_cast<const COutPacket&>(packet).FUN_14020b9f0();
        if(m_file.m_h && ShouldSend(opcode,packet)) {
            CString format=Timestamp(0);Write(format,DescribeSend(opcode,packet));m_lastSend=opcode;
        }
    }
}
MS2_REPLACE_METHOD(0x140716C50, CPacketLogger, LogSend, 258, 0x3EAD989D);
// @0x140716d60
void CPacketLogger::LogReceive(int opcode,const Unk_LogInPacket& packet) {
    if(!m_enabled)return;
    {
        if(m_sendBytes<0x100000)m_sendBytes+=packet.GetLength();
        if(m_file.m_h && ShouldReceive(opcode,packet)) {
            CString format=Timestamp(1);Write(format,DescribeReceive(opcode,packet));m_lastReceive=opcode;
        }
    }
}
MS2_REPLACE_METHOD(0x140716D60, CPacketLogger, LogReceive, 261, 0xA9C74171);
// @0x140716e70
void CPacketLogger::Update() { if(m_timer.Check(1000)){m_sendRate=(float)m_sendBytes;m_sendBytes=0;m_receiveRate=(float)m_receiveBytes;m_receiveBytes=0;} }
MS2_REPLACE_METHOD(0x140716E70, CPacketLogger, Update, 124, 0xD63C88FA);
// @0x140716f00
const float& CPacketLogger::SendRate() const {return m_sendRate;}
MS2_REPLACE_METHOD(0x140716F00, CPacketLogger, SendRate, 17, 0x7500A253);
// @0x140716f20
const float& CPacketLogger::ReceiveRate() const {return m_receiveRate;}
MS2_REPLACE_METHOD(0x140716F20, CPacketLogger, ReceiveRate, 17, 0xAA3C736B);
// @0x140716f40
void CPacketLogger::Open() {
    SYSTEMTIME time;GetLocalTime(&time);CString name;
    if(m_client) name.Format("packet_client_%04d%02d%02d_%02d%02d%02d%03d.txt",time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);
    else name.Format("packet_game_%04d%02d%02d_%02d%02d%02d%03d.txt",time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);
    const char* directory=".\\log";
    char path[MAX_PATH]={0};char filename[MAX_PATH]={0};
    if(!GetFullPathNameA(directory,MAX_PATH,path,0)){MS2_ASSERT_AT(302,0);return;}
    if(!PathIsDirectoryA(path))CreateDirectoryA(path,0);
    PathCombineA(filename,path,name);
    Unk_LockGuard lock(m_lock);
    if(lock.operator int()!=0){}else
    {m_file.Create(filename,GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,OPEN_ALWAYS);m_file.Seek(0,FILE_END);if(m_client)WriteHeader();}
}
MS2_REPLACE_METHOD(0x140716F40, CPacketLogger, Open, 678, 0xD988DD1E);
// @0x1407171f0
void CPacketLogger::WriteHeader() {}
MS2_REPLACE_METHOD(0x1407171F0, CPacketLogger, WriteHeader, 6, 0xA9AF6E37);
// @0x140717200
void CPacketLogger::Close() { if(m_file.m_h){m_file.Flush();m_file.Close();} }
MS2_REPLACE_METHOD(0x140717200, CPacketLogger, Close, 60, 0x588D41BE);
// @0x140717250
bool CPacketLogger::ShouldReceive(int opcode,const Unk_LogInPacket& packet) const {
    if(packet.GetFlags())return false;
    if(opcode==m_lastReceive)return false;
    if(m_client)return AllowClient(opcode);else return AllowGame(opcode);
}
MS2_REPLACE_METHOD(0x140717250, CPacketLogger, ShouldReceive, 105, 0x3032FC2F);
// @0x1407172d0
bool CPacketLogger::ShouldSend(int opcode,const Unk_LogOutPacket& packet) const {
    if(reinterpret_cast<const COutPacket&>(packet).FUN_14020bc40())return false;
    if(opcode==m_lastSend)return false;
    if(m_client)return AllowGame(opcode);else return AllowClient(opcode);
}
MS2_REPLACE_METHOD(0x1407172D0, CPacketLogger, ShouldSend, 105, 0x1A4DEF22);
// @0x140717350
bool CPacketLogger::AllowClient(int opcode) const { switch(opcode){case 17:case 28:case 88:case 126:case 135:case 217:return false;}return true; }
MS2_REPLACE_METHOD(0x140717350, CPacketLogger, AllowClient, 80, 0x0A6801AB);
// @0x140717480
bool CPacketLogger::AllowGame(int opcode) const { switch(opcode){case 11:case 18:return false;}return true; }
MS2_REPLACE_METHOD(0x140717480, CPacketLogger, AllowGame, 45, 0xC3C0542A);
// @0x1407174c0
CString CPacketLogger::Timestamp(int direction) const {
    SYSTEMTIME time;GetLocalTime(&time);CString format;
    switch(direction){
    case 0:format.Format("[%02d:%02d:%02d.%03d] %%80s\r\n",time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);break;
    case 1:format.Format("[%02d:%02d:%02d.%03d] %%-80s\r\n",time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);break;
    default:MS2_ASSERT_AT(200,FALSE);break;
    }
    return format;
}
MS2_REPLACE_METHOD(0x1407174C0, CPacketLogger, Timestamp, 300, 0x34F8F3DC);
// @0x140717600
CString CPacketLogger::DescribeReceive(int opcode,const Unk_LogInPacket& packet) const {
    CString text;CString name;int code=opcode;int length=packet.GetLength();
    if(m_client && !m_receiveNames.Lookup(code,name))name="Undefined";
    text.Format("%s(%d)(size:%d)(seq:%d)",(const char*)name,code,length,packet.GetSequence());return text;
}
MS2_REPLACE_METHOD(0x140717600, CPacketLogger, DescribeReceive, 289, 0x7E4E80BD);
// @0x140717730
CString CPacketLogger::DescribeSend(int opcode,const Unk_LogOutPacket& packet) const {
    CString text;CString name;int code=opcode;int length=reinterpret_cast<const COutPacket&>(packet).FUN_14020b9f0();
    if(!m_client){}else {if(!m_sendNames.Lookup(code,name))name="Undefined";}
    text.Format("%s(%d)(size:%d)(seq:%d)",(const char*)name,code,length,reinterpret_cast<const COutPacket&>(packet).FUN_14020ba00());return text;
}
MS2_REPLACE_METHOD(0x140717730, CPacketLogger, DescribeSend, 289, 0xAA1B9B85);
// @0x140717860
void CPacketLogger::Write(const CString& format,const CString& message) {
    CString text;text.Format(format,(const char*)message);
    Unk_1401b4ec0 lock(m_lock,1);
    ATL::CAtlStringA output(text);m_file.Write((const char*)output,output.GetLength(),(DWORD*)0);
}
MS2_REPLACE_METHOD(0x140717860, CPacketLogger, Write, 222, 0x49D880BC);
MS2_EMIT_CRT_MEMMOVE_S();
// @0x1407180b0
int FUN_1407180b0(const CString& value) { return (int)atoi(value); }
MS2_REPLACE(0x1407180B0, FUN_1407180b0, 34, 0x025377C4);
// @0x1407180e0
int FUN_1407180e0(const CStringW& value) { return (int)_wtoi(value); }
MS2_REPLACE(0x1407180E0, FUN_1407180e0, 34, 0xEFA5A5A7);
// @0x140718110
unsigned FUN_140718110(const CString& value) { return (unsigned)atoi(value); }
MS2_REPLACE(0x140718110, FUN_140718110, 34, 0xDD3E476F);
// @0x140718140
unsigned FUN_140718140(const CStringW& value) { return (unsigned)_wtoi(value); }
MS2_REPLACE(0x140718140, FUN_140718140, 34, 0x72E13427);
// @0x140718170
short FUN_140718170(const CString& value) { return (short)atoi(value); }
MS2_REPLACE(0x140718170, FUN_140718170, 34, 0x6A12126F);
// @0x1407181a0
int FUN_1407181a0(const CStringW& value) { return _wtoi(value); }
MS2_REPLACE(0x1407181A0, FUN_1407181a0, 34, 0x98CF054B);
// @0x1407181d0
unsigned int FUN_1407181d0(const CString& value) { return atoi(value); }
MS2_REPLACE(0x1407181D0, FUN_1407181d0, 34, 0x50004183);
// @0x140718200
unsigned short FUN_140718200(const CStringW& value) { return (unsigned short)_wtoi(value); }
MS2_REPLACE(0x140718200, FUN_140718200, 34, 0x3EB409CB);
// @0x140718230
long FUN_140718230(const CString& value) { return (long)atol(value); }
MS2_REPLACE(0x140718230, FUN_140718230, 34, 0x72CD199B);
// @0x140718260
long FUN_140718260(const CStringW& value) { return (long)_wtol(value); }
MS2_REPLACE(0x140718260, FUN_140718260, 34, 0xB8D1A564);
// @0x140718290
unsigned long FUN_140718290(const CString& value) { return (unsigned long)atol(value); }
MS2_REPLACE(0x140718290, FUN_140718290, 34, 0x7790581B);
// @0x1407182c0
unsigned long FUN_1407182c0(const CStringW& value) { return (unsigned long)_wtol(value); }
MS2_REPLACE(0x1407182C0, FUN_1407182c0, 34, 0xBBFF2B24);
// @0x1407182f0
__int64 FUN_1407182f0(const CString& value) { return (__int64)_atoi64(value); }
MS2_REPLACE(0x1407182F0, FUN_1407182f0, 34, 0xBE8E21FF);
// @0x140718320
__int64 FUN_140718320(const CStringW& value) { return (__int64)_wtoi64(value); }
MS2_REPLACE(0x140718320, FUN_140718320, 34, 0xA55FE927);
// @0x140718350
unsigned __int64 FUN_140718350(const CString& value) {return XmlConvert<unsigned __int64>(value);}
MS2_REPLACE(0x140718350, FUN_140718350, 24, 0xFD556A71);
// @0x140718370
unsigned __int64 FUN_140718370(const CStringW& value) {return FUN_1403d7cb0(value);}
MS2_REPLACE(0x140718370, FUN_140718370, 24, 0x4BA512C4);
// @0x140718390
bool FUN_140718390(const CString& value) {if(value.IsEmpty())return false;return value.FindOneOf("1oOtT")!=-1;}
MS2_REPLACE(0x140718390, FUN_140718390, 82, 0xBF97EEFE);
// @0x1407183f0
bool FUN_1407183f0(const CStringW& value) {if(value.IsEmpty())return false;return value.FindOneOf(L"1oOtT")!=-1;}
MS2_REPLACE(0x1407183F0, FUN_1407183f0, 82, 0x41F3574A);
// @0x140718450
float FUN_140718450(const CString& value) {return (float)atof(value);}
MS2_REPLACE(0x140718450, FUN_140718450, 38, 0xD5B205B4);
// @0x140718480
float FUN_140718480(const CStringW& value) {return (float)_wtof(value);}
MS2_REPLACE(0x140718480, FUN_140718480, 38, 0x335E5377);
// @0x1407184b0
double FUN_1407184b0(const CString& value) {return (double)atof(value);}
MS2_REPLACE(0x1407184B0, FUN_1407184b0, 34, 0xD6F6A6A4);
// @0x1407184e0
double FUN_1407184e0(const CStringW& value) {return (double)_wtof(value);}
MS2_REPLACE(0x1407184E0, FUN_1407184e0, 34, 0x1A085EE7);
// @0x140718510
char FUN_140718510(const CString& value) {if(value.GetLength()>0 && !value.IsEmpty())return value[0];return 0;}
MS2_REPLACE(0x140718510, FUN_140718510, 64, 0x689D98BC);
// @0x140718560
wchar_t FUN_140718560(const CStringW& value) {if(value.GetLength()>0 && !value.IsEmpty())return value[0];return 0;}
MS2_REPLACE(0x140718560, FUN_140718560, 64, 0xA74129BE);
// @0x1407185b0
CString FUN_1407185b0(const CString& value) {return value;}
MS2_REPLACE(0x1407185B0, FUN_1407185b0, 59, 0x2F42D480);
// @0x140718600
CStringW FUN_140718600(const CStringW& value) {return value;}
MS2_REPLACE(0x140718600, FUN_140718600, 59, 0xCCCC7D48);
// @0x140718650
CStringW FUN_140718650(const CString& value) {return FUN_14016a730(value,0);}
MS2_REPLACE(0x140718650, FUN_140718650, 70, 0x5C616411);
// @0x1407186a0
CString FUN_1407186a0(const CStringW& value) {return FUN_14016a600(value,0);}
MS2_REPLACE(0x1407186A0, FUN_1407186a0, 70, 0x1C0BFAF3);
