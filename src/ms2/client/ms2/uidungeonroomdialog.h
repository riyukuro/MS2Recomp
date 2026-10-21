// uidungeonroomdialog.h - UIDungeonRoomDialog (RTTI .?AVUIDungeonRoomDialog@@, 0x258 bytes, UI id 0x4ebd, swf
// "DungeonRoomDialog"): the dungeon list window (dungeon groups, the room list, the selected room's info panel with its
// rewards, mission ranks and season rank rewards, enter / party / helper buttons). Owning unit:
// client\ms2\uidungeonroomdialog.cpp (0x1412a74a0-0x1412c2020, statics 0x1400ed270-0x1400ed3e0). Header name assumed
// from the unit path. Class names are RTTI; member names follow the AS instance names the ctors bind (string evidence)
// and the v2525 snapshot's headers (same layouts); method names are invented unless noted.
#pragma once
#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/gfxvalue.h"

class ASButton;
class ASDropdownMenu;
class ASGaugeControl;
class ASItemRendererBase;
class ASItemSlot;
class ASLabel;
class ASLoader;
class ASMovieClip;
class ASScrollPanel;
class ASTextField;
class ASTileList;
class ASUIComponent;
class ASData;
class CInPacket;
class CMsgBoxData;
class CPartyMember;
class DungeonRoom;
class NotifyObject;
class UIDungeonRoomDialog;

typedef Scaleform::GFx::FunctionHandler::Params ASParams;

// The "mission rank" sub panel (sub panel 3): the room's missions with their best score, the high / season score.
// RTTI .?AVUIDungeonRoomRankPanel@@, 0x60 bytes, vftable 0x142edc168 (??_G 0x1412c0610), implicit dtor 0x1412bfe20.
class UIDungeonRoomRankPanel : public CPtred
{
public:
    UIDungeonRoomRankPanel(MS2Ptr<ASMovieClip> spPanel);           // 0x1412a74a0
    void Refresh(MS2Ptr<DungeonRoom> spRoom);                       // 0x1412a78a0
    void Reset();                                                   // 0x1412a81d0
    void AddMissionLabels(size_t nCount);                           // 0x1412a83e0
    void SetLayout(unsigned __int64 nLines);                        // 0x1412a8770

    MS2Ptr<ASMovieClip> m_spPanel;                                  // +0x18
    MS2Ptr<ASMovieClip> m_missionRankIcon;                          // +0x28
    MS2Ptr<ASMovieClip> m_summaryScore;                             // +0x38
    std::vector<MS2Ptr<ASMovieClip> > m_missions;                   // +0x48 "UIDungeonRoom_MissionLabel" clips
};
MS2_CHECK_SIZE(UIDungeonRoomRankPanel, 0x60);

// The season rank reward sub panel (sub panel 4): five reward slots and their rank marks.
// RTTI .?AVUIDungeonRoomSeasonRankReward@@, 0x70 bytes, vftable 0x142edc178 (??_G 0x1412c0650).
class UIDungeonRoomSeasonRankReward : public CPtred
{
public:
    UIDungeonRoomSeasonRankReward(MS2Ptr<ASMovieClip> spPanel);    // 0x1412a87e0
    virtual ~UIDungeonRoomSeasonRankReward();                       // 0x1412a8d30
    void Refresh(MS2Ptr<DungeonRoom> spRoom);                       // 0x1412a8e20

    MS2Ptr<ASMovieClip> m_spPanel;                                  // +0x18
    std::vector<MS2Ptr<ASMovieClip> > m_seasonRankReward;           // +0x28 x5
    std::vector<MS2Ptr<ASItemSlot> > m_slots;                       // +0x40 the "m_slot" of each reward
    std::vector<MS2Ptr<ASMovieClip> > m_seasonRank;                 // +0x58 x5
};
MS2_CHECK_SIZE(UIDungeonRoomSeasonRankReward, 0x70);

// The stacked limit texts of the requirement sub panel (sub panel 1).
// RTTI .?AVUIDungeonRoomLimitTextGroup@@, 0x48 bytes, vftable 0x142edc188 (??_G 0x1412c05d0).
class UIDungeonRoomLimitTextGroup : public CPtred
{
public:
    UIDungeonRoomLimitTextGroup(MS2Ptr<ASMovieClip> spPanel);      // 0x1412a94e0
    virtual ~UIDungeonRoomLimitTextGroup();                         // 0x1412a9570
    void SetPosition(int x, int y);                                 // 0x1412a95e0
    int GetBottom();                                                // 0x1412a9610
    void AddText(const CStringW& strText, int nColor, const CStringW& strTooltip);   // 0x1412a9630
    void Clear();                                                   // 0x1412a98d0

