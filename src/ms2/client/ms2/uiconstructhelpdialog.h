// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiconstructhelpdialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIConstructHelpDialog is the help panel of the home construct mode ("ConstructHelpDialog", UI type 0x4e85): the movie
// is told which mode the home map information service is in ("setMode"), and the dialog sits at the screen's right
// edge (below the minimap when the visitor list is empty). RTTI .?AVUIConstructHelpDialog@@, 0x178 bytes (no members),
// vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/imessagelistener.h"

class UIConstructHelpDialog : public UIDialog
{
public:
    UIConstructHelpDialog();                                    // 0x141905eb0
    virtual ~UIConstructHelpDialog();                           //  0 0x141905f20 (??_G 0x141906440)
    virtual CString GetTypeName();                                  //  1 0x141905f60
    virtual void OnLoadComplete();                              // 22 0x141906000
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x141906140
    virtual void vfunc_43();                                    // 43 0x1419061b0
    virtual int vfunc_65();                                     // 65 0x141905fb0
    virtual void vfunc_67();                                    // 67 0x141905fe0
    virtual void vfunc_79(void* p);                             // 79 0x1419060e0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141906380 message box answers
    // @0x141906480
    virtual int vfunc_48() { return 0x4e85; }                   // 48
};
MS2_CHECK_SIZE(UIConstructHelpDialog, 0x178);
