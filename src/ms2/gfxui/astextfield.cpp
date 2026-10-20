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
CStringW FUN_1408767c0(const char* sz);                             // a UTF-8 string as a wide CString
CString FUN_1409a23d0(const char* sz, int n);                       // a UTF-8 string as a CString
CStringW FUN_140efe330(const wchar_t* psz, int n);                  // a wide string as a CString
void FUN_1422bccb0(Value* pValue, int n);                           // set an Int value
void FUN_1422bce70(Value* pValue, const char* psz);                 // set a String value

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
void ASTextField::FUN_1422c4c80(const CString& strText)
{
    FUN_1422bb870().SetText(strText);
}
MS2_REPLACE_METHOD(0x1422C4C80, ASTextField, FUN_1422c4c80, 61, 0xE4942A47);

// @0x1422c4cd0
void ASTextField::FUN_1422c4cd0(const CStringW& strText)
{
    FUN_1422bb870().SetText(strText);
}
MS2_REPLACE_METHOD(0x1422C4CD0, ASTextField, FUN_1422c4cd0, 61, 0x9903C860);

// @0x1422c4d20
CString ASTextField::FUN_1422c4d20()
{
    return FUN_14016a600(FUN_1422c4da0(), 0);
}
MS2_REPLACE_METHOD(0x1422C4D20, ASTextField, FUN_1422c4d20, 120, 0x91918A67);

