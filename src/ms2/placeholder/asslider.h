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
    virtual ~ASSlider();
    float FUN_1422ce840();                                          // 0x1422ce840 the current value
    void FUN_1422ce800(float fValue);                               // 0x1422ce800 set the current value
    void FUN_1422ce6a0(float fMax);                                 // 0x1422ce6a0 set the maximum
    void FUN_1422ce9a0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, int nUser);   // 0x1422ce9a0 registers the change callback (UIMeratMarketDialog)
};
MS2_CHECK_SIZE(ASSlider, 0x88);
