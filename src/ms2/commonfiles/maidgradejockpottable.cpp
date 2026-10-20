// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The maid tables: CMaidGradeJockpotTable
// (Table/Server/MaidGradeInfo.xml), CMaidRecipeTable (Table/MaidRecipe.xml) and CMaidRecipeGroupTable
// (Table/MaidRecipeGroup.xml), see maidgradejockpottable.h.
// MS2-UNIT: ?\maidgradejockpottable.cpp
// MS2-RANGE: 0x1406846a0-0x14068f630 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0CNode@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAA@HAEBV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@Z 0x1406890f0 ; unique
// MS2-PIN: ??0CPair@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@IEAA@HAEBV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@Z 0x140689200 ; unique
// MS2-PIN: ??_ECMaidGradeJockpotTable@@W7EAAPEAXI@Z 0x140689c30 ; unique
// MS2-PIN: ??_ECMaidRecipeGroupTable@@W7EAAPEAXI@Z 0x140689c3c ; unique
// MS2-PIN: ??_ECMaidRecipeTable@@W7EAAPEAXI@Z 0x140689c48 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@Z 0x14068b210 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14068b730 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@Z 0x14068c110 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@IEAAPEAVCNode@12@HAEBV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@Z 0x14068ce10 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14068d930 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@Z 0x14068dc20 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@HV?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x14068dde0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$TPtrValue@URecipeLevel@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$TPtrValue@URecipeLevel@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$TPtrValue@URecipeLevel@@@@@2@XZ 0x14068e750 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CMaidGradeJockpotTable@@6B?$TSingleton@VCMaidGradeJockpotTable@@@@@ 0x142d75dc8
// MS2-PIN: ??_7CMaidGradeJockpotTable@@6B?$CValidData@VCMaidGradeJockpotTable@@@@@ 0x142d75dd8
// MS2-PIN: ??_7CMaidRecipeTable@@6B?$TSingleton@VCMaidRecipeTable@@@@@ 0x142d75e18
// MS2-PIN: ??_7CMaidRecipeTable@@6B?$CValidData@VCMaidRecipeTable@@@@@ 0x142d75e28
// MS2-PIN: ??_7CMaidRecipeGroupTable@@6B?$TSingleton@VCMaidRecipeGroupTable@@@@@ 0x142d75e58
// MS2-PIN: ??_7CMaidRecipeGroupTable@@6B?$CValidData@VCMaidRecipeGroupTable@@@@@ 0x142d75e68
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$TPtrValue@URecipeLevel@@@@V?$CElementTraits@V?$TPtrValue@URecipeLevel@@@@@ATL@@@ATL@@@@6B@ 0x142d75e78
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\maidgradejockpottable.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#define MS2_TPTRVALUE_MOVE
#include "maidgradejockpottable.h"
#include <algorithm>
#include <typeinfo>
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_MaidLoader { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_MaidLoader* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const CString& strArg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);                 // undecorated class name
bool FUN_14028f710(Unk_140165cf0* pNode);                               // the row is for this client's region
int FUN_1408733a0(Unk_140165cf0* pNode, const char* pszName, double& rOut);
// The locale list test and the game rule block (the level limit slot at +0x5180).
class Unk_MaidLocale { public: bool FUN_14036d750(const CStringW& strLocale); };
Unk_MaidLocale* FUN_140166410();
struct Unk_MaidLimitSlot { char m_pad[0x58]; };
struct Unk_MaidRule
{
    char m_pad[0x5180];
    Unk_MaidLimitSlot m_limit;
};
Unk_MaidRule* FUN_1401d3200();
unsigned* FUN_1402056b0(Unk_MaidLimitSlot* pSlot);   // the level limit
void FUN_140177e10(const CString& str, ATL::CAtlArray<int>& arr, const char* pszDelim);   // split into ints
// The item string table (id <-> name).
class Unk_MaidIngTable;
Unk_MaidIngTable* FUN_140281980();
unsigned FUN_1405575b0(Unk_MaidIngTable* pTable, int nStringId);
int FUN_140557640(Unk_MaidIngTable* pTable, const CString& strName);
unsigned FUN_1407181d0(const CString& strItem);                         // numeric item id of a text, or 0

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flags (symbols.tsv); local copies stay false
bool CMaidGradeJockpotTable::s_bInit;
bool CMaidRecipeTable::s_bInit;
bool CMaidRecipeGroupTable::s_bInit;
#endif

