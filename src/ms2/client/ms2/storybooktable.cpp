// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CStoryBookTable: the story book table (Table/storybook.xml)
// and the CStoryBookData / CStoryBookData::BookPage rows it holds in ATL::CAtlMap containers.
// MS2-UNIT: ?\storybooktable.cpp
// MS2-RANGE: 0x14180bc30-0x14180f030 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x14180ccc0 ; order
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCStoryBookData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCStoryBookData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14180d480 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1BookPage@CStoryBookData@@UEAA@XZ 0x14180cb30
// MS2-PIN: ??1CStoryBookData@@UEAA@XZ 0x14180cc00
// MS2-PIN: ??_7CStoryBookTable@@6B?$TSingleton@VCStoryBookTable@@@@@ 0x142f7ec20
// MS2-PIN: ??_7CStoryBookTable@@6B?$CValidData@VCStoryBookTable@@@@@ 0x142f7ec30
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\storybooktable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "storybooktable.h"
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
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
CString FUN_14028d1f0(const char* pszText);                 // "" when null
CString FUN_140536a50(const char* pszFormat, const CString& strArg0);       // fmt::format("..{0}", arg)
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);   // attribute text (null = absent)
CString FUN_140cc2ad0(const CString& strDir, const CString& strFile);      // <resource root><dir>/<file>
class Unk_ScriptTextFilter { public: void FUN_1416fb380(CStringW* pText); };
Unk_ScriptTextFilter* FUN_1403b4750();

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CStoryBookTable::s_bInit;
#endif

// ---- CStoryBookData::BookPage ----

// @0x14180c840
CStoryBookData::BookPage::BookPage()
{
}

// ---- CStoryBookData ----

// @0x14180c9b0
CStoryBookData::CStoryBookData()
    : m_nType(0), m_nMaxPage(0), m_pages(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// ---- CStoryBookTable ----

// @0x14180bc30
CStoryBookTable::CStoryBookTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
    Load();
}

// @0x14180bce0
CStoryBookTable::~CStoryBookTable()
{
}

// MS2-FUNCTIONAL: exe hops the c_str / text pointer args through rcx (mov rcx,[x]; mov r8,rcx); no source form found
// @0x14180bd40
void CStoryBookTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "storybook.xml");
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "book", "id", &nodes);
    for (unsigned __int64 i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pBook = nodes[i];
        CStoryBookDataPtr spData(new CStoryBookData);
        spData->m_nMaxPage = 0;
        int nId = 0;
        FUN_1408731e0(pBook, "id", nId);
        CString strType = FUN_14015f710(pBook, "type", CString(""));
        if (strType.CompareNoCase("book") == 0)
            spData->m_nType = 1;
        else if (strType.CompareNoCase("sketchbook") == 0)
            spData->m_nType = 2;
        else if (strType.CompareNoCase("magazine") == 0)
            spData->m_nType = 3;
        else if (strType.CompareNoCase("adpaper") == 0)
            spData->m_nType = 4;
        for (Unk_140165cf0* pPage = pBook->FUN_140165cf0("page"); pPage != 0; pPage = pPage->FUN_140168650("page"))
        {
            CStoryBookData::BookPagePtr spPage(new CStoryBookData::BookPage);
            int nNumber = 0;
            FUN_1408731e0(pPage, "number", nNumber);
            FUN_140873420(pPage, "string", spPage->m_strText);
            FUN_1408733e0(pPage, "valign", spPage->m_strVAlign);
            CString strImage = FUN_14028d1f0(FUN_14086f4b0(pPage, "image"));
            if (strImage.GetLength() > 0)
            {
                ATL::CAtlArray<CString> arrPath;
                FUN_14015f050(strImage, arrPath, "/");
                if (arrPath.GetCount() != 2)
                    continue;
                CString strDir = FUN_140536a50("StoryBook/{0}", arrPath[0]);
                spPage->m_strImage = FUN_140cc2ad0(strDir, arrPath[1]);
            }
            CStringW* pText = &spPage->m_strText;
            FUN_1403b4750()->FUN_1416fb380(pText);
            spData->m_pages.SetAt(nNumber, spPage);
            if (nNumber > spData->m_nMaxPage)
                spData->m_nMaxPage = nNumber;
        }
        m_map.SetAt(nId, spData);
    }
    SetInit(true);
}

// @0x14180c400
CStoryBookDataPtr CStoryBookTable::GetData(int nId)
{
    CheckInit();
    CStoryBookDataPtr spData(0);
    m_map.Lookup(nId, spData);
    return spData;
}

// @0x14180c490
int CStoryBookTable::GetMaxPage(int nId)
{
    CheckInit();
    CStoryBookDataPtr spData(0);
    if (m_map.Lookup(nId, spData))
        return spData->m_nMaxPage;
    return 0;
}

// @0x14180cea0
void CStoryBookTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CStoryBookTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14180eb20
void CStoryBookTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x14180ef10
MS2_EMIT_CRT_MEMMOVE_S();
