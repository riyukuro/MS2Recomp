// uivipgoodsshopdialog.h - UIVIPGoodsShopDialog (RTTI .?AVUIVIPGoodsShopDialog@@, base UIDialog; 0x1f0 bytes): the VIP
// membership goods list ("VIPGoodsShopDialog", UI id 0x4f1d). It lists the purchasable CVIPGoods rows (price, sale, buy
// limit, bonus items) from the CVIPTable, asks the server which goods were already bought in the limit period (packet 0x8e)
// and opens the merat bill dialog with a TVIPGoodsBillDataParam for the clicked row. Recovered from MapleStory2.exe KMS2_DEV
// x64 (2022-04-13); header name assumed, member names invented. Ctor 0x140fb9ac0, dtor 0x140fb9bc0 (deleting 0x140fbfaa0).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/tmarketbilldataparam.h"
#include "ms2/placeholder/mctimer.h"
#include "ms2/placeholder/ascript.h"

// The bill parameter of one VIP goods row: the goods id rides in m_nGoodsId (+0xe0); the buy callback sends packet 0x8e.
class TVIPGoodsBillDataParam : public TMarketBillDataParam
{
public:
    TVIPGoodsBillDataParam();                                       // 0x140fbf740
    virtual ~TVIPGoodsBillDataParam();                              //  0 0x140fbf860 (??_G 0x140fbfa60)

    int m_nGoodsId;                                                 // +0xe0
};
MS2_CHECK_SIZE(TVIPGoodsBillDataParam, 0xe8);
MS2_CHECK_OFFSET(TVIPGoodsBillDataParam, m_nGoodsId, 0xe0);

class CInPacket;
class CVIPGoods;
class ASData;

class UIVIPGoodsShopDialog : public UIDialog
{
public:
    typedef TMarketBillDataParam::PaymentMap PaymentMap;

    UIVIPGoodsShopDialog();                                         // 0x140fb9ac0
    virtual ~UIVIPGoodsShopDialog();                                //  0 0x140fb9bc0 (??_G 0x140fbfaa0)
    virtual CString vfunc_1();                                      //  1 0x140fb9c30 "VIPGoodsShopDialog"
    virtual void OnLoadComplete();                                  // 22 0x140fb9e10 asks the server for the bought goods
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fb9e90 onClickBuyGoods
    virtual int vfunc_48();                                         // 48 0x140fbfaf0 0x4f1d
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140fb9f70 tooltips: bonusItem / effectIcon / buyLimit
    virtual int vfunc_65();                                         // 65 0x140fb9c80
    virtual void vfunc_67();                                        // 67 0x140fb9cb0 Close: drops the bind ids
    virtual void vfunc_72();                                        // 72 0x140fb9d50 re-lists when the bought goods changed
    virtual void vfunc_79(void* pPacket);                           // 79 0x140fba7a0 packet 0xeb: the bought goods (3), a buy result (4)

    void FUN_140fbb940(std::vector<MS2Ptr<CVIPGoods> >& rOut);      // 0x140fbb940 collect the goods that are on sale (and bought where limited)
    int FUN_140fbbe00(int nPriceType);                              // 0x140fbbe00 the pay type of a price type
    void FUN_140fbaca0();                                           // 0x140fbaca0 fill the goods list of the movie
    void FUN_140fbbae0(int nGoodsId);                               // 0x140fbbae0 "onClickBuyGoods": check the limit, open the bill
    void FUN_140fbbe40(MS2Ptr<CVIPGoods> spGoods);                  // 0x140fbbe40 open the bill dialog for a goods row
    bool SendPremiumClubMode4(MS2Ptr<TMarketBillDataParam> spParam, const PaymentMap& mapPay);   // 0x140fbcca0 the buy callback
    bool FUN_140fbce80(Scaleform::GFx::Value* pRetVal, ASData& rData, MS2Ptr<TMarketBillDataParam> spParam);   // 0x140fbce80 the bill tooltip callback

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<CString> m_bindIds;                              // +0x178 the bind ids of the listed bonus items
    ATL::CAtlMap<unsigned, unsigned> m_mapBought;                   // +0x198 goods id -> bought count in the limit period
    Unk_McTimer m_timer;                                            // +0x1e0 poll of the bought goods
    unsigned m_nGoodsCount;                                         // +0x1e8 the listed goods
    int m_bReady;                                                   // +0x1ec the bought goods arrived
};
MS2_CHECK_SIZE(UIVIPGoodsShopDialog, 0x1f0);
MS2_CHECK_OFFSET(UIVIPGoodsShopDialog, m_bindIds, 0x178);
MS2_CHECK_OFFSET(UIVIPGoodsShopDialog, m_mapBought, 0x198);
MS2_CHECK_OFFSET(UIVIPGoodsShopDialog, m_timer, 0x1e0);
MS2_CHECK_OFFSET(UIVIPGoodsShopDialog, m_nGoodsCount, 0x1e8);
MS2_CHECK_OFFSET(UIVIPGoodsShopDialog, m_bReady, 0x1ec);
