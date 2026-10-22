// uiitemautouseoptiondialog.h - UIItemAutoUseOptionDialog (RTTI .?AVUIItemAutoUseOptionDialog@@, 0x1a8 bytes, UIDialog +
// UIStatusEventListener at +0x178, UI id 0x4ef4, swf "ItemAutoUseOptionDialog"): the pet auto-use settings window. The
// window lists DAT_1439ed000 rows; each row is a slot (holds the item id to use, dropped from the pet or the main
// inventory) and a drop-down with the hp threshold (0, 10, 20, ... percent, the last entry = off). "OnClickOk" packs the
// rows into the pet option map (CPetManager info +0x68, key = row index; type = drop-down index, value = threshold,
// 3rd = item id) and sends packet 0x78 / 5. Slot (0x98, ids 0x6200068) and SlotBag (0x88, 0x6200069) are the nested
// slot classes of the "m_itemBag"-like control (bound under the dialog's m_strBag = the class name). Owning unit:
// ?\uiitemautouseoptiondialog.cpp. Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/client/ms2/ms2dragslot.h"

class UIItemAutoUseOptionDialog : public UIDialog, public UIStatusEventListener
{
public:
    // 0x98 bytes. vftable (26 slots, ??_G 0x140f508a0 sized delete 0x98), ITooltip @+0x78. Holds the item id to use.
    class Slot : public MS2DragSlot
    {
    public:
        Slot(const CString& strName, int nIndex, int nItemId);  // 0x140f4dfd0
        virtual ~Slot();                                // 0x140f4e040

        // slots 2-4: GetClassDesc 0x140f509a0, TypeCast 0x140f50b00 / 0x140f50b50; ms_ClassInfo 0x143acaa80,
        // SetupClassInfo 0x140f50a40 (parent MS2DragSlot, id 0x6200068).
        EE_DECLARE_CLASS1(Slot, 0x06200068, MS2DragSlot);
    public:
        virtual void vfunc_6(void* p) override;         // 6  0x140f4e210 the item id as text
        virtual int vfunc_8(void* p) override;          // 8  0x140f4ee10 build the item slot into p
        virtual int vfunc_11() override;                // 11 0x140f4e280 clear the item id
        virtual int vfunc_13() override;                // 13 0x140f4e2f0 return 0
        virtual int vfunc_14() override;                // 14 0x140f4e300 remove the item
        virtual int vfunc_15() override;                // 15 0x140f4e340
        virtual int vfunc_17() override;                // 17 0x140f4e3e0 vfunc_11()
        virtual int vfunc_18(void* p) override;         // 18 0x140f4e410 an item was dropped on the slot
        virtual void vfunc_23(void* p) override;        // 23 0x140f4eb30
        virtual void vfunc_24(void* p) override;        // 24 0x140f4eb80
        virtual int vfunc_0(void* p) override;          // ITooltip 0x140f4ebd0 build the tooltip into p

        float FUN_140f4e080();                          // cooldown left of the item's skill (0: no player)
        int FUN_140f4e0e0();                            // item type of the item (0: none)
        int FUN_140f4e180();                            // return m_nItemId
        void FUN_140f4e1a0(int nItemId);                // m_nItemId = nItemId
        int FUN_140f4e1c0(int nItemId);                 // the item id is already in a slot of the open window
        void FUN_140f4f030(int nOtherIndex);            // swap the option rows of this slot and nOtherIndex
        void FUN_140f4f100(int nState);                 // set the state of this row's drop-down

    public:
        MS2_LAYOUT_FRIEND;
        int m_nItemId;                                  // +0x90 item id to use (0: empty)
        int m_pad_94;
    };

    // 0x88 bytes. vftable (17 slots, ??_G 0x140f50900 sized delete 0x88).
    class SlotBag : public DragSlotBag
    {
    public:
        explicit SlotBag(const CString& strName);       // 0x140f4f260
        virtual ~SlotBag();                             // 0x140f4f2a0

        // slots 2-4: GetClassDesc 0x140f509b0, TypeCast 0x140f50ba0 / 0x140f50bf0; ms_ClassInfo 0x143acae90,
        // SetupClassInfo 0x140f50aa0 (parent DragSlotBag, id 0x6200069).
        EE_DECLARE_CLASS1(SlotBag, 0x06200069, DragSlotBag);
    public:
        virtual DragSlot* vfunc_16(int nIndex) override;    // 16 0x140f4f2d0 new Slot with the saved item id of the row
    };

    UIItemAutoUseOptionDialog();                                    // 0x140f4f460
    virtual ~UIItemAutoUseOptionDialog();                           //  0 0x140f4f560 (??_G 0x140f50960)
    virtual CString vfunc_1();                                      //  1 0x140f4f5f0 "ItemAutoUseOptionDialog"
    virtual void OnLoadComplete();                                  // 22 0x140f4f710
    virtual void vfunc_15();                                        // 15 0x140f4f990
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f4f9c0 OnClickOk
    virtual int vfunc_48() { return 0x4ef4; }                       // 48 0x140f509c0
    virtual int vfunc_65();                                         // 65 0x140f4f640 open: register the listener
    virtual void vfunc_67();                                        // 67 0x140f4f6a0 close: drop the bag
    virtual void vfunc_oa0_25(void* p) override;                    // UIStatusEventListener 0x140f4fa30 -> bag slot 11
    virtual void vfunc_oa0_26(void* p) override;                    // 0x140f4fa90 -> bag slot 12

    int FUN_140f4faf0(int nItemId);                                 // 0x140f4faf0 the item id is in a row
    void FUN_140f4fc40(int nItemId);                                // 0x140f4fc40 put an item into a free row
    void FUN_140f50090(int nState, int nIndex);                     // 0x140f50090 enable / disable / reset a row's drop-down
    void FUN_140f50190();                                           // 0x140f50190 rebuild the bag, tell the movie
    void FUN_140f50230(void* pCombo, int nIndex);                   // 0x140f50230 fill a row's drop-down
    void OnClickOk();                                           // 0x140f50480 OnClickOk: validate and send

private:
    MS2_LAYOUT_FRIEND;
    CString m_strBag;                                               // +0x180 name of the bag control (the class name)
    ATL::CAtlArray<unsigned int> m_thresholds;                      // +0x188 hp thresholds of the drop-down (0, 10, 20, ...)
};
MS2_CHECK_SIZE(UIItemAutoUseOptionDialog, 0x1a8);
MS2_CHECK_OFFSET(UIItemAutoUseOptionDialog, m_strBag, 0x180);
MS2_CHECK_OFFSET(UIItemAutoUseOptionDialog, m_thresholds, 0x188);
MS2_CHECK_SIZE(UIItemAutoUseOptionDialog::Slot, 0x98);
MS2_CHECK_SIZE(UIItemAutoUseOptionDialog::SlotBag, 0x88);
