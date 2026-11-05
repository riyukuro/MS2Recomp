// cinematiccomponent_statics.h - the static of cinematiccomponent.cpp that sits between the shared header statics ("stun")
// and the condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION). Same shape as reactor_statics.h.
#pragma once

class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };   // ctor 0x1401cd100 (C3: was Unk_Handle1401cd100)

static Unk_BuddyHandle s_dat_143acd5c8(NULL);                                              // @0x1400e5290
