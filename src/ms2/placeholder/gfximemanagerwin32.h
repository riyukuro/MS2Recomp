// gfximemanagerwin32.h - PLACEHOLDER for Scaleform's Win32 IME manager (GFx 4.1.18 GFx::IME::GFxIMEManagerWin32, 0xc8
// bytes, base GFx::IMEManagerBase; no RTTI in the exe). The partial 4.1.19 SDK in work/scaleform has no header for it, so
// only what the game calls is declared: the ctor (out of line in the Scaleform lib, 0x1423c8a50). GFxManager::
// FUN_1422b1820 creates it and sets it on the loader. NOT an SDK header.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"
#include "GFx/IME/GFx_IMEManager.h"

namespace Scaleform { namespace GFx { namespace IME {

class GFxIMEManagerWin32 : public IMEManagerBase
{
public:
    explicit GFxIMEManagerWin32(HWND hWnd);                         // 0x1423c8a50

    // the Win32 members (window, IME context, candidate state); only +0x84 is read by the game
    void* m_pad68[(0x80 - sizeof(IMEManagerBase)) / sizeof(void*)];
    UInt32 m_80;
    UInt32 m_dwConversionMode;                                      // +0x84 (GFxManager::FUN_1422af8a0; 0x1000000 = none)
    void* m_pad88[(0xc8 - 0x88) / sizeof(void*)];
};

}}}

MS2_CHECK_OFFSET(Scaleform::GFx::IME::GFxIMEManagerWin32, m_dwConversionMode, 0x84);
MS2_CHECK_SIZE(Scaleform::GFx::IME::GFxIMEManagerWin32, 0xc8);
