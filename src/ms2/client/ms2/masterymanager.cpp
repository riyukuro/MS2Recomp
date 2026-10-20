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
#include <atlcoll.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// The string-key formatter with one enum argument (the argument rides the formatter customization path).
template <class A> CStringW Unk_MmFormat(CStringW strKey, const A& x)
{
    const fmt::internal::ArgArray<1>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x)};
    return FUN_14028dfa0(strKey, fmt::ArgList(fmt::internal::make_type(x), values));
}

// ---- unit-local views of the exe objects --------------------------------------------------------------------------

// The local player.
class Unk_MmPlayer
{
public:
    unsigned int FUN_141662750(int nType);                  // the mastery exp of the type
    int FUN_141654700();                                    // the job
};
class Unk_MmWorld { };
Unk_MmWorld* FUN_1403ed2d0();
Unk_MmPlayer* FUN_141bd0cc0(Unk_MmWorld* pWorld);

// A cost entry of a mastery step: +0x1c kind (0 = item, else an item class), +0x20 count.
class Unk_MmCost : public CPtred
{
public:
    char m_pad_18[4];
    int m_nKind;                                            // +0x1c
    int m_nCount;                                           // +0x20
    unsigned int FUN_14026b500();                           // the item id
};
class Unk_MmCostList
{
public:
    size_t FUN_14026bee0();                                 // count
    MS2Ptr<Unk_MmCost> FUN_14026bdc0(size_t nIndex);        // the nIndex-th entry
    char m_pad[0x18];
};
class Unk_MmIds
{
public:
    size_t FUN_140186270();                                 // count
    unsigned int* FUN_140184510(size_t nIndex);             // operator[]
    char m_pad[0x18];
};

// A step row of the mastery table.
class Unk_MmRow : public CPtred
{
public:
    char m_pad_18[4];
    int m_nType;                                            // +0x1c
    char m_pad_20[4];
    unsigned int m_nNeedExp;                                // +0x24
    __int64 m_nNeedMeso;                                    // +0x28
    Unk_MmIds m_ids;                                        // +0x30 quest ids (any of them completed)
    char m_pad_48[8];
    Unk_MmCostList m_costs;                                 // +0x50
};

// The mastery table (singleton).
class Unk_MmTable
{
public:
    MS2Ptr<Unk_MmRow> FUN_14066aa00(int nStep);             // the row of a step
    int FUN_14066b050(int nType);                           // number of levels of the type
    unsigned int FUN_14066b310(int nType, int nLevel);      // exp needed
    int FUN_14066b500(int nType, int nLevel);               // step id
    void FUN_14066b100(int nStep, int nJob, ATL::CAtlArray<void*>& rOut);   // rewards of the step
};
Unk_MmTable* FUN_1409670c0();

// The learned steps (global 0x143ab31a0), the inventory (0x143ab2a90) and the meso (0x143ab2898).
class Unk_MmLearned { public: void* FUN_140167ca0(int nStep); };
extern Unk_MmLearned DAT_143ab31a0;
class Unk_MmInventory
{
public:
    int FUN_140a5f180(int nItemId, int n);                  // count of an item id
    int FUN_140a5f780(int nKind, int n);                    // count of an item class
};
extern Unk_MmInventory DAT_143ab2a90;
extern __int64 DAT_143ab2898;

class Unk_MmQuests { public: int FUN_140745630(unsigned int nQuestId); };
class Unk_MmQuestMgr
{
public:
    char m_pad[0x10];
    Unk_MmQuests m_10;
};
Unk_MmQuestMgr* FUN_140764020();

void* FUN_140665850(ATL::CAtlArray<void*>& rArr);           // the data pointer of the reward list
CStringW FUN_14028b8e0(const CStringW& str);
void FUN_1412751f0(const CStringW& str, int nA, int nB);

// @0x140b6d070
CMasteryManager::CMasteryManager()
{
}

// @0x140b6d0b0
CMasteryManager::~CMasteryManager()
{
}

// @0x140b6d0e0
int CMasteryManager::FUN_140b6d0e0()
{
    int nTotal = 0;
    for (size_t i = 0; i < 0xc; i++)
        nTotal += FUN_140b6d140((int)i);
    return nTotal;
}

// MS2-FUNCTIONAL: frame / loop-continue layout differs from the exe (same calls and branches)
// @0x140b6d140
int CMasteryManager::FUN_140b6d140(int nType)
{
    Unk_MmPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    unsigned int nExp = pPlayer->FUN_141662750(nType);
    int nMax = FUN_1409670c0()->FUN_14066b050(nType);
    int nCount = 0;
    for (int nLevel = 1; nLevel <= nMax; nLevel++)
    {
        unsigned int nNeed = FUN_1409670c0()->FUN_14066b310(nType, nLevel);
        if (nExp < nNeed)
            return nCount;
        int nStep = FUN_1409670c0()->FUN_14066b500(nType, nLevel);
        if (DAT_143ab31a0.FUN_140167ca0(nStep) == 0 && FUN_140b6d250(nType, nLevel) != 0)
            nCount++;
    }
    return nCount;
}

