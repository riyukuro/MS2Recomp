// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSkillTierOptionManager / CSkillTierOption: the skill tier
// item options (Table/itemOptionSkillTier.xml: <skillTier id skillIDs/>) with the static tier table, plus the template
// glue of the CAtlMaps / CRBMultiMap / CAtlArray they use.
// MS2-UNIT: ?\skilltieroptionmanager.cpp
// MS2-RANGE: 0x1400bcdf0-0x1400bd070 .text$di
// MS2-RANGE: 0x14080b800-0x1408105e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$TPtrValue@V?$CRBMultiMap@W4eJobCode@@IV?$CElementTraits@W4eJobCode@@@ATL@@V?$CElementTraits@I@3@@ATL@@@@QEAA@H@Z 0x14080c990 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCSkillTierOption@@@@QEAA@H@Z 0x14080c9d0 ; unique
// MS2-PIN: ??4?$TPtrValue@V?$CRBMultiMap@W4eJobCode@@IV?$CElementTraits@W4eJobCode@@@ATL@@V?$CElementTraits@I@3@@ATL@@@@QEAAAEAV0@AEBV0@@Z 0x14080cec0 ; unique
// MS2-PIN: ??C?$TPtrValue@V?$CRBMultiMap@W4eJobCode@@IV?$CElementTraits@W4eJobCode@@@ATL@@V?$CElementTraits@I@3@@ATL@@@@QEBAPEAV?$CRBMultiMap@W4eJobCode@@IV?$CElementTraits@W4eJobCode@@@ATL@@V?$CElementTraits@I@3@@ATL@@XZ 0x14080d000 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4eJobCode@@@ATL@@SAHAEBW4eJobCode@@0@Z 0x14080d2a0 ; unique
// MS2-PIN: ?AddRefImpl@?$TPtrValue@V?$CRBMultiMap@W4eJobCode@@IV?$CElementTraits@W4eJobCode@@@ATL@@V?$CElementTraits@I@3@@ATL@@@@AEBAXPEAX@Z 0x1408102e0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\skilltieroptionmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/skilltieroptionmanager.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/specialability.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& rOut);
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& rOut);
void FUN_140177e10(const CString& str, ATL::CAtlArray<unsigned int>* pOut, const char* pszDelim);   // split into uints
unsigned char FUN_1401d1320(CCacheData*);                                // the file changed since it was loaded
int FUN_14081d9e0(unsigned nTier);                                       // the tier id is used
unsigned FUN_14081da20(CSkillTierOptionManager::TierId nTier);                                       // the tier's skill group id
unsigned short FUN_141662980(PC* pOwner, CSkillTierOptionManager::TierId nTier);                     // the owner's level of a tier
int FUN_141654700(PC* pOwner);                                           // the owner's job
struct Unk_RegMarker {};

typedef MS2Ptr<CSkillTierOption> CSkillTierOptionPtr;
int LoadItemOptionSkillTier();
unsigned FUN_14080c530();
unsigned FUN_14080c5a0(unsigned nIndex);
int FUN_14080c1c0(unsigned nTier, ATL::CAtlArray<unsigned int>* pOut);
int FUN_14080c370(unsigned nTier, eJobCode eJob, ATL::CAtlArray<unsigned int>* pOut);

// ---- dynamic initializers (.text$di) ----

// @0x1400bcdf0
static MS2Ptr<CCacheData> s_spCache;

// @0x1400bce20
static CLockCriticalSection s_lock;

// @0x1400bce50
static ATL::CAtlMap<unsigned int, CSkillTierOptionPtr> s_options;

// @0x1400bcea0
static ATL::CAtlArray<CSkillTierOptionManager::TierId> s_tierIds;

// @0x1400bced0
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400bcf90
static CString s_skill("skill");

// @0x1400bcfc0
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
// @0x1400bcff0
#include "ms2/placeholder/unk_1402a9d70.h"
static Unk_1402a9d70 s_marker(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142c9c2f0
#endif

// @0x1400bd040 (the table is built by specialability.cpp; this unit only initialises its storage)
#ifndef MS2_HOOK_DLL
std::vector<SpecialAbilityInfo> DAT_143ab1a40;           // ctor 0x140821660, atexit thunk 0x142c9c310 (dtor 0x140821a90)
#endif

// ---- .text$mn ----

// @0x14080b800
CSkillTierOptionManager::CSkillTierOptionManager(PC* pOwner)
    : m_pOwner(pOwner)
{
}

// @0x14080b8e0
int CSkillTierOptionManager::Update()
{
    int bChanged = 0;
    for (unsigned i = 0; i < FUN_14080c530(); i++)
    {
        CSkillTierOptionManager::TierId nTier = (CSkillTierOptionManager::TierId)FUN_14080c5a0(i);
        if (nTier == 0)
            continue;
        unsigned short nLevel = FUN_141662980(m_pOwner, nTier);
        int bTierChanged = 0;
        if (Unk_LockGuard guard = m_lock) { __assume(0); } else
        {
            unsigned short nOld = 0;
            m_tierLevels.Lookup(nTier, nOld);
            if (nOld != nLevel)
                bTierChanged = 1;
            m_tierLevels.SetAt(nTier, nLevel);
        }
        if (bTierChanged)
        {
            bChanged = 1;
            ATL::CAtlArray<unsigned int> aSkills;
            eJobCode eJob = (eJobCode)FUN_141654700(m_pOwner);
            FUN_14080c370(FUN_14081da20(nTier), eJob, &aSkills);
            for (unsigned j = 0; j < aSkills.GetCount(); j++)
            {
                if (Unk_LockGuard guard = m_lock) { __assume(0); } else
                    m_skillLevels.SetAt(aSkills[j], nLevel);
            }
        }
    }
    return bChanged;
}

// @0x14080baf0
unsigned short CSkillTierOptionManager::GetSkillLevel(unsigned int nSkillId)
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else
    {
        unsigned short nLevel = 0;
        m_skillLevels.Lookup(nSkillId, nLevel);
        return nLevel;
    }
}

