// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateJump, the actor state of a player jumping: picks the
// jump variant, plays the jump / fall animation, steers in the air with the launch direction and lands (on the ground,
// on a ridee or onto a sit / lie / climb object). See statejump.h.
// MS2-UNIT: ?\statejump.cpp
// MS2-RANGE: 0x140102ff0-0x140103020 .text$di
// MS2-RANGE: 0x1417d5160-0x1417d6c00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statejump.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>

#include <new>
#include <cstdlib>
#include <float.h>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "statejump.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/client/ms2/gameobjectcontroller.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------


class Unk_CubeSelection;
        // the cube selection is in the craft mode
float FUN_14059d930(float f);                              // 0x14059d930 fabs
__int64 FUN_14028d260(float f);                                // 0x14028d260 round to ms  (C3: the definition's __int64 return, read as int)
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
Vector3 FUN_140a0b080(const Vector3& kFrom, const Vector3& kTo, const Vector3& kUp);   // C3: the definer's signature (0x140a0b080), look-at angles
#define DAT_143a08cf8 (*(efd::Point3*)&efd::Point3::UNIT_Z)                          // the up axis

// The animation service: the sequence id of the model.
int FUN_140b7f6a0(void* pSvc, const egf::EntityID& kId);   // C3: the real free function (def in statebannerdata)
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();

// The efd::Point3 *.
class Unk_JpConsts { public: char m_pad[0x48e8]; };
struct Unk_IntOptionEntry { int& FUN_140298f40(); };   // C3: the real member (0x140298f40, commonutil.cpp)
class Unk_JpScale { public: };
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

// The actor's physics body.
inline GameObjectController* JpBody(PCBase* p) { return reinterpret_cast<GameObjectController*>(p->GetPhysicsBody()); }

// The actor's buffs.
#include "ms2/placeholder/nipoint3.h"   // C3: Vector3, the return type of Unk_PCMove::FUN_141683290
#include "ms2/commonfiles/hideandseek.h"   // C3: HideAndSeek::Info
class Unk_PCMove { public: Vector3 FUN_141683290(); bool FUN_141683100(int nKey); };   // C3: view of the real class (unit_141682f80)

// The hide and seek record of the actor (MS2Ptr<T> from PC::FUN_141664200).
class Unk_HsInfo : public CPtred { };
int FUN_141276180(const CString& strCommand, const CString& strArg);   // 0x141276180 run a client command


// The hide-and-seek jump animation name (set up by the .text$di init, cleared when the actor hides) and the toggle of the
// random jump.
static CString s_strHideSeekJump("System_HideNSeek_Jump_01");
static int s_nJumpToggle;

// @0x1417d5160
StateJump::StateJump(PCBase* pOwner) : State(pOwner), m_n54(1), m_n80(0x32)
{
    m_n14 = 0;
    m_vDir = efd::Point3::ZERO;
    m_nOnGround = 0;
    m_fSpeed = 0;
    m_pSeat = 0;
    m_f60 = -FLT_MAX;
    m_v64 = efd::Point3::ZERO;
    m_aSub[0] = 0x21;
    m_aSub[1] = 0x23;
    (m_aSub + 2)[0] = 0x22;
    (m_aSub + 2)[1] = 0x24;
}

// @0x1417d52e0
StateJump::~StateJump()
{
}

// @0x1417d5320
// MS2-FUNCTIONAL: the record ref has no dtor (the exe has two more EH states)
void StateJump::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spJump.AssignRaw(dynamic_cast<StateJumpData*>(pData));
    if (m_pOwner->FUN_141676b70() != 0)
    {
        m_n10 = 0x27;
    }
    else if (m_n10 == 0)
    {
        m_n10 = 0x21;
    }
    else if (m_n10 == 0x25)
    {
        s_nJumpToggle = (s_nJumpToggle + 1) % 2;
        int nSub;
        if (rand() % 2 != 0)
            nSub = (m_aSub + 2)[s_nJumpToggle];
        else
            nSub = m_aSub[s_nJumpToggle];
        m_n10 = nSub;
    }
    m_pSeat = 0;
    m_f60 = -FLT_MAX;
    m_v64 = efd::Point3::ZERO;
    m_vDir = m_pOwner->CalcMoveDirectionNoYaw(m_pOwner->FUN_14123c360());
    m_n54 = 1;
    m_fSpeed = m_pOwner->FUN_141671940();
    m_nOnGround = m_pOwner->FUN_1416749c0();
    float fA = m_pOwner->FUN_14166da60();
    float fSpeed = m_pOwner->vfunc_95();
    GameObjectController* pBody = JpBody(m_pOwner);
    pBody->FUN_141240730();
    pBody->FUN_141240610(fA, m_vDir, fSpeed);
    m_tick.Init();
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        pPC->FUN_141676060(m_pOwner->vfunc_18());
        pPC->SendStateChange(0, 6);
        MS2Ptr<Unk_HsInfo> spInfo = pPC->GetHideAndSeekInfo();
        if (spInfo.get() ? true : false)
        {
            if (reinterpret_cast<HideAndSeek::Info*>(spInfo.operator->())->FUN_14050a6a0() == 1)
                FUN_141276180(s_strHideSeekJump, "");
        }
    }
}