// @0x1422c4da0
CStringW ASTextField::FUN_1422c4da0()
{
    Value v;
    if (FUN_1422bb870().GetText(&v))
    {
        if (v.IsString())
            return FUN_1408767c0(v.GetString());
        if (v.IsStringW())
            return FUN_140efe330(v.GetStringW(), 0);
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1422C4DA0, ASTextField, FUN_1422c4da0, 264, 0x98304C6D);

// @0x1422c4eb0
void ASTextField::FUN_1422c4eb0(const CString& strText)
{
    FUN_1422bb870().SetTextHTML(strText);
}
MS2_REPLACE_METHOD(0x1422C4EB0, ASTextField, FUN_1422c4eb0, 61, 0xAF866D5D);

// @0x1422c4f00
void ASTextField::FUN_1422c4f00(const CStringW& strText)
{
    FUN_1422bb870().SetTextHTML(strText);
}
MS2_REPLACE_METHOD(0x1422C4F00, ASTextField, FUN_1422c4f00, 61, 0xC299544E);

// @0x1422c4f50
CString ASTextField::FUN_1422c4f50()
{
    return FUN_14016a600(FUN_1422c4fd0(), 0);
}
MS2_REPLACE_METHOD(0x1422C4F50, ASTextField, FUN_1422c4f50, 120, 0x34FEC111);

// @0x1422c4fd0
CStringW ASTextField::FUN_1422c4fd0()
{
    Value v;
    if (FUN_1422bb870().GetTextHTML(&v))
    {
        if (v.IsString())
            return FUN_1408767c0(v.GetString());
        if (v.IsStringW())
            return FUN_140efe330(v.GetStringW(), 0);
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1422C4FD0, ASTextField, FUN_1422c4fd0, 264, 0x1C267731);

// @0x1422c50e0
void ASTextField::FUN_1422c50e0(unsigned int nColor)
{
    FUN_1409c0d20("textColor", nColor);
}
MS2_REPLACE_METHOD(0x1422C50E0, ASTextField, FUN_1422c50e0, 40, 0x839BCDCD);

// @0x1422c5110
unsigned int ASTextField::FUN_1422c5110()
{
    return FUN_1422baa20("textColor").GetUInt();
}
MS2_REPLACE_METHOD(0x1422C5110, ASTextField, FUN_1422c5110, 88, 0x832C249C);

// @0x1422c5170
void ASTextField::FUN_1422c5170(int nMaxChars)
{
    FUN_1407cb9c0("maxChars", nMaxChars);
}
MS2_REPLACE_METHOD(0x1422C5170, ASTextField, FUN_1422c5170, 40, 0xAFB9804F);

// @0x1422c51a0
int ASTextField::FUN_1422c51a0()
{
    return FUN_1422baa20("maxChars").GetInt();
}
MS2_REPLACE_METHOD(0x1422C51A0, ASTextField, FUN_1422c51a0, 88, 0xEA80715C);

// @0x1422c5200
void ASTextField::FUN_1422c5200(int bMultiline)
{
    FUN_1407cbbe0("multiline", bMultiline != 0);
}
MS2_REPLACE_METHOD(0x1422C5200, ASTextField, FUN_1422c5200, 60, 0x195876E7);

// @0x1422c5250
int ASTextField::FUN_1422c5250()
{
    return FUN_1422baa20("multiline").GetBool();
}
MS2_REPLACE_METHOD(0x1422C5250, ASTextField, FUN_1422c5250, 91, 0xFE82D2D3);

// @0x1422c52c0
void ASTextField::FUN_1422c52c0(int bSelectable)
{
    FUN_1407cbbe0("selectable", bSelectable != 0);
}
MS2_REPLACE_METHOD(0x1422C52C0, ASTextField, FUN_1422c52c0, 60, 0xA6D0D30B);

// @0x1422c5310
int ASTextField::FUN_1422c5310()
{
    return FUN_1422baa20("selectable").GetBool();
}
MS2_REPLACE_METHOD(0x1422C5310, ASTextField, FUN_1422c5310, 91, 0xBF1D2E51);

// @0x1422c5380
void ASTextField::FUN_1422c5380(int nIndex)
{
    FUN_1407cb9c0("caretIndex", nIndex);
}
MS2_REPLACE_METHOD(0x1422C5380, ASTextField, FUN_1422c5380, 40, 0x23842660);

// @0x1422c53b0
int ASTextField::FUN_1422c53b0()
{
    return FUN_1422baa20("caretIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422C53B0, ASTextField, FUN_1422c53b0, 88, 0xF2C211FC);

// @0x1422c5410
void ASTextField::FUN_1422c5410(int bEmbed)
{
    FUN_1407cbbe0("embedFonts", bEmbed != 0);
}
MS2_REPLACE_METHOD(0x1422C5410, ASTextField, FUN_1422c5410, 60, 0x719A42F7);

// @0x1422c5460
int ASTextField::FUN_1422c5460()
{
    return FUN_1422baa20("embedFonts").GetBool();
}
MS2_REPLACE_METHOD(0x1422C5460, ASTextField, FUN_1422c5460, 91, 0x37D62B23);

// @0x1422c54d0
void ASTextField::FUN_1422c54d0(int bPassword)
{
    FUN_1407cbbe0("displayAsPassword", bPassword != 0);
}
MS2_REPLACE_METHOD(0x1422C54D0, ASTextField, FUN_1422c54d0, 60, 0xE6E1A2E3);

// @0x1422c5520
int ASTextField::FUN_1422c5520()
{
    return FUN_1422baa20("displayAsPassword").GetBool();
}
MS2_REPLACE_METHOD(0x1422C5520, ASTextField, FUN_1422c5520, 91, 0x44A77CED);

// @0x1422c5590
void ASTextField::FUN_1422c5590(int bRich)
{
    FUN_1407cbbe0("useRichTextClipboard", bRich != 0);
}
MS2_REPLACE_METHOD(0x1422C5590, ASTextField, FUN_1422c5590, 60, 0xD6FD35D3);

// @0x1422c55e0
int ASTextField::FUN_1422c55e0()
{
    return FUN_1422baa20("useRichTextClipboard").GetBool();
}
MS2_REPLACE_METHOD(0x1422C55E0, ASTextField, FUN_1422c55e0, 91, 0x8799CAC5);

// @0x1422c5650
void ASTextField::FUN_1422c5650(int bEnabled)
{
    FUN_1407cbbe0("mouseWheelEnabled", bEnabled != 0);
}
MS2_REPLACE_METHOD(0x1422C5650, ASTextField, FUN_1422c5650, 60, 0xA757D84F);

// @0x1422c56a0
int ASTextField::FUN_1422c56a0()
{
    return FUN_1422baa20("mouseWheelEnabled").GetBool();
}
MS2_REPLACE_METHOD(0x1422C56A0, ASTextField, FUN_1422c56a0, 91, 0x672000D3);

// @0x1422c5710
void ASTextField::FUN_1422c5710(const CString& strRestrict)
{
    FUN_1407cba60("restrict", strRestrict);
}
MS2_REPLACE_METHOD(0x1422C5710, ASTextField, FUN_1422c5710, 72, 0x7997D9A1);

// @0x1422c5760
CString ASTextField::FUN_1422c5760()
{
    return FUN_1409a23d0(FUN_1422baa20("restrict").GetString(), 0);
}
MS2_REPLACE_METHOD(0x1422C5760, ASTextField, FUN_1422c5760, 125, 0xD125DBC8);

// @0x1422c57f0
int ASTextField::FUN_1422c57f0()
{
    return FUN_1422baa20("length").GetInt();
}
MS2_REPLACE_METHOD(0x1422C57F0, ASTextField, FUN_1422c57f0, 88, 0xA94234E0);

// @0x1422c5850
int ASTextField::FUN_1422c5850()
{
    return FUN_1422baa20("numLines").GetInt();
}
MS2_REPLACE_METHOD(0x1422C5850, ASTextField, FUN_1422c5850, 88, 0xFEEFBE14);

// @0x1422c58b0
int ASTextField::FUN_1422c58b0()
{
    return FUN_1422baa20("maxScrollV").GetInt();
}
MS2_REPLACE_METHOD(0x1422C58B0, ASTextField, FUN_1422c58b0, 88, 0xBB9656F7);

// @0x1422c5910
void ASTextField::FUN_1422c5910(int nAutoSize)
{
    FUN_1407cba60("autoSize", FUN_1422c5d40(nAutoSize));
}
MS2_REPLACE_METHOD(0x1422C5910, ASTextField, FUN_1422c5910, 75, 0x5C8AA59F);

// @0x1422c5970
double ASTextField::FUN_1422c5970()
{
    return FUN_1422baa20("textWidth").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C5970, ASTextField, FUN_1422c5970, 92, 0x19304E37);

// @0x1422c59e0
double ASTextField::FUN_1422c59e0()
{
    return FUN_1422baa20("textHeight").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C59E0, ASTextField, FUN_1422c59e0, 92, 0x284D168C);

// @0x1422c5a50
void ASTextField::FUN_1422c5a50(const CString& strText)
{
    Invoke("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422C5A50, ASTextField, FUN_1422c5a50, 87, 0x851E8324);

// @0x1422c5ab0
void ASTextField::FUN_1422c5ab0(const CStringW& strText)
{
    Invoke("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422C5AB0, ASTextField, FUN_1422c5ab0, 87, 0xB8D8F4CD);

// @0x1422c5b10
void ASTextField::FUN_1422c5b10(const CString& strText)
{
    Invoke("replaceSelectedText", strText);
}
MS2_REPLACE_METHOD(0x1422C5B10, ASTextField, FUN_1422c5b10, 87, 0xB256E8DA);

// @0x1422c5b70
void ASTextField::FUN_1422c5b70(const CStringW& strText)
{
    Invoke("replaceSelectedText", strText);
}
MS2_REPLACE_METHOD(0x1422C5B70, ASTextField, FUN_1422c5b70, 87, 0x59FD8A6A);

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
void ASTextField::FUN_1422c5cf0(int nBegin, int nEnd)
{
    FUN_1409ba0d0("setSelection", nBegin, nEnd);
}
MS2_REPLACE_METHOD(0x1422C5CF0, ASTextField, FUN_1422c5cf0, 68, 0x3CD49EF9);

// @0x1422c5d40
CString ASTextField::FUN_1422c5d40(int nAutoSize)
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
MS2_REPLACE_METHOD(0x1422C5D40, ASTextField, FUN_1422c5d40, 254, 0xCD237E29);

// @0x1422c5e40 (inline COMDAT: Invoke with two Ints and a String)
Value AScript::FUN_1422c5e40(const char* szMethod, int a1, int a2, CString a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bce70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ??_GASTextField@@UEAAPEAXI@Z 0x1422c5f40
