// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateSkill, the actor state of a player casting a skill:
// plays the skill's motion sequences (combo, charging and loop phases from the text keys), moves the actor with a
// CMotionController, fires the attacks (magic models, target picks), shows the casting bar and reports the cast to the
// server. Also the hit pause helper, the area target pick context and the Linear / Blink / Move motion controllers.
// See stateskill.h.
// MS2-UNIT: client\ms2\stateskill.cpp
// MS2-RANGE: 0x140103f20-0x140104310 .text$di
// MS2-RANGE: 0x1417e47d0-0x1417f6050 .text$mn
// MS2-PIN: ??A?$CAtlArray@V?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@ATL@@@ATL@@QEAAAEAV?$SmartPointer@VGameObject@@@efd@@_K@Z 0x1417f5e30
// MS2-PIN: ??A?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAAEAHH@Z 0x1417f5c80
// MS2-PIN: ??__Es_pointer1@@YAXXZ 0x140104040
#define NOMINMAX
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
#include "ms2/placeholder/cboxcollision.h"
#include "ms2/placeholder/cdetectcontext.h"
#include "ms2/client/ms2/skillcollisionmanager.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/uicoupleactiondialog.h"
#include "ms2/placeholder/statecoupleemotion.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/skillusepayload.h"
#include <typeinfo>
#include <NiMatrix3.h>
#include <NiColor.h>
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
#include "ms2/client/ms2/stateglide.h"
#include "ms2/client/ms2/inventory.h"
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
CLogString* GetLogString();                               // the game log, or 0

// The animation service: the actor manager of an entity.
class Unk_SsAnimSvc { public: NiActorManager* FUN_140999440(const egf::EntityID& kId); };
Unk_SsAnimSvc* FUN_141b6f910();

// TSingleton<WorldService>: the scene kind of an actor.
class Unk_SsWorld
{
public:
    void* FUN_141bd0cc0();                              // the local player (a MyPC)
    int FUN_141bd1a10(GameObject* pObject);
    void* FUN_141bd1200(int nId);                       // the field object of an id
    GameObject* FUN_141bd1180(int nId);                 // the field object of an id (a counted reference)
    void* FUN_141bd1530(__int64 nId);                   // the player of a character id
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
    bool FUN_141682fe0(int nBuffId);                       // the actor has the buff
    efd::Point3 FUN_1416836d0();                           // the move key direction
    efd::Point3 FUN_141683290();                           // the held move direction
    bool FUN_141683100(int nBuffId);                       // the buff's input was given
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
void FUN_141663be0(PCBase* pPC, const NiFixedString& kSequence, float fFrequency, const NiFixedString& kKey);  // sync the pc's weapon
void FUN_14142c6c0(CKeyTable* pKeys, ATL::CAtlArray<Unk_MyPCKeyId>& aOut, unsigned nSkillId);   // the keys of a skill

// The couple emotion checks (statecoupleemotion.cpp) and the notices.
bool FUN_140b83ec0();                                      // the couple emotions are allowed here
bool FUN_140b83f60(int nState);                            // the state allows a couple emotion
bool FUN_140b83fa0(const NiPoint3& kA, const NiPoint3& kB);  // the two actors are close enough
bool FUN_140b84dc0(const NiPoint3& kPoint);                // the point is placeable
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);  // string table text with {0}
void FUN_1412751f0(const CStringW& text, int nA, int nB);  // show a notice
void FUN_141275260(int nStringId, int nA, int nB);         // show a string table notice
void* FUN_14097a780();                                     // the buddy manager
int FUN_140ae51b0(void* pService, __int64 nActorId);       // the actor is on the block list
int FUN_141240780(Unk_PCBaseBody* pBody);                  // the body is blocked
class Unk_SsUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_SsUIManager* FUN_1403ed2b0();

CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);  // the string key's text formatted with one argument
void FUN_1418e0ad0(Unk_CastingParam* pThis, MS2Ptr<CXmlData> spXml);  // the cast arguments of a <castingBar> node

int FUN_141654700(void* pPc);                              // the pc's job

bool FUN_14028d470(float a, float b);                      // a == b (within epsilon)

int FUN_141472bc0();                                       // the client tick of a cast
Unk_UtilFloat3 FUN_141b6dff0(const Unk_UtilFloat3* pVec);  // a copy of the position
void FUN_1401fd510(unsigned char* payload, COutputStream& stream);  // write the skill use payload
void FUN_14165f130(MyPC* pMy, int n);                      // put the held object weapon away

class CNpc;
CNpc* FUN_14096e110(PCBase* pActor);                       // the npc side of an actor (null for a player)
PCBase* FUN_141468360(PCBase* pActor);                     // the player base of an actor
extern bool DAT_143ae95e0;                                 // debug: show the skill range of a pc
extern bool DAT_143ae95e1;                                 // debug: show the skill range of an npc

int FUN_141769410(PCBase* pOwner, SkillAttackData* pAttack, unsigned nSkillId);   // the attack's target count

