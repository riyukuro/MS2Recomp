// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The shop/mail "price" value (currency kind, sub kind, amount;
// 16 bytes) with its stream (de)serialisation and xml loader, the list of prices (CAtlArray at +0) and the record
// validity test. Class and member names are invented (the range belongs to the commonstruct family, no __FILE__).
// MS2-UNIT: unit_140269c30
// MS2-RANGE: 0x140269c30-0x14026a1b0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/commonpricerecord.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

bool FUN_140184310(const CString& str, const char* psz);   // str == psz

// @0x140269c30
void Unk_CommonPrice::Write(COutputStream* pOut)
{
    pOut->WriteUInt8((unsigned char)m_type);
    pOut->WriteUInt8((unsigned char)m_subType);
    pOut->WriteInt64(m_amount);
}
MS2_REPLACE_METHOD(0x140269C30, Unk_CommonPrice, Write, 93, 0x2ED870DB);

// @0x140269ca0
void Unk_CommonPrice::Read(CInputStream* pIn)
{
    m_type = pIn->ReadUInt8();
    m_subType = pIn->ReadUInt8();
    m_amount = pIn->ReadInt64();
}
MS2_REPLACE_METHOD(0x140269CA0, Unk_CommonPrice, Read, 97, 0xE26F4BDD);

// @0x140269d10
void Unk_CommonPrice::ClearAmount()
{
    m_amount = 0;
}
MS2_REPLACE_METHOD(0x140269D10, Unk_CommonPrice, ClearAmount, 19, 0x8111F705);

// @0x140269d30
bool Unk_CommonPrice::LoadXml(Unk_140165cf0* pNode)
{
    CStringA strType;
    FUN_1408733e0(pNode, "type", strType);
    FUN_1408732e0(pNode, "amount", m_amount);
    if (FUN_140184310(strType, "meso"))
    {
        m_type = 0;
        return true;
    }
    else if (FUN_140184310(strType, "merat_f") || FUN_140184310(strType, "merat"))
    {
        m_type = 2;
        m_subType = 1;
        return true;
    }
    else if (FUN_140184310(strType, "merat_c"))
    {
        m_type = 2;
        m_subType = 0;
        return true;
    }
    else if (FUN_140184310(strType, "merat_m"))
    {
        m_type = 2;
        m_subType = 2;
        return true;
    }
    else if (FUN_140184310(strType, "merat_e"))
    {
        m_type = 2;
        m_subType = 3;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140269D30, Unk_CommonPrice, LoadXml, 483, 0xF7A084D2);

// @0x140269f30
void Unk_CommonPriceList::AddPrice(const Unk_CommonPrice& price)
{
    m_prices.Add(price);
}
MS2_REPLACE_METHOD(0x140269F30, Unk_CommonPriceList, AddPrice, 37, 0x22625142);

// @0x140269f60
void Unk_CommonPriceList::AddAmount(int type, int subType, __int64 amount)
{
    int nCount = (int)m_prices.GetCount();
    for (int i = 0; i < nCount; i++)
    {
        Unk_CommonPrice& price = m_prices[i];
        if (price.m_type == type && price.m_subType == subType)
        {
            price.m_amount += amount;
            return;
        }
    }
    AddPrice(Unk_CommonPrice(type, subType, amount));
}
MS2_REPLACE_METHOD(0x140269F60, Unk_CommonPriceList, AddAmount, 189, 0x650EFAA4);

// @0x14026a030
void Unk_CommonPriceList::Write(COutputStream* pOut)
{
    unsigned char nCount = (unsigned char)m_prices.GetCount();
    pOut->WriteUInt8(nCount);
    for (int i = 0; i < (int)nCount; i++)
    {
        Unk_CommonPrice* pPrice = &m_prices.GetAt(i);
        pPrice->Write(pOut);
    }
}
MS2_REPLACE_METHOD(0x14026A030, Unk_CommonPriceList, Write, 128, 0x06B8811A);

// @0x14026a0c0
void Unk_CommonPriceList::Read(CInputStream* pIn)
{
    unsigned char nCount = pIn->ReadUInt8();
    for (int i = 0; i < (int)nCount; i++)
    {
        Unk_CommonPrice price;
        price.Read(pIn);
        m_prices.Add(price);
    }
}
MS2_REPLACE_METHOD(0x14026A0C0, Unk_CommonPriceList, Read, 115, 0xC302B45E);

// @0x14026a140
void Unk_CommonPriceList::Clear()
{
    m_prices.RemoveAll();
}
MS2_REPLACE_METHOD(0x14026A140, Unk_CommonPriceList, Clear, 27, 0xBF716CEA);

// @0x14026a170
unsigned char Unk_CommonPriceRecord::IsUsed()
{
    int nUsed;
    if (m_price.m_amount > 0 && m_usedTime != 0)
    {
        nUsed = 1;
    }
    else
    {
        nUsed = 0;
    }
    return nUsed;
}
MS2_REPLACE_METHOD(0x14026A170, Unk_CommonPriceRecord, IsUsed, 58, 0xD046B5DF);
