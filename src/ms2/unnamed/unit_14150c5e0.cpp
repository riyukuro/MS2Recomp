// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2ShimmerSortProcessor::PreRenderProcessList (swaps the
// shimmer material onto the refractive objects near the player, completes the modifiers of the rest) and its small
// helpers. Original source file name unknown; the class is declared in ms2/placeholder/ms2renderprocessors.h.
// MS2-UNIT: unit_14150c5e0
// MS2-RANGE: 0x14150c5e0-0x14150cd00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\postprocessingservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
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
    virtual NiPoint3 GetPosition();
};
// The post-processing service (singleton FUN_1409a8b20); FUN_1416a3a90 reads one of its flags.
struct Unk_ShService;
class Unk_AeFeatureMgr   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AeFeatureMgr* FUN_1409a8b20();
};
long long FUN_1416a3a90(Unk_ShService* pService, int nFlag);
// The graphics-settings object (FUN_1401d3200) and its float option accessor.
struct Unk_ShSettings;
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
class Unk_IntOptionEntry   // C3: member view for the former free stand-ins
{
public:
    int& FUN_140298f40();
};

extern const NiRTTI DAT_143afbfd0;                          // NiPSMeshParticleSystem::ms_RTTI
extern const NiRTTI DAT_143afbfb8;
#define DAT_143b01a60 (*(NiPoint3*)&efd::Point3::ZERO)          // C3: was extern NiPoint3 DAT_143b01a60
extern int DAT_143ae0dd0;                                   // shimmer mode (0: all objects, 1: near the player)
extern float DAT_1439f8010;                                 // distance scale
extern bool DAT_143ae53c0;                                  // "any shimmer object this frame" flag

