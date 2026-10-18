// weddinghallticket.h - PLACEHOLDER for WeddingHallTicket (RTTI .?AVWeddingHallTicket@@, weddingproxy.cpp, 0xa0 bytes,
// vftable 0x142da7990 with the deleting dtor only): the value of the character's wedding hall ticket map,
// `std::map<unsigned __int64, WeddingHallTicket>`; the tree node is 0xc8 = 0x20 header + the 8-byte key + this.
// NOT an original header. Member names are invented except those of the ToString text (0x140900050). The copy ctor
// (0x140fc6060) and operator= (0x140fc6240) are defined in uiweddingbillboarddialog.cpp, the unit that first
// instantiated them.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class COutputStream;
class CInPacket;

class WeddingHallTicket : public CPtred
{
public:
    WeddingHallTicket();                            // 0x1408ff990
    WeddingHallTicket(const WeddingHallTicket& other);              // 0x140fc6060
    virtual ~WeddingHallTicket();                   // 0x1408ffa10 (??_G 0x140902340)
    WeddingHallTicket& operator=(const WeddingHallTicket& other);   // 0x140fc6240
    void Reset();                                   // 0x1408ffa80
    void Assign(const WeddingHallTicket& other);    // 0x1408ffb30
    void Write(COutputStream& out);                 // 0x1408ffc30
    void Read(CInPacket& in);                       // 0x1408ffd80
    CStringW ToString();                            // 0x140900050
    unsigned __int64 m_nWeddingHallSN;              // +0x18
    int m_nPackageId;                               // +0x20
    int m_nHallId;                                  // +0x24
    bool m_bPublic;                                 // +0x28
    unsigned __int64 m_nBookingAccSN;               // +0x30
    unsigned __int64 m_nBookingCharSN;              // +0x38
    __int64 m_nTime;                                // +0x40 the wedding time
    CStringW m_strGroom;                            // +0x48
    CStringW m_strBride;                            // +0x50
    WeddingHallReservationFee m_fee;                // +0x58
    unsigned int m_nReservationCouponId;            // +0x98
};
MS2_CHECK_OFFSET(WeddingHallTicket, m_nTime, 0x40);
MS2_CHECK_SIZE(WeddingHallTicket, 0xa0);
