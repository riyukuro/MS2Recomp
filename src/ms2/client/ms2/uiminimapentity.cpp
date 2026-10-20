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
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/ctaximanager.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/uiugceventdispatcher.h"
#include "ms2/placeholder/uibuddyeventdispatcher.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/client/ms2/uileveluppackagewidgetdialog.h"
#include "ms2/client/ms2/uicommunitydialog.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asuicomponent.h"
#include <efd/utf8string.h>
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
    int FUN_141bc80c0(int nChannel);                                // change the channel
};
Unk_MmWorld* FUN_1403ed2d0();

CQuestManager* FUN_140764020();                                    // TSingleton<CQuestManager>::GetInstance
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);                         // the npc table row

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
CInputKeyHandler* FUN_14025e7c0();                                  // TSingleton<CInputKeyHandler>::GetInstance
class Unk_MmUIManager { public: int FUN_1422af2d0(int nLayer); };  // the ui layer manager
Unk_MmUIManager* FUN_14025e7a0();
class Unk_MmBossTip { public: void FUN_141b99dc0(int nNpcId, ASObj& tip); };
Unk_MmBossTip* FUN_140cb17d0();
CFeatureManager* FUN_140166410();
CStringW FUN_14016a730(const char* psz, int nLength);              // narrow -> wide
CStringW FUN_14028b8e0(const CStringW& strKey);                     // a common string
int FUN_140408410(const ATL::CAtlArray<int>& arr, const int& n);    // the index of a value or -1
extern ATL::CAtlArray<int> DAT_143ab3078;                           // the taxi stops the player has found
CTaxiManager* FUN_1409f24a0();                                      // TSingleton<CTaxiManager>::GetInstance
int FUN_141b71c00(unsigned short nValue);                           // the taxi tier of a level
void FUN_141276180(const CString& strSound, const CString& strArg); // play a ui sound
int FUN_1418fd2f0();                                                // the minimap is suppressed (uicommon)
int FUN_14192e8f0();
extern int DAT_143af7d40;                                           // input enabled
UIObject* FUN_140ce8310(int nClass);
UIObject* FUN_140ce8270(int nClass);
class Unk_MmEntityEvents                                            // UIEntityEventDispatcher (FUN_140c607b0)
{
public:
    void FUN_1419308c0(UIEntityEventListener* pListener);           // register
    void FUN_141930950(UIEntityEventListener* pListener);           // unregister
};
Unk_MmEntityEvents* FUN_140c607b0();
UIQuestEventDispatcher* FUN_140bfc4b0();
UIUGCEventDispatcher* FUN_140bc09f0();
UIStatusEventDispatcher* FUN_140aa6d40();
UIBuddyEventDispatcher* FUN_140a4a7b0();
UIServerEventDispatcher* FUN_140933230();
class ASDialog : public ASUIComponent {};                             // the dialog root clip (UIDialog::m_90)

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
// MS2-FUNCTIONAL: the exe frame is 0x10 larger (an unrecovered extra temp); the code is otherwise identical.
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
    Unk_QmNpcQuestState guide;
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
    FUN_140700390()->FUN_1406fb900(FUN_1403ed2d0()->FUN_141bd3060(), nField, npcs);
    for (POSITION pos = npcs.GetHeadPosition(); pos != 0; npcs.GetNext(pos)) {
        int nId = npcs.GetAt(pos);
        if (FUN_140700390()->FUN_1406fba40(nId, nField)) {
            MS2Ptr<NpcDataCli> spNpc = FUN_1406d6e90()->FUN_140a7cab0(nId);
            if (spNpc == 0)
                continue;
            if (FUN_141a32640(spNpc) && nNpcId == 0) {
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

// @0x141a31c80
bool UIMinimapEntity::FUN_141a31c80(const Unk_QmNpcQuestState* pGuide, CString& strIcon, CString& strLayer)
{
    if (pGuide->m_icon != 0xb) {
        Unk_PayloadPtr<CQuest> spQuest(0);
        bool bSuffix = true;
        int nState = pGuide->m_state;
        int nQuestId = pGuide->m_questId;
        switch (nState) {
        case 1:
            spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
            if (static_cast<bool>(spQuest.get()) && spQuest->m_data.vfunc_1()) {
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
    if (params.ArgCount <= 0)
        return;
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
MS2_REPLACE_METHOD(0x141a32120, UIMinimapEntity, FUN_141a32120, 0, 0);

// @0x141a32260
bool UIMinimapEntity::FUN_141a32260(ASObj& data)
{
    CStringW strText;
    GetText(strText, data);
    if (!strText.IsEmpty()) {
        data.FUN_1407cbb20(s_strText, strText);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x141a32260, UIMinimapEntity, FUN_141a32260, 0, 0);

// @0x141a32330
void UIMinimapEntity::FUN_141a32330()
{
    vfunc_3();
    if (FUN_14025e7c0()->IsDebugMode() && m_position != efd::Point3::ZERO) {
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
    int nType = pNpc->GetNpcType();
    switch (nType) {
    case 0:
        if (pNpc->IsBoss()) {
            int nClass = pNpc->GetClass();
            if (nClass == 3 || nClass == 7) {
                return s_strEliteBoss;
            } else {
                return s_strBoss;
            }
        }
        break;
    case 0x55:
        return s_strGatekeeper;
    }
    CString strIcon = FUN_14192ebf0(pNpc->GetKind());
    if (!strIcon.IsEmpty())
        return strIcon;
    if (pNpc->GetFriendly() > 0)
        return s_strFriendly;
    return s_strEnemy;
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
        return L"";
    CStringW strHome = FUN_1409796e0(spBuddy->FUN_1401cc3e0(), spBuddy->FUN_1401cc3a0(), spBuddy->FUN_1401cc3c0(), spBuddy->FUN_1401cc350());
    return FUN_14028dfa0(L"s_worldmap_tooltip_friendhome", strHome);
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
                    } else if (spNpc->m_nClass <= 3 || spNpc->m_nClass == 7) {
                        strFrame = L"elite";
                    }
                    data.FUN_1409c0d20("npcID", spNpc->GetId());
                    data.FUN_1407cbb20("bossFrameName", strFrame);
                    FUN_140cb17d0()->FUN_141b99dc0(spNpc->GetId(), data);
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
    if (spProxy == 0 || spProxy->m_portal == 0)
        return;
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
            size_t nCount = nTotal < 5 ? nTotal : 5;
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
            if (nTotal > nCount) {
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

// @0x141a33e30
// MS2-FUNCTIONAL: my frame is 0x10 larger than the exe (an unrecovered temp layout); calls and logic match.
void UIMinimapEntityProxyPortal::FUN_141a33e30(MS2Ptr<CPortal> spPortal, CStringW& strText)
{
    if (spPortal == 0)
        return;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    const int& nField = spPortal->FUN_14169d280();
    int nSelected = m_field;
    bool bQuest = m_flag;
    CStringW strLabel;
    ATL::CAtlList<unsigned int> quests(10);
    FUN_140764020()->FUN_1416d16c0(nField, quests);
    ATL::CAtlList<unsigned int> npcs(10);
    FUN_140700390()->FUN_1406fb900(FUN_1403ed2d0()->FUN_141bd3060(), nField, npcs);
    ATL::CAtlList<unsigned int> visible(10);
    for (POSITION pos = npcs.GetHeadPosition(); pos != 0; npcs.GetNext(pos)) {
        unsigned int nId = npcs.GetAt(pos);
        if (FUN_140700390()->FUN_1406fba40(nId, nField)) {
            MS2Ptr<CNpcData> spNpc = FUN_1406cd330(nId);
            if (static_cast<CNpcData*>(spNpc) != 0 && FUN_141a32640(spNpc.get()))
                visible.AddTail(nId);
        }
    }
    if (bQuest) {
        Unk_QmNpcQuestState guide;
        guide.m_wantText = 1;
        FUN_140764020()->FUN_1416d12d0(nSelected, &guide, 0);
        strLabel = guide.m_text;
    } else {
        MS2Ptr<NpcDataCli> spNpc = FUN_1406d6e90()->FUN_140a7cab0(nSelected);
        if (static_cast<NpcDataCli*>(spNpc) != 0) {
            CStringW strAlign = visible.GetCount() > 1 ? s_strLeft : s_strCenter;
            strLabel = FUN_141a319f0(spNpc.get(), strAlign, false);
        }
    }
    if (!quests.IsEmpty()) {
        bool bInclude = true;
        for (POSITION pos = quests.GetHeadPosition(); pos != 0; quests.GetNext(pos)) {
            int nId = quests.GetAt(pos);
            if (bQuest)
                bInclude = nId != nSelected;
            if (bInclude) {
                Unk_QmNpcQuestState guide;
                guide.m_wantText = 1;
                FUN_140764020()->FUN_1416d12d0(nId, &guide, 0);
                strLabel.Append(guide.m_text);
            }
        }
    }
    if (!visible.IsEmpty()) {
        bool bInclude = true;
        for (POSITION pos = visible.GetHeadPosition(); pos != 0; visible.GetNext(pos)) {
            int nId = visible.GetAt(pos);
            if (!bQuest)
                bInclude = nId != nSelected;
            if (bInclude) {
                MS2Ptr<NpcDataCli> spNpc = FUN_1406d6e90()->FUN_140a7cab0(nId);
                if (spNpc == 0)
                    continue;
                strLabel.Append(FUN_141a319f0(spNpc.get(), s_strLeft, false));
            }
        }
    }
    strText = FUN_1408f71a0(L"s_minimap_tooltip_function_portal", FUN_1401a9d70()->FUN_141811980(3, nField), strLabel);
}
MS2_REPLACE_METHOD(0x141a33e30, UIMinimapEntityProxyPortal, FUN_141a33e30, 0, 0);

// @0x141a34550
UIMinimapEntityBuddyHome::UIMinimapEntityBuddyHome(Unk_BuddyPtr<CBuddy> spBuddy)
    : UIMinimapEntity(5), m_buddy(spBuddy)
{
}

// @0x141a345c0
void UIMinimapEntityBuddyHome::GetText(CStringW& strText, ASObj& data)
{
    if (m_buddy == 0)
        return;
    strText = FUN_141a32ba0(m_buddy);
}
MS2_REPLACE_METHOD(0x141a345c0, UIMinimapEntityBuddyHome, GetText, 0, 0);

// @0x141a34670
UIMinimapEntityMapObject::UIMinimapEntityMapObject(const int& nId, efd::SmartPointer<egf::Entity> spEntity)
    : UIMinimapEntity(8), m_id(nId), m_entity(spEntity)
{
}

// @0x141a34700
void UIMinimapEntityMapObject::GetText(CStringW& strText, ASObj& data)
{
    if (m_entity == 0)
        return;
    efd::utf8string strTooltip;
    m_entity->GetPropertyValue(0x794e257e, strTooltip);
    strText = FUN_140298ea0(FUN_14016a730(strTooltip.c_str(), 0));
}
MS2_REPLACE_METHOD(0x141a34700, UIMinimapEntityMapObject, GetText, 0, 0);

// @0x141a34810
UIMinimapEntityTaxi::UIMinimapEntityTaxi(const efd::Point3& kPos)
    : UIMinimapEntity(2)
{
    FUN_141a34890(kPos);
}

// @0x141a34890
void UIMinimapEntityTaxi::FUN_141a34890(const efd::Point3& kPos)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    int nField = FUN_1403ed2d0()->FUN_141bd3060();
    m_state = FUN_140408410(DAT_143ab3078, nField) >= 0 ? "enabled" : "disabled";
    if (FUN_1409f24a0()->FUN_14085f730(nField)) {
        if (pPC->FUN_140967010()->FUN_14050da30() == 0)
            return;
        m_state = "enabled";
    }
    bool bBest = FUN_141b71c00((unsigned short)pPC->vfunc_78()) == 1;
    m_best = bBest;
    m_icon = bBest ? s_strTaxiBest : s_strTaxi;
    m_layer = s_strLayerTaxi;
    m_position = kPos;
    m_visible = true;
    m_text = bBest ? FUN_14028b8e0(L"s_word_besttaxistation") : FUN_14028b8e0(L"s_word_taxistation");
}
MS2_REPLACE_METHOD(0x141a34890, UIMinimapEntityTaxi, FUN_141a34890, 0, 0);

// @0x141a34870
void UIMinimapEntityTaxi::FUN_141a34870(bool bBest)
{
    m_best = bBest;
}
MS2_REPLACE_METHOD(0x141a34870, UIMinimapEntityTaxi, FUN_141a34870, 0, 0);

// @0x141a34c30
void UIMinimapEntityTaxi::GetText(CStringW& strText, ASObj& data)
{
    strText = m_best ? FUN_14028b8e0(L"s_word_besttaxistation") : FUN_14028b8e0(L"s_word_taxistation");
}
MS2_REPLACE_METHOD(0x141a34c30, UIMinimapEntityTaxi, GetText, 0, 0);

// @0x141a34db0
UIMinimapEntityStorm::UIMinimapEntityStorm(int nId, const efd::Point3& kPos, const CStringW& strIcon)
    : UIMinimapEntity(9), m_id(nId)
{
    FUN_141a34e30(nId, kPos, strIcon);
}

// @0x141a34e30
void UIMinimapEntityStorm::FUN_141a34e30(int nId, const efd::Point3& kPos, const CStringW& strIcon)
{
    m_icon = (const wchar_t*)strIcon;
    m_layer = s_strLayerInteract;
    m_position = kPos;
    m_visible = true;
}
MS2_REPLACE_METHOD(0x141a34e30, UIMinimapEntityStorm, FUN_141a34e30, 0, 0);

// @0x141a34eb0
void UIMinimapEntityStorm::GetText(CStringW& strText, ASObj& data)
{
    strText.Empty();
}
MS2_REPLACE_METHOD(0x141a34eb0, UIMinimapEntityStorm, GetText, 0, 0);

// @0x141a34ee0
UIMinimapEntityPing::UIMinimapEntityPing(const efd::Point3& kPos)
    : UIMinimapEntity(10)
{
    FUN_141a34f40(kPos);
}

// @0x141a34f40
void UIMinimapEntityPing::FUN_141a34f40(const efd::Point3& kPos)
{
    m_icon = (const wchar_t*)s_strPing;
    m_layer = s_strLayerPlayer;
    m_position = kPos;
    m_visible = true;
    m_showGuide = true;
    m_showText = true;
    m_state = "red_flag";
    m_guideName = L"";
}
MS2_REPLACE_METHOD(0x141a34f40, UIMinimapEntityPing, FUN_141a34f40, 0, 0);

// @0x141a35000
void UIMinimapEntityPing::FUN_141a35000(unsigned __int64 nId, int nColor, const efd::Point3& kPos, const CStringW& strName)
{
    if (m_clip == 0)
        return;
    if (nColor == 0) {
        m_clip->Invoke("OnNotice");
        m_clip->FUN_1422c00f0(kPos.x, kPos.y);
        FUN_141276180(s_strRedPingSound, "");
    } else if (nColor == 1) {
        m_clip->Invoke("OnAlert");
        m_clip->FUN_1422c00f0(kPos.x, kPos.y);
        FUN_141276180(s_strBluePingSound, "");
    }
    m_guideName = strName;
    m_text = strName;
}
MS2_REPLACE_METHOD(0x141a35000, UIMinimapEntityPing, FUN_141a35000, 0, 0);

// @0x141a351e0
void UIMinimapEntityPing::GetText(CStringW& strText, ASObj& data)
{
    strText = m_text;
}
MS2_REPLACE_METHOD(0x141a351e0, UIMinimapEntityPing, GetText, 0, 0);

// ---- UIMinimapDialog ----

// @0x141a35220
UIMinimapDialog::UIMinimapDialog()
    : m_forceMinimize(false), m_fullmap(false), m_1fa(false), m_1fb(false), m_1fc(false),
      m_scale(1.0f), m_channel(0), m_208(NiPoint2::ZERO),
      m_210(false), m_211(false), m_212(false), m_460(0), m_468(0), m_47c(1)
{
    m_viewport = EE_NEW MinimapViewport;
    m_80 = 1;
    m_7c = 0;
    m_88 = 1;
    FUN_1422dc3b0(1);
    FUN_141a3b6f0();
    FUN_141925e70(0, 1);
    m_alignment = new UICommon::CAlignmentInfo(6, 0, 0);
}

// @0x141a358a0
UIMinimapDialog::~UIMinimapDialog()
{
    m_viewport = 0;
    m_data = 0;
    m_showAttrs.RemoveAll();
    m_clip228 = 0;
    FUN_141a3fd20();
}

// @0x141a35ba0
CString UIMinimapDialog::vfunc_1()
{
    return "MinimapDialog";
}
MS2_REPLACE_METHOD(0x141a35ba0, UIMinimapDialog, vfunc_1, 0, 0);

// @0x141a35bf0
void UIMinimapDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (FUN_1418fd2f0()) {
        vfunc_8(0);
        return;
    }
    FUN_141923680(1);
    FUN_141a3c150();
    FUN_141a3ced0();
    FUN_140c607b0()->FUN_1419308c0(this);
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140bc09f0()->FUN_141b38be0(this);
    FUN_140aa6d40()->FUN_141b0cd00(this);
    FUN_140a4a7b0()->FUN_1418d9450(this);
    FUN_140933230()->AddListener(this);
    if (UIObject* pWindow = FUN_140ce8310(0x4f00))
        pWindow->FUN_1422dc450();
    if (UIObject* pWindow = FUN_140ce8270(0x4f01))
        pWindow->FUN_1422dc450();
    if (UILevelUpPackageWidgetDialog* pWindow = Unk_MmFindDialog<UILevelUpPackageWidgetDialog>(0x4f5e))
        pWindow->FUN_1422dc450();
    FUN_141a42a70();
    if (FUN_141a45ce0()) {
        if (m_90.get()) {
            m_90->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMinimapDialog::FUN_141a456c0), 0);
            m_90->FUN_1422c2c30(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMinimapDialog::FUN_141a45720), 0);
        }
    }
}
MS2_REPLACE_METHOD(0x141a35bf0, UIMinimapDialog, OnLoadComplete, 0, 0);

// @0x141a35fe0
void UIMinimapDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140aa6d40()->FUN_141b0cd90(this);
    FUN_140c607b0()->FUN_141930950(this);
    FUN_140bfc4b0()->FUN_141aa8850(this);
    FUN_140bc09f0()->FUN_141b38c70(this);
    FUN_140a4a7b0()->FUN_1418d94e0(this);
    FUN_140933230()->RemoveListener(this);
    vfunc_63(0);
    m_forceMinimize = false;
    m_fullmap = false;
    m_1fa = false;
    m_1fb = false;
    m_1fc = false;
    m_scale = 1.0f;
    m_channel = 0;
    NiPoint2 kOrigin(NiPoint2::ZERO);
    m_208 = kOrigin;
    m_210 = false;
    m_211 = false;
    m_212 = false;
    m_data = 0;
    m_clip228 = 0;
    m_clip238 = 0;
    m_maxPanel = 0;
    FUN_141a3fd20();
    m_460 = 0;
    m_468 = 0;
    m_timer46c.FUN_140268840();
    m_timer474.FUN_140268840();
    m_47c = 1;
}
MS2_REPLACE_METHOD(0x141a35fe0, UIMinimapDialog, vfunc_26, 0, 0);

// @0x141a362b0
void UIMinimapDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30 == 0 || vfunc_64() == 1 || !m_1fc)
        return;
    if (!m_timer474.FUN_140268870(60))
        return;
    FUN_141a402b0(m_player);
    for (POSITION pos = m_proxies.GetHeadPosition(); pos != 0; m_proxies.GetNext(pos)) {
        ProxyPtr spProxy(0);
        EntityPtr spEntity(0);
        m_proxies.GetAt(pos, spProxy, spEntity);
        if (spProxy == 0)
            continue;
        int nKind = spEntity->vfunc_4();
        if (nKind == m_47c)
            FUN_141a3fe10(spProxy, spEntity, nKind);
        else
            FUN_141a400d0(spProxy, spEntity, nKind);
    }
    if (m_210 && m_47c == 4)
        m_210 = false;
    ++m_47c;
    if (m_47c >= 5)
        m_47c = 1;
    if (m_211) {
        m_211 = false;
        FUN_141a42550();
    }
    FUN_141a42bb0();
}
MS2_REPLACE_METHOD(0x141a362b0, UIMinimapDialog, vfunc_15, 0, 0);

// @0x141a36650
void UIMinimapDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_timer46c.FUN_140268870(1000)) {
        const std::pair<unsigned, __int64>& target = FUN_140764020()->FUN_1416d1e90();
        m_468 = target.first;
        m_460 = target.second;
    }
}
MS2_REPLACE_METHOD(0x141a36650, UIMinimapDialog, vfunc_72, 0, 0);

