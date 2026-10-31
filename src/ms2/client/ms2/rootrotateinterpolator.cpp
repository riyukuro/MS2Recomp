// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See rootrotateinterpolator.h.
// MS2-UNIT: ?\rootrotateinterpolator.cpp
// MS2-RANGE: 0x1400d58b0-0x1400d58e0 .text$di
// MS2-RANGE: 0x140dc9b30-0x140dca0b0 .text$mn
// MS2-PIN: ??_GRootRotateInterpolator@@UEAAPEAXI@Z 0x140dca020
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\rootrotateinterpolator.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "rootrotateinterpolator.h"

#include <NiAVObject.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (unit-local views) ----
struct Unk_RrQuat { float v[4]; };
struct Unk_RrTransform { unsigned char m_rotate[0x24]; Unk_RrPoint3 m_translate; float m_fScale; };     // the NiTransform the target hands out
Unk_RrPoint3* FUN_14027dda0(Unk_RrPoint3* p, float x, float y, float z);
Unk_RrMatrix3* FUN_1409f7320(Unk_RrMatrix3* p);            // identity
extern const unsigned char DAT_143afa458[];                // NiRTTI of the target class
Unk_RrQuat* FUN_14209b8e0(Unk_RrQuat* p, float fAngle, Unk_RrPoint3* pAxis);   // efd::Quaternion(float, const Point3&) (was mislabelled 0x14098d000, an iterator ==)
Unk_RrMatrix3* FUN_140a34450(Unk_RrQuat* pQ, Unk_RrMatrix3* pOut);
Unk_RrMatrix3& FUN_140a33480(Unk_RrMatrix3& a, Unk_RrMatrix3* pOut, const Unk_RrMatrix3* b);   // a * b
void FUN_140a33240(Unk_RrMatrix3* pOut, const Unk_RrMatrix3& pSrc);
Unk_RrQuat* FUN_140a33310(Unk_RrQuat* p);
void FUN_140a33280(void* pOut, const Unk_RrQuat* pQ);
void FUN_140a333e0(NiQuatTransform* pDst, const NiQuatTransform* pSrc);
bool FUN_140552700(Unk_RrPoint3* a, Unk_RrPoint3* b);
void FUN_140194470(Unk_RrPoint3* pDst, const Unk_RrPoint3* pSrc);
void FUN_140a333b0(void* pThis);
void MakeXRotation(Unk_RrMatrix3* p, float fRad);
void MakeYRotation(Unk_RrMatrix3* p, float fRad);
void MakeZRotation(Unk_RrMatrix3* p, float fRad);

// @0x140dc9b30
RootRotateInterpolator::RootRotateInterpolator()
    : NiTransformInterpolator()
{
    FUN_14027dda0(&m_axis, 0, 0, 0);
    FUN_14027dda0(&m_rotation, 0, 0, 0);
    FUN_1409f7320(&m_matrix);
    m_bAlwaysUpdate = false;
    ((efd::Matrix3*)(struct Unk_RrMatrix3*)(&m_matrix))->MakeIdentity();
}

// @0x140dc9bd0
RootRotateInterpolator::RootRotateInterpolator(const void* pUnused)
    : NiTransformInterpolator()
{
    FUN_14027dda0(&m_axis, 0, 0, 0);
    FUN_14027dda0(&m_rotation, 0, 0, 0);
    FUN_1409f7320(&m_matrix);
    m_bAlwaysUpdate = true;
    ((efd::Matrix3*)(struct Unk_RrMatrix3*)(&m_matrix))->MakeIdentity();
}

// @0x140dc9c80
bool RootRotateInterpolator::Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue)
{
    void* pTarget = ((void*)NiObject::DynamicCast((class NiRTTI const*)(DAT_143afa458), (class NiObject const*)(pkInterpTarget)));
    if (pTarget != 0)
    {
        Unk_RrTransform kLocal = *((struct Unk_RrTransform*)&((class NiAVObject*)(void*)(pTarget))->GetLocalTransform());
        ((class NiQuatTransform*)(class NiQuatTransform*)(&m_kTransformValue))->SetTranslate(*(class NiPoint3 const*)(&kLocal.m_translate));
        ((class NiQuatTransform*)(class NiQuatTransform*)(&m_kTransformValue))->SetRotate(*(class NiMatrix3 const*)(&m_matrix));
        ((class NiQuatTransform*)(class NiQuatTransform*)(&m_kTransformValue))->SetScale(kLocal.m_fScale);
        Unk_RrQuat kAxisRot;
        FUN_14209b8e0(&kAxisRot, 1.0471976f, &m_axis);
        Unk_RrMatrix3 kRot;
        FUN_1409f7320(&kRot);
        FUN_140a34450(&kAxisRot, &kRot);
        Unk_RrMatrix3 kTemp, kMul;
        FUN_140a33240(&kMul, FUN_140a33480(kRot, &kTemp, &m_matrix));
        Unk_RrQuat kQuat;
        FUN_140a33310(&kQuat);
        ((efd::Quaternion*)(struct Unk_RrQuat*)(&kQuat))->FromRotation(*(class efd::Matrix3 const*)(&kMul));
        Unk_RrQuat kOut;      // NiQuaternion
        FUN_140a33280(&kOut, &kQuat);
        ((class NiQuatTransform*)(class NiQuatTransform*)(&m_kTransformValue))->SetRotate(*(class NiQuaternion const*)(&kOut));
        FUN_140a333e0(&kValue, &m_kTransformValue);
        return true;
    }
    return false;
}

// @0x140dc9e40
void RootRotateInterpolator::FUN_140dc9e40(Unk_RrPoint3* pRotation)
{
    if (FUN_140552700(&m_rotation, pRotation))
    {
        FUN_140194470(&m_rotation, pRotation);
        Unk_RrMatrix3 kX, kY, kZ;
        FUN_1409f7320(&kX);
        FUN_1409f7320(&kY);
        FUN_1409f7320(&kZ);
        MakeXRotation(&kX, pRotation->x * -0.017453292f);
        MakeYRotation(&kY, pRotation->y * -0.017453292f);
        MakeZRotation(&kZ, pRotation->z * -0.017453292f);
        Unk_RrMatrix3 kT1, kT2, kResult;
        FUN_140a33240(&kResult, FUN_140a33480(FUN_140a33480(kX, &kT1, &kY), &kT2, &kZ));
        m_matrix = kResult;
    }
}

// @0x140dc9fb0
void RootRotateInterpolator::FUN_140dc9fb0(const Unk_RrPoint3* pValue)
{
    m_axis.x = pValue->x;
    m_axis.y = pValue->y;
    m_axis.z = pValue->z;
}

// @0x140dca080
bool RootRotateInterpolator::AlwaysUpdate() const
{
    return m_bAlwaysUpdate;
}

const NiRTTI RootRotateInterpolator::ms_RTTI("RootRotateInterpolator", &NiTransformInterpolator::ms_RTTI);   // @0x1400d58b0
