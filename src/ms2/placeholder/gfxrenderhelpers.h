// gfxrenderhelpers.h - PLACEHOLDER for the GFx UI library's inline render helpers (their COMDATs sit in
// ?\asmousecursor.cpp's tail 0x1422cf060-0x1422cf170, the first obj that used them; the caller there was dropped by
// /OPT:REF). Written here as plain functions of that unit. NOT an original header; the helper names are invented (Ghidra's FUN_<va> kept). Other units declare
// some of them locally with stand-in return types (ugcmanager_1.cpp, gfxmoviebackground.cpp, asyncimageloader.cpp).
#pragma once

#include <d3d9.h>

#include <NiDX9Renderer.h>

#include "ms2/placeholder/gfxservice.h"
#include "ms2/placeholder/gfxrenderer2d.h"         // Unk_GFxUIHal, Unk_GFxUIRenderer2D

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
