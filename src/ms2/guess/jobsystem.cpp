// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). JobSkill / JobSystem: a character's job skill tree state
// (learned skills and levels, skill points by rank). The TU right before commonfiles\jobtable.cpp, ending with its
// own memmove_s copy at 0x140643530; it has no __FILE__ string, so the name is a guess from the classes.
// The skill map is a std::unordered_map: its emplace is _List.emplace_front + _Hash::_Insert (0x14063b4f0).
// MS2-UNIT: ?\jobsystem.cpp
// MS2-RANGE: 0x140637b00-0x140643650 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Insert@AEAU?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@std@@@2@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VJobSkill@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@1@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@std@@@1@@Z 0x14063b4f0 ; unique
// MS2-PIN: ??0?$unordered_map@IV?$MS2Ptr@VJobSkill@@@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@3@@std@@QEAA@XZ 0x14063e440 ; unique
// MS2-PIN: ?FindNextNode@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x14063f2a0 ; unique
// MS2-PIN: ?GetKeyAt@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEBAAEBIPEAU__POSITION@@@Z 0x14063f360 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14063f3d0 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x14063f420 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAAEAGPEAU__POSITION@@@Z 0x14063f490 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEBA_NXZ 0x14063f500 ; unique
// MS2-PIN: ?_Hashval@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VJobSkill@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@3@$0A@@std@@@std@@IEBA_KAEBI@Z 0x140640e80 ; unique
// MS2-PIN: ?_Max_bucket_size@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VJobSkill@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@3@$0A@@std@@@std@@IEAAAEAMXZ 0x140641360 ; unique
// MS2-PIN: ?_Unchecked_begin@?$vector@IV?$allocator@I@std@@@std@@QEAAPEAIXZ 0x1406420c0 ; unique
// MS2-PIN: ?_Unchecked_end@?$vector@IV?$allocator@I@std@@@std@@QEAAPEAIXZ 0x140642190 ; unique
// MS2-PIN: ?lower_bound@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VJobSkill@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@std@@@2@AEBI@Z 0x1406430a0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\jobsystem.cpp"   // guessed (no asserts)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/jobsystem.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit callees.
JobTable* FUN_1401d7a50();                              // the JobTable singleton
class Unk_JobSkillTable { public: MS2Ptr<SkillData> FUN_1407ee1d0(int nSkillId); };
Unk_JobSkillTable* FUN_1401958b0();                     // the skill table


// @0x140637b00
JobSkill::JobSkill(unsigned nId)
    : m_nId(nId), m_nLevel(1), m_bChanged(false), m_bLearned(false), m_bExtra(false)
{
}

// @0x140637ba0
bool JobSkill::Init(JobData* pJob)
{
    m_spData = pJob->GetSkillData(GetID());
    if (!m_bExtra && m_spData == 0)
        return false;
    m_spSkill = JobSystem::GetSkillData(GetID());
    if (m_spSkill == 0)
        return false;
    return true;
}

// @0x140637cc0
unsigned JobSkill::GetID()
{
    return m_nId;
}

// @0x140637ce0
int JobSkill::GetUsedPoint()
{
    MS2Ptr<SkillData> spSkill = JobSystem::GetSkillData(m_nId);
    if (spSkill == 0)
        return 0;
    if (IsSubSkill())
        return 0;
    if (IsLearn() || m_bExtra)
    {
        return m_nLevel - 1;
    }
    else
    {
        if (!m_bLearned)
            return 0;
        return m_nLevel;
    }
}

// @0x140637e00
int JobSkill::GetJobLevel()
{
    if (m_spData == 0)
        return 0;
    return m_spData->m_jobLevel;
}

// @0x140637e50
bool JobSkill::IsSubSkill()
{
    if (m_spData == 0)
        return false;
    return GetID() != m_spData->m_skillID;
}

// @0x140637ec0
bool JobSkill::IsLearn()
{
    if (m_spData == 0)
        return false;
    return m_spData->m_isLearn;
}

