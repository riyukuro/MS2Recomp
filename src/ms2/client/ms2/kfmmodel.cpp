// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CKfmModel: a CEquipModel backed by a .kfm (NiActorManager
// driven by an egf entity; animation / pony-tail physics glue) plus the PhysX NxJointDesc / NxD6JointDesc inline
// COMDATs and the std::set<NiAVObjectPtr> / vector glue first used here.
// MS2-UNIT: ?\kfmmodel.cpp
// MS2-RANGE: 0x14143d580-0x141443550 .text$mn
// MS2-RANGE: 0x1400f6db0-0x1400f6f20 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$vector@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@QEAA@XZ 0x141442340 ; prop
// MS2-PIN: ??B?$SmartPointer@VIEquipModelForceApplier@@@efd@@QEBAPEAVIEquipModelForceApplier@@XZ 0x1414424d0 ; unique
// MS2-PIN: ?TypeCast@CKfmModel@@UEBA_NIPEAPEAX@Z 0x141442960 ; unique
// MS2-PIN: ?TypeCast@CKfmModel@@UEBA_NIPEAPEBX@Z 0x1414429b0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@2@XZ 0x141442a60 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@XZ 0x141442a80 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@2@XZ 0x141442a90 ; unique
// MS2-PINS-END tplpin
// AssetID(const char*, ...): the game's one COMDAT, 0x141441ec0, strips a trailing ':' (AssetID.inl, on for /D_AFXDLL)
// MS2-PIN: ?ScalePoint3@@YAPEAXPEAX0M@Z 0x1414424f0
// MS2-PIN: ??_7CKfmModel@@6BCallbackObject@NiActorManager@@@ 0x142f135d0
// MS2-FUNCTIONAL: extern-heavy; engine/game helpers are opaque FUN_ externs (see nifmodel.cpp, the same model shape
// for a single .nif). Loops over the node list at +0xf8 use the exe's iterator helpers (begin 0x141209190, end
// 0x141209360, neq 0x140b029f0, deref 0x140b02a60, inc 0x140b02a80).
#include "ms2/placeholder/ms2stdafx.h"
#include "kfmmodel.h"
#include "kfmmodel_actor.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/client/ms2/equipmodel.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/client/ms2/animationcallbackmanager.h"
#include "ms2/placeholder/citemservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/nipoint3.h"
#include <NiSequenceData.h>
#include <NiTextKeyExtraData.h>
#include <egmAnimation/AnimationService.h>
#include <egf/EntityManager.h>
#include <egf/EntityIDFactory.h>
#include <efd/Category.h>
#include <NiFloatsExtraData.h>
#include <NiKFMTool.h>
#include <NiTransform.h>
#include <NiColor.h>
#include <NiNode.h>
#include <NiMesh.h>
#include <efd/ServiceManager.h>
#include <set>
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxD6JointDesc.h>
#include <NxD6Joint.h>
#include <ecrPhysX/PropService.h>
#include <NiPhysXProp.h>
#include <NiPhysXActorDesc.h>
#include <NiPhysXD6JointDesc.h>
#include "ms2/client/ms2/equipment.h"
#include "ms2/placeholder/propertycache.h"
#include "ms2/client/ms2/pcbase.h"  // C3: PCBase (efd::DynamicCast<PCBase, GameObject>)
#include "ms2/commonfiles/os.h"
#pragma pop_macro("max")
#pragma pop_macro("min")

// ---- exe data ----
extern int DAT_143ae2b30;       // 1: actor-manager callbacks are routed through the animation service
extern int DAT_143ae2b38;       // 1: dyed / skinned model support enabled
extern char DAT_143afa4d8;      // NiNode::ms_RTTI
extern char DAT_143b01a60;      // NiPoint3::ZERO
extern char DAT_143afbbb0;      // NiMesh::ms_RTTI
extern char DAT_143afc8c0;      // RTTI of the joint-carrying scene component
extern char DAT_143afafe0;      // NiFloatsExtraData::ms_RTTI
class MS2ActorManager { public: static const NiRTTI ms_RTTI; };   // C3: was extern char DAT_143ac2fc0
extern efd::AssetID DAT_143a0acf8;   // the invalid asset id

// ---- unit-local views of exe objects ----
// The animation service (singleton behind FUN_141b6f910).
class Unk_AnimSvc : public egmAnimation::AnimationService { public: bool PlayAnimation(const egf::EntityID& entityID, const efd::utf8string& sequenceName, float fBlend, bool bForce);   // play (animationmanager.cpp)
    bool SetTargetAnimation(const egf::EntityID& kId, unsigned int nSeq, float fSpeed, bool bLoop); };   // play by sequence id (decoeditservice.cpp)
class Unk_KfmAnimSvc : public Unk_AnimSvc
{
public:
    // C3: SetTargetAnimation is Unk_AnimSvc's (the AnimationService view)
};
egmAnimation::AnimationService* FUN_141b6f910();

// Effect play request (0x70 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0). Layout as in entityvibrator.cpp.
void* FUN_1403ed2d0();
class CEffectService;
int GetObjectId(void* p);
void* GetOwnerObject(CEquipModel* p);

// ---- out-of-unit callees ----
void* GetItem(void* owner, void* out);   void* FUN_14052cd70(void* p);
int FUN_140527a20(void* p);   void* GetItemData(void* owner);class CItemData   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14053cfd0();
    bool FUN_14053d2b0();
};
void FUN_141200e30(class CEquipModel*, int);   // C3: was FUN_141200e30
void FUN_141200ca0(class CEquipModel*);   // C3: was FUN_141200ca0
void* GetOwnerPC(class CEquipModel*);   // C3: was GetOwnerPC
void* FUN_1412008e0(class CEquipModel*);   // C3: was FUN_1412008e0
void* GetItemData(class CEquipModel*);   // C3: was GetItemData
void CreateAttachNode(CEquipModel* self, CString* s);
void FUN_141202280(class CEquipModel*, class NiTransform*);   // C3: was FUN_141202280
bool FUN_1409f77a0(void* sp, int n);   void* FUN_1409475f0(void* sp);   void* FUN_1409475d0(void* sp);
void* FUN_1409478e0(void* p);
unsigned FUN_141422110(NiNode* pRoot, const CString& strPrefix, std::set<NiAVObjectPtr>* pSet);
float GetPartScale(class CEquipModel*, int);   // C3: was GetPartScale
   void FUN_141167840(NiAVObject* o, const CString& s, float f);
