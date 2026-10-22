// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCubeMotionManager: per-entity timed cube-object motions
// (scale, rotation, bounce, fade) kept in ATL red-black maps keyed by entity id, plus the motion value classes' inline
// COMDATs and the ATL map/list/vector glue first used here.
// MS2-UNIT: ?\cubemotionmanager.cpp
// MS2-RANGE: 0x14115b040-0x141165f00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0Unk_CmFade@@QEAA@AEBV0@@Z 0x14115dce0 ; unique
// MS2-PIN: ??4Unk_CmFade@@QEAAAEAV0@AEBV0@@Z 0x14115e9c0 ; unique
// MS2-PIN: ?Lookup@?$CRBMap@VEntityID@egf@@VUnk_CmBounce@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@VUnk_CmBounce@@@5@@ATL@@QEAAPEAVCPair@?$CRBTree@VEntityID@egf@@VUnk_CmBounce@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@VUnk_CmBounce@@@5@@2@AEBVEntityID@egf@@@Z 0x141160690 ; prop
// MS2-PIN: ?RBDelete@?$CRBTree@VEntityID@egf@@VUnk_CmBounce@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@VUnk_CmBounce@@@5@@ATL@@AEAA_NPEAVCNode@12@@Z 0x141161d30 ; unique
// MS2-PIN: ?RBDeleteFixup@?$CRBTree@VEntityID@egf@@VUnk_CmBounce@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@VUnk_CmBounce@@@5@@ATL@@AEAAXPEAVCNode@12@@Z 0x1411625f0 ; unique
// MS2-PIN: ?RemoveAt@?$CRBTree@VEntityID@egf@@VUnk_CmBounce@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@VUnk_CmBounce@@@5@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141163e70 ; prop
// MS2-PIN: ?RemoveKey@?$CRBMap@VEntityID@egf@@VUnk_CmBounce@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@VUnk_CmBounce@@@5@@ATL@@QEAA_NAEBVEntityID@egf@@@Z 0x141163f50 ; unique
// MS2-PIN: ?SwapNode@?$CRBTree@VEntityID@egf@@VUnk_CmBounce@@V?$CElementTraits@VEntityID@egf@@@ATL@@V?$CElementTraits@VUnk_CmBounce@@@5@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141164ed0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@V?$_Vector_val@U?$_Simple_types@PEAVTransparencyStandardMaterial@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@XZ 0x141165670 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@V?$_Vector_val@U?$_Simple_types@PEAVTransparencyStandardMaterial@@@std@@@std@@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVTransparencyStandardMaterial@@@std@@@2@XZ 0x141165690 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?__empty_global_delete@@YAXPEAX@Z 0x141165da0
// MS2-PIN: ??$_Construct1@PEAVTransparencyStandardMaterial@@AEBQEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@@std@@SAXU?$integral_constant@_N$0A@@1@AEAV?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@PEAPEAVTransparencyStandardMaterial@@AEBQEAV5@@Z 0x14115c770
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBQEAVTransparencyStandardMaterial@@@?$vector@PEAVTransparencyStandardMaterial@@V?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@@std@@AEAAXAEBQEAVTransparencyStandardMaterial@@@Z 0x14115cac0
// MS2-PIN: ??$_Emplace_reallocate@AEBQEAVTransparencyStandardMaterial@@@?$vector@PEAVTransparencyStandardMaterial@@V?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@@std@@QEAAPEAPEAVTransparencyStandardMaterial@@QEAPEAV2@AEBQEAV2@@Z 0x14115cb80
// MS2-PIN: ??$construct@PEAVTransparencyStandardMaterial@@AEBQEAV1@@?$_Normal_allocator_traits@V?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@@std@@SAXAEAV?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@PEAPEAVTransparencyStandardMaterial@@AEBQEAV4@@Z 0x14115d2e0
// MS2-PIN: ??$emplace_back@AEBQEAVTransparencyStandardMaterial@@@?$vector@PEAVTransparencyStandardMaterial@@V?$CustomAllocator@PEAVTransparencyStandardMaterial@@@efd@@@std@@QEAAXAEBQEAVTransparencyStandardMaterial@@@Z 0x14115d3c0
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemotionmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cubemotionmanager.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/placeholder/hardwareinstancingservice.h"
#include "ms2/placeholder/nipoint3.h"
#include <egf/Entity.h>
#include <NiAVObject.h>
#include <NiNode.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names are exe addresses) ----------------------------------------------------------------
extern char DAT_143b059e8;                                      // service lookup cell
EntityWorldManager* FUN_1409670f0();
HardwareInstancingService* FUN_14098c5b0(char* pCell);
void FUN_1413d78e0(HardwareInstancingService* pSvc, egf::Entity* pEntity);   // refresh the entity's instancing
bool FUN_14028d470(float a, float b);                           // nearly equal
NiNode* FUN_1413fa070(egf::EntityID id);                     // entity id -> scene root
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                // entity -> scene node
void FUN_141567330(NiAVObject* pNode, bool b);                  // set the node's visibility flag

