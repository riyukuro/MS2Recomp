// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiselectitemboxdialog.h (name assumed:
// the exe has no __FILE__ string for this unit).
//
// UISelectItemBoxDialog ("SelectItemBoxDialog", UI type 0x4eff, RTTI .?AVUISelectItemBoxDialog@@, 0x278 bytes): the
// window that opens a "select box" item: the player ticks up to m_nSelectCount of the box's reward items and confirms
// ("select_item_box_function" with the chosen indices, comma separated). The rewards come from the drop table
// (individualDropBoxId of the item) and are bound to item slots through two ItemSlotBinders.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/itemslotbinder.h"

// ---- the movie's controls ----
class ASButton;
class ASMultiSelectTileCacheList;
class ASTextField;



// A slot of the movie.
class Unk_SibSlot : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(int bVisible);
};


class UISelectItemBoxDialog : public UIDialog
{
public:
    UISelectItemBoxDialog();                                            // 0x140f99280
    virtual ~UISelectItemBoxDialog();                                   //  0 0x140f99420 (??_G 0x140f9b740)
    virtual CString GetTypeName();                                          //  1 0x140f99500 "SelectItemBoxDialog"
    virtual void OnLoadComplete();                                      // 22 0x140f99550
    virtual void vfunc_26();                                            // 26 0x140f9a140 reset
    virtual int vfunc_48() { return 0x4eff; }                           // 48 0x140f9b780 UI type id

    void SetItemUid(unsigned __int64 uItemUid);                      // the box item to open
    void FUN_140f9a230(const Scaleform::GFx::FunctionHandler::Params& params);   // "m_okButton" clicked: send the choice
    void FUN_140f9a5f0(const Scaleform::GFx::FunctionHandler::Params& params);   // list selection changed
    void FUN_140f9a700();                                               // refresh the slots, counters and the ok label

    // C3: FUN_140e8d030 (bind the tile list) is UISelectSuperWorldChatDialog's (uisidepopuptalk.h), called through a view in the .cpp
    MS2Ptr<ASTextField> FUN_140e48d80(const CString& strName, MS2Ptr<ASTextField>* pOut);

protected:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_uItemUid;                                        // +0x178
    MS2Ptr<ASButton> m_okButton;                                       // +0x180
    MS2Ptr<ASMultiSelectTileCacheList> m_selectItemList;               // +0x190
    std::vector<MS2Ptr<Unk_SibSlot> > m_selectedSlots;                  // +0x1a0 six "m_selectedSlot<n>"
    MS2Ptr<ASTextField> m_selectedCount;                                // +0x1b8
    MS2Ptr<ASTextField> m_selectNotice;                                 // +0x1c8
    std::vector<ItemDropResult> m_rewards;                              // +0x1d8 the box's reward entries
    unsigned m_nSelectCount;                                            // +0x1f0 how many the player may take
    ItemSlotBinder m_binder;                                            // +0x1f8 "SelectItemBoxDialog"
    ItemSlotBinder m_binderSel;                                         // +0x238 "SelectItemBoxDialog_Sel"
};
MS2_CHECK_SIZE(UISelectItemBoxDialog, 0x278);
