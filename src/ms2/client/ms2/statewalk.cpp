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

void FUN_1409989e0(void* pOut, const char* psz);           // 0x1409989e0 efd::utf8string(const char*)
void FUN_1408a8900(void* pStr);                            // 0x1408a8900 ~efd::utf8string
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

// The efd::utf8string the exe builds out of line (ctor 0x1409989e0, dtor 0x1408a8900; 0x20 bytes).
struct Unk_WkString
{
    Unk_WkString(const char* psz) { FUN_1409989e0(m_buf, psz); }
    ~Unk_WkString() { FUN_1408a8900(m_buf); }
    operator const efd::utf8string&() const { return *(const efd::utf8string*)m_buf; }
    char m_buf[0x20];
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
// MS2-FUNCTIONAL: the exe holds the ridee in a CComPtr (temp + EH frame); a raw pointer is used here
void StateWalk::vfunc_4(StateData* pData)
{
    m_fSpeed1 = m_pOwner->vfunc_96();
    m_fSpeed2 = m_pOwner->vfunc_97();
    if (FUN_1406aeee0()->FUN_1406af100())
    {
        efd::Point3 kDir = m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
    }
    if (m_pOwner->FUN_141675ed0() == 0)
    {
        float* pSpeed = m_pOwner->FUN_141671920();
        if (m_pOwner->FUN_141676b70() != 0)
            m_n10 = 0x17;
        if (m_n10 == 0x19)
        {
            m_pOwner->FUN_141671960(pSpeed[1]);
        }
        else if (m_n10 == 0x18)
        {
            if (m_pOwner->GetClassID() == 0x6200045)
            {
                Ridee* pRidee = FUN_141468360(m_pOwner);
                if (pRidee != 0)
                    m_pOwner->FUN_141671960(pRidee->FUN_1417071d0());
            }
            else
            {
                m_pOwner->FUN_141671960(pSpeed[2]);
            }
        }
        else if (m_n10 == 0x17)
        {
            if (m_pOwner->GetClassID() == 0x6200045)
            {
                Ridee* pRidee = FUN_141468360(m_pOwner);
                if (pRidee != 0)
                    m_pOwner->FUN_141671960(pRidee->FUN_1417070a0());
            }
            else
            {
                m_pOwner->FUN_141671960(pSpeed[2]);
            }
        }
        else if (m_n10 == 0x1a)
        {
            m_pOwner->FUN_141671960(15.0f);
        }
        State::vfunc_4(pData);
    }
    else
    {
        m_pOwner->vfunc_59(0x1b, 0, 0, 0);
    }
}

// @0x1417ffb40
// MS2-FUNCTIONAL: inlined array temporaries differ from the exe
void StateWalk::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_n10 = 0x18;
    m_pOwner->FUN_141671960(m_pOwner->FUN_141671920()[2]);
}

// @0x1417ffba0
// MS2-FUNCTIONAL: the exe holds the ridee in a CComPtr and lays out the point temporaries differently
void StateWalk::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    float* pSpeed = m_pOwner->FUN_141671920();
    if (m_n10 == 0x19)
    {
        m_pOwner->FUN_141671960(pSpeed[1]);
    }
    else if (m_n10 == 0x18)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            Ridee* pRidee = FUN_141468360(m_pOwner);
            if (pRidee != 0)
                m_pOwner->FUN_141671960(pRidee->FUN_1417071d0());
        }
        else
        {
            m_pOwner->FUN_141671960(pSpeed[2]);
        }
    }
    else if (m_n10 == 0x17)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            Ridee* pRidee = FUN_141468360(m_pOwner);
            if (pRidee != 0)
                m_pOwner->FUN_141671960(pRidee->FUN_1417070a0());
        }
        else
        {
            m_pOwner->FUN_141671960(pSpeed[2]);
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
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417fff20
// MS2-FUNCTIONAL: call-site temporaries and branch layout differ from the exe
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
    m_pOwner->vfunc_22(kDir);
    if (m_pOwner->FUN_141676b70() == 0)
    {
        if (m_n4c == 0)
        {
            if (!FUN_140166410()->FUN_14036d570(0xd6))
            {
                m_n10 = 0x18;
            }
            else
            {
                int nY = FUN_140a58540()->FUN_140d8c450();
                nY = nY < 0 ? -nY : nY;
                int nX = FUN_140a58540()->FUN_140d8c4d0();
                nX = nX < 0 ? -nX : nX;
                int nStick = *FUN_1404eb7e0(&nX, &nY);
                if (nStick < 1)
                {
                    m_n10 = 0x18;
                }
                else
                {
                    int nOld = m_n10;
                    if (FUN_140a58500(FUN_1409a8b10())->m_n0c < nStick)
                        m_n10 = 0x18;
                    else
                        m_n10 = 0x19;
                    m_n50 = nOld != m_n10;
                }
            }
        }
        else
        {
            m_n10 = 0x1a;
        }
    }
    else
    {
        m_n10 = 0x17;
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
            if (FUN_1416764d0(pPC) == 0)
            {
                pPC->FUN_1415248d0(1, 0xbadf0a13);
            }
            else
            {
                MS2Ptr<RideOffActionTakeLR> spAction(new RideOffActionTakeLR(1));
                spAction->m_n2c = 0xbadf0a13;
                if (pPC->SendRequestRideMode1(spAction) != 0)
                    pPC->vfunc_59(1, 0, 0, 0);
            }
        }
        return;
    }
    if (pPC == 0 || !pBuff->FUN_141682fe0(0x30d42))
    {
        if (FUN_140953f30()->FUN_140ad2260() == 0)
        {
            if (m_pOwner->FUN_1416749c0())
                return;
            m_pOwner->vfunc_59(1, 0, 0, 0);
            return;
        }
    }
    pPC->FUN_1415248d0(2, 0xbadf0a13);
}

