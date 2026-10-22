// timer.h - Timer (CPtred-derived poll timer, 0x38 bytes) and TimeRange (two CMsTime, 0x20 bytes). Owning unit:
// ?\timer.cpp (0x1408686b0-0x1408691c0). Header name assumed from the unit path; class names Timer (decompiler/RTTI of the
// vftable symbol) and TimeRange (invented). Method names are FUN_ addresses because other units already call them so.
#pragma once
#include <afx.h>
#include <atltime.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"
// stream.h pulls in ms2recover.h (needs MS2_THIS_FILE), so includers of this header get forward declarations only
class COutputStream;
class CInPacket;

namespace efd { class IClock; }

class Timer : public CPtred
{
public:
    Timer();                                    // 0x1408686b0
    virtual ~Timer();                           // 0x140868720 (scalar deleting 0x140868c90)
    void FUN_140868750(unsigned int ms);        // arm: expires ms from now
    void FUN_1408687c0();                       // arm with 0x3fffffff ms
    void FUN_1408687f0();                       // reset (period = 0, pause cleared)
    void FUN_140868820();                       // start = now - period (already elapsed)
    void FUN_140868850();                       // pause (remember now)
    void FUN_140868880();                       // resume (shift start/end by the paused span)
    __int64 FUN_1408688e0();                    // now in milliseconds (cached IClock 0xe001001b)
    float FUN_140868940();                      // elapsed / period, 1.0 once expired
    float FUN_1408689a0();                      // eased ratio (x + 2x capped at 1.0)
    int GetStart() const;                  // start time
    int FUN_140868a70();                        // elapsed milliseconds
    int FUN_140868ab0();                        // remaining milliseconds
    int FUN_140868af0() const;                  // period (1 if unset)
    float FUN_140868b20();                      // ratio delta since the last call
    int FUN_140868b80() const;                 // armed
    int FUN_140868ba0();                       // armed and not expired
    int FUN_140868c00();                       // expired
    int HasPauseTime() const;                 // paused

    int m_nPeriod;                  // +0x18
    int m_nStart;                   // +0x1c
    int m_nEnd;                     // +0x20
    int m_nPauseTime;               // +0x24
    float m_fLastRatio;             // +0x28
    efd::IClock* m_pClock;          // +0x30
};
MS2_CHECK_SIZE(Timer, 0x38);
MS2_CHECK_OFFSET(Timer, m_nPeriod, 0x18);
MS2_CHECK_OFFSET(Timer, m_nStart, 0x1c);
MS2_CHECK_OFFSET(Timer, m_nEnd, 0x20);
MS2_CHECK_OFFSET(Timer, m_nPauseTime, 0x24);
MS2_CHECK_OFFSET(Timer, m_fLastRatio, 0x28);
MS2_CHECK_OFFSET(Timer, m_pClock, 0x30);

class Unk_140165cf0;     // game TinyXML element

class TimeRange
{
public:
    TimeRange();                                                            // 0x140868cd0
    TimeRange(const CMsTime& start, const CMsTime& end);                    // 0x140868d10
    void FUN_140868d60(Unk_140165cf0* pNode);                               // load "startTime"/"endTime"
    void FUN_140868db0(COutputStream& out) const;                           // write
    void FUN_140868e70(CInPacket& in);                                      // read
    CMsTime& FUN_140868f20();                                               // start
    CMsTime& FUN_140868f40();                                               // end
    bool FUN_140868f60(const CMsTime& t) const;                             // start <= t < end
    bool FUN_140868fd0(const CMsTime& t, ATL::CTimeSpan before, ATL::CTimeSpan after) const;
    bool FUN_140869060() const;                                             // start <= end

    CMsTime m_start;                // +0x00
    CMsTime m_end;                  // +0x10
};
MS2_CHECK_SIZE(TimeRange, 0x20);
