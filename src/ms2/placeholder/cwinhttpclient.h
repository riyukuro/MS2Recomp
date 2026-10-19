// cwinhttpclient.h - PLACEHOLDER for CWinHttpClient (RTTI name; TPtredDummy<CWinHttpClient> 0x228 bytes, deleting dtor
// 0x140518120). NOT an original header: only the 0x210-byte extent and the methods commonfiles\imagehttpclient.cpp calls.
// Member names are inferred from the ctor 0x140920690; the HTTP implementation itself is not recovered here.
#pragma once
#include <string>
#include "ms2/ms2layout.h"

class CWinHttpClient
{
public:
    CWinHttpClient();                                       // 0x140920690
    ~CWinHttpClient();                                      // 0x140920b30
    void FUN_140920cc0(const std::wstring& strUrl);         // m_070 = the request URL
    bool FUN_140920cf0(const std::wstring& strVerb, bool bAsync);   // sends the request ("GET"/"PUT"/"POST")
    void FUN_140922b90(const unsigned char* pBody, unsigned nSize);
    void FUN_140922d20(const std::wstring& strHeaders);
    int FUN_140922f20();                                    // last error (0: none)
    std::wstring FUN_140922860();                           // copy of the response text (+0x70)

private:
    void* m_session;                    // +0x000
    bool m_secure;                      // +0x008
    std::wstring m_010;
    std::wstring m_030;
    std::wstring m_050;
    std::wstring m_070;
    std::wstring m_090;
    void* m_payload;                    // +0x0b0
    unsigned m_payloadSize;
    unsigned m_0bc;
    std::wstring m_0c0;
    void* m_0e0;
    unsigned m_0e8;
    std::wstring m_0f0;
    std::wstring m_110;
    std::wstring m_130;
    std::wstring m_150;
    std::wstring m_170;
    bool m_190;
    std::wstring m_198;
    std::wstring m_1b8;
    std::wstring m_1d8;
    unsigned m_1f8;
    unsigned m_resolveTimeout;
    unsigned m_connectTimeout;
    unsigned m_sendTimeout;
    unsigned m_208;
};
MS2_CHECK_SIZE(CWinHttpClient, 0x210);
