// uicashshopdialog.h - UICashShopDialog (RTTI .?AVUICashShopDialog@@, base UIDialog; 0x2f0 bytes): the in-game cash shop
// ("CashShopDialog", UI id 0x4ebc). It lists the sale products of the cash shop manager page by page, keeps a basket,
// banners (left / right) and the cash inventory filter, and opens the merat bill dialog (UI id 0x4f17) with a
// TCashShopBillDataParam for a purchase or a gift. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name
// assumed, member names invented (layout cross-checked with the xr2 tree's UICashShopDialog.h). Ctor 0x141033360, dtor
// 0x1410334e0 (deleting 0x14103c460).
//
// The unit also holds the three small classes of the shop: CashBannerInfo (0x38, ctor 0x14103b920), TCashShopBillDataParam
// (0xe0, ctor 0x14103ba30) and ASCashShopBillData (0x58, ctor 0x14103b620).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/tmarketbilldataparam.h"
#include "ms2/placeholder/asbilldata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class ASUIComponent;
class ASTextField;
class CInPacket;
class CMsgBoxData;
class CItemData;
class CCashUnlockDialog;
class UIMsg;
class Unk_CashBag;
class Unk_CashBannerRecord;
class Unk_CashButton;
class Unk_CashList;

// One banner of the shop (the left / right image): the narrowed strings of the banner record.
class CashBannerInfo : public CPtred
{
public:
    CashBannerInfo();                                               // 0x14103b920
    virtual ~CashBannerInfo();                                      //  0 0x14103be30 (??_G 0x14103c3e0)

    CString m_strImage;                                             // +0x18 the image name of the record
    CString m_strPath;                                              // +0x20 the resolved banner path
    CString m_strType;                                              // +0x28 "url" / "product"
    CString m_strValue;                                             // +0x30 the url or the product id
};
MS2_CHECK_SIZE(CashBannerInfo, 0x38);
MS2_CHECK_OFFSET(CashBannerInfo, m_strImage, 0x18);
MS2_CHECK_OFFSET(CashBannerInfo, m_strValue, 0x30);

// A product row of the bill dialog: the product id rides in m_nProductId (+0x50).
class ASCashShopBillData : public ASBillData
{
public:
    ASCashShopBillData();                                           // 0x14103b620
    virtual ~ASCashShopBillData();                                  //  0 0x14103bcd0 (??_G 0x14103c260)
    int FUN_14103d2b0() { return m_nProductId; }                    // 0x14103d2b0 the product id
    void FUN_14103fba0(int nProductId) { m_nProductId = nProductId; }   // 0x14103fba0
    void FUN_1409ab990(MS2Ptr<CItemData> spItem, int nRank);        // 0x1409ab990 the item (icon slot) of the row

    int m_nProductId;                                               // +0x50
};
MS2_CHECK_SIZE(ASCashShopBillData, 0x58);
MS2_CHECK_OFFSET(ASCashShopBillData, m_nProductId, 0x50);

// The bill parameter of a cash shop purchase / gift (the base is complete; the ctor sets the gift flag).
class TCashShopBillDataParam : public TMarketBillDataParam
{
public:
    TCashShopBillDataParam();                                       // 0x14103ba30
    virtual ~TCashShopBillDataParam();                              //  0 0x14103bec0 (??_G 0x14103c420)
};
MS2_CHECK_SIZE(TCashShopBillDataParam, 0xe0);

class UICashShopDialog : public UIDialog
{
public:
    // The product filter of the shop: the categories shown (m_mapInclude) and the product ids hidden (m_mapExclude).
    struct CategoryFilter
    {
        CategoryFilter();                                           // 0x14103b9a0
        ~CategoryFilter();                                          // 0x14103be90
        void FUN_141033200();                                       // 0x141033200 clear both maps
        void FUN_141033240(int nCategory);                          // 0x141033240 show one category, hide the listed inventory ids
        bool FUN_141033300(int nCategory, int nId);                 // 0x141033300 is the product shown?

