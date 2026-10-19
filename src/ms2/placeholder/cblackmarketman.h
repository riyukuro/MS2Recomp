// cblackmarketman.h - PLACEHOLDER for CBlackMarketMan (RTTI .?AVCBlackMarketMan@@, 0x128 bytes). NOT an original header.
// Bases: TSingleton<CBlackMarketMan> at +0x0.
// The black market (player auction house) manager: the products of the two market lists, the handlers of the packet
// 0x5f replies and the senders of its requests. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Defined in
// ?\blackmarketman.cpp; member names are invented from the use.
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/mstime.h"

class CInPacket;
class UIBlackMarketDialog;

class CBlackMarketMan : public TSingleton<CBlackMarketMan>
{
public:
    typedef ATL::CAtlMap<unsigned __int64, MS2Ptr<CBlackMarketProduct> > ProductMap;
    typedef ATL::CAtlList<MS2Ptr<CBlackMarketProduct> > ProductList;

    CBlackMarketMan();                                      // 0x140a20460
    virtual ~CBlackMarketMan();                             // 0x140a20590

    void FUN_140a20650(CInPacket& packet);                  // packet 0x5f dispatcher by the sub code
    void FUN_140a20940();                                   // send 0x5f/1
    void FUN_140a209a0();                                   // send 0x5f/6
    void FUN_140a20a00(unsigned __int64 qwA, unsigned __int64 qwB, int nCount);   // send 0x5f/2
    void FUN_140a20aa0(unsigned __int64 qwId);              // send 0x5f/3
    void FUN_140a20b10(MS2Ptr<CBlackMarketSchCond> spCond); // send 0x5f/4: the search condition
    void FUN_140a20bf0(unsigned __int64 qwId, int nCount);  // send 0x5f/5
    void FUN_140a20c70(int nA, int nB);                     // send 0x5f/8
    int FUN_140a20cf0(MS2Ptr<CBlackMarketProduct> sp);     // add to the own list (true when it was new)
    void FUN_140a20e00(unsigned __int64 qwId);              // remove from the own list
    MS2Ptr<CBlackMarketProduct> FUN_140a20e70(unsigned __int64 qwId);   // product of the own list
    void FUN_140a20f30(MS2Ptr<CBlackMarketProduct> sp);     // add to the search result
    MS2Ptr<CBlackMarketProduct> FUN_140a20ff0(unsigned __int64 qwId);   // product of the search result
    size_t FUN_140a210b0();                                 // size of the own list
    void FUN_140a210e0(ProductList& out);                   // the own list as a list
    void FUN_140a211a0(CInPacket& packet);                  // 1: the whole own list
    void FUN_140a21340(CInPacket& packet);                  // 2: one new own product
    void FUN_140a21460(CInPacket& packet);                  // 3: one own product left
    void FUN_140a216b0(CInPacket& packet);                  // 4: a search result page
    void FUN_140a21930(CInPacket& packet);                  // 5: a product was bought
    void FUN_140a21be0(CInPacket& packet);                  // 8
    void FUN_140a21ca0(CInPacket& packet);                  // 0: result code message

    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x08
    ProductList m_listSearch;                               // +0x38 the search result in server order
    ProductMap m_mapSearch;                                 // +0x68 by product id
    ProductMap m_mapOwn;                                    // +0xb0 by product id
    int m_nF8;                                              // +0xf8
    int m_padFC;
    CMsTime m_tmA;                                          // +0x100
    CMsTime m_tmB;                                          // +0x110
    int m_nReload;                                          // +0x120 set when a search page replaces the list
    int m_pad124;
};
MS2_CHECK_SIZE(CBlackMarketMan, 0x128);
MS2_CHECK_OFFSET(CBlackMarketMan, m_lock, 0x8);
MS2_CHECK_OFFSET(CBlackMarketMan, m_listSearch, 0x38);
MS2_CHECK_OFFSET(CBlackMarketMan, m_mapSearch, 0x68);
MS2_CHECK_OFFSET(CBlackMarketMan, m_mapOwn, 0xb0);
MS2_CHECK_OFFSET(CBlackMarketMan, m_nF8, 0xf8);
MS2_CHECK_OFFSET(CBlackMarketMan, m_tmA, 0x100);
MS2_CHECK_OFFSET(CBlackMarketMan, m_tmB, 0x110);
MS2_CHECK_OFFSET(CBlackMarketMan, m_nReload, 0x120);
