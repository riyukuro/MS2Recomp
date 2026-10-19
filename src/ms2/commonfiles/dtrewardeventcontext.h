// dtrewardeventcontext.h - CommonUserEvent::DTRewardEventContext (RTTI .?AVDTRewardEventContext@CommonUserEvent@@, 0x58
// bytes, ctor 0x14041bb00, dtor 0x14041bc60, deleting dtor 0x14041bdd0): the daily attendance reward event the user event
// manager hands to the UI. Only the members the manager reads are named; the layout follows the third-party v2525
// decompile (+0x20 a 0x10 object, +0x38 a 0x20 ATL array). Owning unit: ?\gameeventdtreward.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

namespace CommonUserEvent {

class DTRewardEventContext : public CPtred
{
public:
    int m_id;                       // +0x18 the key of CUserEventManager's reward map
    char m_pad_1c[4];
    char m_pad_20[0x10];
    unsigned short m_level;         // +0x30
    char m_pad_32[0x58 - 0x32];
};

}   // namespace CommonUserEvent
MS2_CHECK_SIZE(CommonUserEvent::DTRewardEventContext, 0x58);
MS2_CHECK_OFFSET(CommonUserEvent::DTRewardEventContext, m_level, 0x30);
