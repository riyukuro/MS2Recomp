// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCefMS2ClientApp: the game's CEF application object (CefApp +
// browser / render process handler): the command line switches of the browser process, the ms2 / ms2dl javascript extension
// registered in the render process, and the ime / token process messages between the two. Names other than the CEF
// overrides are invented (the exe has no symbols for them). Layout: ms2/placeholder/ccefms2clientapp.h.
// MS2-UNIT: lib_cef_clientapp
// MS2-RANGE: 0x140cbfd50-0x140cc20a0 .text$mn
// MS2-PIN: ??_7CefBrowserProcessHandler@@6B0@@ 0x142e1afc0
// MS2-PIN: ??_7CefRenderProcessHandler@@6B0@@ 0x142e1b018
// MS2-PIN: ??_7CefApp@@6B0@@ 0x142e1b098
// MS2-PIN: ??_7CefBrowserProcessHandler@@6BCefBaseRefCounted@@@ 0x142e1aff0
// MS2-PIN: ??_7CefRenderProcessHandler@@6BCefBaseRefCounted@@@ 0x142e1b070
// MS2-PIN: ??_7CefApp@@6BCefBaseRefCounted@@@ 0x142e1b0c8
// MS2-PIN: ??_7CCefMS2ClientApp@@6BCefBaseRefCounted@@@ 0x142e1b1a8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cefms2clientapp.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ccefms2clientapp.h"
#include "ms2/placeholder/cms2javascripthandler.h"
#include "ms2/placeholder/cwebbrowserservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern const char* g_szCefMessageImeRequest;    // 0x1439f7ea8 "ime_request"
extern const char* g_szCefMessageToken;         // 0x1439f7eb0 "token"

// @0x140cbfd50
CCefMS2ClientApp::CCefMS2ClientApp()
    : m_bImeRequest(false)
{
}

// @0x140cbfea0
CCefMS2ClientApp::~CCefMS2ClientApp()
{
}

// @0x140cbff60
void CCefMS2ClientApp::FUN_140cbff60(bool bUnk)
{
    bool v = (bUnk && m_bEditableFocus) ? 1 : 0;
    FUN_140cbffc0(v);
}

// @0x140cbffc0
void CCefMS2ClientApp::FUN_140cbffc0(bool bImeRequest)
{
    if (m_bImeRequest != bImeRequest) {
        m_bImeRequest = bImeRequest;
        CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageImeRequest);
        message->GetArgumentList()->SetBool(0, bImeRequest);
        CWebBrowserService::GetInstance()->FUN_141b78570(NULL, message);
    }
}

// @0x140cc0130
bool CCefMS2ClientApp::FUN_140cc0130()
{
    return m_bImeRequest;
}

// @0x140cc0150
void CCefMS2ClientApp::FUN_140cc0150()
{
    FUN_140cbff60(false);
    m_bImeRequest = false;
    m_bEditableFocus = false;
}

// @0x140cc0190
void CCefMS2ClientApp::OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line)
{
    command_line->AppendSwitch("no-proxy-server");
    command_line->AppendSwitch("disable-smooth-scrolling");
    command_line->AppendSwitchWithValue("disable-features", "TouchpadAndWheelScrollLatching,AsyncWheelEvents,SurfaceSynchronization");
}

// @0x140cc02d0
void CCefMS2ClientApp::OnWebKitInitialized()
{
    std::string strCode = "var ms2 = {};var ms2dl = {};(function() {\tms2.isInGame = function(field)\t\t\t\t\t{ native function isInGame();\t\t\treturn isInGame(); };\tms2.getLoginUser = function(field)\t\t\t\t{ native function getLoginUser();\t\treturn getLoginUser(); };\tms2.getCurrentMap = function()\t\t\t\t\t{ native function getCurrentMap();\t\treturn getCurrentMap(); };\tms2.requestToken = function(callback)\t\t\t{ native function requestToken();\t\treturn requestToken( callback ); };\tms2.isVisitedField = function(field)\t\t\t{ native function isVisitedField();\t\treturn isVisitedField( field ); };\tms2.haveHome = function()\t\t\t\t\t\t{ native function haveHome();\t\t\treturn haveHome(); };\tms2.openUI = function(ui,action,param)\t\t\t{ native function openUI();\t\t\t\treturn openUI( ui, action, param ); };\tms2.openWeb = function(url)\t\t\t\t\t\t{ native function openWeb();\t\t\treturn openWeb( url ); };\tms2.openMaview = function(url)\t\t\t\t\t{ native function openMaview();\t\t\treturn openMaview( url ); };\tms2.moveToHouse = function(acc_sn)\t\t\t\t{ native function moveToHouse();\t\treturn moveToHouse( acc_sn ); };\tms2.logGuestbookWrite = function()\t\t\t\t{ native function logGuestbookWrite();\treturn logGuestbookWrite(); };\n\tms2dl.projectNew = function()\t\t\t\t\t{ native function ms2dlProjectNew();\treturn ms2dlProjectNew(); };\tms2dl.projectOpen = function()\t\t\t\t\t{ native function ms2dlProjectOpen();\treturn ms2dlProjectOpen(); };\tms2dl.projectRefresh = function()\t\t\t\t{ native function ms2dlProjectRefresh();return ms2dlProjectRefresh(); };\tms2dl.projectClose = function()\t\t\t\t\t{ native function ms2dlProjectClose();\treturn ms2dlProjectClose(); };\tms2dl.projectUpload = function()\t\t\t\t{ native function ms2dlProjectUpload();\treturn ms2dlProjectUpload(); };\tms2dl.projectPlay = function()\t\t\t\t\t{ native function ms2dlProjectPlay();\treturn ms2dlProjectPlay(); };\tms2dl.projectReset = function()\t\t\t\t\t{ native function ms2dlProjectReset();\treturn ms2dlProjectReset(); };\tms2dl.executeCommand = function(command)\t\t{ native function ms2dlExecuteCommand();return ms2dlExecuteCommand(command); };\tms2dl.doAction = function(command,arg1)\t\t\t{ native function ms2dlDoAction();\t\treturn ms2dlDoAction(command,arg1); };})();";
    CefRegisterExtension("ms2/jsi", strCode, new CMS2JavascriptHandler());
}

// @0x140cc03f0
void CCefMS2ClientApp::OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefDOMNode> node)
{
    bool bEditable = (node != NULL) && node->IsEditable();
    m_bEditableFocus = bEditable;
    FUN_140cbffc0(bEditable);
}

// @0x140cc04b0
bool CCefMS2ClientApp::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process,
    CefRefPtr<CefProcessMessage> message)
{
    if (message->GetName() == g_szCefMessageToken) {
        CWebBrowserService::GetInstance()->FUN_141b78e70(message);
        return true;
    }
    return false;
}

// @0x140cc1fb0
int FUN_140cc1fb0(int nKind)
{
    int nResult;
    switch (nKind) {
    case 1: case 2: nResult = 0x210; break;
    case 3: nResult = 0x211; break;
    case 4: case 5: nResult = 0xace; break;
    case 6: nResult = 0x213; break;
    case 8: nResult = 0x216; break;
    case 10: nResult = 0x215; break;
    case 16: nResult = 0x218; break;
    case 22: nResult = 0x224; break;
    default: nResult = 0x217; break;
    }
    return nResult;
}
