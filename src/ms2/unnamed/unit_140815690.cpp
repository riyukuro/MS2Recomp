// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSmartRecommendShopTable (smartRecommendShop.xml) with its
// CRecommendItem rows and the CRecommendTableCache (Unk_SmartRecommendShops) holding the code -> row map
// (ATL::CAtlMap<unsigned, MS2Ptr<CRecommendItem>>); see ms2/placeholder/csmartrecommendshoptable.h.
// MS2-UNIT: unit_140815690
// MS2-RANGE: 0x140815690-0x1408179d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7Unk_SmartRecommendShops@@6B@ 0x142d95648
// MS2-PIN: ??1CRecommendItem@@UEAA@XZ 0x1408165d0
// MS2-PIN: ??_GCRecommendItem@@UEAAPEAXI@Z 0x140816770
// MS2-PIN: ??1Unk_SmartRecommendShops@@UEAA@XZ 0x140816620
// MS2-PIN: ??_GUnk_SmartRecommendShops@@UEAAPEAXI@Z 0x1408167b0
//
// File name assumed (the unit has no assert path).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\smartrecommendshoptable.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/csmartrecommendshoptable.h"

#include <typeinfo>
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_RsLoader { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_RsLoader* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const CString& strArg);
class Unk_RsItemTable { public: void FUN_1405f5e90(int nCode, int nRank, CString strTag, CString strInfo); };
Unk_RsItemTable* FUN_140166430();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);                 // undecorated class name
unsigned char FUN_1401d1320(CCacheData* p);                             // file changed since load
int FUN_140873220(Unk_140165cf0* pNode, const char* pszName, unsigned& rOut);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& rOut);
int FUN_14015f500(Unk_140165cf0* pNode, const char* pszName, int* pOut);        // itemRank
int FUN_1408732e0(Unk_140165cf0* pNode, const char* pszName, __int64& rOut);
int FUN_140873420(Unk_140165cf0* pNode, const char* pszName, CStringW& rOut);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CSmartRecommendShopTable::s_bInit;
#endif

// @0x140815690
int CSmartRecommendShopTable::FUN_140815690()
{
    m_spData.AssignRaw(new Unk_SmartRecommendShops);
    CString strPath = FUN_14071a5b0("Table", "smartRecommendShop.xml");
    m_bLoaded = 0;
    if (FUN_140815ac0(CString(strPath)) != 0)
        m_bLoaded = 1;
    if (m_bLoaded != 0)
        SetInit(true);
    return m_bLoaded;
}
MS2_REPLACE_METHOD(0x140815690, CSmartRecommendShopTable, FUN_140815690, 329, 0xD02E9B63);

// @0x1408157e0
int CSmartRecommendShopTable::FUN_1408157e0(CString strPath)
{
    return 1;
}
MS2_REPLACE_METHOD(0x1408157E0, CSmartRecommendShopTable, FUN_1408157e0, 42, 0x1D9326F7);

