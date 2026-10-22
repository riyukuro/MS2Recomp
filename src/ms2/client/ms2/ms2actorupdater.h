// MS2ActorUpdater: per-actor throttle for scene-graph updates. Owns a CMeshUpdateGate and remembers the actor's
// distances to the camera focus; the per-frame update picks an interval by the world's update mode.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/unnamed/unit_14176f2a0.h"
#include <egf/Entity.h>

struct Vector3;

class MS2ActorUpdater : public CPtred
{
public:
    MS2ActorUpdater(const egf::EntityID& kId);       // 0x1414a8240
    virtual ~MS2ActorUpdater();                                     // 0x1414a8380
    float FUN_1414a8410(const Vector3& kPos);               // m_fDistB = |kPos - entity position|
    float FUN_1414a84f0(const Vector3& kPos);               // m_fDistA = |kPos - entity position|
    void FUN_1414a85d0(float fInterval);                            // run the gate with the mode's duration
    float GetDistB() const;                                    // m_fDistB
    float GetDistA() const;                                    // m_fDistA
    void FUN_141c1bb30(float f) { m_fDistB = f; }                  // 0x141c1bb30 (inline; COMDAT in worldservice.cpp)
    // @0x141bfe6d0
    egf::EntityID FUN_141bfe6d0() { return m_kId; }                 // (inline; COMDAT in worldservice.cpp)

    CMeshUpdateGate* m_pGate;                                       // +0x18
    egf::EntityID m_kId;                                            // +0x20
    float m_fDistA;                                                 // +0x28
    float m_fDistB;                                                 // +0x2c
};
MS2_CHECK_SIZE(MS2ActorUpdater, 0x30);
