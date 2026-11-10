// CGuildManager (RTTI .?AVCGuildManager@@): the client's guild state and the guild packet handlers.
// Bases: TSingleton<CGuildManager> +0 (vftable 0x142f0a5d8, s_instance 0x143aaee00), CGuildInfo +8 (vftable
// 0x142f0a5e8, no overrides). sizeof 0x480 (operator new in the singleton setup). Names other than the RTTI class
// names are inferred; methods without a proven name keep FUN_<va>.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <deque>
#include <map>
#include <set>
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/ascript.h"
class CInPacket;
class NotifyObject;
class CMsgBoxData;
class PCBase;
struct ItemEntity;
// The guild a notice points at (the second base at +8 carries the id and the name).
class Unk_GuildTargetInfo {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual __int64 vfunc_4();                                  // the guild id
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual CStringW vfunc_8();                                 // the guild name
};
class Unk_GuildTargetBase { public: virtual void vfunc_0(); };
class Unk_GuildTarget : public Unk_GuildTargetBase, public Unk_GuildTargetInfo {};

class CGuildManager : public TSingleton<CGuildManager>, public CGuildInfo {
public:
    CGuildManager();
    virtual ~CGuildManager();
    void FUN_1413b5e80();
    void FUN_1413b5f90();
    void ClearGuildInvite();
    int IsInGuild();
    CStringW GetTargetGuildName() { return m_targetGuildName; }   // inline COMDAT (uiguilddialog.cpp: the championship page)
    int HasGuildInvite();
    MS2Ptr<CGuildMember> FindMemberByCharacterId(__int64 characterId);
    void FUN_1413b6370(CInPacket& packet);
    bool FUN_1413b6d10(CStringW name);
    bool SendGuildMode2();
    bool FUN_1413b71c0(CStringW name);
    void SendGuildMode5(int accept);
    void SendGuildMode7();
    void SendGuildMode8(CStringW name);
    void SendGuildMode10(CStringW name, int grade);
    void SendGuildMode63(CStringW name);
    bool FUN_1413b7c70(int kind, CStringW text);
    bool SendGuildMode13(const CStringW& text);
    bool SendGuildMode15();
    bool CanAttend();
    bool FUN_1413b8540(int amount);
    void SendGuildMode65(CString text);
    void SendGuildMode67(int index, CGuildGrade grade);
    void SendGuildMode68(int focus, int value);
    void FUN_1413b8fe0(int skillId);
    void FUN_1413b96e0(int skillId);
    void FUN_1413b9ac0(int skillId);
    void FUN_1413ba080(int eventId);
    void SendGuildMode100(int eventId);
    void FUN_1413ba4b0();
    void FUN_1413ba820(int level, int theme);
    void FUN_1413babf0(int theme);
    void UpdateGuildPoster(int posterId, unsigned char show);
    void FUN_1413bb000(Unk_GuildNpcKind kind);
    bool FUN_1413bb490(ItemEntity& item, const CStringW& receiver);
    void SendGuildMode112();
    bool SendGuildMail(const CStringW& title, const CStringW& body);
    void RequestPvpHistoryAndSeason();
    void GetPvpHistoryNewestFirst(ATL::CAtlArray<MS2Ptr<CGuildPVPHistoryData>>& out);
    void GetPvpSeasonHistoryNewestFirst(ATL::CAtlArray<MS2Ptr<CGuildPVPSeasonHistoryData>>& out);
    void SendPVPMode3();
    void SendPVPMode4();
    void SetTargetGuild(__int64 guildId, CStringW guildName);
    void SetTargetGuildAndNotify(Unk_GuildTarget* target);
    int FUN_1413bc390();
    void SendGuildMode82(__int64 guildId);
    void SendGuildMode83(__int64 guildId);
    void SendGuildMode84(__int64 characterId, int accept);
    void SendGuildMode85();
    void SendGuildMode86();
    void SendGuildMode87(bool anyFocus);
    bool SendGuildMode88(CStringW name);
    int GetMemberPCsInWorld(std::map<unsigned __int64, PCBase*>& out);
    int FUN_1413bcbc0(std::map<unsigned __int64, PCBase*>& out);
    void NotifyGuildNoticeIfChanged();
    void FUN_1413bce40(unsigned int skillId, unsigned short skillLevel);
    int GetSkillCostWithEventDiscount(int skillId, int skillLevel);
    int GetPersonalSkillDiscountedCost(int skillId, int skillLevel);
    void SendGuildMode115();
    void SendGuildMode116();
    void NotifyVsGameCanRegister();
    int GetGuildNotificationCount();
    void FUN_1413bd5c0(NotifyObject* notify);
    void SetGuildExpEvent(bool show);
    void ShowGuildError(int kind, int code, int arg);
    CStringW GetMyName();
    bool SendGuildMode120(int result, const CMsgBoxData& box);
    void FUN_1413c7900(CInPacket& packet);
    void FUN_1413c7aa0(CInPacket& packet);                                 // reload the grade list
    void GetSearchResults(ATL::CAtlArray<MS2Ptr<CSearchGuildJoin>>& out) const;
    MS2Ptr<CSearchGuildJoin> FindSearchResultByName(const CStringW& guildName) const;
    void ClearSearchResults();
    void FUN_1413c7f00(ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForChar>>& out) const;
    void FUN_1413c7f80(ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForGuild>>& out) const;
    MS2Ptr<CGuildJoinRequestForChar> FUN_1413c8000(__int64 guildId) const;
    // @0x14197e010
    int GetSearchPropensity() { return m_468; }                                  // the search propensity (inline; uiguilddialog.cpp)
    // @0x14197e040
    void SetSearchPropensity(int nValue) { m_468 = nValue; }
    // @0x14197dfb0
    __int64 GetTargetGuildId() { return m_targetGuildId; }                 // the pending join / visit guild (inline; uiguilddialog.cpp)

