// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Cash shop product records and their serialisers.
// MS2-UNIT: ?\cashproductdata.cpp
// MS2-RANGE: 0x1401d4a00-0x1401d64a0 .text$mn
// MS2-RANGE: 0x1400b46f0-0x1400b48e5 .text$di
// MS2-RANGE: 0x142c9a260-0x142c9a295 .text$yd
// MS2-RANGE: 0x142c9a2c0-0x142c9a317 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?RemovePostOrder@?$CRBTree@IV?$MS2Ptr@VCCashSaleProduct@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCCashSaleProduct@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x1401d6210 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\cashproductdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cashproductdata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Region setting of the client (0/1 here); read by the three selectors below.
extern int DAT_143ab0248;

// An unrecovered table built by its constructor (commonenum.cpp); only its constructor is called here.
class Unk_CashEnumTable
{
public:
    Unk_CashEnumTable();                        // 0x140220190
    char m_pad[0x30];
};

#ifndef MS2_HOOK_DLL
typedef MS2Ptr<CCashSaleProduct> CashSalePtr;
static ATL::CRBMap<unsigned, CashSalePtr> s_products(10);
static CLockCriticalSection s_lock;
static CString s_sortNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static Unk_CashEnumTable s_enumTable;
#endif

// @0x1401d4a00
CCashProductData::CCashProductData()
{
    m_n18 = 0;
    m_str20 = "";
    m_n28 = 0;
    m_n2c = 0;
    m_n30 = 0;
    m_n34 = 0;
    m_n38 = 0;
    m_n3c = 0;
    m_n40 = 0;
    m_n4c = 0;
    m_n50 = 0;
    m_n44 = 0;
    m_n48 = 0;
    m_n58 = 0;
    m_n60 = 0;
    m_n68 = 0;
    m_n70 = 0;
    m_n74 = 0;
    m_n78 = 0;
}

// @0x1401d4b50
CCashProductData::~CCashProductData()
{
}

// @0x1401d4b90
int CCashProductData::IsFlag70()
{
    if (m_n70 != 0)
        return 1;
    return 0;
}

// @0x1401d4bb0
void CCashProductData::Assign(const CCashProductData* pSrc)
{
    if (!pSrc)
        return;
    m_n18 = pSrc->m_n18;
    m_str20 = pSrc->m_str20;
    m_n28 = pSrc->m_n28;
    m_n2c = pSrc->m_n2c;
    m_n30 = pSrc->m_n30;
    m_n34 = pSrc->m_n34;
    m_n38 = pSrc->m_n38;
    m_n3c = pSrc->m_n3c;
    m_n40 = pSrc->m_n40;
    m_n44 = pSrc->m_n44;
    m_n48 = pSrc->m_n48;
    m_n4c = pSrc->m_n4c;
    m_n50 = pSrc->m_n50;
    m_n58 = pSrc->m_n58;
    m_n60 = pSrc->m_n60;
    m_n68 = pSrc->m_n68;
    m_n70 = pSrc->m_n70;
    m_n74 = pSrc->m_n74;
    m_n78 = pSrc->m_n78;
}

// @0x1401d4d20
void CCashProductData::Write(COutputStream& out)
{
    out.WriteInt32(m_n18);
    out.WriteUnicodeStringA(m_str20);
    out.WriteInt32(m_n28);
    out.WriteUInt8(m_n2c);
    out.WriteInt64(m_n30);
    out.WriteInt64(m_n34);
    out.WriteUInt8(m_n38);
    out.WriteUInt8(m_n3c);
    out.WriteUInt8(m_n40);
    out.WriteInt32(m_n44);
    out.WriteInt32(m_n48);
    out.WriteUInt8(m_n4c);
    out.WriteUInt8(m_n50);
    out.WriteInt64(m_n58);
    out.WriteInt64(m_n60);
    out.WriteInt64(m_n68);
    out.WriteUInt8(m_n70);
    out.WriteInt32(m_n74);
    out.WriteInt32(m_n78);
}

