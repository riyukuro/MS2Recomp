// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of several
// neighbouring TUs: skill/stun name pairs (a header shared by the TUs), a null handle, a three-int settings default, a
// sort-type name table, a condition table and CMirrored3DRenderView's RTTI descriptor. The CU names are unknown.
// MS2-UNIT: unit_1400f7d50
// MS2-RANGE: 0x1400f7d50-0x1400f8050 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/mirrored3drenderview.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// {0x11, 0x32, 1} by its out-of-line default constructor.
class Unk_141481440 { public: Unk_141481440(); private: int m_n0; int m_n1; int m_n2; };

// first TU
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_141481440 s_defaults;

// second TU
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);

// third TU
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
NiImplementRTTI(CMirrored3DRenderView, Ni3DRenderView);

// fourth TU
static CString s_strSkill4 = "skill";
static CString s_strStun4 = "stun";
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2850-0x142cb2920 .text$yd
// MS2-RANGE: 0x142cb2940-0x142cb29c0 .text$yd
