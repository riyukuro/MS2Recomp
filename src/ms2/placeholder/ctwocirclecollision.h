// ctwocirclecollision.h - CTwoCircleCollision (0xb0 bytes, ctor 0x141868af0): the debug-visible attenuation shape of a
// sound event (an inner and an outer circle). NOT an original header (name from the exe's RTTI, layout from the
// operator new size in CSoundEvent::CSoundEvent and CTwoCircleCollision::CTwoCircleCollision). Owning unit:
// ?\twocirclecollision.cpp (0x141868af0-0x1418694d0). The virtual destructor is the key function, so no vftable is
// emitted in the including unit. The radius setters live in unit_1416c2c00.
#pragma once
#include "ms2/placeholder/cbasecollision.h"

class CTwoCircleCollision : public CBaseCollision
{
public:
    CTwoCircleCollision();                                          // 0x141868af0
    virtual ~CTwoCircleCollision();                                 // 0x141868bd0
    virtual void vfunc_1();                                         // 0x141868d10 renders the two wire rings
    virtual void vfunc_3(Unk_StreamPoint ptPos, Unk_StreamPoint ptDir, float fScale);   // 0x141868c60
    virtual void vfunc_5();                                         // 0x141868db0 builds the two wire circles
    virtual float vfunc_6();                                        // 0x1418694c0
    void SetInnerRadius(float fMin);                                 // 0x1416c4b60 the inner radius
    void SetOuterRadius(float fMax);                                 // 0x1416c4bf0 the outer radius

private:
    void BuildWire(NiMesh* pMesh, const Unk_StreamPoint* pPoints, unsigned int nCount);   // 0x1418692d0

    MS2_LAYOUT_FRIEND;
    NiMeshPtr m_spInner;                // +0x78 inner circle mesh
    NiMeshPtr m_spOuter;                // +0x80 outer circle mesh
    NiMeshPtr m_aspDraw[2];             // +0x88 meshes vfunc_1 renders
    float m_fInnerRadius;               // +0x98
    float m_fOuterRadius;               // +0x9c
    Unk_StreamPoint m_ptCenter;         // +0xa0
};
MS2_CHECK_SIZE(CTwoCircleCollision, 0xb0);
MS2_CHECK_OFFSET(CTwoCircleCollision, m_aspDraw, 0x88);
MS2_CHECK_OFFSET(CTwoCircleCollision, m_fInnerRadius, 0x98);
MS2_CHECK_OFFSET(CTwoCircleCollision, m_ptCenter, 0xa0);
