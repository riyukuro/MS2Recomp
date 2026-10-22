// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiexpbar.h (name assumed: the class
// name; the exe has no assert path for it).
//
// UIExpBar (RTTI .?AVUIExpBar@@, 0x78 bytes) is the HUD experience bar ("ExpBar", UI type 0x4e27). Like the adventure
// level bar it is UIHeadUpDisplay (0x70) + the UIStatusEventListener subobject at +0x70, with no fields of its own.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/asdata.h"

class UIExpBar : public UIHeadUpDisplay, public UIStatusEventListener
{
public:
    UIExpBar();                                                     // 0x141931eb0 (m_2c = 0xf)
    virtual ~UIExpBar();                                            //  0 0x141931f30 (??_G 0x141933100)
    virtual CString GetTypeName();                                      //  1 0x141931f90 "ExpBar"
    virtual void vfunc_2();                                         //  2 0x141931fe0 show unless the cinematic gate is on
    virtual void vfunc_3();                                         //  3 0x141932020 hide and leave the status listeners
    virtual void OnLoadComplete();                                  // 22 0x1419326a0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141932b10 "OnClickBar"
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x141932bc0 m_30 = new ASGameEntity
    virtual void vfunc_43();                                        // 43 0x1419325b0 scale the bar
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x141932730 "getExp" tooltip
    virtual int vfunc_48() { return 0x4e27; }                       // 48 0x141933140 UI type id
    // UIStatusEventListener (+0x70) override: slot 20 (the status/exp changed), 0x141932b90
    virtual void vfunc_oa0_20(int a1);

    void FUN_141932080(const unsigned int& nFlags);                 // push "setExp" (bit 0: percent text)
    __int64 FUN_1419322a0();                                        // current exp
    __int64 FUN_1419322e0();                                        // exp of one level
    __int64 FUN_141932340();                                        // rest exp
    void FUN_141932380(int nVisible);                               // show/hide the "m_point" clip
    void FUN_141932430();                                           // show/hide the bar clip by the mount state
};
MS2_CHECK_SIZE(UIExpBar, 0x78);
