// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers (and their atexit thunks) of the
// shared header statics of 1 TU(s) between stringtable (complete set) and swoosheffectparam (no mn TU left in between: a TU with no own code).
// Split by ps1, left without owner; standalone per the gap2 orphan di sweep. The CU names are unknown.
// MS2-UNIT: unit_14010d120
// MS2-RANGE: 0x14010d120-0x14010d290 .text$di
// MS2-RANGE: 0x142cbb780-0x142cbb810 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

// TU 1
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
