// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateSwimDash, the actor state of a player dashing
// through water: steers with the move direction, plays the dash animation and a looping effect. See stateswimdash.h.
// MS2-UNIT: ?\stateswimdash.cpp
// MS2-RANGE: 0x1417fb5c0-0x1417fc010 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateswimdash.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "stateswimdash.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

void FUN_141769440(int n);                                 // 0x141769440 (arg 7: the dash was cancelled)
class Unk_PCBaseBody;
void FUN_141240700(Unk_PCBaseBody* pBody, efd::Point3 kVel);               // 0x141240700
void FUN_1408a8700(void* pStr);                            // 0x1408a8700 efd::utf8string()
void FUN_1408a8900(void* pStr);                            // 0x1408a8900 ~efd::utf8string
void FUN_140ae18f0(void* pStr, const char* psz);           // 0x140ae18f0 efd::utf8string::operator=(const char*)
bool FUN_14096ad40(const efd::utf8string& str);            // 0x14096ad40 the string is empty
void FUN_14165e2a0(PCBase* p, void* pStr, int nKey);       // 0x14165e2a0 the player's animation name of a key
void FUN_14165f170(PCBase* p);                             // 0x14165f170
int FUN_140b7f6a0(void* pSvc, const egf::EntityID& kId);   // 0x140b7f6a0 sequence id of the model
void* FUN_141b6f910();                                     // 0x141b6f910 the animation service
void* FUN_1403ed280();                                     // effect manager
void* FUN_1403ed2d0();                                     // player manager
int FUN_141bd1a10(void* pPlayer, GameObject* pObject);
int FUN_1411a49c0(void* pEffectMgr, Unk_EffectQuery* pQuery);
void FUN_1411a6060(void* pEffectMgr, int nId);

// The efd::utf8string the exe builds out of line (ctor 0x1408a8700, dtor 0x1408a8900; 0x20 bytes).
struct Unk_SwimString
{
    Unk_SwimString() { FUN_1408a8700(m_buf); }
    ~Unk_SwimString() { FUN_1408a8900(m_buf); }
    Unk_SwimString& operator=(const char* psz) { FUN_140ae18f0(m_buf, psz); return *this; }
    operator const efd::utf8string&() const { return *(const efd::utf8string*)m_buf; }
    char m_buf[0x20];
};

// The config constants singleton: the dash speed at +0x56a8.
class Unk_SwimScale { public: float* FUN_140298f40(); };
class Unk_SwimConsts
{
public:
    char m_pad[0x56a8];
    Unk_SwimScale m_scale;
};
Unk_SwimConsts* FUN_1401d3200();

// The actor's buff set: the movement direction and the buff tests.
class Unk_SwimBuff
{
public:
    efd::Point3 FUN_141683900();
    bool FUN_141683100(int nKey);
    bool FUN_141682fe0(int nKey);
};

// The input / skill tables of the dash check.
class Unk_SwimInput { public: bool FUN_14116dcb0(int nSetting, bool bDebugOnly, int nLevel); };
Unk_SwimInput* FUN_14025e7c0();
class Unk_SwimSkillTbl { public: int FUN_14142c0c0(int nSkill); };
Unk_SwimSkillTbl* FUN_1409331f0();

// @0x1417fb5c0
StateSwimDash::StateSwimDash(PCBase* pOwner) : StateMoveSkill(pOwner)
{
    m_nEffect = 0;
    m_n44 = 0x1c;
    m_nFallbackState = 0x1b;
}

// @0x1417fb620
StateSwimDash::~StateSwimDash()
{
    FUN_1417fbe80();
}

// @0x1417fb670
void StateSwimDash::vfunc_4(StateData* pData)
{
    StateMoveSkill::vfunc_4(pData);
    FUN_1417fbec0();
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        FUN_14165f170(pPC);
}

// @0x1417fb6d0
// MS2-FUNCTIONAL: inlined point/array temporaries differ from the exe
void StateSwimDash::vfunc_5(int n)
{
    StateMoveSkill::vfunc_5(n);
    m_pOwner->FUN_141671960(m_pOwner->FUN_141671920()[2]);
    FUN_1417fbe80();
}