// @0x140637f10
unsigned JobSkill::GetQuickSlotPriority()
{
    if (m_spData == 0)
        return 0xffffffff;
    return m_spData->m_quickSlotPriority;
}

// @0x140637f60
JobSkillData* JobSkill::GetData()
{
    return m_spData.get();
}

// @0x140637f90
void JobSkill::Write(COutputStream& os)
{
    os.WriteInt32(m_nLevel);
    os.WriteBool(m_bChanged);
    os.WriteBool(m_bLearned);
    os.WriteBool(m_bExtra);
}

// @0x140638020
void JobSkill::Read(CByteBuffer& buf)
{
    m_nLevel = buf.ReadInt32();
    m_bChanged = buf.ReadBool();
    m_bLearned = buf.ReadBool();
    m_bExtra = buf.ReadBool();
}

// @0x1406380e0
JobSystem::JobSystem()
    : m_nTotalPoint(0), m_nRank(0)
{
}

// @0x140638180
JobSystem::~JobSystem()
{
}

// @0x140638200
void JobSystem::SetJob(int nJobGroup, int nJobCode, unsigned short nLevel)
{
    if (!FUN_1401d7a50()->GetJobData(nJobGroup))
        return;
    int nRank = FUN_1401d7a50()->GetJobRank(nJobCode);
    Unk_CriticalSectionLock lock(m_lock, 1);
    InitSkills(nJobGroup, nRank);
    RecalcPoints();
}

// @0x1406382e0
// MS2-FUNCTIONAL: the exe frame is 0x10 larger (the lock at rsp+0x70 instead of 0x60; temporaries ordered differently)
bool JobSystem::ChangeJob(int nJobGroup, int nRank, unsigned short nLevel)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!FUN_1401d7a50()->GetJobData(nJobGroup))
        return false;
    ATL::CAtlMap<unsigned, unsigned short> learned;
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        if (spSkill->m_bLearned)
        {
            if (spSkill->m_nLevel > 1)
                learned.SetAt(spSkill->GetID(), spSkill->m_nLevel);
        }
    }
    InitSkills(nJobGroup, nRank);
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        if (spSkill->m_bLearned)
            spSkill->m_bChanged = true;
    }
    POSITION pos = learned.GetStartPosition();
    while (pos != 0)
    {
        unsigned nSkillId = learned.GetKeyAt(pos);
        if (vfunc_2(nSkillId))
            SetSkill(nSkillId, learned.GetValueAt(pos), true);
        learned.GetNext(pos);
    }
    RecalcPoints();
    return true;
}

// @0x140638690
// MS2-FUNCTIONAL: the exe frame has one more 4-byte slot below the locals (every local 4 bytes higher)
MS2Ptr<SkillLevelData> JobSystem::vfunc_1(unsigned nSkillId)
{
    unsigned short nBonus = vfunc_5(nSkillId);
    Unk_CriticalSectionLock lock(m_lock, 1);
    JobSkillPtr spSkill = FindSkill(nSkillId);
    if (spSkill.get() != 0)
    {
        MS2Ptr<SkillData> spData = GetSkillData(spSkill->GetID());
        if (spData == 0)
            return 0;
        unsigned short nLevel = spSkill->m_bLearned ? spSkill->m_nLevel : 0;
        unsigned short nCur = spData->GetMaxLevel() < nLevel + nBonus ? spData->GetMaxLevel() : nLevel + nBonus;
        return spData->FUN_1407e90a0(nCur);
    }
    MS2Ptr<SkillData> spData = GetSkillData(nSkillId);
    if (spData.get() != 0 && !spData->FUN_1407e9f30())
        return spData->FUN_1407e90a0(1);
    return 0;
}

// @0x140638980
bool JobSystem::vfunc_2(unsigned nSkillId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    JobSkillPtr spSkill = FindSkill(nSkillId);
    if (spSkill.get() != 0)
        return spSkill->m_bLearned;
    return false;
}

