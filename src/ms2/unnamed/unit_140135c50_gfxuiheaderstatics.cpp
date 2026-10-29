// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of one translation unit whose CU name is
// unknown, in the GFx UI-library block of the final .text$di run (split out of unit_140120880 by w520): the Scaleform identity
// matrices, the shared UI string-constant tables (same header as unit_140105110: item/skill/slot XML attribute names, then the
// confirm-dialog ids), the ATL static initializers, the Gamebryo NiAnimation/Floodgate SDM statics and animation key loaders,
// the ATL trace categories, the gos* / SubState / attach-point / menu name tables (same header as unit_140107420) and the
// efd::Category header constants. No functions, only .text$di initializers (definition order = exe order).
// MS2-UNIT: unit_140135c50
// MS2-RANGE: 0x140135c50-0x14013acc0 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??__E?Identity@?$Matrix2x4@M@Render@Scaleform@@2V123@A@@YAXXZ 0x140135c50
// MS2-PIN: ??__E?Identity@?$Matrix3x4@M@Render@Scaleform@@2V123@A@@YAXXZ 0x140135c70
// MS2-PIN: ??__E?Identity@?$Matrix4x4@M@Render@Scaleform@@2V123@A@@YAXXZ 0x140135c90
// MS2-PIN: ??__EInitializeCAtlStringMgr@ATLImplementationDetails@ATL@@YAXXZ 0x140137a20
// MS2-PIN: ??__ENiAnimationSDMObject@@YAXXZ 0x140137aa0
// MS2-PIN: ??__ENiFloodgateSDMObject@@YAXXZ 0x140137ba0
// MS2-PIN: ??__E_AtlComModule@ATL@@YAXXZ 0x140137d80
// MS2-PIN: ??__E_AtlWinModule@ATL@@YAXXZ 0x140137db0
#define MS2_NO_ENGINE_STATIC_INIT
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <utility>
#include "ms2/placeholder/sfrendermatrix.h"

namespace Scaleform { namespace Render {
template Matrix2x4<float> Matrix2x4<float>::Identity;       // 0x140135c50
template Matrix3x4<float> Matrix3x4<float>::Identity;       // 0x140135c70
template Matrix4x4<float> Matrix4x4<float>::Identity;       // 0x140135c90
}}

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

#include <atlstr.h>

static CString s_str_empty("");
static CString s_str_empty2("");

// ---- Gamebryo static initializers (NiAnimation SDM + key loaders, Floodgate SDM), in the exe's order ----
#ifndef NOMINMAX
#define NOMINMAX
#endif
#undef min
#undef max
#include <NiMain.h>
#include <NiAnimation.h>
#include <NiStreamProcessor.h>

static NiAnimationSDM NiAnimationSDMObject;
static int NiBezFloatKeyregisterloaderreturn = NiBezFloatKey::RegisterLoader();
static int NiBezPosKeyregisterloaderreturn = NiBezPosKey::RegisterLoader();
static int NiBezRotKeyregisterloaderreturn = NiBezRotKey::RegisterLoader();
static int NiBoolKeyregisterloaderreturn = NiBoolKey::RegisterLoader();
static int NiColorKeyregisterloaderreturn = NiColorKey::RegisterLoader();
static int NiEulerRotKeyregisterloaderreturn = NiEulerRotKey::RegisterLoader();
static int NiFloatKeyregisterloaderreturn = NiFloatKey::RegisterLoader();
static NiFloodgateSDM NiFloodgateSDMObject;
static int NiLinColorKeyregisterloaderreturn = NiLinColorKey::RegisterLoader();
static int NiLinFloatKeyregisterloaderreturn = NiLinFloatKey::RegisterLoader();
static int NiLinPosKeyregisterloaderreturn = NiLinPosKey::RegisterLoader();
static int NiLinRotKeyregisterloaderreturn = NiLinRotKey::RegisterLoader();
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

#include <atltrace.h>
#include <efd/Category.h>

// MS2-FUNCTIONAL: atlTrace* are the selectany ATL trace categories of atltrace.h; the exe holds look-alike copies (paired as look-alikes), this TU emits those it references.
extern const void* const g_atlTraceRefs_140135c50[]; const void* const g_atlTraceRefs_140135c50[] = {
    &ATL::atlTraceAllocation, &ATL::atlTraceCOM, &ATL::atlTraceCache, &ATL::atlTraceControls, &ATL::atlTraceDBClient,
    &ATL::atlTraceDBProvider, &ATL::atlTraceException, &ATL::atlTraceGeneral, &ATL::atlTraceHosting, &ATL::atlTraceISAPI,
    &ATL::atlTraceMap, &ATL::atlTraceNotImpl, &ATL::atlTraceQI, &ATL::atlTraceRefcount, &ATL::atlTraceRegistrar,
    &ATL::atlTraceSecurity, &ATL::atlTraceSnapin, &ATL::atlTraceStencil, &ATL::atlTraceString, &ATL::atlTraceSync,
    &ATL::atlTraceTime, &ATL::atlTraceUtil, &ATL::atlTraceWindowing,
};

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
class Unk_1418036e0 { public: Unk_1418036e0(void*); private: void* m_p; };
class Unk_1418036b0 { public: Unk_1418036b0(); private: void* m_p; int m_n; };


