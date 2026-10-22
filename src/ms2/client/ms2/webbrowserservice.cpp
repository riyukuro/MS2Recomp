// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CWebBrowserService: the in-game web browser efd system
// service over CEF 3.3396 (see ms2/placeholder/cwebbrowserservice.h), plus the CEF wrapper (scoped_refptr,
// CefStructBase), ATL Server CAtlRegExp<CAtlRECharTraitsA> and std::deque / std::vector instantiations it pulls in.
// Function names other than the efd overrides are invented (the exe has no symbols for them).
// MS2-UNIT: client\ms2\webbrowserservice.cpp
// MS2-RANGE: 0x141b77810-0x141b81ac0 .text$mn
// MS2-RANGE: 0x14011fb70-0x14011fc20 .text$di
// MS2-RANGE: 0x142cc3730-0x142cc3790 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?TypeCast@CWebBrowserService@@UEBA_NIPEAPEAX@Z 0x141b80210 ; unique
// MS2-PIN: ?TypeCast@CWebBrowserService@@UEBA_NIPEAPEBX@Z 0x141b80260 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\webbrowserservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
// CAtlRegExp::Match (0x141b7cda0) sign-extends its _TUCHAR casts (movsx): the SBCS _TUCHAR, char.
#define MS2_ATLRX_TUCHAR char
#include "ms2/placeholder/cwebbrowserservice.h"
#include "ms2/placeholder/ccefms2clientapp.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern int DAT_143ab0248;                       // the service region (0 Korea, 1 Japan, 2 global, 3 China)
extern const char* g_szCefMessageToken;         // 0x1439f7eb0 "token" (the CEF process message names table)
CStringA FUN_1401d2b10(const CStringA& a, const CStringA& b);  // a + b (exe copy of the CStringT operator+)
CStringA FUN_14038f6d0(const CStringA& a, const char* b);      // a + b (exe copy of the CStringT operator+)

// The web page urls: the maview (news) page and the web api (both set from the server by SceneStateGame).
CStringA g_strWebApiURL("http://ms2plan:8002");                 // 0x143af7be8
CStringA g_strMaviewURL("http://ms2plan:8000");                 // 0x143af7be0

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CWebBrowserService);

// The CEF application object (CefInitialize); null until CEF runs.
MS2_WBS_APP_STORAGE CefRefPtr<CCefMS2ClientApp> s_app;                       // 0x143af7bd8

// @0x141b77810
CWebBrowserService::CWebBrowserService(HINSTANCE hInstance)
    : m_hInstance(hInstance)
{
    AddAllowedURL("^https?://ms2plan:8000");
    AddAllowedURL("^https?://maview\\.nexon\\.com");
    AddAllowedURL("^https?://stage\\.maview\\.nexon\\.com");
    AddAllowedURL("^https?://www\\.facebook\\.com");
    if (DAT_143ab0248 == 3) {
        AddAllowedURL("^https?://game\\.qq\\.com");
        AddAllowedURL("^https?://mxd2\\.qq\\.com");
    }
}

// @0x141b77aa0
CWebBrowserService::~CWebBrowserService()
{
    for (size_t i = 0; i < m_aAllowedURLs.GetCount(); i++) {
        delete m_aAllowedURLs[i];
    }
}

// @0x141b77c20
void CWebBrowserService::InitializeCef(HINSTANCE hInstance)
{
    CefMainArgs mainArgs(hInstance);
    s_app = new CCefMS2ClientApp();
    CefSettings settings;
    CStringA strUserAgent("MapleStory2");
    if (DAT_143ab0248 == 2) {
        strUserAgent = "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.80 Safari/537.36";
    }
    cef_string_ascii_to_utf16(strUserAgent, strUserAgent.GetLength(), &settings.user_agent);
    settings.single_process = 1;
    settings.multi_threaded_message_loop = 1;
    settings.pack_loading_disabled = 0;
    settings.no_sandbox = 1;
    settings.windowless_rendering_enabled = 1;
    settings.background_color = 0xffffffff;
    // the app goes through operator CCefMS2ClientApp*() (0x141b81540) and CefRefPtr<CefApp>(T*)
    bool bInitialized = CefInitialize(mainArgs, settings, (CCefMS2ClientApp*)s_app, NULL);
    if (!bInitialized) {
        return;
    }
}

