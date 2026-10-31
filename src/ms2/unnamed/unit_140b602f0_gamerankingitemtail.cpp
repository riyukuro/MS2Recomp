// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tail of the ranking item obj (?\gamerankingcli.cpp): the MS2Ptr<T>
// Release/ReleaseImpl instantiations of the GameRankingItem rows, then a few entity property helpers (the first real
// functions after the template COMDATs) and this obj's CRT memmove_s copy. Names invented.
// MS2-UNIT: unit_140b602f0
// MS2-RANGE: 0x140b602f0-0x140b60ff0 .text$mn
#define NOMINMAX
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <egf/Entity.h>
#include <efd/utf8string.h>
#include <efd/Point3.h>
#include "ms2/client/ms2/gamerankingcli.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

template void MS2Ptr<GameRankingItem::Arcade>::Release();
template void MS2Ptr<GameRankingItem::BossColosseum>::Release();
template void MS2Ptr<GameRankingItem::BossDamageAmount>::Release();
template void MS2Ptr<GameRankingItem::BossDamageCount>::Release();
template void MS2Ptr<GameRankingItem::BossDamageDate>::Release();
template void MS2Ptr<GameRankingItem::BossKillCount>::Release();
template void MS2Ptr<GameRankingItem::BossKillRecord>::Release();
template void MS2Ptr<GameRankingItem::BossRumbleCount>::Release();
template void MS2Ptr<GameRankingItem::BossRumbleRecord>::Release();
template void MS2Ptr<GameRankingItem::DarkStream>::Release();
template void MS2Ptr<GameRankingItem::GuildPvp>::Release();
template void MS2Ptr<GameRankingItem::GuildTrophy>::Release();
template void MS2Ptr<GameRankingItem::UgcMapCommendation>::Release();
template void MS2Ptr<GameRankingItem::UserPvp>::Release();
template void MS2Ptr<GameRankingItem::UserTrophy>::Release();
template void MS2Ptr<GameRankingItem::WorldChampion>::Release();

template void MS2Ptr<GameRankingItem::Arcade>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::BossColosseum>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::BossDamageAmount>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::BossDamageCount>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::BossDamageDate>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::BossKillCount>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::BossKillRecord>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::BossRumbleCount>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::BossRumbleRecord>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::DarkStream>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::GuildPvp>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::GuildTrophy>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::UgcMapCommendation>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::UserPvp>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::UserTrophy>::ReleaseImpl(void*);
template void MS2Ptr<GameRankingItem::WorldChampion>::ReleaseImpl(void*);

void FUN_1408a2020(egf::Entity* pEntity, unsigned nProperty, int* pOut);
int FUN_1408a2060(egf::Entity* pEntity, unsigned nProperty, efd::utf8string* pOut);
void FUN_1408a20a0(egf::Entity* pEntity, unsigned nProperty, bool* pOut);
void FUN_140961880(egf::Entity* pEntity, unsigned nProperty, float* pOut);
void FUN_1409618c0(egf::Entity* pEntity, unsigned nProperty, efd::Point3* pOut);
void FUN_14098c6e0(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0
void FUN_140ae1160(egf::Entity* pEntity, unsigned nProperty, unsigned short* pOut);
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0

// @0x140b60bf0
CString FUN_140b60bf0(egf::Entity* pEntity)
{
    efd::utf8string str;
    FUN_1408a2060(pEntity, 0xdd2ac78a, &str);
    return CString(str.c_str());
}

// @0x140b60c90
float FUN_140b60c90(egf::Entity* pEntity)
{
    float fValue = 1.0f;
    FUN_140961880(pEntity, 0x2d7cad2d, &fValue);
    return fValue;
}

// @0x140b60cd0
efd::Point3 FUN_140b60cd0(egf::Entity* pEntity)
{
    efd::Point3 kPoint;
    FUN_1409618c0(pEntity, 0xfd95ca52, &kPoint);
    return kPoint;
}

// @0x140b60d30
efd::Point3 FUN_140b60d30(egf::Entity* pEntity)
{
    efd::Point3 kPoint;
    FUN_1409618c0(pEntity, 0x68c7c29d, &kPoint);
    return kPoint;
}

// @0x140b60d90
int FUN_140b60d90(egf::Entity* pEntity)
{
    int nValue = 0;
    FUN_1408a2020(pEntity, 0x819a96c0, &nValue);
    return nValue;
}

// @0x140b60dd0
bool FUN_140b60dd0(egf::Entity* pEntity)
{
    bool bValue = false;
    FUN_1408a20a0(pEntity, 0xa0b6b179, &bValue);
    return bValue;
}

// @0x140b60e10
void FUN_140b60e10(egf::Entity* pEntity, bool bValue)
{
    FUN_14098c6e0((class Unk_CachedEntity*)(pEntity), 0xa0b6b179, *(bool const*)(&bValue));
}

// @0x140b60e40
void FUN_140b60e40(egf::Entity* pEntity, bool bDefault)
{
    if (((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689a10(pEntity) == 0)
        return;
    unsigned short usKind = 0;
    FUN_140ae1160(pEntity, 0xada5c5d2, &usKind);
    unsigned short usGroup;
    if (bDefault)
        usGroup = usKind;
    else
        usGroup = 5;
    ((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(pEntity, usGroup, 0, 1);
}

// @0x140b60ed0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
