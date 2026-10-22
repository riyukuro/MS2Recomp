// skilloverlapcompare.h - the skill table (SkillDataTable: Xml/SkillData/*.xml, Table/glideData.xml), one skill
// (SkillData, RTTI .?AVSkillData@@) and its XML blocks (condition, beginCondition, overlap compare). Recovered from
// ?\skilloverlapcompare.cpp (0x1407e5b80-0x1408001f0); member names follow the XML attribute names, the rest are invented.
// The <basic> sub blocks read by the 0x1408011f0 unit (SkillLevelData, SkillMotionData, the sensor) are declared here
// with the members this unit touches.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/skillattackdata.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // Unk_RangeShape, the attribute enums, Unk_CompareStat

class SkillData;
#include "ms2/commonfiles/skillactionadditional.h"

// The comparison of an overlap / target count condition ("Equals", "Less", ...; 0x1407e7750 / 0x1407e7820).
enum SkillCompareSign
{
    SkillCompareSign_Never = 0,
    SkillCompareSign_Equals = 1,
    SkillCompareSign_Less = 2,
    SkillCompareSign_LessEquals = 3,
    SkillCompareSign_Greater = 4,
    SkillCompareSign_GreaterEquals = 5,
};
enum SkillMainType { SkillMainType_None };
enum SkillRangeType { SkillRangeType_None };
enum SkillImmediateActive { SkillImmediateActive_None };

SkillCompareSign ParseCompareSign(const CString& str);     // 0x1407e7750
CString CompareSignToString(int eSign);                     // 0x1407e7820

// <weapon lh= rh=> of a skill condition.
struct Unk_SkillWeapon
{
    Unk_SkillWeapon();                                      // 0x1407e5b80
    bool operator!=(const Unk_SkillWeapon& o);              // 0x1407e5bb0

    int m_nRightHand;                                       // +0x00 "rh"
    int m_nLeftHand;                                        // +0x04 "lh"
};
MS2_CHECK_SIZE(Unk_SkillWeapon, 8);

// hasBuffCount / hasBuffCountCompare of an additional effect.
class SkillOverlapCompare : public CPtred
{
public:
    SkillOverlapCompare();                                  // 0x1407e5bf0
    bool operator!=(const SkillOverlapCompare& o);          // 0x1407e5c50
    void Load(Unk_140165cf0* pElem);                        // 0x1407e5cc0

    ATL::CAtlArray<unsigned> m_arrHasBuffCount;             // +0x18
    ATL::CAtlArray<SkillCompareSign> m_arrHasBuffCountCompare;  // +0x38
};
MS2_CHECK_SIZE(SkillOverlapCompare, 0x58);

#include "ms2/commonfiles/skillbegincondition.h"

// <condition> of a skill.
struct SkillCondition
{
    SkillCondition();                                       // 0x1407e69f0
    bool operator!=(const SkillCondition& o);               // 0x1407e6ac0
    bool IsDefault();                                       // 0x1407e6cd0
    int Load(Unk_140165cf0* pElem);                         // 0x1407e6f20
    int Save(void* pParent);                                // 0x1407e7210

    float m_fDefaultRechargingCooldownTime;                 // +0x00
    int m_nUseCoolDownShowUI;                               // +0x04
    int m_nOnlyShadowWorld;                                 // +0x08
    int m_nOnlyFlyableMap;                                  // +0x0c
    int m_nAllowBattleRidingState;                          // +0x10
    int m_nOnlyBattleRidingState;                           // +0x14
    int m_nSp;                                              // +0x18 "sp"
    float m_fInvokeEffectFactor;                            // +0x1c
    ATL::CAtlArray<Unk_SkillWeapon> m_arrWeapon;            // +0x20
    ATL::CAtlArray<unsigned> m_arrRequireEffect;            // +0x40
    ATL::CAtlArray<unsigned> m_arrRequireMapCodes;          // +0x60
    ATL::CAtlArray<int> m_arrHasNotAdditionalEffectGroup;   // +0x80
};
MS2_CHECK_SIZE(SkillCondition, 0xa0);

// The <basic> sub blocks of the 0x1408011f0 unit.
enum SkillAutoChange { SkillAutoChange_None };
enum SkillMagicControl { SkillMagicControl_None };
enum SkillMoveType { SkillMoveType_None };

