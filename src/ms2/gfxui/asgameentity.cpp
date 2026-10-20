// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASGameEntity, the AS component behind the HUD entities
// (name tags, HP bars, chat balloons; the UIHudEntity family).
// MS2-UNIT: ?\asgameentity.cpp
// MS2-RANGE: 0x1422de590-0x1422de680 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asgameentity.h"

#include "hook/ms2hook.h"

// @0x1422de590
ASGameEntity::ASGameEntity(const Scaleform::GFx::Value& root, int nMovieId)
    : ASUIComponent(root, nMovieId)
{
}

// @0x1422de5e0
ASGameEntity::~ASGameEntity()
{
}

// @0x1422de610
void ASGameEntity::vfunc_25()
{
    Invoke("alignment");
}
MS2_REPLACE_METHOD(0x1422DE610, ASGameEntity, vfunc_25, 46, 0x31FD9A6E);

// MS2-PIN: ??_GASGameEntity@@UEAAPEAXI@Z 0x1422de640
