// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Actor states StateEmotion / StateEmotionIdle /
// StateTriggerEmotion / StateTriggerFollowNpc and their StateData payloads. See stateemotionidle.h.
// MS2-UNIT: client\ms2\stateemotionidle.cpp
// MS2-RANGE: 0x1417c3780-0x1417c6e40 .text$mn
// MS2-RANGE: 0x140101fe0-0x140102270 .text$di
// MS2-PIN: ??0?$MS2Ptr@VStateTriggerEmotionData@@@@QEAA@XZ 0x1417c5140
// MS2-PIN: ??8?$MS2Ptr@VStateDataTriggerFollowNpc@@@@QEBA_NPEAVStateDataTriggerFollowNpc@@@Z 0x1417c53b0
// MS2-PIN: ?get@?$MS2Ptr@VStateTriggerEmotionData@@@@QEBAPEAVStateTriggerEmotionData@@XZ 0x1417c5440
// MS2-PIN: ??C?$MS2Ptr@VStateTriggerEmotionData@@@@QEBAPEAVStateTriggerEmotionData@@XZ 0x1417c5470
// MS2-PIN: ??_GStateEmotionData@@UEAAPEAXI@Z 0x1417c5500
// MS2-PIN: ??8?$MS2Ptr@VStateEmotionIdleData@@@@QEBA_NPEAVStateEmotionIdleData@@@Z 0x1417c6bb0
// MS2-PIN: ??C?$MS2Ptr@VRideOffAction@@@@QEBAPEAVRideOffAction@@XZ 0x1417c6bf0
// MS2-PIN: ??C?$MS2Ptr@VStateEmotionIdleData@@@@QEBAPEAVStateEmotionIdleData@@XZ 0x1417c6c10
// MS2-PIN: ??_GStateEmotionIdle@@UEAAPEAXI@Z 0x1417c6c20
// MS2-PIN: ??_GStateEmotionIdleData@@UEAAPEAXI@Z 0x1417c6c60
// MS2-PIN: ??0?$MS2Ptr@VStateEmotionIdleData@@@@QEAA@PEAVStateEmotionIdleData@@@Z 0x1417c6a70
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateEmotionIdleData@@@@QEAAAEAV1@PEAVStateEmotionIdleData@@@Z 0x1417c6b40
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateDataTriggerFollowNpc@@@@QEAAAEAV1@PEAVStateDataTriggerFollowNpc@@@Z 0x1417c5260 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateEmotionData@@@@QEAAAEAV1@PEAVStateEmotionData@@@Z 0x1417c52d0 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateTriggerEmotionData@@@@QEAAAEAV1@PEAVStateTriggerEmotionData@@@Z 0x1417c5340 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VStateEmotionData@@@@QEBAPEAVStateEmotionData@@XZ 0x1417c5430 ; unique
// MS2-PIN: ??C?$MS2Ptr@VStateDataTriggerFollowNpc@@@@QEBAPEAVStateDataTriggerFollowNpc@@XZ 0x1417c5450 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateDataTriggerFollowNpc@@@@AEBAXPEAX@Z 0x1417c58a0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateEmotionData@@@@AEBAXPEAX@Z 0x1417c58d0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateTriggerEmotionData@@@@AEBAXPEAX@Z 0x1417c5900 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VStateEmotionIdleData@@@@QEBAPEAVStateEmotionIdleData@@XZ 0x1417c6c00 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VStateEmotionIdleData@@@@AEBAXXZ 0x1417c6d30 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateemotionidle.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>

#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <efd/utf8string.h>

#include "stateemotionidle.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"   // C3: the real MyPC (FUN_141523bc0 returns CSkillSystem*)
#include "ms2/placeholder/cnpc.h"   // C3: CNpc::FUN_141093510
#include "ms2/placeholder/chomeprivilege.h"   // MyPC::m_spHomePrivilege needs the CPtred base
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <egmAnimation/AnimationService.h>   // C3: AnimationService::GetActorManager
#include "ms2/client/ms2/skilldatatablecli.h"   // C3: SkillDataTable::GetSkillData
#include "ms2/placeholder/fittingdollpc.h"   // C3: PC members
#include "ms2/placeholder/nipoint3.h"   // Vector3
#include "ms2/placeholder/clientconstants.h"   // C3: Common::Constants::Value<int>::Read
#include "ms2/client/ms2/skillsystem.h"   // C3: CSkillSystem::FUN_141768fb0

