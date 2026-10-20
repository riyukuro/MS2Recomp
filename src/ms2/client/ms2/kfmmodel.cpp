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
#include <egmAnimation/AnimationService.h>
#include <egf/EntityManager.h>
#include <efd/Category.h>
#include <NiFloatsExtraData.h>
#include <NiKFMTool.h>
#include <NiTransform.h>
#include <set>
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxD6JointDesc.h>
#include <NxD6Joint.h>
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
    int FUN_140999490(const egf::EntityID& id, const efd::utf8string& kName);                  // sequence id, -2 when absent
    NiActorManager* FUN_140999440(const egf::EntityID& id);
    efd::utf8string FUN_1409a1790(const egf::EntityID& id, unsigned int nSeq);                // name of a sequence
    void FUN_1409a1fc0(const egf::EntityID& id, const efd::utf8string& kName, float fBlend, bool b);   // play
    void FUN_1411766b0(const egf::EntityID& id, unsigned int nSeq, float fBlend, bool b);     // play by sequence id
    efd::utf8string FUN_140b7cc50(const egf::EntityID& id);                                  // current animation name
    char FUN_14227a3d0(const efd::AssetID& kId, void* pReq, efd::Category kCat,
        efd::vector<egmAnimation::KFMCache::KFMCacheHandle>& kHandles);                      // cache a .kfm
    void FUN_14227ffe0(efd::vector<egmAnimation::KFMCache::KFMCacheHandle>& kHandles);       // release the handles
};
Unk_KfmAnimSvc* FUN_141b6f910();

// Effect play request (0x70 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0). Layout as in entityvibrator.cpp.
struct Unk_KfmEffectReq
{
    alignas(8) char m_buf[0x70];
};
void FUN_140a52ef0(Unk_KfmEffectReq* p);
void FUN_1405a89e0(Unk_KfmEffectReq* p);
void FUN_140a53190(Unk_KfmEffectReq* p, int nOwner);
int FUN_141bd1a10(void* pEffectMgr, void* pActor);
void* FUN_1403ed2d0();
void* FUN_1403ed280();
void FUN_1411a4a00(void* pFxMgr, Unk_KfmEffectReq* p);
void* FUN_1409ffd30(void* p);
int FUN_14123c580(void* p);
void* FUN_141200850(CEquipModel* p);

