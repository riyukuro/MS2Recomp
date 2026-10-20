// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSkillPointSimulator: the skill window's point
// distribution preview (two JobSkill trees, snapshot and edit). Template glue: CAtlMap<unsigned, MS2Ptr<JobSkill>>,
// std::map<int, long> copy assignment, the JobSkill copy constructor.
// MS2-UNIT: ?\skillpointsimulator.cpp
// MS2-RANGE: 0x140abc2b0-0x140ac02e0 .text$mn
// MS2-PIN: ?get@?$MS2Ptr@VJobSkill@@@@QEBAPEAVJobSkill@@XZ 0x140abf080
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\skillpointsimulator.cpp"   // guessed (no asserts)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/skillpointsimulator.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit callees.
JobTable* FUN_1401d7a50();                              // the JobTable singleton
class Unk_SpSkillTable { public: MS2Ptr<SkillData> FUN_1407ee1d0(int nSkillId); };
Unk_SpSkillTable* FUN_1401958b0();                      // the skill table
void* FUN_1403ed2d0();                                  // the game
void* FUN_141bd0cc0(void*);                             // the local player
JobSystem* FUN_1416546d0(void*);                        // its job system
char* FUN_141523ba0(void*);                             // its quest state holder
int FUN_140745590(void*, unsigned nQuestId);            // quest completed

// @0x140abc2b0
CSkillPointSimulator::CSkillPointSimulator()
    : m_nLevel(0), m_nJobCode(0), m_nJobRank(0), m_mapSnapshot(17, 0.75f, 0.25f, 2.25f, 10),
      m_mapEdit(17, 0.75f, 0.25f, 2.25f, 10), m_mapUnused(17, 0.75f, 0.25f, 2.25f, 10), m_nSpent(0), m_nRemain(0),
      m_nBonus(0)
{
}

// @0x140abc450
CSkillPointSimulator::~CSkillPointSimulator()
{
}

// @0x140abc500
void CSkillPointSimulator::Reset(unsigned short nLevel, int nJobCode, std::vector<JobSkillPtr>& skills, PointMap& extra, int nBonus)
{
    m_mapSnapshot.RemoveAll();
    m_mapEdit.RemoveAll();
    m_nJobCode = nJobCode;
    m_nJobRank = FUN_1401d7a50()->GetJobRank(nJobCode);
    m_nLevel = nLevel;
    m_mapExtra = extra;
    m_nSpent = 0;
    m_mapRemain.clear();
    m_mapSpent.clear();
    m_nBonus = nBonus;
    for (auto& spSrc : skills)
    {
        JobSkillPtr spSnapshot(new JobSkill(*spSrc.get()));
        JobSkillPtr spEdit(new JobSkill(*spSrc.get()));
        m_mapSnapshot.SetAt(spSrc->GetID(), spSnapshot);
        m_mapEdit.SetAt(spSrc->GetID(), spEdit);
    }
    Recalc();
}

// @0x140abc7a0
void CSkillPointSimulator::SetLevel(unsigned short nLevel)
{
    m_nLevel = nLevel;
    Recalc();
}

// @0x140abc7e0
void CSkillPointSimulator::SetExtraPoints(PointMap& extra)
{
    m_mapExtra = extra;
    Recalc();
}

// @0x140abc820
int CSkillPointSimulator::GetTotalPoints(int nType)
{
    return m_mapTotal[nType];
}

// @0x140abc860
int CSkillPointSimulator::GetRemainPoints(int nType)
{
    return m_mapRemain[nType];
}

// @0x140abc8a0
int CSkillPointSimulator::GetSpentPoints(int nType)
{
    return m_mapSpent[nType];
}

// @0x140abc8e0
CSkillPointSimulator::SkillMap& CSkillPointSimulator::GetEditSkills()
{
    return m_mapEdit;
}

// @0x140abc900
JobSkillPtr CSkillPointSimulator::GetSnapshotSkill(unsigned nSkillId)
{
    JobSkillPtr sp(0);
    m_mapSnapshot.Lookup(nSkillId, sp);
    return sp;
}

// @0x140abc980
JobSkillPtr CSkillPointSimulator::GetEditSkill(unsigned nSkillId)
{
    JobSkillPtr sp(0);
    m_mapEdit.Lookup(nSkillId, sp);
    return sp;
}

