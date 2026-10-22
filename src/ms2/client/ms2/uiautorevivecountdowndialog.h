// uiautorevivecountdowndialog.h - UIAutoReviveCountDownDialog (RTTI .?AVUIAutoReviveCountDownDialog@@, 0x180
// bytes: UIDialog + the countdown deadline and the seconds last sent to the swf), the auto-revive countdown.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\uiautorevivecountdowndialog.cpp`
// (0x141284ac0-0x141284e00 .text$mn, dir client\ms2). Header/unit name assumed; the class has no __FILE__ string.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) -> UIObject -> UISwfEntity -> CPtred, IMessageListener. Primary
// vftable 0x142ed0348 (84 slots), IMessageListener-in-UIAutoReviveCountDownDialog 0x142ed05f0. Overridden slots:
// 1 (class name "AutoReviveCountDownDialog"), 43 (resize the movie root), 48 (UI type id 0x4ea2), 67 (forward to
// UIDialog::vfunc_67), 72 (per-frame: the countdown).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIAutoReviveCountDownDialog : public UIDialog
{
public:
    UIAutoReviveCountDownDialog();                                  // 0x141284ac0
    virtual ~UIAutoReviveCountDownDialog();                         //  0 0x141284b30 (??_G 0x141284db0)
    virtual CString GetTypeName();                                      //  1 0x141284d00: "AutoReviveCountDownDialog"
    virtual void vfunc_43();                                        // 43 0x141284c50 (resize the movie root)
    virtual int vfunc_48();                                         // 48 0x141284df0: 0x4ea2
    virtual void vfunc_67();                                        // 67 0x141284d50 forwards to UIDialog
    virtual void vfunc_72();                                        // 72 0x141284b70 the countdown (per-frame)
    void FUN_141284d70(int nDuration);                              // 0x141284d70 start: deadline = now + nDuration

private:
    MS2_LAYOUT_FRIEND;
    unsigned int m_nEndTime;            // +0x178 GetTickCountMs2() deadline; once passed the dialog closes
    unsigned int m_nRemainSec;          // +0x17c the remaining seconds last sent to the swf (0xffffffff: none)
};
MS2_CHECK_SIZE(UIAutoReviveCountDownDialog, 0x180);
MS2_CHECK_OFFSET(UIAutoReviveCountDownDialog, m_nEndTime, 0x178);
MS2_CHECK_OFFSET(UIAutoReviveCountDownDialog, m_nRemainSec, 0x17c);
