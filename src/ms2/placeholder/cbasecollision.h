// cbasecollision.h - CBaseCollision (RTTI .?AVCBaseCollision@@, vftable 0x142dc1928, 8 slots): base of the debug-visible
// collision shapes (CBoxCollision, CCylinderCollision, CHoleCylinderCollision, ...). NOT an original header (name
// assumed). Owning unit: ?\basecollision.cpp (0x1409fbb80-0x140a02ac0), whose members are only declared here (the
// layout is proven by CBaseCollision::CBaseCollision 0x1409fbc80 and the derived ctor of holecylindercollision.cpp).
// Member names are invented from use.
// Slots: 0 scalar deleting dtor, 1 render, 2/3 transform setters with identical bodies (m_ptPos = pos, then 0x1409fe440),
// 4 empty, 5 Build (pure here), 6 float accessor (pure here), 7 intersection test.
#pragma once
#include <afx.h>
#include <NiMesh.h>
#include <NiColor.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include <efd/Point3.h>
#include <efd/SmartPointer.h>

class GameObject;
class CBoxCollision;
class CDetectContext;
template <class T> class MS2Ptr;

// Per-object result of CBaseCollision::TestShape (ctor 0x140a00200): the sort mode in, the metrics out (x lateral,
// y forward distance, z planar distance).
struct Unk_DetectHit
{
    int m_nMode;
    NiPoint3 m_kMetric;
};

class CBaseCollision : public CPtred
{
public:
    CBaseCollision();                                               // 0x1409fbc80
    virtual ~CBaseCollision();                                      // 0x1409fbed0
    virtual void vfunc_1();                                         // 0x1409fbf20: draws the wire mesh
    virtual void vfunc_2(Vector3 ptPos, const NiMatrix3& kRot, float fScale);   // 0x1409fbff0 (same body as vfunc_3)
    virtual void vfunc_3(Vector3 ptPos, Vector3 ptDir, float fScale);   // 0x1409fbfa0
    virtual void vfunc_4();                                         // 0x1409fc040
    virtual void vfunc_5() = 0;                                     // builds the wire meshes
    virtual float vfunc_6() = 0;
    virtual int vfunc_7(efd::SmartPointer<GameObject> spSelf, efd::SmartPointer<GameObject> spTarget);   // 0x1409fc050
                                                                    // hit test of spTarget's box against this shape
                                                                    // placed at spSelf

    void FUN_1409fc390(MS2Ptr<CDetectContext> spCtx, const efd::Point3& kRot);   // place by a z rotation, then Detect
    void FUN_1409fc540(MS2Ptr<CDetectContext> spCtx, const NiMatrix3& kRot);     // place by a rotation, then Detect
    void Detect(MS2Ptr<CDetectContext> spCtx);                      // 0x1409fc6c0 collect and sort the hit objects
    void Invalidate();                                              // 0x1409fe440 rebuild the wire meshes on next draw
    static bool TestShape(efd::Point3 kPos, efd::Point3 kRight, efd::Point3 kDir, CBaseCollision* pShape,
                          CBoxCollision* pBox, Unk_DetectHit* pHit);   // 0x1409fe460
    static bool Intersect(CBaseCollision* pShape, CBaseCollision* pBox);   // 0x1409ff0d0

    int m_n18;                          // +0x18
    Vector3 m_ptPos;            // +0x1c
    Vector3 m_ptSize;           // +0x28 (size / half extents)
    Vector3 m_ptDir;            // +0x34
    int m_nShape;                       // +0x40 shape kind (the hole cylinder stores 4)
    NiColorA m_kColor;                  // +0x44 wire color (red)
    bool m_b54;                         // +0x54
    int m_n58;                          // +0x58
    CStringA m_strName;                 // +0x60
    NiMeshPtr m_spMesh;                 // +0x68
    int m_bBuilt;                       // +0x70 vfunc_5 has run
};
MS2_CHECK_SIZE(CBaseCollision, 0x78);
MS2_CHECK_OFFSET(CBaseCollision, m_ptPos, 0x1c);
MS2_CHECK_OFFSET(CBaseCollision, m_nShape, 0x40);
MS2_CHECK_OFFSET(CBaseCollision, m_kColor, 0x44);
MS2_CHECK_OFFSET(CBaseCollision, m_strName, 0x60);
MS2_CHECK_OFFSET(CBaseCollision, m_spMesh, 0x68);
MS2_CHECK_OFFSET(CBaseCollision, m_bBuilt, 0x70);
