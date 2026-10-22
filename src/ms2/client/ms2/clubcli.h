// Original: client\ms2\clubcli.h (name assumed from the .cpp). CClubClientManager: the client-side club registry. It
// keeps the clubs the player joined and the pending club invitations (both keyed by id, guarded by one lock), sends
// the club requests (opcode 0x95) and dispatches the club packets to the clubs (CClubCli, see commonfiles\clubcommon.h).
// The manager is a TSingleton (global 0x143abad48). Members and Unk_ names are inferred.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/clubcommon.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/tptreddummy.h"

class CInPacket;
class CMsgBoxData;

// The joined clubs by id, and the invitations by invitation id.
typedef ATL::CRBMap<unsigned __int64, MS2Ptr<CClubCli> > Unk_ClubCliMap;
typedef ATL::CRBMap<unsigned __int64, MS2Ptr<Club::PacketInvite> > Unk_ClubInviteMap;

// The filtered copy of the club map (FUN_140b14e40) is an intrusive-counted box (TPtredDummy, 0x48 bytes).
template<> struct Unk_SocketRef<Unk_ClubCliMap>
{
    static CPtred* Base(Unk_ClubCliMap* p)
    {
        CPtred* result;
        if (p == NULL)
            result = NULL;
        else
            result = CONTAINING_RECORD(p, TPtredDummy<Unk_ClubCliMap>, value);
        return result;
    }
    static TPtredDummy<Unk_ClubCliMap>* New(void*) { return new TPtredDummy<Unk_ClubCliMap>(); }
    static Unk_ClubCliMap* Value(CPtred* p)
    {
        Unk_ClubCliMap* result;
        if (p == NULL)
            result = NULL;
        else
            result = &static_cast<TPtredDummy<Unk_ClubCliMap>*>(p)->value;
        return result;
    }
    static Unk_ClubCliMap* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(Unk_ClubCliMap)
MS2_CHECK_SIZE(TPtredDummy<Unk_ClubCliMap>, 0x48);
MS2_CHECK_OFFSET(TPtredDummy<Unk_ClubCliMap>, value, 0x18);

// 0x98 bytes, vftable 0x142ddacb8 (the destructor only).
class CClubClientManager : public TSingleton<CClubClientManager>
{
public:
    CClubClientManager();                                           // 0x140b14b70
    virtual ~CClubClientManager();                                  // 0x140b14bf0

    void FUN_140b14c50();                                           // forget all clubs and invitations
    int FUN_140b14cd0();                                            // 1 when the clubs plus the invitations exceed the limit
    MS2Ptr<CClubCli> FUN_140b14d80(__int64 nClubId);                // a joined club by id
    Unk_SocketPtr<Unk_ClubCliMap> FUN_140b14e40();                  // the clubs that are fully joined (state 2)
    __int64 FUN_140b14fc0(CStringW strName);                        // a joined club's id by name, 0 if none
    CStringW FUN_140b15150(__int64 nClubId);                        // a club's name
    int FUN_140b15210(__int64 nClubId);                             // the club is known
    int FUN_140b15290(__int64 nClubId);                             // same, other caller
    int FUN_140b15310();                                            // 1 when a fully joined club exists
    void FUN_140b15440(MS2Ptr<CClubCli> spClub);                    // add a club
    void FUN_140b15530(__int64 nClubId);                            // remove a club
    void FUN_140b155a0(MS2Ptr<Club::PacketInvite> spInvite);        // add an invitation
    void FUN_140b15640(__int64 nInviteId);                          // remove an invitation
    MS2Ptr<Club::PacketInvite> FUN_140b156b0(__int64 nInviteId);    // an invitation by id
    MS2Ptr<CClubMember> FUN_140b15770(__int64 nClubId, __int64 nCharacterId);   // a club member by character id
    int FUN_140b15830(__int64 nClubId);                             // number of members of a club that are online
    void OnClub(CInPacket& packet);                          // dispatch a club packet (opcode 0x56 sub-opcode)

    bool FUN_140b15c10(CStringW strName);                           // request: create a club
    void FUN_140b15f40(__int64 nClubId, int nCode);                 // request: answer a club invitation to join
    bool FUN_140b16030(__int64 nClubId);                            // the club's "always true"
    bool FUN_140b160c0(__int64 nClubId, CStringW strName);          // request: add a member
    void FUN_140b161a0(__int64 nInviteId, int bAccept);             // request: answer an invitation
    void FUN_140b16270(__int64 nClubId);                            // request: withdraw
    void FUN_140b162f0(__int64 nClubId, CStringW strName);          // request: change the leader
    void FUN_140b163c0(__int64 nClubId, int nBuffId, int nLevel);   // request: set the buff
    void FUN_140b16450(__int64 nClubId, CStringW strName);          // request: rename the club

    // Packet handlers by sub-opcode (OnClub).
    void FUN_140b16520(CInPacket& packet);                          // 0 a club (own record)
    void FUN_140b16650(CInPacket& packet);                          // 1
    void FUN_140b166d0(CInPacket& packet);                          // 2 a club to join
    void FUN_140b16a70(CInPacket& packet);                          // 4
    void FUN_140b16b20(CInPacket& packet);                          // 5
    void FUN_140b16bc0(CInPacket& packet);                          // 6
    void FUN_140b16d20(CInPacket& packet);                          // 7 an invitation
    void FUN_140b17150(CInPacket& packet);                          // 8
    void FUN_140b17210(CInPacket& packet);                          // 9
    void FUN_140b173f0(CInPacket& packet);                          // 10
    void FUN_140b17530(CInPacket& packet);                          // 0xc
    void FUN_140b17600(CInPacket& packet);                          // 0xd
    void FUN_140b176e0(CInPacket& packet);                          // 0xf
    void FUN_140b17780(CInPacket& packet);                          // 0x10
    void FUN_140b17a60(CInPacket& packet);                          // 0x11 (forwards to the club)
    void FUN_140b17b00(CInPacket& packet);                          // 0x12
    void FUN_140b17ba0(CInPacket& packet);                          // 0x13
    void FUN_140b17c40(CInPacket& packet);                          // 0x14
    void FUN_140b17ce0(CInPacket& packet);                          // 0x15
    void FUN_140b17d80(CInPacket& packet);                          // 0x16
    void FUN_140b17e20(CInPacket& packet);                          // 0x17
    void FUN_140b17ec0(CInPacket& packet);                          // 0x18
    void FUN_140b17f60(CInPacket& packet);                          // 0x19
    void FUN_140b18000(CInPacket& packet);                          // 0x1a
    void FUN_140b180a0(CInPacket& packet);                          // 0x1b
    void FUN_140b18140(CInPacket& packet);                          // 0x1c
    void FUN_140b181e0(CInPacket& packet);                          // 0x1d
    void FUN_140b18260(CInPacket& packet);                          // 0x1e

    bool FUN_140b18390(int nResult, const CMsgBoxData& data);       // "join this club?" box result
    bool FUN_140b18400(int nResult, const CMsgBoxData& data);       // invitation box result

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                                    // +0x08
    Unk_ClubInviteMap m_invites;                                    // +0x38
    Unk_ClubCliMap m_clubs;                                         // +0x68
};
MS2_CHECK_SIZE(CClubClientManager, 0x98);
MS2_CHECK_OFFSET(CClubClientManager, m_lock, 0x08);
MS2_CHECK_OFFSET(CClubClientManager, m_invites, 0x38);
MS2_CHECK_OFFSET(CClubClientManager, m_clubs, 0x68);