// <combo> of a skill.
struct Unk_SkillBlockA4
{
    Unk_SkillBlockA4();                                     // 0x140802df0
    bool FUN_140802e40(const Unk_SkillBlockA4& o);          // is different
    int Load(Unk_140165cf0* pElem);
    int FUN_140802fc0(int nSkill);                          // the output skill of an input skill (else nSkill)
    int FUN_140802ff0(int nSkill);                          // whether nSkill is the output skill
    int FUN_140803040();                                    // the output skill (0 without a combo)

    unsigned m_nInputSkill;                                 // +0x00 "inputSkill"
    unsigned m_nOutputSkill;                                // +0x04 "outputSkill"
    bool m_bComboSkill;                                     // +0x08
    bool m_bChargingSkill;                                  // +0x09
    bool m_bDisableChargingAttackSkipFrame;                 // +0x0a
    bool m_b0b;                                             // +0x0b
};
MS2_CHECK_SIZE(Unk_SkillBlockA4, 0xc);

// <changeSkill> of a skill.
struct Unk_SkillBlockB0
{
    Unk_SkillBlockB0();                                     // 0x140803330
    bool FUN_1408033b0(const Unk_SkillBlockB0& o);          // is different
    int Load(Unk_140165cf0* pElem);
    ATL::CAtlArray<unsigned> m_arrCheckEffectID;            // +0x00
    ATL::CAtlArray<unsigned short> m_arrCheckEffectLevel;   // +0x20
    ATL::CAtlArray<unsigned> m_arrCheckEffectOverlapCount;  // +0x40
    std::vector<SkillCompareSign> m_vCheckEffectCompareFunc; // +0x60 (default Equals)
    ATL::CAtlArray<unsigned> m_arrChangeSkillID;            // +0x78
    SkillAutoChange m_eAutoChange;                          // +0x98
    int m_n9c;
};
MS2_CHECK_SIZE(Unk_SkillBlockB0, 0xa0);

// <magicControl> of a skill.
struct Unk_SkillBlock150
{
    Unk_SkillBlock150();                                    // 0x140803790
    bool FUN_1408037e0(const Unk_SkillBlock150& o);         // is different
    int Load(Unk_140165cf0* pElem);
    int Save(void* pParent);
    SkillMagicControl m_eEnable;                            // +0x00 "enable"
    float m_fMoveSpeed;                                     // +0x04
    float m_fDuration;                                      // +0x08
    float m_fMaxDistance;                                   // +0x0c
};
MS2_CHECK_SIZE(Unk_SkillBlock150, 0x10);

// <autoTargeting> of a skill.
struct Unk_SkillBlock160
{
    Unk_SkillBlock160();                                    // 0x140803070
    bool FUN_1408030c0(const Unk_SkillBlock160& o);         // is different
    int Load(Unk_140165cf0* pElem);
    int FUN_1408031f0(void* pParent);
    __int64 FUN_140803210();                                // key bits of the block
    float m_fMaxDegree;                                     // +0x00
    float m_fMaxDistance;                                   // +0x04
    float m_fMaxHeight;                                     // +0x08
    int m_nUseMove;                                         // +0x0c "autoTargetUseMove"
};
MS2_CHECK_SIZE(Unk_SkillBlock160, 0x10);

// <push> of a skill.
struct Unk_SkillBlock170
{
    Unk_SkillBlock170();                                    // 0x140802cd0
    bool FUN_140802d00(const Unk_SkillBlock170& o);         // is different
    int FUN_140802d50(Unk_140165cf0* pElem);
    int FUN_140802dd0(void* pParent);
    float m_fUp;                                            // +0x00 "up"
    float m_fBack;                                          // +0x04 "back"
};
MS2_CHECK_SIZE(Unk_SkillBlock170, 8);

// <sensor> of a skill (the range shape; m_nType holds the sensor index once registered).
struct Unk_SkillSensor : public Unk_RangeShape
{
    Unk_SkillSensor();                                      // 0x1408011f0
    bool FUN_140801270(const Unk_SkillSensor& o);           // is different
    void LoadElement(Unk_140165cf0* pElem, CString strName);
    void SaveElement(void* pParent, CString strName);
    unsigned m_nSensorStartDelay;                           // +0x40
    unsigned m_nSensorSplashStartDelay;                     // +0x44
    int m_nSensorForceInvokeByInterval;                     // +0x48
    unsigned m_nTargetHasBuffID;                            // +0x4c
    unsigned m_nTargetHasBuffOverlapCount;                  // +0x50
    unsigned m_nTargetHasNotBuffID;                         // +0x54
    int m_nTargetHasBuffOwner;                              // +0x58
};
MS2_CHECK_SIZE(Unk_SkillSensor, 0x60);

