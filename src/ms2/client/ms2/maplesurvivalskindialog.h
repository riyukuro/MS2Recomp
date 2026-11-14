// maplesurvivalskindialog.h - Mushking Royale restore: UIMapleSurvivalSkinDialog (GMS 0x4f80, here
// MS2_UI_MAPLESURVIVAL_SKIN). NOT recovered KMS code; ported from the GMS 2019 x86 client. Branch restore/mushking only.
// Included only by maplesurvivalskindialog.cpp and maplesurvivalpassdialog.cpp.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"        // IUIAvatarEventListener

class ASButton;
class ASScrollingList;
class ASButtonBar;
class ASMovieClip;
class UIAvatarPC;

// GMS vtables: the dialog at +0 (0x1740464) and IUIAvatarEventListener at +0x10c (0x1740444).
class UIMapleSurvivalSkinDialog : public UIDialog, public IUIAvatarEventListener
{
public:
    UIMapleSurvivalSkinDialog();
    virtual ~UIMapleSurvivalSkinDialog();
    virtual CString GetTypeName();                  // 1 (GMS 0x7a4890) "MapleSurvivalSkinDialog"
    virtual void OnLoadComplete();                  // 22 (GMS 0x7a5eb0)
    virtual void vfunc_16();                        // 16 (GMS 0x7a4b60) hidden: unloadRenderTarget
    virtual bool vfunc_17();                        // 17 (GMS 0x7a64a0) shown: loadRenderTarget
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 (GMS 0x7a4950) camera
    virtual void vfunc_26();                        // 26 (GMS 0x7a5270) releases the children and the avatar
    // 28 (GMS 0x7a48f0) the preview's mouse events
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual int vfunc_o178_1(void* pAvatar);        // listener slot 1 (GMS 0x7a64c0) the avatar model is loaded
    virtual int vfunc_48() { return 0x4fc3; }       // 48 MS2_UI_MAPLESURVIVAL_SKIN
    // 49 (GMS 0x7a4bb0, its slot 50) a skin row's tooltip: name, description and expiry
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);

    void SetSlot(int nSlot);                        // the category (skin slot 0 tail, 1 riding, 2 gliding) to show
    void RefreshSkins();                            // GMS 0x7a5b90 (manager event MushkingUI::Skin_OnSkins)

    void OnCategoryChange(const Scaleform::GFx::FunctionHandler::Params& params);   // GMS 0x7a5ea0
    void OnOk(const Scaleform::GFx::FunctionHandler::Params& params);               // GMS 0x7a5680 equip
    void OnCancel(const Scaleform::GFx::FunctionHandler::Params& params);           // GMS 0x7a5910 take off
    void OnItemSelect(const Scaleform::GFx::FunctionHandler::Params& params);       // GMS 0x7a5440 preview the row

private:
    int SelectedCategory();
    void CreateAvatar();                            // GMS 0x7a5ac0
    void LoadRenderTarget();                        // GMS 0x7a6450
    void UnloadRenderTarget();

    MS2Ptr<ASScrollingList> m_items;
    MS2Ptr<ASButtonBar> m_category;         // a CLIK ButtonBar (GMS 0x779de0 -> ctor 0x1177cc0)
    MS2Ptr<ASButton> m_okButton;
    MS2Ptr<ASButton> m_cancelButton;
    MS2Ptr<ASMovieClip> m_skinPreview;              // GMS +0x138, the render target clip
    MS2Ptr<UIAvatarPC> m_avatar;                    // GMS +0x140, the local player's preview avatar
    std::vector<int> m_ids;                         // skin id of each m_items row
    int m_nSlot;
};
