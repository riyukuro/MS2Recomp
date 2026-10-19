// cskillsettable.h - CSkillSet / CSkillSetTable (RTTI .?AVCSkillSet@@ / .?AVCSkillSetTable@@). NOT an original header.
// The table reads Table/skillSet.xml (<skillSet id version slotLock skillIDs skillLevels learnSkillIDs
// learnSkillLevels itemIDs/>) into an ATL::CAtlMap<int, MS2Ptr<CSkillSet>> (unit ?\skillset.cpp). Member names are
// invented from use.
// CSkillSetTable: TSingleton<CSkillSetTable> at +0x0, CValidData<CSkillSetTable> at +0x8. A TSingleton that
// CGameApp::InitInstance (?\ms2.cpp) creates.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// One <skillSet> row, 0xa0 bytes, base CPtred. The skill lists pair an id with its level by index.
class CSkillSet : public CPtred
{
public:
    CSkillSet();                                            // 0x1408092d0
    virtual ~CSkillSet();                                   // 0x140809380

    int HasSkill(int nSkillId, unsigned short nLevel);              // 0x140809410 (level 0 = any level); skills, then learn skills
    unsigned short GetSkillLevel(int nSkillId);             // 0x140809560 (0 when missing)

    unsigned m_nId;                                         // +0x18 "id"
    int m_nVersion;                                         // +0x1c "version" (1 by default)
    int m_nSlotLock;                                        // +0x20 "slotLock" (1 by default)
    std::vector<unsigned> m_arrSkillIds;                    // +0x28 "skillIDs"
    std::vector<unsigned short> m_arrSkillLevels;           // +0x40 "skillLevels"
    std::vector<unsigned> m_arrLearnSkillIds;               // +0x58 "learnSkillIDs"
    std::vector<unsigned short> m_arrLearnSkillLevels;      // +0x70 "learnSkillLevels"
    std::vector<unsigned> m_arrItemIds;                     // +0x88 "itemIDs"
};
MS2_CHECK_SIZE(CSkillSet, 0xa0);
MS2_CHECK_OFFSET(CSkillSet, m_nId, 0x18);
MS2_CHECK_OFFSET(CSkillSet, m_arrSkillIds, 0x28);
MS2_CHECK_OFFSET(CSkillSet, m_arrSkillLevels, 0x40);
MS2_CHECK_OFFSET(CSkillSet, m_arrLearnSkillIds, 0x58);
MS2_CHECK_OFFSET(CSkillSet, m_arrLearnSkillLevels, 0x70);
MS2_CHECK_OFFSET(CSkillSet, m_arrItemIds, 0x88);

typedef MS2Ptr<CSkillSet> CSkillSetPtr;

class CSkillSetTable : public TSingleton<CSkillSetTable>, public CValidData<CSkillSetTable>
{
public:
    CSkillSetTable();                                       // 0x140809660
    virtual ~CSkillSetTable();                              // 0x140809730

    CSkillSetPtr GetSkillSet(int nSetId);                   // 0x140809840 reloads first when the xml changed on disk
    int Init();                                             // 0x1408097c0 (Load, then marks the table initialized)
    int Load();                                             // 0x140809930 parses the xml into the map (0 on a bad file)

    static void CheckInit();                                // 0x14080a610
    static void SetInit(bool b);                            // 0x14080b4e0

    static bool s_bInit;                                    // 0x143ab18d0

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x10
    MS2Ptr<CCacheData> m_spCache;                           // +0x40 the loaded file
    ATL::CAtlMap<int, CSkillSetPtr> m_map;                  // +0x50 set id -> row
};
MS2_CHECK_SIZE(CSkillSetTable, 0x98);
MS2_CHECK_OFFSET(CSkillSetTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CSkillSetTable, m_spCache, 0x40);
MS2_CHECK_OFFSET(CSkillSetTable, m_map, 0x50);
