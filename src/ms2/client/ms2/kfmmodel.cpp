// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CKfmModel: a CEquipModel backed by a .kfm (NiActorManager
// driven by an egf entity; animation / pony-tail physics glue) plus the PhysX NxJointDesc / NxD6JointDesc inline
// COMDATs and the std::set<NiAVObjectPtr> / vector glue first used here.
// MS2-UNIT: ?\kfmmodel.cpp
// MS2-RANGE: 0x14143d580-0x141443550 .text$mn
// MS2-RANGE: 0x1400f6db0-0x1400f6f20 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$vector@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@QEAA@XZ 0x141442340 ; prop
// MS2-PIN: ??B?$SmartPointer@VUnk_KfmPhysics@@@efd@@QEBAPEAVUnk_KfmPhysics@@XZ 0x1414424d0 ; unique
// MS2-PIN: ?TypeCast@CKfmModel@@UEBA_NIPEAPEAX@Z 0x141442960 ; unique
// MS2-PIN: ?TypeCast@CKfmModel@@UEBA_NIPEAPEBX@Z 0x1414429b0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@2@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@2@XZ 0x141442a60 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@XZ 0x141442a80 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@std@@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@2@XZ 0x141442a90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?FUN_141441ec0@@YAXPEAVAssetID@efd@@PEBDEW4CachingPolicy@12@@Z 0x141441ec0
// MS2-PIN: ?FUN_1414424f0@@YAPEAXPEAX0M@Z 0x1414424f0
// MS2-PIN: ??_7CKfmModel@@6BCallbackObject@NiActorManager@@@ 0x142f135d0
// MS2-FUNCTIONAL: extern-heavy; engine/game helpers are opaque FUN_ externs (see nifmodel.cpp, the same model shape
// for a single .nif). Loops over the node list at +0xf8 use the exe's iterator helpers (begin 0x141209190, end
// 0x141209360, neq 0x140b029f0, deref 0x140b02a60, inc 0x140b02a80).
#include "ms2/placeholder/ms2stdafx.h"
#include "kfmmodel.h"
#include "kfmmodel_actor.h"
#include "ms2/placeholder/effectquery.h"
#include <egmAnimation/AnimationService.h>
#include <egf/EntityManager.h>
#include <efd/Category.h>
#include <NiFloatsExtraData.h>
#include <NiKFMTool.h>
#include <NiTransform.h>
#include <NiColor.h>
#include <NiNode.h>
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
extern char DAT_143ac2fc0;      // ms_ClassInfo of the actor-manager owner component
extern efd::AssetID DAT_143a0acf8;   // the invalid asset id

// ---- unit-local views of exe objects ----
// The animation service (singleton behind FUN_141b6f910).
class Unk_KfmAnimSvc
{
public:
    unsigned int FUN_140999490(const egf::EntityID& id, const efd::utf8string& kName);         // sequence id, INVALID_SEQUENCE_ID when absent
    NiActorManager* FUN_140999440(const egf::EntityID& id);
    efd::utf8string FUN_1409a1790(const egf::EntityID& id, unsigned int nSeq);                // name of a sequence
    void FUN_1409a1fc0(const egf::EntityID& id, const efd::utf8string& kName, float fBlend, bool b);   // play
    void FUN_1411766b0(const egf::EntityID& id, unsigned int nSeq, float fBlend, bool b);     // play by sequence id
    efd::utf8string FUN_140b7cc50(const egf::EntityID& id);                                  // current animation name
    bool FUN_14227a3d0(const efd::AssetID& kId, void* pReq, efd::Category kCat,
        efd::vector<egmAnimation::KFMCache::KFMCacheHandle>& kHandles);                      // cache a .kfm
    void FUN_14227ffe0(efd::vector<egmAnimation::KFMCache::KFMCacheHandle>& kHandles);       // release the handles
};
Unk_KfmAnimSvc* FUN_141b6f910();

// Effect play request (0x70 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0). Layout as in entityvibrator.cpp.
int FUN_141bd1a10(void* pEffectMgr, void* pActor);
void* FUN_1403ed2d0();
void* FUN_1403ed280();
void FUN_1411a4a00(void* pFxMgr, NoticeMessage* p);
void* FUN_1409ffd30(void* p);
int FUN_14123c580(void* p);
void* FUN_141200850(CEquipModel* p);

// ---- out-of-unit callees ----
void* FUN_1405a8ed0(void* sp);   void FUN_1405a85c0(void* sp);   void* FUN_1409849b0(void* sp);
void* FUN_1411dc7a0(void* owner, void* out);   void* FUN_14052cd70(void* p);   void FUN_1401bfde0(void* p);
void* FUN_1401c0180(void* p);   int FUN_140527a20(void* p);   void* FUN_1411dc7f0(void* owner);   bool FUN_14053cfd0(void* p);
void FUN_141200e30(void* self, int n);   void FUN_141200ca0(void* self);
void* FUN_141200820(void* self);   void* FUN_1412008e0(void* self);   void* FUN_1412009d0(void* self);
void FUN_1412029d0(void* self, CString* out);   void FUN_141202ea0(void* self, CString* s);
void FUN_141202280(void* self, NiTransform* out);
bool FUN_1409f77a0(void* sp, int n);   void* FUN_1409475f0(void* sp);   void* FUN_1409475d0(void* sp);
void* FUN_1409478e0(void* p);
int FUN_141422110(void* a, void* b, void* c);
float FUN_141422340(void* self, int n);   void FUN_141167840(void* o, const CString& s, float f);
bool FUN_140534e50(void* p);   void* FUN_140527840(void* p);   bool FUN_14053d2b0(void* p);   unsigned FUN_1405258b0(void* p);
void* FUN_140527870(void* p);   unsigned FUN_140599fd0(void* o, int i);   void FUN_141b6f000(void* o, int i, void* v);
void* FUN_141b6dea0(void* out, unsigned v);   void* FUN_1414424f0(void* in, void* out, float f);   void FUN_140a0a3a0(void* out, void* in);
void* FUN_1416561a0(void* p);   int FUN_1411e99a0(void* a, unsigned b, const CString& c, unsigned d, int e);
void* FUN_1409f7cb0(void* p);   void* FUN_14098d8d0(void* tbl, void* key);   void* FUN_14098d0f0(void* sp);
int FUN_141422f30(void* o);
void FUN_140a0b300(void* o, bool b);
class Unk_AeSceneIter   // the scene graph walk (applyeffect.cpp)
{
public:
    Unk_AeSceneIter(NiAVObject* pRoot);                     // 0x14098cb80
    ~Unk_AeSceneIter();                                     // 0x14098cf00
    NiAVObject* FUN_14098e0d0(bool bEnterChildren);
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};
void FUN_1411ffee0(void* self, double t);
void FUN_1402bd040(float* p);
void FUN_1411dde50(void* owner, void* self);
void FUN_141422b30(void* a, void* b, void* c, void* d, float f);
void FUN_1409f76f0(void* p, void* node);   void FUN_1409fabf0(void* p, void* v);

