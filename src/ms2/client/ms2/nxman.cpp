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

#include <stdlib.h>
#include <errno.h>
#include <string.h>

#pragma comment(lib,"ws2_32.lib")

// ---- unrecovered callees (bound by VA) --------------------------------------------------------------------------------

void FUN_14160f720(void* p1, void** pOut, void* p3);
void FUN_14160f840(void* p1, void* p2, void* p3);
int  FUN_14160eb40(void*);
int  FUN_14160ecd0(void*);
int  FUN_14160f890(void*);
int  FUN_14160f870(void*);

void FUN_1415c3430(int nGameCode, const char* psz0, const char* psz1, const char* psz2);
int  FUN_1415c3780(void);
int  FUN_1415c4540(void* p, int a, int b, int c, int d);
int  FUN_1415c4810(void* p, int a);
void FUN_1415c4930(void* p, int a);
int  FUN_1415c4990(void* p, const char* psz);
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

void* FUN_140d86260(void);
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
CStringW FUN_140560c00(const wchar_t* pszFmt, const int* pArg);
CStringW FUN_14136e2e0(const wchar_t* pszFmt, const wchar_t* pszArg);
CString  FUN_140540050(const char* pszFmt, const CString& rArg);
void*    FUN_140163e50(void* pOut, void* p2, void* p3);
void     FUN_1401d02a0(void* pOut, const wchar_t* psz, void* p3);
void     FUN_1409208e0(void* pOut, const void* pSrc);
void     FUN_140920b30(void* p);
bool     FUN_140920cf0(void* p, const void* pVerb, int n);
int      FUN_140922f20(void* p);
void     FUN_140922860(void* p, std::wstring* pOut);
void     FUN_141b77e50(const CString& rString);
void     FUN_141b77e90(const CString& rString);
void*    FUN_1402da110(void* p1, void* p2, void* p3);
void     FUN_1416a0e70(void);

