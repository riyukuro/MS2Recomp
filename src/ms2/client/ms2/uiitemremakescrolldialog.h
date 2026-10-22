// uiitemremakescrolldialog.h - UIItemRemakeScrollDialog (RTTI .?AVUIItemRemakeScrollDialog@@, 0x1d8 bytes, UIDialog, UI id
// 0x4f09, swf "ItemRemakeScrollDialog"): the option remake scroll box. The scroll (an inventory item, bound by uid) takes a
// target equipment (or pet) in the "<name>.slot" slot and, optionally, an ingredient in "targetIngredient.slot". The state
// machine (1 pick the target, 2 pick lock options, 3 choose between the current and the new options, 4 done) is driven by
// "onClickConfirm"; packet 0x76 asks the server, packet 0xc9 is the answer (type 0 = the scroll was opened for a uid,
// 2 = the new options, 3 = the options were applied, 4 = error code). Owning unit: ?\uiitemremakescrolldialog.cpp. Header name
// assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citemremakescrolldata.h"

class CItem;
class CItemData;
class CInPacket;
class CMsgBoxData;
class ASData;
class ItemScrollSlot;
class DragSlot;

class UIItemRemakeScrollDialog : public UIDialog
{
public:
    UIItemRemakeScrollDialog();                                 // 0x140f58080
    virtual ~UIItemRemakeScrollDialog();                        //  0 0x140f58290 (??_G 0x140f607b0)
    virtual CString GetTypeName();                                  //  1 0x140f583e0 "ItemRemakeScrollDialog"
    virtual void OnLoadComplete();                              // 22 0x140f58430 bind the slots, show the scroll
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140f58dd0 onClickConfirm / GetEnableLockOption
    virtual int vfunc_48();                                     // 48 0x140f607f0
    virtual int vfunc_65();                                     // 65 0x140f58f10
    virtual void vfunc_67();                                    // 67 0x140f58f40 close: forget the items
    virtual int vfunc_71();                                     // 71 0x140f59070 ask before closing in state 3

