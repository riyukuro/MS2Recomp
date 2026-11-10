// itemlockslot.h - ItemLockSlot / ItemLockSlotBag: the slots of the item lock window (UIItemLockDialog). The slot holds
// the item being locked or unlocked; dropping an item onto it asks CItemLockManager to take the item, the bag creates the
// slots (0x12 in the dialog) from the manager's list. Owning unit: ?\itemlockslot.cpp (0x140d418e0-0x140d42540). Header
// name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0xa0 bytes. vftable 0x142e2b370 (26 slots, ??_G 0x140d41ee0 sized delete 0xa0), ITooltip @+0x78.
class ItemLockSlot : public MS2DragSlot
{
public:
    ItemLockSlot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem);     // 0x140d418e0
    virtual ~ItemLockSlot() = default;                  // 0x140d41eb0 (the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x140d41f40, TypeCast 0x140d41fb0 / 0x140d42000; ms_ClassInfo 0x143ac1d80,
    // SetupClassInfo 0x140d41f50 (parent MS2DragSlot, id 0x620006f).
    EE_DECLARE_CLASS1(ItemLockSlot, 0x0620006F, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140d41cf0 build the item slot into p
    virtual int vfunc_14();                             // 14 0x140d41a60 ask the lock manager to unlock the item
    virtual int vfunc_15();                             // 15 0x140d41ad0
    virtual int vfunc_18(void* p);                      // 18 0x140d41990 an item was dropped on the slot
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140d41b40 the item in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x140d41b90 build the tooltip into p

    int CanLockItem(__int64 nItemUid);                // can the item be locked

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_spItem;                             // +0x90
};
MS2_CHECK_SIZE(ItemLockSlot, 0xa0);
MS2_CHECK_OFFSET(ItemLockSlot, m_spItem, 0x90);

// 0x88 bytes. vftable (16 slots, ??_G 0x140d423d0 sized delete 0x88).
class ItemLockSlotBag : public DragSlotBag
{
public:
    ItemLockSlotBag(const CString& strName, int nUnused);   // 0x140d42150 (the second argument is not used)
    virtual ~ItemLockSlotBag();                         // 0x140d421a0

    // slots 2-4: GetClassDesc 0x140d42430, TypeCast 0x140d424a0 / 0x140d424f0; ms_ClassInfo 0x143ac2230,
    // SetupClassInfo 0x140d42440 (parent DragSlotBag, id 0x6200070).
    EE_DECLARE_CLASS1(ItemLockSlotBag, 0x06200070, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x140d421d0 (calls the base)
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x140d42220 new ItemLockSlot holding the manager's item
};
MS2_CHECK_SIZE(ItemLockSlotBag, 0x88);
