// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateSwim, the actor state of a player swimming: picks the
// swim speed (own or the ridee's), steers in the move direction, plays the swim animation and a looping effect.
// See stateswim.h.
// MS2-UNIT: ?\stateswim.cpp
// MS2-RANGE: 0x1417fa370-0x1417fb5c0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateswim.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>
#include <efd/SmartPointer.h>

#include "stateswim.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/gameobjectcontroller.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

int FUN_140b7f6a0(void* pSvc, const egf::EntityID& kId);   // 0x140b7f6a0 sequence id of the model
void* FUN_141b6f910();                                     // 0x141b6f910 the animation service
void* FUN_1403ed280();                                     // effect manager
void* FUN_1403ed2d0();                                     // player manager
int FUN_141bd1a10(void* pPlayer, GameObject* pObject);
class Unk_PCBaseBody;

// The owner's vtable up to slot 68, which takes the move by value (the exe passes a pointer to a copy).
class Unk_SwOwnerSlots
{
public:
#define MS2_SW_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_SW_SLOTS(0, 1, 2, 3, 4) MS2_SW_SLOTS(5, 6, 7, 8, 9) MS2_SW_SLOTS(10, 11, 12, 13, 14) MS2_SW_SLOTS(15, 16, 17, 18, 19)
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kDir);                                        // 22 takes the direction by value
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_SW_SLOTS(25, 26, 27, 28, 29) MS2_SW_SLOTS(30, 31, 32, 33, 34)
    MS2_SW_SLOTS(35, 36, 37, 38, 39) MS2_SW_SLOTS(40, 41, 42, 43, 44) MS2_SW_SLOTS(45, 46, 47, 48, 49)
    MS2_SW_SLOTS(50, 51, 52, 53, 54) MS2_SW_SLOTS(55, 56, 57, 58, 59) MS2_SW_SLOTS(60, 61, 62, 63, 64)
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
#undef MS2_SW_SLOTS
    virtual bool vfunc_68(efd::Point3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};
class Unk_SwimHitReport { public: void FUN_140cfaf30(); };   // the actor body's controller hit report

class Unk_SwimApp;
bool FUN_1415337c0(int nLast, int nNow, int nMillis);      // 0x1415337c0 enough time passed since the last request
Ridee* FUN_141468360(PCBase* p);                           // 0x141468360 the ridee the actor sits on

// The config constants singleton: the swim speed at +0x56a8 is not read here; only the buff view below is.
class Unk_SwimBuff
{
public:
    efd::Point3 FUN_141683900();
    bool FUN_141683100(int nKey);
    bool FUN_141682fe0(int nKey);
};

// The item a state is told about in its slots 29/30.
class Unk_StateArg29 : public CItem { };

// @0x1417fa370
StateSwim::StateSwim(PCBase* pOwner) : State(pOwner)
{
    m_nEffect = 0;
    m_nMode = 0;
}

// @0x1417fa3d0
StateSwim::~StateSwim()
{
    FUN_1417fb400();
}

// @0x1417fa420
void StateSwim::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_nMode = reinterpret_cast<CMainSystem*>(reinterpret_cast<Unk_SwimApp*>(TSingleton<CMainSystem>::GetInstance()))->FUN_141473390();
    FUN_1417fb440();
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        reinterpret_cast<PC*>(pPC)->SendRequestCube();
    if (m_pOwner->GetClassID() == 0x6200045)
        PCBase::FUN_141677f40(m_pOwner);
    Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
    if (FUN_1417fb370() != 0)
    {
        if (m_pOwner->FUN_141676b70() != 0)
        {
            m_n10 = 0x85;
            if (m_pOwner->GetClassID() == 0x6200045)
            {
                efd::SmartPointer<Ridee> spRidee(FUN_141468360(m_pOwner));
                if (spRidee)
                    m_pOwner->FUN_141671960(spRidee->FUN_1417070a0());
                else
                    m_pOwner->FUN_141671960(pSpeed->m_w);
            }
            else
            {
                m_pOwner->FUN_141671960(pSpeed->m_w);
            }
        }
        else
        {
            m_n10 = 0x84;
            m_pOwner->FUN_141671960(pSpeed->m_z);
        }
    }
    else
    {
        m_n10 = 0x84;
        m_pOwner->FUN_141671960(pSpeed->m_w);
    }
}

