// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\transitioneffectparam.cpp
// MS2-RANGE: 0x14185f1d0-0x14185ff70 .text$mn
// MS2-PIN: ??_GTransitionEffect@@UEAAPEAXI@Z 0x14185fb90
// MS2-PIN: ??_GTransitionEffectParam@@UEAAPEAXI@Z 0x14185fbf0
// MS2-PIN: ?GetRTTI@TransitionEffect@@UEBAPEBVNiRTTI@@XZ 0x14185fdd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\transitioneffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "transitioneffectparam.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

bool FUN_14028d470(float a, float b);                   // nearly equal
float FUN_1409f25a0(float f);                           // sine

// Game clock (commonfiles singleton 0x14086d260): current time in seconds.
class Unk_GameClock
{
public:
    double FUN_141473280();
};
Unk_GameClock* FUN_14086d260();

// Interpolation functors (empty; t in [0, 1]). 0 and 3 were emitted here, 1 and 2 elsewhere.
struct Unk_InterpLinear
{
    // @0x14185fb50
    float FUN_14185fb50(float t)
    {
        if (t < 0.0f)
            return 0.0f;
        if (t > 1.0f)
            return 1.0f;
        return t;
    }
};
struct Unk_InterpEase1
{
    float FUN_140cd8c20(float t);
};
struct Unk_InterpEase2
{
    float FUN_1410af700(float t);
};
struct Unk_InterpSine
{
    // @0x14185fae0
    float FUN_14185fae0(float t)
    {
        if (t < 0.0f)
            return 0.0f;
        if (t > 1.0f)
            return 1.0f;
        return FUN_1409f25a0((t - 0.5f) * 3.1415927f) * 0.5f + 0.5f;
    }
};

// @0x14185f1d0
TransitionEffectParam::TransitionEffectParam(int nType)
    : CEffectParam(nType)
{
    m_nLoopIndex = -1;
}

// @0x14185f230
TransitionEffectParam& TransitionEffectParam::operator=(const TransitionEffectParam& o)
{
    if (this == &o)
        return *this;
    m_nLoopIndex = o.m_nLoopIndex;
    m_arrData.Copy(o.m_arrData);
    return *this;
}

// @0x14185f290
TransitionEffect::TransitionEffect()
    : m_nLoopIndex(-1)
{
}

// @0x14185f2e0
TransitionEffect::~TransitionEffect()
{
    vfunc_7();
}

// @0x14185f340
void TransitionEffect::FUN_14185f340(const TransitionEffectParam* pParam)
{
    m_nLoopIndex = pParam->m_nLoopIndex;
    m_arrData.Copy(pParam->m_arrData);
}
MS2_REPLACE_METHOD(0x14185f340, TransitionEffect, FUN_14185f340, 61, 0xB160F342);

// @0x14185f390
bool TransitionEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const TransitionEffectParam* pTransition = static_cast<const TransitionEffectParam*>(pParam);
    m_nLoopIndex = pTransition->m_nLoopIndex;
    m_arrData.Copy(pTransition->m_arrData);
    return true;
}
MS2_REPLACE_METHOD(0x14185f390, TransitionEffect, vfunc_3, 109, 0x39A5897B);

