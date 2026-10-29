// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's nxman.cpp: CNXMan, the Nexon platform session
// singleton (game code, stage/UGC settings, login web response), the window-message event-handler chain, and the small
// HTTP/INI helpers it uses. See ms2/client/ms2/nxman.h.
// MS2-UNIT: ?\nxman.cpp
// MS2-RANGE: 0x14160d520-0x14160fb10 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nxman.cpp"
#define _WINSOCKAPI_
#include <afx.h>
#include <winsock2.h>
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/client/ms2/nxman.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/fmt/format.h"
#include "ms2/placeholder/cwinhttpclient.h"

#include <stdlib.h>
#include <errno.h>
#include <string.h>

#pragma comment(lib,"ws2_32.lib")

// ---- unrecovered callees (bound by VA) --------------------------------------------------------------------------------

void FUN_14160f720(void* p1, void** pOut, void* p3);
void FUN_14160f840(void* p1, void* p2, void* p3);
int  FUN_14160eb40(void*);
int  FUN_14160ecd0(void*);
fmt::ULongLong FUN_14160f890(const int* p);
fmt::ULongLong FUN_14160f870(const int* p);
enum Unk_NxErrorCode {};   // the formatted error code's enum type (only is_enum matters)

int  FUN_1415c3430(int nGameCode, const char* psz0, const char* psz1, const char* psz2, int nMode, int n6, int n7,
                   const char* pszLogContext, int n9, const char* psz10, int n11); // NMCO_ExecuteNGMPatcher
int  FUN_1415c3780(void);
int  FUN_1415c4540(void* p, int a, int b, int c, void* d);
int  FUN_1415c4810(void* p, int a);
void FUN_1415c4930(void* p, int a);
int  FUN_1415c4990(void* p, const char* psz, unsigned int nValue);
void FUN_1415c4a30(void* p);
void FUN_1415c4bb0(void* p, char* psz);
void FUN_1415c5010(void* p, char* psz);
void FUN_1415ca030(const char* pszA, const char* pszB, const char* pszC);
void FUN_1415ca240(void* pOut);
void FUN_1415cb420(void* p);
void FUN_1415cb430(void* p);
void FUN_1415cb760(void* pHandler, void* p1, void* p2);
void* FUN_1415fa1b0(void);
void* FUN_1415fa260(void);

// The platform service (FUN_140d86260): slot 22 logs a formatted line.
class Unk_NxPlatform
{
public:
#define NX_V(n) virtual void vfunc_##n();
    NX_V(0) NX_V(1) NX_V(2) NX_V(3) NX_V(4) NX_V(5) NX_V(6) NX_V(7) NX_V(8) NX_V(9)
    NX_V(10) NX_V(11) NX_V(12) NX_V(13) NX_V(14) NX_V(15) NX_V(16) NX_V(17) NX_V(18) NX_V(19)
    NX_V(20) NX_V(21)
#undef NX_V
    virtual void vfunc_22(int nId, const char* pszFormat, int nValue);
};
Unk_NxPlatform* FUN_140d86260(void);
void  FUN_140c79890(void* p);
void  FUN_140c79b50(void* p);

CStringA FUN_14016a600(const wchar_t* psz, int n = 0);      // wide -> narrow
CStringW FUN_14016a730(const char* psz, int n = 0);         // narrow -> wide
CStringA FUN_14016a5c0(const char* psz, int n = 0);
CStringA FUN_140188f50(const char* psz, int n = 0);
CString& FUN_140164930(CAtlArray<CString>& rArray, unsigned __int64 nIndex);
unsigned __int64 FUN_1401662c0(CAtlArray<CString>& rArray);
void FUN_14015f050(const CString& rString, CAtlArray<CString>& rArray, const char* pszSep);
bool FUN_140184310(const CString& rString, const char* psz);
CStringW FUN_140560c00(const wchar_t* pszFmt, const int& rArg);
CStringW FUN_14136e2e0(const wchar_t* pszFmt, const wchar_t* const& rArg);
CString  FUN_140540050(const char* pszFmt, const CString& rArg);
CStringW FUN_1401d02a0(const wchar_t* psz, const fmt::ArgList& args);
void     FUN_141b77e50(const CString& rString);
void     FUN_141b77e90(const CString& rString);
void*    FUN_1402da110(void* p1, void* p2, void* p3);
void     FUN_1416a0e70(void);

