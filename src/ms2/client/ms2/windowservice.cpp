// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CWindowService: the game's Win32 window service (window creation,
// fullscreen/windowed switching, the window procedure).
// MS2-UNIT: ?\windowservice.cpp
// MS2-PIN: ??_7CWindowService@@6BWin32PlatformService@efd@@@ 0x142ff7eb8
// MS2-PIN: ??_7CWindowService@@6B?$TSingleton@VCWindowService@@@@@ 0x142ff7f50
// MS2-PIN: ??_7?$TSingleton@VCWindowService@@@@6B@ 0x142ff7ea8
// MS2-RANGE: 0x14011fe40-0x14011fff0 .text$di
// MS2-RANGE: 0x141b90cd0-0x141b93fd0 .text$mn
// MS2-RANGE: 0x142cc38a0-0x142cc3970 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\windowservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "windowservice.h"
#include <atlcomcli.h>
#include <NiDX9Renderer.h>
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asmousecursor.h"
#include "ms2/placeholder/cmainsystem.h"
#include "reconnectionmanagercli.h"
#include "networkservice.h"
#include "statemanager.h"
#include "scenestatemulti.h"
#include "uiservice.h"
#include "soundservice.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/crashmanagercli.h"
#include "bigdatalogsystem.h"
#include "ms2/placeholder/cgameoption.h"
#pragma comment(lib, "user32.lib")

// Statics of the unit's header (initialized in this order in .text$di).
static CStringW s_forceLogin = L"forcelogin";
static CStringW s_gameExit = L"gameexit";
static CString s_sortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static UICommon::CMyPCKeyInputController s_keyInput;

// Exe globals (invented names; progress/symbols-manual.tsv rows).
extern int g_bAppActive;                // 0x143af7d40: window is the active application
extern int DAT_143af7d44;               // nonzero while the window is being rebuilt (WM_ACTIVATE is ignored)
extern RECT g_rcWindow;                 // 0x143af7d48: last GetWindowRect of the game window
extern int g_143af7d58;                 // 0: show the window after a mode switch
extern int g_bDefaultWndProc;           // 0x143af7d5c: 1 = forward every message to DefWindowProc
extern int g_bPrintScreenPending;       // 0x143af80f8
extern int g_bHotkeyPrintScreen;        // 0x143af80fc: RegisterHotKey(-2) succeeded
extern int g_bHotkeyAltPrintScreen;     // 0x143af8100: RegisterHotKey(-1) succeeded
extern int g_143afa350;
extern int DAT_143ab2858;               // nonzero: the login dialog is the front end
extern char g_byteFlag1439faadc;
extern unsigned g_uTimerInterval;       // 0x1439fab0c: SetTimer(1000) period
extern const NiRTTI* const g_pRendererRTTI;     // placeholder, see FUN_14098d8d0 uses (NiDX9Renderer::ms_RTTI)

// Unit-local stand-ins and unrecovered callees (names invented from their use).
class Unk_MouseTarget {                 // UI object receiving the translated mouse messages (slot 13)
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(UINT, int, int, unsigned, unsigned, int);
};
class Unk_MessageHook {                 // message filter object behind 0x1414a56c0 (slot 18)
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual int vfunc_18(HWND, UINT, WPARAM, LPARAM);
};
class Unk_ComObj : public IUnknown {    // COM-style object queried from the game core (slot 16 is invoked on G)
public:
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
};
struct Unk_Holder {                     // sub-object at +8 of the game core, its member at +8 is the object queried below
    void* m_pad_00;
    void* m_pObj;
};
struct Unk_GameCore {
    void* m_pad_00;
    Unk_Holder m_holder;                // +8
};
struct Unk_Worker;
class Unk_WorkerPtr {                   // 16-byte intrusive handle (pointer at +8) of a worker thread object
public:
    Unk_WorkerPtr& operator=(int);      // 0x141b93c40: drops the held object
    operator struct Unk_Worker*() const;    // 0x141b93c70
    struct Unk_Worker* operator->() const;  // 0x141b93c90
    void FUN_140d4dc30();               // release
private:
    void* m_pad_00;
    struct Unk_Worker* m_p;
};
class Unk_MsgBoxPtr {                   // 16-byte handle of a message box (MS2Ptr<CMsgBoxData>)
public:
    ~Unk_MsgBoxPtr();                   // 0x140534d60
private:
    void* m_pad_00;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_MsgBoxPtr, 0x10);
class Unk_MsgCallback {                 // Delegate<bool(int, const CMsgBoxData&)> built from a plain function (8 bytes)
public:
    Unk_MsgCallback(const Unk_MsgCallback&);    // declared (as Delegate's): the by-value argument goes by reference to a caller temp
    ~Unk_MsgCallback();                 // 0x140534cb0
private:
    void* m_p;
};
class Unk_HudPtr {                      // handle returned by the UI manager lookup
public:
    ~Unk_HudPtr();                      // 0x140a58400
    void* FUN_140a58470();              // non-null test (operator T*)
    struct Unk_HudCursor* FUN_140a584a0();  // operator->
private:
    void* m_pad_00;
    void* m_pad_08;
};
class Unk_LoginDialog;
int FUN_141b938f0(int);
void FUN_141b93a20(unsigned);
void FUN_141b93aa0();
Unk_MessageHook* FUN_1414a56c0();