// @0x141800580
// MS2-FUNCTIONAL: string wrapper, CComPtr temp and EH frame differ from the exe
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
    if (m_pOwner->vfunc_99(s_nDelay) != 0)
    {
        m_pOwner->vfunc_59(5, 0, 0, 0);
        return;
    }
    int nKey = 0x1c;
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
    bool bChanged;
    if (m_pOwner->vfunc_96() == m_fSpeed1 && m_pOwner->vfunc_97() == m_fSpeed2 && m_n50 == 0)
        bChanged = false;
    else
        bChanged = true;
    egf::EntityID kId;
    unsigned nSeq = FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460(kId));
    if (!m_pOwner->FUN_14166de90(nKey, nSeq) || bChanged)
    {
        float aSpeed[4];
        memcpy(aSpeed, m_pOwner->FUN_141671920(), sizeof(aSpeed));
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            Ridee* pRidee = FUN_141468360(m_pOwner);
            if (pRidee != 0)
                aSpeed[2] = pRidee->FUN_1417071d0();
        }
        vfunc_10(m_pOwner->vfunc_95(), aSpeed[2], aSpeed[1], 1.0f, 0);
        m_fSpeed1 = m_pOwner->vfunc_96();
        m_fSpeed2 = m_pOwner->vfunc_97();
        Unk_WkString strAnim(m_pOwner->vfunc_123(nKey));
        m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), bChanged, false);
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
// MS2-FUNCTIONAL: frame/local layout differs from the exe
void StateWalk::vfunc_10(float a, float b, float c, float d, int e)
{
    float fSpeed = m_pOwner->vfunc_115(a, b, c, d, e, &m_n48);
    m_pOwner->FUN_141670d80(fSpeed);
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
// MS2-FUNCTIONAL: string temporaries and the EH frame differ from the exe
void StateWalkNPC::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    bool bChanged;
    if (m_pOwner->vfunc_96() == m_fSpeed1 && m_pOwner->vfunc_97() == m_fSpeed2)
        bChanged = false;
    else
        bChanged = true;
    if (bChanged)
    {
        PCBase* pMount = FUN_1417b8480();
        pMount->vfunc_95();
        m_fSpeed1 = m_pOwner->vfunc_96();
        m_fSpeed2 = m_pOwner->vfunc_97();
        egf::EntityID kId;
        efd::utf8string strName = FUN_141b6f910()->FUN_141206030(m_pOwner->FUN_14123c460(kId));
        Unk_WkString strAnim(FUN_1408ac310(strName));
        m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), bChanged, false);
    }
}

// @0x141800ed0
// MS2-FUNCTIONAL: frame/local layout differs from the exe
void StateWalkNPC::vfunc_10(float a, float b, float c, float d, int e)
{
    float fSpeed = m_pOwner->vfunc_115(a, b, c, d, e, &m_n48);
    m_pOwner->FUN_141670d80(fSpeed);
}

// @0x141801000
int StateWalkNPC::vfunc_1()
{
    return 2;
}
