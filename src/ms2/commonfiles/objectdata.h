// objectdata.h - CObjectData: one interactive object row (Data/Xml/Object/%08d.xml, <FunctionCube> and <ConfigurableCube>)
// and the free per-id queries over the cache of loaded rows. Header name assumed. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/ms2svrptr.h"

// RTTI CObjectData, 0x2e0 bytes, CCacheData-derived, vftable 0x142d7ffb0 (the destructor only).
class CObjectData : public CCacheData
{
public:
    // The <nurturing> reward triple (item id, rarity, count). 12 bytes.
    struct RewardItem
    {
        RewardItem();                                       // 0x1407089d0
        int m_nItemId;
        int m_nRarity;
        int m_nCount;
    };

    // <skillobject>. 16 bytes.
    struct SkillObject
    {
        SkillObject();                                      // 0x140708a00
        int m_n00;
        int m_nSkillId;
        short m_nSkillLevel;
        int m_bFriendly;
    };

    // <spawner>. 16 bytes.
    struct Spawner
    {
        Spawner();                                          // 0x140708a40
        float m_fRadius;
        int m_nNpcCount;
        int m_nNpcId;
        float m_fRegenCheckTime;
    };

    // <fusioner>. 12 bytes.
    struct Fusioner
    {
        Fusioner();                                         // 0x1407087a0
        int m_n00;
        int m_nTemperature;
        int m_nSacrifice;
    };

    // <fittingdoll>. 0x48 bytes.
    struct FittingDoll     // the destructor (0x140708bb0) is implicit
    {
        FittingDoll();                                      // 0x1407084a0
        int m_n00;
        int m_nType;
        int m_nGender;
        int m_n0c;
        CString m_strAsset;
        ATL::CAtlArray<unsigned> m_defaultItems;
        int m_nSkinColor0;
        int m_nSkinColor1;
        int m_nSkinColor2;
        int m_n44;
    };

    // The automatic state change pair and its time. 12 bytes.
    struct AutoState
    {
        AutoState();                                        // 0x1407082e0
        int m_nStateA;
        int m_nStateB;
        int m_nTime;
    };

    // <firstPCAnimation>. 0x48 bytes.
    struct FirstPcAnimation
    {
        FirstPcAnimation();                                 // 0x1407086e0
        CString m_strAnimation;
        int m_nUsePcMove;
        CString m_strBone;
        efd::Point3 m_vTranslation;
        efd::Point3 m_vRotation;
        CString m_strEmotionId;
        CString m_strEffectStart;
        CString m_strEffectEnd;
    };

    // <firstAdditionalEffect>. 0x18 bytes.
    struct AdditionalEffect
    {
        AdditionalEffect();                                 // 0x140708280
        int m_nEffectId;
        short m_nLevel;
        int m_nTarget;
        float m_fRange;
        int m_bEnabled;
        int m_bPopup;
    };

    // The recipe / reactable effect. 0x10 bytes.
    struct Reactable
    {
        Reactable();                                        // 0x1407087d0
        int m_nRecipeId;
        CString m_strEffect;
    };

    // <nurturing>. 0xf8 bytes.
    struct Nurturing
    {
        Nurturing();                                        // 0x140708840
        void operator=(const Nurturing& o);                 // 0x140704bd0
        CStringW m_strQuestTag;
        RewardItem m_rewardByFeeding;
        RewardItem m_reward;
        ATL::CAtlMap<short, unsigned __int64> m_requiredGrowth;
        ATL::CAtlMap<short, int> m_pluralNpcIds;
        ATL::CAtlMap<short, RewardItem> m_rewardByGrowth;
    };

    // The <pvp> element. 8 bytes.
    struct Pvp
    {
        Pvp();                                              // 0x1407089b0
        char m_bEnabled;
        int m_nTeam;
    };

    // <openWeb>. 0x18 bytes.
    struct OpenWeb
    {
        OpenWeb();                                          // 0x140708950
        CString m_strUrl;
        CString m_strTarget;
        int m_nOpenType;
    };

    // <noticePopup>. 8 bytes.
    struct NoticePopup
    {
        NoticePopup();                                      // 0x140708810
        CStringW m_strType;
    };

