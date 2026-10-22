// skillrecord.h - the skill cast records of ?\skillrecord.cpp (RTTI names: SkillTargetRecord, CSkillRecord,
// CDamageRecord, CDotDamageRecord, CSplashDamageRecord). Layouts from the ctors/dtors and the member functions of the
// unit (CSkillRecord cross-checked against the v2525 decomp, work/ext/v2525/x/ms2decomp/include/ms2/client/CSkillRecord.h).
// SkillTargetRecord is the "Unk_MagicTag" of scenestategame.cpp / magicdata.cpp (its ctor 0x141746440 and dtor 0x141746cb0
// are emitted by scenestategame.cpp).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/commonfiles/ugccubecategorytable.h"   // Unk_CubeBoxPtr, Unk_CubeNewTag
#include "ms2/commonfiles/skilloverlapcompare.h"    // SkillData, SkillLevelData

class CMagicModel;

// The skill request a cast record is built from (the 3rd argument of CSkillRecord::Init).
// The request's point fields are a 12-byte float triple with no default ctor in the exe: the request ctor copy-
// initialises them (implicit copy ctor, rep movsb) and constructs nothing. The user-declared ctor keeps the request a
// non-POD (no /GS cookie in functions with a request local); the efd::Point3 operations go through Unk_StreamPoint casts.
struct Unk_IsrPoint
{
    Unk_IsrPoint(float fX, float fY, float fZ);             // declared only
    float x, y, z;
};

struct Unk_InventorySkillRequest
{
    Unk_InventorySkillRequest(int nSkillId, unsigned short nLevel);   // 0x141763fa0 (?\skillslot.cpp)
    int m_nSkillId;                                         // +0x00
    unsigned short m_nLevel;                                // +0x04
    __int64 m_nCastId;                                      // +0x08
    int m_nTick;                                            // +0x10
    int m_nMotion;                                          // +0x14
    Unk_IsrPoint m_ptPos;                                   // +0x18
    Unk_IsrPoint m_ptDir;                                   // +0x24
    float m_fRotZ;                                          // +0x30
    int m_n34;                                              // +0x34
    bool m_b38;                                             // +0x38
    bool m_b39;                                             // +0x39
    bool m_b3a;                                             // +0x3a
    __int64 m_n40;                                          // +0x40
};
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, m_ptPos, 0x18);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, m_b3a, 0x3a);
MS2_CHECK_OFFSET(Unk_InventorySkillRequest, m_n40, 0x40);

// The record of one skill hit on the field (new(0xd8)).
class SkillTargetRecord : public CPtred
{
public:
    bool FUN_141758d70(unsigned long long nTagId, unsigned long long nTagSub, int nOwnerId, int nCasterId, int nSkillId,
        short nLevel, int nMotion, const Unk_StreamPoint& ptDir, int n80, int n84, int nAttack, int n8c);   // fill in
    SkillMotionData* FUN_141759010();                       // the motion
    SkillAttackData* FUN_141759050();                       // the attack
    int FUN_141759090();                                    // whether the attack exists
    const CString& FUN_1417590d0();                         // the arrow effect of an arrow attack
    unsigned FUN_141758fb0();                               // the skill id
    unsigned short FUN_141758fe0();                         // the skill level
    int FUN_141759190();                                    // the start tick
    void FUN_1417591b0();                                   // hands the record to the attack state of the own player

    unsigned long long m_nTagId;                            // +0x18
    unsigned long long m_nTagSub;                           // +0x20
    int m_nCasterId;                                        // +0x28
    int m_nOwnerId;                                         // +0x2c
    int m_nTimeMode;                                        // +0x30
    MS2Ptr<SkillData> m_spSkill;                            // +0x38
    MS2Ptr<SkillLevelData> m_spLevel;                       // +0x48
    int m_nMotion;                                        // +0x58
    int m_nAttack;                                        // +0x5c
    Unk_StreamPoint m_ptDir;                                // +0x60
    Unk_SocketPtr<SkillTargetRecord> m_spLinked;            // +0x70 the cast this one continues into
    int m_n80;                                              // +0x80
    int m_n84;                                              // +0x84
    int m_nStartTick;                                       // +0x88
    int m_n8c;                                              // +0x8c
    ATL::CAtlMap<__int64, int> m_mapHit;                    // +0x90
};
MS2_CHECK_OFFSET(SkillTargetRecord, m_spSkill, 0x38);
MS2_CHECK_OFFSET(SkillTargetRecord, m_spLinked, 0x70);
MS2_CHECK_OFFSET(SkillTargetRecord, m_mapHit, 0x90);
MS2_CHECK_SIZE(SkillTargetRecord, 0xd8);