MyPC* FUN_14096e160(PCBase* pActor);                       // the own player side of an actor (null for others)
extern Unk_Inventory DAT_143ab2a90;                        // the inventory
// The record of an item (citem.h types it Unk_ItemEquipData; the glide / ride / pet getters are CItemData's).
#define SS_ITEMDATA(spItem) reinterpret_cast<CItemData*>((spItem)->FUN_140527840())

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
    m_fZOffset = 0;
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
    if (FUN_1417b84b0() != NULL && m_spRecord.get() != NULL && GetLogString() != NULL)
        Unk_SsLog2(GetLogString(), 0xb, 0x134, L"Start ID:{0}, level:{1}", m_spRecord->GetSkillId(), m_spRecord->GetLevel());
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
        if (GetLogString() != NULL)
            Unk_SsLog3(GetLogString(), 0xb, 0x134, L"End ID:{0}, level:{1} duration:{2}", m_spRecord->GetSkillId(),
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
                CMagicModel* pMagic = m_spRecord->m_magics.GetAt(pos).get();
                SkillTargetRecord* pTarget = SS_TARGET(pMagic->FUN_141467bc0());
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
                if (pItem->FUN_140527840()->FUN_14053dc90() == m_spRecord->GetSkillId())
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
        SendSkillMode4();
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
                if (FUN_141b6ff60(m_pSequence, "loopstart") && FUN_141b6ff60(m_pSequence, "loopend"))
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
            float fOffset = FUN_140a53fa0(m_pSequence) + FUN_141b6fe90(m_pSequence, "charging_attack", 1.0f)
                * (1.0f / FUN_140a53f80(m_pSequence));
            m_pSequence->SetOffset(fOffset);
            m_bLoop = true;
            m_b112 = false;
            m_b117 = false;
            m_fLoopStart = FUN_141b6fe90(m_pSequence, "charging_attack", 1.0f);
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
    if ((bool)m_spRecord.get() && m_spRecord->m_n84 == 0)
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
    m_nComboTick = FUN_14028d260(FUN_141b6fe90(m_pSequence, "combo", m_fSpeed)) + m_nStartTick;
    m_nSelfComboTick = FUN_14028d260(FUN_141b6fe90(m_pSequence, "selfcombo", m_fSpeed)) + m_nStartTick;
    m_nChargingComboTick = FUN_14028d260(FUN_141b6fe90(m_pSequence, "charging_combo", m_fSpeed)) + m_nStartTick;
    m_nChargingAttackTick = FUN_14028d260(FUN_141b6fe90(m_pSequence, "charging_attack", m_fSpeed)) + m_nStartTick;
    float fOffset = FUN_140a53fa0(m_pSequence) + FUN_14028d280(m_nChargeTick) * (1.0f / FUN_140a53f80(m_pSequence));
    m_pSequence->SetOffset(fOffset);
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
                    float fAttack = FUN_141b6fe90(m_pSequence, "charging_attack", 1.0f);
                    if (fKey < fAttack)
                        bPlay = false;
                }
            }
            else
            {
                float fKey = FUN_141b6fe90(m_pSequence, kTextKey, 1.0f);
                if (fKey != -FLT_MAX)
                {
                    float fStart = FUN_141b6fe90(m_pSequence, "loopstart", 1.0f);
                    if (fKey >= fStart)
                    {
                        float fEnd = FUN_141b6fe90(m_pSequence, "loopend", 1.0f);
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
        m_fLoopStart = FUN_141b6fe90(m_pSequence, "loopstart", 1.0f);
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
            m_fLoopEnd = FUN_141b6fe90(m_pSequence, "loopend", 1.0f);
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
                    m_spRecord->SendSkill();
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
                    FUN_141663be0(pWeaponPC, m_pSequence->GetName(), m_fSpeed, "loopstart");
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
        float fStart = FUN_141b6fe90(m_pSequence, "move0", 1.0f);
        float fEnd = FUN_141b6fe90(m_pSequence, "move1", 1.0f);
        FUN_1417ec210(m_spRecord, fStart, fEnd, m_fSpeed);
    }
    else if (m_bMove2 && kTextKey == "move2")
    {
        m_bMove2 = false;
        m_spRecord->m_fElapsed = 0;
        m_spRecord->m_fDuration = 0;
        m_spRecord->m_f80 = 0;
        float fStart = FUN_141b6fe90(m_pSequence, "move2", 1.0f);
        float fEnd = FUN_141b6fe90(m_pSequence, "move3", 1.0f);
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
            MS2Ptr<CSkillRecord> spRecord = GetRecord();
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
float StateSkill::GetSpeed()
{
    return m_fSpeed;
}
MS2_REPLACE_METHOD(0x1417e9380, StateSkill, GetSpeed, 19, 0xAABC9E7C);

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

// The skill's area shape (CSkillCollisionManager keeps its own view of SkillLevelData).
class Unk_SkillSrc;
// CArrowFillTargetContext keeps its hit list and shape as opaque arrays / handles (magicdata.h).
typedef ATL::CAtlArray<efd::SmartPointer<GameObject> > Unk_SsTargetArray;

// @0x1417e95a0
int StateSkill::FUN_1417e95a0(Unk_SocketPtr<CFillTargetContext> spCtx)
{
    if (spCtx == NULL)
        return 0;
    spCtx->m_spCollision = CSkillCollisionManager::GetInstance()->GetCached(
        reinterpret_cast<Unk_SkillSrc*>((SkillLevelData*)spCtx->m_spLevel), spCtx->m_nMotion, spCtx->m_nAttack,
        spCtx->m_pOwner, spCtx->m_fZOffset);
    if (spCtx->m_spCollision.IsNull())
        return 0;
    SkillMotionData* pMotion = spCtx->m_spLevel->FUN_140803f00(spCtx->m_nMotion);
    if (pMotion == NULL)
        return 0;
    SkillAttackData* pAttack = spCtx->m_spLevel->FUN_140803f60(spCtx->m_nMotion, spCtx->m_nAttack);
    if (pAttack == NULL)
        return 0;
    efd::Point3 kOffset = efd::Point3::ZERO;
    efd::Point3 kHeight = efd::Point3::ZERO;
    if (spCtx->m_spLevel->FUN_1408043f0(spCtx->m_nMotion, spCtx->m_nAttack) == 0)
    {
        kOffset = pAttack->m_range.m_pt2c;
        kHeight.z = pAttack->m_range.m_f38;
        float fAngle = GameObject::FUN_14123ce70(spCtx->m_pOwner->FUN_14123cc20());
        NiMatrix3 kRot;
        kRot.MakeZRotation(fAngle + 3.1415927f);
        kOffset = kRot * kOffset;
    }
    int nSortMode = pAttack->m_nDirection;
    int bRideToRider = pAttack->m_range.m_n40;
    int nKind = pAttack->m_range.m_n44;
    if (spCtx->m_n60 != 0)
        nKind = pAttack->m_range.m_n48;
    if (spCtx->m_nKindFlags != 0)
        nKind |= spCtx->m_nKindFlags;
    MS2Ptr<CDetectContext> spDetect(new CDetectContext);
    spDetect->m_pOwner = spCtx->m_pOwner;
    spDetect->m_pRange = reinterpret_cast<Unk_DetectRange*>(pAttack);
    spDetect->m_kPos = spCtx->m_ptOwner + kOffset;
    spDetect->m_nTargetKind = nKind;
    spDetect->m_nSortMode = nSortMode;
    spDetect->m_bRideToRider = bRideToRider;
    spDetect->m_n78 = spCtx->m_nAttack;
    spDetect->m_bUseAllAnchors = spCtx->m_n84;
    NiPoint3 kPos(spCtx->m_pOwner->vfunc_20() + kHeight);
    spCtx->m_spCollision->FUN_1409fc390(spDetect, kPos);
    spCtx->m_arrTargets.Append(spDetect->m_arrTargets);
    return 1;
}
MS2_REPLACE(0x1417e95a0, StateSkill::FUN_1417e95a0, 1914, 0xDAAEFE48);

// @0x1417e9d20
int StateSkill::FUN_1417e9d20(Unk_SocketPtr<CArrowFillTargetContext> spCtx)
{
    if (spCtx == NULL)
        return 0;
    GameObject* pOwner = (GameObject*)FUN_1403ed2d0()->FUN_141bd1200(SS_TAG(spCtx->m_spOwner)->m_nOwnerId);
    if (pOwner == NULL)
        return 0;
    SkillAttackData* pAttack = SS_TAG(spCtx->m_spOwner)->FUN_141759050();
    const Unk_RangeProperty& kRange = pAttack->m_range;
    int nKind = kRange.m_n44;
    if (spCtx->m_n8C != 0)
        nKind = kRange.m_n48;
    if (spCtx->m_nA0 != 0)
        nKind |= spCtx->m_nA0;
    Unk_StreamPoint kDelta = spCtx->m_ptTo.FUN_140965c40(spCtx->m_ptFrom);
    float fLength = kDelta.FUN_140968990();
    efd::Point3 kSize = pAttack->m_arrow.m_collision;
    MS2Ptr<CBoxCollision> spBox(new CBoxCollision);
    spBox->m_ptBox = Unk_StreamPoint(kSize.x, fLength + kSize.y, kSize.z);
    efd::Point3 kAdd = pAttack->m_arrow.m_collisionAdd;
    Unk_StreamPoint ptAdd(0.0f, kAdd.y, kAdd.z);
    spBox->m_ptSize = ptAdd;
    spBox->m_kColor = NiColorA(0.0f, 0.0f, 1.0f, 1.0f);
    spBox->vfunc_4();
    int nSortMode = pAttack->m_nDirection;
    int bRideToRider = kRange.m_n40;
    MS2Ptr<CDetectContext> spDetect(new CDetectContext);
    spDetect->m_pOwner = pOwner;
    spDetect->m_pRange = reinterpret_cast<Unk_DetectRange*>(pAttack);
    spDetect->m_kPos = SS_PT(spCtx->m_ptFrom);
    spDetect->m_nTargetKind = nKind;
    spDetect->m_nSortMode = nSortMode;
    spDetect->m_bRideToRider = bRideToRider;
    spDetect->m_pExclude = (ATL::CAtlMap<unsigned int, float>*)spCtx->m_p28;
    spDetect->m_bUseAllAnchors = spCtx->m_nA4;
    spBox->FUN_1409fc540(spDetect, reinterpret_cast<const NiMatrix3&>(spCtx->m_matAim));
    reinterpret_cast<Unk_SsTargetArray&>(spCtx->m_arr30).Append(spDetect->m_arrTargets);
    reinterpret_cast<MS2Ptr<CBaseCollision>&>(spCtx->m_spVal) = spBox;
    return 1;
}
MS2_REPLACE(0x1417e9d20, StateSkill::FUN_1417e9d20, 1501, 0x89F8755C);

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
    COutPacket packet(static_cast<int>(SendOp::Skill), 0);
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

typedef ATL::CAtlArray<Unk_MagicTagPtr> Unk_SsTagArray;

// Fires one attack of a cast: shows its debug range, notes the attack's tick, picks the targets of the attack along
// the cast's direction (for a direction-rotation actor, -x turned by the rotation), starts a magic model for every
// target record and every record linked to it, then sends them (packet 0x20 mode 1) and runs the models once.
// @0x1417ecce0
void StateSkill::FUN_1417ecce0(unsigned nTick, MS2Ptr<CSkillRecord> spRecord, int nAttack, PCBase* pOwner)
{
    FUN_1417f2cb0(FUN_14028d280(nTick), spRecord, nAttack, pOwner);
    spRecord->m_mapC0[nAttack] = nTick;
    if (pOwner->vfunc_108() == 0)
        return;
    Unk_SsTagArray aTags;
    efd::Point3 kDir;
    PCBase* pPC = FUN_140974230(pOwner);
    if (pPC != NULL && FUN_141489940(pPC) == 10)
    {
        efd::Point3 kRad = SS_PT(spRecord->m_ptRot) * 3.1415927f / 180.0f;
        efd::Point3 kAxis = -efd::Point3::UNIT_X;
        efd::Matrix3 kMat;
        kMat.FromEulerAnglesXYZ(kRad.x, kRad.y, kRad.z);
        kAxis = kMat * kAxis;
        kDir = kAxis;
    }
    else
    {
        kDir = GameObject::FUN_14123cc80(reinterpret_cast<const NiPoint3&>(spRecord->m_ptRot));
    }
    FUN_1417f3180(aTags, kDir, spRecord, nAttack, pOwner);
    for (unsigned i = 0; i < aTags.GetCount(); i++)
    {
        SkillTargetRecord* pTag = reinterpret_cast<SkillTargetRecord*>(aTags[i].get());
        pTag->m_nStartTick = 0;
        Unk_SocketPtr<CMagicModel> spModel(new CMagicModel);
        spModel->FUN_141467500(Unk_MagicTagPtr(reinterpret_cast<Unk_MagicTag*>(pTag)), Unk_MagicTagPtr(0),
            SS_SP(efd::Point3::ZERO), 0, 0, 0);
        spRecord->m_magics.AddTail(spModel);
        do
        {
            SkillTargetRecord* pPrev = pTag;
            pTag = pTag->m_spLinked.get();
            bool bLinked = pTag != NULL;
            if (bLinked)
            {
                Unk_SocketPtr<CMagicModel> spLinkModel(new CMagicModel);
                spLinkModel->FUN_141467500(Unk_MagicTagPtr(reinterpret_cast<Unk_MagicTag*>(pTag)),
                    Unk_MagicTagPtr(reinterpret_cast<Unk_MagicTag*>(pPrev)), SS_SP(efd::Point3::ZERO), 0, 0, 0);
            }
        } while (pTag != NULL);
    }
    FUN_1417f2b50(spRecord);
    COutPacket packet(static_cast<int>(SendOp::Skill), 0);
    packet.Encode1(1);
    packet.Encode1(0);
    packet.Encode8(spRecord->m_nCastId);
    packet.Encode1((unsigned char)nAttack);
    packet.vfunc_o10_10(spRecord->m_ptPos);
    packet.vfunc_o10_10(SS_SP(kDir));
    packet.Encode1((unsigned char)aTags.GetCount());
    packet.Encode4(spRecord->m_nSendCount);
    for (unsigned i = 0; i < aTags.GetCount(); i++)
    {
        SkillTargetRecord* pTag = reinterpret_cast<SkillTargetRecord*>(aTags[i].get());
        packet.Encode8(pTag->m_nTagSub);
        packet.Encode4(pTag->m_nCasterId);
        packet.Encode1((unsigned char)pTag->m_n84);
        do
        {
            pTag = pTag->m_spLinked.get();
            bool bLinked = pTag != NULL;
            packet.Encode1(bLinked);
            if (bLinked)
            {
                packet.Encode8(pTag->m_nTagSub);
                packet.Encode4(pTag->m_nCasterId);
                packet.Encode1((unsigned char)pTag->m_n80);
                packet.Encode1((unsigned char)pTag->m_n84);
            }
        } while (pTag != NULL);
    }
    FUN_140710590(packet);
    for (unsigned i = 0; i < aTags.GetCount(); i++)
    {
        SkillTargetRecord* pTag = reinterpret_cast<SkillTargetRecord*>(aTags[i].get());
        if (pTag == NULL)
            continue;
        CMagicModel* pModel = FUN_1410a7630()->FUN_14146c5d0(pTag->m_nTagId, pTag->m_nTagSub).get();
        if (pModel == NULL)
            continue;
        pModel->FUN_141467860();
    }
    spRecord->m_nA0 = 1;
}
MS2_REPLACE(0x1417ecce0, StateSkill::FUN_1417ecce0, 2564, 0xE267354E);

// The charge input of a charging skill. Released before the loop: jump the motion to its charging attack key (the
// loop starts there). Pressed again after a charge: turn to the cast, restart the loop sequence at the loop start,
// sync the weapon and run the move phases.
// @0x1417ec630
void StateSkill::FUN_1417ec630(bool bCharge, bool bStart)
{
    if (m_spRecord == NULL)
        return;
    m_bCharging = bCharge;
    if (m_bCharging)
    {
        if (m_fChargeTime <= 0.0f)
            return;
        NiActorManager* pManager = FUN_141b6f910()->FUN_140999440(m_pOwner->FUN_14123c460());
        if (pManager == NULL)
            return;
        PCBase* pPC = FUN_1417b8370();
        if (pPC != NULL && FUN_141489940(pPC) == 10)
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
        m_fChargeTime = 0.0f;
        m_bCharging = false;
        m_b117 = true;
        pManager->SetTargetAnimation(m_nLoopSequenceId, m_fSpeed, true);
        pManager->Update((float)CMainSystem::GetInstance()->FUN_141473280());
        NiControllerSequence* pSequence = pManager->GetActiveSequence(m_nLoopSequenceId, true, true);
        if (pSequence == NULL)
            return;
        float fOffset = FUN_140a53fa0(pSequence) + m_fLoopStart * (1.0f / FUN_140a53f80(pSequence));
        pSequence->SetOffset(fOffset);
        FUN_1417f1a90();
        if (pPC != NULL)
            FUN_141663be0(pPC, pSequence->GetName(), m_fSpeed, "loopstart");
    }
    else
    {
        if (!m_bLoop && bStart)
        {
            NiActorManager* pManager = FUN_141b6f910()->FUN_140999440(m_pOwner->FUN_14123c460());
            if (pManager == NULL)
                return;
            unsigned nSequenceId = m_pOwner->FUN_141679270(m_strSequence);
            pManager->SetTargetAnimation(nSequenceId, m_fSpeed, true);
            pManager->Update((float)CMainSystem::GetInstance()->FUN_141473280());
            NiControllerSequence* pSequence = pManager->GetActiveSequence(nSequenceId, true, true);
            if (pSequence == NULL)
                return;
            float fOffset = FUN_140a53fa0(pSequence) + FUN_141b6fe90(pSequence, "charging_attack", 1.0f)
                * (1.0f / FUN_140a53f80(pSequence));
            pSequence->SetOffset(fOffset);
            m_bLoop = true;
            m_b112 = false;
            m_bCharging = false;
            m_nRepeat = 0;
            m_fLoopStart = FUN_141b6fe90(pSequence, "charging_attack", 1.0f);
        }
    }
}
MS2_REPLACE_METHOD(0x1417ec630, StateSkill, FUN_1417ec630, 1432, 0x65202FA4);

// @0x1417ed6f0
MS2Ptr<CSkillRecord> StateSkill::GetRecord()
{
    return m_spRecord;
}
MS2_REPLACE_METHOD(0x1417ed6f0, StateSkill, GetRecord, 65, 0x1490D003);

// @0x1417ed740
void StateSkill::FUN_1417ed740(MS2Ptr<CSkillRecord> spRecord)
{
    m_spCharge = spRecord;
    m_spCharge->m_n9c = 1;
}
MS2_REPLACE_METHOD(0x1417ed740, StateSkill, FUN_1417ed740, 87, 0x3BB4FF37);

// @0x1417ed7a0
MS2Ptr<CSkillRecord> StateSkill::GetCharge()
{
    return m_spCharge;
}
MS2_REPLACE_METHOD(0x1417ed7a0, StateSkill, GetCharge, 65, 0x4E486D38);

// The move input during a cast: the self combo / chain casts take the input direction as the push (the move key
// direction or, with CancelSwing_KeyIsDown, the held direction); a continuing skill whose key is held and a charging
// cast push nowhere. A combo cast whose key is released moves the actor and leaves the state (2 after a move input, 6
// after the cancel buff 0x493e1).
// @0x1417ed7f0
void StateSkill::FUN_1417ed7f0()
{
    if (m_spRecord == NULL)
        return;
    MyPC* pMyPC = FUN_1417b84b0();
    if (m_pOwner->vfunc_63() == 0)
        return;
    if (m_pOwner->vfunc_99(0) != 0)
        return;
    if (m_b4a || m_b114)
    {
        Unk_SsMove* pMove = static_cast<Unk_SsMove*>(m_pOwner->FUN_14166d240());
        efd::Point3 kDir;
        static int s_nCancelSwingKeyIsDown = TSingleton<Client::Constants>::GetInstance()->CancelSwing_KeyIsDown.Read();
        if (s_nCancelSwingKeyIsDown != 0)
            kDir = pMove->FUN_141683290();
        else
            kDir = pMove->FUN_1416836d0();
        if (kDir != efd::Point3::ZERO)
            m_ptPush = kDir;
        if (pMove->FUN_141683100(0x493e1))
            m_b110 = true;
    }
    if (m_spRecord->m_spSkill->m_bContinue)
    {
        CSkillRecord* pRecord = m_spRecord.operator->();
        if (static_cast<Unk_SsMove*>(pMyPC->FUN_14166d240())->FUN_141682f80(pRecord->m_nA4))
            m_ptPush = efd::Point3::ZERO;
    }
    if (m_spCharge.get() != NULL)
        m_ptPush = efd::Point3::ZERO;
    if (!m_b49 && !m_b116 && !m_b112)
        return;
    int nKey = m_spRecord->m_nA4;
    if (m_spNext.get() != NULL)
        nKey = m_spNext->m_nA4;
    if (static_cast<Unk_SsMove*>(pMyPC->FUN_14166d240())->FUN_141682f80(nKey))
        return;
    efd::Point3 kPush = m_ptPush;
    m_pOwner->vfunc_22(kPush);
    if (m_n10 != 0x3c)
    {
        if (m_b110)
        {
            SendSkillMode4();
            vfunc_7(6);
        }
        else if (m_pOwner->FUN_1416749c0())
        {
            SendSkillMode4();
            vfunc_7(2);
        }
    }
}
MS2_REPLACE_METHOD(0x1417ed7f0, StateSkill, FUN_1417ed7f0, 1061, 0x9F13DD5B);

// @0x1417f0ec0
float StateSkill::FUN_1417f0ec0()
{
    float fScale = 1.0f;
    if (m_spRecord == NULL)
        return 1.0f;
    return fScale;
}
MS2_REPLACE_METHOD(0x1417f0ec0, StateSkill, FUN_1417f0ec0, 70, 0x113F1B89);

// Releases the charging cast once its cooldown allows: a plain charge is cast from the current position, a charge of
// a continuing skill resumes the loop of the running sequence after the charge time and starts its cooldown.
// @0x1417f11d0
void StateSkill::FUN_1417f11d0()
{
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC == NULL)
        return;
    if (m_spCharge == NULL)
        return;
    int nQueued = pMyPC->FUN_141523bc0()->FUN_141768bd0(m_spCharge);
    if (nQueued != 0 || FUN_14028d470(pMyPC->FUN_141523bc0()->FUN_141765fe0(m_spCharge->GetSkillId(), 0), 0.0f))
    {
        m_spCharge->m_n9c = 0;
        if (m_spCharge->m_n98 != 0)
        {
            m_spCharge->SendSkill();
            FUN_1417f1a90();
            FUN_1417f16f0(m_spCharge);
            pMyPC->FUN_141523bc0()->FUN_141767990(m_spCharge->GetSkillId(), m_spCharge->GetLevel());
            pMyPC->FUN_141523bc0()->FUN_141768900(m_spRecord);
            NiActorManager* pManager = FUN_141b6f910()->FUN_140999440(m_pOwner->FUN_14123c460());
            if (pManager != NULL)
            {
                pManager->SetTargetAnimation(m_nLoopSequenceId, m_fSpeed, true);
                pManager->Update((float)CMainSystem::GetInstance()->FUN_141473280());
                float fOffset = FUN_140a53fa0(m_pSequence)
                    + (m_fLoopStart + FUN_14028d280(m_nChargeTick)) * (1.0f / FUN_140a53f80(m_pSequence));
                m_pSequence->SetOffset(fOffset);
                NiFixedString kLoopStart("loopstart");
                FUN_141663be0(pMyPC, m_pSequence->GetName(), m_fSpeed, kLoopStart);
            }
            m_nStartTick = GetTickCountMs2();
        }
        else
        {
            m_spCharge->m_ptPos = SS_SP(static_cast<const NiPoint3&>(pMyPC->vfunc_18()));
            m_spCharge->m_bAD = m_spCharge->m_spLevel->FUN_140804450();
            pMyPC->vfunc_102(m_spCharge);
        }
        m_spCharge = 0;
    }
}
MS2_REPLACE_METHOD(0x1417f11d0, StateSkill, FUN_1417f11d0, 1299, 0xEA9B4824);

// Starts the cooldown of a continuing skill for the rest of its loop ("loopstart".."loopend" of the sequence at the
// cast's speed, less the charge time), unless the loop was entered by the input of a chain.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417f16f0
void StateSkill::FUN_1417f16f0(MS2Ptr<CSkillRecord> spRecord)
{
    if (spRecord == NULL)
        return;
    if (m_pSequence == NULL)
        return;
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC == NULL)
        return;
    MS2Ptr<SkillData> spSkill = spRecord->m_spSkill;
    MS2Ptr<SkillLevelData> spLevel = spRecord->m_spLevel;
    if (!spSkill->m_bContinue)
        return;
    if (m_b111 && spRecord->m_n98 != 0)
        return;
    float fStart = FUN_141b6fe90(m_pSequence, "loopstart", 1.0f);
    float fEnd = FUN_141b6fe90(m_pSequence, "loopend", 1.0f);
    float fLeft = (fEnd - fStart) / GetSpeed();
    if (fLeft - FUN_14028d280(m_nChargeTick) >= 0.0f)
        fLeft = fLeft - FUN_14028d280(m_nChargeTick);
    else
        fLeft = 0.0f;
    pMyPC->FUN_141523bc0()->FUN_1417664e0(spRecord->m_nSendTick, spLevel->FUN_140803dc0(), fLeft, 0, 1);
}
MS2_REPLACE_METHOD(0x1417f16f0, StateSkill, FUN_1417f16f0, 782, 0xDA74EBE1);

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
void StateSkill::SendSkillMode4()
{
    if (m_spRecord == NULL)
        return;
    COutPacket packet(static_cast<int>(SendOp::Skill), 0);
    packet.vfunc_o10_1(4);
    packet.vfunc_o10_4(m_spRecord->m_nCastId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1417f4e10, StateSkill, SendSkillMode4, 134, 0x06A14881);

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

// Puts the party members of the own player first in a target list (only while in a party).
// @0x1417ea310
int StateSkill::FUN_1417ea310(GameObject* pOwner, Unk_SsTargetArray& aTargets)
{
    MyPC* pMy = efd::DynamicCast<MyPC>(pOwner);
    if (pMy == NULL)
        return 0;
    if (!pMy->FUN_141527280())
        return 0;
    Unk_SsTargetArray aParty;
    Unk_SsTargetArray aOther;
    for (unsigned i = 0; i < aTargets.GetCount(); i++)
    {
        GameObject* pObject = aTargets[i];
        PC* pPC = efd::DynamicCast<PC>(pObject);
        if (pPC != NULL && pMy->FUN_1415278d0(reinterpret_cast<void*>(pPC->FUN_141656a80())) != 0)
            aParty.Add(pObject);
        else
            aOther.Add(pObject);
    }
    if (!aParty.IsEmpty())
    {
        aTargets.RemoveAll();
        for (unsigned i = 0; i < aParty.GetCount(); i++)
            aTargets.Add(aParty[i]);
        for (unsigned i = 0; i < aOther.GetCount(); i++)
            aTargets.Add(aOther[i]);
    }
    return 1;
}
MS2_REPLACE(0x1417ea310, StateSkill::FUN_1417ea310, 596, 0xA8082E63);

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

// The dialog of an id as a couple action dialog (GetDialog<UICoupleActionDialog>).
// @0x1417f5780
UICoupleActionDialog* FUN_1417f5780(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UICoupleActionDialog*>((UIObject*)p);
    }
    return 0;
}
MS2_REPLACE(0x1417f5780, FUN_1417f5780, 147, 0x98A4701D);

// The special casts: a social emotion (main type 0xe, sent as packet 0x13) or a couple emotion with the partner chosen
// in the couple action dialog (main type 0xf, the state 0x3a and packet 0xa3). *pResult is set when the cast is handled.
// @0x1417eaa50
int StateSkill::FUN_1417eaa50(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord, int* pResult)
{
    Unk_PCBaseBody* pBody = pOwner->FUN_14166d220();
    efd::SmartPointer<Ridee> spRidee = pOwner->FUN_1416764a0();
    if (spRidee != NULL)
    {
        Unk_PCBaseBody* pRideeBody = spRidee->FUN_14166d220();
        if (pRideeBody != NULL)
            pBody = pRideeBody;
    }
    if (pBody != NULL && FUN_141240780(pBody))
        return 0;
    switch (spRecord->m_spSkill->GetMainType())
    {
    case 0xe:
        if (pOwner->FUN_141675ed0())
            break;
        switch (pOwner->FUN_14166c930())
        {
        case 5:
        case 8:
        case 9:
        case 0xd:
        case 0x10:
        case 0x1d:
        case 0x1e:
            return 0;
        }
        pOwner->FUN_14166ed70(spRecord->GetSkillId());
        if (spRecord->GetSkillId())
        {
            COutPacket packet(static_cast<int>(SendOp::Emote), 0);
            packet.Encode1(2);
            packet.Encode4(spRecord->GetSkillId());
            packet.vfunc_o10_6(spRecord->m_spSkill->GetParamStr());
            FUN_140710590(packet);
        }
        *pResult = 1;
        break;
    case 0xf:
    {
        MyPC* pMyPC = efd::DynamicCast<MyPC>(pOwner);
        if (pMyPC == NULL)
        {
            MS2_ASSERT_AT(0x47e, "pMyPC" && 0);
            break;
        }
        UICoupleActionDialog* pDialog = FUN_1417f5780(0x4f4e);
        if (pDialog == NULL)
        {
            MS2_ASSERT_AT(0x481, "pDialog" && 0);
            break;
        }
        __int64 nPartner = pDialog->FUN_1417f5f70();
        PCBase* pPeer = (PCBase*)FUN_1403ed2d0()->FUN_141bd1530(pDialog->FUN_1417f5f70());
        if (pPeer == NULL)
        {
            MS2_ASSERT_AT(0x486, "pPeer" && 0);
            break;
        }
        if (FUN_140ae51b0(FUN_14097a780(), nPartner) != 0)
        {
            FUN_1412751f0(FUN_14052bd00(0xcef, pPeer->vfunc_77()), 1, 1);
            break;
        }
        if (!FUN_140b83ec0())
        {
            FUN_141275260(0xced, 1, 1);
            break;
        }
        if (pMyPC->FUN_1416595d0() == 1)
        {
            FUN_141275260(0xcec, 1, 1);
            break;
        }
        if (pMyPC->FUN_141675ed0() == 1)
        {
            FUN_141275260(0xcec, 1, 1);
            break;
        }
        if (!FUN_140b83f60(pMyPC->FUN_14166c930()))
        {
            FUN_141275260(0xcec, 1, 1);
            break;
        }
        NiPoint3 kMyPos = pMyPC->vfunc_18();
        if (!FUN_140b84dc0(kMyPos))
        {
            FUN_141275260(0xcec, 1, 1);
            break;
        }
        if (!FUN_140b83fa0(kMyPos, pPeer->vfunc_18()))
        {
            FUN_1412751f0(FUN_14052bd00(0xcee, pPeer->vfunc_77()), 1, 1);
            break;
        }
        MS2Ptr<StateCoupleEmotionData> spData(new StateCoupleEmotionData);
        if (!spData)
        {
            MS2_ASSERT_AT(0x4b4, "spData" && 0);
            break;
        }
        spData->m_nEmotion = spRecord->GetSkillId();
        spData->m_nPartnerId = pPeer->FUN_14123c580();
        spData->m_nRequesterId = pMyPC->FUN_14123c580();
        spData->m_posStart = pPeer->vfunc_18();
        spData->m_posEnd = pPeer->vfunc_20();
        pMyPC->vfunc_59(0x3a, spData.get(), 0x93, 1);
        COutPacket packet(static_cast<int>(SendOp::BuddyEmote), 0);
        packet.Encode1(0);
        packet.Encode4(spRecord->GetSkillId());
        packet.Encode8(pPeer->FUN_141656a80());
        FUN_140710590(packet);
        *pResult = 1;
        break;
    }
    }
    return 0;
}
MS2_REPLACE(0x1417eaa50, StateSkill::FUN_1417eaa50, 2311, 0xEAE85E66);
// A cast that runs as a state of the own player. Kind 0x26 (use the request's item): mount a ride item, or summon
// the pet of a pet item. Kind 0x1e (glide on the request's item): glide off when already gliding on it, else start
// the glide state. Any other kind starts its own state. Both state starts are reported (packet 0x21 mode 0).
// @0x1417eb3a0
int StateSkill::FUN_1417eb3a0(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord, int* pResult)
{
    MyPC* pMy = FUN_14096e160(pOwner);
    if (pMy == NULL)
        return 0;
    pMy->FUN_14152e0c0();
    *pResult = 1;
    int nState = spRecord->m_spSkill->FUN_1407e9bd0();
    if (pMy->FUN_141527650(nState) == 0)
        return 0;
    if (nState == 0x26 && pMy->GetClassID() == 0x6200004)
    {
        if (spRecord->FUN_1417599c0() != 0)
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(spRecord->FUN_1417599c0());
            if (spItem.get() != NULL)
            {
                if (SS_ITEMDATA(spItem)->FUN_14053cc80())
                    pMy->FUN_14152ba80(spItem);
                else if (SS_ITEMDATA(spItem)->FUN_14053cc40())
                    pMy->FUN_14152aa90(spItem, 0);
            }
        }
    }
    else if (nState == 0x1e)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(spRecord->FUN_1417599c0());
        if (spItem == NULL)
            return 0;
        if (pMy->FUN_14166c930() == 0x1e)
        {
            StateGlide* pGlide = static_cast<StateGlide*>(pMy->GetStateMgr()->GetState());
            if (pGlide->GetMode() == 1 && pGlide->FUN_1417df3e0() == (int)spRecord->GetSkillId()
                && pGlide->FUN_1417c9740() == SS_ITEMDATA(spItem)->FUN_14053dde0())
            {
                pGlide->FUN_1417df370();
                return 0;
            }
        }
        MS2Ptr<StateGlideData> spData(new StateGlideData);
        spData->m_nSkill = spRecord->GetSkillId();
        spData->m_nLevel = spRecord->GetLevel();
        spData->m_n20 = SS_ITEMDATA(spItem)->FUN_14053dde0();
        pMy->vfunc_59(nState, spData.get(), 0, 1);
        COutPacket packet(static_cast<int>(SendOp::StateSkill), 0);
        packet.Encode1(0);
        packet.Encode8(spRecord->m_nCastId);
        packet.Encode4(spRecord->m_nTick);
        packet.Encode4(spRecord->GetSkillId());
        packet.Encode2(spRecord->GetLevel());
        packet.Encode4(nState);
        packet.Encode4(CMainSystem::GetInstance()->GetElapsedTime());
        packet.Encode8(spRecord->FUN_1417599c0());
        FUN_140710590(packet);
    }
    else
    {
        MS2Ptr<StateSkillData> spData(new StateSkillData);
        spData->m_nSkill = spRecord->GetSkillId();
        spData->m_nLevel = spRecord->GetLevel();
        pMy->vfunc_59(nState, spData.get(), 0, 1);
        COutPacket packet(static_cast<int>(SendOp::StateSkill), 0);
        packet.Encode1(0);
        packet.Encode8(spRecord->m_nCastId);
        packet.Encode4(spRecord->m_nTick);
        packet.Encode4(spRecord->GetSkillId());
        packet.Encode2(spRecord->GetLevel());
        packet.Encode4(nState);
        packet.Encode4(CMainSystem::GetInstance()->GetElapsedTime());
        packet.Encode8(spRecord->FUN_1417599c0());
        FUN_140710590(packet);
    }
    return 0;
}
MS2_REPLACE(0x1417eb3a0, StateSkill::FUN_1417eb3a0, 2135, 0x4FF54D4C);

