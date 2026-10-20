// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASLabel, the ActionScript label wrapper of the GFx UI library.
// MS2-UNIT: ?\aslabel.cpp
// MS2-RANGE: 0x1422e4900-0x1422e4fd0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/aslabel.h (shared; Ghidra's FUN_<va> names are kept there). The setters
// pass the text by value to the AS member setters, the getters read the member back as a string.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/aslabel.h"
#include "ms2/placeholder/astextfield.h"

#include "hook/ms2hook.h"

// @0x1422e4900
ASLabel::ASLabel(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1422e4950
ASLabel::ASLabel(CString strLinkage, int nMovieId)
    : ASUIComponent(strLinkage, nMovieId)
{
}

// @0x1422e49d0
ASLabel::~ASLabel()
{
}

// @0x1422e4a00
void ASLabel::FUN_1422e4a00(const CString& strText)
{
    FUN_1407cba60("text", strText);
}
MS2_REPLACE_METHOD(0x1422E4A00, ASLabel, FUN_1422e4a00, 72, 0x901D9060);

// @0x1422e4a50
void ASLabel::FUN_1422e4a50(const CStringW& strText)
{
    FUN_1407cbb20("text", strText);
}
MS2_REPLACE_METHOD(0x1422E4A50, ASLabel, FUN_1422e4a50, 72, 0x097D1931);

// @0x1422e4aa0
CStringW ASLabel::FUN_1422e4aa0()
{
    return FUN_1422baa20("text").GetStringW();
}
MS2_REPLACE_METHOD(0x1422E4AA0, ASLabel, FUN_1422e4aa0, 123, 0xB13FED19);

// @0x1422e4b30
void ASLabel::FUN_1422e4b30(const CString& strText)
{
    FUN_1407cba60("htmlText", strText);
}
MS2_REPLACE_METHOD(0x1422E4B30, ASLabel, FUN_1422e4b30, 72, 0xEF204333);

// @0x1422e4b80
void ASLabel::FUN_1422e4b80(const CStringW& strText)
{
    FUN_1407cbb20("htmlText", strText);
}
MS2_REPLACE_METHOD(0x1422E4B80, ASLabel, FUN_1422e4b80, 72, 0x70D6C936);

// @0x1422e4bd0
CStringW ASLabel::FUN_1422e4bd0()
{
    return FUN_1422baa20("htmlText").GetStringW();
}
MS2_REPLACE_METHOD(0x1422E4BD0, ASLabel, FUN_1422e4bd0, 123, 0xE0781EE2);

// @0x1422e4c60
void ASLabel::FUN_1422e4c60(const CString& strAutoSize)
{
    FUN_1407cba60("autoSize", strAutoSize);
}
MS2_REPLACE_METHOD(0x1422E4C60, ASLabel, FUN_1422e4c60, 72, 0x8E9278D8);

// @0x1422e4cb0
CString ASLabel::FUN_1422e4cb0()
{
    return FUN_1422baa20("autoSize").GetString();
}
MS2_REPLACE_METHOD(0x1422E4CB0, ASLabel, FUN_1422e4cb0, 123, 0x0D4463AB);

// @0x1422e4d40
void ASLabel::FUN_1422e4d40(const CString& strText)
{
    FUN_1407cba60("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422E4D40, ASLabel, FUN_1422e4d40, 72, 0xCB95CC5E);

// @0x1422e4d90
void ASLabel::FUN_1422e4d90(const CStringW& strText)
{
    FUN_1407cbb20("appendText", strText);
}
MS2_REPLACE_METHOD(0x1422E4D90, ASLabel, FUN_1422e4d90, 72, 0x9A27ED00);

// @0x1422e4de0
void ASLabel::FUN_1422e4de0(const CString& strHtml)
{
    FUN_1407cba60("appendHtml", strHtml);
}
MS2_REPLACE_METHOD(0x1422E4DE0, ASLabel, FUN_1422e4de0, 72, 0xD7A93D24);

// @0x1422e4e30
void ASLabel::FUN_1422e4e30(const CStringW& strHtml)
{
    FUN_1407cbb20("appendHtml", strHtml);
}
MS2_REPLACE_METHOD(0x1422E4E30, ASLabel, FUN_1422e4e30, 72, 0xA636B77C);

// @0x1422e4e80
MS2Ptr<ASTextField> ASLabel::FUN_1422e4e80()
{
    return FUN_1409b4620("textField");
}
MS2_REPLACE_METHOD(0x1422E4E80, ASLabel, FUN_1422e4e80, 102, 0xA832DBEC);

// @0x1422e4ef0
void ASLabel::FUN_1422e4ef0(int nBegin, int nEnd)
{
    if (FUN_1422c76c0() == 0)
        FUN_1422c7630(1);
    vfunc_24(true);
    MS2Ptr<ASTextField> spTextField = FUN_1422e4e80();
    if (spTextField.get())
        spTextField->FUN_1422c5cf0(nBegin, nEnd);
}
MS2_REPLACE_METHOD(0x1422E4EF0, ASLabel, FUN_1422e4ef0, 151, 0x53302C30);

// MS2-PIN: ??_GASLabel@@UEAAPEAXI@Z 0x1422e4f90
