// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The minimap window and its markers: see uiminimapentity.h. w508.
// MS2-UNIT: ?\uiminimapentity.cpp
// MS2-RANGE: 0x141a30f30-0x141a517d0 .text$mn
// MS2-RANGE: 0x140117c70-0x140118e40 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMinimapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x141a47ab0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VUIMinimapEntityPing@@@@QEAA@PEAVUIMinimapEntityPing@@@Z 0x141a47e30 ; unique
// MS2-PIN: ??0?$MS2Ptr@VUIMinimapEntityProxyPortal@@@@QEAA@PEAVUIMinimapEntityProxyPortal@@@Z 0x141a47e60 ; unique
// MS2-PIN: ??1?$MS2Ptr@VUIMinimapEntityProxyPortal@@@@QEAA@XZ 0x141a48610 ; unique
// MS2-PIN: ??1?$MS2Ptr@VUIMinimapEntityTaxi@@@@QEAA@XZ 0x141a48640 ; unique
// MS2-PIN: ??8?$MS2Ptr@VUIMinimapEntityPing@@@@QEBA_NPEAVUIMinimapEntityPing@@@Z 0x141a48c20 ; unique
// MS2-PIN: ??8?$MS2Ptr@VUIMinimapEntityProxyPortal@@@@QEBA_NPEAVUIMinimapEntityProxyPortal@@@Z 0x141a48c60 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUIMinimapEntityPing@@@@QEBAPEAVUIMinimapEntityPing@@XZ 0x141a48d50 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUIMinimapEntityProxyPortal@@@@QEBAPEAVUIMinimapEntityProxyPortal@@XZ 0x141a48d60 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUIMinimapEntityTaxi@@@@QEBAPEAVUIMinimapEntityTaxi@@XZ 0x141a48d70 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCNpcData@@@@QEBAPEAVCNpcData@@XZ 0x141a48d80 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$TPtrValue@V?$CAtlList@_KV?$CElementTraits@_K@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlList@_KV?$CElementTraits@_K@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x141a4ac40 ; unique
// MS2-PIN: ?FUN_141a4b020@UIMinimapEntityProxyPortal@@QEBAHXZ 0x141a4b020 ; unique
// MS2-PIN: ?vfunc_4@UIMinimapEntity@@UEAAHXZ 0x141a4b200 ; unique
// MS2-PIN: ?vfunc_48@UIMinimapDialog@@UEAAHXZ 0x141a4b210 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAPEAVCPair@12@_K@Z 0x141a4c6d0 ; unique
// MS2-PIN: ?FUN_141a50bc0@UIMinimapEntityProxyPortal@@QEAAXAEBH@Z 0x141a50bc0 ; unique
// MS2-PIN: ?FUN_141a51030@UIMinimapEntityProxyPortal@@QEAAX_N@Z 0x141a51030 ; unique
// MS2-PIN: ?FUN_141a51050@UIMinimapEntityProxyPortal@@QEAAXH@Z 0x141a51050 ; unique
// MS2-PINS-END tplpin
#define NOMINMAX
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
#include "ms2/client/ms2/interactobject.h"
#include "ms2/placeholder/cquestnavigator.h"
#include <efd/utf8string.h>
#include "ms2/fmt/format.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/placeholder/cpartymember.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/commonfiles/pvpinfo.h"
#include "ms2/client/ms2/hardwareinstancingservice.h"
#include "ms2/client/ms2/uiserverlistdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----


// The world's per-object proxy (RTTI .?AVCProxyGameObject@@, 0xe8). Unit-local typed view of
// placeholder/cproxygameobject.h: its +0x18 / +0x28 handles are MS2Ptr<CPortal> / MS2Ptr<NpcDataCli> here.
class CProxyGameObject : public CPtred
{
public:
    int FUN_1416c1ff0();                                            // the local player's own object
    int FUN_1416c2040();                                            // another player's object
    int FUN_1416c2090();                                            // has a template id
    int FUN_1416c20d0();                                            // has a portal
    int FUN_1416c2110();                                            // the portal is shown on the minimap
    Unk_QmNpcQuestState* FUN_1416c2200();                         // the quest guide (+0x88)
    MS2Ptr<NpcDataCli> FUN_1416c2220();                             // the npc data
    __int64 FUN_1416c22f0();                                        // the owner character id
    int FUN_1416c2350();                                            // the template (npc) id
    CStringW FUN_1416c23b0();                                       // the name
    CString FUN_1416c2520();                                        // the portrait path
    CStringW FUN_1416c2570();                                       // the today word
    bool FUN_1416c2b30();                                           // visible on the minimap
    bool FUN_1416c2b70();                                           // the visibility follows the actor
    int FUN_1416c21c0();                                            // a pet
    efd::Point3 FUN_1416c2270();                                    // the position

    MS2Ptr<CPortal> m_portal;                                       // +0x18
    MS2Ptr<NpcDataCli> m_npc;                                       // +0x28
    int m_proxyId;                                                  // +0x38 (object id)
    int m_pad_3c;
    __int64 m_charId;                                               // +0x40 owner character id
    __int64 m_48;
    CString m_50;
    CStringW m_name;                                                // +0x58
    __int64 m_60;
    int m_68;                                                       // +0x68 dead
    int m_6c;
    char m_pad_70[0xcc - 0x70];
    int m_cc;                                                       // +0xcc the actor state (0x3f: hidden)
};

// The entity list a world model lookup returns (the same view as uiworldmapdialog.cpp).
struct Unk_MmEntityList
{
    ~Unk_MmEntityList();                                                    // 0x1409f20e0
    ATL::CAtlList<efd::SmartPointer<egf::Entity> >* FUN_1409f2170() const;  // get
    ATL::CAtlList<efd::SmartPointer<egf::Entity> >* FUN_1409f2190() const;  // operator->
    void* m_0;
    void* m_8;
};
struct Unk_MmMinimapInfo : public CPtred                            // the field's minimap settings
{
    CString m_image;                                                // +0x18 the minimap image
};
struct Unk_MmFieldInfo : public CPtred                              // the current field's settings (world +0x298)
{
    char m_pad_18[0x64 - 0x18];
    int m_64;                                                       // +0x64 nonzero: the minimap is forced minimized
    char m_pad_68[0x150 - 0x68];
    bool m_allowPing;                                               // +0x150
    char m_pad_151[0x160 - 0x151];
    MS2Ptr<Unk_MmMinimapInfo> m_minimap;                            // +0x160
    int FUN_1403754d0();                                            // the pk mode
};
class Unk_MmWorld                                                   // the world service (FUN_1403ed2d0)
{
public:
    class MyPC* FUN_141bd0cc0();                                    // the local player
    int FUN_141bd3060();                                            // the current map id
    MS2Ptr<CProxyGameObject> FUN_141bc9be0(int nId);                // a proxy by object id
    int FUN_141bc80c0(int nChannel);                                // change the channel
    Unk_MmEntityList FUN_141bd0420(unsigned nModel);                // the entities of a model
    MS2Ptr<Unk_MmFieldInfo> FUN_141bd30a0();                        // the current field settings
    MS2Ptr<CProxyGameObject> FUN_141bc9c60(unsigned __int64 nUid);  // a proxy by character uid
    class Unk_MmActor* FUN_141bd1320(int nId);                      // the actor of an object id
    PC* FUN_141bd1530(unsigned __int64 nCharId);                    // a player by character id
    void FUN_141bc5f10(ATL::CAtlArray<MS2Ptr<CInteractObject> >& objects);   // the interact objects
    int FUN_141bd98f0();                                            // the channel group
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);  // an interact object by name
    ATL::CAtlMap<unsigned int, MS2Ptr<CProxyGameObject> >& FUN_141bc9fb0();   // the proxy objects by object id
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
class Unk_MmConfigValue { public: unsigned* FUN_1401d7c10(); };    // Value<unsigned int>::Get
class Unk_MmGameConfig                                              // Client::Constants (only the members read here)
{
public:
    char m_pad[0xae70];
    Unk_MmConfig m_colors;                                          // +0xae70 NameTagColorFriendly
    char m_pad_ae71[0xda48 - 0xae71];
    Unk_MmConfigValue m_minimapCell;                                // +0xda48 MinimapScaleSkipSplitPixel
};
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
class CQuest : public CPtred, public Unk_MmQuestData {};          // the interface is the second base (+0x18)
CString FUN_1401d2b10(const CString& a, const CString& b);         // a + b (exe operator+; clang would import MFC CopyChars)

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
static CString s_strNoIcon = MS2_MINIMAP_NOICON_SRC;
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
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strBluePingSound = "System_BluePing_01";
static CString s_strRedPingSound = "System_RedPing_01";
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
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
MS2_REPLACE_METHOD(0x141a310e0, UIMinimapEntity, FUN_141a310e0, 389, 0x38FD60B2);

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
MS2_REPLACE_METHOD(0x141a31270, UIMinimapEntity, FUN_141a31270, 1101, 0x837C432C);

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
MS2_REPLACE_METHOD(0x141a316d0, UIMinimapEntity, FUN_141a316d0, 780, 0x51BBD233);

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
MS2_REPLACE_METHOD(0x141a319f0, UIMinimapEntity, FUN_141a319f0, 648, 0xB42DAA1D);

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
            if (static_cast<bool>(spQuest.get()) && spQuest->vfunc_1()) {
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
        MS2Ptr<CQuestData> spData = spQuest.get() ? spQuest->vfunc_0() : FUN_14074bc40(nQuestId);
        const CString& strSuffix = FUN_141082150(spData, "_epic", "_world", "_repeat", "_event");
        if (bSuffix)
            strIcon += strSuffix;
        strLayer += FUN_1401d2b10(s_strLayerQuest, strSuffix);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x141a31c80, UIMinimapEntity, FUN_141a31c80, 1165, 0xD673AD64);

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
MS2_REPLACE_METHOD(0x141a32120, UIMinimapEntity, FUN_141a32120, 312, 0x1DDD54D5);

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
MS2_REPLACE_METHOD(0x141a32260, UIMinimapEntity, FUN_141a32260, 190, 0x14DE07A2);

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
MS2_REPLACE_METHOD(0x141a32330, UIMinimapEntity, FUN_141a32330, 164, 0x87D81A70);

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
MS2_REPLACE_METHOD(0x141a32500, UIMinimapEntity, GetText, 267, 0x2BEF602D);

// @0x141a32620
void UIMinimapEntity::vfunc_2(ASObj* pData)
{
}
MS2_REPLACE_METHOD(0x141a32620, UIMinimapEntity, vfunc_2, 11, 0x02239C70);

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
MS2_REPLACE_METHOD(0x141a32640, UIMinimapEntity, FUN_141a32640, 264, 0xE39CD148);

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
MS2_REPLACE_METHOD(0x141a32750, UIMinimapEntity, FUN_141a32750, 638, 0x25D61A8E);

// @0x141a329e0
CString UIMinimapEntity::FUN_141a329e0(const CString& strIcon)
{
    if (strIcon == s_strEliteBoss || strIcon == s_strBoss || strIcon == s_strEventBoss)
        return s_strAlive;
    return "";
}
MS2_REPLACE_METHOD(0x141a329e0, UIMinimapEntity, FUN_141a329e0, 174, 0xA64ECAAB);

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
MS2_REPLACE_METHOD(0x141a32aa0, UIMinimapEntity, FUN_141a32aa0, 236, 0x6D436F94);

// @0x141a32ba0
CStringW UIMinimapEntity::FUN_141a32ba0(Unk_BuddyPtr<CBuddy> spBuddy)
{
    if (spBuddy == 0)
        return L"";
    CStringW strHome = FUN_1409796e0(spBuddy->FUN_1401cc3e0(), spBuddy->FUN_1401cc3a0(), spBuddy->FUN_1401cc3c0(), spBuddy->FUN_1401cc350());
    return FUN_14028dfa0(L"s_worldmap_tooltip_friendhome", strHome);
}
MS2_REPLACE_METHOD(0x141a32ba0, UIMinimapEntity, FUN_141a32ba0, 390, 0x45717DE1);

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
MS2_REPLACE_METHOD(0x141a32da0, UIMinimapEntityProxy, FUN_141a32da0, 111, 0x93351C5B);

// @0x141a32e20
void UIMinimapEntityProxy::GetText(CStringW& strText, ASObj& data)
{
    MS2Ptr<CProxyGameObject> spProxy = FUN_141a32da0();
    if (spProxy == 0)
        return;
    vfunc_5(spProxy, strText, data);
}
MS2_REPLACE_METHOD(0x141a32e20, UIMinimapEntityProxy, GetText, 155, 0xDD25025D);

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
                    FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4ebd);
            }
        }
    } else if (spProxy->FUN_1416c2090()) {
        UIBossRewardPreviewDialog* pDialog = Unk_MmFindDialog<UIBossRewardPreviewDialog>(0x4efb);
        if (pDialog) {
            FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4efb);
            if (pDialog->FUN_140f25ad0(spProxy->FUN_1416c2350()))
                FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4efb);
        }
    }
    }
}
MS2_REPLACE_METHOD(0x141a32ed0, UIMinimapEntityProxy, vfunc_3, 389, 0xE3B4CF7E);