// The platform error table (0x58 bytes): index -> localized wide string. Its ctor/dtor live at 0x140c79890/0x140c79b50;
// the index lookup is the exe function at 0x140c7a360.
struct Unk_PlatformErrorTable
{
    char m_pad[0x58];
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
// MS2-FUNCTIONAL: stack temporaries/error table paths differ; equivalent control flow.
unsigned CNXMan::FUN_14160d820()
{
    Unk_PlatformErrorTable kErrors;
    unsigned uResult;
    if (FUN_14160e630() == 0)
    {
        DAT_143ac2fd0 = 0x44d;
        DAT_143ac2fe0 = kErrors.FUN_140c7a360(2);
        uResult = 0;
    }
    else
    {
        FUN_1415cb420(FUN_1415fa260());
        if (FUN_1415c4540(FUN_1415fa1b0(), m_0c, m_10, 0, 0) == 0)
        {
            DAT_143ac2fd0 = 0x44e;
            DAT_143ac2fe0 = kErrors.FUN_140c7a360(2);
            uResult = 0;
        }
        else
        {
            int nResult = FUN_1415c4810(FUN_1415fa1b0(), m_nGameCode);
            if (nResult == 0)
            {
                DAT_143ac2fd0 = 0x44f;
                DAT_143ac2fe0 = kErrors.FUN_140c7a360(2);
            }
            uResult = (unsigned)(nResult != 0);
            FUN_1415ca030("MapleStory2", (LPCSTR)m_str18, (LPCSTR)DAT_143ae0918);
        }
    }
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
// MS2-FUNCTIONAL: the platform connect call returns an error code; return/file-name temporaries differ.
int CNXMan::FUN_14160db80()
{
    CString strAddress = DAT_143ae0910;
    bool bConnected = false;
    if (strAddress.GetLength() > 0)
    {
        int nError = FUN_1415c4990(FUN_1415fa1b0(), (LPCSTR)strAddress);
        if (nError == 0)
        {
            m_30 = 1;
            FUN_14160e410();
            bConnected = true;
        }
        else
        {
            CStringW strText = FUN_14160ed00(nError);
            m_c0 = FUN_14016a600((LPCWSTR)strText, 0);
            SendMessageA(m_hWnd, 0x180, 0, (LPARAM)(LPCSTR)m_c0);
        }
    }
    return bConnected ? 1 : 0;
}

// @0x14160dd20
void CNXMan::FUN_14160dd20()
{
    if (m_30 != 0)
        FUN_1415c4a30(FUN_1415fa1b0());
}

// @0x14160dd50
// MS2-FUNCTIONAL: winhttp request object is opaque (0x210 bytes); response parsing follows the recovered flow.
int CNXMan::FUN_14160dd50(CStringW& rResult)
{
    char kRequest[0x210];
    FUN_1409208e0(kRequest, &m_60);
    std::wstring strVerb(L"GET");
    if (!FUN_140920cf0(kRequest, &strVerb, 0))
    {
        int nError = FUN_140922f20(kRequest);
        rResult = FUN_140560c00(L"winhttp err={0}", &nError);
        FUN_140920b30(kRequest);
        return 0;
    }
    int nError = FUN_140922f20(kRequest);
    if (nError != 0)
    {
        rResult = FUN_140560c00(L"winhttp err={0}", &nError);
        FUN_140920b30(kRequest);
        return 0;
    }
    std::wstring strBody;
    FUN_140922860(kRequest, &strBody);
    CString strResponse = FUN_14016a600(strBody.c_str(), 0);
    CAtlArray<CString> kLines;
    FUN_14015f050(strResponse, kLines, ";");
    int nLines = (int)FUN_1401662c0(kLines);
    for (int i = 0; i < nLines; ++i)
    {
        CAtlArray<CString> kParts;
        FUN_14015f050(FUN_140164930(kLines, i), kParts, "=");
        if ((int)FUN_1401662c0(kParts) != 2)
        {
            rResult = FUN_14136e2e0(L"invalid http response. ({0})", strBody.c_str());
            FUN_140920b30(kRequest);
            return 0;
        }
        const CString& kName = FUN_140164930(kParts, 0);
        const CString& kValue = FUN_140164930(kParts, 1);
        if (kName == "ver")
            m_88 = atoi((LPCSTR)kValue);
        else if (kName == "purl")
            m_38 = kValue;
        else if (kName == "mweb")
            m_50 = kValue;
        else if (kName == "mapi")
            m_58 = kValue;
    }
    FUN_141b77e50(m_50);
    FUN_141b77e90(m_58);
    FUN_140920b30(kRequest);
    return 1;
}

// @0x14160e260
// MS2-FUNCTIONAL: the platform logger call carries extra stack arguments (file/line) that are not recovered.
int CNXMan::FUN_14160e260()
{
    if (m_88 == 0)
        return 3;
    if (m_88 == 0x19f3e)
        return 1;
    if (FUN_1415c3780() == 0)
        return 3;
    void* pPlatform = FUN_140d86260();
    typedef void (__fastcall* FnLog)(void*, int, const char*, int);
    (*(FnLog)((*(void***)pPlatform)[0xb0 / 8]))(pPlatform, 0x271, "Current Patch Version = %d", 0x19f3e);
    char kLogContext[32];
    FUN_1415ca240(kLogContext);
    FUN_1415c3430(m_nGameCode, (LPCSTR)m_38, (LPCSTR)m_40, (LPCSTR)m_48);
    return 2;
}

// @0x14160e3e0
void FUN_14160e3e0()
{
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
    CStringW strUgc = FUN_14016a730(szUgc, 0);
    m_60 = (LPCWSTR)strUgc;
    m_nGameCode = GetPrivateProfileIntA("Stage", "gc", FUN_14160eb40(this), ".\\anysetting.ini");
    m_str18.Format("http://gamelog.nexon.com/%d.html", m_nGameCode);
    if (DAT_143ae08f8 == 0)
    {
        char szIp[0x104];
        memset(szIp, 0, sizeof(szIp));
        CString strIpDefault = FUN_14160ebf0();
        GetPrivateProfileStringA("Stage", "cip", (LPCSTR)strIpDefault, szIp, 0x104, ".\\anysetting.ini");
        DAT_143ae08f4 = GetPrivateProfileIntA("Stage", "cport", FUN_14160ecd0(this), ".\\anysetting.ini");
        DAT_143ae0928 = szIp;
    }
    return 1;
}

// @0x14160e870
void CNXMan::FUN_14160e870()
{
    char szModule[0x104];
    char szPath[0x104];
    LPSTR pszFilePart = 0;
    GetModuleFileNameA(0, szModule, 0x104);
    GetFullPathNameA(szModule, 0x104, szPath, &pszFilePart);
    if (pszFilePart != 0)
        *pszFilePart = 0;
    for (int i = (int)strlen(szPath) - 2; i >= 1; --i)
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
CString CNXMan::FUN_14160e9e0(CString& rHost)
{
    WSADATA kData;
    if (WSAStartup(0x202, &kData) != 0)
        return CString("");
    hostent* pHost = gethostbyname((LPCSTR)rHost);
    if (pHost == 0)
        return CString("");
    return CString(inet_ntoa(*(in_addr*)pHost->h_addr_list[0]));
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
    strHost = "login.game.maplestory2.nexon.com";
    return FUN_14160e9e0(strHost);
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
// MS2-FUNCTIONAL: long error-code -> localized-string switch; the table lookup (0x140c7a360) is opaque.
CStringW FUN_14160ed00(int nErrorCode)
{
    Unk_PlatformErrorTable kErrors;
    CStringW strResult(L"");
    switch (nErrorCode - 0x4e22)
    {
    case 0:  strResult = kErrors.FUN_140c7a360(5);    break;
    case 1:  strResult = kErrors.FUN_140c7a360(6);    break;
    case 5:  strResult = kErrors.FUN_140c7a360(7);    break;
    case 6:  strResult = kErrors.FUN_140c7a360(8);    break;
    case 8:  strResult = kErrors.FUN_140c7a360(9);    break;
    case 0xc: strResult = kErrors.FUN_140c7a360(0x17); break;
    case 0x10: strResult = kErrors.FUN_140c7a360(0x16); break;
    case 0x17: strResult = kErrors.FUN_140c7a360(10); break;
    case 0x18: strResult = kErrors.FUN_140c7a360(0xb); break;
    case 0x1a: strResult = kErrors.FUN_140c7a360(0xc); break;
    case 0x1d: strResult = kErrors.FUN_140c7a360(0xd); break;
    case 0x22: strResult = kErrors.FUN_140c7a360(0xe); break;
    case 0x2d: strResult = kErrors.FUN_140c7a360(0xf); break;
    case 0x32: strResult = kErrors.FUN_140c7a360(0x10); break;
    case 0x38: strResult = kErrors.FUN_140c7a360(0x11); break;
    case 0x3b: strResult = kErrors.FUN_140c7a360(0x12); break;
    case 0x3d: strResult = kErrors.FUN_140c7a360(0x13); break;
    case 0x42: strResult = kErrors.FUN_140c7a360(0x14); break;
    case 0x43: strResult = kErrors.FUN_140c7a360(0x15); break;
    }
    if (strResult.IsEmpty())
    {
        CStringW strDefault = kErrors.FUN_140c7a360(0x18);
        strResult = FUN_14160f680((LPCWSTR)strDefault, &nErrorCode);
    }
    return strResult;
}

// @0x14160f650
void** FUN_14160f650(void** pOut, void* p)
{
    pOut[0] = p;
    pOut[1] = (void*)&FUN_14160f840;
    return pOut;
}

// @0x14160f680
CStringW FUN_14160f680(const wchar_t* psz, const int* pCode)
{
    void* kDelegate[2];
    char kArgList[32];
    FUN_14160f650(kDelegate, (void*)pCode);
    int nArgs = FUN_14160f870((void*)pCode);
    FUN_140163e50(kArgList, (void*)(__int64)nArgs, kDelegate);
    CStringW strResult;
    FUN_1401d02a0(&strResult, psz, kArgList);
    return strResult;
}

// @0x14160f720
void FUN_14160f720(void* p1, void** pOut, void* p3)
{
    int local[2];
    local[0] = *(int*)p3;
    local[1] = 1;
    void* p = FUN_1402da110(p1, pOut, local);
    *pOut = p;
}

// @0x14160f840
void FUN_14160f840(void* p1, void* p2, void* p3)
{
    FUN_14160f720(p1, (void**)p3, p2);
}

// @0x14160f870
int FUN_14160f870(void* p)
{
    return FUN_14160f890(p);
}

// @0x14160f890
int FUN_14160f890(void* p)
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
int FUN_14160f9c0(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount)
{
    if (nCount == 0)
        return 0;
    if (pDst == 0)
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
        return 0x16;
    }
    if (pSrc == 0 || nDstSize < nCount)
    {
        memset(pDst, 0, nDstSize);
        if (pSrc == 0)
        {
            *_errno() = 0x16;
            _invalid_parameter_noinfo();
            return 0x16;
        }
        if (nDstSize < nCount)
        {
            *_errno() = 0x22;
            _invalid_parameter_noinfo();
            return 0x22;
        }
        return 0x16;
    }
    memcpy(pDst, pSrc, nCount);
    return 0;
}

// @0x14160d520
void CPlatformEventHandler::vfunc_2(void* pParam)
{
    (void)pParam;
}
