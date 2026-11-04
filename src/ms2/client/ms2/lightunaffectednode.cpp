// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\lightunaffectednode.cpp
// MS2-RANGE: 0x1400f73f0-0x1400f7440 .text$di
// MS2-RANGE: 0x14144df10-0x14144e400 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\lightunaffectednode.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <NiShadowGenerator.h>
#include <NiShadowManager.h>
#include "lightunaffectednode.h"
#include "hook/ms2hook.h"

// @0x1400f73f0
const NiRTTI LightUnaffectedNode::ms_RTTI("LightUnaffectedNode", &NiNode::ms_RTTI);

// @0x1400f7420
class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };   // ctor 0x1401cd100 (C3: in place of the header's Unk_LUNHolder)
static Unk_BuddyHandle s_holder(0);

// @0x14144df10
NiObject* LightUnaffectedNode::CreateClone(NiCloningProcess& kCloning)
{
    LightUnaffectedNode* pkClone = new (efd::MemHint(efd::MemHint::NONE)) LightUnaffectedNode(m_bUpdateEffects, m_bTemplate);
    CopyMembers(pkClone, kCloning);
    return pkClone;
}

// @0x14144dfd0
void LightUnaffectedNode::CopyMembers(LightUnaffectedNode* pkDest, NiCloningProcess& kCloning)
{
    if (pkDest != 0) {
        NiNode::CopyMembers(pkDest, kCloning);
        pkDest->m_bUpdateEffects = m_bUpdateEffects;
    }
}

MS2_REPLACE_METHOD(0x14144DFD0, LightUnaffectedNode, CopyMembers, 75, 0xBA0EE6B4);

// @0x14144e030
LightUnaffectedNode::LightUnaffectedNode(bool affectsLights, bool isTemplate) : NiNode(0)
{
    m_bUpdateEffects = affectsLights;
    m_bTemplate = isTemplate;
    if (m_bTemplate == false) {
        const NiTPointerList<NiShadowGeneratorPtr>& list = NiShadowManager::GetShadowGenerators();
        NiTListIterator pos = list.GetHeadPos();
        while (pos != 0) {
            NiShadowGenerator* light = list.GetNext(pos);
            light->AttachUnaffectedCasterNode(this);
            light->AttachUnaffectedReceiverNode(this);
        }
    }
}

// @0x14144e110
LightUnaffectedNode::~LightUnaffectedNode()
{
    const NiTPointerList<NiShadowGeneratorPtr>& list1 = NiShadowManager::GetShadowGenerators();
    NiTListIterator pos1 = list1.GetHeadPos();
    while (pos1 != 0) {
        NiShadowGenerator* light1 = list1.GetNext(pos1);
        light1->SetRenderViewsDirty(true);
    }
    if (m_bTemplate == false) {
        const NiTPointerList<NiShadowGeneratorPtr>& list2 = NiShadowManager::GetShadowGenerators();
        NiTListIterator pos2 = list2.GetHeadPos();
        while (pos2 != 0) {
            NiShadowGenerator* light2 = list2.GetNext(pos2);
            light2->DetachUnaffectedCasterNode(this);
            light2->DetachUnaffectedReceiverNode(this);
        }
    }
}

// @0x14144e210
void LightUnaffectedNode::UpdateEffectsDownward(NiDynamicEffectState* pkParentState)
{
    if (m_bUpdateEffects == false)
        return;
    NiNode::UpdateEffectsDownward(pkParentState);
}

MS2_REPLACE_METHOD(0x14144E210, LightUnaffectedNode, UpdateEffectsDownward, 52, 0xDFEF2499);

// @0x14144e250
bool LightUnaffectedNode::IsTemplate() { return m_bTemplate; }

MS2_REPLACE_METHOD(0x14144E250, LightUnaffectedNode, IsTemplate, 18, 0xABE20AAB);

// @0x14144e2d0
const NiRTTI* LightUnaffectedNode::GetRTTI() const { return &ms_RTTI; }

#pragma function(memset, memcpy)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
// @0x14144e2e0 (the UCRT header-inline memmove_s from corecrt_memcpy_s.h, emitted here as an ordinary function)
errno_t FUN_14144e2e0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x14144e2d0, LightUnaffectedNode, GetRTTI, 13, 0x978D2C99);

