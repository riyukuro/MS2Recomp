// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateDead / StateDeadNPC / StateRevival: the actor states of
// a player's death (death motion, optional revive-in-place effect, auto-revival), of an npc's death (motion, corpse effect,
// exp reward to the local player) and of the stand-up motion after a revival. See statedead.h.
// MS2-UNIT: ?\statedead.cpp
// MS2-RANGE: 0x1417c24a0-0x1417c3780 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statedead.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>

#include <float.h>
#include <errno.h>
#include <string.h>
#include <efd/utf8string.h>

#include "statedead.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/commonfiles/pvpinfo.h"   // C3: CPvPInfo::m_nTeam
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/pushcontrol.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/gameobjectcontroller.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
class NoticeMessage   // C3: unit-local view (ctor 0x140a52ef0, dtor 0x1405a89e0, 0x70 bytes)
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void SetActor(int nActor);   // 0x140a53190
    void* m_storage[14];
};

// ---- unit-local views of the exe objects and unrecovered callees ----

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

// The map data of the current field: +0x140375570 tells whether the field revives players on its own.
class Unk_DeadField : public CFieldData { };

// The player manager singleton.
class Unk_DeadWorld
{
public:
    MyPC* FUN_141bd0cc0();                               // the local player
};


// The constants tables: the revive animation id slot at +0xd248 of the first, two effect names at +0x278 of the second.
struct Unk_DeadConstVal { char m_pad[0x58]; };
struct Unk_DeadConsts
{
    char m_pad_00[0xd248];
    Unk_DeadConstVal m_reviveAnim;                       // +0xd248
};
struct Unk_DeadTexts
{
    char m_pad_00[0x278];
    CString m_strReviveEffect;                           // +0x278
    CString m_strDeathEffect;                            // +0x280
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0

// The npc table row: the corpse effect name at +0x448.
class Unk_DeadNpcData { public: char m_pad_00[0x448]; CString m_strCorpseEffect; };
// The owner seen as an npc.
class Unk_DeadNpc : public CNpc
{
public:
};

void FUN_140ef4330();
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
void FUN_1410943b0(PCBase* pActor, int n);
CString FUN_1409a2360(const char* psz, int n);             // text conversion

// ---- StateDead ----

// @0x1417c24a0
StateDead::StateDead(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
    m_nEffect = 0;
}

// @0x1417c2500
StateDead::~StateDead()
{
}

// @0x1417c2530
void StateDead::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    bool bRevive = false;
    int nAnimId = 0;
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        MS2Ptr<CFieldDataCli> kField = WorldService::GetInstance()->FUN_141bd30a0();
        if (kField == 0)
            return;
        if (reinterpret_cast<PC*>(pPC)->FUN_14165ef30() != 0)
        {
            bRevive = true;
            nAnimId = reinterpret_cast<CPvPInfo*>(reinterpret_cast<PC*>(pPC)->FUN_140967420().operator->())->m_nTeam;
        }
        else
        {
            if (reinterpret_cast<Unk_DeadField*>(kField.operator->())->FUN_140375570() != 0)
            {
                bRevive = true;
                nAnimId = *reinterpret_cast<Common::Constants::Value<int>*>(&((struct Unk_DeadConsts*)GetClientConstants())->m_reviveAnim)->Get();
            }
        }
    }
    if (bRevive == true)
    {
        m_pOwner->vfunc_23(0);
        m_pOwner->PlayAnimation(m_pOwner->FUN_141679170(0x40, nAnimId), 1.0f, false, false);
        m_pOwner->vfunc_31(false);
    }
    else
    {
        m_pOwner->vfunc_23(1);
        {
            efd::utf8string kAnim(m_pOwner->vfunc_123(0x34));
            m_pOwner->PlayAnimation(kAnim, 1.0f, false, false);
        }
        m_pOwner->vfunc_31(false);
        PCBase* pPCAgain = FUN_1417b8370();
        if (pPCAgain != 0)
            reinterpret_cast<PC*>(pPCAgain)->FUN_14165cac0();
    }
    if (FUN_1417b84b0() != 0)
    {
        MyPC* pMyPC = FUN_1417b84b0();
        if (pMyPC != 0)
        {
            reinterpret_cast<PC*>(pMyPC)->SendRequestCube();
            ((CPushControl*)pMyPC->FUN_141675eb0())->FUN_1413fcf90();
        }
        if (bRevive == true)
        {
            NoticeMessage kTarget;   // C3: was Unk_EffectTarget
            ((Unk_EffectTarget&)(kTarget)).m_strName = ((struct Unk_DeadTexts*)FUN_1401d31f0())->m_strReviveEffect;
            ((Unk_EffectTarget&)(kTarget)).m_nKind = 1;
            ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->FUN_14123c580());
            m_nEffect = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(((Unk_EffectTarget&)(kTarget)));
        }
        else
        {
            NoticeMessage kTarget;   // C3: was Unk_EffectTarget
            ((Unk_EffectTarget&)(kTarget)).m_strName = ((struct Unk_DeadTexts*)FUN_1401d31f0())->m_strDeathEffect;
            ((Unk_EffectTarget&)(kTarget)).m_nKind = 1;
            ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->FUN_14123c580());
            TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(((Unk_EffectTarget&)(kTarget)));
        }
        if (reinterpret_cast<PC*>(FUN_1417b84b0())->IsRevivalBlocked() != 0)
            reinterpret_cast<CGuideManager*>(((void*)FUN_1409331e0()))->AddTrigger((CGuideManager::TriggerType)(8), 0, 0);
    }
}

