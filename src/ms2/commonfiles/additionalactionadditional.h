// additionalactionadditional.h - the additional effect (buff/debuff) table rows: AdditionalData (one <additional> of
// Table/additionaleffect*.xml), its per level AdditionalLevelData and the chained actions AdditionalActionAdditional /
// AdditionalActionSkill (RTTI names). Header name assumed from the unit path; member names are the XML attribute
// each member is read from, sub-struct names are the XML element names (invented as type names).
// Owner unit ?\additionalactionadditional.cpp (0x14016fda0-0x140195470 .text$mn): ctors, dtors, Load, IsDifferent and
// all inline sub-struct members below are emitted there.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include <vector>
#include <NiPoint3.h>
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cobjectcount.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/gostate.h"     // Unk_RequireState (requireStates)
#include "ms2/placeholder/gosubstate.h"   // Unk_RequireSubState (requireSubStates)

class Unk_140165cf0;    // game TinyXML element (ms2/placeholder/xmlattr.h)
class COutputStream;
class CInPacket;

// Enum attributes (stored as their numeric value). Names invented; they sort in the exe order of their
// XmlValue<E> instantiations (0x140178970 ... 0x140178f10).
enum AdditionalSpecialEffectType { AdditionalSpecialEffectType_None };
enum AdditionalSpreadType { AdditionalSpreadType_None };
enum AdditionalUIIconOnOff { AdditionalUIIconOnOff_Off, AdditionalUIIconOnOff_On, AdditionalUIIconOnOff_Unk2 };
enum ApplyFieldType { ApplyFieldType_None };
enum BuffMainType { BuffMainType_None };
enum CompulsionEventType { CompulsionEventType_None };
enum DotDamageType { DotDamageType_None };
enum ElementType { ElementType_None };
enum EventConditionType { EventConditionType_None };
enum SkillGroupType { SkillGroupType_None };
enum UIShieldType { UIShieldType_None };
// Enum attributes stored by name.
enum Unk_CompareOp { Unk_CompareOp_None };                  // casterHpOp (FUN_140219400)
#include "ms2/placeholder/dungeongrouptype.h"                // Unk_DungeonGroupType: dungeonGroupType (FUN_140218c20)
enum SAType { SAType_None };                                // <SpecialAbility><v type=...> (FUN_14081dd80)
enum Unk_SkillMasteryType { Unk_SkillMasteryType_None };              // requireMasteryTypes (FUN_14021c400)

// One <Additional> action: another additional effect started by this one. 0x150 bytes.
class AdditionalActionAdditional : public CPtred
{
public:
    AdditionalActionAdditional();                       // 0x14016fda0
    virtual ~AdditionalActionAdditional() = default;          // ??_G 0x140185340, dtor 0x140183c80

    bool IsDifferent(const AdditionalActionAdditional& o);      // 0x140170010
    int Load(Unk_140165cf0* pElem);                     // 0x140170160

    int m_nRandomCast;                                  // +0x18 "randomCast"
    ATL::CAtlArray<unsigned short> m_arrLevel;          // +0x20 "level"
    ATL::CAtlArray<unsigned> m_arrSkillID;              // +0x40 "skillID"
    ATL::CAtlArray<unsigned> m_arrLinkSkillID;          // +0x60 "linkSkillID"
    int m_nSkillTarget;                                 // +0x80
    int m_nSkillOwner;                                  // +0x84 (1 when 0)
    bool m_bActiveByIntervalTick;                       // +0x88
    float m_fProbability;                               // +0x8c (1.0)
    bool m_bIsAllowDead;                                // +0x90
    EventConditionType m_eOwnerEvent;                   // +0x94
    bool m_bOwnerEventIgnore;                           // +0x98
    std::vector<unsigned> m_vOwnerEventSkillID;         // +0xa0
    std::vector<unsigned> m_vOwnerEventNoSkillID;       // +0xb8
    std::vector<unsigned> m_vOwnerEventAdditionalID;    // +0xd0
    unsigned m_nOwnerAdditionalID;                      // +0xe8
    unsigned short m_nOwnerAdditionalLevel;             // +0xec
    unsigned m_nOwnerAdditionalCount;                   // +0xf0
    bool m_bOwnerAdditionalMine;                        // +0xf4
    unsigned m_nOwnerNoAdditionalID;                    // +0xf8
    float m_fOwnerHpLess;                               // +0xfc
    float m_fOwnerHpOver;                               // +0x100
    float m_fOwnerSpLess;                               // +0x104
    int m_nOwnerRange;                                  // +0x108
    int m_nOwnerRangeCountLess;                         // +0x10c
    int m_nOwnerRangeCountOver;                         // +0x110
    unsigned m_nCasterAdditionalID;                     // +0x114
    unsigned m_nCasterAdditionalCount;                  // +0x118
    unsigned m_nCasterNoAdditionalID;                   // +0x11c
    EventConditionType m_eCasterEvent;                  // +0x120
    unsigned m_nTargetAdditionalID;                     // +0x124
    unsigned m_nTargetAdditionalCount;                  // +0x128
    bool m_bTargetAdditionalMine;                       // +0x12c
    unsigned m_nTargetNoAdditionalID;                   // +0x130
    std::set<unsigned> m_setTargetNpcIDs;               // +0x138
    float m_fTargetHpLess;                              // +0x148
    bool m_bTargetNpcOnly;                              // +0x14c
};
MS2_CHECK_SIZE(AdditionalActionAdditional, 0x150);
MS2_CHECK_OFFSET(AdditionalActionAdditional, m_vOwnerEventSkillID, 0xa0);
MS2_CHECK_OFFSET(AdditionalActionAdditional, m_setTargetNpcIDs, 0x138);

