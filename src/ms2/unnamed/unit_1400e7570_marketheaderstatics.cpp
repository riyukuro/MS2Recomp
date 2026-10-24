// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics of three neighbouring TUs:
// skill/stun labels with a null handle, a sort-type table with labels, and the same with two null handles.
// MS2-UNIT: unit_1400e7570
// MS2-RANGE: 0x1400e7570-0x1400e7870 .text$di
// MS2-RANGE: 0x142cacb80-0x142cacca0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// tail of one TU's statics
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);

// next TU
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";

// next TU
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1401cd100 s_pointer3(NULL);
static Unk_1401cd100 s_pointer4(NULL);
