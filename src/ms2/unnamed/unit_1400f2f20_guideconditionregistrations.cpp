// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic initializers of 16 CGuideCondition* classes (AllOf .. DesignItem): each registers its factory with the ClassObject registry from a one-byte static, in exe order (see unit_1400f3a60 for the pattern).
// MS2-UNIT: unit_1400f2f20
// MS2-RANGE: 0x1400f2f20-0x1400f3420 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factories are defined by the
// class TUs' own code units.
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
ClassObject* FUN_1413aa2e0();
ClassObject* FUN_1413aa070();
ClassObject* FUN_1413adb00();
ClassObject* FUN_1413aeca0();
ClassObject* FUN_1413aafc0();
ClassObject* FUN_1413afb20();
ClassObject* FUN_1413a8270();
ClassObject* FUN_1413ac3a0();
ClassObject* FUN_1413a85f0();
ClassObject* FUN_1413a9f10();
ClassObject* FUN_1413af280();
ClassObject* FUN_1413a9900();
ClassObject* FUN_1413a9610();
ClassObject* FUN_1413ae730();
ClassObject* FUN_1413a8120();
ClassObject* FUN_1413a8fc0();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist

// @0x1400f2f20
static char s_regAllOf;
static Unk_RegMarker s_initAllOf =
    (FUN_140316aa0(&s_regAllOf, CStringW(L"CGuideConditionAllOf"), FUN_1413aa2e0), Unk_RegMarker());

// @0x1400f2f70
static char s_regAnyOne;
static Unk_RegMarker s_initAnyOne =
    (FUN_140316aa0(&s_regAnyOne, CStringW(L"CGuideConditionAnyOne"), FUN_1413aa070), Unk_RegMarker());

// @0x1400f2fc0
static char s_regBattleState;
static Unk_RegMarker s_initBattleState =
    (FUN_140316aa0(&s_regBattleState, CStringW(L"CGuideConditionBattleState"), FUN_1413adb00), Unk_RegMarker());

// @0x1400f3010
static char s_regButtonSelected;
static Unk_RegMarker s_initButtonSelected =
    (FUN_140316aa0(&s_regButtonSelected, CStringW(L"CGuideConditionButtonSelected"), FUN_1413aeca0), Unk_RegMarker());

// @0x1400f3060
static char s_regCanObserveMode;
static Unk_RegMarker s_initCanObserveMode =
    (FUN_140316aa0(&s_regCanObserveMode, CStringW(L"CGuideConditionCanObserveMode"), FUN_1413aafc0), Unk_RegMarker());

// @0x1400f30b0
static char s_regChatEmoticon;
static Unk_RegMarker s_initChatEmoticon =
    (FUN_140316aa0(&s_regChatEmoticon, CStringW(L"CGuideConditionChatEmoticon"), FUN_1413afb20), Unk_RegMarker());

// @0x1400f3100
static char s_regConstructMode;
static Unk_RegMarker s_initConstructMode =
    (FUN_140316aa0(&s_regConstructMode, CStringW(L"CGuideConditionConstructMode"), FUN_1413a8270), Unk_RegMarker());

// @0x1400f3150
static char s_regConstructSlot;
static Unk_RegMarker s_initConstructSlot =
    (FUN_140316aa0(&s_regConstructSlot, CStringW(L"CGuideConditionConstructSlot"), FUN_1413ac3a0), Unk_RegMarker());

// @0x1400f31a0
static char s_regConstructable;
static Unk_RegMarker s_initConstructable =
    (FUN_140316aa0(&s_regConstructable, CStringW(L"CGuideConditionConstructable"), FUN_1413a85f0), Unk_RegMarker());

// @0x1400f31f0
static char s_regContinentCode;
static Unk_RegMarker s_initContinentCode =
    (FUN_140316aa0(&s_regContinentCode, CStringW(L"CGuideConditionContinentCode"), FUN_1413a9f10), Unk_RegMarker());

// @0x1400f3240
static char s_regContract;
static Unk_RegMarker s_initContract =
    (FUN_140316aa0(&s_regContract, CStringW(L"CGuideConditionContract"), FUN_1413af280), Unk_RegMarker());

// @0x1400f3290
static char s_regCountInDoorInstallItem;
static Unk_RegMarker s_initCountInDoorInstallItem =
    (FUN_140316aa0(&s_regCountInDoorInstallItem, CStringW(L"CGuideConditionCountInDoorInstallItem"), FUN_1413a9900), Unk_RegMarker());

// @0x1400f32e0
static char s_regCountItem;
static Unk_RegMarker s_initCountItem =
    (FUN_140316aa0(&s_regCountItem, CStringW(L"CGuideConditionCountItem"), FUN_1413a9610), Unk_RegMarker());

// @0x1400f3330
static char s_regCubeHolderSelectItem;
static Unk_RegMarker s_initCubeHolderSelectItem =
    (FUN_140316aa0(&s_regCubeHolderSelectItem, CStringW(L"CGuideConditionCubeHolderSelectItem"), FUN_1413ae730), Unk_RegMarker());

// @0x1400f3380
static char s_regDead;
static Unk_RegMarker s_initDead =
    (FUN_140316aa0(&s_regDead, CStringW(L"CGuideConditionDead"), FUN_1413a8120), Unk_RegMarker());

// @0x1400f33d0
static char s_regDesignItem;
static Unk_RegMarker s_initDesignItem =
    (FUN_140316aa0(&s_regDesignItem, CStringW(L"CGuideConditionDesignItem"), FUN_1413a8fc0), Unk_RegMarker());

#endif