// One <Skill> action: a skill cast by the effect. 0x48 bytes.
class AdditionalActionSkill : public CPtred
{
public:
    AdditionalActionSkill();                            // 0x140170830
    virtual ~AdditionalActionSkill() {}                 // ??_G 0x140185380, dtor 0x140183d20

    bool IsDifferent(const AdditionalActionSkill& o);   // 0x1401708f0
    int Load(Unk_140165cf0* pElem);                     // 0x140170a10
    int FUN_140170b50(Unk_140165cf0* pElem, CString strName);   // 0x140170b50: unused hook, returns 1

    unsigned m_nSkillID;                                // +0x18
    unsigned short m_nLevel;                            // +0x1c (1)
    unsigned m_nLinkSkillID;                            // +0x20
    unsigned m_nDelay;                                       // +0x24 (tick)
    unsigned m_nRemoveDelay;                                 // +0x28 (tick)
    unsigned m_nInterval;                                    // +0x2c (tick)
    int m_nImmediateActive;                             // +0x30
    int m_nFireCount;                                   // +0x34 (1)
    int m_nUseDirection;                                // +0x38
    int m_nUnk3c;                                       // +0x3c (compared, never read)
    int m_nChainDistance;                               // +0x40
};
MS2_CHECK_SIZE(AdditionalActionSkill, 0x48);

class AdditionalLevelData;

// One <additional> row. 0x50 bytes.
class AdditionalData : public CPtred
{
public:
    AdditionalData();                                   // 0x140170b90
    virtual ~AdditionalData() = default;                      // ??_G 0x1401853c0, dtor 0x140183d40
    virtual void ReadLevel(Unk_140165cf0* pElem);       // slot 1, 0x140171050: one <level>

    unsigned GetID();                                   // 0x140170c20
    bool Load(Unk_140165cf0* pElem);                    // 0x140170c60
    BuffMainType GetMainType();                         // 0x140170e20
    bool IsDebuff();                                    // 0x140170e40
    unsigned GetCategory();                             // 0x140170e60
    bool IsSkillGroupType();                            // 0x140170e80: skillGroupType 1 or 2
    bool GetFlag48();                                   // 0x140170ec0
    bool GetFlag49();                                   // 0x140170ee0
    void GetLevels(std::vector<MS2Ptr<AdditionalLevelData> >& vOut);   // 0x140170f00
    int GetFirstLevelGroupIDs();                        // 0x140170f80
    MS2Ptr<AdditionalLevelData> GetLevel(unsigned short nLevel);       // 0x140170fe0

    unsigned m_nID;                                     // +0x18 "id"
    BuffMainType m_eMainType;                           // +0x1c
    bool m_bIsDebuff;                                   // +0x20
    unsigned m_nCategory;                               // +0x24
    SkillGroupType m_eSkillGroupType;                   // +0x28
    std::vector<MS2Ptr<AdditionalLevelData> > m_vLevel; // +0x30 (sorted by level)
    bool m_b48;                                         // +0x48 FUN_140829c80(id)
    bool m_b49;                                         // +0x49 FUN_140829cf0(id)
};
MS2_CHECK_SIZE(AdditionalData, 0x50);
MS2_CHECK_OFFSET(AdditionalData, m_vLevel, 0x30);

// rangeProperty of <Spread> (owner: the 0x1408001f0 unit; ctor 0x140800860, read 0x140800b50, compare 0x140800920).
struct Unk_RangeShape
{
    int m_nType;                        // +0x00
    CString m_str;                      // +0x08
    float m_f10, m_f14, m_f18, m_f1c;   // +0x10 (copied one by one in 0x1401945c0)
    efd::Point3 m_pt20;                  // +0x20
    efd::Point3 m_pt2c;                  // +0x2c
    float m_f38;                        // +0x38

