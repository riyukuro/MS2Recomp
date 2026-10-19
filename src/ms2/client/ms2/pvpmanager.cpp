// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPVPManager, the PvP manager singleton: it owns a notice
// timer block, two entry tables and the rank-duel component, and forwards the server's PvP packets to them. The
// component bodies are in the neighbouring unit (0x141017950..0x14101f9d0). See pvpmanager.h.
// MS2-UNIT: ?\pvpmanager.cpp
// MS2-RANGE: 0x141280b40-0x141282440 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pvpmanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "pvpmanager.h"

#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------
// The local player actor (COM-style: AddRef slot 1, Release slot 2).
class Unk_PvpActor
{
public:
    virtual void vfunc_0(); virtual void AddRef(); virtual void Release();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    int FUN_14166ce30();                                            // the state (0: alive)
};
// The pointer to the actor: AddRef on copy, Release on destruction.
class Unk_PvpActorPtr
{
public:
    Unk_PvpActorPtr(Unk_PvpActor* lp) { p = lp; if (p != 0) p->AddRef(); }
    ~Unk_PvpActorPtr() { if (p != 0) p->Release(); }
    bool operator==(Unk_PvpActor* other) const { return p == other; }
    Unk_PvpActor* operator->() const { return p; }
    Unk_PvpActor* p;
};
Unk_PvpActor* FUN_141bd0cc0(void* pWorld);                          // the local player
void* FUN_1403ed2d0();                                              // the world
int FUN_141bd3060(void* pWorld);                                    // the current map id
CStringW FUN_14028de60(int nId);
void FUN_140d73aa0(CStringW text, int nA, int nB, CStringW tag);

// The arena table (0x14051a980 returns the record of a selection, MS2Ptr-style).
struct Unk_PvpRecord { char m_pad[0x30]; int m_nMapId; };
class Unk_PvpRecordPtr
{
public:
    ~Unk_PvpRecordPtr();                                            // 0x14051ae60
    bool operator==(__int64 value) const { return (__int64)m_p == value; }  // 0x1412816a0
    Unk_PvpRecord* operator->() const;                              // 0x14051afc0
    void* m_pad0;
    Unk_PvpRecord* m_p;
};
class Unk_PvpArenaTable { public: Unk_PvpRecordPtr FUN_14051a980(int nSelection); };
extern Unk_PvpArenaTable* DAT_143aaf098;

// @0x1412818c0
Unk_PvpArenaTable* FUN_1412818c0()
{
    return DAT_143aaf098;
}

// ---- CPVPManager --------------------------------------------------------------------------------------------------

// @0x141280b40
CPVPManager::CPVPManager()
{
    m_nState = 0;
    m_nSelection = 0;
}

// @0x141280be0
CPVPManager::~CPVPManager()
{
    Clear();
}

// @0x141280c60
void CPVPManager::Clear()
{
    m_timers.m_timer.FUN_141017e80();
    m_entries.FUN_14101b7f0();
}

// @0x141280ca0
void CPVPManager::ForwardToEntries(void* pArgument)
{
    m_entries.FUN_14101c0b0(pArgument);
}

// @0x141280cd0
void CPVPManager::OnMessage(int nMessage, CInPacket& packet)
{
    m_timers.m_timer.FUN_141017950(nMessage, packet);
    m_entries.FUN_14101b830(nMessage, packet);
    m_rankDuel.OnMessage(nMessage, packet);
}

// @0x141280d40
void CPVPManager::SendCancelRequest()
{
    switch (State())
    {
    case 2:
    {
        Unk_PvpActorPtr spActor(FUN_141bd0cc0(FUN_1403ed2d0()));
        if (spActor == 0)
            return;
        if (spActor->FUN_14166ce30() != 0)
        {
            FUN_140d73aa0(FUN_14028de60(0x42e), 0, 0, CStringW(L""));
            return;
        }
        Unk_PvpRecordPtr spRecord = FUN_1412818c0()->FUN_14051a980(Selection());
        if (spRecord == 0)
            return;
        if (spRecord->m_nMapId == FUN_141bd3060(FUN_1403ed2d0()))
        {
            FUN_140d73aa0(FUN_14028de60(0x42f), 0, 0, CStringW(L""));
            return;
        }
        COutPacket packet(0x61, 0);
        packet.vfunc_o10_1(0xb);
        FUN_140710590(packet);
    }
    }
}

// @0x141281610
// MS2-FUNCTIONAL: the exe's block destructor has no EH table although the timer destructor (try/catch(...), not noexcept)
// is called from it; cl 19.16 emits a noexcept FuncInfo here, and the base TSingleton forces the noexcept chain
Unk_PvpTimerBlock::~Unk_PvpTimerBlock() noexcept
{
}

// ---- timer helper -------------------------------------------------------------------------------------------------

// @0x1412818f0
void Unk_PvpTimer::FUN_1412818f0(float fA, float fB, float fC, bool bApply)
{
    m_fA = fA;
    m_fB = fB;
    m_fC = fC;
    FUN_14101af70();
    if (bApply && (m_8 > m_20 || m_8 < m_28))
        FUN_14101a9f0(FUN_14101a900(m_8));
}
