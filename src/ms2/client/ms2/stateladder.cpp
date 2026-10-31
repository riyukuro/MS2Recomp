// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateLadder, the actor state of a player climbing a ladder /
// rope entity: up / down movement driven by the move keys, the get-on / get-off interpolation between recorded points,
// and the fall-off when the ladder ends. See stateladder.h.
// MS2-UNIT: ?\stateladder.cpp
// MS2-RANGE: 0x1417d79e0-0x1417d9c70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateladder.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <math.h>
#include <float.h>
#include <new>
#include <egf/Entity.h>
#include <efd/Point3.h>

#include "stateladder.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

void FUN_1408a20a0(egf::Entity* pEntity, unsigned int nHash, bool* pbOut);                // property read (bool)
void FUN_1409618c0(egf::Entity* pEntity, unsigned int nHash, efd::Point3* pOut);          // property read (point)
bool FUN_140998dc0(const NiFixedString& kStr, const char* psz);                           // string compare
bool FUN_14028d470(float a, float b);                                                      // approx equal
float FUN_14059d930(float f);                                                              // fabsf
bool FUN_1412410c0(Unk_PCBaseBody* pBody, const efd::Point3& kPos, float fHeight);                // blocked test of the body
void FUN_141240730(Unk_PCBaseBody* pBody);
void* FUN_141240f20(Unk_PCBaseBody* pBody);
void FUN_140cfaf30(void* p);
// Physics: the ray cast record and the PhysX helper (physxhelper.h cannot be included here: it needs NOMINMAX).
struct Unk_RayCastInfo
{
    Unk_RayCastInfo();                                  // 0x140ad4440
    efd::Point3 m_origin;                               // +0x00
    efd::Point3 m_dir;                                  // +0x0c
    float m_maxDist;                                    // +0x18
    int m_groups;                                       // +0x1c
    void* m_20;
    void* m_28;
    void* m_hitEntity;                                  // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                    // +0x48
    efd::Point3 m_hitPoint;                             // +0x4c
    efd::Point3 m_hitNormal;                            // +0x58
};
MS2_CHECK_SIZE(Unk_RayCastInfo, 0x68);
class NxGroupsMask;
class CPhysXHelper
{
public:
    bool CastRay(Unk_RayCastInfo* pInfo, const NxGroupsMask* pMask);
    int FUN_14168a450(const efd::Point3& kPos, float* pfDist, float fMaxDist);     // ground below kPos
};
CPhysXHelper* FUN_1409f7ca0();
int FUN_140961880(egf::Entity* pEntity, unsigned int nHash, float* pOut);                 // property read (float)
void FUN_140291bc0(efd::Point3* pDegrees);                                                 // wrap the angles into 0..359
extern efd::Point3 DAT_143a08cf8;                                                          // the up axis

// The owner seen through its vftable: the exe returns slot 18's point straight into an efd::Point3 local, and slot 22
// takes the point by value (gameobject.h declares it by reference; the caller copies it into an argument temp).
class Unk_LadderOwnerSlots
{
public:
#define MS2_LADDER_SLOTS(a, b, c, d, e, f, g, h, i, j, k) virtual void vfunc_##a(); virtual void vfunc_##b(); \
    virtual void vfunc_##c(); virtual void vfunc_##d(); virtual void vfunc_##e(); virtual void vfunc_##f(); \
    virtual void vfunc_##g(); virtual void vfunc_##h(); virtual void vfunc_##i(); virtual void vfunc_##j(); \
    virtual void vfunc_##k();
    MS2_LADDER_SLOTS(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
#undef MS2_LADDER_SLOTS
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual efd::Point3 vfunc_18();                                         // 18 0x14123c120 (returned into the local)
    virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kDir);                                // 22 0x14123c3a0
};
// The actor's move-key state (PCBase::FUN_14166d240).
class Unk_LadderMove
{
public:
    bool FUN_141682fe0(int nKey);
    bool FUN_141683100(int nKey);
    efd::Point3 FUN_141683290();                                                           // the move direction of the keys
};

// @0x1417d79e0
void Unk_LadderStep::FUN_1417d79e0(efd::Point3 kA, efd::Point3 kB, efd::Point3 kC)
{
    m_timer.FUN_1408687f0();
    m_a = kA;
    m_b = kB;
    m_c = kC;
}

// @0x1417d7a60
void Unk_LadderStep::FUN_1417d7a60()
{
    m_timer.FUN_1408687f0();
    m_a = efd::Point3::ZERO;
    m_b = efd::Point3::ZERO;
    m_c = efd::Point3::ZERO;
}

