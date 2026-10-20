// asscrollpanel.h - PLACEHOLDER for ASScrollPanel (RTTI .?AVASScrollPanel@@, an ASUIComponent, 0x88 bytes; ctor
// 0x1409c1ae0, ??_G 0x1409c1be0). NOT an original header. The class's own unit (?\asitemslot.cpp) keeps a unit-local copy
// with the full slot list; this header declares what other units call. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASScrollPanel : public ASUIComponent
{
public:
    ASScrollPanel(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASScrollPanel();                                   // 0
    void FUN_1409c1ba0(int nHeight);                            // setContentsHeight
};
MS2_CHECK_SIZE(ASScrollPanel, 0x88);
