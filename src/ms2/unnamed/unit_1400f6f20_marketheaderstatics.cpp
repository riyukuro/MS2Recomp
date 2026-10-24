// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the market TU's header statics: the
// pointer and condition objects closing one copy, then two more copies of the sort-type name table ("None".."EnumEnd")
// with their "skill"/"stun" labels and condition object (the first of them also has a null-handle object).
// MS2-UNIT: unit_1400f6f20
// MS2-RANGE: 0x1400f6f20-0x1400f7290 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2320-0x142cb2460 .text$yd
