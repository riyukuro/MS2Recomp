// cboxcollision.h - CBoxCollision (RTTI name; 0x150 bytes, ctor 0x140ada4c0, vftable 0x142dd4fd8): the oriented-box
// collision shape (shape kind 1), built with the PhysX 2.8 foundation types: the local bounds from the box size, the
// world NxBox (NxCreateBox) and its 8 corner points (NxComputeBoxPoints). NOT an original header (name assumed);
// owning unit ?\boxcollision.cpp (0x140ada4c0-0x140add560). Member names are invented from use.
#pragma once
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxVec3.h>
#include <NxBounds3.h>
#include <NxBox.h>
#pragma pop_macro("max")
#pragma pop_macro("min")
#include "ms2/placeholder/cbasecollision.h"

class CBoxCollision : public CBaseCollision
{
public:
    CBoxCollision();                                                // 0x140ada4c0
    virtual ~CBoxCollision();                                       // 0x140ada5a0
    virtual void vfunc_2(Vector3 ptPos, const NiMatrix3& kRot, float fScale);   // 0x140ada910 place by a matrix
    virtual void vfunc_3(Vector3 ptPos, Vector3 ptDir, float fScale);   // 0x140ada620 place by angles
    virtual void vfunc_4();                                         // 0x140adab30 the local bounds from the size
    virtual void vfunc_5();                                         // 0x140adae20 the 16-point wire mesh
    virtual float vfunc_6();                                        // 0x140adae00 the height (m_ptBox.z)
    int FUN_140adac70(const NxVec3& pt) const;                      // the point is inside the box
    int FUN_140adacb0(const Vector3& pt) const;             // the same for a game point
    float FUN_140adad00() const;                                    // top: the largest corner z
    float FUN_140adad80() const;                                    // bottom: the smallest corner z

    Vector3 m_ptBox;                                        // +0x78 size: length (x, centred), width, height
    Vector3 m_ptMin;                                        // +0x84 local bounds
    Vector3 m_ptMax;                                        // +0x90
    NxBounds3 m_kBounds;                                            // +0x9c
    NxBox m_kBox;                                                   // +0xb4 center, extents, rotation
    NxVec3 m_akCorners[8];                                          // +0xf0
};
MS2_CHECK_OFFSET(CBoxCollision, m_ptBox, 0x78);
MS2_CHECK_OFFSET(CBoxCollision, m_kBounds, 0x9c);
MS2_CHECK_OFFSET(CBoxCollision, m_kBox, 0xb4);
MS2_CHECK_OFFSET(CBoxCollision, m_akCorners, 0xf0);
MS2_CHECK_SIZE(CBoxCollision, 0x150);
