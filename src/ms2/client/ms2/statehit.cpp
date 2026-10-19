// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateHit / StateHitNPC, the actor state of an actor that got
// hit: plays the hit animation (a fly-away "Jump_FlyDamg_A" while the hit lifts the actor, else the "Damg_C" / record
// animation) and leaves the state when the hit timer or the animation runs out. See statehit.h.
// MS2-UNIT: ?\statehit.cpp
// MS2-RANGE: 0x1417ca270-0x1417cb9c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statehit.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <efd/Point3.h>
#include <efd/utf8string.h>
#include <egf/EntityID.h>

#include "statehit.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/statefall.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/ms2recover.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

void* FUN_14086d260();                                                  // 0x14086d260 the game clock
double FUN_141473280(void* pClock);                                     // 0x141473280 its current time
bool FUN_14028d470(float a, float b);                                   // 0x14028d470 approx equal
CString FUN_1409a2360(const char* psz, int n);                          // 0x1409a2360 CString from text
bool FUN_14096ad40(const efd::utf8string& str);                         // 0x14096ad40 the string is empty
void FUN_140de91f0(efd::utf8string* pStr);                              // 0x140de91f0 the animation is missing
float FUN_14099eb30(const egf::EntityID& kId, CString strName);         // 0x14099eb30 the animation length in seconds
unsigned int FUN_1409a1a00(NiActorManager* pActor);                     // 0x1409a1a00 the actor's playing sequence id
Unk_FallAnimSvc* FUN_1410a68d0();                                       // 0x1410a68d0 the animation service

// The physics body of the actor: the fly-away lift.
void FUN_141240d70(Unk_PCBaseBody* pBody);                              // 0x141240d70 reset the lift
void FUN_141240cb0(Unk_PCBaseBody* pBody, float fDuration, float fHeight, float fBase);   // 0x141240cb0 start the lift
int FUN_141240db0(Unk_PCBaseBody* pBody);                               // 0x141240db0 the lift is set
int FUN_141240dd0(Unk_PCBaseBody* pBody);                               // 0x141240dd0 the lift is running

// The actor's buffs (PCBase::FUN_14166d240).
class Unk_HitBuff
{
public:
    efd::Point3 FUN_1416836d0();                                        // 0x1416836d0 the knock-back direction (variant 1)
    efd::Point3 FUN_141683290();                                        // 0x141683290 the knock-back direction (variant 2)
    char FUN_141683100(int nBuff);                                      // 0x141683100 the actor has the buff
};

// @0x1417ca270
StateHit::StateHit(PCBase* pOwner) : State(pOwner)
{
    FUN_1417cb1d0();
}

// @0x1417ca300
StateHit::~StateHit()
{
}

// @0x1417ca370
// MS2-FUNCTIONAL: first-pass source, temporaries / frame layout not yet compared
void StateHit::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    FUN_1417cb1d0();
    float fSpeed = 1.0f;
    StateHitData* pHit = dynamic_cast<StateHitData*>(pData);
    if (pHit)
    {
        fSpeed = pHit->m_f18;
        m_f9c = pHit->m_f1c;
        m_fA4 = pHit->m_f24;
        m_fA8 = pHit->m_f20;
        double dDuration = m_fA4;
        m_fA0 = (float)(dDuration + FUN_141473280(FUN_14086d260()));
        m_fB0 = pHit->m_f28;
        m_nB4 = pHit->m_n2c;
        m_fAc = m_pOwner->vfunc_18().z;
        m_nB8 = 0;
        m_nBc = pHit->m_n30;
        m_strC0 = pHit->m_str;
    }
    m_timer.FUN_1408687f0();
    if (!FUN_14028d470(m_fB0, 0))
    {
        m_strAnim = (const char*)FUN_1409a2360("Jump_FlyDamg_A", 0);
        Unk_PCBaseBody* pBody = m_pOwner->FUN_14166d220();
        FUN_141240d70(pBody);
        FUN_141240cb0(pBody, m_fA4, m_fB0, m_fAc);
    }
    else
    {
        m_strAnim = m_pOwner->vfunc_123(0x35);
    }
    if (!m_strC0.IsEmpty())
    {
        efd::utf8string kName((const char*)FUN_1409a2360((const char*)m_strC0, 0));
        if (m_pOwner->FUN_141679220(kName.c_str()))
            m_strAnim = kName;
    }
    if (!m_pOwner->FUN_141679220(m_strAnim.c_str()))
    {
        FUN_140de91f0(&m_strAnim);
    }
    else
    {
        m_pOwner->FUN_14166dd20(m_strAnim, fSpeed, true, false);
        float fLength = FUN_14099eb30(m_pOwner->FUN_14123c460(), CString(m_strAnim.c_str()));
        m_timer.FUN_140868750((int)(fLength * 1000.0 * 0.7));
    }
    m_bC8 = false;
}

