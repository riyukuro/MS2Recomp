// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Entity / scene-graph helper functions (service accessors, scene root and
// camera lookup, node traversal, entity property helpers, CP949 <-> Johab <-> Unicode string conversion, Korean josa selection)
// plus the template glue they instantiate (efd::vector<NiDynamicEffect*>, GetSystemServiceAs<T>).
// File and function names are invented (the exe has only the local class NodeHelper::FindNode::SceneNodeFunctor to go by).
// MS2-UNIT: unit_1413f9810
// MS2-RANGE: 0x1400f4ea0-0x1400f4f00 .text$di
// MS2-RANGE: 0x1413f9810-0x1413fc9d0 .text$mn
// MS2-RANGE: 0x142cb1580-0x142cb1600 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$DynamicCast@VCameraService@ecr@@VISystemService@efd@@@efd@@YAPEAVCameraService@ecr@@PEAVISystemService@0@@Z 0x1413fb590 ; unique
// MS2-PIN: ??$GetService@VCameraService@ecr@@@@YAPEAVCameraService@ecr@@XZ 0x1413fb6e0 ; unique
// MS2-PIN: ??$GetSystemServiceAs@VCameraService@ecr@@@Unk_ServiceManager@@QEBAPEAVCameraService@ecr@@XZ 0x1413fb800 ; unique
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <string>
#include <atlstr.h>
#include <efd/AssetID.h>
#include <efd/Point3.h>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiCloningProcess.h>
#include <NiDefaultClickRenderStep.h>
#include <NiViewRenderClick.h>
#include <Ni3DRenderView.h>
#include <NiDynamicEffect.h>
#include <egf/Entity.h>
#include <egf/EntityLoaderService.h>
#include <ecr/SceneGraphService.h>
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/client/ms2/entityinstancing.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (names invented) --------------------------------------------------------------------------
class EntityWorldManager;
struct Unk_NHEntIter { void* m_a; void* m_b; };                            // iterator over the world's entities (16 bytes)
struct Unk_NHFramework { void* m_0; void* m_svc; };                       // object at FUN_14086d260(); +8 holds the service manager pointer
class Unk_NHSvc;                                                          // service returned from the framework (FUN_14098c5b0)

// smart pointer to a framework service (ctor 0x14098c7d0, dtor 0x14098cc60)
class Unk_NHSvcPtr
{
public:
    Unk_NHSvcPtr(Unk_NHSvc* p);                                           // 0x14098c7d0
    ~Unk_NHSvcPtr();                                                      // 0x14098cc60
    Unk_NHSvc* FUN_14098d0e0() const;                                     // operator->
    void* FUN_14098d090() const;                                           // operator bool (returns the pointer)
private:
    void* m_p;
};

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class, see nifanimationservice.cpp).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x28);

// effect object configured by FUN_1413f9ba0 (only the members used here)
struct Unk_NHXform { float m_f[10]; };
MS2_CHECK_SIZE(Unk_NHXform, 0x28);
class Unk_NHPt3 { public: Unk_NHPt3(float x, float y, float z); float x, y, z; };       // 0x14097f250
class Unk_NHEffect
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32();
    virtual void vfunc_33();                                              // 0x108
    void FUN_140aacbb0(const Unk_NHXform& x);
    void FUN_140aacbe0(float f);
    void FUN_140aacc00(const Unk_NHPt3& p);
};

// ---- externs (unrecovered exe code; names are the exe addresses) ---------------------------------------------------------
Unk_NHFramework* FUN_14086d260();
Unk_ServiceManager* FUN_140af8310(void* pHolder);
void FUN_140a33240(Unk_NHXform* out, const void* pSrc);
extern char DAT_143a09600;
Unk_NHSvc* FUN_14098c5b0(void* pFramework);
extern char DAT_143b059e8;
void FUN_1413d6ab0(Unk_NHSvc* p, bool b);
ecr::RenderSurface* FUN_140af7da0(ecr::RenderService* p);
bool FUN_140998dc0(const NiFixedString& s, const char* psz);
void* FUN_14200aae0(ecr::CameraService* pService, ecr::RenderSurface* pTarget);
void* FUN_142008b80(void* p);
void* FUN_1410a68d0();
void* FUN_140999440(void* a, unsigned __int64 id);
void* FUN_1411d14b0(Unk_ServiceManager* m);
void* FUN_1411ab8a0(Unk_ServiceManager* m);
efd::MessageService* FUN_1411d1530(Unk_ServiceManager* m);
void* FUN_140af2a30(Unk_ServiceManager* m);
ecr::RenderService* FUN_1411d15b0(Unk_ServiceManager* m);
ecr::SceneGraphService* FUN_1409a5730(Unk_ServiceManager* m);
void* FUN_140d86bf0(Unk_ServiceManager* m);

