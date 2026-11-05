// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateIdle and its siblings, the actor states of a standing
// player / npc / pet / fitting doll: pick and play the idle animation of the sub state, run the bore and emotion
// timers and start the idle sounds. See stateidle.h.
// MS2-UNIT: ?\stateidle.cpp
// MS2-RANGE: 0x1417cd420-0x1417d0be0 .text$mn
// MS2-PIN: memmove_s 0x1417d0ac0
#pragma function(memmove)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateidle.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>

#include <string.h>

#include <new>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <efd/utf8string.h>
#include <efd/SmartPointer.h>

#include "stateidle.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/pushcontrol.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/bonerotateinterpolator.h"
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail::FUN_1408e57f0 (the scene-service global)
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include <egmAnimation/AnimationService.h>   // C3: AnimationService::GetActorManager
#include "ms2/client/ms2/uihudentity.h"   // C3: UIHudEntity::Entity::FUN_140f48d40

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

// The item a state is told about in its slots 29/30.
class Unk_StateArg29 : public CItem { };

// A npc / pet actor: the animation named by the npc's record.
class CNpc : public PCBase
{
public:
    CString FUN_141093530();                             // the jump animation name of the record
};

// Buff container of an actor.
#include "ms2/placeholder/nipoint3.h"   // C3: Vector3, the return type of Unk_PCMove::FUN_141683290
class NoticeMessage   // C3: unit-local view (ctor 0x140a52ef0, dtor 0x1405a89e0, 0x70 bytes)
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void SetActor(int nActor);                           // 0x140a53190
    void* m_storage[14];
};
class Unk_PCMove { public: Vector3 FUN_141683290(); bool FUN_141683100(int nKey); bool FUN_141682fe0(int nKey); };   // C3: view of the real class (unit_141682f80)

// The player-side views of the actor (PC members seen through the PCBase pointer of FUN_1417b8370).
class Unk_PCD88 : public CBoneRotateManager { };    // the target the player is bound to
// C3: the +0xd00 action table lookup is PCBase::FUN_141679120 (pcbase.h).

#define AsPC(p) reinterpret_cast<PC*>(p)


// The animation service: the sequence id / actor manager of a model key.
class Unk_SiAnimSvc;
int FUN_140b7f6a0(void* pSvc, const egf::EntityID& kKey);   // C3: the real free function (sequence id of a model key)
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();

// Config constants singleton (FUN_1401d3200).
class Unk_SiDelay { public: char m_c; };
int FUN_14025a620(class Unk_ConstVal* p);   // C3: the real free function (a constant slot's value)
class Unk_SiUInt { public: char m_c; };
class Unk_StringOptionEntry { public: char m_c; };   // C3: layout view of Common::Constants::Value<CString> (its Get() is 0x140298f80)
typedef Unk_StringOptionEntry Unk_SiName;
class Unk_SiConsts
{
public:
    char m_pad0[0x8a0];
    Unk_SiDelay m_delayLeave;                            // +0x8a0
    char m_pad1[0xa00 - 0x8a1];
    Unk_SiDelay m_delayBore;                             // +0xa00
    char m_pad2[0x7de0 - 0xa01];
    Unk_SiUInt m_intervalA;                              // +0x7de0
    char m_pad3[0x7e90 - 0x7de1];
    Unk_SiUInt m_intervalB;                              // +0x7e90
    char m_pad4[0xe038 - 0x7e91];
    Unk_SiName m_strSoundJob50;                          // +0xe038
    char m_pad5[0xe098 - 0xe039];
    Unk_SiName m_strSoundJob110;                         // +0xe098
};
MS2_CHECK_OFFSET(Unk_SiConsts, m_delayBore, 0xa00);
MS2_CHECK_OFFSET(Unk_SiConsts, m_intervalB, 0x7e90);
MS2_CHECK_OFFSET(Unk_SiConsts, m_strSoundJob110, 0xe098);
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
class Unk_PCBaseComp_aa8 : public CPtred { };     // the pet component
struct Unk_MagicRidee* FUN_141468360(struct Unk_MagicEntity*);   // C3: was FUN_141468360

