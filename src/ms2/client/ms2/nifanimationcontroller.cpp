// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nifanimationcontroller.cpp
// MS2-RANGE: 0x1400fa290-0x1400fa2d0 .text$di
// MS2-RANGE: 0x141544660-0x141545470 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nifanimationcontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nifanimationcontroller.h"
#include "hook/ms2hook.h"
#include <NiAVObject.h>
#include <NiTransformController.h>
#include <NiPathInterpolator.h>
#include <NiTimeController.h>
#include <egf/EntityID.h>
#include <string.h>
#include <errno.h>
#pragma function(memset, memcpy)

// Unrecovered callees (real types unknown).
void* FUN_14098dc80(void* o);
void* FUN_14098de40(void* o);
void FUN_14098e870(void* o, int v);
bool FUN_14098df90(const void* rtti, void* o);
void* FUN_14127cc40(void* o);
void* FUN_14098ddb0(void* o);
void* FUN_14098de00(void* o, void** it);
void* FUN_140993f00(void* o);
unsigned int FUN_14098daf0(void* o);
void* FUN_14098db40(void* o, unsigned int i);
void* FUN_1413f98b0();
void* FUN_1409670f0();
void* FUN_1411cf440(void* a, void* id);
void* FUN_141fff400(void* svc, void* ent);   // ecr::SceneGraphService::GetSceneGraphFromEntity
void FUN_141d24a50(void* o);
extern char DAT_143afa458;

// @0x1400fa290
const NiRTTI CNifAnimationController::ms_RTTI("CNifAnimationController", 0);

// @0x1400fa2b0 (0x143ae1a28: a file-static invalid entity id; unreferenced in this unit)
static egf::EntityID s_kNoEntity(0ull);

// @0x141544660
CNifAnimationController::CNifAnimationController()
    : m_10(0), m_18(0), m_20(0), m_28(0), m_30(0), m_38(efd::Point3::ZERO), m_44(efd::Point3::ZERO)
{
    m_58 = 0;
}

// @0x141544750
CNifAnimationController::~CNifAnimationController()
{
    m_10 = 0;
    m_18 = 0;
    m_20 = 0;
    m_30 = 0;
    m_28 = 0;
}

// @0x141545340
const NiRTTI* CNifAnimationController::GetRTTI() const { return &ms_RTTI; }

// The .nif loading service (CNifLoadingService; nifmodel.cpp declares the same view). Only the loader this unit calls.
class Unk_NifLoader
{
public:
    NiAVObjectPtr FUN_141551ea0(CStringA strPath, bool bShared, int a, int b, int c);   // Load
};
Unk_NifLoader* FUN_140a0afd0();                           // the service singleton

// The scene-graph walk (applyeffect.cpp / kfmmodel.cpp declare the same view).
class Unk_AeSceneIter
{
public:
    Unk_AeSceneIter(NiAVObject* pRoot);                     // 0x14098cb80
    ~Unk_AeSceneIter();                                     // 0x14098cf00
    NiAVObject* FUN_14098e0d0(bool bEnterChildren);
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};

// @0x141544850
bool CNifAnimationController::FUN_141544850(int mode, CStringA name, const efd::Point3& kEuler)
{
    m_58 = mode;
    if (m_58 == 0) {
        m_10 = FUN_140a0afd0()->FUN_141551ea0(name, false, 5, 0, 0);
        if (m_10 != 0) {
            NiTransform kXf = m_10->GetLocalTransform();
            kXf.m_Rotate.FromEulerAnglesXYZ((-kEuler.x * 3.1415927f) / 180.0f, (-kEuler.y * 3.1415927f) / 180.0f,
                                            (-kEuler.z * 3.1415927f) / 180.0f);
            m_10->SetLocalTransform(kXf);
            m_18 = NiDynamicCast(NiNode, m_10->GetObjectByName("Dummy01"));
            if (m_18) {
                NiTimeController* pCtrl = m_18->GetControllers();
                while (pCtrl != 0) {
                    if (m_54 < pCtrl->GetEndKeyTime())
                        m_54 = pCtrl->GetEndKeyTime();
                    NiTransformController* pXf = NiDynamicCast(NiTransformController, pCtrl);
                    // Kept exe quirk: the search only runs while m_20 is already set; it starts null and nothing
                    // else sets it, so it never runs.
                    if (pXf != 0 && m_20 != 0) {
                        for (unsigned short i = 0; i < pXf->GetInterpolatorCount(); ++i) {
                            m_20 = (NiObjectNET*)NiDynamicCast(NiPathInterpolator, pXf->GetInterpolator(i));
                            if (m_20 != 0)
                                break;
                        }
                    }
                    pCtrl = pCtrl->GetNext();
                }
            }
        }
    } else if (m_58 == 1) {
        m_10 = FUN_140a0afd0()->FUN_141551ea0(name, false, 5, 0, 0);
        if (m_10 != 0) {
            m_28 = NiDynamicCast(NiNode, m_10->GetObjectByName("Camera01"));
            Unk_AeSceneIter walk(m_28);
            while (NiAVObject* pObject = walk.FUN_14098e0d0(true)) {
                NiTimeController* pCtrl = pObject->GetControllers();
                while (pCtrl != 0 && pCtrl->GetAnimType() == 1) {
                    pCtrl->SetAnimType((NiTimeController::AnimType)0);
                    pCtrl = pCtrl->GetNext();
                }
                m_30 = NiDynamicCast(NiCamera, pObject);
            }
        }
    }
    return true;
}

