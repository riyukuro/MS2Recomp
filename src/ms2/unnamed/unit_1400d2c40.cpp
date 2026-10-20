// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of several TUs that
// follow unit_1400d0510's pattern (condition table, sort-type name table, skill/stun pair, null handle), plus one
// null MS2Ptr-shaped handle (pointee type unknown). The CU names are unknown.
// MS2-UNIT: unit_1400d2c40
// MS2-RANGE: 0x1400d2c40-0x1400d3280 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
class Unk_HeldObject : public CPtred { };

// first TU
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static MS2Ptr<Unk_HeldObject> s_heldObject(0);

static CString s_strSortTypeNames4[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill4 = "skill";
static CString s_strStun4 = "stun";
static Unk_1401cd100 s_pointer4(NULL);
static Unk_1402a9d70 s_condition4(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames5[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill5 = "skill";
static CString s_strStun5 = "stun";
static Unk_1401cd100 s_pointer5(NULL);
static Unk_1402a9d70 s_condition5(17, 0.75f, 0.25f, 2.25f, 10);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4f10-0x142ca5020 .text$yd
// MS2-RANGE: 0x142ca5060-0x142ca5180 .text$yd
