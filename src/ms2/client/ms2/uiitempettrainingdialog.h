// uiitempettrainingdialog.h - UIItemPetTrainingDialog (RTTI .?AVUIItemPetTrainingDialog@@, 0x1b8 bytes, UIDialog, UI id
// 0x4f12, swf "ItemPetTrainingDialog"): the pet training box. The training item (a box from the inventory)
// is bound by uid; a pet dragged into the item scroll slot ("<name>.slot") is checked and shown with its exp. Owning
// unit: ?\uiitempettrainingdialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class CInPacket;
class ItemScrollSlot;
class DragSlot;
class Unk_PetRow;

class UIItemPetTrainingDialog : public UIDialog
{
public:
    UIItemPetTrainingDialog();                                  // 0x140e56eb0
    virtual ~UIItemPetTrainingDialog();                         //  0 0x140e57030 (??_G 0x140e59610)
    virtual CString vfunc_1();                                  //  1 0x140e57150 "ItemPetTrainingDialog"
    virtual void OnLoadComplete();                              // 22 0x140e571a0 bind the slot, show the training item
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140e577c0 onClickConfirm
    virtual int vfunc_48() { return 0x4f12; }                   // 48 0x140e59650
    virtual int vfunc_65();                                     // 65 0x140e57bb0
    virtual void vfunc_67();                                    // 67 0x140e57bd0 close: forget the items

    void SetOwner(unsigned __int64 nOwner);                // 0x140e57c80 the uid of the training item
    void FUN_140e57cb0(CInPacket& packet);                      // 0x140e57cb0 packet 0xcc: training done
    void FUN_140e57d60();                                       // 0x140e57d60 ask the server to train the pet
    ItemScrollSlot* FUN_140e57e50(CString strName);             // 0x140e57e50 the scroll slot of a name
    int FUN_140e57ed0(MS2Ptr<CItem> spPet, int bMessage);       // 0x140e57ed0 can this pet be trained
    void FUN_140e58280(ItemScrollSlot& slot);                  // 0x140e58280 the pet was removed from the slot
    void FUN_140e58300(ItemScrollSlot& slot, DragSlot* pDrag); // 0x140e58300 a pet was dropped onto the slot

private:
    MS2_LAYOUT_FRIEND;
    CString m_strSlot;                                          // +0x178 "<name>.slot"
    unsigned __int64 m_nOwner;                                  // +0x180 uid of the training item
    MS2Ptr<CItem> m_spBox;                                      // +0x188 the training item
    MS2Ptr<CItem> m_spPet;                                      // +0x198 the pet in the slot
    __int64 m_nOffsetExp;                                       // +0x1a8 "offsetExp" of the training item
    int m_bDone;                                                // +0x1b0 training finished
};
MS2_CHECK_SIZE(UIItemPetTrainingDialog, 0x1b8);
MS2_CHECK_OFFSET(UIItemPetTrainingDialog, m_strSlot, 0x178);
MS2_CHECK_OFFSET(UIItemPetTrainingDialog, m_nOwner, 0x180);
MS2_CHECK_OFFSET(UIItemPetTrainingDialog, m_spBox, 0x188);
MS2_CHECK_OFFSET(UIItemPetTrainingDialog, m_spPet, 0x198);
MS2_CHECK_OFFSET(UIItemPetTrainingDialog, m_nOffsetExp, 0x1a8);
MS2_CHECK_OFFSET(UIItemPetTrainingDialog, m_bDone, 0x1b0);
