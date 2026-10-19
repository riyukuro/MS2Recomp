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
class Unk_AppPlatform {                 // app/platform object behind 0x140d86260 (59+ slots; vfunc_58 posts a UI message)
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
    virtual int vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(HWND);
    virtual void vfunc_19(UINT);
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58(int, int);
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71(unsigned __int64);
};
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
class Unk_StateRef {                    // counted reference to the current game state (8 bytes)
public:
    ~Unk_StateRef();                    // 0x140f30880
    void* FUN_140f30a30();              // get()
private:
    void* m_p;
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
class Unk_MsgCallback {                 // Delegate<bool(int, const CMsgBoxData&)> built from a plain function (8 bytes)
public:
    ~Unk_MsgCallback();                 // 0x140534cb0
private:
    void* m_p;
};
class Unk_HudPtr {                      // handle returned by the UI manager lookup
public:
    ~Unk_HudPtr();                      // 0x140a58400
    bool FUN_140a58470();
    void* FUN_140a584a0();
private:
    void* m_pad_00;
    void* m_pad_08;
    void* m_pad_10;
};
class Unk_LoginDialog;
void FUN_1417e25a0(void*, int);
int FUN_141b938f0(int);
void FUN_141b93a20(unsigned);
void FUN_141b93aa0();
Unk_MessageHook* FUN_1414a56c0();

extern Unk_WorkerPtr g_workerPtr;       // 0x143ac2bd0
Unk_AppPlatform* FUN_140d86260();
void* FUN_140a44830();
void FUN_1401ce2f0(void*, const char*, unsigned, unsigned);
void* FUN_140d89bc0();
void* FUN_140994450();
NiDX9Renderer* FUN_14098d8d0(const NiRTTI*, void*);
void* FUN_1409a8d60(NiDX9Renderer*);
void FUN_1427d5390(NiDX9Renderer*);
void FUN_1427cb2a0(NiDX9Renderer*, unsigned);
void FUN_140d4a600(Unk_Worker*);
void* FUN_14025e7a0();
struct Unk_WinMovieMgrView { Unk_HudPtr FUN_1422b0370(int nLayer); };   // member (this=rcx, hidden return=rdx)
void FUN_1422cec40(void*, char);
void FUN_14209cc20(void*, void*);
void* FUN_140d8ee90();
void FUN_140a1f970(void*, const CString&, const CString&);
void* FUN_1403ed2b0();
void FUN_141adbea0(void*);
CStringW FUN_1408116a0(int, const int&);
CStringW FUN_14028de60(unsigned);
CStringW FUN_1401d0080(const CStringW&, const CStringW&);
CStringW FUN_14052bd00(unsigned, const CStringW&);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_140d73bc0(int, int, void*, CStringW);
Unk_LoginDialog* FUN_141a003b0(int);
void FUN_1419e21e0(Unk_LoginDialog*, CStringW);
Unk_MsgBoxPtr FUN_140d74390(CStringW, int, Unk_MsgCallback);
Unk_MsgCallback FUN_140b76b10(bool (*)(int));
bool FUN_141902530(int);
void* FUN_140aa6d30();
int FUN_1417e2610(void*);
struct Unk_WinSceneView { Unk_StateRef FUN_1417e26d0(); };   // current state (member: this=rcx, hidden return=rdx)
void FUN_14174ebc0(void*);
void* FUN_140714f90();
void FUN_141538f80(void*);
void FUN_1415382c0(void*);
void FUN_141538540(void*);
void FUN_141538480(void*, char);
void* FUN_140e800e0();
void* FUN_140aadf80();
bool FUN_140aacf50(void*, unsigned);
bool FUN_140aad1e0(void*);
void FUN_140aad340(void*, unsigned);
int FUN_140aad2b0(void*);
bool FUN_140aad2d0(void*, int);
bool FUN_140aad220(void*);
void FUN_140aad5c0(void*, int);
bool FUN_140aad450(void*);
void FUN_140aad6e0(void*, int);
void* FUN_1409a8b10();
void* FUN_140c9cb10();
char* FUN_140d13c70(void*);
void FUN_1417ae840(void*, int);
void* FUN_140c8dac0();
void FUN_140d0a510(void*);
void FUN_140d0a560(void*);
Unk_GameCore* FUN_14086d260();
void* FUN_140af8310(Unk_Holder*);
Unk_ComObj* FUN_141296b50(void*);
void* FUN_1403ed2d0();
void FUN_141bc9fd0(void*, int);
void* FUN_140aae430();
int FUN_141489fb0(void*);
void FUN_141489f40(void*);
unsigned FUN_140869420();
__int64 FUN_141ade340(HWND, UINT, WPARAM, LPARAM);
HWND FUN_14209c720(const void*);

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
    if (!ScreenToClient(FUN_14209c720(this), &pt))
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
// MS2-FUNCTIONAL: cursor-position arithmetic scheduling differs from the exe
void CWindowService::PostMouseMove(UINT nMessage)
{
    POINT pt;
    RECT rc;
    if (g_bAppActive != 0 && GetCursorPos(&pt))
    {
        if (ScreenToClient(FUN_14209c720(this), &pt))
        {
            if (GetClientRect(FUN_14209c720(this), &rc))
            {
                unsigned x = pt.x - rc.left;
                int y = pt.y - rc.top;
                LPARAM lParam = (LPARAM)(int)(x | y * 0x10000);
                PostMessageA(FUN_14209c720(this), nMessage, 0, lParam);
            }
        }
    }
}

// @0x141b91010
// MS2-FUNCTIONAL: renderer re-creation; temporaries and register allocation differ from the exe
// MS2-FUNCTIONAL: frame layout of the renderer creation parameters differs
bool CWindowService::RecreateRenderer(bool bFullscreen, unsigned nWidth, unsigned nHeight)
{
    FUN_1401ce2f0(FUN_140a44830(), "\n *RecreateRenderer %d %d", nWidth, nHeight);
    NiDX9Renderer* pRenderer = FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, FUN_140d89bc0());
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
    if (!bFullscreen || m_bMaximize)
        nUseFlags &= ~4u;
    else
        nUseFlags |= 4;
    nCurHeight = nHeight;
    nCurWidth = nWidth;
    NiDX9Renderer::RecreateStatus eStatus = pRenderer->Recreate(nCurWidth, nCurHeight, nUseFlags, FUN_14209c720(this),
        eFBFormat, eDSFormat, ePresentInterval, eSwapEffect, nFBMode, nBackBufferCount, nRefreshRate);
    if (eStatus == NiDX9Renderer::RECREATESTATUS_FAILED)
        return false;
    OnRendererChanged(FUN_1409a8d60(pRenderer));
    char bMode = bFullscreen;
    if (m_bMaximize)
        bMode = 1;
    ApplyWindowMode(bMode != 0, nCurWidth, nCurHeight);
    return true;
}