// @0x1417d7ad0
void Unk_LadderStep::FUN_1417d7ad0(unsigned int ms)
{
    m_timer.FUN_140868750(ms);
}

// @0x1417d7b00
float Unk_LadderStep::FUN_1417d7b00()
{
    return m_timer.FUN_140868940();
}

// @0x1417d7b30
StateLadder::StateLadder(PCBase* pOwner) : State(pOwner)
{
    m_pLadder = 0;
    m_n14 = 0;
    m_bUpFlip = false;
    m_bDownFlip = false;
}

// @0x1417d7c30
StateLadder::~StateLadder()
{
}

// @0x1417d7ce0
void StateLadder::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    FUN_141240730(m_pOwner->FUN_14166d220());
    m_timerPos.FUN_140868750(100);
    m_timerUp.FUN_1408687f0();
    m_timerDown.FUN_1408687f0();
    m_step0.FUN_1417d7a60();
    m_step1.FUN_1417d7a60();
    m_step2.FUN_1417d7a60();
    m_step3.FUN_1417d7a60();
    m_bUpFlip = false;
    m_bDownFlip = false;
    int nSide;
    if (m_n10 == 0x2f)
        nSide = 1;
    else if (m_n10 == 0x30)
        nSide = 2;
    else
        nSide = 3;
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC != 0)
    {
        if (((void*)(reinterpret_cast<PC*>(pMyPC)->FUN_14165f100())) != 0)
            reinterpret_cast<PC*>(pMyPC)->SendRequestCube();
    }
    PCBase* pPC = FUN_1417b8370();
    egf::Entity* pLadder = reinterpret_cast<PC*>(pPC)->FUN_141659af0(nSide);
    if (pLadder != 0 && pPC != 0)
    {
        efd::Point3 kRot;
        efd::Point3 kBase;
        float fDist;
        FUN_1409618c0(pLadder, 0xfd95ca52, &kBase);
        FUN_1409618c0(pLadder, 0x68c7c29d, &kRot);
        FUN_140961880(pLadder, 0xf8b99313, &fDist);
        kRot.z = kRot.z + 180.0f;
        FUN_140291bc0(&kRot);
        pPC->FUN_14166d970(kRot);
        kBase = kBase + (-m_pOwner->FUN_14123cc20()) * fDist;
        kBase.z = FUN_1417d9880(pLadder);
        NiPoint3 kPos = pPC->vfunc_18();
        efd::Point3 kMid(kBase.x, kBase.y, kPos.z);
        m_step0.FUN_1417d79e0(reinterpret_cast<const efd::Point3&>(kPos), efd::Point3::ZERO, kBase);
        m_step3.FUN_1417d79e0(reinterpret_cast<const efd::Point3&>(kPos), kMid, kBase);
        m_step1.FUN_1417d79e0(reinterpret_cast<const efd::Point3&>(kPos), kMid, kBase);
        m_step2.FUN_1417d79e0(reinterpret_cast<const efd::Point3&>(kPos), efd::Point3::ZERO, kBase);
        if (m_n10 == 0x2f)
            m_step0.FUN_1417d7ad0(0x96);
        else if (m_n10 == 0x30)
            m_step1.FUN_1417d7ad0(200);
        else
        {
            m_n10 = 0x31;
            m_step2.FUN_1417d7ad0(100);
        }
        m_pLadder = pLadder;
    }
    else
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    m_pOwner->FUN_14123cb20(false);
}

// @0x1417d82a0
void StateLadder::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_14166d8b0(m_pOwner->vfunc_20().z);
    FUN_141240730(m_pOwner->FUN_14166d220());
    m_pOwner->FUN_14123cb20(true);
    m_n10 = 0x2a;
    if (m_pOwner->FUN_14166d220() != 0)
        FUN_140cfaf30(FUN_141240f20(m_pOwner->FUN_14166d220()));
    m_pLadder = 0;
}

// @0x1417d8370
void StateLadder::vfunc_3(double fTime)
{
    if (m_pLadder == 0)
        return;
    if (m_n10 == 0x2b && m_timerUp.FUN_140868ba0() == 0)
    {
        FUN_1417d9240(0);
        m_n10 = 0x2a;
    }
    if (m_n10 == 0x2c && m_timerDown.FUN_140868ba0() == 0)
    {
        FUN_1417d9240(0);
        m_n10 = 0x2a;
    }
    if (m_n10 == 0x2a)
    {
        NiPoint3 kVel = m_pOwner->FUN_14123c360();
        if (kVel.y > 0.0f)
            m_n10 = 0x2b;
        else if (kVel.y < 0.0f)
            m_n10 = 0x2c;
    }
    float fDist = FUN_1417d8c00();
    FUN_1417d9240(fDist);
}

