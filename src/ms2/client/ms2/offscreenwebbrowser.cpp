// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COffscreenWebBrowser: one windowless CEF 3.3396 browser
// (CefClient + render/request/life-span/context-menu handlers) that paints into a 2048x1024 Gamebryo dynamic texture,
// forwards the game's mouse/keyboard input and handles the renderer's process messages (ime, open_ui, open_web,
// open_maview, move_home). Owned by CWebBrowserService (webbrowserservice.cpp). Layout: ms2/placeholder/coffscreenwebbrowser.h.
// Names other than the CEF overrides are invented (the exe has no symbols for them). Cross-checked with the v2525
// snapshot (src/ms2/tu/1416113e0.cpp there).
// MS2-UNIT: client\ms2\offscreenwebbrowser.cpp
// MS2-RANGE: 0x1416113e0-0x14161b8c0 .text$mn
// MS2-RANGE: 0x1400fa870-0x1400fa940 .text$di
// MS2-RANGE: 0x142cb3a40-0x142cb3a70 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$scoped_refptr@VCefDialogHandler@@@@QEAA@PEAVCefDialogHandler@@@Z 0x141617250 ; prop
// MS2-PIN: ??0?$scoped_refptr@VCefDisplayHandler@@@@QEAA@PEAVCefDisplayHandler@@@Z 0x1416172c0 ; prop
// MS2-PIN: ??0?$scoped_refptr@VCefDownloadHandler@@@@QEAA@PEAVCefDownloadHandler@@@Z 0x141617330 ; prop
// MS2-PIN: ??0?$scoped_refptr@VCefDragHandler@@@@QEAA@PEAVCefDragHandler@@@Z 0x1416173a0 ; prop
// MS2-PIN: ??0?$scoped_refptr@VCefFindHandler@@@@QEAA@PEAVCefFindHandler@@@Z 0x141617410 ; prop
// MS2-PIN: ??0?$scoped_refptr@VCefJSDialogHandler@@@@QEAA@PEAVCefJSDialogHandler@@@Z 0x1416174f0 ; prop
// MS2-PIN: ??0?$scoped_refptr@VCefKeyboardHandler@@@@QEAA@PEAVCefKeyboardHandler@@@Z 0x141617560 ; prop
// MS2-PIN: ?CanGetCookies@CefRequestHandler@@UEAA_NV?$scoped_refptr@VCefBrowser@@@@V?$scoped_refptr@VCefFrame@@@@V?$scoped_refptr@VCefRequest@@@@@Z 0x141619160 ; unique
// MS2-PIN: ?CanSetCookie@CefRequestHandler@@UEAA_NV?$scoped_refptr@VCefBrowser@@@@V?$scoped_refptr@VCefFrame@@@@V?$scoped_refptr@VCefRequest@@@@AEBV?$CefStructBase@UCefCookieTraits@@@@@Z 0x1416191b0 ; unique
// MS2-PIN: ?GetContextMenuHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefContextMenuHandler@@@@XZ 0x1416193a0 ; prop
// MS2-PIN: ?GetDialogHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefDialogHandler@@@@XZ 0x1416193e0 ; unique
// MS2-PIN: ?GetDisplayHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefDisplayHandler@@@@XZ 0x141619420 ; unique
// MS2-PIN: ?GetDownloadHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefDownloadHandler@@@@XZ 0x141619460 ; unique
// MS2-PIN: ?GetDragHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefDragHandler@@@@XZ 0x1416194a0 ; unique
// MS2-PIN: ?GetFindHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefFindHandler@@@@XZ 0x1416194e0 ; unique
// MS2-PIN: ?GetFocusHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefFocusHandler@@@@XZ 0x141619520 ; unique
// MS2-PIN: ?GetJSDialogHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefJSDialogHandler@@@@XZ 0x141619560 ; unique
// MS2-PIN: ?GetKeyboardHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefKeyboardHandler@@@@XZ 0x1416195a0 ; unique
// MS2-PIN: ?GetLifeSpanHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefLifeSpanHandler@@@@XZ 0x1416195e0 ; prop
// MS2-PIN: ?GetLoadHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefLoadHandler@@@@XZ 0x141619620 ; unique
// MS2-PIN: ?GetRenderHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefRenderHandler@@@@XZ 0x141619660 ; prop
// MS2-PIN: ?GetRequestHandler@CefClient@@UEAA?AV?$scoped_refptr@VCefRequestHandler@@@@XZ 0x1416196a0 ; prop
// MS2-PIN: ?GetRootScreenRect@CefRenderHandler@@UEAA_NV?$scoped_refptr@VCefBrowser@@@@AEAVCefRect@@@Z 0x1416197d0 ; prop
// MS2-PIN: ?GetScreenInfo@CefRenderHandler@@UEAA_NV?$scoped_refptr@VCefBrowser@@@@AEAVCefScreenInfo@@@Z 0x141619800 ; unique
// MS2-PIN: ?OnResourceLoadComplete@CefRequestHandler@@UEAAXV?$scoped_refptr@VCefBrowser@@@@V?$scoped_refptr@VCefFrame@@@@V?$scoped_refptr@VCefRequest@@@@V?$scoped_refptr@VCefResponse@@@@W4cef_urlrequest_status_t@@_J@Z 0x141619ea0 ; prop
// MS2-PIN: ?OnResourceRedirect@CefRequestHandler@@UEAAXV?$scoped_refptr@VCefBrowser@@@@V?$scoped_refptr@VCefFrame@@@@V?$scoped_refptr@VCefRequest@@@@V?$scoped_refptr@VCefResponse@@@@AEAV?$CefStringBase@UCefStringTraitsUTF16@@@@@Z 0x141619ef0 ; unique
// MS2-PIN: ?UpdateDragCursor@CefRenderHandler@@UEAAXV?$scoped_refptr@VCefBrowser@@@@W4cef_drag_operations_mask_t@@@Z 0x14161a330 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\offscreenwebbrowser.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <imm.h>
#pragma comment(lib, "imm32.lib")
#include "ms2/placeholder/coffscreenwebbrowser.h"
#include "ms2/placeholder/cwebbrowserservice.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/uiattendgiftdialog.h"
#include "ms2/client/ms2/uimeratmarketdialog.h"
#include "ms2/client/ms2/uiwebbrowser.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The premium market sort names (a header static every includer of the market headers gets a copy of).
static CString s_premiumSortNames[8] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

