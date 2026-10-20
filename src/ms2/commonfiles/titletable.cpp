// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTitleTable: the title tags (Table/titleTag.xml), by id
// and by tag name, plus the template glue of its two CAtlMap instances. The last object of the ones the unit map
// merged into commonfiles\tinyxmlhelper.cpp.
// MS2-UNIT: commonfiles\tinyxmlhelper.cpp#5
// MS2-RANGE: 0x14087a3e0-0x14087d0c0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\titletable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/titletable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled

// @0x14087a3e0
CTitleTable::CTitleTable()
{
}

// @0x14087a490
CTitleTable::~CTitleTable()
{
}

// @0x14087a4e0
int CTitleTable::Load()
{
    TiXmlDocument doc;
    CString strPath = FUN_14071a5b0("Table", "titleTag.xml");
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        MS2Ptr<CTitle> spTitle(new CTitle);
        FUN_140873220(pNode, "id", spTitle->m_nId);
        FUN_1408733e0(pNode, "tag", spTitle->m_strTag);
        FUN_1408731e0(pNode, "account", spTitle->m_nAccount);
        m_titles.SetAt(spTitle->m_nId, spTitle);
        if (spTitle->m_strTag.GetLength() > 0)
            m_tags.SetAt(spTitle->m_strTag, spTitle->m_nId);
    }
    return 1;
}

// @0x14087a820
int CTitleTable::HasTitle(unsigned nId)
{
    MS2Ptr<CTitle> spTitle(0);
    m_titles.Lookup(nId, spTitle);
    return spTitle.get() != 0;
}

// @0x14087a8a0
int CTitleTable::GetAccount(unsigned nId)
{
    MS2Ptr<CTitle> spTitle(0);
    if (m_titles.Lookup(nId, spTitle))
        return spTitle->m_nAccount;
    return 0;
}

// @0x14087a930
unsigned CTitleTable::FindTitleId(CStringA strTag)
{
    unsigned nId = 0;
    if (m_tags.Lookup(strTag, nId))
        return nId;
    return 0;
}

// @0x14087a9c0
unsigned CTitleTable::FindVipTitle(int nVipLevel)
{
    unsigned nId = 0;
    switch (nVipLevel)
    {
    case 1:
        nId = FindTitleId("tencentVip1");
        break;
    case 2:
        nId = FindTitleId("tencentVip2");
        break;
    case 3:
        nId = FindTitleId("tencentVip3");
        break;
    case 4:
        nId = FindTitleId("tencentVip4");
        break;
    }
    return nId;
}

// The ctor/dtor are not hooked: TSingleton<CTitleTable> keeps its instance pointer in a static the hook DLL does not share.
MS2_REPLACE_METHOD(0x14087a4e0, CTitleTable, Load, 811, 0xE110AA6A);
MS2_REPLACE_METHOD(0x14087a820, CTitleTable, HasTitle, 121, 0x1F86CD7D);
MS2_REPLACE_METHOD(0x14087a8a0, CTitleTable, GetAccount, 128, 0xF1DF446C);
MS2_REPLACE_METHOD(0x14087a930, CTitleTable, FindTitleId, 124, 0x8770F21E);
MS2_REPLACE_METHOD(0x14087a9c0, CTitleTable, FindVipTitle, 320, 0xCCDB7DD9);
