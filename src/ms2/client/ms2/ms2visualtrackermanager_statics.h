// ms2visualtrackermanager_statics.h - the two statics of ms2visualtrackermanager.cpp that sit between the shared
// header statics ("stun") and the condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION).
#pragma once

#include <efd/Category.h>

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))

// The channel the tracker subscribes to (0x143ae0f38, dtor thunk 0x142cb33c0).
static efd::Category s_visualTrackerCategory(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);        // @0x1400f9a20
static egf::EntityID s_dat_143ae0ee8(0);                                              // @0x1400f9a50
