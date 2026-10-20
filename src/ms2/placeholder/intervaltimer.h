// intervaltimer.h - PLACEHOLDER for the game's 8-byte tick interval timer (real name unknown). NOT an original header.
// ctor 0x140517b00, Init 0x140268840 (arm: remember the tick), Check 0x140268870 (nonzero at most once per interval,
// re-arms). unit_140268010.cpp (the owner of Init/Check) and a few older units keep unit-local copies of the class
// (Unk_140517b00, Unk_AdTick, Unk_HlTimer, ...); new units include this one.
#pragma once

#include "ms2/ms2layout.h"

class Unk_IntervalTimer
{
public:
    Unk_IntervalTimer();                                        // 0x140517b00
    void Init();                                                // 0x140268840
    int Check(unsigned int nInterval);                          // 0x140268870
    // @0x1411f9230 (first emitted by equipment.cpp)
    unsigned int GetLast() const { return m_nLast; }

    unsigned int m_nInterval;
    unsigned int m_nLast;
};
MS2_CHECK_SIZE(Unk_IntervalTimer, 0x8);
