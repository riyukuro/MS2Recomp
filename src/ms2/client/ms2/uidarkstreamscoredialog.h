// uidarkstreamscoredialog.h - UIScoreDialog (RTTI .?AVUIScoreDialog@@, 0x178 bytes: an empty UIDialog subclass with
// two new virtual slots, 84 and 85) and UIDarkStreamScoreDialog (RTTI .?AVUIDarkStreamScoreDialog@@, 0x188 bytes), the
// dark stream minigame's score HUD ("DarkStreamScoreDialog", UI type 0x4ee4). Recovered from MapleStory2.exe KMS2_DEV
// x64 (2022-04-13); the unit is `?\uidarkstreamscoredialog.cpp` (0x140f35340-0x140f359b0 .text$mn, dir client\ms2).
// Header/unit name assumed (the class names; the exe has no assert path for them).
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable plus the IMessageListener-in-UIxxx one at +0x18.
// UIDarkStreamScoreDialog overrides slots 1 (class name), 22 (OnLoadComplete: push the score), 43 (place the movie
// root), 48 (UI type 0x4ee4), 84 (set the score) and 85 (push it to the swf as "setScore").
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIScoreDialog : public UIDialog
{
public:
    UIScoreDialog();                                                // 0x140f357a0
    virtual ~UIScoreDialog() = default;                      //  0 0x140f357e0 (??_G 0x140f35840)
    virtual void vfunc_84(int nScore) = 0;                          // 84 set the score
    virtual void vfunc_85() = 0;                                    // 85 push the score to the swf
};
MS2_CHECK_SIZE(UIScoreDialog, 0x178);

class UIDarkStreamScoreDialog : public UIScoreDialog
{
public:
    UIDarkStreamScoreDialog();                                      // 0x140f35340
    virtual ~UIDarkStreamScoreDialog();                             //  0 0x140f353f0 (??_G 0x140f35800)
    virtual CString GetTypeName();                                      //  1 0x140f35430 "DarkStreamScoreDialog"
    virtual void OnLoadComplete();                                  // 22 0x140f35550
    virtual void vfunc_43();                                        // 43 0x140f35480 (movie root position)
    virtual int vfunc_48();                                         // 48 0x140f35880 UI type id
    virtual void vfunc_84(int nScore);                              // 84 0x140f35590
    virtual void vfunc_85();                                        // 85 0x140f355d0
    void FUN_140f35660(int nOffsetY);                               // 0x140f35660 set m_nOffsetY, re-place the root
    void FUN_140f356a0(int nAlign);                                 // 0x140f356a0 set m_nAlign, re-place the root
private:
    MS2_LAYOUT_FRIEND;
    int m_nScore;                   // +0x178
    int m_nOffsetY;                 // +0x17c added to 0x82 as the root's y
    int m_nAlign;                   // +0x180 1; first argument of the root's vfunc_2
};
MS2_CHECK_SIZE(UIDarkStreamScoreDialog, 0x188);
MS2_CHECK_OFFSET(UIDarkStreamScoreDialog, m_nScore, 0x178);
MS2_CHECK_OFFSET(UIDarkStreamScoreDialog, m_nOffsetY, 0x17c);
MS2_CHECK_OFFSET(UIDarkStreamScoreDialog, m_nAlign, 0x180);
