// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics of neighbouring TUs:
// two market sort-type name tables (each with its own skill/stun labels and a condition object), the key-input
// controller singleton, three stray AS-property names, and a name/record registrar object.
// MS2-UNIT: unit_1400fa940
// MS2-RANGE: 0x1400fa940-0x1400fad30 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include <NiRTTI.h>

class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };   // C3: was Unk_1401cd100 (ctor 0x1401cd100)

// The TU's NiRTTI ctor lives out of line in the exe at 0x141d16b90 ([this]=name, [this+8]=base RTTI).

// first TU: the market sort-type name table with its labels and condition
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// next TU: the key-input controller singleton
static UICommon::CMyPCKeyInputController s_keyInputController;

// next TU: three AS-property names
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";

// next TU: the second sort-type name table, its labels, condition and registrar
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_BuddyHandle s_pointer(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// The TU's registration record; only its address is taken here.
static char s_registrarRecord[1];
static NiRTTI s_registrar("OutlineRenderStep", reinterpret_cast<const NiRTTI*>(s_registrarRecord));
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb3a70-0x142cb3c10 .text$yd
