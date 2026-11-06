// decoeditservice_statics.h - the statics that sit between the shared header statics ("stun") and the condition object
// in decoeditservice.cpp (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION): the message
// category of the service and the null pointer handle.
#pragma once

static const efd::Category s_cat(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_pointer(0);
