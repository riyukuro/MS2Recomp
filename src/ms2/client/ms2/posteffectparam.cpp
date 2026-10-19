// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\posteffectparam.cpp
// MS2-RANGE: 0x140dbcbc0-0x140dbddc0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\posteffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "posteffectparam.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp).
void FUN_1408730a0(void* pNode, const char* pszName, bool& bOut);
void FUN_140873360(void* pNode, const char* pszName, float& fOut);
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);

// Game clock (commonfiles singleton 0x14086d260, mainsystem.cpp 0x141473280: current time in seconds).
class Unk_GameClock
{
public:
    double FUN_141473280();
};
Unk_GameClock* FUN_14086d260();

bool FUN_14028d470(float a, float b);                   // nearly equal
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_141b6fe40(float t, int nInterpolator);        // 1 linear, 2 log, 3 exp

// Post-process effect manager (?\applyeffect.cpp, singleton 0x1409a8b00).
class Unk_PostEffectMgr
{
public:
    void FUN_1409a3ee0(int nType, int nId);
    void FUN_1409a3f80(int nType, int nId);
    bool FUN_1409a4020(int nId, CScreenEffectBase* pEffect);
};
Unk_PostEffectMgr* FUN_1409a8b00();

// The concrete screen effects (own units; only the constructors are used here).
#include "monochromeeffectparam.h"
#include "radialblureffectparam.h"
#include "screenmaskingeffectparam.h"
#include "gaussianblureffectparam.h"
#include "postprocessing/postshimmerrenderstep.h"

extern int DAT_143ac47c8;   // CPostEffect id counter

// ---------------------------------------------------------------------------------------------------------------
// CPostEffectParam

// @0x140dbcbc0
CPostEffectParam::CPostEffectParam(int nType)
    : CEffectParam(nType)
{
    m_bUseFade = 0;
    m_fFadeStartDuration = 0;
    m_fFadeEndDuration = 0;
    m_nFadeStartInterpolator = 1;
    m_nFadeEndInterpolator = 1;
}

// @0x140dbcc40
void CPostEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408730a0(pNode, "useFade", m_bUseFade);
    FUN_140873360(pNode, "fadeStartDuration", m_fFadeStartDuration);
    FUN_140873360(pNode, "fadeEndDuration", m_fFadeEndDuration);
    FUN_140873360(pNode, "holdDuration", m_fHoldDuration);
    if (const char* pszStart = FUN_14086f4b0(pNode, "fadeStartInterpolator"))
    {
        CString str(pszStart);
        str.MakeLower();
        if (str == "linear")
            m_nFadeStartInterpolator = 1;
        else if (str == "log")
            m_nFadeStartInterpolator = 2;
        else if (str == "exp")
            m_nFadeStartInterpolator = 3;
    }
    if (const char* pszEnd = FUN_14086f4b0(pNode, "fadeEndInterpolator"))
    {
        CString str(pszEnd);
        str.MakeLower();
        if (str == "linear")
            m_nFadeEndInterpolator = 1;
        else if (str == "log")
            m_nFadeEndInterpolator = 2;
        else if (str == "exp")
            m_nFadeEndInterpolator = 3;
    }
}
MS2_REPLACE_METHOD(0x140dbcc40, CPostEffectParam, vfunc_1, 529, 0xA368D026);

#ifndef MS2_HOOK_DLL
// @0x140dbce60
// Not hooked: constructs CPostEffect with this unit's (DLL) constructor/vftable.
CEffectPtr CPostEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CPostEffect;
}
#endif

// @0x140dbcf00
bool CPostEffectParam::vfunc_7(Unk_EffectTarget* p)
{
    if (CEffectParam::vfunc_7(p))
        return true;
    if (p->m_nKind == 3)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140dbcf00, CPostEffectParam, vfunc_7, 62, 0x0E527B0A);

// ---------------------------------------------------------------------------------------------------------------
// CPostEffect

// @0x140dbcf50
CPostEffect::CPostEffect()
{
    m_nId = NextId();
}

// @0x140dbcfa0
CPostEffect::~CPostEffect()
{
}

