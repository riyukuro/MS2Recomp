// survivalobserverdialog.h - Mushking Royale restore: UISurvivalObserverDialog (GMS 0x4f6b, here
// MS2_UI_SURVIVAL_OBSERVER, swf "SurvivalObserverDialog"). NOT recovered KMS code; ported from the GMS 2019 x86 client.
// Branch restore/mushking only. Included by survivalobserverdialog.cpp and survivalkilllogdialog.cpp.
#pragma once

#include <afx.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CMsgBoxData;

class UISurvivalObserverDialog : public UIDialog
{
public:
    UISurvivalObserverDialog();                     // GMS 0x89ce20
    virtual ~UISurvivalObserverDialog();
    virtual CString GetTypeName();                  // 1 (GMS 0x89c720) "SurvivalObserverDialog"
    virtual int vfunc_13();                         // 13 (GMS slot 14, 0x89c9e0) Escape: the exit box
    virtual void OnLoadComplete();                  // 22 (GMS 0x89cb10) "initData"(name)
    virtual int vfunc_48() { return 0x4fc6; }       // 48 (GMS 0x89d240) MS2_UI_SURVIVAL_OBSERVER
    virtual int vfunc_65();                         // 65 open (+ visible)
    virtual void vfunc_67();                        // 67 (GMS 0x89c760) close
    virtual void vfunc_72();                        // 72 (GMS 0x89c9a0) tick: leave timer, state check

    void ChangePlayerName(const CStringW& strName); // GMS 0x89cb90 "changePlayerName"
    void SetGameMessage(const CStringW& strText);   // GMS 0x89cc30 "setGameMessage"
    void OnGameFinish(bool bLocalIn);               // GMS 0x89ccc0 (NotifySurvivalGameFinish)
    bool OnExitBox(int nResult, const CMsgBoxData& box);   // GMS 0x89c830

    static void LeaveField();                       // GMS 0x89c7a0 RequestMoveField u8 1

private:
    CStringW m_strName;             // GMS +0x10c the watched player's name
    CStringW m_strMessage;          // kept until the movie is loaded
    DWORD m_dwLeaveAt;              // GMS +0x110 leave timer (GetTickCount; 0 = off)
    int m_nFieldId;
};