// @0x1406846a0
CMaidGradeJockpotTable::CMaidGradeJockpotTable()
{
}

// @0x140684730
CMaidGradeJockpotTable::~CMaidGradeJockpotTable()
{
    m_feelRates.RemoveAll();
}

// @0x1406847c0
int CMaidGradeJockpotTable::Load()
{
    CString strPath = FUN_14071a5b0("Table/Server", "MaidGradeInfo.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("Grade"); pNode != 0; pNode = pNode->FUN_140168650("Grade"))
    {
        int nGrade = 0;
        double dJackpot = 0;
        FUN_1408731e0(pNode, "Grade", nGrade);
        FUN_1408733a0(pNode, "JackpotRate", dJackpot);
        m_jackpotRates.SetAt(nGrade, dJackpot);
        TPtrValue<ATL::CAtlArray<double> > spRates(Unk_GrNewTag(0));
        double dNormal = 0;
        FUN_1408733a0(pNode, "FeelNormalRate", dNormal);
        spRates->Add(dNormal);
        double dGood = 0;
        FUN_1408733a0(pNode, "FeelGoodRate", dGood);
        spRates->Add(dGood);
        double dVeryGood = 0;
        FUN_1408733a0(pNode, "FeelVeryGoodRate", dVeryGood);
        spRates->Add(dVeryGood);
        m_feelRates.SetAt(nGrade, spRates);
    }
    SetInit(true);
    return 1;
}
MS2_REPLACE_METHOD(0x1406847C0, CMaidGradeJockpotTable, Load, 819, 0xEC7979A4);

// @0x140684b00
double CMaidGradeJockpotTable::GetJackpotRate(int nGrade)
{
    CheckInit();
    double dRate = 0;
    if (m_jackpotRates.Lookup(nGrade, dRate))
        return dRate;
    return 0;
}
MS2_REPLACE_METHOD(0x140684B00, CMaidGradeJockpotTable, GetJackpotRate, 76, 0x27A306B5);

// @0x140684b60
double CMaidGradeJockpotTable::GetFeelRate(int nGrade, int nFeel)
{
    CheckInit();
    TPtrValue<ATL::CAtlArray<double> > spRates;
    if (m_feelRates.Lookup(nGrade, spRates) && (size_t)nFeel < spRates->GetCount())
        return (*spRates)[nFeel];
    return 0;
}
MS2_REPLACE_METHOD(0x140684B60, CMaidGradeJockpotTable, GetFeelRate, 214, 0x4478FC36);

// @0x140684c40
unsigned MaidIngredient::GetItemId()
{
    if (itemStringId == 0)
        return itemId;
    return FUN_1405575b0(FUN_140281980(), itemStringId);
}
MS2_REPLACE_METHOD(0x140684C40, MaidIngredient, GetItemId, 56, 0x2A489CEE);

// @0x140684c80
int MaidIngredient::GetItemStringId()
{
    return itemStringId;
}
MS2_REPLACE_METHOD(0x140684C80, MaidIngredient, GetItemStringId, 14, 0xAAC7684B);

// @0x140684ca0
void MaidIngredient::SetItem(const CStringA& value)
{
    unsigned nId = FUN_1407181d0(value);
    if (nId > 0)
        itemId = nId;
    else if (!value.IsEmpty())
        itemStringId = FUN_140557640(FUN_140281980(), value);
}
MS2_REPLACE_METHOD(0x140684CA0, MaidIngredient, SetItem, 98, 0xA762B9F0);

// @0x140684d10
CMaidRecipe::CMaidRecipe()
    : id(0), workbenchType(0), maidExp(0)
{
}

// @0x140684d80
CMaidRecipe::~CMaidRecipe()
{
}

// @0x140684dc0
CMaidRecipeTable::CMaidRecipeTable()
{
}

// @0x140684e40
CMaidRecipeTable::~CMaidRecipeTable()
{
}

// @0x140684ea0
int CMaidRecipeTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "MaidRecipe.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("recipe"); pNode != 0; pNode = pNode->FUN_140168650("recipe"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CStringW strLocale;
        FUN_140873420(pNode, "locale", strLocale);
        if (!FUN_140166410()->FUN_14036d750(strLocale))
            continue;
        MS2Ptr<CMaidRecipe> spRecipe(new CMaidRecipe);
        FUN_1408731e0(pNode, "Id", spRecipe->id);
        CStringA strItem;
        TPtrValue<MaidIngredient> spFirst(Unk_GrNewTag(0));
        FUN_1408733e0(pNode, "FirstIngredientItemID", strItem);
        FUN_140873220(pNode, "FirstIngredientCount", spFirst->count);
        spFirst->SetItem(strItem);
        if (spFirst->GetItemId() > 0)
            spRecipe->ingredients.push_back(spFirst);
        TPtrValue<MaidIngredient> spSecond(Unk_GrNewTag(0));
        FUN_1408733e0(pNode, "SecondIngredientItemID", strItem);
        FUN_140873220(pNode, "SecondIngredientCount", spSecond->count);
        spSecond->SetItem(strItem);
        if (spSecond->GetItemId() > 0)
            spRecipe->ingredients.push_back(spSecond);
        TPtrValue<MaidIngredient> spThird(Unk_GrNewTag(0));
        FUN_1408733e0(pNode, "ThirdIngredientItemID", strItem);
        FUN_140873220(pNode, "ThirdIngredientCount", spThird->count);
        spThird->SetItem(strItem);
        if (spThird->GetItemId() > 0)
            spRecipe->ingredients.push_back(spThird);
        FUN_1408731e0(pNode, "WorkbenchType", spRecipe->workbenchType);
        FUN_140873220(pNode, "LeadTimeNormal", spRecipe->leadTimes[0]);
        FUN_140873220(pNode, "LeadTimeGood", spRecipe->leadTimes[1]);
        FUN_140873220(pNode, "LeadTimeVeryGood", spRecipe->leadTimes[2]);
        FUN_1408731e0(pNode, "MaidExp", spRecipe->maidExp);
        FUN_1408731e0(pNode, "MaidMood", spRecipe->maidMood);
        FUN_140873220(pNode, "ProductItemID", spRecipe->productItemId);
        FUN_1408731e0(pNode, "ProductCount", spRecipe->productCount);
        FUN_140873220(pNode, "ProductsocketDataID", spRecipe->productSocketDataId);
        int nRank = 0;
        FUN_1408731e0(pNode, "ProductRank", nRank);
        spRecipe->productRank = (std::min)(6, (std::max)(1, nRank));
        m_recipes.SetAt(spRecipe->id, spRecipe);
    }
    return Validate();
}
MS2_REPLACE_METHOD(0x140684EA0, CMaidRecipeTable, Load, 1780, 0x17526064);