// The unit includes the sort-name / skill / stun header statics a second time (without the condition object).
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";

// ---- unit-local placeholders ----

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

// StateData slots 1/2 argument: the state-sync record; +0x64 carries the emotion / npc id.
class Unk_StateDataArg
{
public:
    char m_pad_00[0x64];
    int m_n64;
};

// MS2Ptr<StateSyncObject> argument of slots 22/28 (a state request): +0x1c state sub id, +0x64 emotion id.
class StateSyncObject : public CPtred
{
public:
    char m_pad_18[4];
    int m_n1c;
    char m_pad_20[0x44];
    int m_n64;
};
MS2_CHECK_OFFSET(StateSyncObject, m_n64, 0x64);

MS2_CHECK_OFFSET(SkillData, m_nOffsetNameTag, 0x30);   // C3: the emotion skill row read below (was the row view Unk_EmoRow)

class RideOffAction : public CPtred
{
public:
    char m_pad_18[0x10];
    int m_n28;                                           // +0x28
    int m_n2c;                                           // +0x2c
};
class RideOffActionTakeLR : public RideOffAction
{
public:
    RideOffActionTakeLR(int n);                          // 0x14077f9d0
};

// Buff container of an actor.
// The knock-back direction (a POD with a declared ctor, so the return temp is not a /GS buffer).
struct Unk_SeiPoint { float x, y, z; Unk_SeiPoint(); };
class Unk_PCMove { public: Vector3 GetMoveDirection(); bool IsActionKeyPressed(int nKey); bool IsActionKeyDown(int nKey); };   // C3: view of the real class (unit_141682f80)

// Config constants singleton (FUN_1401d3200): the idle delay at +0xa00 and the idle-emotion chance at +0x29c8.
class Unk_IdleDelay { public: char m_c; };
class Unk_IdleChance { public: char m_c; };
int FUN_14025a620(class Unk_ConstVal*);   // C3: was Unk_IdleDelay::FUN_14025a620
class Unk_IdleConsts
{
public:
    char m_pad0[0xa00];
    Unk_IdleDelay m_delay;
    char m_pad1[0x29c8 - 0xa01];
    Unk_IdleChance m_chance;
};

typedef efd::utf8string Unk_AnimName;   // 0x20 bytes (ctor 0x1409989e0, dtor 0x1408a8900)

// The animation service lookup (cached actor manager of a model key) and the sequence table.
class Unk_FNAnimSvc { public: };
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();

// Casts of the actor class ids.
struct Unk_MagicRidee* FUN_141468360(struct Unk_MagicEntity*);   // C3: was FUN_141468360
class Ridee   // C3: member view for the former free stand-ins
{
public:
    class PCBase* GetRider();
};

// MyPC / PCBase non-virtual helpers (free-function form: `this` is the first argument).
// PCBase vtable view: slot 22 takes the position by value (the exe copies it into an arg slot)
class Unk_SeiSlots
{
public:
#define MS2_SEI_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_SEI_SLOTS(0, 1, 2, 3, 4) MS2_SEI_SLOTS(5, 6, 7, 8, 9) MS2_SEI_SLOTS(10, 11, 12, 13, 14)
#undef MS2_SEI_SLOTS
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual efd::Point3 vfunc_18();                                         // 18 0x14166bbe0
    virtual void vfunc_19();
    virtual efd::Point3 vfunc_20();                                         // 20 0x14166bc50
    virtual void vfunc_21();
    virtual void vfunc_22(Unk_SeiPoint kPos);                               // 22
#define MS2_SEI_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_SEI_SLOTS(23, 24, 25, 26, 27) MS2_SEI_SLOTS(28, 29, 30, 31, 32) MS2_SEI_SLOTS(33, 34, 35, 36, 37)
    MS2_SEI_SLOTS(38, 39, 40, 41, 42) MS2_SEI_SLOTS(43, 44, 45, 46, 47) MS2_SEI_SLOTS(48, 49, 50, 51, 52)
    MS2_SEI_SLOTS(53, 54, 55, 56, 57) MS2_SEI_SLOTS(58, 59, 60, 61, 62) MS2_SEI_SLOTS(63, 64, 65, 66, 67)
#undef MS2_SEI_SLOTS
    virtual bool vfunc_68(Unk_SeiPoint kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};

unsigned long GetTickCountMs2();   // C3: was FUN_140869420
class WorldService   // C3: member view for the former free stand-ins
{
public:
    class Unk_WsC_GameObj* FindNpcById(int);
    static class WorldService* GetInstance();
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
int GetRandomRange(int, int);   // C3: was GetRandomRange
unsigned FUN_140767ff0();

// ---- StateEmotionData ----

// @0x1417c3780
StateEmotionData::StateEmotionData()
{
    m_nEmotion = 0;
}

// @0x1417c37c0
StateEmotionData::StateEmotionData(long nEmotion)
{
    m_nEmotion = nEmotion;
}

// @0x1417c3810
void StateEmotionData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_n64 = m_nEmotion;
}

// @0x1417c3850
void StateEmotionData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nEmotion = p->m_n64;
}

