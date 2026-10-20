// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The minimap window and its markers: see uiminimapentity.h. w508.
// MS2-UNIT: ?\uiminimapentity.cpp
// MS2-RANGE: 0x141a30f30-0x141a517d0 .text$mn
// MS2-RANGE: 0x140117c70-0x140118e40 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiminimapentity.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiminimapentity.h"
#include <egf/Entity.h>
#include "ms2/client/ms2/portal.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/fmt/format.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

class Unk_MmQuestGuide;                                             // the quest guide result (0x1c bytes; ctor 0x140964630)

// The world's per-object proxy (RTTI .?AVCProxyGameObject@@, 0xe8). Unit-local typed view of
// placeholder/cproxygameobject.h: its +0x18 / +0x28 handles are MS2Ptr<CPortal> / MS2Ptr<NpcDataCli> here.
struct Unk_MmProxyInfo                                              // the proxy's display info (+0x88)
{
    int m_type;                                                     // +0x00 (0xb = npc)
    int m_04;
    int m_08;
    int m_0c;
    CStringW m_text;                                                // +0x10
};
class CProxyGameObject : public CPtred
{
public:
    int FUN_1416c1ff0();                                            // the local player's own object
    int FUN_1416c2040();                                            // another player's object
    int FUN_1416c2090();                                            // has a template id
    int FUN_1416c20d0();                                            // has a portal
    Unk_MmProxyInfo* FUN_1416c2200();
    MS2Ptr<NpcDataCli> FUN_1416c2220();                             // the npc data
    __int64 FUN_1416c22f0();                                        // the owner character id
    int FUN_1416c2350();                                            // the template (npc) id

    MS2Ptr<CPortal> m_portal;                                       // +0x18
    MS2Ptr<NpcDataCli> m_npc;                                       // +0x28
};

class Unk_MmWorld                                                   // the world service (FUN_1403ed2d0)
{
public:
    class MyPC* FUN_141bd0cc0();                                    // the local player
    int FUN_141bd3060();                                            // the current map id
    MS2Ptr<CProxyGameObject> FUN_141bc9be0(int nId);                // a proxy by object id
};
Unk_MmWorld* FUN_1403ed2d0();

class MyPC
{
public:
    int FUN_141527f80(int* pMapId);                                 // the home map
    CStringW FUN_1415281c0();                                       // the home name
};

class Unk_MmQuestTable { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual Unk_PayloadPtr<class CQuest> vfunc_3(int nQuestId); };
class Unk_MmQuestManager                                            // CQuestManager (FUN_140764020)
{
public:
    char m_pad[0x10];
    Unk_MmQuestTable m_quests;                                      // +0x10 the quest list interface
    void FUN_1416d1800(int nNpcId, Unk_MmQuestGuide* pGuide);       // the npc's quest guide
};
Unk_MmQuestManager* FUN_140764020();

class Unk_MmQuestGuide
{
public:
    Unk_MmQuestGuide();                                             // 0x140964630
    ~Unk_MmQuestGuide();                                            // 0x140964e40
    int m_type;                                                     // +0x00 (0xb: none)
    int m_state;                                                    // +0x04 (0 start, 1 progress, 2 complete)
    int m_questId;                                                  // +0x08
    int m_0c;
    int m_10;
    int m_14;
    int m_npcId;                                                    // +0x18
};
MS2_CHECK_SIZE(Unk_MmQuestGuide, 0x1c);

class Unk_MmFieldMeta                                               // CFieldMetaTable (FUN_140700390)
{
public:
    void FUN_1406fb900(int nMapId, int nNpcId, ATL::CAtlList<unsigned int>& out);   // the portal npcs of a map
    int FUN_1406fba40(int nId, int nNpcId);
};
Unk_MmFieldMeta* FUN_140700390();

class Unk_MmNpcTable                                                // NpcDataTableCli (FUN_1406d6e90)
{
public:
    MS2Ptr<NpcDataCli> FUN_140a7cab0(int nNpcId);
};
Unk_MmNpcTable* FUN_1406d6e90();

