// effectservice.h - the effect data cache (CEffectData, EffectDataManager) and the effect param factory of
// client\ms2\effectservice.cpp. CEffect / CEffectParam (the runtime effect and the param base) are in effectparam.h.
// Header name assumed; member names are invented from use.
//
// Effect files live in ./Data/Xml/Effect/<name>.xml: <ms2><effect type="nif" .../>...</ms2>. Each <effect> becomes one
// CEffectParam subclass (FUN_1411a04e0 by the "type" attribute, FUN_1411a0f80); the params of one file form a CEffectData,
// which EffectDataManager caches by lower-case path.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"            // MS2Ptr<T>
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/client/ms2/effectparam.h"

// Effect param kinds (the "type" attribute; CEffectParam::m_nType).
enum
{
    kEffectNone = 0,
    kEffectNif = 1,
    kEffectSoundEvent = 2,
    kEffectSoundMusic = 3,
    kEffectMonochrome = 4,
    kEffectRadialBlur = 5,
    kEffectWeather = 6,
    kEffectSwoosh = 7,
    kEffectStatus = 8,
    kEffectLight = 9,
    kEffectFog = 10,
    kEffectRandom = 11,
    kEffectVibrate = 12,
    kEffectRibbon = 13,
    kEffectChaosLight = 14,
    kEffectTextureOverride = 15,
    kEffectLightning = 16,
    kEffectCameraMove = 17,
    kEffectScreenMasking = 18,
    kEffectGaussianBlur = 19,
    kEffectPostShimmer = 20,
    kEffectBeam = 21,
    kEffectAfterImage = 22,
};

int FUN_1411a0f80(const CString& strType);                  // 0x1411a0f80 type name -> kind (case-insensitive)
CString FUN_1411a12f0(int nType);                           // 0x1411a12f0 kind -> display name ("NULL" if unknown)
int FUN_1411a16c0(Unk_140165cf0* pNode, const char* pszName, int& nType);   // 0x1411a16c0 read a type attribute
MS2Ptr<CEffectParam> FUN_1411a04e0(const CString& strName, Unk_140165cf0* pNode);   // 0x1411a04e0 create + load one param
CEffectPtr FUN_14119eae0(CEffectParam* pParam, Unk_EffectTarget* pTarget);  // 0x14119eae0 create the runtime effect

typedef MS2Ptr<CEffectParam> CEffectParamPtr;

// 0x58 bytes, vftable 0x142eba0e8 (1 slot, ??_G 0x1411a1d70). The params of one effect file.
class CEffectData : public CCacheData
{
public:
    CEffectData();                                          // 0x14119f4b0
    virtual ~CEffectData();                                 // 0x14119f500

    ATL::CAtlList<CEffectParamPtr>& FUN_14119f540();        // 0x14119f540 the param list
    void FUN_14119f560(CEffectParam* pParam);               // 0x14119f560 append
    bool FUN_14119f5c0();                                   // 0x14119f5c0 no params
    bool FUN_14119f5f0();                                   // 0x14119f5f0 some param has ignoreOptimize
    bool FUN_14119f680();                                   // 0x14119f680 every param is ready (vfunc_3)
    void FUN_14119f710();                                   // 0x14119f710 vfunc_4 on each param that is not ready

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<CEffectParamPtr> m_params;                // +0x28
};
MS2_CHECK_SIZE(CEffectData, 0x58);
MS2_CHECK_OFFSET(CEffectData, m_params, 0x28);
typedef MS2Ptr<CEffectData> CEffectDataPtr;

// 0x68 bytes, vftable 0x142eba108 (1 slot, ??_G 0x1411a1e70). Effect file cache.
class EffectDataManager : public TSingleton<EffectDataManager>
{
public:
    EffectDataManager();                                    // 0x14119f7b0
    virtual ~EffectDataManager();                           // 0x14119f820

    CEffectDataPtr FUN_14119f870(CString strPath);          // 0x14119f870 cached load
    void FUN_14119fa60();                                   // 0x14119fa60 load every file of ./Data/Xml/Effect
    CEffectDataPtr FUN_14119fc50(const CString& strPath);   // 0x14119fc50 parse one file

public:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x08
    ATL::CRBMap<CString, CEffectDataPtr> m_map;             // +0x38 path -> data
};
MS2_CHECK_SIZE(EffectDataManager, 0x68);
MS2_CHECK_OFFSET(EffectDataManager, m_map, 0x38);

