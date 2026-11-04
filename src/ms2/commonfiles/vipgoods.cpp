// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CVIPTable: Table/vipGoodsTable.xml, vipBenefitItemTable.xml and
// vipBenefitEffectTable.xml (VIP membership goods, their bonus items and the VIP effects).
// MS2-UNIT: commonfiles\vipgoods.cpp
// MS2-RANGE: 0x1408f50a0-0x1408fb8c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??$FUN_14028dfa0@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBV01@1@Z 0x1408f71a0
// MS2-PIN: ??_7CVIPTable@@6B?$TSingleton@VCVIPTable@@@@@ 0x142da6f30
// MS2-PIN: ??_7CVIPTable@@6B?$CValidData@VCVIPTable@@@@@ 0x142da6f40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\vipgoods.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "vipgoods.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/wcformat.h"   // FUN_14028dfa0: string table text, formatted
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "additionalactionadditional.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/filesystem.h"
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
class Unk_XmlNode { public: class Unk_XmlNode * FirstChild(char const *); };
// Unrecovered helpers (the xml loader helpers the other table units use).
CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028faa0(struct Unk_XmlElement*, char const*, char const*, std::vector<struct Unk_XmlElement*>&);   // C3: retyped to the commonutil def
void FUN_14028fd90(struct Unk_XmlElement* pParent, const char* pszName, const char* pszAttr1, const char* pszAttr2,
                   std::vector<struct Unk_XmlElement*>& out);
int XmlGetAttr(class TiXmlElement*, char const*, class CMsTime&);   // C3: was FUN_140873600
int XmlGetAttr(class TiXmlElement *, char const *, class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> &);
int XmlQuery(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873890
enum eShopSaleTag { eShopSaleTag_None = 0 }; template <class E> int XmlValue(Unk_140165cf0*, const char*, E&);               // saleTag
enum eShopResetType { eShopResetType_None = 0 };               // buyLimitResetType
int Unk_ReadRank(class Unk_XmlNode*, char const*, int*);   // C3: was FUN_14015f500
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // C3: was FUN_140177e10 (CAtlArray<unsigned>), FUN_140177de0 (CAtlArray<int>)
void ParseInt64List(CString& str, ATL::CAtlArray<__int64>& rOut, const char* pszSep);   // 0x1402a5010 (conditionutil)
unsigned char FUN_1401d1320(CCacheData*);
CString FUN_14016a5c0(const char* psz, int n);
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string table text
CStringW FUN_140b8ec90(const CMsTime& time);                               // date text
CStringW FUN_1418fec00(int nType, __int64 nValue, bool);        // money text by pay type
CStringW FUN_1418fef90(int nType, __int64 nValue);

// The skill table (TSingleton<SkillDataTableCli>::GetInstance): finds the skill of a VIP effect.


#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton and init flag (symbols-manual.tsv)
CVIPTable* TSingleton<CVIPTable>::s_instance;
bool CVIPTable::s_bInit;
#endif

// @0x1408f50a0
CVIPGoods::CVIPGoods()
    : m_nId(0), m_n1c(0), m_salesStartDate(0), m_salesEndDate(0), m_nDisplayOrder(0),
      m_nPrice(0), m_nSalePrice(0), m_nSaleTag(0), m_nPriceType(VIP_PRICE_TYPE_0), m_nBuyLimit(0), m_nBuyLimitResetType(0)
{
}

// @0x1408f51c0
CVIPGoods::~CVIPGoods()
{
}

// @0x1408f5240
CStringW CVIPGoods::GetPriceText(int bShort)
{
    if (m_nSalePrice == 0)
    {
        CStringW strKey(L"s_vip_dialog_goods_free");
        return GetStringCommonByKey(strKey);
    }
    if (m_nPriceType == 0)
    {
        if (bShort != 0)
            return FUN_1418fef90(3, m_nSalePrice);
        return FUN_1418fec00(3, m_nSalePrice, false);
    }
    else if (m_nPriceType == 1)
    {
        if (bShort != 0)
            return FUN_1418fef90(9, m_nSalePrice);
        return FUN_1418fec00(9, m_nSalePrice, false);
    }
    return CStringW(L"");
}

// @0x1408f53c0
CStringW CVIPGoods::GetSalesPeriodText()
{
    if (HasSalesPeriod() == 0)
    {
        return CStringW(L"");
    }
    return FUN_14028dfa0(CStringW(L"s_vip_dialog_goods_sales_duration"), FUN_140b8ec90(CMsTime(m_salesStartDate)), FUN_140b8ec90(CMsTime(m_salesEndDate)));
}

// @0x1408f5510
int CVIPGoods::HasSalesPeriod()
{
    return m_salesStartDate != 0 && m_salesEndDate != 0;
}

// @0x1408f5590
int CVIPGoods::HasBuyLimit()
{
    return m_nBuyLimit != 0;
}

// @0x1408f55d0
CVIPBenefitItem::CVIPBenefitItem() : m_nId(0), m_nItemId(0), m_nItemCount(0), m_nItemRank(1), m_nItemPeriod(0)
{
}

// @0x1408f5640
CVIPBenefitItem::~CVIPBenefitItem()
{
}

// @0x1408f5670
CVIPBenefitEffect::CVIPBenefitEffect() : m_nEffectId(0), m_nEffectLevel(1)
{
}

// @0x1408f56c0
CVIPBenefitEffect::~CVIPBenefitEffect()
{
}

// @0x1408f56f0
CVIPTable::CVIPTable()
{
    Load();
}

// @0x1408f5850
CVIPTable::~CVIPTable()
{
}

// @0x1408f5930
int CVIPTable::Load()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (LoadGoods() == 0)
            return 0;
        if (LoadBenefitItems() == 0)
            return 0;
        if (LoadBenefitEffects() == 0)
            return 0;
    }
    SetInit(true);
    return 1;
}

