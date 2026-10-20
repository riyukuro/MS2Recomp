// asgaugecontrol.h - PLACEHOLDER for ASGaugeControl (RTTI .?AVASGaugeControl@@, an ASUIComponent, 0x88 bytes): the
// Scaleform gauge bar clip. NOT an original header. The class's own unit (?\asgaugecontrol.cpp, 0x1409b9ee0..) keeps a
// unit-local copy; this header declares what other units call. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASGaugeControl : public ASUIComponent
{
public:
    ASGaugeControl(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1409b9ee0
    virtual ~ASGaugeControl();                                      // 0x1409b9f30
    void SetValue(int a1, int a2);                                  // 0x1409b9f60 setValue
    void SetCurValue(int nValue);                                   // 0x1409b9fb0 setCurValue
    void SetMaxValue(int nValue);                                   // 0x1409b9ff0 setMaxValue
};
MS2_CHECK_SIZE(ASGaugeControl, 0x88);