bool FUN_1401c0090(const CString& a, const CString& b);
void FUN_140194470(void* dst, const void* src);
bool FUN_140a33ff0(const NiPoint3& p);   void FUN_140a38a50(egf::Entity* e, unsigned id, const void* v);
void FUN_1409457c0(egf::Entity* e, unsigned id, const float& v);
void FUN_14098c6e0(egf::Entity* e, unsigned id, const bool& v);
int FUN_140998250(egf::Entity* e, unsigned id, efd::AssetID* v);
void FUN_140de8bd0(egf::Entity* e, unsigned id, efd::AssetID* v);
egf::Entity* FUN_1408a9090(const void* sp);   egf::Entity* FUN_1408a9280(const void* sp);
bool FUN_1408b70b0(const void* sp, int n);   bool FUN_140965490(const void* sp, int n);
const egf::EntityID& FUN_1408b76f0(const void* ent);   void FUN_1401cd100(void* dst, int n);
void FUN_1408b6ec0(void* sp, void* v);   void FUN_140964eb0(void* sp, const egf::EntityPtr& v);
void FUN_1414737d0(egf::Entity* e);
egf::EntityManager* FUN_1409670f0();
egf::Entity* FUN_1411cf440(egf::EntityManager* m, const egf::EntityID& id);
bool FUN_1411cf2d0(egf::EntityManager* m, egf::Entity* e, int n);
struct Unk_KfmEntWorld   // the entity manager's create-from-model-name member
{
    egf::EntityPtr FUN_1411cec80(const efd::utf8string& kModel, unsigned long long nId, bool b);
};
unsigned long long FUN_142132a40(void* p);
void* FUN_1411f91c0();   void FUN_141419f50(void* reg, void* model);   void FUN_14141a000(void* reg, void* model);
bool FUN_1413e9750(const efd::AssetID& a, const efd::AssetID& b);
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();   bool FUN_141689a10(CPhysXHelper* h, egf::Entity* e);
void FUN_14168a540(CPhysXHelper* h, int n);   void FUN_14168a570(CPhysXHelper* h);
void FUN_141689ec0(CPhysXHelper* h, egf::Entity* e, int n, void* params, int m);
void FUN_1416962d0(void* pModel, void* pPonyTails);
efd::SmartPointer<Unk_KfmPhysics> FUN_141209640(CEquipModel* p);
void FUN_140a332d0(NiTransform* p);
const NiTransform& FUN_140a33f90(void* obj);   void FUN_140aacb60(void* obj, const void* xf);
void FUN_140981070(void* obj, const void* p);   void FUN_140ddcca0(void* obj, const void* m);   void FUN_1410b2450(void* obj, float s);
void FUN_14097faa0(void* dst, const void* src);   void FUN_140a33240(void* dst, const void* src);
void FUN_140a0b1f0(const void* pRotate, float* out);
void FUN_1409f72e0(void* m);
const efd::utf8string& FUN_1409a1a90();   bool FUN_140de8ea0(const efd::utf8string& a, const efd::utf8string& b);
bool FUN_1409a1140(const efd::utf8string& a, const efd::utf8string& b);
CString FUN_1409a2360(const char* psz, int n);   CString FUN_140719190(int v);
const char* FUN_142087e50(const void* kFixed);
size_t FUN_14028b4c0(void* v);   CString* FUN_140fe01a0(void* v, unsigned __int64 i);
bool FUN_14028d470(float a, float b);
void FUN_14120a440(void* p, void* v);
void FUN_141205320(void* s);   void FUN_141205530(void* s);
void FUN_141209360(void* list, void* out);   void FUN_141209190(void* list, void* out);
bool FUN_140b029f0(void* a, void* b);   void* FUN_140b02a60(void* it);   void FUN_140b02a80(void* it);
void* FUN_141c43700(void* a, int b, unsigned c, int d);
void FUN_141c435b0(void* a, int b, unsigned c, void* pName);   // RegisterCallback(type, seq, const NiFixedString&)
bool FUN_140d821f0(void* p);
void* FUN_14098db90(void* pClassInfo);   // ClassInfo::GetParent
void FUN_140de91f0(void* pStr);
char FUN_140de0b00(void* pChar, char c);
size_t FUN_14208c9b0(void* pStr);
void* FUN_14208ae50(void* pStr, void* pOut, size_t n);

// Unit-local runtime-type helpers (the exe emits them as out-of-line functions next to the model code).
class Unk_KfmTyped
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void* GetClassInfoPtr();                // slot 2
};

bool FUN_1414428a0(void* p, void* pClass)           // p's class derives from pClass
{
    void* pCur = ((Unk_KfmTyped*)p)->GetClassInfoPtr();
    while (pCur != 0) {
        if (pCur == pClass)
            return true;
        pCur = FUN_14098db90(pCur);
    }
    return false;
}

void* FUN_141442810(void* p, void* pClass)
{
    return FUN_1414428a0(p, pClass) ? p : 0;
}

void* FUN_141442860(void* pClass, void* p)
{
    if (p == 0)
        return 0;
    return FUN_141442810(p, pClass);
}

struct Unk_KfmVec3 { float x, y, z; };

void* FUN_1414424f0(void* pIn, void* pOut, float fScale)   // pOut = *pIn * fScale
{
    NiPoint3 v = *(NiPoint3*)pIn;
    v.x *= fScale;
    v.y *= fScale;
    v.z *= fScale;
    *(Unk_KfmVec3*)pOut = *(Unk_KfmVec3*)&v;
    return pOut;
}

