// citemoptiontable.h - CItemOptionTable (commonfiles\itemoptiondata.cpp#3). NOT an original header: names invented
// except the RTTI ones (CItemOptionTable, CItemOptionTable::ProbabilityFromRank). The layout-only placeholder used by
// other units is ms2/placeholder/citemoptiontable.h; this is the recovered form for the unit itself.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/unk_optionnamelist.h"
#include "ms2/commonfiles/itemoption.h"
#include "ms2/commonfiles/itemoptiondata.h"   // Unk_ProbabilityLog
#include <map>
#include <unordered_map>
#include <atlcoll.h>

class Unk_Random;
class CItem;
class CItemData;
class CItemOption;
class CItemRemakeOptionIngredient;
class Unk_1405e74c0;
class Unk_ItemOptionPreset;
class ItemOptionConstant;
class ItemOptionRandom;
class ItemOptionVariationData;

// RTTI CItemOptionTable (TSingleton at +0, CValidData at +8), 0x118 bytes: the item option xml tables.
class CItemOptionTable : public TSingleton<CItemOptionTable>, public CValidData<CItemOptionTable>
{
public:
    // The rank weights of an item level band (RTTI CItemOptionTable::ProbabilityFromRank, a CPtred, 0x30 bytes).
    class ProbabilityFromRank : public CPtred
    {
    public:
        ProbabilityFromRank(float f18, float f1c, float f20, float f24, float f28);    // 0x140604020
        // implicit dtor 0x140604b70 (no vptr store)
        float m_f18;                    // +0x18
        float m_f1c;                    // +0x1c
        float m_f20;                    // +0x20
        float m_f24;                    // +0x24
        float m_f28;                    // +0x28
    };

    CItemOptionTable();                                     // 0x1405f4140
    virtual ~CItemOptionTable();                            // 0x1405f4640

    bool FUN_1405f4720();                                   // loads every table
    void FUN_1405f47a0(int nItemId, int nLevel, int nRank, unsigned short nItemLevel,
                       const CItemRemakeOptionIngredient& kIngredient);    // the remake cost of an item
    void FUN_1405f4bb0(int nLevel, int nRank, const CItemRemakeOptionIngredient& kIngredient);
    int FUN_1405f4d30(int nItemId, int nGroup, unsigned short nLevel, int nSeed, bool bSecond) const;   // a random rank
    MS2Ptr<CItemOption> FUN_1405f4ff0(MS2Ptr<CItemData> spItem, int nRank, Unk_Random* pRandom);
    MS2Ptr<CItemOption> FUN_1405f5290(MS2Ptr<Unk_ItemOptionPreset> spPreset, Unk_Random* pRandom);
    bool FUN_1405f5620(MS2Ptr<CItemOption> spOption, int nItemId, int nRank);
    bool FUN_1405f5870(MS2Ptr<CItemOption> spOption, int nItemId, int nRank);
    bool FUN_1405f59b0(MS2Ptr<Unk_1405e74c0> spTarget, Unk_Random* pRandom);
    bool FUN_1405f5ba0(MS2Ptr<Unk_1405e74c0> spTarget, Unk_Random* pRandom);
    bool FUN_1405f5d90(int nItemId);                        // the item has constant options
    int FUN_1405f5e90(int nCode, int nRank, CString strTag, CString strInfo);   // always 1
    MS2Ptr<ItemOptionConstant> FUN_1405f5ee0(unsigned nId, int nGrade) const;  // the best constant row up to a grade
    MS2Ptr<ItemOptionRandom> FUN_1405f6010(int nId) const;
    int FUN_1405f6100(unsigned nStatId);
    int FUN_1405f6190(unsigned nStatId, Unk_Random* pRandom);
    int FUN_1405f6230(unsigned nStatId);
    int FUN_1405f62c0(unsigned nStatId);
    int FUN_1405f6350(unsigned nStatId);
    std::pair<int, int> FUN_1405f63e0(unsigned nStatId);         // the first and last stat of a variation row
    std::pair<int, int> FUN_1405f64e0(int nItemId, int nRank, int nStat);
    std::pair<int, int> FUN_1405f6650(int nItemId, int nRank, unsigned nSpecial);
    bool FUN_1405f67e0(MS2Ptr<CItem> spItem, int nStat, int nUnused, int nValue);
    bool FUN_1405f6a90(MS2Ptr<CItem> spItem, unsigned nSpecial, int nUnused, int nValue);
    int FUN_1405f6d40(MS2Ptr<CItemData> spItem, int nRank, unsigned nSpecial);
    Unk_OptionNameListPtr FUN_1405f6e40(const CString& strName);    // the exclusive group of a stat name (null: none)
    int FUN_1405f6ed0(Unk_SocketSpecialStat nKey) const;
    void FUN_1405f6f50(MS2Ptr<CItemData> spItem, int nRank, unsigned nTrials,
                       const std::vector<std::pair<int, int> >& vLocked, std::vector<CStringW>* pOut);
    void FUN_1405f70f0(MS2Ptr<CItemData> spItem, int nRank, unsigned nTrials,
                       const std::vector<std::pair<int, int> >& vLocked, std::vector<CStringW>* pOut,
                       unsigned nPickCount, int nIndex, Unk_ProbabilityLog& vLogs);
    void FUN_1405f78f0();                                   // the exclusive option groups
    bool LoadItemOptionConstant();
    bool LoadItemOptionRandom();
    bool FUN_1405f8770();
    bool LoadItemOptionVariation();                                   // the variation rows

    static void CheckInit();                                // 0x140608280
    static void SetInit(bool bInit) { s_bInit = bInit; }    // 0x140609530
    static bool s_bInit;                                    // DAT_143aafe98

    CLockCriticalSection m_lock;                                                        // +0x10
    std::map<std::pair<int, int>, MS2Ptr<ProbabilityFromRank> > m_rankProbs;            // +0x40
    std::map<std::pair<int, int>, MS2Ptr<ProbabilityFromRank> > m_rankProbs2;           // +0x50
    std::multimap<unsigned, MS2Ptr<ItemOptionConstant> > m_constants;                     // +0x60
    std::unordered_map<int, MS2Ptr<ItemOptionRandom> > m_randoms;                       // +0x70
    ATL::CAtlMap<CString, Unk_OptionNameListPtr, ATL::CStringElementTraits<CString> > m_names;  // +0xb0
    std::map<Unk_SocketSpecialStat, int> m_f8;                                          // +0xf8
    std::map<unsigned, MS2Ptr<ItemOptionVariationData> > m_variations;                    // +0x108
};
MS2_CHECK_SIZE(CItemOptionTable, 0x118);
MS2_CHECK_OFFSET(CItemOptionTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CItemOptionTable, m_constants, 0x60);
MS2_CHECK_OFFSET(CItemOptionTable, m_randoms, 0x70);
MS2_CHECK_OFFSET(CItemOptionTable, m_names, 0xb0);
MS2_CHECK_OFFSET(CItemOptionTable, m_f8, 0xf8);
MS2_CHECK_OFFSET(CItemOptionTable, m_variations, 0x108);
