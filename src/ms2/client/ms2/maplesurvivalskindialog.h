// maplesurvivalskindialog.h - Mushking Royale restore: UIMapleSurvivalSkinDialog (GMS 0x4f80, here
// MS2_UI_MAPLESURVIVAL_SKIN). NOT recovered KMS code; ported from the GMS 2019 x86 client. Branch restore/mushking only.
// Included only by maplesurvivalskindialog.cpp and maplesurvivalpassdialog.cpp.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASButton;
class ASScrollingList;

class UIMapleSurvivalSkinDialog : public UIDialog
{
public:
    UIMapleSurvivalSkinDialog();
    virtual ~UIMapleSurvivalSkinDialog();
    virtual CString GetTypeName();                  // 1 (GMS 0x7a4890) "MapleSurvivalSkinDialog"
    virtual void OnLoadComplete();                  // 22 (GMS 0x7a5eb0)
    virtual void vfunc_26();                        // 26 releases the children
    virtual int vfunc_48() { return 0x4fc3; }       // 48 MS2_UI_MAPLESURVIVAL_SKIN

    void SetSlot(int nSlot);                        // the category (skin slot 0 tail, 1 riding, 2 gliding) to show
    void RefreshSkins();                            // GMS 0x7a5b90 (manager event MushkingUI::Skin_OnSkins)

    void OnCategoryChange(const Scaleform::GFx::FunctionHandler::Params& params);   // GMS 0x7a5ea0
    void OnOk(const Scaleform::GFx::FunctionHandler::Params& params);               // GMS 0x7a5680 equip
    void OnCancel(const Scaleform::GFx::FunctionHandler::Params& params);           // GMS 0x7a5910 take off

private:
    int SelectedCategory();

    MS2Ptr<ASScrollingList> m_items;
    MS2Ptr<ASScrollingList> m_category;
    MS2Ptr<ASButton> m_okButton;
    MS2Ptr<ASButton> m_cancelButton;
    std::vector<int> m_ids;                         // skin id of each m_items row
    int m_nSlot;
};
