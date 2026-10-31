// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\monochromeeffectparam.cpp
// MS2-RANGE: 0x1414876d0-0x141487a20 .text$mn
// MS2-PIN: ??1MonochromeEffect@@UEAA@XZ 0x141487950
// MS2-PIN: ??1MonochromeEffectParam@@UEAA@XZ 0x141487970
// MS2-PIN: ??_GMonochromeEffect@@UEAAPEAXI@Z 0x141487990
// MS2-PIN: ??_GMonochromeEffectParam@@UEAAPEAXI@Z 0x1414879d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\monochromeeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "monochromeeffectparam.h"
#include <NiFixedString.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Post-processing service (singleton 0x1409a8b20): enable step by id.
class Unk_PostProcessSvc
{
public:
    void FUN_1416a3920(int nId, bool bOn);
};
class Unk_AeFeatureMgr   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AeFeatureMgr* FUN_1409a8b20();
};

int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
bool FUN_1409a5770(class NiFixedString&, float const*, int);   // C3: was FUN_1409a5770
extern NiFixedString DAT_143ae5350;                                             // saturation constant name

// @0x1414876d0
MonochromeEffectParam::MonochromeEffectParam()
    : CPostEffectParam(4), m_fSaturationMin(0.0f), m_fSaturationMax(1.0f)
{
}

// @0x141487730
void MonochromeEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CPostEffectParam::vfunc_1(pNode);
    XmlGetAttr((class TiXmlElement*)(pNode), "saturationMin", m_fSaturationMin);
    XmlGetAttr((class TiXmlElement*)(pNode), "saturationMax", m_fSaturationMax);
}
MS2_REPLACE_METHOD(0x141487730, MonochromeEffectParam, vfunc_1, 92, 0x51D8D943);

// @0x1414877a0
MonochromeEffect::MonochromeEffect(int nId, const CPostEffectParam* pParam)
    : CScreenEffectBase(nId, pParam), m_fSaturationMin(0.0f), m_fSaturationMax(1.0f)
{
    if (pParam)
    {
        m_fSaturationMin = static_cast<const MonochromeEffectParam*>(pParam)->m_fSaturationMin;
        m_fSaturationMax = static_cast<const MonochromeEffectParam*>(pParam)->m_fSaturationMax;
    }
}

// @0x141487840
void MonochromeEffect::vfunc_1()
{
    CScreenEffectBase::vfunc_1();
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416a3920(7, true);
}
MS2_REPLACE_METHOD(0x141487840, MonochromeEffect, vfunc_1, 45, 0x17925F21);

// @0x141487880
void MonochromeEffect::vfunc_4()
{
    CScreenEffectBase::vfunc_4();
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416a3920(7, false);
}
MS2_REPLACE_METHOD(0x141487880, MonochromeEffect, vfunc_4, 45, 0x7CD6796C);

// @0x1414878c0
void MonochromeEffect::vfunc_7(int nState, float fAlpha)
{
    float fT = fAlpha;
    switch (nState)
    {
    case 1:
        fT = 1.0f - fAlpha;
        break;
    }
    float fSaturation = (m_fSaturationMax - m_fSaturationMin) * fT + m_fSaturationMin;
    FUN_1409a5770(*(class NiFixedString*)&(DAT_143ae5350), &fSaturation, 1);
}
MS2_REPLACE_METHOD(0x1414878c0, MonochromeEffect, vfunc_7, 138, 0xD83FE52B);

// @0x141487a10
int MonochromeEffect::vfunc_5()
{
    return 4;
}
