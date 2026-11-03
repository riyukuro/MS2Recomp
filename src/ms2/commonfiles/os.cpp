// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Operating-system queries and input stream extraction.
// MS2-UNIT: commonfiles\os.cpp
// MS2-PIN: ??_GCOSInfo@@UEAAPEAXI@Z 0x14070f1a0
// MS2-RANGE: 0x14070e080-0x14070f700 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\os.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "os.h"
#define EE_EFD_CONFIG_RELEASE
#define EE_USE_NATIVE_STL
#include <efd/ILogger.h>
#include <efd/Helpers.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
// @0x14070e080
void COSInfo::StartUp() {
    if(m_data == 0) {
        char country[8] = "\n";
        if(GetLocaleInfoA(0x800, 5, country, 7)) m_country = atoi(country);
        m_data = new Unk_OSData;
        memset(&m_data->system, 0, sizeof(SYSTEM_INFO));
        memset(&m_data->version, 0, sizeof(OSVERSIONINFOEXA));
        typedef void (WINAPI* NativeInfo)(LPSYSTEM_INFO);
        NativeInfo nativeInfo = (NativeInfo)GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetNativeSystemInfo");
        if(nativeInfo) nativeInfo(&m_data->system);
        else GetSystemInfo(&m_data->system);
        if(m_data->system.wProcessorArchitecture == 6 || m_data->system.wProcessorArchitecture == 9) m_data->is64 = true;
        m_data->version.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXA);
        BOOL ok = GetVersionExA((LPOSVERSIONINFOA)&m_data->version);
        if(!ok) {
            EE_LOG_AT(1, 1, ("COSInfo::StartUp() - Failed to GetVersion"), MS2_THIS_FILE, 80);
        } else if(m_data->version.dwPlatformId == 1) {
            if(m_data->version.dwMajorVersion == 4) {
                if(m_data->version.dwMinorVersion <= 0) m_data->kind = 1;
                else if(m_data->version.dwMinorVersion >= 10) m_data->kind = 2;
                else if(m_data->version.dwMinorVersion >= 90) m_data->kind = 3;
                else m_data->kind = 4;
            } else m_data->kind = 5;
            m_data->family = 2;
            m_data->isNT = false;
        } else if(m_data->version.dwPlatformId == 2) {
            if(m_data->version.dwMajorVersion <= 3) {
                if(m_data->version.dwMinorVersion <= 51) m_data->kind = 6;
                else m_data->kind = 7;
            } else if(m_data->version.dwMajorVersion <= 4) {
                if(m_data->version.dwMinorVersion <= 0) m_data->kind = 8;
                else m_data->kind = 9;
            } else if(m_data->version.dwMajorVersion <= 5) {
                if(m_data->version.dwMinorVersion <= 0) m_data->kind = 10;
                else if(m_data->version.dwMinorVersion <= 1) m_data->kind = 11;
                else if(m_data->version.dwMinorVersion <= 2) m_data->kind = 12;
                else m_data->kind = 13;
            } else if(m_data->version.dwMajorVersion <= 6) {
                if(m_data->version.dwMinorVersion <= 0) {
                    if(m_data->version.wProductType == 1) m_data->kind = 15;
                    else m_data->kind = 14;
                } else if(m_data->version.dwMinorVersion == 1) m_data->kind = 16;
                else if(m_data->version.dwMinorVersion == 2) {
                    if(m_data->version.wProductType == 1) m_data->kind = 18;
                    else m_data->kind = 17;
                } else if(m_data->version.dwMinorVersion == 3) {
                    if(m_data->version.wProductType == 1) m_data->kind = 20;
                    else m_data->kind = 19;
                } else m_data->kind = 21;
            } else if(m_data->version.dwMajorVersion <= 10) {
                if(m_data->version.wProductType == 1) m_data->kind = 22;
                else m_data->kind = 23;
            } else m_data->kind = 24;
            m_data->family = 3;
            m_data->isNT = true;
        } else {
            if(m_data->version.dwPlatformId == 0) m_data->family = 1;
            else m_data->family = 0;
            m_data->kind = 0;
            m_data->isNT = false;
        }
    }
}
MS2_REPLACE_METHOD(0x14070E080, COSInfo, StartUp, 1955, 0x3569FAAE);
// @0x14070e830
void COSInfo::ShutDown() { if(m_data) { delete m_data; m_data=0; } }
MS2_REPLACE_METHOD(0x14070E830, COSInfo, ShutDown, 68, 0x51C91A49);
// @0x14070e880
CString COSInfo::GetName() {
    if(m_data) { switch(m_data->kind) {
    case 1: return "Microsoft Windows 95";
    case 2: return "Microsoft Windows 98";
    case 3: return "Microsoft Windows Me";
    case 4: return "Microsoft Windows 95 (Unknown)";
    case 5: return "Microsoft Windows (Unknown 95 Core)";
    case 6: return "Microsoft Windows NT 3.51";
    case 7: return "Microsoft Windows NT 3 (Unknown)";
    case 8: return "Microsoft Windows NT 4";
    case 9: return "Microsoft Windows NT 4 (Unknown)";
    case 10: return "Microsoft Windows 2000";
    case 0xb: return "Microsoft Windows XP";
    case 0xc: return "Microsoft Windows Server 2003";
    case 0xd: return "Microsoft Windows NT 5 (Unknown)";
    case 0xe: return "Microsoft Windows Server 2008";
    case 0xf: return "Microsoft Windows Vista";
    case 0x10: return "Microsoft Windows 7";
    case 0x11: return "Microsoft Windows Server 2012";
    case 0x12: return "Microsoft Windows 8";
    case 0x13: return "Microsoft Windows Server 2012R";
    case 0x14: return "Microsoft Windows 8.1";
    case 0x15: return "Microsoft Windows Vista (Unknown)";
    case 0x16: return "Microsoft Windows 10";
    case 0x17: return "Microsoft Windows Server 2016";
    case 0x18: return "Microsoft Windows (Unknown NT Core)";
    default: return "Unknown OS";
    } }
    return (const char*)0;
}
MS2_REPLACE_METHOD(0x14070E880, COSInfo, GetName, 1102, 0xD06CD2A2);
// @0x14070ed40
COSInfo::COSInfo() : m_data(0),m_country(0) { StartUp(); }
// @0x14070eda0
COSInfo::~COSInfo() { ShutDown(); }
// @0x14070edf0
bool COSInfo::IsNT() { if(m_data) return m_data->isNT; return false; }
MS2_REPLACE_METHOD(0x14070EDF0, COSInfo, IsNT, 38, 0xBBDFEE59);
// @0x14070ee20
bool COSInfo::Is64Bit() { if(m_data) return m_data->is64; return false; }
MS2_REPLACE_METHOD(0x14070EE20, COSInfo, Is64Bit, 38, 0x90424FC2);
// @0x14070ee50
CString COSInfo::GetFullName() {
    if(m_data) {
        if(Is64Bit()) return GetName() + " x64";
        else return GetName() + " x86";
    }
    return (const char*)0;
}
MS2_REPLACE_METHOD(0x14070EE50, COSInfo, GetFullName, 260, 0xCD42FC0D);
// @0x14070ef60
CString COSInfo::GetServicePack() { if(m_data) return m_data->version.szCSDVersion; return (const char*)0; }
MS2_REPLACE_METHOD(0x14070EF60, COSInfo, GetServicePack, 113, 0x1E81E342);
// @0x14070efe0
int COSInfo::GetKind() { if(m_data) return m_data->kind; return 0; }
MS2_REPLACE_METHOD(0x14070EFE0, COSInfo, GetKind, 37, 0x78D58E9B);
// @0x14070f010
int COSInfo::GetFamily() { if(m_data) return m_data->family; return 0; }
MS2_REPLACE_METHOD(0x14070F010, COSInfo, GetFamily, 37, 0xE2C1F2A7);
// @0x14070f040
unsigned long COSInfo::GetMajor() { if(m_data) return m_data->version.dwMajorVersion; return 0; }
MS2_REPLACE_METHOD(0x14070F040, COSInfo, GetMajor, 34, 0x8E8A5A38);
// @0x14070f070
unsigned long COSInfo::GetMinor() { if(m_data) return m_data->version.dwMinorVersion; return 0; }
MS2_REPLACE_METHOD(0x14070F070, COSInfo, GetMinor, 34, 0xFDE2CEAC);
// @0x14070f0a0
unsigned long COSInfo::GetProcessorCount() { if(m_data) return m_data->system.dwNumberOfProcessors; return 0; }
MS2_REPLACE_METHOD(0x14070F0A0, COSInfo, GetProcessorCount, 37, 0x425B8A4B);
MS2_EMIT_CRT_MEMMOVE_S();
// @0x14070f300
Unk_OSInput& Unk_OSInput::Read0(bool& value) { value=vfunc_0(); return *this; }
MS2_REPLACE_METHOD(0x14070F300, Unk_OSInput, Read0, 46, 0x1AE1FA6B);
// @0x14070f340
Unk_OSInput& Unk_OSInput::Read1(unsigned char& value) { value=vfunc_1(); return *this; }
MS2_REPLACE_METHOD(0x14070F340, Unk_OSInput, Read1, 47, 0x935E8BC3);
// @0x14070f380
Unk_OSInput& Unk_OSInput::Read2(short& value) { value=vfunc_2(); return *this; }
MS2_REPLACE_METHOD(0x14070F380, Unk_OSInput, Read2, 48, 0xEF15A43A);
// @0x14070f3c0
Unk_OSInput& Unk_OSInput::Read3(unsigned short& value) { value=vfunc_2(); return *this; }
MS2_REPLACE_METHOD(0x14070F3C0, Unk_OSInput, Read3, 48, 0xEF15A43A);
// @0x14070f400
Unk_OSInput& Unk_OSInput::Read4(int& value) { value=vfunc_3(); return *this; }
MS2_REPLACE_METHOD(0x14070F400, Unk_OSInput, Read4, 47, 0x35B90A4E);
// @0x14070f440
Unk_OSInput& Unk_OSInput::Read5(long& value) { value=vfunc_3(); return *this; }
MS2_REPLACE_METHOD(0x14070F440, Unk_OSInput, Read5, 47, 0x35B90A4E);
// @0x14070f480
Unk_OSInput& Unk_OSInput::Read6(unsigned int& value) { value=vfunc_3(); return *this; }
MS2_REPLACE_METHOD(0x14070F480, Unk_OSInput, Read6, 47, 0x35B90A4E);
// @0x14070f4c0
Unk_OSInput& Unk_OSInput::Read7(__int64& value) { value=vfunc_4(); return *this; }
MS2_REPLACE_METHOD(0x14070F4C0, Unk_OSInput, Read7, 48, 0x1277F828);
// @0x14070f500
Unk_OSInput& Unk_OSInput::Read8(unsigned __int64& value) { value=vfunc_4(); return *this; }
MS2_REPLACE_METHOD(0x14070F500, Unk_OSInput, Read8, 48, 0x1277F828);
// @0x14070f540
Unk_OSInput& Unk_OSInput::Read9(float& value) { value=vfunc_5(); return *this; }
MS2_REPLACE_METHOD(0x14070F540, Unk_OSInput, Read9, 49, 0x31C7829F);
// @0x14070f580
Unk_OSInput& Unk_OSInput::Read10(CString& value) { value=vfunc_7(); return *this; }
MS2_REPLACE_METHOD(0x14070F580, Unk_OSInput, Read10, 97, 0xB244067C);
// @0x14070f5f0
Unk_OSInput& Unk_OSInput::Read11(CStringW& value) { value=vfunc_8(); return *this; }
MS2_REPLACE_METHOD(0x14070F5F0, Unk_OSInput, Read11, 97, 0x5BF0625C);
// @0x14070f660
Unk_OSInput& Unk_OSInput::Read12(Unk_OSId& value) { value=Unk_OSId(vfunc_4()); return *this; }
MS2_REPLACE_METHOD(0x14070F660, Unk_OSInput, Read12, 64, 0x1DDE707F);
// @0x14070f6b0
Unk_OSInput& Unk_OSInput::Read13(Unk_OSNumber& value) { value=Unk_OSNumber(vfunc_4()); return *this; }
MS2_REPLACE_METHOD(0x14070F6B0, Unk_OSInput, Read13, 66, 0x5DF6D9DC);
