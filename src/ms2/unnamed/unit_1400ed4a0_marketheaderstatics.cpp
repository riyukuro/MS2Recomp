// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of two
// neighbouring TUs: a skill/stun label pair with a condition table in front of it, then two sort-type name tables
// with their own skill/stun pairs, a null handle and a second condition table.
// MS2-UNIT: unit_1400ed4a0
// MS2-RANGE: 0x1400ed4a0-0x1400ed7a0 .text$di
// MS2-RANGE: 0x142caf200-0x142caf320 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// first TU
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// next TU
static CString s_sortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer3(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
