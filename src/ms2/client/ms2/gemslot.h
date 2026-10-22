// gemslot.h - GemSlot / GemSlotBag: the slots of the gem page of the my-info window (one slot per gem type of a PCInfo:
// the worn gem items). Dropping a gem item of the slot's type on a slot equips it by packet 0x47, the double click takes
// it off. The bag keeps the gem type of each of its 12 slots. Owning unit: ?\gemslot.cpp (0x14126d170-0x14126fcd0,
// .text$di 0x1400eaed0). Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;
class PCInfo;

// 0xa8 bytes. vftable (26 slots, ??_G 0x14126e180 sized delete 0xa8), ITooltip @+0x78.
class GemSlot : public MS2DragSlot
{
public:
    GemSlot(const CString& strName, MS2Ptr<PCInfo> spPC, int nIndex, int nGemType);   // 0x14126d170
    virtual ~GemSlot() = default;                       // 0x14126e140

    // slots 2-4: GetClassDesc 0x14126e1e0, TypeCast 0x14126e250 / 0x14126e2a0; ms_ClassInfo 0x143ad55d0,
    // SetupClassInfo 0x14126e1f0 (parent MS2DragSlot, id 0x6200053).
    EE_DECLARE_CLASS1(GemSlot, 0x06200053, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x14126dd30 build the slot (item, lock, config, gemSystem) into p
    virtual void vfunc_9();                             // 9  0x14126e080 set m_strSlotType on the bound value
    virtual int vfunc_14();                             // 14 0x14126d430 take the worn gem off
    virtual int vfunc_17();                             // 17 0x14126d210 return vfunc_10()
    virtual int vfunc_18(void* p);                      // 18 0x14126d240 an inventory item was dropped on the slot
    virtual int vfunc_20();                             // 20 0x14126d500 drag start: item sound
    virtual int vfunc_21();                             // 21 0x14126d670 drag end: item sound
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x14126d7e0 the gem item worn in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x14126d9b0 build the tooltip into p

    int FUN_14126d880(CItem* pItem);                    // the item is a gem item the slot's pc can wear
    int GetGemType();                                // m_nGemType
    int FUN_14126d950();                                // the pc is set and its flag is nonzero

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<PCInfo> m_spPC;                              // +0x90
    int m_nGemType;                                     // +0xa0
    int m_pad_a4;
};
MS2_CHECK_SIZE(GemSlot, 0xa8);
MS2_CHECK_OFFSET(GemSlot, m_spPC, 0x90);
MS2_CHECK_OFFSET(GemSlot, m_nGemType, 0xa0);

// 0xe0 bytes. vftable (16 slots, ??_G 0x14126eb70 sized delete 0xe0).
class GemSlotBag : public DragSlotBag
{
public:
    GemSlotBag(const CString& strName, MS2Ptr<PCInfo> spPC);    // 0x14126e440
    virtual ~GemSlotBag();                              // 0x14126e6f0

    // slots 2-4: GetClassDesc 0x14126edd0, TypeCast 0x14126fa40 / 0x14126fa90; ms_ClassInfo 0x143ad5a80,
    // SetupClassInfo 0x14126f9e0 (parent DragSlotBag, id 0x6200054).
    EE_DECLARE_CLASS1(GemSlotBag, 0x06200054, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x14126e750 "<name>.<index>"
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x14126e810 new GemSlot for the gem type of nIndex

    int FUN_14126e930();                                // number of slots
    int FUN_14126e960(int nIndex);                      // the gem type of a slot index

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<PCInfo> m_spPC;                              // +0x88
    ATL::CAtlMap<int, int> m_mapSlot;                   // +0x98 slot index -> gem type
};
MS2_CHECK_SIZE(GemSlotBag, 0xe0);
MS2_CHECK_OFFSET(GemSlotBag, m_spPC, 0x88);
MS2_CHECK_OFFSET(GemSlotBag, m_mapSlot, 0x98);
