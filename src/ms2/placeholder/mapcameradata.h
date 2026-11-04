// mapcameradata.h - PLACEHOLDER for CMapCameraData (RTTI .?AVCMapCameraData@@) and its derived CBossTargetCameraData
// (.?AVCBossTargetCameraData@@): the per-map camera configuration rows (XML "distance", "hAngle", ... ) loaded by
// vfunc_1. NOT an original header (name assumed). The classes are defined by the camera objs (ctors 0x140ae8ba0 and
// 0x140ae8df0, deleting dtors 0x140ae9330 / 0x140ae92f0); the boss camera (bosstargetcamera.cpp) embeds a
// CBossTargetCameraData and uses the inline copy assignments / destructor defined there.
// Layouts proved from the ctors (field initialisers), the copy assignments (0x140a38b90 / 0x140a38ac0, copying each
// field separately) and the operator delete size of CBossTargetCamera (0x168 = 0x110 + 0x58).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// 0x38 bytes. vftable 0x142dd5ca8 (2 slots: ~CMapCameraData, vfunc_1 = load from the XML row).
class CMapCameraData : public CPtred
{
public:
    CMapCameraData();                                               // 0x140ae8ba0
    CMapCameraData(const CMapCameraData& o);                        // 0x140ae8c50
    virtual ~CMapCameraData();                                      // 0x140ae8d10
    virtual void vfunc_1(void* pParam);                             // 0x140ae8d40

    // The implicit copy assignment (COMDAT 0x140a38b90): the base assignment, then each field.
    // @0x140a38b90
    CMapCameraData& operator=(const CMapCameraData& o)
    {
        CPtred::operator=(o);
        m_18 = o.m_18;
        m_distance = o.m_distance;
        m_vAngle = o.m_vAngle;
        m_hAngle = o.m_hAngle;
        m_zoomOutHeightOffset = o.m_zoomOutHeightOffset;
        m_zoomInHeightOffset = o.m_zoomInHeightOffset;
        m_30 = o.m_30;
        return *this;
    }

    int m_18;                           // +0x18 (ctor 2)
    float m_distance;                   // +0x1c "distance" (ctor 1200.0)
    float m_vAngle;                     // +0x20 "vAngle" (radians, ctor 50 degrees)
    float m_hAngle;                     // +0x24 "hAngle" (radians, ctor 45 degrees)
    float m_zoomOutHeightOffset;        // +0x28 "zoomOutHeightOffset" (ctor 60.0)
    float m_zoomInHeightOffset;         // +0x2c "zoomInHeightOffset" (ctor 95.0)
    bool m_30;                          // +0x30
};
MS2_CHECK_SIZE(CMapCameraData, 0x38);
MS2_CHECK_OFFSET(CMapCameraData, m_18, 0x18);
MS2_CHECK_OFFSET(CMapCameraData, m_30, 0x30);

// 0x58 bytes. vftable 0x142dd5cc0 (vfunc_1 overridden: loads the boss fields too).
class CBossTargetCameraData : public CMapCameraData
{
public:
    CBossTargetCameraData();                                        // 0x140ae8df0
    CBossTargetCameraData(const CMapCameraData& o);                 // 0x140ae8ec0 (the boss fields get their defaults)
    CBossTargetCameraData(const CBossTargetCameraData& o);          // 0x140ae8f90
    // The implicit destructor (COMDAT 0x140a38aa0): the exe copy stores no vptr, it only calls ~CMapCameraData.
    virtual ~CBossTargetCameraData() = default;
    virtual void vfunc_1(void* pParam);                             // 0x140ae9070

    // The implicit copy assignment (COMDAT 0x140a38ac0).
    // @0x140a38ac0
    CBossTargetCameraData& operator=(const CBossTargetCameraData& o)
    {
        CMapCameraData::operator=(o);
        m_distanceOffset = o.m_distanceOffset;
        m_detachDistance = o.m_detachDistance;
        m_zoomOut = o.m_zoomOut;
        m_viewOffsetZ = o.m_viewOffsetZ;
        m_lerpSpeedMin = o.m_lerpSpeedMin;
        m_lerpSpeedMax = o.m_lerpSpeedMax;
        m_lerpDelayDistanceMin = o.m_lerpDelayDistanceMin;
        m_lerpDelayDistanceMax = o.m_lerpDelayDistanceMax;
        return *this;
    }

    float m_distanceOffset;             // +0x38 "distanceOffset" (ctor 500.0)
    float m_detachDistance;             // +0x3c "detachDistance" (ctor 800.0)
    float m_zoomOut;                    // +0x40 "zoomOut" (ctor 2000.0)
    float m_viewOffsetZ;                // +0x44 "viewOffsetZ" (ctor 200.0)
    float m_lerpSpeedMin;               // +0x48 "lerpSpeedMin" (ctor 0.001)
    float m_lerpSpeedMax;               // +0x4c "lerpSpeedMax" (ctor 0.005)
    float m_lerpDelayDistanceMin;       // +0x50 "lerpDelayDistanceMin" (ctor 1000.0)
    float m_lerpDelayDistanceMax;       // +0x54 "lerpDelayDistanceMax" (ctor 2000.0)
};
MS2_CHECK_SIZE(CBossTargetCameraData, 0x58);
MS2_CHECK_OFFSET(CBossTargetCameraData, m_distanceOffset, 0x38);
MS2_CHECK_OFFSET(CBossTargetCameraData, m_lerpDelayDistanceMax, 0x54);
