// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics of three neighbouring
// TUs: the skill/stun labels with a null handle, an XML/stream holder object, then the market sort-type name table with
// its own labels, handle and condition object.
// MS2-UNIT: unit_1401119b0
// MS2-RANGE: 0x1401119b0-0x140111bf0 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// first TU's statics
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);

// next TU
static UICommon::CMyPCKeyInputController s_keyInputController;

// next TU
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1401cd100 s_pointer3(NULL);
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbd4b0-0x142cbd5a0 .text$yd
