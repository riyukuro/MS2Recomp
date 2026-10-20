// gfxclipboard.h - PLACEHOLDER for GFxClipboard (RTTI .?AVGFxClipboard@@, base Scaleform::GFx::TextClipboard, 0x40 bytes,
// vftable 0x1431095b8 with 5 slots: ??_G 0x1422b4d00, the SDK's GetText / GetStyledText, ContainsRichText (SDK inline,
// COMDAT 0x1422b5300), OnTextStore 0x1422ecd70). NOT an original header. The ctor / dtor live in the GFx UI manager's
// obj (?\gfxmanager.cpp); OnTextStore is defined in ?\gfxvideo.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"

class GFxClipboard : public Scaleform::GFx::TextClipboard
{
public:
    // The ctor / dtor are implicit: GFxManager::FUN_1422b1030 value-initialises `new GFxClipboard()` (memset 0x40, then the
    // ctor COMDAT 0x1422b33a0); ??_G 0x1422b4d00.
    // Copies the text to the Windows clipboard (CF_UNICODETEXT) when the GFx UI manager allows it.
    virtual void OnTextStore(const wchar_t* ptext, Scaleform::UPInt len);   // 4 0x1422ecd70
};
MS2_CHECK_SIZE(GFxClipboard, 0x40);
