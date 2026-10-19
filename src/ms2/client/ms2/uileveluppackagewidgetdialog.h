// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uieventwidgetdialog.h (name assumed; the
// .cpp's __FILE__ string is not in the exe).
//
// UIEventWidgetDialog (RTTI .?AVUIEventWidgetDialog@@, 0x188 bytes): base of the small event widgets that sit at the edge of
// the HUD. It owns the ItemSlotBinder that binds the widget's reward item and a static list of all live widgets.
// Derived widgets say when they apply (vfunc_84), fill the movie data (vfunc_85) and react to the two buttons
// (vfunc_86 "onClickReward", vfunc_87 "onOpenUI").
//   UILevelUpPackageWidgetDialog (0x1a0 bytes, UI type 0x4f5e): the level-up package quest reward. Also a quest and a
//   status listener.
//   UIBurningEventWidgetDialog (0x1a8 bytes, UI type 0x4f6a): the burning level-up event reward. Also a status listener.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset> (invented names).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/dclevelrange.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)

class ASObj;
class Unk_MyPCBurningEvent;

class UIEventWidgetDialog : public UIDialog
{
public:
    UIEventWidgetDialog();                                                      // 0x140c58d30
    virtual ~UIEventWidgetDialog();                                             //  0 0x140c58de0
    virtual CString vfunc_1();                                                  //  1 0x140c58e60
    virtual CString vfunc_7();                                                  //  7 0x140c58eb0
    virtual int vfunc_65();                                                     // 65 0x140c58f00
    virtual void vfunc_67();                                                    // 67 0x140c58f30
    virtual void OnLoadComplete();                                              // 22 0x140c58f90
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                // 28 0x140c58fc0 onClickReward / onOpenUI
    virtual void vfunc_43();                                                    // 43 0x140c59070 keep the widget on screen
    virtual int vfunc_84() { return 0; }                                        // 84 (COMDAT 0x140c5bd..) the widget applies
    virtual int vfunc_85(ASObj& rObj);                                          // 85 0x140c592f0 fill the movie data
    virtual void vfunc_86();                                                    // 86 (COMDAT 0x140c5c520) reward button
    virtual void vfunc_87();                                                    // 87 (COMDAT 0x140c5c510) open the linked window
    virtual int vfunc_48() { return 0x4f69; }                                   // 48 (COMDAT 0x140c5bd60)

    void FUN_140c59210();                                                       // send the data to the movie
    static void FUN_140c59350();                                                // refresh every open widget

protected:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ItemSlotBinder> m_178;                                               // +0x178 the reward item slot
};
MS2_CHECK_SIZE(UIEventWidgetDialog, 0x188);
MS2_CHECK_OFFSET(UIEventWidgetDialog, m_178, 0x178);

class UILevelUpPackageWidgetDialog : public UIEventWidgetDialog, public UIQuestEventListener, public UIStatusEventListener
{
public:
    UILevelUpPackageWidgetDialog();                                             // 0x140c593d0
    virtual ~UILevelUpPackageWidgetDialog();                                    //  0 0x140c59500
    virtual CString vfunc_1();                                                  //  1 0x140c59590 "LevelUpPackageWidget"
    virtual int vfunc_65();                                                     // 65 0x140c595e0
    virtual void vfunc_67();                                                    // 67 0x140c59680
    virtual int vfunc_84();                                                     // 84 0x140c597f0
    virtual int vfunc_85(ASObj& rObj);                                          // 85 0x140c59830
    virtual void vfunc_86();                                                    // 86 0x140c59b30 receive the reward
    virtual void vfunc_87();                                                    // 87 0x140c59ba0 open the level-up guide
    virtual int vfunc_48() { return 0x4f5e; }                                   // 48 (COMDAT 0x140c5bd70)
    virtual void vfunc_o178_8(void* pQuest);                                    // 0x140c59740 a quest was updated
    virtual void vfunc_oa0_9(unsigned short nLevel);                            // 0x140c59710 level changed

    int FUN_140c59bd0(Unk_DcLevelRange& rRange);                                // the current package quest and its level range

private:
    MS2_LAYOUT_FRIEND;
    int m_198;                                                                  // +0x198 the package quest
};
MS2_CHECK_SIZE(UILevelUpPackageWidgetDialog, 0x1a0);
MS2_CHECK_OFFSET(UILevelUpPackageWidgetDialog, m_198, 0x198);

class UIBurningEventWidgetDialog : public UIEventWidgetDialog, public UIStatusEventListener
{
public:
    UIBurningEventWidgetDialog();                                               // 0x140c59f10
    virtual ~UIBurningEventWidgetDialog();                                      //  0 0x140c5a030
    virtual CString vfunc_1();                                                  //  1 0x140c5a0b0 "BurningEventWidget"
    virtual int vfunc_65();                                                     // 65 0x140c5a130
    virtual void vfunc_67();                                                    // 67 0x140c5a190
    virtual int vfunc_84();                                                     // 84 0x140c5a220
    virtual int vfunc_85(ASObj& rObj);                                          // 85 0x140c5a420
    virtual void vfunc_86();                                                    // 86 0x140c5a930
    virtual int vfunc_48() { return 0x4f6a; }                                   // 48 (COMDAT 0x140c5bd50)
    virtual void vfunc_oa0_9(unsigned short nLevel);                            // 0x140c5a1f0 level changed

    void FUN_140c5a100(void* pEvent);                                           // 0x140c5a100 send the data to the movie (the event is unused)
    void FUN_140c5ab30(MS2Ptr<Unk_MyPCBurningEvent> spEvent);                   // 0x140c5ab30 remember the event
    MS2Ptr<Unk_MyPCBurningEvent> FUN_140c5ab80();                               // 0x140c5ab80 the remembered event

private:
    MS2_LAYOUT_FRIEND;
    int m_190;                                                                  // +0x190 the shown event id
    MS2Ptr<Unk_MyPCBurningEvent> m_198;                                         // +0x198
};
MS2_CHECK_SIZE(UIBurningEventWidgetDialog, 0x1a8);
MS2_CHECK_OFFSET(UIBurningEventWidgetDialog, m_190, 0x190);
MS2_CHECK_OFFSET(UIBurningEventWidgetDialog, m_198, 0x198);