// The community dialog (COMDAT 0x141a46630).
template <class T> T* Unk_MmGetDialog()
{
    CUIService* pService = FUN_1403ed2b0();
    if (pService == 0)
        return 0;
    MS2Ptr<UIObject> obj = pService->FUN_141adcea0(T::GetUIClassID());
    if (!obj)
        return 0;
    return dynamic_cast<T*>(obj.operator->());
}

int FUN_1418fcee0();                                                // OnReport (uicommon)
CStringW FUN_140b99450(CStringW strKey, const CStringW& a1, const unsigned& a2);   // a formatted string table text
class Unk_MmFishing { public: CStringW FUN_140cdc000(unsigned nFieldId); };     // the fishing spot text of a field
Unk_MmFishing* FUN_140953f20();
bool FUN_1409b0350(Scaleform::GFx::Value* pValue);                  // the value is undefined

// @0x141a366d0
int UIMinimapDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnToggleMode", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bEnabled = data.FUN_1422b8a90();
            FUN_141a458d0(bEnabled);
        }
        return 1;
    } else if (_stricmp("OnChangeMode", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            m_fullmap = data.FUN_1422b8a90();
            m_212 = true;
        }
        return 1;
    } else if (_stricmp("OnWorldMap", szMethod) == 0) {
        FUN_1403ed2b0()->FUN_141adc750((eUIClassID)0x4e42);
        return 1;
    } else if (_stricmp("OnMorePlayers", szMethod) == 0) {
        if (FUN_1403ed2b0()->FUN_141adc940((eUIClassID)0x4e4d)) {
            UICommunityDialog* pDialog = Unk_MmGetDialog<UICommunityDialog>();
            if (pDialog != 0)
                pDialog->FUN_1418d6930(0);
        }
        FUN_1403ed2b0()->FUN_141adc750((eUIClassID)0x4e4d);
        return 1;
    } else if (_stricmp("OnCheckIcon", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CString strName = data.FUN_1422b8d30();
            unsigned int nChecked = data.FUN_1422b8a90() != false ? 1 : 0;
            MS2Ptr<TShowAttr> spAttr(0);
            if (m_showAttrs.Lookup(strName, spAttr))
                spAttr->m_state = nChecked;
        }
        return 1;
    } else if (_stricmp("OnChangeChannel", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nChannel = data.FUN_1422b8a10();
            if (!FUN_1403ed2d0()->FUN_141bc80c0(nChannel))
                FUN_141a44ed0();
        }
        return 1;
    } else if (_stricmp("OnPopupMenu", szMethod) == 0) {
        if (!m_1fa) {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs)) {
                float x = data.FUN_1422b8c10();
                float y = data.FUN_1422b8c10();
                unsigned __int64 nId = _atoi64(data.FUN_1422b8d30());
                FUN_141a45790(x, y, nId);
            }
        }
        return 1;
    } else if (_stricmp("OnUpdateCenter", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            m_208.x = data.FUN_1422b8c10();
            m_208.y = data.FUN_1422b8c10();
            m_scale = data.FUN_1422b8c10();
        }
        return 1;
    } else if (_stricmp("OnReport", szMethod) == 0) {
        return FUN_1418fcee0();
    } else if (_stricmp("OnWheelStepChange", szMethod) == 0) {
        m_212 = true;
        return 1;
    } else if (_stricmp("onFieldLoadComplete", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            Scaleform::GFx::Value value = data.FUN_1422b9260();
            if (!FUN_1409b0350(&value)) {
                ASMovieClip clip(value, 2);
                if (static_cast<MinimapViewport*>(m_viewport) != 0)
                    m_viewport->FUN_141485770(clip.FUN_1422c1340());
                m_1fc = true;
                FUN_141a3ea10();
            }
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141a366d0, UIMinimapDialog, vfunc_28, 0, 0);

// @0x141a36e50
bool UIMinimapDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    vfunc_18();
    return true;
}
MS2_REPLACE_METHOD(0x141a36e50, UIMinimapDialog, vfunc_17, 0, 0);