// ---- more unit-local placeholders / externs ------------------------------------------------------------------------------
class Unk_NHEntMgr;                                                      // entity iteration source (FUN_1409670f0)
class Unk_NHEntAccess;                                                   // property accessor (see fieldpropertycli.cpp)
Unk_NHEntMgr* FUN_1409670f0();
void FUN_1411ce4c0(Unk_NHEntMgr* p, Unk_NHEntIter* it);
bool FUN_1411ce510(Unk_NHEntMgr* p, Unk_NHEntIter* it, egf::Entity** ppOut);
egf::Entity* FUN_1411cf440(Unk_NHEntMgr* p, unsigned __int64 id);
bool FUN_142087f40(const NiFixedString& s, const char* psz);
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);
void FUN_140981100(NiProperty* p, bool b);
void FUN_14098f4d0(NiAVObject* p, bool b);
int FUN_1408a2060(egf::Entity* e, unsigned id, efd::utf8string* out);
int FUN_1408a20a0(egf::Entity* e, unsigned id, bool* out);
int FUN_140998250(egf::Entity* e, unsigned id, efd::AssetID* out);
int FUN_1408a01e0(CStringA kText);
void FUN_140b27ec0(Unk_NHEntAccess* e, unsigned id, efd::Point3* p);
CStringW FUN_14016a730(const char* psz, unsigned cp);
CStringA FUN_14016a600(const wchar_t* psz, unsigned cp);
extern efd::AssetID DAT_143a0acf8;
void FUN_14025a680(const CStringW&, ATL::CAtlArray<CStringW>&, const wchar_t*);
size_t FUN_14015a000(ATL::CAtlArray<CStringW>&);
CStringW& FUN_140159a00(ATL::CAtlArray<CStringW>&, size_t);

// GetService<T>: the framework's service manager, asked for system service T (instances at 0x1413fb6e0 / 0x1413fb740, which
// in turn instantiate Unk_ServiceManager::GetSystemServiceAs<T> at 0x1413fb800 / 0x1413fb840).
Unk_ServiceManager* FUN_1413f9850();
template <class T> T* GetService() { return FUN_1413f9850()->GetSystemServiceAs<T>(); }

// tail wrappers defined below (service accessors whose manager call is another unit's COMDAT)
void* FUN_1413fb700();
void* FUN_1413fb720();
efd::MessageService* FUN_1413fb760();
void* FUN_1413fb780();
ecr::RenderService* FUN_1413fb7a0();
ecr::SceneGraphService* FUN_1413fb7c0();
void* FUN_1413fb7e0();

// ---- file-scope strings (.text$di) -------------------------------------------------------------------------------------
// @0x1400f4ea0
static CString s_skill("skill");
// @0x1400f4ed0
static CString s_stun("stun");

// ---- service accessors -------------------------------------------------------------------------------------------------
// @0x1413f9810
void* FUN_1413f9810() { return FUN_1413fb7e0(); }
MS2_REPLACE(0x1413F9810, FUN_1413f9810, 14, 0xE0176E0C);
// @0x1413f9830
efd::MessageService* FUN_1413f9830() { return FUN_1413fb760(); }
MS2_REPLACE(0x1413F9830, FUN_1413f9830, 14, 0x11E32E6C);
// @0x1413f9850
Unk_ServiceManager* FUN_1413f9850() { return FUN_140af8310(&FUN_14086d260()->m_svc); }
MS2_REPLACE(0x1413F9850, FUN_1413f9850, 26, 0xC8CC15AE);
// @0x1413f9870
void* FUN_1413f9870() { return FUN_1413fb720(); }
MS2_REPLACE(0x1413F9870, FUN_1413f9870, 14, 0x6D86080D);
// @0x1413f9890
ecr::RenderService* FUN_1413f9890() { return FUN_1413fb7a0(); }
MS2_REPLACE(0x1413F9890, FUN_1413f9890, 14, 0x3083754C);
// @0x1413f98b0
ecr::SceneGraphService* FUN_1413f98b0() { return FUN_1413fb7c0(); }
MS2_REPLACE(0x1413F98B0, FUN_1413f98b0, 14, 0x3083754C);
// @0x1413f98d0
ecr::RenderSurface* FUN_1413f98d0() { return FUN_140af7da0(FUN_1413f9890()); }
MS2_REPLACE(0x1413F98D0, FUN_1413f98d0, 22, 0xDB3697F6);
// @0x1413f98f0
void* FUN_1413f98f0() { return FUN_1413fb780(); }
MS2_REPLACE(0x1413F98F0, FUN_1413f98f0, 14, 0x56DD25ED);
// @0x1413f9910
ecr::CameraService* FUN_1413f9910() { return GetService<ecr::CameraService>(); }
MS2_REPLACE(0x1413F9910, FUN_1413f9910, 14, 0xDD60EADA);
// @0x1413f9930
NiRenderFrame* FUN_1413f9930() { return FUN_1413f98d0()->GetRenderFrame(); }
MS2_REPLACE(0x1413F9930, FUN_1413f9930, 22, 0x0B440CE1);

