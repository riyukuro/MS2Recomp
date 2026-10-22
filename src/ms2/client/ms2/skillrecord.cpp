// skillrecord.cpp - the skill cast records (SkillTargetRecord, CSkillRecord, the damage records).
// MS2-UNIT: ?\skillrecord.cpp
// MS2-RANGE: 0x141758d70-0x14175c840 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\skillrecord.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "skillrecord.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/magicdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"

// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

extern Unk_StreamPoint DAT_143b01a60;                       // the zero point
SkillDataTable* FUN_1401958b0();                            // the skill table
unsigned FUN_141472bc0();                                   // the tick count

bool FUN_14028d470(float fValue, float fTolerance);         // commonutil: nearly equal
float FUN_14028d3a0(float fPercent);                        // commonutil: percent to rate
int FUN_1409726e0(int nSuperArmor, ApplyFieldType eApplyField);  // PCBase: the super armor applies on this field

// A field object (FieldObject / Actor / PCBase; only the casts and the members below are used).
class Unk_SrEntity;

// The own field world (the field objects by object id).
class Unk_SrWorld
{
public:
    Unk_SrEntity* FUN_141bd1200(int nObjectId);             // the field object
    int FUN_141bd19d0(int nObjectId);                       // the time mode of a field object
};
Unk_SrWorld* FUN_1403ed2d0();

// The state machine of an actor: the attack state takes the hit records of the own player's casts.
class Unk_SrState
{
public:
    void FUN_1417ecc10(Unk_MagicTagPtr spRecord);
};

// The own player (MyPC).
class Unk_SrMyPC
{
public:
    int FUN_14166c930();                                    // the current state id
    Unk_SrState* FUN_14166ccb0();                           // the current state
};
Unk_SrMyPC* FUN_14096e160(Unk_SrEntity* pEntity);           // as MyPC

// The equipment of a player: the weapon's item gives the attack material of an attack without one.
class Unk_ItemEquipData
{
public:
    unsigned char m_unk00[0x10c];
    int m_nAttackMaterial;                                  // +0x10c
};
class Unk_SrEquipSet
{
public:
    MS2Ptr<CEquipItem> FUN_1411e1860(int nSlot, int nKind, int nFlags);    // the item of an equip slot
};
class Unk_SrPC;
void* FUN_14096e110(Unk_SrEntity* pEntity);                 // as an npc (0 for a player)
Unk_SrPC* FUN_140974230(Unk_SrEntity* pEntity);             // as a player
Unk_SrEquipSet* FUN_1416561a0(Unk_SrPC* pPC);               // the equipment of a player

// The buffs of an actor (AdditionalCli is RTTI CPtred, ?\additionalcli.cpp; only its level data is read).
struct Unk_SrBuffLevel
{
    unsigned char m_unk00[0x298];
    int m_nDotDamageType;                                   // +0x298
};
class AdditionalCli : public CPtred
{
public:
    Unk_SrBuffLevel* FUN_14096d810();                       // the level data
};
class Unk_SrBuffs
{
public:
    MS2Ptr<AdditionalCli> FUN_14096fc80(int nBuffId);       // one buff
};
Unk_SrBuffs* FUN_1416749a0(Unk_SrEntity* pEntity);          // the buffs of an actor

// ---- SkillTargetRecord ----

// @0x141758d70
bool SkillTargetRecord::FUN_141758d70(unsigned long long nTagId, unsigned long long nTagSub, int nOwnerId,
    int nCasterId, int nSkillId, short nLevel, int nMotion, const Unk_StreamPoint& ptDir, int n80, int n84,
    int nAttack, int n8c)
{
    m_spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (m_spSkill == 0)
        return false;
    m_spLevel = m_spSkill->FUN_1407e90a0(nLevel);
    if (m_spLevel == 0)
        return false;
    m_spLinked = 0;
    m_n80 = n80;
    m_nTagId = nTagId;
    m_nTagSub = nTagSub;
    m_nOwnerId = nOwnerId;
    m_nTimeMode = FUN_1403ed2d0()->FUN_141bd19d0(m_nOwnerId);
    m_nCasterId = nCasterId;
    m_n84 = n84;
    m_nMotion = nMotion;
    m_ptDir = ptDir;
    m_nStartTick = 0;
    m_nAttack = nAttack;
    m_n8c = n8c;
    return true;
}

