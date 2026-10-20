// asvideo.h - PLACEHOLDER for ASVideo (RTTI .?AVASVideo@@, an ASDisplayObject, vftable 0x14311a8a0), the wrapper of an
// ActionScript Video display object. NOT an original header. It reuses ASDisplayObject's 6 slots and adds no members
// (ctor 0x1422f74c0 only calls ASDisplayObject's and stores the vftable). Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"

class ASVideo : public ASDisplayObject
{
public:
    ASVideo(const Scaleform::GFx::Value& v, int nMovieId);         // 0x1422f74c0
    virtual ~ASVideo();                                             // 0x1422f7510
    void FUN_1422f7540(int nDeblocking);                            // set "deblocking"
    int FUN_1422f7570();                                            // "deblocking" (a bool as an int)
    void FUN_1422f75e0(int bSmoothing);                             // set "smoothing"
    int FUN_1422f7610();                                            // "smoothing" (a bool as an int)
    int FUN_1422f7680();                                            // "videoHeight"
    int FUN_1422f76e0();                                            // "videoWidth"
    void FUN_1422f7740();                                           // "clear"()
};
MS2_CHECK_SIZE(ASVideo, 0x80);
