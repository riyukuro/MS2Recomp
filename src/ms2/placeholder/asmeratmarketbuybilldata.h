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
    ASMeratMarketBuyBillData();                                     // ctor called by uimeratmarketcommon.cpp (VA by symbols.tsv)
    // The ctor 0x140e70220, the dtor 0x140e70310 (it drops both pointers) and ??_G 0x140e70410 are defined by
    // uipaybackdialog.cpp (the first obj that built one); the overrides live in ?\asbilldata.cpp.
    virtual ~ASMeratMarketBuyBillData();                            //  0 0x140e70310
    virtual int vfunc_1();                                          //  1 0x1409acc30 the item id
    virtual __int64 vfunc_6();                                      //  6 0x1409accb0 the payback
    virtual __int64 vfunc_7();                                      //  7 0x1409acdc0 the payback discount
    virtual __int64 vfunc_9();                                      //  9 0x1409aced0 the random payback
    // @0x140a8e4e0 (inline COMDAT, paybackmanagerclient.cpp)
    MS2Ptr<CMeratMarketProduct> FUN_140a8e4e0() { return m_spProduct; }
    // @0x140d66b00 (inline COMDAT, meratmarketman.cpp)
    int FUN_140d66b00() { return m_n74; }
    // @0x140d66b10 (inline COMDAT, meratmarketman.cpp)
    unsigned __int64 FUN_140d66b10() { return m_n58; }
    // @0x140d66da0 (inline COMDAT, meratmarketman.cpp)
    MS2Ptr<CMeratMarketPremiumProduct> FUN_140d66da0() { return m_spPremium; }
    int FUN_1409acb50();                                            // 0x1409acb50 m_n78 (under the bill lock)
    // @0x140d66e60
    char FUN_140d66e60() { return m_b70; }
    int FUN_1409acbe0(int nCurrency);                               // 0x1409acbe0 the pay type of a currency

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
