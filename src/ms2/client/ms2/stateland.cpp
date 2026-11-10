// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateLand, the actor state of a player landing after a
// fall or jump: snaps the standing-on entity with a ray cast, plays the landing animation, leaves for idle. See
// stateland.h.
// MS2-UNIT: ?\stateland.cpp
// MS2-RANGE: 0x1417d9c70-0x1417da7a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateland.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>
#include <NiActorManager.h>

#include "stateland.h"

#include "ms2/client/ms2/statefall.h"               // the animation service view (Unk_FallAnimSvc)
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/client/ms2/groundeffectdata.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/gameobjectcontrollerhitreport.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_AvPhysicsSvc* GetPhysXHelper();   // C3: was GetPhysXHelper

class GameObjectControllerHitReport;
class GameObjectController { public: GameObjectControllerHitReport* GetHitReport(); };   // C3: unit-local view

// The actor's buff set.
#include "ms2/placeholder/nipoint3.h"   // C3: Vector3, the return type of Unk_PCMove::GetMoveDirection
#include <egmAnimation/AnimationService.h>
class Unk_PCMove { public: Vector3 GetMoveDirection(); bool IsActionKeyDown(int nKey); };   // C3: view of the real class (unit_141682f80)
// The owner seen through its vftable where gameobject.h declares slot 22 by reference: the exe passes the point by
// value (the caller copies it into an argument temp).
class Unk_LandOwnerSlots
{
public:
#define MS2_LAND_SLOTS(a, b, c, d, e, f, g, h, i, j, k) virtual void vfunc_##a(); virtual void vfunc_##b(); \
    virtual void vfunc_##c(); virtual void vfunc_##d(); virtual void vfunc_##e(); virtual void vfunc_##f(); \
    virtual void vfunc_##g(); virtual void vfunc_##h(); virtual void vfunc_##i(); virtual void vfunc_##j(); \
    virtual void vfunc_##k();
    MS2_LAND_SLOTS(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) MS2_LAND_SLOTS(11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)
#undef MS2_LAND_SLOTS
    virtual void vfunc_22(efd::Point3 kDir);                                // 22 0x14123c3a0
};
// The land sound service.

// Cube craft selection of the owner (gates the "cube landing" animation).
class Unk_LandCube : public Unk_PCCubeCraft { };

CString FUN_1409a2360(const char* psz, int n);                              // text conversion

// @0x1417d9c70
StateLand::StateLand(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417d9ce0
StateLand::~StateLand()
{
}

// @0x1417d9d20
void StateLand::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spLand.AssignRaw(dynamic_cast<StateLandData*>(pData));
    if (m_pOwner->FUN_141676b70() != 0)
        m_n10 = 0x87;
    else
        m_n10 = 0x86;
    PCBase* pPC = FUN_1417b8370();
    Unk_RayCastInfo kRay;
    efd::Point3 kFrom = m_pOwner->vfunc_18() + efd::Point3(0.0f, 0.0f, 30.0f);
    efd::Point3 kHit = efd::Point3::ZERO;
    efd::Point3 kNormal = efd::Point3::ZERO;
    int nHit = reinterpret_cast<CPhysXHelper*>(GetPhysXHelper())->RayCastFixedDirection(reinterpret_cast<const Vector3&>(kFrom), reinterpret_cast<Vector3&>(kHit), &kRay, 50.0f, reinterpret_cast<Vector3*>(&kNormal), 0);
    if (nHit != 0 && pPC != 0 && kRay.m_hitEntity != 0)
    {
        if (reinterpret_cast<egf::Entity*>(kRay.m_hitEntity)->GetEntityID() != ((GameObjectController*)pPC->GetPhysicsBody())->GetHitReport()->GetEntityID())
            ((GameObjectController*)pPC->GetPhysicsBody())->GetHitReport()->SetEntity(reinterpret_cast<Unk_Entity*>(kRay.m_hitEntity));
    }
    m_pOwner->vfunc_93(true);
    reinterpret_cast<CGroundEffectDataManager*>(TSingleton<CGroundEffectDataManager>::GetInstance())->PlayEffects(m_pOwner, CString("land"));
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC != 0)
        pMyPC->FUN_14152dbc0();
    if (m_pOwner->FUN_141675ed0() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417da070
void StateLand::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    efd::Point3 kMove = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417da0f0
void StateLand::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    Unk_PCMove* pBuff = (Unk_PCMove*)m_pOwner->FUN_14166d240();
    reinterpret_cast<Unk_LandOwnerSlots*>(m_pOwner)->vfunc_22(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pBuff->GetMoveDirection())));
    if (m_pOwner->FUN_1416749c0())
        m_pOwner->vfunc_59(2, 0, 0, 0);
    else if (m_pOwner->FUN_141671a30() != 0 && pBuff->IsActionKeyDown(0x493e1))
        m_pOwner->vfunc_59(6, 0, 0x25, 0);
    else if (m_pOwner->FUN_141675ed0() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
    else
        FUN_1417b9460();
}

// @0x1417da290
void StateLand::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    efd::utf8string strAnim;
    if ((m_spLand.get() ? true : false) && !m_spLand->m_str.IsEmpty())
    {
        strAnim = (const char*)FUN_1409a2360((const char*)m_spLand->m_str, 0);
    }
    else
    {
        if (m_n10 == 0x86)
        {
            PCBase* pPC = FUN_1417b8370();
            if (pPC != 0 && reinterpret_cast<PC*>(pPC)->IsInCubeMode() != 0 && ((Unk_LandCube*)(reinterpret_cast<PC*>(pPC)->GetCubeCraft()))->HasGuide2())
            {
                strAnim = pPC->vfunc_123(0x3c);
            }
            else
            {
                strAnim = m_pOwner->vfunc_123(3);
            }
        }
        else if (m_n10 == 0x87)
        {
            strAnim = m_pOwner->vfunc_123(0x48);
        }
    }
    unsigned int nSeq = NiActorManager::INVALID_SEQUENCE_ID;
    nSeq = reinterpret_cast<egmAnimation::AnimationService*>(FUN_141b6f910())->GetAnimationIdFromName(m_pOwner->GetEntityID(), strAnim);
    if (nSeq == NiActorManager::INVALID_SEQUENCE_ID)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    m_pOwner->PlayAnimation(strAnim, 1.0f, false, false);
}

// @0x1417da580
void StateLand::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    int bDone = 0;
    if ((m_spLand.get() ? true : false) && !m_spLand->m_str.IsEmpty())
    {
        bDone = 1;
    }
    else if (m_pOwner->FUN_14166de90(3, eSequenceID))
    {
        bDone = 1;
    }
    else if (m_pOwner->FUN_14166de90(0x3c, eSequenceID))
    {
        bDone = 1;
    }
    else if (m_pOwner->FUN_14166de90(0x48, eSequenceID))
    {
        bDone = 1;
    }
    if (bDone != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417da780
int StateLand::vfunc_15()
{
    return 1;
}

// @0x1417da790
int StateLand::vfunc_1()
{
    return 4;
}
