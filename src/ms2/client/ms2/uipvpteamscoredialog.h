// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uipvpteamscoredialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIPvPTeamScoreDialog is the PvP team score HUD ("PvPTeamScoreDialog", UI type 0x4ed3): the game mode pushes the two
// team scores to the movie as the "updateScore" object while the dialog is up (FUN_141346960, called when the SWF
// finishes loading). "OnShowResult" pushes its result dialog (0x4ed2, UIPvPTeamResultDialog) and "OnClose" closes
// this one. RTTI .?AVUIPvPTeamScoreDialog@@, 0x178 bytes (no members of its own, as UIPvPTeamResultDialog), vftables
// at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIPvPTeamScoreDialog : public UIDialog
{
public:
    UIPvPTeamScoreDialog();                                     // 0x1413466b0
    virtual ~UIPvPTeamScoreDialog();                            //  0 0x141346720 (??_G 0x1413469f0)
    virtual CString GetTypeName();                                  //  1 0x141346760
    virtual void OnLoadComplete();                              // 22 0x1413467b0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1413467e0
    virtual void vfunc_43();                                    // 43 0x1413468b0
    virtual int vfunc_48();                                     // 48 0x141346a30
};
MS2_CHECK_SIZE(UIPvPTeamScoreDialog, 0x178);

// Push the current team scores to the movie (0x141346960): the score pair comes from the game-mode service and is
// handed to the AS method "updateScore".
void FUN_141346960(UIPvPTeamScoreDialog* pDialog);