// Sends the use of a cast (packet 0x20 mode 0 with the skill use payload); a held object weapon whose skill this is
// is put away.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417ebc00
int StateSkill::FUN_1417ebc00(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord, int* pResult)
{
    *pResult = 1;
    MyPC* pMyPC = efd::DynamicCast<MyPC>(pOwner);
    if (pMyPC == NULL)
        return 0;
    pMyPC->FUN_14152e0c0();
    {
        int nTick = FUN_141472bc0();
        spRecord->m_nTick = nTick;
        spRecord->m_nSendTick = spRecord->m_nTick;
        Unk_SkillUsePayload kPayload;
        kPayload.m_nCastId = spRecord->m_nCastId;
        kPayload.m_nTick = spRecord->m_nTick;
        kPayload.m_nSkillId = spRecord->GetSkillId();
        kPayload.m_nLevel = spRecord->GetLevel();
        kPayload.m_nMotion = (unsigned char)spRecord->m_nMotion;
        kPayload.m_ptPos = FUN_141b6dff0(reinterpret_cast<const Unk_UtilFloat3*>(&spRecord->m_ptPos));
        kPayload.m_ptDir = FUN_141b6dff0(reinterpret_cast<const Unk_UtilFloat3*>(&spRecord->m_ptDir));
        kPayload.m_ptRot = FUN_141b6dff0(reinterpret_cast<const Unk_UtilFloat3*>(&spRecord->m_ptRot));
        kPayload.m_fCooldown = spRecord->m_fCooldown;
        kPayload.m_nElapsed = TSingleton<CMainSystem>::GetInstance()->GetElapsedTime();
        kPayload.m_bAE = spRecord->m_bAE;
        kPayload.m_n48 = spRecord->FUN_1417599c0();
        kPayload.m_n60 = spRecord->FUN_1417599e0();
        if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xae))
        {
            kPayload.m_bAttached = spRecord->m_nB0 != 0 ? true : false;
            kPayload.m_nAttachId = spRecord->m_nB0;
            kPayload.m_strAttachNode = spRecord->m_strB8;
        }
        COutPacket packet(static_cast<int>(SendOp::Skill), 0);
        packet.vfunc_o10_1(0);
        FUN_1401fd510(reinterpret_cast<unsigned char*>(&kPayload), packet);
        FUN_140710590(packet);
        Unk_SsHeldItem* pHeld = FUN_14165f100(pMyPC);
        if (pHeld != NULL && spRecord->m_spSkill->GetMainType() == 4)
        {
            if (pHeld->FUN_140527840()->FUN_14053dc90() == spRecord->GetSkillId())
                FUN_14165f130(pMyPC, 0);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x1417ebc00, StateSkill::FUN_1417ebc00, 1186, 0x00C3144C);