// @0x141b77e10
void CWebBrowserService::FUN_141b77e10()
{
    if (s_app.get()) {
        return;
    }
    InitializeCef(m_hInstance);
}

// @0x141b77e50
void CWebBrowserService::FUN_141b77e50(const CStringA& strUrl)
{
    if (strUrl.GetLength() > 0) {
        g_strMaviewURL = strUrl;
    }
}

// @0x141b77e90
void CWebBrowserService::FUN_141b77e90(const CStringA& strUrl)
{
    if (strUrl.GetLength() > 0) {
        g_strWebApiURL = strUrl;
    }
}

// @0x141b77ed0
void CWebBrowserService::FUN_141b77ed0(const CStringA& strUrls)
{
    if (strUrls.GetLength() == 0) {
        return;
    }
    int nPos = 0;
    CStringA strPattern = strUrls.Tokenize(" ", nPos);
    while (strPattern.GetLength() > 0) {
        GetInstance()->AddAllowedURL(strPattern);
        strPattern = strUrls.Tokenize(" ", nPos);
    }
}

// @0x141b77fa0
bool CWebBrowserService::AddAllowedURL(const CStringA& strPattern)
{
    ATL::CAtlRegExp<>* pRegExp = new ATL::CAtlRegExp<>();
    if (pRegExp->Parse(strPattern, FALSE) != REPARSE_ERROR_OK) {
        delete pRegExp;
        MS2_ASSERT_AT(146, FALSE);
        return false;
    }
    m_aAllowedURLs.Add(pRegExp);
    return true;
}

// @0x141b78090
bool CWebBrowserService::IsAllowedURL(const CStringA& strUrl)
{
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036e560()
        || TSingleton<CFeatureManager>::GetInstance()->FUN_14036e5b0()) {
        return true;
    }
    for (size_t i = 0; i < m_aAllowedURLs.GetCount(); i++) {
        if (MatchURL(strUrl, m_aAllowedURLs[i])) {
            return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x141B78090, CWebBrowserService, IsAllowedURL, 161, 0xDE217A88);

// @0x141b78140
bool CWebBrowserService::MatchURL(const CStringA& strUrl, ATL::CAtlRegExp<>* pRegExp)
{
    if (pRegExp == NULL) {
        return false;
    }
    ATL::CAtlREMatchContext<> context;
    return pRegExp->Match(strUrl, &context) == TRUE;
}
MS2_REPLACE(0x141B78140, CWebBrowserService::MatchURL, 150, 0xB64F4F8B);

// @0x141b781e0
void CWebBrowserService::FUN_141b781e0(int nIndex, const char* pszUrl, const char* pszUnk, int nUnk)
{
    if (!IsValidIndex(nIndex)) {
        return;
    }
    CStringA strUrl(g_strMaviewURL);
    if (pszUrl != NULL) {
        strUrl = pszUrl;
    } else if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x5c) == true) {
        if (strUrl.IsEmpty() == true) {
            // empty in the exe
        }
    }
    CefRefPtr<COffscreenWebBrowser> browser(FindBrowser(nIndex));
    if (browser.get() == NULL) {
        CefWindowInfo windowInfo;
        CefBrowserSettings settings;
        windowInfo.SetAsWindowless(NULL);
        settings.background_color = 0xffffffff;
        browser = new COffscreenWebBrowser();
        browser->FUN_1416124e0(pszUnk, nUnk);
        // the client goes through operator COffscreenWebBrowser*() (0x141b81550) and CefRefPtr<CefClient>(T*)
        CefBrowserHost::CreateBrowser(windowInfo, (COffscreenWebBrowser*)browser, (const char*)strUrl, settings, NULL);
        CefRefPtr<CefBrowser> cefBrowser = NULL;
        browser->FUN_1416119d0(cefBrowser);
        m_aBrowsers[nIndex] = browser;
    } else {
        browser->FUN_1416124e0(pszUnk, nUnk);
        browser->FUN_141611c90(strUrl);
    }
    browser->FUN_141611be0(true);
}

