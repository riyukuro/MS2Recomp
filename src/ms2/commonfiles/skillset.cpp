// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSkillSetTable: the skill set table (Table/skillSet.xml)
// and the CSkillSet rows it holds in an ATL::CAtlMap<int, MS2Ptr<CSkillSet>>.
// MS2-UNIT: ?\skillset.cpp
// MS2-RANGE: 0x1408092d0-0x14080b800 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCSkillSet@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCSkillSet@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14080a8e0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CSkillSetTable@@6B?$TSingleton@VCSkillSetTable@@@@@ 0x142d947b0
// MS2-PIN: ??_7CSkillSetTable@@6B?$CValidData@VCSkillSetTable@@@@@ 0x142d947c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\skillset.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cskillsettable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

bool FUN_14028f710(Unk_140165cf0* pElem);                   // the node is a usable element
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_CommonLog { public: void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg); };
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
int FUN_140873710(Unk_140165cf0* pElem, const char* pszName, int& nOut);

// The unit's init flag is an exe global; the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CSkillSetTable::s_bInit;
#endif

// ---- CSkillSet ----

// @0x1408092d0
CSkillSet::CSkillSet()
    : m_nId(0), m_nVersion(1), m_nSlotLock(1)
{
}

// @0x140809380
CSkillSet::~CSkillSet()
{
}

// @0x140809410
int CSkillSet::HasSkill(int nSkillId, unsigned short nLevel)
{
    size_t nCount = m_arrSkillIds.size();
    for (size_t i = 0; i < nCount; ++i)
    {
        if (m_arrSkillIds[i] == (unsigned)nSkillId && (nLevel == 0 || nLevel == m_arrSkillLevels[i]))
            return 1;
    }
    nCount = m_arrLearnSkillIds.size();
    for (size_t i = 0; i < nCount; ++i)
    {
        if (m_arrLearnSkillIds[i] == (unsigned)nSkillId && (nLevel == 0 || nLevel == m_arrLearnSkillLevels[i]))
            return 1;
    }
    return 0;
}

// @0x140809560
unsigned short CSkillSet::GetSkillLevel(int nSkillId)
{
    size_t nCount = m_arrSkillIds.size();
    for (unsigned int i = 0; i < nCount; ++i)
    {
        if (m_arrSkillIds[i] == (unsigned)nSkillId)
            return m_arrSkillLevels[i];
    }
    nCount = m_arrLearnSkillIds.size();
    for (size_t i = 0; i < nCount; ++i)
    {
        if (m_arrLearnSkillIds[i] == (unsigned)nSkillId)
            return m_arrLearnSkillLevels[i];
    }
    return 0;
}

// ---- CSkillSetTable ----

// @0x140809660
CSkillSetTable::CSkillSetTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
    Init();
}

// @0x140809730
CSkillSetTable::~CSkillSetTable()
{
}

// @0x1408097c0
int CSkillSetTable::Init()
{
    if (Unk_LockGuard guard = m_lock) {}
    else if (Load() == 0)
        return 0;
    SetInit(true);
    return 1;
}

// MS2-FUNCTIONAL: the exe has one extra nop after the inner scope (scope/jump layout, 6 bytes differ)
// @0x140809840
CSkillSetPtr CSkillSetTable::GetSkillSet(int nSetId)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock) {}
    else
    {
        if (FUN_1401d1320(m_spCache.get()) != 0)
            Init();
        CSkillSetPtr spSet(0);
        m_map.Lookup(nSetId, spSet);
        return spSet;
    }
}

// @0x140809930
int CSkillSetTable::Load()
{
    m_map.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "skillSet.xml");
    m_spCache.AssignRaw(new CCacheData);
    m_spCache->FUN_1401d1160(strPath);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("skillSet"); pNode != 0; pNode = pNode->FUN_140168650("skillSet"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CSkillSetPtr spSet(new CSkillSet);
        FUN_140873220(pNode, "id", spSet->m_nId);
        FUN_1408731e0(pNode, "version", spSet->m_nVersion);
        FUN_140873710(pNode, "slotLock", spSet->m_nSlotLock);
        CString strSkillIds = FUN_14015f710(pNode, "skillIDs", CString(""));
        CString strSkillLevels = FUN_14015f710(pNode, "skillLevels", CString(""));
        CString strLearnIds = FUN_14015f710(pNode, "learnSkillIDs", CString(""));
        CString strLearnLevels = FUN_14015f710(pNode, "learnSkillLevels", CString(""));
        CString strItemIds = FUN_14015f710(pNode, "itemIDs", CString(""));
        XmlSplit(strSkillIds, spSet->m_arrSkillIds, ",");
        XmlSplit(strSkillLevels, spSet->m_arrSkillLevels, ",");
        XmlSplit(strLearnIds, spSet->m_arrLearnSkillIds, ",");
        XmlSplit(strLearnLevels, spSet->m_arrLearnSkillLevels, ",");
        XmlSplit(strItemIds, spSet->m_arrItemIds, ",");
        if (spSet->m_arrSkillIds.size() != spSet->m_arrSkillLevels.size())
        {
            FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
            return 0;
        }
        if (spSet->m_arrLearnSkillIds.size() != spSet->m_arrLearnSkillLevels.size())
        {
            FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
            return 0;
        }
        m_map.SetAt(spSet->m_nId, spSet);
    }
    return 1;
}

// @0x14080a610
void CSkillSetTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CSkillSetTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14080b4e0
void CSkillSetTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x14080b6e0 (the obj's unreferenced copy of the CRT's static-inline memmove_s)
MS2_EMIT_CRT_MEMMOVE_S();
