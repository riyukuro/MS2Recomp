// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics: null handles, condition
// objects, key input controllers and market sort-name tables with "skill"/"stun" labels.
// MS2-UNIT: unit_1400dd530
// MS2-RANGE: 0x1400dd530-0x1400dd850 .text$di
// MS2-RANGE: 0x142ca8a80-0x142ca8ba0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static Unk_1401cd100 s_pointer0(NULL);
static Unk_1402a9d70 s_condition0(17, 0.75f, 0.25f, 2.25f, 10);

static UICommon::CMyPCKeyInputController s_keyInput1;
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static UICommon::CMyPCKeyInputController s_keyInput2;
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