// The CEF process message names (shared table, 0x1439f7ea8..; "token" is used by CWebBrowserService).
extern const char* g_szCefMessageImeRequest;    // 0x1439f7ea8 "ime_request"
extern const char* g_szCefMessageOpenUI;        // 0x1439f7eb8 "open_ui"
extern const char* g_szCefMessageOpenWeb;       // 0x1439f7ec0 "open_web"
extern const char* g_szCefMessageOpenMaview;    // 0x1439f7ec8 "open_maview"
extern const char* g_szCefMessageMoveHome;      // 0x1439f7ed0 "move_home"

extern __int64 DAT_143ab2820;                   // the own account id
extern __int64 DAT_143ab2828;                   // the own character id
extern int DAT_143ab0248;                       // the service region (0 Korea)
extern int DAT_1439f4840;                       // the default code page

void FUN_140657820();                           // invalid call of an empty Delegate (shared)
void* FUN_140aadf80();                          // the platform service
HWND FUN_14209c720(void* pPlatform);            // its main window
CWebBrowserService* FUN_140cc18a0();            // the web browser service
void FUN_1418fe1c0(const CStringA& strUrl);     // open an url in the external browser
CStringW FUN_1408767c0(const char* pszUtf8);    // UTF-8 -> wide
CStringA FUN_14016a600(const wchar_t* psz, int nCodePage);     // wide -> multi-byte
int FUN_1407181d0(const CStringA& str);                        // string -> number (returns a 16-bit value in eax)
int FUN_141349e30(const CStringA& strKind);     // banner link kind
UIAttendGiftDialog* FUN_140c053e0(int nUIClassID);             // the dialog of a class id (FindDTDialog<UIAttendGiftDialog>)
UIMeratMarketDialog* FUN_140bfed50(int nUIClassID);            // the dialog of a class id
UIWebBrowser* FUN_140c43790(int nUIClassID);    // the dialog of a class id

// UTF-8 -> multi-byte in the given code page (0: the game's). Header inline (COMDAT 0x14161a290).
inline CStringA Utf8ToMultiByte(const std::string& str, int nCodePage)
{
    int nCP = nCodePage == 0 ? DAT_1439f4840 : nCodePage;
    CStringW strWide = FUN_1408767c0(str.c_str());
    return FUN_14016a600(strWide, nCP);
}