// The effect service and the player manager.

// Scene / mode queries of the bore timer.
class Unk_SiScene;
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1422b9ea0();
};
class Unk_SiMode;
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: was FUN_14025e7a0
class GFxManager   // C3: member view for the former free stand-ins
{
public:
    int FUN_1422ae940();
};

// The npc's pet bookkeeping (idle voices).
class CPet   // C3: member view for the former free stand-ins
{
public:
    class PCBase* FUN_140b10360();
    int FUN_140b11180();
    void FUN_140b114e0(int);
};
class Unk_SiPetBook { public: char m_c; };
int FUN_140b11e90(struct Unk_PetFoodBook* pBook, PCBase* pPet);   // C3: the real free function
class Unk_SiPetData { public: char m_pad[0x68]; Unk_SiPetBook m_book; };
class Unk_SiPetMgr;
class Unk_BreakSelected* FUN_140535320();   // C3: was FUN_140535320
class CCPetInfoPacket { public: class Info; };
class CPetManager   // C3: member view for the former free stand-ins
{
public:
    class Unk_PetManagerEmpty* FUN_140c8b430();
    CCPetInfoPacket::Info* GetInfo();
    MS2Ptr<CItem> FindItemById(int nItemId);
};

// ---- StateIdle ----

// @0x1417cd420
StateIdle::StateIdle(PCBase* pOwner) : State(pOwner)
{
    m_nSoundIdle = 0;
}

// @0x1417cd4a0
StateIdle::~StateIdle()
{
    FUN_1417cf210();
    FUN_1417cf4a0();
}

// @0x1417cd520
void StateIdle::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    if (m_pOwner->FUN_141676b70() != 0)
        vfunc_2(0xc);
    else
        vfunc_2(1);
    m_timerBore.FUN_1408687f0();
    m_timerLeave.FUN_1408687f0();
    if (m_pOwner->FUN_141675ed0() != 0)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
            PCBase::FUN_141677f40(m_pOwner);
        vfunc_2(7);
        if (m_nSoundIdle == 0)
            FUN_1417cf260();
    }
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
        AsPC(pPC)->FUN_141659000(0);
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC != 0)
        static_cast<CPushControl*>(pMyPC->FUN_141675eb0())->FUN_1413fcf90();
    m_pOwner->FUN_14166f8f0(0, 1);
}

// @0x1417cd680
void StateIdle::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Vector3 kMove = DAT_143b01a60;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417cd700
void StateIdle::vfunc_5(int n)
{
    State::vfunc_5(n);
    FUN_1417cf210();
    FUN_1417cf4a0();
}

// @0x1417cd740
int StateIdle::vfunc_15()
{
    if (m_n10 == 7)
        return 0;
    if (m_n10 == 6)
        return 0;
    return 1;
}

