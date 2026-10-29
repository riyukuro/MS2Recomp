// dungeonroom.h - the dungeon room table (DungeonRoom.xml and its companions). Owning unit: commonfiles\dungeonroom.cpp
// (0x14031c970-0x140343e50). Class names from RTTI; field names from the xml attribute names the loaders read; method
// names invented unless noted.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include <vector>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/partybits.h"

class Unk_140165cf0;     // game TinyXML element
class DungeonRewardCoupon;


// Room ids are dungeonId * 1000 + index.
int MakeDungeonRoomId(int nDungeonId, int nIndex);             // 0x14031c970
unsigned GetDungeonIdOfRoom(unsigned nRoomId);                 // 0x14031c990
unsigned GetIndexOfRoom(unsigned nRoomId);                     // 0x14031c9b0
CString GetRankName(int nRank);                                // 0x14031c9d0 "rank{0}" / "rank_unknown"

// RTTI DungeonLobbyCtx, 0x38 bytes.
class DungeonLobbyCtx : public CPtred
{
public:
    DungeonLobbyCtx();                  // 0x14031ca50

    int m_18;                           // +0x18
    int m_1c;                           // +0x1c
    __int64 m_20;                       // +0x20
    std::set<__int64> m_28;             // +0x28
};
MS2_CHECK_SIZE(DungeonLobbyCtx, 0x38);

struct DungeonRankRewardItem
{
    // The exe's vector<DungeonRankRewardItem> moves element-wise (_Uninitialized_move_al_unchecked loop, _Ptr_move_cat ->
    // _General_ptr_iterator_tag 0x14032daa0) while copy-constructing inline: a user default ctor and a user-provided
    // copy assignment (never instantiated in this unit, body assumed memberwise).
    DungeonRankRewardItem() : itemID(0), systemMailID(0) {}   // 0x140323380 (vector::resize value-constructs through it)
    DungeonRankRewardItem& operator=(const DungeonRankRewardItem& o) { itemID = o.itemID; systemMailID = o.systemMailID; return *this; }
    unsigned itemID;                    // +0
    int systemMailID;                   // +4
};

// RTTI DungeonRankRewardBase, 0x40 bytes (DungeonRankReward.xml).
class DungeonRankRewardBase : public CPtred
{
public:
    DungeonRankRewardBase();                    // 0x14031cad0
    bool Load(Unk_140165cf0* pElem);            // 0x14031cb30
    unsigned GetId();                           // 0x14031ccf0
    unsigned GetItemId(int nRank);              // 0x14031cd10
    int GetSystemMailId(int nRank);             // 0x14031cd70
    int GetMaxRank();                           // 0x14031cdd0

    unsigned m_rewardID;                        // +0x18
    std::vector<DungeonRankRewardItem> m_items; // +0x20 indexed by rank (1..5)
    int m_maxRank;                              // +0x38
};
MS2_CHECK_SIZE(DungeonRankRewardBase, 0x40);

class DungeonRoundGroup;

// The room group type ("groupType", read as a number; 1/2 are the random-match groups, 3 the season rank rooms).
enum DungeonGroupType {};
// "timerType" (string, parsed by 0x14021ab60) and "BossRankingType" (kill/damage/killrumble/multikill/colosseum).
enum DungeonTimerType {};
enum DungeonBossRankingType {};