// @0x1413f9950
void* FUN_1413f9950()
{
    ecr::RenderSurface* pTarget = FUN_1413f98d0();
    if (pTarget != 0) {
        void* pCamera = FUN_14200aae0(FUN_1413f9910(), pTarget);
        if (pCamera != 0)
            return FUN_142008b80(pCamera);
    }
    return 0;
}
MS2_REPLACE(0x1413F9950, FUN_1413f9950, 72, 0xBFE082CE);

// The "SceneGraphClick" render click of the main surface.
// @0x1413f99a0
NiViewRenderClick* FUN_1413f99a0()
{
    ecr::RenderService* pService = FUN_1413f9890();
    NiDefaultClickRenderStep* pClickStep = NiDynamicCast(NiDefaultClickRenderStep, FUN_140af7da0(pService)->GetRenderStep());
    NiViewRenderClick* pResult = 0;
    NiTPointerList<NiRenderClickPtr>& kClicks = pClickStep->GetRenderClickList();
    NiTListIterator kPos = kClicks.GetHeadPos();
    while (kPos != 0) {
        pResult = NiDynamicCast(NiViewRenderClick, kClicks.GetNext(kPos));
        if (pResult != 0) {
            if (FUN_140998dc0(pResult->GetName(), "SceneGraphClick"))
                return pResult;
        }
    }
    return 0;
}
MS2_REPLACE(0x1413F99A0, FUN_1413f99a0, 198, 0x7B349F4F);

// The "Render View" 3D render view of the scene graph click.
// @0x1413f9a70
Ni3DRenderView* FUN_1413f9a70()
{
    NiTPointerList<NiRenderViewPtr>& kViews = FUN_1413f99a0()->GetRenderViews();
    NiTListIterator kPos = kViews.GetHeadPos();
    Ni3DRenderView* pResult;
    while (kPos != 0) {
        pResult = NiDynamicCast(Ni3DRenderView, kViews.GetNext(kPos));
        if (pResult != 0) {
            if (FUN_140998dc0(pResult->GetName(), "Render View"))
                return pResult;
        }
    }
    return 0;
}
MS2_REPLACE(0x1413F9A70, FUN_1413f9a70, 144, 0x1355C9B9);

// @0x1413f9b10
void* FUN_1413f9b10() { return FUN_1410a68d0(); }
MS2_REPLACE(0x1413F9B10, FUN_1413f9b10, 14, 0x6C309163);
// @0x1413f9b30
void* FUN_1413f9b30() { return FUN_1413fb700(); }
MS2_REPLACE(0x1413F9B30, FUN_1413f9b30, 14, 0xC45E29F8);
// @0x1413f9b50
egf::EntityLoaderService* FUN_1413f9b50() { return GetService<egf::EntityLoaderService>(); }
MS2_REPLACE(0x1413F9B50, FUN_1413f9b50, 14, 0xCE7DBF18);
// @0x1413f9b70
void* FUN_1413f9b70(unsigned __int64 id) { return FUN_140999440(FUN_1413f9b10(), id); }
MS2_REPLACE(0x1413F9B70, FUN_1413f9b70, 32, 0x15F69FD7);

// @0x1413f9ba0
void FUN_1413f9ba0(Unk_NHEffect* pEffect)
{
    if (pEffect != 0) {
        Unk_NHXform kXform;
        FUN_140a33240(&kXform, &DAT_143a09600);
        pEffect->FUN_140aacbb0(kXform);
        pEffect->FUN_140aacbe0(1.0f);
        pEffect->FUN_140aacc00(Unk_NHPt3(0.0f, 0.0f, 0.0f));
        pEffect->vfunc_33();
    }
}
MS2_REPLACE(0x1413F9BA0, FUN_1413f9ba0, 151, 0xA4EE9233);

// @0x1413f9c40
void FUN_1413f9c40(bool bFlag)
{
    Unk_NHSvcPtr spSvc(FUN_14098c5b0(&DAT_143b059e8));
    if (spSvc.FUN_14098d090() != 0)
        FUN_1413d6ab0(spSvc.FUN_14098d0e0(), bFlag);
}
MS2_REPLACE(0x1413F9C40, FUN_1413f9c40, 97, 0x864DB9EB);


