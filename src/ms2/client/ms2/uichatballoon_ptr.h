// uichatballoon_ptr.h - the pointer handle static the uichatballoon unit's header statics hold between "stun" and the
// condition (initialised by 0x1401cd100 with NULL). NOT an original header.
#pragma once
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_pointer1401cd100(0);
