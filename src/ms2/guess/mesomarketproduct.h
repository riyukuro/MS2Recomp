// mesomarketproduct.h - CMesoMarketProduct (RTTI .?AVCMesoMarketProduct@@, vftable 0x142d78378, only the deleting dtor
// in slot 0): a CPtred-derived Meso-Market listing record (three 64-bit values, two CMsTime dates and one flag) with a
// Write/Read pair on the game's output/input streams. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit
// is `?\mesomarketproduct.cpp` (0x1406aeaf0-0x1406aee80 .text$mn). Header name assumed; member and method names invented
// (the class is a value record; the client-side CMesoMarketProductCli derives from it).
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"


class CMesoMarketProduct : public CPtred
{
public:
    CMesoMarketProduct();                               // 0x1406aeaf0
    virtual ~CMesoMarketProduct();                      // 0x1406aeb90 (??_G 0x1406aee40)
    void Write(COutputStream& out);                     // 0x1406aec40
    void Read(CInputStream& in);                        // 0x1406aed20
    __int64 GetValue18();                               // 0x1406aebc0
    __int64 GetUnitPrice();                             // 0x1406aebe0: m_n28 / (m_n20 / constants->value)

    __int64 m_n18;                                      // +0x18
    __int64 m_n20;                                      // +0x20
    __int64 m_n28;                                      // +0x28
    CMsTime m_30;                                       // +0x30
    CMsTime m_40;                                       // +0x40
    bool m_b50;                                         // +0x50
};
MS2_CHECK_SIZE(CMesoMarketProduct, 0x58);
MS2_CHECK_OFFSET(CMesoMarketProduct, m_n18, 0x18);
MS2_CHECK_OFFSET(CMesoMarketProduct, m_30, 0x30);
MS2_CHECK_OFFSET(CMesoMarketProduct, m_40, 0x40);
MS2_CHECK_OFFSET(CMesoMarketProduct, m_b50, 0x50);

CInputStream& operator>>(CInputStream& in, CMesoMarketProduct& product);         // 0x1406aede0
COutputStream& operator<<(COutputStream& out, CMesoMarketProduct& product);      // 0x1406aee10
