// survivalkilllogdialog.h - Mushking Royale restore: UISurvivalKillLogDialog (GMS 0x4f69, here MS2_UI_SURVIVAL_KILLLOG,
// swf "SurvivalKillLogDialog"). NOT recovered KMS code; ported from the GMS 2019 x86 client. Branch restore/mushking only.
// Included by survivalkilllogdialog.cpp, survivalgameresultdialog.cpp and survivalobserverdialog.cpp.
#pragma once

#include <afx.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class UISurvivalKillLogDialog : public UIDialog
{
public:
    UISurvivalKillLogDialog();                      // GMS 0x89bbe0 (SetFlag(1, 1): CloseAllDialogs keeps it)
    virtual ~UISurvivalKillLogDialog();
    virtual CString GetTypeName();                  // 1 (GMS 0x89bb70) "SurvivalKillLogDialog"
    virtual void OnLoadComplete();                  // 22 (GMS 0x89c580) replay the kept kill, status
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 (0x89bbc0)
    virtual void vfunc_43();                        // 43 (GMS 0x89bce0) dock
    virtual int vfunc_48() { return 0x4fc5; }       // 48 (GMS 0x89c670) MS2_UI_SURVIVAL_KILLLOG
    virtual int vfunc_65();                         // 65 (GMS 0x89bba0) open
    virtual void vfunc_67();                        // 67 (GMS 0x89bbb0) close
    virtual void vfunc_72();                        // 72 (GMS 0x89c550) tick: field leave, observer state

    void AddKill(const CStringW& strKiller, const CStringW& strVictim);   // GMS 0x89be30 "addKill"
    void RefreshStatus();                           // GMS 0x89c2a0 "setStatus"(killA, killB, alive)
    void SetVisiblePlayInfo(bool bVisible);         // GMS 0x89c500 "setVisiblePlayInfo"

    // The local player's last killer (GMS 0x89bda0 stores the id in the result dialog). The result dialog's OnWatch
    // spectates this id; the observer dialog shows this name.
    static __int64 s_killerId;
    static CStringW s_killerName;
    // True from game start (mode 0x13) to game finish (0x14) or field leave.
    static bool s_bInGame;
    static void CloseGameHud();                     // kill log + storm bar (game finish, field leave)

private:
    CStringW m_strPendKiller;       // kept until the movie is loaded (GMS +0x10c / +0x110)
    CStringW m_strPendVictim;
    bool m_bPlayInfo;               // last setVisiblePlayInfo value (replayed on load)
    int m_nFieldId;                 // the field the game runs in (close on leave)
};
