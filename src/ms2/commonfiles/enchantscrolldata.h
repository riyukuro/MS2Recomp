// enchantscrolldata.h - CEnchantScrollData / CEnchantScrollRecipe / CEnchantScrollTable (RTTI names): the enchant scroll
// tables read from Table/enchantScroll.xml and Table/enchantScrollRecipe.xml.
// Header name assumed from the unit path; member and method names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// One <scroll> row, 0xc0 bytes (CPtred base).
class CEnchantScrollData : public CPtred
{
public:
    CEnchantScrollData();                   // 0x14034d030
    virtual ~CEnchantScrollData();          // 0x14034d130

    int Read(Unk_140165cf0* pElem);         // 0x14034d190 attributes of one <scroll>
    unsigned GetMaxRank();                  // 0x14034d370
    unsigned GetMinKey();                   // 0x14034d400
    unsigned GetMaxKey();                   // 0x14034d4a0

    int m_nScrollType;                      // +0x18 "scrollType" (0 = invalid)
    int m_nGrade;                           // +0x1c "grade"
    unsigned short m_nMinLv;                // +0x20 "minLv"
    unsigned short m_nMaxLv;                // +0x22 "maxLv"
    int m_nField24;                         // +0x24
    bool m_bLockTrade;                      // +0x28 "isLockTrade"
    bool m_bDisableBreak;                   // +0x29 "disableBreak"
    int m_nMinGrade;                        // +0x2c "minGrade"
    int m_nMaxGrade;                        // +0x30 "maxGrade"
    ATL::CAtlArray<unsigned> m_slots;       // +0x38 "slot"
    ATL::CAtlArray<unsigned> m_ranks;       // +0x58 "rank"
    ATL::CAtlMap<unsigned, unsigned> m_map; // +0x78
};
MS2_CHECK_SIZE(CEnchantScrollData, 0xc0);
MS2_CHECK_OFFSET(CEnchantScrollData, m_nMinLv, 0x20);
MS2_CHECK_OFFSET(CEnchantScrollData, m_bLockTrade, 0x28);
MS2_CHECK_OFFSET(CEnchantScrollData, m_slots, 0x38);
MS2_CHECK_OFFSET(CEnchantScrollData, m_ranks, 0x58);
MS2_CHECK_OFFSET(CEnchantScrollData, m_map, 0x78);

// Item data record looked up by id (the pieces this unit reads; the rest is unrecovered).
class Unk_EnchantFuncParams
{
public:
    int FUN_1408d1f60(unsigned nIndex, int nDefault);   // GetInt
    unsigned FUN_1408d2380();                           // GetCount
};

class Unk_EnchantItemData
{
public:
    CString FUN_14053fdd0();                // the item's display name

    char m_pad_000[0x290];
    CStringW m_strFunction;                 // +0x290 "EnchantScroll" for scroll items
    void* m_pad_298;
    void* m_pad_2a0;
    void* m_pad_2a8;
    Unk_EnchantFuncParams m_params;         // +0x2b0
};
MS2_CHECK_OFFSET(Unk_EnchantItemData, m_strFunction, 0x290);
MS2_CHECK_OFFSET(Unk_EnchantItemData, m_params, 0x2b0);

class Unk_EnchantItemPtr
{
public:
    ~Unk_EnchantItemPtr();                  // 0x1401b50d0
    bool FUN_1402ffd90() const;             // is null
private:
    MS2_LAYOUT_FRIEND;
    void* m_unknown;
    Unk_EnchantItemData* m_pObject;
};
MS2_CHECK_SIZE(Unk_EnchantItemPtr, 0x10);

// One <recipe> row, 0xb8 bytes (CPtred base).
class CEnchantScrollRecipe : public CPtred
{
public:
    CEnchantScrollRecipe();                 // 0x14034d530
    virtual ~CEnchantScrollRecipe();        // 0x14034d5f0

    int Read(Unk_140165cf0* pElem);         // 0x14034d660 attributes of one <recipe>
    CString GetRewardName();                // 0x14034dbe0

    int m_nId;                              // +0x18 "id"
    int m_nRecipeType;                      // +0x1c "recipeType"
    int m_nScrollId;                        // +0x20 the scroll item's function parameter 0
    int m_nSlot;                            // +0x24 "slot"
    int m_nMaxLv;                           // +0x28 the scroll's maxLv
    ItemEntity m_scroll;                    // +0x30 "rewardScroll"
    __int64 m_nMeso;                        // +0x60 "requireMeso"
    CIngredientContainer m_ingredients;     // +0x68 "requireItem1..5"
    ATL::CAtlArray<ItemEntity> m_rewards;   // +0x98 "rewardItem1..5"
};
MS2_CHECK_SIZE(CEnchantScrollRecipe, 0xb8);
MS2_CHECK_OFFSET(CEnchantScrollRecipe, m_scroll, 0x30);
MS2_CHECK_OFFSET(CEnchantScrollRecipe, m_nMeso, 0x60);
MS2_CHECK_OFFSET(CEnchantScrollRecipe, m_ingredients, 0x68);
MS2_CHECK_OFFSET(CEnchantScrollRecipe, m_rewards, 0x98);

// RTTI CEnchantScrollTable, 0x98 bytes (+ TSingleton).
class CEnchantScrollTable : public TSingleton<CEnchantScrollTable>
{
public:
    typedef MS2Ptr<CEnchantScrollData> ScrollPtr;
    typedef MS2Ptr<CEnchantScrollRecipe> RecipePtr;
    typedef ATL::CAtlMap<unsigned, ScrollPtr> ScrollMap;
    typedef ATL::CAtlMap<unsigned, RecipePtr> RecipeMap;

    CEnchantScrollTable();                  // 0x14034dcb0
    virtual ~CEnchantScrollTable();         // 0x14034dd60

    int Load();                                                     // 0x14034dde0
    int LoadScrolls();                                              // 0x14034de20
    int LoadRecipes();                                              // 0x14034e0d0
    ScrollPtr FindScroll(unsigned nId);                             // 0x14034e360
    RecipePtr FindRecipe(unsigned nId);                             // 0x14034e3e0
    void FindRecipes(int nType, int nSlot, int nRank, ATL::CAtlArray<RecipePtr>& rOut);   // 0x14034e460
    int HasRecipe(int nType, int nRank);                            // 0x14034e5e0

private:
    MS2_LAYOUT_FRIEND;
    ScrollMap m_scrolls;                    // +0x08 id -> <scroll>
    RecipeMap m_recipes;                    // +0x50 id -> <recipe>
};
MS2_CHECK_SIZE(CEnchantScrollTable, 0x98);
MS2_CHECK_OFFSET(CEnchantScrollTable, m_scrolls, 0x08);
MS2_CHECK_OFFSET(CEnchantScrollTable, m_recipes, 0x50);
