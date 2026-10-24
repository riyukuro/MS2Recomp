// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Market-buy limit product values and archive methods.
// MS2-UNIT: unit_140269020
// MS2-RANGE: 0x140269020-0x140269160 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"

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

class Unk_MarketBuyLimitProduct
{
public:
    Unk_MarketBuyLimitProduct();
    void Reset();
    void Deserialize(Unk_MarketLimitReadArchive& archive);
    char m_base[0x18];
    int m_limit;
    int m_count;
};
MS2_CHECK_SIZE(Unk_MarketBuyLimitProduct, 0x20);

// @0x140269020
Unk_MarketBuyLimitProduct::Unk_MarketBuyLimitProduct() : m_base{}, m_limit(0), m_count(0)
{
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