// @0x141b784f0
void CWebBrowserService::FUN_141b784f0(int nIndex)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser) {
        pBrowser->FUN_141611b80();
        pBrowser->FUN_141611be0(false);
        s_app->FUN_140cc0150();
        pBrowser->FUN_141611a70();
        m_aBrowsers[nIndex] = NULL;
    }
}

// @0x141b78570
void CWebBrowserService::FUN_141b78570(CefRefPtr<CefV8Context> context, CefRefPtr<CefProcessMessage> message)
{
    Unk_WebBrowserMessage item = { FindBrowserIndex(context), message };
    if (Unk_LockGuard guard = m_messageLock) {
    } else {
        m_messages.push(item);
    }
}

// @0x141b78650
BOOL CWebBrowserService::FUN_141b78650()
{
    return s_app->FUN_140cc0130() ? TRUE : FALSE;
}

// @0x141b786a0
void* CWebBrowserService::FUN_141b786a0(int nIndex)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser == NULL) {
        return NULL;
    }
    return pBrowser->FUN_141612b20();
}
MS2_REPLACE_METHOD(0x141B786A0, CWebBrowserService, FUN_141b786a0, 59, 0xDFAC4E8D);

// @0x141b786f0
void CWebBrowserService::FUN_141b786f0(int nIndex, const char* pszUrl)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser == NULL) {
        return;
    }
    CStringA strUrl(pszUrl);
    pBrowser->FUN_141611c90(strUrl);
}
MS2_REPLACE_METHOD(0x141B786F0, CWebBrowserService, FUN_141b786f0, 105, 0x3FC9B551);

// @0x141b78760
void CWebBrowserService::FUN_141b78760(int nIndex, int nPage)
{
    if (nPage == 0) {
        CStringA strPath("");
        if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x5c) == true) {
            // empty in the exe (the feature test is all that is left)
        }
        FUN_141b786f0(nIndex, FUN_1401d2b10(g_strMaviewURL, strPath));
    } else {
        COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
        if (pBrowser == NULL) {
            return;
        }
        pBrowser->FUN_141611d50(nPage);
    }
}

// @0x141b78840
void CWebBrowserService::FUN_141b78840(int nIndex, bool bShow)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser == NULL) {
        return;
    }
    pBrowser->FUN_141611be0(bShow);
    s_app->FUN_140cbff60(bShow);
}

// @0x141b788b0
void CWebBrowserService::FUN_141b788b0(int nIndex, int nWidth, int nHeight)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser == NULL) {
        return;
    }
    pBrowser->FUN_1416123d0(nWidth, nHeight);
}
MS2_REPLACE_METHOD(0x141B788B0, CWebBrowserService, FUN_141b788b0, 76, 0x1560CF1E);

// @0x141b78910
bool CWebBrowserService::FUN_141b78910(int nIndex, unsigned nMsg, WPARAM wParam, LPARAM lParam, int x, int y)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser == NULL) {
        return false;
    }
    if (nMsg >= WM_MOUSEFIRST && nMsg <= WM_XBUTTONDBLCLK) {  // WM_MOUSELAST before Vista
        pBrowser->FUN_141611ea0(x, y, nMsg, wParam, lParam);
        return false;
    } else if (nMsg >= WM_KEYFIRST && nMsg <= WM_KEYLAST) {
        pBrowser->FUN_141612210(nMsg, wParam, lParam);
        return false;
    }
    return false;
}
MS2_REPLACE_METHOD(0x141B78910, CWebBrowserService, FUN_141b78910, 180, 0xE99C5FE4);

// @0x141b789d0
void CWebBrowserService::FUN_141b789d0(int nIndex)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser == NULL) {
        return;
    }
    pBrowser->FUN_1416126f0();
}
MS2_REPLACE_METHOD(0x141B789D0, CWebBrowserService, FUN_141b789d0, 57, 0x8949FDB8);