// The game-object state and sub-state name tables (0x143b0c750, 0x143b0bba0; initializers 0x1401380c0, 0x140138a80):
// the same std::make_pair rows as uinametag.cpp and additionalactionadditional.cpp, one copy per including unit.
#include "ms2/client/ms2/uinametag_gos.h"
#include "ms2/placeholder/gosubstatenames.h"
static CString s_attachNames_c50[] = {"Head", "Body", "Back", "RHand", "LHand", "RFoot", "LFoot", "Tail", "Hold_Point"};
// MS2-FUNCTIONAL: the exe calls other look-alike copies of the pair<const char*,int> array-ref ctors (0x14021f3e0..) than the ones the symbol table binds (0x14021c9d0..)
// The exe builds this table with std::make_pair (0x14021f3e0..), like the name tables above.
static std::pair<const char*, int> s_menuNames_c50[] = {
    std::make_pair("WorldMap", 1),
    std::make_pair("Mail", 2),
    std::make_pair("Commuty", 3),
    std::make_pair("Guild", 4),
    std::make_pair("LevelUp", 5),
    std::make_pair("Arcade", 6),
    std::make_pair("Option", 7),
    std::make_pair("Character", 8),
    std::make_pair("Inventory", 9),
    std::make_pair("Skill", 10),
    std::make_pair("Quest", 11),
    std::make_pair("Achieve", 12),
    std::make_pair("DungeonSearch", 13),
    std::make_pair("Maview", 14),
    std::make_pair("MeratMarket", 15),
    std::make_pair("CashShop", 16),
    std::make_pair("Beauty", 17),
    std::make_pair("BlackMarket", 18),
    std::make_pair("IndividualBattle", 19),
    std::make_pair("CharacterAbility", 20),
    std::make_pair("Design", 21),
    std::make_pair("Home", 22),
    std::make_pair("VIP", 23),
    std::make_pair("Mastery", 24),
    std::make_pair("PartySearch", 25),
    std::make_pair("LearningQuest", 26),
    std::make_pair("CompactKey", 27),
    std::make_pair("Dictionary", 28),
    std::make_pair("Ranking", 29),
    std::make_pair("BeautyHair", 30),
    std::make_pair("BeautyItem", 31),
    std::make_pair("BeautySkin", 32),
    std::make_pair("Club", 33),
    std::make_pair("EpicRestart", 34),
    std::make_pair("LevelUpPackage", 35),
    std::make_pair("AdventureBar", 36),
    std::make_pair("StampEvent", 37),
    std::make_pair("AttendGift", 38),
    std::make_pair("Pet", 39),
    std::make_pair("LiveBroadCast", 40),
    std::make_pair("TimeRunEvent", 41),
    std::make_pair("Mentoring", 42),
    std::make_pair("DailyMission", 43),
    std::make_pair("FamePointBoard", 44),
    std::make_pair("GalleryEvent", 45),
    std::make_pair("SkyFortress", 46),
    std::make_pair("Rps", 47),
    std::make_pair("CharacterSelect", 48),
    std::make_pair("GameExit", 49),
    std::make_pair("SurvivalMap", 50),
    std::make_pair("AdventureLevel", 51),
    std::make_pair("WorldChampion", 52),
    std::make_pair("CashAttend", 53),
    std::make_pair("ChangeJob", 54),
    std::make_pair("Lapenshard", 55),
    std::make_pair("MushkingRoyal", 56),
    std::make_pair("CoupleDanceEvent", 57),
    std::make_pair("MeratCharge", 58),
    std::make_pair("PssbShop", 59),
    std::make_pair("CollectItemGroupEvent", 60),
    std::make_pair("BingoEvent", 61),
    std::make_pair("Payback", 62),
    std::make_pair("Wedding", 63),
    std::make_pair("LongTermAttendGift", 64),
    std::make_pair("MarketGroup", 1000),
    std::make_pair("CharacterGroup", 1001),
    std::make_pair("ContentsGroup", 1002),
    std::make_pair("GameGroup", 1003),
    std::make_pair("CommunityGroup", 1004),
    std::make_pair("GamePad_SystemGroup", 2000),
    std::make_pair("GamePad_CharacterGroup", 2001),
    std::make_pair("GamePad_ContentsGroup", 2002),
    std::make_pair("GamePad_GameGroup", 2003),
    std::make_pair("GamePad_CommunityGroup", 2004),
    std::make_pair("GamePad_MarketGroup", 2005),
};
static const efd::Category s_cat_7f00004(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
static Unk_1418036b0 s_zero;
static Unk_1401cd100 s_pointer(NULL);
static Unk_1418036e0 s_pointer2(NULL);
static CString s_str_empty3("");
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc7460-0x142cc8970 .text$yd