// The exe's AssetID(const char*, ...) constructor (copy in this TU): the SDK constructor plus dropping a trailing ':'.
struct Unk_KfmAssetIDAccess
{
    static void Init(efd::AssetID* p, const char* pszUrn, unsigned char nMult, efd::AssetID::CachingPolicy ePolicy)
    {
        new (p) efd::AssetID(pszUrn, nMult, ePolicy);
        void* pUrn = (void*)&p->GetURN();
        size_t nLen = FUN_14208c9b0(pUrn);
        if (nLen != 0) {
            char t[16];
            if (FUN_140de0b00(FUN_14208ae50(pUrn, t, nLen - 1), ':') != 0)
                FUN_140de91f0(pUrn);
        }
    }
};

void FUN_141441ec0(efd::AssetID* p, const char* pszUrn, unsigned char nMult, efd::AssetID::CachingPolicy ePolicy)
{
    Unk_KfmAssetIDAccess::Init(p, pszUrn, nMult, ePolicy);
}
void* FUN_1414f1e70(void* p, egf::EntityID id, int n);   void* FUN_1409613d0(void* p);   void* FUN_140ad4ba0();
void FUN_1401bf970(void* out, void* p);   bool FUN_1401b5240(void* sp, int n);   void FUN_1401b50d0(void* sp);
void FUN_1414413b0(egf::Entity* e, unsigned id, const efd::utf8string* kKey, efd::utf8string* pVal);
void* FUN_1413f9b70(const egf::EntityID& id);   void* FUN_1409995d0(void* p);   void* FUN_1409995c0();
void FUN_14099a7c0(void* a, void* b);   void FUN_140999170(void* a);   void FUN_14099bb80(void* a, void* b, void* c);
void* FUN_140999740(void* a, unsigned b);   void* FUN_140999900(void* a);   void* FUN_1409995f0(void* a, unsigned* n);
void* FUN_1409998f0(void* a);   bool FUN_140998dc0(void* a, const char* s);
void* FUN_141203e60(void* p);
void* FUN_141d17b40(void* node, void* name);
float FUN_141d57ca0(void* ed, int i);
efd::ServiceManager* FUN_140af8310(char* pManager);   void* FUN_14086d260();
void* FUN_1412018c0(void* self);

#define VSLOT(o, off) ((*(void***)(o))[(off) / 8])
#define V0(R, o, off) (((R(*)(void*))VSLOT(o, off))(o))
#define V2(R, o, off, T1, a, T2, b) (((R(*)(void*, T1, T2))VSLOT(o, off))(o, a, b))
#define V1(R, o, off, T, a) (((R(*)(void*, T))VSLOT(o, off))(o, a))

#define CFG ((Unk_KfmConfig*)m_unk_20)
#define F8(self) ((void*)((char*)(self) + 0xf8))
#define PAIR_BEGIN(self, it, end) FUN_141209360(F8(self), end); FUN_141209190(F8(self), it)

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
CKfmModel::CKfmModel(MS2Ptr<Unk_EquipModelOwner> spOwner, void* p18, void* p20)
    : CEquipModel(spOwner, p18, p20), m_nUpdateHR(0), m_nUpdateTransform(0), m_bPhysicsLoaded(0), m_spEntity(0),
      m_pPhysics(0)
{
}

// @0x14143d680
CKfmModel::~CKfmModel()
{
    FUN_1414409f0();
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
    if (FUN_140965490(&m_spEntity, 0) != 0) {
        if (FUN_140998250(FUN_1408a9280(&m_spEntity), 0x12383cea, &kCur) == 0 && FUN_1413e9750(kCur, kNew) != 0)
            return 1;
    }
    FUN_1414408e0();
    m_str38 = strPath;
    FUN_1409fabf0(&m_unk_f0, 0);
    m_nState = 0;
    FUN_1409f76f0(&m_spNode, 0);
    FUN_140de8bd0(FUN_1408a9280(&m_spEntity), 0x12383cea, &kNew);
    bool bFlag = false;
    FUN_14098c6e0(FUN_1408a9280(&m_spEntity), 0xa0b6b179, bFlag);
    if (FUN_1411cf440(FUN_1409670f0(), FUN_14143ff70()) != 0)
        return 1;
    FUN_141440a70();
    if (FUN_1411cf2d0(FUN_1409670f0(), FUN_1408a9090(&m_spEntity), 0) != 0)
        FUN_1411dde50(FUN_1405a8ed0(&m_spOwner), this);
    return 1;
}

// @0x14143da90
void CKfmModel::vfunc_5()
{
    MS2Ptr<CEquipModel> spKeep(this);    // keeps the model alive through the teardown
    CEquipModel::vfunc_5();
    FUN_1414409f0();
    m_pPhysics = 0;
}