// @0x1406855a0
int CMaidRecipeTable::Validate()
{
    SetInit(true);
    return 1;
}
MS2_REPLACE_METHOD(0x1406855A0, CMaidRecipeTable, Validate, 26, 0x9925CE45);

// @0x1406855c0
MS2Ptr<CMaidRecipe> CMaidRecipeTable::Find(int nId)
{
    CheckInit();
    MS2Ptr<CMaidRecipe> spRecipe(0);
    if (m_recipes.Lookup(nId, spRecipe))
        return spRecipe;
    return MS2Ptr<CMaidRecipe>(0);
}
MS2_REPLACE_METHOD(0x1406855C0, CMaidRecipeTable, Find, 173, 0x76577CEC);

// @0x140685680
CMaidRecipeGroupTable::CMaidRecipeGroupTable()
{
}

// @0x140685700
CMaidRecipeGroupTable::~CMaidRecipeGroupTable()
{
}

// @0x140685f80
static bool Unk_RecipeLevelLess(const TPtrValue<RecipeLevel>& lhs, const TPtrValue<RecipeLevel>& rhs)
{
    if (lhs->requireLevel == rhs->requireLevel)
        return lhs->recipeId < rhs->recipeId;
    return lhs->requireLevel < rhs->requireLevel;
}