// @0x1417d8490
void StateLadder::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    Unk_LadderMove* pMove = (Unk_LadderMove*)m_pOwner->FUN_14166d240();
    efd::Point3 kDir = efd::Point3::ZERO;
    if (m_timerPos.FUN_140868c00() != 0)
        kDir = pMove->FUN_141683290();
    reinterpret_cast<Unk_LadderOwnerSlots*>(m_pOwner)->vfunc_22(kDir);
    if (pMove->FUN_141683100(0x493e1) || m_n28 != 0)
    {
        m_n28 = 0;
        reinterpret_cast<Unk_LadderOwnerSlots*>(m_pOwner)->vfunc_22(pMove->FUN_141683290());
        if (m_pOwner->FUN_1416749c0() && !pMove->FUN_141682fe0(0x30d43) && !pMove->FUN_141682fe0(0x30d44)
            && pMove->FUN_141682fe0(0x30d41))
            reinterpret_cast<Unk_LadderOwnerSlots*>(m_pOwner)->vfunc_22(efd::Point3::ZERO);
        m_pOwner->vfunc_59(6, 0, 0, 0);
    }
}

// @0x1417d86d0
void StateLadder::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    switch (m_n10)
    {
    case 0x2a:
        m_pOwner->FUN_14166dda0(0xc);
        m_bDownFlip = false;
        m_bUpFlip = false;
        break;
    case 0x2b:
    {
        int nAnim;
        if (m_bUpFlip)
            nAnim = 0xd;
        else
            nAnim = 0xe;
        m_pOwner->FUN_14166dda0(nAnim);
        break;
    }
    case 0x2c:
    {
        int nAnim;
        if (m_bDownFlip)
            nAnim = 8;
        else
            nAnim = 9;
        m_pOwner->FUN_14166dda0(nAnim);
        break;
    }
    case 0x2d:
        m_pOwner->FUN_14166dda0(0xf);
        break;
    case 0x2e:
        m_pOwner->FUN_14166dda0(10);
        break;
    case 0x30:
        m_pOwner->FUN_14166dda0(0xb);
        break;
    case 0x2f:
        m_pOwner->FUN_14166dda0(0x10);
    }
}

// @0x1417d8840
void StateLadder::TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID, const NiFixedString& kTextKey,
    const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_pOwner->FUN_14166de90(0xd, eSequenceID) || m_pOwner->FUN_14166de90(0xe, eSequenceID))
    {
        if (FUN_140998dc0(kTextKey, "begin") != 0)
            m_timerUp.FUN_140868750((int)(200.0f / m_pOwner->FUN_1416713c0()));
    }
    else if (m_pOwner->FUN_14166de90(8, eSequenceID) || m_pOwner->FUN_14166de90(9, eSequenceID))
    {
        if (FUN_140998dc0(kTextKey, "begin") != 0)
            m_timerDown.FUN_140868750((int)(200.0f / m_pOwner->FUN_1416713c0()));
    }
}

// @0x1417d8980
void StateLadder::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (m_pOwner->FUN_14166de90(0xd, eSequenceID) || m_pOwner->FUN_14166de90(0xe, eSequenceID))
    {
        if (m_pOwner->FUN_14123c360().y != 0.0f)
            m_pOwner->FUN_14166e0a0();
        m_bUpFlip = !m_bUpFlip;
    }
    else if (m_pOwner->FUN_14166de90(8, eSequenceID) || m_pOwner->FUN_14166de90(9, eSequenceID))
    {
        if (m_pOwner->FUN_14123c360().y != 0.0f)
            m_pOwner->FUN_14166e0a0();
        m_bDownFlip = !m_bDownFlip;
    }
    else if (m_pOwner->FUN_14166de90(10, eSequenceID))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417d8b20
egf::Entity* StateLadder::FUN_1417d8b20(int nSide, unsigned int nKey)
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        egf::Entity* pFound = reinterpret_cast<PC*>(pPC)->FUN_141659b80(nSide, nKey, 90.0f);
        if (pFound == 0)
            return 0;
        if (pFound != m_pLadder)
        {
            efd::Point3 kNew;
            FUN_1409618c0(pFound, 0x68c7c29d, &kNew);
            efd::Point3 kOld;
            FUN_1409618c0(m_pLadder, 0x68c7c29d, &kOld);
            if (kNew != kOld)
                return 0;
        }
        return pFound;
    }
    return 0;
}

