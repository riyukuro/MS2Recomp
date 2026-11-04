// itemscrollslot.h - ItemScrollSlot: a single item slot of the item scroll windows (enchant / transform scroll dialogs).
// It shows one item (an MS2Ptr<CItem>), and calls two optional callbacks: one when an item is dropped on it (with the
// dragged slot) and one when the item is removed. Owning unit: ?\itemscrollslot.cpp (0x140d42540-0x140d431c0, .text$di
// 0x1400d2c20). Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;
class ItemScrollSlot;

typedef Delegate<void(ItemScrollSlot&, DragSlot*)> ItemScrollSlotDropFn;    // an item was dropped onto the slot
typedef Delegate<void(ItemScrollSlot&)> ItemScrollSlotRemoveFn;             // the item was removed from the slot

// 0xc0 bytes. vftable 0x142e2b770 (26 slots, ??_G 0x140d42ff0 sized delete 0xc0), ITooltip @+0x78.
class ItemScrollSlot : public MS2DragSlot
{
public:
    ItemScrollSlot(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem);   // 0x140d42670
    virtual ~ItemScrollSlot() = default;                // 0x140d42d80 (the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x140d43050, TypeCast 0x140d430c0 / 0x140d43110; ms_ClassInfo 0x143ac26e0,
    // SetupClassInfo 0x140d43060 (parent MS2DragSlot, id 0x6200034).
    EE_DECLARE_CLASS1(ItemScrollSlot, 0x06200034, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140d42a60 build the item slot into p
    virtual int vfunc_14();                             // 14 0x140d42820 remove the item (vfunc_17), return 1
    virtual int vfunc_17();                             // 17 0x140d42740 clear the item, call the remove callback
    virtual int vfunc_18(void* p);                      // 18 0x140d427c0 an item was dropped on the slot
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140d42850 the item in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x140d42940 build the tooltip into p

    void SetItem(MS2Ptr<CItem> spItem);                 // 0x140d428a0
    __int64 FUN_140d428f0();                            // the uid of the item (0 when empty)
    void SetDropFn(ItemScrollSlotDropFn fn);            // 0x140d42b70
    void SetRemoveFn(ItemScrollSlotRemoveFn fn);        // 0x140d42bc0
    void SetFlags(int nFlags);                          // 0x140d42c10

public:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_nOwner;                          // +0x90 ctor argument
    MS2Ptr<CItem> m_spItem;                             // +0x98
    int m_nFlags;                                       // +0xa8 slot build flags (1 initially)
    int m_pad_ac;
    ItemScrollSlotDropFn m_fnDrop;                      // +0xb0
    ItemScrollSlotRemoveFn m_fnRemove;                  // +0xb8
};
MS2_CHECK_SIZE(ItemScrollSlot, 0xc0);
MS2_CHECK_OFFSET(ItemScrollSlot, m_nOwner, 0x90);
MS2_CHECK_OFFSET(ItemScrollSlot, m_spItem, 0x98);
MS2_CHECK_OFFSET(ItemScrollSlot, m_nFlags, 0xa8);
MS2_CHECK_OFFSET(ItemScrollSlot, m_fnDrop, 0xb0);
MS2_CHECK_OFFSET(ItemScrollSlot, m_fnRemove, 0xb8);
