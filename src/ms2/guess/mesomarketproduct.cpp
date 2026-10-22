// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMesoMarketProduct: a Meso-Market listing record with its
// stream Write/Read pair, two getters and the operator>> / operator<< wrappers. See mesomarketproduct.h.
// MS2-UNIT: ?\mesomarketproduct.cpp
// MS2-RANGE: 0x1406aeaf0-0x1406aee80 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\mesomarketproduct.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "mesomarketproduct.h"

// The game's config singleton (FUN_1401d3200; Unk_RsConfig in regionskillobject.cpp); class in the header.
Unk_CMesoMarketConfig* FUN_1401d3200();             // the config singleton
__int64* FUN_1402c05b0(void* pConstBlock);          // 0x1402c05b0: the <constants> record at block+0x50

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1406aeaf0
CMesoMarketProduct::CMesoMarketProduct()
    : m_n18(0), m_n20(0), m_n28(0), m_30(0), m_40(0), m_b50(false)
{
}

// @0x1406aeb90
CMesoMarketProduct::~CMesoMarketProduct()
{
}

// @0x1406aebc0
__int64 CMesoMarketProduct::GetValue18()
{
    return m_n18;
}
MS2_REPLACE_METHOD(0x1406AEBC0, CMesoMarketProduct, GetValue18, 15, 0xBBB219C9);

// @0x1406aebe0
__int64 CMesoMarketProduct::GetUnitPrice()
{
    return m_n28 / (m_n20 / *FUN_1402c05b0(reinterpret_cast<char*>(FUN_1401d3200()) + 0x6018));
}
MS2_REPLACE_METHOD(0x1406AEBE0, CMesoMarketProduct, GetUnitPrice, 81, 0x0EF75E33);

// @0x1406aec40
void CMesoMarketProduct::Write(COutputStream& out)
{
    out.WriteInt64(m_n18);
    out.WriteInt64(m_n20);
    out.WriteInt64(m_n28);
    out.WriteInt64(m_30.Get());
    out.WriteInt64(m_40.Get());
    out.WriteBool(m_b50);
}
MS2_REPLACE_METHOD(0x1406AEC40, CMesoMarketProduct, Write, 210, 0x61DBEAD2);

// @0x1406aed20
void CMesoMarketProduct::Read(CInputStream& in)
{
    m_n18 = in.ReadInt64();
    m_n20 = in.ReadInt64();
    m_n28 = in.ReadInt64();
    m_30 = in.ReadInt64();
    m_40 = in.ReadInt64();
    m_b50 = in.ReadBool();
}
MS2_REPLACE_METHOD(0x1406AED20, CMesoMarketProduct, Read, 183, 0x4159FE3C);

// @0x1406aede0
CInputStream& operator>>(CInputStream& in, CMesoMarketProduct& product)
{
    product.Read(in);
    return in;
}
MS2_REPLACE_OVERLOAD(0x1406AEDE0, CInputStream&(CInputStream&, CMesoMarketProduct&), operator>>, 39, 0xE1229887);

// @0x1406aee10
COutputStream& operator<<(COutputStream& out, CMesoMarketProduct& product)
{
    product.Write(out);
    return out;
}
MS2_REPLACE_OVERLOAD(0x1406AEE10, COutputStream&(COutputStream&, CMesoMarketProduct&), operator<<, 39, 0x0B555F04);
