// uiitemrepackingscrolldialog.h - UIItemRePackingScrollDialog (RTTI .?AVUIItemRePackingScrollDialog@@, 0x198 bytes,
// UIDialog, UI id 0x4f11, swf "ItemRePackingScrollDialog"): the repacking scroll box. The scroll (an inventory item,
// bound by uid) is shown with its limits; an item dragged into the item scroll slot ("<name>.slot") is validated
// against the scroll's row and on confirm the server is asked (packet 0x8c). Packet 0xe4 (the result) is handled
// through a delegate registered in the ctor. Owning unit: ?\uiitemrepackingscrolldialog.cpp. Header name assumed from
// the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class CItemData;
class ASTextField;
class Unk_RpRow;
class CInPacket;
class ItemScrollSlot;
class DragSlot;

class UIItemRePackingScrollDialog : public UIDialog
{
public:
    UIItemRePackingScrollDialog();                              // 0x140f60e00
    virtual ~UIItemRePackingScrollDialog();                     //  0 0x140f60f50 (??_G 0x140f64110)
    virtual CString GetTypeName();                                  //  1 0x140f61050 "ItemRePackingScrollDialog"
    virtual void OnLoadComplete();                              // 22 0x140f610a0 bind the slot, show the scroll
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140f61b60 onRePacking
    virtual int vfunc_48();                                     // 48 0x140f64160
    virtual int vfunc_65();                                     // 65 0x140f61e70
    virtual void vfunc_67();                                    // 67 0x140f61ea0 close: forget the items
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140f61f20 message box answers

    void FUN_140f62020(CInPacket& packet);                      // 0x140f62020 packet 0xe4: result
    void FUN_140f62200(CInPacket& packet);                      // 0x140f62200 result 2: success
    void FUN_140f625e0(CInPacket& packet);                      // 0x140f625e0 result 3: error code
    void FUN_140f62710(int nError);                             // 0x140f62710 error code -> message
    void FUN_140f628d0(MS2Ptr<CItem> spItem);                   // 0x140f628d0 forget an item's lock
    ItemScrollSlot* FUN_140f62930(CString strName);             // 0x140f62930 the scroll slot of a name
    MS2Ptr<Unk_RpRow> FUN_140f62a90(MS2Ptr<CItemData> spData);   // 0x140f62a90 the scroll row of an item's data
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // 0x140bb4cf0 text field child lookup (a UIDialog member)
    bool FUN_140f629b0(MS2Ptr<CItem> spItem);                   // 0x140f629b0 put an item in the slot
    void FUN_140f62b70(ItemScrollSlot& slot);                   // 0x140f62b70 the item was removed from the slot
    void FUN_140f62be0(ItemScrollSlot& slot, DragSlot* pDrag);  // 0x140f62be0 an item was dropped onto the slot

private:
    MS2_LAYOUT_FRIEND;
    CString m_strSlot;                                          // +0x178 "<name>.slot"
    unsigned __int64 m_nOwner;                                  // +0x180 uid of the scroll
    MS2Ptr<CItem> m_spItem;                                     // +0x188 the item in the slot
};
MS2_CHECK_SIZE(UIItemRePackingScrollDialog, 0x198);
MS2_CHECK_OFFSET(UIItemRePackingScrollDialog, m_strSlot, 0x178);
MS2_CHECK_OFFSET(UIItemRePackingScrollDialog, m_nOwner, 0x180);
MS2_CHECK_OFFSET(UIItemRePackingScrollDialog, m_spItem, 0x188);