// @0x141759010
SkillMotionData* SkillTargetRecord::FUN_141759010()
{
    return m_spLevel->FUN_140803f00(m_nMotion);
}

// @0x141759050
SkillAttackData* SkillTargetRecord::FUN_141759050()
{
    return m_spLevel->FUN_140803f60(m_nMotion, m_nAttack);
}

// @0x141759090
int SkillTargetRecord::FUN_141759090()
{
    return m_spLevel->FUN_1408043f0(m_nMotion, m_nAttack);
}

// @0x1417590d0
const CString& SkillTargetRecord::FUN_1417590d0()
{
    static CString s_strEmpty;
    SkillAttackData* pAttack = FUN_141759050();
    if (pAttack == 0)
        return s_strEmpty;
    if (pAttack->GetAttackMethodType() != 1)
        return s_strEmpty;
    return pAttack->GetArrowEffect();
}

// @0x141758fb0
unsigned SkillTargetRecord::FUN_141758fb0()
{
    return m_spSkill->GetId();
}

// @0x141758fe0
unsigned short SkillTargetRecord::FUN_141758fe0()
{
    return m_spLevel->FUN_140803df0();
}

// @0x141759190
int SkillTargetRecord::FUN_141759190()
{
    return m_nStartTick;
}

// @0x1417591b0
void SkillTargetRecord::FUN_1417591b0()
{
    Unk_SrEntity* pOwner = FUN_1403ed2d0()->FUN_141bd1200(m_nOwnerId);
    if (pOwner == 0)
        return;
    Unk_SrMyPC* pMe = FUN_14096e160(pOwner);
    if (pMe != 0) {
        int nState = pMe->FUN_14166c930();
        if (nState == 0x10) {
            Unk_SrState* pState = pMe->FUN_14166ccb0();
            if (pState != 0)
                pState->FUN_1417ecc10(Unk_MagicTagPtr(reinterpret_cast<Unk_MagicTag*>(this)));   // Unk_MagicTag is this class
        }
    }
}

// ---- CSkillRecord ----

// @0x141759260
CSkillRecord::CSkillRecord()
    : m_nTick(0), m_nSendTick(0), m_nSendCount(0), m_nCastId(0), m_ptPos(DAT_143b01a60), m_ptDir(DAT_143b01a60),
      m_ptRot(DAT_143b01a60), m_fCooldown(0), m_fDuration(0), m_fElapsed(0), m_f80(0), m_n84(0), m_n88(0), m_nMotion(0),
      m_nAttack(0), m_nAttackIndex(0), m_n98(0), m_n9c(0), m_nA0(0), m_nA4(0), m_nA8(0), m_bAC(false), m_bAD(true), m_bAE(false), m_nB0(0), m_bEnd(false), m_n1b8(0)
{
}

// @0x141759520
CSkillRecord::~CSkillRecord()
{
}

// @0x1417595d0
bool CSkillRecord::Init(Unk_InventorySkillRequest& kReq)
{
    m_spSkill = FUN_1401958b0()->GetSkillData(kReq.m_nSkillId);
    if (m_spSkill == 0)
        return false;
    m_spLevel = m_spSkill->FUN_1407e90a0(kReq.m_nLevel);
    if (m_spLevel == 0)
        return false;
    m_nTick = kReq.m_nTick;
    m_nSendTick = kReq.m_nTick;
    m_nCastId = kReq.m_nCastId;
    m_nMotion = kReq.m_nMotion;
    m_ptPos = *(const Unk_StreamPoint*)&kReq.m_ptPos;
    m_ptDir = *(const Unk_StreamPoint*)&kReq.m_ptDir;
    m_ptRot = Unk_StreamPoint(0, 0, kReq.m_fRotZ);
    m_bAE = kReq.m_b3a;
    m_bAD = kReq.m_b38;
    m_nA4 = kReq.m_n34;
    m_n1b8 = kReq.m_n40;
    return true;
}

