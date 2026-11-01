// cmeratmarketman.h - PLACEHOLDER for CMeratMarketMan (RTTI .?AVCMeratMarketMan@@, 0x2e0 bytes) and CMeratMarketBasket
// (RTTI .?AVCMeratMarketBasket@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<CMeratMarketMan> at +0x0. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the code is
// client\ms2\meratmarketman.cpp (ctor 0x140d53ad0, dtor 0x140d53da0). Member and method names are invented from use.
#pragma once

#include <list>
#include <map>
#include <utility>
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/meratproductkey.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/cmeratmarketpacket.h"

class CPendingBuyBase;              // client/ms2/cmeratmarketbuy.h
class CMeratMarketProduct;          // commonfiles/meratmarketbasketinfo.h
class CMeratMarketPremiumProduct;
class CUgcBookMark;                 // commonfiles/ugcdef.h
class CUgcCharBookMark;
class CUgcMarketSeller;
class CMeratMarketBuy;
class CMeratMarketSchCond;
class CMsgBoxData;
class NotifyObject;
class CInPacket;
class ASMeratMarketBuyBillData;
class CMeratMarketBasketInfo;

// A basket line: a product with its quantity (ctor 0x140d61300, dtor 0x140d61380).
class CMeratMarketBasket : public CPtred
{
public:
    CMeratMarketBasket();                                   // 0x140d61300
    virtual ~CMeratMarketBasket();                          // 0x140d61380

    Unk_MeratProductKey FUN_140d613e0();                    // the product's key (a default key without a product)
    void FUN_140d61450(MS2Ptr<ASMeratMarketBuyBillData> spBill);    // take the product and the counts of a bill
    // @0x140d6a9d0
    void FUN_140d6a9d0(bool bBought) { m_b34 = bBought; }
    // @0x140d676f0
    bool FUN_140d676f0() { return m_b34; }
    // @0x1413159c0
    int FUN_1413159c0() { return m_n30; }

    MS2Ptr<CMeratMarketProduct> m_spProduct;                // +0x18
    __int64 m_n28;                                          // +0x28
    int m_n30;                                              // +0x30
    bool m_b34;                                             // +0x34
};
MS2_CHECK_SIZE(CMeratMarketBasket, 0x38);

typedef ATL::CRBMap<Unk_MeratProductKey, MS2Ptr<CMeratMarketProduct> > Unk_MeratProductMap;
typedef ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> > Unk_MeratProductArray;
typedef std::map<std::pair<unsigned int, int>, TPtrValue<std::list<MS2Ptr<CMeratMarketProduct> > > > Unk_MeratProductListMap;

class CMeratMarketMan : public TSingleton<CMeratMarketMan>
{
public:
    CMeratMarketMan();                                      // 0x140d53ad0
    virtual ~CMeratMarketMan();                             // 0x140d53da0

