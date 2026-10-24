// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A small static table (id -> cost) kept in an ATL CRBMap, with
// its lookups, and the CRBMap instantiation (RBTree glue, CAtlArray<int> growth). File and function names are invented.
// MS2-UNIT: unit_140837660
// MS2-RANGE: 0x1400bd1f0-0x1400bd250 .text$di
// MS2-RANGE: 0x140837660-0x140838d50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Add@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@QEAA_KAEBH@Z 0x140837a20 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@H@ATL@@SAHAEBH0@Z 0x140837ad0 ; unique
// MS2-PIN: ?Find@?$CRBTree@H_KV?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@_K@2@@ATL@@IEBAPEAVCNode@12@AEBH@Z 0x140837b10 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@AEAA_N_K@Z 0x140837d60 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@H_KV?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@_K@2@@ATL@@AEAAPEAVCNode@12@AEBH_K@Z 0x140837f00 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@H@ATL@@SAXPEAH0_K@Z 0x140838860 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/ms2recover.h"
#include "ms2/placeholder/clockcriticalsection.h"

typedef ATL::CRBMap<int, unsigned __int64, ATL::CDefaultElementTraits<int> > Unk_CostMap;

static Unk_CostMap s_costs(10);
static CLockCriticalSection s_lock;

void FUN_140837660();
#ifndef MS2_HOOK_DLL
// @0x140837660
void FUN_140837660()
{
    s_costs.SetAt(0, 1);
    s_costs.SetAt(1, 1);
    s_costs.SetAt(2, 1);
    s_costs.SetAt(3, 1);
    s_costs.SetAt(4, 10);
    s_costs.SetAt(0x11, 3);
}
#endif

int FUN_140837730(int nId);
#ifndef MS2_HOOK_DLL
// @0x140837730
int FUN_140837730(int nId)
{
    return s_costs.Lookup(nId) != 0;
}
#endif

// @0x140837770
unsigned __int64 FUN_140837770(int nId, unsigned nCount)
{
    unsigned __int64 nCost = 0;
    if (FUN_140837730(nId) == 0)
        return nCost;
    s_costs.Lookup(nId, nCost);
    return nCost * nCount;
}

// @0x1408377d0
void FUN_1408377d0(ATL::CAtlArray<int, ATL::CDefaultElementTraits<int> >& ids)
{
    for (POSITION pos = s_costs.GetHeadPosition(); pos != 0; s_costs.GetNext(pos))
    {
        ids.Add(s_costs.GetKeyAt(pos));
    }
}

// @0x140838c30
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c410-0x142c9c430 .text$yd
// MS2-RANGE: 0x142c9c490-0x142c9c4b0 .text$yd