// @0x140abca00
void CSkillPointSimulator::Recalc()
{
    m_mapTotal.clear();
    for (int nRank = 1; nRank < 3; nRank++)
    {
        int nKey = nRank;
        int nBase = JobSystem::GetLevelSkillPoint(m_nLevel, nRank);
        int nExtra = m_mapExtra[nKey];
        int nTotal = nBase + nExtra + m_nBonus;
        m_mapTotal[nKey] = nTotal;
    }
    m_nSpent = 0;
    m_nRemain = 0;
    m_mapRemain.clear();
    m_mapSpent.clear();
    PointMap used;
    for (POSITION pos = m_mapEdit.GetStartPosition(); pos != 0; m_mapEdit.GetNext(pos))
    {
        JobSkillPtr sp = m_mapEdit.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (!sp->m_bLearned)
            continue;
        int nKey = sp->GetJobLevel();
        long* pnUsed = &used[nKey];
        *pnUsed += sp->GetUsedPoint();
        m_nSpent += sp->GetUsedPoint();
    }
    for (int nRank = 1; nRank < 3; nRank++)
    {
        m_mapSpent[nRank] = used[nRank];
        int nTotal = GetTotalPoints(nRank);
        int nLeft = nTotal - used[nRank] < 1 ? 0 : nTotal - used[nRank];
        int nRemain = nLeft;
        m_mapRemain[nRank] = nRemain;
        m_nRemain += nRemain;
    }
}

// MS2-FUNCTIONAL: exe reloads the skill id via ecx->r8d and keeps one fewer 4-byte local (register/temp allocation; same callees and control flow)
// @0x140abcd70
int CSkillPointSimulator::Validate(unsigned* pnBadSkill)
{
    unsigned nSum = 0;
    for (POSITION pos = m_mapEdit.GetStartPosition(); pos != 0; m_mapEdit.GetNext(pos))
    {
        JobSkillPtr sp = m_mapEdit.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (!sp->m_bLearned)
            continue;
        *pnBadSkill = sp->GetID();
        int nSkillId = sp->GetID();
        MS2Ptr<SkillData> spSkill = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
        if (spSkill == 0)
            return 0;
        if (spSkill->FUN_1407e9ac0() < sp->m_nLevel)
            return 0;
        if (!CheckRequirements(sp->GetID(), sp->m_nLevel))
            return 0;
        nSum += sp->GetUsedPoint();
    }
    return nSum <= m_nSpent;
}

// @0x140abcfe0
int CSkillPointSimulator::LevelUp(unsigned nSkillId)
{
    JobSkillPtr sp = GetEditSkill(nSkillId);
    if (sp == 0)
        return 0;
    if (!CanLevelUp(nSkillId))
        return 0;
    int nId = sp->GetID();
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->FUN_1407ee1d0(nId);
    if (spSkill == 0)
        return 0;
    if (!sp->m_bLearned)
    {
        sp->m_bLearned = true;
    }
    else
    {
        int nMaxLevel = spSkill->FUN_1407e9ac0();
        if (nMaxLevel < sp->m_nLevel + 1)
            return 0;
        sp->m_nLevel += 1;
    }
    Recalc();
    return 1;
}

// @0x140abd1b0
int CSkillPointSimulator::LevelDown(unsigned nSkillId, unsigned* pnBadSkill)
{
    JobSkillPtr sp = GetEditSkill(nSkillId);
    if (sp == 0)
        return 0;
    if (!CanLevelDown(nSkillId))
        return 0;
    unsigned short nOldLevel = sp->m_nLevel;
    bool bOldLearned = sp->m_bLearned;
    if (!sp->IsLearn())
    {
        if (sp->m_nLevel == 1)
            sp->m_bLearned = false;
        else
            sp->m_nLevel -= 1;
    }
    else
    {
        if (sp->m_nLevel == 1)
            return 0;
        sp->m_nLevel -= 1;
    }
    if (!Validate(pnBadSkill))
    {
        sp->m_nLevel = nOldLevel;
        sp->m_bLearned = bOldLearned;
        return 0;
    }
    Recalc();
    return 1;
}

// @0x140abd3b0
int CSkillPointSimulator::CanLevelUp(unsigned nSkillId)
{
    JobSkillPtr sp = GetEditSkill(nSkillId);
    if (sp == 0)
        return 0;
    if (!GetRemainPoints(sp->GetJobLevel()))
        return 0;
    int nId = sp->GetID();
    MS2Ptr<SkillData> spSkill = FUN_1401958b0()->FUN_1407ee1d0(nId);
    if (spSkill == 0)
        return 0;
    if (sp->m_bLearned)
    {
        unsigned nMaxLevel = spSkill->FUN_1407e9ac0();
        if ((int)nMaxLevel <= (int)sp->m_nLevel)
            return 0;
    }
    if (m_nJobRank < sp->GetJobLevel())
        return 0;
    short nNext = sp->m_nLevel;
    if (sp->m_bLearned)
        nNext++;
    return CheckRequirements(sp->GetID(), nNext);
}