// @0x14143db00
int CKfmModel::vfunc_6()
{
    m_nState = 1;
    if (!m_str38.IsEmpty() && FUN_1409613d0(FUN_141200820(this)) != 0) {
        efd::AssetID kId((const char*)m_str38, 0, efd::AssetID::NEVER_CACHE);
        efd::vector<egmAnimation::KFMCache::KFMCacheHandle> kHandles;
        if (FUN_141b6f910()->FUN_14227a3d0(kId, 0, g_catKfm, kHandles) == 0)
            FUN_141b6f910()->FUN_14227ffe0(kHandles);
    }
    void* pComp = FUN_141442860(&DAT_143ac2fc0, FUN_1414400d0());
    if (pComp != 0)
        FUN_140d821f0(pComp);
    if (FUN_1408a9090(&m_spEntity) != 0) {
        FUN_141203e60(this);
        if (DAT_143ae2b30 != 0)
            FUN_1414f1e70(FUN_140ad4ba0(), FUN_1408b76f0(FUN_1408a9280(&m_spEntity)), 3);
        void* pActorMgr = FUN_1413f9b70(FUN_1408b76f0(FUN_1408a9280(&m_spEntity)));
        if (pActorMgr != 0) {
            if (DAT_143ae2b30 != 0) {
                FUN_14099bb80(FUN_1409995c0(), pActorMgr, static_cast<NiActorManager::CallbackObject*>(this));
            } else {
                FUN_14099a7c0(pActorMgr, 0);
                FUN_140999170(pActorMgr);
                FUN_14099a7c0(pActorMgr, static_cast<NiActorManager::CallbackObject*>(this));
            }
            NiKFMTool* pKfm = (NiKFMTool*)FUN_1409995d0(pActorMgr);
            unsigned int* pIds = 0;
            unsigned int nIds;
            pKfm->GetSequenceIDs(pIds, nIds);
            for (unsigned int i = 0; i < nIds; ++i) {
                unsigned int nSeqId = pIds[i];
                void* pSeq = FUN_140999740(pActorMgr, nSeqId);
                if (pSeq == 0)
                    continue;
                void* pTextKeys = FUN_140999900(pSeq);
                unsigned int nKeys = 0;
                char* pKey = (char*)FUN_1409995f0(pTextKeys, &nKeys);
                FUN_141c43700(pActorMgr, 0, nSeqId, 0);
                FUN_141c43700(pActorMgr, 4, nSeqId, 0);
                for (unsigned int k = 0; k < nKeys; ++k) {
                    void* pName = FUN_1409998f0(pKey + (unsigned long long)k * 0x10);
                    if (FUN_140998dc0(pName, "start") || FUN_140998dc0(pName, "end"))
                        continue;
                    FUN_141c435b0(pActorMgr, 3, nSeqId, pName);
                }
            }
            if (pIds != 0)
                efd::_Free(pIds, 0xffffffffffffffffull);
        }
    }
    FUN_141440bc0();
    FUN_141200ca0(this);
    vfunc_10();
    vfunc_11();
    {
        efd::utf8string kIdle("Idle_A");
        CString strA("");
        CString strB("");
        FUN_141440380(strB, strA, kIdle, 1.0f, false);
    }
    return 1;
}

// @0x14143e090
int CKfmModel::vfunc_7()
{
    FUN_141200e30(this, 1);
    vfunc_5();
    return 1;
}

// @0x14143e0d0
int CKfmModel::vfunc_33()
{
    m_bPhysicsLoaded = 1;
    m_pPhysics = FUN_141209640(this);
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
    if (!FUN_141689a10(FUN_1409f7ca0(), FUN_1408a9090(&m_spEntity)))
        return m_nState;
    return m_nState != 0 && m_bPhysicsLoaded != 0;
}

// @0x14143e240
void CKfmModel::vfunc_10()
{
    m_nUpdateHR = (vfunc_9() == 0);
    if (m_nUpdateHR != 0)
        return;
    if (FUN_14053cfd0(FUN_1411dc7f0(FUN_1405a8ed0(&m_spOwner)))) {
        {
            CString s("HR:0");
            FUN_141167840(vfunc_14(), s, FUN_141422340(this, 0));
        }
        {
            CString s("HR0:0");
            FUN_141167840(vfunc_14(), s, FUN_141422340(this, 0));
        }
        {
            CString s("HR1:1");
            FUN_141167840(vfunc_14(), s, FUN_141422340(this, 1));
        }
    }
}

class CItem;
struct Unk_KfmEquipItem { MS2Ptr<CItem> FUN_1411dc7a0(); };   // CEquipItem::GetItem
struct Unk_KfmColor : efd::Color
{
    using efd::Color::operator=;
    efd::Color FUN_1414424f0(float fScale) const;   // 0x1414424f0 Color * scale
};
Unk_KfmColor FUN_141b6dea0(unsigned nColor);

// @0x14143e3e0
void CKfmModel::vfunc_11()
{
    m_nUpdateTransform = (vfunc_9() == 0);
    if (m_nUpdateTransform != 0)
        return;
    void* pPartList = FUN_140527870(((Unk_KfmEquipItem*)FUN_1405a8ed0(&m_spOwner))->FUN_1411dc7a0().operator->());
    if (pPartList == 0)
        return;
    for (int i = 0; i < 3; ++i) {
        Unk_KfmColor kColor = FUN_141b6dea0(FUN_140599fd0(pPartList, i));
        if (i == 1) {
            NiColor kScaled(FUN_141b6dea0(FUN_140599fd0(pPartList, 0)).FUN_1414424f0(1.3f));
            kColor = kScaled;
        }
        void* pRoot = vfunc_14();
        if (pRoot != 0)
            FUN_141b6f000(pRoot, i, &kColor);
        struct Unk_SetIt { void* p; };
        void* pRange = F8(this);
        Unk_SetIt itEnd;
        FUN_141209360(pRange, &itEnd);
        Unk_SetIt it;
        for (FUN_141209190(pRange, &it); FUN_140b029f0(&it, &itEnd); FUN_140b02a80(&it)) {
            NiAVObjectPtr sp(*(NiAVObjectPtr*)FUN_140b02a60(&it));
            if (FUN_1409849b0(&sp) != 0)
                FUN_141b6f000(FUN_1409849b0(&sp), i, &kColor);
        }
    }
    Unk_ModelActor* p = (Unk_ModelActor*)FUN_141200820(this);
    if (p != 0)
        p->vfunc_139();
}