// MS2-FUNCTIONAL: frame slots of the step / job locals differ from the exe
// @0x140b6d250
int CMasteryManager::FUN_140b6d250(int nType, int nLevel)
{
    Unk_MmPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    int nStep = FUN_1409670c0()->FUN_14066b500(nType, nLevel);
    ATL::CAtlArray<void*> rewards;
    int nJob = pPlayer->FUN_141654700();
    FUN_1409670c0()->FUN_14066b100(nStep, nJob, rewards);
    int bHas = FUN_140665850(rewards) != 0 ? 1 : 0;
    return bHas;
}

// @0x140b6d330
int CMasteryManager::FUN_140b6d330(int nStep)
{
    MS2Ptr<Unk_MmRow> spRow = FUN_1409670c0()->FUN_14066aa00(nStep);
    if (!spRow)
        return 0;
    if (spRow->m_ids.FUN_140186270() == 0)
        return 1;
    for (size_t i = 0; i < spRow->m_ids.FUN_140186270(); i++)
    {
        if (FUN_140764020()->m_10.FUN_140745630(*spRow->m_ids.FUN_140184510(i)) != 0)
            return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: per-return temporaries / cost loop frame differ from the exe
// @0x140b6d470
Unk_MasteryResult CMasteryManager::FUN_140b6d470(int nStep)
{
    Unk_MmPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return (Unk_MasteryResult)5;
    MS2Ptr<Unk_MmRow> spRow = FUN_1409670c0()->FUN_14066aa00(nStep);
    if (spRow.get() != 0)
    {
        int nType = spRow->m_nType;
        if (spRow->m_nNeedExp != 0)
        {
            unsigned int nExp = pPlayer->FUN_141662750(nType);
            if (nExp < spRow->m_nNeedExp)
                return (Unk_MasteryResult)1;
        }
        if (FUN_140b6d330(nStep) == 0)
            return (Unk_MasteryResult)3;
        if (spRow->m_nNeedMeso != 0 && DAT_143ab2898 < spRow->m_nNeedMeso)
            return (Unk_MasteryResult)2;
        for (size_t i = 0; i < spRow->m_costs.FUN_14026bee0(); i++)
        {
            MS2Ptr<Unk_MmCost> spCost = spRow->m_costs.FUN_14026bdc0(i);
            if (spCost->m_nKind == 0)
            {
                int nHave = DAT_143ab2a90.FUN_140a5f180(spCost->FUN_14026b500(), 0);
                if (nHave < spCost->m_nCount)
                    return (Unk_MasteryResult)4;
            }
            else
            {
                int nHave = DAT_143ab2a90.FUN_140a5f780(spCost->m_nKind, 0);
                if (nHave < spCost->m_nCount)
                    return (Unk_MasteryResult)4;
            }
        }
    }
    return (Unk_MasteryResult)0;
}

// MS2-FUNCTIONAL: the exe shares the CStringW temporaries between the cases (frame 0x138 smaller)
// @0x140b6d710
void CMasteryManager::FUN_140b6d710(Unk_MasteryResult eResult)
{
    CStringW strText;
    switch (eResult)
    {
    case 1:
        strText = FUN_14028b8e0(CStringW(L"s_mastery_error_lack_mastery"));
        break;
    case 2:
        strText = FUN_14028b8e0(CStringW(L"s_mastery_error_lack_meso"));
        break;
    case 3:
        strText = FUN_14028b8e0(CStringW(L"s_mastery_error_lack_quest"));
        break;
    case 4:
        strText = FUN_14028b8e0(CStringW(L"s_mastery_error_lack_item"));
        break;
    case 5:
        strText = Unk_MmFormat(CStringW(L"s_mastery_error_unknown"), eResult);
        break;
    case 7:
        strText = Unk_MmFormat(CStringW(L"s_mastery_error_invalid_level"), eResult);
        break;
    case 0xc:
        strText = FUN_14028b8e0(CStringW(L"s_anti_addiction_cannot_receive"));
        break;
    }
    FUN_1412751f0(strText, 1, 1);
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x140B6D0E0, CMasteryManager, FUN_140b6d0e0, 86, 0x3C2C797F);
MS2_REPLACE_METHOD(0x140B6D140, CMasteryManager, FUN_140b6d140, 266, 0x0B05C086);
MS2_REPLACE_METHOD(0x140B6D250, CMasteryManager, FUN_140b6d250, 203, 0x95812AFB);
MS2_REPLACE_METHOD(0x140B6D330, CMasteryManager, FUN_140b6d330, 310, 0xC4E143C1);
MS2_REPLACE_METHOD(0x140B6D470, CMasteryManager, FUN_140b6d470, 657, 0xED84B747);
MS2_REPLACE_METHOD(0x140B6D710, CMasteryManager, FUN_140b6d710, 936, 0xE616FB85);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca0d50-0x142ca0e10 .text$yd