// The hold attack of a cast attached to an npc (feature 0xae, buff 0x49401, job 0x46): a record of the hold attack
// skill (Constants HoldAttackSkillID, level 1) attached to the same npc node.
// @0x1417f0230
MS2Ptr<CSkillRecord> StateSkill::FUN_1417f0230()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xae))
        return MS2Ptr<CSkillRecord>(0);
    Unk_SsMove* pBuffs = static_cast<Unk_SsMove*>(m_pOwner->FUN_14166d240());
    if (!pBuffs->FUN_141682fe0(0x49401))
        return MS2Ptr<CSkillRecord>(0);
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC == NULL)
        return MS2Ptr<CSkillRecord>(0);
    if (FUN_141654700(pMyPC) != 0x46)
        return MS2Ptr<CSkillRecord>(0);
    if (m_spRecord == NULL)
        return MS2Ptr<CSkillRecord>(0);
    PCBase* pTarget = (PCBase*)FUN_1403ed2d0()->FUN_141bd1200(m_spRecord->m_nB0);
    if (pTarget == NULL)
        return MS2Ptr<CSkillRecord>(0);
    if (pTarget->GetClassID() != 0x6200028)
        return MS2Ptr<CSkillRecord>(0);
    Unk_InventorySkillRequest kReq(TSingleton<Client::Constants>::GetInstance()->HoldAttackSkillID, 1);
    MS2Ptr<CSkillRecord> spHold = pMyPC->FUN_141523bc0()->FUN_141765570(kReq);
    if (spHold == NULL)
        return MS2Ptr<CSkillRecord>(0);
    spHold->m_nB0 = m_spRecord->m_nB0;
    spHold->m_strB8 = m_spRecord->m_strB8;
    return spHold;
}
MS2_REPLACE_METHOD(0x1417f0230, StateSkill, FUN_1417f0230, 825, 0x32E08868);

