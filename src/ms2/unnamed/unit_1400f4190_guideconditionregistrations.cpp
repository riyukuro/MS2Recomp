// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic initializers of the guide-condition TU: each
// CGuideCondition* class registers its factory with the ClassObject registry from a one-byte static, in exe order. The
// registrar call is a comma-expression initializer of a storage-less marker object, so the initializer is the call alone.
// MS2-UNIT: unit_1400f4190
// MS2-RANGE: 0x1400f4190-0x1400f4460 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/cguidecondition.h"

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp): the by-value name is consumed
// and destroyed by the callee. The factories below are defined by the TU's own code unit.
ClassObject* CreateObject();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist
// @0x1400f4190
static char s_regRealEstateExpireDays;
static Unk_RegMarker s_initRealEstateExpireDays =
    (((ClassObjectRegistrar*)&s_regRealEstateExpireDays)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionRealEstateExpireDays"), CGuideConditionRealEstateExpireDays::CreateObject), Unk_RegMarker());

// @0x1400f41e0
static char s_regReturnPortal;
static Unk_RegMarker s_initReturnPortal =
    (((ClassObjectRegistrar*)&s_regReturnPortal)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionReturnPortal"), CGuideConditionReturnPortal::CreateObject), Unk_RegMarker());

// @0x1400f4230
static char s_regSelectItemEnchant;
static Unk_RegMarker s_initSelectItemEnchant =
    (((ClassObjectRegistrar*)&s_regSelectItemEnchant)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionSelectItemEnchant"), CGuideConditionSelectItemEnchant::CreateObject), Unk_RegMarker());

// @0x1400f4280
static char s_regServerTime;
static Unk_RegMarker s_initServerTime =
    (((ClassObjectRegistrar*)&s_regServerTime)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionServerTime"), CGuideConditionServerTime::CreateObject), Unk_RegMarker());

// @0x1400f42d0
static char s_regState;
static Unk_RegMarker s_initState =
    (((ClassObjectRegistrar*)&s_regState)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionState"), CGuideConditionState::CreateObject), Unk_RegMarker());

// @0x1400f4320
static char s_regSubJobCode;
static Unk_RegMarker s_initSubJobCode =
    (((ClassObjectRegistrar*)&s_regSubJobCode)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionSubJobCode"), CreateObject), Unk_RegMarker());

// @0x1400f4370
static char s_regSummonPet;
static Unk_RegMarker s_initSummonPet =
    (((ClassObjectRegistrar*)&s_regSummonPet)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionSummonPet"), CGuideConditionSummonPet::CreateObject), Unk_RegMarker());

// @0x1400f43c0
static char s_regTimeout;
static Unk_RegMarker s_initTimeout =
    (((ClassObjectRegistrar*)&s_regTimeout)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionTimeout"), CGuideConditionTimeout::CreateObject), Unk_RegMarker());

// @0x1400f4410
static char s_regTitle;
static Unk_RegMarker s_initTitle =
    (((ClassObjectRegistrar*)&s_regTitle)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionTitle"), CGuideConditionTitle::CreateObject), Unk_RegMarker());
#endif
