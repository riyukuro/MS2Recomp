// PartyVoteCli layout from ctor 140a89190 and its virtual callers.
#pragma once
#include <afx.h>
#include <set>
#include "ms2/placeholder/cptred.h"
class CInPacket;
class PartyVoteCli : public CPtred {
public:
    PartyVoteCli();
    virtual ~PartyVoteCli() = default;
    virtual void vfunc_1(CInPacket&);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual CStringW vfunc_4();
    virtual unsigned char vfunc_5();
    virtual void vfunc_6(unsigned __int64);
    virtual void vfunc_7(__int64, bool);
    void AddVote(unsigned __int64, bool);
    int GetKind() const;      // kind
    size_t GetYesCount();         // yes count
    size_t GetNoCount();         // no count
    bool HasVoted();     // the local player already voted
    void SendParty(bool);       // sends the vote (0x2c / 0x30)
    CStringW GetRemainingTimeText() const; // remaining time text
    int id, kind;
    __int64 owner, expires;
    std::set<unsigned __int64> participants, yes, no;   // unsigned: find(key) 0x1404c0270 / erase(key) 0x1404bfb40 use less<unsigned __int64> (jae)
};
MS2_CHECK_SIZE(PartyVoteCli, 0x60);
MS2_CHECK_OFFSET(PartyVoteCli, participants, 0x30);
