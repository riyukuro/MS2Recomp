// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The notify classes: see notifychangebuff.h.
// MS2-UNIT: unit_140db46d0
// MS2-RANGE: 0x1400d3d30-0x1400d4e20 .text$di
// MS2-RANGE: 0x140db46d0-0x140db5c50 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\notifychangebuff.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "notifychangebuff.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// The factories of the classes of the first half of the notify header (their code is in unit_140da50e0's range): `return 0`.
ClassObject* FUN_140db4360();   // NotifyChangeMyJob
ClassObject* FUN_140db43c0();   // NotifyChangeMyLevel
ClassObject* FUN_140db45a0();   // NotifyChangeMyPC
ClassObject* FUN_140db4300();   // NotifyChangeServer
ClassObject* FUN_140db4600();   // NotifyChangedTokenMoney
ClassObject* FUN_140db4540();   // NotifyCompleteMyPC
ClassObject* FUN_140db44e0();   // NotifyCreateMyPC
ClassObject* FUN_140db4480();   // NotifyCutSceneCinematicSkip
ClassObject* FUN_140db4120();   // NotifyGameEventChanged
ClassObject* FUN_140db42a0();   // NotifyGameStart
ClassObject* FUN_140db4180();   // NotifyLearnEmotion
ClassObject* FUN_140db40c0();   // NotifyObject
ClassObject* FUN_140db41e0();   // NotifyPcBang
ClassObject* FUN_140db4420();   // NotifyRemoveGameObject
ClassObject* FUN_140db4240();   // NotifyUgcDownloadComplete
ClassObject* FUN_140db4660();   // NotifyUseSKill

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registry at DllMain time (RECOVERY section 9)
// Registration of the notify classes by name (dynamic initializers 0x1400d3d30-0x1400d4be0), in the order of the notify header list.
static ClassObjectRegistrar s_regActiveMyCodiTab(L"NotifyActiveMyCodiTab", NotifyActiveMyCodiTab::CreateObject);
static ClassObjectRegistrar s_regAddInteract(L"NotifyAddInteract", NotifyAddInteract::CreateObject);
static ClassObjectRegistrar s_regAddLiftable(L"NotifyAddLiftable", NotifyAddLiftable::CreateObject);
static ClassObjectRegistrar s_regAddNpc(L"NotifyAddNpc", NotifyAddNpc::CreateObject);
static ClassObjectRegistrar s_regAddPortal(L"NotifyAddPortal", NotifyAddPortal::CreateObject);
static ClassObjectRegistrar s_regBlindTarget(L"NotifyBlindTarget", NotifyBlindTarget::CreateObject);
static ClassObjectRegistrar s_regChangeActiveMyCodiTab(L"NotifyChangeActiveMyCodiTab", NotifyChangeActiveMyCodiTab::CreateObject);
static ClassObjectRegistrar s_regChangeBuff(L"NotifyChangeBuff", NotifyChangeBuff::CreateObject);
static ClassObjectRegistrar s_regChangeEnableFeature(L"NotifyChangeEnableFeature", NotifyChangeEnableFeature::CreateObject);
static ClassObjectRegistrar s_regChangeEquipment(L"NotifyChangeEquipment", NotifyChangeEquipment::CreateObject);
static ClassObjectRegistrar s_regChangeGameOptionInput(L"NotifyChangeGameOptionInput", NotifyChangeGameOptionInput::CreateObject);
static ClassObjectRegistrar s_regChangeJob(L"NotifyChangeJob", NotifyChangeJob::CreateObject);
static ClassObjectRegistrar s_regChangeLevel(L"NotifyChangeLevel", NotifyChangeLevel::CreateObject);
static ClassObjectRegistrar s_regChangeMyJob(L"NotifyChangeMyJob", FUN_140db4360);
static ClassObjectRegistrar s_regChangeMyLevel(L"NotifyChangeMyLevel", FUN_140db43c0);
static ClassObjectRegistrar s_regChangeMyPC(L"NotifyChangeMyPC", FUN_140db45a0);
static ClassObjectRegistrar s_regChangePcRidee(L"NotifyChangePcRidee", NotifyChangePcRidee::CreateObject);
static ClassObjectRegistrar s_regChangeServer(L"NotifyChangeServer", FUN_140db4300);
static ClassObjectRegistrar s_regChangeTitle(L"NotifyChangeTitle", NotifyChangeTitle::CreateObject);
static ClassObjectRegistrar s_regChangeUIBuildingCount(L"NotifyChangeUIBuildingCount", NotifyChangeUIBuildingCount::CreateObject);
static ClassObjectRegistrar s_regChangedTokenMoney(L"NotifyChangedTokenMoney", FUN_140db4600);
static ClassObjectRegistrar s_regChatEmoticonSelected(L"NotifyChatEmoticonSelected", NotifyChatEmoticonSelected::CreateObject);
static ClassObjectRegistrar s_regClearAchieve(L"NotifyClearAchieve", NotifyClearAchieve::CreateObject);
static ClassObjectRegistrar s_regCompleteMyPC(L"NotifyCompleteMyPC", FUN_140db4540);
static ClassObjectRegistrar s_regCreateMyPC(L"NotifyCreateMyPC", FUN_140db44e0);
static ClassObjectRegistrar s_regCutSceneCinematicSkip(L"NotifyCutSceneCinematicSkip", FUN_140db4480);
static ClassObjectRegistrar s_regDamagedMyPC(L"NotifyDamagedMyPC", NotifyDamagedMyPC::CreateObject);
static ClassObjectRegistrar s_regDebugMode(L"NotifyDebugMode", NotifyDebugMode::CreateObject);
static ClassObjectRegistrar s_regDebugState(L"NotifyDebugState", NotifyDebugState::CreateObject);
static ClassObjectRegistrar s_regDungeonEnterState(L"NotifyDungeonEnterState", NotifyDungeonEnterState::CreateObject);
static ClassObjectRegistrar s_regFadeInComplete(L"NotifyFadeInComplete", NotifyFadeInComplete::CreateObject);
static ClassObjectRegistrar s_regGameEventChanged(L"NotifyGameEventChanged", FUN_140db4120);
static ClassObjectRegistrar s_regGameStart(L"NotifyGameStart", FUN_140db42a0);
static ClassObjectRegistrar s_regKillPlayer(L"NotifyKillPlayer", NotifyKillPlayer::CreateObject);
static ClassObjectRegistrar s_regLearnEmotion(L"NotifyLearnEmotion", FUN_140db4180);
static ClassObjectRegistrar s_regObject(L"NotifyObject", FUN_140db40c0);
static ClassObjectRegistrar s_regOpenDialogByScene(L"NotifyOpenDialogByScene", NotifyOpenDialogByScene::CreateObject);
static ClassObjectRegistrar s_regPcBang(L"NotifyPcBang", FUN_140db41e0);
static ClassObjectRegistrar s_regRemoveGameObject(L"NotifyRemoveGameObject", FUN_140db4420);
static ClassObjectRegistrar s_regRemoveNpc(L"NotifyRemoveNpc", NotifyRemoveNpc::CreateObject);
static ClassObjectRegistrar s_regShortkeyPage(L"NotifyShortkeyPage", NotifyShortkeyPage::CreateObject);
static ClassObjectRegistrar s_regSkillSetMode(L"NotifySkillSetMode", NotifySkillSetMode::CreateObject);
static ClassObjectRegistrar s_regSurvivalGameFinish(L"NotifySurvivalGameFinish", NotifySurvivalGameFinish::CreateObject);
static ClassObjectRegistrar s_regSurvivalGameStart(L"NotifySurvivalGameStart", NotifySurvivalGameStart::CreateObject);
static ClassObjectRegistrar s_regSurvivalState(L"NotifySurvivalState", NotifySurvivalState::CreateObject);
static ClassObjectRegistrar s_regUgcDownloadComplete(L"NotifyUgcDownloadComplete", FUN_140db4240);
static ClassObjectRegistrar s_regUseSKill(L"NotifyUseSKill", FUN_140db4660);
#endif

