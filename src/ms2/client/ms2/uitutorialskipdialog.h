// uitutorialskipdialog.h - UITutorialSkipDialog (RTTI .?AVUITutorialSkipDialog@@, UIDialog, UI id 0x4ea5, swf
// "TutorialSkipDialog"): the dialog that offers to skip the tutorial; the button asks for confirmation in a message box.
// Owning unit: ?\uitutorialskipdialog.cpp. Header name assumed from the unit path.
#pragma once
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxvalue.h"

class CMsgBoxData;

class UITutorialSkipDialog : public UIDialog
{
public:
    UITutorialSkipDialog();                                     // 0x141b33740
    virtual ~UITutorialSkipDialog();                            //  0 0x141b337c0 (??_G 0x141b33f70)
    virtual CString GetTypeName();                                  //  1 0x141b33800 "TutorialSkipDialog"
    virtual void OnLoadComplete();                              // 22 0x141b33850 job texts, showOnDelay
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b33ad0
    virtual int vfunc_48() { return 0x4ea5; }                   // 48 0x141b33fb0

    bool FUN_141b33ca0(int nResult, const CMsgBoxData& data);   // message box result
};
