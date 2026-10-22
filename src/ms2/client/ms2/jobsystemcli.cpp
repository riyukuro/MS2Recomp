// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). JobSystemCli: see jobsystemcli.h.
// MS2-UNIT: ?\jobsystemcli.cpp
// MS2-RANGE: 0x140a6d890-0x140a6e830 .text$mn
// MS2-PIN: ??_GJobSystemCli@@UEAAPEAXI@Z 0x140a6e6d0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\jobsystemcli.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "jobsystemcli.h"

#include <vector>

#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// ---- unit-local views of exe types ----

class Unk_JscSkillRow : public CPtred { public: bool FUN_1407e9f30(); };

class Unk_JscSkillTable
{
public:
    MS2Ptr<Unk_JscSkillRow> FUN_1407ee1d0(int nSkillId);
    MS2Ptr<SkillLevelData> FUN_1407ee2f0(int nSkillId, short nLevel);
};
Unk_JscSkillTable* FUN_1401958b0();

class Unk_JscSkillSet : public CPtred
{
public:
    unsigned short FUN_140809560(int nSkillId);                 // the level of the skill in the set
    int FUN_140809410(int nSkillId, int a1);                    // the set contains the skill
};
class Unk_JscTree : public CPtred { public: unsigned short FUN_14080baf0(int nSkillId); };   // the tier option level
class Unk_JscSkillSys { public: MS2Ptr<Unk_JscSkillSet> FUN_141768380(); };
class Unk_JscPlayer
{
public:
    Unk_JscSkillSys* FUN_141523bc0();
    unsigned short FUN_14152fce0(int nSkillId);                 // the override level of the skill
    MS2Ptr<Unk_JscTree> FUN_1409eee00();
};
Unk_JscPlayer* FUN_1409613d0(PCBase* pPC);                      // the MyPC of a PC, or 0

class Unk_JscOptions { public: bool FUN_14036d570(int nId); };
Unk_JscOptions* FUN_140166410();

int FUN_14165c570(PCBase* pPC);                                 // the active stance skill
void FUN_14165c720(PCBase* pPC, int nSkillId, unsigned short nLevel);
void FUN_1401fdb50(unsigned char* payload, COutputStream& stream);
void FUN_140710590(COutPacket& packet);
JobSkillPtr* FUN_1406420e0(std::vector<JobSkillPtr>* pVec);       // begin
JobSkillPtr* FUN_1406421b0(std::vector<JobSkillPtr>* pVec);       // end

// @0x140a6d890
JobSystemCli::JobSystemCli()
{
    m_pOwner = 0;
}

// @0x140a6d8e0
void JobSystemCli::SetOwner(PCBase* pOwner)
{
    m_pOwner = pOwner;
}

// @0x140a6d910
MS2Ptr<SkillLevelData> JobSystemCli::vfunc_1(unsigned nSkillId)
{
    Unk_JscPlayer* pPlayer = FUN_1409613d0(m_pOwner);
    if (pPlayer != 0)
    {
        MS2Ptr<Unk_JscSkillSet> spSet = pPlayer->FUN_141523bc0()->FUN_141768380();
        if (spSet.get() != 0)
        {
            unsigned short nLevel = spSet->FUN_140809560(nSkillId);
            if (nLevel != 0)
                return FUN_1401958b0()->FUN_1407ee2f0(nSkillId, nLevel);
        }
        if (FUN_140166410()->FUN_14036d570(0xd3))
        {
            unsigned short nLevel = pPlayer->FUN_14152fce0(nSkillId);
            if (nLevel != 0)
                return FUN_1401958b0()->FUN_1407ee2f0(nSkillId, nLevel);
        }
    }
    return JobSystem::vfunc_1(nSkillId);
}

// @0x140a6da90
// MS2-FUNCTIONAL: the exe keeps one GetJobData()/tree temp per use and releases the row / set on each exit path; cl orders the temps differently
bool JobSystemCli::vfunc_2(unsigned nSkillId)
{
    MS2Ptr<Unk_JscSkillRow> spRow = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
    if (spRow.IsNull())
        return false;
    if (!spRow->FUN_1407e9f30())
        return true;
    Unk_JscPlayer* pPlayer = FUN_1409613d0(m_pOwner);
    if (pPlayer != 0)
    {
        MS2Ptr<Unk_JscSkillSet> spSet = pPlayer->FUN_141523bc0()->FUN_141768380();
        if (spSet.get() != 0)
        {
            if (spSet->FUN_140809410(nSkillId, 0) != 0)
                return true;
        }
        if (pPlayer->FUN_1409eee00()->FUN_14080baf0(nSkillId) != 0)
            return true;
        if (FUN_140166410()->FUN_14036d570(0xd3) && pPlayer->FUN_14152fce0(nSkillId) != 0)
            return true;
        if (GetJobData().get() != 0)
        {
            int nMain = GetJobData()->GetSubSkillParent(nSkillId);
            if (nMain != 0)
            {
                if (pPlayer->FUN_1409eee00()->FUN_14080baf0(nMain) != 0)
                    return true;
            }
        }
    }
    return JobSystem::vfunc_2(nSkillId);
}

