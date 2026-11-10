// jobtable.h - JobTable (Table/job.xml): per job group the start data and the job skill tree. Recovered with
// commonfiles\jobtable.cpp; the member and method names are invented except the RTTI class names and the xml
// attribute names.
//
// JobSkillData (RTTI .?AVJobSkillData@@, 0xb0): one <skills><v ...> row of a job.
// JobData      (RTTI .?AVJobData@@, 0x78): one <job jobGroupID=..> row.
// JobTable     (RTTI .?AVJobTable@@, 0x50): TSingleton<JobTable> +0x0, CValidData<JobTable> +0x8, the jobs by group +0x10.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atltypes.h>
#include <map>
#include <unordered_map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/xmlattr.h"

// The job group of a JobData (jobGroupID: 1 beginner, 10 knight, ...) and the job code of its two sub jobs
// (subJob1 / subJob2). Enum names invented; the xml readers are one XmlValue<E> instance per enum.
enum Unk_JobGroupID { Unk_JobGroupID_None = 0 };
enum Unk_JobCode { Unk_JobCode_None = 0 };

int FUN_140718170(const CString& s);    // string -> int
CString ToCString(const char* psz, int nCodePage);         // narrows a string (the RTTI name in CheckInit)

// "x,y" point attribute (uiPosition).
int XmlValue(TiXmlElement* pElem, const char* pszName, CPoint& pt);    // 0x140645190

class JobSkillData : public CPtred
{
public:
    JobSkillData();                                     // 0x140643650
    bool Load(TiXmlElement* pElem);                    // 0x140643720
    bool HasRequirement();                              // 0x140643880 any requireLevel / requireSkillIDs / requireQuestID
    unsigned short GetRequireLevel(unsigned short skillLevel);    // 0x1406438e0 character level needed for a skill level

    unsigned m_skillID;                                 // +0x18
    CPoint m_uiPosition;                                // +0x1c
    bool m_uiHighlight;                                 // +0x24
    unsigned m_quickSlotPriority;                       // +0x28
    int m_jobLevel;                                     // +0x2c
    std::vector<unsigned> m_subSkillIDs;                // +0x30
    bool m_isLearn;                                     // +0x48 learnt from the start
    std::vector<unsigned short> m_requireLevel;         // +0x50 per skill level
    ATL::CAtlArray<unsigned> m_requireSkillIDs;         // +0x68
    ATL::CAtlArray<unsigned short> m_requireSkillLevels;    // +0x88
    unsigned m_requireQuestID;                          // +0xa8
};
MS2_CHECK_SIZE(JobSkillData, 0xb0);
MS2_CHECK_OFFSET(JobSkillData, m_uiPosition, 0x1c);
MS2_CHECK_OFFSET(JobSkillData, m_subSkillIDs, 0x30);
MS2_CHECK_OFFSET(JobSkillData, m_requireLevel, 0x50);
MS2_CHECK_OFFSET(JobSkillData, m_requireSkillLevels, 0x88);
MS2_CHECK_OFFSET(JobSkillData, m_requireQuestID, 0xa8);

typedef MS2Ptr<JobSkillData> JobSkillDataPtr;

class JobData : public CPtred
{
public:
    typedef std::map<unsigned, JobSkillDataPtr> SkillMap;

    JobData();                                          // 0x1406439a0
    void Load(TiXmlElement* pElem);                    // 0x140643a60
    Unk_JobGroupID GetJobGroupID();                     // 0x140643e40
    Unk_JobCode GetSubJob(int nIndex);                  // 0x140643e60 nIndex 1 / 2
    Unk_JobCode GetSubJob1();                           // 0x140643ed0
    Unk_JobCode GetSubJob2();                           // 0x140643ef0
    unsigned GetCharacterBGM();                         // 0x140643f10
    CStringW GetName();                                 // 0x140643f30 string table 6
    unsigned GetStartField();                           // 0x140643fb0
    bool HasSkill(unsigned nSkillId);                   // 0x140643fd0
    bool HasSubSkill(unsigned nSkillId);                // 0x140644050
    unsigned GetSubSkillParent(unsigned nSkillId);      // 0x1406440d0 the skill a sub skill belongs to
    JobSkillDataPtr FindSkill(unsigned nSkillId) const;    // 0x140644150
    JobSkillDataPtr FindSubSkill(unsigned nSkillId) const;    // 0x140644210
    JobSkillDataPtr GetSkillData(unsigned nSkillId);    // 0x1406442d0 skill or sub skill
    void GetSkills(std::vector<JobSkillDataPtr>& vOut);    // 0x140644380
    static unsigned short GetSkillMaxLevel(unsigned nSkillId);    // 0x140644430

    static ATL::CAtlMap<unsigned, unsigned short> s_skillMaxLevel;  // 0x143ab01b0 maxLevel by skill id (all jobs)

    CString m_characterVoice;                           // +0x18
    int m_defaultWeaponSlot;                            // +0x20
    std::vector<unsigned> m_startItems;                 // +0x28
    Unk_JobGroupID m_jobGroupID;                        // +0x40
    unsigned m_characterBGM;                            // +0x44
    unsigned m_startField;                              // +0x48
    SkillMap m_skills;                                  // +0x50 by skill id
    SkillMap m_subSkills;                               // +0x60 sub skill id -> owning skill
    Unk_JobCode m_subJob1;                              // +0x70
    Unk_JobCode m_subJob2;                              // +0x74
};
MS2_CHECK_SIZE(JobData, 0x78);
MS2_CHECK_OFFSET(JobData, m_jobGroupID, 0x40);
MS2_CHECK_OFFSET(JobData, m_skills, 0x50);
MS2_CHECK_OFFSET(JobData, m_subJob1, 0x70);

typedef MS2Ptr<JobData> JobDataPtr;

class JobTable : public TSingleton<JobTable>, public CValidData<JobTable>
{
public:
    typedef std::unordered_map<int, JobDataPtr> JobMap;

    JobTable();                                         // 0x140644470
    virtual ~JobTable();                                // 0x1406444e0
    int Load();                                         // 0x140644540 Table/job.xml
    JobDataPtr GetJobData(int nJobGroup);               // 0x140644880
    unsigned GetStartField(int nJobGroup);              // 0x140644940
    Unk_JobGroupID GetJobGroupBySkill(unsigned nSkillId);   // 0x1406449c0
    Unk_JobGroupID GetJobGroupBySubJob(Unk_JobCode nJobCode);   // 0x140644a80
    int GetJobRank(int nJobCode);                       // 0x140644b80 (job code % 10) + 1
    Unk_JobCode GetSubJob1(int nJobGroup);              // 0x140644bb0

    // @0x140648bf0
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CStringA msg;
            msg.Format("%s is not initialized", (const char*)ToCString(typeid(JobTable).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x140648ca0
    static void SetInit(bool bInit) { s_bInit = bInit; }

    static bool s_bInit;                                // 0x143ab01f8

    JobMap m_jobs;                                      // +0x10
};
MS2_CHECK_SIZE(JobTable, 0x50);
MS2_CHECK_OFFSET(JobTable, m_jobs, 0x10);