// @0x14143e670
class CItemData;
struct Unk_KfmPartSelf { CString FUN_1412029d0(); };   // the part name (by value)
void CKfmModel::vfunc_12()
{
    MS2Ptr<CItemData> spItem((CItemData*)FUN_1412009d0(this));
    if (spItem == 0)
        return;
    const CString& strName = ((Unk_KfmPartSelf*)this)->FUN_1412029d0();
    if (strName.IsEmpty())
        return;
    FUN_141202ea0(this, (CString*)&strName);
    if (FUN_1409f77a0(&m_spNode, 0) != 0)
        return;
    std::set<NiAVObjectPtr> kSet;
    if (FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &kSet) != 0) {
        struct Unk_SetIt { void* p; };
        void* pRange = &kSet;
        Unk_SetIt itEnd;
        FUN_141209360(pRange, &itEnd);
        Unk_SetIt it;
        for (FUN_141209190(pRange, &it); FUN_140b029f0(&it, &itEnd); FUN_140b02a80(&it)) {
            NiAVObjectPtr sp(*(NiAVObjectPtr*)FUN_140b02a60(&it));
            if (FUN_1409849b0(&sp) != 0) {
                if (FUN_141440f20()) {
                    NiNode* pParent = (NiNode*)FUN_1409475f0(&m_spNode);
                    pParent->AttachChild((NiAVObject*)FUN_1409849b0(&sp), true);
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
    void* pRootNode = FUN_1412008e0(this);
    if (pRootNode == 0)
        return;
    NiTransform kXf;
    kXf.MakeIdentity();
    FUN_141202280(this, &kXf);
    Unk_ModelActor* pActor = (Unk_ModelActor*)FUN_141200820(this);
    if (pActor == 0)
        return;
    MS2Ptr<CItem> spItem = ((Unk_KfmEquipItem*)FUN_1405a8ed0(&m_spOwner))->FUN_1411dc7a0();
    if (FUN_140534e50(&spItem) != 0)
        return;
    int nResult = FUN_1411e99a0(FUN_1416561a0(pActor), FUN_140527a20(spItem.operator->()),
                                ((Unk_KfmPartSelf*)this)->FUN_1412029d0(), FUN_1405258b0(spItem.operator->()),
                                FUN_14053d2b0(FUN_140527840(spItem.operator->())));
    if (nResult != 0) {
        NiNode* pTarget;
        {
            NiFixedString kName("Bip01 Head");
            pTarget = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, ((NiAVObject*)FUN_1409f7cb0(pRootNode))->GetObjectByName(kName));
        }
        if (pTarget == 0)
            return;
        std::set<NiAVObjectPtr> kSet;
        if (FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &kSet) != 0) {
            struct Unk_SetIt { void* p; };
            void* pRange = &kSet;
            Unk_SetIt itEnd;
            FUN_141209360(pRange, &itEnd);
            Unk_SetIt it;
            for (FUN_141209190(pRange, &it); FUN_140b029f0(&it, &itEnd); FUN_140b02a80(&it)) {
                NiAVObjectPtr sp(*(NiAVObjectPtr*)FUN_140b02a60(&it));
                FUN_140aacb60(FUN_14098d0f0(&sp), &static_cast<const NiTransform&>(kXf * FUN_140a33f90(FUN_14098d0f0(&sp))));
                pTarget->AttachChild((NiAVObject*)FUN_1409849b0(&sp), true);
                m_unk_f8.insert(sp);
            }
        }
    }
}

// @0x14143ee10
void* CKfmModel::vfunc_14()
{
    NiActorManager* pMgr = FUN_1414400d0();
    if (pMgr != 0)
        FUN_1409fabf0(&m_unk_f0, FUN_1409f7cb0(pMgr));
    return FUN_1409849b0(&m_unk_f0);
}

// @0x14143ed00
int CKfmModel::vfunc_15()
{
    void* pRoot = vfunc_14();
    if (pRoot != 0 && FUN_141422f30(pRoot) != 0)
        return 1;
    struct Unk_SetIt { void* p; };
    void* pRange = F8(this);
    Unk_SetIt itEnd;
    FUN_141209360(pRange, &itEnd);
    Unk_SetIt it;
    for (FUN_141209190(pRange, &it); FUN_140b029f0(&it, &itEnd); FUN_140b02a80(&it)) {
        NiAVObjectPtr sp(*(NiAVObjectPtr*)FUN_140b02a60(&it));
        if (FUN_1409849b0(&sp) != 0 && FUN_141422f30(FUN_1409849b0(&sp)) != 0)
            return 1;
    }
    return 0;
}

// @0x14143ee70
void CKfmModel::vfunc_16()
{
    vfunc_10();
    if (CFG->m_bPhysics != 0) {
        FUN_141200e30(this, 0);
        FUN_141440bc0();
        FUN_141200ca0(this);
    }
    vfunc_31();
}

// @0x14143eee0
void CKfmModel::vfunc_17()
{
    CEquipModel::vfunc_17();
    bool bVisible = (m_nState != 0 && vfunc_20() != 0) ? true : false;
    bool bHide = (bVisible == 0);
    struct Unk_SetIt { void* p; };
    void* pRange = F8(this);
    Unk_SetIt itEnd;
    FUN_141209360(pRange, &itEnd);
    Unk_SetIt it;
    for (FUN_141209190(pRange, &it); FUN_140b029f0(&it, &itEnd); FUN_140b02a80(&it)) {
        NiAVObjectPtr sp(*(NiAVObjectPtr*)FUN_140b02a60(&it));
        Unk_AeSceneIter kIter((NiAVObject*)FUN_1409849b0(&sp));
        NiAVObject* pObject;
        while ((pObject = kIter.FUN_14098e0d0(true)) != 0) {
            void* pMesh = FUN_14098d8d0(&DAT_143afbbb0, pObject);
            if (pMesh != 0)
                FUN_140a0b300(pMesh, bHide);
        }
    }
    Unk_AeSceneIter kIter((NiAVObject*)vfunc_14());
    NiAVObject* pObject;
    while ((pObject = kIter.FUN_14098e0d0(true)) != 0) {
        void* pMesh = FUN_14098d8d0(&DAT_143afbbb0, pObject);
        if (pMesh != 0)
            FUN_140a0b300(pMesh, bHide);
    }
    FUN_14098c6e0(FUN_1408a9280(&m_spEntity), 0xa0b6b179, bVisible);
}

// @0x14143f110
void CKfmModel::vfunc_18()
{
    vfunc_5();
}

// @0x14143f140
void CKfmModel::vfunc_19(double fTime)
{
    FUN_1411ffee0(this, fTime);
    if ((Unk_KfmPhysics*)m_pPhysics != 0) {
        FUN_14168a540(FUN_1409f7ca0(), 1);
        m_pPhysics->Update(fTime);
        FUN_14168a570(FUN_1409f7ca0());
    }
    if (m_nUpdateHR != 0)
        vfunc_10();
    if (m_nUpdateTransform != 0)
        vfunc_11();
    if (m_b111 != 0) {
        if (vfunc_20() != 0) {
            if (FUN_141200820(this) != 0)
                vfunc_32(((Unk_ModelActor*)FUN_141200820(this))->vfunc_65());
            m_b111 = false;
        }
    }
    FUN_141440f60();
}

// @0x14143f2a0
void CKfmModel::vfunc_32(int n)
{
    CEquipModel::vfunc_32(n);
    egf::EntityID kId = FUN_14143ff70();
    efd::utf8string kAnim(n != 0 ? "Attack_Idle_A" : "Idle_A");
    efd::utf8string kCur = FUN_141b6f910()->FUN_140b7cc50(kId);
    if (FUN_141b6f910()->FUN_140999490(kId, kAnim) != NiActorManager::INVALID_SEQUENCE_ID) {
        bool bSame = FUN_1409a1140(kAnim, kCur);
        FUN_141b6f910()->FUN_1409a1fc0(kId, kAnim, 1.0f, bSame);
    }
}

// @0x14143f970
void CKfmModel::vfunc_22(float f)
{
    m_fScale44 = f;
    if (FUN_1408a9090(&m_spEntity) != 0)
        FUN_1409457c0(FUN_1408a9280(&m_spEntity), 0x2d7cad2d, m_fScale44);
    FUN_14143f3d0();
}

// @0x14143f9f0
void CKfmModel::vfunc_24(const NiPoint3& p)
{
    if (!FUN_140a33ff0(p))
        return;
    m_pos48 = p;
    if (FUN_1408a9090(&m_spEntity) != 0)
        FUN_140a38a50(FUN_1408a9280(&m_spEntity), 0xfd95ca52, &m_pos48);
}

// @0x14143fa80
void CKfmModel::vfunc_26(const NiPoint3& p)
{
    if (!FUN_140a33ff0(p))
        return;
    m_pos54 = p;
    if (FUN_1408a9090(&m_spEntity) != 0)
        FUN_140a38a50(FUN_1408a9280(&m_spEntity), 0x68c7c29d, &m_pos54);
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
    FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &kSet);
    FUN_141422b30(this, &kSet, &DAT_143b01a60, &DAT_143b01a60, 1.0f);
}