// @0x1417cd770
// MS2-FUNCTIONAL: slot 22 of GameObject takes the point by value in the exe (the returned point is copied into the
// argument slot), but the shared header declares it by reference.
void StateIdle::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000d)
    {
        FUN_1417cef60();
        return;
    }
    MyPC* pPC = FUN_1417b84b0();
    if (m_pOwner->vfunc_63() == 0)
        return;
    int nWater = m_pOwner->FUN_141675ed0();
    Unk_PCMove* pBuff = static_cast<Unk_PCMove*>(m_pOwner->FUN_14166d240());
    m_pOwner->vfunc_22(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pBuff->FUN_141683290())));
    if (m_pOwner->FUN_141676b70() != 0)
    {
        vfunc_2(0xc);
    }
    else if (m_n10 == 0xc)
    {
        vfunc_2(1);
    }
    if (pPC != 0 && pBuff->FUN_141683100(0x30d41))
    {
        egf::Entity* pEntity = reinterpret_cast<PC*>(pPC)->FUN_141659af0(1);
        if (pEntity != 0)
        {
            if (pPC->FUN_1416764a0() != 0)
            {
                MS2Ptr<RideOffActionTakeLR> spAction(new RideOffActionTakeLR(1));
                spAction->m_n28 = 1;
                if (pEntity->GetModel()->ContainsModel(0xbadf0a13))
                {
                    spAction->m_n2c = 0xbadf0a13;
                }
                else if (pEntity->GetModel()->ContainsModel(0xc13e30c8))
                {
                    spAction->m_n2c = 0xc13e30c8;
                }
                pPC->SendRequestRideMode1(spAction.get());
            }
            else
            {
                pPC->FUN_1415248d0(1, 0);
            }
        }
    }
    else if (pPC != 0 && pBuff->FUN_141683100(0x30d42))
    {
        pPC->FUN_1415248d0(2, 0);
    }
    else if (m_pOwner->FUN_141671a30() != 0 && pBuff->FUN_141682fe0(0x493e1))
    {
        m_pOwner->vfunc_59(6, 0, 0x25, 0);
    }
    else if (m_pOwner->FUN_1416749c0())
    {
        m_pOwner->vfunc_59(2, 0, 0, 0);
    }
    else if (pBuff->FUN_141682fe0(0x493e5) && nWater == 0)
    {
        m_pOwner->vfunc_59(3, 0, 0, 0);
    }
    else
    {
        FUN_1417b9460();
    }
    if (nWater == 0)
        FUN_1417cef60();
}

// @0x1417cdbb0
void StateIdle::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    unsigned nSeq = FUN_140b7f6a0(reinterpret_cast<Unk_SiAnimSvc*>(FUN_141b6f910()), m_pOwner->FUN_14123c460());
    const efd::ClassInfo* pDesc;
    if (m_pOwner != 0)
        pDesc = m_pOwner->GetClassDesc();
    else
        pDesc = 0;
    if (!efd::ClassInfo::IsKindOf(pDesc, 0x6200044))
    {
        int nWater = m_pOwner->FUN_141675ed0();
        if (nWater == 0 && m_pOwner->vfunc_99(0) != 0)
        {
            m_pOwner->vfunc_59(5, 0, 0, 0);
            return;
        }
        else
        {
            PCBase* pPC = FUN_1417b8370();
            if (FUN_1417b84b0() != 0)
            {
                efd::SmartPointer<Ridee> spRidee(((class Ridee*)FUN_141468360((struct Unk_MagicEntity*)(m_pOwner))));
                if (spRidee ? true : false)
                {
                    if (spRidee->FUN_1417075e0() != 0)
                        nWater = 0;
                }
                if (nWater != 0)
                {
                    vfunc_2(7);
                }
                else if (pPC != 0)
                {
                    if (m_n10 == 7)
                        vfunc_2(1);
                    if (AsPC(pPC)->IsCubeMode1() != 0)
                    {
                        vfunc_2(9);
                    }
                    else if (AsPC(pPC)->FUN_141659690() != 0)
                    {
                        vfunc_2(8);
                    }
                    else if (m_n10 == 8 || m_n10 == 9)
                    {
                        vfunc_2(1);
                    }
                }
            }
            if (m_n10 != 7 && m_nSoundIdle != 0)
            {
                FUN_1417cf210();
                return;
            }
        }
    }
    switch (m_n10)
    {
    case 0xc:
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x1e));
        m_pOwner->PlayAnimation(kName, 1.0f, false, false);
    }
        break;
    case 6:
        FUN_1417ce9f0(nSeq);
        break;
    case 1:
        FUN_1417ce6f0(nSeq);
        break;
    case 0x14:
        FUN_1417cee40(nSeq);
        break;
    case 0x15:
        FUN_1417cee90(nSeq);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        FUN_1417ce820(nSeq);
        break;
    case 7:
        FUN_1417ceab0(nSeq);
        break;
    case 8:
        FUN_1417ceca0(nSeq);
        break;
    case 9:
        FUN_1417ced70(nSeq);
        break;
    case 0xa:
        if (m_pOwner->vfunc_65() != 0)
            m_pOwner->FUN_14166ce70(0);
        if (m_pOwner->PlayAnimationById(0x3d))
            m_pOwner->FUN_14166f8f0(0, 1);
        break;
    case 0xb:
    {
        if (m_pOwner->vfunc_65() != 0)
            m_pOwner->FUN_14166ce70(0);
        bool bPlayed;
        {
            efd::utf8string kName("FittingDoll_Idle_A");
            bPlayed = m_pOwner->PlayAnimation(kName, 1.0f, false, false);
        }
        if (bPlayed)
            m_pOwner->FUN_14166f8f0(0, 1);
    }
        break;
    case 0x16:
    {
        if (m_pOwner->vfunc_65() != 0)
            m_pOwner->FUN_14166ce70(0);
        bool bPlayed;
        {
            efd::utf8string kName("Emotion_MusicStart_A");
            bPlayed = m_pOwner->PlayAnimation(kName, 1.0f, false, false);
        }
        if (bPlayed)
            m_pOwner->FUN_14166f8f0(0, 1);
    }
        break;
    case 0xd:
        FUN_1417ce970(nSeq);
        break;
    case 0xe:
        FUN_1417ce9b0(nSeq);
        break;
    case 0x4c:
    {
        efd::utf8string kName("Equip_Change_Cap_A");
        m_pOwner->PlayAnimation(kName, 1.0f, false, false);
    }
        break;
    case 0x4e:
    {
        efd::utf8string kName("Equip_Change_Body_A");
        m_pOwner->PlayAnimation(kName, 1.0f, false, false);
    }
        break;
    case 0x53:
    {
        efd::utf8string kName("Equip_Change_Shoes_A");
        m_pOwner->PlayAnimation(kName, 1.0f, false, false);
    }
        break;
    case 0x51:
    {
        efd::utf8string kName("Equip_Change_Glove_A");
        m_pOwner->PlayAnimation(kName, 1.0f, false, false);
    }
        break;
    case 0x52:
    {
        efd::utf8string kName("Equip_Change_Mantle_A");
        m_pOwner->PlayAnimation(kName, 1.0f, false, false);
    }
        break;
    }
}

