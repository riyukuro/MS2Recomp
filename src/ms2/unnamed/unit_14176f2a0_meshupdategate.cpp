// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mesh update throttle (CMeshUpdateGate) + NiMeshUpdateProcess/NiUpdateProcess members.
// MS2-UNIT: unit_14176f2a0
// MS2-RANGE: 0x14176f2a0-0x14176fbb0 .text$mn
// MS2-PIN: ??0?$SmartPointer@VSceneGraphService@ecr@@@efd@@QEAA@PEAVSceneGraphService@ecr@@@Z 0x1410a69b0
// MS2-PIN: ??B?$SmartPointer@VSceneGraphService@ecr@@@efd@@QEBAPEAVSceneGraphService@ecr@@XZ 0x1411d7280
// MS2-PIN: ??1?$SmartPointer@VSceneGraphService@ecr@@@efd@@QEAA@XZ 0x1410a6c40
#define MS2_THIS_FILE ""
#include <vcruntime_string.h>
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_14176f2a0.h"
#include <NiMeshUpdateProcess.h>
#include <efd/SmartPointer.h>
#include <egf/Entity.h>
#include <ecr/SceneGraphService.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/ms2scenegraphservice.h"   // MS2SceneGraphService::MarkEntityDynamic / RemoveEntityFromUpdate

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
class Unk_Clock;
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(char*)&egf::g_bapiContext)          // C3: was extern char DAT_143b059e8

// @0x14176f2a0
CMeshUpdateGate::CMeshUpdateGate()
{
    m_fLast = (float)((class CMainSystem*)(class Unk_Clock*)(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())))->GetGameTime();
    m_fInterval = 0.0f;
    m_fDuration = 0.0f;
    m_bActive = false;
    m_bPending = false;
    m_pProcess = NiNew NiMeshUpdateProcess(NULL);
    m_pProcess->SetSubmitModifiers(true);
    m_pProcess->SetUpdateControllers(false);
}

// @0x14176f390
void CMeshUpdateGate::ReleaseProcess()
{
    if (m_pProcess)
    {
        NiDelete m_pProcess;
        m_pProcess = NULL;
    }
}
MS2_REPLACE_METHOD(0x14176f390, CMeshUpdateGate, ReleaseProcess, 107, 0xF384864A);

// @0x14176f410
bool CMeshUpdateGate::FUN_14176f410(egf::Entity* pEntity, float fInterval)
{
    if (pEntity)
    {
    bool bShown = IsActive();
    if (IsUpdateDue(fInterval) && bShown != IsActive())
    {
        bShown = bShown ^ 1;
        efd::SmartPointer<ecr::SceneGraphService> spService(egf::g_bapiContext.GetSystemServiceAs<ecr::SceneGraphService>());
        if (bShown)
            reinterpret_cast<MS2SceneGraphService*>((ecr::SceneGraphService*)spService)->RemoveEntityFromUpdate(pEntity);
        else
            reinterpret_cast<MS2SceneGraphService*>((ecr::SceneGraphService*)spService)->MarkEntityDynamic(pEntity);
    }
    return bShown;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14176f410, CMeshUpdateGate, FUN_14176f410, 232, 0x5891011D);

// @0x14176f500
bool CMeshUpdateGate::FUN_14176f500(egf::Entity* pEntity, float fInterval, float fTime)
{
    if (pEntity)
    {
    bool bShown = IsActive();
    if (fTime >= GetDuration())
    {
        if (IsUpdateDue(fInterval) && bShown != IsActive())
        {
            bShown = bShown ^ 1;
            if (pEntity)
            {
                efd::SmartPointer<ecr::SceneGraphService> spService(egf::g_bapiContext.GetSystemServiceAs<ecr::SceneGraphService>());
                if (bShown)
                    reinterpret_cast<MS2SceneGraphService*>((ecr::SceneGraphService*)spService)->RemoveEntityFromUpdate(pEntity);
                else
                    reinterpret_cast<MS2SceneGraphService*>((ecr::SceneGraphService*)spService)->MarkEntityDynamic(pEntity);
            }
        }
    }
    else if (bShown)
    {
        efd::SmartPointer<ecr::SceneGraphService> spService(egf::g_bapiContext.GetSystemServiceAs<ecr::SceneGraphService>());
        reinterpret_cast<MS2SceneGraphService*>((ecr::SceneGraphService*)spService)->MarkEntityDynamic(pEntity);
        m_bActive = true;
        bShown = true;
        m_bPending = true;
    }
    return bShown;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14176f500, CMeshUpdateGate, FUN_14176f500, 364, 0x2CFC64F7);

// @0x14176f680
void CMeshUpdateGate::FUN_14176f680(egf::Entity* pEntity)
{
    if (pEntity && IsActive())
    {
        efd::SmartPointer<ecr::SceneGraphService> spService(egf::g_bapiContext.GetSystemServiceAs<ecr::SceneGraphService>());
        reinterpret_cast<MS2SceneGraphService*>((ecr::SceneGraphService*)spService)->MarkEntityDynamic(pEntity);
        m_bActive = false;
        m_bPending = true;
    }
}
MS2_REPLACE_METHOD(0x14176f680, CMeshUpdateGate, FUN_14176f680, 130, 0x22CFBCFD);

// @0x14176f710
void CMeshUpdateGate::FUN_14176f710()
{
    m_fLast = (float)((class CMainSystem*)(class Unk_Clock*)(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())))->GetGameTime();
}
MS2_REPLACE_METHOD(0x14176f710, CMeshUpdateGate, FUN_14176f710, 40, 0x42587A2C);

// @0x14176f740
bool CMeshUpdateGate::IsUpdateDue(float)
{
    float fInterval = m_fInterval;
    float fElapsed = (float)(((class CMainSystem*)(class Unk_Clock*)(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())))->GetGameTime() - m_fLast);
    bool bDue = !(fInterval > fElapsed);
    if (bDue)
    {
        m_fLast = (float)((class CMainSystem*)(class Unk_Clock*)(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())))->GetGameTime();
        m_bPending = true;
        m_bActive = false;
        return true;
    }
    else if (m_bPending && !m_bActive)
    {
        m_bActive = true;
        m_bPending = false;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14176f740, CMeshUpdateGate, IsUpdateDue, 219, 0x4AF8C9A0);

// @0x14176fa50
float CMeshUpdateGate::GetDuration() const { return m_fDuration; }
MS2_REPLACE_METHOD(0x14176fa50, CMeshUpdateGate, GetDuration, 16, 0x5C30854E);

// @0x14176fa60
bool CMeshUpdateGate::IsActive() const { return m_bActive; }
MS2_REPLACE_METHOD(0x14176fa60, CMeshUpdateGate, IsActive, 15, 0x5B0DC671);

// @0x14176fa70
void CMeshUpdateGate::SetProcess(NiMeshUpdateProcess* pProcess) { m_pProcess = pProcess; }
MS2_REPLACE_METHOD(0x14176fa70, CMeshUpdateGate, SetProcess, 25, 0x7B768AB3);

// @0x14176fa90
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
