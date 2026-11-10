// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemEnchantUtil: the enchant success-rate tables.
// MS2-UNIT: ?\itemenchantutil.cpp
// MS2-RANGE: 0x1405942e0-0x140595050 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemenchantutil.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/citemenchantutil.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

int FUN_1406516b0();

// @0x1405942e0
CItemEnchantUtil::CItemEnchantUtil()
{
}

// @0x140594350
CItemEnchantUtil::~CItemEnchantUtil()
{
}

// @0x1405943b0
void FUN_1405943b0(CItemEnchantUtil* pUtil)
{
    pUtil->m_rates8.clear();
    pUtil->m_rates20.clear();
    pUtil->m_rates38.clear();
    pUtil->m_rates8 = { 0, 10000, 10000, 10000, 5000, 5000, 5000, 2500, 2500, 2500, 2000, 1000, 250, 250, 200, 100 };
    pUtil->m_rates20 = { 0, 10000, 10000, 10000, 5000, 5000, 5000, 2500, 2500, 2500, 2000, 2000, 1000, 500, 200, 100 };
    pUtil->m_rates38 = { 0, 10000, 10000, 10000, 5000, 5000, 5000, 2500, 2500, 2500, 2000, 3334, 2000, 2000, 1250, 1250 };
}

// @0x140594720
int CItemEnchantUtil::FUN_140594720(int nLevel)
{
    return FUN_1405947c0(nLevel);
}

// @0x140594750
int CItemEnchantUtil::GetEnchantRate(int nLevel)
{
    if (nLevel < 1 || nLevel > 15)
        return 0;
    if (FUN_1406516b0() == 0)
        return m_rates20[nLevel];
    return m_rates8[nLevel];
}

// @0x1405947c0
int CItemEnchantUtil::FUN_1405947c0(int nLevel)
{
    if (nLevel < 1 || nLevel > 15)
        return 0;
    return m_rates38[nLevel];
}

// @0x140594810
int CItemEnchantUtil::FUN_140594810(int nType)
{
    switch (nType)
    {
    case 0x16:
    case 0x1e:
    case 0x20:
    case 0x21:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
        return 2;
    default:
        return 1;
    }
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140594720, CItemEnchantUtil, FUN_140594720, 32, 0x41D6ADA3);
MS2_REPLACE_METHOD(0x140594750, CItemEnchantUtil, GetEnchantRate, 95, 0xFF573FC7);
MS2_REPLACE_METHOD(0x1405947C0, CItemEnchantUtil, FUN_1405947c0, 60, 0x39B2A6F0);
MS2_REPLACE_METHOD(0x140594810, CItemEnchantUtil, FUN_140594810, 83, 0x690661F6);
