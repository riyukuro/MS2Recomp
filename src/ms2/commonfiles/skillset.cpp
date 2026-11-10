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
#include "ms2/commonfiles/filesystem.h"
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

bool IsElementAvailable(struct Unk_XmlElement*);   // C3: was IsElementAvailable
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString GetXmlPath(const CString& strDir, const CString& strFile);        // Table/<file>
CString ToCString(const char* pszName, int nFlags);     // undecorated class name
int XmlGetBool(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873710

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
    if (Unk_LockGuard guard = m_lock) { __assume(0); }
    else if (Load() == 0)
        return 0;
    SetInit(true);
    return 1;
}

// @0x140809840
CSkillSetPtr CSkillSetTable::GetSkillSet(int nSetId)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock) { __assume(0); }
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
    CString strPath = GetXmlPath("Table", "skillSet.xml");
    m_spCache.AssignRaw(new CCacheData);
    m_spCache->SetPath(strPath);
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("skillSet")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("skillSet")))
    {
        if (!IsElementAvailable((struct Unk_XmlElement*)(pNode)))
            continue;
        CSkillSetPtr spSet(new CSkillSet);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", spSet->m_nId);
        XmlGetAttr((class TiXmlElement*)(pNode), "version", reinterpret_cast<int&>(spSet->m_nVersion));
        XmlGetBool((class TiXmlElement*)(pNode), "slotLock", spSet->m_nSlotLock);
        CString strSkillIds = Unk_ReadString((class Unk_XmlNode*)(pNode), "skillIDs", CString(""));
        CString strSkillLevels = Unk_ReadString((class Unk_XmlNode*)(pNode), "skillLevels", CString(""));
        CString strLearnIds = Unk_ReadString((class Unk_XmlNode*)(pNode), "learnSkillIDs", CString(""));
        CString strLearnLevels = Unk_ReadString((class Unk_XmlNode*)(pNode), "learnSkillLevels", CString(""));
        CString strItemIds = Unk_ReadString((class Unk_XmlNode*)(pNode), "itemIDs", CString(""));
        XmlSplit(strSkillIds, spSet->m_arrSkillIds, ",");
        XmlSplit(strSkillLevels, spSet->m_arrSkillLevels, ",");
        XmlSplit(strLearnIds, spSet->m_arrLearnSkillIds, ",");
        XmlSplit(strLearnLevels, spSet->m_arrLearnSkillLevels, ",");
        XmlSplit(strItemIds, spSet->m_arrItemIds, ",");
        if (spSet->m_arrSkillIds.size() != spSet->m_arrSkillLevels.size())
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
            return 0;
        }
        if (spSet->m_arrLearnSkillIds.size() != spSet->m_arrLearnSkillLevels.size())
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
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
        msg.Format("%s is not initialized", (const char*)ToCString(typeid(CSkillSetTable).name(), 0));
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
