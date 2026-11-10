// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Environment force appliers of CEquipModel (null / wind).
// MS2-UNIT: client\ms2\equipmodelforceapplier.cpp
// MS2-RANGE: 0x141209610-0x14120c0e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetOwner@IEquipModelForceApplier@@QEBAPEAVCEquipModel@@XZ 0x141209800 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetJointAt@NiPhysXPropDesc@@QEAA?AV?$SmartPointer@VNiPhysXJointDesc@@@efd@@I@Z 0x14120abd0
// MS2-PIN: ?GetJointCount@NiPhysXPropDesc@@QEBAIXZ 0x14120ac30
// MS2-PIN: ??$GetService@VPropService@ecrPhysX@@@@YAPEAVPropService@ecrPhysX@@XZ 0x14120a220
// MS2-PIN: ??$GetSystemServiceAs@VPropService@ecrPhysX@@@Unk_ServiceManager@@QEBAPEAVPropService@ecrPhysX@@XZ 0x14120a240
// MS2-PIN: ??$DynamicCast@VPropService@ecrPhysX@@VISystemService@efd@@@efd@@YAPEAVPropService@ecrPhysX@@PEAVISystemService@0@@Z 0x14120a1d0
// MS2-PIN: ??0?$CAtlMap@PEAVNxActor@@PEAV1@V?$CElementTraits@PEAVNxActor@@@ATL@@V23@@ATL@@QEAA@IMMMI@Z 0x14120a350
// MS2-PIN: ??1?$SmartPointer@VNiPhysXActorDesc@@@efd@@QEAA@XZ 0x14120a5d0
// MS2-PIN: ??1?$SmartPointer@VNiPhysXJointDesc@@@efd@@QEAA@XZ 0x14120a600
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\equipmodelforceapplier.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <stdlib.h>
#include <atlcoll.h>
#include "equipmodelforceapplier.h"
#include "kfmmodel.h"
#include "physxhelper.h"
#include <efd/ILogger.h>
#include <efd/LoggerMacros.h>
#include <egf/EntityID.h>
#include <ecrPhysX/PropService.h>
#include <NiPhysXProp.h>
#include <NiPhysXPropDesc.h>
#include <NiPhysXActorDesc.h>
#include <NiPhysXJointDesc.h>   // C3: the wind loop walks the snapshot's joints
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/equipmodel.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/equipitem.h"  // C3
#include "ms2/placeholder/fittingdollpc.h"

#ifdef MS2_HOOK_DLL
extern unsigned char DAT_143afc898;                                        // assertions throw when set
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" unsigned char __identifier("?DAT_143afc898@@3DA");   // assertions throw when set (the engine's name)
#define DAT_143afc898 __identifier("?DAT_143afc898@@3DA")
#endif

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names) ----
void* FUN_141200a90(CEquipModel* pModel);                           // the model's info record (CEquipModel +0x18)
class ModelGroup   // C3: member view for the former free stand-ins
{
public:
    int FUN_1405451a0() const;
};

// The owner record's entity reference: a smart pointer to an object that carries the world id (+0x58).

// The world object table (singleton FUN_1403ed2d0) and its game objects (slot 20 = rotation in degrees).
class Unk_WindObj
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual Vector3 GetRotation();                          // slot 20 (+0xa0)
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    class Unk_WsC_GameObj* FindObjectById(int id);   // C3: the real member (0x141bd1180, an object by id)
    static class WorldService* GetInstance();
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
float FUN_1409f2310(float f);                                       // sin
float FUN_1409f25a0(float f);                                       // cos
Unk_ServiceManager* FUN_1413f9850();                                // the framework's service manager
template <class T> T* GetService() { return FUN_1413f9850()->GetSystemServiceAs<T>(); }   // 0x14120a220

// C3: the former views are SDK classes. The snapshot's array at +0x30 is NiPhysXPropDesc::m_kJoints (GetJointCount 0x14120ac30,
// GetJointAt 0x14120abd0). The two-slot loop is NiPhysXJointDesc::GetActor(l) (0x141ef37e0, m_aspActors[2]), and the sub-object
// holding the NxActor at +0x60 is NiPhysXActorDesc (GetActor 0x14120ab90).
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// @0x141209640
IEquipModelForceApplierPtr CreateForceApplier(CEquipModel* pModel)
{
    if (!(pModel && FUN_141200a90(pModel) && ((class ModelGroup*)(void*)(FUN_141200a90(pModel)))->FUN_1405451a0() == 7)) {
        return IEquipModelForceApplierPtr(EE_NEW EquipModelNullApplier());
    }
    return IEquipModelForceApplierPtr(EE_NEW EquipModelWindApplier(pModel));
}

