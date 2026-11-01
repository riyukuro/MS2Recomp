// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPartyMember: one member of the party (ms2/placeholder/cpartymember.h),
// its constructor/destructor and the small field accessors used by CPartyManager.
// MS2-UNIT: ?\partymember.cpp
// MS2-RANGE: 0x141637930-0x141637d50 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\partymember.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/cpartymember.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class Unk_LockedIntMap   // C3: member view for the former free stand-ins
{
public:
    void Assign(class Unk_LockedIntMap*);
};
__int64 FUN_141637b90(CPartyMember* pMember);
int FUN_141637c40(CPartyMember* pMember);
int FUN_141637cf0(CPartyMember* pMember);

// @0x141637930
CPartyMember::CPartyMember(int nIndex)
    : index(nIndex), role(1), leader(0), offline(false)
{
    readyState = 0;
}

// @0x1416379e0
CPartyMember::~CPartyMember()
{
}

// @0x141637a40
void CPartyMember::SetOffline(bool bOffline)
{
    offline = bOffline;
}
MS2_REPLACE_METHOD(0x141637A40, CPartyMember, SetOffline, 23, 0x5185E109);

// @0x141637a60
void CPartyMember::FUN_141637a60(short nValue)
{
    user.m_34 = nValue;
}
MS2_REPLACE_METHOD(0x141637A60, CPartyMember, FUN_141637a60, 25, 0xD3EFB748);

// @0x141637a80
void CPartyMember::FUN_141637a80(int a, int b)
{
    if (user.m_48 == a && user.m_44 == b)
        return;
    user.m_48 = a;
    user.m_44 = b;
}
MS2_REPLACE_METHOD(0x141637A80, CPartyMember, FUN_141637a80, 69, 0x7FFDD686);

// @0x141637ad0
void CPartyMember::FUN_141637ad0(int nValue)
{
    user.m_3c = nValue;
}
MS2_REPLACE_METHOD(0x141637AD0, CPartyMember, FUN_141637ad0, 22, 0x5E3B67AF);

// @0x141637af0
void CPartyMember::SetLeader(int nValue)
{
    leader = nValue;
}
MS2_REPLACE_METHOD(0x141637AF0, CPartyMember, SetLeader, 22, 0xF6E32213);

// @0x141637b10
void CPartyMember::SetRole(int nValue)
{
    role = nValue;
}
MS2_REPLACE_METHOD(0x141637B10, CPartyMember, SetRole, 22, 0x6E748507);

// @0x141637b30
void CPartyMember::FUN_141637b30(int nValue)
{
    readyState = nValue;
}
MS2_REPLACE_METHOD(0x141637B30, CPartyMember, FUN_141637b30, 25, 0x0BE2A528);

// @0x141637b50
void CPartyMember::SetCounters(const Unk_PartyCounters* pCounters)
{
    ((class Unk_LockedIntMap*)(struct Unk_PartyCounters*)(&counters))->Assign((class Unk_LockedIntMap*)(pCounters));
}
MS2_REPLACE_METHOD(0x141637B50, CPartyMember, SetCounters, 43, 0x0B77F2C1);

// @0x141637b90
__int64 FUN_141637b90(CPartyMember* pMember)
{
    return pMember->user.m_0;
}

// @0x141637bb0
__int64 CPartyMember::FUN_141637bb0()
{
    return user.m_8;
}
MS2_REPLACE_METHOD(0x141637BB0, CPartyMember, FUN_141637bb0, 15, 0xAC153A31);

// @0x141637bd0
CStringW CPartyMember::FUN_141637bd0()
{
    return user.FUN_1408f19e0();
}
MS2_REPLACE_METHOD(0x141637BD0, CPartyMember, FUN_141637bd0, 65, 0x67BF551D);

// @0x141637c20
bool CPartyMember::FUN_141637c20()
{
    return offline;
}
MS2_REPLACE_METHOD(0x141637C20, CPartyMember, FUN_141637c20, 15, 0x6AAAA609);

// @0x141637c40
int FUN_141637c40(CPartyMember* pMember)
{
    if (pMember->FUN_141637c20())
        return 0;
    if (pMember->user.m_184)
        return 2;
    return 1;
}

// @0x141637c90
int CPartyMember::FUN_141637c90()
{
    if (FUN_141637c20())
        return 0;
    return readyState;
}
MS2_REPLACE_METHOD(0x141637C90, CPartyMember, FUN_141637c90, 46, 0x416E31BE);

// @0x141637cd0
void CPartyMember::FUN_141637cd0(int nValue)
{
    index = nValue;
}
MS2_REPLACE_METHOD(0x141637CD0, CPartyMember, FUN_141637cd0, 22, 0x068001AB);

// @0x141637cf0
int FUN_141637cf0(CPartyMember* pMember)
{
    if (pMember->user.m_8 == 0)
        return 0;
    return 1;
}
