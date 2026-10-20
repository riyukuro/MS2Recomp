// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxSoundFMOD, the FMOD Ex sound system of the GFx UI movies.
// MS2-UNIT: ?\gfxsoundfmod.cpp
// MS2-RANGE: 0x1422f5910-0x1422f69e0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). It is
// the Scaleform sample FxSoundFMOD.cpp (SDK 4.2 Apps/Samples/Common) on a NiRefObject base: the FMOD allocator
// callbacks check the heap, Initialize opens 20 channels. The obj's COMDAT tail is the Ptr<SoundRendererFMOD> glue,
// MemoryHeap::CreateHeap, FMOD_ErrorString (fmod_errors.h) and the FMOD::Memory_Initialize / System_Create inlines.
#include "ms2/placeholder/ms2stdafx.h"
#include <stdio.h>

#include "gfxsoundfmod.h"
#include "ms2/placeholder/fmodwrap.h"
#include "../../../third_party/fmod44464/api/inc/fmod_errors.h"

#include "hook/ms2hook.h"

#define ERR_NOSOUND     "FMOD error! (%d) %s. No sound will be playing.\n"
#define ERR_OLDVERSION  "Error! You are using an old version of FMOD %08x. This program requires %08x\n"
#define ERR_INITFAIL    "Error! Can not initialize sound system. No sound will be playing.\n"

Scaleform::MemoryHeap* GFxSoundFMOD::pFMODHeap = 0;

// @0x1422f6040
void* F_CALLBACK FMOD_AllocCallback(unsigned int size, FMOD_MEMORY_TYPE, const char*)
{
    if (GFxSoundFMOD::pFMODHeap)
        return GFxSoundFMOD::pFMODHeap->Alloc(size);
    return 0;
}

// @0x1422f60a0
void* F_CALLBACK FMOD_ReallocCallback(void* ptr, unsigned int size, FMOD_MEMORY_TYPE, const char*)
{
    if (GFxSoundFMOD::pFMODHeap)
        return GFxSoundFMOD::pFMODHeap->Realloc(ptr, size);
    return 0;
}

// @0x1422f6100
void F_CALLBACK FMOD_FreeCallback(void* ptr, FMOD_MEMORY_TYPE, const char*)
{
    if (GFxSoundFMOD::pFMODHeap)
        GFxSoundFMOD::pFMODHeap->Free(ptr);
}

// @0x1422f5910
GFxSoundFMOD::GFxSoundFMOD()
    : pFMOD(0), Initialized(false)
{
}

// @0x1422f5980
GFxSoundFMOD::~GFxSoundFMOD()
{
    if (Initialized)
        Finalize();
}

// @0x1422f59f0
bool GFxSoundFMOD::Initialize()
{
    FMOD_RESULT      result;
    FMOD_SPEAKERMODE speakermode;
    FMOD_CAPS        caps;
    unsigned int     version;

    pFMODHeap = Scaleform::Memory::GetGlobalHeap()->CreateHeap("_FMOD_Heap", 0, 32);
    FMOD::Memory_Initialize(NULL, 0, FMOD_AllocCallback, FMOD_ReallocCallback, FMOD_FreeCallback);

    result = FMOD::System_Create(&pFMOD);
    if (result != FMOD_OK) {
        fprintf(stderr, ERR_NOSOUND, result, FMOD_ErrorString(result));
        Finalize();
        return false;
    }
    result = pFMOD->getVersion(&version);
    if (result != FMOD_OK) {
        fprintf(stderr, ERR_NOSOUND, result, FMOD_ErrorString(result));
        Finalize();
        return false;
    }
    if (version < FMOD_VERSION) {
        fprintf(stderr, ERR_OLDVERSION, version, FMOD_VERSION);
        Finalize();
        return false;
    }
    result = pFMOD->getDriverCaps(0, &caps, 0, &speakermode);
    if (result != FMOD_OK) {
        fprintf(stderr, ERR_NOSOUND, result, FMOD_ErrorString(result));
        Finalize();
        return false;
    }
    result = pFMOD->setSpeakerMode(speakermode);
    if (result != FMOD_OK) {
        fprintf(stderr, ERR_NOSOUND, result, FMOD_ErrorString(result));
        Finalize();
        return false;
    }
    if (caps & FMOD_CAPS_HARDWARE_EMULATED) {
        result = pFMOD->setDSPBufferSize(1024, 10);
        if (result != FMOD_OK) {
            fprintf(stderr, ERR_NOSOUND, result, FMOD_ErrorString(result));
            Finalize();
            return false;
        }
    }
    result = pFMOD->init(20, FMOD_INIT_NORMAL, 0);
    if (result == FMOD_ERR_OUTPUT_CREATEBUFFER) {
        result = pFMOD->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
        if (result != FMOD_OK) {
            fprintf(stderr, ERR_NOSOUND, result, FMOD_ErrorString(result));
            Finalize();
            return false;
        }
        result = pFMOD->init(20, FMOD_INIT_NORMAL, 0);
        if (result != FMOD_OK) {
            fprintf(stderr, ERR_NOSOUND, result, FMOD_ErrorString(result));
            Finalize();
            return false;
        }
    } else if (result != FMOD_OK) {
        fprintf(stderr, ERR_NOSOUND, result, FMOD_ErrorString(result));
        Finalize();
        return false;
    }

    pSoundRenderer = *Scaleform::Sound::SoundRendererFMOD::CreateSoundRenderer();
    if (!pSoundRenderer->Initialize(pFMOD, true, false)) {
        fprintf(stderr, ERR_INITFAIL);
        Finalize();
        return false;
    }
    Initialized = true;
    return true;
}
MS2_REPLACE_METHOD(0x1422F59F0, GFxSoundFMOD, Initialize, 1300, 0x8F16C47D);