CStringTable* FUN_1401a9d70();                                      // the string table
CStringW FUN_1401aa6a0(int nNpcId);                                 // the npc name
CStringW FUN_1409eaa20(CStringW strKey, const CStringW& a1, const CStringW& a2, const CStringW& a3);
CStringW FUN_14183e930(const CStringW& strText, int nColor);        // a coloured text
int FUN_140a7c970(NpcDataCli* pNpc);                                // the npc's colour
class Unk_MmConfig { public: int FUN_140a7d630(); };                // the colour option block
class Unk_MmGameConfig { public: char m_pad[0xae70]; Unk_MmConfig m_colors; };
Unk_MmGameConfig* FUN_1401d3200();
CString FUN_14192ebf0(int nKind);                                   // the minimap icon of an npc function
CStringW FUN_14052bd00(int nStringId, const CStringW& str);
CStringW FUN_140a22c00(int nStrId, const CStringW& strArg1, const unsigned short& nArg2);
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);          // a string table text by id, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
UIMinimapDialog* FUN_141386800();
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a1, const CStringW& a2);                                   // the minimap dialog
CStringW FUN_140292a70(const wchar_t* szFormat, const unsigned int& n);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_1409796e0(int a, int b, int c, CStringW s);           // the home label
CString FUN_141082150(MS2Ptr<class CQuestData> spQuest, const CString& sEpic, const CString& sWorld, const CString& sRepeat, const CString& sEvent);
MS2Ptr<class CQuestData> FUN_14074bc40(int nQuestId);
void FUN_140710590(COutPacket& packet);
class Unk_MmTextHook { public: unsigned char FUN_14116d720(); };
Unk_MmTextHook* FUN_14025e7c0();
class Unk_MmBossTip { public: void FUN_141b99dc0(int nNpcId, ASObj& tip); };
Unk_MmBossTip* FUN_140cb17d0();
CFeatureManager* FUN_140166410();

// The quest payload pointer (Unk_PayloadPtr<CQuest>).
class CQuest;
class Unk_MmQuestData                                               // the quest's data interface (CQuest +0x18)
{
public:
    virtual MS2Ptr<class CQuestData> vfunc_0();                     // 0 the quest data
    virtual int vfunc_1();                                          // 1 completable
};
class CQuest : public CPtred { public: Unk_MmQuestData m_data; };

// The UI dialogs reached from the markers.
CUIService* FUN_1403ed2b0();
class UIBossRewardPreviewDialog : public UIDialog { public: int FUN_140f25ad0(int nNpcId); };
class UIDungeonRoomDialog : public UIDialog { public: bool FUN_1412b8f00(int nId); };
UIDungeonRoomDialog* FUN_140961550(int nUiId);

// The open dialog of a ui id (COMDAT per T in this unit).
template <class T> T* Unk_MmFindDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// The AS function object (0x50; ctor 0x1422c8430, dtor 0x1422c85b0).
class ASFunction : public AScript
{
public:
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int nUser, int nMovieId);
    ~ASFunction();
};

// ---- statics (.text$di order) ----