// @0x14143fc70
void CKfmModel::vfunc_28(void* pPos, void* pMatrix3, float fScale)
{
    float x, y, z;
    FUN_1402bd040(&x);     // NiPoint3() on the x, y, z angles
    ((efd::Matrix3*)pMatrix3)->ToEulerAnglesXYZ(x, y, z);
    x = (x * 180.0f) / 3.1415927f;
    y = (y * 180.0f) / 3.1415927f;
    z = (z * 180.0f) / 3.1415927f;
    vfunc_29(pPos, &x, fScale);
}

// NiPoint3(const efd::Point3&), NiPoint3::operator= and NiMatrix3(const efd::Matrix3&) as the exe calls them
struct Unk_KfmPoint3 { float x, y, z; };
struct Unk_KfmMatrix3 { float m00, m01, m02, m10, m11, m12, m20, m21, m22; };
void FUN_14027dcf0(Unk_KfmPoint3* p, const void* pPoint);
void FUN_14097faa0(NiPoint3* p, const Unk_KfmPoint3* pSrc);
void FUN_140a33240(Unk_KfmMatrix3* p, const void* pMatrix);

// @0x14143fd30
void CKfmModel::vfunc_30(void* pPos, void* pRot, float fScale)
{
    NiTransform kXf;
    Unk_KfmPoint3 kPos;
    FUN_14027dcf0(&kPos, pPos);
    FUN_14097faa0(&kXf.m_Translate, &kPos);
    Unk_KfmMatrix3 kRot;
    FUN_140a33240(&kRot, pRot);
    kXf.m_Rotate = *(NiMatrix3*)&kRot;
    kXf.m_fScale = fScale;
    FUN_140aacb60(vfunc_14(), &kXf);
}

// @0x14143fe10
void CKfmModel::vfunc_31()
{
    if (vfunc_9() == 0)
        return;
    if (FUN_14053cfd0(FUN_1412009d0(this)) == 0)
        return;
    NxGroupsMask kMask;
    kMask.bits0 = 0; kMask.bits1 = 0; kMask.bits2 = 0; kMask.bits3 = 0;
    FUN_141689ec0(FUN_1409f7ca0(), FUN_1411cf440(FUN_1409670f0(), FUN_14143ff70()), 0, &kMask, 0);
    if (CFG->m_bPhysics != 0)
        FUN_1416962d0(this, (char*)m_unk_20 + 0xb8);
}

// @0x14143ff20
egf::EntityPtr CKfmModel::GetEntity()
{
    return m_spEntity;
}

// @0x14143ff70
egf::EntityID CKfmModel::FUN_14143ff70()
{
    if (FUN_1408a9090(&m_spEntity) != 0)
        return FUN_1408a9280(&m_spEntity)->GetEntityID();
    return egf::EntityID((efd::UInt64)0);
}

// @0x14143fff0
efd::AssetID CKfmModel::FUN_14143fff0()
{
    efd::AssetID kCur;
    if (FUN_140998250(FUN_1408a9280(&m_spEntity), 0x12383cea, &kCur) == 0)
        return kCur;
    return DAT_143a0acf8;
}

// @0x1414400d0
NiActorManager* CKfmModel::FUN_1414400d0()
{
    return FUN_141b6f910()->FUN_140999440(FUN_14143ff70());
}

// @0x141440110
void CKfmModel::FUN_141440110(const CString& strBone, float f)
{
    for (unsigned int i = 0; i < 4; ++i) {
        Unk_KfmPonyTail* p = &CFG->m_aPonyTail[i];
        if (FUN_1401c0090(p->m_strBone, strBone) != 0)
            p->m_fDamping = f;
    }
    vfunc_31();
}

// @0x1414401b0
void CKfmModel::FUN_1414401b0(const CString& strBone, float x, float y, float z)
{
    for (unsigned int i = 0; i < 4; ++i) {
        Unk_KfmPonyTail* p = &CFG->m_aPonyTail[i];
        if (FUN_1401c0090(p->m_strBone, strBone) != 0) {
            p->m_fX = x;
            p->m_fY = y;
            p->m_fZ = z;
        }
    }
    vfunc_31();
}