// The second header's statics sit after the registrations: sort-name strings of the exe's ugc market / sort tables.
static CString s_strSortTypeNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x1400d4d50

// @0x140db46c0
ClassObject* NotifyChangeBuff::CreateObject() { return 0; }

// @0x140db46d0
CStringW NotifyChangeBuff::GetTypeName() { return L"NotifyChangeBuff"; }

// @0x140db4720
NotifyChangeBuff::NotifyChangeBuff(unsigned nId, unsigned short nSubId) : m_nId(nId), m_nSubId(nSubId), m_bAdded(1)
{
}

// @0x140db47a0
ClassObject* NotifyFadeInComplete::CreateObject() { return 0; }

// @0x140db47b0
CStringW NotifyFadeInComplete::GetTypeName() { return L"NotifyFadeInComplete"; }

// @0x140db4800
ClassObject* NotifyAddNpc::CreateObject() { return 0; }

// @0x140db4810
CStringW NotifyAddNpc::GetTypeName() { return L"NotifyAddNpc"; }

// @0x140db4860
NotifyAddNpc::NotifyAddNpc(efd::SmartPointer<Unk_SSGNpc> spNpc) : m_spNpc(spNpc)
{
}

// @0x140db48d0
ClassObject* NotifyRemoveNpc::CreateObject() { return 0; }

