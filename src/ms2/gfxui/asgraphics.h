// asgraphics.h - ASGraphics (RTTI .?AVASGraphics@@, base AScript, vftable 0x14311a670, 1 slot): wraps an AS
// flash.display.Graphics object. Header name and directory assumed (the GFx UI library has no __FILE__ strings).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class ASGraphics : public AScript
{
public:
    ASGraphics(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1422f7250
    virtual ~ASGraphics();                                      // 0x1422f72a0 (scalar deleting 0x1422f72d0)
};
MS2_CHECK_SIZE(ASGraphics, 0x40);
