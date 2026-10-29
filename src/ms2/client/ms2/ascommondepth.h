// ascommondepth.h - ASCommonDepth: the C++ side of the Scaleform class scaleform.ms2.common.CommonDepth, a helper
// that stacks display objects on named depth layers (addLayer / getLayer). Owning unit: ?\ascommondepth.cpp
// (0x1409b0fd0-0x1409b2870). Header name assumed from the unit path; the class name is real (RTTI, vftable
// 0x142db69d8, 1 slot: the deleting dtor 0x1409b1ff0). Derives from AScript (0x40 bytes), adds nothing.
#pragma once
#include "ms2/placeholder/ascript.h"

class ASCommonDepth : public AScript
{
public:
    ASCommonDepth(Scaleform::GFx::Value v, int nMovieId);               // 0x1409b0fd0 creates the AS object
    // ~ASCommonDepth 0x1409b1f50 is implicit (the exe dtor stores no vftable).

    // The AS helper object of the given movie (null smart pointer when the movie is not loaded).
    static MS2Ptr<ASCommonDepth> Create(int nMovieId);                  // 0x1409b1090
    // CommonDepth.addLayer(layer, nDepth)
    static void AddLayer(const Scaleform::GFx::Value& layer, int nDepth, int nMovieId);     // 0x1409b11d0
    // CommonDepth.getLayer(layer)
    static Scaleform::GFx::Value GetLayer(const Scaleform::GFx::Value& layer, int nMovieId);  // 0x1409b1290
};