// @0x141440270
void CKfmModel::FUN_141440270(unsigned int nSeq)
{
    bool bEmpty = FUN_140de8ea0(FUN_141b6f910()->FUN_1409a1790(FUN_14143ff70(), nSeq), FUN_1409a1a90());
    if (bEmpty)
        FUN_141b6f910()->FUN_1411766b0(FUN_14143ff70(), nSeq, 1.0f, false);
}

// @0x141440380
void CKfmModel::FUN_141440380(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend,
    bool b)
{
    const egf::EntityID& kId = FUN_14143ff70();
    efd::utf8string kA((const char*)FUN_1409a2360((const char*)strA, 0));
    if (FUN_141b6f910()->FUN_140999490(kId, kA) != NiActorManager::INVALID_SEQUENCE_ID) {
        FUN_141b6f910()->FUN_1409a1fc0(kId, kA, fBlend, b);
        return;
    }
    efd::utf8string kB = (const char*)FUN_1409a2360((const char*)strB, 0) + kDefault;
    if (FUN_141b6f910()->FUN_140999490(kId, kB) != NiActorManager::INVALID_SEQUENCE_ID) {
        FUN_141b6f910()->FUN_1409a1fc0(kId, kB, fBlend, b);
        return;
    }
    if (FUN_141b6f910()->FUN_140999490(kId, kDefault) != NiActorManager::INVALID_SEQUENCE_ID) {
        FUN_141b6f910()->FUN_1409a1fc0(kId, kDefault, fBlend, b);
        return;
    } else {
        bool bFound;
        {
            efd::utf8string kIdle("Idle_A");
            bFound = FUN_141b6f910()->FUN_140999490(kId, kIdle) != NiActorManager::INVALID_SEQUENCE_ID;
        }
        if (bFound) {
            efd::utf8string kIdle2("Idle_A");
            FUN_141b6f910()->FUN_1409a1fc0(kId, kIdle2, fBlend, b);
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
    CString strKey(FUN_142087e50(&kTextKey));
    if (strKey.Find("effect_", 0) == 0) {
        void* pActor = FUN_1409ffd30(FUN_141200850(this));
        NoticeMessage kReq;
        kReq.m_strName = strKey.Right(strKey.GetLength() - 7);
        kReq.m_nObject = FUN_141bd1a10(FUN_1403ed2d0(), pActor);
        FUN_1409fabf0(&kReq.m_spNode, FUN_14098d8d0(&DAT_143afa4d8, vfunc_14()));
        if (pActor != 0)
            kReq.SetActor(FUN_14123c580(pActor));
        FUN_1411a4a00(FUN_1403ed280(), &kReq);
    }
}

// @0x1414408c0
void CKfmModel::EndOfSequence(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float) {}

// @0x1414408e0
void CKfmModel::FUN_1414408e0()
{
    FUN_1414409f0();
    unsigned __int64 nScratch;
    void* pDummy = &nScratch;
    FUN_140964eb0(&m_spEntity,
        ((Unk_KfmEntWorld*)FUN_1409670f0())->FUN_1411cec80(FUN_141201780(), FUN_142132a40(pDummy), true));
    FUN_141419f50(FUN_1411f91c0(), this);
}

// @0x1414409f0
void CKfmModel::FUN_1414409f0()
{
    if (FUN_1408b70b0(&m_spEntity, 0))
        return;
    FUN_14141a000(FUN_1411f91c0(), this);
    FUN_1414737d0(FUN_1408a9090(&m_spEntity));
    FUN_1408b6ec0(&m_spEntity, 0);
}

// @0x141440a70
void CKfmModel::FUN_141440a70()
{
    std::vector<CString>& kNames = CFG->m_arrAnimNames;
    for (unsigned int i = 0; i < FUN_14028b4c0(&kNames); ++i) {
        efd::utf8string kKey((const char*)FUN_140719190(i));
        efd::utf8string kVal((const char*)*FUN_140fe01a0(&kNames, i));
        FUN_1414413b0(FUN_1408a9280(&m_spEntity), 0xa75781ca, &kKey, &kVal);
    }
}

// @0x141440bc0
void CKfmModel::FUN_141440bc0()
{
    if (CFG->m_bPhysics == 0) return;
    if (FUN_14053cfd0(FUN_1411dc7f0(FUN_1405a8ed0(&m_spOwner)))) {
        void* pData = FUN_140527870(((Unk_KfmEquipItem*)FUN_1405a8ed0(&m_spOwner))->FUN_1411dc7a0().operator->());
        if (pData != 0) {
            float fScale = ((float*)((char*)pData + 0x58))[0];
            efd::Point3 kPos = ((efd::Point3*)((char*)pData + 0x60))[CFG->m_nIndex];
            efd::Point3 kRot = ((efd::Point3*)((char*)pData + 0x78))[CFG->m_nIndex];
            std::set<NiAVObjectPtr> kSet;
            FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &kSet);
            efd::Matrix3 kMat;
            kMat.FromEulerAnglesXYZ((kRot.x * 3.1415927f) / 180.0f, (kRot.y * 3.1415927f) / 180.0f,
                (kRot.z * 3.1415927f) / 180.0f);
            struct Unk_SetIt { void* p; };
            void* pRange = &kSet;
            Unk_SetIt itEnd;
            FUN_141209360(pRange, &itEnd);
            Unk_SetIt it;
            for (FUN_141209190(pRange, &it); FUN_140b029f0(&it, &itEnd); FUN_140b02a80(&it)) {
                NiAVObjectPtr sp(*(NiAVObjectPtr*)FUN_140b02a60(&it));
                sp->SetTranslate(kPos);
                sp->SetRotate(kMat);
                sp->SetScale(fScale);
            }
            vfunc_22(fScale);
        }
    }
}

// @0x141440f20
bool CKfmModel::FUN_141440f20()
{
    if (m_unk_20 == 0)
        return false;
    return FUN_14028d470(CFG->m_fScale, 1.0f);
}

// @0x141440f60
void CKfmModel::FUN_141440f60()
{
    if (FUN_141440f20())
        return;
    if (FUN_1409475d0(&m_spNode) == 0)
        return;
    NiTransform* pXf = (NiTransform*)FUN_1409478e0(FUN_1409475f0(&m_spNode));
    NiPoint3 kTrans = pXf->m_Translate;
    reinterpret_cast<Unk_KfmModelSlots*>(this)->vfunc_24(kTrans);
    efd::Point3 kRot;
    FUN_140a0b1f0(&pXf->m_Rotate, &kRot.x);
    reinterpret_cast<Unk_KfmModelSlots*>(this)->vfunc_26(reinterpret_cast<NiPoint3&>(kRot));
}

// The exe's NiPhysXPropDesc keeps its joint array at +0x30 (the engine header has another layout); the same view as
// equipmodelforceapplier.cpp's.
class Unk_WindPropDesc
{
public:
    unsigned GetActorCount() const;                             // 0x14120ac30
    NiPhysXActorDescPtr GetActorAt(unsigned uiIndex);           // 0x14120abd0
};

// @0x14143f3d0
void CKfmModel::FUN_14143f3d0()
{
    if (CFG->m_bPhysics != 0 || CFG->m_bHead != 0 || FUN_14028d470(CFG->m_fScale, 1.0f) == 0) {
        efd::ServiceManager* pServiceManager = FUN_140af8310((char*)FUN_14086d260() + 8);
        ecrPhysX::PropService* pService = pServiceManager->GetSystemServiceAs<ecrPhysX::PropService>();
        unsigned nProps = pService->GetNumProps(FUN_14143ff70());
        NiObjectNET* pNode = (NiObjectNET*)FUN_1412018c0(this);
        if (pNode == 0)
            return;
        for (unsigned i = 0; i < nProps; ++i) {
            NiPhysXProp* pProp = pService->GetPropAt(FUN_14143ff70(), i);
            if (pProp == 0)
                continue;
            Unk_WindPropDesc* pDesc = (Unk_WindPropDesc*)pProp->GetSnapshot();
            if (pDesc == 0)
                continue;
            unsigned nCount = pDesc->GetActorCount();
            for (unsigned j = 0; j < nCount; ++j) {
                NiPhysXD6JointDesc* pJointDesc = (NiPhysXD6JointDesc*)FUN_14098d8d0(&DAT_143afc8c0, pDesc->GetActorAt(j));
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
                            pExtra = (NiFloatsExtraData*)FUN_14098d8d0(&DAT_143afafe0, FUN_141d17b40(pNode, &kFixed));
                        }
                        if (pExtra != 0) {
                            kDesc.localAnchor[k].x = FUN_141d57ca0(pExtra, 0) * m_fScale44;
                            kDesc.localAnchor[k].y = FUN_141d57ca0(pExtra, 1) * m_fScale44;
                            kDesc.localAnchor[k].z = FUN_141d57ca0(pExtra, 2) * m_fScale44;
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
                    FUN_14168a540(FUN_1409f7ca0(), 1);
                    pJoint->loadFromDesc(kDesc);
                    FUN_14168a570(FUN_1409f7ca0());
                }
            }
        }
    }
}