    Unk_RangeShape();                                       // 0x1408001f0
    bool FUN_1408002b0(const Unk_RangeShape& o);            // is different
    void FUN_1408003b0(Unk_140165cf0* pElem);               // reads the shape attributes
    void FUN_140800570(void* pElem);                        // writes the shape attributes
    // Declared (0x140184190), so SpreadProperty::Clear assigns through the copy operator= 0x1401945c0 like the exe.
    ~Unk_RangeShape() {}
};
MS2_CHECK_SIZE(Unk_RangeShape, 0x40);
// The shape is a base: ~Unk_RangeProperty 0x140184170 calls ~Unk_RangeShape 0x140184190 on `this` itself.
class Unk_RangeProperty : public Unk_RangeShape
{
public:
    Unk_RangeProperty();                                                // 0x140800860
    ~Unk_RangeProperty() {}                                             // 0x140184170 (no move: copy operator= 0x1401944c0)
    bool FUN_140800920(const Unk_RangeProperty& o);                     // is different
    int FUN_140800b50(Unk_140165cf0* pElem, CString strName);           // reads the named child element
    void FUN_140800de0(void* pParent, CString strName);                 // writes the named child element

    // Thirteen scalars, not an array: SpreadProperty::Clear 0x140192e20 has no /GS cookie for the 0x78 temporary and
    // operator= 0x1401944c0 copies them one by one.
    int m_n40, m_n44, m_n48, m_n4c; // +0x40
    int m_n50, m_n54, m_n58, m_n5c; // +0x50
    int m_n60, m_n64, m_n68, m_n6c; // +0x60
    int m_n70;                      // +0x70
};
MS2_CHECK_SIZE(Unk_RangeProperty, 0x78);

// <compareStat> of <Condition><owner> (owner: ?\skilloverlapcompare.cpp; ctor 0x1407e5db0, read 0x1407e5e70).
class Unk_CompareStat
{
public:
    Unk_CompareStat();                                                  // 0x1407e5db0
    int FUN_1407e5e70(Unk_140165cf0* pElem);
    bool FUN_1407e5e00(const Unk_CompareStat& o);                       // is different

    float m_f0;
    int m_n4;                           // -1
    int m_n8;
    int m_nC;
};
MS2_CHECK_SIZE(Unk_CompareStat, 0x10);

// Condition block read from the <Condition> element by 0x1407e6080 (owner: ?\skilloverlapcompare.cpp).
class Unk_SkillOverlapCondition
{
public:
    Unk_SkillOverlapCondition();                                        // 0x1407e5f80
    void FUN_1407e6080(Unk_140165cf0* pElem);
    bool FUN_1407e5fe0(const Unk_SkillOverlapCondition& o);             // is different

    bool m_b0;
    int m_n4[5];
};
MS2_CHECK_SIZE(Unk_SkillOverlapCondition, 0x18);

// One <level> of an <additional>. 0x6b0 bytes.
class AdditionalLevelData : public CObjectCount<AdditionalLevelData>, public CPtred
{
public:
    // <UI>, 0x18 bytes.
    struct UIProperty
    {
        // @0x140192630
        UIProperty() { Clear(); }
        // @0x140192670
        bool IsDifferent(const UIProperty& o)
        {
            if (m_eIconOnOff != o.m_eIconOnOff) return true;
            if (m_bIconBalloonOnOff != o.m_bIconBalloonOnOff) return true;
            if (m_bIsHideCooltime != o.m_bIsHideCooltime) return true;
            if (m_strIcon != o.m_strIcon) return true;
            if (m_nPriority != o.m_nPriority) return true;
            if (m_bInfinitySP != o.m_bInfinitySP) return true;
            if (m_bVisibleItemOption != o.m_bVisibleItemOption) return true;
            return false;
        }
        // @0x140192750
        void Clear()
        {
            m_eIconOnOff = AdditionalUIIconOnOff_On;
            m_bIconBalloonOnOff = false;
            m_strIcon = "";
            m_bIsHideCooltime = false;
            m_nPriority = 0;
            m_bInfinitySP = false;
            m_bVisibleItemOption = true;
        }
        bool FUN_1401927c0(bool bFlag);                 // 0x1401927c0: icon shown (_Unk2 only with bFlag)

        AdditionalUIIconOnOff m_eIconOnOff;     // +0x00 "iconOnOff"
        bool m_bIconBalloonOnOff;               // +0x04
        bool m_bIsHideCooltime;                 // +0x05
        CString m_strIcon;                      // +0x08 "icon"
        int m_nPriority;                        // +0x10
        bool m_bInfinitySP;                     // +0x14
        bool m_bVisibleItemOption;              // +0x15
    };

    // <Status> and <SpecialAbility>, 0x60 bytes.
    struct StatusProperty
    {
        // @0x140191d60
        StatusProperty() { Clear(); }
        bool IsDifferent(const StatusProperty& o);      // 0x140191db0
        void Clear();                                   // 0x140191f40

