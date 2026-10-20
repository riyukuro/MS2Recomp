// notifykeytable.h - PLACEHOLDER for the two key-table notifications that UIMainPlayerInfo listens to (RTTI
// NotifyShortkeyPage / NotifySkillSetMode, both NotifyObject). NOT an original header. Ctors 0x141435590 / 0x1414355e0
// belong to client\ms2\keytable.cpp (unrecovered): only the fields UIMainPlayerInfo reads are modelled.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/notifyobject.h"

// The shortkey page changed: the page before and after (0-based).
class NotifyShortkeyPage : public NotifyObject
{
public:
    NotifyShortkeyPage(int nPrev, int nCur);        // 0x141435590 / 0x1414355e0 (one of them)
    virtual ~NotifyShortkeyPage() = default;                 // compiler-generated (no vptr reset)
    virtual CStringW vfunc_1();
    int m_nPrev;                                    // +0x18
    int m_nCur;                                     // +0x1c
};
MS2_CHECK_SIZE(NotifyShortkeyPage, 0x20);

// The skill set mode switched (byte at +0x18: 0 = the page buttons stay enabled).
class NotifySkillSetMode : public NotifyObject
{
public:
    explicit NotifySkillSetMode(bool bMode);
    virtual ~NotifySkillSetMode() = default;                 // compiler-generated (no vptr reset)
    virtual CStringW vfunc_1();
    bool m_bMode;                                   // +0x18
};
MS2_CHECK_SIZE(NotifySkillSetMode, 0x20);