// Switches the window between the bordered windowed mode (bFullscreen false) and the borderless full-screen mode.
// @0x141b91290
// MS2-FUNCTIONAL: large window-mode switch; temporaries and branch layout differ from the exe
// MS2-FUNCTIONAL: control flow equivalent; temporaries and the error-report locals are laid out differently
void CWindowService::ApplyWindowMode(bool bFullscreen, unsigned nWidth, unsigned nHeight)
{
    int nShowCmd = (g_143af7d58 == 0);
    if (!bFullscreen)
    {
        void* pRenderMgr = FUN_140994450();
        if (pRenderMgr != 0)
        {
            NiDX9Renderer* pRenderer = FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, pRenderMgr);
            if (pRenderer != 0)
                FUN_1427d5390(pRenderer);
        }
        HMENU hMenu = m_menu.GetSafeHmenu();
        unsigned bHasMenu = (hMenu != 0);
        if (bHasMenu != 0)
            CWnd::FromHandle(m_hWnd)->SetMenu(&m_menu);
        unsigned nScreenW = GetSystemMetrics(0);
        unsigned nScreenH = GetSystemMetrics(1);
        unsigned nClientW = nWidth;
        if ((int)nScreenW < (int)nWidth)
            nClientW = nScreenW;
        unsigned nClientH = nHeight;
        if ((int)nScreenH < (int)nHeight)
            nClientH = nScreenH;
        RECT rc;
        rc.left = 0;
        rc.top = 0;
        rc.right = nClientW;
        rc.bottom = nClientH;
        AdjustWindowRect(&rc, 0xca0000, bHasMenu);
        int nOuterW = rc.right - rc.left;
        int nOuterH = rc.bottom - rc.top;
        if (pRenderMgr != 0)
        {
            NiDX9Renderer* pRenderer = FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, pRenderMgr);
            if (pRenderer != 0)
                pRenderer->Recreate(nClientW, nClientH);
        }
        ShowWindow(FUN_14209c720(this), 0);
        SetWindowLongA(FUN_14209c720(this), -16, 0xca0000);
        SetWindowPos(FUN_14209c720(this), 0, 0, 0, nOuterW, nOuterH, 0x23);
        float fX = (float)(int)(nScreenW - nOuterW) * 0.5f;
        float fPosX;
        if (0.0f <= (float)floorf(fX))
            fPosX = (float)floorf(fX);
        else
            fPosX = 0.0f;
        float fY = (float)(int)(nScreenH - nOuterH) * 0.5f;
        float fPosY;
        if (0.0f <= (float)floorf(fY))
            fPosY = (float)floorf(fY);
        else
            fPosY = 0.0f;
        SetWindowPos(FUN_14209c720(this), HWND_NOTOPMOST, (int)fPosX, (int)fPosY, nOuterW, nOuterH, 0);
        ShowWindow(FUN_14209c720(this), nShowCmd);
    }
    else
    {
        void* pRenderMgr = FUN_140994450();
        if (pRenderMgr != 0)
        {
            NiDX9Renderer* pRenderer = FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, pRenderMgr);
            if (pRenderer != 0)
                FUN_1427cb2a0(pRenderer, nWidth);
        }
        CWnd::FromHandle(m_hWnd)->SetMenu(0);
        CRect rcWindow(0, 0, nWidth, nHeight);
        if (!AdjustWindowRect((LPRECT)rcWindow, 0x80000000, 0))
        {
            DWORD nError = GetLastError();
            CString strError;
            strError.Format("!AdjustWindowRect() result [%d] %d %d - %d %d", nError, rcWindow.left, rcWindow.top,
                rcWindow.Width(), rcWindow.Height());
            if (FUN_140d8ee90() != 0)
                FUN_140a1f970(FUN_140d8ee90(), CString("Error AdjustWindowRect"), strError);
            rcWindow.SetRect(0, 0, nWidth, nHeight);
        }
        SetWindowLongA(FUN_14209c720(this), -16, 0x80000000);
        UINT nFlags = 2;
        HWND hWndInsertAfter = HWND_TOPMOST;
        if (m_bMaximize)
        {
            nFlags = 0;
            hWndInsertAfter = HWND_NOTOPMOST;
        }
        int nHeightOuter = rcWindow.Height();
        int nWidthOuter = rcWindow.Width();
        if (!SetWindowPos(FUN_14209c720(this), hWndInsertAfter, 0, 0, nWidthOuter, nHeightOuter, nFlags))
        {
            DWORD nError = GetLastError();
            CString strError;
            strError.Format("!SetWindowPos() result [%d] %d %d - %d %d topMost %d flag %d", nError, rcWindow.left,
                rcWindow.top, rcWindow.Width(), rcWindow.Height(), (int)(INT_PTR)hWndInsertAfter, nFlags);
            if (FUN_140d8ee90() != 0)
                FUN_140a1f970(FUN_140d8ee90(), CString("Error SetWindowPos"), strError);
        }
        ShowWindow(FUN_14209c720(this), nShowCmd);
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
// MS2-FUNCTIONAL: handle temporary and lookup inline differ from the exe
void FUN_141b91b20(char bValue)
{
    g_byteFlag1439faadc = bValue;
    Unk_HudPtr hud = static_cast<Unk_WinMovieMgrView*>(FUN_14025e7a0())->FUN_1422b0370(6);
    if (hud.FUN_140a58470())
        FUN_1422cec40(hud.FUN_140a584a0(), bValue);
}

