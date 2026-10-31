// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scalemodifier.cpp
// MS2-RANGE: 0x14170b530-0x14170b850 .text$mn
// One of the six objs inside the units.tsv range of client\ms2\scenestategame.cpp (see scenestatebase.cpp); CU name
// assumed.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scalemodifier.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scalemodifier.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"

   // current game time (seconds)
CMainSystem* FUN_14086d260();

// Ease-out curve on [0,1] (0x140cd8c20); empty functor, called on a temporary.
struct Unk_EaseOut { float FUN_140cd8c20(float t); };

// @0x14170b530
CScaleModifier::CScaleModifier()
    : m_fBaseScale(1.0f), m_fScale(1.0f), m_fDuration(0.0f), m_fMaxScale(1.0f), m_dStartTime(0.0), m_bActive(false)
{
    m_fMaxScale = 1.2f;
    m_fDuration = 0.5f;
}

// @0x14170b5e0
CScaleModifier::~CScaleModifier()
{
}

// @0x14170b610
bool CScaleModifier::Update()
{
    double dNow = FUN_14086d260()->FUN_141473280();
    if (dNow > m_dStartTime + m_fDuration || dNow < m_dStartTime)
    {
        if (m_bActive)
        {
            m_bActive = false;
            m_fScale = m_fBaseScale;
            return true;
        }
        else
            return false;
    }
    float fElapsed = (float)(dNow - m_dStartTime);
    float fHalf = m_fDuration * 0.5f;
    float fRatio = 0.0f;
    if (fElapsed < fHalf)
        fRatio = Unk_EaseOut().FUN_140cd8c20(fElapsed / fHalf);
    else
        fRatio = 1.0f - Unk_EaseOut().FUN_140cd8c20((fElapsed - fHalf) / fHalf);
    m_fScale = m_fBaseScale * (1.0f + fRatio * (m_fMaxScale - 1.0f));
    return true;
}
MS2_REPLACE_METHOD(0x14170b610, CScaleModifier, Update, 378, 0x2188D5BC);

// @0x14170b7a0
void CScaleModifier::Start(float fBaseScale)
{
    m_dStartTime = FUN_14086d260()->FUN_141473280();
    m_fBaseScale = fBaseScale;
    m_bActive = true;
}
MS2_REPLACE_METHOD(0x14170b7a0, CScaleModifier, Start, 68, 0xC0316A06);