// @0x1417ce460
void StateIdle::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (m_pOwner->FUN_14166de90(0x27, eSequenceID))
    {
        vfunc_2(1);
        unsigned nSeq = static_cast<NiActorManager*>(pkManager)->GetTargetAnimation();
        FUN_1417ce6f0(nSeq);
    }
    else if (m_pOwner->FUN_14166de90(0x49, eSequenceID))
    {
        vfunc_2(0x15);
        unsigned nSeq = static_cast<NiActorManager*>(pkManager)->GetTargetAnimation();
        FUN_1417cee90(nSeq);
        FUN_1417cf360();
    }
    if (m_n10 == 0x4c || m_n10 == 0x4e || m_n10 == 0x53 || m_n10 == 0x51 || m_n10 == 0x52)
    {
        vfunc_2(1);
    }
    else if (m_n10 == 0xd || m_n10 == 0xe)
    {
        vfunc_2(0x15);
    }
}

// @0x1417ce5b0
void StateIdle::vfunc_21(int n)
{
    m_timerLeave.FUN_140868750(FUN_14025a620((class Unk_ConstVal*)&((class Unk_SiConsts*)FUN_1401d3200())->m_delayLeave));
    vfunc_2(6);
}

// @0x1417ce600
int StateIdle::vfunc_14()
{
    if (m_n10 == 7)
        return 0;
    else
        return m_n14;
}

// @0x1417ce630
int StateIdle::vfunc_16()
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0 && AsPC(pPC)->IsCubeMode1() != 0)
        return 1;
    return 0;
}