static CString s_strText = "text";
static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static CStringW s_strCenter = L"center";
static CStringW s_strLeft = L"left";
static CStringW s_strRight = L"right";
static CString s_strAlive = "alive";
static CString s_strApartment = "apartment";
static CString s_strApartmentMerat = "apartment_merat";
static CString s_strTaxiBest = "taxibest";
static CString s_strBgAlpha = "bgAlpha";
static CString s_strBoss = "boss";
static CString s_strBuddy = "buddy";
static CString s_strDie = "die";
namespace { extern CString s_strEmptyIcon; }                         // defined below (the exe copies it before its own init)
static CString s_strNoIcon = s_strEmptyIcon;
static CString s_strEliteBoss = "elite_boss";
namespace { CString s_strEmptyIcon = "empty"; }
static CString s_strEnemy = "enemy";
static CString s_strEventBoss = "event_boss";
static CString s_strFrame = "frame";
static CString s_strFriendHome = "friend_home";
static CString s_strFriendly = "friendly";
static CString s_strFullmap = "fullmap";
static CString s_strGatekeeper = "gatekeeper";
static CString s_strGuideName = "guideName";
static CString s_strGuild = "guild";
static CString s_strIconCheck = "iconcheck";
static CString s_strIdle = "idle";
static CString s_strLayer = "layer";
static CString s_strLayerApartment = "apartment";
static CString s_strLayerBlueTeam = "blueteam";
static CString s_strLayerBuddy = "buddy";
static CString s_strLayerFriendly = "friendly";
static CString s_strLayerGuild = "guild";
static CString s_strLayerHealingRegion = "healingregion";
static CString s_strLayerHome = "home";
static CString s_strLayerInteract = "interact";
static CString s_strLayerMyHome = "myhome";
static CString s_strLayerPlayer = "player";
static CString s_strLayerNpc = "npc";
static CString s_strLayerParty = "party";
static CString s_strLayerPc = "pc";
static CString s_strLayerPortal = "portal";
static CString s_strLayerQuest = "quest";
static CString s_strLayerQuestEpic = "quest_epic";
static CString s_strLayerQuestRepeat = "quest_repeat";
static CString s_strLayerQuestTarget = "quest_target";
static CString s_strLayerQuestWorld = "quest_world";
static CString s_strLayerRedTeam = "redteam";
static CString s_strLayerShop = "shop";
static CString s_strLayerTamingPet = "taming_pet";
static CString s_strLayerTaxi = "taxi";
static CString s_strLayerTelescope = "telescope";
static CString s_strLayerText = "text";
static CString s_strLayerTriggerObject = "triggerobject";
static CString s_strLayerWatchtower = "watchtower";
static CString s_strMapAlpha = "mapAlpha";
static CString s_strMcName = "mcname";
static CString s_strMinimize = "minimize";
static CString s_strMyHome = "my_home";
static CString s_strPlayer = "player";
static CString s_strName = "name";
static CString s_strNormal = "normal";
static CString s_strOther = "other";
static CString s_strParty = "party";
static CString s_strPartyChief = "party_chief";
static CStringW s_strPing = L"ping";
static CString s_strPortal = "portal";
static CString s_strQuest = "quest";
static CString s_strQuestComplete = "quest_complete";
static CString s_strQuestStart = "quest_start";
static CString s_strQuestTarget = "quest_target";
static CString s_strQuestTargetMonster = "quest_target_monster";
static CString s_strQuestTargetObject = "quest_target_object";
static CString s_strScale = "scale";
static CString s_strShowGuide = "showguide";
static CString s_strShowText = "showtext";
static CStringW s_strStorm = L"storm";
static CStringW s_strStormPreview = L"storm_preview";
static CString s_strTamingPet = "taming_pet";
static CString s_strTaxi = "taxi";
static CString s_strTooltip = "tooltip";
static egf::EntityID s_entityInvalid(0);
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strBluePingSound = "System_BluePing_01";
static CString s_strRedPingSound = "System_RedPing_01";
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static egf::EntityID s_entityInvalid2(0);
static UICommon::CMyPCKeyInputController s_keyInputController2;

// ---- UIMinimapEntity ----

// @0x141a30f30
UIMinimapEntity::UIMinimapEntity(const int& nType)
    : m_clip(0), m_position(efd::Point3::ZERO)
{
    m_showText = false;
    m_showGuide = false;
    m_visible = false;
    m_inFieldNpc = false;
    m_type = nType;
    m_64 = false;
}

// @0x141a31040
UIMinimapEntity::~UIMinimapEntity()
{
}

// @0x141a310e0
void UIMinimapEntity::FUN_141a310e0(NpcDataCli* pNpc)
{
    m_icon = FUN_141a32750(pNpc);
    m_state = FUN_141a329e0(m_icon);
    m_layer = FUN_141a32aa0(pNpc, m_icon);
    m_visible = !m_icon.IsEmpty() && m_icon != s_strNoIcon;
}
MS2_REPLACE_METHOD(0x141a310e0, UIMinimapEntity, FUN_141a310e0, 0, 0);

