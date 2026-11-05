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
struct Unk_RrTransform { unsigned char m_rotate[0x24]; efd::Point3 m_translate; float m_fScale; };     // the NiTransform the target hands out
// C3: 14027dda0 is efd::Point3::Point3(float, float, float)
efd::Matrix3* FUN_1409f7320(efd::Matrix3* p);            // identity
// C3: 140552700 is efd::Point3::operator!=
// C3: 140194470 is efd::Point3::operator=
void FUN_140a333b0(void* pThis);

// @0x140dc9b30
RootRotateInterpolator::RootRotateInterpolator()
    : NiTransformInterpolator()
    , m_axis(0, 0, 0)
    , m_rotation(0, 0, 0)
{
    FUN_1409f7320((efd::Matrix3*)&m_matrix);
    m_bAlwaysUpdate = false;
    ((efd::Matrix3*)(struct Unk_RrMatrix3*)(&m_matrix))->MakeIdentity();
}

// @0x140dc9bd0
RootRotateInterpolator::RootRotateInterpolator(const void* pUnused)
    : NiTransformInterpolator()
    , m_axis(0, 0, 0)
    , m_rotation(0, 0, 0)
{
    FUN_1409f7320((efd::Matrix3*)&m_matrix);
    m_bAlwaysUpdate = true;
    ((efd::Matrix3*)(struct Unk_RrMatrix3*)(&m_matrix))->MakeIdentity();
}

// @0x140dc9c80
bool RootRotateInterpolator::Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue)
{
    void* pTarget = ((void*)NiObject::DynamicCast(&NiAVObject::ms_RTTI, (class NiObject const*)(pkInterpTarget)));
    if (pTarget != 0)
    {
        Unk_RrTransform kLocal = *((struct Unk_RrTransform*)&((class NiAVObject*)(void*)(pTarget))->GetLocalTransform());
        ((class NiQuatTransform*)(class NiQuatTransform*)(&m_kTransformValue))->SetTranslate(*(class NiPoint3 const*)(&kLocal.m_translate));
        ((class NiQuatTransform*)(class NiQuatTransform*)(&m_kTransformValue))->SetRotate(*(class NiMatrix3 const*)(&m_matrix));
        ((class NiQuatTransform*)(class NiQuatTransform*)(&m_kTransformValue))->SetScale(kLocal.m_fScale);
        efd::Quaternion kAxisRot(1.0471976f, m_axis);
        Unk_RrMatrix3 kRot;
        FUN_1409f7320((efd::Matrix3*)&kRot);
        kAxisRot.ToRotation(*(efd::Matrix3*)&kRot);
        NiMatrix3 kMul(*(efd::Matrix3*)&kRot * *(efd::Matrix3*)&m_matrix);
        efd::Quaternion kQuat;
        kQuat.FromRotation(*(class efd::Matrix3 const*)(&kMul));
        NiQuaternion kOut(kQuat);
        ((class NiQuatTransform*)(class NiQuatTransform*)(&m_kTransformValue))->SetRotate(*(class NiQuaternion const*)(&kOut));
        kValue = m_kTransformValue;
        return true;
    }
    return false;
}

// @0x140dc9e40
void RootRotateInterpolator::FUN_140dc9e40(efd::Point3* pRotation)
{
    if (m_rotation != *pRotation)
    {
        m_rotation = *pRotation;
        Unk_RrMatrix3 kX, kY, kZ;
        FUN_1409f7320((efd::Matrix3*)&kX);
        FUN_1409f7320((efd::Matrix3*)&kY);
        FUN_1409f7320((efd::Matrix3*)&kZ);
        ((efd::Matrix3*)&kX)->MakeXRotation(pRotation->x * -0.017453292f);
        ((efd::Matrix3*)&kY)->MakeYRotation(pRotation->y * -0.017453292f);
        ((efd::Matrix3*)&kZ)->MakeZRotation(pRotation->z * -0.017453292f);
        NiMatrix3 kResult(*(efd::Matrix3*)&kX * *(efd::Matrix3*)&kY * *(efd::Matrix3*)&kZ);
        m_matrix = *(Unk_RrMatrix3*)&kResult;
    }
}

// @0x140dc9fb0
void RootRotateInterpolator::SetAxis(const efd::Point3* pValue)
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
