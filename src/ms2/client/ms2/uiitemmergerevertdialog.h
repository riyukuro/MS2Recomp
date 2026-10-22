// uiitemmergerevertdialog.h - UIItemMergeRevertDialog (RTTI .?AVUIItemMergeRevertDialog@@, 0x180 bytes, UIDialog, UI id
// 0x4f3d, swf "ItemMergeRevertDialog"): the window that reverts the merged option of an item. It holds one item scroll
// slot (registered under the dialog name), takes the item dragged from the inventory, checks it against the item merged
// before (FUN_140e4d330 returns the error code) and sends packet 0x3f/6 on "onOk". Owning unit:
// ?\uiitemmergerevertdialog.cpp. Header name assumed from the unit path; member names are invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class ItemScrollSlot;
class DragSlot;

class UIItemMergeRevertDialog : public UIDialog
{
public:
    UIItemMergeRevertDialog();                                  // 0x140e4c050
    virtual ~UIItemMergeRevertDialog() = default;               //  0 0x140e4da70 (the exe's dtor writes no vptr; ??_G 0x140e4db90)
    virtual CString GetTypeName();                                  //  1 0x140e4c0d0 "ItemMergeRevertDialog"
    virtual void OnLoadComplete();                              // 22 0x140e4c200 show the empty slot
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140e4c230 onOk: send the revert request
    virtual int vfunc_48() { return 0x4f3d; }                   // 48 0x140e4dbd0
    virtual int vfunc_65();                                     // 65 0x140e4c120
    virtual void vfunc_67();                                    // 67 0x140e4c150 close: forget the item
    virtual void vfunc_72();                                    // 72 0x140e4c1d0 vfunc_55()

    void FUN_140e4c440();                                       // register the empty slot, "setData" (not ready)
    void FUN_140e4c7a0(CItem* pItem);                           // remember the uid of the item merged before
    void FUN_140e4c7d0(CItem* pItem);                           // show the item in the slot, "setData" (ready)
    void FUN_140e4cda0(CItem* pItem);                           // ask for the revert (message), then close
    void FUN_140e4ce70(ItemScrollSlot& slot);                   // the item was removed from the slot
    void FUN_140e4cea0(ItemScrollSlot& slot, DragSlot* pDrag);  // an inventory item was dropped on the slot
    void FUN_140e4d010(int nError);                             // show the message of an error code
    int FUN_140e4d330(CItem* pItem);                            // check the item, 0 ok or an error code (3..8)

private:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_nItemUid;                                // +0x178 uid of the item merged before
};
MS2_CHECK_SIZE(UIItemMergeRevertDialog, 0x180);
MS2_CHECK_OFFSET(UIItemMergeRevertDialog, m_nItemUid, 0x178);