        std::map<SAType, int> m_mapSA;                  // +0x00 <SpecialAbility><v type value>
        CompulsionEventType m_eCompulsionEventTypes;    // +0x10
        float m_fCompulsionEventRate;                   // +0x14
        ATL::CAtlArray<unsigned> m_arrCompulsionEventSkillCodes;   // +0x18
        float m_fItemRecoveryHPRate;                    // +0x38
        float m_fHealRecoveryHPRate;                    // +0x3c
        float m_fResWapR;                               // +0x40
        float m_fResBapR;                               // +0x44
        float m_fResCadR;                               // +0x48
        float m_fResAtpR;                               // +0x4c
        float m_fResEvpR;                               // +0x50
        float m_fResPenR;                               // +0x54
        __int64 m_nDeathResistanceHP;                   // +0x58
    };

    // <Motion><OverlapKeepEffect>: effect per overlap count, 0x30 bytes.
    struct OverlapKeepEffectProperty
    {
        // @0x140183150
        OverlapKeepEffectProperty() { Clear(); }
        bool IsDifferent(const OverlapKeepEffectProperty& o);   // 0x1401915c0
        // @0x1401918c0
        void Clear()
        {
            m_mapStart.clear();
            m_mapKeep.clear();
            m_mapEnd.clear();
        }
        // @0x140191910
        bool HasKeep()
        {
            if (m_mapKeep.size() != 0)
                return true;
            return false;
        }

        std::map<unsigned, CString> m_mapStart;         // +0x00
        std::map<unsigned, CString, std::greater<unsigned> > m_mapKeep;   // +0x10 (descending: 0x140185050)
        std::map<unsigned, CString, std::greater<unsigned> > m_mapEnd;    // +0x20
    };

    // <Motion>, 0xc8 bytes.
    struct MotionProperty
    {
        // @0x140183090
        MotionProperty() { Clear(); }
        bool IsDifferent(const MotionProperty& o);      // 0x140191940
        void Clear();                                   // 0x140191c40

        CString m_strStartEffect;                       // +0x00
        CString m_strKeepEffect;                        // +0x08
        CString m_strStopEffect;                        // +0x10
        CString m_strInvokeEffect;                      // +0x18
        OverlapKeepEffectProperty m_overlapKeepEffect;  // +0x20
        bool m_bIgnoreOptimalHideStartEffect;           // +0x50
        float m_fAlphaBlending;                         // +0x54 (1.0)
        int m_nHide;                                    // +0x58
        unsigned m_nStun;                               // +0x5c
        CString m_strStunAnimation;                     // +0x60
        int m_nConfusionMove;                           // +0x68
        int m_nSoundPitch;                              // +0x6c
        int m_nAbnormalImmuneBreak;                     // +0x70
        int m_nRevival;                                 // +0x74
        float m_fScale;                                 // +0x78
        unsigned m_nIgnoreCollisionGroups;              // +0x7c
        int m_nNoFly;                                   // +0x80
        unsigned m_nSuperArmor;                         // +0x84
        ApplyFieldType m_eSuperArmorApplyFieldType;     // +0x88
        std::vector<unsigned> m_vClearCondition;        // +0x90
        unsigned m_nSkillUseDisable;                    // +0xa8
        std::set<unsigned> m_setSkillUseDisableIDs;     // +0xb0
        float m_fFixedZRotation;                        // +0xc0
    };

    // <DotDamage>, 0x28 bytes.
    struct DotDamageProperty
    {
        // @0x140183000
        DotDamageProperty() : m_eType(DotDamageType_None) { Clear(); }
        bool IsDifferent(const DotDamageProperty& o);   // 0x140192170
        void Clear();                                   // 0x1401922b0

        DotDamageType m_eType;                          // +0x00 "type"
        int m_nValue;                                   // +0x04
        float m_fRate;                                  // +0x08 "rate"
        ElementType m_eElement;                         // +0x0c
        float m_fDamageByTargetMaxHP;                   // +0x10
        float m_fCasterRecoveryHpByDamage;              // +0x14
        int m_nSoundMaterial;                           // +0x18
        int m_nSpValue;                                 // +0x1c
        int m_nEpValue;                                 // +0x20
        bool m_bUseGrade;                               // +0x24
        bool m_bIsConstDotDamageValue;                  // +0x25
        bool m_bNotKill;                                // +0x26
    };

    // <DotBuff>, 0xc bytes.
    struct DotBuffProperty
    {
        // @0x140182fe0
        DotBuffProperty() { Clear(); }
        // @0x140192350
        bool IsDifferent(const DotBuffProperty& o)
        {
            if (m_nTarget != o.m_nTarget) return true;
            if (m_nBuffID != o.m_nBuffID) return true;
            if (m_nBuffLevel != o.m_nBuffLevel) return true;
            return false;
        }
        // @0x1401923b0
        void Clear() { m_nTarget = 0; m_nBuffID = 0; m_nBuffLevel = 0; }

