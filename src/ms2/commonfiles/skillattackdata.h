// skillattackdata.h - SkillAttackData (RTTI .?AVSkillAttackData@@, 0x280 bytes): one <attack> of a skill motion and its
// XML blocks (arrow, damage, pause, chain). Recovered from ?\skillattackdata.cpp (0x1407dee30-0x1407e5b80); member
// names follow the XML attribute names (the v2525 snapshot agrees with the exe layout).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <bitset>
#include <vector>
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // Unk_RangeProperty
#include "ms2/commonfiles/skillactionadditional.h"
#include "ms2/commonfiles/skillactionskill.h"

// Attribute enums (values unrecovered).
enum SkillAttackType { };
enum SkillNonTarget { };
enum SkillGrabTargetType { };
enum SkillUnrideOnHit { };
enum SkillAttackMethodType { };
enum SkillPushType { };
enum SkillPushEaseType { };
enum SkillPushApplyField { };
enum SkillStateHit { };

struct SkillArrow
{
    SkillArrow();                                           // 0x1407dee30
    int Load(Unk_140165cf0* pElem);                         // 0x1407df190
    void Save(void* pParent);                               // 0x1407df6e0
    bool operator!=(const SkillArrow& o) const;             // 0x1407def80
    int IsNonTargetOne() const;                             // 0x1407dfbb0

    int m_nOverlap;                                         // +0x00
    int m_nExplosion;                                       // +0x04
    SkillNonTarget m_eNonTarget;                            // +0x08
    int m_nBounceType;                                      // +0x0c
    int m_nBounceCount;                                     // +0x10
    float m_fBounceRadius;                                  // +0x14
    int m_nBounceOverlap;                                   // +0x18
    int m_nRayType;                                         // +0x1c
    int m_nRayPhysxTest;                                    // +0x20
    efd::Point3 m_collision;                                // +0x24
    efd::Point3 m_collisionAdd;                             // +0x30
    CString m_strEffect;                                    // +0x40
    CString m_strEffectRemain;                              // +0x48
    CString m_strEffectDestroy;                             // +0x50
    CString m_strTargetKeepEffect;                          // +0x58
    CString m_strEffectInvoke;                              // +0x60
};
MS2_CHECK_SIZE(SkillArrow, 0x68);

struct SkillDamage
{
    SkillDamage();                                          // 0x1407dfbf0
    int Load(Unk_140165cf0* pElem);                         // 0x1407e01c0
    void Save(void* pParent);                               // 0x1407e0720
    bool operator!=(const SkillDamage& o) const;            // 0x1407dfdf0
    int RollPush() const;                                   // 0x1407e0ee0
    int HasDamage() const;                                  // 0x1407e0f40
    SkillPushType GetPush(int nState) const;                // 0x1407e0f90

    int m_nCount;                                           // +0x00
    int m_nHand;                                            // +0x04
    float m_fRate;                                          // +0x08
    __int64 m_nValue;                                       // +0x10
    int m_nNameIndex;                                       // +0x18 numbered by SkillDataTable from m_strEffectHit
    CString m_strEffectHit;                                 // +0x20
    CString m_strEffectRemain;                              // +0x28
    int m_nIsConstDamageValue;                              // +0x30
    bool m_bIgnoreOptimalHideDamageHitEffect;               // +0x34
    bool m_bIgnoreOptimalHideDamageRemainEffect;            // +0x35
    int m_nAttackMaterial;                                  // +0x38
    float m_fHitSpeedRate;                                  // +0x3c
    float m_fHitPauseTime;                                  // +0x40
    float m_fDamagedVibrateRatio;                           // +0x44
    float m_fDamageByTargetMaxHP;                           // +0x48
    __int64 m_nConstDamageByTargetHP;                       // +0x50
    __int64 m_nConstDamageByTargetSP;                       // +0x58
    SkillPushType m_ePush;                                  // +0x60
    float m_fPushDistance;                                  // +0x64
    float m_fPushDuration;                                  // +0x68
    float m_fPushProb;                                      // +0x6c
    SkillPushEaseType m_ePushEaseType;                      // +0x70
    SkillPushApplyField m_ePushApplyField;                  // +0x74
    float m_fPushUpDistance;                                // +0x78
    int m_nPushDown;                                        // +0x7c
    int m_nPushFall;                                        // +0x80
    int m_nPushPriority;                                    // +0x84
    int m_nPushPriorityHitImmune;                           // +0x88
    CString m_strPushAnimation;                             // +0x90
    SkillStateHit m_eStateHitIgnore;                        // +0x98
    SkillStateHit m_eStateHitOnly;                          // +0x9c
    int m_nSuperArmorBreak;                                 // +0xa0
    int m_nInvokeEffectDisable;                             // +0xa4
    int m_nDamageEventDisable;                              // +0xa8
};
MS2_CHECK_SIZE(SkillDamage, 0xb0);