// Delegate specializations of the two callback types (COMDATs in this unit's range).
template<> inline Delegate<void(const CStringA&)>::Delegate(const Delegate& o) {
    if(o.m_pImpl==0) m_pImpl=0;
    else m_pImpl=o.m_pImpl->vfunc_1();
}
template<> inline Delegate<void(const CStringA&)>::~Delegate() { if(m_pImpl) delete m_pImpl; }
template<> inline Delegate<void(const CStringA&)>& Delegate<void(const CStringA&)>::operator=(const Delegate& o) {
    if(this==&o) return *this;
    if(m_pImpl) delete m_pImpl;
    if(o.m_pImpl==0) m_pImpl=0;
    else m_pImpl=o.m_pImpl->vfunc_1();
    return *this;
}
template<> inline void Delegate<void(const CStringA&)>::Reset() {
    if(m_pImpl) {
        delete m_pImpl;
        m_pImpl=0;
    }
}
template<> inline bool Delegate<void(const CStringA&)>::is_valid() const { return m_pImpl != 0; }
template<> inline bool Delegate<void(const CStringA&)>::IsSet() const { return is_valid(); }
template<> inline void Delegate<void(const CStringA&)>::operator()(const CStringA& a1) const {
    if(m_pImpl==0) FUN_140657820();
    m_pImpl->vfunc_2(a1);
}
template<> inline Delegate<void(const std::string&)>::Delegate(const Delegate& o) {
    if(o.m_pImpl==0) m_pImpl=0;
    else m_pImpl=o.m_pImpl->vfunc_1();
}
template<> inline Delegate<void(const std::string&)>::~Delegate() { if(m_pImpl) delete m_pImpl; }
template<> inline Delegate<void(const std::string&)>& Delegate<void(const std::string&)>::operator=(const Delegate& o) {
    if(this==&o) return *this;
    if(m_pImpl) delete m_pImpl;
    if(o.m_pImpl==0) m_pImpl=0;
    else m_pImpl=o.m_pImpl->vfunc_1();
    return *this;
}
template<> inline void Delegate<void(const std::string&)>::Reset() {
    if(m_pImpl) {
        delete m_pImpl;
        m_pImpl=0;
    }
}
template<> inline bool Delegate<void(const std::string&)>::is_valid() const { return m_pImpl != 0; }
template<> inline bool Delegate<void(const std::string&)>::IsSet() const { return is_valid(); }
template<> inline void Delegate<void(const std::string&)>::operator()(const std::string& a1) const {
    if(m_pImpl==0) FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

void CopyBrowserPixels(unsigned char* pDest, int nDestWidth, int nDestHeight, const unsigned char* pSrc, int nSrcWidth,
    int nSrcHeight, int nSrcX, int nSrcY, int nWidth, int nHeight, int nDestX, int nDestY, unsigned nColor);

// @0x1416113e0
COffscreenWebBrowser::COffscreenWebBrowser()
    : m_pPixels(NULL), m_pPopupPixels(NULL), m_nPaintWidth(0), m_nPaintHeight(0), m_hIMC(NULL),
      m_eLastButton(MBT_MIDDLE), m_nClickCount(0), m_bClosed(true), m_nAccountId(0), m_nCharacterId(0),
      m_strCharacterName(L""), m_eJob((Unk_JobCode)1), m_nLevel(0), m_nGuildId(0), m_strGuildName(L""),
      m_strToken(L""), m_nWindowType(1), m_bPopupShow(false), m_bKeyboard(true)
{
    m_nViewWidth = 2048;
    m_nViewHeight = 1024;
}

// @0x141611770
COffscreenWebBrowser::~COffscreenWebBrowser()
{
    if (m_pPixels != NULL) {
        delete[] m_pPixels;
        m_pPixels = NULL;
    }
    if (m_pPopupPixels != NULL) {
        delete[] m_pPopupPixels;
        m_pPopupPixels = NULL;
    }
}

// @0x1416119d0
void COffscreenWebBrowser::FUN_1416119d0(const CefRefPtr<CefBrowser>& browser)
{
    m_browser = browser;
    m_pPixels = new unsigned char[0x800000];
    m_spTexture = NiDynamicTexture::Create(2048, 1024);
    m_bClosed = false;
    m_hIMC = ImmCreateContext();
}
MS2_REPLACE_METHOD(0x1416119D0, COffscreenWebBrowser, FUN_1416119d0, 141, 0);

// @0x141611a70
void COffscreenWebBrowser::FUN_141611a70()
{
    if (Unk_LockGuard guard = m_lock) {
    } else {
        m_spTexture = NULL;
    }
    if (m_browser.get() == NULL) {
        return;
    }
    ImmDestroyContext(m_hIMC);
    m_browser->GetHost()->CloseBrowser(true);
    m_hIMC = NULL;
}
MS2_REPLACE_METHOD(0x141611A70, COffscreenWebBrowser, FUN_141611a70, 255, 0);

// @0x141611b80
void COffscreenWebBrowser::FUN_141611b80()
{
    if (m_browser.get() == NULL) {
        return;
    }
    m_browser->StopLoad();
}
MS2_REPLACE_METHOD(0x141611B80, COffscreenWebBrowser, FUN_141611b80, 76, 0);

// @0x141611be0
void COffscreenWebBrowser::FUN_141611be0(bool bShow)
{
    if (m_browser.get() == NULL) {
        return;
    }
    m_browser->GetHost()->SendFocusEvent(bShow);
}
MS2_REPLACE_METHOD(0x141611BE0, COffscreenWebBrowser, FUN_141611be0, 158, 0);

// @0x141611c90
void COffscreenWebBrowser::FUN_141611c90(const CStringA& strUrl)
{
    if (m_browser.get() == NULL) {
        return;
    }
    CefRefPtr<CefFrame> frame = m_browser->GetMainFrame();
    frame->LoadURL((const char*)strUrl);
}
MS2_REPLACE_METHOD(0x141611C90, COffscreenWebBrowser, FUN_141611c90, 179, 0);

// @0x141611d50
void COffscreenWebBrowser::FUN_141611d50(int nCommand)
{
    if (m_browser.get() == NULL) {
        return;
    }
    switch (nCommand) {
    case 1:
        m_browser->GoForward();
        break;
    case 2:
        m_browser->GoBack();
        break;
    case 3:
        m_browser->Reload();
        break;
    }
}
MS2_REPLACE_METHOD(0x141611D50, COffscreenWebBrowser, FUN_141611d50, 194, 0);

// @0x141611e20
void COffscreenWebBrowser::FUN_141611e20(CefRefPtr<CefProcessMessage> message)
{
    m_browser->SendProcessMessage(PID_RENDERER, message);
}

// @0x141611ea0
void COffscreenWebBrowser::FUN_141611ea0(int x, int y, unsigned nMsg, WPARAM wParam, LPARAM lParam)
{
    if (m_browser.get() == NULL) {
        return;
    }
    CefMouseEvent event;
    event.x = x;
    event.y = y;
    event.modifiers = GetMouseModifiers(wParam);
    CefBrowserHost::MouseButtonType eButton = GetMouseButton(nMsg);
    CefRefPtr<CefBrowserHost> host = m_browser->GetHost();
    switch (nMsg) {
    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
        if (eButton == m_eLastButton) {
        } else {
            m_eLastButton = eButton;
            m_nClickCount = 1;
        }
        host->SendMouseClickEvent(event, eButton, false, m_nClickCount);
        return;
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        host->SendMouseClickEvent(event, eButton, true, m_nClickCount);
        return;
    case WM_MOUSEMOVE:
        host->SendMouseMoveEvent(event, false);
        return;
    case WM_MOUSEWHEEL: {
        int nDelta = GET_WHEEL_DELTA_WPARAM(wParam);
        host->SendMouseWheelEvent(event, IsKeyDown(VK_SHIFT) ? nDelta : 0, !IsKeyDown(VK_SHIFT) ? nDelta : 0);
        return;
    }
    }
}
MS2_REPLACE_METHOD(0x141611EA0, COffscreenWebBrowser, FUN_141611ea0, 814, 0);

// @0x141612210
void COffscreenWebBrowser::FUN_141612210(unsigned nMsg, WPARAM wParam, LPARAM lParam)
{
    if (m_browser.get() == NULL) {
        return;
    }
    if (!m_bKeyboard) {
        return;
    }
    CefKeyEvent event;
    event.windows_key_code = (int)wParam;
    event.native_key_code = (int)lParam;
    event.is_system_key = (nMsg == WM_SYSCHAR || nMsg == WM_SYSKEYDOWN || nMsg == WM_SYSKEYUP) ? 1 : 0;
    if (nMsg == WM_KEYDOWN || nMsg == WM_SYSKEYDOWN) {
        event.type = KEYEVENT_RAWKEYDOWN;
    } else if (nMsg == WM_KEYUP || nMsg == WM_SYSKEYUP) {
        event.type = KEYEVENT_KEYUP;
    } else {
        event.type = KEYEVENT_CHAR;
    }
    event.modifiers = GetKeyboardModifiers(wParam, lParam);
    CefRefPtr<CefBrowserHost> host = m_browser->GetHost();
    host->SendKeyEvent(event);
}
MS2_REPLACE_METHOD(0x141612210, COffscreenWebBrowser, FUN_141612210, 435, 0);

// @0x1416123d0
void COffscreenWebBrowser::FUN_1416123d0(int nWidth, int nHeight)
{
    m_nViewWidth = nWidth;
    m_nViewHeight = nHeight;
    if (m_nViewWidth > 2048) {
        m_nViewWidth = 2048;
    }
    if (m_nViewHeight > 1024) {
        m_nViewHeight = 1024;
    }
    if (m_browser.get() == NULL) {
        return;
    }
    m_browser->GetHost()->WasResized();
}
MS2_REPLACE_METHOD(0x1416123D0, COffscreenWebBrowser, FUN_1416123d0, 252, 0);

// @0x1416124e0
void COffscreenWebBrowser::FUN_1416124e0(const char* pszToken, int nWindowType)
{
    m_nAccountId = DAT_143ab2820;
    m_nCharacterId = DAT_143ab2828;
    m_strToken = pszToken;
    m_nWindowType = nWindowType;
    PC* pPlayer = (PC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != NULL) {
        m_strCharacterName = pPlayer->vfunc_77();
        m_eJob = (Unk_JobCode)pPlayer->FUN_141654700();
        m_nLevel = (unsigned short)pPlayer->vfunc_78();
        if (CGuildManager::GetInstance()->FUN_1413b6160() != 0) {
            m_nGuildId = CGuildManager::GetInstance()->FUN_1404ccbd0();
            m_strGuildName = pPlayer->FUN_141656be0();
        } else {
            m_nGuildId = 0;
            m_strGuildName = L"";
        }
    } else {
        m_strCharacterName = "";
        m_eJob = (Unk_JobCode)1;
        m_nLevel = 0;
        m_nGuildId = 0;
        m_strGuildName = L"";
    }
    m_strToken = pszToken;
}
MS2_REPLACE_METHOD(0x1416124E0, COffscreenWebBrowser, FUN_1416124e0, 520, 0);

// @0x1416126f0
void COffscreenWebBrowser::FUN_1416126f0()
{
    if (m_bClosed) {
        return;
    }
    if (Unk_LockGuard guard = m_lock) {
    } else {
        if (!m_bDirty) {
            return;
        }
        if (m_spTexture == NULL) {
            return;
        }
        int nPitch = 0;
        unsigned char* pDest = (unsigned char*)m_spTexture->Lock(nPitch);
        if (pDest == NULL) {
            return;
        }
        for (int y = 0; y < m_nPaintHeight; y++) {
            memcpy(pDest + y * nPitch, m_pPixels + y * m_nPaintWidth * 4, m_nPaintWidth << 2);
        }
        if (m_bPopupShow && m_pPopupPixels != NULL) {
            CopyBrowserPixels(pDest, nPitch / 4, 1024, m_pPopupPixels, m_rcPopup.width, m_rcPopup.height, 0, 0,
                m_rcPopup.width, m_rcPopup.height, m_rcPopup.x, m_rcPopup.y, 0xffffffff);
        }
        m_spTexture->UnLock();
        m_bDirty = false;
    }
}
MS2_REPLACE_METHOD(0x1416126F0, COffscreenWebBrowser, FUN_1416126f0, 711, 0);

// @0x1416129c0
void COffscreenWebBrowser::FUN_1416129c0()
{
    m_bClosed = true;
}
MS2_REPLACE_METHOD(0x1416129C0, COffscreenWebBrowser, FUN_1416129c0, 18, 0);

// @0x1416129e0
bool COffscreenWebBrowser::FUN_1416129e0()
{
    m_bClosed = false;
    m_bDirty = true;
    return true;
}
MS2_REPLACE_METHOD(0x1416129E0, COffscreenWebBrowser, FUN_1416129e0, 32, 0);

// @0x141612a10
CefRefPtr<CefBrowserHost> COffscreenWebBrowser::FUN_141612a10()
{
    if (m_browser.get() == NULL) {
        return NULL;
    }
    return m_browser->GetHost();
}

// @0x141612aa0
CefRefPtr<CefBrowser> COffscreenWebBrowser::FUN_141612aa0()
{
    if (m_browser.get() == NULL) {
        return NULL;
    }
    return m_browser;
}

// @0x141612b20
void* COffscreenWebBrowser::FUN_141612b20()
{
    return m_spTexture;
}
MS2_REPLACE_METHOD(0x141612B20, COffscreenWebBrowser, FUN_141612b20, 31, 0);

// @0x141612b50
void COffscreenWebBrowser::FUN_141612b50(Delegate<void(const CStringA&)> onNavigate)
{
    m_onNavigate = onNavigate;
}

// @0x141612ba0
void COffscreenWebBrowser::FUN_141612ba0()
{
    m_onNavigate.Reset();
}
MS2_REPLACE_METHOD(0x141612BA0, COffscreenWebBrowser, FUN_141612ba0, 33, 0);

// @0x141612bd0
void COffscreenWebBrowser::FUN_141612bd0(Delegate<void(const std::string&)> onUrlChanged)
{
    m_onUrlChanged = onUrlChanged;
}

// @0x141612c20
void COffscreenWebBrowser::FUN_141612c20()
{
    m_onUrlChanged.Reset();
}
MS2_REPLACE_METHOD(0x141612C20, COffscreenWebBrowser, FUN_141612c20, 33, 0);

// @0x141612c50
void COffscreenWebBrowser::FUN_141612c50(bool bKeyboard)
{
    m_bKeyboard = bKeyboard;
}
MS2_REPLACE_METHOD(0x141612C50, COffscreenWebBrowser, FUN_141612c50, 26, 0);

// @0x141612c70
void COffscreenWebBrowser::FUN_141612c70(int nWindowType)
{
    m_nWindowType = nWindowType;
}
MS2_REPLACE_METHOD(0x141612C70, COffscreenWebBrowser, FUN_141612c70, 25, 0);

// @0x141612c90
bool COffscreenWebBrowser::IsKeyDown(WPARAM wParam)
{
    return (GetKeyState((int)wParam) & 0x8000) != 0;
}
MS2_REPLACE(0x141612C90, COffscreenWebBrowser::IsKeyDown, 57, 0);

// @0x141612cd0
unsigned COffscreenWebBrowser::GetMouseModifiers(WPARAM wParam)
{
    unsigned nModifiers = 0;
    if (wParam & MK_CONTROL) {
        nModifiers |= EVENTFLAG_CONTROL_DOWN;
    }
    if (wParam & MK_SHIFT) {
        nModifiers |= EVENTFLAG_SHIFT_DOWN;
    }
    if (IsKeyDown(VK_MENU)) {
        nModifiers |= EVENTFLAG_ALT_DOWN;
    }
    if (wParam & MK_LBUTTON) {
        nModifiers |= EVENTFLAG_LEFT_MOUSE_BUTTON;
    }
    if (wParam & MK_MBUTTON) {
        nModifiers |= EVENTFLAG_MIDDLE_MOUSE_BUTTON;
    }
    if (wParam & MK_RBUTTON) {
        nModifiers |= EVENTFLAG_RIGHT_MOUSE_BUTTON;
    }
    if (GetKeyState(VK_NUMLOCK) & 1) {
        nModifiers |= EVENTFLAG_NUM_LOCK_ON;
    }
    if (GetKeyState(VK_CAPITAL) & 1) {
        nModifiers |= EVENTFLAG_CAPS_LOCK_ON;
    }
    return nModifiers;
}
MS2_REPLACE(0x141612CD0, COffscreenWebBrowser::GetMouseModifiers, 240, 0);

// @0x141612dd0
unsigned COffscreenWebBrowser::GetKeyboardModifiers(WPARAM wParam, LPARAM lParam)
{
    unsigned nModifiers = 0;
    if (IsKeyDown(VK_SHIFT)) {
        nModifiers |= EVENTFLAG_SHIFT_DOWN;
    }
    if (IsKeyDown(VK_CONTROL)) {
        nModifiers |= EVENTFLAG_CONTROL_DOWN;
    }
    if (IsKeyDown(VK_MENU)) {
        nModifiers |= EVENTFLAG_ALT_DOWN;
    }
    if (GetKeyState(VK_NUMLOCK) & 1) {
        nModifiers |= EVENTFLAG_NUM_LOCK_ON;
    }
    if (GetKeyState(VK_CAPITAL) & 1) {
        nModifiers |= EVENTFLAG_CAPS_LOCK_ON;
    }
    switch (wParam) {
    case VK_RETURN:
        if ((lParam >> 16) & KF_EXTENDED) {
            nModifiers |= EVENTFLAG_IS_KEY_PAD;
        }
        break;
    case VK_INSERT:
    case VK_DELETE:
    case VK_HOME:
    case VK_END:
    case VK_PRIOR:
    case VK_NEXT:
    case VK_UP:
    case VK_DOWN:
    case VK_LEFT:
    case VK_RIGHT:
        if (!((lParam >> 16) & KF_EXTENDED)) {
            nModifiers |= EVENTFLAG_IS_KEY_PAD;
        }
        break;
    case VK_NUMLOCK:
    case VK_NUMPAD0:
    case VK_NUMPAD1:
    case VK_NUMPAD2:
    case VK_NUMPAD3:
    case VK_NUMPAD4:
    case VK_NUMPAD5:
    case VK_NUMPAD6:
    case VK_NUMPAD7:
    case VK_NUMPAD8:
    case VK_NUMPAD9:
    case VK_DIVIDE:
    case VK_MULTIPLY:
    case VK_SUBTRACT:
    case VK_ADD:
    case VK_DECIMAL:
    case VK_CLEAR:
        nModifiers |= EVENTFLAG_IS_KEY_PAD;
        break;
    case VK_SHIFT:
        if (IsKeyDown(VK_LSHIFT)) {
            nModifiers |= EVENTFLAG_IS_LEFT;
        } else if (IsKeyDown(VK_RSHIFT)) {
            nModifiers |= EVENTFLAG_IS_RIGHT;
        }
        break;
    case VK_CONTROL:
        if (IsKeyDown(VK_LCONTROL)) {
            nModifiers |= EVENTFLAG_IS_LEFT;
        } else if (IsKeyDown(VK_RCONTROL)) {
            nModifiers |= EVENTFLAG_IS_RIGHT;
        }
        break;
    case VK_MENU:
        if (IsKeyDown(VK_LMENU)) {
            nModifiers |= EVENTFLAG_IS_LEFT;
        } else if (IsKeyDown(VK_RMENU)) {
            nModifiers |= EVENTFLAG_IS_RIGHT;
        }
        break;
    case VK_LWIN:
        nModifiers |= EVENTFLAG_IS_LEFT;
        break;
    case VK_RWIN:
        nModifiers |= EVENTFLAG_IS_RIGHT;
        break;
    }
    return nModifiers;
}
MS2_REPLACE(0x141612DD0, COffscreenWebBrowser::GetKeyboardModifiers, 553, 0);

// @0x1416130b0
CefBrowserHost::MouseButtonType COffscreenWebBrowser::GetMouseButton(unsigned nMsg)
{
    switch (nMsg) {
    case WM_LBUTTONDOWN:
        return MBT_LEFT;
    case WM_RBUTTONDOWN:
        return MBT_RIGHT;
    case WM_MBUTTONDOWN:
        return MBT_MIDDLE;
    case WM_LBUTTONUP:
        return MBT_LEFT;
    case WM_RBUTTONUP:
        return MBT_RIGHT;
    case WM_MBUTTONUP:
        return MBT_MIDDLE;
    }
    return MBT_MIDDLE;
}
MS2_REPLACE(0x1416130B0, COffscreenWebBrowser::GetMouseButton, 100, 0);

// @0x141613140
CefRefPtr<CefRenderHandler> COffscreenWebBrowser::GetRenderHandler()
{
    return this;
}

// @0x1416131b0
CefRefPtr<CefRequestHandler> COffscreenWebBrowser::GetRequestHandler()
{
    return this;
}

// @0x141613220
CefRefPtr<CefLifeSpanHandler> COffscreenWebBrowser::GetLifeSpanHandler()
{
    return this;
}

// @0x141613290
CefRefPtr<CefContextMenuHandler> COffscreenWebBrowser::GetContextMenuHandler()
{
    return this;
}

// @0x141613300
bool COffscreenWebBrowser::OnBeforeBrowse(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request, bool user_gesture, bool is_redirect)
{
    CStringA strUrl = Utf8ToMultiByte(request->GetURL().ToString(), 0);
    if (!FUN_140cc18a0()->IsAllowedURL(strUrl)) {
        FUN_1418fe1c0(strUrl);
        return true;
    }
    if (m_onNavigate.IsSet()) {
        m_onNavigate(strUrl);
    }
    return false;
}

// @0x1416134b0
void COffscreenWebBrowser::OnResourceLoadComplete(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request, CefRefPtr<CefResponse> response, URLRequestStatus status,
    int64 received_content_length)
{
    if (frame.get() == NULL) {
        return;
    }
    CefString strUrl = frame->GetURL();
    if (strUrl.empty() || strUrl.length() == 0) {
        return;
    }
    if (m_strLastUrl == strUrl) {
        return;
    }
    if (m_onUrlChanged.IsSet()) {
        m_onUrlChanged(strUrl.ToString());
    }
    m_strLastUrl = strUrl;
}

// @0x141613710
CefRequestHandler::ReturnValue COffscreenWebBrowser::OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request, CefRefPtr<CefRequestCallback> callback)
{
    if (DAT_143ab0248 == 0) {
        CefRequest::HeaderMap headers;
        request->GetHeaderMap(headers);
        headers.insert(std::make_pair("X-ms2-acc-sn", CefString(StringFormat(L"{0}", m_nAccountId))));
        headers.insert(std::make_pair("X-ms2-char-sn", CefString(StringFormat(L"{0}", m_nCharacterId))));
        headers.insert(std::make_pair("X-ms2-char-name", CefString(m_strCharacterName)));
        headers.insert(std::make_pair("X-ms2-char-job", CefString(StringFormat(L"{0}", m_eJob))));
        headers.insert(std::make_pair("X-ms2-char-level", CefString(StringFormat(L"{0}", m_nLevel))));
        headers.insert(std::make_pair("X-ms2-char-world", "1"));
        headers.insert(std::make_pair("X-ms2-guild-sn", CefString(StringFormat(L"{0}", m_nGuildId))));
        headers.insert(std::make_pair("X-ms2-guild-name", CefString(m_strGuildName)));
        headers.insert(std::make_pair("X-ms2-window-type", CefString(StringFormat(L"{0}", m_nWindowType))));
        if (!m_strToken.IsEmpty()) {
            headers.insert(std::make_pair("X-ms2-token", CefString(m_strToken)));
            m_strToken = L"";
        }
        request->SetHeaderMap(headers);
    }
    return RV_CONTINUE;
}

