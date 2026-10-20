// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovieMouseCursor, the GFx movie of the mouse cursor layer.
// MS2-UNIT: ?\gfxmoviemousecursor.cpp
// MS2-RANGE: 0x1422f2600-0x1422f30b0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in gfxmoviemousecursor.h. The obj's COMDAT tail is the ASMouseCursor factory 0x1422f2f30 with its
// MS2Ptr<ASMouseCursor> ctor / move ctor, the scalar deleting dtor and vfunc_2.
#include "ms2/placeholder/ms2stdafx.h"
#include <windowsx.h>

#include "gfxmoviemousecursor.h"
#include "ms2/placeholder/asmousecursor.h"
#include "ms2/placeholder/gfxservice.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

MS2Ptr<ASUIComponent> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);   // wrap an AS object in an ASUIComponent

// @0x1422f2600
GFxMovieMouseCursor::GFxMovieMouseCursor()
    : m_90(0)
{
    m_18 = 6;
}

// @0x1422f2660
GFxMovieMouseCursor::~GFxMovieMouseCursor()
{
    if (m_90.get())
        m_90 = 0;
}

// @0x1422f26e0
void GFxMovieMouseCursor::vfunc_11()
{
    if (m_90.get())
        m_90 = 0;
    GFxMovieEventHandler::vfunc_11();
}
MS2_REPLACE_METHOD(0x1422F26E0, GFxMovieMouseCursor, vfunc_11, 69, 0xDA8A286A);

// @0x1422f2730
void GFxMovieMouseCursor::vfunc_3(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (m_30 == 0)
        return;
    if (_stricmp("fireCursorEvent", szEvent) == 0) {
        if (nArgs > 0) {
            Scaleform::GFx::Value v(pArgs[0]);
            m_30->Invoke("fireCursorEvent", v);
        }
    } else if (_stricmp("setText", szEvent) == 0) {
        if (nArgs > 0) {
            Scaleform::GFx::Value v(pArgs[0]);
            m_30->Invoke("setText", v);
        }
    } else if (_stricmp("fireCursorMouseEvent", szEvent) == 0) {
        if (nArgs > 0 && pArgs[0].IsString()) {
            Scaleform::GFx::Value v;
            m_60->CreateString(&v, pArgs[0].GetString());
            m_30->Invoke("fireCursorMouseEvent", v);
        }
    }
}
MS2_REPLACE_METHOD(0x1422F2730, GFxMovieMouseCursor, vfunc_3, 781, 0x52AEA28B);

// @0x1422f2a50
void GFxMovieMouseCursor::vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (_stricmp("initializeClass", szEvent) == 0) {
        if (nArgs > 1) {
            Scaleform::GFx::Value vRoot(pArgs[0]);
            Scaleform::GFx::Value vCursor(pArgs[1]);
            m_90 = FUN_140acca70(m_18, vRoot);
            MS2Ptr<ASMouseCursor> spCursor = FUN_1422f2f30(m_18, vCursor);
            if (spCursor)
                FUN_1422be560(spCursor);
        }
    }
}
MS2_REPLACE_METHOD(0x1422F2A50, GFxMovieMouseCursor, vfunc_4, 374, 0x3351ABBD);

// @0x1422f2bd0
int GFxMovieMouseCursor::vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    switch (msg) {
    case WM_SIZE:
        vfunc_16();
        return 1;
        break;
    case WM_MOUSEHOVER: {
        float x = (float)(short)LOWORD(lParam);
        float y = (float)(short)HIWORD(lParam);
        vfunc_27(hwnd, x, y);
        break;
    }
    case WM_MOUSELEAVE: {
        float x = (float)(short)LOWORD(lParam);
        float y = (float)(short)HIWORD(lParam);
        vfunc_28(hwnd, x, y);
        break;
    }
    case WM_ENTERIDLE:
        vfunc_23(hwnd);
        break;
    case WM_NCMOUSEMOVE: {
        float x = (float)(short)LOWORD(lParam);
        float y = (float)(short)HIWORD(lParam);
        vfunc_29(hwnd, x, y);
        break;
    }
    case WM_ENABLE:
        vfunc_22(hwnd);
        break;
    case WM_MOUSEMOVE: {
        float x = (float)(short)LOWORD(lParam);
        float y = (float)(short)HIWORD(lParam);
        vfunc_26(hwnd, x, y);
        return 1;
    }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422F2BD0, GFxMovieMouseCursor, vfunc_14, 606, 0x49EE5E44);

// @0x1422f2e40
void GFxMovieMouseCursor::vfunc_5(bool b)
{
    GFxService* pService = FUN_1414a56c0();
    if (pService == 0)
        return;
    if (!pService->FUN_1422ea2a0())
        GFxMovie::vfunc_5(b);
}
MS2_REPLACE_METHOD(0x1422F2E40, GFxMovieMouseCursor, vfunc_5, 70, 0x7FD0DBD6);

// @0x1422f2e90
void GFxMovieMouseCursor::vfunc_19(void* hwnd)
{
    if (m_30)
        m_30->FUN_1422cecb0(1);
}
MS2_REPLACE_METHOD(0x1422F2E90, GFxMovieMouseCursor, vfunc_19, 71, 0xC37F33BE);

// @0x1422f2ee0
void GFxMovieMouseCursor::vfunc_20(void* hwnd)
{
    if (m_30)
        m_30->FUN_1422cecb0(2);
}
MS2_REPLACE_METHOD(0x1422F2EE0, GFxMovieMouseCursor, vfunc_20, 71, 0x1E03A8FF);

// @0x1422f2f30
MS2Ptr<ASMouseCursor> FUN_1422f2f30(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASMouseCursor> sp(new ASMouseCursor(v, nMovieId));
    return sp;
}

// MS2-PIN: ??_GGFxMovieMouseCursor@@UEAAPEAXI@Z 0x1422f3040
// MS2-PIN: ?vfunc_2@GFxMovieMouseCursor@@UEAAPEAXXZ 0x1422f30a0
// MS2-PIN: ??0?$MS2Ptr@VASMouseCursor@@@@QEAA@$$QEAV0@@Z 0x1422f2fe0
// MS2-PIN: ??0?$MS2Ptr@VASMouseCursor@@@@QEAA@PEAVASMouseCursor@@@Z 0x1422f3010