// @0x1401d4f40
void CCashProductData::Read(Unk_CashReader& in)
{
    m_n18 = in.ReadInt32();
    m_str20 = in.ReadUnicodeStringA();
    m_n28 = in.ReadInt32();
    m_n2c = in.ReadUInt8();
    m_n30 = (int)in.ReadInt64();
    m_n34 = (int)in.ReadInt64();
    m_n38 = in.ReadUInt8();
    m_n3c = in.ReadUInt8();
    m_n40 = in.ReadUInt8();
    m_n44 = in.ReadInt32();
    m_n48 = in.ReadInt32();
    m_n4c = in.ReadUInt8();
    m_n50 = in.ReadUInt8();
    m_n58 = in.ReadInt64();
    m_n60 = in.ReadInt64();
    m_n68 = in.ReadInt64();
    m_n70 = in.ReadUInt8();
    m_n74 = in.ReadInt32();
    m_n78 = in.ReadInt32();
}

#ifndef MS2_HOOK_DLL
// @0x1401d53c0
CashSalePtr GetCashSaleProduct(unsigned nId)
{
    CashSalePtr product(0);
    {
        Unk_LockGuard guard(s_lock);
        if (guard)
        {
        }
        else
            s_products.Lookup(nId, product);
    }
    return product;
}
#endif

// @0x1401d5470
CCashSaleProduct::CCashSaleProduct()
{
    m_n18 = 0;
    m_n1c = 0;
}

// @0x1401d54e0
CCashSaleProduct::~CCashSaleProduct()
{
}

// @0x1401d5520
void CCashSaleProduct::Write(COutputStream& out)
{
    out.WriteInt32(m_n18);
    out.WriteInt32(m_n1c);
    m_data.Write(out);
}

// @0x1401d5580
void CCashSaleProduct::Read(Unk_CashReader& in)
{
    m_n18 = in.ReadInt32();
    m_n1c = in.ReadInt32();
    m_data.Read(in);
}

// @0x1401d5610
CCashInventoryProduct::CCashInventoryProduct()
{
    m_n18 = 0;
    m_n1c = 0;
    m_n24 = 0;
    m_n20 = 0;
    m_nB8 = 0;
}

// @0x1401d56d0
CCashInventoryProduct::~CCashInventoryProduct()
{
}

// @0x1401d5740
void CCashInventoryProduct::Write(COutputStream& out)
{
    out.WriteInt32(m_n18);
    out.WriteInt32(m_n1c);
    out.WriteInt32(m_n24);
    out.WriteInt32(m_n20);
    out.WriteUInt8(m_nB8);
    out.WriteUnicodeString(m_strA8);
    out.WriteUnicodeString(m_strB0);
    m_data.Write(out);
}

// @0x1401d5840
void CCashInventoryProduct::Read(Unk_CashReader& in)
{
    m_n18 = in.ReadInt32();
    m_n1c = in.ReadInt32();
    m_n24 = in.ReadInt32();
    m_n20 = in.ReadInt32();
    m_nB8 = in.ReadUInt8();
    m_strA8 = in.ReadUnicodeString();
    m_strB0 = in.ReadUnicodeString();
    m_data.Read(in);
}

// The three selectors below map the region setting (0 or 1) to a flag.
// @0x1401d5a60
int CashRegionSelectA()
{
    int n = 0;
    switch (DAT_143ab0248)
    {
    case 0:
        n = 1;
        break;
    case 1:
        n = 0;
        break;
    }
    return n;
}

// @0x1401d5ab0
int CashRegionSelectB()
{
    int n = 0;
    switch (DAT_143ab0248)
    {
    case 0:
        n = 1;
        break;
    case 1:
        n = 0;
        break;
    }
    return n;
}

// @0x1401d5b00
int CashRegionSelectC()
{
    int n = 0;
    switch (DAT_143ab0248)
    {
    case 0:
        n = 0;
        break;
    case 1:
        n = 1;
        break;
    }
    return n;
}

// @0x1401d6380
MS2_EMIT_CRT_MEMMOVE_S();
