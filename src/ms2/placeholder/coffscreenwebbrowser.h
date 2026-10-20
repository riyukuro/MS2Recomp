// coffscreenwebbrowser.h - PLACEHOLDER for COffscreenWebBrowser (RTTI .?AVCOffscreenWebBrowser@@, 0x178 bytes: `new`
// in CWebBrowserService 0x141b782f1). NOT an original header. Bases (RTTI): CefClient +0, CefRenderHandler +0x10,
// CefRequestHandler +0x20, CefLifeSpanHandler +0x30, CefContextMenuHandler +0x40, each with the virtual base
// CefBaseRefCounted. One windowless (off-screen) CEF browser rendered into a texture (?\offscreenwebbrowser.cpp,
// 0x1416113e0-0x14161b8c0, not recovered). Only what other units call is declared; the FUN_ names are the exe's
// addresses, the comments say what the callers use them for.
#pragma once

#include <afxstr.h>
#include "ms2/cef/cef.h"
#include "ms2/ms2layout.h"

class COffscreenWebBrowser : public CefClient, public CefRenderHandler, public CefRequestHandler,
    public CefLifeSpanHandler, public CefContextMenuHandler
{
public:
    COffscreenWebBrowser();                         // 0x1416113e0 (edx = 1: the virtual-base "most derived" flag)

    // CefBaseRefCounted (IMPLEMENT_REFCOUNTING in the exe class; defined in its unit)
    void AddRef() const override;
    bool Release() const override;
    bool HasOneRef() const override;
    // CefRenderHandler (pure there; defined in its unit)
    bool GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
    void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer,
        int width, int height) override;

    void FUN_1416119d0(const CefRefPtr<CefBrowser>& browser);  // after CefBrowserHost::CreateBrowser (with null)
    void FUN_141611a70();                           // close the browser
    void FUN_141611b80();                           // before closing
    void FUN_141611be0(bool bShow);                 // show / hide
    void FUN_141611c90(const CStringA& strUrl);     // load an url
    void FUN_141611d50(int nUnk);
    void FUN_141611e20(CefRefPtr<CefProcessMessage> message);  // send a process message to the renderer
    bool FUN_141611ea0(int x, int y, unsigned nMsg, WPARAM wParam, LPARAM lParam);    // mouse input
    bool FUN_141612210(unsigned nMsg, WPARAM wParam, LPARAM lParam);                  // keyboard input
    void FUN_1416123d0(int nWidth, int nHeight);    // resize
    void FUN_1416124e0(const char* pszUnk, int nUnk);
    void FUN_1416126f0();
    void FUN_1416129c0();
    bool FUN_1416129e0();
    CefRefPtr<CefBrowser> FUN_141612aa0();          // the CEF browser
    void* FUN_141612b20();                          // the texture the page is rendered into
    void FUN_141612c50(bool bUnk);
    void FUN_141612c70(int nUnk);
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_50[0x118];                           // + the vtordisp slot cl adds before the virtual base
};
MS2_CHECK_SIZE(COffscreenWebBrowser, 0x178);