// @0x140685760
int CMaidRecipeGroupTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "MaidRecipeGroup.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("group"); pNode != 0; pNode = pNode->FUN_140168650("group"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CStringW strLocale;
        FUN_140873420(pNode, "locale", strLocale);
        if (!FUN_140166410()->FUN_14036d750(strLocale))
            continue;
        int nGroupId = 0;
        FUN_1408731e0(pNode, "GroupID", nGroupId);
        CStringA strRecipeIds;
        ATL::CAtlArray<int> recipeIds;
        FUN_1408733e0(pNode, "RecipeIDs", strRecipeIds);
        FUN_140177e10(strRecipeIds, recipeIds, ",");
        CStringA strLevels;
        ATL::CAtlArray<int> levels;
        FUN_1408733e0(pNode, "RequireLevels", strLevels);
        FUN_140177e10(strLevels, levels, ",");
        if (recipeIds.GetCount() != levels.GetCount())
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[RecipeID count mismatch requirelevel count {0}]", strPath);
            return 0;
        }
        std::vector<TPtrValue<RecipeLevel> > sorted;
        for (size_t i = 0; i < recipeIds.GetCount(); i++)
        {
            if ((unsigned)levels[i] > *FUN_1402056b0(&FUN_1401d3200()->m_limit))
                continue;
            TPtrValue<RecipeLevel> spLevel(Unk_GrNewTag(0));
            spLevel->recipeId = recipeIds[i];
            spLevel->requireLevel = levels[i];
            sorted.push_back(spLevel);
        }
        std::sort(sorted.begin(), sorted.end(), Unk_RecipeLevelLess);
        RecipeList spList(Unk_GrNewTag(0));
        for (size_t i = 0; i < sorted.size(); i++)
            spList->Add(sorted[i]);
        m_groups.SetAt(nGroupId, spList);
    }
    SetInit(true);
    return 1;
}
MS2_REPLACE_METHOD(0x140685760, CMaidRecipeGroupTable, Load, 1593, 0xB883C251);

// @0x140685da0
CMaidRecipeGroupTable::RecipeList CMaidRecipeGroupTable::Find(int nGroupId)
{
    CheckInit();
    RecipeList spList(0);
    if (m_groups.Lookup(nGroupId, spList))
        return spList;
    return RecipeList(0);
}
MS2_REPLACE_METHOD(0x140685DA0, CMaidRecipeGroupTable, Find, 173, 0x49F66F69);

// @0x140685e60
int CMaidRecipeGroupTable::GetRequireLevel(int nGroupId, int nRecipeId, int& rnLevel)
{
    CheckInit();
    RecipeList spList(0);
    if (m_groups.Lookup(nGroupId, spList))
    {
        for (size_t i = 0; i < spList->GetCount(); i++)
        {
            if ((*spList)[i]->recipeId == nRecipeId)
            {
                rnLevel = (*spList)[i]->requireLevel;
                return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140685E60, CMaidRecipeGroupTable, GetRequireLevel, 272, 0xEAA9789F);

// @0x14068a360
void CMaidGradeJockpotTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CMaidGradeJockpotTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14068a410
void CMaidRecipeGroupTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CMaidRecipeGroupTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14068a4c0
void CMaidRecipeTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CMaidRecipeTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14068dec0
void CMaidGradeJockpotTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x14068ded0
void CMaidRecipeGroupTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x14068dee0
void CMaidRecipeTable::SetInit(bool b)
{
    s_bInit = b;
}
// MS2-PIN: ??1?$CAtlArray@NV?$CElementTraits@N@ATL@@@ATL@@QEAA@XZ 0x1406892f0 ; byte-identical to ~CAtlArray<int> (ICF); TPtredDummy<CAtlArray<double>> dtor 0x140689680 calls it
// MS2-PIN: ?CallDestructors@?$CAtlArray@NV?$CElementTraits@N@ATL@@@ATL@@CAXPEAN_K@Z 0x14068a2c0 ; byte-identical to CallDestructors<int> (ICF), called by 0x1406892f0