// @0x141544ec0
void CNifAnimationController::FUN_141544ec0(float time)
{
    if (m_58 == 1) {
        m_28->Update(time, true);
        m_38 = m_28->GetLocalTransform().m_Translate;
        m_30->GetWorldTransform().m_Rotate.ToEulerAnglesXYZ(m_44.x, m_44.y, m_44.z);
        m_44.x = -((m_44.x * 180.0f) / 3.1415927f);
        m_44.y = -((m_44.y * 180.0f) / 3.1415927f);
        m_44.z = -((m_44.z * 180.0f) / 3.1415927f);
    }
}

// @0x141545020
efd::Point3 CNifAnimationController::FUN_141545020() { return m_38; }

// @0x141545050
efd::Point3 CNifAnimationController::FUN_141545050() { return m_44; }

// @0x141545080
void FUN_141545080(int value, void* node)
{
    for (void* c = FUN_14098dc80(node); c != 0; c = FUN_14098de40(c))
        FUN_14098e870(c, value);
    if (FUN_14098df90(&DAT_143afa458, node)) {
        void* pSwitch = node;   // the exe's static cast to the switch-node type
        void* it = FUN_14098ddb0(FUN_14127cc40(pSwitch));
        while (it != 0) {
            void* ch = FUN_140993f00(FUN_14098de00(FUN_14127cc40(pSwitch), &it));
            if (ch != 0 && FUN_14098dc80(ch) != 0)
                FUN_141545080(value, ch);
        }
    }
    if (FUN_14098df90(&NiNode::ms_RTTI, node)) {
        void* pNode = node;     // static cast to NiNode
        for (unsigned int i = 0; i < FUN_14098daf0(pNode); ++i) {
            void* ch = FUN_14098db40(pNode, i);
            if (ch != 0)
                FUN_141545080(value, ch);
        }
    }
}

// @0x1415451d0
void FUN_1415451d0(int value, void* entityId)
{
    void* sg = FUN_1413f98b0();
    if (sg == 0)
        return;
    void* ent = FUN_1411cf440(FUN_1409670f0(), entityId);
    if (ent == 0)
        return;
    void* n = FUN_141fff400(sg, ent);
    if (n == 0)
        return;
    FUN_141545080(value, n);
}

// @0x141545250
void FUN_141545250(void* entityId, int mode)
{
    void* sg = FUN_1413f98b0();
    if (sg == 0)
        return;
    void* ent = FUN_1411cf440(FUN_1409670f0(), entityId);
    if (ent == 0)
        return;
    void* n = FUN_141fff400(sg, ent);
    if (n == 0)
        return;
    if (mode != 0)
        FUN_141d24a50(n);
    else
        NiTimeController::StopAnimations(static_cast<NiObjectNET*>(n));
}

// @0x141545350 (memmove_s)
unsigned __int64 FUN_141545350(void* dst, unsigned __int64 dstSize, void* src, unsigned __int64 n)
{
    if (n == 0)
        return 0;
    // The checks are the CRT's _CRT_MEMCPY_S_VALIDATE_RETURN_ERRCODE (memmove_s in vcruntime_string.h).
    {
        int bValid = !!(dst != 0);
        if (!bValid) { *_errno() = EINVAL; _invalid_parameter_noinfo(); return EINVAL; }
    }
    {
        int bValid = !!(src != 0);
        if (!bValid) { *_errno() = EINVAL; _invalid_parameter_noinfo(); return EINVAL; }
    }
    {
        int bValid = !!(dstSize >= n);
        if (!bValid) { *_errno() = ERANGE; _invalid_parameter_noinfo(); return ERANGE; }
    }
    memmove(dst, src, n);
    return 0;
}
