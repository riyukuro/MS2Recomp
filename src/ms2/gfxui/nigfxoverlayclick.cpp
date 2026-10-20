// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NiGFxOverlayClick (the GFx UI overlay render click),
// GFxRenderer and AtlasRecord of the GFx UI library. See nigfxoverlayclick.h.
// MS2-UNIT: ?\nigfxoverlayclick.cpp
// MS2-RANGE: 0x142303440-0x142303963 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// range likely holds three original objs (one per class); the tail is Render::Rect<int>'s ctor / SetRect COMDATs.
// MS2-PIN: ??_GNiGFxOverlayClick@@UEAAPEAXI@Z 0x142303570
// MS2-PIN: ??_GGFxRenderer@@UEAAPEAXI@Z 0x142303770
// MS2-PIN: ??_GAtlasRecord@@UEAAPEAXI@Z 0x1423038c0
#include "ms2/placeholder/ms2stdafx.h"

#include "nigfxoverlayclick.h"
#include "ms2/placeholder/gfxmanager.h"
#include "hook/ms2hook.h"

float FUN_1416fa2f0();                                              // the current time in seconds
void FUN_1422adf90(GFxManager* pManager);                           // renders the GFx UI movies

// @0x142303440
NiGFxOverlayClick::NiGFxOverlayClick()
    : m_fUIRenderTime(0.0f)
{
}

// @0x142303490
NiGFxOverlayClick::~NiGFxOverlayClick()
{
    m_fUIRenderTime = 0.0f;
}

// @0x1423034d0
float NiGFxOverlayClick::GetCullTime() const
{
    return 0.0f;
}
MS2_REPLACE_METHOD(0x1423034D0, NiGFxOverlayClick, GetCullTime, 9, 0x4FE1E1A5);

// @0x1423034e0
float NiGFxOverlayClick::GetRenderTime() const
{
    return m_fRenderTime;
}
MS2_REPLACE_METHOD(0x1423034E0, NiGFxOverlayClick, GetRenderTime, 19, 0xBB381A10);

// @0x142303500
unsigned int NiGFxOverlayClick::GetNumObjectsDrawn() const
{
    return 1;
}
MS2_REPLACE_METHOD(0x142303500, NiGFxOverlayClick, GetNumObjectsDrawn, 11, 0x30025ED0);

// @0x142303520
void NiGFxOverlayClick::PerformRendering(unsigned int uiFrameID)
{
    if (FUN_14025e7a0() != NULL)
    {
        float fStart = FUN_1416fa2f0();
        FUN_1422adf90(FUN_14025e7a0());
        m_fUIRenderTime = FUN_1416fa2f0() - fStart;
    }
}
MS2_REPLACE_METHOD(0x142303520, NiGFxOverlayClick, PerformRendering, 76, 0x4D46AFD2);

// @0x1423035e0
void NiGFxOverlayClick::FUN_1423035e0(void* p)
{
}

// @0x142303600
GFxRenderer::GFxRenderer()
{
}

// @0x142303640
GFxRenderer::~GFxRenderer()
{
}

// @0x142303670
Unk_GFxUIRenderer2D* GFxRenderer::vfunc_2() { return 0; }
// @0x142303680
int GFxRenderer::vfunc_3() { return 0; }
// @0x142303690
int GFxRenderer::vfunc_4() { return 0; }
// @0x1423036a0
void GFxRenderer::vfunc_5() {}
// @0x1423036b0
void GFxRenderer::vfunc_6(void* p) {}
// @0x1423036d0
int GFxRenderer::vfunc_7() { return 0; }
// @0x1423036e0
void GFxRenderer::vfunc_8() {}
// @0x1423036f0
void GFxRenderer::vfunc_9(void* p) {}
// @0x142303710
void GFxRenderer::vfunc_10() {}
// @0x142303720
void GFxRenderer::vfunc_11() {}
// @0x142303730
bool GFxRenderer::vfunc_12() { return true; }
// @0x142303740
void GFxRenderer::vfunc_13(void* p) {}
// @0x142303760
Ni2DBuffer* GFxRenderer::vfunc_14() { return 0; }

// @0x1423037d0
AtlasRecord::AtlasRecord(Unk_GfxImage* pImage)
    : m_spImage(pImage)
{
}

// @0x142303840
Unk_GfxImage* AtlasRecord::FUN_142303840()
{
    return m_spImage.get();
}
MS2_REPLACE_METHOD(0x142303840, AtlasRecord, FUN_142303840, 31, 0x8E35D2E7);