#define DAT_143b01a60 (*(const NiPoint3*)&efd::Point3::ZERO)          // C3: was extern const NiPoint3 DAT_143b01a60

// @0x1417d5700
// MS2-FUNCTIONAL: the zero point is copied byte-wise in the exe
void StateJump::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_141671960(m_fSpeed);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        if (n != 5 && n != 4 && n != 0x10)
            pPC->FUN_141676060(DAT_143b01a60);
        pPC->SendStateChange(1, 6);
    }
}

// @0x1417d57b0
void StateJump::vfunc_6()
{
    State::vfunc_6();
    m_n10 = 0x26;
    unsigned nSeq = FUN_140b7f6a0(FUN_141b6f910(), m_pOwner->FUN_14123c460());
    if (!m_pOwner->FUN_14166de90(0x35, nSeq))
    {
        efd::utf8string strAnim(m_pOwner->vfunc_123(0x35));
        m_pOwner->PlayAnimation(strAnim, 1.0f, false, false);
    }
}

// @0x1417d58d0
void StateJump::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    GameObjectController* pBody = JpBody(m_pOwner);
    if (pBody->IsJumping() != 0)
    {
        efd::Point3 kWorld = m_pOwner->CalcMoveDirectionNoYaw(m_pOwner->FUN_14123c360());
        if (m_pOwner->FUN_14166dbb0() != efd::Point3::ZERO)
        {
            m_vDir = m_pOwner->FUN_14166dbb0();
            if (m_spJump)
            {
                efd::Point3 kJump = m_spJump->m_pos;
                Vector3 kRot = FUN_140a0b080(reinterpret_cast<const Vector3&>(kJump), reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(m_pOwner->vfunc_18())), reinterpret_cast<const Vector3&>(DAT_143a08cf8));
                m_pOwner->SetRotationAndTargetYaw(reinterpret_cast<efd::Point3&>(kRot));
            }
        }
        else
        {
            if (m_nOnGround == 0 && m_n54 != 0 && kWorld != efd::Point3::ZERO)
            {
                m_vDir = kWorld;
                m_n54 = 0;
                m_pOwner->FUN_141671960(1.0f);
            }
            else if (kWorld != efd::Point3::ZERO)
            {
                m_vDir = kWorld;
            }
        }
        float fScale = reinterpret_cast<float&>(reinterpret_cast<Unk_IntOptionEntry*>(reinterpret_cast<char*>(((class Unk_JpConsts*)FUN_1401d3200())) + 0x48e8)->FUN_140298f40());
        JpBody(m_pOwner)->SetKVelocity((m_vDir * m_pOwner->vfunc_95()) * fScale);
        efd::Point3 kMove = efd::Point3::ZERO;
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
    }
    else
    {
        m_pOwner->vfunc_59(4, 0, 0, 0);
    }
}

// @0x1417d5c70
void StateJump::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    Unk_PCMove* pBuff = (Unk_PCMove*)m_pOwner->FUN_14166d240();
    m_pOwner->vfunc_22(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pBuff->FUN_141683290())));
    if (m_pOwner->FUN_141676b70() != 0)
        m_n10 = 0x27;
    if (pPC != 0 && pBuff->FUN_141683100(0x30d41))
    {
        if (!FUN_1417d65d0())
            return;
        egf::Entity* pEntity = reinterpret_cast<PC*>(pPC)->FUN_141659af0(1);
        if (pEntity != 0)
        {
            if (pPC->FUN_1416764a0())
            {
                MS2Ptr<RideOffActionTakeLR> spAction(new RideOffActionTakeLR(1));
                spAction->m_n28 = 1;
                if (pEntity->GetModel()->ContainsModel(0xbadf0a13))
                    spAction->m_n2c = 0xbadf0a13;
                else if (pEntity->GetModel()->ContainsModel(0xc13e30c8))
                    spAction->m_n2c = 0xc13e30c8;
                pPC->SendRequestRideMode1(spAction);
            }
            else
            {
                pPC->FUN_1415248d0(1, 0);
            }
        }
        else
        {
            if (pPC->FUN_141678820() != 0 && reinterpret_cast<PC*>(pPC)->FUN_14165b500(1) != 0)
                pPC->FUN_1416788d0();
        }
    }
    else
    {
        if (!FUN_1417b9460() && pPC != 0 && FUN_1417d65d0() && FUN_1417d6620() == 0)
        {
            if (pPC->FUN_1416764a0())
            {
                if (m_pOwner->FUN_141678820() != 0 && reinterpret_cast<PC*>(pPC)->FUN_14165b500(1) != 0)
                    pPC->SendRequestRideMode1(new RideOffActionAutoClimb(1));
            }
            else
            {
                if (pPC->FUN_141678820() != 0 && reinterpret_cast<PC*>(pPC)->FUN_14165b500(1) != 0)
                    pPC->FUN_1416788d0();
            }
        }
    }
}