unsigned FUN_1405258b0(void* p);
class CItemExtraData   // C3: member view for the former free stand-ins
{
public:
    int GetCurrentRgbComponent(unsigned int);
};
void FUN_141b6f000(class NiAVObject*, int, struct Unk_Colc const&);   // C3: was FUN_141b6f000
void* FUN_141b6dea0(void* out, unsigned v);   void* ScalePoint3(void* in, void* out, float f);   void FUN_140a0a3a0(void* out, void* in);
class PC   // C3: member view for the former free stand-ins
{
public:
    struct Unk_PCEquipSet* GetEquipment();
};
void* FUN_1409f7cb0(void* p);   void* FUN_14098d8d0(void* tbl, void* key);
int FUN_141422f30(class NiAVObject*);   // C3: was FUN_141422f30
void FUN_140a0b300(void* o, bool b);
class Unk_NodeQueue   // the scene graph walk (applyeffect.cpp)
{
public:
    Unk_NodeQueue(NiAVObject* pRoot);                     // 0x14098cb80
    ~Unk_NodeQueue();                                     // 0x14098cf00
    NiAVObject* Next(bool bEnterChildren);
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};
typedef Unk_NodeQueue Unk_AeSceneIter;   // C3: was a local stand-in for Unk_NodeQueue
void FUN_1411ffee0(class CEquipModel*, double);   // C3: was FUN_1411ffee0
// (0x1402bd040 is efd::Point3::Point3())
void FUN_1411dde50(void* owner, void* self);
void FUN_141422b30(class CEquipModel* pPart, std::set<NiAVObjectPtr>& kNodes, const Vector3& kPos, const Vector3& kEuler, float fScale);

bool FUN_1401c0090(const CString& a, const CString& b);
bool Unk_IsFinite(const efd::Point3& p);   void FUN_140a38a50(egf::Entity* e, unsigned id, const void* v);
void SetCachedBoolProperty(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0
int FUN_140998250(egf::Entity* e, unsigned id, efd::AssetID* v);
void SetAssetIdProperty(egf::Entity* e, unsigned id, efd::AssetID* v);
egf::Entity* FUN_1408a9090(const void* sp);   egf::Entity* FUN_1408a9280(const void* sp);
bool FUN_1408b70b0(const void* sp, int n);   bool FUN_140965490(const void* sp, int n);
   void FUN_1401cd100(void* dst, int n);
void FUN_1408b6ec0(void* sp, void* v);   void FUN_140964eb0(void* sp, const egf::EntityPtr& v);
void FUN_1414737d0(egf::Entity* e);
class EntityWorldManager;
egf::Entity* FindEntity(egf::EntityManager* m, const egf::EntityID& id);
void* FUN_1411f91c0();   void FUN_141419f50(void* reg, void* model);   void FUN_14141a000(void* reg, void* model);
bool FUN_1413e9750(const efd::AssetID& a, const efd::AssetID& b);
class CPhysXHelper;
class Unk_AvPhysicsSvc* GetPhysXHelper();   // C3: was GetPhysXHelper
class NxGroupsMask;
class CPhysXHelper   // C3: member view for the former free stand-ins
{
public:
    void FUN_14168a540(int);
    void Unlock();
    void SetEntityCollisionGroup(egf::Entity* pEntity, unsigned short nGroup, const NxGroupsMask* pMask, int bRefresh);
    bool HasPhysicsProps(egf::Entity* pEntity);
};
class CPonyTailPhysXHelper   // C3: member view for the former free stand-ins
{
public:
    static void UpdateModelPhysXValues(class CEquipModel*, void const*);
};
// FUN_141209640 (the force-applier factory): equipmodelforceapplier.h
void FUN_140a332d0(NiTransform* p);
const NiTransform& FUN_140a33f90(void* obj);   void FUN_140aacb60(void* obj, const void* xf);
void FUN_140981070(void* obj, const void* p);   void FUN_140ddcca0(void* obj, const void* m);   void FUN_1410b2450(void* obj, float s);
void FUN_140a0b1f0(const NiMatrix3&, efd::Point3&);   // C3: rotation to euler angles (degrees, negated)
void FUN_1409f72e0(void* m);
bool FUN_140de8ea0(const efd::utf8string& a, const efd::utf8string& b);
bool FUN_1409a1140(const efd::utf8string& a, const efd::utf8string& b);
CString FUN_1409a2360(const char* psz, int n);   CString FUN_140719190(int v);
size_t FUN_14028b4c0(void* v);   CString* FUN_140fe01a0(void* v, unsigned __int64 i);
bool FUN_14028d470(float a, float b);
void FUN_14120a440(void* p, void* v);
void FUN_141205320(void* s);   void FUN_141205530(void* s);
void* FUN_141c43700(void* a, int b, unsigned c, int d);
void FUN_141c435b0(void* a, int b, unsigned c, void* pName);   // RegisterCallback(type, seq, const NiFixedString&)
bool FlushPendingSequenceData(void* p);

// Unit-local runtime-type helpers (the exe emits them as out-of-line functions next to the model code).
class Unk_KfmTyped
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void* GetClassInfoPtr();                // slot 2
};

bool IsKindOf(void* p, void* pClass)           // p's class derives from pClass
{
    void* pCur = ((Unk_KfmTyped*)p)->GetClassInfoPtr();
    while (pCur != 0) {
        if (pCur == pClass)
            return true;
        pCur = ((void*)((class NiRTTI*)(void*)(pCur))->GetBaseRTTI());
    }
    return false;
}

void* FUN_141442810(void* p, void* pClass)
{
    return IsKindOf(p, pClass) ? p : 0;
}

void* FUN_141442860(void* pClass, void* p)
{
    if (p == 0)
        return 0;
    return FUN_141442810(p, pClass);
}

struct Unk_KfmVec3 { float x, y, z; };

void* ScalePoint3(void* pIn, void* pOut, float fScale)   // pOut = *pIn * fScale
{
    NiPoint3 v = *(NiPoint3*)pIn;
    v.x *= fScale;
    v.y *= fScale;
    v.z *= fScale;
    *(Unk_KfmVec3*)pOut = *(Unk_KfmVec3*)&v;
    return pOut;
}

// AssetID(const char*, ...) (0x141441ec0) is the SDK inline, stripping in game TUs (AssetID.inl, /D_AFXDLL):
// its COMDAT copy in this unit drops a URN's trailing ':'.

















