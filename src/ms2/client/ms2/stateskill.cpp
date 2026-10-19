// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateSkill, the actor state of a player casting a skill:
// plays the skill's motion sequences (combo, charging and loop phases from the text keys), moves the actor with a
// CMotionController, fires the attacks (magic models, target picks), shows the casting bar and reports the cast to the
// server. Also the hit pause helper, the area target pick context and the Linear / Blink / Move motion controllers.
// See stateskill.h.
// MS2-UNIT: client\ms2\stateskill.cpp
// MS2-RANGE: 0x140103f20-0x140104310 .text$di
// MS2-RANGE: 0x1417e47d0-0x1417f6050 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateskill.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <float.h>
#include <efd/Matrix3.h>

#include "stateskill.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/placeholder/cbasecollision.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/client/ms2/motioncontroller.h"
#include "ms2/client/ms2/skillrecord.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/skillattackdata.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/magicdata.h"
#include "ms2/client/ms2/uicastingbar.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/cequipmentslotlayerinfo.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/commonresource.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/pushcontrol.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------

bool FUN_14028d470(float a, float b);                      // 0x14028d470 a == b (within epsilon)

// TSingleton<SkillDataTableCli> (placeholder/skilldatatablecli.h clashes with commonfiles' SkillDataTable).
class Unk_SsSkillTable
{
public:
    SkillAttackData* FUN_140aae660(unsigned nSkillId, unsigned short nLevel, CString strPoint);  // the attack of a cast point
};
MS2InputService* FUN_140a58540();                          // TSingleton<MS2InputService>::GetInstance
Unk_SsSkillTable* FUN_1401958b0();                         // TSingleton<SkillDataTableCli>::GetInstance


// The skill record PCBase slots 103 / 104 hand out (a CSkillRecord; the shared headers keep it opaque).
class Unk_PCBaseComp_b18 : public CSkillRecord {};

// The running projectile handle's target (a SkillTargetRecord; magicdata.h keeps Unk_MagicTag opaque).
#define SS_TARGET(spTag) reinterpret_cast<SkillTargetRecord*>((spTag).get())
#define SS_TAG(spTag) reinterpret_cast<SkillTargetRecord*>((spTag).operator->())
// CSkillRecord keeps its points as Unk_StreamPoint; the actor and the packets use efd::Point3 / Unk_StreamPoint.
#define SS_SP(pt) reinterpret_cast<const Unk_StreamPoint&>(pt)
#define SS_PT(pt) reinterpret_cast<const efd::Point3&>(pt)

// PCBase slot 98 returns the stat-scaled sequence speed (pcbase.h declares it void); called by address.
float FUN_1416718d0(PCBase* pOwner, float fSpeed);
float FUN_140a34650(float f);                              // efd::ACos (clamped)

// The state-sync record as slot 26 fills it (unit-local view: each state unit declares the fields it writes).
class Unk_StateDataArg
{
public:
    char m_pad_00[0x90];
    int m_n90;                                          // +0x90 the cast's id
    CString m_str98;                                    // +0x98 the cast's input combo
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str98, 0x98);

DWORD GetTickCountMs2();                                   // 0x140869420 the millisecond clock
int FUN_14028d260(float fTime);                            // 0x14028d260 s -> ms
float FUN_14028d280(unsigned nMs);                         // 0x14028d280 ms -> s
float FUN_141b6fe90(NiControllerSequence* pSeq, const NiFixedString& kKey, float fDivisor);   // text key time / fDivisor
int FUN_141b6ff60(NiControllerSequence* pSeq, const NiFixedString& kKey);  // the sequence has the text key
float FUN_140a53fa0(NiControllerSequence* pSeq);           // NiControllerSequence::m_fOffset
float FUN_140a53f80(NiControllerSequence* pSeq);           // NiControllerSequence::m_fFrequency
CLogString* FUN_140166440();                               // the game log, or 0

// The animation service: the actor manager of an entity.
class Unk_SsAnimSvc { public: NiActorManager* FUN_140999440(const egf::EntityID& kId); };
Unk_SsAnimSvc* FUN_141b6f910();

// TSingleton<WorldService>: the scene kind of an actor.
class Unk_SsWorld
{
public:
    void* FUN_141bd0cc0();                              // the local player (a MyPC)
    int FUN_141bd1a10(GameObject* pObject);
    Unk_WsOptional<float>* FUN_141bd9c00();             // the effect hide distance option
};
Unk_SsWorld* FUN_1403ed2d0();
UICastingBar* FUN_140ac2270(int nId);                  // the casting bar dialog
float FUN_140966f00(NiPoint3 kFrom, NiPoint3 kTo);      // the distance of two points

// The magic service: cancel the projectiles of a cast.
CMagicService* FUN_1410a7630();

// The actor's movement controller (PCBase::FUN_14166d240).
class Unk_SsMove
{
public:
    bool FUN_141682f80(int nKey);                          // the key is held
    efd::Point3 FUN_141683900();                           // the move input direction
};

// The actor's buffs: a buff blocks the kept skill effects.
int FUN_1409709d0(Unk_PCBaseBuffs* pBuffs);

// The PC / MyPC helpers the state reaches.
void FUN_141659000(PCBase* pPC, int n);                    // reset the pc's emotion
int FUN_141489940(PCBase* pPC);                            // the pc's actor kind (10: the rotation is a direction)
void FUN_141663d00(PCBase* pPC, efd::Point3 kRot);         // the pc's aim
class Unk_SsHeldItemData { public: int FUN_14053dc90(); }; // the item's skill id
class Unk_SsHeldItem { public: Unk_SsHeldItemData* FUN_140527840(); };
Unk_SsHeldItem* FUN_14165f100(MyPC* pMy);                  // the held object weapon
void FUN_14165f170(MyPC* pMy);                             // drop the held object weapon
void FUN_14165f1f0(MyPC* pMy, int a, int b);
class Unk_SsCubeControl { public: __int64 FUN_1410a67f0(); void FUN_1410a6520(); };
Unk_SsCubeControl* FUN_141662440(MyPC* pMy, int nKind);    // the controlled cube of a kind
int FUN_141092ff0(PCBase* pMount);                         // the mount is a vehicle
PCBase* FUN_140974230(GameObject* pActor);                // the actor's player character
int FUN_141793500(CString strName);                        // the voice id of a sound name
void FUN_141663be0(PCBase* pPC, const char* szSequence, float fFrequency, const NiFixedString& kKey);  // sync the pc's weapon
void FUN_14142c6c0(CKeyTable* pKeys, ATL::CAtlArray<Unk_MyPCKeyId>& aOut, unsigned nSkillId);   // the keys of a skill

// ---- statics -------------------------------------------------------------------------------------------------------

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";                       // the GameObject flag of a hit pause
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";

// ---- Unk_SkillPauseEvent ------------------------------------------------------------------------------------------

// @0x1417e47d0
Unk_SkillPauseEvent::Unk_SkillPauseEvent()
{
    m_pAttack = NULL;
    m_fStart = 0;
    m_fPending = 0;
}