// @0x14080bb80
void CSkillTierOptionManager::Clear()
{
    if (Unk_LockGuard guard = m_lock) { __assume(0); } else
    {
        m_skillLevels.RemoveAll();
        m_tierLevels.RemoveAll();
    }
}

// @0x14080bc00
int LoadItemOptionSkillTier()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("itemOptionSkillTier.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    if (Unk_LockGuard guard = s_lock) { __assume(0); } else
    {
        s_options.RemoveAll();
        s_spCache.AssignRaw(new CCacheData);
        s_spCache.get()->FUN_1401d1160(CString(strPath));
        if (s_tierIds.IsEmpty())
        {
            for (unsigned nTier = 0; nTier < 0xcf; nTier++)
            {
                if (FUN_14081d9e0(nTier) != 0)
                    s_tierIds.Add((CSkillTierOptionManager::TierId)nTier);
            }
        }
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("skillTier"); pNode != 0; pNode = pNode->FUN_140168650("skillTier"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nId = 0;
        CString strSkills;
        FUN_140873220(pNode, "id", nId);
        FUN_140873ad0(pNode, "skillIDs", strSkills);
        ATL::CAtlArray<unsigned int> aSkills;
        FUN_140177e10(strSkills, &aSkills, ",");
        if (aSkills.IsEmpty())
            continue;
        TPtrValue<Unk_SkillJobMap> spMap = Unk_GrNewTag(0);
        for (unsigned i = 0; i < aSkills.GetCount(); i++)
        {
            eJobCode eJob = (eJobCode)JobTable::GetInstance()->GetJobGroupBySkill(aSkills[i]);
            spMap->Insert(eJob, aSkills[i]);
        }
        CSkillTierOptionPtr spOption(new CSkillTierOption);
        spOption->m_skills = spMap;
        if (Unk_LockGuard guard = s_lock) { __assume(0); } else
            s_options.SetAt(nId, spOption);
    }
    return 1;
}

// @0x14080c1c0
int FUN_14080c1c0(unsigned nTier, ATL::CAtlArray<unsigned int>* pOut)
{
    TPtrValue<Unk_SkillJobMap> spMap = 0;
    if (Unk_LockGuard guard = s_lock) { __assume(0); } else
    {
        if (FUN_1401d1320(s_spCache.get()))
            LoadItemOptionSkillTier();
        CSkillTierOptionPtr spOption = 0;
        if (!s_options.Lookup(nTier, spOption))
            return 0;
        spMap = spOption->m_skills;
    }
    if (spMap == 0)
        return 0;
    POSITION pos = spMap->GetHeadPosition();
    while (pos != 0)
    {
        pOut->Add(spMap->GetValueAt(pos));
        spMap->GetNext(pos);
    }
    return 1;
}

// @0x14080c370
int FUN_14080c370(unsigned nTier, eJobCode eJob, ATL::CAtlArray<unsigned int>* pOut)
{
    TPtrValue<Unk_SkillJobMap> spMap = 0;
    if (Unk_LockGuard guard = s_lock) { __assume(0); } else
    {
        if (FUN_1401d1320(s_spCache.get()))
            LoadItemOptionSkillTier();
        CSkillTierOptionPtr spOption = 0;
        if (!s_options.Lookup(nTier, spOption))
            return 0;
        spMap = spOption->m_skills;
    }
    if (spMap == 0)
        return 0;
    POSITION pos = spMap->FindFirstWithKey(eJob);
    while (pos != 0)
    {
        pOut->Add(spMap->GetValueAt(pos));
        spMap->GetNextWithKey(pos, eJob);
    }
    return 1;
}

// @0x14080c530
unsigned FUN_14080c530()
{
    if (Unk_LockGuard guard = s_lock) { __assume(0); } else
        return (unsigned)s_tierIds.GetCount();
}

// @0x14080c5a0
unsigned FUN_14080c5a0(unsigned nIndex)
{
    if (Unk_LockGuard guard = s_lock) { __assume(0); } else
    {
        if (nIndex < s_tierIds.GetCount())
            return s_tierIds[nIndex];
        return 0;
    }
}

// @0x14080cbf0
CSkillTierOption::CSkillTierOption()
    : m_18(0)
{
}

// @0x14080ce40
CSkillTierOption::~CSkillTierOption()
{
}

// @0x14080ce70
CSkillTierOptionManager::~CSkillTierOptionManager()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c200-0x142c9c2f0 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142c9c2f0-0x142c9c330 .text$yd
