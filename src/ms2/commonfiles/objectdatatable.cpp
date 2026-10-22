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

// ---- unrecovered helpers (the tinyxml wrappers the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
CString FUN_14015f710(Unk_140165cf0* pElem, const char* pszName, CString strDefault);
void FUN_14086ddc0(TiXmlDocument* pDoc);                    // Clear

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
    FUN_14086ddc0(&m_doc);
}

// @0x14070c590
void CObjectDataTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "ObjectData.xml");
    if (FUN_140166420()->FUN_1403974b0(&m_doc, strPath, 0, true, false) == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}]", strPath);
        return;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&m_doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
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
void CObjectDataTable::LoadDisplays(Unk_140165cf0* pRoot)
{
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("display"); pNode != 0; pNode = pNode->FUN_140168650("display"))
    {
        int nId = 0;
        DisplayPtr spDisplay(new Display);
        FUN_1408731e0(pNode, "id", nId);
        spDisplay->m_strActionKey = FUN_14015f710(pNode, "actionkey", CString(""));
        spDisplay->m_strUi = FUN_14015f710(pNode, "ui", CString(""));
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
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CObjectDataTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14070de80
void CObjectDataTable::SetInit(bool b)
{
    s_bInit = b;
}