// @0x141613fd0
bool COffscreenWebBrowser::OnBeforePopup(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    const CefString& target_url, const CefString& target_frame_name,
    CefLifeSpanHandler::WindowOpenDisposition target_disposition, bool user_gesture,
    const CefPopupFeatures& popupFeatures, CefWindowInfo& windowInfo, CefRefPtr<CefClient>& client,
    CefBrowserSettings& settings, bool* no_javascript_access)
{
    CStringA strUrl = Utf8ToMultiByte(target_url.ToString(), 0);
    FUN_1418fe1c0(strUrl);
    return true;
}

// @0x1416140a0
bool COffscreenWebBrowser::GetRootScreenRect(CefRefPtr<CefBrowser> browser, CefRect& rect)
{
    rect = CefRect(0, 0, m_nViewWidth, m_nViewHeight);
    return true;
}

// @0x141614160
bool COffscreenWebBrowser::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect)
{
    rect = CefRect(0, 0, m_nViewWidth, m_nViewHeight);
    return true;
}

// @0x141614220
bool COffscreenWebBrowser::GetScreenPoint(CefRefPtr<CefBrowser> browser, int viewX, int viewY, int& screenX,
    int& screenY)
{
    screenX = viewX;
    screenY = viewY;
    return true;
}

// @0x141614270
void COffscreenWebBrowser::OnPopupShow(CefRefPtr<CefBrowser> browser, bool show)
{
    if (!show) {
        CefRect rcOld = m_rcPopup;
        m_rcPopup.Set(0, 0, 0, 0);
        m_browser->GetHost()->Invalidate(PET_VIEW);
    }
    m_bPopupShow = show;
}