// ---- second CU: EffectNode and CEffectService ----
#include "ms2/client/ms2/lightunaffectednode.h"
class CEffectDummy;

// INodeMovement (RTTI name; 0x60 bytes, vftable 0x142f45cd8, 3 slots, dtor 0x141626240): the base of the effect
// node movements (CBirdMovement, COrbMovement) an EffectNode applies to its world transform.
class INodeMovement : public CPtred
{
public:
    virtual ~INodeMovement();                                   // 0x141626240
    virtual INodeMovement* Clone() = 0;                         // slot 1
    NiTransform FUN_141625430(double dTime, const NiTransform& kWorld);     // moved world transform

    char m_pad_18[0x48];
};
MS2_CHECK_SIZE(INodeMovement, 0x60);

// EffectNode (RTTI name; 400 bytes, vftable 0x142eba238, ms_RTTI 0x143ad1588): the root node of a runtime effect.
// Follows its parent's world transform (optionally without the parent scale, or keeping only the parent's position
// and an own rotation turned by a target object), applies an optional movement and can snap to the ground.
class EffectNode : public LightUnaffectedNode
{
public:
    EffectNode(bool bUpdateEffects, bool bTemplate);            // 0x1411a34b0
    explicit EffectNode(const CEffectDummy& kDummy);            // 0x1411a35b0 (named after the dummy, 3cb0)
    virtual ~EffectNode();                                      // 0x1411a36b0, ??_G 0x1411a3f40
    virtual const NiRTTI* GetRTTI() const;                      // slot 2, 0x1411a3fc0
    virtual NiObject* CreateClone(NiCloningProcess& kCloning);  // slot 3, 0x1411a32c0
    virtual void UpdateWorldData();                             // slot 32, 0x1411a3720
    void CopyMembers(EffectNode* pkDest, NiCloningProcess& kCloning);   // 0x1411a3380

    void FUN_1411a3cb0(const CEffectDummy& kDummy);             // transform and attach flags from a dummy
    void FUN_1411a3db0(INodeMovement* pMovement);               // set the movement
    void FUN_1411a3fa0(int bOnGround);                          // snap to the ground
    void FUN_1411a3fd0(NiAVObject* pTarget);                    // rotation target (ignored if this)
    void FUN_1411a4000(const NiMatrix3& kRot);                  // local + own rotation
    void FUN_1411a4040(const NiPoint3& kPos);                   // local + own translation

    static const NiRTTI ms_RTTI;

    MS2_LAYOUT_FRIEND;
    NiAVObject* m_pTarget;                                      // +0x138
    int m_bApplyWorldTransform;                                 // +0x140 keep only the parent position
    int m_bApplyLocalScale;                                     // +0x144 keep the parent scale
    int m_bOnGround;                                            // +0x148
    NiPoint3 m_kTranslate;                                      // +0x14c
    NiMatrix3 m_kRotate;                                        // +0x158
    int m_unk_17c;                                              // +0x17c 1, 2 when made from a dummy
    MS2Ptr<INodeMovement> m_spMovement;                         // +0x180
};
MS2_CHECK_SIZE(EffectNode, 400);
MS2_CHECK_OFFSET(EffectNode, m_pTarget, 0x138);
MS2_CHECK_OFFSET(EffectNode, m_kTranslate, 0x14c);
MS2_CHECK_OFFSET(EffectNode, m_kRotate, 0x158);
MS2_CHECK_OFFSET(EffectNode, m_spMovement, 0x180);

// ---- CEffectService ----
#include <list>
#include <string>
#include <vector>
#include <map>
#include <efd/ISystemService.h>
#include <efd/SmartPointer.h>
#include <egf/EntityID.h>
#include <NiDynamicEffect.h>
#include <NiLight.h>
#include <efd/Category.h>
namespace egf { class EntityChangeMessage; class Entity; }
#include "ms2/placeholder/iworldservicecallback.h"
class PendingEffect;
class RainDropSystem;
class GameObject;
class NiPoint3;
class NiTransform;