// @0x1417ce680
int StateIdle::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p->m_nSub != m_n10)
        return 1;
    return 0;
}

// @0x1417ce6f0
void StateIdle::FUN_1417ce6f0(unsigned nSeq)
{
    int nKey = 0;
    if (m_pOwner->vfunc_65() != 0)
        nKey = 1;
    if (!m_pOwner->FUN_14166de90(nKey, nSeq))
    {
        {
            efd::utf8string kName(m_pOwner->vfunc_123(nKey));
            m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
        }
        m_pOwner->FUN_14166f8f0(0, 1);
    }
}

// @0x1417ce820
void StateIdle::FUN_1417ce820(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x27, nSeq))
    {
        int nSub = m_n10 - 2;
        efd::utf8string kName = m_pOwner->FUN_141679170(0x27, nSub);
        if (!m_pOwner->HasAnimSequence(kName.c_str()))
            kName = m_pOwner->FUN_141679170(0x27, 0);
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417ce970
void StateIdle::FUN_1417ce970(unsigned nSeq)
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        pPC->PlayAnimationById(0x49);
}

// @0x1417ce9b0
void StateIdle::FUN_1417ce9b0(unsigned nSeq)
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        pPC->PlayAnimationById(0x49);
}

// @0x1417ce9f0
void StateIdle::FUN_1417ce9f0(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x2e, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x2e));
        m_pOwner->PlayAnimation(kName, 1.0f, false, false);
    }
}

// @0x1417ceab0
void StateIdle::FUN_1417ceab0(unsigned nSeq)
{
    int nKey = 0x30;
    efd::SmartPointer<Ridee> spRidee(((class Ridee*)FUN_141468360((struct Unk_MagicEntity*)(m_pOwner))));
    if (spRidee ? true : false)
    {
        if (spRidee->FUN_1417075e0() != 0)
            nKey = 0;
    }
    efd::utf8string kName;
    if (nKey == 0x30)
    {
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0)
            AsPC(pPC)->FUN_14165e2a0(kName, nKey);
    }
    if (kName.empty() && !m_pOwner->FUN_14166de90(nKey, nSeq))
        kName = m_pOwner->vfunc_123(nKey);
    bool bPlayed = false;
    if (!kName.empty())
        bPlayed = m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    if (bPlayed)
        FUN_1417cf210();
    if (m_nSoundIdle == 0)
        FUN_1417cf260();
}

// @0x1417ceca0
void StateIdle::FUN_1417ceca0(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x37, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x37));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417ced70
void StateIdle::FUN_1417ced70(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x36, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x36));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417cee40
void StateIdle::FUN_1417cee40(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x49, nSeq))
        m_pOwner->PlayAnimationById(0x49);
}

// @0x1417cee90
void StateIdle::FUN_1417cee90(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x4a, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x4a));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417cef60
void StateIdle::FUN_1417cef60()
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    if (pPC->FUN_1416764a0() != 0)
        return;
    if (m_pOwner->vfunc_65() != 0)
        m_timerBore.FUN_1408687f0();
    bool bBusy = ((class GFxSceneService*)(class Unk_SiScene*)(((Unk_SiScene*)CUserMail::FUN_1408e57f0())))->FUN_1422b9ea0() == 1;
    if (!bBusy)
        bBusy = ((class GFxManager*)(class Unk_SiMode*)(((class Unk_SiMode*)FUN_14025e7a0())))->FUN_1422ae940() == 1;
    if (m_n10 == 1 && m_pOwner->vfunc_65() == 0 && !bBusy)
    {
        Unk_PCD88* pTarget = AsPC(pPC)->FUN_14165c2d0().get();
        if (pTarget != 0 && pTarget->IsLooking() == 0 && m_timerBore.FUN_140868c00() != 0)
        {
            int nBore = m_pOwner->FUN_141679120(0x27);
            vfunc_2(nBore + 2);
            if (m_n10 < 2)
                m_n10 = 2;
            if (5 < m_n10)
                m_n10 = 5;
            m_timerBore.FUN_1408687f0();
        }
        if (m_timerBore.FUN_140868ba0() == 0)
            m_timerBore.FUN_140868750(FUN_14025a620((class Unk_ConstVal*)&((class Unk_SiConsts*)FUN_1401d3200())->m_delayBore));
    }
    else
    {
        if (m_timerLeave.FUN_140868c00() != 0)
            vfunc_2(1);
    }
}

