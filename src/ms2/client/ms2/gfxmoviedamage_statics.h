// gfxmoviedamage_statics.h - the static of gfxmoviedamage.cpp that sits between the shared header statics ("stun") and the
// condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION): a null handle (same shape as
// reactor_statics.h).
#pragma once

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))

static egf::EntityID s_dat_143abb128(0);                                             // @0x1400c8340