// @0x1408f5a00
int CVIPTable::LoadGoods()
{
    m_goods.RemoveAll();
    m_goodsList.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "vipGoodsTable.xml");
    m_cacheGoods.AssignRaw(new CCacheData);
    m_cacheGoods.get()->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>((class Unk_140165cf0 *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0((struct Unk_XmlElement*)(pRoot), "goods", "id", *reinterpret_cast<std::vector<struct Unk_XmlElement*>*>(&nodes));
    for (unsigned __int64 i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        int nDisable = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "disable", reinterpret_cast<int&>(nDisable));
        if (nDisable == 1)
            continue;
        CVIPGoodsPtr spGoods(new CVIPGoods);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<unsigned int&>(spGoods->m_nId));
        XmlGetAttr((class TiXmlElement*)(pNode), "salesStartDate", spGoods->m_salesStartDate);
        XmlGetAttr((class TiXmlElement*)(pNode), "salesEndDate", spGoods->m_salesEndDate);
        XmlGetAttr((class TiXmlElement*)(pNode), "displayOrder", reinterpret_cast<unsigned int&>(reinterpret_cast<unsigned&>(spGoods->m_nDisplayOrder)));
        XmlGetAttr((class TiXmlElement*)(pNode), "vipPeriod", reinterpret_cast<__int64&>(spGoods->m_nVipPeriod));
        spGoods->m_nVipPeriod *= 3600;
        XmlGetAttr((class TiXmlElement*)(pNode), "price", reinterpret_cast<__int64&>(spGoods->m_nPrice));
        XmlGetAttr((class TiXmlElement*)(pNode), "salePrice", reinterpret_cast<__int64&>(spGoods->m_nSalePrice));
        XmlValue(pNode, "saleTag", *(eShopSaleTag*)&spGoods->m_nSaleTag);
        XmlValue(pNode, "priceType", spGoods->m_nPriceType);
        XmlGetAttr((class TiXmlElement*)(pNode), "buyLimit", reinterpret_cast<unsigned int&>(reinterpret_cast<unsigned&>(spGoods->m_nBuyLimit)));
        XmlValue(pNode, "buyLimitResetType", *(eShopResetType*)&spGoods->m_nBuyLimitResetType);
        CString strIds;
        XmlGetAttr((class TiXmlElement*)(pNode), "bonusItemID", strIds);
        XmlSplit(strIds, spGoods->m_bonusItemIds, ",");
        CString strRanks;
        XmlGetAttr((class TiXmlElement*)(pNode), "bonusItemRank", strRanks);
        ATL::CAtlArray<int> ranks;
        XmlSplit(strRanks, ranks, ",");
        for (unsigned n = 0; n < ranks.GetCount(); n++)
        {
            Unk_VipItemRank rank = static_cast<Unk_VipItemRank>(ranks[n]);
            spGoods->m_bonusItemRanks.Add(rank);
        }
        if (spGoods->m_bonusItemIds.GetCount() != spGoods->m_bonusItemRanks.GetCount())
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
            return 0;
        }
        CString strCounts;
        XmlGetAttr((class TiXmlElement*)(pNode), "bonusItemCount", strCounts);
        XmlSplit(strCounts, spGoods->m_bonusItemCounts, ",");
        if (spGoods->m_bonusItemIds.GetCount() != spGoods->m_bonusItemCounts.GetCount())
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
            return 0;
        }
        CString strPeriods;
        XmlGetAttr((class TiXmlElement*)(pNode), "bonusItemPeriod", strPeriods);
        ParseInt64List(strPeriods, spGoods->m_bonusItemPeriods, ",");
        if (spGoods->m_bonusItemIds.GetCount() != spGoods->m_bonusItemPeriods.GetCount())
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
            return 0;
        }
        m_goods.SetAt(spGoods->m_nId, spGoods);
        m_goodsList.Add(spGoods);
    }
    return 1;
}

