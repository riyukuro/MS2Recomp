// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header/file statics of a long run
// of neighbouring TUs: the ATL trace categories, the gos* / SubState / menu name-to-id tables (std::pair<CString,int>),
// attachment-point names, efd::Category constants and a few hundred sound / UI event name strings.
// MS2-UNIT: unit_140107420
// MS2-RANGE: 0x140107420-0x14010cbd0 .text$di
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <utility>
#include <atltrace.h>
#include <efd/Category.h>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#undef min
#undef max
#include <efdPhysX/PhysXSDKManager.h>
#include "ms2/ms2recover.h"

// MS2-FUNCTIONAL: atlTrace* are the selectany ATL trace categories of atltrace.h; the exe holds 23 look-alike copies (paired as look-alikes), this TU emits those it references.
extern const void* const g_atlTraceRefs[]; const void* const g_atlTraceRefs[] = {
    &ATL::atlTraceAllocation,
    &ATL::atlTraceCOM,
    &ATL::atlTraceCache,
    &ATL::atlTraceControls,
    &ATL::atlTraceDBClient,
    &ATL::atlTraceDBProvider,
    &ATL::atlTraceException,
    &ATL::atlTraceGeneral,
    &ATL::atlTraceHosting,
    &ATL::atlTraceISAPI,
    &ATL::atlTraceMap,
    &ATL::atlTraceNotImpl,
    &ATL::atlTraceQI,
    &ATL::atlTraceRefcount,
    &ATL::atlTraceRegistrar,
    &ATL::atlTraceSecurity,
    &ATL::atlTraceSnapin,
    &ATL::atlTraceStencil,
    &ATL::atlTraceString,
    &ATL::atlTraceSync,
    &ATL::atlTraceTime,
    &ATL::atlTraceUtil,
    &ATL::atlTraceWindowing,
};

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
class Unk_1418036e0 { public: Unk_1418036e0(void*); private: void* m_p; };
class Unk_1418036b0 { public: Unk_1418036b0(); private: void* m_p; int m_n; };

// efdPhysX/PhysXSDKManager.h's SDM object (0x143aedddd; ctor 0x1421177a0, the engine copy whose Init/Shutdown are
// 0x142117800/0x142117860). The header's own copy is compiled out (MS2_NO_ENGINE_STATIC_INIT); defined here as in
// unit_140105110.cpp (which also defines the constructor for the hook DLL).
static efdPhysX::efdPhysXSDM efdPhysXSDMObject;