// @0x140a6de30
void JobSystemCli::vfunc_3(int nJobGroup, unsigned nSkillId, unsigned short nLevel)
{
    JobSystem::vfunc_3(nJobGroup, nSkillId, nLevel);
    NotifySkill(nSkillId, nLevel);
}

// @0x140a6de80
void JobSystemCli::vfunc_4(unsigned short nLevel)
{
    UpdateLearnable(nLevel);
    Refresh();
}

// @0x140a6dec0
// MS2-FUNCTIONAL: temp lifetimes of the tree / job data MS2Ptrs differ (frame 0x88 vs 0x78)
unsigned short JobSystemCli::vfunc_5(unsigned nSkillId)
{
    Unk_JscPlayer* pPlayer = FUN_1409613d0(m_pOwner);
    if (pPlayer == 0)
        return 0;
    unsigned short nLevel = pPlayer->FUN_1409eee00()->FUN_14080baf0(nSkillId);
    if (nLevel != 0)
        return nLevel;
    if (GetJobData().IsNull())
        return 0;
    int nMain = GetJobData()->GetSubSkillParent(nSkillId);
    if (nMain == 0)
        return 0;
    return pPlayer->FUN_1409eee00()->FUN_14080baf0(nMain);
}

// @0x140a6e0a0
void JobSystemCli::vfunc_7(CByteBuffer& buf)
{
    JobSystem::vfunc_7(buf);
    Refresh();
}

// @0x140a6e0e0
void JobSystemCli::RequestReset()
{
    COutPacket packet(static_cast<int>(SendOp::Job), 0);
    packet.WriteUInt8(8);
    FUN_140710590(packet);
}

// @0x140a6e140
void JobSystemCli::RequestSkill(unsigned __int64 nSerial, int nSkill, unsigned short nLevel)
{
    SendRequest(GetJobGroupID(), nSerial, nSkill, nLevel);
}

// @0x140a6e190
void JobSystemCli::SendRequest(int nJob, unsigned __int64 nSerial, int nSkill, unsigned short nLevel)
{
    Request request;
    request.m_nJob = nJob;
    request.m_nSerial = nSerial;
    request.m_nSkill = nSkill;
    request.m_nLevel = nLevel;
    COutPacket packet(static_cast<int>(SendOp::Job), 0);
    packet.WriteUInt8(7);
    FUN_1401fdb50((unsigned char*)&request, packet);
    FUN_140710590(packet);
}

// @0x140a6e240
// MS2-FUNCTIONAL: the exe holds the lock state in a local and runs the loop on raw element pointers; cl lays out the frame differently
void JobSystemCli::Refresh()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::vector<JobSkillPtr> skills;
    GetSkills(skills, 1, false);
    for (JobSkillPtr* it = FUN_1406420e0(&skills); it != FUN_1406421b0(&skills); it++)
    {
        if (!it->IsNull())
            NotifySkill((*it)->GetID(), (*it)->m_nLevel);
    }
}

// @0x140a6e360
// MS2-FUNCTIONAL: local layout of the lock / skill pointer differs (the exe stores the raw skill pointer in a local)
void JobSystemCli::RefreshActiveStance()
{
    if (m_pOwner != 0)
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        JobSkillPtr spSkill = FindSkill(1);
        if (spSkill.get() != 0)
            NotifySkill(FUN_14165c570(m_pOwner), spSkill->m_nLevel);
    }
}

// @0x140a6e430
void JobSystemCli::NotifySkill(int nSkillId, unsigned short nLevel)
{
    if (m_pOwner != 0)
    {
        MS2Ptr<Unk_JscSkillRow> spRow = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
        if (spRow.IsNull())
            return;
        FUN_14165c720(m_pOwner, nSkillId, nLevel);
    }
}

// @0x140a6e4d0
// MS2-FUNCTIONAL: iterator temp placement of the map loop differs
int JobSystemCli::ChangedMainSkills()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int nCount = 0;
    for (SkillMap::iterator it = m_skills.begin(); it != m_skills.end(); ++it)
    {
        JobSkillPtr spSkill = it->second;
        if (spSkill->m_bChanged)
        {
            MS2Ptr<SkillData> spData = GetSkillData(spSkill->GetID());
            if (spData.get() != 0)
            {
                if (!spSkill->IsSubSkill())
                    nCount++;
            }
        }
    }
    return nCount;
}

// @0x140a6e640
int JobSystemCli::FUN_140a6e640()
{
    if (GetJobGroupID() == 1)
        return 0;
    return GetJobGroupID();
}

// @0x140a6e670
JobSystemCli::Request::Request()
    : m_nJob(1), m_nSerial(0), m_nSkill(0), m_nLevel(0)
{
}

// @0x140a6e6b0
// MS2-FUNCTIONAL: the exe dtor is a bare call into the base destructor without the vftable store
JobSystemCli::~JobSystemCli()
{
}

MS2_EMIT_CRT_MEMMOVE_S();
