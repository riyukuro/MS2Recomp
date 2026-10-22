// uiquestdialog.h - UIQuestDialog (RTTI .?AVUIQuestDialog@@, 0x310 bytes, UIDialog + UIQuestEventListener at +0x178,
// UI id 0x4e3e, swf "QuestDialog"): the quest journal. A tab strip (m_tab: episodes / world / events / ...) and a sub tab
// strip (m_subTab: available / in progress / finished) pick which quests the list (m_questList) shows; the info panel
// (m_questInfo) shows the selected quest's story, rewards, conditions and goto buttons. Listens to the quest events to
// refresh the list. Owning unit: ?\uiquestdialog.cpp (header name assumed from the unit path; the layout and the method
// roles follow the third-party v2525 decompile, the member names are invented).
// vftables: 0x142fd82d0 (84 slots), 0x142fd8578 (IMessageListener at +0x18), 0x142fd8588 (UIQuestEventListener +0x178).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"

class ASArray;
class ASObj;
class CInPacket;
class CMsgBoxData;
class CQuest;
class Unk_QdTabBar;
class Unk_QdList;
class Unk_QdInfo;
class Unk_QdCheck;

class UIQuestDialog : public UIDialog, public UIQuestEventListener
{
public:
    // chapter -> quest ids, then (continent name -> chapter groups) and (character id -> chapter open flags) per sub tab.
    typedef ATL::CAtlMap<int, TPtrValue<ATL::CAtlArray<int> > > ChapterQuests;
    typedef ATL::CAtlMap<CStringW, TPtrValue<ChapterQuests>, ATL::CStringElementTraits<CStringW> > QuestGroups;
    typedef ATL::CAtlMap<int, bool> QuestFlags;
    typedef ATL::CAtlMap<__int64, TPtrValue<QuestFlags> > FlagsByChar;

