// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEnchantScrollTable: Table/enchantScroll.xml and Table/enchantScrollRecipe.xml.
// MS2-UNIT: ?\enchantscrolldata.cpp
// MS2-RANGE: 0x14034d030-0x140351890 .text$mn
// MS2-RANGE: 0x1400b6060-0x1400b6120 .text$di
// MS2-RANGE: 0x142c9a6d0-0x142c9a700 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?IsNull@?$MS2Ptr@VCEnchantScrollData@@@@QEBA_NXZ 0x14034eeb0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCEnchantScrollRecipe@@@@QEBAPEAVCEnchantScrollRecipe@@XZ 0x14034ef30 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VCEnchantScrollData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCEnchantScrollData@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x14034f7e0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VCEnchantScrollRecipe@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCEnchantScrollRecipe@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x14034f8d0 ; unique
// MS2-PIN: ??9ATL@@YA_NAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@0@PEB_W@Z 0x14034eee0 ; manual
// MS2-PIN: ??C?$MS2Ptr@VCEnchantScrollData@@@@QEBAPEAVCEnchantScrollData@@XZ 0x14034ef20 ; manual
// MS2-PIN: ?GetNext@?$CAtlMap@IV?$MS2Ptr@VCEnchantScrollRecipe@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCEnchantScrollRecipe@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14034f790 ; manual
// MS2-PIN: ?GetStartPosition@?$CAtlMap@IV?$MS2Ptr@VCEnchantScrollRecipe@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCEnchantScrollRecipe@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x14034f9c0 ; manual
// MS2-PIN: ?IsEmpty@?$CAtlMap@IV?$MS2Ptr@VCEnchantScrollRecipe@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCEnchantScrollRecipe@@@@@3@@ATL@@QEBA_NXZ 0x140350020 ; manual
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\enchantscrolldata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "enchantscrolldata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 : public CFileSystem { };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
bool FUN_14028f710(Unk_140165cf0*);                                     // the element is usable
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_1408731a0(Unk_140165cf0*, const char*, unsigned short&);
void FUN_1408730a0(Unk_140165cf0*, const char*, bool&);
void FUN_1408732e0(Unk_140165cf0*, const char*, __int64&);
int FUN_1408733e0(Unk_140165cf0*, const char*, CStringA&);
void FUN_140873420(Unk_140165cf0*, const char*, CStringW&);
int FUN_140873890(Unk_140165cf0*, const char*, int&);
void FUN_140177e10(const CStringA& str, ATL::CAtlArray<unsigned>& rOut, const char* pszSep);
Unk_EnchantItemPtr FUN_14053f870(int nItemId);
void* FUN_140302b10();
float FUN_1404c1810(void* pThis, int a, int b);
int FUN_14034e730(Unk_140165cf0* pElem, const char* pszName, int* pnOut);

// Sort names of the item list (header static of this unit).
#ifndef MS2_HOOK_DLL
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

// @0x14034d030
CEnchantScrollData::CEnchantScrollData()
    : m_nScrollType(0), m_nGrade(0), m_nMinLv(0), m_nMaxLv(0), m_nField24(0), m_bLockTrade(false), m_bDisableBreak(false),
      m_nMinGrade(0), m_nMaxGrade(0), m_slots(), m_ranks(), m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14034d130
CEnchantScrollData::~CEnchantScrollData()
{
}

// @0x14034d190
int CEnchantScrollData::Read(Unk_140165cf0* pElem)
{
    FUN_14034e730(pElem, "scrollType", &m_nScrollType);
    FUN_1408731a0(pElem, "minLv", m_nMinLv);
    FUN_1408731a0(pElem, "maxLv", m_nMaxLv);
    FUN_1408730a0(pElem, "isLockTrade", m_bLockTrade);
    FUN_1408730a0(pElem, "disableBreak", m_bDisableBreak);
    if (m_nScrollType == 0)
        return 0;
    if (m_nScrollType != 3)
        FUN_1408731e0(pElem, "grade", m_nGrade);
    if (m_nScrollType == 4)
    {
        FUN_1408731e0(pElem, "minGrade", m_nMinGrade);
        FUN_1408731e0(pElem, "maxGrade", m_nMaxGrade);
    }
    CString strSlot;
    CString strRank;
    FUN_1408733e0(pElem, "slot", strSlot);
    FUN_1408733e0(pElem, "rank", strRank);
    FUN_140177e10(strSlot, m_slots, ",");
    FUN_140177e10(strRank, m_ranks, ",");
    return 1;
}

// @0x14034d370
unsigned CEnchantScrollData::GetMaxRank()
{
    unsigned nMax = 0;
    for (size_t i = 0; i < m_ranks.GetCount(); i++)
    {
        if (m_ranks[i] > nMax)
            nMax = m_ranks[i];
    }
    return nMax;
}

