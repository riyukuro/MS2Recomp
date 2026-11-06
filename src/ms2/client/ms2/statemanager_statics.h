// statemanager_statics.h - the null pointer handle that sits between the shared header statics ("stun") and the
// condition object in statemanager.cpp (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION).
#pragma once

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_pointer(0);
