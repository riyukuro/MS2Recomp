// astextinput.h - PLACEHOLDER for ASTextInput (RTTI .?AVASTextInput@@), the C++ wrapper of a GFx text input box. NOT an
// original header. Derives from ASUIComponent: the ctor 0x1422e07c0 runs ASUIComponent's (0x1422c7100) and stores its own
// vftable, so it adds no members (0x88 bytes). Only what recovered code calls is declared; the slots between
// ASMovieClip's last (15) and 24 are not recovered.
#pragma once

#include <afx.h>

#include "ms2/placeholder/asuicomponent.h"

class ASTextField;

class ASTextInput : public ASUIComponent
{
public:
    ASTextInput(const Scaleform::GFx::Value& v, int nMovieId);          // 0x1422e07c0
    virtual ~ASTextInput();                                             // 0 0x1422e0810
#define TI_V(n) virtual void vfunc_##n();
    TI_V(16) TI_V(17) TI_V(18) TI_V(19) TI_V(20) TI_V(21) TI_V(22) TI_V(23)
#undef TI_V
    virtual void vfunc_24(int n);                                       // 24 (+0xc0) uitradedialogex.cpp: called with 1 after the text is set
    void FUN_1422e0ab0(const CStringW& strText);                        // set the text
    void FUN_1422e0920(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // "change" listener
    CStringW FUN_1422e0b00();                                           // the text
    MS2Ptr<ASTextField> FUN_1422e1490();                                // the text field child
    void FUN_1422e0d60(int nMaxChars);                                  // the maximum length
};
MS2_CHECK_SIZE(ASTextInput, 0x88);