// @0x140638a30
void JobSystem::vfunc_3(int nJobGroup, unsigned nSkillId, unsigned short nLevel)
{
    if (GetJobGroupID() != nJobGroup)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!FindSkill(nSkillId))
    {
        JobSkillPtr spSkill(new JobSkill(nSkillId));
        spSkill->m_nLevel = nLevel;
        spSkill->m_bChanged = true;
        spSkill->m_bLearned = true;
        spSkill->m_bExtra = true;
        if (!spSkill->Init(m_spJob.get()))
            return;
        m_skills.insert(std::make_pair(spSkill->GetID(), spSkill));
    }
    RecalcPoints();
}

// @0x140638c70
void JobSystem::vfunc_4(unsigned short nLevel)
{
}

// @0x140638c90
unsigned short JobSystem::vfunc_5(unsigned nSkillId)
{
    return 0;
}

// @0x140638cb0
void JobSystem::vfunc_6(COutputStream& os)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    os.WriteInt32(m_nRank);
    if (GetJobData().get())
    {
        os.WriteInt32(GetJobData()->GetJobGroupID());
        os.WriteUInt8((unsigned char)m_skills.size());
        for (auto& kv : m_skills)
        {
            JobSkillPtr spSkill = kv.second;
            os.WriteInt32(spSkill->GetID());
            spSkill->Write(os);
        }
    }
    RecalcPoints();
}

// @0x140638f10
void JobSystem::vfunc_7(CByteBuffer& buf)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nRank = buf.ReadInt32();
    int nJobGroup = buf.ReadInt32();
    m_spJob = FUN_1401d7a50()->GetJobData(nJobGroup);
    m_skills.clear();
    int nCount = buf.ReadUInt8();
    for (int i = 0; i < nCount; i++)
    {
        unsigned nSkillId = buf.ReadInt32();
        JobSkillPtr spSkill(new JobSkill(nSkillId));
        spSkill->Read(buf);
        if (!spSkill->Init(m_spJob.get()))
            continue;
        m_skills.insert(std::make_pair(spSkill->GetID(), spSkill));
    }
    RecalcPoints();
}

// @0x140639210
MS2Ptr<SkillData> JobSystem::GetSkillData(unsigned nSkillId)
{
    return FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
}

// @0x140639260
int JobSystem::GetLevelSkillPoint(unsigned short nLevel, int nType)
{
    if (nLevel < 10)
        return 0;
    if (nType == 1)
    {
        return (nLevel < FUN_1401d3200()->SkillPointLimitLevel1 ? nLevel : FUN_1401d3200()->SkillPointLimitLevel1) - 9;
    }
    else if (nType == 2)
    {
        if (nLevel < 60)
            return 0;
        return (nLevel < FUN_1401d3200()->SkillPointLimitLevel2 ? nLevel : FUN_1401d3200()->SkillPointLimitLevel2) - 59;
    }
    return 0;
}

// @0x140639340
Unk_JobGroupID JobSystem::GetJobGroupID()
{
    if (!GetJobData())
        return Unk_JobGroupID_None;
    return GetJobData()->GetJobGroupID();
}

// @0x1406393f0
Unk_JobCode JobSystem::GetSubJob()
{
    if (GetJobData() == 0)
        return Unk_JobCode_None;
    return GetJobData()->GetSubJob(m_nRank);
}

// @0x1406394b0
int JobSystem::GetRank()
{
    return m_nRank;
}

// @0x1406394d0
JobSkillPtr JobSystem::FindSkill(unsigned nSkillId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    SkillMap::iterator it = m_skills.find(nSkillId);
    if (it != m_skills.end())
        return it->second;
    return nullptr;
}

// @0x1406395c0
void JobSystem::GetSkills(std::vector<JobSkillPtr>& vOut, int bLearnedOnly, bool bNoSubSkills)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        if (bLearnedOnly != 0 && !spSkill->m_bLearned)
            continue;
        if (bNoSubSkills && spSkill->IsSubSkill())
            continue;
        vOut.push_back(spSkill);
    }
}