namespace ecr { class SceneGraphService; }
ecr::SceneGraphService* GetSceneGraphService();
class MS2SceneGraphService { public: void SetBucketOverride(egf::EntityID entityID, int iBucket); };   // C3: member view (0x1414f1e70)
class Unk_AkoMyPC;
template <> Unk_AkoMyPC* efd::DynamicCast<Unk_AkoMyPC, PCBase>(PCBase* Source);
void FUN_1401bf970(void* out, void* p);   bool FUN_1401b5240(void* sp, int n);   void FUN_1401b50d0(void* sp);
void FUN_1414413b0(egf::Entity* e, unsigned id, const efd::utf8string* kKey, efd::utf8string* pVal);
class NiActorManager* FUN_1413f9b70(const egf::EntityID& id);   void* FUN_1409995d0(void* p);   void* FUN_1409995c0();
void FUN_14099a7c0(void* a, void* b);   void FUN_140999170(void* a);   void SetCallbackObject(void* a, void* b, void* c);
void* GetSequenceData(void* a, unsigned b);   void* FUN_140999900(void* a);   void* FUN_1409995f0(void* a, unsigned* n);
void* FUN_1409998f0(void* a);   bool FUN_140998dc0(void* a, const char* s);
void FUN_141203e60(CEquipModel* p);
void* FUN_141d17b40(void* node, void* name);
float FUN_141d57ca0(void* ed, int i);
namespace efd { class ServiceManager; }
class Unk_GameContext { public: efd::ServiceManager* GetServiceManager(); };   // C3: unit-local view (def in camera); the service manager
class CMainSystem;
void* GetFirstRoot(class CEquipModel*);   // C3: was GetFirstRoot

#define VSLOT(o, off) ((*(void***)(o))[(off) / 8])
#define V0(R, o, off) (((R(*)(void*))VSLOT(o, off))(o))
#define V2(R, o, off, T1, a, T2, b) (((R(*)(void*, T1, T2))VSLOT(o, off))(o, a, b))
#define V1(R, o, off, T, a) (((R(*)(void*, T))VSLOT(o, off))(o, a))

#define CFG ((Unk_KfmConfig*)m_unk_20)

// ---- static data (.text$di) ----
#ifdef __clang__
// clang-cl folds the ClassInfo setup (parent = exe's CEquipModel::ms_ClassInfo) into static data (ADDR64 to an exe
// global, rejected by the post-link check): hide the setup function behind a volatile pointer to force a dynamic init.
static efd::ClassInfo::CLASSINFO_FUNC volatile s_kfmSetup = &CKfmModel::SetupClassInfo;
const efd::ClassInfo CKfmModel::ms_ClassInfo((efd::ClassInfo::CLASSINFO_FUNC)s_kfmSetup);
#else
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CKfmModel);
#endif

// @0x1400f6dd0
CString g_astrKfmNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
// @0x1400f6e90
CString g_strKfmSkill("skill");
// @0x1400f6ec0
CString g_strKfmStun("stun");
// @0x1400f6ef0
efd::Category g_catKfm(0ull);

// ---- CKfmModel ----

// @0x14143d580
CKfmModel::CKfmModel(MS2Ptr<CEquipItem> spOwner, void* p18, void* p20)
    : CEquipModel(spOwner, p18, p20), m_nUpdateHR(0), m_nUpdateTransform(0), m_bPhysicsLoaded(0), m_spEntity(0),
      m_pPhysics(0)
{
}

// @0x14143d680
CKfmModel::~CKfmModel()
{
    DestroyEntity();
    m_pPhysics = 0;
}

// @0x14143d730
int CKfmModel::vfunc_4(CString strPath)
{
    if (strPath.IsEmpty())
        return 0;
    if (m_str38 == strPath)
        return 1;
    efd::AssetID kCur;
    efd::AssetID kNew((const char*)strPath, 0, efd::AssetID::NEVER_CACHE);
    if (m_spEntity.operator!=((egf::Entity*)0) != 0) {
        if (m_spEntity.operator->()->GetPropertyValue<efd::AssetID>(0x12383cea, kCur) == 0 && kCur.operator==(kNew) != 0)
            return 1;
    }
    CreateEntity();
    m_str38 = strPath;
    m_unk_f0.operator=((NiAVObject*)0);
    m_nState = 0;
    m_spNode.operator=((NiNode*)0);
    SetAssetIdProperty(m_spEntity.operator->(), 0x12383cea, &kNew);
    bool bFlag = false;
    SetCachedBoolProperty((class Unk_CachedEntity*)(m_spEntity.operator->()), 0xa0b6b179, bFlag);
    if (TSingleton<EntityWorldManager>::GetInstance()->FindEntity(GetEntityID()) != 0)
        return 1;
    ApplyAnimNames();
    if (TSingleton<EntityWorldManager>::GetInstance()->AddEntity(m_spEntity.operator egf::Entity*(), 0) != 0)
        (reinterpret_cast<const MS2Ptr<CEquipItem>&>(m_spOwner).operator->())->AddModel(this);
    return 1;
}

// @0x14143da90
void CKfmModel::vfunc_5()
{
    MS2Ptr<CEquipModel> spKeep(this);    // keeps the model alive through the teardown
    CEquipModel::vfunc_5();
    DestroyEntity();
    m_pPhysics = 0;
}

// @0x14143db00
int CKfmModel::vfunc_6()
{
    m_nState = 1;
    if (!m_str38.IsEmpty() && efd::DynamicCast<Unk_AkoMyPC, PCBase>((PCBase*)GetOwnerPC((class CEquipModel*)(this))) != 0) {
        efd::AssetID kId((const char*)m_str38, 0, efd::AssetID::NEVER_CACHE);
        efd::vector<egmAnimation::KFMCache::KFMCacheHandle> kHandles;
        if (FUN_141b6f910()->Cache(kId, (egmAnimation::KFMCache::IKFMCacheRequestData*)0, g_catKfm, kHandles) == 0)
            FUN_141b6f910()->UnCacheHandles(kHandles);
    }
    void* pComp = FUN_141442860((void*)&MS2ActorManager::ms_RTTI, GetActorManager());
    if (pComp != 0)
        FlushPendingSequenceData(pComp);
    if (m_spEntity.operator egf::Entity*() != 0) {
        FUN_141203e60(this);
        if (DAT_143ae2b30 != 0)
            ((MS2SceneGraphService*)(void*)GetSceneGraphService())->SetBucketOverride(((egf::Entity*)(void const*)(m_spEntity.operator->()))->GetEntityID(), 3);
        void* pActorMgr = FUN_1413f9b70(((egf::Entity*)(void const*)(m_spEntity.operator->()))->GetEntityID());
        if (pActorMgr != 0) {
            if (DAT_143ae2b30 != 0) {
                AnimationCallbackManager::GetInstance()->SetCallbackObject((NiActorManager*)pActorMgr, static_cast<NiActorManager::CallbackObject*>(this));
            } else {
                ((NiActorManager*)pActorMgr)->SetCallbackObject(0);
                ((NiActorManager*)pActorMgr)->ClearAllRegisteredCallbacks();
                ((NiActorManager*)pActorMgr)->SetCallbackObject(static_cast<NiActorManager::CallbackObject*>(this));
            }
            NiKFMTool* pKfm = ((NiActorManager*)pActorMgr)->GetKFMTool();
            unsigned int* pIds = 0;
            unsigned int nIds;
            pKfm->GetSequenceIDs(pIds, nIds);
            for (unsigned int i = 0; i < nIds; ++i) {
                unsigned int nSeqId = pIds[i];
                NiSequenceData* pSeq = ((NiActorManager*)pActorMgr)->GetSequenceData(nSeqId);
                if (pSeq == 0)
                    continue;
                NiTextKeyExtraData* pTextKeys = pSeq->GetTextKeys();
                unsigned int nKeys = 0;
                char* pKey = (char*)pTextKeys->GetKeys(nKeys);
                ((NiActorManager*)pActorMgr)->RegisterCallback((NiActorManager::EventType)0, nSeqId, (NiTextKeyMatch*)0);
                ((NiActorManager*)pActorMgr)->RegisterCallback((NiActorManager::EventType)4, nSeqId, (NiTextKeyMatch*)0);
                for (unsigned int k = 0; k < nKeys; ++k) {
                    const NiFixedString& kName = ((NiTextKey*)(pKey + (unsigned long long)k * 0x10))->GetText();
                    if (kName == "start" || kName == "end")
                        continue;
                    ((NiActorManager*)pActorMgr)->RegisterCallback((NiActorManager::EventType)3, nSeqId, kName);
                }
            }
            if (pIds != 0)
                efd::_Free(pIds, 0xffffffffffffffffull);
        }
    }
    FUN_141440bc0();
    FUN_141200ca0((class CEquipModel*)(this));
    vfunc_10();
    vfunc_11();
    {
        efd::utf8string kIdle("Idle_A");
        CString strA("");
        CString strB("");
        PlayAnimationWithFallback(strB, strA, kIdle, 1.0f, false);
    }
    return 1;
}

