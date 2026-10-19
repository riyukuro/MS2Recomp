// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The game's subclass of ecr::CameraService.
// MS2-UNIT: ?\ms2cameraservice.cpp
// MS2-RANGE: 0x1414af320-0x1414b1230 .text$mn
// MS2-PIN: ??_7MS2CameraService@@6BISystemService@efd@@@ 0x142f1f128
// MS2-PIN: ??_7MS2CameraService@@6BIRenderServiceDelegate@ecr@@@ 0x142f1f1b8
// MS2-PIN: ??_7MS2CameraService@@6B@ 0x142f1f210
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2cameraservice.h"
#include "hook/ms2hook.h"
#include <egf/Entity.h>
#include <egf/EntityManager.h>
#include <ecr/CameraData.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

// ---- out-of-unit callees ----
class Unk_GameInstance;
Unk_GameInstance* FUN_1409478c0();                                           // the game instance (global)
egf::Entity* FUN_140af7f70(Unk_GameInstance* pGame);                         // its local player entity (or 0)
egf::EntityManager* FUN_1409670f0();                                         // the world's entity manager
egf::Entity* FUN_1411cf440(egf::EntityManager* mgr, const egf::EntityID* id);   // entity lookup by id
void FUN_1413eb6d0(egf::IPropertyCallback* pCallback);                       // registers the camera property callback

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1414af320
MS2CameraService::MS2CameraService()
    : m_dirty(10)
{
}
#endif

// @0x1414af3a0
MS2CameraService::~MS2CameraService()
{
}

// @0x1414af410
efd::SyncResult MS2CameraService::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    efd::SyncResult result = ecr::CameraService::OnPreInit(pDependencyRegistrar);
    if (result == efd::SyncResult_Success)
        FUN_1413eb6d0(static_cast<egf::IPropertyCallback*>(this));
    return result;
}
MS2_REPLACE_METHOD(0x1414af410, MS2CameraService, OnPreInit, 92, 0x25AB48BB);

// @0x1414af480
void MS2CameraService::FUN_1414af480(ecr::CameraData* pCamera)
{
    egf::Entity* pEntity = FUN_140af7f70(FUN_1409478c0());
    if (pEntity && pCamera)
        UpdateCamera(pCamera, pEntity);
}
MS2_REPLACE_METHOD(0x1414af480, MS2CameraService, FUN_1414af480, 73, 0x27A5C709);

// @0x1414af4d0
efd::AsyncResult MS2CameraService::OnTick()
{
    for (POSITION pos = m_dirty.GetHeadPosition(); pos != NULL; m_dirty.GetNext(pos))
    {
        egf::EntityID id = m_dirty.GetKeyAt(pos);
        ecr::CameraDataPtr spCamera = NULL;
        if (m_entityCameraMap.find(id, spCamera))
        {
            egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), &id);
            if (pEntity)
                UpdateCamera(spCamera, pEntity);
        }
    }
    m_dirty.RemoveAll();
    return ecr::CameraService::OnTick();
}
MS2_REPLACE_METHOD(0x1414af4d0, MS2CameraService, OnTick, 265, 0xDFBD9EEA);

// @0x1414af5e0
void MS2CameraService::OnPropertyUpdate(const efd::ClassID&, egf::Entity* pEntity, const egf::PropertyID& propertyID,
    const egf::IProperty*, const efd::UInt32)
{
    if (pEntity == NULL)
        return;
    if (propertyID == 0xfd95ca52 || propertyID == 0x68c7c29d || propertyID == 0x2d7cad2d)
    {
        ecr::CameraDataPtr spCamera = NULL;
        if (!m_entityCameraMap.find(pEntity->GetEntityID(), spCamera))
            return;
        if (m_dirty.Lookup(pEntity->GetEntityID()) == NULL)
            m_dirty.SetAt(pEntity->GetEntityID(), 0);
    }
}
MS2_REPLACE_METHOD_VIA(0x1414af5e0, MS2CameraService, egf::IPropertyCallback, OnPropertyUpdate, 231, 0x9072AF41);

// @0x1414b1110 (the UCRT header-inline memmove_s from corecrt_memcpy_s.h, emitted here as an ordinary function)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
errno_t FUN_1414b1110(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}
