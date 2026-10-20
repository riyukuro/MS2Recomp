// uiminimapentity.h - the minimap window (UIMinimapDialog, RTTI .?AVUIMinimapDialog@@, UI id 0x4e29, swf "MinimapDialog")
// and its marker classes (UIMinimapEntity and the Proxy / ProxyPortal / BuddyHome / MapObject / Taxi / Storm / Ping
// subclasses). Owning unit ?\uiminimapentity.cpp (client\ms2, 0x141a30f30..0x141a517d0). Header name assumed from the
// unit name. Layouts from the constructors/destructors; method names follow the v2525 snapshot's inferred names
// (work/ext/v2525 include/ms2/client/UIMinimap*.h) where given, FUN_<va> otherwise.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include <efd/Point3.h>
#include <efd/SmartPointer.h>
#include <NiPoint2.h>
#include <NiPoint3.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uicommon.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/minimapviewport.h"
#include "ms2/client/ms2/uiservereventdispatcher.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"   // UIQuestEventListener
#include "ms2/client/ms2/uisnowmaneventdialog.h"   // SnowmanPtr<>
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/uientityeventlistener.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/uibuddyeventlistener.h"

namespace egf { class Entity; }
class ASMovieClip;
class ASGameEntity;
class ASData;
class CProxyGameObject;
class CPortal;
class CInteractObject;
class CNpcData;
class NpcDataCli;
class PCBase;

// The refresh interval timer (8 bytes, 4-aligned: the dialog embeds two at +0x46c / +0x474). Ctor 0x140517b00,
// Reset 0x140268840, Check 0x140268870 (same shape as Unk_140517b00 in statemanager.h).
class Unk_MmRefreshTimer
{
public:
    Unk_MmRefreshTimer();                                       // 0x140517b00
    void FUN_140268840();                                       // reset
    int FUN_140268870(int nInterval);                           // elapsed check
    unsigned m_nInterval;
    unsigned m_nLastTick;
};
MS2_CHECK_SIZE(Unk_MmRefreshTimer, 8);

// ---- markers ----

// One marker on the minimap (0x68, base CPtred). vftable 0x142fca858.
class UIMinimapEntity : public CPtred
{
public:
    explicit UIMinimapEntity(const int& nType);                 // 0x141a30f30
    virtual ~UIMinimapEntity();                                 // 0 0x141a31040 (??_G 0x141a49130)
    virtual void GetText(CStringW& strText, ASObj& data);       // 1 0x141a32500 tooltip text
    virtual void vfunc_2(ASObj* pData);                         // 2 0x141a32620 extra data (empty)
    virtual void vfunc_3() {}                                   // 3 0x141a4df80 (empty)
    virtual int vfunc_4() { return 0; }                         // 4 0x141a4b200 kind

    void FUN_141a310e0(NpcDataCli* pNpc);                       // InitializeNpc
    void FUN_141a31270(ASObj& data, efd::SmartPointer<MinimapViewport> spViewport);   // BuildData
    int FUN_141a316d0(const int& nField, bool& bSpecial, CString& strIcon, CString& strLayer);   // ResolvePortalNpc
    CStringW FUN_141a319f0(NpcDataCli* pNpc, const CStringW& strName, bool b);          // NpcTooltip
    bool FUN_141a31c80(const struct Unk_QmNpcQuestState* pGuide, CString& strIcon, CString& strLayer);      // ResolveQuestIcon
    void FUN_141a32120(const Scaleform::GFx::FunctionHandler::Params& params);          // the AS "userFunction"
    bool FUN_141a32260(ASObj& data);                            // BuildTooltip
    void FUN_141a32330();                                       // OnClick
    void FUN_141a323e0(MS2Ptr<CPortal> spPortal);               // InitializePortal
    bool FUN_141a32640(CNpcData* pNpc);                         // NpcVisible
    CString FUN_141a32750(NpcDataCli* pNpc);                    // NpcIcon
    CString FUN_141a329e0(const CString& strIcon);              // NpcState
    CString FUN_141a32aa0(NpcDataCli* pNpc, const CString& strIcon);   // NpcLayer
    CStringW FUN_141a32ba0(Unk_BuddyPtr<CBuddy> spBuddy);       // BuddyHomeText

