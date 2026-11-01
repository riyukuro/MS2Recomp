// astextfield.h - PLACEHOLDER for ASTextField (RTTI .?AVASTextField@@, vftable 0x14310bab0), the C++ wrapper of a
// Scaleform TextField. NOT an original header. Derives from ASInteractiveObject (ctor 0x1422de680 stores that base's
// vftable, then the ctor 0x1422c4c00 stores its own); the exe allocates 0x80 bytes for it (aseffect.cpp), the same
// as ASMovieClip. Recovered with ?\astextfield.cpp (src/ms2/gfxui/astextfield.cpp, 0x1422c4c00-0x1422c6100).
//
// The text accessors go through GFx::Value::GetText/SetText (plain) and GetTextHTML/SetTextHTML; the others read or
// write the AS TextField properties named in the comments. The narrow strings are UTF-8.
#pragma once

#include <afx.h>

#include "ms2/placeholder/asdisplayobject.h"

class ASTextField : public ASInteractiveObject
{
public:
    ASTextField(const Scaleform::GFx::Value& v, int nMovieId);          // 0x1422c4c00 (the Value is not copied: const&)
    virtual ~ASTextField();                                             // 0x1422c4c50
    void FUN_1422c4c80(const CString& strText);                         // set the text (narrow; UICameraDialog)
    void FUN_1422c4cd0(const CStringW& strText);                        // set the text
    CString FUN_1422c4d20();                                            // the text (narrow)
    CStringW GetTextW();                                           // the text
    void FUN_1422c4eb0(const CString& strText);                         // set the html text (narrow)
    void FUN_1422c4f00(const CStringW& strText);                        // set the html text
    CString FUN_1422c4f50();                                            // the html text (narrow)
    CStringW FUN_1422c4fd0();                                           // the html text
    void SetTextColor(unsigned int nColor);                            // set "textColor" (0xRRGGBB; uirankpvpdialog.cpp)
    unsigned int GetTextColor();                                       // "textColor"
    void SetMaxChars(int nMaxChars);                                  // set "maxChars" (uitradedialogex.cpp)
    int GetMaxChars();                                                // "maxChars"
    void SetMultiline(int bMultiline);                                 // set "multiline"
    int FUN_1422c5250();                                                // "multiline"
    void SetSelectable(int bSelectable);                                // set "selectable"
    int FUN_1422c5310();                                                // "selectable"
    void SetCaretIndex(int nIndex);                                     // set "caretIndex"
    int GetCaretIndex();                                                // "caretIndex"
    void SetEmbedFonts(int bEmbed);                                     // set "embedFonts"
    int FUN_1422c5460();                                                // "embedFonts"
    void SetDisplayAsPassword(int bPassword);                                  // set "displayAsPassword"
    int FUN_1422c5520();                                                // "displayAsPassword"
    void SetUseRichTextClipboard(int bRich);                                      // set "useRichTextClipboard"
    int FUN_1422c55e0();                                                // "useRichTextClipboard"
    void SetMouseWheelEnabled(int bEnabled);                                   // set "mouseWheelEnabled"
    int FUN_1422c56a0();                                                // "mouseWheelEnabled"
    void SetRestrict(const CString& strRestrict);                     // set "restrict" (astextinput.cpp)
    CString GetRestrict();                                            // "restrict" (astextinput.cpp)
    int GetLength();                                                // "length"
    int GetNumLines();                                                // "numLines"
    int GetMaxScrollV();                                                // "maxScrollV" (uimessenger.cpp)
    void SetAutoSize(int nAutoSize);                                  // set "autoSize" (0 none, 1 center, 2 left, 3 right)
    double GetTextWidth();                                             // "textWidth" (uivipdialog.cpp)
    double FUN_1422c59e0();                                             // "textHeight" (uidungeonroomdialog.cpp)
    void FUN_1422c5a50(const CString& strText);                         // appendText (narrow; uihairphysxdialog.cpp)
    void FUN_1422c5ab0(const CStringW& strText);                        // appendText (uinpcpreviewdialog.cpp)
    void FUN_1422c5b10(const CString& strText);                         // replaceSelectedText (narrow)
    void FUN_1422c5b70(const CStringW& strText);                        // replaceSelectedText
    void FUN_1422c5bd0(int nBegin, int nEnd, const CString& strText);   // replaceText (narrow)
    void FUN_1422c5c60(int nBegin, int nEnd, const CStringW& strText);  // replaceText
    void SetSelection(int nBegin, int nEnd);                           // setSelection(begin, end) (aslabel.cpp)
    CString FUN_1422c5d40(int nAutoSize);                               // the "autoSize" name ("none"/"center"/"left"/"right", else "")
    void FUN_1422de780(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n1, int n2);   // "focusOut" listener (uitradedialogex.cpp)
};
MS2_CHECK_SIZE(ASTextField, 0x80);                                      // exe allocates 0x80 bytes
