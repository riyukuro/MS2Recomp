// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See cameratargetboundingbox.h.
// MS2-UNIT: ?\cameratargetboundingbox.cpp
// MS2-RANGE: 0x140afef30-0x140b00540 .text$mn
// MS2-PIN: memcpy_s 0x140b002d0
// MS2-PIN: memmove_s 0x140b00420
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cameratargetboundingbox.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "cameratargetboundingbox.h"
#include "targetlookcentercameramode.h"

#include <egf/Entity.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----

int FUN_1409618c0(egf::Entity* pEntity, unsigned uPropId, Vector3* pOut);   // read a Point3 property (0 = ok)
float FUN_140968970(float f);                                                       // sqrtf

void FUN_140add1a0(Unk_CtbBounds3* pSelf, float x0, float y0, float z0, float x1, float y1, float z1);   // set
void FUN_140adca00(Unk_CtbMat33* pSelf);                                            // identity
void FUN_140add040(Unk_CtbMat33* pSelf, float fAngle);                              // rotation about z
void FUN_140adc690(Unk_CtbObb* pOut, const Unk_CtbBounds3* pBounds, const Unk_CtbMat34* pPose);   // NxBox from bounds + pose
bool FUN_140adc610(const Unk_CtbObb* pObb, const Unk_CtbVec3& pt);                 // point inside the box
void FUN_140adcdd0(const Unk_CtbMat33* pMat, const Unk_CtbVec3& vec, Unk_CtbVec3* pOut);   // pOut = mat * vec

// @0x140afef30
float CCameraTargetBounding::GetDistance(const Vector3& pt)
{
    if (Contains(pt))
        return 0.0f;
    Vector3 ptClosest = GetClosest(pt);
    float fDist = ptClosest.FUN_140965c40(pt).FUN_140967ac0();
    return fDist;
}
MS2_REPLACE_METHOD(0x140AFEF30, CCameraTargetBounding, GetDistance, 160, 0x5191A643);

// @0x140afefe0
CCameraTargetBoundingBox::CCameraTargetBoundingBox()
    : m_pose(true), m_inverse(true)
{
}

// @0x140aff070
CCameraTargetBoundingBox::~CCameraTargetBoundingBox()
{
}

// @0x140aff0f0
int CCameraTargetBoundingBox::InitFromEntity(egf::Entity* pEntity)
{
    Vector3 ptPos;
    Vector3 ptRot;
    Vector3 ptSize;
    if (FUN_1409618c0(pEntity, 0x9dc22aea, &ptSize) != 0)
        return 0;
    if (FUN_1409618c0(pEntity, 0xfd95ca52, &ptPos) != 0)
        return 0;
    if (FUN_1409618c0(pEntity, 0x68c7c29d, &ptRot) != 0)
        return 0;
    m_entityId = pEntity->GetEntityIDValue();
    Vector3 ptHalf = ptSize.FUN_14097fc90(0.5f);
    FUN_140add1a0(&m_bounds, -ptHalf.x, -ptHalf.y, -ptHalf.z, ptHalf.x, ptHalf.y, ptHalf.z);
    m_pose.m_pos.x = ptPos.x;
    m_pose.m_pos.y = ptPos.y;
    m_pose.m_pos.z = ptPos.z;
    FUN_140adca00(&m_pose.m_rot);
    FUN_140add040(&m_pose.m_rot, (ptRot.z * 3.1415927f) / 180.0f);
    m_pose.FUN_140b00260(&m_inverse);
    FUN_140adc690(&m_obb, &m_bounds, &m_pose);
    return 1;
}
MS2_REPLACE_METHOD(0x140AFF0F0, CCameraTargetBoundingBox, InitFromEntity, 560, 0x6AA13F9C);

// @0x140aff330
int CCameraTargetBoundingBox::Contains(Vector3 pt)
{
    return FUN_140adc610(&m_obb, Unk_CtbVec3(pt.x, pt.y, pt.z)) != 0;
}
MS2_REPLACE_METHOD(0x140AFF330, CCameraTargetBoundingBox, Contains, 104, 0xFF706066);

