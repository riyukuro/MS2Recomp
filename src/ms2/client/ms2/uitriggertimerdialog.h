// uitriggertimerdialog.h - UITriggerTimerDialog (RTTI .?AVUITriggerTimerDialog@@, 0x188 bytes) and its subclass
// UIFreeForAllTimerDialog (RTTI .?AVUIFreeForAllTimerDialog@@, no members of its own): the countdown HUD a game-mode
// trigger runs ("TriggerTimerDialog", UI type 0x4e95; the free-for-all mode's one is 0x4e99). The world service
// supplies the remaining time, the dialog pushes it to the swf as "setTime" ("mmss") and plays the low-time effect
// (the one UITimerDialog uses) in the last ten seconds; when the world has no timer left the dialog closes itself.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\uitriggertimerdialog.cpp`
// (0x141b330c0-0x141b33740 .text$mn, dir client\ms2). Header/unit name assumed (the class names).
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable plus the IMessageListener-in-UIxxx one at +0x18.
// UITriggerTimerDialog overrides slots 1 (class name), 20 (OnLoadInit), 28, 43 (place the movie root), 48 (UI type),
// 65, 67 (close: stop the effect), 72 (the per-frame update).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UITriggerTimerDialog : public UIDialog
{
public:
    UITriggerTimerDialog();                                         // 0x141b330c0 (m_2c = 0x13)
    virtual ~UITriggerTimerDialog() = default;                             //  0 0x141b33680 (??_G 0x141b336e0)
    virtual CString GetTypeName();                                      //  1 0x141b33180 "TriggerTimerDialog"
    virtual void OnLoadInit();                                      // 20 0x141b333f0 (the effect is not running)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x141b33480
    virtual void vfunc_43();                                        // 43 0x141b33550 (movie root position)
    virtual int vfunc_48();                                         // 48 0x141b33730 UI type id
    virtual int vfunc_65();                                         // 65 0x141b331d0
    virtual void vfunc_67();                                        // 67 0x141b33420 (stop the effect, close)
    virtual void vfunc_72();                                        // 72 0x141b33200 (push the time, low-time effect)
    void FUN_141b334d0(int nOffsetY);                               // 0x141b334d0 set m_nOffsetY, re-place the root
    void FUN_141b33510(int nAlign);                                 // 0x141b33510 set m_nAlign, re-place the root
protected:
    MS2_LAYOUT_FRIEND;
    int m_nEffectRunning;           // +0x178 the low-time effect has been started
    int m_nEffect;                  // +0x17c its effect id (0 = none)
    int m_nOffsetY;                 // +0x180 added to 0x82 as the root's y
    int m_nAlign;                   // +0x184 1; first argument of the root's vfunc_2
};
MS2_CHECK_SIZE(UITriggerTimerDialog, 0x188);
MS2_CHECK_OFFSET(UITriggerTimerDialog, m_nEffectRunning, 0x178);
MS2_CHECK_OFFSET(UITriggerTimerDialog, m_nEffect, 0x17c);
MS2_CHECK_OFFSET(UITriggerTimerDialog, m_nOffsetY, 0x180);
MS2_CHECK_OFFSET(UITriggerTimerDialog, m_nAlign, 0x184);

class UIFreeForAllTimerDialog : public UITriggerTimerDialog
{
public:
    UIFreeForAllTimerDialog();                                      // 0x141b33620
    virtual ~UIFreeForAllTimerDialog() = default;                          //  0 0x141b33660 (??_G 0x141b336a0)
    virtual int vfunc_48();                                         // 48 0x141b33720
};
MS2_CHECK_SIZE(UIFreeForAllTimerDialog, 0x188);