// @0x141b78a10
void CWebBrowserService::FUN_141b78a10(int nIndex)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser == NULL) {
        return;
    }
    pBrowser->FUN_1416129c0();
}
MS2_REPLACE_METHOD(0x141B78A10, CWebBrowserService, FUN_141b78a10, 57, 0x0CD22AEF);

// @0x141b78a50
bool CWebBrowserService::FUN_141b78a50(int nIndex)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser == NULL) {
        return true;
    }
    return pBrowser->FUN_1416129e0();
}
MS2_REPLACE_METHOD(0x141B78A50, CWebBrowserService, FUN_141b78a50, 59, 0x317860A6);

// @0x141b78aa0
void CWebBrowserService::FUN_141b78aa0(int nIndex, bool bUnk)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser) {
        pBrowser->SetKeyboard(bUnk);
    }
}
MS2_REPLACE_METHOD(0x141B78AA0, CWebBrowserService, FUN_141b78aa0, 65, 0x8AADAA9C);

// @0x141b78af0
void CWebBrowserService::FUN_141b78af0(int nIndex, int nUnk)
{
    COffscreenWebBrowser* pBrowser = FindBrowser(nIndex);
    if (pBrowser) {
        pBrowser->SetWindowType(nUnk);
    }
}
MS2_REPLACE_METHOD(0x141B78AF0, CWebBrowserService, FUN_141b78af0, 64, 0x90148246);

// @0x141b78b40
void CWebBrowserService::FUN_141b78b40(bool bUnk, int nUnk)
{
    COutPacket packet(static_cast<int>(SendOp::NewsNotification), 0);
    packet.vfunc_o10_1(0);
    packet.vfunc_o10_1(bUnk ? 1 : 0);
    packet.vfunc_o10_3(nUnk);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141B78B40, CWebBrowserService, FUN_141b78b40, 146, 0xF1A79B50);

// @0x141b78be0
void CWebBrowserService::FUN_141b78be0(CefRefPtr<CefV8Context> context, CefRefPtr<CefV8Value> callback)
{
    if (Unk_LockGuard guard = m_tokenLock) {
    } else {
        m_tokenContext = context;
        m_tokenCallback = callback;
        COutPacket packet(static_cast<int>(SendOp::NewsNotification), 0);
        packet.vfunc_o10_1(0);
        packet.vfunc_o10_1(0);
        packet.vfunc_o10_1(0);
        FUN_140710590(packet);
    }
}

// @0x141b78cf0
void CWebBrowserService::FUN_141b78cf0(int nIndex, const CStringA& strToken)
{
    if (m_tokenContext.get() == NULL || m_tokenCallback.get() == NULL) {
        return;
    }
    CefString token(strToken);
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageToken);
    CefRefPtr<CefListValue> args = message->GetArgumentList();
    args->SetString(0, token);
    m_aBrowsers[nIndex]->FUN_141611e20(message);
}
MS2_REPLACE_METHOD(0x141B78CF0, CWebBrowserService, FUN_141b78cf0, 372, 0x4E1DE1B4);

// @0x141b78e70
void CWebBrowserService::FUN_141b78e70(CefRefPtr<CefProcessMessage> message)
{
    if (Unk_LockGuard guard = m_tokenLock) {
    } else {
        if (m_tokenContext.get() == NULL || m_tokenCallback.get() == NULL) {
            return;
        }
        if (m_tokenContext->Enter()) {
            CefV8ValueList args;
            args.push_back(CefV8Value::CreateString(message->GetArgumentList()->GetString(0)));
            CefRefPtr<CefV8Value> retval = m_tokenCallback->ExecuteFunctionWithContext(m_tokenContext, NULL, args);
            m_tokenContext->Exit();
        }
        m_tokenCallback = NULL;
        m_tokenContext = NULL;
    }
}