// @0x1417cf210
void StateIdle::FUN_1417cf210()
{
    if (m_nSoundIdle != 0)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nSoundIdle);
        m_nSoundIdle = 0;
    }
}

// @0x1417cf260
void StateIdle::FUN_1417cf260()
{
    FUN_1417cf210();
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        ((Unk_EffectTarget&)(kTarget)).m_strName = AsPC(pPC)->FUN_14165e010(0x30);
        ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd1a10(reinterpret_cast<class Unk_WsC_GameObj*>(m_pOwner));
        kTarget.SetActor(m_pOwner->FUN_14123c580());
        m_nSoundIdle = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(((Unk_EffectTarget&)(kTarget)));
    }
}

// @0x1417cf360
void StateIdle::FUN_1417cf360()
{
    FUN_1417cf4a0();
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        if (AsPC(pPC)->FUN_141654700() == 0x32)
        {
            ((Unk_EffectTarget&)(kTarget)).m_strName = *reinterpret_cast<Common::Constants::Value<CString>*>(&((class Unk_SiConsts*)FUN_1401d3200())->m_strSoundJob50)->Get();
        }
        else if (AsPC(pPC)->FUN_141654700() == 0x6e)
        {
            ((Unk_EffectTarget&)(kTarget)).m_strName = *reinterpret_cast<Common::Constants::Value<CString>*>(&((class Unk_SiConsts*)FUN_1401d3200())->m_strSoundJob110)->Get();
        }
        else
        {
            return;
        }
        ((Unk_EffectTarget&)(kTarget)).m_nKind = WorldService::GetInstance()->FUN_141bd1a10(reinterpret_cast<class Unk_WsC_GameObj*>(m_pOwner));
        kTarget.SetActor(m_pOwner->FUN_14123c580());
        ((Unk_EffectTarget&)(kTarget)).m_b30 = true;
        m_nSoundEmotion = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(((Unk_EffectTarget&)(kTarget)));
    }
}

// @0x1417cf4a0
void StateIdle::FUN_1417cf4a0()
{
    if (m_nSoundEmotion != 0)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nSoundEmotion);
        m_nSoundEmotion = 0;
    }
}

// @0x1417cf4f0
void StateIdle::vfunc_29(MS2Ptr<Unk_StateArg29> p)
{
    State::vfunc_29(p);
    MS2Ptr<CItemGem> spGem(p->GetGem());
    bool bGem = (spGem.get() ? true : false) && (spGem->GetGem().get() ? true : false);
    if (bGem && m_n10 == 7)
    {
        MS2Ptr<CGemSwim> spSwim(dynamic_cast<CGemSwim*>((CGemBase*)spGem->GetGem()));
        if (spSwim.get() != 0)
            FUN_1417cf210();
    }
}

// ---- StateIdleNPC ----

// @0x1417cf710
StateIdleNPC::StateIdleNPC(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417cf750
StateIdleNPC::~StateIdleNPC()
{
}

// @0x1417cf780
void StateIdleNPC::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n10 = 1;
    NiActorManager* pMgr = reinterpret_cast<egmAnimation::AnimationService*>(reinterpret_cast<Unk_SiAnimSvc*>(FUN_141b6f910()))->GetActorManager(m_pOwner->FUN_14123c460());
    if (pMgr != 0)
    {
        unsigned nSeq = static_cast<NiActorManager*>(pMgr)->GetTargetAnimation();
        m_pOwner->FUN_14166de90(0, nSeq) || m_pOwner->FUN_14166de90(1, nSeq) ||
            m_pOwner->FUN_14166de90(0x27, nSeq);
    }
}

