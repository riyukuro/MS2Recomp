// unk_mergerange.h - the [min, max] int range shared by the item merge option records (citemmergeoptionproxy.h) and
// the guide-quest conditions (cguidecondition.h). NOT an original header; the real name is unknown.
// The exe uses one type: the same ctor (0x1405c38a0) builds both, and guideentity_9 calls the merge range's
// is-set check (0x1405c7ba0) on the condition's range.
#pragma once

#include "ms2/ms2layout.h"

// Inclusive value range (ctor 0x1405c38a0). A trigger range is valid when max >= min and not both 0.
struct Unk_MergeRange
{
    Unk_MergeRange() : m_nMin(0), m_nMax(0) {}
    void Set(int nMin, int nMax);                   // 0x1405c6380
    int m_nMin;
    int m_nMax;
};
MS2_CHECK_SIZE(Unk_MergeRange, 8);
