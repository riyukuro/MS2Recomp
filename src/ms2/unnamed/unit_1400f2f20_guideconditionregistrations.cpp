// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic initializers of 16 CGuideCondition* classes (AllOf .. DesignItem): each registers its factory with the ClassObject registry from a one-byte static, in exe order (see unit_1400f3a60 for the pattern).
// MS2-UNIT: unit_1400f2f20
// MS2-RANGE: 0x1400f2f20-0x1400f3420 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/cguidecondition.h"

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factories are defined by the
// class TUs' own code units.
ClassObject* FUN_1413aeca0();
ClassObject* FUN_1413af280();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist

// @0x1400f2f20
static char s_regAllOf;
static Unk_RegMarker s_initAllOf =
    (((ClassObjectRegistrar*)&s_regAllOf)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionAllOf"), CGuideConditionAllOf::CreateObject), Unk_RegMarker());

// @0x1400f2f70
static char s_regAnyOne;
static Unk_RegMarker s_initAnyOne =
    (((ClassObjectRegistrar*)&s_regAnyOne)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionAnyOne"), CGuideConditionAnyOne::CreateObject), Unk_RegMarker());

// @0x1400f2fc0
static char s_regBattleState;
static Unk_RegMarker s_initBattleState =
    (((ClassObjectRegistrar*)&s_regBattleState)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionBattleState"), CGuideConditionBattleState::CreateObject), Unk_RegMarker());

// @0x1400f3010
static char s_regButtonSelected;
static Unk_RegMarker s_initButtonSelected =
    (((ClassObjectRegistrar*)&s_regButtonSelected)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionButtonSelected"), FUN_1413aeca0), Unk_RegMarker());

// @0x1400f3060
static char s_regCanObserveMode;
static Unk_RegMarker s_initCanObserveMode =
    (((ClassObjectRegistrar*)&s_regCanObserveMode)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionCanObserveMode"), CGuideConditionCanObserveMode::CreateObject), Unk_RegMarker());

// @0x1400f30b0
static char s_regChatEmoticon;
static Unk_RegMarker s_initChatEmoticon =
    (((ClassObjectRegistrar*)&s_regChatEmoticon)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionChatEmoticon"), CGuideConditionChatEmoticon::CreateObject), Unk_RegMarker());

// @0x1400f3100
static char s_regConstructMode;
static Unk_RegMarker s_initConstructMode =
    (((ClassObjectRegistrar*)&s_regConstructMode)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionConstructMode"), CGuideConditionConstructMode::CreateObject), Unk_RegMarker());

// @0x1400f3150
static char s_regConstructSlot;
static Unk_RegMarker s_initConstructSlot =
    (((ClassObjectRegistrar*)&s_regConstructSlot)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionConstructSlot"), CGuideConditionConstructSlot::CreateObject), Unk_RegMarker());

// @0x1400f31a0
static char s_regConstructable;
static Unk_RegMarker s_initConstructable =
    (((ClassObjectRegistrar*)&s_regConstructable)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionConstructable"), CGuideConditionConstructable::CreateObject), Unk_RegMarker());

// @0x1400f31f0
static char s_regContinentCode;
static Unk_RegMarker s_initContinentCode =
    (((ClassObjectRegistrar*)&s_regContinentCode)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionContinentCode"), CGuideConditionContinentCode::CreateObject), Unk_RegMarker());

// @0x1400f3240
static char s_regContract;
static Unk_RegMarker s_initContract =
    (((ClassObjectRegistrar*)&s_regContract)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionContract"), FUN_1413af280), Unk_RegMarker());

// @0x1400f3290
static char s_regCountInDoorInstallItem;
static Unk_RegMarker s_initCountInDoorInstallItem =
    (((ClassObjectRegistrar*)&s_regCountInDoorInstallItem)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionCountInDoorInstallItem"), CGuideConditionCountInDoorInstallItem::CreateObject), Unk_RegMarker());

// @0x1400f32e0
static char s_regCountItem;
static Unk_RegMarker s_initCountItem =
    (((ClassObjectRegistrar*)&s_regCountItem)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionCountItem"), CGuideConditionCountItem::CreateObject), Unk_RegMarker());

// @0x1400f3330
static char s_regCubeHolderSelectItem;
static Unk_RegMarker s_initCubeHolderSelectItem =
    (((ClassObjectRegistrar*)&s_regCubeHolderSelectItem)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionCubeHolderSelectItem"), CGuideConditionCubeHolderSelectItem::CreateObject), Unk_RegMarker());

// @0x1400f3380
static char s_regDead;
static Unk_RegMarker s_initDead =
    (((ClassObjectRegistrar*)&s_regDead)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionDead"), CGuideConditionDead::CreateObject), Unk_RegMarker());

// @0x1400f33d0
static char s_regDesignItem;
static Unk_RegMarker s_initDesignItem =
    (((ClassObjectRegistrar*)&s_regDesignItem)->ClassObjectRegistrar::ClassObjectRegistrar(CStringW(L"CGuideConditionDesignItem"), CGuideConditionDesignItem::CreateObject), Unk_RegMarker());

#endif