// @0x1417cf860
void StateIdleNPC::FUN_1417cf860(unsigned nSeq)
{
    int nKey = 0;
    if (m_pOwner->vfunc_65() != 0)
        nKey = 1;
    if (!m_pOwner->FUN_14166de90(nKey, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(nKey));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
}

// ---- StateIdlePet ----

// @0x1417cf970
StateIdlePet::StateIdlePet(PCBase* pOwner) : State(pOwner), m_nVoiced(0), m_nTired(0)
{
}

// @0x1417cfa00
StateIdlePet::~StateIdlePet()
{
}

// @0x1417cfa30
void StateIdlePet::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    if (m_nTired == 0)
    {
        m_timerVoiceA.Init();
        m_nTired = 1;
    }
}

// @0x1417cfa80
void StateIdlePet::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc == 0)
        return;
    PCBase* pPet = ((class CPet*)(class PCBase*)(pNpc))->FUN_140b10360();
    if (pPet == 0)
        return;
    ((class CPet*)(class PCBase*)(pNpc))->FUN_140b11180();
}

// @0x1417cfaf0
void StateIdlePet::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_n10 = 1;
}

// @0x1417cfb30
void StateIdlePet::vfunc_9(double fTime)
{
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc == 0)
        return;
    PCBase* pPet = ((class CPet*)(class PCBase*)(pNpc))->FUN_140b10360();
    if (pPet == 0)
        return;
    if (pPet->IsDead() != 0 && AsPC(pPet)->IsRevivalBlocked() != 0)
    {
        efd::utf8string kName("Tired_A");
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
    else
    {
        unsigned nSeq = FUN_140b7f6a0(reinterpret_cast<Unk_SiAnimSvc*>(FUN_141b6f910()), m_pOwner->FUN_14123c460());
        switch (m_n10)
        {
        case 1:
            FUN_1417cfea0(nSeq);
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            FUN_1417d0140(nSeq);
            break;
        case 0xf:
            FUN_1417d0210(nSeq);
            break;
        case 0x10:
            FUN_1417d02e0(nSeq);
            break;
        case 0x11:
            FUN_1417d03b0(nSeq);
            break;
        case 0x13:
            FUN_1417d0470(nSeq);
            break;
        }
    }
}

// @0x1417cfd60
void StateIdlePet::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc == 0)
        return;
    {
        MS2Ptr<Unk_PCBaseComp_aa8> spComp = pNpc->vfunc_85();
        if (spComp.get() ? true : false)
        {
            if (reinterpret_cast<UIHudEntity::Entity*>(spComp.operator->())->FUN_140f48d40() == 0)
            {
                if (m_nVoiced != 0)
                    m_n10 = 1;
                m_nVoiced = 0;
            }
        }
        if (m_pOwner->FUN_14166de90(0x27, eSequenceID))
        {
            m_n10 = 1;
            unsigned nSeq = static_cast<NiActorManager*>(pkManager)->GetTargetAnimation();
            FUN_1417cfea0(nSeq);
        }
        else if (m_pOwner->FUN_14166de90(0x44, eSequenceID))
            m_n10 = 1;
    }
}

