// itemslotbinder.h - PLACEHOLDER for ItemSlotBinder (RTTI .?AVItemSlotBinder@@, 0x40 bytes, base CPtred, own
// virtual dtor). NOT an original header. Its unit is ?\itemslotbinder.cpp (0x140d431c0...). Declarations only: ctor
// 0x140d431c0 (takes the owner's name by value: the callee destroys it), dtor 0x140d43260. Members are named by
// offset; the object at +0x30 is a 16-byte container (ctor 0x140c205d0, dtor 0x140c20690).
#pragma once

#include <afx.h>
#include <set>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class ItemSlotBinder : public CPtred
{
public:
    ItemSlotBinder(CString strOwner);       // 0x140d431c0
    virtual ~ItemSlotBinder();              // 0x140d43260

    // Creates the item from (id, rarity), sets its amount and binds it under a new "{owner}_{n}" slot name.
    CString BindNewItem(int nItemId, int nRarity, int nAmount);
    CString FUN_140d43510(const void* pItem);   // binds an item info under a new slot name (dungeon control center reward)
    void FUN_140d43990();                       // unbinds all slots
    CString BindItem(void* pItem);         // binds an already built item (MS2Ptr<CItem>-compatible) under a new slot name
    void FUN_140d438f0(CString strSlot);        // unbinds one slot by name
    friend void SetIconType(ItemSlotBinder* pBinder, int n);     // sets m_24
    friend void SetFlags(ItemSlotBinder* pBinder, int n);     // sets m_28

private:
    MS2_LAYOUT_FRIEND;
    CString m_18;                           // +0x18 owner name
    unsigned m_20;                             // +0x20 running slot counter
    int m_24;                               // +0x24 0x11
    int m_28;                               // +0x28 0x800
    int m_2c;
    std::set<CString> m_slots;              // +0x30 names of the bound slots (16 bytes)
};
MS2_CHECK_SIZE(ItemSlotBinder, 0x40);
MS2_CHECK_OFFSET(ItemSlotBinder, m_18, 0x18);
MS2_CHECK_OFFSET(ItemSlotBinder, m_slots, 0x30);