// ---- forward declarations (functions defined further down) ----------------------------------------------------------------
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);       // NiNode-checked dynamic cast through an NiRTTI
NiNode* FUN_1413fa030(egf::Entity* pEntity);
void FUN_1413fa580(std::string kIn, std::string* pOut);
void FUN_1413fa8e0(std::string kIn, std::string* pOut);
void FUN_1413fa820(std::string kIn, std::wstring* pOut);
void FUN_1413fb0f0(std::string kIn, std::string* pOut);
const wchar_t* FUN_1413fb330(const char* pcText, unsigned int uiCodePage);
const char* FUN_1413fb400(const wchar_t* pwText, unsigned int uiCodePage);
void FUN_1413fb630(egf::Entity* pEntity, efd::vector<NiMesh*>* pMeshes);
template <class Functor> bool FUN_1413fb4d0(NiAVObject* pObject, Functor& kFunctor);

struct NodeHelper { static bool FindNode(NiAVObject* pRoot, NiAVObject* pNode); };

// ---- scene graph helpers ---------------------------------------------------------------------------------------------------

// Clones a scene graph root, strips its children and registers the bare clone with the scene graph service.
// @0x1413f9cb0
NiNode* FUN_1413f9cb0(NiObject* pkObject, ecr::SceneGraphService::SceneGraphHandle* pHandle)
{
    NiCloningProcess kCloning(37);
    kCloning.m_eCopyType = NiObjectNET::COPY_EXACT;
    kCloning.m_eDynamicEffectRelationBehavior = NiCloningProcess::CLONE_RELATION_ALL;
    kCloning.m_eAffectedNodeRelationBehavior = NiCloningProcess::CLONE_RELATION_ALL;
    NiNode* pkNode = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, pkObject->Clone(kCloning)));
    for (unsigned int i = 0; i < pkNode->GetArrayCount(); ++i)
        pkNode->DetachChildAt(i);
    if (pHandle != 0) {
        efd::vector<NiObjectPtr> kObjects;
        {
            NiObjectPtr spNode(pkNode);
            kObjects.push_back(spNode);
        }
        *pHandle = FUN_1413f98b0()->AddSceneGraph(kObjects, true, true);
    }
    return pkNode;
}
MS2_REPLACE(0x1413F9CB0, FUN_1413f9cb0, 325, 0x56E97F62);

// @0x1413f9e00
void FUN_1413f9e00(egf::Entity* pEntity, ecr::SceneGraphService::SceneGraphHandle* pHandle)
{
    FUN_1413f9cb0(FUN_1413fa030(pEntity), pHandle);
}
MS2_REPLACE(0x1413F9E00, FUN_1413f9e00, 42, 0xCFDCB8F8);

// Does the scene graph below pRoot contain pNode? (the local functor stops the traversal at the node)
// @0x1413f9e30
bool NodeHelper::FindNode(NiAVObject* pRoot, NiAVObject* pNode)
{
    class SceneNodeFunctor
    {
    public:
        // @0x1413fc100
        SceneNodeFunctor(NiAVObject* pTarget) : m_pTarget(pTarget) {}
        // @0x1413fc180
        virtual bool vfunc_0(NiAVObject* pObject)
        {
            if (m_pTarget == pObject)
                return false;
            return true;
        }
        NiAVObject* m_pTarget;
    };
    SceneNodeFunctor kFunctor(pNode);
    if (!FUN_1413fb4d0(pRoot, kFunctor))
        return true;
    return false;
}
MS2_REPLACE(0x1413F9E30, NodeHelper::FindNode, 62, 0x4726E06C);

// Collects the dynamic effects of an entity's scene graph.
// @0x1413f9e80
void FUN_1413f9e80(egf::Entity* pEntity, efd::vector<NiDynamicEffect*>* pEffects)
{
    NiAVObject* pkScene = FUN_1413f98b0()->GetSceneGraphFromEntity(pEntity);
    NiNode* pkNode;
    if (pkScene != 0 && (pkNode = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, pkScene))) != 0) {
        const NiDynamicEffectList& kList = pkNode->GetEffectList();
        if (kList.GetSize() != 0) {
            NiTListIterator kPos = kList.GetHeadPos();
            NiDynamicEffect* pkEffect;
            while ((pkEffect = kList.Get(kPos)) != 0) {
                pEffects->push_back(pkEffect);
                kPos = kList.GetNextPos(kPos);
                if (kPos == 0)
                    return;
                if (kPos == kList.GetTailPos()) {
                    pEffects->push_back(kList.Get(kPos));
                    return;
                }
            }
        }
    }
}
MS2_REPLACE(0x1413F9E80, FUN_1413f9e80, 261, 0x6D1EB66C);

