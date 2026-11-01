// ms2visualtrackermanager_statics.h - the two statics of ms2visualtrackermanager.cpp that sit between the shared
// header statics ("stun") and the condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION).
#pragma once

#include <efd/Category.h>

class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };   // C3: was Unk_Handle1401cd100 (ctor 0x1401cd100)

// The channel the tracker subscribes to (0x143ae0f38, dtor thunk 0x142cb33c0).
static efd::Category s_visualTrackerCategory(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);        // @0x1400f9a20
static Unk_BuddyHandle s_dat_143ae0ee8(NULL);                                              // @0x1400f9a50
