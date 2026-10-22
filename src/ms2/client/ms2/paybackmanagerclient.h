// paybackmanagerclient.h - PaybackManagerClient (RTTI .?AVPaybackManagerClient@@, base TSingleton<PaybackManagerClient>; 0x28
// bytes), the client side of the merat payback event: the player's payback level and merat (the 0x12d packet), the products
// of the payback shop sorted by their start date, the payback button of the merat market, and the period text of the
// payback dialog (UIPaybackDialog, UI id 0x4f93). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name
// assumed, member names invented. Ctor 0x140a8af50; the dtor 0x140a8e240 (deleting 0x140a8e460) is the implicit one (it does not store the vptr).
#pragma once
#include <afx.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/client/ms2/tmarketbilldataparam.h"

class CInPacket;

class PaybackManagerClient : public TSingleton<PaybackManagerClient>
{
public:
    typedef std::vector<MS2Ptr<CMeratMarketProduct> > ProductVector;

    PaybackManagerClient();                                         // 0x140a8af50

    void FUN_140a8afb0(CInPacket& packet);                          // 0x140a8afb0 the 0x12d packet: 0 level / merat, 1 the product list
    void FUN_140a8b240(CStringW& strButton, bool& bShow);           // 0x140a8b240 the payback button of the merat market
    void FUN_140a8b290();                                           // 0x140a8b290 click on that button: open / toggle the dialog
    int FUN_140a8b320() const { return m_nLevel; }                  // 0x140a8b320
    unsigned GetMerat() const;             // 0x140a8b340
    MS2Ptr<CMeratMarketProduct> FUN_140a8b360() const;              // 0x140a8b360 the first product that is on sale
    void FUN_140a8b490(MS2Ptr<TMarketBillDataParam> spParam);       // 0x140a8b490 text of the bottom line of the bill
    CStringW FUN_140a8ba00();                                       // 0x140a8ba00 "from y/m/d to y/m/d"
    bool FUN_140a8bcc0(MS2Ptr<CMeratMarketProduct> spProduct);      // 0x140a8bcc0 a payback product is bought: tell the player
    bool FUN_140a8be20(unsigned char bNotify);                      // 0x140a8be20 the payback is open
    bool FUN_140a8be80(unsigned char bNotify);                               // 0x140a8be80 the payback event is on and not blocked
    bool FUN_140a8bf50(MS2Ptr<CMeratMarketProduct> spProduct) const;   // 0x140a8bf50 the product is in the list

private:
    MS2_LAYOUT_FRIEND;
    int m_nLevel;                                                   // +0x08 the adventure level of the payback
    unsigned m_nMerat;                                              // +0x0c the merat earned so far
    ProductVector m_products;                                       // +0x10 sorted by start date
};
MS2_CHECK_SIZE(PaybackManagerClient, 0x28);
MS2_CHECK_OFFSET(PaybackManagerClient, m_nLevel, 0x8);
MS2_CHECK_OFFSET(PaybackManagerClient, m_products, 0x10);
