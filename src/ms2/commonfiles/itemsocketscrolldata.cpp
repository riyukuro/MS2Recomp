// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemSocketScrollTable: the item socket scroll table
// (Table/itemSocketScroll.xml) and the CItemSocketScrollData rows it holds in an ATL::CAtlMap<unsigned, MS2Ptr<...>>.
// MS2-UNIT: ?\itemsocketscrolldata.cpp
// MS2-RANGE: 0x140624700-0x140626a20 .text$mn
// MS2-PIN: ??_7CItemSocketScrollTable@@6B?$TSingleton@VCItemSocketScrollTable@@@@@ 0x142d6b008
// MS2-PIN: ??_7CItemSocketScrollTable@@6B?$CValidData@VCItemSocketScrollTable@@@@@ 0x142d6b028
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VCItemSocketScrollData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItemSocketScrollData@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x140625b00 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemsocketscrolldata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemsocketscrolldata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

bool FUN_14028f710(Unk_140165cf0* pElem);                   // the node is a usable element
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CItemSocketScrollTable::s_bInit;
#endif

// ---- CItemSocketScrollData ----

// @0x140624700
CItemSocketScrollData::CItemSocketScrollData()
    : m_eType(ITEM_SOCKET_SCROLL_TYPE_0), m_nUnk1c(1), m_nMinLv(0), m_nMaxLv(0), m_bTradableCountDeduction(false)
{
}

// @0x140624790
CItemSocketScrollData::~CItemSocketScrollData()
{
    m_arrSlot.RemoveAll();
    m_arrRank.RemoveAll();
}

// @0x140624810
void CItemSocketScrollData::Read(Unk_140165cf0* pElem)
{
    ItemSocketScrollType eType = ITEM_SOCKET_SCROLL_TYPE_0;
    XmlValue(pElem, "type", eType);
    m_eType = eType;
    FUN_1408731a0(pElem, "minLv", m_nMinLv);
    FUN_1408731a0(pElem, "maxLv", m_nMaxLv);
    XmlTokenList(pElem, "slot", m_arrSlot);
    XmlTokenList(pElem, "rank", m_arrRank);
    FUN_1408730a0(pElem, "tradableCountDeduction", m_bTradableCountDeduction);
    CString strUsePart;
    if (FUN_1408733e0(pElem, "usePart", strUsePart) == 0)
    {
        strUsePart.Trim();
        if (!strUsePart.IsEmpty())
        {
            ATL::CAtlArray<int> arrParts;
            XmlSplitImpl(strUsePart, arrParts, ",");
            if (!arrParts.IsEmpty())
            {
                size_t nCount = arrParts.GetCount();
                unsigned int nUsePart = 0;
                for (size_t i = 0; i < nCount; ++i)
                {
                    unsigned int nPart = arrParts[i];
                    if (0 < (int)nPart)
                        nUsePart |= nPart;
                }
            }
        }
    }
}

// ---- CItemSocketScrollDataServer ----

// @0x140624a10
CItemSocketScrollDataServer::CItemSocketScrollDataServer()
    : m_nSuccessProb(0), m_nOpenCount(0)
{
}

// @0x140624a80
CItemSocketScrollDataServer::~CItemSocketScrollDataServer()
{
}

// @0x140624ac0
void CItemSocketScrollDataServer::Read(Unk_140165cf0* pElem)
{
    CItemSocketScrollData::Read(pElem);
    if (m_eType == ITEM_SOCKET_SCROLL_TYPE_1)
    {
        FUN_140873220(pElem, "successProb", m_nSuccessProb);
        FUN_140873220(pElem, "openCount", m_nOpenCount);
    }
}

// ---- CItemSocketScrollTable ----

// @0x140624b30
CItemSocketScrollTable::CItemSocketScrollTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140624c00
CItemSocketScrollTable::~CItemSocketScrollTable()
{
    m_map.RemoveAll();
}

// @0x140624cc0
int CItemSocketScrollTable::Load()
{
    CString strDir;
    strDir = "Table";
    CString strPath = FUN_14071a5b0(strDir, "itemSocketScroll.xml");
    FUN_1401d1160(strPath);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 1;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    const CString& strTag = CString("scroll");
    const CString& strKey = CString("id");
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0(strTag); pNode != 0; pNode = pNode->FUN_140168650(strTag))
    {
        if (!FUN_14028f710(pNode))
            continue;
        int nId = 0;
        FUN_1408731e0(pNode, strKey, nId);
        if (nId == 0)
            continue;
        CItemSocketScrollDataPtr spData(new CItemSocketScrollData);
        if (spData == 0)
            continue;
        spData->Read(pNode);
        if (Unk_LockGuard guard = m_lock) {}
        else
            m_map.SetAt(nId, spData);
    }
    SetInit(true);
    return 1;
}

// @0x1406250e0
int CItemSocketScrollTable::Reload()
{
    int nRet = 0;
    if (Unk_LockGuard guard = m_lock) {}
    else if (FUN_1401d1320(&static_cast<CCacheData&>(*this)) != 0)
    {
        m_map.RemoveAll();
        nRet = Load();
    }
    return nRet;
}
MS2_REPLACE_METHOD(0x1406250E0, CItemSocketScrollTable, Reload, 139, 0x4A325FA5);

// @0x140625180
CItemSocketScrollDataPtr CItemSocketScrollTable::GetData(unsigned int nId)
{
    CheckInit();
    CItemSocketScrollDataPtr spData(0);
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_map.Lookup(nId, spData);
    return spData;
}
MS2_REPLACE_METHOD(0x140625180, CItemSocketScrollTable, GetData, 176, 0xA845BAE0);

// @0x140625830
void CItemSocketScrollTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemSocketScrollTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140626700
void CItemSocketScrollTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x140626900
MS2_EMIT_CRT_MEMMOVE_S();
