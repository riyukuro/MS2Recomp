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
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int Unk_ReadRank(class Unk_XmlNode*, char const*, int*);   // C3: was FUN_14015f500
int Parse_14021a270(const CStringA& value);                 // commonenum.cpp: the "type" name -> enum (C3: was FUN_14021a270)

// The discount service chain: the discount rate (per 10000) of an item grade.
class Unk_140302b00 { public: };
class CGameEventValueExchangeScrollSale { public: int Get(unsigned long); }; class Unk_1403ed190 : public CGameEventValueExchangeScrollSale { };

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CItemExchangeScrollTable::s_bInit;
#endif

// The price with the discount rate (per 10000) applied.
// @0x1405957d0
__int64 FUN_1405957d0(__int64 nMeso, unsigned int nRate);

// ---- CExchangeItemInfo ----

// @0x140595050
__int64 CExchangeItemInfo::GetMeso() const
{
    int nRate = ((class Unk_1403ed190*)((class CGameEventValueManager*)(class Unk_140302b00*)(reinterpret_cast<Unk_140302b00*>(TSingleton<CGameEventValueManager>::GetInstance())))->GetExchangeScrollSale())->Get(m_nId);
    if (nRate != 0)
        return FUN_1405957d0(m_nMeso, nRate);
    return m_nMeso;
}

// @0x1405950b0
__int64 CExchangeItemInfo::GetTotalMeso(int nCount) const
{
    if (nCount <= 0)
        return 0;
    __int64 nTotal = GetMeso() * nCount;
    return nTotal;
}

// ---- CItemExchangeScrollTable ----

// @0x1405950f0
CItemExchangeScrollTable::CItemExchangeScrollTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140595190
CItemExchangeScrollTable::~CItemExchangeScrollTable()
{
}

// @0x1405951f0
void CItemExchangeScrollTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "ItemExchangeScrollTable.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    TiXmlElement* pRoot = reinterpret_cast<TiXmlElement*>((class TiXmlElement *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("exchange")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("exchange")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        int nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<int&>(nId));
        CExchangeItemInfoPtr spInfo(new CExchangeItemInfo);
        spInfo->m_nId = nId;
        XmlEnumName<int, Parse_14021a270>(pNode, "type", reinterpret_cast<int&>(spInfo->m_eType));
        XmlGetAttr((class TiXmlElement*)(pNode), "maxGrade", reinterpret_cast<int&>(spInfo->m_nMaxGrade));
        XmlGetAttr((class TiXmlElement*)(pNode), "tradableCountDeduction", reinterpret_cast<int&>(spInfo->m_nTradableCountDeduction));
        TiXmlElement* pReceipe = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("receipe"));
        if (pReceipe != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pReceipe), "id", spInfo->m_receipe.m_nId);
            Unk_ReadRank((class Unk_XmlNode*)(pReceipe), "rank", &spInfo->m_receipe.m_nRank);
            XmlGetAttr((class TiXmlElement*)(pReceipe), "count", reinterpret_cast<int&>(spInfo->m_receipe.m_nCount));
        }
        TiXmlElement* pExchange = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("exchange"));
        if (pExchange != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pExchange), "id", spInfo->m_exchange.m_nId);
            Unk_ReadRank((class Unk_XmlNode*)(pExchange), "rank", &spInfo->m_exchange.m_nRank);
            XmlGetAttr((class TiXmlElement*)(pExchange), "count", reinterpret_cast<int&>(spInfo->m_exchange.m_nCount));
        }
        TiXmlElement* pEquip = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("requireEquip"));
        if (pEquip != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pEquip), "id", spInfo->m_requireEquip.m_nId);
            Unk_ReadRank((class Unk_XmlNode*)(pEquip), "rank", &spInfo->m_requireEquip.m_nRank);
            XmlGetAttr((class TiXmlElement*)(pEquip), "count", reinterpret_cast<int&>(spInfo->m_requireEquip.m_nCount));
        }
        TiXmlElement* pRequire = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("require"));
        if (pRequire != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pRequire), "meso", reinterpret_cast<__int64&>(spInfo->m_nMeso));
            for (TiXmlElement* pItem = ((class TiXmlElement*)((class Unk_XmlNode*)(pRequire))->FirstChild("item")); pItem != 0; pItem = ((class TiXmlElement*)((class Unk_XmlNode*)(pItem))->NextSibling("item")))
            {
                CStringW strItem;
                XmlGetAttr((class TiXmlElement*)(pItem), "id", strItem);
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
__int64 FUN_1405957d0(__int64 nMeso, unsigned int nRate)
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
