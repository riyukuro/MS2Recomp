// uihomepassworddialog.h - UIHomePasswordDialog (RTTI .?AVUIHomePasswordDialog@@, 0x180 bytes, UIDialog, UI id 0x4ed6,
// swf "HomePasswordDialog"): the dialog where the owner of a house sets the entry password and the visitors enter it.
// Owning unit: ?\uihomepassworddialog.cpp. Header name assumed from the unit path. m_178 is the password the dialog
// currently holds (set by FUN_1412c9680, sent by vfunc_67 on close).
#pragma once
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/gfxvalue.h"

class UIHomePasswordDialog : public UIDialog
{
public:
    UIHomePasswordDialog();                                     // 0x1412c8bd0
    virtual ~UIHomePasswordDialog();                            //  0 0x1412c8c50 (??_G 0x1412c9810)
    virtual CString vfunc_1();                                  //  1 0x1412c8cb0 "HomePasswordDialog"
    virtual void OnLoadComplete();                              // 22 0x1412c8db0 show the lock state (setState)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412c9090
    virtual void vfunc_43();                                    // 43 0x1412c94d0
    virtual int vfunc_48() { return 0x4ed6; }                   // 48 0x1412c9850
    virtual int vfunc_65();                                     // 65 0x1412c8d00
    virtual void vfunc_67();                                    // 67 0x1412c8d30 Close: tell the server, then UIDialog::vfunc_67
    virtual void vfunc_79(void* p);                             // 79 0x1412c9030
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x1412c9580

    void FUN_1412c9680(CString strPassword);                    // m_178 = strPassword
    void SendRequestCube(int nMode, CStringW strPassword, int nUnused);   // send the password packet (type 0x37, sub 0x18)
    void FUN_1412c97c0();                                       // SendRequestCube(0, L"", 0): clear the password

private:
    CString m_178;                                              // +0x178
};
MS2_CHECK_SIZE(UIHomePasswordDialog, 0x180);
