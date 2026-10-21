// cwebbrowserservice.h - CWebBrowserService (RTTI .?AVCWebBrowserService@@, 0x120 bytes). NOT an original header (the
// class is recovered with client\ms2\webbrowserservice.cpp, which owns it). Bases: efd::ISystemService at +0,
// TSingleton<CWebBrowserService> at +0x18 (vftables 0x142ff5410 / 0x142ff5498). The in-game web browser efd system
// service (class id 0x06100018): it initialises CEF 3.3396 (CefInitialize with the game's CCefMS2ClientApp), owns up to
// 7 windowless COffscreenWebBrowser instances (the UI dialogs address them by index), filters the urls a page may open
// against a list of ATL Server regular expressions, and passes process messages between the CEF render process and
// the browsers. Member and method names are invented where the exe has none (the FUN_ names of the methods other
// units call are kept: their units bind them by those names).
#pragma once

// Storage class of webbrowserservice.cpp's s_app (the CCefMS2ClientApp, exe 0x143af7bd8). In the hook DLL it must be the
// exe's object: the hooked MS2::RegisterServices runs the DLL copy of FUN_141b77e10 -> InitializeCef, and a DLL-private
// s_app left the exe's null (null deref in FUN_141b78650 at the title screen, hk1 2026-10-20). The DLL declares it extern
// and progress/symbols-manual.tsv binds ?s_app@@3V?$scoped_refptr@VCCefMS2ClientApp@@@@A to 0x143af7bd8.
#ifdef MS2_HOOK_DLL
#define MS2_WBS_APP_STORAGE extern
#else
#define MS2_WBS_APP_STORAGE static
#endif

#include <efd/ISystemService.h>
#include <efd/ReferenceCounting.h>
#include <atlcoll.h>
#include <deque>
#include <queue>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/coffscreenwebbrowser.h"
#pragma warning(push)
#pragma warning(disable: 6385 6011 4127)
#include "ms2/atlserver/atlrx.h"
#pragma warning(pop)

// A process message queued for the browsers (FUN_141b78570 -> OnTick): the browser index (-1 = every browser) and the
// message. Initialised member-wise (aggregate), copied by the implicit copy ctor 0x141b7b090.
struct Unk_WebBrowserMessage
{
    int nIndex;
    CefRefPtr<CefProcessMessage> message;
};
MS2_CHECK_SIZE(Unk_WebBrowserMessage, 0x10);

class CWebBrowserService : public efd::ISystemService, public TSingleton<CWebBrowserService>
{
    // The exe's SetupClassInfo (0x141b800f0) chains to efd::IBase::SetupClassInfo, not ISystemService's.
    EE_DECLARE_CLASS1(CWebBrowserService, 0x06100018, efd::IBase);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    enum { kMaxBrowsers = 7 };

    explicit CWebBrowserService(HINSTANCE hInstance);               // 0x141b77810
    virtual ~CWebBrowserService();                                  // 0x141b77aa0
    efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar) override;
    efd::AsyncResult OnInit() override;
    efd::AsyncResult OnTick() override;
    efd::AsyncResult OnShutdown() override;
    const char* GetDisplayName() const override;

    static void InitializeCef(HINSTANCE hInstance);                 // 0x141b77c20 CefInitialize
    void FUN_141b77e10();                                           // initialises CEF unless it already runs
    static void FUN_141b77e50(const CStringA& strUrl);              // sets the maview (news page) url
    static void FUN_141b77e90(const CStringA& strUrl);              // sets the web api url
    static void FUN_141b77ed0(const CStringA& strUrls);             // adds space-separated allowed-url patterns
    bool AddAllowedURL(const CStringA& strPattern);                 // 0x141b77fa0
    bool IsAllowedURL(const CStringA& strUrl);                      // 0x141b78090
    static bool MatchURL(const CStringA& strUrl, ATL::CAtlRegExp<>* pRegExp);   // 0x141b78140
    void FUN_141b781e0(int nIndex, const char* pszUrl, const char* pszUnk, int nUnk); // creates / shows a browser
    void FUN_141b784f0(int nIndex);                                 // closes a browser
    void FUN_141b78570(CefRefPtr<CefV8Context> context, CefRefPtr<CefProcessMessage> message);  // queues a message
    BOOL FUN_141b78650();
    void* FUN_141b786a0(int nIndex);                                // the browser's texture
    void FUN_141b786f0(int nIndex, const char* pszUrl);             // navigates a browser
    void FUN_141b78760(int nIndex, int nPage);
    void FUN_141b78840(int nIndex, bool bShow);
    void FUN_141b788b0(int nIndex, int nWidth, int nHeight);
    bool FUN_141b78910(int nIndex, unsigned nMsg, WPARAM wParam, LPARAM lParam, int x, int y);    // input message
    void FUN_141b789d0(int nIndex);
    void FUN_141b78a10(int nIndex);
    bool FUN_141b78a50(int nIndex);
    void FUN_141b78aa0(int nIndex, bool bUnk);
    void FUN_141b78af0(int nIndex, int nUnk);
    void FUN_141b78b40(bool bUnk, int nUnk);                        // sends packet 0x63
    void FUN_141b78be0(CefRefPtr<CefV8Context> context, CefRefPtr<CefV8Value> callback);  // the token callback
    void FUN_141b78cf0(int nIndex, const CStringA& strToken);       // sends a "token" process message
    void FUN_141b78e70(CefRefPtr<CefProcessMessage> message);       // calls the token callback
    void FUN_141b794e0(CStringA& strOut, const char* pszUrl);       // expands the maview:/api:/search:/external: prefixes
    COffscreenWebBrowser* FindBrowser(int nIndex);                  // 0x141b796e0
    bool IsValidIndex(int nIndex);                                  // 0x141b79730
    int FindBrowserIndex(CefRefPtr<CefV8Context> context);          // 0x141b79770

private:
    MS2_LAYOUT_FRIEND;
    HINSTANCE m_hInstance;                                          // +0x28
    ATL::CAtlArray<ATL::CAtlRegExp<>*> m_aAllowedURLs;              // +0x30
    CefRefPtr<COffscreenWebBrowser> m_aBrowsers[kMaxBrowsers];      // +0x50
    std::queue<Unk_WebBrowserMessage> m_messages;                   // +0x88
    CLockCriticalSection m_messageLock;                             // +0xb0
    CefRefPtr<CefV8Context> m_tokenContext;                         // +0xe0
    CefRefPtr<CefV8Value> m_tokenCallback;                          // +0xe8
    CLockCriticalSection m_tokenLock;                               // +0xf0
};
MS2_CHECK_SIZE(CWebBrowserService, 0x120);
MS2_CHECK_OFFSET(CWebBrowserService, m_hInstance, 0x28);
MS2_CHECK_OFFSET(CWebBrowserService, m_aBrowsers, 0x50);
MS2_CHECK_OFFSET(CWebBrowserService, m_messages, 0x88);
MS2_CHECK_OFFSET(CWebBrowserService, m_tokenContext, 0xe0);
MS2_CHECK_OFFSET(CWebBrowserService, m_tokenLock, 0xf0);