// @0x1417ca8a0
// MS2-FUNCTIONAL: first-pass source, temporaries / frame layout not yet compared
void StateHit::vfunc_3(double fTime)
{
    efd::Point3 kDir = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kDir, fTime, 0, 0, 0);
    if (0.0f < m_fEndTime)
    {
        if ((double)m_fEndTime <= FUN_141473280(FUN_14086d260()))
        {
            if (m_nB4 == 0)
            {
                m_pOwner->vfunc_59(1, 0, 0, 0);
            }
            else
            {
                efd::utf8string kName("Damg_C");
                m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
            }
        }
    }
}

// @0x1417caa10
void StateHit::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (m_pOwner != 0)
    {
        Unk_PCBaseBody* pBody = m_pOwner->FUN_14166d220();
        if (pBody != 0)
            FUN_141240d70(pBody);
    }
    m_bC8 = true;
}

// @0x1417caa80
void StateHit::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (FUN_14096ad40(m_strAnim))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417caaf0
// MS2-FUNCTIONAL: first-pass source, temporaries / frame layout not yet compared
void StateHit::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (eSequenceID != FUN_1409a1a00(pkManager))
        return;
    Unk_FallAnimSvc* pSvc = FUN_1410a68d0();
    int nDamg = pSvc->FUN_140999490(m_pOwner->FUN_14123c460(), efd::utf8string("Damg_C"));
    int nFly = pSvc->FUN_140999490(m_pOwner->FUN_14123c460(), efd::utf8string("Jump_FlyDamg_A"));
    if ((!FUN_14028d470(m_fA4, 0) || !FUN_14028d470(m_f9c, 0)) && (int)eSequenceID != nDamg)
    {
        if (nFly == (int)eSequenceID)
        {
            efd::utf8string kName("Jump_FlyDamg_A");
            m_pOwner->FUN_14166dd20(kName, 1.0f, true, false);
        }
        m_fEndTime = m_fA0 + m_f9c;
        return;
    }
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417cad10
// MS2-FUNCTIONAL: first-pass source, temporaries / frame layout not yet compared
void StateHit::vfunc_8(double fTime)
{
    Unk_PCBaseBody* pBody = m_pOwner->FUN_14166d220();
    if (pBody != 0 && FUN_141240db0(pBody) != 0 && FUN_141240dd0(pBody) == 0)
        return;
    State::vfunc_8(fTime);
    static int s_nSkill = *Client::Constants::GetInstance()->EscapeHitMethodSkill.Get();
    static int s_nJump = *Client::Constants::GetInstance()->EscapeHitMethodJump.Get();
    static int s_nMove = *Client::Constants::GetInstance()->EscapeHitMethodMove.Get();
    static int s_nKeyIsDown = *Client::Constants::GetInstance()->EscapeHitMoveKeyIsDown.Get();
    if (m_pOwner->vfunc_63() == 0)
        return;
    Unk_HitBuff* pBuff = (Unk_HitBuff*)m_pOwner->FUN_14166d240();
    if (s_nKeyIsDown == 0)
    {
        efd::Point3 kDir = pBuff->FUN_1416836d0();
        m_pOwner->vfunc_22(kDir);
    }
    else
    {
        efd::Point3 kDir = pBuff->FUN_141683290();
        m_pOwner->vfunc_22(kDir);
    }
    if (s_nMove == 0 || !m_pOwner->FUN_1416749c0())
    {
        if (s_nJump == 0 || m_pOwner->vfunc_99(0) != 0 || !pBuff->FUN_141683100(0x493e1))
        {
            if (s_nSkill != 0)
                FUN_1417b9460();
        }
        else
        {
            m_pOwner->vfunc_59(6, 0, 0, 0);
        }
    }
    else
    {
        m_pOwner->vfunc_59(2, 0, 0, 0);
    }
    efd::Point3 kZero = efd::Point3::ZERO;
    m_pOwner->vfunc_22(kZero);
}

// @0x1417cb120
bool StateHit::vfunc_36()
{
    return m_timer.FUN_140868ba0() == 0;
}

