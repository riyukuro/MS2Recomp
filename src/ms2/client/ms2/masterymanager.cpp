// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMasteryManager: the mastery learning rules.
// MS2-UNIT: ?\masterymanager.cpp
// MS2-RANGE: 0x140b6d070-0x140b6df50 .text$mn
// MS2-RANGE: 0x1400c85c0-0x1400c87f0 .text$di
// MS2-PIN: ??$?0W4Unk_MasteryResult@@$0A@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@AEBW4Unk_MasteryResult@@@Z 0x140b6daf0
// MS2-PIN: ??$format_arg@_WW4Unk_MasteryResult@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_MasteryResult@@@Z 0x140b6dbd0
// MS2-PIN: ??$FormatCustomArg@W4Unk_MasteryResult@@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@SAXPEAXPEBX0@Z 0x140b6dcf0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\masterymanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cmasterymanager.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemgift.h"
#include <atlcoll.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/masterytable.h"
#include "ms2/placeholder/cquestmanagercommon.h"   // C3: CQuestManagerCommon::IsQuestActive
#include "ms2/client/ms2/inventory.h"   // C3: Unk_Inventory::FUN_140a5f180

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// The string-key formatter with one enum argument (the argument rides the formatter customization path).
template <class A> CStringW Unk_MmFormat(CStringW strKey, const A& x)
{
    const fmt::internal::ArgArray<1>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x)};
    return FUN_14028dfa0(strKey, fmt::ArgList(fmt::internal::make_type(x), values));
}

// ---- unit-local views of the exe objects --------------------------------------------------------------------------

// The local player.
class Unk_MmPlayer : public PC
{
};
class Unk_MmWorld { };

// The mastery table (singleton).
typedef ATL::CAtlArray<MS2Ptr<ItemEntity> > Unk_MmItemArray;   // reward lists hold item pointers (CMasteryTable::Rewards)

class Unk_MmTable : public CMasteryTable
{
};
class Unk_MData* FUN_1409670c0();   // C3: was FUN_1409670c0

// The learned steps (global 0x143ab31a0), the inventory (0x143ab2a90) and the meso (0x143ab2898).
extern ATL::CAtlMap<unsigned int, int> DAT_143ab31a0;   // scenestategame.cpp
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90)
extern __int64 DAT_143ab2898;

class Unk_MmQuests { };
class Unk_MmQuestMgr
{
public:
    char m_pad[0x10];
    Unk_MmQuests m_10;
};
void* FUN_140764020();   // C3: was FUN_140764020

CStringW GetStringCommonByKey(const CStringW& str);
void ShowSystemNotice(const CStringW& str, int nA, int nB);

// @0x140b6d070
CMasteryManager::CMasteryManager()
{
}

// @0x140b6d0b0
CMasteryManager::~CMasteryManager()
{
}

// @0x140b6d0e0
int CMasteryManager::GetTotalClaimableRewardLevels()
{
    int nTotal = 0;
    for (size_t i = 0; i < 0xc; i++)
        nTotal += CountClaimableRewardLevels((int)i);
    return nTotal;
}