extern Unk_WorkerPtr g_workerPtr;       // 0x143ac2bd0
void FUN_140d4a600(Unk_Worker*);
void* FUN_14025e7a0();
float FUN_14028aed0(float f);                                       // floor(float)
struct Unk_WinMovieMgrView { Unk_HudPtr FUN_1422b0370(int nLayer); };   // member (this=rcx, hidden return=rdx)
struct Unk_HudCursor : public ASMouseCursor { };   // ASMouseCursor (0x1422cec40)
void FUN_14209cc20(void*, void*);
CStringW FUN_1408116a0(int, const int&);
CStringW GetStringCommon(unsigned);
CStringW FUN_1401d0080(const CStringW&, const CStringW&);
CStringW FUN_14052bd00(unsigned, const CStringW&);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_140d73bc0(int, int, void*, CStringW);
Unk_LoginDialog* FUN_141a003b0(int);
void FUN_1419e21e0(Unk_LoginDialog*, CStringW);
Unk_MsgBoxPtr FUN_140d74390(CStringW, int, Unk_MsgCallback);
Unk_MsgCallback FUN_140b76b10(bool (*)(int));
bool FUN_141902530(int);
CNetworkService* FUN_140714f90();
CReconnectionManagerCli* FUN_140e800e0();
void* FUN_140aadf80();
CSoundService* FUN_140c9cb10();
void* FUN_140c8dac0();
void FUN_140d0a510(void*);
void FUN_140d0a560(void*);
void* FUN_140af8310(Unk_Holder*);
Unk_ComObj* FUN_141296b50(void*);
void* FUN_1403ed2d0();
void FUN_141bc9fd0(void*, int);
void* FUN_140aae430();
int FUN_141489fb0(void*);
void FUN_141489f40(void*);
unsigned FUN_140869420();
__int64 FUN_141ade340(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK Unk_WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x141b90cd0
CWindowService::CWindowService(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
    : efd::Win32PlatformService(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
{
    SetWndProc(Unk_WindowProc);
    m_bMaximize = false;
}
#endif

// @0x141b90d90
CWindowService::~CWindowService()
{
}

// @0x141b90e00
void CWindowService::SetTitleText(const char* pszText)
{
    SetWindowTextA(m_hWnd, pszText);
}

// Client-area position of the mouse cursor; false while the application is inactive.
// @0x141b90e30
int CWindowService::GetCursorClientPos(float* pfX, float* pfY)
{
    if (g_bAppActive == 0)
        return 0;
    POINT pt;
    if (!GetCursorPos(&pt))
        return 0;
    if (!ScreenToClient(GetWindowRef(), &pt))
        return 0;
    *pfX = (float)pt.x;
    *pfY = (float)pt.y;
    return 1;
}

// @0x141b90ec0
void CWindowService::MoveCursor(int nDeltaX, int nDeltaY)
{
    POINT pt;
    if (g_bAppActive == 0)
        return;
    if (!GetCursorPos(&pt))
        return;
    SetCursorPos(pt.x + nDeltaX, pt.y + nDeltaY);
}

// Posts nMessage with the current cursor position (client coordinates, relative to the client rect) to the window.
// @0x141b90f20
void CWindowService::PostMouseMove(UINT nMessage)
{
    POINT pt;
    RECT rc;
    if (g_bAppActive == 0)
        return;
    if (!GetCursorPos(&pt))
        return;
    if (!ScreenToClient(GetWindowRef(), &pt))
        return;
    if (!GetClientRect(GetWindowRef(), &rc))
        return;
    int x = pt.x - rc.left;
    int y = pt.y - rc.top;
    PostMessageA(GetWindowRef(), nMessage, 0, (LPARAM)(x | (y << 16)));
}

// @0x141b91010
bool CWindowService::RecreateRenderer(bool bFullscreen, unsigned nWidth, unsigned nHeight)
{
    TSingleton<CrashManagerCli>::GetInstance()->FUN_1401ce2f0("\n *RecreateRenderer %d %d", nWidth, nHeight);
    NiDX9Renderer* pRenderer = (NiDX9Renderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, NiDX9Renderer::GetRenderer());
    unsigned nUseFlags, nCurWidth, nCurHeight;
    NiWindowRef hWndDevice, hWndFocus;
    unsigned nAdapter;
    NiDX9Renderer::DeviceDesc eDesc;
    NiDX9Renderer::FrameBufferFormat eFBFormat;
    NiDX9Renderer::DepthStencilFormat eDSFormat;
    NiDX9Renderer::PresentationInterval ePresentInterval;
    NiDX9Renderer::SwapEffect eSwapEffect;
    unsigned nFBMode, nBackBufferCount, nRefreshRate;
    pRenderer->GetCreationParameters(nCurWidth, nCurHeight, nUseFlags, hWndDevice, hWndFocus, nAdapter, eDesc, eFBFormat,
        eDSFormat, ePresentInterval, eSwapEffect, nFBMode, nBackBufferCount, nRefreshRate);
    nCurWidth = nWidth;
    nCurHeight = nHeight;
    if (bFullscreen && !m_bMaximize)
        nUseFlags |= 4;
    else
        nUseFlags &= ~4u;
    NiDX9Renderer::RecreateStatus eStatus = pRenderer->Recreate(nCurWidth, nCurHeight, nUseFlags, GetWindowRef(),
        eFBFormat, eDSFormat, ePresentInterval, eSwapEffect, nFBMode, nBackBufferCount, nRefreshRate);
    if (eStatus == NiDX9Renderer::RECREATESTATUS_FAILED)
        return false;
    OnRendererChanged(pRenderer->GetRenderState());
    if (m_bMaximize)
        bFullscreen = true;
    ApplyWindowMode(bFullscreen, nCurWidth, nCurHeight);
    return true;
}

// Switches the window between the bordered windowed mode (bFullscreen false) and the borderless full-screen mode.
// @0x141b91290
void CWindowService::ApplyWindowMode(bool bFullscreen, unsigned nWidth, unsigned nHeight)
{
    int nShowCmd = 1;
    if (g_143af7d58 != 0)
        nShowCmd = 0;
    if (bFullscreen)
    {
        NiRenderer* pRenderMgr = NiRenderer::GetRenderer();
        if (pRenderMgr != 0)
        {
            NiDX9Renderer* pRenderer = (NiDX9Renderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, pRenderMgr);
            if (pRenderer != 0)
                pRenderer->SetDisplayMode(nWidth, nHeight);
        }
        CWnd::FromHandle(m_hWnd)->SetMenu(0);
        CRect rcWindow(0, 0, nWidth, nHeight);
        if (!AdjustWindowRect((LPRECT)rcWindow, 0x80000000, 0))
        {
            DWORD nError = GetLastError();
            CString strError;
            strError.Format("!AdjustWindowRect() result [%d] %d %d - %d %d", nError, rcWindow.Width(), rcWindow.Height(),
                nWidth, nHeight);
            if (TSingleton<CBigDataLogSystem>::GetInstance() != 0)
                TSingleton<CBigDataLogSystem>::GetInstance()->SendLog("Error AdjustWindowRect", strError);
            rcWindow.SetRect(0, 0, nWidth, nHeight);
        }
        SetWindowLongA(GetWindowRef(), -16, 0x80000000);
        UINT nFlags = 2;
        HWND hWndInsertAfter = HWND_TOPMOST;
        if (m_bMaximize)
        {
            nFlags &= ~2;
            hWndInsertAfter = HWND_NOTOPMOST;
        }
        if (!SetWindowPos(GetWindowRef(), hWndInsertAfter, 0, 0, rcWindow.Width(), rcWindow.Height(), nFlags))
        {
            DWORD nError = GetLastError();
            CString strError;
            strError.Format("!SetWindowPos() result [%d] %d %d - %d %d topMost %d flag %d", nError, rcWindow.Width(),
                rcWindow.Height(), nWidth, nHeight, hWndInsertAfter, nFlags);
            if (TSingleton<CBigDataLogSystem>::GetInstance() != 0)
                TSingleton<CBigDataLogSystem>::GetInstance()->SendLog("Error SetWindowPos", strError);
        }
        ShowWindow(GetWindowRef(), nShowCmd);
    }
    else
    {
        NiRenderer* pRenderMgr = NiRenderer::GetRenderer();
        if (pRenderMgr != 0)
        {
            NiDX9Renderer* pRenderer = (NiDX9Renderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, pRenderMgr);
            if (pRenderer != 0)
                pRenderer->RestoreDisplayMode();
        }
        BOOL bHasMenu = m_menu.GetSafeHmenu() != 0;
        if (bHasMenu)
            CWnd::FromHandle(m_hWnd)->SetMenu(&m_menu);
        int nScreenW = GetSystemMetrics(0);
        int nScreenH = GetSystemMetrics(1);
        if (nScreenW < (int)nWidth)
            nWidth = nScreenW;
        if (nScreenH < (int)nHeight)
            nHeight = nScreenH;
        RECT rc;
        rc.left = 0;
        rc.top = 0;
        rc.right = nWidth;
        rc.bottom = nHeight;
        AdjustWindowRect(&rc, 0xca0000, bHasMenu);
        int nOuterW = rc.right - rc.left;
        int nOuterH = rc.bottom - rc.top;
        if (pRenderMgr != 0)
        {
            NiDX9Renderer* pRenderer = (NiDX9Renderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, pRenderMgr);
            if (pRenderer != 0)
                pRenderer->Recreate(nWidth, nHeight);
        }
        DWORD dwStyle = 0xca0000;
        ShowWindow(GetWindowRef(), 0);
        SetWindowLongA(GetWindowRef(), -16, dwStyle);
        SetWindowPos(GetWindowRef(), 0, 0, 0, nOuterW, nOuterH, 0x23);
        int nPosX = (int)(FUN_14028aed0((float)(nScreenW - nOuterW) * 0.5f) < 0.0f
                              ? 0.0f : FUN_14028aed0((float)(nScreenW - nOuterW) * 0.5f));
        int nPosY = (int)(FUN_14028aed0((float)(nScreenH - nOuterH) * 0.5f) < 0.0f
                              ? 0.0f : FUN_14028aed0((float)(nScreenH - nOuterH) * 0.5f));
        SetWindowPos(GetWindowRef(), HWND_NOTOPMOST, nPosX, nPosY, nOuterW, nOuterH, 0);
        ShowWindow(GetWindowRef(), nShowCmd);
    }
    GetWindowRect(m_hWnd, &g_rcWindow);
}

// Stops the worker thread held in g_workerPtr and drops it.
// @0x141b91a60
void FUN_141b91a60()
{
    if (g_workerPtr)
    {
        FUN_140d4a600(g_workerPtr.operator->());
        g_workerPtr = 0;
        g_143af7d58 = 0;
    }
}

// True when another desktop is in front (the secure desktop / screen saver is active).
// @0x141b91ab0
int FUN_141b91ab0()
{
    HDESK hDesktop = OpenDesktopA("Default", 0, 0, 0x100);
    if (hDesktop != 0)
    {
        BOOL bSwitched = SwitchDesktop(hDesktop);
        if (bSwitched == 0)
        {
            CloseDesktop(hDesktop);
            return 1;
        }
        else
        {
            CloseDesktop(hDesktop);
        }
    }
    return 0;
}

// @0x141b91b20
void FUN_141b91b20(bool bValue)
{
    g_byteFlag1439faadc = bValue;
    Unk_HudPtr hud = static_cast<Unk_WinMovieMgrView*>(FUN_14025e7a0())->FUN_1422b0370(6);
    if (hud.FUN_140a58470())
        hud.FUN_140a584a0()->FUN_1422cec40(bValue);
}

// @0x141b91ba0
void CWindowService::ShowGameWindow()
{
    FUN_141b91a60();
    if (m_bMaximize)
        ShowWindow(GetWindowRef(), 3);
    else
        ShowWindow(GetWindowRef(), 5);
    SetForegroundWindow(GetWindowRef());
    SetFocus(GetWindowRef());
}

// Window procedure of the game window.
// @0x141b91c30
LRESULT CALLBACK Unk_WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (g_bDefaultWndProc == 1)
        return DefWindowProcA(hWnd, uMsg, wParam, lParam);
    if (uMsg == 0x4c8)
    {
        if (TSingleton<CStateService>::GetInstance() != 0)
        {
            if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000d)
            {
                CSceneStateBase* pState = TSingleton<CStateService>::GetInstance()->GetCurrent();
                if (pState != 0)
                    static_cast<CSceneStateMulti*>(pState)->FUN_14174ebc0();
            }
        }
    }
    else if (uMsg == 0x465)
    {
        if (FUN_140714f90() != 0)
            FUN_140714f90()->FUN_141538f80();
        if (TSingleton<CStateService>::GetInstance() != 0)
        {
            int nCode = (int)wParam;
            bool bHandled = false;
            if (FUN_140e800e0() != 0 && FUN_140aadf80() != 0)
            {
                if (FUN_140e800e0()->FUN_140aacf50(nCode))
                {
                    if (!FUN_140e800e0()->FUN_140aad1e0())
                        FUN_140e800e0()->FUN_140aad340(nCode);
                    bHandled = true;
                }
                if (FUN_140e800e0()->FUN_140aad1e0() == 1)
                {
                    int nKey = FUN_140e800e0()->FUN_140aad2b0();
                    if (FUN_140e800e0()->FUN_140aad2d0(nKey))
                        bHandled = false;
                    if (FUN_140e800e0()->FUN_140aad220())
                    {
                        FUN_140e800e0()->FUN_140aad5c0(0xc9);
                        bHandled = false;
                    }
                }
            }
            if (!bHandled)
            {
                TSingleton<CStateService>::GetInstance()->FUN_1417e25a0(0x6200009);
                unsigned nMsgId = 0;
                switch (nCode)
                {
                    case 0x2714: nMsgId = 0xd29; break;
                    case 0x271d: nMsgId = 0xd2a; break;
                    case 0x271e: nMsgId = 0xd2b; break;
                    case 0x2726: nMsgId = 0xd2c; break;
                    case 0x2728: nMsgId = 0xd2d; break;
                    case 0x2733: nMsgId = 0xd2e; break;
                    case 0x2734: nMsgId = 0xd2f; break;
                    case 0x2735: nMsgId = 0xd30; break;
                    case 0x2736: nMsgId = 0xd28; break;
                    case 0x2737: nMsgId = 0xd31; break;
                    case 0x2738: nMsgId = 0xd32; break;
                    case 0x2739: nMsgId = 0xd28; break;
                    case 0x273a: nMsgId = 0xd28; break;
                    case 0x273b: nMsgId = 0xd28; break;
                    case 0x273c: nMsgId = 0xd28; break;
                    case 0x273d: nMsgId = 0xd28; break;
                    case 0x273e: nMsgId = 0xd28; break;
                    case 0x273f: nMsgId = 0xd28; break;
                    case 0x2740: nMsgId = 0xd33; break;
                    case 0x2741: nMsgId = 0xd28; break;
                    case 0x2742: nMsgId = 0xd34; break;
                    case 0x2743: nMsgId = 0xd35; break;
                    case 0x2744: nMsgId = 0xd36; break;
                    case 0x2745: nMsgId = 0xd37; break;
                    case 0x2746: nMsgId = 0xd38; break;
                    case 0x2747: nMsgId = 0xd39; break;
                    case 0x2748: nMsgId = 0xd3a; break;
                    case 0x2749: nMsgId = 0xd28; break;
                    case 0x274a: nMsgId = 0xd3b; break;
                    case 0x274c: nMsgId = 0xd3c; break;
                    case 0x274d: nMsgId = 0xd3d; break;
                    case 0x2750: nMsgId = 0xd3e; break;
                    case 0x2751: nMsgId = 0xd3f; break;
                    case 0x2753: nMsgId = 0xd40; break;
                    case 0x276b: nMsgId = 0xd28; break;
                    case 0x276c: nMsgId = 0xd28; break;
                    case 0x276d: nMsgId = 0xd28; break;
                    case 0x2775: nMsgId = 0xd41; break;
                case 0x277d: nMsgId = 0xd28; break;
                case 0x2af9: nMsgId = 0xd42; break;
                case 0x2afa: nMsgId = 0xd43; break;
                case 0x2afb: nMsgId = 0xd28; break;
                case 0x2afc: nMsgId = 0xd28;
                }
                CStringW strReason = GetStringCommon(nMsgId);
                if (!strReason.IsEmpty())
                    strReason += L" : ";
                CStringW strCode;
                strCode.Format(L"%d", nCode);
                unsigned nFormatId;
                if (DAT_143ab2858 != 0)
                    nFormatId = 0xc69;
                else
                    nFormatId = 0x20f;
                CStringW strMessage = FUN_14052bd00(nFormatId, FUN_1401d0080(strReason, strCode));
                if (DAT_143ab2858 != 0)
                {
                    Unk_LoginDialog* pLogin = FUN_141a003b0(0x4e22);
                    if (pLogin != 0)
                        FUN_1419e21e0(pLogin, strMessage);
                }
                else
                {
                    FUN_140d73aa0(strMessage, 0, 0, CStringW(L""));
                    if (GetClientPlatform() != 0)
                        GetClientPlatform()->vfunc_58(0x20f, nCode);
                }
            }
        }
    }
    else if (uMsg == 0x46b)
    {
        if (FUN_140e800e0() != 0 && FUN_140aadf80() != 0)
        {
            bool bFlag = true;
            if (TSingleton<CStateService>::GetInstance() != 0)
            {
                if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() != 0x620000c)
                {
                    bFlag = false;
                    FUN_140e800e0()->FUN_140aad6e0(0xcc);
                }
            }
            if (bFlag)
            {
                bool bBusy = FUN_140e800e0()->FUN_140aad450();
                if (!bBusy)
                    FUN_140e800e0()->FUN_140aad6e0(200);
            }
        }
    }
    else if (uMsg == 0x466)
    {
        int nCode = (int)wParam;
        bool bHandled = false;
        if (TSingleton<CStateService>::GetInstance() != 0 && FUN_140e800e0() != 0 && FUN_140aadf80() != 0)
        {
            if (FUN_140e800e0()->FUN_140aacf50(nCode))
            {
                if (!FUN_140e800e0()->FUN_140aad1e0())
                    FUN_140e800e0()->FUN_140aad340(nCode);
                bHandled = true;
            }
            if (FUN_140e800e0()->FUN_140aad1e0() == 1)
            {
                int nKey = FUN_140e800e0()->FUN_140aad2b0();
                if (FUN_140e800e0()->FUN_140aad2d0(nKey))
                    bHandled = false;
                if (FUN_140e800e0()->FUN_140aad220())
                {
                    FUN_140e800e0()->FUN_140aad5c0(0xc9);
                    bHandled = false;
                }
            }
        }
        if (!bHandled)
            FUN_141b93a20(nCode);
    }
    else if (uMsg == 0x467)
    {
        bool bFlag = false;
        if (FUN_140e800e0() != 0)
            bFlag = FUN_140e800e0()->FUN_140aad1e0();
        if (bFlag)
        {
            FUN_140e800e0()->FUN_140aad6e0(200);
        }
        else
        {
            int nCode = (int)wParam;
            FUN_140d74390(FUN_1408116a0(0x20e, nCode), 0, FUN_140b76b10(FUN_141902530));
            if (GetClientPlatform() != 0)
                GetClientPlatform()->vfunc_58(0x20e, nCode);
        }
    }
    else if (uMsg == 0x468)
    {
        if (FUN_140714f90() != 0)
            FUN_140714f90()->FUN_1415382c0();
    }
    else if (uMsg == 0x469)
    {
        if (FUN_140714f90() != 0)
            FUN_140714f90()->FUN_141538540();
    }
    else if (uMsg == 0x46a)
    {
        int bFlag = 0;
        if (FUN_140e800e0() != 0)
            bFlag = FUN_140e800e0()->FUN_140aad1e0();
        if (FUN_140714f90() != 0)
            FUN_140714f90()->FUN_141538480(bFlag);
    }
    if (GetClientPlatform() != 0)
        GetClientPlatform()->vfunc_19(uMsg, (void*)wParam, (void*)lParam);
    switch (uMsg)
    {
    case 0xa1:
        if (wParam == 0x14)
        {
            if (TSingleton<CStateService>::GetInstance() != 0)
            {
                if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() != 0x6200009 && TSingleton<CStateService>::GetInstance()->FUN_1417e2610() != 0x620000b)
                {
                    FUN_140d73bc0(0x288, 0x17, 0, s_gameExit);
                    return 0;
                }
                else
                {
                    PostQuitMessage(0);
                    return 0;
                }
            }
        }
        else if (wParam == 8)
        {
            if (FUN_140aadf80() != 0)
                PostMessageA(((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef(), 0x112, 0xf020, 0);
            return 0;
        }
        else if (wParam == 9)
        {
            return 0;
        }
        break;
    case 0xa3:
    case 0xa4:
    case 0xa5:
    case 0xa6:
    case 0xa7:
    case 0xa8:
    case 0xa9:
        return 0;
    }
    if (uMsg == 0x201 || uMsg == 0x202 || uMsg == 0x203 || uMsg == 0x204 || uMsg == 0x205 || uMsg == 0x206 ||
        uMsg == 0x207 || uMsg == 0x208 || uMsg == 0x209 || uMsg == 0x20a || uMsg == 0x200 || uMsg == 0x2a3)
    {
        int nPosX = (int)(short)LOWORD(lParam);
        int nPosY = (int)(short)HIWORD(lParam);
        if (uMsg == 0x20a)
        {
            POINT pt;
            pt.x = nPosX;
            pt.y = nPosY;
            ScreenToClient(hWnd, &pt);
            nPosX = pt.x;
            nPosY = pt.y;
        }
        int nWheel = 0;
        if (uMsg == 0x20a)
            nWheel = (short)HIWORD(wParam);
        int nKeys = LOWORD(wParam);
        BOOL bLeft = (nKeys & 1) ? TRUE : FALSE;
        BOOL bRight = (nKeys & 2) ? TRUE : FALSE;
        if (TSingleton<CStateService>::GetInstance() != 0)
        {
            Unk_MouseTarget* pTarget = (Unk_MouseTarget*)(CSceneStateBase*)TSingleton<CStateService>::GetInstance()->GetCurrent();
            if (pTarget != 0)
                pTarget->vfunc_13(uMsg, nPosX, nPosY, bLeft, bRight, nWheel);
        }
    }
    switch (uMsg)
    {
    case 0x113:
        if (wParam == 1000 && FUN_140aae430() != 0 && DAT_143af7d44 == 0)
        {
            unsigned nLastInput = FUN_141489fb0(FUN_140aae430());
            unsigned nNow = FUN_140869420();
            if (nLastInput + 500 < nNow)
                FUN_141489f40(FUN_140aae430());
            static unsigned s_nLastPowerTick = FUN_140869420();
            unsigned nElapsed = nNow - s_nLastPowerTick;
            if (nElapsed >= 10000)
            {
                FUN_141b938f0(1);
                s_nLastPowerTick = nNow;
            }
        }
        break;
    case 0x281:
        return DefWindowProcA(hWnd, uMsg, wParam, 0);
    case 0x100:
        if (wParam == 0x7b && (GetAsyncKeyState(0x11) & 0x8000) != 0 &&
            AfxMessageBox("Crash \xb8\xb8\xb5\xe9\xb1\xe2", 1, 0) == 1)
        {
            throw 0xd;
        }
        if (wParam == 0x47 && (GetAsyncKeyState(0x11) & 0x8000) != 0 && reinterpret_cast<Unk_GameCore*>(TSingleton<CMainSystem>::GetInstance()) != 0)
        {
            void* pHolder = FUN_140af8310(&reinterpret_cast<Unk_GameCore*>(TSingleton<CMainSystem>::GetInstance())->m_holder);
            ATL::CComPtr<Unk_ComObj> spObj(FUN_141296b50(pHolder));
            if (static_cast<Unk_ComObj*>(spObj) != 0)
            {
                spObj->vfunc_16();
                break;
            }
        }
        break;
    case 0x101:
        if (wParam == 0x2c)
        {
            if (g_bPrintScreenPending == 0 && FUN_1403ed2d0() != 0)
            {
                FUN_141bc9fd0(FUN_1403ed2d0(), 0x75);
                return 0;
            }
            g_bPrintScreenPending = 0;
        }
        break;
    case 0x312:
        if ((wParam == (WPARAM)-2 || wParam == (WPARAM)-1) && g_bPrintScreenPending == 0)
        {
            if (FUN_1403ed2d0() != 0)
                FUN_141bc9fd0(FUN_1403ed2d0(), 0x75);
            g_bPrintScreenPending = 1;
        }
        break;
    case 0x112:
        switch (wParam)
        {
        case 0xf100:
            return 0;
        }
        break;
    case 0x10:
    {
        NiDX9Renderer* pRenderer = (NiDX9Renderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, NiDX9Renderer::GetRenderer());
        if (pRenderer != 0)
            pRenderer->RestoreDisplayMode();
        if (TSingleton<CStateService>::GetInstance() != 0 && TSingleton<CStateService>::GetInstance()->FUN_1417e2610() != 0x6200009 &&
            TSingleton<CStateService>::GetInstance()->FUN_1417e2610() != 0x620000b)
        {
            FUN_140d73bc0(0x288, 0x17, 0, s_gameExit);
            return 0;
        }
        break;
    }
    case 2:
    {
        NiDX9Renderer* pRenderer = (NiDX9Renderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, NiDX9Renderer::GetRenderer());
        if (pRenderer != 0)
            pRenderer->RestoreDisplayMode();
        PostQuitMessage(0);
        break;
    }
    case 6:
        if (DAT_143af7d44 != 0)
            return 0;
        else if (GetClientPlatform() != 0)
            GetClientPlatform()->vfunc_71((void*)wParam);
        switch (wParam)
        {
        case 1:
        case 2:
            if (g_bAppActive == 0)
            {
                g_bAppActive = 1;
                if (TSingleton<CGameOption>::GetInstance() != 0 && FUN_140c9cb10() != 0 && TSingleton<CGameOption>::GetInstance()->FUN_140d13c70()->m_b01 == 0)
                {
                    FUN_140c9cb10()->FUN_1417ae840(0);
                    if (FUN_140c8dac0() != 0)
                        FUN_140d0a560(FUN_140c8dac0());
                }
                g_143afa350 = 1;
                if (g_bHotkeyPrintScreen == 0)
                    g_bHotkeyPrintScreen = RegisterHotKey(hWnd, -2, 0, 0x2c);
                if (g_bHotkeyAltPrintScreen == 0)
                    g_bHotkeyAltPrintScreen = RegisterHotKey(hWnd, -1, 1, 0x2c);
            }
            break;
        default:
            if (g_bAppActive != 0)
            {
                NiDX9Renderer* pRenderer = (NiDX9Renderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, NiDX9Renderer::GetRenderer());
                if (pRenderer != 0)
                {
                    unsigned int nFlags = pRenderer->GetCreationFlags();
                    if ((nFlags & 4) != 0)
                        pRenderer->RestoreDisplayMode();
                }
                g_bAppActive = 0;
                if (TSingleton<CGameOption>::GetInstance() != 0 && FUN_140c9cb10() != 0 && TSingleton<CGameOption>::GetInstance()->FUN_140d13c70()->m_b01 == 0)
                {
                    FUN_140c9cb10()->FUN_1417ae840(1);
                    if (FUN_140c8dac0() != 0)
                        FUN_140d0a510(FUN_140c8dac0());
                }
                if (g_bHotkeyPrintScreen != 0)
                    UnregisterHotKey(hWnd, -2);
                if (g_bHotkeyAltPrintScreen != 0)
                    UnregisterHotKey(hWnd, -1);
                g_bHotkeyPrintScreen = 0;
                g_bHotkeyAltPrintScreen = 0;
            }
        }
        break;
    case 0x18:
        FUN_141b91a60();
        break;
    case 3:
        GetWindowRect(hWnd, &g_rcWindow);
        break;
    case 0x24:
    {
        int nTrackW = GetSystemMetrics(0x3b);
        int nTrackH = GetSystemMetrics(0x3c);
        int nScreenW = GetSystemMetrics(0);
        int nScreenH = GetSystemMetrics(1);
        MINMAXINFO* pInfo = (MINMAXINFO*)lParam;
        pInfo->ptMaxSize.x = nScreenW + 0x32;
        pInfo->ptMaxSize.y = nScreenH + 0x32;
        pInfo->ptMaxTrackSize.x = nTrackW + 0x32;
        pInfo->ptMaxTrackSize.y = nTrackH + 0x32;
    }
    }
    if (FUN_141ade340(hWnd, uMsg, wParam, lParam) != 0)
        return 0;
    if (FUN_1414a56c0() != 0)
    {
        if (FUN_1414a56c0()->vfunc_18(hWnd, uMsg, wParam, lParam) != 0)
            return 0;
    }
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// @0x141b93470
efd::AsyncResult CWindowService::OnTick()
{
    if (GetClientPlatform()->vfunc_12() == 0)
    {
        if (GetWindowRef() != 0)
            GetClientPlatform()->vfunc_18(GetWindowRef());
    }
    return efd::AsyncResult_Complete;
}

// @0x141b934f0
BOOL CWindowService::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    BOOL bMenu = FALSE;
    RECT rc;
    rc.left = m_windowLeft;
    rc.top = m_windowTop;
    rc.right = m_windowWidth;
    rc.bottom = m_windowHeight;
    DWORD dwStyle = 0xca0000;
    AdjustWindowRect(&rc, dwStyle, bMenu);
    m_hWnd = CreateWindowExA(0, m_strWindowClass.c_str(), m_strWindowTitle.c_str(), dwStyle, 0, 0, rc.right - rc.left,
                             rc.bottom - rc.top, 0, 0, hInstance, 0);
    if (m_hWnd != 0)
    {
        CWnd* pWnd = CWnd::FromHandle((HWND)m_hWnd);
        CMenu* pMenu = pWnd->GetMenu();
        if (pMenu != 0)
            m_menu.Attach(pMenu->GetSafeHmenu());
        ShowWindow((HWND)m_hWnd, SW_HIDE);
        UpdateWindow((HWND)m_hWnd);
        SetTimer((HWND)m_hWnd, 1000, g_uTimerInterval, 0);
        return TRUE;
    }
    return FALSE;
}

// @0x141b93740
ATOM CWindowService::RegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXA wc;
    wc.cbSize = sizeof(WNDCLASSEXA);
    wc.style = 0xb;
    wc.lpfnWndProc = m_pWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    m_idLargeIcon = 2000;
    m_idSmallIcon = 2000;
    if (m_idLargeIcon != 0)
        wc.hIcon = LoadIconA(hInstance, MAKEINTRESOURCEA((WORD)m_idLargeIcon));
    else
        wc.hIcon = LoadIconA(hInstance, IDI_APPLICATION);
    wc.hCursor = LoadCursorA(0, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    if (m_idWindowMenu != 0)
        wc.lpszMenuName = MAKEINTRESOURCEA((WORD)m_idWindowMenu);
    wc.lpszMenuName = 0;
    wc.lpszClassName = m_strWindowClass.c_str();
    if (m_idSmallIcon != 0)
        wc.hIconSm = LoadIconA(hInstance, MAKEINTRESOURCEA((WORD)m_idSmallIcon));
    else
        wc.hIconSm = LoadIconA(hInstance, IDI_APPLICATION);
    return RegisterClassExA(&wc);
}

// @0x141b938d0
void CWindowService::OnRendererChanged(void* pDevice)
{
}

// Keeps the display awake (nMode 1) or restores the power and screensaver defaults (nMode 0).
// @0x141b938f0
int FUN_141b938f0(int nMode)
{
    switch (nMode)
    {
    case 0: SetThreadExecutionState(0x80000000); break;
    case 1: SetThreadExecutionState(0x80000043); break;
    case 2: SetThreadExecutionState(0x80000001); break;
    case 3: SetThreadExecutionState(0x80000001); break;
    }
    if (nMode == 1)
    {
        SystemParametersInfoA(0x51, 0, 0, 0);
        SystemParametersInfoA(0x52, 0, 0, 0);
        SystemParametersInfoA(0xf, 0, 0, 0);
        SystemParametersInfoA(0x11, 0, 0, 0);
    }
    if (nMode == 0)
    {
        SystemParametersInfoA(0x51, 0x1e, 0, 0);
        SystemParametersInfoA(0x52, 0x1e, 0, 0);
        SystemParametersInfoA(0xf, 0x1e, 0, 0);
        SystemParametersInfoA(0x11, 1, 0, 0);
    }
    return 1;
}

// @0x141b93a20
void FUN_141b93a20(unsigned nArg)
{
    TSingleton<CUIService>::GetInstance()->FUN_141adbea0();
    FUN_140d73bc0(0xae, 0, 0, s_forceLogin);
    GetClientPlatform()->vfunc_58(0xae, nArg);
}

// @0x141b93aa0
void FUN_141b93aa0()
{
    TSingleton<CUIService>::GetInstance()->FUN_141adbea0();
    FUN_140d73aa0(FUN_1408116a0(0x20f, 0), 0, 0, s_forceLogin);
    GetClientPlatform()->vfunc_58(0x20f, 0);
}

TSingleton<CWindowService>::TSingleton() { s_instance = static_cast<CWindowService*>(this); }
CWindowService* TSingleton<CWindowService>::s_instance = 0;

// @0x141b93c40
Unk_WorkerPtr& Unk_WorkerPtr::operator=(int)
{
    FUN_140d4dc30();
    return *this;
}
// @0x141b93c70
Unk_WorkerPtr::operator Unk_Worker*() const { return m_p; }
// ATL::CComPtrBase<Unk_ComObj>::operator->
// @0x141b93c80
Unk_ComObj* FUN_141b93c80(Unk_ComObj** ppObj) { return *ppObj; }
// @0x141b93c90
Unk_Worker* Unk_WorkerPtr::operator->() const { return m_p; }

// Full-exe clients use two older manager class names for the window-service methods.
class Unk_RsApp
{
public:
    void FUN_141b90f20(int message);
    bool FUN_141b91010(bool fullscreen, int width, int height);
    void FUN_141b91290(bool fullscreen, int width, int height);
};
class Unk_GsApp
{
public:
    bool FUN_141b91010(bool fullscreen, int width, int height);
};

// MS2-FUNCTIONAL: legacy message entry delegates to the recovered platform service method.
void Unk_RsApp::FUN_141b90f20(int message)
{ reinterpret_cast<CWindowService*>(this)->PostMouseMove(static_cast<UINT>(message)); }
// MS2-FUNCTIONAL: both old client spellings delegate to the same renderer recreation path.
bool Unk_GsApp::FUN_141b91010(bool fullscreen, int width, int height)
{ return reinterpret_cast<CWindowService*>(this)->RecreateRenderer(fullscreen, width, height); }
// MS2-FUNCTIONAL: both old client spellings delegate to the same renderer recreation path.
bool Unk_RsApp::FUN_141b91010(bool fullscreen, int width, int height)
{ return reinterpret_cast<CWindowService*>(this)->RecreateRenderer(fullscreen, width, height); }
// MS2-FUNCTIONAL: legacy mode entry delegates to the recovered platform service method.
void Unk_RsApp::FUN_141b91290(bool fullscreen, int width, int height)
{ reinterpret_cast<CWindowService*>(this)->ApplyWindowMode(fullscreen, width, height); }

// Full-executable aliases for the corresponding CWindowService methods.
// MS2-PIN: ?PostMouseMove@CWindowService@@QEAAXI@Z 0x141b90f20
// MS2-PIN: ?RecreateRenderer@CWindowService@@QEAA_N_NII@Z 0x141b91010
// MS2-PIN: ?ApplyWindowMode@CWindowService@@QEAAX_NII@Z 0x141b91290
// MS2-PIN: ?FUN_141b90f20@Unk_RsApp@@QEAAXH@Z 0x141b90f20
// MS2-PIN: ?FUN_141b91010@Unk_GsApp@@QEAA_N_NHH@Z 0x141b91010
// MS2-PIN: ?FUN_141b91010@Unk_RsApp@@QEAA_N_NHH@Z 0x141b91010
// MS2-PIN: ?FUN_141b91290@Unk_RsApp@@QEAAX_NHH@Z 0x141b91290
