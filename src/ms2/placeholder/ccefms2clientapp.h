// ccefms2clientapp.h - PLACEHOLDER for CCefMS2ClientApp (RTTI .?AVCCefMS2ClientApp@@, 0x48 bytes: `new` in
// CWebBrowserService 0x141b77c4b). NOT an original header. Bases (RTTI): CefApp +0, CefBrowserProcessHandler +0x10,
// CefRenderProcessHandler +0x20, each with the virtual base CefBaseRefCounted. The game's CEF application object
// (?\cefms2clientapp.cpp, 0x140cbfd50-0x140cc20a0, not recovered); only what other units call is declared.
#pragma once

#include "ms2/cef/cef.h"
#include "ms2/ms2layout.h"

class CCefMS2ClientApp : public CefApp, public CefBrowserProcessHandler, public CefRenderProcessHandler
{
public:
    CCefMS2ClientApp();                             // 0x140cbfd50 (edx = 1: the virtual-base "most derived" flag)

    // CefBaseRefCounted (IMPLEMENT_REFCOUNTING in the exe class; defined in its unit)
    void AddRef() const override;
    bool Release() const override;
    bool HasOneRef() const override;

    void FUN_140cbff60(bool bUnk);                  // CWebBrowserService::FUN_141b78840 forwards a browser's flag
    bool FUN_140cc0130();                           // CWebBrowserService::FUN_141b78650
    void FUN_140cc0150();                           // CWebBrowserService::FUN_141b784f0 (before closing a browser)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_30[0x8];                             // + the vtordisp slot cl adds before the virtual base
};
MS2_CHECK_SIZE(CCefMS2ClientApp, 0x48);