        int m_nTarget;                                  // +0x00
        unsigned m_nBuffID;                             // +0x04
        unsigned short m_nBuffLevel;                    // +0x08
    };

    // <Consume>, 0xc bytes.
    struct ConsumeProperty
    {
        // @0x140182fc0
        ConsumeProperty() { Clear(); }
        // @0x1401923e0
        bool IsDifferent(const ConsumeProperty& o)
        {
            if (m_fHpRate != o.m_fHpRate) return true;
            if (m_fSpRate != o.m_fSpRate) return true;
            if (m_fSpConsumeChangeHpRate != o.m_fSpConsumeChangeHpRate) return true;
            return false;
        }
        // @0x140192440
        void Clear() { m_fHpRate = 0; m_fSpRate = 0; m_fSpConsumeChangeHpRate = 0; }

        float m_fHpRate;                                // +0x00
        float m_fSpRate;                                // +0x04
        float m_fSpConsumeChangeHpRate;                 // +0x08
    };

    // <Reflect>, 0x2c bytes.
    struct ReflectProperty
    {
        // @0x1401831b0
        ReflectProperty() { Clear(); }
        bool IsDifferent(const ReflectProperty& o);     // 0x140192480
        void Clear();                                   // 0x1401925b0

        float m_fReflectionRate;                        // +0x00
        int m_nReflectionCount;                         // +0x04
        float m_fReflectionRates[3];                    // +0x08 (physical +0x0c, magical +0x10)
        int m_nReflectionRateLimits[3];                 // +0x14 (physical +0x18, magical +0x1c)
        unsigned m_nReflectionAdditionalEffectId;       // +0x20
        unsigned short m_nReflectionAdditionalEffectLevel;  // +0x24
        float m_fReflectionDamageReduceRate;            // +0x28
    };

    // <Recovery>, 0x30 bytes.
    struct RecoveryProperty
    {
        // @0x140191ff0
        RecoveryProperty() : m_bShowUIText(true), m_bDisableCriticalRecovery(false), m_nHpValue(0), m_nSpValue(0),
            m_nEpValue(0), m_fHpRate(0), m_fSpRate(0), m_fEpRate(0), m_fRecoveryRate(0) {}
        bool IsDifferent(const RecoveryProperty& o);    // 0x140192070

        bool m_bShowUIText;                             // +0x00 (true)
        bool m_bDisableCriticalRecovery;                // +0x01
        __int64 m_nHpValue;                             // +0x08
        __int64 m_nSpValue;                             // +0x10
        __int64 m_nEpValue;                             // +0x18
        float m_fHpRate;                                // +0x20
        float m_fSpRate;                                // +0x24
        float m_fEpRate;                                // +0x28
        float m_fRecoveryRate;                          // +0x2c "RecoveryRate"
    };

    // <Shield>, 0x18 bytes.
    struct ShieldProperty
    {
        // @0x1401831d0
        ShieldProperty() { Clear(); }
        // @0x140192850
        bool IsDifferent(const ShieldProperty& o)
        {
            if (m_nHpValue != o.m_nHpValue) return true;
            if (m_fHpByTargetMaxHP != o.m_fHpByTargetMaxHP) return true;
            if (m_eUIType != o.m_eUIType) return true;
            if (m_nUITypeValue != o.m_nUITypeValue) return true;
            return false;
        }
        bool FUN_140192900();                           // 0x140192900: has an hp value
        // @0x1401928c0
        void Clear() { m_nHpValue = 0; m_fHpByTargetMaxHP = 0; m_eUIType = UIShieldType_None; m_nUITypeValue = 0; }

        __int64 m_nHpValue;                             // +0x00
        float m_fHpByTargetMaxHP;                       // +0x08
        UIShieldType m_eUIType;                         // +0x0c
        unsigned m_nUITypeValue;                        // +0x10
    };

    // <InvokeEffect>, 0x58 bytes.
    struct InvokeEffectProperty
    {
        // @0x140183030
        InvokeEffectProperty() { Clear(); }
        bool IsDifferent(const InvokeEffectProperty& o);    // 0x140192950
        bool FUN_140192ac0();                               // 0x140192ac0: an id is set and every list is empty
        // @0x140192a40
        void Clear()
        {
            m_nSkillID = 0;
            m_nSkillGroupID = 0;
            m_nEffectID = 0;
            m_nEffectGroupID = 0;
            m_vTypes.clear();
            m_vValues.clear();
            m_vRates.clear();
        }

        unsigned m_nSkillID;                            // +0x00
        unsigned m_nSkillGroupID;                       // +0x04
        unsigned m_nEffectID;                           // +0x08
        unsigned m_nEffectGroupID;                      // +0x0c
        std::vector<unsigned> m_vTypes;                 // +0x10
        std::vector<int> m_vValues;                     // +0x28
        std::vector<float> m_vRates;                    // +0x40
    };

