// commonresource.h - PLACEHOLDER for CommonResource (RTTI .?AVCommonResource@@, 0x608 bytes). NOT an original header.
// Bases: TSingleton<CommonResource> at +0x0, CValidData<CommonResource> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates and loads (Load, 0x140cca010). It reads
// Table/commonResource.xml, a <ms2><... key="" value=""/> list, into the key/value map at +0x30 and then copies the
// well-known keys (resource directories, default icons, effect and weather names, fishing and instrument effects) into
// the string members below. Member names are invented from the key they hold.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"

// The key/value map of the xml (ctor 0x1402bc570 with 10 buckets, dtor 0x1402bd1d0). Its layout is not recovered.
class Unk_CrKeyMap
{
public:
    Unk_CrKeyMap(int nBuckets);                                 // 0x1402bc570
    ~Unk_CrKeyMap();                                            // 0x1402bd1d0
    void RemoveAll();                                           // 0x1402c28d0
    void SetAt(const CString& strKey, const CString& strValue); // 0x1402c2b10
    bool Lookup(const CString& strKey, CString& strValue);      // 0x1402c1f40
private:
    char m_unk[0x30];
};
MS2_CHECK_SIZE(Unk_CrKeyMap, 0x30);

class CommonResource : public TSingleton<CommonResource>, public CValidData<CommonResource>
{
public:
    CommonResource();                                       // 0x140cc2da0
    virtual ~CommonResource();                              // 0x140cc3a80
    bool Load();                                            // 0x140cca010 (xml, then the members)
    void CheckReload();                                     // 0x140cc9c00 (a cached file changed on disk: Load again)
    CString GetPath(int nKind);                             // 0x140cca050 (2 = +0x1d8, else +0x1c8)
    CString GetValue(const CString& strKey);                // 0x140cca0e0 (the map value of a key)
    static void CheckInit();                                // 0x140cca5d0 (error box when Load has not run)
    static void SetInit(bool bInit) { s_bInit = bInit; }    // 0x140cca690
    static bool s_bInit;                                    // DAT_143ac0498
    bool LoadXml();                                         // 0x140cc9c90 (fills m_map, true on success)
    void LoadMembers();                                     // 0x140cc4720 (m_map into the members)