// @0x141a36e90
void UIMinimapDialog::vfunc_43()
{
    m_1fa = false;
    FUN_141a44e60();
    if (m_60 != 0) {
        if (m_alignment.get() != 0)
            m_alignment->FUN_141901cd0();
    }
    FUN_141a44f40();
}
MS2_REPLACE_METHOD(0x141a36e90, UIMinimapDialog, vfunc_43, 0, 0);

// @0x141a36f10
int UIMinimapDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (m_30 == 0)
        return 0;
    if (m_1fb)
        return 0;
    if (m_1fa && DAT_143af7d40 == 0) {
        FUN_141a3abd0();
    } else if (FUN_14025e7c0()->FUN_14116dd30(0x49407, 0, 0)) {
        if (!FUN_14025e7a0()->FUN_1422af2d0(m_28))
            FUN_141a3aca0();
    } else if (FUN_14025e7c0()->FUN_14116ddb0(0x49407, 0, 0)) {
        FUN_141a3abd0();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141a36f10, UIMinimapDialog, vfunc_13, 0, 0);

// @0x141a37010
void UIMinimapDialog::vfunc_18()
{
    if (static_cast<bool>(m_30.get()) && FUN_1422dc430()) {
        FUN_141a44e60();
        FUN_141a44f40();
    }
}
MS2_REPLACE_METHOD(0x141a37010, UIMinimapDialog, vfunc_18, 0, 0);

