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

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
class Unk_Clock;
Unk_Clock* FUN_14086d260();                                     // the game clock
double FUN_141473280(Unk_Clock* pClock);                        // seconds
void FUN_1414f1240(ecr::SceneGraphService* pService, egf::Entity* pEntity);   // show the entity's scene graph
void FUN_1414f11d0(ecr::SceneGraphService* pService, egf::Entity* pEntity);   // hide the entity's scene graph
ecr::SceneGraphService* FUN_1410a68f0(char* pCell);             // scene graph service lookup
extern char DAT_143b059e8;                                      // service lookup cell

// @0x14176f2a0
CMeshUpdateGate::CMeshUpdateGate()
{
    m_fLast = (float)FUN_141473280(FUN_14086d260());
    m_fInterval = 0.0f;
    m_fDuration = 0.0f;
    m_bActive = false;
    m_bPending = false;
    m_pProcess = NiNew NiMeshUpdateProcess(NULL);
    m_pProcess->SetSubmitModifiers(true);
    m_pProcess->SetUpdateControllers(false);
}

// @0x14176f390
void CMeshUpdateGate::FUN_14176f390()
{
    if (m_pProcess)
    {
        NiDelete m_pProcess;
        m_pProcess = NULL;
    }
}
MS2_REPLACE_METHOD(0x14176f390, CMeshUpdateGate, FUN_14176f390, 107, 0xF384864A);

// @0x14176f410
bool CMeshUpdateGate::FUN_14176f410(egf::Entity* pEntity, float fInterval)
{
    if (pEntity)
    {
    bool bShown = IsActive();
    if (FUN_14176f740(fInterval) && bShown != IsActive())
    {
        bShown = bShown ^ 1;
        efd::SmartPointer<ecr::SceneGraphService> spService(FUN_1410a68f0(&DAT_143b059e8));
        if (bShown)
            FUN_1414f1240(spService, pEntity);
        else
            FUN_1414f11d0(spService, pEntity);
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
        if (FUN_14176f740(fInterval) && bShown != IsActive())
        {
            bShown = bShown ^ 1;
            if (pEntity)
            {
                efd::SmartPointer<ecr::SceneGraphService> spService(FUN_1410a68f0(&DAT_143b059e8));
                if (bShown)
                    FUN_1414f1240(spService, pEntity);
                else
                    FUN_1414f11d0(spService, pEntity);
            }
        }
    }
    else if (bShown)
    {
        efd::SmartPointer<ecr::SceneGraphService> spService(FUN_1410a68f0(&DAT_143b059e8));
        FUN_1414f11d0(spService, pEntity);
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
        efd::SmartPointer<ecr::SceneGraphService> spService(FUN_1410a68f0(&DAT_143b059e8));
        FUN_1414f11d0(spService, pEntity);
        m_bActive = false;
        m_bPending = true;
    }
}
MS2_REPLACE_METHOD(0x14176f680, CMeshUpdateGate, FUN_14176f680, 130, 0x22CFBCFD);

// @0x14176f710
void CMeshUpdateGate::FUN_14176f710()
{
    m_fLast = (float)FUN_141473280(FUN_14086d260());
}
MS2_REPLACE_METHOD(0x14176f710, CMeshUpdateGate, FUN_14176f710, 40, 0x42587A2C);

// @0x14176f740
bool CMeshUpdateGate::FUN_14176f740(float)
{
    float fInterval = m_fInterval;
    float fElapsed = (float)(FUN_141473280(FUN_14086d260()) - m_fLast);
    bool bDue = !(fInterval > fElapsed);
    if (bDue)
    {
        m_fLast = (float)FUN_141473280(FUN_14086d260());
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
MS2_REPLACE_METHOD(0x14176f740, CMeshUpdateGate, FUN_14176f740, 219, 0x4AF8C9A0);

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