// @0x1417d8c00
float StateLadder::FUN_1417d8c00()
{
    bool bFlag = false;
    if (m_pLadder != 0)
        FUN_1408a20a0(m_pLadder, 0x4df0c0de, &bFlag);
    float fMove = 0.0f;
    if (bFlag == false)
    {
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0)
        {
            NiPoint3 kPos = pPC->vfunc_18();
            float fGround = 0.0f;
            if (FUN_1409f7ca0()->FUN_14168a450(kPos, &fGround, 0.0f) != 0
                && fGround != FLT_MAX)
                m_n10 = 0x32;
        }
    }
    else if (m_n10 == 0x2b)
    {
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0)
        {
            fMove = 75.0f * m_timerUp.FUN_140868b20();
            egf::Entity* pFound = FUN_1417d8b20(1, 0xbadf0a13);
            if (pFound == 0)
            {
                efd::Point3 kTop = FUN_1417d99e0();
                if (kTop == efd::Point3::ZERO)
                    return 0.0f;
                {
                    kTop.z = kTop.z + 5.0f;
                    NiPoint3 kPos = m_pOwner->vfunc_18();
                    kPos.z = kPos.z + fMove;
                    if ((kPos - kTop).Length() > 150.0f)
                        m_n10 = 0x2a;
                    else
                    {
                        efd::Point3 kAt = kTop;                     // unused copy (the exe makes it)
                        efd::Point2 kSize = m_pOwner->FUN_141671390();
                        if (FUN_1412410c0(m_pOwner->FUN_14166d220(), kTop, kSize.y * 0.5f) == 0)
                        {
                            efd::Point3 kMid = kPos;
                            kMid.z = kTop.z;
                            m_step3.FUN_1417d79e0(reinterpret_cast<const efd::Point3&>(kPos), kMid, kTop);
                            m_step3.FUN_1417d7ad0(200);
                            m_n10 = 0x2d;
                        }
                        else
                            m_n10 = 0x2a;
                    }
                }
            }
            else if (m_pLadder != pFound)
                m_pLadder = pFound;
        }
    }
    else if (m_n10 == 0x2c)
    {
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0)
        {
            fMove = 75.0f * m_timerDown.FUN_140868b20();
            egf::Entity* pFound = FUN_1417d8b20(2, 0xbadf0a13);
            if (pFound == 0 && m_pLadder != 0)
            {
                NiPoint3 kPos = pPC->vfunc_18();
                efd::Point3 kProp = efd::Point3::ZERO;
                float fGround = 0.0f;
                if (FUN_1409f7ca0()->FUN_14168a450(kPos, &fGround, 0.0f) != 0)
                {
                    float fHit = kPos.z - fGround;
                    FUN_1409618c0(m_pLadder, 0xfd95ca52, &kProp);
                    if (kPos.z - fMove <= fHit && fGround != FLT_MAX)
                    {
                        m_n10 = 0x2e;
                        if (kPos.z < fHit)
                        {
                            kPos.z = fHit + 1.0f;
                            pPC->vfunc_19(reinterpret_cast<const efd::Point3&>(kPos));
                        }
                    }
                    else
                    {
                        if (kPos.z - fMove <= kProp.z)
                            pPC->vfunc_59(5, 0, 0, 0);
                    }
                }
                else
                {
                    FUN_1409618c0(m_pLadder, 0xfd95ca52, &kProp);
                    if (FUN_14028d470(kPos.z, kProp.z) != 0)
                        m_n10 = 0x2e;
                }
            }
            else if (m_pLadder != pFound)
                m_pLadder = pFound;
        }
    }
    return fMove;
}

