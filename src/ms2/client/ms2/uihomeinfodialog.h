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
class Unk_HiCombo;
class Unk_HiPanelB;

class UIHomeInfoDialog : public UIDialog
{
public:
    UIHomeInfoDialog();                                         // 0x1412c4cd0
    // the dtor (0x1412c88b0, ??_G 0x1412c8910) is implicit: the exe's calls UIDialog::~UIDialog only
    virtual CString vfunc_1();                                  //  1 0x1412c4d70 "HomeInfoDialog"
    virtual void OnLoadComplete();                              // 22 0x1412c4dc0 title of the channel label, then FUN_1412c72d0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412c5030
    virtual void vfunc_43();                                    // 43 0x1412c4fc0 ASDialog slot 4 (6, 0, 0)
    virtual int vfunc_48();                   // 48 0x1412c8950

    void FUN_1412c5330(unsigned int nRemainMs);                 // start the bank cooldown animation
    void FUN_1412c54e0(unsigned int nRemainMs);                 // start the doctor cooldown animation
    void FUN_1412c5690();                                       // set both cooldown labels and start the animations
    void FUN_1412c5c30();                                       // m_notice text
    void FUN_1412c5da0();                                       // m_recommend enabled state
    void FUN_1412c5f00();                                       // m_address text
    void FUN_1412c6070();                                       // m_constructScore text
    void FUN_1412c6220();                                       // balance (meso / merat) of the convenience panel
    void FUN_1412c66c0();                                       // the visitors list
    void FUN_1412c6b50();                                       // extension area title / height
    void FUN_1412c6e70(const CStringW& strItemName, const CStringW& strCreator);   // m_itemName / m_creator
    CStringW FUN_1412c7090();                                   // the notice text
    CStringW FUN_1412c7140();                                   // the address text
    int FUN_1412c72d0();                                        // fill the whole panel; 1 = shown
    void FUN_1412c7600();                                       // leave the home
    void FUN_1412c7630();                                       // toggle the minimize state
    void FUN_1412c76e0();                                       // open the notice editor
    void FUN_1412c7710();                                       // construct mode
    void FUN_1412c7770();                                       // bank
    void FUN_1412c77c0();                                       // doctor
    void FUN_1412c7810();                                       // balance: ask for the amount to move
    void SendRequestCubeMode58(CStringW strName);                       // send the "remove user" request
    bool FUN_1412c7aa0(int nResult, const CMsgBoxData& data);
    bool FUN_1412c7af0(int nSlot);                              // save slot action (0 save, 1 load, 2 demolish)
    bool FUN_1412c7ef0(int nResult, const CMsgBoxData& data);
    bool SendRequestCubeMode31(int nResult, const CMsgBoxData& data);
    bool FUN_1412c7ff0(int nResult, const CMsgBoxData& data);
    unsigned int FUN_1412c81d0();                                      // remaining bank cooldown in ms
    unsigned int FUN_1412c8280();                                      // remaining doctor cooldown in ms
    MS2Ptr<Unk_HiCombo> FUN_140c28560(const CString& strName);  // child lookup (ICF'd GetChild instance)
    MS2Ptr<Unk_HiPanelB> FUN_140ede180(const CString& strName); // child lookup (ICF'd GetChild instance)

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                  // +0x178 minimized
    int m_17c;                                                  // +0x17c
};
MS2_CHECK_SIZE(UIHomeInfoDialog, 0x180);
MS2_CHECK_OFFSET(UIHomeInfoDialog, m_178, 0x178);
