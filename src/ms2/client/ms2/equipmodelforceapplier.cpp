// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Environment force appliers of CEquipModel (null / wind).
// MS2-UNIT: client\ms2\equipmodelforceapplier.cpp
// MS2-RANGE: 0x141209610-0x14120c0e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetOwner@IEquipModelForceApplier@@QEBAPEAVCEquipModel@@XZ 0x141209800 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetActorAt@Unk_WindPropDesc@@QEAA?AV?$SmartPointer@VNiPhysXActorDesc@@@efd@@I@Z 0x14120abd0
// MS2-PIN: ?GetActorCount@Unk_WindPropDesc@@QEBAIXZ 0x14120ac30
// MS2-PIN: ??$GetService@VPropService@ecrPhysX@@@@YAPEAVPropService@ecrPhysX@@XZ 0x14120a220
// MS2-PIN: ??$GetSystemServiceAs@VPropService@ecrPhysX@@@Unk_ServiceManager@@QEBAPEAVPropService@ecrPhysX@@XZ 0x14120a240
// MS2-PIN: ??$DynamicCast@VPropService@ecrPhysX@@VISystemService@efd@@@efd@@YAPEAVPropService@ecrPhysX@@PEAVISystemService@0@@Z 0x14120a1d0
// MS2-PIN: ??0?$CAtlMap@PEAVNxActor@@PEAV1@V?$CElementTraits@PEAVNxActor@@@ATL@@V23@@ATL@@QEAA@IMMMI@Z 0x14120a350
// MS2-PIN: ??1?$SmartPointer@VUnk_WindSub@@@efd@@QEAA@XZ 0x14120a5d0
// MS2-PIN: ??1?$SmartPointer@VNiPhysXActorDesc@@@efd@@QEAA@XZ 0x14120a600
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
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern char DAT_143afc898;                                          // assertions throw when set

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names) ----
void* FUN_141200a90(CEquipModel* pModel);                           // the model's info record (CEquipModel +0x18)
int FUN_1405451a0(void* pInfo);                                     // its type (+0x30); 7 = wind

// The owner record's entity reference: a smart pointer to an object that carries the world id (+0x58).
class Unk_WindRef { public: int FUN_140526b10() const; };
// The model seen as the owner holder: FUN_141200a40 copies CEquipModel::m_spOwner (a member in the exe).
class Unk_WindEquip { public: MS2Ptr<Unk_EquipModelOwner> FUN_141200a40(); };
class Unk_EquipModelOwner { public: MS2Ptr<Unk_WindRef> FUN_1411dc7a0(); };

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
class Unk_WindWorld { public: Unk_WindObj* FUN_141bd1180(int nId); };
Unk_WindWorld* FUN_1403ed2d0();
class Unk_WindModel;                                                // the object's 0x6200003 interface
Unk_WindModel* FUN_14099eef0(Unk_WindObj* p);                       // EE_DYNAMIC_CAST-style query
int FUN_14166c930(Unk_WindModel* p);                                // its state (3 = not simulated)
char* FUN_1401d3200();                                              // Client::Constants
float FUN_1402bac70(void* pValue);                                  // Constants::Value<float>::get
float FUN_1409f2310(float f);                                       // sin
float FUN_1409f25a0(float f);                                       // cos
Unk_ServiceManager* FUN_1413f9850();                                // the framework's service manager
template <class T> T* GetService() { return FUN_1413f9850()->GetSystemServiceAs<T>(); }   // 0x14120a220

// The sub-object of an actor description that holds the PhysX actor (+0x60).
class Unk_WindSub : public NiRefObject
{
public:
    NxActor* FUN_14120ab90() const { return m_pActor; }
    char m_pad_10[0x50];
    NxActor* m_pActor;                                              // +0x60
};
typedef NiPointer<Unk_WindSub> Unk_WindSubPtr;

// The exe's NiPhysXPropDesc keeps its actor array at +0x30 (the engine header's NiPhysXPropDesc has it at +0x18), so the
// two accessors used here are declared on a unit-local view of the snapshot description.
class Unk_WindPropDesc
{
public:
    unsigned GetActorCount() const { return m_kActors.GetSize(); }
    NiPhysXActorDescPtr GetActorAt(unsigned uiIndex) { return m_kActors.GetAt(uiIndex); }
    char m_pad_00[0x30];
    NiTObjectArray<NiPhysXActorDescPtr> m_kActors;                  // +0x30
};
Unk_WindSubPtr* FUN_141ef37e0(NiPhysXActorDesc* pDesc, Unk_WindSubPtr* pOut, unsigned nIdx);

