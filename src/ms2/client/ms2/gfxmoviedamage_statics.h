// gfxmoviedamage_statics.h - the static of gfxmoviedamage.cpp that sits between the shared header statics ("stun") and the
// condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION): a null handle (same shape as
// reactor_statics.h).
#pragma once

class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); void* m_p; };     // ctor 0x1401cd100 (C3: was Unk_Handle1401cd100)

static Unk_BuddyHandle s_dat_143abb128(0);                                           // @0x1400c8340
