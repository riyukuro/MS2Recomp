// caprotationcontroller.h - CCapRotationController (RTTI .?AVCCapRotationController@@, 0x140 bytes): the customize
// controller of the cap (hat) rotation gizmo. It rotates the cap model on the head by dragging the mouse around the
// mesh of the cap's attach part. Equip slot 6 = cap. Owning unit: ?\caprotationcontroller.cpp
// (src/ms2/client/ms2/caprotationcontroller.cpp, 0x140b00540-0x140b03040). Header name assumed. Member names are
// invented from their use.
#pragma once
#include "itemcustomizecontroller_1.h"
#include "itempickinghelper.h"
#include <efd/SmartPointer.h>
#include <efd/Point3.h>
#include <efd/Point2.h>
#include "ms2/placeholder/nipoint3.h"

class NiMesh;

class CCapRotationController : public CItemCustomizeController
{
public:
    CCapRotationController();                                       // 0x140b00540
    virtual ~CCapRotationController();                              // 0x140b006a0, ??_G 0x140b02b30
    NiDeclareRTTI;                                                  // 2  GetRTTI 0x140b02c30
    virtual int vfunc_3();                                          // 3  0x140b00730 (initialize from the item)
    virtual void vfunc_6();                                         // 6  0x140b007e0 (re-apply the initial rotation)
    virtual int vfunc_29();                                         // 29 0x140b00830
    virtual void vfunc_28();                                        // 28 0x140b00960 (attach / picking mesh names)
    virtual void vfunc_30(const NiPoint3& kPos);                    // 30 0x140b00d30 drag (mode 1) begin
    virtual void vfunc_31();                                        // 31 0x140b00f20 drag (mode 1) no hit
    virtual void vfunc_32(const NiPoint3& kHit, const NiPoint3& kNormal, const NiPoint2& kUV, float fValue);
                                                                    // 32 0x140b01310 drag (mode 1) hit
    virtual void vfunc_33();                                        // 33 0x140b01870 drag (mode 1) end
    virtual void vfunc_34(const NiPoint3& kPos);                    // 34 0x140b01920 drag (mode 2) begin
    virtual void vfunc_35();                                        // 35 0x140b019a0 drag (mode 2) update
    virtual void vfunc_36();                                        // 36 0x140b01b80 drag (mode 2) end

    // non-virtual (names invented)
    int InitPart();                                                 // 0x140b01bb0
    void ResetHighlight();                                          // 0x140b01fa0
    Vector3 UpdateRotationMatrix();                                // 0x140b020d0
    Vector3 GetPartEuler();                                        // 0x140b02180
    void SetPartEuler(Vector3 kEuler);                             // 0x140b02310
    float WrapAngle(float fDegrees, float fMin, float fMax);        // 0x140b02730
    static float SafeAcos(float fCos);                              // 0x140b02b90

    efd::SmartPointer<NiMesh> m_spMesh;                             // +0xb8 the cap mesh
    MS2Ptr<Unk_PickTarget> m_spPart;                                // +0xc0 the cap attach part
    float m_fSpeed;                                                 // +0xd0 = 0.5
    float m_fRadius;                                                // +0xd4
    Vector3 m_kDragDir;                                            // +0xd8
    Vector3 m_kMinEuler;                                           // +0xe4
    Vector3 m_kMaxEuler;                                           // +0xf0
    Vector3 m_kCurEuler;                                           // +0xfc
    Vector3 m_kInitEuler;                                          // +0x108
    Unk_EfdMatrix3 m_kInitRot;                                        // +0x114
    efd::Point2 m_kDragStart;                                       // +0x138
};
MS2_CHECK_SIZE(CCapRotationController, 0x140);
MS2_CHECK_OFFSET(CCapRotationController, m_spMesh, 0xb8);
MS2_CHECK_OFFSET(CCapRotationController, m_spPart, 0xc0);
MS2_CHECK_OFFSET(CCapRotationController, m_fSpeed, 0xd0);
MS2_CHECK_OFFSET(CCapRotationController, m_kDragDir, 0xd8);
MS2_CHECK_OFFSET(CCapRotationController, m_kMinEuler, 0xe4);
MS2_CHECK_OFFSET(CCapRotationController, m_kCurEuler, 0xfc);
MS2_CHECK_OFFSET(CCapRotationController, m_kInitRot, 0x114);
MS2_CHECK_OFFSET(CCapRotationController, m_kDragStart, 0x138);
