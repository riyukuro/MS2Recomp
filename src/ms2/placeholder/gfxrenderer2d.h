// gfxrenderer2d.h - PLACEHOLDER for the GFx UI renderer objects of Scaleform 4.1.18: the D3D9 HAL (Render::D3D9::HAL) and
// Render::Renderer2D. NOT an original header; the classes are SDK code (out-of-line, bound through symbols / FUN_<va> names).
// The exe's HAL is 0xa7a0 bytes and its slot list differs from the 4.1.19 SDK's, so neither SDK class is used here (the
// SDK Renderer2D(HAL*) ctor would need the SDK HAL). Both are RefCountBase<.., StatRender_Mem> objects: Scaleform::Ptr<>
// AddRef/Release are RefCountImpl's (0x14257dc30/0x14257dcb0) and `new` is the SF_MEMORY_REDEFINE_NEW operator.
// Created by GFxRenderSingleThread (gfxui/gfxrendersinglethread.cpp, `*SF_NEW` into Ptr<> members).
#pragma once

#include "Kernel/SF_RefCount.h"
#include "Render/Render_Stats.h"
#include "Render/Render_GlyphCacheConfig.h"

#include "ms2/ms2layout.h"

namespace Scaleform { namespace Render {
class ThreadCommandQueue;
namespace D3D9 { struct HALInitParams; }
} }

// Render::D3D9::HAL (vftable 0x14319d760; slot 0 the virtual dtor). Only the slots called by the game are typed; their
// names are the SDK's Render::HAL ones.
class Unk_GFxUIHal : public Scaleform::RefCountBase<Unk_GFxUIHal, Scaleform::StatRender_Mem>
{
public:
    explicit Unk_GFxUIHal(Scaleform::Render::ThreadCommandQueue* pCommandQueue = 0);   // 0x14272dc10

    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35();
    virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43();
    virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47();
    virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51();
    virtual void* vfunc_52();                                       // 52 (+0x1a0) the UI render context (asyncimageloader.cpp)
    virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55();
    virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62();
    virtual bool InitHAL(const Scaleform::Render::D3D9::HALInitParams& params);    // 63 (+0x1f8) 0x142741e90
    virtual bool ShutdownHAL();                                     // 64 (+0x200) 0x1427423e0
    virtual void PrepareForReset();                                 // 65 (+0x208) 0x1427422c0
    virtual bool RestoreAfterReset();                               // 66 (+0x210) 0x142742360

private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xa7a0 - 0x10];
};
MS2_CHECK_SIZE(Unk_GFxUIHal, 0xa7a0);

// Render::Renderer2D (0x18 bytes: RefCountBase + the Renderer2DImpl pointer).
class Unk_GFxUIRenderer2D : public Scaleform::RefCountBase<Unk_GFxUIRenderer2D, Scaleform::StatRender_Mem>
{
public:
    explicit Unk_GFxUIRenderer2D(Unk_GFxUIHal* pHal);               // 0x142581fe0 Renderer2D(HAL*)

    bool FUN_142582210();                                           // BeginFrame()
    void FUN_142582250();                                           // EndFrame()
    Scaleform::Render::GlyphCacheConfig* FUN_142582280();           // GetGlyphCacheConfig()
    Unk_GFxUIHal* FUN_1425822a0();                                  // GetHAL(): pImpl (+0x10) -> HAL (+0x50)

private:
    MS2_LAYOUT_FRIEND;
    void* m_pImpl;                                                  // +0x10 Renderer2DImpl*
};
MS2_CHECK_SIZE(Unk_GFxUIRenderer2D, 0x18);