    // packet handlers dispatched by FUN_1413b6370 (exe order)
    void OnPacketGuildInfo(CInPacket& packet);
    void OnPacketCreateGuild(CInPacket& packet);
    void FUN_1413bda00(CInPacket& packet);
    void FUN_1413bdaf0(CInPacket& packet);
    void FUN_1413bdbb0(CInPacket& packet);
    void OnPacketInviteResult(CInPacket& packet);
    void FUN_1413be150(CInPacket& packet);
    void FUN_1413be350(CInPacket& packet);
    void FUN_1413be400(CInPacket& packet);
    void FUN_1413be460(CInPacket& packet);
    void FUN_1413be670(CInPacket& packet);
    void FUN_1413be7e0(CInPacket& packet);
    void OnPacketMemberRenamed(CInPacket& packet);
    void FUN_1413beb10(CInPacket& packet);
    void OnPacketAttendComplete(CInPacket& packet);
    void OnPacketMyDonation(CInPacket& packet);
    void FUN_1413bee70(CInPacket& packet);
    void FUN_1413beed0(CInPacket& packet);
    void FUN_1413beff0(CInPacket& packet);
    void OnPacketExpandCapacity(CInPacket& packet);
    void OnPacketGradeChanged(CInPacket& packet);
    void FUN_1413bf2a0(CInPacket& packet);
    void FUN_1413bf340(CInPacket& packet);
    void FUN_1413bf540(CInPacket& packet);
    void OnPacketGainExpFund(CInPacket& packet);
    void OnPacketOpenEvent(CInPacket& packet);
    void OnPacketMemberJoined(CInPacket& packet);
    void OnPacketMemberLeft(CInPacket& packet);
    void OnPacketMemberExpelled(CInPacket& packet);
    void FUN_1413c0250(CInPacket& packet);
    void FUN_1413c0430(CInPacket& packet);
    void FUN_1413c0630(CInPacket& packet);
    void OnPacketMemberGradeChanged(CInPacket& packet);
    void OnPacketSetMemberMessage(CInPacket& packet);
    void OnPacketMemberContribution(CInPacket& packet);
    void OnPacketMemberRaidCount(CInPacket& packet);
    void OnPacketMasterChanged(CInPacket& packet);
    void OnPacketNoticeChanged(CInPacket& packet);
    void FUN_1413c15b0(CInPacket& packet);
    void OnPacketGuildRenamed(CInPacket& packet);
    void FUN_1413c1840(CInPacket& packet);
    void OnPacketGradeUpdated(CInPacket& packet);
    void FUN_1413c1c50(CInPacket& packet);
    void FUN_1413c1d30(CInPacket& packet);
    void OnPacketMemberDataChanged(CInPacket& packet);
    void OnPacketMemberAchievement(CInPacket& packet);
    void FUN_1413c23d0(CInPacket& packet);
    void FUN_1413c2590(CInPacket& packet);
    void FUN_1413c2860(CInPacket& packet);
    void FUN_1413c28e0(CInPacket& packet);
    void FUN_1413c2c60(CInPacket& packet);
    void OnPacketBattleResult(CInPacket& packet);
    void OnPacketBattleApplied(CInPacket& packet);
    void OnPacketGuildBattleNotice(CInPacket& packet);
    void FUN_1413c3110(CInPacket& packet);
    void FUN_1413c3170(CInPacket& packet);
    void FUN_1413c3460(CInPacket& packet);
    void FUN_1413c3780(CInPacket& packet);
    void FUN_1413c39e0(CInPacket& packet);
    void FUN_1413c3c40(CInPacket& packet);
    void FUN_1413c3e50(CInPacket& packet);
    void FUN_1413c3ef0(CInPacket& packet);
    void OnPacketWeeklyContributionReset(CInPacket& packet);
    void FUN_1413c4300(CInPacket& packet);
    void OnPacketVsGameTicket(CInPacket& packet);
    void OnPacketVsGameMatchCanceled(CInPacket& packet);
    void FUN_1413c45e0(CInPacket& packet);
    void FUN_1413c4870(CInPacket& packet);
    void OnPacketVsGameReward(CInPacket& packet);
    void OnPacketGuildExp(CInPacket& packet);
    void FUN_1413c4b60(CInPacket& packet);
    void FUN_1413c4bd0(CInPacket& packet);
    void OnPacketExpelledOfflineMembers(CInPacket& packet);
    void FUN_1413c4dd0(CInPacket& packet);
    void FUN_1413c4e20(CInPacket& packet);
    void OnRemainTimeNotice(CInPacket& packet);
    void OnPacketPvpHistory(CInPacket& packet);
    void OnPacketPvpSeasonHistory(CInPacket& packet);
    void FUN_1413c5360(CInPacket& packet);
    void FUN_1413c5440(CInPacket& packet);
    void OnPacketJoinRequestAnswer(CInPacket& packet);
    void OnPacketJoinRequestsForGuild(CInPacket& packet);
    void FUN_1413c5840(CInPacket& packet);
    void OnPacketSearchResults(CInPacket& packet);
    void OnPacketStorageGiftResult(CInPacket& packet);
    void OnPacketStorageHistory(CInPacket& packet);
    void OnPacketMyJoinRequestRemoved(CInPacket& packet);
    void FUN_1413c6180(CInPacket& packet);
    void OnPacketJoinRequestReceived(CInPacket& packet);
    void OnPacketJoinRequestWithdrawn(CInPacket& packet);
    void FUN_1413c7700(CInPacket& packet);
    void FUN_1413c7810(CInPacket& packet);

