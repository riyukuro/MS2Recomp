// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform::GFx::Video::MS2VideoSoundSystemDX8, the game's
// DirectSound video sound system, and its sound stream MS2VideoSoundDX8.
// MS2-UNIT: ?\ms2videosoundsystemdx8.cpp
// MS2-RANGE: 0x1422fe810-0x142300880 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). A copy of
// the Scaleform SDK sample Video_VideoSoundSystemDX8.cpp (work/scaleform/4.3, same code in the 4.1 SDKs) with the game's
// changes: the system creates its own DirectSound device on a game window (Impl::Init(HWND)), can re-initialize and
// restore a lost primary buffer (FUN_1422fea10), and the sound thread first calls a game hook (DAT_143b15f88). The video
// library was built with GFX_ENABLE_SOUND: CreateOutput ends with SetVolume(pChannel->GetVolume()).

// The Scaleform video declarations need GFX_ENABLE_VIDEO (GFxConfig.h): the exe is built with video support.
#define GFX_USE_VIDEO_WIN32

#include "ms2/placeholder/ms2stdafx.h"

#include <cmath>
#include <process.h>
#include <mmsystem.h>
#include <dsound.h>
#include <ks.h>
#include <ksmedia.h>

#include "ms2/placeholder/sfvideo.h"
#include "Kernel/SF_HeapNew.h"

#include "hook/ms2hook.h"

// The GFx UI library is built with /fp:precise (IEEE-ordered float compares); the per-unit build uses the game's /fp:fast.
#pragma float_control(precise, on)
#pragma function(memset)                // ZeroMemory / memset are CRT calls in the exe

extern void (*DAT_143b15f88)();         // called once on every video sound thread before its loop (set by the game)

namespace Scaleform { namespace GFx { namespace Video {

class MS2VideoSoundDX8 : public VideoSoundStream
{
public:
    MS2VideoSoundDX8(MemoryHeap* pheap, IDirectSound8* ds);
    virtual ~MS2VideoSoundDX8();

    virtual bool CreateOutput(UInt32 channel, UInt32 samplerate);
    virtual void DestroyOutput();
    virtual PCMFormat GetPCMFormat() const { return PCM_Float; }
    virtual void Start(PCMStream* pstream);
    virtual void Stop();
    virtual Status GetStatus() const { return SoundStatus; }
    virtual void Pause(bool sw);
    virtual void GetTime(UInt64* count, UInt64* unit) const;

    // Normalized value (0.0f - 1.0f)
    virtual void SetVolume(float volume);
    virtual float GetVolume() { return Volume; }

    // Variables borrowed from CRI CriSmpMvSoundPc
    static const UInt32 NSMPL_BLK = 128;
    static const UInt32 BUF_NSMPL = 3200;
    static const UInt32 PLAY_THRESHOLD = 800;
    static const UInt32 MAX_NUM_SPEAKERS = 6;
    static const UInt32 DEFAULT_SRATE = 48000;

private:
    MemoryHeap* pHeap;                  // +0x18
    PCMStream* pPCMStream;              // +0x20
    UInt32 ChannelCount;                // +0x28
    Status SoundStatus;                 // +0x2c
    UInt64 TotalSamples;                // +0x30
    UInt64 SampleRate;                  // +0x38
    float Volume;                       // +0x40