    ATL::CAtlArray<MS2Ptr<CCacheData> > m_caches;           // +0x10 the loaded files
    Unk_CrKeyMap m_map;                                     // +0x30 key -> value of the xml
    CString m_strResourcePath;                       // +0x60 "RESOURCE_PATH"
    CString m_strImagePath;                          // +0x68 "IMAGE_PATH"
    CString m_strModelPath;                          // +0x70 "MODEL_PATH"
    CString m_strSoundPath;                          // +0x78 "SOUND_PATH"
    CString m_strSoundFmodPath;                      // +0x80 "SOUND_FMOD_PATH"
    CString m_strIllustPath;                         // +0x88 "ILLUST_PATH"
    CString m_strDefaultProfileImagePath;            // +0x90 "DEFAULT_PROFILE_IMAGE_PATH"
    CString m_strDefaultGuildMarkImagePath;          // +0x98 "DEFAULT_GUILD_MARK_IMAGE_PATH"
    CString m_strDefaultGuildMarkImageBattlePath;    // +0xa0 "DEFAULT_GUILD_MARK_IMAGE_BATTLE_PATH"
    CString m_strDefaultBlindImagePath;              // +0xa8 "DEFAULT_BLIND_IMAGE_PATH"
    CString m_strDefaultBlindBannerPath;             // +0xb0 "DEFAULT_BLIND_BANNER_PATH"
    CString m_strDefaultMeratmarketImagePath;        // +0xb8 "DEFAULT_MERATMARKET_IMAGE_PATH"
    CString m_strDefaultMeratmarketLimitedIconPath;  // +0xc0 "DEFAULT_MERATMARKET_LIMITED_ICON_PATH"
    CString m_strDefaultBlueprintTooltipImagePath;   // +0xc8 "DEFAULT_BLUEPRINT_TOOLTIP_IMAGE_PATH"
    CString m_strWorldmapTilePath;                   // +0xd0 "WORLDMAP_TILE_PATH"
    CString m_strUgcIconCaptureFileFullPath;         // +0xd8 "UGC_ICON_CAPTURE_FILE_FULL_PATH"
    CString m_strHdrPath;                            // +0xe0 "HDR_PATH"
    CString m_strDistortionPath;                     // +0xe8 "distortion_path"
    CString m_strObjectShadowDDS;                    // +0xf0 "objectShadowDDS"
    CString m_strVectorNoiseDDS;                     // +0xf8 "vectorNoiseDDS"
    CString m_strRainDropPath;                       // +0x100 "rainDropPath"
    CString m_strFittingDollMDefaultC;               // +0x108 "fittingDoll_M_Default_C"
    CString m_strFittingDollMDefaultS;               // +0x110 "fittingDoll_M_Default_S"
    CString m_strFittingDollMDefaultCPath;           // +0x118 "fittingDoll_M_Default_C_Path"
    CString m_strFittingDollMDefaultSPath;           // +0x120 "fittingDoll_M_Default_S_Path"
    CString m_strBloodTexturePath;                   // +0x128 "bloodTexturePath"
    CString m_strDecalTextureName01;                 // +0x130 "decalTextureName01"
    CString m_strDecalTextureName02;                 // +0x138 "decalTextureName02"
    CString m_strDecalTextureName03;                 // +0x140 "decalTextureName03"
    CString m_strDecalTextureName04;                 // +0x148 "decalTextureName04"
    CString m_strExpIconPath;                        // +0x150 "exp_icon_path"
    CString m_strMesoIconPath;                       // +0x158 "meso_icon_path"
    CString m_strFieldEnteranceIconPath;             // +0x160 "field_enterance_icon_path"
    CString m_strShopUnlockIconPath;                 // +0x168 "shop_unlock_icon_path"
    CString m_strTitleIconPath;                      // +0x170 "title_icon_path"
    CString m_strKarmaTokenIconPath;                 // +0x178 "karma_token_icon_path"
    CString m_strHonorTokenIconPath;                 // +0x180 "honor_token_icon_path"
    CString m_strLuTokenIconPath;                    // +0x188 "lu_token_icon_path"
    CString m_strHabiTokenIconPath;                  // +0x190 "habi_token_icon_path"
    CString m_strShardTokenIconPath;                 // +0x198 "shard_token_icon_path"
    CString m_strReverseCoinIconPath;                // +0x1a0 "reverse_coin_icon_path"
    CString m_strMentorTokenIconPath;                // +0x1a8 "mentor_token_icon_path"
    CString m_strMenteeTokenIconPath;                // +0x1b0 "mentee_token_icon_path"
    CString m_strStarPointIconPath;                  // +0x1b8 "star_point_icon_path"
    CString m_strMesoMarketTokenIconPath;            // +0x1c0 "meso_market_token_icon_path"
    CString m_strSkillPointIconPath;                 // +0x1c8 "skill_point_icon_path"
    CString m_strStatPointIconPath;                  // +0x1d0 "stat_point_icon_path"
    CString m_strSkillPoint2IconPath;                // +0x1d8 "skill_point2_icon_path"
    CString m_strCenterMark;                         // +0x1e0 "centerMark"
    CString m_strCubeMarkEnable;                     // +0x1e8 "cubeMarkEnable"
    CString m_strCubeMarkDisable;                    // +0x1f0 "cubeMarkDisable"
    CString m_strCubeMarkEmpty;                      // +0x1f8 "cubeMarkEmpty"
    CString m_strPortalArrow;                        // +0x200 "portalArrow"
    CString m_strWeatherSnowSoft;                    // +0x208 "weatherSnowSoft"
    CString m_strWeatherSnowHeavy;                   // +0x210 "weatherSnowHeavy"
    CString m_strWeatherRainSoft;                    // +0x218 "weatherRainSoft"
    CString m_strWeatherRainHeavy;                   // +0x220 "weatherRainHeavy"
    CString m_strWeatherSandstorm;                   // +0x228 "weatherSandstorm"
    CString m_strWeatherCherryBlossom;               // +0x230 "weatherCherryBlossom"
    CString m_strWeatherLeafFall;                    // +0x238 "weatherLeafFall"
    CString m_strSelectGizmo;                        // +0x240 "selectGizmo"
    CString m_strTranslateGizmo;                     // +0x248 "translateGizmo"
    CString m_strBossItemBonusIconLv1;               // +0x250 "bossItemBonusIconLv1"
    CString m_strBossItemBonusIconLv2;               // +0x258 "bossItemBonusIconLv2"
    CString m_strBossItemBonusIconLv3;               // +0x260 "bossItemBonusIconLv3"
    CString m_strRevivalInvincible;                  // +0x268 "Revival_Invincible"
    CString m_strJumpDash;                           // +0x270 "jump_Dash"
    CString m_strDeadStartMyPCPvP;                   // +0x278 "dead_Start_MyPC_PvP"
    CString m_strDeadStartMyPC;                      // +0x280 "dead_Start_MyPC"
    CString m_strNpcSuperArmor;                      // +0x288 "NPC_SuperArmor"
    CString m_strEnchantSuccess;                     // +0x290 "enchant_Success"
    CString m_strEnchantFail;                        // +0x298 "enchant_Fail"
    CString m_strRemoveCube;                         // +0x2a0 "remove_Cube"
    CString m_strTrophyBuff;                         // +0x2a8 "TROPHY_BUFF"
    CString m_strItemRideUse;                        // +0x2b0 "item_Ride_Use"
    CString m_strItemRideUnUse;                      // +0x2b8 "item_Ride_UnUse"
    CString m_strQuestobjectOn;                      // +0x2c0 "questobject_On"
    CString m_strChangeJobs;                         // +0x2c8 "changeJobs"
    CString m_strFemaleDropDamgVoice;                // +0x2d0 "female_DropDamg_Voice"
    CString m_strMaleDropDamgVoice;                  // +0x2d8 "male_DropDamg_Voice"
    CString m_strCustomizingFinish;                  // +0x2e0 "customizing_Finish"
    CString m_strProjector;                          // +0x2e8 "projector"
    CString m_strTimeLimit;                          // +0x2f0 "timeLimit"
    CString m_strTutorialSoundArrow;                 // +0x2f8 "tutorial_Sound_arrow"
    CString m_strComForsaleA01;                      // +0x300 "com_forsaleA_01"
    CString m_strRegenerateCube;                     // +0x308 "regenerate_Cube"
    CString m_strEffectCustomizingReleaseMouse;      // +0x310 "EFFECT_CUSTOMIZING_RELEASE_MOUSE"
    CString m_strEffectSwooshTest;                   // +0x318 "EFFECT_SWOOSH_TEST"
    CString m_strEffectFullscreenGrayscale;          // +0x320 "EFFECT_FULLSCREEN_GRAYSCALE"
    CString m_strEffectLevelUp;                      // +0x328 "EFFECT_LEVEL_UP"
    CString m_strEffectRevivalPc;                    // +0x330 "EFFECT_REVIVAL_PC"
    CString m_strEffectGetExp;                       // +0x338 "EFFECT_GET_EXP"
    CString m_strEffectGetExpEnd;                    // +0x340 "EFFECT_GET_EXP_END"
    CString m_strEffectLiftableCubeMarker;           // +0x348 "EFFECT_LIFTABLE_CUBE_MARKER"
    CString m_strEffectLiftableQuestEffect;          // +0x350 "EFFECT_LIFTABLE_QUEST_EFFECT"
    CString m_strEffectResolvePanelty;               // +0x358 "EFFECT_RESOLVE_PANELTY"
    CString m_strEffectTaxiDefault;                  // +0x360 "EFFECT_TAXI_DEFAULT"
    CString m_strEffectTaxiArrive;                   // +0x368 "EFFECT_TAXI_ARRIVE"
    CString m_strEffectTaxiWait;                     // +0x370 "EFFECT_TAXI_WAIT"
    CString m_strEffectTaxiLeave;                    // +0x378 "EFFECT_TAXI_LEAVE"
    CString m_strEffectTaxiReveal;                   // +0x380 "EFFECT_TAXI_REVEAL"
    CString m_strEffectTaxiArriveBestdriver;         // +0x388 "EFFECT_TAXI_ARRIVE_BESTDRIVER"
    CString m_strEffectTaxiWaitBestdriver;           // +0x390 "EFFECT_TAXI_WAIT_BESTDRIVER"
    CString m_strEffectTaxiLeaveBestdriver;          // +0x398 "EFFECT_TAXI_LEAVE_BESTDRIVER"
    CString m_strEffectAirtaxiCash;                  // +0x3a0 "EFFECT_AIRTAXI_CASH"
    CString m_strEffectAirtaxiMeso;                  // +0x3a8 "EFFECT_AIRTAXI_MESO"
    CString m_strEffectCashCallMedic;                // +0x3b0 "EFFECT_CASH_CALL_MEDIC"
    CString m_strEffectCashCallBlackMarket;          // +0x3b8 "EFFECT_CASH_CALL_BLACK_MARKET"
    CString m_strEffectWeatherRain;                  // +0x3c0 "EFFECT_WEATHER_RAIN"
    CString m_strEffectWeatherHeabyRain;             // +0x3c8 "EFFECT_WEATHER_HEABY_RAIN"
    CString m_strEffectWeatherSnow;                  // +0x3d0 "EFFECT_WEATHER_SNOW"
    CString m_strEffectWeatherHeabySnow;             // +0x3d8 "EFFECT_WEATHER_HEABY_SNOW"
    CString m_strEffectWeatherSandstorm;             // +0x3e0 "EFFECT_WEATHER_SANDSTORM"
    CString m_strEffectWeatherCherryblossom;         // +0x3e8 "EFFECT_WEATHER_CHERRYBLOSSOM"
    CString m_strEffectWeatherLeafFall;              // +0x3f0 "EFFECT_WEATHER_LEAF_FALL"
    CString m_strFishingCursorEnabled;               // +0x3f8 "FISHING_CURSOR_ENABLED"
    CString m_strFishingCursorDisabled;              // +0x400 "FISHING_CURSOR_DISABLED"
    CString m_strFishingWaterSplash;                 // +0x408 "FISHING_WATER_SPLASH"
    CString m_strFishingFloatBaitEffect;             // +0x410 "FISHING_FLOAT_BAIT_EFFECT"
    CString m_strFishingLineEffect;                  // +0x418 "FISHING_LINE_EFFECT"
    CString m_strFishGuideCubeEffect;                // +0x420 "FISH_GUIDE_CUBE_EFFECT"
    CString m_strFishHintEffect[4];                         // +0x428 "FISH_HINT_EFFECT_SMALL/MEDIUM/LARGE/BIG_FISH"
    CString m_strFishBoundEffect[4];                        // +0x448 "FISH_BOUND_EFFECT_SMALL/MEDIUM/LARGE/BIG_FISH"
    CString m_strFishingFloatAsset[0x16];                   // +0x468 [1..21] by float tier (BEGINNER 1-4, INTERMEDIATE 5-8, ..)
    CString m_strEffectInstrumentPlayDirect;                   // +0x518 "EFFECT_INSTRUMENT_PLAY_DIRECT"
    CString m_strEffectInstrumentPlayScoreSolo;                // +0x520 "EFFECT_INSTRUMENT_PLAY_SCORE_SOLO"
    CString m_strEffectInstrumentWaitScoreEnsemble;            // +0x528 "EFFECT_INSTRUMENT_WAIT_SCORE_ENSEMBLE"
    CString m_strEffectInstrumentPlayScoreEnsemble;            // +0x530 "EFFECT_INSTRUMENT_PLAY_SCORE_ENSEMBLE"
    CString m_strEffectInstrumentMuteDirect;                   // +0x538 "EFFECT_INSTRUMENT_MUTE_DIRECT"
    CString m_strEffectInstrumentMuteScoreSolo;                // +0x540 "EFFECT_INSTRUMENT_MUTE_SCORE_SOLO"
    CString m_strEffectInstrumentMuteScoreEnsemble;            // +0x548 "EFFECT_INSTRUMENT_MUTE_SCORE_ENSEMBLE"
    CString m_strEffectInstrumentPlayDirectExpensive;          // +0x550 "EFFECT_INSTRUMENT_PLAY_DIRECT_EXPENSIVE"
    CString m_strEffectInstrumentPlayScoreSoloExpensive;       // +0x558 "EFFECT_INSTRUMENT_PLAY_SCORE_SOLO_EXPENSIVE"
    CString m_strEffectInstrumentWaitScoreEnsembleExpensive;   // +0x560 "EFFECT_INSTRUMENT_WAIT_SCORE_ENSEMBLE_EXPENSIVE"
    CString m_strEffectInstrumentPlayScoreEnsembleExpensive;   // +0x568 "EFFECT_INSTRUMENT_PLAY_SCORE_ENSEMBLE_EXPENSIVE"
    CString m_strEffectInstrumentMuteDirectExpensive;          // +0x570 "EFFECT_INSTRUMENT_MUTE_DIRECT_EXPENSIVE"
    CString m_strEffectInstrumentMuteScoreSoloExpensive;       // +0x578 "EFFECT_INSTRUMENT_MUTE_SCORE_SOLO_EXPENSIVE"
    CString m_strEffectInstrumentMuteScoreEnsembleExpensive;   // +0x580 "EFFECT_INSTRUMENT_MUTE_SCORE_ENSEMBLE_EXPENSIVE"
    CString m_strEffectInstrumentStartMusic;                   // +0x588 "EFFECT_INSTRUMENT_START_MUSIC"
    CString m_strEffectInstrumentStopMusic;                    // +0x590 "EFFECT_INSTRUMENT_STOP_MUSIC"
    CString m_strEffectInstrumentConcertFirework;              // +0x598 "EFFECT_INSTRUMENT_CONCERT_FIREWORK"
    CString m_strEffectSummonPortal;                           // +0x5a0 "EFFECT_SUMMON_PORTAL"
    CString m_strMusicScorePremiumShopSample;                  // +0x5a8 "MUSIC_SCORE_PREMIUM_SHOP_SAMPLE"
    CString m_strEffectAdventureLevelUp;                       // +0x5b0 "EFFECT_ADVENTURE_LEVEL_UP"
    CString m_strAllianceSidePopupIllust[10];               // +0x5b8 [1..9] "allinace_sidepopup_illust_{0}"
private:
    MS2_LAYOUT_FRIEND;
};
MS2_CHECK_SIZE(CommonResource, 0x608);