// @0x140db48e0
CStringW NotifyRemoveNpc::GetTypeName() { return L"NotifyRemoveNpc"; }

// @0x140db4930
NotifyRemoveNpc::NotifyRemoveNpc(efd::SmartPointer<Unk_SSGNpc> spNpc) : m_spNpc(spNpc)
{
}

// @0x140db49a0
ClassObject* NotifyAddInteract::CreateObject() { return 0; }

// @0x140db49b0
CStringW NotifyAddInteract::GetTypeName() { return L"NotifyAddInteract"; }

// @0x140db4a00
NotifyAddInteract::NotifyAddInteract(void* pObj) : m_pObj(pObj)
{
}

// @0x140db4a50
ClassObject* NotifyAddLiftable::CreateObject() { return 0; }

// @0x140db4a60
CStringW NotifyAddLiftable::GetTypeName() { return L"NotifyAddLiftable"; }

// @0x140db4ab0
NotifyAddLiftable::NotifyAddLiftable(void* pObj) : m_pObj(pObj)
{
}

// @0x140db4b00
ClassObject* NotifyAddPortal::CreateObject() { return 0; }

// @0x140db4b10
CStringW NotifyAddPortal::GetTypeName() { return L"NotifyAddPortal"; }

// @0x140db4b60
NotifyAddPortal::NotifyAddPortal(void* pObj) : m_pObj(pObj)
{
}

// @0x140db4bb0
ClassObject* NotifyDamagedMyPC::CreateObject() { return 0; }

// @0x140db4bc0
CStringW NotifyDamagedMyPC::GetTypeName() { return L"NotifyDamagedMyPC"; }

// @0x140db4c10
NotifyDamagedMyPC::NotifyDamagedMyPC(Unk_MDamage* pDamage) : m_pDamage(pDamage)
{
}

// @0x140db4c60
ClassObject* NotifyDebugMode::CreateObject() { return 0; }

// @0x140db4c70
CStringW NotifyDebugMode::GetTypeName() { return L"NotifyDebugMode"; }

// @0x140db4cc0
ClassObject* NotifyActiveMyCodiTab::CreateObject() { return 0; }

// @0x140db4cd0
CStringW NotifyActiveMyCodiTab::GetTypeName() { return L"NotifyActiveMyCodiTab"; }

// @0x140db4d20
ClassObject* NotifyChangeActiveMyCodiTab::CreateObject() { return 0; }

// @0x140db4d30
CStringW NotifyChangeActiveMyCodiTab::GetTypeName() { return L"NotifyChangeActiveMyCodiTab"; }

// @0x140db4d80
ClassObject* NotifyDebugState::CreateObject() { return 0; }

// @0x140db4d90
CStringW NotifyDebugState::GetTypeName() { return L"NotifyDebugState"; }

// @0x140db4de0
ClassObject* NotifyChangeJob::CreateObject() { return 0; }

// @0x140db4df0
CStringW NotifyChangeJob::GetTypeName() { return L"NotifyChangeJob"; }

// @0x140db4e40
NotifyChangeJob::NotifyChangeJob(PCBase* pPc) : m_pc(pPc)
{
}

// @0x140db4e90
ClassObject* NotifyChangeEquipment::CreateObject() { return 0; }

// @0x140db4ea0
CStringW NotifyChangeEquipment::GetTypeName() { return L"NotifyChangeEquipment"; }

// @0x140db4ef0
NotifyChangeEquipment::NotifyChangeEquipment(PCBase* pPc) : m_pc(pPc)
{
}

// @0x140db4f40
ClassObject* NotifyChangeLevel::CreateObject() { return 0; }

