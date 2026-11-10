// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTextField, the ActionScript TextField wrapper of the GFx UI
// library.
// MS2-UNIT: ?\astextfield.cpp
// MS2-RANGE: 0x1422c4c00-0x1422c6100 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/astextfield.h. The tail 0x1422c5f80-0x1422c6100 is the GFx::Value
// GetText/GetTextHTML/SetText/SetTextHTML inline COMDATs of the Scaleform headers.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astextfield.h"

#include "hook/ms2hook.h"

using Scaleform::GFx::Value;

CString FUN_14016a600(const wchar_t* psz, int n);                   // a wide string as UTF-8
CStringW XmlWide(const char* sz);                             // a UTF-8 string as a wide CString
CString FUN_1409a23d0(const char* sz, int n);                       // a UTF-8 string as a CString
CStringW Unk_ArcWide(const wchar_t* psz, int n);                  // a wide string as a CString
void FUN_1422bccb0(Value* pValue, int n);                           // set an Int value
void SetString(Value* pValue, const char* psz);                 // set a String value

// @0x1422c4c00
ASTextField::ASTextField(const Value& v, int nMovieId)
    : ASInteractiveObject(v, nMovieId)
{
}

// @0x1422c4c50
ASTextField::~ASTextField()
{
}

// @0x1422c4c80
void ASTextField::SetTextA(const CString& strText)
{
    GetValue().SetText(strText);
}
MS2_REPLACE_METHOD(0x1422C4C80, ASTextField, SetTextA, 61, 0xE4942A47);

// @0x1422c4cd0
void ASTextField::SetTextW(const CStringW& strText)
{
    GetValue().SetText(strText);
}
MS2_REPLACE_METHOD(0x1422C4CD0, ASTextField, SetTextW, 61, 0x9903C860);

// @0x1422c4d20
CString ASTextField::GetTextA()
{
    return FUN_14016a600(GetTextW(), 0);
}
MS2_REPLACE_METHOD(0x1422C4D20, ASTextField, GetTextA, 120, 0x91918A67);

