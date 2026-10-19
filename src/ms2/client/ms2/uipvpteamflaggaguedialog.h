// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uipvpteamflaggaguedialog.h (name
// assumed: the class name). UIPvPTeamFlagGagueDialog (UI type 0x4ed4, "PvPTeamFlagGagueDialog"): the red team's flag
// gauge of the team PvP. The definitions are in uipvpteamflaggaguedialog.cpp; this header only exposes the class to the
// callers that look the dialog up (the entry tables, unit_14101b7f0).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIPvPTeamFlagGagueDialog : public UIDialog
{
public:
    UIPvPTeamFlagGagueDialog();                                             // 0x141344ab0
    virtual ~UIPvPTeamFlagGagueDialog();                                    //  0 0x141344b50
    virtual CString vfunc_1();                                              //  1 0x141344b90
    virtual void OnLoadComplete();                                          // 22 0x141344be0
    virtual void vfunc_43();                                                // 43 0x141344c30
    virtual int vfunc_48() { return 0x4ed4; }                               // 48 (COMDAT 0x141344fa0)
    virtual void vfunc_72();                                                // 72 0x141344ce0

    void FUN_141344d50(int nIndex);                                         // set the red team gauge to nIndex + 1 percent
    void FUN_141344f20();                                                   // hide

    int m_nPercent;                                                         // +0x178 the gauge value to show (1..101)
    int m_nLastPercent;                                                     // +0x17c the value last sent (-1: none)
    unsigned m_nShownTick;                                                  // +0x180 clock of the last change
    bool m_bShown;                                                          // +0x184
};
MS2_CHECK_SIZE(UIPvPTeamFlagGagueDialog, 0x188);