// @0x140db4f50
CStringW NotifyChangeLevel::GetTypeName() { return L"NotifyChangeLevel"; }

// @0x140db4fa0
NotifyChangeLevel::NotifyChangeLevel(PCBase* pPc) : m_pc(pPc)
{
}

// @0x140db4ff0
ClassObject* NotifyChangeTitle::CreateObject() { return 0; }

// @0x140db5000
CStringW NotifyChangeTitle::GetTypeName() { return L"NotifyChangeTitle"; }

// @0x140db5050
NotifyChangeTitle::NotifyChangeTitle(PCBase* pPc) : m_pc(pPc)
{
}

// @0x140db50a0
ClassObject* NotifyClearAchieve::CreateObject() { return 0; }

// @0x140db50b0
CStringW NotifyClearAchieve::GetTypeName() { return L"NotifyClearAchieve"; }

// @0x140db5100
ClassObject* NotifyChangePcRidee::CreateObject() { return 0; }

// @0x140db5110
CStringW NotifyChangePcRidee::GetTypeName() { return L"NotifyChangePcRidee"; }

// @0x140db5160
NotifyChangePcRidee::NotifyChangePcRidee(PCBase* pPc) : m_pc(pPc)
{
}

// @0x140db51b0
ClassObject* NotifyOpenDialogByScene::CreateObject() { return 0; }

// @0x140db51c0
CStringW NotifyOpenDialogByScene::GetTypeName() { return L"NotifyOpenDialogByScene"; }

// @0x140db5210
ClassObject* NotifyKillPlayer::CreateObject() { return 0; }

// @0x140db5220
CStringW NotifyKillPlayer::GetTypeName() { return L"NotifyKillPlayer"; }

// @0x140db5270
ClassObject* NotifySurvivalState::CreateObject() { return 0; }

// @0x140db5280
CStringW NotifySurvivalState::GetTypeName() { return L"NotifySurvivalState"; }

// @0x140db52d0
ClassObject* NotifySurvivalGameStart::CreateObject() { return 0; }

// @0x140db52e0
CStringW NotifySurvivalGameStart::GetTypeName() { return L"NotifySurvivalGameStart"; }

// @0x140db5330
ClassObject* NotifySurvivalGameFinish::CreateObject() { return 0; }

// @0x140db5340
CStringW NotifySurvivalGameFinish::GetTypeName() { return L"NotifySurvivalGameFinish"; }

// @0x140db5390
ClassObject* NotifyDungeonEnterState::CreateObject() { return 0; }

// @0x140db53a0
CStringW NotifyDungeonEnterState::GetTypeName() { return L"NotifyDungeonEnterState"; }

// @0x140db53f0
ClassObject* NotifySkillSetMode::CreateObject() { return 0; }

// @0x140db5400
CStringW NotifySkillSetMode::GetTypeName() { return L"NotifySkillSetMode"; }

// @0x140db5450
ClassObject* NotifyShortkeyPage::CreateObject() { return 0; }

// @0x140db5460
CStringW NotifyShortkeyPage::GetTypeName() { return L"NotifyShortkeyPage"; }

// @0x140db54b0
ClassObject* NotifyBlindTarget::CreateObject() { return 0; }

// @0x140db54c0
CStringW NotifyBlindTarget::GetTypeName() { return L"NotifyBlindTarget"; }

// @0x140db5510
ClassObject* NotifyChatEmoticonSelected::CreateObject() { return 0; }

// @0x140db5520
CStringW NotifyChatEmoticonSelected::GetTypeName() { return L"NotifyChatEmoticonSelected"; }

// @0x140db5570
ClassObject* NotifyChangeGameOptionInput::CreateObject() { return 0; }

// @0x140db5580
CStringW NotifyChangeGameOptionInput::GetTypeName() { return L"NotifyChangeGameOptionInput"; }

// @0x140db55d0
ClassObject* NotifyChangeUIBuildingCount::CreateObject() { return 0; }

// @0x140db55e0
CStringW NotifyChangeUIBuildingCount::GetTypeName() { return L"NotifyChangeUIBuildingCount"; }

// @0x140db5630
ClassObject* NotifyChangeEnableFeature::CreateObject() { return 0; }

// @0x140db5640
CStringW NotifyChangeEnableFeature::GetTypeName() { return L"NotifyChangeEnableFeature"; }