    // <SpecialEffect>, 0x28 bytes.
    struct SpecialEffectProperty
    {
        // @0x1401831f0
        SpecialEffectProperty() { Clear(); }
        bool IsDifferent(const SpecialEffectProperty& o);   // 0x140192b60
        void Clear();                                   // 0x140192c40
        void Parse();                                   // 0x140192ce0: values -> m_xml
        bool FUN_140192d70();                           // 0x140192d70: has a type

        AdditionalSpecialEffectType m_eType;            // +0x00 "type"
        float m_fProbability;                           // +0x04 (1.0)
        MS2Ptr<CXmlData> m_xml;                         // +0x08
        CStringW m_strValues;                           // +0x18
        CStringW m_strActivateMsg;                      // +0x20
    };

    // <Spread>, 0x80 bytes.
    struct SpreadProperty
    {
        // @0x140183250
        SpreadProperty() { Clear(); }
        bool IsDifferent(const SpreadProperty& o);      // 0x140192db0
        void Clear();                                   // 0x140192e20
        // @0x140192ea0
        bool IsValid() { return m_eType != AdditionalSpreadType_None && m_nCount != 0; }

        AdditionalSpreadType m_eType;                   // +0x00 "type"
        unsigned m_nCount;                              // +0x04
        Unk_RangeProperty m_rangeProperty;              // +0x08
    };

    AdditionalLevelData(AdditionalData* pParent);       // 0x140171110
    virtual ~AdditionalLevelData() = default;                 // ??_G 0x140185400, dtor 0x140183f60
    virtual bool Load(Unk_140165cf0* pElem);            // slot 1, 0x140172a30

    AdditionalData* GetParent();                        // 0x140171800
    unsigned GetID();                                   // 0x140171820
    unsigned short GetLevel();                          // 0x140171850
    int GetGroup();                                     // 0x140171870
    bool IsBuff();                                      // 0x140171890
    BuffMainType GetMainType();                         // 0x1401718d0
    bool IsDifferent(const AdditionalLevelData& o);     // 0x140171900
    bool HasRevival();                                  // 0x140174ee0
    bool IsRecovery();                                  // 0x140174f20
    bool IsDotDamage();                                 // 0x140174fe0
    bool HasDuration();                                 // 0x140175070
    bool IsExp();                                       // 0x1401750c0
    bool IsDotBuff();                                   // 0x140175110
    bool HasChainSkill();                               // 0x140175170
    bool IsSpread();                                    // 0x1401751f0
    bool HasOverlapKeepEffect();                        // 0x140175220
    bool IsKeepCondition99();                           // 0x140175250
    bool IsHideBuffIcon();                              // 0x140175290
    bool IsInfinitySP();                                // 0x1401752e0
    bool IsVisibleItemOption();                         // 0x140175300
    void LoadOverlapKeepEffect(Unk_140165cf0* pElem);   // 0x140175320
    CString GetIcon();                                  // 0x1401756c0
    static unsigned __int64 MakeKey(unsigned nID, unsigned short nLevel);   // 0x140175710
    static unsigned __int64 GetKeyID(unsigned __int64 nKey);                // 0x140175750
    static unsigned __int64 GetKeyLevel(unsigned __int64 nKey);             // 0x140175770
    bool HasSA(SAType eType) const;                     // 0x140175790 (calls the const find 0x1401900a0)
    void LoadCondition(Unk_140165cf0* pElem);           // 0x1401757f0

