// maplesurvivalbuybundledialog.h - Mushking Royale restore: UIMapleSurvivalBuyBundleDialog (GMS 0x4f81, here
// MS2_UI_MAPLESURVIVAL_BUYBUNDLE). NOT recovered KMS code; ported from the GMS 2019 x86 client. Branch restore/mushking only.
// Included only by maplesurvivalbuybundledialog.cpp.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASButton;
class ASItemSlot;

class UIMapleSurvivalBuyBundleDialog : public UIDialog
{
public:
    UIMapleSurvivalBuyBundleDialog();
    virtual ~UIMapleSurvivalBuyBundleDialog();
    virtual CString GetTypeName();                  // 1 (GMS 0x79ea20) "MapleSurvivalBuyBundleDialog"
    virtual void OnLoadComplete();                  // 22 (GMS 0x79f200)
    virtual void vfunc_26();                        // 26 (GMS 0x79ec70 releases the children)
    virtual int vfunc_48() { return 0x4fc2; }       // 48 (GMS 0x79f6b0) MS2_UI_MAPLESURVIVAL_BUYBUNDLE
    void Refresh();                                 // re-read the bundle event; closes the window when it ended

    void OnBuyDefault(const Scaleform::GFx::FunctionHandler::Params& params);   // GMS 0x79ed70
    void OnBuyBundle(const Scaleform::GFx::FunctionHandler::Params& params);    // GMS 0x79efe0

private:
    MS2Ptr<ASButton> m_buyDefault;
    MS2Ptr<ASButton> m_buyBundle;
    MS2Ptr<ASItemSlot> m_bonusItem;
    __int64 m_defaultPrice;      // GMS +0x110
    __int64 m_bundlePrice;       // GMS +0x118
    int m_bonusItemId;           // GMS +0x128
};
