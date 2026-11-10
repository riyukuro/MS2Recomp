// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASSlider, the ActionScript slider wrapper of the GFx UI library.
// MS2-UNIT: ?\asslider.cpp
// MS2-RANGE: 0x1422ce570-0x1422ceac0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asslider.h (shared; Ghidra's FUN_<va> names are kept there). The accessors
// read / write the Number members of the AS Slider ("value", "maximum", "minimum", "position", "snapInterval").
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asslider.h"

#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

// @0x1422ce570
ASSlider::ASSlider(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1422ce5c0
ASSlider::~ASSlider()
{
}

// @0x1422ce5f0
void ASSlider::SetValue(float f)
{
    SetMemberFloat("value", f);
}
MS2_REPLACE_METHOD(0x1422CE5F0, ASSlider, SetValue, 43, 0xB02E9BC5);

// @0x1422ce630
float ASSlider::GetValue()
{
    return (float)GetMember("value").GetNumber();
}
MS2_REPLACE_METHOD(0x1422CE630, ASSlider, GetValue, 96, 0xF625FCB4);

// @0x1422ce6a0
void ASSlider::SetMaximum(float f)
{
    SetMemberFloat("maximum", f);
}
MS2_REPLACE_METHOD(0x1422CE6A0, ASSlider, SetMaximum, 43, 0xE93331B9);

// @0x1422ce6e0
float ASSlider::GetMaximum()
{
    return (float)GetMember("maximum").GetNumber();
}
MS2_REPLACE_METHOD(0x1422CE6E0, ASSlider, GetMaximum, 96, 0x130F2EF2);

// @0x1422ce750
void ASSlider::SetMinimum(float f)
{
    SetMemberFloat("minimum", f);
}
MS2_REPLACE_METHOD(0x1422CE750, ASSlider, SetMinimum, 43, 0x7FB2EF9D);

// @0x1422ce790
float ASSlider::GetMinimum()
{
    return (float)GetMember("minimum").GetNumber();
}
MS2_REPLACE_METHOD(0x1422CE790, ASSlider, GetMinimum, 96, 0x1E1CD5F1);

// @0x1422ce800
void ASSlider::SetPosition(float f)
{
    SetMemberFloat("position", f);
}
MS2_REPLACE_METHOD(0x1422CE800, ASSlider, SetPosition, 43, 0xF3A5660D);

// @0x1422ce840
float ASSlider::GetPosition()
{
    return (float)GetMember("position").GetNumber();
}
MS2_REPLACE_METHOD(0x1422CE840, ASSlider, GetPosition, 96, 0xE0F51450);

// @0x1422ce8b0
void ASSlider::SetSnapInterval(float f)
{
    SetMemberFloat("snapInterval", f);
}
MS2_REPLACE_METHOD(0x1422CE8B0, ASSlider, SetSnapInterval, 43, 0x4CE96E19);

// @0x1422ce8f0
float ASSlider::GetSnapInterval()
{
    return (float)GetMember("snapInterval").GetNumber();
}
MS2_REPLACE_METHOD(0x1422CE8F0, ASSlider, GetSnapInterval, 96, 0xEDC75B72);

// @0x1422ce960
void ASSlider::InvalidateSettings()
{
    Invoke("invalidateSettings");
}
MS2_REPLACE_METHOD(0x1422CE960, ASSlider, InvalidateSettings, 46, 0x568A40D0);

// @0x1422ce9a0
void ASSlider::AddValueChangeListener(const ASCallback& onChange, void* pUser)
{
    AddEventListener("valueChange", onChange, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422CE9A0, ASSlider, AddValueChangeListener, 113, 0xC77D355E);

// @0x1422cea20
void ASSlider::RemoveValueChangeListener(const ASCallback& onChange)
{
    RemoveEventListener("valueChange", onChange, false);
}
MS2_REPLACE_METHOD(0x1422CEA20, ASSlider, RemoveValueChangeListener, 82, 0xD35445FF);

// MS2-PIN: ??_GASSlider@@UEAAPEAXI@Z 0x1422cea80