// The scene graph named "Scene Root" among all entities.
// @0x1413f9f90
NiNode* FUN_1413f9f90()
{
    egf::Entity* pEntity = 0;
    Unk_NHEntIter kIter;
    FUN_1411ce4c0(FUN_1409670f0(), &kIter);
    NiAVObject* pkScene;
    while (FUN_1411ce510(FUN_1409670f0(), &kIter, &pEntity)) {
        pkScene = FUN_1413f98b0()->GetSceneGraphFromEntity(pEntity);
        if (pkScene != 0) {
            if (FUN_142087f40(pkScene->GetName(), "Scene Root"))
                return static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, pkScene));
        }
    }
    return 0;
}
MS2_REPLACE(0x1413F9F90, FUN_1413f9f90, 152, 0x9962FE8E);

// @0x1413fa030
NiNode* FUN_1413fa030(egf::Entity* pEntity)
{
    return static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1413f98b0()->GetSceneGraphFromEntity(pEntity)));
}
MS2_REPLACE(0x1413FA030, FUN_1413fa030, 47, 0x82637247);

// @0x1413fa070
NiNode* FUN_1413fa070(unsigned __int64 id)
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), id);
    if (pEntity != 0) {
        return static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1413f98b0()->GetSceneGraphFromEntity(pEntity)));
    } else {
        return 0;
    }
}
MS2_REPLACE(0x1413FA070, FUN_1413fa070, 82, 0x52B06117);

// @0x1413fa0d0
efd::AssetID FUN_1413fa0d0(egf::Entity* pEntity)
{
    efd::AssetID kId(DAT_143a0acf8);
    if (FUN_140998250(pEntity, 0x770e5fc6, &kId) == 0)
        return kId;
    return DAT_143a0acf8;
}
MS2_REPLACE(0x1413FA0D0, FUN_1413fa0d0, 207, 0x9C2AC7F3);

// Detaches every mesh of an entity from its parent.
// MS2-FUNCTIONAL: efd::vector iterator copies/temps differ from the exe's range loop (frame 0x78 vs 0x88)
// @0x1413fa1b0
void FUN_1413fa1b0(egf::Entity* pEntity)
{
    efd::vector<NiMesh*> kMeshes;
    FUN_1413fb630(pEntity, &kMeshes);
    for (NiMesh* pkMesh : kMeshes)
        pkMesh->GetParent()->DetachChild(pkMesh);
}
MS2_REPLACE(0x1413FA1B0, FUN_1413fa1b0, 232, 0xC57CBF3D);

// @0x1413fa2a0
bool FUN_1413fa2a0(egf::Entity* pEntity)
{
    bool bValue = true;
    FUN_1408a20a0(pEntity, 0xd89e9b12, &bValue);
    return bValue;
}
MS2_REPLACE(0x1413FA2A0, FUN_1413fa2a0, 44, 0xB3C8E4E0);

// @0x1413fa2e0
bool FUN_1413fa2e0(egf::Entity* pEntity)
{
    bool bValue = true;
    FUN_1408a20a0(pEntity, 0x90d6d437, &bValue);
    return bValue;
}
MS2_REPLACE(0x1413FA2E0, FUN_1413fa2e0, 44, 0x7EEE2184);

// @0x1413fa320
efd::Point3 FUN_1413fa320(Unk_NHEntAccess* pEntity)
{
    efd::Point3 kValue(0.70588237f, 0.70588237f, 0.70588237f);
    FUN_140b27ec0(pEntity, 0x213f5f94, &kValue);
    return kValue;
}
MS2_REPLACE(0x1413FA320, FUN_1413fa320, 102, 0xE69C262A);

// Is the entity's resource valid (named "None" aside, either flagged or a 64 character hash)?
// @0x1413fa390
bool FUN_1413fa390(egf::Entity* pEntity)
{
    bool bFlag;
    if (pEntity == 0)
        return false;
    efd::utf8string kName("None");
    if (FUN_1408a2060(pEntity, 0x15014205, &kName) != 0)
        return false;
    bFlag = false;
    if (FUN_1408a20a0(pEntity, 0xa9487f97, &bFlag) != 0)
        return false;
    return (bFlag || FUN_1408a01e0(CStringA(kName.c_str())) == 0x40) ? 1 : 0;
}

// @0x1413fa4c0
void FUN_1413fa4c0(egf::Entity* pEntity)
{
    NiAVObject* pkRoot = FUN_141b6efc0(pEntity);
    if (pkRoot == 0)
        return;
    Unk_SceneWalker kWalker(pkRoot);
    NiAVObject* pkObject;
    while ((pkObject = kWalker.Next(true)) != 0) {
        NiProperty* pkProp = pkObject->GetProperty(0xb);
        if (pkProp == 0)
            continue;
        FUN_140981100(pkProp, true);
    }
    pkRoot->UpdateProperties();
    FUN_14098f4d0(pkRoot, FUN_1413fa390(pEntity));
}
MS2_REPLACE(0x1413FA4C0, FUN_1413fa4c0, 186, 0x5DE9E22A);

