// cwinhttpclient.h - CWinHttpClient (RTTI name; TPtredDummy<CWinHttpClient> 0x228 bytes, deleting dtor 0x140518120).
// Recovered with unit_140920cf0 (src/ms2/unnamed/unit_140920cf0.cpp). The class is Nexon's edit of Cheng Shi's open
// source "WinHttpClient" (CodeProject, 2008-2010; WinHttpClient.h + RegExp.h + StringProcess.h, all moved into one .cpp):
// no progress callback, an extra default ctor and url setter, PUT/DELETE verbs, m_dwLastError moved to the end.
// Method and member names follow that source. The seven FUN_<va> names are kept because done units call them by that
// name (real names in the comments).
#pragma once
#include <windows.h>
#include <winhttp.h>
#include <string>
#include <vector>
#include "ms2/ms2layout.h"

class CWinHttpClient
{
public:
    CWinHttpClient();                                       // 0x140920690
    CWinHttpClient(const std::wstring& strUrl);             // 0x1409208e0
    ~CWinHttpClient();                                      // 0x140920b30
    void FUN_140920cc0(const std::wstring& strUrl);         // SetRequestUrl (m_requestURL = url)
    bool FUN_140920cf0(const std::wstring& strVerb, bool bAsync);   // SendHttpRequest(httpVerb, disableAutoRedirect)
    std::wstring GetResponseHeader();
    std::wstring FUN_140922860();                           // GetResponseContent
    std::wstring GetResponseCharset();
    std::wstring GetResponseStatusCode();
    std::wstring GetResponseLocation();
    std::wstring GetRequestHost();
    const BYTE* GetRawResponseContent();
    unsigned int GetRawResponseContentLength();
    unsigned int GetRawResponseReceivedContentLength();
    std::wstring GetResponseCookies();
    bool SaveResponseToFile(const std::wstring& filePath);
    bool SetAdditionalRequestCookies(const std::wstring& cookies);
    bool FUN_140922b90(const unsigned char* pBody, unsigned nSize);    // SetAdditionalDataToSend
    bool UpdateUrl(const std::wstring& url);
    bool ResetAdditionalDataToSend();
    bool FUN_140922d20(const std::wstring& strHeaders);     // SetAdditionalRequestHeaders
    bool SetProxy(const std::wstring& proxy);
    bool SetUserAgent(const std::wstring& userAgent);
    bool SetForceCharset(const std::wstring& charset);
    bool SetProxyUsername(const std::wstring& username);
    bool SetProxyPassword(const std::wstring& password);
    bool SetTimeouts(unsigned int resolveTimeout = 0, unsigned int connectTimeout = 60000,
                     unsigned int sendTimeout = 30000, unsigned int receiveTimeout = 30000);
    int FUN_140922f20();                                    // GetLastError (0: none)

private:
    CWinHttpClient(const CWinHttpClient& other);
    CWinHttpClient& operator=(const CWinHttpClient& other);

    HINTERNET m_sessionHandle;                  // +0x000
    bool m_requireValidSsl;                     // +0x008
    std::wstring m_requestURL;                  // +0x010
    std::wstring m_requestHost;                 // +0x030
    std::wstring m_responseHeader;              // +0x050
    std::wstring m_responseContent;             // +0x070
    std::wstring m_responseCharset;             // +0x090
    BYTE* m_pResponse;                          // +0x0b0
    unsigned int m_responseByteCountReceived;   // +0x0b8
    unsigned int m_responseByteCount;           // +0x0bc
    std::wstring m_responseCookies;             // +0x0c0
    BYTE* m_pDataToSend;                        // +0x0e0
    unsigned int m_dataToSendSize;              // +0x0e8
    std::wstring m_additionalRequestCookies;    // +0x0f0
    std::wstring m_additionalRequestHeaders;    // +0x110
    std::wstring m_proxy;                       // +0x130
    std::wstring m_statusCode;                  // +0x150
    std::wstring m_userAgent;                   // +0x170
    bool m_bForceCharset;                       // +0x190
    std::wstring m_proxyUsername;               // +0x198
    std::wstring m_proxyPassword;               // +0x1b8
    std::wstring m_location;                    // +0x1d8
    unsigned int m_resolveTimeout;              // +0x1f8
    unsigned int m_connectTimeout;              // +0x1fc
    unsigned int m_sendTimeout;                 // +0x200
    unsigned int m_receiveTimeout;              // +0x204
    DWORD m_dwLastError;                        // +0x208
};
MS2_CHECK_SIZE(CWinHttpClient, 0x210);

// RegExp.h / StringProcess.h free functions (defined in the same TU, after the class).
bool ParseRegExp(const std::wstring& regExp, bool caseSensitive, int groupCount, const std::wstring& source,
                 std::vector<std::wstring>& result, bool allowDuplicate = false);
std::wstring Trim(const std::wstring& source, const std::wstring& targets);
bool PrepareString(wchar_t* dest, size_t* size, const std::wstring& src);
std::wstring ReplaceString(const std::wstring& srcStr, const std::wstring& oldStr, const std::wstring& newStr);
int StringToInteger(const std::wstring& number);
std::wstring LowerString(const std::wstring& text);
std::wstring UpperString(const std::wstring& text);
std::wstring GetAnchorText(const std::wstring& anchor);
std::wstring GetAnchorLink(const std::wstring& anchor);
bool SeparateString(const std::wstring& content, const std::wstring& delimiter, std::vector<std::wstring>& result);
std::wstring URLEncoding(const std::wstring& keyword, bool convertToUTF8 = true);
unsigned int GetSeparateKeywordMatchGrade(const std::wstring& source, const std::wstring& keyword);
unsigned int GetKeywordMatchGrade(const std::wstring& source, const std::wstring& keyword);
std::wstring MD5(const std::wstring& text);
std::wstring FilterFileName(const std::wstring& name);
std::wstring GetMagic(unsigned int length);
std::wstring GetHost(const std::wstring& url);
std::wstring GetValidFileName(const std::wstring& fileName);