// Ease curves (empty functors called on temporaries).
struct Unk_CmEaseOut { float FUN_140cd8c20(float t); };
struct Unk_CmEaseIn { float FUN_1410af700(float t); };

// Property access on the entity (hash id, value).
class Unk_CmEntity
{
public:
    void FUN_1409618c0(unsigned nProp, Vector3* pOut);          // get a point property
    void FUN_140a38a50(unsigned nProp, const Vector3* pValue);  // set a point property
    void FUN_1409457c0(unsigned nProp, const float* pValue);            // set a float property
    void FUN_14098c6e0(unsigned nProp, const bool* pValue);             // set a bool property
};

// Transparency material attached to a mesh (0x38 bytes); slots 2 and 4 are used here.
class TransparencyStandardMaterial
{
public:
    static void* operator new(size_t nSize, unsigned nCat);     // 0x14208a860
    static void operator delete(void* p, unsigned nCat);        // 0x14097f700
    static void operator delete(void* p);                       // the deleting dtor frees through the heap
    TransparencyStandardMaterial(void* pGeometry);              // 0x140a16050
    virtual ~TransparencyStandardMaterial();
    virtual void vfunc_1();
    virtual void vfunc_2(int n);                                // MS2: slot 2 (0x10)
    virtual void vfunc_3();
    virtual void vfunc_4(float fAlpha);                         // MS2: slot 4 (0x20) set alpha
    char m_pad_08[0x38 - 8];
};

// A scene-graph walk over a model: the exe's iterator helpers (construct 0x14098cb80, next 0x14098e0d0, destroy 0x14098cf00).
struct Unk_CmWalker
{
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5; void* m_p6; void* m_p7;
    Unk_CmWalker(NiObject* pRoot);                    // 0x14098cb80
    ~Unk_CmWalker();                                  // 0x14098cf00
    NiAVObject* FUN_14098e0d0(int bDescend);
};
NiObject* FUN_14098d8d0(const void* pRTTI, NiObject* pObject);    // dynamic cast through an NiRTTI
extern char DAT_143afa7d0;                                         // NiRTTI of the mesh type
extern char DAT_143d69198;                                         // material table
void* FUN_140a17cd0(void* pMesh);                                  // the mesh's active material
void* FUN_140a17af0(void* pTable, void* pMaterial);                // table lookup
int* FUN_140876480(int* pOut, int nCat);                          // memory category helper

// ---- motion value classes (header-inline in the exe, COMDATs of this obj) ----------------------------------------------

// @0x14115e3e0
Unk_CmScale::Unk_CmScale(float fFrom, float fTo, unsigned nMs)
{
    m_fFrom = fFrom;
    m_fTo = fTo;
    m_timer.FUN_140868750(nMs);
}

// @0x14115e2c0
Unk_CmRotate::Unk_CmRotate(float fFrom, float fTo, unsigned nMs)
{
    m_fFrom = fFrom;
    m_fTo = fTo;
    m_timer.FUN_140868750(nMs);
    if (FUN_14028d470(m_fFrom, 0.0f) && 180.0f < m_fTo - m_fFrom)
        m_fFrom = 360.0f;
}

// @0x14115e1c0
Unk_CmBounce::Unk_CmBounce(float fFrom, float fTo, unsigned nUnused, unsigned nMs)
{
    m_fFrom = fFrom;
    m_fTo = fTo;
    m_timer.FUN_1408687f0();
    m_timerDown.FUN_140868750(nMs);
}

// @0x14115e8b0
Unk_CmFade::~Unk_CmFade()
{
}

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy).
// @0x141165db0
// MS2-FUNCTIONAL: unreferenced CRT memcpy_s copy: frame saves rsi/rdi, source spelling differs
static __inline errno_t ms2_cm_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnCmMemcpyS)(void*, size_t, const void*, size_t) = &ms2_cm_memcpy_s;

// @0x14115e0e0
Unk_CmFade::Unk_CmFade()
{
}

