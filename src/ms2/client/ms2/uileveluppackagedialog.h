// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uileveluppackagedialog.h (name assumed from
// the class name; the .cpp's __FILE__ string is not in the exe).
//
// UILevelUpPackageDialog ("LevelUpPackageDialog", UI type 0x4f2f): the level-up package window. It lists the grade 1 quests
// of the level steps (the package), shows the reward item of the selected step and lets the player receive the reward of a
// finished step. RTTI .?AVUILevelUpPackageDialog@@, 0x1e8 bytes, vftables (UIDialog), +0x18, UIQuestEventListener at +0x178
// and UIStatusEventListener at +0x180.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset> (invented names).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)

class ASData;
class ASObj;

class UILevelUpPackageDialog : public UIDialog, public UIQuestEventListener, public UIStatusEventListener
{
public:
    UILevelUpPackageDialog();                                                                   // 0x140ea44b0
    virtual ~UILevelUpPackageDialog();                                                          //  0 0x140ea45b0 (??_G 0x140ea5f30)
    virtual CString GetTypeName();                                                                  //  1 0x140ea4660
    virtual int vfunc_65();                                                                     // 65 0x140ea46b0
    virtual void vfunc_67();                                                                    // 67 0x140ea4750
    virtual void OnLoadComplete();                                                              // 22 0x140ea4830
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                // 28 0x140ea4890
    virtual int vfunc_48() { return 0x4f2f; }                                                   // 48 (COMDAT 0x140ea5f70)
    virtual void vfunc_o178_10(void* pQuest);                                                   // 0x140ea4a60 a quest was updated
    virtual void vfunc_oa0_9(unsigned short nLevel);                                            // 0x140ea49e0 level changed

    int FUN_140ea4b70();                                            // some package quest is still open
    void FUN_140ea4d00();                                           // send the level steps to the movie
    void FUN_140ea4f10(unsigned short nLevel);                      // show the reward of the step of nLevel
    void SendQuest(int nQuest);                                 // receive the reward of a quest
    void FUN_140ea5460(ASObj& rObj, int nQuest);                    // one level step row: state, level text, reward
    void FUN_140ea57d0(ASObj& rObj, int nQuest);                    // the item reward of a level step
    unsigned FUN_140ea5b50(unsigned short nLevel);                  // the reward item id of the step of nLevel
    unsigned short FUN_140ea5d10();                                 // the highest step level the player reached

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<CString> m_188;                                  // +0x188 names of the bound item slots
    ItemSlotBinder m_1a8;                                           // +0x1a8 binds the reward items
};
MS2_CHECK_SIZE(UILevelUpPackageDialog, 0x1e8);
MS2_CHECK_OFFSET(UILevelUpPackageDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UILevelUpPackageDialog, m_1a8, 0x1a8);