    void OnMeretMarket(CInPacket& packet);
    void SendMeretMarketMode101(int nTab, int nSort);
    void SendMeretMarketMode102();
    void SendMeretMarketMode103(int nFlag);
    void SendMeretMarketMode107();
    void SendMeretMarketMode11();
    void SendMeretMarketMode12();
    void SendMeretMarketMode13(MS2Ptr<CMeratMarketPacket::UgcAddProduct> spRequest);
    void SendMeretMarketMode14(Unk_MeratProductKey key);
    void SendMeretMarketMode15(Unk_MeratProductKey key);
    void SendMeretMarketMode18(MS2Ptr<CMeratMarketPacket::UgcResaleProduct> spRequest);
    void SendMeretMarketMode19(Unk_MeratProductKey key);
    void SendMeretMarketMode20(__int64 nSellerId);
    void FUN_140d54ac0();
    void SendMeretMarketMode22();
    void SendMeretMarketMode23(__int64 nId);
    void SendMeretMarketMode24(__int64 nId);
    void SendMeretMarketMode25(__int64 nId);
    void SendMeretMarketMode27(MS2Ptr<CMeratMarketSchCond> spCond);
    void SendSearchCondition(MS2Ptr<CMeratMarketSchCond> spCond);
    void SendMeretMarketMode29(bool bLike, const __int64& nUgcId, const int& nUIClassID);
    void SendMeretMarketMode104(MS2Ptr<CMeratMarketSchCond> spCond, int nSort);
    void SendMeretMarketMode32(ATL::CAtlArray<int>& ids);
    void SendMeretMarketMode33(ATL::CAtlArray<unsigned __int64>& ids);
    void RefreshRandomSaleProducts();
    int AddProduct(MS2Ptr<CMeratMarketProduct> spProduct);
    void RemoveProduct(Unk_MeratProductKey key);
    MS2Ptr<CMeratMarketProduct> FindProduct(Unk_MeratProductKey key);
    MS2Ptr<CMeratMarketProduct> FindProductByUid(__int64 nUid);
    MS2Ptr<CMeratMarketProduct> FindProductByDesignUid(__int64 nUgcUid);
    MS2Ptr<CMeratMarketProduct> FindProductByMusicUid(__int64 nMusicUid);
    void AddSeller(MS2Ptr<CUgcMarketSeller> spSeller);
    void RemoveSeller(MS2Ptr<CUgcMarketSeller> spSeller);
    MS2Ptr<CUgcMarketSeller> FindSeller(__int64 nId);
    MS2Ptr<CUgcMarketSeller> GetFirstSeller();
    int GetSellerCount();
    int GetProductCount();
    void RecalcSalesSums();
    void AdjustSellerTotals(MS2Ptr<CUgcMarketSeller> spSeller, __int64 nAmount);
    __int64 FUN_140d56470();
    __int64 FUN_140d56490();
    int GetBuyLimitCharLevelGoal();
    int GetBuyLimitAdLevelGoal();
    int GetSellerState();
    void SetSellerState(int nState);
    __int64 FUN_140d56780();
    int IsSettled(MS2Ptr<CUgcMarketSeller> spSeller);
    int ShowSettlementResult();
    void AddBookMark(MS2Ptr<CUgcBookMark> spOwner);
    void RemoveBookMark(__int64 nId);
    void ClearBookMarks();
    MS2Ptr<CUgcCharBookMark> FindBookMark(__int64 nId);
    int HasBookMark(__int64 nId);
    int GetBookMarkCount();
    void ReadBookMarkProducts(__int64 nId, CInPacket& packet);
    void AddProductToMapAndList(MS2Ptr<CMeratMarketProduct> spProduct, Unk_MeratProductMap& map, Unk_MeratProductArray& list);
    MS2Ptr<CMeratMarketProduct> FUN_140d57150(Unk_MeratProductKey key, __int64 nBookMarkId);
    MS2Ptr<CMeratMarketProduct> FUN_140d575e0(Unk_MeratProductKey key);
    MS2Ptr<CMeratMarketProduct> FUN_140d576a0(Unk_MeratProductKey key);
    MS2Ptr<CMeratMarketProduct> GetAdProduct(int nIndex);
    MS2Ptr<CMeratMarketProduct> FUN_140d578d0(Unk_MeratProductKey key);
    bool GetVisiblePremiumProducts(unsigned int nCategory, int nTab, Unk_MeratProductArray& out);
    MS2Ptr<CMeratMarketProduct> FUN_140d57d80(Unk_MeratProductKey key);
    void ClearLists();
    MS2Ptr<CMeratMarketBasket> GetBasketLine(unsigned int nIndex);
    MS2Ptr<CMeratMarketProduct> FUN_140d57f70(Unk_MeratProductKey key);
    int AddBasketLine(MS2Ptr<CMeratMarketBasket> spLine);
    int AddProductToBasket(MS2Ptr<CMeratMarketProduct> spProduct, __int64 nBookMarkId);
    void MarkBasketLineBought(unsigned int nIndex);
    void RemoveBasketLine(unsigned int nIndex);
    void StartPendingPurchases(int nBuyType);
    void OnPendingPurchaseResult(int bSuccess, int nResult, int nIndex);
    void RefreshAfterBuyFailure(CMeratMarketPacket::BuyPacket& buy, int nError);
    void FinishPendingPurchases(int bCancel);
    void ClearPendingPurchases();
    int FUN_140d59e20(MS2Ptr<CMeratMarketBasketInfo> spInfo, MS2Ptr<CMeratMarketBasket> spLine, int nPayType);
    void QueuePurchase(MS2Ptr<CPendingBuyBase> spBuy, int nBuyType);
    void GetShopDialogIfShopBuy();
    __int64 GetEarliestSaleEnd();
    void SetMarketNotice(const CStringW& str);
    CStringW GetMarketNotice();
    bool AddAdProduct(MS2Ptr<CMeratMarketProduct> spProduct);
    void ClearAdProducts();
    void OnMyLevelChanged(NotifyObject* pObject);
    void SendMeretMarketMode30(MS2Ptr<CMeratMarketBuy> spBuy);
    __int64 FUN_140d5a1b0();
    __int64 FUN_140d5a1d0();
    void OnDialogClosed(const int& nUIClassID);
    Unk_MeratProductArray& GetBlueprintList() { return m_150; }     // 0x140bc09d0 (inline COMDAT; uiblueprintmarketdialog.cpp)
    void CloseMarketAndClearAds();
    int FUN_140d5a2e0();
    CStringW GetPurchaseErrorText(int nError, MS2Ptr<CPendingBuyBase> spBuy);
    int GetRegisteredDesignCount();
    bool CanBuyProduct(MS2Ptr<CMeratMarketProduct> spProduct, bool bShowError);
    bool CanBuyPremiumProduct(CMeratMarketPremiumProduct* pProduct, bool bShowError);
    bool IsPushableProduct(MS2Ptr<CMeratMarketProduct> spProduct);
    bool IsProductAvailable(MS2Ptr<CMeratMarketProduct> spProduct, bool bStrict);
    int HasBuyableAdProduct();
    bool FUN_140d5b710();
    bool PushAdProducts(unsigned int nCategory, int nTab);
    bool FUN_140d5ba70();                                   // push the ad products to the ad dialog (0x4f34)
    // The server answers (sub-opcodes of the market packet, see OnMeretMarket).
    void OnMainPageProducts(CInPacket& packet);
    void ReadHomePage(CInPacket& packet);
    void ReadHomeProductGroup(CInPacket& packet);
    void ReadCategoryPage(CInPacket& packet, int nPage, int nValue);
    void UpdateEarliestSaleEnd(MS2Ptr<CMeratMarketProduct> spProduct);    // keep the earliest sale end
    void OnAdProducts(CInPacket& packet);
    void OnUgcProductsPacket(CInPacket& packet);
    void OnMySaleProducts(CInPacket& packet);
    void OnSellerList(CInPacket& packet);
    void OnProductRegistered(CInPacket& packet);
    void OnProductRemoved(CInPacket& packet);
    void OnProductUpdated(CInPacket& packet);
    void FUN_140d5d3e0(CInPacket& packet);
    void OnSellerSettled(CInPacket& packet);
    void OnProductSaleStateChanged(CInPacket& packet);
    void OnBookMarkList(CInPacket& packet);
    void OnBookMarkAdded(CInPacket& packet);
    void OnBookMarkRemoved(CInPacket& packet);
    void OnBookMarkUpdated(CInPacket& packet);
    void OnSaleNoticeTimes(CInPacket& packet);
    void OnSettleSettings(CInPacket& packet);
    void OnSearchResultPage(CInPacket& packet);
    void OnBlueprintPage(CInPacket& packet);
    void OnHomeRefreshPacket(CInPacket& packet);
    void OnRandomCouponPick(CInPacket& packet);
    void OnBuySucceeded(CInPacket& packet);
    void OnBuyFailed(CInPacket& packet);
    void OnItemUpdatePacket(CInPacket& packet);
    void FUN_140d5f5b0(CInPacket& packet);
    void FUN_140d5f5e0(CInPacket& packet);
    void OnErrorReply(CInPacket& packet);
    void HandleErrorByRequestKind(CMeratMarketPacket::ErrorPacket& error);
    void ClearSearchResults(const int& nUIType);
    bool OnPurchaseResultBoxClosed(int nResult, const CMsgBoxData& box);
    static __int64 AddDaysToTime(__int64 nTime, int nDays);

    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x8
    Unk_MeratProductMap m_products;                         // +0x38 every product seen, by key
    ATL::CRBMap<unsigned __int64, MS2Ptr<CUgcCharBookMark> > m_bookMarks;   // +0x68 by bookmark id
    ATL::CRBMap<unsigned __int64, MS2Ptr<CUgcMarketSeller> > m_sellers;     // +0x98 by seller id
    int m_nSellerState;                                     // +0xc8
    __int64 m_nd0;                                          // +0xd0
    __int64 m_nd8;                                          // +0xd8
    __int64 m_ne0;                                          // +0xe0
    __int64 m_ne8;                                          // +0xe8
    __int64 m_nf0;                                          // +0xf0
    bool m_bf8;                                             // +0xf8
    Unk_MeratProductArray m_100;                            // +0x100
    Unk_MeratProductMap m_120;                              // +0x120
    Unk_MeratProductArray m_150;                            // +0x150
    Unk_MeratProductMap m_170;                              // +0x170
    __int64 m_n1a0;                                         // +0x1a0
    __int64 m_n1a8;                                         // +0x1a8
    __int64 m_n1b0;                                         // +0x1b0
    int m_n1b8;                                             // +0x1b8
    int m_n1bc;                                             // +0x1bc
    int m_n1c0;                                             // +0x1c0
    int m_n1c4;                                             // +0x1c4 7 (days)
    void* m_p1c8;                                           // +0x1c8 (not set by the ctor)
    ATL::CAtlArray<MS2Ptr<CMeratMarketBasket> > m_basket;   // +0x1d0
    bool m_b1f0;                                            // +0x1f0
    Unk_MeratProductMap m_1f8;                              // +0x1f8
    Unk_MeratProductArray m_228;                            // +0x228
    Unk_MeratProductArray m_248;                            // +0x248
    int m_nFlags;                                           // +0x268
    Unk_MeratProductArray m_270;                            // +0x270
    Unk_MeratProductListMap m_lists;                        // +0x290
    int m_n2a0;                                             // +0x2a0
    int m_n2a4;                                             // +0x2a4
    int m_n2a8;                                             // +0x2a8
    ATL::CAtlArray<MS2Ptr<CPendingBuyBase> > m_pending;     // +0x2b0 purchases waiting for the server
    CStringW m_str2d0;                                      // +0x2d0
    bool m_b2d8;                                            // +0x2d8
};
MS2_CHECK_SIZE(CMeratMarketMan, 0x2e0);
MS2_CHECK_OFFSET(CMeratMarketMan, m_products, 0x38);
MS2_CHECK_OFFSET(CMeratMarketMan, m_nSellerState, 0xc8);
MS2_CHECK_OFFSET(CMeratMarketMan, m_100, 0x100);
MS2_CHECK_OFFSET(CMeratMarketMan, m_n1a0, 0x1a0);
MS2_CHECK_OFFSET(CMeratMarketMan, m_basket, 0x1d0);
MS2_CHECK_OFFSET(CMeratMarketMan, m_nFlags, 0x268);
MS2_CHECK_OFFSET(CMeratMarketMan, m_lists, 0x290);
MS2_CHECK_OFFSET(CMeratMarketMan, m_pending, 0x2b0);
MS2_CHECK_OFFSET(CMeratMarketMan, m_b2d8, 0x2d8);
