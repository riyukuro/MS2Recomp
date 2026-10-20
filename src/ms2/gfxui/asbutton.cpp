// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASButton, the ActionScript button wrapper of the GFx UI library.
// MS2-UNIT: ?\asbutton.cpp
// MS2-RANGE: 0x1422cdda0-0x1422ce4b0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asbutton.h (shared; Ghidra's FUN_<va> names are kept there). Every accessor
// reads or writes one member of the AS Button object ("autoRepeat", "isHtml", "label", "selected", "toggle", "valign")
// or adds / removes an event listener ("buttonClick", "select").
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asbutton.h"

#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

CStringW FUN_14016a730(const char* sz, int nCodePage);         // a multi-byte text as a wide string (commonfiles/packet.h)
CString FUN_1409a23d0(const char* sz, int nCodePage);          // a text as a CString (code page 0)
CString FUN_1422e51c0(int nAlign);                             // the AS name of a vertical alignment ("top", ...)

// @0x1422cdda0
ASButton::ASButton()
    : ASUIComponent(2)
{
}

// @0x1422cdde0
ASButton::ASButton(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1422cde30
ASButton::~ASButton()
{
}

// @0x1422cde60
void ASButton::FUN_1422cde60(int bAutoRepeat)
{
    FUN_1407cbbe0("autoRepeat", bAutoRepeat != 0);
}
MS2_REPLACE_METHOD(0x1422CDE60, ASButton, FUN_1422cde60, 60, 0x5AFD8831);

// @0x1422cdeb0
int ASButton::FUN_1422cdeb0()
{
    return FUN_1422baa20("autoRepeat").GetBool();
}
MS2_REPLACE_METHOD(0x1422CDEB0, ASButton, FUN_1422cdeb0, 91, 0x47F5C858);

// @0x1422cdf20
void ASButton::FUN_1422cdf20(bool bVisible)
{
    FUN_1407cbbe0("isHtml", bVisible);
}
MS2_REPLACE_METHOD(0x1422CDF20, ASButton, FUN_1422cdf20, 41, 0x5FB9899A);

// @0x1422cdf50
void ASButton::FUN_1422cdf50(const CString& strLabel)
{
    FUN_1407cbb20("label", FUN_14016a730(strLabel, 0));
}
MS2_REPLACE_METHOD(0x1422CDF50, ASButton, FUN_1422cdf50, 83, 0xB97C8B92);

// @0x1422cdfb0
void ASButton::FUN_1422cdfb0(const CStringW& strText)
{
    FUN_1407cbb20("label", strText);
}
MS2_REPLACE_METHOD(0x1422CDFB0, ASButton, FUN_1422cdfb0, 72, 0x5AA699A2);

// @0x1422ce000
CString ASButton::FUN_1422ce000()
{
    return FUN_1409a23d0(FUN_1422baa20("label").GetString(), 0);
}
MS2_REPLACE_METHOD(0x1422CE000, ASButton, FUN_1422ce000, 125, 0x18300678);

// @0x1422ce090
void ASButton::FUN_1422ce090(int bSelected)
{
    FUN_1407cbbe0("selected", bSelected != 0);
}
MS2_REPLACE_METHOD(0x1422CE090, ASButton, FUN_1422ce090, 60, 0x0539AE61);

// @0x1422ce0e0
bool ASButton::FUN_1422ce0e0()
{
    return FUN_1422baa20("selected").GetBool();
}
MS2_REPLACE_METHOD(0x1422CE0E0, ASButton, FUN_1422ce0e0, 89, 0xD14A87FE);

// @0x1422ce140
void ASButton::FUN_1422ce140(int bToggle)
{
    FUN_1407cbbe0("toggle", bToggle != 0);
}
MS2_REPLACE_METHOD(0x1422CE140, ASButton, FUN_1422ce140, 60, 0x7875B4EC);

// @0x1422ce190
bool ASButton::FUN_1422ce190()
{
    return FUN_1422baa20("toggle").GetBool();
}
MS2_REPLACE_METHOD(0x1422CE190, ASButton, FUN_1422ce190, 89, 0xC524C4EF);

// @0x1422ce1f0
void ASButton::FUN_1422ce1f0(int nMode)
{
    FUN_1407cba60("valign", FUN_1422e51c0(nMode));
}
MS2_REPLACE_METHOD(0x1422CE1F0, ASButton, FUN_1422ce1f0, 69, 0xF7814A72);

// @0x1422ce240
void ASButton::FUN_1422ce240(const ASCallback& onClick, void* pUser)
{
    FUN_1422c3600("buttonClick", onClick, false, 0, 0, pUser);
}
// not hooked: FUN_1422ce240 is overloaded in asbutton.h (int / void* user value), MS2_REPLACE_METHOD needs a unique name

// @0x1422ce2c0
void ASButton::FUN_1422ce2c0(const ASCallback& onClick)
{
    FUN_1422c3820("buttonClick", onClick, false);
}
MS2_REPLACE_METHOD(0x1422CE2C0, ASButton, FUN_1422ce2c0, 82, 0xE370F22A);

// @0x1422ce320
void ASButton::FUN_1422ce320(const ASCallback& onSelect, void* pUser)
{
    FUN_1422c3600("select", onSelect, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422CE320, ASButton, FUN_1422ce320, 113, 0xC56355E2);

// @0x1422ce3a0
void ASButton::FUN_1422ce3a0(const ASCallback& onSelect)
{
    FUN_1422c3820("select", onSelect, false);
}
MS2_REPLACE_METHOD(0x1422CE3A0, ASButton, FUN_1422ce3a0, 82, 0x08521630);

// @0x1422ce400
MS2Ptr<ASTextField> ASButton::FUN_1422ce400()
{
    return FUN_1409b4620("textField");
}
MS2_REPLACE_METHOD(0x1422CE400, ASButton, FUN_1422ce400, 102, 0x205DB9BE);

// MS2-PIN: ??_GASButton@@UEAAPEAXI@Z 0x1422ce470
