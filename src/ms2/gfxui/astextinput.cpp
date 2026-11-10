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

CStringW XmlWide(const char* sz);                            // a UTF-8 string as a wide CString

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
void ASTextInput::AddTextInputHandler(const ASCallback& cb)
{
    FUN_1422c3600("textInput", cb, false, 0, 0, (void*)0);
}
MS2_REPLACE_METHOD(0x1422E0840, ASTextInput, AddTextInputHandler, 107, 0x5986C37A);

// @0x1422e08c0
void ASTextInput::RemoveTextInputHandler(const ASCallback& cb)
{
    FUN_1422c3820("textInput", cb, false);
}
MS2_REPLACE_METHOD(0x1422E08C0, ASTextInput, RemoveTextInputHandler, 82, 0xE1D7C22E);

// @0x1422e0920
void ASTextInput::AddChangeHandler(const ASCallback& cb)
{
    FUN_1422c3600("change", cb, false, 0, 0, (void*)0);
}
MS2_REPLACE_METHOD(0x1422E0920, ASTextInput, AddChangeHandler, 107, 0xDB00C72D);

// @0x1422e09a0
void ASTextInput::SetFocusable(int bFocusable)
{
    FUN_1407cbbe0("focusable", bFocusable != 0);
}
MS2_REPLACE_METHOD(0x1422E09A0, ASTextInput, SetFocusable, 60, 0x861540F4);

// @0x1422e09f0
int ASTextInput::GetFocusable()
{
    return GetMember("focusable").GetBool();
}
MS2_REPLACE_METHOD(0x1422E09F0, ASTextInput, GetFocusable, 91, 0x0236B36C);

// @0x1422e0a60
void ASTextInput::SetTextA(const CStringA& strText)
{
    FUN_1407cba60("text", strText);
}
MS2_REPLACE_METHOD(0x1422E0A60, ASTextInput, SetTextA, 72, 0xE12F8D12);

// @0x1422e0ab0
void ASTextInput::SetTextW(const CStringW& strText)
{
    FUN_1407cbb20("text", strText);
}
MS2_REPLACE_METHOD(0x1422E0AB0, ASTextInput, SetTextW, 72, 0x34312FD5);

// @0x1422e0b00
CStringW ASTextInput::GetText()
{
    return XmlWide(GetMember("text").GetString());
}
MS2_REPLACE_METHOD(0x1422E0B00, ASTextInput, GetText, 122, 0x3FE447E4);

// @0x1422e0b80
void ASTextInput::SetHtmlTextA(const CString& strHtml)
{
    FUN_1407cba60("htmlText", strHtml);
}
MS2_REPLACE_METHOD(0x1422E0B80, ASTextInput, SetHtmlTextA, 72, 0x41E8B1AD);

// @0x1422e0bd0
void ASTextInput::SetHtmlTextW(const CStringW& strHtml)
{
    FUN_1407cbb20("htmlText", strHtml);
}
MS2_REPLACE_METHOD(0x1422E0BD0, ASTextInput, SetHtmlTextW, 72, 0xA9D05A60);

// @0x1422e0c20
CStringW ASTextInput::GetHtmlText()
{
    return XmlWide(GetMember("htmlText").GetString());
}
MS2_REPLACE_METHOD(0x1422E0C20, ASTextInput, GetHtmlText, 122, 0xB38E2811);

// @0x1422e0ca0
void ASTextInput::SetDisplayAsPassword(int bPassword)
{
    FUN_1407cbbe0("displayAsPassword", bPassword != 0);
}
MS2_REPLACE_METHOD(0x1422E0CA0, ASTextInput, SetDisplayAsPassword, 60, 0xD9A25FD8);

// @0x1422e0cf0
int ASTextInput::GetDisplayAsPassword()
{
    return GetMember("displayAsPassword").GetBool();
}
MS2_REPLACE_METHOD(0x1422E0CF0, ASTextInput, GetDisplayAsPassword, 91, 0xC3CC33EA);

// @0x1422e0d60
void ASTextInput::SetMaxChars(int nMaxChars)
{
    SetMemberFloat("maxChars", (float)nMaxChars);
}
MS2_REPLACE_METHOD(0x1422E0D60, ASTextInput, SetMaxChars, 44, 0x42EED258);

// @0x1422e0da0
int ASTextInput::GetMaxChars()
{
    return GetMember("maxChars").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E0DA0, ASTextInput, GetMaxChars, 88, 0x557E07B7);

// @0x1422e0e00
void ASTextInput::SetEditable(int bEditable)
{
    FUN_1407cbbe0("editable", bEditable != 0);
}
MS2_REPLACE_METHOD(0x1422E0E00, ASTextInput, SetEditable, 60, 0x67084F97);

// @0x1422e0e50
int ASTextInput::GetEditable()
{
    return GetMember("editable").GetBool();
}
MS2_REPLACE_METHOD(0x1422E0E50, ASTextInput, GetEditable, 91, 0x1579A70B);