// @0x141b79190
efd::SyncResult CWebBrowserService::OnPreInit(efd::IDependencyRegistrar*)
{
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD(0x141B79190, CWebBrowserService, OnPreInit, 16, 0x32804D89);

// @0x141b791b0
efd::AsyncResult CWebBrowserService::OnInit()
{
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x141B791B0, CWebBrowserService, OnInit, 11, 0x620C90F9);

// @0x141b791d0
efd::AsyncResult CWebBrowserService::OnTick()
{
    if (Unk_LockGuard guard = m_messageLock) {
    } else {
        while (!m_messages.empty()) {
            Unk_WebBrowserMessage item = m_messages.front();
            m_messages.pop();
            if (item.nIndex == -1) {
                for (int i = 0; i < kMaxBrowsers; i++) {
                    if (m_aBrowsers[i].get()) {
                        m_aBrowsers[i]->OnProcessMessageReceived(NULL, PID_BROWSER, item.message);
                    }
                }
            } else {
                m_aBrowsers[item.nIndex]->OnProcessMessageReceived(NULL, PID_BROWSER, item.message);
            }
        }
    }
    return efd::AsyncResult_Pending;
}

// @0x141b79420
efd::AsyncResult CWebBrowserService::OnShutdown()
{
    for (int i = 0; i < kMaxBrowsers; i++) {
        if (m_aBrowsers[i].get()) {
            m_aBrowsers[i]->FUN_141611a70();
            m_aBrowsers[i] = NULL;
        }
    }
    s_app = NULL;
    return efd::AsyncResult_Complete;
}

// @0x141b794c0
const char* CWebBrowserService::GetDisplayName() const
{
    return "WebBrowserService";
}
MS2_REPLACE_METHOD(0x141B794C0, CWebBrowserService, GetDisplayName, 13, 0xC1B115A6);

// @0x141b794e0
void CWebBrowserService::FUN_141b794e0(CStringA& strOut, const char* pszUrl)
{
    if (pszUrl != NULL) {
        int nPrefix = -1;
        if (strncmp(pszUrl, "maview:", 7) == 0) {
            strOut = g_strMaviewURL;
            nPrefix = 7;
        } else if (strncmp(pszUrl, "api:", 4) == 0) {
            strOut = g_strWebApiURL;
            nPrefix = 4;
        } else if (strncmp(pszUrl, "search:", 7) == 0) {
            strOut = FUN_14038f6d0(g_strMaviewURL, "/search?q=");
            nPrefix = 7;
        } else if (strncmp(pszUrl, "external:", 9) == 0) {
            strOut = "";
            nPrefix = 9;
        } else {
            strOut = pszUrl;
        }
        if (nPrefix == -1) {
            return;
        }
        char szRest[256];
        memset(szRest, 0, sizeof(szRest));
        strcpy_s(szRest, 200, pszUrl + nPrefix);
        strOut += szRest;
    }
}

// @0x141b796e0
COffscreenWebBrowser* CWebBrowserService::FindBrowser(int nIndex)
{
    if (!IsValidIndex(nIndex)) {
        return NULL;
    }
    return m_aBrowsers[nIndex].get();
}
MS2_REPLACE_METHOD(0x141B796E0, CWebBrowserService, FindBrowser, 66, 0xE5F0B11F);

// @0x141b79730
bool CWebBrowserService::IsValidIndex(int nIndex)
{
    return nIndex >= 0 && nIndex < kMaxBrowsers;
}
MS2_REPLACE_METHOD(0x141B79730, CWebBrowserService, IsValidIndex, 52, 0x1B2208E7);

// @0x141b79770
int CWebBrowserService::FindBrowserIndex(CefRefPtr<CefV8Context> context)
{
    if (context.get() == NULL) {
        return -1;
    }
    CefRefPtr<CefBrowser> browser = context->GetBrowser();
    for (int i = 0; i < kMaxBrowsers; i++) {
        if (m_aBrowsers[i].get() == NULL) {
            continue;
        }
        if (m_aBrowsers[i]->FUN_141612aa0().get() == browser.get()) {
            return i;
        }
    }
    return -1;
}

// MS2-PIN: ??_7CWebBrowserService@@6BISystemService@efd@@@ 0x142ff5410
// MS2-PIN: ??_7CWebBrowserService@@6B?$TSingleton@VCWebBrowserService@@@@@ 0x142ff5498
