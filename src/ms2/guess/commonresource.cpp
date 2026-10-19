// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CommonResource: the singleton that reads Table/commonResource.xml
// (key/value pairs: resource directories, default images, token icons, effect/weather/fishing/instrument effect names)
// and copies the known keys into string members; plus the illust path and the KFM path helpers around it.
// MS2-UNIT: ?\commonresource.cpp
// MS2-RANGE: 0x140cc2c70-0x140cca6a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$StringFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV01@1@Z 0x140cca160 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetModelPath@NiKFMTool@@QEBAAEBVNiFixedString@@XZ 0x140cca680
// MS2-PIN: ??_7CommonResource@@6B?$TSingleton@VCommonResource@@@@@ 0x142e1c780
// MS2-PIN: ??_7CommonResource@@6B?$CValidData@VCommonResource@@@@@ 0x142e1c790
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\commonresource.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <typeinfo>
#include "ms2/placeholder/commonresource.h"
#include <egf/EntityManager.h>
#include <NiKFMTool.h>
#include <NiActorManager.h>
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
CString FUN_14016a5c0(const char* psz, int nCodePage);                   // narrows a string (the RTTI name in CheckInit)
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
Unk_140165cf0* FUN_140345b40(TiXmlDocument* pDoc);                       // the document's first child element
Unk_140165cf0* FUN_140345b40(Unk_140165cf0* pNode);                      // first child element
Unk_140165cf0* FUN_1403f0510(Unk_140165cf0* pNode);                      // next sibling element
const char* FUN_140189180(Unk_140165cf0* pElem);                         // the element name
CString FUN_140188f50(const char* psz, int nCodePage);                   // CString from a C string
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);    // attribute text (null = absent)
CString FUN_14021a6b0(int n);                                            // int to string
CString FUN_140540050(const char* pszFormat, const CString& strArg);     // StringFormat with one string

// The animation service (singleton behind FUN_141b6f910): the actor manager of an entity.
class Unk_CrAnimSvc { public: NiActorManager* FUN_140999440(const egf::EntityID& kId); };
Unk_CrAnimSvc* FUN_141b6f910();
NiKFMTool* FUN_1409995d0(NiActorManager* pActorMgr);                     // the actor manager's KFM tool

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CommonResource::s_bInit;
#endif

// @0x140cc2c70
CString FUN_140cc2c70(const CString& strName)
{
    if (strName.IsEmpty())
        return CString("");
    return StringFormat("{0}{1}.dds", TSingleton<CommonResource>::GetInstance()->m_strIllustPath, strName);
}


// @0x140cc2d00
void FUN_140cc2d00(const egf::EntityID& kId, CString* pOut)
{
    NiActorManager* pActorMgr = FUN_141b6f910()->FUN_140999440(kId);
    if (pActorMgr == 0)
        return;
    NiKFMTool* pKfm = FUN_1409995d0(pActorMgr);
    if (pKfm == 0)
        return;
    NiFixedString kPath(pKfm->GetModelPath());
    *pOut = (const char*)kPath;
}

// @0x140cc2da0
CommonResource::CommonResource()
    : m_map(10)
{
}

// @0x140cc3a80
CommonResource::~CommonResource()
{
}

