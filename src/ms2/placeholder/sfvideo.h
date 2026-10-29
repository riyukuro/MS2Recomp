// sfvideo.h - PLACEHOLDER for the Scaleform Video (CRI) classes the game uses. NOT an original header. The user-supplied
// 4.1.19 SDK has only GFx_VideoBase.h; Video / VideoPC / VideoDecoder / VideoSoundSystem follow the 4.3 SDK's
// Src/Video/Video_Video.h and Video_VideoPC.h (work/scaleform/4.3), whose layout matches the exe (new VideoPC is 0x70
// bytes; Video::pTextureManager +0x20, pDecoder +0x28, pSoundSystem +0x38). Declarations only: the Video library itself
// (AS2/AS3VideoSupport::CreateInstance 0x1400019f0 / 0x140002730, Video 0x14001c000..) is not recovered; VideoPC is in
// src/ms2/unnamed/unit_140002780.cpp.
//
// MS2VideoSoundSystemDX8 (RTTI .?AVMS2VideoSoundSystemDX8@Video@GFx@Scaleform@@, 0x20 bytes, vftable 0x14311b1c8 with 3
// slots) is the game's DirectSound video sound system, ?\ms2videosoundsystemdx8.cpp (0x1422fe810-0x142300880): the SDK's
// VideoSoundSystemDX8 sample, but it creates its own DirectSound device on a game window (HWND) and can re-initialize.
// VideoSound / VideoSoundStream carry the slots of the exe's video library, which was built with GFX_ENABLE_SOUND
// (GetSoundChannel / SetSpatialInfo, VideoSoundStream::pChannel); the sound channel is a stand-in here.
//
// The Video classes come from the recovered tree (scaleform/include/video: video_video.h, video_videopc.h,
// video_statebag.h); only MS2VideoSoundSystemDX8 is declared here.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"


#if defined(MS2_SF_VIDEO_VIDEO_H)
#error "sfvideo.h: include it before scaleform/include/video/video_video.h (it sets MS2_VIDEO_GAME_TU)"
#endif
#define MS2_VIDEO_GAME_TU           // the game's /Od copies keep the vftables of the video sound bases
#include "ms2/scaleform/include/video/video_video.h"
#include "ms2/scaleform/include/video/video_videopc.h"
#include "ms2/scaleform/include/video/video_statebag.h"


namespace Scaleform { namespace GFx { namespace Video {

// The game's DirectSound video sound system.
class MS2VideoSoundSystemDX8 : public VideoSoundSystem
{
public:
    MS2VideoSoundSystemDX8(HWND hWnd, MemoryHeap* pheap = Memory::GetGlobalHeap());   // 0x1422fe810
    ~MS2VideoSoundSystemDX8();                                              // 0x1422fe8b0
    virtual VideoSound* Create();                                           // 1 0x1422fe920
    bool FUN_1422fe9e0();                                                   // the DirectSound output is up
    bool FUN_1422fea10(HWND hWnd);                                          // (re)initializes it on hWnd, restores a lost buffer

private:
    MS2_LAYOUT_FRIEND;
    class MS2VideoSoundSystemDX8Impl* pImpl;                                // +0x18
};

}}} // namespace Scaleform::GFx::Video

MS2_CHECK_SIZE(Scaleform::GFx::Video::VideoPC, 0x70);
MS2_CHECK_SIZE(Scaleform::GFx::Video::MS2VideoSoundSystemDX8, 0x20);
MS2_CHECK_SIZE(Scaleform::GFx::Video::VideoSoundStream, 0x18);
