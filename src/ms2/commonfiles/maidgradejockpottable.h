// maidgradejockpottable.h - the maid tables: CMaidGradeJockpotTable (Table/Server/MaidGradeInfo.xml, jackpot and
// "feel" rates per maid grade), CMaidRecipeTable (Table/MaidRecipe.xml) and CMaidRecipeGroupTable
// (Table/MaidRecipeGroup.xml), plus their rows (CMaidRecipe, MaidIngredient, RecipeLevel). Header name assumed (the
// unit is ?\maidgradejockpottable.cpp, 0x1406846a0-0x14068f630); member names come from the xml attributes. The
// cmaidrecipetable.h / cmaidrecipegrouptable.h placeholders forward here.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/commonfiles/os.h"

// One ingredient of a recipe, a 0x10 value inside a TPtredDummy box.
struct MaidIngredient
{
    MaidIngredient() : count(0), field04(0), itemId(0), itemStringId(0) {}
    unsigned GetItemId();                       // 0x140684c40 the numeric id, or the string table entry's id
    int GetItemStringId();                      // 0x140684c80
    void SetItem(const CStringA& value);        // 0x140684ca0
    unsigned count;                             // +0x00 "FirstIngredientCount"
    unsigned field04;
    unsigned itemId;                            // +0x08
    int itemStringId;                           // +0x0c
};
MS2_CHECK_SIZE(MaidIngredient, 0x10);

// One (recipe id, required level) pair of a recipe group, 8 bytes inside a TPtredDummy box.
struct RecipeLevel
{
    RecipeLevel() : recipeId(0), requireLevel(0) {}
    int recipeId;                               // +0x00
    int requireLevel;                           // +0x04
};
MS2_CHECK_SIZE(RecipeLevel, 8);

// One <recipe> row of MaidRecipe.xml, 0x60 bytes.
class CMaidRecipe : public CPtred
{
public:
    CMaidRecipe();                              // 0x140684d10
    virtual ~CMaidRecipe();                     // 0x140684d80
    int id;                                     // +0x18 "Id"
    int workbenchType;                          // +0x1c "WorkbenchType"
    unsigned leadTimes[3];                      // +0x20 "LeadTimeNormal" / "Good" / "VeryGood"
    int maidExp;                                // +0x2c "MaidExp"
    int maidMood;                               // +0x30 "MaidMood"
    std::vector<TPtrValue<MaidIngredient> > ingredients;   // +0x38
    unsigned productItemId;                     // +0x50 "ProductItemID"
    int productCount;                           // +0x54 "ProductCount"
    int productRank;                            // +0x58 "ProductRank" (1..6)
    unsigned productSocketDataId;               // +0x5c "ProductsocketDataID"
};
MS2_CHECK_SIZE(CMaidRecipe, 0x60);
MS2_CHECK_OFFSET(CMaidRecipe, leadTimes, 0x20);
MS2_CHECK_OFFSET(CMaidRecipe, ingredients, 0x38);
MS2_CHECK_OFFSET(CMaidRecipe, productSocketDataId, 0x5c);

// RTTI CMaidGradeJockpotTable, 0x70 bytes: TSingleton at +0, CValidData at +8.
class CMaidGradeJockpotTable : public TSingleton<CMaidGradeJockpotTable>, public CValidData<CMaidGradeJockpotTable>
{
public:
    CMaidGradeJockpotTable();                   // 0x1406846a0
    virtual ~CMaidGradeJockpotTable();          // 0x140684730
    int Load();                                 // 0x1406847c0
    double GetJackpotRate(int nGrade);          // 0x140684b00
    double GetFeelRate(int nGrade, int nFeel);  // 0x140684b60
    static void CheckInit();                    // 0x14068a360
    static void SetInit(bool b);                // 0x14068dec0
    static bool s_bInit;                        // 0x143ab03c0

    ATL::CRBMap<int, double> m_jackpotRates;    // +0x10 grade -> jackpot rate
    ATL::CRBMap<int, TPtrValue<ATL::CAtlArray<double> > > m_feelRates;   // +0x40 grade -> (normal, good, very good)
};
MS2_CHECK_SIZE(CMaidGradeJockpotTable, 0x70);
MS2_CHECK_OFFSET(CMaidGradeJockpotTable, m_jackpotRates, 0x10);
MS2_CHECK_OFFSET(CMaidGradeJockpotTable, m_feelRates, 0x40);

// RTTI CMaidRecipeTable, 0x40 bytes.
class CMaidRecipeTable : public TSingleton<CMaidRecipeTable>, public CValidData<CMaidRecipeTable>
{
public:
    CMaidRecipeTable();                         // 0x140684dc0
    virtual ~CMaidRecipeTable();                // 0x140684e40
    int Load();                                 // 0x140684ea0
    int Validate();                             // 0x1406855a0
    MS2Ptr<CMaidRecipe> Find(int nId);          // 0x1406855c0
    static void CheckInit();                    // 0x14068a4c0
    static void SetInit(bool b);                // 0x14068dee0
    static bool s_bInit;                        // 0x143ab03d0

    ATL::CRBMap<int, MS2Ptr<CMaidRecipe> > m_recipes;   // +0x10 recipe id -> recipe
};
MS2_CHECK_SIZE(CMaidRecipeTable, 0x40);
MS2_CHECK_OFFSET(CMaidRecipeTable, m_recipes, 0x10);

// RTTI CMaidRecipeGroupTable, 0x40 bytes.
class CMaidRecipeGroupTable : public TSingleton<CMaidRecipeGroupTable>, public CValidData<CMaidRecipeGroupTable>
{
public:
    typedef TPtrValue<ATL::CAtlArray<TPtrValue<RecipeLevel> > > RecipeList;
    CMaidRecipeGroupTable();                    // 0x140685680
    virtual ~CMaidRecipeGroupTable();           // 0x140685700
    int Load();                                 // 0x140685760
    RecipeList Find(int nGroupId);              // 0x140685da0
    int GetRequireLevel(int nGroupId, int nRecipeId, int& rnLevel);   // 0x140685e60
    static void CheckInit();                    // 0x14068a410
    static void SetInit(bool b);                // 0x14068ded0
    static bool s_bInit;                        // 0x143ab03e0

    ATL::CRBMap<int, RecipeList> m_groups;      // +0x10 group id -> recipes sorted by level
};
MS2_CHECK_SIZE(CMaidRecipeGroupTable, 0x40);
MS2_CHECK_OFFSET(CMaidRecipeGroupTable, m_groups, 0x10);