// One motion of a level (RTTI .?AVSkillMotionData@@, 0x110 bytes; the 0x1408011f0 unit).
class SkillMotionData : public CPtred
{
public:
    SkillMotionData();                                      // 0x1408073a0
    bool FUN_140807620(const SkillMotionData& o);           // is different
    int FUN_1408080d0(Unk_140165cf0* pElem);                // reads a <motion>
    void Load(Unk_140165cf0* pElem);               // reads its attributes
    int FUN_140808240(void* pParent);                       // writes a <motion>
    SkillAttackData* FUN_140807e20(int nAttack);            // one attack (0 if out of range)
    SkillAttackData* FUN_140807e80(const CString& strPoint);    // one attack by its point
    SkillAttackData* FUN_140807f20(const CString& strPoint);    // one attack with a pause by its point
    int FUN_140807fd0();                                    // the attack count
    bool FUN_140808000();                                   // whether the move type is 3
    __int64 FUN_140808040();                                // key bits of the movement

    CString m_strSequenceName;                              // +0x18 "sequenceName"
    float m_fSequenceSpeed;                                 // +0x20
    int m_n24;                                              // +0x24
    CString m_strMotionEffect;                              // +0x28
    CString m_strSplashInvokeEffect;                        // +0x30
    CString m_strLoopEffect;                                // +0x38
    CString m_strEndEffect;                                 // +0x40
    CString m_strSplashEndEffect;                           // +0x48
    CString m_strWeaponSequenceName;                        // +0x50
    ATL::CRBMap<CString, CString> m_mapTagEffects;          // +0x58 "strTagEffects"
    CString m_strLoopKeepEffect;                            // +0x88
    CString m_strLoopEndEffect;                             // +0x90
    CString m_strSplashDurationCastEffect;                  // +0x98
    bool m_bA0;                                             // +0xa0 "IgnoreOptimalHideCastEffect"
    bool m_bSplashCastEffectStartDelay;                     // +0xa1
    unsigned m_nSplashLifeTick;                             // +0xa4
    unsigned m_nSplashInvokeCoolTick;                       // +0xa8
    float m_fAC;                                            // +0xac "keyMove" the default cooldown
    SkillMoveType m_eMoveType;                              // +0xb0
    float m_fMoveAngle;                                     // +0xb4
    float m_fB8;                                            // +0xb8 "movedistance" the cooldown (0: m_fAC)
    SkillPushEaseType m_eMoveEaseType;                      // +0xbc
    unsigned m_nIgnoreCollisionGroups;                      // +0xc0
    int m_nHoldWeapon;                                      // +0xc4
    int m_nLoopCount;                                       // +0xc8
    float m_fPushCylinderVelH;                              // +0xcc
    float m_fPushCylinderVelV;                              // +0xd0
    float m_fPushCylinderOuter;                             // +0xd4
    float m_fPushCylinderInner;                             // +0xd8
    float m_fPushCylinderHeight;                            // +0xdc
    CString m_strSelfInputCombo;                            // +0xe0
    bool m_bDoesPlayIdleOnSkillEnd;                         // +0xe8
    int m_nFaceTarget;                                      // +0xec
    int m_nStartNoneBlendDelay;                             // +0xf0
    float m_fAniSkipTime;                                   // +0xf4
    std::vector<MS2Ptr<SkillAttackData> > m_vAttack;        // +0xf8
};
MS2_CHECK_SIZE(SkillMotionData, 0x110);
MS2_CHECK_OFFSET(SkillMotionData, m_mapTagEffects, 0x58);
MS2_CHECK_OFFSET(SkillMotionData, m_fAC, 0xac);
MS2_CHECK_OFFSET(SkillMotionData, m_fB8, 0xb8);
MS2_CHECK_OFFSET(SkillMotionData, m_vAttack, 0xf8);