// @0x1417e4810
void Unk_SkillPauseEvent::FUN_1417e4810(PCBase* pOwner, unsigned nSkillId, unsigned short nLevel, const CString& strPoint)
{
    if (m_pAttack == NULL)
    {
        SkillAttackData* pAttack = FUN_1401958b0()->FUN_140aae660(nSkillId, nLevel, strPoint);
        if (pAttack != NULL)
        {
            m_fStart = 0;
            m_pAttack = pAttack;
            if (m_fPending > 0.0f)
            {
                FUN_1417e4900(pOwner, m_fPending);
                m_fPending = 0;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1417e4810, Unk_SkillPauseEvent, FUN_1417e4810, 222, 0x3DBCDCF1);

// @0x1417e4900
void Unk_SkillPauseEvent::FUN_1417e4900(PCBase* pOwner, float fTime)
{
    if (m_pAttack == NULL)
    {
        m_fPending = fTime;
        return;
    }
    float fFps = CMainSystem::GetInstance()->GetFps();
    if (!FUN_14028d470(m_pAttack->m_pause.m_fDuration, 0) || fFps >= 30.0f)
    {
        m_fStart = fTime;
        pOwner->FUN_14123d7a0(s_strSkill, 1);
    }
    if (CameraMgr::GetInstance()->FUN_140a18070() && CameraMgr::GetInstance()->FUN_140aed0f0()
        && m_pAttack->m_pause.m_fShakeDuration > 0.0f)
    {
        CameraMgr::GetInstance()->FUN_140af0de0(MS2Ptr<CCameraEffect>(new CVibrateCameraEffect(fTime,
            fTime + m_pAttack->m_pause.m_fShakeDuration, m_pAttack->m_pause.GetShakeRate(), m_pAttack->m_pause.m_fAmp,
            0, fTime + m_pAttack->m_pause.m_fShakeDuration, 0)));
    }
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xc3))
    {
        if (TSingleton<CGameOption>::GetInstance()->FUN_140a58500()->m_bVibration
            && m_pAttack->m_pause.m_fShakeDuration > 0.0f)
        {
            FUN_140a58540()->FUN_140d8b3e0(m_pAttack->m_pause.m_fShakeDuration
                * *TSingleton<Client::Constants>::GetInstance()->GamePadRumbleMultiple.Get());
        }
    }
}
MS2_REPLACE_METHOD(0x1417e4900, Unk_SkillPauseEvent, FUN_1417e4900, 832, 0x57C56DEA);

// @0x1417e4c50
void Unk_SkillPauseEvent::FUN_1417e4c50(PCBase* pOwner)
{
    pOwner->FUN_14123d7a0(s_strSkill, 0);
    m_pAttack = NULL;
    m_fStart = 0;
    m_fPending = 0;
}
MS2_REPLACE_METHOD(0x1417e4c50, Unk_SkillPauseEvent, FUN_1417e4c50, 108, 0x2C792102);

// @0x1417e4cd0
void Unk_SkillPauseEvent::FUN_1417e4cd0(PCBase* pOwner, CSkillRecord* pRecord)
{
    if (m_pAttack != NULL)
    {
        double fNow = CMainSystem::GetInstance()->FUN_141473280();
        if (m_fStart > 0.0f)
        {
            float fFps = CMainSystem::GetInstance()->GetFps();
            float fLag = 1.0f / fFps > 0.016f ? 1.0f / fFps - 0.016f : 0.0f;
            float fDuration = m_pAttack->m_pause.m_fDuration - fLag >= 0.001f ? m_pAttack->m_pause.m_fDuration - fLag : 0.001f;
            if ((float)fNow - m_fStart > fDuration)
            {
                m_fStart = 0;
                m_pAttack = NULL;
                pOwner->FUN_14123d7a0(s_strSkill, 0);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1417e4cd0, Unk_SkillPauseEvent, FUN_1417e4cd0, 360, 0xA5023C20);

// @0x1417e4e40
int Unk_SkillPauseEvent::FUN_1417e4e40()
{
    return m_pAttack != NULL && m_fStart > 0.0f;
}
MS2_REPLACE_METHOD(0x1417e4e40, Unk_SkillPauseEvent, FUN_1417e4e40, 58, 0xA9752C44);

// ---- CFillTargetContext ------------------------------------------------------------------------------------------

// @0x1417e4e80
CFillTargetContext::CFillTargetContext()
    : m_pOwner(NULL), m_ptOwner(efd::Point3::ZERO), m_spLevel(0), m_spCollision(0)
{
    m_n60 = 0;
    m_nMotion = 0;
    m_nAttack = 0;
    m_n6c = 0;
    m_nKindFlags = 0;
    m_n84 = 0;
}

// ---- StateSkill --------------------------------------------------------------------------------------------------

// @0x1417e4f70
StateSkill::StateSkill(PCBase* pOwner)
    : State(pOwner), m_bMoved(false)
{
    m_pMotion = NULL;
    m_n14 = 0;
    m_pSequence = NULL;
    m_fSpeed = 1.0f;
    m_nRepeat = 0;
    m_nEffectId = 0;
    m_b114 = false;
    m_b115 = false;
    m_b4a = false;
    m_b116 = false;
    m_b48 = false;
    m_b49 = false;
    m_b111 = false;
    m_b112 = false;
    m_bLoop = false;
    m_b117 = false;
    m_nChainType = 0;
    m_spCharge = 0;
    m_nChargeTick = 0;
    m_bSentLoop = false;
    m_pt144 = efd::Point3::ZERO;
    m_b11c = false;
    m_b11d = false;
    m_b11e = false;
    m_nCastEnd = 0;
    m_nCastDuration = 0;
    m_nLoopEffectId = 0;
    m_nCastId = 0;
}

// @0x1417e5210
StateSkill::~StateSkill()
{
    if (m_nEffectId != 0)
    {
        CEffectService::GetInstance()->FUN_1411a6060(m_nEffectId);
        m_nEffectId = 0;
    }
    FUN_1417f1060();
    if (m_pMotion != NULL)
    {
        delete m_pMotion;
        m_pMotion = NULL;
    }
}

// The 2- and 3-argument fmt log lines (log, level, category, "format", a, b[, c]).
// @0x1417f50a0
template<class T, class U> inline void Unk_SsLog2(CLogString* log, int level, int category, const wchar_t* format,
                                                  const T& first, const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// @0x1417f53a0
template<class T, class U, class V> inline void Unk_SsLog3(CLogString* log, int level, int category, const wchar_t* format,
                                                           const T& first, const U& second, const V& third)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(third)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third), args));
}

// @0x1417e5350
void StateSkill::vfunc_4(StateData* pData)
{
    m_spRecord = m_pOwner->vfunc_103();
    State::vfunc_4(pData);
    m_fSpeed = 1.0f;
    m_nAttack = 0;
    m_nSequenceId = (unsigned)-2;
    m_n10 = 0x3a;
    m_fLoopStart = 0;
    m_nLoopSequenceId = (unsigned)-2;
    m_bCharging = false;
    m_bA5 = true;
    m_fChargeTime = 0;
    m_b111 = false;
    m_b112 = false;
    m_bLoop = false;
    m_b114 = false;
    m_b115 = false;
    m_b4a = false;
    m_b116 = false;
    m_b49 = false;
    m_b117 = false;
    m_nChainType = 0;
    m_b11c = false;
    m_b11d = false;
    m_b11e = false;
    m_spCharge = 0;
    m_nComboTick = 0;
    m_nSelfComboTick = 0;
    m_nChargingComboTick = 0;
    m_nChargingAttackTick = 0;
    m_nStartTick = GetTickCountMs2();
    m_bMove0 = true;
    m_bMove2 = true;
    m_pt144 = efd::Point3::ZERO;
    m_nLoopEffectId = 0;
    if (m_spRecord.get() == NULL)
    {
        m_pOwner->vfunc_59(1, NULL, 0, 0);
        return;
    }
    if (m_spRecord->m_spSkill->m_bBattle)
        m_pOwner->FUN_14166ce70(1);
    PCBase* pPC = FUN_1417b8370();
    if (pPC != NULL)
        FUN_141659000(pPC, 0);
    if (FUN_1417b84b0() != NULL && m_spRecord.get() != NULL && FUN_140166440() != NULL)
        Unk_SsLog2(FUN_140166440(), 0xb, 0x134, L"Start ID:{0}, level:{1}", m_spRecord->GetSkillId(), m_spRecord->GetLevel());
    m_pOwner->vfunc_22(efd::Point3(efd::Point3::ZERO));
    m_pOwner->vfunc_19(reinterpret_cast<const efd::Point3&>(m_spRecord->m_ptPos));
    if (pPC == NULL || FUN_141489940(pPC) != 10)
    {
        m_pOwner->FUN_14166d8b0(m_spRecord->m_ptRot.z);
        m_pOwner->vfunc_21(reinterpret_cast<const efd::Point3&>(m_spRecord->m_ptRot));
    }
    else
    {
        float fYaw = FUN_1417f4ea0(m_pOwner, reinterpret_cast<const efd::Point3&>(m_spRecord->m_ptRot));
        m_pOwner->FUN_14166d8b0(fYaw);
    }
    if (pPC != NULL)
        FUN_141663d00(pPC, reinterpret_cast<const efd::Point3&>(m_spRecord->m_ptRot));
    if (m_pMotion != NULL)
    {
        delete m_pMotion;
        m_pMotion = NULL;
    }
    int nMoveType = 0;
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion != NULL)
        nMoveType = pMotion->m_eMoveType;
    if (nMoveType == 0)
        m_pMotion = new CLinearMotionController;
    else if (nMoveType == 1)
        m_pMotion = new CArcMotionController;
    else if (nMoveType == 2)
        m_pMotion = new CBlinkMotionController;
    else if (nMoveType == 3)
        m_pMotion = new CMoveMotionController;
    else
    {
        m_pMotion = new CBlinkMotionController;
        MS2_ASSERT_AT(0x15e, 0);
    }
    m_pMotion->vfunc_2(reinterpret_cast<Unk_MotionData*>(m_spRecord.get()), m_pOwner);
    MyPC* pMy = FUN_1417b84b0();
    if (pMy != NULL && FUN_14165f100(pMy) != NULL && m_spRecord->m_spSkill->m_bReleaseObjectWeapon)
        FUN_14165f1f0(pMy, 0, 0);
    m_ptSentRot = m_pOwner->vfunc_20();
    m_ptSentPos = efd::Point3::ZERO;
    m_bSentCharging = false;
    m_bSentLoop = false;
    FUN_1417f0940();
    if (FUN_1417b8480() != NULL && FUN_141092ff0(FUN_1417b8480()) == 0 && m_spRecord->FUN_14175a210())
        FUN_1417f4d20();
    if (m_spRecord->m_nB0 == 0)
    {
        if (m_spRecord->m_spSkill->m_block150.m_eEnable != 0)
            m_n10 = 0x3c;
    }
    else
    {
        m_pt144 = m_pOwner->vfunc_20();
        m_n10 = 0x3b;
    }
}
MS2_REPLACE_METHOD(0x1417e5350, StateSkill, vfunc_4, 2944, 0xE394BAD4);

