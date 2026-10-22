// uidungeonsearchselectdialog.h - UIDungeonSearchSelectDialog (RTTI .?AVUIDungeonSearchSelectDialog@@, 0x250 bytes,
// UIModalDialog, UI id 0x4f22, swf "DungeonSearchSelectDialog"): the dungeon picker opened by the dungeon search page's
// setting button. It lists the dungeon rooms of one group (11 rows with a check box each), lets the player tick the
// rooms to search and hands the ticked set back to UIDungeonSearchDialog on OK. Owning unit:
// client\ms2\uidungeonsearchselectdialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <set>
#include <list>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/ascript.h"

class Unk_SdRadio;
class Unk_SdButton;
class Unk_SdList;
class Unk_SdRow;
class Unk_SdCheck;

class UIDungeonSearchSelectDialog : public UIModalDialog
{
public:
    UIDungeonSearchSelectDialog();                              // 0x140e26c20
    virtual ~UIDungeonSearchSelectDialog();                     //  0 0x140e26d60 (??_G 0x140e29060)
    virtual CString GetTypeName();                                  //  1 0x140e26e60 "DungeonSearchSelectDialog"
    virtual void OnLoadComplete();                              // 22 0x140e26eb0
    virtual void vfunc_26();                                    // 26 0x140e27df0
    virtual int vfunc_48() { return 0x4f22; }                   // 48 0x140e290a0

    // Opens the dialog for one page: rooms = the dungeon ids of its group, pSelected = the ids ticked so far.
    void FUN_140e27ed0(int nPage, std::set<unsigned>& rooms, std::set<unsigned>* pSelected);   // 0x140e27ed0
    void FUN_140e27f80();                                       // title and the "recommended" radio
    void FUN_140e28100();                                       // the list's row count
    void FUN_140e28170(const Scaleform::GFx::FunctionHandler::Params& params);   // the radio was clicked: select all
    void FUN_140e281f0(const Scaleform::GFx::FunctionHandler::Params& params);   // OK
    void FUN_140e28280(const Scaleform::GFx::FunctionHandler::Params& params);   // a row was filled
    void FUN_140e286a0(const Scaleform::GFx::FunctionHandler::Params& params);   // a row's tooltip
    void FUN_140e288f0(const Scaleform::GFx::FunctionHandler::Params& params);   // a check box was clicked
    void FUN_140e28a40(const Scaleform::GFx::FunctionHandler::Params& params);   // the radio's other state

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_SdRadio> m_radio;                                // +0x180 "m_radioRecommend"
    MS2Ptr<ASMovieClip> m_page;                                 // +0x190 "m_customPage"
    MS2Ptr<Unk_SdButton> m_okButton;                            // +0x1a0 "m_okButton"
    MS2Ptr<Unk_SdList> m_list;                                  // +0x1b0 "m_customList"
    std::vector<MS2Ptr<Unk_SdRow> > m_rows;                     // +0x1c0 "m_listItem1".."m_listItem11"
    std::vector<MS2Ptr<Unk_SdCheck> > m_checks;                 // +0x1d8 the rows' "m_checkBox"
    std::vector<unsigned> m_roomOfRow;                          // +0x1f0 row -> index into m_rooms
    int m_nPage;                                                // +0x208 1 = custom dungeon page
    std::vector<DungeonRoomPtr> m_rooms;                        // +0x210 the group's dungeon rooms
    bool m_bAll;                                                // +0x228 nothing ticked yet: select all
    std::set<unsigned> m_allRooms;                              // +0x230 the dungeon ids offered
    std::set<unsigned> m_selected;                              // +0x240 the ticked dungeon ids
};
MS2_CHECK_SIZE(UIDungeonSearchSelectDialog, 0x250);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_radio, 0x180);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_page, 0x190);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_okButton, 0x1a0);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_list, 0x1b0);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_rows, 0x1c0);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_checks, 0x1d8);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_roomOfRow, 0x1f0);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_nPage, 0x208);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_rooms, 0x210);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_bAll, 0x228);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_allRooms, 0x230);
MS2_CHECK_OFFSET(UIDungeonSearchSelectDialog, m_selected, 0x240);
