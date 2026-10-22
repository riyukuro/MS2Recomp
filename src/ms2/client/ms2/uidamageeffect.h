// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uidamageeffect.h (name assumed: the
// .cpp's __FILE__ string is not in the exe for this unit, the header's never is).
//
// UIDamageEffect ("DamageEffect", UI type 0x4e3c, RTTI .?AVUIDamageEffect@@, 0x88 bytes): the red low-HP screen effect.
// Layout: UIHeadUpDisplay (0x70) + the UIStatusEventListener subobject at +0x70 (vptr only) + three fields. It listens for
// HP changes (listener slot 3), turns the "changeHP" flag on at or below a percentage threshold from the game options
// and fades the movie ("init", "changeHP", "onHide", "setAlpha").
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class UIDamageEffect : public UIHeadUpDisplay, public UIStatusEventListener
{
public:
    UIDamageEffect();                                               // 0x141910480 (m_2c = 1)
    virtual ~UIDamageEffect();                                      //  0 0x141910550 (??_G 0x141910ba0)
    virtual CString GetTypeName();                                      //  1 0x1419105b0 "DamageEffect"
    virtual void vfunc_3();                                         //  3 0x141910600 hide and leave the status listeners
    virtual void OnLoadComplete();                                  // 22 0x141910980 read the options, "init", first HP push
    virtual void vfunc_43();                                        // 43 0x1419108e0 validate the movie's root now
    virtual int vfunc_48() { return 0x4e3c; }                       // 48 0x141910be0 UI type id
    // UIStatusEventListener (+0x70) override: slot 3 (HP changed: current, maximum), 0x1419107d0
    virtual void vfunc_oa0_3(int a1, int a2);

    void FUN_141910660();                                           // "onHide" and leave the status listeners
    void FUN_141910700();                                           // enter the status listeners, push the HP now
    void FUN_141910ab0();                                           // read the threshold and the fade from the options
    static void FUN_141910b10(void*, void* a1);                     // empty (the first argument is unnamed)
    void FUN_141910b30(float fAlpha);                               // "setAlpha" when the movie is up

private:
    MS2_LAYOUT_FRIEND;
    int m_nLowHp;                                                   // +0x78 the low-HP flag last sent to the movie
    float m_fLowHpPercent;                                          // +0x7c percentage at or below which it is low (30.0)
    float m_fOption80;                                              // +0x80 option value (10.0), read with the threshold
};
MS2_CHECK_SIZE(UIDamageEffect, 0x88);
MS2_CHECK_OFFSET(UIDamageEffect, m_nLowHp, 0x78);
MS2_CHECK_OFFSET(UIDamageEffect, m_fLowHpPercent, 0x7c);
MS2_CHECK_OFFSET(UIDamageEffect, m_fOption80, 0x80);
