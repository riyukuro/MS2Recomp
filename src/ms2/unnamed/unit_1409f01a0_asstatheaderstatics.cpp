// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASStat, the AS stat-block object (six AS arrays filled with
// { statName, statValue, statStrengthen } rows), plus the header statics of its translation unit.
// MS2-UNIT: unit_1409f01a0
// MS2-RANGE: 0x1400c2000-0x1400c2300 .text$di
// MS2-RANGE: 0x1409f01a0-0x1409f0910 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/asstat.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The header statics: header_statics_a.h's list, then a second header's copy of it with a handle in front of the condition.
#include "ms2/placeholder/header_statics_a.h"
class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };   // C3: was Unk_1401cd100 (ctor 0x1401cd100) ctor 0x1401cd100
static CString s_aSortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_BuddyHandle s_pointer2(NULL);
static Unk_1402a9d70 s_unk1402a9d702(17, 0.75f, 0.25f, 2.25f, 10);

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);   // the movie of a UI layer (ascript.cpp)
CStringW GetStatCommonText(unsigned nStat);                            // stat display text
CStringW GetStringCommon(int nId);                                       // string table text
template <class A, class B> CStringW BlockFormat(int nId, const A& a, const B& b);

// @0x1409f01a0
ASStat::ASStat(int nType) : ASObj(nType)
{
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie != 0)
    {
        pMovie->CreateArray(&m_title);
        pMovie->CreateArray(&m_hidden);
        pMovie->CreateArray(&m_random);
        pMovie->CreateArray(&m_special);
        pMovie->CreateArray(&m_compare);
        pMovie->CreateArray(&m_essential);
    }
    FUN_1409adbe0("title", m_title);
    FUN_1409adbe0("hidden", m_hidden);
    FUN_1409adbe0("random", m_random);
    FUN_1409adbe0("special", m_special);
    FUN_1409adbe0("compare", m_compare);
    FUN_1409adbe0("essential", m_essential);
}

// @0x1409f04f0
void ASStat::AddCompare(int nStat, __int64 nValue)
{
    CStringW strName = GetStatCommonText(nStat);
    ASObj row(2);
    row.FUN_1407cbb20("statName", strName);
    row.FUN_1409c1180("statValue", nValue);
    m_compare.PushBack(row.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409F04F0, ASStat, AddCompare, 206, 0x89FDD721);

// @0x1409f05d0
void ASStat::AddStat(int nStat, unsigned nValue, unsigned nStrengthen, int bEssential)
{
    CStringW strName = GetStatCommonText(nStat);
    ASObj row(2);
    row.FUN_1407cbb20("statName", strName);
    row.FUN_1409c0d20("statValue", nValue);
    row.FUN_1409c0d20("statStrengthen", nStrengthen);
    if (bEssential != 0)
        m_essential.PushBack(row.FUN_1422bb870());
    else
        m_random.PushBack(row.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409F05D0, ASStat, AddStat, 281, 0x44847E99);

// @0x1409f06f0
void ASStat::AddEssentialText(int a1, int a2)
{
    CStringW strValue = BlockFormat<unsigned, unsigned>(0x4f8, reinterpret_cast<const unsigned&>(a1), reinterpret_cast<const unsigned&>(a2));
    ASObj row(2);
    row.FUN_1407cbb20("statName", GetStringCommon(0x4aa));
    row.FUN_1407cbb20("statValue", strValue);
    row.FUN_1407cb9c0("statStrengthen", 0);
    m_essential.PushBack(row.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409F06F0, ASStat, AddEssentialText, 267, 0xB3775FA1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9e950-0x142c9ea70 .text$yd