static std::pair<const char*, int> s_gosNames[] = {
    {"gosNone", 0},
    {"gosIdle", 1},
    {"gosWalk", 2},
    {"gosCrawl", 3},
    {"gosLand", 4},
    {"gosFall", 5},
    {"gosJump", 6},
    {"gosJumpTo", 7},
    {"gosLadder", 8},
    {"gosRope", 9},
    {"gosSit", 10},
    {"gosEmotion", 11},
    {"gosDead", 12},
    {"gosHit", 13},
    {"gosWaittingSelect", 14},
    {"gosEmotionIdle", 15},
    {"gosPcSkill", 16},
    {"gosSpawn", 17},
    {"gosStun", 18},
    {"gosDash", 20},
    {"gosPush", 21},
    {"gosTalk", 22},
    {"gosRegen", 23},
    {"gosRevival", 24},
    {"gosInteraction", 25},
    {"gosInteractionNpc", 26},
    {"gosSwim", 27},
    {"gosSwimDash", 28},
    {"gosClimb", 29},
    {"gosGlide", 30},
    {"gosFallDamage", 31},
    {"gosHold", 32},
    {"gosRide", 33},
    {"gosTransform", 34},
    {"gosPuppet", 35},
    {"gosFloat", 36},
    {"gosTaxiCall", 37},
    {"gosSummon", 38},
    {"gosGotoHome", 39},
    {"gosPvPWinLose", 40},
    {"gosUseFurniture", 41},
    {"gosCashCall", 42},
    {"gosGrabTarget", 43},
    {"gosRecall", 44},
    {"gosFishing", 45},
    {"gosFishingFloat", 46},
    {"gosPlayInstrument", 47},
    {"gosSummonRevive", 48},
    {"gosSummonExpire", 49},
    {"gosSummonItemPick", 50},
    {"gosWarp", 51},
    {"gosTrace", 52},
    {"gosTriggerEmotion", 53},
    {"gosHomeConvenient", 54},
    {"gosHomemade", 55},
    {"gosSummonPortal", 56},
    {"gosAutoInteraction", 57},
    {"gosCoupleEmotion", 58},
    {"gosBanner", 59},
    {"gosMicroGameRps", 60},
    {"gosReact", 61},
    {"gosTreeWatering", 62},
    {"gosObserver", 63},
    {"gosNurturing", 64},
    {"gosSkillMagicControl", 65},
    {"gosMicroGameCoupleDance", 69},
    {"gosTriggerFollowNpc", 70},
    {"gosWeddingEmotion", 71},
    {"gosMAX", 72},
};
static std::pair<const char*, int> s_subStateNames[] = {
    {"SubState_None", 0},
    {"StateIdle_Idle", 1},
    {"StateIdle_Bore_A", 2},
    {"StateIdle_Bore_B", 3},
    {"StateIdle_Bore_C", 4},
    {"StateIdle_Bore_D", 5},
    {"StateIdle_Talk", 6},
    {"StateIdle_Water", 7},
    {"StateIdle_QuestCraft", 8},
    {"StateIdle_UGCCraft", 9},
    {"StateIdle_Fitting", 10},
    {"StateIdle_Fitting_Basic", 11},
    {"StateIdle_Stunt", 12},
    {"StateIdle_CreateCharComplete", 13},
    {"StateIdle_CharacterList", 14},
    {"StateIdle_Happy", 15},
    {"StateIdle_UseSkill", 16},
    {"StateIdle_AutoRevive", 17},
    {"StateIdle_NotUseSkill", 18},
    {"StateIdle_Nutrient", 19},
    {"StateIdle_CharacterSelect_Bore", 20},
    {"StateIdle_CharacterSelect_Bore_Idle", 21},
    {"StateIdle_ListenMusic", 22},
    {"StateWalk_Stunt", 23},
    {"StateWalk_Running", 24},
    {"StateWalk_Walking", 25},
    {"StateWalk_Booster", 26},
    {"StateCrawl_Idle", 27},
    {"StateCrawl_Crawling", 28},
    {"StateDash_ForwardDash", 29},
    {"StateDash_Falling", 30},
    {"StateDash_Landing", 31},
    {"StateDash_Hit", 32},
    {"StateJump_Jump", 33},
    {"StateJump_JumpSpecial", 34},
    {"StateJump_Jump2", 35},
    {"StateJump_JumpSpecial2", 36},
    {"StateJump_JumpRandom", 37},
    {"StateJump_Hit", 38},
    {"StateJump_Stunt", 39},
    {"StateJumpTo_Idle", 40},
    {"StateJumpTo_Done", 41},
    {"StateLadder_Idle", 42},
    {"StateLadder_Up", 43},
    {"StateLadder_Down", 44},
    {"StateLadder_UpLand", 45},
    {"StateLadder_DownLand", 46},
    {"StateLadder_UpTake", 47},
    {"StateLadder_DownTake", 48},
    {"StateLadder_MiddleTake", 49},
    {"StateLadder_Fall", 50},
    {"StateRope_Idle", 51},
    {"StateRope_Up", 52},
    {"StateRope_Down", 53},
    {"StateRope_Middle", 54},
    {"StateRope_Turn", 55},
    {"StateRope_Take", 56},
    {"StateRope_Fall", 57},
    {"StateSkill_Default", 58},
    {"StateSkill_HoldAttack", 59},
    {"StateSkill_MagicControl", 60},
    {"StateStun_LieStart", 61},
    {"StateStun_LieKeep", 62},
    {"StateStun_LieStop", 63},
    {"StateStun_Standing", 64},
    {"StateStun_Freezing", 65},
    {"StateStun_Snare", 66},
    {"StateStun_Vomit", 67},
    {"StateStun_Frozen", 68},
    {"StateStun_Stuck", 69},
    {"StateStun_Custom", 70},
    {"StateTalk_Start", 71},
    {"StateTalk_Loop", 72},
    {"StateTalk_Idle", 73},
    {"StateTalk_EnchantSuccess", 74},
    {"StateTalk_EnchantFail", 75},
    {"StateWaitingSelect_CHANGE_CAP", 76},
    {"StateWaitingSelect_CHANGE_IDLE", 77},
    {"StateWaitingSelect_CHANGE_BODY", 78},
    {"StateWaitingSelect_CHANGE_HEAD", 79},
    {"StateWaitingSelect_CHANGE_HAIR", 80},
    {"StateWaitingSelect_CHANGE_GLOVE", 81},
    {"StateWaitingSelect_CHANGE_MANTLE", 82},
    {"StateWaitingSelect_CHANGE_SHOES", 83},
    {"StateWaitingSelect_CHANGE_WEAPON", 84},
    {"StateWaitingSelect_CHANGE_WEAPON_IDLE", 85},
    {"StateClimb_Idle", 86},
    {"StateClimb_Up", 87},
    {"StateClimb_UpLeft", 88},
    {"StateClimb_UpRight", 89},
    {"StateClimb_Down", 90},
    {"StateClimb_DownLeft", 91},
    {"StateClimb_DownRight", 92},
    {"StateClimb_Left", 93},
    {"StateClimb_Right", 94},
    {"StateClimb_UpLand", 95},
    {"StateClimb_UpTake", 96},
    {"StateClimb_DownTake", 97},
    {"StateClimb_DownLand", 98},
    {"StateGlide_Idle", 99},
    {"StateGlide_Run", 100},
    {"StateTaxiCall_Call", 101},
    {"StateTaxiCall_Arrive", 102},
    {"StateTaxiCall_Wait1", 103},
    {"StateTaxiCall_Wait2", 104},
    {"StateTaxiCall_Leave", 105},
    {"StateTaxiCall_End", 106},
    {"StateCashCall_Call", 107},
    {"StateCashCall_Arrive", 108},
    {"StateCashCall_Leave", 109},
    {"StateCashCall_End", 110},
    {"StateEmotionIdle_Idle", 111},
    {"StateEmotionIdle_Bore_A", 112},
    {"StateEmotionIdle_Bore_B", 113},
    {"StateEmotionIdle_Bore_C", 114},
    {"StatePvPWinLose_Win", 115},
    {"StatePvPWinLose_Lose", 116},
    {"StateFishing_Start", 117},
    {"StateFishing_Idle", 118},
    {"StateFishing_Bore", 119},
    {"StateFishing_FishFighting", 120},
    {"StateFishing_Catch", 121},
    {"StateFishingFloat_Idle", 122},
    {"StateFishingFloat_Fishing", 123},
    {"StateFishingFloat_Catch", 124},
    {"StatePlayInstrument_Ready", 125},
    {"StatePlayInstrument_Playing_Direct", 126},
    {"StatePlayInstrument_Playing_Score_Solo", 127},
    {"StatePlayInstrument_Ready_Score_Ensemble", 128},
    {"StatePlayInstrument_Playing_Score_Ensemble", 129},
    {"StateSummon_React", 130},
    {"StateSummon_Pet", 131},
    {"StateSwim_Swim", 132},
    {"StateSwim_Stunt", 133},
    {"StateLand_Land", 134},
    {"StateLand_Stunt", 135},
    {"StateHomeConvenient_Call", 136},
    {"StateHomeConvenient_End", 137},
    {"StateInteract_Intearct", 138},
    {"StateInteract_Success", 139},
    {"StateInteract_Fail", 140},
    {"StateHomemade_Try", 142},
    {"StateHomemade_Harvest", 143},
    {"StateHomemade_Success", 144},
    {"StateHomemade_Fail", 145},
    {"SubState_Max", 179},
};
static CString s_attachNames[] = {"Head", "Body", "Back", "RHand", "LHand", "RFoot", "LFoot", "Tail", "Hold_Point"};
// Each element is built by std::make_pair (one make_pair<const char (&)[N], int> COMDAT per name length).
static std::pair<const char*, int> s_menuNames[] = {
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
static const efd::Category s_cat_db00(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
static const efd::Category s_cat_c520(efd::UniversalID::ECU_Any, 0xfff, 0x07001008);
static Unk_1418036b0 s_zero;
static Unk_1401cd100 s_pointer(NULL);
static Unk_1418036e0 s_pointer2(NULL);
static CString s_str001 = "02100303";
static CString s_str002 = "buddy_agree";
static CString s_str003 = "buddy_deny";
static CString s_str004 = "buddy_request";
static CString s_str005 = "button_click";
static CString s_str006 = "cinematic_nextkey";
static CString s_str007 = "dialog_close";
static CString s_str008 = "dialog_open";
static CString s_str009 = "System_Fishing_ActionFail";
static CString s_str010 = "System_Fishing_ActionPopup";
static CString s_str011 = "System_Fishing_BookOpen";
static CString s_str012 = "System_Fishing_Cursor_01";
static CString s_str013 = "System_Fishing_Fail";
static CString s_str014 = "System_Fishing_Great_Success";
static CString s_str015 = "System_Fishing_Start";
static CString s_str016 = "System_Fishing_Success";
static CString s_str017 = "System_Fishing_Throw";
static CString s_str018 = "System_Gotcha_Click_01";
static CString s_str019 = "System_Gotcha_Normal_01";
static CString s_str020 = "System_Gotcha_Rolling_01";
static CString s_str021 = "System_Gotcha_Special_01";
static CString s_str022 = "LulluOpenBox_Open";
static CString s_str023 = "LulluOpenBox_SpecialItem_Get";
static CString s_str024 = "LulluOpenBox_10Items_Open";
static CString s_str025 = "LulluOpenBox_Start";
static CString s_str026 = "massive_fail";
static CString s_str027 = "massive_ready";
static CString s_str028 = "massive_success";
static CString s_str029 = "notice_battle_failskill_incorect_weapon";
static CString s_str030 = "notice_battle_hp_10percent";
static CString s_str031 = "02100201";
static CString s_str032 = "pet_eatFood";
static CString s_str033 = "pet_eatFoodSuccess";
static CString s_str034 = "02100200";
static CString s_str035 = "02100199";
static CString s_str036 = "profile_take_photo";
static CString s_str037 = "quest_accept";
static CString s_str038 = "QuestChapter_Close";
static CString s_str039 = "quest_complete";
static CString s_str040 = "QuestChapter_Open";
static CString s_str041 = "quest_progress";
static CString s_str042 = "quest_reward";
static CString s_str043 = "System_Random_Coupon_01";
static CString s_str044 = "System_Random_Coupon_02";
static CString s_str045 = "System_Random_Coupon_03";
static CString s_str046 = "System_UI_Shadow_Off_01";
static CString s_str047 = "System_UI_Shadow_On_01";
static CString s_str048 = "System_UI_Shadow_Upgrade_01";
static CString s_str049 = "shop_dialog_close";
static CString s_str050 = "shop_dialog_open";
static CString s_str051 = "shop_itembuy";
static CString s_str052 = "shop_itemsell";
static CString s_str053 = "shop_reset";
static CString s_str054 = "shop_reset_fail";
static CString s_str055 = "skill_put_onoff";
static CString s_str056 = "System_Gemstone_Upgrade_01";
static CString s_str057 = "System_Gemstone_button_01";
static CString s_str058 = "System_Gemstone_Success_01";
static CString s_str059 = "store_dialog_close";
static CString s_str060 = "store_dialog_open";
static CString s_str061 = "store_itemin";
static CString s_str062 = "store_itemout";
static CString s_str063 = "System_Draw_01";
static CString s_str064 = "System_Fight_01";
static CString s_str065 = "System_GetReady_01";
static CString s_str066 = "System_Pefect_01";
static CString s_str067 = "Voice_Draw_01";
static CString s_str068 = "Voice_Fight_01";
static CString s_str069 = "Voice_GetReady_01";
static CString s_str070 = "Voice_Pefect_01";
static CString s_str071 = "Voice_YouLose_01";
static CString s_str072 = "Voice_YouWin_01";
static CString s_str073 = "System_YouLose_01";
static CString s_str074 = "System_YouWin_01";
static CString s_str075 = "AttendGift_Stamp";
static CString s_str076 = "BattleField_Kill";
static CString s_str077 = "BattleField_Win";
static CString s_str078 = "System_Bingo_LineComplete_01";
static CString s_str079 = "System_Bingo_RegPopUp_01";
static CString s_str080 = "System_Bingo_SpecialPopUp_01";
static CString s_str081 = "System_Bingo_Success_01";
static CString s_str082 = "BlackMarket_Sell";
static CString s_str083 = "System_BluePing_01";
static CString s_str084 = "PC_buy_house";
static CString s_str085 = "cash_InventorytoBag";
static CString s_str086 = "cash_Buy";
static CString s_str087 = "cinematic_getItem";
static CString s_str088 = "ugc_EndMode";
static CString s_str089 = "PC_create_character";
static CString s_str090 = "PC_cure_deadPanelty";
static CString s_str091 = "button_click";
static CString s_str092 = "button_click";
static CString s_str093 = "emergency_notice";
static CString s_str094 = "Enchant_Fail";
static CString s_str095 = "Enchant_FailEffect";
static CString s_str096 = "Enchant_ItemChoice";
static CString s_str097 = "Enchant_OptionChoice";
static CString s_str098 = "Enchant_Progress";
static CString s_str099 = "Enchant_Success";
static CString s_str100 = "Enchant_SuccessEffect";
static CString s_str101 = "System_EnterHouse";
static CString s_str102 = "system_expandbankSlot";
static CString s_str103 = "System_FieldWar";
static CString s_str104 = "Telescope_Find";
static CString s_str105 = "PC_TitleGet";
static CString s_str106 = "PC_Attendance";
static CString s_str107 = "cash_Buy";
static CString s_str108 = "system_GroupChat";
static CString s_str109 = "system_guide_tooltip";
static CString s_str110 = "System_GuildInvitation";
static CString s_str111 = "PC_GuildMake";
static CString s_str112 = "System_GuildMegaphone";
static CString s_str113 = "guildBattle_Apply";
static CString s_str114 = "GuildBattle_Enter";
static CString s_str115 = "guildBattle_MatchingFail";
static CString s_str116 = "guildBattle_MatchingSuccess";
static CString s_str117 = "system_notice_GuildBattleMatching01";
static CString s_str118 = "GuildBattle_MemberPick";
static CString s_str119 = "guildBattle_Reward";
static CString s_str120 = "GuildBattle_SemiLose";
static CString s_str121 = "GuildBattle_SemiWin";
static CString s_str122 = "System_HideNSeek_Jump_01";
static CString s_str123 = "System_HideNSeek_Result_01";
static CString s_str124 = "System_HideNSeek_Spin_01";
static CString s_str125 = "System_HouseIcon";
static CString s_str126 = "PC_investigation_goldChest";
static CString s_str127 = "Extract_End";
static CString s_str128 = "Extract_ItemChoice";
static CString s_str129 = "Extract_Progress";
static CString s_str130 = "PC_SkillGet";
static CString s_str131 = "mail_delete";
static CString s_str132 = "system_mail_event_popdown";
static CString s_str133 = "system_mail_event_popup";
static CString s_str134 = "mail_recieve";
static CString s_str135 = "PC_make_ugcItem";
static CString s_str136 = "maid_Cancel";
static CString s_str137 = "maid_Finish";
static CString s_str138 = "maid_Firework";
static CString s_str139 = "maid_Receive";
static CString s_str140 = "maid_Receive_Jackpot";
static CString s_str141 = "maid_Request";
static CString s_str142 = "System_Matching_Popup_01";
static CString s_str143 = "System_MaviewClose";
static CString s_str144 = "System_MaviewOpen";
static CString s_str145 = "design_Upload";
static CString s_str146 = "cash_Buy";
static CString s_str147 = "Market_Caculate";
static CString s_str148 = "PC_ugc_endsale";
static CString s_str149 = "Market_ItemChoice";
static CString s_str150 = "system_notice_confirm";
static CString s_str151 = "system_notice_error";
static CString s_str152 = "system_notice_error_ep";
static CString s_str153 = "system_notice_error_sp";
static CString s_str154 = "system_notice_error_warningBag";
static CString s_str155 = "system_notice_error_warningClass";
static CString s_str156 = "system_notice_error_warningGender";
static CString s_str157 = "system_notice_error_warningLevel";
static CString s_str158 = "system_notice_error_warningNotThisPlace";
static CString s_str159 = "system_notice_error_warningWeapon";
static CString s_str160 = "system_notice_warningDanger";
static CString s_str161 = "system_notice_error_warningBuildingCount";
static CString s_str162 = "system_notice_error_warningDefaultLand";
static CString s_str163 = "system_notice_error_warningDefaultLandRotation";
static CString s_str164 = "system_notice_error_warningNoBuild";
static CString s_str165 = "system_notice_error_warningNoBuildLand";
static CString s_str166 = "system_notice_error_warningNoChangeCube";
static CString s_str167 = "system_notice_error_warningNoTearDown";
static CString s_str168 = "system_notice_error_warningNoWall";
static CString s_str169 = "system_notice_error_warningNotThisPlace";
static CString s_str170 = "system_notice_error_warningNotThisTime";
static CString s_str171 = "system_notice_error_warningOnlyWall";
static CString s_str172 = "system_notice_whisper";
static CString s_str173 = "System_PartyReady_Popup_01";
static CString s_str174 = "system_pcbang_gift{0}";
static CString s_str175 = "System_PinkBeans_Arcade_Click_01";
static CString s_str176 = "button_click";
static CString s_str177 = "button_click";
static CString s_str178 = "System_KillPlayer";
static CString s_str179 = "System_KillSlayer";
static CString s_str180 = "System_RedPing_01";
static CString s_str181 = "PremiumShop_ReportSiren";
static CString s_str182 = "System_ReportClose";
static CString s_str183 = "System_ReportOpen";
static CString s_str184 = "PC_InviteFail";
static CString s_str185 = "PC_InviteSuccess";
static CString s_str186 = "PC_ReturnHouse";
static CString s_str187 = "system_smart_recommend_dialog_open";
static CString s_str188 = "spin_MultiSelect";
static CString s_str189 = "spin_MultiStart";
static CString s_str190 = "spin_Select";
static CString s_str191 = "spin_Start";
static CString s_str192 = "Summon_Cash";
static CString s_str193 = "Change_Dagger";
static CString s_str194 = "PC_take_photo";
static CString s_str195 = "PC_Taxi_Call";
static CString s_str196 = "system_Taxi_Find";
static CString s_str197 = "system_TimeLimit";
static CString s_str198 = "trade_lock";
static CString s_str199 = "trade_unlock";
static CString s_str200 = "system_Trophy_Daily";
static CString s_str201 = "system_Trophy_Hero";
static CString s_str202 = "system_Trophy_Reward_Get";
static CString s_str203 = "System_TypingGame_Fail_01";
static CString s_str204 = "System_TypingGame_Key_Hit_01";
static CString s_str205 = "System_TypingGame_Key_PopUp_01";
static CString s_str206 = "System_TypingGame_Success_01";
static CString s_str207 = "System_BuildOpenShop";
static CString s_str208 = "ugc_buyland";
static CString s_str209 = "ugc_changeMode";
static CString s_str210 = "ugc_moveblock";
static CString s_str211 = "ugc_removeblock";
static CString s_str212 = "ugc_rotateblock";
static CString s_str213 = "ugc_sellland";
static CString s_str214 = "ugc_setblock";
static CString s_str215 = "PC_use_telescope";
static CString s_str216 = "PC_win_game";
static CString s_str217 = "store_itemout";
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb9940-0x142cbb550 .text$yd
