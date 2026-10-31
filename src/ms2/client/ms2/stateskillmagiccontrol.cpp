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

// The controlled target (a GameObject-derived actor; FUN_140ac06f0 asks the owner for the component 0x6200081).
class Unk_ControlTarget : public CSkillMagicControlGuide
{
public:
    NiPoint3 FUN_1410a6750();                    // destination
};

NiPoint3* FUN_14123c360(PCBase* p, NiPoint3* pOut);                 // move direction (member: this=rcx, hidden return=rdx)
NiPoint3* FUN_141674b60(PCBase* p, NiPoint3* pOut, NiPoint3* pDir); // local dir -> world dir (by-value dir = pointer to a copy)
void FUN_140968990(NiPoint3* p);                                    // normalize
NiPoint3* FUN_14097fc90(const NiPoint3* pIn, NiPoint3* pOut, float f);   // scale (member: this=rcx, hidden return=rdx)
float FUN_140966ea0(NiPoint3 a, NiPoint3 b);                        // horizontal distance
void* FUN_14166d240(PCBase* p);                                     // buff container
NiPoint3* FUN_141683900(void* pContainer, NiPoint3* pOut);          // move direction (member: this=rcx, hidden return=rdx)

// @0x140ac06f0
Unk_ControlTarget* FUN_140ac06f0(PCBase* p)
{
    Unk_ControlTarget* r = 0;
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
// MS2-FUNCTIONAL: PCBase::vfunc_68 takes the move by value in the exe (shared header declares void*), and the
// vtable-in-local call shape of the final vfunc_18().z compare is not reproduced.
void StateSkillMagicControl::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (!m_pOwner->vfunc_63())
        return;
    Unk_ControlTarget* pTarget = FUN_140ac06f0(m_pOwner);
    if (!pTarget)
        return;
    NiPoint3 kDir, kUnit;
    FUN_141674b60(m_pOwner, &kUnit, FUN_14123c360(m_pOwner, &kDir));
    FUN_140968990(&kUnit);
    NiPoint3 kStep, kMove;
    FUN_14097fc90(&kUnit, &kStep, pTarget->FUN_1410a6790());
    FUN_14097fc90(&kStep, &kMove, (float)fTime);
    NiPoint3 kOld = m_pOwner->vfunc_18();
    NiPoint3 kNew = kMove;
    m_pOwner->vfunc_68(&kNew, fTime, 0, 0, 1);
    float fDist = FUN_140966ea0(pTarget->FUN_1410a6750(), pTarget->vfunc_18());
    if (fDist < pTarget->FUN_1410a67d0())
    {
        const NiPoint3& rDest = pTarget->FUN_1410a6750();
        if (pTarget->vfunc_18().z == rDest.z)
            return;
    }
    m_pOwner->vfunc_19(kOld);
}

// @0x140ac0640
// MS2-FUNCTIONAL: slot 22 of GameObject takes the point by value in the exe (second 12-byte copy), but the shared
// header declares it void*; the temporary/copy pair cannot be expressed without editing gameobject.h.
void StateSkillMagicControl::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (!m_pOwner->vfunc_63())
        return;
    void* pBuffs = FUN_14166d240(m_pOwner);
    NiPoint3 kPos;
    FUN_141683900(pBuffs, &kPos);
    m_pOwner->vfunc_22(kPos);
}

// @0x140ac07c0
MS2_EMIT_CRT_MEMMOVE_S();
