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
struct Unk_PartyRecruitInvite;
class CMsgBoxData;
class CPartyManager : public TSingleton<CPartyManager> {
public:
    CPartyManager();
    virtual ~CPartyManager();
    void FUN_14162a310();
    void FUN_14162a340();
    void FUN_14162a370();
    void FUN_14162a480();
    void OnParty(CInPacket&);
    void FUN_14162a840(TPtr<PCBase>);
    void FUN_14162a910(TPtr<PCBase>);
    void FUN_14162aa10(TPtr<PCBase>);
    void SendPartyMode1(CStringW);
    void SendPartyMode23(const Unk_PartyRecruitInvite&);
    void FUN_14162bcc0(MS2Ptr<CMatchPartyRecruit>);
    int FUN_14162bf20();
    void SendMatchPartyMode0(const Unk_PartyRecruitRequest&);
    void SendMatchPartyMode2(const CMatchPartyRecruitSchCond&);
    int FUN_14162ab00();
    bool FUN_14162ab20();
    bool FUN_14162ab60();
    bool FUN_14162aba0(int);
    bool FUN_14162abe0();
    bool FUN_14162ac00(int);
    bool FUN_14162ac40();
    bool FUN_14162ac70(int);
    bool FUN_14162ad30();
    int FUN_14162ad50(CStringW);                // exe returns a full int (callers test eax)
    int FUN_14162ae20(__int64);                 // exe returns a full int (callers test eax)
    int FUN_14162ae90(__int64);                 // exe returns a full int (callers test eax)
    int FUN_14162af00();
    int FUN_14162af30(__int64);
    MS2Ptr<CPartyMember> FUN_14162afc0(__int64);
    MS2Ptr<CPartyMember> FUN_14162b0c0(CStringW);
    MS2Ptr<CPartyMember> FUN_14162b260(__int64);
    MS2Ptr<CPartyMember> FUN_14162b360(int);
    MS2Ptr<CPartyMember> FUN_14162b400();
    CStringW FUN_14162b4f0();
    int FUN_14162b540();
    void FUN_14162b560(CStringW);
    void FUN_14162b740();
    void FUN_14162b790();
    void SendPartyMode4(CStringW);
    void SendPartyMode45(__int64);
    void SendPartyMode2(int);
    ATL::CAtlArray<MS2Ptr<CPartyMember>>& FUN_14162ba30();
    void SendRoomDungeon(int);
    void SendPartyMode46();
    void SendPartyMode3();
    int FUN_14162be70();
    int FUN_14162c090();
    unsigned short FUN_14162c0b0();
    unsigned FUN_14162c1e0();
    void FUN_14162c3a0();
    void FUN_14162c4a0(int);
    void FUN_14162c580(__int64, int);
    void FUN_14162c630();
    void FUN_14162c670(int);
    void FUN_14162c8b0(CInPacket&);
    void FUN_14162cc40(CInPacket&);
    void FUN_14162cea0(CInPacket&);
    void FUN_14162d070(CInPacket&);
    void FUN_14162d220();
    void FUN_14162d2b0(CInPacket&);
    void FUN_14162d5b0(CInPacket&);
    void FUN_14162db10(CInPacket&);
    void FUN_14162de40(CInPacket&);
    void FUN_14162dfc0(CInPacket&);
    void FUN_14162e100(CInPacket&);
    void FUN_14162e240(CInPacket&);
    void FUN_14162e310(CInPacket&);
    void FUN_14162e3d0(CInPacket&);
    void FUN_14162e5d0(CInPacket&);
    void FUN_14162e730(CInPacket&);
    void FUN_14162e820(CInPacket&);
    void FUN_14162e9d0(CInPacket&);
    void FUN_14162ea90(CInPacket&);
    void FUN_14162ed60();
    void FUN_14162ee10(CInPacket&);
    void FUN_14162ee70(CInPacket&);
    void FUN_14162f030(CInPacket&);
    void FUN_1416302f0(CInPacket&);
    void FUN_1416303b0(CInPacket&);
    void FUN_141630790(CInPacket&);
    void FUN_141630a60(CInPacket&);
    CStringW FUN_141630db0(CStringW);
    bool FUN_14162c300();
    MS2Ptr<PartyVoteCli> FUN_14162c350();
    void FUN_141630550(CInPacket&);
    void FUN_141630670(CInPacket&);
    void FUN_141630720();
    bool FUN_141630c30(__int64);
    bool FUN_141630c70(int, const CMsgBoxData&);
    void FUN_141630cb0();
    void FUN_141630fd0();
    void FUN_141631030();
    void FUN_141631060();
    void OnMatchParty(CInPacket&);
    void SendMatchPartyMode1();
    void FUN_1416312f0(int);
    int FUN_141631330();
    void FUN_141631370(CInPacket&);
    void FUN_141631410(CInPacket&);
    void FUN_1416314c0(CInPacket&);
    void FUN_141631700(CInPacket&);
    int FUN_141631cc0();
    int FUN_141631dd0();
    CMatchPartyRecruit& FUN_141631ce0();
    ATL::CAtlMap<__int64, MS2Ptr<CMatchPartyRecruit>>& FUN_141631d00();
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
