// cameratargetboundingbox.h - CCameraTargetBounding (RTTI .?AVCCameraTargetBounding@@) and its three shapes
// CCameraTargetBoundingBox / Sphere / Cylinder: the volumes a camera target may roam in, initialised from a map entity's
// properties. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\cameratargetboundingbox.cpp`
// (0x140afef30-0x140b00540). Header name assumed; vfunc names are invented from their use.
//
// The box keeps PhysX (NxBounds3 / NxMat34 / NxBox) helper values from the boxcollision unit; their member functions live
// in the exe and are called through FUN_<va> functions.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"

namespace egf { class Entity; }

// NxVec3-like value (x, y, z); ctor(x, y, z) 0x140a00350, default ctor 0x140a003a0.
struct Unk_CtbVec3
{
    Unk_CtbVec3();                                      // 0x140a003a0
    Unk_CtbVec3(float fX, float fY, float fZ);          // 0x140a00350
    Unk_CtbVec3& FUN_140adbbc0(const Unk_CtbVec3& v);   // operator=
    Unk_CtbVec3 FUN_140adbd00(float f) const;           // operator*(float)
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_CtbVec3, 12);
// NxBounds3: min, max (ctor 0x140adb8f0 makes it empty, dtor 0x140adbb40).
struct Unk_CtbBounds3
{
    Unk_CtbBounds3();                                   // 0x140adb8f0
    ~Unk_CtbBounds3();                                  // 0x140adbb40
    Unk_CtbVec3 m_min;
    Unk_CtbVec3 m_max;
};
MS2_CHECK_SIZE(Unk_CtbBounds3, 0x18);
// 3x3 matrix, row-major (default ctor 0x140adb9d0 does nothing).
struct Unk_CtbMat33
{
    bool FUN_140afff50(Unk_CtbMat33* pOut) const;       // inverse (false when singular: the output is the identity)
    float m00, m01, m02;                                // rows
    float m10, m11, m12;
    float m20, m21, m22;
};
MS2_CHECK_SIZE(Unk_CtbMat33, 0x24);
// NxBox: centre, extents, rotation (ctor 0x140adb930, dtor 0x140adbb50).
struct Unk_CtbObb
{
    Unk_CtbObb();                                       // 0x140adb930
    ~Unk_CtbObb();                                      // 0x140adbb50
    Unk_CtbVec3 m_center;
    Unk_CtbVec3 m_extents;
    Unk_CtbMat33 m_rot;
};
MS2_CHECK_SIZE(Unk_CtbObb, 0x3c);
// NxMat34: rotation + translation (ctor(bool identity) 0x140adb9e0, dtor 0x140adbb80).
struct Unk_CtbMat34
{
    Unk_CtbMat34(bool bIdentity);                       // 0x140adb9e0
    ~Unk_CtbMat34();                                    // 0x140adbb80
    bool FUN_140b00260(Unk_CtbMat34* pOut) const;       // inverse
    Unk_CtbVec3 FUN_140adbcb0(const Unk_CtbVec3& v) const;   // pose * point
    Unk_CtbMat33 m_rot;
    Unk_CtbVec3 m_pos;
};
MS2_CHECK_SIZE(Unk_CtbMat34, 0x30);

// The shape base (vftable 0x142dd6ec8, 5 slots, deleting dtor 0x140affd40).
class CCameraTargetBounding : public CPtred
{
public:
    CCameraTargetBounding();                                            // 0x140affc90
    // @0x140affcc0
    virtual ~CCameraTargetBounding() = default;

    virtual int InitFromEntity(egf::Entity* pEntity) = 0;              // slot 1: read the size / position / rotation properties
    virtual int Contains(Vector3 pt) = 0;                      // slot 2
    virtual float GetDistance(const Vector3& pt);               // slot 3: distance to the shape (0 inside)
    virtual Vector3 GetClosest(const Vector3& pt) = 0;  // slot 4: the nearest point of the shape

    unsigned __int64 m_entityId;                                        // +0x18
};
MS2_CHECK_SIZE(CCameraTargetBounding, 0x20);
MS2_CHECK_OFFSET(CCameraTargetBounding, m_entityId, 0x18);

// 0xd8 bytes. vftable 0x142dd6ef8.
class CCameraTargetBoundingBox : public CCameraTargetBounding
{
public:
    CCameraTargetBoundingBox();                                         // 0x140afefe0
    virtual ~CCameraTargetBoundingBox();                                // 0x140aff070
    virtual int InitFromEntity(egf::Entity* pEntity);
    virtual int Contains(Vector3 pt);
    virtual Vector3 GetClosest(const Vector3& pt);

    Unk_CtbBounds3 m_bounds;                                            // +0x20 local box
    Unk_CtbObb m_obb;                                                   // +0x38 the box in world space
    Unk_CtbMat34 m_pose;                                                // +0x74
    Unk_CtbMat34 m_inverse;                                             // +0xa4
};
MS2_CHECK_SIZE(CCameraTargetBoundingBox, 0xd8);
MS2_CHECK_OFFSET(CCameraTargetBoundingBox, m_obb, 0x38);
MS2_CHECK_OFFSET(CCameraTargetBoundingBox, m_pose, 0x74);
MS2_CHECK_OFFSET(CCameraTargetBoundingBox, m_inverse, 0xa4);

// 0x30 bytes. vftable 0x142dd6f28.
class CCameraTargetBoundingSphere : public CCameraTargetBounding
{
public:
    CCameraTargetBoundingSphere();                                      // 0x140aff5b0
    virtual ~CCameraTargetBoundingSphere();                             // 0x140aff600
    virtual int InitFromEntity(egf::Entity* pEntity);
    virtual int Contains(Vector3 pt);
    virtual Vector3 GetClosest(const Vector3& pt);

    Vector3 m_center;                                           // +0x20
    float m_radius;                                                     // +0x2c
};
MS2_CHECK_SIZE(CCameraTargetBoundingSphere, 0x30);
MS2_CHECK_OFFSET(CCameraTargetBoundingSphere, m_radius, 0x2c);

// 0x38 bytes. vftable 0x142dd6f58.
class CCameraTargetBoundingCylinder : public CCameraTargetBounding
{
public:
    CCameraTargetBoundingCylinder();                                    // 0x140aff840
    virtual ~CCameraTargetBoundingCylinder();                           // 0x140aff890
    virtual int InitFromEntity(egf::Entity* pEntity);
    virtual int Contains(Vector3 pt);
    virtual Vector3 GetClosest(const Vector3& pt);

    Vector3 m_center;                                           // +0x20
    float m_radius;                                                     // +0x2c
    float m_halfHeight;                                                 // +0x30
};
MS2_CHECK_SIZE(CCameraTargetBoundingCylinder, 0x38);
MS2_CHECK_OFFSET(CCameraTargetBoundingCylinder, m_radius, 0x2c);
MS2_CHECK_OFFSET(CCameraTargetBoundingCylinder, m_halfHeight, 0x30);