// @0x140cc4720
void CommonResource::LoadMembers()
{
    m_strResourcePath = GetValue("RESOURCE_PATH");
    m_strImagePath = GetValue("IMAGE_PATH");
    m_strModelPath = GetValue("MODEL_PATH");
    m_strSoundPath = GetValue("SOUND_PATH");
    m_strSoundFmodPath = GetValue("SOUND_FMOD_PATH");
    m_strIllustPath = GetValue("ILLUST_PATH");
    m_strDefaultProfileImagePath = GetValue("DEFAULT_PROFILE_IMAGE_PATH");
    m_strDefaultGuildMarkImagePath = GetValue("DEFAULT_GUILD_MARK_IMAGE_PATH");
    m_strDefaultGuildMarkImageBattlePath = GetValue("DEFAULT_GUILD_MARK_IMAGE_BATTLE_PATH");
    m_strDefaultBlindImagePath = GetValue("DEFAULT_BLIND_IMAGE_PATH");
    m_strDefaultBlindBannerPath = GetValue("DEFAULT_BLIND_BANNER_PATH");
    m_strDefaultMeratmarketImagePath = GetValue("DEFAULT_MERATMARKET_IMAGE_PATH");
    m_strDefaultMeratmarketLimitedIconPath = GetValue("DEFAULT_MERATMARKET_LIMITED_ICON_PATH");
    m_strDefaultBlueprintTooltipImagePath = GetValue("DEFAULT_BLUEPRINT_TOOLTIP_IMAGE_PATH");
    m_strWorldmapTilePath = GetValue("WORLDMAP_TILE_PATH");
    m_strUgcIconCaptureFileFullPath = GetValue("UGC_ICON_CAPTURE_FILE_FULL_PATH");
    m_strObjectShadowDDS = GetValue("objectShadowDDS");
    m_strVectorNoiseDDS = GetValue("vectorNoiseDDS");
    m_strHdrPath = GetValue("HDR_PATH");
    m_strDistortionPath = GetValue("distortion_path");
    m_strRainDropPath = GetValue("rainDropPath");
    m_strFittingDollMDefaultC = GetValue("fittingDoll_M_Default_C");
    m_strFittingDollMDefaultS = GetValue("fittingDoll_M_Default_S");
    m_strFittingDollMDefaultCPath = GetValue("fittingDoll_M_Default_C_Path");
    m_strFittingDollMDefaultSPath = GetValue("fittingDoll_M_Default_S_Path");
    m_strBloodTexturePath = GetValue("bloodTexturePath");
    m_strDecalTextureName01 = GetValue("decalTextureName01");
    m_strDecalTextureName02 = GetValue("decalTextureName02");
    m_strDecalTextureName03 = GetValue("decalTextureName03");
    m_strDecalTextureName04 = GetValue("decalTextureName04");
    m_strExpIconPath = GetValue("exp_icon_path");
    m_strMesoIconPath = GetValue("meso_icon_path");
    m_strFieldEnteranceIconPath = GetValue("field_enterance_icon_path");
    m_strShopUnlockIconPath = GetValue("shop_unlock_icon_path");
    m_strTitleIconPath = GetValue("title_icon_path");
    m_strKarmaTokenIconPath = GetValue("karma_token_icon_path");
    m_strHonorTokenIconPath = GetValue("honor_token_icon_path");
    m_strLuTokenIconPath = GetValue("lu_token_icon_path");
    m_strHabiTokenIconPath = GetValue("habi_token_icon_path");
    m_strShardTokenIconPath = GetValue("shard_token_icon_path");
    m_strReverseCoinIconPath = GetValue("reverse_coin_icon_path");
    m_strMentorTokenIconPath = GetValue("mentor_token_icon_path");
    m_strMenteeTokenIconPath = GetValue("mentee_token_icon_path");
    m_strStarPointIconPath = GetValue("star_point_icon_path");
    m_strMesoMarketTokenIconPath = GetValue("meso_market_token_icon_path");
    m_strSkillPointIconPath = GetValue("skill_point_icon_path");
    m_strStatPointIconPath = GetValue("stat_point_icon_path");
    m_strSkillPoint2IconPath = GetValue("skill_point2_icon_path");
    m_strCenterMark = GetValue("centerMark");
    m_strCubeMarkEnable = GetValue("cubeMarkEnable");
    m_strCubeMarkDisable = GetValue("cubeMarkDisable");
    m_strCubeMarkEmpty = GetValue("cubeMarkEmpty");
    m_strPortalArrow = GetValue("portalArrow");
    m_strWeatherSnowSoft = GetValue("weatherSnowSoft");
    m_strWeatherSnowHeavy = GetValue("weatherSnowHeavy");
    m_strWeatherRainSoft = GetValue("weatherRainSoft");
    m_strWeatherRainHeavy = GetValue("weatherRainHeavy");
    m_strWeatherSandstorm = GetValue("weatherSandstorm");
    m_strWeatherCherryBlossom = GetValue("weatherCherryBlossom");
    m_strWeatherLeafFall = GetValue("weatherLeafFall");
    m_strTranslateGizmo = GetValue("translateGizmo");
    m_strSelectGizmo = GetValue("selectGizmo");
    m_strRevivalInvincible = GetValue("Revival_Invincible");
    m_strJumpDash = GetValue("jump_Dash");
    m_strDeadStartMyPCPvP = GetValue("dead_Start_MyPC_PvP");
    m_strDeadStartMyPC = GetValue("dead_Start_MyPC");
    m_strNpcSuperArmor = GetValue("NPC_SuperArmor");
    m_strEnchantSuccess = GetValue("enchant_Success");
    m_strEnchantFail = GetValue("enchant_Fail");
    m_strRemoveCube = GetValue("remove_Cube");
    m_strTrophyBuff = GetValue("TROPHY_BUFF");
    m_strItemRideUse = GetValue("item_Ride_Use");
    m_strItemRideUnUse = GetValue("item_Ride_UnUse");
    m_strQuestobjectOn = GetValue("questobject_On");
    m_strChangeJobs = GetValue("changeJobs");
    m_strFemaleDropDamgVoice = GetValue("female_DropDamg_Voice");
    m_strMaleDropDamgVoice = GetValue("male_DropDamg_Voice");
    m_strCustomizingFinish = GetValue("customizing_Finish");
    m_strProjector = GetValue("projector");
    m_strTimeLimit = GetValue("timeLimit");
    m_strTutorialSoundArrow = GetValue("tutorial_Sound_arrow");
    m_strComForsaleA01 = GetValue("com_forsaleA_01");
    m_strRegenerateCube = GetValue("regenerate_Cube");
    m_strBossItemBonusIconLv1 = GetValue("bossItemBonusIconLv1");
    m_strBossItemBonusIconLv2 = GetValue("bossItemBonusIconLv2");
    m_strBossItemBonusIconLv3 = GetValue("bossItemBonusIconLv3");
    m_strEffectCustomizingReleaseMouse = GetValue("EFFECT_CUSTOMIZING_RELEASE_MOUSE");
    m_strEffectSwooshTest = GetValue("EFFECT_SWOOSH_TEST");
    m_strEffectFullscreenGrayscale = GetValue("EFFECT_FULLSCREEN_GRAYSCALE");
    m_strEffectLevelUp = GetValue("EFFECT_LEVEL_UP");
    m_strEffectRevivalPc = GetValue("EFFECT_REVIVAL_PC");
    m_strEffectGetExp = GetValue("EFFECT_GET_EXP");
    m_strEffectGetExpEnd = GetValue("EFFECT_GET_EXP_END");
    m_strEffectLiftableCubeMarker = GetValue("EFFECT_LIFTABLE_CUBE_MARKER");
    m_strEffectLiftableQuestEffect = GetValue("EFFECT_LIFTABLE_QUEST_EFFECT");
    m_strEffectResolvePanelty = GetValue("EFFECT_RESOLVE_PANELTY");
    m_strEffectTaxiDefault = GetValue("EFFECT_TAXI_DEFAULT");
    m_strEffectTaxiArrive = GetValue("EFFECT_TAXI_ARRIVE");
    m_strEffectTaxiWait = GetValue("EFFECT_TAXI_WAIT");
    m_strEffectTaxiLeave = GetValue("EFFECT_TAXI_LEAVE");
    m_strEffectTaxiReveal = GetValue("EFFECT_TAXI_REVEAL");
    m_strEffectTaxiArriveBestdriver = GetValue("EFFECT_TAXI_ARRIVE_BESTDRIVER");
    m_strEffectTaxiWaitBestdriver = GetValue("EFFECT_TAXI_WAIT_BESTDRIVER");
    m_strEffectTaxiLeaveBestdriver = GetValue("EFFECT_TAXI_LEAVE_BESTDRIVER");
    m_strEffectAirtaxiCash = GetValue("EFFECT_AIRTAXI_CASH");
    m_strEffectAirtaxiMeso = GetValue("EFFECT_AIRTAXI_MESO");
    m_strEffectCashCallMedic = GetValue("EFFECT_CASH_CALL_MEDIC");
    m_strEffectCashCallBlackMarket = GetValue("EFFECT_CASH_CALL_BLACK_MARKET");
    m_strEffectWeatherRain = GetValue("EFFECT_WEATHER_RAIN");
    m_strEffectWeatherHeabyRain = GetValue("EFFECT_WEATHER_HEABY_RAIN");
    m_strEffectWeatherSnow = GetValue("EFFECT_WEATHER_SNOW");
    m_strEffectWeatherHeabySnow = GetValue("EFFECT_WEATHER_HEABY_SNOW");
    m_strEffectWeatherSandstorm = GetValue("EFFECT_WEATHER_SANDSTORM");
    m_strEffectWeatherCherryblossom = GetValue("EFFECT_WEATHER_CHERRYBLOSSOM");
    m_strEffectWeatherLeafFall = GetValue("EFFECT_WEATHER_LEAF_FALL");
    m_strFishingCursorEnabled = GetValue("FISHING_CURSOR_ENABLED");
    m_strFishingCursorDisabled = GetValue("FISHING_CURSOR_DISABLED");
    m_strFishingWaterSplash = GetValue("FISHING_WATER_SPLASH");
    m_strFishingFloatBaitEffect = GetValue("FISHING_FLOAT_BAIT_EFFECT");
    m_strFishGuideCubeEffect = GetValue("FISH_GUIDE_CUBE_EFFECT");
    m_strFishingLineEffect = GetValue("FISHING_LINE_EFFECT");
    m_strFishHintEffect[0] = GetValue("FISH_HINT_EFFECT_SMALL");
    m_strFishHintEffect[1] = GetValue("FISH_HINT_EFFECT_MEDIUM");
    m_strFishHintEffect[2] = GetValue("FISH_HINT_EFFECT_LARGE");
    m_strFishHintEffect[3] = GetValue("FISH_HINT_EFFECT_BIG_FISH");
    m_strFishBoundEffect[0] = GetValue("FISH_BOUND_EFFECT_SMALL");
    m_strFishBoundEffect[1] = GetValue("FISH_BOUND_EFFECT_MEDIUM");
    m_strFishBoundEffect[2] = GetValue("FISH_BOUND_EFFECT_LARGE");
    m_strFishBoundEffect[3] = GetValue("FISH_BOUND_EFFECT_BIG_FISH");
    for (size_t i = 1; i <= 4; i++)
        m_strFishingFloatAsset[i] = GetValue("FISHING_FLOAT_ASSET_BEGINNER");
    for (size_t i = 5; i <= 8; i++)
        m_strFishingFloatAsset[i] = GetValue("FISHING_FLOAT_ASSET_INTERMEDIATE");
    for (size_t i = 9; i <= 12; i++)
        m_strFishingFloatAsset[i] = GetValue("FISHING_FLOAT_ASSET_EXPERT");
    for (size_t i = 13; i <= 15; i++)
        m_strFishingFloatAsset[i] = GetValue("FISHING_FLOAT_ASSET_MASTER");
    for (size_t i = 16; i <= 18; i++)
        m_strFishingFloatAsset[i] = GetValue("FISHING_FLOAT_ASSET_PRO");
    for (size_t i = 19; i <= 21; i++)
        m_strFishingFloatAsset[i] = GetValue("FISHING_FLOAT_ASSET_CHAMPION");
    m_strEffectInstrumentPlayDirect = GetValue("EFFECT_INSTRUMENT_PLAY_DIRECT");
    m_strEffectInstrumentPlayScoreSolo = GetValue("EFFECT_INSTRUMENT_PLAY_SCORE_SOLO");
    m_strEffectInstrumentWaitScoreEnsemble = GetValue("EFFECT_INSTRUMENT_WAIT_SCORE_ENSEMBLE");
    m_strEffectInstrumentPlayScoreEnsemble = GetValue("EFFECT_INSTRUMENT_PLAY_SCORE_ENSEMBLE");
    m_strEffectInstrumentMuteDirect = GetValue("EFFECT_INSTRUMENT_MUTE_DIRECT");
    m_strEffectInstrumentMuteScoreSolo = GetValue("EFFECT_INSTRUMENT_MUTE_SCORE_SOLO");
    m_strEffectInstrumentMuteScoreEnsemble = GetValue("EFFECT_INSTRUMENT_MUTE_SCORE_ENSEMBLE");
    m_strEffectInstrumentPlayDirectExpensive = GetValue("EFFECT_INSTRUMENT_PLAY_DIRECT_EXPENSIVE");
    m_strEffectInstrumentPlayScoreSoloExpensive = GetValue("EFFECT_INSTRUMENT_PLAY_SCORE_SOLO_EXPENSIVE");
    m_strEffectInstrumentWaitScoreEnsembleExpensive = GetValue("EFFECT_INSTRUMENT_WAIT_SCORE_ENSEMBLE_EXPENSIVE");
    m_strEffectInstrumentPlayScoreEnsembleExpensive = GetValue("EFFECT_INSTRUMENT_PLAY_SCORE_ENSEMBLE_EXPENSIVE");
    m_strEffectInstrumentMuteDirectExpensive = GetValue("EFFECT_INSTRUMENT_MUTE_DIRECT_EXPENSIVE");
    m_strEffectInstrumentMuteScoreSoloExpensive = GetValue("EFFECT_INSTRUMENT_MUTE_SCORE_SOLO_EXPENSIVE");
    m_strEffectInstrumentMuteScoreEnsembleExpensive = GetValue("EFFECT_INSTRUMENT_MUTE_SCORE_ENSEMBLE_EXPENSIVE");
    m_strEffectInstrumentStartMusic = GetValue("EFFECT_INSTRUMENT_START_MUSIC");
    m_strEffectInstrumentStopMusic = GetValue("EFFECT_INSTRUMENT_STOP_MUSIC");
    m_strEffectInstrumentConcertFirework = GetValue("EFFECT_INSTRUMENT_CONCERT_FIREWORK");
    m_strEffectSummonPortal = GetValue("EFFECT_SUMMON_PORTAL");
    m_strMusicScorePremiumShopSample = GetValue("MUSIC_SCORE_PREMIUM_SHOP_SAMPLE");
    m_strEffectAdventureLevelUp = GetValue("EFFECT_ADVENTURE_LEVEL_UP");
    for (size_t i = 1; i < 10; i++)
        m_strAllianceSidePopupIllust[i] = GetValue(FUN_140540050("allinace_sidepopup_illust_{0}", FUN_14021a6b0((int)i)));
}