    MS2Ptr<ASMovieClip> m_spPanel;                                  // +0x18
    std::vector<MS2Ptr<ASLabel> > m_labels;                         // +0x28
    int m_x;                                                        // +0x40
    int m_y;                                                        // +0x44 the next line's y
};
MS2_CHECK_SIZE(UIDungeonRoomLimitTextGroup, 0x48);

// The selected room's info panel ("m_dungeonInfo").
// RTTI .?AVUIDungeonRoomInfo@@, 0x278 bytes, vftable 0x142edc198 (??_G 0x1412c0590).
class UIDungeonRoomInfo : public CPtred
{
public:
    UIDungeonRoomInfo(UIDungeonRoomDialog* pOwner, MS2Ptr<ASMovieClip> spPanel);   // 0x1412a99a0
    virtual ~UIDungeonRoomInfo();                                   // 0x1412ad760
    void Refresh();                                                 // 0x1412adb40 (the room changed)
    void RefreshSubTabVisibility();                                 // 0x1412adfc0 mission rank / season rank tabs
    void RefreshLimits();                                           // 0x1412ae2b0 the requirement texts
    void FUN_1412b0110();                                           // 0x1412b0110
    void RefreshReward();                                           // 0x1412b0d30
    void RefreshNormalReward();                                     // 0x1412b0da0
    void RefreshRoundReward();                                      // 0x1412b1d50
    void FUN_1412b2250();                                           // 0x1412b2250
    void FUN_1412b2e70();                                           // 0x1412b2e70
    void RefreshEnterButtons();                                     // 0x1412b3120
    void FUN_1412b3180();                                           // 0x1412b3180 not in a party
    void FUN_1412b3430();                                           // 0x1412b3430 in a party
    void RefreshResetButton();                                      // 0x1412b3720
    void RefreshHelper();                                           // 0x1412b3850
    void FUN_1412b3890();                                           // 0x1412b3890
    void FUN_1412b3b40();                                           // 0x1412b3b40
    void FUN_1412b3e90();                                           // 0x1412b3e90
    void FUN_1412b3fe0();                                           // 0x1412b3fe0
    CStringW FUN_1412b4100();                                       // 0x1412b4100 the party status text (m_strBanner)
    void FUN_1412b4150(MS2Ptr<DungeonRoom> spRoom);                 // 0x1412b4150 set the room
    void OnEnterSolo(const ASParams& params);                       // 0x1412b41a0
    void OnEnterParty(const ASParams& params);                      // 0x1412b4220
    void OnPartySearch(const ASParams& params);                     // 0x1412b4330
    void OnAddExtraRewardCount(const ASParams& params);             // 0x1412b4480
    void OnChangeExpert(const ASParams& params);                    // 0x1412b49d0
    void OnSubTab(const ASParams& params);                          // 0x1412b4b40
    void OnFindHelper(const ASParams& params);                      // 0x1412b4c00
    void OnFindMember(const ASParams& params);                      // 0x1412b4ee0
    void OnRequireCondition(const ASParams& params);                // 0x1412b51c0
    void OnReset(const ASParams& params);                           // 0x1412b5290
    void OnFavoriteMark(const ASParams& params);                    // 0x1412b5320
    bool OnUseExtraRewardItem(int nButton, const CMsgBoxData& box); // 0x1412b5410
    bool OnUseExtraTicketEnter(int nButton, const CMsgBoxData& box);// 0x1412b54a0
    bool OnChangeHelpDungeon(int nButton, const CMsgBoxData& box);  // 0x1412b54f0
    bool OnChangeMemberDungeon(int nButton, const CMsgBoxData& box);// 0x1412b5540
    bool OnLeaveDungeonForHelp(int nButton, const CMsgBoxData& box);// 0x1412b5590
    bool OnChangeExpertConfirm(int nButton, const CMsgBoxData& box);// 0x1412b55c0
    void RequestFindHelper(unsigned nRoomId);                       // 0x1412b5610
    void RequestFindMember(unsigned nRoomId);                       // 0x1412b5680
    void RequestChangeExpert(unsigned nRoomId);                     // 0x1412b56f0
    void RequestLeaveDungeon();                                     // 0x1412b5760
    void LayoutSubPanels();                                         // 0x1412b57c0
    void LayoutSearching();                                         // 0x1412b59a0
    bool CanAskHelp();                                              // 0x1412b5c40
    bool AskExtraTicketEnter(bool bParty);                          // 0x1412b5ee0 true: asked (or entering waits for the box)
    void RequestEntry(bool bParty, bool bUseTicket);                // 0x1412b6250
    int GetClearCount();                                            // 0x1412b6360
    int GetMemberClearCount(MS2Ptr<CPartyMember> spMember);         // 0x1412b63d0
    CString GetCountColor(int nState);                              // 0x1412b6480
    CStringW FUN_1412b6530(int nState, CStringW strName);           // 0x1412b6530 a party member's status tooltip line
    int IsCooldown();                                               // 0x1412b6bb0

