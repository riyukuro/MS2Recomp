// uidailymissiondialog.h - UIDailyMissionDialog (RTTI .?AVUIDailyMissionDialog@@, 0x1b8 bytes, UIDialog +
// UIQuestEventListener at +0x178 + UIStatusEventListener at +0x180, UI id 0x4f53, swf "DailyMissionDialog"): the daily
// mission window. It lists the daily mission quests (quest type 1/2, 3..5 are the guide / level quests) of the selected
// group tab, the recommended list, the level guide bar and the mission point gauge, and sends the "receive reward"
// request for a finished mission.
// Owning unit: ?\uidailymissiondialog.cpp. Header name assumed from the unit path; member names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)
#include "ms2/client/ms2/questmanager_1.h"           // CQuest, Unk_PayloadPtr<CQuest>

class ASData;
class ASMovieClip;
class ASObj;
class CInPacket;
class NotifyObject;
class Unk_DmTabBar;
class Unk_DmList;
class Unk_DmGuideBar;

class UIDailyMissionDialog : public UIDialog, public UIQuestEventListener, public UIStatusEventListener
{
public:
    UIDailyMissionDialog();                                     // 0x140bff060
    virtual ~UIDailyMissionDialog();                            //  0 0x140bff390 (??_G 0x140c02e60)
    virtual CString vfunc_1();                                  //  1 0x140bff660 "DailyMissionDialog"
    virtual void OnLoadComplete();                              // 22 0x140bff950 build the tabs, list and guide
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140bff990 "onReceiveItem" / "onChangeIndex"
    virtual int vfunc_48();                                     // 48 0x140c02f10 0x4f53
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140bffb20 the tooltip of the item / point
    virtual int vfunc_65();                                     // 65 0x140bff6b0 Open: needs the level, registers the listeners
    virtual void vfunc_67();                                    // 67 0x140bff7d0 Close: unregisters, unbinds the reward items
    virtual void vfunc_72();                                    // 72 0x140bff8c0 apply the pending refresh flags
    virtual void vfunc_o178_8(void* pQuest);                    // UIQuestEventListener 8 0x140bffd70 a daily mission quest changed

    void FUN_140bffee0(NotifyObject* pNotify);                  // 0x140bffee0 "NotifyGameStart": open once in the lobby
    void FUN_140bfff70(NotifyObject* pNotify);                  // 0x140bfff70 "NotifyChangeMyPC": allow the auto open again
    void FUN_140bfff90(CInPacket& rPacket);                     // 0x140bfff90 packet 0x10b: show the window
    int FUN_140bffff0();                                        // 0x140bffff0 BOOL: the feature is on and the player has a level
    void SendQuest(int nQuestId);                           // 0x140c00070 request the reward of a finished quest
    void FUN_140c001d0();                                       // 0x140c001d0 fill the recommended list of the selected group
    void FUN_140c00500();                                       // 0x140c00500 fill the level guide bar and the mission point
    void FUN_140c009b0();                                       // 0x140c009b0 fill the group tabs
    void FUN_140c00c10(CQuest* pQuest);                         // 0x140c00c10 update one quest row
    void FUN_140c00cd0();                                       // 0x140c00cd0 refresh the clear / satisfied counts and the point
    void FUN_140c01040(ASObj& rRow, CQuest* pQuest);            // 0x140c01040 fill the row of a quest
    int FUN_140c012d0(ASObj& rRow, unsigned nQuestId);          // 0x140c012d0 fill the row of a level guide entry
    void FUN_140c01790(ASObj& rRow, unsigned nQuestId, int bName);   // 0x140c01790 bind the reward item to the row
    int FUN_140c01b50(int nGroup);                              // 0x140c01b50 quests of the group
    int FUN_140c01d30(int nGroup);                              // 0x140c01d30 satisfied quests of the group
    int FUN_140c01f50();                                        // 0x140c01f50 the highest reward point of the finished quests
    int FUN_140c020d0();                                        // 0x140c020d0 the largest mission point of the open quests
    int FUN_140c02320(int nGroup);                              // 0x140c02320 the group has a quest that can be received
    MS2Ptr<Unk_DmTabBar> FUN_140c02870(const CString& strName);     // 0x140c02870 bind a tab child
    MS2Ptr<Unk_DmList> FUN_140c02900(const CString& strName);       // 0x140c02900 bind a list child
    MS2Ptr<Unk_DmGuideBar> FUN_140c02990(const CString& strName);   // 0x140c02990 bind the guide bar child
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);      // 0x140ba7930 movie clip child lookup (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<CString> m_188;      // +0x188 the slot names of the bound reward items
    int m_1a8;                          // +0x1a8 the auto open has been done
    int m_1ac;
    int m_1b0;                          // +0x1b0 the selected group
    int m_1b4;
};
MS2_CHECK_SIZE(UIDailyMissionDialog, 0x1b8);
MS2_CHECK_OFFSET(UIDailyMissionDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIDailyMissionDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UIDailyMissionDialog, m_1b0, 0x1b0);
