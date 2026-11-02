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
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
ClassObject* FUN_1413aeca0();
ClassObject* FUN_1413af280();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist

// @0x1400f2f20
static char s_regAllOf;
static Unk_RegMarker s_initAllOf =
    (FUN_140316aa0(&s_regAllOf, CStringW(L"CGuideConditionAllOf"), CGuideConditionAllOf::CreateObject), Unk_RegMarker());

// @0x1400f2f70
static char s_regAnyOne;
static Unk_RegMarker s_initAnyOne =
    (FUN_140316aa0(&s_regAnyOne, CStringW(L"CGuideConditionAnyOne"), CGuideConditionAnyOne::CreateObject), Unk_RegMarker());

// @0x1400f2fc0
static char s_regBattleState;
static Unk_RegMarker s_initBattleState =
    (FUN_140316aa0(&s_regBattleState, CStringW(L"CGuideConditionBattleState"), CGuideConditionBattleState::CreateObject), Unk_RegMarker());

// @0x1400f3010
static char s_regButtonSelected;
static Unk_RegMarker s_initButtonSelected =
    (FUN_140316aa0(&s_regButtonSelected, CStringW(L"CGuideConditionButtonSelected"), FUN_1413aeca0), Unk_RegMarker());

// @0x1400f3060
static char s_regCanObserveMode;
static Unk_RegMarker s_initCanObserveMode =
    (FUN_140316aa0(&s_regCanObserveMode, CStringW(L"CGuideConditionCanObserveMode"), CGuideConditionCanObserveMode::CreateObject), Unk_RegMarker());

// @0x1400f30b0
static char s_regChatEmoticon;
static Unk_RegMarker s_initChatEmoticon =
    (FUN_140316aa0(&s_regChatEmoticon, CStringW(L"CGuideConditionChatEmoticon"), CGuideConditionChatEmoticon::CreateObject), Unk_RegMarker());

// @0x1400f3100
static char s_regConstructMode;
static Unk_RegMarker s_initConstructMode =
    (FUN_140316aa0(&s_regConstructMode, CStringW(L"CGuideConditionConstructMode"), CGuideConditionConstructMode::CreateObject), Unk_RegMarker());

// @0x1400f3150
static char s_regConstructSlot;
static Unk_RegMarker s_initConstructSlot =
    (FUN_140316aa0(&s_regConstructSlot, CStringW(L"CGuideConditionConstructSlot"), CGuideConditionConstructSlot::CreateObject), Unk_RegMarker());

// @0x1400f31a0
static char s_regConstructable;
static Unk_RegMarker s_initConstructable =
    (FUN_140316aa0(&s_regConstructable, CStringW(L"CGuideConditionConstructable"), CGuideConditionConstructable::CreateObject), Unk_RegMarker());

// @0x1400f31f0
static char s_regContinentCode;
static Unk_RegMarker s_initContinentCode =
    (FUN_140316aa0(&s_regContinentCode, CStringW(L"CGuideConditionContinentCode"), CGuideConditionContinentCode::CreateObject), Unk_RegMarker());

// @0x1400f3240
static char s_regContract;
static Unk_RegMarker s_initContract =
    (FUN_140316aa0(&s_regContract, CStringW(L"CGuideConditionContract"), FUN_1413af280), Unk_RegMarker());

// @0x1400f3290
static char s_regCountInDoorInstallItem;
static Unk_RegMarker s_initCountInDoorInstallItem =
    (FUN_140316aa0(&s_regCountInDoorInstallItem, CStringW(L"CGuideConditionCountInDoorInstallItem"), CGuideConditionCountInDoorInstallItem::CreateObject), Unk_RegMarker());

// @0x1400f32e0
static char s_regCountItem;
static Unk_RegMarker s_initCountItem =
    (FUN_140316aa0(&s_regCountItem, CStringW(L"CGuideConditionCountItem"), CGuideConditionCountItem::CreateObject), Unk_RegMarker());

// @0x1400f3330
static char s_regCubeHolderSelectItem;
static Unk_RegMarker s_initCubeHolderSelectItem =
    (FUN_140316aa0(&s_regCubeHolderSelectItem, CStringW(L"CGuideConditionCubeHolderSelectItem"), CGuideConditionCubeHolderSelectItem::CreateObject), Unk_RegMarker());

// @0x1400f3380
static char s_regDead;
static Unk_RegMarker s_initDead =
    (FUN_140316aa0(&s_regDead, CStringW(L"CGuideConditionDead"), CGuideConditionDead::CreateObject), Unk_RegMarker());

// @0x1400f33d0
static char s_regDesignItem;
static Unk_RegMarker s_initDesignItem =
    (FUN_140316aa0(&s_regDesignItem, CStringW(L"CGuideConditionDesignItem"), CGuideConditionDesignItem::CreateObject), Unk_RegMarker());

#endif
