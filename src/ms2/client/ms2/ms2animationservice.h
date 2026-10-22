// ms2animationservice.h - MS2AnimationService (RTTI .?AVMS2AnimationService@@): the game's subclass of the engine's
// egmAnimation::AnimationService (0x138 bytes, no members of its own, no ClassInfo of its own). It reloads the gender
// specific KF sets of the local player when the options change and drops the cached NPC assets; the KF "preload"
// table reader (FUN_1414a90c0) and the shared XML/cache statics live in the same unit. Recovered from MapleStory2.exe
// KMS2_DEV x64; owning unit `?\ms2animationservice.cpp` (0x1414a8770-0x1414af320, dir client\ms2).
#pragma once

#include "ms2/ms2layout.h"
#include <egmAnimation/AnimationService.h>

struct Unk_AssetEvent;

class MS2AnimationService : public egmAnimation::AnimationService
{
public:
    MS2AnimationService();                                                  // 0x1414a8770
    virtual ~MS2AnimationService();                                         // 0x1414a87c0, ??_G 0x1414ac330
    virtual efd::AsyncResult OnInit();                                      // 0x1414a8850
    virtual efd::AsyncResult OnTick();                                      // 0x1414a8880
    virtual efd::AsyncResult OnShutdown();                                  // 0x1414a8910
    virtual void OnAssetLoadFailure(AssetDataPtr spAssetData);              // 0x1414a8f00

    void ReloadFemaleKF();                                                  // 0x1414a8980 (FUN_1414a8980)
    void ReloadMaleKF();                                                    // 0x1414a8c40 (FUN_1414a8c40)
    void UnCacheNpcAssets();                                                // 0x1414a8f60 (FUN_1414a8f60)
    size_t GetAssetCount();                                               // 0x1414a9940 (FUN_1414a9940), m_assetsByPhysicalID.size()
    size_t GetActorCount();                                               // 0x1414a9970 (FUN_1414a9970), m_entityData.size()
    size_t GetKFMCacheCount();                                            // 0x1414a99a0 (FUN_1414a99a0), cached KFM files
    bool RemoveUnusedAsset(efd::utf8string kPhysicalID);                    // 0x1414a9a80 (FUN_1414a9a80)

    egmAnimation::KFMCache* GetKFMCache();                                // 0x1414ac8a0, the KFM cache service

    static bool FUN_1414a9810(Unk_AssetEvent* pEvent);                      // 0x1414a9810, filter stored by OnInit
};
MS2_CHECK_SIZE(MS2AnimationService, 0x138);