// @0x141209640
IEquipModelForceApplierPtr FUN_141209640(CEquipModel* pModel)
{
    if (!(pModel && FUN_141200a90(pModel) && FUN_1405451a0(FUN_141200a90(pModel)) == 7)) {
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
// MS2-FUNCTIONAL: not byte-matched (exe frame is 0x10 larger and 56 bytes shorter; local/temporary layout of the CAtlMap set and
// the smart-pointer temporaries differ, unit-local views of the exe's NiPhysX* layouts)
void EquipModelWindApplier::OnTick(double fDeltaTime)
{
    CEquipModel* pModel = GetOwner();
    if (pModel->vfunc_8() == 0) {
        return;
    }
    MS2Ptr<Unk_EquipModelOwner> spOwner = reinterpret_cast<Unk_WindEquip*>(pModel)->FUN_141200a40();
    if (spOwner == (Unk_EquipModelOwner*)0) {
        return;
    }
    Unk_WindObj* pObj = FUN_1403ed2d0()->FUN_141bd1180(spOwner->FUN_1411dc7a0()->FUN_140526b10());
    if (pObj == 0) {
        return;
    }
    Unk_WindModel* pWindModel = FUN_14099eef0(pObj);
    if (pWindModel == 0 || FUN_14166c930(pWindModel) == 3) {
        return;
    }

    if (!(m_fPeriod > m_fElapsed)) {
        static float s_fVariance = FUN_1402bac70(FUN_1401d3200() + 0x2f48);
        static float s_fBase = FUN_1402bac70(FUN_1401d3200() + 0x2fa0);
        m_fPeriod = s_fBase + s_fVariance * (rand() / 32767.0 - 0.5);
        m_fElapsed = 0;
    }
    static float s_fStrength = FUN_1402bac70(FUN_1401d3200() + 0x2ff8);
    float fStrength = s_fStrength * (float)fDeltaTime;
    float fGust = fStrength * (FUN_1409f2310((m_fElapsed / m_fPeriod) * 2.0 * 3.1415927 - 3.1415927) + 1.0);
    m_fElapsed = (float)(m_fElapsed + fDeltaTime);

    Vector3 ptRot = pObj->GetRotation();
    ptRot = ptRot.FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
    float fY = fGust * FUN_1409f2310(ptRot.z);
    float fX = -fGust * FUN_1409f25a0(ptRot.z);
    NxVec3 vForce(fX, fY, 0);
    if (!vForce.isFinite()) {
        EE_LOG_AT(0x12, 1, ("EquipModelWindApplier::OnTick"), MS2_THIS_FILE, 0x54);
        if (DAT_143afc898 != 0) {
            throw 13;
        }
        return;
    }

    ATL::CAtlMap<NxActor*, NxActor*> mapActors;
    ecrPhysX::PropService* pService = GetService<ecrPhysX::PropService>();
    egf::EntityID idEntity = static_cast<CKfmModel*>(pModel)->FUN_14143ff70();
    unsigned nProps = pService->GetNumProps(idEntity);
    for (unsigned i = 0; i < nProps; i++) {
        NiPhysXProp* pProp = pService->GetPropAt(static_cast<CKfmModel*>(pModel)->FUN_14143ff70(), i);
        for (unsigned j = 0; j < pProp->GetSourcesCount(); j++) {
            Unk_WindPropDesc* pDesc = reinterpret_cast<Unk_WindPropDesc*>(pProp->GetSnapshot());
            for (unsigned k = 0; k < pDesc->GetActorCount(); k++) {
                NiPhysXActorDescPtr spActorDesc = pDesc->GetActorAt(k);
                for (unsigned l = 0; l < 2; l++) {
                    Unk_WindSubPtr spSub;
                    FUN_141ef37e0(spActorDesc, &spSub, l);
                    NxActor* pActor = spSub->FUN_14120ab90();
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
