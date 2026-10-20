// astextfieldex.h - ASTextFieldEx (RTTI .?AVASTextFieldEx@@, vftable 0x143115898, 0x40 bytes: the ??_G deletes 0x40),
// the C++ side of the "scaleform.gfx.TextFieldEx" AS class (its static helpers setVerticalAlign / setTextAutoSize take
// the target text field). Derives from AScript (ctor 0x1422ba780, dtor 0x1422ba860) and adds no members. Header name
// assumed; method names invented from the AS method names they invoke.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class ASTextFieldEx : public AScript
{
public:
    // v by value (the ctor destroys it); const so that AScript's const& ctor (0x1422ba780) is the one called
    ASTextFieldEx(const Scaleform::GFx::Value v, int nMovieId);         // 0x1422e4fd0
    virtual ~ASTextFieldEx();                                           // 0x1422e5030 (??_G 0x1422e52c0)
    void SetVerticalAlign(const Scaleform::GFx::Value& target, int nAlign);           // 0x1422e5060 "setVerticalAlign"
    void SetTextAutoSize(const Scaleform::GFx::Value& target, const CString& strMode); // 0x1422e5110 "setTextAutoSize"
    static CString GetVerticalAlignName(int nAlign);                    // 0x1422e51c0 0 none, 1 top, 2 center, 3 bottom
};
MS2_CHECK_SIZE(ASTextFieldEx, 0x40);
