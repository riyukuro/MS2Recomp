// sfvideo.h - PLACEHOLDER for the Scaleform Video (CRI) classes the game uses. NOT an original header. The user-supplied
// 4.1.19 SDK has only GFx_VideoBase.h; Video / VideoPC / VideoDecoder / VideoSoundSystem follow the 4.3 SDK's
// Src/Video/Video_Video.h and Video_VideoPC.h (work/scaleform/4.3), whose layout matches the exe (new VideoPC is 0x70
// bytes; Video::pTextureManager +0x20, pDecoder +0x28, pSoundSystem +0x38). Declarations only: the Video library itself
// (VideoPC ctor 0x140002780, AS2/AS3VideoSupport::CreateInstance 0x1400019f0 / 0x140002730) is not recovered.
//
// MS2VideoSoundSystemDX8 (RTTI .?AVMS2VideoSoundSystemDX8@Video@GFx@Scaleform@@, 0x20 bytes, vftable 0x14311b1c8 with 3
// slots) is the game's DirectSound video sound system, ?\ms2videosoundsystemdx8.cpp (0x1422fe810-0x142300880).
//
// The SDK compiles the video declarations only with GFX_ENABLE_VIDEO, which GFxConfig.h derives from
// GFX_USE_VIDEO_WIN32: define that before the first Scaleform include of the TU.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"

#if !defined(GFX_ENABLE_VIDEO)
#error "sfvideo.h: #define GFX_USE_VIDEO_WIN32 before the first Scaleform include of the TU"
#endif

#include "Kernel/SF_Threads.h"
#include "GFx/GFx_VideoBase.h"

struct IDirectSound8;

namespace Scaleform { namespace GFx { namespace Video {

class VideoPlayer;
class VideoReaderConfig;
class VideoSound;

// Video ActionScript VM support: AS2, AS3 or both.
struct VideoVMSupport
{
    AS2VideoSupport* pAS2VSupport;
    AS3VideoSupport* pAS3VSupport;

protected:
    VideoVMSupport(AS2VideoSupport* pas2, AS3VideoSupport* pas3)
        : pAS2VSupport(pas2), pAS3VSupport(pas3) {}
};

struct VideoVMSupportAll : public VideoVMSupport
{
    VideoVMSupportAll() : VideoVMSupport(AS2VideoSupport::CreateInstance(), AS3VideoSupport::CreateInstance()) {}
};

class VideoDecoder : public RefCountBaseNTS<VideoDecoder, Stat_Video_Mem>
{
public:
    virtual void StartDecoding(VideoPlayer*) = 0;
    virtual void StopDecoding(VideoPlayer*) = 0;
    virtual bool IsDecodingStopped(VideoPlayer*) = 0;
    virtual bool ExecuteDecode(VideoPlayer*) = 0;
    virtual void GetReadBufferInfo(void* pInfos) = 0;          // Array<VideoPlayer::ReadBufferInfo>& (not declared here)
    virtual bool IsIORequired() const = 0;
    virtual void PauseDecoding(bool) = 0;                       // 7
    virtual void SetUsableProcessors(int) {}
};

class VideoSoundSystem : public RefCountBaseNTS<VideoSoundSystem, Stat_Video_Mem>
{
public:
    VideoSoundSystem(MemoryHeap* pheap) : pHeap(pheap) {}
    virtual ~VideoSoundSystem() {}
    virtual VideoSound* Create() = 0;
    virtual void Update() {}
    MemoryHeap* GetHeap() const { return pHeap; }

protected:
    MemoryHeap* pHeap;                  // +0x10
};

class Video : public VideoBase
{
public:
    Video(const VideoVMSupport& vmSupport, Thread::ThreadPriority decodeThreadPriority = Thread::NormalPriority,
          bool autoInit = true);
    ~Video();

    virtual AS2VideoSupport* GetAS2Support() const;
    virtual AS3VideoSupport* GetAS3Support() const;
    virtual VideoPlayer* CreateVideoPlayer(MemoryHeap*, TaskManager*, FileOpenerBase*, Log*);
    virtual void SetReadCallback(ReadCallback*);
    virtual bool IsIORequired() const;
    virtual void EnableIO(bool enable);
    virtual void ReadDefineVideoStreamTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual void ApplySystemSettings(VideoPlayer*);
    virtual void ApplySystemSettings(VideoDecoder*);
    virtual void ApplySystemSettings(VideoReaderConfig*);

    void SetTextureManager(Render::TextureManager* ptexman) { pTextureManager = ptexman; }
    virtual Render::TextureManager* GetTextureManager() const;
    virtual MemoryHeap* GetHeap() const;

    void SetSoundSystem(VideoSoundSystem* psoundSystem) { pSoundSystem = psoundSystem; }
    VideoSoundSystem* GetSoundSystem() const { return pSoundSystem; }

    VideoDecoder* GetDecoder() { return pDecoder; }
    VideoReaderConfig* GetReaderConfig() { return pReaderConfig; }

protected:
    Ptr<MemoryHeap> pHeap;                          // +0x18
    Ptr<Render::TextureManager> pTextureManager;    // +0x20
    Ptr<VideoDecoder> pDecoder;                     // +0x28
    Ptr<VideoReaderConfig> pReaderConfig;           // +0x30
    Ptr<VideoSoundSystem> pSoundSystem;             // +0x38
    Ptr<ReadCallback> pReadCallback;                // +0x40
    Thread::ThreadPriority DecodeThreadPriority;    // +0x48
    AS2VideoSupport* pAS2VSupport;                  // +0x50
    AS3VideoSupport* pAS3VSupport;                  // +0x58
};

class VideoPC : public Video
{
public:
    VideoPC(const VideoVMSupport& vmSupport, Thread::ThreadPriority decodingThreadsPriority = Thread::NormalPriority,
            int decodingThreadsNumber = 3, UInt32* affinityMask = NULL);    // 0x140002780

    virtual void ApplySystemSettings(VideoPlayer* pvideoPlayer);
    virtual void ApplySystemSettings(VideoDecoder*);
    virtual void ApplySystemSettings(VideoReaderConfig*);

private:
    int DecodingThreadNumber;           // +0x60
    UInt32 AffinityMask[3];             // +0x64
};

// The game's DirectSound video sound system.
class MS2VideoSoundSystemDX8 : public VideoSoundSystem
{
public:
    MS2VideoSoundSystemDX8(IDirectSound8* pds8, MemoryHeap* pheap = Memory::GetGlobalHeap());   // 0x1422fe810
    ~MS2VideoSoundSystemDX8();
    virtual VideoSound* Create();
    bool FUN_1422fe9e0();                           // the DirectSound output is up
    bool FUN_1422fea10(IDirectSound8* pds8);        // (re)initializes the output on a DirectSound device

private:
    MS2_LAYOUT_FRIEND;
    void* m_pImpl;                      // +0x18 (VideoSoundSystemDX8Impl in the SDK sample)
};

}}} // namespace Scaleform::GFx::Video

MS2_CHECK_SIZE(Scaleform::GFx::Video::VideoPC, 0x70);
MS2_CHECK_SIZE(Scaleform::GFx::Video::MS2VideoSoundSystemDX8, 0x20);