// @0x1417d9240
void StateLadder::FUN_1417d9240(float fDist)
{
    efd::Point3 kPos = reinterpret_cast<Unk_LadderOwnerSlots*>(m_pOwner)->vfunc_18();
    if (m_n10 == 0x2b)
        kPos.z = kPos.z + fDist;
    else if (m_n10 == 0x2c)
        kPos.z = kPos.z - fDist;
    else if (m_n10 == 0x32)
    {
        kPos.z = kPos.z - fDist;
        m_pOwner->vfunc_59(5, 0, 0, 0);
    }
    else if (m_n10 == 0x2d)
    {
        float fRatio = m_step3.FUN_1417d7b00();
        if (fRatio <= 0.5f)
        {
            efd::Point3 kStep = m_step3.m_b - m_step3.m_a;
            kStep *= fRatio * 2.0f;
            kPos = m_step3.m_a + kStep;
        }
        else if (fRatio < 1.0f)
        {
            efd::Point3 kStep = m_step3.m_c - m_step3.m_b;
            kStep *= (fRatio - 0.5f) * 2.0f;
            kPos = m_step3.m_b + kStep;
        }
        else if (fRatio == 1.0f)
        {
            kPos = m_step3.m_c;
            m_pOwner->vfunc_59(1, 0, 0, 0);
        }
    }
    else if (m_n10 == 0x2f)
    {
        float fRatio = m_step0.FUN_1417d7b00();
        if (fRatio == 1.0f)
        {
            kPos = m_step0.m_c;
            m_n10 = 0x2a;
        }
        else
        {
            efd::Point3 kStep = m_step0.m_c - m_step0.m_a;
            kStep *= fRatio;
            kPos = m_step0.m_a + kStep;
        }
    }
    else if (m_n10 == 0x30)
    {
        float fRatio = m_step1.FUN_1417d7b00();
        if (fRatio <= 0.5f)
        {
            efd::Point3 kStep = m_step1.m_b - m_step1.m_a;
            kStep *= fRatio * 2.0f;
            kPos = m_step1.m_a + kStep;
        }
        else if (fRatio < 1.0f)
        {
            efd::Point3 kStep = m_step1.m_c - m_step1.m_b;
            kStep *= (fRatio - 0.5f) * 2.0f;
            kPos = m_step1.m_b + kStep;
        }
        else if (fRatio == 1.0f)
        {
            kPos = m_step1.m_c;
            m_n10 = 0x2a;
        }
    }
    else if (m_n10 == 0x31)
    {
        float fRatio = m_step2.FUN_1417d7b00();
        if (fRatio == 1.0f)
        {
            kPos = m_step2.m_c;
            m_n10 = 0x2a;
        }
        else
        {
            efd::Point3 kStep = m_step2.m_c - m_step2.m_a;
            kStep *= fRatio;
            kPos = m_step2.m_a + kStep;
        }
    }
    else
        return;
    m_pOwner->vfunc_19(kPos);
}

// @0x1417d9880
float StateLadder::FUN_1417d9880(egf::Entity* pLadder)
{
    const float fDrop = 5.0f;
    efd::Point3 kProp = efd::Point3::ZERO;
    efd::Point3 kAbove = m_pOwner->vfunc_18() + efd::Point3(0.0f, 0.0f, 90.0f);
    FUN_1409618c0(pLadder, 0xfd95ca52, &kProp);
    float fNear = FUN_14059d930((kAbove.z - kProp.z) + 56.0f);
    float fFar = FUN_14059d930((kAbove.z - kProp.z) + 131.0f);
    float fZ;
    if (fNear < fFar)
        fZ = kProp.z + 56.0f - fDrop;
    else
        fZ = kProp.z + 131.0f - fDrop;
    return fZ;
}

// @0x1417d99e0
efd::Point3 StateLadder::FUN_1417d99e0()
{
    efd::Point3 kFace = m_pOwner->FUN_14123cc20();
    NiPoint3 kPos = m_pOwner->vfunc_18();
    kPos += kFace * 75.0f;
    kPos.z = kPos.z + 500.0f;
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = kPos;
    kInfo.m_dir = -DAT_143a08cf8;
    kInfo.m_maxDist = 0;
    kInfo.m_groups = 0x201;
    kInfo.m_20 = m_pOwner->FUN_14123c410();
    kInfo.m_28 = 0;
    efd::Point3 kUnused;                                    // the exe constructs a Point3 it never uses
    if (FUN_1409f7ca0()->CastRay(&kInfo, 0))
        return kInfo.m_hitPoint;
    return efd::Point3::ZERO;
}

// @0x1417d9b50
Unk_LadderStep::Unk_LadderStep()
    : m_a(efd::Point3::ZERO), m_b(efd::Point3::ZERO), m_c(efd::Point3::ZERO)
{
}

// @0x1417d9bd0
Unk_LadderStep::~Unk_LadderStep()
{
}

// @0x1417d9c30
int StateLadder::vfunc_1() { return 8; }

// @0x1417d9c40
int StateLadder::vfunc_18() { return 0; }

// @0x1417d9c50
void StateLadder::vfunc_34()
{
    m_n28 = 1;
}
