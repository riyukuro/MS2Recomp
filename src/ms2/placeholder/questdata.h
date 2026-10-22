// CQuestData: heap-only quest table row. Names inferred from client quest use.
// Layout proved by ctor 0x140748cf0 and the 0x3f0 allocation in questdata.cpp.
#pragma once
#include <vector>
#include <bitset>
#include "ms2/placeholder/famealliance.h"
#include <atlcoll.h>
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/dclevelrange.h"
#include "ms2/placeholder/socketptr.h"

class Unk_140165cf0;

class CQuestData : public CPtred
{
public:
    class QuestRewardItem : public CPtred
    {
    public:
        QuestRewardItem();
        QuestRewardItem(const QuestRewardItem& o) : CPtred(o), m_itemId(o.m_itemId), m_count(o.m_count), m_job(o.m_job) {}   // 0x1407585c0
        QuestRewardItem(QuestRewardItem&& o) : CPtred(o), m_itemId(o.m_itemId), m_count(o.m_count), m_job(o.m_job) {}        // 0x140758550
        virtual ~QuestRewardItem();
        int m_itemId, m_count, m_job;
        bool operator!=(const QuestRewardItem& o) const;   // 0x140747f60
        bool LoadXml(Unk_140165cf0* pElem);                // 0x140747fc0
    };
    // <navigation> targets: ctor 0x140748aa0, compare 0x140748b00.
    class NavigationTarget : public CPtred
    {
    public:
        NavigationTarget();
        bool operator!=(const NavigationTarget& o) const;
        int m_kind;                                 // +0x18 ctor 3
        ATL::CAtlArray<unsigned> m_ids;             // +0x20
        ATL::CAtlArray<unsigned> m_maps;            // +0x40
    };
    // One navigation entry: ctor 0x140748b80, compare 0x140748bd0.
    class NavigationData : public CPtred
    {
    public:
        NavigationData();
        bool operator!=(const NavigationData& o) const;
        int m_kind;                                 // +0x18
        ATL::CAtlArray<Unk_SocketPtr<NavigationTarget> > m_targets;   // +0x20
    };
    // Random pick of a quest group: ctor 0x140748c30, compare 0x140748c90.
    class GroupPickData : public CPtred
    {
    public:
        GroupPickData();
        virtual ~GroupPickData();
        bool operator!=(const GroupPickData& o) const;
        int m_18;                                   // ctor 0
        int m_count;                                // +0x1c ctor 1
        int m_kind;                                 // +0x20 ctor 0
    };
    CQuestData();
    virtual ~CQuestData();
    bool operator!=(const CQuestData& o) const;   // 0x140749090
    Unk_SocketPtr<NavigationData> FUN_14074b380(int nKey);   // the <navi> entry of a state (null when missing)
    int Load(Unk_140165cf0* pElem);       // XML loader (<quest> element)
    int m_id, m_type, m_20, m_level, m_28;
    unsigned char m_2c, m_2d, m_2e, m_2f, m_30, m_31, m_flag, m_33, m_34;
    unsigned char GetKind() const { return m_2c; }   // 0x14064dbd0 (COMDAT first emitted by learningquesttable.cpp)
    int m_durationMinutes, m_resetType;
    CStringW m_schedule;
    // <require> block, CQuestData+0x58 (0x1f0). ctor 0x140747910, dtor 0x140758c80,
    // operator== 0x140747b10; XML loader in questdata.cpp. A = CAtlArray<unsigned>
    // (ctor 0x140181d30/dtor 0x140183460), B = CAtlArray<int> (0x140181cf0/0x140183420).
    struct Require
    {
        Require();
        ~Require();
        bool operator!=(const Require& o) const;   // 0x140747b10
        short m_level;                      // +0x00 (+0x58)
        short m_maxLevel;                   // +0x02
        unsigned m_achievement;             // +0x04
        int m_achievementGrade;             // +0x08
        int m_unreqAchievement;             // +0x0c "unreqAchievement" id,grade pair
        int m_unreqAchievementGrade;        // +0x10
        int m_groupId;                      // +0x14
        unsigned m_gearScore;               // +0x18
        int m_guildLevel;                   // +0x1c ctor -1
        short m_guildNpcLevel;              // +0x20
        unsigned m_dungeon;                 // +0x24
        unsigned m_unrequireDungeon;        // +0x28
        unsigned m_enterDungeon;            // +0x2c
        ATL::CAtlArray<unsigned> m_dungeonBeginner;   // +0x30 (+0x88)
        int m_mentor;                       // +0x50 (+0xa8)
        int m_mentee;                       // +0x54
        int m_vip;                          // +0x58
        Unk_FameAlliance m_alliance;        // +0x5c reader 0x14035bc20
        int m_fameGrade;                    // +0x60
        int m_masteryType;                  // +0x64 enum, reader 0x14051fd20
        int m_masteryGrade;                 // +0x68
        ATL::CAtlArray<int> m_job;          // +0x70 (+0xc8)
        ATL::CAtlArray<int> m_subJob;       // +0x90
        ATL::CAtlArray<unsigned> m_quest;   // +0xb0 (+0x108)
        ATL::CAtlArray<unsigned> m_selectableQuest;   // +0xd0
        ATL::CAtlArray<unsigned> m_unrequire;         // +0xf0
        ATL::CAtlArray<unsigned> m_progressQuest;     // +0x110
        ATL::CAtlArray<int> m_unrequireGroup;         // +0x130
        ATL::CAtlArray<unsigned> m_equipment;         // +0x150 (+0x1a8)
        ATL::CAtlArray<int> m_dayOfWeek;              // +0x170
        ATL::CAtlArray<unsigned> m_followingQuests;   // +0x190 reverse links, filled after load
        ATL::CAtlArray<unsigned> m_requiredBy;        // +0x1b0 quests listing this in "quest"
        ATL::CAtlArray<unsigned> m_selectableBy;      // +0x1d0 quests listing this in "selectableQuest"
    };
    // <completeReward> block, CQuestData+0x248 (0x70). ctor 0x140748100, dtor 0x140758d90,
    // compare 0x140748210. Reward item array ctor 0x140757730, dtor 0x140758680.
    struct CompleteReward
    {
        CompleteReward();
        ~CompleteReward();
        bool operator!=(const CompleteReward& o) const;   // 0x140748210
        int m_money;                        // +0x00 (+0x248)
        int m_karma;                        // +0x04
        int m_lu;                           // +0x08
        int m_exp;                          // +0x0c
        int m_guildFund;                    // +0x10
        int m_guildExp;                     // +0x14
        int m_guildCoin;                    // +0x18
        int m_menteeCoin;                   // +0x1c
        int m_missionPoint;                 // +0x20
        int m_useMainFamePoint;             // +0x24
        unsigned m_fameLog;                 // +0x28
        __int64 m_weddingExp;               // +0x30 (+0x278) reader 0x1408732e0
        float m_38;                         // +0x38 ctor 1.0f
        int m_relativeExp;                  // +0x3c ctor -1, reader 0x140354050
        float m_40;                         // +0x40 ctor 1.0f
        int m_relativeMeso;                 // +0x44 reader 0x140752270
        int m_rewardExpExtra;               // +0x48
        ATL::CAtlArray<QuestRewardItem> m_choiceRewards;   // +0x50 (+0x298)
    };
    int m_48;
    Unk_FameAlliance m_4c;
    int m_50;
    std::bitset<4> m_54;                // ctor 0x1402a5610
    Require m_require;
    CompleteReward m_complete;
    std::vector<QuestRewardItem> m_rewards;
    struct Sound                        // ctor 0x1407489d0, compare 0x140748a20
    {
        Sound();
        bool operator!=(const Sound& o) const;
        int m_id;                       // -1
        CString m_accept, m_reward;
    };
    Sound m_2d0;
    int m_2e8, m_2ec;
    struct Quad                         // ctor 0x1407486d0, compare 0x140748710
    {
        Quad();
        bool operator!=(const Quad& o) const;
        int m_0, m_4, m_8, m_c;
    };
    Quad m_2f0;
    struct Tri300                       // ctor 0x140748780, compare 0x1407487c0
    {
        Tri300();
        bool operator!=(const Tri300& o) const;
        int m_0, m_4, m_8;
    };
    Tri300 m_300;
    struct Room                         // ctor 0x140748820, compare 0x140748860
    {
        Room();
        bool operator!=(const Room& o) const;
        int m_0, m_roomId, m_fieldId;
    };
    Room m_30c;
    // +0x318..+0x368, typed from the member ctors called by CQuestData::CQuestData 0x140748cf0.
    struct Pair                         // ctor 0x1407488c0, compare 0x1407488f0
    {
        Pair();
        bool operator!=(const Pair& o) const;
        int m_0, m_4;
    };
    Pair m_318;
    struct Triple                       // ctor 0x140748930, compare 0x140748970
    {
        Triple();
        bool operator!=(const Triple& o) const;
        int m_0, m_4, m_8;
    };
    Triple m_320, m_32c;
    struct Grade                        // ctor 0x1407484d0, compare 0x140748530
    {
        Grade();
        bool operator!=(const Grade& o) const;
        int m_value;                    // +0x338 0; CQuestManager counts quests by ranges 1..2 / 3..5
        int m_4;                        // ctor 6
        CString m_8;
        Unk_DcLevelRange m_levelRange;  // +0x10 ctor 0x140757bd0 zeroes both
    };
    Grade m_338;
    struct Flag                         // ctor 0x1407485c0, compare 0x1407485e0
    {
        Flag();
        bool operator!=(const Flag& o) const;
        int m_value;                    // CQuestManager::vfunc_1 tests == 2
    };
    Flag m_350;
    struct Named                        // ctor 0x140748610, compare 0x140748660
    {
        Named();
        bool operator!=(const Named& o) const;
        int m_0, m_4; CString m_8;
    };
    Named m_358;
    ATL::CAtlArray<unsigned> m_fields;
    ATL::CAtlArray<MS2Ptr<CConditionCommonData>> m_conditions;
    ATL::CAtlMap<int, Unk_SocketPtr<NavigationData> > m_navigation;   // +0x3a8 (17 bins, 0.75, 0.25, 2.25, block 10)
};
MS2_CHECK_SIZE(CQuestData::QuestRewardItem, 0x28);
MS2_CHECK_SIZE(CQuestData, 0x3f0);
MS2_CHECK_OFFSET(CQuestData, m_flag, 0x32);
MS2_CHECK_SIZE(CQuestData::Require, 0x1f0);
MS2_CHECK_OFFSET(CQuestData::Require, m_guildNpcLevel, 0x20);
MS2_CHECK_OFFSET(CQuestData::Require, m_dungeonBeginner, 0x30);
MS2_CHECK_OFFSET(CQuestData::Require, m_mentor, 0x50);
MS2_CHECK_OFFSET(CQuestData::Require, m_job, 0x70);
MS2_CHECK_OFFSET(CQuestData::Require, m_equipment, 0x150);
MS2_CHECK_OFFSET(CQuestData::Require, m_selectableBy, 0x1d0);
MS2_CHECK_SIZE(CQuestData::CompleteReward, 0x70);
MS2_CHECK_OFFSET(CQuestData::CompleteReward, m_fameLog, 0x28);
MS2_CHECK_OFFSET(CQuestData::CompleteReward, m_weddingExp, 0x30);
MS2_CHECK_OFFSET(CQuestData::CompleteReward, m_rewardExpExtra, 0x48);
MS2_CHECK_OFFSET(CQuestData::CompleteReward, m_choiceRewards, 0x50);
MS2_CHECK_OFFSET(CQuestData, m_require, 0x58);
MS2_CHECK_OFFSET(CQuestData, m_complete, 0x248);
MS2_CHECK_OFFSET(CQuestData, m_rewards, 0x2b8);
MS2_CHECK_OFFSET(CQuestData, m_2d0, 0x2d0);
MS2_CHECK_OFFSET(CQuestData, m_2f0, 0x2f0);
MS2_CHECK_OFFSET(CQuestData, m_navigation, 0x3a8);
MS2_CHECK_OFFSET(CQuestData::Room, m_roomId, 4);
MS2_CHECK_OFFSET(CQuestData, m_conditions, 0x388);
MS2_CHECK_OFFSET(CQuestData, m_320, 0x320);
MS2_CHECK_OFFSET(CQuestData, m_338, 0x338);
MS2_CHECK_OFFSET(CQuestData, m_350, 0x350);
MS2_CHECK_OFFSET(CQuestData, m_30c, 0x30c);
MS2_CHECK_OFFSET(CQuestData, m_358, 0x358);
MS2_CHECK_OFFSET(CQuestData, m_fields, 0x368);