    // PC specific members
    LPDIRECTSOUND8 pDS8;                // +0x48 DirectSound
    LPDIRECTSOUNDBUFFER pDSBuffer;      // +0x50 DirectSound secondary sound buffer
    UInt32 pRead;                       // +0x58 Read pointer (SAMPLE)
    UInt32 pWrite;                      // +0x5c Write pointer (SAMPLE)
    UInt32 ndata;                       // +0x60 Number of samples in the buffer
    UInt32 nch;                         // +0x64 Number of channels
    float sample_buffer[MaxChannels][BUF_NSMPL];   // +0x68 Sample buffer for receiving from App
    CRITICAL_SECTION cs;                // +0x19068
    bool cs_initialized;                // +0x19090
    HANDLE hevent;                      // +0x19098
    HANDLE hthread;                     // +0x190a0
    unsigned int thread_id;             // +0x190a8
    UINT timer_id;                      // +0x190ac
    volatile bool thread_exit_flag;     // +0x190b0

private:
    static unsigned WINAPI SoundOutputTimerProc(LPVOID param);
    void ExecuteAudioFrame(void);
    UInt32 GetSoundData(UInt32 nch, float* sample[], UInt32 nsmpl);

protected:
    inline SInt16 PcmfToPcm16(float pcmf)
    {
        if ((pcmf > -1.0f) && (pcmf <= 1.0f))
            return (SInt16)(pcmf * 32767.0f);
        else if (pcmf > 1.0f)
            return 32767;
        else
            return -32768;
    }

    inline SInt32 LinearToDecibel(float linear)
    {
        SInt32 decibel;
        if (linear >= 1.0f)
            decibel = DSBVOLUME_MAX;
        else if (linear > 0.00001f)
            decibel = ((SInt32)(2000.0f * log10(linear)));
        else
            decibel = DSBVOLUME_MIN;
        return decibel;
    }
};

class MS2VideoSoundSystemDX8Impl : public NewOverrideBase<StatMD_Other_Mem>
{
public:
    MS2VideoSoundSystemDX8Impl(HWND hWnd)
    {
        Init(hWnd);
    }
    ~MS2VideoSoundSystemDX8Impl()
    {
        Finalize();
    }

    void Init(HWND hWnd)
    {
        InitializedByUs = false;

        HRESULT hr;
        hr = DirectSoundCreate8(NULL, &pDS8.GetRawRef(), NULL);
        if (FAILED(hr))
        {
            Finalize();
            return;
        }
        hr = pDS8->SetCooperativeLevel(hWnd, DSSCL_EXCLUSIVE);
        if (FAILED(hr))
        {
            Finalize();
            return;
        }

        // Create the primary sound buffer
        DSBUFFERDESC dsbdesc;
        ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
        dsbdesc.dwSize = sizeof(DSBUFFERDESC);
        dsbdesc.dwFlags = DSBCAPS_PRIMARYBUFFER;
        hr = pDS8->CreateSoundBuffer(&dsbdesc, &pDSBPrimary.GetRawRef(), NULL);
        if (FAILED(hr))
        {
            Finalize();
            return;
        }

        // Set the format of the primary buffer: 5.1ch 48 kHz, else stereo 44.1 kHz
        WAVEFORMATEX wfx;
        ZeroMemory(&wfx, sizeof(WAVEFORMATEX));
        wfx.wFormatTag = WAVE_FORMAT_PCM;
        wfx.nChannels = MS2VideoSoundDX8::MAX_NUM_SPEAKERS;
        wfx.nSamplesPerSec = MS2VideoSoundDX8::DEFAULT_SRATE;
        wfx.wBitsPerSample = 16;
        wfx.nBlockAlign = wfx.wBitsPerSample / 8 * wfx.nChannels;
        wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;
        hr = pDSBPrimary->SetFormat(&wfx);
        if (FAILED(hr))
        {
            wfx.nChannels = 2;
            wfx.nSamplesPerSec = 44100;
            wfx.wBitsPerSample = 16;
            wfx.nBlockAlign = wfx.wBitsPerSample / 8 * wfx.nChannels;
            wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;
            hr = pDSBPrimary->SetFormat(&wfx);
            if (SUCCEEDED(hr))
                InitializedByUs = true;
            else
                Finalize();
        }
        else
            InitializedByUs = true;
    }

    void Finalize(void)
    {
        pDSBPrimary = 0;
        pDS8 = 0;
    }

    IDirectSound8* GetDirectSound() const
    {
        if (InitializedByUs)
            return pDS8.GetPtr();
        return 0;
    }