// The platform error table (0x48 bytes: RawString, one CAtlMap): index -> localized wide string. Its ctor/dtor live at 0x140c79890/0x140c79b50;
// the index lookup is the exe function at 0x140c7a360.
struct Unk_PlatformErrorTable
{
    void* m_pad[9];
    Unk_PlatformErrorTable() { FUN_140c79890(this); }
    ~Unk_PlatformErrorTable() { FUN_140c79b50(this); }
    CStringW FUN_140c7a360(const int& nIndex);
};

// Stage settings read from .\anysetting.ini / the platform helpers.
extern int DAT_143ac2fd0;                                   // platform error code
extern CStringW DAT_143ac2fe0;                              // platform error text
extern CString DAT_143ae0908;                               // default channel name
extern CString DAT_143ae0910;                               // default ugc address
extern CString DAT_143ae0918;                               // MapleStory2 service name
extern CString DAT_143ae0928;                               // login ip
extern int DAT_143ae08f8;                                   // login ip already cached
extern int DAT_143ae08f4;                                   // login port

// @0x14160d540
CNXMan::CNXMan()
{
    m_08 = 1;
    m_0c = 1;
    m_10 = 0;
    m_nGameCode = 0;
    m_88 = 0;
    m_90 = "";
    m_98 = "";
    m_30 = 0;
    FUN_14160e870();
    FUN_14160e9b0();
}

// @0x14160d710
CNXMan::~CNXMan()
{
}

// @0x14160d820
unsigned CNXMan::FUN_14160d820()
{
    Unk_PlatformErrorTable kErrors;
    if (FUN_14160e630() == 0)
    {
        DAT_143ac2fd0 = 0x44d;
        DAT_143ac2fe0 = kErrors.FUN_140c7a360(2);
        return 0;
    }
    FUN_1415cb420(FUN_1415fa260());
    if (FUN_1415c4540(FUN_1415fa1b0(), m_0c, m_10, 0, 0) == 0)
    {
        DAT_143ac2fd0 = 0x44e;
        DAT_143ac2fe0 = kErrors.FUN_140c7a360(2);
        return 0;
    }
    unsigned uResult = 1;
    if (FUN_1415c4810(FUN_1415fa1b0(), m_nGameCode) == 0)
    {
        uResult = 0;
        DAT_143ac2fd0 = 0x44f;
        DAT_143ac2fe0 = kErrors.FUN_140c7a360(2);
    }
    FUN_1415ca030("MapleStory2", (LPCSTR)m_str18, (LPCSTR)DAT_143ae0918);
    return uResult;
}

// @0x14160da80
void CNXMan::FUN_14160da80()
{
    FUN_14160dd20();
    FUN_14160db10();
    FUN_1415cb430(FUN_1415fa260());
}

// @0x14160dac0
bool CNXMan::FUN_14160dac0()
{
    return true;
}

// @0x14160db10
void CNXMan::FUN_14160db10()
{
    FUN_1415c4930(FUN_1415fa1b0(), 0);
}

// @0x14160db40
void CNXMan::FUN_14160db40(void* p1, void* p2)
{
    FUN_1415cb760(&m_eventHandler, p1, p2);
}

// @0x14160db80
int CNXMan::FUN_14160db80()
{
    CString strAddress = DAT_143ae0910;
    int bConnected = 0;
    if (strAddress.GetLength() > 0)
    {
        int nError = FUN_1415c4990(FUN_1415fa1b0(), (LPCSTR)strAddress, 0);
        if (nError == 0)
        {
            m_30 = 1;
            FUN_14160e410();
            bConnected = 1;
        }
        else
        {
            m_c0 = FUN_14016a600(FUN_14160ed00(nError), 0);
            SendMessageA(m_hWnd, 0x180, 0, (LPARAM)(LPCSTR)m_c0);
            bConnected = 0;
        }
    }
    if (bConnected == 0)
        return 0;
    return 1;
}