// MS2-FUNCTIONAL: the result byte is switched as an int (exe jumps straight to the end for 0); 2 attempts
// @0x141a37080
void UIMinimapDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() || m_30.IsNull())
        return;
    switch (static_cast<CInPacket*>(p)->FUN_14070fe80()) {
    case 0x10:
        if (m_30.IsNull())
            return;
        switch (static_cast<CInPacket*>(p)->vfunc_o8_1()) {
        case 0:
            break;
        default:
            FUN_141a44ed0();
            break;
        }
        break;
    }
}
MS2_REPLACE_METHOD(0x141a37080, UIMinimapDialog, vfunc_79, 0, 0);

// @0x141a37150
void UIMinimapDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    CString strTarget = pArgs->FUN_1422b8d30();
    if (strTarget == "m_fieldname") {
        ASTooltip tooltip(1, 2);
        {
            int nField = FUN_1403ed2d0()->FUN_141bd3060();
            MS2Ptr<CFieldDataCli> spData = CFieldDataCli::Find(nField);
            if (!spData)
                return;
            CStringW strText = FUN_140b99450(CStringW(L"s_minimap_tooltip_field_info"), FUN_1401a9d70()->FUN_141811980(3, nField), spData->m_nMapLevel);
            CStringW strExtra = FUN_140953f20()->FUN_140cdc000(nField);
            if (strExtra.GetLength() > 0) {
                strText += L"\n";
                strText += strExtra;
            }
            tooltip.FUN_1409c6d70("export_common_tooltip_tooltipText");
            tooltip.FUN_1409c6e00(300);
            tooltip.FUN_1409c6e30(60000);
            tooltip.FUN_1409c6dc0(7);
            tooltip.FUN_1409c6cb0(strText);
        }
        *pRetVal = tooltip.FUN_1422bb870();
    }
}
MS2_REPLACE_METHOD(0x141a37150, UIMinimapDialog, vfunc_49, 0, 0);

