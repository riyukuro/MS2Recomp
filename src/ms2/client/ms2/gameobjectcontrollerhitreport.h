// gameobjectcontrollerhitreport.h - GameObjectControllerHitReport (RTTI name): the PhysX character-controller hit
// callback of the game's actors. Remembers the last touched shape's contact normal, the egf entity owning the touched
// actor and the touched controller. Derives the real NxUserControllerHitReport (PhysX 2.8.4, NxCharacter). Header
// name assumed.
#pragma once
#include <afx.h>
#include <NxPhysics.h>
// The NxCharacter include directory is not on the game include path (cmake/ms2-engine-flags.cmake): reach the real
// 2.8.4 header relatively. Ask the coordinator to add SDKs/NxCharacter/include to the engine include list.
#include "NxCharacter/include/NxController.h"

#include "ms2/ms2layout.h"
#include "cubespawnobject.h"        // Unk_EntRef (8-byte entity handle)

namespace egf { class EntityID; }
class CPhysXHelper;

// 0x38 bytes. vftable 0x142f2e... (3 slots: onShapeHit, onControllerHit, ??_G).
class GameObjectControllerHitReport : public NxUserControllerHitReport
{
public:
    GameObjectControllerHitReport();                                    // 0x140cfad00
    virtual ~GameObjectControllerHitReport();                           // 0x140cfada0

    NxControllerAction onShapeHit(const NxControllerShapeHit& hit) override;        // 0x140cfade0
    NxControllerAction onControllerHit(const NxControllersHit& hit) override;       // 0x140cfaec0

    NxVec3 GetNormal() const;                                           // 0x140cfaef0
    void FUN_140cfaf30();                                               // clear the entity and the hit flag
    egf::EntityID GetEntityID() const;                                  // 0x140cfaf70 (entity id or the null id)
    Unk_Entity* GetEntity() const;                                            // 0x140cfaff0
    void SetEntity(Unk_Entity* pEntity);                                      // 0x140cfb020
    void* GetOtherController() const;                                  // 0x140cfb050
    void ClearOtherController();                                        // 0x140cfb070
    void SetField28(void* p);                                           // 0x140cfb090
    void ClearHit();                                                    // 0x140cfb0b0
    int GetHit() const;                                                 // 0x140cfb0d0

private:
    NxVec3 m_normal;            // +0x08 contact normal of the last shape hit
    Unk_EntRef m_entity;        // +0x18 egf entity owning the touched actor
    void* m_pOther;             // +0x20 the other controller of the last controller hit
    void* m_p28;                // +0x28
    int m_bHit;                 // +0x30 1 while m_entity is valid
};
MS2_CHECK_SIZE(GameObjectControllerHitReport, 0x38);