// ---- StateEmotion ----

// @0x1417c3890
StateEmotion::StateEmotion(PCBase* pOwner) : State(pOwner)
{
    m_n10 = 0;
}

// @0x1417c3920
StateEmotion::~StateEmotion()
{
}

// @0x1417c3990
void StateEmotion::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (reinterpret_cast<PC*>(pPC)->GetHeldItem())
            reinterpret_cast<PC*>(pPC)->SendRequestCube();
    }
    m_spData2.AssignRaw(dynamic_cast<StateEmotionData*>(pData));
    if (m_spData2 == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        MS2Ptr<SkillData> spRow = TSingleton<SkillDataTableCli>::GetInstance()->GetSkillData(m_spData2->m_nEmotion);
        if (spRow == 0)
            return;
        if (reinterpret_cast<SkillData*>(spRow.operator->())->GetMainType() != 0xe)
            return;
        m_strAnim = reinterpret_cast<SkillData*>(spRow.operator->())->GetParamStr();
        reinterpret_cast<PCBase*>(m_pOwner)->FUN_141670330((float)spRow.operator->()->m_nOffsetNameTag);
        reinterpret_cast<PCBase*>(m_pOwner)->FUN_141670360((float)spRow.operator->()->m_nOffsetNameTag);
        reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166ef10(m_strAnim, 1, 0, false);
        FUN_1417b92a0();
        m_strLoop.Empty();
        if (reinterpret_cast<PCBase*>(m_pOwner)->GetEmotionAnimation((void*)&m_strAnim, m_strLoop, 0))
        {
            efd::utf8string kName(m_strLoop);
            static_cast<PCBase*>(m_pOwner)->PlayAnimation(kName, 1.0f, true, false);
        }
    }
}

// @0x1417c3cb0
void StateEmotion::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_n10 = 0;
    reinterpret_cast<PCBase*>(m_pOwner)->FUN_141670330(0.0f);
    reinterpret_cast<PCBase*>(m_pOwner)->FUN_141670360(0.0f);
    if (n != 0xf)
        reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166f8f0(0, 1);
}

// @0x1417c3d30
int StateEmotion::vfunc_22(MS2Ptr<StateSyncObject> p)
{
    if (p == 0 || m_spData2 == 0)
        return 0;
    if (m_spData2->m_nEmotion == p->m_n64)
        return 0;
    return 1;
}

// @0x1417c3e00
void StateEmotion::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    Unk_PCMove* pBuff = ((Unk_PCMove*)(reinterpret_cast<PCBase*>(pPC)->FUN_14166d240()));
    reinterpret_cast<Unk_SeiSlots*>(pPC)->vfunc_22(reinterpret_cast<const Unk_SeiPoint&>(static_cast<const Vector3&>(pBuff->GetMoveDirection())));
    if (reinterpret_cast<PCBase*>(m_pOwner)->FUN_1416749c0())
    {
        pPC->vfunc_59(2, 0, 0, 0);
    }
    else if (pBuff->IsActionKeyPressed(0x30d41))
    {
        pPC->TryUseChairOrBed(1, 0);
    }
    else if (pBuff->IsActionKeyPressed(0x30d42))
    {
        pPC->TryUseChairOrBed(2, 0);
    }
    else if (reinterpret_cast<PCBase*>(pPC)->FUN_141671a30() != 0 && pBuff->IsActionKeyDown(0x493e1))
    {
        pPC->vfunc_59(6, 0, 0x25, 0);
    }
    else if (pBuff->IsActionKeyDown(0x493e5))
    {
        pPC->vfunc_59(3, 0, 0, 0);
    }
    else
    {
        FUN_1417b9460();
    }
}

