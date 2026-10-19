// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of one translation unit whose CU name is unknown: the
// Scaleform identity matrices, a Winsock start-up object, the UI string-constant tables (shared item/skill/slot XML attribute
// names, then the confirm-dialog ids), the ATL static initializers and the Gamebryo library SDM statics / animation key loaders
// pulled in by the engine headers. No functions, only .text$di initializers (definition order = exe order).
// MS2-UNIT: unit_140105110
// MS2-RANGE: 0x140105110-0x1401073f0 .text$di
// MS2: the SDM objects and key-loader registrations are defined below, in the exe order (the engine headers guard theirs).
// MS2-PIN: ??__E?Identity@?$Matrix2x4@M@Render@Scaleform@@2V123@A@@YAXXZ 0x140105110
// MS2-PIN: ??__E?Identity@?$Matrix3x4@M@Render@Scaleform@@2V123@A@@YAXXZ 0x140105130
// MS2-PIN: ??__E?Identity@?$Matrix4x4@M@Render@Scaleform@@2V123@A@@YAXXZ 0x140105150
// MS2-PIN: ??__Es_wsaStartup@@YAXXZ 0x140105170
// MS2-PIN: ??__EInitializeCAtlStringMgr@ATLImplementationDetails@ATL@@YAXXZ 0x140106f10
// MS2-PIN: ??__EInitializeCImage@ATLImplementationDetails@ATL@@YAXXZ 0x140106f30
// MS2-PIN: ??__EefdPhysXSDMObject@@YAXXZ 0x140106fb0
// MS2-PIN: ??__ENSFParserLibSDMObject@@YAXXZ 0x140106fd0
// MS2-PIN: ??__ENiAnimationSDMObject@@YAXXZ 0x140106ff0
// MS2-PIN: ??__ENiBinaryShaderLibSDMObject@@YAXXZ 0x140107070
// MS2-PIN: ??__ENiCollisionSDMObject@@YAXXZ 0x1401070b0
// MS2-PIN: ??__ENiDX9RendererSetupSDMObject@@YAXXZ 0x1401070f0
// MS2-PIN: ??__ENiFloodgateSDMObject@@YAXXZ 0x140107150
// MS2-PIN: ??__ENiParticleSDMObject@@YAXXZ 0x1401071f0
// MS2-PIN: ??__ENiPhysXSDMObject@@YAXXZ 0x140107210
// MS2-PIN: ??__ENiTerrainSDMObject@@YAXXZ 0x140107370
// MS2-PIN: ??__E_AtlComModule@ATL@@YAXXZ 0x140107390
// MS2-PIN: ??__E_AtlWinModule@ATL@@YAXXZ 0x1401073c0
#define MS2_NO_ENGINE_STATIC_INIT
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <winsock2.h>
#include "GFxConfig.h"
#include "Render/Render_Matrix2x4.h"
#include "Render/Render_Matrix3x4.h"
#include "Render/Render_Matrix4x4.h"

namespace Scaleform { namespace Render {
template Matrix2x4<float> Matrix2x4<float>::Identity;       // 0x140105110
template Matrix3x4<float> Matrix3x4<float>::Identity;       // 0x140105130
template Matrix4x4<float> Matrix4x4<float>::Identity;       // 0x140105150
}}

// Winsock start-up object (ctor 0x141803bb0: version 2.0, result unused).
struct Unk_WsaStartup
{
    int m_nResult;
    Unk_WsaStartup();
    ~Unk_WsaStartup();
};
static Unk_WsaStartup s_wsaStartup;