// @0x1416143b0
void COffscreenWebBrowser::OnPopupSize(CefRefPtr<CefBrowser> browser, const CefRect& rect)
{
    m_rcPopup = rect;
}

// @0x141614400
void COffscreenWebBrowser::OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects,
    const void* buffer, int width, int height)
{
    if (m_bClosed) {
        return;
    }
    if (Unk_LockGuard guard = m_lock) {
    } else {
        if (type == PET_POPUP) {
            if (m_pPopupPixels == NULL) {
                m_pPopupPixels = new unsigned char[0x800000];
            }
            CopyBrowserPixels(m_pPopupPixels, m_rcPopup.width, m_rcPopup.height, (const unsigned char*)buffer, width,
                height, 0, 0, m_rcPopup.width, m_rcPopup.height, 0, 0, 0xff0000ff);
        } else {
            m_nPaintWidth = width;
            m_nPaintHeight = height;
            for (RectList::const_iterator it = dirtyRects.begin(); it != dirtyRects.end(); ++it) {
                const CefRect& rc = *it;
                CopyBrowserPixels(m_pPixels, m_nPaintWidth, m_nPaintHeight, (const unsigned char*)buffer, width,
                    height, rc.x, rc.y, rc.width, rc.height, rc.x, rc.y, 0xff00);
            }
        }
        m_bDirty = true;
    }
}

