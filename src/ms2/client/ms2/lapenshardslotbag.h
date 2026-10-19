// lapenshardslotbag.h - LapenshardSlotBag: the bag of LapenshardSlots of the lapenshard system window (a list of items,
// slot kind per entry) and of the quick bar (six fixed equip slots). One LapenshardSlot is created per index. Owning unit:
// ?\lapenshardslotbag.cpp (0x140a702f0-0x140a71e70, .text$di 0x1400c4760-0x1400c4a80). Header name assumed from the unit
// path; member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/gfxui/dragslot.h"

class CItem;

// The lapenshard slot number an equip slot index maps to (the exe's map passes its values by reference: an enum).
enum Unk_LapenEquipSlot { kLapenEquipSlotNone = 0 };

// 0xf8 bytes. vftable (17 slots, ??_G 0x140a70d40 sized delete 0xf8).
class LapenshardSlotBag : public DragSlotBag
{
public:
    LapenshardSlotBag(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items, int nKind);   // 0x140a704f0
    explicit LapenshardSlotBag(const CString& strName);          // 0x140a705d0 the six equip slots of the quick bar
    virtual ~LapenshardSlotBag();                                // 0x140a706d0

    // slots 2-4: GetClassDesc 0x140a71080, TypeCast 0x140a71cf0 / 0x140a71d40; ms_ClassInfo 0x143ab7f00,
    // SetupClassInfo 0x140a71c90 (parent DragSlotBag, id 0x6200084).
    EE_DECLARE_CLASS1(LapenshardSlotBag, 0x06200084, DragSlotBag);
public:
    virtual void vfunc_13(int nIndex);                           // 13 0x140a70a80 the slot's vfunc_11
    virtual void vfunc_14(int nIndex);                           // 14 0x140a70ad0 the slot's vfunc_10
    virtual CString vfunc_15(int nIndex);                        // 15 0x140a70730 "<bag name>.<index>"
    virtual DragSlot* vfunc_16(int nIndex);                      // 16 0x140a707f0 new LapenshardSlot for the index

    int FUN_140a70a30();                                         // the number of slots (items, or equip slots)
    int FUN_140a70b20(int nIndex);                               // the lapenshard slot number of an equip slot index

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<CItem> > m_items;                      // +0x88 the items shown (item list mode)
    ATL::CAtlMap<unsigned, Unk_LapenEquipSlot> m_equipSlots;                      // +0xa8 index -> lapenshard slot number (equip slot mode)
    int m_bEquipMode;                                            // +0xf0 1: the six equip slots, 0: the item list
    int m_nKind;                                                 // +0xf4
};
MS2_CHECK_SIZE(LapenshardSlotBag, 0xf8);
MS2_CHECK_OFFSET(LapenshardSlotBag, m_items, 0x88);
MS2_CHECK_OFFSET(LapenshardSlotBag, m_equipSlots, 0xa8);
MS2_CHECK_OFFSET(LapenshardSlotBag, m_bEquipMode, 0xf0);
MS2_CHECK_OFFSET(LapenshardSlotBag, m_nKind, 0xf4);