// @0x141a33060
int UIMinimapEntityProxy::vfunc_4()
{
    return m_kind;
}
MS2_REPLACE_METHOD(0x141a33060, UIMinimapEntityProxy, vfunc_4, 14, 0xD1D12A47);

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
        Unk_QmNpcQuestState* pInfo = spProxy->FUN_1416c2200();
        if (pInfo->m_icon != 0xb) {
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
MS2_REPLACE_METHOD(0x141a33080, UIMinimapEntityProxy, vfunc_5, 1357, 0x6DCA8BBE);

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
MS2_REPLACE_METHOD(0x141a33650, UIMinimapEntityProxyPortal, FUN_141a33650, 39, 0xF292E240);

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
MS2_REPLACE_METHOD(0x141a33680, UIMinimapEntityProxyPortal, vfunc_5, 444, 0x1694A5EB);

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
MS2_REPLACE_METHOD(0x141a33850, UIMinimapEntityProxyPortal, FUN_141a33850, 1494, 0xAD2BDB4B);

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
MS2_REPLACE_METHOD(0x141a33e30, UIMinimapEntityProxyPortal, FUN_141a33e30, 1806, 0xFF202207);

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
MS2_REPLACE_METHOD(0x141a345c0, UIMinimapEntityBuddyHome, GetText, 161, 0x8388091F);

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
MS2_REPLACE_METHOD(0x141a34700, UIMinimapEntityMapObject, GetText, 263, 0xD0921D42);

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
MS2_REPLACE_METHOD(0x141a34890, UIMinimapEntityTaxi, FUN_141a34890, 908, 0x75C22537);

// @0x141a34870
void UIMinimapEntityTaxi::FUN_141a34870(bool bBest)
{
    m_best = bBest;
}
MS2_REPLACE_METHOD(0x141a34870, UIMinimapEntityTaxi, FUN_141a34870, 23, 0x1A4301B5);

// @0x141a34c30
void UIMinimapEntityTaxi::GetText(CStringW& strText, ASObj& data)
{
    strText = m_best ? FUN_14028b8e0(L"s_word_besttaxistation") : FUN_14028b8e0(L"s_word_taxistation");
}
MS2_REPLACE_METHOD(0x141a34c30, UIMinimapEntityTaxi, GetText, 368, 0xC0965097);

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
MS2_REPLACE_METHOD(0x141a34e30, UIMinimapEntityStorm, FUN_141a34e30, 113, 0xE51E0043);

// @0x141a34eb0
void UIMinimapEntityStorm::GetText(CStringW& strText, ASObj& data)
{
    strText.Empty();
}
MS2_REPLACE_METHOD(0x141a34eb0, UIMinimapEntityStorm, GetText, 35, 0xFDDC58CE);

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
MS2_REPLACE_METHOD(0x141a34f40, UIMinimapEntityPing, FUN_141a34f40, 174, 0xC68B0059);

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
MS2_REPLACE_METHOD(0x141a35000, UIMinimapEntityPing, FUN_141a35000, 471, 0xECE9CD61);

// @0x141a351e0
void UIMinimapEntityPing::GetText(CStringW& strText, ASObj& data)
{
    strText = m_text;
}
MS2_REPLACE_METHOD(0x141a351e0, UIMinimapEntityPing, GetText, 47, 0x85DA9292);

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
MS2_REPLACE_METHOD(0x141a35ba0, UIMinimapDialog, vfunc_1, 61, 0xE2400997);

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
MS2_REPLACE_METHOD(0x141a35bf0, UIMinimapDialog, OnLoadComplete, 992, 0x16529FDF);

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
MS2_REPLACE_METHOD(0x141a35fe0, UIMinimapDialog, vfunc_26, 707, 0xEB99CE5C);

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
MS2_REPLACE_METHOD(0x141a362b0, UIMinimapDialog, vfunc_15, 916, 0x744426E4);

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
MS2_REPLACE_METHOD(0x141a36650, UIMinimapDialog, vfunc_72, 119, 0xABF169B7);

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
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4e42);
        return 1;
    } else if (_stricmp("OnMorePlayers", szMethod) == 0) {
        if (FUN_1403ed2b0()->FUN_141adc940((eUIClassID)0x4e4d)) {
            UICommunityDialog* pDialog = Unk_MmGetDialog<UICommunityDialog>();
            if (pDialog != 0)
                pDialog->FUN_1418d6930(0);
        }
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4e4d);
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
MS2_REPLACE_METHOD(0x141a366d0, UIMinimapDialog, vfunc_28, 1862, 0x371BD9E1);

// @0x141a36e50
bool UIMinimapDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    vfunc_18();
    return true;
}
MS2_REPLACE_METHOD(0x141a36e50, UIMinimapDialog, vfunc_17, 56, 0xE31DC9A6);

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
MS2_REPLACE_METHOD(0x141a36e90, UIMinimapDialog, vfunc_43, 108, 0x65931339);

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
MS2_REPLACE_METHOD(0x141a36f10, UIMinimapDialog, vfunc_13, 242, 0x0AE9BAF2);

// @0x141a37010
void UIMinimapDialog::vfunc_18()
{
    if (static_cast<bool>(m_30.get()) && FUN_1422dc430()) {
        FUN_141a44e60();
        FUN_141a44f40();
    }
}
MS2_REPLACE_METHOD(0x141a37010, UIMinimapDialog, vfunc_18, 91, 0x42C557CB);

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
MS2_REPLACE_METHOD(0x141a37080, UIMinimapDialog, vfunc_79, 190, 0x7B420DBA);

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
MS2_REPLACE_METHOD(0x141a37150, UIMinimapDialog, vfunc_49, 662, 0x279A0D2F);

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
MS2_REPLACE_METHOD(0x141a37480, UIMinimapDialog, vfunc_53, 2338, 0x38DA50FE);

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
MS2_REPLACE_METHOD(0x141a37db0, UIMinimapDialog, vfunc_54, 1484, 0xF135E625);

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
MS2_REPLACE_METHOD(0x141a373f0, UIMinimapDialog, vfunc_65, 85, 0xB26CB77A);

// @0x141a37450
void UIMinimapDialog::vfunc_67()
{
    FUN_141a3abd0();
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x141a37450, UIMinimapDialog, vfunc_67, 34, 0xCF85CBAA);

// @0x141a38390
int UIMinimapDialog::vfunc_52()
{
    return 1;
}
MS2_REPLACE_METHOD(0x141a38390, UIMinimapDialog, vfunc_52, 11, 0x30025ED0);

CString FUN_140719530(unsigned __int64 nId);                        // "%I64u"
CString FUN_141028a90(CString strId, int bDefault);                 // the UGC profile image path
void FUN_1406c70a0(void* pActor);                                   // ~MS2Ptr<CProxyGameObject> (the by-value actor)

// @0x141a383b0
void UIMinimapDialog::vfunc_ugc_1(void* p, CString str)
{
    if (m_30.get() != 0) {
        CString strKey = FUN_140719530(reinterpret_cast<unsigned __int64>(p));
        m_30->FUN_1413127f0("changePlayer", strKey, FUN_141028a90(str, 1));
    }
}
MS2_REPLACE_METHOD_VIA(0x141a383b0, UIMinimapDialog, UIUGCEventListener, vfunc_ugc_1, 320, 0x51752DA6);

// @0x141a38500
void UIMinimapDialog::vfunc_ugc_5()
{
    if (vfunc_55())
        return;
    FUN_141a3a9a0(false);
    FUN_141a39e60();
}
MS2_REPLACE_METHOD_VIA(0x141a38500, UIMinimapDialog, UIUGCEventListener, vfunc_ugc_5, 102, 0x66758822);

// @0x141a38570
void UIMinimapDialog::vfunc_ugc_6()
{
    if (vfunc_55())
        return;
    FUN_141a3a9a0(true);
    FUN_141a39e60();
}
MS2_REPLACE_METHOD_VIA(0x141a38570, UIMinimapDialog, UIUGCEventListener, vfunc_ugc_6, 102, 0x9D9C5CC7);

// MS2-FUNCTIONAL: frame 0x20 larger (temporaries of the by-value entity/buddy copies); 2 attempts
// @0x141a385e0
void UIMinimapDialog::vfunc_buddy_10(__int64 nId, int n)
{
    if (m_30 == 0)
        return;
    Unk_BuddyPtr<CBuddy> spBuddy = CBuddyManager::GetInstance()->FUN_140ae4b70(nId);
    if (spBuddy == 0)
        return;
    int nField = spBuddy->FUN_1401cc3e0();
    if (static_cast<unsigned int>(nField) > 0) {
        int nCurrent = FUN_1403ed2d0()->FUN_141bd3060();
        if (nCurrent == nField) {
            EntityPtr spEntity(0);
            if (m_buddies.Lookup(nId, spEntity))
                FUN_141a3f930(spEntity);
            FUN_141a3e2d0(spBuddy);
        } else {
            FUN_141a454d0(nField, nId);
        }
        if (static_cast<unsigned int>(n) > 0)
            FUN_141a455e0(n, nId);
    } else {
        EntityPtr spEntity(0);
        if (m_buddies.Lookup(nId, spEntity))
            FUN_141a3f930(spEntity);
        else if (static_cast<unsigned int>(n) > 0)
            FUN_141a455e0(n, nId);
    }
}
MS2_REPLACE_METHOD_VIA(0x141a385e0, UIMinimapDialog, UIBuddyEventListener, vfunc_buddy_10, 666, 0xD25223C1);

// @0x141a38880
void UIMinimapDialog::vfunc_buddy_5(__int64 nId)
{
    Unk_BuddyPtr<CBuddy> spBuddy = CBuddyManager::GetInstance()->FUN_140ae4b70(nId);
    if (spBuddy == 0)
        return;
    FUN_141a3f9f0(spBuddy);
}
MS2_REPLACE_METHOD_VIA(0x141a38880, UIMinimapDialog, UIBuddyEventListener, vfunc_buddy_5, 148, 0xE6AABD87);

// @0x141a38920
void UIMinimapDialog::vfunc_buddy_4(__int64 nId, int n)
{
    if (!n)
        return;
    Unk_BuddyPtr<CBuddy> spBuddy = CBuddyManager::GetInstance()->FUN_140ae4b70(nId);
    if (spBuddy == 0)
        return;
    FUN_141a3f9f0(spBuddy);
}
MS2_REPLACE_METHOD_VIA(0x141a38920, UIMinimapDialog, UIBuddyEventListener, vfunc_buddy_4, 165, 0xBDF902EA);

// @0x141a389d0
void UIMinimapDialog::vfunc_buddy_3(__int64 nId)
{
    vfunc_buddy_10(nId, 0);
}
MS2_REPLACE_METHOD_VIA(0x141a389d0, UIMinimapDialog, UIBuddyEventListener, vfunc_buddy_3, 56, 0xAA097725);

// @0x141a38a10
void UIMinimapDialog::vfunc_oa0_9(unsigned short a1)
{
    if (m_30 == 0)
        return;
    m_210 = true;
    FUN_141a3a200();
}
MS2_REPLACE_METHOD_VIA(0x141a38a10, UIMinimapDialog, UIStatusEventListener, vfunc_oa0_9, 80, 0x1B176E1B);

// @0x141a38a70
void UIMinimapDialog::vfunc_oa0_7(int a1, CStringW s)
{
    if (m_30 == 0)
        return;
    m_210 = true;
}
MS2_REPLACE_METHOD_VIA(0x141a38a70, UIMinimapDialog, UIStatusEventListener, vfunc_oa0_7, 96, 0x85711457);

// @0x141a38ae0
void UIMinimapDialog::vfunc_oa0_20(int a1)
{
    FUN_141a42a70();
}
MS2_REPLACE_METHOD_VIA(0x141a38ae0, UIMinimapDialog, UIStatusEventListener, vfunc_oa0_20, 37, 0x92EE80B3);

// @0x141a38b10
int UIMinimapDialog::vfunc_oa0_1()
{
    if (vfunc_55())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x141a38b10, UIMinimapDialog, UIStatusEventListener, vfunc_oa0_1, 69, 0x830FFD61);

// @0x141a38b60
void UIMinimapDialog::Notify()
{
    FUN_141a42800();
}
MS2_REPLACE_METHOD_VIA(0x141a38b60, UIMinimapDialog, UIServerEventListener, Notify, 33, 0x1C92923F);

// MS2-FUNCTIONAL: the exe takes the actor as a by-value MS2Ptr (EH frame); the shared slot is declared void*
// @0x141a38b90
void UIMinimapDialog::vfunc_3(void* pActor)
{
    if (m_30 == 0) {
        FUN_1406c70a0(pActor);
        return;
    }
    FUN_141a3d080(*static_cast<const ProxyPtr*>(pActor));
    FUN_1406c70a0(pActor);
}
MS2_REPLACE_METHOD_VIA(0x141a38b90, UIMinimapDialog, UIEntityEventListener, vfunc_3, 133, 0xC8D16EBF);

// MS2-FUNCTIONAL: the exe takes the actor as a by-value MS2Ptr (EH frame); the shared slot is declared void*
// @0x141a38c20
void UIMinimapDialog::vfunc_4(void* pActor)
{
    if (m_30 == 0) {
        FUN_1406c70a0(pActor);
        return;
    }
    FUN_141a3f600(*static_cast<const ProxyPtr*>(pActor));
    FUN_1406c70a0(pActor);
}
MS2_REPLACE_METHOD_VIA(0x141a38c20, UIMinimapDialog, UIEntityEventListener, vfunc_4, 133, 0xF5478FEC);

// @0x141a38cb0
void UIMinimapDialog::vfunc_o178_1(void* p)
{
    if (vfunc_55())
        return;
    if (p != 0 && static_cast<bool>(static_cast<CQuest*>(p)->vfunc_0().get()))
        FUN_141a3ada0();
}
MS2_REPLACE_METHOD_VIA(0x141a38cb0, UIMinimapDialog, UIQuestEventListener, vfunc_o178_1, 294, 0xA47B2DEF);

// @0x141a38de0
void UIMinimapDialog::vfunc_o178_2(void* p)
{
    if (vfunc_55())
        return;
    if (p != 0 && static_cast<bool>(static_cast<CQuest*>(p)->vfunc_0().get()))
        FUN_141a3ada0();
}
MS2_REPLACE_METHOD_VIA(0x141a38de0, UIMinimapDialog, UIQuestEventListener, vfunc_o178_2, 294, 0x0513889D);

// @0x141a38f10
void UIMinimapDialog::vfunc_o178_3(void* p)
{
    if (vfunc_55())
        return;
    if (p != 0 && static_cast<bool>(static_cast<CQuest*>(p)->vfunc_0().get()))
        FUN_141a3ada0();
}
MS2_REPLACE_METHOD_VIA(0x141a38f10, UIMinimapDialog, UIQuestEventListener, vfunc_o178_3, 294, 0xAB5504E1);

// @0x141a39040
void UIMinimapDialog::vfunc_o178_4(void* p)
{
}

// @0x141a39060
void UIMinimapDialog::vfunc_o178_7(int a1, int a2)
{
    if (vfunc_55())
        return;
    FUN_141a3ada0();
}
MS2_REPLACE_METHOD_VIA(0x141a39060, UIMinimapDialog, UIQuestEventListener, vfunc_o178_7, 90, 0xB4E6AB38);

// @0x141a390c0
void UIMinimapDialog::vfunc_o178_5(void* p)
{
    if (vfunc_55())
        return;
    if (p != 0 && static_cast<bool>(static_cast<CQuest*>(p)->vfunc_0().get()))
        FUN_141a3ada0();
}
MS2_REPLACE_METHOD_VIA(0x141a390c0, UIMinimapDialog, UIQuestEventListener, vfunc_o178_5, 294, 0x33501AE3);

MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& v);   // the child clip of a value
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);                 // the value is an object