// @0x1412097b0
IEquipModelForceApplier::IEquipModelForceApplier(CEquipModel* pOwner)
{
    m_pOwner = pOwner;
}

// @0x141209610
IEquipModelForceApplier::~IEquipModelForceApplier()
{
}

// @0x141209820
EquipModelNullApplier::EquipModelNullApplier()
    : IEquipModelForceApplier(0)
{
}

// @0x141209860
EquipModelNullApplier::~EquipModelNullApplier()
{
}

// @0x141209890
void EquipModelNullApplier::OnTick(double)
{
}

// @0x1412098b0
EquipModelWindApplier::EquipModelWindApplier(CEquipModel* pOwner)
    : IEquipModelForceApplier(pOwner)
{
    m_fElapsed = 0;
    m_fPeriod = 0;
}

// @0x141209910
EquipModelWindApplier::~EquipModelWindApplier()
{
}

// @0x141209940
void EquipModelWindApplier::OnTick(double fDeltaTime)
{
    CEquipModel* pModel = GetOwner();
    if (pModel->vfunc_8() == 0) {
        return;
    }
    MS2Ptr<CEquipItem> spOwner = reinterpret_cast<CEquipModel*>(pModel)->FUN_141200a40();
    if (spOwner == (CEquipItem*)0) {
        return;
    }
    Unk_WindObj* pObj = reinterpret_cast<Unk_WindObj*>(WorldService::GetInstance()->FindObjectById(spOwner->GetItem()->FUN_140526b10()));
    if (pObj == 0) {
        return;
    }
    PC* pWindModel = efd::DynamicCast<PC>(reinterpret_cast<GameObject*>(pObj));
    if (pWindModel == 0 || pWindModel->GetCurStateId() == 3) {
        return;
    }

    if (!(m_fElapsed < m_fPeriod)) {
        static float s_fVariance = reinterpret_cast<Common::Constants::Value<float>*>(((char*)GetClientConstants()) + 0x2f48)->Read();
        static float s_fBase = reinterpret_cast<Common::Constants::Value<float>*>(((char*)GetClientConstants()) + 0x2fa0)->Read();
        m_fPeriod = s_fBase + s_fVariance * (rand() / 32767.0f - 0.5f);
        m_fElapsed = 0;
    }
    static float s_fStrength = reinterpret_cast<Common::Constants::Value<float>*>(((char*)GetClientConstants()) + 0x2ff8)->Read();
    float fGust = s_fStrength * (float)fDeltaTime * (FUN_1409f2310((m_fElapsed / m_fPeriod) * 2.0f * 3.1415927f - 3.1415927f) + 1.0f);
    m_fElapsed = (float)(m_fElapsed + fDeltaTime);

    Vector3 ptRot = pObj->GetRotation();
    ptRot = (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptRot) * 3.1415927f)) / 180.0f);
    NxVec3 vForce(-fGust * FUN_1409f25a0(ptRot.z), fGust * FUN_1409f2310(ptRot.z), 0);
    if (!vForce.isFinite()) {
        EE_LOG_AT(0x12, efd::ILogger::kERR1, ("EquipModelWindApplier::OnTick"), MS2_THIS_FILE, 0x54);
        if (DAT_143afc898 != 0) {
            throw 13;
        }
        return;
    }

    ATL::CAtlMap<NxActor*, NxActor*> mapActors;
    ecrPhysX::PropService* pService = GetService<ecrPhysX::PropService>();
    unsigned nProps = pService->GetNumProps(static_cast<CKfmModel*>(pModel)->GetEntityID());
    for (unsigned i = 0; i < nProps; i++) {
        NiPhysXProp* pProp = pService->GetPropAt(static_cast<CKfmModel*>(pModel)->GetEntityID(), i);
        for (unsigned j = 0; j < pProp->GetSourcesCount(); j++) {
            NiPhysXPropDesc* pDesc = pProp->GetSnapshot();
            for (unsigned k = 0; k < pDesc->GetJointCount(); k++) {
                NiPhysXJointDesc* pJointDesc = pDesc->GetJointAt(k);
                for (unsigned l = 0; l < 2; l++) {
                    NxActor* pActor = pJointDesc->GetActor(l)->GetActor();
                    if (pActor && pActor->isDynamic() && !pActor->readBodyFlag(NX_BF_KINEMATIC)
                        && mapActors.Lookup(pActor) == 0) {
                        mapActors.SetAt(pActor, pActor);
                    }
                }
            }
        }
    }
    POSITION pos = mapActors.GetStartPosition();
    while (pos) {
        NxActor* pActor = mapActors.GetNextValue(pos);
        pActor->addForce(vForce, NX_FORCE, true);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