// @0x1422c4da0
CStringW ASTextField::GetTextW()
{
    Value v;
    if (GetValue().GetText(&v))
    {
        if (v.IsString())
            return XmlWide(v.GetString());
        if (v.IsStringW())
            return Unk_ArcWide(v.GetStringW(), 0);
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1422C4DA0, ASTextField, GetTextW, 264, 0x98304C6D);

// @0x1422c4eb0
void ASTextField::SetTextHTMLA(const CString& strText)
{
    GetValue().SetTextHTML(strText);
}
MS2_REPLACE_METHOD(0x1422C4EB0, ASTextField, SetTextHTMLA, 61, 0xAF866D5D);

// @0x1422c4f00
void ASTextField::SetTextHTMLW(const CStringW& strText)
{
    GetValue().SetTextHTML(strText);
}
MS2_REPLACE_METHOD(0x1422C4F00, ASTextField, SetTextHTMLW, 61, 0xC299544E);

// @0x1422c4f50
CString ASTextField::GetTextHTMLA()
{
    return FUN_14016a600(GetTextHTMLW(), 0);
}
MS2_REPLACE_METHOD(0x1422C4F50, ASTextField, GetTextHTMLA, 120, 0x34FEC111);

// @0x1422c4fd0
CStringW ASTextField::GetTextHTMLW()
{
    Value v;
    if (GetValue().GetTextHTML(&v))
    {
        if (v.IsString())
            return XmlWide(v.GetString());
        if (v.IsStringW())
            return Unk_ArcWide(v.GetStringW(), 0);
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1422C4FD0, ASTextField, GetTextHTMLW, 264, 0x1C267731);

// @0x1422c50e0
void ASTextField::SetTextColor(unsigned int nColor)
{
    SetMemberUInt("textColor", nColor);
}
MS2_REPLACE_METHOD(0x1422C50E0, ASTextField, SetTextColor, 40, 0x839BCDCD);

// @0x1422c5110
unsigned int ASTextField::GetTextColor()
{
    return GetMember("textColor").GetUInt();
}
MS2_REPLACE_METHOD(0x1422C5110, ASTextField, GetTextColor, 88, 0x832C249C);

// @0x1422c5170
void ASTextField::SetMaxChars(int nMaxChars)
{
    SetIntMember("maxChars", nMaxChars);
}
MS2_REPLACE_METHOD(0x1422C5170, ASTextField, SetMaxChars, 40, 0xAFB9804F);

// @0x1422c51a0
int ASTextField::GetMaxChars()
{
    return GetMember("maxChars").GetInt();
}
MS2_REPLACE_METHOD(0x1422C51A0, ASTextField, GetMaxChars, 88, 0xEA80715C);

// @0x1422c5200
void ASTextField::SetMultiline(int bMultiline)
{
    SetBoolMember("multiline", bMultiline != 0);
}
MS2_REPLACE_METHOD(0x1422C5200, ASTextField, SetMultiline, 60, 0x195876E7);

// @0x1422c5250
int ASTextField::GetMultiline()
{
    return GetMember("multiline").GetBool();
}
MS2_REPLACE_METHOD(0x1422C5250, ASTextField, GetMultiline, 91, 0xFE82D2D3);

// @0x1422c52c0
void ASTextField::SetSelectable(int bSelectable)
{
    SetBoolMember("selectable", bSelectable != 0);
}
MS2_REPLACE_METHOD(0x1422C52C0, ASTextField, SetSelectable, 60, 0xA6D0D30B);

// @0x1422c5310
int ASTextField::GetSelectable()
{
    return GetMember("selectable").GetBool();
}
MS2_REPLACE_METHOD(0x1422C5310, ASTextField, GetSelectable, 91, 0xBF1D2E51);

// @0x1422c5380
void ASTextField::SetCaretIndex(int nIndex)
{
    SetIntMember("caretIndex", nIndex);
}
MS2_REPLACE_METHOD(0x1422C5380, ASTextField, SetCaretIndex, 40, 0x23842660);

// @0x1422c53b0
int ASTextField::GetCaretIndex()
{
    return GetMember("caretIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422C53B0, ASTextField, GetCaretIndex, 88, 0xF2C211FC);

// @0x1422c5410
void ASTextField::SetEmbedFonts(int bEmbed)
{
    SetBoolMember("embedFonts", bEmbed != 0);
}
MS2_REPLACE_METHOD(0x1422C5410, ASTextField, SetEmbedFonts, 60, 0x719A42F7);

// @0x1422c5460
int ASTextField::GetEmbedFonts()
{
    return GetMember("embedFonts").GetBool();
}
MS2_REPLACE_METHOD(0x1422C5460, ASTextField, GetEmbedFonts, 91, 0x37D62B23);

// @0x1422c54d0
void ASTextField::SetDisplayAsPassword(int bPassword)
{
    SetBoolMember("displayAsPassword", bPassword != 0);
}
MS2_REPLACE_METHOD(0x1422C54D0, ASTextField, SetDisplayAsPassword, 60, 0xE6E1A2E3);

// @0x1422c5520
int ASTextField::GetDisplayAsPassword()
{
    return GetMember("displayAsPassword").GetBool();
}
MS2_REPLACE_METHOD(0x1422C5520, ASTextField, GetDisplayAsPassword, 91, 0x44A77CED);

// @0x1422c5590
void ASTextField::SetUseRichTextClipboard(int bRich)
{
    SetBoolMember("useRichTextClipboard", bRich != 0);
}
MS2_REPLACE_METHOD(0x1422C5590, ASTextField, SetUseRichTextClipboard, 60, 0xD6FD35D3);

// @0x1422c55e0
int ASTextField::GetUseRichTextClipboard()
{
    return GetMember("useRichTextClipboard").GetBool();
}
MS2_REPLACE_METHOD(0x1422C55E0, ASTextField, GetUseRichTextClipboard, 91, 0x8799CAC5);

// @0x1422c5650
void ASTextField::SetMouseWheelEnabled(int bEnabled)
{
    SetBoolMember("mouseWheelEnabled", bEnabled != 0);
}
MS2_REPLACE_METHOD(0x1422C5650, ASTextField, SetMouseWheelEnabled, 60, 0xA757D84F);

// @0x1422c56a0
int ASTextField::GetMouseWheelEnabled()
{
    return GetMember("mouseWheelEnabled").GetBool();
}
MS2_REPLACE_METHOD(0x1422C56A0, ASTextField, GetMouseWheelEnabled, 91, 0x672000D3);

// @0x1422c5710
void ASTextField::SetRestrict(const CString& strRestrict)
{
    SetStringMember("restrict", strRestrict);
}
MS2_REPLACE_METHOD(0x1422C5710, ASTextField, SetRestrict, 72, 0x7997D9A1);

// @0x1422c5760
CString ASTextField::GetRestrict()
{
    return FUN_1409a23d0(GetMember("restrict").GetString(), 0);
}
MS2_REPLACE_METHOD(0x1422C5760, ASTextField, GetRestrict, 125, 0xD125DBC8);

// @0x1422c57f0
int ASTextField::GetLength()
{
    return GetMember("length").GetInt();
}
MS2_REPLACE_METHOD(0x1422C57F0, ASTextField, GetLength, 88, 0xA94234E0);

// @0x1422c5850
int ASTextField::GetNumLines()
{
    return GetMember("numLines").GetInt();
}
MS2_REPLACE_METHOD(0x1422C5850, ASTextField, GetNumLines, 88, 0xFEEFBE14);

// @0x1422c58b0
int ASTextField::GetMaxScrollV()
{
    return GetMember("maxScrollV").GetInt();
}
MS2_REPLACE_METHOD(0x1422C58B0, ASTextField, GetMaxScrollV, 88, 0xBB9656F7);

// @0x1422c5910
void ASTextField::SetAutoSize(int nAutoSize)
{
    SetStringMember("autoSize", AutoSizeToString(nAutoSize));
}
MS2_REPLACE_METHOD(0x1422C5910, ASTextField, SetAutoSize, 75, 0x5C8AA59F);

// @0x1422c5970
double ASTextField::GetTextWidth()
{
    return GetMember("textWidth").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C5970, ASTextField, GetTextWidth, 92, 0x19304E37);

// @0x1422c59e0
double ASTextField::GetTextHeight()
{
    return GetMember("textHeight").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C59E0, ASTextField, GetTextHeight, 92, 0x284D168C);

// @0x1422c5a50
void ASTextField::AppendTextA(const CString& strText)
{
    Invoke("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422C5A50, ASTextField, AppendTextA, 87, 0x851E8324);

// @0x1422c5ab0
void ASTextField::AppendTextW(const CStringW& strText)
{
    Invoke("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422C5AB0, ASTextField, AppendTextW, 87, 0xB8D8F4CD);

// @0x1422c5b10
void ASTextField::ReplaceSelectedTextA(const CString& strText)
{
    Invoke("replaceSelectedText", strText);
}
MS2_REPLACE_METHOD(0x1422C5B10, ASTextField, ReplaceSelectedTextA, 87, 0xB256E8DA);

// @0x1422c5b70
void ASTextField::ReplaceSelectedTextW(const CStringW& strText)
{
    Invoke("replaceSelectedText", strText);
}
MS2_REPLACE_METHOD(0x1422C5B70, ASTextField, ReplaceSelectedTextW, 87, 0x59FD8A6A);

// @0x1422c5bd0
void ASTextField::FUN_1422c5bd0(int nBegin, int nEnd, const CString& strText)
{
    FUN_1422c5e40("replaceText", nBegin, nEnd, strText);
}
MS2_REPLACE_METHOD(0x1422C5BD0, ASTextField, FUN_1422c5bd0, 126, 0x01EF77D9);

// @0x1422c5c60
void ASTextField::FUN_1422c5c60(int nBegin, int nEnd, const CStringW& strText)
{
    FUN_141979f30("replaceText", nBegin, nEnd, strText);
}
MS2_REPLACE_METHOD(0x1422C5C60, ASTextField, FUN_1422c5c60, 126, 0x13FF3336);

// @0x1422c5cf0
void ASTextField::SetSelection(int nBegin, int nEnd)
{
    FUN_1409ba0d0("setSelection", nBegin, nEnd);
}
MS2_REPLACE_METHOD(0x1422C5CF0, ASTextField, SetSelection, 68, 0x3CD49EF9);

// @0x1422c5d40
CString ASTextField::AutoSizeToString(int nAutoSize)
{
    switch (nAutoSize)
    {
    case 0:
        return "none";
    case 1:
        return "center";
    case 2:
        return "left";
    case 3:
        return "right";
    default:
        return "";
    }
}
MS2_REPLACE_METHOD(0x1422C5D40, ASTextField, AutoSizeToString, 254, 0xCD237E29);

// @0x1422c5e40 (inline COMDAT: Invoke with two Ints and a String)
Value AScript::FUN_1422c5e40(const char* szMethod, int a1, int a2, CString a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bccb0(&args[0], a1);
    FUN_1422bccb0(&args[1], a2);
    SetString(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ??_GASTextField@@UEAAPEAXI@Z 0x1422c5f40
