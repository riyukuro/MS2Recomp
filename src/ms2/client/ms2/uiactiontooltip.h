// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiactiontooltip.h (name assumed: the
// .cpp's __FILE__ string is not in the exe for this unit).
//
// UIActionTooltip ("ActionTooltip", UI type 0x4e5c, RTTI .?AVUIActionTooltip@@, 0x98 bytes): the tooltip next to the
// player that names the action the action key would run now (talk, portal, gather, ...). It follows the current action
// of MyPC's action key manager (actionkeyobject.h): shows the action's title and text at the action's target point
// (projected to the screen) or at the screen center when the action has no target, and hides when there is none.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/client/ms2/actionkeyobject.h"

class UIActionTooltip : public UIHeadUpDisplay
{
public:
    UIActionTooltip();                                              // 0x1418b1520 (m_2c = 9, m_28 = next UI layer)
    virtual ~UIActionTooltip();                                     //  0 0x1418b23f0 (??_G 0x1418b2480)
    virtual CString vfunc_1();                                      //  1 0x1418b15e0 "ActionTooltip"
    virtual void vfunc_2();                                         //  2 0x1418b16a0 show (the base's)
    virtual void vfunc_3();                                         //  3 0x1418b16c0 hide, then the base's hide
    virtual void vfunc_15();                                        // 15 0x1418b1630 per-frame: show / move / hide
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x1418b1890 m_30 = new ASGameEntity
    virtual void vfunc_43();                                        // 43 0x1418b1690
    virtual int vfunc_48() { return 0x4e5c; }                       // 48 0x1418b24c0 UI type id

    void FUN_1418b16f0();                                           // refresh from the current action
    ActionKeyObject* GetAction();                               // the action shown
    CStringW GetTitle();                                       // the title shown
    CStringW GetText();                                       // the text shown
    ActionKeyObject* FUN_1418b1900();                               // the current action of the local player (NULL without)
    int FUN_1418b1950();                                            // string table id of the key hint
    CStringW FUN_1418b1990();                                       // the key hint text
    CStringW FUN_1418b1a20();                                       // the current action's text ("" without)
    void FUN_1418b1ab0();                                           // take the current action and show it
    void FUN_1418b1e60();                                           // forget the action and hide
    void FUN_1418b1ef0();                                           // place the movie at the target point
    int FUN_1418b2140();                                            // the tooltip must stay hidden now
    int FUN_1418b23a0();                                            // the current action's type (0x1e: none)

private:
    MS2_LAYOUT_FRIEND;
    ActionKeyObject* m_pAction;                                     // +0x70 the action shown (NULL: hidden)
    Unk_AkoTarget m_kTarget;                                        // +0x78 the action's target point
    CStringW m_strTitle;                                            // +0x88
    CStringW m_strText;                                             // +0x90
};
MS2_CHECK_SIZE(UIActionTooltip, 0x98);
MS2_CHECK_OFFSET(UIActionTooltip, m_pAction, 0x70);
MS2_CHECK_OFFSET(UIActionTooltip, m_kTarget, 0x78);
MS2_CHECK_OFFSET(UIActionTooltip, m_strTitle, 0x88);
MS2_CHECK_OFFSET(UIActionTooltip, m_strText, 0x90);