// @0x14143e090
int CKfmModel::vfunc_7()
{
    FUN_141200e30((class CEquipModel*)(this), 1);
    vfunc_5();
    return 1;
}

// @0x14143e0d0
int CKfmModel::vfunc_33()
{
    m_bPhysicsLoaded = 1;
    m_pPhysics = CreateForceApplier(this);
    vfunc_31();
    return 1;
}

// @0x14143e160
void CKfmModel::vfunc_34()
{
    vfunc_6();
}

// @0x14143e190
int CKfmModel::vfunc_8() { return 1; }

// @0x14143e1b0
int CKfmModel::vfunc_9()
{
    if (!((class CPhysXHelper*)GetPhysXHelper())->HasPhysicsProps(m_spEntity.operator egf::Entity*()))
        return m_nState;
    return m_nState != 0 && m_bPhysicsLoaded != 0;
}

// @0x14143e240
void CKfmModel::vfunc_10()
{
    m_nUpdateHR = (vfunc_9() == 0);
    if (m_nUpdateHR != 0)
        return;
    if (((class CItemData*)(void*)((reinterpret_cast<const MS2Ptr<CEquipItem>&>(m_spOwner).operator->())->GetItemData()))->FUN_14053cfd0()) {
        {
            CString s("HR:0");
            FUN_141167840((NiAVObject*)vfunc_14(), s, GetPartScale((class CEquipModel*)(this), 0));
        }
        {
            CString s("HR0:0");
            FUN_141167840((NiAVObject*)vfunc_14(), s, GetPartScale((class CEquipModel*)(this), 0));
        }
        {
            CString s("HR1:1");
            FUN_141167840((NiAVObject*)vfunc_14(), s, GetPartScale((class CEquipModel*)(this), 1));
        }
    }
}

class CItem;
   // CEquipItem::GetItem
// (Unk_KfmColor was a view of NiColor; its ScalePoint3 is efd::Color::operator*(float) const 0x1414424f0)
//
//
//
//
NiColor FUN_141b6dea0(unsigned nColor);

// @0x14143e3e0
void CKfmModel::vfunc_11()
{
    m_nUpdateTransform = (vfunc_9() == 0);
    if (m_nUpdateTransform != 0)
        return;
    void* pPartList = ((void*)((class CItem*)(void*)((reinterpret_cast<const MS2Ptr<CEquipItem>&>(m_spOwner).operator->())->GetItem().operator->()))->FUN_140527870());
    if (pPartList == 0)
        return;
    for (int i = 0; i < 3; ++i) {
        NiColor kColor = FUN_141b6dea0(((class CItemExtraData*)(void*)(pPartList))->GetCurrentRgbComponent(i));
        if (i == 1) {
            NiColor kScaled(FUN_141b6dea0(((class CItemExtraData*)(void*)(pPartList))->GetCurrentRgbComponent(0)) * 1.3f);
            kColor = kScaled;
        }
        void* pRoot = vfunc_14();
        if (pRoot != 0)
            FUN_141b6f000((class NiAVObject*)(pRoot), i, *(struct Unk_Colc const*)(&kColor));
        std::set<NiAVObjectPtr>& rRange = m_unk_f8;
        std::set<NiAVObjectPtr>::iterator itEnd = rRange.end();
        for (std::set<NiAVObjectPtr>::iterator it = rRange.begin(); it != itEnd; ++it) {
            NiAVObjectPtr sp(*it);
            if (sp.operator NiAVObject*() != 0)
                FUN_141b6f000((class NiAVObject*)(sp.operator NiAVObject*()), i, *(struct Unk_Colc const*)(&kColor));
        }
    }
    Unk_ModelActor* p = (Unk_ModelActor*)GetOwnerPC((class CEquipModel*)(this));
    if (p != 0)
        p->vfunc_139();
}

// @0x14143e670
class CItemData;
   // the part name (by value)
void CKfmModel::vfunc_12()
{
    MS2Ptr<CItemData> spItem((CItemData*)GetItemData((class CEquipModel*)(this)));
    if (spItem == 0)
        return;
    const CString& strName = ((CEquipModel*)this)->GetPartName();
    if (strName.IsEmpty())
        return;
    CreateAttachNode(this, (CString*)&strName);
    if (m_spNode.operator==((NiNode*)0) != 0)
        return;
    std::set<NiAVObjectPtr> kSet;
    if (FUN_141422110((NiNode*)vfunc_14(), *(const CString*)((char*)m_unk_20 + 8), &kSet) != 0) {
        std::set<NiAVObjectPtr>& rRange = kSet;
        std::set<NiAVObjectPtr>::iterator itEnd = rRange.end();
        for (std::set<NiAVObjectPtr>::iterator it = rRange.begin(); it != itEnd; ++it) {
            NiAVObjectPtr sp(*it);
            if (sp.operator NiAVObject*() != 0) {
                if (IsDefaultScale()) {
                    NiNode* pParent = (NiNode*)m_spNode.operator->();
                    pParent->AttachChild((NiAVObject*)sp.operator NiAVObject*(), true);
                }
                m_unk_f8.insert(sp);
            }
        }
    }
}