// @0x1422e0ec0
void ASTextInput::SetTabEnabled(int bEnabled)
{
    FUN_1407cbbe0("tabEnabled", bEnabled != 0);
}
MS2_REPLACE_METHOD(0x1422E0EC0, ASTextInput, SetTabEnabled, 60, 0x1C4FE222);

// @0x1422e0f10
int ASTextInput::GetTabEnabled()
{
    return GetMember("tabEnabled").GetBool();
}
MS2_REPLACE_METHOD(0x1422E0F10, ASTextInput, GetTabEnabled, 91, 0x852335CE);

// @0x1422e0f80
void ASTextInput::SetTabIndex(int nIndex)
{
    FUN_1407cbbe0("tabIndex", nIndex != 0);
}
MS2_REPLACE_METHOD(0x1422E0F80, ASTextInput, SetTabIndex, 60, 0xB60CBD41);

// @0x1422e0fd0
int ASTextInput::GetTabIndex()
{
    return GetMember("tabIndex").GetBool();
}
MS2_REPLACE_METHOD(0x1422E0FD0, ASTextInput, GetTabIndex, 91, 0xC18DC610);

// @0x1422e1040
void ASTextInput::SetActAsButton(int bActAsButton)
{
    FUN_1407cbbe0("actAsButton", bActAsButton != 0);
}
MS2_REPLACE_METHOD(0x1422E1040, ASTextInput, SetActAsButton, 60, 0xBD97A66E);

// @0x1422e1090
int ASTextInput::GetActAsButton()
{
    return GetMember("actAsButton").GetBool();
}
MS2_REPLACE_METHOD(0x1422E1090, ASTextInput, GetActAsButton, 91, 0x5D0D871B);

// @0x1422e1100
void ASTextInput::SetAlwaysShowSelection(int bAlways)
{
    FUN_1407cbbe0("alwaysShowSelection", bAlways != 0);
}
MS2_REPLACE_METHOD(0x1422E1100, ASTextInput, SetAlwaysShowSelection, 60, 0xBB9932B2);

// @0x1422e1150
int ASTextInput::GetAlwaysShowSelection()
{
    return GetMember("alwaysShowSelection").GetBool();
}
MS2_REPLACE_METHOD(0x1422E1150, ASTextInput, GetAlwaysShowSelection, 91, 0xDD9D497A);

// @0x1422e11c0
void ASTextInput::SetRestrict(const CString& strRestrict)
{
    GetTextField()->SetRestrict(strRestrict);
}
MS2_REPLACE_METHOD(0x1422E11C0, ASTextInput, SetRestrict, 92, 0x14F1B453);

// @0x1422e1230
CString ASTextInput::GetRestrict()
{
    return GetTextField()->GetRestrict();
}
MS2_REPLACE_METHOD(0x1422E1230, ASTextInput, GetRestrict, 115, 0xEE2E454F);

// @0x1422e12b0
int ASTextInput::GetLength()
{
    return GetMember("length").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E12B0, ASTextInput, GetLength, 88, 0x7CFECEAD);

// @0x1422e1310
void ASTextInput::AppendTextA(const CString& strText)
{
    Invoke("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422E1310, ASTextInput, AppendTextA, 87, 0x3FD4D47D);

// @0x1422e1370
void ASTextInput::AppendTextW(const CStringW& strText)
{
    Invoke("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422E1370, ASTextInput, AppendTextW, 87, 0xCB27F55E);

// @0x1422e13d0
void ASTextInput::AppendHtmlA(const CString& strHtml)
{
    Invoke("appendHtml", strHtml);
}
MS2_REPLACE_METHOD(0x1422E13D0, ASTextInput, AppendHtmlA, 87, 0x35DEF906);

// @0x1422e1430
void ASTextInput::AppendHtmlW(const CStringW& strHtml)
{
    Invoke("appendHtml", strHtml);
}
MS2_REPLACE_METHOD(0x1422E1430, ASTextInput, AppendHtmlW, 87, 0xFCBDD19D);

// @0x1422e1490
MS2Ptr<ASTextField> ASTextInput::GetTextField()
{
    return FUN_1409b4620("textField");
}
MS2_REPLACE_METHOD(0x1422E1490, ASTextInput, GetTextField, 102, 0xD6FCC66F);

// @0x1422e1500
void ASTextInput::FocusAndSetSelection(int nBegin, int nEnd)
{
    if (!GetFocused())
        SetFocused(1);
    vfunc_24(true);
    GetTextField()->SetSelection(nBegin, nEnd);
}
MS2_REPLACE_METHOD(0x1422E1500, ASTextInput, FocusAndSetSelection, 150, 0x62B5C952);

// MS2-PIN: ??_GASTextInput@@UEAAPEAXI@Z 0x1422e15a0
