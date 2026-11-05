// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemRePackingScrollTable: the item re-packing scroll table
// (Table/itemRePackingScroll.xml) and the CItemRePackingScrollData rows it holds in an ATL::CAtlMap<int, MS2Ptr<...>>.
// MS2-UNIT: ?\itemrepackingscrolldata.cpp
// MS2-RANGE: 0x14061ce90-0x14061f540 .text$mn
// MS2-RANGE: 0x1400ba890-0x1400baa10 .text$di
// MS2-RANGE: 0x142c9b2b0-0x142c9b310 .text$yd
// MS2-PIN: ??_7CItemRePackingScrollTable@@6B?$TSingleton@VCItemRePackingScrollTable@@@@@ 0x142d6a3a8
// MS2-PIN: ??_7CItemRePackingScrollTable@@6B?$CValidData@VCItemRePackingScrollTable@@@@@ 0x142d6a3c8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemrepackingscrolldata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemrepackingscrolldata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int XmlGetBool(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873710
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
bool FUN_140634230(MS2Ptr<CItem> pItem);
__int64 GetServerTime();
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& rValue);

// The market sort-name tables the header (tinyxmlhelper enum names) gives every unit; two copies land here (0x143aaff68, 0x143aaffa0).
static CString s_sortNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CItemRePackingScrollTable::s_bInit;
#endif

// ---- CItemRePackingScrollData ----

// @0x14061ce90
CItemRePackingScrollData::CItemRePackingScrollData()
    : m_nId(0), m_nPet(0), m_nMinLv(0), m_nMaxLv(0)
{
}

// @0x14061cf20
CItemRePackingScrollData::~CItemRePackingScrollData()
{
    m_arrSlot.RemoveAll();
    m_arrRank.RemoveAll();
}

// ---- CItemRePackingScrollTable ----

// @0x14061cfa0
CItemRePackingScrollTable::CItemRePackingScrollTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14061d070
CItemRePackingScrollTable::~CItemRePackingScrollTable()
{
    m_map.RemoveAll();
}

// @0x14061d130
int CItemRePackingScrollTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "itemRePackingScroll.xml");
    FUN_1401d1160(strPath);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 1;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("rePackingScroll")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("rePackingScroll")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        CItemRePackingScrollDataPtr spData(new CItemRePackingScrollData);
        if (spData == 0)
            continue;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<int&>(spData->m_nId));
        XmlGetAttr((class TiXmlElement*)(pNode), "minLv", reinterpret_cast<unsigned short&>(spData->m_nMinLv));
        XmlGetAttr((class TiXmlElement*)(pNode), "maxLv", reinterpret_cast<unsigned short&>(spData->m_nMaxLv));
        XmlTokenList(pNode, "rank", spData->m_arrRank);
        XmlTokenList(pNode, "slot", spData->m_arrSlot);
        int nPetType = 0;
        XmlGetBool((class TiXmlElement*)(pNode), "petType", nPetType);
        if (nPetType == 1)
            spData->m_nPet = 1;
        if (Unk_LockGuard guard = m_lock) {}
        else
            m_map.SetAt(spData->m_nId, spData);
    }
    SetInit(true);
    return 1;
}

// @0x14061d530
int CItemRePackingScrollTable::Reload()
{
    int nRet = 0;
    if (Unk_LockGuard guard = m_lock) {}
    else
    {
        m_map.RemoveAll();
        nRet = Load();
    }
    return nRet;
}

// @0x14061d5b0
CItemRePackingScrollDataPtr CItemRePackingScrollTable::GetData(int nId)
{
    CheckInit();
    CItemRePackingScrollDataPtr spData(0);
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_map.Lookup(nId, spData);
    return spData;
}

// @0x14061d670
int CItemRePackingScrollTable::Check(MS2Ptr<CItem> pItem, CItemRePackingScrollDataPtr pData)
{
    if (pItem == 0)
        return 1;
    if (pData == 0)
        return 7;
    if (!((CItem*)pItem)->FUN_140528980() || ((CItem*)pItem)->FUN_140527030() != 0)
        return 2;
    CItemEnchantInfo* pEnchant = reinterpret_cast<CItemStatus*>(((CItem*)pItem)->FUN_1405278a0())->GetEnchant();
    if (pEnchant != 0 && !pEnchant->FUN_14058c9a0())
        return 10;
    MS2Ptr<CItemData> pItemData(((class CItemData*)((class CItem*)(class CItem*)(pItem))->FUN_140527840()));
    if (pItemData == 0)
        return 2;
    if (!pItemData->property.rePackingScrollID.IsEmpty())
    {
        int bFound = 0;
        for (unsigned i = 0; i < pItemData->property.rePackingScrollID.GetCount(); i++)
        {
            int nScroll = pItemData->property.rePackingScrollID[(size_t)i];
            if (nScroll == pData->m_nId)
            {
                bFound = 1;
                break;
            }
        }
        if (bFound == 0)
            return 1;
    }
    switch (pData->m_nPet)
    {
    case 0:
    {
        int nType = pItemData->GetEquipSubtype();
        if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(pData->m_arrSlot), nType) == -1)
            return 3;
        break;
    }
    case 1:
        if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xa4))
            return 7;
        if (!pItemData->IsPetItem())
            return 3;
        break;
    }
    int nRank = ((CItem*)pItem)->GetRarity();
    if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(pData->m_arrRank), nRank) == -1)
        return 4;
    int nLevel = pItemData->limit.levelLimit;
    if (nLevel < (int)pData->m_nMinLv || nLevel > (int)pData->m_nMaxLv)
        return 5;
    if (!pItemData->FUN_14053d800())
        return 8;
    if (((CItem*)pItem)->FUN_140527930() == 0)
        return 2;
    if (reinterpret_cast<CItemTransfer*>(((CItem*)pItem)->FUN_140527930())->GetCount() > 0)
        return 9;
    if (FUN_140634230(pItem))
        return 1;
    if (((CItem*)pItem)->GetRemainingRePackingCount() == 0)
        return 10;
    if (((CItem*)pItem)->FUN_140528ca0() == 1 || ((CItem*)pItem)->FUN_140528e00() > GetServerTime())
        return 0xb;
    return 0;
}

// @0x14061e350
void CItemRePackingScrollTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemRePackingScrollTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14061f220
void CItemRePackingScrollTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x14061f420
MS2_EMIT_CRT_MEMMOVE_S();
