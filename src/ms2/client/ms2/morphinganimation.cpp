// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See morphinganimation.h.
// MS2-UNIT: ?\morphinganimation.cpp
// MS2-RANGE: 0x141487a20-0x141487ed0 .text$mn
// MS2-PIN: ??_GCMorphingAnimation@@UEAAPEAXI@Z 0x141487e50
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\morphinganimation.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "morphinganimation.h"

#include <NiAVObject.h>
#include <NiNode.h>
#include <NiFixedString.h>
#include <NiTimeController.h>
#include <NiInterpController.h>
#include <NiInterpolator.h>
#include <NiMorphWeightsController.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"

// ---- out-of-unit callees ----
// Key that names the owner's model in the model cache (16 bytes; plain data).
struct Unk_ModelKey
{
    void* m_pad_00;
    void* m_pad_08;
};
MS2_CHECK_SIZE(Unk_ModelKey, 0x10);

class Unk_MorphOwner
{
public:
    Unk_ModelKey& FUN_14123c460(Unk_ModelKey& kOut);    // fills kOut with the key of the owner's model, returns it
};
class Unk_ModelEntry
{
public:
    NiNode* FUN_1409f7cb0();                            // the cached model's root (smart pointer at +0x28)
};
class Unk_ModelCache
{
public:
    Unk_ModelEntry* FUN_140999440(const Unk_ModelKey& key);   // lookup, NULL when not cached
};
class CMainSystem;
template<> CMainSystem* TSingleton<CMainSystem>::GetInstance();
Unk_ModelCache* FUN_141b6f910();                        // the model cache singleton
// RTTI of the render object class (0x143afa7d0; name assumed from its uses).
extern const NiRTTI Unk_RenderObjectRTTI;

// @0x141487a20
CMorphingAnimation::CMorphingAnimation(Unk_MorphOwner* pOwner, CMorphingAnimationData* pData)
    : CTimeBasedAnimation(pOwner)
{
    m_pData = pData;
    m_nFrame = 0x7fffffff;
    m_bRunning = true;
}

// @0x141487a90
CMorphingAnimation::~CMorphingAnimation()
{
}

// @0x141487ac0
void CMorphingAnimation::vfunc_1()
{
    FUN_141487bf0(0);
}
MS2_REPLACE_METHOD(0x141487ac0, CMorphingAnimation, vfunc_1, 26, 0xF2C5C3DF);


// @0x141487ae0
void CMorphingAnimation::vfunc_2()
{
    if (!m_bRunning)
        return;
    FUN_141487c50(0.0f);
    m_bRunning = false;
}
MS2_REPLACE_METHOD(0x141487ae0, CMorphingAnimation, vfunc_2, 51, 0x438D66E1);


// @0x141487b20
bool CMorphingAnimation::vfunc_3(int nTime)
{
    int nFrame = m_pData->FUN_141851c20(nTime);
    if (nFrame != m_nFrame) {
        m_nFrame = nFrame;
        if ((unsigned int)m_nFrame >= m_pData->m_weights.GetCount())
            vfunc_2();
        else
            FUN_141487bf0((unsigned int)m_nFrame);
    }
    return m_bRunning;
}
MS2_REPLACE_METHOD(0x141487b20, CMorphingAnimation, vfunc_3, 154, 0x0806ADAF);


// @0x141487bc0
int CMorphingAnimation::vfunc_4()
{
    if (m_pData == NULL)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141487bc0, CMorphingAnimation, vfunc_4, 27, 0x1B43C364);


// @0x141487bf0
void CMorphingAnimation::FUN_141487bf0(size_t nFrame)
{
    if (m_pData->m_weights.GetCount() <= 0)
        return;
    FUN_141487c50(m_pData->m_weights[nFrame]);
}
MS2_REPLACE_METHOD(0x141487bf0, CMorphingAnimation, FUN_141487bf0, 87, 0xF591E8A1);


// @0x141487c50
void CMorphingAnimation::FUN_141487c50(float fWeight)
{
    if (m_pData->m_weights.GetCount() <= 0)
        return;
    int nCount = 0;
    NiInterpController* pCtrl = NULL;
    NiAVObject* pNode = FUN_141487d80(m_pData->m_strNodeName);
    if (pNode != NULL) {
        NiTimeController* pTimeCtrl = pNode->GetControllers();
        while (pTimeCtrl != NULL) {
            pCtrl = (NiInterpController*)NiObject::DynamicCast(&NiMorphWeightsController::ms_RTTI, (class NiObject const*)(pTimeCtrl));
            if (pCtrl != NULL) {
                nCount = pCtrl->GetInterpolatorCount();
                break;
            }
            pTimeCtrl = pTimeCtrl->GetNext();
        }
    }
    if (pCtrl != NULL) {
        for (unsigned short us = 0; us < nCount; us++)
            pCtrl->UpdateValue(TSingleton<CMainSystem>::GetInstance()->GetLastGameTimeDelta(), fWeight, us);
    }
}
MS2_REPLACE_METHOD(0x141487c50, CMorphingAnimation, FUN_141487c50, 295, 0x516868E3);


// @0x141487d80
NiAVObject* CMorphingAnimation::FUN_141487d80(const CString& strNodeName)
{
    Unk_ModelKey kKey;
    Unk_ModelEntry* pEntry = FUN_141b6f910()->FUN_140999440(m_pOwner->FUN_14123c460(kKey));
    if (pEntry != NULL) {
        NiNode* pRoot = pEntry->FUN_1409f7cb0();
        if (pRoot == NULL)
            return NULL;
        NiAVObject* pObject;
        {
            NiFixedString kName((const char*)strNodeName);
            pObject = pRoot->GetObjectByName(kName);
        }
        return (NiAVObject*)NiObject::DynamicCast(&Unk_RenderObjectRTTI, (class NiObject const*)(pObject));
    }
    return NULL;
}
