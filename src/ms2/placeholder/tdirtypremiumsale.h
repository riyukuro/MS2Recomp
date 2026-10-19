// tdirtypremiumsale.h - PLACEHOLDER for UIMeratMarketCommon::TDirtyPremiumSale (RTTI
// .?AVTDirtyPremiumSale@UIMeratMarketCommon@@, base CPtred, 0x38 bytes). NOT an original header. The premium product ids
// whose sale state changed since the last refresh (the merat market dialog and UIShopDialog keep one in their dirty state).
// Owning unit: the merat market dialog (unrecovered). Ctor 0x1413142f0 (CPtred, vftable, CAtlArray<int> ctor), Add
// 0x1413153b0 (m_ids.Add(n)). Layout cross-checked with the v2525 snapshot's TDirtyPremiumSale.h.
#pragma once
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

namespace UIMeratMarketCommon {

class TDirtyPremiumSale : public CPtred
{
public:
    TDirtyPremiumSale();                                    // 0x1413142f0
    virtual ~TDirtyPremiumSale();                           //  0

    void Add(const int& nId);                               // 0x1413153b0

    ATL::CAtlArray<int> m_ids;                              // +0x18
};

}   // namespace UIMeratMarketCommon
MS2_CHECK_SIZE(UIMeratMarketCommon::TDirtyPremiumSale, 0x38);
