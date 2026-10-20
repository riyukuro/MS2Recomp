// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASDisplayObject, the base of every ActionScript display wrapper.
// MS2-UNIT: ?\asdisplayobject.cpp
// MS2-RANGE: 0x1422bf7c0-0x1422c1e40 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: the ctor 0x1422bf7c0 follows GFxMovie's COMDAT tail (its Delegate glue 0x1422bf690-0x1422bf7c0); the
// ASMovieClip ctors start the next obj at 0x1422c1e40. The obj's COMDAT tail is sorted by mangled name: the
// Invoke(float, float, bool) instance 0x1422c1870, the SDK's DisplayInfo ctor 0x1422c1950, the scalar deleting dtor
// 0x1422c19a0, then the SDK's DisplayInfo / Value::Get/SetDisplayInfo inlines 0x1422c19e0-0x1422c1e40.
// The class is declared in src/ms2/placeholder/asdisplayobject.h (shared; Ghidra's FUN_<va> names are kept there).
#include "ms2/placeholder/ms2stdafx.h"


#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

typedef Scaleform::GFx::Value::DisplayInfo DisplayInfo;

extern "C" double (__cdecl* __imp_ceil)(double);              // the exe imports ceil from the UCRT

// The GFx UI manager singleton (0x14025e7a0; its class lives in the library's first obj, 0x1422b0060-0x1422b7f20).
class Unk_GFxUIManager
{
public:
    MS2Ptr<ASStage> FUN_1422b02f0(int nMovieId);                // the stage of a movie (null if the movie is not loaded)
};
Unk_GFxUIManager* FUN_14025e7a0();

// The typed Value setters of the Invoke argument lists (COMDATs of ASArray's obj).
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);

// @0x1422bf7c0
ASDisplayObject::ASDisplayObject(const Scaleform::GFx::Value& v, int nMovieId)
    : ASEventDispatcher(v, nMovieId)
{
}

// @0x1422bf810
ASDisplayObject::~ASDisplayObject()
{
}

// @0x1422bf840
void ASDisplayObject::vfunc_2(int a1, int a2, int a3)
{
    vfunc_1(a1, a2, a3, (int)FUN_1422c1420(), (int)FUN_1422c1490());
}
MS2_REPLACE_METHOD(0x1422BF840, ASDisplayObject, vfunc_2, 112, 0x3F908D23);

// @0x1422bf8c0
void ASDisplayObject::vfunc_1(int a1, int a2, int a3, int a4, int a5)
{
    if (a1 == 0) {
        int nX = (int)((float)(FUN_1422c1500() - a4) * 0.5f);
        int nY = (int)((float)(FUN_1422c1530() - a5) * 0.5f);
        FUN_1422bffe0(nX + a2, nY + a3);
    }
    else if (a1 == 1) {
        int nX = (int)((float)(FUN_1422c1500() - a4) * 0.5f);
        FUN_1422bffe0(nX + a2, a3);
    }
    else if (a1 == 2) {
        int nX = (int)((float)(FUN_1422c1500() - a4) * 0.5f);
        int nY = FUN_1422c1530() - a5;
        FUN_1422bffe0(nX + a2, nY + a3);
    }
    else if (a1 == 3) {
        int nY = (int)((float)(FUN_1422c1530() - a5) * 0.5f);
        FUN_1422bffe0(a2, nY + a3);
    }
    else if (a1 == 4) {
        int nX = FUN_1422c1500() - a4;
        int nY = (int)((float)(FUN_1422c1530() - a5) * 0.5f);
        FUN_1422bffe0(nX + a2, nY + a3);
    }
    else if (a1 == 5) {
        FUN_1422bffe0(a2, a3);
    }
    else if (a1 == 6) {
        int nX = FUN_1422c1500() - a4;
        FUN_1422bffe0(nX + a2, a3);
    }
    else if (a1 == 7) {
        int nY = FUN_1422c1530() - a5;
        FUN_1422bffe0(a2, nY + a3);
    }
    else if (a1 == 8) {
        int nX = FUN_1422c1500() - a4;
        int nY = FUN_1422c1530() - a5;
        FUN_1422bffe0(nX + a2, nY + a3);
    }
}
MS2_REPLACE_METHOD(0x1422BF8C0, ASDisplayObject, vfunc_1, 767, 0x3D15EC4D);

