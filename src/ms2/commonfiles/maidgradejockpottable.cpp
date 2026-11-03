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
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);                 // undecorated class name
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int XmlGetAttr(class TiXmlElement*, char const*, double&);   // C3: was FUN_1408733a0
// The locale list test and the game rule block (the level limit slot at +0x5180).
struct Unk_MaidLimitSlot { char m_pad[0x58]; };
struct Unk_MaidRule
{
    char m_pad[0x5180];
    Unk_MaidLimitSlot m_limit;
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // C3: was FUN_140177e10 (CAtlArray<unsigned>)
// The item string table (id <-> name).
class Unk_MaidIngTable;


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
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>((class Unk_140165cf0 *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("Grade")); pNode != 0; pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("Grade")))
    {
        int nGrade = 0;
        double dJackpot = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "Grade", reinterpret_cast<int&>(nGrade));
        XmlGetAttr((class TiXmlElement*)(pNode), "JackpotRate", dJackpot);
        m_jackpotRates.SetAt(nGrade, dJackpot);
        TPtrValue<ATL::CAtlArray<double> > spRates(Unk_GrNewTag(0));
        double dNormal = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "FeelNormalRate", dNormal);
        spRates->Add(dNormal);
        double dGood = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "FeelGoodRate", dGood);
        spRates->Add(dGood);
        double dVeryGood = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "FeelVeryGoodRate", dVeryGood);
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
    return TSingleton<CItemDataTable>::GetInstance()->GetTagItemId((ItemTagKey)itemStringId);
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
        itemStringId = reinterpret_cast<CItemDataTable*>(reinterpret_cast<Unk_MaidIngTable*>(TSingleton<CItemDataTable>::GetInstance()))->GetTagByName(value);
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
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>((class Unk_140165cf0 *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("recipe")); pNode != 0; pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("recipe")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        CStringW strLocale;
        XmlGetAttr((class TiXmlElement*)(pNode), "locale", strLocale);
        if (!TSingleton<CFeatureManager>::GetInstance()->IsLocaleInList(strLocale))
            continue;
        MS2Ptr<CMaidRecipe> spRecipe(new CMaidRecipe);
        XmlGetAttr((class TiXmlElement*)(pNode), "Id", reinterpret_cast<int&>(spRecipe->id));
        CStringA strItem;
        TPtrValue<MaidIngredient> spFirst(Unk_GrNewTag(0));
        XmlGetAttr((class TiXmlElement*)(pNode), "FirstIngredientItemID", strItem);
        XmlGetAttr((class TiXmlElement*)(pNode), "FirstIngredientCount", spFirst->count);
        spFirst->SetItem(strItem);
        if (spFirst->GetItemId() > 0)
            spRecipe->ingredients.push_back(spFirst);
        TPtrValue<MaidIngredient> spSecond(Unk_GrNewTag(0));
        XmlGetAttr((class TiXmlElement*)(pNode), "SecondIngredientItemID", strItem);
        XmlGetAttr((class TiXmlElement*)(pNode), "SecondIngredientCount", spSecond->count);
        spSecond->SetItem(strItem);
        if (spSecond->GetItemId() > 0)
            spRecipe->ingredients.push_back(spSecond);
        TPtrValue<MaidIngredient> spThird(Unk_GrNewTag(0));
        XmlGetAttr((class TiXmlElement*)(pNode), "ThirdIngredientItemID", strItem);
        XmlGetAttr((class TiXmlElement*)(pNode), "ThirdIngredientCount", spThird->count);
        spThird->SetItem(strItem);
        if (spThird->GetItemId() > 0)
            spRecipe->ingredients.push_back(spThird);
        XmlGetAttr((class TiXmlElement*)(pNode), "WorkbenchType", reinterpret_cast<int&>(spRecipe->workbenchType));
        XmlGetAttr((class TiXmlElement*)(pNode), "LeadTimeNormal", spRecipe->leadTimes[0]);
        XmlGetAttr((class TiXmlElement*)(pNode), "LeadTimeGood", spRecipe->leadTimes[1]);
        XmlGetAttr((class TiXmlElement*)(pNode), "LeadTimeVeryGood", spRecipe->leadTimes[2]);
        XmlGetAttr((class TiXmlElement*)(pNode), "MaidExp", reinterpret_cast<int&>(spRecipe->maidExp));
        XmlGetAttr((class TiXmlElement*)(pNode), "MaidMood", reinterpret_cast<int&>(spRecipe->maidMood));
        XmlGetAttr((class TiXmlElement*)(pNode), "ProductItemID", spRecipe->productItemId);
        XmlGetAttr((class TiXmlElement*)(pNode), "ProductCount", reinterpret_cast<int&>(spRecipe->productCount));
        XmlGetAttr((class TiXmlElement*)(pNode), "ProductsocketDataID", spRecipe->productSocketDataId);
        int nRank = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "ProductRank", reinterpret_cast<int&>(nRank));
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
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>((class Unk_140165cf0 *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("group")); pNode != 0; pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("group")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        CStringW strLocale;
        XmlGetAttr((class TiXmlElement*)(pNode), "locale", strLocale);
        if (!TSingleton<CFeatureManager>::GetInstance()->IsLocaleInList(strLocale))
            continue;
        int nGroupId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "GroupID", reinterpret_cast<int&>(nGroupId));
        CStringA strRecipeIds;
        ATL::CAtlArray<unsigned> recipeIds;
        XmlGetAttr((class TiXmlElement*)(pNode), "RecipeIDs", strRecipeIds);
        XmlSplit(strRecipeIds, recipeIds, ",");
        CStringA strLevels;
        ATL::CAtlArray<unsigned> levels;
        XmlGetAttr((class TiXmlElement*)(pNode), "RequireLevels", strLevels);
        XmlSplit(strLevels, levels, ",");
        if (recipeIds.GetCount() != levels.GetCount())
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[RecipeID count mismatch requirelevel count {0}]", strPath);
            return 0;
        }
        std::vector<TPtrValue<RecipeLevel> > sorted;
        for (size_t i = 0; i < recipeIds.GetCount(); i++)
        {
            if ((unsigned)levels[i] > *reinterpret_cast<unsigned*>(reinterpret_cast<Common::Constants::Value<int>*>(&((struct Unk_MaidRule*)FUN_1401d3200())->m_limit)->Get()))
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
