// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Head of client\ms2\guideentity.cpp (part 1): the guide name
// tables (limit / trigger / shop action names) with their name<->index lookups, the key-config action name parser, and the
// GuideTriggerEventGroup value-set methods. The CGuideManager methods follow at 0x14138a4d0.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: client\ms2\guideentity.cpp#1
// MS2-RANGE: 0x1413892f0-0x14138a4d0 .text$mn
// MS2-RANGE: 0x1400f27b0-0x1400f2ed0 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guideentity.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <set>

#include "ms2/placeholder/guideoccurcontainer.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/cguidecondition.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees --------------------------------------------------------------------------

CStringW FUN_14016a730(const char* psz, int nCodePage);         // ANSI text to wide
CStringA FUN_14016a600(const wchar_t* psz, int nCodePage);      // wide text to ANSI
bool FUN_1403b3c40(const CStringW& strLeft, const wchar_t* pszRight);   // case-insensitive equal

// ---- name tables --------------------------------------------------------------------------------------------------------

#ifndef MS2_HOOK_DLL
// @0x1400f27b0
static CStringA g_guideLimitNames[25] = {
    "None", "KeyConfigTab", "ActionTalk", "ActionInteraction", "ItemPutOn", "ItemPutOff", "ItemDrop", "ItemPickup",
    "ItemUse", "PortalUse", "ShortcutModify", "ShortcutModifyExceptIndex8", "ShortcutModifyExceptIndex9", "CubeKeyInstall",
    "CubeKeyRotate", "CubeKeyRemove", "CubeKeyUp", "CubeKeyDown", "CubeKeySelect", "CubeKeyAll", "PlayerMove",
    "PlayerControl", "ProgressAchieve", "DesignHome", "Blueprint"
};

// @0x1400f29e0
static CStringA g_guideTriggerNames[33] = {
    "None", "BuyHome", "SellHome", "AchieveReward", "Job", "UgcShopRegister", "SkillBookTab", "RemoveBuilding",
    "DarkTombStone", "Interact", "ConstructRotate", "DesignItemCreate", "ItemPickup", "WorldmapEventPortal",
    "RevivalPanelty", "FallDamage", "TaxiFind", "TaxiAction", "AddItem", "AddItemByIconType", "LearnEmotion",
    "ServerTriggerEvent", "HookUpFish", "CanAchieveReward", "UseSkill", "MovePortal", "QuestSummonPortal",
    "HousePointReward", "QuestAccept", "QuestProgress", "QuestComplete", "SelectGameMenu", "ShopOpen"
};

// @0x1400f2cc0
static CStringA g_guideShopActionNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// @0x1400f2d80
static CStringA g_guideSkillName("skill");

// @0x1400f2db0
static CStringA g_guideStunName("stun");
#else
MS2_GLOBAL(0x143ad8dc0, CStringA[25], g_guideLimitNames);
MS2_GLOBAL(0x143ad8cb0, CStringA[33], g_guideTriggerNames);
#endif
static const size_t kGuideLimitCount = 25;
static const size_t kGuideTriggerCount = 33;

// ---- name <-> index ------------------------------------------------------------------------------------------------------

// @0x1413892f0
CStringW FUN_1413892f0(int nTrigger)
{
    return FUN_14016a730(g_guideTriggerNames[nTrigger], 0);
}

// @0x141389350
CStringA FUN_141389350(int nLimit)
{
    return g_guideLimitNames[nLimit];
}

// @0x1413893a0
CStringW FUN_1413893a0(int nLimit)
{
    return FUN_14016a730(FUN_141389350(nLimit), 0);
}

// @0x141389420
unsigned FUN_141389420(const CStringA& strName, unsigned nDefault)
{
    for (int i = 0; i < kGuideLimitCount; ++i)
    {
        if (g_guideLimitNames[i].CompareNoCase(strName) == 0)
            return i;
    }
    return nDefault;
}

// @0x141389490
unsigned FUN_141389490(const CStringW& strName, unsigned nDefault)
{
    return FUN_141389420(FUN_14016a600(strName, 0), nDefault);
}

