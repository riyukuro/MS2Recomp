// ccashmarketman.h - PLACEHOLDER for CCashMarketMan (RTTI .?AVCCashMarketMan@@, 0x100 bytes). NOT an original header.
// Bases: TSingleton<CCashMarketMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the cash shop product lists and the cash inventory
// ("pick up" list) with the handlers of the cash shop packet 0x6a. Defined in ?\cashinventorybag.cpp; member names are
// invented from the use.
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/cashproductdata.h"
#include "ms2/commonfiles/cmarketbuylimithistory.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"

class CInPacket;
class CMsgBoxData;
class Unk_CashLimitRowA;
class Unk_CashLimitRowB;

class CCashMarketMan : public TSingleton<CCashMarketMan>
{
public:
    CCashMarketMan();                                       // 0x140b05e40
    virtual ~CCashMarketMan();                              // 0x140b05f20

    ATL::CAtlArray<MS2Ptr<CCashInventoryProduct> >& FUN_140b05c00() { return m_aInv; }   // 0x140b05c00
    bool GetFlag() const;                                   // 0x140b06000 m_bFlag
    void OnCash(CInPacket& packet);                  // packet 0x6a dispatcher by the sub code
    void SendCashMode0();                                   // send 0x6a/0
    void SendCashMode1();                                   // send 0x6a/1
    void SendCashMode2(int a, int b);                       // send 0x6a/2
    void SendCashMode3(int a, int b, CString s1, CString s2);   // send 0x6a/3 (strings by value: the callee destroys them)
    void SendCashMode4(int a, int b, int c);               // send 0x6a/4
    void SendCashMode5(int a);                              // send 0x6a/5
    void SendCashMode7(int a, int b, int c, int nFlag);     // send 0x6a/7
    void SendCashMode6(int a, int b);                       // send 0x6a/6
    int FUN_140b06600(int nId);                             // result code of the sale product nId
    int FUN_140b06680(MS2Ptr<CCashSaleProduct> spSale);     // result code of the sale product (by value)
    MS2Ptr<CCashSaleProduct> FUN_140b06750(int nId);        // find a sale product
    MS2Ptr<CCashInventoryProduct> FUN_140b067d0(int nIndex);        // the inventory product at nIndex (null if outside)
    MS2Ptr<CCashInventoryProduct> FUN_140b06870(int a, int b);      // the inventory product with m_n1c == a && m_n18 == b
    void FUN_140b06980(int nByte, int nResult);             // show the message of a result code
    void FUN_140b06bd0(CInPacket& packet);                  // 0xc9: the whole buy limit list
    void FUN_140b06d70(CInPacket& packet);                  // 0xca: one buy limit row
    int FUN_140b06ed0(int nProductId);                      // bought count of the product (0 when unknown)
    bool FUN_140b06f90(MS2Ptr<Unk_CashLimitRowA> sp);       // limit reached
    bool FUN_140b07060(MS2Ptr<Unk_CashLimitRowB> sp);       // limit reached
    void FUN_140b07120(CInPacket& packet);                  // 0: the sale product list
    void FUN_140b072d0(CInPacket& packet);                  // 1
    void FUN_140b07490(CInPacket& packet);                  // 2
    void FUN_140b07cb0(CInPacket& packet);                  // 3
    void FUN_140b084f0(CInPacket& packet);                  // 4
    void FUN_140b08760(CInPacket& packet);                  // 5: the cash inventory page
    void FUN_140b08ab0(CInPacket& packet);                  // 7
    void FUN_140b08ee0(CInPacket& packet);                  // 9
    void FUN_140b08f50(CInPacket& packet);                  // 8
    bool FUN_140b08fe0(int nButton, const CMsgBoxData& box);    // message box callback

    MS2_LAYOUT_FRIEND;
    int m_nPage;                                            // +0x08 page of the cash inventory
    int m_pad_c;
    CLockCriticalSection m_lock;                            // +0x10
    ATL::CAtlMap<int, MS2Ptr<CCashSaleProduct> > m_mapSale;     // +0x40 by product id
    ATL::CAtlArray<MS2Ptr<CCashSaleProduct> > m_aSale;      // +0x88
    ATL::CAtlArray<MS2Ptr<CCashInventoryProduct> > m_aInv;  // +0xa8
    bool m_bFlag;                                           // +0xc8
    ATL::CRBMap<unsigned int, MS2Ptr<CMarketBuyLimitHistory> > m_mapLimit;   // +0xd0
};
MS2_CHECK_SIZE(CCashMarketMan, 0x100);
MS2_CHECK_OFFSET(CCashMarketMan, m_lock, 0x10);
MS2_CHECK_OFFSET(CCashMarketMan, m_mapSale, 0x40);
MS2_CHECK_OFFSET(CCashMarketMan, m_aSale, 0x88);
MS2_CHECK_OFFSET(CCashMarketMan, m_aInv, 0xa8);
MS2_CHECK_OFFSET(CCashMarketMan, m_mapLimit, 0xd0);
