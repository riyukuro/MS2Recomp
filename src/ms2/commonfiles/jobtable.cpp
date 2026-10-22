// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). JobTable (Table/job.xml: per job group the start field,
// items and the job skill tree). The JobSkill / JobSystem TU right before it is ?\jobsystem.cpp (src/ms2/guess).
// MS2-UNIT: commonfiles\jobtable.cpp
// MS2-RANGE: 0x140643650-0x14064c590 .text$mn
// MS2-RANGE: 0x1400bae70-0x1400baec0 .text$di
// MS2-RANGE: 0x142c9b490-0x142c9b4b0 .text$yd
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHAEAV?$MS2Ptr@VJobData@@@@$0A@@?$pair@HV?$MS2Ptr@VJobData@@@@@std@@QEAA@AEAHAEAV?$MS2Ptr@VJobData@@@@@Z 0x140645070 ; unique
// MS2-PIN: ??$?0HV?$MS2Ptr@VJobData@@@@$0A@@?$pair@$$CBHV?$MS2Ptr@VJobData@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VJobData@@@@@1@@Z 0x1406450c0 ; unique
// MS2-PIN: ?XmlValue@@YAHPEAVUnk_140165cf0@@PEBDAEAVCPoint@@@Z 0x140645190 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@1@@Z 0x140645330 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@1@AEAU?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@1@1@Z 0x140646050 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@1@@Z 0x1406463b0 ; unique
// MS2-PIN: ??$forward@AEAV?$MS2Ptr@VJobData@@@@@std@@YAAEAV?$MS2Ptr@VJobData@@@@AEAV1@@Z 0x140647480 ; prop
// MS2-PIN: ??$make_pair@AEAHAEAV?$MS2Ptr@VJobData@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VJobData@@@@@0@AEAHAEAV?$MS2Ptr@VJobData@@@@@Z 0x140647650 ; unique
// MS2-PIN: ??0?$MS2Ptr@VJobData@@@@QEAA@$$QEAV0@@Z 0x140647720 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x140647fe0 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140648800 ; prop
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@2@XZ 0x140648f80 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x140649490 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@2@XZ 0x140649f40 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@2@$00@2@XZ 0x14064a130 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@2@XZ 0x14064a170 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@PEAX@std@@@2@XZ 0x14064a1f0 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@2@XZ 0x14064b6b0 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14064b810 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@2@XZ 0x14064bb00 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@2@0@Z 0x14064bd10 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VJobSkillData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkillData@@@@@std@@@std@@@std@@@2@@Z 0x14064be00 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7JobTable@@6B?$TSingleton@VJobTable@@@@@ 0x142d6e0a8
// MS2-PIN: ??_7JobTable@@6B?$CValidData@VJobTable@@@@@ 0x142d6e0b8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\jobtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "jobtable.h"
#include "logstring.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <vector>
#include "hook/ms2hook.h"

// Out-of-unit callees.
JobTable* FUN_1401d7a50();                              // the JobTable singleton
CStringTable* FUN_1401a9d70();                          // the string table singleton
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton, init flag and max level map (symbols-manual.tsv)
JobTable* TSingleton<JobTable>::s_instance;
bool JobTable::s_bInit;
ATL::CAtlMap<unsigned, unsigned short> JobData::s_skillMaxLevel;
#endif

// ---- jobtable.cpp -----------------------------------------------------------------------------------------------

// @0x140643650
JobSkillData::JobSkillData()
    : m_skillID(0), m_uiHighlight(false), m_quickSlotPriority(0x7fffffff), m_jobLevel(0), m_isLearn(false),
      m_requireQuestID(0)
{
}

// @0x140643720
bool JobSkillData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "skillID", m_skillID);
    XmlValue(pElem, "uiPosition", m_uiPosition);
    FUN_1408730a0(pElem, "uiHighlight", m_uiHighlight);
    FUN_140873220(pElem, "quickSlotPriority", m_quickSlotPriority);
    FUN_1408731e0(pElem, "jobLevel", m_jobLevel);
    XmlTokenList(pElem, "subSkillIDs", m_subSkillIDs);
    FUN_1408730a0(pElem, "isLearn", m_isLearn);
    XmlTokenList(pElem, "requireLevel", m_requireLevel);
    XmlTokenList(pElem, "requireSkillIDs", m_requireSkillIDs);
    XmlTokenList(pElem, "requireSkillLevels", m_requireSkillLevels);
    FUN_140873220(pElem, "requireQuestID", m_requireQuestID);
    return true;
}