// @0x1416146c0
void COffscreenWebBrowser::vfunc_14(CefRefPtr<CefBrowser> browser, void* pUnk)
{
}

// MS2-FUNCTIONAL: CefString/CefRefPtr temporaries get different frame slots (3.4 KB, the same calls in the same order)
// @0x1416146f0
bool COffscreenWebBrowser::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process,
    CefRefPtr<CefProcessMessage> message)
{
    if (message->GetName() == g_szCefMessageImeRequest) {
        if (message->GetArgumentList()->GetBool(0)) {
            ImmAssociateContext(FUN_14209c720(FUN_140aadf80()), m_hIMC);
        } else {
            if (ImmGetContext(FUN_14209c720(FUN_140aadf80())) == m_hIMC) {
                ImmAssociateContext(FUN_14209c720(FUN_140aadf80()), NULL);
            }
        }
        return true;
    } else if (message->GetName() == g_szCefMessageOpenUI) {
        CefString strUI = message->GetArgumentList()->GetString(0);
        if (strUI == "cash") {
            CUIService::GetInstance()->OpenDialog((eUIClassID)0x4ebc);
        } else if (strUI == "merat") {
            CUIService::GetInstance()->OpenDialog((eUIClassID)0x4ec1);
            if (message->GetArgumentList()->GetSize() == 3) {
                CStringA strKind(message->GetArgumentList()->GetString(1).c_str());
                CStringA strTarget(message->GetArgumentList()->GetString(2).c_str());
                int nKind = FUN_141349e30(strKind);
                UIMeratMarketDialog* pDialog = FUN_140bfed50(0x4ec1);
                if (pDialog != NULL) {
                    pDialog->OpenBanner(nKind, strTarget);
                }
            }
        } else if (strUI == "attend") {
            CStringA strDay(message->GetArgumentList()->GetString(1).c_str());
            int nDay = FUN_1407181d0(strDay);
            UIAttendGiftDialog* pDialog = FUN_140c053e0(0x4eb8);
            if (pDialog != NULL) {
                if (nDay != 0) {
                    pDialog->FUN_14102d5c0(nDay);
                }
                if (pDialog->FUN_141924630() == 0) {
                    pDialog->FUN_141924680();
                }
            }
        }
    } else if (message->GetName() == g_szCefMessageOpenWeb) {
        std::string strUrl = message->GetArgumentList()->GetString(0).ToString();
        FUN_1418fe1c0(CStringA(strUrl.c_str()));
    } else if (message->GetName() == g_szCefMessageOpenMaview) {
        std::string strUrl = message->GetArgumentList()->GetString(0).ToString();
        UIWebBrowser* pBrowser = FUN_140c43790(0x4e6a);
        if (pBrowser != NULL) {
            pBrowser->FUN_14135ec00(CStringA(strUrl.c_str()), true);
        }
    } else if (message->GetName() == g_szCefMessageMoveHome) {
        __int64 nOwner = message->GetArgumentList()->GetInt(0);
        MyPC* pPlayer = (MyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
        if (pPlayer != NULL) {
            pPlayer->FUN_141529c80(0, 0, 0, nOwner, CStringW(L""));
        }
    }
    return false;
}

// @0x141615490
void COffscreenWebBrowser::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
    m_browser = browser;
}

