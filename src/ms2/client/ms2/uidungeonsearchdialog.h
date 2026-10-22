// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed (the .cpp's __FILE__ string is in the
// exe, the header's is not).
//
// The dungeon search window (RTTI .?AVUIDungeonSearchDialog@@, UI type 0x4f1c, 0x1e8 bytes). It shows two search pages
// (UIDungeonSearchPage, one per search kind: 1 = custom dungeon, 2 = random dungeon), the united reward panel
// (UIDungeonSearchUnitedReward, uidungeonhelper.h), a row of 12 category buttons with their labels and a sub panel.
#pragma once

#include <afx.h>
#include <list>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;
class NotifyObject;
class CMsgBoxData;
class UIDungeonSearchUnitedReward;
class Unk_DsButton;
class Unk_DsLabel;
class Unk_DsRoom;

// One search page: the ASMovieClip "m_mainPage<n>" with its find / cancel / setting buttons and the list of the
// dungeon room ids the player ticked in the select dialog.
class UIDungeonSearchPage : public CPtred
{
public:
    explicit UIDungeonSearchPage(int nPage);                                    // 0x140e186e0
    virtual ~UIDungeonSearchPage();                                             // 0x140e1ee20
    bool Init(MS2Ptr<ASMovieClip> root);                                        // 0x140e18790
    void FUN_140e18f30();                                                       // releases the bound clips
    void FUN_140e18f90();                                                       // title and progress icon
    void FUN_140e19220();                                                       // clears the room id list
    void FUN_140e19250(const std::list<int>& rooms);                            // sets the room id list
    bool FUN_140e19290(int nResult, const CMsgBoxData& data);                   // message box answer
    void FUN_140e192d0(const Scaleform::GFx::FunctionHandler::Params& params);  // find button
    void SendPartyMode34(const Scaleform::GFx::FunctionHandler::Params& params);  // cancel button
    void FUN_140e19380(const Scaleform::GFx::FunctionHandler::Params& params);  // setting button
    bool FUN_140e194f0();                                                       // checks before searching
    void SendPartyMode32(bool bStart);                                            // sends the search packet
    void FUN_140e19770();                                                       // progress icon and buttons
    void FUN_140e199b0(std::vector<MS2Ptr<Unk_DsRoom> >& out);                                    // room list of the page
private:
    MS2_LAYOUT_FRIEND;
    int m_nPage;                                                                // +0x18 1 = custom, 2 = random
    MS2Ptr<ASMovieClip> m_movie;                                                // +0x20
    MS2Ptr<Unk_DsButton> m_findButton;                                          // +0x30 "m_findButton"
    MS2Ptr<Unk_DsButton> m_cancelButton;                                        // +0x40 "m_cancelButton"
    MS2Ptr<Unk_DsButton> m_settingButton;                                       // +0x50 "m_settingButton"
    std::list<int> m_rooms;                                                     // +0x60 selected dungeon room ids
};
MS2_CHECK_SIZE(UIDungeonSearchPage, 0x70);
MS2_CHECK_OFFSET(UIDungeonSearchPage, m_nPage, 0x18);
MS2_CHECK_OFFSET(UIDungeonSearchPage, m_movie, 0x20);
MS2_CHECK_OFFSET(UIDungeonSearchPage, m_findButton, 0x30);
MS2_CHECK_OFFSET(UIDungeonSearchPage, m_cancelButton, 0x40);
MS2_CHECK_OFFSET(UIDungeonSearchPage, m_settingButton, 0x50);
MS2_CHECK_OFFSET(UIDungeonSearchPage, m_rooms, 0x60);

class UIDungeonSearchDialog : public UIDialog
{
public:
    UIDungeonSearchDialog();                                                    // 0x140e19b60
    virtual ~UIDungeonSearchDialog();                                           // 0x140e19dd0

    virtual CString vfunc_1();                                                  //  1 "DungeonSearchDialog"
    virtual void OnLoadComplete();                                              // 22
    virtual void vfunc_26();                                                    // 26
    virtual int vfunc_48() { return 0x4f1c; }                                   // 48 UI type id (COMDAT 0x140e1f110)

    void FUN_140e1b640(CInPacket& packet);                                      // packet 0x53: refresh the pages
    void FUN_140e1b6f0(CInPacket& packet);                                      // packet 0x1a: reward reset result
    void FUN_140e1b760(CInPacket& packet);                                                     // united reward reset message
    void FUN_140e1b800(NotifyObject* pNotify);                                  // NotifyGameStart: pages
    void FUN_140e1b850(const Scaleform::GFx::FunctionHandler::Params& params);  // opens the select dialog
    void SendRoomDungeonMode4(const Scaleform::GFx::FunctionHandler::Params& params);  // category 4 packet
    void SendRoomDungeonMode12(const Scaleform::GFx::FunctionHandler::Params& params);  // category 12 packet
    void SendRoomDungeonMode13(const Scaleform::GFx::FunctionHandler::Params& params);  // category 13 packet
    void SendRoomDungeonMode14(const Scaleform::GFx::FunctionHandler::Params& params);  // category 14 packet
    void FUN_140e1ba50(const Scaleform::GFx::FunctionHandler::Params& params);  // opens UI 0x4eda
    void FUN_140e1ba80(int nPage, const std::list<int>& rooms);                 // sets the room list of a page
    MS2Ptr<UIDungeonSearchPage> FUN_140e1baf0(int nPage);                       // page 1 = custom, otherwise random
    void FUN_140e1bb70();                                                       // enables the category buttons
    void FUN_140e1bc70(int nContent, int nButton);                              // enables one category button
    void FUN_140e1bd90(int nContent, int nButton);                              // disables one category button

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<UIDungeonSearchPage> m_pageCustom;                                   // +0x178 page 1
    MS2Ptr<UIDungeonSearchPage> m_pageRandom;                                   // +0x188 page 2
    MS2Ptr<UIDungeonSearchUnitedReward> m_unitedReward;                         // +0x198 "m_unitedReward"
    std::vector<MS2Ptr<Unk_DsButton> > m_subButtons;                            // +0x1a8 "m_subButton0".."m_subButton11"
    std::vector<MS2Ptr<Unk_DsLabel> > m_subLabels;                              // +0x1c0 "m_subLabel0".."m_subLabel11"
    MS2Ptr<ASMovieClip> m_subPanel;                                             // +0x1d8 "m_subPanel"
};
MS2_CHECK_SIZE(UIDungeonSearchDialog, 0x1e8);
MS2_CHECK_OFFSET(UIDungeonSearchDialog, m_pageCustom, 0x178);
MS2_CHECK_OFFSET(UIDungeonSearchDialog, m_pageRandom, 0x188);
MS2_CHECK_OFFSET(UIDungeonSearchDialog, m_unitedReward, 0x198);
MS2_CHECK_OFFSET(UIDungeonSearchDialog, m_subButtons, 0x1a8);
MS2_CHECK_OFFSET(UIDungeonSearchDialog, m_subLabels, 0x1c0);
MS2_CHECK_OFFSET(UIDungeonSearchDialog, m_subPanel, 0x1d8);