// The settings xml readers / writers (UIDialog's "transform" section).
void FUN_1408743d0(void* pCfg, const char* szGroup, const char* szName, bool b, bool bCreate);
void FUN_140874440(void* pCfg, const char* szGroup, const char* szName, int n, bool bCreate);
void FUN_1408744b0(void* pCfg, const char* szGroup, const char* szName, float f, bool bCreate);
void FUN_140874130(void* pCfg, const char* szGroup, const char* szName, bool* pb);
void FUN_1408741a0(void* pCfg, const char* szGroup, const char* szName, int* pn);
void FUN_140874210(void* pCfg, const char* szGroup, const char* szName, float* pf);
void* FUN_140165cf0(void* pCfg, const char* szName);                // the child element
float FUN_141276490(float fWidth, float fHeight);                   // UI scale
struct Unk_MmScaleInfo { __int64 m_pad_00; float m_fValue; };
void* FUN_1409a8b10();
Unk_MmScaleInfo* FUN_140e09150(void* p);
extern unsigned DAT_143af62d4;                                      // client area width
extern unsigned DAT_143af62d8;                                      // client area height
double FUN_140f17ed0(const Scaleform::GFx::Value& v);               // Value::GetNumber
int FUN_1409c1750(const Scaleform::GFx::Value& v);                  // the value as an int
bool FUN_1409c1720(const Scaleform::GFx::Value& v);                 // the value as a bool

