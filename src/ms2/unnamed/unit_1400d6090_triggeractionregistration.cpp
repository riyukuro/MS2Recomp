// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of several
// neighbouring TUs (skill/stun labels, null handles, condition tables and sort-type name tables), ending with the
// TriggerActionCli class-object registration.
// MS2-UNIT: unit_1400d6090
// MS2-RANGE: 0x1400d6090-0x1400d66e0 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/unk_1402a9d70.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factory is defined by the
// TriggerActionCli code unit.
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
ClassObject* FUN_140de4cb0();

// first TU
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// second TU
static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// third TU
static CString s_sortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1401cd100 s_pointer3(NULL);
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);

// fourth TU
static CString s_sortTypeNames4[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortTypeNames5[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill4 = "skill";
static CString s_strStun4 = "stun";
static Unk_1402a9d70 s_condition4(17, 0.75f, 0.25f, 2.25f, 10);

struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist
// @0x1400d6690
static char s_regTriggerAction;
static Unk_RegMarker s_initTriggerAction =
    (FUN_140316aa0(&s_regTriggerAction, CStringW(L"TriggerActionCli"), FUN_140de4cb0), Unk_RegMarker());
#endif
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca5c90-0x142ca5ed0 .text$yd