// @0x1417e5ee0
void StateSkill::vfunc_5(int n)
{
    if (FUN_1417b84b0() != NULL && m_spRecord.get() != NULL)
    {
        DWORD nDuration = GetTickCountMs2() - m_nStartTick;
        if (FUN_140166440() != NULL)
            Unk_SsLog3(FUN_140166440(), 0xb, 0x134, L"End ID:{0}, level:{1} duration:{2}", m_spRecord->GetSkillId(),
                m_spRecord->GetLevel(), nDuration);
    }
    m_pOwner->FUN_14166da10(1800.0f);
    m_pause.FUN_1417e4c50(m_pOwner);
    if (m_spRecord.get() != NULL)
    {
        if (!m_spRecord->FUN_141759e40())
            m_spRecord->FUN_141759fe0();
        if (m_pOwner->FUN_14166ce30() || FUN_1409709d0(m_pOwner->FUN_1416749a0()) || n == 0xd
            || m_spRecord->m_spSkill->m_bNotKeepEffect)
            FUN_1417f1060();
        FUN_1410a7630()->FUN_14146c6c0(m_spRecord->m_nCastId, 0, 0);
        CEffectService::GetInstance()->FUN_1411a69e0(m_spRecord->m_n84);
        CEffectService::GetInstance()->FUN_1411a69e0(m_spRecord->m_n88);
        for (POSITION pos = m_spRecord->m_map138.GetHeadPosition(); pos != NULL; m_spRecord->m_map138.GetNext(pos))
            CEffectService::GetInstance()->FUN_1411a69e0(m_spRecord->m_map138.GetAt(pos)->m_value);
        if (!m_spRecord->m_magics.IsEmpty())
        {
            DWORD nNow = CMainSystem::GetInstance()->FUN_1414732b0(m_pOwner);
            for (POSITION pos = m_spRecord->m_magics.GetHeadPosition(); pos != NULL; m_spRecord->m_magics.GetNext(pos))
            {
                SkillTargetRecord* pTarget = SS_TARGET(m_spRecord->m_magics.GetAt(pos).get()->FUN_141467bc0());
                m_spRecord->m_mapC0[pTarget->m_nAttack] = nNow;
            }
            FUN_1417f2b50(m_spRecord);
        }
        const CString& strEffect = m_spRecord->FUN_141759920();
        if (strEffect.GetLength() > 0)
        {
            Unk_EffectTarget kTarget;
            kTarget.m_strName = strEffect;
            kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
            kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
            kTarget.m_b31 = m_spRecord->FUN_141759a50();
            if (!FUN_1417f4bc0(kTarget))
                CEffectService::GetInstance()->FUN_1411a4a00(kTarget);
        }
        MyPC* pMy = FUN_1417b84b0();
        if (pMy != NULL)
        {
            Unk_SsHeldItem* pItem = FUN_14165f100(pMy);
            if (pItem != NULL)
            {
                int nItemSkill = pItem->FUN_140527840()->FUN_14053dc90();
                if (nItemSkill == m_spRecord->GetSkillId())
                    FUN_14165f170(pMy);
            }
            if (m_spRecord->m_spSkill->m_block150.m_eEnable != 0)
            {
                Unk_SsCubeControl* pControl = FUN_141662440(pMy, 2);
                if (pControl != NULL && pControl->FUN_1410a67f0() == m_spRecord->m_nCastId)
                    pControl->FUN_1410a6520();
            }
        }
    }
    if (n != 0x10)
        m_nChargeTick = 0;
    FUN_1417f4dc0();
    FUN_1417f1fe0();
    if (m_pt144 != efd::Point3::ZERO)
        m_pOwner->vfunc_21(m_pt144);
    FUN_1417f2a90(false);
    State::vfunc_5(n);
}
MS2_REPLACE_METHOD(0x1417e5ee0, StateSkill, vfunc_5, 1955, 0x45E38F40);

// @0x1417e6690
void StateSkill::vfunc_7(int n)
{
    if (m_spRecord.get() != NULL)
    {
        if (m_spRecord->m_spSkill->m_bNotKeepEffect)
            FUN_1417f1060();
        FUN_1410a7630()->FUN_14146c6c0(m_spRecord->m_nCastId, 0, 0);
        MyPC* pMy = FUN_1417b84b0();
        if (pMy != NULL)
        {
            Unk_SsHeldItem* pItem = FUN_14165f100(pMy);
            if (pItem != NULL && pItem->FUN_140527840()->FUN_14053dc90() == m_spRecord->GetSkillId())
                FUN_14165f170(pMy);
        }
    }
    m_pOwner->vfunc_59(n, NULL, 0, 0);
}
MS2_REPLACE_METHOD(0x1417e6690, StateSkill, vfunc_7, 294, 0xDBAE7894);

// @0x1417e67c0
int StateSkill::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    return m_bMoved;
}
MS2_REPLACE_METHOD(0x1417e67c0, StateSkill, vfunc_22, 78, 0xBF26BF16);

// @0x1417e6820
void StateSkill::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_spRecord == NULL)
        return;
    if (m_pOwner->FUN_141675ed0() == 0)
    {
        if (FUN_1417efbe0() == 0)
            FUN_1417edc20(fTime);
        if (!m_spRecord->m_magics.IsEmpty())
            FUN_1417f2b50(m_spRecord);
        FUN_1417ee120();
        FUN_1417f11d0();
        m_pause.FUN_1417e4cd0(m_pOwner, m_spRecord.get());
    }
    else
    {
        FUN_1417f4e10();
        vfunc_7(0x1b);
    }
    unsigned nNow = GetTickCountMs2();
    if (m_nCastEnd != 0 && m_nCastEnd < nNow)
        FUN_1417f27d0();
}
MS2_REPLACE_METHOD(0x1417e6820, StateSkill, vfunc_3, 359, 0x8E54A614);