// @0x14143e900
void CKfmModel::vfunc_13()
{
    if (CFG->m_bHead == 0)
        return;
    void* pRootNode = FUN_1412008e0((class CEquipModel*)(this));
    if (pRootNode == 0)
        return;
    NiTransform kXf;
    kXf.MakeIdentity();
    FUN_141202280((class CEquipModel*)(this), &kXf);
    Unk_ModelActor* pActor = (Unk_ModelActor*)GetOwnerPC((class CEquipModel*)(this));
    if (pActor == 0)
        return;
    MS2Ptr<CItem> spItem = (reinterpret_cast<const MS2Ptr<CEquipItem>&>(m_spOwner).operator->())->GetItem();
    if (spItem.operator!() != 0)
        return;
    int nResult = reinterpret_cast<CEquipment*>(((class PC*)(void*)(pActor))->GetEquipment())->FUN_1411e99a0(spItem->FUN_140527a20(),
                                ((CEquipModel*)this)->GetPartName(), spItem->HasSkin(),
                                ((class CItemData*)(void*)(((void*)((class CItem*)(void*)(spItem.operator->()))->FUN_140527840())))->FUN_14053d2b0());
    if (nResult != 0) {
        NiNode* pTarget;
        {
            NiFixedString kName("Bip01 Head");
            pTarget = (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, ((NiActorManager*)pRootNode)->GetNIFRoot()->GetObjectByName(kName));
        }
        if (pTarget == 0)
            return;
        std::set<NiAVObjectPtr> kSet;
        if (FUN_141422110((NiNode*)vfunc_14(), *(const CString*)((char*)m_unk_20 + 8), &kSet) != 0) {
            std::set<NiAVObjectPtr>& rRange = kSet;
            std::set<NiAVObjectPtr>::iterator itEnd = rRange.end();
            for (std::set<NiAVObjectPtr>::iterator it = rRange.begin(); it != itEnd; ++it) {
                NiAVObjectPtr sp(*it);
                sp.operator->()->SetLocalTransform(kXf * sp.operator->()->GetLocalTransform());
                pTarget->AttachChild((NiAVObject*)sp.operator NiAVObject*(), true);
                m_unk_f8.insert(sp);
            }
        }
    }
}

// @0x14143ee10
void* CKfmModel::vfunc_14()
{
    NiActorManager* pMgr = GetActorManager();
    if (pMgr != 0)
        m_unk_f0.operator=(pMgr->GetNIFRoot());
    return m_unk_f0.operator NiAVObject*();
}

// @0x14143ed00
int CKfmModel::vfunc_15()
{
    void* pRoot = vfunc_14();
    if (pRoot != 0 && FUN_141422f30((class NiAVObject*)(pRoot)) != 0)
        return 1;
    std::set<NiAVObjectPtr>& rRange = m_unk_f8;
    std::set<NiAVObjectPtr>::iterator itEnd = rRange.end();
    for (std::set<NiAVObjectPtr>::iterator it = rRange.begin(); it != itEnd; ++it) {
        NiAVObjectPtr sp(*it);
        if (sp.operator NiAVObject*() != 0 && FUN_141422f30((class NiAVObject*)(sp.operator NiAVObject*())) != 0)
            return 1;
    }
    return 0;
}

// @0x14143ee70
void CKfmModel::vfunc_16()
{
    vfunc_10();
    if (CFG->m_bPhysics != 0) {
        FUN_141200e30((class CEquipModel*)(this), 0);
        FUN_141440bc0();
        FUN_141200ca0((class CEquipModel*)(this));
    }
    vfunc_31();
}

// @0x14143eee0
void CKfmModel::vfunc_17()
{
    CEquipModel::vfunc_17();
    bool bVisible = (m_nState != 0 && vfunc_20() != 0) ? true : false;
    bool bHide = (bVisible == 0);
    std::set<NiAVObjectPtr>& rRange = m_unk_f8;
    std::set<NiAVObjectPtr>::iterator itEnd = rRange.end();
    for (std::set<NiAVObjectPtr>::iterator it = rRange.begin(); it != itEnd; ++it) {
        NiAVObjectPtr sp(*it);
        Unk_AeSceneIter kIter((NiAVObject*)((NiAVObject*)sp.operator NiAVObject*()));
        NiAVObject* pObject;
        while ((pObject = kIter.Next(true)) != 0) {
            void* pMesh = NiObject::DynamicCast(&NiMesh::ms_RTTI, pObject);
            if (pMesh != 0)
                ((NiAVObject*)pMesh)->SetAppCulled(bHide);
        }
    }
    Unk_AeSceneIter kIter((NiAVObject*)((NiAVObject*)vfunc_14()));
    NiAVObject* pObject;
    while ((pObject = kIter.Next(true)) != 0) {
        void* pMesh = NiObject::DynamicCast(&NiMesh::ms_RTTI, pObject);
        if (pMesh != 0)
            ((NiAVObject*)pMesh)->SetAppCulled(bHide);
    }
    SetCachedBoolProperty((class Unk_CachedEntity*)(m_spEntity.operator->()), 0xa0b6b179, bVisible);
}

// @0x14143f110
void CKfmModel::vfunc_18()
{
    vfunc_5();
}

// @0x14143f140
void CKfmModel::vfunc_19(double fTime)
{
    FUN_1411ffee0((class CEquipModel*)(this), fTime);
    if ((IEquipModelForceApplier*)m_pPhysics != 0) {
        ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)GetPhysXHelper())))->FUN_14168a540(1);
        m_pPhysics->OnTick(fTime);
        ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)GetPhysXHelper())))->Unlock();
    }
    if (m_nUpdateHR != 0)
        vfunc_10();
    if (m_nUpdateTransform != 0)
        vfunc_11();
    if (m_b111 != 0) {
        if (vfunc_20() != 0) {
            if (GetOwnerPC((class CEquipModel*)(this)) != 0)
                vfunc_32(((Unk_ModelActor*)GetOwnerPC((class CEquipModel*)(this)))->vfunc_65());
            m_b111 = false;
        }
    }
    FUN_141440f60();
}

// @0x14143f2a0
void CKfmModel::vfunc_32(int n)
{
    CEquipModel::vfunc_32(n);
    egf::EntityID kId = GetEntityID();
    efd::utf8string kAnim(n != 0 ? "Attack_Idle_A" : "Idle_A");
    efd::utf8string kCur = FUN_141b6f910()->GetCurrentAnimation(kId);
    if (FUN_141b6f910()->GetAnimationIdFromName(kId, kAnim) != NiActorManager::INVALID_SEQUENCE_ID) {
        bool bSame = (kAnim == kCur);
        static_cast<Unk_KfmAnimSvc*>(FUN_141b6f910())->PlayAnimation(kId, kAnim, 1.0f, bSame);
    }
}

