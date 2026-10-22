// equipslot.h - EquipSlot / EquipSlotBag: the slots of the equipment window (one worn-item slot per equip position of a
// PCInfo: the player's own equipment, the preview of another player, the codi / avatar sets). The slot holds the PCInfo
// and the (set kind, equip position) it shows; dropping an inventory item on it equips the item, dropping another equip
// slot swaps them by packet. The bag keeps the position of each of its 12 slots. Owning unit: ?\equipslot.cpp
// (0x14120c0e0-0x14120f7c0, .text$di 0x1400e8e70). Header name assumed from the unit path; member names are invented from
// the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/client/ms2/inventory.h"      // Unk_InventoryEquipSlot

class CItem;
class PCInfo;

// 0xb0 bytes. vftable (26 slots, ??_G 0x14120d650 sized delete 0xb0), ITooltip @+0x78.
class EquipSlot : public MS2DragSlot
{
public:
    EquipSlot(const CString& strName, int nIndex, MS2Ptr<PCInfo> spPC, int nSlot, int nKind, int nUnk);   // 0x14120c0e0
    virtual ~EquipSlot() = default;                     // 0x14120d5e0 (the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x14120d6b0, TypeCast 0x14120d720 / 0x14120d770; ms_ClassInfo 0x143ad28c0,
    // SetupClassInfo 0x14120d6c0 (parent MS2DragSlot, id 0x620002b).
    EE_DECLARE_CLASS1(EquipSlot, 0x0620002B, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x14120cae0 build the slot (item, flags) into p
    virtual void vfunc_9();                             // 9  0x14120cd40 set m_strSlotType on the bound value
    virtual int vfunc_13();                             // 13 0x14120c1b0 return 0
    virtual int vfunc_14();                             // 14 0x14120c1c0 take the worn item off
    virtual int vfunc_15();                             // 15 0x14120c240 link the item / notice when no pc
    virtual int vfunc_17();                             // 17 0x14120c2f0 return vfunc_10()
    virtual int vfunc_18(void* p);                      // 18 0x14120c320 something was dropped on the slot
    virtual int vfunc_20();                             // 20 0x14120c5e0 drag start: item sound
    virtual int vfunc_21();                             // 21 0x14120c750 drag end: item sound
    virtual CStringW vfunc_22();                        // 22 0x14120d1b0 string 0x752
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x14120ce00 the item worn in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x14120c8c0 build the tooltip into p

    MS2Ptr<CItem> FUN_14120ce90(int nKind);             // the item of a set kind (the codi sets fall back to the other slot)
    int GetKind();                                // m_nKind
    int FUN_14120d1f0();                                // the pc is set and its flag is nonzero
    int FUN_14120d250(CItem* pItem);                    // can the item be put on (notice otherwise)
    int FUN_14120d2e0(CItem* pItem);                    // can the item be put on this slot (notice otherwise)
    int FUN_14120d510(CItem* pItem);                    // the inventory accepts the item

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<PCInfo> m_spPC;                              // +0x90
    int m_nKind;                                        // +0xa0
    int m_nUnkA4;                                       // +0xa4
    int m_nSlot;                                        // +0xa8
};
MS2_CHECK_SIZE(EquipSlot, 0xb0);
MS2_CHECK_OFFSET(EquipSlot, m_spPC, 0x90);
MS2_CHECK_OFFSET(EquipSlot, m_nKind, 0xa0);
MS2_CHECK_OFFSET(EquipSlot, m_nSlot, 0xa8);

// 0xe8 bytes. vftable (16 slots, ??_G 0x14120e9... sized delete 0xe8).
class EquipSlotBag : public DragSlotBag
{
public:
    EquipSlotBag(const CString& strName, MS2Ptr<PCInfo> spPC, int nKind, int nUnk);     // 0x14120d930
    virtual ~EquipSlotBag();                            // 0x14120de20

    // slots 2-4: GetClassDesc 0x14120e9d0, TypeCast 0x14120f640 / 0x14120f690; ms_ClassInfo 0x143ad2cd0,
    // SetupClassInfo 0x14120f5e0 (parent DragSlotBag, id 0x620002c).
    EE_DECLARE_CLASS1(EquipSlotBag, 0x0620002C, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x14120de80 "<name>.<equip position>"
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x14120df40 new EquipSlot for the position of nIndex

    int FUN_14120e090();                                // number of slots
    Unk_InventoryEquipSlot FUN_14120e0c0(int nIndex);   // the equip position of a slot index

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<PCInfo> m_spPC;                              // +0x88
    int m_nKind;                                        // +0x98
    int m_nUnk9C;                                       // +0x9c
    ATL::CAtlMap<int, Unk_InventoryEquipSlot> m_mapSlot;   // +0xa0 slot index -> equip position
};
MS2_CHECK_SIZE(EquipSlotBag, 0xe8);
MS2_CHECK_OFFSET(EquipSlotBag, m_spPC, 0x88);
MS2_CHECK_OFFSET(EquipSlotBag, m_mapSlot, 0xa0);
