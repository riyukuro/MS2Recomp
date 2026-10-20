// astextinput.h - PLACEHOLDER for ASTextInput (RTTI .?AVASTextInput@@, vftable 0x1431142f8), the C++ wrapper of a CLIK
// TextInput. NOT an original header; the code is the ?\astextinput.cpp unit (src/ms2/gfxui/astextinput.cpp,
// 0x1422e07c0-0x1422e15e0). Derives from ASUIComponent: the ctor 0x1422e07c0 runs ASUIComponent's (0x1422c7100) and
// stores its own vftable, so it adds no members (0x88 bytes). Only the dtor is overridden: slots 16-24 are
// ASUIComponent's (vfunc_24(true) = validateNow after an invalidate). They are redeclared here for the units that do not
// opt in to ASUIComponent's slot list (MS2_ASUICOMPONENT_SLOTS, defined by astextinput.cpp so the vftable pairs).
#pragma once

#include <afx.h>

#include "ms2/placeholder/asuicomponent.h"

class ASTextField;

class ASTextInput : public ASUIComponent
{
public:
    ASTextInput(const Scaleform::GFx::Value& v, int nMovieId);          // 0x1422e07c0
    virtual ~ASTextInput();                                             // 0 0x1422e0810 (scalar deleting 0x1422e15a0)
#ifndef MS2_ASUICOMPONENT_SLOTS
#define TI_V(n) virtual void vfunc_##n();
    TI_V(16) TI_V(17) TI_V(18) TI_V(19) TI_V(20) TI_V(21) TI_V(22) TI_V(23)
#undef TI_V
    virtual void vfunc_24(bool bInvalidate);                            // 24 (+0xc0) validateNow (uitradedialogex.cpp: true after the text is set)
#endif

    // "textInput" / "change" listeners
    void FUN_1422e0840(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // add "textInput"
    void FUN_1422e08c0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // remove "textInput"
    void FUN_1422e0920(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // add "change"
    void FUN_1422e09a0(int bFocusable);                                 // set "focusable"
    int FUN_1422e09f0();                                                // "focusable"
    void FUN_1422e0a60(const CStringA& strText);                        // 0x1422e0a60 set the text (narrow; UIMeratMarketDialog::ClearSearchInput)
    void FUN_1422e0ab0(const CStringW& strText);                        // set the text
    CStringW FUN_1422e0b00();                                           // the text
    void FUN_1422e0b80(const CString& strHtml);                         // 0x1422e0b80 set "htmlText" (narrow)
    void FUN_1422e0bd0(const CStringW& strHtml);                        // 0x1422e0bd0 set "htmlText"
    CStringW FUN_1422e0c20();                                           // 0x1422e0c20 "htmlText"
    void FUN_1422e0ca0(int bPassword);                                  // set "displayAsPassword"
    int FUN_1422e0cf0();                                                // "displayAsPassword"
    void FUN_1422e0d60(int nMaxChars);                                  // the maximum length ("maxChars", set as a Number)
    int FUN_1422e0da0();                                                // 0x1422e0da0 "maxChars" (uimessenger.cpp)
    void FUN_1422e0e00(int bEditable);                                  // set "editable"
    int FUN_1422e0e50();                                                // "editable"
    void FUN_1422e0ec0(int bEnabled);                                   // set "tabEnabled"
    int FUN_1422e0f10();                                                // "tabEnabled"
    void FUN_1422e0f80(int nIndex);                                     // set "tabIndex" (as a Boolean: the exe passes nIndex != 0)
    int FUN_1422e0fd0();                                                // "tabIndex" (read as a Boolean)
    void FUN_1422e1040(int bActAsButton);                               // set "actAsButton"
    int FUN_1422e1090();                                                // "actAsButton"
    void FUN_1422e1100(int bAlways);                                    // set "alwaysShowSelection"
    int FUN_1422e1150();                                                // "alwaysShowSelection"
    void FUN_1422e11c0(const CString& strRestrict);                     // the text field's "restrict"
    CString FUN_1422e1230();                                            // the text field's "restrict"
    int FUN_1422e12b0();                                                // "length"
    void FUN_1422e1310(const CString& strText);                         // appendText (narrow)
    void FUN_1422e1370(const CStringW& strText);                        // appendText
    void FUN_1422e13d0(const CString& strHtml);                         // appendHtml (narrow)
    void FUN_1422e1430(const CStringW& strHtml);                         // 0x1422e1430 append html ("appendHtml")
    MS2Ptr<ASTextField> FUN_1422e1490();                                // the "textField" child
    void FUN_1422e1500(int nBegin, int nEnd);                           // 0x1422e1500 focus, validateNow, set the selection
};
MS2_CHECK_SIZE(ASTextInput, 0x88);
