// coffscreenwebbrowser.h - PLACEHOLDER for COffscreenWebBrowser (RTTI .?AVCOffscreenWebBrowser@@, 0x178 bytes: `new`
// in CWebBrowserService 0x141b782f1). NOT an original header. Bases (RTTI): CefClient +0, CefRenderHandler +0x10,
// CefRequestHandler +0x20, CefLifeSpanHandler +0x30, CefContextMenuHandler +0x40, each with the virtual base
// CefBaseRefCounted (+0x170, vtordisp at +0x16c). One windowless (off-screen) CEF browser rendered into a Gamebryo
// dynamic texture; recovered with ?\offscreenwebbrowser.cpp (0x1416113e0-0x14161b8c0, src/ms2/client/ms2/).
// Layout: ctor 0x1416113e0 / dtor 0x141611770 (gap4, cross-checked with the v2525 snapshot). Member names are invented;
// the FUN_ method names are kept because CWebBrowserService (webbrowserservice.cpp) binds to them.
#pragma once

#include <afxstr.h>
#include <imm.h>
#include <string>
#include "ms2/cef/cef.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/jobtable.h"
#include <NiDynamicTexture.h>

class COffscreenWebBrowser : public CefClient, public CefRenderHandler, public CefRequestHandler,
    public CefLifeSpanHandler, public CefContextMenuHandler
{
public:
    COffscreenWebBrowser();                         // 0x1416113e0 (edx = 1: the virtual-base "most derived" flag)
    virtual ~COffscreenWebBrowser();                // 0x141611770

    void AttachBrowser(const CefRefPtr<CefBrowser>& browser);  // attach: after CefBrowserHost::CreateBrowser (with null)
    void Close();                           // close the browser
    void StopLoad();                           // stop loading
    void SetFocus(bool bShow);                 // focus / unfocus
    void LoadUrl(const CStringA& strUrl);     // load an url
    void Navigate(int nCommand);               // 1 forward, 2 back, 3 reload
    void SendRendererMessage(CefRefPtr<CefProcessMessage> message);  // send a process message to the renderer
    void OnMouseEvent(int x, int y, unsigned nMsg, WPARAM wParam, LPARAM lParam);    // mouse input
    void OnKeyEvent(unsigned nMsg, WPARAM wParam, LPARAM lParam);                  // keyboard input
    void SetViewSize(int nWidth, int nHeight);    // resize the view (clamped to the 2048x1024 texture)
    void SetLoginInfo(const char* pszToken, int nWindowType);  // the request headers: local player, guild, token
    void UpdateTexture();                           // copy the page into the texture
    void FUN_1416129c0();                           // stop painting
    bool Open();                           // resume painting
    CefRefPtr<CefBrowserHost> GetBrowserHost();      // the browser host
    CefRefPtr<CefBrowser> GetBrowser();          // the CEF browser
    void* GetTexture();                          // the texture the page is rendered into (NiDynamicTexture*)
    void SetOnNavigate(Delegate<void(const CStringA&)> onNavigate);
    void FUN_141612ba0();
    void SetOnUrlChanged(Delegate<void(const std::string&)> onUrlChanged);
    void FUN_141612c20();
    void SetKeyboard(bool bKeyboard);             // keyboard input on/off
    void SetWindowType(int nWindowType);

    static bool IsKeyDown(WPARAM wParam);           // 0x141612c90
    static unsigned GetMouseModifiers(WPARAM wParam);              // 0x141612cd0
    static unsigned GetKeyboardModifiers(WPARAM wParam, LPARAM lParam);  // 0x141612dd0
    static CefBrowserHost::MouseButtonType GetMouseButton(unsigned nMsg);  // 0x1416130b0

    // CefClient
    CefRefPtr<CefRenderHandler> GetRenderHandler() override;
    CefRefPtr<CefRequestHandler> GetRequestHandler() override;
    CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;
    CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() override;
    bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process,
        CefRefPtr<CefProcessMessage> message) override;
    virtual void vfunc_14(CefRefPtr<CefBrowser> browser, void* pUnk);  // CefClient slot 14 (game's own, empty)
    // CefRequestHandler
    bool OnBeforeBrowse(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request,
        bool user_gesture, bool is_redirect) override;
    void OnResourceLoadComplete(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request, CefRefPtr<CefResponse> response, URLRequestStatus status,
        int64 received_content_length) override;
    ReturnValue OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request, CefRefPtr<CefRequestCallback> callback) override;
    // CefLifeSpanHandler
    bool OnBeforePopup(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& target_url,
        const CefString& target_frame_name, CefLifeSpanHandler::WindowOpenDisposition target_disposition,
        bool user_gesture, const CefPopupFeatures& popupFeatures, CefWindowInfo& windowInfo,
        CefRefPtr<CefClient>& client, CefBrowserSettings& settings, bool* no_javascript_access) override;
    // CefRenderHandler
    bool GetRootScreenRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
    bool GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
    bool GetScreenPoint(CefRefPtr<CefBrowser> browser, int viewX, int viewY, int& screenX, int& screenY) override;
    void OnPopupShow(CefRefPtr<CefBrowser> browser, bool show) override;
    void OnPopupSize(CefRefPtr<CefBrowser> browser, const CefRect& rect) override;
    void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer,
        int width, int height) override;
    // CefLifeSpanHandler
    void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
    // CefContextMenuHandler
    void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
        CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model) override;
    bool OnContextMenuCommand(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
        CefRefPtr<CefContextMenuParams> params, int command_id, EventFlags event_flags) override;

    IMPLEMENT_REFCOUNTING(COffscreenWebBrowser);    // +0x50
