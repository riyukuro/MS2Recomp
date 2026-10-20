// skilldatatablecli.h - the client skill table SkillDataTableCli (RTTI .?AVSkillDataTableCli@@, 0x1c8 bytes): the
// common SkillDataTable (commonfiles/skilloverlapcompare.h) plus the additional effect table read from
// Table/additionaleffect*.xml (AdditionalData rows by id, and the ids per first-level group). A TSingleton that
// CGameApp::InitInstance (?\ms2.cpp) creates. Recovered from ?\skilldatatablecli.cpp (0x140aae580-0x140abc2b0);
// header name assumed, method names invented except LoadAdditionalFile (the pure slot 0 of SkillDataTable).
#pragma once

#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/skilloverlapcompare.h"

class AdditionalData;
class AdditionalLevelData;
class SkillAttackData;

class SkillDataTableCli : public SkillDataTable, public TSingleton<SkillDataTableCli>
{
public:
    SkillDataTableCli();                                    // 0x140aae580 (implicit dtor 0x140ab7050)
    void ReloadFiles();                                     // 0x140aae640 reloads the changed skill files
    // One attack of a skill level by its point name (0 when the level or the attack is unknown).
    SkillAttackData* FindSkillAttack(unsigned nSkillId, unsigned short nLevel, CString strPoint);    // 0x140aae660
    // Preloads the effects of a skill level and of the skills/effects it chains to (CFilePreload).
    void PreloadSkill(unsigned nSkillId, unsigned short nLevel, int nPriority);                     // 0x140aae720
    void PreloadAdditional(unsigned nId, unsigned short nLevel, int nPriority);                     // 0x140aaf190
    // Recursion guards for skill -> additional effect -> skill chains (false: the chain loops back).
    bool CheckAdditionalChain(MS2Ptr<SkillLevelData> spLevel, unsigned nDepth);                          // 0x140aaf6a0
    int CheckSkillChain(unsigned nId, unsigned short nLevel, unsigned nSkillId, unsigned short nSkillLevel,
                        unsigned nDepth);                                                             // 0x140aaf8c0
    void GetSkillIds(std::set<unsigned>& out);                                                      // 0x140aafb20
    void GetGlides(std::vector<MS2Ptr<SkillGlideData> >& out);                                      // 0x140aafc30 (sorted by id)
    MS2Ptr<AdditionalData> GetAdditional(unsigned nId);                                             // 0x140aafd60
    MS2Ptr<AdditionalLevelData> GetAdditionalLevel(unsigned __int64 nKey);                          // 0x140aafe80 (id/level key)
    // The additional-effect level row (id, level); NULL when unknown (UIPcBangDialog::UpdateBuff, the buff icon).
    MS2Ptr<AdditionalLevelData> FUN_140aafef0(int nId, unsigned short nLevel);
    std::set<unsigned>* GetAdditionalGroup(unsigned nGroupId);                                      // 0x140aaffb0
    std::vector<MS2Ptr<AdditionalData> > GetAdditionals();                                          // 0x140ab0080
    virtual void LoadAdditionalFile(CString strPath);       // 0x140ab0180 (slot 0)

    CLockCriticalSection m_csAdditional;                                    // +0x148
    std::unordered_map<unsigned, MS2Ptr<AdditionalData> > m_additionals;    // +0x178
    std::map<unsigned, std::set<unsigned> > m_additionalGroups;             // +0x1b8 first-level group -> ids
};
MS2_CHECK_SIZE(SkillDataTableCli, 0x1c8);
MS2_CHECK_OFFSET(SkillDataTableCli, m_csAdditional, 0x148);
MS2_CHECK_OFFSET(SkillDataTableCli, m_additionals, 0x178);
MS2_CHECK_OFFSET(SkillDataTableCli, m_additionalGroups, 0x1b8);
