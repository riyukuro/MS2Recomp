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
#include "ms2/client/ms2/individualarenadata.h"
#include "ms2/client/ms2/pcbase.h"

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
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
public:
    static class WorldService* GetInstance();   // C3: was free FUN_1403ed2d0
public:
    int FUN_141bd3060();   // C3: was free FUN_141bd3060
};
CStringW GetStringCommon(int nId);
void FUN_140d73aa0(CStringW text, int nA, void* pB, CStringW tag);

// The arena table (CIndividualArenaDataTable, the TSingleton instance).
class Unk_PvpArenaTable;
class CIndividualArenaDataTable;

// @0x1412818c0
Unk_PvpArenaTable* FUN_1412818c0()
{
    return reinterpret_cast<Unk_PvpArenaTable*>(TSingleton<CIndividualArenaDataTable>::s_instance);
}

// ---- CPVPManager --------------------------------------------------------------------------------------------------

// @0x141280b40
CPVPManager::CPVPManager()
{
    m_nState = 0;
    m_nSelection = 0;
}

// @0x141280be0
CPVPManager::~CPVPManager() noexcept
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
        Unk_PvpActorPtr spActor(((class Unk_PvpActor*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0()));
        if (spActor == 0)
            return;
        if (reinterpret_cast<PCBase*>(spActor.operator->())->IsDead() != 0)
        {
            FUN_140d73aa0(GetStringCommon(0x42e), 0, 0, CStringW(L""));
            return;
        }
        CIndividualArenaDataTable::DataPtr spRecord = reinterpret_cast<CIndividualArenaDataTable*>(FUN_1412818c0())->GetData(Selection());
        if (spRecord == 0)
            return;
        if (spRecord->m_nFieldID == ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd3060())
        {
            FUN_140d73aa0(GetStringCommon(0x42f), 0, 0, CStringW(L""));
            return;
        }
        COutPacket packet(static_cast<int>(SendOp::Pvp), 0);
        packet.WriteUInt8(0xb);
        FUN_140710590(packet);
    }
    }
}

// @0x141281610
Unk_PvpTimerBlock::~Unk_PvpTimerBlock()
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
        reinterpret_cast<ATL::CAtlMap<unsigned __int64, int>&>(*this).Rehash(FUN_14101a900(m_8));
}
