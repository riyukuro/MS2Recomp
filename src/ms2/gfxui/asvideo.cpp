// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASVideo, the ActionScript Video display object wrapper of
// the GFx UI library.
// MS2-UNIT: ?\asvideo.cpp
// MS2-RANGE: 0x1422f74c0-0x1422f77b0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asvideo.h.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asvideo.h"

#include "hook/ms2hook.h"

// @0x1422f74c0
ASVideo::ASVideo(const Scaleform::GFx::Value& v, int nMovieId)
    : ASDisplayObject(v, nMovieId)
{
}

// @0x1422f7510
ASVideo::~ASVideo()
{
}

// @0x1422f7540
void ASVideo::FUN_1422f7540(int nDeblocking)
{
    FUN_1407cb9c0("deblocking", nDeblocking);
}
MS2_REPLACE_METHOD(0x1422F7540, ASVideo, FUN_1422f7540, 40, 0xE4F47567);

// @0x1422f7570
int ASVideo::FUN_1422f7570()
{
    return FUN_1422baa20("deblocking").GetBool();
}
MS2_REPLACE_METHOD(0x1422F7570, ASVideo, FUN_1422f7570, 91, 0xB5FAD214);

// @0x1422f75e0
void ASVideo::FUN_1422f75e0(int bSmoothing)
{
    FUN_1407cb9c0("smoothing", bSmoothing);
}
MS2_REPLACE_METHOD(0x1422F75E0, ASVideo, FUN_1422f75e0, 40, 0xAEB91D5F);

// @0x1422f7610
int ASVideo::FUN_1422f7610()
{
    return FUN_1422baa20("smoothing").GetBool();
}
MS2_REPLACE_METHOD(0x1422F7610, ASVideo, FUN_1422f7610, 91, 0xFE65B6FE);

// @0x1422f7680
int ASVideo::FUN_1422f7680()
{
    return FUN_1422baa20("videoHeight").GetInt();
}
MS2_REPLACE_METHOD(0x1422F7680, ASVideo, FUN_1422f7680, 88, 0x21AD8DD2);

// @0x1422f76e0
int ASVideo::FUN_1422f76e0()
{
    return FUN_1422baa20("videoWidth").GetInt();
}
MS2_REPLACE_METHOD(0x1422F76E0, ASVideo, FUN_1422f76e0, 88, 0x797DFB1E);

// @0x1422f7740
void ASVideo::FUN_1422f7740()
{
    Invoke("clear");
}
MS2_REPLACE_METHOD(0x1422F7740, ASVideo, FUN_1422f7740, 46, 0xE4A2C251);

// MS2-PIN: ??_GASVideo@@UEAAPEAXI@Z 0x1422f7770