static CString s_str_binding("binding");
static CString s_str_characterName("characterName");
static CString s_str_charSN("charSN");
static CString s_str_charName("charName");
static CString s_str_color("color");
static CString s_str_disable("disable");
static CString s_str_disableDrag("disableDrag");
static CString s_str_drag("drag");
static CString s_str_dropShadowDisable("dropShadowDisable");
static CString s_str_enabled("enabled");
static CString s_str_frame("frame");
static CString s_str_grayColor("grayColor");
static CString s_str_iconPath("iconPath");
static CString s_str_index("index");
static CString s_str_itemBothEquip("itemBothEquip");
static CString s_str_itemCash("itemCash");
static CString s_str_itemCategory("itemCategory");
static CString s_str_itemColor("itemColor");
static CString s_str_itemCount("itemCount");
static CString s_str_itemDesc("itemDesc");
static CString s_str_itemDesign("itemDesign");
static CString s_str_itemEquip2("itemEquip2");
static CString s_str_itemEquip("itemEquip");
static CString s_str_itemEvent("itemEvent");
static CString s_str_itemGrade("itemGrade");
static CString s_str_itemGUID("itemGUID");
static CString s_str_itemIconLock("itemIconLock");
static CString s_str_itemPiece("itemPiece");
static CString s_str_itemIconUnLock("itemIconUnLock");
static CString s_str_itemID("itemID");
static CString s_str_itemInstall("itemInstall");
static CString s_str_itemKinds("itemKinds");
static CString s_str_itemLevel("itemLevel");
static CString s_str_itemLock("itemLock");
static CString s_str_itemMaxCount("itemMaxCount");
static CString s_str_itemMovie("itemMovie");
static CString s_str_itemName("itemName");
static CString s_str_itemNew("itemNew");
static CString s_str_itemOperation("itemOperation");
static CString s_str_itemPackageList("itemPackageList");
static CString s_str_itemPcBang("itemPcBang");
static CString s_str_itemPet("itemPet");
static CString s_str_itemPrice("itemPrice");
static CString s_str_itemResultTag("itemResultTag");
static CString s_str_itemSeal("itemSeal");
static CString s_str_itemSellLimit("itemSellLimit");
static CString s_str_itemSkin("itemSkin");
static CString s_str_itemSummon("itemSummon");
static CString s_str_itemUpgrade("itemUpgrade");
static CString s_str_itemVIP("itemVIP");
static CString s_str_itemWedding("itemWedding");
static CString s_str_itemBreakIngredientList("itemBreakIngredientList");
static CString s_str_itemConditionLock("itemConditionLock");
static CString s_str_itemPetRank("itemPetRank");
static CString s_str_itemPetSkin("itemPetSkin");
static CString s_str_jobcode("jobcode");
static CString s_str_label("label");
static CString s_str_learn("learn");
static CString s_str_levelAndJobName("levelAndJobName");
static CString s_str_merat("merat");
static CString s_str_meso("meso");
static CString s_str_onCooldownEnd("onCooldownEnd");
static CString s_str_onCooldownStart("onCooldownStart");
static CString s_str_online("online");
static CString s_str_originPrice("originPrice");
static CString s_str_passive("passive");
static CString s_str_paymentIcon("paymentIcon");
static CString s_str_price("price");
static CString s_str_rechargeRemainCount("rechargeRemainCount");
static CString s_str_remainTime("remainTime");
static CString s_str_setData("setData");
static CString s_str_shortcutKey("shortcutKey");
static CString s_str_skillDescription("skillDescription");
static CString s_str_skillID("skillID");
static CString s_str_skillLearnLevel("skillLearnLevel");
static CString s_str_skillLevel("skillLevel");
static CString s_str_skillmaster("skillmaster");
static CString s_str_skillMaxLevel("skillMaxLevel");
static CString s_str_skillMovie("skillMovie");
static CString s_str_skillName("skillName");
static CString s_str_skillNew("skillNew");
static CString s_str_skilltype("skilltype");
static CString s_str_skillUpgrade("skillUpgrade");
static CString s_str_slot("slot");
static CString s_str_slotHint("slotHint");
static CString s_str_text("text");
static CString s_str_tooltipAlign("tooltipAlign");
static CString s_str_totalTime("totalTime");
static CString s_str_ugctag("ugctag");
static CString s_str_updateIconSearchOn("updateIconSearchOn");
static CStringW s_wstr_alreadyReconnect(L"alreadyReconnect");
static CStringW s_wstr_autoExternalBlock(L"autoExternalBlock");
static CStringW s_wstr_changeCharName(L"changeCharName");
static CStringW s_wstr_changeGuildName(L"changeGuildName");
static CStringW s_wstr_changeInvalidCharName(L"changeInvalidCharName");
static CStringW s_wstr_bannerClose(L"bannerClose");
static CStringW s_wstr_clubbuff(L"clubbuff");
static CStringW s_wstr_composeBindPet(L"composeBindPet");
static CStringW s_wstr_confirmChangeCharName(L"confirmChangeCharName");
static CStringW s_wstr_confirmCommend(L"confirmCommend");
static CStringW s_wstr_currency_overflow_ask(L"currency_overflow_ask");
static CStringW s_wstr_destroy_item(L"destroy_item");
static CStringW s_wstr_destroy_doll_item(L"destroy_doll_item");
static CStringW s_wstr_destroy_store_item(L"destroy_store_item");
static CStringW s_wstr_drop(L"drop");
static CStringW s_wstr_evolutionBindPet(L"evolutionBindPet");
static CStringW s_wstr_externalBlock(L"externalBlock");
static CStringW s_wstr_forcelogin(L"forcelogin");
static CStringW s_wstr_gameexit(L"gameexit");
static CStringW s_wstr_groupEdit(L"groupEdit");
static CStringW s_wstr_groupExit(L"groupExit");
static CStringW s_wstr_groupList(L"groupList");
static CStringW s_wstr_guildArenaJoin(L"guildArenaJoin");
static CStringW s_wstr_guildinvite(L"guildinvite");
static CStringW s_wstr_individualArenaJoin(L"individualArenaJoin");
static CStringW s_wstr_itemlock_confirm(L"itemlock_confirm");
static CStringW s_wstr_learn_emotion(L"learn_emotion");
static CStringW s_wstr_learn_skill(L"learn_skill");
static CStringW s_wstr_maintenanceExit(L"maintenanceExit");
static CStringW s_wstr_mapleSurvivalJoin(L"mapleSurvivalJoin");
static CStringW s_wstr_mapleSurvivalTeamJoin(L"mapleSurvivalTeamJoin");
static CStringW s_wstr_noticeModify(L"noticeModify");
static CStringW s_wstr_openMassive(L"openMassive");
static CStringW s_wstr_partyinvite(L"partyinvite");
static CStringW s_wstr_rankArenaJoin(L"rankArenaJoin");
static CStringW s_wstr_rankArenaObserve(L"rankArenaObserve");
static CStringW s_wstr_rankArenaRegister(L"rankArenaRegister");
static CStringW s_wstr_recallconfirm(L"recallconfirm");
static CStringW s_wstr_recallscrollconfirm(L"recallscrollconfirm");
static CStringW s_wstr_remakeOptionBindPet(L"remakeOptionBindPet");
static CStringW s_wstr_remakeOptionScrollBindPet(L"remakeOptionScrollBindPet");
static CStringW s_wstr_requestTradeEx(L"requestTradeEx");
static CStringW s_wstr_coupleDanceRequest(L"coupleDanceRequest");
static CStringW s_wstr_coupleEffect(L"coupleEffect");
static CStringW s_wstr_coupleEffectconfirm(L"coupleEffectconfirm");
static CStringW s_wstr_coupleEmotion(L"coupleEmotion");
static CStringW s_wstr_rpsGameRequest(L"rpsGameRequest");
static CStringW s_wstr_sell(L"sell");
static CStringW s_wstr_sellconfirm(L"sellconfirm");
static CStringW s_wstr_startbypass(L"startbypass");
static CStringW s_wstr_studyBindPet(L"studyBindPet");
static CStringW s_wstr_summonBindPet(L"summonBindPet");
static CStringW s_wstr_swapstorein_(L"swapstorein-");
static CStringW s_wstr_swapstoreout_(L"swapstoreout-");
static CStringW s_wstr_tradein(L"tradein");
static CStringW s_wstr_trainingBindPet(L"trainingBindPet");
static CStringW s_wstr_unlockcash(L"unlockcash");
static CStringW s_wstr_use_function_item(L"use_function_item");
static CStringW s_wstr_use_function_item_ask(L"use_function_item_ask");
static CStringW s_wstr_usestorein(L"usestorein");
static CStringW s_wstr_usestoreout(L"usestoreout");
static CStringW s_wstr_useBindEquipItem(L"useBindEquipItem");
static CStringW s_wstr_useBindFuncItem(L"useBindFuncItem");
static CStringW s_wstr_useBindGemEquipItem(L"useBindGemEquipItem");
static CStringW s_wstr_useBindItemSkill(L"useBindItemSkill");
static CStringW s_wstr_coupleDanceWaiting(L"coupleDanceWaiting");
static CStringW s_wstr_rpsGameWaiting(L"rpsGameWaiting");

