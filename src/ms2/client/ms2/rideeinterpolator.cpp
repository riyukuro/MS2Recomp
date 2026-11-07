// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See rideeinterpolator.h.
// MS2-UNIT: ?\rideeinterpolator.cpp
// MS2-RANGE: 0x1400e3e80-0x1400e3eb0 .text$di
// MS2-RANGE: 0x141020350-0x141020bd0 .text$mn
// MS2-PIN: ??_GRideeInterpolator@@UEAAPEAXI@Z 0x141020b60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\rideeinterpolator.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "rideeinterpolator.h"

#include <NiAVObject.h>
#include <NiNode.h>
#include "ms2/client/ms2/ridee.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cmainsystem.h"

// ---- out-of-unit callees (all unit-local views) ----
class Unk_RiObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual bool vfunc_5(int nId, __int64* pOut); };
__int64 FUN_141020ad0(__int64 pObject);                         // the rider's body component (vfunc 5, id 0x6200013)
NiAVObject* FUN_141b6ef70(egf::EntityID id);                    // the scene root of an entity
void FUN_140b86230(const efd::Point3& kEuler, NiMatrix3& kOut);    // euler angles (degrees) to a rotation matrix
void FUN_140a0b1f0(const NiMatrix3&, efd::Point3&);   // C3: rotation to euler angles (degrees, negated)
class Unk_RiApp;

RideeInterpolator::RideeInterpolator()
    : NiTransformInterpolator()
{
    m_nObjectId = 0;
    m_bAlwaysUpdate = true;
}

RideeInterpolator::RideeInterpolator(NiTransformData* pData)
    : NiTransformInterpolator(pData)
{
    m_nObjectId = 0;
    m_bAlwaysUpdate = true;
}

RideeInterpolator::~RideeInterpolator()
{
}

// @0x141020430
// Seats the interpolated node on the rider: the node's world transform, rotated by the riding row's seat rotation and
// moved by its seat offset along the rotated axes, is applied to the rider's scene root.
bool RideeInterpolator::Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue)
{
    if (m_nObjectId == 0)
        return false;
    PCBase* pBody = (PCBase*)FUN_141020ad0(reinterpret_cast<__int64>(WorldService::GetInstance()->FUN_141bd1200(m_nObjectId)));
    if (pBody == 0)
        return false;
    efd::SmartPointer<Ridee> spRidee(pBody->FUN_1416764a0());
    if (spRidee == 0)
        return false;
    MS2SvrPtr<CRideeData> spData = spRidee->GetData();
    if (spData == 0)
        return false;
    efd::SmartPointer<NiNode> spNode(NiDynamicCast(NiNode, pkInterpTarget));
    NiAVObject* pRoot = FUN_141b6ef70(pBody->FUN_14123c460());
    if ((spNode ? true : false) && pRoot != 0)
    {
        Unk_RiderPtr spModel = spData->FUN_140784970();
        if (spModel == 0)
            return false;
        NiTransform kXform = ((class NiAVObject*)(class NiAVObject*)(spNode.operator->()))->GetLocalTransform();
        NiTransform kParent;
        ((class NiTransform*)(class NiTransform*)(&kParent))->MakeIdentity();
        if (((class NiAVObject*)(class NiAVObject*)(spNode.operator->()))->GetParent() != 0)
            kParent = ((class NiAVObject*)(class NiAVObject*)(((class NiAVObject*)(class NiAVObject*)(spNode.operator->()))->GetParent()))->GetWorldTransform();
        kXform = kParent * kXform;
        NiPoint3 kPos = kXform.m_Translate;
        NiMatrix3 kRot = kXform.m_Rotate;
        efd::Point3 kEuler;
        efd::Point3 kSeatRot(spModel->m_vRotation.x, spModel->m_vRotation.y, spModel->m_vRotation.z);
        NiMatrix3 kSeat;
        FUN_140b86230(kSeatRot, kSeat);
        kRot = kRot * kSeat;
        FUN_140a0b1f0(static_cast<const NiMatrix3&>(kRot), reinterpret_cast<efd::Point3&>(kEuler));
        efd::Point3 kX;
        ((efd::Matrix3*)(class NiMatrix3 const*)(&kRot))->GetCol(0, *(class efd::Point3*)(&kX));
        ((Vector3*)&(kX))->Unitize();
        efd::Point3 kY;
        ((efd::Matrix3*)(class NiMatrix3 const*)(&kRot))->GetCol(1, *(class efd::Point3*)(&kY));
        ((Vector3*)&(kY))->Unitize();
        efd::Point3 kZ;
        ((efd::Matrix3*)(class NiMatrix3 const*)(&kRot))->GetCol(2, *(class efd::Point3*)(&kZ));
        ((Vector3*)&(kZ))->Unitize();
        kPos = kPos + kY * -spModel->m_vTranslation.y;
        kPos = kPos + kX * (0, spModel->m_vTranslation.x);
        kPos = kPos + kZ * (0, spModel->m_vTranslation.z);
        ((class NiAVObject*)(class NiAVObject*)(pRoot))->SetTranslate(kPos);
        ((class NiAVObject*)(class NiAVObject*)(pRoot))->SetRotate(kRot);
        ((class NiAVObject*)(void*)(pRoot))->UpdateEffects();
        pRoot->UpdateProperties();
        ((class NiAVObject*)(void*)(pRoot))->Update((float)((class CMainSystem*)(class Unk_RiApp*)(reinterpret_cast<Unk_RiApp*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    }
    m_fLastTime = fTime;
    return true;
}

// @0x141020a70
void RideeInterpolator::SetObjectId(int nObjectId)
{
    m_nObjectId = nObjectId;
}

// @0x141020a90
bool RideeInterpolator::AlwaysUpdate() const
{
    return m_bAlwaysUpdate;
}

// @0x141020ad0
__int64 FUN_141020ad0(__int64 pObject)
{
    __int64 pRes = 0;
    if (pObject != 0 && ((Unk_RiObj*)pObject)->vfunc_5(0x6200013, &pRes))
        return pRes;
    else
        return 0;
}

const NiRTTI RideeInterpolator::ms_RTTI("RideeInterpolator", &NiTransformInterpolator::ms_RTTI);   // @0x1400e3e80

// @0x141020b20
bool FUN_141020b20(__int64* pLhs, __int64 nRhs)
{
    return *pLhs == nRhs;
}
