// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASMovieClip, the wrapper of an AS MovieClip (the base of
// the UI components).
// MS2-UNIT: ?\asmovieclip.cpp
// MS2-RANGE: 0x1422c1e40-0x1422c2fc0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: the ctor 0x1422c1e40 follows ASDisplayObject's COMDAT tail; ASEventDispatcher's ctor starts the next obj at
// 0x1422c2fc0. The obj's COMDAT tail is sorted by mangled name: the SDK's Value(Double) ctor 0x1422c2da0, the scalar
// deleting dtor 0x1422c2de0, the SDK's Value::GotoAndPlay/GotoAndStop(unsigned) 0x1422c2e20/0x1422c2e60, then the CRT
// memmove_s copy 0x1422c2ea0. The class is declared in src/ms2/placeholder/asdisplayobject.h.
#define MS2_THIS_FILE "asmovieclip.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asfunction.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

extern Scaleform::GFx::Value DAT_143b0ae18;                    // an undefined value (unit_140135ac0.cpp)
Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);            // the GFx movie of a movie id (null if not loaded)

// @0x1422c1e40
ASMovieClip::ASMovieClip(int nMovieId)
    : ASSprite(DAT_143b0ae18, nMovieId)
{
}

// @0x1422c1e90
ASMovieClip::ASMovieClip(Scaleform::GFx::Value v, int nMovieId)
    : ASSprite(v, nMovieId)
{
}

// @0x1422c1ef0
ASMovieClip::ASMovieClip(CString strLinkage, int nMovieId)
    : ASSprite(DAT_143b0ae18, nMovieId)
{
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie != NULL) {
        pMovie->CreateObject(&m_value, strLinkage, 0, 0);
        if (m_value.IsUndefined()) {
        }
    }
}

// @0x1422c1fb0
ASMovieClip::~ASMovieClip()
{
}

// @0x1422c1fe0
void ASMovieClip::FUN_1422c1fe0(int bEnabled)
{
    FUN_1407cbbe0("enabled", bEnabled != 0);
}
MS2_REPLACE_METHOD(0x1422C1FE0, ASMovieClip, FUN_1422c1fe0, 60, 0x71A1E927);

// @0x1422c2030
int ASMovieClip::FUN_1422c2030()
{
    return FUN_1422baa20("enabled").GetBool();
}
MS2_REPLACE_METHOD(0x1422C2030, ASMovieClip, FUN_1422c2030, 91, 0xF8A9AD73);

// @0x1422c20a0
void ASMovieClip::vfunc_6()
{
    Invoke("play");
}
MS2_REPLACE_METHOD(0x1422C20A0, ASMovieClip, vfunc_6, 46, 0x31463620);

// @0x1422c20e0
void ASMovieClip::vfunc_7()
{
    Invoke("stop");
}
MS2_REPLACE_METHOD(0x1422C20E0, ASMovieClip, vfunc_7, 46, 0xF2930B75);

// @0x1422c2120
void ASMovieClip::vfunc_8()
{
    Invoke("prevFrame");
}
MS2_REPLACE_METHOD(0x1422C2120, ASMovieClip, vfunc_8, 46, 0xE13EFAD2);

// @0x1422c2160
void ASMovieClip::vfunc_9()
{
    Invoke("nextFrame");
}
MS2_REPLACE_METHOD(0x1422C2160, ASMovieClip, vfunc_9, 46, 0xAF7C6522);

// @0x1422c21a0
void ASMovieClip::vfunc_10()
{
    Invoke("prevScene");
}
MS2_REPLACE_METHOD(0x1422C21A0, ASMovieClip, vfunc_10, 46, 0x35D284EF);

// @0x1422c21e0
void ASMovieClip::vfunc_11()
{
    Invoke("nextScene");
}
MS2_REPLACE_METHOD(0x1422C21E0, ASMovieClip, vfunc_11, 46, 0xC00D47A0);

// @0x1422c2220
void ASMovieClip::vfunc_13(const CString& strLabel)
{
    m_value.GotoAndPlay(strLabel);
}
MS2_REPLACE_METHOD(0x1422C2220, ASMovieClip, vfunc_13, 47, 0x38AE6DC2);

// @0x1422c2260
void ASMovieClip::vfunc_12(int nFrame)
{
    m_value.GotoAndPlay(nFrame);
}
MS2_REPLACE_METHOD(0x1422C2260, ASMovieClip, vfunc_12, 39, 0x880AFFE7);

// @0x1422c2290
void ASMovieClip::vfunc_15(const CString& strLabel)
{
    m_value.GotoAndStop(strLabel);
}
MS2_REPLACE_METHOD(0x1422C2290, ASMovieClip, vfunc_15, 47, 0xF7EB8654);

// @0x1422c22d0
void ASMovieClip::vfunc_14(int nFrame)
{
    m_value.GotoAndStop(nFrame);
}
MS2_REPLACE_METHOD(0x1422C22D0, ASMovieClip, vfunc_14, 39, 0x441BCDF7);

// @0x1422c2300
int ASMovieClip::FUN_1422c2300()
{
    return FUN_1422baa20("currentFrame").GetInt();
}
MS2_REPLACE_METHOD(0x1422C2300, ASMovieClip, FUN_1422c2300, 88, 0x3860367F);

// @0x1422c2360
CString ASMovieClip::FUN_1422c2360()
{
    Scaleform::GFx::Value v = FUN_1422baa20("currentFrameLabel");
    if (v.IsString())
        return CString(v.GetString());
    return CString("");
}
MS2_REPLACE_METHOD(0x1422C2360, ASMovieClip, FUN_1422c2360, 172, 0x4B3CB78C);