    // <FunctionCube>. 0x2a0 bytes.
    struct FunctionCube
    {
        FunctionCube();                                     // 0x140708500
        int m_bEnabled;                                     // +0x00 the object has a function cube
        int m_bUseKfm;
        int m_nStateChangeAction;                           // 1 ActionKey, 2 Attack
        int m_nDefaultState;
        int m_nControlType;                                 // 1 default, 2 Sensor, 3 Switch ... 0xd Nurturing
        int m_nUiFunction;                                  // 1 TriggerTool ... 7 Summon (FunctionUI only)
        int m_nCamera;                                      // 1 TPS ... 6 Console
        int m_bForbidJump;
        int m_bForbidClimb;
        int m_bForbidSkill;
        int m_bForbidPlayInstrument;
        int m_bForbidExceptOwner;
        int m_bEnableTriggerControl;
        int m_nStateChangePermission;
        CString m_strControlType;
        ATL::CAtlArray<CString> m_sequences;                // Zero/First/Second (Ing) Seq
        ATL::CAtlArray<CString> m_effects;                  // Zero/First/Second (Ing) Effect
        int m_anPhysics[3];                                 // Zero / First / Second
        SkillObject m_skill;
        Spawner m_spawner;
        Fusioner m_fusioner;
        FittingDoll m_fittingDoll;
        AutoState m_autoState;
        FirstPcAnimation m_firstAnimation;
        AdditionalEffect m_firstEffect;
        Reactable m_reactable;
        Nurturing m_nurturing;
        Pvp m_pvp;
        OpenWeb m_openWeb;
        NoticePopup m_notice;
    };

    // <ConfigurableCube>. 0x10 bytes.
    struct ConfigurableCube
    {
        ConfigurableCube() throw();                         // 0x140708470
        int m_bEnabled;
        CString m_strId;
    };

    CObjectData();                                          // 0x140704df0
    virtual ~CObjectData();                                 // 0x140704e60

    unsigned m_nId;                                         // +0x28
    FunctionCube m_cube;                                    // +0x30
    ConfigurableCube m_config;                              // +0x2d0
};
MS2_CHECK_SIZE(CObjectData::RewardItem, 0xc);
MS2_CHECK_SIZE(CObjectData::SkillObject, 0x10);
MS2_CHECK_SIZE(CObjectData::Spawner, 0x10);
MS2_CHECK_SIZE(CObjectData::Fusioner, 0xc);
MS2_CHECK_SIZE(CObjectData::FittingDoll, 0x48);
MS2_CHECK_SIZE(CObjectData::AutoState, 0xc);
MS2_CHECK_SIZE(CObjectData::FirstPcAnimation, 0x48);
MS2_CHECK_SIZE(CObjectData::AdditionalEffect, 0x18);
MS2_CHECK_SIZE(CObjectData::Reactable, 0x10);
MS2_CHECK_SIZE(CObjectData::Nurturing, 0xf8);
MS2_CHECK_SIZE(CObjectData::Pvp, 8);
MS2_CHECK_SIZE(CObjectData::OpenWeb, 0x18);
MS2_CHECK_SIZE(CObjectData::NoticePopup, 8);
MS2_CHECK_SIZE(CObjectData::FunctionCube, 0x2a0);
MS2_CHECK_SIZE(CObjectData::ConfigurableCube, 0x10);
MS2_CHECK_SIZE(CObjectData, 0x2e0);
MS2_CHECK_OFFSET(CObjectData, m_cube, 0x30);
MS2_CHECK_OFFSET(CObjectData, m_config, 0x2d0);

typedef MS2SvrPtr<CObjectData> CObjectDataPtr;

// Per-id queries over the row cache (names invented from the compared fields).
CObjectDataPtr FUN_140704ec0(unsigned nId);     // the row of an id; loads Data/Xml/Object/<id>.xml when it is not cached
int FUN_1407071e0(int nId);                     // has a function cube
int FUN_140707260(int nId);                     // function cube uses a kfm
int FUN_1407072e0(int nId);                     // switch with the fitting doll ui
int FUN_1407073a0(int nId);                     // switch with the item fusion ui
int FUN_140707460(int nId);                     // skill control type
int FUN_1407074f0(int nId);                     // bank ui
int FUN_1407075a0(int nId);                     // spawn npc or install npc
int FUN_140707660(int nId);                     // trigger tool ui
int FUN_140707710(int nId);                     // trigger control enabled
int FUN_1407077c0(int nId);                     // state change permission 1
int FUN_140707870(int nId);                     // password ui
int FUN_140707920(int nId);                     // forbids jump, climb, skill or instrument
int FUN_140707a00(int nId);                     // forbidden for non owners
int FUN_140707ac0(int nId);                     // portal control type
int FUN_140707b40(int nId);                     // notice control type
int FUN_140707bc0(int nId);                     // has a configurable cube
int FUN_140707c60(int nId);                     // breeding control type
int FUN_140707d10(int nId);                     // farming control type
int FUN_140707dc0(int nId);                     // nurturing control type
int FUN_140707e70(int nId);                     // install npc control type
