// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTextInput, the CLIK TextInput wrapper of the GFx UI library.
// MS2-UNIT: ?\astextinput.cpp
// MS2-RANGE: 0x1422e07c0-0x1422e15e0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/astextinput.h. The int setters write the AS member as a Boolean ("tabIndex"
// included, as the exe does); "maxChars" is set as a Number. The range ends at the GfxException ctor 0x1422e15e0
// (?\gfxexception.cpp).
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astextinput.h"

#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

CStringW FUN_1408767c0(const char* sz);                            // a UTF-8 string as a wide CString

// @0x1422e07c0
ASTextInput::ASTextInput(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1422e0810
ASTextInput::~ASTextInput()
{
}

// @0x1422e0840
void ASTextInput::FUN_1422e0840(const ASCallback& cb)
{
    FUN_1422c3600("textInput", cb, false, 0, 0, (void*)0);
}
MS2_REPLACE_METHOD(0x1422E0840, ASTextInput, FUN_1422e0840, 107, 0x5986C37A);

// @0x1422e08c0
void ASTextInput::FUN_1422e08c0(const ASCallback& cb)
{
    FUN_1422c3820("textInput", cb, false);
}
MS2_REPLACE_METHOD(0x1422E08C0, ASTextInput, FUN_1422e08c0, 82, 0xE1D7C22E);

// @0x1422e0920
void ASTextInput::FUN_1422e0920(const ASCallback& cb)
{
    FUN_1422c3600("change", cb, false, 0, 0, (void*)0);
}
MS2_REPLACE_METHOD(0x1422E0920, ASTextInput, FUN_1422e0920, 107, 0xDB00C72D);

// @0x1422e09a0
void ASTextInput::FUN_1422e09a0(int bFocusable)
{
    FUN_1407cbbe0("focusable", bFocusable != 0);
}
MS2_REPLACE_METHOD(0x1422E09A0, ASTextInput, FUN_1422e09a0, 60, 0x861540F4);

// @0x1422e09f0
int ASTextInput::FUN_1422e09f0()
{
    return FUN_1422baa20("focusable").GetBool();
}
MS2_REPLACE_METHOD(0x1422E09F0, ASTextInput, FUN_1422e09f0, 91, 0x0236B36C);

// @0x1422e0a60
void ASTextInput::FUN_1422e0a60(const CStringA& strText)
{
    FUN_1407cba60("text", strText);
}
MS2_REPLACE_METHOD(0x1422E0A60, ASTextInput, FUN_1422e0a60, 72, 0xE12F8D12);

// @0x1422e0ab0
void ASTextInput::FUN_1422e0ab0(const CStringW& strText)
{
    FUN_1407cbb20("text", strText);
}
MS2_REPLACE_METHOD(0x1422E0AB0, ASTextInput, FUN_1422e0ab0, 72, 0x34312FD5);

// @0x1422e0b00
CStringW ASTextInput::FUN_1422e0b00()
{
    return FUN_1408767c0(FUN_1422baa20("text").GetString());
}
MS2_REPLACE_METHOD(0x1422E0B00, ASTextInput, FUN_1422e0b00, 122, 0x3FE447E4);

// @0x1422e0b80
void ASTextInput::FUN_1422e0b80(const CString& strHtml)
{
    FUN_1407cba60("htmlText", strHtml);
}
MS2_REPLACE_METHOD(0x1422E0B80, ASTextInput, FUN_1422e0b80, 72, 0x41E8B1AD);

// @0x1422e0bd0
void ASTextInput::FUN_1422e0bd0(const CStringW& strHtml)
{
    FUN_1407cbb20("htmlText", strHtml);
}
MS2_REPLACE_METHOD(0x1422E0BD0, ASTextInput, FUN_1422e0bd0, 72, 0xA9D05A60);

// @0x1422e0c20
CStringW ASTextInput::FUN_1422e0c20()
{
    return FUN_1408767c0(FUN_1422baa20("htmlText").GetString());
}
MS2_REPLACE_METHOD(0x1422E0C20, ASTextInput, FUN_1422e0c20, 122, 0xB38E2811);

// @0x1422e0ca0
void ASTextInput::FUN_1422e0ca0(int bPassword)
{
    FUN_1407cbbe0("displayAsPassword", bPassword != 0);
}
MS2_REPLACE_METHOD(0x1422E0CA0, ASTextInput, FUN_1422e0ca0, 60, 0xD9A25FD8);

// @0x1422e0cf0
int ASTextInput::FUN_1422e0cf0()
{
    return FUN_1422baa20("displayAsPassword").GetBool();
}
MS2_REPLACE_METHOD(0x1422E0CF0, ASTextInput, FUN_1422e0cf0, 91, 0xC3CC33EA);

// @0x1422e0d60
void ASTextInput::FUN_1422e0d60(int nMaxChars)
{
    FUN_1409c4a30("maxChars", (float)nMaxChars);
}
MS2_REPLACE_METHOD(0x1422E0D60, ASTextInput, FUN_1422e0d60, 44, 0x42EED258);

// @0x1422e0da0
int ASTextInput::FUN_1422e0da0()
{
    return FUN_1422baa20("maxChars").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E0DA0, ASTextInput, FUN_1422e0da0, 88, 0x557E07B7);

// @0x1422e0e00
void ASTextInput::FUN_1422e0e00(int bEditable)
{
    FUN_1407cbbe0("editable", bEditable != 0);
}
MS2_REPLACE_METHOD(0x1422E0E00, ASTextInput, FUN_1422e0e00, 60, 0x67084F97);

// @0x1422e0e50
int ASTextInput::FUN_1422e0e50()
{
    return FUN_1422baa20("editable").GetBool();
}
MS2_REPLACE_METHOD(0x1422E0E50, ASTextInput, FUN_1422e0e50, 91, 0x1579A70B);

// @0x1422e0ec0
void ASTextInput::FUN_1422e0ec0(int bEnabled)
{
    FUN_1407cbbe0("tabEnabled", bEnabled != 0);
}
MS2_REPLACE_METHOD(0x1422E0EC0, ASTextInput, FUN_1422e0ec0, 60, 0x1C4FE222);

// @0x1422e0f10
int ASTextInput::FUN_1422e0f10()
{
    return FUN_1422baa20("tabEnabled").GetBool();
}
MS2_REPLACE_METHOD(0x1422E0F10, ASTextInput, FUN_1422e0f10, 91, 0x852335CE);

// @0x1422e0f80
void ASTextInput::FUN_1422e0f80(int nIndex)
{
    FUN_1407cbbe0("tabIndex", nIndex != 0);
}
MS2_REPLACE_METHOD(0x1422E0F80, ASTextInput, FUN_1422e0f80, 60, 0xB60CBD41);

// @0x1422e0fd0
int ASTextInput::FUN_1422e0fd0()
{
    return FUN_1422baa20("tabIndex").GetBool();
}
MS2_REPLACE_METHOD(0x1422E0FD0, ASTextInput, FUN_1422e0fd0, 91, 0xC18DC610);

// @0x1422e1040
void ASTextInput::FUN_1422e1040(int bActAsButton)
{
    FUN_1407cbbe0("actAsButton", bActAsButton != 0);
}
MS2_REPLACE_METHOD(0x1422E1040, ASTextInput, FUN_1422e1040, 60, 0xBD97A66E);

// @0x1422e1090
int ASTextInput::FUN_1422e1090()
{
    return FUN_1422baa20("actAsButton").GetBool();
}
MS2_REPLACE_METHOD(0x1422E1090, ASTextInput, FUN_1422e1090, 91, 0x5D0D871B);

// @0x1422e1100
void ASTextInput::FUN_1422e1100(int bAlways)
{
    FUN_1407cbbe0("alwaysShowSelection", bAlways != 0);
}
MS2_REPLACE_METHOD(0x1422E1100, ASTextInput, FUN_1422e1100, 60, 0xBB9932B2);

// @0x1422e1150
int ASTextInput::FUN_1422e1150()
{
    return FUN_1422baa20("alwaysShowSelection").GetBool();
}
MS2_REPLACE_METHOD(0x1422E1150, ASTextInput, FUN_1422e1150, 91, 0xDD9D497A);

// @0x1422e11c0
void ASTextInput::FUN_1422e11c0(const CString& strRestrict)
{
    FUN_1422e1490()->FUN_1422c5710(strRestrict);
}
MS2_REPLACE_METHOD(0x1422E11C0, ASTextInput, FUN_1422e11c0, 92, 0x14F1B453);

// @0x1422e1230
CString ASTextInput::FUN_1422e1230()
{
    return FUN_1422e1490()->FUN_1422c5760();
}
MS2_REPLACE_METHOD(0x1422E1230, ASTextInput, FUN_1422e1230, 115, 0xEE2E454F);

// @0x1422e12b0
int ASTextInput::FUN_1422e12b0()
{
    return FUN_1422baa20("length").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E12B0, ASTextInput, FUN_1422e12b0, 88, 0x7CFECEAD);

// @0x1422e1310
void ASTextInput::FUN_1422e1310(const CString& strText)
{
    Invoke("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422E1310, ASTextInput, FUN_1422e1310, 87, 0x3FD4D47D);

// @0x1422e1370
void ASTextInput::FUN_1422e1370(const CStringW& strText)
{
    Invoke("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422E1370, ASTextInput, FUN_1422e1370, 87, 0xCB27F55E);

// @0x1422e13d0
void ASTextInput::FUN_1422e13d0(const CString& strHtml)
{
    Invoke("appendHtml", strHtml);
}
MS2_REPLACE_METHOD(0x1422E13D0, ASTextInput, FUN_1422e13d0, 87, 0x35DEF906);

// @0x1422e1430
void ASTextInput::FUN_1422e1430(const CStringW& strHtml)
{
    Invoke("appendHtml", strHtml);
}
MS2_REPLACE_METHOD(0x1422E1430, ASTextInput, FUN_1422e1430, 87, 0xFCBDD19D);

// @0x1422e1490
MS2Ptr<ASTextField> ASTextInput::FUN_1422e1490()
{
    return FUN_1409b4620("textField");
}
MS2_REPLACE_METHOD(0x1422E1490, ASTextInput, FUN_1422e1490, 102, 0xD6FCC66F);

// @0x1422e1500
void ASTextInput::FUN_1422e1500(int nBegin, int nEnd)
{
    if (!FUN_1422c76c0())
        FUN_1422c7630(1);
    vfunc_24(true);
    FUN_1422e1490()->FUN_1422c5cf0(nBegin, nEnd);
}
MS2_REPLACE_METHOD(0x1422E1500, ASTextInput, FUN_1422e1500, 150, 0x62B5C952);

// MS2-PIN: ??_GASTextInput@@UEAAPEAXI@Z 0x1422e15a0
