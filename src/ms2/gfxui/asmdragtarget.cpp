// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASMDragTarget, a drag-and-drop target component.
// MS2-UNIT: ?\asmdragtarget.cpp
// MS2-RANGE: 0x1422e47c0-0x1422e4900 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"

#include "asmdragtarget.h"

#include "hook/ms2hook.h"

// @0x1422e47c0
ASMDragTarget::ASMDragTarget(const Scaleform::GFx::Value& v, int nMovieId)
    : ASDragSlot(v, nMovieId)
{
}

// @0x1422e4810
ASMDragTarget::~ASMDragTarget()
{
}

// @0x1422e4840
void ASMDragTarget::FUN_1422e4840(CString strBinding)
{
    m_value.SetMember("binding", Scaleform::GFx::Value(strBinding));
}

// MS2-PIN: ??_GASMDragTarget@@UEAAPEAXI@Z 0x1422e48c0