// @0x1417fa600
void StateSwim::vfunc_5(int n)
{
    State::vfunc_5(n);
    Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
    m_pOwner->FUN_141671960(pSpeed->m_z);
    FUN_1417fb400();
}

// @0x1417fa660
void StateSwim::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
    if (m_n10 == 0x84)
    {
        if (FUN_1417fb370() != 0)
            m_pOwner->FUN_141671960(pSpeed->m_z);
        else
            m_pOwner->FUN_141671960(pSpeed->m_w);
    }
    else if (m_n10 == 0x85)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            efd::SmartPointer<Ridee> spRidee(FUN_141468360(m_pOwner));
            if (spRidee)
                m_pOwner->FUN_141671960(spRidee->FUN_1417070a0());
            else
                m_pOwner->FUN_141671960(pSpeed->m_w);
        }
        else
        {
            m_pOwner->FUN_141671960(pSpeed->m_w);
        }
    }
    efd::Point3 kDir = m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
    efd::Point3 kVel = kDir * m_pOwner->vfunc_95();
    efd::Point3 kMove = kVel * (float)fTime;
    reinterpret_cast<GameObjectController*>(m_pOwner->FUN_14166d220())->SetKVelocity(kVel);
    reinterpret_cast<Unk_SwOwnerSlots*>(m_pOwner)->vfunc_68(kMove, fTime, 0, 0, 0);
}

// @0x1417fa950
void StateSwim::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    if (m_pOwner->vfunc_63() == 0)
        return;
    if (m_pOwner->FUN_141675ed0() != 0)
    {
        if (!FUN_1417b9460())
        {
            if (m_pOwner->vfunc_99(0) != 0)
            {
                ((Unk_SwimHitReport*)(reinterpret_cast<GameObjectController*>(m_pOwner->FUN_14166d220())->FUN_141240f20()))->FUN_140cfaf30();
                m_pOwner->vfunc_59(1, 0, 0, 0);
                return;
            }
            Unk_SwimBuff* pBuff = (Unk_SwimBuff*)m_pOwner->FUN_14166d240();
            efd::Point3 kDir = pBuff->FUN_141683900();
            reinterpret_cast<Unk_SwOwnerSlots*>(m_pOwner)->vfunc_22(kDir);
            if (m_pOwner->FUN_141676b70() != 0 && FUN_1417fb370() != 0)
                m_n10 = 0x85;
            else
                m_n10 = 0x84;
            if (pBuff->FUN_141683100(0x30d41))
            {
                pPC->FUN_1415248d0(1, 0);
            }
            else if (pBuff->FUN_141683100(0x30d42))
            {
                pPC->FUN_1415248d0(2, 0);
            }
            else if (m_pOwner->FUN_141671a30() != 0 && (pBuff->FUN_141682fe0(0x493e1) || m_n28 != 0))
            {
                m_n28 = 0;
                m_pOwner->vfunc_59(6, 0, 0x25, 0);
            }
            else if (!m_pOwner->FUN_1416749c0())
            {
                m_pOwner->vfunc_59(1, 0, 0, 0);
            }
        }
    }
    else
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x1417fac90
void StateSwim::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    int nSeq = FUN_140b7f6a0(FUN_141b6f910(), m_pOwner->FUN_14123c460());
    if (FUN_1417fb370() != 0)
    {
        int nKey = (m_n10 == 0x85) ? 0x1f : 0x1c;
        if (!m_pOwner->FUN_14166de90(nKey, nSeq))
        {
            Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
            vfunc_10(m_pOwner->vfunc_95(), pSpeed->m_z, pSpeed->m_y, 1.0f, 0);
            m_pOwner->FUN_14166dda0(nKey);
        }
    }
    else
    {
        efd::utf8string strAnim;
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0)
            reinterpret_cast<PC*>(pPC)->FUN_14165e2a0(*reinterpret_cast<efd::utf8string*>(static_cast<void*>(&strAnim)), 0x31);
        if (strAnim.empty())
        {
            if (!m_pOwner->FUN_14166de90(0x31, nSeq))
                strAnim = m_pOwner->vfunc_123(0x31);
        }
        bool bPlayed = false;
        if (!strAnim.empty())
        {
            Unk_Vec4* pSpeed = (Unk_Vec4*)m_pOwner->FUN_141671920();
            vfunc_10(m_pOwner->vfunc_95(), pSpeed->m_w, pSpeed->m_y, 1.0f, 0);
            bPlayed = m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), false, false);
        }
        if (bPlayed)
            FUN_1417fb440();
    }
}

