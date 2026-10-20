// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2ShimmerSortProcessor::PreRenderProcessList (swaps the
// shimmer material onto the refractive objects near the player, completes the modifiers of the rest) and its small
// helpers. Original source file name unknown; the class is declared in ms2/placeholder/ms2renderprocessors.h.
// MS2-UNIT: unit_14150c5e0
// MS2-RANGE: 0x14150c5e0-0x14150cd00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\postprocessingservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ms2renderprocessors.h"
#include "hook/ms2hook.h"
#include <NiRenderer.h>
#include <NiRenderObject.h>
#include <NiAVObject.h>
#include <NiMesh.h>
#include <NiPSMeshParticleSystem.h>
#include <NiVisibleArray.h>
#include <NiSyncArgs.h>
#include <NiTPointerMap.h>

// ---- out-of-unit callees ----
// The local player actor; only the position getter (vfunc 18) matters here.
class Unk_ShActor
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual NiPoint3* GetPosition(NiPoint3* pOut);
};
// The post-processing service (singleton FUN_1409a8b20); FUN_1416a3a90 reads one of its flags.
struct Unk_ShService;
Unk_ShService* FUN_1409a8b20();
long long FUN_1416a3a90(Unk_ShService* pService, int nFlag);
// The graphics-settings object (FUN_1401d3200) and its float option accessor.
struct Unk_ShSettings;
Unk_ShSettings* FUN_1401d3200();
float* FUN_140298f40(void* pOption);

extern const NiRTTI DAT_143afbfd0;                          // NiPSMeshParticleSystem::ms_RTTI
extern const NiRTTI DAT_143afbfb8;
extern NiPoint3 DAT_143b01a60;                              // zero position
extern int DAT_143ae0dd0;                                   // shimmer mode (0: all objects, 1: near the player)
extern float DAT_1439f8010;                                 // distance scale
extern bool DAT_143ae53c0;                                  // "any shimmer object this frame" flag

unsigned FUN_140d89680(const NiVisibleArray* pkInput);                          // NiVisibleArray count
NiRenderObject* FUN_1414d1830(const NiVisibleArray* pkInput, unsigned uiIndex); // NiVisibleArray::GetAt
void FUN_140d9d620(NiVisibleArray* pkOutput, NiRenderObject* pkObject);         // NiVisibleArray::Add
Unk_ShActor* FUN_141bd0cc0(void* pSingleton);
void* FUN_1403ed2d0();
void FUN_140194470(NiPoint3* pDst, NiPoint3* pSrc);         // NiPoint3 assignment
bool FUN_141568c20(NiRenderObject* pObject);
bool FUN_141568c90(NiRenderObject* pObject);
bool FUN_141567260(NiRenderObject* pObject);
NiPoint3* FUN_140947900(NiRenderObject* pObject);           // world position
void* FUN_140994490(NiRenderObject* pObject);
NiPoint3* FUN_140980350(void* pNode);
float FUN_14059d930(float f);                               // fabsf
NiPoint3 FUN_14027dcf0(NiPoint3 kPos);
float FUN_141403f20(NiPoint3 kA, NiPoint3 kB);
NiMaterial* FUN_140a17cd0(NiRenderObject* pObject);         // the object's active material
void* FUN_1409a8120(void* pSmartPointer);                   // the raw pointer held by a smart pointer
void* FUN_140d89420(NiRenderObject* pObject);
void FUN_141047900(void* p);
void FUN_1409a5850(void* pDst, const void* pSrc, int nSize);

void FUN_14150cc30(MS2ShimmerSortProcessor* pProcessor, NiAVObject* pkObject);
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);

typedef NiTPointerMap<NiRenderObject*, const NiMaterial*> Unk_ShSavedMap;