// @0x1422bfbd0
void ASDisplayObject::vfunc_4(bool b)
{
    if (FUN_1422bfca0() != b) {
        DisplayInfo info;
        info.SetVisible(b);
        FUN_1422c17d0(info);
    }
}
MS2_REPLACE_METHOD(0x1422BFBD0, ASDisplayObject, vfunc_4, 132, 0x34FE4609);

// @0x1422bfc60
void ASDisplayObject::vfunc_3(int nVisible)
{
    vfunc_4(nVisible != 0);
}
MS2_REPLACE_METHOD(0x1422BFC60, ASDisplayObject, vfunc_3, 58, 0xD413C844);

// @0x1422bfca0
bool ASDisplayObject::FUN_1422bfca0()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return info.GetVisible();
}
MS2_REPLACE_METHOD(0x1422BFCA0, ASDisplayObject, FUN_1422bfca0, 92, 0xBED04D4E);

// @0x1422bfd10
void ASDisplayObject::FUN_1422bfd10(float fFOV)
{
    DisplayInfo info;
    info.SetFOV(fFOV);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422BFD10, ASDisplayObject, FUN_1422bfd10, 110, 0x0E1B4542);

// @0x1422bfd90
float ASDisplayObject::FUN_1422bfd90()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetFOV();
}
MS2_REPLACE_METHOD(0x1422BFD90, ASDisplayObject, FUN_1422bfd90, 96, 0xDA1A6BAC);

// @0x1422bfe00
void ASDisplayObject::FUN_1422bfe00(float fAlpha)
{
    DisplayInfo info;
    info.SetAlpha(fAlpha);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422BFE00, ASDisplayObject, FUN_1422bfe00, 110, 0x436B3027);

// @0x1422bfe80
float ASDisplayObject::FUN_1422bfe80()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetAlpha();
}
MS2_REPLACE_METHOD(0x1422BFE80, ASDisplayObject, FUN_1422bfe80, 96, 0xA53736ED);

// @0x1422bfef0
void ASDisplayObject::FUN_1422bfef0(float fRotation)
{
    DisplayInfo info;
    info.SetRotation(fRotation);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422BFEF0, ASDisplayObject, FUN_1422bfef0, 110, 0x21578B05);

// @0x1422bff70
float ASDisplayObject::FUN_1422bff70()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetRotation();
}
MS2_REPLACE_METHOD(0x1422BFF70, ASDisplayObject, FUN_1422bff70, 96, 0x2AD71F62);

// @0x1422bffe0
void ASDisplayObject::FUN_1422bffe0(int x, int y)
{
    DisplayInfo info;
    info.SetPosition(x, y);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422BFFE0, ASDisplayObject, FUN_1422bffe0, 122, 0x21E0AFC2);

// @0x1422c0060
void ASDisplayObject::FUN_1422c0060(unsigned int x, unsigned int y)
{
    DisplayInfo info;
    info.SetPosition(x, y);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0060, ASDisplayObject, FUN_1422c0060, 128, 0xD9BC7E96);

// @0x1422c00f0
void ASDisplayObject::FUN_1422c00f0(float x, float y)
{
    DisplayInfo info;
    info.SetPosition(x, y);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C00F0, ASDisplayObject, FUN_1422c00f0, 125, 0xBFC88BB6);

