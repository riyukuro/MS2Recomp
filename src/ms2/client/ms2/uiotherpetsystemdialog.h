// uiotherpetsystemdialog.h - UIOtherPetSystemDialog (RTTI .?AVUIOtherPetSystemDialog@@, 0x1f8 bytes, base
// UIPetSystemDialog; UI id 0x4f41, swf "OtherPetSystemDialog"): the pet window for another player's pet (no own pages:
// vfunc_84 returns 0). Vftables 0x142e527c8 (86 slots) / 0x142e52a80 / 0x142e52a90 (UIItemEventListener). Ctor
// 0x140e6d3c0, dtor 0x140e6d980 (??_G 0x140e6da50). Recovered with the queue unit ?\uiotherpetsystemdialog.cpp
// (TU 0x140e6d3c0-0x140e6e400); header name assumed.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uipetsystemdialog.h"

class UIOtherPetSystemDialog : public UIPetSystemDialog
{
public:
    UIOtherPetSystemDialog();                                   // 0x140e6d3c0
                                                                //  0 dtor 0x140e6d980 implicit (??_G 0x140e6da50)
    virtual CString vfunc_1();                                  //  1 0x140e6d450 "OtherPetSystemDialog"
    virtual void OnLoadComplete();                              // 22 0x140e6d580
    virtual int vfunc_48() { return 0x4f41; }                   // 48 0x140e6dc30
    virtual void vfunc_67();                                    // 67 0x140e6d540
    virtual int vfunc_84();                                     // 84 0x140e6d650 returns 0 (no own pages)
    virtual MS2Ptr<CItem> vfunc_85();                           // 85 0x140e6d660 the shown pet item

    static void FUN_140e6d4a0(int nOwnerId, MS2Ptr<CItem> spPet);    // show a player's pet (when the dialog exists)
    void FUN_140e6d5b0(int nOwnerId, MS2Ptr<CItem> spPet);      // set the pet and open (or refresh) the window
    void FUN_140e6d6b0();                                       // "m_title": "s_pet_owner" with the owner's name

private:
    MS2_LAYOUT_FRIEND;
    int m_1e0;                                                  // +0x1e0 the owner (game object id)
    MS2Ptr<CItem> m_1e8;                                        // +0x1e8 the pet item
};
MS2_CHECK_SIZE(UIOtherPetSystemDialog, 0x1f8);
MS2_CHECK_OFFSET(UIOtherPetSystemDialog, m_1e0, 0x1e0);
MS2_CHECK_OFFSET(UIOtherPetSystemDialog, m_1e8, 0x1e8);