// @0x141a31270
void UIMinimapEntity::FUN_141a31270(ASObj& data, efd::SmartPointer<MinimapViewport> spViewport)
{
    if (spViewport == 0)
        return;
    data.FUN_1407cba60(s_strMcName, m_icon);
    data.FUN_1407cba60(s_strFrame, m_state);
    data.FUN_1407cba60(s_strLayer, m_layer);
    data.FUN_1407cbbe0(s_strShowText, m_showText);
    data.FUN_1407cbbe0(s_strShowGuide, m_showGuide);
    data.FUN_1407cbb20(s_strName, m_text);
    data.FUN_1407cbb20(s_strGuideName, m_guideName);
    data.FUN_1407cbbe0("inFieldNpc", m_inFieldNpc);
    data.FUN_141a472c0("groupType", m_type);
    NiPoint3 kPos(efd::Point3::ZERO);
    NiPoint3 kWorld(m_position);
    bool bVisible = spViewport->FUN_141486410(kWorld, kPos) && m_visible;
    data.FUN_1409c4a30("x", kPos.x);
    data.FUN_1409c4a30("y", kPos.y);
    data.FUN_1407cbbe0("visible", bVisible);
    ASFunction fn(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMinimapEntity::FUN_141a32120), 0, 2);
    data.FUN_1409adbe0("userFunction", Scaleform::GFx::Value(fn.FUN_1422bb870()));
    vfunc_2(&data);
}
MS2_REPLACE_METHOD(0x141a31270, UIMinimapEntity, FUN_141a31270, 0, 0);

// @0x141a316d0
int UIMinimapEntity::FUN_141a316d0(const int& nField, bool& bSpecial, CString& strIcon, CString& strLayer)
{
    unsigned int nNpcId = 0;
    Unk_MmQuestGuide guide;
    FUN_140764020()->FUN_1416d1800(nField, &guide);
    CString strQuestIcon;
    CString strQuestLayer;
    if (FUN_141a31c80(&guide, strQuestIcon, strQuestLayer) && !bSpecial) {
        bSpecial = true;
        strIcon = strQuestIcon;
        strLayer = strQuestLayer;
        nNpcId = guide.m_npcId;
    }
    if (nNpcId > 0)
        return nNpcId;
    ATL::CAtlList<unsigned int> npcs(10);
    unsigned int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    FUN_140700390()->FUN_1406fb900(nMapId, nField, npcs);
    for (POSITION pos = npcs.GetHeadPosition(); pos != 0; npcs.GetNext(pos)) {
        int nId = npcs.GetAt(pos);
        if (FUN_140700390()->FUN_1406fba40(nId, nField)) {
            MS2Ptr<NpcDataCli> spNpc = FUN_1406d6e90()->FUN_140a7cab0(nId);
            if (spNpc == 0)
                continue;
            if (FUN_141a32640(spNpc)) {
                bSpecial = false;
                strIcon = FUN_141a32750(spNpc);
                strLayer = s_strLayerNpc;
                nNpcId = nId;
                break;
            }
        }
    }
    return nNpcId;
}
MS2_REPLACE_METHOD(0x141a316d0, UIMinimapEntity, FUN_141a316d0, 0, 0);

// @0x141a319f0
CStringW UIMinimapEntity::FUN_141a319f0(NpcDataCli* pNpc, const CStringW& strAlign, bool bMultiRow)
{
    CStringW strFunction = FUN_1401a9d70()->FUN_141811980(10, pNpc->GetId());
    if (!strFunction.IsEmpty()) {
        int nColor = pNpc->GetFriendly() > 0 ? FUN_1401d3200()->m_colors.FUN_140a7d630() : FUN_140a7c970(pNpc);
        CStringW strColored = FUN_14183e930(strFunction, nColor);
        CStringW strKey = bMultiRow ? L"s_minimap_tooltip_function_npc" : L"s_minimap_tooltip_function_npc_1row";
        const CStringW& strFormat = strKey;
        return FUN_1409eaa20(strFormat, strAlign, strColored, FUN_1401aa6a0(pNpc->GetId()));
    }
    return FUN_14028dfa0(L"s_minimap_tooltip_normal", FUN_1401aa6a0(pNpc->GetId()));
}
MS2_REPLACE_METHOD(0x141a319f0, UIMinimapEntity, FUN_141a319f0, 0, 0);
MS2_REPLACE_METHOD(0x141a319f0, UIMinimapEntity, FUN_141a319f0, 0, 0);