// The live effects of one owner id (0x20 bytes; plain new/delete, ??_G 0x1411b1330, dtor 0x1411b0140).
struct Unk_EsEffectGroup
{
    explicit Unk_EsEffectGroup(unsigned nId) : m_nId(nId) {}   // 0x1411af8b0
    ~Unk_EsEffectGroup();                                       // 0x1411b0140: FUN_1411a42b0, then the members
    void FUN_1411a42b0();                                       // drop every effect (vfunc_7) and the skip counts

    static int FUN_1411b1f50();                                 // m_sTotalEffectCount
    // @0x1411b1ed0
    unsigned FUN_1411b1ed0() { return m_nId; }
    static int m_sTotalEffectCount;                             // 0x143ad15a0 live effects of every group

    // @0x141044280
    std::list<CEffectPtr>::iterator FUN_141044280() { return m_listEffects.begin(); }
    // @0x1410443f0
    std::list<CEffectPtr>::iterator FUN_1410443f0() { return m_listEffects.end(); }
    std::list<CEffectPtr>::iterator FUN_1411b2df0(std::list<CEffectPtr>::iterator it);   // erase one effect
    void FUN_1411b3070(const char* pszName);                    // m_strName = pszName
    const std::string& FUN_1411b1e40();                         // m_strName
    void FUN_1411b15b0(CEffectPtr spEffect);                    // add an effect (counted)
    bool FUN_1411b2720();                                       // no effects left

    unsigned m_nId;                                             // +0x00
    std::list<CEffectPtr> m_listEffects;                        // +0x08
    std::string m_strName;                                      // +0x18 the effect file name
};
MS2_CHECK_SIZE(Unk_EsEffectGroup, 0x38);
typedef std::map<unsigned int, Unk_EsEffectGroup*> Unk_EsGroupMap;

// A ref-counted object the service keeps while vfunc_2 says it is alive (CAtlList +0x68); +0x28 is its entity.
class Unk_EsTracked : public NiRefObject
{
public:
    virtual bool vfunc_2();                                     // still alive
    // @0x1411b1ee0
    egf::EntityID FUN_1411b1ee0() { return m_entity; }          // the entity (+0x28)

    void* m_unk_10;                                             // +0x10
    void* m_unk_18;                                             // +0x18
    void* m_unk_20;                                             // +0x20
    egf::EntityID m_entity;                                     // +0x28
};
MS2_CHECK_OFFSET(Unk_EsTracked, m_entity, 0x28);
typedef efd::SmartPointer<Unk_EsTracked> Unk_EsTrackedPtr;

class CEffectService;
template <class T> class TSingleton;
template <> class TSingleton<CEffectService>
{
public:
    TSingleton();                                   // 0x1411aeeb0 (inline, effectservice.cpp)
    virtual ~TSingleton() { s_instance = 0; }       // 0x1411afd50
    static CEffectService* GetInstance() { return s_instance; }     // 0x1403ed280 (COMDAT of another unit)
    static CEffectService* s_instance;              // 0x143aaee08
};

// CEffectService (RTTI name; 0x1d0 bytes, class id 0x0610000c): owns the "World Effect Root" node(s), creates the
// runtime effects of effect files for a target (pending until their resources are loaded), ticks and removes them,
// plays the hit/voice sounds and keeps the area weather (rain) and the map's light list.
bool FUN_1411a4800(const CString& strName, int nArg);           // preload an effect file

class CEffectService : public efd::ISystemService, public IWorldServiceCallback, public TSingleton<CEffectService>
{
    EE_DECLARE_CLASS1(CEffectService, 0x0610000c, efd::IBase);  // the exe's SetupClassInfo chains to IBase (like PostProcessingService)
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CEffectService();                                           // 0x1411a4400
    virtual ~CEffectService();                                  // 0x1411a4650, ??_G 0x1411b1370
    virtual const char* GetDisplayName() const;                 // 0x1411a47e0
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x1411a9260
    virtual efd::AsyncResult OnInit();                          // 0x1411a92f0
    virtual efd::AsyncResult OnTick();                          // 0x1411a9e90
    virtual efd::AsyncResult OnShutdown();                      // 0x1411aa690
    // IWorldServiceCallback
    virtual void vfunc_1(int nMap);                             // 0x1411a8070 map entered: area weather and sounds
    virtual void vfunc_3(int nMap);                             // 0x1411a8210 map left: drop lights and effects

