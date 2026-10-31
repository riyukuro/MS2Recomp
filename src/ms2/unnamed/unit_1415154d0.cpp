// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2VelocityMaterialSwapProcessor::PreRenderProcessList
// (applies the motion-blur velocity material to the visible objects) and the mesh-modifier completion helper it uses.
// Original source file name unknown; the class is declared in ms2/placeholder/ms2renderprocessors.h.
// MS2-UNIT: unit_1415154d0
// MS2-RANGE: 0x1415154d0-0x141515740 .text$mn
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
#include "ms2/client/ms2/material/ms2materials.h"

// ---- out-of-unit callees ----
// A material-table entry; only its state word (+0x540) is read here. Its exe accessor (0x1427542f0) lies in the
// statically linked runtime range (0x142748000-0x1427b6c90, not mapped by the hook DLL), so it is expressed inline.
struct Unk_MaterialEntry
{
    char m_pad[0x540];
    unsigned m_nState;
    bool IsActive() const { return m_nState - 1 <= 2; }
};
class Unk_PtrArray   // C3: member view for the former free stand-ins
{
public:
    void Add(void*);
};
NiRenderer* GetNiRenderer();                                // NiRenderer::GetRenderer
bool FUN_141568c90(NiRenderObject* pObject);
void* FUN_1409a8120(void* pSmartPointer);                   // the raw pointer held by a smart pointer

// @0x1415156b0
void FUN_1415156b0(MS2VelocityMaterialSwapProcessor* pProcessor, NiAVObject* pkObject)
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
MS2_REPLACE(0x1415156B0, FUN_1415156b0, 131, 0xFEE62AE4);

// @0x1415154d0
void MS2VelocityMaterialSwapProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (pkInput == 0)
        return;
    unsigned int uiCount = ((class NiVisibleArray*)(class NiVisibleArray const*)(pkInput))->GetCount();
    if (FUN_1409a8120(&m_spMaterial) == 0)
    {
        for (unsigned int ui = 0; ui < uiCount; ui++)
            ((class Unk_PtrArray*)(class NiVisibleArray*)(&kOutput))->Add((void*)(((class NiRenderObject*)&((class NiVisibleArray*)(class NiVisibleArray const*)(pkInput))->GetAt(ui))));
    }
    else
    {
        NiRenderer* pkRenderer = GetNiRenderer();
        for (unsigned int ui = 0; ui < uiCount; ui++)
        {
            NiRenderObject* pkObject = ((class NiRenderObject*)&((class NiVisibleArray*)(class NiVisibleArray const*)(pkInput))->GetAt(ui));
            if (NiDynamicCast(NiPSMeshParticleSystem, pkObject) != 0)
            {
                FUN_1415156b0(this, pkObject);
                continue;
            }
            if (FUN_141568c90(pkObject))
                continue;
            int nActive = 0;
            Unk_MaterialEntry* pkEntry = ((struct Unk_MaterialEntry*)NiMaterial::DynamicCast(&MS2StandardMaterial::ms_RTTI, ((class NiMaterial*)((class NiRenderObject*)(class NiRenderObject*)(pkObject))->GetActiveMaterial())));
            if (pkEntry != 0)
                nActive = pkEntry->IsActive();
            if (m_nMode == 1 && nActive == 0)
            {
                FUN_1415156b0(this, pkObject);
                continue;
            }
            NiMaterial* pkOriginal = ((class NiMaterial*)((class NiRenderObject*)(class NiRenderObject*)(pkObject))->GetActiveMaterial());
            pkObject->ApplyAndSetActiveMaterial(m_spMaterial, m_uiMaterialExtraData);
            pkObject->RenderImmediate(pkRenderer);
            pkObject->SetActiveMaterial(pkOriginal);
        }
    }
}
MS2_REPLACE_METHOD(0x1415154D0, MS2VelocityMaterialSwapProcessor, PreRenderProcessList, 462, 0x29241620);

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x1400f98d0-0x1400f9900 .text$di
#include <NiMaterialSwapProcessor.h>
#ifndef MS2_HOOK_DLL
const NiRTTI MS2VelocityMaterialSwapProcessor::ms_RTTI("MS2VelocityMaterialSwapProcessor", &NiMaterialSwapProcessor::ms_RTTI);   // @0x1400f98d0
#endif