    bool IsInitialized() const
    {
        return InitializedByUs;
    }

    // Restores the primary buffer after the device lost it (another application took the sound card).
    void RestoreLostBuffer()
    {
        if (pDSBPrimary)
        {
            DWORD status;
            pDSBPrimary->GetStatus(&status);
            if (status == DSBSTATUS_BUFFERLOST)
                pDSBPrimary->Restore();
        }
    }

protected:
    Ptr<IDirectSound8> pDS8;            // +0x00
    Ptr<IDirectSoundBuffer> pDSBPrimary;   // +0x08
    bool InitializedByUs;               // +0x10
};

// ---- MS2VideoSoundSystemDX8 ---------------------------------------------------------------------------------------------

// @0x1422fe810
MS2VideoSoundSystemDX8::MS2VideoSoundSystemDX8(HWND hWnd, MemoryHeap* pheap)
    : VideoSoundSystem(pheap)
{
    pImpl = SF_HEAP_NEW(pheap) MS2VideoSoundSystemDX8Impl(hWnd);
}

// @0x1422fe8b0
MS2VideoSoundSystemDX8::~MS2VideoSoundSystemDX8()
{
    delete pImpl;
}

// @0x1422fe920
VideoSound* MS2VideoSoundSystemDX8::Create()
{
    if (pImpl)
    {
        IDirectSound8* pds8 = pImpl->GetDirectSound();
        if (pds8)
            return SF_HEAP_NEW(GetHeap()) MS2VideoSoundDX8(GetHeap(), pds8);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422FE920, MS2VideoSoundSystemDX8, Create, 172, 0x28F60E3A);

// @0x1422fe9e0
bool MS2VideoSoundSystemDX8::FUN_1422fe9e0()
{
    return pImpl->IsInitialized();
}
MS2_REPLACE_METHOD(0x1422FE9E0, MS2VideoSoundSystemDX8, FUN_1422fe9e0, 28, 0x2753C1AE);

// @0x1422fea10
bool MS2VideoSoundSystemDX8::FUN_1422fea10(HWND hWnd)
{
    if (!pImpl->IsInitialized())
        pImpl->Init(hWnd);
    pImpl->RestoreLostBuffer();
    return pImpl->IsInitialized();
}
MS2_REPLACE_METHOD(0x1422FEA10, MS2VideoSoundSystemDX8, FUN_1422fea10, 87, 0xC6B70D8B);

// ---- MS2VideoSoundDX8 ---------------------------------------------------------------------------------------------------

// @0x1422fea70
MS2VideoSoundDX8::MS2VideoSoundDX8(MemoryHeap* pheap, IDirectSound8* pds)
    : pHeap(pheap), pPCMStream(0),
      ChannelCount(0), SoundStatus(Sound_Stopped),
      TotalSamples(0), SampleRate(0), Volume(1.0f)
{
    pDS8 = pds;
    pDSBuffer = 0;
    hevent = NULL;
    hthread = NULL;
    ZeroMemory(&cs, sizeof(cs));
    cs_initialized = FALSE;
    InitializeCriticalSection(&cs);
    cs_initialized = TRUE;
}

// @0x1422feb90
MS2VideoSoundDX8::~MS2VideoSoundDX8()
{
    if (cs_initialized)
    {
        DeleteCriticalSection(&cs);
        cs_initialized = FALSE;
    }
}

// @0x1422febf0
bool MS2VideoSoundDX8::CreateOutput(UInt32 channel, UInt32 samplerate)
{
    SoundStatus = Sound_Stopped;
    pDSBuffer = NULL;
    pRead = 0;
    pWrite = 0;
    ndata = 0;
    nch = MAX_NUM_SPEAKERS;
    ZeroMemory(&sample_buffer, sizeof(sample_buffer));
    hevent = NULL;
    hthread = NULL;
    thread_id = 0;
    timer_id = 0;
    thread_exit_flag = FALSE;

    if (channel == 0)
        return false;

    WAVEFORMATEXTENSIBLE wfext;
    WAVEFORMATEX* pwfex;
    ZeroMemory(&wfext, sizeof(wfext));
    pwfex = &wfext.Format;

    // Configure WAVEFORMATEX structure
    // NOTE: number of channels of secondary buffer is always MAX_NUM_SPEAKERS
    pwfex->wFormatTag = WAVE_FORMAT_EXTENSIBLE;
    pwfex->nChannels = (WORD)nch;
    pwfex->nSamplesPerSec = samplerate;
    pwfex->wBitsPerSample = 16;
    pwfex->nBlockAlign = pwfex->nChannels * pwfex->wBitsPerSample / 8;
    pwfex->nAvgBytesPerSec = pwfex->nBlockAlign * pwfex->nSamplesPerSec;
    pwfex->cbSize = sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX);

    // Configure WAVEFORMATEXTENSIBLE structure
    wfext.Samples.wValidBitsPerSample = pwfex->wBitsPerSample;
    wfext.dwChannelMask = KSAUDIO_SPEAKER_5POINT1;
    wfext.SubFormat = KSDATAFORMAT_SUBTYPE_PCM;

    // Create secondary sound buffer
    DSBUFFERDESC dsbdesc;
    ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
    dsbdesc.dwSize = sizeof(DSBUFFERDESC);
    dsbdesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_GLOBALFOCUS
                    | DSBCAPS_LOCDEFER | DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRLVOLUME;
    dsbdesc.dwBufferBytes = BUF_NSMPL * pwfex->nBlockAlign;
    dsbdesc.lpwfxFormat = (LPWAVEFORMATEX)&wfext;
    HRESULT hr = pDS8->CreateSoundBuffer(&dsbdesc, &pDSBuffer, NULL);
    if (FAILED(hr))
    {
        DestroyOutput();
        return false;
    }

    // Create event for timer
    hevent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (hevent == NULL)
    {
        DestroyOutput();
        return false;
    }
    timer_id = timeSetEvent(16, 0, (LPTIMECALLBACK)hevent, (DWORD)NULL, TIME_PERIODIC | TIME_CALLBACK_EVENT_PULSE);

    // Create thread for sound output
    hthread = (HANDLE)_beginthreadex(NULL, 0, SoundOutputTimerProc, this, CREATE_SUSPENDED, &thread_id);
    if (hthread == NULL)
    {
        DestroyOutput();
        return false;
    }
    SetThreadPriority(hthread, THREAD_PRIORITY_HIGHEST);
    ResumeThread(hthread);

    ChannelCount = channel;
    SampleRate = samplerate;

    SInt32 decibel = LinearToDecibel(Volume);
    EnterCriticalSection(&cs);
    if (pDSBuffer != NULL)
        pDSBuffer->SetVolume(decibel);
    LeaveCriticalSection(&cs);

    SetVolume(pChannel->GetVolume());
    return true;
}
MS2_REPLACE_METHOD(0x1422FEBF0, MS2VideoSoundDX8, CreateOutput, 1228, 0x6A83B915);

// @0x1422ff0d0
void MS2VideoSoundDX8::DestroyOutput()
{
    if (hthread)
    {
        thread_exit_flag = TRUE;
        WaitForSingleObject(hthread, INFINITE);
        CloseHandle(hthread);
        hthread = NULL;
    }
    if (hevent)
    {
        timeKillEvent(timer_id);
        CloseHandle(hevent);
        hevent = NULL;
    }
    if (pDSBuffer != NULL)
    {
        pDSBuffer->Release();
        pDSBuffer = NULL;
    }
    ChannelCount = 0;
    SoundStatus = Sound_Stopped;
    TotalSamples = 0;
}
MS2_REPLACE_METHOD(0x1422FF0D0, MS2VideoSoundDX8, DestroyOutput, 250, 0x79E7AE40);

// @0x1422ff1d0
void MS2VideoSoundDX8::Start(PCMStream* pstream)
{
    EnterCriticalSection(&cs);
    pPCMStream = pstream;
    SoundStatus = Sound_Playing;
    SetVolume(Volume);
    LeaveCriticalSection(&cs);
    TotalSamples = 0;
}
MS2_REPLACE_METHOD(0x1422FF1D0, MS2VideoSoundDX8, Start, 124, 0x5896E9CA);

// @0x1422ff260
void MS2VideoSoundDX8::Stop()
{
    EnterCriticalSection(&cs);
    SoundStatus = Sound_Stopped;
    pPCMStream = 0;
    LeaveCriticalSection(&cs);
    TotalSamples = 0;
}
MS2_REPLACE_METHOD(0x1422FF260, MS2VideoSoundDX8, Stop, 92, 0xF0C39F44);

// @0x1422ff2d0
void MS2VideoSoundDX8::Pause(bool sw)
{
    EnterCriticalSection(&cs);
    if (sw)
    {
        if (SoundStatus == Sound_Playing)
            SoundStatus = Sound_Paused;
    }
    else
    {
        if (SoundStatus == Sound_Paused)
            SoundStatus = Sound_Playing;
    }
    LeaveCriticalSection(&cs);
}
MS2_REPLACE_METHOD(0x1422FF2D0, MS2VideoSoundDX8, Pause, 115, 0x7D5845AD);

// @0x1422ff350
void MS2VideoSoundDX8::GetTime(UInt64* count, UInt64* unit) const
{
    if (TotalSamples == 0)
    {
        *count = 0;
        *unit = 1000;
    }
    else
    {
        *count = TotalSamples * 1000 / SampleRate;
        *unit = 1000;
    }
}
MS2_REPLACE_METHOD(0x1422FF350, MS2VideoSoundDX8, GetTime, 98, 0x513EEF39);

// @0x1422ff3c0
void MS2VideoSoundDX8::SetVolume(float volume)
{
    Volume = volume;
    if (SoundStatus == Sound_Playing)
    {
        SInt32 decibel = LinearToDecibel(volume);
        EnterCriticalSection(&cs);
        if (pDSBuffer)
            pDSBuffer->SetVolume(decibel);
        LeaveCriticalSection(&cs);
    }
}
MS2_REPLACE_METHOD(0x1422FF3C0, MS2VideoSoundDX8, SetVolume, 147, 0x8A33E600);

// @0x1422ff460
unsigned WINAPI MS2VideoSoundDX8::SoundOutputTimerProc(LPVOID param)
{
    if (DAT_143b15f88 != NULL)
        DAT_143b15f88();
    MS2VideoSoundDX8* pthis = (MS2VideoSoundDX8*)param;
    while (pthis->thread_exit_flag == FALSE)
    {
        WaitForSingleObject(pthis->hevent, INFINITE);
        pthis->ExecuteAudioFrame();
    }
    return 0;
}

// @0x1422ff4d0
void MS2VideoSoundDX8::ExecuteAudioFrame()
{
    DWORD dsb_stat;
    float* sample[MaxChannels];
    UInt32 nsmpl, wsmpl;
    HRESULT hr;

    EnterCriticalSection(&cs);

    if (SoundStatus != Sound_Playing)
    {
        pDSBuffer->Stop();
        LeaveCriticalSection(&cs);
        return;
    }

    pDSBuffer->GetStatus(&dsb_stat);
    if (dsb_stat & DSBSTATUS_PLAYING)
    {
        UInt32 cpos, wpos;
        pDSBuffer->GetCurrentPosition(reinterpret_cast<LPDWORD>(&cpos), reinterpret_cast<LPDWORD>(&wpos));
        cpos /= nch * sizeof(SInt16);
        if (cpos >= pRead)
            ndata -= cpos - pRead;
        else
            ndata -= BUF_NSMPL - (pRead - cpos);
        pRead = cpos;
    }

    nsmpl = BUF_NSMPL - ndata;
    if (nsmpl > BUF_NSMPL)
        nsmpl = BUF_NSMPL;
    nsmpl = nsmpl / NSMPL_BLK * NSMPL_BLK;

    SInt16* pcmbuf[2];
    UInt32 bsize[2], bsmpl[2], i, j, k, n;
    for (i = 0; i < nch; i++)
        sample[i] = sample_buffer[i];
    wsmpl = GetSoundData(nch, sample, nsmpl);

    if (wsmpl > 0)
    {
        hr = pDSBuffer->Lock(pWrite * nch * sizeof(SInt16), wsmpl * nch * sizeof(SInt16),
                             (LPVOID*)&pcmbuf[0], reinterpret_cast<LPDWORD>(&bsize[0]),
                             (LPVOID*)&pcmbuf[1], reinterpret_cast<LPDWORD>(&bsize[1]), 0);
        if (FAILED(hr))
        {
            LeaveCriticalSection(&cs);
            return;
        }

        bsmpl[0] = bsize[0] / (nch * sizeof(SInt16));
        bsmpl[1] = bsize[1] / (nch * sizeof(SInt16));
        i = 0;
        for (k = 0; k < 2; k++)
        {
            for (j = 0; j < bsmpl[k]; j++)
            {
                static UInt32 ch_map[8] = {0, 1, 4, 5, 2, 3, 6, 7};
                if (i >= wsmpl)
                    break;
                for (n = 0; n < nch; n++)
                    pcmbuf[k][j * nch + n] = PcmfToPcm16(sample[ch_map[n]][i]);
                i++;
            }
        }

        if (i < bsmpl[0])
        {
            bsize[0] = i * (nch * sizeof(SInt16));
            bsize[1] = 0;
        }
        else if (i < bsmpl[0] + bsmpl[1])
            bsize[1] = (i - bsmpl[0]) * (nch * sizeof(SInt16));

        pDSBuffer->Unlock((LPVOID)pcmbuf[0], bsize[0], (LPVOID)pcmbuf[1], bsize[1]);
    }

    ndata += wsmpl;
    pWrite += wsmpl;
    if (pWrite >= BUF_NSMPL)
        pWrite = pWrite % BUF_NSMPL;

    if ((dsb_stat & DSBSTATUS_PLAYING) == 0)
    {
        if (ndata >= PLAY_THRESHOLD)
            pDSBuffer->Play(0, 0, DSBPLAY_LOOPING);
    }

    LeaveCriticalSection(&cs);
}

// @0x1422ffb50
UInt32 MS2VideoSoundDX8::GetSoundData(UInt32 nch, float* sample[], UInt32 nsmpl)
{
    UInt32 recv_nsmpl = 0;
    if (pPCMStream)
    {
        if (ChannelCount == 1)
        {
            // mono: the center channel only
            UInt32 i, center_ch = 4;
            for (i = 0; i < nch; i++)
            {
                if (i != center_ch)
                    memset(sample[i], 0, nsmpl * sizeof(float));
            }
            recv_nsmpl = pPCMStream->GetDataFloat(1, &sample[4], nsmpl);
        }
        else
            recv_nsmpl = pPCMStream->GetDataFloat(nch, sample, nsmpl);
    }
    TotalSamples += recv_nsmpl;
    return recv_nsmpl;
}

}}} // namespace Scaleform::GFx::Video

// MS2-PIN: ?PcmfToPcm16@MS2VideoSoundDX8@Video@GFx@Scaleform@@IEAAFM@Z 0x142300760
// MS2-PIN: ?log10@@YAMM@Z 0x142300860
// MS2-FUNCTIONAL ?log10@@YAMM@Z: CRT header inline; it calls log10f directly here, through the ucrtbase IAT in the exe