// @0x1417e6990
void StateSkill::vfunc_8(double fTime)
{
    if (m_spRecord == NULL)
        return;
    MyPC* pMy = FUN_1417b84b0();
    int nOldInput = pMy->FUN_141523bc0()->FUN_141765cf0(0);
    int nOldHold = pMy->FUN_141523bc0()->FUN_141765d30(1);
    FUN_1417eeb10(false);
    FUN_1417eeb10(true);
    if (m_spRecord->m_spSkill->m_nMoveType == 2 || m_spRecord->m_spSkill->m_nMoveType == 3)
        m_pOwner->vfunc_22(static_cast<Unk_SsMove*>(m_pOwner->FUN_14166d240())->FUN_141683900());
    if (m_bA5 && m_spRecord->m_spSkill->m_bContinue && FUN_14028d470(m_fChargeTime, 0))
    {
        unsigned nOriginId = m_spRecord->m_spSkill->GetOriginId();
        ATL::CAtlArray<Unk_MyPCKeyId> aKeys;
        FUN_14142c6c0(CKeyTable::GetInstance(), aKeys, nOriginId);
        bool bHeld = false;
        m_bCharging = false;
        for (unsigned i = 0; i < aKeys.GetCount(); i++)
        {
            if (static_cast<Unk_SsMove*>(m_pOwner->FUN_14166d240())->FUN_141682f80(aKeys[i]))
            {
                bHeld = true;
                break;
            }
        }
        if (!bHeld && pMy->FUN_141523bc0()->FUN_1417674a0(1) == nOriginId)
            bHeld = true;
        if (bHeld)
        {
            bool bLoop = false;
            if (m_pSequence != NULL)
            {
                if (FUN_141b6ff60(m_pSequence, NiFixedString("loopstart")) && FUN_141b6ff60(m_pSequence, NiFixedString("loopend")))
                    bLoop = true;
            }
            if (!m_b111)
            {
                if (!pMy->FUN_141523bc0()->FUN_141765a70(m_spRecord->GetSkillId()))
                    m_bA5 = false;
                else if (bLoop)
                    m_bCharging = true;
            }
            else if (bLoop)
            {
                if (m_nRepeat < 1)
                    m_bCharging = false;
                else
                    m_bCharging = true;
            }
        }
    }
    pMy->FUN_141523bc0()->FUN_141765cf0(nOldInput);
    pMy->FUN_141523bc0()->FUN_141765d30(nOldHold);
    if (m_b111 && !m_bLoop)
    {
        CSkillRecord* pRecord = m_spRecord.get();
        if (!static_cast<Unk_SsMove*>(pMy->FUN_14166d240())->FUN_141682f80(pRecord->m_nA4))
        {
            m_bCharging = false;
            m_nRepeat = 0;
            if (m_spRecord->m_spSkill->m_blockA4.m_bDisableChargingAttackSkipFrame)
                return;
            NiActorManager* pManager = FUN_141b6f910()->FUN_140999440(m_pOwner->FUN_14123c460());
            if (pManager == NULL)
                return;
            pManager->SetTargetAnimation(m_nSequenceId, m_fSpeed, true);
            pManager->Update((float)CMainSystem::GetInstance()->FUN_141473280());
            float fOffset = FUN_140a53fa0(m_pSequence) + FUN_141b6fe90(m_pSequence, NiFixedString("charging_attack"), 1.0f)
                * (1.0f / FUN_140a53f80(m_pSequence));
            m_pSequence->SetOffset(fOffset);
            m_bLoop = true;
            m_b112 = false;
            m_b117 = false;
            m_fLoopStart = FUN_141b6fe90(m_pSequence, NiFixedString("charging_attack"), 1.0f);
            return;
        }
    }
    FUN_1417ec2f0();
    FUN_1417ed7f0();
}
MS2_REPLACE_METHOD(0x1417e6990, StateSkill, vfunc_8, 1978, 0x88EC092B);

// @0x1417e7150
int StateSkill::vfunc_18()
{
    if (!(m_spRecord == NULL) && TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xca)
        && m_spRecord->m_spSkill->m_nMoveType == 2)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1417e7150, StateSkill, vfunc_18, 119, 0xC9B98F78);

// @0x1417e71d0
void StateSkill::AnimActivated(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (eSequenceID != pkManager->GetTargetAnimation())
        return;
    if (m_pOwner->FUN_141679270(m_strSequence) != eSequenceID)
        return;
    m_pause.FUN_1417e4c50(m_pOwner);
    if (m_spRecord.get() != NULL && m_spRecord->m_n84 == 0)
    {
        const CString& strEffect = m_spRecord->FUN_1417598a0();
        if (strEffect.GetLength() > 0)
        {
            Unk_EffectTarget kTarget;
            kTarget.m_strName = strEffect;
            kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
            kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
            kTarget.m_b31 = m_spRecord->FUN_141759a50();
            if (!FUN_1417f4bc0(kTarget))
                m_spRecord->m_n84 = CEffectService::GetInstance()->FUN_1411a49c0(kTarget);
        }
    }
    m_nSequenceId = eSequenceID;
    m_pSequence = pkSeq;
    m_b111 = m_spRecord->m_spSkill->m_blockA4.m_bChargingSkill;
    m_nComboTick = FUN_14028d260(FUN_141b6fe90(m_pSequence, NiFixedString("combo"), m_fSpeed)) + m_nStartTick;
    m_nSelfComboTick = FUN_14028d260(FUN_141b6fe90(m_pSequence, NiFixedString("selfcombo"), m_fSpeed)) + m_nStartTick;
    m_nChargingComboTick = FUN_14028d260(FUN_141b6fe90(m_pSequence, NiFixedString("charging_combo"), m_fSpeed)) + m_nStartTick;
    m_nChargingAttackTick = FUN_14028d260(FUN_141b6fe90(m_pSequence, NiFixedString("charging_attack"), m_fSpeed)) + m_nStartTick;
    m_pSequence->SetOffset(FUN_140a53fa0(m_pSequence) + FUN_14028d280(m_nChargeTick) * (1.0f / FUN_140a53f80(m_pSequence)));
    FUN_1417f2150();
}
MS2_REPLACE_METHOD(0x1417e71d0, StateSkill, AnimActivated, 1155, 0x25809D4D);

