// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ugcbannerobject.h.
// MS2-UNIT: ?\ugcbannerobject.cpp
// MS2-RANGE: 0x140b9c680-0x140b9c920 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugcbannerobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcbannerobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (the entity's banner component; names invented) ----
int FUN_140b60d90(egf::Entity *);  // C3: the definition's signature
bool FUN_140b60dd0(egf::Entity *);  // C3: the definition's signature
void FUN_140b60e10(egf::Entity *, bool);  // C3: the definition's signature
void FUN_140b60e40(egf::Entity *, bool);  // C3: the definition's signature

// @0x140b9c680
UgcBannerObject::UgcBannerObject(Unk_EntRef ent)
    : m_ent(ent)
{
    m_nBannerId = 0;
    m_bVisible = 0;
    Init();
}

// @0x140b9c710
UgcBannerObject::~UgcBannerObject()
{
}

// @0x140b9c750
unsigned int UgcBannerObject::GetBannerId() const
{
    return m_nBannerId;
}

// @0x140b9c770
void UgcBannerObject::SetVisible(unsigned char bVisible)
{
    if (m_bVisible == bVisible)
        return;
    m_bVisible = bVisible;
    FUN_140b60e10((egf::Entity *)(m_ent.FUN_1408a9090()), (bool&)m_bVisible);
    FUN_140b60e40((egf::Entity *)(m_ent.FUN_1408a9090()), (bool&)m_bVisible);
}

// @0x140b9c7f0
unsigned char UgcBannerObject::GetVisible() const
{
    return m_bVisible;
}

// @0x140b9c810
Unk_Entity* UgcBannerObject::GetEntity() const
{
    return m_ent.FUN_1408a9090();
}

// @0x140b9c840
void UgcBannerObject::Init()
{
    if (m_ent.FUN_1408b70b0(0))
        return;
    m_nBannerId = FUN_140b60d90((egf::Entity *)(m_ent.FUN_1408a9090()));
    m_bVisible = FUN_140b60dd0((egf::Entity *)(m_ent.FUN_1408a9090()));
    if (m_bVisible == 0)
        FUN_140b60e40((egf::Entity *)(m_ent.FUN_1408a9090()), (bool&)m_bVisible);
}
