// ms2cameraservice.h - MS2CameraService (RTTI .?AVMS2CameraService@@): the game's subclass of the engine's ecr::CameraService.
// It also implements egf::IPropertyCallback (second base, at +0x68; ecr::CameraService's own members end at 0x60). Camera
// property updates only mark the entity dirty; OnTick then re-applies the camera of every dirty entity. Recovered from
// MapleStory2.exe KMS2_DEV x64; owning unit `?\ms2cameraservice.cpp` (0x1414af320-0x1414b1230, dir client\ms2).
#pragma once

#include "ms2/ms2layout.h"
#include <atlcoll.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <egf/IPropertyCallback.h>
#include "ms2/placeholder/ecrcameraservice.h"

class MS2CameraService : public ecr::CameraService, public egf::IPropertyCallback
{
public:
    MS2CameraService();                                                 // 0x1414af320
    virtual ~MS2CameraService();                                        // 0x1414af3a0, ??_G 0x1414afc60
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar);     // 0x1414af410
    virtual efd::AsyncResult OnTick();                                  // 0x1414af4d0
    virtual void OnPropertyUpdate(const efd::ClassID& callerID, egf::Entity* pEntity, const egf::PropertyID& propertyID,
        const egf::IProperty* pProperty, const efd::UInt32 tags);      // 0x1414af5e0

    // Applies the camera data to the local player entity (called by CCameraMode with the plain CameraService pointer).
    void UpdateCameraFromMgr(ecr::CameraData* pCamera);                       // 0x1414af480

public:
    ATL::CRBMap<egf::EntityID, int> m_dirty;                            // +0x70, entities whose camera needs refreshing
};
MS2_CHECK_SIZE(MS2CameraService, 0xa0);
MS2_CHECK_OFFSET(MS2CameraService, m_dirty, 0x70);
