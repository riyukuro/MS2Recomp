// uilearningquestdialog.h - UILearningQuestDialog (RTTI .?AVUILearningQuestDialog@@, 0x358 bytes, UIDialog +
// UIQuestEventListener at +0x178 + UIStatusEventListener at +0x180, UI id 0x4f18, swf "LearningQuestDialog"): the
// learning quest ("guide") window. It lists the learning quests grouped by their required quest's chapter, shows the
// selected one's movie, rewards and "start" button state, and remembers which learning quests the character / the
// account has already seen in ms2/v1 xml files (learningQuestCharacter.xml / learningQuestAccount.xml).
// Owning unit: ?\uilearningquestdialog.cpp. Header name assumed from the unit path; member names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)

class ASObj;
class ASTextField;
class CLearningQuestData;
class NotifyObject;
class Unk_140acd6e0;

class UILearningQuestDialog : public UIDialog, public UIQuestEventListener, public UIStatusEventListener
{
public:
    UILearningQuestDialog();                                    // 0x140ea0850
    virtual ~UILearningQuestDialog();                           //  0 0x140ea0da0 (??_G 0x140ea3ee0)
    virtual CString GetTypeName();                                  //  1 0x140ea11b0 "LearningQuestDialog"
    virtual void vfunc_12();                                    // 12 0x140ea1e00 mark the list dirty
    virtual void OnLoadComplete();                              // 22 0x140ea1270 fill the movie
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ea12a0 "onOk" / "onSelectQuest"
    virtual int vfunc_48() { return 0x4f18; }                   // 48 0x140ea41b0
    virtual int vfunc_65();                                     // 65 0x140ea1200
    virtual void vfunc_67();                                    // 67 0x140ea1220 Close
    virtual void vfunc_72();                                    // 72 0x140ea1580 refresh once when marked dirty
    virtual void vfunc_o178_2(void*);                           // UIQuestEventListener 2 0x140ea1da0
    virtual void vfunc_oa0_9(unsigned short a1);                // UIStatusEventListener 9 0x140ea1dd0

    void FUN_140ea15d0(int bPickCategory);                      // 0x140ea15d0 send the selected quest's data to the movie
    void FUN_140ea1c00(NotifyObject* pNotify);                  // 0x140ea1c00 "NotifyChangeServer": reload the seen lists
    void FUN_140ea1c30(NotifyObject* pNotify);                  // 0x140ea1c30 "NotifyGameStart": which learning quests are open
    void FUN_140ea1d70(NotifyObject* pNotify);                  // 0x140ea1d70 "NotifyChangeMyPC": forget the open flags
    int FUN_140ea1e20(int bNew);                                // 0x140ea1e20 pick the first open learning quest
    void LoadLearningQuest();                                       // 0x140ea2120 read the seen lists from the xml files
    void SaveLearningQuest();                                       // 0x140ea26e0 write the seen lists
    void FUN_140ea2e50(ASObj& rOut);                            // 0x140ea2e50 build the category / quest tree
    void FUN_140ea3570(const CQuestData::CompleteReward& rReward, ASObj& rOut);   // 0x140ea3570 exp / meso text and reward items
    void FUN_140ea3910();                                       // 0x140ea3910 mark dirty while the lobby scene is shown
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // 0x140bb4cf0 text field child lookup (a UIDialog member)
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);   // 0x140bb4b10 bind a button child

private:
    MS2_LAYOUT_FRIEND;
    int m_188;                          // +0x188 the list needs a refresh (vfunc_72)
    int m_18c;                          // +0x18c selected learning quest id
    int m_190;                          // +0x190 its category
    int m_194;                          // +0x194 its required quest id
    CString m_198;                      // +0x198 its movie name
    CString m_1a0;                      // +0x1a0 the movie currently shown
    ItemSlotBinder m_1a8;               // +0x1a8 the reward item slots
    TiXmlDocument m_1e8;                // +0x1e8 learningQuestCharacter.xml
    TiXmlDocument m_258;                // +0x258 learningQuestAccount.xml
    ATL::CAtlMap<int, unsigned> m_2c8;  // +0x2c8 learning quest id -> seen
    ATL::CAtlMap<int, unsigned> m_310;  // +0x310 learning quest id -> not yet startable
};
MS2_CHECK_SIZE(UILearningQuestDialog, 0x358);
MS2_CHECK_OFFSET(UILearningQuestDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UILearningQuestDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UILearningQuestDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UILearningQuestDialog, m_1e8, 0x1e8);
MS2_CHECK_OFFSET(UILearningQuestDialog, m_258, 0x258);
MS2_CHECK_OFFSET(UILearningQuestDialog, m_2c8, 0x2c8);
MS2_CHECK_OFFSET(UILearningQuestDialog, m_310, 0x310);
