// uikeysettingselectdialog.h - UIKeySettingSelectDialog (RTTI .?AVUIKeySettingSelectDialog@@, 0x198 bytes, UIDialog, UI id
// 0x4f65, swf "KeySettingSelectDialog"): asks which default key layout to load (keyboard / mouse control); both buttons
// ("m_button1" / "m_button2") share one click handler that loads the default key xml, refreshes the key UIs and closes.
// Owning unit: ?\uikeysettingselectdialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_KsButton;

class UIKeySettingSelectDialog : public UIDialog
{
public:
    UIKeySettingSelectDialog();                                 // 0x140c581a0
    virtual ~UIKeySettingSelectDialog();                        //  0 0x140c58240 (??_G 0x140c58a80)
    virtual CString GetTypeName();                                  //  1 0x140c582e0 "KeySettingSelectDialog"
    virtual void OnLoadComplete();                              // 22 0x140c58380 hook the two buttons
    virtual int vfunc_48() { return 0x4f65; }                   // 48 0x140c58cd0
    virtual void vfunc_67();                                    // 67 0x140c58330

    void FUN_140c58690(const Scaleform::GFx::FunctionHandler::Params& params);   // a button was clicked

private:
    MS2Ptr<Unk_KsButton> m_button1;                             // +0x178 "m_button1"
    MS2Ptr<Unk_KsButton> m_button2;                             // +0x188 "m_button2"
    MS2Ptr<Unk_KsButton> FUN_140bc6d10(const CString& strName, MS2Ptr<Unk_KsButton>& out);   // 0x140bc6d10 returns by value (hidden return pointer)
};
MS2_CHECK_SIZE(UIKeySettingSelectDialog, 0x198);