// @0x140cc9c00
void CommonResource::CheckReload()
{
    for (unsigned i = 0; i < m_caches.GetCount(); i++)
    {
        if (FUN_1401d1320(m_caches[i].operator->()))
        {
            Load();
            return;
        }
    }
}

// @0x140cc9c90
bool CommonResource::LoadXml()
{
    m_map.RemoveAll();
    m_caches.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "commonResource.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return false;
    }
    {
        MS2Ptr<CCacheData> spCache(new CCacheData);
        if (spCache.get() != 0)
        {
            spCache->FUN_1401d1160(CString(strPath));
            m_caches.Add(spCache);
        }
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = FUN_140345b40(pRoot); pNode != 0; pNode = FUN_1403f0510(pNode))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CString strKey = FUN_140188f50(FUN_140189180(pNode), 0);
        CString strValue = FUN_140188f50(FUN_14086f4b0(pNode, "value"), 0);
        m_map.SetAt(strKey, strValue);
    }
    SetInit(true);
    return true;
}

// @0x140cca010
bool CommonResource::Load()
{
    bool bLoaded = LoadXml();
    if (!bLoaded)
        return false;
    LoadMembers();
    return true;
}

// @0x140cca050
CString CommonResource::GetPath(int nKind)
{
    if (nKind == 2)
        return CString(m_strSkillPoint2IconPath);
    return CString(m_strSkillPointIconPath);
}

// @0x140cca0e0
CString CommonResource::GetValue(const CString& strKey)
{
    CheckInit();
    CString strValue;
    m_map.Lookup(strKey, strValue);
    return strValue;
}

// @0x140cca5d0
void CommonResource::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CommonResource).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}
