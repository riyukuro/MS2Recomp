// uialliancequestdialog.h - UIAllianceQuestDialog (RTTI .?AVUIAllianceQuestDialog@@, 0x200 bytes, UIDialog +
// UIQuestEventListener at +0x178, UI id 0x4f50, swf "AllianceQuestDialog"): the alliance (fame) quest window of an
// alliance npc. It lists the alliance's daily / repeatable quests, the npc portrait and speech, the current fame grade, and
// the "accept all" / "complete all" buttons. The alliance npc / grade it shows is the global DAT_143abdc30.
// Owning unit: unit_140bf60f0 (the exe has no assert path for it; header name assumed from the class name).
// Member names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)

class CMsgBoxData;

class UIAllianceQuestDialog : public UIDialog, public UIQuestEventListener
{
public:
    UIAllianceQuestDialog();                                    // 0x140bf60f0
    virtual ~UIAllianceQuestDialog();                           //  0 0x140bf61f0 (??_G 0x140bfc3b0)
    virtual CString GetTypeName();                                  //  1 0x140bf6290 "AllianceQuestDialog"
    virtual void vfunc_67();                                    // 67 0x140bf62e0 Close
    virtual void OnLoadComplete();                              // 22 0x140bf6360 fill the movie
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140bf6520
    virtual int vfunc_48() { return 0x4f50; }                   // 48 0x140bfc630
    virtual void vfunc_o178_2(void* pQuest);                    // 0x140bf6a90 close when a kind 9 quest changes

    int FUN_140bf6af0(int nNpc);                                // 0x140bf6af0 the alliance of an alliance npc
    CStringW FUN_140bf6b20(int nAlliance);                      // 0x140bf6b20 "current fame grade" text
    CStringW FUN_140bf6be0(int nAlliance);                      // 0x140bf6be0 "daily mission" text
    CStringW FUN_140bf6c90(unsigned nQuest);                    // 0x140bf6c90 time left until the quest resets
    void FUN_140bf6ef0();                                       // 0x140bf6ef0 send the fame header to the movie
    void FUN_140bf70f0();                                       // 0x140bf70f0 send the npc portrait and speech
    void FUN_140bf7630();                                       // 0x140bf7630 fill "m_list" with the quests
    int FUN_140bf8800(unsigned nQuest);                         // 0x140bf8800 a completion ticket can be used
    int FUN_140bf8900();                                        // 0x140bf8900 some quest can be accepted at once
    int FUN_140bf8ab0();                                        // 0x140bf8ab0 some quest can be completed at once
    void FUN_140bf8c30(unsigned nQuest);                        // 0x140bf8c30 ask to use a completion ticket
    bool SendQuestMode34(int nResult, const CMsgBoxData& rBox);   // 0x140bf9010 "accept all" confirmed
    bool SendQuestMode35(int nResult, const CMsgBoxData& rBox);   // 0x140bf9090 "complete all" confirmed
    bool SendQuestMode33(int nResult, const CMsgBoxData& rBox);   // 0x140bf9110 ticket use confirmed
    void FUN_140bf91b0();                                       // 0x140bf91b0 collect the acceptable quests
    void FUN_140bf9360();                                       // 0x140bf9360 collect the completable quests
    int FUN_140bf94e0(int nQuest);                              // 0x140bf94e0 the quest is among the collected acceptable ones
    int FUN_140bf9530(int nQuest);                              // 0x140bf9530 the quest is among the collected completable ones
    unsigned FUN_140bf9580(unsigned nQuest);                    // 0x140bf9580 the quest to act on for a row (0 = none)
    int FUN_140bf9a40(unsigned nQuest);                         // 0x140bf9a40 the fame / required quests are met
    CStringW FUN_140bf9bd0();                                   // 0x140bf9bd0 "requirement" text (empty when met)
    CStringW FUN_140bf9e10();                                   // 0x140bf9e10 "limit by other alliance fame" text
    MS2Ptr<class Unk_140acd6e0> FUN_140bb4b10(const CString& strName);   // 0x140bb4b10 bind a button child
    MS2Ptr<class Unk_AqList> FUN_140bfa760(const CString& strName);      // 0x140bfa760 the list child of the movie

private:
    MS2_LAYOUT_FRIEND;
    ItemSlotBinder m_180;               // +0x180 the reward item slots
    ATL::CAtlArray<unsigned> m_1c0;     // +0x1c0 quests "accept all" will accept
    ATL::CAtlArray<unsigned> m_1e0;     // +0x1e0 quests "complete all" will complete
};
MS2_CHECK_SIZE(UIAllianceQuestDialog, 0x200);
MS2_CHECK_OFFSET(UIAllianceQuestDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIAllianceQuestDialog, m_1c0, 0x1c0);
MS2_CHECK_OFFSET(UIAllianceQuestDialog, m_1e0, 0x1e0);
