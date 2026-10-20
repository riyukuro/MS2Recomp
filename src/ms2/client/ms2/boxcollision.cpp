// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBoxCollision: the oriented-box collision shape. The box
// size gives local bounds (centred on x), which are scaled, posed by a position + angles (vfunc_3) or a rotation matrix
// (vfunc_2) into a PhysX NxBox, whose 8 corners feed the inside / top / bottom tests and a 16-point wire mesh.
// The tail of the unit (0x140adb820-0x140add560) is the PhysX foundation / Gamebryo inline COMDATs it instantiates.
// File name assumed (no __FILE__ string); followed in the exe by the CBreakableObject unit (?\breakableobject.cpp).
// MS2-UNIT: ?\boxcollision.cpp
// MS2-RANGE: 0x140ada4c0-0x140add560 .text$mn
// MS2-PIN: ?RemoveAllStreamRefs@NiMesh@@QEAAXXZ 0x140adc720
// MS2-PIN: memcpy_s 0x140add440
#define NOMINMAX
#define MS2_THIS_FILE ""
// The exe's memcpy_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memcpy)
#include "ms2/placeholder/ms2stdafx.h"
#include <math.h>
// NxMath::cos / sin (NxMat33::rotX / rotZ) call the CRT through the exe's IAT.
extern "C" float (__cdecl* __imp_cosf)(float);
extern "C" float (__cdecl* __imp_sinf)(float);
#define cosf(x) __imp_cosf(x)
#define sinf(x) __imp_sinf(x)
#include <NiMesh.h>
#include <NiDataStreamElementLock.h>
#include <NiCommonSemantics.h>
#include <NxPhysics.h>
#include <NiPhysXTypes.h>
#include <efd/Point3.h>
#include "ms2/placeholder/cboxcollision.h"
#include "hook/ms2hook.h"

NxVec3 FUN_141b6e0e0(const efd::Point3& v);                         // efd::Point3 -> NxVec3

// @0x140ada4c0
CBoxCollision::CBoxCollision() : m_ptBox(0.0f, 0.0f, 0.0f)
{
    m_nShape = 1;
}

// @0x140ada5a0
CBoxCollision::~CBoxCollision()
{
    m_spMesh = 0;
}

// @0x140ada620
void CBoxCollision::vfunc_3(Unk_StreamPoint ptPos, Unk_StreamPoint ptDir, float fScale)
{
    NxMat34 kPose(true);
    kPose.t.x = ptPos.x;
    kPose.t.y = ptPos.y;
    kPose.t.z = ptPos.z;
    kPose.M.id();
    kPose.M.rotZ(ptDir.z * 3.1415927f / 180.0f);
    if ((ptDir.x > -1.1920929e-07f && ptDir.x < 1.1920929e-07f) == 0)
    {
        NxMat33 kRotX(NX_IDENTITY_MATRIX);
        kRotX.rotX(ptDir.x * 3.1415927f / 180.0f);
        kPose.M.multiply(kPose.M, kRotX);
    }
    vfunc_4();
    m_kBounds.scale(fScale);
    NxCreateBox(m_kBox, m_kBounds, kPose);
    NxVec3 kCenter;
    m_kBounds.getCenter(kCenter);
    kCenter.y = -kCenter.y;
    kCenter += FUN_141b6e0e0(reinterpret_cast<const efd::Point3&>(m_ptDir));
    kCenter *= fScale;
    kCenter = kPose * kCenter;
    m_kBox.center = kCenter;
    NxComputeBoxPoints(m_kBox, m_akCorners);
    CBaseCollision::vfunc_3(ptPos, ptDir, fScale);
}
MS2_REPLACE_METHOD(0x140ADA620, CBoxCollision, vfunc_3, 746, 0x68FFF7F0);

// @0x140ada910
void CBoxCollision::vfunc_2(Unk_StreamPoint ptPos, const NiMatrix3& kRot, float fScale)
{
    NxMat34 kPose(true);
    kPose.t.x = ptPos.x;
    kPose.t.y = ptPos.y;
    kPose.t.z = ptPos.z;
    kPose.M.id();
    NiPhysXTypes::NiMatrix3ToNxMat33(kRot, kPose.M);
    vfunc_4();
    m_kBounds.scale(fScale);
    NxCreateBox(m_kBox, m_kBounds, kPose);
    NxVec3 kCenter;
    m_kBounds.getCenter(kCenter);
    kCenter.y = -kCenter.y;
    kCenter += FUN_141b6e0e0(reinterpret_cast<const efd::Point3&>(m_ptDir));
    kCenter *= fScale;
    kCenter = kPose * kCenter;
    m_kBox.center = kCenter;
    NxComputeBoxPoints(m_kBox, m_akCorners);
    CBaseCollision::vfunc_2(ptPos, kRot, fScale);
}
MS2_REPLACE_METHOD(0x140ADA910, CBoxCollision, vfunc_2, 529, 0xAAF2271F);

// @0x140adab30
void CBoxCollision::vfunc_4()
{
    m_ptMin = Unk_StreamPoint(-m_ptBox.x / 2.0f, -m_ptSize.y, -m_ptSize.z);
    m_ptMax = Unk_StreamPoint(m_ptBox.x / 2.0f, m_ptBox.y, m_ptBox.z);
    m_kBounds.set(m_ptMin.x, m_ptMin.y, m_ptMin.z, m_ptMax.x, m_ptMax.y, m_ptMax.z);
}
MS2_REPLACE_METHOD(0x140ADAB30, CBoxCollision, vfunc_4, 313, 0x78BA12DE);

