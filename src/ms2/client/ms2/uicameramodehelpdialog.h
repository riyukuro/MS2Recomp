// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicameramodehelpdialog.h (name assumed:
// the class name; the exe has no assert path for it).
//
// UICameraModeHelpDialog is the help overlay of the camera mode ("CameraModeHelpDialog", UI type 0x4f3e). RTTI
// .?AVUICameraModeHelpDialog@@, 0x178 bytes (no members of its own), vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UICameraModeHelpDialog : public UIDialog
{
public:
    UICameraModeHelpDialog();                                       // 0x140e05260
    virtual ~UICameraModeHelpDialog();                              //  0 0x140e052d0 (??_G 0x140e05410)
    virtual CString GetTypeName();                                      //  1 0x140e05310
    virtual void vfunc_43();                                        // 43 0x140e05360
    virtual int vfunc_48();                                         // 48 0x140e05450
};
MS2_CHECK_SIZE(UICameraModeHelpDialog, 0x178);