// @0x14185f410
bool TransitionEffect::vfunc_9()
{
    if (!CEffect::vfunc_9())
        return false;
    double dNow = FUN_14086d260()->FUN_141473280();
    unsigned int nIndex = 0;
    float fT = 0.0f;
    if (FUN_14185f6f0(dNow, &nIndex, &fT))
    {
        if (nIndex >= m_arrData.GetCount())
            nIndex = (unsigned int)(m_arrData.GetCount() - 1);
        TransitionData* pFrom = m_arrData[nIndex];
        TransitionData* pTo = nIndex != m_arrData.GetCount() - 1 ? m_arrData[nIndex + 1]
            : (m_nLoopIndex != -1 ? m_arrData[m_nLoopIndex] : m_arrData[nIndex]);
        switch (pFrom->m_nInterpolation)
        {
        case 0:
            fT = Unk_InterpLinear().FUN_14185fb50(fT);
            break;
        case 1:
            fT = Unk_InterpEase1().FUN_140cd8c20(fT);
            break;
        case 2:
            fT = Unk_InterpEase2().FUN_1410af700(fT);
            break;
        case 3:
            fT = Unk_InterpSine().FUN_14185fae0(fT);
            break;
        }
        vfunc_13(pFrom, pTo, fT);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14185f410, TransitionEffect, vfunc_9, 597, 0x036D8903);

// @0x14185f670
void TransitionEffect::FUN_14185f670(TransitionData* pData)
{
    m_arrData.Add(pData);
}
MS2_REPLACE_METHOD(0x14185f670, TransitionEffect, FUN_14185f670, 77, 0x11902412);

// @0x14185f6f0
bool TransitionEffect::FUN_14185f6f0(double dNow, unsigned int* pnIndex, float* pfT)
{
    if (!m_arrData.GetCount())
        return false;
    float fElapsed = (float)(dNow - m_dStartTime);
    int nCount = (int)m_arrData.GetCount();
    int i = 0;
    float fEnd = 0.0f;
    float fLoopStart = 0.0f;
    for (i = 0; i < nCount; i++)
    {
        TransitionDataPtr& spData = m_arrData[i];
        float fStart = spData->m_fStartTime;
        float fDuration = spData->m_fDuration;
        if (i == m_nLoopIndex)
            fLoopStart = fStart;
        fEnd = fStart + fDuration;
        if (fEnd > fElapsed)
        {
            *pfT = FUN_14028d470(fDuration, 0.0f) ? 1.0f : (fElapsed - fStart) / fDuration;
            break;
        }
    }
    if (i == nCount && m_nLoopIndex != -1)
    {
        float fLoopLength = fEnd - fLoopStart;
        if (fLoopLength <= 0.0f)
        {
            *pnIndex = nCount;
            *pfT = 1.0f;
            return true;
        }
        fElapsed -= fLoopStart;
        if (!FUN_14028d470(fLoopLength, 0.0f))
        {
            while (fElapsed > fLoopLength)
                fElapsed -= fLoopLength;
        }
        for (i = m_nLoopIndex; i < nCount; i++)
        {
            TransitionDataPtr& spData = m_arrData[i];
            float fStart = spData->m_fStartTime;
            float fDuration = spData->m_fDuration;
            fEnd = fStart + fDuration;
            if (fEnd > fElapsed)
            {
                *pfT = FUN_14028d470(fDuration, 0.0f) ? 1.0f : (fElapsed - fStart) / fDuration;
                break;
            }
        }
    }
    *pnIndex = i;
    return true;
}
MS2_REPLACE_METHOD(0x14185f6f0, TransitionEffect, FUN_14185f6f0, 793, 0xE0359D10);

// Keyframe XML reader shared by the light and chaos-light effect params (sits just before this TU's range start).
// MS2-RANGE: 0x14185f0b0-0x14185f1d0 .text$mn
class Unk_140165cf0;                                                    // game TinyXML element
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);   // attribute text (null = absent)
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
CString FUN_140188f50(const char* psz, int nCodePage);                  // CString from a C string

// @0x14185f0b0
void FUN_14185f0b0(TransitionData* pData, Unk_140165cf0* pNode, float* pfTime)
{
    pData->m_nInterpolation = 0;
    CString strType = FUN_140188f50(FUN_14086f4b0(pNode, "type"), 0);
    if (strType.CompareNoCase("FastInEaseOut") == 0)
        pData->m_nInterpolation = 1;
    else if (strType.CompareNoCase("EaseInFastOut") == 0)
        pData->m_nInterpolation = 2;
    else if (strType.CompareNoCase("EaseInEaseOut") == 0)
        pData->m_nInterpolation = 3;
    FUN_140873360(pNode, "duration", pData->m_fDuration);
    pData->m_fStartTime = *pfTime;
    *pfTime += pData->m_fDuration;
}
MS2_REPLACE(0x14185F0B0, FUN_14185f0b0, 272, 0x9103B1FB);
