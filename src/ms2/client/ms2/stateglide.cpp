// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateGlide, the actor state of a player gliding: falls with
// the glide animation, drifts forward along the skill row's curves and plays a looping effect. See stateglide.h.
// MS2-UNIT: ?\stateglide.cpp
// MS2-RANGE: 0x1417c8900-0x1417ca270 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateglide.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <math.h>
#include <efd/utf8string.h>

#include "stateglide.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/pushcontrol.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/gameobjectcontroller.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/gameobjectcontrollerhitreport.h"
#include "ms2/client/ms2/skilldatatablecli.h"   // C3: SkillDataTable::GetGlideData, SkillGlideData

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

class Unk_PCBaseBody;
     // the actor body (+0x150)
class Unk_PCBaseBodyDummy;
class Unk_GlideHit : public GameObjectControllerHitReport { };

// The owner's vtable up to slot 68, which takes the move by value (the exe passes a pointer to a copy).
class Unk_GlOwnerSlots
{
public:
#define MS2_GL_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_GL_SLOTS(0, 1, 2, 3, 4) MS2_GL_SLOTS(5, 6, 7, 8, 9) MS2_GL_SLOTS(10, 11, 12, 13, 14)
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual efd::Point3 vfunc_18();                                                 // 18 returns the position by value
    virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kDir);                                        // 22 takes the direction by value
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_GL_SLOTS(25, 26, 27, 28, 29) MS2_GL_SLOTS(30, 31, 32, 33, 34)
    MS2_GL_SLOTS(35, 36, 37, 38, 39) MS2_GL_SLOTS(40, 41, 42, 43, 44) MS2_GL_SLOTS(45, 46, 47, 48, 49)
    MS2_GL_SLOTS(50, 51, 52, 53, 54) MS2_GL_SLOTS(55, 56, 57, 58, 59) MS2_GL_SLOTS(60, 61, 62, 63, 64)
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
#undef MS2_GL_SLOTS
    virtual bool vfunc_68(efd::Point3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};
bool IsNearlyEqual(float a, float b);                      // approximately equal
CStringW GetStringCommonByKey(const CStringW& strKey);             // string table text
void ShowSystemNotice(const CStringW& str, int a, int b);     // 0x1412751f0 chat notice


// The world service (0x1403ed2d0): the upper bound of the map.

// The actor's buff set: the airborne check.

// The actor's buff view: the movement direction.
#include "ms2/commonfiles/ugcmappackageinfo.h"   // C3: Unk_Int3
#include "ms2/placeholder/nipoint3.h"   // C3: Vector3, the return type of Unk_PCMove::FUN_141683900
class Unk_PCMove { public: Vector3 FUN_141683900(); };   // C3: view of the real class (unit_141682f80)
class Unk_GlideBuff { public: };

// The actor's player character (+ the buff based speed bonus).

// The cube grid: the cell of a cube key and the centre point of a cell.
Unk_Int3 FUN_1408a0400(int nKey);                                    // C3: the definer's signature (ugcmapdata_1)
efd::Point3 FUN_1408a15b0(Unk_Int3 kCell, efd::Point3& kCentre);     // fills kCentre with the cell centre (the exe copies the cell: by value)

// The PhysX helper (0x1409f7ca0): ground below a point.
class Unk_AvPhysicsSvc* GetPhysXHelper();   // C3: was GetPhysXHelper

// @0x1417c8900
StateGlide::StateGlide(PCBase* pOwner) : StateMoveSkill(pOwner), m_nEffect(0)
{
    m_fTime = 0;
    m_fStartZ = 0;
    m_bHeightErr = false;
    m_bTooHigh = false;
    m_n44 = 0x1e;
    m_nFallbackState = 5;
    m_n10 = 99;
    m_nAnim = 99;
    m_nMode = 1;
}