        ATL::CAtlMap<int, int> m_mapInclude;                        // +0x00
        ATL::CAtlMap<int, int> m_mapExclude;                        // +0x48
    };
    typedef ATL::CAtlMap<CString, MS2Ptr<CashBannerInfo>, ATL::CStringElementTraitsI<CString> > BannerMap;
    typedef TMarketBillDataParam::PaymentMap PaymentMap;

    UICashShopDialog();                                             // 0x141033360
    virtual ~UICashShopDialog();                                    //  0 0x1410334e0 (??_G 0x14103c460)
    virtual CString vfunc_1();                                      //  1 0x141033660 "CashShopDialog"
    virtual int vfunc_13();                                         // 13 0x141033a50
    virtual void vfunc_15();                                        // 15 0x141033a80 runs the pending refreshes
    virtual void OnLoadComplete();                                  // 22 0x141033970 banners, categories, basket
    virtual void vfunc_26();                                        // 26 0x141033d50
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141034350
    virtual int vfunc_46();                                         // 46 0x141033d90 binds "m_probInfo"
    virtual int vfunc_48();                                         // 48 0x14103d310 0x4ebc
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x1410337e0 tooltips
    virtual int vfunc_65();                                         // 65 0x141033930
    virtual void vfunc_67();                                        // 67 0x141033710
    virtual int vfunc_73();                                         // 73 0x1410336b0
    virtual bool vfunc_75();                                        // 75 0x1410337a0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x141033e40