// The key-config action id for an action name (nResult when the name is unknown).
// @0x141389500
int FUN_141389500(const CStringW& strName, int nResult)
{
    if (FUN_1403b3c40(strName, L"moveUp")) return 0x30d41;
    if (FUN_1403b3c40(strName, L"moveDown")) return 0x30d42;
    if (FUN_1403b3c40(strName, L"moveLeft")) return 0x30d43;
    if (FUN_1403b3c40(strName, L"moveRight")) return 0x30d44;
    if (FUN_1403b3c40(strName, L"moveUpLeft")) return 0x30d45;
    if (FUN_1403b3c40(strName, L"moveUpRight")) return 0x30d46;
    if (FUN_1403b3c40(strName, L"moveDownLeft")) return 0x30d47;
    if (FUN_1403b3c40(strName, L"moveDownRight")) return 0x30d48;
    if (FUN_1403b3c40(strName, L"jump")) return 0x493e1;
    if (FUN_1403b3c40(strName, L"totalAction")) return 0x493e2;
    if (FUN_1403b3c40(strName, L"get")) return 0x493e3;
    if (FUN_1403b3c40(strName, L"sit")) return 0x493e4;
    if (FUN_1403b3c40(strName, L"crawl")) return 0x493e5;
    if (FUN_1403b3c40(strName, L"run")) return 0x493e6;
    if (FUN_1403b3c40(strName, L"chat")) return 0x493e7;
    if (FUN_1403b3c40(strName, L"zoomIn")) return 0x493e8;
    if (FUN_1403b3c40(strName, L"zoomOut")) return 0x493e9;
    if (FUN_1403b3c40(strName, L"walkPress")) return 0x493ea;
    if (FUN_1403b3c40(strName, L"install")) return 0x493ed;
    if (FUN_1403b3c40(strName, L"triggerNext")) return 0x493ee;
    if (FUN_1403b3c40(strName, L"screenShot")) return 0x493ef;
    if (FUN_1403b3c40(strName, L"ride")) return 0x493f0;
    if (FUN_1403b3c40(strName, L"transformFittingDoll1")) return 0x493f1;
    if (FUN_1403b3c40(strName, L"transformFittingDoll2")) return 0x493f2;
    if (FUN_1403b3c40(strName, L"transformFittingDoll3")) return 0x493f3;
    if (FUN_1403b3c40(strName, L"transformFittingDoll4")) return 0x493f4;
    if (FUN_1403b3c40(strName, L"transformFittingDoll5")) return 0x493f5;
    if (FUN_1403b3c40(strName, L"changeCameraAngle")) return 0x493f6;
    if (FUN_1403b3c40(strName, L"attack")) return 0x49401;
    if (FUN_1403b3c40(strName, L"catch")) return 0x49402;
    if (FUN_1403b3c40(strName, L"gotoHome")) return 0x49403;
    if (FUN_1403b3c40(strName, L"toggleHeadupDIsplay")) return 0x49404;
    if (FUN_1403b3c40(strName, L"whisper")) return 0x49405;
    if (FUN_1403b3c40(strName, L"itemPreview")) return 0x49406;
    if (FUN_1403b3c40(strName, L"minimapExtendView")) return 0x49407;
    if (FUN_1403b3c40(strName, L"ok")) return 0x49408;
    if (FUN_1403b3c40(strName, L"cancel")) return 0x49409;
    if (FUN_1403b3c40(strName, L"dialogInventory")) return 0x61a81;
    if (FUN_1403b3c40(strName, L"dialogMyInfo")) return 0x61a82;
    if (FUN_1403b3c40(strName, L"dialogSkill")) return 0x61a85;
    if (FUN_1403b3c40(strName, L"dialogMap")) return 0x61a86;
    if (FUN_1403b3c40(strName, L"dialogQuest")) return 0x61a87;
    if (FUN_1403b3c40(strName, L"dialogUGCCamera")) return 0x61a88;
    if (FUN_1403b3c40(strName, L"dialogAchieve")) return 0x61a89;
    if (FUN_1403b3c40(strName, L"dialogBeautyshop")) return 0x61a8a;
    if (FUN_1403b3c40(strName, L"dialogItemEdit")) return 0x61a8b;
    if (FUN_1403b3c40(strName, L"dialogCommunity")) return 0x61a8c;
    if (FUN_1403b3c40(strName, L"dialogAbility")) return 0x61a99;
    if (FUN_1403b3c40(strName, L"dialogMail")) return 0x61a8d;
    if (FUN_1403b3c40(strName, L"dialogGuild")) return 0x61a8e;
    if (FUN_1403b3c40(strName, L"dialogVIP")) return 0x61a9a;
    if (FUN_1403b3c40(strName, L"dialogPartySearch")) return 0x61a9b;
    if (FUN_1403b3c40(strName, L"dialogUGCItemEdit")) return 0x61a9c;
    if (FUN_1403b3c40(strName, L"dialogMastery")) return 0x61a9d;
    if (FUN_1403b3c40(strName, L"dialogQuest")) return 0x61a9e;
    if (FUN_1403b3c40(strName, L"dialogSkillCompactControl")) return 0x61a9f;
    if (FUN_1403b3c40(strName, L"dialogDictionary")) return 0x61aa0;
    if (FUN_1403b3c40(strName, L"dialogGameRanking")) return 0x61aa1;
    if (FUN_1403b3c40(strName, L"dialogClub")) return 0x61aa2;
    if (FUN_1403b3c40(strName, L"dialogPet")) return 0x61aa3;
    if (FUN_1403b3c40(strName, L"dialogLapenshard")) return 0x61aa6;
    if (FUN_1403b3c40(strName, L"actionSlot1")) return 0x7a121;
    if (FUN_1403b3c40(strName, L"actionSlot2")) return 0x7a122;
    if (FUN_1403b3c40(strName, L"actionSlot3")) return 0x7a123;
    if (FUN_1403b3c40(strName, L"actionSlot4")) return 0x7a124;
    if (FUN_1403b3c40(strName, L"actionSlot5")) return 0x7a125;
    if (FUN_1403b3c40(strName, L"actionSlot6")) return 0x7a126;
    if (FUN_1403b3c40(strName, L"actionSlot7")) return 0x7a127;
    if (FUN_1403b3c40(strName, L"actionSlot8")) return 0x7a128;
    if (FUN_1403b3c40(strName, L"actionSlot9")) return 0x7a129;
    if (FUN_1403b3c40(strName, L"actionSlot10")) return 0x7a12a;
    if (FUN_1403b3c40(strName, L"actionSlot11")) return 0x7a12b;
    if (FUN_1403b3c40(strName, L"actionSlot12")) return 0x7a12c;
    if (FUN_1403b3c40(strName, L"actionSlot13")) return 0x7a12d;
    if (FUN_1403b3c40(strName, L"actionSlot14")) return 0x7a12e;
    if (FUN_1403b3c40(strName, L"actionSlot15")) return 0x7a12f;
    if (FUN_1403b3c40(strName, L"actionSlot16")) return 0x7a130;
    if (FUN_1403b3c40(strName, L"actionSlot17")) return 0x7a131;
    if (FUN_1403b3c40(strName, L"actionSlot18")) return 0x7a132;
    if (FUN_1403b3c40(strName, L"actionSlot19")) return 0x7a133;
    if (FUN_1403b3c40(strName, L"actionSlot20")) return 0x7a134;
    if (FUN_1403b3c40(strName, L"actionSlot21")) return 0x7a135;
    if (FUN_1403b3c40(strName, L"actionSlot22")) return 0x7a136;
    if (FUN_1403b3c40(strName, L"actionSkillCompactControl1")) return 0xaae61;
    if (FUN_1403b3c40(strName, L"actionSkillCompactControl2")) return 0xaae62;
    if (FUN_1403b3c40(strName, L"actionSkillCompactControl3")) return 0xaae63;
    if (FUN_1403b3c40(strName, L"gamePadModified1")) return 0xc3501;
    if (FUN_1403b3c40(strName, L"gamePadModified2")) return 0xc3502;
    if (FUN_1403b3c40(strName, L"gamePadModified3")) return 0xc3503;
    if (FUN_1403b3c40(strName, L"gamePadMainMenu")) return 0xc3504;
    if (FUN_1403b3c40(strName, L"gamePadMouseClickRight")) return 0xc3505;
    if (FUN_1403b3c40(strName, L"gamePadMouseClickLeft")) return 0xc3506;
    if (FUN_1403b3c40(strName, L"gamePadMouseMode")) return 0xc3507;
    return nResult;
}

