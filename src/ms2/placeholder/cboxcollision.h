// cboxcollision.h - CBoxCollision (RTTI name; 0x150 bytes, ctor 0x140ada4c0): the oriented-box collision shape (shape
// kind 1). NOT an original header; owning unit ?\boxcollision.cpp (0x140ada4c0-0x140ae2d20, not recovered yet), whose
// members are only declared here. Layout from ?\basecollision.cpp: the PhysX box at +0xb4 (NxBoxBoxIntersect,
// NxPointOBBSqrDist, NxSegmentOBBSqrDist read it) and its 8 corner points at +0xf0 (the min/max z scans).
// functioncubeobject.h keeps an older partial declaration of the same class (only +0x78 named).
#pragma once
#include <NxBox.h>
#include "ms2/placeholder/cbasecollision.h"

class CBoxCollision : public CBaseCollision
{
public:
    CBoxCollision();                                                // 0x140ada4c0
    virtual void vfunc_5();
    virtual float vfunc_6();
    int FUN_140adacb0(const Unk_StreamPoint& pt) const;             // the point is inside the box
    float FUN_140adad00() const;                                    // top: the largest corner z
    float FUN_140adad80() const;                                    // bottom: the smallest corner z

    Unk_StreamPoint m_ptBox;                                        // +0x78
    char m_pad_84[0xb4 - 0x84];
    NxBox m_kBox;                                                   // +0xb4 center, extents, rotation
    Unk_StreamPoint m_akCorners[8];                                 // +0xf0
};
MS2_CHECK_OFFSET(CBoxCollision, m_kBox, 0xb4);
MS2_CHECK_OFFSET(CBoxCollision, m_akCorners, 0xf0);
MS2_CHECK_SIZE(CBoxCollision, 0x150);
