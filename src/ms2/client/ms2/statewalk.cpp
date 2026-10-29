// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateWalk / StateWalkNPC, the actor states of a walking
// player and of a walking npc: pick the gait (walk / run / sprint / swim-walk), set the move speed, steer in the move
// direction and play the matching animation. See statewalk.h.
// MS2-UNIT: ?\statewalk.cpp
// MS2-RANGE: 0x1417ff730-0x141801030 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statewalk.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>
#include <efd/SmartPointer.h>

#include "statewalk.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

const char* FUN_1408ac310(const efd::utf8string& str);     // 0x1408ac310 the string's c string
Ridee* FUN_141468360(PCBase* p);                           // 0x141468360 the ridee the actor sits on
int FUN_1416764d0(MyPC* p);                                // 0x1416764d0 is riding
int FUN_1416595d0(PCBase* p);                              // 0x1416595d0
float FUN_141240c40(bool b);                               // 0x141240c40 the move speed (xmm0)
float FUN_14059d930(float f);                              // 0x14059d930 fabs
float FUN_14096b1c0(float f);                              // 0x14096b1c0
int FUN_14028d260(float f);                                // 0x14028d260 round to ms
class Unk_CubeSelection;
Unk_CubeSelection* FUN_141659700(PCBase* p);               // 0x141659700 the cube selection of a player
class Unk_WkCube { public: bool FUN_1410aa010(); };        // the cube selection is in the craft mode
egf::Entity* FUN_141659b80(PCBase* p, int n, unsigned nProp, float fRange);   // 0x141659b80 the nearby object to sit on
int* FUN_1404eb7e0(int* pA, int* pB);                      // 0x1404eb7e0 the larger of two ints

// The animation service: the sequence id of the model / the model's animation name by the entity id.
class Unk_WkAnimSvc
{
public:
    unsigned FUN_140b7f6a0(const egf::EntityID& kId);
    efd::utf8string FUN_141206030(const egf::EntityID& kId);
};
Unk_WkAnimSvc* FUN_141b6f910();

// The replay / spectator mode flag, the key-binding config and the controller input readings.
class Unk_WkPlayback { public: bool FUN_1406af100(); };
Unk_WkPlayback* FUN_1406aeee0();
class Unk_WkConfig { public: bool FUN_14036d570(int nSetting); };
Unk_WkConfig* FUN_140166410();
class Unk_WkInputSvc { public: int FUN_140d8c450(); int FUN_140d8c4d0(); };
Unk_WkInputSvc* FUN_140a58540();
class Unk_WkOption { public: char m_pad[0xc]; int m_n0c; };
Unk_WkOption* FUN_140a58500(void* p);
void* FUN_1409a8b10();
class Unk_WkInput { public: int FUN_140ad2220(); int FUN_140ad2260(); };
Unk_WkInput* FUN_140953f30();

// The actor's buff set: the movement direction and the buff tests.
class Unk_WkBuff
{
public:
    efd::Point3 FUN_141683900();
    bool FUN_141683100(int nKey);
    bool FUN_141682fe0(int nKey);
    bool FUN_141683200(int nKey);
};

// The owner's vtable up to slot 68, which takes the move by value (the exe passes a pointer to a copy).
class Unk_WkOwnerSlots
{
public:
#define MS2_WK_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_WK_SLOTS(0, 1, 2, 3, 4) MS2_WK_SLOTS(5, 6, 7, 8, 9) MS2_WK_SLOTS(10, 11, 12, 13, 14) MS2_WK_SLOTS(15, 16, 17, 18, 19)
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kDir);                                        // 22 takes the direction by value
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_WK_SLOTS(25, 26, 27, 28, 29) MS2_WK_SLOTS(30, 31, 32, 33, 34)
    MS2_WK_SLOTS(35, 36, 37, 38, 39) MS2_WK_SLOTS(40, 41, 42, 43, 44) MS2_WK_SLOTS(45, 46, 47, 48, 49)
    MS2_WK_SLOTS(50, 51, 52, 53, 54) MS2_WK_SLOTS(55, 56, 57, 58, 59) MS2_WK_SLOTS(60, 61, 62, 63, 64)
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
#undef MS2_WK_SLOTS
    virtual bool vfunc_68(efd::Point3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};

