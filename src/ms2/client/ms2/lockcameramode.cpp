// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See lockcameramode.h.
// MS2-UNIT: ?\lockcameramode.cpp
// MS2-RANGE: 0x14144fd30-0x14144fe90 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\lockcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "lockcameramode.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14144fd30
CLockCameraMode::CLockCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev)
{
}

// @0x14144fdb0
CLockCameraMode::~CLockCameraMode()
{
}

// @0x14144fde0
void CLockCameraMode::vfunc_8(double fTime)
{
}
MS2_REPLACE_METHOD(0x14144fde0, CLockCameraMode, vfunc_8, 12, 0x49415BA5);

// @0x14144fe00
void CLockCameraMode::vfunc_9()
{
}
MS2_REPLACE_METHOD(0x14144fe00, CLockCameraMode, vfunc_9, 6, 0xA9AF6E37);

// @0x14144fe10
void FUN_14144fe10(void* p)
{
}

// @0x14144fe20
float CLockCameraMode::vfunc_22()
{
    return 90.0f;
}
MS2_REPLACE_METHOD(0x14144fe20, CLockCameraMode, vfunc_22, 14, 0xB9A998B4);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x14144fe10, FUN_14144fe10, 6, 0xA9AF6E37);

