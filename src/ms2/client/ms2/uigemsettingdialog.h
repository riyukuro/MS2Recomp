// uigemsettingdialog.h - UIGemSettingDialog (RTTI .?AVUIGemSettingDialog@@, 0x180 bytes, UIModalDialog, UI id 0x4e75,
// swf "GemSettingDialog"): the modal dialog that sets which of the 10 equip slots the worn transparency gem hides
// (check boxes m_cp m_ey m_cl m_pa m_mt m_ea m_fh m_gl m_ri m_sh). Owning unit: ?\uigemsettingdialog.cpp. Header name
// assumed from the unit path. No members of its own.
#pragma once
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/placeholder/gfxvalue.h"

class UIGemSettingDialog : public UIModalDialog
{
public:
    UIGemSettingDialog();                                       // 0x141946030
    virtual ~UIGemSettingDialog();                              //  0 0x141946090 (??_G 0x141946bc0)
    virtual CString GetTypeName();                                  //  1 0x1419460d0 "GemSettingDialog"
    virtual void vfunc_67();                                    // 67 0x141946120 UIModalDialog::vfunc_67
    virtual void OnLoadComplete();                              // 22 0x141946140 fill the check boxes from the worn gem
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141946510
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141946560 "OnOk"
    virtual int vfunc_48() { return 0x4e75; }                   // 48 0x141946c00

    class CGemTransparency* FUN_1419469b0();                    // the worn transparency gem (null: none)
    bool FUN_141946a70(CString strName);                        // the check box value
    void FUN_141946b10(CString strName, int nValue);            // set the check box value
};
MS2_CHECK_SIZE(UIGemSettingDialog, 0x180);
