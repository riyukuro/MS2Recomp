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
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read

// ---- unit-local views of exe objects ----

// C3: the float getter 0x140298f40 is Common::Constants::Value<float>::Get() (clientconstants.h)
// The client constants table (FUN_1401d3200). Each value is a 0x58-byte record.
class Unk_AuCfgValue
{
public:
    char m_pad[0x58];
};
struct Unk_AuConfig
{
    char m_pad[0xa58];
    Unk_AuCfgValue m_kUpdateRate;       // +0xa58 mesh update passes per second
    Unk_AuCfgValue m_kUpdateDuration;   // +0xab0
};
MS2_CHECK_OFFSET(Unk_AuConfig, m_kUpdateDuration, 0xab0);
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
void* FUN_14123ed90(CMeshUpdateGate* pGate, unsigned int nFlags) throw();

// Property access on the entity (hash id, value).
class Unk_AuEntity
{
public:
};

// @0x1414a8240
MS2ActorUpdater::MS2ActorUpdater(egf::EntityID kId)
    : m_kId(kId), m_fDistA(0.0f), m_fDistB(0.0f)
{
    m_pGate = new CMeshUpdateGate;
    float fRate = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_AuConfig*)GetClientConstants())->m_kUpdateRate)->Read();
    if (fRate <= 0.0f)
        fRate = 60.0f;
    ((class CMeshUpdateGate*)(class CMeshUpdateGate*)(m_pGate))->SetUpdateInterval(1.0f / fRate);
    m_pGate->SetUpdateDuration(reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_AuConfig*)GetClientConstants())->m_kUpdateDuration)->Read());
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
float MS2ActorUpdater::UpdateDistB(const Vector3& kPos)
{
    Vector3 kEntityPos(0.0f, 0.0f, 0.0f);
    egf::EntityPtr spEntity(TSingleton<EntityWorldManager>::GetInstance()->FindEntity(m_kId));
    if ((egf::Entity*)spEntity != 0)
        reinterpret_cast<egf::Entity*>(((Unk_AuEntity*)spEntity.operator->()))->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(kEntityPos));
    m_fDistB = (kPos - kEntityPos).Length();
    return m_fDistB;
}

// @0x1414a84f0
float MS2ActorUpdater::UpdateDistA(const Vector3& kPos)
{
    Vector3 kEntityPos(0.0f, 0.0f, 0.0f);
    egf::EntityPtr spEntity(TSingleton<EntityWorldManager>::GetInstance()->FindEntity(m_kId));
    if ((egf::Entity*)spEntity != 0)
        reinterpret_cast<egf::Entity*>(((Unk_AuEntity*)spEntity.operator->()))->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(kEntityPos));
    m_fDistA = (kPos - kEntityPos).Length();
    return m_fDistA;
}

// @0x1414a85d0
void MS2ActorUpdater::FUN_1414a85d0(float fInterval)
{
    int nMode = WorldService::GetInstance()->FUN_141bdb5c0();
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
        fDuration = GetDistB() - *reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_AuConfig*)GetClientConstants())->m_kUpdateDuration)->Get();
        break;
    default:
        MS2_ASSERT_AT(0x31, FALSE);
    }
    egf::EntityPtr spEntity(TSingleton<EntityWorldManager>::GetInstance()->FindEntity(m_kId));
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