// @0x1417c3fe0
void StateEmotion::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_spData2 == 0)
        return;
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (((class CSkillSystem*)((class MyPC*)(class MyPC*)(pPC))->GetSkillSystem())->IsEmotionLearned(m_spData2->m_nEmotion, 1) == 0)
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
            return;
        }
    }
    if (m_strLoop.IsEmpty())
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        reinterpret_cast<Unk_SeiSlots*>(m_pOwner)->vfunc_68(reinterpret_cast<const Unk_SeiPoint&>(DAT_143b01a60), fTime, 0, 0, 0);
    }
}

// @0x1417c4150
void StateEmotion::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (reinterpret_cast<PCBase*>(m_pOwner)->GetEmotionAnimation((void*)&m_strAnim, m_strLoop, 1))
    {
        m_pOwner->vfunc_59(0xf, new StateEmotionIdleData(m_spData2->m_nEmotion), 0, 0);
    }
    else
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x1417c4270
bool StateEmotion::vfunc_28(MS2Ptr<StateSyncObject> p)
{
    if (m_spData2 == 0)
        return true;
    return m_spData2->m_nEmotion != p->m_n64;
}

// @0x1417c4320
int StateEmotion::FUN_1417c4320()
{
    if (m_spData2.get() != 0)
        return m_spData2->m_nEmotion;
    return 0;
}

// ---- StateTriggerEmotionData ----

// @0x1417c4370
StateTriggerEmotionData::StateTriggerEmotionData()
{
    m_nMode = 0;
    m_nFlag = 0;
    m_nValue = 0;
    m_bLoop = false;
}

// ~StateTriggerEmotionData (0x1417c5230) is implicit: an explicit empty body keeps a dead vptr store the exe does not have.

// ---- StateTriggerEmotion ----

// @0x1417c43e0
StateTriggerEmotion::StateTriggerEmotion(PCBase* pOwner)
    : State(pOwner), m_nIndex(0), m_nFlag(0), m_nMode(0), m_nDuration(0), m_nStart(0)
{
    m_n10 = 0;
    m_nIndex = 0;
    m_nFlag = 0;
}

// @0x1417c44b0
StateTriggerEmotion::~StateTriggerEmotion()
{
}

// @0x1417c4500
void StateTriggerEmotion::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (reinterpret_cast<PC*>(pPC)->GetHeldItem())
            reinterpret_cast<PC*>(pPC)->SendRequestCube();
    }
    ((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)&static_cast<class ATL::CAtlArray<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>, class ATL::CElementTraits<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>>>&>(m_aEmotions))->RemoveAll();
    m_nIndex = 0;
    m_spData2.AssignRaw(dynamic_cast<StateTriggerEmotionData*>(pData));
    if (m_spData2.get() != 0)
    {
        m_nMode = m_spData2->m_nMode;
        m_nDuration = m_spData2->m_nValue;
        ((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)&static_cast<class ATL::CAtlArray<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>, class ATL::CElementTraits<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>>>&>(m_aEmotions))->Copy(m_spData2->m_aEmotions);
        m_nFlag = m_spData2->m_nFlag;
    }
    if (m_nFlag != 0)
    {
        MyPC* pPC2 = FUN_1417b84b0();
        if (pPC2)
            reinterpret_cast<PC*>(pPC2)->FUN_141657c80(true);
    }
    if (((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)&static_cast<class ATL::CAtlArray<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>, class ATL::CElementTraits<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>>>&>(m_aEmotions))->GetCount() != 0)
    {
        efd::utf8string kName(m_aEmotions[0]);
        static_cast<PCBase*>(m_pOwner)->PlayAnimation(kName, 1.0f, m_spData2->m_bLoop, false);
    }
    m_nStart = GetTickCountMs2();
}

// @0x1417c4770
void StateTriggerEmotion::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_nFlag = 0;
}

// @0x1417c47b0
int StateTriggerEmotion::vfunc_16()
{
    return m_nFlag;
}