// @0x140adac70
int CBoxCollision::FUN_140adac70(const NxVec3& pt) const
{
    return NxBoxContainsPoint(m_kBox, pt);
}
MS2_REPLACE_METHOD(0x140ADAC70, CBoxCollision, FUN_140adac70, 46, 0xEB1EFC06);

// @0x140adacb0
int CBoxCollision::FUN_140adacb0(const Unk_StreamPoint& pt) const
{
    return FUN_140adac70(NxVec3(pt.x, pt.y, pt.z));
}
MS2_REPLACE_METHOD(0x140ADACB0, CBoxCollision, FUN_140adacb0, 71, 0x2694CF4D);

// @0x140adad00
float CBoxCollision::FUN_140adad00() const
{
    float fMax = -3.402823466e+38f;
    for (int i = 0; i < 8; i++)
    {
        if (fMax < m_akCorners[i].z)
            fMax = m_akCorners[i].z;
    }
    return fMax;
}
MS2_REPLACE_METHOD(0x140ADAD00, CBoxCollision, FUN_140adad00, 116, 0xD916356F);

// @0x140adad80
float CBoxCollision::FUN_140adad80() const
{
    float fMin = 3.402823466e+38f;
    for (int i = 0; i < 8; i++)
    {
        if (m_akCorners[i].z < fMin)
            fMin = m_akCorners[i].z;
    }
    return fMin;
}
MS2_REPLACE_METHOD(0x140ADAD80, CBoxCollision, FUN_140adad80, 116, 0x4230D01D);

// @0x140adae00
float CBoxCollision::vfunc_6()
{
    return m_ptBox.z;
}
MS2_REPLACE_METHOD(0x140ADAE00, CBoxCollision, vfunc_6, 19, 0xC69F9DE8);

// @0x140adae20
void CBoxCollision::vfunc_5()
{
    m_bBuilt = 1;
    m_spMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    m_spMesh->RemoveAllStreamRefs();

    const int nPts = 16;
    Unk_StreamPoint aPts[nPts];
    aPts[0] = Unk_StreamPoint(m_akCorners[0].x, m_akCorners[0].y, m_akCorners[0].z);
    aPts[1] = Unk_StreamPoint(m_akCorners[3].x, m_akCorners[3].y, m_akCorners[3].z);
    aPts[2] = Unk_StreamPoint(m_akCorners[2].x, m_akCorners[2].y, m_akCorners[2].z);
    aPts[3] = Unk_StreamPoint(m_akCorners[1].x, m_akCorners[1].y, m_akCorners[1].z);
    aPts[4] = Unk_StreamPoint(m_akCorners[0].x, m_akCorners[0].y, m_akCorners[0].z);
    aPts[5] = Unk_StreamPoint(m_akCorners[4].x, m_akCorners[4].y, m_akCorners[4].z);
    aPts[6] = Unk_StreamPoint(m_akCorners[7].x, m_akCorners[7].y, m_akCorners[7].z);
    aPts[7] = Unk_StreamPoint(m_akCorners[6].x, m_akCorners[6].y, m_akCorners[6].z);
    aPts[8] = Unk_StreamPoint(m_akCorners[5].x, m_akCorners[5].y, m_akCorners[5].z);
    aPts[9] = Unk_StreamPoint(m_akCorners[4].x, m_akCorners[4].y, m_akCorners[4].z);
    aPts[10] = Unk_StreamPoint(m_akCorners[5].x, m_akCorners[5].y, m_akCorners[5].z);
    aPts[11] = Unk_StreamPoint(m_akCorners[1].x, m_akCorners[1].y, m_akCorners[1].z);
    aPts[12] = Unk_StreamPoint(m_akCorners[2].x, m_akCorners[2].y, m_akCorners[2].z);
    aPts[13] = Unk_StreamPoint(m_akCorners[6].x, m_akCorners[6].y, m_akCorners[6].z);
    aPts[14] = Unk_StreamPoint(m_akCorners[7].x, m_akCorners[7].y, m_akCorners[7].z);
    aPts[15] = Unk_StreamPoint(m_akCorners[3].x, m_akCorners[3].y, m_akCorners[3].z);

    m_spMesh->AddStream(NiCommonSemantics::POSITION(), 0, NiDataStreamElement::F_FLOAT32_3, 16, 0x13,
                        NiDataStream::USAGE_VERTEX, aPts, false, true);
    NiDataStreamElementLock kLock = m_spMesh->AddStreamGetLock(NiCommonSemantics::COLOR(), 0,
        NiDataStreamElement::F_FLOAT32_4, 16, 0x12, NiDataStream::USAGE_VERTEX, false, true, 2);
    NiTStridedRandomAccessIterator<NiColorA> it = kLock.begin<NiColorA>(0);
    for (int i = 0; i < 16; i++)
        it[i] = m_kColor;
    kLock.Unlock();
    m_spMesh->Update(0.0f, true);
    m_spMesh->UpdateProperties();
    m_spMesh->UpdateEffects();
    m_spMesh->UpdateNodeBound();
    m_spMesh->SetSelectiveUpdate(true);
}
MS2_REPLACE_METHOD(0x140ADAE20, CBoxCollision, vfunc_5, 2545, 0xD923878B);

// The UCRT's `static __inline memcpy_s` of this TU (0x140add440, no caller left in the exe; kept alive by the pointer below).
// MS2-FUNCTIONAL memcpy_s: CRT memcpy_s copy: source spelling may differ
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnBoxCollisionMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