    void FUN_140f59230(CInPacket& packet);                      // 0x140f59230 packet 0xc9
    void FUN_140f59420(unsigned __int64 nOptionUid, int nUnk);  // 0x140f59420 remake clicked: ask for confirmation
    void FUN_140f59ad0(unsigned __int64 nOptionUid, int nUnk);  // 0x140f59ad0 send the remake request (packet 0x76, kind 1)
    void FUN_140f5a7e0(CInPacket& packet);                      // 0x140f5a7e0 packet type 2: the new options
    void FUN_140f5a9c0(CInPacket& packet);                      // 0x140f5a9c0 packet type 3: the options were applied
    void FUN_140f5ab10(CInPacket& packet);                      // 0x140f5ab10 packet type 4: error code
    void FUN_140f5acf0(ASData& data);                           // 0x140f5acf0 onClickConfirm by state
    void FUN_140f5adb0();                                       // 0x140f5adb0 state 1: go to the lock option choice
    void FUN_140f5ae60();                                       // 0x140f5ae60 state 2: ask for the lock option
    void FUN_140f5b670(ASData& data);                           // 0x140f5b670 state 3: apply the selected option
    void FUN_140f5bb20();                                       // 0x140f5bb20 state 4: open the dialog again
    void FUN_140f5bb60();                                       // 0x140f5bb60 state 4: restart
    void FUN_140f5bbb0(ASData& data);                           // 0x140f5bbb0 GetEnableLockOption
    void FUN_140f5c2e0();                                       // 0x140f5c2e0 "restart"
    void FUN_140f5c340();                                       // 0x140f5c340 "showOption"
    void FUN_140f5c700();                                       // 0x140f5c700 "selectOption"
    void FUN_140f5cba0(MS2Ptr<CItem> spItem);                   // 0x140f5cba0 "complete"
    void FUN_140f5d020(MS2Ptr<CItem> spItem);                   // 0x140f5d020 forget an item's lock
    void SetState(int nState);                             // 0x140f5d080 set the state
    int GetState();                                        // 0x140f5d0a0 the state
    ItemScrollSlot* FUN_140f5d0c0(CString strName);             // 0x140f5d0c0 the scroll slot of a name
    bool FUN_140f5d140(MS2Ptr<CItem> spItem);                   // 0x140f5d140 put an item in the target slot
    bool FUN_140f5d220(MS2Ptr<CItem> spItem);                   // 0x140f5d220 put an item in the ingredient slot
    MS2Ptr<CItemRemakeScrollData> FUN_140f5d380(MS2Ptr<CItemData> spData);  // 0x140f5d380 the table row of a scroll
    bool FUN_140f5d460(MS2Ptr<CItemRemakeScrollData> spRow, CStringW& strNotice);   // 0x140f5d460 the limit text
    bool FUN_140f5dd50(MS2Ptr<CItem> spItem, MS2Ptr<CItemRemakeScrollData> spRow, CStringW& strDesc);   // 0x140f5dd50 the description
    void FUN_140f5e1f0(int nState);                             // 0x140f5e1f0 set the state and show it
    CStringW FUN_140f5e240(MS2Ptr<CItem> spItem, bool bUnk);     // 0x140f5e240 (an empty text)
    bool FUN_140f5e2a0(int nError);                             // 0x140f5e2a0 notice for a check error
    bool FUN_140f5e4c0(int nButton, const CMsgBoxData& box);    // 0x140f5e4c0 "lock option" box answered: send
    void FUN_140f5e510();                                       // 0x140f5e510 forget the options
    void FUN_140f5e570(ItemScrollSlot& slot);                   // 0x140f5e570 the target was removed from the slot
    void FUN_140f5e5f0(ItemScrollSlot& slot, DragSlot* pDrag);  // 0x140f5e5f0 an item was dropped onto the target slot
    void FUN_140f5ed50(ItemScrollSlot& slot);                   // 0x140f5ed50 the ingredient was removed from the slot
    void FUN_140f5ede0(ItemScrollSlot& slot, DragSlot* pDrag);  // 0x140f5ede0 an item was dropped onto the ingredient slot
    bool FUN_140f5f250(int nButton, const CMsgBoxData& box);    // 0x140f5f250 "ask close" box answered: close
    bool FUN_140f5f2a0(int nButton, const CMsgBoxData& box);    // 0x140f5f2a0 "high option" box answered: send
    void FUN_140f5f310(ATL::CAtlArray<int>& aLocked);           // 0x140f5f310 the locked option indexes

private:
    MS2_LAYOUT_FRIEND;
    CString m_strSlot;                                          // +0x178 "<name>.slot"
    CString m_strIngredientSlot;                                // +0x180 "targetIngredient.slot"
    unsigned __int64 m_nScrollUid;                              // +0x188 uid of the scroll
    unsigned __int64 m_nIngredientUid;                          // +0x190 uid of the ingredient
    MS2Ptr<CItem> m_spTarget;                                   // +0x198 the equipment in the slot
    MS2Ptr<CItem> m_spOption;                                   // +0x1a8 the item with the new options
    MS2Ptr<CItem> m_spIngredient;                               // +0x1b8 the ingredient in the slot
    int m_nState;                                               // +0x1c8
    int m_nPet;                                                 // +0x1cc the scroll is for pets
    bool m_bFinal;                                              // +0x1d0
    bool m_bLockOption;                                         // +0x1d1 the scroll supports locking options
    bool m_bHasLocked;                                          // +0x1d2
    int m_nOptionCount;                                         // +0x1d4
};
MS2_CHECK_SIZE(UIItemRemakeScrollDialog, 0x1d8);
MS2_CHECK_OFFSET(UIItemRemakeScrollDialog, m_strSlot, 0x178);
MS2_CHECK_OFFSET(UIItemRemakeScrollDialog, m_nScrollUid, 0x188);
MS2_CHECK_OFFSET(UIItemRemakeScrollDialog, m_spTarget, 0x198);
MS2_CHECK_OFFSET(UIItemRemakeScrollDialog, m_nState, 0x1c8);
MS2_CHECK_OFFSET(UIItemRemakeScrollDialog, m_nOptionCount, 0x1d4);