// @0x1422c2420
CString ASMovieClip::FUN_1422c2420()
{
    return CString(FUN_1422baa20("currentLabel").GetString());
}
MS2_REPLACE_METHOD(0x1422C2420, ASMovieClip, FUN_1422c2420, 123, 0xB3302518);

// @0x1422c24b0
int ASMovieClip::FUN_1422c24b0()
{
    return FUN_1422baa20("totalFrames").GetInt();
}
MS2_REPLACE_METHOD(0x1422C24B0, ASMovieClip, FUN_1422c24b0, 88, 0x340EE638);

// @0x1422c2510
int ASMovieClip::FUN_1422c2510(double* pX, double* pY)
{
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie == NULL)
        return 0;
    Scaleform::GFx::Value point;
    pMovie->CreateObject(&point, "flash.geom.Point", 0, 0);
    if (point.IsUndefined())
        return 0;
    Scaleform::GFx::Value result = Invoke("localToGlobal", point);
    if (result.IsObject()) {
        Scaleform::GFx::Value x;
        Scaleform::GFx::Value y;
        if (result.GetMember("x", &x))
            *pX = x.GetNumber();
        if (result.GetMember("y", &y))
            *pY = y.GetNumber();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422C2510, ASMovieClip, FUN_1422c2510, 489, 0x5C25EF81);

// @0x1422c2700
int ASMovieClip::FUN_1422c2700(float* pX, float* pY)
{
    return FUN_1422c2740(0, 0, pX, pY);
}
MS2_REPLACE_METHOD(0x1422C2700, ASMovieClip, FUN_1422c2700, 55, 0xEEA93180);

// @0x1422c2740
int ASMovieClip::FUN_1422c2740(float x, float y, float* pX, float* pY)
{
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie == NULL)
        return 0;
    Scaleform::GFx::Value point;
    pMovie->CreateObject(&point, "flash.geom.Point", 0, 0);
    if (point.IsUndefined())
        return 0;
    point.SetMember("x", (double)x);
    point.SetMember("y", (double)y);
    Scaleform::GFx::Value result = Invoke("globalToLocal", point);
    if (result.IsObject()) {
        Scaleform::GFx::Value localX;
        Scaleform::GFx::Value localY;
        if (result.GetMember("x", &localX))
            *pX = (float)localX.GetNumber();
        if (result.GetMember("y", &localY))
            *pY = (float)localY.GetNumber();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422C2740, ASMovieClip, FUN_1422c2740, 634, 0x7848ED6E);

// @0x1422c29c0
int ASMovieClip::FUN_1422c29c0(float x, float y, bool bShapeFlag)
{
    Scaleform::GFx::Value result = FUN_1422c1870("hitTestPoint", x, y, bShapeFlag);
    if (result.IsBool())
        return result.GetBool();
    return 0;
}
MS2_REPLACE_METHOD(0x1422C29C0, ASMovieClip, FUN_1422c29c0, 168, 0x46923415);

// @0x1422c2a70
void ASMovieClip::FUN_1422c2a70(const ASCallback& cb, void* pUser)
{
    CString strEvent("click");
    FUN_1422c3600(strEvent, cb, false, 0, 0, pUser);
}
// no hook: overloaded (the int-user declaration in asdisplayobject.h names the same function)

// @0x1422c2af0
void ASMovieClip::FUN_1422c2af0(const ASCallback& cb)
{
    CString strEvent("click");
    FUN_1422c3820(strEvent, cb, false);
}
MS2_REPLACE_METHOD(0x1422C2AF0, ASMovieClip, FUN_1422c2af0, 82, 0x90C507C3);

// @0x1422c2b50
void ASMovieClip::FUN_1422c2b50(const ASCallback& cb, void* pUser)
{
    CString strEvent("doubleClick");
    FUN_1422c3600(strEvent, cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422C2B50, ASMovieClip, FUN_1422c2b50, 113, 0xCF13A8F9);

// @0x1422c2bd0
void ASMovieClip::FUN_1422c2bd0(const ASCallback& cb)
{
    CString strEvent("doubleClick");
    FUN_1422c3820(strEvent, cb, false);
}
MS2_REPLACE_METHOD(0x1422C2BD0, ASMovieClip, FUN_1422c2bd0, 82, 0x11EE430C);

// @0x1422c2c30
void ASMovieClip::FUN_1422c2c30(const ASCallback& cb, void* pUser)
{
    CString strEvent("rightClick");
    FUN_1422c3600(strEvent, cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422C2C30, ASMovieClip, FUN_1422c2c30, 113, 0x0C34BD40);

// @0x1422c2cb0
void ASMovieClip::FUN_1422c2cb0(const ASCallback& cb)
{
    CString strEvent("rightClick");
    FUN_1422c3820(strEvent, cb, false);
}
MS2_REPLACE_METHOD(0x1422C2CB0, ASMovieClip, FUN_1422c2cb0, 82, 0x0E45EB64);

// @0x1422c2d10
void ASMovieClip::FUN_1422c2d10(ASCallback cb, void* pUser)
{
    FUN_141b46a40("externalTooltipFunction", ASFunction(cb, (__int64)pUser, m_nMovieId));
}

// @0x1422c2ea0
MS2_EMIT_CRT_MEMMOVE_S();

// MS2-PIN: ??_GASMovieClip@@UEAAPEAXI@Z 0x1422c2de0