// @0x1416154e0
void COffscreenWebBrowser::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model)
{
    model->Clear();
}

// @0x141615560
bool COffscreenWebBrowser::OnContextMenuCommand(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params, int command_id, EventFlags event_flags)
{
    return true;
}

// Copies a BGRA rectangle (nSrcX, nSrcY, nWidth x nHeight) of pSrc to (nDestX, nDestY) in pDest, clipped. nColor is
// unused (a debug tint).
// @0x1416155b0
void CopyBrowserPixels(unsigned char* pDest, int nDestWidth, int nDestHeight, const unsigned char* pSrc, int nSrcWidth,
    int nSrcHeight, int nSrcX, int nSrcY, int nWidth, int nHeight, int nDestX, int nDestY, unsigned nColor)
{
    int i;
    int x = nSrcX;
    int y = nSrcY;
    if (x < 0) {
        nDestX -= x;
        nWidth -= x;
        x = 0;
    }
    if (y < 0) {
        nDestY -= y;
        nHeight -= y;
        y = 0;
    }
    if (nDestX + nWidth > nDestWidth) {
        nWidth = nDestWidth - nDestX;
    }
    if (nDestY + nHeight > nDestHeight) {
        nHeight = nDestHeight - nDestY;
    }
    for (i = 0; i < nHeight; i++) {
        memcpy(pDest + ((i + nDestY) * nDestWidth + nDestX) * 4, pSrc + ((i + y) * nSrcWidth + x) * 4, nWidth << 2);
    }
}
MS2_REPLACE(0x1416155B0, CopyBrowserPixels, 365, 0);
// The CEF handler bases each have a primary vftable and one for the CefBaseRefCounted virtual base (offset 16); RTTI
// pairing can't tell them apart by size.
// MS2-PIN: ??_7CefClient@@6B0@@ 0x142f44e98
// MS2-PIN: ??_7CefClient@@6BCefBaseRefCounted@@@ 0x142f44f10
// MS2-PIN: ??_7CefRenderHandler@@6B0@@ 0x142f44d38
// MS2-PIN: ??_7CefRenderHandler@@6BCefBaseRefCounted@@@ 0x142f44db0
// MS2-PIN: ??_7CefRequestHandler@@6B0@@ 0x142f44dd8
// MS2-PIN: ??_7CefRequestHandler@@6BCefBaseRefCounted@@@ 0x142f44e70
// MS2-PIN: ??_7CefLifeSpanHandler@@6B0@@ 0x142f44ce8
// MS2-PIN: ??_7CefLifeSpanHandler@@6BCefBaseRefCounted@@@ 0x142f44d10
// MS2-PIN: ??_7CefContextMenuHandler@@6B0@@ 0x142f44c98
// MS2-PIN: ??_7CefContextMenuHandler@@6BCefBaseRefCounted@@@ 0x142f44cc0
// MS2-PIN: ??_7COffscreenWebBrowser@@6BCefBaseRefCounted@@@ 0x142f45118
