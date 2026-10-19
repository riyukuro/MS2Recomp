// uiskillcompactcontroldialog.h - the compact skill control window (RTTI UISkillCompactControlDialog, UI id 0x4ef6;
// "SkillCompactControl"): up to three named tabs (CSkillCompactControlConfig), each with a skill list the player ticks
// and a hot key that triggers the whole set. Tabs are loaded from / saved to the server (packet 0x7b / 0xd1) and
// pushed into the skill system (FUN_141767d90). NOT an original header (the unit is ?\uiskillcompactcontroldialog.cpp).
// Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"

class CMsgBoxData;
class CSkillCompactControlConfig;
class Unk_140acd6e0;                                    // a button child
class Unk_SkillButtonBar;                               // the "m_buttonBar" tab bar

// The key state of the hot key being edited (0x18 bytes).
class Unk_ScHotKeyState
{
public:
    Unk_ScHotKeyState();
    void Clear();                                       // key 0, state 0, no tab
    int FUN_140fa35d0() const;                                  // 0x140fa35d0

    int m_nState;                                       // +0x00 1 = a key was captured
    CStringW m_strTab;                                  // +0x08 the tab being edited
    int m_nKey;                                         // +0x10
};
MS2_CHECK_SIZE(Unk_ScHotKeyState, 0x18);

class UISkillCompactControlDialog : public UIDialog
{
public:
    UISkillCompactControlDialog();                      // 0x140f9e200
    virtual ~UISkillCompactControlDialog();             // 0x140fa2f80 (??_G 0x140fa3160)
    virtual CString vfunc_1();
    virtual int vfunc_13();
    virtual void OnLoadInit();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual int vfunc_48();                             // 0x140fa35c0 returns 0x4ef6
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void vfunc_79(void* p);
    virtual void vfunc_80(void* p);
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);

    bool FUN_140fa0820(int nResult, const CMsgBoxData& data);   // answer of the rename box
    bool FUN_140fa0a20(CStringW strName);               // rename the tab (m_strRename) to strName
    bool FUN_140fa0d80(int nResult, const CMsgBoxData& data);   // answer of the add tab box
    bool FUN_140fa0fa0(CStringW strName);               // add a tab
    void FUN_140fa1240();                               // send the tabs to the server
    void FUN_140fa1400();                               // push the tabs to the skill system
    void FUN_140fa1460(ATL::CAtlList<unsigned>* pList); // the job's skills (the usable ones first)
    void FUN_140fa16f0(CStringW strTab);         // rebuild the skill list in the movie
    void FUN_140fa1ff0();                               // add all tabs to the tab bar
    void FUN_140fa2180(CStringW strTab);         // set the hot key label
    bool FUN_140fa23a0(int nKey);                       // the key is not bound to a tab yet
    bool FUN_140fa23f0(int nKey, __int64 nId);          // bind the key to a tab's id
    __int64 FUN_140fa2520(CStringW strTab);      // the tab's emotion / key id
    MS2Ptr<CSkillCompactControlConfig> FUN_140fa2720(CStringW strName);   // create a tab
    MS2Ptr<CSkillCompactControlConfig> FUN_140fa28b0(CStringW strName);   // find a tab
    void FUN_140fa29f0(CStringW strName);        // remove a tab

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<MS2Ptr<CSkillCompactControlConfig> > m_lstConfig;   // +0x178
    CStringW m_strTab;                                  // +0x1a8 the selected tab
    MS2Ptr<Unk_SkillButtonBar> m_spButtonBar;           // +0x1b0 "m_buttonBar"
    MS2Ptr<Unk_140acd6e0> m_spAddButton;                // +0x1c0 "m_addButton"
    int m_bLoaded;                                      // +0x1d0
    Unk_ScHotKeyState m_cur;                            // +0x1d8
    Unk_ScHotKeyState m_prev;                           // +0x1f0
    CStringW m_strRename;                               // +0x208
};
MS2_CHECK_SIZE(UISkillCompactControlDialog, 0x210);
MS2_CHECK_OFFSET(UISkillCompactControlDialog, m_lstConfig, 0x178);
MS2_CHECK_OFFSET(UISkillCompactControlDialog, m_strTab, 0x1a8);
MS2_CHECK_OFFSET(UISkillCompactControlDialog, m_spButtonBar, 0x1b0);
MS2_CHECK_OFFSET(UISkillCompactControlDialog, m_spAddButton, 0x1c0);
MS2_CHECK_OFFSET(UISkillCompactControlDialog, m_bLoaded, 0x1d0);
MS2_CHECK_OFFSET(UISkillCompactControlDialog, m_cur, 0x1d8);
MS2_CHECK_OFFSET(UISkillCompactControlDialog, m_prev, 0x1f0);
MS2_CHECK_OFFSET(UISkillCompactControlDialog, m_strRename, 0x208);
