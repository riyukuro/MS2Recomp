// astooltipmanager.h - ASTooltipManager (RTTI .?AVASTooltipManager@@, base AScript, vftable 0x14310bbe0, 0x40 bytes:
// `new` of 0x40 in FUN_1422c6240): the movie's AS "scaleform.ms2.manager.TooltipManager" class object, through which
// display objects register for tooltip mouse events. Header name and directory assumed (the GFx UI library has no
// __FILE__ strings). The code is in astooltipmanager.cpp (?\astooltipmanager.cpp).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class ASTooltipManager : public AScript
{
public:
    ASTooltipManager(Scaleform::GFx::Value v, int nMovieId);        // 0x1422c6100 (v by value: the callee destroys it)
    // ~ASTooltipManager is implicit (0x1422c64a0: only ~AScript; ??_G 0x1422c64d0)
    void FUN_1422c6160(const Scaleform::GFx::Value& obj);           // AS registerMouseEvent(obj)
    void FUN_1422c61d0(const Scaleform::GFx::Value& obj);           // AS unregisterMouseEvent(obj)
};
MS2_CHECK_SIZE(ASTooltipManager, 0x40);

// The tooltip manager of movie nMovieId (null if the movie is not loaded; a fresh wrapper each call).
MS2Ptr<ASTooltipManager> FUN_1422c6240(int nMovieId);
// Register / unregister a display object for tooltip mouse events in movie nMovieId (unit_140cff310.cpp).
void FUN_1422c6380(Scaleform::GFx::Value& obj, int nMovieId);
void FUN_1422c63f0(Scaleform::GFx::Value& obj, int nMovieId);
