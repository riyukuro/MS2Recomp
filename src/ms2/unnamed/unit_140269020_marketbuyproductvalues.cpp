// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Market-buy limit product values and archive methods.
// MS2-UNIT: unit_140269020
// MS2-RANGE: 0x140269020-0x140269160 .text$mn
#define MS2_THIS_FILE ""
// MS2-PIN: ??_7Unk_MarketBuyLimitProduct@@6B@ 0x142d15a88
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class Unk_MarketLimitWriteArchive
{
public:
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void WriteInt(int value) = 0;
};

class Unk_MarketLimitReadArchive
{
public:
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual int ReadInt() = 0;
};

// RTTI CMarketBuyLimitProduct, vftable 0x142d15a88 with one slot: ??_G (0x14027fc70, crt delete 0x20). The ctor runs
// CPtred() (0x140159740), stores that vftable and calls Reset; the old `char m_base[0x18]` stand-in left it null.
class Unk_MarketBuyLimitProduct : public CPtred
{
public:
    Unk_MarketBuyLimitProduct();
    void Reset();
    void Deserialize(Unk_MarketLimitReadArchive& archive);
    int m_limit;
    int m_count;
};
MS2_CHECK_SIZE(Unk_MarketBuyLimitProduct, 0x20);

// @0x140269020
Unk_MarketBuyLimitProduct::Unk_MarketBuyLimitProduct()
{
    Reset();
}

// @0x140269070
void Unk_MarketBuyLimitProduct::Reset()
{
    m_limit = 0;
    m_count = 0;
}

// @0x1402690a0
void FUN_1402690a0(const Unk_MarketBuyLimitProduct* product, Unk_MarketLimitWriteArchive& archive)
{
    archive.WriteInt(product->m_limit);
    archive.WriteInt(product->m_count);
}

// @0x1402690f0
void Unk_MarketBuyLimitProduct::Deserialize(Unk_MarketLimitReadArchive& archive)
{
    m_limit = archive.ReadInt();
    m_count = archive.ReadInt();
}
