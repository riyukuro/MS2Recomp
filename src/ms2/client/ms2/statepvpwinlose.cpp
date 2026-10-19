// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StatePvPWinLose, the actor state that plays the PvP
// win/lose motion: the enter hook reads the player's team-info value, builds the motion name for the animation slot
// the sub-type selects (0x41 for 0x73, 0x40 for 0x74) and plays it; the state leaves when that sequence ends.
// See statepvpwinlose.h.
// MS2-UNIT: ?\statepvpwinlose.cpp
// MS2-RANGE: 0x141282440-0x141282a50 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statepvpwinlose.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <string.h>

#include "statepvpwinlose.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The player's team-info proxy (PC method 0x140967420; uinametag.cpp reads the team id at +0x18 of the same entry,
// this state reads the value at +0x1c). The proxy's operator-> is 0x140965970, its release 0x140964aa0.
struct Unk_PvPTeam
{
    char m_pad_00[0x1c];
    int m_nValue;                                           // +0x1c
};
class Unk_PvPTeamPtr
{
public:
    ~Unk_PvPTeamPtr() { FUN_140964aa0(); }
    Unk_PvPTeam* FUN_140965970() const;                     // operator->
    void FUN_140964aa0();                                   // release
    void* m_pad_00;
    Unk_PvPTeam* m_p;
};
struct Unk_PwlTeamOwner { Unk_PvPTeamPtr FUN_140967420(); }; // 0x140967420 the player's team-info proxy

// Build the animation name of slot nSlot for the value nId, looked up in the owner's +0xd00 name table.
struct Unk_PwlAnimOwner { efd::utf8string FUN_141679170(int nSlot, int nId); }; // 0x141679170

// @0x141282440
StatePvPWinLose::StatePvPWinLose(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x141282490
StatePvPWinLose::~StatePvPWinLose()
{
}

// @0x1412824c0
// MS2-FUNCTIONAL: the animation-name temporaries differ from the exe
void StatePvPWinLose::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    int nId = 0;
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        Unk_PvPTeamPtr kTeam = reinterpret_cast<Unk_PwlTeamOwner*>(pPC)->FUN_140967420();
        nId = kTeam.FUN_140965970()->m_nValue;
    }
    if (m_n10 == 0x73)
    {
        efd::utf8string kAnim = reinterpret_cast<Unk_PwlAnimOwner*>(m_pOwner)->FUN_141679170(0x41, nId);
        m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
    }
    else if (m_n10 == 0x74)
    {
        efd::utf8string kAnim = reinterpret_cast<Unk_PwlAnimOwner*>(m_pOwner)->FUN_141679170(0x40, nId);
        m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
    }
}

// @0x141282670
// MS2-FUNCTIONAL: the zero point is copied byte-wise in the exe
void StatePvPWinLose::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    efd::Point3 kMove = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1412826f0
void StatePvPWinLose::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_pOwner->FUN_14166de90(0x41, eSequenceID) || m_pOwner->FUN_14166de90(0x40, eSequenceID))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1412827c0
int StatePvPWinLose::vfunc_15()
{
    return 1;
}

// @0x1412827d0
int StatePvPWinLose::vfunc_1()
{
    return 0x28;
}

// ---- the unreferenced CRT copies of this TU -----------------------------------------------------------------------

// The UCRT's header-inline memcpy_s of this TU, kept alive through the pointer below.
#pragma function(memset, memcpy)
// @0x1412827e0
static __inline errno_t ms2_pvpwinlose_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnPvpWinLoseMemcpyS)(void*, size_t, const void*, size_t) =
    &ms2_pvpwinlose_memcpy_s;
#pragma intrinsic(memset, memcpy)

// The UCRT's static-inline memmove_s copy of this TU (0x141282930).
MS2_EMIT_CRT_MEMMOVE_S();
