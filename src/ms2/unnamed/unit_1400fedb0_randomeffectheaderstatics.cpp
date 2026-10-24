// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics: a full header_statics_a.h
// group with a null handle before the condition, the CRandomEffect RTTI, and a second group (skill/stun, the table, skill/stun, condition).
// MS2-UNIT: unit_1400fedb0
// MS2-RANGE: 0x1400fedb0-0x1400ff140 .text$di
// MS2-RANGE: 0x142cb5bd0-0x142cb5d30 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ninode.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

#ifndef MS2_HOOK_DLL
class CRandomEffect { public: static const NiRTTI ms_RTTI; };
extern const NiRTTI DAT_143ad1568;   // CEffect::ms_RTTI
const NiRTTI CRandomEffect::ms_RTTI("CRandomEffect", &DAT_143ad1568);
#endif

static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);