struct SkillPause
{
    SkillPause();                                           // 0x1407e1020
    int Load(Unk_140165cf0* pElem);                         // 0x1407e10c0
    int Save(void* pParent) const;                          // 0x1407e1150
    bool operator!=(const SkillPause& o) const;             // 0x1407e1060
    float GetShakeRate() const;                             // 0x1407e1170

    float m_fDuration;                                      // +0x00
    float m_fShakeDuration;                                 // +0x04
    float m_fAmp;                                           // +0x08
};
MS2_CHECK_SIZE(SkillPause, 0xc);

struct SkillChain
{
    SkillChain();                                           // 0x1407e11b0
    int Load(Unk_140165cf0* pElem);                         // 0x1407e1220
    int Save(void* pParent) const;                          // 0x1407e12d0
    bool operator!=(const SkillChain& o) const;             // 0x1407e11e0
    int HasEffect() const;                                  // 0x1407e12f0

    CString m_strEffect;
};
MS2_CHECK_SIZE(SkillChain, 8);

class SkillAttackData : public CPtred
{
public:
    SkillAttackData();                                      // 0x1407e1330
    bool operator!=(const SkillAttackData& o);              // 0x1407e1500
    unsigned char HasPause() const;                         // 0x1407e19c0
    SkillAttackMethodType GetAttackMethodType() const;      // 0x1407e1a10
    const CString& GetArrowEffect() const;                  // 0x1407e1a30
    int Load(Unk_140165cf0* pElem);                         // 0x1407e1a50
    int Save(void* pParent);                                // 0x1407e2180

    SkillAttackType m_eAttackType;                          // +0x18 "attacktype"
    int m_unk1c;
    CString m_strPoint;                                     // +0x20
    unsigned m_nPointGroupID;                               // +0x28
    int m_nTargetCount;                                     // +0x2c
    int m_nMagicPathID;                                     // +0x30
    int m_nCubeMagicPathID;                                 // +0x34
    int m_nDirection;                                       // +0x38
    int m_nHitImmuneBreak;                                  // +0x3c
    int m_nBrokenOffence;                                   // +0x40
    float m_fBrokenForce;                                   // +0x44
    SkillGrabTargetType m_eGrabTargetType;                  // +0x48
    ATL::CAtlArray<CString> m_arrGrabNodeCategory;          // +0x50
    CString m_strCompulsionType;                            // +0x70 (only compared and saved)
    std::bitset<5> m_compulsionType;                        // +0x78
    SkillUnrideOnHit m_eUnrideOnHit;                        // +0x7c
    int m_nReleaseObjectWeaponOnHit;                        // +0x80
    Unk_RangeProperty m_range;                              // +0x88
    SkillArrow m_arrow;                                     // +0x100
    SkillDamage m_damage;                                   // +0x168
    std::vector<MS2Ptr<SkillActionAdditional> > m_vAdditional;  // +0x218
    std::vector<MS2Ptr<SkillActionSkill> > m_vSkill;        // +0x230
    SkillPause m_pause;                                     // +0x248
    std::vector<unsigned> m_vSplashActiveSkillID;           // +0x258
    SkillChain m_chain;                                     // +0x270
    SkillAttackMethodType m_eAttackMethodType;              // +0x278
};
MS2_CHECK_SIZE(SkillAttackData, 0x280);
