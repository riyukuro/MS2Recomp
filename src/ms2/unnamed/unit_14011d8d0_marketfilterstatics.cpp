// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Static market filter labels and controller data.
// MS2-UNIT: unit_14011d8d0
// MS2-RANGE: 0x14011d8d0-0x14011dbe0 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
// The statics of this TU: two copies of header_statics_a.h's set (sort names, skill/stun, the condition table), then a
// key-input controller. Atexit thunks 0x142cc2950-0x142cc2a90.
#include "ms2/placeholder/header_statics_a.h"
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142cc2950-0x142cc2a90 .text$yd
