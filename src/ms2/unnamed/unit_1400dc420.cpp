// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of two TUs that
// follow unit_1400d0510's pattern (condition table, key-input controller; the first also has the jobCode/sortValue/tabIndex
// name strings, the sort-type name table and the skill/stun pair). The CU names are unknown.
// MS2-UNIT: unit_1400dc420
// MS2-RANGE: 0x1400dc420-0x1400dc6d0 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

// first TU
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput1;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// second TU
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput2;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca8310-0x142ca8460 .text$yd