// @0x141759830
SkillMotionData* CSkillRecord::FUN_141759830()
{
    return m_spLevel ? m_spLevel->FUN_140803f00(m_nMotion) : 0;
}

// @0x1417598a0
const CString& CSkillRecord::FUN_1417598a0()
{
    return m_spLevel->FUN_140804500(2, m_nMotion);
}

// @0x1417598e0
const CString& CSkillRecord::FUN_1417598e0()
{
    return m_spLevel->FUN_140804500(3, m_nMotion);
}

// @0x141759920
const CString& CSkillRecord::FUN_141759920()
{
    return m_spLevel->FUN_140804500(4, m_nMotion);
}

// @0x141759960
unsigned CSkillRecord::GetSkillId()
{
    return m_spSkill->GetId();
}

// @0x141759990
unsigned short CSkillRecord::GetLevel()
{
    return m_spLevel->FUN_140803df0();
}

// @0x1417599c0
__int64 CSkillRecord::FUN_1417599c0()
{
    return m_n1b8;
}

// @0x1417599e0
__int64 CSkillRecord::FUN_1417599e0()
{
    if (m_spLevel == 0)
        return 0;
    return m_spLevel->FUN_140804c90(m_nMotion);
}

// @0x141759a50
bool CSkillRecord::FUN_141759a50()
{
    if (m_spLevel == 0)
        return false;
    SkillMotionData* pMotion = m_spLevel->FUN_140803f00(m_nMotion);
    if (pMotion == 0)
        return false;
    return pMotion->m_bA0;
}

// @0x141759ad0
float CSkillRecord::FUN_141759ad0()
{
    SkillMotionData* pMotion = FUN_141759830();
    if (pMotion == 0)
        return 0;
    if (pMotion->m_fB8 != 0)
        return 0;
    if (m_fCooldown != 0)
        return 0;
    if (m_ptDir.FUN_140552690(DAT_143b01a60))
        return 0;
    else
        return pMotion->m_fAC;
}

// @0x141759b60
float CSkillRecord::FUN_141759b60(double dDelta)
{
    SkillMotionData* pMotion = FUN_141759830();
    if (pMotion == 0)
        return 0;
    float fResult = 0;
    float fRate = FUN_14028d470(pMotion->m_fB8, 0) ? pMotion->m_fAC : pMotion->m_fB8;
    fRate = FUN_14028d470(m_fCooldown, 0) ? fRate : m_fCooldown;
    fRate = FUN_14028d3a0(fRate);
    if (m_fDuration > 0 && m_fElapsed < m_fDuration) {
        float fStep = (float)dDelta;
        if (m_fElapsed + fStep > m_fDuration)
            fStep = m_fDuration - m_fElapsed;
        m_fElapsed += fStep;
        if (m_fElapsed > m_fDuration)
            m_fElapsed = m_fDuration;
        fResult = fRate * (fStep / m_fDuration);
    }
    return fResult;
}

// @0x141759d20
float CSkillRecord::FUN_141759d20(double dDelta, float fRate)
{
    float fResult = 0;
    float fScale = fRate;
    fScale *= 0.01f;
    if (m_fDuration > 0 && m_fElapsed < m_fDuration) {
        float fStep = (float)dDelta;
        if (m_fElapsed + fStep > m_fDuration)
            fStep = m_fDuration - m_fElapsed;
        m_fElapsed += fStep;
        if (m_fElapsed > m_fDuration)
            m_fElapsed = m_fDuration;
        fResult = fScale * (fStep / m_fDuration);
    }
    return fResult;
}

