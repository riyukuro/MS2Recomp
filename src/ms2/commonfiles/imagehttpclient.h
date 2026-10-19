// Recovered CImageHttpClient (RTTI .?AVCImageHttpClient@@, 0x78 bytes, vftable at +0 with only the destructor): uploads a
// screenshot of the character / home to the web server as a JSON POST and sends the returned temporary key to the game
// server (packet 0xb8). Original header name assumed; method and member names are inferred.
#pragma once
#include <afx.h>
#include <string>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cwinhttpclient.h"
#include "ms2/placeholder/tptrvalue.h"

class CByteBuffer;

// 8-byte tick holder with the ctor at 0x140517b00 (many units own look-alikes) and the 3000 ms check 0x140268870.
class Unk_ImageTimer
{
public:
    Unk_ImageTimer();                       // 0x140517b00
    int FUN_140268870(int nMilliseconds);   // elapsed check (nonzero: the interval has passed)

private:
    int m_nTick;
    int m_nLast;
};
MS2_CHECK_SIZE(Unk_ImageTimer, 8);

class CImageHttpClient
{
public:
    CImageHttpClient();                                                     // 0x140511030
    virtual ~CImageHttpClient();                                            // 0x1405110d0
    void SetMode(int nMode);                                                // 0x140511190: 1 character, else housing
    void SetImage(int x, int y, int nWidth, int nHeight);                   // 0x1405111b0
    bool RequestKey();                                                      // 0x140511210
    bool UploadTemporaryKey(std::string strKey);                            // 0x140511450
    bool BeginImage();                                                      // 0x1405116c0
    unsigned SendWebScreenshot();                                           // 0x1405118f0
    unsigned SendTemporaryKey();                                            // 0x140511b30
    bool CanSend();                                                         // 0x140511c10
    void ClearRequest();                                                    // 0x140511c80
    bool BuildImage(CByteBuffer& data);                                     // 0x140511cf0
    bool BuildTemporaryKey(CByteBuffer& data, const std::string& strKey);   // 0x140511f80
    std::wstring GetUrl();                                                  // 0x140512100
    std::wstring MakeHeaders(CByteBuffer& data);                            // 0x140512150
    std::string GetImageType();                                             // 0x140512280
    std::string CaptureImage();                                             // 0x1405122f0
    std::string ParseTemporaryKey(const std::wstring& strResponse);         // 0x1405123a0
    TPtrValue<CWinHttpClient> CreateRequest(const std::wstring& strUrl);    // 0x1405125f0
    TPtrValue<CWinHttpClient> GetRequest();                                 // 0x1405126d0
    void SetRequest(TPtrValue<CWinHttpClient> request);                     // 0x140512760
    bool IsRequestPending();                                                // 0x1405127e0
    static unsigned __cdecl ResponseClient(void* pParam);                   // 0x140512880
    static unsigned __cdecl ResponseServer(void* pParam);                   // 0x140512920

private:
    MS2_LAYOUT_FRIEND;
    CRect m_rect;                           // +0x08
    Unk_ImageTimer m_timer;                 // +0x18
    int m_nMode;                            // +0x20
    CWinThread* m_pImageThread;             // +0x28
    CWinThread* m_pUploadThread;            // +0x30
    CLockCriticalSection m_lock;            // +0x38
    TPtrValue<CWinHttpClient> m_request;    // +0x68
};
MS2_CHECK_SIZE(CImageHttpClient, 0x78);
MS2_CHECK_OFFSET(CImageHttpClient, m_request, 0x68);