// @0x1417c47d0
void StateTriggerEmotion::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (m_nMode != 0)
    {
        if (GetTickCountMs2() >= (unsigned)(m_nStart + m_nDuration))
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
        }
        else
        {
            if (((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)&static_cast<class ATL::CAtlArray<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>, class ATL::CElementTraits<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>>>&>(m_aEmotions))->GetCount() != 0)
            {
                efd::utf8string kName(m_aEmotions[0]);
                static_cast<PCBase*>(m_pOwner)->PlayAnimation(kName, 1.0f, false, false);
            }
        }
    }
    else
    {
        m_nIndex = m_nIndex + 1;
        if (m_nIndex >= (int)((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)&static_cast<class ATL::CAtlArray<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>, class ATL::CElementTraits<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>>>&>(m_aEmotions))->GetCount())
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
        }
        else
        {
            efd::utf8string kName(m_aEmotions[m_nIndex]);
            static_cast<PCBase*>(m_pOwner)->PlayAnimation(kName, 1.0f, false, false);
        }
    }
}

// ---- StateDataTriggerFollowNpc ----

// @0x1417c49e0
StateDataTriggerFollowNpc::StateDataTriggerFollowNpc(long nNpc)
{
    m_nNpc = nNpc;
}

// @0x1417c4a30
void StateDataTriggerFollowNpc::vfunc_1(Unk_StateDataArg* p)
{
    p->m_n64 = m_nNpc;
}

// @0x1417c4a60
void StateDataTriggerFollowNpc::vfunc_2(Unk_StateDataArg* p)
{
    m_nNpc = p->m_n64;
}

// ---- StateTriggerFollowNpc ----

// @0x1417c4a90
StateTriggerFollowNpc::StateTriggerFollowNpc(PCBase* pOwner) : State(pOwner)
{
    m_nAnim = 0;
}

// @0x1417c4b00
StateTriggerFollowNpc::~StateTriggerFollowNpc()
{
}

// @0x1417c4b40
void StateTriggerFollowNpc::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        if (reinterpret_cast<PC*>(pPC)->GetHeldItem())
            reinterpret_cast<PC*>(pPC)->SendRequestCube();
    }
    m_spData2.AssignRaw(dynamic_cast<StateDataTriggerFollowNpc*>(pData));
    if (m_spData2 == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_nAnim = 0;
        PCBase* pNpc = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FindNpcById(m_spData2->m_nNpc));
        if (pNpc == 0)
            m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x1417c4c90
void StateTriggerFollowNpc::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pActor = m_pOwner;
    void* pRidee = ((void*)FUN_141468360((struct Unk_MagicEntity*)(m_pOwner)));
    if (pRidee)
        pActor = ((class Ridee*)(void*)(pRidee))->GetRider();
    PCBase* pNpc = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FindNpcById(m_spData2->m_nNpc));
    if (pNpc == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_pOwner->vfunc_19(reinterpret_cast<Unk_SeiSlots*>(pNpc)->vfunc_18());
        efd::Point3 kRot = reinterpret_cast<Unk_SeiSlots*>(pNpc)->vfunc_20();
        reinterpret_cast<PCBase*>(m_pOwner)->SetRotationAndTargetYaw(kRot);
        short nAnim = reinterpret_cast<CNpc*>(pNpc)->FUN_141093510();
        if (nAnim != 0 && m_nAnim != nAnim)
        {
            m_nAnim = nAnim;
            CString strAnim;
            if (m_nAnim == -2 || m_nAnim == -3)
            {
                strAnim = "Jump_Down_A";
            }
            else
            {
                NiPointer<NiActorManager> spMgr = reinterpret_cast<egmAnimation::AnimationService*>(reinterpret_cast<Unk_FNAnimSvc*>(FUN_141b6f910()))->GetActorManager(pActor->GetEntityID());
                if (spMgr)
                {
                    NiSequenceData* pSeq = spMgr->GetSequenceData(m_nAnim);
                    if (pSeq != 0)
                        strAnim = (const char*)pSeq->GetName();
                }
            }
            if (!strAnim.IsEmpty())
            {
                efd::utf8string kName(strAnim);
                static_cast<PCBase*>(m_pOwner)->PlayAnimation(kName, 1.0f, false, false);
            }
        }
    }
}

// @0x1417c4fe0
bool StateTriggerFollowNpc::vfunc_25(int n, void* p)
{
    if (!State::vfunc_25(n, p))
        return false;
    StateDataTriggerFollowNpc* pData = dynamic_cast<StateDataTriggerFollowNpc*>((StateData*)p);
    if (pData == 0)
        return false;
    if (m_spData2->m_nNpc != pData->m_nNpc)
        return false;
    return true;
}