// @0x14138a170
int FUN_14138a170(const CStringA& strName)
{
    for (int i = 0; i < kGuideTriggerCount; ++i)
    {
        if (g_guideTriggerNames[i].CompareNoCase(strName) == 0)
            return i;
    }
    return 0;
}

// The unreferenced CRT memmove_s copy of the TU (see ms2recover.h).
MS2_EMIT_CRT_MEMMOVE_S();

// ---- GuideTriggerEventGroup ---------------------------------------------------------------------------------------------

// @0x14138a2f0
void GuideTriggerEventGroup::AddValue(int nValue)
{
    m_values.insert(nValue);
}

// @0x14138a330
bool GuideTriggerEventGroup::HasValue(int nValue)
{
    return m_values.find(nValue) != m_values.end();
}

// @0x14138a390
bool GuideTriggerEventGroup::HasValueInRange(Unk_GameEventIntRange* pRange)
{
    for (std::set<int>::iterator it = m_values.begin(), itEnd = m_values.end(); it != itEnd; it++)
    {
        if (pRange->IsInRange(*it))
            return true;
    }
    return false;
}

// @0x14138a430
void GuideTriggerEventGroup::AddSubValue(int nValue)
{
    m_subValues.insert(nValue);
}

// @0x14138a470
bool GuideTriggerEventGroup::HasSubValue(int nValue)
{
    return m_subValues.find(nValue) != m_subValues.end();
}

// ---- dynamic initializers (.text$di) -------------------------------------------------------------------------------------

#ifndef MS2_HOOK_DLL
ClassObject* FUN_1413aa580();
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
void FUN_1402a9d70(void*, int, float, float, float, int);
void FUN_142cb11a0();   // the exe's atexit destructor of the object
struct Unk_RegMarker {};

// @0x1400f2de0
static char s_8ee0[0x30];
static Unk_RegMarker s_init8ee0 = (FUN_1402a9d70(&s_8ee0, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142cb11a0), Unk_RegMarker());

// @0x1400f2e30
static char s_regAchieveExistTrophy;
static Unk_RegMarker s_initAchieveExistTrophy =
    (FUN_140316aa0(&s_regAchieveExistTrophy, CStringW(L"CGuideConditionAchieveExistTrophy"), FUN_1413aa580), Unk_RegMarker());

// @0x1400f2e80
static char s_regAchieveTab;
static Unk_RegMarker s_initAchieveTab =
    (FUN_140316aa0(&s_regAchieveTab, CStringW(L"CGuideConditionAchieveTab"), CGuideConditionAchieveTab::CreateObject), Unk_RegMarker());
#endif
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb10d0-0x142cb11a0 .text$yd