    UIQuestDialog();                                            // 0x141a993a0
    virtual ~UIQuestDialog();                                   //  0 0x141a99600 (??_G 0x141aa3fe0)
    virtual CString GetTypeName();                                  //  1 0x141a997b0 "QuestDialog"
    virtual void OnLoadInit();                                  // 20 0x141a99800 refresh the tabs and the info panel
    virtual void OnLoadComplete();                              // 22 0x141a99a40 hide the web guide button
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a99aa0
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);       // 45 0x141a9a790
    virtual int vfunc_48() { return 0x4e3e; }                   // 48 0x141aa4f60
    virtual int vfunc_53(void* pCfg);                           // 53 0x141a9a7d0 save the filter checkboxes
    virtual int vfunc_54(void* pCfg);                           // 54 0x141a9a930 load them
    virtual int vfunc_65();                                     // 65 0x141a9a700
    virtual void vfunc_67();                                    // 67 0x141a9a730 Close: remember the tabs
    virtual void vfunc_o178_1(void* pQuest);                    // UIQuestEventListener 1 0x141a9aa90 quest accepted: pin it
    virtual void vfunc_o178_2(void* pQuest);                    // UIQuestEventListener 2 0x141a9ab10 quest removed
    virtual void vfunc_o178_3(void* pQuest);                    // UIQuestEventListener 3 0x141a9aca0 (empty)
    virtual void vfunc_o178_5(void* pQuest);                    // UIQuestEventListener 5 0x141a9acc0
    virtual void vfunc_o178_6(void* pQuest);                    // UIQuestEventListener 6 0x141a9ada0

    void RefreshTab();                                          // 0x141a9ae00
    void RefreshEpisodes();                                     // 0x141a9ae90
    void RefreshList();                                         // 0x141a9b0e0
    void RefreshCompleted();                                    // 0x141a9b6e0
    void SelectQuest(int nQuestId);                             // 0x141a9bb30 fill the info panel
    void FocusQuest(int nQuestId);                              // 0x141a9bff0
    void SelectListIndex(int nIndex);                           // 0x141a9c0e0
    void ScrollToQuest(int nQuestId);                           // 0x141a9c1c0
    int HasAvailable(int nQuestId);                             // 0x141a9c290
    int HasPinned(int nQuestId);                                // 0x141a9c430
    int IsInCurrentTab(int nQuestId);                           // 0x141a9c470
    void RemovePinned(int nQuestId);                            // 0x141a9c4d0
    void CollectQuests(ATL::CAtlArray<Unk_PayloadPtr<CQuest> >& rOut, unsigned nChapter);   // 0x141a9c560
    int GetTab();                                               // 0x141a9c6d0 "m_tab" (4 without the strip)
    int GetSubTab();                                            // 0x141a9c780 "m_subTab" (3 without the strip)
    int GetSubTabFilter();                                      // 0x141a9c830
    int GetQuestListIndex();                                    // 0x141a9c880
    int GetSelectedID();                                        // 0x141a9c950
    int IndexOfQuest(int nQuestId);                             // 0x141a9ca00
    CString RewardIconName(int nItemId, int nRarity, int nCount, CString strBindName);   // 0x141a9cad0
    CStringW ConditionText(int nQuestId, int nIndex);           // 0x141a9cd30
    CString QuestStateName(CQuest* pQuest);                     // 0x141a9cd80
    CStringW QuestProgressStory(CQuest* pQuest);                // 0x141a9cf90
    CStringW QuestStory(unsigned nQuestId);                     // 0x141a9d690
    CStringW LevelRange(int nChapter);                          // 0x141a9dd60
    CStringW QuestTitle(unsigned nQuestId);                     // 0x141a9df60
    CStringW QuestListLabel(unsigned nQuestId);                 // 0x141a9e250
    void SetTab(int nTab);                                      // 0x141a9e390
    void SetSubTab(int nTab);                                   // 0x141a9e4a0
    CStringW QuestDate(__int64 nTime);                          // 0x141a9e5b0
    void ClearOpened();                                         // 0x141a9e7f0
    void RefreshDetail();                                       // 0x141a9e870 empty info panel
    void ClearFlags();                                          // 0x141a9ea20
    int AddQuestNode(int nQuestId, ASArray& rNodes);            // 0x141a9ea80
    void AddRewardInfo(int nQuestId, ASObj& rOut);              // 0x141a9f3c0
    void AddConditions(int nQuestId, ASObj& rOut);              // 0x141a9fab0
    int AddChapterQuests(MS2Ptr<CQuestData> spData, ASArray& rNodes);   // 0x141a9fe50
    void AddButtons(Unk_PayloadPtr<CQuest> spQuest, ASObj& rOut);       // 0x141aa02b0
    void GetChapterIDs(ATL::CAtlArray<unsigned>& rOut);         // 0x141aa06f0
    void CollectEpisodes(ATL::CAtlArray<unsigned>& rOut);       // 0x141aa07f0
    void GroupChapters(QuestGroups& rOut);                      // 0x141aa0a00
    void CollectRecommended(ATL::CAtlArray<MS2Ptr<CQuestData> >& rOut);   // 0x141aa0f80
    int IsSubTabOne();                                          // 0x141aa17b0
    void FocusQuestTab(int nQuestId);                           // 0x141aa17f0
    void FocusQuestSubTab(int nQuestId);                        // 0x141aa18b0
    int TabOfQuest(int nQuestId);                               // 0x141aa1990
    void GiveUpQuest(int nQuestId);                             // 0x141aa1b50
    bool OnGiveUpConfirm(int nButton, const CMsgBoxData& rData);   // 0x141aa1fa0
    void ResetFilters();                                        // 0x141aa2050
    void ChangeTab(int nTab);                                   // 0x141aa2130
    void OnPacketParty(CInPacket& rPacket);                     // 0x141aa22b0
    int IsChapterOpen(int nChapter);                            // 0x141aa2330
    void SelectChapter(int nChapter);                           // 0x141aa2420
    void CloseChapter(int nChapter);                            // 0x141aa2520
    TPtrValue<QuestFlags> GetFlags(int nChapter);               // 0x141aa25a0

    // child lookups (one COMDAT per wrapper class; defined in other units)
    MS2Ptr<Unk_QdTabBar> FUN_140c02870(const CString& strName);    // tab strips
    MS2Ptr<Unk_QdList> FUN_140c02900(const CString& strName);      // "m_questList"
    MS2Ptr<Unk_QdInfo> FUN_140c02990(const CString& strName);      // "m_questInfo"
    MS2Ptr<Unk_QdCheck> FUN_140e52670(const CString& strName);     // "m_properLevel" / "m_progressOnly" check boxes

private:
    MS2_LAYOUT_FRIEND;
    int m_180;                                  // +0x180 the tab to restore (vfunc_67)
    int m_184;                                  // +0x184 the sub tab to restore
    int m_188;                                  // +0x188 the quest to focus once the movie is loaded
    ATL::CAtlArray<CString> m_opened;           // +0x190 the quest movie names opened in the info panel
    ATL::CAtlArray<int> m_pinned;               // +0x1b0 quests accepted while the dialog was open
    ATL::CAtlMap<int, int> m_1d0;               // +0x1d0 (only the ctor / dtor touch it)
    int m_filterA[4];                           // +0x218 "properLevel" check per tab
    int m_filterB[4];                           // +0x228 "progressOnly" check per tab
    FlagsByChar m_flags[3];                     // +0x238 chapter open flags per sub tab
};
MS2_CHECK_SIZE(UIQuestDialog, 0x310);
MS2_CHECK_OFFSET(UIQuestDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIQuestDialog, m_opened, 0x190);
MS2_CHECK_OFFSET(UIQuestDialog, m_pinned, 0x1b0);
MS2_CHECK_OFFSET(UIQuestDialog, m_1d0, 0x1d0);
MS2_CHECK_OFFSET(UIQuestDialog, m_filterA, 0x218);
MS2_CHECK_OFFSET(UIQuestDialog, m_filterB, 0x228);
MS2_CHECK_OFFSET(UIQuestDialog, m_flags, 0x238);
