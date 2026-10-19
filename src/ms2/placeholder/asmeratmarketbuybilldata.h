// asmeratmarketbuybilldata.h - PLACEHOLDER for ASMeratMarketBuyBillData (RTTI .?AVASMeratMarketBuyBillData@@, 0x90 bytes),
// the bill row of a merat market purchase: an ASBillData that keeps the product it was built from. NOT an original header.
// Ctor 0x140e70220, size from the sized delete 0x140e70410; the member names are invented (layout cross-checked with the
// xr2 tree's ASMeratMarketBuyBillData.h). Only the layout and the product getter are declared; the overrides of the
// ASBillData getters live in the exe.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/placeholder/asbilldata.h"

class ASMeratMarketBuyBillData : public ASBillData
{
public:
    // @0x140a8e4e0 (inline COMDAT, paybackmanagerclient.cpp)
    MS2Ptr<CMeratMarketProduct> FUN_140a8e4e0() { return m_spProduct; }

    int m_n50;                                                      // +0x50
    unsigned __int64 m_n58;                                         // +0x58
    MS2Ptr<CMeratMarketProduct> m_spProduct;                        // +0x60 what the row was built from
    char m_b70;                                                     // +0x70
    int m_n74;                                                      // +0x74
    int m_n78;                                                      // +0x78
    MS2Ptr<CMeratMarketPremiumProduct> m_spPremium;                 // +0x80
};
MS2_CHECK_SIZE(ASMeratMarketBuyBillData, 0x90);
MS2_CHECK_OFFSET(ASMeratMarketBuyBillData, m_spProduct, 0x60);
MS2_CHECK_OFFSET(ASMeratMarketBuyBillData, m_spPremium, 0x80);
