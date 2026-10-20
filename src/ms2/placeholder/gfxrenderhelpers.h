// gfxrenderhelpers.h - PLACEHOLDER for the GFx UI library's inline render helpers (their COMDATs sit in
// ?\asmousecursor.cpp's tail 0x1422cf060-0x1422cf170, the first obj that used them; the caller there was dropped by
// /OPT:REF). Written here as plain functions of that unit. NOT an original header; the helper names are invented (Ghidra's FUN_<va> kept). Other units declare
// some of them locally with stand-in return types (ugcmanager_1.cpp, gfxmoviebackground.cpp, asyncimageloader.cpp).
#pragma once

#include <d3d9.h>

#include <NiDX9Renderer.h>

#include "ms2/placeholder/gfxservice.h"

// The GFx renderer's HAL (exe D3D9::HAL, 0xa7a0 bytes; the SDK's Render::HAL slot list does not match the exe). Only
// the slot the helpers call is typed.
class Unk_GFxUIHal
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
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
};

// Scaleform's Render::Renderer2D (SDK code; only the accessor the helpers call).
class Unk_GFxUIRenderer2D
{
public:
    Unk_GFxUIHal* FUN_1425822a0();                                  // GetHAL(): pImpl (+0x10) -> HAL (+0x50)
};

// The GFx UI manager singleton (getter 0x14025e7a0; its class is in the library's first obj, 0x1422b0060-0x1422b7f20).
class Unk_GFxUIManager
{
public:
    Unk_GFxUIRenderer2D* FUN_1422b02b0();                           // the movie renderer (+0x40 member, slot 2)
};
Unk_GFxUIManager* FUN_14025e7a0();

// The helpers (defined in asmousecursor.cpp; in the exe they are inline COMDATs of that obj's tail).
Unk_GFxUIRenderer2D* FUN_1422cf080();                               // the UI's Renderer2D
Unk_GFxUIHal* FUN_1422cf060();                                      // the UI renderer's HAL (gfxmoviebackground.cpp)
NiDX9Renderer* FUN_1422cf0a0();                                     // the Gamebryo renderer as an NiDX9Renderer
LPDIRECT3DDEVICE9 FUN_1422cf0d0();                                  // its D3D device (ugcmanager_1.cpp)
void* FUN_1422cf0f0();                                              // the UI render context (asyncimageloader.cpp)
int FUN_1422cf120();                                                // 1 while the device is lost or screen capture is blocked
