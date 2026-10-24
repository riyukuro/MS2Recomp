// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of several TUs that
// follow unit_1400d0510's pattern (sort-type name tables of 7 or 8 entries, skill/stun pair, condition table, null handle,
// key-input controller). The CU names and exact TU boundaries are unknown; statics are listed in initializer order.
// MS2-UNIT: unit_1400f0a70
// MS2-RANGE: 0x1400f0a70-0x1400f1000 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames2[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames4[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

static CString s_strSortTypeNames5[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb0840-0x142cb0a10 .text$yd
