// storeslot.h - StoreSlot / StoreSlotBag: the slots of the npc shop window. A slot holds the id of the store item
// (looked up through the store table DAT_143ab2d80) and implements buying / selling by drag & drop, the bag creates the
// slots and listens for item events (UIItemEventListener at +0x88). Owning unit: client\ms2\storeslot.cpp
// (0x141808730-0x14180bc20). Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener

class CItem;

// 0xa0 bytes. vftable (26 slots, sized delete 0xa0), ITooltip @+0x78, UIQuestEventListener @+0x90 (registered with
// the quest event dispatcher in the ctor; its slots 1, 2 and 5 re-check the store item).
class StoreSlot : public MS2DragSlot, public UIQuestEventListener
{
public:
    StoreSlot(const CString& strName, int nIndex, unsigned __int64 nStoreItemId);   // 0x141808730
    virtual ~StoreSlot();                               // 0x141808810 (scalar deleting dtor 0x14180b000)

    // slots 2-4: GetClassDesc 0x14180b060, TypeCast 0x14180b0d0 / 0x14180b120; ms_ClassInfo 0x143aee670,
    // SetupClassInfo 0x14180b070 (parent MS2DragSlot, id 0x6200033).
    EE_DECLARE_CLASS1(StoreSlot, 0x06200033, MS2DragSlot);
public:
    virtual void vfunc_6(void* p) override;             // 6  0x1418089a0 fill the slot's gfx data
    virtual int vfunc_8(void* p);                       // 8  0x14180ab10 build the item slot into p
    virtual int vfunc_11() override;                    // 11 0x141808d30 clear the store item id
    virtual int vfunc_13() override;                    // 13 0x141808d60 -> vfunc_14()
    virtual int vfunc_14() override;                    // 14 0x141808d90 buy / take the item
    virtual int vfunc_15() override;                    // 15 0x141809280
    virtual int vfunc_17() override;                    // 17 0x141809310
    virtual int vfunc_18(void* p) override;             // 18 0x141809460 an item was dropped on the slot
    virtual int vfunc_20() override;                    // 20 0x141809ba0
    virtual int vfunc_21() override;                    // 21 0x141809d10
    virtual CStringW vfunc_22() override;               // 22 0x14180ac70
    virtual void vfunc_23(void* p) override;            // 23 0x14180acb0
    virtual void vfunc_24(void* p) override;            // 24 0x14180ad00
    virtual MS2Ptr<CItem> vfunc_25() override;          // 25 0x141809b20 the store item in the slot
    virtual int vfunc_26(MS2Ptr<CItem> spItem);         // 26 0x141809ea0 can the item be sold into the store
    virtual int vfunc_0(void* p) override;              // ITooltip 0x14180a970 build the tooltip into p
    virtual void vfunc_o178_1(void* p) override;        // UIQuestEventListener 0x14180ad80
    virtual void vfunc_o178_2(void* p) override;        // 0x14180ad50
    virtual void vfunc_o178_5(void* p) override;        // 0x14180adb0

    void SetStoreItemId(unsigned __int64 nItemId);       // m_nStoreItemId = nItemId
    unsigned __int64 GetStoreItemId();                   // return m_nStoreItemId
    int FUN_141808910();                                // item type of the store item (0: gone)
    int FUN_141808b10(CStringW strSearch);              // slot index when the item name contains strSearch (-1: no)
    void FUN_14180ade0();                               // re-check the store item (the listener slots)
    bool FUN_14180aea0();

public:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_nStoreItemId;                    // +0x98
};
MS2_CHECK_SIZE(StoreSlot, 0xa0);
MS2_CHECK_OFFSET(StoreSlot, m_nStoreItemId, 0x98);

// 0x98 bytes. vftable (17 slots), UIItemEventListener @+0x88.
class StoreSlotBag : public DragSlotBag, public UIItemEventListener
{
public:
    StoreSlotBag(const CString& strName, int nStoreId);     // 0x14180b280
    virtual ~StoreSlotBag();                            // 0x14180b340 (scalar deleting dtor 0x14180b9a0)

    // slots 2-4: GetClassDesc 0x14180ba00, TypeCast 0x14180ba70 / 0x14180bac0; ms_ClassInfo 0x143aeeb20,
    // SetupClassInfo 0x14180ba10 (parent DragSlotBag).
    EE_DECLARE_CLASS1(StoreSlotBag, 0x06200032, DragSlotBag);
public:
    virtual DragSlot* vfunc_16(int nIndex) override;    // 16 0x14180b710 new StoreSlot for the nIndex-th store item
    virtual void vfunc_9(void* p) override;             // UIItemEventListener 0x14180b560
    virtual void vfunc_10(void* p) override;            // 0x14180b5e0
    virtual void vfunc_il11(void* p) override;          // 0x14180b640
    virtual void vfunc_12() override;                   // 0x14180b6c0

    int FUN_14180b3e0(CStringW strSearch);              // first slot index whose item name contains strSearch

public:
    MS2_LAYOUT_FRIEND;
    int m_nStoreId;                                     // +0x90
};
MS2_CHECK_SIZE(StoreSlotBag, 0x98);
MS2_CHECK_OFFSET(StoreSlotBag, m_nStoreId, 0x90);
