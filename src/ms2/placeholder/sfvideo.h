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

namespace Scaleform { namespace GFx { namespace Video {

class VideoPlayer;
class VideoReaderConfig;
class VideoSound;

// Scaleform::Sound::SoundChannelSystem of the video library (Sound::SoundChannel slots; GFX_ENABLE_SOUND is off here).
class Unk_VideoSoundChannel : public RefCountBase<Unk_VideoSoundChannel, Stat_Video_Mem>
{
public:
    virtual void* GetSoundRenderer() const = 0;
    virtual void* GetSample() const = 0;
    virtual void Stop() = 0;
    virtual void Pause(bool) = 0;
    virtual bool IsPlaying() const = 0;
    virtual void SetPosition(float) = 0;
    virtual float GetPosition() = 0;
    virtual void Loop(int, float, float) = 0;
    virtual float GetVolume() = 0;                              // 9
};

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

class VideoSound : public RefCountBaseNTS<VideoSound, Stat_Video_Mem>
{
public:
    enum PCMFormat
    {
        PCM_SInt16,
        PCM_Float
    };
    enum Status
    {
        Sound_Stopped,
        Sound_Playing,
        Sound_Paused,
        Sound_Error
    };
    enum
    {
        MaxChannels = 8
    };
    class PCMStream
    {
    public:
        virtual ~PCMStream() {}
        virtual UInt32 GetDataSInt16(UInt32 nch, SInt16* pcmbuf[], UInt32 samplesRequested) = 0;
        virtual UInt32 GetDataFloat(UInt32 nch, float* pcmbuf[], UInt32 samplesRequested) = 0;
    };

    virtual ~VideoSound() {}
    virtual bool CreateOutput(UInt32 channels, UInt32 samplerate) = 0;     // 1
    virtual void DestroyOutput() = 0;
    virtual PCMFormat GetPCMFormat() const = 0;
    virtual void Start(PCMStream* pstream) = 0;
    virtual void Stop() = 0;
    virtual void Pause(bool paused) = 0;
    virtual Status GetStatus() const = 0;
    virtual void GetTime(UInt64* count, UInt64* unit) const = 0;           // 8
    virtual Unk_VideoSoundChannel* GetSoundChannel() = 0;                   // 9
    virtual void SetSpatialInfo(const void* spatinfo) = 0;                 // 10 (const Array<SoundChannel::Vector>[])
};

class VideoSoundStream : public VideoSound
{
public:
    VideoSoundStream();
    virtual ~VideoSoundStream();                                            // 0x140002ab0
    virtual void SetVolume(float volume) = 0;                               // 11
    virtual float GetVolume() = 0;                                          // 12
    virtual Unk_VideoSoundChannel* GetSoundChannel();                       // 9 0x140002b00
    virtual void SetSpatialInfo(const void*) {}                             // 10

protected:
    Ptr<Unk_VideoSoundChannel> pChannel;                                    // +0x10
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

    virtual AS2VideoSupport* GetAS2Support() const { return pAS2VSupport; }     // VideoPC copy 0x140002800
    virtual AS3VideoSupport* GetAS3Support() const { return pAS3VSupport; }     // VideoPC copy 0x140002810
    virtual VideoPlayer* CreateVideoPlayer(MemoryHeap*, TaskManager*, FileOpenerBase*, Log*);
    virtual void SetReadCallback(ReadCallback*);
    virtual bool IsIORequired() const;
    virtual void EnableIO(bool enable);
    virtual void ReadDefineVideoStreamTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual void ApplySystemSettings(VideoPlayer*);
    virtual void ApplySystemSettings(VideoDecoder*);
    virtual void ApplySystemSettings(VideoReaderConfig*);

    void SetTextureManager(Render::TextureManager* ptexman) { pTextureManager = ptexman; }
    virtual Render::TextureManager* GetTextureManager() const { return pTextureManager; }   // VideoPC copy 0x1400028b0
    virtual MemoryHeap* GetHeap() const { return pHeap; }                       // VideoPC copy 0x1400028c0

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

    virtual void ApplySystemSettings(VideoPlayer* pvideoPlayer);                // 12 0x140002850
    virtual void ApplySystemSettings(VideoDecoder*) {}                          // 11 0x140002820
    virtual void ApplySystemSettings(VideoReaderConfig*) {}                     // 10 0x140002830

private:
    int DecodingThreadNumber;           // +0x60
    UInt32 AffinityMask[3];             // +0x64
};

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