// @0x141a391f0
void UIMinimapDialog::FUN_141a391f0(MS2Ptr<CInteractObject> spObject)
{
    if (FUN_1418fd2f0())
        return;
    EntityPtr spEntity(0);
    if (m_named.Lookup(spObject->FUN_140967060(), spEntity)) {
        if (spEntity == 0)
            return;
        CString strIcon = spEntity->m_icon;
        FUN_141a44380(spObject, spEntity);
        if (strIcon != spEntity->m_icon) {
            if (spEntity->m_icon.IsEmpty()) {
                spEntity->m_visible = false;
                spEntity->m_clip->vfunc_4(false);
            } else {
                if (!strIcon.IsEmpty()) {
                    ASObj data(2);
                    spEntity->FUN_141a31270(data, m_viewport);
                    Scaleform::GFx::Value value = m_30->Invoke("changeEntityData", spEntity->m_clip->FUN_1422bb870(), data.FUN_1422bb870());
                    if (!FUN_1409b4d40(value))
                        return;
                    spEntity->m_clip = FUN_1409b40c0(m_28, value);
                }
                spEntity->m_clip->vfunc_4(spEntity->m_visible);
            }
            if (spEntity->m_64)
                m_212 = true;
        } else {
            spEntity->m_clip->vfunc_4(spEntity->m_visible);
        }
    } else {
        FUN_141a39770(spObject);
    }
}
MS2_REPLACE_METHOD(0x141a391f0, UIMinimapDialog, FUN_141a391f0, 1396, 0xED7D2B0A);

// @0x141a39770
void UIMinimapDialog::FUN_141a39770(MS2Ptr<CInteractObject> spObject)
{
    if (FUN_1418fd2f0())
        return;
    if (m_30 == 0)
        return;
    if (spObject == 0 || spObject->FUN_140966e00() == 0)
        return;
    bool bQuestObject = CQuestNavigator::GetInstance()->HasNpc(spObject->FUN_140967110()) == 1;
    if (spObject->FUN_140966e00()->m_display.m_strMinimapIcon.IsEmpty() && !bQuestObject)
        return;
    NamedMap::CPair* pPair = m_named.Lookup(spObject->FUN_140967060());
    if (pPair != 0)
        return;
    EntityPtr spEntity = new UIMinimapEntity(6);
    FUN_141a44380(spObject, spEntity);
    if (FUN_141a3e7d0(spEntity))
        m_named.SetAt(spObject->FUN_140967060(), spEntity);
    if (spEntity->m_64)
        m_212 = true;
}
MS2_REPLACE_METHOD(0x141a39770, UIMinimapDialog, FUN_141a39770, 1141, 0x13204261);

// @0x141a39bf0
void UIMinimapDialog::FUN_141a39bf0(MS2Ptr<CInteractObject> spObject)
{
    if (FUN_1418fd2f0())
        return;
    EntityPtr spEntity;
    if (m_named.Lookup(spObject->FUN_140967060(), spEntity)) {
        FUN_141a3f930(spEntity);
        m_named.RemoveKey(spObject->FUN_140967060());
    }
}
MS2_REPLACE_METHOD(0x141a39bf0, UIMinimapDialog, FUN_141a39bf0, 325, 0xD354B6EA);

// @0x141a39d40
void UIMinimapDialog::FUN_141a39d40(int nId, int bVisible)
{
    if (FUN_1418fd2f0())
        return;
    EntityPtr spEntity(0);
    if (m_triggers.Lookup(nId, spEntity) && static_cast<bool>(static_cast<UIMinimapEntity*>(spEntity))) {
        if (static_cast<bool>(spEntity->m_clip.get()))
            spEntity->m_clip->vfunc_3(bVisible);
    }
}
MS2_REPLACE_METHOD(0x141a39d40, UIMinimapDialog, FUN_141a39d40, 240, 0x68BE3E46);

// @0x141a39e40
void UIMinimapDialog::FUN_141a39e40()
{
    FUN_1418fd2f0();
}
MS2_REPLACE_METHOD(0x141a39e40, UIMinimapDialog, FUN_141a39e40, 19, 0x7CB65D04);

extern Unk_StreamPoint DAT_143b01a60;                               // the zero point
CBuddyManager* FUN_14097a780();                                    // TSingleton<CBuddyManager>::GetInstance
void FUN_1409618c0(egf::Entity* pEntity, unsigned nProperty, Unk_StreamPoint* pOut);   // reads a point property