// @0x140b6d140
int CMasteryManager::CountClaimableRewardLevels(int nType)
{
    Unk_MmPlayer* pPlayer = ((class Unk_MmPlayer*)((class WorldService*)(class Unk_MmWorld*)(reinterpret_cast<Unk_MmWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    unsigned int nExp = pPlayer->GetMastery(nType);
    int nMax = ((class Unk_MmTable*)FUN_1409670c0())->MaxGrade(nType);
    int nCount = 0;
    for (int nLevel = 1; nLevel <= nMax; nLevel++)
    {
        unsigned int nNeed = ((class Unk_MmTable*)FUN_1409670c0())->Value(nType, nLevel);
        if (nExp < nNeed)
            break;
        int nStep = ((class Unk_MmTable*)FUN_1409670c0())->MakeID(nType, nLevel);
        if (DAT_143ab31a0.Lookup(nStep) != 0)
            continue;
        if (HasRewards(nType, nLevel) == 0)
            continue;
        nCount++;
    }
    return nCount;
}

// @0x140b6d250
int CMasteryManager::HasRewards(int nType, int nLevel)
{
    Unk_MmPlayer* pPlayer = ((class Unk_MmPlayer*)((class WorldService*)(class Unk_MmWorld*)(reinterpret_cast<Unk_MmWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    int nStep = ((class Unk_MmTable*)FUN_1409670c0())->MakeID(nType, nLevel);
    Unk_MmItemArray rewards;
    ((class Unk_MmTable*)FUN_1409670c0())->Rewards(nStep, pPlayer->GetJobGroupId(), rewards);
    return rewards.GetCount() != 0 ? 1 : 0;
}

// @0x140b6d330
int CMasteryManager::FUN_140b6d330(int nStep)
{
    MS2Ptr<CMasteryReceipe> spRow = ((class Unk_MmTable*)FUN_1409670c0())->Find(nStep);
    if (!spRow)
        return 0;
    if (spRow->m_requireQuest.GetCount() == 0)
        return 1;
    for (size_t i = 0; i < spRow->m_requireQuest.GetCount(); i++)
    {
        if (reinterpret_cast<CQuestManagerCommon*>(&((class Unk_MmQuestMgr*)FUN_140764020())->m_10)->IsQuestActive(spRow->m_requireQuest[i]) != 0)
            return 1;
    }
    return 0;
}

// @0x140b6d470
Unk_MasteryResult CMasteryManager::FUN_140b6d470(int nStep)
{
    Unk_MmPlayer* pPlayer = ((class Unk_MmPlayer*)((class WorldService*)(class Unk_MmWorld*)(reinterpret_cast<Unk_MmWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return (Unk_MasteryResult)5;
    MS2Ptr<CMasteryReceipe> spRow = ((class Unk_MmTable*)FUN_1409670c0())->Find(nStep);
    if (spRow.get() != 0)
    {
        int nType = spRow->m_nType;
        if (spRow->m_nRequireMastery != 0)
        {
            if (pPlayer->GetMastery(nType) < spRow->m_nRequireMastery)
                return (Unk_MasteryResult)1;
        }
        if (FUN_140b6d330(nStep) == 0)
            return (Unk_MasteryResult)3;
        if (spRow->m_nRequireMeso != 0 && DAT_143ab2898 < spRow->m_nRequireMeso)
            return (Unk_MasteryResult)2;
        for (size_t i = 0; i < spRow->m_ingredients.FUN_14026bee0(); i++)
        {
            Unk_IngRef spCost = spRow->m_ingredients.FUN_14026bdc0(i);
            if (spCost->m_b != 0)
            {
                if (g_143ab2a90.GetItemCountByTag(spCost->m_b, 0) < spCost->m_c)
                    return (Unk_MasteryResult)4;
            }
            else
            {
                if (g_143ab2a90.FUN_140a5f180(spCost->GetItemId(), 0) < spCost->m_c)
                    return (Unk_MasteryResult)4;
            }
        }
    }
    return (Unk_MasteryResult)0;
}

// @0x140b6d710
void CMasteryManager::FUN_140b6d710(Unk_MasteryResult eResult)
{
    CStringW strText;
    switch (eResult)
    {
    case 1:
        strText = GetStringCommonByKey(L"s_mastery_error_lack_mastery");
        break;
    case 2:
        strText = GetStringCommonByKey(L"s_mastery_error_lack_meso");
        break;
    case 3:
        strText = GetStringCommonByKey(L"s_mastery_error_lack_quest");
        break;
    case 4:
        strText = GetStringCommonByKey(L"s_mastery_error_lack_item");
        break;
    case 0xc:
        strText = GetStringCommonByKey(L"s_anti_addiction_cannot_receive");
        break;
    case 7:
        strText = Unk_MmFormat(L"s_mastery_error_invalid_level", eResult);
        break;
    case 5:
        strText = Unk_MmFormat(L"s_mastery_error_unknown", eResult);
        break;
    }
    ShowSystemNotice(strText, 1, 1);
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x140B6D0E0, CMasteryManager, GetTotalClaimableRewardLevels, 86, 0x3C2C797F);
MS2_REPLACE_METHOD(0x140B6D140, CMasteryManager, CountClaimableRewardLevels, 266, 0x0B05C086);
MS2_REPLACE_METHOD(0x140B6D250, CMasteryManager, HasRewards, 203, 0x95812AFB);
MS2_REPLACE_METHOD(0x140B6D330, CMasteryManager, FUN_140b6d330, 310, 0xC4E143C1);
MS2_REPLACE_METHOD(0x140B6D470, CMasteryManager, FUN_140b6d470, 657, 0xED84B747);
MS2_REPLACE_METHOD(0x140B6D710, CMasteryManager, FUN_140b6d710, 936, 0xE616FB85);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca0d50-0x142ca0e10 .text$yd
