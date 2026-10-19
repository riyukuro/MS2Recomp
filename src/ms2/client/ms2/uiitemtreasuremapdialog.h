// uiitemtreasuremapdialog.h - UIItemTreasureMapDialog (RTTI .?AVUIItemTreasureMapDialog@@, 0x208 bytes, UI type 0x4f5b,
// swf "ItemTreasureMapDialog"): the window in which a treasure map is appraised. The dialog lists the treasure maps of the
// inventory in an item bag (m_itemBag), the player picks one, presses the m_submit button and the server appraises it
// (packet 0x9f sub 2: item uid + the "free" flag). The server answers with packet 0xf5: sub 2 = the cost of the appraise for
// the picked map, sub 3 = the result of the appraise (a new item) or the end of the appraise. A free appraise (the "free"
// parameter, FUN_140c55b50) costs nothing. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\uiitemtreasuremapdialog.cpp` (0x140c54ee0-0x140c581a0 .text$mn, 0x1400cd9a0-0x1400cdba0 .text$di, dir client\ms2).
// Header/unit/member names assumed. w420.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Overridden slots: 0 (dtor), 1 (class name), 13, 22 (OnLoadComplete),
// 43 (placed beside the maid dialog's reference), 48 (UI type), 67 (close), 79 (server packets).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"

class ASMovieClip;
class Unk_140acd6e0;
class Unk_TmBag;

class UIItemTreasureMapDialog : public UIDialog
{
public:
    UIItemTreasureMapDialog();                                       // 0x140c54ee0
    virtual ~UIItemTreasureMapDialog();                              //  0 0x140c55140 (??_G 0x140c58020)
    virtual CString vfunc_1();                                       //  1 0x140c55210: "ItemTreasureMapDialog"
    virtual int vfunc_13();                                          // 13 0x140c55950: 0
    virtual void OnLoadComplete();                                   // 22 0x140c553a0 bind the children
    virtual void vfunc_43();                                         // 43 0x140c55260 placed beside the maid dialog's reference
    virtual int vfunc_48() { return 0x4f5b; }                        // 48 (COMDAT 0x140c58060)
    virtual void vfunc_67();                                         // 67 0x140c558a0 drop the bag, close
    virtual void vfunc_79(void* p);                                  // 79 0x140c55960 server packet 0xf5

    void FUN_140c55b50(const CString& strParam);                     // 0x140c55b50 "free" parameter: free appraise
    void FUN_140c55ba0(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140c55ba0 item bag click: ask the cost
    void FUN_140c55d20(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140c55d20 m_submit click
    void FUN_140c55ea0();                                            // 0x140c55ea0 show the initial (select) page
    void FUN_140c560f0();                                            // 0x140c560f0 collect the treasure maps, fill the bag
    void FUN_140c563d0();                                            // 0x140c563d0 start the appraise
    void FUN_140c56670();                                            // 0x140c56670 back to the select page
    void FUN_140c56a50(__int64 nUid, __int64 nCost);                 // 0x140c56a50 packet: the cost of the picked map
    void FUN_140c57300(int nItemId, int nRank);                      // 0x140c57300 packet: the appraised item
    bool FUN_140c57a70(MS2Ptr<CItem> spItem);                        // 0x140c57a70 is a treasure map (the callee drops spItem)
    void FUN_140c57b50();                                            // 0x140c57b50 drop the children
    MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out);   // 0x140c57ce0 bind a movie clip child
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);       // movie clip child lookup (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    int m_nState;                                                    // +0x178 0 select, 1 waiting for the server, 2 result
    CString m_strBag;                                                // +0x180 "<name>.Target" bag id of the maps
    CString m_strBind;                                               // +0x188 "<name>.Select" binding of the shown item
    __int64 m_nCost;                                                 // +0x190 cost of the picked map (-1: none, <0: cannot)
    bool m_bFree;                                                    // +0x198 the free appraise
    ATL::CAtlArray<MS2Ptr<CItem> > m_items;                          // +0x1a0 the treasure maps of the inventory
    MS2Ptr<CItem> m_spTarget;                                        // +0x1c0 the picked map
    __int64 m_nTargetUid;                                            // +0x1d0 the map that is being appraised
    MS2Ptr<ASMovieClip> m_board;                                     // +0x1d8 "m_board"
    MS2Ptr<Unk_140acd6e0> m_submit;                                  // +0x1e8 "m_submit"
    MS2Ptr<Unk_TmBag> m_itemBag;                                     // +0x1f8 "m_itemBag"
};
MS2_CHECK_SIZE(UIItemTreasureMapDialog, 0x208);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_nState, 0x178);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_strBag, 0x180);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_nCost, 0x190);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_bFree, 0x198);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_items, 0x1a0);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_spTarget, 0x1c0);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_nTargetUid, 0x1d0);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_board, 0x1d8);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_submit, 0x1e8);
MS2_CHECK_OFFSET(UIItemTreasureMapDialog, m_itemBag, 0x1f8);
