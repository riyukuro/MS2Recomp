// gfximageloader.h - PLACEHOLDER for GFxImageLoader (RTTI .?AVGFxImageLoader@@, base Scaleform::GFx::ImageCreator, 0x88
// bytes, vftable 0x1431170b0 with 6 slots). NOT an original header. Recovered with ?\gfximageloader.cpp
// (src/ms2/gfxui/gfximageloader.cpp).
//
// The game's Scaleform image creator. LoadProtocolImage (slot 1) resolves "img://" urls through a Protocol:
//   img://ugc:<rest>                  type 0 ugc image, <rest> is the path
//   img://icon:<path>                 type 1 icon file, loaded by LoadImageFile
//   img://keepMem:<path>              type 4 file kept in the GFx UI manager's memory-file cache (FUN_1422edd80)
//   img://emoticon:<path>             type 5 handed to the image callback (m_fnCallback)
//   img://<movie>:webBrowser/<w>/<h>  type 0 \
//   img://<movie>:faceView|cube/<w>/<h>  type 2  > a w x h render image created here and handed to the named UI movie
//   img://<movie>:avatar/<w>/<h>/<x>  type 2  |   (UISwfEntity vfunc_25)
//   img://<movie>:screenShot          type 3 / the size of the GFx UI manager's screen-shot view
// Slots: 0 ??_G 0x1422eecb0, 1 LoadProtocolImage 0x1422ed950, 2-4 the SDK's LoadImageFile / LoadExportedImage /
// CreateImage, 5 GetBindKey (SDK inline, COMDAT 0x1422eee80).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/tfunctor2.h"

#if defined(MS2_HAVE_SCALEFORM_SDK)
#include "GFx/GFx_ImageCreator.h"
#endif

class GFxImageLoader : public Scaleform::GFx::ImageCreator
{
public:
    // A parsed "img://" url (0x28 bytes).
    class Protocol
    {
    public:
        Protocol();                                                     // 0x1422ece40
        // ~Protocol() is implicit (COMDAT 0x1422eeb20)
        int Parse(const Scaleform::String& strUrl);                     // 0x1422eced0: 0 when the url is not usable
        CString Token(CString& str, CString strDelim);                  // 0x1422ed7a0: cuts the text before strDelim

        int m_nWidth;                   // +0x00
        int m_nHeight;                  // +0x04
        CString m_strPath;              // +0x08 the image name / file path (or the view kind for the movie images)
        CString m_strHost;              // +0x10 the scheme ("ugc", "icon", "keepMem", "emoticon") or the movie name
        CString m_strExtra;             // +0x18 the avatar image's extra token
        int m_nType;                    // +0x20 0 ugc / web, 1 icon, 2 view, 3 screen shot, 4 keepMem, 5 emoticon
    };

    typedef TFunctor<Scaleform::Render::Image*, ParamList<const Protocol&,
        ParamList<Scaleform::Render::TextureManager*, EmptyParam>>> ImageCallback;

    GFxImageLoader(Scaleform::Render::TextureManager* pTextureManager);    // 0x1422ed8c0
    virtual Scaleform::Render::Image* LoadProtocolImage(const Scaleform::GFx::ImageCreateInfo& info,
        const Scaleform::String& url);                                      // 1 0x1422ed950
    // The keepMem loader: LoadImageFile through the GFx UI manager's memory-file cache.
    Scaleform::Render::Image* FUN_1422edd80(const Scaleform::GFx::ImageCreateInfo& info, const Scaleform::String& url);
    // m_fnCallback = fn (inline COMDAT 0x1422b7890 in ?\gfxmanager.cpp; fn by value: the callee destroys it).
    void FUN_1422b7890(ImageCallback fn) { m_fnCallback = fn; }

private:
    MS2_LAYOUT_FRIEND;
    CRBMap<__int64, CString> m_map20;                       // +0x20 (only constructed / destroyed in the unit)
    CRBMap<CString, Scaleform::String> m_map50;             // +0x50 (only constructed / destroyed in the unit)
    ImageCallback m_fnCallback;                             // +0x80 the emoticon image callback
};
MS2_CHECK_OFFSET(GFxImageLoader, m_map20, 0x20);
MS2_CHECK_OFFSET(GFxImageLoader, m_map50, 0x50);
MS2_CHECK_OFFSET(GFxImageLoader, m_fnCallback, 0x80);
MS2_CHECK_SIZE(GFxImageLoader, 0x88);
MS2_CHECK_SIZE(GFxImageLoader::Protocol, 0x28);
