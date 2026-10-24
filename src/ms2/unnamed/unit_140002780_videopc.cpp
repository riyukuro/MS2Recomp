// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform::GFx::Video::VideoPC, the Windows PC video system of
// the statically linked Scaleform 4.1.18 Video library (Video_VideoPC.cpp; source shape from the 4.3 SDK's
// Src/Video/Video_VideoPC.cpp): the ctor, ApplySystemSettings(VideoPlayer*) (decoder threads / affinity / priority on the
// CRI player) and the scalar deleting dtor. The library is built without RTTI, so the vftable 0x1431b4b10 has no COL.
// MS2-UNIT: unit_140002780
// MS2-RANGE: 0x140002780-0x140002930 .text$mn
#define MS2_THIS_FILE ""

// The Scaleform video declarations need GFX_ENABLE_VIDEO (GFxConfig.h): the exe is built with video support.
#define GFX_USE_VIDEO_WIN32

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/sfvideo.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Statically linked Scaleform library: built with /O2, not /Od ("gsy" is closer to the exe than "gty"; inlining stays off
// under the per-unit /Ob0, see the MS2-FUNCTIONAL notes).
#pragma optimize("gsy", on)

// ---- CRI Movie (Sofdec) player API used here (cri_movie.h of the CRI SDK the Scaleform Video library links) ------------
typedef enum
{
    CRIERR_OK = 0,
    CRIERR_NG = -1,
    CRIERR_ENUM_BE_SINT32 = 0x7FFFFFFF
} CriError;

namespace CriMv {
extern CriError ErrorContainer;                                 // 0x143b278c0
}

class CriMvEasyPlayer
{
public:
    // The PC version of this CRI build takes one priority for all decoding threads (the 4.3 SDK's CRI takes an array).
    void SetUsableProcessors_PC(int num_threads, const unsigned long* affinity_masks, int priority,
                                CriError& err = CriMv::ErrorContainer);     // 0x140024c40
};

namespace Scaleform { namespace GFx { namespace Video {

// Stand-in for the library's VideoPlayerImpl (Video_VideoPlayerImpl.h, not declared in sfvideo.h): the object behind the
// VideoPlayer* this is called with; only its CRI player pointer (+0x08, the first member after the vptr) is used here.
// The library inlines VideoPlayerImpl::GetCriPlayer() (/O2); the per-unit build does not inline, so the member is read
// directly.
class Unk_VideoPlayerImpl
{
public:
    virtual ~Unk_VideoPlayerImpl();

    CriMvEasyPlayer* pCriPlayer;                                // +0x08
};

// MS2-FUNCTIONAL: /O2 library code; the per-unit /Od build with #pragma optimize strength-reduces the loop differently
// @0x140002780
VideoPC::VideoPC(const VideoVMSupport& vmSupport, Thread::ThreadPriority decodingThreadsPriority,
                 int decodingThreadsNumber, UInt32* affinityMask) : Video(vmSupport, decodingThreadsPriority)
{
    DecodingThreadNumber = decodingThreadsNumber > 3 ? 3 : decodingThreadsNumber;
    for (int i = 0; i < 3; ++i)
    {
        AffinityMask[i] = affinityMask && i < DecodingThreadNumber ? affinityMask[i] : 0xffffffff;
    }
}

// MS2-FUNCTIONAL: /O2 library code; rbx/rdi register assignment swapped (pragma-optimized build)
// @0x140002850
void VideoPC::ApplySystemSettings(VideoPlayer* pvideoPlayer)
{
    CriMvEasyPlayer* pcriPlayer = ((Unk_VideoPlayerImpl*)pvideoPlayer)->pCriPlayer;
    if (pcriPlayer)
    {
        pcriPlayer->SetUsableProcessors_PC(DecodingThreadNumber, AffinityMask,
                                           Thread::GetOSPriority(DecodeThreadPriority));
    }
}

// Not hooked: vendor library code, and ApplySystemSettings is an overloaded virtual (MS2_REPLACE_METHOD takes
// &Class::Method, which is ambiguous here); the ctor and ??_G are never hooked.

}}} // namespace Scaleform::GFx::Video

// MS2-FUNCTIONAL ??_GVideoPC@Video@GFx@Scaleform@@UEAAPEAXI@Z: /O2 library inlines ~VideoPC and the SF operator delete
// (Memory::pGlobalHeap->Free); the /Ob0 per-unit build cannot inline
// MS2-PIN: ??_GVideoPC@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x1400028d0
// MS2-PIN: ??_7VideoPC@Video@GFx@Scaleform@@6B@ 0x1431b4b10