// One <level> of a skill (RTTI .?AVSkillLevelData@@, 0xc0 bytes; the 0x1408011f0 unit).
class SkillLevelData : public CPtred
{
public:
    SkillLevelData(SkillData* pSkill);                      // 0x140803a30
    bool FUN_140803b30(const SkillLevelData& o);            // is different
    unsigned FUN_140803dc0();                               // the skill id
    unsigned short FUN_140803df0();                         // the level
    SkillData* FUN_140803e10();                             // the skill
    SkillMotionData* FUN_140803e30(CString strSequence);    // one motion by its sequence name
    SkillMotionData* FUN_140803f00(int nMotion);            // one motion (0 if out of range)
    SkillAttackData* FUN_140803f60(int nMotion, int nAttack);   // one attack of a motion (0 if out of range)
    SkillAttackData* FUN_140803fb0(int nMotion, CString strName);   // one attack of a motion by name
    SkillAttackData* FUN_140804030(const CString& strPoint) const; // one attack with a pause, by point
    Unk_RangeProperty* FUN_1408040d0(int nMotion, int nAttack);   // the range of an attack
    Unk_RangeShape* FUN_140804120();                        // the detect shape (0 without one)
    float FUN_140804150(int nMotion, int nAttack);          // the damage rate of an attack
    __int64 FUN_1408041d0(int nMotion, int nAttack);        // the damage value of an attack
    int FUN_140804250();                                    // the stance damage rate
    int FUN_140804270();                                    // the motion count
    float FUN_1408042a0(int nMotion, int nAttack);          // the range value of an attack
    float FUN_140804310();                                  // the largest range value
    int FUN_1408043f0(int nMotion, int nAttack);            // whether the attack exists
    bool FUN_140804450();                                   // whether a motion has a sequence name
    const CString& FUN_140804500(int nKind, int nMotion);   // an effect of a motion (kind 2/3/4)
    int FUN_1408045f0(int nMotion, int nAttack);            // the magic path id of an attack
    float FUN_140804660();                                  // the cooldown
    int Load(Unk_140165cf0* pElem);                // reads a <level>
    int FUN_140804ae0(void* pParent);                       // writes a <level>
    __int64 FUN_140804c90(unsigned __int64 nMotion);        // the cooldown key of a motion (0 if out of range)

    int m_nSp;                                              // +0x18 "sp"
    int m_nEp;                                              // +0x1c "ep"
    int m_nMeso;                                            // +0x20 "meso"
    unsigned m_nCooldown;                                   // +0x24
    float m_fHpRate;                                        // +0x28
    CStringW m_strStringParam;                              // +0x30
    int m_nStanceDamageRate;                                // +0x38
    Unk_RangeShape m_detect;                                // +0x40 "detectProperty"
    std::vector<MS2Ptr<SkillMotionData> > m_vMotion;        // +0x80
    std::vector<MS2Ptr<SkillActionAdditional> > m_vAdditional;  // +0x98
    SkillData* m_pSkill;                                    // +0xb0
    unsigned short m_nLevel;                                // +0xb8
};
MS2_CHECK_SIZE(SkillLevelData, 0xc0);
MS2_CHECK_OFFSET(SkillLevelData, m_detect, 0x40);
MS2_CHECK_OFFSET(SkillLevelData, m_vMotion, 0x80);
MS2_CHECK_OFFSET(SkillLevelData, m_vAdditional, 0x98);

// One <glide> of Table/glideData.xml (RTTI .?AVSkillGlideData@@, 0x80 bytes; the 0x1408011f0 unit).
class SkillGlideData : public CPtred
{
public:
    SkillGlideData();                                       // 0x1408024f0
    bool FUN_140802640(const SkillGlideData& o);            // is different
    void Load(Unk_140165cf0* pElem);               // reads a <glide>
    int FUN_140802a40(Unk_140165cf0* pElem);                // reads the <glideProperty> of a skill
    int FUN_140802a90(void* pParent);
    int FUN_140802ab0();                                    // the id
    CStringW* FUN_140802ad0();

    unsigned m_nId;                                         // +0x18 "id"
    float m_fGravity;                                       // +0x1c
    float m_fHeightLimit;                                   // +0x20
    float m_fHorizontalAccelerate;                          // +0x24
    float m_fHorizontalVelocity;                            // +0x28
    float m_fVerticalAccelerate;                            // +0x2c
    float m_fVerticalVelocity;                              // +0x30
    float m_fVerticalVibrateAmplitude;                      // +0x34
    float m_fVerticalVibrateFrequency;                      // +0x38
    float m_fGlideVerticalAccelerateLimit;                  // +0x3c
    float m_fGlideHorizontalAccelerateLimit;                // +0x40
    CString m_strEffectRun;                                 // +0x48
    CString m_strEffectIdle;                                // +0x50
    CString m_strAniIdle;                                   // +0x58
    CString m_str60;                                        // +0x60
    CString m_strAniRun;                                    // +0x68
    bool m_bOnGroundDisable;                                // +0x70
    int m_nNameTagOffset;                                   // +0x74
    CStringW m_str78;                                       // +0x78
};
MS2_CHECK_SIZE(SkillGlideData, 0x80);