// RTTI DungeonRoom, 0x208 bytes (one DungeonRoom.xml entry).
class DungeonRoom : public CPtred
{
public:
    DungeonRoom();                                  // 0x14031cdf0
    virtual ~DungeonRoom();                         // 0x14031d220
    void Load(Unk_140165cf0* pElem);                // 0x14031d350
    unsigned GetDungeonRoomID();                    // 0x14031ddd0
    unsigned GetRewardRoomID();                     // 0x14031ddf0
    unsigned GetDungeonID();                        // 0x14031de20
    unsigned GetRoomIndex();                        // 0x14031de50
    bool HasEnterRequirement();                     // 0x14031de80
    unsigned GetLobbyFieldID();                     // 0x14031df00
    unsigned GetFirstFieldID();                     // 0x14031df20
    int GetLimitType();                             // 0x14031df70
    int GetCooldownType();                          // 0x14031dfa0
    int GetCooldownValue();                         // 0x14031dfd0
    __int64 GetCooldownEndTime(__int64 tNow);       // 0x14031dff0
    unsigned GetMaxUserCount(unsigned nUser);       // 0x14031e030
    bool HasExtraRewardTicket();                    // 0x14031e0d0
    unsigned GetCouponBaseItemID();                 // 0x14031e110
    unsigned GetCouponTicketTag();                  // 0x14031e150
    bool CanBuyCouponInMeratMarket();               // 0x14031e190
    bool HasMissions();                             // 0x14031e1d0
    unsigned GetSeasonRankRewardID();               // 0x14031e220
    unsigned GetRandomFieldID();                    // 0x14031e240
    unsigned GetExtraRewardTicketCost(unsigned nCount); // 0x14031e2b0
    int GetCouponMaxExtraCount();                   // 0x14031e340
    void GetRewardDropBoxIds(std::vector<unsigned>& out);   // 0x14031e380
    unsigned GetDefaultRevivalLimitCount();         // 0x14031e3c0
    void GetMissions(std::vector<unsigned>& out);   // 0x14031e3e0
    int GetRank(short nScore);                      // 0x14031e440
    bool IsSeasonRankRoom();                        // 0x14031e480
    bool IsRandomMatchable();                       // 0x14031e4d0
    bool HasRoundGroup() const;                     // 0x14031e530
    bool IsSingleRound();                           // 0x14031e570
    void GetRoundRewardIds(unsigned char nFrom, unsigned char nTo, std::vector<unsigned>& out);   // 0x14031e5b0
    int GetRankTableID();                           // 0x14031e610
    void ApplyConstants();                          // 0x14031e840
    DungeonRewardCoupon* GetCoupon();               // 0x14031e8a0

