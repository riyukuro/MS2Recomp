// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateFall, the actor state of a player in free fall:
// plays the fall animation, steers in the air and lands (on the ground, on a ridee or onto a climbable object).
// See statefall.h.
// MS2-UNIT: ?\statefall.cpp
// MS2-RANGE: 0x1417c6e40-0x1417c7be0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VStateFallData@@@@QEBAPEAVStateFallData@@XZ 0x1417c7a40 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$MS2Ptr@VStateFallData@@@@QEAA@PEAVStateFallData@@@Z 0x1417c79e0 ; merge-bind
// MS2-PIN: ??1?$MS2Ptr@VStateFallData@@@@QEAA@XZ 0x1417c7a10 ; merge-bind
// MS2-PIN: ?AddRef@?$MS2Ptr@VStateFallData@@@@AEBAXXZ 0x1417c7ad0 ; merge-bind
// MS2-PIN: ?Reference@?$MS2Ptr@VStateFallData@@@@CAXPEAVStateFallData@@@Z 0x1417c7b00 ; merge-bind
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateFallData@@@@AEBAXPEAX@Z 0x1417c7b20 ; merge-bind
// MS2-PIN: ?Release@?$MS2Ptr@VStateFallData@@@@AEAAXXZ 0x1417c7b50 ; merge-bind
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VStateFallData@@@@AEAAXPEAX@Z 0x1417c7b90 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statefall.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>

#include "statefall.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The physics body of the actor: sets the velocity.
void FUN_141240700(Unk_PCBaseBody* pBody, efd::Point3 kVel);               // 0x141240700

// The config constants singleton: the air control scale at +0x48e8.
class Unk_FallScale { public: float* FUN_140298f40(); };
class Unk_FallConsts
{
public:
    char m_pad[0x48e8];
    Unk_FallScale m_scale;
};
Unk_FallConsts* FUN_1401d3200();

// The actor's buff set: the knock-back direction.
class Unk_FallBuff { public: efd::Point3 FUN_141683290(); };

// The casting skill record (CSkillRecord); +0x30 holds the table row of its skill.
class Unk_FallRow { public: int FUN_1407e9bd0(); char FUN_1407e9d70(); };
class Unk_FallTable { public: Unk_FallRow* FUN_14063ed50(); };
class Unk_PCBaseComp_b18 : public CPtred
{
public:
    char m_pad_18[0x18];
    Unk_FallTable m_table30;
};
class CSkillRecord : public Unk_PCBaseComp_b18 {};

bool FUN_14028d470(float a, float b);                                      // approx equal
int FUN_14165b500(MyPC* p, int n);
egf::Entity* FUN_141659af0(MyPC* p, int nSide);                            // the nearby object to sit / lie on

// @0x1417c6e40
StateFall::StateFall(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417c6eb0
StateFall::~StateFall()
{
}

// @0x1417c6ef0
// MS2-FUNCTIONAL: frame 0x20 larger than the exe (temporaries), call order otherwise equal
void StateFall::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    PCBase* pPC = FUN_1417b8370();
    NiPoint3 kPos = m_pOwner->vfunc_18();
    MS2Ptr<StateFallData> spData(dynamic_cast<StateFallData*>(pData));
    bool bHasData = spData.get() != 0;
    if (bHasData)
    {
        if (spData->m_pos != efd::Point3::ZERO)
            kPos = spData->m_pos;
    }
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC != 0)
        pMyPC->FUN_141676060(kPos);
    if (m_pOwner->FUN_141675ed0() == 0 || m_pOwner->FUN_141671a30() == 0)
    {
        m_strAnim = m_pOwner->vfunc_123(5);
        if (pPC != 0)
        {
            CString strRec;
            bool bHasRec = !FUN_1416561a0(pPC)->FUN_1411eabd0().IsEmpty();
            if (bHasRec)
                strRec = FUN_1416561a0(pPC)->FUN_1411eabd0();
            if (!strRec.IsEmpty())
            {
                efd::utf8string kAnim((const char*)FUN_14038f6d0(strRec, m_strAnim.c_str()));
                int nSeq = FUN_141b6f910()->FUN_140999490(m_pOwner->FUN_14123c460(), kAnim);
                if (nSeq != -2)
                    m_strAnim = kAnim;
            }
        }
        m_pOwner->FUN_14166dd20(m_strAnim, m_pOwner->FUN_1416713c0(), false, false);
    }
    else
    {
        m_pOwner->vfunc_59(4, 0, 0, 0);
    }
}