// ---- CP949 / Johab / Unicode conversion -----------------------------------------------------------------------------------
// @0x1413fa580
void FUN_1413fa580(std::string kIn, std::string* pOut)
{
    *pOut = FUN_1413fb400(FUN_1413fb330(kIn.c_str(), 0x3b5), 0x551);
}

// @0x1413fa5e0
void FUN_1413fa5e0(std::string kIn, std::string* pOut)
{
    *pOut = FUN_1413fb400(FUN_1413fb330(kIn.c_str(), 0x551), 0x3b5);
}

// @0x1413fa640
void FUN_1413fa640(std::string kIn, std::wstring* pOut)
{
    std::string kJohab;
    FUN_1413fa580(std::string(kIn), &kJohab);
    std::string kJamo;
    FUN_1413fb0f0(std::string(kJohab), &kJamo);
    *pOut = FUN_1413fb330(kJamo.c_str(), 0x551);
}

// @0x1413fa760
void FUN_1413fa760(std::string kIn, std::string* pOut)
{
    std::wstring kWide;
    FUN_1413fa640(std::string(kIn), &kWide);
    *pOut = FUN_1413fb400(kWide.c_str(), 0x3b5);
}

// @0x1413fa820
void FUN_1413fa820(std::string kIn, std::wstring* pOut)
{
    std::string kJamo;
    FUN_1413fa8e0(std::string(kIn), &kJamo);
    *pOut = FUN_1413fb330(kJamo.c_str(), 0x551);
}

// @0x1413fa8e0
void FUN_1413fa8e0(std::string kIn, std::string* pOut)
{
    FUN_1413fb0f0(std::string(kIn), pOut);
}

// @0x1413fa940
void FUN_1413fa940(std::wstring kIn, std::wstring* pOut)
{
    FUN_1413fa820(std::string(FUN_1413fb400(kIn.c_str(), 0x551)), pOut);
}

// @0x1413fa9b0
CStringW FUN_1413fa9b0(const CStringW& kIn)
{
    std::wstring kWide((const wchar_t*)kIn);
    std::wstring kOut;
    FUN_1413fa940(std::wstring(kWide), &kOut);
    return CStringW(kOut.c_str());
}
MS2_REPLACE(0x1413FA9B0, FUN_1413fa9b0, 236, 0x1D84D70F);

