// fittingdollslot.h - FittingDollSlot / FittingDollSlotBag: the item slots of the fitting doll window (one slot per equip
// position of the doll, its items are the doll's FittingDollPC equipment). A slot knows the player it belongs to (object
// id) and the doll's entity id; dropping or double-clicking the worn doll item destroys it (packet 0x42). The bag keeps the
// equip position of each of its 12 slots (the two layouts differ in the position of slots 2 and 3). Owning unit:
// ?\fittingdollslot.cpp (0x14121b350-0x14121f110 .text$mn, 0x1400e9290-0x1400e9740 .text$di; FittingDollPC lives in
// ms2/placeholder/fittingdollpc.h). Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/client/ms2/inventory.h"      // Unk_InventoryEquipSlot

class CItem;
class PC;
class FittingDollPC;

// 0xa8 bytes. vftable 0x142ec3330 (26 slots, ??_G 0x14121e500 sized delete 0xa8), ITooltip @+0x78 0x142ec3408.
class FittingDollSlot : public MS2DragSlot
{
public:
    FittingDollSlot(const CString& strName, int nIndex, int nPcId, unsigned __int64 nDollId, Unk_InventoryEquipSlot nSlot);   // 0x14121d110
    virtual ~FittingDollSlot() = default;               // 0x14121e4e0 (the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x14121e560, TypeCast 0x14121e5d0 / 0x14121e620; ms_ClassInfo 0x143ad3740,
    // SetupClassInfo 0x14121e570 (parent MS2DragSlot, id 0x6200055).
    EE_DECLARE_CLASS1(FittingDollSlot, 0x06200055, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x14121d810 build the slot (item, flags) into p
    virtual void vfunc_9();                             // 9  0x14121dc90 set m_strSlotType on the bound value
    virtual int vfunc_13();                             // 13 0x14121d1c0 return 0
    virtual int vfunc_14();                             // 14 0x14121d1d0 destroy the doll item (FUN_14121ddc0)
    virtual int vfunc_15();                             // 15 0x14121d1f0 link the item
    virtual int vfunc_18(void* p);                      // 18 0x14121d280 an inventory item was dropped on the slot
    virtual int vfunc_20();                             // 20 0x14121d330 drag start: item sound
    virtual int vfunc_21();                             // 21 0x14121d4a0 drag end: item sound
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x14121db80 the item worn by the doll in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x14121d610 build the tooltip into p

    PC* FUN_14121dd90();                                // 0x14121dd90 the player
    FittingDollPC* FUN_14121dd50();                     // 0x14121dd50 the doll
    int FUN_14121ddc0();                                // 0x14121ddc0 destroy the doll item (confirm box / packet 0x42)

public:
    MS2_LAYOUT_FRIEND;
    int m_nPcId;                                        // +0x90 object id of the player
    int m_pad_94;
    unsigned __int64 m_nDollId;                         // +0x98 entity id of the doll
    Unk_InventoryEquipSlot m_nSlot;                     // +0xa0 equip position
    int m_pad_a4;
};
MS2_CHECK_SIZE(FittingDollSlot, 0xa8);
MS2_CHECK_OFFSET(FittingDollSlot, m_nPcId, 0x90);
MS2_CHECK_OFFSET(FittingDollSlot, m_nDollId, 0x98);
MS2_CHECK_OFFSET(FittingDollSlot, m_nSlot, 0xa0);

// 0xe0 bytes. vftable 0x142ec3550 (17 slots, ??_G 0x14121efa0 sized delete 0xe0).
class FittingDollSlotBag : public DragSlotBag
{
public:
    FittingDollSlotBag(const CString& strName, int nPcId, unsigned __int64 nDollId, bool bCodi);   // 0x14121e7b0
    virtual ~FittingDollSlotBag();                      // 0x14121ec70

    // slots 2-4: GetClassDesc 0x14121f000, TypeCast 0x14121f070 / 0x14121f0c0; ms_ClassInfo 0x143ad3bf0,
    // SetupClassInfo 0x14121f010 (parent DragSlotBag, id 0x6200056).
    EE_DECLARE_CLASS1(FittingDollSlotBag, 0x06200056, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x14121ecb0 "<name>.<equip position>"
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x14121ed70 new FittingDollSlot for the position of nIndex

    int FUN_14121eee0();                                // number of slots
    Unk_InventoryEquipSlot FUN_14121ef10(int nIndex);   // the equip position of a slot index

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<int, Unk_InventoryEquipSlot> m_mapSlot;   // +0x88 slot index -> equip position
    int m_nPcId;                                        // +0xd0
    int m_pad_d4;
    unsigned __int64 m_nDollId;                         // +0xd8
};
MS2_CHECK_SIZE(FittingDollSlotBag, 0xe0);
MS2_CHECK_OFFSET(FittingDollSlotBag, m_mapSlot, 0x88);
MS2_CHECK_OFFSET(FittingDollSlotBag, m_nPcId, 0xd0);
MS2_CHECK_OFFSET(FittingDollSlotBag, m_nDollId, 0xd8);