// @0x1417c5600
MS2Ptr<StateData> StateEmotion::vfunc_27()
{
    return MS2Ptr<StateData>(new StateEmotionData);
}

// @0x1417c5680
MS2Ptr<StateData> StateTriggerEmotion::vfunc_27()
{
    return MS2Ptr<StateData>(new StateTriggerEmotionData);
}

// @0x1417c5700
MS2Ptr<StateData> StateTriggerFollowNpc::vfunc_27()
{
    return MS2Ptr<StateData>(new StateDataTriggerFollowNpc(0));
}

// @0x1417c5780
int StateEmotion::vfunc_1()
{
    return 0xb;
}

// @0x1417c5790
int StateTriggerEmotion::vfunc_1()
{
    return 0x35;
}

// @0x1417c57a0
int StateTriggerFollowNpc::vfunc_1()
{
    return 0x46;
}

// ---- StateEmotionIdleData ----

// @0x1417c5ae0
StateEmotionIdleData::StateEmotionIdleData()
{
    m_nEmotion = 0;
}

// @0x1417c5b20
StateEmotionIdleData::StateEmotionIdleData(long nEmotion)
{
    m_nEmotion = nEmotion;
}

// @0x1417c5b70
void StateEmotionIdleData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_n64 = m_nEmotion;
}

// @0x1417c5bb0
void StateEmotionIdleData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nEmotion = p->m_n64;
}

// ---- StateEmotionIdle ----

// @0x1417c5bf0
StateEmotionIdle::StateEmotionIdle(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417c5c90
StateEmotionIdle::~StateEmotionIdle()
{
}

// @0x1417c5d10
void StateEmotionIdle::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_timer.Reset();
    m_n10 = 0x6f;
    m_spData2.AssignRaw(dynamic_cast<StateEmotionIdleData*>(pData));
    if (m_spData2 == 0)
    {
        MS2_ASSERT_AT(0x3d, 0);
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        MS2Ptr<SkillData> spRow = TSingleton<SkillDataTableCli>::GetInstance()->GetSkillData(m_spData2->m_nEmotion);
        if (spRow == 0 || reinterpret_cast<SkillData*>(spRow.operator->())->GetMainType() != 0xe)
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
            return;
        }
        m_strAnim = reinterpret_cast<SkillData*>(spRow.operator->())->GetParamStr();
        reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166ef10(m_strAnim, 1, 0, false);
        reinterpret_cast<PCBase*>(m_pOwner)->FUN_141670330((float)spRow.operator->()->m_nOffsetNameTag);
        reinterpret_cast<PCBase*>(m_pOwner)->FUN_141670360((float)spRow.operator->()->m_nOffsetNameTag);
        m_strNext.Empty();
        if (reinterpret_cast<PCBase*>(m_pOwner)->GetEmotionAnimation((void*)&m_strAnim, m_strNext, 1))
        {
            efd::utf8string kName(m_strNext);
            static_cast<PCBase*>(m_pOwner)->PlayAnimation(kName, 1.0f, true, false);
        }
        FUN_1417b92a0();
    }
}

// @0x1417c6070
void StateEmotionIdle::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_spData2 == 0)
        return;
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (((class CSkillSystem*)((class MyPC*)(class MyPC*)(pPC))->GetSkillSystem())->IsEmotionLearned(m_spData2->m_nEmotion, 1) == 0)
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
            return;
        }
    }
    reinterpret_cast<Unk_SeiSlots*>(m_pOwner)->vfunc_68(reinterpret_cast<const Unk_SeiPoint&>(DAT_143b01a60), fTime, 0, 0, 0);
}

// @0x1417c61a0
void StateEmotionIdle::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_spData2 = 0;
    m_strAnim = "";
    reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166f8f0(0, 1);
    reinterpret_cast<PCBase*>(m_pOwner)->FUN_141670330(0.0f);
    reinterpret_cast<PCBase*>(m_pOwner)->FUN_141670360(0.0f);
}

