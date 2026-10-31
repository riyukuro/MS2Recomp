// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\gaussianblureffectparam.cpp
// MS2-RANGE: 0x140cfd2a0-0x140cfd6f0 .text$mn
// MS2-PIN: ??1GaussianBlurEffect@@UEAA@XZ 0x140cfd620
// MS2-PIN: ??1GaussianBlurEffectParam@@UEAA@XZ 0x140cfd640
// MS2-PIN: ??_GGaussianBlurEffect@@UEAAPEAXI@Z 0x140cfd660
// MS2-PIN: ??_GGaussianBlurEffectParam@@UEAAPEAXI@Z 0x140cfd6a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gaussianblureffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gaussianblureffectparam.h"
#include <NiFixedString.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cgameoption.h"

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

// Render target size: renderer wrapper (singleton 0x1409a8b10) -> back buffer (0x1409a8ac0) -> width / height.
class Unk_RenderTarget
{
public:
    unsigned int FUN_1409a8ab0();   // width
    unsigned int FUN_1409a8aa0();   // height
};
class Unk_RendererWrap
{
public:
    Unk_RenderTarget* FUN_1409a8ac0();
};

int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
bool FUN_1409a5770(class NiFixedString&, float const*, int);   // C3: was FUN_1409a5770
extern NiFixedString DAT_143ae5460;                                             // blur offset x constant name
extern NiFixedString DAT_143ae5468;                                             // blur offset y constant name

// @0x140cfd2a0
GaussianBlurEffectParam::GaussianBlurEffectParam()
    : CPostEffectParam(0x13), m_fOffsetMin(0.0f), m_fOffsetMax(1.0f)
{
}

// @0x140cfd300
void GaussianBlurEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CPostEffectParam::vfunc_1(pNode);
    XmlGetAttr((class TiXmlElement*)(pNode), "offsetMin", m_fOffsetMin);
    XmlGetAttr((class TiXmlElement*)(pNode), "offsetMax", m_fOffsetMax);
}
MS2_REPLACE_METHOD(0x140cfd300, GaussianBlurEffectParam, vfunc_1, 92, 0x37F14C03);

// @0x140cfd370
GaussianBlurEffect::GaussianBlurEffect(int nId, const CPostEffectParam* pParam)
    : CScreenEffectBase(nId, pParam), m_fOffsetMin(0.0f), m_fOffsetMax(1.0f)
{
    if (pParam)
    {
        m_fOffsetMin = static_cast<const GaussianBlurEffectParam*>(pParam)->m_fOffsetMin;
        m_fOffsetMax = static_cast<const GaussianBlurEffectParam*>(pParam)->m_fOffsetMax;
    }
}

// @0x140cfd410
void GaussianBlurEffect::vfunc_1()
{
    CScreenEffectBase::vfunc_1();
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416a3920(0xb, true);
}
MS2_REPLACE_METHOD(0x140cfd410, GaussianBlurEffect, vfunc_1, 45, 0x6DD405AA);

// @0x140cfd450
void GaussianBlurEffect::vfunc_4()
{
    CScreenEffectBase::vfunc_4();
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416a3920(0xb, false);
}
MS2_REPLACE_METHOD(0x140cfd450, GaussianBlurEffect, vfunc_4, 45, 0xF44CA84E);

// @0x140cfd490
void GaussianBlurEffect::vfunc_7(int nState, float fAlpha)
{
    float fT = fAlpha;
    switch (nState)
    {
        break;
    case 1:
        fT = 1.0f - fAlpha;
        break;
    }
    float fOffset = (m_fOffsetMax - m_fOffsetMin) * fT + m_fOffsetMin;
    unsigned int nWidth = reinterpret_cast<Unk_RendererWrap*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0()->FUN_1409a8ab0();
    unsigned int nHeight = reinterpret_cast<Unk_RendererWrap*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0()->FUN_1409a8aa0();
    if (nWidth == 0 || nHeight == 0)
        return;
    if (nWidth >= nHeight)
    {
        float fX = fOffset * ((float)nHeight / (float)nWidth);
        float fY = fOffset;
        FUN_1409a5770(*(class NiFixedString*)&static_cast<class NiFixedString const&>(DAT_143ae5460), &fX, 1);
        FUN_1409a5770(*(class NiFixedString*)&static_cast<class NiFixedString const&>(DAT_143ae5468), &fY, 1);
    }
    else
    {
        float fX = fOffset;
        float fY = fOffset * ((float)nWidth / (float)nHeight);
        FUN_1409a5770(*(class NiFixedString*)&static_cast<class NiFixedString const&>(DAT_143ae5460), &fX, 1);
        FUN_1409a5770(*(class NiFixedString*)&static_cast<class NiFixedString const&>(DAT_143ae5468), &fY, 1);
    }
}
MS2_REPLACE_METHOD(0x140cfd490, GaussianBlurEffect, vfunc_7, 394, 0xDB8F90F3);

// @0x140cfd6e0
int GaussianBlurEffect::vfunc_5()
{
    return 0x13;
}