// Final consonant test: 0 = none (open syllable), 1 = has one, 2 = not a Hangul syllable or digit.
// @0x1413faab0
int FUN_1413faab0(wchar_t wc)
{
    if (wc >= 0xac00 && wc <= 0xd7a3) {
        if ((wc - 0xac00) % 28 == 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (wc >= L'0' && wc <= L'9') {
        int iDigit = wc - L'0';
        if (iDigit == 2 || iDigit == 4 || iDigit == 5 || iDigit == 9) {
            return 0;
        } else {
            return 1;
        }
    }
    return 2;
}
MS2_REPLACE(0x1413FAAB0, FUN_1413faab0, 144, 0x76201C02);

// Same with the rieul exception (final consonant 8).
// @0x1413fab50
int FUN_1413fab50(wchar_t wc)
{
    if (wc >= 0xac00 && wc <= 0xd7a3) {
        if ((wc - 0xac00) % 28 == 0 || (wc - 0xac00) % 28 == 8) {
            return 0;
        } else {
            return 1;
        }
    } else if (wc >= L'0' && wc <= L'9') {
        int iDigit = wc - L'0';
        if (iDigit == 2 || iDigit == 4 || iDigit == 5 || iDigit == 9) {
            return 0;
        } else {
            return 1;
        }
    }
    return 2;
}
MS2_REPLACE(0x1413FAB50, FUN_1413fab50, 169, 0x98F7441E);

// Resolves a "$a, b$" josa placeholder in kText by the last character of kWord.
// MS2-FUNCTIONAL: frame slot order of the hidden iSecond/retval flag differs (iSecond lands at +0x38 not +0x28)
// @0x1413fac10
CStringW FUN_1413fac10(CStringW kText, CStringW kWord)
{
    int iFirst = 0;
    int iSecond;
    CStringW kResult(kText);
    iFirst = kText.Find(L"$", iFirst);
    if (iFirst != -1) {
        iSecond = kText.Find(L"$", iFirst + 1);
        if (iSecond == -1)
            return CStringW(L"");
        CStringW kToken = kText.Mid(iFirst);
        kToken.Remove(L'$');
        ATL::CAtlArray<CStringW> kParts;
        FUN_14025a680(kToken, kParts, L", ");
        if (FUN_14015a000(kParts) != 2)
            return CStringW(L"");
        if (kWord.GetLength() == 0)
            return CStringW(L"");
        wchar_t wcLast = kWord.GetAt(kWord.GetLength() - 1);
        int iType = FUN_1413faab0(wcLast);
        CStringW* pJosa;
        if (iType == 1)
            pJosa = &FUN_140159a00(kParts, 1);
        else
            pJosa = &FUN_140159a00(kParts, 0);
        CStringW kJosa(*pJosa);
        kResult.Delete(iFirst, (iSecond - iFirst) + 1);
        kResult.Insert(iFirst, (const wchar_t*)kJosa);
    }
    return kResult;
}

// Is the code a Hangul syllable or jamo?
// @0x1413faf90
int FUN_1413faf90(wchar_t wc)
{
    if (wc >= 0xac00 && wc <= 0xd7a3)
        return 1;
    if (wc >= 0x1100 && wc <= 0x11f9)
        return 1;
    if (wc >= 0x3130 && wc <= 0x318f)
        return 1;
    return 0;
}
MS2_REPLACE(0x1413FAF90, FUN_1413faf90, 101, 0xD33A8D88);

// @0x1413fb000
unsigned int FUN_1413fb000(egf::Entity* pEntity)
{
    efd::vector<NiMesh*> kMeshes;
    FUN_1413fb630(pEntity, &kMeshes);
    return (unsigned int)kMeshes.size();
}
MS2_REPLACE(0x1413FB000, FUN_1413fb000, 77, 0x0DBED506);

// Johab jamo tables (initial / medial / final), indexed by the 5 bit fields of a Johab character.
static const unsigned short s_johabInitial[32] = {
    0x0000, 0x0000, 0x8841, 0x8c41, 0x9041, 0x9441, 0x9841, 0x9c41, 0xa041, 0xa441, 0xa841, 0xac41, 0xb041, 0xb441, 0xb841, 0xbc41,
    0xc041, 0xc441, 0xc841, 0xcc41, 0xd041, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };
static const unsigned short s_johabMedial[32] = {
    0x0000, 0x0000, 0x0000, 0x8461, 0x8481, 0x84a1, 0x84c1, 0x84e1, 0x0000, 0x0000, 0x8541, 0x8561, 0x8581, 0x85a1, 0x85c1, 0x85e1,
    0x0000, 0x0000, 0x8641, 0x8661, 0x8681, 0x86a1, 0x86c1, 0x86e1, 0x0000, 0x0000, 0x8741, 0x8761, 0x8781, 0x87a1, 0x0000, 0x0000 };
static const unsigned short s_johabFinal[32] = {
    0x0000, 0x0000, 0x8442, 0x8443, 0x8444, 0x8445, 0x8446, 0x8447, 0x8448, 0x8449, 0x844a, 0x844b, 0x844c, 0x844d, 0x844e, 0x844f,
    0x8450, 0x8451, 0x0000, 0x8453, 0x8454, 0x8455, 0x8456, 0x8457, 0x8458, 0x8459, 0x845a, 0x845b, 0x845c, 0x845d, 0x0000, 0x0000 };

// @0x1413fb060
unsigned short FUN_1413fb060(unsigned short usIndex, int iKind)
{
    if (usIndex < 0 && usIndex > 31)
        return 0;
    switch (iKind) {
    case 1:
        return s_johabInitial[usIndex];
    case 2:
        return s_johabMedial[usIndex];
    case 3:
        return s_johabFinal[usIndex];
    }
    return 0;
}
MS2_REPLACE(0x1413FB060, FUN_1413fb060, 124, 0x9ACB187F);

// Expands every Johab (combining) double byte character of kIn into its jamo codes.
// @0x1413fb0f0
void FUN_1413fb0f0(std::string kIn, std::string* pOut)
{
    pOut->clear();
    size_t uiLength = kIn.size();
    for (size_t i = 0; i < uiLength; ++i) {
        if (IsDBCSLeadByte(kIn[i]) && i < uiLength - 1) {
            WORD usCode = MAKEWORD(kIn[i + 1], kIn[i]);
            WORD sInitial = FUN_1413fb060((usCode & 0x7c00) >> 10, 1);
            WORD sMedial = FUN_1413fb060((usCode & 0x3e0) >> 5, 2);
            WORD sFinal = FUN_1413fb060(usCode & 0x1f, 3);
            if (sInitial != 0) {
                pOut->push_back(HIBYTE(sInitial));
                pOut->push_back(LOBYTE(sInitial));
            }
            if (sMedial != 0) {
                pOut->push_back(HIBYTE(sMedial));
                pOut->push_back(LOBYTE(sMedial));
            }
            if (sFinal != 0) {
                pOut->push_back(HIBYTE(sFinal));
                pOut->push_back(LOBYTE(sFinal));
            }
            ++i;
        } else {
            pOut->push_back(kIn[i]);
        }
    }
}

// Multibyte to wide through a static buffer (valid until the next call).
#ifndef MS2_HOOK_DLL
// @0x1413fb330
const wchar_t* FUN_1413fb330(const char* pcText, unsigned int uiCodePage)
{
    static CStringW s_kBuffer;
    s_kBuffer = FUN_14016a730(pcText, uiCodePage);
    return s_kBuffer.GetBuffer(0);
}
#endif

// Wide to multibyte through a static buffer (valid until the next call).
#ifndef MS2_HOOK_DLL
// @0x1413fb400
const char* FUN_1413fb400(const wchar_t* pwText, unsigned int uiCodePage)
{
    static CStringA s_kBuffer;
    s_kBuffer = FUN_14016a600(pwText, uiCodePage);
    return s_kBuffer.GetBuffer(0);
}
#endif

// Depth first traversal; stops (returns false) as soon as the functor returns false.
// @0x1413fb4d0
template <class Functor> bool FUN_1413fb4d0(NiAVObject* pObject, Functor& kFunctor)
{
    if (pObject == 0)
        return true;
    if (!kFunctor.vfunc_0(pObject))
        return false;
    if (pObject->IsNode()) {
        NiNode* pkNode = (NiNode*)pObject;
        unsigned int uiCount = pkNode->GetArrayCount();
        for (unsigned int i = 0; i < uiCount; ++i) {
            NiAVObject* pkChild = pkNode->GetAt(i);
            if (!FUN_1413fb4d0(pkChild, kFunctor))
                return false;
        }
    }
    return true;
}

// Collects the NiMesh objects of an entity's scene graph.
// @0x1413fb630
void FUN_1413fb630(egf::Entity* pEntity, efd::vector<NiMesh*>* pMeshes)
{
    if (pEntity != 0) {
        unsigned int uiCount = FUN_1413f98b0()->GetObjectCountFromEntity(pEntity);
        for (unsigned int i = 0; i < uiCount; ++i) {
            EntityHelper::SceneGraphMeshFunctor<NiMesh> kFunctor(*pMeshes);
            NiAVObject* pkObject = static_cast<NiAVObject*>(FUN_14098d8d0(&NiAVObject::ms_RTTI, FUN_1413f98b0()->GetObjectFromEntity(pEntity, i)));
            if (pkObject != 0)
                EntityHelper::Traverse(pkObject, kFunctor);
        }
    }
}
MS2_REPLACE(0x1413FB630, FUN_1413fb630, 166, 0xC0724502);

// Plain service accessors (the manager call is another unit's COMDAT).
// @0x1413fb700
void* FUN_1413fb700() { return FUN_1411d14b0(FUN_1413f9850()); }
MS2_REPLACE(0x1413FB700, FUN_1413fb700, 22, 0x2B776A23);
// @0x1413fb720
void* FUN_1413fb720() { return FUN_1411ab8a0(FUN_1413f9850()); }
MS2_REPLACE(0x1413FB720, FUN_1413fb720, 22, 0xF6909721);
// @0x1413fb760
efd::MessageService* FUN_1413fb760() { return FUN_1411d1530(FUN_1413f9850()); }
MS2_REPLACE(0x1413FB760, FUN_1413fb760, 22, 0xBCA5E236);
// @0x1413fb780
void* FUN_1413fb780() { return FUN_140af2a30(FUN_1413f9850()); }
MS2_REPLACE(0x1413FB780, FUN_1413fb780, 22, 0x6C40E697);
// @0x1413fb7a0
ecr::RenderService* FUN_1413fb7a0() { return FUN_1411d15b0(FUN_1413f9850()); }
MS2_REPLACE(0x1413FB7A0, FUN_1413fb7a0, 22, 0x275BB836);
// @0x1413fb7c0
ecr::SceneGraphService* FUN_1413fb7c0() { return FUN_1409a5730(FUN_1413f9850()); }
MS2_REPLACE(0x1413FB7C0, FUN_1413fb7c0, 22, 0x084C1DD9);
// @0x1413fb7e0
void* FUN_1413fb7e0() { return FUN_140d86bf0(FUN_1413f9850()); }
MS2_REPLACE(0x1413FB7E0, FUN_1413fb7e0, 22, 0xF80406BF);