class SkillData : public CCacheData
{
public:
    typedef ATL::CRBMap<unsigned short, MS2Ptr<SkillLevelData> > LevelMap;

    SkillData();                                            // 0x1407e83a0
    virtual ~SkillData();                                   // 0x1407e86e0
    bool operator!=(const SkillData& o);                    // 0x1407e8790
    MS2Ptr<SkillLevelData> FUN_1407e90a0(unsigned short nLevel);  // the data of one level
    void Load(Unk_140165cf0* pElem);                        // 0x1407e9130
    unsigned GetId();                                       // 0x1407e9a40
    SkillMainType GetMainType();                            // 0x1407e9a60
    SkillRangeType GetRangeType();                          // 0x1407e9a80
    ElementType GetElement();                               // 0x1407e9aa0
    unsigned short FUN_1407e9ac0();                         // the level cap a sub skill follows its parent skill up to
    unsigned short FUN_1407e9b10();                         // the max level
    unsigned GetRechargeMaxCount();                         // 0x1407e9b30
    unsigned GetOriginId();                                 // 0x1407e9b50 (own id when there is no origin)
    unsigned GetRechargeId();                               // 0x1407e9b90
    int FUN_1407e9bd0();
    unsigned __int64 GetCooldownKey();     // cooldown group << 32 | id                  // 0x1407e9c40
    unsigned GetCooldownGroupId();                          // 0x1407e9c70
    int GetParam1();                                        // 0x1407e9c90
    CString GetParamStr();                                  // 0x1407e9cb0
    Unk_SkillSensor* GetSensor();                           // 0x1407e9d00
    bool FUN_1407e9d30();
    bool FUN_1407e9d70();
    bool FUN_1407e9de0();
    bool FUN_1407e9e20();
    bool FUN_1407e9ea0();
    bool FUN_1407e9ef0();
    bool FUN_1407e9f30();                                   // checked before handing out level 1 of an unowned skill
    bool HasOrigin();                                       // 0x1407e9fb0
    bool FUN_1407e9ff0();
    void FUN_1407ea010();
    __int64 FUN_1407ea030();                                // key bits of the targeting
    std::vector<MS2Ptr<SkillAttackData> > GetAttacks() const;   // 0x1407ea0d0 the attacks of every level

