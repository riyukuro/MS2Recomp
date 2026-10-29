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

// ---- out-of-unit callees (all unit-local views) ----
class Unk_RiMain { };
class Unk_RiObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual bool vfunc_5(int nId, __int64* pOut); };
Unk_RiMain* FUN_1403ed2d0();                                    // the game object manager singleton
__int64 FUN_141bd1200(Unk_RiMain* p, int nObjectId);            // find the object by id
__int64 FUN_141020ad0(__int64 pObject);                         // the rider's body component (vfunc 5, id 0x6200013)
NiAVObject* FUN_141b6ef70(egf::EntityID id);                    // the scene root of an entity
const NiTransform& FUN_140a33f90(NiAVObject* pObj);             // NiAVObject::GetLocalTransform
const NiTransform& FUN_1409478e0(NiAVObject* pObj);             // NiAVObject::GetWorldTransform
NiNode* FUN_140a0b000(NiAVObject* pObj);                        // NiAVObject::GetParent
void FUN_141d2fab0(NiTransform* pXform);                        // NiTransform::MakeIdentity
void FUN_140b86230(const efd::Point3& kEuler, NiMatrix3& kOut);    // euler angles (degrees) to a rotation matrix
void FUN_140a0b1f0(const NiMatrix3& kRot, efd::Point3* pEuler); // rotation matrix to euler angles
void FUN_140a01190(const NiMatrix3* pRot, unsigned int uiCol, efd::Point3* pOut);   // NiMatrix3::GetCol
float FUN_140968990(efd::Point3& kPt);                          // efd::Point3::Unitize
void FUN_140981070(NiAVObject* pObj, const NiPoint3& kTrn);     // NiAVObject::SetTranslate
void FUN_140ddcca0(NiAVObject* pObj, const NiMatrix3& kRot);    // NiAVObject::SetRotate
void FUN_141d16210(void* pObj);
void FUN_141d16040(void* pObj, float fTime, bool bUpdateControllers);   // NiAVObject::Update
class Unk_RiApp;
Unk_RiApp* FUN_14086d260();                                     // the app
double FUN_141473280(Unk_RiApp* pApp);                          // the current game time

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
    PCBase* pBody = (PCBase*)FUN_141020ad0(FUN_141bd1200(FUN_1403ed2d0(), m_nObjectId));
    if (pBody == 0)
        return false;
    efd::SmartPointer<Ridee> spRidee(pBody->FUN_1416764a0());
    if (spRidee == 0)
        return false;
    MS2Ptr<Unk_RideeData> spData = spRidee->GetData();
    if (spData == 0)
        return false;
    efd::SmartPointer<NiNode> spNode(NiDynamicCast(NiNode, pkInterpTarget));
    NiAVObject* pRoot = FUN_141b6ef70(pBody->FUN_14123c460());
    if ((spNode ? true : false) && pRoot != 0)
    {
        MS2Ptr<Unk_RideeModel> spModel = spData->FUN_140784970();
        if (spModel == 0)
            return false;
        NiTransform kXform = FUN_140a33f90(spNode.operator->());
        NiTransform kParent;
        FUN_141d2fab0(&kParent);
        if (FUN_140a0b000(spNode.operator->()) != 0)
            kParent = FUN_1409478e0(FUN_140a0b000(spNode.operator->()));
        kXform = kParent * kXform;
        NiPoint3 kPos = kXform.m_Translate;
        NiMatrix3 kRot = kXform.m_Rotate;
        efd::Point3 kEuler;
        efd::Point3 kSeatRot(spModel->m_fRotX, spModel->m_fRotY, spModel->m_fRotZ);
        NiMatrix3 kSeat;
        FUN_140b86230(kSeatRot, kSeat);
        kRot = kRot * kSeat;
        FUN_140a0b1f0(kRot, &kEuler);
        efd::Point3 kX;
        FUN_140a01190(&kRot, 0, &kX);
        FUN_140968990(kX);
        efd::Point3 kY;
        FUN_140a01190(&kRot, 1, &kY);
        FUN_140968990(kY);
        efd::Point3 kZ;
        FUN_140a01190(&kRot, 2, &kZ);
        FUN_140968990(kZ);
        kPos = kPos + kY * -spModel->m_fY;
        kPos = kPos + kX * spModel->m_fX;
        kPos = kPos + kZ * spModel->m_fZ;
        FUN_140981070(pRoot, kPos);
        FUN_140ddcca0(pRoot, kRot);
        FUN_141d16210(pRoot);
        pRoot->UpdateProperties();
        FUN_141d16040(pRoot, (float)FUN_141473280(FUN_14086d260()), true);
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
