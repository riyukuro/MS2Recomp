// uichatballoon_ptr.h - the pointer handle static the uichatballoon unit's header statics hold between "stun" and the
// condition (initialised by 0x1401cd100 with NULL). NOT an original header.
#pragma once
class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };
static Unk_BuddyHandle s_pointer1401cd100(NULL);