// @0x14143f970
void CKfmModel::vfunc_22(float f)
{
    m_fScale44 = f;
    if (m_spEntity.operator egf::Entity*() != 0)
        reinterpret_cast<Unk_CachedEntity*>(m_spEntity.operator->())->SetPropertyValue<float>(0x2d7cad2d, m_fScale44);
    ScalePhysXJointAnchors();
}

// @0x14143f9f0
void CKfmModel::vfunc_24(const NiPoint3& p)
{
    if (!Unk_IsFinite(*(const efd::Point3*)&p))
        return;
    m_pos48 = p;
    if (m_spEntity.operator egf::Entity*() != 0)
        m_spEntity.operator->()->SetPropertyValue<efd::Point3>(0xfd95ca52, m_pos48);
}

// @0x14143fa80
void CKfmModel::vfunc_26(const NiPoint3& p)
{
    if (!Unk_IsFinite(*(const efd::Point3*)&p))
        return;
    m_pos54 = p;
    if (m_spEntity.operator egf::Entity*() != 0)
        m_spEntity.operator->()->SetPropertyValue<efd::Point3>(0x68c7c29d, m_pos54);
}

// CKfmModel's vfunc_24/vfunc_26 as the exe calls them here: the point goes by value (16-aligned arg copy).
class Unk_KfmModelSlots
{
public:
#define MS2_KFM_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_KFM_SLOTS(0, 1, 2, 3, 4) MS2_KFM_SLOTS(5, 6, 7, 8, 9) MS2_KFM_SLOTS(10, 11, 12, 13, 14) MS2_KFM_SLOTS(15, 16, 17, 18, 19)
#undef MS2_KFM_SLOTS
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(NiPoint3 p);                                      // 24 0x14143f9f0
    virtual void vfunc_25();
    virtual void vfunc_26(NiPoint3 p);                                      // 26 0x14143fa80
};

// @0x14143fb10
void CKfmModel::vfunc_29(void* pPos, void* pRotDeg, float fScale)
{
    reinterpret_cast<Unk_KfmModelSlots*>(this)->vfunc_24(*(NiPoint3*)pPos);
    reinterpret_cast<Unk_KfmModelSlots*>(this)->vfunc_26(*(NiPoint3*)pRotDeg);
    vfunc_22(fScale);
    std::set<NiAVObjectPtr> kSet;
    FUN_141422110((NiNode*)vfunc_14(), *(const CString*)((char*)m_unk_20 + 8), &kSet);
    FUN_141422b30((class CEquipModel*)this, kSet, *(const Vector3*)&efd::Point3::ZERO, *(const Vector3*)&efd::Point3::ZERO, 1.0f);
}

// @0x14143fc70
void CKfmModel::vfunc_28(void* pPos, void* pMatrix3, float fScale)
{
    float x, y, z;
    reinterpret_cast<efd::Point3*>(&x)->efd::Point3::Point3();     // NiPoint3() on the x, y, z angles
    ((efd::Matrix3*)pMatrix3)->ToEulerAnglesXYZ(x, y, z);
    x = (x * 180.0f) / 3.1415927f;
    y = (y * 180.0f) / 3.1415927f;
    z = (z * 180.0f) / 3.1415927f;
    vfunc_29(pPos, &x, fScale);
}

// NiMatrix3(const efd::Matrix3&) as the exe calls it
struct Unk_KfmMatrix3 { float m00, m01, m02, m10, m11, m12, m20, m21, m22; };

// @0x14143fd30
void CKfmModel::vfunc_30(void* pPos, void* pRot, float fScale)
{
    NiTransform kXf;
    kXf.m_Translate = *reinterpret_cast<const efd::Point3*>(pPos);
    Unk_KfmMatrix3 kRot;
    reinterpret_cast<Unk_NiMatrix3*>(&kRot)->Unk_NiMatrix3::Unk_NiMatrix3(*(const Unk_EfdMatrix3*)pRot);
    kXf.m_Rotate = *(NiMatrix3*)&kRot;
    kXf.m_fScale = fScale;
    ((NiAVObject*)vfunc_14())->SetLocalTransform(kXf);
}

// @0x14143fe10
void CKfmModel::vfunc_31()
{
    if (vfunc_9() == 0)
        return;
    if (((class CItemData*)(void*)(GetItemData((class CEquipModel*)(this))))->FUN_14053cfd0() == 0)
        return;
    NxGroupsMask kMask;
    kMask.bits0 = 0; kMask.bits1 = 0; kMask.bits2 = 0; kMask.bits3 = 0;
    ((class CPhysXHelper*)GetPhysXHelper())->SetEntityCollisionGroup(TSingleton<EntityWorldManager>::GetInstance()->FindEntity(GetEntityID()), 0, &kMask, 0);
    if (CFG->m_bPhysics != 0)
        CPonyTailPhysXHelper::UpdateModelPhysXValues((class CEquipModel*)(this), (void const*)((char*)m_unk_20 + 0xb8));
}

// @0x14143ff20
egf::EntityPtr CKfmModel::GetEntity()
{
    return m_spEntity;
}

// @0x14143ff70
egf::EntityID CKfmModel::GetEntityID()
{
    if (m_spEntity.operator egf::Entity*() != 0)
        return m_spEntity.operator->()->GetEntityID();
    return egf::EntityID((efd::UInt64)0);
}

// @0x14143fff0
efd::AssetID CKfmModel::GetAssetId()
{
    efd::AssetID kCur;
    if (m_spEntity.operator->()->GetPropertyValue<efd::AssetID>(0x12383cea, kCur) == 0)
        return kCur;
    return DAT_143a0acf8;
}

// @0x1414400d0
NiActorManager* CKfmModel::GetActorManager()
{
    return FUN_141b6f910()->GetActorManager(GetEntityID());
}

// @0x141440110
void CKfmModel::SetPonyTailDamping(const CString& strBone, float f)
{
    for (unsigned int i = 0; i < 4; ++i) {
        Unk_KfmPonyTail* p = &CFG->m_aPonyTail[i];
        if ((p->m_strBone == strBone) != 0)
            p->m_fDamping = f;
    }
    vfunc_31();
}

// @0x1414401b0
void CKfmModel::SetPonyTailOffset(const CString& strBone, float x, float y, float z)
{
    for (unsigned int i = 0; i < 4; ++i) {
        Unk_KfmPonyTail* p = &CFG->m_aPonyTail[i];
        if ((p->m_strBone == strBone) != 0) {
            p->m_fX = x;
            p->m_fY = y;
            p->m_fZ = z;
        }
    }
    vfunc_31();
}

// @0x141440270
void CKfmModel::PlaySequence(unsigned int nSeq)
{
    bool bEmpty = FUN_140de8ea0(FUN_141b6f910()->GetAnimationNameFromId(GetEntityID(), nSeq), efd::utf8string::NullString());
    if (bEmpty)
        static_cast<Unk_KfmAnimSvc*>(FUN_141b6f910())->SetTargetAnimation(GetEntityID(), nSeq, 1.0f, false);
}

