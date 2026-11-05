// decoeditservice_statics.h - the statics that sit between the shared header statics ("stun") and the condition object
// in decoeditservice.cpp (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION): the message
// category of the service and the null pointer handle.
#pragma once

static const efd::Category s_cat(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };   // ctor 0x1401cd100 (C3: was Unk_1401cd100)
static Unk_BuddyHandle s_pointer(NULL);