    unsigned FUN_1411a49c0(Unk_EffectTarget& kTarget);          // insert, not detached (+0x34 = 0)
    unsigned FUN_1411a4a00(Unk_EffectTarget& kTarget);          // insert an effect: its id, 0 on failure
    Unk_EsEffectGroup* FUN_1411aac40(unsigned nId);             // the group of an id (created when missing)
    CString FUN_1411aad50();                                    // the m_a190 history, "[name]" per line
    CString FUN_1411aaeb0();                                    // the m_a1b0 history, "[name]" per line
    void FUN_1411ab010(CString strName);                        // remember an inserted effect name (last 6)
    void FUN_1411ab090(CString strName);                        // remember a ... name (last 6)
    unsigned FUN_1411a4f40(CString strName, const NiPoint3& kPos);          // play a voice sound at kPos
    unsigned FUN_1411a5110(CString strCategory, CString strName, CString strExtra, int nKind, NiTransform* pXform,
        float fVolume, int nOwner);                             // play a sound event: its id, 0 when skipped
    unsigned FUN_1411a5580(int nA, int nB, int nKind, const NiPoint3& kPos, float fVolume);    // play a hit sound
    unsigned FUN_1411a5770(int nId, GameObject* pActor);        // play an actor voice
    unsigned FUN_1411a5a60(const CString& strName, const CString& strArg);  // play a field sound
    unsigned FUN_1411a5d80(const CString& strName);             // play a local player voice
    void FUN_1411a6160();                                       // stop the sound effects (vfunc_12 2/3)
    void FUN_1411a6060(unsigned nId);                           // stop (vfunc_5) the effects of an id
    void FUN_1411a66d0(unsigned nId);                           // drop the pending requests of an id
    void FUN_1411a67c0();                                       // drop every pending request
    void FUN_1411a67f0(unsigned nId, float f);                  // vfunc_6 on the effects of an id
    void FUN_1411a68f0(unsigned nId, bool b);                   // vfunc_10 on the effects of an id
    void FUN_1411a69e0(unsigned nId);                           // stop the id once every effect is done (vfunc_11)
    NiNode* FUN_1411a6b10();                                    // the root with the fewest children
    void FUN_1411a6490();                                       // drop the finished effects and the empty groups
    void FUN_1411a6be0();                                       // detach every child of the roots
    void FUN_1411a6d50(NiAVObject* pChild);                     // detach pChild from the roots
    void FUN_1411a6ea0(Unk_EsTracked* p);                       // keep p
    void FUN_1411a6f00(const egf::EntityID& id);                // drop the kept object of an entity
    void FUN_1411a7000(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);   // 8253 added
    void FUN_1411a7070(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);   // 8254 removed
    void FUN_1411a7330(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);   // 8196 updated
    void FUN_1411a7420(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);
    void FUN_1411a74a0(egf::EntityID id, egf::Entity* pEntity);  // attach the light of a light entity
    void FUN_1411a76d0();                                       // UpdateEffects on the roots
    void FUN_1411a7760(unsigned nId, ATL::CAtlArray<CEffectPtr>& aOut); // the effects of an id
    bool FUN_1411a7830();                                       // enabled
    void FUN_1411a7850(bool bEnabled);
    void FUN_1411a7870(int nIndex);                             // re-show the sky object (0 = the first)
    void FUN_1411a7960(unsigned nIndex);                        // show preloaded sky object nIndex on the root
    void FUN_1411a7ce0(bool bRain);                             // create / drop the rain
    void FUN_1411a7db0();
    void FUN_1411a7e00(const CString& strName);                 // set the area effect (stops the playing one)
    void FUN_1411a7e80(int nType);                              // pick the area effect of a weather type
    unsigned FUN_1411a85a0();                                   // the effect count
    unsigned FUN_1411a85c0();
    int FUN_1411a88c0();
    void FUN_1411a8880(int n);                                  // m_unk_188 = clamp(n, 1, 3)
    void FUN_1411aa800();                                       // insert the loaded pending requests
    void FUN_1411aab90(NiAVObject* pObject);                    // put pObject in front of the camera
    void FUN_1411a8e90();                                       // stop the sounds of the sound event effects
    void FUN_1411a8610();                                       // crash log: counters and the newest id's effects
    int FUN_1411a88e0(int nKind, float fDistance);              // the effect LOD level of a caster kind and distance
    static CString FUN_1411a8ae0(int nCaster);                  // caster kind name ("eCaster_...")
    // @0x1411b1bd0
    unsigned FUN_1411b1bd0() { return s_nLastId; }              // the newest effect id
    void FUN_1411a8cb0(const CString& strName);                 // play strName on the camera target, keep the id
    void FUN_1411a8dc0();                                       // stop every id of m_list140
    void FUN_1411a8e50(unsigned nTick);
    unsigned FUN_1411a8e70();
    bool FUN_1411a91d0(int nType);                              // false when the option hides that effect type
    static unsigned FUN_1411a9230();                            // next effect id (never 0)
    static unsigned s_nLastId;                                  // 0x1439f7038

