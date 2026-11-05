// avatarpc_statics.h - the static of avatarpc.cpp (AvatarPC part) that sits between the shared header statics ("stun")
// and the condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION).
#pragma once

class Unk_BuddyHandle { public: Unk_BuddyHandle(void* p); void* m_p; };     // ctor 0x1401cd100

static Unk_BuddyHandle s_dat_143ab4c58(0);                                              // @0x1400c2580
