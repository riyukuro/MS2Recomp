// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics of three neighbouring
// TUs: a null handle with a condition object, the market sort-type name table with its skill/stun labels, then another
// handle/condition pair and its own skill/stun labels.
// MS2-UNIT: unit_1401124f0
// MS2-RANGE: 0x1401124f0-0x140112750 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// first TU's statics
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// next TU
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";

// next TU
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// tail of the last TU's statics
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbda20-0x142cbdb10 .text$yd
