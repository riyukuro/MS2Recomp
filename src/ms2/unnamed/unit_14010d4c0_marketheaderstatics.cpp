// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics of three neighbouring
// TUs: the market sort-type name table with skill/stun labels, null handle and condition object (twice), then a lone
// skill/stun label pair.
// MS2-UNIT: unit_14010d4c0
// MS2-RANGE: 0x14010d4c0-0x14010d840 .text$di
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))

// first TU's statics
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static egf::EntityID s_pointer1(0);                                              // @0x14010d5e0
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// next TU
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static egf::EntityID s_pointer2(0);                                              // @0x14010d770
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// next TU
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbb900-0x142cbba60 .text$yd