// The auto change cast of the running skill (its autoChange 1 / 2 when the matching input is held, nKind 0: any):
// the record of the skill the player's buffs turn it into, unless that is the same skill and level.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417f0570
MS2Ptr<CSkillRecord> StateSkill::FUN_1417f0570(int nKind)
{
    if (m_spRecord == NULL)
        return MS2Ptr<CSkillRecord>(0);
    int nAutoChange = m_spRecord->m_spSkill->m_blockB0.m_eAutoChange;
    if (nKind != 0 && nKind != nAutoChange)
        return MS2Ptr<CSkillRecord>(0);
    if (nAutoChange == 0)
        return MS2Ptr<CSkillRecord>(0);
    if (nAutoChange == 1)
    {
        if (!m_b11c)
            return MS2Ptr<CSkillRecord>(0);
    }
    else if (nAutoChange == 2)
    {
        if (!m_b11d)
            return MS2Ptr<CSkillRecord>(0);
    }
    else
        return MS2Ptr<CSkillRecord>(0);
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC == NULL)
        return MS2Ptr<CSkillRecord>(0);
    Unk_InventorySkillRequest kReq(m_spRecord->m_spLevel->FUN_140803dc0(), 1);
    kReq.m_nLevel = m_spRecord->m_spLevel->GetLevel();
    pMyPC->FUN_141526c80(kReq.m_nSkillId, kReq.m_nLevel);
    if (kReq.m_nSkillId == m_spRecord->m_spLevel->FUN_140803dc0()
        && kReq.m_nLevel == m_spRecord->m_spLevel->GetLevel())
        return MS2Ptr<CSkillRecord>(0);
    MS2Ptr<CSkillRecord> spChange = pMyPC->FUN_141523bc0()->FUN_141765570(kReq);
    if (spChange == NULL)
        return MS2Ptr<CSkillRecord>(0);
    if (m_b11d)
        m_b11d = false;
    m_b11e = true;
    return spChange;
}
MS2_REPLACE_METHOD(0x1417f0570, StateSkill, FUN_1417f0570, 970, 0xA2CA0BB0);

// Starts the motion of the running cast: resets the chain / combo state, takes the motion's loop count and sequence
// (a charging skill of another player loops 20 more times), and plays the model's animation of it at the cast's
// speed (without blending when it is the same sequence, a delayed / non-idle motion or an immediate skill).
// @0x1417f0940
void StateSkill::FUN_1417f0940()
{
    if (m_spRecord == NULL)
        return;
    m_pSequence = NULL;
    m_spNext = 0;
    m_b48 = false;
    m_b49 = false;
    m_b4a = false;
    m_ptPush = efd::Point3::ZERO;
    m_b110 = false;
    m_b111 = false;
    m_b112 = false;
    m_bLoop = false;
    m_b114 = false;
    m_b115 = false;
    m_b116 = false;
    m_b117 = false;
    m_nChainType = 0;
    m_pause.FUN_1417e4c50(m_pOwner);
    int nRepeat = 0;
    CString strSequence("");
    bool bIdleOnEnd = true;
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion != NULL)
    {
        nRepeat = pMotion->m_nLoopCount;
        strSequence = pMotion->m_strSequenceName;
        bIdleOnEnd = pMotion->m_bDoesPlayIdleOnSkillEnd;
    }
    m_nRepeat = nRepeat;
    if (FUN_1417b84b0() == NULL && m_spRecord->m_spSkill->m_blockA4.m_bChargingSkill)
        m_nRepeat += 0x14;
    CString strName(strSequence);
    CString strAnim = m_pOwner->FUN_14166dbf0((const char*)strName);
    bool bNoBlend = m_strSequence == strAnim;
    if (pMotion->m_nStartNoneBlendDelay != 0)
        bNoBlend = true;
    if (!bIdleOnEnd)
        bNoBlend = true;
    if (m_spRecord->m_spSkill->m_eImmediateActive != 0)
        bNoBlend = true;
    m_fSpeed = FUN_1417ec0d0(m_pOwner, m_spRecord);
    m_strSequence = strAnim;
    m_pOwner->FUN_14166dd20((const char*)strName, m_fSpeed, bNoBlend, false);
}
MS2_REPLACE_METHOD(0x1417f0940, StateSkill, FUN_1417f0940, 1044, 0x0BF7F050);

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

// Arms the move phases of the cast when the sequence's "move0" / "move2" keys lie in its loop: the phase from
// "move2" to "move3" (or "move0" to "move1" for move0) when it spans the whole loop.
// @0x1417f1a90
void StateSkill::FUN_1417f1a90()
{
    if (m_spRecord == NULL)
        return;
    float fMove0 = FUN_141b6fe90(m_pSequence, "move0", 1.0f);
    float fMove2 = FUN_141b6fe90(m_pSequence, "move2", 1.0f);
    if (fMove0 == -FLT_MAX && fMove2 == -FLT_MAX)
        return;
    float fLoopStart = FUN_141b6fe90(m_pSequence, "loopstart", 1.0f);
    float fLoopEnd = FUN_141b6fe90(m_pSequence, "loopend", 1.0f);
    if (fLoopStart == -FLT_MAX || fLoopEnd == -FLT_MAX)
        return;
    bool bMove = false;
    if (fLoopStart <= fMove0 && fMove0 <= fLoopEnd)
    {
        bMove = true;
        m_bMove0 = true;
    }
    if (fLoopStart <= fMove2 && fMove2 <= fLoopEnd)
    {
        bMove = true;
        m_bMove2 = true;
    }
    if (bMove)
    {
        m_spRecord->m_fDuration = 0;
        m_spRecord->m_fElapsed = 0;
        m_spRecord->m_f80 = 0;
        float fStart = FUN_141b6fe90(m_pSequence, "move2", 1.0f);
        float fEnd = FUN_141b6fe90(m_pSequence, "move3", 1.0f);
        if (m_bMove0)
        {
            fStart = FUN_141b6fe90(m_pSequence, "move0", 1.0f);
            fEnd = FUN_141b6fe90(m_pSequence, "move1", 1.0f);
        }
        if (FUN_14028d470(fStart, fLoopStart) && FUN_14028d470(fEnd, fLoopEnd))
            FUN_1417ec210(m_spRecord, fStart, fEnd, m_fSpeed);
    }
}
MS2_REPLACE_METHOD(0x1417f1a90, StateSkill, FUN_1417f1a90, 1033, 0x395E7CBD);

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
// Times the casting bar of a cast that shows one: from the motion's casting start key to its casting end key (the
// auto change keys without them; the end of the motion without an end key), plus the charge loops of the motion,
// less 100 ms. Nothing while the bar runs a cast or this cast was shown already.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417f2150
void StateSkill::FUN_1417f2150()
{
    m_nCastDuration = 0;
    if (!FUN_1417b8560())
        return;
    UICastingBar* pBar = FUN_140ac2270(0x4e72);
    if (pBar == NULL)
        return;
    if (pBar->FUN_1417f5f90() != 0)
        return;
    if (!m_spRecord)
        return;
    if (m_spRecord->m_nCastId == m_nCastId)
        return;
    MS2Ptr<SkillData> spSkill = m_spRecord->m_spSkill;
    if (!spSkill)
        return;
    if (!spSkill->m_bShowCastingBar)
        return;
    if (m_pSequence == NULL)
        return;
    float fLoops = 0.0f;
    do
    {
        SkillMotionData* pMotion = m_spRecord->FUN_141759830();
        if (pMotion == NULL)
            break;
        int nLoopCount = pMotion->m_nLoopCount;
        if (nLoopCount == 0)
            break;
        const char* szLoopStart = "loopstart";
        const char* szLoopEnd = "loopend";
        bool bNoLoop = !FUN_141b6ff60(m_pSequence, NiFixedString(szLoopStart))
            || !FUN_141b6ff60(m_pSequence, NiFixedString(szLoopEnd));
        if (bNoLoop)
            break;
        float fLoopStart = FUN_141b6fe90(m_pSequence, NiFixedString(szLoopStart), 1.0f);
        float fLoopEnd = FUN_141b6fe90(m_pSequence, NiFixedString(szLoopEnd), 1.0f);
        fLoops = (fLoopEnd - fLoopStart) * (float)nLoopCount / m_fSpeed;
    } while (false);
    const char* szStart = FUN_141b6ff60(m_pSequence, "casting_start") ? "casting_start" : "startAutoChangeSkill";
    const char* szEnd = FUN_141b6ff60(m_pSequence, "casting_end") ? "casting_end" : "endAutoChangeSkill";
    float fStart = 0.0f;
    if (FUN_141b6ff60(m_pSequence, NiFixedString(szStart)))
        fStart = FUN_141b6fe90(m_pSequence, NiFixedString(szStart), m_fSpeed);
    float fEnd = m_pSequence->GetDuration() / m_fSpeed;
    // The exe tests the start key again before it reads the end key.
    if (FUN_141b6ff60(m_pSequence, NiFixedString(szStart)))
        fEnd = FUN_141b6fe90(m_pSequence, NiFixedString(szEnd), m_fSpeed);
    fEnd += fLoops;
    int nStart = FUN_14028d260(fStart);
    int nEnd = FUN_14028d260(fEnd) - 100;
    int nZero = 0;
    int nLast = (std::max)(nZero, nEnd);
    if (nStart >= nLast)
        return;
    m_nCastEnd = GetTickCountMs2() + nStart;
    m_nCastDuration = nLast - nStart;
}
MS2_REPLACE_METHOD(0x1417f2150, StateSkill, FUN_1417f2150, 1646, 0x0C618763);