// @0x141b91ba0
void CWindowService::ShowGameWindow()
{
    FUN_141b91a60();
    if (m_bMaximize)
        ShowWindow(FUN_14209c720(this), 3);
    else
        ShowWindow(FUN_14209c720(this), 5);
    SetForegroundWindow(FUN_14209c720(this));
    SetFocus(FUN_14209c720(this));
}

// Window procedure of the game window.
// @0x141b91c30
// MS2-FUNCTIONAL: large message dispatcher; temporaries and branch layout differ from the exe
LRESULT CALLBACK Unk_WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (g_bDefaultWndProc == 1)
        return DefWindowProcA(hWnd, uMsg, wParam, lParam);
    if (uMsg == 0x4c8)
    {
        if (FUN_140aa6d30() != 0)
        {
            if (FUN_1417e2610(FUN_140aa6d30()) == 0x620000d)
            {
                void* pState = static_cast<Unk_WinSceneView*>(FUN_140aa6d30())->FUN_1417e26d0().FUN_140f30a30();
                if (pState != 0)
                    FUN_14174ebc0(pState);
            }
        }
    }
    else
    {
        int nCode = (int)wParam;
        if (uMsg == 0x465)
        {
            if (FUN_140714f90() != 0)
                FUN_141538f80(FUN_140714f90());
            if (FUN_140aa6d30() != 0)
            {
                bool bHandled = false;
                if (FUN_140e800e0() != 0 && FUN_140aadf80() != 0)
                {
                    if (FUN_140aacf50(FUN_140e800e0(), (unsigned)wParam))
                    {
                        if (!FUN_140aad1e0(FUN_140e800e0()))
                            FUN_140aad340(FUN_140e800e0(), (unsigned)wParam);
                        bHandled = true;
                    }
                    if (FUN_140aad1e0(FUN_140e800e0()) == 1)
                    {
                        int nKey = FUN_140aad2b0(FUN_140e800e0());
                        if (FUN_140aad2d0(FUN_140e800e0(), nKey))
                            bHandled = false;
                        if (FUN_140aad220(FUN_140e800e0()))
                        {
                            FUN_140aad5c0(FUN_140e800e0(), 0xc9);
                            bHandled = false;
                        }
                    }
                }
                if (!bHandled)
                {
                    FUN_1417e25a0(FUN_140aa6d30(), 0x6200009);
                    unsigned nMsgId = 0;
                    if (nCode < 0x2afa)
                    {
                        if (nCode == 0x2af9)
                        {
                            nMsgId = 0xd42;
                        }
                        else
                        {
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
                            case 0x277d: nMsgId = 0xd28;
                            }
                        }
                    }
                    else if (nCode == 0x2afa)
                    {
                        nMsgId = 0xd43;
                    }
                    else if (nCode == 0x2afb)
                    {
                        nMsgId = 0xd28;
                    }
                    else if (nCode == 0x2afc)
                    {
                        nMsgId = 0xd28;
                    }
                    CStringW strReason = FUN_14028de60(nMsgId);
                    if (!strReason.IsEmpty())
                        strReason += L" : ";
                    CStringW strCode;
                    strCode.Format(L"%d", wParam & 0xffffffff);
                    unsigned nFormatId;
                    if (DAT_143ab2858 == 0)
                        nFormatId = 0x20f;
                    else
                        nFormatId = 0xc69;
                    CStringW strMessage = FUN_14052bd00(nFormatId, FUN_1401d0080(strReason, strCode));
                    if (DAT_143ab2858 == 0)
                    {
                        FUN_140d73aa0(strMessage, 0, 0, CStringW(L""));
                        if (FUN_140d86260() != 0)
                            FUN_140d86260()->vfunc_58(0x20f, 0);
                    }
                    else
                    {
                        Unk_LoginDialog* pLogin = FUN_141a003b0(0x4e22);
                        if (pLogin != 0)
                            FUN_1419e21e0(pLogin, strMessage);
                    }
                }
            }
        }
        else if (uMsg == 0x46b)
        {
            if (FUN_140e800e0() != 0 && FUN_140aadf80() != 0)
            {
                bool bFlag = true;
                if (FUN_140aa6d30() != 0)
                {
                    if (FUN_1417e2610(FUN_140aa6d30()) != 0x620000c)
                    {
                        bFlag = false;
                        FUN_140aad6e0(FUN_140e800e0(), 0xcc);
                    }
                }
                if (bFlag)
                {
                    if (!FUN_140aad450(FUN_140e800e0()))
                        FUN_140aad6e0(FUN_140e800e0(), 200);
                }
            }
        }
        else if (uMsg == 0x466)
        {
            bool bHandled = false;
            if (FUN_140aa6d30() != 0 && FUN_140e800e0() != 0 && FUN_140aadf80() != 0)
            {
                if (FUN_140aacf50(FUN_140e800e0(), (unsigned)wParam))
                {
                    if (!FUN_140aad1e0(FUN_140e800e0()))
                        FUN_140aad340(FUN_140e800e0(), (unsigned)wParam);
                    bHandled = true;
                }
                if (FUN_140aad1e0(FUN_140e800e0()) == 1)
                {
                    int nKey = FUN_140aad2b0(FUN_140e800e0());
                    if (FUN_140aad2d0(FUN_140e800e0(), nKey))
                        bHandled = false;
                    if (FUN_140aad220(FUN_140e800e0()))
                    {
                        FUN_140aad5c0(FUN_140e800e0(), 0xc9);
                        bHandled = false;
                    }
                }
            }
            if (!bHandled)
                FUN_141b93a20((unsigned)wParam);
        }
        else if (uMsg == 0x467)
        {
            char bFlag = 0;
            if (FUN_140e800e0() != 0)
                bFlag = FUN_140aad1e0(FUN_140e800e0());
            if (bFlag == 0)
            {
                int nZero = 0;
                Unk_MsgBoxPtr box = FUN_140d74390(FUN_1408116a0(0x20e, nZero), 1, FUN_140b76b10(FUN_141902530));
                if (FUN_140d86260() != 0)
                    FUN_140d86260()->vfunc_58(0x20e, 0);
            }
            else
            {
                FUN_140aad6e0(FUN_140e800e0(), 200);
            }
        }
        else if (uMsg == 0x468)
        {
            if (FUN_140714f90() != 0)
                FUN_1415382c0(FUN_140714f90());
        }
        else if (uMsg == 0x469)
        {
            if (FUN_140714f90() != 0)
                FUN_141538540(FUN_140714f90());
        }
        else if (uMsg == 0x46a)
        {
            char bFlag = 0;
            if (FUN_140e800e0() != 0)
                bFlag = FUN_140aad1e0(FUN_140e800e0());
            if (FUN_140714f90() != 0)
                FUN_141538480(FUN_140714f90(), bFlag);
        }
    }
    if (FUN_140d86260() != 0)
        FUN_140d86260()->vfunc_19(uMsg);
    if (uMsg == 0xa1)
    {
        if (wParam == 0x14)
        {
            if (FUN_140aa6d30() != 0)
            {
                if (FUN_1417e2610(FUN_140aa6d30()) != 0x6200009)
                {
                    if (FUN_1417e2610(FUN_140aa6d30()) != 0x620000b)
                    {
                        FUN_140d73bc0(0x288, 0x17, 0, s_gameExit);
                        return 0;
                    }
                }
            }
            PostQuitMessage(0);
            return 0;
        }
        else
        {
            if (wParam == 8)
            {
                if (FUN_140aadf80() != 0)
                    PostMessageA(FUN_14209c720(FUN_140aadf80()), 0x112, 0xf020, 0);
                return 0;
            }
            if (wParam == 9)
                return 0;
        }
    }
    else if (0xa2 < uMsg && uMsg < 0xaa)
    {
        return 0;
    }
    if (uMsg == 0x201 || uMsg == 0x202 || uMsg == 0x203 || uMsg == 0x204 || uMsg == 0x205 || uMsg == 0x206 ||
        uMsg == 0x207 || uMsg == 0x208 || uMsg == 0x209 || uMsg == 0x20a || uMsg == 0x200 || uMsg == 0x2a3)
    {
        int nPosX = (int)(short)lParam;
        int nPosY = (int)(short)((unsigned __int64)lParam >> 16);
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
            nWheel = (int)(short)(wParam >> 16);
        unsigned bLeft = ((wParam & 1) != 0);
        unsigned bRight = ((wParam & 2) != 0);
        if (FUN_140aa6d30() != 0)
        {
            Unk_MouseTarget* pTarget = (Unk_MouseTarget*)static_cast<Unk_WinSceneView*>(FUN_140aa6d30())->FUN_1417e26d0().FUN_140f30a30();
            if (pTarget != 0)
                pTarget->vfunc_13(uMsg, nPosX, nPosY, bLeft, bRight, nWheel);
        }
    }
    if (uMsg < 0x101)
    {
        if (uMsg == 0x100)
        {
            if (wParam == 0x7b && (GetAsyncKeyState(0x11) & 0x8000) != 0 &&
                AfxMessageBox("Crash \xb8\xb8\xb5\xe9\xb1\xe2", 1, 0) == 1)
            {
                int nException = 0xd;
                throw nException;
            }
            if (wParam == 0x47 && (GetAsyncKeyState(0x11) & 0x8000) != 0 && FUN_14086d260() != 0)
            {
                ATL::CComPtr<Unk_ComObj> spObj(FUN_141296b50(FUN_140af8310(&FUN_14086d260()->m_holder)));
                if (static_cast<Unk_ComObj*>(spObj) == 0)
                    ;
                else
                    spObj->vfunc_16();
            }
        }
        else
        {
            switch (uMsg)
            {
            case 2:
            {
                NiDX9Renderer* pRenderer = FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, FUN_140d89bc0());
                if (pRenderer != 0)
                    FUN_1427d5390(pRenderer);
                PostQuitMessage(0);
                break;
            }
            case 3:
                GetWindowRect(hWnd, &g_rcWindow);
                break;
            case 6:
                if (DAT_143af7d44 != 0)
                    return 0;
                if (FUN_140d86260() != 0)
                    FUN_140d86260()->vfunc_71(wParam);
                if (wParam == 0 || 2 < wParam)
                {
                    if (g_bAppActive != 0)
                    {
                        NiDX9Renderer* pRenderer = FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, FUN_140d89bc0());
                        if (pRenderer != 0 && (pRenderer->GetCreationFlags() & 4) != 0)
                            FUN_1427d5390(pRenderer);
                        g_bAppActive = 0;
                        if (FUN_1409a8b10() != 0 && FUN_140c9cb10() != 0)
                        {
                            if (FUN_140d13c70(FUN_1409a8b10())[1] == 0)
                            {
                                FUN_1417ae840(FUN_140c9cb10(), 1);
                                if (FUN_140c8dac0() != 0)
                                    FUN_140d0a510(FUN_140c8dac0());
                            }
                        }
                        if (g_bHotkeyPrintScreen != 0)
                            UnregisterHotKey(hWnd, -2);
                        if (g_bHotkeyAltPrintScreen != 0)
                            UnregisterHotKey(hWnd, -1);
                        g_bHotkeyPrintScreen = 0;
                        g_bHotkeyAltPrintScreen = 0;
                    }
                }
                else if (g_bAppActive == 0)
                {
                    g_bAppActive = 1;
                    if (FUN_1409a8b10() != 0 && FUN_140c9cb10() != 0)
                    {
                        if (FUN_140d13c70(FUN_1409a8b10())[1] == 0)
                        {
                            FUN_1417ae840(FUN_140c9cb10(), 0);
                            if (FUN_140c8dac0() != 0)
                                FUN_140d0a560(FUN_140c8dac0());
                        }
                    }
                    g_143afa350 = 1;
                    if (g_bHotkeyPrintScreen == 0)
                        g_bHotkeyPrintScreen = RegisterHotKey(hWnd, -2, 0, 0x2c);
                    if (g_bHotkeyAltPrintScreen == 0)
                        g_bHotkeyAltPrintScreen = RegisterHotKey(hWnd, -1, 1, 0x2c);
                }
                break;
            case 0x10:
            {
                NiDX9Renderer* pRenderer = FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, FUN_140d89bc0());
                if (pRenderer != 0)
                    FUN_1427d5390(pRenderer);
                if (FUN_140aa6d30() != 0)
                {
                    if (FUN_1417e2610(FUN_140aa6d30()) != 0x6200009)
                    {
                        if (FUN_1417e2610(FUN_140aa6d30()) != 0x620000b)
                        {
                            FUN_140d73bc0(0x288, 0x17, 0, s_gameExit);
                            return 0;
                        }
                    }
                }
                break;
            }
            case 0x18:
                FUN_141b91a60();
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
        }
    }
    else if (uMsg == 0x101)
    {
        if (wParam == 0x2c)
        {
            if (g_bPrintScreenPending == 0 && FUN_1403ed2d0() != 0)
            {
                FUN_141bc9fd0(FUN_1403ed2d0(), 0x75);
                return 0;
            }
            g_bPrintScreenPending = 0;
        }
    }
    else if (uMsg == 0x112)
    {
        if (wParam == 0xf100)
            return 0;
    }
    else if (uMsg == 0x113)
    {
        if (wParam == 1000 && FUN_140aae430() != 0 && DAT_143af7d44 == 0)
        {
            int nLastInput = FUN_141489fb0(FUN_140aae430());
            unsigned nNow = FUN_140869420();
            if (nLastInput + 500U < nNow)
                FUN_141489f40(FUN_140aae430());
            static unsigned s_nLastPowerTick = FUN_140869420();
            unsigned nElapsed = nNow - s_nLastPowerTick;
            if (9999 < nElapsed)
            {
                FUN_141b938f0(1);
                s_nLastPowerTick = nNow;
            }
        }
    }
    else
    {
        if (uMsg == 0x281)
            return DefWindowProcA(hWnd, 0x281, wParam, 0);
        if (uMsg == 0x312 && (wParam == (WPARAM)-2 || wParam == (WPARAM)-1) && g_bPrintScreenPending == 0)
        {
            if (FUN_1403ed2d0() != 0)
                FUN_141bc9fd0(FUN_1403ed2d0(), 0x75);
            g_bPrintScreenPending = 1;
        }
    }
    __int64 nResult = FUN_141ade340(hWnd, uMsg, wParam, lParam);
    if (nResult == 0)
    {
        if (FUN_1414a56c0() != 0)
        {
            if (FUN_1414a56c0()->vfunc_18(hWnd, uMsg, wParam, lParam) != 0)
                return 0;
        }
        return DefWindowProcA(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

// @0x141b93470
efd::AsyncResult CWindowService::OnTick()
{
    if (FUN_140d86260()->vfunc_12() == 0)
    {
        if (GetWindowRef() != 0)
            FUN_140d86260()->vfunc_18(GetWindowRef());
    }
    return efd::AsyncResult_Complete;
}

// @0x141b934f0
// MS2-FUNCTIONAL: efd::utf8string accessors and CWnd::GetMenu are inlined differently than in the exe
BOOL CWindowService::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    RECT rc;
    rc.left = m_windowLeft;
    rc.top = m_windowTop;
    rc.right = m_windowWidth;
    rc.bottom = m_windowHeight;
    AdjustWindowRect(&rc, 0xca0000, FALSE);
    int nHeight = rc.bottom - rc.top;
    int nWidth = rc.right - rc.left;
    m_hWnd = CreateWindowExA(0, m_strWindowClass.c_str(), m_strWindowTitle.c_str(), 0xca0000, 0, 0, nWidth, nHeight, 0, 0,
                             hInstance, 0);
    if (m_hWnd == 0)
        return FALSE;
    CMenu* pMenu = CWnd::FromHandle((HWND)m_hWnd)->GetMenu();
    if (pMenu != 0)
        m_menu.Attach(pMenu->GetSafeHmenu());
    ShowWindow((HWND)m_hWnd, SW_HIDE);
    UpdateWindow((HWND)m_hWnd);
    SetTimer((HWND)m_hWnd, 1000, g_uTimerInterval, 0);
    return TRUE;
}

// @0x141b93740
// MS2-FUNCTIONAL: efd::utf8string accessors are inlined differently than in the exe
ATOM CWindowService::RegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXA wc;
    wc.cbSize = sizeof(WNDCLASSEXA);
    wc.style = 0xb;
    wc.lpfnWndProc = m_pWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    m_idLargeIcon = 2000;
    m_idSmallIcon = 2000;
    wc.hInstance = hInstance;
    if (m_idLargeIcon == 0)
        wc.hIcon = LoadIconA(hInstance, IDI_APPLICATION);
    else
        wc.hIcon = LoadIconA(hInstance, MAKEINTRESOURCEA((WORD)m_idLargeIcon));
    wc.hCursor = LoadCursorA(0, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = 0;
    wc.lpszClassName = m_strWindowClass.c_str();
    if (m_idSmallIcon == 0)
        wc.hIconSm = LoadIconA(hInstance, IDI_APPLICATION);
    else
        wc.hIconSm = LoadIconA(hInstance, MAKEINTRESOURCEA((WORD)m_idSmallIcon));
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
    FUN_141adbea0(FUN_1403ed2b0());
    FUN_140d73bc0(0xae, 0, 0, s_forceLogin);
    FUN_140d86260()->vfunc_58(0xae, nArg);
}

// @0x141b93aa0
void FUN_141b93aa0()
{
    FUN_141adbea0(FUN_1403ed2b0());
    FUN_140d73aa0(FUN_1408116a0(0x20f, 0), 0, 0, s_forceLogin);
    FUN_140d86260()->vfunc_58(0x20f, 0);
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
