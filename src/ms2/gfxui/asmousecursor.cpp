// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASMouseCursor, the ActionScript mouse cursor clip of the GFx UI library.
// MS2-UNIT: ?\asmousecursor.cpp
// MS2-RANGE: 0x1422ceb80-0x1422cf290 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings; the
// MS2_THIS_FILE below is only needed by ms2recover.h and never emitted). The class is declared in
// src/ms2/placeholder/asmousecursor.h. The obj's COMDAT tail holds the Invoke(method, cursor type) instance 0x1422cef80,
// the scalar deleting dtor, the render helpers of gfxrenderhelpers.h 0x1422cf060-0x1422cf120 (their caller in this obj
// was dropped by /OPT:REF; written here as plain functions) and the CRT memmove_s copy 0x1422cf170.
#define MS2_THIS_FILE "asmousecursor.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asmousecursor.h"
#include "ms2/placeholder/gfxrenderhelpers.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The int Value setter of the Invoke argument lists (a COMDAT of ASArray's obj).
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// @0x1422ceb80
ASMouseCursor::ASMouseCursor(const Scaleform::GFx::Value& v, int nMovieId)
    : ASGameEntity(v, nMovieId)
{
    m_bDisabled = 0;
    m_nMode = 0;
}

// @0x1422cebf0
ASMouseCursor::~ASMouseCursor()
{
}

// @0x1422cec40
void ASMouseCursor::FUN_1422cec40(int bShow)
{
    if (bShow != 0) {
        int nMode = m_nMode;
        m_nMode = 0;
        FUN_1422cecb0(nMode);
    } else {
        while (ShowCursor(FALSE) >= 0) {
        }
        vfunc_3(0);
    }
}
MS2_REPLACE_METHOD(0x1422CEC40, ASMouseCursor, FUN_1422cec40, 103, 0x74716333);

// @0x1422cecb0
void ASMouseCursor::FUN_1422cecb0(int nMode)
{
    if (m_nMode == nMode)
        return;
    if (m_bDisabled != 0) {
        while (ShowCursor(TRUE) < 0) {
        }
        vfunc_3(0);
    } else {
        if (nMode == 2) {
            while (ShowCursor(TRUE) < 0) {
            }
            vfunc_3(0);
            m_nMode = nMode;
        } else if (nMode == 1) {
            CURSORINFO info;
            info.cbSize = sizeof(info);
            if (GetCursorInfo(&info) && info.flags == CURSOR_SHOWING) {
                while (ShowCursor(FALSE) >= 0) {
                }
                vfunc_3(1);
                m_nMode = nMode;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422CECB0, ASMouseCursor, FUN_1422cecb0, 240, 0x6AD91E82);

// @0x1422cedb0
void ASMouseCursor::FUN_1422cedb0()
{
    if (m_bDisabled != 0)
        return;
    Invoke("lock");
}
MS2_REPLACE_METHOD(0x1422CEDB0, ASMouseCursor, FUN_1422cedb0, 62, 0xFCF37239);

// @0x1422cee00
void ASMouseCursor::FUN_1422cee00()
{
    if (m_bDisabled != 0)
        return;
    Invoke("unlock");
}
MS2_REPLACE_METHOD(0x1422CEE00, ASMouseCursor, FUN_1422cee00, 62, 0xDA4ED8B6);

// @0x1422cee50
void ASMouseCursor::FUN_1422cee50(Unk_MouseCursorType eType)
{
    if (m_bDisabled != 0)
        return;
    Invoke("changeType", eType);
}
MS2_REPLACE_METHOD(0x1422CEE50, ASMouseCursor, FUN_1422cee50, 71, 0x133479F8);

// @0x1422ceea0
void ASMouseCursor::FUN_1422ceea0(const CStringW& strText)
{
    if (m_bDisabled != 0)
        return;
    Invoke("setText", strText);
}
MS2_REPLACE_METHOD(0x1422CEEA0, ASMouseCursor, FUN_1422ceea0, 103, 0x0D3A4B38);

// @0x1422cef10
int ASMouseCursor::FUN_1422cef10()
{
    if (m_bDisabled != 0)
        return 0;
    return Invoke("getCursorType").GetInt();
}
MS2_REPLACE_METHOD(0x1422CEF10, ASMouseCursor, FUN_1422cef10, 106, 0x5A62D2A9);

// @0x1422cef80
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Unk_MouseCursorType a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- gfxrenderhelpers.h (not hooked: inline COMDATs in the exe) ----

// @0x1422cf060
Unk_GFxUIHal* FUN_1422cf060()
{
    return FUN_1422cf080()->FUN_1425822a0();
}

// @0x1422cf080
Unk_GFxUIRenderer2D* FUN_1422cf080()
{
    return FUN_14025e7a0()->FUN_1422b02b0();
}

// @0x1422cf0a0
NiDX9Renderer* FUN_1422cf0a0()
{
    return NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
}

// @0x1422cf0d0
LPDIRECT3DDEVICE9 FUN_1422cf0d0()
{
    return FUN_1422cf0a0()->GetD3DDevice();
}

// @0x1422cf0f0
void* FUN_1422cf0f0()
{
    return FUN_1422cf060()->vfunc_52();
}

// @0x1422cf120
int FUN_1422cf120()
{
    if (FUN_1422cf0d0()->TestCooperativeLevel() == D3DERR_DEVICELOST)
        return 1;
    if (FUN_1414a56c0()->FUN_141b47780())
        return 1;
    return 0;
}

// @0x1422cf170
MS2_EMIT_CRT_MEMMOVE_S();

// MS2-PIN: ??_GASMouseCursor@@UEAAPEAXI@Z 0x1422cf020
