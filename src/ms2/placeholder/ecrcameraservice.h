// ecrcameraservice.h - the real ecr::CameraService (engine/gamebryo/GameFramework/ecr/CameraService.h, system service id
// kCLASSID_CameraService 0x07002002) plus the game's service-manager access. Not an original header: MS2's
// efd::ServiceManager has a different vftable from the SDK's (GetSystemService is slot 14 here), so the manager is a stand-in
// (Unk_ServiceManager). Exe facts: ecr::CameraService members end at 0x60 (ctor 0x14200a080, dtor 0x14200a190); MS2CameraService
// (0xa0 bytes, vftables at 0/24/104) places its egf::IPropertyCallback base at 0x68, 8 bytes after that (unexplained).
//
// Usage (CCameraMode, 0x140afe4b0):
//     efd::SmartPointer<ecr::CameraService> spCamera = g_143b059e8.GetSystemServiceAs<ecr::CameraService>();
#pragma once
#include <efd/IBase.h>
#include <efd/ISystemService.h>
#include <efd/SmartPointer.h>
#include <ecr/CameraService.h>
#include <ecr/CameraData.h>

#include "ms2/ms2layout.h"

class Unk_CameraTarget;     // what FUN_1413f98d0 returns (the active camera entity)

// Unrecovered members of the real ecr::CameraService, as free functions (x64 has one calling convention, so `this` is the first
// argument). FUN_14200aae0 is ecr::CameraService::GetActiveCamera(RenderSurface*) (the "target" is the surface, whose window
// handle is at +0x10); FUN_1414af480 is MS2CameraService::FUN_1414af480 (ms2cameraservice.h).
ecr::CameraData* FUN_14200aae0(ecr::CameraService* pService, Unk_CameraTarget* pTarget);    // camera object of the target (or 0)

// MS2's efd::ServiceManager (only the slot used here is declared).
class Unk_ServiceManager
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13();
    virtual efd::ISystemService* GetSystemService(efd::UInt32 idSysSer) const;     // slot 14

    // efd::ServiceManager::GetSystemServiceAs<T>() (ServiceManager.inl)
    template <typename T> T* GetSystemServiceAs() const
    {
        efd::ISystemService* pService = GetSystemService(T::CLASS_ID);
        T* pResult = EE_DYNAMIC_CAST(T, pService);
        return pResult;
    }
};

// The global at 0x143b059e8 (egf::g_bapiContext), viewed as the game framework object; its first member is a smart pointer to the service manager
// (efd::SmartPointer<ServiceManager>::operator-> is 0x1401cd190, a COMDAT of another obj).
class Unk_AppFramework
{
public:
    template <typename T> T* GetSystemServiceAs()
    {
        return m_spServiceManager->GetSystemServiceAs<T>();
    }

    efd::SmartPointer<Unk_ServiceManager> m_spServiceManager;   // +0x00
};
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define g_143b059e8 (*(Unk_AppFramework*)&egf::g_bapiContext)   // C3: was extern Unk_AppFramework g_143b059e8
