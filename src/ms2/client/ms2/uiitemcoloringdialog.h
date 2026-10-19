// uiitemcoloringdialog.h - the item dye page of the beauty shop (RTTI UIItemColoringDialog, UI id 0x4e23, swf
// "ItemColoringDialog"): lists the dyeable equipment of the player ("buildItems"), previews a palette colour on the
// selected item through the customize controller, keeps a basket of the dyed items and buys them in one bill
// (UIBillDialog 0x4e7b, packet 0x23/0x16 CCItemColoringPacket::ChangeColors). NOT an original header (the unit is
// ?\uiitemcoloringdialog.cpp); member and helper names are invented from use.
//
// Layout: UIDialog (0x178) + UIItemEventListener at +0x178 + IItemCustomizeEventListener at +0x180 (vftables
// 0x142fb6c58 / 0x142fb6f00 / 0x142fb6f10 / 0x142fb7030), size 0x2e0 (operator new in CUIService::RegisterDialogs).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/client/ms2/uibeautyshopstyledialog.h"     // IItemCustomizeEventListener, Customize, CBeautyShopDataCli, Unk_BSCamera

class CItem;
class CInPacket;
class CMsgBoxData;
class NotifyObject;
class ASData;

class UIItemColoringDialog : public UIDialog, public UIItemEventListener, public IItemCustomizeEventListener
{
public:
    UIItemColoringDialog();                                     // 0x1419abdd0
    virtual ~UIItemColoringDialog();                            // 0x1419ac060 (??_G 0x1419b34a0)
    virtual CString vfunc_1();                                  //  1 "ItemColoringDialog"
    virtual int vfunc_13();                                     // 13 close on Escape
    virtual void vfunc_15();                                    // 15 tick
    virtual void OnLoadInit();                                  // 20
    virtual void OnLoadComplete();                              // 22
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
    // @0x1419b34e0
    virtual int vfunc_48() { return 0x4e23; }
    virtual void vfunc_67();                                    // 67 close
    virtual int vfunc_74(int a1, void* p2, void* p3);           // 74
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0
    virtual void vfunc_24(void* pItem);                         // UIItemEventListener 24: an item left the inventory

    void FUN_1419adbe0(NotifyObject* pNotify);                  // "NotifyGameEventChanged"
    void FUN_1419addc0(NotifyObject* pNotify);                  // "NotifyChangeActiveMyCodiTab"
    void FUN_1419ae170();                                       // fill "buildItems" with the dyeable equipment
    void FUN_1419ae790();                                       // play the dye pose of the previewed item
    bool FUN_1419ae940();                                       // leave the page (restore the camera)
    void FUN_1419ae9f0();                                       // close (asks first when the basket is not saved)
    void FUN_1419aeb50();                                       // refresh the save button and the fee
    void FUN_1419aebc0(const __int64* pUid, int nIndex);        // select an item
    void FUN_1419aeea0(unsigned nPalette, unsigned nColor);     // preview a palette colour
    void FUN_1419aef10(int nPalette, int nColor);               // preview a detail colour
    int FUN_1419aef80();                                        // "m_save" enabled
    void FUN_1419af050(int bEnable);                            // enable "m_save"
    void FUN_1419af110(int bEnable);                            // enable "m_reset"
    void FUN_1419af1d0(int bEnable);                            // enable "m_addBasket"
    void FUN_1419af290();                                       // "forceClearSelected"
    void FUN_1419af2f0(unsigned nPrice);                        // "setFee"
    void FUN_1419af750();                                       // the dye done effect
    bool FUN_1419af840();                                       // the dye was applied
    void FUN_1419af8d0();                                       // the dye failed
    int FUN_1419af980();                                        // ask and pay (coupons first)
    void FUN_1419afcd0(const Scaleform::GFx::FunctionHandler::Params& params);    // item slot tooltip
    int FUN_1419afe30();                                        // "initData" once the shop and the page are there
    void FUN_1419b00b0(CInPacket& packet);                      // beauty shop packet 0x31
    void FUN_1419b02c0(__int64 nUid, int nIndex);               // preview the item
    void FUN_1419b0620(int n);                                  // refresh the buttons
    void FUN_1419b0700();                                       // send the basket (0x23/0x16)
    int FUN_1419b0b10(ASArray* pRows, int* pTotal);             // the bill rows
    int FUN_1419b0ef0();                                        // open the bill
    MS2Ptr<CItem> FUN_1419b1440(int nItemId);                   // move the previewed item into the basket
    MS2Ptr<CItem> FUN_1419b1590(int nItemId);                   // take an item out of the basket
    __int64 FUN_1419b1710();                                    // the basket price
    bool FUN_1419b1760(int* pCoupons);                          // the player can pay; coupons used
    bool FUN_1419b1900(int bCoupon);                            // a coupon is owned
    int FUN_1419b1970(int bCoupon);                             // coupons owned
    CStringW FUN_1419b19c0();                                   // the coupon name
    int FUN_1419b1a50();                                        // the player level
    unsigned FUN_1419b1a90();                                   // the price per item
    Unk_BSFee* FUN_1419b1ac0();                                 // the fee row
    unsigned FUN_1419b1af0(unsigned nPrice);                    // the sale price
    bool FUN_1419b1b50();                                       // restart (the "my codi" tab expired)
    bool FUN_1419b1d00(int nButton, const CMsgBoxData& box);    // close confirm
    bool FUN_1419b1d40(int nButton, const CMsgBoxData& box);    // pay confirm
    bool FUN_1419b1d70(int nButton, const CMsgBoxData& box);    // restart confirm
    void FUN_1419b1db0();                                       // empty the basket
    void FUN_1419b1e40(ATL::CAtlList<MS2Ptr<CItem> >& list);    // restore the items of a list
    void FUN_1419b1f50(int nDelta);                             // pending dye requests
    int FUN_1418ce5b0();                                        // the sale event id (m_1a8.m_18; uibeautyshopdialog.cpp)

private:
    MS2_LAYOUT_FRIEND;
    unsigned m_198;                                             // +0x198 the last "SaleBeautyShop" pose tick
    unsigned m_19c;                                             // +0x19c the pose interval (5..10 s)
    int m_1a0;                                                  // +0x1a0 the shop packet mode
    int m_1a4;
    CBeautyShopDataCli m_1a8;                                   // +0x1a8 the shop
    int m_250;                                                  // +0x250 the selected item index (-1: none)
    std::pair<unsigned, unsigned> m_254;                        // +0x254 the palette and the colour
    int m_25c;                                                  // +0x25c the page is up
    bool m_260;                                                 // +0x260 dye requests pending
    int m_264;                                                  // +0x264 their count
    MS2Ptr<Customize> m_268;                                    // +0x268 the customize controller
    ATL::CAtlList<MS2Ptr<CItem> > m_278;                        // +0x278 the dyeable items
    ATL::CAtlList<MS2Ptr<CItem> > m_2a8;                        // +0x2a8 the basket
    Unk_BSCamera* m_2d8;                                        // +0x2d8 the camera (UI 0x4ef2's object)
};
MS2_CHECK_SIZE(UIItemColoringDialog, 0x2e0);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_250, 0x250);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_254, 0x254);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_25c, 0x25c);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_268, 0x268);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_278, 0x278);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_2a8, 0x2a8);
MS2_CHECK_OFFSET(UIItemColoringDialog, m_2d8, 0x2d8);