// @0x140aff3a0
Vector3 CCameraTargetBoundingBox::GetClosest(const Vector3& pt)
{
    if (Contains(pt))
        return pt;
    Unk_CtbVec3 vWorld(pt.x, pt.y, pt.z);
    Unk_CtbVec3 vLocal = m_inverse.FUN_140adbcb0(vWorld);
    if (vLocal.x < m_bounds.m_min.x)
        vLocal.x = m_bounds.m_min.x;
    if (vLocal.x > m_bounds.m_max.x)
        vLocal.x = m_bounds.m_max.x;
    if (vLocal.y < m_bounds.m_min.y)
        vLocal.y = m_bounds.m_min.y;
    if (vLocal.y > m_bounds.m_max.y)
        vLocal.y = m_bounds.m_max.y;
    if (vLocal.z < m_bounds.m_min.z)
        vLocal.z = m_bounds.m_min.z;
    if (vLocal.z > m_bounds.m_max.z)
        vLocal.z = m_bounds.m_max.z;
    vWorld.FUN_140adbbc0(m_pose.FUN_140adbcb0(vLocal));
    return Vector3(vWorld.x, vWorld.y, vWorld.z);
}
MS2_REPLACE_METHOD(0x140AFF3A0, CCameraTargetBoundingBox, GetClosest, 514, 0x1D624BCD);

// @0x140aff5b0
CCameraTargetBoundingSphere::CCameraTargetBoundingSphere()
{
}

// @0x140aff600
CCameraTargetBoundingSphere::~CCameraTargetBoundingSphere()
{
}

// @0x140aff630
int CCameraTargetBoundingSphere::InitFromEntity(egf::Entity* pEntity)
{
    Vector3 ptSize;
    if (FUN_1409618c0(pEntity, 0x9dc22aea, &ptSize) != 0)
        return 0;
    if (FUN_1409618c0(pEntity, 0xfd95ca52, &m_center) != 0)
        return 0;
    m_entityId = pEntity->GetEntityIDValue();
    m_radius = ptSize.x * 0.5f;
    return 1;
}
MS2_REPLACE_METHOD(0x140AFF630, CCameraTargetBoundingSphere, InitFromEntity, 140, 0xD967970C);

// @0x140aff6d0
int CCameraTargetBoundingSphere::Contains(Vector3 pt)
{
    if (pt.FUN_140965c40(m_center).FUN_140967ac0() < m_radius)
        return 1;
    else
        return 0;
}
MS2_REPLACE_METHOD(0x140AFF6D0, CCameraTargetBoundingSphere, Contains, 74, 0x4D191DD8);

// @0x140aff730
Vector3 CCameraTargetBoundingSphere::GetClosest(const Vector3& pt)
{
    if (Contains(pt))
        return pt;
    Vector3 ptDir = pt.FUN_140965c40(m_center);
    ptDir.FUN_140968990();
    Vector3 ptNear = m_center.FUN_14097fd50(ptDir.FUN_14097fc90(m_radius));
    return Vector3(ptNear.x, ptNear.y, ptNear.z);
}
MS2_REPLACE_METHOD(0x140AFF730, CCameraTargetBoundingSphere, GetClosest, 253, 0x1DF3CA6D);

// @0x140aff840
CCameraTargetBoundingCylinder::CCameraTargetBoundingCylinder()
{
}

// @0x140aff890
CCameraTargetBoundingCylinder::~CCameraTargetBoundingCylinder()
{
}

// @0x140aff8c0
int CCameraTargetBoundingCylinder::InitFromEntity(egf::Entity* pEntity)
{
    Vector3 ptSize;
    if (FUN_1409618c0(pEntity, 0x9dc22aea, &ptSize) != 0)
        return 0;
    if (FUN_1409618c0(pEntity, 0xfd95ca52, &m_center) != 0)
        return 0;
    m_entityId = pEntity->GetEntityIDValue();
    m_radius = ptSize.x * 0.5f;
    m_halfHeight = ptSize.z * 0.5f;
    return 1;
}
MS2_REPLACE_METHOD(0x140AFF8C0, CCameraTargetBoundingCylinder, InitFromEntity, 164, 0x316AC71E);

// @0x140aff970
int CCameraTargetBoundingCylinder::Contains(Vector3 pt)
{
    if (m_center.z + m_halfHeight < pt.z || pt.z < m_center.z - m_halfHeight)
        return false;
    float fDx = pt.x - m_center.x;
    float fDy = pt.y - m_center.y;
    if (fDx * fDx + fDy * fDy > m_radius * m_radius)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140AFF970, CCameraTargetBoundingCylinder, Contains, 195, 0x7580B175);

