// ssquickentry.h - PLACEHOLDER for the quick slot binding of one slot (name unrecovered, no RTTI). NOT an original header.
// 0x18 bytes, ctor 0x141253e20 (inline): a skill, or an item id + uid. Shared by gameoptioninputdefault.h (the saved key
// settings) and skillslot.cpp (the quick slot manager); ckeytable.h forward-declares it.
#pragma once
#include "ms2/ms2layout.h"

struct Unk_SsQuickEntry
{
    int m_nSkillId;                                                 // +0x00
    __int64 m_nItemUid;                                             // +0x08
    int m_nItemId;                                                  // +0x10
    Unk_SsQuickEntry() : m_nSkillId(0), m_nItemUid(0), m_nItemId(0) {}   // 0x141253e20
};
MS2_CHECK_SIZE(Unk_SsQuickEntry, 0x18);