// @0x1422c0180
void ASDisplayObject::FUN_1422c0180(int xScale, int yScale)
{
    DisplayInfo info;
    info.SetScale(xScale, yScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0180, ASDisplayObject, FUN_1422c0180, 122, 0xAE8B3511);

// @0x1422c0200
void ASDisplayObject::FUN_1422c0200(unsigned int xScale, unsigned int yScale)
{
    DisplayInfo info;
    info.SetScale(xScale, yScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0200, ASDisplayObject, FUN_1422c0200, 128, 0x90F337AE);

// @0x1422c0290
void ASDisplayObject::FUN_1422c0290(float xScale, float yScale)
{
    DisplayInfo info;
    info.SetScale(xScale, yScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0290, ASDisplayObject, FUN_1422c0290, 125, 0x6D488ABF);

// @0x1422c0320
void ASDisplayObject::FUN_1422c0320(int x)
{
    DisplayInfo info;
    info.SetX(x);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0320, ASDisplayObject, FUN_1422c0320, 108, 0x30022F9B);

// @0x1422c03a0
void ASDisplayObject::FUN_1422c03a0(unsigned int x)
{
    DisplayInfo info;
    info.SetX(x);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C03A0, ASDisplayObject, FUN_1422c03a0, 111, 0x49D7DC28);

// @0x1422c0420
void ASDisplayObject::FUN_1422c0420(float x)
{
    DisplayInfo info;
    info.SetX(x);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0420, ASDisplayObject, FUN_1422c0420, 110, 0x53F38A0F);

// @0x1422c04a0
void ASDisplayObject::FUN_1422c04a0(int y)
{
    DisplayInfo info;
    info.SetY(y);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C04A0, ASDisplayObject, FUN_1422c04a0, 108, 0x8927D0FA);

// @0x1422c0520
void ASDisplayObject::FUN_1422c0520(unsigned int y)
{
    DisplayInfo info;
    info.SetY(y);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0520, ASDisplayObject, FUN_1422c0520, 111, 0xAE514023);

// @0x1422c05a0
void ASDisplayObject::FUN_1422c05a0(float y)
{
    DisplayInfo info;
    info.SetY(y);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C05A0, ASDisplayObject, FUN_1422c05a0, 110, 0x33914884);

// @0x1422c0620
void ASDisplayObject::FUN_1422c0620(int z)
{
    DisplayInfo info;
    info.SetZ(z);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0620, ASDisplayObject, FUN_1422c0620, 108, 0x4EE6034F);

// @0x1422c06a0
void ASDisplayObject::FUN_1422c06a0(unsigned int z)
{
    DisplayInfo info;
    info.SetZ(z);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C06A0, ASDisplayObject, FUN_1422c06a0, 111, 0xABB4FE7C);

// @0x1422c0720
void ASDisplayObject::FUN_1422c0720(float z)
{
    DisplayInfo info;
    info.SetZ(z);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0720, ASDisplayObject, FUN_1422c0720, 110, 0x8EC9E9CB);

// @0x1422c07a0
void ASDisplayObject::FUN_1422c07a0(int dx)
{
    DisplayInfo info;
    FUN_1422c1810(info);
    info.SetX(info.GetX() + dx);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C07A0, ASDisplayObject, FUN_1422c07a0, 140, 0x2321F16B);

// @0x1422c0840
void ASDisplayObject::FUN_1422c0840(int dy)
{
    DisplayInfo info;
    FUN_1422c1810(info);
    info.SetY(info.GetY() + dy);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0840, ASDisplayObject, FUN_1422c0840, 140, 0x0D3F84EB);

// @0x1422c08e0
void ASDisplayObject::FUN_1422c08e0(int dx, int dy)
{
    DisplayInfo info;
    FUN_1422c1810(info);
    info.SetPosition(info.GetX() + dx, info.GetY() + dy);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C08E0, ASDisplayObject, FUN_1422c08e0, 183, 0x499E9910);

// @0x1422c09a0
void ASDisplayObject::FUN_1422c09a0(int xScale)
{
    DisplayInfo info;
    info.SetXScale(xScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C09A0, ASDisplayObject, FUN_1422c09a0, 108, 0xC4A5EF59);

// @0x1422c0a20
void ASDisplayObject::FUN_1422c0a20(unsigned int xScale)
{
    DisplayInfo info;
    info.SetXScale(xScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0A20, ASDisplayObject, FUN_1422c0a20, 111, 0x659F08AA);

// @0x1422c0aa0
void ASDisplayObject::FUN_1422c0aa0(float xScale)
{
    DisplayInfo info;
    info.SetXScale(xScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0AA0, ASDisplayObject, FUN_1422c0aa0, 110, 0x7AF10865);

// @0x1422c0b20
void ASDisplayObject::FUN_1422c0b20(int yScale)
{
    DisplayInfo info;
    info.SetYScale(yScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0B20, ASDisplayObject, FUN_1422c0b20, 108, 0x03F8A57A);

// @0x1422c0ba0
void ASDisplayObject::FUN_1422c0ba0(unsigned int yScale)
{
    DisplayInfo info;
    info.SetYScale(yScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0BA0, ASDisplayObject, FUN_1422c0ba0, 111, 0x47E3694B);

// @0x1422c0c20
void ASDisplayObject::FUN_1422c0c20(float yScale)
{
    DisplayInfo info;
    info.SetYScale(yScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0C20, ASDisplayObject, FUN_1422c0c20, 110, 0x774D0774);

// @0x1422c0ca0
void ASDisplayObject::FUN_1422c0ca0(int zScale)
{
    DisplayInfo info;
    info.SetZScale(zScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0CA0, ASDisplayObject, FUN_1422c0ca0, 108, 0x8C8B2FD5);

// @0x1422c0d20
void ASDisplayObject::FUN_1422c0d20(unsigned int zScale)
{
    DisplayInfo info;
    info.SetZScale(zScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0D20, ASDisplayObject, FUN_1422c0d20, 111, 0x73C6966E);

// @0x1422c0da0
void ASDisplayObject::FUN_1422c0da0(float zScale)
{
    DisplayInfo info;
    info.SetZScale(zScale);
    FUN_1422c17d0(info);
}
MS2_REPLACE_METHOD(0x1422C0DA0, ASDisplayObject, FUN_1422c0da0, 110, 0x4F1B59B5);

// @0x1422c0e20
void ASDisplayObject::FUN_1422c0e20(int nWidth)
{
    FUN_1407cb9c0("width", nWidth);
}
MS2_REPLACE_METHOD(0x1422C0E20, ASDisplayObject, FUN_1422c0e20, 40, 0xF43A4683);

// @0x1422c0e50
void ASDisplayObject::FUN_1422c0e50(unsigned int nWidth)
{
    FUN_1409c0d20("width", nWidth);
}
MS2_REPLACE_METHOD(0x1422C0E50, ASDisplayObject, FUN_1422c0e50, 40, 0x6CA4A137);

// @0x1422c0e80
void ASDisplayObject::FUN_1422c0e80(float fWidth)
{
    FUN_1409c4a30("width", fWidth);
}
MS2_REPLACE_METHOD(0x1422C0E80, ASDisplayObject, FUN_1422c0e80, 43, 0xBDE70F30);

// @0x1422c0ec0
void ASDisplayObject::FUN_1422c0ec0(int nHeight)
{
    FUN_1407cb9c0("height", nHeight);
}
MS2_REPLACE_METHOD(0x1422C0EC0, ASDisplayObject, FUN_1422c0ec0, 40, 0x7CDC41CA);

// @0x1422c0ef0
void ASDisplayObject::FUN_1422c0ef0(unsigned int nHeight)
{
    FUN_1409c0d20("height", nHeight);
}
MS2_REPLACE_METHOD(0x1422C0EF0, ASDisplayObject, FUN_1422c0ef0, 40, 0x8BA3A8EF);

// @0x1422c0f20
void ASDisplayObject::FUN_1422c0f20(float fHeight)
{
    FUN_1409c4a30("height", fHeight);
}
MS2_REPLACE_METHOD(0x1422C0F20, ASDisplayObject, FUN_1422c0f20, 43, 0x01256289);

// @0x1422c0f60
void ASDisplayObject::FUN_1422c0f60(float* pX, float* pY)
{
    DisplayInfo info;
    FUN_1422c1810(info);
    *pX = (float)info.GetX();
    *pY = (float)info.GetY();
}
MS2_REPLACE_METHOD(0x1422C0F60, ASDisplayObject, FUN_1422c0f60, 144, 0x5A46A634);

// @0x1422c1000
void ASDisplayObject::FUN_1422c1000(float* pXScale, float* pYScale)
{
    DisplayInfo info;
    FUN_1422c1810(info);
    *pXScale = (float)info.GetXScale();
    *pYScale = (float)info.GetYScale();
}
MS2_REPLACE_METHOD(0x1422C1000, ASDisplayObject, FUN_1422c1000, 144, 0x805C9117);

// @0x1422c10a0
float ASDisplayObject::FUN_1422c10a0()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetX();
}
MS2_REPLACE_METHOD(0x1422C10A0, ASDisplayObject, FUN_1422c10a0, 96, 0x63D14FD3);

// @0x1422c1110
float ASDisplayObject::FUN_1422c1110()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetY();
}
MS2_REPLACE_METHOD(0x1422C1110, ASDisplayObject, FUN_1422c1110, 96, 0xA56E69E6);

// @0x1422c1180
float ASDisplayObject::FUN_1422c1180()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetZ();
}
MS2_REPLACE_METHOD(0x1422C1180, ASDisplayObject, FUN_1422c1180, 96, 0x63B5C7F0);

// @0x1422c11f0
float ASDisplayObject::FUN_1422c11f0()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetXScale();
}
MS2_REPLACE_METHOD(0x1422C11F0, ASDisplayObject, FUN_1422c11f0, 96, 0x6DB6F603);

// @0x1422c1260
float ASDisplayObject::FUN_1422c1260()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetYScale();
}
MS2_REPLACE_METHOD(0x1422C1260, ASDisplayObject, FUN_1422c1260, 96, 0xA1BD8121);

// @0x1422c12d0
float ASDisplayObject::FUN_1422c12d0()
{
    DisplayInfo info;
    FUN_1422c1810(info);
    return (float)info.GetZScale();
}
MS2_REPLACE_METHOD(0x1422C12D0, ASDisplayObject, FUN_1422c12d0, 96, 0x86E13DDA);

// @0x1422c1340
int ASDisplayObject::FUN_1422c1340()
{
    return (int)__imp_ceil(FUN_1422baa20("width").GetNumber());
}
MS2_REPLACE_METHOD(0x1422C1340, ASDisplayObject, FUN_1422c1340, 98, 0x03A840C4);

// @0x1422c13b0
int ASDisplayObject::FUN_1422c13b0()
{
    return (int)__imp_ceil(FUN_1422baa20("height").GetNumber());
}
MS2_REPLACE_METHOD(0x1422C13B0, ASDisplayObject, FUN_1422c13b0, 98, 0x2F42C94E);

// @0x1422c1420
float ASDisplayObject::FUN_1422c1420()
{
    return (float)FUN_1422baa20("width").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C1420, ASDisplayObject, FUN_1422c1420, 96, 0x61F8A1E0);

// @0x1422c1490
float ASDisplayObject::FUN_1422c1490()
{
    return (float)FUN_1422baa20("height").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C1490, ASDisplayObject, FUN_1422c1490, 96, 0xA52BF40A);

// @0x1422c1500
int ASDisplayObject::FUN_1422c1500()
{
    return vfunc_5()->FUN_1422cfec0();
}
MS2_REPLACE_METHOD(0x1422C1500, ASDisplayObject, FUN_1422c1500, 38, 0x85E10692);

// @0x1422c1530
int ASDisplayObject::FUN_1422c1530()
{
    return vfunc_5()->FUN_1422cff20();
}
MS2_REPLACE_METHOD(0x1422C1530, ASDisplayObject, FUN_1422c1530, 38, 0x200B7642);

// @0x1422c1560
ASStage* ASDisplayObject::vfunc_5()
{
    return FUN_14025e7a0()->FUN_1422b02f0(m_nMovieId).get();
}
MS2_REPLACE_METHOD(0x1422C1560, ASDisplayObject, vfunc_5, 95, 0xFEF77BC5);

// @0x1422c15d0
int ASDisplayObject::FUN_1422c15d0(int x, int y, bool bShapeFlag)
{
    return FUN_1422c1870("hitTestPoint", (float)x, (float)y, bShapeFlag).GetBool();
}
MS2_REPLACE_METHOD(0x1422C15D0, ASDisplayObject, FUN_1422c15d0, 147, 0xD9FCB1BD);

// @0x1422c1670
int ASDisplayObject::FUN_1422c1670(float x, float y, bool bShapeFlag)
{
    return FUN_1422c1870("hitTestPoint", x, y, bShapeFlag).GetBool();
}
MS2_REPLACE_METHOD(0x1422C1670, ASDisplayObject, FUN_1422c1670, 147, 0x4082612F);

// @0x1422c1710
int ASDisplayObject::FUN_1422c1710(MS2Ptr<ASDisplayObject> spObj)
{
    return Invoke("hitTestObject", spObj->FUN_1422bb870()).GetBool();
}

// @0x1422c17d0
int ASDisplayObject::FUN_1422c17d0(const DisplayInfo& info)
{
    if (!m_value.SetDisplayInfo(info))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1422C17D0, ASDisplayObject, FUN_1422c17d0, 57, 0x63C11524);

// @0x1422c1810
int ASDisplayObject::FUN_1422c1810(DisplayInfo& info)
{
    if (!m_value.IsObject())
        return 0;
    if (!m_value.GetDisplayInfo(&info))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1422C1810, ASDisplayObject, FUN_1422c1810, 85, 0xB2492391);

// @0x1422c1870
inline Scaleform::GFx::Value AScript::FUN_1422c1870(const char* szMethod, float a1, float a2, bool a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcd70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}
