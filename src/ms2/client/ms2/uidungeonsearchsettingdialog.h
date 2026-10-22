// uidungeonsearchsettingdialog.h - UIDungeonSearchSettingDialog (RTTI .?AVUIDungeonSearchSettingDialog@@, 0x238 bytes,
// UIModalDialog, UI id 0x4f86, swf "DungeonSearchSettingDialog"): the dungeon bookmark settings of the dungeon control
// center. A dropdown picks a dungeon group (none / group 1 / group 2), the list shows the group's dungeon rooms (11 rows
// with a check box each), the player ticks the rooms to bookmark and OK hands the ticked set to UIDungeonControlCenter
// (0x4f84). Owning unit: client\ms2\uidungeonsearchsettingdialog.cpp. Header name assumed from the unit path; member and
// method names are invented from use.
#pragma once
#include <afx.h>
#include <set>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ascorelist.h"

class UIDungeonSearchSettingDialog : public UIModalDialog
{
public:
    UIDungeonSearchSettingDialog();                             // 0x140c0fdc0
    virtual ~UIDungeonSearchSettingDialog();                    //  0 0x140c0fee0 (??_G 0x140c14230)
    virtual CString vfunc_1();                                  //  1 0x140c0ffd0 "DungeonSearchSettingDialog"
    virtual void OnLoadComplete();                              // 22 0x140c10020
    virtual void vfunc_26();                                    // 26 0x140c110b0
    virtual int vfunc_48() { return 0x4f86; }                   // 48 0x140c14270

    void FUN_140c11190(int nGroup);                             // pick the dungeon group: refill m_rooms
    void SetSelected(const std::set<unsigned>& selected);     // the ticked dungeon ids (set by the control center)
    void FUN_140c112e0();                                       // refresh
    void FUN_140c11300();                                       // the list's row count
    void FUN_140c11370(const Scaleform::GFx::FunctionHandler::Params& params);   // the dropdown changed
    void FUN_140c113c0(const Scaleform::GFx::FunctionHandler::Params& params);   // OK
    void FUN_140c11420(const Scaleform::GFx::FunctionHandler::Params& params);   // a row was filled
    void FUN_140c11840(const Scaleform::GFx::FunctionHandler::Params& params);   // a check box was clicked

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASDropdownMenu> m_group;                             // +0x180 "m_groupDropdown"
    MS2Ptr<ASMovieClip> m_page;                                 // +0x190 "m_customPage"
    MS2Ptr<ASButton> m_okButton;                                // +0x1a0 "m_okButton"
    MS2Ptr<ASScrollingList> m_list;                             // +0x1b0 "m_customList"
    std::vector<MS2Ptr<ASItemRendererBase> > m_rows;            // +0x1c0 "m_listItem1".."m_listItem11"
    std::vector<MS2Ptr<ASCheckBox> > m_checks;                  // +0x1d8 the rows' "m_checkBox"
    std::vector<unsigned> m_roomOfRow;                          // +0x1f0 row -> index into m_rooms
    int m_nGroup;                                               // +0x208 0 = both groups, 1 / 2 = one group
    std::vector<DungeonRoomPtr> m_rooms;                        // +0x210 the group's dungeon rooms
    std::set<unsigned> m_selected;                              // +0x228 the ticked dungeon ids
};
MS2_CHECK_SIZE(UIDungeonSearchSettingDialog, 0x238);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_group, 0x180);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_page, 0x190);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_okButton, 0x1a0);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_list, 0x1b0);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_rows, 0x1c0);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_checks, 0x1d8);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_roomOfRow, 0x1f0);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_nGroup, 0x208);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_rooms, 0x210);
MS2_CHECK_OFFSET(UIDungeonSearchSettingDialog, m_selected, 0x228);
