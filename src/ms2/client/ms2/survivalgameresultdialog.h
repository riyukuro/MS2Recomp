// survivalgameresultdialog.h - Mushking Royale restore: UISurvivalGameResultDialog (GMS 0x4f6f, here
// MS2_UI_SURVIVAL_GAMERESULT, swf "SurvivalGameResultDialog"). NOT recovered KMS code; ported from the GMS 2019 x86
// client. Branch restore/mushking only. Included by survivalgameresultdialog.cpp only.
#pragma once

#include <afx.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASItemSlot;

class UISurvivalGameResultDialog : public UIDialog
{
public:
    UISurvivalGameResultDialog();                   // GMS 0x899aa0
    virtual ~UISurvivalGameResultDialog();
    virtual CString GetTypeName();                  // 1 (GMS 0x8999e0) "SurvivalGameResultDialog"
    virtual void OnLoadComplete();                  // 22 (GMS 0x89af40)
    virtual void vfunc_26();                        // 26 (GMS 0x899e50) release the children
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 (0x89a090)
    virtual int vfunc_48() { return 0x4fc4; }       // 48 (GMS 0x89baf0) MS2_UI_SURVIVAL_GAMERESULT
    virtual void vfunc_67();                        // 67 (GMS 0x899f60) close: leave the field unless watching

    void Populate();                                // GMS 0x89a4d0 (from CMapleSurvivalManager::m_result)
    void OnShow();                                  // GMS 0x89b290 (setter) + open

private:
    bool m_bPending;                // GMS +0x10c populate once the movie is loaded
    bool m_bWatching;               // GMS +0x1b0 OnWatch sent: closing does not leave the field
    int m_nFieldId;                 // the field the result was shown in
    MS2Ptr<ASItemSlot> m_slot[5];   // GMS +0x18c m_RewardItems children
};
