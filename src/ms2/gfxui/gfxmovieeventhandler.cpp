// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovieEventHandler, the base of the GFx movies that
// take Win32 input: it turns the window messages into GFx mouse/key/char/IME events of the movie (m_60) and keeps the
// window in the clipboard viewer chain (the clipboard text is copied into the GFx text clipboard). The key and
// modifier handling is the Scaleform SDK's Platform_WinAPI.cpp AppImpl code (processKey/updateModifiers/KeyCodeMap).
// See ms2/placeholder/gfxmovie.h.
// MS2-UNIT: ?\gfxmovieeventhandler.cpp
// MS2-RANGE: 0x1422d8dc0-0x1422db480 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"
#include <windowsx.h>
#include <imm.h>
#include <NiRenderTargetGroup.h>
#include <ecr/RenderSurface.h>

#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/gfxmanager.h"
#include "hook/ms2hook.h"

#pragma comment(lib, "imm32.lib")

extern char DAT_143b059e8;                                      // the entity app framework
void* FUN_14127bf80(void* pFramework);                          // its render service (null if none)
ecr::RenderSurface* FUN_140af7da0(ecr::RenderService* pService);  // the service's default surface

// Windows virtual key -> Scaleform key code for the keys outside the A-Z/F1-F15/0-9/numpad ranges (the SDK's
// Platform_XInput.h KeyCodeMap without VK_SNAPSHOT; 0x143a290e0).
static struct
{
    WPARAM winKey;
    Scaleform::KeyCode appKey;
} KeyCodeMap[] =
{
    {VK_BACK,    Scaleform::Key::Backspace},
    {VK_TAB,     Scaleform::Key::Tab},
    {VK_CLEAR,   Scaleform::Key::Clear},
    {VK_RETURN,  Scaleform::Key::Return},
    {VK_SHIFT,   Scaleform::Key::Shift},
    {VK_CONTROL, Scaleform::Key::Control},
    {VK_MENU,    Scaleform::Key::Alt},
    {VK_PAUSE,   Scaleform::Key::Pause},
    {VK_CAPITAL, Scaleform::Key::CapsLock},
    {VK_ESCAPE,  Scaleform::Key::Escape},
    {VK_SPACE,   Scaleform::Key::Space},
    {VK_PRIOR,   Scaleform::Key::PageUp},
    {VK_NEXT,    Scaleform::Key::PageDown},
    {VK_END,     Scaleform::Key::End},
    {VK_HOME,    Scaleform::Key::Home},
    {VK_LEFT,    Scaleform::Key::Left},
    {VK_UP,      Scaleform::Key::Up},
    {VK_RIGHT,   Scaleform::Key::Right},
    {VK_DOWN,    Scaleform::Key::Down},
    {VK_INSERT,  Scaleform::Key::Insert},
    {VK_DELETE,  Scaleform::Key::Delete},
    {VK_HELP,    Scaleform::Key::Help},
    {VK_NUMLOCK, Scaleform::Key::NumLock},
    {VK_SCROLL,  Scaleform::Key::ScrollLock},

    {VK_OEM_1,     Scaleform::Key::Semicolon},
    {VK_OEM_PLUS,  Scaleform::Key::Equal},
    {VK_OEM_COMMA, Scaleform::Key::Comma},
    {VK_OEM_MINUS, Scaleform::Key::Minus},
    {VK_OEM_PERIOD,Scaleform::Key::Period},
    {VK_OEM_2,     Scaleform::Key::Slash},
    {VK_OEM_3,     Scaleform::Key::Bar},
    {VK_OEM_4,     Scaleform::Key::BracketLeft},
    {VK_OEM_5,     Scaleform::Key::Backslash},
    {VK_OEM_6,     Scaleform::Key::BracketRight},
    {VK_OEM_7,     Scaleform::Key::Quote},
    {VK_OEM_AX,    Scaleform::Key::OEM_AX},
    {VK_OEM_102,   Scaleform::Key::OEM_102},
    {VK_ICO_HELP,  Scaleform::Key::ICO_HELP},
    {VK_ICO_00,    Scaleform::Key::ICO_00},
    // Terminator
    {0,            Scaleform::Key::None}
};

bool GFxMovieEventHandler::ms_bImeEnabled = true;

