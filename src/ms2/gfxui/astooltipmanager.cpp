// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTooltipManager, the AS tooltip manager of a movie.
// MS2-UNIT: ?\astooltipmanager.cpp
// MS2-RANGE: 0x1422c6100-0x1422c6570 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings). Function names are Ghidra's
// (FUN_<va>). Tail: MS2Ptr<ASTooltipManager> members (its operator-> 0x140ed3bc0 and dtor 0x140ed3780 are copies of an
// earlier unit), the implicit ~ASTooltipManager and ??_G. FUN_1422c6240 and its two callers are not hooked: they
// construct an ASTooltipManager (the DLL copy would install the DLL's vftable).
#include "ms2/placeholder/ms2stdafx.h"

#include "astooltipmanager.h"

#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

// @0x1422c6100
ASTooltipManager::ASTooltipManager(Scaleform::GFx::Value v, int nMovieId)
    : AScript(v, nMovieId)
{
}

// @0x1422c6160
void ASTooltipManager::FUN_1422c6160(const Scaleform::GFx::Value& obj)
{
    Invoke("registerMouseEvent", obj);
}
MS2_REPLACE_METHOD(0x1422C6160, ASTooltipManager, FUN_1422c6160, 92, 0x18941F28);

// @0x1422c61d0
void ASTooltipManager::FUN_1422c61d0(const Scaleform::GFx::Value& obj)
{
    Invoke("unregisterMouseEvent", obj);
}
MS2_REPLACE_METHOD(0x1422C61D0, ASTooltipManager, FUN_1422c61d0, 92, 0x03ECCAA6);

// @0x1422c6240
MS2Ptr<ASTooltipManager> FUN_1422c6240(int nMovieId)
{
    GFxMovie* pMovie = FUN_14025e7a0()->FUN_1422b01a0(nMovieId);
    if (pMovie != 0)
        return MS2Ptr<ASTooltipManager>(new ASTooltipManager(pMovie->FUN_1422bd120("scaleform.ms2.manager.TooltipManager"), nMovieId));
    return MS2Ptr<ASTooltipManager>(0);
}

// @0x1422c6380
void FUN_1422c6380(Scaleform::GFx::Value& obj, int nMovieId)
{
    MS2Ptr<ASTooltipManager> spManager = FUN_1422c6240(nMovieId);
    if (spManager.get() != 0)
        spManager->FUN_1422c6160(obj);
}

// @0x1422c63f0
void FUN_1422c63f0(Scaleform::GFx::Value& obj, int nMovieId)
{
    MS2Ptr<ASTooltipManager> spManager = FUN_1422c6240(nMovieId);
    if (spManager.get() != 0)
        spManager->FUN_1422c61d0(obj);
}

// MS2-PIN: ??_GASTooltipManager@@UEAAPEAXI@Z 0x1422c64d0
