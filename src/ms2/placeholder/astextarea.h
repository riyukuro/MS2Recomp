// astextarea.h - PLACEHOLDER for ASTextArea (RTTI .?AVASTextArea@@, vftable 0x143115388), the C++ wrapper of a GFx
// multi-line text area (the messenger's chat lines). NOT an original header. Derives from ASTextInput: the ctor
// 0x1422e4570 runs ASTextInput's (0x1422e07c0) and stores its own vftable, so it adds no members (0x88 bytes,
// operator new(0x88) in the GetChild<ASTextArea> COMDAT 0x140c26f60). The "position" member is the scroll position
// in lines. Only what recovered code calls is declared.
#pragma once

#include <afx.h>

#include "ms2/placeholder/astextinput.h"

class ASTextArea : public ASTextInput
{
public:
    ASTextArea(const Scaleform::GFx::Value& v, int nMovieId);           // 0x1422e4570
    virtual ~ASTextArea();
    void FUN_1422e45f0(int nPosition);                                  // 0x1422e45f0 set "position"
    int FUN_1422e4620();                                                // 0x1422e4620 "position"
    int FUN_1422e4680();                                                // 0x1422e4680 scrolled to the last line
    void FUN_1422e4720();                                               // 0x1422e4720 scroll to the last line
};
MS2_CHECK_SIZE(ASTextArea, 0x88);
