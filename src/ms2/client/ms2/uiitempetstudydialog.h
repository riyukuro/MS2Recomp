// uiitempetstudydialog.h - UIItemPetStudyDialog (RTTI .?AVUIItemPetStudyDialog@@, 0x1b0 bytes, UIDialog, UI id
// 0x4f13, swf "ItemPetStudyDialog"): the pet study box. The study scroll (an
// item from the inventory) is bound by uid; a pet dragged into the item scroll slot ("<name>.slot") is checked and shown.
// Packet 0xcc (study finished) is handled through a delegate registered in the ctor. Owning unit:
// ?\uiitempetstudydialog.cpp. Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class CInPacket;
class ItemScrollSlot;
class DragSlot;

class UIItemPetStudyDialog : public UIDialog
{
public:
    UIItemPetStudyDialog();                                     // 0x140e54b60
    virtual ~UIItemPetStudyDialog();                            //  0 0x140e54cd0 (??_G 0x140e56ac0)
    virtual CString vfunc_1();                                  //  1 0x140e54df0 "ItemPetStudyDialog"
    virtual void OnLoadComplete();                              // 22 0x140e54e40 bind the slot, show the scroll
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140e55340 onClickConfirm
    virtual int vfunc_48();                                     // 48 0x140e56b00
    virtual int vfunc_65();                                     // 65 0x140e55730
    virtual void vfunc_67();                                    // 67 0x140e55750 close: forget the items

    void SetOwner(unsigned __int64 nOwner);                // 0x140e557f0 the uid of the study scroll
    void FUN_140e55820(CInPacket& packet);                      // 0x140e55820 packet 0xcc: study done
    void FUN_140e558d0();                                       // 0x140e558d0 ask the server to study
    ItemScrollSlot* FUN_140e559c0(CString strName);             // 0x140e559c0 the scroll slot of a name
    int FUN_140e55a40(MS2Ptr<CItem> spPet, int bMessage);       // 0x140e55a40 can this pet study the scroll
    void FUN_140e55f10(ItemScrollSlot& slot);                  // 0x140e55f10 the pet was removed from the slot
    void FUN_140e55f90(ItemScrollSlot& slot, DragSlot* pDrag); // 0x140e55f90 a pet was dropped onto the slot

private:
    MS2_LAYOUT_FRIEND;
    CString m_strSlot;                                          // +0x178 "<name>.slot"
    unsigned __int64 m_nOwner;                                  // +0x180 uid of the study scroll
    MS2Ptr<CItem> m_spBox;                                      // +0x188 the study scroll
    MS2Ptr<CItem> m_spPet;                                      // +0x198 the pet in the slot
    int m_bDone;                                                // +0x1a8 study finished
    int m_pad_1ac;
};
MS2_CHECK_SIZE(UIItemPetStudyDialog, 0x1b0);
MS2_CHECK_OFFSET(UIItemPetStudyDialog, m_strSlot, 0x178);
MS2_CHECK_OFFSET(UIItemPetStudyDialog, m_nOwner, 0x180);
MS2_CHECK_OFFSET(UIItemPetStudyDialog, m_spBox, 0x188);
MS2_CHECK_OFFSET(UIItemPetStudyDialog, m_spPet, 0x198);
MS2_CHECK_OFFSET(UIItemPetStudyDialog, m_bDone, 0x1a8);