// @0x140affa40
Vector3 CCameraTargetBoundingCylinder::GetClosest(const Vector3& pt)
{
    if (Contains(pt))
        return pt;
    Vector3 ptNear = pt;
    float fDx = pt.x - m_center.x;
    float fDy = pt.y - m_center.y;
    if (fDx * fDx + fDy * fDy > m_radius * m_radius)
    {
        Unk_Point2 ptDir(pt.x - m_center.x, pt.y - m_center.y);
        ptDir.FUN_140affeb0();
        Unk_Point2 ptEdge = ptDir.FUN_140affce0(m_radius);
        ptNear.x = m_center.x + ptEdge.x;
        ptNear.y = m_center.y + ptEdge.y;
    }
    if (ptNear.z < m_center.z - m_halfHeight)
        ptNear.z = m_center.z - m_halfHeight;
    if (ptNear.z > m_center.z + m_halfHeight)
        ptNear.z = m_center.z + m_halfHeight;
    return ptNear;
}
MS2_REPLACE_METHOD(0x140AFFA40, CCameraTargetBoundingCylinder, GetClosest, 588, 0xE7A8C72B);

// @0x140affc90
CCameraTargetBounding::CCameraTargetBounding()
{
}

// @0x140affce0
Unk_Point2 Unk_Point2::FUN_140affce0(float f) const
{
    Unk_Point2 r = *this;
    r.x = r.x * f;
    r.y = r.y * f;
    return r;
}

// @0x140affe70
float Unk_Point2::FUN_140affe70() const
{
    return FUN_140968970(x * x + y * y);
}

// @0x140affeb0
float Unk_Point2::FUN_140affeb0()
{
    float fLen = FUN_140affe70();
    if (fLen > 1.0e-6f)
    {
        float fInv = 1.0f / fLen;
        x = x * fInv;
        y = y * fInv;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        fLen = 0.0f;
    }
    return fLen;
}

// @0x140afff50
bool Unk_CtbMat33::FUN_140afff50(Unk_CtbMat33* pOut) const
{
    float c0 = m11 * m22 - m12 * m21;
    float c1 = m02 * m21 - m01 * m22;
    float c2 = m01 * m12 - m02 * m11;
    float c3 = m12 * m20 - m10 * m22;
    float c4 = m00 * m22 - m02 * m20;
    float c5 = m02 * m10 - m00 * m12;
    float c6 = m10 * m21 - m11 * m20;
    float c7 = m01 * m20 - m00 * m21;
    float c8 = m00 * m11 - m01 * m10;
    float fDet = c0 * m00 + c1 * m10 + c2 * m20;
    if (fDet == 0.0f)
    {
        FUN_140adca00(pOut);
        return false;
    }
    fDet = 1.0f / fDet;
    pOut->m00 = c0 * fDet;
    pOut->m01 = c1 * fDet;
    pOut->m02 = c2 * fDet;
    pOut->m10 = c3 * fDet;
    pOut->m11 = c4 * fDet;
    pOut->m12 = c5 * fDet;
    pOut->m20 = c6 * fDet;
    pOut->m21 = c7 * fDet;
    pOut->m22 = c8 * fDet;
    return true;
}

// @0x140b00260
bool Unk_CtbMat34::FUN_140b00260(Unk_CtbMat34* pOut) const
{
    bool bOk = m_rot.FUN_140afff50(&pOut->m_rot);
    FUN_140adcdd0(&pOut->m_rot, m_pos.FUN_140adbd00(-1.0f), &pOut->m_pos);
    return bOk;
}

// The exe's CRT memcpy_s / memmove_s copies close the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_ctbMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
__declspec(selectany) extern errno_t(__cdecl* const ms2_ctbMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140affe70, Unk_Point2, FUN_140affe70, 61, 0x39BB8533);
MS2_REPLACE_METHOD(0x140affeb0, Unk_Point2, FUN_140affeb0, 157, 0xABEDF44D);
MS2_REPLACE_METHOD(0x140afff50, Unk_CtbMat33, FUN_140afff50, 777, 0xB05E510B);
MS2_REPLACE_METHOD(0x140b00260, Unk_CtbMat34, FUN_140b00260, 108, 0xB288BF53);

