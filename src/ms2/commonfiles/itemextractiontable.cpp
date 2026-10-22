// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemExtractionTable: the item extraction table
// (Table/itemExtraction.xml) and the CExtractionItemInfo rows it holds in an ATL::CAtlMap<unsigned, MS2Ptr<...>>.
// MS2-UNIT: ?\itemextractiontable.cpp
// MS2-RANGE: 0x140596fb0-0x140598b80 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1CExtractionItemInfo@@UEAA@XZ 0x140597920
// MS2-PIN: ??_GCExtractionItemInfo@@UEAAPEAXI@Z 0x140597a70
// MS2-PIN: ??_7CItemExtractionTable@@6B?$TSingleton@VCItemExtractionTable@@@@@ 0x142d61088
// MS2-PIN: ??_7CItemExtractionTable@@6B?$CValidData@VCItemExtractionTable@@@@@ 0x142d61098
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemextractiontable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemextractiontable.h"
#include "logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml wrappers the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>

// @0x140596fb0
CExtractionItemInfo::CExtractionItemInfo()
    : m_nScrollCount(0), m_nTargetItemId(0), m_nResultItemId(0)
{
}

// @0x140597010
CItemExtractionTable::CItemExtractionTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1405970d0
CItemExtractionTable::~CItemExtractionTable()
{
}

// @0x140597150
void CItemExtractionTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "itemExtraction.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        CExtractionItemInfoPtr spInfo(new CExtractionItemInfo);
        FUN_140873220(pNode, "ScrollCount", spInfo->m_nScrollCount);
        FUN_140873220(pNode, "TargetItemID", spInfo->m_nTargetItemId);
        FUN_140873220(pNode, "ResultItemID", spInfo->m_nResultItemId);
        if (spInfo->m_nScrollCount < 1)
        {
            FUN_14015eb90(GetLogString(), 2, 0x13, L"값이 0 입니다.[<ms2> {0}][ScrollCount]", strPath);
            continue;
        }
        m_map.SetAt(spInfo->m_nTargetItemId, spInfo);
    }
}

// @0x140597430
int CItemExtractionTable::HasRow(unsigned int nTargetItemId)
{
    CExtractionItemInfoPtr spInfo(0);
    if (m_map.Lookup(nTargetItemId, spInfo))
        return 1;
    return 0;
}

// @0x1405974b0
unsigned int CItemExtractionTable::GetResultItemId(unsigned int nTargetItemId)
{
    CExtractionItemInfoPtr spInfo(0);
    if (m_map.Lookup(nTargetItemId, spInfo))
        return spInfo->m_nResultItemId;
    return 0;
}

// @0x140597540
int CItemExtractionTable::IsTarget(unsigned int nTargetItemId)
{
    if (m_map.Lookup(nTargetItemId))
        return 1;
    return 0;
}

// @0x140597580
CExtractionItemInfoPtr CItemExtractionTable::GetData(unsigned int nTargetItemId)
{
    CExtractionItemInfoPtr spInfo(0);
    m_map.Lookup(nTargetItemId, spInfo);
    return spInfo;
}

