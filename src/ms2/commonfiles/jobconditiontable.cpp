// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CJobConditionTable: the job condition table
// (Table/jobConditionTable.xml) and the NpcJobData rows it holds in an ATL::CAtlMap<int, ...>.
// MS2-UNIT: ?\jobconditiontable.cpp
// MS2-RANGE: 0x140635ec0-0x140637b00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_JobPtr@VNpcJobData@CJobConditionTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_JobPtr@VNpcJobData@CJobConditionTable@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140636cb0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CJobConditionTable@@6B?$TSingleton@VCJobConditionTable@@@@@ 0x142d6ca30
// MS2-PIN: ??_7CJobConditionTable@@6B?$CValidData@VCJobConditionTable@@@@@ 0x142d6ca40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\jobconditiontable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "jobconditiontable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// ---- unrecovered helpers (the tinyxml wrappers the other table units share) ----

CString GetXmlPath(const CString& strDir, const CString& strFile);        // Table/<file>
CString ToCString(const char* pszName, int nFlags);     // undecorated class name
bool IsElementAvailable(struct Unk_XmlElement*);   // C3: was IsElementAvailable
int XmlQuery(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873890

// Reads an attribute that is converted by name; stores the value only on success.
// @0x1406363a0
static int FUN_1406363a0(TiXmlElement* pElem, const char* pszName, int* pOut);

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CJobConditionTable::s_bInit;
#endif

// @0x140635ec0
CJobConditionTable::CJobConditionTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140635f70
CJobConditionTable::~CJobConditionTable()
{
    m_map.RemoveAll();
}

// @0x140636000
int CJobConditionTable::Load()
{
    return LoadFile(GetXmlPath("Table", "jobConditionTable.xml"));
}

// @0x1406360a0
int CJobConditionTable::LoadFile(const CString& strPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
        return 0;
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("condition")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("condition")))
    {
        if (!IsElementAvailable((struct Unk_XmlElement*)(pNode)))
            continue;
        int nNpcId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "npcID", reinterpret_cast<int&>(nNpcId));
        if (nNpcId == 0)
            continue;
        NpcJobDataPtr spData(Unk_JobNewTag(0));
        XmlGetAttr((class TiXmlElement*)(pNode), "moveFieldID", spData->m_nMoveFieldId);
        XmlGetAttr((class TiXmlElement*)(pNode), "movePortalID", reinterpret_cast<int&>(spData->m_nMovePortalId));
        FUN_1406363a0(pNode, "jobCode", &spData->m_nJobCode);
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
            m_map.SetAt(nNpcId, spData);
    }
    SetInit(true);
    return 1;
}

// @0x1406362f0
CJobConditionTable::NpcJobDataPtr CJobConditionTable::GetData(int nNpcId)
{
    CheckInit();
    NpcJobDataPtr spData(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
        m_map.Lookup(nNpcId, spData);
    return spData;
}

// @0x1406363a0
static int FUN_1406363a0(TiXmlElement* pElem, const char* pszName, int* pOut)
{
    // the tinyxmlhelper.h enum reader's compile-time-false type guard (ASSERT(FALSE) of its line 231)
    if (false)
    {
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 231), 0));
        return 2;
    }
    int nValue = 0;
    int nResult = XmlQuery((class TiXmlElement*)(pElem), pszName, nValue);
    if (nResult != 0)
        return nResult;
    *pOut = nValue;
    return nResult;
}

// @0x1406366f0
CJobConditionTable::NpcJobData::NpcJobData()
    : m_nMoveFieldId(0), m_nMovePortalId(0), m_nJobCode(200)
{
}

// @0x1406369e0
void CJobConditionTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)ToCString(typeid(CJobConditionTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1406378b0
void CJobConditionTable::SetInit(bool b)
{
    s_bInit = b;
}
