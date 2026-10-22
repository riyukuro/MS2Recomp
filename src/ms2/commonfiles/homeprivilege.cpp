// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CHomePrivilege: what the local player may use in the house
// he stands in; the lists come from the house's Unk_UGCGroup row.
// MS2-UNIT: ?\homeprivilege.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x14050d4c0-0x14050e140 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\homeprivilege.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/userugcmapinfo.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/commonfiles/ugcmapdata.h"
#include "hook/ms2hook.h"

// The world manager singleton: the current map id.
class Unk_HpWorld { public: int FUN_141bd3060(); };
Unk_HpWorld* FUN_1403ed2d0();
int FUN_1408a0d30(int nGroup, Unk_UGCGroup& rResult, int nMapId);

// @0x14050d4c0
CHomePrivilege::CHomePrivilege()
{
}

// @0x14050d500
CHomePrivilege::~CHomePrivilege()
{
}

// @0x14050d530
void CHomePrivilege::SetOwner(MyPC* pOwner)
{
    m_pOwner = pOwner;
}
MS2_REPLACE_METHOD(0x14050d530, CHomePrivilege, SetOwner, 25, 0xAB8BF0FB);

// @0x14050d550
int CHomePrivilege::FUN_14050d550(int nNpcId)
{
    if (m_pOwner == 0)
        return 0;
    if (m_pOwner->FUN_141527e00() == 0)
    {
        Unk_BmPtr<UserUGCMapInfo> spHouse(m_pOwner->FUN_141523c50());
        if (spHouse->m_n20 != FUN_1403ed2d0()->FUN_141bd3060())
            return 0;
        Unk_UGCGroup group;
        if (FUN_1408a0d30(spHouse->m_n24, group, spHouse->m_n20) != 0)
        {
            std::vector<unsigned> aNpcs(group.privilegeNPC);
            for (size_t i = 0; i < aNpcs.size(); i++)
            {
                if (aNpcs[i] == nNpcId)
                    return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14050d550, CHomePrivilege, FUN_14050d550, 410, 0x6ADA6698);

// @0x14050d6f0
int CHomePrivilege::FUN_14050d6f0(int nPortalId)
{
    if (m_pOwner == 0)
        return 0;
    if (m_pOwner->FUN_141527e00() == 0)
    {
        Unk_BmPtr<UserUGCMapInfo> spHouse(m_pOwner->FUN_141523c50());
        if (spHouse->m_n20 != FUN_1403ed2d0()->FUN_141bd3060())
            return 0;
        Unk_UGCGroup group;
        if (FUN_1408a0d30(spHouse->m_n24, group, spHouse->m_n20) != 0)
        {
            std::vector<int> aPortals(group.privilegePortal);
            for (size_t i = 0; i < aPortals.size(); i++)
            {
                if (aPortals[i] == nPortalId)
                    return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14050d6f0, CHomePrivilege, FUN_14050d6f0, 410, 0x90A315DC);

// @0x14050d890
int CHomePrivilege::FUN_14050d890(int nInteractId)
{
    if (m_pOwner == 0)
        return 0;
    if (m_pOwner->FUN_141527e00() == 0)
    {
        Unk_BmPtr<UserUGCMapInfo> spHouse(m_pOwner->FUN_141523c50());
        if (spHouse->m_n20 != FUN_1403ed2d0()->FUN_141bd3060())
            return 0;
        Unk_UGCGroup group;
        if (FUN_1408a0d30(spHouse->m_n24, group, spHouse->m_n20) != 0)
        {
            std::vector<int> aInteracts(group.privilegeInteract);
            for (size_t i = 0; i < aInteracts.size(); i++)
            {
                if (aInteracts[i] == nInteractId)
                    return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14050d890, CHomePrivilege, FUN_14050d890, 410, 0x14278398);

// @0x14050da30
int CHomePrivilege::FUN_14050da30()
{
    if (m_pOwner == 0)
        return 0;
    if (m_pOwner->FUN_141527e00() == 0)
    {
        Unk_BmPtr<UserUGCMapInfo> spHouse(m_pOwner->FUN_141523c50());
        if (spHouse->m_n20 != FUN_1403ed2d0()->FUN_141bd3060())
            return 0;
        Unk_UGCGroup group;
        if (FUN_1408a0d30(spHouse->m_n24, group, spHouse->m_n20) != 0)
            return group.privilegeTaxi;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14050da30, CHomePrivilege, FUN_14050da30, 292, 0xF923D869);