    AdditionalData* m_pParent;                          // +0x18
    unsigned short m_nLevel;                            // +0x20
    int m_nGroup;                                       // +0x24
    CStringW m_strStringParam;                          // +0x28
    // <Basic>
    unsigned m_nEventBuffType;                          // +0x30
    unsigned m_nDurationTick;                                // +0x34
    unsigned m_nIntervalTick;                                // +0x38
    unsigned m_nDelayTick;                                   // +0x3c
    int m_nKeepCondition;                               // +0x40
    int m_nResetCondition;                              // +0x44
    unsigned m_nMaxBuffCount;                           // +0x48 (1)
    int m_nDotCondition;                                // +0x4c
    int m_nInvokeEvent;                                 // +0x50
    float m_f54;                                        // +0x54 (100.0, compared, not read)
    float m_fCoolDownTime;                              // +0x58
    float m_fClearDistanceFromCaster;                   // +0x5c
    bool m_bUseInGameTime;                              // +0x60
    bool m_bDeadKeepEffect;                             // +0x61
    bool m_bLogoutClearEffect;                          // +0x62
    bool m_bLeaveFieldClearEffect;                      // +0x63
    bool m_bPvpOnOff;                                   // +0x64
    bool m_bCasterKeepEffect;                           // +0x65
    bool m_bCasterIndividualEffect;                     // +0x66
    bool m_bClearEffectFromPVPZone;                     // +0x67
    bool m_bDoNotClearEffectFromEnterPVPZone;           // +0x68
    bool m_bClearCooldownFromPVPZone;                   // +0x69
    bool m_bIgnoreReduceTimeCondition;                  // +0x6a
    bool m_bDisableRevivalHere;                         // +0x6b
    bool m_bImmediateActiveRequireSkill;                // +0x6c
    int m_nForceApplyTarget;                            // +0x70
    unsigned m_nSkillSetID;                             // +0x74
    unsigned m_nCostumeSetID;                           // +0x78
    unsigned m_nStatSetID;                              // +0x7c
    unsigned m_nAttackPossibleEffectID;                 // +0x80
    unsigned m_nAttackPossibleIndividualEffectID;       // +0x84
    std::set<unsigned> m_setAttackPossibleSkillIDs;     // +0x88
    std::set<unsigned> m_setAttackPossibleDotEffectIDs; // +0x98
    unsigned m_nGroupIDs;                               // +0xa8
    unsigned m_nItemSlotDisable;                        // +0xac
    int m_nTailEffect;                                  // +0xb0
    UIProperty m_ui;                                    // +0xb8
    StatusProperty m_status;                            // +0xd0
    MotionProperty m_motion;                            // +0x130
    DotDamageProperty m_dotDamage;                      // +0x1f8
    DotBuffProperty m_dotBuff;                          // +0x220
    ConsumeProperty m_consume;                          // +0x22c
    ReflectProperty m_reflect;                          // +0x238
    RecoveryProperty m_recovery;                        // +0x268
    int m_nHitImmuneBreak;                              // +0x298 <Offensive>
    int m_nInvincible;                                  // +0x29c <Defensive>
    ShieldProperty m_shield;                            // +0x2a0
    InvokeEffectProperty m_invokeEffect;                // +0x2b8
    SpecialEffectProperty m_specialEffect;              // +0x310
    SpreadProperty m_spread;                            // +0x338
    std::vector<MS2Ptr<AdditionalActionAdditional> > m_vAdditional;    // +0x3b8 <Additional>
    std::vector<MS2Ptr<AdditionalActionSkill> > m_vSkill;              // +0x3d0 <Skill>
    int m_nExpValue;                                    // +0x3e8 <Exp value>
    unsigned m_nRideeID;                                // +0x3ec <Ridee>
    unsigned m_nRemoveRechargingSkillID;                // +0x3f0 <RemoveRechargingCount>
    unsigned m_nRemoveRechargingCount;                  // +0x3f4
    bool m_bCancelCheckSameCaster;                      // +0x3f8 <CancelEffect>
    bool m_bCancelPassiveEffect;                        // +0x3f9
    ATL::CAtlArray<unsigned> m_arrCancelEffectCodes;    // +0x400
    ATL::CAtlArray<unsigned> m_arrCancelBuffCategories; // +0x420
    ATL::CAtlMap<unsigned, int> m_mapModifyOverlapCount;    // +0x440 <ModifyOverlapCount> effect -> offset
    ATL::CAtlArray<unsigned> m_arrImmuneEffectCodes;    // +0x488 <ImmuneEffect>
    ATL::CAtlArray<unsigned> m_arrImmuneBuffCategories; // +0x4a8
    ATL::CAtlArray<unsigned> m_arrResetSkillCodes;      // +0x4c8 <ResetSkillCoolDownTime>
    ATL::CAtlMap<unsigned, std::pair<float, float> > m_mapModifyEffectDuration;    // +0x4e8 effect -> (factor, value)
    ATL::CAtlMap<unsigned, float> m_mapModifySkillCooldown; // +0x530 skill -> value
    // <Condition>
    bool m_bAllowDeadState;                             // +0x578
    bool m_bOnlyShadowWorld;                            // +0x579
    bool m_bAllowBattleRidingState;                     // +0x57a
    bool m_bOnlyBattleRidingState;                      // +0x57b
    float m_fRequireDurationWithoutMove;                // +0x57c
    int m_nApplyPvPZoneType;                            // +0x580
    unsigned m_nJobCode;                                // +0x584
    std::set<unsigned> m_setFieldIDs;                   // +0x588
    unsigned m_nMapCategory;                            // +0x598
    int m_nMapContinent;                                // +0x59c
    Unk_DungeonGroupType m_eDungeonGroupType;           // +0x5a0
    std::set<unsigned> m_setUsedSkillIDs;               // +0x5a8
    int m_nEquipHandL;                                  // +0x5b8
    int m_nEquipHandR;                                  // +0x5bc
    unsigned m_nHasBuffID;                              // +0x5c0
    unsigned short m_nHasBuffLevel;                     // +0x5c4
    unsigned m_nHasBuffCount;                           // +0x5c8
    unsigned m_nHasNotBuffID;                           // +0x5cc
    bool m_bCheckActivateBuff;                          // +0x5d0
    EventConditionType m_eEventCondition;               // +0x5d4
    int m_nIgnoreOwnerEvent;                            // +0x5d8
    ATL::CAtlArray<Unk_CompareStat> m_arrCompareStat;   // +0x5e0 <owner><compareStat>
    Unk_SkillOverlapCondition m_overlapCondition;       // +0x600
    ATL::CAtlArray<Unk_RequireState> m_arrRequireStates;        // +0x618
    ATL::CAtlArray<Unk_RequireSubState> m_arrRequireSubStates;  // +0x638
    ATL::CAtlArray<Unk_SkillMasteryType> m_arrRequireMasteryTypes;   // +0x658
    ATL::CAtlArray<unsigned> m_arrRequireMasteryValues; // +0x678
    unsigned m_nCasterAdditionalID;                     // +0x698
    unsigned m_nCasterAdditionalCount;                  // +0x69c
    float m_fCasterHpRate;                              // +0x6a0
    Unk_CompareOp m_eCasterHpOp;                        // +0x6a4
    unsigned m_nTargetAdditionalID;                     // +0x6a8
};
MS2_CHECK_SIZE(AdditionalLevelData, 0x6b0);
MS2_CHECK_OFFSET(AdditionalLevelData, m_ui, 0xb8);
MS2_CHECK_OFFSET(AdditionalLevelData, m_status, 0xd0);
MS2_CHECK_OFFSET(AdditionalLevelData, m_motion, 0x130);
MS2_CHECK_OFFSET(AdditionalLevelData, m_dotDamage, 0x1f8);
MS2_CHECK_OFFSET(AdditionalLevelData, m_reflect, 0x238);
MS2_CHECK_OFFSET(AdditionalLevelData, m_recovery, 0x268);
MS2_CHECK_OFFSET(AdditionalLevelData, m_shield, 0x2a0);
MS2_CHECK_OFFSET(AdditionalLevelData, m_invokeEffect, 0x2b8);
MS2_CHECK_OFFSET(AdditionalLevelData, m_specialEffect, 0x310);
MS2_CHECK_OFFSET(AdditionalLevelData, m_spread, 0x338);
MS2_CHECK_OFFSET(AdditionalLevelData, m_vAdditional, 0x3b8);
MS2_CHECK_OFFSET(AdditionalLevelData, m_mapModifyOverlapCount, 0x440);
MS2_CHECK_OFFSET(AdditionalLevelData, m_mapModifyEffectDuration, 0x4e8);
MS2_CHECK_OFFSET(AdditionalLevelData, m_mapModifySkillCooldown, 0x530);
MS2_CHECK_OFFSET(AdditionalLevelData, m_setFieldIDs, 0x588);
MS2_CHECK_OFFSET(AdditionalLevelData, m_arrCompareStat, 0x5e0);
MS2_CHECK_OFFSET(AdditionalLevelData, m_overlapCondition, 0x600);
MS2_CHECK_OFFSET(AdditionalLevelData, m_arrRequireMasteryValues, 0x678);