    SkillGroupType m_eGroupType;                            // +0x28 kinds "groupType"
    unsigned m_nJump;                                       // +0x2c kinds "jump"
    int m_nOffsetNameTag;                                   // +0x30
    bool m_bContinue;                                       // +0x34
    bool m_bUnrideOnUse;                                    // +0x35
    SkillImmediateActive m_eImmediateActive;                // +0x38
    bool m_bReleaseObjectWeapon;                            // +0x3c
    bool m_bDisableWater;                                   // +0x3d
    bool m_bHoldAttack;                                     // +0x3e
    unsigned m_nGroupIDs;                                   // +0x40
    CString m_strIcon;                                      // +0x48 ui "icon"
    DotDamageType m_eAttackType;                            // +0x50
    bool m_bDisableChangeSkillIconEffect;                   // +0x54
    bool m_bShowCastingBar;                                 // +0x55
    int m_nTooltip;                                         // +0x58
    MS2Ptr<CXmlData> m_spParamCastingBar;                   // +0x60
    bool m_bBattle;                                         // +0x70 stateAttr
    int m_nAutoTargeting;                                   // +0x74
    unsigned m_nAutoTargetingType;                          // +0x78
    bool m_bNotKeepEffect;                                  // +0x7c
    bool m_bKeyIsDown;                                      // +0x7d
    bool m_bUseDefaultSkill;                                // +0x7e
    bool m_bUseInGameTime;                                  // +0x7f
    bool m_bClearCooldownFromPVPZone;                       // +0x80
    bool m_bIgnoreReduceCooldown;                           // +0x81
    bool m_bMovingInMovekey;                                // +0x82
    unsigned m_nUseDefaultSkillID;                          // +0x84
    int m_nMoveType;                                        // +0x88
    int m_nSuperArmor;                                      // +0x8c
    ApplyFieldType m_eSuperArmorApplyFieldType;             // +0x90
    unsigned m_nCooldownGroupID;                            // +0x94
    unsigned m_nRechargeMaxCount;                           // +0x98
    bool m_bRechargeShareOrigin;                            // +0x9c
    unsigned m_nSplashMaxCount;                             // +0xa0
    Unk_SkillBlockA4 m_blockA4;                             // +0xa4
    Unk_SkillBlockB0 m_blockB0;                             // +0xb0
    Unk_SkillBlock150 m_block150;                           // +0x150
    Unk_SkillBlock160 m_block160;                           // +0x160
    Unk_SkillBlock170 m_block170;                           // +0x170
    SkillCondition m_condition;                             // +0x178
    unsigned m_nId;                                         // +0x218
    unsigned m_nOriginId;                                   // +0x21c
    unsigned short m_nMaxLevel;                             // +0x220
    SkillMainType m_eMainType;                              // +0x224
    SkillRangeType m_eRangeType;                            // +0x228
    ElementType m_eElement;                                 // +0x22c
    int m_nParam1;                                          // +0x230
    CString m_strParamStr;                                  // +0x238
    Unk_SkillSensor m_sensor;                               // +0x240
    bool m_b2a0;                                            // +0x2a0
    LevelMap m_levels;                                      // +0x2a8
};
MS2_CHECK_SIZE(SkillData, 0x2d8);
MS2_CHECK_OFFSET(SkillData, m_spParamCastingBar, 0x60);
MS2_CHECK_OFFSET(SkillData, m_blockA4, 0xa4);
MS2_CHECK_OFFSET(SkillData, m_condition, 0x178);
MS2_CHECK_OFFSET(SkillData, m_nId, 0x218);
MS2_CHECK_OFFSET(SkillData, m_sensor, 0x240);
MS2_CHECK_OFFSET(SkillData, m_levels, 0x2a8);

// The skill table. Abstract: the additional effect files are read by the derived table.
class SkillDataTable
{
public:
    SkillDataTable();                                       // 0x1407edd10
    virtual void LoadAdditionalFile(CString strPath) = 0;   // slot 0
    void LoadSkillData();                                   // 0x1407eddd0
    void LoadAdditional();                                  // 0x1407edfe0
    MS2Ptr<SkillData> GetSkillData(unsigned nSkillId);      // 0x1407ee1d0
    MS2Ptr<SkillLevelData> GetSkillLevelData(unsigned nSkillId, unsigned short nLevel);   // 0x1407ee2f0
    std::set<unsigned>* GetGroupSkills(unsigned nGroupId);  // 0x1407ee3b0
    MS2Ptr<SkillGlideData> GetGlideData(int nGlideId);      // 0x1407ee470
    void LoadSkillFile(CString strPath);                    // 0x1407ee530
    void AddSkill(MS2Ptr<SkillData> spSkill);               // 0x1407ee730
    void IndexSensors(MS2Ptr<SkillData> spSkill);           // 0x1407ee9f0
    void FUN_1407eec60(MS2Ptr<SkillData> spSkill);
    void FindSkillFiles(std::vector<CString>& out);         // 0x1407eece0
    void FindAdditionalFiles(std::vector<CString>& out);    // 0x1407eedb0
    bool Reload();                                          // 0x1407eee80 reloads the changed files
    void LoadGlideData();                                   // 0x1407eef70

    CLockCriticalSection m_cs;                                          // +0x08
    std::unordered_map<unsigned, MS2Ptr<SkillData> > m_skills;          // +0x38
    std::unordered_map<unsigned, std::set<unsigned> > m_groups;         // +0x78
    std::unordered_map<int, MS2Ptr<SkillGlideData> > m_glides;          // +0xb8
    std::vector<MS2Ptr<CCacheData> > m_skillCaches;                     // +0xf8
    std::vector<MS2Ptr<CCacheData> > m_additionalCaches;                // +0x110
    int m_nSensorCount;                                                 // +0x128
    std::map<CString, int> m_sensorIndex;                               // +0x130
};
MS2_CHECK_SIZE(SkillDataTable, 0x140);
MS2_CHECK_OFFSET(SkillDataTable, m_skills, 0x38);
MS2_CHECK_OFFSET(SkillDataTable, m_skillCaches, 0xf8);
MS2_CHECK_OFFSET(SkillDataTable, m_sensorIndex, 0x130);