// The record of one skill cast of a player (new(0x1c0)).
class CSkillRecord : public CPtred
{
public:
    typedef Unk_CubeBoxPtr<std::set<unsigned> > TargetSetPtr;

    CSkillRecord();                                         // 0x141759260
    virtual ~CSkillRecord();                                // 0x141759520
    bool Init(Unk_InventorySkillRequest& kReq);             // 0x1417595d0
    SkillMotionData* FUN_141759830();                       // the motion
    const CString& FUN_1417598a0();                         // the motion effects (kind 2, 3, 4)
    const CString& FUN_1417598e0();
    const CString& FUN_141759920();
    unsigned GetSkillId();                                  // 0x141759960
    unsigned short GetLevel();                              // 0x141759990
    __int64 FUN_1417599c0();                                // the request's +0x40
    __int64 FUN_1417599e0();                                // the cooldown key of the motion
    bool FUN_141759a50();                                   // the motion's flag +0xa0
    float FUN_141759ad0();                                  // the default cooldown of a plain cast
    float FUN_141759b60(double dDelta);                     // the share of the cooldown of the elapsed duration
    float FUN_141759d20(double dDelta, float fRate);        // the share of fRate % of the elapsed duration
    int FUN_141759e40();                                    // the attacks are over
    int FUN_141759eb0();                                    // the last motion is running
    int FUN_141759f20();                                    // the motion is the last one
    int FUN_141759f70();                                    // whether the attack exists
    void FUN_141759fc0();                                   // the attack has started
    void FUN_141759fe0();                                   // the cast is over
    SkillAttackData* FUN_14175a000();                       // the attack
    SkillAttackData* FUN_14175a050(int nAttack);            // one attack of the motion
    SkillAttackData* FUN_14175a0a0(CString strName);        // one attack of the motion by name
    int FUN_14175a130();                                    // the attack's broken offence
    float FUN_14175a170();                                  // the attack's broken force
    float FUN_14175a1b0();                                  // the duration left
    int FUN_14175a210();                                    // the super armor of the skill (0 if not allowed)
    void AddTarget(unsigned nKey, unsigned nTarget);        // 0x14175a280
    int HasTarget(unsigned nKey, unsigned nTarget);         // 0x14175a360
    void SendSkill();                                   // sends the cast again

    int m_nTick;                                            // +0x18
    int m_nSendTick;                                        // +0x1c
    int m_nSendCount;                                       // +0x20
    __int64 m_nCastId;                                      // +0x28
    MS2Ptr<SkillData> m_spSkill;                            // +0x30
    MS2Ptr<SkillLevelData> m_spLevel;                       // +0x40
    Unk_StreamPoint m_ptPos;                                // +0x50
    Unk_StreamPoint m_ptDir;                                // +0x5c
    Unk_StreamPoint m_ptRot;                                // +0x68
    float m_fCooldown;                                      // +0x74 (0: the motion's)
    float m_fDuration;                                      // +0x78
    float m_fElapsed;                                       // +0x7c
    float m_f80;                                            // +0x80
    int m_n84;                                              // +0x84
    int m_n88;                                              // +0x88
    int m_nMotion;                                          // +0x8c
    int m_nAttack;                                          // +0x90
    int m_nAttackIndex;                                     // +0x94
    int m_n98;                                              // +0x98
    int m_n9c;                                              // +0x9c
    int m_nA0;                                              // +0xa0
    int m_nA4;                                              // +0xa4
    int m_nA8;                                              // +0xa8
    bool m_bAC;                                             // +0xac
    bool m_bAD;                                             // +0xad
    bool m_bAE;                                             // +0xae
    int m_nB0;                                              // +0xb0
    CString m_strB8;                                        // +0xb8
    ATL::CAtlMap<int, int> m_mapC0;                         // +0xc0
    ATL::CAtlList<Unk_SocketPtr<CMagicModel> > m_magics;    // +0x108
    ATL::CRBMap<CString, int> m_map138;                     // +0x138
    ATL::CAtlMap<unsigned, TargetSetPtr> m_targets;         // +0x168
    bool m_bEnd;                                            // +0x1b0
    __int64 m_n1b8;                                         // +0x1b8
};
MS2_CHECK_OFFSET(CSkillRecord, m_spLevel, 0x40);
MS2_CHECK_OFFSET(CSkillRecord, m_ptRot, 0x68);
MS2_CHECK_OFFSET(CSkillRecord, m_nB0, 0xb0);
MS2_CHECK_OFFSET(CSkillRecord, m_mapC0, 0xc0);
MS2_CHECK_OFFSET(CSkillRecord, m_magics, 0x108);
MS2_CHECK_OFFSET(CSkillRecord, m_map138, 0x138);
MS2_CHECK_OFFSET(CSkillRecord, m_targets, 0x168);
MS2_CHECK_OFFSET(CSkillRecord, m_bEnd, 0x1b0);
MS2_CHECK_SIZE(CSkillRecord, 0x1c0);