// @0x140dbcfd0
bool CPostEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CPostEffectParam* pPost = static_cast<const CPostEffectParam*>(pParam);
    m_nType = pPost->m_nType;
    if (pPost->m_bUseFade)
        m_fDuration = pPost->m_fFadeStartDuration + pPost->m_fFadeEndDuration + pPost->m_fHoldDuration;
    switch (pParam->m_nType)
    {
    case 4:
    {
        const CPostEffectParam* pMono = static_cast<const CPostEffectParam*>(pParam);
        MonochromeEffect* pEffect = new MonochromeEffect(m_nId, pMono);
        if (!FUN_1409a8b00()->FUN_1409a4020(m_nId, pEffect))
            return false;
        break;
    }
    case 5:
    {
        const CPostEffectParam* pRadial = static_cast<const CPostEffectParam*>(pParam);
        RadialBlurEffect* pEffect = new RadialBlurEffect(m_nId, pRadial);
        if (!FUN_1409a8b00()->FUN_1409a4020(m_nId, pEffect))
            return false;
        break;
    }
    case 0x12:
    {
        const CPostEffectParam* pMask = static_cast<const CPostEffectParam*>(pParam);
        ScreenMaskingEffect* pEffect = new ScreenMaskingEffect(m_nId, pMask);
        if (!FUN_1409a8b00()->FUN_1409a4020(m_nId, pEffect))
            return false;
        break;
    }
    case 0x13:
    {
        const CPostEffectParam* pBlur = static_cast<const CPostEffectParam*>(pParam);
        GaussianBlurEffect* pEffect = new GaussianBlurEffect(m_nId, pBlur);
        if (!FUN_1409a8b00()->FUN_1409a4020(m_nId, pEffect))
            return false;
        break;
    }
    case 0x14:
    {
        const CPostEffectParam* pShimmer = static_cast<const CPostEffectParam*>(pParam);
        PostShimmerEffect* pEffect = new PostShimmerEffect(m_nId, pShimmer);
        if (!FUN_1409a8b00()->FUN_1409a4020(m_nId, pEffect))
            return false;
        break;
    }
    default:
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140dbcfd0, CPostEffect, vfunc_3, 1064, 0xD45CB6D4);

// @0x140dbd400
void CPostEffect::vfunc_4()
{
    CEffect::vfunc_4();
    FUN_1409a8b00()->FUN_1409a3ee0(m_nType, m_nId);
}
MS2_REPLACE_METHOD(0x140dbd400, CPostEffect, vfunc_4, 54, 0x9A0ECA22);

// @0x140dbd440
void CPostEffect::vfunc_5()
{
    CEffect::vfunc_5();
    FUN_1409a8b00()->FUN_1409a3f80(m_nType, m_nId);
}
MS2_REPLACE_METHOD(0x140dbd440, CPostEffect, vfunc_5, 54, 0x59BBACAF);

// @0x140dbd480
void CPostEffect::vfunc_7()
{
}

// @0x140dbd490
int CPostEffect::NextId()
{
    if (++DAT_143ac47c8 == 0)
        DAT_143ac47c8 = 1;
    return DAT_143ac47c8;
}

// @0x140dbdc80
int CPostEffect::vfunc_12()
{
    return m_nType;
}

// ---------------------------------------------------------------------------------------------------------------
// CScreenEffectBase

// @0x140dbd4c0
CScreenEffectBase::CScreenEffectBase(int nType, const CPostEffectParam* pParam)
{
    m_nType = nType;
    m_bEnding = 0;
    m_bStarted = 0;
    m_dStartTime = 0;
    m_nState = 0;
    m_fAlpha = 0;
    m_nFadeStartInterp = 1;
    m_nFadeEndInterp = 1;
    if (pParam)
    {
        m_fDuration = pParam->m_fDuration;
        m_fFadeStart = pParam->m_fFadeStartDuration;
        m_fFadeEnd = pParam->m_fFadeEndDuration;
        m_fHold = pParam->m_fHoldDuration;
        m_bLoop = pParam->m_b30;
        m_bUseFade = pParam->m_bUseFade;
        m_nFadeStartInterp = pParam->m_nFadeStartInterpolator;
        m_nFadeEndInterp = pParam->m_nFadeEndInterpolator;
        if (!m_bLoop && !m_bUseFade)
            m_bEnding = 1;
        if (m_bUseFade)
            m_fDuration = m_fFadeStart + m_fFadeEnd + m_fHold;
    }
}