// @0x1417e7660
void StateSkill::TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID, const NiFixedString& kTextKey,
    const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_spRecord == NULL || eSequenceID != pkManager->GetTargetAnimation())
        return;
    if (m_pSequence == NULL)
    {
        m_nSequenceId = eSequenceID;
        m_pSequence = pkSeq;
    }
    SkillAttackData* pAttack = m_spRecord->FUN_14175a050(m_nAttack < 0 ? 0 : m_nAttack);
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion != NULL)
    {
        CString strEffect;
        if (pMotion->m_mapTagEffects.Lookup(CString((const char*)kTextKey), strEffect))
        {
            bool bPlay = true;
            if (!m_b117)
            {
                float fKey = FUN_141b6fe90(m_pSequence, kTextKey, 1.0f);
                if (fKey != -FLT_MAX && m_bLoop)
                {
                    float fAttack = FUN_141b6fe90(m_pSequence, NiFixedString("charging_attack"), 1.0f);
                    if (fKey < fAttack)
                        bPlay = false;
                }
            }
            else
            {
                float fKey = FUN_141b6fe90(m_pSequence, kTextKey, 1.0f);
                if (fKey != -FLT_MAX)
                {
                    float fStart = FUN_141b6fe90(m_pSequence, NiFixedString("loopstart"), 1.0f);
                    if (fKey >= fStart)
                    {
                        float fEnd = FUN_141b6fe90(m_pSequence, NiFixedString("loopend"), 1.0f);
                        if (fKey <= fEnd)
                        {
                            if (m_spRecord->m_n9c != 0)
                                bPlay = false;
                        }
                        else
                            bPlay = false;
                    }
                    else
                        bPlay = false;
                }
            }
            if (bPlay)
            {
                Unk_EffectTarget kTarget;
                kTarget.m_strName = strEffect;
                kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
                kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
                if (!FUN_1417f4bc0(kTarget))
                {
                    unsigned nId = CEffectService::GetInstance()->FUN_1411a49c0(kTarget);
                    m_spRecord->m_map138.SetAt(CString((const char*)kTextKey), nId);
                }
            }
        }
    }
    PCBase* pVoicePC;
    if (kTextKey.ContainsNoCase("EventSound") && (pVoicePC = FUN_140974230(m_pOwner)) != NULL)
    {
        CString strSound((const char*)kTextKey);
        strSound = strSound.Mid(10);
        int nVoice = FUN_141793500(strSound);
        CEffectService::GetInstance()->FUN_1411a5770(nVoice, pVoicePC);
    }
    if (kTextKey == "loopstart" && (m_b117 = true, !m_bLoop))
    {
        if (m_spRecord->m_n88 != 0)
        {
            CEffectService::GetInstance()->FUN_1411a6060(m_spRecord->m_n88);
            m_spRecord->m_n88 = 0;
        }
        const CString& strLoop = m_spRecord->FUN_1417598e0();
        if (strLoop.GetLength() > 0)
        {
            Unk_EffectTarget kTarget;
            kTarget.m_strName = strLoop;
            kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
            kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
            if (!FUN_1417f4bc0(kTarget))
                m_spRecord->m_n88 = CEffectService::GetInstance()->FUN_1411a49c0(kTarget);
        }
        m_fLoopStart = FUN_141b6fe90(m_pSequence, NiFixedString("loopstart"), 1.0f);
        m_nLoopSequenceId = eSequenceID;
        m_fChargeTime = 0;
        m_b112 = false;
        m_n138 = GetTickCountMs2();
    }
    if (kTextKey == "loopend")
    {
        if (m_spRecord->m_n88 != 0)
        {
            CEffectService::GetInstance()->FUN_1411a6060(m_spRecord->m_n88);
            m_spRecord->m_n88 = 0;
        }
        m_fChargeTime = fEventTime;
        m_b117 = false;
        if (m_bCharging || m_nRepeat > 0)
        {
            if (m_nRepeat > 0)
                m_nRepeat--;
            if (FUN_1417b84b0() != NULL)
                m_pOwner->vfunc_100(m_spRecord, 1);
            PCBase* pPC = FUN_140974230(m_pOwner);
            if (pPC == NULL)
            {
                m_pOwner->FUN_14166d8b0(m_spRecord->m_ptRot.z);
                m_pOwner->vfunc_21(reinterpret_cast<const efd::Point3&>(m_spRecord->m_ptRot));
            }
            else if (FUN_141489940(pPC) == 10)
            {
                float fYaw = FUN_1417f4ea0(m_pOwner, reinterpret_cast<const efd::Point3&>(m_spRecord->m_ptRot));
                m_pOwner->FUN_14166d8b0(fYaw);
            }
            else
            {
                m_pOwner->FUN_14166d8b0(m_spRecord->m_ptRot.z);
                m_pOwner->vfunc_21(reinterpret_cast<const efd::Point3&>(m_spRecord->m_ptRot));
            }
            m_nAttack = 0;
            m_bCharging = false;
            m_bSentCharging = false;
            m_b112 = false;
            m_b117 = true;
            m_b49 = false;
            m_fSpeed = FUN_1417ec0d0(m_pOwner, m_spRecord);
            m_fLoopEnd = FUN_141b6fe90(m_pSequence, NiFixedString("loopend"), 1.0f);
            m_n134 = FUN_14028d260((m_fLoopEnd - m_fLoopStart) / m_fSpeed);
            DWORD nNow = GetTickCountMs2();
            DWORD nElapsed = nNow - m_n138;
            m_nChargeTick = FUN_1417f1a10(nElapsed, m_n134);
            m_nChargeTick = m_n134 - 5U < m_nChargeTick ? m_n134 - 5 : m_nChargeTick;
            MyPC* pMy = FUN_1417b84b0();
            if (pMy != NULL)
            {
                m_spRecord->m_n98 = 1;
                int bReady = pMy->FUN_141523bc0()->FUN_141768bd0(m_spRecord);
                unsigned nSkillId = m_spRecord->m_spSkill->GetId();
                float fCooldown = pMy->FUN_141523bc0()->FUN_141765fe0(nSkillId, 0);
                if (bReady || fCooldown <= 0.0f || m_b111)
                {
                    m_spRecord->FUN_14175a430();
                    FUN_1417f16f0(m_spRecord);
                    pMy->FUN_141523bc0()->FUN_141767990(m_spRecord->GetSkillId(), m_spRecord->GetLevel());
                    pMy->FUN_141523bc0()->FUN_141768900(m_spRecord);
                }
                else
                    FUN_1417ed740(m_spRecord);
            }
            if (m_spRecord->m_n9c == 0)
            {
                pkManager->SetTargetAnimation(m_nLoopSequenceId, m_fSpeed, true);
                pkManager->Update((float)CMainSystem::GetInstance()->FUN_141473280());
                float fOffset = FUN_140a53fa0(m_pSequence);
                float fTime = FUN_14028d280(m_nChargeTick);
                fTime = m_fLoopStart + fTime;
                float fTarget = fOffset + fTime * (1.0f / FUN_140a53f80(m_pSequence));
                m_pSequence->SetOffset(fTarget);
                PCBase* pWeaponPC = FUN_1417b8370();
                if (pWeaponPC != NULL)
                    FUN_141663be0(pWeaponPC, m_pSequence->GetName(), m_fSpeed, NiFixedString("loopstart"));
                m_nStartTick = GetTickCountMs2();
                FUN_1417f1a90();
            }
        }
    }
    MyPC* pComboPC;
    if (m_b111 && m_nRepeat == 0 && !m_bLoop && kTextKey == "charging_combo" && (pComboPC = FUN_1417b84b0()) != NULL)
    {
        CSkillRecord* pRecord = m_spRecord.get();
        if (static_cast<Unk_SsMove*>(pComboPC->FUN_14166d240())->FUN_141682f80(pRecord->m_nA4))
        {
            m_nChargeTick = FUN_1417f1a10(GetTickCountMs2(), m_nChargingComboTick);
            m_b112 = true;
            m_bLoop = true;
            m_b117 = false;
            FUN_1417ef4a0();
        }
    }
    if (m_bMove0 && kTextKey == "move0")
    {
        m_bMove0 = false;
        m_spRecord->m_fElapsed = 0;
        m_spRecord->m_fDuration = 0;
        m_spRecord->m_f80 = 0;
        float fStart = FUN_141b6fe90(m_pSequence, NiFixedString("move0"), 1.0f);
        float fEnd = FUN_141b6fe90(m_pSequence, NiFixedString("move1"), 1.0f);
        FUN_1417ec210(m_spRecord, fStart, fEnd, m_fSpeed);
    }
    else if (m_bMove2 && kTextKey == "move2")
    {
        m_bMove2 = false;
        m_spRecord->m_fElapsed = 0;
        m_spRecord->m_fDuration = 0;
        m_spRecord->m_f80 = 0;
        float fStart = FUN_141b6fe90(m_pSequence, NiFixedString("move2"), 1.0f);
        float fEnd = FUN_141b6fe90(m_pSequence, NiFixedString("move3"), 1.0f);
        FUN_1417ec210(m_spRecord, fStart, fEnd, m_fSpeed);
    }
    else
    {
        if (pAttack != NULL && kTextKey == (const char*)pAttack->m_strPoint)
        {
            if (m_b111 && !m_bLoop && m_nRepeat == 0)
            {
                m_bLoop = true;
                m_b112 = false;
            }
            FUN_1417f0f10(CMainSystem::GetInstance()->FUN_1414732b0(m_pOwner), kTextKey);
            return;
        }
        if (kTextKey == "charging_attack")
        {
            if (m_b111 && !m_bLoop && m_nRepeat == 0)
            {
                m_bLoop = true;
                m_b112 = false;
                m_b117 = false;
            }
        }
        else if (kTextKey == "combo")
        {
            if (FUN_1417f5060())
            {
                m_nChargeTick = FUN_1417f1a10(GetTickCountMs2(), m_nComboTick);
                m_b49 = true;
                m_b117 = false;
                FUN_1417ef4a0();
            }
        }
        else if (kTextKey == "inputcombo")
            m_b4a = true;
        else if (kTextKey.EqualsNoCase("endInputCombo"))
            m_b4a = false;
        else
        {
            if (pMotion != NULL && kTextKey == (const char*)pMotion->m_strSelfInputCombo)
            {
                m_b114 = true;
                return;
            }
            if (kTextKey.EqualsNoCase("endSelfInputcombo"))
                m_b115 = true;
            else if (kTextKey == "selfcombo")
            {
                m_nChargeTick = FUN_1417f1a10(GetTickCountMs2(), m_nSelfComboTick);
                m_b116 = true;
                m_b117 = false;
                FUN_1417ef4a0();
            }
            else if (kTextKey.EqualsNoCase("startAutoChangeSkill"))
            {
                m_b11c = true;
                m_b11d = false;
            }
            else if (kTextKey.EqualsNoCase("endAutoChangeSkill"))
            {
                m_b11c = false;
                m_b11d = true;
            }
            else if (kTextKey.EqualsNoCase("startLoopKeepEffect"))
                FUN_1417f1ea0();
            else if (kTextKey.EqualsNoCase("endLoopKeepEffect"))
            {
                FUN_1417f1fe0();
                FUN_1417f2030();
            }
            else if (kTextKey == "pauseEvent")
                m_pause.FUN_1417e4900(m_pOwner, fEventTime);
        }
    }
}
MS2_REPLACE_METHOD(0x1417e7660, StateSkill, TextKeyEvent, 6858, 0x17354B69);