// @0x1422d8dc0
GFxMovieEventHandler::GFxMovieEventHandler()
{
    m_80 = 0;
    m_84 = 0;
    m_88 = 0;
}

// @0x1422d8e20
GFxMovieEventHandler::~GFxMovieEventHandler()
{
    m_80 = 0;
    m_84 = 0;
    m_88 = 0;
}

// @0x1422d8e80
int GFxMovieEventHandler::FUN_1422d8e80(void* hwnd)
{
    m_88 = SetClipboardViewer((HWND)hwnd);
    if (m_88 == hwnd)
        m_88 = 0;
    return m_88 != 0;
}
MS2_REPLACE_METHOD(0x1422D8E80, GFxMovieEventHandler, FUN_1422d8e80, 114, 0xA9C1F361);

// @0x1422d8f00
void GFxMovieEventHandler::FUN_1422d8f00(CStringW strText)
{
    Scaleform::Ptr<Scaleform::GFx::TextClipboard> spClipboard = m_58->GetTextClipboard();
    if (spClipboard)
        spClipboard->SetText(strText);
}
MS2_REPLACE_METHOD(0x1422D8F00, GFxMovieEventHandler, FUN_1422d8f00, 135, 0x496A8081);

// @0x1422d8f90
void GFxMovieEventHandler::FUN_1422d8f90(void* hwnd)
{
    if (m_88 == 0)
        ChangeClipboardChain((HWND)hwnd, (HWND)m_88);
}
MS2_REPLACE_METHOD(0x1422D8F90, GFxMovieEventHandler, FUN_1422d8f90, 57, 0x214238EB);

// @0x1422d8fd0
void GFxMovieEventHandler::FUN_1422d8fd0(const CStringW& strText)
{
    FUN_1422d8f00(strText);
}
MS2_REPLACE_METHOD(0x1422D8FD0, GFxMovieEventHandler, FUN_1422d8fd0, 65, 0x270113FE);

// @0x1422d9020
void GFxMovieEventHandler::FUN_1422d9020(bool bEnable)
{
    ms_bImeEnabled = bEnable;
}

// @0x1422d9040
int GFxMovieEventHandler::vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        FUN_1422d8f90(hwnd);
        break;
    case WM_SETFOCUS:
        vfunc_17(hwnd);
        break;
    case WM_KILLFOCUS:
        vfunc_18(hwnd);
        break;
    case WM_SIZE:
        vfunc_16();
        return 1;
        break;
    case WM_MOUSEHOVER:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            vfunc_27(hwnd, x, y);
        }
        break;
    case WM_MOUSELEAVE:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            vfunc_28(hwnd, x, y);
        }
        break;
    case WM_ENTERIDLE:
        vfunc_23(hwnd);
        break;
    case WM_NCMOUSEMOVE:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            vfunc_29(hwnd, x, y);
        }
        break;
    case WM_ENABLE:
        vfunc_22(hwnd);
        break;
    case WM_MOUSEMOVE:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            vfunc_26(hwnd, x, y);
            return 1;
        }
        break;
    case WM_MOUSEWHEEL:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            float fDelta = (float)GET_WHEEL_DELTA_WPARAM(wParam);
            POINT pt = {0, 0};
            ClientToScreen((HWND)hwnd, &pt);
            vfunc_30(hwnd, x - pt.x, y - pt.y, fDelta > 0.0f ? 1.0f : -1.0f);
            return 1;
        }
        break;
    case WM_LBUTTONUP:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            ReleaseCapture();
            vfunc_31(hwnd, x, y);
            return 1;
        }
        break;
    case WM_LBUTTONDOWN:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            SetCapture((HWND)hwnd);
            vfunc_32(hwnd, x, y);
            return 1;
        }
        break;
    case WM_LBUTTONDBLCLK:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            vfunc_33(hwnd, x, y);
            return 1;
        }
        break;
    case WM_RBUTTONUP:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            ReleaseCapture();
            vfunc_34(hwnd, x, y);
        }
        break;
    case WM_RBUTTONDOWN:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            SetCapture((HWND)hwnd);
            vfunc_35(hwnd, x, y);
        }
        break;
    case WM_RBUTTONDBLCLK:
        {
            float x = (float)GET_X_LPARAM(lParam);
            float y = (float)GET_Y_LPARAM(lParam);
            vfunc_36(hwnd, x, y);
        }
        break;
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    case WM_KEYDOWN:
    case WM_KEYUP:
        if (vfunc_38(hwnd, msg, wParam, lParam))
            return 1;
        break;
    case WM_CHAR:
        // the KeyModifiers byte goes in vfunc_39's bool slot (see gfxmovie.h)
        vfunc_39(0, Scaleform::Key::None, (unsigned)wParam, true,
                 *(const bool*)&static_cast<const Scaleform::KeyModifiers&>(UpdateModifiers(false)));
        break;
    case WM_IME_STARTCOMPOSITION:
    case WM_IME_ENDCOMPOSITION:
    case WM_IME_NOTIFY:
    case WM_INPUTLANGCHANGE:
    case WM_IME_CHAR:
    case WM_IME_KEYDOWN:
        if (vfunc_37(hwnd, msg, (void*)wParam, (void*)lParam))
            return 1;
        break;
    case WM_IME_COMPOSITION:
        if (FUN_14025e7a0()->FUN_1422af390(m_18))
            return 1;
        if (vfunc_37(hwnd, msg, (void*)wParam, (void*)lParam))
            return 1;
        break;
    case WM_DRAWCLIPBOARD:
        vfunc_24(hwnd);
        break;
    case WM_CHANGECBCHAIN:
        vfunc_25(hwnd, wParam, lParam);
        break;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422D9040, GFxMovieEventHandler, vfunc_14, 2429, 0xFD56D2C8);

