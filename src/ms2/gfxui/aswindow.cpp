// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASWindow, the ActionScript window wrapper of the GFx UI
// library (the base of ASDialog).
// MS2-UNIT: ?\aswindow.cpp
// MS2-RANGE: 0x1422e6170-0x1422e63e0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/aswindow.h (shared with ASDialog).
#include "ms2/placeholder/ms2stdafx.h"

#include <math.h>

#include "ms2/placeholder/aswindow.h"

#include "hook/ms2hook.h"

extern "C" double (__cdecl* __imp_ceil)(double);              // the exe imports ceil from the UCRT

// @0x1422e6170
ASWindow::ASWindow(const Scaleform::GFx::Value& v, int nMovieId)
    : ASGameEntity(v, nMovieId)
{
}

// @0x1422e61c0
ASWindow::~ASWindow()
{
}

// @0x1422e61f0
void ASWindow::FUN_1422e61f0(int bEnable)
{
    Invoke("setTopMostEnable", bEnable);
}
MS2_REPLACE_METHOD(0x1422E61F0, ASWindow, FUN_1422e61f0, 55, 0xFA12FBAB);

// @0x1422e6230
void ASWindow::FUN_1422e6230(int bCanDrag)
{
    Invoke("setCanDrag", bCanDrag);
}
MS2_REPLACE_METHOD(0x1422E6230, ASWindow, FUN_1422e6230, 55, 0xF721A3F4);

// @0x1422e6270
int ASWindow::FUN_1422e6270()
{
    Scaleform::GFx::Value v = Invoke("getWindowHeight");
    if (v.IsUndefined() || v.IsNull())
        return 0;
    return (int)__imp_ceil(v.GetNumber());
}
MS2_REPLACE_METHOD(0x1422E6270, ASWindow, FUN_1422e6270, 142, 0x776610A0);

// @0x1422e6310
int ASWindow::FUN_1422e6310()
{
    Scaleform::GFx::Value v = Invoke("getWindowWidth");
    if (v.IsUndefined() || v.IsNull())
        return 0;
    return (int)__imp_ceil(v.GetNumber());
}
MS2_REPLACE_METHOD(0x1422E6310, ASWindow, FUN_1422e6310, 142, 0x36950EA9);

// MS2-PIN: ??_GASWindow@@UEAAPEAXI@Z 0x1422e63a0
