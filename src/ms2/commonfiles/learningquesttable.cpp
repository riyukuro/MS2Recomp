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

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_140873220(Unk_140165cf0*, const char*, int&);
void FUN_1408731a0(Unk_140165cf0*, const char*, unsigned short&);
int FUN_1408733e0(Unk_140165cf0*, const char*, CStringA&);
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);

// The <learning> children of a parent (24 bytes) with index access.
class Unk_ElemArray
{
public:
    Unk_ElemArray();                                                // 0x140163e20
    ~Unk_ElemArray();                                               // 0x1401644e0
    unsigned __int64 FUN_14016d900();                               // size
    Unk_140165cf0*& FUN_140164a30(unsigned __int64 n);              // operator[]
    void *m_a, *m_b, *m_c;
};
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, Unk_ElemArray* pOut);

// @0x14064ca50
int CLearningQuestData::Read(Unk_140165cf0* pElem)
{
    FUN_1408731e0(pElem, "id", m_nId);
    FUN_1408731e0(pElem, "category", m_nCategory);
    FUN_1408733e0(pElem, "movie", m_strMovie);
    FUN_1408731a0(pElem, "reqLevel", m_nReqLevel);
    FUN_140873220(pElem, "reqQuest", m_nReqQuest);
    FUN_140873220(pElem, "reqField", m_nReqField);
    FUN_140873220(pElem, "gotoField", m_nGotoField);
    FUN_1408731e0(pElem, "gotoPortal", m_nGotoPortal);
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
bool CLearningQuestTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "learningQuest.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    Unk_ElemArray list;
    FUN_14028faa0(pRoot, "learning", "id", &list);
    for (unsigned __int64 i = 0; i < list.FUN_14016d900(); i++)
    {
        Unk_140165cf0* pNode = list.FUN_140164a30(i);
        DataPtr data(new CLearningQuestData);
        if (data->Read(pNode) == 0)
            return false;
        m_map.SetAt(data->m_nId, data);
    }
    return true;
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
