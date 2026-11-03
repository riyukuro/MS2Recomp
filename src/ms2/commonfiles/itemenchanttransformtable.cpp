// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemEnchantTransformTable: Table/ItemEnchantTransform.xml, the
// item enchant transform rows (inputs, meso cost, outputs) and the lookups over them (see itemenchanttransformtable.h).
// MS2-UNIT: ?\itemenchanttransformtable.cpp
// MS2-RANGE: 0x140591330-0x1405942e0 .text$mn
// MS2-RANGE: 0x1400b9dd0-0x1400b9f50 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$Unk_SocketFormat@IIIW4EnchantTransformRank@@I@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBI11AEBW4EnchantTransformRank@@1@Z 0x140592730 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCEnchantTransformData@@@@V?$CStringElementTraitsI@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CDefaultCharTraits@D@2@@2@V?$CElementTraits@V?$MS2Ptr@VCEnchantTransformData@@@@@2@@ATL@@AEBAPEAVCNode@12@PEBDAEAI1AEAPEAV312@@Z 0x1405934d0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??$format_arg@DW4EnchantTransformRank@@@fmt@@YAXAEAV?$BasicFormatter@D@0@AEAPEBDAEBW4EnchantTransformRank@@@Z 0x140592b30
// MS2-PIN: ??_7?$TSingleton@VCItemEnchantTransformTable@@@@6B@ 0x142d60998
// MS2-PIN: ??_7?$CValidData@VCItemEnchantTransformTable@@@@6B@ 0x142d609a8
// MS2-PIN: ??_7CItemEnchantTransformTable@@6B?$TSingleton@VCItemEnchantTransformTable@@@@@ 0x142d609b8
// MS2-PIN: ??_7CItemEnchantTransformTable@@6B?$CValidData@VCItemEnchantTransformTable@@@@@ 0x142d609c8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemenchanttransformtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemenchanttransformtable.h"
#include <typeinfo>
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);                 // undecorated class name
unsigned char FUN_1401d1320(CCacheData* p);                             // file changed since load
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
__int64 GetServerTime();                                                // the server time

// The header statics of this unit (the sort name tables every item table unit carries).
#ifndef MS2_HOOK_DLL
static const CString s_enchantSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static const CString s_enchantShopSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CItemEnchantTransformTable::s_bInit;
#endif

// @0x140591330
CEnchantTransformData::CEnchantTransformData()
    : m_nNeedMeso(0)
{
}

// @0x1405913b0
CEnchantTransformData::~CEnchantTransformData()
{
}

// @0x140591410
CItemEnchantTransformTable::CItemEnchantTransformTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10), m_mapLimit(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140591510
CItemEnchantTransformTable::~CItemEnchantTransformTable()
{
}

// @0x1405915b0
int CItemEnchantTransformTable::Init()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (LoadItemEnchantTransform() == 0)
            return 0;
    }
    SetInit(true);
    return 1;
}

