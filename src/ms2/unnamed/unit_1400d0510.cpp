// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of three
// neighbouring TUs: a sort-type name table with a skill/stun pair, a condition table and a key-input controller, a
// lone skill/stun pair, then a sort-type name table with its own skill/stun pair, a null handle and a condition table.
// MS2-UNIT: unit_1400d0510
// MS2-RANGE: 0x1400d0510-0x1400d08a0 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// first TU
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput1;

// next TU
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";

// next TU
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4180-0x142ca4300 .text$yd
