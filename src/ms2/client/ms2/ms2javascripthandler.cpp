// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMS2JavascriptHandler: the CefV8Handler behind the "ms2" / "ms2dl"
// javascript extension that CCefMS2ClientApp::OnWebKitInitialized registers in the browser render process (the web pages'
// native hooks: login user, token, current map, open ui / web, the ms2dl project commands). Names other than the CEF
// override are invented (the exe has no symbols for them); the process messages they send are consumed by
// COffscreenWebBrowser::OnProcessMessageReceived. Layout: ms2/placeholder/cms2javascripthandler.h.
// MS2-UNIT: client\ms2\ms2javascripthandler.cpp
// MS2-RANGE: 0x1400f8c00-0x1400f8d70 .text$di
// MS2-RANGE: 0x1414bc6c0-0x1414bfc40 .text$mn
// MS2-RANGE: 0x142cb2e80-0x142cb2f00 .text$yd
// MS2-PIN: ??_7CefV8Handler@@6B0@@ 0x142f20870
// MS2-PIN: ??_7CefV8Handler@@6BCefBaseRefCounted@@@ 0x142f20880
// MS2-PIN: ??_7CMS2JavascriptHandler@@6BCefBaseRefCounted@@@ 0x142f208b8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2javascripthandler.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cms2javascripthandler.h"
#include "ms2/placeholder/cwebbrowserservice.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern const char* g_szCefMessageOpenUI;                // 0x1439f7eb8 "open_ui"
extern const char* g_szCefMessageOpenWeb;               // 0x1439f7ec0 "open_web"
extern const char* g_szCefMessageOpenMaview;            // 0x1439f7ec8 "open_maview"
extern const char* g_szCefMessageMoveHome;              // 0x1439f7ed0 "move_home"
extern const char* g_szCefMessageDlProjectNew;          // 0x1439f7ed8 "dl_project_new"
extern const char* g_szCefMessageDlProjectOpen;         // 0x1439f7ee0 "dl_project_open"
extern const char* g_szCefMessageDlProjectRefresh;      // 0x1439f7ee8 "dl_project_refresh"
extern const char* g_szCefMessageDlProjectClose;        // 0x1439f7ef0 "dl_project_close"
extern const char* g_szCefMessageDlProjectUpload;       // 0x1439f7ef8 "dl_project_upload"
extern const char* g_szCefMessageDlProjectPlay;         // 0x1439f7f00 "dl_project_play"
extern const char* g_szCefMessageDlProjectReset;        // 0x1439f7f08 "dl_project_reset"
extern const char* g_szCefMessageDlDoAction;            // 0x1439f7f10 "dl_do_action"
extern const char* g_szCefMessageDlExecuteCommand;      // 0x1439f7f18 "dl_execute_command"

extern __int64 DAT_143ab2828;                           // the own account id
extern int DAT_143ab2830;                               // the own world id
extern ATL::CAtlArray<int> DAT_143ab3078;               // the visited field ids

class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    int FUN_141bd3060();
    static class WorldService* GetInstance();
};
class CGuildManager   // C3: member view for the former free stand-ins
{
public:
    int FUN_1413b6160();
};
class CGuildInfo   // C3: member view for the former free stand-ins
{
public:
    __int64 FUN_1404ccbd0();
};
int FUN_141654700(PCBase* pPC);                         // PC member: the job
CStringW& FUN_141656be0(PCBase* pPC);                   // PC member: the guild name
int FUN_140408410(const ATL::CAtlArray<int>& array, const int& nValue);     // index of nValue, -1 if absent
class CBigDataLogSystem;
template<> CBigDataLogSystem* TSingleton<CBigDataLogSystem>::GetInstance();
void FUN_140a1f970(void* pService, const CStringA& strKey, const CStringA& strValue);   // logs an event

// ---- dynamic initializers (.text$di) ----