    UIDungeonRoomDialog* m_pOwner;                                  // +0x18
    MS2Ptr<ASMovieClip> m_spPanel;                                  // +0x20
    MS2Ptr<ASButton> m_enterSoloButton;                             // +0x30
    MS2Ptr<ASButton> m_enterPartyButton;                            // +0x40
    MS2Ptr<ASButton> m_partySearchButton;                           // +0x50
    MS2Ptr<ASButton> m_resetButton;                                 // +0x60
    MS2Ptr<ASButton> m_addExtraRewardCount;                         // +0x70
    MS2Ptr<ASMovieClip> m_dungeonBanner;                            // +0x80
    MS2Ptr<ASScrollPanel> m_dungeonScrollInfo;                      // +0x90
    MS2Ptr<ASTextField> m_enterStatusText;                          // +0xa0
    MS2Ptr<ASButton> m_findHelperButton;                            // +0xb0
    MS2Ptr<ASButton> m_findMemberButton;                            // +0xc0
    MS2Ptr<ASButton> m_changeExpertButton;                          // +0xd0
    MS2Ptr<ASMovieClip> m_clearCount;                               // +0xe0
    MS2Ptr<ASMovieClip> m_helpCoinInfo;                             // +0xf0
    MS2Ptr<ASMovieClip> m_dungeonHelpEvent;                         // +0x100
    MS2Ptr<ASMovieClip> m_dungeonSearching;                         // +0x110
    MS2Ptr<ASButton> m_favoriteMark;                                // +0x120
    std::vector<MS2Ptr<ASMovieClip> > m_partyMembers;               // +0x130 "m_partyMember" x10
    std::vector<MS2Ptr<ASMovieClip> > m_subPanels;                  // +0x148 "m_subPanel" x5
    std::vector<MS2Ptr<ASButton> > m_subTabButtons;                 // +0x160 "m_subTabButton" x5
    MS2Ptr<ASUIComponent> m_rewardIcon1;                            // +0x178
    MS2Ptr<ASUIComponent> m_rewardIcon2;                            // +0x188
    MS2Ptr<ASTextField> m_dungeonDesc;                              // +0x198
    MS2Ptr<ASTextField> m_limitText;                                // +0x1a8
    MS2Ptr<ASMovieClip> m_requireCondition;                         // +0x1b8
    std::vector<MS2Ptr<ASMovieClip> > m_rewardItems;                // +0x1c8 "m_rewardItem" x28
    ItemSlotBinder m_slotBinder;                                    // +0x1e0 "DungeonRoomDialog"
    MS2Ptr<UIDungeonRoomRankPanel> m_spRankPanel;                   // +0x220
    MS2Ptr<UIDungeonRoomSeasonRankReward> m_spSeasonRankReward;     // +0x230
    MS2Ptr<UIDungeonRoomLimitTextGroup> m_spLimitTextGroup;         // +0x240
    MS2Ptr<ASLoader> m_spBannerLoader;                              // +0x250
    MS2Ptr<DungeonRoom> m_spRoom;                                   // +0x260
    CStringW m_strBanner;                                           // +0x270
};
MS2_CHECK_SIZE(UIDungeonRoomInfo, 0x278);
MS2_CHECK_OFFSET(UIDungeonRoomInfo, m_rewardIcon1, 0x178);
MS2_CHECK_OFFSET(UIDungeonRoomInfo, m_slotBinder, 0x1e0);

class UIDungeonRoomDialog : public UIDialog
{
public:
    UIDungeonRoomDialog();                                          // 0x1412b6c90
    virtual ~UIDungeonRoomDialog();                                 //  0 0x1412b6f60 (??_G 0x1412c0550)
    virtual CString vfunc_1();                                      //  1 0x1412b71d0 "DungeonRoomDialog"
    virtual void OnLoadComplete();                                  // 22 0x1412b7220
    virtual void vfunc_26();                                        // 26 0x1412b82f0
    virtual void vfunc_43();                                        // 43 0x1412b8cc0
    virtual int vfunc_48() { return 0x4ebd; }                       // 48 0x1412c0690
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x1412b87c0

