// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUGCDesignTable: the UGC design table (Table/UGCDesign.xml)
// behind the UGC design / UGC shop UI, plus the CUGCDesignData rows it holds in an ATL::CAtlMap<unsigned, MS2Ptr<...>>.
// The unit also defines the UGC/cube point globals DAT_143ab2388 ("the none cell") and DAT_143ab2398 ("down vector")
// that cubemapinformationservice_3 / mypc / cubecraft_1 read.
// MS2-UNIT: ?\ugcdesigntable.cpp
// MS2-RANGE: 0x1400bdb40-0x1400bdde0 .text$di
// MS2-RANGE: 0x14089e270-0x1408a0190 .text$mn
// MS2-PIN: ??_7CUGCDesignTable@@6B?$TSingleton@VCUGCDesignTable@@@@@ 0x142da0370
// MS2-PIN: ??_7CUGCDesignTable@@6B?$CValidData@VCUGCDesignTable@@@@@ 0x142da0390
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcdesigntable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcdesigntable.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants methods
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- dynamic initializers (.text$di, in exe order) ----

// The 8-byte object the unit shares with the other table units (built by 0x1401cd100, "one integer" ctor).
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))


// @0x1400bdb40
static CStringA s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 143ab22b8
// @0x1400bdc00
Unk_Int3 DAT_143ab2388(0x80000000, 0x80000000, 0x80000000);         // "the none cell" of the cube maps
// @0x1400bdc30
Unk_Int3 DAT_143ab2398(0, 0, 0);                                     // the cube "down vector"
// @0x1400bdc50
static CStringA s_priceTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 143ab22f0
// @0x1400bdd10
CStringA s_skill("skill");                                          // 143ab2338
// @0x1400bdd40
CStringA s_stun("stun");                                            // 143ab2330
// @0x1400bdd70
egf::EntityID s_nullKey(0);                                       // 143ab2328
// @0x1400bdd90
ATL::CAtlMap<unsigned int, CStringA> s_saleTags(17, 0.75f, 0.25f, 2.25f, 10);   // 143ab2340

// The unit's init flag and the singleton pointer are exe globals (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CUGCDesignTable::s_bInit;
#endif

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view




bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
int XmlGetAttr(class TiXmlElement *, char const *, class ATL::CStringT<wchar_t, class StrTraitMFC_DLL<wchar_t, class ATL::ChTraitsCRT<wchar_t>>> &);
int FUN_14088da20(int nPriceType);                          // the xml priceType -> the runtime enum
enum eShopSaleTag { eShopSaleTag_None = 0 }; template <class E> int XmlValue(TiXmlElement*, const char*, E&);   // "saleTag"
   // the feature/locale singleton
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
class Unk_1401d3200;
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
__int64 FUN_1406a6d50(Common::Constants::Value<int>& value);   // the default market max price

// Defined below (0x14089fef0): the s_bInit setter the loader calls.
void FUN_14089fef0(bool bInit);

// ---- CUGCDesignData ----

// @0x14089ed40
CUGCDesignData::CUGCDesignData()
    : m_nItemID(0), m_nItemGrade(0), m_bVisible(false), m_nPriceType(1), m_nPrice(0), m_nSalePrice(0),
      m_nMarketMinPrice(0), m_nMarketMaxPrice(0), m_nSaleTag(0), m_nCategory(0), m_nDpOrder(0)
{
}

