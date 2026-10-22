// uidpsdialog.h - UIDPSDialog (RTTI .?AVUIDPSDialog@@, 0x190 bytes, UIDialog, UI id 0x4e44, swf "DPSDialog"): the
// damage-per-second meter window. It starts / stops a timed measurement ("OnStart" with a delay and a duration,
// "OnStop", "OnResetHistory"), shows the elapsed time and the damage per second, writes a history line when the
// measurement ends and tells the DPS meter system and the DPS tool dialog (CDPSDialog) about it.
// Owning unit: ?\uidpsdialog.cpp. Header name assumed from the unit path; member names are invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIDPSDialog : public UIDialog
{
public:
    UIDPSDialog();                                              // 0x141928c80
    virtual CString vfunc_1();                                  //  1 0x141928d50 "DPSDialog"
    virtual int vfunc_13();                                     // 13 0x141929640 the start / stop hotkey
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141929490
    virtual int vfunc_48() { return 0x4e44; }                   // 48 0x14192a2d0
    virtual int vfunc_65();                                     // 65 0x141928da0 open + create the tool dialog
    virtual void vfunc_67();                                    // 67 0x141928e80 close
    virtual void vfunc_72();                                    // 72 0x141928f20 per frame update

    void FUN_141929700();                                       // reset the measurement
    void FUN_141929760();                                       // add the history line
    int FUN_1419299e0();                                        // m_178: the measurement runs
    void FUN_141929a00(__int64 nDamage, int nType);             // add damage
    void FUN_141929a60(int nDelay, int nDuration);              // OnStart: arm the measurement (seconds)
    void OnStop();                                       // OnStop
    void FUN_141929b70(int bStart);                             // tell the movie "onStart" / "onStop"

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                  // +0x178 the measurement has started
    int m_17c;                                                  // +0x17c the measurement is armed
    unsigned m_180;                                             // +0x180 start tick
    unsigned m_184;                                             // +0x184 end tick (0 = open)
    __int64 m_188;                                              // +0x188 damage sum
};
MS2_CHECK_SIZE(UIDPSDialog, 0x190);
MS2_CHECK_OFFSET(UIDPSDialog, m_188, 0x188);