// @0x1417fafb0
void StateSwim::vfunc_10(float a, float b, float c, float d, int e)
{
    int nOut = 0;
    m_pOwner->FUN_141670d80(m_pOwner->vfunc_115(a, b, c, d, e, &nOut));
}

// @0x1417fb040
int StateSwim::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
        return 0;
    MyPC* pPC = FUN_1417b84b0();
    int nNow = reinterpret_cast<CMainSystem*>(reinterpret_cast<Unk_SwimApp*>(TSingleton<CMainSystem>::GetInstance()))->FUN_141473390();
    if (pPC != 0 && reinterpret_cast<PCBase*>(pPC)->FUN_1416764d0() != 0 && FUN_1415337c0(m_nMode, nNow, 1000))
    {
        m_nMode = nNow;
        return 1;
    }
    if (m_n10 == p->m_nSub)
        return 0;
    m_nMode = nNow;
    return 1;
}

// @0x1417fb160
void StateSwim::vfunc_29(MS2Ptr<Unk_StateArg29> p)
{
    State::vfunc_29(p);
    MS2Ptr<CItemGem> spGem(p->FUN_140527900());
    if ((spGem ? true : false) && (spGem->GetGem().get() ? true : false))
    {
        MS2Ptr<CGemSwim> spSwim(dynamic_cast<CGemSwim*>(spGem->GetGem().operator->()));
        if (spSwim.get() != 0)
            FUN_1417fb440();
    }
}

// @0x1417fb370
int StateSwim::FUN_1417fb370()
{
    efd::SmartPointer<Ridee> spRidee(FUN_141468360(m_pOwner));
    if (!spRidee)
        return 0;
    return spRidee->FUN_1417075e0();
}

// @0x1417fb400
void StateSwim::FUN_1417fb400()
{
    if (m_nEffect != 0)
    {
        reinterpret_cast<CEffectService*>(FUN_1403ed280())->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417fb440
void StateSwim::FUN_1417fb440()
{
    FUN_1417fb400();
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        Unk_EffectQuery query;
        query.m_strName = static_cast<PC*>(pPC)->FUN_14165e010(0x31);
        query.m_nObject = FUN_141bd1a10(FUN_1403ed2d0(), m_pOwner);
        query.SetActor(pPC->FUN_14123c580());
        m_nEffect = reinterpret_cast<CEffectService*>(FUN_1403ed280())->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(static_cast<NoticeMessage*>(&query)));
    }
}

// @0x1417fb570
int StateSwim::vfunc_14()
{
    return 0;
}

// @0x1417fb580
int StateSwim::vfunc_1()
{
    return 0x1b;
}

// @0x1417fb590
int StateSwim::vfunc_19()
{
    return 0;
}

// @0x1417fb5a0
void StateSwim::vfunc_34()
{
    m_n28 = 1;
}
