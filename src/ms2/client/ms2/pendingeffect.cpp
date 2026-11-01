// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See pendingeffect.h.
// MS2-UNIT: ?\pendingeffect.cpp
// MS2-RANGE: 0x140a8f1d0-0x140a91030 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pendingeffect.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "pendingeffect.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Check (0x140268870)
#include "ms2/client/ms2/effectservice.h"   // C3: CEffectData, the real effect set

// Effect factory (effectservice): create the runtime effect of a param for a target.
CEffectPtr FUN_14119eae0(CEffectParam* pParam, Unk_EffectTarget* pTarget);

// @0x140a8f1d0
PendingEffect::PendingEffect(int nId)
    : m_nId(nId)
{
}

// @0x140a8f290
PendingEffect::~PendingEffect()
{
}

// @0x140a8f300
bool PendingEffect::Init(MS2Ptr<Unk_PeEffectSet> spSet, const Unk_PeTarget& kTarget)
{
    m_spSet = spSet;
    m_target = kTarget;
    if (kTarget.m_pXformA)
    {
        m_xformA = *kTarget.m_pXformA;
        m_target.m_pXformA = &m_xformA;
    }
    if (kTarget.m_pXformB)
    {
        m_xformB = *kTarget.m_pXformB;
        m_target.m_pXformB = &m_xformB;
    }
    if (kTarget.m_pPoints)
    {
        m_points.Copy(*kTarget.m_pPoints);
        m_target.m_pPoints = &m_points;
    }
    reinterpret_cast<CEffectData*>(m_spSet.operator->())->FUN_14119f710();
    return true;
}
MS2_REPLACE_METHOD(0x140A8F300, PendingEffect, Init, 302, 0x19DB2124);

// @0x140a8f440
bool PendingEffect::Poll()
{
    if (m_tick.Check(50) && reinterpret_cast<CEffectData*>(m_spSet.operator->())->FUN_14119f680())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140A8F440, PendingEffect, Poll, 80, 0x381B39C2);

// @0x140a8f4a0
void PendingEffect::CreateEffects(std::vector<CEffectPtr>& vOut)
{
    for (POSITION pos = reinterpret_cast<CEffectData*>(m_spSet.operator->())->FUN_14119f540().GetHeadPosition(); pos != 0; reinterpret_cast<CEffectData*>(m_spSet.operator->())->FUN_14119f540().GetNext(pos))
    {
        CEffectParam* pParam = reinterpret_cast<CEffectData*>(m_spSet.operator->())->FUN_14119f540().GetAt(pos).get();
        CEffectPtr spEffect = FUN_14119eae0(pParam, reinterpret_cast<Unk_EffectTarget*>(&m_target));
        if (spEffect)
            vOut.push_back(spEffect);
    }
}
MS2_REPLACE_METHOD(0x140A8F4A0, PendingEffect, CreateEffects, 239, 0xA8B9A6F7);

// @0x140a8f5a0
int PendingEffect::GetId() const
{
    return m_nId;
}
MS2_REPLACE_METHOD(0x140A8F5A0, PendingEffect, GetId, 14, 0x72E52537);

// @0x140a8f5c0
Unk_PeTarget& PendingEffect::GetTarget()
{
    return m_target;
}
MS2_REPLACE_METHOD(0x140A8F5C0, PendingEffect, GetTarget, 15, 0x3758D2A9);