// @0x1417e9130
void StateSkill::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (m_bCharging)
        return;
    if (m_nRepeat > 0)
        return;
    if (eSequenceID == pkManager->GetTargetAnimation())
    {
        m_b116 = true;
        m_b49 = true;
        m_b112 = true;
        m_b48 = true;
        m_bLoop = true;
        m_nAttack = 0;
        m_fStartTime = fEventTime;
    }
}
MS2_REPLACE_METHOD(0x1417e9130, StateSkill, EndOfSequence, 172, 0x613DC206);

// @0x1417e91f0
void StateSkill::vfunc_26(Unk_StateDataArg* p)
{
    State::vfunc_26(p);
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xae))
    {
        if (FUN_1417b7e40() == 0x3b)
        {
            MS2Ptr<CSkillRecord> spRecord = FUN_1417ed6f0();
            if (spRecord.get())
            {
                p->m_n90 = spRecord->m_nB0;
                p->m_str98 = spRecord->m_strB8;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1417e91f0, StateSkill, vfunc_26, 189, 0x74FB2242);

// @0x1417e92c0
int StateSkill::vfunc_15()
{
    if (m_spRecord == NULL)
        return 0;
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion == NULL)
        return 1;
    return pMotion->m_nHoldWeapon;
}
MS2_REPLACE_METHOD(0x1417e92c0, StateSkill, vfunc_15, 100, 0x94A8B998);

// @0x1417e9330
unsigned StateSkill::FUN_1417e9330()
{
    if (m_spRecord == NULL)
        return 0;
    return m_spRecord->GetSkillId();
}
MS2_REPLACE_METHOD(0x1417e9330, StateSkill, FUN_1417e9330, 69, 0xE1CA125F);

// @0x1417e9380
float StateSkill::FUN_1417e9380()
{
    return m_fSpeed;
}
MS2_REPLACE_METHOD(0x1417e9380, StateSkill, FUN_1417e9380, 19, 0xAABC9E7C);

// @0x1417e93a0
int StateSkill::FUN_1417e93a0(PCBase* pOwner, MS2Ptr<SkillLevelData> spLevel, int n60, int nAttack)
{
    for (int i = 0; i < spLevel->FUN_140804270(); i++)
    {
        Unk_SocketPtr<CFillTargetContext> spCtx(new CFillTargetContext);
        spCtx->m_pOwner = pOwner;
        spCtx->m_ptOwner = pOwner->vfunc_18();
        spCtx->m_spLevel = spLevel;
        spCtx->m_n60 = n60;
        spCtx->m_nAttack = nAttack;
        spCtx->m_nMotion = i;
        FUN_1417e95a0(spCtx);
        if (!spCtx->m_arrTargets.IsEmpty())
            return 1;
    }
    return 0;
}
MS2_REPLACE(0x1417e93a0, StateSkill::FUN_1417e93a0, 494, 0x53B86F72);

// MS2-FUNCTIONAL: slot 98 is called directly (pcbase.h declares it void; the exe returns its float).
// @0x1417ec0d0
float StateSkill::FUN_1417ec0d0(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord)
{
    if (pOwner == NULL)
        return 1.0f;
    if (spRecord == NULL)
        return 1.0f;
    SkillMotionData* pMotion = spRecord->FUN_141759830();
    if (pMotion == NULL)
        return 1.0f;
    float fSpeed = FUN_1416718d0(pOwner, pMotion->m_fSequenceSpeed);
    if (pMotion->FUN_140808000())
        fSpeed = pMotion->m_fSequenceSpeed;
    return fSpeed * 1.0f;
}
MS2_REPLACE(0x1417ec0d0, StateSkill::FUN_1417ec0d0, 304, 0xCE4B8FE0);

// @0x1417ec210
void StateSkill::FUN_1417ec210(MS2Ptr<CSkillRecord> spRecord, float fStart, float fEnd, float fSpeed)
{
    if (fStart != -FLT_MAX && fEnd != -FLT_MAX)
    {
        spRecord->m_fDuration = (fEnd - fStart) / fSpeed;
        if (spRecord->m_spSkill->m_bMovingInMovekey)
            spRecord->m_fDuration += 0.05f;
    }
}
MS2_REPLACE(0x1417ec210, StateSkill::FUN_1417ec210, 208, 0x667E6867);

// @0x1417ec2f0
void StateSkill::FUN_1417ec2f0()
{
    if (m_spRecord == NULL)
        return;
    if (!(m_ptSentRot != SS_PT(m_spRecord->m_ptRot)))
    {
        if (!(m_ptSentPos != m_pOwner->FUN_14123c360()) && m_bSentCharging == m_bCharging && m_bSentLoop == m_bLoop)
            return;
    }
    m_ptSentRot = SS_PT(m_spRecord->m_ptRot);
    m_ptSentPos = m_pOwner->FUN_14123c360();
    m_bSentCharging = m_bCharging;
    m_bSentLoop = m_bLoop;
    COutPacket packet(0x20, 0);
    packet.vfunc_o10_1(2);
    packet.vfunc_o10_4(m_spRecord->m_nCastId);
    packet.vfunc_o10_3(m_spRecord->GetSkillId());
    packet.vfunc_o10_2(m_spRecord->GetLevel());
    packet.vfunc_o10_1(m_spRecord->m_nMotion);
    packet.vfunc_o10_10(m_spRecord->m_ptPos);
    packet.vfunc_o10_10(m_spRecord->m_ptDir);
    packet.vfunc_o10_10(m_spRecord->m_ptRot);
    NiPoint3 kPos = m_pOwner->FUN_14123c360();
    packet.vfunc_o10_10(SS_SP(kPos));
    packet.vfunc_o10_0(m_bCharging);
    packet.vfunc_o10_0(m_bLoop);
    packet.vfunc_o10_5(m_spRecord->m_fCooldown);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1417ec2f0, StateSkill, FUN_1417ec2f0, 826, 0x2288ACBB);

// @0x1417ecbd0
int StateSkill::vfunc_14()
{
    if (0.0f < static_cast<CPushControl*>(m_pOwner->FUN_141675eb0())->m_fSpeed)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1417ecbd0, StateSkill, vfunc_14, 46, 0xB6DBC682);

// @0x1417ecc10
void StateSkill::FUN_1417ecc10(Unk_MagicTagPtr spTag)
{
    if (SS_TAG(spTag)->FUN_141759090() == 0)
        m_pause.FUN_1417e4810(m_pOwner, SS_TAG(spTag)->FUN_141758fb0(), SS_TAG(spTag)->FUN_141758fe0(),
            SS_TAG(spTag)->FUN_141759050()->m_strPoint);
}
MS2_REPLACE_METHOD(0x1417ecc10, StateSkill, FUN_1417ecc10, 189, 0x9A62BC2A);

// @0x1417ed6f0
MS2Ptr<CSkillRecord> StateSkill::FUN_1417ed6f0()
{
    return m_spRecord;
}
MS2_REPLACE_METHOD(0x1417ed6f0, StateSkill, FUN_1417ed6f0, 65, 0x1490D003);

// @0x1417ed740
void StateSkill::FUN_1417ed740(MS2Ptr<CSkillRecord> spRecord)
{
    m_spCharge = spRecord;
    m_spCharge->m_n9c = 1;
}
MS2_REPLACE_METHOD(0x1417ed740, StateSkill, FUN_1417ed740, 87, 0x3BB4FF37);

// @0x1417ed7a0
MS2Ptr<CSkillRecord> StateSkill::FUN_1417ed7a0()
{
    return m_spCharge;
}
MS2_REPLACE_METHOD(0x1417ed7a0, StateSkill, FUN_1417ed7a0, 65, 0x4E486D38);

// @0x1417f0ec0
float StateSkill::FUN_1417f0ec0()
{
    float fScale = 1.0f;
    if (m_spRecord == NULL)
        return 1.0f;
    return fScale;
}
MS2_REPLACE_METHOD(0x1417f0ec0, StateSkill, FUN_1417f0ec0, 70, 0x113F1B89);

// @0x1417f1a10
int StateSkill::FUN_1417f1a10(unsigned nNow, unsigned nStart)
{
    unsigned nElapsed = nNow > nStart ? nNow - nStart : 0;
    return nElapsed > 16 ? (nElapsed - 16 > 50 ? 50 : nElapsed - 16) : 0;
}
MS2_REPLACE_METHOD(0x1417f1a10, StateSkill, FUN_1417f1a10, 122, 0xD06F938A);

// @0x1417f1fe0
void StateSkill::FUN_1417f1fe0()
{
    if (m_nLoopEffectId == 0)
        return;
    CEffectService::GetInstance()->FUN_1411a6060(m_nLoopEffectId);
    m_nLoopEffectId = 0;
}
MS2_REPLACE_METHOD(0x1417f1fe0, StateSkill, FUN_1417f1fe0, 69, 0xE8F0E92B);

// @0x1417f4d20
void StateSkill::FUN_1417f4d20()
{
    Unk_EffectTarget kTarget;
    kTarget.m_strName = CommonResource::GetInstance()->m_strNpcSuperArmor;
    kTarget.m_nKind = 0;
    kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
    m_nEffectId = CEffectService::GetInstance()->FUN_1411a49c0(kTarget);
}
MS2_REPLACE_METHOD(0x1417f4d20, StateSkill, FUN_1417f4d20, 144, 0x0C85CAD8);

// @0x1417f4dc0
void StateSkill::FUN_1417f4dc0()
{
    if (m_nEffectId != 0)
    {
        CEffectService::GetInstance()->FUN_1411a6060(m_nEffectId);
        m_nEffectId = 0;
    }
}
MS2_REPLACE_METHOD(0x1417f4dc0, StateSkill, FUN_1417f4dc0, 67, 0x398B83F0);

// @0x1417f4e10
void StateSkill::FUN_1417f4e10()
{
    if (m_spRecord == NULL)
        return;
    COutPacket packet(0x20, 0);
    packet.vfunc_o10_1(4);
    packet.vfunc_o10_4(m_spRecord->m_nCastId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1417f4e10, StateSkill, FUN_1417f4e10, 134, 0x06A14881);

// The yaw (degrees, 0..360 from +y) of an euler rotation; turns the actor to it.
// @0x1417f4ea0
float StateSkill::FUN_1417f4ea0(PCBase* pOwner, efd::Point3 kRot)
{
    efd::Point3 kRad = kRot * 3.1415927f / 180.0f;
    efd::Matrix3 kMat;
    kMat.FromEulerAnglesXYZ(kRad.x, kRad.y, kRad.z);
    efd::Point3 kDir;
    kMat.GetCol(0, kDir);
    kDir.z = 0.0f;
    kDir.Unitize();
    float fCos = kDir.Dot(-efd::Point3::UNIT_Y);
    efd::Point3 kCross = kDir.UnitCross(efd::Point3::UNIT_Z);
    float fYaw = FUN_140a34650(fCos) * 180.0f / 3.1415927f;
    float fSide = kCross.Dot(efd::Point3::UNIT_Y);
    if (0.0f < fSide)
        fYaw = 360.0f - fYaw;
    efd::Point3 kYaw = efd::Point3(0.0f, 0.0f, fYaw);
    pOwner->vfunc_21(kYaw);
    return fYaw;
}
MS2_REPLACE_METHOD(0x1417f4ea0, StateSkill, FUN_1417f4ea0, 436, 0xB29DC6F7);

// @0x1417f5060
bool StateSkill::FUN_1417f5060()
{
    if (!m_b111 || (!m_b112 && m_nRepeat == 0))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1417f5060, StateSkill, FUN_1417f5060, 58, 0x514F126A);

// @0x1417f58b0
CBlinkMotionController::CBlinkMotionController()
{
}

// @0x1417f58e0
CLinearMotionController::CLinearMotionController()
{
}

// @0x1417f5910
CMoveMotionController::CMoveMotionController()
{
}

// @0x1417f5ed0
const NiRTTI* CBlinkMotionController::vfunc_1()
{
    return &ms_RTTI;
}

// @0x1417f5ee0
const NiRTTI* CLinearMotionController::vfunc_1()
{
    return &ms_RTTI;
}

// @0x1417f5ef0
const NiRTTI* CMoveMotionController::vfunc_1()
{
    return &ms_RTTI;
}

// @0x1417f5f00
int StateSkill::vfunc_1()
{
    return 0x10;
}

// @0x1417ea570
int StateSkill::FUN_1417ea570(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord, int* pResult)
{
    if (spRecord->m_spSkill->FUN_1407e9d30())
        return FUN_1417eaa50(pOwner, spRecord, pResult);
    if (spRecord->m_spSkill->FUN_1407e9bd0() != 0)
        return FUN_1417eb3a0(pOwner, spRecord, pResult);
    if (pOwner->FUN_141675ed0() != 0 && spRecord->m_spLevel->FUN_140804450())
        return 0;
    return FUN_1417ebc00(pOwner, spRecord, pResult);
}
MS2_REPLACE(0x1417ea570, StateSkill::FUN_1417ea570, 453, 0x1F6283A2);

// MS2-FUNCTIONAL: the record goes to PCBase::FUN_141673ce0 as the Unk_PCBaseComp_b18 view of the same pointer.
// @0x1417ea750
void StateSkill::FUN_1417ea750(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord)
{
    if (pOwner->FUN_14166ce30() != 0)
        return;
    if (!spRecord->m_spLevel->FUN_140804450())
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = spRecord->FUN_1417598a0();
        kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(pOwner);
        kTarget.FUN_140a53190(pOwner->FUN_14123c580());
        kTarget.m_b31 = spRecord->FUN_141759a50();
        if (!FUN_1417f4bc0(kTarget))
            CEffectService::GetInstance()->FUN_1411a4a00(kTarget);
    }
    else
    {
        if (pOwner->FUN_141673ce0(reinterpret_cast<MS2Ptr<Unk_PCBaseComp_b18>&>(spRecord)).get() != NULL)
            pOwner->vfunc_59(0x10, NULL, 0, 1);
    }
}
MS2_REPLACE(0x1417ea750, StateSkill::FUN_1417ea750, 453, 0xDBB6FA7A);

// @0x1417ea920
int StateSkill::FUN_1417ea920(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord)
{
    if (!spRecord)
        return 0;
    DWORD nNow = CMainSystem::GetInstance()->FUN_1414732b0(pOwner);
    SkillAttackData* pAttack = spRecord->FUN_14175a000();
    if (pAttack == NULL)
        return 0;
    FUN_1417ecce0(nNow, spRecord, 0, pOwner);
    FUN_1417f2b50(spRecord);
    return 1;
}
MS2_REPLACE(0x1417ea920, StateSkill::FUN_1417ea920, 296, 0xAEF0F574);

// @0x1417f0d60
void StateSkill::FUN_1417f0d60(unsigned nTick, const char* szPoint)
{
    if (m_spRecord == NULL)
        return;
    SkillAttackData* pAttack = m_spRecord->FUN_14175a050(m_nAttack);
    if (pAttack == NULL)
        return;
    if (pAttack->m_strPoint.IsEmpty())
        return;
    m_spRecord->m_nAttackIndex = m_nAttack;
    FUN_1417ecce0(nTick, m_spRecord, m_nAttack, m_pOwner);
    FUN_1417f2b50(m_spRecord);
    FUN_1417f2a90(false);
}
MS2_REPLACE_METHOD(0x1417f0d60, StateSkill, FUN_1417f0d60, 336, 0xD8EB0EE5);

// @0x1417f0f10
void StateSkill::FUN_1417f0f10(unsigned nTick, const char* szPoint)
{
    if (!(m_spRecord == NULL) && m_spRecord->m_n9c == 0)
    {
        CString strPoint;
        while (true)
        {
            SkillAttackData* pAttack = m_spRecord->FUN_14175a050(m_nAttack);
            if (pAttack == NULL || pAttack->m_strPoint.IsEmpty()
                || (!strPoint.IsEmpty() && !(strPoint == pAttack->m_strPoint)))
                break;
            strPoint = pAttack->m_strPoint;
            FUN_1417f0d60(nTick, szPoint);
            m_nAttack++;
        }
    }
}
MS2_REPLACE_METHOD(0x1417f0f10, StateSkill, FUN_1417f0f10, 315, 0xED11F6BF);

// @0x1417f1060
void StateSkill::FUN_1417f1060()
{
    if (m_spRecord == NULL)
        return;
    CEffectService::GetInstance()->FUN_1411a6060(m_spRecord->m_n84);
    CEffectService::GetInstance()->FUN_1411a6060(m_spRecord->m_n88);
    m_spRecord->m_n84 = 0;
    m_spRecord->m_n88 = 0;
    for (POSITION pos = m_spRecord->m_map138.GetHeadPosition(); pos != NULL; m_spRecord->m_map138.GetNext(pos))
    {
        ATL::CRBMap<CString, int>::CPair* pPair = m_spRecord->m_map138.GetAt(pos);
        CEffectService::GetInstance()->FUN_1411a6060(pPair->m_value);
        pPair->m_value = 0;
    }
}
MS2_REPLACE_METHOD(0x1417f1060, StateSkill, FUN_1417f1060, 349, 0x409298ED);

// @0x1417f1ea0
void StateSkill::FUN_1417f1ea0()
{
    if (m_nLoopEffectId != 0)
        return;
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion != NULL && !pMotion->m_strLoopKeepEffect.IsEmpty())
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = pMotion->m_strLoopKeepEffect;
        kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        kTarget.m_b31 = m_spRecord->FUN_141759a50();
        if (!FUN_1417f4bc0(kTarget))
            m_nLoopEffectId = CEffectService::GetInstance()->FUN_1411a49c0(kTarget);
    }
}
MS2_REPLACE_METHOD(0x1417f1ea0, StateSkill, FUN_1417f1ea0, 309, 0xA356D9CC);

