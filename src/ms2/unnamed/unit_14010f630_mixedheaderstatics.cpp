// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics: a null handle and a
// condition object, a key input controller and a full header_statics_a.h-style group, then another group closing with a hash map.
// MS2-UNIT: unit_14010f630
// MS2-RANGE: 0x14010f630-0x14010fa00 .text$di
// MS2-RANGE: 0x142cbc660-0x142cbc7c0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include <atlcoll.h>

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static Unk_1401cd100 s_pointer0(NULL);
static Unk_1402a9d70 s_condition0(17, 0.75f, 0.25f, 2.25f, 10);

static UICommon::CMyPCKeyInputController s_keyInput1;
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static ATL::CAtlMap<int, int> s_map2(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbc7c0-0x142cbc7e0 .text$yd
