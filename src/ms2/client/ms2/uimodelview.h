// uimodelview.h - UIModelView (RTTI .?AVUIModelView@@, 0xe8 bytes): the UIRenderView that shows one avatar object (character,
// cube, pet, ridee) in the UI. It adds an orbit camera with a zoom range and a back/forth zoom animation to the base view.
// Unit `?\uimodelview.cpp` (.text$mn 0x140e66920-0x140e694a0, vftable 0x142e51298); every name except the RTTI class names
// is invented from its use.
#pragma once

#include "ms2/client/ms2/uirenderview.h"
#include <NiPoint3.h>

// The camera preset the view is set to (0x30): the camera position, the point it looks at, and the zoom range.
class Unk_ModelViewCamera
{
public:
    Unk_ModelViewCamera();                                  // 0x140cb13b0
    NiPoint3 m_kPosition;                                   // +0x00
    NiPoint3 m_kTarget;                                     // +0x0c
    float m_fSpeed;                                         // +0x18 (distance per second of the zoom animation)
    float m_fMinDistance;                                   // +0x1c
    float m_fMaxDistance;                                   // +0x20
    float m_fStep;                                          // +0x24
    int m_nSteps;                                           // +0x28
    int m_nStepsDone;                                       // +0x2c
};
MS2_CHECK_SIZE(Unk_ModelViewCamera, 0x30);

class UIModelView : public UIRenderView
{
public:
    UIModelView(unsigned int uiWidth, unsigned int uiHeight, GameObject* pObject, float fLightDimmer);   // 0x140e67e30
    virtual ~UIModelView();                                 // 0x140e66920 (scalar deleting 0x140e69000)

    virtual void vfunc_2();                                 // 2 0x140e66a30 before the click draws: advance the zoom animation
    virtual void vfunc_3();                                 // 3 0x140e66aa0 after the click drew
    virtual void vfunc_5(float fStep);                      // 5 0x140e66b20 start a zoom-in animation
    virtual void vfunc_6(float fStep);                      // 6 0x140e66bb0 start a zoom-out animation
    virtual void vfunc_7(float fX, float fY, float fZ);     // 7 0x140e66c40 rotate the camera about the target
    virtual void vfunc_8(float fDist);                      // 8 0x140e66fa0 set the camera distance (clamped to the near limit)
    virtual void vfunc_9(float fDist);                      // 9 0x140e67140 set the camera distance (clamped to the far limit)
    virtual void vfunc_10(int nObjectId);                   // 10 0x140e672e0
    virtual void vfunc_12(const ATL::CAtlArray<NiNode*>& arrNodes, NiNodePtr spRoot);   // 12 0x140e67350 show the object's nodes
    virtual int vfunc_13(const Unk_ModelViewCamera& kCamera);   // 13 0x140e67710 apply a camera preset
    virtual int vfunc_14();                                 // 14 0x140e67f80 create the lights
    virtual int vfunc_15();                                 // 15 0x140e68420 create the camera
    virtual void vfunc_17(const NiPoint3& kPivot);          // 17 0x140e67c20 remember the pivot and the camera state

    void FUN_140e685d0();                                   // 0x140e685d0 steps the zoom animation

protected:
    NiPoint3 m_kFarPosition;                                // +0x60 camera position at the far limit
    NiPoint3 m_kNearPosition;                               // +0x6c camera position at the near limit
    Unk_ModelViewCamera m_kCamera;                          // +0x78
    int m_nZoomState;                                       // +0xa8 0 idle, 1 zooming in, 2 zooming out
    NiPoint3 m_kZoomStart;                                  // +0xac camera position when the animation started
    NiPoint3 m_kBackupTranslate;                            // +0xb8
    NiPoint3 m_kRotation;                                   // +0xc4 accumulated rotation (degrees)
    NiPoint3 m_kBackupCenter;                               // +0xd0
    NiPoint3 m_kBackupUp;                                   // +0xdc
};
MS2_CHECK_SIZE(UIModelView, 0xe8);