// @0x1417f2030
void StateSkill::FUN_1417f2030()
{
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion != NULL && !pMotion->m_strLoopEndEffect.IsEmpty())
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = pMotion->m_strLoopEndEffect;
        kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        kTarget.m_b31 = m_spRecord->FUN_141759a50();
        if (!FUN_1417f4bc0(kTarget))
            CEffectService::GetInstance()->FUN_1411a4a00(kTarget);
    }
}
MS2_REPLACE_METHOD(0x1417f2030, StateSkill, FUN_1417f2030, 274, 0x09AB4954);

// @0x1417f2b50
void StateSkill::FUN_1417f2b50(MS2Ptr<CSkillRecord> spRecord)
{
    POSITION pos = spRecord->m_magics.GetHeadPosition();
    while (pos != NULL)
    {
        SkillTargetRecord* pTarget = SS_TARGET(spRecord->m_magics.GetAt(pos)->FUN_141467bc0());
        int nTick = 0;
        if (!spRecord->m_mapC0.Lookup(pTarget->m_nAttack, nTick))
            return;
        pTarget->m_nStartTick = nTick;
        spRecord->m_magics.GetNext(pos);
    }
    spRecord->m_magics.RemoveAll();
}
MS2_REPLACE(0x1417f2b50, StateSkill::FUN_1417f2b50, 332, 0x570297DB);

