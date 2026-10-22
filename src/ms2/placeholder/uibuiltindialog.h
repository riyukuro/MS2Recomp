// uibuiltindialog.h - PLACEHOLDER for UIBuiltInDialog (RTTI .?AVUIBuiltInDialog@@, 0x178 bytes), the base of the
// always-present HUD dialogs (UIMainPlayerInfo). NOT an original header. Base UIDialog (uidialog.h); no members of its
// own. Owning unit ?\uibuiltindialog.cpp (0x1418dcf70-0x1418dd2e0, unrecovered): every out-of-line member is a
// symbols-manual row. Primary vftable overrides: slot 1 (class name "BuiltInDialog"), 20 (OnLoadInit), 67 (Close).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIBuiltInDialog : public UIDialog
{
public:
    UIBuiltInDialog();                                              // 0x1418dcf70 (m_2c = 14, m_80 = 0, m_88 = 1)
    virtual ~UIBuiltInDialog();                                     //  0 0x1418dd000 (??_G 0x1418dd180)
    virtual CString GetTypeName();                                      //  1 0x1418dd040 "BuiltInDialog"
    virtual void OnLoadInit();                                      // 20 0x1418dd150
    virtual void vfunc_67();                                        // 67 0x1418dd090 UIDialog::vfunc_67()
};
MS2_CHECK_SIZE(UIBuiltInDialog, 0x178);