    unsigned m_dungeonRoomID;                       // +0x18
    DungeonGroupType m_groupType;                   // +0x1c
    CStringW m_20;                                  // +0x20
    unsigned short m_dungeonLevel;                  // +0x28
    bool m_limitEnter;                              // +0x2a
    int m_clearKillNpc;                             // +0x2c
    int m_sortOrder;                                // +0x30
    int m_cooldownValue;                            // +0x34
    unsigned m_rewardCount;                         // +0x38
    unsigned m_subRewardCount;                      // +0x3c
    bool m_isAccountReward;                         // +0x40
    unsigned m_unionRewardID;                       // +0x44
    unsigned m_roundID;                             // +0x48
    __int64 m_rewardExp;                            // +0x50
    float m_rewardExpRate;                          // +0x58
    __int64 m_rewardMeso;                           // +0x60
    std::vector<unsigned> m_rewardLimitedDropBoxIds;    // +0x68
    std::vector<unsigned> m_rewardLimitedDropBoxIds2;   // +0x80
    std::vector<unsigned> m_rewardDropBoxIds;       // +0x98 both lists
    unsigned m_seasonRankRewardID;                  // +0xb0
    int m_scoreBonusId;                             // +0xb4
    unsigned m_extraRewardTicketTableID;            // +0xb8
    unsigned m_extraRewardTicketBaseCount;          // +0xbc
    unsigned m_lobbyFieldID;                        // +0xc0
    ATL::CAtlArray<unsigned> m_fieldIDs;            // +0xc8
    int m_durationSeconds;                          // +0xe8
    bool m_isExpireTimeOut;                         // +0xec
    DungeonTimerType m_timerType;                   // +0xf0
    unsigned m_minUserCount;                        // +0xf4
    unsigned m_maxUserCount;                        // +0xf8
    unsigned m_gearScore;                           // +0xfc
    int m_limitAchieveID;                           // +0x100
    unsigned short m_limitPlayerLevel;              // +0x104
    Unk_PartyBits m_limitDayOfWeeks;                // +0x106
    bool m_limitVIP;                                // +0x107
    bool m_isLimitTime;                             // +0x108
    bool m_limitMesoRevival;                        // +0x109
    bool m_limitMeratRevival;                       // +0x10a
    bool m_limitRecommendWeapon;                    // +0x10b
    std::vector<unsigned> m_limitClearDungeon;      // +0x110
    std::vector<unsigned> m_limitAdditionalEffects; // +0x128
    unsigned m_defaultRevivalLimitCount;            // +0x140
    CString m_dungeonBanner;                        // +0x148
    CString m_bossIcon;                             // +0x150
    int m_isTimeUp;                                 // +0x158
    bool m_isUseBossIcon;                           // +0x15c
    DungeonBossRankingType m_bossRankingType;       // +0x160
    unsigned m_bossRanking;                         // +0x164
    CStringW m_openPeriodTag;                       // +0x168
    CMsTime m_openPeriodDate;                       // +0x170
    bool m_isRandomField;                           // +0x180
    bool m_isPartyOnly;                             // +0x181
    bool m_isChangeMaxUser;                         // +0x182
    unsigned m_playerCountFactorID;                 // +0x184
    int m_customMonsterLevel;                       // +0x188
    bool m_chaosDamageMeter;                        // +0x18c
    bool m_isMoveOutToBackupField;                  // +0x18d
    int m_dungeonHelperRequireClearCount;           // +0x190
    std::vector<unsigned> m_findHelperRewardDropBoxIds; // +0x198
    bool m_isUseRandomMatch;                        // +0x1b0
    bool m_isDisableRandomMatch;                    // +0x1b1
    bool m_isLeaveAfterCloseReward;                 // +0x1b2
    std::vector<unsigned> m_partyMissions;          // +0x1b8
    std::vector<unsigned> m_userMissions;           // +0x1d0
    unsigned m_rankTableID;                         // +0x1e8
    unsigned m_representID;                         // +0x1ec
    unsigned m_dungeonScaleStatID;                  // +0x1f0
    DungeonRoundGroup* m_pRoundGroup;               // +0x1f8 linked by the table
    DungeonRewardCoupon* m_pCoupon;                 // +0x200 linked by the table
};
MS2_CHECK_SIZE(DungeonRoom, 0x208);
MS2_CHECK_OFFSET(DungeonRoom, m_rewardLimitedDropBoxIds, 0x68);
MS2_CHECK_OFFSET(DungeonRoom, m_fieldIDs, 0xc8);
MS2_CHECK_OFFSET(DungeonRoom, m_limitDayOfWeeks, 0x106);
MS2_CHECK_OFFSET(DungeonRoom, m_limitClearDungeon, 0x110);
MS2_CHECK_OFFSET(DungeonRoom, m_dungeonBanner, 0x148);
MS2_CHECK_OFFSET(DungeonRoom, m_openPeriodDate, 0x170);
MS2_CHECK_OFFSET(DungeonRoom, m_findHelperRewardDropBoxIds, 0x198);
MS2_CHECK_OFFSET(DungeonRoom, m_partyMissions, 0x1b8);
MS2_CHECK_OFFSET(DungeonRoom, m_rankTableID, 0x1e8);
MS2_CHECK_OFFSET(DungeonRoom, m_pCoupon, 0x200);

typedef MS2Ptr<DungeonRoom> DungeonRoomPtr;

int Unk_DungeonRoom_14031e6d0(int nType);                                       // 0x14031e6d0 (asserts on other types)
bool IsDungeonLevelInRange(unsigned short nLevel, unsigned short nDungeonLevel); // 0x14031e720
bool Unk_DungeonRoom_14031e780(int nValue);                                     // 0x14031e780
__int64 CalcCooldownEndTime(int nType, int nValue, __int64 tNow);              // 0x14031e7c0

// RTTI DungeonSeasonItemGift, 0x38 bytes: a season reward with the score it needs.
struct DungeonSeasonItemGift : ItemGift {
    DungeonSeasonItemGift();                        // 0x14031e950
    virtual void vfunc_4(Unk_140165cf0* pElem);     // 0x14031e9a0
    unsigned m_requireScore;                        // +0x30
};
MS2_CHECK_SIZE(DungeonSeasonItemGift, 0x38);