#include <atlimage.h>

static CString s_str_empty("");
static CString s_str_empty2("");

// ---- Gamebryo static initializers: the exe's order is alphabetical by header (library SDM objects and the animation key
// loader registrations interleaved) ----
#ifndef NOMINMAX
#define NOMINMAX
#endif
#undef min
#undef max
#include <NiMain.h>
#include <efdPhysX/PhysXSDKManager.h>
#include <NSFParserLib.h>
#include <NiAnimation.h>
#include <NiBinaryShaderLib.h>
#include <NiCollision.h>
#include <NiDX9RendererSetup.h>
#include <NiStreamProcessor.h>
#include <NiParticle.h>
#include <NiPhysX.h>
#include <NiTerrainLib.h>

// efdPhysXSDM's constructor (0x142756a00, a Gamebryo PhysX-lib function in the exe's runtime range) is not part of the
// engine libraries this build links, so it is defined here (EE_IMPLEMENT_SDM_CONSTRUCTOR without the ms_initialized
// definition, which the exe's Init already owns).
efdPhysX::efdPhysXSDM::efdPhysXSDM()
{
    static efd::SInt32 counter = 0;
    if (counter++ == 0)
        efd::StaticDataManager::AddLibrary("efdPhysX", efdPhysXSDM::Init, efdPhysXSDM::Shutdown, NULL, NULL, "");
}

