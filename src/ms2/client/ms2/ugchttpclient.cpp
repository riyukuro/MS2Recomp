// MS2-UNIT: ?\ugchttpclient.cpp
// MS2-RANGE: 0x140dfa160-0x140dfc1b0 .text$mn
// MS2-RANGE: 0x1400d6b50-0x1400d6d00 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugchttpclient.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include <string>
#include <string.h>
#include <stdlib.h>
#include <wininet.h>

#include "ms2/placeholder/exception.h"
#include "ms2/ms2format.h"

#include "ugchttpclient.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Statics. The exe emits them in this order: the base64 alphabet, the byte counter of InternetReadFile, then the two
// sort-name tables (the .text$di order follows the declaration order).
static std::string s_strBase64Alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");  // 0x143ac5488

static DWORD s_nBytesRead = 0;                                                                               // 0x143ac54a8

static CString s_strSortTypeNamesN[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};  // 0x143ac54b0

static CString s_strSortTypeNamesExN[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};  // 0x143ac5508

// The exe's second formatter (0x1402bf9a0); the POST header block is built with its 3-string instantiation.
CString FUN_140513200(const char* szFormat, const unsigned int& nArg);

// @0x140dfbc70: the "{0}{1}{2}" instantiation the POST header block is built with. It must be declared before its first
// use (RequestPost), otherwise the call site instantiates the generic wrapper first.
template <>
CString Unk_SocketFormat<const char*, CString, const char*>(const char* format, const char* const& v0, const CString& v1,
                                                            const char* const& v2)
{
    const fmt::internal::ArgArray<3>::Type array = {fmt::internal::MakeValue<fmt::BasicFormatter<char>>(v0),
                                                    fmt::internal::MakeValue<fmt::BasicFormatter<char>>(v1),
                                                    fmt::internal::MakeValue<fmt::BasicFormatter<char>>(v2)};
    return Unk_SocketFormat(format, fmt::ArgList(fmt::internal::make_type(v0, v1, v2), array));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CUgcHttpClient

// @0x140dfa160
CUgcHttpClient::CUgcHttpClient()
{
    m_hInternet = 0;
    m_hConnect = 0;
    m_hRequest = 0;
    m_buffer.FUN_140518490();
    m_nResult = 0;
}

// @0x140dfa200
CUgcHttpClient::~CUgcHttpClient()
{
    m_hInternet = 0;
    m_hConnect = 0;
    m_hRequest = 0;
    m_buffer.FUN_140518490();
}

// @0x140dfa290
int CUgcHttpClient::Connect(const char* pszHost, const char* pszUserAgent, int nPort, const char* pszUser,
                             const char* pszPass)
{
    int bOk = 1;
    try {
        m_hInternet = InternetOpenA(pszUserAgent, 0, "", "", 0);
        if (m_hInternet == 0) {
            throw Exception(CString("Connect : InternetOpen"), GetLastError());
        }
        m_hConnect = InternetConnectA(m_hInternet, pszHost, nPort, pszUser, pszPass, 3, 0x4400000, 0);
        if (m_hConnect == 0) {
            throw Exception(CString("Connect : InternetConnect"), GetLastError());
        }
        if (InternetAttemptConnect(0) != 0) {
            throw Exception(CString("Connect : InternetAttemptConnect"), GetLastError());
        }
    } catch (Exception& e) {
        m_nStatus = e.GetCode();
        m_strError = e.GetText();
        if (m_hInternet != 0) {
            InternetCloseHandle(m_hInternet);
        }
        if (m_hConnect != 0) {
            InternetCloseHandle(m_hConnect);
        }
        bOk = 0;
    }
    return bOk;
}

// @0x140dfa490
int CUgcHttpClient::Disconnect()
{
    if (m_hRequest != 0) {
        InternetCloseHandle(m_hRequest);
    }
    if (m_hConnect != 0) {
        InternetCloseHandle(m_hConnect);
    }
    if (m_hInternet != 0) {
        InternetCloseHandle(m_hInternet);
    }
    return true;
}

// @0x140dfa500
int CUgcHttpClient::Request(const char* pszUrl)
{
    int bOk = 1;
    long nPort = 0;
    char szProtocol[1024] = "";
    char szHost[1024] = "";
    char szPath[1024] = "";
    unsigned nRead = 0;

    FUN_140dfaf10(pszUrl, szProtocol, szHost, &nPort, szPath);
    if (Connect(szHost, "UgcHttp", nPort, 0, 0)) {
        if (!RequestEx(szPath)) {
            bOk = 0;
        } else {
            m_nResult = 0;
            if (!Response(m_szHeader, 100000, m_szBody, 100000, &nRead)) {
                bOk = 0;
            } else {
                m_nResult = nRead;
            }
        }
        Disconnect();
    } else {
        bOk = 0;
    }
    return bOk;
}

// @0x140dfa6e0
int CUgcHttpClient::RequestEx(const char* pszUrl)
{
    int bOk = 1;
    try {
        bOk = RequestPost(pszUrl);
    } catch (CException* e) {
        char szError[1024];
        e->GetErrorMessage(szError, 1024, 0);
        m_strError = szError;
    }
    return bOk;
}

// @0x140dfa760
int CUgcHttpClient::Response(char* pszHeader, unsigned nHeaderSize, char* pszBody, unsigned nBodySize,
                             unsigned* pnRead)
{
    int bOk = 1;
    char szChunk[1024] = "";
    unsigned nChunk = 0;
    try {
        if (m_hRequest == 0) {
            throw Exception(CString("Response : handle request is null"), GetLastError());
        }
        memset(pszBody, 0, nBodySize);
        *pnRead = 0;
        while ((nChunk = ResponseOfBytes(szChunk, 0x400)) != 0 && *pnRead < nBodySize) {
            memcpy(pszBody + *pnRead, szChunk, nChunk);
            *pnRead += nChunk;
        }
        memset(pszHeader, 0, nHeaderSize);
        if (HttpQueryInfoA(m_hRequest, 0x16, pszHeader, (DWORD*)&nHeaderSize, 0) == 0) {
            throw Exception(CString("Response : HttpQueryInfo"), GetLastError());
        }
    } catch (Exception& e) {
        m_nStatus = e.GetCode();
        m_strError = e.GetText();
        if (m_hRequest != 0) {
            InternetCloseHandle(m_hRequest);
        }
        bOk = 0;
    }
    if (!bOk) {
        return 0;
    }
    return *pnRead != 0;
}

// @0x140dfa9e0
char* CUgcHttpClient::Body()
{
    return m_szBody;
}

// @0x140dfaa00
char* CUgcHttpClient::Header()
{
    return m_szHeader;
}

// @0x140dfaa20
int CUgcHttpClient::Result()
{
    return m_nResult;
}

// @0x140dfaa40
int CUgcHttpClient::RequestPost(const char* pszUrl)
{
    int bOk = 1;
    if (m_buffer.GetLength() == 0) {
        m_nStatus = 0;
        m_strError = "RequestPost : UgcDataEmpty";
        return 0;
    }
    const char* pszContentType = "Content-Type: application/octet-stream\r\n";
    const char* pszConnection = "Connection: close\r\n";
    CString strLength = FUN_140513200("Content-Length: {0}\r\n", m_buffer.GetLength());
    CString strHeaders = Unk_SocketFormat("{0}{1}{2}", pszContentType, strLength, pszConnection);
    const char* aszAccept[2] = {"*/*", 0};
    try {
        m_hRequest = HttpOpenRequestA(m_hConnect, "POST", pszUrl, "HTTP/1.0", "", aszAccept, 0x4400040, 0);
        if (m_hRequest == 0) {
            throw Exception(CString("RequestPost : HttpOpenRequest"), GetLastError());
        }
        if (HttpAddRequestHeadersA(m_hRequest, "Accept: */*\r\n", 0xd, 0x80000000) == 0) {
            throw Exception(CString("RequestPost : HttpAddRequestHeaders"), GetLastError());
        }
        if (HttpSendRequestA(m_hRequest, strHeaders, (DWORD)strlen(strHeaders), m_buffer.FUN_140204eb0(),
                             m_buffer.GetLength()) == 0) {
            throw Exception(CString("RequestPost : HttpSendRequest"), GetLastError());
        }
    } catch (Exception& e) {
        m_nStatus = e.GetCode();
        m_strError = e.GetText();
        if (m_hRequest != 0) {
            InternetCloseHandle(m_hRequest);
        }
        bOk = 0;
    }
    return bOk;
}

// @0x140dfade0
int CUgcHttpClient::ResponseOfBytes(void* pData, unsigned nSize)
{
    if (m_hRequest == 0) {
        throw Exception(CString("ResponseOfBytes : handle request is null"), GetLastError());
    }
    memset(pData, 0, nSize);
    if (InternetReadFile(m_hRequest, pData, nSize, &s_nBytesRead) == 0) {
        throw Exception(CString("ResponseOfBytes : InternetReadFile"), GetLastError());
    }
    return s_nBytesRead;
}

// @0x140dfb420
void CUgcHttpClient::Append(CByteBuffer& buffer)
{
    unsigned nSize = buffer.GetLength();
    m_buffer.WriteBytes(buffer.FUN_140204eb0(), nSize);
}

// @0x140dfb480
int CUgcHttpClient::StatusCode()
{
    return m_nStatus;
}

// @0x140dfb4a0
CString CUgcHttpClient::ErrorText()
{
    return m_strError;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMDATs

// @0x140dfaf10
void CUgcHttpClient::FUN_140dfaf10(const char* pszUrl, char* pszProtocol, char* pszHost, long* pnPort, char* pszPath)
{
    int nPos = 0;
    int bFound = 0;
    int nHostStart;
    int nColon;

    while (strlen(pszUrl) > 0 && nPos < (int)strlen(pszUrl) && strncmp(pszUrl + nPos, ":", 1) != 0) {
        ++nPos;
    }
    if (strncmp(pszUrl + nPos + 1, "/", 1) == 0) {
        if (pszProtocol != 0) {
            strncpy(pszProtocol, pszUrl, nPos);
            pszProtocol[nPos] = 0;
        }
        bFound = 1;
    } else if (pszProtocol != 0) {
        strncpy(pszProtocol, "http", 4);
        pszProtocol[5] = 0;
    }
    nHostStart = 0;
    if (bFound) {
        nPos += 3;
        nHostStart = nPos;
    } else {
        nPos = 0;
        nHostStart = nPos;
    }
    bFound = 0;
    while (strlen(pszUrl) > 0 && nPos < (int)strlen(pszUrl) && strncmp(pszUrl + nPos, "/", 1) != 0) {
        ++nPos;
    }
    for (nColon = nHostStart; nColon <= nPos; ++nColon) {
        if (strncmp(pszUrl + nColon, ":", 1) == 0) {
            bFound = 1;
            break;
        }
    }
    if (bFound) {
        char szPortBuf[1024] = "";
        strncpy(szPortBuf, pszUrl + nColon + 1, nPos - nColon);
        *pnPort = atol(szPortBuf);
        strncpy(pszHost, pszUrl + nHostStart, nColon - nHostStart);
    } else if (strcmp(pszProtocol, "https") == 0) {
        *pnPort = 0x1bb;
        strncpy(pszHost, pszUrl + nHostStart, nPos - nHostStart);
    } else {
        *pnPort = 0x50;
        strncpy(pszHost, pszUrl + nHostStart, nPos - nHostStart);
    }
    if (nPos < (int)strlen(pszUrl)) {
        strncpy(pszPath, pszUrl + nPos, strlen(pszUrl) - nPos);
    } else {
        pszPath[0] = 0;
    }
}

// @0x140dfb4f0
static bool FUN_140dfb4f0(unsigned char ch)
{
    return isalnum(ch) || ch == 0x2b || ch == 0x2f;
}

// @0x140dfb540
std::string FUN_140dfb540(const unsigned char* pData, int nLength)
{
    std::string strOut;
    unsigned char aTriple[4];
    char aQuad[4];
    int nIndex = 0;
    int nRemain = 0;

    while (nLength != 0) {
        aTriple[nIndex] = *pData;
        ++nIndex;
        ++pData;
        --nLength;
        if (nIndex == 3) {
            aQuad[0] = (char)((aTriple[0] & 0xfc) >> 2);
            aQuad[1] = (char)((aTriple[0] & 3) * 0x10 + ((aTriple[1] & 0xf0) >> 4));
            aQuad[2] = (char)(((aTriple[2] & 0xc0) >> 6) + (aTriple[1] & 0xf) * 4);
            aQuad[3] = (char)(aTriple[2] & 0x3f);
            for (nIndex = 0; nIndex < 4; ++nIndex) {
                strOut += s_strBase64Alphabet[(unsigned char)aQuad[nIndex]];
            }
            nIndex = 0;
        }
    }
    if (nIndex != 0) {
        for (nRemain = nIndex; nRemain < 3; ++nRemain) {
            aTriple[nRemain] = 0;
        }
        aQuad[0] = (char)((aTriple[0] & 0xfc) >> 2);
        aQuad[1] = (char)((aTriple[0] & 3) * 0x10 + ((aTriple[1] & 0xf0) >> 4));
        aQuad[2] = (char)(((aTriple[2] & 0xc0) >> 6) + (aTriple[1] & 0xf) * 4);
        aQuad[3] = (char)(aTriple[2] & 0x3f);
        for (nRemain = 0; nRemain < nIndex + 1; ++nRemain) {
            strOut += s_strBase64Alphabet[(unsigned char)aQuad[nRemain]];
        }
        for (; nIndex < 3; ++nIndex) {
            strOut += '=';
        }
    }
    return strOut;
}

// @0x140dfb8b0
std::string FUN_140dfb8b0(const std::string& strText)
{
    std::string strOut;
    int nLength = (int)strText.length();
    char aQuad[4];
    char aTriple[4];
    int nIndex = 0;
    int nPos = 0;
    int nPad = 0;

    while (true) {
        int nRemain = nLength;
        --nLength;
        if (nRemain == 0 || strText[nPos] == '=') {
            break;
        }
        if (FUN_140dfb4f0((unsigned char)strText[nPos]) == 0) {
            break;
        }
        aQuad[nIndex] = strText[nPos];
        ++nIndex;
        ++nPos;
        if (nIndex == 4) {
            for (nIndex = 0; nIndex < 4; ++nIndex) {
                aQuad[nIndex] = FUN_140dfc030(s_strBase64Alphabet, aQuad[nIndex], 0);
            }
            aTriple[0] = (char)(((aQuad[1] & 0x30) >> 4) + aQuad[0] * 4);
            aTriple[1] = (char)(aQuad[1] * 0x10 + ((aQuad[2] & 0x3c) >> 2));
            aTriple[2] = (char)(aQuad[2] * 0x40 + aQuad[3]);
            for (nIndex = 0; nIndex < 3; ++nIndex) {
                strOut += aTriple[nIndex];
            }
            nIndex = 0;
        }
    }
    if (nIndex != 0) {
        for (nPad = nIndex; nPad < 4; ++nPad) {
            aQuad[nPad] = 0;
        }
        for (nPad = 0; nPad < 4; ++nPad) {
            aQuad[nPad] = FUN_140dfc030(s_strBase64Alphabet, aQuad[nPad], 0);
        }
        aTriple[0] = (char)(((aQuad[1] & 0x30) >> 4) + aQuad[0] * 4);
        aTriple[1] = (char)(aQuad[1] * 0x10 + ((aQuad[2] & 0x3c) >> 2));
        aTriple[2] = (char)(aQuad[2] * 0x40 + aQuad[3]);
        for (nPad = 0; nPad < nIndex - 1; ++nPad) {
            strOut += aTriple[nPad];
        }
    }
    return strOut;
}

// @0x140dfc030
char FUN_140dfc030(std::string& strAlphabet, char ch, unsigned nPos)
{
    return (char)strAlphabet.find(ch, nPos);
}

// @0x140dfc090
MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca6070-0x142ca60f0 .text$yd
