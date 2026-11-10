// equipmodelforceapplier.h - per-model "environment force" appliers of CEquipModel (owner unit
// client\ms2\equipmodelforceapplier.cpp, 0x141209610-0x14120c0e0). NiRefObject based, 0x18 bytes; the wind applier adds
// two floats. Class and member names invented (RTTI names IEquipModelForceApplier / EquipModelNullApplier /
// EquipModelWindApplier are real).
#pragma once
#include <NiRefObject.h>
#include <NiSmartPointer.h>
#include "ms2/ms2layout.h"

class CEquipModel;

// vftable 0x142ec1250 (3 slots: scalar-deleting dtor 0x141209610 family, NiRefObject::DeleteThis, pure OnTick).
class IEquipModelForceApplier : public NiRefObject
{
public:
    IEquipModelForceApplier(CEquipModel* pOwner);                       // 0x1412097b0
    virtual ~IEquipModelForceApplier();                                 // 0x141209610
    virtual void OnTick(double fDeltaTime) = 0;                         // slot 2
    CEquipModel* GetOwner() const { return m_pOwner; }                  // 0x141209800
    CEquipModel* m_pOwner;                                              // +0x10
};
MS2_CHECK_SIZE(IEquipModelForceApplier, 0x18);
typedef NiPointer<IEquipModelForceApplier> IEquipModelForceApplierPtr;

// vftable 0x142ec1270: does nothing.
class EquipModelNullApplier : public IEquipModelForceApplier
{
public:
    EquipModelNullApplier();                                            // 0x141209820
    virtual ~EquipModelNullApplier();                                   // 0x141209860
    virtual void OnTick(double fDeltaTime);                             // 0x141209890
};
MS2_CHECK_SIZE(EquipModelNullApplier, 0x18);

// vftable 0x142ec1290: gusts of wind (a sine-shaped force along the owner's heading, randomised period) on every
// dynamic PhysX actor of the owner entity's props.
class EquipModelWindApplier : public IEquipModelForceApplier
{
public:
    EquipModelWindApplier(CEquipModel* pOwner);                         // 0x1412098b0
    virtual ~EquipModelWindApplier();                                   // 0x141209910
    virtual void OnTick(double fDeltaTime);                             // 0x141209940
    float m_fElapsed;                                                   // +0x18 time inside the current gust
    float m_fPeriod;                                                    // +0x1c gust length (re-rolled when elapsed)
};
MS2_CHECK_SIZE(EquipModelWindApplier, 0x20);

// Factory (0x141209640): wind applier for a model whose info type is 7, else the null applier.
IEquipModelForceApplierPtr CreateForceApplier(CEquipModel* pModel);
