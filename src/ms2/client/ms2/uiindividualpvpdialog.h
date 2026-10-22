// uiindividualpvpdialog.h - UIIndividualPvPDialog (RTTI .?AVUIIndividualPvPDialog@@, 0x1f8 bytes, UIDialog, UI id 0x4ed1,
// swf "IndividualPvPDialog"): the individual arena window. The three arenas are buttons (m_arena1..m_arena3; the second
// is permanently disabled), the register / unregister / join buttons switch with the PvP manager state. Selecting an
// arena shows its name, description, banner and the two reward items. Owning unit: ?\uiindividualpvpdialog.cpp (header
// name assumed from the unit path; member names are invented from use).
#pragma once
#include <afx.h>
#include <map>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/astextfield.h"

class Unk_140acd6e0;

class UIIndividualPvPDialog : public UIDialog
{
public:
    UIIndividualPvPDialog();                                    // 0x1412c9e70
    virtual ~UIIndividualPvPDialog();                           //  0 0x1412c9fa0 (??_G 0x1412cf440)
    virtual CString vfunc_1();                                  //  1 0x1412ca080 "IndividualPvPDialog"
    virtual void OnLoadInit();                                  // 20 0x1412ca0d0
    virtual void OnLoadComplete();                              // 22 0x1412ca0f0 bind the buttons, select an arena
    virtual void vfunc_26();                                    // 26 0x1412cab00 release the buttons and the bound icons
    virtual int vfunc_48() { return 0x4ed1; }                   // 48 0x1412cf410
    virtual int vfunc_53(void* pCfg);                           // 53 0x1412cac50 save "Convenience/lastPage"
    virtual int vfunc_54(void* pCfg);                           // 54 0x1412cabf0 load "Convenience/lastPage"

    void FUN_1412cacc0();                                       // show the button of the state, refresh the effects
    void FUN_1412cae10(int nArena);                             // select an arena: name, detail, banner, rewards
    void FUN_1412cb220();                                       // play the registered effect
    void FUN_1412cb240();                                       // the wait time labels of the arenas
    void FUN_1412cb4b0(const Scaleform::GFx::FunctionHandler::Params& params);   // join button
    void FUN_1412cb4e0(const Scaleform::GFx::FunctionHandler::Params& params);   // register button
    void SendPVPMode10(const Scaleform::GFx::FunctionHandler::Params& params);   // unregister button
    void FUN_1412cb7e0(const Scaleform::GFx::FunctionHandler::Params& params);   // an arena button
    void FUN_1412cb8d0(bool bPlay);                             // the "m_effect" clips of the arenas
    CString FUN_1412cbc20(unsigned int nItemId);                // bind a reward icon, returns its key
    void FUN_1412cbe90();                                       // release the bound icons
    void FUN_1412cbf20();                                       // hide the three buttons

    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);   // 0x140bb4b10 bind a button child
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);     // 0x140bb4cf0 bind a text field child

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_140acd6e0> m_spJoin;                             // +0x178 "m_joinPVP"
    MS2Ptr<Unk_140acd6e0> m_spRegister;                         // +0x188 "m_registPVP"
    MS2Ptr<Unk_140acd6e0> m_spUnregister;                       // +0x198 "m_unregistPVP"
    MS2Ptr<ASTextField> m_spName;                               // +0x1a8 "m_arenaName"
    MS2Ptr<ASTextField> m_spDetail;                             // +0x1b8 "m_arenaDetail"
    std::map<int, MS2Ptr<Unk_140acd6e0> > m_arenas;             // +0x1c8 arena id -> "m_arena<id>"
    int m_nLastPage;                                            // +0x1d8 1; the remembered arena
    int m_nSelected;                                            // +0x1dc the selected arena
    CStringW m_strBannerDir;                                    // +0x1e0 the banner folder
    std::set<CString> m_icons;                                  // +0x1e8 the bound reward icon keys
};
MS2_CHECK_SIZE(UIIndividualPvPDialog, 0x1f8);
MS2_CHECK_OFFSET(UIIndividualPvPDialog, m_spJoin, 0x178);
MS2_CHECK_OFFSET(UIIndividualPvPDialog, m_arenas, 0x1c8);
MS2_CHECK_OFFSET(UIIndividualPvPDialog, m_nSelected, 0x1dc);
MS2_CHECK_OFFSET(UIIndividualPvPDialog, m_icons, 0x1e8);
