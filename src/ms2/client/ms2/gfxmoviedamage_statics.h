// gfxmoviedamage_statics.h - the static of gfxmoviedamage.cpp that sits between the shared header statics ("stun") and the
// condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION): a null handle (same shape as
// reactor_statics.h).
#pragma once

class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100

static Unk_Handle1401cd100 s_dat_143abb128(0);                                       // @0x1400c8340
