// gfxsoundfmod.h - GFxSoundFMOD (RTTI .?AVGFxSoundFMOD@@, 0x28 bytes, vftable 0x14311a4a8: ??_G, NiRefObject::DeleteThis),
// the FMOD Ex sound system of the GFx UI movies: the Scaleform sample FxSoundFMOD (Apps/Samples/Common/FxSoundFMOD.h,
// SDK 4.2) on a NiRefObject base. NOT an original header; the code is the ?\gfxsoundfmod.cpp unit (0x1422f5910-0x1422f69e0).
#pragma once

#include <NiRefObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"
#include "Sound/Sound_SoundRendererFMOD.h"

namespace FMOD { class System; }

class GFxSoundFMOD : public NiRefObject
{
public:
    GFxSoundFMOD();                                                 // 0x1422f5910
    virtual ~GFxSoundFMOD();                                        // 0x1422f5980 (scalar deleting 0x1422f6240)

    bool Initialize();                                              // 0x1422f59f0 heap, FMOD system (20 channels), renderer
    void Finalize();                                                // 0x1422f5f10
    bool IsInitialized() const;                                     // 0x1422f5fd0
    Scaleform::Sound::SoundRenderer* GetSoundRenderer();            // 0x1422f5ff0
    FMOD::System* GetFMOD();                                        // 0x1422f6020

    static Scaleform::MemoryHeap* pFMODHeap;                        // 0x143b0d810 the "_FMOD_Heap" of the FMOD allocator callbacks

private:
    MS2_LAYOUT_FRIEND;
    FMOD::System* pFMOD;                                            // +0x10
    Scaleform::Ptr<Scaleform::Sound::SoundRendererFMOD> pSoundRenderer; // +0x18
    bool Initialized;                                               // +0x20
};
MS2_CHECK_SIZE(GFxSoundFMOD, 0x28);
