// MS2MeshCullingProcess: NiCullingProcess that culls a flat list of scene roots (skipping flagged objects). 0xc8 bytes.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/niculling.h"

class MS2MeshCullingProcess : public NiCullingProcess {
public:
    MS2MeshCullingProcess(NiVisibleArray* pkVisibleSet, NiSPWorkflowManager* pkWorkflowManager);                         // 0x140d96010
    MS2MeshCullingProcess(NiVisibleArray* pkVisibleSet, NiSPWorkflowManager* pkWorkflowManager, bool bUseVirtualAppend); // 0x140d962e0
    virtual ~MS2MeshCullingProcess();                                                  // 0x140d96100
    virtual const NiRTTI* GetRTTI() const;                                             // 0x140d966a0
    virtual void Process(const NiCamera* pkCamera, NiAVObject* pkScene, NiVisibleArray* pkVisibleSet);                  // 0x140d963d0
    virtual void Process(const NiCamera* pkCamera, NiTPointerList<NiAVObject*>* pkSceneList, NiVisibleArray* pkVisibleSet); // 0x140d96410
    virtual void PreProcess();                                                         // 0x140d96540
    virtual void PostProcess();                                                        // 0x140d96550

    static const NiRTTI ms_RTTI;                                                       // 0x143ac3cd8

    friend NiSPWorkflowManager* GetWorkflowManager(MS2MeshCullingProcess* p);     // reads the protected m_pkWorkflowManager
    bool m_ownsWorkflow;                                                               // +0xc0
};
MS2_CHECK_SIZE(MS2MeshCullingProcess, 0xc8);
