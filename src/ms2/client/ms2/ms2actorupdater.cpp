// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ms2actorupdater.h.
// MS2-UNIT: client\ms2\ms2actorupdater.cpp
// MS2-RANGE: 0x1414a8240-0x1414a8770 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2actorupdater.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2actorupdater.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// The client constants table (FUN_1401d3200). Each value is a 0x58-byte record.
class Unk_AuCfgValue
{
public:
    float FUN_1402bac70();
    const float& FUN_140298f40();
    char m_pad[0x58];
};
struct Unk_AuConfig
{
    char m_pad[0xa58];
    Unk_AuCfgValue m_kUpdateRate;       // +0xa58 mesh update passes per second
    Unk_AuCfgValue m_kUpdateDuration;   // +0xab0
};
MS2_CHECK_OFFSET(Unk_AuConfig, m_kUpdateDuration, 0xab0);
Unk_AuConfig* FUN_1401d3200();
void FUN_14108c240(CMeshUpdateGate* pGate, float fInterval);
void* FUN_14123ed90(CMeshUpdateGate* pGate, unsigned int nFlags) throw();

// The world service (FUN_1403ed2d0); only the update mode is read here.
class Unk_AuWorld
{
public:
    int FUN_141bdb5c0();
};
Unk_AuWorld* FUN_1403ed2d0();

// Property access on the entity (hash id, value).
class Unk_AuEntity
{
public:
    void FUN_1409618c0(unsigned nProp, Unk_StreamPoint* pOut);          // get a point property
};
EntityWorldManager* FUN_1409670f0();

// @0x1414a8240
MS2ActorUpdater::MS2ActorUpdater(const egf::EntityID& kId)
    : m_kId(kId), m_fDistA(0.0f), m_fDistB(0.0f)
{
    m_pGate = new CMeshUpdateGate;
    float fRate = FUN_1401d3200()->m_kUpdateRate.FUN_1402bac70();
    if (fRate <= 0.0f)
        fRate = 60.0f;
    FUN_14108c240(m_pGate, 1.0f / fRate);
    m_pGate->FUN_14123ef30(FUN_1401d3200()->m_kUpdateDuration.FUN_1402bac70());
}

// @0x1414a8380
MS2ActorUpdater::~MS2ActorUpdater()
{
    if (m_pGate)
    {
        CMeshUpdateGate* pTmp = m_pGate;
        CMeshUpdateGate* pGate = pTmp;
        pGate ? FUN_14123ed90(pGate, 1) : 0;
        m_pGate = 0;
    }
}

// @0x1414a8410
float MS2ActorUpdater::FUN_1414a8410(const Unk_StreamPoint& kPos)
{
    Unk_StreamPoint kEntityPos(0.0f, 0.0f, 0.0f);
    egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(m_kId));
    if ((egf::Entity*)spEntity != 0)
        ((Unk_AuEntity*)spEntity.operator->())->FUN_1409618c0(0xfd95ca52, &kEntityPos);
    m_fDistB = kPos.FUN_140965c40(kEntityPos).FUN_140967ac0();
    return m_fDistB;
}

// @0x1414a84f0
float MS2ActorUpdater::FUN_1414a84f0(const Unk_StreamPoint& kPos)
{
    Unk_StreamPoint kEntityPos(0.0f, 0.0f, 0.0f);
    egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(m_kId));
    if ((egf::Entity*)spEntity != 0)
        ((Unk_AuEntity*)spEntity.operator->())->FUN_1409618c0(0xfd95ca52, &kEntityPos);
    m_fDistA = kPos.FUN_140965c40(kEntityPos).FUN_140967ac0();
    return m_fDistA;
}

// @0x1414a85d0
void MS2ActorUpdater::FUN_1414a85d0(float fInterval)
{
    int nMode = FUN_1403ed2d0()->FUN_141bdb5c0();
    float fDuration = 0.0f;
    switch (nMode)
    {
    case 0:
        fDuration = GetDistA();
        break;
    case 1:
        fDuration = GetDistB();
        break;
    case 2:
        fDuration = GetDistB() - FUN_1401d3200()->m_kUpdateDuration.FUN_140298f40();
        break;
    default:
        MS2_ASSERT_AT(0x31, FALSE);
    }
    egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(m_kId));
    m_pGate->FUN_14176f500(spEntity, fInterval, fDuration);
}

// @0x1414a8750
float MS2ActorUpdater::GetDistB() const
{
    return m_fDistB;
}

// @0x1414a8760
float MS2ActorUpdater::GetDistA() const
{
    return m_fDistA;
}
