// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTextFieldEx, the wrapper of the "scaleform.gfx.TextFieldEx"
// AS helper class (vertical alignment and auto-size of text fields).
// MS2-UNIT: ?\astextfieldex.cpp
// MS2-RANGE: 0x1422e4fd0-0x1422e5300 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: the ctor 0x1422e4fd0 follows ASLabel's obj; ASLoader's ctor starts the next obj at 0x1422e5300. The
// alignment/auto-size name statics (none/top/center/bottom and "shrink") are this TU's, but their dynamic initializers
// are kept in unit_14013acc0 (the .text$di run), so they are bound here as externs.
#include "ms2/placeholder/ms2stdafx.h"

#include "astextfieldex.h"

#include "hook/ms2hook.h"

extern CString DAT_143b0d330;                                           // "none"
extern CString DAT_143b0d338;                                           // "top"
extern CString DAT_143b0d340;                                           // "center"
extern CString DAT_143b0d348;                                           // "bottom"

// @0x1422e4fd0
ASTextFieldEx::ASTextFieldEx(const Scaleform::GFx::Value v, int nMovieId)
    : AScript(v, nMovieId)
{
}

// @0x1422e5030
ASTextFieldEx::~ASTextFieldEx()
{
}

// @0x1422e5060
void ASTextFieldEx::SetVerticalAlign(const Scaleform::GFx::Value& target, int nAlign)
{
    FUN_141a46b60("setVerticalAlign", target, GetVerticalAlignName(nAlign));
}
MS2_REPLACE_METHOD(0x1422E5060, ASTextFieldEx, SetVerticalAlign, 167, 0xFDA85E29);

// @0x1422e5110
void ASTextFieldEx::SetTextAutoSize(const Scaleform::GFx::Value& target, const CString& strMode)
{
    FUN_141a46b60("setTextAutoSize", target, strMode);
}
MS2_REPLACE_METHOD(0x1422E5110, ASTextFieldEx, SetTextAutoSize, 169, 0x1BC7F7F9);

// @0x1422e51c0
CString ASTextFieldEx::GetVerticalAlignName(int nAlign)
{
    switch (nAlign)
    {
    case 0:
        return DAT_143b0d330;
        break;
    case 1:
        return DAT_143b0d338;
        break;
    case 2:
        return DAT_143b0d340;
        break;
    case 3:
        return DAT_143b0d348;
        break;
    }
    return "";
}
MS2_REPLACE(0x1422E51C0, ASTextFieldEx::GetVerticalAlignName, 248, 0xB093819A);

// MS2-PIN: ??_GASTextFieldEx@@UEAAPEAXI@Z 0x1422e52c0
