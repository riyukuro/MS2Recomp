// uihomeinfoeditdialog.h - UIHomeInfoEditDialog (RTTI .?AVUIHomeInfoEditDialog@@, 0x180 bytes, UIModalDialog, UI id 0x4f79,
// swf "HomeInfoEditDialog"): the modal dialog that edits the home name ("m_homeName") and the home notice
// ("m_homeNotice"). Owning unit: ?\uihomeinfoeditdialog.cpp (0x140c26440-0x140c27340). Header name assumed from the unit path.
// vftable 0x142... (IMessageListener part at +0x18 as in UIModalDialog); no members of its own.
#pragma once
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/placeholder/gfxvalue.h"

class UIHomeInfoEditDialog : public UIModalDialog
{
public:
    UIHomeInfoEditDialog();                                     // 0x140c26440
    virtual ~UIHomeInfoEditDialog();                            //  0 0x140c264b0 (??_G 0x140c270c0)
    virtual CString GetTypeName();                                  //  1 0x140c264f0 "HomeInfoEditDialog"
    virtual void OnLoadComplete();                              // 22 0x140c26540 fill the two inputs
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c267e0 "OnConfirm"
    virtual void vfunc_43();                                    // 43 0x140c26770 ASDialog slot 4 (0, 0, 0)
    virtual int vfunc_48() { return 0x4f79; }                   // 48 0x140c27100

    CStringW FUN_140c26850();                                   // the notice text (the home info dialog's, or string 0x574)
    CStringW FUN_140c268d0();                                   // the owner name
    int FUN_140c26920();                                        // max chars of the home name (8 / 0x10)
    void OnConfirm();                                       // confirm: send the home name / notice, then close
};
MS2_CHECK_SIZE(UIHomeInfoEditDialog, 0x180);
