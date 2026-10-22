// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CInstrumentData / CInstrumentCategoryData rows and the
// CInstrumentDataTable that loads them (Table/InstrumentInfo.xml, Table/InstrumentCategoryInfo.xml), plus the ATL
// CAtlMap<int, MS2Ptr<...>> template glue. Names are invented from use.
// MS2-UNIT: unit_14072bdc0
// MS2-PIN: ??_7CInstrumentDataTable@@6B?$TSingleton@VCInstrumentDataTable@@@@@ 0x142d83468
// MS2-PIN: ??_7CInstrumentDataTable@@6B?$CValidData@VCInstrumentDataTable@@@@@ 0x142d83478
// MS2-RANGE: 0x14072bdc0-0x14072f7f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml / string table wrappers the other table units share) ----
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pNode);                                   // node is enabled for this client
CStringW FUN_14028b8e0(const CStringW& strKey);                             // string table text
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);          // formats one number argument into the message
CString FUN_14016a5c0(const char* pszName, int nFlags);                     // undecorated class name

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CInstrumentDataTable::s_bInit;
#endif

// @0x14072bdc0
CInstrumentData::CInstrumentData(Unk_140165cf0* pNode)
    : m_nId(0), m_nCategory(0), m_bExpensive(false), m_strAsset(), m_nEquipItemId(0), m_nSoloRelayScoreCount(1),
      m_strReadyEffect(), m_strPlayEffect(), m_strAnimationReady(), m_strAnimationPlayIdle(),
      m_strAnimationPlayLevel1(), m_strAnimationPlayLevel2(), m_strAnimationPlayLevel3(), m_strAnimationPlayLevel4()
{
    FUN_1408731e0(pNode, "id", m_nId);
    FUN_1408731e0(pNode, "category", m_nCategory);
    FUN_1408733e0(pNode, "asset", m_strAsset);
    FUN_1408731e0(pNode, "equipItemId", m_nEquipItemId);
    FUN_1408731e0(pNode, "soloRelayScoreCount", m_nSoloRelayScoreCount);
    FUN_1408733e0(pNode, "readyEffect", m_strReadyEffect);
    FUN_1408733e0(pNode, "playEffect", m_strPlayEffect);
    FUN_1408730a0(pNode, "isExpensive", m_bExpensive);
    FUN_1408733e0(pNode, "animationReady", m_strAnimationReady);
    FUN_1408733e0(pNode, "animationPlayIdle", m_strAnimationPlayIdle);
    FUN_1408733e0(pNode, "animationPlayLevel1", m_strAnimationPlayLevel1);
    FUN_1408733e0(pNode, "animationPlayLevel2", m_strAnimationPlayLevel2);
    FUN_1408733e0(pNode, "animationPlayLevel3", m_strAnimationPlayLevel3);
    FUN_1408733e0(pNode, "animationPlayLevel4", m_strAnimationPlayLevel4);
}

// @0x14072c080
CInstrumentData::~CInstrumentData()
{
}

// @0x14072c150
CStringW CInstrumentData::GetName() const
{
    if (m_nId == 1)
    {
        CStringW strKey(L"s_play_instrument_instrument_name_1");
        return FUN_14028b8e0(strKey);
    }
    else if (m_nId == 2)
    {
        CStringW strKey(L"s_play_instrument_instrument_name_2");
        return FUN_14028b8e0(strKey);
    }
    return CStringW(L"");
}

// @0x14072c240
CStringW CInstrumentData::GetCategoryName() const
{
    CInstrumentDataTable::CategoryPtr spCategory = CInstrumentDataTable::GetInstance()->GetCategory(m_nCategory);
    if (spCategory == 0)
        return CStringW(L"");
    return spCategory->GetName();
}

// @0x14072c300
CInstrumentCategoryData::CInstrumentCategoryData(Unk_140165cf0* pNode)
    : m_nId(0), m_nGMId(0), m_nPercussionId(0), m_strIcon(), m_strDefaultOctave()
{
    FUN_1408731e0(pNode, "id", m_nId);
    FUN_1408731e0(pNode, "GMId", m_nGMId);
    FUN_1408731e0(pNode, "percussionId", m_nPercussionId);
    FUN_1408733e0(pNode, "icon", m_strIcon);
    FUN_1408733e0(pNode, "defaultOctave", m_strDefaultOctave);
}