// @0x1417cb160
bool StateHit::FUN_1417cb160()
{
    float fNow = (float)FUN_141473280(FUN_14086d260());
    if (fNow < m_fA0 && !FUN_14028d470(m_fB0, 0))
        return false;
    return true;
}

// @0x1417cb1d0
void StateHit::FUN_1417cb1d0()
{
    m_fEndTime = 0;
    m_f9c = 0;
    m_fA0 = 0;
    m_fA4 = 0;
    m_fAc = 0;
    m_fB0 = 0;
    m_nB4 = 0;
    m_nB8 = 0;
    m_fA8 = 0;
    m_nBc = 0;
    m_strC0.Empty();
}

// @0x1417cb2a0
bool StateHit::FUN_1417cb2a0()
{
    return !FUN_14028d470(m_fA4, 0);
}

// @0x1417cb2f0
int StateHit::FUN_1417cb2f0()
{
    return m_nBc;
}

// @0x1417cb310
StateHitNPC::StateHitNPC(PCBase* pOwner) : State(pOwner)
{
    FUN_1417cb730();
}

// @0x1417cb370
StateHitNPC::~StateHitNPC()
{
}

// @0x1417cb3a0
// MS2-FUNCTIONAL: first-pass source, temporaries / frame layout not yet compared
void StateHitNPC::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    FUN_1417cb730();
    StateHitData* pHit = dynamic_cast<StateHitData*>(pData);
    if (pHit)
    {
        m_f44 = pHit->m_f1c;
        m_f58 = pHit->m_f28;
        m_n5c = pHit->m_n2c;
        m_f50 = pHit->m_f24;
        m_f4c = m_f50 + (float)FUN_141473280(FUN_14086d260());
        m_f54 = m_pOwner->vfunc_18().z;
        m_n40 = pHit->m_n30;
    }
}

// @0x1417cb4c0
// MS2-FUNCTIONAL: first-pass source, temporaries / frame layout not yet compared
void StateHitNPC::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    FUN_1417cb7b0();
    if (0.0f < m_fEndTime)
    {
        if ((double)m_fEndTime <= FUN_141473280(FUN_14086d260()))
        {
            if (m_n5c == 0)
            {
                m_pOwner->vfunc_59(1, 0, 0, 0);
            }
            else
            {
                efd::utf8string kName("Damg_C");
                m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
            }
        }
    }
}

// @0x1417cb5d0
// MS2-FUNCTIONAL: first-pass source, temporaries / frame layout not yet compared
void StateHitNPC::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (eSequenceID != FUN_1409a1a00(pkManager))
        return;
    Unk_FallAnimSvc* pSvc = FUN_1410a68d0();
    int nDamg = pSvc->FUN_140999490(m_pOwner->FUN_14123c460(), efd::utf8string("Damg_C"));
    if ((!FUN_14028d470(m_f4c, 0) || !FUN_14028d470(m_f44, 0)) && (int)eSequenceID != nDamg)
    {
        m_fEndTime = m_f4c + m_f44;
        return;
    }
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417cb730
void StateHitNPC::FUN_1417cb730()
{
    m_f44 = 0;
    m_fEndTime = 0;
    m_f4c = 0;
    m_f50 = 0;
    m_f54 = 0;
    m_f58 = 0;
    m_n5c = 0;
    m_n40 = 0;
}

// @0x1417cb7b0
// MS2-FUNCTIONAL: first-pass source, temporaries / frame layout not yet compared
void StateHitNPC::FUN_1417cb7b0()
{
    float fNow = (float)FUN_141473280(FUN_14086d260());
    float fZ = m_f54;
    if (fNow < m_f4c)
    {
        float f = 1.0f - (m_f4c - fNow) / m_f50;
        fZ = fZ - m_f58 * 4.0f * f * (f - 1.0f);
    }
    efd::Point3 kPos = m_pOwner->vfunc_18();
    kPos.z = fZ;
    m_pOwner->vfunc_19(kPos);
}

// ---- inline virtuals ----

int StateHit::vfunc_15() { return 1; }                                  // @0x1417cb950
int StateHit::vfunc_1() { return 0xd; }                                 // @0x1417cb960
int StateHitNPC::vfunc_1() { return 0xd; }                              // @0x1417cb970
bool StateHit::vfunc_32() { return m_bC8; }                             // @0x1417cb980
void StateHit::vfunc_33(bool b) { m_bC8 = b; }                          // @0x1417cb9a0