unsigned FUN_140d89680(const NiVisibleArray* pkInput);                          // NiVisibleArray count
class Unk_PtrArray   // C3: member view for the former free stand-ins
{
public:
    void Add(void*);
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
void FUN_140194470(NiPoint3* pDst, NiPoint3* pSrc);         // NiPoint3 assignment
bool FUN_141568c20(NiRenderObject* pObject);
bool FUN_141568c90(NiRenderObject* pObject);
bool FUN_141567260(class NiAVObject*);   // C3: was FUN_141567260
float FUN_14059d930(float f);                               // fabsf
float FUN_141403f20(NiPoint3 kA, NiPoint3 kB);       // horizontal distance
void* FUN_1409a8120(void* pSmartPointer);                   // the raw pointer held by a smart pointer
bool FUN_1409a5850(class NiFixedString&, bool const*, unsigned int);   // C3: was FUN_1409a5850

void FUN_14150cc30(MS2ShimmerSortProcessor* pProcessor, NiAVObject* pkObject);

typedef NiTPointerMap<NiRenderObject*, const NiMaterial*> Unk_ShSavedMap;

// @0x14150c5e0
void MS2ShimmerSortProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    int nShimmer = 0;
    if (pkInput == 0)
        return;
    Unk_ShSavedMap kSaved(37);
    NiVisibleArray kList;
    Unk_ShActor* pActor = ((class Unk_ShActor*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    efd::Point3 kPlayerPos = DAT_143b01a60;
    if (pActor != 0)
        FUN_140194470(static_cast<NiPoint3*>(&kPlayerPos), const_cast<NiPoint3*>(&static_cast<const NiPoint3&>(pActor->GetPosition())));
    for (unsigned int ui = 0; ui < FUN_140d89680(pkInput); ui++)
    {
        NiRenderObject* pkObject = ((class NiRenderObject*)&((class NiVisibleArray*)(class NiVisibleArray const*)(pkInput))->GetAt(ui));
        if (NiDynamicCast(NiPSMeshParticleSystem, pkObject) != 0)
            continue;
        if (!FUN_141568c20(pkObject))
            continue;
        if (FUN_141568c90(pkObject))
            continue;
        if (DAT_143ae0dd0 == 1 && pActor != 0)
        {
            int bParticle = NiObject::DynamicCast(&DAT_143afbfb8, (class NiObject const*)(pkObject)) ? 1 : 0;
            int bNear = 0;
            const NiPoint3& kPos = bParticle ? *((class NiPoint3*)&((class NiBound*)(void*)(((void*)&((class NiAVObject*)(class NiRenderObject*)(pkObject))->GetWorldBound())))->GetCenter()) : *((class NiPoint3*)&((class NiAVObject*)(class NiRenderObject*)(pkObject))->GetWorldTranslate());
            float fDz = FUN_14059d930(kPlayerPos.z - kPos.z);
            if (fDz < *((float*)&((class Unk_IntOptionEntry*)(void*)((char*)((struct Unk_ShSettings*)FUN_1401d3200()) + 0xce28))->FUN_140298f40()) * DAT_1439f8010)
            {
                float fDist = FUN_141403f20(kPlayerPos, kPos);
                if (fDist < *((float*)&((class Unk_IntOptionEntry*)(void*)((char*)((struct Unk_ShSettings*)FUN_1401d3200()) + 0xcdd0))->FUN_140298f40()) * DAT_1439f8010)
                    bNear = 1;
            }
            if (bNear == 0)
                continue;
        }
        const NiMaterial* pkMat = ((class NiMaterial*)((class NiRenderObject*)(class NiRenderObject*)(pkObject))->GetActiveMaterial());
        kSaved.SetAt(pkObject, pkMat);
        pkObject->ApplyAndSetActiveMaterial((NiMaterial*)FUN_1409a8120(&m_spSkinnedMaterial), 0xffffffff);
        ((class NiMaterialInstance*)(void*)(((void*)((class NiRenderObject*)(class NiRenderObject*)(pkObject))->GetActiveMaterialInstance())))->ClearCachedShader();
        pkObject->SetMaterialNeedsUpdate(true);
        ((class Unk_PtrArray*)(class NiVisibleArray*)(&kList))->Add((void*)(pkObject));
        nShimmer++;
    }
    Unk_ShService* pService = ((struct Unk_ShService*)Unk_AeFeatureMgr::FUN_1409a8b20());
    long long nEnabled = FUN_1416a3a90(pService, 0xc);
    if (nEnabled != 0)
    {
        if (nShimmer == 0)
        {
            bool bFlag = false;
            FUN_1409a5850(*(class NiFixedString*)(&DAT_143ae53c0), (bool const*)(&bFlag), 1);
            for (unsigned int ui = 0; ui < FUN_140d89680(pkInput); ui++)
                FUN_14150cc30(this, ((class NiRenderObject*)&((class NiVisibleArray*)(class NiVisibleArray const*)(pkInput))->GetAt(ui)));
        }
        else
        {
            bool bFlag = true;
            FUN_1409a5850(*(class NiFixedString*)(&DAT_143ae53c0), (bool const*)(&bFlag), 1);
            if (DAT_143ae0dd0 == 0)
            {
                for (unsigned int ui = 0; ui < FUN_140d89680(pkInput); ui++)
                {
                    NiRenderObject* pkObject = ((class NiRenderObject*)&((class NiVisibleArray*)(class NiVisibleArray const*)(pkInput))->GetAt(ui));
                    if (NiDynamicCast(NiPSMeshParticleSystem, pkObject) != 0)
                    {
                        FUN_14150cc30(this, pkObject);
                        continue;
                    }
                    if (FUN_141567260((class NiAVObject*)(pkObject)))
                    {
                        FUN_14150cc30(this, pkObject);
                        continue;
                    }
                    if (FUN_141568c20(pkObject))
                        continue;
                    if (FUN_141568c90(pkObject))
                        continue;
                    if (pkObject->GetProperty(8) != 0)
                    {
                        const NiMaterial* pkMat = ((class NiMaterial*)((class NiRenderObject*)(class NiRenderObject*)(pkObject))->GetActiveMaterial());
                        kSaved.SetAt(pkObject, pkMat);
                        pkObject->ApplyAndSetActiveMaterial((NiMaterial*)FUN_1409a8120(&m_spMaterial), 0xffffffff);
                        ((class NiMaterialInstance*)(void*)(((void*)((class NiRenderObject*)(class NiRenderObject*)(pkObject))->GetActiveMaterialInstance())))->ClearCachedShader();
                        pkObject->SetMaterialNeedsUpdate(true);
                        ((class Unk_PtrArray*)(class NiVisibleArray*)(&kList))->Add((void*)(pkObject));
                    }
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
