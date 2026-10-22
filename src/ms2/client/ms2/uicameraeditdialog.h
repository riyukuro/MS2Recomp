// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicameraeditdialog.h (name assumed:
// the class name; the exe has no assert path for it).
//
// UICameraEditDialog is the camera edit overlay of the character customisation / housing UI (UI type 0x4ef2,
// "CameraEditDialog"). RTTI .?AVUICameraEditDialog@@, 0x1f8 bytes, vftables at +0 and +0x18 (IMessageListener). It
// reads ./data/xml/camera/customize.xml (one <camera> per preset, fov/distance/zoomIn/zoomOut/direction/rotation) and
// lets the mouse drag turn the target actor and the wheel zoom the camera.
// Names: virtuals are Ghidra's vfunc_<slot>; members are invented from their use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include <NiPoint3.h>

#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/client/ms2/uidialog.h"

class GameObject;
class Unk_140165cf0;

class UICameraEditDialog : public UIDialog
{
public:
    // One camera preset of customize.xml (RTTI UICameraEditDialog::CameraData, 0x48 bytes, reference counted).
    class CameraData : public CPtred
    {
    public:
        CameraData(int nTargetId);                                  // 0x1418dd2e0
        // ~CameraData: implicit (0x1418decb0 = CPtred::~CPtred only; ??_G 0x1418ded70)

        float GetFov() const;                                       // 0x1418dd3b0 m_fFov
        float GetZoomIn() const;                                    // 0x1418dd3d0 m_fZoomIn
        float GetZoomOut() const;                                   // 0x1418dd3f0 m_fZoomOut
        float GetDistance() const;                                  // 0x1418dd410 m_fDistance, /1.5 unless the actor has scale 1.5
        NiPoint3 GetCameraPos() const;                              // 0x1418dd470 actor position + direction * distance
        NiPoint3 GetRotation() const;                                 // 0x1418dd560 m_vRotation
        GameObject* GetTarget() const;                              // 0x1418dd590 the actor of m_nTargetId, else the local player

        int m_nTargetId;                                            // +0x18
        float m_fFov;                                               // +0x1c xml "fov"
        float m_fZoomIn;                                            // +0x20 xml "zoomIn"
        float m_fZoomOut;                                           // +0x24 xml "zoomOut"
        float m_fDistance;                                          // +0x28 xml "distance"
        NiPoint3 m_vRotation;                                        // +0x2c xml "rotation"
        NiPoint3 m_vDirection;                                       // +0x38 xml "direction"
    };

    typedef Unk_SocketPtr<CameraData> CameraDataPtr;                // RTTI TPtr<UICameraEditDialog::CameraData>
    typedef ATL::CAtlArray<CameraDataPtr> CameraDataArray;

    UICameraEditDialog();                                           // 0x1418dd5e0
    virtual ~UICameraEditDialog();                                  //  0 0x1418dd7c0 (??_G 0x1418dedb0)
    virtual CString vfunc_1();                                      //  1 0x1418dd810 "CameraEditDialog"
    virtual void OnLoadComplete();                                  // 22 0x1418dda70
    virtual void vfunc_15();                                        // 15 0x1418dda90 per-frame: keep the camera on the target
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x1418ddc80
    virtual void vfunc_32(void* p, float x, float y);               // 32 0x1418ddfc0
    virtual void vfunc_33(void* p, float x, float y);               // 33 0x1418de010
    virtual void vfunc_35(void* p, float x, float y);               // 35 0x1418de060
    virtual void vfunc_36(void* p, float x, float y);               // 36 0x1418de110
    virtual void vfunc_38(void* p, float x, float y);               // 38 0x1418ddcd0 drag: turn the actor
    virtual void vfunc_39(void* p, float x, float y, float f);      // 39 0x1418dded0 wheel: zoom in/out
    virtual int vfunc_48();                                         // 48 0x1418def90
    virtual int vfunc_65();                                         // 65 0x1418dd860 Open
    virtual void vfunc_67();                                        // 67 0x1418dd8a0 Close

    void FUN_1418dda30(int n);                                      // 0x1418dda30 m_bEnable = n unless vfunc_55()
    int FUN_1418de260();                                            // 0x1418de260 camera locked (not for dialog 0x4ec2)
    unsigned LoadCustomizeCamera();                                       // 0x1418de2b0 load customize.xml; 1 if it has presets
    void FUN_1418de570();                                           // 0x1418de570 zoom-in step
    void FUN_1418de690();                                           // 0x1418de690 zoom-out step
    void FUN_1418de7b0(const Unk_StreamPoint& vFrom, float fStep);  // 0x1418de7b0 move the camera one step
    void FUN_1418de920();                                           // 0x1418de920 m_1ec = 0
    void FUN_1418de980();                                           // 0x1418de980 turn the actor to the spawn direction
    GameObject* FUN_1418dea40();                                    // 0x1418dea40 the actor of m_nTargetId, else the local player
    int IsDragging();                                            // 0x1418dead0 m_bDragging

    int m_nTargetId;                                                // +0x178
    int m_nDialogId;                                                // +0x17c
    int m_180;                                                      // +0x180
    float m_fSavedCamera;                                           // +0x184 the camera setting restored on Close
    int m_nPreset;                                                  // +0x188
    int m_bEnable;                                                  // +0x18c
    int m_bDragging;                                                // +0x190
    CPoint m_ptDrag;                                                // +0x194
    Unk_StreamPoint m_vDragRotation;                                // +0x19c
    int m_nState;                                                   // +0x1a8 0 idle, 4 zoom in, 5 zoom out
    int m_1ac;                                                      // +0x1ac
    CameraDataArray m_aPresets;                                     // +0x1b0
    Unk_StreamPoint m_vMoveStart;                                   // +0x1d0
    int m_1dc;                                                      // +0x1dc
    Unk_StreamPoint m_vMoveTarget;                                  // +0x1e0
    int m_1ec;                                                      // +0x1ec
    int m_1f0;                                                      // +0x1f0
    int m_1f4;                                                      // +0x1f4
};
MS2_CHECK_SIZE(UICameraEditDialog::CameraData, 0x48);
MS2_CHECK_SIZE(UICameraEditDialog, 0x1f8);
