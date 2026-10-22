// uisystemshopdialog.h - UISystemShopDialog (RTTI .?AVUISystemShopDialog@@, base UIDialog; 0x180 bytes): the "system shop"
// box of the auto actions ("SystemShopDialog", UI id 0x4f07). Mode 4 is the auto fishing shop (a bait slot plus the
// "extend auto fishing" button), mode 5 the auto instrument play shop. "OnShop" 0 opens the item shop on the mode's tab,
// "OnShop" 1 (fishing) / 0 (instrument) opens the extend box of the CSmartPushAutoFishing / CSmartPushAutoPlayInstrument
// push, or the cancel box when an extension is running. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// header name assumed from the unit path, member names invented from the use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

class ASData;
class CMsgBoxData;
class DragSlot;
class ItemScrollSlot;
class NotifyObject;

class UISystemShopDialog : public UIDialog
{
public:
    UISystemShopDialog();                                           // 0x140fa4180
    virtual ~UISystemShopDialog();                                  //  0 0x140fa4210 (??_G 0x140fa7ef0)
    virtual CString GetTypeName();                                      //  1 0x140fa4250 "SystemShopDialog"
    virtual void OnLoadComplete();                                  // 22 0x140fa42a0 listen to "NotifyChangeBuff", set up the mode
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x140fa44f0 "OnShop"
    virtual int vfunc_48();                                         // 48 0x140fa7f30 0x4f07
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140fa59b0 the icon tooltip (count left)
    virtual void vfunc_67();                                        // 67 0x140fa43c0 close: drop the slot, stop listening

    void SetMode(int nMode);                                  // 0x140fa5ba0 set the mode (4 fishing, 5 instrument)
    void FUN_140fa5bc0();                                           // 0x140fa5bc0 fishing: bind the bait slot, fill the movie
    bool FUN_140fa62d0(int nButton, const CMsgBoxData& box);        // 0x140fa62d0 fishing extend box answered
    bool FUN_140fa64a0(int nButton, const CMsgBoxData& box);        // 0x140fa64a0 fishing cancel box answered
    void FUN_140fa64e0();                                           // 0x140fa64e0 instrument: fill the movie
    bool FUN_140fa67a0(int nButton, const CMsgBoxData& box);        // 0x140fa67a0 instrument extend box answered
    bool FUN_140fa6970(int nButton, const CMsgBoxData& box);        // 0x140fa6970 instrument cancel box answered
    void FUN_140fa69b0(NotifyObject* pNotify);                      // 0x140fa69b0 "NotifyChangeBuff": refresh the mode
    void FUN_140fa6ab0(ItemScrollSlot& slot);                       // 0x140fa6ab0 the bait was removed from the slot
    void FUN_140fa6ae0(ItemScrollSlot& slot, DragSlot* pDrag);      // 0x140fa6ae0 a bait was dropped onto the slot

private:
    MS2_LAYOUT_FRIEND;
    int m_nMode;                                                    // +0x178 4 = auto fishing, 5 = auto instrument play
    int m_pad_17c;
};
MS2_CHECK_SIZE(UISystemShopDialog, 0x180);
MS2_CHECK_OFFSET(UISystemShopDialog, m_nMode, 0x178);