// ---- hooks ----
MS2_REPLACE_METHOD(0x140DB46D0, NotifyChangeBuff, GetTypeName, 61, 0x4682417E);
MS2_REPLACE_METHOD(0x140DB47B0, NotifyFadeInComplete, GetTypeName, 61, 0x7F7FA8AC);
MS2_REPLACE_METHOD(0x140DB4810, NotifyAddNpc, GetTypeName, 61, 0x4757803C);
MS2_REPLACE_METHOD(0x140DB48E0, NotifyRemoveNpc, GetTypeName, 61, 0x4D91E3DD);
MS2_REPLACE_METHOD(0x140DB49B0, NotifyAddInteract, GetTypeName, 61, 0xD121D589);
MS2_REPLACE_METHOD(0x140DB4A60, NotifyAddLiftable, GetTypeName, 61, 0xC5749678);
MS2_REPLACE_METHOD(0x140DB4B10, NotifyAddPortal, GetTypeName, 61, 0x6857211D);
MS2_REPLACE_METHOD(0x140DB4BC0, NotifyDamagedMyPC, GetTypeName, 61, 0xB5065172);
MS2_REPLACE_METHOD(0x140DB4C70, NotifyDebugMode, GetTypeName, 61, 0x2A62EAF0);
MS2_REPLACE_METHOD(0x140DB4CD0, NotifyActiveMyCodiTab, GetTypeName, 61, 0xFF1DF340);
MS2_REPLACE_METHOD(0x140DB4D30, NotifyChangeActiveMyCodiTab, GetTypeName, 61, 0x7E51A983);
MS2_REPLACE_METHOD(0x140DB4D90, NotifyDebugState, GetTypeName, 61, 0xBA16B023);
MS2_REPLACE_METHOD(0x140DB4DF0, NotifyChangeJob, GetTypeName, 61, 0xB032B1FB);
MS2_REPLACE_METHOD(0x140DB4EA0, NotifyChangeEquipment, GetTypeName, 61, 0x3CA4E76A);
MS2_REPLACE_METHOD(0x140DB4F50, NotifyChangeLevel, GetTypeName, 61, 0x888D82CD);
MS2_REPLACE_METHOD(0x140DB5000, NotifyChangeTitle, GetTypeName, 61, 0x1595E910);
MS2_REPLACE_METHOD(0x140DB50B0, NotifyClearAchieve, GetTypeName, 61, 0x41C4F781);
MS2_REPLACE_METHOD(0x140DB5110, NotifyChangePcRidee, GetTypeName, 61, 0x1A9218D1);
MS2_REPLACE_METHOD(0x140DB51C0, NotifyOpenDialogByScene, GetTypeName, 61, 0x73F34BED);
MS2_REPLACE_METHOD(0x140DB5220, NotifyKillPlayer, GetTypeName, 61, 0x36944AB5);
MS2_REPLACE_METHOD(0x140DB5280, NotifySurvivalState, GetTypeName, 61, 0xF29D59E4);
MS2_REPLACE_METHOD(0x140DB52E0, NotifySurvivalGameStart, GetTypeName, 61, 0x41F6FFAC);
MS2_REPLACE_METHOD(0x140DB5340, NotifySurvivalGameFinish, GetTypeName, 61, 0x2C4465A3);
MS2_REPLACE_METHOD(0x140DB53A0, NotifyDungeonEnterState, GetTypeName, 61, 0x2911F6EB);
MS2_REPLACE_METHOD(0x140DB5400, NotifySkillSetMode, GetTypeName, 61, 0xC0B034E3);
MS2_REPLACE_METHOD(0x140DB5460, NotifyShortkeyPage, GetTypeName, 61, 0xBC269732);
MS2_REPLACE_METHOD(0x140DB54C0, NotifyBlindTarget, GetTypeName, 61, 0xFD92EE42);
MS2_REPLACE_METHOD(0x140DB5520, NotifyChatEmoticonSelected, GetTypeName, 61, 0x543D2122);
MS2_REPLACE_METHOD(0x140DB5580, NotifyChangeGameOptionInput, GetTypeName, 61, 0xB3705849);
MS2_REPLACE_METHOD(0x140DB55E0, NotifyChangeUIBuildingCount, GetTypeName, 61, 0x13599739);
MS2_REPLACE_METHOD(0x140DB5640, NotifyChangeEnableFeature, GetTypeName, 61, 0x75EC97C8);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca55d0-0x142ca5690 .text$yd