// @0x1417fb730
// MS2-FUNCTIONAL: temporaries of the point math are laid out differently from the exe
void StateSwimDash::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (FUN_1417df6a0() == 0)
    {
        FUN_141769440(7);
    }
    else if (m_pOwner->vfunc_63() != 0)
    {
        efd::Point3 kDir = m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
        efd::Point3 kVel = kDir * m_pOwner->vfunc_95();
        efd::Point3 kMove = kVel * (float)fTime;
        m_pOwner->FUN_141671960(*FUN_1401d3200()->m_scale.FUN_140298f40());
        FUN_141240700(m_pOwner->FUN_14166d220(), kVel);
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
    }
}

// @0x1417fb910
// MS2-FUNCTIONAL: call-site temporaries and branch layout differ from the exe
void StateSwimDash::vfunc_8(double fTime)
{
    StateMoveSkill::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0 || m_pOwner->vfunc_63() == 0)
        return;
    if (m_pOwner->FUN_141675ed0() == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    Unk_SwimBuff* pBuff = (Unk_SwimBuff*)m_pOwner->FUN_14166d240();
    efd::Point3 kDir = pBuff->FUN_141683900();
    m_pOwner->vfunc_22(kDir);
    if (pBuff->FUN_141683100(0x30d41))
    {
        pPC->FUN_1415248d0(1, 0);
    }
    else if (pBuff->FUN_141683100(0x30d42))
    {
        pPC->FUN_1415248d0(2, 0);
    }
    else if (m_pOwner->FUN_141671a30() == 0 || !pBuff->FUN_141682fe0(0x493e1))
    {
        if (!m_pOwner->FUN_1416749c0())
            m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_pOwner->vfunc_59(6, 0, 0x25, 0);
    }
}

// @0x1417fbb50
// MS2-FUNCTIONAL: string wrapper and EH frame differ from the exe (unwind slot 0x70 vs 0x50)
void StateSwimDash::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    egf::EntityID kId;
    int nSeq = FUN_140b7f6a0(FUN_141b6f910(), m_pOwner->FUN_14123c460(kId));
    Unk_SwimString strAnim;
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
        FUN_14165e2a0(pPC, &strAnim, 0x32);
    if (FUN_14096ad40(strAnim))
    {
        if (!m_pOwner->FUN_14166de90(0x32, nSeq))
            strAnim = m_pOwner->vfunc_123(0x32);
    }
    bool bPlayed = false;
    if (!FUN_14096ad40(strAnim))
    {
        float* pSpeed = m_pOwner->FUN_141671920();
        vfunc_10(m_pOwner->vfunc_95(), pSpeed[3], pSpeed[1], 1.0f, 0);
        bPlayed = m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), false, false);
    }
    if (bPlayed)
        FUN_1417fbec0();
}

// @0x1417fbd70
// MS2-FUNCTIONAL: frame/local layout differs from the exe
void StateSwimDash::vfunc_10(float a, float b, float c, float d, int e)
{
    int nOut = 0;
    float fSpeed = m_pOwner->vfunc_115(a, b, c, d, e, &nOut);
    m_pOwner->FUN_141670d80(fSpeed);
}

// @0x1417fbe00
int StateSwimDash::vfunc_36()
{
    if (FUN_14025e7c0()->FUN_14116dcb0(0x49401, false, 0))
        return 1;
    if (m_spData.get() != 0)
    {
        return FUN_1409331f0()->FUN_14142c0c0(m_spData->m_nSkill);
    }
    return 0;
}

// @0x1417fbe80
void StateSwimDash::FUN_1417fbe80()
{
    if (m_nEffect != 0)
    {
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417fbec0
// MS2-FUNCTIONAL: CString temporaries differ from the exe
void StateSwimDash::FUN_1417fbec0()
{
    FUN_1417fbe80();
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        Unk_EffectQuery query;
        query.m_strName = static_cast<PC*>(pPC)->FUN_14165e010(0x32);
        query.m_nObject = FUN_141bd1a10(FUN_1403ed2d0(), m_pOwner);
        query.SetActor(pPC->FUN_14123c580());
        m_nEffect = FUN_1411a49c0(FUN_1403ed280(), &query);
    }
}

// @0x1417fbff0
int StateSwimDash::vfunc_14()
{
    return 0;
}

// @0x1417fc000
int StateSwimDash::vfunc_1()
{
    return 0x1c;
}
