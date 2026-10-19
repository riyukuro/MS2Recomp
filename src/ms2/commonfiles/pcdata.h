// CPCData / CPCDataPack (RTTI names): the persisted record of a player character as it travels between the servers and the
// client. CPCData is the 0x440 byte record (ids, name, three 0x118 byte blobs, a stat map, the strings and a few counters;
// FUN_14071e570 serialises it to a COutputStream, FUN_14071ec80 reads it back from a CInputStream). CPCDataPack holds three
// CByteBuffers: the CPCData record, the equipped / inventory items and the extra items (FUN_14071f950 packs the item lists
// into them, FUN_140720030 unpacks them, FUN_140720850 is the CRC over the three buffers). Member names are invented
// from use. Both classes derive from CPtred and have only the deleting destructor in their vftable.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/stream.h"

// The key of the stat map of CPCData (an enum-like id; only the low 16 bits go out on the wire).
enum Unk_PcMapKey : unsigned { };

class CPCData : public CPtred
{
public:
    CPCData();                                              // 0x14071e2f0
    virtual ~CPCData() = default;                           // 0x1407209c0 (deleting 0x140720b00); the exe dtor stores no vptr
    void FUN_14071e570(COutputStream& out);                 // write the record
    void FUN_14071ec80(CInputStream& in);                   // read the record
    MS2_LAYOUT_FRIEND;
    __int64 m_n18;                                          // +0x18
    __int64 m_n20;                                          // +0x20
    CStringW m_str28;                                       // +0x28
    short m_n30;                                            // +0x30
    int m_n34;                                              // +0x34
    int m_n38;                                              // +0x38
    int m_n3c;                                              // +0x3c
    int m_n40;                                              // +0x40
    int m_n44;                                              // +0x44 (a byte on the wire)
    unsigned char m_a48[0x118];                             // +0x48
    unsigned char m_a160[0x118];                            // +0x160
    unsigned char m_a278[0x118];                            // +0x278
    std::map<Unk_PcMapKey, int> m_map390;                  // +0x390 (key goes out as a short)
    CString m_str3a0;                                       // +0x3a0
    CStringW m_str3a8;                                      // +0x3a8
    CStringW m_str3b0;                                      // +0x3b0
    CStringW m_str3b8;                                      // +0x3b8
    CStringW m_str3c0;                                      // +0x3c0
    int m_n3c8;                                             // +0x3c8
    int m_n3cc;                                             // +0x3cc
    int m_n3d0;                                             // +0x3d0
    int m_n3d4;                                             // +0x3d4
    ATL::CAtlArray<int> m_arr3d8;                           // +0x3d8
    int m_n3f8;                                             // +0x3f8
    int m_n3fc;                                             // +0x3fc
    __int64 m_n400;                                         // +0x400
    int m_n408;                                             // +0x408
    int m_n40c;                                             // +0x40c
    int m_an410[2];                                         // +0x410
    int m_n418;                                             // +0x418 (a short on the wire)
    CStringW m_str420;                                      // +0x420
    CStringW m_str428;                                      // +0x428
    __int64 m_n430;                                         // +0x430
    __int64 m_n438;                                         // +0x438
};
MS2_CHECK_SIZE(CPCData, 0x440);
MS2_CHECK_OFFSET(CPCData, m_str28, 0x28);
MS2_CHECK_OFFSET(CPCData, m_a48, 0x48);
MS2_CHECK_OFFSET(CPCData, m_map390, 0x390);
MS2_CHECK_OFFSET(CPCData, m_arr3d8, 0x3d8);
MS2_CHECK_OFFSET(CPCData, m_an410, 0x410);
MS2_CHECK_OFFSET(CPCData, m_n418, 0x418);
MS2_CHECK_OFFSET(CPCData, m_str420, 0x420);

class CPCDataPack : public CPtred
{
public:
    typedef ATL::CAtlArray<MS2Ptr<CItem> > ItemArray;
    CPCDataPack();                                          // 0x14071f480
    virtual ~CPCDataPack();                                 // 0x14071f510 (deleting 0x140720b40)
    void FUN_14071f580(COutputStream& out);                 // write the three buffers
    void FUN_14071f710(CInputStream& in);                   // read the three buffers
    void FUN_14071f8a0(CPCData* pData);                     // fill the record from the first buffer
    void FUN_14071f920(CPCData* pData);                     // store the record into the first buffer
    void FUN_14071f950(const ItemArray& aEquip, const ItemArray& aExtra, const CMsTime& tmBegin, const CMsTime& tmEnd,
                       const ItemArray& aMore);             // pack the item lists
    void FUN_140720030(ItemArray& aEquip, ItemArray& aExtra, bool& bTimed, CMsTime& tmBegin, CMsTime& tmEnd,
                       ItemArray& aMore);                   // unpack the item lists
    int FUN_140720850();                                    // CRC32 of the three buffers, summed
    MS2_LAYOUT_FRIEND;
    __int64 m_n18;                                          // +0x18 (not set by the ctor)
    __int64 m_n20;                                          // +0x20
    __int64 m_n28;                                          // +0x28
    CByteBuffer m_bufRecord;                                // +0x30
    CByteBuffer m_bufItems;                                 // +0x70
    CByteBuffer m_bufExtra;                                 // +0xb0
};
MS2_CHECK_SIZE(CPCDataPack, 0xf0);
MS2_CHECK_OFFSET(CPCDataPack, m_bufRecord, 0x30);
MS2_CHECK_OFFSET(CPCDataPack, m_bufItems, 0x70);
MS2_CHECK_OFFSET(CPCDataPack, m_bufExtra, 0xb0);