// @0x1417cfea0
void StateIdlePet::FUN_1417cfea0(unsigned nSeq)
{
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc == 0)
        return;
    PCBase* pPet = ((class CPet*)(class PCBase*)(pNpc))->FUN_140b10360();
    if (pPet != 0)
    {
        if (m_timerVoiceA.Check(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_SiConsts*)FUN_1401d3200())->m_intervalA)->Get()) != 0)
            FUN_1417d0540(0x5a);
        if (m_timerVoiceB.Check(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_SiConsts*)FUN_1401d3200())->m_intervalB)->Get()) != 0)
        {
            int nPetId = FUN_140b11e90((struct Unk_PetFoodBook*)&reinterpret_cast<Unk_SiPetData*>(reinterpret_cast<CPetManager*>(FUN_140535320())->GetInfo())->m_book, pPet);
            if (nPetId != 0)
            {
                MS2Ptr<CItem> spRow = reinterpret_cast<CPetManager*>(((class CPetManager*)(class Unk_SiPetMgr*)(((class Unk_SiPetMgr*)FUN_140535320())))->FUN_140c8b430())->FindItemById(nPetId);
                if (spRow == 0)
                    FUN_1417d0540(0x5f);
            }
        }
    }
    if (m_pOwner->FUN_14166de90(0x27, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x27));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
    else if (!m_pOwner->FUN_14166de90(0, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417d0140
void StateIdlePet::FUN_1417d0140(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x27, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x27));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x5c);
}

// @0x1417d0210
void StateIdlePet::FUN_1417d0210(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x42, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x42));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x5d);
}

// @0x1417d02e0
void StateIdlePet::FUN_1417d02e0(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x43, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x43));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x5e);
}

// @0x1417d03b0
void StateIdlePet::FUN_1417d03b0(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x44, nSeq))
    {
        efd::utf8string kName("Revive_A");
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x60);
}

// @0x1417d0470
void StateIdlePet::FUN_1417d0470(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x45, nSeq))
    {
        efd::utf8string kName(m_pOwner->vfunc_123(0x45));
        m_pOwner->PlayAnimation(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x61);
}

// @0x1417d0540
void StateIdlePet::FUN_1417d0540(int nVoice)
{
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc == 0)
        return;
    if (m_nVoiced != 0)
        return;
    ((class CPet*)(class PCBase*)(pNpc))->FUN_140b114e0(nVoice);
    m_nVoiced = 1;
}

// ---- StateJumpNpc ----

// @0x1417d05a0
StateJumpNpc::StateJumpNpc(PCBase* pOwner) : State(pOwner)
{
    m_pNpc = dynamic_cast<CNpc*>(pOwner);
}

// @0x1417d0620
void StateJumpNpc::vfunc_4(StateData* pData)
{
    if (m_pNpc == 0)
        return;
    CString strAnim = m_pNpc->FUN_141093530();
    efd::utf8string kName((const char*)strAnim);
    m_pNpc->PlayAnimation(kName, 1.0f, false, false);
}

// ---- StatePuppetNpc ----

// @0x1417d06e0
StatePuppetNpc::StatePuppetNpc(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417d0720
void StatePuppetNpc::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// ---- StateIdleFittingDoll ----

// @0x1417d0780
StateIdleFittingDoll::StateIdleFittingDoll(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417d07c0
StateIdleFittingDoll::~StateIdleFittingDoll()
{
}

// @0x1417d07f0
void StateIdleFittingDoll::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n10 = 1;
    efd::utf8string kName("EMPTY_SEQUENCE_AT_0f");
    m_pOwner->PlayAnimation(kName, 1.0f, false, false);
}

// @0x1417d0890
void StateIdleFittingDoll::vfunc_5(int n)
{
}

// ---- trivial slots ----

// @0x1417d0a60
int StateIdle::vfunc_1()
{
    return 1;
}

// @0x1417d0a70
int StateIdleFittingDoll::vfunc_1()
{
    return 1;
}

// @0x1417d0a80
int StateIdleNPC::vfunc_1()
{
    return 1;
}

// @0x1417d0a90
int StateIdlePet::vfunc_1()
{
    return 1;
}

// @0x1417d0aa0
int StateJumpNpc::vfunc_1()
{
    return 6;
}

// @0x1417d0ab0
int StatePuppetNpc::vfunc_1()
{
    return 0x23;
}

// ---- trailing CRT inline ----

// The UCRT header-inline memmove_s (corecrt_memcpy_s.h) ends the unit; the pointer keeps the unreferenced COMDAT.
// @0x1417d0ac0
__declspec(selectany) extern errno_t(__cdecl* const g_pStateIdleMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;