// @0x1417c89e0
StateGlide::~StateGlide()
{
    if (m_nEffect != 0)
    {
        reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417c8a60
void StateGlide::vfunc_4(StateData* pData)
{
    StateMoveSkill::vfunc_4(pData);
    if (m_spRow == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    m_fTime = 0;
    efd::Point3 kCentre(0.0f, 0.0f, 0.0f);
    FUN_1408a15b0(FUN_1408a0400(m_pOwner->FUN_1416782e0()), kCentre);
    m_fStartZ = kCentre.z;
    m_bHeightErr = false;
    m_bTooHigh = false;
    bool bFromGlide = static_cast<CStateManager*>(m_pOwner->GetStateMgr())->GetPrev() == 0x1e;
    if (bFromGlide)
    {
        m_bTooHigh = FUN_1417ca000() == 0;
        if (m_bTooHigh && m_pOwner->vfunc_108() != 0)
            ShowSystemNotice(GetStringCommonByKey(L"s_err_skill_maximum_Height"), 1, 1);
    }
    ((GameObjectController*)m_pOwner->GetPhysicsBody())->StopJump();
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        efd::Point3 kPos = reinterpret_cast<Unk_GlOwnerSlots*>(pPC)->vfunc_18();
        if (((class CPhysXHelper*)GetPhysXHelper())->CheckCapsuleOverlap(reinterpret_cast<const Vector3*>(&kPos)))
        {
            pPC->vfunc_59(1, 0, 0, 0);
            return;
        }
        reinterpret_cast<PC*>(pPC)->SendRequestCube();
        ((CPushControl*)pPC->GetPushControl())->Reset();
    }
    m_nAnim = 99;
    Unk_EffectQuery query;
    query.m_strName = m_spRow->m_strEffectIdle;
    query.m_nObject = 0;
    query.SetActor(m_pOwner->GetObjectId());
    query.m_bFlag31 = true;
    m_nEffect = reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(static_cast<NoticeMessage*>(&query)));
    m_pOwner->vfunc_47(false);
    m_pOwner->FUN_141670330((float)m_spRow->m_nNameTagOffset);
    m_pOwner->FUN_141670360((float)m_spRow->m_nNameTagOffset);
    efd::utf8string strAnim(m_spRow->m_strAniIdle);
    m_pOwner->PlayAnimation(strAnim, m_pOwner->FUN_1416713c0(), false, false);
}

// @0x1417c8f60
void StateGlide::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->GetPhysicsBody() != 0)
        ((Unk_GlideHit*)(reinterpret_cast<GameObjectController*>(m_pOwner->GetPhysicsBody())->GetHitReport()))->FUN_140cfaf30();
    if (m_spRow == 0)
        return;
    UpdateGlide((float)fTime);
    int bLand = 0;
    if (m_spRow->m_bOnGroundDisable)
    {
        if (m_pOwner->FUN_141671a30() != 0)
        {
            bLand = 1;
        }
        else
        {
            efd::Point3 kPos = reinterpret_cast<Unk_GlOwnerSlots*>(m_pOwner)->vfunc_18();
            float fDist = 0.0f;
            if (((class CPhysXHelper*)GetPhysXHelper())->GetGroundDistance(kPos, &fDist, 200.0f) != 0 && fDist < 100.0f)
                bLand = 1;
        }
    }
    if (m_pOwner->GetClassID() == 0x6200044)
        bLand = 0;
    if (((AdditionalCliList*)m_pOwner->FUN_1416749a0())->FUN_140970a00() != 0 || bLand)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417c9110
void StateGlide::vfunc_5(int n)
{
    StateMoveSkill::vfunc_5(n);
    ((GameObjectController*)m_pOwner->GetPhysicsBody())->StopJump();
    m_pOwner->FUN_141670330(0);
    m_pOwner->FUN_141670360(0);
    m_pOwner->vfunc_47(true);
    reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a6060(m_nEffect);
    m_nAnim = 99;
    if (m_nEffect != 0)
    {
        reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
    }
    m_spRow.AssignRaw(0);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        pPC->FUN_141676060(reinterpret_cast<const NiPoint3&>(efd::Point3::ZERO));
    m_pOwner->FUN_14166f8f0(0, 1);
}

