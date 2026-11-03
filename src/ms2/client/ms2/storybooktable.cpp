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
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/creservedwordtable.h"
void Unk_SplitA(CStringA&, ATL::CAtlArray<CStringA>*, const char*);   // C3: the achievedata def at 0x14015f050
class Unk_140165cf0;
class TiXmlElement   // C3: member view for the former free stand-ins
{
public:
    char const* Attribute(char const*) const;
};
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

class Unk_140166420 : public CFileSystem { };
class CLogString;
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was V::FUN_14015eb90
class Unk_CommonLog { public: };
class CLogString* GetLogString();   // C3: was FUN_140166440
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
CString FUN_14028d1f0(const char* pszText);                 // "" when null
template <class T> CString Unk_SocketFormat(const char* szFormat, const T& n);   // C3: was FUN_140536a50
CString FUN_140cc2ad0(const CString& strDir, const CString& strFile);      // <resource root><dir>/<file>

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

// @0x14180bd40
void CStoryBookTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "storybook.xml");
    TiXmlDocument doc;
    if (((class CFileSystem*)(((class Unk_140166420*)GetFileSystem())))->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>((class Unk_140165cf0 *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
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
        XmlGetAttr((class TiXmlElement*)(pBook), "id", reinterpret_cast<int&>(nId));
        CString strType = Unk_ReadString((class Unk_XmlNode*)(pBook), "type", CString(""));
        if (strType.CompareNoCase("book") == 0)
            spData->m_nType = 1;
        else if (strType.CompareNoCase("sketchbook") == 0)
            spData->m_nType = 2;
        else if (strType.CompareNoCase("magazine") == 0)
            spData->m_nType = 3;
        else if (strType.CompareNoCase("adpaper") == 0)
            spData->m_nType = 4;
        for (Unk_140165cf0* pPage = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pBook))->FirstChild("page")); pPage != 0; pPage = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pPage))->NextSibling("page")))
        {
            CStoryBookData::BookPagePtr spPage(new CStoryBookData::BookPage);
            int nNumber = 0;
            XmlGetAttr((class TiXmlElement*)(pPage), "number", reinterpret_cast<int&>(nNumber));
            XmlGetAttr((class TiXmlElement*)(pPage), "string", spPage->m_strText);
            XmlGetAttr((class TiXmlElement*)(pPage), "valign", spPage->m_strVAlign);
            CString strImage = FUN_14028d1f0(((class TiXmlElement*)(class Unk_140165cf0*)(pPage))->Attribute("image"));
            if (strImage.GetLength() > 0)
            {
                ATL::CAtlArray<CString> arrPath;
                Unk_SplitA(const_cast<CStringA&>(strImage), (ATL::CAtlArray<CStringA>*)&(arrPath), "/");
                if (arrPath.GetCount() != 2)
                    continue;
                CString strDir = Unk_SocketFormat<CString>("StoryBook/{0}", arrPath[0]);
                spPage->m_strImage = FUN_140cc2ad0(strDir, arrPath[1]);
            }
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(spPage->m_strText);
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
