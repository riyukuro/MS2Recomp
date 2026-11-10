// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CContinentRegionTable: Table/MapContinentTable.xml.
// MS2-UNIT: ?\continentregiontable.cpp
// MS2-RANGE: 0x1402c5180-0x1402c6c20 .text$mn
// MS2-PIN: ??_7CContinentRegionTable@@6B?$TSingleton@VCContinentRegionTable@@@@@ 0x142d203c8
// MS2-PIN: ??_7CContinentRegionTable@@6B?$CValidData@VCContinentRegionTable@@@@@ 0x142d203d8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\continentregiontable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "continentregiontable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// Unrecovered helpers (same ones serverlisttable.cpp uses).
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view
// C3 #8: the cast-only Unk_140168650 view removed
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
CString GetXmlPath(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString ToCString(const char* psz, int n);
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CContinentRegionTable::s_bInit;
#endif

// @0x1402c5180
CContinentRegionTable::CContinentRegionTable() : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
    Load();
}

// @0x1402c5230
CContinentRegionTable::~CContinentRegionTable()
{
    m_map.RemoveAll();
}

// @0x1402c52b0
void CContinentRegionTable::Load()
{
    CString strPath = GetXmlPath("Table", "MapContinentTable.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("continent")); pNode != 0;
         pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("continent")))
    {
        InfoPtr info(new ContinentInfo);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", info->m_nId);
        XmlGetAttr((class TiXmlElement*)(pNode), "hideOtherWorldQuest", info->m_nHideOtherWorldQuest);
        XmlGetAttr((class TiXmlElement*)(pNode), "shadowContinent", info->m_nShadowContinent);
        XmlGetAttr((class TiXmlElement*)(pNode), "representWorldmapContinent", info->m_nRepresentWorldmapContinent);
        m_map.SetAt(info->m_nId, info);
    }
    SetInit(true);
}

// @0x1402c5570
CContinentRegionTable::InfoPtr CContinentRegionTable::GetContinent(DWORD nId)
{
    CheckInit();
    InfoPtr p(0);
    m_map.Lookup(nId, p);
    return p;
}

// @0x1402c5850
ContinentInfo::ContinentInfo()
{
    m_nId = 0;
    m_nHideOtherWorldQuest = 0;
    m_nShadowContinent = 0;
    m_nRepresentWorldmapContinent = 0;
}

// @0x1402c5b50
void CContinentRegionTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)ToCString(typeid(CContinentRegionTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1402c6a20
void CContinentRegionTable::SetInit(bool b)
{
    s_bInit = b;
}
