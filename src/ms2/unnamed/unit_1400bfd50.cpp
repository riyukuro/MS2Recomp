// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of three
// neighbouring TUs: a sort-type name table with its skill/stun pair and a condition table, the same group again, and a
// third name table whose skill/stun pair closes the block.
// MS2-UNIT: unit_1400bfd50
// MS2-RANGE: 0x1400bfd50-0x1400c0150 .text$di
// MS2-RANGE: 0x142c9d720-0x142c9d8c5 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include <efd/utf8string.h>

// first TU
static CString s_sortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// next TU
static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
// this TU also calls efd::utf8string::NullString(): its function-local `static utf8string ns` gets the atexit
// destructor 0x142c9d840 between the TU's statics and the next block
void Unk_1400bfd50_UsesNullString() { efd::utf8string::NullString(); }

// next TU
static CString s_sortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
// MS2-PIN: ??__Fns@?1??NullString@utf8string@efd@@SAAEBV12@XZ@YAXXZ 0x142c9d840 ; NullString local static atexit dtor (second block)
