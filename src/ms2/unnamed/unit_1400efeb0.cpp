// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics of three neighbouring
// TUs, each the market sort-type name table with skill/stun labels, a condition object and a PC key-input controller.
// MS2-UNIT: unit_1400efeb0
// MS2-RANGE: 0x1400efeb0-0x1400f0390 .text$di
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

// first TU's statics
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController1;

// next TU
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController2;

// next TU
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController3;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb0360-0x142cb0570 .text$yd