// @0x14089e270
bool CUGCDesignData::Parse(TiXmlElement* pElem, __int64 nDefaultMarketMaxPrice)
{
    if (pElem == 0)
        return false;
    int nItemGrade = 0;
    XmlGetAttr((class TiXmlElement*)(pElem), "itemGrade", nItemGrade);
    m_nItemGrade = nItemGrade;
    XmlGetAttr((class TiXmlElement*)(pElem), "visible", m_bVisible);
    int nPriceType = 0;
    XmlGetAttr((class TiXmlElement*)(pElem), "priceType", nPriceType);
    m_nPriceType = FUN_14088da20(nPriceType);
    XmlGetAttr((class TiXmlElement*)(pElem), "price", m_nPrice);
    XmlGetAttr((class TiXmlElement*)(pElem), "salePrice", m_nSalePrice);
    XmlGetAttr((class TiXmlElement*)(pElem), "marketMinPrice", m_nMarketMinPrice);
    XmlGetAttr((class TiXmlElement*)(pElem), "marketMaxPrice", m_nMarketMaxPrice);
    if (m_nMarketMaxPrice == 0)
        m_nMarketMaxPrice = nDefaultMarketMaxPrice;
    XmlGetAttr((class TiXmlElement*)(pElem), "dpOrder", m_nDpOrder);
    XmlGetAttr((class TiXmlElement*)(pElem), "category", m_nCategory);
    XmlValue(pElem, "saleTag", *(eShopSaleTag*)&m_nSaleTag);
    return true;
}
MS2_REPLACE_METHOD(0x14089E270, CUGCDesignData, Parse, 388, 0xC4EB28A7);

// ---- CUGCDesignTable ----

// @0x14089e400
CUGCDesignTable::CUGCDesignTable()
{
    // The literals convert implicitly (the exe builds the file name first: MSVC evaluates the arguments right to left).
    CString strPath = FUN_14071a5b0("Table", "UGCDesign.xml");
    FUN_1401d1160(strPath);
    Reload();
}

// @0x14089e590
CUGCDesignTable::~CUGCDesignTable()
{
}

// @0x14089e630
bool CUGCDesignTable::Reload()
{
    Clear();
    if (Unk_LockGuard guard = m_lock) {}
    else
    {
        TiXmlDocument doc;
        // The exe converts the cache's CString to const char* inline (no named pointer local).
        if (GetFileSystem()->FUN_1403974b0(&doc, *FUN_1401d1140(), 0, true, false) == 0)
            return false;
        TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
        if (pRoot == 0)
            return false;
        __int64 nDefaultMarketMaxPrice =
            FUN_1406a6d50(*reinterpret_cast<Common::Constants::Value<int>*>(reinterpret_cast<char*>(((class Unk_1401d3200*)GetClientConstants())) + 0x4660));
        for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("list")); pNode != 0;
             pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("list")))
        {
            if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
                continue;
            CStringW strLocale;
            XmlGetAttr((class TiXmlElement*)(pNode), "locale", strLocale);
            if (!TSingleton<CFeatureManager>::GetInstance()->IsLocaleInList(strLocale))
                continue;
            int nItemID = 0;
            XmlGetAttr((class TiXmlElement*)(pNode), "itemID", *(unsigned int*)&static_cast<int&>(nItemID));
            if (nItemID == 0)
                continue;
            CUGCDesignDataPtr spData(new CUGCDesignData);
            if (spData == 0)
                continue;
            spData->m_nItemID = nItemID;
            spData->Parse(pNode, nDefaultMarketMaxPrice);
            m_map.SetAt(nItemID, spData);
        }
        FUN_14089fef0(true);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14089E630, CUGCDesignTable, Reload, 790, 0x5A962346);

// @0x14089e950
bool CUGCDesignTable::Load()
{
    // The exe passes the CCacheData subobject through a reference cast: a plain `this` upcast would add a null check.
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)) != 0)
        return Reload();
    return true;
}
MS2_REPLACE_METHOD(0x14089E950, CUGCDesignTable, Load, 52, 0xF8103265);

// @0x14089e990
void CUGCDesignTable::Clear()
{
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_map.RemoveAll();
}
MS2_REPLACE_METHOD(0x14089E990, CUGCDesignTable, Clear, 90, 0xB3BAF2E3);

// @0x14089e9f0
CUGCDesignDataPtr CUGCDesignTable::GetData(unsigned int nItemID)
{
    if (m_map.IsEmpty())
        return 0;
    CUGCDesignDataPtr spData(0);
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_map.Lookup(nItemID, spData);
    return spData;
}
MS2_REPLACE_METHOD(0x14089E9F0, CUGCDesignTable, GetData, 228, 0x4D21A01F);

// @0x14089fef0
void FUN_14089fef0(bool bInit)
{
    CUGCDesignTable::s_bInit = bInit;
}

// @0x1408a0040 (the obj's unreferenced copy of the CRT's static-inline memmove_s)
MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c850-0x142c9c910 .text$yd
