// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CLearningQuestTable: Table/learningQuest.xml.
// MS2-UNIT: ?\learningquesttable.cpp
// MS2-RANGE: 0x14064ca50-0x14064ead0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\learningquesttable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "learningquesttable.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

// Unrecovered helpers (the same xml loader helpers the other table units use).
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);

// The <learning> children of a parent (24 bytes) with index access.
typedef std::vector<Unk_XmlNode*> Unk_ElemArray;   // ctor 0x140163e20, dtor 0x1401644e0, size 0x14016d900, [] 0x140164a30
void FUN_14028faa0(struct Unk_XmlElement*, char const*, char const*, std::vector<struct Unk_XmlElement*>&);   // C3: retyped to the commonutil def

// @0x14064ca50
int CLearningQuestData::Read(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "id", m_nId);
    XmlGetAttr((class TiXmlElement*)(pElem), "category", m_nCategory);
    XmlGetAttr((class TiXmlElement*)(pElem), "movie", m_strMovie);
    XmlGetAttr((class TiXmlElement*)(pElem), "reqLevel", m_nReqLevel);
    XmlGetAttr((class TiXmlElement*)(pElem), "reqQuest", *(unsigned int*)&static_cast<int&>(m_nReqQuest));
    XmlGetAttr((class TiXmlElement*)(pElem), "reqField", *(unsigned int*)&static_cast<int&>(m_nReqField));
    XmlGetAttr((class TiXmlElement*)(pElem), "gotoField", *(unsigned int*)&static_cast<int&>(m_nGotoField));
    XmlGetAttr((class TiXmlElement*)(pElem), "gotoPortal", m_nGotoPortal);
    MS2Ptr<CQuestData> quest = FUN_14074bc40(m_nReqQuest);
    if (!quest)
        return 0;
    m_nQuestKind = quest->GetKind();
    if (m_nGotoField == 0)
        return 0;
    return 1;
}

// @0x14064cbf0
CLearningQuestTable::CLearningQuestTable() : m_map(10)
{
}

// @0x14064cc40
CLearningQuestTable::~CLearningQuestTable()
{
}

// @0x14064cc80
// MS2-FUNCTIONAL: the exe Load returns int (dword result temps); learningquesttable.h is shared (filepreload_1, questmanager_2, uilearningquestdialog), so it stays bool
int CLearningQuestTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "learningQuest.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    Unk_ElemArray list;
    FUN_14028faa0((struct Unk_XmlElement*)(pRoot), "learning", "id", *reinterpret_cast<std::vector<struct Unk_XmlElement*>*>(&list));
    for (unsigned __int64 i = 0; i < list.size(); i++)
    {
        TiXmlElement* pNode = (TiXmlElement*)list[i];
        DataPtr data(new CLearningQuestData);
        if (data->Read(pNode) == 0)
            return 0;
        m_map.SetAt(data->m_nId, data);
    }
    return 1;
}

// @0x14064cf80
void CLearningQuestTable::GetAll(ATL::CAtlArray<DataPtr>& rOut)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos; m_map.GetNext(pos))
    {
        DataPtr data = m_map.GetValueAt(pos);
        rOut.Add(data);
    }
}

// @0x14064d020
CLearningQuestTable::DataPtr CLearningQuestTable::Get(int nId)
{
    DataPtr data(0);
    m_map.Lookup(nId, data);
    return data;
}

// @0x14064d220
CLearningQuestData::CLearningQuestData()
    : m_nId(0), m_nCategory(0), m_nQuestKind(0), m_nReqLevel(0), m_nReqQuest(0), m_nReqField(0), m_nGotoField(0), m_nGotoPortal(0)
{
}

// ---- hooks (functional, non-COMDAT, non-ctor bodies) ----------------------------------------------------------------
MS2_REPLACE_METHOD(0x14064CC80, CLearningQuestTable, Load, 754, 0xF69D7261);