// @0x1417c29b0
void StateDead::vfunc_5(int n)
{
    if (m_nEffect != 0)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect);
    m_pOwner->vfunc_23(0);
    m_pOwner->vfunc_31(true);
    FUN_140ef4330();
    State::vfunc_5(n);
}

// @0x1417c2a40
void StateDead::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Vector3 kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// @0x1417c2ac0
void StateDead::vfunc_23()
{
    m_pOwner->vfunc_23(1);
    m_pOwner->vfunc_31(false);
    m_pOwner->vfunc_32(true);
}

// ---- StateDeadNPC ----

// @0x1417c2b30
StateDeadNPC::StateDeadNPC(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
    m_nEffect = 0;
    m_bFinished = 0;
}

// @0x1417c2bb0
StateDeadNPC::~StateDeadNPC()
{
    if (m_nEffect != 0)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417c2c30
void StateDeadNPC::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_bFinished = 0;
    MS2Ptr<StateDeadNPCData> spData(dynamic_cast<StateDeadNPCData*>(pData));
    if (spData.get() != 0 && spData->m_b18 != 0)
    {
        m_strAnim = "Dead_Idle_A";
    }
    else
    {
        m_strAnim = m_pOwner->vfunc_123(0x34);
        if (FUN_1417b8480() != 0)
            FUN_1410943b0(FUN_1417b8480(), 4);
    }
    CString strEffect(reinterpret_cast<Unk_DeadNpcData*>(reinterpret_cast<CNpc*>(((Unk_DeadNpc*)FUN_1417b8480()))->GetNpcData().operator->())->m_strCorpseEffect);
    if (strEffect.GetLength() != 0)
    {
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        ((Unk_EffectTarget&)(kTarget)).m_strName = strEffect;
        ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd1a10(reinterpret_cast<class Unk_WsC_GameObj*>(m_pOwner));
        ((NoticeMessage&)(kTarget)).SetActor(m_pOwner->FUN_14123c580());
        m_nEffect = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(((Unk_EffectTarget&)(kTarget)));
    }
    reinterpret_cast<GameObjectController*>(m_pOwner->GetPhysicsBody())->FUN_14123fbf0(5);
    m_pOwner->PlayAnimation(efd::utf8string((const char*)FUN_1409a2360(m_strAnim, 0)), 1.0f, false, false);
}

// @0x1417c2f50
void StateDeadNPC::vfunc_5(int n)
{
    State::vfunc_5(n);
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect);
    m_nEffect = 0;
}

// @0x1417c2fa0
void StateDeadNPC::vfunc_6()
{
    if (m_bFinished == 0)
        return;
    Unk_DeadNpc* pNpc = reinterpret_cast<Unk_DeadNpc*>(efd::DynamicCast<CNpc, PCBase>(m_pOwner));
    if (pNpc != 0)
    {
        {
            int nHit = reinterpret_cast<CNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->GetCorpseHitAble();
            if (nHit != 0)
            {
                efd::utf8string kAnim;
                if ((m_strAnim == "Dead_A") || (m_strAnim == "Dead_Idle_A"))
                {
                    kAnim = "Dead_Damg_A";
                }
                else
                {
                    if ((m_strAnim == "Dead_B"))
                        kAnim = "Dead_Damg_B";
                    else
                        return;
                }
                m_pOwner->PlayAnimation(kAnim, 1.0f, true, false);
            }
        }
    }
}

// @0x1417c3140
void StateDeadNPC::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_bFinished != 0)
        return;
    if (m_pOwner->FUN_14166de90(0x34, eSequenceID))
    {
        m_bFinished = 1;
        Unk_DeadNpc* pNpc = reinterpret_cast<Unk_DeadNpc*>(efd::DynamicCast<CNpc, PCBase>(m_pOwner));
        if (pNpc != 0)
        {
            if (pNpc->FUN_141094e20() <= 0)
                return;
            MyPC* pMyPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            if (pMyPC != 0)
                pMyPC->FUN_1415294f0(m_pOwner->FUN_14123c580(), pNpc->FUN_141094e20());
        }
    }
}

// ---- StateRevival ----

// @0x1417c3220
StateRevival::StateRevival(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417c3270
StateRevival::~StateRevival()
{
}

// @0x1417c32a0
void StateRevival::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    efd::utf8string kAnim(m_pOwner->vfunc_123(0x33));
    m_pOwner->PlayAnimation(kAnim, 1.0f, false, false);
}

// @0x1417c3350
void StateRevival::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_pOwner->FUN_14166de90(0x33, eSequenceID))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417c3500
int StateDeadNPC::vfunc_15()
{
    return 1;
}

// @0x1417c3510
int StateRevival::vfunc_15()
{
    return 1;
}

// @0x1417c3520
int StateDead::vfunc_1()
{
    return 0xc;
}

// @0x1417c3530
int StateDeadNPC::vfunc_1()
{
    return 0xc;
}

// @0x1417c3540
int StateRevival::vfunc_1()
{
    return 0x18;
}

// ---- the unreferenced CRT copy of this TU ----

// The UCRT's `static __inline memmove_s` of this TU (unreferenced copy, kept alive by the pointer below).
#pragma function(memcpy, memset)
// @0x1417c3660
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
