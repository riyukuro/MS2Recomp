// astextfield.h - PLACEHOLDER for ASTextField (RTTI .?AVASTextField@@, vftable 0x14310bab0), the C++ wrapper of a
// Scaleform TextField. NOT an original header. Derives from ASInteractiveObject (ctor 0x1422de680 stores that base's
// vftable, then the ctor 0x1422c4c00 stores its own); the exe allocates 0x80 bytes for it (aseffect.cpp), the same
// as ASMovieClip. Only what recovered code calls is declared.
#pragma once

#include <afx.h>

#include "ms2/placeholder/asdisplayobject.h"

class ASTextField : public ASInteractiveObject
{
public:
    ASTextField(const Scaleform::GFx::Value& v, int nMovieId);          // 0x1422c4c00 (the Value is not copied: const&)
    virtual ~ASTextField();
    CStringW FUN_1422c4da0();                                           // get the html text
    void FUN_1422c4cd0(const CStringW& strText);                        // set the text
    void FUN_1422c50e0(unsigned int nColor);                            // set the text colour (0xRRGGBB; uirankpvpdialog.cpp)
    void FUN_1422c4f00(const CStringW& strText);                        // set the html text
    void FUN_1422c5ab0(const CStringW& strText);                        // append text (uinpcpreviewdialog.cpp)
    void FUN_1422c5a50(const CString& strText);                         // append text (narrow; uihairphysxdialog.cpp)
    void FUN_1422c4eb0(const CString& strText);                         // set the html text (narrow)
    void FUN_1422c4c80(const CString& strText);                         // set the text (narrow; UICameraDialog)
    double FUN_1422c59e0();                                             // the text height (uidungeonroomdialog.cpp)
    double FUN_1422c5970();                                             // the text width (uivipdialog.cpp)
    void FUN_1422c5170(int nMaxChars);                                  // set the "maxChars" member (uitradedialogex.cpp)
    void FUN_1422de780(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n1, int n2);   // "focusOut" listener (uitradedialogex.cpp)
    int FUN_1422c58b0();                                                // "maxScrollV" (uimessenger.cpp)
    void FUN_1422c5cf0(int nBegin, int nEnd);                           // setSelection(begin, end) (aslabel.cpp)
};
MS2_CHECK_SIZE(ASTextField, 0x80);                                      // exe allocates 0x80 bytes
