// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers (and their atexit thunks) of the
// shared header statics of 2 TU(s) after ?\avatarpc.cpp (link order: unit_1409faff0 / basecollision / baseoption have no .text$di; which two own these is unknown).
// Split by ps1, left without owner; standalone per the gap2 orphan di sweep. The CU names are unknown.
// MS2-UNIT: unit_1400c28c0
// MS2-RANGE: 0x1400c28c0-0x1400c2b20 .text$di
// MS2-RANGE: 0x142c9ec70-0x142c9ed50 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

// TU 1
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInputController1;

// TU 2
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
