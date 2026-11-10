// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See stateskillmagiccontrol.h.
// MS2-UNIT: unit_140ac02e0
// MS2-RANGE: 0x140ac02e0-0x140ac08e0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateskillmagiccontrol.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "stateskillmagiccontrol.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/cubecraft_1.h"

// ---- unit-local placeholders ----

float GetPlanarDistance(Vector3 a, Vector3 b);   // C3: actionkeyobject.cpp's definition (0x140966ea0)
class Unk_PCMove { public: Vector3 FUN_141683900(); };   // C3: view of the real class (unit_141682f80)

// PCBase seen with Vector3 points (as in statefloat.cpp): slots 19, 22 and 68 take the point by value, and the
// local -> world dir transform takes / returns it by value too.
class Unk_FloatOwner
{
public:
#define MS2_SF_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_SF_SLOTS(0, 1, 2, 3, 4) MS2_SF_SLOTS(5, 6, 7, 8, 9) MS2_SF_SLOTS(10, 11, 12, 13, 14)
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Vector3 vfunc_18();                                            // 18 0x14166bbe0
    virtual void vfunc_19(Vector3 kPos);                                   // 19 0x14166bb10
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(Vector3 kPos);                                   // 22 0x14123c3a0
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_SF_SLOTS(25, 26, 27, 28, 29) MS2_SF_SLOTS(30, 31, 32, 33, 34) MS2_SF_SLOTS(35, 36, 37, 38, 39)
    MS2_SF_SLOTS(40, 41, 42, 43, 44) MS2_SF_SLOTS(45, 46, 47, 48, 49) MS2_SF_SLOTS(50, 51, 52, 53, 54)
    MS2_SF_SLOTS(55, 56, 57, 58, 59) MS2_SF_SLOTS(60, 61, 62, 63, 64)
#undef MS2_SF_SLOTS
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
    virtual bool vfunc_68(Vector3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
    // 0x141674b60 local dir -> world dir: C3: PCBase::CalcMoveDirectionNoYaw (pcbase.h)
};

// @0x140ac06f0
// The controlled target: asks the owner for the component 0x6200081 (CSkillMagicControlGuide).
CSkillMagicControlGuide* FUN_140ac06f0(PCBase* p)
{
    CSkillMagicControlGuide* r = 0;
    if (p && p->TypeCast(0x6200081, (void**)&r))
        return r;
    else
        return 0;
}

// @0x140ac02e0
StateSkillMagicControl::StateSkillMagicControl(PCBase* pOwner) : State(pOwner)
{
}

// @0x140ac0320
StateSkillMagicControl::~StateSkillMagicControl()
{
}

// @0x140ac0780
int StateSkillMagicControl::vfunc_15()
{
    return 1;
}

// @0x140ac0790
int StateSkillMagicControl::vfunc_1()
{
    return 0x41;
}

// @0x140ac0350
void StateSkillMagicControl::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
}

// @0x140ac0380
void StateSkillMagicControl::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (!m_pOwner->vfunc_63())
        return;
    CSkillMagicControlGuide* pTarget = FUN_140ac06f0(m_pOwner);
    if (!pTarget)
        return;
    efd::Point3 kWorld = m_pOwner->CalcMoveDirectionNoYaw(m_pOwner->FUN_14123c360());
    reinterpret_cast<Vector3&>(kWorld).Unitize();
    efd::Point3 kSpeed = kWorld * (pTarget->GetMoveSpeed());
    efd::Point3 kStep = reinterpret_cast<const efd::Point3&>(kSpeed) * ((float)fTime);
    Vector3 kOld = reinterpret_cast<Unk_FloatOwner*>(m_pOwner)->vfunc_18();
    reinterpret_cast<Unk_FloatOwner*>(m_pOwner)->vfunc_68(reinterpret_cast<Vector3&>(kStep), fTime, 0, 0, 1);
    float fDist = GetPlanarDistance(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(pTarget->GetOriginPosition())), reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pTarget->vfunc_18())));
    if (fDist >= pTarget->GetMaxDistance() || pTarget->GetOriginPosition().z != pTarget->vfunc_18().z)
        reinterpret_cast<Unk_FloatOwner*>(m_pOwner)->vfunc_19(kOld);
}

// @0x140ac0640
void StateSkillMagicControl::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (!m_pOwner->vfunc_63())
        return;
    void* pBuffs = m_pOwner->FUN_14166d240();
    Vector3 kPos = reinterpret_cast<Unk_PCMove*>(pBuffs)->FUN_141683900();
    reinterpret_cast<Unk_FloatOwner*>(m_pOwner)->vfunc_22(kPos);
}

// @0x140ac07c0
MS2_EMIT_CRT_MEMMOVE_S();