// @0x1417c9250
void StateGlide::vfunc_7(int n)
{
    m_pOwner->vfunc_59(n, 0, 0, 0);
}

// @0x1417c92a0
void StateGlide::vfunc_8(double fTime)
{
    StateMoveSkill::vfunc_8(fTime);
    Unk_GlideBuff* pBuff = (Unk_GlideBuff*)m_pOwner->FUN_14166d240();
    Vector3 kDir = reinterpret_cast<Unk_PCMove*>(pBuff)->FUN_141683900();
    reinterpret_cast<Unk_GlOwnerSlots*>(m_pOwner)->vfunc_22(reinterpret_cast<const efd::Point3&>(kDir));
    if (m_pOwner->FUN_1416749c0())
        m_n10 = 100;
    else
        m_n10 = 99;
}

// @0x1417c9360
void StateGlide::vfunc_9(double fTime)
{
    if (m_nAnim != m_n10)
    {
        if (m_nAnim == 99)
        {
            if (m_nEffect != 0)
            {
                reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a6060(m_nEffect);
                Unk_EffectQuery query;
                query.m_strName = m_spRow->m_strEffectRun;
                query.m_nObject = 0;
                query.SetActor(m_pOwner->GetObjectId());
                query.m_bFlag31 = true;
                m_nEffect = reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(static_cast<NoticeMessage*>(&query)));
            }
            efd::utf8string strAnim(m_spRow->m_strAniRun);
            m_pOwner->PlayAnimation(strAnim, m_pOwner->FUN_1416713c0(), false, false);
        }
        else
        {
            if (m_nEffect != 0)
            {
                reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a6060(m_nEffect);
                Unk_EffectQuery query;
                query.m_strName = m_spRow->m_strEffectIdle;
                query.m_nObject = 0;
                query.SetActor(m_pOwner->GetObjectId());
                query.m_bFlag31 = true;
                m_nEffect = reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(static_cast<NoticeMessage*>(&query)));
            }
            efd::utf8string strAnim(m_spRow->m_strAniIdle);
            m_pOwner->PlayAnimation(strAnim, m_pOwner->FUN_1416713c0(), false, false);
        }
        m_nAnim = m_n10;
    }
}

// @0x1417c9660
bool StateGlide::vfunc_28(MS2Ptr<StateSyncObject> p)
{
    if (m_spRow == 0)
        return true;
    return m_spRow->m_nId != p->m_n68;
}

// @0x1417c9710
int StateGlide::vfunc_22(MS2Ptr<StateSyncObject> p)
{
    return 1;
}

// @0x1417c9740
int StateGlide::FUN_1417c9740()
{
    if (m_spRow == 0)
        return 0;
    return m_spRow->GetId();
}

// @0x1417c9790
bool StateGlide::vfunc_38(StateData* pData)
{
    if (!StateMoveSkill::vfunc_38(pData))
        return false;
    StateGlideData* pGlide = dynamic_cast<StateGlideData*>(pData);
    if (pGlide == 0)
        return false;
    m_spRow = reinterpret_cast<SkillDataTable*>(TSingleton<SkillDataTableCli>::GetInstance())->GetGlideData(pGlide->m_n20);
    if (m_spRow == 0)
        return false;
    return true;
}

// @0x1417c9880
void StateGlide::UpdateGlide(float fTime)
{
    m_fTime += fTime;
    efd::Point3 kMove = (GetVerticalMove() + FUN_1417c9ee0()) * fTime;
    m_pOwner->FUN_141671960(GetHorizontalVelocity());
    reinterpret_cast<GameObjectController*>(m_pOwner->GetPhysicsBody())->SetKVelocity(FUN_1417c9ee0());
    reinterpret_cast<Unk_GlOwnerSlots*>(m_pOwner)->vfunc_68(kMove, fTime, 0, 0x10, 1);
}