private:
    MS2_LAYOUT_FRIEND;
    CefRefPtr<CefBrowser> m_browser;                // +0x58
    NiDynamicTexturePtr m_spTexture;                // +0x60 2048x1024
    unsigned char* m_pPixels;                       // +0x68 the view (BGRA, 2048x1024)
    unsigned char* m_pPopupPixels;                  // +0x70 the popup widget
    int m_nPaintWidth;                              // +0x78 last OnPaint view size
    int m_nPaintHeight;                             // +0x7c
    HIMC m_hIMC;                                    // +0x80
    CefBrowserHost::MouseButtonType m_eLastButton;  // +0x88 the last pressed button (click count)
    int m_nClickCount;                              // +0x8c
    int m_nViewWidth;                               // +0x90 GetViewRect
    int m_nViewHeight;                              // +0x94
    bool m_bClosed;                                 // +0x98 OnPaint ignored
    CLockCriticalSection m_lock;                    // +0xa0 the pixel buffers
    bool m_bDirty;                                  // +0xd0 pixels changed since the last texture copy
    unsigned __int64 m_nAccountId;                          // +0xd8 request headers (SetLoginInfo)
    unsigned __int64 m_nCharacterId;                        // +0xe0
    CStringW m_strCharacterName;                    // +0xe8
    Unk_JobCode m_eJob;                             // +0xf0
    int m_nLevel;                                   // +0xf4
    unsigned __int64 m_nGuildId;                            // +0xf8
    CStringW m_strGuildName;                        // +0x100
    CStringA m_strToken;                            // +0x108 sent once
    unsigned m_nWindowType;                         // +0x110
    bool m_bPopupShow;                              // +0x114
    CefRect m_rcPopup;                              // +0x118 (0x20: vptr, cef_rect_t, attached_to_)
    Delegate<void(const CStringA&)> m_onNavigate;   // +0x138 OnBeforeBrowse (allowed urls)
    bool m_bKeyboard;                               // +0x140
    Delegate<void(const std::string&)> m_onUrlChanged;  // +0x148 OnResourceLoadComplete
    CefString m_strLastUrl;                         // +0x150
};
MS2_CHECK_SIZE(COffscreenWebBrowser, 0x178);
