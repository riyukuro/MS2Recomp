// uiskillbookautodistributedialog.h - UISkillBookAutoDistributeDialog (RTTI .?AVUISkillBookAutoDistributeDialog@@, 0x1c8 bytes,
// UI id 0x4f20, swf "SkillBookAutoDistributeDialog") and UISkillBookTreeDialog (RTTI .?AVUISkillBookTreeDialog@@, 0x2f8 bytes,
// UI id 0x4f2d, swf "SkillBookTreeDialog"). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13) with the unit
// `?\uiskillbookautodistributedialog.cpp` (0x140ec41e0-0x140ed74c0 .text$mn, dir client\ms2). The unit and header names are
// assumed (the unit starts with the auto-distribute choice dialog); the skill window owns the tabs ("skill sets"), one
// CSkillPointSimulator per tab, and the auto-distribute table read from Table/skillAutoDistribute.xml. Member names are
// invented from use. The third-party v2525 snapshot (work/ext/v2525, tu/140ec4d30.cpp) was a cross-reference for the names.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/client/ms2/skillpointsimulator.h"
#include "ms2/commonfiles/skillconfig.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class CInPacket;
class CMsgBoxData;
class Unk_140acd6e0;
class Unk_SkillButtonBar;
class UIMsg;
class UISwfEntity;
class AScript;
class ASObj;
class JobSkill;

// The skill window's "Auto Distribute" choice dialog (modal). The names and tooltips of the entries are filled by
// UISkillBookTreeDialog::FUN_140eca230 before it opens; vfunc_28 "onDistribute" asks for the choice.
class UISkillBookAutoDistributeDialog : public UIModalDialog
{
public:
    UISkillBookAutoDistributeDialog();                          // 0x140ec41e0
    virtual ~UISkillBookAutoDistributeDialog();                 //  0 0x140ec4290 (??_G 0x140ec4ce0)
    virtual CString vfunc_1();                                  //  1 0x140ec4300 "SkillBookAutoDistributeDialog"
    virtual void OnLoadComplete();                              // 22 0x140ec43d0 (fills the three buttons)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ec4400
    virtual int vfunc_48() { return 0x4f20; }                   // 48 0x140ec4d20
    virtual int vfunc_65();                                     // 65 0x140ec43a0
    virtual void vfunc_67();                                    // 67 0x140ec4350
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140ec4660

    void FUN_140ec48e0();                                       // 0x140ec48e0 name / tooltip of the (up to) three buttons

    ATL::CAtlArray<CStringW> m_names;                           // +0x180 the entries' names (string table keys)
    ATL::CAtlArray<CStringW> m_tooltips;                        // +0x1a0 and their tooltips
    unsigned int m_nSelected;                                   // +0x1c0 the entry picked in "onDistribute"
};
MS2_CHECK_SIZE(UISkillBookAutoDistributeDialog, 0x1c8);
MS2_CHECK_OFFSET(UISkillBookAutoDistributeDialog, m_names, 0x180);
MS2_CHECK_OFFSET(UISkillBookAutoDistributeDialog, m_tooltips, 0x1a0);
MS2_CHECK_OFFSET(UISkillBookAutoDistributeDialog, m_nSelected, 0x1c0);

// The skill window. Overridden slots: 1 (movie name), 20, 22, 26, 28, 45, 48, 65, 67, 71, 73, 79; new slot 84 (closable);
// the UIStatusEventListener at +0x178 overrides 1, 7, 9, 21, 28.
class UISkillBookTreeDialog : public UIDialog, public UIStatusEventListener
{
public:
    // One preset of the auto-distribute table (a sub job's skill id -> point list), read from skillAutoDistribute.xml.
    class AutoDistribute : public CPtred
    {
    public:
        AutoDistribute();                                       // 0x140ed34a0
        int m_nSubJob;                                          // +0x18 "subJobCode"
        CStringW m_strName;                                     // +0x20 "name"
        CStringW m_strTooltip;                                  // +0x28 "tooltip"
        ATL::CAtlArray<unsigned> m_skillIds;                         // +0x30 <skill id>
        ATL::CAtlArray<unsigned> m_skillPoints;                      // +0x50 <skill point>
    };
    typedef ATL::CAtlArray<MS2Ptr<AutoDistribute> > AutoDistributeArray;

