// CPartyManager; names other than the RTTI class name are inferred.
#pragma once
#include <map>
#include "ms2/placeholder/tptr.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cpartymember.h"
#include "ms2/placeholder/cmatchpartyrecruit.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/partyvotecli.h"
#include "ms2/placeholder/partybits.h"
class CInPacket;
class PCBase;
class CMatchPartyRecruitSchCond;
struct Unk_PartyRecruitRequest;
struct Unk_PayloadIdentity;
class CMsgBoxData;
class CPartyManager : public TSingleton<CPartyManager> {
public:
    CPartyManager();
    virtual ~CPartyManager();
    void FUN_14162a310();
    void FUN_14162a340();
    void ClearParty();
    void FUN_14162a480();
    void OnParty(CInPacket&);
    void UpdateMemberJob(TPtr<PCBase>);
    void UpdateMemberHp(TPtr<PCBase>);
    void UpdateMemberLevel(TPtr<PCBase>);
    void SendPartyMode1(CStringW);
    void SendPartyMode23(const Unk_PayloadIdentity&);
    void SendPartyInviteFromRecruit(MS2Ptr<CMatchPartyRecruit>);
    int CountOnlineMembersOutsideTutorial();
    void SendMatchPartyMode0(const Unk_PartyRecruitRequest&);
    void SendMatchPartyMode2(const CMatchPartyRecruitSchCond&);
    int GetPartyId();
    bool IsInParty();
    bool IsLocalPlayerLeader();
    bool IsPartyId(int);
    bool IsMatchmaking();
    bool IsMatchSearching(int);
    bool IsAnySearching();
    bool CanEnterDungeonRoom(int);
    bool FUN_14162ad30();
    int IsMemberByName(CStringW);                // exe returns a full int (callers test eax)
    int IsMemberByCharId(__int64);                 // exe returns a full int (callers test eax)
    int IsMemberByAccountId(__int64);                 // exe returns a full int (callers test eax)
    int FUN_14162af00();
    int GetMemberIndex(__int64);
    MS2Ptr<CPartyMember> FindMemberByCharId(__int64);
    MS2Ptr<CPartyMember> FindMemberByName(CStringW);
    MS2Ptr<CPartyMember> FindMemberByAccountId(__int64);
    MS2Ptr<CPartyMember> GetMemberAt(int);
    MS2Ptr<CPartyMember> FindLeader();
    CStringW GetPartyName();
    int GetPartyKind();
    void SetLeaderByName(CStringW);
    void ClearLeaderName();
    void CloseDialogs();
    void SendPartyMode4(CStringW);
    void SendPartyMode45(__int64);
    void SendPartyMode2(int);
    ATL::CAtlArray<MS2Ptr<CPartyMember>>& GetMembers();
    void SendRoomDungeon(int);
    void SendPartyMode46();
    void SendPartyMode3();
    int GetOnlineMemberCount();
    int GetDungeonId();
    unsigned short GetMinMemberLevel();
    unsigned FUN_14162c1e0();
    void FUN_14162c3a0();
    void SetAllMembersState(int);
    void SetMemberReadyState(__int64, int);
    void ClearPartyNameAndKind();
    void RemoveMemberAt(int);
    void OnPartyInvite(CInPacket&);
    void OnPartyMemberJoin(CInPacket&);
    void OnPartyMemberLeave(CInPacket&);
    void OnPartyMemberKick(CInPacket&);
    void FUN_14162d220(CInPacket& packet);
    void OnPartyLeaderChange(CInPacket&);
    void OnPartyInfo(CInPacket&);
    void OnPartyMemberOnline(CInPacket&);
    void OnPartyMemberOffline(CInPacket&);
    void FUN_14162dfc0(CInPacket&);
    void FUN_14162e100(CInPacket&);
    void OnPartyMemberCounters(CInPacket&);
    void FUN_14162e310(CInPacket&);
    void FUN_14162e3d0(CInPacket&);
    void OnPartyNotice(CInPacket&);
    void FUN_14162e730(CInPacket&);
    void OnPartyMatchDungeonChange(CInPacket&);
    void OnPartyRecruitUpdate(CInPacket&);
    void OnPartyDungeonMatchRegister(CInPacket&);
    void OnPartyDungeonMatchConfirm(CInPacket& packet);
    void FUN_14162ee10(CInPacket&);
    void FUN_14162ee70(CInPacket&);
    void OnPartyResultMessage(CInPacket&);
    void OnPartyFindDungeonCooldown(CInPacket&);
    void OnPartyInviteSent(CInPacket&);
    void OnPartySurvivalSquadRegister(CInPacket&);
    void OnPartyDungeonRoomCreate(CInPacket&);
    CStringW FormatDungeonGroupList(CStringW);
    bool HasVote();
    MS2Ptr<PartyVoteCli> GetVote();
    void OnPartyVoteStart(CInPacket&);
    void OnPartyVoteReply(CInPacket&);
    void OnPartyVoteEnd(CInPacket& packet);
    bool IsLeaderId(__int64);
    bool OnDungeonRoomMsgBoxAnswer(int, const CMsgBoxData&);
    void PurgeExpiredInvitations();
    void ClearRecruitmentAndResetSearchUI();
    void ClearVote();
    void ResetRecruitmentAndRefreshSearch();
    void OnMatchParty(CInPacket&);
    void SendMatchPartyMode1();
    void SetPartyDeadline(int);
    int GetPartyDeadlineRemaining();
    void OnMatchPartyRecruitRegistered(CInPacket&);
    void OnMatchPartyRecruitRemoved(CInPacket&);
    void OnMatchPartySearchResults(CInPacket&);
    void OnMatchPartyError(CInPacket&);
    int IsRecruitPending();
    int FUN_141631dd0();
    CMatchPartyRecruit& FUN_141631ce0();
    ATL::CAtlMap<__int64, MS2Ptr<CMatchPartyRecruit>>& GetRecruitMap();
    ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit>>& FUN_141631d20();
    MS2Ptr<CMatchPartyRecruit> FUN_141631d40(__int64);
    int partyId;
    __int64 leaderId;
    CStringW leaderName;
    bool matchmaking;
    int dungeonId;
    Unk_PartyBits permissions;
    bool flag29;
    ATL::CAtlArray<MS2Ptr<CPartyMember>> members;
    CStringW partyName;
    int partyKind;
    std::map<CStringW, CMsTime> invitations;
    CMatchPartyRecruit recruitment;
    ATL::CAtlMap<__int64, MS2Ptr<CMatchPartyRecruit>> recruits;
    ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit>> results;
    unsigned deadline;
    int searchPending, recruitPending;
    MS2Ptr<PartyVoteCli> vote;
};
MS2_CHECK_OFFSET(CPartyManager, members, 0x30);
MS2_CHECK_OFFSET(CPartyManager, invitations, 0x60);
MS2_CHECK_OFFSET(CPartyManager, recruitment, 0x70);
MS2_CHECK_OFFSET(CPartyManager, recruits, 0xd8);
MS2_CHECK_OFFSET(CPartyManager, results, 0x120);
MS2_CHECK_OFFSET(CPartyManager, vote, 0x150);
MS2_CHECK_SIZE(CPartyManager, 0x160);
