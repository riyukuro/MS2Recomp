// commonpricerecord.h - the shop/mail "price" value (currency kind, sub kind, amount; 16 bytes), the list of prices and the
// record that remembers when a price was used, plus the record list (unit_140269c30, unit_14026a1b0).
// Class and member names are invented (the range belongs to the commonstruct family, no __FILE__).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/xmlattr.h"

// One currency amount: kind 0 = meso, 2 = merat (sub kind 0 = merat_c, 1 = merat/merat_f, 2 = merat_m, 3 = merat_e).
class Unk_CommonPrice
{
public:
    Unk_CommonPrice();                                              // 0x14027d940 (commonstruct_2.cpp)
    Unk_CommonPrice(int type, int subType, __int64 amount);         // 0x14027d900 (commonstruct_2.cpp)
    void Write(COutputStream* pOut);                                // 0x140269c30
    void Read(CInputStream* pIn);                                   // 0x140269ca0
    void ClearAmount();                                             // 0x140269d10
    bool LoadXml(TiXmlElement* pNode);                             // 0x140269d30

    int m_type;                                                     // +0x00 (one byte on the wire)
    int m_subType;                                                  // +0x04 (one byte on the wire)
    __int64 m_amount;                                               // +0x08
};
MS2_CHECK_SIZE(Unk_CommonPrice, 0x10);

// The array of prices (the object is the CAtlArray itself).
class Unk_CommonPriceList
{
public:
    void AddPrice(const Unk_CommonPrice& price);                    // 0x140269f30
    void AddAmount(int type, int subType, __int64 amount);          // 0x140269f60
    void Write(COutputStream* pOut);                                // 0x14026a030
    void Read(CInputStream* pIn);                                   // 0x14026a0c0
    void Clear();                                                   // 0x14026a140

    ATL::CAtlArray<Unk_CommonPrice> m_prices;
};
MS2_CHECK_SIZE(Unk_CommonPriceList, 0x20);

// A price plus the time it was used.
class Unk_CommonPriceRecord
{
public:
    Unk_CommonPriceRecord();                                              // 0x14027d8d0 (commonstruct_2.cpp)
    Unk_CommonPriceRecord(int type, int subType, __int64 amount, __int64 usedTime);   // 0x14027d880 (commonstruct_2.cpp)
    unsigned char IsUsed();                                               // 0x14026a170
    unsigned char IsAvailable();                                                // 0x14026a1b0 priced and not yet used
    __int64 GetAvailableAmount();                                         // 0x14026a1f0 the amount while unused
    bool MarkUsed();                                                      // 0x14026a220 stamp the use time (false if already used)
    void Write(COutputStream* pOut);                                      // 0x14026a260
    void Read(CInputStream* pIn);                                         // 0x14026a2b0

    Unk_CommonPrice m_price;                                        // +0x00
    __int64 m_usedTime;                                             // +0x10
};
MS2_CHECK_SIZE(Unk_CommonPriceRecord, 0x18);

// The array of price records (the object is the CAtlArray itself).
class Unk_CommonPriceRecordList
{
public:
    Unk_CommonPriceRecordList& operator=(const Unk_CommonPriceRecordList& rOther);   // 0x14026a300
    void Write(COutputStream* pOut);                                // 0x14026a350
    void Read(CInputStream* pIn);                                   // 0x14026a3d0
    void AddRecord(int type, int subType, __int64 amount, __int64 usedTime);   // 0x14026a450
    int GetCount();                                                 // 0x14026a4b0
    void Clear();                                                   // 0x14026a4e0
    unsigned char HasAvailable();                                          // 0x14026a510
    __int64 GetUsedTime(int nIndex);                                // 0x14026a580

    ATL::CAtlArray<Unk_CommonPriceRecord> m_records;
};
MS2_CHECK_SIZE(Unk_CommonPriceRecordList, 0x20);