// @0x140639710
void JobSystem::SetSkill(unsigned nSkillId, unsigned short nLevel, bool bLearned)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    JobSkillPtr spSkill = FindSkill(nSkillId);
    if (spSkill.get() != 0)
    {
        spSkill->m_nLevel = nLevel;
        spSkill->m_bChanged = false;
        if (spSkill->m_bLearned != bLearned && bLearned)
            spSkill->m_bChanged = true;
        spSkill->m_bLearned = bLearned;
        SyncSubSkills(spSkill);
    }
}

// @0x140639840
void JobSystem::ClearChanged()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        spSkill->m_bChanged = false;
    }
}

// @0x140639920
void JobSystem::SetRank(unsigned short nLevel, int nJobCode)
{
    m_nRank = FUN_1401d7a50()->GetJobRank(nJobCode);
    UpdateLearnable(nLevel);
}

// @0x140639970
void JobSystem::RecalcPoints()
{
    std::vector<JobSkillPtr> skills;
    GetSkills(skills, 1, false);
    if (skills.empty())
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nTotalPoint = 0;
    m_usedPoints.clear();
    for (auto& spSkill : skills)
    {
        if (spSkill == 0)
            continue;
        int nJobLevel = spSkill->GetJobLevel();
        int nPoint = spSkill->GetUsedPoint();
        m_usedPoints[nJobLevel] += nPoint;
        m_nTotalPoint += nPoint;
    }
}

// @0x140639b20
int JobSystem::GetTotalPoint()
{
    return m_nTotalPoint;
}

// @0x140639b40
int JobSystem::GetUsedPoint(int nJobLevel)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_usedPoints[nJobLevel];
}

// @0x140639bb0
JobDataPtr JobSystem::GetJobData()
{
    return m_spJob;
}

// @0x140639c00
void JobSystem::InitSkills(int nJobGroup, int nRank)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_spJob = FUN_1401d7a50()->GetJobData(nJobGroup);
    m_nRank = nRank;
    m_skills.clear();
    std::vector<JobSkillDataPtr> skills;
    m_spJob->GetSkills(skills);
    for (auto& spData : skills)
        AddSkill(spData);
}

// @0x140639d90
void JobSystem::UpdateLearnable(unsigned short nLevel)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        if (!spSkill->IsLearn())
            continue;
        bool bWasLearned = spSkill->m_bLearned;
        spSkill->m_bLearned = m_nRank >= spSkill->GetJobLevel();
        spSkill->m_bChanged = !bWasLearned && spSkill->m_bLearned;
        SyncSubSkills(spSkill);
    }
    RecalcPoints();
}

// @0x140639f70
void JobSystem::AddSkill(JobSkillDataPtr spData)
{
    if (spData == 0)
        return;
    JobSkillPtr spSkill(new JobSkill(spData->m_skillID));
    if (!spSkill->Init(m_spJob.get()))
        return;
    if (spSkill->IsLearn())
        spSkill->m_bLearned = m_nRank >= spSkill->GetJobLevel();
    m_skills.insert(std::make_pair(spSkill->GetID(), spSkill));
    for (auto& nSubId : spData->m_subSkillIDs)
    {
        JobSkillPtr spSub(new JobSkill(nSubId));
        if (!spSub->Init(m_spJob.get()))
            continue;
        spSub->m_bLearned = spSkill->m_bLearned;
        m_skills.insert(std::make_pair(spSub->GetID(), spSub));
    }
}

// @0x14063a330
void JobSystem::SyncSubSkills(JobSkillPtr spSkill)
{
    if (spSkill == 0)
        return;
    JobSkillDataPtr spData = m_spJob->FindSkill(spSkill->GetID());
    if (spData == 0)
        return;
    for (unsigned nSubId : spData->m_subSkillIDs)
    {
        JobSkillPtr spSub = FindSkill(nSubId);
        if (spSub == 0)
            continue;
        MS2Ptr<SkillData> spSubData = GetSkillData(nSubId);
        if (spSubData == 0)
            continue;
        spSub->m_bLearned = spSkill->m_bLearned;
        spSub->m_nLevel = spSubData->FUN_1407e9ac0() < spSkill->m_nLevel ? spSubData->FUN_1407e9ac0() : spSkill->m_nLevel;
    }
}

// @0x140643530
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