// Encoded/decoded effect state records (ctors are in ?\additionalcli.cpp).
struct Unk_AdditionalOwner              // 0xc bytes (ctor 0x1409755b0)
{
    Unk_AdditionalOwner() : m_n0(0), m_n4(0), m_n8(0) {}               // 0x1409755b0 (?\additionalcli.cpp)
    void Encode(COutputStream* pStream);                // 0x140175f80
    void Decode(CInPacket& packet);                     // 0x140175fe0
    int m_n0;
    int m_n4;
    int m_n8;
};
MS2_CHECK_SIZE(Unk_AdditionalOwner, 0xc);
struct Unk_AdditionalState              // 0x18 bytes (ctor 0x14096e4f0)
{
    Unk_AdditionalState() : m_n0(0), m_n4(0), m_n8(0), m_nC(0), m_n10(0), m_n14(0) {}   // 0x14096e4f0 (?\additionalcli.cpp)
    void Encode(COutputStream* pStream);                // 0x140176080
    void Decode(CInPacket& packet);                     // 0x140176130
    int m_n0;
    int m_n4;
    int m_n8;
    short m_nC;
    int m_n10;
    int m_n14;                          // sent as a byte
};
MS2_CHECK_SIZE(Unk_AdditionalState, 0x18);
struct Unk_AdditionalValue              // 8 bytes (ctor 0x14096e580)
{
    Unk_AdditionalValue() : m_n0(0) {}                                 // 0x14096e580 (?\additionalcli.cpp)
    void Encode(COutputStream* pStream);                // 0x140176250
    void Decode(CInPacket& packet);                     // 0x140176290
    __int64 m_n0;
};
MS2_CHECK_SIZE(Unk_AdditionalValue, 8);