// @0x140815810
void CSmartRecommendShopTable::FUN_140815810()
{
    if (Unk_LockGuard guard = m_spData->m_lock)
    {
    }
    else
    {
        m_spData->m_items.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x140815810, CSmartRecommendShopTable, FUN_140815810, 114, 0x00B29241);

// @0x140815890
// MS2-FUNCTIONAL: trailing cleanup NOP after the lock-guard else path / EH ip2state boundary
MS2Ptr<CRecommendItem> CSmartRecommendShopTable::FUN_140815890(int nCode)
{
    CheckInit();
    if (Unk_LockGuard guard = m_spData->m_lock)
    {
    }
    else
    {
        if (FUN_1401d1320(m_spData.operator->()) != 0)
        {
            if (FUN_140815ac0(CString(*m_spData->FUN_1401d1140())) == 0)
                return MS2Ptr<CRecommendItem>(0);
        }
        MS2Ptr<CRecommendItem> spItem(0);
        m_spData->m_items.Lookup(nCode, spItem);
        return spItem;
    }
}
MS2_REPLACE_METHOD(0x140815890, CSmartRecommendShopTable, FUN_140815890, 364, 0xA094458D);

// @0x140815a10
// MS2-FUNCTIONAL: `this->m_spData` is reached through rax+mov rcx instead of the exe's direct add rcx,0x10 (no source form found)
void CSmartRecommendShopTable::FUN_140815a10(MS2Ptr<CRecommendItem> spItem)
{
    if (Unk_LockGuard guard = m_spData->m_lock)
    {
    }
    else
    {
        CRecommendItem* pItem = spItem.operator->();
        m_spData->m_items.SetAt(pItem->m_nCode, spItem);
    }
}
MS2_REPLACE_METHOD(0x140815A10, CSmartRecommendShopTable, FUN_140815a10, 155, 0x3D6FB2DA);

// @0x140815ac0
// MS2-FUNCTIONAL: trailing cleanup NOP after the lock-guard else path (ip2state boundary)
int CSmartRecommendShopTable::FUN_140815ac0(CString strPath)
{
    if (Unk_LockGuard guard = m_spData->m_lock)
    {
    }
    else
    {
        m_spData->m_items.RemoveAll();
        TiXmlDocument doc;
        if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
            return 0;
        m_spData->FUN_1401d1160(CString(strPath));
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
            return 0;
        }
        for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("recommend"); pNode != 0; pNode = pNode->FUN_140168650("recommend"))
        {
            MS2Ptr<CRecommendItem> spItem(new CRecommendItem);
            FUN_140873220(pNode, "code", spItem->m_nCode);
            FUN_140873220(pNode, "itemID", spItem->m_nItemId);
            FUN_14015f500(pNode, "itemRank", &spItem->m_nItemRank);
            FUN_1408731e0(pNode, "itemCount", spItem->m_nItemCount);
            FUN_140873420(pNode, "itemDescription", spItem->m_strItemDescription);
            FUN_140873420(pNode, "storeDescription", spItem->m_strStoreDescription);
            FUN_140873420(pNode, "buyButtonText", spItem->m_strBuyButtonText);
            FUN_1408731e0(pNode, "npcImageType", spItem->m_nNpcImageType);
            FUN_1408732e0(pNode, "requireMoney", spItem->m_nRequireMoney);
            FUN_140873220(pNode, "requireItemID", spItem->m_nRequireItemId);
            FUN_14015f500(pNode, "requireItemRank", &spItem->m_nRequireItemRank);
            FUN_1408731e0(pNode, "requireItemCount", spItem->m_nRequireItemCount);
            m_spData->m_items.SetAt(spItem->m_nCode, spItem);
            CString strCode;
            strCode.Format("code=%u", spItem->m_nCode);
            FUN_140166430()->FUN_1405f5e90(spItem->m_nItemId, spItem->m_nItemRank, CString("recommendItem smartRecommendShop.xml"), CString(strCode));
            FUN_140166430()->FUN_1405f5e90(spItem->m_nRequireItemId, spItem->m_nRequireItemRank, CString("requireItem smartRecommendShop.xml"), CString(strCode));
        }
        return 1;
    }
}
MS2_REPLACE_METHOD(0x140815AC0, CSmartRecommendShopTable, FUN_140815ac0, 1687, 0xFD880C5C);

// @0x1408163a0
CRecommendItem::CRecommendItem()
    : m_nCode(0), m_nItemId(0), m_nItemRank(1), m_nItemCount(0), m_nNpcImageType(0), m_nRequireMoney(0),
      m_nRequireItemId(0), m_nRequireItemRank(1), m_nRequireItemCount(0)
{
}

// @0x140816470
Unk_SmartRecommendShops::Unk_SmartRecommendShops()
    : m_items(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1408167f0
void CSmartRecommendShopTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CSmartRecommendShopTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1408176c0
void CSmartRecommendShopTable::SetInit(bool b)
{
    s_bInit = b;
}