// @0x141a37480
int UIMinimapDialog::vfunc_53(void* pCfg)
{
    if (m_80 == 0)
        return 1;
    if (m_30.get() != 0) {
        float x = 0;
        float y = 0;
        float fScale = 1.0f;
        int nBgAlpha = 30;
        int nMapAlpha = 100;
        int nWidth = 0;
        int nHeight = 0;
        bool bFullmap = m_fullmap;
        bool bMinimize = vfunc_64() == 1;
        Scaleform::GFx::Value saveData = m_30->Invoke("getSaveData");
        AScript save(saveData, 2);
        if (!save.FUN_1422ba9a0()) {
            x = static_cast<float>(FUN_140f17ed0(save.FUN_1422baa20("x")));
            y = static_cast<float>(FUN_140f17ed0(save.FUN_1422baa20("y")));
            nWidth = FUN_1409c1750(save.FUN_1422baa20("width"));
            nHeight = FUN_1409c1750(save.FUN_1422baa20("height"));
            nMapAlpha = FUN_1409c1750(save.FUN_1422baa20("mapAlpha"));
            nBgAlpha = FUN_1409c1750(save.FUN_1422baa20("bgAlpha"));
            fScale = static_cast<float>(FUN_140f17ed0(save.FUN_1422baa20("scale")));
            bFullmap = FUN_1409c1720(save.FUN_1422baa20("fullmap"));
            bMinimize = FUN_1409c1720(save.FUN_1422baa20("minimize"));
        }
        FUN_1408744b0(pCfg, "transform", "x", x, 1);
        FUN_1408744b0(pCfg, "transform", "y", y, 1);
        float fRatio = FUN_141276490(static_cast<float>(DAT_143af62d4), FUN_140e09150(FUN_1409a8b10())->m_fValue);
        FUN_1408744b0(pCfg, "transform", "rateX", x / (static_cast<float>(DAT_143af62d4) * fRatio), 1);
        FUN_1408744b0(pCfg, "transform", "rateY", y / (static_cast<float>(DAT_143af62d8) * fRatio), 1);
        FUN_140874440(pCfg, "transform", "width", nWidth, 1);
        FUN_140874440(pCfg, "transform", "height", nHeight, 1);
        FUN_1408744b0(pCfg, "transform", s_strScale, fScale, 1);
        FUN_140874440(pCfg, "transform", s_strBgAlpha, nBgAlpha, 1);
        FUN_140874440(pCfg, "transform", s_strMapAlpha, nMapAlpha, 1);
        FUN_1408743d0(pCfg, "transform", s_strFullmap, bFullmap, 1);
        FUN_1408743d0(pCfg, "transform", s_strMinimize, bMinimize, 1);
        if (static_cast<bool>(m_alignment.get()) && static_cast<bool>(m_90.get())) {
            float fLeft = static_cast<float>(m_90->FUN_1422c1500());
            float fTop = static_cast<float>(m_90->FUN_1422c1530());
            m_alignment->FUN_141901880(m_30, static_cast<float>(nWidth), static_cast<float>(nHeight), fLeft, fTop);
            m_alignment->FUN_1419015e0(static_cast<Unk_140165cf0*>(pCfg));
        }
        for (POSITION pos = m_showAttrs.GetStartPosition(); pos != 0; m_showAttrs.GetNext(pos)) {
            MS2Ptr<TShowAttr> spAttr = m_showAttrs.GetValueAt(pos);
            if (spAttr == 0)
                continue;
            FUN_140874440(pCfg, s_strIconCheck, m_showAttrs.GetKeyAt(pos), spAttr->m_state, 1);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141a37480, UIMinimapDialog, vfunc_53, 0, 0);

// @0x141a37db0
int UIMinimapDialog::vfunc_54(void* pCfg)
{
    if (!UIDialog::vfunc_54(pCfg))
        return 0;
    FUN_140874130(pCfg, "transform", s_strFullmap, &m_fullmap);
    FUN_1408741a0(pCfg, "transform", s_strMinimize, &m_6c);
    float fScale = 1.0f;
    int nBgAlpha = 30;
    int nMapAlpha = 100;
    int nWidth = 0;
    int nHeight = 0;
    FUN_140874210(pCfg, "transform", s_strScale, &fScale);
    FUN_1408741a0(pCfg, "transform", "width", &nWidth);
    FUN_1408741a0(pCfg, "transform", "height", &nHeight);
    FUN_1408741a0(pCfg, "transform", s_strBgAlpha, &nBgAlpha);
    FUN_1408741a0(pCfg, "transform", s_strMapAlpha, &nMapAlpha);
    m_data.AssignRaw(new AScript(2));
    static_cast<ASObj*>(m_data.operator->())->FUN_1407cb9c0("width", nWidth);
    static_cast<ASObj*>(m_data.operator->())->FUN_1407cb9c0("height", nHeight);
    static_cast<ASObj*>(m_data.operator->())->FUN_1407cb9c0("mapAlpha", nMapAlpha);
    static_cast<ASObj*>(m_data.operator->())->FUN_1407cb9c0("bgAlpha", nBgAlpha);
    static_cast<ASObj*>(m_data.operator->())->FUN_1409c4a30("scale", fScale);
    void* pSection = FUN_140165cf0(pCfg, s_strIconCheck);
    if (pSection != 0) {
        for (POSITION pos = m_showAttrs.GetStartPosition(); pos != 0; m_showAttrs.GetNext(pos)) {
            ShowAttrMap::CPair* pPair = m_showAttrs.GetAt(pos);
            if (pPair == 0)
                continue;
            MS2Ptr<TShowAttr> spAttr = pPair->m_value;
            if (spAttr == 0)
                continue;
            FUN_1408741a0(pCfg, s_strIconCheck, pPair->m_key, &spAttr->m_state);
        }
    }
    if (static_cast<bool>(m_alignment.get()) && static_cast<bool>(m_90.get())) {
        if (!m_alignment->FUN_141901660(static_cast<Unk_140165cf0*>(pCfg))) {
            float fLeft = static_cast<float>(m_90->FUN_1422c1500());
            float fTop = static_cast<float>(m_90->FUN_1422c1530());
            m_alignment->FUN_141901880(m_30, static_cast<float>(nWidth), static_cast<float>(nHeight), fLeft, fTop);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141a37db0, UIMinimapDialog, vfunc_54, 0, 0);

// @0x141a373f0
int UIMinimapDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    if (FUN_1418fd2f0()) {
        m_80 = 0;
        return 0;
    }
    m_80 = 1;
    FUN_14192e8f0();
    return 1;
}
MS2_REPLACE_METHOD(0x141a373f0, UIMinimapDialog, vfunc_65, 0, 0);

// @0x141a37450
void UIMinimapDialog::vfunc_67()
{
    FUN_141a3abd0();
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x141a37450, UIMinimapDialog, vfunc_67, 0, 0);

// @0x141a38390
int UIMinimapDialog::vfunc_52()
{
    return 1;
}
MS2_REPLACE_METHOD(0x141a38390, UIMinimapDialog, vfunc_52, 0, 0);
