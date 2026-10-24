// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics: the tail of one TU's
// header_statics_a.h group (the condition object), a full group, and the next TU's sort-type table with its own group.
// MS2-UNIT: unit_1400c36d0
// MS2-RANGE: 0x1400c36d0-0x1400c3a20 .text$di
// MS2-RANGE: 0x142c9f170-0x142c9f2a5 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_condition0@@YAXXZ 0x1400c36d0 ; prop
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400c3840 ; prop
// MS2-PIN: ??__Es_condition2@@YAXXZ 0x1400c39d0 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_strSortTypeNames@@YAXXZ 0x1400c3720
// MS2-PIN: ??__Fs_strSortTypeNames@@YAXXZ 0x142c9f190
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// the condition object closing the previous TU's header_statics_a.h group
static Unk_1402a9d70 s_condition0(17, 0.75f, 0.25f, 2.25f, 10);

// a TU whose own statics follow the shared header
#include "ms2/placeholder/header_statics_a.h"

// the next TU: its sort-type table (the same list), then the same shared group with a null handle before the condition
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
