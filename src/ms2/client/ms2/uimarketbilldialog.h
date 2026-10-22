// uimarketbilldialog.h - UIMarketBillDialog (RTTI .?AVUIMarketBillDialog@@, base UIModalDialog; 0x280 bytes): the purchase
// bill of the merat market / cash shop ("MarketBillDialog", UI id 0x4f17). It lists what is bought with the payment kinds,
// the payback and the random payback, asks for the recipient of a gift and runs the callbacks of the TMarketBillDataParam
// it was opened with. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names invented.
// Ctor 0x140ea6ee0, dtor 0x140ea7050 (deleting dtor 0x140eac700).
//
// The dialog works in one of three modes (m_nMode): 1 buy as a gift ("buyGift"), 3 buy ("buy"), 4 basket ("basket").
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/client/ms2/tmarketbilldataparam.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"

class ASTextField;
class CMsgBoxData;

class UIMarketBillDialog : public UIModalDialog
{
public:
    typedef TMarketBillDataParam::PaymentMap PaymentMap;

    UIMarketBillDialog();                                           // 0x140ea6ee0
    virtual ~UIMarketBillDialog();                                  //  0 0x140ea7050 (??_G 0x140eac700)
    virtual CString vfunc_1();                                      //  1 0x140ea7100 "MarketBillDialog"
    virtual int vfunc_13();                                         // 13 0x140ea7270 the Tab key sends "onTabKey" to the movie
    virtual void OnLoadComplete();                                  // 22 0x140ea7310 takes the mode of the parameter, fills the movie
    virtual void vfunc_26();                                        // 26 0x140ea7210
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ea7390
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);       // 45 0x140ea7230
    virtual int vfunc_48();                                         // 48 0x140eacd00 0x4f17
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140ea7630 the tooltip of the parameter
    virtual int vfunc_65();                                         // 65 0x140ea71f0
    virtual void vfunc_67();                                        // 67 0x140ea7150 Close: forgets the parameter and the sums
    virtual void vfunc_72();                                        // 72 0x140ea7730 refreshes the fee texts when m_bDirty

    void FUN_140ea7770(MS2Ptr<TMarketBillDataParam> spParam);       // 0x140ea7770 take a new parameter and its fixed sums (the callee releases spParam)
    void FUN_140ea7900();                                           // 0x140ea7900 write the fee / payback texts and grow the movie
    float FUN_140ea7e70(MS2Ptr<ASTextField> spFee, MS2Ptr<ASTextField> spFeeText, const PaymentMap& mapPay);   // 0x140ea7e70 fill the fee texts; the height they gained
    float FUN_140ea8ab0(MS2Ptr<ASTextField> spPayback, MS2Ptr<ASTextField> spPaybackText, const PaymentMap& mapPay);   // 0x140ea8ab0 the same for the random payback
    MS2Ptr<TMarketBillDataParam> GetParam();                   // 0x140ea8da0 a copy of the parameter
    void FUN_140ea8df0();                                           // 0x140ea8df0 "initData": hand the bill rows and the texts to the movie
    CStringW FUN_140ea9710(int nPayType, __int64 nAmount);          // 0x140ea9710 the amount as text
    void FUN_140ea9770(int nPayType, __int64 nAmount);              // 0x140ea9770 add to the price of a pay type (and the total)
    void FUN_140ea9880(int nPayType, __int64 nAmount);              // 0x140ea9880 add to the random payback of a pay type
    void FUN_140ea9970(int nPayType, __int64 nAmount);              // 0x140ea9970 add to the payback of a pay type
    bool FUN_140ea9a70();                                           // 0x140ea9a70 a row is a UGC map package
    bool FUN_140ea9c30(const int& nItemType);                       // 0x140ea9c30 a row is an item of the type
    bool FUN_140ea9df0();                                           // 0x140ea9df0 a row is a locked item
    void FUN_140ea9fc0();                                           // 0x140ea9fc0 "onClickBuy" in the basket mode
    void FUN_140eaa0b0(const char* szMethod);                       // 0x140eaa0b0 "onClickBuy"
    void FUN_140eaa1e0(const char* szMethod, ASData* pData);        // 0x140eaa1e0 "onClickGiftOk"
    void FUN_140eaa5e0(ASData* pData);                              // 0x140eaa5e0 "onUpdateTotalPrice"
    void FUN_140eaa860(ASData* pData);                              // 0x140eaa860 "onChangeMode"
    void FUN_140eaa8d0();                                           // 0x140eaa8d0 rebuild the sums from the rows
    void SetMode(int nMode);                                  // 0x140eaac30 m_nMode = nMode
    CString FUN_140eaac50(int nMode);                               // 0x140eaac50 the mode as the movie names it
    bool FUN_140eaad30(bool* pbClose);                              // 0x140eaad30 ask before the buy (blueprint / UGC warnings)
    bool FUN_140eab330(bool* pbClose, const CStringW& strName, const CStringW& strMessage);   // 0x140eab330 ask before the gift
    bool FUN_140eab6b0(int nButton, const CMsgBoxData& box);        // 0x140eab6b0 the answer of the buy warning
    bool FUN_140eab7b0(int nButton, const CMsgBoxData& box);        // 0x140eab7b0 the answer of the gift question
    int FUN_140eacad0() { return m_nMode; }                         // 0x140eacad0

private:
    MS2_LAYOUT_FRIEND;
    int m_nMode;                        // +0x180 1 buy as a gift, 3 buy, 4 basket
    PaymentMap m_mapPrice;              // +0x188 the price per pay type
    PaymentMap m_mapPayback;            // +0x1d0 the payback per pay type
    PaymentMap m_mapRandomPayback;      // +0x218 the random payback per pay type
    __int64 m_nTotal;                   // +0x260 the sum of the prices
    MS2Ptr<TMarketBillDataParam> m_spParam;   // +0x268 what the dialog was opened with
    bool m_bDirty;                      // +0x278 the fee texts need a refresh
    bool m_bBlueprint;                  // +0x279 a row is an item with the gift-block flag
};
MS2_CHECK_SIZE(UIMarketBillDialog, 0x280);
MS2_CHECK_OFFSET(UIMarketBillDialog, m_nMode, 0x180);
MS2_CHECK_OFFSET(UIMarketBillDialog, m_mapPrice, 0x188);
MS2_CHECK_OFFSET(UIMarketBillDialog, m_mapPayback, 0x1d0);
MS2_CHECK_OFFSET(UIMarketBillDialog, m_mapRandomPayback, 0x218);
MS2_CHECK_OFFSET(UIMarketBillDialog, m_nTotal, 0x260);
MS2_CHECK_OFFSET(UIMarketBillDialog, m_spParam, 0x268);
MS2_CHECK_OFFSET(UIMarketBillDialog, m_bDirty, 0x278);
MS2_CHECK_OFFSET(UIMarketBillDialog, m_bBlueprint, 0x279);
