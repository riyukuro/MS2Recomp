// Placeholder (not an original header): the "{0} {1:.2f}" wide text formatter of the string utility TU
// unit_14083f3d0 (its methods live there; the inline ctor/dtor COMDATs 0x1410254e0/0x141025530 elsewhere).
// Name invented. Layout from the ctor (CStringW at +0, the next argument index at +8, an unused int at +0xc).
#pragma once
#include "ms2/ms2layout.h"
#include <atlstr.h>

class Unk_TextFormat
{
public:
    explicit Unk_TextFormat(const CStringW& strFormat);         // 0x1410254e0
    ~Unk_TextFormat();                                          // 0x141025530
    Unk_TextFormat& FUN_14083ff40(const wchar_t* pszArg);       // replaces "{n}" / "{n:fmt}" by the next argument
    Unk_TextFormat& FUN_140840530(CStringW strArg);
    CStringA FUN_140840580() const;                             // the formatted text, narrowed
    CStringW GetStr() const;                             // the formatted text
private:
    CStringW m_str;
    int m_nArg, m_nPos;
};
MS2_CHECK_SIZE(Unk_TextFormat, 0x10);