// @0x141a31c80
bool UIMinimapEntity::FUN_141a31c80(const Unk_MmQuestGuide* pGuide, CString& strIcon, CString& strLayer)
{
    if (pGuide->m_type != 0xb) {
        Unk_PayloadPtr<CQuest> spQuest(0);
        bool bSuffix = true;
        int nState = pGuide->m_state;
        int nQuestId = pGuide->m_questId;
        switch (nState) {
        case 1:
            spQuest = FUN_140764020()->m_quests.vfunc_3(nQuestId);
            if (spQuest.get() && spQuest->m_data.vfunc_1()) {
                strIcon = s_strQuestComplete;
                bSuffix = true;
            } else {
                strIcon = s_strQuestStart;
                bSuffix = false;
            }
            break;
        case 2:
            strIcon = s_strQuestComplete;
            break;
        case 0:
            strIcon = s_strQuest;
            break;
        default:
            return false;
        }
        MS2Ptr<CQuestData> spData = spQuest.get() ? spQuest->m_data.vfunc_0() : FUN_14074bc40(nQuestId);
        const CString& strSuffix = FUN_141082150(spData, "_epic", "_world", "_repeat", "_event");
        if (bSuffix)
            strIcon += strSuffix;
        strLayer += s_strLayerQuest + strSuffix;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x141a31c80, UIMinimapEntity, FUN_141a31c80, 0, 0);

// @0x141a32120
void UIMinimapEntity::FUN_141a32120(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (params.ArgCount > 0) {
        ASData args;
        if (!args.FUN_1422b9620(params.pArgs, params.ArgCount))
            return;
        CStringW strName = args.FUN_1422b8f40();
        if (strName == L"tooltip") {
            ASObj tip(2);
            if (FUN_141a32260(tip))
                *params.pRetVal = tip.FUN_1422bb870();
        } else if (strName == L"click") {
            FUN_141a32330();
        }
    }
}
MS2_REPLACE_METHOD(0x141a32120, UIMinimapEntity, FUN_141a32120, 0, 0);

// @0x141a32260
bool UIMinimapEntity::FUN_141a32260(ASObj& data)
{
    CStringW strText;
    GetText(strText, data);
    if (strText.IsEmpty())
        return false;
    data.FUN_1407cbb20(s_strText, strText);
    return true;
}
MS2_REPLACE_METHOD(0x141a32260, UIMinimapEntity, FUN_141a32260, 0, 0);

// @0x141a32330
void UIMinimapEntity::FUN_141a32330()
{
    vfunc_3();
    if (FUN_14025e7c0()->FUN_14116d720() && m_position != efd::Point3::ZERO) {
        COutPacket packet(0x50, 0);
        packet.Encode1(2);
        packet.vfunc_o10_11(reinterpret_cast<const Unk_StreamPoint&>(m_position));
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x141a32330, UIMinimapEntity, FUN_141a32330, 0, 0);

// @0x141a323e0
void UIMinimapEntity::FUN_141a323e0(MS2Ptr<CPortal> spPortal)
{
    m_icon = spPortal->FUN_14169c5f0();
    m_layer = s_strLayerPortal;
    m_text = spPortal->FUN_14169cae0();
    m_visible = spPortal->FUN_14169d1d0();
    m_showText = m_visible;
    m_showGuide = m_visible;
}

// @0x141a32500
void UIMinimapEntity::GetText(CStringW& strText, ASObj& data)
{
    if (m_type == 3) {
        strText = m_text;
    } else if (m_type == 4) {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC)
            strText = FUN_14052bd00(0x70f, pPC->FUN_1415281c0());
    } else if (m_type == 6) {
        strText = m_text;
    } else {
        strText.Empty();
    }
}
MS2_REPLACE_METHOD(0x141a32500, UIMinimapEntity, GetText, 0, 0);

// @0x141a32620
void UIMinimapEntity::vfunc_2(ASObj* pData)
{
}
MS2_REPLACE_METHOD(0x141a32620, UIMinimapEntity, vfunc_2, 0, 0);

// @0x141a32640
bool UIMinimapEntity::FUN_141a32640(CNpcData* pNpc)
{
    CString strIcon = FUN_14192ebf0(pNpc->GetKind());
    if (strIcon.IsEmpty())
        return false;
    if (pNpc->GetKind() == 0)
        return false;
    bool bEmpty = FUN_1401a9d70()->FUN_141811980(10, pNpc->GetId()).IsEmpty();
    if (bEmpty)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x141a32640, UIMinimapEntity, FUN_141a32640, 0, 0);

// @0x141a32750
CString UIMinimapEntity::FUN_141a32750(NpcDataCli* pNpc)
{
    if (!pNpc->IsMinimap())
        return s_strNoIcon;
    if (pNpc->m_strMinimapIcon != "")
        return pNpc->m_strMinimapIcon;
    if (pNpc->HasPropertyTag(0xd))
        return s_strEventBoss;
    switch (pNpc->GetNpcType()) {
    case 0:
        if (pNpc->IsBoss()) {
            int nClass = pNpc->GetClass();
            if (nClass == 3 || nClass == 7)
                return s_strEliteBoss;
            return s_strBoss;
        }
        break;
    case 0x55:
        return s_strGatekeeper;
    }
    CString strIcon = FUN_14192ebf0(pNpc->GetKind());
    if (strIcon.IsEmpty()) {
        if (pNpc->GetFriendly() < 1)
            return s_strEnemy;
        return s_strFriendly;
    }
    return strIcon;
}
MS2_REPLACE_METHOD(0x141a32750, UIMinimapEntity, FUN_141a32750, 0, 0);

// @0x141a329e0
CString UIMinimapEntity::FUN_141a329e0(const CString& strIcon)
{
    if (strIcon == s_strEliteBoss || strIcon == s_strBoss || strIcon == s_strEventBoss)
        return s_strAlive;
    return "";
}
MS2_REPLACE_METHOD(0x141a329e0, UIMinimapEntity, FUN_141a329e0, 0, 0);

// @0x141a32aa0
CString UIMinimapEntity::FUN_141a32aa0(NpcDataCli* pNpc, const CString& strIcon)
{
    switch (pNpc->GetNpcType()) {
    case 1:
        return s_strLayerShop;
    case 0x55:
        return s_strLayerInteract;
    }
    if (strIcon == s_strFriendly)
        return s_strLayerFriendly;
    return s_strLayerNpc;
}
MS2_REPLACE_METHOD(0x141a32aa0, UIMinimapEntity, FUN_141a32aa0, 0, 0);

// @0x141a32ba0
CStringW UIMinimapEntity::FUN_141a32ba0(Unk_BuddyPtr<CBuddy> spBuddy)
{
    if (spBuddy == 0)
        return CStringW(L"");
    return FUN_14028dfa0(L"s_worldmap_tooltip_friendhome",
        FUN_1409796e0(spBuddy->FUN_1401cc3e0(), spBuddy->FUN_1401cc3a0(), spBuddy->FUN_1401cc3c0(), spBuddy->FUN_1401cc350()));
}
MS2_REPLACE_METHOD(0x141a32ba0, UIMinimapEntity, FUN_141a32ba0, 0, 0);

// ---- UIMinimapEntityProxy ----

// @0x141a32d30
UIMinimapEntityProxy::UIMinimapEntityProxy(const int& nId, const int& nKind)
    : UIMinimapEntity(1)
{
    m_kind = nKind;
    m_id = nId;
}

// @0x141a32da0
MS2Ptr<CProxyGameObject> UIMinimapEntityProxy::FUN_141a32da0()
{
    if (m_id == 0)
        return MS2Ptr<CProxyGameObject>(0);
    return FUN_1403ed2d0()->FUN_141bc9be0(m_id);
}
MS2_REPLACE_METHOD(0x141a32da0, UIMinimapEntityProxy, FUN_141a32da0, 0, 0);

// @0x141a32e20
void UIMinimapEntityProxy::GetText(CStringW& strText, ASObj& data)
{
    MS2Ptr<CProxyGameObject> spProxy = FUN_141a32da0();
    if (spProxy == 0)
        return;
    vfunc_5(spProxy, strText, data);
}
MS2_REPLACE_METHOD(0x141a32e20, UIMinimapEntityProxy, GetText, 0, 0);

// @0x141a32ed0
void UIMinimapEntityProxy::vfunc_3()
{
    if (!FUN_140166410()->FUN_14036d570(0x1a))
        return;
    MS2Ptr<CProxyGameObject> spProxy = FUN_141a32da0();
    if (spProxy.get() != 0) {
    if (spProxy->FUN_1416c20d0()) {
        MS2Ptr<CPortal> spPortal = spProxy->m_portal;
        if (spPortal->m_nType == 8) {
            UIDungeonRoomDialog* pDialog = FUN_140961550(0x4ebd);
            if (pDialog) {
                FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4ebd);
                if (pDialog->FUN_1412b8f00(spPortal->m_nId))
                    FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4ebd);
            }
        }
    } else if (spProxy->FUN_1416c2090()) {
        UIBossRewardPreviewDialog* pDialog = Unk_MmFindDialog<UIBossRewardPreviewDialog>(0x4efb);
        if (pDialog) {
            FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4efb);
            if (pDialog->FUN_140f25ad0(spProxy->FUN_1416c2350()))
                FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4efb);
        }
    }
    }
}
MS2_REPLACE_METHOD(0x141a32ed0, UIMinimapEntityProxy, vfunc_3, 0, 0);