// @0x14160dd20
void CNXMan::FUN_14160dd20()
{
    if (m_30 != 0)
        FUN_1415c4a30(FUN_1415fa1b0());
}

// @0x14160dd50
int CNXMan::FUN_14160dd50(CStringW& rResult)
{
    CWinHttpClient kRequest(m_60);
    if (kRequest.FUN_140920cf0(L"GET", false))
    {
        if (kRequest.FUN_140922f20() != 0)
        {
            int nError = kRequest.FUN_140922f20();
            rResult = FUN_140560c00(L"winhttp err={0}", nError);
            return 0;
        }
        std::wstring strBody = kRequest.GetResponseContent();
        CString strResponse = FUN_14016a600(strBody.c_str(), 0);
        CAtlArray<CString> kLines;
        FUN_14015f050(strResponse, kLines, ";");
        int nLines = (int)FUN_1401662c0(kLines);
        for (int i = 0; i < nLines; ++i)
        {
            CAtlArray<CString> kParts;
            FUN_14015f050(FUN_140164930(kLines, i), kParts, "=");
            int nParts = (int)FUN_1401662c0(kParts);
            if (nParts != 2)
            {
                rResult = FUN_14136e2e0(L"invalid http response. ({0})", strBody.c_str());
                return 0;
            }
            if (FUN_140164930(kParts, 0) == "ver")
                m_88 = atoi(FUN_140164930(kParts, 1));
            else if (FUN_140164930(kParts, 0) == "purl")
                m_38 = FUN_140164930(kParts, 1);
            else if (FUN_140164930(kParts, 0) == "mweb")
                m_50 = FUN_140164930(kParts, 1);
            else if (FUN_140164930(kParts, 0) == "mapi")
                m_58 = FUN_140164930(kParts, 1);
        }
        FUN_141b77e50(m_50);
        FUN_141b77e90(m_58);
    }
    else
    {
        int nError = kRequest.FUN_140922f20();
        rResult = FUN_140560c00(L"winhttp err={0}", nError);
        return 0;
    }
    return 1;
}

// @0x14160e260
int CNXMan::FUN_14160e260()
{
    if (m_88 == 0)
        return 3;
    if (m_88 == 0x19f3e)
        return 1;
    if (FUN_1415c3780() == 0)
        return 3;
    else
    {
        Unk_NxPlatform* pPlatform = FUN_140d86260();
        pPlatform->vfunc_22(0x271, "Current Patch Version = %d", 0x19f3e);
        char kLogContext[32];
        FUN_1415ca240(kLogContext);
        int nResult = FUN_1415c3430(m_nGameCode, (LPCSTR)m_38, (LPCSTR)m_40, (LPCSTR)m_48, 1, 0, 0, kLogContext, 0, 0, 0);
        return 2;
    }
}

// @0x14160e3e0
void FUN_14160e3e0(void* pParam)
{
    (void)pParam;
    FUN_1416a0e70();
    PostQuitMessage(0);
}

// @0x14160e410
void CNXMan::FUN_14160e410()
{
    if (m_30 == 0)
    {
        m_90 = "";
        m_98 = "";
    }
    else
    {
        char szCert[1024];
        char szName[64];
        FUN_1415c4bb0(FUN_1415fa1b0(), szCert);
        FUN_1415c5010(FUN_1415fa1b0(), szName);
        m_90 = szCert;
        m_98 = szName;
    }
}

// @0x14160e500
CString CNXMan::FUN_14160e500()
{
    return m_90;
}

// @0x14160e550
CString CNXMan::FUN_14160e550()
{
    return m_98;
}

// @0x14160e5a0
CString CNXMan::FUN_14160e5a0()
{
    return m_c0;
}

// @0x14160e5f0
int CNXMan::FUN_14160e5f0()
{
    return FUN_14160eb40(this) == m_nGameCode;
}