// @0x140abd5f0
int CSkillPointSimulator::CanLevelDown(unsigned nSkillId)
{
    JobSkillPtr sp = GetEditSkill(nSkillId);
    if (sp == 0)
        return 0;
    if (!sp->m_bLearned)
        return 0;
    if (sp->GetJobLevel() > m_nJobRank)
        return 0;
    if (sp->IsLearn() || sp->m_bExtra)
    {
        if (sp->m_nLevel > 1)
            return 1;
    }
    else if (sp->m_nLevel >= 1)
        return 1;
    return 0;
}

// @0x140abd760
int CSkillPointSimulator::CheckRequirements(unsigned nSkillId, unsigned short nLevel)
{
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    JobDataPtr spJob = FUN_1416546d0(pPlayer)->GetJobData();
    if (spJob == 0)
        return 0;
    JobSkillDataPtr spData = spJob->FindSkill(nSkillId);
    if (spData == 0)
        return 1;
    if (m_nLevel < spData->GetRequireLevel(nLevel))
        return 0;
    ATL::CAtlArray<unsigned>* pIds = &spData->m_requireSkillIDs;
    ATL::CAtlArray<unsigned short>* pLevels = &spData->m_requireSkillLevels;
    for (unsigned i = 0; i < pIds->GetCount(); i++)
    {
        JobSkillPtr spReq = GetEditSkill((*pIds)[i]);
        if (spReq == 0)
            return 0;
        if (!spReq->m_bLearned)
            return 0;
        int nReqLevel = spReq->m_nLevel;
        if (nReqLevel < (*pLevels)[i])
            return 0;
    }
    if (spData->m_requireQuestID != 0)
    {
        JobSkillData* pData = spData.operator->();
        char* pQuest = FUN_141523ba0(pPlayer);
        if (!FUN_140745590(pQuest + 0x10, pData->m_requireQuestID))
            return 0;
    }
    return 1;
}

// @0x140abdac0
void CSkillPointSimulator::GetChanged(std::vector<JobSkillPtr>& out, int nRank)
{
    for (POSITION pos = m_mapEdit.GetStartPosition(); pos != 0; m_mapEdit.GetNext(pos))
    {
        JobSkillPtr spEdit = m_mapEdit.GetValueAt(pos);
        if (spEdit == 0)
            continue;
        JobSkillPtr spOld(0);
        m_mapSnapshot.Lookup(spEdit->GetID(), spOld);
        if (spOld == 0)
            continue;
        if (nRank != 0 && nRank != spEdit->GetJobLevel())
            continue;
        if (spOld->m_bLearned != spEdit->m_bLearned)
        {
            out.push_back(spEdit);
        }
        else
        {
            if (spOld->m_nLevel != spEdit->m_nLevel)
                out.push_back(spEdit);
        }
    }
}

// @0x140abdc90
void CSkillPointSimulator::GetMerged(std::vector<JobSkillPtr>& out, int nRank)
{
    for (POSITION pos = m_mapEdit.GetStartPosition(); pos != 0; m_mapEdit.GetNext(pos))
    {
        JobSkillPtr spEdit = m_mapEdit.GetValueAt(pos);
        if (spEdit == 0)
            continue;
        JobSkillPtr spOld(0);
        m_mapSnapshot.Lookup(spEdit->GetID(), spOld);
        if (spOld == 0)
            continue;
        if (nRank != 0 && nRank != spEdit->GetJobLevel())
            out.push_back(spOld);
        else
            out.push_back(spEdit);
    }
}

// @0x140abddf0
void CSkillPointSimulator::GetSnapshot(std::vector<JobSkillPtr>& out, int nRank)
{
    for (POSITION pos = m_mapSnapshot.GetStartPosition(); pos != 0; m_mapSnapshot.GetNext(pos))
    {
        JobSkillPtr sp = m_mapSnapshot.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (nRank != 0)
        {
            if (nRank != sp->GetJobLevel())
                continue;
        }
        out.push_back(sp);
    }
}

// @0x140abdef0
int CSkillPointSimulator::IsChanged()
{
    for (POSITION pos = m_mapEdit.GetStartPosition(); pos != 0; m_mapEdit.GetNext(pos))
    {
        JobSkillPtr spEdit = m_mapEdit.GetValueAt(pos);
        if (spEdit == 0)
            continue;
        JobSkillPtr spOld(0);
        m_mapSnapshot.Lookup(spEdit->GetID(), spOld);
        if (spOld == 0)
            continue;
        if (spOld->m_bLearned != spEdit->m_bLearned)
        {
            return 1;
        }
        else
        {
            if (spOld->m_nLevel != spEdit->m_nLevel)
                return 1;
        }
    }
    return 0;
}