// @0x141a33060
int UIMinimapEntityProxy::vfunc_4()
{
    return m_kind;
}
MS2_REPLACE_METHOD(0x141a33060, UIMinimapEntityProxy, vfunc_4, 0, 0);

// @0x141a33080
void UIMinimapEntityProxy::vfunc_5(MS2Ptr<CProxyGameObject> spProxy, CStringW& strText, ASObj& data)
{
    strText = m_text;
    if (spProxy->FUN_1416c2040()) {
        UIMinimapDialog* pDialog = FUN_141386800();
        if (pDialog) {
            unsigned int nQuest = 0;
            unsigned __int64 nCharId = 0;
            pDialog->FUN_141a3b4d0(nQuest, nCharId);
            if (nCharId == spProxy->FUN_1416c22f0()) {
                CStringW strKey = FUN_140292a70(L"s_minimap_tooltip_quest_target_{0}", nQuest);
                strText = FUN_140298ea0(strKey);
            }
        }
    } else if (spProxy->FUN_1416c2090()) {
        Unk_MmProxyInfo* pInfo = spProxy->FUN_1416c2200();
        if (pInfo->m_type != 0xb) {
            strText = pInfo->m_text;
        } else {
            MS2Ptr<NpcDataCli> spNpc = spProxy->FUN_1416c2220();
            if (spNpc.get()) {
                if (spNpc->m_nClass == 4 || spNpc->m_nClass == 6) {
                    if (spNpc->HasPropertyTag(3)) {
                        strText = FUN_14028dee0(0x71a, FUN_1401aa6a0(spNpc->GetId()), L"??");
                    } else {
                        unsigned short nLevel = spNpc->GetLevel();
                        strText = FUN_140a22c00(0x71a, FUN_1401aa6a0(spNpc->GetId()), nLevel);
                    }
                    CStringW strFrame(L"boss");
                    if (spNpc->HasPropertyTag(0xd)) {
                        strFrame = L"event";
                    } else if (spNpc->m_nClass < 4 || spNpc->m_nClass == 7) {
                        strFrame = L"elite";
                    }
                    data.FUN_1409c0d20("npcID", spNpc->GetId());
                    data.FUN_1407cbb20("bossFrameName", strFrame);
                    int nNpcId = spNpc->GetId();
                    FUN_140cb17d0()->FUN_141b99dc0(nNpcId, data);
                } else {
                    strText = FUN_141a319f0(spNpc, s_strCenter, true);
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141a33080, UIMinimapEntityProxy, vfunc_5, 0, 0);

// ---- UIMinimapEntityProxyPortal ----

// @0x141a335e0
UIMinimapEntityProxyPortal::UIMinimapEntityProxyPortal(const int& nId)
    : UIMinimapEntityProxy(nId, 4)
{
    m_state = 0;
    m_field = 0;
    m_flag = false;
}

// @0x141a33650
void UIMinimapEntityProxyPortal::FUN_141a33650()
{
    m_state = 0;
    m_field = 0;
    m_flag = false;
}
MS2_REPLACE_METHOD(0x141a33650, UIMinimapEntityProxyPortal, FUN_141a33650, 0, 0);

// @0x141a33680
void UIMinimapEntityProxyPortal::vfunc_5(MS2Ptr<CProxyGameObject> spProxy, CStringW& strText, ASObj& data)
{
    if (!(spProxy == 0) && !(spProxy->m_portal == 0)) {
        MS2Ptr<CPortal> spPortal = spProxy->m_portal;
        if (m_state == 2) {
            FUN_141a33850(spPortal, strText);
        } else if (m_state == 1) {
            FUN_141a33e30(spPortal, strText);
        } else {
            CStringW strName = spPortal->FUN_14169cae0();
            if (!strName.IsEmpty())
                strText = FUN_14052bd00(0x73d, strName);
        }
    }
}
MS2_REPLACE_METHOD(0x141a33680, UIMinimapEntityProxyPortal, vfunc_5, 0, 0);

// @0x141a33850
void UIMinimapEntityProxyPortal::FUN_141a33850(MS2Ptr<CPortal> spPortal, CStringW& strText)
{
    if (spPortal == 0)
        return;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    CStringW strLabel;
    int nHome = 0;
    const int& nField = spPortal->FUN_14169d280();
    if (pPC->FUN_141527f80(&nHome) && nHome == nField)
        strLabel = FUN_14052bd00(0x70f, pPC->FUN_1415281c0());
    UIMinimapDialog* pDialog = FUN_141386800();
    if (pDialog) {
        CStringW strBuddies;
        UIMinimapDialog::HomeListPtr spHomes = pDialog->FUN_141a3b660(nField);
        if (spHomes.get()) {
            size_t nTotal = spHomes->GetCount();
            size_t nCount = nTotal;
            if (nTotal > 4)
                nCount = 5;
            POSITION pos = spHomes->GetHeadPosition();
            for (size_t i = 0; i < nCount; i++) {
                __int64 nId = spHomes->GetAt(pos);
                Unk_BuddyPtr<CBuddy> spBuddy = CBuddyManager::GetInstance()->FUN_140ae4b70(nId);
                if (spBuddy.get()) {
                    if (!strBuddies.IsEmpty())
                        strBuddies.Append(L"\n");
                    strBuddies.Append(FUN_141a32ba0(spBuddy));
                }
                spHomes->GetNext(pos);
            }
            if (nCount < nTotal) {
                if (!strBuddies.IsEmpty())
                    strBuddies.Append(L"\n");
                strBuddies.Append(FUN_14028dfa0(L"s_worldmap_tooltip_friendhome", L"..."));
            }
        }
        if (!strBuddies.IsEmpty()) {
            if (!strLabel.IsEmpty())
                strLabel.Append(L"\n");
            strLabel.Append(strBuddies);
        }
    }
    if (!strLabel.IsEmpty()) {
        CStringW strAligned = FUN_14028dfa0(L"s_minimap_tooltip_normal_alignleft", strLabel);
        strText = FUN_1408f71a0(L"s_minimap_tooltip_function_portal", FUN_1401a9d70()->FUN_141811980(3, nField), strAligned);
    }
}
MS2_REPLACE_METHOD(0x141a33850, UIMinimapEntityProxyPortal, FUN_141a33850, 0, 0);
