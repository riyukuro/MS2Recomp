// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CWinHttpClient: Nexon's copy of Cheng Shi's open source
// WinHttp wrapper "WinHttpClient" (CodeProject, 2008-2010) with its RegExp.h (ParseRegExp over ATL Server's CAtlRegExp)
// and StringProcess.h helpers, all as plain functions of one TU, plus the CAtlRegExp<CAtlRECharTraitsW> / std::vector
// instantiations they pull in. The original file name is unknown (no __FILE__): unit name kept.
// Names follow the published source; changes against it (from the exe): no progress callback, default ctor + url
// setter, PUT/DELETE verbs, heap proxy strings, no GetDateString/GetTimeString, m_dwLastError last.
// The TU starts at 0x140920690 (the weddingrewarditem TU ends with its memmove_s at 0x140920570).
// MS2-UNIT: unit_140920cf0
// MS2-RANGE: 0x140920690-0x14092c230 .text$mn
// MS2-PIN: ?Match@?$CAtlRegExp@VCAtlRECharTraitsW@ATL@@@ATL@@QEAAHPEB_WPEAV?$CAtlREMatchContext@VCAtlRECharTraitsW@ATL@@@2@PEAPEB_W@Z 0x140927f00 ; called by ParseRegExp 0x140922f40
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <windows.h>
#include <winhttp.h>
#include <wincrypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <comutil.h>
#pragma warning(push)
#pragma warning(disable: 6385 6011 4127)
#include "ms2/atlserver/atlrx.h"
#pragma warning(pop)
#include "ms2/placeholder/cwinhttpclient.h"
#include "ms2/placeholder/specialnpcinfo.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "advapi32.lib")

// The exe calls the imported wcslen and wcscmp (`call [__imp_wcslen]`); the static-CRT headers declare it without dllimport, so the
// IAT slot is reached through its own symbol (same as fmt/format.h).
extern "C" size_t (__cdecl* __imp_wcslen)(const wchar_t*);
extern "C" int (__cdecl* __imp_wcscmp)(const wchar_t*, const wchar_t*);

using namespace std;

static const unsigned int INT_RETRYTIMES = 3;
static wchar_t *SZ_AGENT = L"WinHttpClient";
static const int INT_BUFFERSIZE = 10240;    // Initial 10 KB temporary buffer, double if it is not enough.

#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p); (p) = NULL; } }

// @0x140920690
CWinHttpClient::CWinHttpClient()
    : m_sessionHandle(NULL),
      m_requireValidSsl(false),
      m_requestURL(L""),
      m_requestHost(L""),
      m_responseHeader(L""),
      m_responseContent(L""),
      m_responseCharset(L""),
      m_pResponse(NULL),
      m_responseByteCountReceived(0),
      m_responseByteCount(0),
      m_responseCookies(L""),
      m_pDataToSend(NULL),
      m_dataToSendSize(0),
      m_additionalRequestCookies(L""),
      m_proxy(L""),
      m_statusCode(L""),
      m_userAgent(SZ_AGENT),
      m_bForceCharset(false),
      m_proxyUsername(L""),
      m_proxyPassword(L""),
      m_location(L""),
      m_resolveTimeout(0),
      m_connectTimeout(60000),
      m_sendTimeout(30000),
      m_receiveTimeout(30000),
      m_dwLastError(0)
{
}

// @0x1409208e0
CWinHttpClient::CWinHttpClient(const wstring &url)
    : m_sessionHandle(NULL),
      m_requireValidSsl(false),
      m_requestURL(url),
      m_requestHost(L""),
      m_responseHeader(L""),
      m_responseContent(L""),
      m_responseCharset(L""),
      m_pResponse(NULL),
      m_responseByteCountReceived(0),
      m_responseByteCount(0),
      m_responseCookies(L""),
      m_pDataToSend(NULL),
      m_dataToSendSize(0),
      m_additionalRequestCookies(L""),
      m_proxy(L""),
      m_statusCode(L""),
      m_userAgent(SZ_AGENT),
      m_bForceCharset(false),
      m_proxyUsername(L""),
      m_proxyPassword(L""),
      m_location(L""),
      m_resolveTimeout(0),
      m_connectTimeout(60000),
      m_sendTimeout(30000),
      m_receiveTimeout(30000),
      m_dwLastError(0)
{
}

// @0x140920b30
CWinHttpClient::~CWinHttpClient()
{
    if (m_pResponse != NULL)
    {
        delete[] m_pResponse;
    }
    if (m_pDataToSend != NULL)
    {
        delete[] m_pDataToSend;
    }

    if (m_sessionHandle != NULL)
    {
        ::WinHttpCloseHandle(m_sessionHandle);
    }
}

// @0x140920cc0
void CWinHttpClient::FUN_140920cc0(const wstring &url)
{
    m_requestURL = url;
}

