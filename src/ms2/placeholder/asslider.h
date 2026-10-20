// asslider.h - PLACEHOLDER for ASSlider (RTTI .?AVASSlider@@, vftable 0x14310d1e0, 25 slots = the ASUIComponent slots,
// scalar deleting destructor 0x1422cea80): the ActionScript slider wrapper of the GFx UI library. NOT an original
// header. The exe allocates 0x88 bytes for it (AScript child factory 0x140a57ea0). Older units carry unit-local views
// of the same object (Unk_GoSlider, Unk_GpSlider, Unk_HudSlider, ...). Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/delegate.h"

class ASSlider : public ASUIComponent
{
public:
    ASSlider(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422ce570
    virtual ~ASSlider();                                            // 0 0x1422ce5c0 (scalar deleting 0x1422cea80)
    // ASUIComponent's own slots (0x1422c7260 / 0x1422c7ec0-0x1422c80c0: invalidate(...), validateNow), redeclared here
    // because asuicomponent.h does not list them yet (astextinput.h declares slot 24 as vfunc_24(int)).
    virtual void vfunc_3(int nVisible);                             // 3 0x1422c7260
    virtual void vfunc_16();                                        // 16 0x1422c7ec0 invalidate()
    virtual void vfunc_17();                                        // 17 0x1422c7f00 invalidate("size")
    virtual void vfunc_18();                                        // 18 0x1422c7f40 invalidate("data")
    virtual void vfunc_19();                                        // 19 0x1422c7f80 invalidate("state")
    virtual void vfunc_20();                                        // 20 0x1422c7fc0 invalidate("settings")
    virtual void vfunc_21();                                        // 21 0x1422c8000 invalidate("renderers")
    virtual void vfunc_22();                                        // 22 0x1422c8040 invalidate("scrollBar")
    virtual void vfunc_23();                                        // 23 0x1422c8080 invalidate("selectedIndex")
    virtual void vfunc_24(bool bInvalidate);                        // 24 0x1422c80c0 validateNow (invalidate() first if set)
    // recovered with ?\asslider.cpp (src/ms2/gfxui/asslider.cpp): the AS Slider members, read as a Number and narrowed
    void FUN_1422ce5f0(float fValue);                               // 0x1422ce5f0 set "value"
    float FUN_1422ce630();                                          // 0x1422ce630 "value"
    void FUN_1422ce6a0(float fMax);                                 // 0x1422ce6a0 set "maximum"
    float FUN_1422ce6e0();                                          // 0x1422ce6e0 "maximum"
    void FUN_1422ce750(float fMin);                                 // 0x1422ce750 set "minimum"
    float FUN_1422ce790();                                          // 0x1422ce790 "minimum"
    void FUN_1422ce800(float fValue);                               // 0x1422ce800 set "position" (the current value)
    float FUN_1422ce840();                                          // 0x1422ce840 "position" (the current value)
    void FUN_1422ce8b0(float fInterval);                            // 0x1422ce8b0 set "snapInterval"
    float FUN_1422ce8f0();                                          // 0x1422ce8f0 "snapInterval"
    void FUN_1422ce960();                                           // 0x1422ce960 invalidateSettings()
    // registers / removes the "valueChange" callback (UIMeratMarketDialog); pUser comes back in Params::pUserData
    void FUN_1422ce9a0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, void* pUser);   // 0x1422ce9a0
    void FUN_1422cea20(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange);                // 0x1422cea20
};
MS2_CHECK_SIZE(ASSlider, 0x88);
