// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxVideo, the Scaleform video state of the GFx UI library,
// and GFxClipboard::OnTextStore.
// MS2-UNIT: ?\gfxvideo.cpp
// MS2-RANGE: 0x1422ec360-0x1422ece40 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// classes are declared in src/ms2/placeholder/gfxvideo.h, sfvideo.h (the Scaleform Video SDK part) and gfxclipboard.h.
// The queue range ran to 0x1422ed8c0; 0x1422ece40.. is GFxImageLoader::Protocol (?\gfximageloader.cpp).

// The Scaleform video declarations need GFX_ENABLE_VIDEO (GFxConfig.h): the exe is built with video support.
#define GFX_USE_VIDEO_WIN32

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/gfxclipboard.h"
#include "ms2/placeholder/gfxvideo.h"

#include "hook/ms2hook.h"

using Scaleform::GFx::Video::MS2VideoSoundSystemDX8;
using Scaleform::GFx::Video::Video;
using Scaleform::GFx::Video::VideoDecoder;
using Scaleform::GFx::Video::VideoPC;
using Scaleform::GFx::Video::VideoVMSupportAll;

// The GFx UI manager singleton (0x14025e7a0; its class lives in the library's first obj, 0x1422b0060-0x1422b7f20).
class Unk_GFxUIManager
{
public:
    int FUN_1422af580(int nOption);     // a manager option (2: the text copy goes to the Windows clipboard)
};
Unk_GFxUIManager* FUN_14025e7a0();

Scaleform::Render::TextureManager* FUN_1422cf0f0();   // the GFx renderer's texture manager

// StateBag::SetVideo of the exe's Scaleform 4.1.18 (COMDAT 0x1422ecd40): its State::StateType has one more entry before
// State_Video than the 4.1.19 headers (State_Video is 0x1e there, 0x1d in 4.1.19), so the SDK inline sets the wrong state.
inline void SetVideo418(Scaleform::GFx::StateBag* pStateBag, Scaleform::GFx::Video::VideoBase* pVideo)
{
    pStateBag->SetState((Scaleform::GFx::State::StateType)(Scaleform::GFx::State::State_Video + 1), pVideo);
}

// ---- GFxVideo -----------------------------------------------------------------------------------------------------------

// @0x1422ec360
GFxVideo::GFxVideo()
    : m_spVideo(NULL)
    , m_eDecodePriority(Scaleform::Thread::NormalPriority)
{
}

// @0x1422ec3d0
GFxVideo::~GFxVideo()
{
    m_spVideo = NULL;
    m_spSoundSystem = NULL;
}

// @0x1422ec460
int GFxVideo::FUN_1422ec460(HWND hWnd, Scaleform::GFx::Loader* pLoader)
{
    Scaleform::UInt32 affinityMask[3] = {0xffffffff, 0xffffffff, 0xffffffff};
    m_spVideo = *new VideoPC(VideoVMSupportAll(), m_eDecodePriority, 3, affinityMask);
    m_spVideo->SetTextureManager(FUN_1422cf0f0());
    m_spSoundSystem = *new MS2VideoSoundSystemDX8(hWnd, Scaleform::Memory::GetGlobalHeap());
    if (m_spSoundSystem->FUN_1422fe9e0())
        m_spVideo->SetSoundSystem(m_spSoundSystem);
    SetVideo418(pLoader, m_spVideo);
    return 1;
}
MS2_REPLACE_METHOD(0x1422EC460, GFxVideo, FUN_1422ec460, 511, 0x55EE505C);

// @0x1422ec670
void GFxVideo::FUN_1422ec670()
{
    m_spSoundSystem = NULL;
    if (m_spVideo)
    {
        VideoDecoder* pDecoder = m_spVideo->GetDecoder();
        if (pDecoder != NULL)
            pDecoder->PauseDecoding(true);
        m_spVideo->SetTextureManager(NULL);
    }
}
MS2_REPLACE_METHOD(0x1422EC670, GFxVideo, FUN_1422ec670, 138, 0x5F9876F6);

// @0x1422ec700
bool GFxVideo::FUN_1422ec700(HWND hWnd)
{
    if (!m_spSoundSystem)
        m_spSoundSystem = *new MS2VideoSoundSystemDX8(hWnd, Scaleform::Memory::GetGlobalHeap());
    if (!m_spSoundSystem->FUN_1422fe9e0() && m_spSoundSystem->FUN_1422fea10(hWnd))
    {
        m_spVideo->SetSoundSystem(m_spSoundSystem);
        return true;
    }
    return m_spSoundSystem->FUN_1422fe9e0();
}
MS2_REPLACE_METHOD(0x1422EC700, GFxVideo, FUN_1422ec700, 294, 0x00BAD35A);

// @0x1422ec830
Video* GFxVideo::FUN_1422ec830()
{
    return m_spVideo;
}
MS2_REPLACE_METHOD(0x1422EC830, GFxVideo, FUN_1422ec830, 31, 0xBE0AC345);

// @0x1422ec860
VideoDecoder* GFxVideo::FUN_1422ec860()
{
    if (m_spVideo)
        return m_spVideo->GetDecoder();
    return 0;
}
MS2_REPLACE_METHOD(0x1422EC860, GFxVideo, FUN_1422ec860, 65, 0x48503F42);

// ---- GFxClipboard -------------------------------------------------------------------------------------------------------

// @0x1422ecd70
void GFxClipboard::OnTextStore(const wchar_t* ptext, Scaleform::UPInt len)
{
    Scaleform::GFx::TextClipboard::OnTextStore(ptext, len);
    if (FUN_14025e7a0()->FUN_1422af580(2) == 0)
        return;
    if (OpenClipboard(NULL))
    {
        EmptyClipboard();
        HGLOBAL hMem = GlobalAlloc(GMEM_DDESHARE, len * 2 + 2);
        wchar_t* pText = (wchar_t*)GlobalLock(hMem);
        Scaleform::SFwcscpy(pText, len + 1, ptext);
        GlobalUnlock(hMem);
        SetClipboardData(CF_UNICODETEXT, hMem);
        CloseClipboard();
    }
}
MS2_REPLACE_METHOD(0x1422ECD70, GFxClipboard, OnTextStore, 190, 0xCD0D7D9E);

// MS2-PIN: ??_GGFxVideo@@UEAAPEAXI@Z 0x1422ecc50
