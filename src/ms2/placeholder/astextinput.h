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
    void AddTextInputHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // add "textInput"
    void RemoveTextInputHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // remove "textInput"
    void AddChangeHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // add "change"
    void SetFocusable(int bFocusable);                                 // set "focusable"
    int GetFocusable();                                                // "focusable"
    void SetTextA(const CStringA& strText);                        // 0x1422e0a60 set the text (narrow; UIMeratMarketDialog::ClearSearchInput)
    void SetTextW(const CStringW& strText);                        // set the text
    CStringW GetText();                                           // the text
    void SetHtmlTextA(const CString& strHtml);                         // 0x1422e0b80 set "htmlText" (narrow)
    void SetHtmlTextW(const CStringW& strHtml);                        // 0x1422e0bd0 set "htmlText"
    CStringW GetHtmlText();                                           // 0x1422e0c20 "htmlText"
    void SetDisplayAsPassword(int bPassword);                                  // set "displayAsPassword"
    int GetDisplayAsPassword();                                                // "displayAsPassword"
    void SetMaxChars(int nMaxChars);                                  // the maximum length ("maxChars", set as a Number)
    int GetMaxChars();                                                // 0x1422e0da0 "maxChars" (uimessenger.cpp)
    void SetEditable(int bEditable);                                  // set "editable"
    int GetEditable();                                                // "editable"
    void SetTabEnabled(int bEnabled);                                   // set "tabEnabled"
    int GetTabEnabled();                                                // "tabEnabled"
    void SetTabIndex(int nIndex);                                     // set "tabIndex" (as a Boolean: the exe passes nIndex != 0)
    int GetTabIndex();                                                // "tabIndex" (read as a Boolean)
    void SetActAsButton(int bActAsButton);                               // set "actAsButton"
    int GetActAsButton();                                                // "actAsButton"
    void SetAlwaysShowSelection(int bAlways);                                    // set "alwaysShowSelection"
    int GetAlwaysShowSelection();                                                // "alwaysShowSelection"
    void SetRestrict(const CString& strRestrict);                     // the text field's "restrict"
    CString GetRestrict();                                            // the text field's "restrict"
    int GetLength();                                                // "length"
    void AppendTextA(const CString& strText);                         // appendText (narrow)
    void AppendTextW(const CStringW& strText);                        // appendText
    void AppendHtmlA(const CString& strHtml);                         // appendHtml (narrow)
    void AppendHtmlW(const CStringW& strHtml);                         // 0x1422e1430 append html ("appendHtml")
    MS2Ptr<ASTextField> GetTextField();                                // the "textField" child
    void FocusAndSetSelection(int nBegin, int nEnd);                           // 0x1422e1500 focus, validateNow, set the selection
};
MS2_CHECK_SIZE(ASTextInput, 0x88);
