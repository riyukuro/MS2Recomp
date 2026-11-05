// gfxrenderhandle.h - the GFx render-handle glue shared by the movies that draw into a render texture (GFxMovieBackground,
// GFxMovieUgc): the HAL (FUN_1422cf060) that wraps a D3D surface into a render target, and the ref-counted render
// handle objects passed by Ptr<> to GFxMovie::vfunc_9. Same definitions as the local ones of gfxmoviebackground.cpp
// (which owns the out-of-line members: Unk_BgDispHandle copy/dtor 0x14127c130/0x14127c530, Assign 0x14127cb10, ...).
#pragma once

#include "ms2/client/ms2/gfxmoviebackground.h"     // Unk_BgTarget, Unk_BgComPtr<T>

struct IDirect3DSurface9;

// The GFx renderer HAL: slot 67 wraps a D3D surface into a render target.
class Unk_BgHal
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual Unk_BgTarget* vfunc_67(IDirect3DSurface9* pSurface, int nFlags);
};
class Unk_GFxUIHal* FUN_1422cf060();   // the UI renderer's HAL (gfxrenderhelpers.h); callers view it as Unk_BgHal

// The ref-counted handle objects of vfunc_9 (Scaleform render handles): AddRef/Release are out-of-line library functions.
// Views of the SDK render classes vfunc_9 calls by name (render_renderer2d.h clashes with the GFx kernel headers here;
// gfxmoviebackground.cpp declares the same views).
namespace Scaleform { namespace Render {
namespace ContextImpl {
class Entry;
class RenderNotify;
class RTHandle
{
public:
    bool   NextCapture(RenderNotify* render);
    Entry* GetRenderEntry() const;
private:
    void* pData;
};
}
class Renderer2D
{
public:
    ContextImpl::RenderNotify* GetContextNotify() const;
};
} }
class Unk_BgDispHandle;
// (Unk_GFxHandleObj is Unk_GFxUIHal, gfxrenderer2d.h; the display call is Unk_GFxUIRenderer2D::Display.)
// The display handle copy of the movie (vfunc_9): a ref-counted pointer, wrapped twice (0x14127c160 <- 0x14127c3d0 <- 0x14127c130).
class Unk_BgHandleRef
{
public:
    Unk_BgHandleRef(const Unk_BgHandleRef& r);                              // 0x14127c160
    Scaleform::RefCountImpl* m_p;                                           // the handle data (RefCountImpl AddRef 0x14257dc30)
};
class Unk_BgDispBase : public Unk_BgHandleRef
{
public:
    Unk_BgDispBase(const Unk_BgDispBase& r);                                // 0x14127c3d0
};
class Unk_BgDispHandle : public Unk_BgDispBase
{
public:
    Unk_BgDispHandle(const Unk_BgDispHandle& r);                            // 0x14127c130
    ~Unk_BgDispHandle();                                                    // 0x14127c530
    void* FUN_142580250();
    void* GetObj();                                                         // 0x14127cc80
};
