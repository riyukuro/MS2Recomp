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
#include "ms2/placeholder/cinputkeyhandler.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

void FUN_141769440(int n);                                 // 0x141769440 (arg 7: the dash was cancelled)
class Unk_PCBaseBody;
void FUN_141240700(Unk_PCBaseBody* pBody, efd::Point3 kVel);               // 0x141240700
bool FUN_14096ad40(const efd::utf8string& str);            // 0x14096ad40 the string is empty
void FUN_14165e2a0(PCBase* p, efd::utf8string* pStr, int nKey);       // 0x14165e2a0 the player's animation name of a key
void FUN_14165f170(PCBase* p);                             // 0x14165f170
int FUN_140b7f6a0(void* pSvc, const egf::EntityID& kId);   // 0x140b7f6a0 sequence id of the model
void* FUN_141b6f910();                                     // 0x141b6f910 the animation service
void* FUN_1403ed280();                                     // effect manager
void* FUN_1403ed2d0();                                     // player manager
int FUN_141bd1a10(void* pPlayer, GameObject* pObject);
int FUN_1411a49c0(void* pEffectMgr, Unk_EffectQuery* pQuery);
void FUN_1411a6060(void* pEffectMgr, int nId);

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
CInputKeyHandler* FUN_14025e7c0();
class Unk_SwimSkillTbl { public: int FUN_14142c0c0(int nSkill); };
Unk_SwimSkillTbl* FUN_1409331f0();

// The owner's vtable up to slot 68: slots 22 and 68 take their point by value (the exe passes a pointer to a copy).
class Unk_SdOwnerSlots
{
public:
#define MS2_SD_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_SD_SLOTS(0, 1, 2, 3, 4) MS2_SD_SLOTS(5, 6, 7, 8, 9) MS2_SD_SLOTS(10, 11, 12, 13, 14) MS2_SD_SLOTS(15, 16, 17, 18, 19)
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kDir);                                        // 22 takes the direction by value
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_SD_SLOTS(25, 26, 27, 28, 29) MS2_SD_SLOTS(30, 31, 32, 33, 34)
    MS2_SD_SLOTS(35, 36, 37, 38, 39) MS2_SD_SLOTS(40, 41, 42, 43, 44) MS2_SD_SLOTS(45, 46, 47, 48, 49)
    MS2_SD_SLOTS(50, 51, 52, 53, 54) MS2_SD_SLOTS(55, 56, 57, 58, 59) MS2_SD_SLOTS(60, 61, 62, 63, 64)
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
#undef MS2_SD_SLOTS
    virtual bool vfunc_68(efd::Point3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};

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
void StateSwimDash::vfunc_5(int n)
{
    StateMoveSkill::vfunc_5(n);
    Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
    m_pOwner->FUN_141671960(pSpeed->m_z);
    FUN_1417fbe80();
}

// @0x1417fb730
void StateSwimDash::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (FUN_1417df6a0() == 0)
    {
        FUN_141769440(7);
        return;
    }
    if (m_pOwner->vfunc_63() == 0)
        return;
    efd::Point3 kDir = m_pOwner->FUN_141674b60(static_cast<const efd::Point3&>(m_pOwner->FUN_14123c360()));
    efd::Point3 kVel = kDir * m_pOwner->vfunc_95();
    efd::Point3 kMove = kVel * (float)fTime;
    m_pOwner->FUN_141671960(*FUN_1401d3200()->m_scale.FUN_140298f40());
    FUN_141240700(m_pOwner->FUN_14166d220(), kVel);
    reinterpret_cast<Unk_SdOwnerSlots*>(m_pOwner)->vfunc_68(kMove, fTime, 0, 0, 0);
}

// @0x1417fb910
void StateSwimDash::vfunc_8(double fTime)
{
    StateMoveSkill::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    if (m_pOwner->vfunc_63() == 0)
        return;
    if (m_pOwner->FUN_141675ed0() != 0)
    {
        Unk_SwimBuff* pBuff = (Unk_SwimBuff*)m_pOwner->FUN_14166d240();
        efd::Point3 kDir = pBuff->FUN_141683900();
        reinterpret_cast<Unk_SdOwnerSlots*>(m_pOwner)->vfunc_22(kDir);
        if (pBuff->FUN_141683100(0x30d41))
        {
            pPC->FUN_1415248d0(1, 0);
        }
        else if (pBuff->FUN_141683100(0x30d42))
        {
            pPC->FUN_1415248d0(2, 0);
        }
        else if (m_pOwner->FUN_141671a30() != 0 && pBuff->FUN_141682fe0(0x493e1))
        {
            m_pOwner->vfunc_59(6, 0, 0x25, 0);
        }
        else if (!m_pOwner->FUN_1416749c0())
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
        }
    }
    else
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x1417fbb50
void StateSwimDash::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    int nSeq = FUN_140b7f6a0(FUN_141b6f910(), m_pOwner->FUN_14123c460());
    efd::utf8string strAnim;
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
        Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
        vfunc_10(m_pOwner->vfunc_95(), pSpeed->m_w, pSpeed->m_y, 1.0f, 0);
        bPlayed = m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), false, false);
    }
    if (bPlayed)
        FUN_1417fbec0();
}

// @0x1417fbd70
void StateSwimDash::vfunc_10(float a, float b, float c, float d, int e)
{
    int nOut = 0;
    m_pOwner->FUN_141670d80(m_pOwner->vfunc_115(a, b, c, d, e, &nOut));
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
