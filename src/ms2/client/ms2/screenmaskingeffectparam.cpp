// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\screenmaskingeffectparam.cpp
// MS2-RANGE: 0x140dca0b0-0x140dca750 .text$mn
// MS2-PIN: ??1ScreenMaskingEffect@@UEAA@XZ 0x140dca660
// MS2-PIN: ??1ScreenMaskingEffectParam@@UEAA@XZ 0x140dca690
// MS2-PIN: ??_GScreenMaskingEffect@@UEAAPEAXI@Z 0x140dca6c0
// MS2-PIN: ??_GScreenMaskingEffectParam@@UEAAPEAXI@Z 0x140dca700
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\screenmaskingeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "screenmaskingeffectparam.h"
#include <NiFixedString.h>
#include "ms2/placeholder/postprocesseffect.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"

// Main system (commonfiles singleton 0x14086d260): resource root path.
CMainSystem* FUN_14086d260();

// Resource manager (singleton 0x140a0afd0): texture load by path.
class Unk_ResourceMgr
{
public:
    Unk_PPSmartC FUN_141552f90(CString strPath, int nFlags);
};
Unk_ResourceMgr* FUN_140a0afd0();

// Post-processing service (singleton 0x1409a8b20): enable step by id.
class Unk_PostProcessSvc
{
public:
    void FUN_1416a3920(int nId, bool bOn);
};
Unk_PostProcessSvc* FUN_1409a8b20();

int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);     // TinyXML float attribute
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut); // TinyXML string attribute
void FUN_1409a5770(const NiFixedString& kName, const float* pf, int n);         // validated global shader constant
void FUN_1416ba640(Unk_PPSmartC spTexture);                                     // swap the live step's mask texture
extern NiFixedString DAT_143ae5340;                                             // mask blend constant name

// @0x140dca0b0
ScreenMaskingEffectParam::ScreenMaskingEffectParam()
    : CPostEffectParam(0x12), m_fBlendingMin(0.0f), m_fBlendingMax(1.0f), m_strTexture("title_make_ch.tga")
{
}

// @0x140dca130
void ScreenMaskingEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CPostEffectParam::vfunc_1(pNode);
    FUN_140873360(pNode, "blendingMin", m_fBlendingMin);
    FUN_140873360(pNode, "blendingMax", m_fBlendingMax);
    FUN_1408733e0(pNode, "texture", m_strTexture);
}
MS2_REPLACE_METHOD(0x140dca130, ScreenMaskingEffectParam, vfunc_1, 121, 0xE292A065);

// @0x140dca1b0
ScreenMaskingEffect::ScreenMaskingEffect(int nId, const CPostEffectParam* pParam)
    : CScreenEffectBase(nId, pParam), m_fBlendMin(0.0f), m_fBlendMax(1.0f)
{
    if (pParam)
    {
        if (static_cast<const ScreenMaskingEffectParam*>(pParam)->m_fBlendingMin > 0.0f)
            m_fBlendMin = static_cast<const ScreenMaskingEffectParam*>(pParam)->m_fBlendingMin;
        if (static_cast<const ScreenMaskingEffectParam*>(pParam)->m_fBlendingMax < 1.0f)
            m_fBlendMax = static_cast<const ScreenMaskingEffectParam*>(pParam)->m_fBlendingMax;
        m_strTexture = static_cast<const ScreenMaskingEffectParam*>(pParam)->m_strTexture;
    }
}

// @0x140dca2a0
void ScreenMaskingEffect::vfunc_1()
{
    CScreenEffectBase::vfunc_1();
    FUN_1409a8b20()->FUN_1416a3920(8, true);
    float fBlend = 0.0f;
    CString strPath;
    strPath.Format("%s/Image/ScreenMask/%s", (const char*)FUN_14086d260()->GetDataPath(), (const char*)m_strTexture);
    FUN_1416ba640(FUN_140a0afd0()->FUN_141552f90(CString((const char*)strPath), 5));
    FUN_1409a5770(DAT_143ae5340, &fBlend, 1);
}
MS2_REPLACE_METHOD(0x140dca2a0, ScreenMaskingEffect, vfunc_1, 354, 0x89DB4D6F);

// @0x140dca410
void ScreenMaskingEffect::vfunc_4()
{
    CScreenEffectBase::vfunc_4();
    float fBlend = 0.0f;
    FUN_1409a8b20()->FUN_1416a3920(8, false);
    FUN_1409a5770(DAT_143ae5340, &fBlend, 1);
}
MS2_REPLACE_METHOD(0x140dca410, ScreenMaskingEffect, vfunc_4, 77, 0x6FFAF778);

// @0x140dca470
bool ScreenMaskingEffect::vfunc_6(bool b)
{
    if (!b)
    {
        CString strPath;
        strPath.Format("%s/Image/ScreenMask/%s", (const char*)FUN_14086d260()->GetDataPath(), (const char*)m_strTexture);
        FUN_1416ba640(FUN_140a0afd0()->FUN_141552f90(strPath, 5));
        vfunc_7(m_nState, m_fAlpha);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140dca470, ScreenMaskingEffect, vfunc_6, 344, 0x9D5EB7B0);

// @0x140dca5d0
void ScreenMaskingEffect::vfunc_7(int nState, float fAlpha)
{
    float fT = fAlpha;
    switch (nState)
    {
    case 1:
        fT = 1.0f - fAlpha;
        break;
    }
    float fBlend = (m_fBlendMax - m_fBlendMin) * fT + m_fBlendMin;
    FUN_1409a5770(DAT_143ae5340, &fBlend, 1);
}
MS2_REPLACE_METHOD(0x140dca5d0, ScreenMaskingEffect, vfunc_7, 138, 0x4D971D0B);

// @0x140dca740
int ScreenMaskingEffect::vfunc_5()
{
    return 0x12;
}