// @0x14115dd90
// MS2-FUNCTIONAL: stack-slot assignment of the category/EntityID temporaries differs (frame 0xe8 vs 0xd8)
Unk_CmFade::Unk_CmFade(egf::EntityID id, float fFrom, float fTo, unsigned nMs, bool bHide)
{
    m_fFrom = fFrom;
    m_fTo = fTo;
    m_timer.FUN_140868750(nMs);
    m_bHide = bHide;
    m_id = id;
    egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(id));
    if (spEntity != 0)
    {
        ((Unk_CmEntity*)spEntity.operator->())->FUN_14098c6e0(0xd89e9b12, &bHide);
        NiAVObject* pNode = FUN_141b6efc0(spEntity);
        if (pNode != 0)
        {
            FUN_141567330(pNode, bHide);
            pNode->UpdateEffects();
            pNode->UpdateProperties();
            pNode->Update(0.0, true);
        }
        efd::SmartPointer<NiNode> spRoot(FUN_1413fa070(m_id));
        if (spRoot != 0)
        {
            Unk_CmWalker walker(spRoot);
            while (NiAVObject* pObject = walker.FUN_14098e0d0(1))
            {
                NiObject* pMesh = FUN_14098d8d0(&DAT_143afa7d0, pObject);
                void* pMat;
                if (pMesh != 0 && (pMat = FUN_140a17cd0(pMesh)) != 0 && FUN_140a17af0(&DAT_143d69198, pMat) != 0)
                {
                    int nCat[2];
                    int* pCat = FUN_140876480(nCat, 0);
                    TransparencyStandardMaterial* pMaterial = new (*pCat) TransparencyStandardMaterial(pMesh);
                    pMaterial->vfunc_2(0);
                    pMaterial->vfunc_4(m_fFrom);
                    m_materials.push_back(pMaterial);
                }
            }
        }
    }
}

// @0x141161600
void Unk_CmFade::FUN_141161600()
{
    egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(m_id));
    if (spEntity != 0)
    {
        bool bVisible = true;
        ((Unk_CmEntity*)spEntity.operator->())->FUN_14098c6e0(0xd89e9b12, &bVisible);
        MS2_FOR_EACH(TransparencyStandardMaterial* pMaterial, m_materials)
        {
            pMaterial->vfunc_3();
            delete pMaterial;
        }
        efd::SmartPointer<NiNode> spRoot(FUN_1413fa070(m_id));
        if (spRoot != 0)
        {
            spRoot->UpdateProperties();
            spRoot->UpdateEffects();
            spRoot->Update(0.0, true);
        }
    }
}

// ---- CCubeMotionManager -----------------------------------------------------------------------------------------

// @0x14115b040
CCubeMotionManager::CCubeMotionManager()
    : m_scale(10), m_rotate(10), m_bounce(10), m_fade(10)
{
    m_scale.RemoveAll();
    m_rotate.RemoveAll();
    m_bounce.RemoveAll();
    m_fade.RemoveAll();
}

// @0x14115b120
CCubeMotionManager::~CCubeMotionManager()
{
    m_scale.RemoveAll();
    m_rotate.RemoveAll();
    m_bounce.RemoveAll();
    m_fade.RemoveAll();
}

// @0x14115b1e0
void CCubeMotionManager::AddScale(const egf::EntityID& id, float fFrom, float fTo, unsigned nMs)
{
    Unk_CmScale scale(fFrom, fTo, nMs);
    m_scale.SetAt(id, scale);
}
MS2_REPLACE_METHOD(0x14115B1E0, CCubeMotionManager, AddScale, 121, 0x9CC36F9E);

// @0x14115b260
void CCubeMotionManager::AddRotate(const egf::EntityID& id, float fFrom, float fTo, unsigned nMs)
{
    Unk_CmRotate rotate(fFrom, fTo, nMs);
    m_rotate.SetAt(id, rotate);
}
MS2_REPLACE_METHOD(0x14115B260, CCubeMotionManager, AddRotate, 121, 0x55BB4FD1);

// @0x14115b2e0
void CCubeMotionManager::AddBounce(const egf::EntityID& id, float fFrom, float fTo, unsigned nUnused, unsigned nMs)
{
    Unk_CmBounce bounce(fFrom, fTo, nUnused, nMs);
    m_bounce.SetAt(id, bounce);
}
MS2_REPLACE_METHOD(0x14115B2E0, CCubeMotionManager, AddBounce, 138, 0x90835330);

// @0x14115b370
void CCubeMotionManager::AddFade(const egf::EntityID& id, float fFrom, float fTo, unsigned nMs, bool bHide)
{
    Unk_CmFade fade(id, fFrom, fTo, nMs, bHide);
    m_fade.SetAt(id, fade);
}
MS2_REPLACE_METHOD(0x14115B370, CCubeMotionManager, AddFade, 175, 0x2DBF5238);