// @0x1417c7330
// MS2-FUNCTIONAL: the zero point is copied byte-wise in the exe
void StateFall::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (n != 4)
    {
        MyPC* pMyPC = FUN_1417b84b0();
        if (pMyPC != 0)
            pMyPC->FUN_141676060(efd::Point3::ZERO);
    }
    m_strAnim = "";
}

// @0x1417c73c0
// MS2-FUNCTIONAL: the zero point is copied byte-wise in the exe
void StateFall::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    efd::Point3 kDir = m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
    if (kDir != efd::Point3::ZERO)
    {
        float fSpeed = m_pOwner->vfunc_95();
        efd::Point3 kVel = kDir * (fSpeed * *FUN_1401d3200()->m_scale.FUN_140298f40());
        FUN_141240700(m_pOwner->FUN_14166d220(), kVel);
    }
    efd::Point3 kMove = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417c7550
// MS2-FUNCTIONAL: frame 0x20 larger than the exe (temporaries), call order otherwise equal
void StateFall::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    Unk_FallBuff* pBuff = (Unk_FallBuff*)m_pOwner->FUN_14166d240();
    efd::Point3 kDir = pBuff->FUN_141683290();
    m_pOwner->vfunc_22(kDir);
    MS2Ptr<Unk_PCBaseComp_b18> spRec = m_pOwner->vfunc_104(true, false, false);
    if (spRec.get() == 0)
    {
        if (pPC->FUN_1416764a0() == 0)
        {
            if (pPC->FUN_141678820() != 0 && FUN_14165b500(pPC, 1) != 0)
                pPC->FUN_1416788d0();
        }
        else
        {
            if (m_pOwner->FUN_141678820() != 0 && FUN_14165b500(pPC, 1) != 0)
                pPC->SendRequestRideMode1(new RideOffActionAutoClimb(1));
        }
    }
    else
    {
        int nKind = spRec->m_table30.FUN_14063ed50()->FUN_1407e9bd0();
        if (nKind == 0x1d || nKind == 0x20 || spRec->m_table30.FUN_14063ed50()->FUN_1407e9d70() != 0)
            m_pOwner->vfunc_102(MS2Ptr<CSkillRecord>(static_cast<CSkillRecord*>(spRec.get())));
    }
}

// @0x1417c77e0
// MS2-FUNCTIONAL: the zero point is copied byte-wise in the exe
void StateFall::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (m_pOwner->FUN_141671a30() == 0)
        return;
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        int nSide = 3;
        if (FUN_14028d470(m_pOwner->FUN_14123c360().y, -1.0f))
            nSide = 2;
        egf::Entity* pEntity = FUN_141659af0(pPC, nSide);
        if (pEntity != 0)
        {
            if (pPC->FUN_1416764a0() != 0)
            {
                MS2Ptr<RideOffActionTakeLR> spAction(new RideOffActionTakeLR(1));
                spAction->m_n28 = nSide;
                spAction->m_n2c = 0xbadf0a13;
                if (pPC->SendRequestRideMode1(spAction) != 0)
                    pPC->vfunc_59(1, 0, 0, 0);
                return;
            }
            if (pPC->FUN_1415248d0(nSide, 0xbadf0a13) != 0)
                return;
        }
    }
    m_pOwner->vfunc_59(4, 0, 0, 0);
}

// @0x1417c7aa0
int StateFall::vfunc_15()
{
    return 1;
}

// @0x1417c7ab0
int StateFall::vfunc_1()
{
    return 5;
}

// @0x1417c7ac0
int StateFall::vfunc_19()
{
    return 0;
}