    int GetCategory();                                            // 0x141034da0 the category page
    bool FUN_141034dc0(int nId);                                    // 0x141034dc0 is the product shown?
    void FUN_141034e00(int nCash);                                  // 0x141034e00 the cash balance
    void FUN_141034ef0(int n, CInPacket& rPacket);                  // 0x141034ef0 the buy result: drops the bought basket rows
    void FUN_141035050();                                           // 0x141035050 products dirty
    void FUN_141035080(int nCategory);                              // 0x141035080 switch the category
    void FUN_1410350d0(MS2Ptr<CashBannerInfo> spBanner);            // 0x1410350d0 a banner was clicked
    void FUN_141035260(ATL::CAtlArray<MS2Ptr<Unk_CashBannerRecord> >& rRecords);   // 0x141035260 build the banner map
    void FUN_1410355e0(CString strSide, CString strPath);           // 0x1410355e0 a banner image arrived
    bool FUN_1410356a0();                                           // 0x1410356a0 buy ids are waiting
    void FUN_1410356f0();                                           // 0x1410356f0 open the cash unlock web dialog
    void FUN_141035920(int n);                                      // 0x141035920
    void SetUnlockState(int nState);                                 // 0x141035970 unlock state
    bool FUN_141035990(const CString& strName, ATL::CAtlArray<int>& rIds, bool bBasket);   // 0x141035990 open the bill dialog for the products
    void FUN_141035e40();                                           // 0x141035e40 page buttons
    void FUN_1410360c0();                                           // 0x1410360c0 fill the sale list
    void FUN_141036ca0();                                           // 0x141036ca0 fill the basket list
    void FUN_141037360();                                           // 0x141037360 gift prompts of the cash inventory
    void OnChargeCash();                                           // 0x141037880 open the charge page
    CString FUN_1410378d0();                                        // 0x1410378d0 the charge url
    CString FUN_141037b70();                                        // 0x141037b70 the browser path
    bool FUN_141037cd0(int nItemId, int* pnReason, int* pnTab);     // 0x141037cd0 can the item be received?
    int FUN_141037ea0(const PaymentMap& mapPay);                    // 0x141037ea0 the cash part of the payment
    MS2Ptr<TMarketBillDataParam> FUN_141037f40(const CString& strName, bool bGift);   // 0x141037f40 the bill parameter
    bool FUN_1410382a0(MS2Ptr<TMarketBillDataParam> spParam, const PaymentMap& mapPay);   // 0x1410382a0 buy callback
    bool FUN_141038aa0(MS2Ptr<TMarketBillDataParam> spParam, const PaymentMap& mapPay, const CStringW& strName, const CStringW& strText);   // 0x141038aa0 gift callback
    bool FUN_141039540(Scaleform::GFx::Value* pRetVal, ASData& rData, MS2Ptr<TMarketBillDataParam> spParam);   // 0x141039540 tooltip callback
    void FUN_1410398f0(const CString& strSide);                     // 0x1410398f0 show a banner
    void FUN_141039a90();                                           // 0x141039a90 ask for the cash charge
    bool FUN_141039bf0(int nButton, const CMsgBoxData& rData);      // 0x141039bf0 add the product to the basket
    bool FUN_141039ca0(int nButton, const CMsgBoxData& rData);      // 0x141039ca0 buy the product
    bool FUN_141039d30(int nButton, const CMsgBoxData& rData);      // 0x141039d30 refund an inventory row
    bool FUN_141039da0(int nButton, const CMsgBoxData& rData);      // 0x141039da0 use an inventory row
    bool FUN_141039e80(int nButton, const CMsgBoxData& rData);      // 0x141039e80 send the gift
    bool FUN_14103a040(int nButton, const CMsgBoxData& rData);      // 0x14103a040 open the charge page on "ok"
    MS2Ptr<ASUIComponent> FUN_14103a700(const CString& strName);    // 0x14103a700 child lookup (uiswfentity.inl)
    MS2Ptr<Unk_CashList> FUN_14103a890(const CString& strName);     // 0x14103a890 child lookup (uiswfentity.inl)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_CashBag> FUN_140ba4b70(const CString& strName);      // child lookup (shared COMDAT)
    MS2Ptr<Unk_CashButton> FUN_140bb4b10(const CString& strName);   // child lookup (shared COMDAT)
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);      // child lookup (shared COMDAT)

    int m_nCash;                                                    // +0x178 the cash balance
    int m_nCategory;                                                // +0x17c the page
    int m_nDirty;                                                   // +0x180 refresh flags (1 products, 2 inventory, 4 basket)
    CString m_str188;                                               // +0x188
    CategoryFilter m_filter;                                        // +0x190
    ATL::CAtlList<int> m_basket;                                    // +0x220 the product ids in the basket
    ATL::CAtlArray<int> m_waiting;                                  // +0x250 product ids still to buy one after another
    BannerMap m_banners;                                            // +0x270 "left" / "right"
    bool m_b2b8;                                                    // +0x2b8
    CObject* m_p2c0;                                                // +0x2c0
    int m_n2c8;                                                     // +0x2c8
    CCashUnlockDialog* m_pUnlockDialog;                             // +0x2d0
    int m_nUnlockState;                                             // +0x2d8
    MS2Ptr<ASMovieClip> m_spProbInfo;                               // +0x2e0 "m_probInfo"
};
MS2_CHECK_SIZE(UICashShopDialog, 0x2f0);
MS2_CHECK_OFFSET(UICashShopDialog, m_nCash, 0x178);
MS2_CHECK_OFFSET(UICashShopDialog, m_nCategory, 0x17c);
MS2_CHECK_OFFSET(UICashShopDialog, m_nDirty, 0x180);
MS2_CHECK_OFFSET(UICashShopDialog, m_str188, 0x188);
MS2_CHECK_OFFSET(UICashShopDialog, m_filter, 0x190);
MS2_CHECK_OFFSET(UICashShopDialog, m_basket, 0x220);
MS2_CHECK_OFFSET(UICashShopDialog, m_waiting, 0x250);
MS2_CHECK_OFFSET(UICashShopDialog, m_banners, 0x270);
MS2_CHECK_OFFSET(UICashShopDialog, m_b2b8, 0x2b8);
MS2_CHECK_OFFSET(UICashShopDialog, m_p2c0, 0x2c0);
MS2_CHECK_OFFSET(UICashShopDialog, m_pUnlockDialog, 0x2d0);
MS2_CHECK_OFFSET(UICashShopDialog, m_spProbInfo, 0x2e0);