// @0x1422d9c30
int GFxMovieEventHandler::vfunc_15(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    if (!ms_bImeEnabled)
        return 0;
    if (!m_60)
        return 0;
    bool imeUIMsg = (ImmIsUIMessageA(NULL, msg, wParam, lParam) == 0) ? FALSE : TRUE;
    if ((msg == WM_KEYDOWN) || (msg == WM_KEYUP) || imeUIMsg
        || (msg == WM_LBUTTONDOWN) || (msg == WM_LBUTTONUP))
    {
        Scaleform::GFx::IMEWin32Event kEvent(Scaleform::GFx::IMEEvent::IME_PreProcessKeyboard, (Scaleform::UPInt)hwnd,
                                             msg, wParam, lParam, 0);
        unsigned nResult = m_60->HandleEvent(kEvent);
        return (nResult & Scaleform::GFx::Movie::HE_NoDefaultAction) != 0;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422D9C30, GFxMovieEventHandler, vfunc_15, 366, 0x9B20B1D1);

// @0x1422d9db0
void GFxMovieEventHandler::vfunc_16()
{
    void* pService = FUN_14127bf80(&DAT_143b059e8);
    if (pService != 0)
    {
        NiRenderTargetGroup* pTarget = FUN_140af7da0((ecr::RenderService*)pService)->GetRenderTargetGroup();
        if (pTarget != 0)
            vfunc_7(pTarget->GetWidth(0), pTarget->GetHeight(0));
    }
}
MS2_REPLACE_METHOD(0x1422D9DB0, GFxMovieEventHandler, vfunc_16, 162, 0xD54A7F2A);

// @0x1422d9e60
void GFxMovieEventHandler::vfunc_17(void* hwnd)
{
    m_60->HandleEvent(Scaleform::GFx::SetFocusEvent(UpdateModifiers(false)));
}
MS2_REPLACE_METHOD(0x1422D9E60, GFxMovieEventHandler, vfunc_17, 132, 0x9131E574);

// @0x1422d9ef0
void GFxMovieEventHandler::vfunc_18(void* hwnd)
{
    Scaleform::GFx::Event kEvent(Scaleform::GFx::Event::KillFocus);
    m_60->HandleEvent(kEvent);
}
MS2_REPLACE_METHOD(0x1422D9EF0, GFxMovieEventHandler, vfunc_18, 80, 0xD4896A37);

// @0x1422d9f50
void GFxMovieEventHandler::vfunc_11()
{
    GFxMovie::vfunc_11();
    FUN_1422d8f90(m_88);
}
MS2_REPLACE_METHOD(0x1422D9F50, GFxMovieEventHandler, vfunc_11, 46, 0xF3006939);

// @0x1422d9f90
void GFxMovieEventHandler::vfunc_19(void* hwnd)
{
}
MS2_REPLACE_METHOD(0x1422D9F90, GFxMovieEventHandler, vfunc_19, 11, 0x02239C70);

// @0x1422d9fb0
void GFxMovieEventHandler::vfunc_20(void* hwnd)
{
}
MS2_REPLACE_METHOD(0x1422D9FB0, GFxMovieEventHandler, vfunc_20, 11, 0x02239C70);

// @0x1422d9fd0
void GFxMovieEventHandler::vfunc_21(void* hwnd)
{
    vfunc_19(hwnd);
    m_80 = GetTickCount();
}
MS2_REPLACE_METHOD(0x1422D9FD0, GFxMovieEventHandler, vfunc_21, 60, 0x0778A12A);

// @0x1422da020
void GFxMovieEventHandler::vfunc_22(void* hwnd)
{
    vfunc_20(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA020, GFxMovieEventHandler, vfunc_22, 43, 0xF9F24265);

// @0x1422da060
void GFxMovieEventHandler::vfunc_23(void* hwnd)
{
    vfunc_20(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA060, GFxMovieEventHandler, vfunc_23, 43, 0xF9F24265);

// @0x1422da0a0
void GFxMovieEventHandler::vfunc_24(void* hwnd)
{
    if (!IsClipboardFormatAvailable(CF_UNICODETEXT))
        return;
    if (!OpenClipboard((HWND)hwnd))
        return;
    HANDLE hMem = GetClipboardData(CF_UNICODETEXT);
    if (hMem != NULL)
    {
        const wchar_t* szText = (const wchar_t*)GlobalLock(hMem);
        if (szText != NULL)
        {
            FUN_1422d8f00(CStringW(szText));
            GlobalUnlock(hMem);
        }
    }
    CloseClipboard();
}
MS2_REPLACE_METHOD(0x1422DA0A0, GFxMovieEventHandler, vfunc_24, 167, 0xB8BA8C68);

// @0x1422da150
void GFxMovieEventHandler::vfunc_25(void* hwnd, unsigned __int64 wParam, __int64 lParam)
{
    if ((void*)wParam == m_88)
        m_88 = (void*)lParam;
    else if (m_88 != 0 && hwnd != m_88)
        SendMessageA((HWND)m_88, WM_CHANGECBCHAIN, wParam, lParam);
}
MS2_REPLACE_METHOD(0x1422DA150, GFxMovieEventHandler, vfunc_25, 134, 0x9B8DEA44);

// @0x1422da1e0
void GFxMovieEventHandler::vfunc_26(void* hwnd, float x, float y)
{
    if (m_84 == 0)
    {
        TRACKMOUSEEVENT tme;
        tme.cbSize = sizeof(tme);
        tme.hwndTrack = (HWND)hwnd;
        tme.dwFlags = TME_HOVER | TME_LEAVE;
        tme.dwHoverTime = HOVER_DEFAULT;
        TrackMouseEvent(&tme);
    }
    Scaleform::GFx::MouseEvent kEvent(Scaleform::GFx::Event::MouseMove, 0, x, y);
    m_60->HandleEvent(kEvent);
    vfunc_21(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA1E0, GFxMovieEventHandler, vfunc_26, 243, 0x6792CF2C);

// @0x1422da2e0
void GFxMovieEventHandler::vfunc_27(void* hwnd, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DA2E0, GFxMovieEventHandler, vfunc_27, 23, 0xAB83DBEC);

// @0x1422da300
void GFxMovieEventHandler::vfunc_28(void* hwnd, float x, float y)
{
    vfunc_20(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA300, GFxMovieEventHandler, vfunc_28, 55, 0x5FA71D19);

// @0x1422da340
void GFxMovieEventHandler::vfunc_29(void* hwnd, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DA340, GFxMovieEventHandler, vfunc_29, 23, 0xAB83DBEC);

// @0x1422da360
void GFxMovieEventHandler::vfunc_30(void* hwnd, float x, float y, float fDelta)
{
    Scaleform::GFx::MouseEvent kEvent(Scaleform::GFx::Event::MouseWheel, 0, x, y, fDelta);
    m_60->HandleEvent(kEvent);
    vfunc_21(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA360, GFxMovieEventHandler, vfunc_30, 178, 0xDF628708);

// @0x1422da420
void GFxMovieEventHandler::vfunc_31(void* hwnd, float x, float y)
{
    Scaleform::GFx::MouseEvent kEvent(Scaleform::GFx::Event::MouseUp, 0, x, y);
    m_60->HandleEvent(kEvent);
    vfunc_21(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA420, GFxMovieEventHandler, vfunc_31, 172, 0x5C31013B);

// @0x1422da4e0
void GFxMovieEventHandler::vfunc_32(void* hwnd, float x, float y)
{
    Scaleform::GFx::MouseEvent kEvent(Scaleform::GFx::Event::MouseDown, 0, x, y);
    m_60->HandleEvent(kEvent);
    vfunc_21(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA4E0, GFxMovieEventHandler, vfunc_32, 172, 0x4C486499);

// @0x1422da5a0
void GFxMovieEventHandler::vfunc_33(void* hwnd, float x, float y)
{
    Scaleform::GFx::MouseEvent kEvent(Scaleform::GFx::Event::MouseDown, 0, x, y);
    m_60->HandleEvent(kEvent);
    vfunc_21(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA5A0, GFxMovieEventHandler, vfunc_33, 172, 0x73489389);

// @0x1422da660
void GFxMovieEventHandler::vfunc_34(void* hwnd, float x, float y)
{
    Scaleform::GFx::MouseEvent kEvent(Scaleform::GFx::Event::MouseUp, 1, x, y);
    m_60->HandleEvent(kEvent);
    vfunc_21(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA660, GFxMovieEventHandler, vfunc_34, 175, 0x72251E8D);

// @0x1422da720
void GFxMovieEventHandler::vfunc_35(void* hwnd, float x, float y)
{
    Scaleform::GFx::MouseEvent kEvent(Scaleform::GFx::Event::MouseDown, 1, x, y);
    m_60->HandleEvent(kEvent);
    vfunc_21(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA720, GFxMovieEventHandler, vfunc_35, 175, 0x3FB6A8D0);

// @0x1422da7e0
void GFxMovieEventHandler::vfunc_36(void* hwnd, float x, float y)
{
    Scaleform::GFx::MouseEvent kEvent(Scaleform::GFx::Event::MouseDown, 1, x, y);
    m_60->HandleEvent(kEvent);
    vfunc_21(hwnd);
}
MS2_REPLACE_METHOD(0x1422DA7E0, GFxMovieEventHandler, vfunc_36, 175, 0xE9D4FB8F);

// @0x1422da8a0
int GFxMovieEventHandler::vfunc_37(void* hwnd, int n, void* a, void* b)
{
    Scaleform::GFx::IMEWin32Event kEvent(Scaleform::GFx::IMEEvent::IME_Default, (Scaleform::UPInt)hwnd, n,
                                         (Scaleform::UPInt)a, (Scaleform::UPInt)b, 1);
    unsigned nResult = m_60->HandleEvent(kEvent);
    return (nResult & Scaleform::GFx::Movie::HE_NoDefaultAction) != 0;
}
MS2_REPLACE_METHOD(0x1422DA8A0, GFxMovieEventHandler, vfunc_37, 183, 0xABB80DE4);

// @0x1422da960
int GFxMovieEventHandler::vfunc_38(void* hwnd, int n, unsigned __int64 wParam, __int64 lParam)
{
    bool bDown = (n == WM_KEYDOWN || n == WM_SYSKEYDOWN) ? true : false;
    Scaleform::UInt8 scanCode = (Scaleform::UInt8)((lParam >> 16) & 0xff);
    bool bExtendedKey = (lParam & (1 << 24)) != 0;
    // the right shift key has scan code 54
    if (wParam == VK_SHIFT && scanCode == 54)
        bExtendedKey = true;
    ProcessKey((unsigned)wParam, bDown, bExtendedKey);
    if (n == WM_SYSKEYDOWN || n == WM_SYSKEYUP)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1422DA960, GFxMovieEventHandler, vfunc_38, 210, 0x1C0C0C97);

// @0x1422daa40
void GFxMovieEventHandler::vfunc_39(int a, int b, int c, bool d, bool e)
{
    if (!m_60)
        return;
    if (b == 0 && c != 0)
    {
        if (FUN_14025e7a0()->FUN_1422af2d0(m_18))
        {
            Scaleform::GFx::CharEvent kEvent(c, 0);
            m_60->HandleEvent(kEvent);
        }
    }
    SendKeyEvent(a, b, c, d, (Scaleform::KeyModifiers&)e);
}
MS2_REPLACE_METHOD(0x1422DAA40, GFxMovieEventHandler, vfunc_39, 205, 0x25CE190B);

// @0x1422dab20
void GFxMovieEventHandler::ProcessKey(unsigned vkCode, bool bDown, bool bExtendedKey)
{
    Scaleform::KeyCode kc = Scaleform::Key::None;

    if (vkCode >= 'A' && vkCode <= 'Z')
    {
        kc = (Scaleform::KeyCode)((vkCode - 'A') + Scaleform::Key::A);
    }
    else if (vkCode >= VK_F1 && vkCode <= VK_F15)
    {
        kc = (Scaleform::KeyCode)((vkCode - VK_F1) + Scaleform::Key::F1);
    }
    else if (vkCode >= '0' && vkCode <= '9')
    {
        kc = (Scaleform::KeyCode)((vkCode - '0') + Scaleform::Key::Num0);
    }
    else if (vkCode >= VK_NUMPAD0 && vkCode <= VK_DIVIDE)
    {
        kc = (Scaleform::KeyCode)((vkCode - VK_NUMPAD0) + Scaleform::Key::KP_0);
    }
    else
    {
        for (int i = 0; KeyCodeMap[i].winKey != 0; i++)
        {
            if (vkCode == (unsigned)KeyCodeMap[i].winKey)
            {
                kc = KeyCodeMap[i].appKey;
                break;
            }
        }
    }

    vfunc_39(0, kc, 0, bDown,
             *(const bool*)&static_cast<const Scaleform::KeyModifiers&>(UpdateModifiers(bExtendedKey)));
}
MS2_REPLACE_METHOD(0x1422DAB20, GFxMovieEventHandler, ProcessKey, 310, 0xD27FCE3C);

// @0x1422dac60
void GFxMovieEventHandler::SendKeyEvent(int nKeyboard, int nKeyCode, unsigned nWchar, bool bDown,
                                         Scaleform::KeyModifiers kMods)
{
    if (!m_60)
        return;
    if (nKeyCode == Scaleform::Key::Insert && FUN_14025e7a0()->FUN_1422af2d0(m_18))
        return;
    if (nKeyCode != 0)
    {
        Scaleform::GFx::KeyEvent kEvent(bDown ? Scaleform::GFx::Event::KeyDown : Scaleform::GFx::Event::KeyUp,
                                        (Scaleform::KeyCode)nKeyCode, 0, nWchar, kMods, (Scaleform::UInt8)nKeyboard);
        m_60->HandleEvent(kEvent);
    }
}
MS2_REPLACE_METHOD(0x1422DAC60, GFxMovieEventHandler, SendKeyEvent, 254, 0xCE516423);

// @0x1422dad70
Scaleform::KeyModifiers GFxMovieEventHandler::UpdateModifiers(bool bExtendedKey)
{
    Scaleform::KeyModifiers mods;
    if (::GetKeyState(VK_SHIFT) & 0x8000)
        mods.SetShiftPressed(true);
    if (::GetKeyState(VK_CONTROL) & 0x8000)
        mods.SetCtrlPressed(true);
    if (::GetKeyState(VK_MENU) & 0x8000)
        mods.SetAltPressed(true);
    if (::GetKeyState(VK_NUMLOCK) & 0x1)
        mods.SetNumToggled(true);
    if (::GetKeyState(VK_CAPITAL) & 0x1)
        mods.SetCapsToggled(true);
    if (::GetKeyState(VK_SCROLL) & 0x1)
        mods.SetScrollToggled(true);
    if (bExtendedKey)
        mods.SetExtendedKey(true);
    m_54 = mods;
    return mods;
}
MS2_REPLACE_METHOD(0x1422DAD70, GFxMovieEventHandler, UpdateModifiers, 277, 0xD486D132);

// MS2-PIN: ??_GGFxMovieEventHandler@@UEAAPEAXI@Z 0x1422db0b0