// @0x1400f8c00
static CStringA s_astrEnum[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// @0x1400f8cc0
static CString s_skill("skill");

// @0x1400f8cf0
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
void FUN_142cb2ef0();                                   // the exe's atexit destructor of the map
void FUN_1402a9d70(void*, int, float, float, float, int);
// @0x1400f8d20
static char s_map[0x48];
struct Unk_MapInit {};
static Unk_MapInit s_initMap = (FUN_1402a9d70(&s_map, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142cb2ef0), Unk_MapInit());

void FUN_1402aa1d0(void* p);                                       // ~Unk_1402a9d70
// The exe's atexit destructor of s_map.
// MS2-FUNCTIONAL: our build tail-calls the destructor; the exe's compiler-made atexit thunk keeps a frame.
// @0x142cb2ef0
void FUN_142cb2ef0() { FUN_1402aa1d0(s_map); }
#endif

// @0x1414bc6c0
CMS2JavascriptHandler::CMS2JavascriptHandler()
{
}

// @0x1414bc7a0
CMS2JavascriptHandler::~CMS2JavascriptHandler()
{
}

// @0x1414bc820
bool CMS2JavascriptHandler::Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    if (name == "getCurrentMap")
        return GetCurrentMap(object, arguments, retval, exception);
    else if (name == "getLoginUser")
        return GetLoginUser(object, arguments, retval, exception);
    else if (name == "requestToken")
        return RequestToken(object, arguments, retval, exception);
    else if (name == "isInGame")
        return IsInGame(object, arguments, retval, exception);
    else if (name == "isVisitedField")
        return IsVisitedField(object, arguments, retval, exception);
    else if (name == "haveHome")
        return HaveHome(object, arguments, retval, exception);
    else if (name == "openUI")
        OpenUI(object, arguments, retval, exception);
    else if (name == "openWeb")
        OpenWeb(object, arguments, retval, exception);
    else if (name == "openMaview")
        OpenMaview(object, arguments, retval, exception);
    else if (name == "moveToHouse")
        MoveToHouse(object, arguments, retval, exception);
    else if (name == "logGuestbookWrite")
        LogGuestbookWrite(object, arguments, retval, exception);
    else if (name == "ms2dlProjectNew")
        ProjectNew();
    else if (name == "ms2dlProjectOpen")
        ProjectOpen();
    else if (name == "ms2dlProjectRefresh")
        ProjectRefresh();
    else if (name == "ms2dlProjectClose")
        ProjectClose();
    else if (name == "ms2dlProjectUpload")
        ProjectUpload();
    else if (name == "ms2dlProjectPlay")
        ProjectPlay();
    else if (name == "ms2dlProjectReset")
        ProjectReset();
    else if (name == "ms2dlExecuteCommand")
        ExecuteCommand(object, arguments, retval, exception);
    else if (name == "ms2dlDoAction")
        DoAction(object, arguments, retval, exception);
    return false;
}

// @0x1414bd3d0
bool CMS2JavascriptHandler::GetLoginUser(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    retval = CefV8Value::CreateObject(NULL, NULL);
    PCBase* pPC = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPC == NULL)
        return false;

    CStringA strAccount;
    strAccount.Format("%lld", DAT_143ab2828);
    CefString csAccount((const char*)strAccount);
    CefString csName(pPC->vfunc_77());
    retval->SetValue("sn", CefV8Value::CreateString(csAccount), V8_PROPERTY_ATTRIBUTE_READONLY);
    retval->SetValue("name", CefV8Value::CreateString(csName), V8_PROPERTY_ATTRIBUTE_READONLY);
    retval->SetValue("level", CefV8Value::CreateInt((unsigned short)pPC->vfunc_78()), V8_PROPERTY_ATTRIBUTE_READONLY);
    retval->SetValue("job", CefV8Value::CreateInt(FUN_141654700(pPC)), V8_PROPERTY_ATTRIBUTE_READONLY);
    retval->SetValue("world", CefV8Value::CreateInt(DAT_143ab2830), V8_PROPERTY_ATTRIBUTE_READONLY);
    if (((class CGuildManager*)(void*)(((void*)TSingleton<CGuildManager>::GetInstance())))->FUN_1413b6160() != 0) {
        CStringA strGuild;
        strGuild.Format("%lld", ((class CGuildInfo*)(void*)((char*)((void*)TSingleton<CGuildManager>::GetInstance()) + 8))->FUN_1404ccbd0());
        CefString csGuild((const char*)strGuild);
        CefString csGuildName((const wchar_t*)FUN_141656be0(pPC));
        retval->SetValue("guild_sn", CefV8Value::CreateString(csGuild), V8_PROPERTY_ATTRIBUTE_READONLY);
        retval->SetValue("guild_name", CefV8Value::CreateString(csGuildName), V8_PROPERTY_ATTRIBUTE_READONLY);
    }
    return true;
}

// @0x1414bda60
bool CMS2JavascriptHandler::RequestToken(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    CWebBrowserService::GetInstance()->FUN_141b78be0(CefV8Context::GetCurrentContext(), arguments[0]);
    return true;
}

// @0x1414bdb20
bool CMS2JavascriptHandler::GetCurrentMap(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    if (((void*)WorldService::GetInstance()) == NULL)
        return true;

    CStringA strMap;
    strMap.Format("%08d", ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd3060());
    {
        CefString csMap((const char*)strMap);
        retval = CefV8Value::CreateString(csMap);
    }
    return true;
}

// @0x1414bdc30
bool CMS2JavascriptHandler::IsInGame(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    retval = CefV8Value::CreateBool(true);
    return true;
}

// @0x1414bdcb0
bool CMS2JavascriptHandler::IsVisitedField(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    CefRefPtr<CefV8Value> field = arguments[0];
    CefString csField = field->GetStringValue();
    int nField = (int)_wtoi64(csField.c_str());
    bool bVisited = (FUN_140408410(DAT_143ab3078, nField) >= 0) ? 1 : 0;
    retval = CefV8Value::CreateBool(bVisited);
    return true;
}

