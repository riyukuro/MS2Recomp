// uiitemextractionscrolldialog.h - UIItemExtractionScrollDialog (RTTI .?AVUIItemExtractionScrollDialog@@, 0x190 bytes,
// UIDialog, UI id 0x4f49, swf "ItemExtractionScrollDialog"): the window where an item's extraction scroll is used. The
// player drops the item on the first slot of the bag (Slot::vfunc_18 -> FUN_140e4a920), the dialog looks up the
// extraction table row of the item, shows the result item and the scroll that is consumed, and on "onOk" asks for
// confirmation (message box) before packet 0xa0 is sent. Slot (0xa8, ids 0x620007a) and SlotBag (0xa8, 0x620007b) are the
// nested slot classes of the bag control. Owning unit: ?\uiitemextractionscrolldialog.cpp. Header name assumed from the
// unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;
class CMsgBoxData;

class UIItemExtractionScrollDialog : public UIDialog
{
public:
    // 0xa8 bytes. vftable (26 slots, ??_G 0x140e4ba70 sized delete 0xa8), ITooltip @+0x78. Shows one item (m_spItem).
    class Slot : public MS2DragSlot
    {
    public:
        Slot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem);     // 0x140e497d0
        virtual ~Slot();                                // 0x140e49870

        // slots 2-4: GetClassDesc 0x140e4bb70, TypeCast 0x140e4bcb0 / 0x140e4bd00; ms_ClassInfo 0x143ac5e80,
        // SetupClassInfo 0x140e4bbf0 (parent MS2DragSlot, id 0x620007a).
        EE_DECLARE_CLASS1(Slot, 0x0620007A, MS2DragSlot);
    public:
        virtual int vfunc_8(void* p);                   // 8  0x140e49aa0 build the item slot into p
        virtual int vfunc_13();                         // 13 0x140e498c0 return 0
        virtual int vfunc_14();                         // 14 0x140e498d0 vfunc_11()
        virtual int vfunc_18(void* p);                  // 18 0x140e49900 an item was dropped on the slot
        virtual int vfunc_0(void* p);                   // ITooltip 0x140e499a0 build the tooltip into p

        MS2_LAYOUT_FRIEND;
        MS2Ptr<CItem> m_spItem;                         // +0x90
        int m_nFlags;                                   // +0xa0 tooltip flags (0x20)
        int m_pad_a4;
    };

    // 0xa8 bytes. vftable (16 slots, ??_G 0x140e4bad0 sized delete 0xa8).
    class SlotBag : public DragSlotBag
    {
    public:
        SlotBag(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items);   // 0x140e49ca0
        virtual ~SlotBag();                             // 0x140e49d20

        // slots 2-4: GetClassDesc 0x140e4bb80, TypeCast 0x140e4bd50 / 0x140e4bda0; ms_ClassInfo 0x143ac6290,
        // SetupClassInfo 0x140e4bc50 (parent DragSlotBag, id 0x620007b).
        EE_DECLARE_CLASS1(SlotBag, 0x0620007B, DragSlotBag);
    public:
        virtual DragSlot* vfunc_16(int nIndex);         // 16 0x140e49d60 new Slot holding the item at nIndex

        MS2_LAYOUT_FRIEND;
        ATL::CAtlArray<MS2Ptr<CItem> > m_items;         // +0x88 the items shown (target, scroll)
    };

    UIItemExtractionScrollDialog();                                 // 0x140e49ec0
    virtual ~UIItemExtractionScrollDialog() = default;              //  0 0x140e4b9c0 (the exe's dtor writes no vptr; ??_G 0x140e4bb30)
    virtual CString vfunc_1();                                      //  1 0x140e49f70 "ItemExtractionScrollDialog"
    virtual void OnLoadComplete();                                  // 22 0x140e4a580
    virtual void vfunc_26();                                        // 26 0x140e4a550
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x140e4a8b0 onOk
    virtual int vfunc_48() { return 0x4f49; }                       // 48 0x140e4bb90
    virtual void vfunc_67();                                        // 67 0x140e49fc0 close: drop the bag
    virtual void vfunc_79(void* pPacket);                           // 79 0x140e4a010 the result packet

    bool SendItemExtractionScroll(int nResult, const CMsgBoxData& box);        // 0x140e4a4b0 the confirmation was answered: send 0xa0
    void FUN_140e4a920(__int64 nItemUid);                           // 0x140e4a920 an item was dropped: show it and the scroll
    void FUN_140e4b2c0(__int64 nScrollUid);                         // 0x140e4b2c0 remember the scroll if the player owns it
    void FUN_140e4b340();                                           // 0x140e4b340 refresh the inventory dialog
    void OnOk();                                           // 0x140e4b380 ask for the confirmation
    void FUN_140e4b640(MS2Ptr<CItem> spTarget, MS2Ptr<CItem> spScroll);   // 0x140e4b640 rebuild the bag

private:
    MS2_LAYOUT_FRIEND;
    CString m_strBag;                                               // +0x178 name of the bag control (the class name)
    __int64 m_nScrollUid;                                           // +0x180 uid of the scroll
    __int64 m_nTargetUid;                                           // +0x188 uid of the item to extract
};
MS2_CHECK_SIZE(UIItemExtractionScrollDialog, 0x190);
MS2_CHECK_OFFSET(UIItemExtractionScrollDialog, m_strBag, 0x178);
MS2_CHECK_OFFSET(UIItemExtractionScrollDialog, m_nScrollUid, 0x180);
MS2_CHECK_OFFSET(UIItemExtractionScrollDialog, m_nTargetUid, 0x188);
MS2_CHECK_SIZE(UIItemExtractionScrollDialog::Slot, 0xa8);
MS2_CHECK_SIZE(UIItemExtractionScrollDialog::SlotBag, 0xa8);
