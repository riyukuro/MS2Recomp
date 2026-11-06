// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Trade-meso limits and fee: the min / max meso and the fee
// percent read from the Common::Constants block (TradeMinMeso +0x5f00, TradeMaxMeso +0x5f60, TradeFeePercent +0x5fc0).
// MS2-UNIT: unit_14087d0c0
// MS2-RANGE: 0x14087d0c0-0x14087d240 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_14087d0c0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<T>::Get/Read

struct Unk_TradeConst { char m_pad[0x6000]; };
struct Unk_TradeValInt { char m_pad[0x60]; };
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
int FUN_14025a620(class Unk_ConstVal*);   // C3: was FUN_14025a620

// @0x14087d0c0
__int64 FUN_14087d0c0()
{
    return reinterpret_cast<Common::Constants::Value<__int64>*>((char*)((struct Unk_TradeConst*)GetClientConstants()) + 0x5f00)->Read();
}

// @0x14087d0f0
__int64 FUN_14087d0f0()
{
    return reinterpret_cast<Common::Constants::Value<__int64>*>((char*)((struct Unk_TradeConst*)GetClientConstants()) + 0x5f60)->Read();
}

// @0x14087d120
int FUN_14087d120()
{
    return FUN_14025a620((class Unk_ConstVal*)((Unk_TradeValInt*)((char*)((struct Unk_TradeConst*)GetClientConstants()) + 0x5fc0)));
}

// @0x14087d150
__int64 FUN_14087d150(__int64 nMeso, float fRate)
{
    if (nMeso == 0)
        return 0;
    int nPercent = FUN_14087d120();
    __int64 nFee = nMeso * nPercent;
    nFee /= 100;
    nFee *= (1.0f - fRate);
    return nFee < 0 ? 0 : nFee;
}

// @0x14087d200
bool FUN_14087d200(__int64 nMeso)
{
    if (nMeso == 0)
        return true;
    if (nMeso < FUN_14087d0c0() || FUN_14087d0f0() < nMeso)
        return false;
    return true;
}
