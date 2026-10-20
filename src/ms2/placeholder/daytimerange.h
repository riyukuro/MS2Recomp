// daytimerange.h - Unk_DayTimeRange: a start / end second of the day (two Unk_DayTime). Moved out of
// commonfiles\gameevent.h (w514) so that the NPC shop buy period (cnpcshopbuyperiod.h, its part times) can use it
// without pulling in gameevent.h. The COMDATs belong to commonfiles\gameeventbase.cpp (first instantiation).
#pragma once
#include "ms2/commonfiles/timeutil.h"

// Start / end second of the day (two Unk_DayTime).
struct Unk_DayTimeRange {
    typedef Unk_DayTime ValueType;      // not exe code: the token type of the "a,b" reader
    // @0x1402e4a60
    Unk_DayTimeRange() : m_start(0), m_end(0) {}
    // @0x1402e4a30
    Unk_DayTimeRange(Unk_DayTime start, Unk_DayTime end) : m_start(start), m_end(end) {}
    void Init(Unk_DayTime start, Unk_DayTime end);
    bool Contains(Unk_DayTime time) const;                // 0x1404a4160 (start <= time < end)
    // @0x1406eff80 (first used by commonfiles\npcshopdata.cpp)
    bool operator!=(const Unk_DayTimeRange& o) const
    {
        if (m_start != o.m_start) return true;
        if (m_end != o.m_end) return true;
        return false;
    }
    Unk_DayTime m_start;
    Unk_DayTime m_end;
};
// The code of Unk_GameEventIntRange::Init (identical, folded into 0x1403eeaf0). Defined out of the class so that its
// first line is outside the tag window of the ctor's @0x1402e4a30 above (tools/progress.py would pair it there).
inline void Unk_DayTimeRange::Init(Unk_DayTime start, Unk_DayTime end) { m_start = start; m_end = end; }
