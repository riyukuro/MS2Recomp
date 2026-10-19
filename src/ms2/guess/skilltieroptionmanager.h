// skilltieroptionmanager.h - CSkillTierOptionManager (RTTI .?AVCSkillTierOptionManager@@, 0xe0 bytes) and CSkillTierOption
// (RTTI .?AVCSkillTierOption@@, 0x30 bytes), recovered from ?\skilltieroptionmanager.cpp (0x14080b800-0x1408105e0).
// Header names assumed; member and method names invented. Table/itemOptionSkillTier.xml: <skillTier id skillIDs/>
// maps a tier id to its skills (a job code -> skill multimap); the manager keeps the per-player tier and skill levels.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tptrvalue.h"

class PC;

enum eJobCode { eJobCode_None = 0 };

typedef ATL::CRBMultiMap<eJobCode, unsigned int> Unk_SkillJobMap;

// One <skillTier> row: its skills keyed by the job that owns them.
class CSkillTierOption : public CPtred
{
public:
    CSkillTierOption();                                         // 0x14080cbf0
    virtual ~CSkillTierOption();                                // 0x14080ce40

    void* m_18;                                                 // +0x18
    TPtrValue<Unk_SkillJobMap> m_skills;                        // +0x20
};
MS2_CHECK_SIZE(CSkillTierOption, 0x30);
MS2_CHECK_OFFSET(CSkillTierOption, m_skills, 0x20);

class CSkillTierOptionManager : public CPtred
{
public:
    enum TierId { TierId_None = 0 };

    CSkillTierOptionManager(PC* pOwner);                        // 0x14080b800
    virtual ~CSkillTierOptionManager();                         // 0x14080ce70

    int Update();                                               // 0x14080b8e0 refresh the tier levels; 1 when one changed
    unsigned short GetSkillLevel(unsigned int nSkillId);        // 0x14080baf0
    void Clear();                                               // 0x14080bb80

    PC* m_pOwner;                                               // +0x18
    CLockCriticalSection m_lock;                                // +0x20
    ATL::CAtlMap<unsigned int, unsigned short> m_skillLevels;   // +0x50 skill id -> level
    ATL::CAtlMap<TierId, unsigned short> m_tierLevels;             // +0x98 tier id -> level
};
MS2_CHECK_SIZE(CSkillTierOptionManager, 0xe0);
MS2_CHECK_OFFSET(CSkillTierOptionManager, m_lock, 0x20);
MS2_CHECK_OFFSET(CSkillTierOptionManager, m_skillLevels, 0x50);
MS2_CHECK_OFFSET(CSkillTierOptionManager, m_tierLevels, 0x98);
