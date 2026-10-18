// weddingguest.h - PLACEHOLDER for WeddingGuest (RTTI .?AVWeddingGuest@@, weddingproxy.cpp, 0x38 bytes, vftable with the
// deleting dtor only): one guest of a wedding. NOT an original header; member names are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class COutputStream;
class CInPacket;

class WeddingGuest : public CPtred
{
public:
    WeddingGuest();                                         // 0x1409002b0
    virtual ~WeddingGuest();                                // 0x140900310 (??_G 0x140902300)
    void Assign(const WeddingGuest& other);                 // 0x140900350
    void Write(COutputStream& out);                         // 0x1409003c0
    void Read(CInPacket& in);                               // 0x140900450

    unsigned int m_nKind;                                   // +0x18 (written as a short)
    __int64 m_n20;                                          // +0x20
    __int64 m_n28;                                          // +0x28
    CStringW m_strName;                                     // +0x30
};
MS2_CHECK_OFFSET(WeddingGuest, m_strName, 0x30);
MS2_CHECK_SIZE(WeddingGuest, 0x38);