// @0x141440380
void CKfmModel::PlayAnimationWithFallback(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend,
    bool b)
{
    const egf::EntityID& kId = GetEntityID();
    efd::utf8string kA((const char*)FUN_1409a2360((const char*)strA, 0));
    if (FUN_141b6f910()->GetAnimationIdFromName(kId, kA) != NiActorManager::INVALID_SEQUENCE_ID) {
        static_cast<Unk_KfmAnimSvc*>(FUN_141b6f910())->PlayAnimation(kId, kA, fBlend, b);
        return;
    }
    efd::utf8string kB = (const char*)FUN_1409a2360((const char*)strB, 0) + kDefault;
    if (FUN_141b6f910()->GetAnimationIdFromName(kId, kB) != NiActorManager::INVALID_SEQUENCE_ID) {
        static_cast<Unk_KfmAnimSvc*>(FUN_141b6f910())->PlayAnimation(kId, kB, fBlend, b);
        return;
    }
    if (FUN_141b6f910()->GetAnimationIdFromName(kId, kDefault) != NiActorManager::INVALID_SEQUENCE_ID) {
        static_cast<Unk_KfmAnimSvc*>(FUN_141b6f910())->PlayAnimation(kId, kDefault, fBlend, b);
        return;
    } else {
        bool bFound;
        {
            efd::utf8string kIdle("Idle_A");
            bFound = FUN_141b6f910()->GetAnimationIdFromName(kId, kIdle) != NiActorManager::INVALID_SEQUENCE_ID;
        }
        if (bFound) {
            efd::utf8string kIdle2("Idle_A");
            static_cast<Unk_KfmAnimSvc*>(FUN_141b6f910())->PlayAnimation(kId, kIdle2, fBlend, b);
        }
    }
}

// @0x1414406d0
void CKfmModel::AnimActivated(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float) {}

// @0x1414406f0
void CKfmModel::AnimDeactivated(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float) {}

// @0x141440710
void CKfmModel::AnimCompleted(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float) {}

// @0x141440730
void CKfmModel::TextKeyEvent(NiActorManager*, NiActorManager::SequenceID, const NiFixedString& kTextKey,
    const NiTextKeyMatch*, NiControllerSequence*, float)
{
    CString strKey(kTextKey.operator const char*());
    if (strKey.Find("effect_", 0) == 0) {
        void* pActor = efd::DynamicCast<PCBase, GameObject>(static_cast<GameObject*>(GetOwnerObject(this)));
        NoticeMessage kReq;
        kReq.m_strName = strKey.Right(strKey.GetLength() - 7);
        kReq.m_nObject = ((class WorldService*)(void*)(WorldService::GetInstance()))->GetObjectKind((class Unk_WsC_GameObj*)(pActor));
        kReq.m_spNode.operator=((NiAVObject*)NiObject::DynamicCast(&NiNode::ms_RTTI, (NiObject*)vfunc_14()));
        if (pActor != 0)
            kReq.SetActor(((GameObject*)pActor)->GetObjectId());
        TSingleton<CEffectService>::GetInstance()->InsertEffect(*(class Unk_EffectTarget*)(&kReq));
    }
}

// @0x1414408c0
void CKfmModel::EndOfSequence(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float) {}

// @0x1414408e0
void CKfmModel::CreateEntity()
{
    DestroyEntity();
    m_spEntity.operator=(
        TSingleton<EntityWorldManager>::GetInstance()->FactoryEntity(FUN_141201780(), egf::EntityIDFactory::GetNextID(), true));
    TSingleton<CItemService>::GetInstance()->RegisterModel(this);
}

// @0x1414409f0
void CKfmModel::DestroyEntity()
{
    if (m_spEntity.operator==((egf::Entity*)0))
        return;
    TSingleton<CItemService>::GetInstance()->UnregisterModel(this);
    CMainSystem::DestroyEntity(m_spEntity.operator egf::Entity*());
    m_spEntity.operator=((egf::Entity*)0);
}

// @0x141440a70
void CKfmModel::ApplyAnimNames()
{
    std::vector<CString>& kNames = CFG->m_arrAnimNames;
    for (unsigned int i = 0; i < kNames.size(); ++i) {
        efd::utf8string kKey((const char*)FUN_140719190(i));
        efd::utf8string kVal((const char*)((const std::vector<CString>&)kNames)[i]);
        FUN_1414413b0(m_spEntity.operator->(), 0xa75781ca, &kKey, &kVal);
    }
}

// @0x141440bc0
void CKfmModel::FUN_141440bc0()
{
    if (CFG->m_bPhysics == 0) return;
    if (((class CItemData*)(void*)((reinterpret_cast<const MS2Ptr<CEquipItem>&>(m_spOwner).operator->())->GetItemData()))->FUN_14053cfd0()) {
        void* pData = ((void*)((class CItem*)(void*)((reinterpret_cast<const MS2Ptr<CEquipItem>&>(m_spOwner).operator->())->GetItem().operator->()))->FUN_140527870());
        if (pData != 0) {
            float fScale = ((float*)((char*)pData + 0x58))[0];
            efd::Point3 kPos = ((efd::Point3*)((char*)pData + 0x60))[CFG->m_nIndex];
            efd::Point3 kRot = ((efd::Point3*)((char*)pData + 0x78))[CFG->m_nIndex];
            std::set<NiAVObjectPtr> kSet;
            FUN_141422110((NiNode*)vfunc_14(), *(const CString*)((char*)m_unk_20 + 8), &kSet);
            efd::Matrix3 kMat;
            kMat.FromEulerAnglesXYZ((kRot.x * 3.1415927f) / 180.0f, (kRot.y * 3.1415927f) / 180.0f,
                (kRot.z * 3.1415927f) / 180.0f);
            std::set<NiAVObjectPtr>& rRange = kSet;
            std::set<NiAVObjectPtr>::iterator itEnd = rRange.end();
            for (std::set<NiAVObjectPtr>::iterator it = rRange.begin(); it != itEnd; ++it) {
                NiAVObjectPtr sp(*it);
                sp->SetTranslate(kPos);
                sp->SetRotate(kMat);
                sp->SetScale(fScale);
            }
            vfunc_22(fScale);
        }
    }
}

// @0x141440f20
bool CKfmModel::IsDefaultScale()
{
    if (m_unk_20 == 0)
        return false;
    return FUN_14028d470(CFG->m_fScale, 1.0f);
}