static efdPhysX::efdPhysXSDM efdPhysXSDMObject;
static NSFParserLibSDM NSFParserLibSDMObject;
static NiAnimationSDM NiAnimationSDMObject;
static int NiBezFloatKeyregisterloaderreturn = NiBezFloatKey::RegisterLoader();
static int NiBezPosKeyregisterloaderreturn = NiBezPosKey::RegisterLoader();
static int NiBezRotKeyregisterloaderreturn = NiBezRotKey::RegisterLoader();
static NiBinaryShaderLibSDM NiBinaryShaderLibSDMObject;
static int NiBoolKeyregisterloaderreturn = NiBoolKey::RegisterLoader();
static NiCollisionSDM NiCollisionSDMObject;
static int NiColorKeyregisterloaderreturn = NiColorKey::RegisterLoader();
static NiDX9RendererSetupSDM NiDX9RendererSetupSDMObject;
static int NiEulerRotKeyregisterloaderreturn = NiEulerRotKey::RegisterLoader();
static int NiFloatKeyregisterloaderreturn = NiFloatKey::RegisterLoader();
static NiFloodgateSDM NiFloodgateSDMObject;
static int NiLinColorKeyregisterloaderreturn = NiLinColorKey::RegisterLoader();
static int NiLinFloatKeyregisterloaderreturn = NiLinFloatKey::RegisterLoader();
static int NiLinPosKeyregisterloaderreturn = NiLinPosKey::RegisterLoader();
static int NiLinRotKeyregisterloaderreturn = NiLinRotKey::RegisterLoader();
static NiParticleSDM NiParticleSDMObject;
static NiPhysXSDM NiPhysXSDMObject;
static int NiPosKeyregisterloaderreturn = NiPosKey::RegisterLoader();
static int NiRotKeyregisterloaderreturn = NiRotKey::RegisterLoader();
static int NiStepBoolKeyregisterloaderreturn = NiStepBoolKey::RegisterLoader();
static int NiStepColorKeyregisterloaderreturn = NiStepColorKey::RegisterLoader();
static int NiStepFloatKeyregisterloaderreturn = NiStepFloatKey::RegisterLoader();
static int NiStepPosKeyregisterloaderreturn = NiStepPosKey::RegisterLoader();
static int NiStepRotKeyregisterloaderreturn = NiStepRotKey::RegisterLoader();
static int NiTCBFloatKeyregisterloaderreturn = NiTCBFloatKey::RegisterLoader();
static int NiTCBPosKeyregisterloaderreturn = NiTCBPosKey::RegisterLoader();
static int NiTCBRotKeyregisterloaderreturn = NiTCBRotKey::RegisterLoader();
static NiTerrainSDM NiTerrainSDMObject;
