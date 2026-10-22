// uiquizoxselectdialog.h - UIQuizOXSelectDialog (RTTI .?AVUIQuizOXSelectDialog@@, 0x178 bytes, UI type 0x4f45): the
// O/X answer screen of the OX quiz. "OnClickAnswer" sends the picked answer (packet 0x90, 10, 11, answer).
// Recovered with ?\uiquizoxselectdialog.cpp (header name assumed).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIQuizOXSelectDialog : public UIDialog
{
public:
    UIQuizOXSelectDialog();                                     // 0x140e7ead0
    virtual ~UIQuizOXSelectDialog();                            //  0 0x140e7eb40 (??_G 0x140e7edd0)
    virtual CString GetTypeName();                                  //  1 0x140e7eb80
    virtual void OnLoadComplete();                              // 22 0x140e7ebd0
    virtual void vfunc_43();                                    // 43 0x140e7ebf0
    virtual void vfunc_72();                                    // 72 0x140e7ec70 (empty)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140e7ec80
    virtual int vfunc_48() { return 0x4f45; }                   // 48 (COMDAT 0x140e7ee10)
};
MS2_CHECK_SIZE(UIQuizOXSelectDialog, 0x178);

// Send the picked answer (0x140e7ed60).
void FUN_140e7ed60(UIQuizOXSelectDialog* pDialog, char nAnswer);
