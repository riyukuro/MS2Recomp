// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemExchangeScrollTable: the item exchange scroll table
// (Table/ItemExchangeScrollTable.xml) and the CExchangeItemInfo rows it holds in an ATL::CAtlMap<unsigned, MS2Ptr<...>>.
// MS2-UNIT: ?\itemexchangescrolltable.cpp
// MS2-RANGE: 0x140595050-0x140596fb0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VCExchangeItemInfo@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCExchangeItemInfo@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x1405961b0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CItemExchangeScrollTable@@6B?$TSingleton@VCItemExchangeScrollTable@@@@@ 0x142d60de8
// MS2-PIN: ??_7CItemExchangeScrollTable@@6B?$CValidData@VCItemExchangeScrollTable@@@@@ 0x142d60df8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemexchangescrolltable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemexchangescrolltable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_CommonLog { public: void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg); };
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
bool FUN_14028f710(Unk_140165cf0* pElem);                   // the node is a usable element
int FUN_14015f500(Unk_140165cf0* pElem, const char* pszName, int* pOut);
ExchangeItemType FUN_14021a270(const CStringA& str);        // the "type" name -> enum

// The discount service chain: the discount rate (per 10000) of an item grade.
class Unk_140302b00 { public: };
class Unk_1403ed190 { public: int FUN_140428cb0(int nGrade); };
Unk_140302b00* FUN_140302b00();
Unk_1403ed190* FUN_1403ed190(Unk_140302b00* p);

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CItemExchangeScrollTable::s_bInit;
#endif

// The price with the discount rate (per 10000) applied.
// @0x1405957d0
static __int64 FUN_1405957d0(__int64 nMeso, unsigned int nRate);

// ---- CExchangeItemInfo ----

// @0x140595050
__int64 CExchangeItemInfo::GetMeso() const
{
    int nRate = FUN_1403ed190(FUN_140302b00())->FUN_140428cb0(m_nId);
    if (nRate == 0)
        return m_nMeso;
    return FUN_1405957d0(m_nMeso, nRate);
}

// @0x1405950b0
__int64 CExchangeItemInfo::GetTotalMeso(int nCount) const
{
    if (nCount < 1)
        return 0;
    return GetMeso() * nCount;
}

// ---- CItemExchangeScrollTable ----

// @0x1405950f0
CItemExchangeScrollTable::CItemExchangeScrollTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// MS2-FUNCTIONAL: the toolchain ATL CAtlMap::RemoveAll is not nothrow, so the implicitly-noexcept dtor gets a terminate EH frame (obj 119 vs exe 89 bytes, exe has no FuncInfo); same member/base dtor calls
// @0x140595190
CItemExchangeScrollTable::~CItemExchangeScrollTable()
{
    m_map.RemoveAll();
}

// @0x1405951f0
void CItemExchangeScrollTable::Load()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("ItemExchangeScrollTable.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("exchange"); pNode != 0; pNode = pNode->FUN_140168650("exchange"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        int nId = 0;
        FUN_1408731e0(pNode, "id", nId);
        CExchangeItemInfoPtr spInfo(new CExchangeItemInfo);
        spInfo->m_nId = nId;
        XmlEnumName<ExchangeItemType, FUN_14021a270>(pNode, "type", spInfo->m_eType);
        FUN_1408731e0(pNode, "maxGrade", spInfo->m_nMaxGrade);
        FUN_1408731e0(pNode, "tradableCountDeduction", spInfo->m_nTradableCountDeduction);
        Unk_140165cf0* pReceipe = pNode->FUN_140165cf0("receipe");
        if (pReceipe != 0)
        {
            FUN_140873220(pReceipe, "id", spInfo->m_receipe.m_nId);
            FUN_14015f500(pReceipe, "rank", &spInfo->m_receipe.m_nRank);
            FUN_1408731e0(pReceipe, "count", spInfo->m_receipe.m_nCount);
        }
        Unk_140165cf0* pExchange = pNode->FUN_140165cf0("exchange");
        if (pExchange != 0)
        {
            FUN_140873220(pExchange, "id", spInfo->m_exchange.m_nId);
            FUN_14015f500(pExchange, "rank", &spInfo->m_exchange.m_nRank);
            FUN_1408731e0(pExchange, "count", spInfo->m_exchange.m_nCount);
        }
        Unk_140165cf0* pEquip = pNode->FUN_140165cf0("requireEquip");
        if (pEquip != 0)
        {
            FUN_140873220(pEquip, "id", spInfo->m_requireEquip.m_nId);
            FUN_14015f500(pEquip, "rank", &spInfo->m_requireEquip.m_nRank);
            FUN_1408731e0(pEquip, "count", spInfo->m_requireEquip.m_nCount);
        }
        Unk_140165cf0* pRequire = pNode->FUN_140165cf0("require");
        if (pRequire != 0)
        {
            FUN_1408732e0(pRequire, "meso", spInfo->m_nMeso);
            for (Unk_140165cf0* pItem = pRequire->FUN_140165cf0("item"); pItem != 0; pItem = pItem->FUN_140168650("item"))
            {
                CStringW strItem;
                FUN_140873420(pItem, "id", strItem);
                spInfo->m_require.FUN_14026b9d0(strItem);
            }
        }
        m_map.SetAt(nId, spInfo);
    }
    SetInit(true);
}

// @0x140595750
CExchangeItemInfoPtr CItemExchangeScrollTable::GetData(unsigned int nId)
{
    CheckInit();
    CExchangeItemInfoPtr spInfo(0);
    m_map.Lookup(nId, spInfo);
    return spInfo;
}

// @0x1405957d0
static __int64 FUN_1405957d0(__int64 nMeso, unsigned int nRate)
{
    double dRate = 1.0 - (double)nRate / 10000.0;
    return (__int64)((double)nMeso * dRate + 1e-06);
}

// @0x140595ac0
CExchangeItemInfo::CExchangeItemInfo()
    : m_nId(0), m_eType(EXCHANGE_ITEM_TYPE_0), m_nMaxGrade(0), m_nMeso(0), m_nTradableCountDeduction(0)
{
}

// @0x140595b80
Unk_ExchangeItemRef::Unk_ExchangeItemRef()
    : m_nId(0), m_nRank(0), m_nCount(0)
{
}

// @0x140595cd0
CExchangeItemInfo::~CExchangeItemInfo()
{
}

// @0x140595ee0
void CItemExchangeScrollTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemExchangeScrollTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140596db0
void CItemExchangeScrollTable::SetInit(bool b)
{
    s_bInit = b;
}
