// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic initializers of ten CGuideCondition* classes (GuideClear
// .. Interactable): each registers its factory with the ClassObject registry from a one-byte static, in exe order (see
// unit_1400f4190 for the pattern).
// MS2-UNIT: unit_1400f36f0
// MS2-RANGE: 0x1400f36f0-0x1400f3a10 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/cguidecondition.h"

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factories are the
// CreateObject members of cguidecondition.h (HomeMode's stays a stand-in).
ClassObject* FUN_1413af740();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist
// @0x1400f36f0
static char s_regGuideClear;
static Unk_RegMarker s_initGuideClear =
    (((ClassObjectRegistrar*)&s_regGuideClear)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionGuideClear"), &CGuideConditionGuideClear::CreateObject), Unk_RegMarker());

// @0x1400f3740
static char s_regGuideOpen;
static Unk_RegMarker s_initGuideOpen =
    (((ClassObjectRegistrar*)&s_regGuideOpen)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionGuideOpen"), &CGuideConditionGuideOpen::CreateObject), Unk_RegMarker());

// @0x1400f3790
static char s_regGuildPvpPeriod;
static Unk_RegMarker s_initGuildPvpPeriod =
    (((ClassObjectRegistrar*)&s_regGuildPvpPeriod)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionGuildPvpPeriod"), &CGuideConditionGuildPvpPeriod::CreateObject), Unk_RegMarker());

// @0x1400f37e0
static char s_regHasManufacture;
static Unk_RegMarker s_initHasManufacture =
    (((ClassObjectRegistrar*)&s_regHasManufacture)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionHasManufacture"), &CGuideConditionHasManufacture::CreateObject), Unk_RegMarker());

// @0x1400f3830
static char s_regHasMoney;
static Unk_RegMarker s_initHasMoney =
    (((ClassObjectRegistrar*)&s_regHasMoney)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionHasMoney"), &CGuideConditionHasMoney::CreateObject), Unk_RegMarker());

// @0x1400f3880
static char s_regHasStatPoint;
static Unk_RegMarker s_initHasStatPoint =
    (((ClassObjectRegistrar*)&s_regHasStatPoint)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionHasStatPoint"), &CGuideConditionHasStatPoint::CreateObject), Unk_RegMarker());

// @0x1400f38d0
static char s_regHomeMode;
static Unk_RegMarker s_initHomeMode =
    (((ClassObjectRegistrar*)&s_regHomeMode)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionHomeMode"), FUN_1413af740), Unk_RegMarker());

// @0x1400f3920
static char s_regInput;
static Unk_RegMarker s_initInput =
    (((ClassObjectRegistrar*)&s_regInput)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionInput"), &CGuideConditionInput::CreateObject), Unk_RegMarker());

// @0x1400f3970
static char s_regInteractObject;
static Unk_RegMarker s_initInteractObject =
    (((ClassObjectRegistrar*)&s_regInteractObject)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionInteractObject"), &CGuideConditionInteractObject::CreateObject), Unk_RegMarker());

// @0x1400f39c0
static char s_regInteractable;
static Unk_RegMarker s_initInteractable =
    (((ClassObjectRegistrar*)&s_regInteractable)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionInteractable"), &CGuideConditionInteractable::CreateObject), Unk_RegMarker());

#endif