// @0x14072c420
CInstrumentCategoryData::~CInstrumentCategoryData()
{
}

// @0x14072c480
CStringW CInstrumentCategoryData::GetName() const
{
    CStringW strKey = FUN_1401ceea0(L"s_play_instrument_instrument_category_name_{0}", m_nId);
    return FUN_14028b8e0(strKey);
}

// @0x14072c500
bool CInstrumentCategoryData::IsPercussion() const
{
    if (m_nPercussionId > 0)
        return true;
    return false;
}

// @0x14072c520
CInstrumentDataTable::CInstrumentDataTable()
    : m_instruments(17, 0.75f, 0.25f, 2.25f, 10), m_categories(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14072c600
CInstrumentDataTable::~CInstrumentDataTable()
{
}

// @0x14072c670
bool CInstrumentDataTable::Load()
{
    if (!LoadInstruments())
        return false;
    if (!LoadCategories())
        return false;
    SetInit(true);
    return true;
}

// @0x14072c6c0
bool CInstrumentDataTable::LoadInstruments()
{
    CString strPath = FUN_14071a5b0("Table", "InstrumentInfo.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("instrument"); pNode != 0; pNode = pNode->FUN_140168650("instrument"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        InstrumentPtr spInstrument(new CInstrumentData(pNode));
        m_instruments.SetAt(spInstrument->m_nId, spInstrument);
    }
    return true;
}

// @0x14072c920
bool CInstrumentDataTable::LoadCategories()
{
    CString strPath = FUN_14071a5b0("Table", "InstrumentCategoryInfo.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("category"); pNode != 0; pNode = pNode->FUN_140168650("category"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CategoryPtr spCategory(new CInstrumentCategoryData(pNode));
        m_categories.SetAt(spCategory->m_nId, spCategory);
    }
    return true;
}

// @0x14072cb80
CInstrumentDataTable::InstrumentPtr CInstrumentDataTable::GetInstrument(int nId)
{
    CheckInit();
    InstrumentPtr spInstrument(0);
    m_instruments.Lookup(nId, spInstrument);
    return spInstrument;
}

// @0x14072cc10
CInstrumentDataTable::CategoryPtr CInstrumentDataTable::GetCategory(int nId)
{
    CategoryPtr spCategory(0);
    m_categories.Lookup(nId, spCategory);
    return spCategory;
}

// @0x14072cc90
CInstrumentDataTable::CategoryPtr CInstrumentDataTable::GetInstrumentCategory(int nInstrumentId)
{
    InstrumentPtr spInstrument = GetInstrument(nInstrumentId);
    if (spInstrument == 0)
        return CategoryPtr(0);
    CategoryPtr spCategory = GetCategory(spInstrument->m_nCategory);
    if (spCategory == 0)
        return CategoryPtr(0);
    return spCategory;
}

// @0x14072cdb0
ATL::CAtlMap<int, CInstrumentDataTable::InstrumentPtr>& CInstrumentDataTable::GetInstruments()
{
    return m_instruments;
}

// @0x14072cdd0
ATL::CAtlMap<int, CInstrumentDataTable::CategoryPtr>& CInstrumentDataTable::GetCategories()
{
    return m_categories;
}

// @0x14072cdf0
CStringW CInstrumentDataTable::GetCategoryNameById(int nCategoryId)
{
    CategoryPtr spCategory = GetInstance()->GetCategory(nCategoryId);
    if (spCategory == 0)
        return CStringW(L"");
    return spCategory->GetName();
}

// @0x14072ceb0
CString CInstrumentDataTable::GetCategoryIconById(int nCategoryId)
{
    CategoryPtr spCategory = GetInstance()->GetCategory(nCategoryId);
    if (spCategory.get() != 0)
        return spCategory->m_strIcon;
    return CString("");
}

// @0x14072d7c0
void CInstrumentDataTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CInstrumentDataTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14072f4b0
void CInstrumentDataTable::SetInit(bool b)
{
    s_bInit = b;
}