// @0x141759e40
int CSkillRecord::FUN_141759e40()
{
    if (m_bEnd)
        return 1;
    if (m_nMotion + m_nAttack >= m_spLevel->FUN_140804270())
        return 1;
    else
        return 0;
}

// @0x141759eb0
int CSkillRecord::FUN_141759eb0()
{
    if (m_bEnd)
        return 1;
    if (m_nMotion + 1 >= m_spLevel->FUN_140804270())
        return 1;
    else
        return 0;
}

// @0x141759f20
int CSkillRecord::FUN_141759f20()
{
    if (m_nMotion + 1 >= m_spLevel->FUN_140804270())
        return 1;
    else
        return 0;
}

// @0x141759f70
int CSkillRecord::FUN_141759f70()
{
    return m_spLevel->FUN_1408043f0(m_nMotion, m_nAttackIndex);
}

// @0x141759fc0
void CSkillRecord::FUN_141759fc0()
{
    m_nAttack = 1;
}

// @0x141759fe0
void CSkillRecord::FUN_141759fe0()
{
    m_bEnd = true;
}

// @0x14175a000
SkillAttackData* CSkillRecord::FUN_14175a000()
{
    return m_spLevel->FUN_140803f60(m_nMotion, m_nAttackIndex);
}

// @0x14175a050
SkillAttackData* CSkillRecord::FUN_14175a050(int nAttack)
{
    return m_spLevel->FUN_140803f60(m_nMotion, nAttack);
}

// @0x14175a0a0
SkillAttackData* CSkillRecord::FUN_14175a0a0(CString strName)
{
    return m_spLevel->FUN_140803fb0(m_nMotion, strName);
}

// @0x14175a130
int CSkillRecord::FUN_14175a130()
{
    SkillAttackData* pAttack = FUN_14175a000();
    if (pAttack == 0)
        return 0;
    return pAttack->m_nBrokenOffence;
}

// @0x14175a170
float CSkillRecord::FUN_14175a170()
{
    SkillAttackData* pAttack = FUN_14175a000();
    if (pAttack == 0)
        return 0;
    return pAttack->m_fBrokenForce;
}

// @0x14175a1b0
float CSkillRecord::FUN_14175a1b0()
{
    if (FUN_14028d470(m_fDuration, 0))
        return 0;
    if (m_fDuration <= m_fElapsed)
        return 0;
    return m_fDuration - m_fElapsed;
}

// @0x14175a210
int CSkillRecord::FUN_14175a210()
{
    if (FUN_1409726e0(m_spSkill->m_nSuperArmor, m_spSkill->m_eSuperArmorApplyFieldType))
        return m_spSkill->m_nSuperArmor;
    return 0;
}

// @0x14175a280
void CSkillRecord::AddTarget(unsigned nKey, unsigned nTarget)
{
    TargetSetPtr spTargets;
    if (m_targets.Lookup(nKey, spTargets)) {
        spTargets->insert(nTarget);
    }
    else {
        spTargets = Unk_CubeNewTag(0);
        spTargets->insert(nTarget);
        m_targets.SetAt(nKey, spTargets);
    }
}

// @0x14175a360
int CSkillRecord::HasTarget(unsigned nKey, unsigned nTarget)
{
    TargetSetPtr spTargets;
    if (m_targets.Lookup(nKey, spTargets))
        return spTargets->find(nTarget) != spTargets->end();
    return 0;
}

// @0x14175a430
void CSkillRecord::SendSkill()
{
    m_nSendTick = FUN_141472bc0();
    COutPacket packet(0x20);
    packet.Encode1(3);
    packet.Encode8(m_nCastId);
    packet.Encode4(m_nSendTick);
    FUN_140710590(packet);
    m_nSendCount++;
    m_targets.RemoveAll();
}

// ---- CDamageRecord ----