// @0x1414bdde0
bool CMS2JavascriptHandler::HaveHome(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    bool bHome = false;
    MyPC* pPC = static_cast<MyPC*>(((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0()));
    if (pPC != NULL)
        bHome = pPC->FUN_141527e00() == 0;
    retval = CefV8Value::CreateBool(bHome);
    return true;
}

// @0x1414bdea0
bool CMS2JavascriptHandler::OpenUI(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    if (arguments.size() < 1)
        return false;

    CefRefPtr<CefV8Value> ui = arguments[0];
    CefString csUI = ui->GetStringValue();
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageOpenUI);
    if (!message.get())
        return false;

    message->GetArgumentList()->SetString(0, csUI);
    if (arguments.size() == 3) {
        CefRefPtr<CefV8Value> action = arguments[1];
        CefString csAction = action->GetStringValue();
        CefRefPtr<CefV8Value> param = arguments[2];
        CefString csParam = param->GetStringValue();
        message->GetArgumentList()->SetString(1, csAction);
        message->GetArgumentList()->SetString(2, csParam);
    }
    SendMessage(message);
    return true;
}

// @0x1414be2c0
bool CMS2JavascriptHandler::OpenWeb(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    if (arguments.size() < 1)
        return false;

    CefRefPtr<CefV8Value> url = arguments[0];
    CefString csUrl = url->GetStringValue();
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageOpenWeb);
    if (!message.get())
        return false;

    message->GetArgumentList()->SetString(0, csUrl);
    SendMessage(message);
    return true;
}

// @0x1414be4c0
bool CMS2JavascriptHandler::OpenMaview(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    if (arguments.size() < 1)
        return false;

    CefRefPtr<CefV8Value> url = arguments[0];
    CefString csUrl = url->GetStringValue();
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageOpenMaview);
    if (!message.get())
        return false;

    message->GetArgumentList()->SetString(0, csUrl);
    SendMessage(message);
    return true;
}

// @0x1414be6c0
bool CMS2JavascriptHandler::MoveToHouse(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    if (arguments.size() < 1)
        return false;

    CefRefPtr<CefV8Value> accSn = arguments[0];
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageMoveHome);
    if (!message.get())
        return false;

    message->GetArgumentList()->SetInt(0, accSn->GetIntValue());
    SendMessage(message);
    return true;
}

// @0x1414be8b0
bool CMS2JavascriptHandler::LogGuestbookWrite(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    if (TSingleton<CBigDataLogSystem>::GetInstance() != NULL) {
        CStringA strValue("");
        CStringA strKey("guestbook_write");
        FUN_140a1f970(TSingleton<CBigDataLogSystem>::GetInstance(), strKey, strValue);
    }
    return true;
}

// @0x1414be950
bool CMS2JavascriptHandler::ProjectNew()
{
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlProjectNew);
    if (!message.get())
        return false;

    SendMessage(message);
    return true;
}

// @0x1414bea10
bool CMS2JavascriptHandler::ProjectOpen()
{
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlProjectOpen);
    if (!message.get())
        return false;

    SendMessage(message);
    return true;
}

// @0x1414bead0
bool CMS2JavascriptHandler::ProjectRefresh()
{
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlProjectRefresh);
    if (!message.get())
        return false;

    SendMessage(message);
    return true;
}

// @0x1414beb90
bool CMS2JavascriptHandler::ProjectClose()
{
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlProjectClose);
    if (!message.get())
        return false;

    SendMessage(message);
    return true;
}

// @0x1414bec50
bool CMS2JavascriptHandler::ProjectUpload()
{
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlProjectUpload);
    if (!message.get())
        return false;

    SendMessage(message);
    return true;
}

// @0x1414bed10
bool CMS2JavascriptHandler::ProjectPlay()
{
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlProjectPlay);
    if (!message.get())
        return false;

    SendMessage(message);
    return true;
}

// @0x1414bedd0
bool CMS2JavascriptHandler::ProjectReset()
{
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlProjectReset);
    if (!message.get())
        return false;

    SendMessage(message);
    return true;
}

// @0x1414bee90
bool CMS2JavascriptHandler::ExecuteCommand(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    if (arguments.size() < 1)
        return false;

    CefRefPtr<CefV8Value> command = arguments[0];
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlExecuteCommand);
    if (!message.get())
        return false;

    message->GetArgumentList()->SetString(0, command->GetStringValue());
    SendMessage(message);
    return true;
}

// @0x1414bf0a0
bool CMS2JavascriptHandler::DoAction(CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(g_szCefMessageDlDoAction);
    if (!message.get())
        return false;

    for (size_t i = 0; i < arguments.size(); i++) {
        CefRefPtr<CefV8Value> arg = arguments[i];
        message->GetArgumentList()->SetString(i, arg->GetStringValue());
    }
    SendMessage(message);
    return true;
}

// @0x1414bf2c0
bool CMS2JavascriptHandler::SendMessage(CefRefPtr<CefProcessMessage> message)
{
    CWebBrowserService::GetInstance()->FUN_141b78570(CefV8Context::GetCurrentContext(), message);
    return true;
}
