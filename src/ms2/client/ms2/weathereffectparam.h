// weathereffectparam.h - the "Weather" effect (effect XML type 6): starts a fall type (rain/snow/...) in the weather
// manager and stops it on end. Param (CEffectParam) + runtime effect (CEffect). Owning unit:
// ?\weathereffectparam.cpp (0x141b77250-0x141b77810). Header name assumed from the unit path.
#pragma once
#include "ms2/client/ms2/effectparam.h"

// 0x4c bytes (padded 0x50). Overrides slots 1, 6.
class WeatherEffectParam : public CEffectParam
{
public:
    WeatherEffectParam();                                       // 0x141b77250
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x141b772a0 <... fallType>
    virtual CEffectPtr vfunc_6();                               // 6 0x141b772f0 new WeatherEffect
public:
    unsigned m_nFallType;           // +0x48 XML "fallType"
};
MS2_CHECK_SIZE(WeatherEffectParam, 0x50);
MS2_CHECK_OFFSET(WeatherEffectParam, m_nFallType, 0x48);

// 0x38 bytes. Implicit virtual dtor 0x141b774b0 (WeatherEffectParam: 0x141b774d0).
class WeatherEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x141b77590; ms_RTTI 0x143af77b8
public:
    WeatherEffect();                                            // 0x141b77390
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x141b773d0 capture fall type
    virtual void vfunc_4();                                     // 4 0x141b77430 start the weather
    virtual void vfunc_7();                                     // 7 0x141b77470 stop the weather
    virtual int vfunc_12();                                     // 12 0x141b774a0 return 6
public:
    unsigned m_nFallType;           // +0x30
};
MS2_CHECK_SIZE(WeatherEffect, 0x38);
MS2_CHECK_OFFSET(WeatherEffect, m_nFallType, 0x30);
