// uihidesettingdialog_statics.h - the static of uihidesettingdialog.cpp that sits between the shared header statics
// ("stun") and the condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION). Same shape as
// reactor_statics.h.
#pragma once
class Unk_BuddyHandle { public: Unk_BuddyHandle(void* p); void* m_p; };     // ctor 0x1401cd100
static Unk_BuddyHandle s_dat_143af2de8(0);                                              // @0x140114a00
