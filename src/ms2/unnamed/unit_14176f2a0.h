// Timer helper that throttles a mesh update pass (owns an NiMeshUpdateProcess). The unit 0x14176f2a0-0x14176fbb0 has no
// recovered source path (the rejected name was nimeshupdateprocess.cpp); the class name is invented from its use.
#pragma once
#include "ms2/ms2layout.h"

class NiMeshUpdateProcess;
namespace egf { class Entity; }

class CMeshUpdateGate
{
public:
    CMeshUpdateGate();                                          // 0x14176f2a0
    void FUN_14176f390();                                       // release the update process
    bool FUN_14176f410(egf::Entity* pEntity, float fInterval);  // toggle the entity's scene graph on a due tick
    bool FUN_14176f500(egf::Entity* pEntity, float fInterval, float fDuration);
    void FUN_14176f680(egf::Entity* pEntity);                   // end an active pass
    void FUN_14176f710();                                       // m_fLast = now
    bool FUN_14176f740(float fInterval);                        // is the next pass due?
    float GetDuration() const;                                // m_fDuration
    bool IsActive() const;                                 // m_bActive
    void SetProcess(NiMeshUpdateProcess* pProcess);          // set the process
    // @0x14123ef30 (COMDAT in client\ms2\gameobject.cpp)
    void FUN_14123ef30(float fDuration) { m_fDuration = fDuration; }
    // @0x14108c240 (COMDAT in client\ms2\clonepc.cpp)
    void FUN_14108c240(float fInterval) { m_fInterval = fInterval; }

    float m_fLast;                                              // +0x00 time of the last pass
    float m_fInterval;                                          // +0x04
    float m_fDuration;                                          // +0x08
    bool m_bActive;                                             // +0x0c
    bool m_bPending;                                            // +0x0d
    NiMeshUpdateProcess* m_pProcess;                            // +0x10
};
MS2_CHECK_SIZE(CMeshUpdateGate, 0x18);