    MS2Ptr<ASMovieClip> m_clip;                                 // +0x18
    CString m_icon;                                             // +0x28 mcname
    CString m_state;                                            // +0x30 frame
    CString m_layer;                                            // +0x38 layer
    CStringW m_text;                                            // +0x40 name
    CStringW m_guideName;                                       // +0x48 guideName
    efd::Point3 m_position;                                     // +0x50
    bool m_showText;                                            // +0x5c
    bool m_showGuide;                                           // +0x5d
    bool m_visible;                                             // +0x5e
    bool m_inFieldNpc;                                          // +0x5f
    int m_type;                                                 // +0x60 groupType
    bool m_64;                                                  // +0x64
};
MS2_CHECK_SIZE(UIMinimapEntity, 0x68);
MS2_CHECK_OFFSET(UIMinimapEntity, m_clip, 0x18);
MS2_CHECK_OFFSET(UIMinimapEntity, m_position, 0x50);
MS2_CHECK_OFFSET(UIMinimapEntity, m_type, 0x60);

// A field object (proxy) marker (0x70). vftable 0x142fca888.
class UIMinimapEntityProxy : public UIMinimapEntity
{
public:
    UIMinimapEntityProxy(const int& nId, const int& nKind);     // 0x141a32d30
    virtual void GetText(CStringW& strText, ASObj& data);       // 1 0x141a32e20
    virtual void vfunc_3();                                     // 3 0x141a32ed0 click
    virtual int vfunc_4();                                      // 4 0x141a33060 m_kind
    virtual void vfunc_5(MS2Ptr<CProxyGameObject> spProxy, CStringW& strText, ASObj& data);   // 5 0x141a33080 ProxyText

    MS2Ptr<CProxyGameObject> FUN_141a32da0();                   // GetProxy

    int m_kind;                                                 // +0x68
    int m_id;                                                   // +0x6c
};
MS2_CHECK_SIZE(UIMinimapEntityProxy, 0x70);

// A portal marker (0x80). vftable 0x142fca8c0.
class UIMinimapEntityProxyPortal : public UIMinimapEntityProxy
{
public:
    explicit UIMinimapEntityProxyPortal(const int& nId);        // 0x141a335e0
    virtual void vfunc_5(MS2Ptr<CProxyGameObject> spProxy, CStringW& strText, ASObj& data);   // 5 0x141a33680

    void FUN_141a33650();                                       // Reset
    void FUN_141a33850(MS2Ptr<CPortal> spPortal, CStringW& strText);   // HousingText
    void FUN_141a33e30(MS2Ptr<CPortal> spPortal, CStringW& strText);   // FieldText
    int FUN_141a4b020() const { return m_state; }               // 0x141a4b020
    void FUN_141a50bc0(const int& nField) { m_field = nField; } // 0x141a50bc0
    void FUN_141a51030(bool b) { m_flag = b; }                  // 0x141a51030
    void FUN_141a51050(int nState) { m_state = nState; }        // 0x141a51050

    int m_state;                                                // +0x70 (1 field, 2 housing)
    int m_field;                                                // +0x74
    bool m_flag;                                                // +0x78
};
MS2_CHECK_SIZE(UIMinimapEntityProxyPortal, 0x80);

// A buddy's home marker (0x78). vftable 0x142fca8f8.
class UIMinimapEntityBuddyHome : public UIMinimapEntity
{
public:
    explicit UIMinimapEntityBuddyHome(Unk_BuddyPtr<CBuddy> spBuddy);   // 0x141a34550
    virtual void GetText(CStringW& strText, ASObj& data);       // 1 0x141a345c0