// The record of the damage of one skill hit (new(0xd8)).
class CDamageRecord : public CPtred
{
public:
    CDamageRecord();                                        // 0x14175a4e0 (the implicit dtor is 0x14175b530)
    virtual int vfunc_1();                                  // 0x14175af50
    int Init(unsigned long long nTagId, unsigned long long nTagSub, int nOwnerId, int nCasterId, int nSkillId,
        short nLevel, int nMotion, int nAttack, const Unk_StreamPoint& ptPos, const Unk_StreamPoint& ptDir,
        const Unk_StreamPoint& ptHit);                      // 0x14175a610
    SkillData* FUN_14175a820();                             // the skill
    SkillMotionData* FUN_14175a850();                       // the motion
    SkillAttackData* FUN_14175a8b0();                       // the attack
    int FUN_14175a920();                                    // the attack's name index
    CString FUN_14175a960();                                // the attack's hit effect
    CString FUN_14175aa50();                                // the attack's remain effect
    bool FUN_14175ab40();                                   // the attack ignores the optimal hide of the hit effect
    bool FUN_14175ab80();                                   // ... of the remain effect
    void FUN_14175abc0(int nType, __int64 nDamage);         // adds one damage (type 8 is kept as 3)
    int FUN_14175acc0();                                    // whether the attack exists
    __int64 FUN_14175ac30();                                // the total damage
    unsigned __int64 FUN_14175aeb0();                       // the damage count
    int FUN_14175ad50();                                    // the attack material (the weapon's, for a player)
    int FUN_14175aee0(int nIndex, int& nType);              // the type of one damage

    unsigned long long m_nTagId;                            // +0x18
    unsigned long long m_nTagSub;                           // +0x20
    int m_nCasterId;                                        // +0x28
    int m_nOwnerId;                                         // +0x2c
    int m_nSkillId;                                         // +0x30
    short m_nLevel;                                         // +0x34
    MS2Ptr<SkillData> m_spSkill;                            // +0x38
    MS2Ptr<SkillLevelData> m_spLevel;                       // +0x48
    int m_nMotion;                                        // +0x58
    int m_nAttack;                                        // +0x5c
    Unk_StreamPoint m_ptPos;                                // +0x60
    Unk_StreamPoint m_ptDir;                                // +0x6c
    Unk_StreamPoint m_pt78;                                 // +0x78
    Unk_StreamPoint m_ptHit;                                // +0x84
    ATL::CAtlArray<int> m_types;                            // +0x90
    ATL::CAtlArray<__int64> m_damages;                      // +0xb0
    int m_nD0;                                              // +0xd0
};
MS2_CHECK_OFFSET(CDamageRecord, m_spSkill, 0x38);
MS2_CHECK_OFFSET(CDamageRecord, m_ptHit, 0x84);
MS2_CHECK_OFFSET(CDamageRecord, m_types, 0x90);
MS2_CHECK_OFFSET(CDamageRecord, m_nD0, 0xd0);
MS2_CHECK_SIZE(CDamageRecord, 0xd8);

// The damage of a damage-over-time effect (new(0xe0)).
class CDotDamageRecord : public CDamageRecord
{
public:
    CDotDamageRecord();                                     // 0x14175af90 (the implicit dtor is 0x14175b590)
    virtual int vfunc_1();                                  // 0x14175b070
    int Init(int nOwnerId, int nCasterId, int nEffectLevel, int nType, __int64 nDamage);   // 0x14175aff0
    int FUN_14175b130();                                    // the type of the first damage

    int m_nEffectLevel;                                     // +0xd8
};
MS2_CHECK_OFFSET(CDotDamageRecord, m_nEffectLevel, 0xd8);
MS2_CHECK_SIZE(CDotDamageRecord, 0xe0);

// The damage of a splash (new(0xd8)).
class CSplashDamageRecord : public CDamageRecord
{
public:
    CSplashDamageRecord();                                  // 0x14175b180 (the implicit dtor is 0x14175b5f0)
    int Init(int nCasterId, int nOwnerId, unsigned long long nTagId, int nSkillId, short nLevel, int nMotion,
        int nAttack, const Unk_StreamPoint& ptPos, const Unk_StreamPoint& ptDir);   // 0x14175b1c0
};
MS2_CHECK_SIZE(CSplashDamageRecord, 0xd8);