// @0x14150c5e0
// MS2-FUNCTIONAL: behaviour-equivalent; local layout of the exe's NiTPointerMap / NiPoint3 temporaries differs
void MS2ShimmerSortProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    int nShimmer = 0;
    if (pkInput == 0)
        return;
    Unk_ShSavedMap kSaved(37);
    NiVisibleArray kList;
    Unk_ShActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    NiPoint3 kPlayerPos = DAT_143b01a60;
    if (pActor != 0)
    {
        NiPoint3 kTemp;
        FUN_140194470(&kPlayerPos, pActor->GetPosition(&kTemp));
    }
    for (unsigned int ui = 0; ui < FUN_140d89680(pkInput); ui++)
    {
        NiRenderObject* pkObject = FUN_1414d1830(pkInput, ui);
        if (NiDynamicCast(NiPSMeshParticleSystem, pkObject) == 0 && FUN_141568c20(pkObject) && !FUN_141568c90(pkObject))
        {
            if (DAT_143ae0dd0 == 1 && pActor != 0)
            {
                bool bParticle = FUN_14098d8d0(&DAT_143afbfb8, pkObject) != 0;
                int bNear = 0;
                NiPoint3* pPos;
                if (!bParticle)
                    pPos = FUN_140947900(pkObject);
                else
                    pPos = FUN_140980350(FUN_140994490(pkObject));
                float fDz = FUN_14059d930(kPlayerPos.z - pPos->z);
                if (fDz < *FUN_140298f40((char*)FUN_1401d3200() + 0xce28) * DAT_1439f8010)
                {
                    NiPoint3 kPos = *pPos;
                    NiPoint3 kRel = FUN_14027dcf0(kPlayerPos);
                    float fDist = FUN_141403f20(kRel, kPos);
                    if (fDist < *FUN_140298f40((char*)FUN_1401d3200() + 0xcdd0) * DAT_1439f8010)
                        bNear = 1;
                }
                if (bNear == 0)
                    continue;
            }
            kSaved.SetAt(pkObject, FUN_140a17cd0(pkObject));
            pkObject->ApplyAndSetActiveMaterial((NiMaterial*)FUN_1409a8120(&m_spSkinnedMaterial), 0xffffffff);
            FUN_141047900(FUN_140d89420(pkObject));
            pkObject->SetMaterialNeedsUpdate(true);
            FUN_140d9d620(&kList, pkObject);
            nShimmer++;
        }
    }
    if (FUN_1416a3a90(FUN_1409a8b20(), 0xc) != 0)
    {
        if (nShimmer == 0)
        {
            bool bFlag = false;
            FUN_1409a5850(&DAT_143ae53c0, &bFlag, 1);
            for (unsigned int ui = 0; ui < FUN_140d89680(pkInput); ui++)
                FUN_14150cc30(this, FUN_1414d1830(pkInput, ui));
        }
        else
        {
            bool bFlag = true;
            FUN_1409a5850(&DAT_143ae53c0, &bFlag, 1);
            if (DAT_143ae0dd0 == 0)
            {
                for (unsigned int ui = 0; ui < FUN_140d89680(pkInput); ui++)
                {
                    NiRenderObject* pkObject = FUN_1414d1830(pkInput, ui);
                    if (NiDynamicCast(NiPSMeshParticleSystem, pkObject) == 0)
                    {
                        if (FUN_141567260(pkObject))
                            FUN_14150cc30(this, pkObject);
                        else if (!FUN_141568c20(pkObject) && !FUN_141568c90(pkObject) && pkObject->GetProperty(8) != 0)
                        {
                            kSaved.SetAt(pkObject, FUN_140a17cd0(pkObject));
                            pkObject->ApplyAndSetActiveMaterial((NiMaterial*)FUN_1409a8120(&m_spMaterial), 0xffffffff);
                            FUN_141047900(FUN_140d89420(pkObject));
                            pkObject->SetMaterialNeedsUpdate(true);
                            FUN_140d9d620(&kList, pkObject);
                        }
                    }
                    else
                        FUN_14150cc30(this, pkObject);
                }
            }
        }
    }
    NiShaderSortProcessor::PreRenderProcessList(&kList, kOutput, pvExtraData);
    NiTMapIterator pos = kSaved.GetFirstPos();
    while (pos != 0)
    {
        NiRenderObject* pkKey;
        const NiMaterial* pkMat;
        kSaved.GetNext(pos, pkKey, pkMat);
        pkKey->SetActiveMaterial(pkMat);
    }
    kSaved.RemoveAll();
    kList.RemoveAll();
}

// @0x14150cc30
void FUN_14150cc30(MS2ShimmerSortProcessor* pProcessor, NiAVObject* pkObject)
{
    (void)pProcessor;
    NiSyncArgs kArgs;
    kArgs.m_uiSubmitPoint = NiSyncArgs::SYNC_ANY;
    kArgs.m_uiCompletePoint = NiSyncArgs::SYNC_RENDER;
    NiMesh* pkMesh = NiDynamicCast(NiMesh, pkObject);
    if (pkMesh != 0)
    {
        pkMesh->CompleteModifiers(&kArgs);
    }
    else
    {
        NiPSMeshParticleSystem* pkSystem = NiDynamicCast(NiPSMeshParticleSystem, pkObject);
        if (pkSystem != 0)
            pkSystem->CompleteModifiers(&kArgs);
    }
}
MS2_REPLACE(0x14150CC30, FUN_14150cc30, 131, 0x92A91273);

// @0x14150ccc0
void FUN_14150ccc0(int nMode)
{
    DAT_143ae0dd0 = nMode;
}

// @0x14150cce0
void FUN_14150cce0(float fScale)
{
    DAT_1439f8010 = fScale;
}

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x1400f9700-0x1400f9730 .text$di
#include "ms2/client/ms2/ms2renderlistprocessor.h"
#ifndef MS2_HOOK_DLL
const NiRTTI MS2ShimmerSortProcessor::ms_RTTI("MS2ShimmerSortProcessor", &MS2RenderListProcessor::ms_RTTI);   // @0x1400f9700
#endif
