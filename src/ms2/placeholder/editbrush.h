// editbrush.h - the deco-edit brush classes (RTTI EditBrush / PaintBrush / NoiseBrush). NOT an original header. Owning
// unit: ?\editbrush.cpp (0x141197280-0x141198830). DecoEditService (decoeditservice.cpp) creates the two concrete
// brushes, keeps them in a CAtlMap<int, MS2Ptr<EditBrush>> and drives them through the virtual slots below. A brush
// shows a circle mesh at the picked ground point; paint stamps decoration instances inside it, noise re-rotates and
// re-scales the ones already there. Slot and member names are invented from that use.
//
// vftables: EditBrush 0x142eb9100, PaintBrush 0x142eb9158, NoiseBrush 0x142eb91b0 (10 slots each; slot 0 is the
// deleting dtor). Sizes: EditBrush 0x78 (Timer at +0x40), PaintBrush 0x88, NoiseBrush 0x98.
#pragma once

#include <NiColor.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include <efd/SmartPointer.h>

class NiMesh;
typedef efd::SmartPointer<NiMesh> NiMeshPtr;

// A 2D range / vector (the noise brush keeps a scale range and a rotation range in degrees).
struct Unk_BrushVec2
{
    Unk_BrushVec2* FUN_140a0a600(float x, float y);                 // 0x140a0a600 (same as the Point2 ctor of the dialog)
    float m_x;
    float m_y;
};

class EditBrush : public CPtred
{
public:
    EditBrush();                            // 0x141197280
    virtual ~EditBrush();                   // 0
    virtual void vfunc_1();                 // 1  brush deselected (rebuild the circle mesh)
    virtual void vfunc_2();                 // 2  per tick: poll the mouse buttons, apply on a held press
    virtual void vfunc_3();                 // 3  brush selected (show the mesh)
    virtual void vfunc_4();                 // 4  left button: apply
    virtual void vfunc_5();                 // 5  right button: apply the opposite
    virtual void vfunc_6(float fRadius);    // 6  set the radius
    virtual void vfunc_7(float fDensity);   // 7  set the density
    virtual void vfunc_8(Unk_BrushVec2 v);  // 8  set the scale range
    virtual void vfunc_9(Unk_BrushVec2 v);  // 9  set the rotation range
    void SetKColor(const NiColorA& kColor);     // 0x141197470 set the circle colour
    void SetPtPos(Unk_StreamPoint pt);         // 0x1411974a0 sets the brush point (+0x28)
    Unk_StreamPoint GetPtPos();                // 0x1411974d0 the brush point
    NiColorA m_kColor;                      // +0x18
    Unk_StreamPoint m_ptPos;                // +0x28
    Unk_BrushVec2 m_vUnused;                // +0x34
    Timer m_timer;                          // +0x40
};
MS2_CHECK_SIZE(EditBrush, 0x78);

class PaintBrush : public EditBrush
{
public:
    PaintBrush();                           // 0x141197500
    virtual ~PaintBrush();                  // 0x141197580
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(float fRadius);
    virtual void vfunc_7(float fDensity);
    float m_fRadius;                        // +0x78
    float m_fDensity;                       // +0x7c stamps per application
    NiMeshPtr m_spMesh;                     // +0x80
};
MS2_CHECK_SIZE(PaintBrush, 0x88);

class NoiseBrush : public EditBrush
{
public:
    NoiseBrush();                           // 0x141197a50
    virtual ~NoiseBrush();                  // 0x141197b00
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(float fRadius);
    virtual void vfunc_8(Unk_BrushVec2 v);
    virtual void vfunc_9(Unk_BrushVec2 v);
    float m_fRadius;                        // +0x78
    Unk_BrushVec2 m_vScale;                 // +0x7c
    Unk_BrushVec2 m_vRotation;              // +0x84
    NiMeshPtr m_spMesh;                     // +0x90
};
MS2_CHECK_SIZE(NoiseBrush, 0x98);
