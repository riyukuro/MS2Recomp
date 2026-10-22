// uiunlimitedenchantdialog.h - UIUnlimitedEnchantDialog (RTTI .?AVUIUnlimitedEnchantDialog@@, 0x1d8 bytes, UI type 0x4f97
// "UnlimitedEnchantDialog"): the window in which an item of full enchant level is enchanted beyond the limit. The dialog
// lists the player's enchantable items (inventory and equipment) in an item bag, asks the server for a preview
// ("OnSelect"/"OnRetry", packet 0xbc sub 0), shows the target, the result and the ingredient list (setData) and sends the
// enchant ("OnEnchant", packet 0xbc sub 1). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\uiunlimitedenchantdialog.cpp` (0x140fb5ca0-0x140fb7dc0 .text$mn, dir client\ms2). Header/unit/member names assumed.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) with IMessageListener at +0x18. Overridden slots: 0 (dtor), 1 (class
// name), 22 (OnLoadComplete), 28 (swf callbacks), 43 (placed beside the maid dialog's reference), 48 (UI type), 65, 67, 72.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/itemslotbinder.h"

class CInPacket;
class CItem;
class Unk_UeBag;

// The result of the item check (it is also the argument of the "system error" text, so it is a real enum).
enum Unk_UnlimitedEnchantError
{
    UNLIMITED_ENCHANT_OK = 0,
    UNLIMITED_ENCHANT_INVALID_ITEM = 1,
    UNLIMITED_ENCHANT_LACK_INGREDIENT = 2,
    UNLIMITED_ENCHANT_LACK_MESO = 3,
    UNLIMITED_ENCHANT_SYSTEM = 4,
    UNLIMITED_ENCHANT_MAX_GRADE = 5
};

class UIUnlimitedEnchantDialog : public UIDialog
{
public:
    UIUnlimitedEnchantDialog();                                      // 0x140fb5ca0
    virtual ~UIUnlimitedEnchantDialog();                             //  0 0x140fb5d70 (??_G 0x140fb7c50)
    virtual CString GetTypeName();                                       //  1 0x140fb5de0: "UnlimitedEnchantDialog"
    virtual void OnLoadComplete();                                   // 22 0x140fb5ee0 list the items
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                     // 28 0x140fb5f10 "OnEnchant" / "OnSelect" / "OnRetry"
    virtual void vfunc_43();                                         // 43 0x140fb61e0
    virtual int vfunc_48() { return 0x4f97; }                        // 48 (COMDAT 0x140fb7c90)
    virtual int vfunc_65();                                          // 65 0x140fb5e30
    virtual void vfunc_67();                                         // 67 0x140fb5e50 drop the bag, close
    virtual void vfunc_72();                                         // 72 0x140fb5ec0

    void FUN_140fb6310(CInPacket* pPacket);                          // 0x140fb6310 preview result: target, result, ingredients
    void FUN_140fb6b00(CInPacket* pPacket);                          // 0x140fb6b00 enchant result
    void FUN_140fb6c30(Unk_UnlimitedEnchantError eError);                                  // 0x140fb6c30 show the error text of a check
    void FUN_140fb6ed0();                                            // 0x140fb6ed0 collect the items and fill the bag
    void SendLimitBreakMode0(unsigned __int64 nUid);                       // 0x140fb7450 ask for the preview
    void SendLimitBreakMode1(unsigned __int64 nUid);                       // 0x140fb7570 ask for the enchant
    void FUN_140fb7690(__int64 nUid);                                // 0x140fb7690 refresh the bag, select the item
    Unk_UnlimitedEnchantError FUN_140fb7870(MS2Ptr<CItem> spItem);                         // 0x140fb7870 check an item (0 ok)
    MS2Ptr<Unk_UeBag> FUN_140ba4b70(const CString& strName);         // child lookup of the movie

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<CItem> > m_items;                          // +0x178 the listed items
    ItemSlotBinder m_binder;                                         // +0x198 binds the shown items to slots
};
MS2_CHECK_SIZE(UIUnlimitedEnchantDialog, 0x1d8);
MS2_CHECK_OFFSET(UIUnlimitedEnchantDialog, m_items, 0x178);
MS2_CHECK_OFFSET(UIUnlimitedEnchantDialog, m_binder, 0x198);