// Shows the casting bar of the running cast ("s_action_skill_cating_progress" with the skill name, then the skill's
// <castingBar> parameters) when the cast has a casting duration.
// @0x1417f27d0
void StateSkill::FUN_1417f27d0()
{
    if (!FUN_1417b8560())
        return;
    if (!m_spRecord)
        return;
    MS2Ptr<SkillData> spSkill = m_spRecord->m_spSkill;
    if (!spSkill)
        return;
    if ((unsigned)m_nCastDuration <= 0)
        return;
    UICastingBar* pBar = FUN_140ac2270(0x4e72);
    if (pBar == NULL)
        return;
    unsigned nSkillId = spSkill->GetId();
    Unk_CastingParam kParam;
    kParam.m_nDuration = m_nCastDuration;
    kParam.m_str28 = FUN_1405c2690(CStringW(L"s_action_skill_cating_progress"), CStringTable::GetInstance()->FUN_141811980(4, nSkillId));
    FUN_1418e0ad0(&kParam, spSkill->m_spParamCastingBar);
    pBar->FUN_1418e12b0(reinterpret_cast<Unk_CastingListener*>(static_cast<ICastingEventListener*>(this)), &kParam);
    m_nCastEnd = 0;
    m_nCastDuration = 0;
    m_nCastId = m_spRecord->m_nCastId;
}
MS2_REPLACE_METHOD(0x1417f27d0, StateSkill, FUN_1417f27d0, 683, 0x607D2CF9);

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

// The debug view of an attack's range (the skill range check boxes, pc / npc): a shape of the attack placed at the
// caster along the cast's direction (shifted by the attack's range offset), handed to the collision manager.
// @0x1417f2cb0
void StateSkill::FUN_1417f2cb0(float fTime, MS2Ptr<CSkillRecord> spRecord, int nAttack, PCBase* pOwner)
{
    if (FUN_14096e110(pOwner) != NULL)
    {
        if (!DAT_143ae95e1)
            return;
    }
    else if ((FUN_140974230(pOwner) != NULL || FUN_141468360(pOwner) != NULL) && !DAT_143ae95e0)
        return;
    Unk_SsTagArray aTags;
    efd::Point3 kDir = GameObject::FUN_14123cc80(reinterpret_cast<const NiPoint3&>(spRecord->m_ptRot));
    FUN_1417f3180(aTags, kDir, spRecord, nAttack, pOwner);
    NiPoint3 kPos(SS_PT(static_cast<const NiPoint3&>(pOwner->vfunc_18())));
    NiPoint3 kTop(SS_PT(static_cast<const NiPoint3&>(pOwner->vfunc_20())));
    if (spRecord->FUN_141759f70() == 0)
    {
        efd::Point3 kOffset = SS_PT(spRecord->FUN_14175a000()->m_range.m_pt2c);
        efd::Point3 kHeight(0, 0, spRecord->FUN_14175a000()->m_range.m_f38);
        float fAngle = GameObject::FUN_14123ce70(kDir);
        NiMatrix3 kRot;
        kRot.MakeZRotation(fAngle + 3.1415927f);
        kOffset = kRot * kOffset;
        reinterpret_cast<efd::Point3&>(kPos) += kOffset;
        reinterpret_cast<efd::Point3&>(kTop) += kHeight;
    }
    MS2Ptr<CBaseCollision> spShape = CSkillCollisionManager::GetInstance()->Create(
        reinterpret_cast<Unk_SkillSrc*>((SkillLevelData*)spRecord->m_spLevel), spRecord->m_nMotion,
        spRecord->m_nAttackIndex, pOwner, 0.0f);
    if (spShape == NULL)
        return;
    spShape->m_n58 = GetTickCountMs2();
    spShape->vfunc_3(SS_SP(kPos), SS_SP(kTop), 1.0f);
    CSkillCollisionManager::GetInstance()->Add(spShape);
}
MS2_REPLACE(0x1417f2cb0, StateSkill::FUN_1417f2cb0, 1220, 0x71FD2B5D);

// Picks the targets of one attack of a cast: an area pick around the caster (unless the arrow flies without a
// target), cut to the attack's target count (an overlapping arrow fills the rest with random repeats), a hit record
// per target, a bounce chain from every record, then (for a motion without attacks) one record without a target for
// a target-less arrow, or (for one with attacks) a target-less record for every free target slot.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417f3180
void StateSkill::FUN_1417f3180(Unk_SsTagArray& aTags, const efd::Point3& kDir, MS2Ptr<CSkillRecord> spRecord,
    int nAttack, PCBase* pOwner)
{
    SkillAttackData* pAttack = spRecord->FUN_14175a050(nAttack);
    Unk_SsTargetArray aPicked;
    Unk_SsTargetArray aHits;
    if (pAttack->m_arrow.IsNonTargetOne() == 0)
    {
        Unk_SocketPtr<CFillTargetContext> spCtx(new CFillTargetContext);
        spCtx->m_pOwner = pOwner;
        spCtx->m_ptOwner = pOwner->vfunc_18();
        spCtx->m_spLevel = spRecord->m_spLevel;
        spCtx->m_n60 = 0;
        spCtx->m_nAttack = nAttack;
        spCtx->m_nMotion = spRecord->m_nMotion;
        spCtx->m_fZOffset = spRecord->FUN_141759ad0();
        if (FUN_1417e95a0(spCtx) == 0)
            return;
        aHits.Copy(spCtx->m_arrTargets);
    }
    int nLimit = FUN_141769410(pOwner, pAttack, spRecord->m_spLevel->FUN_140803dc0());
    int nCount = nLimit;
    if ((int)aHits.GetCount() <= nLimit)
        nCount = (int)aHits.GetCount();
    int nUsed = 0;
    for (int i = 0; i < nCount; i++)
    {
        nUsed++;
        aPicked.Add(aHits[i]);
    }
    if (pAttack->m_arrow.m_nOverlap != 0 && nLimit - nCount > 0 && !aHits.IsEmpty())
    {
        for (int i = 0; i < nLimit - nCount; i++)
        {
            nUsed++;
            int nPick = rand() % (int)aHits.GetCount();
            aPicked.Add(aHits[nPick]);
        }
    }
    int nHit = 0;
    for (unsigned i = 0; i < aPicked.GetCount(); i++)
    {
        Unk_MagicTagPtr spTag(reinterpret_cast<Unk_MagicTag*>(new SkillTargetRecord));
        efd::Point3 kTagDir = kDir;
        if (SS_TAG(spTag)->FUN_141758d70(spRecord->m_nCastId, pOwner->FUN_14123cec0(), pOwner->FUN_14123c580(),
                ((GameObject*)aPicked[i])->FUN_14123c580(), spRecord->GetSkillId(), spRecord->GetLevel(),
                spRecord->m_nMotion, SS_SP(kTagDir), 0, nHit, nAttack, spRecord->m_nSendCount))
        {
            aTags.Add(spTag);
            nHit++;
        }
    }
    int nBounce = pAttack->m_arrow.m_nBounceCount;
    if (nBounce > 0)
    {
        for (unsigned i = 0; i < aTags.GetCount(); i++)
        {
            ATL::CAtlList<Unk_MagicTagPtr> lstChain(10);
            lstChain.AddTail(aTags[i]);
            FUN_1417f3e80(nBounce, lstChain, spRecord, nAttack, pOwner);
        }
    }
    if (spRecord->FUN_141759f70() == 0)
    {
        if (pAttack->m_arrow.IsNonTargetOne() != 0)
        {
            Unk_MagicTagPtr spTag(reinterpret_cast<Unk_MagicTag*>(new SkillTargetRecord));
            efd::Point3 kTagDir = kDir;
            if (SS_TAG(spTag)->FUN_141758d70(spRecord->m_nCastId, pOwner->FUN_14123cec0(), pOwner->FUN_14123c580(),
                    0, spRecord->GetSkillId(), spRecord->GetLevel(), spRecord->m_nMotion, SS_SP(kTagDir), 0, 0,
                    nAttack, spRecord->m_nSendCount))
                aTags.Add(spTag);
        }
    }
    else
    {
        int nRest = nLimit - nUsed < 0 ? 0 : nLimit - nUsed;
        for (int i = 0; i < nRest; i++)
        {
            Unk_MagicTagPtr spTag(reinterpret_cast<Unk_MagicTag*>(new SkillTargetRecord));
            efd::Point3 kTagDir = kDir;
            if (SS_TAG(spTag)->FUN_141758d70(spRecord->m_nCastId, pOwner->FUN_14123cec0(), pOwner->FUN_14123c580(),
                    0, spRecord->GetSkillId(), spRecord->GetLevel(), spRecord->m_nMotion, SS_SP(kTagDir), 0, nHit,
                    nAttack, spRecord->m_nSendCount))
            {
                aTags.Add(spTag);
                nHit++;
            }
        }
    }
}
MS2_REPLACE(0x1417f3180, StateSkill::FUN_1417f3180, 3315, 0x5A426317);