// ---- egf::Entity keyed-property write with change tracking (exe-specific inline; first used by FUN_141440a70) ----
struct Unk_KfmEntityAccess : egf::Entity
{
    using egf::Entity::GetPropertyValueUnsafe;
    using egf::Entity::SetPropertyValueUnsafe;
};
unsigned FUN_1408a2000();
void* FUN_1413f83e0(void* tbl, void* itOut, unsigned* pId);   void* FUN_1413f7220(void* tbl, void* out);
bool FUN_1413e9590(void* a, void* b);   void* FUN_1413e9c00(void* it);
void* FUN_1413f8680(void* tbl, void* out, const efd::utf8string* kKey);   void* FUN_1413f7400(void* tbl, void* out);
bool FUN_1413e96d0(void* a, void* b);   void* FUN_1413e9a80(void* tbl, unsigned* pId);
void* FUN_1413e9b80(void* tbl, const efd::utf8string* kKey);   void* FUN_140947490(void* out, unsigned id, void* p, unsigned nType);


// @0x1414410b0
void FUN_1414410b0(egf::Entity* e, unsigned id, const efd::utf8string* kKey, void* pVal)
{
    struct Unk_Rec { void* p[3]; };
    struct Unk_It { void* p; };
    if (*(bool*)((char*)e + 0xc8)) {
        Unk_It itOuter;
        Unk_It kEnd;
        FUN_1413f83e0((char*)e + 0xe0, &itOuter, &id);
        if (FUN_1413e9590(&itOuter, FUN_1413f7220((char*)e + 0xe0, &kEnd)) != 0) {
            efd::utf8string kTmp;
            ((Unk_KfmEntityAccess*)e)->GetPropertyValueUnsafe(id, *kKey, &kTmp, FUN_1408a2000());
            Unk_Rec rec;
            *(Unk_Rec*)FUN_1413e9b80(FUN_1413e9a80((char*)e + 0xe0, &id), kKey) = *(Unk_Rec*)FUN_140947490(&rec, id, new efd::utf8string(kTmp), FUN_1408a2000());
        } else {
            Unk_It itInner;
            Unk_It kEnd2;
            FUN_1413f8680((char*)FUN_1413e9c00(&itOuter) + 8, &itInner, kKey);
            if (FUN_1413e96d0(&itInner, FUN_1413f7400((char*)FUN_1413e9c00(&itOuter) + 8, &kEnd2)) != 0) {
                efd::utf8string kTmp;
                ((Unk_KfmEntityAccess*)e)->GetPropertyValueUnsafe(id, *kKey, &kTmp, FUN_1408a2000());
                Unk_Rec rec;
                *(Unk_Rec*)FUN_1413e9b80((char*)FUN_1413e9c00(&itOuter) + 8, kKey) = *(Unk_Rec*)FUN_140947490(&rec, id, new efd::utf8string(kTmp), FUN_1408a2000());
            }
        }
    }
}

// @0x1414413b0
void FUN_1414413b0(egf::Entity* e, unsigned id, const efd::utf8string* kKey, efd::utf8string* pVal)
{
    FUN_1414410b0(e, id, kKey, pVal);
    ((Unk_KfmEntityAccess*)e)->SetPropertyValueUnsafe(id, *kKey, pVal, FUN_1408a2000());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2290-0x142cb2320 .text$yd