// ---- out-of-unit callees ----
void* FUN_1405a8ed0(void* sp);   void FUN_1405a85c0(void* sp);   void* FUN_1409849b0(void* sp);
void* FUN_1411dc7a0(void* owner, void* out);   void* FUN_14052cd70(void* p);   void FUN_1401bfde0(void* p);
void* FUN_1401c0180(void* p);   int FUN_140527a20(void* p);   void* FUN_1411dc7f0(void* owner);   char FUN_14053cfd0(void* p);
void FUN_141200e30(void* self, int n);   void FUN_141200ca0(void* self);
void* FUN_141200820(void* self);   void* FUN_1412008e0(void* self);   void* FUN_1412009d0(void* self);
void FUN_1412029d0(void* self, CString* out);   void FUN_141202ea0(void* self, CString* s);
void FUN_141202280(void* self, NiTransform* out);
void FUN_141201780(void* self, efd::utf8string* out);
char FUN_1409f77a0(void* sp, int n);   void* FUN_1409475f0(void* sp);   void* FUN_1409475d0(void* sp);
void* FUN_1409478e0(void* p);
int FUN_141422110(void* a, void* b, void* c);
float FUN_141422340(void* self, int n);   void FUN_141167840(void* o, const CString& s, float f);
char FUN_140534e50(void* p);   void* FUN_140527840(void* p);   char FUN_14053d2b0(void* p);   unsigned FUN_1405258b0(void* p);
void* FUN_140527870(void* p);   unsigned FUN_140599fd0(void* o, int i);   void FUN_141b6f000(void* o, int i, void* v);
void* FUN_141b6dea0(void* out, unsigned v);   void* FUN_1414424f0(void* in, void* out, float f);   void FUN_140a0a3a0(void* out, void* in);
void* FUN_1416561a0(void* p);   int FUN_1411e99a0(void* a, unsigned b, void* c, unsigned d, char e);
void* FUN_1409f7cb0(void* p);   void* FUN_14098d8d0(void* tbl, void* key);   void* FUN_14098d0f0(void* sp);
int FUN_141422f30(void* o);
void FUN_14098cb80(void* it, void* o);   void* FUN_14098e0d0(void* it, int n);   void FUN_14098cf00(void* it);
void FUN_140a0b300(void* o, int b);
void FUN_1411ffee0(void* self, double t);
void FUN_1402bd040(float* p);
void FUN_1411dde50(void* owner, void* self);
void FUN_141422b30(void* a, void* b, void* c, void* d, float f);
void FUN_1409f76f0(void* p, void* node);   void FUN_1409fabf0(void* p, void* v);
void FUN_1411de2e0(void* out, void* self);   void FUN_140b02860(void* p);
char FUN_1401c0090(const CString& a, const CString& b);
void FUN_140194470(void* dst, const void* src);
char FUN_140a33ff0(const NiPoint3& p);   void FUN_140a38a50(egf::Entity* e, unsigned id, const void* v);
void FUN_1409457c0(egf::Entity* e, unsigned id, const float& v);
void FUN_14098c6e0(egf::Entity* e, unsigned id, const bool& v);
int FUN_140998250(egf::Entity* e, unsigned id, efd::AssetID* v);
void FUN_140de8bd0(egf::Entity* e, unsigned id, efd::AssetID* v);
egf::Entity* FUN_1408a9090(const void* sp);   egf::Entity* FUN_1408a9280(const void* sp);
char FUN_1408b70b0(const void* sp, int n);   char FUN_140965490(const void* sp, int n);
void* FUN_1408b6b20(void* dst, const void* src);   const void* FUN_1408b76f0(const void* ent);   void FUN_1401cd100(void* dst, int n);
void FUN_1408b6ec0(void* sp, void* v);   void FUN_140964eb0(void* sp, void* v);   void FUN_1408a8720(void* sp);
void FUN_1414737d0(egf::Entity* e);
egf::EntityManager* FUN_1409670f0();
egf::Entity* FUN_1411cf440(egf::EntityManager* m, const egf::EntityID* id);
char FUN_1411cf2d0(egf::EntityManager* m, egf::Entity* e, int n);
void* FUN_1411cec80(egf::EntityManager* m, void* out, efd::utf8string* kName, unsigned long long nId, bool b);
unsigned long long FUN_142132a40(void* p);
void* FUN_1411f91c0();   void FUN_141419f50(void* reg, void* model);   void FUN_14141a000(void* reg, void* model);
char FUN_1413e9750(const efd::AssetID& a, const efd::AssetID& b);
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();   char FUN_141689a10(CPhysXHelper* h, egf::Entity* e);
void FUN_14168a540(CPhysXHelper* h, int n);   void FUN_14168a570(CPhysXHelper* h);
void FUN_141689ec0(CPhysXHelper* h, egf::Entity* e, int n, void* params, int m);
void FUN_1416962d0(void* pModel, void* pPonyTails);
void FUN_140ae1580(void* p);   void FUN_140ae1790(void* p);
efd::SmartPointer<Unk_KfmPhysics> FUN_141209640(CEquipModel* p);
void FUN_140a332d0(NiTransform* p);
void* FUN_140a33f90(void* obj);   void* FUN_140a33de0(NiTransform* a, void* out, void* b);   void FUN_140aacb60(void* obj, const void* xf);
void FUN_140981070(void* obj, const void* p);   void FUN_140ddcca0(void* obj, const void* m);   void FUN_1410b2450(void* obj, float s);
void FUN_14097faa0(void* dst, const void* src);   void FUN_140a33240(void* dst, const void* src);
void FUN_140a0b1f0(void* xf, float* out);
void FUN_1409f72e0(void* m);
const efd::utf8string& FUN_1409a1a90();   char FUN_140de8ea0(const efd::utf8string& a, const efd::utf8string& b);
char FUN_1409a1140(const efd::utf8string& a, const efd::utf8string& b);
CString FUN_1409a2360(const char* psz, int n);   CString FUN_140719190(int v);
const char* FUN_142087e50(const void* kFixed);
size_t FUN_14028b4c0(void* v);   CString* FUN_140fe01a0(void* v, unsigned i);
bool FUN_14028d470(float a, float b);
void FUN_14120a440(void* p, void* v);
void FUN_141205320(void* s);   void FUN_141205530(void* s);
void FUN_141209360(void* list, void* out);   void FUN_141209190(void* list, void* out);
char FUN_140b029f0(void* a, void* b);   void* FUN_140b02a60(void* it);   void FUN_140b02a80(void* it);
void* FUN_141c43700(void* a, int b, unsigned c, int d);
void FUN_141c435b0(void* a, int b, unsigned c);
bool FUN_140d821f0(void* p);
void* FUN_14098db90(void* pClassInfo);   // ClassInfo::GetParent
void FUN_140de91f0(void* pStr);
char FUN_140de0b00(void* pChar, char c);
int FUN_14208c9b0(void* pStr);
void* FUN_14208ae50(void* pStr, void* pOut, int n);

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
        int nLen = FUN_14208c9b0(pUrn);
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
void* FUN_1414f1e70(void* p, void* q, int n);   void* FUN_140ad4ba0();
void FUN_1401bf970(void* out, void* p);   char FUN_1401b5240(void* sp, int n);   void FUN_1401b50d0(void* sp);
void FUN_1414413b0(egf::Entity* e, unsigned id, const efd::utf8string* kKey, efd::utf8string* pVal);
void* FUN_1413f9b70(void* p);   void* FUN_1409995d0(void* p);   void* FUN_1409995c0();
void FUN_14099a7c0(void* a, void* b);   void FUN_140999170(void* a);   void FUN_14099bb80(void* a, void* b, void* c);
void* FUN_140999740(void* a, unsigned b);   void* FUN_140999900(void* a);   void* FUN_1409995f0(void* a, unsigned* n);
void* FUN_1409998f0(void* a);   char FUN_140998dc0(void* a, const char* s);
void* FUN_141203e60(void* p);
void* FUN_141ef6110(void* p);   void* FUN_141d17b40(void* node, void* name);
float FUN_141d57ca0(void* ed, int i);
void* FUN_14120a240(void* svc);   void* FUN_140af8310(void* p);   void* FUN_14086d260();
unsigned FUN_14120ade0(void* svc, const void* id);   void* FUN_14120ae30(void* svc, const void* id, unsigned i);
void* FUN_14120aed0(void* p);   unsigned FUN_14120ac30(void* p);   void* FUN_14120abd0(void* p, void* out, unsigned i);
void* FUN_14120a6e0(void* p);   void FUN_14120a600(void* p);
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
    : CEquipModel(spOwner, p18, p20)
{
    m_nUpdateHR = 0;
    m_nUpdateTransform = 0;
    m_bPhysicsLoaded = 0;
    m_pPhysics = 0;
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
        egf::Entity* pEnt = FUN_1408a9280(&m_spEntity);
        if (FUN_140998250(pEnt, 0x12383cea, &kCur) == 0 && FUN_1413e9750(kCur, kNew) != 0)
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
    egf::EntityID kId = FUN_14143ff70();
    if (FUN_1411cf440(FUN_1409670f0(), &kId) == 0) {
        FUN_141440a70();
        egf::Entity* pEnt2 = FUN_1408a9090(&m_spEntity);
        if (FUN_1411cf2d0(FUN_1409670f0(), pEnt2, 0) != 0)
            FUN_1411dde50(FUN_1405a8ed0(&m_spOwner), this);
    }
    return 1;
}

