// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CObjectDataTable: the object display table
// (Table/ObjectData.xml) and the Display rows it holds in an ATL::CAtlMap<int, MS2Ptr<...>>.
// MS2-UNIT: ?\objectdatatable.cpp
// MS2-RANGE: 0x14070c3f0-0x14070e080 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1Display@CObjectDataTable@@UEAA@XZ 0x14070cdc0
// MS2-PIN: ??_GDisplay@CObjectDataTable@@UEAAPEAXI@Z 0x14070cf70
// MS2-PIN: ??_7CObjectDataTable@@6B?$TSingleton@VCObjectDataTable@@@@@ 0x142d80238
// MS2-PIN: ??_7CObjectDataTable@@6B?$CValidData@VCObjectDataTable@@@@@ 0x142d80248
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\objectdatatable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "objectdatatable.h"
#include "logstring.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- unrecovered helpers (the tinyxml wrappers the other table units share) ----

CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString GetXmlPath(const CString& strDir, const CString& strFile);        // Table/<file>
CString ToCString(const char* pszName, int nFlags);     // undecorated class name
#include "ms2/placeholder/tixmlelement.h"   // C3: was a local TiXml view; the shared reduced view has the same names
//
//
//
//

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CObjectDataTable::s_bInit;
#endif

// @0x14070c3f0
CObjectDataTable::CObjectDataTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
    Load();
}

// @0x14070c4d0
CObjectDataTable::~CObjectDataTable()
{
    ((class TiXmlNode*)(class TiXmlDocument*)(&m_doc))->Clear();
}

// @0x14070c590
void CObjectDataTable::Load()
{
    CString strPath = GetXmlPath("Table", "ObjectData.xml");
    if (GetFileSystem()->LoadXmlFile(&m_doc, strPath, 0, true, false) == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}]", strPath);
        return;
    }
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&m_doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    LoadDisplays(pRoot);
    SetInit(true);
}

// @0x14070c710
CObjectDataTable::DisplayPtr CObjectDataTable::GetData(int nId)
{
    CheckInit();
    if (FUN_1401d1320(this) != 0)
        Reload();
    DisplayPtr spDisplay(0);
    m_map.Lookup(nId, spDisplay);
    return spDisplay;
}

// @0x14070c7c0
void CObjectDataTable::Reload()
{
    m_map.RemoveAll();
    Load();
}

// @0x14070c800
void CObjectDataTable::LoadDisplays(TiXmlElement* pRoot)
{
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("display")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("display")))
    {
        int nId = 0;
        DisplayPtr spDisplay(new Display);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<int&>(nId));
        spDisplay->m_strActionKey = Unk_ReadString((class Unk_XmlNode*)(pNode), "actionkey", CString(""));
        spDisplay->m_strUi = Unk_ReadString((class Unk_XmlNode*)(pNode), "ui", CString(""));
        m_map.SetAt(nId, spDisplay);
    }
}

// @0x14070cc90
CObjectDataTable::Display::Display()
{
}

// @0x14070cfb0
void CObjectDataTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)ToCString(typeid(CObjectDataTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14070de80
void CObjectDataTable::SetInit(bool b)
{
    s_bInit = b;
}
