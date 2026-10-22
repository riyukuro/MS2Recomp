// uipvpkilllogdialog.h - UIPvPKillLogDialog (RTTI .?AVUIPvPKillLogDialog@@, 0x188 bytes, UIDialog, UI id 0x4ea0, swf
// "PvPKillLogDialog"): the kill feed of the battle field. A kill that arrives before the movie is loaded is kept (names at
// +0x178 / +0x180) and replayed in OnLoadComplete. Own kills / deaths play a sound and print a system message.
// Owning unit: ?\uipvpkilllogdialog.cpp. Header name assumed from the unit path; member names are invented.
#pragma once
#include <afx.h>
#include <atlstr.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class UIPvPKillLogDialog : public UIDialog
{
public:
    UIPvPKillLogDialog();                                       // 0x141342570
    virtual ~UIPvPKillLogDialog();                              //  0 0x141342600 (??_G 0x141342ec0)
    virtual CString GetTypeName();                                  //  1 0x141342670 "PvPKillLogDialog"
    virtual void OnLoadComplete();                              // 22 0x141342710 replay the kept kill
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x141342dc0
    virtual void vfunc_43();                                    // 43 0x141342e10 dock at (5, 0x1e, 300)
    virtual int vfunc_48() { return 0x4ea0; }                   // 48 0x141342f00
    virtual int vfunc_65();                                     // 65 0x1413426c0
    virtual void vfunc_67();                                    // 67 0x1413426f0
    virtual void vfunc_79(void* p);                             // 79 0x141342820

    void FUN_141342880(CStringW strAttacker, CStringW strTarget);   // 0x141342880 add a kill to the feed

private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strAttacker;                                     // +0x178 kept until the movie is loaded
    CStringW m_strTarget;                                       // +0x180
};
MS2_CHECK_SIZE(UIPvPKillLogDialog, 0x188);
MS2_CHECK_OFFSET(UIPvPKillLogDialog, m_strAttacker, 0x178);
MS2_CHECK_OFFSET(UIPvPKillLogDialog, m_strTarget, 0x180);