extern "C" float (__cdecl* __imp_cosf)(float);   // cosf through the CRT import table (the exe calls it indirectly)

// @0x1417c99f0
float StateGlide::FUN_1417c99f0()
{
    if (IsNearlyEqual(m_spRow->m_fVerticalVibrateAmplitude, 0))
        return 0.0f;
    if (IsNearlyEqual(m_spRow->m_fVerticalVibrateFrequency, 0))
        return 0.0f;
    return m_spRow->m_fVerticalVibrateAmplitude * __imp_cosf((m_fTime * 3.1415927f * 2.0f) / m_spRow->m_fVerticalVibrateFrequency);
}

// @0x1417c9ad0
float StateGlide::GetVerticalVelocity()
{
    float fBonus = 0.0f;
    PC* pActor = efd::DynamicCast<PC, PCBase>(m_pOwner);
    if (pActor != 0)
    {
        fBonus += pActor->FUN_141662930(0x73);
    }
    return m_spRow->m_fVerticalVelocity + m_spRow->m_fVerticalVelocity * fBonus;
}

// @0x1417c9b70
float StateGlide::GetHorizontalVelocity()
{
    return m_spRow->m_fHorizontalVelocity;
}

// @0x1417c9ba0
efd::Point3 StateGlide::FUN_1417c9ba0()
{
    return m_pOwner->CalcMoveDirectionNoYaw(m_pOwner->FUN_14123c360());
}

// @0x1417c9c00
efd::Point3 StateGlide::GetVerticalMove()
{
    if (m_bTooHigh)
        return efd::Point3::ZERO;
    float fSway = FUN_1417c99f0();
    float fFall = m_spRow->m_fVerticalAccelerate * m_fTime;
    if (!IsNearlyEqual(m_spRow->m_fGlideVerticalAccelerateLimit, 0))
        fFall = fFall > m_spRow->m_fGlideVerticalAccelerateLimit ? m_spRow->m_fGlideVerticalAccelerateLimit : fFall;
    float fTotal = GetVerticalVelocity() + fFall;
    if (!m_bHeightErr)
    {
        m_bHeightErr = FUN_1417ca000() == 0;
        if (m_bHeightErr == true && m_pOwner->vfunc_108() != 0)
            ShowSystemNotice(GetStringCommonByKey(L"s_err_skill_maximum_Height"), 1, 1);
    }
    float fZ = m_bHeightErr ? fSway : (fTotal += fSway);
    if (!m_bHeightErr)
        fZ -= m_spRow->m_fGravity;
    return efd::Point3::UNIT_Z * fZ;
}

// @0x1417c9ee0
efd::Point3 StateGlide::FUN_1417c9ee0()
{
    float fForward = m_spRow->m_fHorizontalAccelerate * m_fTime;
    if (!IsNearlyEqual(m_spRow->m_fGlideHorizontalAccelerateLimit, 0))
        fForward = fForward > m_spRow->m_fGlideHorizontalAccelerateLimit ? m_spRow->m_fGlideHorizontalAccelerateLimit : fForward;
    float fSpeed = GetHorizontalVelocity() + fForward;
    if (20.0f < fSpeed)
        fSpeed = 20.0f;
    return FUN_1417c9ba0() * fSpeed;
}

// @0x1417ca000
int StateGlide::FUN_1417ca000()
{
    const efd::Point3& kPos = static_cast<const efd::Point3&>(m_pOwner->vfunc_18());
    if (WorldService::GetInstance()->GetBoundsMax().z - 300.0f < kPos.z)
        return 0;
    if (0.0f < m_spRow->m_fHeightLimit && m_spRow->m_fHeightLimit < m_pOwner->vfunc_18().z - m_fStartZ)
        return 0;
    return 1;
}

// @0x1417ca1e0
MS2Ptr<StateData> StateGlide::vfunc_27()
{
    return MS2Ptr<StateData>(new StateGlideData());
}

// @0x1417ca260
int StateGlide::vfunc_1()
{
    return 0x1e;
}
