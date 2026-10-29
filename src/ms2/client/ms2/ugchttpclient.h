// ugchttpclient.h - CUgcHttpClient, the WinINet client the UGC (user generated content) upload / download path uses to
// talk to the UGC HTTP service, plus the URL splitter and the base64 codec its signed requests need. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\ugchttpclient.cpp` (0x140dfa160-0x140dfc1b0 .text$mn,
// 0x1400d6b50-0x1400d6d00 .text$di, dir client\ms2). Header name assumed; member names invented from their use.
//
// The class keeps the three WinINet handles at +0x08/+0x10/+0x18, a 100000-byte response body buffer at +0x24, a
// 100044-byte response header buffer at +0x186c4, the outgoing CByteBuffer at +0x30d90, the HTTP status at +0x30dd0 and
// the last error text at +0x30dd8.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"     // CByteBuffer

class CUgcHttpClient
{
public:
    CUgcHttpClient();                                                               // 0x140dfa160
    virtual ~CUgcHttpClient();                                                      // 0x140dfa200

    int  Connect(const char* pszHost, const char* pszUserAgent, int nPort, const char* pszUser,
                 const char* pszPass);                                              // 0x140dfa290
    int  Disconnect();                                                              // 0x140dfa490
    int  Request(const char* pszUrl);                                               // 0x140dfa500
    int  RequestEx(const char* pszUrl);                                             // 0x140dfa6e0
    int  Response(char* pszHeader, unsigned nHeaderSize, char* pszBody, unsigned nBodySize,
                  unsigned* pnRead);                                                // 0x140dfa760

    char* Body();                                                                   // 0x140dfa9e0: m_szBody
    char* Header();                                                                 // 0x140dfaa00: m_szHeader
    int   Result();                                                                 // 0x140dfaa20: m_nResult

    int  RequestPost(const char* pszUrl);                                           // 0x140dfaa40
    int  ResponseOfBytes(void* pData, unsigned nSize);                          // 0x140dfade0

    void Append(CByteBuffer& buffer);                                               // 0x140dfb420
    int  StatusCode();                                                              // 0x140dfb480: m_nStatus
    CString ErrorText();                                                            // 0x140dfb4a0: m_strError

    // The URL splitter: scheme into pszProtocol, host into pszHost, port into pnPort, path into pszPath. A member in
    // the exe (rcx is the client, unused); Request passes this.
    void FUN_140dfaf10(const char* pszUrl, char* pszProtocol, char* pszHost, long* pnPort, char* pszPath); // 0x140dfaf10

    void*      m_hInternet;         // +0x08 InternetOpenA handle
    void*      m_hConnect;          // +0x10 InternetConnectA handle
    void*      m_hRequest;          // +0x18 HttpOpenRequestA handle
    int        m_nResult;           // +0x20 the last request's byte count
    char       m_szBody[100000];    // +0x24 the response body
    char       m_szHeader[100044];  // +0x186c4 the response header block
    CByteBuffer m_buffer;           // +0x30d90 the request payload
    int        m_nStatus;           // +0x30dd0 the HTTP status
    CString    m_strError;          // +0x30dd8 the last error text
};
MS2_CHECK_SIZE(CUgcHttpClient, 0x30de0);

// The base64 codec of the signed requests (the alphabet 0x143ac5488 and its initialiser are this unit's).
std::string FUN_140dfb540(const unsigned char* pData, int nLength);          // 0x140dfb540 encode
std::string FUN_140dfb8b0(const std::string& strText);                       // 0x140dfb8b0 decode

// The fmt-style join the POST header is built with (0x140dfbc70; the three substitutions are the variadic arguments).
CString FUN_140dfbc70(const char* pszFormat, const void* pArg0, const void* pArg1, const void* pArg2);

// 0x140dfc030: the index of a base64 character in the alphabet (char, as the exe truncates).
char FUN_140dfc030(std::string& strAlphabet, char ch, unsigned nPos);

// 0x140dfc090: the bounds-checked memmove (memmove_s).
int FUN_140dfc090(void* pDst, unsigned __int64 nDstSize, const void* pSrc, unsigned __int64 nCount);