    Unk_BuddyPtr<CBuddy> m_buddy;                               // +0x68
};
MS2_CHECK_SIZE(UIMinimapEntityBuddyHome, 0x78);

// A map object (trigger entity) marker (0x78). vftable 0x142fca928.
class UIMinimapEntityMapObject : public UIMinimapEntity
{
public:
    UIMinimapEntityMapObject(const int& nId, efd::SmartPointer<egf::Entity> spEntity);   // 0x141a34670
    virtual void GetText(CStringW& strText, ASObj& data);       // 1 0x141a34700

    int m_id;                                                   // +0x68
    efd::SmartPointer<egf::Entity> m_entity;                    // +0x70
};
MS2_CHECK_SIZE(UIMinimapEntityMapObject, 0x78);

// The taxi station marker (0x70). vftable 0x142fca958.
class UIMinimapEntityTaxi : public UIMinimapEntity
{
public:
    explicit UIMinimapEntityTaxi(const efd::Point3& kPos);      // 0x141a34810
    virtual void GetText(CStringW& strText, ASObj& data);       // 1 0x141a34c30

    void FUN_141a34870(bool bBest);                             // SetBest
    void FUN_141a34890(const efd::Point3& kPos);                // Initialize

    bool m_best;                                                // +0x68
};
MS2_CHECK_SIZE(UIMinimapEntityTaxi, 0x70);

// A storm (field event) marker (0x70). vftable 0x142fca988.
class UIMinimapEntityStorm : public UIMinimapEntity
{
public:
    UIMinimapEntityStorm(int nId, const efd::Point3& kPos, const CStringW& strIcon);   // 0x141a34db0
    virtual void GetText(CStringW& strText, ASObj& data);       // 1 0x141a34eb0

    void FUN_141a34e30(int nId, const efd::Point3& kPos, const CStringW& strIcon);   // Initialize

    int m_id;                                                   // +0x68
};
MS2_CHECK_SIZE(UIMinimapEntityStorm, 0x70);

// A ping marker (0x68). vftable 0x142fca9b8.
class UIMinimapEntityPing : public UIMinimapEntity
{
public:
    explicit UIMinimapEntityPing(const efd::Point3& kPos);      // 0x141a34ee0
    virtual void GetText(CStringW& strText, ASObj& data);       // 1 0x141a351e0

    void FUN_141a34f40(const efd::Point3& kPos);                // Initialize
    void FUN_141a35000(unsigned __int64 nId, int nColor, const efd::Point3& kPos, const CStringW& strName);   // Update
};
MS2_CHECK_SIZE(UIMinimapEntityPing, 0x68);

// ---- the dialog ----