// The score thresholds of one rank table (DungeonConfig.xml MissionRank), 0x20 bytes.
struct DungeonRankRequire
{
    DungeonRankRequire();                           // 0x14031e9f0
    void Load(Unk_140165cf0* pElem);                // 0x14031ea30
    short GetMaxScore();                            // 0x14031eb90
    int GetRank(short nScore);                      // 0x14031ebb0
    size_t GetCount();                              // 0x14031ec40
    short GetScore(unsigned __int64 nIndex);        // 0x14031ec70

    short m_maxScore;                               // +0
    std::vector<short> m_scores;                    // +8 ascending
};
MS2_CHECK_SIZE(DungeonRankRequire, 0x20);

// RTTI DungeonSeason, 0x68 bytes (DungeonSeason.xml).
class DungeonSeason : public CPtred
{
public:
    DungeonSeason();                                // 0x14031ecc0
    virtual ~DungeonSeason();                       // 0x14031ed50
    bool Load(Unk_140165cf0* pElem);                // 0x14031ed90
    bool IsInPeriod(const CMsTime& t);              // 0x14031f030
    MS2Ptr<DungeonSeasonItemGift> GetReward(unsigned nScore);   // 0x14031f060

    short m_seasonID;                               // +0x18
    TimeRange m_period;                             // +0x20
    unsigned m_maxSeasonScore;                      // +0x40
    int m_systemMailID;                             // +0x44
    int m_dayOfWeeks;                               // +0x48
    std::vector<MS2Ptr<DungeonSeasonItemGift> > m_rewards;  // +0x50 descending require score
};
MS2_CHECK_SIZE(DungeonSeason, 0x68);

// RTTI DungeonUnitedWeeklyReward, 0x28 bytes (DungeonConfig.xml UnitedWeeklyReward).
class DungeonUnitedWeeklyReward : public CPtred
{
public:
    DungeonUnitedWeeklyReward();                    // 0x14031f140
    virtual ~DungeonUnitedWeeklyReward();           // 0x14031f1a0
    bool Load(Unk_140165cf0* pElem);                // 0x14031f1d0

    unsigned m_rewardCount;                         // +0x18
    unsigned m_rewardID;                            // +0x1c
    int m_uiPosX;                                   // +0x20
    bool m_uiShowBg;                                // +0x24
};
MS2_CHECK_SIZE(DungeonUnitedWeeklyReward, 0x28);

// RTTI DungeonRoundData, 0x20 bytes.
class DungeonRoundData : public CPtred
{
public:
    DungeonRoundData();                             // 0x14031f260
    bool Load(Unk_140165cf0* pElem);                // 0x14031f2b0

    unsigned m_rewardID;                            // +0x18
    unsigned m_gearScore;                           // +0x1c
};
MS2_CHECK_SIZE(DungeonRoundData, 0x20);

// RTTI DungeonRoundGroup, 0x38 bytes (DungeonRoundData.xml).
class DungeonRoundGroup : public CPtred
{
public:
    DungeonRoundGroup();                            // 0x14031f310
    bool Load(Unk_140165cf0* pElem);                // 0x14031f360
    void GetRewardIds(unsigned char nFrom, unsigned char nTo, std::vector<unsigned>& out);  // 0x14031f480
    MS2Ptr<DungeonRoundData> GetRound(unsigned nIndex);     // 0x14031f530

    unsigned m_id;                                  // +0x18
    std::vector<MS2Ptr<DungeonRoundData> > m_rounds;    // +0x20
};
MS2_CHECK_SIZE(DungeonRoundGroup, 0x38);

class DungeonRoomTable;

