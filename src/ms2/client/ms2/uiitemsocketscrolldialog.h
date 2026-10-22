// uiitemsocketscrolldialog.h - UIItemSocketScrollDialog (RTTI .?AVUIItemSocketScrollDialog@@, 0x1a8 bytes, UIDialog, UI id
// 0x4f10, swf "ItemSocketScrollDialog"): the socket unlock scroll box. The scroll (an item from the inventory) is bound by
// uid; an equipment dragged into the item scroll slot ("<name>.slot") is checked against the scroll's table row
// (itemSocketScroll.xml) and shown with its success probability. "onClickAction" sends packet 0x8b (target uid, scroll
// uid); packet 0xe3 is the answer (0 = the scroll was opened for a uid, 2 = used, 3 = error code). Owning unit:
// ?\uiitemsocketscrolldialog.cpp. Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemsocketscrolldata.h"

class CItem;
class CItemData;
class CInPacket;
class CMsgBoxData;
class ItemScrollSlot;
class DragSlot;

class UIItemSocketScrollDialog : public UIDialog
{
public:
    UIItemSocketScrollDialog();                                 // 0x140f64630
    virtual ~UIItemSocketScrollDialog();                        //  0 0x140f64840 (??_G 0x140f68860)
    virtual CString vfunc_1();                                  //  1 0x140f64940 "ItemSocketScrollDialog"
    virtual void OnLoadComplete();                              // 22 0x140f64ac0 bind the slot, show the scroll
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140f65030 onClickAction
    virtual int vfunc_48();                                     // 48 0x140f688b0
    virtual void vfunc_67();                                    // 67 0x140f64990 close: forget the items

    void FUN_140f64a20(CInPacket& packet);                      // 0x140f64a20 packet 0xe3
    void FUN_140f650a0(ItemScrollSlot& slot);                   // 0x140f650a0 the item was removed from the slot
    void FUN_140f65130(ItemScrollSlot& slot, DragSlot* pDrag);  // 0x140f65130 an item was dropped onto the slot
    bool FUN_140f659e0(int nButton, const CMsgBoxData& box);    // 0x140f659e0 "used" box answered: close
    bool FUN_140f65a40(int nButton, const CMsgBoxData& box);    // 0x140f65a40 "unlock more" box answered: send
    void SetHasItem(int bHasItem);                           // 0x140f65a90
    ItemScrollSlot* FUN_140f65ab0(CString strName);             // 0x140f65ab0 the scroll slot of a name
    CItemSocketScrollDataPtr FUN_140f65b30(MS2Ptr<CItemData> spData);   // 0x140f65b30 the table row of a scroll
    bool FUN_140f65c10(CItemSocketScrollDataPtr spRow, CStringW& strNotice);    // 0x140f65c10 the limit text
    bool FUN_140f66680(MS2Ptr<CItem> spItem, CItemSocketScrollDataPtr spRow, CStringW& strDesc);   // 0x140f66680 the description
    void OnClickAction();                                       // 0x140f66870 onClickAction
    void FUN_140f66f70(int nError);                             // 0x140f66f70 notice for a check error
    void SendItemSocketScroll(__int64 nTargetUid);                     // 0x140f670e0 send packet 0x8b
    void FUN_140f67170(CInPacket& packet);                      // 0x140f67170 packet type 0: a scroll was opened
    void FUN_140f672a0(CInPacket& packet);                      // 0x140f672a0 packet type 2: the scroll was used
    void FUN_140f67650(CInPacket& packet);                      // 0x140f67650 packet type 3: error code

private:
    MS2_LAYOUT_FRIEND;
    CString m_strSlot;                                          // +0x178 "<name>.slot"
    unsigned __int64 m_nScrollUid;                              // +0x180 uid of the scroll
    MS2Ptr<CItem> m_spItem;                                     // +0x188 the equipment in the slot
    int m_bHasItem;                                             // +0x198
    unsigned m_nProb;                                           // +0x19c success probability in percent
    unsigned m_nCount;                                          // +0x1a0 sockets to open
    int m_pad_1a4;
};
MS2_CHECK_SIZE(UIItemSocketScrollDialog, 0x1a8);
MS2_CHECK_OFFSET(UIItemSocketScrollDialog, m_strSlot, 0x178);
MS2_CHECK_OFFSET(UIItemSocketScrollDialog, m_nScrollUid, 0x180);
MS2_CHECK_OFFSET(UIItemSocketScrollDialog, m_spItem, 0x188);
MS2_CHECK_OFFSET(UIItemSocketScrollDialog, m_bHasItem, 0x198);
MS2_CHECK_OFFSET(UIItemSocketScrollDialog, m_nProb, 0x19c);
MS2_CHECK_OFFSET(UIItemSocketScrollDialog, m_nCount, 0x1a0);