// @0x14160e630
int CNXMan::FUN_14160e630()
{
    char szUgc[0x104];
    memset(szUgc, 0, sizeof(szUgc));
    CString strUgcDefault = FUN_14160eb70();
    GetPrivateProfileStringA("Stage", "ugc", (LPCSTR)strUgcDefault, szUgc, 0x104, ".\\anysetting.ini");
    m_60 = FUN_14016a730(szUgc, 0);
    int nGameCodeDefault = FUN_14160eb40(this);
    m_nGameCode = GetPrivateProfileIntA("Stage", "gc", nGameCodeDefault, ".\\anysetting.ini");
    m_str18.Format("http://gamelog.nexon.com/%d.html", m_nGameCode);
    if (DAT_143ae08f8 == 0)
    {
        char szIp[0x104];
        memset(szIp, 0, sizeof(szIp));
        CString strIpDefault = FUN_14160ebf0();
        GetPrivateProfileStringA("Stage", "cip", (LPCSTR)strIpDefault, szIp, 0x104, ".\\anysetting.ini");
        int nPortDefault = FUN_14160ecd0(this);
        int nPort = GetPrivateProfileIntA("Stage", "cport", nPortDefault, ".\\anysetting.ini");
        DAT_143ae0928 = szIp;
        DAT_143ae08f4 = nPort;
    }
    return 1;
}

// @0x14160e870
void CNXMan::FUN_14160e870()
{
    char szModule[0x104];
    char szPath[0x104];
    LPSTR pszFilePart;
    GetModuleFileNameA(0, szModule, 0x104);
    GetFullPathNameA(szModule, 0x104, szPath, &pszFilePart);
    if (pszFilePart != 0)
        *pszFilePart = 0;
    int nLen = (int)strlen(szPath);
    for (int i = nLen - 2; i > 0; --i)
    {
        if (szPath[i] == '\\' || szPath[i] == '/')
        {
            szPath[i + 1] = 0;
            break;
        }
    }
    m_40 = szPath;
}

// @0x14160e9b0
void CNXMan::FUN_14160e9b0()
{
    m_48 = DAT_143ae0908;
}

// @0x14160e9e0
CString CNXMan::FUN_14160e9e0(CString strHost)
{
    WSADATA kData;
    WSAStartup(0x202, &kData);
    hostent* pHost = gethostbyname(FUN_14016a5c0(strHost));
    if (pHost == 0)
        return CString("");
    CString strIp = FUN_140188f50(inet_ntoa(*(in_addr*)pHost->h_addr_list[0]));
    return strIp;
}

// @0x14160eb40
int FUN_14160eb40(void* p)
{
    (void)p;
    int nGameCode = 0;
    nGameCode = 0x1a002;
    return nGameCode;
}

// @0x14160eb70
CString CNXMan::FUN_14160eb70()
{
    CString strHost("");
    strHost = "ugc.game.maplestory2.nexon.com";
    return FUN_140540050("http://{0}/UGCWeb/pvex.aspx", strHost);
}

// @0x14160ebf0
CString CNXMan::FUN_14160ebf0()
{
    CString strHost("");
    strHost = FUN_14160e9e0("login.game.maplestory2.nexon.com");
    return strHost;
}

// @0x14160ecd0
int FUN_14160ecd0(void* p)
{
    (void)p;
    int nPort = 0;
    nPort = 0x4e21;
    return nPort;
}