// @0x141a39e60
void UIMinimapDialog::FUN_141a39e60()
{
    int nField = FUN_1403ed2d0()->FUN_141bd3060();
    if (!FUN_1409f24a0()->FUN_14085f730(nField))
        return;
    bool bDisabled = false;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0 || pPC->FUN_140967010()->FUN_14050da30() == 0)
        bDisabled = true;
    Unk_MmEntityList list = FUN_1403ed2d0()->FUN_141bd0420(0x85359406);
    if (static_cast<bool>(list.FUN_1409f2170()) && !list.FUN_1409f2190()->IsEmpty()) {
        efd::SmartPointer<egf::Entity> spObject = list.FUN_1409f2190()->GetAt(list.FUN_1409f2190()->GetHeadPosition());
        if (spObject) {
            if (bDisabled) {
                FUN_141a3f930(m_taxi);
                m_taxi = 0;
            } else if (m_taxi == 0 || m_taxi->m_clip == 0) {
                Unk_StreamPoint kPos = DAT_143b01a60;
                FUN_1409618c0(spObject.operator->(), 0xfd95ca52, &kPos);
                EntityPtr spEntity = new UIMinimapEntityTaxi(reinterpret_cast<const efd::Point3&>(kPos));
                if (FUN_141a3e7d0(spEntity))
                    m_taxi = spEntity;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141a39e60, UIMinimapDialog, FUN_141a39e60, 908, 0xF9B39C94);

// @0x141a3a200
void UIMinimapDialog::FUN_141a3a200()
{
    if (m_30 == 0)
        return;
    if (m_taxi == 0 || m_taxi->m_clip == 0)
        return;
    MS2Ptr<UIMinimapEntityTaxi> spTaxi = dynamic_cast<UIMinimapEntityTaxi*>(static_cast<UIMinimapEntity*>(m_taxi));
    if (spTaxi == 0)
        return;
    bool bBest = false;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
        bBest = FUN_141b71c00((unsigned short)pPC->vfunc_78()) == 1;
    spTaxi->m_text = bBest ? FUN_14028b8e0(L"s_word_besttaxistation") : FUN_14028b8e0(L"s_word_taxistation");
    spTaxi->m_icon = bBest ? s_strTaxiBest : s_strTaxi;
    spTaxi->FUN_141a34870(bBest);
    ASObj data(2);
    data.FUN_1407cbb20(s_strName, spTaxi->m_text);
    data.FUN_1407cba60(s_strMcName, spTaxi->m_icon);
    Scaleform::GFx::Value value = m_30->Invoke("changeEntityData", spTaxi->m_clip->FUN_1422bb870(), data.FUN_1422bb870());
    if (FUN_1409b4d40(value))
        spTaxi->m_clip = FUN_1409b40c0(m_28, value);
}

// The minimap's root AS object with the Invoke overloads only this unit instantiates.
class Unk_MmScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_141a46a60(const char* szMethod, Scaleform::GFx::Value a1, const char* a2);
    Scaleform::GFx::Value FUN_141a46b60(const char* szMethod, Scaleform::GFx::Value a1, CString a2);
    Scaleform::GFx::Value FUN_141a468e0(const char* szMethod, Scaleform::GFx::Value a1, int a2, CStringW a3, CStringW a4);
};
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// @0x141a468e0
inline Scaleform::GFx::Value Unk_MmScript::FUN_141a468e0(const char* szMethod, Scaleform::GFx::Value a1, int a2, CStringW a3, CStringW a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141a46a60
inline Scaleform::GFx::Value Unk_MmScript::FUN_141a46a60(const char* szMethod, Scaleform::GFx::Value a1, const char* a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141a46b60
inline Scaleform::GFx::Value Unk_MmScript::FUN_141a46b60(const char* szMethod, Scaleform::GFx::Value a1, CString a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141a3a780
void UIMinimapDialog::FUN_141a3a780(int n)
{
    if (FUN_1418fd2f0())
        return;
    if (m_30 == 0 || m_taxi == 0)
        return;
    static_cast<Unk_MmScript*>(m_30.operator->())->FUN_141a46a60("changeEntityFrame", m_taxi->m_clip->FUN_1422bb870(), "enabled");
}
MS2_REPLACE_METHOD(0x141a3a780, UIMinimapDialog, FUN_141a3a780, 260, 0xD00E0BB7);

// @0x141a3a890
void UIMinimapDialog::FUN_141a3a890()
{
    if (FUN_1418fd2f0())
        return;
    if (m_30 == 0 || m_telescope == 0)
        return;
    static_cast<Unk_MmScript*>(m_30.operator->())->FUN_141a46a60("changeEntityFrame", m_telescope->m_clip->FUN_1422bb870(), "enabled");
}
MS2_REPLACE_METHOD(0x141a3a890, UIMinimapDialog, FUN_141a3a890, 256, 0x45FFD4DF);

// @0x141a3a9a0
void UIMinimapDialog::FUN_141a3a9a0(bool bRemove)
{
    if (m_30 == 0)
        return;
    if (static_cast<UIMinimapEntity*>(m_return) != 0) {
        bool bShouldRemove = bRemove;
        if (!bRemove) {
            bShouldRemove = true;
            MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPC != 0) {
                efd::Point3 kPos = efd::Point3::ZERO;
                if (pPC->FUN_141528020(kPos)) {
                    if (static_cast<ASMovieClip*>(m_return->m_clip) != 0) {
                        FUN_141a44730(kPos, m_return->m_clip);
                        bShouldRemove = false;
                    }
                }
            }
        }
        if (bShouldRemove) {
            m_30->Invoke("removeEntity", m_return->m_clip->FUN_1422bb870());
            m_return = 0;
        }
    } else if (!bRemove) {
        FUN_141a3dda0();
    }
}
MS2_REPLACE_METHOD(0x141a3a9a0, UIMinimapDialog, FUN_141a3a9a0, 539, 0xFC7D3984);

// @0x141a3abd0
void UIMinimapDialog::FUN_141a3abd0()
{
    if (m_30 == 0)
        return;
    if (!m_1fa)
        return;
    m_30->Invoke("onTabKeyUp");
    m_1fa = false;
    FUN_1422dc260(m_2c);
    FUN_140b632f0()->FUN_1422d4840(this, 3);
    FUN_140b632f0()->FUN_1422d4780(this, m_e0);
}
MS2_REPLACE_METHOD(0x141a3abd0, UIMinimapDialog, FUN_141a3abd0, 197, 0x23AC8E23);

// @0x141a3aca0
void UIMinimapDialog::FUN_141a3aca0()
{
    if (m_30 == 0)
        return;
    if (m_forceMinimize)
        return;
    if (!m_1fc)
        return;
    m_30->Invoke("onTabKeyDown");
    m_1fa = true;
    FUN_1422dc260(0x1a);
    FUN_140b632f0()->FUN_1422d4840(this, m_e0);
    FUN_140b632f0()->FUN_1422d4780(this, 3);
}
MS2_REPLACE_METHOD(0x141a3aca0, UIMinimapDialog, FUN_141a3aca0, 215, 0x1D15CA91);

// @0x141a3ad80
void UIMinimapDialog::FUN_141a3ad80(bool b)
{
    m_1fb = b;
}
MS2_REPLACE_METHOD(0x141a3ad80, UIMinimapDialog, FUN_141a3ad80, 26, 0x8AB8E1D5);

// @0x141a3ada0
void UIMinimapDialog::FUN_141a3ada0()
{
    m_210 = true;
    m_211 = true;
    m_212 = true;
}
MS2_REPLACE_METHOD(0x141a3ada0, UIMinimapDialog, FUN_141a3ada0, 42, 0xE470E7BA);

struct Unk_MmQuestIconOptions                                       // the quest icon filter options
{
    char m_pad_00[0x20];
    bool m_epic;                                                    // +0x20
    bool m_world;                                                   // +0x21
    bool m_repeat;                                                  // +0x22
};
Unk_MmQuestIconOptions* FUN_140c9b8b0(void* pOptions);

// @0x141a3add0
void UIMinimapDialog::FUN_141a3add0()
{
    if (m_maxPanel == 0)
        return;
    Unk_MmQuestIconOptions* pOptions = FUN_140c9b8b0(FUN_1409a8b10());
    if (pOptions == 0)
        return;
    ASArray icons(2);
    {
        ASObj epic(2);
        epic.FUN_1407cba60("layer", s_strLayerQuestEpic);
        epic.FUN_1407cbbe0("check", pOptions->m_epic);
        icons.FUN_1422bc050(epic.FUN_1422bb870());
        ASObj world(2);
        world.FUN_1407cba60("layer", s_strLayerQuestWorld);
        world.FUN_1407cbbe0("check", pOptions->m_world);
        icons.FUN_1422bc050(world.FUN_1422bb870());
        ASObj repeat(2);
        repeat.FUN_1407cba60("layer", s_strLayerQuestRepeat);
        repeat.FUN_1407cbbe0("check", pOptions->m_repeat);
        icons.FUN_1422bc050(repeat.FUN_1422bb870());
    }
    m_maxPanel->Invoke("checkIcons", icons.FUN_1422bb870());
    m_210 = true;
}

// @0x141a3b130
void UIMinimapDialog::FUN_141a3b130(unsigned __int64 nId, int nColor, const efd::Point3& kPos)
{
    if (FUN_141a45ce0()) {
        EntityPtr spEntity(0);
        if (m_pings.Lookup(nId, spEntity)) {
            FUN_141a3b390(nId, nColor, spEntity, kPos);
        } else {
            spEntity.AssignRaw(new UIMinimapEntityPing(kPos));
            if (FUN_141a3e7d0(spEntity)) {
                m_30->Invoke("onTabKeyDown");
                m_30->Invoke("onTabKeyUp");
                m_pings.SetAt(nId, spEntity);
                FUN_141a3b390(nId, nColor, spEntity, kPos);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141a3b130, UIMinimapDialog, FUN_141a3b130, 599, 0x9F70BD80);

// @0x141a3b390
void UIMinimapDialog::FUN_141a3b390(unsigned __int64 nId, int nColor, EntityPtr spEntity, const efd::Point3& kPos)
{
    if (spEntity == 0)
        return;
    MS2Ptr<UIMinimapEntityPing> spPing = dynamic_cast<UIMinimapEntityPing*>(static_cast<UIMinimapEntity*>(spEntity));
    if (spPing == 0)
        return;
    spPing->FUN_141a35000(nId, nColor, kPos, FUN_141a45d50(nId));
}

// @0x141a3b4d0
void UIMinimapDialog::FUN_141a3b4d0(unsigned int& nQuest, unsigned __int64& nId)
{
    nQuest = m_468;
    nId = m_460;
}
MS2_REPLACE_METHOD(0x141a3b4d0, UIMinimapDialog, FUN_141a3b4d0, 54, 0x63DECFAD);

// @0x141a3b510
UIMinimapDialog::EntityPtr UIMinimapDialog::FUN_141a3b510(ProxyPtr spProxy)
{
    if (m_30 == 0)
        return EntityPtr(0);
    if (spProxy == 0)
        return EntityPtr(0);
    EntityPtr spEntity(0);
    if (m_proxies.Lookup(spProxy, spEntity))
        return spEntity;
    return EntityPtr(0);
}

// @0x141a3b660
UIMinimapDialog::HomeListPtr UIMinimapDialog::FUN_141a3b660(const int& nField)
{
    HomeListPtr spHomes(0);
    m_homes.Lookup(nField, spHomes);
    return spHomes;
}
MS2_REPLACE_METHOD(0x141a3b660, UIMinimapDialog, FUN_141a3b660, 126, 0x41232F01);

// @0x141a3b6f0
void UIMinimapDialog::FUN_141a3b6f0()
{
    if (m_showAttrs.IsEmpty()) {
        m_showAttrs.SetAt(s_strLayerShop, new TShowAttr(1, 0, L"$s_minimap_shop"));
        m_showAttrs.SetAt(s_strLayerFriendly, new TShowAttr(0, 1, L"$s_minimap_friendly_npc"));
        if (FUN_140166410()->FUN_14036d570(0x8d))
            m_showAttrs.SetAt(s_strLayerTamingPet, new TShowAttr(1, 2, L"$s_minimap_taming_pet"));
        m_showAttrs.SetAt(s_strLayerPortal, new TShowAttr(1, 3, L"$s_minimap_portal"));
        m_showAttrs.SetAt(s_strLayerBuddy, new TShowAttr(1, 4, L"$s_minimap_buddy"));
        m_showAttrs.SetAt(s_strLayerPc, new TShowAttr(1, 5, L"$s_minimap_other_pc"));
        m_showAttrs.SetAt(s_strLayerText, new TShowAttr(1, 6, L"$s_minimap_text"));
    }
}

CString FUN_141028be0(__int64 nCharId, const CString& strKey, int nFlag, CString strEmpty);   // the profile image key

// @0x141a3bda0
bool UIMinimapDialog::FUN_141a3bda0(ASObj& data, ProxyPtr spProxy)
{
    if (spProxy == 0)
        return false;
    CString strPath = FUN_141028be0(spProxy->FUN_1416c22f0(), spProxy->FUN_1416c2520(), 1, CString(""));
    CString strId = FUN_140719530(spProxy->FUN_1416c22f0());
    data.FUN_1407cba60("imgpath", strPath);
    data.FUN_1407cba60("charid", strId);
    CStringW strText = FUN_1408f71a0(L"s_tooltip_todayword", spProxy->FUN_1416c23b0(), spProxy->FUN_1416c2570());
    ASObj tooltip(2);
    tooltip.FUN_1409c0dc0("className", "export_common_tooltip_tooltipText");
    tooltip.FUN_1407cbb20("text", strText);
    tooltip.FUN_1409c0dc0("align", "bottomLeft");
    tooltip.FUN_1407cb9c0("onDelay", 300);
    tooltip.FUN_1407cb9c0("offDelay", 60000);
    data.FUN_1409eb270("tooltipData", tooltip);
    return true;
}
MS2_REPLACE_METHOD(0x141a3bda0, UIMinimapDialog, FUN_141a3bda0, 936, 0xFC9D3AA0);

// @0x141a44e60
void UIMinimapDialog::FUN_141a44e60()
{
    FUN_141a3abd0();
    if (m_30.get() != 0)
        m_30->Invoke("changeStageSize");
}
MS2_REPLACE_METHOD(0x141a44e60, UIMinimapDialog, FUN_141a44e60, 93, 0xF5D0C6CA);

// @0x141a44ed0
void UIMinimapDialog::FUN_141a44ed0()
{
    if (m_30.get() != 0)
        m_30->FUN_1409ba030("setSelectedChannel", m_channel);
}
MS2_REPLACE_METHOD(0x141a44ed0, UIMinimapDialog, FUN_141a44ed0, 95, 0x88554227);

// @0x141a44f40
void UIMinimapDialog::FUN_141a44f40()
{
    if (m_30 == 0)
        return;
    if (m_alignment == 0)
        return;
    int nWidth = 0;
    int nHeight = 0;
    FUN_141a45ad0(nWidth, nHeight);
    m_alignment->FUN_141901c10(m_30, nWidth, nHeight);
}
MS2_REPLACE_METHOD(0x141a44f40, UIMinimapDialog, FUN_141a44f40, 210, 0x473BA9B2);

template <> MS2Ptr<Unk_RideeData>::~MS2Ptr();                                           // 0x140788ed0 (ridee.cpp)
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::operator->() const;                   // 0x1407895d0

// The ridden mount of an actor, held while it is read.
class Unk_MmRideeRef
{
public:
    Unk_MmRideeRef(Ridee* p);
    ~Unk_MmRideeRef();                                              // 0x1409648b0
    Ridee* FUN_140965790() const;                                   // get
    Ridee* FUN_140975bc0() const;                                   // operator->
private:
    Ridee* m_p;
};

// @0x141a422c0
void UIMinimapDialog::FUN_141a422c0(ProxyPtr spProxy, EntityPtr spEntity)
{
    if (m_30 == 0)
        return;
    if (spProxy == 0 || !spProxy->FUN_1416c21c0())
        return;
    if (spEntity == 0 || spEntity->m_clip == 0)
        return;
    FUN_141a43ac0(spProxy, spEntity);
    if (spEntity->m_visible) {
        if (!FUN_141a44730(spProxy->FUN_1416c2270(), spEntity->m_clip))
            spEntity->m_visible = false;
    }
    if (!spEntity->m_64)
        spEntity->m_clip->vfunc_4(spEntity->m_visible);
}

// @0x141a42600
void UIMinimapDialog::FUN_141a42600(MS2Ptr<CInteractObject> spObject, EntityPtr spEntity)
{
    if (m_30 == 0 || spObject == 0)
        return;
    if (spEntity == 0 || spEntity->m_clip == 0)
        return;
    CString strState = spObject->FUN_1413b5600() == 0 ? "enabled" : "disabled";
    static_cast<Unk_MmScript*>(m_30.operator->())->FUN_141a46b60("changeEntityFrame", spEntity->m_clip->FUN_1422bb870(), strState);
}

// @0x141a42550
void UIMinimapDialog::FUN_141a42550()
{
    ATL::CAtlArray<MS2Ptr<CInteractObject> > objects;
    FUN_1403ed2d0()->FUN_141bc5f10(objects);
    for (size_t i = 0; i < objects.GetCount(); ++i)
        FUN_141a391f0(objects[i]);
}
MS2_REPLACE_METHOD(0x141a42550, UIMinimapDialog, FUN_141a42550, 166, 0x38F4D24D);

extern int DAT_143ab0248;                                           // client country (2: no channel group)
int FUN_14092f640();                                                // the current channel

// @0x141a42800
void UIMinimapDialog::FUN_141a42800()
{
    if (m_30 == 0)
        return;
    CStringW strGroup;
    if (DAT_143ab0248 != 2)
        strGroup = FUN_1401a9d70()->FUN_141811980(0x17, FUN_1403ed2d0()->FUN_141bd98f0());
    m_channel = FUN_14092f640();
    int nSelected = 0;
    ASArray channels(2);
    UIServerListDialog* pServerList = Unk_MmGetDialog<UIServerListDialog>();
    if (pServerList != 0)
        pServerList->FUN_141ad2f60(channels, &nSelected, m_channel);
    static_cast<Unk_MmScript*>(m_30.operator->())->FUN_141a468e0("buildChannelList", channels.FUN_1422bb870(), nSelected, FUN_14028b8e0(L"s_word_ch"), strGroup);
}
MS2_REPLACE_METHOD(0x141a42800, UIMinimapDialog, FUN_141a42800, 616, 0x8585C70C);

float FUN_141adbe70(void* pService);                               // the ui scale

// @0x141a42bb0
void UIMinimapDialog::FUN_141a42bb0()
{
    if (m_30 == 0)
        return;
    if (!m_212)
        return;
    if (m_maxPanel == 0)
        return;
    double dPanelX = 0.0;
    double dPanelY = 0.0;
    if (!m_maxPanel->FUN_1422c2510(&dPanelX, &dPanelY))
        return;
    float fScale = FUN_141adbe70(FUN_1403ed2b0());
    dPanelX /= fScale;
    dPanelY /= fScale;
    m_212 = false;
    ATL::CAtlMap<unsigned __int64, int> occupied;
    int nCell = *FUN_1401d3200()->m_minimapCell.FUN_1401d7c10();
    ATL::CAtlArray<EntityPtr> entities;
    FUN_141a42fe0(entities);
    for (size_t i = 0; i < entities.GetCount(); ++i) {
        EntityPtr spEntity = entities[i];
        if (spEntity == 0)
            continue;
        NiPoint3 kOut;
        NiPoint3 kWorld(spEntity->m_position);
        if (m_viewport->FUN_141486410(kWorld, kOut)) {
            double dX = 0.0;
            double dY = 0.0;
            if (!spEntity->m_clip->FUN_1422c2510(&dX, &dY))
                continue;
            dX /= fScale;
            dY /= fScale;
            double dOffX = dX - dPanelX;
            double dOffY = dY - dPanelY;
            int nCellX = static_cast<int>(dOffX / nCell);
            int nCellY = static_cast<int>(dOffY / nCell);
            unsigned __int64 nKey = (static_cast<__int64>(nCellX) << 32) | static_cast<__int64>(nCellY);
            if (occupied.Lookup(nKey) != 0) {
                spEntity->m_visible = false;
            } else {
                occupied.SetAt(nKey, 1);
                spEntity->m_visible = true;
            }
            spEntity->m_clip->vfunc_4(spEntity->m_visible);
        }
    }
}
MS2_REPLACE_METHOD(0x141a42bb0, UIMinimapDialog, FUN_141a42bb0, 1058, 0xAC337C95);

// @0x141a42fe0
void UIMinimapDialog::FUN_141a42fe0(ATL::CAtlArray<EntityPtr>& entities)
{
    for (POSITION pos = m_proxies.GetHeadPosition(); pos != 0; m_proxies.GetNext(pos)) {
        EntityPtr spEntity = m_proxies.GetValueAt(pos);
        if (static_cast<bool>(static_cast<UIMinimapEntity*>(spEntity)) && spEntity->m_64)
            entities.Add(m_proxies.GetValueAt(pos));
    }
    for (POSITION pos = m_named.GetStartPosition(); pos != 0; m_named.GetNext(pos)) {
        CString strKey = m_named.GetKeyAt(pos);
        EntityPtr spEntity = m_named.GetValueAt(pos);
        if (static_cast<bool>(static_cast<UIMinimapEntity*>(spEntity)) && spEntity->m_64) {
            MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(strKey);
            if (spObject == 0)
                continue;
            if (spObject->FUN_1413b5600() != 1)
                continue;
            entities.Add(m_named.GetValueAt(pos));
        }
    }
}
MS2_REPLACE_METHOD(0x141a42fe0, UIMinimapDialog, FUN_141a42fe0, 693, 0xCC18C194);

// @0x141a42a70
void UIMinimapDialog::FUN_141a42a70()
{
    if (m_30 == 0)
        return;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    bool bVisible = true;
    Unk_MmRideeRef spRidee(pPC->FUN_1416764a0());
    if (spRidee.FUN_140965790()) {
        if (spRidee.FUN_140975bc0()->FUN_141707750()->m_nSeats != 0)
            bVisible = false;
    }
    m_30->Invoke("visiblePlayers", bVisible);
}
MS2_REPLACE_METHOD(0x141a42a70, UIMinimapDialog, FUN_141a42a70, 310, 0xA88A9455);

// @0x141a43ac0
void UIMinimapDialog::FUN_141a43ac0(ProxyPtr spProxy, EntityPtr spEntity)
{
    spEntity->m_64 = false;
    spEntity->m_showGuide = false;
    spEntity->m_icon = s_strTamingPet;
    spEntity->m_state = s_strAlive;
    spEntity->m_layer = s_strLayerTamingPet;
    spEntity->m_visible = true;
}

// @0x141a44730
bool UIMinimapDialog::FUN_141a44730(const efd::Point3& kPos, MS2Ptr<ASMovieClip> spClip)
{
    if (spClip == 0)
        return false;
    NiPoint3 kOut;
    NiPoint3 kWorld(kPos);
    if (m_viewport->FUN_141486410(kWorld, kOut)) {
        spClip->vfunc_4(true);
        spClip->FUN_1422c00f0(kOut.x, kOut.y);
        return true;
    }
    return false;
}

// @0x141a454d0
// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (the new-list temporary shares a slot).
void UIMinimapDialog::FUN_141a454d0(const int& nField, const unsigned __int64& nHome)
{
    if (m_homes.IsEmpty())
        return;
    HomeListPtr spHomes(0);
    if (m_homes.Lookup(nField, spHomes)) {
        if (spHomes == 0)
            spHomes = HomeListPtr(Unk_GrNewTag(0));
        spHomes->AddTail(nHome);
        m_homes.SetAt(nField, spHomes);
    }
}
MS2_REPLACE_METHOD(0x141a454d0, UIMinimapDialog, FUN_141a454d0, 258, 0x35FA8FE3);

// @0x141a455e0
void UIMinimapDialog::FUN_141a455e0(const int& nField, const unsigned __int64& nHome)
{
    if (m_homes.IsEmpty())
        return;
    HomeListPtr spHomes(0);
    if (m_homes.Lookup(nField, spHomes) && spHomes.get() != 0) {
        POSITION pos = spHomes->Find(nHome);
        if (pos)
            spHomes->RemoveAt(pos);
    }
}
MS2_REPLACE_METHOD(0x141a455e0, UIMinimapDialog, FUN_141a455e0, 206, 0xFF96F73D);

class Unk_MmInput;                                                  // the input manager
Unk_MmInput* FUN_140aadf80();
int FUN_141b90e30(Unk_MmInput* pInput, float& x, float& y);         // the mouse position on the minimap

// @0x141a456c0
void UIMinimapDialog::FUN_141a456c0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    float x = 0;
    float y = 0;
    if (FUN_141b90e30(FUN_140aadf80(), x, y))
        FUN_141a45020(0, x, y);
}
MS2_REPLACE_METHOD(0x141a456c0, UIMinimapDialog, FUN_141a456c0, 88, 0x1BA9816C);

// @0x141a45720
void UIMinimapDialog::FUN_141a45720(const Scaleform::GFx::FunctionHandler::Params& params)
{
    float x = 0;
    float y = 0;
    if (FUN_141b90e30(FUN_140aadf80(), x, y))
        FUN_141a45020(1, x, y);
}
MS2_REPLACE_METHOD(0x141a45720, UIMinimapDialog, FUN_141a45720, 91, 0xCE3BFD94);

// @0x141a458d0
void UIMinimapDialog::FUN_141a458d0(bool b)
{
    vfunc_63(b != false);
}
MS2_REPLACE_METHOD(0x141a458d0, UIMinimapDialog, FUN_141a458d0, 68, 0xA6155441);

// @0x141a45ad0
bool UIMinimapDialog::FUN_141a45ad0(int& nWidth, int& nHeight)
{
    nWidth = 0;
    nHeight = 0;
    if (m_30.get() != 0) {
        static_cast<ASObj*>(m_30.operator->())->FUN_1422bae10("m_windowWidth", nWidth);
        static_cast<ASObj*>(m_30.operator->())->FUN_1422bae10("m_windowHeight", nHeight);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x141a45ad0, UIMinimapDialog, FUN_141a45ad0, 148, 0xC31D8C09);

// @0x141a45c70
bool UIMinimapDialog::FUN_141a45c70(const CString& strIcon)
{
    if (strIcon == s_strBoss || strIcon == s_strEliteBoss || strIcon == s_strEventBoss)
        return 1;
    return 0;
}


// @0x141a45ce0
bool UIMinimapDialog::FUN_141a45ce0()
{
    bool bAllow = FUN_1403ed2d0()->FUN_141bd30a0()->m_allowPing;
    if (bAllow)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x141a45ce0, UIMinimapDialog, FUN_141a45ce0, 102, 0x620E2CE5);

void FUN_140763210(int nId, int nKind, CStringW& strText, CStringW& strExtra, int n);   // the quest guide text

// @0x141a45ed0
// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (the trailing 0 argument is stored straight to the outgoing slot).
CStringW UIMinimapDialog::FUN_141a45ed0(const int& nId, int nKind)
{
    CStringW strText;
    CStringW strExtra;
    FUN_140763210(nId, nKind, strText, strExtra, 0);
    return strText;
}
MS2_REPLACE_METHOD(0x141a45ed0, UIMinimapDialog, FUN_141a45ed0, 151, 0xFEC1B993);

void FUN_14020af60(COutPacket* pPacket, const Unk_StreamPoint* pPt);    // writes the three floats of a point

// @0x141a45020
void UIMinimapDialog::FUN_141a45020(int nKind, float x, float y)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (m_30 == 0)
        return;
    if (!FUN_141a45ce0())
        return;
    NiPoint3 kPos(efd::Point3::ZERO);
    Scaleform::GFx::Value contains = m_30->Invoke("mouseContains");
    if (contains.IsBool() && FUN_1409c1720(contains) && FUN_141a451b0(true, x, y, kPos)) {
        COutPacket packet(0xb1, 0);
        packet.Encode8(pPC->FUN_141656a80());
        packet.Encode1((unsigned char)nKind);
        FUN_14020af60(&packet, reinterpret_cast<const Unk_StreamPoint*>(&kPos));
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x141a45020, UIMinimapDialog, FUN_141a45020, 392, 0xEB54C408);

// The popup menu (uipartydialog.h has the full class; this unit only needs its RTTI and one entry point).
class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p);   // 0x140c302f0
    ~Unk_PopupMenuInfo();                                           // 0x140c304c0
private:
    float m_x, m_y;                                                 // the members are opaque here (no array: /GS)
    int m_a, m_b, m_c;
    void* m_str;                                                    // +0x18 CString
    void* m_p;
    __int64 m_28, m_30, m_38, m_40, m_48;                           // +0x28 info A
    __int64 m_50, m_58, m_60, m_68, m_70, m_78;                     // +0x50 info B
};
MS2_CHECK_SIZE(Unk_PopupMenuInfo, 0x80);
class UIPopUpMenu : public UIDialog
{
public:
    static eUIClassID GetUIClassID() { return (eUIClassID)0x4e39; }   // 0x141a4b230
    void FUN_141a7eb60(const Unk_PopupMenuInfo& info, MS2Ptr<CProxyGameObject> spProxy, int nType);   // the menu of a player in the field
};

// @0x141a45790
void UIMinimapDialog::FUN_141a45790(float x, float y, unsigned __int64 nId)
{
    UIPopUpMenu* pMenu = Unk_MmGetDialog<UIPopUpMenu>();
    if (pMenu != 0) {
        ProxyPtr spProxy = FUN_1403ed2d0()->FUN_141bc9c60(nId);
        if (static_cast<CProxyGameObject*>(spProxy) != 0) {
            Unk_PopupMenuInfo info(x, y, 3, 0x3f3fe, 1, CString(""), 0);
            pMenu->FUN_141a7eb60(info, spProxy, 9);
        }
    }
}
MS2_REPLACE_METHOD(0x141a45790, UIMinimapDialog, FUN_141a45790, 310, 0x37E80969);

class Unk_MmActor                                                   // a field actor
{
public:
    int FUN_14123c660();                                            // hidden
};

// @0x141a45b70
bool UIMinimapDialog::FUN_141a45b70(ProxyPtr spProxy)
{
    if (spProxy == 0)
        return false;
    if (spProxy->FUN_1416c2b70()) {
        Unk_MmActor* pActor = FUN_1403ed2d0()->FUN_141bd1320(spProxy->m_proxyId);
        if (pActor != 0)
            return pActor->FUN_14123c660() == 0;
    }
    return spProxy->FUN_1416c2b30();
}

// @0x141a45d50
CStringW UIMinimapDialog::FUN_141a45d50(const unsigned __int64& nId)
{
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1530(nId);
    if (pActor)
        return pActor->vfunc_77();
    for (POSITION pos = m_proxies.GetHeadPosition(); pos; m_proxies.GetNext(pos)) {
        ProxyPtr spProxy = m_proxies.GetKeyAt(pos);
        if (static_cast<CProxyGameObject*>(spProxy) != 0 && spProxy->m_charId == nId)
            return spProxy->m_name;
    }
    return L"";
}
MS2_REPLACE_METHOD(0x141a45d50, UIMinimapDialog, FUN_141a45d50, 364, 0x1CEEB35C);

class Unk_MmCamera;                                                 // the field camera
Unk_MmCamera* FUN_1409478c0();
int FUN_140a18070(Unk_MmCamera* pCamera);                           // the camera is ready
bool FUN_140af0520(Unk_MmCamera* pCamera, const NiPoint2& kCursor, NiPoint3& kOrigin, NiPoint3& kDir);   // the pick ray
class Unk_MmSpatial;                                                // the field's collision space
Unk_MmSpatial* FUN_1409f7ca0();
int FUN_14168a230(Unk_MmSpatial* pSpatial, NiPoint3 kOrigin, NiPoint3& kHit, NiPoint3 kDir, float fRange, int nMask);   // ray cast

// @0x141a451b0
bool UIMinimapDialog::FUN_141a451b0(bool bLocal, float x, float y, NiPoint3& kOut)
{
    if (bLocal) {
        if (m_30 == 0)
            return false;
        Scaleform::GFx::Value local = m_30->Invoke("getLocal");
        if (FUN_1409b4d40(local)) {
            Scaleform::GFx::Value valueX;
            Scaleform::GFx::Value valueY;
            if (local.GetMember("x", &valueX))
                kOut.x = static_cast<float>(FUN_140f17ed0(valueX));
            if (local.GetMember("y", &valueY))
                kOut.y = static_cast<float>(FUN_140f17ed0(valueY));
            return true;
        }
    } else {
        NiPoint2 kCursor(x, y);
        if (FUN_141b90e30(FUN_140aadf80(), kCursor.x, kCursor.y)) {
            if (FUN_140a18070(FUN_1409478c0())) {
                NiPoint3 kOrigin(efd::Point3::ZERO);
                NiPoint3 kDir(efd::Point3::ZERO);
                if (FUN_140af0520(FUN_1409478c0(), kCursor, kOrigin, kDir)) {
                    NiPoint3 kHit(efd::Point3::ZERO);
                    if (FUN_14168a230(FUN_1409f7ca0(), NiPoint3(kOrigin), kHit, NiPoint3(kDir), 10000.0f, 0x201)) {
                        m_viewport->FUN_141486410(kHit, kOut);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x141a451b0, UIMinimapDialog, FUN_141a451b0, 787, 0x516BAE6F);

// @0x141a45920
float UIMinimapDialog::FUN_141a45920(PCBase* pPC)
{
    efd::Point3 kUp(0.0f, -1.0f, 0.0f);
    efd::Point3 kDir;
    efd::Point3 kSide;
    float fAngle = 0.0f;
    float fRot = 0.0f;
    Unk_MmRideeRef spRidee(pPC->FUN_1416764a0());
    if (spRidee.FUN_140965790()) {
        spRidee.FUN_140975bc0()->vfunc_67(&kDir, &kSide);
        fAngle = spRidee.FUN_140975bc0()->FUN_14166dad0(kUp, kSide);
        fRot = spRidee.FUN_140975bc0()->vfunc_20().z;
    } else {
        pPC->vfunc_67(&kDir, &kSide);
        fAngle = pPC->FUN_14166dad0(kUp, kSide);
        fRot = pPC->vfunc_20().z;
    }
    return fAngle - fRot + 90.0f;
}
MS2_REPLACE_METHOD(0x141a45920, UIMinimapDialog, FUN_141a45920, 425, 0x27EB4910);

// @0x141a3ced0
void UIMinimapDialog::FUN_141a3ced0()
{
    FUN_141a3f570();
    int nField = FUN_1403ed2d0()->FUN_141bd3060();
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(nField);
    if (static_cast<bool>(spField.get())) {
        if (static_cast<bool>(spField->m_spMinimap.get())) {
            Scaleform::GFx::Value value = m_30->FUN_140e6b140("createFieldEntity", 0, spField->m_spMinimap->m_strImageName);
            if (FUN_1409b4d40(value))
                m_clip228 = FUN_1409b40c0(m_28, value);
        }
    }
}
MS2_REPLACE_METHOD(0x141a3ced0, UIMinimapDialog, FUN_141a3ced0, 426, 0x8DA94486);

// @0x141a3dbb0
void UIMinimapDialog::FUN_141a3dbb0()
{
    Unk_MmEntityList list = FUN_1403ed2d0()->FUN_141bd0420(0x85359406);
    if (static_cast<bool>(list.FUN_1409f2170()) && !list.FUN_1409f2190()->IsEmpty()) {
        efd::SmartPointer<egf::Entity> spObject = list.FUN_1409f2190()->GetAt(list.FUN_1409f2190()->GetHeadPosition());
        if (spObject) {
            Unk_StreamPoint kPos = DAT_143b01a60;
            FUN_1409618c0(spObject.operator->(), 0xfd95ca52, &kPos);
            EntityPtr spEntity = new UIMinimapEntityTaxi(reinterpret_cast<const efd::Point3&>(kPos));
            if (FUN_141a3e7d0(spEntity))
                m_taxi = spEntity;
        }
    }
}
MS2_REPLACE_METHOD(0x141a3dbb0, UIMinimapDialog, FUN_141a3dbb0, 475, 0x65BF49F1);

// @0x141a3dda0
void UIMinimapDialog::FUN_141a3dda0()
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0) {
        efd::Point3 kPos = efd::Point3::ZERO;
        if (pPC->FUN_141528020(kPos)) {
            EntityPtr spEntity = new UIMinimapEntity(4);
            spEntity->m_icon = s_strMyHome;
            spEntity->m_layer = s_strLayerMyHome;
            spEntity->m_position = kPos;
            spEntity->m_visible = true;
            if (FUN_141a3e7d0(spEntity))
                m_return = spEntity;
        }
    }
}

// @0x141a3e2d0
void UIMinimapDialog::FUN_141a3e2d0(Unk_BuddyPtr<CBuddy> spBuddy)
{
    if (spBuddy == 0 || !spBuddy->FUN_1401cc5f0())
        return;
    Unk_StreamPoint kPos = DAT_143b01a60;
    if (spBuddy->FUN_1401cc400(&kPos)) {
        EntityPtr spEntity = new UIMinimapEntityBuddyHome(spBuddy);
        spEntity->m_icon = s_strFriendHome;
        spEntity->m_layer = s_strLayerHome;
        spEntity->m_position = reinterpret_cast<const efd::Point3&>(kPos);
        spEntity->m_visible = true;
        if (FUN_141a3e7d0(spEntity))
            m_buddies.SetAt(spBuddy->FUN_1401cc2f0(), spEntity);
    }
}

// @0x141a3ed50
void UIMinimapDialog::FUN_141a3ed50()
{
    ATL::CAtlArray<Unk_BuddyPtr<CBuddy> > buddies;
    FUN_14097a780()->FUN_140ae4df0(buddies);
    int nCurrent = FUN_1403ed2d0()->FUN_141bd3060();
    size_t nCount = buddies.GetCount();
    for (size_t i = 0; i < nCount; ++i) {
        Unk_BuddyPtr<CBuddy> spBuddy = buddies[i];
        if (spBuddy == 0 || !spBuddy->FUN_1401cc5f0())
            continue;
        int nField = spBuddy->FUN_1401cc3e0();
        if (static_cast<unsigned int>(nField) > 0) {
            unsigned __int64 nHome = spBuddy->FUN_1401cc2f0();
            FUN_141a454d0(nField, nHome);
            if (nField == nCurrent)
                FUN_141a3e2d0(spBuddy);
        }
    }
}
MS2_REPLACE_METHOD(0x141a3ed50, UIMinimapDialog, FUN_141a3ed50, 377, 0x077301A2);

void FUN_1408a2020(egf::Entity* pEntity, unsigned nProperty, int* pOut);   // reads an int property
MS2Ptr<CInteractObjectData> FUN_14051f670(int nId);                  // the interact table row
int FUN_1402bacf0(ATL::CAtlArray<int>& arr, const int& value);       // index of the value or -1
extern ATL::CAtlArray<int> DAT_143ab3128;                            // the telescopes the player has used
CStringW FUN_14028de60(int nStringId);                               // a common string by id

// @0x141a3df40
void UIMinimapDialog::FUN_141a3df40()
{
    Unk_MmEntityList list = FUN_1403ed2d0()->FUN_141bd0420(0x62f7a42c);
    if (static_cast<bool>(list.FUN_1409f2170()) && !list.FUN_1409f2190()->IsEmpty()) {
        for (POSITION pos = list.FUN_1409f2190()->GetHeadPosition(); pos != 0; list.FUN_1409f2190()->GetNext(pos)) {
            efd::SmartPointer<egf::Entity> spObject = list.FUN_1409f2190()->GetAt(pos);
            Unk_StreamPoint kPos;
            int nId = 0;
            FUN_1409618c0(spObject.operator->(), 0xfd95ca52, &kPos);
            FUN_1408a2020(spObject.operator->(), 0xd460e9bc, &nId);
            MS2Ptr<CInteractObjectData> spData = FUN_14051f670(nId);
            if (static_cast<bool>(spData.get()) && spData->m_reward.m_firstExp.m_eType != 3)
                continue;
            EntityPtr spEntity = new UIMinimapEntity(3);
            spEntity->m_icon = "telescope";
            spEntity->m_layer = s_strLayerTelescope;
            spEntity->m_position = reinterpret_cast<const efd::Point3&>(kPos);
            spEntity->m_visible = true;
            spEntity->m_state = FUN_1402bacf0(DAT_143ab3128, nId) != -1 ? "enabled" : "disabled";
            spEntity->m_text = FUN_14028de60(0x59b);
            if (FUN_141a3e7d0(spEntity))
                m_telescope = spEntity;
        }
    }
}
MS2_REPLACE_METHOD(0x141a3df40, UIMinimapDialog, FUN_141a3df40, 906, 0x6C5FA91F);

void FUN_1408a20a0(egf::Entity* pEntity, unsigned nProperty, bool* pOut);  // reads a bool property

// @0x141a3e4e0
void UIMinimapDialog::FUN_141a3e4e0(efd::SmartPointer<egf::Entity> spEntity)
{
    if (spEntity == 0)
        return;
    efd::utf8string strIcon;
    spEntity->GetPropertyValue(0x6814a50e, strIcon);
    if (strIcon.length() == 0)
        return;
    Unk_StreamPoint kPos = DAT_143b01a60;
    int nId = 0;
    bool bVisible = false;
    FUN_1409618c0(spEntity.operator->(), 0xfd95ca52, &kPos);
    FUN_1408a2020(spEntity.operator->(), 0x6c37a861, &nId);
    FUN_1408a20a0(spEntity.operator->(), 0xa0b6b179, &bVisible);
    EntityPtr spMinimap = new UIMinimapEntity(7);
    spMinimap->m_icon = "triggerobject";
    spMinimap->m_layer = s_strLayerTriggerObject;
    spMinimap->m_position = reinterpret_cast<const efd::Point3&>(kPos);
    spMinimap->m_visible = bVisible;
    spMinimap->m_state = strIcon.c_str();
    spMinimap->m_text = L"";
    if (FUN_141a3e7d0(spMinimap))
        m_triggers.SetAt(nId, spMinimap);
}

// @0x141a3ef80
void UIMinimapDialog::FUN_141a3ef80()
{
    Unk_MmEntityList first = FUN_1403ed2d0()->FUN_141bd0420(0x74b363a7);
    if (static_cast<bool>(first.FUN_1409f2170()) && !first.FUN_1409f2190()->IsEmpty()) {
        for (POSITION pos = first.FUN_1409f2190()->GetHeadPosition(); pos != 0; first.FUN_1409f2190()->GetNext(pos)) {
            efd::SmartPointer<egf::Entity> spObject = first.FUN_1409f2190()->GetAt(pos);
            FUN_141a3e4e0(spObject);
        }
    }
    Unk_MmEntityList second = FUN_1403ed2d0()->FUN_141bd0420(0x4714f9ea);
    if (static_cast<bool>(second.FUN_1409f2170()) && !second.FUN_1409f2190()->IsEmpty()) {
        for (POSITION pos = second.FUN_1409f2190()->GetHeadPosition(); pos != 0; second.FUN_1409f2190()->GetNext(pos)) {
            efd::SmartPointer<egf::Entity> spObject = second.FUN_1409f2190()->GetAt(pos);
            FUN_141a3e4e0(spObject);
        }
    }
}
MS2_REPLACE_METHOD(0x141a3ef80, UIMinimapDialog, FUN_141a3ef80, 567, 0xD23B9533);

void FUN_1401d3700(CString& str);                                    // normalises the symbol name

// @0x141a3f1c0
void UIMinimapDialog::FUN_141a3f1c0()
{
    Unk_MmEntityList list = FUN_1403ed2d0()->FUN_141bd0420(0x6fb4d420);
    if (static_cast<bool>(list.FUN_1409f2170()) && !list.FUN_1409f2190()->IsEmpty()) {
        int nId = 0;
        for (POSITION pos = list.FUN_1409f2190()->GetHeadPosition(); pos != 0; list.FUN_1409f2190()->GetNext(pos)) {
            efd::SmartPointer<egf::Entity> spObject = list.FUN_1409f2190()->GetAt(pos);
            if (spObject == 0)
                continue;
            Unk_StreamPoint kPos = DAT_143b01a60;
            efd::utf8string strIcon;
            efd::utf8string strUnused;
            FUN_1409618c0(spObject.operator->(), 0xfd95ca52, &kPos);
            spObject->GetPropertyValue(0x6814a50e, strIcon);
            CString strSymbol(strIcon.c_str());
            FUN_1401d3700(strSymbol);
            EntityPtr spEntity = new UIMinimapEntityMapObject(nId, spObject);
            spEntity->m_icon = strSymbol;
            spEntity->m_layer = s_strLayerInteract;
            spEntity->m_position = reinterpret_cast<const efd::Point3&>(kPos);
            spEntity->m_visible = true;
            spEntity->m_state = strSymbol;
            spEntity->m_text = L"";
            if (FUN_141a3e7d0(spEntity))
                m_objects.SetAt(nId, spEntity);
            ++nId;
        }
    }
}
MS2_REPLACE_METHOD(0x141a3f1c0, UIMinimapDialog, FUN_141a3f1c0, 927, 0x9CACB9AE);

// @0x141a3ea10
void UIMinimapDialog::FUN_141a3ea10()
{
    if (m_30 == 0)
        return;
    FUN_141a3fb10();
    int nField = FUN_1403ed2d0()->FUN_141bd3060();
    ATL::CAtlArray<ProxyPtr> portals;
    ATL::CAtlMap<unsigned int, ProxyPtr>& proxies = FUN_1403ed2d0()->FUN_141bc9fb0();
    for (POSITION pos = proxies.GetStartPosition(); pos != 0; proxies.GetNext(pos)) {
        ProxyPtr spProxy = proxies.GetValueAt(pos);
        if (spProxy.get()) {
            if (!spProxy->FUN_1416c20d0()) {
                FUN_141a3d080(spProxy);
            } else {
                {
                    int nDest = spProxy->m_portal->FUN_14169d280();
                    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(nDest);
                    if (spField.get() && spField->FUN_140375130()) {
                        HomeListPtr spHomes(0);
                        m_homes.SetAt(nDest, spHomes);
                    }
                }
                portals.Add(spProxy);
            }
        }
    }
    FUN_141a3ed50();
    size_t nCount = portals.GetCount();
    for (size_t i = 0; i < nCount; ++i)
        FUN_141a3d080(portals[i]);
    if (FUN_1409f24a0()->FUN_14085f6e0(nField))
        FUN_141a3dbb0();
    FUN_141a3df40();
    FUN_141a3dda0();
    FUN_141a3eed0();
    FUN_141a3ef80();
    FUN_141a3f1c0();
    m_30->Invoke("buildPlayers");
}
MS2_REPLACE_METHOD(0x141a3ea10, UIMinimapDialog, FUN_141a3ea10, 816, 0x8461D8E7);

// @0x141a3fe10
void UIMinimapDialog::FUN_141a3fe10(ProxyPtr spProxy, EntityPtr spEntity, int n)
{
    if (spProxy == 0 || spEntity == 0)
        return;
    switch (n) {
    case 1:
        FUN_141a41560(spProxy, spEntity);
        break;
    case 2:
        FUN_141a40d90(spProxy, spEntity);
        break;
    case 3:
        FUN_141a422c0(spProxy, spEntity);
        break;
    case 4:
        FUN_141a407c0(spProxy, spEntity);
        break;
    }
}

// @0x141a400d0
// MS2-FUNCTIONAL: the exe frame is 0x10 larger (one more temporary).
void UIMinimapDialog::FUN_141a400d0(ProxyPtr spProxy, EntityPtr spEntity, int n)
{
    if (spProxy == 0 || spEntity == 0)
        return;
    if (n == 4)
        return;
    if (spEntity->m_visible && static_cast<ASMovieClip*>(spEntity->m_clip) != 0) {
        if (!FUN_141a44730(spProxy->FUN_1416c2270(), spEntity->m_clip)) {
            spEntity->m_visible = false;
            spEntity->m_clip->vfunc_4(spEntity->m_visible);
        }
    }
}

// @0x141a402b0
// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (temporaries share slots).
void UIMinimapDialog::FUN_141a402b0(EntityPtr spEntity)
{
    if (spEntity == 0 || spEntity->m_clip == 0)
        return;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (m_viewport == 0)
        return;
    MS2Ptr<ASMovieClip> spClip = spEntity->m_clip;
    NiPoint3 kOut(efd::Point3::ZERO);
    NiPoint3 kPos(static_cast<const efd::Point3&>(pPC->vfunc_18()));
    if (m_viewport->FUN_141486410(kPos, kOut)) {
        spClip->vfunc_4(true);
        spClip->FUN_1422c00f0(kOut.x, kOut.y);
    }
    if (!m_fullmap && static_cast<ASMovieClip*>(m_clip228) != 0) {
        float x = m_208.x - kOut.x * m_scale;
        float y = m_208.y - kOut.y * m_scale;
        m_clip228->vfunc_4(true);
        m_clip228->FUN_1422c00f0(x, y);
    }
    bool bAlive = pPC->FUN_14166c930() != 12;
    CString strState(bAlive ? s_strIdle : s_strDie);
    if (strState != spEntity->m_state) {
        spEntity->m_state = strState;
        spClip->vfunc_15(strState);
    }
    if (m_clip238 == 0)
        m_clip238 = spClip->FUN_1409b4560(CString("m_arrow"));
    if (static_cast<ASMovieClip*>(m_clip238) != 0) {
        m_clip238->vfunc_4(bAlive);
        if (bAlive)
            m_clip238->FUN_1422bfef0(FUN_141a45920(pPC));
    }
}

// @0x141a407c0
void UIMinimapDialog::FUN_141a407c0(ProxyPtr spProxy, EntityPtr spEntity)
{
    if (m_30 == 0)
        return;
    if (spEntity == 0 || spEntity->m_clip == 0)
        return;
    if (spProxy == 0 || !spProxy->FUN_1416c20d0())
        return;
    MS2Ptr<ASMovieClip> spClip = spEntity->m_clip;
    bool bUpdate = m_210;
    if (!bUpdate)
        bUpdate = spClip->FUN_1422bfca0() != spProxy->m_portal->FUN_14169d1d0();
    if (bUpdate) {
        bool bVisible = spEntity->m_visible;
        CString strIcon = spEntity->m_icon;
        CString strState = spEntity->m_state;
        FUN_141a43b80(spProxy, spEntity, false);
        if (bVisible != spEntity->m_visible || strIcon != spEntity->m_icon || strState != spEntity->m_state) {
            ASObj data(2);
            spEntity->FUN_141a31270(data, m_viewport);
            Scaleform::GFx::Value value = m_30->Invoke("changeEntityData", spClip->FUN_1422bb870(), data.FUN_1422bb870());
            if (!FUN_1409b4d40(value))
                return;
            spClip = FUN_1409b40c0(m_28, value);
            spClip->vfunc_4(spEntity->m_visible);
            spEntity->m_clip = spClip;
        }
    }
}

class Unk_MmObjectPos { public: efd::Point3 FUN_1409673c0(); };    // CInteractObject: position copy

// @0x141a40d90
void UIMinimapDialog::FUN_141a40d90(ProxyPtr spProxy, EntityPtr spEntity)
{
    if (m_30 == 0)
        return;
    if (spProxy == 0 || !spProxy->FUN_1416c2090() || spEntity == 0)
        return;
    CString strIcon = spEntity->m_icon;
    CString strState = spEntity->m_state;
    CString strLayer = spEntity->m_layer;
    CStringW strGuide = spEntity->m_guideName;
    FUN_141a43680(spProxy, spEntity);
    unsigned int nChanged = 0;
    if (!spEntity->m_icon.IsEmpty()) {
        if (strIcon != spEntity->m_icon)
            nChanged |= 1;
        if (strState != spEntity->m_state)
            nChanged |= 2;
        if (strLayer != spEntity->m_layer)
            nChanged |= 8;
        if (strGuide != spEntity->m_guideName)
            nChanged |= 0x10;
    }
    if (nChanged != 0) {
        if (nChanged == 2) {
            spEntity->m_clip->vfunc_15(spEntity->m_state);
        } else {
            ASObj data(2);
            data.FUN_1407cba60(s_strMcName, spEntity->m_icon);
            data.FUN_1407cba60(s_strFrame, spEntity->m_state);
            data.FUN_1407cba60(s_strLayer, spEntity->m_layer);
            data.FUN_1407cbbe0(s_strShowGuide, spEntity->m_showGuide);
            data.FUN_1407cbb20(s_strGuideName, spEntity->m_guideName);
            Scaleform::GFx::Value value = m_30->Invoke("changeEntityData", spEntity->m_clip->FUN_1422bb870(), data.FUN_1422bb870());
            if (FUN_1409b4d40(value))
                spEntity->m_clip = FUN_1409b40c0(m_28, value);
        }
    }
    if (spEntity->m_visible) {
        if (!FUN_141a44730(spProxy->FUN_1416c2270(), spEntity->m_clip))
            spEntity->m_visible = false;
    }
    if (!spEntity->m_64)
        spEntity->m_clip->vfunc_4(spEntity->m_visible);
}

class Unk_MmPvPPlayer { public: MS2Ptr<CPvPInfo> FUN_140967420(); };   // PC: the pvp info (+0x1240)
class Unk_HsInfo : public CPtred { public: int FUN_14050a6a0(); };   // hide and seek: the player is a seeker
class Unk_MmPvPRankEntry { public: bool FUN_141343860(); };         // the player has a rank
class Unk_MmPvPRank                                                 // the pvp ranking service (FUN_140f97ef0)
{
public:
    int FUN_1413437e0(__int64 nCharId);                             // the rank of a character
    Unk_MmPvPRankEntry* FUN_141343810(int nRank);                   // the row of a rank
};
Unk_MmPvPRank* FUN_140f97ef0();
CStringW FUN_140719630(int n);

// @0x141a41560
void UIMinimapDialog::FUN_141a41560(ProxyPtr spProxy, EntityPtr spEntity)
{
    if (m_30 == 0)
        return;
    if (spProxy == 0 || !spProxy->FUN_1416c2040() || spEntity == 0)
        return;
    MS2Ptr<ASMovieClip> spClip = spEntity->m_clip;
    if (spClip == 0)
        return;
    CString strState = spEntity->m_state;
    FUN_141a432a0(spProxy, spEntity);
    if (strState != spEntity->m_state) {
        ASObj data(2);
        data.FUN_1407cba60(s_strFrame, spEntity->m_state);
        data.FUN_1407cba60(s_strLayer, spEntity->m_layer);
        Scaleform::GFx::Value value = m_30->Invoke("changeEntityData", spEntity->m_clip->FUN_1422bb870(), data.FUN_1422bb870());
        if (!FUN_1409b4d40(value))
            return;
        spEntity->m_clip = FUN_1409b40c0(m_28, value);
        spClip = spEntity->m_clip;
    }
    bool bVisible = true;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0) {
        int nPkMode = FUN_1403ed2d0()->FUN_141bd30a0()->FUN_1403754d0();
        if (nPkMode != 0) {
            bVisible = pPC != 0 ? pPC->FUN_1415278d0(reinterpret_cast<void*>(spProxy->FUN_1416c22f0())) == 1 : false;
        } else {
            MS2Ptr<CPvPInfo> spPvP = reinterpret_cast<Unk_MmPvPPlayer*>(pPC)->FUN_140967420();
            if (spPvP.get() != 0) {
                if (spPvP->FUN_1407435d0() || spPvP->FUN_1407436d0()) {
                    __int64 nCharId = spProxy->FUN_1416c22f0();
                    PC* pOther = FUN_1403ed2d0()->FUN_141bd1530(spProxy->FUN_1416c22f0());
                    if (pOther != 0) {
                        bVisible = false;
                        int nRank = FUN_140f97ef0()->FUN_1413437e0(nCharId);
                        if (nRank > 0) {
                            Unk_MmPvPRankEntry* pEntry = FUN_140f97ef0()->FUN_141343810(nRank);
                            if (nRank <= 3 && pEntry != 0 && pEntry->FUN_141343860())
                                bVisible = true;
                            if (bVisible) {
                                {
                                    CString strFrame("rank");
                                    spClip->vfunc_15(strFrame);
                                }
                                MS2Ptr<ASTextField> spText = spClip->FUN_1409b4620("textField");
                                if (spText.get() != 0)
                                    spText->FUN_1422c4cd0(FUN_140719630(nRank));
                            }
                        }
                    }
                } else if (spPvP->FUN_140743610()) {
                    PC* pOther = FUN_1403ed2d0()->FUN_141bd1530(spProxy->FUN_1416c22f0());
                    if (pOther != 0) {
                        bVisible = reinterpret_cast<Unk_MmPvPPlayer*>(pOther)->FUN_140967420()->FUN_140743710() == reinterpret_cast<Unk_MmPvPPlayer*>(pPC)->FUN_140967420()->FUN_140743710();
                        if (bVisible) {
                            const CString& strTeam = spPvP->FUN_140743710() == 0xc9 ? s_strLayerRedTeam : s_strLayerBlueTeam;
                            spClip->vfunc_15(strTeam);
                        }
                    }
                } else if (spPvP->FUN_140743590() || spPvP->FUN_140743690()) {
                    PC* pOther = FUN_1403ed2d0()->FUN_141bd1530(spProxy->FUN_1416c22f0());
                    if (pOther != 0)
                        bVisible = pOther->FUN_141674bc0() == 0;
                } else if (spPvP->FUN_140743550()) {
                    PC* pOther = FUN_1403ed2d0()->FUN_141bd1530(spProxy->FUN_1416c22f0());
                    if (pOther != 0) {
                        bVisible = pOther->vfunc_116() == pPC->vfunc_116() ? true : pOther->FUN_141674bc0() == 0;
                    }
                }
            }
            MS2Ptr<Unk_HsInfo> spHs = pPC->FUN_141664200();
            if (static_cast<bool>(spHs.get()) && spHs->FUN_14050a6a0() != 0)
                bVisible = pPC != 0 ? pPC->FUN_1415278d0(reinterpret_cast<void*>(spProxy->FUN_1416c22f0())) == 1 : false;
        }
    }
    if (spProxy->m_cc == 0x3f)
        bVisible = false;
    if (bVisible) {
        if (!FUN_141a44730(spProxy->FUN_1416c2270(), spClip))
            bVisible = false;
    }
    spEntity->m_visible = bVisible;
    spClip->vfunc_4(bVisible);
}

// @0x141a432a0
void UIMinimapDialog::FUN_141a432a0(ProxyPtr spProxy, EntityPtr spEntity)
{
    if (spProxy == 0 || spEntity == 0)
        return;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    __int64 nId = spProxy->FUN_1416c22f0();
    if (spProxy->FUN_1416c1ff0()) {
        spEntity->m_state = s_strIdle;
        spEntity->m_layer = s_strLayerPlayer;
    } else if (m_460 == nId) {
        spEntity->m_state = s_strQuestTarget;
        spEntity->m_layer = s_strLayerQuestTarget;
    } else {
        MS2Ptr<CPartyMember> spMember = CPartyManager::GetInstance()->FUN_14162afc0(nId);
        if (static_cast<CPartyMember*>(spMember) != 0) {
            spEntity->m_state = spMember->leader != 0 ? s_strPartyChief : s_strParty;
            spEntity->m_layer = s_strLayerParty;
        } else {
            MS2Ptr<CGuildMember> spGuild = CGuildManager::GetInstance()->FUN_1404cf9f0(spProxy->FUN_1416c23b0());
            if (static_cast<CGuildMember*>(spGuild) != 0) {
                spEntity->m_state = s_strGuild;
                spEntity->m_layer = s_strLayerGuild;
            } else if (CBuddyManager::GetInstance()->FUN_140ae4d70(nId)) {
                spEntity->m_state = s_strBuddy;
                spEntity->m_layer = s_strLayerBuddy;
            } else {
                spEntity->m_state = s_strNormal;
                spEntity->m_layer = s_strLayerPc;
            }
        }
    }
    if (spProxy->m_68 != 0)
        spEntity->m_state = s_strDie;
}

// @0x141a43680
void UIMinimapDialog::FUN_141a43680(ProxyPtr spProxy, EntityPtr spEntity)
{
    spEntity->m_64 = false;
    spEntity->m_showGuide = false;
    const Unk_QmNpcQuestState* pGuide = spProxy->FUN_1416c2200();
    bool bBoss = false;
    if (pGuide->m_icon != 0xb) {
        CString strState;
        CString strLayer;
        spEntity->FUN_141a31c80(pGuide, strState, strLayer);
        spEntity->m_icon = s_strQuest;
        spEntity->m_state = strState;
        spEntity->m_layer = strLayer;
        spEntity->m_visible = FUN_141a45b70(spProxy);
        spEntity->m_showGuide = true;
        spEntity->m_guideName = FUN_141a45ed0(reinterpret_cast<const int&>(pGuide->m_questId), pGuide->m_state);
        return;
    }
    MS2Ptr<NpcDataCli> spNpc = spProxy->FUN_1416c2220();
    if (spNpc == 0)
        return;
    spEntity->FUN_141a310e0(spNpc);
    if (spEntity->m_visible)
        spEntity->m_visible = FUN_141a45b70(spProxy);
    if (spProxy->m_68 != 0) {
        bBoss = FUN_141a45c70(spEntity->m_icon);
        if (bBoss)
            spEntity->m_state = s_strDie;
        else
            spEntity->m_visible = false;
    }
    if (!bBoss) {
        if (CQuestNavigator::GetInstance()->HasMap(spProxy->FUN_1416c2350())) {
            spEntity->m_icon = s_strQuestTargetMonster;
            spEntity->m_layer = s_strLayerNpc;
            spEntity->m_64 = true;
        }
    }
}

class Unk_MmPortalPos { public: efd::Point3 FUN_14169d2f0(); };    // CPortal: the entity position
extern char DAT_143b059e8;                                          // the entity app framework
HardwareInstancingService* FUN_14098c5b0(char* pFramework);

// @0x141a43b80
void UIMinimapDialog::FUN_141a43b80(ProxyPtr spProxy, EntityPtr spEntity, bool bInit)
{
    if (spProxy == 0 || spEntity == 0)
        return;
    MS2Ptr<CPortal> spPortal = spProxy->m_portal;
    if (spPortal == 0)
        return;
    efd::SmartPointer<HardwareInstancingService> spService(FUN_14098c5b0(&DAT_143b059e8));
    if (static_cast<bool>(spService)) {
        if (spService->FUN_1413d7d90(spPortal->m_idEntity) != 0)
            return;
    }
    MS2Ptr<UIMinimapEntityProxyPortal> spPortalEntity = dynamic_cast<UIMinimapEntityProxyPortal*>(static_cast<UIMinimapEntity*>(spEntity));
    if (spPortalEntity == 0)
        return;
    spPortalEntity->FUN_141a33650();
    bool bEnabled = spPortal->FUN_14169d160();
    bool bVisible = spPortal->FUN_14169d1d0();
    int nDest = spPortal->FUN_14169d280();
    bool bHousing = false;
    if (nDest != 0) {
        MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(nDest);
        if (spField == 0)
            return;
        bHousing = spField->FUN_140375130();
    }
    if (!bInit) {
        bool bChanged = spEntity->m_visible != bVisible;
        if (!bChanged && !bHousing)
            return;
    }
    if (bInit) {
        int nField = FUN_1403ed2d0()->FUN_141bd3060();
        if (nDest == nField)
            return;
        spEntity->FUN_141a323e0(spPortal);
        spEntity->m_position = reinterpret_cast<Unk_MmPortalPos*>(spPortal.operator->())->FUN_14169d2f0();
    }
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (!bHousing) {
        spEntity->m_showText = true;
        spEntity->m_showGuide = true;
    }
    if (bHousing && spPortal->m_nType != 4) {
        bool bSpecial = false;
        CString strIcon;
        CString strLayer;
        int nNpc = spEntity->FUN_141a316d0(nDest, bSpecial, strIcon, strLayer);
        bool bHandled = false;
        if (!bSpecial) {
            if (FUN_141a44850(spEntity, nDest, bEnabled)) {
                spPortalEntity->FUN_141a51050(2);
                bHandled = true;
            }
        }
        if (!bHandled && nNpc != 0) {
            if (FUN_141a44c00(spEntity, nNpc, bSpecial, strIcon, strLayer, bEnabled, bVisible)) {
                spPortalEntity->FUN_141a51050(1);
                spPortalEntity->FUN_141a51030(bSpecial);
                spPortalEntity->FUN_141a50bc0(nNpc);
            }
        }
    }
    if (spPortalEntity->FUN_141a4b020() == 0)
        spEntity->FUN_141a323e0(spPortal);
}

// @0x141a44380
void UIMinimapDialog::FUN_141a44380(MS2Ptr<CInteractObject> spObject, EntityPtr spEntity)
{
    bool bOverlap = CQuestNavigator::GetInstance()->HasNpc(spObject->FUN_140967110()) == 1 && spObject->FUN_1413b5600() == 1;
    spEntity->m_icon = bOverlap ? s_strQuestTargetObject : spObject->FUN_140966e00()->m_display.m_strMinimapIcon;
    spEntity->m_layer = s_strLayerInteract;
    spEntity->m_position = reinterpret_cast<Unk_MmObjectPos*>(spObject.operator->())->FUN_1409673c0();
    spEntity->m_text = FUN_1401a9d70()->FUN_141811980(0x10, spObject->FUN_140967110());
    spEntity->m_64 = bOverlap;
    if (!spEntity->m_64)
        spEntity->m_visible = spObject->FUN_1413b5600() == 1 && !spEntity->m_icon.IsEmpty();
    if (spObject->vfunc_5() == 9) {
        spEntity->m_layer = s_strLayerWatchtower;
        spEntity->m_visible = true;
        FUN_141a42600(spObject, spEntity);
    }
}

// @0x141a44850
bool UIMinimapDialog::FUN_141a44850(EntityPtr spEntity, const int& nField, bool b)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return false;
    CString strIcon;
    int nHome = 0;
    bool bMine = false;
    if (pPC->FUN_141527f80(&nHome) && nHome == nField) {
        bMine = true;
        strIcon = s_strMyHome;
    }
    HomeListPtr spHomes(0);
    if (m_homes.Lookup(nField, spHomes) && spHomes.get()) {
        bool bFound = false;
        CStringW strUnused;
        size_t nTotal = spHomes->GetCount();
        size_t nCount = nTotal < 5 ? nTotal : 5;
        POSITION pos = spHomes->GetHeadPosition();
        for (size_t i = 0; i < nCount; i++) {
            __int64 nId = spHomes->GetAt(pos);
            Unk_BuddyPtr<CBuddy> spBuddy = CBuddyManager::GetInstance()->FUN_140ae4b70(nId);
            if (spBuddy.get()) {
                bFound = true;
                break;
            }
            spHomes->GetNext(pos);
        }
        if (bFound && strIcon.IsEmpty())
            strIcon = s_strFriendHome;
    }
    if (!strIcon.IsEmpty()) {
        spEntity->m_icon = strIcon;
        spEntity->m_text = "";
        spEntity->m_state = "";
        spEntity->m_layer = s_strLayerHome;
        spEntity->m_showText = false;
        spEntity->m_showGuide = false;
        spEntity->m_visible = b;
        spEntity->m_inFieldNpc = true;
        return true;
    }
    return false;
}

// @0x141a44c00
bool UIMinimapDialog::FUN_141a44c00(EntityPtr spEntity, const int& nField, bool b1, const CString& strIcon, const CString& strLayer, bool b2, bool b3)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return false;
    CStringW strText;
    bool bVisible = false;
    if (b1) {
        Unk_QmNpcQuestState guide;
        FUN_140764020()->FUN_1416d12d0(nField, &guide, 0);
        bVisible = b2;
        strText = FUN_141a45ed0(reinterpret_cast<const int&>(guide.m_questId), guide.m_state);
    } else {
        bVisible = b3;
    }
    spEntity->m_icon = strIcon;
    if (b1) {
        spEntity->m_icon = s_strQuest;
        spEntity->m_showText = true;
        spEntity->m_showGuide = true;
        spEntity->m_guideName = strText;
    } else {
        spEntity->m_showText = true;
        spEntity->m_showGuide = false;
    }
    spEntity->m_state = strIcon;
    spEntity->m_layer = strLayer;
    spEntity->m_visible = bVisible;
    spEntity->m_inFieldNpc = true;
    return true;
}

class Unk_MmHome;
Unk_MmHome* FUN_1409670e0();                                        // the home service
void FUN_1410c3330(Unk_MmHome* pHome, CStringW& strOut);            // the home name
__int64 FUN_1410c3180(Unk_MmHome* pHome);                           // the home owner's account id
extern __int64 DAT_143ab2820;                                       // the own account id

// @0x141a3c150
void UIMinimapDialog::FUN_141a3c150()
{
    if (m_30 == 0)
        return;
    bool bForceMinimize = true;
    MS2Ptr<Unk_MmFieldInfo> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (static_cast<bool>(spField.get()) && static_cast<bool>(spField->m_minimap.get()))
        bForceMinimize = spField->m_64 != 0 || spField->m_minimap->m_image.IsEmpty();
    m_forceMinimize = bForceMinimize;
    CStringW strName;
    FUN_1410c3330(FUN_1409670e0(), strName);
    bool bReport = false;
    __int64 nOwner = FUN_1410c3180(FUN_1409670e0());
    if (nOwner != 0 && nOwner != DAT_143ab2820)
        bReport = true;
    m_maxPanel = FUN_140ede180("m_maxpanel");
    MS2Ptr<AScript> spData = m_data;
    if (spData == 0)
        spData.AssignRaw(new AScript(2));
    if (spData.get() != 0) {
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbb20("fieldname", strName);
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbbe0("minimize", vfunc_64() == 1);
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbbe0("fullmap", m_fullmap);
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbbe0("forceMinimize", bForceMinimize);
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbbe0("reportVisible", bReport);
        if (m_78 == 0) {
            static_cast<ASObj*>(spData.operator->())->FUN_1407cb9c0("width", 0);
            static_cast<ASObj*>(spData.operator->())->FUN_1407cb9c0("height", 0);
            static_cast<ASObj*>(spData.operator->())->FUN_1409c4a30("scale", 1.0f);
            static_cast<ASObj*>(spData.operator->())->FUN_1407cb9c0("bgAlpha", 30);
            static_cast<ASObj*>(spData.operator->())->FUN_1407cb9c0("mapAlpha", 100);
        }
        else {
            float fScale = 1.0f;
            int nBgAlpha = 30;
            int nMapAlpha = 100;
            int nWidth = 0;
            int nHeight = 0;
            nWidth = FUN_1409c1750(spData->FUN_1422baa20("width"));
            nHeight = FUN_1409c1750(spData->FUN_1422baa20("height"));
            nMapAlpha = FUN_1409c1750(spData->FUN_1422baa20("mapAlpha"));
            nBgAlpha = FUN_1409c1750(spData->FUN_1422baa20("bgAlpha"));
            fScale = static_cast<float>(FUN_140f17ed0(spData->FUN_1422baa20("scale")));
        }
        ASArray showEntities(2);
        for (POSITION pos = m_showAttrs.GetStartPosition(); pos != 0; m_showAttrs.GetNext(pos)) {
            ASObj entry(2);
            ShowAttrMap::CPair* pPair = m_showAttrs.GetAt(pos);
            if (pPair != 0) {
                MS2Ptr<TShowAttr> spAttr = pPair->m_value;
                if (spAttr == 0)
                    continue;
                const CString& strKey = pPair->m_key;
                entry.FUN_1407cba60("layer", strKey);
                entry.FUN_1407cb9c0("state", spAttr->m_state);
                entry.FUN_1407cbb20("textKey", spAttr->m_key);
                entry.FUN_1407cb9c0("displayOrder", spAttr->m_order);
                entry.FUN_1407cba60("iconSuffix", strKey);
            }
            showEntities.FUN_1422bc050(entry.FUN_1422bb870());
        }
        static_cast<ASObj*>(spData.operator->())->FUN_1409adbe0("showentity", Scaleform::GFx::Value(showEntities.FUN_1422bb870()));
        int nSelected = 0;
        ASArray channels(2);
        m_channel = FUN_14092f640();
        UIServerListDialog* pServerList = Unk_MmGetDialog<UIServerListDialog>();
        if (pServerList != 0)
            pServerList->FUN_141ad2f60(channels, &nSelected, m_channel);
        static_cast<ASObj*>(spData.operator->())->FUN_1409adbe0("channel", Scaleform::GFx::Value(channels.FUN_1422bb870()));
        static_cast<ASObj*>(spData.operator->())->FUN_1407cb9c0("selectedchannel", nSelected);
        CStringW strGroup;
        if (DAT_143ab0248 != 2)
            strGroup = FUN_1401a9d70()->FUN_141811980(0x17, FUN_1403ed2d0()->FUN_141bd98f0());
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbb20("channelprefix", FUN_14028b8e0(L"s_word_ch"));
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbb20("channelgroup", strGroup);
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbb20("mapAlphaPrefix", FUN_14028b8e0(L"s_word_minimap_alpha"));
        static_cast<ASObj*>(spData.operator->())->FUN_1407cbb20("bgAlphaPrefix", FUN_14028b8e0(L"s_word_mapbg_alpha"));
    }
    m_30->Invoke("initData", spData->FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x141a3c150, UIMinimapDialog, FUN_141a3c150, 3442, 0x5796E527);

// @0x141a3d080
// MS2-FUNCTIONAL: the npc data conversion temp is copied through extra stack slots in the exe
void UIMinimapDialog::FUN_141a3d080(ProxyPtr spProxy)
{
    if (m_30 == 0)
        return;
    if (m_proxies.Lookup(spProxy) != 0)
        return;
    if (spProxy->FUN_1416c2040() || spProxy->FUN_1416c1ff0()) {
        ASObj data(2);
        if (FUN_141a3bda0(data, spProxy))
            m_30->Invoke("createPlayer", data.FUN_1422bb870());
    }
    EntityPtr spEntity(0);
    if (spProxy->FUN_1416c1ff0()) {
        spEntity.AssignRaw(new UIMinimapEntityProxy(spProxy->m_proxyId, 0));
        spEntity->m_icon = s_strPlayer;
        spEntity->m_layer = s_strLayerPlayer;
        spEntity->m_position = spProxy->FUN_1416c2270();
        spEntity->m_visible = true;
        spEntity->m_state = s_strIdle;
        m_player = spEntity;
    } else if (spProxy->FUN_1416c2040()) {
        spEntity.AssignRaw(new UIMinimapEntityProxy(spProxy->m_proxyId, 1));
        spEntity->m_icon = s_strOther;
        spEntity->m_position = spProxy->FUN_1416c2270();
        spEntity->m_visible = true;
        spEntity->m_text = spProxy->FUN_1416c23b0();
        spEntity->m_showText = false;
        spEntity->m_showGuide = false;
        FUN_141a432a0(spProxy, spEntity);
    } else if (spProxy->FUN_1416c2090()) {
        spEntity.AssignRaw(new UIMinimapEntityProxy(spProxy->m_proxyId, 2));
        MS2Ptr<CNpcData> spNpc = spProxy->FUN_1416c2220();
        if (static_cast<CNpcData*>(spNpc) != 0) {
            spEntity->m_text = spProxy->FUN_1416c23b0();
            spEntity->m_position = spProxy->FUN_1416c2270();
            FUN_141a43680(spProxy, spEntity);
        }
    } else if (spProxy->FUN_1416c21c0()) {
        spEntity.AssignRaw(new UIMinimapEntityProxy(spProxy->m_proxyId, 3));
        spEntity->m_text = spProxy->FUN_1416c23b0();
        spEntity->m_position = spProxy->FUN_1416c2270();
        FUN_141a43ac0(spProxy, spEntity);
    } else if (spProxy->FUN_1416c20d0()) {
        spEntity.AssignRaw(new UIMinimapEntityProxyPortal(spProxy->m_proxyId));
        if (spProxy->FUN_1416c2110())
            FUN_141a43b80(spProxy, spEntity, true);
    }
    if (FUN_141a3e7d0(spEntity))
        m_proxies.SetAt(spProxy, spEntity);
    if (spEntity->m_64)
        m_212 = true;
}

// @0x141a3e7d0
bool UIMinimapDialog::FUN_141a3e7d0(EntityPtr spEntity)
{
    if (m_30 == 0)
        return false;
    if (spEntity == 0 || spEntity->m_icon.IsEmpty())
        return false;
    ASObj data(2);
    spEntity->FUN_141a31270(data, m_viewport);
    Scaleform::GFx::Value value = m_30->Invoke("createEntity", data);
    if (FUN_1409b4d40(value)) {
        spEntity->m_clip = FUN_1409b40c0(m_28, value);
        if (static_cast<ASMovieClip*>(spEntity->m_clip) != 0)
            return true;
    }
    return false;
}

// @0x141a3eed0
void UIMinimapDialog::FUN_141a3eed0()
{
    ATL::CAtlArray<MS2Ptr<CInteractObject> > objects;
    FUN_1403ed2d0()->FUN_141bc5f10(objects);
    for (size_t i = 0; i < objects.GetCount(); ++i)
        FUN_141a39770(objects[i]);
}
MS2_REPLACE_METHOD(0x141a3eed0, UIMinimapDialog, FUN_141a3eed0, 166, 0x633A6A4C);

// @0x141a3f570
void UIMinimapDialog::FUN_141a3f570()
{
    if (m_30 == 0)
        return;
    if (static_cast<ASMovieClip*>(m_clip228) != 0) {
        m_30->Invoke("removeField");
        m_clip228 = 0;
    }
}
MS2_REPLACE_METHOD(0x141a3f570, UIMinimapDialog, FUN_141a3f570, 134, 0x60F6F4E1);

// @0x141a3f600
void UIMinimapDialog::FUN_141a3f600(ProxyPtr spProxy)
{
    if (spProxy == 0)
        return;
    EntityPtr spEntity(0);
    if (m_proxies.Lookup(spProxy, spEntity)) {
        FUN_141a3f730(spEntity->m_clip, spProxy);
        m_proxies.RemoveKey(spProxy);
    }
}

// @0x141a3f730
// MS2-FUNCTIONAL: the exe frame is 0x10 larger (one more argument temporary).
void UIMinimapDialog::FUN_141a3f730(MS2Ptr<ASMovieClip> spClip, ProxyPtr spProxy)
{
    if (m_30 == 0 || spClip == 0)
        return;
    CString strChar;
    if (static_cast<CProxyGameObject*>(spProxy) != 0 && spProxy->FUN_1416c22f0() != 0)
        strChar = FUN_140719530(spProxy->FUN_1416c22f0());
    static_cast<Unk_MmScript*>(m_30.operator->())->FUN_141a46b60("removeEntity", spClip->FUN_1422bb870(), strChar);
}

// @0x141a3f930
void UIMinimapDialog::FUN_141a3f930(EntityPtr spEntity)
{
    if (spEntity == 0)
        return;
    FUN_141a3f730(spEntity->m_clip, ProxyPtr(0));
}

// @0x141a46c90
void UIMinimapDialog::FUN_141a46c90(EntityMap& map)
{
    if (map.IsEmpty())
        return;
    for (POSITION pos = map.GetStartPosition(); pos != 0; map.GetNext(pos)) {
        EntityPtr spEntity = map.GetValueAt(pos);
        if (spEntity == 0)
            continue;
        FUN_141a3f730(spEntity->m_clip, ProxyPtr(0));
    }
}

// @0x141a46dc0
void UIMinimapDialog::FUN_141a46dc0(NamedMap& map)
{
    if (map.IsEmpty())
        return;
    for (POSITION pos = map.GetStartPosition(); pos != 0; map.GetNext(pos)) {
        EntityPtr spEntity = map.GetValueAt(pos);
        if (spEntity == 0)
            continue;
        FUN_141a3f730(spEntity->m_clip, ProxyPtr(0));
    }
}

// @0x141a46ef0
void UIMinimapDialog::FUN_141a46ef0(ProxyMap& map)
{
    if (map.IsEmpty())
        return;
    for (POSITION pos = map.GetHeadPosition(); pos != 0; map.GetNext(pos)) {
        ProxyPtr spProxy = map.GetKeyAt(pos);
        EntityPtr spEntity = map.GetValueAt(pos);
        if (spEntity == 0)
            continue;
        FUN_141a3f730(spEntity->m_clip, spProxy);
    }
}

// @0x141a47060
void UIMinimapDialog::FUN_141a47060(BuddyMap& map)
{
    if (map.IsEmpty())
        return;
    for (POSITION pos = map.GetStartPosition(); pos != 0; map.GetNext(pos)) {
        EntityPtr spEntity = map.GetValueAt(pos);
        if (spEntity == 0)
            continue;
        FUN_141a3f730(spEntity->m_clip, ProxyPtr(0));
    }
}

// @0x141a47190
void UIMinimapDialog::FUN_141a47190(PingMap& map)
{
    if (map.IsEmpty())
        return;
    for (POSITION pos = map.GetHeadPosition(); pos != 0; map.GetNext(pos)) {
        EntityPtr spEntity = map.GetValueAt(pos);
        if (spEntity == 0)
            continue;
        FUN_141a3f730(spEntity->m_clip, ProxyPtr(0));
    }
}

void FUN_1407cd930(Scaleform::GFx::Value* pObj, const char* szName, const Scaleform::GFx::Value& v);   // set a member

// @0x141a472c0
void ASObj::FUN_141a472c0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x141a3f9f0
void UIMinimapDialog::FUN_141a3f9f0(Unk_BuddyPtr<CBuddy> spBuddy)
{
    if (spBuddy == 0)
        return;
    int nField = spBuddy->FUN_1401cc3e0();
    if (static_cast<unsigned int>(nField) > 0) {
        unsigned __int64 nHome = spBuddy->FUN_1401cc2f0();
        EntityPtr spEntity(0);
        if (m_buddies.Lookup(nHome, spEntity))
            FUN_141a3f930(spEntity);
        else
            FUN_141a455e0(nField, nHome);
    }
}

// @0x141a3fb10
void UIMinimapDialog::FUN_141a3fb10()
{
    FUN_141a3f930(m_taxi);
    FUN_141a3f930(m_return);
    FUN_141a3f930(m_telescope);
    FUN_141a3f930(m_player);
    m_clip238 = 0;
    FUN_141a46ef0(m_proxies);
    FUN_141a47190(m_pings);
    FUN_141a46ef0(m_proxies);
    FUN_141a47060(m_buddies);
    FUN_141a46dc0(m_named);
    FUN_141a46c90(m_triggers);
    FUN_141a46c90(m_objects);
    FUN_141a3fd20();
}
MS2_REPLACE_METHOD(0x141a3fb10, UIMinimapDialog, FUN_141a3fb10, 513, 0xEBDDB7DE);

// @0x141a3fd20
void UIMinimapDialog::FUN_141a3fd20()
{
    m_taxi = 0;
    m_return = 0;
    m_telescope = 0;
    m_player = 0;
    m_pings.RemoveAll();
    m_proxies.RemoveAll();
    m_buddies.RemoveAll();
    m_named.RemoveAll();
    m_triggers.RemoveAll();
    m_objects.RemoveAll();
    m_homes.RemoveAll();
}
MS2_REPLACE_METHOD(0x141a3fd20, UIMinimapDialog, FUN_141a3fd20, 231, 0x2297E1D9);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc01c0-0x142cc0d10 .text$yd
