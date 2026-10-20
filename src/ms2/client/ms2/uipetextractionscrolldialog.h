// uipetextractionscrolldialog.h - UIPetExtractionScrollDialog (RTTI .?AVUIPetExtractionScrollDialog@@, 0x190 bytes,
// UIDialog, UI id 0x4f4a, swf "PetExtractionScrollDialog"): the window where a pet extraction scroll turns a pet into a pet
// skin gem. The item use handler (unit_140d1ae30.cpp, "PetExtraction") remembers the scroll (FUN_140e72860); the player
// drops the pet on the first slot of the bag (Slot::vfunc_18 -> FUN_140e71d40), the dialog builds the result gem item
// (the gemPetSkinBaseItemID constant, its CGemPetSkin set to the pet id) and on "onOk" asks for confirmation before the
// scroll is used with the pet uid as the argument. Result packet 0x108. Slot (0xa8, id 0x620007a) and SlotBag (0xa8,
// 0x620007b) are the nested slot classes of the bag control. Recovered with the queue unit ?\uiotherpetsystemdialog.cpp
// (TU 0x140e70aa0-0x140e733a0); header name assumed; the layout mirrors UIItemExtractionScrollDialog.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;
class CMsgBoxData;

class UIPetExtractionScrollDialog : public UIDialog
{
public:
    // 0xa8 bytes. ITooltip @+0x78 (??_G 0x140e72f30 sized delete 0xa8). Shows one item (m_spItem).
    class Slot : public MS2DragSlot
    {
    public:
        Slot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem);     // 0x140e70aa0
        virtual ~Slot();                                // 0x140e70b40

        // slots 2-4: GetClassDesc 0x140e73030, TypeCast 0x140e73120 / 0x140e73170; ms_ClassInfo 0x143ac70d0,
        // SetupClassInfo 0x140e73060 (parent MS2DragSlot, id 0x620007a).
        EE_DECLARE_CLASS1(Slot, 0x0620007A, MS2DragSlot);
    public:
        virtual int vfunc_8(void* p);                   // 8  0x140e70d70 build the item slot into p
        virtual int vfunc_13();                         // 13 0x140e70b90 return 0
        virtual int vfunc_14();                         // 14 0x140e70ba0 vfunc_11()
        virtual int vfunc_18(void* p);                  // 18 0x140e70bd0 an item was dropped on the slot
        virtual int vfunc_0(void* p);                   // ITooltip 0x140e70c70 build the tooltip into p

        MS2_LAYOUT_FRIEND;
        MS2Ptr<CItem> m_spItem;                         // +0x90
        int m_nFlags;                                   // +0xa0 tooltip flags (0x20)
        int m_pad_a4;
    };

    // 0xa8 bytes (??_G 0x140e72f90 sized delete 0xa8).
    class SlotBag : public DragSlotBag
    {
    public:
        SlotBag(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items);   // 0x140e70f70
        virtual ~SlotBag();                             // 0x140e70ff0

        // slots 2-4: GetClassDesc 0x140e73040, TypeCast 0x140e731c0 / 0x140e73210; ms_ClassInfo 0x143ac74e0,
        // SetupClassInfo 0x140e730c0 (parent DragSlotBag, id 0x620007b).
        EE_DECLARE_CLASS1(SlotBag, 0x0620007B, DragSlotBag);
    public:
        virtual DragSlot* vfunc_16(int nIndex);         // 16 0x140e71030 new Slot holding the item at nIndex

        MS2_LAYOUT_FRIEND;
        ATL::CAtlArray<MS2Ptr<CItem> > m_items;         // +0x88 the items shown (pet, result gem)
    };

    UIPetExtractionScrollDialog();                                  // 0x140e71190
    virtual ~UIPetExtractionScrollDialog() = default;               //  0 0x140e72ec0 (??_G 0x140e72ff0)
    virtual CString vfunc_1();                                      //  1 0x140e71240 "PetExtractionScrollDialog"
    virtual void OnLoadComplete();                                  // 22 0x140e719a0
    virtual void vfunc_26();                                        // 26 0x140e71970
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x140e71cd0 onOk
    virtual int vfunc_48() { return 0x4f4a; }                       // 48 0x140e73050
    virtual void vfunc_67();                                        // 67 0x140e71290 close: drop the bag
    virtual void vfunc_79(void* pPacket);                           // 79 0x140e712e0 the result packet

    bool FUN_140e71880(int nResult, const CMsgBoxData& box);        // 0x140e71880 the confirmation was answered: use the scroll
    void FUN_140e71d40(__int64 nItemUid);                           // 0x140e71d40 a pet was dropped: show it and the result
    void FUN_140e72860(__int64 nScrollUid);                         // 0x140e72860 remember the scroll if the player owns it
    void FUN_140e728e0();                                           // 0x140e728e0 refresh the inventory dialog
    void FUN_140e72920();                                           // 0x140e72920 ask for the confirmation
    void FUN_140e72b40(MS2Ptr<CItem> spTarget, MS2Ptr<CItem> spResult);   // 0x140e72b40 rebuild the bag

private:
    MS2_LAYOUT_FRIEND;
    CString m_strBag;                                               // +0x178 name of the bag control (the class name)
    __int64 m_nScrollUid;                                           // +0x180 uid of the scroll
    __int64 m_nTargetUid;                                           // +0x188 uid of the pet
};
MS2_CHECK_SIZE(UIPetExtractionScrollDialog, 0x190);
MS2_CHECK_OFFSET(UIPetExtractionScrollDialog, m_strBag, 0x178);
MS2_CHECK_OFFSET(UIPetExtractionScrollDialog, m_nScrollUid, 0x180);
MS2_CHECK_OFFSET(UIPetExtractionScrollDialog, m_nTargetUid, 0x188);
MS2_CHECK_SIZE(UIPetExtractionScrollDialog::Slot, 0xa8);
MS2_CHECK_SIZE(UIPetExtractionScrollDialog::SlotBag, 0xa8);