class Unk_PCBaseBody;
void FUN_141240700(Unk_PCBaseBody* pBody, efd::Point3 kVel);               // 0x141240700

// ---- StateWalk ----

// @0x1417ff730
StateWalk::StateWalk(PCBase* pOwner) : State(pOwner)
{
    m_n10 = 0x18;
    m_n4c = 0;
    m_fSpeed1 = 0;
    m_fSpeed2 = 0;
    m_n48 = 0;
    m_n4c = 0;
    m_n50 = 0;
}

// @0x1417ff7d0
StateWalk::~StateWalk()
{
}

// @0x1417ff800
void StateWalk::vfunc_4(StateData* pData)
{
    m_fSpeed1 = m_pOwner->vfunc_96();
    m_fSpeed2 = m_pOwner->vfunc_97();
    if (FUN_1406aeee0()->FUN_1406af100())
    {
        m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
    }
    if (m_pOwner->FUN_141675ed0() != 0)
    {
        m_pOwner->vfunc_59(0x1b, 0, 0, 0);
    }
    else
    {
        Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
        if (m_pOwner->FUN_141676b70() != 0)
            m_n10 = 0x17;
        if (m_n10 == 0x19)
        {
            m_pOwner->FUN_141671960(pSpeed->m_y);
        }
        else if (m_n10 == 0x18)
        {
            if (m_pOwner->GetClassID() == 0x6200045)
            {
                efd::SmartPointer<Ridee> spRidee(FUN_141468360(m_pOwner));
                if (spRidee)
                    m_pOwner->FUN_141671960(spRidee->FUN_1417071d0());
            }
            else
            {
                m_pOwner->FUN_141671960(pSpeed->m_z);
            }
        }
        else if (m_n10 == 0x17)
        {
            if (m_pOwner->GetClassID() == 0x6200045)
            {
                efd::SmartPointer<Ridee> spRidee(FUN_141468360(m_pOwner));
                if (spRidee)
                    m_pOwner->FUN_141671960(spRidee->FUN_1417070a0());
            }
            else
            {
                m_pOwner->FUN_141671960(pSpeed->m_z);
            }
        }
        else if (m_n10 == 0x1a)
        {
            m_pOwner->FUN_141671960(15.0f);
        }
        State::vfunc_4(pData);
    }
}

// @0x1417ffb40
void StateWalk::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_n10 = 0x18;
    Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
    m_pOwner->FUN_141671960(pSpeed->m_z);
}

// @0x1417ffba0
void StateWalk::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
    if (m_n10 == 0x19)
    {
        m_pOwner->FUN_141671960(pSpeed->m_y);
    }
    else if (m_n10 == 0x18)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            efd::SmartPointer<Ridee> spRidee(FUN_141468360(m_pOwner));
            if (spRidee)
                m_pOwner->FUN_141671960(spRidee->FUN_1417071d0());
        }
        else
        {
            m_pOwner->FUN_141671960(pSpeed->m_z);
        }
    }
    else if (m_n10 == 0x17)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            efd::SmartPointer<Ridee> spRidee(FUN_141468360(m_pOwner));
            if (spRidee)
                m_pOwner->FUN_141671960(spRidee->FUN_1417070a0());
        }
        else
        {
            m_pOwner->FUN_141671960(pSpeed->m_z);
        }
    }
    else if (m_n10 == 0x1a)
    {
        m_pOwner->FUN_141671960(15.0f);
    }
    efd::Point3 kDir = m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
    efd::Point3 kVel = kDir * m_pOwner->vfunc_95();
    efd::Point3 kMove = kVel * (float)fTime;
    FUN_141240700(m_pOwner->FUN_14166d220(), kVel);
    reinterpret_cast<Unk_WkOwnerSlots*>(m_pOwner)->vfunc_68(kMove, fTime, 0, 0, 0);
}

