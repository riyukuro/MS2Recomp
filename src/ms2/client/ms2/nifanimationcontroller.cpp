// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nifanimationcontroller.cpp
// MS2-RANGE: 0x1400fa290-0x1400fa2d0 .text$di
// MS2-RANGE: 0x141544660-0x141545470 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nifanimationcontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nifanimationcontroller.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/client/ms2/nifeffectparam.h"
#include <NiAVObject.h>
#include <NiTransformController.h>
#include <NiPathInterpolator.h>
#include <NiTimeController.h>
#include <egf/EntityID.h>
#include <string.h>
#include <errno.h>
#pragma function(memset, memcpy)

// Unrecovered callees (real types unknown).


#include <ecr/SceneGraphService.h>
ecr::SceneGraphService* FUN_1413f98b0();


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
class Unk_ResourceMgr* FUN_140a0afd0();   // C3: was FUN_140a0afd0

// The scene-graph walk (applyeffect.cpp / kfmmodel.cpp declare the same view).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pRoot);                     // 0x14098cb80
    ~Unk_NodeQueue();                                     // 0x14098cf00
    NiAVObject* Next(bool bEnterChildren);
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};
typedef Unk_NodeQueue Unk_AeSceneIter;   // C3: was a local stand-in for Unk_NodeQueue

// @0x141544850
bool CNifAnimationController::FUN_141544850(int mode, CStringA name, const efd::Point3& kEuler)
{
    m_58 = mode;
    if (m_58 == 0) {
        m_10 = ((class CNifLoadingService*)FUN_140a0afd0())->Load(name, false, 5, 0, 0);
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
        m_10 = ((class CNifLoadingService*)FUN_140a0afd0())->Load(name, false, 5, 0, 0);
        if (m_10 != 0) {
            m_28 = NiDynamicCast(NiNode, m_10->GetObjectByName("Camera01"));
            Unk_AeSceneIter walk((NiAVObject*)(m_28));
            while (NiAVObject* pObject = walk.Next(true)) {
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
void CNifAnimationController::Update(float time)
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
    for (void* c = ((void*)((class NiObjectNET*)(void*)(node))->GetControllers()); c != 0; c = ((void*)((class NiTimeController*)(void*)(c))->GetNext()))
        ((NiTimeController*)c)->SetAnimType((NiTimeController::AnimType)value);
    if (NiObject::IsKindOf(&NiAVObject::ms_RTTI, (class NiObject const*)(node))) {
        void* pSwitch = node;   // the exe's static cast to the switch-node type
        void* it = ((NiTListBase<NiTPointerAllocator<unsigned __int64>, efd::SmartPointer<NiProperty>>*)(void*)(((void*)&((class NiAVObject*)(void*)(pSwitch))->GetPropertyList())))->GetHeadPos();
        while (it != 0) {
            void* ch = (NiProperty*)((class NiAVObject*)(void*)(pSwitch))->GetPropertyList().GetNext(it);
            if (ch != 0 && ((void*)((class NiObjectNET*)(void*)(ch))->GetControllers()) != 0)
                FUN_141545080(value, ch);
        }
    }
    if (NiObject::IsKindOf((class NiRTTI const*)(&NiNode::ms_RTTI), (class NiObject const*)(node))) {
        void* pNode = node;     // static cast to NiNode
        for (unsigned int i = 0; i < ((NiNode*)pNode)->GetArrayCount(); ++i) {
            void* ch = ((void*)((class NiNode*)(void*)(pNode))->GetAt(i));
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
    void* ent = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(*static_cast<const egf::EntityID*>(entityId));
    if (ent == 0)
        return;
    void* n = ((ecr::SceneGraphService*)sg)->GetSceneGraphFromEntity((egf::Entity const*)ent);
    if (n == 0)
        return;
    FUN_141545080(value, n);
}

// @0x141545250
void FUN_141545250(egf::EntityID kId, int mode)
{
    void* sg = FUN_1413f98b0();
    if (sg == 0)
        return;
    void* ent = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(kId);
    if (ent == 0)
        return;
    void* n = ((ecr::SceneGraphService*)sg)->GetSceneGraphFromEntity((egf::Entity const*)ent);
    if (n == 0)
        return;
    if (mode != 0)
        NiTimeController::StartAnimations((NiObjectNET*)n);
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
