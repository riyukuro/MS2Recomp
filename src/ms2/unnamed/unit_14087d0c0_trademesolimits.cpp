// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Trade-meso limits and fee: the min / max meso and the fee
// percent read from the Common::Constants block (TradeMinMeso +0x5f00, TradeMaxMeso +0x5f60, TradeFeePercent +0x5fc0).
// MS2-UNIT: unit_14087d0c0
// MS2-RANGE: 0x14087d0c0-0x14087d240 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_14087d0c0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

struct Unk_TradeConst { char m_pad[0x6000]; };
struct Unk_TradeValI64 { char m_pad[0x60]; };
struct Unk_TradeValInt { char m_pad[0x60]; };
Unk_TradeConst* FUN_1401d3200();                        // the constants singleton
__int64 FUN_1402bac90(Unk_TradeValI64* pValue);         // Value<__int64>::Read
int FUN_14025a620(Unk_TradeValInt* pValue);             // Value<int>::Read

// @0x14087d0c0
__int64 FUN_14087d0c0()
{
    return FUN_1402bac90((Unk_TradeValI64*)((char*)FUN_1401d3200() + 0x5f00));
}

// @0x14087d0f0
__int64 FUN_14087d0f0()
{
    return FUN_1402bac90((Unk_TradeValI64*)((char*)FUN_1401d3200() + 0x5f60));
}

// @0x14087d120
int FUN_14087d120()
{
    return FUN_14025a620((Unk_TradeValInt*)((char*)FUN_1401d3200() + 0x5fc0));
}

// @0x14087d150
// MS2-FUNCTIONAL: exe keeps the meso*percent product and the quotient in a stack temp (extra stores, xmm order)
__int64 FUN_14087d150(__int64 nMeso, float fRate)
{
    if (nMeso == 0)
        return 0;
    int nPercent = FUN_14087d120();
    __int64 nFee = (__int64)((float)((nMeso * nPercent) / 100) * (1.0f - fRate));
    return nFee < 0 ? 0 : nFee;
}

// @0x14087d200
// MS2-FUNCTIONAL: range test branch layout differs (exe falls into the xor-al false case)
bool FUN_14087d200(__int64 nMeso)
{
    if (nMeso == 0)
        return true;
    if (nMeso >= FUN_14087d0c0() && FUN_14087d0f0() >= nMeso)
        return true;
    return false;
}