    void OnPartyPacket(CInPacket& packet);                          // 0x1412b8ce0 packet 0x53 (while loaded): refresh
    void OnRoomPacket(CInPacket& packet);                           // 0x1412b8d60 packet 0x1a
    void OnRoomPacket53(CInPacket& packet);                         // 0x1412b8e30 packet 0x53: the search buttons
    bool FUN_1412b8f00(int nId);                                    // 0x1412b8f00 open a dungeon (id <= 100000) or a room
    bool FUN_1412b8ff0(int nRoomId);                                // 0x1412b8ff0 open a room
    void FUN_1412b90d0(int nType);                                  // 0x1412b90d0 m_17c (the group type to open)
    void FUN_1412b90f0(int n);                                      // 0x1412b90f0 m_178
    void FUN_1412b9110();                                           // 0x1412b9110 m_180 = 0
    void Refresh();                                                 // 0x1412b9130
    void RefreshSubTitle();                                         // 0x1412b91d0
    void FUN_1412b9320();                                           // 0x1412b9320 refresh the reward texts
    void RefreshSeasonSummary();                                    // 0x1412b9370
    void FUN_1412b9460();                                           // 0x1412b9460 empty
    void OnGroupChanged(const ASParams& params);                    // 0x1412b9470 m_dungoenGroupCombo
    void OnRoomSelected(const ASParams& params);                    // 0x1412b94f0 m_dungeonList
    void OnListItemData(const ASParams& params);                    // 0x1412b95e0 m_dungeonListItem rows
    void OnNotifyDebugMode(NotifyObject* pNotify);                  // 0x1412b97f0
    void OnNotifyEnterState(NotifyObject* pNotify);                 // 0x1412b9820
    int FUN_1412b9850();                                            // 0x1412b9850 m_178
    void ShowAchieveTooltip(Scaleform::GFx::Value* pRetVal);        // 0x1412ba100
    void ShowVipTooltip(Scaleform::GFx::Value* pRetVal);            // 0x1412ba290
    bool SelectGroup(int nGroup, unsigned nRoomId);                 // 0x1412ba3a0
    void RefreshGroupList();                                        // 0x1412ba490
    void SelectComboGroup(int nGroup);                              // 0x1412ba7a0
    void ShowGroup(int nGroup, int nRoomId);                        // 0x1412ba830
    void GetPartyLevel(unsigned short& nLevel, unsigned& nGearScore);   // 0x1412bab90 the player's or the party's
    void SetRoom(MS2Ptr<DungeonRoom> spRoom);                       // 0x1412bac40
    int TypeOfGroup(int nGroup);                                    // 0x1412bacf0 combo group -> DungeonGroupType
    int GroupOfType(int nType);                                     // 0x1412bade0 DungeonGroupType -> combo group
    MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out);   // 0x140c57ce0 bind a clip child

    int m_178;                                                      // +0x178
    int m_17c;                                                      // +0x17c
    int m_180;                                                      // +0x180
    unsigned m_184;                                                 // +0x184
    CStringW m_188;                                                 // +0x188
    MS2Ptr<DungeonRoom> m_spRoom;                                   // +0x190
    std::vector<MS2Ptr<DungeonRoom> > m_rooms;                      // +0x1a0
    std::vector<int> m_dungeonIds;                                  // +0x1b8
    MS2Ptr<UIDungeonRoomInfo> m_spInfo;                             // +0x1d0
    MS2Ptr<ASTileList> m_dungeonList;                               // +0x1e0
    MS2Ptr<ASUIComponent> m_1f0;                                    // +0x1f0
    MS2Ptr<ASUIComponent> m_200;                                    // +0x200
    MS2Ptr<ASDropdownMenu> m_dungeonGroupCombo;                     // +0x210
    MS2Ptr<ASGaugeControl> m_220;                                   // +0x220
    MS2Ptr<ASGaugeControl> m_230;                                   // +0x230
    std::vector<MS2Ptr<ASItemRendererBase> > m_240;                 // +0x240 "m_dungeonListItem" x21
};
MS2_CHECK_SIZE(UIDungeonRoomDialog, 0x258);
MS2_CHECK_OFFSET(UIDungeonRoomDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIDungeonRoomDialog, m_240, 0x240);
