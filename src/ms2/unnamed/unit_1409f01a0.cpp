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
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };     // ctor 0x1401cd100
static CString s_aSortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_unk1402a9d702(17, 0.75f, 0.25f, 2.25f, 10);

void* FUN_1422bb8b0(int nMovieId);                                     // the movie of a UI layer
void FUN_14256e3e0(void* pMovie, Scaleform::GFx::Value* pValue);       // movie->CreateArray
CStringW FUN_14082f000(int nStat);                                     // stat display text
CStringW FUN_14028de60(int nId);                                       // string table text
CStringW FUN_1409e9bc0(int nId, const int& a, const int& b);           // formatted string-table text

// @0x1409f01a0
ASStat::ASStat(int nType) : ASObj(nType)
{
    void* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie != 0)
    {
        FUN_14256e3e0(pMovie, &m_title);
        FUN_14256e3e0(pMovie, &m_hidden);
        FUN_14256e3e0(pMovie, &m_random);
        FUN_14256e3e0(pMovie, &m_special);
        FUN_14256e3e0(pMovie, &m_compare);
        FUN_14256e3e0(pMovie, &m_essential);
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
    CStringW strName = FUN_14082f000(nStat);
    ASObj row(2);
    row.FUN_1407cbb20("statName", strName);
    row.FUN_1409c1180("statValue", nValue);
    m_compare.PushBack(row.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409F04F0, ASStat, AddCompare, 206, 0x89FDD721);

// @0x1409f05d0
void ASStat::AddStat(int nStat, unsigned nValue, unsigned nStrengthen, int bEssential)
{
    CStringW strName = FUN_14082f000(nStat);
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
    CStringW strValue = FUN_1409e9bc0(0x4f8, a1, a2);
    ASObj row(2);
    row.FUN_1407cbb20("statName", FUN_14028de60(0x4aa));
    row.FUN_1407cbb20("statValue", strValue);
    row.FUN_1407cb9c0("statStrengthen", 0);
    m_essential.PushBack(row.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409F06F0, ASStat, AddEssentialText, 267, 0xB3775FA1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9e950-0x142c9ea70 .text$yd
