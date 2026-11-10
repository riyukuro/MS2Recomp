// uihomeinfodialog.h - UIHomeInfoDialog (RTTI .?AVUIHomeInfoDialog@@, 0x180 bytes, UI id 0x4ed8, swf "HomeInfoDialog"): the
// info panel of the player's home (address, owner, notice, recommend, construction score, the bank and doctor
// cooldown timers, the convenience buttons and the visitors list). Header name assumed from the unit path
// (?\uihomeinfodialog.cpp, 0x1412c4cd0-0x1412c8bd0). Names: FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"

class CMsgBoxData;
class ASGameEntity;

class UIHomeInfoDialog : public UIDialog
{
public:
    UIHomeInfoDialog();                                         // 0x1412c4cd0
    // the dtor (0x1412c88b0, ??_G 0x1412c8910) is implicit: the exe's calls UIDialog::~UIDialog only
    virtual CString GetTypeName();                                  //  1 0x1412c4d70 "HomeInfoDialog"
    virtual void OnLoadComplete();                              // 22 0x1412c4dc0 title of the channel label, then FUN_1412c72d0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412c5030
    virtual void vfunc_43();                                    // 43 0x1412c4fc0 ASDialog slot 4 (6, 0, 0)
    virtual int vfunc_48();                   // 48 0x1412c8950

    void StartBankCooldown(unsigned int nRemainMs);                 // start the bank cooldown animation
    void StartDoctorCooldown(unsigned int nRemainMs);                 // start the doctor cooldown animation
    void UpdateCooldowns();                                       // set both cooldown labels and start the animations
    void UpdateNoticeText();                                       // m_notice text
    void UpdateRecommendButton();                                       // m_recommend enabled state
    void UpdateAddressText();                                       // m_address text
    void FUN_1412c6070();                                       // m_constructScore text
    void UpdateBalance();                                       // balance (meso / merat) of the convenience panel
    void FUN_1412c66c0();                                       // the visitors list
    void FUN_1412c6b50();                                       // extension area title / height
    void SetItemInfo(const CStringW& strItemName, const CStringW& strCreator);   // m_itemName / m_creator
    CStringW FUN_1412c7090();                                   // the notice text
    CStringW GetAddressText();                                   // the address text
    int FUN_1412c72d0();                                        // fill the whole panel; 1 = shown
    void FUN_1412c7600();                                       // leave the home
    void OnTogglePanel();                                       // toggle the minimize state
    void OnNoticeModify();                                       // open the notice editor
    void OnConstruct();                                       // construct mode
    void OnBank();                                       // bank
    void OnDoctor();                                       // doctor
    void OnBalance();                                       // balance: ask for the amount to move
    void SendRequestCubeMode58(CStringW strName);                       // send the "remove user" request
    bool FUN_1412c7aa0(int nResult, const CMsgBoxData& data);
    bool OnSaveSlotAction(int nSlot, const CMsgBoxData& data);    // save slot action (0 save, 1 load, 2 demolish)
    bool FUN_1412c7ef0(int nResult, const CMsgBoxData& data);
    bool SendRequestCubeMode31(int nResult, const CMsgBoxData& data);
    bool FUN_1412c7ff0(int nResult, const CMsgBoxData& data);
    unsigned int GetBankCooldownRemaining();                                      // remaining bank cooldown in ms
    unsigned int GetDoctorCooldownRemaining();                                      // remaining doctor cooldown in ms
    // C3: FUN_140ede180 = Unk_ReportDialogAccess::GetChild<ASGameEntity> (the .cpp calls it through a view)

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                  // +0x178 minimized
    int m_17c;                                                  // +0x17c
};
MS2_CHECK_SIZE(UIHomeInfoDialog, 0x180);
MS2_CHECK_OFFSET(UIHomeInfoDialog, m_178, 0x178);
