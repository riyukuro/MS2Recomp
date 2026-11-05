// cubecraft_1_statics.h - the static of cubecraft.cpp#1 that sits between the shared header statics ("stun") and the
// condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION).
#pragma once

class Unk_BuddyHandle { public: Unk_BuddyHandle(void* p); void* m_p; };     // ctor 0x1401cd100

static Unk_BuddyHandle s_dat_143ace588(0);                                              // @0x1400e5b70