// @0x1417d6000
// MS2-FUNCTIONAL: temporaries / frame layout differ from the exe
void StateJump::vfunc_9(double fTime)
{
    static int s_nDelay = (int)FUN_14028d260(sqrt(12.0f / FUN_14059d930(GameObjectController::FUN_141240c40(true))));
    State::vfunc_9(fTime);
    unsigned nSeq = FUN_140b7f6a0(FUN_141b6f910(), m_pOwner->FUN_14123c460());
    unsigned nLimit = s_nDelay;
    nLimit += (int)FUN_14028d260(JpBody(m_pOwner)->FUN_141241090());
    if (m_pOwner->FUN_141671a30() != 0)
    {
        m_pOwner->vfunc_59(4, 0, 0, 0);
        return;
    }
    if (nLimit <= JpBody(m_pOwner)->FUN_141240ef0())
    {
        m_pOwner->PlayAnimationById(5);
        return;
    }
    if (m_n10 == 0x27 || m_n10 == 0x21 || m_n10 == 0x22 || m_n10 == 0x23 || m_n10 == 0x24)
    {
        int nAnim;
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0 && reinterpret_cast<PC*>(pPC)->IsInCubeMode() != 0 && ((Unk_PCCubeCraft*)((Unk_CubeSelection*)(reinterpret_cast<PC*>(pPC)->GetCubeCraft())))->FUN_1410aa010())
        {
            if (JpBody(m_pOwner)->FUN_1412407a0() != 0)
                nAnim = 0x3a;
            else
                nAnim = 0x3b;
        }
        else if (JpBody(m_pOwner)->FUN_1412407a0() != 0)
        {
            bool bHas = true;
            efd::utf8string strSpecial(m_pOwner->vfunc_123(0x2a));
            if (!m_pOwner->HasAnimSequence(((efd::utf8string*)&static_cast<class efd::utf8string const&>(strSpecial))->c_str()))
                bHas = false;
            if (bHas && (m_n10 == 0x22 || m_n10 == 0x24))
            {
                nAnim = 0x2a;
            }
            else
            {
                if (m_n10 == 0x27)
                    nAnim = 0x46;
                else
                    nAnim = 4;
            }
        }
        else
        {
            bool bHas = true;
            efd::utf8string strSpecial(m_pOwner->vfunc_123(0x2b));
            if (!m_pOwner->HasAnimSequence(((efd::utf8string*)&static_cast<class efd::utf8string const&>(strSpecial))->c_str()))
                bHas = false;
            if (bHas && (m_n10 == 0x22 || m_n10 == 0x24))
            {
                nAnim = 0x2b;
            }
            else
            {
                if (m_n10 == 0x27)
                    nAnim = 0x47;
                else
                    nAnim = 2;
            }
        }
        if (!m_pOwner->FUN_14166de90(nAnim, nSeq))
        {
            efd::utf8string strAnim(m_pOwner->vfunc_123(nAnim));
            m_pOwner->PlayAnimation(strAnim, 1.0f, false, false);
        }
    }
}

// @0x1417d64c0
int StateJump::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
        return 0;
    if (m_n10 == p->m_nSub)
        return 0;
    return 1;
}

// @0x1417d6560
bool StateJump::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    return FUN_1417b7e40() != p->m_nSub;
}

// @0x1417d65d0
bool StateJump::FUN_1417d65d0()
{
    if (m_tick.GetLast() + m_n80 < GetTickCountMs2())
        return true;
    return false;
}

// @0x1417d6620
int StateJump::FUN_1417d6620()
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return 0;
    if (m_pSeat == 0)
    {
        if (m_nOnGround == 0)
        {
            if (JpBody(m_pOwner)->FUN_1412407a0() != 0)
                return 0;
        }
        m_pSeat = reinterpret_cast<PC*>(pPC)->FUN_141659af0(0);
    }
    if (m_pSeat != 0)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            MS2Ptr<RideOffActionTakeLR> spAction(new RideOffActionTakeLR(1));
            spAction->m_n28 = 0;
            if (m_pSeat->GetModel()->ContainsModel(0xbadf0a13))
                spAction->m_n2c = 0xbadf0a13;
            else if (m_pSeat->GetModel()->ContainsModel(0xc13e30c8))
                spAction->m_n2c = 0xc13e30c8;
            if (pPC->SendRequestRideMode1(spAction) != 0)
                pPC->vfunc_59(1, 0, 0, 0);
        }
        else if (m_pSeat->GetModel()->ContainsModel(0xbadf0a13))
        {
            m_pOwner->vfunc_22(efd::Point3::ZERO);
            m_pOwner->vfunc_59(8, 0, 0, 0);
        }
        else if (m_pSeat->GetModel()->ContainsModel(0xc13e30c8))
        {
            m_pOwner->vfunc_22(efd::Point3::ZERO);
            m_pOwner->vfunc_59(9, 0, 0, 0);
        }
        return 1;
    }
    return 0;
}

// @0x1417d6ac0
int StateJump::vfunc_15()
{
    return 1;
}

// @0x1417d6ad0
int StateJump::vfunc_1()
{
    return 6;
}

// @0x1417d6ae0
int StateJump::vfunc_19()
{
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb77e0-0x142cb7800 .text$yd