    MS2Ptr<CGuildInviteInfo> m_invite;                                  // +0x378
    std::deque<MS2Ptr<CGuildPVPHistoryData>> m_pvpHistory;             // +0x388 (newest last, at most 10)
    __int64 m_lastPvpHistoryId;                                         // +0x3b0
    std::deque<MS2Ptr<CGuildPVPSeasonHistoryData>> m_pvpSeasonHistory; // +0x3b8
    bool m_3e0;
    bool m_noticeAttendance;                                            // +0x3e1 (cleared after the first notice)
    __int64 m_nextRefreshTime;                                          // +0x3e8
    __int64 m_targetGuildId;                                            // +0x3f0 (the guild of a pending join / guild-house visit)
    CStringW m_targetGuildName;
    bool m_400;
    ATL::CAtlArray<MS2Ptr<CSearchGuildJoin>> m_searchResults;             // +0x408
    ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForChar>> m_joinRequestsForChar; // +0x428
    ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForGuild>> m_joinRequestsForGuild; // +0x448
    int m_468;
    std::set<std::pair<unsigned int, unsigned short>> m_470;                  // +0x470 (skill id, level) uses awaiting the server ack
};
MS2_CHECK_OFFSET(CGuildManager, m_invite, 0x378);
MS2_CHECK_OFFSET(CGuildManager, m_pvpHistory, 0x388);
MS2_CHECK_OFFSET(CGuildManager, m_pvpSeasonHistory, 0x3b8);
MS2_CHECK_OFFSET(CGuildManager, m_targetGuildName, 0x3f8);
MS2_CHECK_OFFSET(CGuildManager, m_searchResults, 0x408);
MS2_CHECK_OFFSET(CGuildManager, m_468, 0x468);
MS2_CHECK_SIZE(CGuildManager, 0x480);
