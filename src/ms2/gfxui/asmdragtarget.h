// asmdragtarget.h - ASMDragTarget (RTTI .?AVASMDragTarget@@, base ASDragSlot, vftable 0x143115488, 25 slots, 0x88
// bytes: ??_G deletes 0x88): a drag-and-drop target component. Header name and directory assumed (the GFx UI library
// has no __FILE__ strings). The code is in asmdragtarget.cpp (?\asmdragtarget.cpp).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/gfxui/asdragslot.h"

class ASMDragTarget : public ASDragSlot
{
public:
    ASMDragTarget(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422e47c0
    virtual ~ASMDragTarget();                                       // 0 0x1422e4810 (scalar deleting 0x1422e48c0)
    void FUN_1422e4840(CString strBinding);                         // set the AS "binding" member (by value: the callee destroys it)
};
MS2_CHECK_SIZE(ASMDragTarget, 0x88);
