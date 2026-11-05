// reactor_statics.h - the static of reactor.cpp that sits between the shared header statics ("stun") and the
// condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION). Same shape as cubecraft_1_statics.h.
#pragma once

class Unk_BuddyHandle { public: Unk_BuddyHandle(void* p); void* m_p; };     // ctor 0x1401cd100

static Unk_BuddyHandle s_dat_143abc968(0);                                              // @0x1400c8ec0
