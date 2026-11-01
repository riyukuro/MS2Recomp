// partyvotecli.h - the two vote kinds of the party vote object (base PartyVoteCli: ms2/placeholder/partyvotecli.h).
// Kind 1 = kick a member (PartyVoteKickUserCli, 0x78 bytes), kind 2 = ready check (PartyVoteReadyCli, 0x60 bytes).
// Names other than the RTTI class names are inferred.
#pragma once

#include "ms2/placeholder/partyvotecli.h"

class CMsgBoxData;

class PartyVoteKickUserCli : public PartyVoteCli {
public:
    PartyVoteKickUserCli();
    virtual ~PartyVoteKickUserCli() = default;
    void vfunc_1(CInPacket& packet) override;
    void vfunc_2() override;
    CStringW vfunc_4() override;
    unsigned char vfunc_5() override;
    __int64 target;
    CStringW name;
    unsigned char reason;
};
MS2_CHECK_SIZE(PartyVoteKickUserCli, 0x78);
MS2_CHECK_OFFSET(PartyVoteKickUserCli, name, 0x68);

class PartyVoteReadyCli : public PartyVoteCli {
public:
    PartyVoteReadyCli();
    virtual ~PartyVoteReadyCli() = default;
    void vfunc_2() override;
    void vfunc_3() override;
    void vfunc_6(unsigned __int64 id) override;
    void vfunc_7(__int64 id, bool accepted) override;
    bool OnMessageBoxResult(int result, const CMsgBoxData& box);
};
MS2_CHECK_SIZE(PartyVoteReadyCli, 0x60);