// @0x1422f5f10
void GFxSoundFMOD::Finalize()
{
    Initialized = false;
    if (pSoundRenderer)
        pSoundRenderer->Finalize();
    pSoundRenderer = NULL;
    if (pFMOD) {
        pFMOD->release();
        pFMOD = NULL;
    }
    if (pFMODHeap) {
        pFMODHeap->Release();
        pFMODHeap = 0;
    }
}
MS2_REPLACE_METHOD(0x1422F5F10, GFxSoundFMOD, Finalize, 182, 0xAB18B036);

// @0x1422f5fd0
bool GFxSoundFMOD::IsInitialized() const
{
    return Initialized;
}

// @0x1422f5ff0
Scaleform::Sound::SoundRenderer* GFxSoundFMOD::GetSoundRenderer()
{
    return pSoundRenderer;
}
MS2_REPLACE_METHOD(0x1422F5FF0, GFxSoundFMOD, GetSoundRenderer, 31, 0x153609CC);

// @0x1422f6020
FMOD::System* GFxSoundFMOD::GetFMOD()
{
    return pFMOD;
}

// MS2-PIN: ??_GGFxSoundFMOD@@UEAAPEAXI@Z 0x1422f6240
// MS2-PIN: ??0?$Ptr@VSoundRendererFMOD@Sound@Scaleform@@@Scaleform@@QEAA@XZ 0x1422f6140
// MS2-PIN: ??1?$Ptr@VSoundRendererFMOD@Sound@Scaleform@@@Scaleform@@QEAA@XZ 0x1422f6160
// MS2-PIN: ??4?$Ptr@VSoundRendererFMOD@Sound@Scaleform@@@Scaleform@@QEAAAEBV01@AEAVSoundRendererFMOD@Sound@1@@Z 0x1422f6190
// MS2-PIN: ??4?$Ptr@VSoundRendererFMOD@Sound@Scaleform@@@Scaleform@@QEAAAEBV01@PEAVSoundRendererFMOD@Sound@1@@Z 0x1422f61d0
// MS2-PIN: ??B?$Ptr@VSoundRendererFMOD@Sound@Scaleform@@@Scaleform@@QEBAPEAVSoundRendererFMOD@Sound@1@XZ 0x1422f6220
// MS2-PIN: ??C?$Ptr@VSoundRendererFMOD@Sound@Scaleform@@@Scaleform@@QEBAPEAVSoundRendererFMOD@Sound@1@XZ 0x1422f6230
// MS2-PIN: ?CreateHeap@MemoryHeap@Scaleform@@QEAAPEAV12@PEBDI_K111111@Z 0x1422f62a0
// MS2-PIN: ?FMOD_ErrorString@@YAPEBDW4FMOD_RESULT@@@Z 0x1422f6350
// MS2-PIN: ?Memory_Initialize@FMOD@@YA?AW4FMOD_RESULT@@PEAXHP6APEAXIIPEBD@ZP6APEAX0II1@ZP6AX0I1@ZI@Z 0x1422f6970
// MS2-PIN: ?System_Create@FMOD@@YA?AW4FMOD_RESULT@@PEAPEAVSystem@1@@Z 0x1422f69c0
