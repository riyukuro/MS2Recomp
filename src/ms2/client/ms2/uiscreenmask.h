// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiscreenmask.h (name assumed: the
// .cpp's __FILE__ string is not in the exe for this unit).
//
// UIScreenMask ("ScreenMask", UI type 0x4e55, RTTI .?AVUIScreenMask@@, 0x70 bytes): the full-screen mask the game
// drops over the world (an image/effect from the current field's data). It is a plain UIHeadUpDisplay: it has no
// fields of its own (the ctor only writes the inherited m_2c = 10 and m_58 = 0), and it loads the movie's "load"
// method with the field's effect name. Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class UIScreenMask : public UIHeadUpDisplay
{
public:
    UIScreenMask();                                                 // 0x141ad0650 (m_58 = 0, m_2c = 10)
    virtual ~UIScreenMask();                                        //  0 0x141ad06b0 (??_G 0x141ad0b10)
    virtual CString GetTypeName();                                      //  1 0x141ad06f0 "ScreenMask"
    virtual void vfunc_2();                                         //  2 0x141ad0740 show (m_2c = 10)
    virtual void vfunc_3();                                         //  3 0x141ad0770 hide
    virtual void OnLoadInit();                                      // 20 0x141ad0790 the movie's "load" method with the effect name
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x141ad0aa0 make the component of the root
    virtual void vfunc_43();                                        // 43 0x141ad08c0 resize the component to the screen
    virtual int vfunc_48() { return 0x4e55; }                       // 48 0x141ad0b50 UI type id

    CString FUN_141ad09e0();                                        // 0x141ad09e0 the mask's effect name (this unused)
};
MS2_CHECK_SIZE(UIScreenMask, 0x70);
