// cmesomarketman.h - PLACEHOLDER for CMesoMarketMan (RTTI .?AVCMesoMarketMan@@, 0xf8 bytes). NOT an original header.
// Bases: TSingleton<CMesoMarketMan> at +0x0.
// The meso market manager (players sell merat for meso and the reverse): the products of the search result and of the
// own listing, the limits of the market and the handlers of its packet 0x81 replies. A TSingleton that
// CGameApp::InitInstance (?\ms2.cpp) creates. Defined in ?\mesomarketproductcli.cpp; member names are invented from
// the use.
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/guess/mesomarketproduct.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"

class ASObj;
class CInPacket;

// The client side of a listing: the record plus the rows the market UI shows for it. Owning unit:
// ?\mesomarketproductcli.cpp.
class CMesoMarketProductCli : public CMesoMarketProduct
{
public:
    CMesoMarketProductCli();                                // 0x140d6d8c0
    virtual ~CMesoMarketProductCli();                       // 0x140d70a70 (??_G 0x140d70ca0)

    bool FUN_140d6d900();                                   // the sale is over
    void FUN_140d6d940(ASObj& row);                         // the row of an own listing
    void FUN_140d6dab0(ASObj& row);                         // the row of a listing of the market
    void FUN_140d6db30(ASObj& row);                         // the fields both rows share
};
MS2_CHECK_SIZE(CMesoMarketProductCli, 0x58);

// The market's limits (read from packet 0x81/1).
struct Unk_MesoLimits
{
    Unk_MesoLimits();                                       // 0x140d6df30
    void Read(CInPacket& packet);                           // 0x140d6dfc0
    float FUN_140d6e1f0();                                  // rate A in percent
    float FUN_140d6e210();                                  // rate B in percent
    char m_bLoaded;                                         // +0x00
    float m_fRateA;                                         // +0x04
    float m_fRateB;                                         // +0x08
    char m_pad0C[4];
    __int64 m_nBase;                                        // +0x10
    int m_n18;                                              // +0x18
    int m_n1C;                                              // +0x1c
    int m_n20;                                              // +0x20
    int m_n24;                                              // +0x24
    int m_n28;                                              // +0x28
    int m_nMin;                                             // +0x2c
    int m_nMax;                                             // +0x30
};

class CMesoMarketMan : public TSingleton<CMesoMarketMan>
{
public:
    typedef ATL::CRBMap<unsigned __int64, MS2Ptr<CMesoMarketProductCli> > ProductMap;
    typedef ATL::CAtlArray<MS2Ptr<CMesoMarketProductCli> > ProductArray;

    CMesoMarketMan();                                       // 0x140d6e2b0
    virtual ~CMesoMarketMan();                              // 0x140d6e380

    void SendMesoMarket();                                   // forget the lists and ask for the market (0x81/3)
    void OnMesoMarket(CInPacket& packet);                  // packet 0x81 dispatcher by the sub code
    void FUN_140d6e5b0(ASArray& rows);                      // the rows of the own listing
    void FUN_140d6e6d0(ASArray& rows);                      // the rows of the market
    MS2Ptr<CMesoMarketProductCli> FUN_140d6e7e0(unsigned __int64 qwId);   // product of the own listing
    MS2Ptr<CMesoMarketProductCli> FUN_140d6e890(unsigned __int64 qwId);   // product of the market
    Unk_MesoLimits& FUN_140d6e940();                        // the limits
    bool FUN_140d6e960(__int64 nCount, __int64 nPrice);      // validate a sale (true when allowed)
    bool FUN_140d6ea50(unsigned __int64 qwId);              // validate a buy
    int FUN_140d6eb50();                                    // the own count
    int FUN_140d6eb70();                                    // the buy count
    void FUN_140d6eb90(CInPacket& packet);                  // 0: result code
    void FUN_140d6ebe0(CInPacket& packet);                  // 1: the limits
    void FUN_140d6ec20(CInPacket& packet);                  // 2: the counts
    void FUN_140d6eca0(CInPacket& packet);                  // 4: the own listing
    void FUN_140d6ecf0(CInPacket& packet);                  // 5: one own product
    void FUN_140d6ee00(CInPacket& packet);                  // 6: one own product left
    void FUN_140d6eec0(CInPacket& packet);                  // 7: a market page
    void FUN_140d6efb0(CInPacket& packet);                  // 8: a product was bought
    void FUN_140d6f0b0(MS2Ptr<CMesoMarketProductCli> sp);   // add to the own listing
    void FUN_140d6f130(int nCode);                          // result code -> message
    __int64 FUN_140d6ff60();                                // lowest price allowed
    __int64 FUN_140d6ffe0();                                // highest price allowed
    void FUN_140d70060(__int64 qwId);                       // remove a product from both lists

    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x08
    ProductMap m_mapMarket;                                 // +0x38 the market page by product id
    ProductArray m_arrMarket;                               // +0x68 the market page in server order
    ProductMap m_mapOwn;                                    // +0x88 the own listing by product id
    int m_nOwn;                                             // +0xb8
    int m_nBuy;                                             // +0xbc
    Unk_MesoLimits m_limits;                                // +0xc0
};
MS2_CHECK_SIZE(CMesoMarketMan, 0xf8);
MS2_CHECK_OFFSET(CMesoMarketMan, m_lock, 0x8);
MS2_CHECK_OFFSET(CMesoMarketMan, m_mapMarket, 0x38);
MS2_CHECK_OFFSET(CMesoMarketMan, m_arrMarket, 0x68);
MS2_CHECK_OFFSET(CMesoMarketMan, m_mapOwn, 0x88);
MS2_CHECK_OFFSET(CMesoMarketMan, m_nOwn, 0xb8);
MS2_CHECK_OFFSET(CMesoMarketMan, m_limits, 0xc0);
