// gfximemanagerwin32.h - Scaleform's Win32 IME manager (GFx 4.1.18 GFx::IME::GFxIMEManagerWin32, 0xc8 bytes, base
// GFx::IMEManagerBase; no RTTI in the exe) for the game units. The class is the recovered one of the Scaleform units
// (scaleform/include/gfx/gfx_imemanagerwin32.h, bodies in sfr_ime_01 / sfr_as2_01c). GFxManager::FUN_1422b1820
// creates it (the ctor 0x1423c8a50) and sets it on the loader; FUN_1422af8a0 reads m_dwConversionMode (+0x84).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/scaleform/include/gfx/gfx_imemanagerwin32.h"

MS2_CHECK_OFFSET(Scaleform::GFx::IME::GFxIMEManagerWin32, m_dwConversionMode, 0x84);
MS2_CHECK_SIZE(Scaleform::GFx::IME::GFxIMEManagerWin32, 0xc8);