// @0x1417f2a90
void StateSkill::FUN_1417f2a90(bool bFinish)
{
    if (!FUN_1417b8560())
        return;
    UICastingBar* pBar = FUN_140ac2270(0x4e72);
    if (pBar == NULL)
        return;
    if (!pBar->vfunc_9())
        return;
    if (reinterpret_cast<Unk_CastingListener*>(static_cast<ICastingEventListener*>(this)) != pBar->FUN_1417f5e90())
        return;
    if (bFinish)
        pBar->FUN_1418e1560(1.0f);
    pBar->FUN_1418e1390();
}
MS2_REPLACE_METHOD(0x1417f2a90, StateSkill, FUN_1417f2a90, 173, 0x9B19AA5D);

// @0x1417f4bc0
bool StateSkill::FUN_1417f4bc0(Unk_EffectTarget& kTarget)
{
    if (kTarget.m_nKind != 3)
        return false;
    Unk_WsOptional<float>* pRange = FUN_1403ed2d0()->FUN_141bd9c00();
    if (!*pRange)
        return false;
    PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return false;
    GameObject* pObject = kTarget.FUN_140a533b0();
    if (pObject == NULL)
        return false;
    const NiPoint3& kPlayer = pPlayer->vfunc_18();
    const NiPoint3& kObject = pObject->vfunc_18();
    float fDistance = FUN_140966f00(kObject, kPlayer);
    return fDistance > pRange->get();
}
MS2_REPLACE(0x1417f4bc0, StateSkill::FUN_1417f4bc0, 332, 0x06769160);

// @0x1417f0070
void StateSkill::FUN_1417f0070()
{
    if (m_spRecord.get() != NULL && m_spRecord->m_nB0 != 0)
    {
        MS2Ptr<StateHoldData> spData(new StateHoldData);
        spData->m_nTargetId = m_spRecord->m_nB0;
        spData->m_strTargetName = m_spRecord->m_strB8;
        m_pOwner->vfunc_59(0x20, spData, 0, 0);
        return;
    }
    m_pOwner->vfunc_59(1, NULL, 0, 0);
}
MS2_REPLACE_METHOD(0x1417f0070, StateSkill, FUN_1417f0070, 427, 0xC0B4F0FC);

// @0x1417eeb10
void StateSkill::FUN_1417eeb10(bool bChain)
{
    if (m_spRecord == NULL)
        return;
    if (m_spRecord->FUN_141759e40() != 0)
        return;
    MS2Ptr<CSkillRecord> spNext(0);
    if (bChain && m_spRecord->m_nB0 != 0)
        spNext = FUN_1417f0230();
    else
        spNext = m_pOwner->vfunc_104(bChain, true, true);
    if (spNext == NULL)
        spNext = FUN_1417f0570(0);
    if (spNext == NULL)
        return;
    if (!FUN_1417eed70(spNext))
        return;
    m_spNext = spNext;
    if (m_nChainType != 0)
        FUN_1417ef4a0();
}
MS2_REPLACE_METHOD(0x1417eeb10, StateSkill, FUN_1417eeb10, 587, 0x2D7DDBE8);

// @0x1417efef0
int StateSkill::FUN_1417efef0()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xca))
        return 0;
    if (m_spRecord == NULL)
        return 0;
    if (m_n10 != 0x3c)
        return 0;
    if (!m_b48)
    {
        Unk_MagicModelMapPtr spModels = FUN_1410a7630()->FUN_14146c910(m_spRecord->m_nCastId);
        if (m_spRecord->m_magics.IsEmpty() && (spModels == NULL || spModels->IsEmpty()))
        {
            m_b116 = true;
            m_b49 = true;
            m_b112 = true;
            m_b48 = true;
            m_bLoop = true;
            m_nAttack = 0;
            m_fStartTime = static_cast<float>(TSingleton<CMainSystem>::GetInstance()->FUN_141473280());
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1417efef0, StateSkill, FUN_1417efef0, 373, 0x43743998);
