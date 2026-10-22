// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAdventureLevelExpBar (RTTI .?AVUIAdventureLevelExpBar@@,
// 0x78 bytes), the HUD bar that shows the adventure-level experience. Like UIStanceBar its unit has no __FILE__ string,
// so it lives under unnamed/. Layout: UIHeadUpDisplay (0x70) + the UIStatusEventListener subobject at +0x70 (vptr only).
// The class has no fields of its own. Member names are invented where the exe has none (FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/asdata.h"

class UIAdventureLevelExpBar : public UIHeadUpDisplay, public UIStatusEventListener
{
public:
    UIAdventureLevelExpBar();                                       // 0x140ba6b20 (m_2c = 0x10)
    virtual ~UIAdventureLevelExpBar();                              //  0 0x140ba6ba0 (??_G 0x140ba7c20)
    virtual CString GetTypeName();                                      //  1 0x140ba6c00 "AdventureLevelExpBar"
    virtual void vfunc_2();                                         //  2 0x140ba6c50 show unless the cinematic gate is on
    virtual void vfunc_3();                                         //  3 0x140ba6c90 hide and leave the status listeners
    virtual void OnLoadComplete();                                  // 22 0x140ba72b0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ba7660 "OnClickBar"
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x140ba7710 m_30 = new ASGameEntity
    virtual void vfunc_43();                                        // 43 0x140ba7360 scale the bar, push the bar height
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x140ba74a0 "getExp" tooltip
    virtual int vfunc_48() { return 0x4f66; }                       // 48 0x140ba7c70 UI type id
    // UIStatusEventListener (+0x70) override: slot 20 (the status/exp changed), 0x140ba7630
    virtual void vfunc_oa0_20(int a1);

    void FUN_140ba6cf0(__int64 nGain);                              // push the bar state ("setPoint") for a gain of nGain
    __int64 FUN_140ba6fa0();                                        // current exp
    __int64 FUN_140ba6fc0();                                        // exp of one level
    __int64 FUN_140ba6ff0();                                        // exp shown for the player's adventure level
    void FUN_140ba7080(int nVisible);                               // show/hide the "m_point" clip
    void FUN_140ba7130();                                           // show/hide the bar clip by the mount state
};
MS2_CHECK_SIZE(UIAdventureLevelExpBar, 0x78);