    MS2_LAYOUT_FRIEND;
    NiNode** m_ppRoots;                                         // +0x30 the roots of the split mode (DAT_143ae2b30)
    NiNodePtr m_spRoot;                                         // +0x38 "World Effect Root"
    bool m_bEnabled;                                            // +0x40
    Unk_EsGroupMap m_mapGroups;                                 // +0x48 id -> live effects
    std::list<MS2Ptr<PendingEffect> > m_listPending;            // +0x58
    ATL::CAtlList<Unk_EsTrackedPtr> m_listTracked;              // +0x68
    std::map<egf::EntityID, NiLightPtr> m_mapLights;          // +0x98 the light entities on the roots
    ATL::CAtlList<CEffect*> m_listLooping;                      // +0xa8 refreshed by OnTick
    ATL::CAtlArray<NiAVObjectPtr> m_aPreloaded;                 // +0xd8
    NiAVObjectPtr m_spF8;                                       // +0xf8
    efd::SmartPointer<RainDropSystem> m_spRain;                 // +0x100
    unsigned m_nAreaEffect;                                     // +0x108 the area effect id (not initialised)
    CString m_strAreaEffect;                                    // +0x110 queued area effect
    CString m_strAreaEffectCur;                                 // +0x118
    CString m_strAreaEffectNext;                                // +0x120
    void FUN_141c1caa0(int n) { m_unk_128 = n; }               // 0x141c1caa0 (inline; COMDAT in worldservice.cpp)
    int m_unk_128;                                              // +0x128 = 1
    bool m_bAreaEffect;                                         // +0x12c
    int m_unk_130;                                              // +0x130
    unsigned m_nRoots;                                          // +0x134
    unsigned m_nTick;                                           // +0x138
    ATL::CAtlList<unsigned int> m_list140;                      // +0x140
    int m_unk_170;                                              // +0x170
    std::map<CString, CEffectPtr> m_map178;                     // +0x178 (not used by the own code: only built and destroyed;
                                                                //  the exe's tree dtor chain destroys pair<const CString, SmartPointer> nodes)
    int m_unk_188;                                              // +0x188 = 3
    ATL::CAtlArray<CString> m_a190;                             // +0x190
    ATL::CAtlArray<CString> m_a1b0;                             // +0x1b0
};
MS2_CHECK_SIZE(CEffectService, 0x1d0);
MS2_CHECK_OFFSET(CEffectService, m_ppRoots, 0x30);
MS2_CHECK_OFFSET(CEffectService, m_mapGroups, 0x48);
MS2_CHECK_OFFSET(CEffectService, m_mapLights, 0x98);
MS2_CHECK_OFFSET(CEffectService, m_aPreloaded, 0xd8);
MS2_CHECK_OFFSET(CEffectService, m_spRain, 0x100);
MS2_CHECK_OFFSET(CEffectService, m_strAreaEffect, 0x110);
MS2_CHECK_OFFSET(CEffectService, m_list140, 0x140);
MS2_CHECK_OFFSET(CEffectService, m_map178, 0x178);
MS2_CHECK_OFFSET(CEffectService, m_a1b0, 0x1b0);
