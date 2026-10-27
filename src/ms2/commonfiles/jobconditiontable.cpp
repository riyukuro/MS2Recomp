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

// ---- unrecovered helpers (the tinyxml wrappers the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
bool FUN_14028f710(Unk_140165cf0* pElem);                   // the node is a usable element
int FUN_140873890(Unk_140165cf0* pElem, const char* pszName, int& rOut);

// Reads an attribute that is converted by name; stores the value only on success.
// @0x1406363a0
static int FUN_1406363a0(Unk_140165cf0* pElem, const char* pszName, int* pOut);

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
    return LoadFile(FUN_14071a5b0("Table", "jobConditionTable.xml"));
}

// @0x1406360a0
int CJobConditionTable::LoadFile(const CString& strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return 0;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("condition"); pNode != 0; pNode = pNode->FUN_140168650("condition"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        int nNpcId = 0;
        FUN_1408731e0(pNode, "npcID", nNpcId);
        if (nNpcId == 0)
            continue;
        NpcJobDataPtr spData(Unk_JobNewTag(0));
        FUN_140873220(pNode, "moveFieldID", spData->m_nMoveFieldId);
        FUN_1408731e0(pNode, "movePortalID", spData->m_nMovePortalId);
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
static int FUN_1406363a0(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    // the tinyxmlhelper.h enum reader's compile-time-false type guard (ASSERT(FALSE) of its line 231)
    if (false)
    {
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 231), 0));
        return 2;
    }
    int nValue = 0;
    int nResult = FUN_140873890(pElem, pszName, nValue);
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
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CJobConditionTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1406378b0
void CJobConditionTable::SetInit(bool b)
{
    s_bInit = b;
}
