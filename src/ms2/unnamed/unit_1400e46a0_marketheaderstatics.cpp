// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics (key input controller,
// market order/sort name tables, "skill"/"stun" labels and two small zero-initialised objects).
// MS2-UNIT: unit_1400e46a0
// MS2-RANGE: 0x1400e46a0-0x1400e4960 .text$di
// MS2-RANGE: 0x142cab6b0-0x142cab7a7 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"


// Statics of a header that several TUs include (the first group here belongs to one of them, the second to the next).
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static UICommon::CMyPCKeyInputController s_keyInput1;
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer2(NULL);
static CString s_strBuyTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