// UIDialog 0x178 + six listeners (+0x178 entity, +0x180 status, +0x188 quest, +0x190 UGC, +0x198 buddy, +0x1a0 server);
// members from +0x1a8. 0x490 bytes. vftables: primary 0x142fca9f8 (84 slots), IMessageListener 0x142fcaca0.
class UIMinimapDialog : public UIDialog, public UIEntityEventListener, public UIStatusEventListener,
                        public UIQuestEventListener, public UIUGCEventListener, public UIBuddyEventListener,
                        public UIServerEventListener
{
public:
    // A show/hide option of one marker kind (0x30). vftable 0x142fca9e8.
    class TShowAttr : public CPtred
    {
    public:
        // @0x141a48290
        TShowAttr(int nState, int nOrder, const CStringW& strKey) : m_state(nState), m_order(nOrder), m_key(strKey) {}
        int m_state;                                            // +0x18
        int m_order;                                            // +0x1c
        CStringW m_key;                                         // +0x20
        CStringW m_text;                                        // +0x28
    };

    typedef MS2Ptr<UIMinimapEntity> EntityPtr;
    typedef MS2Ptr<CProxyGameObject> ProxyPtr;
    typedef ATL::CRBMap<unsigned __int64, EntityPtr> PingMap;
    typedef ATL::CRBMap<ProxyPtr, EntityPtr> ProxyMap;
    typedef ATL::CAtlMap<unsigned __int64, EntityPtr> BuddyMap;
    typedef ATL::CAtlMap<CString, EntityPtr, CStringElementTraits<CString> > NamedMap;
    typedef ATL::CAtlMap<int, EntityPtr> EntityMap;
    typedef TPtrValue<ATL::CAtlList<unsigned __int64> > HomeListPtr;
    typedef ATL::CAtlMap<int, HomeListPtr> HomeMap;
    typedef ATL::CAtlMap<CString, MS2Ptr<TShowAttr>, CStringElementTraits<CString> > ShowAttrMap;

    UIMinimapDialog();                                          // 0x141a35220
    virtual ~UIMinimapDialog();                                 //  0 0x141a358a0 (??_G 0x141a490f0)
    virtual CString vfunc_1();                                  //  1 0x141a35ba0 "MinimapDialog"
    virtual int vfunc_13();                                     // 13 0x141a36f10
    virtual void vfunc_15();                                    // 15 0x141a362b0
    virtual bool vfunc_17();                                    // 17 0x141a36e50
    virtual void vfunc_18();                                    // 18 0x141a37010
    virtual void OnLoadComplete();                              // 22 0x141a35bf0
    virtual void vfunc_26();                                    // 26 0x141a35fe0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a366d0
    virtual void vfunc_43();                                    // 43 0x141a36e90
    virtual int vfunc_48() { return 0x4e29; }                   // 48 0x141a4b210
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x141a37150 tooltip
    virtual int vfunc_52();                                     // 52 0x141a38390
    virtual int vfunc_53(void* pCfg);                           // 53 0x141a37480 save
    virtual int vfunc_54(void* pCfg);                           // 54 0x141a37db0 load
    virtual int vfunc_65();                                     // 65 0x141a373f0
    virtual void vfunc_67();                                    // 67 0x141a37450
    virtual void vfunc_72();                                    // 72 0x141a36650 per frame
    virtual void vfunc_79(void* p);                             // 79 0x141a37080
    // UIEntityEventListener (+0x178): the actor arrives by value (MS2Ptr<CProxyGameObject>, the callee destroys it)
    virtual void vfunc_3(void* pActor);                         // 3 0x141a38b90
    virtual void vfunc_4(void* pActor);                         // 4 0x141a38c20
    // UIStatusEventListener (+0x180)
    virtual int vfunc_oa0_1();                                  //  1 0x141a38b10
    virtual void vfunc_oa0_7(int a1, CStringW s);               //  7 0x141a38a70
    virtual void vfunc_oa0_9(unsigned short a1);                //  9 0x141a38a10
    virtual void vfunc_oa0_20(int a1);                          // 20 0x141a38ae0
    // UIQuestEventListener (+0x188)
    virtual void vfunc_o178_1(void* p);                         // 1 0x141a38cb0
    virtual void vfunc_o178_2(void* p);                         // 2 0x141a38de0
    virtual void vfunc_o178_3(void* p);                         // 3 0x141a38f10
    virtual void vfunc_o178_4(void* p);                         // 4 0x141a39040
    virtual void vfunc_o178_5(void* p);                         // 5 0x141a390c0
    virtual void vfunc_o178_7(int a1, int a2);                  // 7 0x141a39060
    // UIUGCEventListener (+0x190)
    virtual void vfunc_ugc_1(void* p, CString str);             // 1 0x141a383b0
    virtual void vfunc_ugc_5();                                 // 5 0x141a38500
    virtual void vfunc_ugc_6();                                 // 6 0x141a38570
    // UIBuddyEventListener (+0x198)
    virtual void vfunc_buddy_3(__int64 nId);                    //  3 0x141a389d0
    virtual void vfunc_buddy_4(__int64 nId, int n);             //  4 0x141a38920
    virtual void vfunc_buddy_5(__int64 nId);                    //  5 0x141a38880
    virtual void vfunc_buddy_10(__int64 nId, int n);            // 10 0x141a385e0
    // UIServerEventListener (+0x1a0)
    virtual void Notify();                                      // 1 0x141a38b60

    void FUN_141a391f0(MS2Ptr<CInteractObject> spObject);       // RefreshNamedObject
    void FUN_141a39770(MS2Ptr<CInteractObject> spObject);       // AddNamed
    void FUN_141a39bf0(MS2Ptr<CInteractObject> spObject);       // RemoveNamed
    void FUN_141a39d40(int nId, int bVisible);                  // SetTriggerVisible
    void FUN_141a39e40();                                       // CheckSuppression
    void FUN_141a39e60();                                       // RefreshHousing
    void FUN_141a3a200();                                       // RefreshTaxi
    void FUN_141a3a780(int n);                                  // EnableTaxi
    void FUN_141a3a890();                                       // EnableTelescope
    void FUN_141a3a9a0(bool b);                                 // UpdateReturn
    void FUN_141a3abd0();                                       // EndTabView
    void FUN_141a3aca0();                                       // BeginTabView
    void FUN_141a3ad80(bool b);                                 // m_1fb
    void FUN_141a3ada0();                                       // InvalidateEntities
    void FUN_141a3add0();                                       // RefreshQuestIconChecks ("checkIcons")
    void FUN_141a3b130(unsigned __int64 nId, int nColor, const efd::Point3& kPos);   // AddPing
    void FUN_141a3b390(unsigned __int64 nId, int nColor, EntityPtr spEntity, const efd::Point3& kPos);   // UpdatePing
    void FUN_141a3b4d0(unsigned int& nQuest, unsigned __int64& nId);   // PingSelection
    EntityPtr FUN_141a3b510(ProxyPtr spProxy);                  // FindProxyEntity
    HomeListPtr FUN_141a3b660(const int& nField);               // PortalHomes
    void FUN_141a3b6f0();                                       // BuildShowAttributes
    bool FUN_141a3bda0(ASObj& data, ProxyPtr spProxy);          // BuildPlayerData
    void FUN_141a3c150();                                       // BuildUIData
    MS2Ptr<ASGameEntity> FUN_140ede180(const CString& strName);  // FindComponent (ICF'd GetChild instance)
    void FUN_141a3ced0();                                       // BuildField
    void FUN_141a3d080(ProxyPtr spProxy);                       // AddProxy
    void FUN_141a3dbb0();                                       // BuildTaxi
    void FUN_141a3dda0();                                       // BuildReturn
    void FUN_141a3df40();                                       // BuildTelescope
    void FUN_141a3e2d0(Unk_BuddyPtr<CBuddy> spBuddy);           // AddBuddyHome
    void FUN_141a3e4e0(efd::SmartPointer<egf::Entity> spEntity);   // AddTrigger
    bool FUN_141a3e7d0(EntityPtr spEntity);                     // CreateEntity
    void FUN_141a3ea10();                                       // BuildEntities
    void FUN_141a3ed50();                                       // BuildBuddyHomes
    void FUN_141a3eed0();                                       // BuildNamed
    void FUN_141a3ef80();                                       // BuildTriggers
    void FUN_141a3f1c0();                                       // BuildMapObjects
    void FUN_141a3f570();                                       // RemoveField
    void FUN_141a3f600(ProxyPtr spProxy);                       // RemoveProxy
    void FUN_141a3f730(MS2Ptr<ASMovieClip> spClip, ProxyPtr spProxy);   // RemoveClip
    void FUN_141a3f930(EntityPtr spEntity);                     // RemoveEntity
    void FUN_141a3f9f0(Unk_BuddyPtr<CBuddy> spBuddy);           // RemoveBuddyHome
    void FUN_141a3fb10();                                       // RemoveAllEntities
    void FUN_141a3fd20();                                       // ClearEntityContainers
    void FUN_141a3fe10(ProxyPtr spProxy, EntityPtr spEntity, int n);   // RefreshProxy
    void FUN_141a400d0(ProxyPtr spProxy, EntityPtr spEntity, int n);   // MoveProxy
    void FUN_141a402b0(EntityPtr spEntity);                     // RefreshLocalPlayer
    void FUN_141a407c0(ProxyPtr spProxy, EntityPtr spEntity);   // RefreshPortal
    void FUN_141a40d90(ProxyPtr spProxy, EntityPtr spEntity);   // RefreshNpc
    void FUN_141a41560(ProxyPtr spProxy, EntityPtr spEntity);   // RefreshOtherPlayer
    void FUN_141a422c0(ProxyPtr spProxy, EntityPtr spEntity);   // RefreshPet
    void FUN_141a42550();                                       // RefreshNamed
    void FUN_141a42600(MS2Ptr<CInteractObject> spObject, EntityPtr spEntity);   // UpdateNamedFrame
    void FUN_141a42800();                                       // UpdateServerData
    void FUN_141a42a70();                                       // UpdatePlayerVisibility
    void FUN_141a42bb0();                                       // RefreshMiscEntities
    void FUN_141a42fe0(ATL::CAtlArray<EntityPtr>& entities);    // GatherOverlapEntities
    void FUN_141a432a0(ProxyPtr spProxy, EntityPtr spEntity);   // UpdateOtherPlayer
    void FUN_141a43680(ProxyPtr spProxy, EntityPtr spEntity);   // UpdateNpc
    void FUN_141a43ac0(ProxyPtr spProxy, EntityPtr spEntity);   // UpdatePet
    void FUN_141a43b80(ProxyPtr spProxy, EntityPtr spEntity, bool bInit);   // UpdatePortal
    void FUN_141a44380(MS2Ptr<CInteractObject> spObject, EntityPtr spEntity);   // UpdateNamed
    bool FUN_141a44730(const efd::Point3& kPos, MS2Ptr<ASMovieClip> spClip);   // ProjectClip
    bool FUN_141a44850(EntityPtr spEntity, const int& nField, bool b);   // TryHousingPortal
    bool FUN_141a44c00(EntityPtr spEntity, const int& nField, bool b1, const CString& strIcon, const CString& strLayer, bool b2, bool b3);   // TryNpcPortal
    void FUN_141a44e60();                                       // ChangeStageSize
    void FUN_141a44ed0();                                       // ResetSelectedChannel
    void FUN_141a44f40();                                       // ApplyAlignment
    void FUN_141a45020(int nColor, float x, float y);           // SendPing
    bool FUN_141a451b0(bool bLocal, float x, float y, NiPoint3& kOut);   // PingPosition
    void FUN_141a454d0(const int& nField, const unsigned __int64& nHome);   // AddPortalHome
    void FUN_141a455e0(const int& nField, const unsigned __int64& nHome);   // RemovePortalHome
    void FUN_141a456c0(const Scaleform::GFx::FunctionHandler::Params& params);   // RedPing
    void FUN_141a45720(const Scaleform::GFx::FunctionHandler::Params& params);   // BluePing
    void FUN_141a45790(float x, float y, unsigned __int64 nId); // ShowPlayerMenu
    void FUN_141a458d0(bool b);                                 // SetInputMode
    float FUN_141a45920(PCBase* pPC);                           // PlayerHeading
    bool FUN_141a45ad0(int& nWidth, int& nHeight);              // WindowSize
    bool FUN_141a45b70(ProxyPtr spProxy);                       // ProxyVisible
    bool FUN_141a45c70(const CString& strIcon);                 // IsBossIcon
    bool FUN_141a45ce0();                                       // CanPing
    CStringW FUN_141a45d50(const unsigned __int64& nId);        // PingText
    CStringW FUN_141a45ed0(const int& nId, int nKind);          // QuestGuideText
    void FUN_141a46c90(EntityMap& map);                         // RemoveEntities
    void FUN_141a46dc0(NamedMap& map);
    void FUN_141a46ef0(ProxyMap& map);
    void FUN_141a47060(BuddyMap& map);
    void FUN_141a47190(PingMap& map);

    ShowAttrMap m_showAttrs;                                    // +0x1a8
    efd::SmartPointer<MinimapViewport> m_viewport;              // +0x1f0
    bool m_forceMinimize;                                       // +0x1f8
    bool m_fullmap;                                             // +0x1f9
    bool m_1fa;                                                 // +0x1fa
    bool m_1fb;                                                 // +0x1fb
    bool m_1fc;                                                 // +0x1fc
    float m_scale;                                              // +0x200
    int m_channel;                                              // +0x204
    NiPoint2 m_208;                                             // +0x208
    bool m_210;                                                 // +0x210
    bool m_211;                                                 // +0x211
    bool m_212;                                                 // +0x212
    MS2Ptr<AScript> m_data;                                     // +0x218
    MS2Ptr<ASMovieClip> m_clip228;                              // +0x228
    MS2Ptr<ASMovieClip> m_clip238;                              // +0x238
    MS2Ptr<ASGameEntity> m_maxPanel;                            // +0x248
    EntityPtr m_taxi;                                           // +0x258
    EntityPtr m_return;                                         // +0x268
    EntityPtr m_telescope;                                      // +0x278
    EntityPtr m_player;                                         // +0x288
    PingMap m_pings;                                            // +0x298
    ProxyMap m_proxies;                                         // +0x2c8
    BuddyMap m_buddies;                                         // +0x2f8
    NamedMap m_named;                                           // +0x340
    EntityMap m_triggers;                                       // +0x388
    EntityMap m_objects;                                        // +0x3d0
    HomeMap m_homes;                                            // +0x418
    unsigned __int64 m_460;                                     // +0x460
    int m_468;                                                  // +0x468
    Unk_MmRefreshTimer m_timer46c;                              // +0x46c
    Unk_MmRefreshTimer m_timer474;                              // +0x474
    int m_47c;                                                  // +0x47c
    SnowmanPtr<UICommon::CAlignmentInfo> m_alignment;           // +0x480
};
MS2_CHECK_SIZE(UIMinimapDialog::TShowAttr, 0x30);
MS2_CHECK_SIZE(UIMinimapDialog, 0x490);
MS2_CHECK_OFFSET(UIMinimapDialog, m_showAttrs, 0x1a8);
MS2_CHECK_OFFSET(UIMinimapDialog, m_viewport, 0x1f0);
MS2_CHECK_OFFSET(UIMinimapDialog, m_scale, 0x200);
MS2_CHECK_OFFSET(UIMinimapDialog, m_data, 0x218);
MS2_CHECK_OFFSET(UIMinimapDialog, m_maxPanel, 0x248);
MS2_CHECK_OFFSET(UIMinimapDialog, m_pings, 0x298);
MS2_CHECK_OFFSET(UIMinimapDialog, m_proxies, 0x2c8);
MS2_CHECK_OFFSET(UIMinimapDialog, m_buddies, 0x2f8);
MS2_CHECK_OFFSET(UIMinimapDialog, m_named, 0x340);
MS2_CHECK_OFFSET(UIMinimapDialog, m_triggers, 0x388);
MS2_CHECK_OFFSET(UIMinimapDialog, m_objects, 0x3d0);
MS2_CHECK_OFFSET(UIMinimapDialog, m_homes, 0x418);
MS2_CHECK_OFFSET(UIMinimapDialog, m_460, 0x460);
MS2_CHECK_OFFSET(UIMinimapDialog, m_timer46c, 0x46c);
MS2_CHECK_OFFSET(UIMinimapDialog, m_47c, 0x47c);
MS2_CHECK_OFFSET(UIMinimapDialog, m_alignment, 0x480);
