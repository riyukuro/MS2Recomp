// holecylindercollision.h - CHoleCylinderCollision (RTTI name): a ring-shaped (hollow cylinder) collision volume with
// an inner and an outer radius, drawn as six wire meshes. Header name assumed. Member names are invented from use.
// Derives from CBaseCollision (ms2/placeholder/cbasecollision.h); vftable 0x142e255c8.
#pragma once
#include "ms2/placeholder/cbasecollision.h"

class CHoleCylinderCollision : public CBaseCollision
{
public:
    CHoleCylinderCollision();                                       // 0x140d03650
    virtual ~CHoleCylinderCollision();                              // 0x140d03780
    virtual void vfunc_1();                                         // 0x140d05650
    virtual void vfunc_3(Vector3 ptPos, Vector3 ptDir, float fScale);   // 0x140d03840
    virtual void vfunc_5();                                         // 0x140d03a60
    virtual float vfunc_6();                                          // 0x140d038d0

    float GetTop() const;                                           // 0x140d038f0 (inline)
    float GetBottom() const;                                        // 0x140d03920 (inline)
    int Contains(const Vector3& pt) const;                 // 0x140d03950
    int ContainsPoint(const Vector3& pt) const;                   // 0x140d039a0

private:
    void BuildWire(NiMesh* pMesh, const Vector3* pPoints, unsigned int nCount);   // 0x140d056f0

    MS2_LAYOUT_FRIEND;
    friend class CBaseCollision;        // the detect/intersect shape tests read the ring geometry
    NiMeshPtr m_spInnerTop;             // +0x78 inner ring at the top (m_spMesh is the outer ring at the center)
    NiMeshPtr m_spInnerBottom;          // +0x80
    NiMeshPtr m_spOuterTop;             // +0x88
    NiMeshPtr m_spOuterBottom;          // +0x90
    NiMeshPtr m_spLines;                // +0x98 the 24 edge lines
    NiMeshPtr m_aspDraw[6];             // +0xa0 meshes vfunc_1 renders
    float m_fInnerRadius;               // +0xd0
    float m_fOuterRadius;               // +0xd4
    Vector3 m_ptCenter;         // +0xd8
    float m_fHeight;                    // +0xe4
};
MS2_CHECK_SIZE(CHoleCylinderCollision, 0xe8);
MS2_CHECK_OFFSET(CHoleCylinderCollision, m_aspDraw, 0xa0);
MS2_CHECK_OFFSET(CHoleCylinderCollision, m_fInnerRadius, 0xd0);
MS2_CHECK_OFFSET(CHoleCylinderCollision, m_ptCenter, 0xd8);
MS2_CHECK_OFFSET(CHoleCylinderCollision, m_fHeight, 0xe4);