// Orders the room sets by gear score, level, sort order, then id; also compares a room with a (gear score, level) key.
// Orders by gear score, player level limit, sort order, room id.
struct DungeonRoomLess
{
    // @0x140335d90
    bool operator()(const DungeonRoomPtr& a, const DungeonRoomPtr& b) const
    {
        if (a->m_gearScore != b->m_gearScore)
            return a->m_gearScore < b->m_gearScore;
        if (a->m_limitPlayerLevel != b->m_limitPlayerLevel)
            return a->m_limitPlayerLevel < b->m_limitPlayerLevel;
        if (a->m_sortOrder != b->m_sortOrder)
            return a->m_sortOrder < b->m_sortOrder;
        return a->m_dungeonRoomID < b->m_dungeonRoomID;
    }
    // @0x140335cd0 (room against a (gear score, level) key; note the reversed direction)
    bool operator()(const DungeonRoomPtr& a, const std::pair<unsigned, unsigned short>& key) const
    {
        if (a->m_gearScore != key.first)
            return a->m_gearScore > key.first;
        if (a->m_limitPlayerLevel != key.second)
            return a->m_limitPlayerLevel > key.second;
        return false;
    }
};
typedef std::set<DungeonRoomPtr, DungeonRoomLess> DungeonRoomSet;

CString FUN_14016a5c0(const char* psz, int nCodePage);         // narrows a string (the RTTI name in CheckInit)

// RTTI DungeonRoomTable, 0x108 bytes: TSingleton at +0 (vftable 0x142d28ab0), CValidData at +8 (0x142d28ac0).
class DungeonRoomTable : public TSingleton<DungeonRoomTable>, public CValidData<DungeonRoomTable>
{
public:
    DungeonRoomTable();                     // 0x14031f5d0
    virtual ~DungeonRoomTable();            // 0x14031f770

    void LoadRooms();                       // 0x14031f8a0 DungeonRoom.xml
    void LoadSeasons();                     // 0x14031fbf0 DungeonSeason.xml
    void LoadConfig();                      // 0x14031fe80 DungeonConfig.xml
    void LoadRankRewards();                 // 0x140320050 DungeonRankReward.xml
    void LoadRoundGroups();                 // 0x140320340 DungeonRoundData.xml
    void Clear();                           // 0x140320620
    DungeonRoomPtr GetRoom(int nDungeonId, int nIndex);         // 0x140320650
    DungeonRoomPtr GetRoom(unsigned nRoomId);                   // 0x1403206b0
    DungeonRoomPtr GetRewardRoom(unsigned nRoomId);             // 0x140320770 follows unionRewardID
    DungeonRoomPtr GetFirstRoom(unsigned nDungeonId);           // 0x140320870
    DungeonRoomPtr GetLastRoom(unsigned nDungeonId);            // 0x140320950
    void GetRoomIndices(unsigned nDungeonId, ATL::CAtlArray<unsigned>& out);   // 0x140320a40
    void GetRooms(unsigned nDungeonId, ATL::CAtlArray<DungeonRoomPtr>& out);   // 0x140320b40
    void GetRoomsForLevel(unsigned short nLevel, unsigned nGearScore, std::vector<DungeonRoomPtr>& out);   // 0x140320c30
    void GetMatchRooms(unsigned short nLevel, unsigned nGearScore, std::vector<DungeonRoomPtr>& out);      // 0x140320da0
    void GetGroupMatchRooms(DungeonGroupType nGroup, unsigned short nLevel, unsigned nGearScore, std::vector<DungeonRoomPtr>& out);   // 0x140320f80
    void GetGroupRooms(DungeonGroupType nGroup, std::vector<DungeonRoomPtr>& out);          // 0x140321160
    void GetBossRankingRooms(ATL::CAtlList<DungeonRoomPtr>& out, DungeonGroupType nGroup);  // 0x140321210 by gear score, then id
    short GetSeasonId(const CMsTime& t);                        // 0x1403214a0
    MS2Ptr<DungeonSeason> GetCurrentSeason(const CMsTime& t);   // 0x140321550
    MS2Ptr<DungeonSeason> GetSeason(short nSeasonId);           // 0x140321630
    std::vector<DungeonRoomPtr>* GetRoomList();                 // 0x140321710
    int GetRank(DungeonRoom* pRoom, short nScore);              // 0x140321730
    short GetMaxScore(DungeonRoom* pRoom);                      // 0x1403217e0
    DungeonRankRequire* GetRankRequire(DungeonRoom* pRoom);     // 0x140321880
    unsigned GetReverseRaidRoomID(const CMsTime& t);            // 0x140321910
    DungeonRoomPtr GetRoom1003();                               // 0x140321a10
    DungeonRoomPtr GetRoom1004();                               // 0x140321a60
    DungeonRoomPtr GetRoom1007();                               // 0x140321ab0
    MS2Ptr<DungeonRankRewardBase> GetRankReward(int nRewardId); // 0x140321b00
    size_t GetUnitedWeeklyRewardCount();                        // 0x140321bc0
    MS2Ptr<DungeonUnitedWeeklyReward> GetUnitedWeeklyReward(size_t nIndex);         // 0x140321bf0
    MS2Ptr<DungeonUnitedWeeklyReward> FindUnitedWeeklyReward(unsigned nRewardCount); // 0x140321c90
    void LinkRoom(DungeonRoomPtr pRoom);                        // 0x140321dc0
    void AddToSets(DungeonRoomPtr pRoom);                       // 0x140321eb0
    DungeonRoomSet& GetGroupSet(DungeonGroupType nGroup);                    // 0x140321fd0
    void LoadCoupons();                                         // 0x140322000 DungeonRewardCoupon.xml
    DungeonRewardCoupon* GetCoupon(int nCouponId);              // 0x140322260
    DungeonRoundGroup* GetRoundGroup(int nGroupId);             // 0x1403222f0
    bool LoadDungeonConfig(Unk_140165cf0* pElem);               // 0x140322370 MissionRank groups
    bool LoadReverseRaidConfig(Unk_140165cf0* pElem);           // 0x140322440
    bool LoadUnitedWeeklyRewards(Unk_140165cf0* pElem);         // 0x140322530