// The cylinder shape (unit_141083230); only the members used here.
class CCylinderCollision : public CBaseCollision
{
public:
    CCylinderCollision();                                               // 0x141083230
    virtual ~CCylinderCollision();                                      // 0x141083320
    virtual void vfunc_5();
    virtual float vfunc_6();
    char m_pad_78[0xb0 - 0x78];
    float m_fRadius;                                                    // +0xb0
    Unk_StreamPoint m_ptCenter;                                         // +0xb4
    float m_fHeight;                                                    // +0xc0
    char m_pad_c4[4];
};
MS2_CHECK_OFFSET(CCylinderCollision, m_fHeight, 0xc0);
MS2_CHECK_SIZE(CCylinderCollision, 0xc8);

// The index of an object in a target list (-1: not in it).
// @0x1417f5710
static int FUN_1417f5710(const Unk_SsTargetArray& aTargets, const efd::SmartPointer<GameObject>& spObject)
{
    for (int i = 0; i < (int)aTargets.GetCount(); i++)
    {
        if (aTargets[i] == spObject)
            return i;
    }
    return -1;
}
MS2_REPLACE(0x1417f5710, FUN_1417f5710, 106, 0xE9D9D3F4);

// Chains one bounce of an arrow from the last record of a chain: a cylinder search (the arrow's bounce radius, 150
// high) around the last hit, without the objects already in the chain (a bounce that may overlap starts again from
// the whole search, shuffled, without the last hit); the first object left gets a record linked to the last one,
// and the chain goes on from it.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417f3e80
void StateSkill::FUN_1417f3e80(int nBounce, ATL::CAtlList<Unk_MagicTagPtr>& lstChain, MS2Ptr<CSkillRecord> spRecord,
    int nAttack, PCBase* pOwner)
{
    if (nBounce == 0)
        return;
    Unk_MagicTagPtr spLast(lstChain.GetTail());
    efd::SmartPointer<GameObject> spFrom(FUN_1403ed2d0()->FUN_141bd1180(SS_TAG(spLast)->m_nCasterId));
    if ((GameObject*)spFrom == NULL)
        return;
    efd::SmartPointer<GameObject> spSearcher(FUN_1403ed2d0()->FUN_141bd1180(SS_TAG(spLast)->m_nOwnerId));
    if ((GameObject*)spSearcher == NULL)
        return;
    CCylinderCollision kShape;
    SkillAttackData* pAttack = spRecord->FUN_14175a050(nAttack);
    kShape.m_fRadius = pAttack->m_arrow.m_fBounceRadius;
    kShape.m_fHeight = 150.0f;
    int nKind = pAttack->m_range.m_n44;
    int nType = pAttack->m_arrow.m_nBounceType;
    int nOverlap = pAttack->m_arrow.m_nBounceOverlap;
    MS2Ptr<CDetectContext> spDetect(new CDetectContext);
    spDetect->m_pOwner = spSearcher;
    spDetect->m_pRange = reinterpret_cast<Unk_DetectRange*>(pAttack);
    NiPoint3 kFrom = spFrom->vfunc_18();
    spDetect->m_kPos = SS_PT(kFrom);
    spDetect->m_nTargetKind = nKind;
    spDetect->m_nSortMode = 3;
    spDetect->m_bRideToRider = 0;
    NiPoint3 kRot(spFrom->vfunc_20());
    kShape.FUN_1409fc390(spDetect, SS_PT(kRot));
    if (nType == 2)
    {
        Unk_SsTargetArray aLeft;
        aLeft.Copy(spDetect->m_arrTargets);
        POSITION pos = lstChain.GetHeadPosition();
        while (pos != NULL)
        {
            Unk_MagicTagPtr spTag(lstChain.GetAt(pos));
            efd::SmartPointer<GameObject> spHit(FUN_1403ed2d0()->FUN_141bd1180(SS_TAG(spTag)->m_nCasterId));
            int nAt = FUN_1417f5710(aLeft, spHit);
            if (nAt != -1)
                aLeft.RemoveAt(nAt, 1);
            lstChain.GetNext(pos);
        }
        if (nOverlap == 1 && aLeft.IsEmpty())
        {
            if (spDetect->m_arrTargets.GetCount() < 2)
            {
                spDetect->m_arrTargets.RemoveAll();
            }
            else
            {
                int nLastId = 0;
                if (!lstChain.IsEmpty())
                    nLastId = SS_TAG(lstChain.GetTail())->m_nCasterId;
                lstChain.RemoveAll();
                for (unsigned i = 0; i < spDetect->m_arrTargets.GetCount(); i++)
                {
                    if (((GameObject*)spDetect->m_arrTargets[i])->FUN_14123c580() == nLastId)
                    {
                        spDetect->m_arrTargets.RemoveAt(i, 1);
                        break;
                    }
                }
                for (unsigned i = 0; i < spDetect->m_arrTargets.GetCount(); i++)
                {
                    int nPick = rand() % (int)spDetect->m_arrTargets.GetCount();
                    std::swap(spDetect->m_arrTargets[i], spDetect->m_arrTargets[nPick]);
                }
            }
        }
        else
        {
            spDetect->m_arrTargets.Copy(aLeft);
        }
    }
    else if (nType == 1 || nOverlap == 0)
    {
        POSITION pos = lstChain.GetHeadPosition();
        while (pos != NULL)
        {
            Unk_MagicTagPtr spTag(lstChain.GetAt(pos));
            efd::SmartPointer<GameObject> spHit(FUN_1403ed2d0()->FUN_141bd1180(SS_TAG(spTag)->m_nCasterId));
            int nAt = FUN_1417f5710(spDetect->m_arrTargets, spHit);
            if (nAt != -1)
                spDetect->m_arrTargets.RemoveAt(nAt, 1);
            lstChain.GetNext(pos);
        }
    }
    if (spDetect->m_arrTargets.IsEmpty())
        return;
    Unk_MagicTagPtr spNext(reinterpret_cast<Unk_MagicTag*>(new SkillTargetRecord));
    efd::SmartPointer<GameObject> spHit(spDetect->m_arrTargets[0]);
    int nStep = spRecord->FUN_14175a050(nAttack)->m_arrow.m_nBounceCount - nBounce + 1;
    efd::Point3 kDir = SS_PT(SS_TAG(spLast)->m_ptDir);
    if (!SS_TAG(spNext)->FUN_141758d70(spRecord->m_nCastId, pOwner->FUN_14123cec0(), pOwner->FUN_14123c580(),
            ((GameObject*)spHit)->FUN_14123c580(), spRecord->GetSkillId(), spRecord->GetLevel(), spRecord->m_nMotion,
            SS_SP(kDir), nStep, 0, nAttack, spRecord->m_nSendCount))
        return;
    reinterpret_cast<Unk_MagicTagPtr&>(SS_TAG(spLast)->m_spLinked) = spNext;
    lstChain.AddTail(spNext);
    FUN_1417f3e80(nBounce - 1, lstChain, spRecord, nAttack, pOwner);
}
MS2_REPLACE(0x1417f3e80, StateSkill::FUN_1417f3e80, 3372, 0x3C869B16);

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

// The motion of the cast for one tick: the motion controller's displacement, then (move type 2 / 3) the move input at
// the actor's speed unless a move-key skill has run out. A running hit pause (feature 0xca) only extends the cast.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417edc20
void StateSkill::FUN_1417edc20(double fTime)
{
    if (m_spRecord == NULL)
        return;
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xca) && m_pause.FUN_1417e4e40() != 0)
    {
        if (m_pOwner->vfunc_99(1) != 0)
            m_spRecord->m_f80 += (float)fTime;
        return;
    }
    if (m_n10 == 0x3c)
        return;
    bool bMoveInput = true;
    if (m_spRecord->m_spSkill->m_bMovingInMovekey && FUN_14028d470(m_spRecord->FUN_14175a1b0(), 0.0f))
        bMoveInput = false;
    m_bMoved = m_pMotion->vfunc_5(fTime);
    Unk_StreamPoint kDelta = m_pMotion->vfunc_3();
    unsigned nIgnoreGroups = 0;
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion != NULL)
        nIgnoreGroups = pMotion->m_nIgnoreCollisionGroups;
    bool bMoved = m_bMoved;
    int nKind = m_pMotion->vfunc_6();
    Unk_StreamPoint kMove = kDelta;
    m_bMoved = bMoved | m_pOwner->vfunc_68(&kMove, fTime, 0, nIgnoreGroups, nKind);
    if (m_spRecord->m_spSkill->m_nMoveType != 2 && m_spRecord->m_spSkill->m_nMoveType != 3)
        return;
    if (!bMoveInput)
        return;
    float fYaw = m_pOwner->FUN_14166da40();
    NiPoint3 kInput = m_pOwner->FUN_14123c360();
    efd::Point3 kDir = m_pOwner->FUN_141674b60(SS_PT(kInput));
    efd::Point3 kStep = kDir * m_pOwner->vfunc_95() * (float)fTime;
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xca) && m_spRecord->m_spSkill->m_nMoveType == 2)
        m_pOwner->FUN_14166d8b0(fYaw);
    bMoved = m_bMoved;
    efd::Point3 kStepCopy = kStep;
    m_bMoved = bMoved | m_pOwner->vfunc_68(&kStepCopy, fTime, 0, nIgnoreGroups, 0);
}
MS2_REPLACE_METHOD(0x1417edc20, StateSkill, FUN_1417edc20, 1264, 0x125D56A2);