// @0x140591630
int CItemEnchantTransformTable::LoadItemEnchantTransform()
{
    m_map.RemoveAll();
    m_mapLimit.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "ItemEnchantTransform.xml");
    m_spCache.AssignRaw(new CCacheData);
    m_spCache->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("transform"); pNode != 0; pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("transform")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        unsigned nInputRank = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "inputRank", nInputRank);
        if (nInputRank == 0)
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
            return 0;
        }
        unsigned nInputLimitLevel = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "inputLimitLevel", nInputLimitLevel);
        unsigned nInputEnchantLevel = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "inputEnchantLevel", nInputEnchantLevel);
        CString strSlot;
        XmlGetAttr((class TiXmlElement*)(pNode), "inputSlot", strSlot);
        ATL::CAtlArray<unsigned> arrSlot;
        XmlSplitImpl(strSlot, arrSlot, ",");
        if (arrSlot.IsEmpty())
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
            return 0;
        }
        CString strItemId;
        XmlGetAttr((class TiXmlElement*)(pNode), "inputItemId", strItemId);
        ATL::CAtlArray<unsigned> arrItemId;
        XmlSplitImpl(strItemId, arrItemId, ",");
        if (arrItemId.IsEmpty())
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
            return 0;
        }
        for (unsigned i = 0; i < arrItemId.GetCount(); i++)
        {
            unsigned nItemId = arrItemId[i];
            unsigned nLowest = 0xffffffff;
            m_mapLimit.Lookup(nItemId, nLowest);
            if (nLowest > nInputEnchantLevel)
                m_mapLimit.SetAt(nItemId, nInputEnchantLevel);
        }
        CEnchantTransformDataPtr spData(new CEnchantTransformData);
        XmlGetAttr((class TiXmlElement*)(pNode), "needMeso", spData->m_nNeedMeso);
        unsigned nOutput1Id = 0;
        unsigned nOutput1Rank = 0;
        unsigned nOutput1Count = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "output1Id", nOutput1Id);
        XmlGetAttr((class TiXmlElement*)(pNode), "output1Rank", nOutput1Rank);
        XmlGetAttr((class TiXmlElement*)(pNode), "output1Count", nOutput1Count);
        if (nOutput1Id == 0 || nOutput1Rank == 0 || nOutput1Count == 0)
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
            return 0;
        }
        spData->m_arrOutputId.Add(nOutput1Id);
        spData->m_arrOutputRank.Add(nOutput1Rank);
        spData->m_arrOutputCount.Add(nOutput1Count);
        unsigned nOutput2Id = 0;
        unsigned nOutput2Rank = 0;
        unsigned nOutput2Count = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "output2Id", nOutput2Id);
        XmlGetAttr((class TiXmlElement*)(pNode), "output2Rank", nOutput2Rank);
        XmlGetAttr((class TiXmlElement*)(pNode), "output2Count", nOutput2Count);
        if (nOutput2Id != 0 && nOutput2Rank != 0 && nOutput2Count != 0)
        {
            spData->m_arrOutputId.Add(nOutput2Id);
            spData->m_arrOutputRank.Add(nOutput2Rank);
            spData->m_arrOutputCount.Add(nOutput2Count);
        }
        for (unsigned i = 0; i < arrSlot.GetCount(); i++)
        {
            for (unsigned j = 0; j < arrItemId.GetCount(); j++)
            {
                CString strKey = MakeKey(arrItemId[j], (EnchantTransformRank)nInputRank, nInputLimitLevel, nInputEnchantLevel, arrSlot[i]);
                m_map.SetAt(strKey, spData);
            }
        }
    }
    return 1;
}

// @0x140592090
CString CItemEnchantTransformTable::MakeKey(unsigned int nItemId, EnchantTransformRank eRank, unsigned int nLimitLevel, unsigned int nEnchantLevel, unsigned int nSlot)
{
    return Unk_SocketFormat("{0}-{1}-{2}-{3}-(4)", nItemId, nSlot, nEnchantLevel, eRank, nLimitLevel);
}

// @0x140592110
int CItemEnchantTransformTable::FUN_140592110(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return 0;
    CEnchantTransformDataPtr spData = GetInstance()->Find(spItem->FUN_1405276c0(), (EnchantTransformRank)spItem->GetRarity(),
        spItem->GetRequiredLevel(), spItem->FUN_140526fc0(), reinterpret_cast<CItemData*>(spItem->FUN_140527840())->GetEquipSubtype());
    if (spData == 0)
        return 0;
    if (spItem->FUN_140528ca0() == 0)
    {
        if (spItem->FUN_140528e00() > GetServerTime())
            return 0;
    }
    if (spItem->FUN_140528ca0() == 1)
        return 0;
    return 1;
}

// @0x140592330
CEnchantTransformDataPtr CItemEnchantTransformTable::FindByKey(const CString& strKey)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_spCache.operator->()) != 0)
            LoadItemEnchantTransform();
        CEnchantTransformDataPtr spData(0);
        m_map.Lookup(strKey, spData);
        return spData;
    }
}

// @0x140592430
CEnchantTransformDataPtr CItemEnchantTransformTable::Find(int nItemId, EnchantTransformRank eRank, int nLimitLevel, int nEnchantLevel, int nSlot)
{
    CString strKey = MakeKey(nItemId, eRank, nLimitLevel, nEnchantLevel, nSlot);
    return FindByKey(strKey);
}

// @0x1405924d0
CEnchantTransformDataPtr CItemEnchantTransformTable::FindByItem(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return CEnchantTransformDataPtr(0);
    return Find(spItem->FUN_1405276c0(), (EnchantTransformRank)spItem->GetRarity(), spItem->GetRequiredLevel(),
                         spItem->FUN_140526fc0(), reinterpret_cast<CItemData*>(spItem->FUN_140527840())->GetEquipSubtype());
}

// @0x140592620
unsigned int CItemEnchantTransformTable::GetLowestLimitLevel(unsigned int nItemId)
{
    CheckInit();
    unsigned int nLowest = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (FUN_1401d1320(m_spCache.operator->()) != 0)
            LoadItemEnchantTransform();
        m_mapLimit.Lookup(nItemId, nLowest);
    }
    return nLowest;
}

// @0x1405931f0
void CItemEnchantTransformTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemEnchantTransformTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1405940e0
void CItemEnchantTransformTable::SetInit(bool b)
{
    s_bInit = b;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9afc0-0x142c9b020 .text$yd
