// invenslot.h - InvenSlot / InventorySlotBag: the item slots of the inventory window. A slot holds the uid of the
// inventory item it shows (looked up in the player's inventory DAT_143ab2a90); right click uses / equips / sells / trades
// the item depending on the dialog that is open, drag & drop moves it or drops it on another slot kind. The bag creates one
// slot per inventory position of its tab and listens for item and UGC events. Owning unit: ?\invenslot.cpp
// (0x1414043e0-0x14140ff10, .text$di 0x1400f5230). Header name assumed from the unit path; member names are invented
// from the use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener

class CItem;
class ASDataProvider;

// 0xa0 bytes. vftable 0x142f0eb08 (27 slots, ??_G 0x14140e960 sized delete 0xa0), ITooltip @+0x78 0x142f0ebe8,
// UIQuestEventListener @+0x90 0x142f0ebf8 (registered with the quest event dispatcher; slots 1, 2 and 5 re-check the item).
class InvenSlot : public MS2DragSlot, public UIQuestEventListener
{
public:
    InvenSlot(const CString& strName, int nIndex, __int64 nItemUid);   // 0x141405760
    virtual ~InvenSlot();                               // 0x141405840

    // slots 2-4: GetClassDesc 0x14140e9c0, TypeCast 0x14140eaf0 / 0x14140eb40; ms_ClassInfo 0x143ad9900,
    // SetupClassInfo 0x14140ea90 (parent MS2DragSlot, id 0x6200023).
    EE_DECLARE_CLASS1(InvenSlot, 0x06200023, MS2DragSlot);
public:
    virtual void vfunc_6(void* p) override;             // 6  0x141405cb0 fill the slot's gfx data (uid, item id, skill)
    virtual int vfunc_8(void* p) override;              // 8  0x14140ae90 build the item slot into p
    virtual int vfunc_11() override;                    // 11 0x141405eb0 clear the slot
    virtual int vfunc_13() override;                    // 13 0x141405f20 double click: use the item
    virtual int vfunc_14() override;                    // 14 0x141406a60 right click: the action of the open dialog
    virtual int vfunc_15() override;                    // 15 0x141407a20 item link
    virtual int vfunc_17() override;                    // 17 0x141407ab0 dropped outside: destroy / drop the item
    virtual int vfunc_18(void* p) override;             // 18 0x141407c80 something was dropped on the slot
    virtual int vfunc_20() override;                    // 20 0x141408cd0 drag start
    virtual int vfunc_21() override;                    // 21 0x141408ea0 drag end
    virtual CStringW vfunc_22() override;               // 22 0x14140b030 the right click hint
    virtual void vfunc_23(void* p) override;            // 23 0x14140b630 cooldown start
    virtual void vfunc_24(void* p) override;            // 24 0x14140b680 cooldown end
    virtual MS2Ptr<CItem> vfunc_25() override;          // 25 0x141408c50 the item in the slot
    virtual int vfunc_26(MS2Ptr<CItem> spItem);         // 26 0x1414092c0 may the item be destroyed (0: ask, 1: dropped)
    virtual int vfunc_0(void* p) override;              // ITooltip 0x14140a490 build the tooltip into p
    virtual void vfunc_o178_1(void* p) override;        // UIQuestEventListener 0x141405e50
    virtual void vfunc_o178_2(void* p) override;        // 0x141405e20
    virtual void vfunc_o178_5(void* p) override;        // 0x141405e80

    int FUN_1414058f0();                                // the skill of the item (0: none)
    int FUN_141405980();                                // the item id
    __int64 GetItemUid();                            // return m_nItemUid
    void SetItemUid(__int64 nItemUid);               // m_nItemUid = nItemUid
    bool FUN_141405a60(CItem* pItem, int nSlot);        // put the item on the fitting doll
    float FUN_141409060();                              // the cooldown left of the item's skill
    int FUN_1414090c0();                                // may the item be registered on the black market
    int FUN_141409150(CItem* pItem);
    int FUN_14140b6d0(MS2Ptr<CItem> spItem);            // put the item into the trade window
    int FUN_14140bc50(CStringW strSearch);              // slot index when the item name contains strSearch (-1: no)
    int FUN_14140be60(CItem* pItem);                    // sell the item to the npc shop
    CItem* FUN_14140c030(MS2Ptr<CItem> spItem);         // the worn item the item would replace
    void FUN_14140c100();                               // re-check the item (the quest listener slots)
    bool FUN_14140c180(MS2Ptr<CItem> spItem);           // the item matches the inventory search text
    int FUN_140d1c3a0(MS2Ptr<CItem> spItem);            // 0x140d1c3a0 (another unit) equip the item; notice 0x55 while its cooldown runs

public:
    MS2_LAYOUT_FRIEND;
    __int64 m_nItemUid;                                 // +0x98
};
MS2_CHECK_SIZE(InvenSlot, 0xa0);
MS2_CHECK_OFFSET(InvenSlot, m_nItemUid, 0x98);

// 0xa0 bytes. vftable 0x142f0eed8 (17 slots, ??_G 0x14140fd10 sized delete 0xa0), UIItemEventListener @+0x88
// 0x142f0ef68, UIUGCEventListener @+0x90 0x142f0f088.
class InventorySlotBag : public DragSlotBag, public UIItemEventListener, public UIUGCEventListener
{
public:
    InventorySlotBag(const CString& strName, int nTab); // 0x14140edb0
    virtual ~InventorySlotBag();                        // 0x14140eee0

    // slots 2-4: GetClassDesc 0x14140fd70, TypeCast 0x14140fde0 / 0x14140fe30; ms_ClassInfo 0x143ad9e20,
    // SetupClassInfo 0x14140fd80 (parent DragSlotBag, id 0x6200026).
    EE_DECLARE_CLASS1(InventorySlotBag, 0x06200026, DragSlotBag);
public:
    virtual DragSlot* vfunc_16(int nIndex) override;    // 16 0x14140f8a0 new InvenSlot for the nIndex-th position
    virtual int vfunc_il1() override;                   // UIItemEventListener 0x14140efe0 the inventory is open
    virtual void vfunc_2(void* p) override;             // 0x14140f140 item added
    virtual void vfunc_3(void* p, bool b) override;     // 0x14140f200 item removed
    virtual void vfunc_4(void* p, int n) override;      // 0x14140f2a0 item changed
    virtual void vfunc_5(void* p, int n) override;      // 0x14140f340 item moved
    virtual void vfunc_21(void* p) override;            // 0x14140f480
    virtual void vfunc_22(void* p) override;            // 0x14140f510
    virtual void vfunc_ugc_2(void* p, CString str) override;   // UIUGCEventListener 0x14140f030

    void FUN_14140f5b0(CItem* pItem);                   // refresh the slot of the item
    int FUN_14140f620(CStringW strSearch);              // the first slot whose item name contains strSearch
    ASDataProvider FUN_14140f7a0();                     // the slot names
    int FUN_14140f990(CItem* pItem);                    // the item is in the bag's tab

public:
    MS2_LAYOUT_FRIEND;
    int m_nTab;                                         // +0x98
    int m_nPendingSlot;                                 // +0x9c (-1)
};
MS2_CHECK_SIZE(InventorySlotBag, 0xa0);
MS2_CHECK_OFFSET(InventorySlotBag, m_nTab, 0x98);
MS2_CHECK_OFFSET(InventorySlotBag, m_nPendingSlot, 0x9c);

InventorySlotBag* FUN_14140eca0(const CString& strName, int nTab, int nCount);   // create and register the bag of a tab
void FUN_14140ed60(const CString& strName);                                       // destroy the bag registered under the name