// @0x14160ed00
CStringW FUN_14160ed00(int nErrorCode)
{
    Unk_PlatformErrorTable kErrors;
    CStringW strResult(L"");
    switch (nErrorCode)
    {
    case 0x4e22: strResult = kErrors.FUN_140c7a360(0x5); break;
    case 0x4e23: strResult = kErrors.FUN_140c7a360(0x6); break;
    case 0x4e27: strResult = kErrors.FUN_140c7a360(0x7); break;
    case 0x4e28: strResult = kErrors.FUN_140c7a360(0x8); break;
    case 0x4e2a: strResult = kErrors.FUN_140c7a360(0x9); break;
    case 0x4e2e: strResult = kErrors.FUN_140c7a360(0x17); break;
    case 0x4e39: strResult = kErrors.FUN_140c7a360(0xa); break;
    case 0x4e3a: strResult = kErrors.FUN_140c7a360(0xb); break;
    case 0x4e3c: strResult = kErrors.FUN_140c7a360(0xc); break;
    case 0x4e3f: strResult = kErrors.FUN_140c7a360(0xd); break;
    case 0x4e44: strResult = kErrors.FUN_140c7a360(0xe); break;
    case 0x4e4f: strResult = kErrors.FUN_140c7a360(0xf); break;
    case 0x4e54: strResult = kErrors.FUN_140c7a360(0x10); break;
    case 0x4e5a: strResult = kErrors.FUN_140c7a360(0x11); break;
    case 0x4e5d: strResult = kErrors.FUN_140c7a360(0x12); break;
    case 0x4e5f: strResult = kErrors.FUN_140c7a360(0x13); break;
    case 0x4e64: strResult = kErrors.FUN_140c7a360(0x14); break;
    case 0x4e65: strResult = kErrors.FUN_140c7a360(0x15); break;
    case 0x4e32: strResult = kErrors.FUN_140c7a360(0x16); break;
    }
    if (strResult.IsEmpty())
    {
        strResult = FUN_14160f680(kErrors.FUN_140c7a360(0x18), &nErrorCode);
    }
    return strResult;
}

// @0x14160f650
// fmt's MakeValue(const T&) for the custom (enum) error code: the value pointer and the FormatCustomArg thunk
fmt::internal::Value* FUN_14160f650(fmt::internal::Value* pThis, const int* p)
{
    pThis->custom.value = p;
    pThis->custom.format = (fmt::internal::FormatFunc)&FUN_14160f840;
    return pThis;
}

// @0x14160f680
// The FMT_VARIADIC wrapper: one custom argument, formatted into a CStringW by 0x1401d02a0.
CStringW FUN_14160f680(const wchar_t* psz, const int* pCode)
{
    fmt::internal::Value kValue;
    const fmt::internal::Value args[1] = {*FUN_14160f650(&kValue, pCode)};
    return FUN_1401d02a0(psz, fmt::ArgList(FUN_14160f870(pCode), args));
}

// @0x14160f720
// fmt::format_arg for the error code (the generic in fmt/format.h): enums take the int shortcut, the stream branch is
// dead code.
void FUN_14160f720(void* p1, void** pOut, void* p3)
{
    fmt::internal::Arg arg;
    fmt::internal::Value& arg_value = arg;
    if (std::is_enum<Unk_NxErrorCode>::value)
    {
        arg.int_value = *static_cast<int*>(p3);
        arg.type = fmt::internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<wchar_t> os;
        os << *static_cast<int*>(p3);
        std::basic_string<wchar_t> str = os.str();
        arg_value = fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(str);
        arg.type = fmt::internal::Arg::STRING;
    }
    *pOut = FUN_1402da110(p1, pOut, &arg);
}

// @0x14160f840
void FUN_14160f840(void* p1, void* p2, void* p3)
{
    FUN_14160f720(p1, (void**)p3, p2);
}

// @0x14160f870
fmt::ULongLong FUN_14160f870(const int* p)
{
    return FUN_14160f890(p);
}

// @0x14160f890
fmt::ULongLong FUN_14160f890(const int* p)
{
    (void)p;
    return 0xd;
}

// @0x14160f8d0
CNMEventHandler::CNMEventHandler()
{
}

// @0x14160f8f0
CPlatformEventHandler::CPlatformEventHandler()
{
}

// @0x14160f9c0
// The UCRT's header-inline memcpy_s (corecrt_memcpy_s.h, /Od): the validate macros' !!(expr) temps and real
// memset/memcpy calls.
#pragma function(memset, memcpy)
int FUN_14160f9c0(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount)
{
    if (nCount == 0) { return 0; }
    { int e = !!(pDst != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (pSrc == NULL || nDstSize < nCount)
    {
        memset(pDst, 0, nDstSize);
        { int e = !!(pSrc != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(nDstSize >= nCount); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(pDst, pSrc, nCount);
    return 0;
}
#pragma intrinsic(memset, memcpy)

// @0x14160d520
void CPlatformEventHandler::vfunc_2(void* pParam)
{
    (void)pParam;
}