    UISkillBookTreeDialog();                                    // 0x140ec4e50
    virtual ~UISkillBookTreeDialog();                           //  0 0x140ec50b0 (??_G 0x140ed3fb0)
    virtual CString vfunc_1();                                  //  1 0x140ec51c0 "SkillBookTreeDialog[_jobchange01]"
    virtual void OnLoadInit();                                  // 20 0x140ec5480
    virtual void OnLoadComplete();                              // 22 0x140ec5570
    virtual void vfunc_26();                                    // 26 0x140ec5520
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ec5e20
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);       // 45 0x140ec5820
    virtual int vfunc_48() { return 0x4f2d; }                   // 48 0x140ed4c90
    virtual int vfunc_65();                                     // 65 0x140ec52e0
    virtual void vfunc_67();                                    // 67 0x140ec5340
    virtual int vfunc_71();                                     // 71 0x140ec7420
    virtual int vfunc_73();                                     // 73 0x140ec5460
    virtual void vfunc_79(void* pPacket);                       // 79 0x140ec7890 the skill book packet (a CInPacket)
    virtual bool vfunc_84();                                    // 84 0x140ec5250 (new) not closed
    // UIStatusEventListener (+0x178)
    virtual int vfunc_oa0_1();                                  //  1 0x140ec5290
    virtual void vfunc_oa0_7(int a1, CStringW s);               //  7 0x140ec7750
    virtual void vfunc_oa0_9(unsigned short nLevel);            //  9 0x140ec76d0
    virtual void vfunc_oa0_21();                                // 21 0x140ec7830
    virtual void vfunc_oa0_28();                                // 28 0x140ec77b0

    // Non-virtual members (names after the third-party snapshot where it had a body; FUN_<va> = address).
    void RefreshSlotsIfShown();                                 // 0x140ec8220
    void ApplyDistribute(unsigned int nIndex);                  // 0x140ec8280 apply the picked auto-distribute preset
    void OnPointClick(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140ec8720 the skill point label's tooltip
    MS2Ptr<CSkillPointSimulator> GetSimulator();                // 0x140ec8ad0
    bool OnRenameConfirm(int nResult, const CMsgBoxData& box);  // 0x140ec8b20 rename-tab message box
    bool OnAddTabConfirm(int nResult, const CMsgBoxData& box);  // 0x140ec8d30 add-tab message box (free tabs)
    bool OnAddTabPayConfirm(int nResult, const CMsgBoxData& box);   // 0x140ec8f60 add-tab message box (paid)
    bool AddPaidTab(CStringW strName);                          // 0x140ec9130
    void RegisterShortcut(int nSkillId);                        // 0x140ec91c0 "OnRegisterShortcutkey"
    void RequestJob(int bConfirm, int bAll, int nRank);         // 0x140ec9200 packet 0x25 (apply the learned skills)
    void PromptReset();                                         // 0x140ec9610
    void RequestTree(__int64 nTabId, int bKeep, int nRank);     // 0x140ec9c20 packet 0xa2 mode 1 (save the tabs)
    void PromptChangeTab();                                     // 0x140ec9fd0
    void ApplyAutoDistribute();                                 // 0x140eca230 open the preset dialog
    bool OnResetConfirm(int nResult, const CMsgBoxData& box);   // 0x140eca480
    bool OnApplyConfirm(int nResult, const CMsgBoxData& box);   // 0x140eca690
    bool OnCloseConfirm(int nResult, const CMsgBoxData& box);   // 0x140eca7e0
    bool OnApplyTabConfirm(int nResult, const CMsgBoxData& box);   // 0x140eca8c0
    void SkillPointUp(int nSkillId);                            // 0x140ecaa30
    void SkillPointDown(int nSkillId);                          // 0x140ecaab0
    void RequireSkillEffect(int nSkillId, int bFlag);           // 0x140ecac10 "requireSkillEffect"
    int GetJobSkillPoint(int nJobLevel);                        // 0x140ecb130
    void RenameTab(__int64 nTabId, CStringW strName);           // 0x140ecb1a0
    void RefreshSlots(int bKeep);                               // 0x140ecb300
    void RefreshJob();                                          // 0x140ecb540
    void RefreshTabButtons(int bKeepSelection);                 // 0x140ecb5c0
    void RefreshJobSkills(int nJobCode);                        // 0x140ecb820
    void RefreshRemainPoint();                                  // 0x140ecc030
    void RefreshPoints();                                       // 0x140ecc2e0
    void UpdateSubJobLevel();                                   // 0x140ecc850
    void RefreshAll();                                          // 0x140ecc8b0
    void RefreshTree();                                         // 0x140eccbb0
    bool HasPendingChanges();                                  // 0x140ecce40
    void LoadAutoDistribute();                                  // 0x140eccf50
    int CanApply();                                             // 0x140ecd4b0
    int CheckApply(bool bNotify);                               // 0x140ecd6d0
    bool IsChangedSkill(MS2Ptr<JobSkill> spSkill);              // 0x140ecd7e0
    CStringW GetLevelText(MS2Ptr<JobSkill> spSkill);            // 0x140ecd960
    unsigned short GetLevelValue(MS2Ptr<JobSkill> spSkill);     // 0x140ecdd90
    bool IsLearnable(MS2Ptr<JobSkill> spSkill);                 // 0x140ece040
    bool IsDisabled(MS2Ptr<JobSkill> spSkill);                  // 0x140ece160
    int FillSkill(MS2Ptr<JobSkill> spSkill, ASObj& info);     // 0x140ece300
    void PlayChangeEffect(int nSkillId);                        // 0x140ece840
    __int64 AddTab(const CStringW& strName, int bFree);         // 0x140ece8b0
    void LoadTab(MS2Ptr<CSkillBookTreeTabConfig> spTab);        // 0x140ecec20
    void RefreshTabs(__int64 nTabId);                           // 0x140ecef10
    void SelectTab(__int64 nTabId);                             // 0x140ecf1c0
    MS2Ptr<CSkillBookTreeTabConfig> FindTab(__int64 nTabId);    // 0x140ecf2d0
    void PromptAddTab();                                        // 0x140ecf3d0
    BOOL IsCurrentTab(__int64 nTabId);                          // 0x140ecf5f0
    static bool CanUpgrade(MS2Ptr<JobSkill> spSkill, int bCheck);   // 0x140ecf630
    static bool CanLevelUp(int nSkillId, unsigned short nLevel, int bCheck);   // 0x140ecf740
    static bool CanLearn(int nSkillId, unsigned short nLevel, int bCheck);     // 0x140ecf840
    static bool CanReachLevel(int nSkillId, unsigned short nLevel, int bCheck);   // 0x140ecf8d0

    MS2_LAYOUT_FRIEND;
    CString m_strSlotPrefix;                                    // +0x180 "skillTreeSlot"
    ATL::CAtlMap<__int64, MS2Ptr<CSkillPointSimulator> > m_simulators;   // +0x188 by tab id
    MS2Ptr<CSkillPointSimulator> m_spSimulator;                 // +0x1d0 the shown tab's
    ATL::CAtlList<MS2Ptr<CSkillBookTreeTabConfig> > m_tabs;     // +0x1e0
    ATL::CAtlMap<int, int> m_slotOrder;                         // +0x210 skill id -> slot index
    int m_nMaxTabs;                                             // +0x258 1
    __int64 m_nTabId;                                           // +0x260 the server's selected tab
    MS2Ptr<Unk_SkillButtonBar> m_spButtonBar;                   // +0x268 "m_buttonBar"
    MS2Ptr<Unk_140acd6e0> m_spAddButton;                        // +0x278 "m_addButton"
    __int64 m_nShownTabId;                                      // +0x288 the tab the simulator belongs to
    int m_n290;                                                 // +0x290
    int m_nWaitServer;                                          // +0x294 a packet is on its way
    int m_nJobLevel;                                            // +0x298 the shown job rank (1 / 2)
    MS2Ptr<CCacheData> m_spCache;                               // +0x2a0 skillAutoDistribute.xml
    ATL::CAtlMap<int, TPtrValue<AutoDistributeArray> > m_autoDistribute;  // +0x2b0 by job code
};
MS2_CHECK_SIZE(UISkillBookTreeDialog::AutoDistribute, 0x70);
MS2_CHECK_SIZE(UISkillBookTreeDialog, 0x2f8);
MS2_CHECK_OFFSET(UISkillBookTreeDialog, m_strSlotPrefix, 0x180);
MS2_CHECK_OFFSET(UISkillBookTreeDialog, m_spSimulator, 0x1d0);
MS2_CHECK_OFFSET(UISkillBookTreeDialog, m_slotOrder, 0x210);
MS2_CHECK_OFFSET(UISkillBookTreeDialog, m_spButtonBar, 0x268);
MS2_CHECK_OFFSET(UISkillBookTreeDialog, m_nJobLevel, 0x298);
MS2_CHECK_OFFSET(UISkillBookTreeDialog, m_autoDistribute, 0x2b0);
