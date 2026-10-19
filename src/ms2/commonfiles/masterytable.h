// masterytable.h - CMasteryTable / CMasteryReceipe (RTTI names): the mastery (job skill) tables read from
// Table/mastery.xml (grade -> required mastery value + job rewards, per mastery type), Table/masteryReceipe.xml (the
// recipes) and Table/masteryDifferentialFactor.xml (reward factor by grade difference). Header name assumed; member
// and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// One recipe row of masteryReceipe.xml, 0xc0 bytes.
class CMasteryReceipe : public CPtred
{
public:
    CMasteryReceipe();                                  // 0x14066d000
    virtual ~CMasteryReceipe();                         // 0x14066d630
    int Load(Unk_140165cf0* pNode);                     // 0x1406694a0
    CStringA IconPath();                                // 0x140669980

    int m_nId;                                          // +0x18 "id"
    int m_nType;                                        // +0x1c "masteryType"
    unsigned short m_nLevel;                            // +0x20 "requireLevel"
    unsigned m_nRequireMastery;                         // +0x24 "requireMastery"
    __int64 m_nRequireMeso;                             // +0x28 "requireMeso"
    ATL::CAtlArray<unsigned> m_requireQuest;            // +0x30 "requireQuest"
    CIngredientContainer m_ingredients;                 // +0x50 "requireItem1..5"
    unsigned m_nRewardMastery;                          // +0x80 "rewardMastery"
    unsigned m_nGatheringTime;                          // +0x84 "gatheringTime"
    unsigned m_nHighPropLimit;                          // +0x88 "highPropLimitCount"
    unsigned m_nNormalPropLimit;                        // +0x8c "normalPropLimitCount"
    CStringW m_strHabitat;                              // +0x90 names of the "habitatMapId" maps
    ATL::CAtlArray<ItemEntity> m_rewards;               // +0x98 "rewardItem1..5"
    int m_nExceptRewardExp;                             // +0xb8 "exceptRewardExp"
};
MS2_CHECK_SIZE(CMasteryReceipe, 0xc0);
MS2_CHECK_OFFSET(CMasteryReceipe, m_requireQuest, 0x30);
MS2_CHECK_OFFSET(CMasteryReceipe, m_ingredients, 0x50);
MS2_CHECK_OFFSET(CMasteryReceipe, m_strHabitat, 0x90);
MS2_CHECK_OFFSET(CMasteryReceipe, m_rewards, 0x98);

// RTTI CMasteryTable, 0x328 bytes: TSingleton at +0, CValidData at +8.
class CMasteryTable : public TSingleton<CMasteryTable>, public CValidData<CMasteryTable>
{
public:
    // One <v> row of masteryDifferentialFactor.xml, 0x28 bytes.
    class DifferentialFactor : public CPtred
    {
    public:
        DifferentialFactor();                           // 0x14066d320
        virtual ~DifferentialFactor();                  // 0x14066d7a0
        unsigned m_nFactor;                             // +0x18 "factor"
        CStringA m_strIcon;                             // +0x20 "icon"
    };
    // One <v> row of mastery.xml, 0x40 bytes.
    class Mastery : public CPtred
    {
    public:
        Mastery();                                      // 0x14066d370
        virtual ~Mastery();                             // 0x14066d7d0
        int m_nGrade;                                   // +0x18 "grade"
        unsigned m_nValue;                              // +0x1c "value" (mastery value needed for the grade)
        ATL::CAtlArray<MS2Ptr<ItemEntity> > m_rewards;  // +0x20 "rewardJobItemID/Rank/Count"
    };
    typedef MS2Ptr<CMasteryReceipe> ReceipePtr;
    typedef MS2Ptr<DifferentialFactor> DifferentialPtr;
    typedef MS2Ptr<Mastery> MasteryPtr;
    typedef ATL::CAtlArray<std::pair<int, int> > IngredientList;
    typedef TPtrValue<IngredientList> IngredientListPtr;

