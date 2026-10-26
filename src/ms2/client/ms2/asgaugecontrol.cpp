// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASGaugeControl: the Scaleform gauge bar clip (a value, a
// current value and a maximum) plus the two AScript::Invoke instantiations its setters are the sole emitters of.
// File name taken from the class name (this unit is where the class's ctor/dtor and vftable were emitted).
// MS2-UNIT: ?\asgaugecontrol.cpp
// MS2-RANGE: 0x1409b9ee0-0x1409ba1d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\asgaugecontrol.cpp"
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int nValue);   // set an Int value (ascommondepth.cpp)

// The gauge bar clip (nothing on top of the component base).
class ASGaugeControl : public ASUIComponent
{
public:
    ASGaugeControl(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASGaugeControl();
    void SetValue(int a1, int a2);          // @0x1409b9f60 ASGaugeControl.setValue
    void SetCurValue(int nValue);           // @0x1409b9fb0 ASGaugeControl.setCurValue
    void SetMaxValue(int nValue);           // @0x1409b9ff0 ASGaugeControl.setMaxValue
};
MS2_CHECK_SIZE(ASGaugeControl, 0x88);

// @0x1409b9ee0
ASGaugeControl::ASGaugeControl(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1409b9f30
ASGaugeControl::~ASGaugeControl()
{
}

// @0x1409b9f60
void ASGaugeControl::SetValue(int a1, int a2)
{
    FUN_1409ba0d0("setValue", a1, a2);
}

// @0x1409b9fb0
void ASGaugeControl::SetCurValue(int nValue)
{
    Invoke("setCurValue", nValue);
}

// @0x1409b9ff0
void ASGaugeControl::SetMaxValue(int nValue)
{
    Invoke("setMaxValue", nValue);
}

// ---- the Invoke back ends this unit emits ----
// A discarded call result is the callee's return slot: the caller reserves the Value buffer, the callee constructs
// into it (the copy ctor at the end of FUN_1422bb8f0) and the caller destroys it, so the buffer itself is never
// default-constructed.

// @0x1409ba030
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409ba0d0
inline Scaleform::GFx::Value AScript::FUN_1409ba0d0(const char* szMethod, int a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}
