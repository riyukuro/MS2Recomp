// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uikillcount.h (name assumed: the .cpp's
// __FILE__ string is not in the exe for this unit).
//
// UIKillCount ("KillCount", UI type 0x4e51, RTTI .?AVUIKillCount@@, 0x88 bytes): the HUD kill combo. Layout:
// UIHeadUpDisplay (0x70) + the CKillCount at +0x70 (vptr + 2 ints) + the shown count and the minimum count to show.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/ckillcount.h"

class UIKillCount : public UIHeadUpDisplay
{
public:
    UIKillCount();                                                  // 0x1419df070 (m_2c = 0x14)
    virtual ~UIKillCount();                                         //  0 0x1419df130 (??_G 0x1419df820)
    virtual CString GetTypeName();                                      //  1 0x1419df180 "KillCount"
    virtual void vfunc_2();                                         //  2 0x1419df1d0 show (the base's)
    virtual void vfunc_3();                                         //  3 0x1419df1f0 hide, forget the shown count
    virtual void vfunc_15();                                        // 15 0x1419df490 hide the count when the combo timed out
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419df440
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x1419df510 m_30 = new ASGameEntity
    virtual void vfunc_43();                                        // 43 0x1419df3a0 validate the movie's root now
    virtual int vfunc_48() { return 0x4e51; }                       // 48 0x1419df860 UI type id

    void FUN_1419df220();                                           // "hide" the movie's count
    void FUN_1419df2a0(void* pKilled);                              // a monster died: count a kill of the local player
    void FUN_1419df580();                                           // show the count, say the combo text
    void FUN_1419df6a0();                                           // the local player's chat balloon with the combo text

private:
    MS2_LAYOUT_FRIEND;
    CKillCount m_kill;                                              // +0x70
    int m_nShown;                                                   // +0x80 the count shown now (0 = nothing)
    int m_nMinShow;                                                 // +0x84 smallest count that is shown (an option)
};
MS2_CHECK_SIZE(UIKillCount, 0x88);
MS2_CHECK_OFFSET(UIKillCount, m_kill, 0x70);
MS2_CHECK_OFFSET(UIKillCount, m_nShown, 0x80);
MS2_CHECK_OFFSET(UIKillCount, m_nMinShow, 0x84);
