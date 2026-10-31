// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\radialblureffectparam.cpp
// MS2-RANGE: 0x1416ec120-0x1416ec580 .text$mn
// MS2-PIN: ??1RadialBlurEffect@@UEAA@XZ 0x1416ec390
// MS2-PIN: ??1RadialBlurEffectParam@@UEAA@XZ 0x1416ec3b0
// MS2-PIN: ??_GRadialBlurEffect@@UEAAPEAXI@Z 0x1416ec3d0
// MS2-PIN: ??_GRadialBlurEffectParam@@UEAAPEAXI@Z 0x1416ec410
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\radialblureffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "radialblureffectparam.h"
#include <NiFixedString.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Post-processing service (singleton 0x1409a8b20): enable step by id.
class Unk_PostProcessSvc
{
public:
    void FUN_1416a3920(int nId, bool bOn);
};
class Unk_AeFeatureMgr   // C3: static member view for the former free stand-ins
{
public:
    static class Unk_AeFeatureMgr* FUN_1409a8b20();
};

int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);     // TinyXML float attribute
void FUN_1409a5770(const NiFixedString& kName, const float* pf, int n);         // validated global shader constant
extern NiFixedString DAT_143ae5458;                                             // radial blur distance constant name

// @0x1416ec120
RadialBlurEffectParam::RadialBlurEffectParam()
    : CPostEffectParam(5), m_fDistMin(0.0f), m_fDistMax(1.0f)
{
}

// @0x1416ec180
void RadialBlurEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CPostEffectParam::vfunc_1(pNode);
    FUN_140873360(pNode, "distMin", m_fDistMin);
    FUN_140873360(pNode, "distMax", m_fDistMax);
}
MS2_REPLACE_METHOD(0x1416ec180, RadialBlurEffectParam, vfunc_1, 92, 0xDA0ADB01);

// @0x1416ec1f0
RadialBlurEffect::RadialBlurEffect(int nId, const CPostEffectParam* pParam)
    : CScreenEffectBase(nId, pParam), m_fDistMin(0.0f), m_fDistMax(1.0f)
{
    m_fDistMin = static_cast<const RadialBlurEffectParam*>(pParam)->m_fDistMin;
    m_fDistMax = static_cast<const RadialBlurEffectParam*>(pParam)->m_fDistMax;
}

// @0x1416ec280
void RadialBlurEffect::vfunc_1()
{
    CScreenEffectBase::vfunc_1();
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416a3920(9, true);
}
MS2_REPLACE_METHOD(0x1416ec280, RadialBlurEffect, vfunc_1, 45, 0x57C7625C);

// @0x1416ec2c0
void RadialBlurEffect::vfunc_4()
{
    CScreenEffectBase::vfunc_4();
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416a3920(9, false);
}
MS2_REPLACE_METHOD(0x1416ec2c0, RadialBlurEffect, vfunc_4, 45, 0x829D7CCC);

// @0x1416ec300
void RadialBlurEffect::vfunc_7(int nState, float fAlpha)
{
    float fT = fAlpha;
    switch (nState)
    {
    case 1:
        fT = 1.0f - fAlpha;
        break;
    }
    float fDist = (m_fDistMax - m_fDistMin) * fT + m_fDistMin;
    FUN_1409a5770(DAT_143ae5458, &fDist, 1);
}
MS2_REPLACE_METHOD(0x1416ec300, RadialBlurEffect, vfunc_7, 138, 0x255E4307);

// @0x1416ec450
int RadialBlurEffect::vfunc_5()
{
    return 5;
}

MS2_EMIT_CRT_MEMMOVE_S();  // memmove_s 0x1416ec460