// @0x140920cf0
bool CWinHttpClient::FUN_140920cf0(const wstring &httpVerb, bool disableAutoRedirect)
{
    if (m_requestURL.size() <= 0)
    {
        m_dwLastError = ERROR_PATH_NOT_FOUND;
        return false;
    }
    // Make verb uppercase.
    wstring verb = httpVerb;
    if (_wcsicmp(verb.c_str(), L"GET") == 0)
    {
        verb = L"GET";
    }
    else if (_wcsicmp(verb.c_str(), L"POST") == 0)
    {
        verb = L"POST";
    }
    else if (_wcsicmp(verb.c_str(), L"PUT") == 0)
    {
        verb = L"PUT";
    }
    else if (_wcsicmp(verb.c_str(), L"DELETE") == 0)
    {
        verb = L"DELETE";
    }
    else
    {
        m_dwLastError = ERROR_INVALID_PARAMETER;
        return false;
    }
    bool bRetVal = true;

    if (m_sessionHandle == NULL)
    {
        m_sessionHandle = ::WinHttpOpen(m_userAgent.c_str(),
                                        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                        WINHTTP_NO_PROXY_NAME,
                                        WINHTTP_NO_PROXY_BYPASS,
                                        0);
        if (m_sessionHandle == NULL)
        {
            m_dwLastError = ::GetLastError();
            return false;
        }
    }

    ::WinHttpSetTimeouts(m_sessionHandle,
                         m_resolveTimeout,
                         m_connectTimeout,
                         m_sendTimeout,
                         m_receiveTimeout);

    wchar_t szHostName[MAX_PATH] = L"";
    wchar_t szURLPath[MAX_PATH * 5] = L"";
    URL_COMPONENTS urlComp;
    memset(&urlComp, 0, sizeof(urlComp));
    urlComp.dwStructSize = sizeof(urlComp);
    urlComp.lpszHostName = szHostName;
    urlComp.dwHostNameLength = MAX_PATH;
    urlComp.lpszUrlPath = szURLPath;
    urlComp.dwUrlPathLength = MAX_PATH * 5;
    urlComp.dwSchemeLength = 1; // None zero

    if (::WinHttpCrackUrl(m_requestURL.c_str(), m_requestURL.size(), 0, &urlComp))
    {
        m_requestHost = szHostName;
        HINTERNET hConnect = NULL;
        hConnect = ::WinHttpConnect(m_sessionHandle, szHostName, urlComp.nPort, 0);
        if (hConnect != NULL)
        {
            DWORD dwOpenRequestFlag = (urlComp.nScheme == INTERNET_SCHEME_HTTPS) ? WINHTTP_FLAG_SECURE : 0;
            HINTERNET hRequest = NULL;
            hRequest = ::WinHttpOpenRequest(hConnect,
                                            verb.c_str(),
                                            urlComp.lpszUrlPath,
                                            NULL,
                                            WINHTTP_NO_REFERER,
                                            WINHTTP_DEFAULT_ACCEPT_TYPES,
                                            dwOpenRequestFlag);
            if (hRequest != NULL)
            {
                // If HTTPS, then client is very susceptable to invalid certificates
                // Easiest to accept anything for now
                if (!m_requireValidSsl && urlComp.nScheme == INTERNET_SCHEME_HTTPS)
                {
                    DWORD options = SECURITY_FLAG_IGNORE_CERT_CN_INVALID
                                    | SECURITY_FLAG_IGNORE_CERT_DATE_INVALID
                                    | SECURITY_FLAG_IGNORE_UNKNOWN_CA;
                    ::WinHttpSetOption(hRequest,
                                       WINHTTP_OPTION_SECURITY_FLAGS,
                                       (LPVOID)&options,
                                       sizeof(DWORD));
                }

                bool bGetReponseSucceed = false;
                unsigned int iRetryTimes = 0;

                // Retry for several times if fails.
                while (!bGetReponseSucceed && iRetryTimes++ < INT_RETRYTIMES)
                {
                    if (m_additionalRequestHeaders.size() > 0)
                    {
                        if (!::WinHttpAddRequestHeaders(hRequest, m_additionalRequestHeaders.c_str(), m_additionalRequestHeaders.size(), WINHTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON))
                        {
                            m_dwLastError = ::GetLastError();
                        }
                    }
                    if (m_additionalRequestCookies.size() > 0)
                    {
                        wstring cookies = L"Cookie: ";
                        cookies += m_additionalRequestCookies;
                        if (!::WinHttpAddRequestHeaders(hRequest, cookies.c_str(), cookies.size(), WINHTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON))
                        {
                            m_dwLastError = ::GetLastError();
                        }
                    }
                    if (m_proxy.size() > 0)
                    {
                        WINHTTP_PROXY_INFO proxyInfo;
                        memset(&proxyInfo, 0, sizeof(proxyInfo));
                        proxyInfo.dwAccessType = WINHTTP_ACCESS_TYPE_NAMED_PROXY;
                        int nProxyLength = (int)__imp_wcslen(m_proxy.c_str()) + 1;
                        proxyInfo.lpszProxy = new wchar_t[nProxyLength];
                        memset(proxyInfo.lpszProxy, 0, nProxyLength);
                        wcscpy_s(proxyInfo.lpszProxy, nProxyLength, m_proxy.c_str());

                        if (!::WinHttpSetOption(hRequest, WINHTTP_OPTION_PROXY, &proxyInfo, sizeof(proxyInfo)))
                        {
                            m_dwLastError = ::GetLastError();
                        }

                        if (m_proxyUsername.size() > 0)
                        {
                            if (!::WinHttpSetOption(hRequest, WINHTTP_OPTION_PROXY_USERNAME, (LPVOID)m_proxyUsername.c_str(), (DWORD)m_proxyUsername.size() * sizeof(wchar_t)))
                            {
                                m_dwLastError = ::GetLastError();
                            }
                            if (m_proxyPassword.size() > 0)
                            {
                                if (!::WinHttpSetOption(hRequest, WINHTTP_OPTION_PROXY_PASSWORD, (LPVOID)m_proxyPassword.c_str(), (DWORD)m_proxyPassword.size() * sizeof(wchar_t)))
                                {
                                    m_dwLastError = ::GetLastError();
                                }
                            }
                        }
                        SAFE_DELETE_ARRAY(proxyInfo.lpszProxy);
                    }

                    if (disableAutoRedirect)
                    {
                        DWORD dwDisableFeature = WINHTTP_DISABLE_REDIRECTS;
                        if (!::WinHttpSetOption(hRequest, WINHTTP_OPTION_DISABLE_FEATURE, &dwDisableFeature, sizeof(dwDisableFeature)))
                        {
                            m_dwLastError = ::GetLastError();
                        }
                    }
                    bool bSendRequestSucceed = false;
                    if (::WinHttpSendRequest(hRequest,
                                             WINHTTP_NO_ADDITIONAL_HEADERS,
                                             0,
                                             WINHTTP_NO_REQUEST_DATA,
                                             0,
                                             0,
                                             NULL))
                    {
                        bSendRequestSucceed = true;
                    }
                    else
                    {
                        // Query the proxy information from IE setting and set the proxy if any.
                        WINHTTP_CURRENT_USER_IE_PROXY_CONFIG proxyConfig;
                        memset(&proxyConfig, 0, sizeof(proxyConfig));
                        if (::WinHttpGetIEProxyConfigForCurrentUser(&proxyConfig))
                        {
                            if (proxyConfig.lpszAutoConfigUrl != NULL)
                            {
                                WINHTTP_AUTOPROXY_OPTIONS autoProxyOptions;
                                memset(&autoProxyOptions, 0, sizeof(autoProxyOptions));
                                autoProxyOptions.dwFlags = WINHTTP_AUTOPROXY_AUTO_DETECT | WINHTTP_AUTOPROXY_CONFIG_URL;
                                autoProxyOptions.dwAutoDetectFlags = WINHTTP_AUTO_DETECT_TYPE_DHCP;
                                autoProxyOptions.lpszAutoConfigUrl = proxyConfig.lpszAutoConfigUrl;
                                autoProxyOptions.fAutoLogonIfChallenged = TRUE;
                                autoProxyOptions.dwReserved = 0;
                                autoProxyOptions.lpvReserved = NULL;

                                WINHTTP_PROXY_INFO proxyInfo;
                                memset(&proxyInfo, 0, sizeof(proxyInfo));

                                if (::WinHttpGetProxyForUrl(m_sessionHandle, m_requestURL.c_str(), &autoProxyOptions, &proxyInfo))
                                {
                                    if (::WinHttpSetOption(hRequest, WINHTTP_OPTION_PROXY, &proxyInfo, sizeof(proxyInfo)))
                                    {
                                        if (::WinHttpSendRequest(hRequest,
                                                                 WINHTTP_NO_ADDITIONAL_HEADERS,
                                                                 0,
                                                                 WINHTTP_NO_REQUEST_DATA,
                                                                 0,
                                                                 0,
                                                                 NULL))
                                        {
                                            bSendRequestSucceed = true;
                                        }
                                    }
                                    if (proxyInfo.lpszProxy != NULL)
                                    {
                                        ::GlobalFree(proxyInfo.lpszProxy);
                                    }
                                    if (proxyInfo.lpszProxyBypass != NULL)
                                    {
                                        ::GlobalFree(proxyInfo.lpszProxyBypass);
                                    }
                                }
                                else
                                {
                                    m_dwLastError = ::GetLastError();
                                }
                            }
                            else if (proxyConfig.lpszProxy != NULL)
                            {
                                WINHTTP_PROXY_INFO proxyInfo;
                                memset(&proxyInfo, 0, sizeof(proxyInfo));
                                proxyInfo.dwAccessType = WINHTTP_ACCESS_TYPE_NAMED_PROXY;
                                int nProxyLength = (int)__imp_wcslen(proxyConfig.lpszProxy) + 1;
                                proxyInfo.lpszProxy = new wchar_t[nProxyLength];
                                memset(proxyInfo.lpszProxy, 0, nProxyLength);
                                wcscpy_s(proxyInfo.lpszProxy, nProxyLength, proxyConfig.lpszProxy);

                                if (proxyConfig.lpszProxyBypass != NULL)
                                {
                                    int nBypassLength = (int)__imp_wcslen(proxyConfig.lpszProxyBypass) + 1;
                                    proxyInfo.lpszProxyBypass = new wchar_t[nBypassLength];
                                    memset(proxyInfo.lpszProxyBypass, 0, nBypassLength);
                                    wcscpy_s(proxyInfo.lpszProxyBypass, nBypassLength, proxyConfig.lpszProxyBypass);
                                }

                                if (!::WinHttpSetOption(hRequest, WINHTTP_OPTION_PROXY, &proxyInfo, sizeof(proxyInfo)))
                                {
                                    m_dwLastError = ::GetLastError();
                                }
                                SAFE_DELETE_ARRAY(proxyInfo.lpszProxy);
                                SAFE_DELETE_ARRAY(proxyInfo.lpszProxyBypass);
                            }

                            if (proxyConfig.lpszAutoConfigUrl != NULL)
                            {
                                ::GlobalFree(proxyConfig.lpszAutoConfigUrl);
                            }
                            if (proxyConfig.lpszProxy != NULL)
                            {
                                ::GlobalFree(proxyConfig.lpszProxy);
                            }
                            if (proxyConfig.lpszProxyBypass != NULL)
                            {
                                ::GlobalFree(proxyConfig.lpszProxyBypass);
                            }
                        }
                        else
                        {
                            m_dwLastError = ::GetLastError();
                        }
                    }
                    if (bSendRequestSucceed)
                    {
                        if (m_pDataToSend != NULL)
                        {
                            DWORD dwWritten = 0;
                            if (!::WinHttpWriteData(hRequest,
                                                    m_pDataToSend,
                                                    m_dataToSendSize,
                                                    &dwWritten))
                            {
                                m_dwLastError = ::GetLastError();
                            }
                        }
                        if (::WinHttpReceiveResponse(hRequest, NULL))
                        {
                            DWORD dwSize = 0;
                            BOOL bResult = FALSE;
                            bResult = ::WinHttpQueryHeaders(hRequest,
                                                            WINHTTP_QUERY_RAW_HEADERS_CRLF,
                                                            WINHTTP_HEADER_NAME_BY_INDEX,
                                                            NULL,
                                                            &dwSize,
                                                            WINHTTP_NO_HEADER_INDEX);
                            if (bResult || (!bResult && (::GetLastError() == ERROR_INSUFFICIENT_BUFFER)))
                            {
                                wchar_t *szHeader = new wchar_t[dwSize];
                                if (szHeader != NULL)
                                {
                                    memset(szHeader, 0, dwSize* sizeof(wchar_t));
                                    if (::WinHttpQueryHeaders(hRequest,
                                                              WINHTTP_QUERY_RAW_HEADERS_CRLF,
                                                              WINHTTP_HEADER_NAME_BY_INDEX,
                                                              szHeader,
                                                              &dwSize,
                                                              WINHTTP_NO_HEADER_INDEX))
                                    {
                                        m_responseHeader.assign(szHeader);
                                        vector<wstring> result;
                                        wstring regExp = L"";
                                        if (!m_bForceCharset)
                                        {
                                            regExp = L"charset={[A-Za-z0-9\\-_]+}";
                                            if (ParseRegExp(regExp, false, 1, m_responseHeader, result) && result.size() > 0)
                                            {
                                                m_responseCharset = result[0];
                                            }
                                        }
                                        regExp = L"Content-Length: {[0-9]+}";
                                        if (ParseRegExp(regExp, false, 1, m_responseHeader, result) && result.size() > 0)
                                        {
                                            m_responseByteCount = (unsigned int)_wtoi(result[0].c_str());
                                        }
                                        regExp = L"Location: {[0-9]+}";
                                        if (ParseRegExp(regExp, false, 1, m_responseHeader, result) && result.size() > 0)
                                        {
                                            m_location = result[0];
                                        }
                                        regExp = L"Set-Cookie:\\b*{.+?}\\n";
                                        if (ParseRegExp(regExp, false, 1, m_responseHeader, result) && result.size() > 0)
                                        {
                                            for (vector<wstring>::size_type i = 0; i < result.size(); i++)
                                            {
                                                m_responseCookies += result[i];
                                                if (i != result.size() - 1)
                                                {
                                                    m_responseCookies += L"; ";
                                                }
                                            }
                                            m_responseCookies = Trim(m_responseCookies, L" ");
                                            if (m_responseCookies.size() > 0 && m_responseCookies[m_responseCookies.size() - 1] != L';')
                                            {
                                                m_responseCookies += L";";
                                            }
                                        }
                                    }
                                    delete[] szHeader;
                                }
                            }

                            dwSize = 0;
                            bResult = ::WinHttpQueryHeaders(hRequest,
                                                            WINHTTP_QUERY_STATUS_CODE,
                                                            WINHTTP_HEADER_NAME_BY_INDEX,
                                                            NULL,
                                                            &dwSize,
                                                            WINHTTP_NO_HEADER_INDEX);
                            if (bResult || (!bResult && (::GetLastError() == ERROR_INSUFFICIENT_BUFFER)))
                            {
                                wchar_t *szStatusCode = new wchar_t[dwSize];
                                if (szStatusCode != NULL)
                                {
                                    memset(szStatusCode, 0, dwSize* sizeof(wchar_t));
                                    if (::WinHttpQueryHeaders(hRequest,
                                                              WINHTTP_QUERY_STATUS_CODE,
                                                              WINHTTP_HEADER_NAME_BY_INDEX,
                                                              szStatusCode,
                                                              &dwSize,
                                                              WINHTTP_NO_HEADER_INDEX))
                                    {
                                        m_statusCode = szStatusCode;
                                    }
                                    delete[] szStatusCode;
                                }
                            }

                            unsigned int iMaxBufferSize = INT_BUFFERSIZE;
                            unsigned int iCurrentBufferSize = 0;
                            if (m_pResponse != NULL)
                            {
                                delete[] m_pResponse;
                                m_pResponse = NULL;
                            }
                            m_pResponse = new BYTE[iMaxBufferSize];
                            if (m_pResponse == NULL)
                            {
                                bRetVal = false;
                                break;
                            }
                            memset(m_pResponse, 0, iMaxBufferSize);
                            do
                            {
                                dwSize = 0;
                                if (::WinHttpQueryDataAvailable(hRequest, &dwSize))
                                {
                                    if (dwSize == 0)
                                    {
                                        break;
                                    }
                                    BYTE *pResponse = new BYTE[dwSize + 1];
                                    if (pResponse != NULL)
                                    {
                                        memset(pResponse, 0, (dwSize + 1)*sizeof(BYTE));
                                        DWORD dwRead = 0;
                                        if (::WinHttpReadData(hRequest,
                                                              pResponse,
                                                              dwSize,
                                                              &dwRead))
                                        {
                                            if (dwRead + iCurrentBufferSize > iMaxBufferSize)
                                            {
                                                BYTE *pOldBuffer = m_pResponse;
                                                m_pResponse = new BYTE[iMaxBufferSize * 2];
                                                if (m_pResponse == NULL)
                                                {
                                                    m_pResponse = pOldBuffer;
                                                    bRetVal = false;
                                                    break;
                                                }
                                                iMaxBufferSize *= 2;
                                                memset(m_pResponse, 0, iMaxBufferSize);
                                                memcpy(m_pResponse, pOldBuffer, iCurrentBufferSize);
                                                delete[] pOldBuffer;
                                            }
                                            memcpy(m_pResponse + iCurrentBufferSize, pResponse, dwRead);
                                            iCurrentBufferSize += dwRead;
                                        }
                                        delete[] pResponse;
                                    }
                                }
                                else
                                {
                                    m_dwLastError = ::GetLastError();
                                }
                            }
                            while (dwSize > 0);
                            m_responseByteCountReceived = iCurrentBufferSize;

                            if (m_responseByteCountReceived != 0)
                            {
                                UINT codePage = CP_ACP;
                                DWORD dwFlag = MB_PRECOMPOSED;
                                if (_wcsnicmp(m_responseCharset.c_str(), L"utf-8", 5) == 0)
                                {
                                    codePage = CP_UTF8;
                                    dwFlag = 0;
                                }
                                int iLength = ::MultiByteToWideChar(codePage,
                                                                    dwFlag,
                                                                    (LPCSTR)m_pResponse,
                                                                    m_responseByteCountReceived + 1,
                                                                    NULL,
                                                                    0);
                                if (iLength <= 0)
                                {
                                    // Use CP_ACP if UTF-8 fail
                                    codePage = CP_ACP;
                                    dwFlag = MB_PRECOMPOSED;
                                    iLength = ::MultiByteToWideChar(codePage,
                                                                    dwFlag,
                                                                    (LPCSTR)m_pResponse,
                                                                    m_responseByteCountReceived + 1,
                                                                    NULL,
                                                                    0);
                                }
                                if (iLength > 0)
                                {
                                    wchar_t *wideChar = new wchar_t[iLength];
                                    if (wideChar != NULL)
                                    {
                                        memset(wideChar, 0, iLength * sizeof(wchar_t));
                                        iLength = ::MultiByteToWideChar(codePage,
                                                                        dwFlag,
                                                                        (LPCSTR)m_pResponse,
                                                                        m_responseByteCountReceived + 1,
                                                                        wideChar,
                                                                        iLength);
                                        if (iLength > 0)
                                        {
                                            m_responseContent = wideChar;
                                        }
                                        delete[] wideChar;
                                    }
                                }
                                bGetReponseSucceed = true;

                                // If the resposne html web page size is less than 200, retry.
                                if (verb == L"GET" && !disableAutoRedirect)
                                {
                                    wstring regExp = L"{<html>}";
                                    vector<wstring> result;
                                    if (ParseRegExp(regExp, false, 1, m_responseContent, result) && result.size() > 0)
                                    {
                                        regExp = L"{</html>}";
                                        if (!ParseRegExp(regExp, false, 1, m_responseContent, result) || result.size() <= 0)
                                        {
                                            m_dwLastError = ERROR_INVALID_DATA;
                                            bGetReponseSucceed = false;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                bGetReponseSucceed = false;
                                m_dwLastError = ERROR_INVALID_DATA;
                            }
                        }
                        else
                        {
                            m_dwLastError = ::GetLastError();
                        }
                    }
                } // while
                if (!bGetReponseSucceed)
                {
                    bRetVal = false;
                }

                ::WinHttpCloseHandle(hRequest);
            }
            ::WinHttpCloseHandle(hConnect);
        }
    }

    return bRetVal;
}

// @0x140922810
wstring CWinHttpClient::GetResponseHeader()
{
    return m_responseHeader;
}

// @0x140922860
wstring CWinHttpClient::FUN_140922860()
{
    return m_responseContent;
}

// @0x1409228b0
wstring CWinHttpClient::GetResponseCharset()
{
    return m_responseCharset;
}

// @0x140922900
wstring CWinHttpClient::GetResponseStatusCode()
{
    return m_statusCode;
}

// @0x140922950
wstring CWinHttpClient::GetResponseLocation()
{
    return m_location;
}

// @0x1409229a0
wstring CWinHttpClient::GetRequestHost()
{
    return m_requestHost;
}

// @0x1409229f0
const BYTE *CWinHttpClient::GetRawResponseContent()
{
    return m_pResponse;
}

// @0x140922a10
unsigned int CWinHttpClient::GetRawResponseContentLength()
{
    return m_responseByteCount;
}

// @0x140922a30
unsigned int CWinHttpClient::GetRawResponseReceivedContentLength()
{
    return m_responseByteCountReceived;
}

// @0x140922a50
wstring CWinHttpClient::GetResponseCookies()
{
    return m_responseCookies;
}

// @0x140922aa0
bool CWinHttpClient::SaveResponseToFile(const wstring &filePath)
{
    if (m_pResponse == NULL || m_responseByteCountReceived <= 0)
    {
        return false;
    }
    FILE *f = NULL;
    int iRet = _wfopen_s(&f, filePath.c_str(), L"wb");
    if (iRet == 0 && f != NULL)
    {
        fwrite(m_pResponse, m_responseByteCountReceived, 1, f);
        fclose(f);
        return true;
    }

    return false;
}

// @0x140922b50
bool CWinHttpClient::SetAdditionalRequestCookies(const wstring &cookies)
{
    m_additionalRequestCookies = cookies;

    return true;
}

// @0x140922b90
bool CWinHttpClient::FUN_140922b90(const unsigned char *data, unsigned int dataSize)
{
    if (data == NULL || dataSize < 0)
    {
        return false;
    }
    if (m_pDataToSend != NULL)
    {
        delete[] m_pDataToSend;
    }
    m_pDataToSend = NULL;
    m_pDataToSend = new BYTE[dataSize];
    if (m_pDataToSend != NULL)
    {
        memset(m_pDataToSend, 0, dataSize);
        memcpy(m_pDataToSend, data, dataSize);
        m_dataToSendSize = dataSize;
        return true;
    }

    return false;
}

// @0x140922c80
bool CWinHttpClient::UpdateUrl(const wstring &url)
{
    m_requestURL = url;
    ResetAdditionalDataToSend();

    return true;
}

// @0x140922cc0
bool CWinHttpClient::ResetAdditionalDataToSend()
{
    if (m_pDataToSend != NULL)
    {
        delete[] m_pDataToSend;
    }
    m_pDataToSend = NULL;
    m_dataToSendSize = 0;

    return true;
}

// @0x140922d20
bool CWinHttpClient::FUN_140922d20(const wstring &additionalRequestHeaders)
{
    m_additionalRequestHeaders = additionalRequestHeaders;

    return true;
}

// @0x140922d80
bool CWinHttpClient::SetProxy(const wstring &proxy)
{
    m_proxy = proxy;

    return true;
}

// @0x140922dc0
bool CWinHttpClient::SetUserAgent(const wstring &userAgent)
{
    m_userAgent = userAgent;

    return true;
}

// @0x140922e00
bool CWinHttpClient::SetForceCharset(const wstring &charset)
{
    m_responseCharset = charset;

    return true;
}

// @0x140922e40
bool CWinHttpClient::SetProxyUsername(const wstring &username)
{
    m_proxyUsername = username;

    return true;
}

// @0x140922e80
bool CWinHttpClient::SetProxyPassword(const wstring &password)
{
    m_proxyPassword = password;

    return true;
}

// @0x140922ec0
bool CWinHttpClient::SetTimeouts(unsigned int resolveTimeout,
                                 unsigned int connectTimeout,
                                 unsigned int sendTimeout,
                                 unsigned int receiveTimeout)
{
    m_resolveTimeout = resolveTimeout;
    m_connectTimeout = connectTimeout;
    m_sendTimeout = sendTimeout;
    m_receiveTimeout = receiveTimeout;

    return true;
}

// @0x140922f20
int CWinHttpClient::FUN_140922f20()
{
    return m_dwLastError;
}

// ---- RegExp.h ----

// @0x140922f40
bool ParseRegExp(const wstring &regExp, bool caseSensitive, int groupCount, const wstring &source, vector<wstring> &result, bool allowDuplicate)
{
    result.clear();
    if (regExp.size() <= 0)
    {
        return false;
    }
    if (groupCount <= 0)
    {
        return false;
    }
    if (source.size() <= 0)
    {
        return false;
    }
    CAtlRegExp<CAtlRECharTraitsW> re;
    REParseError error = re.Parse(regExp.c_str(), caseSensitive);
    if (error != REPARSE_ERROR_OK)
    {
        return false;
    }
    wchar_t *pSource = new wchar_t[source.size()+1];
    wchar_t *pSourceEnd = pSource + source.size();
    if (pSource == NULL)
    {
        return false;
    }
    wcscpy_s(pSource, source.size()+1, source.c_str());
    BOOL bSucceed = TRUE;
    CAtlREMatchContext<CAtlRECharTraitsW> mc;
    const wchar_t *pFrom = pSource;
    const wchar_t *pTo = NULL;
    while (bSucceed)
    {
        bSucceed = re.Match(pFrom, &mc, &pTo);
        if (bSucceed)
        {
            const wchar_t *pStart = NULL;
            const wchar_t *pEnd = NULL;
            vector<wstring> tempMatch;
            for (int i = 0; i < groupCount; i++)
            {
                mc.GetMatch(i, &pStart, &pEnd);
                if (pStart != NULL && pEnd != NULL)
                {
                    wstring match(pStart, pEnd-pStart);
                    tempMatch.push_back(match);
                }
                else
                {
                    break;
                }
            }
            bool bAdd = true;
            if (!allowDuplicate)
            {
                // Check whether this match already exists in the vector.
                for (vector<wstring>::iterator it = result.begin(); it != result.end();)
                {
                    bool bEqual = true;
                    for (vector<wstring>::iterator tempMatchIt = tempMatch.begin(); tempMatchIt != tempMatch.end(); tempMatchIt++, it++)
                    {
                        bool bGroupEqual = true;
                        if (caseSensitive)
                        {
                            bGroupEqual = (__imp_wcscmp(it->c_str(), tempMatchIt->c_str()) == 0);
                        }
                        else
                        {
                            bGroupEqual = (_wcsicmp(it->c_str(), tempMatchIt->c_str()) == 0);
                        }
                        if (!bGroupEqual)
                        {
                            bEqual = false;
                        }
                    }
                    if (bEqual)
                    {
                        bAdd = false;
                        break;
                    }
                }
            }
            if (bAdd)
            {
                for (vector<wstring>::iterator tempMatchIt = tempMatch.begin(); tempMatchIt != tempMatch.end(); tempMatchIt++)
                {
                    result.push_back(*tempMatchIt);
                }
            }
            if (pTo < pSourceEnd)
            {
                pFrom = pTo;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    delete[] pSource;

    return true;
}

// ---- StringProcess.h ----

// @0x140923500
wstring Trim(const wstring &source, const wstring &targets)
{
    wstring::size_type start = 0;
    wstring::size_type end = 0;
    for (start = 0; start < source.size(); start++)
    {
        bool bIsTarget = false;
        for (wstring::size_type i = 0; i < targets.size(); i++)
        {
            if (source[start] == targets[i])
            {
                bIsTarget = true;
                break;
            }
        }
        if (!bIsTarget)
        {
            break;
        }
    }
    for (end = source.size() - 1; (int)end >= 0; end--)
    {
        bool bIsTarget = false;
        for (wstring::size_type i = 0; i < targets.size(); i++)
        {
            if (source[end] == targets[i])
            {
                bIsTarget = true;
                break;
            }
        }
        if (!bIsTarget)
        {
            break;
        }
    }
    wstring result = L"";
    if (end >= start && start < source.size() && end >= 0)
    {
        result = source.substr(start, end-start+1);
    }

    return result;
}

// @0x140923790
bool PrepareString(wchar_t *dest, size_t *size, const wstring &src)
{
    if (dest == NULL)
    {
        if (size != NULL)
        {
            *size = src.size();
        }
        return false;
    }
    else
    {
        if (size != NULL)
        {
            wcsncpy_s(dest, *size, src.c_str(), _TRUNCATE);
            if (*size <= src.size())
            {
                ::SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return false;
            }
        }
    }
    return true;
}

// @0x140923830
wstring ReplaceString(const wstring &srcStr, const wstring &oldStr, const wstring &newStr)
{
    if (srcStr.size() <= 0 || oldStr.size() <= 0)
    {
        return srcStr;
    }
    wstring strReturn = srcStr;
    wstring::size_type offset = 0;
    wstring::size_type start = strReturn.find(oldStr);
    while (start != wstring::npos)
    {
        offset = start + newStr.size();
        strReturn.replace(start, oldStr.size(), newStr);
        start = strReturn.find(oldStr, offset);
    }

    return strReturn;
}

// @0x1409239a0
int StringToInteger(const wstring &number)
{
    if (number.size() <= 0)
    {
        return 0;
    }
    wstring num = ReplaceString(number, L",", L"");
    num = ReplaceString(num, L" ", L"");

    return _wtoi(num.c_str());
}

// @0x140923b10
wstring LowerString(const wstring &text)
{
    if (text.size() <= 0)
    {
        return L"";
    }
    unsigned int iLength = (unsigned int)text.size() + 1;
    wchar_t *pTemp = new wchar_t[iLength];
    if (pTemp == NULL)
    {
        return L"";
    }
    wcscpy_s(pTemp, iLength, text.c_str());
    _wcslwr_s(pTemp, iLength);
    wstring retStr = pTemp;
    delete[] pTemp;

    return retStr;
}

// @0x140923c90
wstring UpperString(const wstring &text)
{
    if (text.size() <= 0)
    {
        return L"";
    }
    unsigned int iLength = (unsigned int)text.size() + 1;
    wchar_t *pTemp = new wchar_t[iLength];
    if (pTemp == NULL)
    {
        return L"";
    }
    wcscpy_s(pTemp, iLength, text.c_str());
    _wcsupr_s(pTemp, iLength);
    wstring retStr = pTemp;
    delete[] pTemp;

    return retStr;
}

// @0x140923e10
wstring GetAnchorText(const wstring &anchor)
{
    wstring regExp = L"<a.*?>[ \t\r\n]*{.*?}[ \t\r\n]*</a>";
    vector<wstring> result;
    if (ParseRegExp(regExp, false, 1, anchor, result) && result.size() == 1)
    {
        wstring text = result[0];
        return text;
    }

    return L"";
}

// @0x140923f60
wstring GetAnchorLink(const wstring &anchor)
{
    wstring regExp = L"<a.*?href=\"|\'{.*?}\"|\'.*?>.*?</a>";
    vector<wstring> result;
    if (ParseRegExp(regExp, false, 1, anchor, result) && result.size() == 1)
    {
        wstring link = result[0];
        return link;
    }

    return L"";
}

// @0x1409240b0
bool SeparateString(const wstring &content, const wstring &delimiter, vector<wstring> &result)
{
    if (content.size() <= 0 || delimiter.size() <= 0)
    {
        return false;
    }

    result.clear();
    wstring::size_type start = 0;
    wstring::size_type index = 0;
    index = content.find(delimiter, start);
    while (index != wstring::npos)
    {
        wstring::size_type size = index - start;
        if (size > 0)
        {
            wstring temp = content.substr(start, size);
            if (temp.size() > 0)
            {
                result.push_back(temp);
            }
        }
        start  += size + delimiter.size();
        index = content.find(delimiter, start);
    }
    if (content.find(delimiter) != wstring::npos)
    {
        wstring last = content.substr(start);
        if (last.size() > 0)
        {
            result.push_back(last);
        }
    }
    else
    {
        false;
    }

    return true;
}

// @0x1409242a0
wstring URLEncoding(const wstring &keyword, bool convertToUTF8)
{
    int iLength = 0;
    char *szKeyword = NULL;

    if (convertToUTF8)
    {
        iLength = ::WideCharToMultiByte(CP_UTF8,
                                        0,
                                        keyword.c_str(),
                                        keyword.length(),
                                        NULL,
                                        0,
                                        NULL,
                                        NULL);
        if (iLength <= 0)
        {
            return L"";
        }

        szKeyword = new char[iLength];
        if (szKeyword == NULL)
        {
            return L"";
        }
        iLength = ::WideCharToMultiByte(CP_UTF8,
                                        0,
                                        keyword.c_str(),
                                        keyword.length(),
                                        szKeyword,
                                        iLength,
                                        NULL,
                                        NULL);
    }
    else
    {
        string strKeyword = (char *)(_bstr_t)keyword.c_str();
        iLength = (int)strKeyword.length();
        szKeyword = new char[strKeyword.length() + 1];
        strcpy_s(szKeyword, strKeyword.length() + 1, strKeyword.c_str());
    }

    wstring encodedKeyword = L"";
    string strEncodedKeyword = "";
    for (int i = 0; i < iLength; i++)
    {
        unsigned char c = (unsigned char)szKeyword[i];
        char temp[MAX_PATH] = "";
        sprintf_s(temp, MAX_PATH, "%%%2X", c);
        if (temp[1] == ' ')
        {
            temp[1] = '0';
        }
        strEncodedKeyword += temp;
    }
    if (szKeyword != NULL)
    {
        delete[] szKeyword;
    }
    encodedKeyword = (wchar_t *)(_bstr_t)strEncodedKeyword.c_str();
    encodedKeyword = ReplaceString(encodedKeyword, L" ", L"+");

    return encodedKeyword;
}

// @0x140924780
unsigned int GetSeparateKeywordMatchGrade(const wstring &source, const wstring &keyword)
{
    if (source.length() <= 0 || keyword.length() <= 0)
    {
        return 0;
    }

    wstring lowerSource = LowerString(source);
    wstring lowerKeyword = LowerString(keyword);

    unsigned int grade = 0;
    if (lowerKeyword.length() <= 3)
    {
        if (lowerSource.find(lowerKeyword) != wstring::npos)
        {
            grade = 100;
        }
        else
        {
            grade = 0;
        }
    }
    else
    {
        unsigned int matchLength = 0;
        unsigned int index = 0;
        while (index < lowerKeyword.length())
        {
            unsigned int compareLength = (unsigned int)lowerKeyword.length() - index;
            while (compareLength > 0 && index < lowerKeyword.length())
            {
                wstring subKeyword = lowerKeyword.substr(index, compareLength);
                if (lowerSource.find(subKeyword) != wstring::npos)
                {
                    matchLength += compareLength;
                    index += compareLength;
                }
                else
                {
                    compareLength--;
                }
            }
            index++;
        }
        grade = matchLength * 100 / (unsigned int)lowerKeyword.length();
    }

    return grade;
}

// @0x1409249b0
unsigned int GetKeywordMatchGrade(const wstring &source, const wstring & keyword)
{
    if (source.length() <= 0 || keyword.length() <= 0)
    {
        return 0;
    }

    unsigned int grade = 0;
    wstring src = source;
    while (src.find(L"\t") != wstring::npos)
    {
        src = ReplaceString(src, L"\t", L" ");
    }
    while (src.find(L"  ") != wstring::npos)
    {
        src = ReplaceString(src, L"  ", L" ");
    }
    vector<wstring> results;
    if (SeparateString(keyword, L" ", results) && results.size() > 0)
    {
        unsigned int keywordTotalLength = 0;
        for (vector<wstring>::size_type index = 0; index < results.size(); index++)
        {
            keywordTotalLength += (unsigned int)results[index].length();
        }
        for (vector<wstring>::size_type index = 0; index < results.size(); index++)
        {
            grade += GetSeparateKeywordMatchGrade(src, results[index]) * (unsigned int)results[index].length() / keywordTotalLength;
        }
    }
    else
    {
        grade = GetSeparateKeywordMatchGrade(src, keyword);
    }

    return grade;
}

// @0x140924d70
wstring MD5(const wstring &text)
{
    if (text.size() <= 0)
    {
        return L"";
    }
    string asciiText = (char *)(_bstr_t)text.c_str();
    wstring encrypted = L"";
    HCRYPTPROV hCryptProv = NULL;
    if (::CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_MACHINE_KEYSET))
    {
        HCRYPTHASH hHash = NULL;
        if (::CryptCreateHash(hCryptProv, CALG_MD5, 0, 0, &hHash))
        {
            if (::CryptHashData(hHash, (BYTE *)asciiText.c_str(), asciiText.size(), 0))
            {
                BYTE result[16];
                DWORD dwSize = 16;
                wchar_t temp[3] = L"";
                if (::CryptGetHashParam(hHash, HP_HASHVAL, result, &dwSize, 0))
                {
                    for (unsigned int i = 0; i < 16; i++)
                    {
                        memset(temp, 0, 6);
                        swprintf(temp, 3, L"%02x", result[i]);
                        encrypted += temp;
                    }
                }
            }
            ::CryptDestroyHash(hHash);
            ::CryptReleaseContext(hCryptProv, 0);
        }
    }

    return encrypted;
}

// @0x140925020
wstring FilterFileName(const wstring &name)
{
    if (name.size() <= 0)
    {
        return L"";
    }

    wstring filteredName = name;
    filteredName = ReplaceString(filteredName, L"/", L"_");
    filteredName = ReplaceString(filteredName, L"\\", L"_");
    filteredName = ReplaceString(filteredName, L":", L"_");
    filteredName = ReplaceString(filteredName, L"*", L"_");
    filteredName = ReplaceString(filteredName, L"?", L"_");
    filteredName = ReplaceString(filteredName, L"\"", L"_");
    filteredName = ReplaceString(filteredName, L"<", L"_");
    filteredName = ReplaceString(filteredName, L">", L"_");
    filteredName = ReplaceString(filteredName, L"|", L"_");

    return filteredName;
}

// @0x1409255d0
wstring GetMagic(unsigned int length)
{
    srand(::GetTickCount());
    if (length <= 0)
    {
        return L"";
    }

    wstring margic = L"";
    for (unsigned int i = 0; i < length; i++)
    {
        wchar_t szMargic[50] = L"";
        swprintf_s(szMargic, 50, L"%c", rand() % 26 + L'a');
        margic += szMargic;
    }

    return margic;
}

// @0x140925730
wstring GetHost(const wstring &url)
{
    if (url.size() <= 0)
    {
        return L"";
    }

    wstring urlWidthoutHttp = ReplaceString(LowerString(url), L"http://", L"");

    unsigned int index = urlWidthoutHttp.find(L"/");
    if (index == wstring::npos)
    {
        index = urlWidthoutHttp.find(L"\\");
    }
    if (index == wstring ::npos)
    {
        return urlWidthoutHttp;
    }

    return urlWidthoutHttp.substr(0, index);
}

// @0x140925900
wstring GetValidFileName(const wstring &fileName)
{
    if (fileName.size() == 0)
    {
        return L"";
    }
    wstring tempFileName = fileName;
    tempFileName = ReplaceString(tempFileName, L"\\", L"_");
    tempFileName = ReplaceString(tempFileName, L"/", L"_");
    tempFileName = ReplaceString(tempFileName, L":", L"_");
    tempFileName = ReplaceString(tempFileName, L"*", L"_");
    tempFileName = ReplaceString(tempFileName, L"?", L"_");
    tempFileName = ReplaceString(tempFileName, L"\"", L"_");
    tempFileName = ReplaceString(tempFileName, L"<", L"_");
    tempFileName = ReplaceString(tempFileName, L">", L"_");
    tempFileName = ReplaceString(tempFileName, L"|", L"_");
    tempFileName = ReplaceString(tempFileName, L"\r", L"_");
    tempFileName = ReplaceString(tempFileName, L"\n", L"_");
    tempFileName = ReplaceString(tempFileName, L"%", L"_");

    return tempFileName;
}

// ---- SpecialNPCInfo (the next TU: three small functions after the WinHttpClient template tail) ----

// @0x14092c0a0
SpecialNPCInfo::SpecialNPCInfo()
{
    m_nNpcId = 0;
    m_nFieldId = 0;
    m_n08 = 0;
    m_n10 = 0;
    m_n18 = 0;
}

// @0x14092c0f0
void SpecialNPCInfo::FUN_14092c0f0(COutputStream& out)
{
    out.vfunc_o10_3(m_nNpcId);
    out.vfunc_o10_3(m_nFieldId);
    out.vfunc_o10_2((short)m_n08);
    out.vfunc_o10_4(m_n10);
    out.vfunc_o10_1((unsigned char)m_n18);
}

// @0x14092c190
void SpecialNPCInfo::FUN_14092c190(CInputStream& in)
{
    m_nNpcId = in.vfunc_o8_3();
    m_nFieldId = in.vfunc_o8_3();
    m_n08 = (unsigned short)in.vfunc_o8_2();
    m_n10 = in.vfunc_o8_4();
    m_n18 = in.vfunc_o8_1();
}
