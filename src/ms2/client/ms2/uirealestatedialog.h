// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uirealestatedialog.h (name assumed).
//
// UIRealEstateDialog is the house (real estate) info dialog (UI type 0x4e76, swf "RealEstateDialog"): for the plot the
// player stands on it shows the building name, the contract / extension prices, the owner (or the waiting date of a house
// being sold), and offers the contract, the extension ("onRenew"), the sale ("onSell"), the home rename and the report of
// the owner. RTTI .?AVUIRealEstateDialog@@, UIDialog + UIUGCEventListener at +0x178 + the plot (0x198 bytes), vftables at
// +0 (84 slots), +0x18 (IMessageListener) and +0x178 (UIUGCEventListener, 8 slots).
// Member and method names are invented where the exe has no name (vfunc_N / FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/uiugceventlistener.h"

class UIMsg;

class UIRealEstateDialog : public UIDialog, public UIUGCEventListener
{
public:
    UIRealEstateDialog();                                           // 0x141ab20e0
    virtual ~UIRealEstateDialog();                                  //  0 0x141ab21a0 (??_G 0x141ab5be0)
    virtual CString vfunc_1();                                      //  1 0x141ab2220 "RealEstateDialog"
    virtual void OnLoadInit();                                      // 20 0x141ab23d0
    virtual void OnLoadComplete();                                  // 22 0x141ab2310
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141ab2410
    virtual int vfunc_48() { return 0x4e76; }                       // 48 0x141ab5c20
    virtual int vfunc_65();                                         // 65 0x141ab2270
    virtual void vfunc_67();                                        // 67 0x141ab22a0 close
    virtual void vfunc_79(void* p);                                 // 79 0x141ab2370
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x141ab39f0 the answers of the message boxes
    // UIUGCEventListener (+0x178)
    virtual void vfunc_ugc_5();                                     // 5 0x141ab31f0 the house changed: refresh the contract effect
    virtual void vfunc_ugc_7(int bRefresh);                         // 7 0x141ab3400 the own house changed: name and dates

    int FUN_141ab3250(const CStringW& strName);                     // request the rename of the home
    void FUN_141ab3760(CStringW strName);                           // push the home name (the callee destroys it)
    void FUN_141ab3820();                                           // push the contract effect
    void SendRequestCubeMode2();                                           // the model house (concept) dialog, or the packet 0x37 / 2
    void FUN_141ab4000(int nGroup, int nMapId);                     // select the plot
    void FUN_141ab4040(const __int64* pnTime);                      // push the expire date
    void FUN_141ab42a0();                                           // fill the movie ("initData")
    CStringW FUN_141ab5520(const __int64& nTime);                   // "y-m-d h:m" text of a time (empty for 0)

    int m_nGroup;                                                   // +0x180 the plot group
    int m_nMapId;                                                   // +0x184 the plot map
    CStringW m_strOwnerName;                                        // +0x188 the owner of the sold house (the report target)
    __int64 m_nOwnerId;                                             // +0x190
};
MS2_CHECK_SIZE(UIRealEstateDialog, 0x198);
MS2_CHECK_OFFSET(UIRealEstateDialog, m_nGroup, 0x180);
MS2_CHECK_OFFSET(UIRealEstateDialog, m_strOwnerName, 0x188);
MS2_CHECK_OFFSET(UIRealEstateDialog, m_nOwnerId, 0x190);