// @0x1417c6230
void StateEmotionIdle::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    if (m_pOwner->vfunc_63() == 0)
        return;
    Unk_PCMove* pBuff = ((Unk_PCMove*)(reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166d240()));
    reinterpret_cast<Unk_SeiSlots*>(m_pOwner)->vfunc_22(reinterpret_cast<const Unk_SeiPoint&>(static_cast<const Vector3&>(pBuff->GetMoveDirection())));
    if (pPC != 0 && pBuff->IsActionKeyPressed(0x30d41))
    {
        egf::Entity* pEntity = reinterpret_cast<PC*>(pPC)->FUN_141659af0(1);
        if (pEntity != 0)
        {
            if (((void*)(reinterpret_cast<PCBase*>(pPC)->GetRidee())) != 0)
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
                pPC->SendRequestRideMode1(spAction);
            }
            else
            {
                pPC->TryUseChairOrBed(1, 0);
            }
        }
    }
    else if (pPC != 0 && pBuff->IsActionKeyPressed(0x30d42))
    {
        pPC->TryUseChairOrBed(2, 0);
    }
    else if (reinterpret_cast<PCBase*>(m_pOwner)->FUN_141671a30() != 0 && pBuff->IsActionKeyDown(0x493e1))
    {
        m_pOwner->vfunc_59(6, 0, 0x25, 0);
    }
    else if (reinterpret_cast<PCBase*>(m_pOwner)->FUN_1416749c0())
    {
        m_pOwner->vfunc_59(2, 0, 0, 0);
    }
    else if (pBuff->IsActionKeyDown(0x493e5))
    {
        m_pOwner->vfunc_59(3, 0, 0, 0);
    }
    else
    {
        FUN_1417b9460();
    }
    if (reinterpret_cast<PCBase*>(m_pOwner)->FUN_1416749c0())
        m_pOwner->vfunc_59(2, 0, 0, 0);
    if (m_timer.IsExpired() != 0)
    {
        m_timer.Reset();
        static unsigned s_nChance = reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_IdleConsts*)GetClientConstants())->m_chance)->Read();
        if (s_nChance >= GetRandomRange(100, 0))
        {
            unsigned nCount = 0;
            CString strTmp;
            if (reinterpret_cast<PCBase*>(m_pOwner)->GetEmotionAnimation((void*)&m_strAnim, strTmp, 2))
                nCount++;
            if (reinterpret_cast<PCBase*>(m_pOwner)->GetEmotionAnimation((void*)&m_strAnim, strTmp, 3))
                nCount++;
            if (reinterpret_cast<PCBase*>(m_pOwner)->GetEmotionAnimation((void*)&m_strAnim, strTmp, 4))
                nCount++;
            if (nCount != 0)
            {
                int nPick = FUN_140767ff0() % nCount;
                m_n10 = nPick + 0x70;
                m_strNext.Empty();
            }
        }
    }
    else if (m_timer.IsRunning() == 0)
    {
        m_timer.Start(FUN_14025a620((class Unk_ConstVal*)&((class Unk_IdleConsts*)GetClientConstants())->m_delay));
    }
}

// @0x1417c6810
void StateEmotionIdle::vfunc_9(double fTime)
{
    int nKind = 1;
    switch (m_n10)
    {
    case 0x6f:
        nKind = 1;
        break;
    case 0x70:
        nKind = 2;
        break;
    case 0x71:
        nKind = 3;
        break;
    case 0x72:
        nKind = 4;
        break;
    }
    if (reinterpret_cast<PCBase*>(m_pOwner)->GetEmotionAnimation((void*)&m_strAnim, m_strNext, nKind))
    {
        efd::utf8string kName(m_strNext);
        static_cast<PCBase*>(m_pOwner)->PlayAnimation(kName, 1.0f, false, false);
    }
}

// @0x1417c6940
void StateEmotionIdle::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (m_n10 != 0x6f)
    {
        m_n10 = 0x6f;
        m_strNext.Empty();
    }
}

// @0x1417c6990
int StateEmotionIdle::vfunc_22(MS2Ptr<StateSyncObject> p)
{
    if (p == 0)
        return 0;
    if (m_n10 == p->m_n1c)
        return 0;
    return 1;
}

// @0x1417c6a30
int StateEmotionIdle::FUN_1417c6a30()
{
    if (m_spData2.get() != 0)
        return m_spData2->m_nEmotion;
    return 0;
}

// @0x1417c6ca0
MS2Ptr<StateData> StateEmotionIdle::vfunc_27()
{
    return MS2Ptr<StateData>(new StateEmotionIdleData);
}

// @0x1417c6d20
int StateEmotionIdle::vfunc_1()
{
    return 0xf;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb71b0-0x142cb72b0 .text$yd