// The end of a motion of the running cast. Without the chain input held it goes to the chain (FUN_1417ef4a0).
// Attacks left: the own player starts the next motion of the cast as a new record. The attacks over: a rider idles
// (unless the motion keeps playing), the own player casts the queued cast (else the chained one, the next input
// or an auto change) unless the running skill blocks it; a cast that does not start ends the state. A cast running
// for more than 5 seconds ends too.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417ee120
void StateSkill::FUN_1417ee120()
{
    if (m_spRecord == NULL)
        return;
    if (!m_b48)
    {
        FUN_1417ef4a0();
        return;
    }
    m_nAttack = 0;
    m_spRecord->FUN_141759fc0();
    if (m_spRecord->FUN_141759e40() == 0)
    {
        if (FUN_1417b8340() != 0)
        {
            Unk_InventorySkillRequest kReq(m_spRecord->GetSkillId(), m_spRecord->GetLevel());
            kReq.m_nCastId = m_spRecord->m_nCastId;
            kReq.m_nMotion = m_spRecord->m_nMotion + 1;
            reinterpret_cast<NiPoint3&>(kReq.m_ptPos) = m_pOwner->vfunc_18();
            reinterpret_cast<NiPoint3&>(kReq.m_ptDir) = reinterpret_cast<const NiPoint3&>(m_spRecord->m_ptDir);
            kReq.m_fRotZ = m_spRecord->m_ptRot.z;
            MS2Ptr<CSkillRecord> spMotion(new CSkillRecord);
            if (!spMotion->Init(kReq))
                return;
            if (m_spRecord->m_nB0 != 0)
            {
                spMotion->m_nB0 = m_spRecord->m_nB0;
                spMotion->m_strB8 = m_spRecord->m_strB8;
            }
            spMotion->m_bAD = spMotion->m_spLevel->FUN_140804450();
            if (!m_pOwner->vfunc_102(spMotion))
                FUN_1417f0070();
        }
    }
    else
    {
        if (FUN_1417b8340() == 0)
        {
            if (FUN_1417b8480() == NULL)
            {
                FUN_1417f0070();
            }
            else
            {
                bool bPlaying = false;
                SkillMotionData* pMotion = m_spRecord->FUN_141759830();
                if (pMotion != NULL)
                    bPlaying = !pMotion->m_bDoesPlayIdleOnSkillEnd;
                if (!bPlaying)
                    m_pOwner->vfunc_59(1, NULL, 0, 0);
            }
        }
        else
        {
            if (m_spNext == NULL)
            {
                MyPC* pMy = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
                if (pMy != NULL)
                {
                    int nOldInput = pMy->FUN_141523bc0()->FUN_141765cf0(0);
                    int nOldHold = pMy->FUN_141523bc0()->FUN_141765d30(1);
                    if (m_spRecord->m_nB0 == 0)
                        m_spNext = m_pOwner->vfunc_104(true, true, true);
                    else
                        m_spNext = FUN_1417f0230();
                    if (m_spNext == NULL)
                    {
                        MS2Ptr<CSkillRecord> spAuto = FUN_1417f0570(2);
                        if (spAuto != NULL)
                        {
                            if (spAuto->m_spSkill->m_bKeyIsDown
                                || spAuto->m_spSkill->GetId() != m_spRecord->m_spSkill->GetId())
                            {
                                if (spAuto->m_spSkill->m_eImmediateActive != 0)
                                    m_spNext = spAuto;
                            }
                        }
                    }
                    pMy->FUN_141523bc0()->FUN_141765cf0(nOldInput);
                    pMy->FUN_141523bc0()->FUN_141765d30(nOldHold);
                }
            }
            if (m_spNext.get() == NULL)
            {
                FUN_1417f0070();
            }
            else if (m_b111 && m_spRecord->m_spSkill->m_blockA4.FUN_140802ff0(m_spNext->m_spSkill->GetId()) != 0)
            {
                FUN_1417f0070();
            }
            else
            {
                m_pOwner->vfunc_100(m_spNext, 0);
                m_spNext->m_bAD = false;
                if ((SkillLevelData*)m_spNext->m_spLevel != NULL)
                    m_spNext->m_bAD = m_spNext->m_spLevel->FUN_140804450();
                if (!m_pOwner->vfunc_102(m_spNext))
                    FUN_1417f0070();
            }
        }
        m_spNext = 0;
    }
    if (m_fStartTime + 5.0 < CMainSystem::GetInstance()->FUN_141473280())
        FUN_1417f0070();
}
MS2_REPLACE_METHOD(0x1417ee120, StateSkill, FUN_1417ee120, 2524, 0x3637A3E5);

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

// Whether the next cast may follow the running one: not the same skill again (unless it is a key-down skill), by its
// chain type (1: any other skill, 2: another origin skill), else only after the last motion with the self combo or
// the chain input, not while a continuing skill keeps its key held, not against the self combo of the motion, and
// never into the running skill or its combo output.
// @0x1417eed70
bool StateSkill::FUN_1417eed70(MS2Ptr<CSkillRecord> spNext)
{
    if (!spNext->m_spSkill->m_bKeyIsDown && spNext->m_spSkill->GetId() == m_spRecord->m_spSkill->GetId())
        return false;
    m_nChainType = (int)spNext->m_spSkill->m_eImmediateActive;
    if (m_nChainType == 1)
    {
        if (spNext->m_spSkill->GetId() == m_spRecord->m_spSkill->GetId())
            return false;
        return true;
    }
    if (m_nChainType == 2 && spNext->m_spSkill->GetOriginId() != m_spRecord->m_spSkill->GetOriginId())
        return true;
    if (m_nChainType == 2 && spNext->m_spSkill->GetOriginId() == m_spRecord->m_spSkill->GetOriginId())
        return false;
    if (m_spRecord->FUN_141759f20() == 0)
        return false;
    if (!m_b4a && !m_b114)
        return false;
    if (m_spRecord->m_spSkill->m_bContinue)
    {
        if (!m_spRecord->m_spSkill->m_blockA4.m_bChargingSkill || FUN_14028d470(m_fChargeTime, 0))
        {
            if (static_cast<Unk_SsMove*>(m_pOwner->FUN_14166d240())->FUN_141682f80(m_spRecord->m_nA4))
                return false;
        }
    }
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion != NULL && !pMotion->m_strSelfInputCombo.IsEmpty())
    {
        if (!m_b114)
        {
            if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xca))
            {
                if (spNext->m_spSkill->GetId() == m_spRecord->m_spSkill->GetId())
                    return false;
                else if (m_spRecord->m_spSkill->m_blockA4.FUN_140802ff0(spNext->m_spSkill->GetId()) != 0)
                    return false;
            }
            else
            {
                if (spNext->m_spSkill->GetId() == m_spRecord->m_spSkill->GetId())
                    return false;
            }
        }
        else if (!m_b4a)
        {
            if (spNext->m_spSkill->GetId() != m_spRecord->m_spSkill->GetId())
                return false;
        }
    }
    if (m_b115)
    {
        if (spNext->m_spSkill->GetId() == m_spRecord->m_spSkill->GetId())
            return false;
        if (m_spRecord->m_spSkill->m_blockA4.FUN_140802ff0(spNext->m_spSkill->GetId()) != 0)
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1417eed70, StateSkill, FUN_1417eed70, 1830, 0xCD4C5F92);

// Chains the queued cast in the last motion of the running one (on a combo input, a chain type, a held chain or the
// charge release): the self combo, the hold attack and the continue rules (as in FUN_1417eed70) or an auto change
// back into the same skill and level can veto it; else the queued cast is started (its charge flag from its level)
// and the running cast finishes.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417ef4a0
void StateSkill::FUN_1417ef4a0()
{
    if (!m_b49 && !m_b116 && m_nChainType == 0 && !m_b112)
        return;
    if (m_spRecord->FUN_141759eb0() == 0 || FUN_1417b8340() == 0 || m_spNext == NULL)
        return;
    bool bChain = true;
    int nNextId = m_spNext->m_spSkill->GetId();
    int nId = m_spRecord->m_spSkill->GetId();
    SkillMotionData* pMotion = m_spRecord->FUN_141759830();
    if (pMotion != NULL && !pMotion->m_strSelfInputCombo.IsEmpty())
    {
        if ((!m_b49 && !m_b112) || m_b116)
        {
            if (!m_b49 && m_b116)
            {
                if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xca))
                {
                    if (nNextId != nId)
                        bChain = false;
                }
                else if (nNextId != nId)
                {
                    if (m_spRecord->m_spSkill->m_blockA4.FUN_140802ff0(nNextId) == 0)
                        bChain = false;
                }
            }
        }
        else
        {
            if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xca))
            {
                if (nNextId == nId)
                    bChain = false;
            }
            else if (nNextId == nId)
            {
                bChain = false;
            }
            else if (m_spRecord->m_spSkill->m_blockA4.FUN_140802ff0(nNextId) != 0)
            {
                bChain = false;
            }
        }
    }
    if (m_b111 && (m_b112 || m_b49))
    {
        if (nNextId == nId)
            bChain = false;
        else if (m_bLoop && !m_b112 && m_spRecord->m_spSkill->m_blockA4.FUN_140802ff0(nNextId) != 0)
            bChain = false;
    }
    if (m_b115)
    {
        if (nNextId == nId)
            bChain = false;
        if (m_spRecord->m_spSkill->m_blockA4.FUN_140802ff0(nNextId) != 0)
            bChain = false;
    }
    if (!m_b11e && m_spRecord->m_spSkill->m_blockB0.m_eAutoChange != 0)
    {
        MyPC* pMy = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pMy != NULL)
        {
            int nSkillId = nId;
            unsigned short nLevel = m_spRecord->m_spLevel->GetLevel();
            pMy->FUN_141526c80(nSkillId, nLevel);
            if (nSkillId == nNextId && (unsigned)nLevel == m_spNext->m_spLevel->GetLevel())
                bChain = false;
        }
    }
    if (!bChain)
        return;
    m_pOwner->vfunc_100(m_spNext, 0);
    MyPC* pMy = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pMy != NULL && m_spNext->m_nA8 != 0)
        pMy->FUN_141523bc0()->FUN_141765a70(m_spNext->m_nA8);
    m_spNext->m_bAD = false;
    if (m_spNext.get() != NULL && (SkillLevelData*)m_spNext->m_spLevel != NULL)
        m_spNext->m_bAD = m_spNext->m_spLevel->FUN_140804450();
    if (m_spNext->m_bAD)
        m_spRecord->FUN_141759fc0();
    FUN_1417f2a90(true);
    if (m_pOwner->vfunc_102(m_spNext))
        m_spNext = 0;
}
MS2_REPLACE_METHOD(0x1417ef4a0, StateSkill, FUN_1417ef4a0, 1843, 0xD30C901D);

// Keeps the caster on the node of the object the cast is attached to (feature 0xae): the caster takes the node's
// world rotation and position; when the object is gone, dead or not an npc the caster leaves the state (6).
// MS2-FUNCTIONAL: written from the call sequence.
// @0x1417efbe0
int StateSkill::FUN_1417efbe0()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xae))
        return 0;
    if (m_spRecord == NULL)
        return 0;
    if (m_spRecord->m_nB0 == 0)
        return 0;
    efd::SmartPointer<NiAVObject> spNode = NULL;
    PCBase* pTarget = (PCBase*)FUN_1403ed2d0()->FUN_141bd1200(m_spRecord->m_nB0);
    if (pTarget != NULL)
        spNode = pTarget->FUN_1416757c0(m_spRecord->m_strB8);
    if ((NiAVObject*)spNode == NULL || pTarget == NULL || pTarget->FUN_14166ce30() != 0
        || pTarget->GetClassID() != 0x6200028)
    {
        m_pOwner->vfunc_59(6, 0, 0x22, 0);
    }
    else
    {
        efd::Point3 kRot;
        if (reinterpret_cast<const efd::Matrix3&>(spNode->GetWorldRotate()).ToEulerAnglesXYZ(kRot.x, kRot.y, kRot.z))
        {
            kRot *= -57.2957764f;
            m_pOwner->vfunc_21(kRot);
        }
        efd::Point3 kPos = reinterpret_cast<const efd::Point3&>(spNode->GetWorldTranslate());
        m_pOwner->vfunc_19(kPos);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1417efbe0, StateSkill, FUN_1417efbe0, 778, 0x4588DED1);

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
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb7de0-0x142cb7f50 .text$yd
