// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateBannerData (the payload of the banner state, 0x20)
// mirrors its banner id into / out of the state-sync record's animation string; StateBanner (actor state type 0x3b,
// 0x50) attaches that payload to the owner and pushes / clears the owner's banner. The unit also holds this unit's
// MS2Ptr<StateBannerData> instantiation copies and its unreferenced CRT memcpy_s / memmove_s copies.
// MS2-UNIT: ?\statebannerdata.cpp
// MS2-RANGE: 0x140b7edf0-0x140b7fa70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statebannerdata.cpp"
// The exe's memcpy_s / memmove_s are plain calls (no /Oi expansion); the pragma must precede the inline copies.
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <new>
#include <string.h>
#include <vcruntime_string.h>

#include <NiActorManager.h>
#include <egf/EntityID.h>

#include "ms2/client/ms2/statebannerdata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// ---- unit-local view of the state-sync record (StateData slots 1/2 argument) ----

class Unk_StateDataArg
{
public:
    char m_pad_00[0x70];
    CString m_str70;                        // +0x70
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

// ---- callees / data outside this unit ----

CString FUN_1405a7e80(int nBanner);                     // 0x1405a7e80: banner id -> text
int FUN_140718170(const CString& strId);                // 0x140718170: text -> id
void* FUN_141b6f910();                                  // 0x141b6f910: the animation service singleton
NiActorManager* FUN_140999440(void* pSvc, const egf::EntityID& kId);   // 0x140999440 (ICF: AnimationService)
unsigned int FUN_1409a1a00(NiActorManager* pActor);     // 0x1409a1a00: the actor's playing sequence id
bool FUN_140b73bc0(MyPC* pPlayer);                      // 0x140b73bc0: the player can join the banner micro game
extern Vector3 DAT_143b01a60;                   // 0x143b01a60: the zero point
int FUN_140b7f6a0(void* pSvc, const egf::EntityID& kId);   // 0x140b7f6a0 (defined below)

// ---- StateBannerData ----

// @0x140b7edf0
StateBannerData::StateBannerData() : m_nBanner(0)
{
}

// @0x140b7ee30
StateBannerData::StateBannerData(int nBanner) : m_nBanner(nBanner)
{
}

// Writes the banner's text into the sync record's animation string.
// @0x140b7ee80
void StateBannerData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_str70 = FUN_1405a7e80(m_nBanner);
}

// Reads the banner id back out of the sync record's animation string.
// @0x140b7ef00
void StateBannerData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nBanner = FUN_140718170(p->m_str70);
}

// ---- StateBanner ----

// @0x140b7ef50
StateBanner::StateBanner(PCBase* pOwner) : State(pOwner)
{
}

// @0x140b7efb0
StateBanner::~StateBanner()
{
}

// @0x140b7eff0
void StateBanner::vfunc_2(int n)
{
    PCBase* pOwner = FUN_1417b8370();
    if (pOwner == 0)
        return;
    if (m_n10 == n)
        return;
    m_n10 = n;
    switch (n)
    {
    case 0x97:
        pOwner->FUN_1416700b0(FUN_140b7f3b0());
        break;
    case 0x98:
        pOwner->FUN_1416700b0(0);
        break;
    }
}

// Enter: take the banner payload; with none, clear the owner's banner instead of pushing one.
// @0x140b7f080
void StateBanner::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spBannerData.AssignRaw(dynamic_cast<StateBannerData*>(pData));
    if (m_spBannerData == 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
    else
        m_pOwner->FUN_1416700b0(m_spBannerData->m_nBanner);
}

// Leave: drop the banner from the owner.
// @0x140b7f150
void StateBanner::vfunc_5(int n)
{
    State::vfunc_5(n);
    PCBase* pOwner = FUN_1417b8370();
    if (pOwner == 0)
        return;
    m_n10 = 0;
    pOwner->FUN_1416700b0(0);
}

// @0x140b7f1b0
void StateBanner::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Vector3 kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// @0x140b7f230
void StateBanner::vfunc_8(double fTime)
{
}

// MS2-FUNCTIONAL: egf::EntityID's default ctor is emitted here, but the exe leaves the out-param unconstructed (frame 0x10 smaller)
// @0x140b7f250
void StateBanner::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    egf::EntityID kId;
    FUN_140b7f320(FUN_140b7f6a0(FUN_141b6f910(), m_pOwner->FUN_14123c460(kId)));
}

// MS2-FUNCTIONAL: as vfunc_4 (vfunc_59's 5th arg)
// @0x140b7f2c0
void StateBanner::vfunc_6()
{
    MyPC* pPlayer = FUN_1417b84b0();
    if (pPlayer != 0)
        pPlayer->vfunc_59(1, 0, 0, 0);
}

// @0x140b7f320
void StateBanner::FUN_140b7f320(int n)
{
    int nState = 0;
    if (m_pOwner->vfunc_65() != 0)
        nState = 1;
    if (!m_pOwner->FUN_14166de90(nState, n))
    {
        m_pOwner->FUN_14166dda0(nState);
        m_pOwner->FUN_14166f8f0(0, 1);
    }
}

// @0x140b7f3b0
int StateBanner::FUN_140b7f3b0()
{
    if (m_spBannerData.get() != 0)
    {
        return m_spBannerData->m_nBanner;
    }
    return 0;
}

// @0x140b7f400
bool FUN_140b7f400(MyPC* pPlayer)
{
    return FUN_140b73bc0(pPlayer);
}

// @0x140b7f610
MS2Ptr<StateData> StateBanner::vfunc_27()
{
    return MS2Ptr<StateData>(new StateBannerData());
}

// @0x140b7f690
int StateBanner::vfunc_1()
{
    return 0x3b;
}

// The sequence id the banner's actor is playing, or NiActorManager's invalid id without an actor.
// @0x140b7f6a0
int FUN_140b7f6a0(void* pSvc, const egf::EntityID& kId)
{
    NiActorManager* pActor = FUN_140999440(pSvc, kId);
    if (pActor == 0)
        return (int)NiActorManager::INVALID_SEQUENCE_ID;
    return (int)FUN_1409a1a00(pActor);
}

// MS2-FUNCTIONAL: the UCRT's static __inline body differs in size (317 vs 319) and unwind codes; trailing unreferenced copy
// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
// MS2-PIN: memcpy_s 0x140b7f800
__declspec(selectany) extern errno_t(__cdecl* const ms2_memcpy_s)(void*, size_t, const void*, size_t) = &memcpy_s;

// The UCRT's `static __inline memmove_s` of this TU (unreferenced copy).
// @0x140b7f950
MS2_EMIT_CRT_MEMMOVE_S();
