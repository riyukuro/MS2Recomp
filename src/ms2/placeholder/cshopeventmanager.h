// cshopeventmanager.h - PLACEHOLDER for CShopEventManager (RTTI .?AVCShopEventManager@@, 0x80 bytes). NOT an original header.
// Bases: TSingleton<CShopEventManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It keeps the running premium market sale events
// (GameEventPremiumMarketSale on / off) by event id, behind a lock; the discount maths are in
// ?\shopeventmanager.cpp. Members and names are invented from the use.
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"

struct PreminmMarketSaleEventContext;

class CShopEventManager : public TSingleton<CShopEventManager>
{
public:
    CShopEventManager();                                    // 0x1407ce160
    virtual ~CShopEventManager();
    bool RemoveAllEvents();                                   // remove every event
    void AddEvent(int eventId, MS2Ptr<PreminmMarketSaleEventContext> spContext);  // GameEventPremiumMarketSale on
    void RemoveEvent(int eventId);                                                  // ... off
    void GetEventsByCurrency(ATL::CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> >& arr, const int& nCurrency);  // the events of a currency
    MS2Ptr<PreminmMarketSaleEventContext> GetEvent(const int& nEventId);         // the event of an id
    bool FUN_1407ce560(int nId, int nCurrency);             // some event covers the id
    bool FUN_1407ce690(int nId, int nCurrency);             // ... (id, no sub id)
    bool FUN_1407ce7c0();                                   // some event of the 0x186a2 currency is running
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x8
    ATL::CAtlMap<int, MS2Ptr<PreminmMarketSaleEventContext> > m_events;    // +0x38
};
MS2_CHECK_SIZE(CShopEventManager, 0x80);
MS2_CHECK_OFFSET(CShopEventManager, m_lock, 0x8);
MS2_CHECK_OFFSET(CShopEventManager, m_events, 0x38);