    CMasteryTable();                                    // 0x140669a20
    virtual ~CMasteryTable();                           // 0x140669b70

    int Load();                                         // 0x140669c30 receipes, mastery, differentials
    int LoadMastery();                                  // 0x140669c90
    int LoadReceipes();                                 // 0x14066a300
    int LoadDifferentials();                            // 0x14066a740
    ReceipePtr Find(int nReceipeId);                    // 0x14066aa00
    void Receipes(int nType, ATL::CAtlArray<ReceipePtr>& rOut);   // 0x14066aa90 sorted by required mastery
    int Factor(int nReceipeId, unsigned nValue);        // 0x14066ab90 reward mastery scaled by the grade difference
    CStringA DifferentialName(int nReceipeId, unsigned nValue);   // 0x14066adb0 icon of that difference
    int Grade(int nType, unsigned nValue);              // 0x14066af60
    int MaxGrade(int nType);                            // 0x14066b050
    void Rewards(int nId, int nJob, ATL::CAtlArray<MS2Ptr<ItemEntity> >& rOut);   // 0x14066b100
    unsigned Value(int nType, int nGrade);              // 0x14066b310
    unsigned MaxValue(int nType);                       // 0x14066b3e0
    int Type(int nReceipeId);                           // 0x14066b440
    int TypeFromID(unsigned nId);                       // 0x14066b4c0
    int GradeFromID(unsigned nId);                      // 0x14066b4e0
    int MakeID(int nType, int nGrade);                  // 0x14066b500
    int StringID(int nType);                            // 0x14066b530
    ItemEntity* FirstItem(int nReceipeId);              // 0x14066b640
    int HasIngredient(int nReceipeId, int nItemId);     // 0x14066b710
    int HasTypeIngredient(int nType, int nItemId);      // 0x14066b910
    int IsProductionType(int nType);                    // 0x14066ba00
    int IsProduction(int nReceipeId);                   // 0x14066bab0
    int IsProduction(ReceipePtr spReceipe);             // 0x14066bb00
    int IsOther(int nReceipeId);                        // 0x14066bb80
    int IsOther(ReceipePtr spReceipe);                  // 0x14066bbc0
    int LimitState(int nReceipeId);                     // 0x14066bc40 0 high / 1 normal / 2 low / 3 none
    CStringW TypeName(int nType);                       // 0x14066bdd0
    CStringW SuccessDescription(int nType, int nReceipeId, int nColored);   // 0x14066c110
    CStringW GradeName(int nType, int nGrade);          // 0x14066c690
    IngredientListPtr IngredientReceipes(unsigned nItemId);   // 0x14066c710 (recipe id, amount) per ingredient item

    static void CheckInit();                            // 0x14066de70
    static void SetInit(bool b);                        // 0x140671e30

    static bool s_bInit;                                // 0x143ab02e8

    ATL::CAtlMap<int, DifferentialPtr> m_differentials; // +0x10 grade difference -> factor
    ATL::CAtlMap<int, ReceipePtr> m_receipes;           // +0x58 recipe id -> recipe
    ATL::CRBMap<int, MasteryPtr> m_mastery[12];         // +0xa0 per mastery type: grade -> row
    ATL::CAtlMap<int, IngredientListPtr> m_ingredientReceipes;   // +0x2e0 ingredient item -> (recipe, amount)
};
MS2_CHECK_SIZE(CMasteryTable::DifferentialFactor, 0x28);
MS2_CHECK_SIZE(CMasteryTable::Mastery, 0x40);
MS2_CHECK_SIZE(CMasteryTable, 0x328);
MS2_CHECK_OFFSET(CMasteryTable, m_differentials, 0x10);
MS2_CHECK_OFFSET(CMasteryTable, m_receipes, 0x58);
MS2_CHECK_OFFSET(CMasteryTable, m_mastery, 0xa0);
MS2_CHECK_OFFSET(CMasteryTable, m_ingredientReceipes, 0x2e0);