// @0x1417fff20
void StateWalk::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (m_pOwner->vfunc_63() == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    Unk_WkBuff* pBuff = (Unk_WkBuff*)m_pOwner->FUN_14166d240();
    efd::Point3 kDir = pBuff->FUN_141683900();
    reinterpret_cast<Unk_WkOwnerSlots*>(m_pOwner)->vfunc_22(kDir);
    if (m_pOwner->FUN_141676b70() != 0)
    {
        m_n10 = 0x17;
    }
    else if (m_n4c != 0)
    {
        m_n10 = 0x1a;
    }
    else if (FUN_140166410()->FUN_14036d570(0xd6))
    {
        int nY = abs(FUN_140a58540()->FUN_140d8c450());
        int nX = abs(FUN_140a58540()->FUN_140d8c4d0());
        int nStick = *FUN_1404eb7e0(&nX, &nY);
        if (nStick > 0)
        {
            int nOld = m_n10;
            if (nStick <= FUN_140a58500(FUN_1409a8b10())->m_n0c)
                m_n10 = 0x19;
            else
                m_n10 = 0x18;
            m_n50 = nOld != m_n10 ? 1 : 0;
        }
        else
        {
            m_n10 = 0x18;
        }
    }
    else
    {
        m_n10 = 0x18;
    }
    if (pPC != 0 && pBuff->FUN_141683100(0x30d41))
    {
        pPC->FUN_1415248d0(1, 0);
        return;
    }
    if (pPC != 0 && pBuff->FUN_141683100(0x30d42))
    {
        pPC->FUN_1415248d0(2, 0);
        return;
    }
    if (m_pOwner->FUN_141671a30() != 0 && (pBuff->FUN_141682fe0(0x493e1) || m_n28 != 0))
    {
        m_n28 = 0;
        m_pOwner->vfunc_59(6, 0, 0x25, 0);
        return;
    }
    if (pBuff->FUN_141682fe0(0x493e5))
    {
        m_pOwner->vfunc_59(3, 0, 0, 0);
        return;
    }
    if (m_pOwner->FUN_141676b70() == 0 && pBuff->FUN_141682fe0(0x493ea) && m_pOwner->FUN_1416749c0())
    {
        m_n48 = 0;
        m_n10 = 0x19;
        m_n50 = 0;
        return;
    }
    if (pBuff->FUN_141683200(0x493ea) && m_pOwner->FUN_1416749c0())
    {
        m_n48 = 1;
        m_n10 = 0x18;
        return;
    }
    if (FUN_1417b9460())
        return;
    if (pPC != 0 && (pBuff->FUN_141682fe0(0x30d41) || FUN_140953f30()->FUN_140ad2220() != 0))
    {
        if (FUN_141659b80(pPC, 1, 0xbadf0a13, 90.0f) != 0)
        {
            if (FUN_1416764d0(pPC) != 0)
            {
                MS2Ptr<RideOffActionTakeLR> spAction(new RideOffActionTakeLR(1));
                spAction->m_n2c = 0xbadf0a13;
                if (pPC->SendRequestRideMode1(spAction) != 0)
                    pPC->vfunc_59(1, 0, 0, 0);
            }
            else
            {
                pPC->FUN_1415248d0(1, 0xbadf0a13);
            }
        }
        return;
    }
    if ((pPC != 0 && pBuff->FUN_141682fe0(0x30d42)) || FUN_140953f30()->FUN_140ad2260() != 0)
    {
        pPC->FUN_1415248d0(2, 0xbadf0a13);
    }
    else if (!m_pOwner->FUN_1416749c0())
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x141800580
void StateWalk::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    int bFalling = m_pOwner->FUN_141675ed0();
    static int s_nDelay = FUN_14028d260(FUN_14096b1c0(3.0f / FUN_14059d930(FUN_141240c40(true))));
    if (bFalling != 0)
    {
        m_pOwner->vfunc_59(0x1b, 0, 0, 0);
        return;
    }
    if (bFalling == 0 && m_pOwner->vfunc_99(s_nDelay) != 0)
    {
        m_pOwner->vfunc_59(5, 0, 0, 0);
        return;
    }
    int nKey = 0x1c;
    bool bForce = false;
    if (m_n10 == 0x19)
        m_n48 = 0;
    if (m_n48 == 0)
        nKey = 0x1d;
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0 && FUN_1416595d0(pPC) != 0)
    {
        if (((Unk_WkCube*)FUN_141659700(pPC))->FUN_1410aa010())
        {
            if (nKey == 0x1c)
                nKey = 0x38;
            else if (nKey == 0x1d)
                nKey = 0x39;
        }
    }
    if (m_n10 == 0x17)
        nKey = 0x1f;
    bool bChanged = !(m_pOwner->vfunc_96() == m_fSpeed1 && m_pOwner->vfunc_97() == m_fSpeed2 && m_n50 == 0);
    unsigned nSeq = FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460());
    if (!m_pOwner->FUN_14166de90(nKey, nSeq) || bChanged)
    {
        Unk_Vec4 kSpeed = *(Unk_Vec4*)m_pOwner->FUN_141671920();
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            efd::SmartPointer<Ridee> spRidee(FUN_141468360(m_pOwner));
            if (spRidee)
                kSpeed.m_z = spRidee->FUN_1417071d0();
        }
        vfunc_10(m_pOwner->vfunc_95(), kSpeed.m_z, kSpeed.m_y, 1.0f, 0);
        m_fSpeed1 = m_pOwner->vfunc_96();
        m_fSpeed2 = m_pOwner->vfunc_97();
        efd::utf8string strAnim(m_pOwner->vfunc_123(nKey));
        m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), bChanged, bForce);
    }
}