// @0x1408f6460
int CVIPTable::LoadBenefitItems()
{
    m_benefitItems.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "vipBenefitItemTable.xml");
    m_cacheBenefitItems.AssignRaw(new CCacheData);
    m_cacheBenefitItems.get()->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>((class Unk_140165cf0 *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0((struct Unk_XmlElement*)(pRoot), "benefit", "id", *reinterpret_cast<std::vector<struct Unk_XmlElement*>*>(&nodes));
    for (unsigned __int64 i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        CVIPBenefitItemPtr spItem(new CVIPBenefitItem);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<unsigned int&>(spItem->m_nId));
        XmlGetAttr((class TiXmlElement*)(pNode), "itemID", reinterpret_cast<unsigned int&>(spItem->m_nItemId));
        XmlGetAttr((class TiXmlElement*)(pNode), "itemCount", reinterpret_cast<unsigned int&>(spItem->m_nItemCount));
        Unk_ReadRank((class Unk_XmlNode*)(pNode), "itemRank", &spItem->m_nItemRank);
        XmlGetAttr((class TiXmlElement*)(pNode), "itemPeriod", reinterpret_cast<__int64&>(spItem->m_nItemPeriod));
        m_benefitItems.SetAt(spItem->m_nId, spItem);
    }
    return 1;
}

// @0x1408f68b0
int CVIPTable::LoadBenefitEffects()
{
    m_benefitEffects.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "vipBenefitEffectTable.xml");
    m_cacheBenefitEffects.AssignRaw(new CCacheData);
    m_cacheBenefitEffects.get()->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>((class Unk_140165cf0 *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028fd90((struct Unk_XmlElement*)pRoot, "benefit", "effectID", "effectLevel", (std::vector<struct Unk_XmlElement*>&)nodes);
    for (unsigned __int64 i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        CVIPBenefitEffectPtr spEffect(new CVIPBenefitEffect);
        XmlGetAttr((class TiXmlElement*)(pNode), "effectID", reinterpret_cast<unsigned int&>(spEffect->m_nEffectId));
        XmlGetAttr((class TiXmlElement*)(pNode), "effectLevel", reinterpret_cast<unsigned short&>(spEffect->m_nEffectLevel));
        m_benefitEffects.Add(spEffect);
    }
    return 1;
}

// @0x1408f6c90
CVIPGoodsPtr CVIPTable::GetGoods(unsigned nId)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_cacheGoods.get()) != 0)
            LoadGoods();
        CVIPGoodsPtr spGoods(0);
        m_goods.Lookup(nId, spGoods);
        return spGoods;
    }
}

// @0x1408f6d80
CVIPBenefitItemPtr CVIPTable::GetBenefitItem(unsigned nId)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_cacheBenefitItems.get()) != 0)
            LoadBenefitItems();
        CVIPBenefitItemPtr spItem(0);
        m_benefitItems.Lookup(nId, spItem);
        return spItem;
    }
}

// @0x1408f6e80
void CVIPTable::GetBenefitEffects(ATL::CAtlArray<CVIPBenefitEffectPtr>& rOut)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_cacheBenefitEffects.get()) != 0)
            LoadBenefitEffects();
        rOut.Copy(m_benefitEffects);
    }
}

// @0x1408f6f20
void CVIPTable::GetBenefitItems(ATL::CAtlArray<CVIPBenefitItemPtr>& rOut)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_cacheBenefitItems.get()) != 0)
            LoadBenefitItems();
        for (POSITION pos = m_benefitItems.GetStartPosition(); pos != 0; m_benefitItems.GetNext(pos))
            rOut.Add(m_benefitItems.GetValueAt(pos));
    }
}

// @0x1408f7010
void CVIPTable::GetGoodsList(ATL::CAtlArray<CVIPGoodsPtr>& rOut)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_cacheGoods.get()) != 0)
            LoadGoods();
        rOut.Copy(m_goodsList);
    }
}

// @0x1408f70b0
MS2Ptr<AdditionalLevelData> CVIPTable::GetFirstEffect()
{
    ATL::CAtlArray<CVIPBenefitEffectPtr> effects;
    GetBenefitEffects(effects);
    if (effects.IsEmpty())
        return MS2Ptr<AdditionalLevelData>(0);
    return TSingleton<SkillDataTableCli>::GetInstance()/*C3:TSingleton<SkillDataTableCli>::GetInstance*/->FUN_140aafef0(effects[0]->m_nEffectId, effects[0]->m_nEffectLevel);
}

// @0x1408f86b0
void CVIPTable::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CVIPTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}