// @0x14175a4e0
CDamageRecord::CDamageRecord()
{
    m_nTagId = 0;
    m_nTagSub = 0;
    m_nD0 = 0;
    m_pt78 = DAT_143b01a60;
    m_ptHit = DAT_143b01a60;
}

// @0x14175a610
int CDamageRecord::Init(unsigned long long nTagId, unsigned long long nTagSub, int nOwnerId, int nCasterId,
    int nSkillId, short nLevel, int nMotion, int nAttack, const Unk_StreamPoint& ptPos,
    const Unk_StreamPoint& ptDir, const Unk_StreamPoint& ptHit)
{
    m_nTagId = nTagId;
    m_nTagSub = nTagSub;
    m_nOwnerId = nOwnerId;
    m_nCasterId = nCasterId;
    m_nSkillId = nSkillId;
    m_nLevel = nLevel;
    m_spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    m_spLevel = m_spSkill->FUN_1407e90a0(nLevel);
    m_nMotion = nMotion;
    m_nAttack = nAttack;
    m_ptPos = ptPos;
    m_ptDir = ptDir;
    m_ptHit = ptHit;
    if (!m_spSkill || !m_spLevel)
        return 0;
    return 1;
}

// @0x14175a820
SkillData* CDamageRecord::FUN_14175a820()
{
    return m_spSkill.get();
}

// @0x14175a850
SkillMotionData* CDamageRecord::FUN_14175a850()
{
    return m_spLevel ? m_spLevel->FUN_140803f00(m_nMotion) : 0;
}

// @0x14175a8b0
SkillAttackData* CDamageRecord::FUN_14175a8b0()
{
    return m_spLevel ? m_spLevel->FUN_140803f60(m_nMotion, m_nAttack) : 0;
}

// @0x14175a920
int CDamageRecord::FUN_14175a920()
{
    SkillAttackData* pAttack = FUN_14175a8b0();
    if (pAttack == 0)
        return 0;
    return pAttack->m_damage.m_nNameIndex;
}

// @0x14175a960
CString CDamageRecord::FUN_14175a960()
{
    static CString s_strEmpty;
    SkillAttackData* pAttack = FUN_14175a8b0();
    if (pAttack == 0)
        return s_strEmpty;
    return pAttack->m_damage.m_strEffectHit;
}

// @0x14175aa50
CString CDamageRecord::FUN_14175aa50()
{
    static CString s_strEmpty;
    SkillAttackData* pAttack = FUN_14175a8b0();
    if (pAttack == 0)
        return s_strEmpty;
    return pAttack->m_damage.m_strEffectRemain;
}

// @0x14175ab40
bool CDamageRecord::FUN_14175ab40()
{
    SkillAttackData* pAttack = FUN_14175a8b0();
    if (pAttack == 0)
        return false;
    return pAttack->m_damage.m_bIgnoreOptimalHideDamageHitEffect;
}

// @0x14175ab80
bool CDamageRecord::FUN_14175ab80()
{
    SkillAttackData* pAttack = FUN_14175a8b0();
    if (pAttack == 0)
        return false;
    return pAttack->m_damage.m_bIgnoreOptimalHideDamageRemainEffect;
}

// @0x14175abc0
void CDamageRecord::FUN_14175abc0(int nType, __int64 nDamage)
{
    if (nType == 8) {
        m_nD0 = 8;
        nType = 3;
    }
    m_types.Add(nType);
    m_damages.Add(nDamage);
}

// @0x14175ac30
__int64 CDamageRecord::FUN_14175ac30()
{
    __int64 nTotal = 0;
    for (unsigned i = 0; i < m_damages.GetCount(); i++)
        nTotal += m_damages[i];
    return nTotal;
}

// @0x14175acc0
int CDamageRecord::FUN_14175acc0()
{
    return (static_cast<bool>(m_spLevel) && m_spLevel->FUN_1408043f0(m_nMotion, m_nAttack) != 0) ? 1 : 0;
}