// @0x141800a90
int StateWalk::vfunc_15()
{
    if (m_n48 == 0 || m_n10 == 0x19)
        return 0;
    else
    {
        return 1;
    }
}

// @0x141800ac0
void StateWalk::vfunc_10(float a, float b, float c, float d, int e)
{
    m_pOwner->FUN_141670d80(m_pOwner->vfunc_115(a, b, c, d, e, &m_n48));
}

// @0x141800b60
int StateWalk::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    return 1;
}

// @0x141800b90
void StateWalk::vfunc_36(int n)
{
    m_n4c = n;
}

// @0x141800bb0
int StateWalk::vfunc_37()
{
    return m_n4c;
}

// @0x141800ff0
int StateWalk::vfunc_1()
{
    return 2;
}

// @0x141801010
int StateWalk::vfunc_19()
{
    return 0;
}

// @0x141801020
void StateWalk::vfunc_34()
{
    m_n28 = 1;
}

// ---- StateWalkNPC ----

// @0x141800bd0
StateWalkNPC::StateWalkNPC(PCBase* pOwner) : State(pOwner)
{
    m_n10 = 0x18;
}

// @0x141800c20
StateWalkNPC::~StateWalkNPC()
{
}

// @0x141800c50
void StateWalkNPC::vfunc_4(StateData* pData)
{
    m_fSpeed1 = 1.0f;
    m_fSpeed2 = 1.0f;
    m_n10 = 0x18;
    State::vfunc_4(pData);
}

// @0x141800cb0
// MS2-FUNCTIONAL: the exe passes the name string inline (two-slot pointer copy, no EH
// state nop) yet destroys it at scope end; no source form found for that
void StateWalkNPC::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    bool bChanged = !(m_pOwner->vfunc_96() == m_fSpeed1 && m_pOwner->vfunc_97() == m_fSpeed2);
    if (bChanged)
    {
        PCBase* pMount = FUN_1417b8480();
        pMount->vfunc_95();
        m_fSpeed1 = m_pOwner->vfunc_96();
        m_fSpeed2 = m_pOwner->vfunc_97();
        const efd::utf8string& strName = FUN_141b6f910()->FUN_141206030(m_pOwner->FUN_14123c460());
        efd::utf8string strAnim(FUN_1408ac310(strName));
        m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), bChanged, false);
    }
}

// @0x141800ed0
void StateWalkNPC::vfunc_10(float a, float b, float c, float d, int e)
{
    m_pOwner->FUN_141670d80(m_pOwner->vfunc_115(a, b, c, d, e, &m_n48));
}

// @0x141801000
int StateWalkNPC::vfunc_1()
{
    return 2;
}
