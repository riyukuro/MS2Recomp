// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
//
// UIKeyboardGuideDialog: the "KeyboardGuideDialog" UI (type 0x4f0f). RTTI .?AVUIKeyboardGuideDialog@@, no own members
// (0x178 bytes like UIDialog), vftables 0x142e861b0 (84 slots) and 0x142e86458 (IMessageListener at +0x18).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIKeyboardGuideDialog : public UIDialog
{
public:
    UIKeyboardGuideDialog();                    // 0x140f83ff0
    virtual ~UIKeyboardGuideDialog();           //  0 0x140f84050 (scalar deleting 0x140f841a0)
    virtual CString GetTypeName();                  //  1 0x140f84090
    virtual void OnLoadComplete();              // 22 0x140f840e0
    virtual void vfunc_67();                    // 67 0x140f84180
    virtual int vfunc_48() { return 0x4f0f; }   // 48 (COMDAT 0x140f841e0)
};
MS2_CHECK_SIZE(UIKeyboardGuideDialog, 0x178);