// @0x14175ad50
int CDamageRecord::FUN_14175ad50()
{
    int nMaterial = 1;
    Unk_SrEntity* pOwner = FUN_1403ed2d0()->FUN_141bd1200(m_nOwnerId);
    if (pOwner == 0)
        return nMaterial;
    nMaterial = FUN_14175a8b0()->m_damage.m_nAttackMaterial;
    void* pNpc = FUN_14096e110(pOwner);
    if (pNpc != 0) {
        return nMaterial;
    }
    else {
        Unk_SrPC* pPC = FUN_140974230(pOwner);
        if (pPC != 0) {
            if (nMaterial != 0)
                return nMaterial;
            MS2Ptr<CEquipItem> spWeapon = FUN_1416561a0(pPC)->FUN_1411e1860(5, 6, 0);
            if (spWeapon.get() != 0)
                nMaterial = spWeapon->FUN_1411dc7a0()->FUN_140527840()->m_nAttackMaterial;
        }
    }
    return nMaterial;
}

// @0x14175aeb0
unsigned __int64 CDamageRecord::FUN_14175aeb0()
{
    return m_damages.GetCount();
}

// @0x14175aee0
int CDamageRecord::FUN_14175aee0(int nIndex, int& nType)
{
    if ((int)m_types.GetCount() <= nIndex)
        return 0;
    nType = m_types[nIndex];
    return 1;
}

// @0x14175af50
int CDamageRecord::vfunc_1()
{
    SkillAttackData* pAttack = FUN_14175a8b0();
    if (pAttack == 0)
        return 0;
    return pAttack->m_nHitImmuneBreak;
}

// ---- CDotDamageRecord ----

// @0x14175af90
CDotDamageRecord::CDotDamageRecord()
{
    m_nOwnerId = 0;
    m_nCasterId = 0;
    m_nEffectLevel = 0;
}

// @0x14175aff0
int CDotDamageRecord::Init(int nOwnerId, int nCasterId, int nEffectLevel, int nType, __int64 nDamage)
{
    m_nOwnerId = nOwnerId;
    m_nCasterId = nCasterId;
    m_nEffectLevel = nEffectLevel;
    m_damages.Add(nDamage);
    m_types.Add(nType);
    return 1;
}

// @0x14175b070
int CDotDamageRecord::vfunc_1()
{
    Unk_SrEntity* pCaster = FUN_1403ed2d0()->FUN_141bd1200(m_nCasterId);
    if (pCaster == 0)
        return 0;
    MS2Ptr<AdditionalCli> spBuff = FUN_1416749a0(pCaster)->FUN_14096fc80(m_nEffectLevel);
    if (spBuff == 0)
        return 0;
    return spBuff->FUN_14096d810()->m_nDotDamageType;
}

// @0x14175b130
int CDotDamageRecord::FUN_14175b130()
{
    if (m_types.IsEmpty())
        return 0;
    return m_types[0];
}

// ---- CSplashDamageRecord ----

// @0x14175b180
CSplashDamageRecord::CSplashDamageRecord()
{
}

// @0x14175b1c0
int CSplashDamageRecord::Init(int nCasterId, int nOwnerId, unsigned long long nTagId, int nSkillId, short nLevel,
    int nMotion, int nAttack, const Unk_StreamPoint& ptPos, const Unk_StreamPoint& ptDir)
{
    m_nCasterId = nCasterId;
    m_nOwnerId = nOwnerId;
    m_nTagId = nTagId;
    m_nSkillId = nSkillId;
    m_nLevel = nLevel;
    m_spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    m_spLevel = m_spSkill->FUN_1407e90a0(nLevel);
    m_nMotion = nMotion;
    m_nAttack = nAttack;
    m_ptPos = ptPos;
    m_ptDir = ptDir;
    if (!m_spSkill || !m_spLevel)
        return 0;
    return 1;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6850-0x142cb6870 .text$yd
// MS2-RANGE: 0x142cb6890-0x142cb68d0 .text$yd
