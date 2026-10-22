// petslot.h - PetSlot / PetSlotBag: the slots of the pet inventory window. A slot holds the uid of an item in the
// pet's own inventory (CPetInventory, looked up through the pet manager singleton); the bag creates the slots and
// listens for item events (UIItemEventListener at +0x88). Owning unit: client\ms2\petslot.cpp
// (0x140dbad20-0x140dbcbc0). Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener

class CItem;

// 0xa0 bytes. vftable (26 slots, sized delete 0xa0), ITooltip @+0x78, UIQuestEventListener @+0x90 (registered with
// the quest event dispatcher in the ctor; its slots 1, 2 and 5 re-check the item).
class PetSlot : public MS2DragSlot, public UIQuestEventListener
{
public:
    PetSlot(const CString& strName, int nIndex, unsigned __int64 nPetItemUid);   // 0x140dbad20
    virtual ~PetSlot();                                 // 0x140dbae00 (scalar deleting dtor 0x140dbc130)

    // slots 2-4: GetClassDesc 0x140dbc190, TypeCast 0x140dbc2d0 / 0x140dbc320; ms_ClassInfo 0x143ac3f70,
    // SetupClassInfo 0x140dbc270 (parent MS2DragSlot, id 0x6200067).
    EE_DECLARE_CLASS1(PetSlot, 0x06200067, MS2DragSlot);
public:
    virtual void vfunc_6(void* p) override;             // 6  0x140dbb0b0 fill the slot's gfx data
    virtual int vfunc_8(void* p);                       // 8  0x140dbbda0 build the item slot into p
    virtual int vfunc_11() override;                    // 11 0x140dbb1d0 clear the item uid
    virtual int vfunc_13() override;                    // 13 0x140dbb240
    virtual int vfunc_14() override;                    // 14 0x140dbb340 take the item out of / put it into the pet inventory
    virtual int vfunc_15() override;                    // 15 0x140dbb4f0
    virtual int vfunc_17() override;                    // 17 0x140dbb590
    virtual int vfunc_18(void* p) override;             // 18 0x140dbb5c0 an item was dropped on the slot
    virtual void vfunc_23(void* p) override;            // 23 0x140dbbee0
    virtual void vfunc_24(void* p) override;            // 24 0x140dbbf30
    virtual MS2Ptr<CItem> vfunc_25() override;          // 25 0x140dbb7e0 the pet item in the slot
    virtual int vfunc_0(void* p) override;              // ITooltip 0x140dbb860 build the tooltip into p
    virtual void vfunc_o178_1(void* p) override;        // UIQuestEventListener 0x140dbbfb0
    virtual void vfunc_o178_2(void* p) override;        // 0x140dbbf80
    virtual void vfunc_o178_5(void* p) override;        // 0x140dbbfe0

    float FUN_140dbaeb0();                              // cooldown left of the item's skill (0: no player)
    int FUN_140dbaf10();                                // item type of the pet item (0: gone)
    int FUN_140dbafc0();                                // item id of the pet item (0: gone)
    unsigned __int64 GetPetItemUid();                   // return m_nPetItemUid
    void SetPetItemUid(unsigned __int64 nUid);          // m_nPetItemUid = nUid
    void FUN_140dbc010();                               // re-check the item (the listener slots)

public:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_nPetItemUid;                     // +0x98
};
MS2_CHECK_SIZE(PetSlot, 0xa0);
MS2_CHECK_OFFSET(PetSlot, m_nPetItemUid, 0x98);

// 0x90 bytes. vftable (17 slots), UIItemEventListener @+0x88.
class PetSlotBag : public DragSlotBag, public UIItemEventListener
{
public:
    explicit PetSlotBag(const CString& strName);        // 0x140dbc470
    virtual ~PetSlotBag();                              // 0x140dbc520 (scalar deleting dtor 0x140dbca50)

    // slots 2-4: GetClassDesc 0x140dbcab0, TypeCast 0x140dbcb20 / 0x140dbcb70; ms_ClassInfo 0x143ac43c0,
    // SetupClassInfo 0x140dbcac0 (parent DragSlotBag, id 0x6200066).
    EE_DECLARE_CLASS1(PetSlotBag, 0x06200066, DragSlotBag);
public:
    virtual DragSlot* vfunc_16(int nIndex) override;    // 16 0x140dbc7d0 new PetSlot for the nIndex-th pet item
    virtual int vfunc_il1() override;                   // UIItemEventListener 0x140dbc5c0
    virtual void vfunc_il6(void* p) override;           // 0x140dbc610
    virtual void vfunc_il7(void* p) override;           // 0x140dbc6b0
    virtual void vfunc_il8(void* p) override;           // 0x140dbc730

    unsigned __int64 FUN_140dbc8b0(int nIndex);         // uid of the pet item in slot nIndex (0: none)

public:
    MS2_LAYOUT_FRIEND;
};
MS2_CHECK_SIZE(PetSlotBag, 0x90);