// @0x14143da90
void CKfmModel::vfunc_5()
{
    alignas(8) char guard[16];
    FUN_1411de2e0(guard, this);
    CEquipModel::vfunc_5();
    FUN_1414409f0();
    m_pPhysics = 0;
    FUN_140b02860(guard);
}

// @0x14143db00
int CKfmModel::vfunc_6()
{
    m_nState = 1;
    if (!m_str38.IsEmpty()) {
        Unk_ModelActor* pActor = (Unk_ModelActor*)FUN_141200820(this);
        if (pActor != 0) {
            efd::AssetID kId((const char*)m_str38, 0, efd::AssetID::NEVER_CACHE);
            efd::vector<egmAnimation::KFMCache::KFMCacheHandle> kHandles;
            efd::Category kCat(g_catKfm);
            if (FUN_141b6f910()->FUN_14227a3d0(kId, 0, kCat, kHandles) == 0)
                FUN_141b6f910()->FUN_14227ffe0(kHandles);
        }
    }
    NiActorManager* pMgr = FUN_1414400d0();
    void* pComp = FUN_141442860(&DAT_143ac2fc0, pMgr);
    if (pComp != 0)
        FUN_140d821f0(pComp);
    if (FUN_1408a9090(&m_spEntity) != 0) {
        FUN_141203e60(this);
        if (DAT_143ae2b30 != 0) {
            egf::EntityID kEntId;
            FUN_1408b6b20(&kEntId, FUN_1408b76f0(FUN_1408a9280(&m_spEntity)));
            FUN_1414f1e70(FUN_140ad4ba0(), &kEntId, 3);
        }
        void* pActorMgr = FUN_1413f9b70((void*)FUN_1408b76f0(FUN_1408a9280(&m_spEntity)));
        if (pActorMgr != 0) {
            if (DAT_143ae2b30 == 0) {
                FUN_14099a7c0(pActorMgr, 0);
                FUN_140999170(pActorMgr);
                NiActorManager::CallbackObject* pCb = (this == 0) ? 0 : static_cast<NiActorManager::CallbackObject*>(this);
                FUN_14099a7c0(pActorMgr, pCb);
            } else {
                NiActorManager::CallbackObject* pCb = (this == 0) ? 0 : static_cast<NiActorManager::CallbackObject*>(this);
                FUN_14099bb80(FUN_1409995c0(), pActorMgr, pCb);
            }
            NiKFMTool* pKfm = (NiKFMTool*)FUN_1409995d0(pActorMgr);
            unsigned int* pIds = 0;
            unsigned int nIds;
            pKfm->GetSequenceIDs(pIds, nIds);
            for (unsigned int i = 0; i < nIds; ++i) {
                unsigned int nSeqId = pIds[i];
                void* pSeq = FUN_140999740(pActorMgr, nSeqId);
                if (pSeq != 0) {
                    void* pTextKeys = FUN_140999900(pSeq);
                    unsigned int nKeys = 0;
                    char* pKey = (char*)FUN_1409995f0(pTextKeys, &nKeys);
                    FUN_141c43700(pActorMgr, 0, nSeqId, 0);
                    FUN_141c43700(pActorMgr, 4, nSeqId, 0);
                    for (unsigned int k = 0; k < nKeys; ++k) {
                        void* pName = FUN_1409998f0(pKey + (unsigned long long)k * 0x10);
                        if (FUN_140998dc0(pName, "start") == 0 && FUN_140998dc0(pName, "end") == 0)
                            FUN_141c435b0(pActorMgr, 3, nSeqId);
                    }
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
    efd::utf8string kIdle("Idle_A");
    CString strA("");
    CString strB("");
    FUN_141440380(strB, strA, kIdle, 1.0f, false);
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
    egf::Entity* pEnt = FUN_1408a9090(&m_spEntity);
    if (FUN_141689a10(FUN_1409f7ca0(), pEnt) == 0)
        return m_nState;
    if (m_nState == 0 || m_bPhysicsLoaded == 0)
        return 0;
    return 1;
}

// @0x14143e240
void CKfmModel::vfunc_10()
{
    m_nUpdateHR = (vfunc_9() == 0);
    if (m_nUpdateHR == 0) {
        void* ow = FUN_1411dc7f0(FUN_1405a8ed0(&m_spOwner));
        if (FUN_14053cfd0(ow) != 0) {
            {
                CString s("HR:0");
                float v = FUN_141422340(this, 0);
                FUN_141167840(vfunc_14(), s, v);
            }
            {
                CString s("HR0:0");
                float v = FUN_141422340(this, 0);
                FUN_141167840(vfunc_14(), s, v);
            }
            {
                CString s("HR1:1");
                float v = FUN_141422340(this, 1);
                FUN_141167840(vfunc_14(), s, v);
            }
        }
    }
}

// @0x14143e3e0
void CKfmModel::vfunc_11()
{
    m_nUpdateTransform = (vfunc_9() == 0);
    if (m_nUpdateTransform == 0) {
        char t40[16];
        void* ow = FUN_1411dc7a0(FUN_1405a8ed0(&m_spOwner), t40);
        void* pPartList = FUN_140527870(FUN_1401c0180(ow));
        FUN_1401bfde0(t40);
        if (pPartList != 0) {
            for (int i = 0; i < 3; ++i) {
                char v80[16];
                FUN_141b6dea0(v80, FUN_140599fd0(pPartList, i));
                if (i == 1) {
                    char t30[12], t24[28], v58[16];
                    void* a = FUN_141b6dea0(t30, FUN_140599fd0(pPartList, 0));
                    void* b = FUN_1414424f0(a, t24, 1.3f);
                    FUN_140a0a3a0(v58, b);
                    memcpy(v80, v58, 12);
                }
                void* pRoot = vfunc_14();
                if (pRoot != 0)
                    FUN_141b6f000(pRoot, i, v80);
                char end[8], it[8];
                alignas(8) char sp[8];
                PAIR_BEGIN(this, it, end);
                while (FUN_140b029f0(it, end) != 0) {
                    new (sp) NiAVObjectPtr(*(NiAVObjectPtr*)FUN_140b02a60(it));
                    if (FUN_1409849b0(sp) != 0)
                        FUN_141b6f000(FUN_1409849b0(sp), i, v80);
                    FUN_1405a85c0(sp);
                    FUN_140b02a80(it);
                }
            }
            Unk_ModelActor* p = (Unk_ModelActor*)FUN_141200820(this);
            if (p != 0)
                p->vfunc_139();
        }
    }
}

// @0x14143e670
void CKfmModel::vfunc_12()
{
    alignas(8) char spItem[16];
    FUN_1401bf970(spItem, FUN_1412009d0(this));
    if (FUN_1401b5240(spItem, 0) == 0) {
        alignas(8) char sbuf[8];
        CString& s = *(CString*)sbuf;
        FUN_1412029d0(this, &s);
        if (!s.IsEmpty()) {
            FUN_141202ea0(this, &s);
            if (FUN_1409f77a0(&m_spNode, 0) == 0) {
                std::set<NiAVObjectPtr> kSet;
                int r = FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &kSet);
                if (r != 0) {
                    char end[8], it[8];
                    alignas(8) char sp[8];
                    FUN_141209360(&kSet, end);
                    FUN_141209190(&kSet, it);
                    while (FUN_140b029f0(it, end) != 0) {
                        new (sp) NiAVObjectPtr(*(NiAVObjectPtr*)FUN_140b02a60(it));
                        if (FUN_1409849b0(sp) != 0) {
                            if (FUN_141440f20()) {
                                void* parent = FUN_1409475f0(&m_spNode);
                                V2(void, parent, 0x120, void*, FUN_1409849b0(sp), int, 1);
                            }
                            m_unk_f8.insert(*(NiAVObjectPtr*)sp);
                        }
                        FUN_1405a85c0(sp);
                        FUN_140b02a80(it);
                    }
                }
            }
        }
        s.~CString();
    }
    FUN_1401b50d0(spItem);
}

// @0x14143e900
void CKfmModel::vfunc_13()
{
    if (CFG->m_bHead == 0) return;
    void* pRootNode = FUN_1412008e0(this);
    if (pRootNode == 0) return;
    NiTransform kXf;
    kXf.MakeIdentity();
    FUN_141202280(this, &kXf);
    Unk_ModelActor* pActor = (Unk_ModelActor*)FUN_141200820(this);
    if (pActor == 0) return;
    char v120[16];
    FUN_1411dc7a0(FUN_1405a8ed0(&m_spOwner), v120);
    if (FUN_140534e50(v120) != 0) {
        FUN_1401bfde0(v120);
        return;
    }
    unsigned char cAttrA = FUN_14053d2b0(FUN_140527840(FUN_1401c0180(v120)));
    unsigned uAttrB = FUN_1405258b0(FUN_1401c0180(v120));
    alignas(8) char sbuf[8];
    CString& s = *(CString*)sbuf;
    FUN_1412029d0(this, &s);
    int nModelKind = FUN_140527a20(FUN_1401c0180(v120));
    int nResult = FUN_1411e99a0(FUN_1416561a0(pActor), nModelKind, &s, uAttrB, cAttrA);
    s.~CString();
    if (nResult != 0) {
        NiFixedString kName("Bip01 Head");
        void* o = FUN_1409f7cb0(pRootNode);
        void* r = V1(void*, o, 0xa0, void*, &kName);
        void* target = FUN_14098d8d0(&DAT_143afa4d8, r);
        kName.~NiFixedString();
        if (target == 0) {
            FUN_1401bfde0(v120);
            return;
        }
        std::set<NiAVObjectPtr> kSet;
        nResult = FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &kSet);
        if (nResult != 0) {
            char end[8], it[8];
            alignas(8) char sp[8];
            FUN_141209360(&kSet, end);
            FUN_141209190(&kSet, it);
            while (FUN_140b029f0(it, end) != 0) {
                new (sp) NiAVObjectPtr(*(NiAVObjectPtr*)FUN_140b02a60(it));
                alignas(8) char tmp[56];
                void* pLocal = FUN_140a33f90(FUN_14098d0f0(sp));
                void* pNew = FUN_140a33de0(&kXf, tmp, pLocal);
                FUN_140aacb60(FUN_14098d0f0(sp), pNew);
                V2(void, target, 0x120, void*, FUN_1409849b0(sp), int, 1);
                m_unk_f8.insert(*(NiAVObjectPtr*)sp);
                FUN_1405a85c0(sp);
                FUN_140b02a80(it);
            }
        }
    }
    FUN_1401bfde0(v120);
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
    char end[8], it[8];
    alignas(8) char sp[8];
    PAIR_BEGIN(this, it, end);
    for (;;) {
        if (FUN_140b029f0(it, end) == 0) return 0;
        new (sp) NiAVObjectPtr(*(NiAVObjectPtr*)FUN_140b02a60(it));
        if (FUN_1409849b0(sp) != 0) {
            if (FUN_141422f30(FUN_1409849b0(sp)) != 0) {
                FUN_1405a85c0(sp);
                return 1;
            }
        }
        FUN_1405a85c0(sp);
        FUN_140b02a80(it);
    }
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
    char bActive;
    if (m_nState == 0 || vfunc_20() == 0)
        bActive = 0;
    else
        bActive = 1;
    char bProp = bActive;
    bool bHide = (bActive == 0);
    char end[8], it[8];
    alignas(8) char sp[8];
    PAIR_BEGIN(this, it, end);
    while (FUN_140b029f0(it, end) != 0) {
        new (sp) NiAVObjectPtr(*(NiAVObjectPtr*)FUN_140b02a60(it));
        char mi[48];
        FUN_14098cb80(mi, FUN_1409849b0(sp));
        void* o;
        while ((o = FUN_14098e0d0(mi, 1)) != 0) {
            void* c = FUN_14098d8d0(&DAT_143afbbb0, o);
            if (c != 0)
                FUN_140a0b300(c, bHide);
        }
        FUN_14098cf00(mi);
        FUN_1405a85c0(sp);
        FUN_140b02a80(it);
    }
    char mi2[56];
    FUN_14098cb80(mi2, vfunc_14());
    void* o2;
    while ((o2 = FUN_14098e0d0(mi2, 1)) != 0) {
        void* c = FUN_14098d8d0(&DAT_143afbbb0, o2);
        if (c != 0)
            FUN_140a0b300(c, bHide);
    }
    FUN_14098c6e0(FUN_1408a9280(&m_spEntity), 0xa0b6b179, (const bool&)bProp);
    FUN_14098cf00(mi2);
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
            if (FUN_141200820(this) != 0) {
                Unk_ModelActor* p = (Unk_ModelActor*)FUN_141200820(this);
                int v = p->vfunc_65();
                vfunc_32(v);
            }
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
    const char* pszAnim = (n == 0) ? "Idle_A" : "Attack_Idle_A";
    efd::utf8string kAnim(pszAnim);
    efd::utf8string kCur = FUN_141b6f910()->FUN_140b7cc50(kId);
    if (FUN_141b6f910()->FUN_140999490(kId, kAnim) != -2) {
        char bSame = FUN_1409a1140(kAnim, kCur);
        FUN_141b6f910()->FUN_1409a1fc0(kId, kAnim, 1.0f, bSame != 0);
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
    if (FUN_140a33ff0(p) != 0) {
        m_pos48 = p;
        if (FUN_1408a9090(&m_spEntity) != 0)
            FUN_140a38a50(FUN_1408a9280(&m_spEntity), 0xfd95ca52, &m_pos48);
    }
}

// @0x14143fa80
void CKfmModel::vfunc_26(const NiPoint3& p)
{
    if (FUN_140a33ff0(p) != 0) {
        m_pos54 = p;
        if (FUN_1408a9090(&m_spEntity) != 0)
            FUN_140a38a50(FUN_1408a9280(&m_spEntity), 0x68c7c29d, &m_pos54);
    }
}

// @0x14143fb10
void CKfmModel::vfunc_29(void* pPos, void* pRotDeg, float fScale)
{
    NiPoint3 a = *(NiPoint3*)pPos;
    vfunc_24(a);
    NiPoint3 b = *(NiPoint3*)pRotDeg;
    vfunc_26(b);
    vfunc_22(fScale);
    std::set<NiAVObjectPtr> kSet;
    FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &kSet);
    FUN_141422b30(this, &kSet, &DAT_143b01a60, &DAT_143b01a60, 1.0f);
}

// @0x14143fc70
void CKfmModel::vfunc_28(void* pPos, void* pMatrix3, float fScale)
{
    float x, y, z;
    FUN_1402bd040(&x);
    ((efd::Matrix3*)pMatrix3)->ToEulerAnglesXYZ(x, y, z);
    x = (x * 180.0f) / 3.1415927f;
    y = (y * 180.0f) / 3.1415927f;
    z = (z * 180.0f) / 3.1415927f;
    float a[3] = { x, y, z };
    vfunc_29(pPos, a, fScale);
}

// @0x14143fd30
void CKfmModel::vfunc_30(void* pPos, void* pRot, float fScale)
{
    NiTransform kXf;
    NiPoint3 kPos = *(NiPoint3*)pPos;
    kXf.m_Translate = kPos;
    kXf.m_Rotate = NiMatrix3(*(NiMatrix3*)pRot);
    kXf.m_fScale = fScale;
    FUN_140aacb60(vfunc_14(), &kXf);
}

// @0x14143fe10
void CKfmModel::vfunc_31()
{
    if (vfunc_9() != 0) {
        if (FUN_14053cfd0(FUN_1412009d0(this)) != 0) {
            int params[4];
            FUN_140ae1580(params);
            params[0] = 0; params[1] = 0; params[2] = 0; params[3] = 0;
            egf::EntityID kId = FUN_14143ff70();
            egf::Entity* pEnt = FUN_1411cf440(FUN_1409670f0(), &kId);
            FUN_141689ec0(FUN_1409f7ca0(), pEnt, 0, params, 0);
            if (CFG->m_bPhysics != 0)
                FUN_1416962d0(this, (char*)m_unk_20 + 0xb8);
            FUN_140ae1790(params);
        }
    }
}

// @0x14143ff20
egf::EntityPtr CKfmModel::FUN_14143ff20()
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
    egf::EntityID kId = FUN_14143ff70();
    return FUN_141b6f910()->FUN_140999440(kId);
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
    const efd::utf8string& kEmpty = FUN_1409a1a90();
    egf::EntityID kId = FUN_14143ff70();
    char bEmpty;
    {
        efd::utf8string kName = FUN_141b6f910()->FUN_1409a1790(kId, nSeq);
        bEmpty = FUN_140de8ea0(kName, kEmpty);
    }
    if (bEmpty != 0) {
        egf::EntityID kId2 = FUN_14143ff70();
        FUN_141b6f910()->FUN_1411766b0(kId2, nSeq, 1.0f, false);
    }
}

// @0x141440380
void CKfmModel::FUN_141440380(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend,
    bool b)
{
    egf::EntityID kId = FUN_14143ff70();
    efd::utf8string kA((const char*)FUN_1409a2360((const char*)strA, 0));
    if (FUN_141b6f910()->FUN_140999490(kId, kA) != -2) {
        FUN_141b6f910()->FUN_1409a1fc0(kId, kA, fBlend, b);
        return;
    }
    efd::utf8string kB = (const char*)FUN_1409a2360((const char*)strB, 0) + kDefault;
    if (FUN_141b6f910()->FUN_140999490(kId, kB) != -2) {
        FUN_141b6f910()->FUN_1409a1fc0(kId, kB, fBlend, b);
        return;
    }
    if (FUN_141b6f910()->FUN_140999490(kId, kDefault) != -2) {
        FUN_141b6f910()->FUN_1409a1fc0(kId, kDefault, fBlend, b);
        return;
    }
    efd::utf8string kIdle("Idle_A");
    if (FUN_141b6f910()->FUN_140999490(kId, kIdle) != -2) {
        efd::utf8string kIdle2("Idle_A");
        FUN_141b6f910()->FUN_1409a1fc0(kId, kIdle2, fBlend, b);
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
    CKfmModel* pModel = (CKfmModel*)((char*)this - 0x118);
    CString strKey(FUN_142087e50(&kTextKey));
    if (strKey.Find("effect_", 0) == 0) {
        void* pActor = FUN_1409ffd30(FUN_141200850(pModel));
        Unk_KfmEffectReq kReq;
        FUN_140a52ef0(&kReq);
        *(CString*)kReq.m_buf = strKey.Right(strKey.GetLength() - 7);
        *(int*)(kReq.m_buf + 8) = FUN_141bd1a10(FUN_1403ed2d0(), pActor);
        FUN_1409fabf0(kReq.m_buf + 0x10, FUN_14098d8d0(&DAT_143afa4d8, pModel->vfunc_14()));
        if (pActor != 0)
            FUN_140a53190(&kReq, FUN_14123c580(pActor));
        FUN_1411a4a00(FUN_1403ed280(), &kReq);
        FUN_1405a89e0(&kReq);
    }
}

// @0x1414408c0
void CKfmModel::EndOfSequence(NiActorManager*, NiActorManager::SequenceID, NiControllerSequence*, float) {}

// @0x1414408e0
void CKfmModel::FUN_1414408e0()
{
    FUN_1414409f0();
    alignas(8) char dummy[8];
    unsigned long long nId = FUN_142132a40(dummy);
    efd::utf8string kName;
    FUN_141201780(this, &kName);
    alignas(8) char spNew[8];
    void* pNew = FUN_1411cec80(FUN_1409670f0(), spNew, &kName, nId, true);
    FUN_140964eb0(&m_spEntity, pNew);
    FUN_1408a8720(spNew);
    FUN_141419f50(FUN_1411f91c0(), this);
}

// @0x1414409f0
void CKfmModel::FUN_1414409f0()
{
    if (FUN_1408b70b0(&m_spEntity, 0) == 0) {
        FUN_14141a000(FUN_1411f91c0(), this);
        FUN_1414737d0(FUN_1408a9090(&m_spEntity));
        FUN_1408b6ec0(&m_spEntity, 0);
    }
}

// @0x141440a70
void CKfmModel::FUN_141440a70()
{
    std::vector<CString>& kNames = CFG->m_arrAnimNames;
    for (unsigned int i = 0; FUN_14028b4c0(&kNames) > i; ++i) {
        efd::utf8string kKey((const char*)FUN_140719190(i));
        efd::utf8string kVal((const char*)*FUN_140fe01a0(&kNames, i));
        FUN_1414413b0(FUN_1408a9280(&m_spEntity), 0xa75781ca, &kKey, &kVal);
    }
}

// @0x141440bc0
void CKfmModel::FUN_141440bc0()
{
    if (CFG->m_bPhysics == 0) return;
    void* ow = FUN_1411dc7f0(FUN_1405a8ed0(&m_spOwner));
    if (FUN_14053cfd0(ow) == 0) return;
    char t88[16];
    void* pData = FUN_140527870(FUN_1401c0180(FUN_1411dc7a0(FUN_1405a8ed0(&m_spOwner), t88)));
    FUN_1401bfde0(t88);
    if (pData == 0) return;
    float fScale = *(float*)((char*)pData + 0x58);
    NiPoint3 kPos = *(NiPoint3*)((char*)pData + 0x60 + (long long)CFG->m_nIndex * 0xc);
    float rot[3];
    memcpy(rot, (char*)pData + 0x78 + (long long)CFG->m_nIndex * 0xc, 12);
    std::set<NiAVObjectPtr> kSet;
    FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &kSet);
    efd::Matrix3 kMat;
    kMat.FromEulerAnglesXYZ((rot[0] * 3.1415927f) / 180.0f, (rot[1] * 3.1415927f) / 180.0f,
        (rot[2] * 3.1415927f) / 180.0f);
    char end[8], it[8];
    alignas(8) char sp[8];
    FUN_141209360(&kSet, end);
    FUN_141209190(&kSet, it);
    while (FUN_140b029f0(it, end) != 0) {
        new (sp) NiAVObjectPtr(*(NiAVObjectPtr*)FUN_140b02a60(it));
        NiPoint3 kP = kPos;
        FUN_140981070(FUN_14098d0f0(sp), &kP);
        alignas(8) char m33[40];
        FUN_140a33240(m33, &kMat);
        FUN_140ddcca0(FUN_14098d0f0(sp), m33);
        FUN_1410b2450(FUN_14098d0f0(sp), fScale);
        FUN_1405a85c0(sp);
        FUN_140b02a80(it);
    }
    vfunc_22(fScale);
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
    if (!FUN_141440f20() && FUN_1409475d0(&m_spNode) != 0) {
        NiTransform* pXf = (NiTransform*)FUN_1409478e0(FUN_1409475f0(&m_spNode));
        NiPoint3 kTrans = pXf->m_Translate;
        NiPoint3 kA = kTrans;
        vfunc_24(kA);
        float rot[3];
        FUN_1402bd040(rot);
        FUN_140a0b1f0(pXf, rot);
        NiPoint3 kRot = *(NiPoint3*)rot;
        vfunc_26(kRot);
    }
}

// @0x14143f3d0
void CKfmModel::FUN_14143f3d0()
{
    if (CFG->m_bPhysics == 0 && CFG->m_bHead == 0 && FUN_14028d470(CFG->m_fScale, 1.0f) != 0)
        return;
    void* pProp = FUN_14120a240(FUN_140af8310((char*)FUN_14086d260() + 8));
    egf::EntityID kId1 = FUN_14143ff70();
    unsigned int nJoints = FUN_14120ade0(pProp, &kId1);
    NiObjectNET* pNode = (NiObjectNET*)FUN_1412018c0(this);
    if (pNode == 0)
        return;
    for (unsigned int i = 0; i < nJoints; ++i) {
        egf::EntityID kId2 = FUN_14143ff70();
        void* pInfo = FUN_14120ae30(pProp, &kId2, i);
        if (pInfo == 0) continue;
        void* pSet = FUN_14120aed0(pInfo);
        if (pSet == 0) continue;
        unsigned int nCount = FUN_14120ac30(pSet);
        for (unsigned int j = 0; j < nCount; ++j) {
            alignas(8) char hnd[8];
            void* pH = FUN_14120abd0(pSet, hnd, j);
            void* pComp = FUN_14098d8d0(&DAT_143afc8c0, FUN_14120a6e0(pH));
            FUN_14120a600(hnd);
            if (pComp == 0) continue;
            void* pJoint = FUN_141ef6110(pComp);
            if (pJoint == 0) continue;
            NxD6JointDesc kDesc;
            V1(void, pJoint, 0xd0, NxD6JointDesc*, &kDesc);
            CString strName(V0(const char*, pJoint, 0xb8));
            for (int k = 0; k < 2; ++k) {
                CString strKey;
                strKey.Format("%s%d", (const char*)strName, k);
                NiFixedString kFixed((const char*)strKey);
                NiFloatsExtraData* pExtra = (NiFloatsExtraData*)FUN_14098d8d0(&DAT_143afafe0, FUN_141d17b40(pNode, &kFixed));
                kFixed.~NiFixedString();
                if (pExtra == 0) {
                    float v[3] = { kDesc.localAnchor[k].x, kDesc.localAnchor[k].y, kDesc.localAnchor[k].z };
                    pExtra = EE_NEW NiFloatsExtraData(3, v);
                    NiFixedString kFixed2((const char*)strKey);
                    pNode->AddExtraData(kFixed2, pExtra);
                    kFixed2.~NiFixedString();
                    kDesc.localAnchor[k] = kDesc.localAnchor[k] * m_fScale44;
                } else {
                    kDesc.localAnchor[k].x = FUN_141d57ca0(pExtra, 0) * m_fScale44;
                    kDesc.localAnchor[k].y = FUN_141d57ca0(pExtra, 1) * m_fScale44;
                    kDesc.localAnchor[k].z = FUN_141d57ca0(pExtra, 2) * m_fScale44;
                }
            }
            FUN_14168a540(FUN_1409f7ca0(), 1);
            V1(void, pJoint, 200, NxD6JointDesc*, &kDesc);
            FUN_14168a570(FUN_1409f7ca0());
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
char FUN_1413e9590(void* a, void* b);   void* FUN_1413e9c00(void* it);
void* FUN_1413f8680(void* tbl, void* out, const efd::utf8string* kKey);   void* FUN_1413f7400(void* tbl, void* out);
char FUN_1413e96d0(void* a, void* b);   void* FUN_1413e9a80(void* tbl, unsigned* pId);
void* FUN_1413e9b80(void* tbl, const efd::utf8string* kKey);   void* FUN_140947490(void* out, unsigned id, void* p, unsigned nType);
void* FUN_1409a0f10(void* mem, efd::utf8string* kSrc);

// @0x1414410b0
void FUN_1414410b0(egf::Entity* e, unsigned id, const efd::utf8string* kKey, void* pVal)
{
    Unk_KfmEntityAccess* pEnt = (Unk_KfmEntityAccess*)e;
    if (*((char*)e + 0xc8) == 0)
        return;
    void* pTbl = (char*)e + 0xe0;
    alignas(8) char itOuter[8], endOuter[8], itInner[8], endInner[8];
    FUN_1413f83e0(pTbl, itOuter, &id);
    FUN_1413f7220(pTbl, endOuter);
    if (FUN_1413e9590(itOuter, endOuter) != 0) {
        efd::utf8string kTmp;
        pEnt->GetPropertyValueUnsafe(id, *kKey, &kTmp, FUN_1408a2000());
        void* pMem = operator new(0x20);
        void* pCopy = pMem ? FUN_1409a0f10(pMem, &kTmp) : 0;
        alignas(8) char rec[0x18];
        void* r = FUN_140947490(rec, id, pCopy, FUN_1408a2000());
        void* pSlot = FUN_1413e9b80(FUN_1413e9a80(pTbl, &id), kKey);
        memcpy(pSlot, r, 0x18);
    } else {
        FUN_1413f8680((char*)FUN_1413e9c00(itOuter) + 8, itInner, kKey);
        FUN_1413f7400((char*)FUN_1413e9c00(itOuter) + 8, endInner);
        if (FUN_1413e96d0(itInner, endInner) != 0) {
            efd::utf8string kTmp;
            pEnt->GetPropertyValueUnsafe(id, *kKey, &kTmp, FUN_1408a2000());
            void* pMem = operator new(0x20);
            void* pCopy = pMem ? FUN_1409a0f10(pMem, &kTmp) : 0;
            alignas(8) char rec[0x18];
            void* r = FUN_140947490(rec, id, pCopy, FUN_1408a2000());
            void* pSlot = FUN_1413e9b80((char*)FUN_1413e9c00(itOuter) + 8, kKey);
            memcpy(pSlot, r, 0x18);
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