// @0x140643880
bool JobSkillData::HasRequirement()
{
    if (!m_requireLevel.empty())
        return true;
    if (!m_requireSkillIDs.IsEmpty())
        return true;
    if (m_requireQuestID != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140643880, JobSkillData, HasRequirement, 90, 0xC2DEF505);

// @0x1406438e0
unsigned short JobSkillData::GetRequireLevel(unsigned short skillLevel)
{
    MS2_ASSERT_AT(55, skillLevel > 0);
    if (m_requireLevel.empty() || skillLevel <= 0)
        return 0;
    if (m_requireLevel.size() < skillLevel)
        return *m_requireLevel.rbegin();
    return m_requireLevel[skillLevel - 1];
}
MS2_REPLACE_METHOD(0x1406438E0, JobSkillData, GetRequireLevel, 184, 0x8744465C);

// @0x1406439a0
JobData::JobData()
    : m_defaultWeaponSlot(1), m_jobGroupID(Unk_JobGroupID_None), m_characterBGM(0), m_startField(2000001)
{
}

// @0x140643a60
void JobData::Load(Unk_140165cf0* pElem)
{
    XmlValue(pElem, "jobGroupID", m_jobGroupID);
    FUN_140873220(pElem, "characterBGM", m_characterBGM);
    FUN_1408731e0(pElem, "defaultWeaponSlot", m_defaultWeaponSlot);
    FUN_140873220(pElem, "startField", m_startField);
    FUN_1408733e0(pElem, "characterVoice", m_characterVoice);
    XmlTokenList(pElem, "startItems", m_startItems);
    XmlValue(pElem, "subJob1", m_subJob1);
    XmlValue(pElem, "subJob2", m_subJob2);
    Unk_140165cf0* pSkills = pElem->FUN_140165cf0("skills");
    if (pSkills != 0)
    {
    for (Unk_140165cf0* pSkill : pSkills->FUN_140165cf0("v"))
    {
        JobSkillDataPtr spSkill(new JobSkillData);
        if (spSkill->Load(pSkill))
        {
            m_skills.insert(std::make_pair(spSkill->m_skillID, spSkill));
            for (unsigned nSubId : spSkill->m_subSkillIDs)
                m_subSkills.insert(std::make_pair(nSubId, spSkill));
        }
        unsigned short nMaxLevel = 0;
        FUN_1408731a0(pSkill, "maxLevel", nMaxLevel);
        s_skillMaxLevel.SetAt(spSkill->m_skillID, nMaxLevel);
    }
    }
}

// @0x140643e40
Unk_JobGroupID JobData::GetJobGroupID()
{
    return m_jobGroupID;
}

// @0x140643e60
Unk_JobCode JobData::GetSubJob(int nIndex)
{
    switch (nIndex)
    {
    case 1:
        return m_subJob1;
    case 2:
        return m_subJob2;
    default:
        MS2_ASSERT_AT(131, 0);
        return Unk_JobCode_None;
    }
}
MS2_REPLACE_METHOD(0x140643E60, JobData, GetSubJob, 98, 0x1862B596);

// @0x140643ed0
Unk_JobCode JobData::GetSubJob1()
{
    return m_subJob1;
}

// @0x140643ef0
Unk_JobCode JobData::GetSubJob2()
{
    return m_subJob2;
}

// @0x140643f10
unsigned JobData::GetCharacterBGM()
{
    return m_characterBGM;
}

// @0x140643f30
CStringW JobData::GetName()
{
    if (FUN_1401a9d70() != 0)
        return FUN_1401a9d70()->FUN_141811980(6, m_jobGroupID);
    return L"";
}

// @0x140643fb0
unsigned JobData::GetStartField()
{
    return m_startField;
}

// @0x140643fd0
bool JobData::HasSkill(unsigned nSkillId)
{
    return GetSkillData(nSkillId).get() != 0;
}
MS2_REPLACE_METHOD(0x140643FD0, JobData, HasSkill, 119, 0x0522C08C);

// @0x140644050
bool JobData::HasSubSkill(unsigned nSkillId)
{
    return FindSubSkill(nSkillId).get() != 0;
}
MS2_REPLACE_METHOD(0x140644050, JobData, HasSubSkill, 119, 0x1D5A63AC);

// @0x1406440d0
unsigned JobData::GetSubSkillParent(unsigned nSkillId)
{
    JobSkillDataPtr spSkill = FindSubSkill(nSkillId);
    if (spSkill == 0)
        return 0;
    return spSkill->m_skillID;
}
MS2_REPLACE_METHOD(0x1406440D0, JobData, GetSubSkillParent, 122, 0x9C42EC81);

// @0x140644150
JobSkillDataPtr JobData::FindSkill(unsigned nSkillId) const
{
    SkillMap::const_iterator it = m_skills.find(nSkillId);
    if (it == m_skills.end())
        return nullptr;
    return it->second;
}
MS2_REPLACE_METHOD(0x140644150, JobData, FindSkill, 174, 0x2C648002);

// @0x140644210
JobSkillDataPtr JobData::FindSubSkill(unsigned nSkillId) const
{
    SkillMap::const_iterator it = m_subSkills.find(nSkillId);
    if (it == m_subSkills.end())
        return nullptr;
    return it->second;
}
MS2_REPLACE_METHOD(0x140644210, JobData, FindSubSkill, 174, 0xF2D68D30);

// @0x1406442d0
JobSkillDataPtr JobData::GetSkillData(unsigned nSkillId)
{
    JobSkillDataPtr spSkill = FindSkill(nSkillId);
    if (spSkill.get() != 0)
        return spSkill;
    return FindSubSkill(nSkillId);
}
MS2_REPLACE_METHOD(0x1406442D0, JobData, GetSkillData, 166, 0x2F1A3B42);

// @0x140644380
void JobData::GetSkills(std::vector<JobSkillDataPtr>& vOut)
{
    for (auto kv : m_skills)
        vOut.push_back(kv.second);
}
MS2_REPLACE_METHOD(0x140644380, JobData, GetSkills, 158, 0x6ADCB646);

// @0x140644430
unsigned short JobData::GetSkillMaxLevel(unsigned nSkillId)
{
    unsigned short nMaxLevel = 0;
    s_skillMaxLevel.Lookup(nSkillId, nMaxLevel);
    return nMaxLevel;
}

// @0x140644470
JobTable::JobTable()
{
}

// @0x1406444e0
JobTable::~JobTable()
{
}

// @0x140644540
int JobTable::Load()
{
    m_jobs.clear();
    CString strPath = FUN_14071a5b0("Table", "job.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "job", "jobGroupID", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        JobDataPtr spJob(new JobData);
        spJob->Load(pNode);
        int nJobGroup = spJob->GetJobGroupID();
        m_jobs.insert(std::make_pair(nJobGroup, spJob));
    }
    SetInit(true);
    return 1;
}

// @0x140644880
JobDataPtr JobTable::GetJobData(int nJobGroup)
{
    CheckInit();
    JobMap::iterator it = m_jobs.find(nJobGroup);
    if (it != m_jobs.end())
        return it->second;
    return nullptr;
}

// @0x140644940
unsigned JobTable::GetStartField(int nJobGroup)
{
    if (JobDataPtr spJob = GetJobData(nJobGroup))
        return spJob->GetStartField();
    return 0x400001;
}
MS2_REPLACE_METHOD(0x140644940, JobTable, GetStartField, 116, 0x4B8E2C88);

// @0x1406449c0
Unk_JobGroupID JobTable::GetJobGroupBySkill(unsigned nSkillId)
{
    CheckInit();
    for (auto& kv : m_jobs)
    {
        JobData* pJob = kv.second.get();
        if (pJob->HasSkill(nSkillId))
            return pJob->GetJobGroupID();
    }
    return Unk_JobGroupID_None;
}

// @0x140644a80
Unk_JobGroupID JobTable::GetJobGroupBySubJob(Unk_JobCode nJobCode)
{
    CheckInit();
    for (auto kv : m_jobs)
    {
        if (kv.second->GetSubJob1() == nJobCode || kv.second->GetSubJob2() == nJobCode)
            return kv.second->GetJobGroupID();
    }
    return Unk_JobGroupID_None;
}

// @0x140644b80
int JobTable::GetJobRank(int nJobCode)
{
    int nRank = nJobCode % 10;
    return nRank + 1;
}
MS2_REPLACE_METHOD(0x140644B80, JobTable, GetJobRank, 40, 0x6B395481);

// @0x140644bb0
Unk_JobCode JobTable::GetSubJob1(int nJobGroup)
{
    JobDataPtr spJob = GetJobData(nJobGroup);
    if (spJob == 0)
        return Unk_JobCode_None;
    return spJob->GetSubJob1();
}
MS2_REPLACE_METHOD(0x140644BB0, JobTable, GetSubJob1, 127, 0x4EBB30A6);
