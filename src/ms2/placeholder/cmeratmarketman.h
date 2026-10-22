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
    void FUN_140d542c0(int nTab, int nSort);
    void FUN_140d54360();
    void FUN_140d543c0(int nFlag);
    void FUN_140d54440();
    void FUN_140d544a0();
    void FUN_140d54500();
    void FUN_140d54560(MS2Ptr<CMeratMarketPacket::UgcAddProduct> spRequest);
    void FUN_140d54610(Unk_MeratProductKey key);
    void FUN_140d54700(Unk_MeratProductKey key);
    void FUN_140d547f0(MS2Ptr<CMeratMarketPacket::UgcResaleProduct> spRequest);
    void FUN_140d54960(Unk_MeratProductKey key);
    void FUN_140d54a50(__int64 nSellerId);
    void FUN_140d54ac0();
    void FUN_140d54ba0();
    void FUN_140d54c00(__int64 nId);
    void FUN_140d54c70(__int64 nId);
    void FUN_140d54ce0(__int64 nId);
    void FUN_140d54d50(MS2Ptr<CMeratMarketSchCond> spCond);
    void FUN_140d54e50(MS2Ptr<CMeratMarketSchCond> spCond);
    void FUN_140d54fe0(bool bLike, const __int64& nUgcId, const int& nUIClassID);
    void FUN_140d550c0(MS2Ptr<CMeratMarketSchCond> spCond, int nSort);
    void FUN_140d551e0(ATL::CAtlArray<int>& ids);
    void FUN_140d552c0(ATL::CAtlArray<unsigned __int64>& ids);
    void FUN_140d553a0();
    int FUN_140d55620(MS2Ptr<CMeratMarketProduct> spProduct);
    void FUN_140d55790(Unk_MeratProductKey key);
    MS2Ptr<CMeratMarketProduct> FUN_140d55800(Unk_MeratProductKey key);
    MS2Ptr<CMeratMarketProduct> FUN_140d558c0(__int64 nUid);
    MS2Ptr<CMeratMarketProduct> FUN_140d55a10(__int64 nUgcUid);
    MS2Ptr<CMeratMarketProduct> FUN_140d55b60(__int64 nMusicUid);
    void FUN_140d55ce0(MS2Ptr<CUgcMarketSeller> spSeller);
    void FUN_140d55e50(MS2Ptr<CUgcMarketSeller> spSeller);
    MS2Ptr<CUgcMarketSeller> FUN_140d55f40(__int64 nId);
    MS2Ptr<CUgcMarketSeller> FUN_140d56000();
    int FUN_140d560e0();
    int FUN_140d56160();
    void FUN_140d56190();
    void FUN_140d56320(MS2Ptr<CUgcMarketSeller> spSeller, __int64 nAmount);
    __int64 FUN_140d56470();
    __int64 FUN_140d56490();
    int FUN_140d564b0();
    int FUN_140d565c0();
    int FUN_140d566d0();
    void FUN_140d566f0(int nState);
    __int64 FUN_140d56780();
    int FUN_140d567a0(MS2Ptr<CUgcMarketSeller> spSeller);
    int FUN_140d56840();
    void FUN_140d56a40(MS2Ptr<CUgcBookMark> spOwner);
    void FUN_140d56be0(__int64 nId);
    void FUN_140d56c60();
    MS2Ptr<CUgcCharBookMark> FUN_140d56cc0(__int64 nId);
    int FUN_140d56db0(__int64 nId);
    int FUN_140d56e40();
    void FUN_140d56eb0(__int64 nId, CInPacket& packet);
    void FUN_140d57090(MS2Ptr<CMeratMarketProduct> spProduct, Unk_MeratProductMap& map, Unk_MeratProductArray& list);
    MS2Ptr<CMeratMarketProduct> FUN_140d57150(Unk_MeratProductKey key, __int64 nBookMarkId);
    MS2Ptr<CMeratMarketProduct> FUN_140d575e0(Unk_MeratProductKey key);
    MS2Ptr<CMeratMarketProduct> FUN_140d576a0(Unk_MeratProductKey key);
    MS2Ptr<CMeratMarketProduct> FUN_140d57760(int nIndex);
    MS2Ptr<CMeratMarketProduct> FUN_140d578d0(Unk_MeratProductKey key);
    bool FUN_140d57a80(unsigned int nCategory, int nTab, Unk_MeratProductArray& out);
    MS2Ptr<CMeratMarketProduct> FUN_140d57d80(Unk_MeratProductKey key);
    void FUN_140d57e40();
    MS2Ptr<CMeratMarketBasket> FUN_140d57ed0(unsigned int nIndex);
    MS2Ptr<CMeratMarketProduct> FUN_140d57f70(Unk_MeratProductKey key);
    int FUN_140d58130(MS2Ptr<CMeratMarketBasket> spLine);
    int FUN_140d58260(MS2Ptr<CMeratMarketProduct> spProduct, __int64 nBookMarkId);
    void FUN_140d583d0(unsigned int nIndex);
    void FUN_140d584c0(unsigned int nIndex);
    void FUN_140d58650(int nBuyType);
    void FUN_140d58810(bool bSuccess, int nResult, int nIndex);
    void FUN_140d5f330(CMeratMarketPacket::BuyPacket& buy, int nError);
    void FUN_140d589f0(int bCancel);
    void FUN_140d595b0();
    int FUN_140d59e20(MS2Ptr<CMeratMarketBasketInfo> spInfo, MS2Ptr<CMeratMarketBasket> spLine, int nPayType);
    void FUN_140d59810(MS2Ptr<CPendingBuyBase> spBuy, int nBuyType);
    void FUN_140d59930();
    __int64 FUN_140d59970();
    void FUN_140d59990(const CStringW& str);
    CStringW FUN_140d599d0();
    bool FUN_140d59a60(MS2Ptr<CMeratMarketProduct> spProduct);
    void FUN_140d59ce0();
    void FUN_140d59df0(NotifyObject* pObject);
    void FUN_140d5a0d0(MS2Ptr<CMeratMarketBuy> spBuy);
    __int64 FUN_140d5a1b0();
    __int64 FUN_140d5a1d0();
    void FUN_140d5a200(const int& nUIClassID);
    Unk_MeratProductArray& GetBlueprintList() { return m_150; }     // 0x140bc09d0 (inline COMDAT; uiblueprintmarketdialog.cpp)
    void FUN_140d5a290();
    bool FUN_140d5a2e0();
    CStringW FUN_140d5a330(int nError, MS2Ptr<CPendingBuyBase> spBuy);
    int FUN_140d5b170();
    bool FUN_140d5b1f0(MS2Ptr<CMeratMarketProduct> spProduct, bool bShowError);
    bool FUN_140d5b280(CMeratMarketPremiumProduct* pProduct, bool bShowError);
    bool FUN_140d5b370(MS2Ptr<CMeratMarketProduct> spProduct);
    bool FUN_140d5b4c0(MS2Ptr<CMeratMarketProduct> spProduct, bool bStrict);
    bool FUN_140d5b6b0();
    bool FUN_140d5b710();
    bool FUN_140d5b880(unsigned int nCategory, int nTab);
    bool FUN_140d5ba70();                                   // push the ad products to the ad dialog (0x4f34)
    // The server answers (sub-opcodes of the market packet, see OnMeretMarket).
    void FUN_140d5bc30(CInPacket& packet);
    void FUN_140d5bd10(CInPacket& packet);
    void FUN_140d5bf40(CInPacket& packet);
    void FUN_140d5c0c0(CInPacket& packet, int nPage, int nValue);
    void FUN_140d601c0(MS2Ptr<CMeratMarketProduct> spProduct);    // keep the earliest sale end
    void FUN_140d5c2f0(CInPacket& packet);
    void FUN_140d5c910(CInPacket& packet);
    void FUN_140d5cb90(CInPacket& packet);
    void FUN_140d5ce00(CInPacket& packet);
    void FUN_140d5cfa0(CInPacket& packet);
    void FUN_140d5d140(CInPacket& packet);
    void FUN_140d5d2c0(CInPacket& packet);
    void FUN_140d5d3e0(CInPacket& packet);
    void FUN_140d5d500(CInPacket& packet);
    void FUN_140d5d760(CInPacket& packet);
    void FUN_140d5da10(CInPacket& packet);
    void FUN_140d5dba0(CInPacket& packet);
    void FUN_140d5dcf0(CInPacket& packet);
    void FUN_140d5dd80(CInPacket& packet);
    void FUN_140d5de90(CInPacket& packet);
    void FUN_140d5e020(CInPacket& packet);
    void FUN_140d5e190(CInPacket& packet);
    void FUN_140d5e540(CInPacket& packet);
    void FUN_140d5e930(CInPacket& packet);
    void FUN_140d5e970(CInPacket& packet);
    void FUN_140d5ed50(CInPacket& packet);
    void FUN_140d5f190(CInPacket& packet);
    void FUN_140d5f250(CInPacket& packet);
    void FUN_140d5f5b0(CInPacket& packet);
    void FUN_140d5f5e0(CInPacket& packet);
    void FUN_140d5f610(CInPacket& packet);
    void FUN_140d5fea0(CMeratMarketPacket::ErrorPacket& error);
    void FUN_140d60050(const int& nUIType);
    bool FUN_140d60280(int nResult, const CMsgBoxData& box);
    static __int64 FUN_140d61530(__int64 nTime, int nDays);

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
