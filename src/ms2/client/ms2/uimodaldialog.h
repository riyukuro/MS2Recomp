// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIModalDialog: the base of the dialogs that block the HUD
// (UIPartySearchRegisterDialog, ...). Header name assumed (no __FILE__ in the unit).
#pragma once
#include "ms2/placeholder/uidialog.h"

class UIModalDialog : public UIDialog {
public:
    UIModalDialog();                    // 0x141a55270
    virtual ~UIModalDialog();           // 0x141a552e0
    virtual CString GetTypeName();          // "ModalDialog"
    virtual void vfunc_8(int nVisible);
    virtual void vfunc_47(int n);       // FUN_141901470(n, vfunc_48())
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void OnLoadComplete();
protected:
    MS2_LAYOUT_FRIEND;
    bool m_178;                         // +0x178 loaded (OnLoadComplete sets, Close clears)
};
MS2_CHECK_SIZE(UIModalDialog, 0x180);
MS2_CHECK_OFFSET(UIModalDialog, m_178, 0x178);

// The id of the shown modal dialog (0x143af4400) and its three accessors in uimodaldialog.cpp.
int FUN_141a55620();
void FUN_141a55650(int nId);
void FUN_141a55670(int nId);
