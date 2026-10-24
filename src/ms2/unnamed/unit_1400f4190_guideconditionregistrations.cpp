// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic initializers of the guide-condition TU: each
// CGuideCondition* class registers its factory with the ClassObject registry from a one-byte static, in exe order. The
// registrar call is a comma-expression initializer of a storage-less marker object, so the initializer is the call alone.
// MS2-UNIT: unit_1400f4190
// MS2-RANGE: 0x1400f4190-0x1400f4460 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp): the by-value name is consumed
// and destroyed by the callee. The factories below are defined by the TU's own code unit.
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
ClassObject* FUN_1413ad4c0();
ClassObject* FUN_1413a6bc0();
ClassObject* FUN_1413ae0c0();
ClassObject* FUN_1413ac790();
ClassObject* FUN_1413a73a0();
ClassObject* FUN_1413ad950();
ClassObject* FUN_1413adc60();
ClassObject* FUN_1413a5e90();
ClassObject* FUN_1413ac5f0();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist
// @0x1400f4190
static char s_regRealEstateExpireDays;
static Unk_RegMarker s_initRealEstateExpireDays =
    (FUN_140316aa0(&s_regRealEstateExpireDays, CStringW(L"CGuideConditionRealEstateExpireDays"), FUN_1413ad4c0), Unk_RegMarker());

// @0x1400f41e0
static char s_regReturnPortal;
static Unk_RegMarker s_initReturnPortal =
    (FUN_140316aa0(&s_regReturnPortal, CStringW(L"CGuideConditionReturnPortal"), FUN_1413a6bc0), Unk_RegMarker());

// @0x1400f4230
static char s_regSelectItemEnchant;
static Unk_RegMarker s_initSelectItemEnchant =
    (FUN_140316aa0(&s_regSelectItemEnchant, CStringW(L"CGuideConditionSelectItemEnchant"), FUN_1413ae0c0), Unk_RegMarker());

// @0x1400f4280
static char s_regServerTime;
static Unk_RegMarker s_initServerTime =
    (FUN_140316aa0(&s_regServerTime, CStringW(L"CGuideConditionServerTime"), FUN_1413ac790), Unk_RegMarker());

// @0x1400f42d0
static char s_regState;
static Unk_RegMarker s_initState =
    (FUN_140316aa0(&s_regState, CStringW(L"CGuideConditionState"), FUN_1413a73a0), Unk_RegMarker());

// @0x1400f4320
static char s_regSubJobCode;
static Unk_RegMarker s_initSubJobCode =
    (FUN_140316aa0(&s_regSubJobCode, CStringW(L"CGuideConditionSubJobCode"), FUN_1413ad950), Unk_RegMarker());

// @0x1400f4370
static char s_regSummonPet;
static Unk_RegMarker s_initSummonPet =
    (FUN_140316aa0(&s_regSummonPet, CStringW(L"CGuideConditionSummonPet"), FUN_1413adc60), Unk_RegMarker());

// @0x1400f43c0
static char s_regTimeout;
static Unk_RegMarker s_initTimeout =
    (FUN_140316aa0(&s_regTimeout, CStringW(L"CGuideConditionTimeout"), FUN_1413a5e90), Unk_RegMarker());

// @0x1400f4410
static char s_regTitle;
static Unk_RegMarker s_initTitle =
    (FUN_140316aa0(&s_regTitle, CStringW(L"CGuideConditionTitle"), FUN_1413ac5f0), Unk_RegMarker());
#endif
