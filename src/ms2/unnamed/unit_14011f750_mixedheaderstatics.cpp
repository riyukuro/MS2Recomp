// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of three TUs that
// follow unit_1400d0510's pattern (null handle, condition table, key-input controller, sort-type name table with a
// skill/stun pair), the middle one also holding CVibrateEffect's RTTI descriptor. The CU names are unknown.
// MS2-UNIT: unit_14011f750
// MS2-RANGE: 0x14011f750-0x14011fa90 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <NiRTTI.h>
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// first TU
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";

// second TU
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
#ifndef MS2_HOOK_DLL
class CVibrateEffect { public: static const NiRTTI ms_RTTI; };
extern const NiRTTI DAT_143ad1568;   // CEffect::ms_RTTI
const NiRTTI CVibrateEffect::ms_RTTI("CVibrateEffect", &DAT_143ad1568);
#endif
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";

// third TU
static Unk_1401cd100 s_pointer3(NULL);
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc35a0-0x142cc36f0 .text$yd