// @0x14034d400
unsigned CEnchantScrollData::GetMinKey()
{
    unsigned nMin = 0xffffffff;
    for (POSITION pos = m_map.GetStartPosition(); pos != 0; m_map.GetNext(pos))
    {
        unsigned nKey = m_map.GetAt(pos)->m_key;
        if (nMin > nKey)
            nMin = nKey;
    }
    if (nMin == 0xffffffff)
        return 0;
    return nMin;
}

// @0x14034d4a0
unsigned CEnchantScrollData::GetMaxKey()
{
    unsigned nMax = 0;
    for (POSITION pos = m_map.GetStartPosition(); pos != 0; m_map.GetNext(pos))
    {
        unsigned nKey = m_map.GetAt(pos)->m_key;
        if (nMax < nKey)
            nMax = nKey;
    }
    return nMax;
}

// @0x14034d530
CEnchantScrollRecipe::CEnchantScrollRecipe()
    : m_nId(0), m_nRecipeType(0), m_nScrollId(0), m_nSlot(0), m_nMaxLv(0), m_scroll(), m_nMeso(0), m_ingredients(), m_rewards()
{
}

// @0x14034d5f0
CEnchantScrollRecipe::~CEnchantScrollRecipe()
{
}

// @0x14034d660
int CEnchantScrollRecipe::Read(Unk_140165cf0* pElem)
{
    FUN_1408731e0(pElem, "id", m_nId);
    FUN_1408731e0(pElem, "recipeType", m_nRecipeType);
    FUN_1408731e0(pElem, "slot", m_nSlot);
    CStringW strScroll;
    FUN_140873420(pElem, "rewardScroll", strScroll);
    m_scroll.vfunc_1(CStringW(strScroll));
    int nItemId = m_scroll.vfunc_o18_0();
    if (nItemId == 0)
        return 0;
    Unk_EnchantItemPtr item = FUN_14053f870(nItemId);
    if (item.FUN_1402ffd90())
        return 0;
    if (item.FUN_1401b52a0()->m_strFunction != L"EnchantScroll")
        return 0;
    if (item.FUN_1401b52a0()->m_params.FUN_1408d2380() == 0)
        return 0;
    m_nScrollId = item.FUN_1401b52a0()->m_params.FUN_1408d1f60(0, 0);
    CEnchantScrollTable::ScrollPtr scroll = CEnchantScrollTable::GetInstance()->FindScroll(m_nScrollId);
    if (scroll.IsNull())
        return 0;
    m_nMaxLv = scroll->m_nMaxLv;
    FUN_1408732e0(pElem, "requireMeso", m_nMeso);
    if (FUN_1404c1810(FUN_140302b10(), 1, 0) != 1.0f)
    {
        m_nMeso *= FUN_1404c1810(FUN_140302b10(), 1, 0);
        m_nMeso = ((m_nMeso + 50) / 100) * 100;
    }
    for (unsigned __int64 i = 1; i <= 5; i++)
    {
        CString strName = StringFormat("requireItem{0}", i);
        CStringW strItem;
        FUN_140873420(pElem, strName, strItem);
        m_ingredients.FUN_14026b9d0(strItem);
    }
    for (unsigned __int64 j = 1; j <= 5; j++)
    {
        CString strName = StringFormat("rewardItem{0}", j);
        CStringW strItem;
        FUN_140873420(pElem, strName, strItem);
        ItemEntity item;
        item.vfunc_1(CStringW(strItem));
        if (item.m_itemId != 0)
            m_rewards.Add(item);
    }
    return 1;
}

// @0x14034dbe0
CString CEnchantScrollRecipe::GetRewardName()
{
    Unk_EnchantItemPtr item = FUN_14053f870(m_scroll.vfunc_o18_0());
    if (item.FUN_1402ffd90())
        return CString("");
    return item.FUN_1401b52a0()->FUN_14053fdd0();
}