// @0x140abe0a0
void CSkillPointSimulator::ResetRank(int nRank)
{
    for (POSITION pos = m_mapEdit.GetStartPosition(); pos != 0; m_mapEdit.GetNext(pos))
    {
        JobSkillPtr sp = m_mapEdit.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (nRank != 0)
        {
            if (sp->GetJobLevel() != nRank)
                continue;
        }
        sp->m_nLevel = 1;
        if (!sp->IsLearn())
        {
            if (!sp->m_bExtra)
                sp->m_bLearned = false;
        }
    }
    Recalc();
}

// MS2-FUNCTIONAL: exe scopes the JobSkillPtr per while-iteration with separate destructor calls on the break/remove paths (674 vs 688 bytes; same callees and logic)
// @0x140abe1e0
int CSkillPointSimulator::AutoDistribute(ATL::CAtlArray<unsigned>& order, ATL::CAtlArray<unsigned>& counts)
{
    ResetRank(0);
    if (m_nRemain == 0)
        return 0;
    for (int nRank = 1; nRank < 3; nRank++)
    {
        unsigned nPoints = GetRemainPoints(nRank);
        while (nPoints > 0)
        {
            unsigned i = 0;
            int bFound = 0;
            JobSkillPtr sp(0);
            for (i = 0; i < order.GetCount(); i++)
            {
                unsigned nId = order[i];
                sp = GetEditSkill(nId);
                if (sp == 0)
                    continue;
                if (sp->GetJobLevel() != nRank)
                    continue;
                if (CanLevelUp(nId))
                {
                    if (!sp->m_bLearned)
                    {
                        sp->m_bLearned = true;
                        bFound = 1;
                        break;
                    }
                    else
                    {
                        sp->m_nLevel += 1;
                        bFound = 1;
                        break;
                    }
                }
            }
            if (bFound == 1)
            {
                nPoints--;
                int nTarget = counts[i];
                if (sp->GetUsedPoint() == nTarget)
                {
                    order.RemoveAt(i, 1);
                    counts.RemoveAt(i, 1);
                }
            }
            else
                break;
        }
    }
    Recalc();
    unsigned nBad = 0;
    return Validate(&nBad);
}

// @0x140abe4a0
void CSkillPointSimulator::GetUsedPoints(ATL::CAtlArray<unsigned>& ids, ATL::CAtlArray<unsigned>& points, int nRank)
{
    for (POSITION pos = m_mapEdit.GetStartPosition(); pos != 0; m_mapEdit.GetNext(pos))
    {
        JobSkillPtr sp = m_mapEdit.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (nRank != 0)
        {
            if (nRank != sp->GetJobLevel())
            {
                sp = m_mapSnapshot.GetValueAt(pos);
                if (sp == 0)
                    continue;
            }
        }
        int nUsed = sp->GetUsedPoint();
        if (nUsed == 0)
            continue;
        ids.Add(sp->GetID());
        points.Add(nUsed);
    }
}

// @0x140abe620
// MS2-FUNCTIONAL: locals are laid out in a different order (the entry's JobSkillPtr slots sit 0x10 lower in the exe)
void CSkillPointSimulator::Commit(int nRank)
{
    SkillMap keep(17, 0.75f, 0.25f, 2.25f, 10);
    if (nRank != 0)
    {
        for (POSITION pos = m_mapSnapshot.GetStartPosition(); pos != 0; m_mapSnapshot.GetNext(pos))
        {
            JobSkillPtr sp = m_mapSnapshot.GetValueAt(pos);
            if (!(sp == 0))
            {
                if (nRank == sp->GetJobLevel())
                {
                }
                else
                {
                    keep.SetAt(sp->GetID(), sp);
                }
            }
        }
    }
    m_mapSnapshot.RemoveAll();
    for (POSITION posEdit = m_mapEdit.GetStartPosition(); posEdit != 0; m_mapEdit.GetNext(posEdit))
    {
        JobSkillPtr sp = m_mapEdit.GetValueAt(posEdit);
        if (!(sp == 0))
        {
            JobSkill* pCopy = new JobSkill(*sp.get());
            JobSkillPtr spCopy(pCopy);
            m_mapSnapshot.SetAt(sp->GetID(), spCopy);
        }
    }
    for (POSITION posKeep = keep.GetStartPosition(); posKeep != 0; keep.GetNext(posKeep))
    {
        JobSkillPtr sp = keep.GetValueAt(posKeep);
        if (!(sp == 0))
        {
            m_mapSnapshot.SetAt(sp->GetID(), sp);
        }
    }
}
