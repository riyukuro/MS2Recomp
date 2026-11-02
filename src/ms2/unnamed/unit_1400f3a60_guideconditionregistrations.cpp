// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic initializers of 20 CGuideCondition* classes (IsMyHome .. Position): each registers its factory with the ClassObject registry from a one-byte static, in exe order (see unit_1400f4190 for the pattern).
// MS2-UNIT: unit_1400f3a60
// MS2-RANGE: 0x1400f3a60-0x1400f40a0 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/cguidecondition.h"

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factories are defined by the
// class TUs' own code units.
ClassObject* FUN_1413ae990();
ClassObject* FUN_1413ade50();

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist

// @0x1400f3a60
static ClassObjectRegistrar s_regIsMyHome(L"CGuideConditionIsMyHome", CGuideConditionIsMyHome::CreateObject);

// @0x1400f3ab0
static ClassObjectRegistrar s_regJobCode(L"CGuideConditionJobCode", CGuideConditionJobCode::CreateObject);

// @0x1400f3b00
static ClassObjectRegistrar s_regJoinGuild(L"CGuideConditionJoinGuild", CGuideConditionJoinGuild::CreateObject);

// @0x1400f3b50
static ClassObjectRegistrar s_regLastClosedTextTip(L"CGuideConditionLastClosedTextTip", CGuideConditionLastClosedTextTip::CreateObject);

// @0x1400f3ba0
static ClassObjectRegistrar s_regMasteryMainTabIndex(L"CGuideConditionMasteryMainTabIndex", CGuideConditionMasteryMainTabIndex::CreateObject);

// @0x1400f3bf0
static ClassObjectRegistrar s_regMasterySubTabIndex(L"CGuideConditionMasterySubTabIndex", CGuideConditionMasterySubTabIndex::CreateObject);

// @0x1400f3c40
static ClassObjectRegistrar s_regMentoringPage(L"CGuideConditionMentoringPage", FUN_1413ae990);

// @0x1400f3c90
static ClassObjectRegistrar s_regMenuExpand(L"CGuideConditionMenuExpand", FUN_1413ade50);

// @0x1400f3ce0
static ClassObjectRegistrar s_regMoney(L"CGuideConditionMoney", CGuideConditionMoney::CreateObject);

// @0x1400f3d30
static ClassObjectRegistrar s_regMovement(L"CGuideConditionMovement", CGuideConditionMovement::CreateObject);

// @0x1400f3d80
static ClassObjectRegistrar s_regMyPlayerLevel(L"CGuideConditionMyPlayerLevel", CGuideConditionMyPlayerLevel::CreateObject);

// @0x1400f3dd0
static ClassObjectRegistrar s_regNext(L"CGuideConditionNext", CGuideConditionNext::CreateObject);

// @0x1400f3e20
static ClassObjectRegistrar s_regPlaceUgcCube(L"CGuideConditionPlaceUgcCube", CGuideConditionPlaceUgcCube::CreateObject);

// @0x1400f3e70
static ClassObjectRegistrar s_regPlaceUgcCubeByIconType(L"CGuideConditionPlaceUgcCubeByIconType", CGuideConditionPlaceUgcCubeByIconType::CreateObject);

// @0x1400f3ec0
static ClassObjectRegistrar s_regPlaceUgcCubeItem(L"CGuideConditionPlaceUgcCubeItem", CGuideConditionPlaceUgcCubeItem::CreateObject);

// @0x1400f3f10
static ClassObjectRegistrar s_regPlayInstrumentHasSelectItem(L"CGuideConditionPlayInstrumentHasSelectItem", CGuideConditionPlayInstrumentHasSelectItem::CreateObject);

// @0x1400f3f60
static ClassObjectRegistrar s_regPlayInstrumentTabIndex(L"CGuideConditionPlayInstrumentTabIndex", CGuideConditionPlayInstrumentTabIndex::CreateObject);

// @0x1400f3fb0
static ClassObjectRegistrar s_regPlayingInstrument(L"CGuideConditionPlayingInstrument", CGuideConditionPlayingInstrument::CreateObject);

// @0x1400f4000
static ClassObjectRegistrar s_regPortalEnable(L"CGuideConditionPortalEnable", CGuideConditionPortalEnable::CreateObject);

// @0x1400f4050
static ClassObjectRegistrar s_regPosition(L"CGuideConditionPosition", CGuideConditionPosition::CreateObject);

#endif