// @0x14115b430
void CCubeMotionManager::RemoveFade(const egf::EntityID& id)
{
    Unk_CmFade fade;
    if (m_fade.Lookup(id, fade))
    {
        fade.FUN_141161600();
        m_fade.RemoveKey(id);
    }
}
MS2_REPLACE_METHOD(0x14115B430, CCubeMotionManager, RemoveFade, 138, 0x245A0FA6);

// @0x14115b4c0
bool CCubeMotionManager::FUN_14115b4c0(const egf::EntityID& id, Unk_CmScale& out)
{
    return m_scale.Lookup(id, out);
}
MS2_REPLACE_METHOD(0x14115B4C0, CCubeMotionManager, FUN_14115b4c0, 51, 0xC14F5254);

// @0x14115b500
bool CCubeMotionManager::FUN_14115b500(const egf::EntityID& id, Unk_CmRotate& out)
{
    return m_rotate.Lookup(id, out);
}
MS2_REPLACE_METHOD(0x14115B500, CCubeMotionManager, FUN_14115b500, 51, 0x29320C83);

// @0x14115b540
// MS2-FUNCTIONAL: 3.5 KB with four near-identical loops; stack-slot assignment (frame 0x1e8 vs 0x218) and temporaries differ
void CCubeMotionManager::Update()
{
    ATL::CAtlList<egf::EntityID> finished(10);
    efd::SmartPointer<HardwareInstancingService> spInstancing(FUN_14098c5b0(&DAT_143b059e8));

    // rotations
    for (POSITION pos1 = m_rotate.GetHeadPosition(); pos1 != 0; m_rotate.GetNext(pos1))
    {
        egf::EntityID id = m_rotate.GetKeyAt(pos1);
        egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(id));
        if (spEntity == 0)
        {
            finished.AddTail(id);
            continue;
        }
        Unk_CmRotate& rotate = m_rotate.GetValueAt(pos1);
        if (rotate.m_timer.FUN_140868ba0() != 0 || rotate.m_timer.FUN_140868c00() != 0)
        {
            float fRatio = Unk_CmEaseOut().FUN_140cd8c20(rotate.m_timer.FUN_140868940());
            float fValue = rotate.m_fFrom + (rotate.m_fTo - rotate.m_fFrom) * fRatio;
            Vector3 pt;
            ((Unk_CmEntity*)spEntity.operator->())->FUN_1409618c0(0x68c7c29d, &pt);
            pt.z = fValue;
            ((Unk_CmEntity*)spEntity.operator->())->FUN_140a38a50(0x68c7c29d, &pt);
            if (rotate.m_timer.FUN_140868c00() != 0)
            {
                rotate.m_timer.FUN_1408687f0();
                finished.AddTail(id);
            }
            if (spInstancing)
                FUN_1413d78e0(spInstancing.operator->(), spEntity);
        }
    }
    for (POSITION pos2 = finished.GetHeadPosition(); pos2 != 0; finished.GetNext(pos2))
    {
        egf::EntityID id = finished.GetAt(pos2);
        m_rotate.RemoveKey(id);
    }
    finished.RemoveAll();

    // bounces
    for (POSITION pos3 = m_bounce.GetHeadPosition(); pos3 != 0; m_bounce.GetNext(pos3))
    {
        egf::EntityID id = m_bounce.GetKeyAt(pos3);
        egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(id));
        if (spEntity == 0)
        {
            finished.AddTail(id);
            continue;
        }
        Unk_CmBounce& bounce = m_bounce.GetValueAt(pos3);
        if (bounce.m_timerDown.FUN_140868c00() != 0)
        {
            bounce.m_timer.FUN_140868750(200);
            bounce.m_timerDown.FUN_1408687f0();
        }
        if (bounce.m_timer.FUN_140868ba0() != 0 || bounce.m_timer.FUN_140868c00() != 0)
        {
            float fT = bounce.m_timer.FUN_140868940();
            if (0.5f < fT)
            {
                fT = bounce.m_timer.FUN_140868940();
                float fRatio = Unk_CmEaseIn().FUN_1410af700((fT - 0.5f) * 2.0f);
                float fValue = bounce.m_fTo + (bounce.m_fFrom - bounce.m_fTo) * fRatio;
                Vector3 pt;
                ((Unk_CmEntity*)spEntity.operator->())->FUN_1409618c0(0xfd95ca52, &pt);
                pt.z = fValue;
                ((Unk_CmEntity*)spEntity.operator->())->FUN_140a38a50(0xfd95ca52, &pt);
                if (bounce.m_timer.FUN_140868c00() != 0)
                {
                    bounce.m_timer.FUN_1408687f0();
                    finished.AddTail(id);
                }
            }
            else
            {
                fT = bounce.m_timer.FUN_140868940();
                float fRatio = Unk_CmEaseOut().FUN_140cd8c20(fT * 2.0f);
                float fValue = bounce.m_fFrom + (bounce.m_fTo - bounce.m_fFrom) * fRatio;
                Vector3 pt;
                ((Unk_CmEntity*)spEntity.operator->())->FUN_1409618c0(0xfd95ca52, &pt);
                pt.z = fValue;
                ((Unk_CmEntity*)spEntity.operator->())->FUN_140a38a50(0xfd95ca52, &pt);
            }
            if (spInstancing)
                FUN_1413d78e0(spInstancing.operator->(), spEntity);
        }
    }
    for (POSITION pos4 = finished.GetHeadPosition(); pos4 != 0; finished.GetNext(pos4))
    {
        egf::EntityID id = finished.GetAt(pos4);
        m_bounce.RemoveKey(id);
    }
    finished.RemoveAll();

    // scales
    for (POSITION pos5 = m_scale.GetHeadPosition(); pos5 != 0; m_scale.GetNext(pos5))
    {
        egf::EntityID id = m_scale.GetKeyAt(pos5);
        egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(id));
        if (spEntity == 0)
        {
            finished.AddTail(id);
            continue;
        }
        Unk_CmScale& scale = m_scale.GetValueAt(pos5);
        if (scale.m_timer.FUN_140868ba0() != 0 || scale.m_timer.FUN_140868c00() != 0)
        {
            float fRatio = Unk_CmEaseOut().FUN_140cd8c20(scale.m_timer.FUN_140868940());
            float fValue = scale.m_fFrom + (scale.m_fTo - scale.m_fFrom) * fRatio;
            ((Unk_CmEntity*)spEntity.operator->())->FUN_1409457c0(0x2d7cad2d, &fValue);
            if (scale.m_timer.FUN_140868c00() != 0)
            {
                scale.m_timer.FUN_1408687f0();
                finished.AddTail(id);
            }
            if (spInstancing)
                FUN_1413d78e0(spInstancing.operator->(), spEntity);
        }
    }
    for (POSITION pos6 = finished.GetHeadPosition(); pos6 != 0; finished.GetNext(pos6))
    {
        egf::EntityID id = finished.GetAt(pos6);
        m_scale.RemoveKey(id);
    }
    finished.RemoveAll();

    // fades
    for (POSITION pos7 = m_fade.GetHeadPosition(); pos7 != 0; m_fade.GetNext(pos7))
    {
        egf::EntityID id = m_fade.GetKeyAt(pos7);
        egf::EntityPtr spEntity(FUN_1409670f0()->FUN_1411cf440(id));
        if (spEntity == 0)
        {
            finished.AddTail(id);
            continue;
        }
        Unk_CmFade& fade = m_fade.GetValueAt(pos7);
        if (fade.m_timer.FUN_140868ba0() != 0 || fade.m_timer.FUN_140868c00() != 0)
        {
            float fRatio = Unk_CmEaseOut().FUN_140cd8c20(fade.m_timer.FUN_140868940());
            float fAlpha = fade.m_fFrom + (fade.m_fTo - fade.m_fFrom) * fRatio;
            Unk_CmMaterialList::iterator itEnd = fade.m_materials.end();
            Unk_CmMaterialList::iterator it = fade.m_materials.begin();
            while (it != itEnd)
            {
                (*it)->vfunc_4(fAlpha);
                ++it;
            }
        }
        if (fade.m_timer.FUN_140868c00() != 0)
        {
            Unk_CmMaterialList::iterator itEnd = fade.m_materials.end();
            Unk_CmMaterialList::iterator it = fade.m_materials.begin();
            while (it != itEnd)
            {
                (*it)->vfunc_4(fade.m_fTo);
                ++it;
            }
            fade.m_timer.FUN_1408687f0();
            ((Unk_CmEntity*)spEntity.operator->())->FUN_14098c6e0(0xa0b6b179, (const bool*)&fade.m_bHide);
            fade.FUN_141161600();
            finished.AddTail(id);
        }
    }
    for (POSITION pos8 = finished.GetHeadPosition(); pos8 != 0; finished.GetNext(pos8))
    {
        egf::EntityID id = finished.GetAt(pos8);
        m_fade.RemoveKey(id);
    }
    finished.RemoveAll();
}
MS2_REPLACE_METHOD(0x14115B540, CCubeMotionManager, Update, 3574, 0xF161404A);