// @0x140dbd650
CScreenEffectBase::~CScreenEffectBase()
{
}

// @0x140dbd680
void CScreenEffectBase::vfunc_1()
{
    m_dStartTime = FUN_14086d260()->FUN_141473280();
    m_bStopped = 0;
    m_bStarted = 1;
    if (m_bUseFade && !FUN_14028d470(m_fFadeStart, 0))
        m_nState = 3;
    SetState(m_nState, 0);
}
MS2_REPLACE_METHOD(0x140dbd680, CScreenEffectBase, vfunc_1, 126, 0x3130B15C);

// @0x140dbd710
bool CScreenEffectBase::vfunc_2()
{
    if (!m_bStarted)
        return true;
    if (!m_bStopped)
    {
        float fElapsed = (float)(FUN_14086d260()->FUN_141473280() - m_dStartTime);
        bool bHold = false;
        if (fElapsed >= m_fDuration)
        {
            if (m_bEnding)
            {
                vfunc_4();
                return false;
            }
            else if (FUN_14028d470(m_fDuration, 0))
                bHold = true;
            else if (!m_bLoop)
                m_bEnding = 1;
        }
        if (!bHold)
        {
            if (m_bUseFade)
            {
                if (fElapsed < m_fFadeStart)
                {
                    float fIn = fElapsed / m_fFadeStart;
                    fIn = FUN_141b6fe40(fIn, m_nFadeStartInterp);
                    SetState(3, fIn);
                }
                else if (fElapsed < m_fFadeStart + m_fHold)
                    SetState(2, 1.0f);
                else if (fElapsed <= m_fFadeStart + m_fHold + m_fFadeEnd)
                {
                    if (m_bLoop)
                        SetState(2, 1.0f);
                    else
                    {
                        float fOut = (fElapsed - (m_fFadeStart + m_fHold)) / m_fFadeEnd;
                        fOut = FUN_141b6fe40(fOut, m_nFadeEndInterp);
                        SetState(1, fOut);
                    }
                }
                else if (m_bLoop)
                    SetState(2, 1.0f);
                else
                    SetState(1, 1.0f);
            }
            else
                SetState(0, 1.0f);
        }
        else
            SetState(m_nState, 1.0f);
    }
    else
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140dbd710, CScreenEffectBase, vfunc_2, 674, 0x167044F7);

// @0x140dbd9c0
void CScreenEffectBase::vfunc_3()
{
    if (m_bStarted)
    {
        if (m_bUseFade)
        {
            m_fFadeStart = 0;
            m_fHold = 0;
            m_fDuration = m_fFadeEnd;
            m_dStartTime = FUN_14086d260()->FUN_141473280();
            m_bLoop = 0;
            m_bEnding = 1;
            return;
        }
        else
        {
            m_bEnding = 1;
            if (!m_bLoop)
                return;
        }
    }
    vfunc_4();
}
MS2_REPLACE_METHOD(0x140dbd9c0, CScreenEffectBase, vfunc_3, 173, 0x704B4F92);

// @0x140dbda80
void CScreenEffectBase::vfunc_4()
{
    SetState(0, 0);
    m_bStopped = 1;
}
MS2_REPLACE_METHOD(0x140dbda80, CScreenEffectBase, vfunc_4, 38, 0x3D6889DC);

// @0x140dbdab0
bool CScreenEffectBase::vfunc_6(bool b)
{
    if (!b)
        vfunc_7(m_nState, m_fAlpha);
    return true;
}
MS2_REPLACE_METHOD(0x140dbdab0, CScreenEffectBase, vfunc_6, 63, 0xF0453B88);

// @0x140dbdb00
void CScreenEffectBase::SetState(int nState, float fAlpha)
{
    fAlpha = FUN_140a17940(fAlpha, 0, 1.0f);
    if (nState != m_nState || !FUN_14028d470(m_fAlpha, fAlpha))
    {
        vfunc_7(nState, fAlpha);
        m_nState = nState;
        m_fAlpha = fAlpha;
    }
}
MS2_REPLACE_METHOD(0x140dbdb00, CScreenEffectBase, SetState, 148, 0x4378EFFD);

// @0x140dbdca0 (the UCRT header-inline memmove_s from corecrt_memcpy_s.h, emitted here as an ordinary function)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
errno_t FUN_140dbdca0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}
