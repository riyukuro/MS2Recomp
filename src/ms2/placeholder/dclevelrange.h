// Unk_DcLevelRange: moved out of client/ms2/uidungeoncategory.h so commonfiles\questdata (CQuestData::Grade) can embed it.
#pragma once
#include "ms2/ms2layout.h"

// The "level" attribute of a sub tab ("low-high"). Out-of-unit members; IsValid is an inline COMDAT of this unit.
class Unk_DcLevelRange
{
public:
    Unk_DcLevelRange();                                         // 0x140757bd0
    bool operator!=(const Unk_DcLevelRange& o) const;           // 0x140759050
    void FUN_14075bc80(unsigned short nLow, unsigned short nHigh);   // set
    bool FUN_1407790a0() const;                                 // both ends are 0 (rewardcontentstable.cpp)
    bool FUN_1407790e0(unsigned short nLevel) const;            // nLow <= nLevel <= nHigh
    bool IsValid() const                                        // 0x140c0e770
    {
        if (m_nLow > m_nHigh)
            return false;
        if (m_nLow == 0 && m_nHigh == 0)
            return false;
        return true;
    }

    unsigned short m_nLow;                                      // +0x0
    unsigned short m_nHigh;                                     // +0x2
};
MS2_CHECK_SIZE(Unk_DcLevelRange, 4);
