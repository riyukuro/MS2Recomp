// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform::GFx::Video::VideoPC, the Windows PC video system of
// the statically linked Scaleform 4.1.18 Video library (Video_VideoPC.cpp; source shape from the 4.3 SDK's
// Src/Video/Video_VideoPC.cpp): the ctor, ApplySystemSettings(VideoPlayer*) (decoder threads / affinity / priority on the
// CRI player) and the scalar deleting dtor. The library is built without RTTI, so the vftable 0x1431b4b10 has no COL.
// MS2-UNIT: unit_140002780
// MS2-TOOLSET: vc9v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140002780-0x140002930 .text$mn
#define MS2_THIS_FILE ""

#include "../scaleform/include/video/video_videopc.h"
#include "../scaleform/include/video/video_videoplayerimpl.h"

// Statically linked Scaleform Video library: built like the sfr_video units (the VS2008 SP1 cl with the vc11 options,
// MS2-TOOLSET: vc9v; cl 17.00 gives a different AffinityMask loop and register assignment). Keep it C++03.

namespace Scaleform { namespace GFx { namespace Video {

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

// @0x140002850
void VideoPC::ApplySystemSettings(VideoPlayer* pvideoPlayer)
{
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)pvideoPlayer;
    CriMvEasyPlayer* pcriPlayer = pplayer->pPlayer;
    if (pcriPlayer)
    {
        pcriPlayer->SetUsableProcessors_PC(DecodingThreadNumber, AffinityMask,
                                           Thread::GetOSPriority(DecodeThreadPriority));
    }
}

// Not hooked: vendor library code, and ApplySystemSettings is an overloaded virtual (MS2_REPLACE_METHOD takes
// &Class::Method, which is ambiguous here); the ctor and ??_G are never hooked.

}}} // namespace Scaleform::GFx::Video

// MS2-PIN: ??_GVideoPC@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x1400028d0
// MS2-PIN: ??_7VideoPC@Video@GFx@Scaleform@@6B@ 0x1431b4b10