// @0x14034dcb0
CEnchantScrollTable::CEnchantScrollTable() : m_scrolls(17, 0.75f, 0.25f, 2.25f, 10), m_recipes(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14034dd60
CEnchantScrollTable::~CEnchantScrollTable()
{
    m_scrolls.RemoveAll();
    m_recipes.RemoveAll();
}

// @0x14034dde0
int CEnchantScrollTable::Load()
{
    if (LoadScrolls() == 0)
        return 0;
    if (LoadRecipes() == 0)
        return 0;
    return 1;
}

// @0x14034de20
int CEnchantScrollTable::LoadScrolls()
{
    CString strPath = FUN_14071a5b0("Table", "enchantScroll.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 1;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("scroll"); pNode != 0; pNode = pNode->FUN_140168650("scroll"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        ScrollPtr data(new CEnchantScrollData);
        int nId = 0;
        FUN_1408731e0(pNode, "id", nId);
        if (data->Read(pNode) == 0)
            continue;
        m_scrolls.SetAt(nId, data);
    }
    return 1;
}

// @0x14034e0d0
int CEnchantScrollTable::LoadRecipes()
{
    CString strPath = FUN_14071a5b0("Table", "enchantScrollRecipe.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 1;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("recipe"); pNode != 0; pNode = pNode->FUN_140168650("recipe"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        RecipePtr data(new CEnchantScrollRecipe);
        if (data->Read(pNode) == 0)
            continue;
        m_recipes.SetAt(data->m_nId, data);
    }
    return 1;
}

// @0x14034e360
CEnchantScrollTable::ScrollPtr CEnchantScrollTable::FindScroll(unsigned nId)
{
    ScrollPtr data(0);
    m_scrolls.Lookup(nId, data);
    return data;
}

// @0x14034e3e0
CEnchantScrollTable::RecipePtr CEnchantScrollTable::FindRecipe(unsigned nId)
{
    RecipePtr data(0);
    m_recipes.Lookup(nId, data);
    return data;
}

// @0x14034e460
void CEnchantScrollTable::FindRecipes(int nType, int nSlot, int nRank, ATL::CAtlArray<RecipePtr>& rOut)
{
    for (POSITION pos = m_recipes.GetStartPosition(); pos != 0; m_recipes.GetNext(pos))
    {
        RecipePtr recipe = m_recipes.GetValueAt(pos);
        if (recipe->m_nSlot != nSlot)
            continue;
        if (recipe->m_nRecipeType != nType)
            continue;
        ScrollPtr scroll = FindScroll(recipe->m_nScrollId);
        if (scroll.IsNull())
            continue;
        if (scroll->GetMaxRank() != nRank)
            continue;
        rOut.Add(recipe);
    }
}

// @0x14034e5e0
int CEnchantScrollTable::HasRecipe(int nType, int nRank)
{
    for (POSITION pos = m_recipes.GetStartPosition(); pos != 0; m_recipes.GetNext(pos))
    {
        RecipePtr recipe = m_recipes.GetValueAt(pos);
        if (recipe->m_nRecipeType != nType)
            continue;
        ScrollPtr scroll = FindScroll(recipe->m_nScrollId);
        if (scroll.IsNull())
            continue;
        if (scroll->GetMaxRank() != nRank)
            continue;
        return 1;
    }
    return 0;
}

// @0x14034e730
int FUN_14034e730(Unk_140165cf0* pElem, const char* pszName, int* pnOut)
{
    if (FALSE)
    {
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 231), 0));
        return 2;
    }
    int nValue = 0;
    int nRet = FUN_140873890(pElem, pszName, nValue);
    if (nRet != 0)
        return nRet;
    *pnOut = nValue;
    return nRet;
}

MS2_REPLACE_METHOD(0x14034D190, CEnchantScrollData, Read, 461, 0x70CBE3B9);
MS2_REPLACE_METHOD(0x14034D370, CEnchantScrollData, GetMaxRank, 134, 0xB90A0214);
MS2_REPLACE_METHOD(0x14034D400, CEnchantScrollData, GetMinKey, 139, 0x9C389C75);
MS2_REPLACE_METHOD(0x14034D4A0, CEnchantScrollData, GetMaxKey, 128, 0x5ED7EB3A);
MS2_REPLACE_METHOD(0x14034E360, CEnchantScrollTable, FindScroll, 121, 0x9A814225);
MS2_REPLACE_METHOD(0x14034E3E0, CEnchantScrollTable, FindRecipe, 121, 0x2A6812D6);

// Full-executable aliases for existing enchant-scroll queries.
// MS2-PIN: ?GetRewardName@CEnchantScrollRecipe@@QEAA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x14034dbe0
// MS2-PIN: ?FUN_14034dbe0@Unk_MScrollRec@@QEAA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x14034dbe0
// MS2-PIN: ?FindRecipes@CEnchantScrollTable@@QEAAXHHHAEAV?$CAtlArray@V?$MS2Ptr@VCEnchantScrollRecipe@@@@V?$CElementTraits@V?$MS2Ptr@VCEnchantScrollRecipe@@@@@ATL@@@ATL@@@Z 0x14034e460
// MS2-PIN: ?FUN_14034e460@Unk_MScrollTable@@QEAAXHHHAEAV?$CAtlArray@V?$MS2Ptr@VUnk_MScrollRec@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_MScrollRec@@@@@ATL@@@ATL@@@Z 0x14034e460
// MS2-PIN: ?HasRecipe@CEnchantScrollTable@@QEAAHHH@Z 0x14034e5e0
// MS2-PIN: ?FUN_14034e5e0@Unk_MScrollTable@@QEAAHHH@Z 0x14034e5e0
