// cms2javascripthandler.h - PLACEHOLDER for CMS2JavascriptHandler (RTTI .?AVCMS2JavascriptHandler@@, 0x28 bytes: `new` in
// CCefMS2ClientApp::OnWebKitInitialized 0x140cc031b). NOT an original header. Base (RTTI): CefV8Handler +0 (with the
// virtual base CefBaseRefCounted at +0x20). The V8 handler of the ms2 / ms2dl javascript extension, recovered with
// ?\ms2javascripthandler.cpp (0x1414bc6c0-0x1414bfc40, src/ms2/client/ms2/). The per-function handlers' names are invented.
#pragma once

#include "ms2/cef/cef.h"
#include "ms2/ms2layout.h"

class CMS2JavascriptHandler : public CefV8Handler
{
public:
    CMS2JavascriptHandler();                        // 0x1414bc6c0 (edx = 1: the virtual-base "most derived" flag)
    virtual ~CMS2JavascriptHandler();               // 0x1414bc7a0

    bool Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
        CefRefPtr<CefV8Value>& retval, CefString& exception) override;      // 0x1414bc820

    IMPLEMENT_REFCOUNTING(CMS2JavascriptHandler);
private:
    bool GetLoginUser(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);       // 0x1414bd3d0
    bool RequestToken(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);       // 0x1414bda60
    bool GetCurrentMap(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);      // 0x1414bdb20
    bool IsInGame(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);           // 0x1414bdc30
    bool IsVisitedField(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);     // 0x1414bdcb0
    bool HaveHome(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);           // 0x1414bdde0
    bool OpenUI(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);             // 0x1414bdea0
    bool OpenWeb(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);            // 0x1414be2c0
    bool OpenMaview(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);        // 0x1414be4c0
    bool MoveToHouse(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);       // 0x1414be6c0
    bool LogGuestbookWrite(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception); // 0x1414be8b0
    bool ProjectNew();                              // 0x1414be950
    bool ProjectOpen();                             // 0x1414bea10
    bool ProjectRefresh();                          // 0x1414bead0
    bool ProjectClose();                            // 0x1414beb90
    bool ProjectUpload();                           // 0x1414bec50
    bool ProjectPlay();                             // 0x1414bed10
    bool ProjectReset();                            // 0x1414bedd0
    bool ExecuteCommand(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);    // 0x1414bee90
    bool DoAction(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception);          // 0x1414bf0a0
    bool SendMessage(CefRefPtr<CefProcessMessage> message);     // 0x1414bf2c0 queues the message for the browsers

    MS2_LAYOUT_FRIEND;
};
MS2_CHECK_SIZE(CMS2JavascriptHandler, 0x28);
