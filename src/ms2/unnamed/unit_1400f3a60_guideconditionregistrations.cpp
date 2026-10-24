// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic initializers of 20 CGuideCondition* classes (IsMyHome .. Position): each registers its factory with the ClassObject registry from a one-byte static, in exe order (see unit_1400f4190 for the pattern).
// MS2-UNIT: unit_1400f3a60
// MS2-RANGE: 0x1400f3a60-0x1400f40a0 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factories are defined by the
// class TUs' own code units.
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
ClassObject* FUN_1413a86f0();
ClassObject* FUN_1413ad7e0();
ClassObject* FUN_1413add70();
ClassObject* FUN_1413ac120();
ClassObject* FUN_1413ae1d0();
ClassObject* FUN_1413ae2e0();
ClassObject* FUN_1413ae990();
ClassObject* FUN_1413ade50();
ClassObject* FUN_1413ab250();
ClassObject* FUN_1413a76f0();
ClassObject* FUN_1413ab0e0();
ClassObject* FUN_1413a7bc0();
ClassObject* FUN_1413ab350();
ClassObject* FUN_1413abb80();
ClassObject* FUN_1413ab750();
ClassObject* FUN_1413ae500();
ClassObject* FUN_1413ae3f0();
ClassObject* FUN_1413ae600();
ClassObject* FUN_1413a6ca0();
ClassObject* FUN_1413a6e30();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist

// @0x1400f3a60
static char s_regIsMyHome;
static Unk_RegMarker s_initIsMyHome =
    (FUN_140316aa0(&s_regIsMyHome, CStringW(L"CGuideConditionIsMyHome"), FUN_1413a86f0), Unk_RegMarker());

// @0x1400f3ab0
static char s_regJobCode;
static Unk_RegMarker s_initJobCode =
    (FUN_140316aa0(&s_regJobCode, CStringW(L"CGuideConditionJobCode"), FUN_1413ad7e0), Unk_RegMarker());

// @0x1400f3b00
static char s_regJoinGuild;
static Unk_RegMarker s_initJoinGuild =
    (FUN_140316aa0(&s_regJoinGuild, CStringW(L"CGuideConditionJoinGuild"), FUN_1413add70), Unk_RegMarker());

// @0x1400f3b50
static char s_regLastClosedTextTip;
static Unk_RegMarker s_initLastClosedTextTip =
    (FUN_140316aa0(&s_regLastClosedTextTip, CStringW(L"CGuideConditionLastClosedTextTip"), FUN_1413ac120), Unk_RegMarker());

// @0x1400f3ba0
static char s_regMasteryMainTabIndex;
static Unk_RegMarker s_initMasteryMainTabIndex =
    (FUN_140316aa0(&s_regMasteryMainTabIndex, CStringW(L"CGuideConditionMasteryMainTabIndex"), FUN_1413ae1d0), Unk_RegMarker());

// @0x1400f3bf0
static char s_regMasterySubTabIndex;
static Unk_RegMarker s_initMasterySubTabIndex =
    (FUN_140316aa0(&s_regMasterySubTabIndex, CStringW(L"CGuideConditionMasterySubTabIndex"), FUN_1413ae2e0), Unk_RegMarker());

// @0x1400f3c40
static char s_regMentoringPage;
static Unk_RegMarker s_initMentoringPage =
    (FUN_140316aa0(&s_regMentoringPage, CStringW(L"CGuideConditionMentoringPage"), FUN_1413ae990), Unk_RegMarker());

// @0x1400f3c90
static char s_regMenuExpand;
static Unk_RegMarker s_initMenuExpand =
    (FUN_140316aa0(&s_regMenuExpand, CStringW(L"CGuideConditionMenuExpand"), FUN_1413ade50), Unk_RegMarker());

// @0x1400f3ce0
static char s_regMoney;
static Unk_RegMarker s_initMoney =
    (FUN_140316aa0(&s_regMoney, CStringW(L"CGuideConditionMoney"), FUN_1413ab250), Unk_RegMarker());

// @0x1400f3d30
static char s_regMovement;
static Unk_RegMarker s_initMovement =
    (FUN_140316aa0(&s_regMovement, CStringW(L"CGuideConditionMovement"), FUN_1413a76f0), Unk_RegMarker());

// @0x1400f3d80
static char s_regMyPlayerLevel;
static Unk_RegMarker s_initMyPlayerLevel =
    (FUN_140316aa0(&s_regMyPlayerLevel, CStringW(L"CGuideConditionMyPlayerLevel"), FUN_1413ab0e0), Unk_RegMarker());

// @0x1400f3dd0
static char s_regNext;
static Unk_RegMarker s_initNext =
    (FUN_140316aa0(&s_regNext, CStringW(L"CGuideConditionNext"), FUN_1413a7bc0), Unk_RegMarker());

// @0x1400f3e20
static char s_regPlaceUgcCube;
static Unk_RegMarker s_initPlaceUgcCube =
    (FUN_140316aa0(&s_regPlaceUgcCube, CStringW(L"CGuideConditionPlaceUgcCube"), FUN_1413ab350), Unk_RegMarker());

// @0x1400f3e70
static char s_regPlaceUgcCubeByIconType;
static Unk_RegMarker s_initPlaceUgcCubeByIconType =
    (FUN_140316aa0(&s_regPlaceUgcCubeByIconType, CStringW(L"CGuideConditionPlaceUgcCubeByIconType"), FUN_1413abb80), Unk_RegMarker());

// @0x1400f3ec0
static char s_regPlaceUgcCubeItem;
static Unk_RegMarker s_initPlaceUgcCubeItem =
    (FUN_140316aa0(&s_regPlaceUgcCubeItem, CStringW(L"CGuideConditionPlaceUgcCubeItem"), FUN_1413ab750), Unk_RegMarker());

// @0x1400f3f10
static char s_regPlayInstrumentHasSelectItem;
static Unk_RegMarker s_initPlayInstrumentHasSelectItem =
    (FUN_140316aa0(&s_regPlayInstrumentHasSelectItem, CStringW(L"CGuideConditionPlayInstrumentHasSelectItem"), FUN_1413ae500), Unk_RegMarker());

// @0x1400f3f60
static char s_regPlayInstrumentTabIndex;
static Unk_RegMarker s_initPlayInstrumentTabIndex =
    (FUN_140316aa0(&s_regPlayInstrumentTabIndex, CStringW(L"CGuideConditionPlayInstrumentTabIndex"), FUN_1413ae3f0), Unk_RegMarker());

// @0x1400f3fb0
static char s_regPlayingInstrument;
static Unk_RegMarker s_initPlayingInstrument =
    (FUN_140316aa0(&s_regPlayingInstrument, CStringW(L"CGuideConditionPlayingInstrument"), FUN_1413ae600), Unk_RegMarker());

// @0x1400f4000
static char s_regPortalEnable;
static Unk_RegMarker s_initPortalEnable =
    (FUN_140316aa0(&s_regPortalEnable, CStringW(L"CGuideConditionPortalEnable"), FUN_1413a6ca0), Unk_RegMarker());

// @0x1400f4050
static char s_regPosition;
static Unk_RegMarker s_initPosition =
    (FUN_140316aa0(&s_regPosition, CStringW(L"CGuideConditionPosition"), FUN_1413a6e30), Unk_RegMarker());

#endif
