// cnpcshopbuyperiod.h - PLACEHOLDER for CNpcShopBuyPeriod (RTTI .?AVCNpcShopBuyPeriod@@, CPtred-derived, 0x90 bytes:
// `operator new(0x90)` at 0x140db61a0, ctor 0x1406dc5a0, dtor 0x1406ef650 (??_G 0x1406f1000)): the period (dates, daily
// time ranges, week days) in which an NPC shop product can be bought. NOT an original header; the class is defined by
// commonfiles\npcshopdata.cpp (w514; startDate / endDate / partTime / dayOfWeek / onlyVisibleInPeriod of the shop xml).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/daytimerange.h"

class CInPacket;
class COutputStream;

// The daily buy windows are Unk_DayTimeRange (start / end second of the day; the CAtlArray<Unk_DayTimeRange> COMDATs
// the period calls are commonfiles\gameeventbase.cpp's: GetCount 0x1402e5330, operator[] 0x1402e4f00, Add 0x1402e51c0).

class CNpcShopBuyPeriod : public CPtred
{
public:
    CNpcShopBuyPeriod();                                    // 0x1406dc5a0
    // implicit dtor (COMDAT 0x1406ef650, ??_G 0x1406f1000)
    bool operator!=(const CNpcShopBuyPeriod& o);            // 0x1406dc660 (non-const: this uses the non-const operator[])
    bool FUN_1406dc810();                                   // after reading: compute the window around the server time
    void FUN_1406dc850(COutputStream& out);                 // write the period
    void FUN_1406dcb40(CInPacket& in);                      // read the period from a packet
    void FUN_1406dcde0(const CMsTime& tmFrom, const CMsTime& tmTo); // set the window, clipped to [start, end]
    void FUN_1406dcf10(const CMsTime& tmNow);               // compute the next buy window from tmNow
    bool FUN_1406dda70() const;                             // the period has a day / time-of-day restriction
    bool FUN_1406ddad0(const CMsTime& tm) const;            // tm is inside the current window
    bool FUN_1406ddb40(const CMsTime& tm) const;            // tm is outside the configured dates
    bool FUN_1406ddc30() const;                             // visible outside the period
    bool FUN_1406ddc50(const CMsTime& tmNow);               // visible now
    bool FUN_1406ddc90(const CMsTime& tmNow);               // tmNow is inside the period

    CMsTime m_tmWindowStart;                                // +0x18 the current buy window (FUN_1406dcf10)
    CMsTime m_tmWindowEnd;                                  // +0x28
    CMsTime m_tmStart;                                      // +0x38 first buyable moment (0: open)
    CMsTime m_tmEnd;                                        // +0x48 last buyable moment (0: open)
    ATL::CAtlArray<Unk_DayTimeRange> m_aPartTimes;          // +0x58 daily buy windows
    std::set<unsigned> m_setDays;                           // +0x78 week days
    bool m_bVisible;                                        // +0x88
};
MS2_CHECK_SIZE(CNpcShopBuyPeriod, 0x90);
MS2_CHECK_OFFSET(CNpcShopBuyPeriod, m_tmStart, 0x38);
MS2_CHECK_OFFSET(CNpcShopBuyPeriod, m_aPartTimes, 0x58);
MS2_CHECK_OFFSET(CNpcShopBuyPeriod, m_setDays, 0x78);
