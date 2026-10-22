// frustumcollision.h - CFrustumCollision (RTTI name): a truncated-pyramid (view frustum) collision volume that is
// drawn as one 16-point wire mesh. Derives from CBaseCollision (ms2/placeholder/cbasecollision.h). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names are invented from use.
// Unit: ?\frustumcollision.cpp (0x141222df0-0x141225080); vftable 0x142ec3fb8.
#pragma once
#include <NiPoint2.h>
#include "ms2/placeholder/cbasecollision.h"
#include "ms2/placeholder/nipoint3.h"

// efd::Point3 with the default constructor 0x1405522f0 (another obj); assigned from a NiPoint3 conversion temporary.
struct Unk_FcPoint3
{
    Unk_FcPoint3();                                         // 0x1405522f0
    Unk_FcPoint3& operator=(const Unk_NiPoint3& pt);        // 0x14097faa0
    float FUN_140968990();                                  // efd::Point3::Unitize (returns the old length)
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_FcPoint3, 12);

// An NxVec3-like triple with the default constructor 0x140a003a0 (the corner points of an oriented box).
struct Unk_FcNxVec3
{
    Unk_FcNxVec3();                                         // 0x140a003a0
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_FcNxVec3, 12);

class CFrustumCollision : public CBaseCollision
{
public:
    CFrustumCollision();                                    // 0x141222df0
    virtual ~CFrustumCollision();                           // 0x141222f20
    virtual void vfunc_3(Vector3 ptPos, Vector3 ptDir, float fScale);   // 0x141222f50 builds the corners
    virtual void vfunc_4();                                 // 0x141223bc0 derives the cone angles
    virtual void vfunc_5();                                 // 0x141224920 builds the wire mesh
    virtual float vfunc_6();                                // 0x141224800

    int Contains(const Vector3& pt) const;          // 0x141223d30
    int ContainsPoint(const Vector3& pt) const;     // 0x141223d80
    int IntersectsBox(const void* pBox) const;              // 0x141223e70 (pBox: the NxBox of a box collision)
    int SegmentIntersect(const NiPoint2* pA1, const NiPoint2* pA2, const NiPoint2* pB1, const NiPoint2* pB2,
                         NiPoint2* pOut) const;             // 0x1412245a0
    float GetMaxZ() const;                                  // 0x141224820
    float GetMinZ() const;                                  // 0x1412248a0

    MS2_LAYOUT_FRIEND;
    float m_fNearHalfWidth;             // +0x78
    float m_fHeight;                    // +0x7c (half height; the volume is twice as tall)
    float m_fFarHalfWidth;              // +0x80
    float m_fDepth;                     // +0x84
    Vector3 m_aCorners[8];      // +0x88 near bottom/top corners, then the far ones (z = the vertical axis)
    Vector3 m_ptRight;          // +0xe8
    Vector3 m_ptForward;        // +0xf4
    float m_fHalfAngle;                 // +0x100
    float m_fVertAngle;                 // +0x104
    float m_fTan;                       // +0x108
    float m_fApexDist;                  // +0x10c distance from the near plane back to the cone apex
    Vector3 m_ptOrigin;         // +0x110
    Vector3 m_ptApex;           // +0x11c
    Unk_FcPoint3 m_aEdgeA[3];           // +0x128 apex and the two far corners of the first side face
    Unk_FcPoint3 m_aEdgeB[3];           // +0x14c apex and the two far corners of the second side face
    NiPoint2 m_akEdge2[4];              // +0x170 the two side edges projected onto the ground plane (pairs)
};
MS2_CHECK_SIZE(CFrustumCollision, 0x190);
MS2_CHECK_OFFSET(CFrustumCollision, m_aCorners, 0x88);
MS2_CHECK_OFFSET(CFrustumCollision, m_ptRight, 0xe8);
MS2_CHECK_OFFSET(CFrustumCollision, m_ptOrigin, 0x110);
MS2_CHECK_OFFSET(CFrustumCollision, m_aEdgeA, 0x128);
MS2_CHECK_OFFSET(CFrustumCollision, m_aEdgeB, 0x14c);
MS2_CHECK_OFFSET(CFrustumCollision, m_akEdge2, 0x170);