// @0x141440f60
void CKfmModel::FUN_141440f60()
{
    if (IsDefaultScale())
        return;
    if (m_spNode.operator NiNode*() == 0)
        return;
    NiTransform* pXf = (NiTransform*)&m_spNode.operator->()->GetWorldTransform();
    NiPoint3 kTrans = pXf->m_Translate;
    reinterpret_cast<Unk_KfmModelSlots*>(this)->vfunc_24(kTrans);
    efd::Point3 kRot;
    FUN_140a0b1f0(reinterpret_cast<const NiMatrix3&>(pXf->m_Rotate), reinterpret_cast<efd::Point3&>(kRot.x));
    reinterpret_cast<Unk_KfmModelSlots*>(this)->vfunc_26(reinterpret_cast<NiPoint3&>(kRot));
}

// The prop snapshot's joint accessors (the joint array is at +0x30), the same calls as
// equipmodelforceapplier.cpp's.
typedef NiPhysXPropDesc Unk_WindPropDesc;   // its joint accessors, GetJointCount 0x14120ac30 and GetJointAt 0x14120abd0
// {
// public:
//     unsigned GetActorCount() const;                             // 0x14120ac30
//     NiPhysXActorDescPtr GetActorAt(unsigned uiIndex);           // 0x14120abd0
// };

// @0x14143f3d0
void CKfmModel::ScalePhysXJointAnchors()
{
    if (CFG->m_bPhysics != 0 || CFG->m_bHead != 0 || FUN_14028d470(CFG->m_fScale, 1.0f) == 0) {
        efd::ServiceManager* pServiceManager = reinterpret_cast<Unk_GameContext*>((char*)TSingleton<CMainSystem>::GetInstance() + 8)->GetServiceManager();
        ecrPhysX::PropService* pService = pServiceManager->GetSystemServiceAs<ecrPhysX::PropService>();
        unsigned nProps = pService->GetNumProps(GetEntityID());
        NiObjectNET* pNode = (NiObjectNET*)GetFirstRoot((class CEquipModel*)(this));
        if (pNode == 0)
            return;
        for (unsigned i = 0; i < nProps; ++i) {
            NiPhysXProp* pProp = pService->GetPropAt(GetEntityID(), i);
            if (pProp == 0)
                continue;
            Unk_WindPropDesc* pDesc = (Unk_WindPropDesc*)pProp->GetSnapshot();
            if (pDesc == 0)
                continue;
            unsigned nCount = pDesc->GetJointCount();
            for (unsigned j = 0; j < nCount; ++j) {
                NiPhysXD6JointDesc* pJointDesc = (NiPhysXD6JointDesc*)NiObject::DynamicCast(&NiPhysXD6JointDesc::ms_RTTI, pDesc->GetJointAt(j));
                NxD6Joint* pJoint;
                if (pJointDesc != 0 && (pJoint = pJointDesc->GetJoint()) != 0) {
                    NxD6JointDesc kDesc;
                    pJoint->saveToDesc(kDesc);
                    CString strName(pJoint->getName());
                    for (int k = 0; k < 2; ++k) {
                        CString strKey;
                        strKey.Format("%s%d", (const char*)strName, k);
                        NiFloatsExtraData* pExtra;
                        {
                            NiFixedString kFixed((const char*)strKey);
                            pExtra = (NiFloatsExtraData*)NiObject::DynamicCast(&NiFloatsExtraData::ms_RTTI, pNode->GetExtraData(kFixed));
                        }
                        if (pExtra != 0) {
                            kDesc.localAnchor[k].x = pExtra->GetValue(0) * m_fScale44;
                            kDesc.localAnchor[k].y = pExtra->GetValue(1) * m_fScale44;
                            kDesc.localAnchor[k].z = pExtra->GetValue(2) * m_fScale44;
                        } else {
                            float afValues[3];
                            afValues[0] = kDesc.localAnchor[k].x;
                            afValues[1] = kDesc.localAnchor[k].y;
                            afValues[2] = kDesc.localAnchor[k].z;
                            pExtra = EE_NEW NiFloatsExtraData(3, afValues);
                            {
                                NiFixedString kFixed2((const char*)strKey);
                                pNode->AddExtraData(kFixed2, pExtra);
                            }
                            kDesc.localAnchor[k] = kDesc.localAnchor[k] * m_fScale44;
                        }
                    }
                    ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)GetPhysXHelper())))->FUN_14168a540(1);
                    pJoint->loadFromDesc(kDesc);
                    ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)GetPhysXHelper())))->Unlock();
                }
            }
        }
    }
}

// ---- egf::Entity keyed-property write with change tracking (exe-specific inline; first used by ApplyAnimNames) ----
struct Unk_KfmEntityAccess : egf::Entity
{
    using egf::Entity::GetPropertyValueUnsafe;
    using egf::Entity::SetPropertyValueUnsafe;
};


// @0x1414410b0
void FUN_1414410b0(egf::Entity* e, unsigned id, const efd::utf8string* kKey, void* pVal)
{
    if (((Unk_CachedEntity*)e)->m_bCaching) {
        efd::map<unsigned, efd::map<efd::utf8string, Unk_PropertyCacheEntry> >::iterator itOuter = ((Unk_CachedEntity*)e)->m_mapKeyedCache.find(id);
        if (itOuter == ((Unk_CachedEntity*)e)->m_mapKeyedCache.end()) {
            efd::utf8string kTmp;
            ((Unk_KfmEntityAccess*)e)->GetPropertyValueUnsafe(id, *kKey, &kTmp, efd::GetClassIDFromType<efd::utf8string>());
            ((Unk_CachedEntity*)e)->m_mapKeyedCache[id][*kKey] = Unk_PropertyCacheEntry(id, new efd::utf8string(kTmp), efd::GetClassIDFromType<efd::utf8string>());
        } else {
            efd::map<efd::utf8string, Unk_PropertyCacheEntry>::iterator itInner = itOuter->second.find(*kKey);
            if (itInner == itOuter->second.end()) {
                efd::utf8string kTmp;
                ((Unk_KfmEntityAccess*)e)->GetPropertyValueUnsafe(id, *kKey, &kTmp, efd::GetClassIDFromType<efd::utf8string>());
                itOuter->second[*kKey] = Unk_PropertyCacheEntry(id, new efd::utf8string(kTmp), efd::GetClassIDFromType<efd::utf8string>());
            }
        }
    }
}

// @0x1414413b0
void FUN_1414413b0(egf::Entity* e, unsigned id, const efd::utf8string* kKey, efd::utf8string* pVal)
{
    FUN_1414410b0(e, id, kKey, pVal);
    ((Unk_KfmEntityAccess*)e)->SetPropertyValueUnsafe(id, *kKey, pVal, efd::GetClassIDFromType<efd::utf8string>());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2290-0x142cb2320 .text$yd
// MS2-PIN: ??0AssetID@efd@@QEAA@PEBDEW4CachingPolicy@01@@Z 0x141441ec0
