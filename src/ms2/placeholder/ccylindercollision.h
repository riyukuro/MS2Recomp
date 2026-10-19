// ccylindercollision.h - CCylinderCollision (RTTI name; 0xc8 bytes, ctor 0x141083230): the upright cylinder collision
// shape (shape kind 2). NOT an original header; the owning unit unit_141083230.cpp keeps its own (identical) class
// declaration. Only what other units need is declared here.
#pragma once
#include "ms2/placeholder/cbasecollision.h"

class CCylinderCollision : public CBaseCollision
{
public:
    CCylinderCollision();                                           // 0x141083230
    virtual ~CCylinderCollision();                                  // 0x141083320
    virtual void vfunc_1();                                         // 0x1410846a0
    virtual void vfunc_3(Unk_StreamPoint pos, Unk_StreamPoint rot, float scale);   // 0x1410833c0
    virtual void vfunc_5();                                         // 0x1410834d0
    virtual float vfunc_6();                                        // 0x141083450

    float GetTopZ() const;                                          // 0x141083470 center z + height
    float GetBottomZ() const;                                       // 0x1410834a0 center z - size z

    NiMeshPtr m_spTopMesh;                                          // +0x78
    NiMeshPtr m_spBottomMesh;                                       // +0x80
    NiMeshPtr m_spLineMesh;                                         // +0x88
    NiMeshPtr m_aspMeshes[4];                                       // +0x90
    float m_radius;                                                 // +0xb0
    Unk_StreamPoint m_center;                                       // +0xb4
    float m_height;                                                 // +0xc0
};
MS2_CHECK_OFFSET(CCylinderCollision, m_radius, 0xb0);
MS2_CHECK_SIZE(CCylinderCollision, 0xc8);
