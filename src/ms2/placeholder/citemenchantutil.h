// citemenchantutil.h - PLACEHOLDER for CItemEnchantUtil (RTTI .?AVCItemEnchantUtil@@, 0x50 bytes). NOT an original header.
// Bases: TSingleton<CItemEnchantUtil> at +0x0. Created by CGameApp::InitInstance (?\ms2.cpp), which also calls
// FUN_1405943b0 (the table setup). Members invented from their use (?\itemenchantutil.cpp): three tables of 16 rates.
#pragma once

#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CItemEnchantUtil : public TSingleton<CItemEnchantUtil>
{
public:
    CItemEnchantUtil();                                     // 0x1405942e0
    virtual ~CItemEnchantUtil();                            // 0x140594350

    int FUN_140594720(int nLevel);                          // the rate of the third table (forwards to FUN_1405947c0)
    int GetEnchantRate(int nLevel);                          // the rate of the first / second table (by the game mode)
    int FUN_1405947c0(int nLevel);                          // the rate of the third table
    int FUN_140594810(int nType);                          // 2 for the item types that enchant twice, else 1

    // MS2_LAYOUT_FRIEND is not needed: the table setup FUN_1405943b0 (a free function, called by ms2.cpp) fills these.
    std::vector<int> m_rates8;                              // +0x08
    std::vector<int> m_rates20;                             // +0x20
    std::vector<int> m_rates38;                             // +0x38
};
MS2_CHECK_SIZE(CItemEnchantUtil, 0x50);
