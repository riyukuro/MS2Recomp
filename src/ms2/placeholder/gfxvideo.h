// gfxvideo.h - PLACEHOLDER for GFxVideo (RTTI .?AVGFxVideo@@, bases NiRefObject / efd::MemObject, 0x28 bytes, vftable
// 0x143116e90 with 2 slots: ??_G 0x1422ecc50, NiRefObject::DeleteThis). NOT an original header. Recovered with
// ?\gfxvideo.cpp (src/ms2/gfxui/gfxvideo.cpp).
//
// The game's Scaleform video state: a VideoPC with the game's DirectSound video sound system, set on a GFx loader.
// Include it after `#define GFX_USE_VIDEO_WIN32` (see sfvideo.h).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/sfvideo.h"

#include <NiRefObject.h>

class GFxVideo : public NiRefObject
{
public:
    GFxVideo();                                                                         // 0x1422ec360
    virtual ~GFxVideo();                                                                // 0x1422ec3d0
    // Creates the video system (texture manager, sound system) and sets it on pLoader; returns 1.
    int FUN_1422ec460(IDirectSound8* pDS8, Scaleform::GFx::Loader* pLoader);
    void FUN_1422ec670();                                                               // drops the sound, pauses
    bool FUN_1422ec700(IDirectSound8* pDS8);                                            // (re)creates the sound system
    Scaleform::GFx::Video::Video* FUN_1422ec830();                                      // the video system
    Scaleform::GFx::Video::VideoDecoder* FUN_1422ec860();                               // its decoder (NULL if none)

private:
    MS2_LAYOUT_FRIEND;
    Scaleform::Ptr<Scaleform::GFx::Video::Video> m_spVideo;                             // +0x10
    Scaleform::Ptr<Scaleform::GFx::Video::MS2VideoSoundSystemDX8> m_spSoundSystem;      // +0x18
    Scaleform::Thread::ThreadPriority m_eDecodePriority;                                // +0x20 NormalPriority
};
MS2_CHECK_OFFSET(GFxVideo, m_spVideo, 0x10);
MS2_CHECK_OFFSET(GFxVideo, m_eDecodePriority, 0x20);
MS2_CHECK_SIZE(GFxVideo, 0x28);
