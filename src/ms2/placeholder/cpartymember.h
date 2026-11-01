// Shared party member layout. Names of fields are inferred from the manager and member methods.
#pragma once
#include "ms2/commonfiles/userproxy.h"
#include "ms2/placeholder/cptred.h"

enum Unk_LimitValue : int;   // value type of the counter map (an enum in the exe; same layout as int; see unit_140268010.cpp)

struct Unk_PartyCounters {
    Unk_PartyCounters(); // 140268010
    ~Unk_PartyCounters();
    CLockCriticalSection lock;
    ATL::CAtlMap<int, Unk_LimitValue> values;
    int FUN_140268570(int);
};
MS2_CHECK_SIZE(Unk_PartyCounters, 0x78);

class CPartyMember : public CPtred {
public:
    explicit CPartyMember(int);
    virtual ~CPartyMember();
    void FUN_141637a60(short);
    void FUN_141637a80(int, int);
    void FUN_141637ad0(int);
    void SetRole(int);
    void SetReadyState(int);
    void SetCounters(const Unk_PartyCounters*);
    __int64 FUN_141637bb0();
    bool FUN_141637c20();
    int FUN_141637c90();
    void FUN_141637cd0(int);
    void SetOffline(bool);
    void SetLeader(int);
    CStringW FUN_141637bd0();
    int index;
    int role;
    int leader;
    bool offline;
    Unk_UserProxy user;
    Unk_PartyCounters counters;
    int readyState;
};
// ctor 141637930, dtor 1416379e0; the last store is the dword at +3f0.
MS2_CHECK_OFFSET(CPartyMember, user, 0x28);
MS2_CHECK_OFFSET(CPartyMember, counters, 0x378);
MS2_CHECK_OFFSET(CPartyMember, readyState, 0x3f0);
MS2_CHECK_SIZE(CPartyMember, 0x3f8);
