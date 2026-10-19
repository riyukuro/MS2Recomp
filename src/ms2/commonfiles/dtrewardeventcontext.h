// dtrewardeventcontext.h - CommonUserEvent::DTRewardEventContext (RTTI .?AVDTRewardEventContext@CommonUserEvent@@, 0x58
// bytes, ctor 0x14041bb00, dtor 0x14041bc60, deleting dtor 0x14041bdd0): the daily attendance reward event the user event
// manager hands to the UI. The +0x38 array holds the reward rows (EventStruct::DTReward, commonfiles/usereventcontext.h),
// filled by GameEventDTReward::FUN_14041b6e0. Member names after +0x30 are invented. Owning unit:
// ?\gameeventdtreward.cpp.
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/mstime.h"

namespace EventStruct { class DTReward; }

namespace CommonUserEvent {

class DTRewardEventContext : public CPtred
{
public:
    DTRewardEventContext(int id, const CMsTime& time);   // 0x14041bb00
    // The dtor (0x14041bc60: the array dtor, then CPtred) and its deleting dtor 0x14041bdd0 are implicit.

    int m_id;                       // +0x18 the key of CUserEventManager's reward map
    char m_pad_1c[4];
    CMsTime m_time;                 // +0x20 the event end time
    unsigned short m_level;         // +0x30
    unsigned char m_b32;            // +0x32
    unsigned char m_b33;            // +0x33
    char m_pad_34[4];
    ATL::CAtlArray<MS2Ptr<EventStruct::DTReward> > m_rewards;   // +0x38 the reward rows
};

}   // namespace CommonUserEvent
MS2_CHECK_SIZE(CommonUserEvent::DTRewardEventContext, 0x58);
MS2_CHECK_OFFSET(CommonUserEvent::DTRewardEventContext, m_level, 0x30);
MS2_CHECK_OFFSET(CommonUserEvent::DTRewardEventContext, m_rewards, 0x38);
