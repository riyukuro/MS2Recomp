// asradiobutton.h - PLACEHOLDER for ASRadioButton (RTTI .?AVASRadioButton@@, an ASButton, vftable 0x14310cf50). NOT an
// original header. It reuses the ASButton slots and adds no virtuals or members (ctor 0x1422ce4b0 only calls ASButton's
// and stores the vftable). Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asbutton.h"

class ASRadioButton : public ASButton
{
public:
    ASRadioButton(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422ce4b0
    virtual ~ASRadioButton();                                       // 0x1422ce500
};
MS2_CHECK_SIZE(ASRadioButton, 0x88);
