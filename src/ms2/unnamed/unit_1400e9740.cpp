// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of four TUs that
// follow unit_1400d0510's pattern (condition table, sort-type name table, skill/stun pair, null handle), the first of
// them also holding CFogEffect's RTTI descriptor. The CU names are unknown.
// MS2-UNIT: unit_1400e9740
// MS2-RANGE: 0x1400e9740-0x1400e9c70 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <NiRTTI.h>
#include "ms2/placeholder/unk_1402a9d70.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// first TU
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);

// second TU
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
#ifndef MS2_HOOK_DLL
class CFogEffect { public: static const NiRTTI ms_RTTI; };
extern const NiRTTI DAT_143ad1568;   // CEffect::ms_RTTI
const NiRTTI CFogEffect::ms_RTTI("CFogEffect", &DAT_143ad1568);
#endif
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer2(NULL);

// third TU
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1401cd100 s_pointer3(NULL);

// fourth TU
static Unk_1402a9d70 s_condition4(17, 0.75f, 0.25f, 2.25f, 10);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cada10-0x142cadbe0 .text$yd
