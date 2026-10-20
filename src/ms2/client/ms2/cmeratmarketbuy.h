// cmeratmarketbuy.h - CPendingBuyBase (RTTI .?AVCPendingBuyBase@@, base CPtred; 0x38 bytes) and CMeratMarketBuy (base
// CPendingBuyBase; 0x60 bytes): a purchase request that waits for the server's answer (the world keeps them in a list).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names invented. The code is in
// client\ms2\meratmarketman.cpp: CPendingBuyBase ctor 0x140d64be0, dtor 0x140d65230, vftable slots 1..5 = 0x140d66ba0 /
// 0x140d66e40 / 0x140d66df0 / 0x140d6a430 / 0x140d67630; CMeratMarketBuy ctor 0x140d602f0 (builds a BuyPacket, 0x90 bytes),
// dtor 0x140d603c0 (??_G 0x140d65fc0). The definitions live in the exe; only the layout is declared here.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cmeratmarketpacket.h"

class CMeratMarketProduct;      // commonfiles/meratmarketbasketinfo.h
class ASMeratMarketBuyBillData; // placeholder/asmeratmarketbuybilldata.h
class Unk_AdMarketItem;         // unit_140e3efd0.h

class CPendingBuyBase : public CPtred
{
public:
    CPendingBuyBase();                                              // 0x140d64be0
    virtual ~CPendingBuyBase();                                     //  0 0x140d65230
    virtual CStringW vfunc_1();                                     //  1 0x140d66ba0 the product name
    virtual __int64 vfunc_2();                                      //  2 0x140d66e40 the price
    virtual int vfunc_3();                                          //  3 0x140d66df0 the pay type
    virtual void vfunc_4();                                         //  4 0x140d6a430 send the request
    virtual bool vfunc_5();                                         //  5 0x140d67630 a premium product

    int m_nState;                                                   // +0x18 1
    int m_nCount;                                                   // +0x1c the quantity (FUN_140d60a80 stores it)
    MS2Ptr<CMeratMarketProduct> m_spItem;                           // +0x20 the product being bought
    unsigned __int64 m_n30;                                         // +0x30 the product's price key
};
MS2_CHECK_SIZE(CPendingBuyBase, 0x38);
MS2_CHECK_OFFSET(CPendingBuyBase, m_nState, 0x18);
MS2_CHECK_OFFSET(CPendingBuyBase, m_nCount, 0x1c);
MS2_CHECK_OFFSET(CPendingBuyBase, m_spItem, 0x20);
MS2_CHECK_OFFSET(CPendingBuyBase, m_n30, 0x30);

class CMeratMarketBuy : public CPendingBuyBase
{
public:
    CMeratMarketBuy();                                              // 0x140d602f0
    virtual ~CMeratMarketBuy();                                     //  0 0x140d603c0 (??_G 0x140d65fc0)

    // Fill the packet (0x140d60a80): item, quantity, price kind, flag. A null item or packet is ignored.
    void FUN_140d60a80(MS2Ptr<CMeratMarketProduct> spItem, int nBuyType, int nPayType, int nFlag);
    // The same exe function as uiadpushlimiteddialog.cpp types the product (unit_140e3efd0.h's view, Unk_AdMarketItem).
    void FUN_140d60a80(MS2Ptr<Unk_AdMarketItem> spItem, int nBuyType, int nPayType, int nFlag);
    void FUN_140d60d60(int nA, int nB);                             // 0x140d60d60 packet +0x40 / +0x44
    int FUN_140d60ef0();                                            // 0x140d60ef0 the basket line index
    void FUN_140d60d10(int nValue);                                 // 0x140d60d10 packet +0x34
    void FUN_140d60dd0(const CStringW& strReceiver, const CStringW& strMessage);    // 0x140d60dd0 a gift
    void FUN_140d60e70(int nPayType);                               // 0x140d60e70
    void FUN_140d60ea0(const int& nValue);                          // 0x140d60ea0 packet +0x48
    CStringW vfunc_1() override;                                    //  1 0x140d60f40
    int vfunc_3() override;                                         //  3 0x140d611f0
    void vfunc_4() override;                                        //  4 0x140d60460
    bool vfunc_5() override;                                        //  5 0x140d61190

    MS2Ptr<CMeratMarketPacket::BuyPacket> m_spPacket;                                   // +0x38 the request sent to the server
    MS2Ptr<ASMeratMarketBuyBillData> m_spBill;                      // +0x48 the bill row of a basket purchase
    CStringW m_strName;                                             // +0x58
};
MS2_CHECK_SIZE(CMeratMarketBuy, 0x60);
MS2_CHECK_OFFSET(CMeratMarketBuy, m_spPacket, 0x38);
MS2_CHECK_OFFSET(CMeratMarketBuy, m_spBill, 0x48);
MS2_CHECK_OFFSET(CMeratMarketBuy, m_strName, 0x58);
