// uitradedialogex.h - UITradeDialogEx (RTTI .?AVUITradeDialogEx@@, 0x230 bytes, UIDialog + UIDialogEventListener +
// UIStatusEventListener, UI id 0x4e83, swf "TradeDialogEx"): the player-to-player trade window. It shows both sides' bags
// ("<name>_my" / "<name>_target" TradeSlotBag ids, 5 slots), the meso inputs and fee texts, forwards the "OnLock" /
// "OnConfirm" buttons to the CTradeManagerEx and docks beside the inventory dialog (UI id 0x4e2d). Owning unit:
// ?\uitradedialogex.cpp (0x141b26de0-0x141b29f20, dir client\ms2). Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uidialogeventlistener.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class ASTextField;
class CItem;
class ASTextInput;

class UITradeDialogEx : public UIDialog, public UIDialogEventListener, public UIStatusEventListener
{
public:
    UITradeDialogEx();                                                  // 0x141b26de0
    virtual ~UITradeDialogEx();                                         //  0 0x141b27070 (??_G 0x141b29bd0)
    virtual CString GetTypeName();                                          //  1 0x141b271d0 "TradeDialogEx"
    virtual void OnLoadInit();                                          // 20 0x141b27a60
    virtual void OnLoadComplete();                                      // 22 0x141b274f0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b27aa0
    virtual int vfunc_48() { return 0x4e83; }                           // 48 0x141b29cc0
    virtual int vfunc_65();                                             // 65 0x141b27220
    virtual void vfunc_66();                                            // 66 0x141b273b0 dock beside the inventory
    virtual void vfunc_67();                                            // 67 0x141b27250 close
    virtual void vfunc_79(void* p);                                     // 79 0x141b27550
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);           // IMessageListener 0 0x141b27ca0
    virtual void vfunc_oa0_11(void* a1);                                // UIStatusEventListener 11 0x141b28440

    void FUN_141b27580();                                               // initData: names, profiles, bag ids; then bind the controls
    void FUN_141b27cf0();                                               // create both slot bags
    void FUN_141b27d50();                                               // destroy both slot bags
    void FUN_141b27d90(__int64 nMeso);                                  // m_nMyMeso = min(nMeso, max trade meso)
    void FUN_141b27de0(int nSide, int nIndex, MS2Ptr<CItem> spItem);    // put an item (or clear) into a trade slot
    void FUN_141b27fa0(int nSide, int nIndex);                          // clear a trade slot
    void FUN_141b28130(int nSide, __int64 nMeso);                       // show the meso of a side
    void FUN_141b28290(int nSlotIndex, int bLock);                      // latch / unlatch a side (sound + AS call)
    int FUN_141b283f0(int* pnSlot);                                     // the first free slot of the trade table (false: none)
    void FUN_141b284b0();                                               // bind the inputs and texts of the movie
    void FUN_141b28d10(char bMine, __int64 nMeso);                      // show the meso number text
    void FUN_141b28e30(char bMine, __int64 nFee);                       // show the fee text
    void FUN_141b28f40(__int64 nMeso, char bMine);                      // compute and show the fee
    void FUN_141b291a0(const Scaleform::GFx::FunctionHandler::Params& params);   // my meso input changed
    void FUN_141b29330(const Scaleform::GFx::FunctionHandler::Params& params);   // focus left the meso input
    void FUN_141b294f0(__int64 nMeso);                                  // set the meso input text
    bool FUN_141b295a0(__int64 nMeso);                                  // validate the offered meso
    void FUN_141b297e0(int nCode);                                      // reset the meso on some trade errors

private:
    MS2_LAYOUT_FRIEND;
    CString m_strMyBagId;                                               // +0x188 "<name>_my"
    CString m_strTargetBagId;                                           // +0x190 "<name>_target"
    __int64 m_uidTarget;                                                // +0x198 the partner's character id
    CStringW m_strTargetName;                                           // +0x1a0
    CString m_strTargetChar;                                            // +0x1a8 (profile image key)
    bool m_bDockedOnInventory;                                          // +0x1b0 the inventory was open when this opened
    MS2Ptr<ASTextInput> m_spMyInput;                                    // +0x1b8 "m_myInputMeso"
    MS2Ptr<ASTextField> m_spMyInputText;                                // +0x1c8 the input's text field
    MS2Ptr<ASTextInput> m_spTargetInput;                                // +0x1d8 "m_targetInputMeso"
    MS2Ptr<ASTextField> m_spMyFee;                                      // +0x1e8 "m_myTradeFee"
    MS2Ptr<ASTextField> m_spTargetFee;                                  // +0x1f8 "m_targetTradeFee"
    MS2Ptr<ASTextField> m_spMyMeso;                                     // +0x208 "m_myMesoNumberString"
    MS2Ptr<ASTextField> m_spTargetMeso;                                 // +0x218 "m_targetMesoNumberString"
    __int64 m_nMyMeso;                                                  // +0x228 the meso offered (clamped)
};
MS2_CHECK_SIZE(UITradeDialogEx, 0x230);
MS2_CHECK_OFFSET(UITradeDialogEx, m_strMyBagId, 0x188);
MS2_CHECK_OFFSET(UITradeDialogEx, m_uidTarget, 0x198);
MS2_CHECK_OFFSET(UITradeDialogEx, m_bDockedOnInventory, 0x1b0);
MS2_CHECK_OFFSET(UITradeDialogEx, m_spMyInput, 0x1b8);
MS2_CHECK_OFFSET(UITradeDialogEx, m_spTargetMeso, 0x218);
MS2_CHECK_OFFSET(UITradeDialogEx, m_nMyMeso, 0x228);