    // @0x140336680
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CStringA msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(DungeonRoomTable).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x140336e80
    static void SetInit(bool bInit) { s_bInit = bInit; }

    static bool s_bInit;                    // DAT_143aad200

    std::map<unsigned, DungeonRoomPtr> m_rooms;                         // +0x10 by room id
    std::vector<DungeonRoomPtr> m_roomList;                             // +0x20 load order
    std::map<DungeonGroupType, DungeonRoomSet> m_roomsByGroup;          // +0x38 by group type
    std::map<unsigned, MS2Ptr<DungeonRewardCoupon> > m_coupons;              // +0x48
    std::map<unsigned, MS2Ptr<DungeonRankRewardBase> > m_rankRewards;        // +0x58
    std::map<unsigned, MS2Ptr<DungeonRoundGroup> > m_roundGroups;            // +0x68
    std::vector<MS2Ptr<DungeonSeason> > m_seasons;                      // +0x78
    std::map<unsigned, DungeonRankRequire> m_rankRequires;              // +0x90 by rank table id
    std::vector<MS2Ptr<DungeonUnitedWeeklyReward> > m_unitedWeeklyRewards;  // +0xa0
    DungeonRoomSet m_matchRooms;                                        // +0xb8 group types 1 and 2
    DungeonRoomSet m_allRooms;                                          // +0xc8
    CMsTime m_startDate;                                                // +0xd8 ReverseRaidConfig
    int m_periodDays;                                                   // +0xe8
    std::vector<unsigned> m_reverseRaidRooms;                           // +0xf0
};
MS2_CHECK_SIZE(DungeonRoomTable, 0x108);
MS2_CHECK_OFFSET(DungeonRoomTable, m_rooms, 0x10);
MS2_CHECK_OFFSET(DungeonRoomTable, m_roomsByGroup, 0x38);
MS2_CHECK_OFFSET(DungeonRoomTable, m_seasons, 0x78);
MS2_CHECK_OFFSET(DungeonRoomTable, m_rankRequires, 0x90);
MS2_CHECK_OFFSET(DungeonRoomTable, m_matchRooms, 0xb8);
MS2_CHECK_OFFSET(DungeonRoomTable, m_startDate, 0xd8);
MS2_CHECK_OFFSET(DungeonRoomTable, m_reverseRaidRooms, 0xf0);
